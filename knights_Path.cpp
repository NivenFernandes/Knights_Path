/** **********************************************************************
* @file
* @brief Knights Tour program
*************************************************************************/


#include "knights_Path.h";




/** **********************************************************************
* @mainpage The Knight's Tour
*
* @section  Information
*
* @author Niven Fernandes
*
** @par Professor:
*         Professor Roger Schrader
*
* @section program_section Program Information
*
* @details
* This program is a sequence of Knight's moves on a chess board
* such that the knight visits every block on the chess board once.
* The first position will be labeled 1 the second will be labeled
* 2 and so on. The final step will be the square of the size of
* the chess board(if size is 8, the final step will by 64).
* It outputs a message if there is no solution.
*
* The progam can be started with command line arguments or with a user
* input. In case of command line arguments we have to specify the name
* of the input file. The file can have many tours.the solutions will
* be stored in the "solutions.tours".
* In case of user input, the user has three options
*
* 1, Change the size of the board
*
* 2, Change the coordinates
*
* 3, start solving
*
* The user can use the first 2 options to change the size and starting
* location. once the user chooses option 3, the program starts solving
* the knights path.
*
* @section compile_section Compiling and Usage
*
* @par Compiling Instructions:
*      none
*
* @par Usage:
  @verbatim
  C:\> thpe3.exe
  C:\> thpe3.exe tourfile

     tourfile: the name of the file containing the tours
  @endverbatim
*
* @section todo_bugs_modification_section Todo, Bugs, and Modifications
*
* @par Modifications and Development Timeline:
*
* Visit gitlab for the development timeline. Click on the link provided
* to access: <a href =
* "https://gitlab.cse.sdsmt.edu/101095650/csc215s22programs/-/commits/master">
* Click Here</a>
*
*************************************************************************/




/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This is the main function. It checks the command line argumnets and runs
 *  the appropriate option accourding to the command line argument. Calls the
 * appropriate function to find the tours
 *
 *  @param[in] argc an integer, the number of command line arguments

 *  @param[in] argv a 2D array of the command line argumnents
 *
 *  @returns an integer. 0 if it suceeded any other number for failure
 *
 *  @par Example
 *  @verbatim

    // pass in command line arguments according to the usage statements

    @endverbatim
 ************************************************************************/
int main(int argc, char** argv)
{
    ifstream fin;

    //check args
    if (!checkArgs(argc, argv))
    {
        return 0;
    }
    //open file

    if (argc == 2)
    {

        //open file
        if (!openFile(fin, string(argv[1])))
        {
            return 0;
        }
    }
    //handle calls
    handleCalls(argc, fin);

    if (argc == 2)
    {
        //if file was opened, clse it
        fin.close();
    }
    return 0;
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 * Checks the command line arguments
 *
 *  @param[in] argc number of command line arguments
 *  @param[in] argv 2D char array of the command line arguments
 *
 *  @returns a boolean value, true if valid, false otherwise
 *
 *  @par Example
 *  @verbatim

     if(!checkArgs(argc, argv)
     {
         return 0;
     }

    @endverbatim
 ************************************************************************/
bool checkArgs(int argc, char** argv)
{
    //if args are neiter 1 or 2 return false
    if (argc != 1 && argc != 2)
    {

        //usage statement
        cout << "Usage: C:\\> thpe3.exe" << endl;
        cout << "Usage: C:\\> thpe3.exe tourfile"
            << endl;

        //return false
        return false;

    }
    //return true
    return true;
}




/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  gets the valid input from the user. Has size as 8x8 and starting position
 *  as 7x7 by default. The user can change size, and starting positions
 *  of the board
 *
 *  @param[in,out] position - array storing the starting position
 *  @param[in, out] size - the size of the board
 *
 *  @returns a boolean value, true on sucess
 *
 *  @par Example
 *  @verbatim

     int position[2]={7,7};
     int size=8;
     userInput(position, size);
     //it will get the valid input from the user

    @endverbatim
 ************************************************************************/
bool userInput(int position[], int& size)
{
    int option = 4, row, tempSize, col;
    bool valid = true;

    //continue till the option is not 3
    while (option != 3)
    {
        //output menue
        cout << " 1) Change Board Size from " << size << "x" << size << endl;
        cout << " 2) Change starting location from [" << position[0] << ","
            << position[1] << "]" << endl;
        cout << " 3) Exit and Solve Tour" << endl;
        cout << " Enter Choice: ";

        //getoption
        cin >> option;
        if (option == 2)
        {
            //output row col statement
            cout << " Enter Starting Coordinates [ row , col ]: ";
            //get row and col

            cin >> row;
            cin >> col;

            if (row < size && col < size)
            {
                //if valid store it and valid is true
                position[0] = row;
                position[1] = col;
                valid = true;
            }

            else
            {
                //not valid statement, valid is false
               //cout<< endl<<"Please enter a valid starting position"<< endl;
                valid = false;
            }
        }

        else if (option == 1)
        {
            //option is 1, output statement
            cout << " Enter the size of the NxN Board (>3): ";
            //get size
            cin >> tempSize;


            //check if valid
            if (tempSize <= 3 || tempSize <= position[0] ||
                tempSize <= position[1])
            {
                //  cout <<endl<< "Please enter a valid size" << endl;
                  //valid is false
                valid = false;
            }

            else
            {
                //if valid store the input in the size
                size = tempSize;
            }

        }
        cout << endl;
    }
    //got valid data, return true
    return true;
}





/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 * This function handles all the calls. In case of readling from a file
 * it reads the data and then calls the solve function to solve it.
 * it outputs the data to the file. in case of user input, it calls
 * appropriate functions to solve it
 *
 *
 *  @param[in] argc - an integer value of the number of command line arguments
 *  @param[in, out] fin -  ifstream the input file stream
 *
 *  @returns a boolean value, true on sucess, false otherwise
 *
 *  @par Example
 *  @verbatim

    ifstream fin;
    //argc wil depend on the number of command line argumnts
    handleCalls(argc, fin);

    // if argc is 2 it will read from a file, else it will get the input
    from the user

    @endverbatim
 ************************************************************************/
void handleCalls(int argc, ifstream& fin)
{
    int position[2] = { 7,7 };
    ofstream fout;
    int size = 8;
    int** board;
    int count = 1;
    int tour = 1;
    bool found = false;
    //two arguments
    if (argc == 2)
    {
        //open output and while we get data from the file, solve it 
        openOutput(fout);
        while (readFile(fin, position, size))
        {
            //create a board of the size, set count to 1 and solve
            createBoard(board, size);

            count = 1;
            soln(board, size, position[0] + 2, position[1] + 2, count, found);

            //not found -  output no solutions
            if (!found)
            {
                fout << "Tour # " << tour << endl;
                fout << "        " << size << "x" << size << " starting at ("
                    << position[0] << " , "
                    << position[1] << ")" << endl << endl;
                fout << "        No solutions for this case" << endl << endl << endl;
            }
            else
            {
                //found, output the board to the file
                output(fout, board, size, tour, position);
            }

            //increment tour, increment tour and delete array
            tour = tour + 1;
            deleteArrays(board, size);

            found = false;
        }
        //close file
        fout.close();
    }
    if (argc == 1)
    {
        //get user input and create board
        userInput(position, size);
        createBoard(board, size);

        //solve, if found - output board, if not found - output no solution
        soln(board, size, position[0] + 2, position[1] + 2, count, found);
        if (!found)
        {
            cout << "No solutions for this case" << endl;
        }
        else
        {
            print(board, size, position, tour);
        }

        //delete board
        deleteArrays(board, size);
    }
}





