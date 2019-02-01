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


    void width_print( std::string);
    void height_print( std::string);
     void end_print( std::string);
    void final_vector (attribute* a);
    void final_vector_animate (animation* a);
    void set_width (double ) ;
     void set_height (double ) ;
    inline std::string to_string(double t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

void tosvg (std::string);




protected :

    double base_width=0 ;
    double base_height=0 ;
    std::vector <attribute*> type1;
    std::vector <animation*> type2;


};

class rectangle : public shape
{
    public:
        rectangle ( );

        ~rectangle(){} ;



   void tag_print(attribute*  , std::string ) ;






};

class circle : public shape
{
public :
    circle () ;
    ~ circle (){}

/**/void tag_print(attribute* a, std::string);

};

//////ellipse
class ellipse : public shape
{
public :
    ellipse () ;
    ~ ellipse (){}

/**/void tag_print(attribute* a, std::string);

};

//line
class line : public shape
{
public :
    line () ;
    ~ line (){}

/**/void tag_print(attribute* a, std::string);

};
////polygon

class polygon : public shape
{
public :
    polygon () ;
    ~ polygon (){}

/**/void tag_print(attribute* a, std::string);

};
////polyline
class polyline :  public shape
{
public :
    polyline () ;
    ~ polyline (){}

/**/void tag_print(attribute* a, std::string);

};


//////path
class path :  public shape
{
public :
    path () ;
    ~ path (){}

/**/void tag_print(attribute* a, std::string);

};

//////text

class text :  public shape
{
public :
    text () ;
    ~ text (){}

/**/void tag_print(attribute* a, std::string);

};
//// animate
class animate : public rectangle , public circle , public ellipse , public path ,public line , public polygon , public polyline , public text
{
public :
    animate () ;
    ~ animate (){}
    void animate_print (animation* a, std::string) ;
    void final_vector_animate (animation* a);
     void rect_print(std::vector <animation*>n ,attribute* a, std::string );
     void circle_print(std::vector <animation*>n ,attribute* a, std::string );
     void ellipse_print(std::vector <animation*>n ,attribute* a, std::string );
     void polygon_print(std::vector <animation*>n ,attribute* a , std::string);
     void line_print(std::vector <animation*>n ,attribute* a , std::string);
     void polyline_print(std::vector <animation*>n ,attribute* a, std::string );
     void text_print(std::vector <animation*>n ,attribute* a, std::string );
     void path_print(std::vector <animation*>n ,attribute* a , std::string);
private:
    std::vector <animation*> type3;

};

class plot :  public shape
{
public :
    plot () ;
    ~ plot (){}

/**/void scatter_print(attribute* a, std::string);
void print_circle(double , double, std::string);
void print_polyline(std::string, std::string);
int ran_num (int x ) ;
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
