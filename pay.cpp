#include "Reservation.h" 

void Reservation::payiReservation() {
    int  m; string phoneNumber;

    cout << "Enter your phone number to search for a reservation (starting with 05, maximum 10 digits): ";
    cin >> phoneNumber;

    while (!isValidPhoneNumber(phoneNumber)) {
        cout << "Invalid phone number format. Please enter again: ";
        cin >> phoneNumber;
    }

    Node* current = head;
    bool foundReservation = false;
    while (current != nullptr) {
        if (current->phone_number == phoneNumber) {
            if (current->status != "Cancelled" || current->status != "Completed")
            {
                foundReservation = true;
                cout << "enter ur total bill today: (should be  more 250 or equal) ";
                cin >> m;

                if (m >= 250) {
                    thepay = m - 150;

                    current->status = "Completed";
                    cout << "ur invoic calculate: " << thepay << endl;
                    cout << "Reservation status : " << current->status << endl;
                }
                else {
                    while (m <250)
                    {
                        cout << "sorry, ur total bill (should be  more 250 equal):  ";
                        cin >> m;
                    }

                    current->status = "Completed";
                    cout << "ur invoic calculate: " << thepay << endl;
                    cout << "Reservation status : " << current->status << endl;
                }
            } else{
            cout << "You can't make payment for Cancelled Reservation or Completed " << endl;
            return;
            }
         }
           
        current = current->next;
    }
    if (!foundReservation) {
        cout << "No reservation found for phone number: " << phoneNumber << endl;
        cout << "Would you like to make a new reservation? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            insertdata();
        }
        else {
            cout << "--------------- Back to main menu ---------------" << endl;
        }
    }
}
