#include <score.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


Score::Score(std::string file_name) : File_Name(file_name)  // good
{
	
}
void Score::Data(){
std::ifstream input(File_Name);
	if (!input) {
		std::ofstream(File_Name, std::fstream::out);
	} 
	else 
	{
		std::string name;
    	int score;
    	while (input >> name) {
        	input >> score;
			scores.push_back(std::pair<std::string, int>(name, score));
    	}
	}
}

void Score::Add_score(std::string name, int score){ //good 
	scores.push_back(std::pair<std::string, int>(name, score));
	Sort(scores);
}

void Score::Write() { //good 
	std::ofstream output(File_Name, std::ofstream::out);
	for (auto x : scores) {
		output << x.first << " " << x.second << "\n";
	}
}

bool cmp(const std::pair<std::string, int>& a,const std::pair<std::string, int>& b)
{
	return (a.second > b.second);
}

void Sort(std::vector<std::pair<std::string,int>> &scores) 
{
	std::sort(scores.begin(), scores.end(), cmp);
}

void Score::Print_scores() //good
{
	int i = 1;
	std::cout << "Rank	Name	Score\n";
	for (auto x : scores)
	{
		std::cout << i << ".	" << x.first << "	" << x.second << "\n";
		i++;
	}
}

