#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//its a class for registration and login purpose
class user
{
public:
    string username;
    string password;
    /*function for Registration.
    We don't have database system here that's why registration info will not store.*/
    void Register()
    {
        cout<<"REGISTRATION\n";
        cout<<"Enter Username: ";
        getline(cin,username);
        cout<<"Enter Password: ";
        cin>>password;
        cin.ignore();

        ofstream fout("users.txt", ios::app);
        fout<<username<<"  "<<password<<endl;
        fout.close();
        cout<<"Registration Succesful! Data Saved. \n";
    }
//Function for Login purpose
    bool login()
    {
        string a,b;
        cout<<"\n_LOGIN_\n";
        cout<<"Enter Username: ";
        getline(cin,a);
        cout<<"Enter Password: ";
        cin>>b;
        cin.ignore();

        ifstream fin("users.txt");
        string u,p;
        bool found=false;

        while(fin>>u>>p)
        {
            if(u==a && p==b)
            {
                found=true;
                break;
            }
        }
        fin.close();

        if(found)
        {
            cout<<"Login Successfully\n";
            return true;
        }
        else
        {
            cout<<"Invalid username/Password\n";
            return false;
        }

    }
};
//Its a class for menu item.
class menu
{
public:
    string item;
    float price;
    menu(string i,float p)//here we use Constructor
    {
        item=i;
        price=p;
    }
    void show()
    {
        cout<<item<<" - "<<price<<" Taka"<<endl;
    }
};
class order
{
public:
    int orderchoice;
    int quantity;
    double bill;
    bool ordering_item()
    {
        cout<<"Select an item: ";
        cin>>orderchoice;
        if(orderchoice<1 || orderchoice>5)
        {
            cout<<"Invalid choice!!"<<endl;
            return false;
        }
        else
        {
            return true;
        }
    }
    bool item_quantity()
    {
        cout<<"Quantity :";
        cin>>quantity;
        if(quantity<1 )
        {
            cout<<"Invalid! "<<endl;
        }
        else if (quantity>10)
        {
            cout<<"You can't order more than 10. \nFor custom order call: 01235656647"<<endl;
            return false;
        }
        else
        {
            return true;
        }
    }
};
class Person
{
public:
    virtual void details()
    {
        cout<<"Regular Person"<<endl;
    }
};
class deliveryman:public Person
{
public:
    string name;
    string phonenumber;

    deliveryman(string d,string p)
    {
        name=d;
        phonenumber=p;
    }

    void details() override
    {
        cout<<"Deliveryman's Name: "<<name<<endl;
        cout<<"Phone Number :"<<phonenumber<<endl;
    }
};

int main()
{

    user c;
    int choice;
    cout << "Do you register?\nPress 1 if yes(Login)\nPress 2 if no(Registration)\nEnter choice: ";
    cin >> choice;
    cin.ignore(); // buffer clear

    if (choice == 2)
    {
        c.Register();
    }

    while (!c.login())
    {
        // repeat until login successful
    }

    menu m[5] =
    {
        menu("1.Burger",150),
        menu("2.Pizza",250),
        menu("3.Pasta",200),
        menu("4.Sandwich",120),
        menu("5.Fries",80)
    };
    cout<<"\n\n--- MENU ---\n";
    for(int i=0; i<5; i++)
    {
        m[i].show();
    }
    order o;
    while(!o.ordering_item())
    {

    }
    while(!o.item_quantity())
    {

    }
    o.bill=m[o.orderchoice-1].price*o.quantity;
    cout<<"Item added to cart!"<<endl<<"Total Bill:"<<o.bill<<" BDT"<<endl<<endl;

    cout<<"_CHECKOUT_"<<endl;
    Person *p;//base class pointer
    deliveryman x("Sadik Hasan","01620072923");
    p= &x;
    p->details();
    cout<<endl<<"Thank you for ordering!!!"<<endl<<"STAY CONNECTED"<<endl<<"HAVE A GOOD DAY!!!";
    return 0;
}
