# PotreeAPI demonstrator

## About
Demonstration of communication between C++ code and [a slightly modified version of Potree](https://github.com/Stakhan/potree).

## Compiling
Make sure you have qt5 installed with the websockets module. On Manjaro Linux this corresponds to the `qt5-base`and `qt5-websockets` packages.

Then, in a shell :
```
qmake
make
```
Optionally, you can clean non-necessary files :
```
make distclean
```
## Running
You should be able to run the binary file called `demo`.

