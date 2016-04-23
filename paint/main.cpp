#include "Graph.h"

void main(int argc, char* argvs[]){
	Graph* g = new Graph();
	g->readfile(argvs[1]);
	g->paint();
	g->writefile(argvs[2]);
}