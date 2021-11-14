# game-of-life
## About:
This repository is a basic implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life), a cellular automaton developed by the prolific mathematician [John Horton Conway](https://en.wikipedia.org/wiki/John_Horton_Conway) (with some foundations belonging to Ulam and von Neumann). This was originally a project for a CSC 250 course I took while working on my undergraduate degree and have since expanded upon. This current version is written in C and uses multiple, two-dimensional arrays in the main algorithm to update and accurately display the growth, decline or complete dissolution of neighborhoods of cells. My goal is to evolve it into more complex versions using different data structures as time permits and skill level increases.     

For an interesting example of what can be done with Conway's Game of Life, have a look at the [Code Challenge at Stack Exchange](https://codegolf.stackexchange.com/questions/88783/build-a-digital-clock-in-conways-game-of-life/) to build a digital clock using Conway's rules.

## What's Here?
### Currently there are two versions in this repository:

#### CLI-Only Version (gameOfLife.c, compiles as "gol"): 
* Uses an "@" character to denote a live cell and a "." character to denote a dead/empty cell within a terminal window.

#### CLI + Gfx Version (gameOfLifeGfx.c, compiles as "golgfx"): 
* Does what the CLI-only version does regarding stats but implements a graphics window to demonstrate live or dead/empty cells rather than using text characters. Live cells are represented by filled circles and dead/empty ones are represented by empty space. See the .mp4 below for an example of this version running.  


video video will be here shortly



## How to Run The Two Versions:
* Everything required to compile and run both versions of the Game of Life on a Linux system is in this repository, including a handy makefile.
 
* Just type make, then type either "./gol default.txt", or "./golgfx default.txt", to run the programs with the included default data file. 

* Replace default.txt with your own custom data file for some fun experimentation, just be sure to change the MAX_ROWS and MAX_COLS definitions in the .c file for the corresponding program if you exceed 200 rows or 200 columns. Usage for custom data files is the same as above, 
e.g. "./golgfx yourCustomFilename.withOrWithoutAnExtension".  
 
* To run either program one step at a time, just press that trusty enter key. To run multiple times in a row, just hold down the enter key for a few seconds at a time, or stack some input - like you'll see in the .mp4 above.
 
* The included default.txt file stabilizes after about 800 iterations and produces some classic shapes such as gliders, pulsars, blinkers, bee hives, loafs and possibly some others.
 
               
