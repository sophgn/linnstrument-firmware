


/**************************************** SKIP FRETTING and MICROLINN ****************************************/

// note to self:  "if (sensorCell->velocity)" means if another touch is already down on the same row
// according to the comment by handleFaderRelease in ls_faders.ino

// a few ideas I had, probably not needed
//short microLinnTuningBend[NUMSPLITS][16][10];                // 16 midi channels, 10 touches, tuning bends come from microLinnFineTuning
//short microLinnSlideBend[NUMSPLITS][16][10];                 // 16 midi channels, 10 touches, slide bends come from sliding along the Linnstrument
//short microLinnLandingBend[NUMSPLITS][16][10];               // 16 midi channels, 10 touches, landing bends come from the initial touch being off-center


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
  microLinnCalcTuning(false);
}
**********************************************************************************************/