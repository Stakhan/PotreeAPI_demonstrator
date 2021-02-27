# PotreeAPI demonstrator

## About
A small demonstrator proving the ability to communicate between some C++ code and [a slightly modified version of Potree](https://github.com/Stakhan/potree).

## Getting Started

### Cloning this repository
:warning: You have to use the `--recursive` option to ensure that the whole repository is being cloned, because it contains a submodule (a nested repository):
```
git clone --recursive https://github.com/Stakhan/PotreeAPI_demonstrator
```

### Dependencies
Make sure you have qt5 installed with the websockets and webengine modules.

__On Ubuntu 20.04 / Debian 10__: 
+ `qt5-default`
+ `libqt5websockets5-dev`
+ `qtwebengine5-dev`

__On Manjaro Linux__: 
+ `qt5-base`
+ `qt5-websockets`
+ `qt5-webengine`

### Compiling
In the project folder, in a shell:
```
qmake
make
```

### Running
1. Make sure [the slightly modified version of Potree](https://github.com/Stakhan/potree) has been installed.

To install it, go to the potree folder and launch:
```
npm install
``` 

2. Make sure Potree is running on `http://localhost:1234`. The latter can easily be done by using npm in the potree folder:
```
npm start 
```
Or by launching any [static http server one-liner](https://gist.github.com/willurd/5720255) on port 1234.

3. You should then be able to run the binary file called `demo`.

## Documentation

+ [User Documentation](docs/user_doc.md)
+ [Developer Documentation](docs/dev_docs/md/dev_docs.md)
