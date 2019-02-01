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


using namespace std ;





string cut (string line )

{  string str;
int j[2]  ;
int k = 0 ;

    for(int  i = 0;i < line.length();i++)
{
    if(line[i] == '"')
    {
        j[k++]=i;
        str = line.substr (j[0]+1 , j[1]-j[0]-1  );

    }

}

return str ;
}

string cut1 (string line )

{  string str , t;
   bool ok =true;
    for(int  i = 0;i < line.length();i++)
{
    if(line[i] == '(')
    {
        cout<<"ooooooooook"<<endl;
        str = line.substr (i+1 , line.length()-i -2  );
        ok =false;


    }



}
if (str == t)
    {
        return line ;
    }
else
return str ;
}

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

std::cout<<"haha"<<std::endl;
         return new attribute(name) ;



    //if (name == "Enemy") return new Enemy();

    return NULL;
}

 animation* create_animate( std::string name , std::string type ,std::string name1 )
{
    //if (name == "hasan")

std::cout<<"haha1"<<std::endl;
         return new animation(name , type ,name1) ;



    //if (name == "Enemy") return new Enemy();

    return NULL;
}


vector<vector<double>> read_file (string file)
{ string path = "F:\\project\\sort\\Basu_SVG_Language\\data\\"+file;
cout<<path<<endl;
    ifstream in(path);

    if (in.good())
    {
        vector<vector<double>> fields;
    if (in) {
        string line;
        while (getline(in, line)) {
            stringstream sep(line);
            string field;
            fields.push_back(vector<double>());
            while (getline(sep, field, ',')) {
                fields.back().push_back(stod(field));
            }
        }
    }
    for (auto row : fields) {
                                     for (int i =0 ; i < 1 ; i++) {
                                            cout << "x="<<row[0]<<"y="<<row[1] << ' ';
                                     }}
    return fields;
    }
    else
    {
        cout<<"ther is no file"<<endl;
           vector<vector<double>> fields ;
           return fields;
    }


}






int main()
{

animate n ;




    string objects[] = {"rectangle","circle","ellipse","line","polygon","polyline","path","text","plot" };
     string names[] = {"create","CREATE","set","SET","get","GET","list","LIST","clear","CLEAR","animation","ANIMATION","export","EXPORT"};
     vector <string > name1 ;
     std::vector <attribute*> type;
     std::vector <animation*> animate;


    shape shape;


    string line ;
    while (getline(cin , line ))
    {
        bool correct = false ;
string arr[6]={"0","0","0","0","0","0"};
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < 5)
        {
        ssin >> arr[i];
       // arr[i] = cut1(arr[i]);



        ++i;
        }



//print
        if (arr[0]=="export")

        {
            correct = true;
             if (arr[2]!= "0")
                    cout<<"the statement that you have entered is wrong :"<<endl;

            string file ="F:\\project\\sort\\Basu_SVG_Language\\export\\" + cut1(line) ;
            cout<<file<<endl;
            for (animation* i : animate )
            n.final_vector_animate(i);

            for (animation* i : animate )
            shape.final_vector_animate(i);

            for (attribute* i : type )
            shape.final_vector(i);
            cout<<type.size()<<"vector size"<<endl;

         shape.width_print(file) ;
         shape.height_print(file) ;
            shape.tosvg (file);


            shape.end_print(file);

        }
        ////
else if (arr[0]=="exit")
{correct = true;
    if (arr[1]!= "0")
    cout<<"the statement that you have entered is wrong :"<<endl;
    exit (0);
}

// set statement

       else if (arr[0] == "set" && arr[1]=="width")
        {  correct = true;
            if (arr[3]!= "0")
           cout<<"the statement that you have entered is wrong :"<<endl;

            shape.set_width(stod(arr[2]));


        }
       else if (arr[0] == "set" && (arr[1]=="height"))
        { correct = true;
              if (arr[3]!= "0")
            cout<<"the statement that you have entered is wrong :"<<endl;
            shape.set_height(stod(arr[2])) ;

        }
// set statement end //

       else if (arr[0] == "create"  )
        {correct = true;
         bool ok = true ;

            for (string i : names )
            if (i.find(arr[2], 0) != std::string::npos)
            {
                cout<<"please choose another name "<<endl;
                ok= false ;
                break;
            }
             for (attribute* i : type )
             if(i->name == (arr[2]))
             { cout<<"please choose another name "<<endl;
                 ok= false ;
                  break;
             }


             if (arr[3]!= "0")
                    cout<<"the statement that you have entered is wrong :"<<endl;
            //sort(objects.begin(),objects.end());
            //bool fn = binary_search(objects.begin(),objects.end(),arr[1]);
            bool okay = false ;
            for (string i : objects )
            {
                okay = i.find(arr[1], 0) != std::string::npos &&ok;
                if (okay==true )
                    break;
            }
            if (okay ==  false)
            {

         cout<<"the statement that you have entered is wrong :"<<endl;
            }
            if (okay)
            { cout <<"ooooook"<<endl;



                if (arr[1]=="rectangle")
                {
                    attribute* a = create (arr[2]) ;
                    type.push_back(a) ;
                    cout<<"good1"<<endl;
                    for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="rectangle" ;


                }


               else if (arr[1]=="circle")
               {
                    attribute* a = create (arr[2]) ;
                    type.push_back(a) ;

                   for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="circle" ;

               }
               else if (arr[1]=="ellipse")
                {
                     attribute* a = create (arr[2]) ;
                    type.push_back(a) ;

                    for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="ellipse" ;

                }
                else if (arr[1]=="line")
                {
                     attribute* a = create (arr[2]) ;
                    type.push_back(a) ;

                    for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="line" ;

                }
                else if (arr[1]=="polygon")
                {
                     attribute* a = create (arr[2]) ;
                    type.push_back(a) ;

                    for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="polygon" ;

                }
                else if (arr[1]=="polyline")
                {
                     attribute* a = create (arr[2]) ;
                    type.push_back(a) ;

                    for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="polyline" ;

                }
                 else if (arr[1]=="path")
                {
                     attribute* a = create (arr[2]) ;
                    type.push_back(a) ;

                    for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="path" ;

                }
                 else if (arr[1]=="text")
                {
                     attribute* a = create (arr[2]) ;
                    type.push_back(a) ;

                    for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="text" ;

                }
                 else if (arr[1]=="plot")
                {
                    cout<<"plot"<<endl;
                     attribute* a = create (arr[2]) ;
                    type.push_back(a) ;

                    for (attribute* i : type )
                        if(i->name == (arr[2]))
                    i->type ="plot" ;
                    cout<<"plot ok"<<endl;

                }





        }


        }
//end create

 else if (arr[0]=="animation")
                      {correct = true;
                           if (arr[3]!= "0")
                          cout<<"the statement that you have entered is wrong :"<<endl;
                          cout<<"ok"<<endl;
                          for (attribute* i : type )
                          if(i->name == (arr[1]))
                          {
                               animation* n = create_animate(i->name , i->type , arr[2]) ;
                               animate.push_back(n) ;

                              i->animate = true ;
                              cout<<"true"<<endl;


                          }




                      }

//////////

else if (arr[0]=="clear")
{ correct = true;
 bool ok = false ;
 bool ok1 = false ;

    int cnt =0 , cnt1=0;
bool Clear = true ;
     for (animation* i : animate )
     {
         if (arr[2]==i->name1 && arr[1]==i->name)
         {  ok = true ;
             animate.erase(animate.begin()+ cnt );
             Clear = true ;
             break;
         }

         cnt++;
     }
     for (attribute* i : type )
     {cout<<"clear"<<endl;
         if (arr[1]== i->name && Clear)
         {
             ok1 = true;
             type.erase(type.begin()+ cnt1 );
         }




         cnt1++;
     }
     if (ok==false &&ok1==false)
     {
         cout<<"the statement that you have entered is wrong :"<<endl;
     }
}




/////////////////



         else   if (arr[0] == "clear" && arr[1]=="all")
           {
               correct = true;
                  if (arr[2]!= "0")
                    cout<<"the statement that you have entered is wrong :"<<endl;

               type.clear();
           }




                      ///////

          else if (arr[0] == "list" && arr[2]=="0")
           {
               correct = true;
               if (arr[3]!= "0")
                cout<<"the statement that you have entered is wrong :"<<endl;
                for (attribute* i : type )
                      cout<<" name : "<<i->name<<" , "<<" type : "<<i->type<<endl;

           }

        else if (arr[0] == "list" && arr[1]=="animate")
           {
               correct = true;
               if (arr[3]!= "0")
            cout<<"the statement that you have entered is wrong :"<<endl;
                for (animation* i : animate )
                      if (arr[2]==i->name)
                      {
                          cout<<i->name1<<endl;
                      }

           }










                      /////
   else if (arr[0] == "get")
        {correct = true;
                    if (arr[3]!= "0")
                    cout<<"the statement that you have entered is wrong :"<<endl;



                  if (arr[2]=="x")
                  {
                      for (attribute* i : type )
                      if(i->name == (arr[1]))
                      cout<<i->x<<endl;


                  }
                  if (arr[2]=="y")
                  {
                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->y<<endl;
                  }
                  if (arr[2]=="width")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                     cout<<i->width<<endl;

                  }
                  if (arr[2]=="height")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->height<<endl;

                  }
                  if (arr[2]=="fill")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->fill_color<<endl;
                  }
                  if (arr[2]=="stroke_width" )
                  {
                      cout<<"yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy"<<endl;

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                    // i->stroke_width=stod(arr[4]);
                    cout<<i->stroke_width<<endl;

                  }
                   if (arr[2]=="stroke")
                  {
cout<<"stroke "<<endl;
                       for (attribute* i : type )
                        if(i->name == (arr[1]))
                     cout<<i->stroke<<endl;


                  }

                   if (arr[2]=="opacity")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                    cout<<i->opacity<<endl;

                  }
                   if (arr[2]=="rx")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                     cout<<i->rx<<endl;

                  }
                   if (arr[2]=="ry")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                     cout<<i->ry<<endl;

                  }

                   if (arr[2]=="cx")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                     cout<<i->cx<<endl;

                  }
                  if (arr[2]=="cy")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->cy<<endl;

                  }
                   if (arr[2]=="r")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->r<<endl;
                  }
                  if (arr[2]=="x1")
                  {
                       for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->x1<<endl;

                  }
                   if (arr[2]=="x2")
                  {
                       for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->x2<<endl;

                  }
                   if (arr[2]=="y1")
                  {
                       for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->y1<<endl;

                  }
                   if (arr[2]=="y2")
                  {
                       for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->y2<<endl;

                  }
                   if (arr[2]=="points")
                  {
                       for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->points<<endl;



                  }
                  if (arr[2]=="d")
                  {
                       for (attribute* i : type )
                        if(i->name == (arr[1]))
                      cout<<i->d<<endl;



                  }
                   if (arr[2]=="font"&&arr[3]=="size")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                     cout<<i->font_size<<endl;


                  }
                    if (arr[2]=="font"&&arr[3]=="family")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))

                     cout<<i->font_family<<endl;



                  }
                  if (arr[2]=="txt")
                  {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                     cout<<i->txt<<endl;



                  }

                   if (arr[3]=="dur")
                              {
                        for (animation* i : animate )
                        if(i->name == (arr[1]))
                                 cout<<i->dur<<endl;

                              }
                              if (arr[3]=="attributeName")
                              {
 for (animation* i : animate )
                        if(i->name == (arr[1]))
                                 cout<<i->attributeName<<endl;

                              }

                               if (arr[3]=="from")
                              {
 for (animation* i : animate )
                        if(i->name == (arr[1]))
                                 cout<<i->from<<endl;

                              }
                               if (arr[3]=="to")
                              {
 for (animation* i : animate )
                        if(i->name == (arr[1]))
                                 cout<<i->to<<endl;

                              }
                              if (arr[3]=="repeatCount")
                              {
 for (animation* i : animate )
                        if(i->name == (arr[1]))
                                 cout<<i->repeatCount<<endl;

                               }
                               if (arr[2]=="title")
                               {
 for (attribute* i : type )
                        if(i->name == (arr[1]))
                                  cout<<i->title<<endl;



                                }
                                 if (arr[2]=="type")
                               {

 for (attribute* i : type )
                        if(i->name == (arr[1]))
                                  cout<<i->type1<<endl;



                                }

                                  if (arr[2]=="data")
                               {



                        for (attribute* i : type )
                        if(i->name == (arr[1])) {
                                     vector<vector<double>> fields = i -> data;
                                     for (auto row : fields) {
                                     for (int i =0 ; i < 1 ; i++) {
                                            cout << "x = "<<row[0]<<" y = "<<row[1] << ' ';
                                     }
                                     cout << '\n';
                                     }
                               }

                                }

       }






// set



       else if (arr[0] == "set")
        {
            correct = true;
             if (arr[4]!= "0")
             cout<<"the statement that you have entered is wrong :"<<endl;


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
                   if (arr[2]=="stroke")
                  {

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                        {
                            i->stroke=arr[3];
                     cout<<i->stroke<<endl;
                        }


                  }
                   if (arr[2]=="stroke_width" )
                  {
                      cout<<"yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy"<<endl;

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                        {
                             i->stroke_width=stod(arr[3]);
                     cout<<i->stroke_width<<endl;
                        }


                  }
                   if (arr[2]=="opacity")
                  {

                     for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->opacity=stod(arr[3]);

                  }
                   if (arr[2]=="rx")
                  {

                     for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->rx=stod(arr[3]);

                  }
                   if (arr[2]=="ry")
                  {

                     for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->ry=stod(arr[3]);

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
                  if (arr[2]=="x1")
                  {
                      cout<<"x"<<endl;
                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->x1=stod(arr[3]);

                  }
                   if (arr[2]=="x2")
                  {
                      cout<<"x"<<endl;
                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->x2=stod(arr[3]);

                  }
                   if (arr[2]=="y1")
                  {
                      cout<<"x"<<endl;
                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->y1=stod(arr[3]);

                  }
                   if (arr[2]=="y2")
                  {
                      cout<<"x"<<endl;
                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                      i->y2=stod(arr[3]);

                  }
                   if (arr[2]=="points")
                  {
                      line = cut(line);
                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                            i->points=line;



                  }
                  if (arr[2]=="d")
                  {
                      line = cut(line);
                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                            i->d=line;



                  }
                   if (arr[2]=="font"&&arr[3]=="size")
                  {

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                        {
                            i->font_size=stod(arr[4]);
                     cout<<i->font_size<<endl;
                        }


                  }
                    if (arr[2]=="font"&&arr[3]=="family")
                  {

                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                        {
                            i->font_family=arr[4];
                     cout<<i->font_family<<endl;
                        }


                  }
                  if (arr[2]=="txt")
                  {
                          line = cut(line);
                      for (attribute* i : type )
                        if(i->name == (arr[1]))
                        {
                            i->txt=line;
                     cout<<i->txt<<endl;
                        }


                  }

                   if (arr[3]=="dur")
                              {
                                  for (animation* i : animate )
                                    if(i->name == (arr[1] ) && i->name1 == (arr[2] ))
                                    {
                                        i->dur=arr[4];
                                 cout<<i->dur<<endl;
                                    }
                              }
                              if (arr[3]=="attributeName")
                              {
                                  for (animation* i : animate )
                                    if(i->name == (arr[1] ) && i->name1 == (arr[2] ))
                                    {
                                        i->attributeName=arr[4];
                                 cout<<i->attributeName<<endl;
                                    }
                              }

                               if (arr[3]=="from")
                              {
                                  for (animation* i : animate )
                                    if(i->name == (arr[1] ) && i->name1 == (arr[2] ))
                                    {
                                        i->from=stod(arr[4]);
                                 cout<<i->from<<endl;
                                    }
                              }
                               if (arr[3]=="to")
                              {
                                  for (animation* i : animate )
                                    if(i->name == (arr[1] ) && i->name1 == (arr[2] ))
                                    {
                                        i->to=stod(arr[4]);
                                 cout<<i->to<<endl;
                                    }
                              }
                              if (arr[3]=="repeatCount")
                              {
                                  for (animation* i : animate )
                                    if(i->name == (arr[1] ) && i->name1 == (arr[2] ))
                                    {
                                        i->repeatCount=arr[4];
                                 cout<<i->repeatCount<<endl;
                                    }



                               }
                               if (arr[2]=="title")
                               {
                                line = cut(line);
                                for (attribute* i : type )
                                if(i->name == (arr[1]))
                                {
                                    i->title=line;
                                  cout<<i->title<<endl;
                                }


                                }
                                 if (arr[2]=="type")
                               {

                                for (attribute* i : type )
                                if(i->name == (arr[1]))
                                {
                                    i->type1=arr[3];
                                  cout<<i->type1<<endl;
                                }


                                }

                                  if (arr[2]=="data")
                               {



                                for (attribute* i : type )
                                if(i->name == (arr[1]))
                                {
                                    cout<<arr[3]<<endl;
                                    try { read_file(arr[3]); }
                                    catch (...) { std::cout << "an unknown exception was caught\n"; }
                                    i->data= read_file(arr[3]);
                                    cout<<arr[3]<<endl;
                                     vector<vector<double>> fields = i -> data;
                                     for (auto row : fields) {
                                     for (int i =0 ; i < 1 ; i++) {
                                            cout << "x="<<row[0]<<"y="<<row[1] << ' ';
                                     }}

                                }


                                }




    }

if (correct==false )
cout <<"there is no statement like this :"<<endl;

    }

    return 0;
}
