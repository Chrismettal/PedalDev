# PedalDev <!-- omit in toc -->

[![License: CC BY-SA 4.0](https://img.shields.io/badge/license-CC%20BY--SA%204.0-blue?style=flat-square)](https://creativecommons.org/licenses/by-sa/4.0/)
[![Shop: Tindie](https://img.shields.io/badge/shop-Tindie-blue?style=flat-square)](https://www.tindie.com/stores/binary-6/?ref=offsite_badges&utm_source=sellers_Chrismettal&utm_medium=badges&utm_campaign=badge_medium)
[![Donations: Coffee](https://img.shields.io/badge/donations-Coffee-brown?style=flat-square)](https://github.com/Chrismettal#donations)

This is a convenient system for quickly creating stompboxes, as well as a collection of designs made with this system.

The design is split into two boards, a lower and an upper one. The lower PCB handles all of the I/O, switching, and power stuff, while the upper one focuses on the individual effect. The two boards plug together and fit neatly inside a commonly used Hammond 1590B. For each finished design there is also a PCB frontpanel so I don't have to deal with any actual design work and can just hide my designs behind technical looking stuff. The actual boards take full advantage of modern SMD components for optimal space usage.

All designs build up from the same template to allow rapid creation of new designs as well as saving time on recurring steps. There are even various protoboard variants of the upper PCB fitting the same template, to make boutique one-off designs more convenient and robust. For every design you will find the full KiCAD project including schematic and production files like **BOM, Gerbers and PCBA place files** in their respective project folders. (`/pcb/*`)

For easy mechanical manufacturing a 3D printable drilling template is provided. There is also a 3D printable design of the full stompbox similar to the 1590B with all ports "predrilled". A plastic case is not super recommended though and should only be used for quick testing. Conductive spray paint as shielding on the inside is also recommended when using the 3D printed case. (`/3d/*`)

Parts marked with ":construction:" are work in progress and not fully verified yet.

---

Individual boards, predrilled cases as well as kits will be stocked at Tindie!

<a href="https://www.tindie.com/stores/binary-6/?ref=offsite_badges&utm_source=sellers_Chrismettal&utm_medium=badges&utm_campaign=badge_medium"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-mediums.png" alt="I sell on Tindie" width="150" height="78"></a>

**If you like my work please consider [supporting my caffeine addiction](https://github.com/Chrismettal#donations)!**

## Table of contents <!-- omit in toc -->

- [Specific Designs](#specific-designs)
  - [404 (:sheep: Ibanez Tubescreamer)](#404-sheep-ibanez-tubescreamer)
  - [YOU WHAT?! (:sheep: emma electronic PisdiYAUwot)](#you-what-sheep-emma-electronic-pisdiyauwot)
  - [:construction: TOP (:sheep: OKKO Dominator)](#construction-top-sheep-okko-dominator)
- [Common PCBs](#common-pcbs)
  - [Lower](#lower)
  - [:construction: Lower Smart](#construction-lower-smart)
- [Protoboards](#protoboards)
  - [Proto Simple](#proto-simple)
- [Designing your own effects](#designing-your-own-effects)
- [Building guide](#building-guide)
  - [Case](#case)
  - [Electronics](#electronics)
- [Sources](#sources)
- [Tools](#tools)
- [Donations](#donations)
- [License](#license)

## Specific Designs

While there aren't many specific designs right now, they will be created faster now that the system is proven working. There is a wide range of devices in the works, from high gain distortions over reverbs to new, experimental stuff.

### 404 (:sheep: Ibanez Tubescreamer)

<img src="/img/404/nice.jpg" width="50%"/>

Based on the popular Tubescreamer this is obviously the first design to be done in this system.

Nothing crazy here, only `D1-3` feature a dual footprint to put in your favourite clipping diodes.

There are two jumpers that need to be set when building this board. `JP1` does not really do anything with the sound but chooses a filter to be sent to ground or to bias voltage as some schematics have it either way. `JP2` however allows choosing betweeen symmetrical or assymetrical clipping.

<img src="/img/404/pcb.jpg" width="50%"/>

### YOU WHAT?! (:sheep: emma electronic PisdiYAUwot)

<img src="/img/YOU_WHAT/nice.jpg" width="50%"/>

Very cheap in parts but incredibly tight high gain distortion with lots of attack.


### :construction: TOP (:sheep: OKKO Dominator)

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:

<img src="/img/TOP/nice.jpg" width="50%"/>

Based on schematic by Saruman [found here](https://www.freestompboxes.org/viewtopic.php?t=12031&hilit=c6).

First PCB version `f35813b` was broken is currently being debugged. 4 Pins on `TL074` were swapped, `ICL7660` does not work when `BOOST` mode is set (But **`ICL7660S`** does..), and input stage sounds super starved, more like a bassy fuzz than a distortion. Simulation seems to confirm this so confidence in schematic is low. Currently getting hold of an original Dominator for schematic comparison.

Two jumpers on board revision `f35813b` are for debugging the power stage around the `7660` but will probably be removed or clarified on the fixed revision

## Common PCBs

### Lower

<img src="/img/Lower/LowerFront.jpg" width="50%"/>

<img src="/img/Lower/LowerBack.jpg" width="50%"/>

The lower PCB consists of the bypass footswitch with a status LED, input and output jacks as well as power input, filtering and FET based reverse polarity protection.

The Input/Output jacks are called `PJ-602B`. These are not available via LCSC sadly, but can be found all over Aliexpress. 

Additionally an optional TL07X based buffer can be enabled via two jumpers. This was only added because the PCB had enough room for it and it can save room on the pedalboard instead of adding a separate buffer box. The buffer parts do NOT NEED to be populated if you intend never to use them. **Either `JP1_A1` and `JP1_B1` or `JP2_A1` and `JP2_B1` need to be set for signal to be passed through**.

The LED is driven through a simple "anti pop" filter and two optional anti-pop bleeders can be enabled via `JP3` and `JP4` to bleed any input/output caps on the connected upper board if neccessary.

Test hooks and pads are sprinkled on interesting signals for effect development and debugging.

> :bulb: Hint: 
> 
> While this system is intended to be used with one lower PCB and one upper PCB fitting together, it might be convenient to just use the lower PCB even if you do not intend to use an actual effect from this system. Doing so greatly reduces the amount of free form wiring and frees up some space on your actual effect PCB.

### :construction: Lower Smart

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:

Same as `Lower`, but instead of a true bypass 3PDT Switch it features a microcontroller to turn your effect on and off either in momentary or latching mode. To show the mode it's currently on, it uses a bicolor LED.

On initial bootup, the device will be in latching mode. Pressing the button will toggle the effect on and off. The :construction: colored LED will be on as long as the effect is on in toggle mode. 
Holding the button down for 9 seconds, both LEDs will start blinking, signaling that a mode change is imminent. Holding the button for one more second, the device will switch into momentary mode.
In momentary mode, the effect will only be on while the button is held. While the effect is on, a :construction: colored LED will be on in momentary mode.
Switching back to toggle mode works the same way, by holding down the button long enough.

## Protoboards

### Proto Simple

<img src="/img/ProtoSimple/nice.jpg" width="50%"/>

This is a simple protoboard to use as an "upper" board, allowing for up to 6 pots, or 5 pots with one DPDT print switch.
It features 9V and GND power rails straight through the design to allow for easy power distribution

While it does not allow for the density of SMD components it can certainly fit a lot of designs.

## Designing your own effects

I would love to merge your designs using this system into this repo!

To design your own effect PCB, create a copy of the `UpperRaw` KiCAD project for the actual effect, and `FrontRaw` for a PCB frontpanel design. `UpperRaw` includes a collection of frequently used parts in the schematic, set up with LCSC part numbers etc. It would be great if you add LCSC part numbers to all parts used in your design as well. After merging I will recreate the production files to the same parameters as the already created designs so don't worry about that.

---

## Building guide

As the system tries to use the little space in the 1590B as efficient as possible, the actual build can be quite tight. There is a set order of steps that should be taken to make the build as quick and easy as possible.

The whole system is designed so the PCBs can be ordered from JLCPCB mostly populated, so only very little hand soldering is involved. If you order the boards finished you will mostly have to solder only the through hole components, but for some rare components that JLCPCB doesn't populate, it might be neccessary to solder some SMD components manually. SMD components go down to `0603` for passives, and `SOIC-*` / `SOT-*` for actives, which is still hand solderable without too much trouble. A hot air solder station is highly recommended though.

<details>
  <summary markdown="span">Building guide, click to expand</summary>

### Case

If you have access to a 3D printer (or to my [Tindie Shop](https://www.tindie.com/stores/binary-6/)), there is a printable drill guide available. Otherwise, there will be a techdraw sheet with all the dimensions. At the [shop](https://www.tindie.com/stores/binary-6/) you will also find predrilled, black cases directly manufactured by Hammond.

All models are compatible with the same drill layout. Holes not required for a specific board will be hidden by the front plate, so the fully stacked 6 controls variant works for every model.

1. Put the case in the drill guide and use a center punch to mark out all the holes to be drilled

2. Pre-drill all marked holes with a `3mm drill bit` (The smallest size used on the device)

3. Drill out all the holes to the sizes marked on the drill guide. Note that the holes are all 0.5mm - 1mm larger than they need to be to make alignment of the frontpanel easier

4. If you want to paint the case, this would be the step to do it. I clean the case with rubbing alcohol, prime and paint, while only focusing on the sides of the case as I will hide the top underneath the frontpanels.


### Electronics

1. Some boards require several components to be mounted manually (Check their individual [documentation](#specific-designs)). These will include through hole parts or not easily available active parts for example. In this case, the OpAmp and input stage transistors, as well as connectors need to be placed manually. Note that the pots and switches are NOT placed at this stage!


<img src="/img/Guide/404AssemblyRaw.jpg" width="50%"/>

<img src="/img/Guide/404AssemblyDone.jpg" width="50%"/>

---

2. The lower PCB also requires some assembly, namely attaching the LED with its spacer and soldering on the board-to-board connector wire. Make sure to set **either `JP1_A1` and `JP1_B1` or `JP2_A1` and `JP2_B1` need to be set for signal to be passed through**.


<img src="/img/Guide/LowerAssemblyRaw.jpg" width="50%"/>

<img src="/img/Guide/LowerAssemblyDone.jpg" width="50%"/>

---

3. On most boards you will also find some configuration jumpers to be set. These include for example the `Buffered - Unbuffered` jumpers for the [Lower](#lower) PCB. Note the individual boards [documentation](#specific-designs).


<img src="/img/Guide/Jumpers.jpg" width="50%"/>

---

4. Attach the 10mm spacers to upper board, facing the "Towards foot" side. No washers required.


<img src="/img/Guide/Spacers.jpg" width="50%"/>

---

5. Prepare the power jack by attaching two solid wires to the jack as shown. Make sure to keep them straight for easier insertion later


<img src="/img/Guide/PowerWire.jpg" width="50%"/>

---

6. Mount all jacks, pots and switches to the case, optionally applying the FrontPanel. Do the input/output jacks first, as you will need to have some space to tilt the jacks while inserting them both into the case. They will go in VERY tight, but they will fit. For the power jack, make sure that the pins face upwards. Make sure to keep a single nut on the footswitch to have the correct spacing.


<img src="/img/Guide/IO.jpg" width="50%"/>

<img src="/img/Guide/Power.jpg" width="50%"/>

<img src="/img/Guide/Footswitch.jpg" width="50%"/>

---

7. Insert the pots, making sure to put each pot the correct hole for your design. Check out the silkscreen on your upper PCB for that. The nut probably won't have much flesh to grip onto so only handtighten them, or leave them out if necessary. The board will be held by screws later so it's no big deal. I like to straighten the potpins after mounting so I have  an easier time inserting the PCB in the next step. 


<img src="/img/Guide/Pots.jpg" width="50%"/>

---

8. If your board does not use the middle upper pot, place a spacer inside the hole where a screw will go


<img src="/img/Guide/PotSpacer.jpg" width="50%"/>

---

9.  Place the upper board on top of the controls. Might be a bit tricky to align all the holes, but it can be made a bit easier by loosening all the controls screws. While it is also possible to first solder on all the controls, slight misalignments in height will lead to mechanical stress on the board when screwing the controls down later. Soldering it after mounting will ensure a mechanically unstressed board and still allow unmounting the board later by unscrewing the controls.

---

10. Secure the PCB with screws from the front, Screw down all controls tightly and after makind sure your pots all spin freely (not crooked), then solder all controls to the board.


<img src="/img/Guide/Soldered.jpg" width="50%"/>

---

11. Place the lower board on top of the I/O


<img src="/img/Guide/LowerPlaced.jpg" width="50%"/>

---

12.  Solder down the lower PCB. Note that this board will NOT be easily removeable without unsoldering the controls again!

<img src="/img/Guide/LowerSoldered.jpg" width="50%"/>

---

13.  Plug in the board-to-board connector.

<img src="/img/Guide/Plug.jpg" width="50%"/>

<img src="/img/Guide/InsideDone.jpg" width="50%"/>

---

14.  Screw on the bottom plate and mount your pot knobs.

<img src="/img/Guide/OutsideDone.jpg" width="50%"/>

---

15. Done!

</details>

## Sources

The following 3D models were used for the simulation renders in KiCAD and FreeCAD. Please check their respective licenses if you intend to reuse them.

Any models that are **not** mentioned here were created by me for this project and are subject to the same [license](#license) as the whole repo.

| File                | Link                                                    |
| ------------------- | ------------------------------------------------------- |
| Hammond 1590B       | https://www.hammfg.com/part/1590B                       |
| PJ-602B Audio jacks | https://github.com/afedorov3/3DModels                   |
| Footswitch_3PDT     | https://grabcad.com/library/3pdt-switch-1               |
| 9mm potentiometers  | https://grabcad.com/library/alpha-rd901f-40-15r1-1      |
| DC barrel jack      | https://grabcad.com/library/5-5mm-panel-mount-dc-jack-1 |
| LED 5mm             | https://grabcad.com/library/led-5mm-1#!                 |

## Tools

- PCBs: [KiCAD 6](https://www.kicad.org/)
- 3D CAD: [FreeCAD 0.20](https://www.freecadweb.org/)
- Source code: [PlatformIO](https://platformio.org/)

## Donations

**If you like my work please consider [supporting my caffeine addiction](https://github.com/Chrismettal#donations)!**

## License

 <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
