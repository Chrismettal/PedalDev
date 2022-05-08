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

- [Common PCBs](#common-pcbs)
  - [Lower](#lower)
  - [Lower Buffered](#lower-buffered)
- [Specific Designs](#specific-designs)
  - [404 (Tubescreamer)](#404-tubescreamer)
  - [TOP (Dominator)](#top-dominator)
- [Protoboards](#protoboards)
  - [Proto Simple](#proto-simple)
  - [Proto Groundplane](#proto-groundplane)
  - [Proto Advanced SMD](#proto-advanced-smd)
- [Designing your own](#designing-your-own)
- [Building manual](#building-manual)
- [Sources](#sources)
- [Tools](#tools)
- [Donations](#donations)
- [License](#license)


## Common PCBs

### Lower

The lower PCB consists of the bypass footswitch with a status LED, input and output jacks as well as power input, filtering and FET based reverse polarity protection. 

Additionally an optional TL07X based buffer can be enabled via two jumpers. This was only added because the PCB had enough room for it and it can save room on the pedalboard instead of adding a separate buffer box. The buffer parts do NOT NEED to be populated if you intend never to use them.

The LED is driven through a simple "anti pop" filter and two optional anti-pop bleeders can be enabled via JP3 and JP4 to bleed any input/output caps on the connected upper board if neccessary.

Test hooks and pads are sprinkled on interesting signals for effect development and debugging.

> :bulb: Hint: 
> 
> While this system is intended to be used with one lower PCB and one upper PCB fitting together, it might be convenient to just use the lower PCB even if you do not intend to use an actual effect from this system. Doing so greatly reduces the amount of free form wiring and frees up some space on your actual effect PCB.


### Lower Buffered

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:

This variant of the lower PCB features mostly the same stuff as the regular one, but instead of true bypass it uses a fully buffered flip-flop bypass that can be set latching or momentary with jumpers. In latching mode it will work like any other Boss like effect, toggling the effect on or off on button press. In momentary mode the effect will only be active as long as the button is held down.


## Specific Designs

### 404 (Tubescreamer)

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:

First version of design finished. PCBs being ordered.


### TOP (Dominator)

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:

Based on schematic by Saruman [here](https://www.freestompboxes.org/viewtopic.php?t=12031&hilit=c6)


## Protoboards

### Proto Simple

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:


### Proto Groundplane

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:


### Proto Advanced SMD

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:


## Designing your own

I would love to merge your designs using this system into this repo!

To design your own effect PCB, create a copy of the `UpperRaw` KiCAD project for the actual effect, and optionally `FrontRaw` for a PCB frontpanel design. `UpperRaw` includes in the schematic a collection of frequently used parts, set up with LCSC part numbers etc. It would be great if you add LCSC part numbers to all parts used in your design, but it is not required. After merging I will recreate the production files to the same parameters as the already created designs so don't worry about that.


## Building manual

As the system tries to use the little space in the 1590B as efficient as possible, the actual build can be quite tight. There is a set order of steps that should be taken to make the build as quick and easy as possible.

:construction: :construction: :construction: **Work in progress** :construction: :construction: :construction:

The whole system is designed so the PCBs can be ordered from JLCPCB mostly populated, so only very little hand soldering is involved. If you order the boards finished you will mostly have to solder only the through hole components, but for some rare components that JLCPCB doesn't populate, it might be neccessary to solder some SMD components manually. SMD components go down to `0603` for passives, and `SOIC-*` / `SOT-*` for actives, which is still hand solderable without too much trouble.

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

- PCBs: [KiCAD Version 6.0.3](https://www.kicad.org/)
- 3D CAD: [FreeCAD 0.20 Dev versions](https://www.freecadweb.org/) 


## Donations

If you like my work please consider [supporting my caffeine addiction](https://gitlab.com/Chrismettal#donations)!


## License

 <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
 