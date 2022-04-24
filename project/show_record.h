#include"user.h"
class show_record:public user
{
    public:
    void showrecord(){
    string c;
    ifstream fin("book.txt");
    cout<<"Your Record will  be displayed in a following pattern\n1.Name 2.City 3.Phone No 4.Type of Room\n";
    while (getline (fin, c))
    {
    cout<<c<<endl;
    }
	fin.close();}
};