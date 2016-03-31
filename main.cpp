#include "header.h"

void main(int argc, char* argvs[]){
	Matrix* mt = new Matrix();
	mt->read_file(argvs[1]);
	/*mt->find_node_by_vertical_axis(mt->getStart());
	mt->find_node_by_horizontal_axis(mt->getStart());*/
	mt->find_node(mt->getStart(), mt->getGoal());
	mt->write_file(argvs[2]);
}