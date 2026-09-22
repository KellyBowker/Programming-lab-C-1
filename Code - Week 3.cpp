#include <iostream> //Used to allow input/output
#include <fstream> //Reading the text file
#include <sstream> //Allows stringstream (Reading individual values from a line)
#include <iomanip> //Used for output formatting: setw (set width) 
#include <map> //Allows storage of paticle codes and number of those partices in pairs
#include <vector> //Storing lists of particle counts (vector is a list)
#include <cmath> //Mathematical functions (sqrt() in this case)

using namespace std; 

void ValuesEvents() {

    fstream infile("output-Set9.txt"); //Connects text file to code

    if (!infile.is_open()) { //Test to see if the file is open
        cout << "Could not open file!" << endl; //If the file is not open, error message
        return; //Exits function if file cannot be opened
    }

    cout << "File opened successfully!" << endl; //If file opens (not in else since function would be exited if not)

    string line; //String storage for each line of the text file
    int ParticleCode; //Stores the particle code (type of particle)
    int EventNumber = 0; //Count for the number of events, seperated by a header (500,000) to prevent hard coding

    vector<int> particleCodes = { //All the particle codes we are processing stored for easy access
        211, -211,
        321, -321,
        2212, -2212,
        3122, -3122,
        3312, -3312,
        3334, -3334
    };

    map<pair<int, int>, int> particleCounts; //Stores the number of particles per event and particle code


    while (getline(infile, line)) { 
        //Reads the file line by line, storing each line in the string (line) and stopping at the end of the file

        stringstream ss(line); //Seperates the line so that the values can be accessed seperately

        double x, y, z; //Variables for each component of the total momentum

        if (ss >> x >> y >> z >> ParticleCode) { 
            //Tries to seperates the line into variables using string stream
            //Works if the line has sufficient values i.e. not a header

            switch (ParticleCode) { //Checks if the particle is of a typr that we want to process

                case 211:
                case -211:
                case 321:
                case -321:
                case 2212:
                case -2212:
                case 3122:
                case -3122:
                case 3312:
                case -3312:
                case 3334:
                case -3334:

                    particleCounts[{EventNumber, ParticleCode}]++; //Adds 1 to the type of particle in this event
                    break;

                default: //If it is not one of the particles we want, just exit the case statement
                    break;
            }
        }
        else {
            EventNumber++; //Increments the event number if the line cannot be seperated i.e. is a header
        }
    }

    int numberOfEvents = EventNumber; //Total number of events using the last value of the event number

    cout << "Finished reading file." << endl; 
    //Check to see when the file has been read to confirm to code is running and not getting stuck
    cout << "Number of events: " << numberOfEvents << endl; //Expected: 50 000
    //Outputs the total number of events, helps to see that the file is read correctly


    cout << endl; //Skip a line to begin printing output

    cout << setw(16) << "Particle Code" 
         << setw(20) << "Average / Event"
         << setw(25) << "Stat. Uncertainty"
         << endl;
         //Prints headers in columns

    cout << string(61, '-') << endl; //Creates a seperation between headers and output values

    for (int code : particleCodes) { //Runs through every particle code

        double total = 0; 
        double totalSquared = 0;
        //Initialises the total number of particles it's square

        for (int event = 0; event < numberOfEvents; event++) { //Runs through each event

            int count = particleCounts[{event, code}]; //Stores the number of particles per type and event in count

            total += count; //Adds the number of particles to the total
            totalSquared += count * count;
        }

        double average = total / numberOfEvents; //Calculates the average number of particles per event

        double variance = //Calculates the variance of number of particles per event
            (totalSquared / numberOfEvents)
            - (average * average);

        if (variance < 0) { //Prevents potential negatives caused by rounding in variance by making them zero
            variance = 0;
        }

        double standardDeviation = sqrt(variance); //Calculates the standard deviation using the variance value

        double statisticalUncertainty = // Statistical uncertainty of the average using standard deviation
            standardDeviation / sqrt(numberOfEvents);


        cout << setw(16) << code //Prints the output under the headings in columns
        //Each row is on particle code
             << setw(20) << fixed << setprecision(4) << average
             << setw(25) << statisticalUncertainty
             << endl;
    }
}


int main() { //Tyoe int required for main function

    ValuesEvents(); //Calls function

    return 0; //Satisfies return required by type int of main
}