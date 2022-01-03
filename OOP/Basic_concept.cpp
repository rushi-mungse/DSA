#include <iostream>
#include <string>
using namespace std;
class AbstractForEmployee{
    virtual void promotionForEmployee()=0;
};
class Employee:AbstractForEmployee
{
string interest;
public:
    string name;
    string company;
    int age;
    void introOfEmployee()
    {
        cout << "Name of Empolyee :- " << name << endl;
        cout << "Company of Empolyee :- " << company << endl;
        cout << "Age of Empolyee :- " << age << endl;
        return;
    }
    Employee(string Name, string Company, int Age)
    {
        name = Name;
        company = Company;
        age = Age;
    }
    //Encapsulation principle
    void set(string Interest){
        interest=Interest;
    }
    string get(){
        return interest;
    }
    void promotionForEmployee(){
        cout<<name<<", Got promotion..."<<endl;
    }
};

class CEO{
    public:
    void promotion(){
        Employee e2=Employee("Rahul","Facebook",19);
        e2.set("listening Music");
        cout<<e2.get()<<endl;
    }
};

int main()
{   //Using contructor
    Employee e1 = Employee("Rushikesh", "Google", 21);
    // e1.name="Rushikesh Mungse";
    // e1.company="Google";
    // e1.age=21;
    e1.introOfEmployee();
    e1.set("Mathematics");
    cout<<e1.get()<<endl;
    CEO c1;
    c1.promotion();
    e1.promotionForEmployee();
    return 0;
}