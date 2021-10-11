# Ringcon-Driver
Play your favourite PC games with Nintendos impressive Ring fit controller system. Attach one Joycon to the Ring-Con, attach the other to your leg with the strap (herein called the strapcon). This driver converts the inputs to correspond with an Xbox 360 controller which can be used on most pc games.


# Installing the software
 * Download the latest version from the releases tab https://github.com/ringrunnermg/Ringcon-Driver/releases/tag/1.0.2
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
 * Connect the Ringcon

# How to use!
 * Always leave the Ringcon driver running in the background.
 * If you tick or untick an option after the program is running then that option will immediately take effect.
 * If you lay down your Ringcon after the program is running then it will be the same as holding forward on an x360 controller. In menus this makes the selected option go up and up and up so it is difficult to click on things. The easy fix for this is to tick "run unlocks gyro" (which you should have ticked anyway as that will give you far more exercise in any games you play), then don't run. This will stop the virtual analog stick from being pushed up. 

# Ringcon to X360 controller mapping
Mode 1 and Mode 2
 * Ringcon tilt/rotate = Left analog stick
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
 * Joycon analog stick = x360 right analog stick
 * Joycon Zr (trigger) = Right trigger (the alternative for heavy press)

# Program details
![Ringcon Driver 11-10-2021](https://user-images.githubusercontent.com/75189281/136767391-f8424c98-34aa-4192-b659-4179aaadf7d4.png)

* **Combine JoyCons**: Combines both Joycons into one X360 controller. 
* **Reverse Stick X**: Reverses axis when joycons are not combined.
* **Reverse Stick Y**: Reverses axis when joycons are not combined.

RINGCON/STRAPCON OPTIONS:
* **Ringcon Full RH**: Refer to "Mode 2" details.
* **Run Unlocks Gyro**: In this case "Gyro" refers to the left analog stick of the virtual X360 controller. With this checked, you have to run or else tilting the Ringcon does nothing.
* **Ringcon to Analog Stick**: Allows the user to control the virtual X360 right stick Y axis with the Ringcon push/pull functionality. Used in the Ringcordian. https://github.com/ressium/Ringcordion
* **Squat Slow Gyro**: This allows more precise control of the left analog stick that is controlled by the Ringcon movement. The more you squat, the less the stick moves in the direction of the Ringcon. This can also be used to temporarily turn off the "Run unlocks Gyro" option which is especially useful in menus, simply squat (or lift your leg) and the Ringcon unlocks for much easier menu navigation.
* **Run Presses Button**: Originally running would press a button on the controller by default, now it does not unless you check this button. For games like Skyrim where you are forced to assign every button to an action, this was an issue. Note: This is for run only, sprint is always assigned to a button.
* **Ringcon Fix**: The command window now shows the current value of the Ringcon sensor. The default when it is not being pressed should be around 10 (give or take). If it is showing around 0 and goes in to the negatives when it is pulled (as some users have found) then this checkbox may fix that issue. Note: This is untested.

JOYCON OPTIONS:
Refer to the original Joycon Driver (https://github.com/mfosse/JoyCon-Driver) for details.

# Acknowledgements
- [mfosse](https://github.com/mfosse/JoyCon-Driver) As this is based on the Joycon Driver by mfosse it would be rude not to point him out first 
- [nefarius](https://github.com/ViGEm/ViGEmBus) for his ViGEm project and being the *insert controller name* to pc master
- [ctcaer](https://github.com/CTCaer/jc_toolkit) for his work on the joycon toolkit
- [dekuNukem](https://github.com/dekuNukem/Nintendo_Switch_Reverse_Engineering) for all of the Bluetooth research
- [mart1nro](https://github.com/mart1nro/joycontrol) for making the program which allowed me to get the Ringcon instructions slowly but surely

