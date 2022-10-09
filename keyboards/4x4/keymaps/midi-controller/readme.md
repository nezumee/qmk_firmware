# Launchpad-like MIDI controller with per-key RGB

This layout shows how to make a keyboard with per-key RGB LEDs react to MIDI feedback messages. I'm using it to show clips in each track, lighting up the keys that have a clip.

From my research, the basic idea is that when a MIDI controller mapping is configured in the DAW, it sends events with the same mapping back to the controller to make it reflect the current state.
For example, if note C2 is assigned to play function (controller sends C2 to start playing), DAW will send C2 note-on message to the controller whenever playing starts, and note-off when it stops and controller can turn on the light under the play button accordingly.
Different colors are represented by using different velocities. For example, in Ableton Live, velocity 5 is used to set red color, 21 is green etc. List of colors is available here: https://github.com/gluon/AbletonLive9_RemoteScripts/blob/0c0db5e2e29bbed88c82bf327f54d4968d36937e/Push/Colors.py#L244

So, to implement the feedback, the keyboard must listens to MIDI note messages, stores the last value for each note in memory, and then uses that value for the per-key LED when the corresponding note is assigned to a key in the layout.

To integrate with Ableton Live, I've tweaked the remote MIDI script from https://github.com/laidlaw42/ableton-live-midi-remote-scripts, assigning the notes C2 through G4 (MI_C through MI_G_2) in a 8x4 block to represent the session view. The scripts are in the FourByFour folder.
A bunch of other functions are assigned to more notes, see MIDI_map.py and keyboard layout at http://www.keyboard-layout-editor.com/##@_name=4x4%20planck%20ableton;&@_a:7;&=Keyb&_c=#17cf34;&=&=&=&=&=&=&=&=&_c=#cccccc;&=Scene%201&=Up&=Track%20option;&@=Device//%20roll&_c=#17cf34;&=&=&=&=&=&=&=&=&_c=#cccccc;&=Scene%202&=Down&=Clip//%20track;&@=Rec&_c=#17cf34;&=&=&=&=&=&=&=&=&_c=#cccccc;&=Scene%203&=Quant&=Dup;&@=Play&_c=#17cf34;&=&=&=&=&=&=&=&=&_c=#cccccc;&=Scene%204&=Undo&=Redo