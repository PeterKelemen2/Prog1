#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill_4.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill4 `fltk-config --ldflags --use-images`
*/

using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return slope(x)+cos(x);}

int main(){

	constexpr int xmax = 600;
	constexpr int ymax = 600;

	Point x_orig {100,300};
	Point y_orig {300,500};
	Point center {300,300};

	constexpr int r_min = -10;
	constexpr int r_max = 11;

	constexpr int n_points = 400;

	Simple_window win{Point{100,100}, xmax,ymax, "Function graphs"};

	Axis x {Axis::x, x_orig, 400, 20, "1 == 20 pixels"};
	Axis y {Axis::y, y_orig, 400, 20, "1 == 20 pixels"};
	x.set_color(Color::red);
	y.set_color(Color::red);

	Function f1 {one, r_min,r_max, center, n_points,20,20};
	
	Function f2 {slope, r_min,r_max, center, n_points, 20,20};
		Text lf1 {Point{70,415},"x/2"};
	
	Function f3 {square, r_min,r_max, center, n_points, 20,20};
	
	Function cosine {cos, r_min,r_max, center, n_points, 20,20};
		cosine.set_color(Color::blue);
	
	Function slop_cos {sloping_cos, r_min,r_max, center, n_points, 20,20};


	win.attach(x);
	win.attach(y);
	win.attach(f1);
	win.attach(f2);
	win.attach(lf1);
	win.attach(f3);
	win.attach(cosine);
	win.attach(slop_cos);

	win.wait_for_button();

	return 0;
}