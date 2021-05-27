/*
g++ drill_12ch.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`
*/


#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1;}
double square(double x) { return x*x;}

int main()
{
	
	Point tl{100, 100};

	int xmax = 600;
	int ymax = 400;

//12.7.2
	Simple_window win {tl, xmax, ymax, "Canvas"};

//12.7.9 hatternek akarom, ezért raktam ide c:
	Image ii {Point{100,50}, "test.jpg"};
	win.attach(ii);
	win.set_label("Canvas #10");

//12.7.3
	Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};
	win.attach(xa);
	win.set_label("My Window #2");
	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.set_color(Color::blue);
	ya.label.set_color(Color::dark_green);
	win.attach(ya);
	win.set_label("My window #3");

//12.7.4
	Function sine {sin, 0, 100, Point{20,150}, 1000, 50, 50};
	win.attach(sine);
	win.set_label("My window #4");


//12.7.5
	sine.set_color(Color::red);

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");

//12.7.6

	Rectangle r {Point{200,200},100,50};
	win.attach(r);
	win.set_label("Canvas #6");

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	poly_rect.add(Point{50,100});
	win.attach(poly_rect);


//12.7.7
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,5));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");


//12.7.8
	Text t {Point{250,150}, "c h e e m s"};
	win.attach(t);
	win.set_label("Canvas #8");

	t.set_font(Font::times_italic);
	t.set_font_size(20);
	win.set_label("Canvas #9");


//	ii.move(100,200);
	win.set_label("Canvas #11");

//12.7.10
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200}, 'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20}, oss.str()};

	Image cal {Point{225,225},"test2.jpeg"};
	cal.set_mask(Point{10,10},200,150);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(cal);
	win.attach(sizes);

	win.wait_for_button();

}