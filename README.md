# PotreeAPI demonstrator

## About
Demonstration of communication between C++ code and [a slightly modified version of Potree](https://github.com/Stakhan/potree).

## Dependencies
Make sure you have qt5 installed with the websockets and webengine modules.
### On Manjaro Linux 
The following packages:
+`qt5-base`
+`qt5-websockets`
+`qt5-webengine`
### On Ubuntu 20.04 / Debian 
The following packages:
+ `qt5-default`
+ `libqt5websockets5-dev`
+ `qtwebengine5-dev`

## Compiling
In the project folder, in a shell :
```
qmake
make
```

## Running
1. Make sure [the slightly modified version of Potree](https://github.com/Stakhan/potree) has been installed. In the potree folder:
```
npm install
``` 

2. And is running on `http://localhost:1234`. The latter can easily be done by using npm in the potree folder:
```
npm start 
```
Or by launching any [static http server one-liner](https://gist.github.com/willurd/5720255) on port 1234.

3. You should then be able to run the binary file called `demo`.

## TODOS
+ [x] Implement sending data to websocket client
+ [x] Implement signal on "Pick a point" button

