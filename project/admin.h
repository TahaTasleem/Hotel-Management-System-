#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctime>
#include<string>
#include<string.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
class admin
{
    int roomno;
    string city;
    string e;
    char name[25];
    char phone_no[12];
    int x,y,z,w;
    public:
    int password();
    void view_complaint();
    void search_record();
    void delete_record();
    void rooms_price();
    void new_employee();
    void modify_record();
    void emp_record();
    void change_password();
};
