#include <bits/stdc++.h>
using namespace std;
class Car
{
private:
    int carNumber;
    string carName;
    int age;
    string type;
    string Racingteam;
    int speed;
    int Capacity;

public:
    // setters and getters for all the private members of the class
    void setcarNumber(int CN)
    {
        if (CN > 0)
        {
            carNumber = CN;
        }
        else
        {
            cout << "Invalid Car Number\n";
        }
    }
    int getcarNumber()
    {
        return carNumber;
    }
    void setcarName(string CNm)
    {
        carName = CNm;
    }
    string getcarName()
    {
        return carName;
    }
    void setage(int a)
    {
        if (a > 0)
        {
            age = a;
        }
        else
        {
            cout << "Invalid Age\n";
        }
    }
    int getage()
    {
        return age;
    }
    void settype(string t)
    {
        type = t;
    }
    string gettype()
    {
        return type;
    }
    void setRacingteam(string RT)
    {
        Racingteam = RT;
    }
    string getRacingteam()
    {
        return Racingteam;
    }
    void setspeed(int s)
    {
        if (s > 0)
        {
            speed = s;
        }
        else
        {
            cout << "Invalid Speed\n";
        }
    }
    int getspeed()
    {
        return speed;
    }
    void setCapacity(int C)
    {
        if (C > 0)
        {
            Capacity = C;
        }
        else
        {
            cout << "Invalid Capacity\n";
        }
    }
    int getCapacity()
    {
        return Capacity;
    }
    void display()
    {
        cout << "Car Number: " << carNumber << "\n";
        cout << "Car Name: " << carName << "\n";
        cout << "Age: " << age << "\n";
        cout << "Type: " << type << "\n";
        cout << "Racing Team: " << Racingteam << "\n";
        cout << "Speed: " << speed << "\n";
        cout << "Capacity: " << Capacity << "\n";
    }
};
class Racer : public Car
{
private:
    int NumberOfRaces;
    int NumberofLaps;

public:
    // setters and getters for all the private members of the class
    void setNumberOfRaces(int NR)
    {
        NumberOfRaces = NR;
    }
    int getNumberOfRaces()
    {
        return NumberOfRaces;
    }
    void setNumberofLaps(int NL)
    {
        NumberofLaps = NL;
    }
    int getNumberofLaps()
    {
        return NumberofLaps;
    }
    void display()
    {
        Car::display();
        cout << "Number of Races: " << NumberOfRaces << "\n";
        cout << "Number of Laps: " << NumberofLaps << "\n";
    }
    int Performance()
    {
        int performance = (getspeed() * 10) + (getCapacity() * 1);
        return performance;
    }
};
class SupportVehicle : public Car
{
private:
    int CrewSize;
    int RelibiltyRating;

public:
    // setters and getters for all the private members of the class
    void setCrewSize(int CS)
    {
        CrewSize = CS;
    }
    int getCrewSize()
    {
        return CrewSize;
    }
    void setReliabilityRating(int RRating)
    {
        RelibiltyRating = RRating;
    }
    int getReliabilityRating()
    {
        return RelibiltyRating;
    }
    void display()
    {
        Car::display();
        cout << "Crew Size: " << CrewSize << "\n";
        cout << "Reliability Rating: " << RelibiltyRating << "\n";
    }
    int Performance()
    {
        int performance = (getspeed() * 5) + (getCapacity() * 5);
        return performance;
    }
};
// Function to save the data of the Racers and Support Vehicles in the garage to a file
 void saveData(vector<Racer> &r,vector<SupportVehicle> &S)
{
    ofstream file("garage.txt");
    for(auto &car : r)
    {
        file << "Racer\n";
        file << car.getcarNumber() << "\n";
        file << car.getcarName() << "\n";
        file << car.getage() << "\n";
        file << car.gettype() << "\n";
        file << car.getRacingteam() << "\n";
        file<<car.getspeed()<<"\n";
        file<<car.getCapacity()<<"\n";
        file << car.getNumberOfRaces() << "\n";
        file << car.getNumberofLaps() << "\n";

    }
    for(auto &vechile : S)
    {
        file << "SupportVehicle\n";
        file << vechile.getcarNumber() << "\n";
        file << vechile.getcarName() << "\n";
        file << vechile.getage() << "\n";
        file << vechile.gettype() << "\n";
        file << vechile.getRacingteam() << "\n";
        file << vechile.getspeed() << "\n";
        file << vechile.getCapacity() << "\n";
        file << vechile.getCrewSize() << "\n";
        file << vechile.getReliabilityRating() << "\n";
    }

    file.close();
}
// Function to load the data of the Racers and Support Vehicles in the garage from a file
void loadData(vector<Racer>& r, vector<SupportVehicle>& S)
{
    ifstream file("garage.txt");

    if (!file)
    {
        return;
    }

    string vehicleType;

    while (file >> vehicleType)
    {
        if (vehicleType == "Racer")
        {
            Racer temp;

            int carNumber, age, speed, capacity;
            int races, laps;
            string carName, type, team ;
            file>> carNumber>> carName>> age >> type >> team >> speed >> capacity >> races >> laps;
            temp.setcarNumber(carNumber);
            temp.setcarName(carName);
            temp.setage(age);
            temp.settype(type);
            temp.setRacingteam(team);
            temp.setspeed(speed);
            temp.setCapacity(capacity);
            temp.setNumberOfRaces(races);
            temp.setNumberofLaps(laps);
            r.push_back(temp);
        }

        else if (vehicleType == "SupportVehicle")
        {
            SupportVehicle temp;

            int carNumber, age, speed, capacity;
            int crewSize, rating;
            string carName, type, team;
            file >> carNumber >> carName >> age >> type >> team >> speed >> capacity >> crewSize >> rating;
            temp.setcarNumber(carNumber);
            temp.setcarName(carName);
            temp.setage(age);
            temp.settype(type);
            temp.setRacingteam(team);
            temp.setspeed(speed);
            temp.setCapacity(capacity);
            temp.setCrewSize(crewSize);
            temp.setReliabilityRating(rating);
            S.push_back(temp);
        }
    }

    file.close();
}

int main()
{
   
    vector<Racer> r;
    vector<SupportVehicle> S;
    loadData(r, S);
    int CN, a, s, C, NR, NL, CS, RRating, type, choice;
    string CNm, t, RT;
    bool found = false;
    do
    {
        cout << "======Main Menu======\n";
        cout << "1. check in\n";
        cout << "2. View the garage\n";
        cout << "3. Tune_Up\n";
        cout << "4. Retire\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the type of vehicle (1 for Racer, 2 for Support Vehicle): ";
            cin >> type;
            if (type == 1)
            {
                Racer r1;
                cout << "Enter Car Number: ";
                cin >> CN;
                bool exists = false;
                for (auto &car : r)
                {
                    if (car.getcarNumber() == CN)
                    {
                        exists = true;
                        break;
                    }
                }
                if(exists)
                {
                    cout << "car number already exists\n";
                    break;
                }
                else
                {
                    r1.setcarNumber(CN);
                }
                
                cout << "Enter Car Name: ";
                cin >> CNm;
                r1.setcarName(CNm);
                cout << "Enter Age: ";
                cin >> a;
                r1.setage(a);
                cout << "Enter Type: ";
                cin >> t;
                r1.settype(t);
                cout << "Enter Racing Team: ";
                cin >> RT;
                r1.setRacingteam(RT);
                cout << "Enter Speed: ";
                cin >> s;
                r1.setspeed(s);
                cout << "Enter Capacity: ";
                cin >> C;
                r1.setCapacity(C);
                cout << "Enter Number of Races: ";
                cin >> NR;
                r1.setNumberOfRaces(NR);
                cout << "Enter Number of Laps: ";
                cin >> NL;
                r1.setNumberofLaps(NL);
                cout << "performance is " << r1.Performance() << "\n";
                r.push_back(r1);
                //saving the data to the file after checking in the Racer to the garage
                saveData(r, S);
                cout << "Racer added successfully!\n";
            }
            if (type == 2)
            {
                SupportVehicle s1;
                cout << "Enter Car Number: ";
                cin >> CN;
                bool exists = false;
                for (auto &vechile : S)
                {
                    if (vechile.getcarNumber() == CN)
                    {
                        exists = true;
                        break;
                    }
                }
                if(exists)
                {
                    cout << "car number already exists\n";
                    break;
                }
                else
                {
                    s1.setcarNumber(CN);
                }
                cout << "Enter Car Name: ";
                cin >> CNm;
                s1.setcarName(CNm);
                cout << "Enter Age: ";
                cin >> a;
                s1.setage(a);
                cout << "Enter Type: ";
                cin >> t;
                s1.settype(t);
                cout << "Enter Racing Team: ";
                cin >> RT;
                s1.setRacingteam(RT);
                cout << "Enter Speed: ";
                cin >> s;
                s1.setspeed(s);
                cout << "Enter Capacity: ";
                cin >> C;
                s1.setCapacity(C);
                cout << "Enter Crew Size: ";
                cin >> CS;
                s1.setCrewSize(CS);
                cout << "Enter Reliability Rating: ";
                cin >> RRating;
                s1.setReliabilityRating(RRating);
                cout << "Performance is:\n " << s1.Performance();
                S.push_back(s1);
                //saving the data to the file after checking in the Support Vehicle
                saveData(r, S);
                cout << "Support Vehicle added successfully!\n";
            }
            break;
        case 2:
            cout << "Current Garage:\n";
            cout << "Racers:\n";
            for (auto &car : r)
            {
                car.display();
            }
            cout << "Support Vehicles:\n";
            for (auto &vechile : S)
            {
                vechile.display();
            }
            break;
        case 3:
            found = false;
            cout << "Enter the type of vehicle (1 for Racer, 2 for Support Vehicle): ";
            cin >> type;
            if (type == 1)
            {
                cout << "Enter the Car Number of the vehicle to tune up: ";
                cin >> CN;
                for (auto &car : r)
                {
                    if (car.getcarNumber() == CN)
                    {
                        found = true;
                        cout << "Enter new Speed: ";
                        cin >> s;
                        car.setspeed(s);
                        cout << "Enter new Capacity: ";
                        cin >> C;
                        car.setCapacity(C);
                        cout << "The new performance is: " << car.Performance() << "\n";
                    }
                }
                if (!found)
                {
                    cout << "Car Number not found\n";
                }
                 //saving the data to the file after tuning up the Racer
                saveData(r, S);
            }
            if (type == 2)
            {
                cout << "Enter the Car Number of the vehicle to tune up: ";
                cin >> CN;
                for (auto &vechile : S)
                {
                    if (vechile.getcarNumber() == CN)
                    {
                        found = true;
                        cout << "Enter new Speed: ";
                        cin >> s;
                        vechile.setspeed(s);
                        cout << "Enter new Capacity: ";
                        cin >> C;
                        vechile.setCapacity(C);
                        cout << "The new performance is: " << vechile.Performance() << "\n";
                    }
                }
                if (!found)
                {
                    cout << "Car Number not found\n";
                }
             //saving the data to the file after tuning up the Support Vehicle
            saveData(r,S);
            }
            break;
        case 4:
            found = false;
            cout << "Enter the type of vehicle (1 for Racer, 2 for Support Vehicle):";
            cin >> type;
            if (type == 1)
            {
                cout << "Enter the Car Number of the vehicle to retire: ";
                cin >> CN;
                for (int i = 0; i < r.size(); i++)
                {
                    if (r[i].getcarNumber() == CN)
                    {
                        found = true;
                        r.erase(r.begin() + i);
                        cout << "Racer retired successfully!\n";
                        //saving the data to the file after retiring the Racer
                        saveData(r, S);
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Car Number not found\n";
                }
            }
            if (type == 2)
            {
                cout << "Enter the Car Number of the vehicle to retire: ";
                cin >> CN;
                for (int i = 0; i < S.size(); i++)
                {
                    if (S[i].getcarNumber() == CN)
                    {
                        found = true;
                        S.erase(S.begin() + i);
                        cout << "Support Vehicle retired successfully!\n";
                        //saving the data to the file after retiring the Support Vehicle
                        saveData(r, S);
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Car Number not found\n";
                }
            }
            break;
        case 5:
            found = false;
            cout << "Enter the type of vehicle (1 for Racer, 2 for Support Vehicle): ";
            cin >> type;
            if (type == 1)
            {
                cout << "Enter the Car Number of the vehicle to search for: ";
                cin >> CN;
                for (int i = 0; i < r.size(); i++)
                {
                    if (r[i].getcarNumber() == CN)
                    {
                        found = true;
                        r[i].display();
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Car Number not found\n";
                }
            }
            if (type == 2)
            {
                cout << "Enter the Car Number of the vehicle to search for: ";
                cin >> CN;
                for (int i = 0; i < S.size(); i++)
                {
                    if (S[i].getcarNumber() == CN)
                    {
                        found = true;
                        S[i].display();
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Car Number not found\n";
                }
            }
            break;
        case 6:
            cout << "Goodbye!\n";
            break;
        }
        }while (choice != 6);

return 0;
}
// This code implements a garage management system for Racers and Support Vehicles. It allows users to check in vehicles, view the garage, tune up vehicles, retire vehicles, and search for vehicles by their car number. The data is saved to and loaded from a file named "garage.txt".
//making comments for the code to explain the functionality of each part of the code
// The code starts by including the necessary libraries and defining the Car class, which has private members for car number, name, age, type, racing team, speed, and capacity. It also has public setters and getters for these members, as well as a display function to print the car's details.
// The Racer class inherits from the Car class and adds private members for the number of races
// and number of laps, along with their respective setters and getters. It also has a display function that calls the base class's display function and prints the additional details, as well as a Performance function that calculates the performance of the racer based on speed and capacity.