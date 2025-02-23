#include <iostream>
#include "Reservation.h"

using namespace std;


int main() {

    

    Reservation res;
    int choice = 0;
    bool a = false;
    while (!a)
    {
        cout <<"Welcome to the Restaurant Reservation System (RRS)...."<<endl;
        cout <<" "<<endl;
        cout <<"Please choose from the following menu:"<<endl;
        cout <<"1-Add reservation." << endl;
        cout <<"2-Search for a reservation." << endl;
        cout <<"3-Make a payment."<<endl;
        cout <<"4-Cancel a reservation."<<endl;
        cout <<"5-daily income."<<endl;
        cout <<"6-Exit."<<endl<<endl;
        cout <<"Enter your choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                res.insertdata();

                break;
            case 2:
                res.searchReservation();
                break;

            case 3 :
                res.payiReservation();
                  break;
            case 4:
                res.cancelReservation();
                  break;
            case 5:
                res.calculateDailyProfit(); 
                 break;
            case 6:
             cout << "Exiting." << endl;
                  a = true ;
                  break;
            default:
                cout << "Invalid option,Please try again." << endl;
            }
            
    }
    cout << "We are happy to serve you." << endl;

    return 0;
}






// void DailyIncome(Reservation& res);

// int main() {

    

//     Reservation res;
//     int choice = 0;
//     bool a = false;
//     while (!a)
//     {
//         cout << "1- insert" << endl;
//         cout << "2- pay" << endl;
//         cout << "3 to exit"<<endl;
//             cout << "enter your chois : ";
//             cin >> choice;
//             switch (choice)
//             {
//             case 1:
//                 res.insertdata();

//                 break;
//             case 2:
//                 res.payiReservation();
//                 break;

//             case 3 :
//                 a = true;
//                   break;
//             }
//     }
//     cout << "daily income" << endl;
//     DailyIncome(res);
//     return 0;
// }

// void DailyIncome(Reservation& res) {
//     dayNode* N = hd;//point to day
//     Reservation::Node* r = res.head;//point to Reservation
//     while (N != nullptr)
//     {
//         int total = 0;
//         r = res.head;
//         while (r != nullptr)
//         {
//             if (N->Ddate == r->date && res.status == "Completed")
//             {
//                 total += res.thepay;
//             }
//             else
//                 r = r->next;
//         }
//         cout << "Daily Income for " << N->Ddate << " = " << total << endl;
//         N = N->link;
//     }

// }

