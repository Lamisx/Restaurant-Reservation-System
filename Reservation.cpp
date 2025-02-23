#include "Reservation.h" 

tables t;
//global object to use functions from tables class
Reservation::Reservation() { head = nullptr; }

Reservation::Reservation(string name, string phone_number, string date, int timee, int num_people, int thepay)
    : name(name), phone_number(phone_number), date(date), timee(timee), num_people(num_people), thepay(thepay), status("Pending") {}

void Reservation::display_info(Node* cur) {
    cout << "----------------------------------------------------------------" << endl;
    cout << "|                    Reservation Information                    |" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "|Name: " << cur->name << endl;
    cout << "|Phone Number: " << cur->phone_number << endl;
    cout << "|Date : " << cur->date << endl;
    cout << "|Time: " << cur->timee << endl;
    cout << "|Number of People: " << cur->num_people << endl;
    cout << "|Status: " << cur->status << endl;
    cout << " ---------------------------------------------------------------" << endl;
}
//(05& 10 digits)التأكد من ادخال رقم الهاتف بشكل صحيح
bool Reservation::isValidPhoneNumber(const string& phone) {
    regex pattern(R"(^05\d{8}$)");
    return regex_match(phone, pattern);
}
//(YYYY-MM-DD)التأكد من ادخال التاريخ بشكل صحيح
bool Reservation::isValidDateFormat(const string& date) {
    regex pattern(R"(^\d{4}-\d{2}-\d{2}$)");
    return regex_match(date, pattern);
}

bool Reservation::isValidTimeFormat(int hour) {
    return (hour >= 4 && hour <= 12);
    // Valid times: 4 PM to 12 AM
}

void Reservation::insertdata() {
    cout << "----------------------------------------------------------------" << endl;
    cout << "|                Iserat Reservation Data                       |" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Enter your name: ";
    //cin.ignore(); // Ignore the newline character from previous input
    //getline(cin, name);
    cin >> name;

    cout << "Enter your phone number (starting with 05,10 digits): ";
    cin >> phone_number;
    while (!isValidPhoneNumber(phone_number)) {//اذا كان طريقه ادخال الرقم غلط يطلب من اليوزر يرجع يدخل الرقم من جديد
        cout << "Invalid phone number format. Please enter again: ";
        cin >> phone_number;
    }

    cout << "Enter date of reservation (e.g., YYYY-MM-DD): ";
    cin >> date;
    while (!isValidDateFormat(date)) {
        cout << "Invalid date format. Please enter again: ";
        cin >> date;
    }

    cout << "Enter number of people: ";
    cin >> num_people;

    cout << "Enter hour of reservation (4 PM to 12 AM): ";
    cin >> timee;
    while (!isValidTimeFormat(timee)) {
        cout << "Invalid hour format. Please enter again (4 PM to 12 AM): ";
        cin >> timee;
    }
    //تم استدعاء الفنكشن عشان تاخذ المتغيرات وتحفظها
    make_reservation(name, phone_number, date, timee, num_people, thepay);
}

void Reservation::make_reservation(string name, string phone_number, string date, int timee, int num_people, int thepay) {
    Node* newReservation = new Node;
    newReservation->name = name;
    newReservation->phone_number = phone_number;
    newReservation->date = date;
    newReservation->timee = timee;
    newReservation->num_people = num_people;
    newReservation->status = "Pending";
    newReservation->next = nullptr;
    newReservation->thepay = thepay;
    num_tabels = t.tabel_numbers(num_people);//send number of people to tables numbers function , store the returned value in this variable
    bool cheacx = false;
    while (!cheacx)
    {
        if (t.check(date, timee, num_tabels)) {
            cout << "----------------------------------------------------------------" << endl;
            cout << "\nCreate an active reservation To complete your reservation, please pay the deposit." << endl;
            make_deposit(newReservation);
            display_info(newReservation);
            cheacx = true;
            cout << endl;
        }else
        {
            cout << "the restaurant is full try to enter another time " << endl;
            cout << "Enter hour of reservation (4 PM to 12 AM): ";
            cin >> timee;
            while (!isValidTimeFormat(timee)) {
                cout << "Invalid hour format. Please enter again (4 PM to 12 AM): ";
                cin >> timee;
            }
         }
    }


    if (head == nullptr) {
        head = newReservation;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newReservation;
    }

}

void Reservation::make_deposit(Node* newReservation) {
    int deposit_amount;
    int remainingAmount;

    cout << "Enter deposit amount: ";
    cin >> deposit_amount;

    if (deposit_amount >= 150) {
        num = deposit_amount - 150; // لفنكشن إلغاء الحجز
        newReservation->status = "Confirmed";
        cout << "Deposit of " << deposit_amount << " successfully made." << endl;
    }
    // اذا العربون اقل من 150
    else {
        cout << "Sorry, the deposit must be at least 150." << endl;
        cout << "Please choose one of the following options:" << endl;
        cout << "1. Cancel the reservation." << endl;
        cout << "2. Complete the payment." << endl;

        int choice;
        cin >> choice;
        int totalDeposit = deposit_amount;
        switch (choice) {
        case 1:
            cout << "The reservation has been canceled." << endl;
            newReservation->status = "Canceled";
            break;
        case 2:
            cout << "The payment has been partially completed." << endl;
            int TheRest = 150 - deposit_amount;
            cout << "Please add the remaining amount: " << "(" << TheRest << ")  ";

            do {

                cin >> remainingAmount;
                totalDeposit += remainingAmount;
                TheRest = 150 - totalDeposit;
                if (totalDeposit < 150) {
                    cout << "The total deposit must be at least 150. Please enter the remaining amount: " << "(" << TheRest << ")  ";
                }
            } while (totalDeposit < 150);

            if (totalDeposit == 150 || totalDeposit >= 150) {
                newReservation->status = "Confirmed";
                cout << "Deposit of " << totalDeposit << " successfully made." << endl;

            }
            break;
            //   default:
            cout << "Invalid choice." << endl;
            cout << "The reservation has been canceled." << endl;
            newReservation->status = "Canceled";
            break;
        }
        return;
    }

}

void Reservation::cancelReservation()
{
    string phoneNumber;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Enter your phone number  (starting with 05, maximum 10 digits): ";
    cin >> phoneNumber;
    cout << "----------------------------------------------------------------" << endl;
    while (!isValidPhoneNumber(phoneNumber)) {
        cout << "Invalid phone number format. Please enter again: ";
        cin >> phoneNumber;
    }

    Node* current = head;
    bool foundReservation = false;
    while (current != nullptr) {
        if (current->phone_number == phoneNumber) {
            if (current->status == "Completed") {
                cout << "Your reservation is not found or has been completed." << endl;
                return;
            }
            else {
                cout << "Do you want to cancel your reservation? (Y/N): ";
                char choice;
                cin >> choice;
                if (toupper(choice) == 'Y') {
                    t.cancelReserve_tables(date, timee, num_tabels);
                    //refund_deposit();
                    current->status = "Cancelled"; // Update the status of the reservation
                    cout << "Your reservation has been successfully cancelled." << endl;
                    cout << "Your deposit " << num << " has been refounded." << endl;
                }
                else {
                    cout << "Your reservation remains unchanged." << endl;
                }
            }
        }
        current = current->next;
    }

    if (!foundReservation) {
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
void Reservation::calculateDailyProfit() {
    cout << "enter the day u want to calculate the incomes for" << endl;
    cin >> date;
    while (!isValidDateFormat(date)) {
        cout << "Invalid date format. Please enter again: ";
        cin >> date;
    }
    int totalProfit = 0;

    Node* current = head;
    while (current != nullptr) {
        if (current->date == date && current->status == "Completed") {
            totalProfit += current->thepay;
        }
        current = current->next;
    }

    cout << "Total profit for " << date << ": " << totalProfit << " SAR" << endl;
}



