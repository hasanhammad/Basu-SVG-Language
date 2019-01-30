#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include<iostream>
#include <string>
#include<algorithm>
#include <vector>
#include <typeinfo>
#include <sstream>
#include"Basu_SVG_Language.h"
class shape
{
public :
    shape () ;
    ~shape(){} ;


    void width_print(double);
    void height_print(double);
     void end_print();
    std::string  List ();
    void final_vector (attribute* a);
    void final_vector_animate (animation* a);
    inline std::string to_string(double t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

void tosvg ();




protected :
    std::string name ;
    double base_width ;
    double base_height ;
     std::string fill_color ;
     std::string stroke ;
    double stroke_width ;
    int opacity;
    std::vector <attribute*> type1;
    std::vector <animation*> type2;


};

class rectangle : public shape
{
    public:
        rectangle ( );

        ~rectangle(){} ;



   void tag_print(attribute* ) ;






};

class circle : public shape
{
public :
    circle () ;
    ~ circle (){}

/**/void tag_print(attribute* a);

};

//////ellipse
class ellipse : public shape
{
public :
    ellipse () ;
    ~ ellipse (){}

/**/void tag_print(attribute* a);

};

//line
class line : public shape
{
public :
    line () ;
    ~ line (){}

/**/void tag_print(attribute* a);

};
////polygon

class polygon : public shape
{
public :
    polygon () ;
    ~ polygon (){}

/**/void tag_print(attribute* a);

};
////polyline
class polyline :  public shape
{
public :
    polyline () ;
    ~ polyline (){}

/**/void tag_print(attribute* a);

};


//////path
class path :  public shape
{
public :
    path () ;
    ~ path (){}

/**/void tag_print(attribute* a);

};

//////text

class text :  public shape
{
public :
    text () ;
    ~ text (){}

/**/void tag_print(attribute* a);

};
//// animate
class animate : public rectangle , public circle , public ellipse , public path ,public line , public polygon , public polyline , public text
{
public :
    animate () ;
    ~ animate (){}
    void animate_print (animation* a) ;
    void final_vector_animate (animation* a);
     void rect_print(std::vector <animation*>n ,attribute* a );
     void circle_print(std::vector <animation*>n ,attribute* a );
     void ellipse_print(std::vector <animation*>n ,attribute* a );
     void polygon_print(std::vector <animation*>n ,attribute* a );
     void line_print(std::vector <animation*>n ,attribute* a );
     void polyline_print(std::vector <animation*>n ,attribute* a );
     void text_print(std::vector <animation*>n ,attribute* a );
     void path_print(std::vector <animation*>n ,attribute* a );
private:
    std::vector <animation*> type3;

};

class plot :  public shape
{
public :
    plot () ;
    ~ plot (){}

/**/void scatter_print(attribute* a);
void print_circle(double , double);
void print_polyline(std::string);
struct point
    {
        double x , y ;
        bool operator < (const point& rhs) const {
        return x < rhs.x;
  }
    };

private :


    std::vector <point>points;

};

#endif // SHAPE_H_INCLUDED
