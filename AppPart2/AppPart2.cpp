#include "Simple_window.h" 
#include "Graph.h" 
#include "AppPart2.h"
int main()
{
    using namespace Graph_lib;
    try{
    //Task 1
    Point tl(100, 100);
    Simple_window win(tl, 800, 600, "My Window");

    win.wait_for_button();

    //Tast 2 Cp 12.7.3
    Axis xa(Axis::x, Point(20, 300), 560, 20, "x axis");
    win.attach(xa); 
    win.set_label("My Window 2"); 
    win.wait_for_button();

    Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
    ya.set_color(Color::cyan); 
    ya.label.set_color(Color::dark_red); 
    win.attach(ya);
    win.set_label("My Window 3");
    win.wait_for_button();

    //Tast 2 Cp 12.7.4
    Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50); 
 
    win.attach(sine);
    win.set_label("My Window 4");
    win.wait_for_button();

    //Tast 2 Cp 12.7.5
    sine.set_color(Color::blue); 

    Graph_lib::Polygon poly;

    poly.add(Point(300, 200)); 
    poly.add(Point(350, 100));
    poly.add(Point(400, 200));
    poly.set_color(Color::red);
    poly.set_style(Line_style::dot);
    win.attach(poly);
    win.set_label("My Window 5");
    win.wait_for_button();

    //Tast 2 Cp 12.7.6
    Graph_lib::Rectangle r(Point(200, 200), 150, 100);
 
    win.attach(r);
    win.set_label("My Window 6");
    win.wait_for_button();

    Closed_polyline poly_rect;
    poly_rect.add(Point(100, 50));
    poly_rect.add(Point(200, 50));
    poly_rect.add(Point(200, 100));
    poly_rect.add(Point(100, 100));
    win.attach(poly_rect);

    //Tast 2 Cp 12.7.7
    r.set_fill_color(Color::yellow); 
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::dark_yellow);
    win.set_label("My Window 7");
    win.wait_for_button();

    //Tast 2 Cp 12.7.8
    Text t(Point(200, 200), "Chapter 12!");
    win.attach(t);
    win.set_label("My Window 8");
    win.wait_for_button();

    //Tast 2 Cp 12.7.9
    Image ii(Point(100, 50), "171.jpg");
 
    win.attach(ii);
    win.set_label("My Window 9");
    win.wait_for_button();

    ii.move(100, 200);
    win.set_label("My Window 10");
    win.wait_for_button();

    //Tast 2 Cp 12.7.10
    Circle c(Point(100, 200), 50);
    Graph_lib::Ellipse e(Point(100, 200), 75, 25);
    e.set_color(Color::dark_red);
    Mark m(Point(100, 200), 'x');
    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes(Point(100, 20), oss.str());
    Image cal(Point(150, 100), "162.jpg"); 
    
    cal.set_mask(Point(50, 50), 200, 150); 
     
    win.attach(c);
    win.attach(m);
    win.attach(e);
    win.attach(sizes);
    win.attach(cal);
    win.set_label("My Window 11");
    win.wait_for_button();

    }
    catch (exception& e) {
        return 1;
    }
    catch (...) {
        return 2;
    }
    return 0;
}