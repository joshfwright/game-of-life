/*
 * Description: A library extension for drawing various shapes based on the gfx: Version 3 library. 
 *                          
 *******************************************/


#include "gfxGraphicsLib.h" 

// Draws an unfilled rectangle in clockwise fashion.
void drawBox(double centerX, double centerY, double width, double height) 
{
    gfx_line(centerX - width/2, centerY - height/2, centerX + width/2, centerY - height/2); // Line across the top
    gfx_line(centerX + width/2, centerY - height/2, centerX + width/2, centerY + height/2); // Line down the right side
    gfx_line(centerX + width/2, centerY + height/2, centerX - width/2, centerY + height/2); // Line back across the bottom
    gfx_line(centerX - width/2, centerY + height/2, centerX - width/2, centerY - height/2); // Line up the left side
}

// Unfilled triangle
void drawTriangle (double aX, double aY, double bX, double bY, double cX, double cY)
{
    gfx_line(aX,aY,bX,bY); // leftmost side
    gfx_line(bX,bY,cX,cY); // rightmost side
    gfx_line(cX,cY,aX,aY); // bottom from right to left
}


// Unfilled circle
void drawCircle(double centerX, double centerY, double radius)
{
    int numSteps = radius + 8;
    double angleIncrement = 2 * M_PI / (radius + 8);
    double previousX = centerX + radius * cos(0);
    double previousY = centerY + radius * sin(0);  
    
    for(int i = 1; i <= numSteps; i++)
    {
        double angle = angleIncrement * i;
        double x = centerX + radius * cos(angle);
        double y = centerY + radius * sin(angle);
        gfx_line(previousX, previousY, x, y);
        
        previousX = x;
        previousY = y;
    }
}


// Unfilled arc
void drawArc(double centerX, double centerY, double radius, double initialAngle, double finalAngle)
{
    
    double angleIncrement = 2 * M_PI / (radius + 5);
    double previousX = centerX + radius * cos(initialAngle);
    double previousY = centerY + radius * sin(initialAngle);    

    for(double angle = initialAngle + angleIncrement; angle < finalAngle; angle = angle + angleIncrement)
    {
        
        double x = centerX + radius * cos(angle);
        double y = centerY + radius * sin(angle);
        gfx_line(previousX, previousY, x, y);        
        previousX = x;
        previousY = y;
    }
}

// More shapes to come...

