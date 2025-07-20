# Cpu_Usage
simple cpu usage graphical app , just try it , you won't lose nothing :)


#Installation :
first you should have gcc or clang pre-installed , then you can install SDL2 library (this create windows , renders ...) ;

* to install gcc / clang :
=> `sudo apt install gcc` or `sudo apt install clang`

* to install SDL2 (with fonts feature support) :
=> `apt install libsdl2-dev libsdl2-ttf-dev`

After that , clone this repo :
`git clone https://github.com/Yas-Devp/Cpu_Usage`

#Usage :
run this command for compiling and generating executable form :
`gcc cpu_info.c -o cpu_info $(sdl2-config --cflags --libs) -lSDL2_ttf`

And now just run it :
`./cpu_info`

~~~~~~
This is my simple app , I will make it supports other things soon ._.
~~~~~~
