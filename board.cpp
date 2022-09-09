

/** **********************************************************************
* @file
* @brief handels the board
*************************************************************************/


#include "knights_Path.h";



/** *********************************************************************
 * @author Niven Fernandes
 *
 * @par Description:
 * This function gets the board ready. It calls createArray and initializes
 * the board using initializeBoard function
 *
 * @param[in, out] board -2D  dynamic array of int
 * @param[in] size - the number of rows and col
 *
 * @returns a bool, true on success
 *
 * @par Example:
   @verbatim

   pixel** board;
   int size=7;

   bool success=createBoard( board , size);
   //success will be true
   //board will be a dynamic 2D array which is initialized

   @endverbatim

 ***********************************************************************/
bool createBoard(int**& board, int size)
{
    //create the board
    board = createArray(size);
    //initialize it
    initializeBoard(board, size);
    return true;
}


/** *********************************************************************
 * @author Niven Fernandes
 *
 * @par Description:
 * This function creates a 2D dynamic array
 * it checks for memeory elocation and if unable to acllocate memory, it
 * outputs a message clears the allocated memory and exits with a code 0.
 *
 *  @param[in] size - the size of the board to be created
 *
 * @returns a pointer to a 2D array
 *
 * @par Example:
   @verbatim

   pixel** board;
   int size=7;

   board=createArray(size);
   //it will return a 2D array

   @endverbatim

 ***********************************************************************/
int** createArray(int size)
{
    int i;
    int** ptr = nullptr;

    //create an array
    ptr = new(nothrow) int* [size + 4];
    if (ptr == nullptr)
    {
        // unable to allocate memory
        delete[] ptr;
        //erroe message exit
        cout << "Unable to allocate memory" << endl;
        exit(0);
    }

    for (i = 0; i < size + 4; i++)
    {
        ptr[i] = new(nothrow) int[size + 4];
        if (ptr[i] == nullptr)
        {
            //unable to allocate memory - error message, clear array exit
            cout << "Unable to allocate memory" << endl;
            //delete the already assigned array
            deleteArrays(ptr, i - 4);
            //exit
            exit(0);
        }
    }

    return ptr;
}


/** *********************************************************************
 * @author Niven Fernandes
 *
 * @par Description:
 * This function deletes a 2D dynamic array
 *
 *  @param[in] board -2D  dynamic array of int
 * @param[in] size - the number of rows and columns in the array
 *
 * @returns a boolean value, true if distroy
 *
 * @par Example:
   @verbatim

   int size=8;

   pixel** board = createArrays(size);

    deleteArrays(board, size); //delete the board

   @endverbatim

 ***********************************************************************/
bool deleteArrays(int**& board, int size)
{
    int i;

    //delete all the contents of the row
    for (i = 0; i < size + 4; i++)
    {
        delete[] board[i];
    }
    //delete the rows
    delete[] board;
    //sucess
    return true;
}




/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  initializes the board to zero and pad the boders with -1
 *
 *  @param[in, out] board -2D  dynamic array of int
 *  @param[in] size - the integer value of the size of the array
 *
 *
 *  @par Example
 *  @verbatim

   // create a 2d array of int - board
    int size=8;

    initializeBoard(board,  size)
    //will intialize the board to 0 and include padding with -1 at
    the sides

    @endverbatim
 ************************************************************************/
void initializeBoard(int**& board, int size)
{
    int i, j;

    //set every position to zero
    for (i = 0; i < size + 4; i++)
    {
        for (j = 0; j < size + 4; j++)
        {
            board[i][j] = 0;
        }
    }

    //pad the sides of the array with -1
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < size + 4; j++)
        {
            board[i][j] = -1;
            board[size + 3 - i][j] = -1;
            board[j][i] = -1;
            board[j][size + 3 - i] = -1;
        }
    }
}




/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  THis function checks if the knight step is valid
 *
 *  @param[in] board - dynamic array of int
 *  @param[in] row - the integer containing the starting row
 *  @param[in] col - the integer containing the starting column
 *  @param[in] size - the integer value of the size of the array
 *
 *  @returns a boolean value, true on sucess, false otherwise
 *
 *  @par Example
 *  @verbatim

      // use a 2d array of int - board
    int row=7, col=7, size=8;
    bool safe;

    safe = isSafe(board,  row, col, size);

    //safe true
    @endverbatim
 ************************************************************************/
bool isSafe(int** board, int row, int col, int size)
{
    //if the element at row and col is not 0 then it is not safe
    if (board[row][col] != 0)
    {
        //not safe
        return false;
    }
    //safe
    return true;
}
