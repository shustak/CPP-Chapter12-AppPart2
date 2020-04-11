#include "Simple_window.h" 
#include "Graph.h" 
#include "AppPart2.h"

struct Axis_x
{
    Axis_x(Simple_window& win, const Point& pos, int w, int h, const std::string& title)
    {
        static Axis xa(Axis::x, pos, w, h, title);
        xa.set_color(Color::dark_blue);
        win.attach(xa);
        win.wait_for_button();
    }       
};

struct Axis_y
{
    Axis_y(Simple_window& win, const Point& pos, int w, int h, const std::string& title)
    {
        static Axis ya(Axis::y, pos, w, h, title);
        ya.set_color(Color::dark_red);
        win.attach(ya);
        win.wait_for_button();
    }
};

struct Sine_custom
{
    Sine_custom(Simple_window& win, const Point& pos, const std::string& title)
    {
        static Function sine(sin, 0, 100, pos, 1000, 50, 50);
        sine.set_color(Color::blue);
        win.attach(sine);
        win.set_label(title);
        win.wait_for_button();
    }
};

struct  Rectagle_Example
{
    Rectagle_Example(Simple_window& win, const Point& pos, int w, int h, const std::string& title)
    {
        static Graph_lib::Rectangle r(pos, w, h);
        win.attach(r);
        win.set_label(title);
        win.wait_for_button();               
    }
};

struct  Circle_custom
{
    Circle_custom(Simple_window& win, const Point& pos, int rad, const std::string& title)
    {
        static Circle c(pos, rad);
        win.attach(c);
        win.set_label(title);
        win.wait_for_button();
    }
};


int main()
{
    using namespace Graph_lib;
    try{
    //Create Window
    Point t1(100, 100);
    Simple_window win(t1, 800, 600, "My Window");
    
    //Create axis X
    Point tl(20, 300);
    Axis_x win_x { win, tl, 560, 20, "x axis" };
   
    //Create axis Y
    Axis_y win_y{ win, tl, 280, 10, "y axis" };
    
    //Draw sine
    Point sinP(20, 150);
    Sine_custom sinC{ win, sinP,  "My Window2" };
   
    //Draw rectagle
    Point r1(200, 200);
    Rectagle_Example rec{ win, r1, 150, 100, "My Window3" };
    
    //Draw Cicle
    Point c1(350, 350);
    Circle_custom cicle { win, c1, 100, "My Window4"};
    }
    catch (exception& e) {
        return 1;
    }
    catch (...) {
        return 2;
    }
    return 0;
}