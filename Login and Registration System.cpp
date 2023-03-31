#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool LoggedIn()
{
    string username,password,un,pw;
    
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    
    ifstream read("C: \\" + username + ".txt");
    getline(read,un);
    getline(read,pw);
    
    if(un==username && pw==password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;
    
    cout<<"1: Register\n2: Login\nYour choice: ";
    cin>>choice;
    if(choice==1)
    {
        string username,password;
        
        cout<<"select a username: ";
        cin>>username;
        cout<<"select a password: ";
        cin>>password;
        
        ofstream file;
        file.open("C: \\" + username + ".txt");
        file<<username<<endl<<password;
        file.close();
        
        main();
    }
    else if(choice==2)
    {
        bool status = LoggedIn();
        
        if(!status)
        {
            cout<<"False Login!"<<endl;
            return 0;
        }
        else{
            cout<<"Succesfully logged in!"<<endl;
            return 1;
        }
    }
    else
    {
        cout<<"\nYou have entered wrong choice.\nTry again.\n\n";
        main();
    }

}