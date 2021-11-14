# Joshua Wright
# makefile for all versions of gameOfLife in this project.
# Updated: November 13, 2021
# Original Version: March 08, 2021

# use the .RECIPEPREFIX variable so we can use > for recipie lines instead of the default [tab].
.RECIPEPREFIX = >


all: gfx.o gfxGraphicsLib.o gameOfLife gameOfLifeGfx  


# Base graphics library object:
gfx.o: gfx.c gfx.h
>@   echo "Rebuilding the base graphics library gfx.o ..."
>   gcc -c gfx.c


# Extended graphics library object: 
gfxGraphicsLib.o: gfxGraphicsLib.c gfxGraphicsLib.h
>@   echo "Rebuilding the extended library gfxGraphicsLib.o ..."
>   gcc -c gfxGraphicsLib.c


# This is the command-line interface version which uses the "@" character for cell display:
gameOfLife: gameOfLife.c     
>@  echo "Rebuilding gameOfLife.c into the program named gol ..."
>   gcc -g gameOfLife.c -o gol


# This version requires the gfx library and uses both the terminal window and a graphics window:  
gameOfLifeGfx: gameOfLifeGfx.c gfxGraphicsLib.o    
>@  echo "Rebuilding gameofLifeGfx into the program named golgfx ..."
>   gcc -g gameOfLifeGfx.c gfx.o gfxGraphicsLib.o -o golgfx -lm -lX11


clean:
>   rm -f gfx.o
>   rm -f gfxGraphicsLib.o
>   rm -f gol
>   rm -f golgfx
