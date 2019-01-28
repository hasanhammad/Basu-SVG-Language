#include<iostream>
#include<string>
#include<fstream>
#include <algorithm>
#include <vector>
#include "rectangle.h"
#include"circle.h"
#include"shape.h"
#include <stdlib.h>
#include <sstream>
#include<array>
#include <iterator>
#include"Basu_SVG_Language.h"



double stod ( std::string Text )//Text not by const reference so that the function can be used with a
{                               //character array as argument
std::stringstream ss(Text);
	double result;
	return ss >> result ? result : 0;
}


  int fond(std::vector<attribute> type , std::vector<std::string>name1 , std::string a )
  {
    sort(name1.begin(),name1.end());
    bool fn = binary_search(name1.begin(),name1.end(),a);
    if (fn ==  true )
    {
        for (int i =0 ; i <type.size();i++ )
        {
            if (type[i].name == a)
             return i ;
        }
    }

  }

  attribute* create( std::string name)
{
    //if (name == "hasan")


         return new attribute(name) ;



    //if (name == "Enemy") return new Enemy();

    return NULL;
}
using namespace std ;






int main()
{


//shape prect = new rectangle() ;
//prect.tag_print();


    vector <string > objects = {"rectangle","circle"};
     vector <string > name1 ;
     std::vector <attribute*> type;

      vector <string >details = {"x","y","fill","width","height","r"};
    shape shape;
     string arr[4];
    string line ;
    while (getline(cin , line ))
    {
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 4)
        {
        ssin >> arr[i];
        ++i;
        }

        // set statement

        if (arr[0]=="print")
        {
            for (attribute* i : type )
            shape.final_vector(i);

            shape.tosvg ();
            shape.end_print();
        }



        if (arr[0] == "set" && arr[1]=="width")
        {

            shape.width_print(stod(arr[2]));


        }
        if (arr[0] == "set" && (arr[1]=="height"))
        {
            shape.height_print(stod(arr[2])) ;

        }
        // set statement end //
        if (arr[0] == "create"  )
        {cout<<"good"<<endl;



            sort(objects.begin(),objects.end());
            bool fn = binary_search(objects.begin(),objects.end(),arr[1]);
            if (fn == true )
            {

                cout<<"good1"<<endl;


                if (arr[1]=="rectangle")
                {
                    type.push_back(create (arr[2])) ;

                    for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="rectangle" ;




                }

                name1.push_back(arr[2]);
               if (arr[1]=="circle")
               {
                   type.push_back(create (arr[2])) ;
                   for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="circle" ;

               }







        }

        }




        if (arr[0] == "set")
        {


                  if (arr[2]=="x")
                  {
                      cout<<"x"<<endl;
                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->x=stod(arr[3]);

                  }
                  if (arr[2]=="y")
                  {

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->y=stod(arr[3]);

                  }
                  if (arr[2]=="width")
                  {

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->width=stod(arr[3]);

                  }
                  if (arr[2]=="height")
                  {

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->height=stod(arr[3]);

                  }
                  if (arr[2]=="fill")
                  {

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->fill_color=arr[3];

                  }
                   if (arr[2]=="cx")
                  {

                     for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->cx=stod(arr[3]);

                  }
                  if (arr[2]=="cy")
                  {

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->cy=stod(arr[3]);

                  }
                   if (arr[2]=="r")
                  {

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->r=stod(arr[3]);

                  }








            }








      for(unsigned int i = 0; i < type.size(); ++i) {

                      cout<<"new idea "<<type[i]->name<<type[i]->type<<type[i]->x<<endl;


                      }


       }











    return 0;
}
