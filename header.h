#include <stdio.h>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#define MAX 100
using namespace std;
struct Node{
	int x;
	int y;
};
class Matrix{
private:
	Node start, goal;
	int m;
	int a[100][100];
	bool temp[MAX][MAX];
	bool checked[MAX][MAX];
	stack <Node> listNode;
public:
	void read_file(std::string file_name);
	int get_m(){return m;}
	void init_visited();
	Node getStart(){ return start;}
	Node getGoal(){return goal;}
	Node find_node_by_vertical_axis(Node node); //y
	Node find_node_by_horizontal_axis(Node node); //x
	void find_node(Node s, Node e);
	void write_file(std::string file_name);
};