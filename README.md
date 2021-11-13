# game-of-life
## About:
This repository is a basic implementation of Conway's Game of Life, a cellular automaton developed by the prolific mathematician John Horton Conway (with some foundations belonging to Ulam and von Neumann). This was originally a project for a CSC 250 course I took while working on my undergraduate degree and have since expanded upon. This current version is written in C and uses multiple, two-dimensional arrays in the main algorithm to update and accurately display the growth, decline or complete dissolution of neighborhoods of cells. My goal is to evolve it into more complex versions using different data structures as time permits and skill level increases.     


## What's Here?
### Currently there are two versions in this repository:

#### CLI-Only Version (gameOfLife.c): 
* Uses an "@" character to denote a live cell and a "." character to denote a dead/empty cell within a terminal window.

#### CLI Plus Graphics Version (gameOfLifeGfx.c): 
* Does what the CLI-only version does and also opens a supplemental graphics window to demonstrate live or dead/empty cells. Live cells are represented by filled circles and dead/empty ones are represented by empty space. See the .mp4 video in the repository for an example of this version running, which includes the CLI-Only version running simultaneously.  


## How to Run The Two Versions:
* Everything required for you to compile and run both versions of the Game of Life on a Linux system is in this repository, including a handy makefile.
 
* To run either program one step at a time, just press that trusty enter key. To run multiple times in a row, just hold down the enter key for a few seconds at a time or stack some input - you'll see an example of this in the .mp4 video included in the repository.
 
* The included gameData.txt file, which the programs read in for processing and display, stabilizes after about 800 iterations, and every character input into the terminal will product one iteration.
 
* Feel free to make your own data files to use, but if you use data files larger than 200 rows by 200 columns, be sure to change the MAX_ROWS and MAX_COLS definitions in the .c file for the corresponding program.


                 
