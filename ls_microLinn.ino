/**************************************** MICROLINN ****************************************

-------- INSTALLATION -------- 

1) Download the latest installer (2.3.3 as of Feb '24) from https://www.rogerlinndesign.com/support/support-linnstrument-update-software. 
2) Download the latest version of linnstrument-firmware-microLinn.bin from __________________.
3) If on a mac, put both the updater and the .bin file on your desktop (important). If on a PC, _______________.
4) Run the updater. Don't run anything else while it's running. If it asks for permission to read files from the desktop, say yes.
5) Confirm the update by short-pressing the OS version (global settings, column 16). It should be 234.08K. If not, try using the 2.3.0 updater instead. 

-------- NON-MICROTONAL FEATURES -------- 

BLINKING MODE: This is a variation of the SAME mode that shows you other occurences of the currently played note.

CHAINING SEQUENCES: hold down the pad for sequence #1 and tap the pad for sequence #2. Now the two sequences are chained into a single 
sequence twice as long. You can chain #3 and #4 together as well. Or chain all 4 together. The PREV and NEXT footswitches work as expected.
To clear the chaining, tap the pad immediately to the left of the 4 selector pads. Or just disconnect the Linnstrument and reconnect it.
You can select sequences on the fly as the sequencer is playing as usual. You can also chain, re-chain and unchain on the fly. 
When chaining on the fly, to start at the beginning of the chain not the end, hold the last sequence and tap the first one.

NEW SWITCH/FOOTSWITCH FUNCTIONS: SCL+ and SCL- cycle you through the 9 scales in columns 2-4 (only affects the note lights)

COLUMN OFFSETS: The column offset can be set for either split independently. This allows Wicki-Hayden layout on the left for easy chording 
and normal layout on the right for easy melody playing. Acces it

-------- MICROTONAL FEATURES -------- 

On the global settings screen, long-press col 1 bottom row (VIEW MAIN) to go to the main microLinn display.
Once the edo (notes per octave) is set to anything other than OFF, VIEW MAIN turns light blue and you can short-press it.
The main display has 10 buttons. Long-press each one to see its function. Most don't work until you set the edo.

The anchor cell is a specific cell or pad that doesn't change pitch when you change the notes per octave.
The anchor cell chooser displays the row and column of the current anchor cell, e.g. R3C6 means row 3 (from the top) and column 6. 
To choose a new anchor cell, tap the blue "R3C6" and then tap any pad.

When the notes per octave is greater than 12, the OCTAVE/TRANSPOSE display shows 2 extra rows for transposing by edosteps.
The 2nd and 3rd rows now transpose not by semitones but by major 2nds (since most edos have several different semitones).

There are 4 new functions for switches 1 & 2 and footswitches 1 & 2: 
EDO+ and EDO- move up or down to the next EDO, wraps around (probably best you don't play while changing!)
SCL+ and SCL- move up or down to the next scale, wraps around (only affects the note lights)

The first 9 scales in cols 2-4 are now microtonal and change for each edo. You can edit them and their colors in microLinn's note lights display. 
Shortcut: you can long-press the scale's pad on the global settings display to go directly to that scale.
The note lights display has 7 scale buttons plus the color editor, the dots selector and the mass-selector button.
Tap a note in a scale to toggle it on or off. Tap a note in the color editor to cycle it thru the rainbow. 
Tapping the dots selector makes the dots appear mid-screen. Tapping there puts you in a full-screen editor that lets you toggle dots on or off. 

Long-press the scale buttons or color editor button or the dots selector button to reset the note lights to the default. 
Hold the mass-selector button in column 3 row 5 while selecting something and your selection will be applied to all 51 edos at once. 
Hold it while long-pressing another button to mass-reset that scale/rainbow/dot-pattern for all 51 edos.

The 3 custom light patterns are totally separate from all this and are still available for use!
This web browser lets you easily edit them: https://forrcaho.github.io/linnstrument_colorizer/

When microLinn is on, the global setting of lefthandedness is ignored. Set the column offsets to something negative to get lefthandedness.

The 8 scales are somewhat similar from edo to edo (except the smaller, weirder edos of course)
The 1st and 2nd scales are 5-over (major or downmajor) and 5-under (minor or upminor)
The 3rd and 4th scales are 7-over (downminor) and 7-under (upmajor)
The 5th scale is 11-over or 11-under (mid or neutral), and the 6th scale is blank but for the tonic
The 7th scale is scales 1-4 combined, and the 8th scale is always the full rainbow

The colors use the rainbow metaphor, red-yellow-green-blue = supermajor to subminor
white = 12-edo-ish = 3-limit
yellow / green = downmajor / upminor =  5-over / 5-under
blue / red = downminor / upmajor = 7-over / 7-under
purple = neutral = 11-over or 11-under or 13-over or 13-under
pink is reserved for the exact half-octave of 600c, 12-edo-ish but not quite 3-limit, "off-white"
cyan / orange = a catch-all pair, e.g. 7/5 and 10/7, cyan is also for "outside" notes aka interordinals e.g. 24edo

Suggestions for exploring:
The first few edos are pretty strange. Try starting with 15, 16, 17 or 19.
The rainbow colors can be overwhelming. Try setting the played mode to BLNK or BLNK8.

To create JI or rank-2 scales with N notes, set the edo to 12 but play as if in N-edo, think one midi note per edostep.
Load a scala file into your synth or run alt-tuner to produce that N-note scale.
eEch note is slightly sharper or flatter from N-edo, thus the pad's note will be different slid up to vs played directly.
However this is only a comma or so difference even on long slides, which might be tolerable.
Perhaps software on the PC could fix this problem by scaling the slides by adjusting the pitch bends?


To find all changes to the code, search for "microlinn" or "brightness" or "playedBlink" or "patternChain"





note to self:  "if (sensorCell->velocity)" means if another touch is already down on the same row
according to the comment by handleFaderRelease in ls_faders.ino

note to self: in ls_settings.ino, "Device.version = 16;"

Geert's coding suggestions for forks: https://www.kvraudio.com/forum/viewtopic.php?t=433791 
Geert's 2014 video: https://www.youtube.com/watch?v=iENVztlxWuk
Geert's 2017 video: https://www.synthtopia.com/content/2017/06/28/from-arduino-to-linnstrument/


 a few ideas I had, probably not needed
short microLinnTuningBend[NUMSPLITS][16][10];                // 16 midi channels, 10 touches, tuning bends come from microLinnFineTuning
short microLinnSlideBend[NUMSPLITS][16][10];                 // 16 midi channels, 10 touches, slide bends come from sliding along the Linnstrument
short microLinnLandingBend[NUMSPLITS][16][10];               // 16 midi channels, 10 touches, landing bends come from the initial touch being off-center

*********************************************************/



// to do: get guitar dots to transpose
// to do: make microLinnDots 55 columns wide, when loading from MICROLINN_DOTS complete the dots via symmetry
// to do: test octave up/down switches while playing, does the calcTuning call make it glitchy?

// decide: 2nd shortcut on global, col 1 row 1 for 2nd config display for brightness etc.?
// decide: delete code for col 16 and/or 17 shortcut (ifndef)?
// decide: delete 12edo reset button? or make it wicki-hayden?
// decide: 6th scale is minimalist: just white tonic and one (or two for odd edos) tritones?
// decide: increase the number of memories from 6? expand what they remember?
// decide: hammerons/pulloffs window of 1, 2 or 3 columns?

// to do: write code for accepting microLinn NRPNs (see midi.txt)

// TO DO: add 3 new played modes: 
// SAM8 = same, but includes the octave-mates
// BLNK = same, but blinks slowly
// BLN8 = same, blinks, octaves too
// all 3 plus SAME should include notes on the other split, but only if the other split also has SAME
// blink modes can blink a lit LED on/off, see getLedColor function

// TO DO: finish MICROLINN_RAINBOWS and MICROLINN_SCALES





/************** linnstrument_firmware.ino ************************/

const byte MICROLINN_MAX_EDOSTEPS = MICROLINN_MAX_OFFSET * (MAXROWS - 1 + MAXCOLS - 1);     // 32 * 31 = 992

const byte MICROLINN_MAJ2ND[MICROLINN_MAX_EDO+1] = {  // for edos 6, 8, 10 and 12, semitones actually
  0,  0,  0,  0,  0,   1,  1,  1,  1,  1,    // 0-9 
  1,  1,  1,  1,  2,   3,  2,  3,  2,  3,    // 10-19 (13b and 18b)
  4,  3,  4,  3,  4,   5,  4,  5,  4,  5,    // 20-29
  6,  5,  6,  5,  6,   5,  6,  7,  6,  7,    // 30-39
  6,  7,  8,  7,  8,   7,  8,  7,  8,  9,    // 40-49
  8,  9,  8,  9, 10,   9                     // 50-55
};

// MICROLINN_SCALEROWS: for each of the 7 degrees + the octave, the last note in each row of the note lights display
//
//  for (byte edo = 5; edo <= MICROLINN_MAX_EDO; ++edo) {
//    byte M2 = MICROLINN_MAJ2ND[edo];                      // actually just a single edostep for edos 6, 8, 10 & 12
//    if (edo == 10 || edo == 12) M2 = 2;
//    byte m2 = ceil ((edo - 5 * M2) / 2.0);                // 6edo and 8edo need ceil
//    byte half2nd = floor (min (M2, m2) / 2.0);            // include half the intraordinal notes on this row
//    if (edo == 14 || edo == 28) half2nd -= 1;             // looks better
//
//    MICROLINN_SCALEROWS[edo][0] = half2nd;                // unisons
//    MICROLINN_SCALEROWS[edo][1] = half2nd + M2;           // 2nds
//    MICROLINN_SCALEROWS[edo][2] = half2nd + 2*M2;         // 3rds
//    MICROLINN_SCALEROWS[edo][3] = half2nd + 2*M2 + m2;    // 4ths
//    MICROLINN_SCALEROWS[edo][4] = half2nd + 3*M2 + m2;    // 5ths
//    MICROLINN_SCALEROWS[edo][5] = half2nd + 4*M2 + m2;    // 6ths
//    MICROLINN_SCALEROWS[edo][6] = half2nd + 5*M2 + m2;    // 7ths
//    MICROLINN_SCALEROWS[edo][7] = half2nd + edo;          // octaves
//
//    if (m2 == 0) {                                        // edos 5, 10, 15, 20, 25 and 30
//      MICROLINN_SCALEROWS[edo][2] -= 1;                   // one less 3rd, makes that last 3rd a 4th, since it's 480¢
//      MICROLINN_SCALEROWS[edo][6] -= 1;                   // one less 7th, makes that last 7th an 8ve, since it's 1200¢
//    }
//  }
//  MICROLINN_SCALEROWS[6][5] = 5;
//  MICROLINN_SCALEROWS[8][3] = 3;

const byte MICROLINN_SCALEROWS[MICROLINN_MAX_EDO+1][8] = { 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  1,  1,  2,  3,  4,  4,  5,  // 5edo **
  0,  1,  2,  3,  4,  5,  5,  6,  // 6edo ***
  0,  1,  2,  3,  4,  5,  6,  7,  // 7edo
  0,  1,  2,  3,  5,  6,  7,  8,  // 8edo ***
  0,  1,  2,  4,  5,  6,  7,  9,  // 9edo
  0,  2,  3,  4,  6,  8,  9, 10,  // 10  **
  0,  1,  2,  5,  6,  7,  8, 11,  // 11
  0,  2,  4,  5,  7,  9, 11, 12,  // 12
  0,  1,  2,  6,  7,  8,  9, 13,  // 13
  0,  2,  4,  6,  8, 10, 12, 14,  // 14  *
  0,  3,  5,  6,  9, 12, 14, 15,  // 15  **
  1,  3,  5,  8, 10, 12, 14, 17,  // 16
  0,  3,  6,  7, 10, 13, 16, 17,  // 17
  1,  3,  5,  9, 11, 13, 15, 19,  // 18
  1,  4,  7,  9, 12, 15, 18, 20,  // 19
  0,  4,  7,  8, 12, 16, 19, 20,  // 20  **
  1,  4,  7, 10, 13, 16, 19, 22,  // 21
  0,  4,  8,  9, 13, 17, 21, 22,  // 22
  1,  4,  7, 11, 14, 17, 20, 24,  // 23
  1,  5,  9, 11, 15, 19, 23, 25,  // 24
  0,  5,  9, 10, 15, 20, 24, 25,  // 25  **
  1,  5,  9, 12, 16, 20, 24, 27,  // 26
  0,  5, 10, 11, 16, 21, 26, 27,  // 27
  1,  5,  9, 13, 17, 21, 25, 29,  // 28  *
  1,  6, 11, 13, 18, 23, 28, 30,  // 29
  0,  6, 11, 12, 18, 24, 29, 30,  // 30  **
  1,  6, 11, 14, 19, 24, 29, 32,  // 31
  0,  6, 12, 13, 19, 25, 31, 32,  // 32
  2,  7, 12, 16, 21, 26, 31, 35,  // 33
  1,  7, 13, 15, 21, 27, 33, 35,  // 34
  2,  7, 12, 17, 22, 27, 32, 37,  // 35
  1,  7, 13, 16, 22, 28, 34, 37,  // 36
  0,  7, 14, 15, 22, 29, 36, 37,  // 37
  2,  8, 14, 18, 24, 30, 36, 40,  // 38
  1,  8, 15, 17, 24, 31, 38, 40,  // 39
  2,  8, 14, 19, 25, 31, 37, 42,  // 40
  1,  8, 15, 18, 25, 32, 39, 42,  // 41
  0,  8, 16, 17, 25, 33, 41, 42,  // 42
  2,  9, 16, 20, 27, 34, 41, 45,  // 43
  1,  9, 17, 19, 27, 35, 43, 45,  // 44
  2,  9, 16, 21, 28, 35, 42, 47,  // 45
  1,  9, 17, 20, 28, 36, 44, 47,  // 46
  3, 10, 17, 23, 30, 37, 44, 50,  // 47
  2, 10, 18, 22, 30, 38, 46, 50,  // 48
  1, 10, 19, 21, 30, 39, 48, 50,  // 49
  2, 10, 18, 23, 31, 39, 47, 52,  // 50
  1, 10, 19, 22, 31, 40, 49, 52,  // 51
  3, 11, 19, 25, 33, 41, 49, 55,  // 52
  2, 11, 20, 24, 33, 42, 51, 55,  // 53
  1, 11, 21, 23, 33, 43, 53, 55,  // 54
  2, 11, 20, 25, 34, 43, 52, 57   // 55
};

const byte MICROLINN_DOTS[MICROLINN_MAX_EDO+1][MAXCOLS+3] = { 
// goes to 28 columns so that the full octave can be deduced by symmetry for edos up to 55
// 0 = unmarked, 16 = single dot, 40 = double (4th/5th if > 5 dots per octave), 84 = triple (octave)
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0,84, 0,16,16, 0,84, 0,16,16, 0,84, 0,16,16, 0,84, 0,16,16, 0,84, 0,16,16, 0,84, 0,16,  //  5edo ---- edos 5-9 mark P4 and P5
  0,84, 0,16, 0,16, 0,84, 0,16, 0,16, 0,84, 0,16, 0,16, 0,84, 0,16, 0,16, 0,84, 0,16, 0,  //  6edo
  0,84, 0, 0,16,16, 0, 0,84, 0, 0,16,16, 0, 0,84, 0, 0,16,16, 0, 0,84, 0, 0,16,16, 0, 0,  //  7edo
  0,84, 0, 0,16, 0,16, 0, 0,84, 0, 0,16, 0,16, 0, 0,84, 0, 0,16, 0,16, 0, 0,84, 0, 0,16,  //  8edo
  0,84, 0, 0,16, 0, 0,16, 0, 0,84, 0, 0,16, 0, 0,16, 0, 0,84, 0, 0,16, 0, 0,16, 0, 0,84,  //  9edo (9b)
  0,84, 0,16, 0,16, 0,16, 0,16, 0,84, 0,16, 0,16, 0,16, 0,16, 0,84, 0,16, 0,16, 0,16, 0,  // 10edo --- edos 10-31 mark (M2) m3 P4 P5 M6 (m7)
  0,84, 0,16, 0,16, 0, 0,16, 0,16, 0,84, 0,16, 0,16, 0, 0,16, 0,16, 0,84, 0,16, 0,16, 0,  // 11edo (11b)
  0,84, 0, 0,16, 0,16, 0,16, 0,16, 0, 0,84, 0, 0,16, 0,16, 0,16, 0,16, 0, 0,84, 0, 0,16,  // 12edo
  0,84, 0,16, 0, 0,16, 0, 0,16, 0, 0,16, 0,84, 0,16, 0, 0,16, 0, 0,16, 0, 0,16, 0,84, 0,  // 13edo
  0,84, 0,16, 0,16, 0,40, 0,40, 0,16, 0,16, 0,84, 0,16, 0,16, 0,40, 0,40, 0,16, 0,16, 0,  // 14edo
  0,84, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,84, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,16,  // 15edo
  0,84, 0,16, 0, 0,16, 0,40, 0,40, 0,16, 0, 0,16, 0,84, 0,16, 0, 0,16, 0,40, 0,40, 0,16,  // 16edo
  0,84, 0, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0, 0,84, 0, 0, 0,16, 0, 0,16, 0, 0,16,  // 17edo
  0,84, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0,84, 0, 0,16, 0, 0, 0,16, 0, 0,  // 18edo
  0,84, 0, 0,16, 0,16, 0, 0,40, 0, 0,40, 0, 0,16, 0,16, 0, 0,84, 0, 0,16, 0,16, 0, 0,40,  // 19edo
  0,84, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,84, 0, 0, 0,16, 0, 0, 0,  // 20edo
  0,84, 0, 0,16, 0, 0,16, 0, 0,40, 0, 0,40, 0, 0,16, 0, 0,16, 0, 0,84, 0, 0,16, 0, 0,16,  // 21edo
  0,84, 0, 0, 0,16,16, 0, 0, 0,40, 0, 0, 0,40, 0, 0, 0,16,16, 0, 0, 0,84, 0, 0, 0,16,16,  // 22edo
  0,84, 0, 0,16, 0, 0, 0,16, 0, 0,40, 0, 0,40, 0, 0,16, 0, 0, 0,16, 0, 0,84, 0, 0,16, 0,  // 23edo
  0,84, 0, 0, 0,16, 0,16, 0, 0, 0,40, 0, 0, 0,40, 0, 0, 0,16, 0,16, 0, 0, 0,84, 0, 0, 0,  // 24edo
  0,84, 0, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0, 0,84, 0, 0,  // 25edo
  0,84, 0, 0, 0,16, 0, 0,16, 0, 0, 0,40, 0, 0, 0,40, 0, 0, 0,16, 0, 0,16, 0, 0, 0,84, 0,  // 26edo
  0,84, 0, 0, 0, 0,16,16, 0, 0, 0, 0,40, 0, 0, 0, 0,40, 0, 0, 0, 0,16,16, 0, 0, 0, 0,84,  // 27edo
  0,84, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,40, 0, 0, 0,40, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,  // 28edo
  0,84, 0, 0, 0, 0,16, 0,16, 0, 0, 0, 0,40, 0, 0, 0, 0,40, 0, 0, 0, 0,16, 0,16, 0, 0, 0,  // 29edo
  0,84, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,40, 0, 0,16, 0, 0,40, 0, 0,16, 0, 0,16, 0, 0,16,  // 30edo (exception -- 15edo dots doubled)
  0,84, 0, 0, 0, 0,16, 0, 0,16, 0, 0, 0, 0,40, 0, 0, 0, 0,40, 0, 0, 0, 0,16, 0, 0,16, 0,  // 31edo
  0,84, 0, 0,16, 0,16, 0, 0,16, 0,16, 0, 0,40, 0, 0,16, 0, 0,40, 0, 0,16, 0,16, 0, 0,16,  // 32edo --- edos 32-55 approximate 12edo
  0,84, 0, 0,16, 0, 0,16, 0,16, 0, 0,16, 0, 0,40, 0, 0, 0, 0,40, 0, 0,16, 0, 0,16, 0,16,  // 33edo
  0,84, 0, 0,16, 0, 0,16, 0,16, 0, 0,16, 0, 0,40, 0, 0,16, 0, 0,40, 0, 0,16, 0, 0,16, 0,  // 34edo
  0,84, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,40, 0, 0, 0, 0,40, 0, 0,16, 0, 0,16, 0,  // 35edo
  0,84, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,40, 0, 0,16, 0, 0,40, 0, 0,16, 0, 0,16,  // 36edo
  0,84, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,16, 0, 0,40, 0, 0,16,16, 0, 0,40, 0, 0,16, 0, 0,  // 37edo
  0,84, 0, 0,16, 0, 0,16, 0, 0, 0,16, 0, 0,16, 0, 0,40, 0, 0,16, 0, 0,40, 0, 0,16, 0, 0,  // 38edo
  0,84, 0, 0,16, 0, 0,16, 0, 0, 0,16, 0, 0,16, 0, 0,40, 0, 0,16,16, 0, 0,40, 0, 0,16, 0,  // 39edo
  0,84, 0, 0,16, 0, 0, 0,16, 0, 0,16, 0, 0, 0,16, 0, 0,40, 0, 0,16, 0, 0,40, 0, 0,16, 0,  // 40edo
  0,16, 0, 0, 0,40, 0, 0, 0,84, 0, 0, 0,16, 0, 0, 0,40, 0, 0, 0,84, 0, 0, 0,16, 0, 0, 0,  // 41edo (exception -- kite guitar dots)
  0,84, 0, 0,16, 0, 0, 0,16, 0, 0,16, 0, 0, 0,16, 0, 0,40, 0, 0, 0,16, 0, 0, 0,40, 0, 0,  // 42edo
  0,84, 0, 0, 0,16, 0, 0,16, 0, 0, 0,16, 0, 0,16, 0, 0, 0,40, 0, 0,16,16, 0, 0,40, 0, 0,  // 43edo
  0,84, 0, 0, 0,16, 0, 0,16, 0, 0, 0,16, 0, 0,16, 0, 0, 0,40, 0, 0, 0,16, 0, 0, 0,40, 0,  // 44edo
  0,84, 0, 0, 0,16, 0, 0, 0,16, 0, 0,16, 0, 0, 0,16, 0, 0, 0,40, 0, 0,16,16, 0, 0,40, 0,  // 45edo
  0,84, 0, 0, 0,16, 0, 0, 0,16, 0, 0,16, 0, 0, 0,16, 0, 0, 0,40, 0, 0, 0,16, 0, 0, 0,40,  // 46edo
  0,84, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,40, 0, 0,16,16, 0, 0,40,  // 47edo
  0,84, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,40, 0, 0, 0,16, 0, 0, 0,  // 48edo
  0,84, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,40, 0, 0, 0,16,16, 0, 0,  // 49edo (...0,40)
  0,84, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,40, 0, 0, 0,16, 0, 0,  // 50edo (...0,40)
  0,84, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0,40, 0, 0, 0,16,16, 0,  // 51edo (...0, 0,40)
  0,84, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0,40, 0, 0, 0,16, 0,  // 52edo (...0, 0,40)
  0,84, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0,40, 0, 0, 0,16,16,  // 53edo (...0, 0, 0,40)
  0,84, 0, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0, 0,40, 0, 0, 0,16,  // 54edo (...0, 0, 0,40)
  0,84, 0, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0, 0,16, 0, 0, 0,16, 0, 0, 0, 0,40, 0, 0, 0,16   // 55edo (...16,0, 0, 0,40)
};

//  white = 12-edo-ish = 3-limit = 8
//  yellow / green = downmajor / upminor =  5-over / 5-under = 10 / 3
//  blue / red = downminor / upmajor = 7-over / 7-under = 5 / 1
//  magenta = neutral = 11-over or 11-under or 13-over or 13-under = 6
//  pink = the exact half-octave of 600c, 12-edo-ish but not quite 3-limit, "off-white" = 11
//  cyan / orange = a catch-all pair, e.g. 7/5 and 10/7, cyan is also for outside notes aka interordinals e.g. 24edo = 4 / 9

const byte MICROLINN_RAINBOWS[MICROLINN_MAX_EDO+1][MICROLINN_MAX_EDO] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  8, 1, 8, 8, 5, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 5edo
  8,10,10,11, 3, 3, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 6
  8,10, 6, 8, 8, 6, 3, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 7
  8, 6, 3, 5,11, 1,10, 6, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 8
  8, 3, 5,10, 6, 6, 3, 1,10, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 9
  8, 3, 1, 6, 8,11, 8, 6, 5,10, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 10
  8, 3, 1, 3, 1, 6, 6, 5,10, 5,10, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 11
  8, 3,10, 3,10, 8,11, 8, 3,10, 3,10, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 12
  8, 6,10, 5,10, 5, 6, 6, 1, 3, 1, 3, 6, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 13
  8, 4,10, 5, 6, 1, 8,11, 8, 5, 6, 1, 3, 9, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 14
  8, 3,10, 1, 3,10, 8, 6, 6, 8, 3,10, 5, 3,10, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 15
  8, 6, 3,10, 3,10, 6, 8,11, 8, 6, 3,10, 3,10, 6, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 16
  8, 5, 6, 1, 5, 6, 1, 8, 4, 9, 8, 5, 6, 1, 5, 6, 1, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 17
  8, 5, 3,10, 5, 3,10, 5, 6,11, 6, 1, 3,10, 1, 3,10, 1, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 18
  8, 6, 3,10, 6, 3,10, 6, 8, 4, 9, 8, 6, 3,10, 6, 3,10, 6, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 19
  8, 6, 3,10, 1, 3,10, 5, 8, 6,11, 6, 8, 1, 3,10, 5, 3,10, 6, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 20
  8, 4, 3,10, 1, 5, 6,10, 1, 8, 4, 9, 8, 5, 3, 6, 1, 5, 3,10, 9, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 21
  8, 5, 3,10, 1, 5, 3,10, 1, 8, 4,11, 9, 8, 5, 3,10, 1, 5, 3,10, 1, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 22
  8, 4, 3, 6, 8, 5, 3,10, 8, 5, 8, 4, 9, 8, 1, 8, 3,10, 1, 8, 6,10, 9, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 23
  8, 4, 3, 6,10, 4, 3, 6,10, 4, 8, 6,11, 6, 8, 4, 3, 6,10, 4, 3, 6,10, 4, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 24
  8, 6, 4, 6,10, 1, 5, 3,10, 1, 8, 6, 4, 9, 6, 8, 5, 3,10, 1, 5, 3, 6, 9, 6, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 25
  8, 1, 5, 3,10, 1, 5, 3,10, 1, 5, 8, 6,11, 6, 8, 1, 5, 3,10, 1, 5, 3,10, 1, 5, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 26
  8, 5, 3, 6,10, 1, 5, 3, 6,10, 1, 8, 3, 4, 9,10, 8, 5, 3, 6,10, 1, 5, 3, 6,10, 1, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 27
  8, 5, 3, 6,10, 1, 5, 3, 6,10, 1, 5, 8, 6,11, 6, 8, 1, 5, 3, 6,10, 1, 5, 3, 6,10, 1, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 28
  8, 6, 8, 3,10, 8, 6, 8, 3,10, 8, 6, 8, 6, 4, 9, 6, 8, 6, 8, 3,10, 8, 6, 8, 3,10, 8, 6, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 29
  8, 6, 5, 3, 6,10, 1, 5, 3, 6,10, 1, 8, 3, 6,11, 6,10, 8, 5, 3, 6,10, 1, 5, 8, 6,10, 1, 6, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 30
  8, 1, 5, 3, 6,10, 1, 5, 3, 6,10, 1, 5, 8, 6,10, 3, 6, 8, 1, 5, 3, 6,10, 1, 5, 3, 6,10, 1, 5, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 31
  8, 4, 5, 3, 6,10, 1, 5, 3, 6,10, 1, 4, 8, 3, 6,11, 6,10, 8, 4, 5, 3, 6,10, 1, 5, 3, 6,10, 1, 4, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 32
  8, 4, 5, 3, 6,10, 1, 4, 5, 3, 6,10, 1, 5, 8, 6,10, 3, 6, 8, 1, 5, 3, 6,10, 1, 4, 5, 3, 6,10, 1, 4, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 33
  8, 4, 8, 3, 6,10, 8, 4, 8, 3, 6,10, 8, 4, 8, 3, 6,11, 6,10, 8, 4, 8, 3, 6,10, 8, 4, 8, 3, 6,10, 8, 4, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 34
  8, 1, 5, 3, 6,10, 8, 1, 5, 3, 6,10, 8, 1, 5, 8, 6,10, 3, 6, 8, 1, 5, 8, 3, 6,10, 1, 5, 8, 3, 6,10, 1, 5, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 35
  8, 1, 5, 3, 6, 6,10, 1, 5, 3, 6, 6,10, 1, 5, 8, 6, 6,11, 6, 6, 8, 1, 5, 3, 6, 6,10, 1, 5, 3, 6, 6,10, 1, 5, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 36

// white  8               cyan    4  
// blue   5               orange  9
// green  3               purple  6
// yellow 10 (lime)       pink   11
// red    1

  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 37
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 38
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 39
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 40
  8, 1, 5, 8, 3, 6,10, 8, 1, 5, 8, 3, 6,10, 8, 1, 5, 8, 3, 6, 4, 9, 6,10, 8, 1, 5, 8, 3, 6,10, 8, 1, 5, 8, 3, 6,10, 8, 1, 5, 0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 41
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0,0,0,0,0,0, // 42
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0,0,0,0,0, // 43
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0,0,0,0, // 44
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0,0,0, // 45
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0,0, // 46
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0,0, // 47
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0,0, // 48
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0,0, // 49
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0,0, // 50
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0,0, // 51
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,0,0, // 52
  8, 1, 4, 5, 8, 3, 6, 6,10, 8, 1, 4, 5, 8, 3, 6, 6,10, 8, 1, 4, 5, 8, 3, 6, 6,10, 3, 6, 6,10, 8, 1, 4, 5, 8, 3, 6, 6,10, 8, 1, 4, 5, 8, 3, 6, 6,10, 8, 1, 4, 5, 0,0, // 53
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, // 54
  8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2   // 55
};

const byte MICROLINN_SCALES[MICROLINN_MAX_EDO+1][MICROLINN_MAX_EDO] = {
// scale 0 = yo, 1 is gu, 2 = zo, 3 = ru, 4 = ila, 5 = blank but for the tonic, 6 = yaza rainbow, 7 = full rainbow, bit 7 is unused
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  127,76,76,76,76, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 5edo
  127,64,64, 0,64,64, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 6edo
  127,67, 3,67,67, 3,67, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 7edo
  127,64,64,64, 0,64,64,64, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 8edo
  127,64,64,64, 0, 0,64,64,64, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 9edo
  127, 0,64, 0,64, 0,64, 0,64, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 10
  127, 0,64,64,64, 0, 0,64,64,64, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 11
  127,64,67,66,65,67, 0,67,66,65,66,65, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 12
  127, 0,64,64,64,64, 0, 0,64,64,64,64, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 13
  127, 0,64,64,64,64,64, 0,64,64,64,64,64, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 14
  127,64,64, 3,66,65,67, 0, 0,67,66,65, 0,66,65, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 15
  127, 0,64,67,66,65, 0,67, 0,67, 0,66,65,66,65, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 16
  127,64, 0,76,68, 0,72,76, 0, 0,76,68, 0,72,68, 0,72, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 17
  127, 0,64,64,64,64,64,64,64, 0,64,64,64,64,64,64,64, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 18
  127, 0,64,67, 0,66,65, 0,67, 0, 0,67, 0,66,65, 0,66,65, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 19

  //  1y   2g   4z   8r   16l   32   64 ygzr
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 20
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 21
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 22
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 23
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 24
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 25
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 26
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 27
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 28
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 29
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 30
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 31
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 32
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 33
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 34
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 35
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 36
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 37
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 38
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 39
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 40
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 41
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 42
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 43
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 44
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 45
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 46
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 47
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 48
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 49
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 50
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 51
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 52
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 53
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 54
  127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0  // 55
};




// runtime vars
byte microLinnMidiNote[NUMSPLITS][MAXCOLS][MAXROWS];         // the midi note that is output for each cell, col 0 is unused
int microLinnFineTuning[NUMSPLITS][MAXCOLS][MAXROWS];        // the deviation from 12edo for each cell, as a pitch bend number from -8192 to 8191
byte microLinnEdostep[NUMSPLITS][MAXCOLS][MAXROWS];          // each cell's edosteps (mod EDO) relative to the anchor cell

byte microLinnOldEDO;                                        // for adjusting the row offset after an edo change
short microLinnRowOffsetCents;                               // set only when user sets row/col offset directly,
short microLinnColOffsetCents[NUMSPLITS];                    // avoids offset drift when switching edos
byte microLinnConfigColNum = 0;                       // active col number in microLinnConfig display, 0 means nothing active
boolean microLinnConfigNowScrolling = false;
char microLinnAnchorString[6] = "R C  ";              // row and column of the anchor cell, e.g. "R3C12", top row is row #1




// delete these once MICROLINN_SCALES is filled in
const float wa2nd = log(9.0/8.0) / log(2.0);            // ratios as a fraction of an octave
const float yo3rd = log(5.0/4.0) / log(2.0);
const float gu3rd = log(6.0/5.0) / log(2.0);
const float zo3rd = log(7.0/6.0) / log(2.0);
const float ru3rd = log(9.0/7.0) / log(2.0);
const float wa4th = log(4.0/3.0) / log(2.0);
const float wa5th = log(3.0/2.0) / log(2.0);
const float yo6th = log(5.0/3.0) / log(2.0);
const float gu6th = log(8.0/5.0) / log(2.0);
const float zo6th = log(14.0/9.0) / log(2.0);
const float ru6th = log(12.0/7.0) / log(2.0);
const float yo7th = log(15.0/8.0)/ log(2.0);
const float gu7th = log(9.0/5.0) / log(2.0);
const float zo7th = log(7.0/4.0) / log(2.0);
const float ru7th = log(27.0/14.0) / log(2.0);

// delete this once these arrays become const arrays
void microLinnInitializeScales() {

  for (byte edo = 20; edo <= MICROLINN_MAX_EDO; ++edo) {
    if (edo == 31 || edo == 41) {
      memset (&Device.microLinnScales[edo][0], 64, edo);         // scale 6 has most notes
    }
    Device.microLinnScales[edo][0] = 127;                        // every scale has the tonic

    Device.microLinnScales[edo][round(edo * wa2nd)] |= 1;        // set scale 0 to yo scale
    Device.microLinnScales[edo][round(edo * yo3rd)] |= 1; 
    Device.microLinnScales[edo][round(edo * wa4th)] |= 1;
    Device.microLinnScales[edo][round(edo * wa5th)] |= 1;
    Device.microLinnScales[edo][round(edo * yo6th)] |= 1;
    Device.microLinnScales[edo][round(edo * yo7th)] |= 1;

    Device.microLinnScales[edo][round(edo * wa2nd)] |= 2;        // set scale 1 to gu scale
    Device.microLinnScales[edo][round(edo * gu3rd)] |= 2; 
    Device.microLinnScales[edo][round(edo * wa4th)] |= 2; 
    Device.microLinnScales[edo][round(edo * wa5th)] |= 2; 
    Device.microLinnScales[edo][round(edo * gu6th)] |= 2; 
    Device.microLinnScales[edo][round(edo * gu7th)] |= 2; 

    Device.microLinnScales[edo][round(edo * wa2nd)] |= 4;        // set scale 2 to zo scale
    Device.microLinnScales[edo][round(edo * zo3rd)] |= 4; 
    Device.microLinnScales[edo][round(edo * wa4th)] |= 4;
    Device.microLinnScales[edo][round(edo * wa5th)] |= 4;
    Device.microLinnScales[edo][round(edo * zo6th)] |= 4;
    Device.microLinnScales[edo][round(edo * zo7th)] |= 4;

    Device.microLinnScales[edo][round(edo * wa2nd)] |= 8;        // set scale 3 to ru scale
    Device.microLinnScales[edo][round(edo * ru3rd)] |= 8; 
    Device.microLinnScales[edo][round(edo * wa4th)] |= 8; 
    Device.microLinnScales[edo][round(edo * wa5th)] |= 8; 
    Device.microLinnScales[edo][round(edo * ru6th)] |= 8; 
    Device.microLinnScales[edo][round(edo * ru7th)] |= 8; 
  }

  Device.microLinnScales[31][1] -= 64;                    // poke 10 holes in the 31edo rainbow 
  Device.microLinnScales[31][4] -= 64;
  Device.microLinnScales[31][9] -= 64;
  Device.microLinnScales[31][12] -= 64;
  Device.microLinnScales[31][14] -= 64;
  Device.microLinnScales[31][17] -= 64;
  Device.microLinnScales[31][19] -= 64;
  Device.microLinnScales[31][22] -= 64;
  Device.microLinnScales[31][27] -= 64;
  Device.microLinnScales[31][30] -= 64;

  Device.microLinnScales[41][1] -= 64;                    // poke 16 holes in the 41edo rainbow 
  Device.microLinnScales[41][3] -= 64;
  Device.microLinnScales[41][5] -= 64;
  Device.microLinnScales[41][10] -= 64;
  Device.microLinnScales[41][12] -= 64;
  Device.microLinnScales[41][14] -= 64;
  Device.microLinnScales[41][16] -= 64;
  Device.microLinnScales[41][18] -= 64;
  Device.microLinnScales[41][23] -= 64;
  Device.microLinnScales[41][25] -= 64;
  Device.microLinnScales[41][27] -= 64;
  Device.microLinnScales[41][29] -= 64;
  Device.microLinnScales[41][31] -= 64;
  Device.microLinnScales[41][36] -= 64;
  Device.microLinnScales[41][38] -= 64;
  Device.microLinnScales[41][40] -= 64;
}



// (could possibly instead put the init function in initializeDeviceSettings in ls_settings.ino)
void resetMicroLinn() {                     // called in reset(), runs when microLinn firmware is first installed
  Device.microLinn.EDO = 4;                      
  Device.microLinn.octaveStretch = 0; 
  Device.microLinn.anchorRow = 4;                 // 4th row from the top
  Device.microLinn.anchorCol = 11;
  Device.microLinn.anchorNote = 60;               // middle-C
  Device.microLinn.anchorCents = 0;  
  Device.microLinn.colOffset[LEFT] = 1;
  Device.microLinn.colOffset[RIGHT] = 1;
  Device.microLinn.transposeEDOsteps[LEFT] = 0;
  Device.microLinn.transposeEDOsteps[RIGHT] = 0;
  Device.microLinn.transposeEDOlights[LEFT] = 0;
  Device.microLinn.transposeEDOlights[RIGHT] = 0;
  memcpy (Device.microLinnDots, MICROLINN_DOTS, sizeof(Device.microLinnDots));
  memcpy (Device.microLinnRainbows, MICROLINN_RAINBOWS, sizeof(Device.microLinnRainbows));
  memcpy (Device.microLinnScales, MICROLINN_SCALES, sizeof(Device.microLinnScales));
  memset (Device.microLinnCurrScale, 0, sizeof(Device.microLinnCurrScale));
  Global.activeNotes = 0;
  initializeMicroLinn();
}

void initializeMicroLinn() {                  // called in setup(), runs every time the Linnstrument powers up
    Global.setSwitchAssignment(3, ASSIGNED_MICROLINN_EDO_UP,   false);  // for debugging
    Global.setSwitchAssignment(2, ASSIGNED_MICROLINN_EDO_DOWN, false);  // for debugging
  microLinnSetGlobalView();
  microLinnInitializeScales();                // delete this line once those arrays are getting saved
  microLinnStoreRowOffsetCents();
  microLinnStoreColOffsetCents(LEFT);
  microLinnStoreColOffsetCents(RIGHT);
  microLinnOldEDO = Device.microLinn.EDO;
  microLinnCalcTuning ();
  updateDisplay();
  microLinnUpdateAnchorString ();
}

void microLinnSetKiteGuitarDefaults() {
  Device.microLinn.EDO = 41;
  Device.microLinn.octaveStretch = 0;
  Device.microLinn.anchorRow = 3;                           // 5th row from top, places the two rainbows nicely
  Device.microLinn.anchorCol = 6;
  Device.microLinn.anchorNote = 54;                         // ^F#2, Kite guitar standard tuning with D = 0 cents
  Device.microLinn.anchorCents = 39;                        // ^M3 = 439c
  Device.microLinn.colOffset[LEFT] = 2;
  Device.microLinn.colOffset[RIGHT] = 2;
  Global.rowOffset = ROWOFFSET_OCTAVECUSTOM;
  Global.customRowOffset = 13;                        // 41-equal downmajor 3rds
  microLinnStoreRowOffsetCents();
  microLinnStoreColOffsetCents(LEFT);
  microLinnStoreColOffsetCents(RIGHT);
  microLinnUpdateAnchorString();
  microLinnSetGlobalView();
  microLinnOldEDO = 41;                               // to avoid microLinnAdjustRowAndColOffsets()
  microLinnCalcTuning();
  Device.microLinnCurrScale[41] = 6;
  Split[LEFT].playedTouchMode = playedBlink;
  Split[RIGHT].playedTouchMode = playedBlink;
}

void microLinnResetTo12equal() {
  Device.microLinn.EDO = 12;
  Device.microLinn.octaveStretch = 0; 
  //Device.microLinn.anchorRow = 4;                 // 4th row from top
  //Device.microLinn.anchorCol = 11; 
  //Device.microLinn.anchorNote = 60;               // middle-C
  //microLinnUpdateAnchorString();
  Device.microLinn.anchorCents = 0;
  Device.microLinn.colOffset[LEFT] = 1;
  Device.microLinn.colOffset[RIGHT] = 1;
  Global.rowOffset = 5;
  microLinnStoreRowOffsetCents();
  microLinnStoreColOffsetCents(LEFT);
  microLinnStoreColOffsetCents(RIGHT);
  microLinnOldEDO = 12;                                 // to avoid microLinnAdjustRowAndColOffsets()
  microLinnCalcTuning();
  Global.activeNotes = 0;                              // set display to the major scale
  loadCustomLedLayer(getActiveCustomLedPattern());
}

int microLinnMod (int num, int base) {                       // -13 % 10 = -3, but microLinnMod (-13, 10) = 7
  num %= base;
  if (num < 0) num += base;
  return num;
}

short microLinnGCD (short x, short y) {         // returns the greatest common divisor of x & y
  x = abs (x); y = abs (y);                     // the GCD is always positive
  if (x == 0) return y;                         // ensures GCD (0, y) = y
  if (y == 0) return x;                         // ensures GCD (x, 0) = x
  short z;
  while (x > 0) {
    if (x < y) {z = x; x = y; y = z;}           // swap x and y
    x %= y;
  }
  return max (x, y);                            // GCD (0, 0) = 0
}

short microLinnLCM (short x,  short y) {        // returns the least common multiple of x & y
  float z = microLinnGCD (x, y);
  return (z == 0 ? 0 : abs (x * y) / z);        // LCM (x, 0) = x, LCM (0, y) = y, LCM (0, 0) = 0
}

signed char microLinnSign (short num) {
  if (num > 0) return 1;
  if (num < 0) return -1;
  return 0;
}

boolean isMicroLinnOn() {
  return Device.microLinn.EDO >= 5;
}

void microLinnUpdateAnchorString() {
  char col1, col2;
  if (Device.microLinn.anchorCol < 10) {
    col1 = '0' + Device.microLinn.anchorCol;
    col2 = ' ';
  } else {
    col1 = '0' + floor (Device.microLinn.anchorCol / 10.0);
    col2 = '0' + Device.microLinn.anchorCol % 10;
  }
  if (LINNMODEL == 128 && Device.microLinn.anchorCol >= 10) {      // "3 12 ", drop R and C to fit 3 digits in
    microLinnAnchorString[0] = '8' - Device.microLinn.anchorRow; 
    microLinnAnchorString[1] = ' ';
    microLinnAnchorString[2] = col1;
    microLinnAnchorString[3] = col2;
    microLinnAnchorString[4] = ' ';
  } else {
    microLinnAnchorString[0] = 'R';                               // "R3C12"
    microLinnAnchorString[1] = '8' - Device.microLinn.anchorRow;
    microLinnAnchorString[2] = 'C';
    microLinnAnchorString[3] = col1;
    microLinnAnchorString[4] = col2;
  }
}

byte microLinnGetNoteNumber(byte side, byte col, byte row) {
  return microLinnMidiNote[side][col][row];
}

void microLinnStoreRowOffsetCents() {               // called from handleGlobalSettingNewTouch, handleGlobalSettingHold
  byte edo = Device.microLinn.EDO;
  if (edo == 4) edo = 12;                           // because "OFF" is 4edo which is really 12edo
  microLinnRowOffsetCents = (Global.rowOffset == ROWOFFSET_OCTAVECUSTOM ? Global.customRowOffset : Global.rowOffset);
  microLinnRowOffsetCents *= 1200.0 / edo;          // convert to cents
}

void microLinnStoreColOffsetCents(byte side) {
  byte edo = Device.microLinn.EDO;
  if (edo == 4) edo = 12;                           // because "OFF" is 4edo which is really 12edo
  microLinnColOffsetCents[side] = Device.microLinn.colOffset[side] * 1200.0 / edo;          // convert to cents
}

void microLinnAdjustRowAndColOffsets () {         
  // going from say 12edo to 19edo adjusts the row offset from +5 (12edo 4th) to +8 (19edo 4th)
  if (Device.microLinn.EDO == microLinnOldEDO) return;
  // user can keep the row offset constant by using an isomorphic guitar tuning
  if (Global.rowOffset == ROWOFFSET_GUITAR ||
      Global.rowOffset == ROWOFFSET_NOOVERLAP ||
      Global.rowOffset == ROWOFFSET_ZERO) {
    return;
  }
  byte edo = Device.microLinn.EDO;
  if (edo == 4) edo = 12;                                               // because "OFF" is 4edo which is really 12edo

  short rowOffset = round (edo * microLinnRowOffsetCents / 1200.0);     // avoid drift as user changes edos
  if (rowOffset == 0) {                                                 // could happen when going from a large edo to a small one
    rowOffset = microLinnSign(Global.rowOffset == ROWOFFSET_OCTAVECUSTOM ? Global.customRowOffset : Global.rowOffset);
  }

  short leftOffset = Device.microLinn.colOffset[LEFT];
  if (leftOffset > 1 || leftOffset < -1) {                              // don't adjust offsets of 1, -1 or 0
    leftOffset = round (edo * microLinnColOffsetCents[LEFT] / 1200.0);
    if (leftOffset == 0) leftOffset = microLinnSign(Device.microLinn.colOffset[LEFT]);   // don't adjust all the way to zero
  }
  short rightOffset = Device.microLinn.colOffset[RIGHT];
  if (rightOffset > 1 || rightOffset < -1) { 
    rightOffset = round (edo * microLinnColOffsetCents[RIGHT] / 1200.0);
    if (rightOffset == 0) rightOffset = microLinnSign(Device.microLinn.colOffset[RIGHT]);
  }

  // ensure coprime row/col offsets so that all notes of the edo are present
  // e.g. 12edo +5 +2 --> 24edo +10 +4 --> 24edo +11 +4
  // bug: ideally if the col offset were bigger than the row offset, the col offset would get adjusted
  short colOffsetLCM = microLinnLCM (leftOffset, rightOffset); 
  if (colOffsetLCM > 1) {
    short zigzagBy = (rowOffset * 1200 > microLinnRowOffsetCents * edo) ? -1 : 1;    // really offset/edo > offsetCents/1200
    while (microLinnGCD (rowOffset, colOffsetLCM) > 1) {     // exits when rowOffset is a prime number if not sooner
      rowOffset += zigzagBy;
      zigzagBy += zigzagBy > 0 ? 1 : -1;                     // zigzag through the nearest numbers,
      zigzagBy *= -1;                                        // e.g. 9 --> 8 --> 10 --> 7
    }
  }
  // store the new offsets
  if (rowOffset < 3 || rowOffset > 7) {
    Global.rowOffset = ROWOFFSET_OCTAVECUSTOM;
    Global.customRowOffset = rowOffset;
  } else {
    Global.rowOffset = rowOffset;
  }
  Device.microLinn.colOffset[LEFT] = leftOffset;
  Device.microLinn.colOffset[RIGHT] = rightOffset;
  microLinnOldEDO = Device.microLinn.EDO;
}

short microLinnTransposition(byte side) {                                    // # of edosteps to transposeEDOsteps by
  short octaves = Split[side].transposeOctave / 12.0;
  return octaves * Device.microLinn.EDO
       + Split[side].transposePitch  * MICROLINN_MAJ2ND[Device.microLinn.EDO]      // semitones are interpreted as whole tones
       - Split[side].transposeLights * MICROLINN_MAJ2ND[Device.microLinn.EDO]
       + Device.microLinn.transposeEDOsteps[side]
       - Device.microLinn.transposeEDOlights[side];
}

short microLinnSumOfRowOffsets (byte row1, byte row2) {      // edosteps from row1 to row2
  switch (Global.rowOffset) {
    case ROWOFFSET_OCTAVECUSTOM: return Global.customRowOffset  * (row2 - row1);
    case ROWOFFSET_GUITAR:       return Global.guitarTuning[row2] - Global.guitarTuning[row1];
    case ROWOFFSET_NOOVERLAP:    return (NUMCOLS - 1) * (row2 - row1);
    case ROWOFFSET_ZERO:         return 0;
    default:                     return Global.rowOffset * (row2 - row1); 
  }
}

void microLinnCalcTuning() { 
  // calcs microLinnEdostep, microLinnMidiNote and microLinnFineTuning
  // called when any column 0 button is released and we return to normal playing mode
  // also called when entering microLinnConfig note lights display or leaving anchor cell display
  // needed for any change on microLinnConfig, lefthandedness, row offsets, transpose or bendrange
  // also for octave up/down via switch1/switch2 control buttons or footswitch presses

  clearDisplay();                                            // to avoid flickering while all this runs, not sure it works
  microLinnAdjustRowAndColOffsets();

  //if (ignoreSlides && sensorCell->velocity) return;       // don't calc on releases caused by slides, causes flickering
  byte edo = Device.microLinn.EDO;
  if (edo == 4) edo = 12;

  byte anchorCol = Device.microLinn.anchorCol;
  byte anchorRow = Device.microLinn.anchorRow; 
  // anchorPitch = a midi note, but with 2 decimal places for anchorCents
  float anchorPitch = Device.microLinn.anchorNote + Device.microLinn.anchorCents / 100.0;
  // edostepSize = size of 1 edostep/arrow in semitones, e.g. 1\41 is 0.29 semitones
  float edostepSize = (1200 + Device.microLinn.octaveStretch) / (100.0 * edo);

  for (short side = 0; side < NUMSPLITS; ++side) {
    short colOffset = Device.microLinn.colOffset[side];
    short transpose = microLinnTransposition(side);
    for (byte row = 0; row < NUMROWS; ++row) {
      short rowDistance = microLinnSumOfRowOffsets (anchorRow, row) + transpose;
      for (byte col = 1; col < NUMCOLS; ++col) {
        short cellDistance = rowDistance + (col - anchorCol) * colOffset;            // cellDistance = distance from the anchor cell in edosteps
        microLinnEdostep[side][col][row] = microLinnMod(cellDistance, edo);          // octave-reduce
        float note = anchorPitch + cellDistance * edostepSize;                       // convert from edosteps to fractional 12edo midi note
        if (note > 127 || note < 0) {
          microLinnMidiNote[side][col][row] = 255;
          microLinnFineTuning[side][col][row] = 0;
        } else {
          microLinnMidiNote[side][col][row] = round (note);
          float fineTuningBend = note - microLinnMidiNote[side][row][col];           // fine-tuning bend as fraction of a semitone
          fineTuningBend *= 8192.0 / getBendRange (side);                            // fine-tuning bend as a zero-centered signed 13-bit integer
          microLinnFineTuning[side][col][row] = round (fineTuningBend);
        }
      }
      performContinuousTasks();                                                      // to avoid flickering 
    }
  }
}

void microLinnSendDebugMidi (byte channel, byte CCnum, short data) {     // channels run 1-16
  if (data < 0) {channel += 1; data = -data;}
  byte databyte = min (data, 127);
  midiSendControlChange(CCnum, databyte, channel);
}

void microLinnTuneNewSeqEvent() {

  if (!isMicroLinnOn()) return;

  // to do: write code that tunes each new note to the edo
  // something like this:
  //   data[0] = microLinnMidiNote[side][sensorRow][sensorCol];
  //   data[3] = microLinnFineTuning[side][sensorRow][sensorCol];  (but convert it to cents)

  // in ls_sequencer.ino, find "void StepEvent::setNewEvent" and add microLinnTuneNewSeqEvent() at the end
  // find "getFaderMin" and "getFaderMax" and let the bend vary by 127 cents each way (pitchOffset is a signed char)
}


/**************************************** FORK MENU ****************************************/

const byte NUM_FORKS = 3;
const byte MAX_LONGPRESS_MESSAGES = 3;     // after the 3rd long-press of OS version since power-up,
byte numTimesForkMenu = 0;                 // stop showing the "LONG-PRESS FOR FORK NAMES" message
byte forkMenuColNum = 0;                   // active column number in fork menu, 0 means nothing active
boolean forkMenuNowScrolling = false;

/**************************************** BRIGHTNESS FORK ****************************************/
byte brightness = 12;               // ranges from 1 to 12, each fork must have one byte that is never zero




/************** ls_displayModes.ino ************************/

// these functions augment or replace existing functions 

void microLinnPaintNormalDisplayCell(byte split, byte col, byte row) {
  // by default clear the cell color
  byte colour = COLOR_OFF;
  CellDisplay cellDisplay = cellOff;
  byte midiNote = microLinnMidiNote[split][col][row];
  byte edostep = microLinnEdostep[split][col][row];
  byte edo = Device.microLinn.EDO;
  byte currScale = Device.microLinnCurrScale[edo];

  // unless the note is out of MIDI note range, show it
  if (midiNote <= 127 && !customLedPatternActive) {
    // either dots...
    if (currScale == 8) {
      byte col2 = (Device.microLinn.colOffset[LEFT] < 0 && Device.microLinn.colOffset[RIGHT] < 0) ? NUMCOLS - col : col;
      if (Device.microLinnDots[edo][col2] & (1 << row)) {
        colour = Split[LEFT].colorMain;
        cellDisplay = cellOn;
      }
    } 
    // ...or rainbows
    else if (displayMode == displayMicroLinnAnchorChooser && 
             col == Device.microLinn.anchorCol && 
             row == Device.microLinn.anchorRow)  {
      colour = Device.microLinnRainbows[edo][edostep];
      if (colour == COLOR_OFF) {colour = COLOR_WHITE;}
      cellDisplay = cellSlowPulse;
    }
    else if (currScale == 7 || Device.microLinnScales[edo][edostep] & (1 << currScale)) {
      colour = Device.microLinnRainbows[edo][edostep];
      cellDisplay = cellOn;
    }
    // show pulsating anchor cell if in the octave centered on middle-C
    if (blinkMiddleRootNote && edostep == 0 && midiNote >= 55 && midiNote < 67) {       // G to F#
      colour = Split[split].colorAccent;
      cellDisplay = cellFastPulse;
    }
  }

  // if the low row is anything but normal, set it to the appropriate color
  if (row == 0 && Split[split].lowRowMode != lowRowNormal) {
    if ((Split[split].lowRowMode == lowRowCCX && Split[sensorSplit].lowRowCCXBehavior == lowRowCCFader) ||
        (Split[split].lowRowMode == lowRowCCXYZ && Split[sensorSplit].lowRowCCXYZBehavior == lowRowCCFader)) {
      colour = COLOR_BLACK;
      cellDisplay = cellOff;
    }
    else {
      colour = Split[split].colorLowRow;
      cellDisplay = cellOn;
    }
    // actually set the cell's color
    setLed(col, row, colour, cellDisplay, LED_LAYER_LOWROW);
  }
  else {
    // actually set the cell's color
    if (row == 0) {
      clearLed(col, row, LED_LAYER_LOWROW);
    }
    setLed(col, row, colour, cellDisplay, LED_LAYER_MAIN);
  }
}

void  microLinnPaintEdostepTranspose(bool doublePerSplit, byte side) {
  // paint the 2 new rows on the transpose display
  if (!isMicroLinnOn()) return;
  if (MICROLINN_MAJ2ND[Device.microLinn.EDO] == 1) return;

  // Paint the edostep transpose values
  if (!doublePerSplit || Device.microLinn.transposeEDOsteps[LEFT] == Device.microLinn.transposeEDOsteps[RIGHT]) {
    paintTranspose(Split[Global.currentPerSplit].colorMain, SPLIT_ROW, Device.microLinn.transposeEDOsteps[side]);
  }
  else if (doublePerSplit) {
    if (abs(Device.microLinn.transposeEDOsteps[LEFT]) > abs(Device.microLinn.transposeEDOsteps[RIGHT])) {
      paintTranspose(Split[LEFT].colorMain, SPLIT_ROW, Device.microLinn.transposeEDOsteps[LEFT]);
      paintTranspose(Split[RIGHT].colorMain, SPLIT_ROW, Device.microLinn.transposeEDOsteps[RIGHT]);
    }
    else {
      paintTranspose(Split[RIGHT].colorMain, SPLIT_ROW, Device.microLinn.transposeEDOsteps[RIGHT]);
      paintTranspose(Split[LEFT].colorMain, SPLIT_ROW, Device.microLinn.transposeEDOsteps[LEFT]);
    }
  }

  // Paint the edostep-light transpose values
  if (!doublePerSplit || Device.microLinn.transposeEDOlights[LEFT] == Device.microLinn.transposeEDOlights[RIGHT]) {
    paintTranspose(Split[Global.currentPerSplit].colorMain, GLOBAL_SETTINGS_ROW, Device.microLinn.transposeEDOlights[side]);
  }
  else if (doublePerSplit) {
    if (abs(Device.microLinn.transposeEDOlights[LEFT]) > abs(Device.microLinn.transposeEDOlights[RIGHT])) {
      paintTranspose(Split[LEFT].colorMain, GLOBAL_SETTINGS_ROW, Device.microLinn.transposeEDOlights[LEFT]);
      paintTranspose(Split[RIGHT].colorMain, GLOBAL_SETTINGS_ROW, Device.microLinn.transposeEDOlights[RIGHT]);
    }
    else {
      paintTranspose(Split[RIGHT].colorMain, GLOBAL_SETTINGS_ROW, Device.microLinn.transposeEDOlights[RIGHT]);
      paintTranspose(Split[LEFT].colorMain, GLOBAL_SETTINGS_ROW, Device.microLinn.transposeEDOlights[LEFT]);
    }
  }
}

void microLinnLightOctaveSwitch() {

  if (!isMicroLinnOn()) return;

  // light the octave/transpose switch if the pitch is transposed by edosteps
  if ((Device.microLinn.transposeEDOsteps[LEFT] < 0 && Device.microLinn.transposeEDOsteps[RIGHT] < 0) ||
      (Device.microLinn.transposeEDOsteps[LEFT] < 0 && Device.microLinn.transposeEDOsteps[RIGHT] == 0) ||
      (Device.microLinn.transposeEDOsteps[LEFT] == 0 && Device.microLinn.transposeEDOsteps[RIGHT] < 0)) {
    setLed(0, OCTAVE_ROW, COLOR_RED, cellOn);
  }
  else if ((Device.microLinn.transposeEDOsteps[LEFT] > 0 && Device.microLinn.transposeEDOsteps[RIGHT] > 0) ||
           (Device.microLinn.transposeEDOsteps[LEFT] > 0 && Device.microLinn.transposeEDOsteps[RIGHT] == 0) ||
           (Device.microLinn.transposeEDOsteps[LEFT] == 0 && Device.microLinn.transposeEDOsteps[RIGHT] > 0)) {
    setLed(0, OCTAVE_ROW, COLOR_GREEN, cellOn);
  }
  else if (Device.microLinn.transposeEDOsteps[LEFT] != 0 && Device.microLinn.transposeEDOsteps[RIGHT] != 0) {
    setLed(0, OCTAVE_ROW, COLOR_YELLOW, cellOn);
  }
  else {
    clearLed(0, OCTAVE_ROW);
  }
}

// these functions don't augment or replace existing functions, they do something new

void paintMicroLinnConfigButtons() {
  for (byte col = 2; col <= 15; ++col) { 
    if (col == 4 || col == 8 || col == 11 || col == 13) col += 1;                // skip over empty columns
    setLed(col, 0, col == microLinnConfigColNum ? Split[LEFT].colorAccent : Split[LEFT].colorMain, cellOn);
  }
}

void paintMicroLinnConfig() {
  clearDisplay();
  paintMicroLinnConfigButtons();

  if (microLinnConfigNowScrolling) {
    // leading spaces ensure the string first appears on the right edge, not on the left edge
    switch (microLinnConfigColNum) {
      case 2: 
        small_scroll_text_row1("      EDO (NOTES PER OCTAVE)", Split[LEFT].colorMain);
        break;
      case 3: 
        if (isMicroLinnOn()) {
          small_scroll_text_row1("      OCTAVE STRETCH IN CENTS", Split[LEFT].colorMain);
        } else {
          small_scroll_text_row1("      FIRST SELECT AN EDO", Split[LEFT].colorMain);
        }
        break;
      case 5: 
        if (isMicroLinnOn()) {
          small_scroll_text_row1("      CHOOSE ANCHOR CELL", Split[LEFT].colorMain);
        } else {
          small_scroll_text_row1("      FIRST SELECT AN EDO", Split[LEFT].colorMain);
        }
        break;
      case 6: 
        if (isMicroLinnOn()) {
          small_scroll_text_row1("      ANCHOR NOTE", Split[LEFT].colorMain);
        } else {
          small_scroll_text_row1("      FIRST SELECT AN EDO", Split[LEFT].colorMain);
        }
        break;
      case 7: 
        if (isMicroLinnOn()) {
          small_scroll_text_row1("      ANCHOR CENTS", Split[LEFT].colorMain);
        } else {
          small_scroll_text_row1("      FIRST SELECT AN EDO", Split[LEFT].colorMain);
        }
        break;
      case 9: 
        small_scroll_text_row1("      LEFT COLUMN OFFSET", Split[LEFT].colorMain);
        break;
      case 10: 
        small_scroll_text_row1("      RIGHT COLUMN OFFSET", Split[RIGHT].colorMain);
        break;
      case 12: 
        if (isMicroLinnOn()) {
          small_scroll_text_row1("      SET NOTE LIGHTS", Split[LEFT].colorMain);
        } else {
          small_scroll_text_row1("      FIRST SELECT AN EDO", Split[LEFT].colorMain);
        }
        break;
      case 14: 
        small_scroll_text_row1("      SET TO KITE GUITAR", Split[LEFT].colorMain);
        break;
      case 15: 
        small_scroll_text_row1("      RESET TO 12-EQUAL", Split[LEFT].colorMain);
        break;
    }
    paintMicroLinnConfigButtons();
  }

  signed char offset = 0;
  switch (microLinnConfigColNum) {
    case 2: 
      if (Device.microLinn.EDO < 5) {
        smallfont_draw_string(4, 1, "OFF", globalColor, false);
      } else {
        paintNumericDataDisplayRow(globalColor, Device.microLinn.EDO, 0, 1, false);
      }
      break;
    case 3: 
      if (!isMicroLinnOn()) break;
      if (Device.microLinn.octaveStretch <= -100) {
        offset = -5;
      } else if (Device.microLinn.octaveStretch <= -10) {
        offset = -3;
      }
      paintNumericDataDisplayRow(globalColor, Device.microLinn.octaveStretch, offset, 1, false);
      break;
    case 5:  
      if (!isMicroLinnOn()) break;
      if (LINNMODEL == 200) {
        smallfont_draw_string(1, 1, microLinnAnchorString, globalColor);
      } else {
        condfont_draw_string(1, 1, microLinnAnchorString, globalColor);
      }
      break;  
    case 6: 
      if (!isMicroLinnOn()) break;
      paintNoteDataDisplay(globalColor, Device.microLinn.anchorNote, LINNMODEL == 200 ? 2 : 1, 1);
      break;
    case 7: 
      if (!isMicroLinnOn()) break;
      if (Device.microLinn.anchorCents <= -100) {
        offset = -5;
      } else if (Device.microLinn.anchorCents <= -10) {
        offset = -3;
      }
      paintNumericDataDisplayRow(globalColor, Device.microLinn.anchorCents, offset, 1, false);
      break;
    case 9:
      paintNumericDataDisplayRow(Split[LEFT].colorMain, Device.microLinn.colOffset[LEFT], 0, 1, false);
      break;
    case 10: 
      paintNumericDataDisplayRow(Split[RIGHT].colorMain, Device.microLinn.colOffset[RIGHT], 0, 1, false);
      break;
    case 12:
      if (!isMicroLinnOn()) break;
      PaintMicroLinnNoteLights();
      break; 
    case 14:
    case 15:
      break;
  }
}

void PaintMicroLinnNoteLights() {
  clearDisplay();
  paintMicroLinnConfigButtons();

  byte col = 12;       
  byte stepspan = 0;                                                            // the degree (2nd, 3rd, etc.) minus 1
  byte edo = Device.microLinn.EDO;
  byte currScale = Device.microLinnCurrScale[edo];

  if (currScale <= 7) {                                                         // paint the scale 
    for (byte edostep = 0; edostep < edo; ++edostep) {
      if (edostep > MICROLINN_SCALEROWS[edo][stepspan]) {                       // reached the end? on to the next row
        stepspan += 1;
        if (edo == 5 && stepspan == 2) stepspan = 3;                            // skip over 5edo's empty row of 3rds
        col -= MICROLINN_SCALEROWS[edo][stepspan] - MICROLINN_SCALEROWS[edo][stepspan - 1];
      }
      if (currScale == 7 || Device.microLinnScales[edo][edostep] & (1 << currScale)) {
        setLed(col, 7 - (stepspan % 7), Device.microLinnRainbows[edo][edostep], cellOn);
      }
      col += 1; 
    }
    col = MICROLINN_SCALEROWS[edo][0];                                                // pink borders
    for (stepspan = 0; stepspan < 7; ++stepspan) {
      setLed(col + 14, 7 - stepspan, COLOR_PINK, cellOn);
    }
    col = MICROLINN_SCALEROWS[edo][1] - MICROLINN_SCALEROWS[edo][0];                  // 2nd - 1sn = major 2nd
    col = max (col, MICROLINN_SCALEROWS[edo][3] - MICROLINN_SCALEROWS[edo][2]);       // 4th - 3rd = minor 2nd
    col -= MICROLINN_SCALEROWS[edo][0];
    if (edo == 8) col += 1;                                                           // 8edo is weird lol
    for (stepspan = 0; stepspan < 7; ++stepspan) {
      setLed(11 - col, 7 - stepspan, COLOR_PINK, cellOn);
    }
  } else {
    paintMicroLinnDotsEditor(false);                                                  // blue dots 
  } 

  for (byte scaleNum = 0; scaleNum < 7; ++scaleNum) {                                        // the 7 scale buttons
    setLed(1, 7 - scaleNum, scaleNum == currScale ? Split[LEFT].colorAccent : Split[LEFT].colorMain, cellOn);
  }
  setLed(3, 7, currScale == 7 ? Split[LEFT].colorAccent : Split[LEFT].colorMain, cellOn);    // color editor
  setLed(3, 5, currScale == 8 ? Split[LEFT].colorAccent : Split[LEFT].colorMain, cellOn);    // dots selector
  setLed(3, 3, Split[LEFT].colorMain, cellOn);                                               // mass selector/resetter
}

void paintMicroLinnDotsEditor(boolean showAll) {
  if (showAll) clearDisplay();
  for (byte col = showAll ? 1 : 4; col < NUMCOLS; ++col) {
    for (byte row = showAll ? 0 : 1; row < MAXROWS; ++row) {
      if (Device.microLinnDots[Device.microLinn.EDO][col] & (1 << row)) {
        setLed(col, row, globalColor, cellOn);
      }
    }
  }
}

void paintForkMenuButtons() {
  for (byte col = 1; col <= NUM_FORKS; ++col) {
    setLed(col, 0, col == forkMenuColNum ? Split[LEFT].colorAccent : Split[LEFT].colorMain, cellOn);
  }
}

void paintForkMenu() {
  clearDisplay();
  paintForkMenuButtons();
  // leading spaces ensure the string first appears on the right edge, not on the left edge
  switch (forkMenuColNum) {    
    case 0:
      if (numTimesForkMenu <= MAX_LONGPRESS_MESSAGES) {
        small_scroll_text_row1("       LONG-PRESS FOR FORK NAMES", Split[LEFT].colorMain);
      }
      break;
    case 1: 
      small_scroll_text_row1("      MICROLINN", Split[LEFT].colorMain);
      break;
    case 2: 
      small_scroll_text_row1("      BRIGHTNESS", Split[LEFT].colorMain);
      break;
    case 3:
      small_scroll_text_row1("      YOUR FORK HERE", Split[LEFT].colorMain);
      break;  
  }
  paintForkMenuButtons();
}

void paintBrightnessScreen() {
  clearDisplay();
  setLed(2, 6, Split[LEFT].colorAccent, cellOn);                       // zero marker, like on the transpose screen
  for (byte col = 14; col > 2; --col ) {
    setLed(col, 6, col - 2 > brightness ? COLOR_BLACK : Split[LEFT].colorMain, cellOn);       // black erases
  }
}


/************** ls_settings.ino ************************/

void enterForkMenu () {
  forkMenuColNum = 0;
  numTimesForkMenu += 1;
  resetNumericDataChange();
  setDisplayMode(displayForkMenu);
  paintForkMenu();                            // use paintForkMenu, updateDisplay() doesn't work here
}

void handleForkMenuNewTouch() {
  // start tracking the touch duration to be able to enable hold functionality
  sensorCell->lastTouch = millis();
  forkMenuNowScrolling = false;
  if (sensorRow == 0 && sensorCol <= NUM_FORKS) { 
    if (forkMenuColNum > 0 && forkMenuColNum != sensorCol) {
      setLed(forkMenuColNum, 0, Split[LEFT].colorMain, cellOn);   // turn off old button
    }
    forkMenuColNum = sensorCol;
    setLed(sensorCol, 0, Split[LEFT].colorAccent, cellOn);        // turn on new button
  }
}

void handleForkMenuHold() {
  if (sensorRow == 0 && sensorCol <= NUM_FORKS
      && isCellPastSensorHoldWait() && !forkMenuNowScrolling) {          // long-press bottom row
    forkMenuNowScrolling = true;
    paintForkMenu();                                                     // scroll the name of the fork
  }
}

void handleForkMenuRelease() {
  if (sensorRow == 0 && sensorCol <= NUM_FORKS && !isCellPastSensorHoldWait()) {    // short-press bottom row
    forkMenuColNum = 0;
    switch (sensorCol) {
      case 1:
        microLinnConfigNowScrolling = false;
        resetNumericDataChange();
        setDisplayMode(displayMicroLinnConfig);
        updateDisplay();
        break;
      case 2:
        resetNumericDataChange();
        setDisplayMode(displayBrightness);  
        updateDisplay();
        break;
      case 3:
        forkMenuColNum = 3;
        break;
    }
  }
}

void microLinnSetGlobalView() {
  if (isMicroLinnOn()) lightSettings = LIGHTS_ACTIVE;
}

void microLinnHandleGlobalScaleHold() {                       // long-press one of the 9 scale buttons
  if (!isMicroLinnOn()) return;
  if (sensorRow <= 2) {
    //cellTouched(ignoredCell);
    Device.microLinnCurrScale[Device.microLinn.EDO] = Global.activeNotes;  
    microLinnCalcTuning();
    setDisplayMode(displayMicroLinnConfig);
    updateDisplay();
    if (microLinnConfigColNum > 0 && microLinnConfigColNum != 12) {
      setLed(microLinnConfigColNum, 0, Split[LEFT].colorMain, cellOn);        // turn off old button
    }
    microLinnConfigColNum = 12;
    setLed(12, 0, Split[LEFT].colorAccent, cellOn);                           // turn on new button
    PaintMicroLinnNoteLights();
  }
}

void microLinnSetCurrScale() {
  Device.microLinnCurrScale[Device.microLinn.EDO] = Global.activeNotes;
}

void microLinnHandleOctaveTransposeNewTouchSplit(byte side) {
  // handle touches to the 2 new rows on the transpose display
  if (!isMicroLinnOn()) return;
  if (MICROLINN_MAJ2ND[Device.microLinn.EDO] == 1) return;

  if (sensorRow == SPLIT_ROW) {
    if (sensorCol > 0 && sensorCol < 16) {
      Device.microLinn.transposeEDOsteps[side] = sensorCol - 8;
    }
  }
  else if (sensorRow == GLOBAL_SETTINGS_ROW) {
    if (sensorCol > 0 && sensorCol < 16) {
      Device.microLinn.transposeEDOsteps[side] = sensorCol - 8;
    }
  }
}

void enterMicroLinnConfig () {
  microLinnConfigNowScrolling = false;
  resetNumericDataChange();
  setDisplayMode(displayMicroLinnConfig);
  updateDisplay();
}

boolean isMicroLinnConfigButton () {
  return sensorRow == 0 && sensorCol >= 2 && sensorCol <= 15 
      && sensorCol != 4 && sensorCol != 8 && sensorCol != 11 && sensorCol != 13;
}

void handleMicroLinnConfigNewTouch() {
  // start tracking the touch duration to be able to enable hold functionality
  sensorCell->lastTouch = millis();

  microLinnConfigNowScrolling = false;
           
  if (isMicroLinnConfigButton()) {                                             // mostly handled on hold or release
    if (microLinnConfigColNum > 0 && microLinnConfigColNum != sensorCol) {
      setLed(microLinnConfigColNum, 0, Split[LEFT].colorMain, cellOn);         // turn off old button
    }
    microLinnConfigColNum = sensorCol;
    setLed(microLinnConfigColNum, 0, Split[LEFT].colorAccent, cellOn);         // turn on new button
    updateDisplay();
    return;
  }
  
  if (sensorRow > 0) {                                                   // rows 1-7 are handled right away
    switch (microLinnConfigColNum) {
      case 2: 
        handleNumericDataNewTouchCol(Device.microLinn.EDO, 4, MICROLINN_MAX_EDO, true);
        lightSettings = LIGHTS_ACTIVE;
        Global.activeNotes = Device.microLinnCurrScale[Device.microLinn.EDO];
        break;
      case 3: 
        if (!isMicroLinnOn()) break;
        handleNumericDataNewTouchCol(Device.microLinn.octaveStretch, -120, 120, true); 
        break;
      case 5: 
        if (!isMicroLinnOn()) break;
        resetNumericDataChange();
        microLinnCalcTuning();                              // anchor cell chooser needs to know the current tuning
        setDisplayMode(displayMicroLinnAnchorChooser);
        updateDisplay();
        break;
      case 6: 
        if (!isMicroLinnOn()) break;
        handleNumericDataNewTouchCol(Device.microLinn.anchorNote, 0, 127, true); 
        break;
      case 7: 
        if (!isMicroLinnOn()) break;
        handleNumericDataNewTouchCol(Device.microLinn.anchorCents, -100, 100, true); 
        break;
      case 9: 
        microLinnAdjustRowAndColOffsets();
        handleNumericDataNewTouchCol(Device.microLinn.colOffset[LEFT], -MICROLINN_MAX_OFFSET, MICROLINN_MAX_OFFSET, true);
        microLinnStoreColOffsetCents(LEFT);
        break;
      case 10: 
        microLinnAdjustRowAndColOffsets();
        handleNumericDataNewTouchCol(Device.microLinn.colOffset[RIGHT], -MICROLINN_MAX_OFFSET, MICROLINN_MAX_OFFSET, true); 
        microLinnStoreColOffsetCents(RIGHT);
        break;
      case 12: 
        if (!isMicroLinnOn()) break;
        handleMicroLinnNoteLightsNewTouch();
        break;
    }
  }
}

void handleMicroLinnConfigHold() {
  if (isMicroLinnConfigButton() &&                                        // long-press bottom row
      isCellPastSensorHoldWait() && !microLinnConfigNowScrolling) {     
    microLinnConfigNowScrolling = true;
    paintMicroLinnConfig();                                               // scroll the name of the button
  } else if (sensorRow > 0 && microLinnConfigColNum == 12) {
    handleMicroLinnNoteLightsHold();
  }
}

void handleMicroLinnConfigRelease() {
  if (isMicroLinnConfigButton() && !isCellPastSensorHoldWait()) {         // short-press bottom row
    switch (microLinnConfigColNum) {
      case 2:
        microLinnOldEDO = Device.microLinn.EDO;
        break;
      case 12:
        microLinnCalcTuning();                                       // note lights display needs to know the current tuning
        updateDisplay();
        break;
      case 14:
        resetNumericDataChange();
        microLinnSetKiteGuitarDefaults();
        setDisplayMode(displayNormal); 
        updateDisplay();
        break;
      case 15:
        resetNumericDataChange();
        microLinnResetTo12equal();
        setDisplayMode(displayNormal); 
        updateDisplay();
        break;
    }
  } else if (microLinnConfigColNum == 12) {
    handleMicroLinnNoteLightsRelease();
  } else if (sensorRow > 0) {
    handleNumericDataReleaseCol(false);
  }
}

void handleMicroLinnAnchorChooserNewTouch() {
  Device.microLinn.anchorRow = sensorRow;
  Device.microLinn.anchorCol = sensorCol;
  cellTouched(ignoredCell);                      // so that choosing a row 0 note won't trigger a scrolling message
  microLinnUpdateAnchorString ();
  setDisplayMode(displayMicroLinnConfig); 
  updateDisplay(); 
}

void handleMicroLinnNoteLightsNewTouch() {
  byte edo = Device.microLinn.EDO;

  if (sensorCol == 1 && sensorRow > 0) {                              // scale selectors
    Device.microLinnCurrScale[edo] = 7 - sensorRow;
    Global.activeNotes = Device.microLinnCurrScale[edo];
    updateDisplay(); 
    setLed(1, sensorRow, Split[LEFT].colorAccent, cellSlowPulse);
    return;
  }
  if (sensorCol == 3 && sensorRow == 7) {                             // rainbow editor
    Device.microLinnCurrScale[edo] = 7;
    Global.activeNotes = 7;
    updateDisplay(); 
    setLed(3, 7, Split[LEFT].colorAccent, cellSlowPulse);
    return;
  }
  if (sensorCol == 3 && sensorRow == 5) {                             // dots selector
    Device.microLinnCurrScale[edo] = 8;
    Global.activeNotes = 8;
    updateDisplay(); 
    setLed(3, 5, Split[LEFT].colorAccent, cellSlowPulse);
    return;
  }
  if (sensorCol > 3 && sensorRow > 0 &&  Device.microLinnCurrScale[edo] == 8) {    // enter dots editor
    setDisplayMode(displayMicroLinnDotsEditor);
    updateDisplay();
    return;
  }
  
  byte stepspan = 7 - sensorRow;                                       // the degree (2nd, 3rd, etc.) minus 1
  short edostep = MICROLINN_SCALEROWS[edo][stepspan] - MICROLINN_SCALEROWS[edo][0] + sensorCol - 12;
  if (edostep <= MICROLINN_SCALEROWS[edo][stepspan] &&                 // did we touch a note?
     (edostep >  MICROLINN_SCALEROWS[edo][stepspan-1] ||
     (stepspan == 0 && edostep > MICROLINN_SCALEROWS[edo][6] - edo))) {
    edostep = microLinnMod (edostep, edo);
    if (Device.microLinnCurrScale[edo] == 7) {                                // rainbow editor
      switch (Device.microLinnRainbows[edo][edostep]) {                       // cycle through the colors
        case 8:  Device.microLinnRainbows[edo][edostep] = 1;  break;          // white to red
        case 1:  Device.microLinnRainbows[edo][edostep] = 9;  break;          // red to orange
        case 9:  Device.microLinnRainbows[edo][edostep] = 2;  break;          // orange
        case 2:  Device.microLinnRainbows[edo][edostep] = 10; break;          // yellow (not used)
        case 10: Device.microLinnRainbows[edo][edostep] = 3;  break;          // lime (used as yellow)
        case 3:  Device.microLinnRainbows[edo][edostep] = 4;  break;          // green
        case 4:  Device.microLinnRainbows[edo][edostep] = 5;  break;          // cyan
        case 5:  Device.microLinnRainbows[edo][edostep] = 6;  break;          // blue
        case 6:  Device.microLinnRainbows[edo][edostep] = 11; break;          // magenta
        case 11: Device.microLinnRainbows[edo][edostep] = 8;  break;          // pink
      }
    } else if (Device.microLinnCurrScale[edo] < 7) {
      Device.microLinnScales[edo][edostep] ^= (1 << Device.microLinnCurrScale[edo]);     // xor to toggle the bit
    }
    updateDisplay(); 
  }
}

void microLinnResetScaleNote (byte edo, byte edostep, byte currScale) {
  bitWrite (Device.microLinnScales[edo][edostep], 
            currScale, 
            bitRead(MICROLINN_SCALES[edo][edostep],currScale));
}

void handleMicroLinnNoteLightsHold() {

  if (isCellPastConfirmHoldWait()) {                                           // long-press 800 ms
    byte edo = Device.microLinn.EDO;
    byte currScale = Device.microLinnCurrScale[edo];

    if (currScale <= 6 && sensorCol == 1 && sensorRow > 0) {                   // scale selector button
      if (cell(3, 3).touched == untouchedCell) {                               // mass-reset button
        for (byte edostep = 0; edostep < edo; ++edostep) {                     // reset the scale
          microLinnResetScaleNote(edo, edostep, currScale);
        }
      } else {
        for (byte edo = 5; edo <= MICROLINN_MAX_EDO; ++edo) {                  // reset this scale in all the edos
          for (byte edostep = 0; edostep < edo; ++edostep) { 
            microLinnResetScaleNote(edo, edostep, currScale);
          }
        }
      }
      updateDisplay();
      return;
    }

    if (currScale == 7 && sensorCol == 3 && sensorRow == 7) {                                      // color editor button
      if (cell(3, 3).touched == untouchedCell) {                                                   // mass-reset button
        memcpy (&Device.microLinnRainbows[edo][0], &MICROLINN_RAINBOWS[edo][0], edo);              // reset the rainbow
      } else {
        memcpy (Device.microLinnRainbows, MICROLINN_RAINBOWS, sizeof(Device.microLinnRainbows));   // reset all the rainbows
      }
      updateDisplay();
      return;
    }

    if (currScale == 8 && sensorCol == 3 && sensorRow == 5) {                        // dots selector button
      if (cell(3, 3).touched == untouchedCell) {                                     //  mass-reset button
        memcpy (&Device.microLinnDots[edo][0], &MICROLINN_DOTS[edo][0], MAXCOLS);    // reset the dots
      } else {
        memcpy (Device.microLinnDots, MICROLINN_DOTS, sizeof(Device.microLinnDots)); // reset all the dots
      }
      updateDisplay();
    }
  }
}

void handleMicroLinnNoteLightsRelease() {
  byte currScale = Device.microLinnCurrScale[Device.microLinn.EDO];
  if (!isCellPastConfirmHoldWait()) {
    if ((sensorCol == 1 && sensorRow > 0 && currScale <= 6) ||                  // short-press scale selector
        (sensorCol == 3 && sensorRow == 7 && currScale == 7) ||                 // short-press rainbow editor
        (sensorCol == 3 && sensorRow == 5 && currScale == 8)) {                 // short-press dots selector
      setLed(sensorCol, sensorRow, Split[LEFT].colorAccent, cellOn);            // stop pulsing
      if (cell(3, 3).touched == touchedCell) {                                  // mass-select button
        memset (Device.microLinnCurrScale, currScale, sizeof(Device.microLinnCurrScale));
      }
    }
  }
}

void handleMicroLinnDotsEditorNewTouch() {
  Device.microLinnDots[Device.microLinn.EDO][sensorCol] ^= (1 << sensorRow);    // xor to toggle the bit
  updateDisplay();
}

void handleBrightnessNewTouch() {
  if (sensorRow >= 5 && sensorCol <= 16) {
    brightness = min (max (sensorCol - 2, 1), 12);
    updateDisplay(); 
  }
}



/************** ls_switches.ino ************************/

void microLinnChangeEDO(int delta) {                                   // called via switch1, switch2 or footswitch press
  if (!isMicroLinnOn()) return;
  microLinnOldEDO = Device.microLinn.EDO;
  Device.microLinn.EDO += delta;
  if (Device.microLinn.EDO < 5) {Device.microLinn.EDO = MICROLINN_MAX_EDO;}        // wrap around
  if (Device.microLinn.EDO > MICROLINN_MAX_EDO) {Device.microLinn.EDO = 5;}
  Global.activeNotes = Device.microLinnCurrScale[Device.microLinn.EDO];
  microLinnCalcTuning();
  updateDisplay();
}

void microLinnChangeScale(int delta) {                                // called via switch1, switch2 or footswitch press, works with 12edo too
  signed char newScale = Global.activeNotes += delta;                 // use a signed char because we can't set a byte to -1
  if (newScale > 8) newScale = 0;                                     // wrap around
  if (newScale < 0) newScale = 8;
  Device.microLinnCurrScale[Device.microLinn.EDO] = Global.activeNotes = newScale;
  updateDisplay();
}



/********************* OBSOLETE CODE  ****************


byte microLinnKiteGuitarDots[MAXCOLS][MAXROWS];

void microLinnPaintDots41() {         // unlike microLinnRainbows, this ignores the anchor cell
  byte row = 4;                       // start with the leftmost dot, a single dot
  byte col = 1;
  short edosteps = MICROLINN_MAJ2ND[microLinn.EDO] * Split[Global.currentPerSplit].transposeLights
                 + microLinn.transpose[Global.currentPerSplit].EDOlights;
  if (edosteps % 2 != 0) {
    row = 3;
    edosteps += microLinnSumOfRowOffsets (3, 4);              // offset is always odd so edosteps is now even
  }
  col = microLinnMod (col + edosteps / 2, 12);                // 2 edosteps per column, kites repeat every 12 columns

  memset(microLinnKiteGuitarDots, 0, sizeof(microLinnKiteGuitarDots));

  while (col < NUMCOLS) {                                     // paint all single dots green
    microLinnKiteGuitarDots[col][row] = Split[LEFT].colorMain; 
    col += 12;
  }

  boolean isFullyLefty = Device.otherHanded && Device.splitHandedness == reversedBoth;

  col += isFullyLefty ? -4 : 4;                       // paint all double dots
  col = microLinnMod (col, 12); 
  while (col < NUMCOLS) {
    microLinnKiteGuitarDots[col][row + 1] = Split[LEFT].colorMain; 
    microLinnKiteGuitarDots[col][row - 1] = Split[LEFT].colorMain; 
    col += 12;
  }

  col += isFullyLefty ? -4 : 4;                       // paint all triple dots
  col = microLinnMod (col, 12); 
  while (col < NUMCOLS) {
    microLinnKiteGuitarDots[col][row] = Split[LEFT].colorMain; 
    microLinnKiteGuitarDots[col][row + 2] = Split[LEFT].colorMain; 
    microLinnKiteGuitarDots[col][row - 2] = Split[LEFT].colorMain; 
    col += 12;
  }
}


// 2 super long rows of the rainbow pattern, starts at the tonic, 65 covers a row of 25 starting at 40
const byte MICROLINN_RAINBOWS41[2][65] = {
                  65, 41, 25, 81,  9,  0,  0,  0,  0,  0,            // righty version 
  33, 49, 65, 41, 25, 81,  9, 65,  0,  0,  0,  0,  0,  0,
  65, 41, 25, 81,  9, 65, 49, 73,  0,  0,  0,  0,  0, 
  41, 25, 81,  9, 65, 41, 25, 81,  9,  0,  0,  0,  0,  0, 
  33, 49, 65, 41, 25, 81,  9, 65,  0,  0,  0,  0,  0,  0,
                  65,  9, 81, 25, 41,  0,  0,  0,  0,  0,            // lefty version, goes backwards
  73, 49, 65,  9, 81, 25, 41, 65,  0,  0,  0,  0,  0,  0,
  65,  9, 81, 25, 41, 65, 49, 33,  0,  0,  0,  0,  0, 
   9, 81, 25, 41, 65,  9, 81, 25, 41,  0,  0,  0,  0,  0, 
  73, 49, 65,  9, 81, 25, 41, 65,  0,  0,  0,  0,  0,  0
};

void microLinnPaintRainbows41() {
  byte startCol[NUMSPLITS] = {1, 1};                                // where each split starts
  byte splitWidth[NUMSPLITS] = {NUMCOLS - 1, NUMCOLS - 1};          // how many columns each split spans
  short rainbowStart;
  if (Global.splitActive) {
    splitWidth[LEFT] = Global.splitPoint - 1;
    startCol[RIGHT] = Global.splitPoint;
    splitWidth[RIGHT] = NUMCOLS - Global.splitPoint;
  } else if (Global.currentPerSplit == LEFT) {
    splitWidth[RIGHT] = 0;
  } else {
    splitWidth[LEFT] = 0;
  }
  for (byte side = 0; side < NUMSPLITS; ++side) {
    for (byte row = 0; row < NUMROWS; ++row) {
      rainbowStart = microLinnEdostep[side][startCol[side]][row];        // rainbowStart is a pointer into RAINBOWS41
      if (isLeftHandedSplit(side)) {
        rainbowStart *= -1;
      }
      if (rainbowStart % 2 != 0) {
        rainbowStart += 41;                                                      // force it to be even
      }
      rainbowStart = microLinnMod(rainbowStart / 2, 41);                         // convert from edosteps to columns
      memcpy(&Device.customLeds[1][row * MAXCOLS + startCol[side]],              // [1] means 1st custom light pattern
             &MICROLINN_RAINBOWS41[isLeftHandedSplit(side)][rainbowStart], splitWidth[side]);
    }
  }
}




// not called, leave the 3 light patterns alone and just use microLinnPaintNormalDisplayCell()
void microLinnPaintFullRainbow() {                   // fill 2nd custom light pattern using anchor cell, transpose, etc.
  for (byte side = 0; side < NUMSPLITS; ++side) {
    byte lowCol, highCol;
    getSplitBoundaries(side, lowCol, highCol);
    for (byte col = lowCol; col <= highCol; ++col) {
      for (byte row = 0; row < NUMROWS; ++row) {
        byte edostep = microLinnEdostep[side][col][row];
        Device.customLeds[1][row * MAXCOLS + col] = microLinnRainbows[microLinn.EDO][edostep];
      }
    }
  }
}



    /**** OLD WAY to initialize major and minor scales **************
    short comma = 2 * M2 - round (i * yo3rd);           // gu comma, to find the yo and gu scales

    microLinnScales[i][0] |= 4;                         // set scale #2 to yo scale
    microLinnScales[i][M2] |= 4;                        // w2
    microLinnScales[i][2*M2 - comma] |= 4;              // y3
    microLinnScales[i][2*M2 + m2] |= 4;                 // w4
    microLinnScales[i][3*M2 + m2] |= 4;                 // w5
    microLinnScales[i][4*M2 + m2 - comma] |= 4;         // y6
    microLinnScales[i][i - m2 - comma] |= 4;            // y7

    microLinnScales[i][0] |= 8;                         // set scale #3 to gu scale
    microLinnScales[i][M2] |= 8;                        // w2
    microLinnScales[i][M2 + m2 + comma] |= 8;           // g3
    microLinnScales[i][2*M2 + m2] |= 8;                 // w4
    microLinnScales[i][3*M2 + m2] |= 8;                 // w5
    microLinnScales[i][3*M2 + 2*m2 + comma] |= 8;       // g6
    microLinnScales[i][i - M2 + comma] |= 8;            // g7


const byte CUSTOM_LEDS_PATTERN_RAINBOWS [LED_LAYER_SIZE] = {        // two rainbow zones for Kite guitar
   0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,  0,  0,  0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,  0,  0,
   0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,  0,  0,  0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,  0,
   0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,  0,  0,  0,  0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,  0,
   0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,  0,  0,  0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,  0,
   0,  0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,  0,  0,  0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,
   0,  0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,  0,  0,  0,  0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,
   0,  0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,  0,  0,  0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,
   0,  0,  0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,  0,  0,  0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9
};

const byte CUSTOM_LEDS_PATTERN_RAINBOWS_LEFTY [LED_LAYER_SIZE] = {
  0,  0,  0, 49, 65,  9, 17, 25, 41, 65, 49, 33,  0,  0,  0,  0,  0,  9, 17, 25, 41,  0,  9, 17, 25, 41,
  0,  0,  0,  9, 17, 25, 41,  0,  9, 17, 25, 41,  0,  0,  0,  0,  0, 33, 49, 65,  9, 17, 25, 41, 65, 49,
  0,  0,  0, 33, 49, 65,  9, 17, 25, 41, 65, 49,  0,  0,  0,  0, 49, 65,  9, 17, 25, 41, 65, 49, 33,  0,
  0,  0, 49, 65,  9, 17, 25, 41, 65, 49, 33,  0,  0,  0,  0,  0,  9, 17, 25, 41,  0,  9, 17, 25, 41,  0,
  0,  0,  9, 17, 25, 41,  0,  9, 17, 25, 41,  0,  0,  0,  0,  0, 33, 49, 65,  9, 17, 25, 41, 65, 49,  0,
  0,  0, 33, 49, 65,  9, 17, 25, 41, 65, 49,  0,  0,  0,  0, 49, 65,  9, 17, 25, 41, 65, 49, 33,  0,  0,
  0, 49, 65,  9, 17, 25, 41, 65, 49, 33,  0,  0,  0,  0,  0,  9, 17, 25, 41,  0,  9, 17, 25, 41,  0,  0,
  0,  9, 17, 25, 41,  0,  9, 17, 25, 41,  0,  0,  0,  0,  0, 33, 49, 65,  9, 17, 25, 41, 65, 49,  0,  0
};

    if (isFullLefty) {
      memcpy(&Device.customLeds[2][0], &CUSTOM_LEDS_PATTERN_RAINBOWS_LEFTY[0], LED_LAYER_SIZE);
    } else {
      memcpy(&Device.customLeds[2][0], &CUSTOM_LEDS_PATTERN_RAINBOWS[0], LED_LAYER_SIZE);
    }


const byte CUSTOM_LEDS_PATTERN_DOTS [LED_LAYER_SIZE] = {              // two green kites for Kite guitar
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,
   0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,
   0, 25,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0, 25,
   0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

const byte CUSTOM_LEDS_PATTERN_DOTS_LEFTY [LED_LAYER_SIZE] = {  
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,
   0, 25,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0, 25,
   0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,
   0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

    if (isFullyLefty) {
      memcpy(&Device.customLeds[2][0], &CUSTOM_LEDS_PATTERN_DOTS_LEFTY[0], LED_LAYER_SIZE);
    } else {
      memcpy(&Device.customLeds[2][0], &CUSTOM_LEDS_PATTERN_DOTS[0], LED_LAYER_SIZE);
    }





// extend audience message #8 by 2 chars, to store the user's choice of skip fretting or not for each split as 2 pseudo-booleans
const char ASCII_FALSE = ' ';                                                      // ascii 32, the lowest ascii char allowed in audienceMessages
const char ASCII_TRUE  = '!';                                                      // ascii 33, the 2nd lowest, plus it looks good!
const byte skipFrettingMsg = 7;                                                    // "HELLO NEW YORK" becomes "HELLO NEW YORK!!"
char * skipFretting = (char *)Device.audienceMessages + 31 * skipFrettingMsg;      // the skipFretting[2] array overlaps the messages array

void checkSkipFrettingAudienceMessage () {                                         // called before reading or writing either pseudo-boolean
  byte len = strlen (Device.audienceMessages[skipFrettingMsg]);
  skipFretting = (char *)Device.audienceMessages + 31 * skipFrettingMsg + len - 2; // find the 2nd to last char of message #8
  if (!(skipFretting[0] == ASCII_TRUE || skipFretting[0] == ASCII_FALSE)           // if either trailing char is not valid,
   || !(skipFretting[1] == ASCII_TRUE || skipFretting[1] == ASCII_FALSE)) {        // (1st run of this fork, or the user edited the message)
    skipFretting += min (2, 30 - len);                                             // extend the message (if no room, overwrite the last 2 chars)
    skipFretting[LEFT] = skipFretting[RIGHT] = ASCII_FALSE;                        // if there were invalid chars, best to initialize to false
    skipFretting[RIGHT + 1] = '\0';                                                // this line shouldn't be needed, but do it anyway just in case
  }
}

boolean isSkipFrettingOLD (byte side) {                          
  checkSkipFrettingAudienceMessage ();
  return skipFretting[side] == ASCII_TRUE;                       // an invalid char (not a space or exclamation point) is assumed to be = FALSE
}

struct SkipFrettingData {                           // used to keep track of transposing, which is done via CCs to the LinnstrumentMicrotonal app
  signed char transposeOctave;
  signed char transposeTone;
  signed char transposeArrow;
};
SkipFrettingData skipFrettingData[NUMSPLITS];





void paintOctaveTransposeDisplaySkipFretting(byte side) {     // alternate version of paintOctaveTransposeDisplay
  clearDisplay();                                             // see handleOctaveTransposeNewTouchSplit in ls_settings.ino
  blinkMiddleRootNote = true;

  // Paint the octave shift value
  if (!doublePerSplit || skipFrettingData[LEFT].transposeOctave == skipFrettingData[RIGHT].transposeOctave) {
    paintOctave(Split[Global.currentPerSplit].colorMain, 8, OCTAVE_ROW, 12 * skipFrettingData[side].transposeOctave);
  }
  else if (doublePerSplit) {
    if (abs(skipFrettingData[LEFT].transposeOctave) > abs(skipFrettingData[RIGHT].transposeOctave)) {
      paintOctave(Split[LEFT].colorMain,  8, OCTAVE_ROW, 12 * skipFrettingData[LEFT].transposeOctave);
      paintOctave(Split[RIGHT].colorMain, 8, OCTAVE_ROW, 12 * skipFrettingData[RIGHT].transposeOctave);
    }
    else {
      paintOctave(Split[RIGHT].colorMain, 8, OCTAVE_ROW, 12 * skipFrettingData[RIGHT].transposeOctave);
      paintOctave(Split[LEFT].colorMain,  8, OCTAVE_ROW, 12 * skipFrettingData[LEFT].transposeOctave);
    }
  }

  // Paint the whole tone transpose values
  if (!doublePerSplit || skipFrettingData[LEFT].transposeTone == skipFrettingData[RIGHT].transposeTone) {
    paintTranspose(Split[Global.currentPerSplit].colorMain, SWITCH_1_ROW, skipFrettingData[side].transposeTone);
  }
  else if (doublePerSplit) {
    if (abs(skipFrettingData[LEFT].transposeTone) > abs(skipFrettingData[RIGHT].transposeTone)) {
      paintTranspose(Split[LEFT].colorMain,  SWITCH_1_ROW, skipFrettingData[LEFT].transposeTone);
      paintTranspose(Split[RIGHT].colorMain, SWITCH_1_ROW, skipFrettingData[RIGHT].transposeTone);
    }
    else {
      paintTranspose(Split[RIGHT].colorMain, SWITCH_1_ROW, skipFrettingData[RIGHT].transposeTone);
      paintTranspose(Split[LEFT].colorMain,  SWITCH_1_ROW, skipFrettingData[LEFT].transposeTone);
    }
  }

  // Paint the arrow transpose values
  if (!doublePerSplit || skipFrettingData[LEFT].transposeArrow == skipFrettingData[RIGHT].transposeArrow) {
    paintTranspose(Split[Global.currentPerSplit].colorMain, SWITCH_2_ROW, skipFrettingData[side].transposeArrow);
  }
  else if (doublePerSplit) {
    if (abs(skipFrettingData[LEFT].transposeArrow) > abs(skipFrettingData[RIGHT].transposeArrow)) {
      paintTranspose(Split[LEFT].colorMain,  SWITCH_2_ROW, skipFrettingData[LEFT].transposeArrow);
      paintTranspose(Split[RIGHT].colorMain, SWITCH_2_ROW, skipFrettingData[RIGHT].transposeArrow);
    }
    else {
      paintTranspose(Split[RIGHT].colorMain, SWITCH_2_ROW, skipFrettingData[RIGHT].transposeArrow);
      paintTranspose(Split[LEFT].colorMain,  SWITCH_2_ROW, skipFrettingData[LEFT].transposeArrow);
    }
  }

  paintShowSplitSelection(side);
}

from ls_displayModes.ino
void paintOctaveTransposeDisplay(byte side) {

  if (isSkipFretting(side) && Global.rowOffset > 7) {       // rowOffset > 7 to exclude 12edo Wicki-Hayden users
    paintOctaveTransposeDisplaySkipFretting (side);         // microLinn
    return;
  }

/*************************************************************************************



void handleOctaveTransposeNewTouchSplitSkipFretting(byte side) {
  // alternate version of handleOctaveTransposeNewTouchSplit
  // send CCs reporting the transposes to LinnstrumentMicrotonal app, it will do the transposing
  // use the CC that the right foot switch is assigned to via long-pressing the CC65 option
  // repurpose semitones to be whole tones and lights to be arrows/edosteps, so that ±7 of each covers 41edo
  // midi for octave transposing via footswitch reports each increment/decrement, plus a 0 CC for pedal release
  // but midi from here directly reports the current amount of transpose, no zero CCs
  // the CCvalue is 93-99 for ±3 octaves, 57-71 for ±7 tones, or 25-39 for ±7 arrows
  // see also paintOctaveTransposeDisplay function in ls_displayModes.ino

  signed char newTransposeOctave = skipFrettingData[side].transposeOctave; 
  signed char newTransposeTone   = skipFrettingData[side].transposeTone;
  signed char newTransposeArrow  = skipFrettingData[side].transposeArrow;

  if (sensorCol > 0 && sensorCol < 16) {
         if (sensorRow == OCTAVE_ROW)   {newTransposeOctave = sensorCol - 8;}
    else if (sensorRow == SWITCH_1_ROW) {newTransposeTone   = sensorCol - 8;}
    else if (sensorRow == SWITCH_2_ROW) {newTransposeArrow  = sensorCol - 8;}
  }
  newTransposeOctave = min (max (newTransposeOctave, -3), 3);

  byte chan = (side == LEFT ? 1 : 16);                                        // midi channel
  byte CCnum = Global.ccForSwitchCC65[SWITCH_FOOT_R];
    
  if (newTransposeOctave != skipFrettingData[side].transposeOctave) {
    skipFrettingData[side].transposeOctave = newTransposeOctave;                           
    midiSendControlChange (CCnum, 96 + newTransposeOctave, chan, true);       // range is 93-99                   
  }

  if (newTransposeTone != skipFrettingData[side].transposeTone) { 
    skipFrettingData[side].transposeTone = newTransposeTone;                           
    midiSendControlChange (CCnum, 64 + newTransposeTone, chan, true);         // range is 57-71                   
  }

  if (newTransposeArrow != skipFrettingData[side].transposeArrow) { 
    skipFrettingData[side].transposeArrow = newTransposeArrow;                           
    midiSendControlChange (CCnum, 32 + newTransposeArrow, chan, true);        // range is 25-39             
  }
}

from ls_settings.ino
void handleOctaveTransposeNewTouchSplit(byte side) {

  if (isSkipFretting(side) && Global.rowOffset > 7) {               // rowOffset > 7 to exclude 12edo Wicki-Hayden users,
    handleOctaveTransposeNewTouchSplitSkipFretting (side);          // who will want to transpose normally
    return;
  }
**********************************************************************************************/



/**********************************************************************************************
void setWickiHaydenDefaults () {
  Global.rowOffset = 5;                               // tune in 4ths
  Split[LEFT].bendRangeOption = bendRange24;          // don't send RPNs
  Split[RIGHT].bendRangeOption = bendRange24;
  Split[LEFT].playedTouchMode = playedSame;           // turn on same-note lighting for familiarity
  Split[RIGHT].playedTouchMode = playedSame;
  microLinn.EDO = 12;
  microLinn.octaveStretch = 0;   
  microLinn.colOffset[LEFT] = 2;
  microLinn.colOffset[RIGHT] = 2;
  microLinnCalcTuning();
}
**********************************************************************************************/



/**********************************************************************************************

const byte MICROLINN_MSG = 0;          // "LINNSTRUMENT" will be truncated to make room for the user's settings
const byte MICROLINN_MSG_LEN = 21;     // 31 chars including the null, minus sizeOf(MicroLinn)

struct __attribute__ ((packed)) MicroLinnColRow {     // packed byte like FocusCell, ":5" means 5 bits long
  byte col:5;
  byte row:3;
};

struct __attribute__ ((packed)) MicroLinn2Nybbles {   // packed byte
  signed char EDOsteps:4;                             // ":4" means 4 bits long, actual amount ranges from -7 to 7
  signed char EDOlights:4;
};

struct MicroLinn {                                    // overlaps the audience messages array
  char nullTerminator;                                // essential, truncates the audience message
  byte EDO;                                           // limited to 5-55, plus 4 for OFF
  signed char octaveStretch;                          // limited to ± 100 cents, for non-octave tunings such as bohlen-pierce
  struct MicroLinnColRow anchorCell;
  byte anchorNote;                                    // any midi note 0-127
  signed char anchorCents;                            // limited to ± 100 cents
  signed char colOffset[NUMSPLITS];                   // 2 column offsets, -34 to 33
  struct MicroLinn2Nybbles transpose[NUMSPLITS];      // 2 packed bytes, accessed not via displayMicroLinnConfig but via displayOctaveTranspose
};  

MicroLinn* microLinn = (MicroLinn*)(Device.audienceMessages + 31 * MICROLINN_MSG + MICROLINN_MSG_LEN);


// Upon powering up, this code has to decide if the audience message is text the user entered pre-forking or valid post-fork user settings
// Each fork's data struct should have one byte that will never equal zero, to make a fool-proof test whether the struct needs initializing
// For microLinn, one such byte is the EDO. The user is not allowed to set it to zero, for obvious reasons
// In the official un-forked code, the unused part of the audience message char array is always padded with trailing nulls
// So it's impossible to have a null followed by a non-null
// So if the nullTerminator is zero and the EDO is non-zero, we know the string has already been truncated and initialized
// And if not, then we know we need to initialize the string to default values
// (could possibly instead put the init function in initializeDeviceSettings in ls_settings.ino)
void initializeMicroLinn() {                  // called in setup(), runs every time the Linnstrument powers up
  if (microLinn.nullTerminator != '\0'       // if user had lengthened the audience message and we haven't truncated it yet,
   || microLinn.EDO == 0) {                  // or if user has never set the EDO, then this fork must be running for the very first time
    microLinn.nullTerminator = '\0';
    microLinn.EDO = 4;                      
    microLinn.octaveStretch = 0; 
    microLinn.anchorRow = 4;                 // 4th row from the top
    microLinn.anchorCol = 11;
    microLinn.anchorNote = 60;               // middle-C
    microLinn.anchorCents = 0;  
    microLinn.colOffset[LEFT] = 1;
    microLinn.colOffset[RIGHT] = 1;
    microLinn.transpose[LEFT].EDOsteps = 0;
    microLinn.transpose[RIGHT].EDOsteps = 0;
    microLinn.transpose[LEFT].EDOlights = 0;
    microLinn.transpose[RIGHT].EDOlights = 0;
  }
    memcpy (microLinnDots, MICROLINN_DOTS, sizeof(microLinnDots));
    memcpy (microLinnRainbows, MICROLINN_RAINBOWS, sizeof(microLinnRainbows));
    memcpy (Device.microLinnScales, MICROLINN_SCALES, sizeof(Device.microLinnScales));
    memset (microLinnCurrScale, 0, sizeof(microLinnCurrScale));
    Global.activeNotes = 0;
    // move the above 5 lines up into the if statement once data storage is figured out
    Global.setSwitchAssignment(3, ASSIGNED_MICROLINN_EDO_UP,   false);  // for debugging
    Global.setSwitchAssignment(2, ASSIGNED_MICROLINN_EDO_DOWN, false);  // for debugging
  microLinnSetGlobalView();
  microLinnInitializeScales();             // delete this line once those arrays are getting saved
  microLinnStoreRowOffsetCents();
  microLinnStoreColOffsetCents(LEFT);
  microLinnStoreColOffsetCents(RIGHT);
  microLinnOldEDO = microLinn.EDO;
  microLinnCalcTuning ();
  updateDisplay();
  microLinnUpdateAnchorString ();
}


byte forkMenuProtectForkData(byte audienceMessageToEdit) {      // keep the user from editing fork data stored at the end of the message
  switch (audienceMessageToEdit) {
    case MICROLINN_MSG: 
      return MICROLINN_MSG_LEN;
    default: 
      return 30;
  }
}

 // fill in all 30 spaces of the message
      int strl = strlen(Device.audienceMessages[audienceMessageToEdit]);
      byte maxLen = forkMenuProtectForkData (audienceMessageToEdit);      // see ls_forkMenu.ino
      if (strl < maxLen) {
        for (byte ch = strl; ch < maxLen; ++ch) {
          Device.audienceMessages[audienceMessageToEdit][ch] = ' ';       // extend to full length with trailing spaces
        }
      }
      Device.audienceMessages[audienceMessageToEdit][maxLen] = '\0';      // null-terminated

**********************************************************************************************/