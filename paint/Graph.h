#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Graph{	
private:
	int num_of_vertex;
	int num_of_edge;
	int num_of_color;
public:
	vector<vector<int>> _matrix;
	vector<int> _level;
	vector<vector<int>> non_paint;
	vector<int>list_color;

	void readfile(std::string file_name);
	bool find_color(int _vertex,int _color);
	void paint();
	vector<int> find_level_of_vertex();
	int find_level_highest();
	int count_color();
	void writefile(std::string file_name);
};