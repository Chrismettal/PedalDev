# PedalDev <!-- omit in toc -->

[![License: CC BY-SA 4.0](https://img.shields.io/badge/license-CC%20BY--SA%204.0-blue?style=flat-square)](https://creativecommons.org/licenses/by-sa/4.0/)
[![Shop: Tindie](https://img.shields.io/badge/shop-Tindie-blue?style=flat-square)](https://www.tindie.com/stores/binary-6/?ref=offsite_badges&utm_source=sellers_Chrismettal&utm_medium=badges&utm_campaign=badge_medium)
[![Donations: Coffee](https://img.shields.io/badge/donations-Coffee-brown?style=flat-square)](https://gitlab.com/Chrismettal#donations)

This is a convenient system for quickly creating stompboxes, as well as a collection of designs made with this system.

The design is split into two boards, a lower and an upper one. The lower PCB handles all of the I/O, switching, and power stuff, while the upper one focuses on the individual effect. The two boards plug together and fit neatly inside a commonly used Hammond 1590B. For each finished design there is also a PCB frontpanel so I don't have to deal with any actual design work and can just hide my designs behind technical looking stuff. The actual boards take full advantage of modern SMD components for optimal space usage.

All designs build up from the same template to allow rapid creation of new designs as well as saving time on recurring steps. There are even various protoboard variants of the upper PCB fitting the same template, to make boutique one-off designs more convenient and robust.

For easy mechanical manufacturing a 3D printable drilling template is provided. There is also a 3D printable design of the full stompbox similar to the 1590B with all ports "predrilled". A plastic case is not super recommended though and should only be used for quick testing. Conductive spray paint as shielding on the inside is also recommended when using the 3D printed case.

---

Individual boards as well as some kits will be stocked at Tindie!

<a href="https://www.tindie.com/stores/binary-6/?ref=offsite_badges&utm_source=sellers_Chrismettal&utm_medium=badges&utm_campaign=badge_medium"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-mediums.png" alt="I sell on Tindie" width="150" height="78"></a>

**If you like my work please consider [supporting my caffeine addiction](https://gitlab.com/Chrismettal#donations)!**


## Table of contents <!-- omit in toc -->

- [Specific Designs](#specific-designs)
  - [404 (:sheep: Ibanez Tubescreamer)](#404-sheep-ibanez-tubescreamer)
  - [:construction: TOP (:sheep: OKKO Dominator)](#construction-top-sheep-okko-dominator)
- [Common PCBs](#common-pcbs)
  - [Lower](#lower)
  - [Lower Smart](#lower-smart)
- [Protoboards](#protoboards)
  - [Proto Simple](#proto-simple)
  - [Proto Groundplane](#proto-groundplane)
  - [Proto Advanced SMD](#proto-advanced-smd)
- [Designing your own effects](#designing-your-own-effects)
- [Building guide](#building-guide)
  - [Case](#case)
  - [Electronics](#electronics)
- [Sources](#sources)
- [Tools](#tools)
- [Donations](#donations)
- [License](#license)


## Specific Designs

### 404 (:sheep: Ibanez Tubescreamer)

Based on the popular Tubescreamer this is obviously the first design to be done in this system.

![404](/img/404/nice.png)


### :construction: TOP (:sheep: OKKO Dominator)

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:

Based on schematic by Saruman [here](https://www.freestompboxes.org/viewtopic.php?t=12031&hilit=c6).

First PCB version `f35813b` was broken is currently being debugged. 4 Pins on TL074 were swapped, `ICL7660` does not work when `BOOST` mode is set (But **`ICL7660S`** does..), and input stage sounds super starved, more like a bass fuzz than a distortion. Simulation seems to confirm this so confidence in schematic is low. Currently ordering an original Dominator for schematic comparison.


## Common PCBs

### Lower

The lower PCB consists of the bypass footswitch with a status LED, input and output jacks as well as power input, filtering and FET based reverse polarity protection. 

Additionally an optional TL07X based buffer can be enabled via two jumpers. This was only added because the PCB had enough room for it and it can save room on the pedalboard instead of adding a separate buffer box. The buffer parts do NOT NEED to be populated if you intend never to use them.

The LED is driven through a simple "anti pop" filter and two optional anti-pop bleeders can be enabled via JP3 and JP4 to bleed any input/output caps on the connected upper board if neccessary.

Test hooks and pads are sprinkled on interesting signals for effect development and debugging.

> :bulb: Hint: 
> 
> While this system is intended to be used with one lower PCB and one upper PCB fitting together, it might be convenient to just use the lower PCB even if you do not intend to use an actual effect from this system. Doing so greatly reduces the amount of free form wiring and frees up some space on your actual effect PCB.


### Lower Smart

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:

Same as `Lower`, but instead of a true bypass 3PDT Switch it features a microcontroller to turn your effect on and off either in momentary or latching mode. To show the mode it's currently on, it uses a bicolor LED.

On initial bootup, the device will be in latching mode. Pressing the button will toggle the effect on and off. The :construction: colored LED will be on as long as the effect is on in toggle mode. 
Holding the button down for 9 seconds, both LEDs will start blinking, signaling that a mode change is imminent. Holding the button for one more second, the device will switch into momentary mode.
In momentary mode, the effect will only be on while the button is held. While the effect is on, a :construction: colored LED will be on in momentary mode.
Switching back to toggle mode works the same way, by holding down the button long enough.


## Protoboards

### Proto Simple

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:


### Proto Groundplane

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:


### Proto Advanced SMD

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:


## Designing your own effects

I would love to merge your designs using this system into this repo!

To design your own effect PCB, create a copy of the `UpperRaw` KiCAD project for the actual effect, and optionally `FrontRaw` for a PCB frontpanel design. `UpperRaw` includes in the schematic a collection of frequently used parts, set up with LCSC part numbers etc. It would be great if you add LCSC part numbers to all parts used in your design, but it is not required. After merging I will recreate the production files to the same parameters as the already created designs so don't worry about that.


## Building guide

As the system tries to use the little space in the 1590B as efficient as possible, the actual build can be quite tight. There is a set order of steps that should be taken to make the build as quick and easy as possible.

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:

The whole system is designed so the PCBs can be ordered from JLCPCB mostly populated, so only very little hand soldering is involved. If you order the boards finished you will mostly have to solder only the through hole components, but for some rare components that JLCPCB doesn't populate, it might be neccessary to solder some SMD components manually. SMD components go down to `0603` for passives, and `SOIC-*` / `SOT-*` for actives, which is still hand solderable without too much trouble.


### Case

If you have access to a 3D printer (or to my [Tindie Shop](https://www.tindie.com/stores/binary-6/), there is a printable drill guide available. Otherwise, there will be a techdraw sheet with all the dimensions.


1. Put the case in the drill guide and use a center punch to mark out all the holes to be drilled

![DrillGuide](/img/Guide/DrillGuide.png)


2. Pre-drill all marked holes with a `3mm drill bit` (The smallest size used on the device)

![PreDrill](/img/Guide/PreDrill.png)


3. Drill out all the holes to the sizes marked on the drill guide. Note that the holes are all 0.5mm - 1mm larger than they need to be to make alignment of the frontpanel easier

![Drilled](/img/Guide/Drilled.png)


4. If you want to paint the case, this would be the step to do it. I clean the case with rubbing alcohol, prime and paint, while only focusing on the sides of the case as I will hide the top underneath the frontpanels.

![Painted](/img/Guide/Painted.png)


### Electronics

1. Some boards require several components to be mounted manually (Check their individual [documentation](#specific-designs)). These will include through hole parts or not easily available active parts for example. In this case, the OpAmp and input stage transistors, as well as connectors need to be placed manually. Note that the pots and switches are NOT placed at this stage!

![TopAssembly](/img/Guide/404Assembly.png)


2. The lower PCB also requires some assembly, namely attaching the LED with its spacer and soldering on the board-to-board connector wire.

![LowerAssembly](/img/Guide/LowerAssembly.png)


3. On most boards you will also find some configuration jumpers to be set. These include for example the `Buffered - Unbuffered` jumpers for the [Lower](#lower) PCB. Note the individual boards [documentation](#specific-designs).

![Jumpers](/img/Guide/Jumpers.png)


4. Attach the spacers to all boards.

![Spacers](/img/Guide/Spacers.png)


5. Prepare the power jack by attaching two solid wires to the jack as shown.

![PowerWire](/img/Guide/PowerWire.png)


6. Mount all jacks, pots and switches to the case, optionally applying the FrontPanel. Do the input/output jacks first, as you will need to have some space to tilt the jacks while inserting them both into the case.

![Mechanicals](/img/Guide/Mechanicals.png)


7. Place the upper board on top of the controls. Might be a bit tricky to align all the holes, but it can be made a bit easier by loosening all the controls screws. While it is also possible to first solder on all the controls, slight misalignments in height will lead to mechanical stress on the board when screwing the controls down later. Soldering it after mounting will ensure a mechanically unstressed board and still allow unmounting the board later by unscrewing the controls.

![PlacedOnControls](/img/Guide/PlacedOnControls.png)


8. Screw down all controls tightly and solder all controls to the board.

![Soldered](/img/Guide/Soldered.png)


9. Place the lower board on top of the I/O

![LowerPlaced](/img/Guide/LowerPlaced.png)


10. Solder down the lower PCB. Note that this board will NOT be easily removeable without unsoldering the controls again!

![LowerSoldered](/img/Guide/LowerSoldered.png)


11. Plug in the board-to-board connector.

![InsideDone](/img/Guide/InsideDone.png)


12. All done! 

![OutsideDone](/img/Guide/OutsideDone.png)


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

- PCBs: [KiCAD Version 6.0.5](https://www.kicad.org/)
- 3D CAD: [FreeCAD 0.20 nightly Dev versions](https://www.freecadweb.org/) 


## Donations

If you like my work please consider [supporting my caffeine addiction](https://gitlab.com/Chrismettal#donations)!


## License

 <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
 