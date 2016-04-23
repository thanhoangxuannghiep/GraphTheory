#include "Graph.h"
void Graph::readfile(std::string file_name){
	ifstream input(file_name);
	input >> this->num_of_vertex;
	input >> this->num_of_edge;
	vector<vector<int>> matrix(this->num_of_vertex, vector<int>(this->num_of_vertex));
	for (int i = 0; i < this->num_of_edge; i++){
		int d1, d2;
		input >> d1 >> d2;
		matrix[d1][d2] = matrix[d2][d1] = 1;
	}
	this->_matrix = matrix;
	input.close();
}
vector<int> Graph::find_level_of_vertex(){
	vector<int> level_temp (this->num_of_vertex, 0);
	for(int i = 0; i < this->num_of_vertex; i++){
		int count_level = 0;
		for(int j = 0; j < this->num_of_vertex; j++){
			if(this->_matrix[i][j] != 0){
				count_level++;
			}
		}
		level_temp[i] = count_level;
	}
	return level_temp;
}
int Graph::find_level_highest(){
	int max = 0;
	for(int i = 1; i < this->_level.size(); i++){
		if(this->_level[i] > this->_level[max]){
			max = i;
		}
	}
	return max;
}
void Graph::paint(){
	for(int h = 0; h < this->num_of_vertex; h++){
		vector<int> arrValue(this->num_of_vertex,-1);
		this->non_paint.push_back(arrValue);
	}

	this->_level = this->find_level_of_vertex();

	for(int i = 0; i < this->num_of_vertex; i++){
		this->list_color.push_back(-1);
	}
	int _vertex;
	while ( this->_level[this->find_level_highest()] != 0 ){
		_vertex = this->find_level_highest();
		this->_level[_vertex] = 0;
		for(int i = 0 ; i < 257; i++){
			if(this->find_color(_vertex,i) == false){
				this->list_color[_vertex] = i;
				break;
			}
		}
		for (int i = 0; i < this->num_of_vertex; i++){
			if(this->_matrix[_vertex][i] == 1){
				this->_level[i]--;
				this->non_paint[i].push_back( this->list_color[_vertex] );
			}
		}
	}
	for(int j = 0; j < this->list_color.size(); j++){
		if(this->list_color[j] < 0){
			for(int i = 0 ; i < 257; i++){
				if(this->find_color(j,i) == false){	
					this->list_color[j] = i;
					break;
				}
			}
		}
	}
}
bool Graph::find_color(int _vertex,int color){
	for(int i = 0; i < this->non_paint[_vertex].size(); i++){	
		if(color == this->non_paint[_vertex][i]){
			return true; 
		}
	}

	return false;
}
int Graph::count_color(){
	int max = 0;
	for (int i = 0; i < this->list_color.size(); i++){
		if(this->list_color[i] > this->list_color[max] || this->list_color[max] == -1){
			max = i;
		}
	}
	return this->list_color[max] + 1 ;
}
void Graph::writefile(std::string file_name){
	ofstream output(file_name);
	output.clear();
	if( output.is_open() ){
		this->num_of_color = this->count_color();
		if(this->num_of_color > 256)
		{
			output<< "-1" <<endl;
		}
		else
		{

			output << this->num_of_color << endl;
			for(int i = 0; i < this->list_color.size(); i++)
			{
				output << this->list_color[i] << " ";
			}

		}
	}
}