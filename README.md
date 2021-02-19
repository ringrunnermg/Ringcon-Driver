# Ringcon-Driver
Play your favourite PC games with Nintendos impressive Ring fit controller system. Attach one Joycon to the Ring-Con, attach the other to your leg with the strap (herein called the strapcon). This driver converts the inputs to correspond with an Xbox 360 controller which can be used on most pc games.


# Installing the software
 * Download the latest version from the releases tab https://github.com/ringrunnermg/Ringcon-Driver/releases/tag/1.0.0
 * Download the latest version of Vigembus from https://github.com/ViGEm/ViGEmBus/releases and install it
 * Connect the controllers (info below) 
 * Run the program, this should set up a virtual x360 controller on your computer.
 
There are currently 2 main modes.

Mode 1 - Ringcon purist/Minimal controller: Tick "Combine JoyCons" then push start. This will set up a minimal controller where you hold the Ringcon in the normal orientation. Tilt the Ringcon forward and backward to go forward and backward. Rotate left or right like a steering wheel to move left or right. Light squeeze, heavy squeeze, light pull, heavy pull all correspond to main buttons.

Mode 2 - Full controller mode: Tick "Combine JoyCons" and "Ringcon Full RH" then push start. In this mode you hold the Ringcon sideways so you can access the buttons and stick on the Joycon with your right hand. The Ringcon tilting/rotating still controls the left stick of the virtual x360 controller, the analog stick on the Joycon controls the right analog stick. The buttons on the Joycon are usable as well as squat, run and sprint. Note: DO NOT USE HEAVY PRESS IN THIS CONFIGURATION. I have disabled it as it goes outside Nintendos limits and may damage the Ringcon. Be careful. You have been warned.

At any point you can check or uncheck "Run unlocks gyro" which locks the Ringcon gyro (usually used for character movement) unless you are running.

# Connecting and Disconnecting the Controllers
 * Hold down the bluetooth button on the controller until the lights start flashing.
 * Go to the bluetooth settings on Windows 10 and add a device. The controller should show up as "Joycon(L)" or "Joycon(R)"
 * Make sure the Joycon shows up in the bluetooth settings as connected, the lights should still be flashing (This seems to be where windows 7 falls over... Note: The Ringcon Driver does not work on windows 7)
 * Connect the other controller, ensure you now have both controllers showing up under Bluetooth as connected.

# How to use!
 * Always leave the Ringcon driver running in the background.
 * If you tick or untick an option after the program is running then that option will immediately take effect.
 * If you lay down your Ringcon after the program is running then it will be the same as holding forward on an x360 controller. In menus this makes the selected option go up and up and up so it is difficult to click on things. The easy fix for this is to tick "run unlocks gyro" (which you should have ticked anyway as that will give you far more exercise in any games you play), then don't run. This will stop the virtual analog stick from being pushed up. 

# Ringcon to X360 controller mapping
Mode 1 and Mode 2
 * Ringcon tilt = Right analog stick
 * Ringcon light press = Right shoulder button
 * Ringcon light pull = Left shoulder button
 * Ringcon heavy press = Right trigger
 * Ringcon heavy pull = Left trigger
 * Run = Left thumb stick button
 * Sprint = Right thumb stick button
 * Squat = Back button
 * Strapcon left = left
 * Strapcon right = right
 * Strapcon down = down
 * Strapcon up = up

Mode 2 (Ringcon Full RH)
 * Do not heavy press! This has been disabled.
 * Turn the Ring so the Red joycon is in your right hand
 * Joycon Y = x360 B
 * Joycon X = x360 A
 * Joycon A = x360 X
 * Joycon B = x360 Y
 * Joycon analog stick = x360 left analog stick
 * Joycon Zr (trigger) = Right trigger (the alternative for heavy press)

# Acknowledgements
- [mfosse](https://github.com/mfosse/JoyCon-Driver) As this is based on the Joycon Driver by mfosse it would be rude not to point him out first 
- [nefarius](https://github.com/ViGEm/ViGEmBus) for his ViGEm project and being the *insert controller name* to pc master
- [ctcaer](https://github.com/CTCaer/jc_toolkit) for his work on the joycon toolkit
- [dekuNukem](https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering) for all of the Bluetooth research
- [mart1nro](https://github.com/mart1nro/joycontrol) for making the program which allowed me to get the Ringcon instructions slowly but surely

