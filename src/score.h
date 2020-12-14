#ifndef SCORE
#define SCORE

#include <string>
#include <map>

class Score
{
public:
	Score(std::string file_name);
	bool Available();
	std::string Get_file();
	void Create_file();
	void Add_score(std::string name, int score);
	void Print_scores();
	void Write();
	void Prev_Scores();

private:
	std::string  File_Name;
	std::multimap<std::string, int> scores;
};
	void Sort(std::multimap<std::string, int> &scores);


#endif
