/*Sakif Chowdhury
CISC 1600
Professor Dakota Hernandez

Fordham Air

Last Edited February 7th, 2023
*/

#include <iostream>
using namespace std;

int main()
{
    char destination;
    cout << "Welcome to Fordham Airlines!\n"
         << "What is your destination? ([C]hicago, [M]iami, [P]ortland): ";
    cin >> destination;

    int flightTime;
    cout << "What time will you travel? (Enter time between 0-2359): ";
    cin >> flightTime;

    char isWeekend;
    cout << "What type of day are you traveling? (week[E]nd or week[D]ay): ";
    cin >> isWeekend;

    double ticketPrice;

    if (destination == 'M') {
        if (isWeekend == 'E') {
            if (flightTime >= 600 && flightTime < 1800) {
                ticketPrice = 150.0;
            } else {
                ticketPrice = 100.0;
            }
        } else {
            if (flightTime >= 600 && flightTime < 1800) {
                ticketPrice = 180.0;
            } else {
                ticketPrice = 120.0;
            }
        }
    } else if (destination == 'C') {
        if (isWeekend == 'E') {
            if (flightTime >= 600 && flightTime < 1800) {
                ticketPrice = 75.0;
            } else {
                ticketPrice = 50.0;
            }
        } else {
            if (flightTime >= 600 && flightTime < 1800) {
                ticketPrice = 90.0;
            } else {
                ticketPrice = 60.0;
            }
        }
    } else {
        if (isWeekend == 'E') {
            if (flightTime >= 600 && flightTime < 1800) {
                ticketPrice = 300.0;
            } else {
                ticketPrice = 200.0;
            }
        } else {
            if (flightTime >= 600 && flightTime < 1800) {
                ticketPrice = 360.0;
            } else {
                ticketPrice = 240.0;
            }
        }
    }

    cout << "Enter the number of tickets you wish to purchase: ";
    int numTickets;
    cin >> numTickets;

    if (numTickets < 0) {
        cout << "Invalid number of tickets ordered. Order cancelled." << endl;
        return 0;
    }

    double totalCost = ticketPrice * numTickets;
    cout << "The total amount due is: $" << totalCost << endl;

    cout << "Enter the amount you are paying: $";
    double userPayment;
    cin >> userPayment;

    if (userPayment < totalCost) {
        cout << "Amount paid is too little. Order cancelled." << endl;
        return 0;
    }

    double change = userPayment - totalCost;
    cout << "Your change is: $" << change << endl;
    cout << "Your order has been placed. Thank you for choosing Fordham Airlines!" << endl;

    return 0;
}

