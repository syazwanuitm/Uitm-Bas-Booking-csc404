// busBooking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct bus {
    int busNo;
    int departFromCityId;
    int arrivalToCityId;
    int totalSeat;
};

struct city {
    int citiId;
    string cityName;
};

struct schedule {
    int scheduleId;
    int busNo;
    string date;
};

struct passenger {
    int passengerId;
    string passengerName;
    int age;
    int busNo;
};


// This function will print introduction on the system
void introduction()
{
    cout << "                      Hello                            \n\n         Welcome to UITM bus booking system         \n \n \n";
}

// This function will print all schedule detail
void showSchedule(city myCity[], bus myBus[], schedule mySchedule[])
{
    for (int i = 0; i < 5; i++)
    {
        int busNo = mySchedule[i].busNo;
        bus selectedBus = myBus[busNo - 1];
        city departure = myCity[selectedBus.departFromCityId - 1];
        city arrival = myCity[selectedBus.arrivalToCityId - 1];

        cout << " Bus no: " << mySchedule[i].busNo << "    Date: " << mySchedule[i].date << "\n";
        cout << " Departpure from: " << departure.cityName << "    Arrival: " << arrival.cityName << "\n";
        cout << " Bus total seat: " << selectedBus.totalSeat << "\n\n\n";
    }
}

// This function received user index number and get input from user to book and return the pessenger object
passenger KeyInPassenger(int currentUser)
{
    passenger myPassenger;

    cout << "\n Which bus would you like to book? Please enter bus no\n";
    cin >> myPassenger.busNo;
    cout << "\n Please enter your name\n";
    cin >> myPassenger.passengerName;
    cout << "\n Please enter your age\n";
    cin >> myPassenger.age;
    myPassenger.passengerId = currentUser;
    return myPassenger;
}

// Initilize passenger object
passenger busPassenger[100] = {};

// This function will loop to enter the passenger booking
void enterPassenger()
{
    for (int i = 0; i < 200; i++)
    {
        char act;

        busPassenger[i] = KeyInPassenger(i);

        cout << "\n  Do you want to continue add more passenger? Enter (Y) to add more and (C) to continue";
        cin >> act;
        if (act == 'C')
        {
            return;
        }
    }
}

//Seeding city
city myCity[5] = { {1,"Terminal Kuala Lumpur"},{2,"Terminal Johor"},{3,"Terminal Perak"},{4,"Terminal Selangor"},{5,"Terminal Perlis"} };


//Seeding bus
bus myBus[5] = { {1,1,2,20},{2,1,3,20},{3,1,4,20},{4,1,5,20},{5,1,3,20} };

//Seeding schedule
schedule mySchedule[5] = { {1,1,"12 July 2022"},{2,2,"19 July 2022"},{3,3,"17 July 2022"},{4,4,"16 July 2022"},{5,5,"15 July 2022"} };


int main()
{
    //bool machineOn = true;
   
    introduction();

    showSchedule(myCity, myBus, mySchedule);

    enterPassenger();
    

   
}


