#include<iostream>
#include<string>
#define MAX 1000//max size of the address book
using namespace std;

struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Address;
};

struct AddressBook
{
    struct Person personArray[MAX];
    int m_Size;//the size of the address book
};

void addPerson(AddressBook *abs)
{
    if(abs->m_Size == MAX)
    {
        cout<<"The address book is full."<<endl;
        return;
    }
    else
    {
        string name;
        cout<<"Please input the name of the person: "<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name = name;
        
        cout<<"Please input the sex of the person: "<<endl;
        cout<<"1. Male"<<endl;
        cout<<"2. Female"<<endl;
        int sex = 0;
        while(true)
        {
            cin>>sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout<<"Please input the correct sex."<<endl;
            }
        }
        cout<<"Please input the age of the person: "<<endl;
        
        int age = 0;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age = age;
        cout<<"Please input the phone number of the person: "<<endl;
        
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        cout<<"Please input the address of the person: "<<endl;
        
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Address = address;
        abs->m_Size++;
        
        cout<<"Add Successfully!"<<endl;
        system("pause");//pause the program
        system("cls");//clear the screen
    }
}

void showPerson(AddressBook *abs)
{
    if(abs->m_Size == 0)
    {
        cout<<"The address book is empty."<<endl;
        return;
    }
    else
    {
        for(int i = 0; i < abs->m_Size; i++)
        {
            cout<<"Name: "<<abs->personArray[i].m_Name<<"\t";
            cout<<"Sex: "<<(abs->personArray[i].m_Sex == 1 ?"Male":"Female")<<"\t";
            cout<<"Age: "<<abs->personArray[i].m_Age<<"\t";
            cout<<"Phone: "<<abs->personArray[i].m_Phone<<"\t";
            cout<<"Address: "<<abs->personArray[i].m_Address<<endl;
        }
    }
    system("pause");
    system("cls");
}

int isExist(AddressBook *abs, string name)//search the name in the address book
{
    for(int i = 0; i < abs->m_Size; i++)
    {
        if(abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;//not found, back -1
}

void findPerson(AddressBook *abs)//search the name in the address book
{
    cout<<"Please input the name you want to find: "<<endl;
    string name;
    cin>>name;
    if(isExist(abs, name) == -1)
    {
        cout<<"The name is not exist."<<endl;
    }
    else
    {
        cout<<"Name: "<<abs->personArray[isExist(abs, name)].m_Name<<"\t";
        cout<<"Sex: "<<(abs->personArray[isExist(abs, name)].m_Sex == 1 ?"Male":"Female")<<"\t";
        cout<<"Age: "<<abs->personArray[isExist(abs, name)].m_Age<<"\t";
        cout<<"Phone: "<<abs->personArray[isExist(abs, name)].m_Phone<<"\t";
        cout<<"Address: "<<abs->personArray[isExist(abs, name)].m_Address<<endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(AddressBook *abs)//modify the person's information
{
    cout<<"Please input the name you want to modify: "<<endl;
    string name;
    cin>>name;
    if(isExist(abs, name) == -1)
    {
        cout<<"The name is not exist."<<endl;
    }
    else
    {
        cout<<"Please input the new name: "<<endl;
        string newName;
        cin>>newName;
        abs->personArray[isExist(abs, name)].m_Name = newName;
        
        cout<<"Please input the new sex: "<<endl;
        cout<<"1. Male"<<endl;
        cout<<"2. Female"<<endl;
        int sex = 0;
        while(true)
        {
            cin>>sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[isExist(abs, name)].m_Sex = sex;
                break;
            }
            else
            {
                cout<<"Please input the correct sex."<<endl;
            }
        }
        
        cout<<"Please input the new age: "<<endl;
        int age = 0;
        cin>>age;
        abs->personArray[isExist(abs, name)].m_Age = age;

        cout<<"Please input the new phone: "<<endl;
        string phone;
        cin>>phone;
        abs->personArray[isExist(abs, name)].m_Phone = phone;

        cout<<"Please input the new address: "<<endl;
        string address;
        cin>>address;
        abs->personArray[isExist(abs, name)].m_Address = address;

        cout<<"Modify Success!"<<endl;
    }
    system("pause");
    system("cls");
}

void clearPerson(AddressBook* abs)
{
    cout<<"Are you sure to clear all the contacts?(y/n)"<<endl;
    char choice;
    cin>>choice;
    if(choice == 'y')
    {
        abs->m_Size = 0;
        cout<<"Clear Success!"<<endl;
    }
    system("pause");
    system("cls");
}

void showMenu()
{
    cout<<"1. Add Contact"<<endl;
    cout<<"2. Show Contact"<<endl;
    cout<<"3. Delete Contact"<<endl;
    cout<<"4. Find Contact"<<endl;
    cout<<"5. Modify Contact"<<endl;
    cout<<"6. Clear Contact"<<endl;
    cout<<"0. Exit Contacts"<<endl;
}

int main()
{
    AddressBook abs;//abs is a variable named addressbooks
    abs.m_Size = 0;
    int select = 0;
    while (true)
    {
    showMenu();
    cin>>select;
    switch(select)
    {
        case 1: // Add Contact
            addPerson(&abs);
            break;
        case 2: // Show Contact
            showPerson(&abs);
            break;
        case 3: // Delete Contact
        {
            cout<<"Please input the name which you wany to delete:"<<endl;
            string name;
            cin>>name;
            if(isExist(&abs, name) == -1)
            {
                cout<<"The name is not exist."<<endl;
            }
            else
            {
                for(int i = isExist(&abs, name); i < abs.m_Size; i++)
                {
                    abs.personArray[i] = abs.personArray[i+1];
                }
                abs.m_Size--; //update the size
                cout << "Name deleted successfully." << endl;
            }
            system("pause");
            system("cls");
        }
            break;
        case 4: // Find Contact
            findPerson(&abs);
            break;
        case 5: // Modify Contact
            modifyPerson(&abs);
            break;
        case 6: // Clear Contact
            cout<<"Modify Contact"<<endl;
            break;
        case 0: // Exit Contacts
            cout<<"Welcome to use next time."<<endl;
            system("pause");
            break;
    }
    }
    
    system("pause");
    return 0;
}