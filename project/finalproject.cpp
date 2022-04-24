#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctime>
#include<string>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<cctype>
#include<windows.h>
#include"admin.h"
#include"facilities.h"
#include"offers.h"
#include"user.h"
#include"show_record.h"
using namespace std;
void user::show_menu()
{
    string a;
    fstream f1("main_menu.txt",ios::in);
    while(getline(f1,a))
    {
        cout<<a<<endl;
    }
    f1.close();
}
void user::bill(string names)
{
    string strData,a,b,x,v,h,m,j,d;
    fstream search("book.txt",ios::in);
    int lines=3;
    ifstream inf( "main_menu.txt" );
    while(!search.eof())
    {
        getline(search,v);
        getline(search,h);
        getline(search,j);
        getline(search,m);
        getline(search,d);
        if (v==names)
        {
            cout<<"Your Name Is: "<<v<<endl;
            cout<<"Your Room Type is: "<<d<<endl;
            if (d=="Luxury Room")
            {
                inf.seekg(155);
                getline(inf, strData);
                cout << "Your Bill Is:"<<strData << '\n'; 
            }
            else if(d=="Elite Room")
            {
                 inf.seekg(195);
                getline(inf, b);
                cout <<"Your Bill Is:"<< b << '\n';  
            }
            else if (d=="Economy Room")
            {
                inf.seekg(235);
                getline(inf, a);
                cout <<"Your Bill Is:"<< a << '\n'; 
            }
            else if(d=="Basic Room")
            {
                inf.seekg(275);
                getline(inf, x);
                cout <<"Your Bill Is:"<< x << '\n'; 
            }
            else
            {
                cout<<"No more rooms!"<<endl; }  
        }  
         else 
            {
                cout<<"\tThank You For Visiting Our Hotel!!"<<endl; 
            }  
    }
    search.close();
    inf.close();
}
void user::bill(int rmno)
{
    string s,strData,a,e,b,x,v,h,m,j,d,z;
    int l;
    ifstream boo("book2.txt");
    ifstream inf( "main_menu.txt" );
    while (boo>>l)
    {
        getline(boo,e);
        getline(boo,j); getline(boo,h); getline(boo,z); getline(boo,m); getline(boo,d);
        if (l==rmno)
        {
            system("CLS");
            cout<<"Your Room Number Is: "<<l<<endl;
            cout<<"Your Name Is: "<<j<<endl;
            cout<<"Your Room Type is: "<<d<<endl;
            if (d=="Luxury Room")
            {
                inf.seekg(155);
                getline(inf, strData);
                cout << "Your Bill Is:"<<strData<<" PKR" << '\n';
            }
            else if(d=="Elite Room")
            {
                 inf.seekg(195);
                getline(inf, b);
                cout <<"Your Bill Is:"<< b <<" PKR" << '\n';
            }
            else if (d=="Economy Room")
            {
                inf.seekg(235);
                getline(inf, a);
                cout <<"Your Bill Is:"<< a<<" PKR"  << '\n';
            }
            else if(d=="Basic Room")
            {
                inf.seekg(275);
                getline(inf, x);
                cout <<"Your Bill Is:"<< x<<" PKR"  << '\n';
            }
            else
            {
                cout<<"No more rooms!"<<endl;
            }
            break;
        }
        else{
        cout<<"There is no room booked with your Room Number!"<<endl;}
    }
    inf.close();
    boo.close();

}
int user::main_menu()
{
    string za;
    fstream s3("book2.txt",ios::app);
    fstream show("main_menu.txt",ios::in);
    while (!show.eof())
    {  
       getline(show,za);
       cout<<za<<endl; 
    }
    show.close();
    int a,b,c,d;
    fstream f1;
    f1.open("numbers.txt",ios::app|ios::in);
    f1>>a>>b>>c>>d;
    w=a;
    x=b;
    y=c;
    z=d;
    int e;
    cout<<"Rooms:\t\t\t\t|Luxury Room\t\t|Elite Room\t|Economy Room\t|Basic Room"<<endl;
    cout<<"Total No of Rooms:\t\t|1-50\t\t\t|50-100\t\t|100-150\t|150-200"<<endl;
    cout<<"No of Rooms Available:\t\t|"<<w<<"\t\t\t|"<<x<<"\t\t|"<<y<<"\t\t|"<<z<<endl;
    f1.close();
    fstream f2;
    fstream f;
    f.open("book.txt",ios::app);
    f2.open("numbers.txt",ios::out|ios::in); cout<<endl;
    cin>>e;
   switch (e)
    {
    case 1:
        if (w>0&&w<=50)
        {
            cout<<"\nRoom no is: "<<w<<endl; s3<<w<<endl;
            w=w-1;
            f2<<w<<endl;f2<<x<<endl; f2<<y<<endl; f2<<z<<endl; 
            cout<<"Room is Available!"<<endl; 
            cout<<"\nEnter Customer Detalis"<<endl;
	        cout<<"Name: ";
            cin>>name;
	        f<<name<<endl; s3<<name<<endl;
	        cout<<"City of Residence: "; cin>>city;
	        f<<city<<endl; s3<<city<<endl;
	        cout<<"Phone No: "; 
            cin>>phone_no;
            cout<<"CNIC: "; cin>>cnic; f<<cnic<<endl; s3<<cnic<<endl;
	        f<<phone_no<<endl<<"Luxury Room"<<endl;
            s3<<phone_no<<endl<<"Luxury Room"<<endl;
	        cout<<"\nThe Luxury Room has been booked!!!"<<endl;
            return w;
        }
        else
        cout<<"Sorry!! There are no rooms left: "<<endl;
        break;
    case 2:
        if (x>50&&x<=100)
        {
            cout<<"\nRoom no is: "<<x<<endl; s3<<x<<endl;
            x=x-1;
            f2<<w<<endl;f2<<x<<endl; f2<<y<<endl; f2<<z<<endl;  
           cout<<"Room is Available!"<<endl; 
            cout<<"\nEnter Customer Detalis"<<endl;
	        cout<<"Name: ";
            cin>>name;
	        f<<name<<endl; s3<<name<<endl;
	        cout<<"City of Residence: "; cin>>city;
	        f<<city<<endl; s3<<city<<endl;
	        cout<<"Phone No: "; 
            cin>>phone_no;
            cout<<"CNIC: "; cin>>cnic; f<<cnic<<endl; s3<<cnic<<endl;
	        f<<phone_no<<endl<<"Elite Room"<<endl;
            s3<<phone_no<<endl<<"Elite Room"<<endl;
	        cout<<"\nThe Elite Room has been booked!!!"<<endl;
            return w;
        }
        else
        cout<<"Sorry!! There are no rooms left: "<<endl;
        break;
    case 3:
        if (y>100&&y<=150)
        {
            cout<<"\nRoom no is: "<<y<<endl; s3<<y<<endl;
            y=y-1;
            f2<<w<<endl;f2<<x<<endl; f2<<y<<endl; f2<<z<<endl;
            cout<<"Room is Available!"<<endl; 
            cout<<"\nEnter Customer Detalis"<<endl;
	        cout<<"Name: ";
            cin>>name;
	        f<<name<<endl; s3<<name<<endl;
	        cout<<"City of Residence: "; cin>>city;
	        f<<city<<endl; s3<<city<<endl;
	        cout<<"Phone No: "; 
            cin>>phone_no;
            cout<<"CNIC: "; cin>>cnic; f<<cnic<<endl; s3<<cnic<<endl;
	        f<<phone_no<<endl<<"Economy Room"<<endl;
            s3<<phone_no<<endl<<"Economy Room"<<endl;
	        cout<<"\nThe Economy Room has been booked!!!"<<endl;
            return w;
        }
        else
        cout<<"Sorry!! There are no rooms left: "<<endl;
        break;
    case 4:
        if (z>150&&z<=200)
        {
            cout<<"\nRoom no is: "<<z<<endl; s3<<z<<endl;
            z=z-1;
            f2<<w<<endl;f2<<x<<endl; f2<<y<<endl; f2<<z<<endl;
            cout<<"Room is Available!"<<endl; 
            cout<<"\nEnter Customer Detalis"<<endl;
	        cout<<"Name: ";
            cin>>name;
	        f<<name<<endl; s3<<name<<endl;
	        cout<<"City of Residence: "; cin>>city;
	        f<<city<<endl; s3<<city<<endl;
	        cout<<"Phone No: "; 
            cin>>phone_no;
            cout<<"CNIC: "; cin>>cnic; f<<cnic<<endl; s3<<cnic<<endl;
	        f<<phone_no<<endl<<"Basic Room"<<endl;
            s3<<phone_no<<endl<<"Basic Room"<<endl;
	        cout<<"\nThe Basic Room has been booked!!!"<<endl;
            return w;
        }
        else
        cout<<"Sorry!! There are no rooms left: "<<endl;
        break;
    default:
        cout<<"Wrong choice!! "<<endl;
        break;
    }
    f2.close();
    f.close();
    s3.close();
}
void user::complaint()
{
    system("CLS");
    string complain;
	cout<<"Enter your Complain: "<<endl;
    cin.ignore();
	getline(cin,complain);
	fstream out;
	out.open("complain.txt",ios::app);
	out<<complain<<endl;
	out.close();
    cout<<"\nData written successfully...";
    cout<<"Thanks for your feedback we will try to better our services!"<<endl;
}
void user::events()
{
    system("CLS");
    fstream in("events.txt",ios::in);
    int ab,ca;
    char a; 
    cout<<"Do you want to book an event in our Hotel?(Press 'y' for yes)"<<endl;
    cin>>a;
    in>>ab;
    in.close();
    ofstream ax("events.txt");
    if (a=='y')
    {
        
        if (ab>0)
        {
            ab--;
            ax<<ab<<endl;
            cout<<"Total no of rooms left: "<<ab<<endl;
            cout<<"Place has been booked Successfully"<<endl;
        }
        else{
        cout<<"Total no of rooms left: "<<ab<<endl;
        cout<<"All places are booked!"<<endl;}
        
    }
    else
    {
        cout<<"Thank you for visiting our hotel!"<<endl;
    }    
    ax.close();
}
void user::cab_services()
{
    system("CLS");
    ifstream t("totalcabs.txt");
    fstream customer("cab_record.txt",ios::app);
    int c; t>>c; t.close();
    ofstream d("totalcabs.txt");
    cout<<"Welcome to Cab Services"<<endl;
    cout<<"1.Airport to Hotel\n2.Hotel to Airport\n3.Railway Station to Hotel\n4.Hotel to Railway Station"<<endl;
    int price=10,a,a2,km=150; cin>>a; char b;  string name; string phone,cnic; 
    switch (a)
    {
    case 1:
        cout<<"Do you want to Book a Ride?('y' for yes)"<<endl; cin>>b;
        if (b=='y')
        {
            cout<<"No of Cabs left!"<<c<<endl;
            if (c>0)
            {
                cout<<"Your cab no is:"<<c<<endl;
                c--; d<<c<<endl;
                cout<<"Please Enter Details"<<endl;
                cout<<"Enter your Name: "<<endl;  cin>>name; customer<<"Name:"<<name<<endl;
                cout<<"Enter your Phone No: "<<endl; cin>>phone; customer<<"Phone:"<<phone<<endl;
                cout<<"Enter your CNIC: "<<endl; cin>>cnic; customer<<"CNIC:"<<cnic<<endl;
                cout<<"Total KMs are:"<<km<<" km"<<endl; customer<<"Total KMs are:"<<km<<" km"<<endl;
                cout<<"Price per KM is "<<price<<" Rs"<<endl; customer<<"Price:"<<price<<endl;
                cout<<"Thank You for choosing this Hotel!\nYour Cab Is Booked!"<<endl;
                price=km*price; customer<<"BILL:"<<price<<endl<<endl;
            }
            else
            {
                cout<<"There is no cab available currently!"<<endl; 
            } 
        }
        else
        {
            cout<<"Thank you for visiting Cab Services!"<<endl;
        }
        break;
    case 2:
        cout<<"Do you want to Book a Ride?('y' for yes)"<<endl; cin>>b;
        if (b=='y')
        {
            cout<<"No of Cabs left!"<<c<<endl;
            if (c>0)
            {
                cout<<"Your cab no is:"<<c<<endl;
                c--; d<<c<<endl;
                cout<<"Please Enter Details"<<endl;
                cout<<"Enter your Name: "<<endl;  cin>>name; customer<<"Name:"<<name<<endl;
                cout<<"Enter your Phone No: "<<endl; cin>>phone; customer<<"Phone:"<<phone<<endl;
                cout<<"Enter your CNIC: "<<endl; cin>>cnic; customer<<"CNIC:"<<cnic<<endl;
                cout<<"Total KMs are:"<<km<<" km"<<endl; customer<<"Total KMs are:"<<km<<" km"<<endl;
                cout<<"Price per KM is "<<price<<" Rs"<<endl; customer<<"Price:"<<price<<endl;
                cout<<"Thank You for choosing this Hotel!\nYour Cab Is Booked!"<<endl;
                price=km*price; customer<<"BILL:"<<price<<endl<<endl;
            }
            else
            {
                cout<<"There is no cab available currently!"<<endl; 
            } 
        }
        else
        {
            cout<<"Thank you for visiting Cab Services!"<<endl;
        }
        break; 
    case 3:
        km=250;
        cout<<"Do you want to Book a Ride?('y' for yes)"<<endl; cin>>b;
        if (b=='y')
        {
            cout<<"No of Cabs left!"<<c<<endl;
            if (c>0)
            {
                cout<<"Your cab no is:"<<c<<endl;
                c--; d<<c<<endl;
                 cout<<"Please Enter Details"<<endl;
                cout<<"Enter your Name: "<<endl;  cin>>name; customer<<"Name:"<<name<<endl;
                cout<<"Enter your Phone No: "<<endl; cin>>phone; customer<<"Phone:"<<phone<<endl;
                cout<<"Enter your CNIC: "<<endl; cin>>cnic; customer<<"CNIC:"<<cnic<<endl;
                cout<<"Total KMs are:"<<km<<" km"<<endl; customer<<"Total KMs are:"<<km<<" km"<<endl;
                cout<<"Price per KM is "<<price<<" Rs"<<endl; customer<<"Price:"<<price<<endl;
                cout<<"Thank You for choosing this Hotel!\nYour Cab Is Booked!"<<endl;
                price=km*price; customer<<"BILL:"<<price<<endl<<endl;
            }
            else
            {
                cout<<"There is no cab available currently!"<<endl; 
            } 
        }
        else
        {
            cout<<"Thank you for visiting Cab Services!"<<endl;
        }
        break;
    case 4:
    km=250;
        cout<<"Do you want to Book a Ride?('y' for yes)"<<endl; cin>>b;
        if (b=='y')
        {
            cout<<"No of Cabs left: "<<c<<endl;
            if (c>0)
            {
                cout<<"Your cab no is:"<<c<<endl;
                c--; d<<c<<endl;
                cout<<"Please Enter Details"<<endl;
               cout<<"Enter your Name: "<<endl;  cin>>name; customer<<"Name:"<<name<<endl;
                cout<<"Enter your Phone No: "<<endl; cin>>phone; customer<<"Phone:"<<phone<<endl;
                cout<<"Enter your CNIC: "<<endl; cin>>cnic; customer<<"CNIC:"<<cnic<<endl;
                cout<<"Total KMs are:"<<km<<" km"<<endl; customer<<"Total KMs are:"<<km<<" km"<<endl;
                cout<<"Price per KM is "<<price<<" Rs"<<endl; customer<<"Price:"<<price<<endl;
                cout<<"Thank You for choosing this Hotel!\nYour Cab Is Booked!"<<endl;
                price=km*price; customer<<"BILL:"<<price<<endl<<endl;
                
            }
            else
            {
                cout<<"There is no cab available currently!"<<endl; 
            } 
        }
        else
        {
            cout<<"Thank you for visiting Cab Services!"<<endl;
        }
        break;
    default:
        cout<<"You have selected wrong number!\nPlease try again"<<endl;
        break;
    }
    d.close();
    customer.close();
}
void admin::change_password()
{
    string v,m;
    fstream log("login.txt",ios::in);
    getline(log,v);
    getline(log,m);
    log.close();
    ofstream log1("login.txt");
    string AdminName;
    string AdminPassword;
    string UserName;
    string Password;
    bool Login= false;
    AdminName=v; AdminPassword=m;
    string password;
    system("CLS");
    cout<<"\tWhat do you want to change\n1.Username\n2.Password\n3.Both"<<endl;
    int y; cin>>y; 
  switch(y)
  {
  case 1:
    system("CLS");
    cout<<"\tEnter current Username: "; cin>>UserName;
    if (UserName==AdminName)
    {
      cout<<"\tEnter New User Name: "<<endl; cin>>AdminName; log1<<AdminName<<endl<<AdminPassword<<endl;
      cout<<"\n\tUser Name Successfully changed!"<<endl;
    }
    else
    {
      log1<<AdminName<<endl<<AdminPassword<<endl;
      cout<<"\n\tWrong User Name!"<<endl;
    }
    break;

  case 2:
    system("CLS");
    cout<<"\tEnter current Password: "; cin>>Password;
    if (Password==AdminPassword)
    {
      cout<<"\tEnter New Password: "<<endl; cin>>AdminPassword; log1<<AdminName<<endl<<AdminPassword<<endl;
      cout<<"\tPassword Successfully changed!"<<endl;
    }
    else
    {
        log1<<AdminName<<endl<<AdminPassword<<endl;
         cout<<"\tWrong Password!"<<endl;
    }
    break;

  case 3:
    system("CLS");
    cout<<"\tEnter current Username: "; cin>>UserName;
    if (UserName==AdminName)
    {
      cout<<"\tEnter New User Name: "<<endl; cin>>AdminName; log1<<AdminName<<endl<<AdminPassword<<endl;
      cout<<"\tUser Name Successfully changed!"<<endl;
      
    }
    else
    {
        log1<<AdminName<<endl<<AdminPassword<<endl;
      cout<<"\tWrong User Name!"<<endl;
    }
    cout<<"\tEnter current Password: "; cin>>Password;
    if (Password==AdminPassword)
    {
      cout<<"\tEnter New Password: "<<endl; cin>>AdminPassword; log1<<AdminName<<endl<<AdminPassword<<endl;
      cout<<"\tPassword Successfully changed!"<<endl;
    }
    else
    {
        log1<<AdminName<<endl<<AdminPassword<<endl;
      cout<<"\tWrong Password!"<<endl;
    }
    break;
  default:
    cout<<"\n\tThank You!"<<endl;
    break;
  }  

log1.close();
}

int admin::password()
{
        admin a1;
        int choice;
        system("CLS");
        string v,m;
        fstream log("login.txt",ios::in|ios::out);
        getline(log,v);
        getline(log,m);
        string AdminName;
        string AdminPassword;
        string UserName;
        string Password;
        bool Login= false;
        AdminName=v; AdminPassword=m;
        cout<<"\t*Admin Login*"<<endl;
        cout<<"\n\tUserName:admin Password:admin\n";
        cout<<"\nUserName: ";
        cin>>UserName;
        cout<<"Password: ";
        cin>>Password; log.close();
    if(UserName== AdminName && Password == AdminPassword)
    {
      cout<<"\tLogin Successful\n";
      Login= true;
      return 1;
    }
    else
    {
        return 0;
    }
}
void admin::view_complaint()
{
    string complain;
	fstream in;
	in.open("complain.txt",ios::in);
	while (!in.eof())
    {
        getline(in,complain);
        cout<<complain<<endl;
    }
	in.close();
	
}
void admin::search_record()
{
    system("CLS");
    int s;     string x,l,a,b,c,d,name,j;
    cout<<"\tPlease Select Any one option:\n\t1.Enter Room Number\n\t2.Enter Name\n\tTo Search Record"<<endl; 
    cin>>s;
    if(s==1)
    {
        fstream search1("book2.txt",ios::in);
        cout<<"\tEnter your Room No to Search: "<<endl; cin>>x;
        while (!search1.eof())
        {
            getline(search1,l);
            getline(search1,name);
            getline(search1,b);
            getline(search1,c);
            getline(search1,j);
            getline(search1,d);
            if(l==x)
            {
                cout<<"ROOM NO: "<<l<<endl;
                cout<<"NAME: "<<a<<endl;
                cout<<"CITY: "<<b<<endl;
                cout<<"PHONE: "<<c<<endl;
                cout<<"CNIC: "<<j<<endl;
                cout<<"ROOM TYPE: "<<d<<endl;
                cout<<"\n\tYour Record Is Successfully Displayed!"<<endl;
            }
                    }
        search1.close();
    }
    else if (s==2)
    {
    
    fstream search("book.txt",ios::in);
    cout<<"\tEnter your name to search: "<<endl;
    cin>>a;
    int lines=3;
    while(!search.eof())
    {
        getline(search,name);
        getline(search,b);
        getline(search,c);
        getline(search,j);
        getline(search,d);
        if (name==a)
        {
            cout<<"NAME: "<<a<<endl;
            cout<<"CITY: "<<b<<endl;
            cout<<"PHONE: "<<c<<endl;
            cout<<"CNIC: "<<j<<endl;
            cout<<"ROOM TYPE: "<<d<<endl;
            cout<<"\n\tYour Record Is Successfully Displayed!"<<endl;
        }    
    }
    search.close();
    }
    else
    {
        cout<<"\tYou have selected wrong choice!"<<endl;
    }    
}
void admin::delete_record()
{
    system("CLS");
    string line,name,a,b,c; int choice; string x,l,d;
    cout<<"\tPlease Select Any one option:\n\t1.Enter Room Number\n\t2.Enter Name\n\tTo Search Record"<<endl; 
    cin >> choice;
    switch(choice)
    {
    case 1:{
        fstream searc1("book2.txt",ios::in);
        fstream del("temp2.txt",ios::app); 
        cout<<"\tEnter your Room No to Delete Record: "<<endl; cin>>x;
        while (getline(searc1,l))
        {
            getline(searc1,name);
            getline(searc1,a);
            getline(searc1,b);
            getline(searc1,c);
            getline(searc1,d);
            if(l != x){
            del<<l<<endl<<name<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;}
            else cout<<"\tRecord Deleted Successfully!"<<endl;
        }
        searc1.close();
        del.close();
        remove("book2.txt");
        rename("temp2.txt", "book2.txt");
        break;}
    case 2:{
        cout<<"\tEnter your Name to Delete Record: "<<endl; cin>>name;
        ifstream m;
        fstream t;
        m.open("book.txt");
        t.open("temp.txt",ios::app);
        char ch; 
        int l4 = 1;            
        while(getline(m,line)) 
        {      
            if(ch == '\n') 
            l4++;
        getline(m,a);
        getline(m,b);
        getline(m,c);
        getline(m,d);
        if (line != name){
        t<<line<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;}
        else cout<<"\tRecord Deleted Successfully!"<<endl;
        } 
    m.close();
    t.close();
    remove("book.txt");
    rename("temp.txt", "book.txt");
        break;}

    default:
        cout<<"\tYou have selected wrong input!"<<endl;
        break;
    }
}
void admin::modify_record()
{
    system("CLS");
    string line,name,a,b,c; int choice; string x,l,d;
    cout<<"\tPlease Select Any one option:\n\t1.Enter Room Number\n\t2.Enter Name\n\tTo Modify Record: "<<endl; 
    cin >> choice;
    switch(choice)
    {
    case 1:{
        fstream searc1("book2.txt",ios::in);
        fstream del("temp2.txt",ios::app); 
        cout<<"Enter your Room No to Modify Record: "<<endl; cin>>x;
        while (getline(searc1,l))
        {
            getline(searc1,name);
            getline(searc1,a);
            getline(searc1,b);
            getline(searc1,c);
            getline(searc1,d);
            if(l != x){
            del<<l<<endl<<name<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;}
            else if(l == x)
        {
            cout<<"Record Found!!!"<<endl;
            cout<<"What do you want to Modify?"<<endl;
            cout<<"1.Room Number\t2.Name\t3.City\t4.Phone Number\t5.CNIC\t6.Whole Record"<<endl; cin>>choice;
            switch (choice)
            {
            case 1:
            cout<<"Enter new details: \nEnter New Room Number: "<<endl; cin>>l;
            del<<l<<endl<<name<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;    
                break;
            case 2:
            cout<<"Enter new details: \nEnter the New Name: "<<endl; cin>>name; 
            del<<l<<endl<<name<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;
                break;
            case 3:
            cout<<"Enter new details: \nEnter the New Cityr: "<<endl; cin>>a;
            del<<l<<endl<<name<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;    
                break;
            case 4:
            cout<<"Enter new details: \nEnter the New Phone Number: "<<endl; cin>>b;  
            del<<l<<endl<<name<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;
                break;
            case 5:
            cout<<"Enter new details: \nEnter the New CNIC: "<<endl; cin>>c;  
            del<<l<<endl<<name<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;
                break;
            case 6:
            cout<<"Enter new details: \nEnter the Room Number: "<<endl; cin>>l; del<<l<<endl;
            cout<<"Enter the New Name: "<<endl; cin>>name; del<<name<<endl;
            cout<<"Enter the New City: "<<endl; cin>>a; del<<a<<endl;
            cout<<"Enter the New Phone Number: "<<endl;  cin>>b; del<<b<<endl;
            cout<<"Enter the New CNIC: "<<endl; cin>>c; ; del<<c<<endl; del<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;
                break;
            default:
            cout<<"You have selected wrong option!\n\nPlease Try Again"<<endl;
                break;
            }
        }
        else
        {cout<<"Your Record not found!!"<<endl;}
        }
        searc1.close();
        del.close();
        remove("book2.txt");
        rename("temp2.txt", "book2.txt");
        break;}
    case 2:{
        cout<<"Enter your Name to Modify Record: "<<endl; cin>>name;
        ifstream m;
        fstream t;
        m.open("book.txt");
        t.open("temp.txt",ios::app);
        char ch; 
        int l4 = 1;            
        while(getline(m,line)) 
        {      
            if(ch == '\n') 
            l4++;
        getline(m,a);
        getline(m,b);
        getline(m,c);
        getline(m,d);
        if (line != name){
        t<<line<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;}
        else if(line==name)
        {
            cout<<"Record Found!!!"<<endl;
            cout<<"What do you want to Modify?"<<endl;
            cout<<"1.Name\t2.City\t3.Phone Number\t4.CNIC\t5.Whole Record"<<endl; cin>>choice;
            switch (choice)
            {
            case 1:
            cout<<"Enter new details: \nEnter the New Name: "<<endl; cin>>line;
            t<<line<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;    
                break;
            case 2:
            cout<<"Enter new details: \nEnter your New City: "<<endl; cin>>a; 
            t<<line<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;
                break;
            case 3:
            cout<<"Enter new details: \nEnter your New Phone Number: "<<endl; cin>>b;
            t<<line<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;    
                break;
            case 4:
            cout<<"Enter new details: \nEnter your CNIC: "<<endl; cin>>c; t<<c<<endl; 
            t<<line<<endl<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;
                break;
            case 5:
            cout<<"Enter new details: \nEnter the New Name: "<<endl; cin>>line; t<<line<<endl;
            cout<<"Enter your New City: "<<endl; cin>>a; t<<a<<endl;
            cout<<"Enter your New Phone Number: "<<endl; cin>>b; t<<b<<endl; 
            cout<<"Enter your CNIC: "<<endl; cin>>c; t<<c<<endl; t<<d<<endl;
            cout<<"YOUR DATA HAS BEEN UPDATED SUCCESSFULLY!"<<endl;
                break;
            default:
            cout<<"You have selected wrong option!\n\nPlease Try Again"<<endl;
                break;
            }
        }
        else
        {cout<<"Your Record not found!!"<<endl;}
        } 
    m.close();
    t.close();
    remove("book.txt");
    rename("temp.txt", "book.txt");
        break;}

    default:
        cout<<"You have selected wrong input!"<<endl;
        break;
    }
}
void admin::rooms_price()
{
    fstream f1("main_menu.txt",ios::out);
    int a=10000,b=15000,c=20000,d=25000,choice;
    cout<<"For which Room do you want to edit price?"<<endl;
    cout<<"1.Luxury Room\n2.Elite Room\n3.Economy Room\n4.Basic Room"<<endl; cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Enter New Price: "<<endl; cin>>a;
        break;
    case 2:
        cout<<"Enter New Price: "<<endl; cin>>b;
        break;
    case 3:
        cout<<"Enter New Price: "<<endl; cin>>c;
        break;
    case 4:
        cout<<"Enter New Price: "<<endl; cin>>d;
        break;
    
    default:
        cout<<"There are no more rooms!\nTRY AGAIN!"<<endl;
        break;
    }
        f1<<"Welcome to Hotel Management System!!!!!"<<endl;
        f1<<"Please Select any Option Below. The following price are Only Valid for One Day of stay!"<<endl;
        f1<<"1.Luxury Room--------------------"<<a<<endl;
        f1<<"2.Elite Room---------------------"<<b<<endl;
        f1<<"3.Economy Room-------------------"<<c<<endl;
        f1<<"4.Basic Room---------------------"<<d<<endl;
    f1.close();
}
void admin::new_employee()
{
    int a;    string name; long double cnic,phone; char choice;
    fstream file("new_worker.txt",ios::in|ios::out);
    fstream bs("emp_record.txt",ios::app);
    file>>a;
    cout<<"\tNumber of seats left for Employees:"<<a<<endl;
    if (a>0)
    {
        a--;
        file<<a;
        system("CLS");
        cout<<"Please Enter Details!"<<endl;
        cout<<"Enter your First Name: "<<endl; cin>>name; bs<<name<<endl;
        cout<<"Enter your CNIC: "<<endl; cin>>cnic; bs<<cnic<<endl;
        cout<<"Enter your Phone No: "<<endl; cin>>phone; bs<<phone<<endl;
        cout<<"\tThank You!You are succesfully selected as a new Employee "<<endl;
        cout<<"\tDo you have a Place to live('y' for yes, 'n' for no): "<<endl; cin>>choice;
        switch (choice)
        {
        case 'y':
            bs<<"N"<<endl;
            break;
        case 'n':
            cout<<"\tPlace will be granted to you in Hotel!"<<endl;
            bs<<"Y"<<endl;
            break;
        
        default:
            cout<<"\tError!Please Enter correctly!"<<endl;
            break;
        }
    }
    else
    {
        cout<<"\tSorry! There are no available seats!"<<endl;
    }
    file.close();
    bs.close();
}
void admin::emp_record()
{
    string y; long double n,h; char k; 
    system("CLS");
    fstream ab("emp_record.txt",ios::in);
    while (getline(ab,y))
    {
        cout<<y<<endl;
    }
    ab.close();
}
void offers::offer()
{
    ofr:
    int choice; char a; 
    fstream o("offer.txt",ios::app);
    system("CLS");
    cout<<"\t1.Family Package\n\t2.Student Package\n\t3.40% Off On Karachi Citizens\n\t4.Meeting Package"<<endl;
    cout<<"\t5.Wedding Package\n\t6.Birthday Package"<<endl; cin>>choice;
    switch (choice)
    {
    case 1:{
        cout<<"\tEnjoy A Day with your Loved Ones at our Hotel For a Day"<<endl;
        cout<<"\tElite Room with sports and fun filled activities and Fine Dining with your Family"<<endl;
        cout<<"\tDo you want to Book this Package?('y' for yes)"<<endl;
        cin>>a; 
        if(a=='y')
        {
            cout<<"\nPlease Enter Detalis"<<endl;
	        cout<<"Name: ";
            cin>>n;
	        o<<n<<endl; 
	        cout<<"City of Residence: "; cin>>ct;
	        o<<ct<<endl; 
	        cout<<"Phone No: "; 
            cin>>pn;
            cout<<"CNIC: "; cin>>cc; o<<cc<<endl; 
	        o<<pn<<endl<<1<<endl; o<<1000<<endl;
            cout<<"\tYour Offer Has Been Booked!"<<endl;
        }
          else
        {
            cout<<"\tThank you for visiting our Hotel!"<<endl;
        }
        
        break;}
    case 2:{
        cout<<"\tTired With The life of Hardships?\n\tForget all your Worries and Have some rest for a Day!"<<endl;
        cout<<"\tUse the facilites of Economy Room with Gym and Spa"<<endl;
        cout<<"\tDo you want to Book this Package?('y' for yes)"<<endl;
        cin>>a; 
        if(a=='y')
        {
            cout<<"\nPlease Enter Detalis"<<endl;
	        cout<<"Name: ";
            cin>>n;
	        o<<n<<endl; 
	        cout<<"City of Residence: "; cin>>ct;
	        o<<ct<<endl; 
	        cout<<"Phone No: "; 
            cin>>pn;
            cout<<"CNIC: "; cin>>cc; o<<cc<<endl; 
	        o<<pn<<endl<<2<<endl; o<<200<<endl;
            cout<<"\tYour Offer Has Been Booked!"<<endl;
        }
          else
        {
            cout<<"\tThank you for visiting our Hotel!"<<endl;
        }
        
        break;}
    case 3:{
    cout<<"\tTired of Visiting All the Places in Karachi?\n\tNow have a visit and enjoy 40% off!"<<endl;
    cout<<"\tDo you want to Book this Package?('y' for yes)"<<endl;
        cin>>a; 
        if(a=='y')
        {
            cout<<"\nPlease Enter Detalis"<<endl;
	        cout<<"Name: ";
            cin>>n;
	        o<<n<<endl; 
	        cout<<"City of Residence: "; cin>>ct;
	        o<<ct<<endl; 
	        cout<<"Phone No: "; 
            cin>>pn;
            cout<<"CNIC: "; cin>>cc; o<<cc<<endl; 
	        o<<pn<<endl<<3<<endl; o<<500<<endl;
            cout<<"\tYour Offer Has Been Booked!"<<endl;
        }
          else
        {
            cout<<"\tThank you for visiting our Hotel!"<<endl;
        }
        
        break;}
    case 4:{
    cout<<"\tHave A Personal Meeting and No Place for Meeting?\n\tDo not worry!We will arrange you a Perfect place for Meeting"<<endl;
    cout<<"\tDo you want to Book this Package?('y' for yes)"<<endl;
        cin>>a; 
        if(a=='y')
        {
            cout<<"\nPlease Enter Detalis"<<endl;
	        cout<<"Name: ";
            cin>>n;
	        o<<n<<endl; 
	        cout<<"City of Residence: "; cin>>ct;
	        o<<ct<<endl; 
	        cout<<"Phone No: "; 
            cin>>pn;
            cout<<"CNIC: "; cin>>cc; o<<cc<<endl; 
	        o<<pn<<endl<<4<<endl; o<<700<<endl;
            cout<<"Your Offer Has Been Booked!"<<endl;
        }
          else
        {
            cout<<"Thank you for visiting our Hotel!"<<endl;
        }
        
        break;}
    case 5:{
    cout<<"\tNow Enjoy your New life in our Hotel!"<<endl; cout<<"\tEnjoy Luxury Room with Fine Dining!"<<endl;
    cout<<"\tDo you want to Book this Package?('y' for yes)"<<endl;
        cin>>a; 
        if(a=='y')
        {
            cout<<"\nPlease Enter Detalis"<<endl;
	        cout<<"Name: ";
            cin>>n;
	        o<<n<<endl; 
	        cout<<"City of Residence: "; cin>>ct;
	        o<<ct<<endl; 
	        cout<<"Phone No: "; 
            cin>>pn;
            cout<<"CNIC: "; cin>>cc; o<<cc<<endl; 
	        o<<pn<<endl<<5<<endl; o<<1500<<endl;
            cout<<"Your Offer Has Been Booked!"<<endl;
        }
          else
        {
            cout<<"Thank you for visiting our Hotel!"<<endl;
        }
        
        break;}
    case 6:{
    cout<<"\tCelebrate your Birthday with Us!"<<endl;
    cout<<"\tDo you want to Book this Package?('y' for yes)"<<endl;
        cin>>a; 
        if(a=='y')
        {
            cout<<"\nPlease Enter Detalis"<<endl;
	        cout<<"Name: ";
            cin>>n;
	        o<<n<<endl; 
	        cout<<"City of Residence: "; cin>>ct;
	        o<<ct<<endl; 
	        cout<<"Phone No: "; 
            cin>>pn;
            cout<<"CNIC: "; cin>>cc; o<<cc<<endl; 
	        o<<pn<<endl<<6<<endl; o<<900<<endl;
            cout<<"Your Offer Has Been Booked!"<<endl;
        }
        else
        {
            cout<<"Thank you for visiting our Hotel!"<<endl;
        }
        
        break;}
    default:
        cout<<"Wrong Choice!Please Try Again!"<<endl;
        goto ofr;
        break;
    }
    o.close();
}
void offers::billoffer()
{
    string na,city,phn,cnc,bill,offno,name;
    cout<<"Enter your Name For Bill: "<<endl; cin>>name;
    ifstream check("offer.txt");
    while (getline(check,na))
    {
        getline(check,city); getline(check,phn); getline(check,cnc); getline(check,offno); getline(check,bill);
    
    if (na==name)
    {
        cout<<"Your Name Is: "<<na<<endl;
        cout<<"Your Offer No Is: "<<offno<<endl;
        cout<<"Your Bill Is: $"<<bill<<endl;
    }
    } 
    check.close();
}
void facilities::facility()
{

    int choice; char yes;
    cout<<"****************Welcome To Hotel*************"<<endl;
    cout<<"Please Select One Of the Facilities Given Below: "<<endl;
    cout<<"1.Gym\n2.Spa\n3.Fun-Filled Activities For Children\n4.Sun Deck"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"Do You Want to Avail Gymnasium Facility?('y' for yes)"<<endl;
        cin>>yes;
        if(yes=='y')
        {
            cout<<"Enter Your Name: "<<endl; cin>>name;
            cout<<"Enter your Phone Number: "<<endl; cin>>phone_no;
            cout<<"Enter your CNIC: "<<endl; cin>>cnic;
            cout<<"Please Pay 50$"<<endl;
            cout<<"Thank you! Now you can avail Gymnasium for 24 hours!"<<endl;
        }
         else
        {
            cout<<"Thank You for choosing our Hotel!"<<endl;

        }
        break;
    case 2:
        cout<<"Do You Want to Avail Spa Facility?('y' for yes)"<<endl;
        cin>>yes;
        if(yes=='y')
        {
            cout<<"Enter Your Name: "<<endl; cin>>name;
            cout<<"Enter your Phone Number: "<<endl; cin>>phone_no;
            cout<<"Enter your CNIC: "<<endl; cin>>cnic;
            cout<<"Please Pay 100$"<<endl;
            cout<<"Thank you! Now you can avail Spa Facility!"<<endl;
        }
         else
        {
            cout<<"Thank You for choosing our Hotel!"<<endl;

        }
        break;
    case 3:
        cout<<"Do You Want to Avail Fun Filled Activities For Children?('y' for yes)"<<endl;
        cin>>yes;
        if(yes=='y')
        {
            cout<<"Enter Your Name: "<<endl; cin>>name;
            cout<<"Enter your Phone Number: "<<endl; cin>>phone_no;
            cout<<"Enter your CNIC: "<<endl; cin>>cnic;
            cout<<"Please Pay 250$"<<endl;
            cout<<"Thank you! Now you can avail Fun Filled Activites!"<<endl;
        }
         else
        {
            cout<<"Thank You for choosing our Hotel!"<<endl;

        }
        break;
    case 4:
        cout<<"Do You Want to Avail Sun Deck Facility?('y' for yes)"<<endl;
        cin>>yes;
        if(yes=='y')
        {
            cout<<"Enter Your Name: "<<endl; cin>>name;
            cout<<"Enter your Phone Number: "<<endl; cin>>phone_no;
            cout<<"Enter your CNIC: "<<endl; cin>>cnic;
            cout<<"Please Pay 90$"<<endl;
            cout<<"Thank you! Now you can avail Sun Deck!"<<endl;
        }
        else
        {
            cout<<"Thank You for choosing our Hotel!"<<endl;

        }
        
        break;
    default:
        cout<<"Thank You for choosing our Hotel!"<<endl;
        break;
    }
}
void select();
void update_customer();
void menu_card();
void show_info();
void receipt();
int time1();
float x=0;
struct restaurant
{
	int quantity[15];
	float bill=x;
	char dish[15][20];
}r;
struct customer
{
	char name[30];
	string contact;
}c;

fstream file;
int n=0;
void menu_card()
{
	
	int option;
	ifstream menu;
	string mytext;
	int i;
	char ch;
	
	cout<<endl<<endl<<"\n\n\t Welcome to Restauarant...... !\n\n";
	
	menu.open("dishes.txt");
	while(getline(menu,mytext))
	{
		cout<<mytext<<endl;
	}
	menu.close();

	abc:
	cout<<"\n\t Select From The Menu : ";
	cin>>option;
		
	switch(option)
	{
		case 1: 
			strcpy(r.dish[n],"Tandoori chicken");
			cout<<"\n\t Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+500*r.quantity[n];
			n++;
			break;
		case 2:
			strcpy(r.dish[n],"Chicken tikka masala");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+650*r.quantity[n];
			n++;
			break;
		case 3:
			strcpy(r.dish[n]," palak paneer");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+400*r.quantity[n];
			n++;
			break;
		case 4:
			strcpy(r.dish[n],"Carbonara");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+600*r.quantity[n];
			n++;
			break;
		case 5:
			strcpy(r.dish[n],"Fetuccine alfredo");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+750*r.quantity[n];
			n++;
			break;
		case 6:
			strcpy(r.dish[n],"Lasagne");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+600*r.quantity[n];
			n++;
			break;
		case 7:
			strcpy(r.dish[n],"Guacamole");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+550*r.quantity[n];
			n++;
			break;
		case 8:
			strcpy(r.dish[n],"Tomato Salsa");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+450*r.quantity[n];
			n++;
			break;
		case 9:
			strcpy(r.dish[n],"Burritos");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+300*r.quantity[n];
			n++;
			break;
		case 10:
			strcpy(r.dish[n],"Enchiladas");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+200*r.quantity[n];
			n++;
			break;
		case 11:
			strcpy(r.dish[n],"Biryani");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+300*r.quantity[n];
			n++;
			break;
		case 12:
			strcpy(r.dish[n],"Qorma");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+400*r.quantity[n];
			n++;
			break;
		case 13:
			strcpy(r.dish[n],"Pulao");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";			
			cin>>r.quantity[n];
			r.bill=r.bill+350*r.quantity[n];
			n++;
			break;
		case 14:
			strcpy(r.dish[n],"Karahi (1/2 Kilo)");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";			
			cin>>r.quantity[n];
			r.bill=r.bill+500*r.quantity[n];
			n++;
			break;
		case 15:
			strcpy(r.dish[n],"Karahi (1 Kilo)");
			cout<<"\n Quantity of "<<r.dish[n]<<" ? ";
			cin>>r.quantity[n];
			r.bill=r.bill+800*r.quantity[n];
			n++;
			break;	
		default :
			cout<<"\n\n Please Check your dish no. carefully.....! ";
			goto abc;
	}
	
	cout<<"\n Do you want to order more ? ";
	cout<<"\n 1- Yes ";
	cout<<"\n 2- No ";
	cout<<"\n Select : ";
	cin>>i;
	if(i==1)
	goto abc;
}
void receipt()
{
	int i;
	cout<<"\n\t\tMr./Mrs. "<<c.name<<" Your information is as follows : ";
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<endl<<i+1<<"- You ordered for : "<<r.dish[i]<<".";
		cout<<"\n   Quantity of "<<r.dish[i]<<" : "<<r.quantity[i];
		cout<<endl;
	}
	cout<<"\n\n\t\t Your total bill : $"<<r.bill<<"/"<<"=";
	
	ofstream ofile;
	ofile.open("receipt.txt",ios::app);
	ofile.write((char*)&r,sizeof(r));
	ofile.close();
}
void show_info()
{
	cout<<"\n\t Customer Information Is As Follows : "<<endl<<endl;
	int i=1;
	file.open("customer.txt",ios::in);
	file.read((char*)&c,sizeof(c));
	cout<<endl<<endl;
	cout<<endl<<endl;
	while(file.eof()==0)
	{
		cout<<endl;
		cout<<i<<"-> NAME : "<<c.name;
		cout<<"    CONTACT : "<<c.contact;		
		cout<<endl;
		i++;
		file.read((char*)&c,sizeof(c));
	}
	file.close();
}
void update_customer()
{
	char cname[30];
	
	cout<<"\n Enter Customer Name : ";
	cin>>cname;
	file.open("customer.txt",ios::in|ios::out);
 	file.read((char*)&c,sizeof(c));
 	while(file.eof()==0)
 	{
 		if(strcmp(c.name,cname)==0)
 		{
 			cout<<"Enter New Contact : ";
			cin>>c.contact;	
   			file.seekp(file.tellg()-sizeof(c));
  			file.write((char*)&c,sizeof(c));
  			cout<<"\n\nFile Updated";
  			break;	
		}
	    file.read((char*)&c,sizeof(c));	
	}
	file.close();
}

int time1()
{
	 // Declaring argument for time() 
    time_t tt; 
  
    // Declaring variable to store return value of 
    // localtime() 
    struct tm * ti; 
  
    // Applying time() 
    time (&tt); 
  
    // Using localtime() 
    ti = localtime(&tt); 
  
    cout<<endl<<"\t\t\t\t\t"<< asctime(ti); 
}
void admins()
{
	int choice1;
	
	lmn:
		
	system("CLS");
  	time1();
  	cout<<"\n 1- Information About Customers. ";
  	cout<<"\n 2- Update Customer Contact no. ";
  	cout<<"\n 3- Exit.";
  	cout<<"\n\n Select : ";
  	cin>>choice1;
  	
  	if(choice1==1)
  		show_info();
	else if(choice1==2)
		update_customer();
	else if(choice1==3)
		exit(1);
	else
		{
			cout<<endl<<" Wrong Input. Please Enter Again. "<<endl;
			goto lmn;		
		}	
}
void users()
{
	int option;
	
		system("CLS");
		cout<<" Please Enter Your Name : ";
		cin>>c.name;
		cout<<" Please Enter Your Contact No. : ";
		cin>>c.contact;
		file.open("customer.txt",ios::app);
 		file.write((char*)&c,sizeof(c));
 		file.close();
	
	while(1)
	{
		rst:
			
		cout<<endl<<endl<<"1- Restaurant Menu Card .\n";
		cout<<"2- Exit. \n";
		cin>>option;
	
		switch(option)
		{
			case 1:
                time1();
				menu_card();
                receipt();
				break;
			case 2:
				exit(1);
            
			default:
				cout<<"Wrong Input. Try Again ! ";
				goto rst;	
		}
	}
}
main()
{
    
    int count=0;
    system("color 1e");//Setting The Color Of Console
    cout<<endl;
    cout<<"\t******************************\n"; 
    cout<<"\t*         Welcome            *\n";
    cout<<"\t*            To              *\n"; 
    cout<<"\t*    Hotel Booking System    *\n";
    cout<<"\t******************************\n";
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"\tLOADING ";
   Sleep(100);//For Pause 
   cout<<"<"; 
   Sleep(100);//For Pause
   cout<<">"; 
   Sleep(100);//For Pause  
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
   Sleep(100);//For Pause
   cout<<">"; 
   Sleep(100);//For Pause  
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"\n\n\t Successful\n";

   Sleep(2000);//For Pause
   system("CLS");//To Clear The Screen
    time1();
    menu:
    offers o1;
    user u1;
    facilities f1;
    admin a1;
    show_record s1;
    int a,choice;
    start:
    cout<<"\tWELCOME TO HOTEL MANAGEMENT SYSTEM!!!"<<endl;
    cout<<"\tPlease select any one! "<<endl;
    cout<<"\t1.Admin\n\t2.User\n"; cin>>a;
    if (a==1)
    {
        system("CLS");
        admin:
        time1();
    cout<<"\tWelcome to Admin Panel!!!"<<endl;
    if (a1.password()==1)
    {
        time1();
    cout<<"\n\t1.View Complaint Box\n\t2.Search For A Specific Record\n\t3.Delete Record\n\t4.Modify Record"<<endl;
    cout<<"\t5.Edit Rooms Price\n\t6.New Employee\n\t7.View Employees Record\n\t8.Change Password for admin"<<endl;
    cout<<"\t9.Restaurant Dine-In\n\t10.Exit\n\t11.Back\n\tPlease Select any one Option!"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        time1();
        a1.view_complaint();
        break;
    case 2:
        time1();
        a1.search_record();
        break;
    case 3:
        time1();
        a1.delete_record();
        break;
    case 4:
        time1();
        a1.modify_record();
        break;
    case 5:
        time1();
        a1.rooms_price();
        break;
    case 6:
        time1();
        a1.new_employee();
        break;
    case 7:
        time1();
        a1.emp_record();
        break;
    case 8:
        time1();
        a1.change_password();
        break;
    case 9:
        time1();
        admins();
        break;
    case 10:
        exit(1);
        break;
    case 11:
        goto start;
        break;
    default:
        cout<<"Wrong Choice!Please Try Again!"<<endl;
        goto admin;
        break; 
    
    }
   }
  else
  {
      cout<<"Login Unsuccessful!\nPlease Try Again"<<endl;
      goto admin;
  }

    }
    else if(a==2)
    {
        system("CLS");
        ls:
        time1();
        cout<<"\tWelcome to User Panel!"<<endl;
        cout<<"\tEnter your Choice: "<<endl;
        cout<<"\t1.Book a Room\n\t2.Special Offers\n\t3.Events and Celebrations\n";
        cout<<"\t4.Facilities\n\t5.Cab Service\n\t6.Complaint\n\t7.Restaurant Dine-IN\n\t8.Show Record"<<endl;
        cout<<"\t9.Main Menu\n\t10.Bill For Hotel\n\t11.Exit"<<endl;
        cin>>a;
        switch (a)
        {
        case 1:
            system("CLS");
            time1();
            u1.main_menu();
            break;
        case 2:
            system("CLS");
            time1();
            o1.offer();
            o1.billoffer();
            break;
        case 3:
            system("CLS");
            time1();
            u1.events();
            break;
        case 4:
            system("CLS");
            time1();
            f1.facility();
            break;
        case 5:
            system("CLS");
            time1();
            u1.cab_services();
            break;
        case 6:
            system("CLS");
            time1();
            u1.complaint();
            break;
        case 7:
            system("CLS");
            time1();
            users();
            break;
        case 8:
            system("CLS");
            time1();
            s1.showrecord();
            break;
        case 9:
            system("CLS");
            goto start;
            break;
        case 11:
            exit(1);
            break;
        case 10:{
            system("CLS");
            paymoney:
            int choice,rmno,slr;
            string nas;
            ao:
            time1();
            cout<<"\n\tDo you want to:\n\t1.Enter Your Name\n\t2.Enter Room Number\n\t3.Exit\n\tFor Bill? "<<endl; cin>>choice;
            switch (choice)
            {
            case 1:
            cout<<"Enter Your Name: "<<endl; cin>>nas;
            u1.bill(nas);
            break;
        case 2:
            cout<<"Enter your Room Number: "<<endl; cin>>rmno;
            u1.bill(rmno);
            break;
        case 3:
            exit(1);
            break;
        default:
            cout<<"Please Select Correct Choice!"<<endl;
            goto ao;
            break;
        }
            break;}
         default:
            cout<<"You have selected wrong input!"<<endl;
            goto ls;
            break;
        }
    }
    else{
    cout<<"Error! Please select again!"<<endl; goto menu;}
    char paid;int j; aa: 
    time1();
    cout<<"\n\tDo you want to Pay:\n\t1.Hotel Bill\n\t2.Main Menu\n\t3.Exit"<<endl; cin>>j;
    switch (j)
    {
    case 1:
        goto paymoney;
        break;
    case 2:
        goto start;
        break;  
    case 3:
        exit(1);
        break;
    default:
        time1();
        cout<<"\n\tWrong Choice!!\n\tPlease Try Again!"<<endl;
        goto aa;
        break;
    }
 }

