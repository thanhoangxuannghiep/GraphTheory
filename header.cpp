#include "header.h"
void Matrix::read_file(std::string file_name){
	ifstream file;
    file.open (file_name);
    if (!file.is_open()) return;
    string line, word;
	file >> start.x;
	file >> start.y;
	file >> goal.x;
	file >> goal.y;
	file >> m;
	cout << "start: " << start.x << "-" << start.y << endl;
	cout << "goal: " << goal.x << "-" << goal.y << endl;
	for(int i = 0; i<m;i++){
		for(int j = 0; j<m;j++){
			file >> a[i][j];
		}
	}
}
Node Matrix::find_node_by_vertical_axis(Node node){
	Node prev, next;
	prev.y = next.y = node.y;
	prev.x = node.x - 1;
	next.x = node.x + 1;
	Node result;
	if(prev.x >= 0){
		if(next.x < m){
			if(a[prev.x][prev.y] == 1 && a[next.x][next.y] == 1){
				result = node;
			}else if(a[prev.x][prev.y] == 0 && a[next.x][next.y] == 1){
				result = prev;
			}else if(a[prev.x][prev.y] == 1 && a[next.x][next.y] == 0){
				result = next;
			}else{
				//result = next;
				if(!temp[next.x][next.y] && !temp[prev.x][prev.y]){
					result = next;
				}else if(!temp[next.x][next.y] && temp[prev.x][prev.y]){
					result = next;
				}else{
					result = prev;
				}
			}
		}else{
			if(a[prev.x][prev.y] == 0){
				result = prev;
			}else{
				result = node;
			}
		}
	}else{
		if(next.x < m){
			if(a[next.x][next.y] == 0){
				result = next;
			}else{
				result = node;
			}
		}else{
			result = node;
		}
	}
	if(!temp[result.x][result.y])
		return result;
	else
		return node;
}
void Matrix::init_visited(){
	for(int i = 0; i<MAX; i++){
		for(int j = 0; j<MAX; j++){
			temp[i][j] = false;
			checked[i][j] = false;
		}
	}
}
Node Matrix::find_node_by_horizontal_axis(Node node){
	Node prev, next;
	prev.x = next.x = node.x;
	prev.y = node.y - 1;
	next.y = node.y + 1;
	Node result;
	if(prev.y >= 0){
		if(next.y < m){
			if(a[prev.x][prev.y] == 1 && a[next.x][next.y] == 1){
				result = node;
			}else if(a[prev.x][prev.y] == 0 && a[next.x][next.y] == 1){
				result = prev;
			}else if(a[prev.x][prev.y] == 1 && a[next.x][next.y] == 0){
				result = next;
			}else{ //both node equal 0 choose node have x less than.
				if(!temp[next.x][next.y] && !temp[prev.x][prev.y]){
					result = next;
				}else if(!temp[next.x][next.y] && temp[prev.x][prev.y]){
					result = next;
				}else{
					result = prev;
				}
			}
		}else{
			if(a[prev.x][prev.y] == 0){
				result = prev;
			}else{
				result = node;
			}
		}
	}else{
		if(next.y < m){
			if(a[next.x][next.y] == 0){
				result = next;
			}else{
				result = node;
			}
		}else{
			result = node;
		}
	}
	if(!temp[result.x][result.y])
		return result;
	else
		return node;
}
void Matrix::find_node(Node s, Node e){
	this->init_visited();
	listNode.push(s); //ðýa node vào stack
	//temp[s.x][s.y] == true;
	int i = 0;
	while(!listNode.empty()){
		Node k ;
		k=listNode.top();
		if(k.x == e.x && k.y == e.y){
			cout << "founded";
			break;
		}
		checked[k.x][k.y] = true;
		//listNode.pop();// Lay k ra khoi stack
		Node temp1 = this->find_node_by_horizontal_axis(k);		
		Node temp2 = this->find_node_by_vertical_axis(k); 
		/*cout << "("<< k.x << ", " << k.y << ")";
		cout << k.x << "-k" << k.y << "\t";
		cout << temp1.x << "-a" << temp1.y << "\t";
		cout << temp2.x << "-b" << temp2.y << endl;*/
		//if(temp1.x != k.x || temp1.y != k.y){
		//	/*cout << 0 << "\t";
		//	listResult[i] = temp1;
		//	i++;*/
		//}
		//if(temp2.x != k.x || temp2.y != k.y){
		//	/*cout << 0 << "\t";
		//	listResult[i] = temp2;
		//	i++;*/
		//}
		//if(temp1.x == k.x && temp1.y == k.y)
		//	listNode.pop();// Lay k ra khoi stack
		/*cout << k.x << "-x" << k.y << endl;*/
		if(temp1.x == temp2.x && temp1.y == temp2.y){
			if((temp1.x == k.x && temp1.y == k.y)){
				listNode.pop();// Lay k ra khoi stack
			}else{
				if(temp1.x != s.x || temp1.y != s.y){//
					if(!temp[temp1.x][temp1.y]){
						listNode.push(temp1);
						temp[temp1.x][temp1.y] = true;
					}
				}
			}
		}else{
			
				if(temp1.x != s.x || temp1.y != s.y){
					if(!temp[temp1.x][temp1.y]){
						listNode.push(temp1);
						temp[temp1.x][temp1.y] = true;
					}
				}
			
				if(temp2.x != s.x || temp2.y != s.y){
					if(!temp[temp2.x][temp2.y]){
						listNode.push(temp2);
						temp[temp2.x][temp2.y] = true;
					}
				}
			
		}
		
	}
}

void Matrix::write_file(std::string file_name){
	cout << endl;
	stack <Node> result;
	while(!listNode.empty()){
		Node k;
		k = listNode.top();
		listNode.pop();
		result.push(k);
	}
	while(!result.empty()){
		Node k1;
		k1 = result.top();
		result.pop();
		if(temp[k1.x][k1.y]){
			if(checked[k1.x][k1.y] || (k1.x == goal.x && k1.y == goal.y)){
				cout << "("<< k1.x << ", " << k1.y << ") \t";
			}
		}
	}
}