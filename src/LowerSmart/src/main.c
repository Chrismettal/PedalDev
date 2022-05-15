/*
 * TODO:
 * - Button debouncing
 *
 * BufferLowerSmart
 * 
 * PB0 - LED toggle PWM
 * PB1 - LED momentary PWM
 * 
 * PB2 - Dry FETs
 * PB3 - Wet FETs
 * 
 * PB4 - Button Input - active LOW
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
//#include <stdint.h>
//#include <stdlib.h>


// Pins
#define LED_TOGGLE      0
#define LED_MOMENTARY   1
#define FET_DRY         2
#define FET_WET         3
#define BUTTON          4


// Times
volatile unsigned long currentTime_ms   = 0;
const unsigned long holdToSwitchMode_ms = 5000;
const unsigned long blinkDuration_ms    = 100;
const unsigned long debounceDuration_ms = 100;
unsigned long lastDebounceTime_ms       = 0;
unsigned long lastButtonDownTime_ms     = 0;



// Modes
uint8_t mode                            = 0;
#define adr_mode                          0
#define mode_toggle                       0
#define mode_momentary                    1


// Flags
struct {
  unsigned effectActive:1;
  unsigned modeSwitchDone:1;
  unsigned modeSwitchImminent:1;
  unsigned modeSwitchBlinker:1;
} flags;


// Inputs
struct {
  unsigned debounceInput_Button:1;
  unsigned lastDebounceInput_Button:1;
  unsigned state_Button:1;
  unsigned ftrig_Button:1;
  unsigned Last_Button:1;
} input;


// Outputs
struct {
  unsigned State_LED_Toggle:1;
  unsigned State_LED_Momentary:1;
  unsigned State_FET_Dry:1;
  unsigned State_FET_Wet:1;
} output;


//Function prototypes
void init();
void readInputs();
void setOutputs();


/*******************************************************************************************/
/*****************************             ISR                     *************************/
/*******************************************************************************************/
ISR(TIM0_COMPA_vect)
{
  currentTime_ms++;
}


/*******************************************************************************************/
/*****************************             main                    *************************/
/*******************************************************************************************/
int main(){

  init();

  while(1){

    // Evaluate Inputs
    readInputs();


    // Switch between modes
    switch (mode) {
      case mode_toggle:
        if (input.ftrig_Button) {
          flags.effectActive = !flags.effectActive;
        }
        break;
      
      case mode_momentary:
        flags.effectActive = !input.state_Button;
        break;
    }


    // Mode change request
    if (input.state_Button) {
      // Follow current time as long as button is not pressed
      lastButtonDownTime_ms     = currentTime_ms;
      flags.modeSwitchDone      = 0;
      flags.modeSwitchImminent  = 0;
    } else {
      // While button is pressed, wait for time elapsed
      if (((currentTime_ms - lastButtonDownTime_ms) >= holdToSwitchMode_ms) && !flags.modeSwitchDone) {
        // Switch mode if time elapsed
        if (mode == mode_momentary) {
          mode = mode_toggle;
        } else if (mode == mode_toggle) {
          mode = mode_momentary;
        }

        // Write mode into EEPROM
        eeprom_write_byte(adr_mode, mode);

        // Prevent cyclic toggling of mode as long as button is held
        flags.modeSwitchDone = 1;
      }
    
      // blink shortly before time is elapsed
      flags.modeSwitchImminent = ((currentTime_ms - lastButtonDownTime_ms) < holdToSwitchMode_ms) &&
                                  (currentTime_ms - lastButtonDownTime_ms >= (holdToSwitchMode_ms - blinkDuration_ms));
    }

    // Mode change blinky toggler
    flags.modeSwitchBlinker = (((currentTime_ms - lastButtonDownTime_ms) % 250) <= 125) && flags.modeSwitchImminent;

    // Evaluate Outputs
    setOutputs();

  }//end while(1)

}//end main()


/*******************************************************************************************/
/*****************************           init                *******************************/
/*******************************************************************************************/
void init() {
  //disable interrupts
  cli();

  /*  Set pinmodes
    +---+---+---+---+---+---+---+---+
    | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 0 = Input, 1 = Output
    +---+---+---+---+---+---+---+---+
    | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | Portnumbers
    +---+---+---+---+---+---+---+---+
  */
  DDRB = 0x07; 


  // Set interrupt overflows to 1ms
  TCCR0A |= (1 << WGM01);             // set timer counter mode to CTC
  TCCR0B |= (1 << CS01);              // set prescaler to 8
  OCR0A   = 150-1;                    // set Timer's counter max value
                                      // 1.200.000 MHZ / 8 / 1000 = 150 - Overflow at 1ms
  TIMSK0 |= (1 << OCIE0A);            // enable Timer CTC interrupt
  sei();                              // enable global interrupts


  // Read in EEPROM into mode
  mode = eeprom_read_byte(adr_mode);
}


/*******************************************************************************************/
/*****************************         readInputs                  *************************/
/*******************************************************************************************/
void readInputs() {
  // Read in button
  input.debounceInput_Button = PORTB & BUTTON;

  // Debounce button
  if (input.debounceInput_Button != input.lastDebounceInput_Button) {
    lastButtonDownTime_ms = currentTime_ms;
  } else if (currentTime_ms - lastButtonDownTime_ms >= debounceDuration_ms) {
    input.state_Button    = input.debounceInput_Button;
  }

  // Evaluate edge on button
  input.ftrig_Button  = !input.state_Button && input.Last_Button;
  input.Last_Button   =  input.state_Button;
}


/*******************************************************************************************/
/*****************************         setOutputs                  *************************/
/*******************************************************************************************/
void setOutputs() {
  // Evaluate output flags
  output.State_FET_Wet        =  flags.effectActive;
  output.State_FET_Dry        = !flags.effectActive;

  output.State_LED_Toggle     = (mode == mode_toggle      && flags.effectActive && !flags.modeSwitchBlinker) ||
                                (mode == mode_momentary   && flags.modeSwitchBlinker);
  output.State_LED_Momentary  = (mode == mode_momentary   && flags.effectActive && !flags.modeSwitchBlinker) ||
                                (mode == mode_toggle      && flags.modeSwitchBlinker);


  //Write outputs to port
  //LEDs inverted outputs
  if (output.State_LED_Toggle) {
    PORTB &= ~(1 << LED_TOGGLE);
  } else {
    PORTB |=  (1 << LED_TOGGLE);
  }
  
  if (output.State_LED_Momentary) {
    PORTB &= ~(1 << LED_MOMENTARY);
  } else {
    PORTB |=  (1 << LED_MOMENTARY);
  }
  
  // FETs non-inverted outputs
  if (output.State_FET_Dry) {
    PORTB |=  (1 << FET_DRY);
  } else {
    PORTB &= ~(1 << FET_DRY);
  }

  if (output.State_FET_Wet) {
    PORTB |=  (1 << FET_WET);
  } else {
    PORTB &= ~(1 << FET_WET);
  }

}
