#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

/*
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill2 `fltk-config --ldflags --use-images`
*/

int main(){

	using namespace Graph_lib;
	
try{

	int x_max = 800;
	int y_max = 1000;
	Simple_window win {Point{100,100},x_max,y_max, "Canvas"};
	win.set_label("My Window");

	int x_grid = 100;
	int y_grid = 100;
	int x_size = 800;
	int y_size = 800;

	// ======== GRID ========
	Lines grid;
	for(int x=x_grid; x<=x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	for(int y=y_grid; y<=800; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});
	grid.set_color(Color::red);
	grid.set_style(Line_style{Line_style::solid,2});
	win.attach(grid);

	// ======== 3 images ========
	Vector_ref<Image> Pictures;
	Image x {Point{0,0},"img.jpg"};
	Pictures.push_back(x);
	Pictures.push_back(new Image{Point{400,0},"img.jpg"});
	Pictures.push_back(new Image{Point{300,300},"img.jpg"});

	for(int i=0; i<Pictures.size(); i++)
		win.attach(Pictures[i]);
	
	// ======== Moving ========

	int xx = 0, yy = 0;
	
	Vector_ref<Image> m;
	m.push_back(new Image{Point{xx,yy}, "img2.jpg"});
	int aux = 1;

	while(yy <= 700){

		win.detach(m[aux-1]);

		if(xx <= 700){
			if( // Swerves the three 200x200 images
		       (xx == 0 && yy == 0)     ||
		       (xx == 0 && yy == 100)   ||
		       (xx == 100 && yy == 100) ||
		       (xx == 100 && yy == 0)   ||
			   (xx == 400 && yy == 0)   || 
			   (xx == 400 && yy == 100) ||
			   (xx == 300 && yy == 300) ||
			   (xx == 300 && yy == 400) ) 
					xx = xx + 200;

			m.push_back(new Image{Point{xx,yy}, "img2.jpg"});
			win.attach(m[aux]);
			xx = xx + 100;
			aux++;
		}
		else{
			xx = 100;
			yy = yy + 100;
			
		}
		
		win.set_label("My Window");
		win.wait_for_button();
	}

	}
	catch (exception& e){
		cout << "Error\n";
		return 1;
	}

	catch(...){
		cout << "Other error\n";
		return 2;
	}
} 