/**************************************** SKIP FRETTING and MICROLINN ****************************************

1) Download the latest installer (2.3.3 as of Feb '24) from https://www.rogerlinndesign.com/support/support-linnstrument-update-software. 
2) Download the latest version of linnstrument-firmware-microLinn.bin from __________________.
3) If on a mac, put both the updater and the .bin file on your *desktop*. If on a PC, _______________.
4) Run the updater. Don't run anything else while it's running. If it asks for permission to read files from the desktop, say yes.
5) Confirm the update by short-pressing the OS version (global settings, column 16). It should be 234.08K. If not, try using the 2.3.0 updater instead. 

Once installed, long-press that same OS version pad (or short-press the pad immediately to the right of it, if you have a 200).
You should see 3 green buttons in the lower left. Long-press each one to see its function.
Short-press the first green button to see microLinn's 10 green buttons. Long-press each of these 10 to see its function.

On the global settings screen, long-press col 1 bottom row (VIEW MAIN) to go directly to the main microLinn display.
Once the notes per octave is set to anything other than OFF, VIEW MAIN turns light blue and you can short-press it.

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
MicroLinn's note lights display has 7 scale buttons plus the color editor and the dots selector, plus the blue mass-selector button.
Tap a note in a scale to toggle it on or off. Tap a note in the color editor to cycle it thru the rainbow. 
Tapping the dots selector makes the dots appear mid-screen. Tapping there puts you in a full-screen editor that lets you toggle dots on or off. 

Long-press the scale buttons or color editor button or the dots selector button to reset the scale or colors or dots pattern. 
Hold the blue  mass-selector button in column 3 while selecting a scale and your selection will be applied to all 52 edos at once. 
Hold it while long-pressing another button to mass-reset that scale/rainbow/dot-pattern for all 52 edos.

The 3 custom light patterns are totally separate from all this and are still available for use!
This web browser lets you easily edit them: https://forrcaho.github.io/linnstrument_colorizer/

When microLinn is on, the global setting of lefthandedness is ignored. Lefthandedness results from negative column offsets

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

(new played modes)

Suggestions for exploring:
The first few edos are pretty strange. Try starting with 15, 16, 17 or 19.
The rainbow colors can be overwhelming. Try setting the played mode to BLNK or BLNK8.





Possible non-microtonal features:
The column offset can be set for either split, range is -33 to 33
brightness knob (not done)
chaining of sequencer patterns (not done, looks easy)
make channel pressure less jumpy for non-MPE synths (use another's fork, so pretty easy)
hammer-on/pull-off window (1-5 columns, 0 columns turns it off) (not even started)
in SAME mode, twin notes in the other split show up as well, if SAME is also on there
3 new played modes, SAM8 (includes octaves) BLNK (slow blink) and BLN8 (blink plus octaves)



// to find all changes to the code, search for "microlinn" or "playedBlink" or "chainSeq"



// to create JI or rank-2 scales with N notes, set the edo to 12 but play as if in N-edo, think one midi note per edostep
// load a scala file into your synth or run alt-tuner to produce that N-note scale
// each note is slightly sharper or flatter from N-edo, thus the pad's note will be different slid up to vs played directly
// however this is only a comma or so difference even on long slides, might be tolerable
// plus software on the PC could possibly fix this problem by scaling the slides by adjusting the pitch bends


// note to self:  "if (sensorCell->velocity)" means if another touch is already down on the same row
// according to the comment by handleFaderRelease in ls_faders.ino

// note to self: in ls_settings.ino, "Device.version = 16;"

// Geert's coding suggestions for forks: https://www.kvraudio.com/forum/viewtopic.php?t=433791 
// Geert's 2014 video: https://www.youtube.com/watch?v=iENVztlxWuk
// Geert's 2017 video: https://www.synthtopia.com/content/2017/06/28/from-arduino-to-linnstrument/


// a few ideas I had, probably not needed
//short microLinnTuningBend[NUMSPLITS][16][10];                // 16 midi channels, 10 touches, tuning bends come from microLinnFineTuning
//short microLinnSlideBend[NUMSPLITS][16][10];                 // 16 midi channels, 10 touches, slide bends come from sliding along the Linnstrument
//short microLinnLandingBend[NUMSPLITS][16][10];               // 16 midi channels, 10 touches, landing bends come from the initial touch being off-center

*********************************************************/

void microLinnChangeEDO(int delta) {                                   // called via switch1, switch2 or footswitch press
  if (!isMicroLinnOn()) return;
  microLinnOldEDO = microLinn->EDO;
  microLinn->EDO += delta;
  if (microLinn->EDO < 5) {microLinn->EDO = MICROLINN_MAX_EDO;}        // wrap around
  if (microLinn->EDO > MICROLINN_MAX_EDO) {microLinn->EDO = 5;}
  Global.activeNotes = microLinnCurrScale[microLinn->EDO];
  microLinnCalcTuning();
  updateDisplay();
}

void microLinnChangeScale(int delta) {                                // called via switch1, switch2 or footswitch press
  signed char newScale = Global.activeNotes += delta;                 // use a signed char because we can't set a byte to -1
  if (newScale > 8) {newScale = 0;}                                   // wrap around
  if (newScale < 0) {newScale = 8;}
  microLinnCurrScale[microLinn->EDO] = Global.activeNotes = newScale;
  updateDisplay();
}

/********************* OBSOLETE CODE  ****************


byte microLinnKiteGuitarDots[MAXCOLS][MAXROWS];

void microLinnPaintDots41() {         // unlike microLinnRainbows, this ignores the anchor cell
  byte row = 4;                       // start with the leftmost dot, a single dot
  byte col = 1;
  short edosteps = MICROLINN_MAJ2ND[microLinn->EDO] * Split[Global.currentPerSplit].transposeLights
                 + microLinn->transpose[Global.currentPerSplit].EDOlights;
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
        Device.customLeds[1][row * MAXCOLS + col] = microLinnRainbows[microLinn->EDO][edostep];
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
  microLinn->EDO = 12;
  microLinn->octaveStretch = 0;   
  microLinn->colOffset[LEFT] = 2;
  microLinn->colOffset[RIGHT] = 2;
  microLinnCalcTuning();
}
**********************************************************************************************/