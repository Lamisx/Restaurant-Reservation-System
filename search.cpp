#include "Reservation.h" 
void Reservation::searchReservation() {
    string phoneNumber;
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
            foundReservation = true;
            display_info(current);
            break;
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
            cout << "---------------------- Back to main menu ----------------------" << endl;
        }
    }
}