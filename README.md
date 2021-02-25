# PotreeAPI demonstrator

## About
Demonstration of communication between C++ code and [a slightly modified version of Potree](https://github.com/Stakhan/potree).

## Dependencies
Make sure you have qt5 installed with the websockets webengine modules. On Manjaro Linux this corresponds to the `qt5-base`, `qt5-websockets` and `qt5-webengine` packages.

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

