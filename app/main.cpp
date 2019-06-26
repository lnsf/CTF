#include <iostream>
#include <fstream>
#include <vector>

#include "../include/xor4file.h"

using namespace std;

void showStartMessage();

bool isStrContainsOnlyNum(const string &);

void showFlag();

void showCode();

string showAsciiAsStr(const vector<int> &);

bool readInput(string *);

long long num;
string num_s;
vector<int> flagAscii;

int main() {
    flagAscii = {99, 116, 102, 52, 98, 45, 107, 111, 115, 101, 110, 123, 121, 48, 117,
                 95, 103, 48, 116, 95, 116, 104, 49, 115, 95, 102, 108, 97, 103, 125};

    string dummy = "ctf4b-kosen-hint{__INPUT_TO_NUMBER> SHOW_CODE}";
    string name;
    time_t now = time(nullptr);

    showStartMessage();

    cout << "Type your name > ";
    if (readInput(&name)) return 0;

    cout << "Hello " << name << endl;

    while (true) {
        cout << endl << "Number > ";
        if (readInput(&num_s)) return 0;

        if (num_s[0] == '-') {
            cout << "Sorry!" << endl;
            cout << "You can input only > 0" << endl;
        } else if (num_s == "SHOW_CODE") {
            cout << "OK" << endl;

            showCode();

            cout << "Output file is ./code" << endl;
        } else if (!isStrContainsOnlyNum(num_s)) {
            cout << "You can input only integers" << endl;
        } else {
            try { num = stol(num_s); }
            catch (out_of_range &e) {
                cout << "Toooooooo big number orz..." << endl;
                cout << "Try again" << endl;

                continue;
            }
            if ((int) num == -((localtime(&now)->tm_mday))) {
                showFlag();
                break;
            }
            else{
                cout << "Too big number!" << endl;
                cout << "Try again" << endl;
            }
        }
    }
    return 0;
}

void showStartMessage() {
    cout << "  _____ _______ ______ " << endl;
    cout << " / ____|__   __|  ____|" << endl;
    cout << "| |       | |  | |__   " << endl;
    cout << "| |       | |  |  __|  " << endl;
    cout << "| |____   | |  | |     " << endl;
    cout << " \\_____|  |_|  |_|     " << endl;

    cout << "Welcome to my question!" << endl;
}

void showCode() {
    ifstream is;
    ofstream os;

    string key = showAsciiAsStr(flagAscii);
    try {
        is.open("./.hint");
        string code = doXor2File(is, key);
        is.close();

        os.open("./code");
        os << code;
        os.close();
    }
    catch (exception &e) {
        cerr << e.what() << endl;

        is.close();
        os.close();
    }
}

bool isStrContainsOnlyNum(const string &s) {
    for (char c : s)
        if (!isdigit(c)) return false;
    return true;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

void showFlag() {


    if (!(num & ((long) INT32_MAX + 1))) {
        cout << "Missing!" << endl;
    } else {
        cout << showAsciiAsStr(flagAscii) << endl;
    }

}

#pragma clang diagnostic pop

string showAsciiAsStr(const vector<int> &arr) {
    string after;

    for (int i : arr)
        after.push_back((char) i);

    return after;
}

bool readInput(string *v) {
    cin >> *v;

    return cin.eof();
}


