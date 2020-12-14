#include <score.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


Score::Score(std::string file_name) : File_Name(file_name) 
{

}

std::string Score::Get_file() 
{
	return File_Name;
}

bool Score::Available() 
{
	bool available = true;
	std::string file = Get_file();
	std::ifstream input(file);
	if (!input) available = false;
	return available;
}

void Score::Create_file() 
{
	std::string file = Get_file();
	std::ofstream(file, std::fstream::out);
}

void Score::Prev_Scores() {
	std::ifstream input(File_Name);
    std::string People;
    int Points;
    while (input >> People) {
        input >> Points;
        scores.insert({People, Points});
    }
}

void Score::Add_score(std::string name, int score)
{
	scores.insert(std::pair<std::string, int>(name, score));
	Sort(scores);
}

bool cmp(const std::pair<std::string, int>& a,const std::pair<std::string, int>& b)
{
	return (a.second > b.second);
}

void Sort(std::map<std::string, int> &scores) 
{
	std::vector<std::pair<std::string, int> > A;
	for (auto& it : scores) {
		A.push_back(it);
	}
	std::sort(A.begin(), A.end(), cmp);
	scores.clear();
	for (auto it : A) {
		scores.insert(it);
	}

}

void Score::Print_scores()
{
	int i = 1;
	std::cout << "Rank	Name	Score\n";
	for (auto it = scores.begin(); it != scores.end(); ++it)
	{
		std::cout << i << ".	" << it->first << "	" << it->second << "\n";
		i++;
	}
}

void Score::Write() {
	std::ofstream output(File_Name, std::ofstream::out);
	std::map<std::string, int>::iterator it2;
	for (it2 = scores.begin(); it2 != scores.end(); it2++) {
		output << it2->first << " " << it2->second << "\n";
	}
}
