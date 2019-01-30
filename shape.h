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

class rectangle :virtual public shape
{
    public:
        rectangle ( );

        ~rectangle(){} ;



   virtual void tag_print(attribute* ) ;






};

class circle :virtual public shape
{
public :
    circle () ;
    ~ circle (){}

/**/void tag_print(attribute* a);

};

//////ellipse
class ellipse :virtual public shape
{
public :
    ellipse () ;
    ~ ellipse (){}

/**/void tag_print(attribute* a);

};

//line
class line :virtual public shape
{
public :
    line () ;
    ~ line (){}

/**/void tag_print(attribute* a);

};
////polygon

class polygon :virtual public shape
{
public :
    polygon () ;
    ~ polygon (){}

/**/void tag_print(attribute* a);

};
////polyline
class polyline : virtual public shape
{
public :
    polyline () ;
    ~ polyline (){}

/**/void tag_print(attribute* a);

};


//////path
class path : virtual public shape
{
public :
    path () ;
    ~ path (){}

/**/void tag_print(attribute* a);

};

//////text

class text : virtual public shape
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
    void tag_print(attribute* a);
    void animate_print (animation* a) ;
    void final_vector_animate (animation* a);
     int  get_size( attribute* a);
private:
    std::vector <animation*> type3;

};

#endif // SHAPE_H_INCLUDED
