
/** **********************************************************************
* @file
* @brief handels input and output
*************************************************************************/


#include "knights_Path.h";



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  open input file. Check for sucess
 *
 *  @param[in,out] fin ifstream
 *  @param[in] str the name of the input file
 *
 *  @returns a boolean value, true on sucess, false otherwise
 *
 *  @par Example
 *  @verbatim

    ifstream fin;
    string str="Knights.txt"
    bool open;

    open = openFile(fin, str);
    //open is true
    @endverbatim
 ************************************************************************/
bool openFile(ifstream& fin, string str)
{
    //opening the file
    fin.open(str);
    //checking if the file is not opened


    if (!fin.is_open())
    {
        //not open
        cout << "Unable to open the input file: " << str << endl;
        //false


        return false;
    }


    return true;
}



/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This function outputs the solution to the file. We append the file if
 * there is any  solution in the file already.
 *
 *  @param[in] fout ofstream
 *  @param[in] board - dynamic array of int
 *  @param[in] size - the integer value of the size of the array
 *  @param[in] count - the nth tour
 *  @param[in] pos - an integer array containing the starting positions
 *
 *  @returns a boolean value, true on sucess
 *
 *  @par Example
 *  @verbatim

    ofstream fout;
    bool sucess;
    //create a 2d array o fint - board
    int size=8, count=1;
    int pos[2]={3,4}
    sucess = output(fout,  board, size, count,  pos)

    //sucess is true
    @endverbatim
 ************************************************************************/
bool output(ofstream& fout, int** board, int size, int count, int pos[])
{
    int i, j;

    //output the number of solution
    fout << "Tour # " << count << endl;


    //output the size and the starting position
    fout << "        " << size << "x" << size << " starting at ("
        << pos[0] << " , "
        << pos[1] << ")" << endl << endl;


    //go through every element in the array
    for (i = 0; i < size + 4; i++)
    {
        for (j = 0; j < size + 4; j++)
        {
            //if the element at i and j is not -1 then output it 
            if (board[i][j] != -1)
            {
                if (j == 2)
                {
                    fout << "        ";
                }
                //setwith
                fout << setw(5) << left << board[i][j];
                //output a newline
                if (j == size + 1)
                {
                    fout << endl;
                }
            }
        }
    }

    fout << endl << endl;
    //sucess
    return true;
}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  This function opens the output file to append it
 *
 *  @param[in,out] fout ofstream
 *
 *  @returns a boolean value, true on sucess, false otherwise
 *
 *  @par Example
 *  @verbatim

    ofstream fout;
    bool open;

    open = openOutput(fout);
    //open is true, it will open "Solutions.tours"

    fout.colse();

    @endverbatim
 ************************************************************************/
bool openOutput(ofstream& fout)
{
    //open the output file to append
    fout.open("Solutions.tours", ios::app);

    //if not open output an error meaage and exit
    if (!fout.is_open())
    {
        cout << "Unable to open output file: Solutions.tours" << endl;
        exit(0);
    }
    //opened successfully
    return true;
}


/** **********************************************************************
 *  @author Niven Fernandes
 *
 *  @par Description
 *  gets the valid input from the file.
 *
 *  @param[in,out] fin ifstream - the file to read data from
 *  @param[in,out] position - array storing the starting position
 *  @param[in, out] size - the size of the board
 *
 *  @returns a boolean value, true on sucess, false otherwise
 *
 *  @par Example
 *  @verbatim

     int position[2]={7,7};
     int size=8;
     ifstream fin;
     fin.open("file.txt");
     readFile(ifstream& fin, int position[], int &size)
     //it will get the input from the file

    @endverbatim
 ************************************************************************/
bool readFile(ifstream& fin, int position[], int& size)
{
    //read size
    if (fin >> size)
    {
        //read row
        if (fin >> position[0])
        {
            //read column
            if (fin >> position[1])
            {
                return true;
            }
        }
    }
    return false;
}