#include<iostream>
#include<string>
#include<algorithm>
#include <vector>
#include<fstream>
#include <typeinfo>
#include"shape.h"
#include"rectangle.h"
#include"circle.h"

using namespace std ;

shape::shape ()
{

}




/**/void shape::width_print(double width)
    {
        ofstream fout;
        fout.open("hello.txt" ,std::ios_base::app);
        fout << "<?xml version=\"1.0\" standalone=\"no\"?>"<<endl;
        fout<<"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\""<<endl;
        fout<<"\"\http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">"<<endl;
        fout<<"<svg width=\""<<width<<"\"";
        fout.close();
    }
/**//**/void shape::height_print(double height)
    {
        ofstream fout;
        fout.open("hello.txt" ,std::ios_base::app);
        //fout<<"<svg width=\""<<get_width()<<"\" height=\""<<get_height()<<\""<<endl;
        fout<<" height=\""<<height<<"\""<<endl;
        fout<<"xmlns=\"\http://www.w3.org/2000/svg\" version=\"1.1\">"<<endl;
        fout.close();
    }
    /**/void shape::end_print()
    {
        ofstream fout;

        fout.open("hello.txt" ,std::ios_base::app);

        fout<<"</svg>"<< endl;

    }




    void shape::final_vector (attribute* a)
    {

       type1.push_back(a)  ;
       cout<<type1.size()<<endl;
        for (attribute* i : type1 )
        cout<<"shape class : "<<i->name<<endl;

    }

    void shape::tosvg ()
    {
        for (attribute* i : type1 )
        {
            if(i->type=="rectangle")
            {

                rectangle r ;
                r.tag_print(i);
                cout<<"reeeeee"<<endl;
            }

            if(i->type=="circle")
            {
                circle c ;
                c.tag_print(i);
                cout<<"ceeeeeeeeee"<<endl;
            }


        }



    }





    ////// rectangle
    rectangle::rectangle( )
{

}

void rectangle::tag_print(attribute* a )
    {
       ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<rect x=\""<<a->x
             <<"\" y=\""<<a->y
             <<"\" width=\""<<a->width
             <<"\" fill=\""<<a->fill_color
             <<"\" height=\""<<a->height
             //<<"\" stroke=\""<<get_stroke()
             //<<"\" stroke=\""<<get_stroke()
             <<"\" />"<<endl;
             fout.close();
    }
    ////// rectangle



    /////// circle
    circle::circle ()
{

}

    void circle::tag_print( attribute* a)
    {

         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<circle r=\""<<a->r
             <<"\" cx=\""<<a->cx
             <<"\" cy=\""<<a->cy
             <<"\" fill=\""<<a->fill_color
             //<<"\" stroke=\""<<get_stroke()
             //<<"\" stroke=\""<<get_stroke()
             <<"\" />"<<endl;
             fout.close();

    }


    ////// circle



