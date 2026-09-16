#include <iostream> //Allows input and output
#include <fstream> //Allows to read to and write from files
#include <cmath> //Needed for square root function
#include <iomanip> //Allows formatting of output
#include <string> //Allows use of string variables and functions

void PrintFile() { //Test function to check if the text file was being read correctly
    std::fstream infile("output-set9.txt"); 
    //Textfile saved in github to allow to be read easily when code is used by others
    std::string line; //Assigning a string variable to use to store and output each line
    while (std::getline(infile,line)) { 
        //While loop which loops through and stops when there are no more lines in the text file
        //Assigns each line to the variable to be printed
        std::cout << line << std::endl; //Prints each line of the text file from the variable
    }
    infile.close(); //Closes the text file
}

int main() {
    PrintFile();
    return 0;
}