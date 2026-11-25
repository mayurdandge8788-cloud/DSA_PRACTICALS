#include <iostream>
#include <cstring>
using namespace std;

struct Friend {
    char name[30];
    char mobile[15];
};

Friend phoneBook[100];
int n = 0;


void sortFriends() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(phoneBook[j].name, phoneBook[j + 1].name) > 0) {
                swap(phoneBook[j], phoneBook[j + 1]);
            }
        }
    }
}


int sentinelSearch(char key[]) {
    if (n == 0)
        return -1;

    Friend last = phoneBook[n - 1];
    strcpy(phoneBook[n - 1].name, key);

    int i = 0;
    while (strcmp(phoneBook[i].name, key) != 0)
        i++;

    phoneBook[n - 1] = last;

    if (i < n - 1 || strcmp(last.name, key) == 0)
        return i;

    return -1;
}


void insertFriend() {
    char name[30], mobile[15];

    cout << "Enter name: ";
    cin >> name;

    if (sentinelSearch(name) != -1) {
        cout << "Friend already exists!\n";
        return;
    }

    cout << "Enter mobile number: ";
    cin >> mobile;

    strcpy(phoneBook[n].name, name);
    strcpy(phoneBook[n].mobile, mobile);
    n++;

    sortFriends();

    cout << "Friend inserted successfully!\n";
}


void deleteFriend() {
    char name[30];

    cout << "Enter name to delete: ";
    cin >> name;

    int pos = sentinelSearch(name);

    if (pos == -1) {
        cout << "Friend not found!\n";
        return;
    }

    for (int i = pos; i < n - 1; i++)
        phoneBook[i] = phoneBook[i + 1];

    n--;

    cout << "Friend deleted successfully!\n";
}


void searchFriend() {
    char name[30];

    cout << "Enter name to search: ";
    cin >> name;

    int pos = sentinelSearch(name);

    if (pos != -1) {
        cout << "Name   : " << phoneBook[pos].name << endl;
        cout << "Mobile : " << phoneBook[pos].mobile << endl;
    }
    else {
        cout << "Friend not found!\n";
    }
}


void display() {
    if (n == 0) {
        cout << "Phone book is empty!\n";
        return;
    }

    cout << "\n----- PHONE BOOK -----\n";

    for (int i = 0; i < n; i++)
        cout << phoneBook[i].name << " : "
             << phoneBook[i].mobile << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Delete";
        cout << "\n4. Sort";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertFriend(); break;
            case 2: searchFriend(); break;
            case 3: deleteFriend(); break;
            case 4: sortFriends(); cout << "Sorted!\n"; break;
            case 5: display(); break;
            case 6: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}