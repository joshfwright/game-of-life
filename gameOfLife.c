/*
 * Last Updated: November 13, 2021
 * Date Created: March 8, 2021
 *
 * Programmer:   Joshua Wright
 * 
 * Description:  A CLI-only implementation of Conway's Game of Life. Originally written for a CSC 250 course (May, 2021) 
 *               I had at Dakota State University, and further modified for personal use.
 *               The rules and general information for Conway's Game of Life can be found at:
 *                                                     https://en.wikipedia.org/wiki/Conway's_Game_of_Life
 * 
 * Dependencies: 1. Requires a plain text file to run, with the following structure: 
 *                  a. The first line holds two values, space separated, that indicate the number of rows 
 *                     followed by the number of columns (i.e. 50 200).
 
 *                  b. Rows thereafter can hold either an "@" sign to represent a live cell or a standard period "." 
 *                     to indicate a dead cell. The number of columns in each row, and the number of rows in the file 
 *                     (excluding the first line holding the row and column sizes) must adhere to the values listed on 
 *                     the first line. Open the gameData.txt file included in the directory of this project
 *                     to see a concrete example.
 *                     
 **********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ROWS 200
#define MAX_COLS 200

//GLOBALS:
int numRows, numCols;


/***********************************************************************************************                               
 * Name:LoadFile()
 * Purpose: Opens, reads, and closes a pre-formatted file in read-only mode for program I/O
 * Called From: main()   
 ***********************************************************************************************/
void LoadFile(char *filename, int cellGrid[MAX_ROWS][MAX_COLS]) 
{   
    // Locals 
    char temp, userAnswer, successFlag;
    FILE* gameData; // the FILE data type   
    gameData = fopen(filename, "r");     

    // fopen() will return NULL when it fails to open
    if(gameData == NULL)
    {
        // NOTE: This is not the best way to do this...I'll be integrating a separate user menu function
        //       soon to handle this situation and offer the user better options for custom data files. 
        printf("\n Could not find or open the Game of Life data file.\n");
        printf(" Be sure to include the data file name after the program name.\n\n");
        printf(" Please enter 'd' to run the program with the default data file\n");
        printf(" or any other character to exit and retry the file name: ");
        
        userAnswer = getchar();
        
        if (userAnswer == 'd')
        {
            gameData = fopen("default.txt", "r");
        }
        else
        {
            exit(1);
        } 
    }         

    // PRIMING READ: Gets row and column sizes from first line of data file as sentinel values
    fscanf(gameData," %d %d", &numRows, &numCols);     

    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++) 
        { 
            fscanf(gameData," %c", &temp);
            
            // checks for the ASCII Decimal representation of the "@" character, which is 64           
            cellGrid[i][j] = (temp == 64) ? 1 : 0; 
        } 
    }
    fclose(gameData);
    
    // Let the user know the file loaded and wait for some benign user input so 
    // the the 0th generation is always visible to user:    
    printf("\nData file loaded successfully! Press enter to run the program. \n");
    successFlag = getchar(); 
    
}// End LoadFile()


/**************************************************************************************************
 *Name:    CountLiveCells((int[][], int, int)
 *Purpose: Counts the results of the cell grid after iterations. 
 *Called From: main()
 *Returns: A count of the current number of living cells in each generation
 **************************************************************************************************/
int CountLiveCells(int grid[MAX_ROWS][MAX_COLS], int numRows, int numCols)
{
    int count = numRows * numCols;
    
    for(int i=0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if(grid[i][j] == 1)
            {
                count++;
            }
            else
            {
                count--;
            }        
        }        
    }
    return count;
}


/**************************************************************************************************
 *Name:    DisplayLifeGrid(int[][], int, int)
 *Purpose: Displays the results of the cell grid after iterations. 
 *Called From: main()  
 **************************************************************************************************/
void DisplayLifeGrid(int grid[MAX_ROWS][MAX_COLS], int numRows, int numCols)
{
    for(int i=0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if(grid[i][j] == 1)
            {
                printf("@");
            }
            else
            {
                printf(".");
            }        
        } 
        printf("\n");
    }
}


/**************************************************************************************************
 *Name:    UpdateLifeGrid(int[][], int, int)
 *Purpose: Creates a copy of the cellGrid 2D array, then uses the copy to index a roaming 3x3 grid 
 *         that evaluates, on a 0 or 1 basis, neighboring cells in relation to the centerpoint of 
 *         the roaming grid. Elements of the array (i.e. cells) are updated, or left alone, so their 
 *         states can be one of the three according to John Conway's Game of Life: 
 *                                         living/empty....(remaining a 1 or 0) 
 *                                         empty...........(becoming a 0 from a 1)
 *                                         birthed.........(becoming a 1 from a 0)
 *Called From: main()  
 **************************************************************************************************/
void UpdateLifeGrid(int cellGrid[MAX_ROWS][MAX_COLS], int numRows, int numCols)
{
    int cellGridCopy[MAX_ROWS][MAX_COLS];
    
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
             cellGridCopy[i][j] = cellGrid[i][j];
        }
    }

    // Takes advantage of the fact that we are logically working with only 0s and 1s in the algorithm
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            int neighborCount = 0; // Reset the neighbor count
            
            for (int rowOffset = -1; rowOffset <= 1; rowOffset++) // For the row above, same row and below
            {
                for(int colOffset = -1; colOffset <= 1; colOffset++) // For column to the left, the same column and to the right
                { 
                    neighborCount += cellGridCopy[i + rowOffset][j + colOffset]; 
                }
            }
            neighborCount -= cellGridCopy[i][j];
            if (cellGridCopy[i][j] == 1) // If the cell is currently alive
            {                
                if(neighborCount < 2 || neighborCount > 3) // If neighborCount is is anything but 2 or 3
                {
                    cellGrid[i][j] = 0;    
                }
            }   
            else // the cell is currently empty
            {
                if(neighborCount == 3) // Exactly 3 by an empty cell, then give birth by filling cell with a 1
                {
                    cellGrid[i][j] = 1;
                }
            } 
        }
    }
} //End UpdateLifeGrid() 


/**************************************************************************************************
 *Name:    DisplayProgramFooter(int[][], int)
 *Purpose: Draws the program footer that contains the step, live cell and generation counts, 
 *         as well as the current grid size that was read in by LoadFile(). 
 *Called From: main()  
 **************************************************************************************************/
void DisplayProgramFooter(int cellGrid[MAX_ROWS][MAX_COLS], int stepCount)
{
    printf("\n\n|***********************************\n");        
    printf("|******* GAME OF LIFE STATS ********\n");
    printf("|***********************************\n");
    printf("|\n");        
    printf("| Current Number of Live Cells: %d\n", CountLiveCells(cellGrid, numRows, numCols));           
    printf("| Number of Generations: %d\n", stepCount);
    printf("| Grid Size: %d rows by %d columns.\n", numRows, numCols);
    printf("| Enter to continue, or 'q' to quit: ");
}

/**************************************************************************************************/


int main(int argc, char** argv)
{
    char exit;
    int numSteps;
    int cellGrid[MAX_ROWS][MAX_COLS];   
 
    // INPUT
    LoadFile(argv[1], cellGrid);
    
    // PROCESSING
    while(exit != 'q') 
    {  
        system("clear");        
        
        // OUTPUT & POST-PROCESSING
        DisplayLifeGrid(cellGrid, numRows, numCols);
        DisplayProgramFooter(cellGrid, numSteps);        
        UpdateLifeGrid(cellGrid, numRows, numCols);
        exit = getchar();
        numSteps++;
        
        // a small pause to allow terminal windows to display correctly          
        usleep(50000);          
    }
    return 0;
}




