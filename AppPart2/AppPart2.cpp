#include "Simple_window.h" 
#include "Graph.h" 

struct custom_Draw_Window
{
    Simple_window win;
       
    custom_Draw_Window(const Point& posForWindow, int windowHigh, int windowWidth, const std::string& windowTitle)
        :win{ posForWindow, windowHigh, windowWidth, windowTitle } {}

    void Axis_x(const Point& posForAxisX, int axisLenght_x, int axisDivision_x, const std::string& axisTitle_x) 
    {
        Axis xa(Axis::x, posForAxisX, axisLenght_x, axisDivision_x, axisTitle_x);
        xa.set_color(Color::dark_blue);
        win.attach(xa);
    }      

    void Axis_y(const Point& posForAxisY, int axisLenght_y, int axisDivision_y, const std::string& axisTitle_y) 
    {
        Axis ya(Axis::y, posForAxisY, axisLenght_y, axisDivision_y, axisTitle_y);
        ya.set_color(Color::dark_red);
        win.attach(ya);
    }

    void Rectagle_c(const Point& posForRectagle, int rectagleWidth, int rectagleHigh) 
    {
        Graph_lib::Rectangle r(posForRectagle, rectagleWidth, rectagleHigh);
        win.attach(r);
    }

    void Circle_c(const Point& posForCircle, int radius) 
    {
        Circle c(posForCircle, radius);
        win.attach(c);
    }

    void wait_for_button()
    {
        win.wait_for_button();
    }
};

int main()
{
    using namespace Graph_lib;
    try{
    //Create Window
    Point t1(100, 100);
    custom_Draw_Window win2(t1, 800, 600, "My Window");
    
    //Create axis X
    Point tl(20, 300);
    win2.Axis_x (tl, 560, 20, "x axis");
    //win.wait_for_button();

    //Create axis Y
    win2.Axis_y(tl, 280, 10, "y axis");
    //win.wait_for_button();
      
    //Draw rectagle
    Point r1(200, 200);
    Point r2(100, 100);
    win2.Rectagle_c(r1, 150, 100);
    win2.Rectagle_c(r2, 250, 250);
    win2.wait_for_button();

    //Draw Cicle
    Point c1(350, 350);
    win2.Circle_c(c1, 100);
    win2.wait_for_button();
    }
    catch (exception& e) {
        return 1;
    }
    catch (...) {
        return 2;
    }
    return 0;
}