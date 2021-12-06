#include<iostream>

#include<iomanip>

#include<fstream>

//using standard namespace
using namespace std;

// Defining num_of_score and Total_player
double num_of_score = 5.0;

#define Total_player 10

//Declairing functions
bool GetBowlingData(char name[][10], int scores[][5], int& r);

void GetAverageScore(int scores[][5], double average_scores[], int r);

void PrettyPrintResults(char name[][10], int scores[][5], double average_score[], int r);

//Defining GetBowlingData() function
bool GetBowlingData(char name[][10], int scores[][5], int& r)
{
	//opening Bowling.txt file
	ifstream file("BowlingScores.txt");

	// if the file doesn't open 
	if (file.fail() == true) {
		// return value false 
		return false;
	}
	// if the file openes
	else {
		// continue untill the file is ended
		while (file.eof() == false) {
			// reading the names in name array
			file >> name[r];
			//reading the scores such r as row and 0 1 2 3 4 as columns
			file >> scores[r][0];
			file >> scores[r][1];
			file >> scores[r][2];
			file >> scores[r][3];
			file >> scores[r][4];
			// increasing r by adding 1
			r = r + 1;
		}
		// the return type is true
		return true;
	}
}

//Defining GetAverageScore() function
void GetAverageScore(int scores[][5], double average_scores[], int r)
{
	//starting for loop
	for (int x = 0; x < r; x++) 
	{

		average_scores[x] = 0;

		for (int y = 0; y < 5; y++) 
		{

			average_scores[x] = average_scores[x] + scores[x][y];

		}
		//calculationg average_scores
		average_scores[x] /= num_of_score;

	}

}

//Defining PrettyPrintResults() function
void PrettyPrintResults(char name[][10], int scores[][5], double average_score[], int r)
{
	//printing the hearder aligned to the left
	cout << left << setw(10) << "Name      1st_score       2nd_score       3rd_score       4th_score       5th_score       Average_score" << endl;

	//for loop continues untill x<r
	for (int x = 0; x < r; x++) {

		//printing result aligned to left
		cout << left << setw(10) << name[x] << "      ";

		//continuing for loop untill y<5
		for (int y = 0; y < 5; y++)

			//pritng scores
			cout << scores[x][y] << "\t\t";
		//printing average score
		cout << average_score[x] << endl;

	}

}
//Defining the main() function
int main()
{
	//defining arrays and initial value
	char name[Total_player][10];

	int scores[Total_player][5];

	double average_score[Total_player];

	int r = 0;

	//if GetBowlingData has values then do the follwings
	if (GetBowlingData(name, scores, r))
	{

		GetAverageScore(scores, average_score, r);

		PrettyPrintResults(name, scores, average_score, r);

	}
	//else print "No file found"
	else
	{
		cout << "No file found";
	}


	return 0;

}
