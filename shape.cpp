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
        cout<<"shape class : "<<i->stroke<<endl;

    }
    void shape::final_vector_animate (animation* a)
    {

       type2.push_back(a)  ;
       cout<<type2.size()<<endl;
        for (animation* i : type2 )
        cout<<"shape classcccccc : "<<i->name<<endl;

    }

    void shape::tosvg ()
    {
        cout<<type2.size()<<"sssssssssss"<<endl;
        for (attribute* i : type1 )
        {
            if(i->type=="rectangle" && i->animate==true)
            {
                cout<<"you are ok"<<endl;
                animate n ;
                n.rect_print(type2,i);
            }
            if (i->type=="rectangle" && i->animate==false)
            {
                rectangle r ;
                r.tag_print(i);
                cout<<"reeeeee"<<endl;
            }

            if(i->type=="circle"&& i->animate==true)
            {
                 animate n ;
                n.circle_print(type2,i);
            }
            if(i->type=="circle"&& i->animate==false)
            {
                circle c ;
                c.tag_print(i);
            }
            if(i->type=="ellipse"&&i->animate==true)
            {
                 animate n ;
                n.ellipse_print(type2,i);
            }
            if(i->type=="ellipse"&&i->animate==false)
            {
                ellipse r ;
                r.tag_print(i);
                cout<<"eeeeee"<<endl;
            }
             if(i->type=="line"&&i->animate==true)
            {
                animate n ;
                n.line_print(type2,i);
            }
            if(i->type=="line"&&i->animate==false)
            {
                line r ;
                r.tag_print(i);
                cout<<"eeeeee"<<endl;
            }
            if(i->type=="polygon"&&i->animate==true)
            {
               animate n ;
                n.polygon_print(type2,i);
            }
             if(i->type=="polygon"&&i->animate==false)
            {
                polygon r ;
                r.tag_print(i);
                cout<<"pooooo"<<endl;
            }
            if(i->type=="polyline"&&i->animate==true)
            {
                animate n ;
                n.polyline_print(type2,i);
            }
             if(i->type=="polyline"&&i->animate==false)
            {
                polyline r ;
                r.tag_print(i);
                cout<<"poooooliiiii"<<endl;
            }
            if(i->type=="path"&&i->animate==true)
            {
                animate n ;
                n.path_print(type2,i);
            }
            if(i->type=="path"&&i->animate==false)
            {
                path r ;
                r.tag_print(i);
                cout<<"paaaaaaaaaaaa"<<endl;
            }
            if(i->type=="text"&&i->animate==true)
            {
                animate n ;
                n.text_print(type2,i);
            }
            if(i->type=="text"&&i->animate==false)
            {
                text r ;
                r.tag_print(i);
                cout<<"teeeeeee"<<endl;
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



    //////ellipse

 ellipse::ellipse ()
{

}

    void ellipse::tag_print( attribute* a)
    {
        cout<<a->stroke<<"in classsssssss"<<endl;

         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<ellipse cx=\""<<a->cx
             <<"\" cy=\""<<a->cy
             <<"\" rx=\""<<a->rx
             <<"\" ry=\""<<a->ry
             <<"\" fill=\""<<a->fill_color
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" />"<<endl;
             fout.close();

    }
///// line
line ::line  ()
{

}

    void line ::tag_print( attribute* a)
    {

         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<line x1=\""<<a->x1
             <<"\" y1=\""<<a->y1
             <<"\" x2=\""<<a->x2
             <<"\" y2=\""<<a->y2
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" />"<<endl;
             fout.close();

    }


    //////polygon
    polygon ::polygon  ()
{

}
    void polygon ::tag_print( attribute* a)
    {

         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<polygon points=\""<<a->points
             <<"\" fill=\""<<a->fill_color
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" />"<<endl;
             fout.close();

    }

    ////polyline
      polyline ::polyline  ()
{

}
    void polyline ::tag_print( attribute* a)
    {

         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<polyline points=\""<<a->points
             <<"\" fill=\""<<a->fill_color
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" />"<<endl;
             fout.close();

    }
    /////path
    path ::path  ()
{

}
    void path ::tag_print( attribute* a)
    {

         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<path d=\""<<a->d
             <<"\" fill=\""<<a->fill_color
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" />"<<endl;
             fout.close();

    }


    ////
      text ::text  ()
{

}
    void text ::tag_print( attribute* a)
    {

         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<text x=\""<<a->x
             <<"\" y=\""<<a->y
             <<"\" font-size=\""<<a->font_size
             <<"\" font-family=\""<<a->font_family
             <<"\">"<<a->txt<<"</text>"
             <<endl;
             fout.close();

    }


    ////// animate

       animate::animate()
{

}
void animate::final_vector_animate (animation* a)
    {

       type3.push_back(a)  ;
       cout<<type3.size()<<" finale vector size"<<endl;
        for (animation* i : type3 )
        cout<<"shape class : "<<i->name<<endl;
        cout<<type3.size()<<"finale vector size"<<endl;

    }
    void animate::rect_print(vector <animation*>n ,attribute* a )
    {
         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<rect x=\""<<a->x
             <<"\" y=\""<<a->y
             <<"\" width=\""<<a->width
             <<"\" fill=\""<<a->fill_color
             <<"\" height=\""<<a->height
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" >"<<endl;
             fout.close();
        for (animation* i : n )
        {
            cout<<i->name<<"  "<< a->name<<endl;
            if(i->name==a->name)
            {
            animate_print(i);
            }

        }
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"</rect>"<<endl;



    }
    void animate::circle_print(vector <animation*>n ,attribute* a )
    {
         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<circle r=\""<<a->r
             <<"\" cx=\""<<a->cx
             <<"\" cy=\""<<a->cy
             <<"\" fill=\""<<a->fill_color
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" >"<<endl;
             fout.close();
        for (animation* i : n )
        {
            cout<<i->name<<"  "<< a->name<<endl;
            if(i->name==a->name)
            {
            animate_print(i);
            }

        }
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"</circle>"<<endl;



    }
    void animate::ellipse_print(vector <animation*>n ,attribute* a )
    {
         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<ellipse cx=\""<<a->cx
             <<"\" cy=\""<<a->cy
             <<"\" rx=\""<<a->rx
             <<"\" ry=\""<<a->ry
             <<"\" fill=\""<<a->fill_color
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" >"<<endl;
             fout.close();
        for (animation* i : n )
        {
            cout<<i->name<<"  "<< a->name<<endl;
            if(i->name==a->name)
            {
            animate_print(i);
            }

        }
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"</ellipse>"<<endl;



    }
    void animate::line_print(vector <animation*>n ,attribute* a )
    {
         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<line x1=\""<<a->x1
             <<"\" y1=\""<<a->y1
             <<"\" x2=\""<<a->x2
             <<"\" y2=\""<<a->y2
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" />"<<endl;
             fout.close();
        for (animation* i : n )
        {
            cout<<i->name<<"  "<< a->name<<endl;
            if(i->name==a->name)
            {
            animate_print(i);
            }

        }
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"</line>"<<endl;



    }
    void animate::polygon_print(vector <animation*>n ,attribute* a )
    {
ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<polygon points=\""<<a->points
             <<"\" fill=\""<<a->fill_color
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" />"<<endl;
             fout.close();
        for (animation* i : n )
        {
            cout<<i->name<<"  "<< a->name<<endl;
            if(i->name==a->name)
            {
            animate_print(i);
            }

        }
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"</polygon>"<<endl;



    }
    void animate::polyline_print(vector <animation*>n ,attribute* a )
    {
         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<polyline points=\""<<a->points
             <<"\" fill=\""<<a->fill_color
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" />"<<endl;
             fout.close();
        for (animation* i : n )
        {
            cout<<i->name<<"  "<< a->name<<endl;
            if(i->name==a->name)
            {
            animate_print(i);
            }

        }
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"</polyline>"<<endl;



    }
    void animate::path_print(vector <animation*>n ,attribute* a )
    {
         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<path d=\""<<a->d
             <<"\" fill=\""<<a->fill_color
             <<"\" stroke=\""<<a->stroke
             <<"\" stroke-width=\""<<a->stroke_width
             <<"\" />"<<endl;
             fout.close();
        for (animation* i : n )
        {
            cout<<i->name<<"  "<< a->name<<endl;
            if(i->name==a->name)
            {
            animate_print(i);
            }

        }
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"</path>"<<endl;



    }
    void animate::text_print(vector <animation*>n ,attribute* a )
    {
         ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<text x=\""<<a->x
             <<"\" y=\""<<a->y
             <<"\" font-size=\""<<a->font_size
             <<"\" font-family=\""<<a->font_family
             <<"\">"<<a->txt<<"</text>"
             <<endl;
             fout.close();
        for (animation* i : n )
        {
            cout<<i->name<<"  "<< a->name<<endl;
            if(i->name==a->name)
            {
            animate_print(i);
            }

        }
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"</text>"<<endl;



    }









    void animate::animate_print (animation* a)
    {
        cout<<"animation print"<<endl;
        ofstream fout;
         fout.open("hello.txt" ,std::ios_base::app);
         fout<<"<animate attributeType=\"XML"
             <<"\" attributeName=\""<<a->attributeName
             <<"\" from=\""<<a->from
             <<"\" to=\""<<a->to
             <<"\" dur=\""<<a->dur
             <<"\" repeatCount=\""<<a->repeatCount
             <<"\"/>"
             <<endl;
             fout.close();
    }

