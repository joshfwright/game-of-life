/*
 * Programmer:  Joshua Wright
 *
 * Description: Requires gfx.h from "gfx: A Simple Graphics Library" by Douglas Thain, further extended 
 *              by Scott Graham into Version 3. Version 3 is included within the repository for this 
                project on GitHub, but can also be downloaded at:
 *              https://gist.github.com/OverProf/59a269b6208f907f4f6afd7a87a6240f 
 * 
 ****************************/

#include "gfx.h" // For some graphics functions not prototyped here
#include <math.h>

void drawBox(double centerX, double centerY, double width, double height); 

void drawTriangle (double aX, double aY, double bX, double bY, double cX, double cY);

void drawCircle(double centerX, double centerY, double radius);

void drawArc(double centerX, double centerY, double radius, double initalAngle, double finalAngle);
