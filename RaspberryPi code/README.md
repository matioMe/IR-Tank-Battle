# Information on files

This is a Qt Application.

To compile it, you have two possibilities:

## First possibility

You can copy the GUI_Tank folder on the Pi and use qmake on the RaspberryPi with these command lines:

    qmake
    make

It will compile the project and create a executable file.

Then you can launch the program using:
    
    ./GUI_Tank

## Second possibility

You can install a cross-compilation toolchain. A tutorial is available here in french:

https://www.logre.eu/wiki/Cross-compilation_Qt_pour_Raspberry_Pi

