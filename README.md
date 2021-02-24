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
## Running
Make sure Potree is running on `http://localhost:1234`. This can easily be done if you have python installed :
```
cd potree
# If your Python version is >= 3.X
python -m http.server --directory ./potree 1234
```

You should then be able to run the binary file called `demo`.

## TODOS
+ [ ] Implement sending data to websocket client
+ [ ] Implement signal on "Pick a point" button
+ [ ] Script to automate Potree installation and launch 

