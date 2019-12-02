#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	fstream input;
	input.open("Day2in.txt");
	string holder;
	stringstream sstr;
	sstr << input.rdbuf();
	holder = sstr.str();//read input file into string
	vector<string> tokens;
	string token;
	istringstream tokenStreams(holder);
	while (getline(tokenStreams, token, ',')) { //divide into vector of strings
		tokens.push_back(token);
	}
	vector<int> array;
	for (int i = 0; i < tokens.size(); i++) {
		array.push_back(stoi(tokens[i]));//transform into vector of integers
	}
	int pos1, pos2, pos3;
	int verb, noun;
	for (noun = 0; noun < 99; noun++)
	{
		for (verb = 0; verb < 99; verb++)//brute force iterating for each value of noun and verb
		{
			for (int i = 0; i < array.size(); i++)
			{
				array[i] = stoi(tokens[i]);//make sure to work on same array as input
			}
			array[1] = noun;
			array[2] = verb;
			for (int i = 0; i < array.size(); i += 4) {//executing the IntCode
				switch (array[i]) {
				case 1:
					pos1 = array[i + 1];
					pos2 = array[i + 2];
					pos3 = array[i + 3];
					array[pos3] = array[pos1] + array[pos2];
					break;
				case 2:
					pos1 = array[i + 1];
					pos2 = array[i + 2];
					pos3 = array[i + 3];
					array[pos3] = array[pos1] * array[pos2];
					break;
				case 99:
					break;
					break;
				}
			}
			
			if (array[0] == 19690720) {
				cout << noun * 100 + verb << endl;//the result of part2
			}
		}
	}	
	//cout << array[0] << endl; //the result of part1
	return 0;
}