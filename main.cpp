#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct shoe {
    int modelNum;
    double price;
    string brand;
};

class shoeStore {
public:
    shoeStore();

    double AveragePrice(const string &brand);

    double AveragePrice(int modNum1, int modNum2);

private:
    int count;
    int capacity;
    shoe *list;
};

shoeStore::shoeStore() {
    string fileName;
    cout << "Please enter the file name: ";
    getline(cin, fileName);
    cout << "Please enter the count: ";
    cin >> count;
    cout << "Please enter the capacity: ";
    cin >> capacity;

    list = new shoe[capacity];

    ifstream theFile(fileName);

    int i = 0;
    while (!theFile.eof()) {
        theFile >> list[i].modelNum >> list[i].price >> list[i].brand;
        i++;
    }
}

double shoeStore::AveragePrice(const string &brand) {
    int i = count, stockOfBrand = 0;
    double total = 0;
    while (i > 0) {
        shoe s = list[i];
        if (s.brand == brand) {
            total += s.price;
            stockOfBrand++;
        }
        i--;
    }
    return total / stockOfBrand;
}

double shoeStore::AveragePrice(const int modNum1, const int modNum2) {
    int i = count, stockOfModel = 0;
    double total = 0;
    while (i > 0) {
        shoe s = list[i];
        if (s.modelNum >= modNum1 && s.modelNum <= modNum2) {
            total += s.price;
            stockOfModel++;
        }
        i--;
    }
    return total / stockOfModel;
}

class JumbledGame {
private:
    string scrambled, solution, guess;
    int numGuesses, incorrectGuesses;
public:
    JumbledGame();

    explicit JumbledGame(const string &s);

    int getNumGuesses() const;

    void setNumGuesses(int i);

    int getIncorrectGuesses() const;

    void setIncorrectGuesses(int i);
};

JumbledGame::JumbledGame() {

}

JumbledGame::JumbledGame(const string &a) {

}

int JumbledGame::getNumGuesses() const {
    return numGuesses;
}

void JumbledGame::setNumGuesses(int i) {
    JumbledGame::numGuesses = i;
}

int JumbledGame::getIncorrectGuesses() const {
    return incorrectGuesses;
}

void JumbledGame::setIncorrectGuesses(int i) {
    JumbledGame::incorrectGuesses = i;
}

class skateboard {
public:
    skateboard();

    skateboard(int, string);

    void setSize(double newSize);

    void setBrand(string newBrand);

    double getSize() const;

    string getBrand() const;

private:
    double size;
    string brand;
};

bool sameBrand(const skateboard &a, const skateboard &b, const skateboard &c) {
    if (a.getBrand() != b.getBrand()) {
        return true;
    } else if (a.getBrand() != c.getBrand()) {
        return true;
    } else if (b.getBrand() != c.getBrand()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    if (sameBrand(skateboard(200, "Brand 1"), skateboard(400, "Brand 2"), skateboard(550, "Brand 3"))) {
        cout << "Two of your skateboards are the same brand.";
    } else {
        cout << "Two of your skateboards are not the brand.";
    }

    return 0;
}

