#include <iostream> //Allows input and output
#include <fstream> //Allows to read to and write from files
#include <cmath> //Needed for square root function
#include <iomanip> //Allows formatting of output
#include <string> //Allows use of string variables and functions

void PrintFile() { //Test function to check if the text file was being read correctly
    std::fstream infile("output-Set0.txt"); 
    //Textfile saved in github to allow to be read easily when code is used by others
    std::string line; //Assigning a string variable to use to store and output each line
    while (std::getline(infile,line)) { 
        //While loop which loops through and stops when there are no more lines in the text file
        //Assigns each line to the variable to be printed
        std::cout << line << std::endl; //Prints each line of the text file from the variable
    }
    infile.close(); //Closes the text file
}

void TotalMomentum() { //Void used to bypass the need for a return value
    std::fstream infile("output-Set0.txt"); //Opening the text file

    if (!infile.is_open()) { //If statement to check if the text file is open
    std::cout << "Could not open file!" << std::endl; //If the text fiole is not open, outputs error message
    return; //Exits the function if text file could not be opened
}
    std::cout << std::setw(15) << "Particle Number" //Headings for output in columns with a set width (setw)
            << std::setw(25) << "Particle Code "
            << std::setw(25) << "Total Momentum "
            << std::endl;
    std::cout << std::string(65, '-') << std::endl; //Line to seperete headings from output

    std::string line, ParticleCode; 
    //Creating string variables, one for the particle code and one for the lines of the text file

    double x, y, z; //Variables for each dimension of the momentum of the particle

    int lineno = 0; //Line number variable, starting at 0 for the heading and allowing us to give the patricles numbers
    while (std::getline(infile, line)) { //Loops through the text file line by line until there are no more lines
        //Assigns each line to the previously declared string variable to be processed
    int a=0, b=0; //Variables used to see where in the line we are and extract the data
        for(int i = 0; i < line.length(); i++) { //For loop through the line to extract data
            if (line[i]==' ') { //When a space is reached (seperation between data points)
                if (b == 0) { //If it is the first space
                    x = stod(line.substr(a, i - a)); 
                    //Assign the data point, from a (place of previous space, currently 0) to place before current space to x
                }
                else if (b == 1) { //If it is the second space
                    y = stod(line.substr(a, i - a)); //Assign the data point, from a to place before current space to y
                }
                else if (b == 2) { //If it is the third space
                    z = stod(line.substr(a, i - a)); //Assign the data point, from a to place before current space to z
                    ParticleCode = line.substr(i + 1); //Assign any data after the last space to the ParticleCode  
                }
                b++; //Increment b (which space we are currently at)
                a = i + 1;
            }
        }

        if (lineno > 0) { //Only output the lines after the heading
            double Totalp = sqrt(x*x + y*y + z*z); //Caculate total momentum
            //Neat output
            std::cout << std::setw(15) << lineno
              << std::setw(25) << ParticleCode //setw to print information in columns of a set width
              << std::setw(25) << Totalp
              << std::endl; //Information of each particle on a new line
        }

        lineno++; //Increment the line number/particle number
    }
    
    infile.close(); //Close the file
}

int main() { //Main function to call other functions, type int required for main function
    //PrintFile(); //Commented out since it was just a test, but code left in so that it can be tested in future
    TotalMomentum();
    return 0; //Return needed for type int
}