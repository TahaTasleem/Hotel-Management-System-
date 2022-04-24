#ifndef USER_H					// avoid repeated expansion
#define USER_H
class user
{
    protected:
    int roomno;
    string city;
    char name[25];
    char phone_no[12],cnic[13];
    int x,y,z,w;
    public:
    void show_menu();
    int main_menu();
    void bill(string );
    void bill(int rmno);
    void special_offers();
    void events();
    void facilities();
    void cab_services();
    void complaint();
    void dine_in();
};
#endif  