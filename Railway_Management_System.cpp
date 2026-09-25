#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class train{
    public : 
        int train_no;
        string train_name;
        string source; 
        string destination;
        string route;
        string departureTime;
        string arrivalTime;
        string duration;
        string distance;
        string availableClasses;
        int totalSeats;
        int availableSeats;
        int seatSL;
        int seat3Ac;
        int seat2Ac;
        int maxcapSL;
        int maxcap3Ac;
        int maxcap2Ac;
        float fare;
};

class userData{
    public : 
        string name;
        string age;
        string boardingDate;
};

userData usersList;
train trainsList[6];
// Ticket storage for each train
int ticketCollectionTrain1[1250] = {};
int ticketCollectionTrain2[1250] = {};
int ticketCollectionTrain3[1250] = {};
int ticketCollectionTrain4[1250] = {};
int ticketCollectionTrain5[1250] = {};
int ticketCollectionTrain6[1250] = {};

//Complete Ticket Database 
struct TicketDatabaseWithUserInfo{
    public : 
        int traincode;
        int TicketNumber;
        string name;
        string arrivalTime;
        string departureTime;
        string source;
        string destination;
        string seatType;
        int seatNo;
        int quantity;
        float fare;
        string date;
};

int record = 0;
TicketDatabaseWithUserInfo Data[1250];
void getUserData(train trainsList[],int ticketNumber,TicketDatabaseWithUserInfo Data[],int TrainID,int &record,string seatType,int seatNo,int quantity,float fare);
void displayOptions();
void createTrains();
void searchTrains(train trainList[]);
void ViewallTrains(train trainList[]);
void checkAvailability(train trainlist[]);
void bookTicket(train trainlist[]);
void ticketToSeatConnector(train trainlist[]);
bool ticketCheck(int ticketData[],int size,int ticketNumber);
void uploadingDataInCollection(int *Train1TicketStorage,int *Train2TicketStorage,int *Train3TicketStorage,int *Train4TicketStorage,int *Train5TicketStorage,int *Train6TicketStorage,int TrainSearchID,train trainlist[],int ticketNumber);
void generateTicket(train trainslist[],TicketDatabaseWithUserInfo Data[],int record);
void viewTicket();
void cancelTicket();
void viewBookingHistory();

int main(){
    srand(time(NULL));
    cout << "========================================" << "\n";
    cout << "|       RAILWAY RESERVATION SYSTEM      | " << "\n";
    cout << "========================================" << "\n";
    cout << "\n";
    createTrains();
    displayOptions();
    
    return 0;
}

void displayOptions(){
    int choice = 0;
    cout << "1. View all Trains" << '\n';
    cout << "2. Search Train" << '\n';
    cout << "3. Check Seat Availability" << '\n';
    cout << "4. Book Ticket" << '\n';
    cout << "5. View Ticket" << '\n';
    cout << "6. Cancel Ticket" << '\n';
    cout << "7. View Booking History" << '\n';
    cout << "8. Exit" << '\n';
    while(choice != 8){
        cout << "Enter your action here :";
        cin >> choice;
        //executing the function here 
        if(choice == 1){
            ViewallTrains(trainsList);
        }
        else if (choice == 2){
            searchTrains(trainsList);
        }
        else if(choice == 3){   
            checkAvailability(trainsList);
        }
        else if(choice == 4){
            bookTicket(trainsList);
        }
        else if(choice == 5){
            viewTicket();
        }
        else if(choice == 6){
            cancelTicket();
        }
        else if(choice == 7){
            viewBookingHistory();
        }
        else if(choice == 8){
            cout << "Thank you for using Railway Reservation System.\n";
        }
        else{
            cout << "Enter a valid choice !!!!";
        }
    }
}

void createTrains(){

    //1


    trainsList[0].train_no = 12001;
    trainsList[0].train_name = "Northern Express";
    trainsList[0].source = "New Delhi";
    trainsList[0].destination = "Lucknow";
    trainsList[0].departureTime = "6:00 ";
    trainsList[0].arrivalTime = "12:30 "; 
    trainsList[0].distance = "512 KM";
    trainsList[0].duration = "6 hr 30m";
    trainsList[0].totalSeats = 900;
    trainsList[0].availableSeats = 900;
    trainsList[0].seatSL = 500;
    trainsList[0].seat3Ac = 300;
    trainsList[0].seat2Ac = 100;
    trainsList[0].availableClasses = 
    "|   Sleeper Class   |     3AC Class     |     2AC Class     |";
    trainsList[0].maxcapSL = 500;
    trainsList[0].maxcap2Ac = 100;
    trainsList[0].maxcap3Ac = 300;
    trainsList[0].fare = 500.0;

    //2
        
    trainsList[1].train_no = 12002;
    trainsList[1].train_name = "Deccan Express";
    trainsList[1].source = "Mumbai";
    trainsList[1].destination = "Pune";
    trainsList[1].departureTime = "07:10";
    trainsList[1].arrivalTime = "10:25";
    trainsList[1].distance = "192 KM";
    trainsList[1].duration = "3 hr 15m";
    trainsList[1].totalSeats =  680;
    trainsList[1].availableSeats =  680;
    trainsList[1].seatSL = 400;
    trainsList[1].seat2Ac = 80;
    trainsList[1].seat3Ac = 200;
    trainsList[1].availableClasses = 
    "|   Sleeper Class   |   3AC Class   |   2AC Class   |";
    trainsList[1].maxcapSL = 400;
    trainsList[1].maxcap2Ac = 80;
    trainsList[1].maxcap3Ac = 200;
    trainsList[1].fare = 450.0;
    
    //3
    
    trainsList[2].train_no = 12301;
    trainsList[2].train_name = "Eastern Express";
    trainsList[2].source = "New Delhi";
    trainsList[2].destination = "Kolkata";
    trainsList[2].departureTime = "16:55";
    trainsList[2].arrivalTime = "10:00";
    trainsList[2].distance = "1451 km";
    trainsList[2].duration = "17h 05m";
    trainsList[2].totalSeats = 1070;
    trainsList[2].availableSeats = 1070;    
    trainsList[2].seatSL = 600;
    trainsList[2].seat2Ac = 120;
    trainsList[2].seat3Ac = 350; 
    trainsList[2].availableClasses = 
    "|   Sleeper Class   |   3AC Class   |   2AC Class   |" ; 
    trainsList[2].maxcapSL = 600;
    trainsList[2].maxcap2Ac = 120;
    trainsList[2].maxcap3Ac = 350;
    trainsList[2].fare = 900.0;
    //4
    
    trainsList[3].train_no = 12401 ;
    trainsList[3].train_name = "Desert Express";
    trainsList[3].source = "New Delhi";
    trainsList[3].destination = "Jaipur";
    trainsList[3].departureTime = "06:15";
    trainsList[3].arrivalTime = "10:45";
    trainsList[3].distance = "303 km";
    trainsList[3].duration = "4h 30m";
    trainsList[3].totalSeats = 780;
    trainsList[3].availableSeats = 780;
    trainsList[3].seatSL = 450;
    trainsList[3].seat3Ac = 250;
    trainsList[3].seat2Ac = 80;
    trainsList[3].availableClasses = 
    "|   Sleeper Class   |   3AC Class   |   2AC Class   |";
    trainsList[3].maxcapSL = 450;
    trainsList[3].maxcap2Ac = 80;
    trainsList[3].maxcap3Ac = 250;
    trainsList[3].fare = 400.0;
    //5
    
    trainsList[4].train_no = 12951;
    trainsList[4].train_name = "Western Rajdhani";
    trainsList[4].source = "Mumbai";
    trainsList[4].destination = "New Delhi";
    trainsList[4].departureTime = "17:00";
    trainsList[4].arrivalTime = "08:35";
    trainsList[4].distance = "1384 km";
    trainsList[4].duration = "15h 35m";
    trainsList[4].totalSeats = 550;
    trainsList[4].availableSeats = 550;
    trainsList[4].seatSL = 0;
    trainsList[4].seat2Ac = 150;
    trainsList[4].seat3Ac = 400;
    trainsList[4].availableClasses = 
    "|   Sleeper Class   |   3AC Class   |   2AC Class   |";
    trainsList[4].maxcapSL = 0;
    trainsList[4].maxcap2Ac = 150;
    trainsList[4].maxcap3Ac = 400;
    trainsList[4].fare = 1200.0;
    //6
    
    trainsList[5].train_no = 12627;
    trainsList[5].train_name = "Southern Express";
    trainsList[5].source = "New Delhi";
    trainsList[5].destination = "Chennai";
    trainsList[5].departureTime = "21:05";
    trainsList[5].arrivalTime = "05:45";
    trainsList[5].distance = "2180 km";
    trainsList[5].duration = "32h 40m";
    trainsList[5].totalSeats = 1250;
    trainsList[5].availableSeats = 1250;
    trainsList[5].seatSL = 700;
    trainsList[5].seat3Ac = 400;
    trainsList[5].seat2Ac = 150;
    trainsList[5].availableClasses = 
    "|   Sleeper Class   |   3AC Class   |   2AC Class   |";
    trainsList[5].maxcapSL = 700;
    trainsList[5].maxcap2Ac = 150;
    trainsList[5].maxcap3Ac = 400;
    trainsList[5].fare = 1500.0;
}

void ViewallTrains(train trainsList[]){
    cout << "Available Trains : " << "\n";
    for(int i = 0; i < 6; i++){
        cout << "Train Code : " << trainsList[i].train_no<< " | "<<"Train Name : " <<trainsList[i].train_name <<'\n';
    }
}

void searchTrains(train trainsList[]){
    int train_id;
    bool found = false;
    cout << "Enter the Train ID : ";
    cin >> train_id;

    for(int i = 0; i < 6;i++){
        if(train_id == trainsList[i].train_no){
            found = true;
            cout << "Train Found!!" << "\n" ;
            cout << "Train Code : " <<trainsList[i].train_no << "\n";
            cout << "Train Name : " <<trainsList[i].train_name << "\n";
            cout << "Train Source : "<<trainsList[i].source << '\n';
            cout << "Train Destination : " << trainsList[i].destination << "\n";
            cout << "Train Departure Time : " << trainsList[i].departureTime << "\n";
            cout << "Train Arrival Time : " << trainsList[i].arrivalTime << "\n";
            cout << "Train Distance : " << trainsList[i].distance << '\n';
            cout << "Train Duration : " << trainsList[i].duration << '\n';
            cout << "Available Seats in Train : " << trainsList[i].availableSeats << '\n';
            cout << "Available Seats Classes : "<< '\n' << trainsList[i].availableClasses << '\n';
            cout << "Seats in Sleeper Class : " << trainsList[i].seatSL << '\n';
            cout << "Seats in 3AC Class : " << trainsList[i].seat3Ac << '\n';
            cout << "Seats in 2AC Class : " << trainsList[i].seat2Ac << '\n';
            cout << "Base Fare : Rs. " << trainsList[i].fare << '\n';
        }
    }
    if(!found){
        cout << "Train not found. Please enter a valid Train ID.\n";
    }
}

void checkAvailability(train trainlist[]){
    int searchID;
    bool found = false;
    cout << "Please enter your Train ID : ";
    cin >> searchID;
    cout << "Available Seats Classes : " << '\n';
    for(int i = 0;i < 6;i++){
        if(searchID == trainlist[i].train_no){
            found = true;
            cout << trainlist[i].availableClasses << '\n';
            cout << "|         "<<trainlist[i].seatSL<<"         |         "<<trainlist[i].seat3Ac<<"         |         "<<trainlist[i].seat2Ac<<"         |" <<'\n';
        }
    }
    if(!found){
        cout << "Train not found. Please enter a valid Train ID.\n";
    }
}

void bookTicket(train trainlist[]){
    int trainID;
    int quantity;
    int seatType;
    int ticketNumber;

    cout << "------------------------------Ticket Counter------------------------------" << '\n';

    cout << "Current Available Trains: " << '\n';
    ViewallTrains(trainsList);

    cout << "--------------------------------------------------------------------------" << '\n';

    cout << "Please enter the train number : ";
    cin >> trainID;

    // Search for the train
    for(int i = 0; i < 6; i++)
    {
        if(trainID == trainlist[i].train_no)
        {
            cout << "Train found !!!" << '\n';

            cout << "Please enter the type of seat you want to book :" << '\n';
            cout << "1. Sleeper Seats" << '\n';
            cout << "2. 3AC Seats" << '\n';
            cout << "3. 2AC Seats" << '\n';

            cin >> seatType;

            cout << "Please enter the no. of seats which you want to book : ";
            cin >> quantity;

            // First check total available seats
            if(quantity <= 0 || quantity > trainlist[i].availableSeats)
            {
                cout << "Invalid quantity or not enough seats available." << '\n';
                return;
            }

            string seatTypeName;
            int classMaximumCapacity = 0;
            int startSeatNumber = 1;

            switch(seatType)
            {
                case 1:

                    // Check Sleeper availability
                    if(quantity <= trainlist[i].seatSL)
                    {
                        if(trainlist[i].maxcapSL == 0)
                        {
                            cout << "Sleeper class is not available on this train." << '\n';
                            return;
                        }

                        seatTypeName = "Sleeper";
                        classMaximumCapacity = trainlist[i].maxcapSL;
                        startSeatNumber = 1;
                    }
                    else{
                        cout << "Not enough Sleeper seats available." << '\n';
                        return;
                    }
                    break;
                case 2:

                    // Check 3AC availability
                    if(quantity <= trainlist[i].seat3Ac)
                    {
                        if(trainlist[i].maxcap3Ac == 0)
                        {
                            cout << "3AC class is not available on this train." << '\n';
                            return;
                        }

                        seatTypeName = "3AC";
                        classMaximumCapacity = trainlist[i].maxcap3Ac;
                        startSeatNumber = trainlist[i].maxcapSL + 1;
                    }
                    else
                    {
                        cout << "Not enough 3AC seats available." << '\n';
                        return;
                    }
                    break;
                case 3:

                    // Check 2AC availability
                    if(quantity <= trainlist[i].seat2Ac){
                        if(trainlist[i].maxcap2Ac == 0)
                        {
                            cout << "2AC class is not available on this train." << '\n';
                            return;
                        }

                        seatTypeName = "2AC";
                        classMaximumCapacity = trainlist[i].maxcap2Ac;
                        startSeatNumber = trainlist[i].maxcapSL + trainlist[i].maxcap3Ac + 1;
                    }
                    else
                    {
                        cout << "Not enough 2AC seats available." << '\n';
                        return;
                    }

                    break;


                default:

                    cout << "You entered a wrong number." << '\n';
                    return;
            }

            // Generate a unique ticket number for this booking
            ticketNumber = (rand() % 900000) + 100000;
            while(ticketCheck(ticketCollectionTrain1, 1250, ticketNumber) ||
                  ticketCheck(ticketCollectionTrain2, 1250, ticketNumber) ||
                  ticketCheck(ticketCollectionTrain3, 1250, ticketNumber) ||
                  ticketCheck(ticketCollectionTrain4, 1250, ticketNumber) ||
                  ticketCheck(ticketCollectionTrain5, 1250, ticketNumber) ||
                  ticketCheck(ticketCollectionTrain6, 1250, ticketNumber)){
                ticketNumber = (rand() % 900000) + 100000;
            }

            int seatNo = startSeatNumber;
            for(int j = 0; j < classMaximumCapacity; j++){
                int possibleSeat = startSeatNumber + j;
                if(seatType == 1 && possibleSeat > trainlist[i].maxcapSL) break;
                if(seatType == 2 && possibleSeat > trainlist[i].maxcapSL + trainlist[i].maxcap3Ac) break;
                if(seatType == 3 && possibleSeat > trainlist[i].maxcapSL + trainlist[i].maxcap3Ac + trainlist[i].maxcap2Ac) break;
                seatNo = possibleSeat;
                break;
            }

            cout << "Ticket Number : " << ticketNumber << '\n';
            cout << "Seat Number   : " << seatNo << '\n';
            cout << "Seat Type     : " << seatTypeName << '\n';
            cout << "Quantity      : " << quantity << '\n';
            cout << "Total Fare    : Rs. " << trainlist[i].fare * quantity << '\n';

            trainlist[i].availableSeats -= quantity;
            if(seatType == 1){
                trainlist[i].seatSL -= quantity;
            }
            else if(seatType == 2){
                trainlist[i].seat3Ac -= quantity;
            }
            else if(seatType == 3){
                trainlist[i].seat2Ac -= quantity;
            }

            uploadingDataInCollection(ticketCollectionTrain1,ticketCollectionTrain2,ticketCollectionTrain3,ticketCollectionTrain4,ticketCollectionTrain5,ticketCollectionTrain6,trainID,trainlist,ticketNumber);
            getUserData(trainlist,ticketNumber,Data,trainID,record,seatTypeName,seatNo,quantity,trainlist[i].fare * quantity);

            // Train has been found, so stop searching
            return;
        }
    }

    // If loop finishes, train was not found
    cout << "Please enter a valid train ID." << '\n';
}

void ticketToSeatConnector(train trainlist[]){
    (void)trainlist;
    // Seat numbers are assigned during booking and stored in Data[].
}

bool ticketCheck(int ticketData[], int size, int ticketNumber)
{
    for(int i = 0; i < size; i++)
    {
        if(ticketData[i] == ticketNumber){
            return true;
        }
    }

    return false;
}

void uploadingDataInCollection(int *Train1TicketStorage,int *Train2TicketStorage,int *Train3TicketStorage,int *Train4TicketStorage,int *Train5TicketStorage,int *Train6TicketStorage,int TrainSearchID,train trainlist[],int ticketNumber){
    for(int i = 0;i < 6;i++){
        if(TrainSearchID == trainlist[i].train_no){
            int *selectedStorage = Train1TicketStorage;
            switch(i + 1){
                case 1: 
                    selectedStorage = Train1TicketStorage;
                    break;
                case 2: 
                    selectedStorage = Train2TicketStorage;
                    break;
                case 3:
                    selectedStorage = Train3TicketStorage;
                    break;
                case 4: 
                    selectedStorage = Train4TicketStorage;
                    break;
                case 5:
                    selectedStorage = Train5TicketStorage;
                    break;
                case 6:
                    selectedStorage = Train6TicketStorage;
                    break;
            }

            for(int j = 0;j < 1250;j++){
                if(selectedStorage[j] == 0){
                    selectedStorage[j] = ticketNumber;
                    break;
                }
            }
            return;
        }
    }
}

int getSeatNumberForTicket(int trainID,int ticketNumber){
    for(int i = 0;i < record;i++){
        if(Data[i].traincode == trainID && Data[i].TicketNumber == ticketNumber){
            return Data[i].seatNo;
        }
    }
    return 0;
}

void getUserData(train trainsList[],int ticketNumber,TicketDatabaseWithUserInfo Data[],int TrainID,int &record,string seatType,int seatNo,int quantity,float fare){
    if(record >= 1250){
        cout << "Booking database is full.\n";
        return;
    }

    for(int i = 0;i<6;i++){
        if(TrainID == trainsList[i].train_no){
            cout << "Enter Your Name : ";
            getline(cin >> ws,Data[record].name);
            cout << "Enter Date : " << '\n';
            Data[record].traincode = TrainID;
            Data[record].TicketNumber = ticketNumber;
            Data[record].destination = trainsList[i].destination;
            Data[record].source =  trainsList[i].source;
            Data[record].seatType = seatType;
            Data[record].seatNo = seatNo;
            Data[record].quantity = quantity;
            Data[record].fare = fare;
            Data[record].arrivalTime = trainsList[i].arrivalTime; 
            Data[record].departureTime = trainsList[i].departureTime;
        }
    }

    cout << "Please enter the date when you wish to board the train : ";
    getline(cin>>ws,Data[record].date);
    
    //generate ticket 
    generateTicket(trainsList,Data,record);
    record++;
}

void generateTicket(train trainslist[],TicketDatabaseWithUserInfo Data[],int record){
    (void)trainslist;
    
    cout << "\n";
    cout << "============================================================\n";
    cout << "                    RAILWAY TICKET\n";
    cout << "============================================================\n";

    cout << " Train Code      : " << Data[record].traincode << "\n";
    cout << " Ticket Number   : " << Data[record].TicketNumber << "\n";
    cout << "------------------------------------------------------------\n";

    cout << " Passenger Name  : " << Data[record].name << "\n";
    cout << " Date            : " << Data[record].date << "\n";
    cout << " Departure Time  : " << Data[record].departureTime << "\n";
    cout << " Arrival Time    : " << Data[record].arrivalTime << "\n";

    cout << "------------------------------------------------------------\n";

    cout << " From            : " << Data[record].source << "\n";
    cout << " To              : " << Data[record].destination << "\n";

    cout << "------------------------------------------------------------\n";

    cout << " Seat Type       : " << Data[record].seatType << "\n";
    cout << " Seat Number     : " << Data[record].seatNo << "\n";
    cout << " Quantity        : " << Data[record].quantity << "\n";
    cout << " Total Fare      : Rs. " << Data[record].fare << "\n";

    cout << "============================================================\n";
    cout << "                HAVE A SAFE JOURNEY!\n";
    cout << "============================================================\n";
}

void viewTicket(){
    int ticketNumber;
    bool found = false;

    cout << "Enter Ticket Number : ";
    cin >> ticketNumber;

    for(int i = 0;i < record;i++){
        if(Data[i].TicketNumber == ticketNumber){
            generateTicket(trainsList,Data,i);
            found = true;
            break;
        }
    }

    if(!found){
        cout << "Ticket not found.\n";
    }
}

void cancelTicket(){
    int ticketNumber;
    bool found = false;

    cout << "Enter Ticket Number to cancel : ";
    cin >> ticketNumber;

    for(int i = 0;i < record;i++){
        if(Data[i].TicketNumber == ticketNumber){
            for(int j = 0;j < 6;j++){
                if(trainsList[j].train_no == Data[i].traincode){
                    trainsList[j].availableSeats += Data[i].quantity;
                    if(Data[i].seatType == "Sleeper"){
                        trainsList[j].seatSL += Data[i].quantity;
                    }
                    else if(Data[i].seatType == "3AC"){
                        trainsList[j].seat3Ac += Data[i].quantity;
                    }
                    else if(Data[i].seatType == "2AC"){
                        trainsList[j].seat2Ac += Data[i].quantity;
                    }
                }
            }

            int *selectedStorage = nullptr;
            if(Data[i].traincode == trainsList[0].train_no) selectedStorage = ticketCollectionTrain1;
            else if(Data[i].traincode == trainsList[1].train_no) selectedStorage = ticketCollectionTrain2;
            else if(Data[i].traincode == trainsList[2].train_no) selectedStorage = ticketCollectionTrain3;
            else if(Data[i].traincode == trainsList[3].train_no) selectedStorage = ticketCollectionTrain4;
            else if(Data[i].traincode == trainsList[4].train_no) selectedStorage = ticketCollectionTrain5;
            else if(Data[i].traincode == trainsList[5].train_no) selectedStorage = ticketCollectionTrain6;

            if(selectedStorage != nullptr){
                for(int j = 0;j < 1250;j++){
                    if(selectedStorage[j] == ticketNumber){
                        selectedStorage[j] = 0;
                        break;
                    }
                }
            }

            Data[i].TicketNumber = 0;
            cout << "Ticket cancelled successfully.\n";
            found = true;
            break;
        }
    }

    if(!found){
        cout << "Ticket not found.\n";
    }
}

void viewBookingHistory(){
    if(record == 0){
        cout << "No booking history available.\n";
        return;
    }

    cout << "\n==================== BOOKING HISTORY ====================\n";
    bool found = false;

    for(int i = 0;i < record;i++){
        if(Data[i].TicketNumber != 0){
            found = true;
            cout << "Booking " << i + 1 << "\n";
            cout << "Passenger Name : " << Data[i].name << "\n";
            cout << "Train Code     : " << Data[i].traincode << "\n";
            cout << "Ticket Number  : " << Data[i].TicketNumber << "\n";
            cout << "Date           : " << Data[i].date << "\n";
            cout << "Seat Type      : " << Data[i].seatType << "\n";
            cout << "Seat Number    : " << Data[i].seatNo << "\n";
            cout << "Quantity       : " << Data[i].quantity << "\n";
            cout << "Total Fare     : Rs. " << Data[i].fare << "\n";
            cout << "----------------------------------------------------------\n";
        }
    }

    if(!found){
        cout << "No active bookings available.\n";
    }
}
