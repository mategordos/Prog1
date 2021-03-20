/*
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{

	int max_width = 600;
	int max_height = 400;

	Simple_window win{Point{100,100},
			max_width, max_height, "Graphics Classes"};
/*
	Line l (Point {200,200}, Point {300,300});

	Lines lines = {
		Point{100,100}, Point{200,100}, 
		Point{150,50}, Point{150,150} 
	};

	lines.add(Point{400,340}, Point{450,250});

	lines.set_color(Color::red);

	win.attach(lines);
 */
	Polygon opl;

	opl.add(Point{100,100});
	opl.add(Point{300,200});
	opl.add(Point{250,250});
	opl.add(Point{150,100});


	win.attach(opl);

	win.wait_for_button();

}