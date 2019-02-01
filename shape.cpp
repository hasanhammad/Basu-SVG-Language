#include<iostream>
#include<string>
#include<algorithm>
#include <vector>
#include<fstream>
#include <typeinfo>
#include"shape.h"
#include"rectangle.h"
#include"circle.h"
#include <ctime>

using namespace std ;

shape::shape ()
{

}




/**/void shape::width_print( string file)
    {
        if (base_width == 0 )
            cout<<"this photo has no width please enter a width "<<endl;
        ofstream fout;
        fout.open(file ,std::ios_base::app);
        fout << "<?xml version=\"1.0\" standalone=\"no\"?>"<<endl;
        fout<<"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\""<<endl;
        fout<<"\"\http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">"<<endl;
        fout<<"<svg width=\""<<base_width<<"\"";
        fout.close();
    }

     void shape::set_width (double width  )
     {

         base_width = width ;
     }

     void shape::set_height (double height  )
     {

         base_height = height ;
     }





/**//**/void shape::height_print( string file)
    {       if (base_height == 0 )
            cout<<"this photo has no height please enter a height "<<endl;

        ofstream fout;
        fout.open(file ,std::ios_base::app);
        //fout<<"<svg width=\""<<get_width()<<"\" height=\""<<get_height()<<\""<<endl;
        fout<<" height=\""<<base_height<<"\""<<endl;
        fout<<"xmlns=\"\http://www.w3.org/2000/svg\" version=\"1.1\">"<<endl;
        fout.close();
    }
    /**/void shape::end_print( string file )
    {
        ofstream fout;

        fout.open(file ,std::ios_base::app);

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

    void shape::tosvg (string file)
    {
        cout<<type2.size()<<"sssssssssss"<<endl;
        for (attribute* i : type1 )
        {
            if(i->type=="rectangle" && i->animate==true)
            {
                cout<<"you are ok"<<endl;
                animate n ;
                n.rect_print(type2,i,file);
            }
            if (i->type=="rectangle" && i->animate==false)
            {
                rectangle r ;
                r.tag_print(i,file);
                cout<<"reeeeee"<<endl;
            }

            if(i->type=="circle"&& i->animate==true)
            {
                 animate n ;
                n.circle_print(type2,i,file);
            }
            if(i->type=="circle"&& i->animate==false)
            {
                circle c ;
                c.tag_print(i,file);
            }
            if(i->type=="ellipse"&&i->animate==true)
            {
                 animate n ;
                n.ellipse_print(type2,i,file);
            }
            if(i->type=="ellipse"&&i->animate==false)
            {
                ellipse r ;
                r.tag_print(i,file);
                cout<<"eeeeee"<<endl;
            }
             if(i->type=="line"&&i->animate==true)
            {
                animate n ;
                n.line_print(type2,i,file);
            }
            if(i->type=="line"&&i->animate==false)
            {
                line r ;
                r.tag_print(i,file);
                cout<<"eeeeee"<<endl;
            }
            if(i->type=="polygon"&&i->animate==true)
            {
               animate n ;
                n.polygon_print(type2,i,file);
            }
             if(i->type=="polygon"&&i->animate==false)
            {
                polygon r ;
                r.tag_print(i,file);
                cout<<"pooooo"<<endl;
            }
            if(i->type=="polyline"&&i->animate==true)
            {
                animate n ;
                n.polyline_print(type2,i,file);
            }
             if(i->type=="polyline"&&i->animate==false)
            {
                polyline r ;
                r.tag_print(i,file);
                cout<<"poooooliiiii"<<endl;
            }
            if(i->type=="path"&&i->animate==true)
            {
                animate n ;
                n.path_print(type2,i,file);
            }
            if(i->type=="path"&&i->animate==false)
            {
                path r ;
                r.tag_print(i,file);
                cout<<"paaaaaaaaaaaa"<<endl;
            }
            if(i->type=="text"&&i->animate==true)
            {
                animate n ;
                n.text_print(type2,i,file);
            }
            if(i->type=="text"&&i->animate==false)
            {
                text r ;
                r.tag_print(i,file);
                cout<<"teeeeeee"<<endl;
            }
            if(i->type=="plot")
            {
                plot r ;
                r.scatter_print(i,file);
                cout<<"scaaaaaaaa"<<endl;
            }


        }



    }





    ////// rectangle
    rectangle::rectangle( )
{

}

void rectangle::tag_print(attribute* a , string file )
    {
       ofstream fout;
         fout.open(file ,std::ios_base::app);
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

    void circle::tag_print( attribute* a, string file)
    {

         ofstream fout;
         fout.open(file ,std::ios_base::app);
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

    void ellipse::tag_print( attribute* a, string file)
    {
        cout<<a->stroke<<"in classsssssss"<<endl;

         ofstream fout;
         fout.open(file ,std::ios_base::app);
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

    void line ::tag_print( attribute* a, string file)
    {

         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
    void polygon ::tag_print( attribute* a, string file)
    {

         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
    void polyline ::tag_print( attribute* a, string file)
    {

         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
    void path ::tag_print( attribute* a, string file)
    {

         ofstream fout;
         fout.open(file,std::ios_base::app);
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
    void text ::tag_print( attribute* a, string file)
    {

         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
    void animate::rect_print(vector <animation*>n ,attribute* a, string file )
    {
         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
            animate_print(i , file);
            }

        }
         fout.open(file ,std::ios_base::app);
         fout<<"</rect>"<<endl;



    }
    void animate::circle_print(vector <animation*>n ,attribute* a, string file )
    {
         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
            animate_print(i , file);
            }

        }
         fout.open(file ,std::ios_base::app);
         fout<<"</circle>"<<endl;



    }
    void animate::ellipse_print(vector <animation*>n ,attribute* a, string file )
    {
         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
            animate_print(i , file);
            }

        }
         fout.open(file ,std::ios_base::app);
         fout<<"</ellipse>"<<endl;



    }
    void animate::line_print(vector <animation*>n ,attribute* a , string file)
    {
         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
            animate_print(i, file);
            }

        }
         fout.open(file ,std::ios_base::app);
         fout<<"</line>"<<endl;



    }
    void animate::polygon_print(vector <animation*>n ,attribute* a, string file )
    {
ofstream fout;
         fout.open(file ,std::ios_base::app);
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
            animate_print(i, file);
            }

        }
         fout.open(file ,std::ios_base::app);
         fout<<"</polygon>"<<endl;



    }
    void animate::polyline_print(vector <animation*>n ,attribute* a, string file )
    {
         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
            animate_print(i, file);
            }

        }
         fout.open(file ,std::ios_base::app);
         fout<<"</polyline>"<<endl;



    }
    void animate::path_print(vector <animation*>n ,attribute* a , string file)
    {
         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
            animate_print(i, file);
            }

        }
         fout.open(file ,std::ios_base::app);
         fout<<"</path>"<<endl;



    }
    void animate::text_print(vector <animation*>n ,attribute* a, string file )
    {
         ofstream fout;
         fout.open(file ,std::ios_base::app);
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
            animate_print(i, file);
            }

        }
         fout.open(file ,std::ios_base::app);
         fout<<"</text>"<<endl;



    }









    void animate::animate_print (animation* a ,string file)
    {
        cout<<"animation print"<<endl;
        ofstream fout;
         fout.open(file ,std::ios_base::app);
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

     plot ::plot  ()
{

}
    void plot::scatter_print( attribute* a , string file)
    {

         ofstream fout;
         fout.open(file ,std::ios_base::app);



fout<<"<rect x=\""<<a->x<<"\" y=\""<<a->y<<"\" width=\""<<a->width<<"\" fill=\"white\" stroke=\"black\" stroke-width=\"5\" height=\""<<a->height<<"\" />"<<endl;
fout<<"<text y=\"20\" x=\""<<(a->width / 2) + a->x <<"\" style=\"text-anchor: middle; fill: rgb(103, 102, 102); font-size: 24px;\">"<<a->title<<"</text>"<<endl;
fout<<"<text y=\""<<a->y +a->height +10<<"\" x=\""<<a->x +10<<"\" style=\"text-anchor: middle; fill: rgb(103, 102, 102); font-size: 12px;\">0</text>"<<endl;
fout<<"<text y=\""<<a->y +a->height +10<<"\" x=\""<<a->x +20<<"\" style=\"text-anchor: middle; fill: rgb(103, 102, 102); font-size: 12px;\">1</text>"<<endl;
fout<<"<text y=\""<<a->y +a->height -10<<"\" x=\""<<a->x -5<<"\" style=\"text-anchor: middle; fill: rgb(103, 102, 102); font-size: 12px;\">1</text>"<<endl;
fout<<"<text y=\""<<a->y +a->height -20<<"\" x=\""<<a->x -5<<"\" style=\"text-anchor: middle; fill: rgb(103, 102, 102); font-size: 12px;\">2</text>"<<endl;


             fout.close();
             double xsc=0 , ysc =0; string path ;
             vector<vector<double>> fields = a-> data;
             for (auto row : fields) {
            for (int i =0 ; i < 1 ; i++) {
                    point a;
                    a.x = row[0];
                    a.y = row[1];
            points.push_back(a);

                    if (row[0]>xsc)
                    {
                        xsc=row[0];
                    }
                    if (row[1]>ysc)
                    {
                        ysc=row[1];
                    }

            }
            }
sort(points.begin(), points.end());
             xsc = (a->width-10)/xsc;
             ysc = (a->height-10)/ysc ;
for (auto row : points)
{
    path= path + shape::to_string(a->x +(row.x*xsc)) + "," + shape::to_string(a->y + (a->height -row.y*ysc)) + " ";
}

             for (auto row : fields) {
             for (int i =0 ; i < 1 ; i++)
                {

                    if (a->type1 == "scatter")
                    {
                       print_circle(a->x +(row[0]*xsc),a->y + (a->height -row[1]*ysc) , file);

                    }



                }


                                    }
                    if (a->type1 == "line")
                    {
                        print_polyline(path , file);
                    }




    }

    void plot::print_circle(double x , double y ,string file )
    {srand((unsigned)time(0));
        cout<<"circle print "<<endl;
        ofstream fout;
         fout.open(file ,std::ios_base::app);
         fout<<"<circle r=\""<<"3"
             <<"\" cx=\""<<x
             <<"\" cy=\""<<y
             <<"\" fill=\""<<"rgb("<<ran_num(255)<<", "<<ran_num(255)<<", "<<ran_num(255)<<")"
             <<"\" />"<<endl;
             fout.close();
    }

    void plot::print_polyline(string path , string file)
    {srand((unsigned)time(0));
        ofstream fout;
         fout.open(file ,std::ios_base::app);
         fout<<"<polyline points=\""<<path
             <<"\" fill=\""<<"none"
             <<"\" stroke=\""<<"rgb("<<ran_num(255)<<", "<<ran_num(255)<<", "<<ran_num(255)<<")"
             <<"\" stroke-width=\""<<"2"
             <<"\" />"<<endl;
             fout.close() ;
    }

      int plot::ran_num (int x ) //  return a random number
    {
        int i;
        i = (rand()%x);

        return i ;
    }

