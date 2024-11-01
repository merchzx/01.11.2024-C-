#include<iostream>
using namespace std;

class Movie
{
    char* name;
    double time;
    int year;
public:

    Movie()
    {
        name = nullptr;
        time = 0;
        year = 0;
    }
    Movie(const char* n, double t, int y)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        time = t;
        year = y;
    }
    Movie(const Movie& obj)
    {
        name = new char[strlen(obj.name) + 1];
        strcpy_s(name, strlen(obj.name) + 1, obj.name);
        time = obj.time;
        year = obj.year;

    }
    ~Movie()
    {
        delete[] name;
    }
    double getTime() {
        return time;
    }
    int getYear() {
        return year;
    }
    const char* getName() {
        return name;
    }
    void setName(const char * _name) {
        if (name != nullptr) {
            delete[]name;
        }
        name = new char[strlen(_name) + 1];
        strcpy_s(name, strlen(_name) + 1, _name);
    }
    void setTime(double _time) {
        time = _time;
    }
    void setYear(int _year) {
        year = _year;
    }
    /*friend istream& operator>>(istream& is, Movie& obj);*/
    friend ostream& operator<<(ostream& os, Movie& obj);
};

//ostream& operator<<(ostream& os, Movie& obj) {
//    os <<"Name: " << obj.name << "\t" << "Year: " << obj.year << "\t" << "Time: " << obj.time << endl;
//    return os;
//}

ostream& operator<<(ostream& os, Movie& obj) {
    os << "Name: " << obj.getName() << "\t" << "Year: " << obj.getYear() << "\t" << "Time: " << obj.getTime() << endl;
    return os;
}

//istream& operator>>(istream& is, Movie& obj) {
//    char buff[100];
//    if (obj.name != nullptr) {
//        delete[]obj.name;
//    }
//    cout << "Input name - ";
//    cin >> buff;
//    obj.name = new char[strlen(buff) + 1];
//    strcpy_s(obj.name, strlen(buff) + 1, buff);
//    cout << endl<<"Input year - ";
//    is >> obj.year;
//    cout << endl << "Input time - ";
//    is >> obj.time;
//    return is;
//}

istream& operator>>(istream& is, Movie& obj) {
    
    double _time;
    int _year;
    char buff[20];
    cout << "Input name - ";
    is >> buff;
    obj.setName(buff);
    cout << "Input year - ";
    is >> _year;
    obj.setYear(_year);
    cout << "Input time - ";
    is >> _time;
    obj.setTime(_time);
    return is;
}

int main()
{
    Movie a;
    cin >> a;
    cout << a;
}