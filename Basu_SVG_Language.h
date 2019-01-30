#ifndef BASU_SVG_LANGUAGE_H_INCLUDED
#define BASU_SVG_LANGUAGE_H_INCLUDED

struct attribute  {

    std::string name ;
    std::string type , type1 ;
    double r=0.f ;
    double width =0;
    double height=0 ;
    double x =0.f, y=0.f ,cx=0.f ,cy=0.f ;
    double x1 =0.f, y1=0.f ,x2=0.f ,y2=0.f ;
    int rx=0 , ry=0 ,font_size;
    std::string fill_color ,font_family,txt ;
    std::string stroke="red" ;
    double stroke_width=0 ;
    int opacity=1;
    std::string points ;
    std::string d ;
    bool animate = false ;
    std::string title  ;
     std::vector<std::vector<double>> data;


attribute(std::string nam ) : name (nam){}


} ;


struct animation
    {

        std::string name1 ;
        std::string name ;
        std::string type ;
        std::string attributeName;
        double from ;
        double to ;
        std::string dur ;
        std::string repeatCount ;
        animation(std::string nam , std::string typ ,std::string nam1 ) : name (nam), type (typ),name1(nam1){}
    };



#endif // BASU_SVG_LANGUAGE_H_INCLUDED
