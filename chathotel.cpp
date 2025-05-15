#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Room {
protected:
    int roomNumber;
    bool isBooked;
    double price;

public:
    Room(int num, double cost) {
        roomNumber = num;
        isBooked = false;
        price = cost;
    }

    virtual void displayInfo() const {
        cout << "Room Number: " << roomNumber << ", Price: Rs." << price;
        if (isBooked)
            cout << " [Booked]";
        else
            cout << " [Available]";
        cout << endl;
    }

    virtual string getRoomType() const {
        return "Generic Room";
    }

    bool bookRoom() {
        if (!isBooked) {
            isBooked = true;
            return true;
        }
        return false;
    }

    bool isAvailable() const {
        return !isBooked;
    }

    int getRoomNumber() const {
        return roomNumber;
    }

    virtual ~Room() {}
};

class DeluxeRoom : public Room {
public:
    DeluxeRoom(int num) : Room(num, 3000.0) {}

    void displayInfo() const {
        cout << "Deluxe ";
        Room::displayInfo();
    }

    string getRoomType() const {
        return "Deluxe";
    }
};

class StandardRoom : public Room {
public:
    StandardRoom(int num) : Room(num, 1500.0) {}

    void displayInfo() const {
        cout << "Standard ";
        Room::displayInfo();
    }

    string getRoomType() const {
        return "Standard";
    }
};

class Customer {
private:
    string name;
    int roomNumber;

public:
    Customer(string customerName, int roomNum) {
        name = customerName;
        roomNumber = roomNum;
    }

    void display() const {
        cout << "Customer Name: " << name << ", Room Number: " << roomNumber << endl;
    }

    int getRoomNumber() const {
        return roomNumber;
    }
};

class Hotel {
private:
    vector<Room*> rooms;
    vector<Customer> customers;

public:
    Hotel() {
        for (int i = 201; i <= 210; ++i)
            rooms.push_back(new StandardRoom(i));
        for (int i = 301; i <= 304; ++i)
            rooms.push_back(new DeluxeRoom(i));
    }

    void showAvailableRooms() const {
        cout << "\nAvailable Rooms:\n";
        for (int i = 0; i < rooms.size(); i++) {
            if (rooms[i]->isAvailable())
                rooms[i]->displayInfo();
        }
    }

    void bookRoom() {
        string customerName;
        int roomNum;

        showAvailableRooms();
        cout << "\nEnter customer name: ";
        cin >> ws;
        getline(cin, customerName);
        cout << "Enter room number to book: ";
        cin >> roomNum;

        for (int i = 0; i < rooms.size(); i++) {
            if (rooms[i]->getRoomNumber() == roomNum) {
                if (rooms[i]->bookRoom()) {
                    customers.push_back(Customer(customerName, roomNum));
                    cout << "Room booked successfully!\n";
                } else {
                    cout << "Room is already booked.\n";
                }
                return;
            }
        }

        cout << "Invalid room number.\n";
    }

    void showAllCustomers() const {
        cout << "\nCustomer List:\n";
        for (int i = 0; i < customers.size(); i++) {
            customers[i].display();
        }
    }

    void showAllRooms() const {
        cout << "\nAll Room Details:\n";
        for (int i = 0; i < rooms.size(); i++) {
            rooms[i]->displayInfo();
        }
    }

    void placeOrder() {
	    cout << "\n===========================================\n";
	    cout << "|             Room Service Menu             |\n";
	    cout << "===========================================\n";
	    cout << "|  No  | Item                | Price (USD)  |\n";
	    cout << "-------------------------------------------\n";
	    cout << "|  1   | Burger              |    Rs.990.00     |\n";
	    cout << "|  2   | Cheese Pizza        |    Rs.880.00     |\n";
	    cout << "|  3   | Veggie Sandwich     |    Rs.650.00     |\n";
	    cout << "|  4   | Chicken Wrap        |    Rs.700.00     |\n";
	    cout << "|  5   | Caesar Salad        |    Rs.550.00     |\n";
	    cout << "|  6   | French Fries        |    Rs.500.00     |\n";
	    cout << "|  7   | Coffee              |    Rs.400.00     |\n";
	    cout << "|  8   | Tea                 |    Rs.200.00     |\n";
	    cout << "|  9   | Soft Drink          |    Rs.100.50     |\n";
	    cout << "| 10   | Chocolate Cake      |    Rs.500.00     |\n";
	    cout << "| 11   | Ice Cream           |    Rs.300.50     |\n";
	    cout << "|  0   | Cancel Order                           |\n";
	    cout << "===========================================\n";
	    cout << "Enter your choice: ";
	
	    int choice;
	    cin >> choice;
	
	    switch(choice) {
	        case 1: cout << "You ordered a Burger. It will be delivered soon!\n"; break;
	        case 2: cout << "You ordered a Cheese Pizza. It will be delivered soon!\n"; break;
	        case 3: cout << "You ordered a Veggie Sandwich. It will be delivered soon!\n"; break;
	        case 4: cout << "You ordered a Chicken Wrap. It will be delivered soon!\n"; break;
	        case 5: cout << "You ordered a Caesar Salad. It will be delivered soon!\n"; break;
	        case 6: cout << "You ordered French Fries. It will be delivered soon!\n"; break;
	        case 7: cout << "You ordered a Coffee. It will be delivered soon!\n"; break;
	        case 8: cout << "You ordered a Tea. It will be delivered soon!\n"; break;
	        case 9: cout << "You ordered a Soft Drink. It will be delivered soon!\n"; break;
	        case 10: cout << "You ordered Chocolate Cake. It will be delivered soon!\n"; break;
	        case 11: cout << "You ordered Ice Cream. It will be delivered soon!\n"; break;
	        case 0: cout << "Order cancelled.\n"; break;
	        default: cout << "Invalid choice. Please try again.\n";
	    }
	}

	~Hotel() {
        for (int i = 0; i < rooms.size(); i++)
            delete rooms[i];
    }
};

int main() {
	system("COLOR 05");
    Hotel hotel;
    int choice;

    do {
        cout << "\n====================================\n";
		cout << "      Welcome to Hotel Management   \n";
		cout << "====================================\n";
		cout << "1. Show All Rooms\n";
		cout << "2. Show Available Rooms\n";
		cout << "3. Book a Room\n";
		cout << "4. Show All Customers\n";
		cout << "5. Place an Order\n";
		cout << "0. Exit\n";
		cout << "------------------------------------\n";
		cout << "Enter your choice: ";
		cin >> choice;

        switch (choice) {
            case 1:
                hotel.showAllRooms();
                break;
            case 2:
                hotel.showAvailableRooms();
                break;
            case 3:
                hotel.bookRoom();
                break;
            case 4:
                hotel.showAllCustomers();
                break;
            case 5:
			    hotel.placeOrder();
			    break;
            case 0:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

