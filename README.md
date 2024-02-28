/**************************************** MICROLINN ****************************************/


WARNING: unfinished, many features don't work yet. In particular, the microtonal features require a helper app, microLinn.jsfx.
But the sequence chaining and the scale +/- footswitches do work.



-------- INSTALLATION -------- 

WARNING: installing this fork deletes your Linnstrument's settings and calibration (for now, fix coming soon).

1) Download the latest installer (2.3.3 as of Feb '24) from https://www.rogerlinndesign.com/support/support-linnstrument-update-software. 
2) Download the latest version of linnstrument-firmware-microLinn.bin from this github.
3) If on a mac, put both the updater and the .bin file on your **desktop**. If on a PC, _______________.
4) Run the updater. Don't run anything else while it's running. If it asks for permission to read files from the desktop, say yes.
5) Confirm the update by short-pressing the OS version (global settings, column 16). It should be 234.08A. If not, try using the 2.3.0 updater instead. 

-------- NON-MICROTONAL FEATURES -------- 

BLINKING MODE: This is a variation of the SAME mode that shows you other occurences of the currently played note.

CHAINING SEQUENCES: hold down the pad for sequence #1 and tap the pad for sequence #2. Now the two sequences are chained into a single 
sequence twice as long. You can chain #3 and #4 together as well. Or chain all 4 together. The PREV and NEXT footswitches work as expected.
To clear the chaining, tap the pad immediately to the left of the 4 selector pads. Or just disconnect the Linnstrument and reconnect it.
You can select sequences on the fly as the sequencer is playing as usual. You can also chain, re-chain and unchain on the fly. 
When chaining on the fly, to start at the beginning of the chain not the end, hold the last sequence and tap the first one.

NEW SWITCH/FOOTSWITCH FUNCTIONS: SCL+ and SCL- cycle you through the 9 scales in Global columns 2-4 (only affects the note lights).

COLUMN OFFSETS: The column offset can be set for each split independently. This allows Wicki-Hayden layout on the left for easy chord
playing and normal layout on the right for easy melody playing. Access it throught microLinn, see below.

-------- MICROTONAL FEATURES -------- 

On the global settings screen, long-press col 1 bottom row (VIEW MAIN) to go to the main microLinn display.
Once the edo (notes per octave) is set to anything other than OFF, VIEW MAIN turns light blue and you can short-press it.
The display has 10 buttons. Long-press each one to see its function. Most don't work until you set the edo.

1) edo (notes per octave)
2) octave stretch in cents

3) anchor cell
4) anchor note
5) anchor cents

6) left column offset
7) right column offset

8) set note lights

9) set to Kite guitar
10) reset to 12-equal

The anchor cell is a specific cell or pad that doesn't change pitch when you change the notes per octave.
The anchor cell chooser displays the row and column of the current anchor cell, e.g. R3C6 means row 3 (from the top) and column 6. 
To choose a new anchor cell, tap the blue "R3C6" and then tap any pad.

When the notes per octave is greater than 12, the OCTAVE/TRANSPOSE display shows 2 extra rows for transposing by edosteps.
The 2nd and 3rd rows now transpose not by semitones but by major 2nds (since most edos have several different semitones).

There are 4 new functions for switches 1 & 2 and footswitches 1 & 2: 
EDO+ and EDO- move up or down to the next EDO, wraps around (probably best you don't play while changing!)
SCL+ and SCL- move up or down to the next scale, wraps around (only affects the note lights)

The first 9 scales in cols 2-4 are now microtonal and change for each edo. You can edit them and their colors in microLinn's note lights. 
Shortcut: you can long-press the scale's pad on the global settings display to go directly to that scale.

The note lights display has 7 scale buttons plus the color editor, the dots selector and the mass-selector button.
Tap a note in a scale to toggle it on or off. Tap a note in the color editor to cycle it thru the rainbow. 

Tapping the dots selector makes the dots appear mid-screen. Tapping there puts you in a full-screen editor 
that lets you toggle dots on or off. 

Long-press the scale buttons or color editor button or the dots selector button to reset the note lights to the default. 
Hold the mass-selector button in column 3 row 5 while selecting something and your selection will be applied to all 51 edos at once. 
Hold it while long-pressing another button to mass-reset that scale/rainbow/dot-pattern for all 51 edos.

The 3 custom light patterns are totally separate from all this and are still available for use!
This web browser lets you easily edit them: https://forrcaho.github.io/linnstrument_colorizer/

When microLinn is on, the global setting of lefthandedness is ignored. Set the column offsets to -1 to get lefthandedness.

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
The first few edos are pretty strange. Try starting with 15, 17, 19 or 22.
The rainbow colors can be overwhelming. Try setting the played mode to BLNK or BLNK8.

To create JI or rank-2 scales with N notes, set the edo to 12 but play as if in N-edo, think one midi note per edostep.
Load a scala file into your synth or run alt-tuner to produce that N-note scale.
eEch note is slightly sharper or flatter from N-edo, thus the pad's note will be different slid up to vs played directly.
However this is only a comma or so difference even on long slides, which might be tolerable.
Perhaps software on the PC could fix this problem by scaling the slides by adjusting the pitch bends?


To find all changes to the code, search for "microlinn" or "brightness" or "playedBlink" or "patternChain"





=============================

"Skip-fretting" is a column offset of 2 - each subsequent pad represents every other MIDI note, so note 0 2 4 6 8 ... instead of 0 1 2 3 4. 
The name is in reference to the microtonal [kite guitar](https://kiteguitar.com/), which obviously uses frets and not keys, but the Linnstrument's 
rows and columns work just like strings and frets.

Why would you want to skip half the notes? On the kite guitar, strings are 13 steps apart, which you can achieve on the Linnstrument by setting 
the Row Offset to a custom value of 13 (Global Settings -> Row Offset -> hold down "Octave" to get the secret menu -> swipe right). 
Thirteen is an odd number, so that means that if the first row represented the _even_ scale degrees (0 2 4 6 8...), the next row will represent 
the _odd_ scale degrees (..13 15 17 19 21..)! Thus you actually have access to **all** the midi notes after all, with two neighboring rows filling 
each other's gaps. 

This is handy, as 41 notes per octave would not otherwise fit on a single row. But with half that, you get at least an octave per row on a 200-pad 
instrument. Luckily, you typically only want the odds or evens at the same time on the same string/row anyway, as explained on the kite guitar website.

# Install
Follow the [standard directions](https://www.rogerlinndesign.com/support/support-linnstrument-update-software), but replace the `.bin` file in the
updater bundle with the one found in the Releases section of this project.

WARNING: this method does not preserve your Linnstruments' settings and calibration (for now).

If you're not on mac or windows but gnu/linux, you can still do it using `arduino-cli`, or by cloning this project, opening it in Arduino IDE 
(following the Dev section below), and hitting "Upload" - no coding or command line required. 

# Kite Guitar Mode
- Enables skip fretting (column offset of 2)
- Enables Custom Row Offset
- Sets the Custom Row Offset to 13 steps (kite tuning)
- Sets `PLAYED` note lighting to `SAME` mode, so you can see which other pads represent the same note as you learn the kite layout (optional)

# Development

These sources assume that you're using Arduino IDE v1.8.1 with SAM boards v1.6.11.
Different versions of this package might create unknown build and execution problems.
I use the flatpak version of Arduino IDE, which means the build environment is nicely sandboxed. This means you can just pick the versions 
as per the instructions and all other software will work the same.

Instructions from [Linnstrument support page](https://www.rogerlinndesign.com/support/support-linnstrument-source-code):
-    Visit the Ardunino downloads page and follow the instructions for downloading the latest Arduino IDE.
-    Launch the "Arduino IDE" app.
-    Connect your LinnStrument via USB, then turn on UPDATE OS mode (Global Settings > Actions column).
-    In the Arduino IDE, Click Tools menu > Board > "Boards Manager...", then Install "Arduino SAM Boards". Then click Tools menu > Board > "Arduino SAM boards (32 bit ARM Cortex M3)" > "Arduino Due (Programming Port)".
-    Go to Sketch > Include Library > "Manage Libraries...". Search for "DueFlashStorage" and install it.
-    Go to File menu > "Open..." and select the file "linnstrument-firmware.ino" in the "linnStrument-firmware" directory that you downloaded above.
-    Go to Tools menu > Port and select your LinnStrument port from there. (It starts with /dev/cu.usbmodem followed by a number.)
-    In the "linnstrument-firmware" window, click the top-left check mark icon (Verify) to compile the code. If you receive compilation errors or warnings, check the above steps.
    Note: You can simply click the Upload button (right-facing arrow) in the IDE to upload your code to LinnStrument, but this will reset LinnStrument's sequencer data, stored panel settings, and sensor calibration data to defaults, requiring you to perform a subsequent 'Global Settings > Calibration' after the upload. To avoid losing this data, do the following additional steps:
-    Compile your LinnStrument firmware as above by clicking the Arduino IDE's "Verify" button (the checkmark button in upper left corner).
-    In the IDE's Output pane, select and copy the file path that will appear similar to the picture at the bottom of this page, starting with "/var" and ending with ".bin":
-    On mac, open a finder window, press Shift + Command G, paste the line you just copied and press Enter. This will take you to the location of the newly-compiled OS file. On Windows, go to the directory indicated by the file path.
-    From the LinnStrument Support page, click the "Update OS" page and download the latest Updater app. Place your newly compiled OS file in the same directory as the Updater app. Now the Updater app will load your newly compiled OS file instead of the OS file inside the Updater app. By using this method to load your edited source code, your LinnStrument's settings and calibration data will be preserved.

# Support
For support with the official firmware, email Roger at support@rogerlinndesign.com.
For requests for this fork, open an new issue.
