#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Data structures
vector<string> sandwiches = {"Turkey", "Ham", "Veggie"};
vector<string> snacks = {"Apple", "Banana", "Trail-Mix"};
vector<string> drinks = {"Water", "Juice", "Soda"};
vector<string> desserts = {"Flan", "Ice Cream", "Cake"};

vector<string> currentLunch;

bool isValidLunch() {
    if (currentLunch[0] == "Turkey" && currentLunch[2] == "Juice") {
        return false;
    }
    if (currentLunch[0] == "Veggie" && currentLunch[2] == "Soda") {
        return false;
    }
    if (currentLunch[1] == "Banana" && currentLunch[3] == "Ice Cream") {
        return false;
    }
    if (currentLunch[2] == "Water" && currentLunch[3] != "Ice Cream" && currentLunch[3] != "Cake") {
        return false;
    }
    return true;
}

void printLunchTree() {
    for (int i = 0; i < currentLunch.size(); i++) {
        for (int j = 0; j < i; j++) {
            cout << "  "; 
        }
        cout << currentLunch[i] << endl;
    }
}

void findLunchesNoPrune(int index) {
    if (index == 4) {
        printLunchTree();
        cout << endl;
        return;
    }

    vector<string> &options = (index == 0) ? sandwiches : (index == 1) ? snacks : (index == 2) ? drinks : desserts;

    for (string option : options) {
        currentLunch.push_back(option);
        findLunchesNoPrune(index + 1);
        currentLunch.pop_back();
    }
}

void findLunchesWithPrune(int index) {
    if (index == 4) { 
        for (string item : currentLunch) {
            cout << item << " ";
        }
        cout << endl;
        return;
    }

    vector<string> &options = (index == 0) ? sandwiches : (index == 1) ? snacks : (index == 2) ? drinks : desserts;

    for (string option : options) {
        currentLunch.push_back(option);
        if (isValidLunch()) {
            findLunchesWithPrune(index + 1);
        }
        currentLunch.pop_back();
    }
}

int main() {
    auto start1 = high_resolution_clock::now();
    findLunchesNoPrune(0);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);

    auto start2 = high_resolution_clock::now();
    findLunchesWithPrune(0);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);

    cout << "\nTime without pruning: " << duration1.count() << " milliseconds" << endl;
    cout << "Time with pruning: " << duration2.count() << " milliseconds" << endl;

    double reduction = (double)(duration1.count() - duration2.count()) / duration1.count() * 100;
    cout << "Time reduction: " << reduction << "%" << endl;

    return 0;
}