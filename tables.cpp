#include "tables.h"
#include <iostream>

void tables::create_node(string date) {
    node* newNode = new node;
    newNode->date = date;
    newNode->link = nullptr;
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        node* temp = head;
        while (temp->link != nullptr)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void tables::Reserve_tables(string date, int timee, int number_of_tables) {
    node* temp = head;
    while (temp != nullptr)
    {
        if (temp->date == date)
        {
            temp->tables_per_hours[timee - 4] -= number_of_tables;
        }
        temp = temp->link;
    }//اذا مالقينا النود اللي به التاريخ المحدد
    return;
}

void tables::cancelReserve_tables(string date, int timee, int number_of_tables) {
    node* temp = head;
    while (temp != nullptr)
    {
        if (temp->date == date)
        {
            temp->tables_per_hours[timee - 4] += number_of_tables;
        }
        temp = temp->link;
    }
    return;
}


bool tables::check(string date, int timee, int number_of_tables) {
    node* temp = head;
    //1- list is empty 
    if (temp == nullptr)
    {
        create_node(date);
        Reserve_tables(date, timee, number_of_tables);
        return true;
    }
    else if (head != nullptr)//2-list is not empty 
    {
        while (temp != nullptr)
        {
            if (temp->date == date)
            {
                if (temp->tables_per_hours[timee - 4] >= number_of_tables)
                {
                    Reserve_tables(date, timee, number_of_tables);
                    return true;//there are enough tables
                }
                else
                    return false;// there are not enough tables
            }
            else
                temp = temp->link;
        }
    }
    if (temp == nullptr)//we didn't find the date in whole list
    {
        create_node(date);
        Reserve_tables(date, timee, number_of_tables);
        return true;//there are enough tables
    }
    return 0;
}
int tables::tabel_numbers(int number_of_people) {
    int number_of_tables =0;
    if (number_of_people > 0 && number_of_people <= 5) {
        number_of_tables = 1;
    }
    else if (number_of_people > 5 && number_of_people <= 10) {
        number_of_tables = 2;
    }
    else if (number_of_people > 10 && number_of_people <= 15) {
        number_of_tables = 3;
    }
    else if (number_of_people > 15 && number_of_people <= 20) {
        number_of_tables = 4;
    }
    else if (number_of_people > 20 && number_of_people <=25) {
        number_of_tables = 5;
    }
    else if (number_of_people > 25 && number_of_people <= 30) {
        number_of_tables = 6;
    }
    else if (number_of_people > 30 && number_of_people <= 35) {
        number_of_tables = 7;
    }
    else if (number_of_people > 35 && number_of_people <= 40) {
        number_of_tables = 8;
    }
    else if (number_of_people > 40 && number_of_people <= 45) {
        number_of_tables = 9;
    }
    else if (number_of_people > 45 && number_of_people <= 50) {
        number_of_tables = 10;
    }
    else {
        cout << "No MORE TABLES ! " << endl;
    }

    return number_of_tables;
}












