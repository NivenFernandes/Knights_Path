
/** **********************************************************************
* @file
* @brief lay the game
*************************************************************************/


#include "knights_Path.h";

/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  Recursively solves the knights path to find the first solution where
 * the knight steps on every square on the board atleast once. recuservely
 * try all positions , all permutations till you find a solution.
 * found will be false if we dont find a solution
 *
 *  @param[in] board - dynamic array of int
 *  @param[in] size - the integer value of the size of the array
 *  @param[in] row - the integer containing the starting row
 *  @param[in] col - the integer containing the starting column
 *  @param[in] count - the int next step of the knight
 *  @param[in] found - a bool value that is true if the solution is found
 *                     false otherwise
 *
 *
 *  @par Example
 *  @verbatim

    int size=8, row=5, col=3, count=0;
    bool found=false;

    soln(board, size,  row,  col,  count,  found);
    found will be true if the solution is found , false otherwise

    @endverbatim
 ************************************************************************/

void soln(int**& board, int size, int row, int col, int count, bool& found)
{

    //base case 
    if (count >= size * size + 1 && !found)
    {
        //count >= size * size + 1 , solution found
        found = true;
        return;
    }

    //if solution is not ound, find one
    else if (!found)
    {
        //if the next step is safe
        if (isSafe(board, row, col, size))
        {
            //go to that step
            board[row][col] = count;
            //recuservely try all positions , all permutations till you
            //find a solution
            soln(board, size, row - 2, col + 1, count + 1, found);
            soln(board, size, row - 1, col + 2, count + 1, found);
            soln(board, size, row + 1, col + 2, count + 1, found);
            soln(board, size, row + 2, col + 1, count + 1, found);


            soln(board, size, row + 2, col - 1, count + 1, found);
            soln(board, size, row + 1, col - 2, count + 1, found);
            soln(board, size, row - 1, col - 2, count + 1, found);
            soln(board, size, row - 2, col - 1, count + 1, found);
            //no solution was found, set current position to 0 and go back
            if (!found)
            {
                board[row][col] = 0;
            }

        }

        //if not safe, exit out of the the current recursieve function
        //call and go to the previous one
        else
        {
            return;
        }
    }
}




