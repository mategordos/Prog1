/*
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/


#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1;}
double square(double x) { return x*x;}

int main()
{
	using namespace Graph_lib;
	
	Point tl{100, 100};

	int xmax = 1280;
	int ymax = 720;

	int x_orig = xmax/2;
	int y_orig = ymax/2;

	int rmin = -11;
	int rmax = 11;

	int n_points = 400;

	Simple_window win {tl, xmax, ymax, "Canvas"};

/*	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
 	win.attach(poly);
*/

	Point origo {x_orig, y_orig};

	int	xlength = xmax-10;
	int	ylength = ymax-40;


	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func( [] (double x) { return cos(x); }
					, rmin, rmax, origo, n_points, xscale, yscale);

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle r {Point{200,200}, 100, 50};

	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 4));

	Text t {Point{200,400}, "Hello Graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{100,100}, "test.jpg"};

	Circle c {Point{400,4000}, 50};

	win.attach(ii);
	win.attach(x);
	win.attach(y);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(r);
	win.attach(t);
	win.attach(c);



	win.wait_for_button();

}