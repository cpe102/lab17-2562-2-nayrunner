#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <stdio.h>
#include <ctype.h>
using namespace std;

string upper(string a) 
{  int i=0;
    while (a[i])
  {
    a[i]=toupper(a[i]);
    i++;
  }
  return a;
} 

int main(){

    ifstream onepiece("name_score.txt");

    vector<string> Vname,Vgrade;
    string s;
    int first , second , third, i=0;
    double total;
    char name[100];
    char Grade[100];
    string grade;

    while(getline(onepiece,s)){

        sscanf(s.c_str(),"%[^:] : %d %d %d",name,&first,&second,&third);
        Vname.push_back(name);

        total= first + second + third;
        if(total>=80){grade ="A";}
        else if(total>=70){grade="B";}
        else if(total>=60){grade="C";}
        else if(total>=50){grade="D";}
        else {grade="F";}
         
        Vgrade.push_back(grade);


   }


while(1){
    string command , Upvgrade;
    char type[100] , input[100];

    cout<<"Please input your command :";
    getline(cin,command);
    
    command= upper(command);
    
    
    int idx = command.find_first_of(" ");
    string s1 = command.substr(0,idx);
    string s2 = command.substr(idx+1,command.size());


    if(s1 == "NAME"){
        int end=0;
        for(int j=0; j<Vname.size();j++){
            if(s2 == upper(Vname[j])){
                cout<<"-----------------------------------------------"<<"\n";
                cout<<Vname[j]<<"'s grade = "<<Vgrade[j]<<"\n"<<"-----------------------------------------------\n";
            }else{end++;}
        }
        if(end==Vname.size()){
             cout<<"-----------------------------------------------"<<"\n";
             cout<<"Cannot found"<<"\n";
             cout<<"-----------------------------------------------"<<"\n";
        }
    }

 if(s1 =="GRADE"){
     int end=0;
        cout<<"-----------------------------------------------"<<"\n";
        for(int j=0; j<Vname.size();j++){
            if(s2 == upper(Vgrade[j])){
                
                cout<<Vname[j]<<"\n";
               
            }else{end++;}
        }
        if(end==Vname.size()){
             
             cout<<"Cannot found"<<"\n";
            
        }

        cout<<"-----------------------------------------------"<<"\n";
    }

    if(s1 == "EXIT"){
        break;
    }

    if(s1 != "NAME" & s1 != "GRADE" &s1 != "EXIT"){cout<<"Invalid command"<<"\n";}

    






}


}
