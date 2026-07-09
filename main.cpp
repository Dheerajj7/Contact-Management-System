#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Contact
{

public:

    string name;
    string phone;
    string email;


    void input()
    {

        cin.ignore();

        cout << "\nEnter Name: ";
        getline(cin, name);


        cout << "Enter Phone Number: ";
        getline(cin, phone);


        cout << "Enter Email: ";
        getline(cin, email);

    }



    void display()
    {

        cout << "\nName  : " << name;
        cout << "\nPhone : " << phone;
        cout << "\nEmail : " << email;

        cout << "\n-------------------------";

    }

};




// Add contact

void addContact()
{

    Contact c;


    ofstream file("contacts.txt", ios::app);


    c.input();


    file << c.name << endl;
    file << c.phone << endl;
    file << c.email << endl;



    file.close();


    cout << "\nContact added successfully!";

}




// Display contacts

void displayContacts()
{

    Contact c;


    ifstream file("contacts.txt");


    if(!file)
    {

        cout << "\nNo contacts available.";

        return;

    }



    while(getline(file, c.name))
    {

        getline(file, c.phone);

        getline(file, c.email);



        c.display();

    }


    file.close();

}




// Search contact

void searchContact()
{

    string searchName;


    cin.ignore();


    cout << "\nEnter name to search: ";

    getline(cin, searchName);



    Contact c;

    bool found = false;


    ifstream file("contacts.txt");



    while(getline(file, c.name))
    {

        getline(file, c.phone);

        getline(file, c.email);



        if(c.name == searchName)
        {

            c.display();

            found = true;

            break;

        }

    }


    file.close();


    if(!found)
    {

        cout << "\nContact not found.";

    }

}


// Delete contact

void deleteContact()
{

    string deleteName;


    cin.ignore();


    cout << "\nEnter name to delete: ";

    getline(cin, deleteName);



    Contact c;


    bool deleted = false;



    ifstream file("contacts.txt");

    ofstream temp("temp.txt");



    while(getline(file, c.name))
    {

        getline(file, c.phone);

        getline(file, c.email);



        if(c.name != deleteName)
        {

            temp << c.name << endl;
            temp << c.phone << endl;
            temp << c.email << endl;

        }

        else
        {

            deleted = true;

        }

    }


    file.close();

    temp.close();


    remove("contacts.txt");

    rename("temp.txt","contacts.txt");



    if(deleted)

        cout << "\nContact deleted successfully!";


    else

        cout << "\nContact not found.";

}


// Update contact

void updateContact()
{

    string oldName;


    cin.ignore();


    cout << "\nEnter contact name to update: ";

    getline(cin, oldName);


    Contact c;


    bool updated = false;



    ifstream file("contacts.txt");

    ofstream temp("temp.txt");



    while(getline(file, c.name))
    {

        getline(file, c.phone);

        getline(file, c.email);



        if(c.name == oldName)
        {

            cout << "\nEnter new details:";

            c.input();

            updated = true;

        }


        temp << c.name << endl;

        temp << c.phone << endl;

        temp << c.email << endl;


    }



    file.close();

    temp.close();



    remove("contacts.txt");

    rename("temp.txt","contacts.txt");



    if(updated)

        cout << "\nContact updated successfully!";

    else

        cout << "\nContact not found.";

}

int main()
{

    int choice;

    do
    {

        cout << "\n\n===== Contact Management System =====";

        cout << "\n1. Add Contact";

        cout << "\n2. Display Contacts";

        cout << "\n3. Search Contact";

        cout << "\n4. Update Contact";

        cout << "\n5. Delete Contact";

        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";

        cin >> choice;

        switch(choice)
        {


        case 1:

            addContact();

            break;



        case 2:

            displayContacts();

            break;




        case 3:

            searchContact();

            break;




        case 4:

            updateContact();

            break;




        case 5:

            deleteContact();

            break;



        case 6:

            cout << "\nExiting program...";

            break;



        default:

            cout << "\nInvalid choice!";


        }


    }
    
    while(choice != 6);


    return 0;

}