#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

void PrintFile() {
    std::fstream infile("output-Set0.txt");
    std::string line;
    while (std::getline(infile,line)) {
        std::cout << line << std::endl;
    }
    infile.close();
}

void TotalMomentum() {
    std::fstream infile("output-Set0.txt");
    std::string line;
    double x, y, z;
    std::string ParticleCode;
    int lineno = 0;
    while (std::getline(infile, line)) {
    int a=0, b=0;
        for(int i=0; i=line.length(), i++;) {
            if (line[i]==' ') {
                if (b=0) {
                    x = stod(line.substr(a, i));
                    b++;
                }
                else if (b=1) {
                    y = stod(line.substr(a, i));
                    b++;
                }
                else if (b=2) {
                    z = stod(line.substr(a, i));
                    b++;   
                }
                else {
                    ParticleCode = line.substr(a, i);
                }
            }         //Stopped work here. Output total momentum, particle no and code
        }
        if (lineno > 0) {
            double Totalp = sqrt(x*x+y*y+z*z); 
            std::cout << "Particle Number: " + std::to_string(lineno) << std::endl; 
            std::cout << ", Particle Code: " + ParticleCode << std::endl;
            std::cout << ", Total Momentum of particle: " + std::to_string(Totalp) << std::endl;
            std::cout << " " << std::endl;
        }
        lineno++;
    }
}

int main() {
    //PrintFile();
    TotalMomentum();
    return 0;
}