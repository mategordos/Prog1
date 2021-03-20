/*
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{

	Simple_window win {Point{100,100},801,1000,"My window"};
	//azért nem 800, mert a next button miatt nem férne ki az utolsó grid oszlop

	int x_size = win.x_max();
	int y_size = win.y_max()-200;
	int x_grid = 100;
	int y_grid = 100;

//grid create, attach

	Lines grid;
	for (int x = x_grid; x<x_size; x+=x_grid)
	{
		grid.add(Point{x,0}, Point{x,y_size});
	}
	for (int y = y_grid; y<y_size; y+=y_grid)
	{
		grid.add(Point{0,y}, Point{x_size,y});
	}

	win.attach(grid);

//grid create, attach end

//rect create, fill

	Vector_ref<Rectangle> rect;
	const int sq_size = 100;
	for (int i = 0; i < 8; i++)
	{
		rect.push_back(new Rectangle{Point{i*sq_size,i*sq_size},Point{(i+1)*sq_size,(i+1)*sq_size}});
		rect[rect.size()-1].set_fill_color(Color::red);
		win.attach(rect[rect.size()-1]);
	}

//rect create, fill end
//3 200x200 images start

	Image chad {Point{0,600}, "gigachad.jpeg"};
	Image chad_two {Point{600,0}, "gigachad.jpeg"};
	Image chad_three {Point{600,300}, "gigachad.jpeg"};


	win.attach(chad);
	win.attach(chad_two);
	win.attach(chad_three);
//3 200x200 ened

//moving  100x100 image around

	Image pepeclown {Point{0,0}, "schubertroll.jpeg"};
	win.attach(pepeclown);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {   
            win.wait_for_button();
            win.set_label("PepeLaugh");

            if (j < 7)
            {
                pepeclown.move(100,0);
            } 
            else
            {
                pepeclown.move(-700,100);
            } 

        }
    }
// 100x100 end
	win.wait_for_button();


}