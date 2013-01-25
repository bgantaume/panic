panic button project
====================

* Goal

This project is aimed at hooking the button pressed event using usb hid api.
The goal was to connect it to a RasberryPi board.
And it works!

* Build and run

gcc main.cpp -lhidapi-libusb -o panic
sudo ./panic 

* Dependencies

This code sample requires hidapi lib
git clone git://github.com/signal11/hidapi.git

** Lib pre-requisite

sudo apt-get install libudev-dev libusb-1.0-0-dev 
sudo apt-get install autotools-dev
sudo apt-get install dh-autoreconf

** Build lib

./bootstrap
./configure
make
make install 

