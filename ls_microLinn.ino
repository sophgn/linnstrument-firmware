/**************************************** SKIP FRETTING and MICROLINN ****************************************/

/********************* OLD WAY  ****************
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
*/

/************************************ NEW WAY ******************************************

const byte CUSTOM_LEDS_PATTERN2_K[LED_LAYER_SIZE] = {        // two rainbow zones for 41edo skipFretting
   0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,  0,  0,  0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,  0,  0,
   0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,  0,  0,  0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,  0,
   0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,  0,  0,  0,  0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,  0,
   0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,  0,  0,  0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,  0,
   0,  0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,  0,  0,  0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,
   0,  0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,  0,  0,  0,  0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,
   0,  0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9,  0,  0,  0,  0,  0, 33, 49, 65, 41, 25, 17,  9, 65, 49,
   0,  0,  0, 49, 65, 41, 25, 17,  9, 65, 49, 33,  0,  0,  0,  0,  0, 41, 25, 17,  9,  0, 41, 25, 17,  9
};

const byte CUSTOM_LEDS_PATTERN3[LED_LAYER_SIZE] = {            // two green kites for 41edo Kite guitar
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,
   0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,
   0, 25,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0, 25,
   0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

const byte MAX_ROW_OFFSET = 31;        // increased from 16 to 31 (53edo's 5th) for microLinn users

const byte microLinnMsg = 7;           // "HELLO NEW YORK!" will be truncated to make room for the user's settings
const byte microLinnMsgLength = 24;    // 31 chars (including the null) minus the 7 bytes in MicroLinn = 24 chars left

struct MicroLinn {                     // overlaps the audience messages array
  char nullTerminator;                 // truncates the audience message to 24 chars
  byte EDO;                            // limited to 5-72
  byte anchorPad;                      // numbered 8-207, same for both splits, anchorPad = 8 * anchorCol + anchorRow
  byte anchorNote;                     // any midi note 0-127, same for both splits
  signed char anchorCents;             // limited to ± 60 cents, same for both splits
  boolean skipFretting[2];             // can be set on either side
};  
MicroLinn* microLinn = (MicroLinn*)(Device.audienceMessages + 31 * microLinnMsg + microLinnMsgLength);
// anchorPad format:                left edge    right edge          anchorRow           anchorRowUser              
//                        top row:  15 23 31...  135 or 207              7                     1
//                        2nd row:  14 22 30...                          6                     2
//                        ...                                           ...                   ...
//                        low row:   8 16 24...  128 or 200              0                     8

boolean isSkipFretting (byte side) {       
  return microLinn->skipFretting[side];
}

void toggleSkipFretting (byte side) {
  microLinn->skipFretting[side] = !microLinn->skipFretting[side]; 
}

byte microLinnConfigRowNum = 5;                 // active row number for configuring the EDO and anchor data
byte microLinnAnchorRow;                        // numbered 0-7 bottom to top as usual
byte microLinnAnchorRowUser;                    // what the user sees, numbered 1-8 top to bottom, more intuitive for the general public
byte microLinnAnchorCol;                        // numbered 1-25 as usual
signed char microLinnAnchorCentsUser;           // what the user sees, ranges from -60 to 60, stored in the string as 4 to 114
float microLinnAnchorPitch;                     // midi note, but with 2 decimal places for anchorCents
byte microLinnEDOtone;                          // 9/8 in edosteps, used in transposing

void updateMicroLinnVars () {                                                      // called when user releases a touch in displayMicroLinnConfig
  microLinnAnchorRow = 8 - microLinnAnchorRowUser;                                 // also when user long-presses the skip-fretting pad
  microLinn->anchorPad = 8 * microLinnAnchorCol + microLinnAnchorRow;
  microLinn->anchorCents = microLinnAnchorCentsUser + 64;
  microLinnAnchorPitch = microLinn->anchorNote + microLinn->anchorCents/100;
  microLinnEDOtone = 2 * round (microLinn->EDO * log (3/2) / log (2)) - microLinn->EDO;     // whole tone = 9/8, calc as two 5ths minus an octave
}

byte microLinnMidiNote[NUMSPLITS][MAXROWS][MAXCOLS-1];         // the midi note that is output for each pad
short microLinnFineTuning[NUMSPLITS][MAXROWS][MAXCOLS-1];      // the deviation from 12edo for each pad, as a pitch bend number from -8192 to 8191
short microLinnTuningBend[NUMSPLITS][16][10];                  // 16 midi channels, up to 10 touches, tuning bends come from microLinnFineTuning
short microLinnSlideBend[NUMSPLITS][16][10];                   // 16 midi channels, up to 10 touches, slide bends come from sliding along the Linnstrument

short microLinnSumOfRowOffsets (byte row1, byte row2) {
  switch (Global.rowOffset) {
    case ROWOFFSET_OCTAVECUSTOM: return Global.customRowOffset  * (row1 - row2);
    case ROWOFFSET_GUITAR:       return Global.guitarTuning[row1] - Global.guitarTuning[row2];
    case ROWOFFSET_NOOVERLAP:    return (NUMCOLS - 1) * (row1 - row2);
    case ROWOFFSET_ZERO:         return 0;
    default:                     return Global.rowOffset * (row1 - row2); 
  }
}

void microLinnCalcTuningOfEachPad () {                                           // maps e.g. pad[LEFT][4][13] to note #60 - 5.0¢
  for (byte side = 0; side < 2; side++) {                                        // called on change to EDO, anchor, transpose, skipFretting, lefty
    for (byte row = 0; row < 8; row++) {
      for (byte col = 1; col <= 25; col++) {
        short padDistance = col - microLinnAnchorCol;                            // padDistance = distance from the anchor pad in edosteps
        if (isLeftHandedSplit(side)) {padDistance *= -1;}
        if (microLinn->skipFretting[side]) {padDistance *= 2;}
        padDistance += microLinnSumOfRowOffsets (microLinnAnchorRow, row);
        padDistance += Split[side].transposeOctave * microLinn->EDO;
        padDistance += Split[side].transposePitch * microLinnEDOtone;
        padDistance += Split[side].transposeLights;
        float note = microLinnAnchorPitch + padDistance * 12 / microLinn->EDO;   // convert to fractional 12edo midi note
        note = min (max (note, 0), 127); 
        microLinnMidiNote[side][row][col] = round (note);
        float bend = note - microLinnMidiNote[side][row][col];                   // fine-tuning bend as fraction of a semitone
        bend *= 8192 / getBendRange (side);                                      // fine-tuning bend as a zero-centered signed 13-bit integer
        microLinnFineTuning[side][row][col] = round (bend);                      // (to convert to midi, add 8192 and split into two bytes)
      }
    }
  }
}

void initializeMicroLinn () {                 // called in setup()
  if (microLinn->nullTerminator != '\0'       // if user had lengthened the audience message and we haven't truncated it yet,
   || microLinn->EDO == 0) {                  // or if user has never set the EDO, then this fork must be running for the very first time
    microLinn->nullTerminator = '\0';
    microLinn->EDO = 12;                      
    microLinn->anchorPad = 53;                // in 12edo, anchorPad and anchorNote are ignored
    microLinn->anchorNote = 62;               // D3, Kite guitar standard tuning
    microLinn->anchorCents = 4;               // 4 is really zero
    microLinn->skipFretting[LEFT] = false;
    microLinn->skipFretting[RIGHT] = false;
  }
  microLinnAnchorRow = microLinn->anchorPad % 8;
  microLinnAnchorRowUser = 8 - microLinnAnchorRow;
  microLinnAnchorCol = microLinn->anchorPad >> 3;
  microLinnAnchorCentsUser = microLinn->anchorCents - 64;
  microLinnAnchorPitch = microLinn->anchorNote + microLinn->anchorCents/100;
  microLinnEDOtone = 2 * round (microLinn->EDO * log (3/2) / log (2)) - microLinn->EDO;     // whole tone = 9/8, calc as two 5ths minus an octave
  microLinnCalcTuningOfEachPad ();
}

void handleMicroLinnConfigNewTouch() {
  if (sensorCol == 1) {
    if (sensorRow != 4 && sensorRow < 6) {
      microLinnConfigRowNum = sensorRow;
      updateDisplay();
    }
  } else {
    switch (microLinnConfigRowNum) {
      case 0: 
        handleNumericDataNewTouchCol(microLinnAnchorCentsUser, -60, 60, true); 
        break;
      case 1: 
        handleNumericDataNewTouchCol(microLinn->anchorNote, 0, 127, true); 
        break;
      case 2: 
        handleNumericDataNewTouchCol(microLinnAnchorCol, 1, NUMCOLS-1, true); 
        break;
      case 3: 
        handleNumericDataNewTouchCol(microLinnAnchorRowUser, 1, 8, true);
        break;
      case 5: 
        handleNumericDataNewTouchCol(microLinn->EDO, 5, 72, true); 
        break;
    }
  }
}

void handleMicroLinnConfigRelease() {
  handleNumericDataReleaseCol(false); 
  updateMicroLinnVars();
  microLinnCalcTuningOfEachPad();
}

void handleSkipFrettingLongPress () {               // long-press skip fretting button
  Global.rowOffset = ROWOFFSET_OCTAVECUSTOM;        // use custom row offset to get 13
  Global.customRowOffset = 13;                      // kite guitar uses +13 row offset
  Split[LEFT].playedTouchMode = playedSame;         // turn on same-note lighting for familiarity
  Split[RIGHT].playedTouchMode = playedSame;
  microLinn->skipFretting[LEFT] = true;
  microLinn->skipFretting[RIGHT] = true;
  microLinn->EDO = 41;
  microLinnAnchorRowUser = 3;
  microLinnAnchorCol = 6;
  microLinn->anchorNote = 62;                       // D3, Kite guitar standard tuning
  microLinnAnchorCentsUser = 0;
  updateMicroLinnVars();
  microLinnCalcTuningOfEachPad();
}

/**************************** DELETE THIS ONCE NEW MIDI IS WORKING ******************

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

*************************************************************************************/




/**************************** DELETE THIS ONCE NEW MIDI IS WORKING ******************
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
