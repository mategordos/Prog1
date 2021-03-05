/*
g++ drill_12ch.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/


#include "Simple_window.h"
#include "Graph.h"


int main(){
	using namespace Graph_lib;

	int xmax = 600;
	int ymax = 400;

	Simple_window win {{100,100}, xmax, ymax, "My window"};
}