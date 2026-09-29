# Programming-lab-C-1

## Student Information

Kelly Bowker
i6434342

## Title

Simulation of Expected Particle Production Using a Model Commonly Used in Particle Physics

## Questions to be answered

- What are the average counts of each particle species and their statistical uncertainties? 
- Is there any asymmetry between the particle and the anti-particle?
- Is there any asymmetry as a function of their momentum?

## Installation and Usage Instructions

### Requirements

The program requires:
- A C++ compiler supporting **C++11 or later**
- The standard C++ libraries
- The input data files:
  - output-Set1-restored.txt
  - output-Set2-restored.txt
  - up to output-Set10-restored.txt

No additional external libraries are required.

### Installation

1. Download or clone the project repository.
2. Make sure the C++ source code and the input files are in the same directory.
3. Open a terminal in the project directory.
4. Compile the program using the built-in compiler

### Usage

After compiling, run the program.
The program reads the particle data from the text files. It identifies the specified particle IDs and calculates the average number of particles produced per event and the corresponding statistical uncertainty.

The particle IDs analysed are:

* 211 and -211
* 321 and -321
* 2212 and -2212
* 3122 and -3122
* 3312 and -3312
* 3334 and -3334

The program then outputs the average number of particles per event and the statistical uncertainty for each particle ID.

### Expected Input

The input files should contain the particle-event data in the expected format, with the event information and particle data provided as in the supplied dataset.

The input file must be available in the directory from which the program is executed. If the file is located elsewhere, the file path in the source code must be changed accordingly.

##Results and discussion

QUESTION 1: What are the average counts of each particle species and their statistical uncertainties? 

   Particle Code     Average / Event        Stat. Uncertainty
-------------------------------------------------------------
             211             18.4253                   0.0080
            -211             18.3955                   0.0080
             321              2.3174                   0.0010
            -321              2.3122                   0.0010
            2212              1.1157                   0.0007
           -2212              1.0937                   0.0007
            3122              0.2555                   0.0003
           -3122              0.2509                   0.0002
            3312              0.0364                   0.0001
           -3312              0.0360                   0.0001
            3334              0.0011                   0.0000
           -3334              0.0011                   0.0000

QUESTION 2: Is there any asymmetry between the particle and the anti-particle?

To investigate possible particle–antiparticle asymmetries, each particle ID was compared with its corresponding antiparticle. The difference between the two averages was compared with the combined statistical uncertainty.
The combined uncertainty of the difference is calculated using: √(σ1^2 + σ2^2).
A difference that is close to zero compared with its uncertainty is consistent with no asymmetry. Conversely, a difference that is several standard deviations away from zero provides evidence for an asymmetry in the measured production rates.

###211 and -211
The averages are: 18.4253 ± 0.0080 and 18.3955 ± 0.0080
The difference is: 18.4253 - 18.3955 = 0.0298
The combined uncertainty is: √(0.0080^2 + 0.0080^2) = 0.0113
The difference is therefore 2.6 standard deviations away from zero. This shows an asymmetry between 211 and -211 in the measured data. The positive difference shows that 211 has the higher measured average production rate.

###321 and -321
The averages are: 2.3174 ± 0.0010 and 2.3122 ± 0.0010
The difference is: 2.3174 - 2.3122 = 0.0052
The combined uncertainty is: √(0.0010^2 + 0.0010^2)=0.0014
The difference is therefore about 3.7 standard deviations away from zero. This provides evidence for an asymmetry between 321 and -321 in the measured data. The positive difference shows that 321 has the higher measured average production rate.

###2212 and -2212
The averages are: 1.1157 ± 0.0007 and 1.0937 ± 0.0007
The difference is: 1.1157 - 1.0937 = 0.0220
The combined uncertainty is: √(0.0007^2 + 0.0007^2) = 0.0010
The difference is therefore 22 standard deviations away from zero. This provides strong evidence for an asymmetry between 2212 and -2212 in the measured data. The positive difference shows that 2212 has the higher measured average production rate.

###3122 and -3122
The averages are: 0.2555 ± 0.0003 and 0.2509 ± 0.0002
The difference is: 0.2555 - 0.2509 = 0.0046
The combined uncertainty is: √(0.0003^2 + 0.0002^2) = 0.00036
The difference is therefore 12.8 standard deviations away from zero. This provides strong evidence for an asymmetry between 3122 and -3122 in the measured data. The positive difference shows that 3122 has the higher measured average production rate.

###3312 and -3312
The averages are: 0.0364 ± 0.0001 and 0.0360 ± 0.0001
The difference is: 0.0364 - 0.0360 = 0.0004.
The combined uncertainty is: √(0.0001^2 + 0.0001^2) = 0.00014.
The difference is therefore 2.8 standard deviations away from zero. This provides evidence for an asymmetry between 3312 and -3312 in the measured data. The positive difference shows that 3312 has the higher measured average production rate.

###3334 and -3334
The averages are: 0.0011 ± 0.0000 and 0.0011 ± 0.0000.
The difference is: 0.0011 - 0.0011 = 0.
Since the difference is exactly zero, the result is consistent with zero without the need for the statistical uncertainty. Therefore, there is no evidence for asymmetry between 3334 and -3334 in the measured data. The zero difference shows that they have an equal measured average production rate.
