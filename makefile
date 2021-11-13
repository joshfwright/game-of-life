# Joshua Wright
# makefile for all versions of gameOfLife in this project.
# Updated: November 12, 2021
# Original Version: March 08, 2021

# use the .RECIPEPREFIX variable so we can use > for recipie lines instead of the default [tab].
.RECIPEPREFIX = >


# Rebuild all end-product targets
all: gameOfLife gameOfLifeGfx gfxGraphicsLib.o


# Use when the graphics library object needs updating
gfxGraphicsLib.o: gfxGraphicsLib.c gfxGraphicsLib.h
>@   echo "Rebuilding library gfxGraphicsLib.o ..."
>   gcc -c gfxGraphicsLib.c


# This is the command-line interface version which uses the "@" character for cell display:
gameOfLife: gameOfLife.c     
>@  echo "Rebuilding gameOfLife.c into the program named gol ..."
>   gcc -g gameOfLife.c -o gol


# This version requires the gfx library and uses both the terminal window and a graphics window:  
gameOfLifeGfx: gameOfLifeGfx.c gfxGraphicsLib.o    
>@  echo "Rebuilding gameofLifeGfx into the program named golgfx ..."
>   gcc -g gameOfLifeGfx.c gfx.o gfxGraphicsLib.o -o golgfx -lm -lX11


# Delete all:
clean:
>   rm -f gfxGraphicsLib.o
>   rm -f gol
>   rm -f golgfx
