#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{

	string inputFile;
	if (argc > 1)
	{
		inputFile = argv[1];
	}
	else
	{
		cout << "Need an input, please!" << endl;
		exit(1);
	}
	//declare inputStream -- reading from file
	ifstream inputStream;
	inputStream.open(inputFile);

	if(inputStream.fail())
	{
		cout << "Problem opening the file!" << endl;
		exit(1);
	}

	ofstream outputStream;
	outputStream.open("Joshua.out", ios::app);

	if(outputStream.fail())
	{
		cout << "Problem creating or opening the output file!" << endl;
		exit(1);
	}

	//set the file output to 2 decimal places for float or double values
		outputStream.setf(ios::fixed);
		outputStream.setf(ios::showpoint);
		outputStream.precision(2);

	//Set the console output to 2 decimal places for float or double values
	outputStream.setf(ios::fixed);
	outputStream.setf(ios::fixed);
	outputStream.precision(2);

	//print out header information in output file

	outputStream << "Joshua Barrs" << endl
				 << "002294736" << endl
				 << "barrs@chapman.edu" << endl
				 << "CPSC350 -- 01" << endl
				 << "Assignment1" << endl << endl;

	//read the lines of the file to determine the mean string length

	int stringCount = 0;      //number of strings in the file
	int sizeOfAllStrings = 0; //the total size of all the string lengths
	string allDNASequences;   //a string containing all of the valid DNA sequences from the various lines of the file

	while(!inputStream.eof())
	{
		string sequence;

		getline(inputStream, sequence);

		stringCount++;


		for(int i = 0; i < sequence.size(); ++i)
		{
			if(sequence[i]=='A' || sequence[i] == 'a' || sequence[i]=='C' || sequence[i] == 'c' || sequence[i]=='T' || sequence[i] == 't' || sequence[i] == 'G' || sequence[i] == 'g')
			{
				sizeOfAllStrings++;
				allDNASequences += sequence[i];
			}
		}
	}

	//capitalize all the sequences passed into allDNASequences
	for (int i = 0; i <= allDNASequences.size(); ++i)
	{
		toupper(allDNASequences[i]);
	}

	outputStream << "All DNA sequences: " << allDNASequences << endl;

	double stringSizeMean = static_cast<double>(sizeOfAllStrings) / stringCount;
	outputStream << "Mean string size: " << stringSizeMean << endl;

	inputStream.close();


	//Now find the variance (mean had to be computed first)

	inputStream.open("inputFile.txt");

	double sumOfVarianceComponents;
	double varianceComponent;


	while(!inputStream.eof())
	{
		string sequence;
		int sizeOfThisString;

		getline(inputStream,sequence);

		for(int i = 0; i < sequence.size(); ++i)
		{
			if(sequence[i]=='A' || sequence[i] == 'a' || sequence[i]=='C' || sequence[i] == 'c' || sequence[i]=='T' || sequence[i] == 't' || sequence[i] == 'G' || sequence[i] == 'g')
			{
				sizeOfThisString++;
			}
		}

		varianceComponent = pow((sizeOfThisString - stringSizeMean), 2);

		sumOfVarianceComponents += varianceComponent;
	}

	double variance = sumOfVarianceComponents / stringCount;
	double stDev = sqrt(variance);

	outputStream << "Variance is: " << variance << endl
		 << "Standard deviation is: " << stDev << endl;

	//code to calculate probabilities of nucleotides

	double probOfA = 0, probOfG = 0, probOfT = 0, probOfC = 0;
	int countOfA = 0, countOfT = 0, countOfG = 0, countOfC = 0;

	for (int i = 0; i <= allDNASequences.size(); ++i)
	{
		if(allDNASequences[i] == 'A' || allDNASequences[i] == 'a')
		{
			countOfA++;
		}

		else if(allDNASequences[i] == 'G' || allDNASequences[i] == 'g')
		{
			countOfG++;
		}

		else if(allDNASequences[i] == 'T' || allDNASequences[i] == 't')
		{
			countOfT++;
		}

		else if(allDNASequences[i] == 'C' || allDNASequences[i] == 'c')
		{
			countOfC++;
		}
	}

	outputStream << "total size of all strings: " << allDNASequences.size() << endl;

	probOfA = static_cast<double>(countOfA) / sizeOfAllStrings;

	probOfG = static_cast<double>(countOfG) / sizeOfAllStrings;

	probOfT = static_cast<double>(countOfT) / sizeOfAllStrings;

	probOfC = static_cast<double>(countOfC) / sizeOfAllStrings;

	outputStream << "Probability of A: " << probOfA << endl
		 << "Probability of G: " << probOfG << endl
		 << "Probability of T: " << probOfT << endl
		 << "Probability of C: " << probOfC << endl;

//probabilities of bigrams

	int countOfAA = 0;
	double probOfAA = 0;
	int countOfAC = 0;
	double probOfAC = 0;
	int countOfAT = 0;
	double probOfAT = 0;
	int countOfAG = 0;
	double probOfAG = 0;
	int countOfCA = 0;
	double probOfCA = 0;
	int countOfCC = 0;
	double probOfCC = 0;
	int countOfCT = 0;
	double probOfCT = 0;
	int countOfCG = 0;
	double probOfCG = 0;
	int countOfTA = 0;
	double probOfTA = 0;
	int countOfTC = 0;
	double probOfTC = 0;
	int countOfTT = 0;
	double probOfTT = 0;
	int countOfTG = 0;
	double probOfTG = 0;
	int countOfGA = 0;
	double probOfGA = 0;
	int countOfGC = 0;
	double probOfGC = 0;
	int countOfGT = 0;
	double probOfGT = 0;
	int countOfGG = 0;
	double probOfGG = 0;
	int totalBigramsPossible = sizeOfAllStrings / 2;

	//count number of bigrams in allDNASequences
	for (int i = 0; i <= allDNASequences.size(); i+=2)
	{
		if(allDNASequences[i] == 'A' && allDNASequences[i+1] == 'A')
		{
			countOfAA++;
		}

		else if(allDNASequences[i] == 'A' && allDNASequences[i+1] == 'C')
		{
			countOfAC++;
		}

		else if(allDNASequences[i] == 'A' && allDNASequences[i+1] == 'T')
		{
			countOfAT++;
		}

		else if(allDNASequences[i] == 'A' && allDNASequences[i+1] == 'G')
		{
			countOfAG++;
		}

		else if(allDNASequences[i] == 'C' && allDNASequences[i+1] == 'A')
		{
			countOfCA++;
		}

		else if(allDNASequences[i] == 'C' && allDNASequences[i+1] == 'C')
		{
			countOfCC++;
		}

		else if(allDNASequences[i] == 'C' && allDNASequences[i+1] == 'T')
		{
			countOfCT++;
		}

		else if(allDNASequences[i] == 'C' && allDNASequences[i+1] == 'G')
		{
			countOfCG++;
		}

		else if(allDNASequences[i] == 'T' && allDNASequences[i+1] == 'A')
		{
			countOfTA++;
		}

		else if(allDNASequences[i] == 'T' && allDNASequences[i+1] == 'C')
		{
			countOfTC++;
		}

		else if(allDNASequences[i] == 'T' && allDNASequences[i+1] == 'T')
		{
			countOfTT++;
		}

		else if(allDNASequences[i] == 'T' && allDNASequences[i+1] == 'G')
		{
			countOfTG++;
		}

		else if(allDNASequences[i] == 'G' && allDNASequences[i+1] == 'A')
		{
			countOfGA++;
		}

		else if(allDNASequences[i] == 'G' && allDNASequences[i+1] == 'C')
		{
			countOfGC++;
		}

		else if(allDNASequences[i] == 'G' && allDNASequences[i+1] == 'T')
		{
			countOfGT++;
		}

		else if(allDNASequences[i] == 'G' && allDNASequences[i+1] == 'G')
		{
			countOfGG++;
		}
	}

	//compute the probabilities
	probOfAA = static_cast<double>(countOfAA) / totalBigramsPossible;
	probOfAC = static_cast<double>(countOfAC) / totalBigramsPossible;
	probOfAT = static_cast<double>(countOfAT) / totalBigramsPossible;
	probOfAG = static_cast<double>(countOfAG) / totalBigramsPossible;
	probOfCA = static_cast<double>(countOfCA) / totalBigramsPossible;
	probOfCC = static_cast<double>(countOfCC) / totalBigramsPossible;
	probOfCT = static_cast<double>(countOfCT) / totalBigramsPossible;
	probOfCG = static_cast<double>(countOfCG) / totalBigramsPossible;
	probOfTA = static_cast<double>(countOfTA) / totalBigramsPossible;
	probOfTC = static_cast<double>(countOfTC) / totalBigramsPossible;
	probOfTT = static_cast<double>(countOfTT) / totalBigramsPossible;
	probOfTG = static_cast<double>(countOfTG) / totalBigramsPossible;
	probOfGA = static_cast<double>(countOfGA) / totalBigramsPossible;
	probOfGC = static_cast<double>(countOfGC) / totalBigramsPossible;
	probOfGT = static_cast<double>(countOfGT) / totalBigramsPossible;
	probOfGG = static_cast<double>(countOfGG) / totalBigramsPossible;

	outputStream << "Probabilities of various bigrams follow: " << endl
		 << "AA: " << probOfAA << endl
		 <<"AC: " << probOfAC << endl
		 <<"AT: " << probOfAT << endl
		 << "AG: " << probOfAG << endl
		 << "CA: " << probOfCA << endl
		 <<"CC: " << probOfCC << endl
		 <<"CT: " << probOfCT << endl
		 << "CG: " << probOfCG << endl
		 << "TA: " << probOfTA << endl
		 <<"TC: " << probOfTC << endl
		 <<"TT: " << probOfTT << endl
		 << "TG: " << probOfTG << endl
		 << "GA: " << probOfGA << endl
		 <<"GC: " << probOfGC << endl
		 <<"GT: " << probOfGT << endl
		 << "GG: " << probOfGG << endl;

//generate the 1000 DNA strings adhering to the statistics calculated above

	int printedStrings = 0;
	int countOfAInCollection = 0;
	int countOfTInCollection = 0;
	int countOfCInCollection = 0;
	int countOfGInCollection = 0;
	int totalNucleotidesInCollection = 1;
	int i = 0; //needed to set the seed for outer while loop random variable generation
	int j = 0; //needed to set the seed value for inner while loop random variable generation

	while(printedStrings < 1000)
	{

		srand(i);
		//Compute the Gaussian distribution

		double a = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);
		double b = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);

		if(a == 1.0)
		{
			a = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);
		}

		if(b == 1.0)
		{
			b = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);
		}

		double radianForCalculation = (2 * 3.14159 * b * (3.14159 / 180)); //formula to convert degrees to radians is PI/180

		double C = sqrt(-2 * log(a)) * cos(radianForCalculation);

		double D = (stDev * C) + stringSizeMean;

		int integerD = static_cast<int>(D);
		//finished computing Gaussian distribution

		//cout << D << endl;

		string stringToPrint;
		int stringLength = integerD;
		int nucleotidesInString = 0;

		while(nucleotidesInString <= stringLength)
		{

			srand(j);
			int randomNumber = rand() % 4;

			if(randomNumber == 0)
			{
				if ((countOfAInCollection/totalNucleotidesInCollection) <= probOfA)
				{
					stringToPrint += 'A';
					countOfAInCollection++;
					totalNucleotidesInCollection++;
					nucleotidesInString++;

				}
				else
				{
					continue;
				}
			}

			else if(randomNumber == 1)
			{
				if((countOfCInCollection/totalNucleotidesInCollection) <= probOfC)
				{
					stringToPrint += 'C';
					countOfCInCollection++;
					totalNucleotidesInCollection++;
					nucleotidesInString++;
				}
				else
				{
					continue;
				}
			}

			else if(randomNumber == 2)
			{
				if((countOfTInCollection/totalNucleotidesInCollection) <= probOfT)
				{
					stringToPrint += 'T';
					countOfTInCollection++;
					totalNucleotidesInCollection++;
					nucleotidesInString++;
				}
				else
				{
					continue;
				}
			}

			else if(randomNumber == 3)
			{
				if((countOfGInCollection/totalNucleotidesInCollection) <= probOfG)
				{
						stringToPrint += 'G';
						countOfGInCollection++;
						totalNucleotidesInCollection++;
						nucleotidesInString++;
				}
				else
				{
					continue;
				}
			}
			j++;
		}
		outputStream << stringToPrint << endl;
		printedStrings++;
		i++;
	}
}
