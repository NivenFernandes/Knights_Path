/** **********************************************************************
* @file
* @brief Knights Tout header file
*************************************************************************/


#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;



bool checkArgs(int argc, char** argv);
bool openFile(ifstream& fin, string str);
bool userInput(int array[], int& size);
bool readFile(ifstream& fin, int array[], int& size);
void handleCalls(int argc, ifstream& fin);
bool deleteArrays(int**& board, int size);
int** createArray(int size);
bool createBoard(int**& board, int size);
void initializeBoard(int**& board, int size);
void print(int** board, int size, int pos[], int count);
bool isSafe(int** board, int row, int col, int size);
bool output(ofstream& fout, int** board, int size, int count, int pos[]);
bool openOutput(ofstream& fout);
void soln(int**& board, int  size, int row, int col, int count, bool& found);

