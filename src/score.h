#ifndef SCORE
#define SCORE

#include <string>
#include <vector>

class Score
{
public:
	Score(std::string file_name);
	void Add_score(std::string name, int score);
	void Print_scores();
	void Write();
	void Data();

private:
	std::string  File_Name;
	std::vector<std::pair<std::string,int>> scores;
};
	void Sort(std::vector<std::pair<std::string,int>> &scores);


#endif
