#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <iomanip>
using namespace std;

int NoEvents = 0;

void CountHeaders() {
    std::fstream infile("output-Set9.txt");
    std::string line;

    if (!infile.is_open()) {
    cout << "Could not open file!" << endl;
    return;
}

    while (std::getline(infile,line)) {
        if (line.length() < 10) {
            NoEvents ++;
        }
    }
}

void ValuesEvents() {

    fstream infile("output-Set9.txt");

    if (!infile.is_open()) {
        std::cout << "Could not open file!" << std::endl;
        return;
    }

    std::cout << "File opened successfully!" << std::endl;

    string line;

    double x, y, z;
    int ParticleCode;
    int EventNumber = 0;

    // Stores the statistics for one event + particle code
    struct Stats {
        int count = 0;
        double mean = 0;
        double M2 = 0;
    };

    // Key = (EventNumber, ParticleCode)
    // Value = statistics for that combination
    std::map<std::pair<int, int>, Stats> statistics;


    while (std::getline(infile, line)) {

        if (line.length() >= 15) {

            stringstream ss(line);

            ss >> x >> y >> z >> ParticleCode;

            double momentum = sqrt(x * x + y * y + z * z);


            // Only keep your 12 particle codes
            switch (ParticleCode) {

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
                    break;

                default:
                    continue;
            }


            // Identify this particular event + particle type
            std::pair<int, int> key = {EventNumber, ParticleCode};

            Stats& stats = statistics[key];


            // Update statistics using Welford's algorithm
            stats.count++;

            double difference = momentum - stats.mean;

            stats.mean += difference / stats.count;

            double difference2 = momentum - stats.mean;

            stats.M2 += difference * difference2;
        }

        else {

            // Short line = new event
            EventNumber++;
        }
    }


    std::cout << "Finished reading file." << std::endl;

    std::cout << "Number of events: "
              << EventNumber << std::endl;

    std::cout << "Number of event/particle combinations: "
              << statistics.size() << std::endl;


    // Print results
    std::cout << std::endl;

std::cout << std::setw(12) << "Event"
          << std::setw(16) << "Particle Code"
          << std::setw(10) << "Count"
          << std::setw(20) << "Average Momentum"
          << std::setw(20) << "Statisticle Uncertainty"
          << std::endl;

std::cout << std::string(68, '-') << std::endl;

    for (const auto& item : statistics) {

        int event = item.first.first;
        int code = item.first.second;

        const Stats& stats = item.second;

        double statisticalUncertainty = 0;

        if (stats.count > 1) {
            double standardDeviation =
                sqrt(stats.M2 / stats.count);

            statisticalUncertainty =
                standardDeviation / sqrt(stats.count);
        }

        std::cout << std::setw(12) << event
                << std::setw(16) << code
                << std::setw(10) << stats.count
                << std::setw(20) << stats.mean
                << std::setw(20) << statisticalUncertainty
                << std::endl;
    }   
}


int main() {
    ValuesEvents();
    return 0;
}