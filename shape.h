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


};

class rectangle : public shape
{
    public:
        rectangle ( );

        ~rectangle(){} ;



   virtual void tag_print(attribute* ) ;






};

class circle : public shape
{
public :
    circle () ;
    ~ circle (){}

/**/void tag_print(attribute* a);

};



#endif // SHAPE_H_INCLUDED
