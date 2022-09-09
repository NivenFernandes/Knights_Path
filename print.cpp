
/** **********************************************************************
* @file
* @brief print
*************************************************************************/


#include "knights_Path.h";

/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This function outputs the solution to the screen
 *
 *  @param[in] board - dynamic array of int
 *  @param[in] size - the integer value of the size of the array
 *  @param[in] pos - an integer array of the starting location
 *  @param[in] count - the nth tour
 *
 *
 *  @par Example
 *  @verbatim

      // create a 2d array of int board
    int  size=8;

    print(board, size)

    @endverbatim
 ************************************************************************/
void print(int** board, int size, int pos[], int count)
{
    int i, j;
    cout << endl;
    cout << "Tour # " << count << endl;


    //output the size and the starting position
    cout << "        " << size << "x" << size << " starting at ("
        << pos[0] << " , "
        << pos[1] << ")" << endl << endl;


    //go through the array
    for (i = 0; i < size + 4; i++)
    {
        for (j = 0; j < size + 4; j++)
        {

            //if the element at i and j is not -1, output it
            if (board[i][j] != -1)
            {
                if (j == 2)
                {
                    cout << "        ";
                }
                cout << setw(5) << left << board[i][j];

                //newline when j is size+5
                if (j == size + 1)
                {
                    cout << endl;
                }
            }

        }

    }

    cout << endl << endl;

}


