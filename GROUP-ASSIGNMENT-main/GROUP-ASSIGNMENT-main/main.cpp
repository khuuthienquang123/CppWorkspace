#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;

//test2

string membersFile = "members.txt" ;
string motorbikeFile = "mmotorbike.txt";

class Member {
    private:
        int memberId;
        string username;
        string fullName;
        double creditPoints;
        int renterRating;
        // ... other member details

    public:
        Member(int id, const string& uname, const string& name)
            : memberId(id), username(uname), fullName(name), creditPoints(20), renterRating(5) {
            // Initialize other member details
        }

        //Getter
        int getMemberId() const { return memberId; }
        string getUsernameName() const { return username; }
        string getFullName() const { return fullName; }
        double getCreditPoints() const { return creditPoints;}
        int getRenterRating() const {return renterRating;}

        // Function to deduct credit points
        bool deductCreditPoints(double amount) {
            if (creditPoints >= amount) {
                creditPoints -= amount;
                return true;
            }
            return false; // Insufficient credit points
        }

        // Function to rate a renter
        void rateRenter(int rating) {
            // Update renter rating logic here
        }

        // Function to list a motorbike
        void listMotorbike(const Motorbike& motorbike, double pricePerDay, int minRenterRating) {
            // Implement listing logic here
        }

        // Function to view rental requests
        void viewRequests() {
            // Implement request viewing logic here
        }

        // Function to accept a rental request
        void acceptRequest(int requestId) {
            // Implement request acceptance logic here
        }

        // Function to rate a rented motorbike
        void rateRentedMotorbike(int motorbikeId, int rating) {
            // Implement motorbike rating logic here
        }

        // Function to rate a renter who used the motorbike
        void rateRenterOfMotorbike(int motorbikeId, int rating) {
            // Implement renter rating logic here
        }

        // Function to display member details
        void displayMemberDetails() {
            cout << "Member ID: " << memberId << endl;
            cout << "Username: " << username << endl;
            cout << "Full Name: " << fullName << endl;
            cout << "Credit Points: " << creditPoints << endl;
            cout << "Renter Rating: " << renterRating << endl;
            // ... display other member details
        }
};

// Function to generate the next available member ID
string getNextMemberId(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open " << filename << " for reading." << endl;
        return "m1"; // Default to m1 if the file cannot be opened
    }

    string line;
    string lastId = "m0"; // Initialize with m0 to handle an empty file

    while (getline(file, line)) {
        istringstream iss(line);
        string type, memberId;
        iss >> type >> memberId;

        if (type == "Member" && memberId.substr(0, 1) == "m") {
            lastId = memberId;
        }
    }

    file.close();

    // Extract the numeric part of the lastId and increment it by 1
    int numericPart = stoi(lastId.substr(1)) + 1;

    return "m" + to_string(numericPart);
}

class Motorbike {
    private:
        int motorbikeId;
        string model;
        string color;
        double motorbikeRating;
        // ... other motorbike details

    public:
        Motorbike(int id, const string& mdl, const string& clr)
            : motorbikeId(id), model(mdl), color(clr), motorbikeRating(5) {
            // Initialize other motorbike details
        }

        //Getter
        int getMotorbikeId() const { return motorbikeId; }
        string getModel() const { return model; }
        string getColor() const { return color; }
        double getMotorbikeRating() const {return motorbikeRating;}

        // Function to display motorbike details
        void displayMotorbikeDetails() {
            cout << "Motorbike ID: " << motorbikeId << endl;
            cout << "Model: " << model << endl;
            cout << "Color: " << color << endl;
            cout << "Motorbike Rating: " << motorbikeRating << endl;
            // ... display other motorbike details
        }
        
};

vector<Member> members;
vector<Motorbike> motorbikes;

// Function to save member data to a text file
void saveMemberDataToFile(const string& filename) {
    ofstream file(membersFile);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (const Member& member : members) {
        file << "Member," << member.getMemberId() << "," << member.getUsernameName() << "," << member.getFullName()
             << "," << member.getCreditPoints() << "," << member.getRenterRating() << "\n";
    }

    file.close();
}

// Function to save motorbike data to a text file
void saveMotorbikeDataToFile(const string& filename) {
    ofstream file(motorbikeFile);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (const Motorbike& motorbike : motorbikes) {
        file << "Motorbike," << motorbike.getMotorbikeId() << "," << motorbike.getModel() << ","
             << motorbike.getColor() << "," << motorbike.getMotorbikeRating() << "\n";
    }

    file.close();
}

// Function to load member data from a text file
void loadMemberDataFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string type;
        iss >> type;

        if (type == "Member") {
            int memberId, renterRating;
            string username, fullName;
            double creditPoints;
            iss >> memberId >> username >> fullName >> creditPoints >> renterRating;
            members.push_back(Member(memberId, username, fullName));
        }
    }

    file.close();
}

// Function to load motorbike data from a text file
void loadMotorbikeDataFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string type;
        iss >> type;

        if (type == "Motorbike") {
            int motorbikeId;
            string model, color;
            double motorbikeRating;
            iss >> motorbikeId >> model >> color >> motorbikeRating;
            motorbikes.push_back(Motorbike(motorbikeId, model, color));
        }
    }

    file.close();
}

bool IsAdminLoggedIn() {
    string adminUsername = "admin"; // Predefined admin username
    string adminPassword = "admin123"; // Predefined admin password

    string username, password;
    cout << "Admin Login\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    return (username == adminUsername && password == adminPassword);
}

void adminViewMemberInfo() {
    // Implement admin functionality to view information of all members
    cout << "Admin: Viewing information of all members...\n";
    for (Member& member : members) {
        member.displayMemberDetails();
        cout << "----------------------\n";
    }
}

void adminViewMotorbikeInfo() {
    // Implement admin functionality to view information of all motorbikes
    cout << "Admin: Viewing information of all motorbikes...\n";
    for (Motorbike& motorbike : motorbikes) {
        motorbike.displayMotorbikeDetails();
        cout << "----------------------\n";
    }
}


bool IsLoggedIn(){
    string username, password, un, pass;
    cout << "Please enter username: ";
    getline(cin, username);

    cout << "Please enter password: " ;
    getline(cin, password);

    ifstream read("records.txt");

    while(read >> un >> pass){
        if(un == username && pass == password){
            return true;
        }else{
            return false;
        }
    }

}

void registration(){
    cout << "\tCreating new account...\n" << endl;

     // Get the next available member ID
    string memberId = getNextMemberId("records.txt");

    string fullname, phone, idNumber, driver_license_number, expiry_date;
    int idType;

    cin.ignore(); // Consume the newline character left in the input buffer

    cout << "Please enter your full name: ";
    getline(cin, fullname);

    cout << "Please enter your phone number: ";
    getline(cin, phone);

    cout << "Choose your ID type: 1. Citizen ID - 2. Passport: ";
    cin >> idType;

    if (idType == 1) {
        cout << "Please enter your ID number: ";
        cin.ignore(); // Consume the newline character left in the input buffer
        getline(cin, idNumber);
    } else if (idType == 2) {
        cout << "Please enter your passport number: ";
        cin.ignore(); // Consume the newline character left in the input buffer
        getline(cin, idNumber);
    }

    string rUserName, rPassword, rUn, rPass;

    cout << "PLease enter your username: ";
    cin >> rUserName;

    cout << "PLease enter your password: ";
    cin >> rPassword;

    ofstream recordFile("records.txt", ios::app);

    if (!recordFile.is_open()) {
        cerr << "Error: Unable to open records.txt for writing." << endl;
        return;
    }

    recordFile << rUserName << " " << rPassword << endl;

    // Open the MemberPI.txt file for writing
    ofstream memberFile("MemberPI.txt", ios::app);

    if (!memberFile.is_open()) {
        cerr << "Error: Unable to open MemberPI.txt for writing." << endl;
        return;
    }

    // Write member information to the file in a single line
    memberFile << memberId << "," << fullname << "," << phone << ","
               << idNumber << "," << rUserName << "," << rPassword << endl;

    memberFile.close();
    recordFile.close();

    cout << "Registration is successfull" << endl;
}

void forgotPassword(){
    string username, fUn, fPass, newPassword;

    cout << "Enter username: ";
    cin >> username;

    ifstream inFile("records.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cerr << "Error opening files." << endl;
        return;
    }

    bool found = false;

    while (inFile >> fUn >> fPass) {
        if (username == fUn) {
            cout << "Enter your new password: ";
            cin >> newPassword;
            tempFile << username << " " << newPassword << endl;
            found = true;
        } else {
            tempFile << fUn << " " << fPass << endl;
        }
    }

    inFile.close();
    tempFile.close();

    if (!found) {
        cout << "Username not found." << endl;
    } else {
        remove("records.txt");
        rename("temp.txt", "records.txt");
        cout << "Password updated successfully." << endl;
    }
}

int main(){
    int c;

    cout << "EEET2482/COSC2082 ASSIGNMENT\n";
    cout << "MOTORBIKE RENTAL APPLICATION\n";

    cout << "Instructor: Dr. Ling Huo Chong\n";
    cout << "Group: Group No.\n";
    cout << "s3979034, Student Name: Khuu Thien Quang\n";
    cout << "sXXXXXXX, Student Name\n";
    cout << "sXXXXXXX, Student Name\n";
    cout << "sXXXXXXX, Student Name\n";

    while (true) {
        cout << "Use the app as:\n";
        cout << "1. Guest\n";
        cout << "2. Member\n";
        cout << "3. Admin\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> c;

        switch (c) {
            case 1:
                // Guest functionalities (View motorbike details, register as a member, rent a motorbike)
                // ...
                break;
            case 2:
                // Member functionalities
                // ...
                break;
            case 3:
                // Admin functionalities
                if (IsAdminLoggedIn()) {
                    while (true) {
                        cout << "Admin Menu:\n";
                        cout << "1. View Information of All Members\n";
                        cout << "2. View Information of All Motorbikes\n";
                        cout << "3. Logout\n";
                        cout << "Enter your choice: ";
                        cin >> c;

                        switch (c) {
                            case 1:
                                adminViewMemberInfo();
                                break;
                            case 2:
                                adminViewMotorbikeInfo();
                                break;
                            case 3:
                                cout << "Admin logged out.\n";
                                break;
                            default:
                                cout << "Invalid choice. Try again.\n";
                                break;
                        }

                        if (c == 3) {
                            break;
                        }
                    }
                } else {
                    cout << "Admin login failed. Invalid username or password.\n";
                }
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}
