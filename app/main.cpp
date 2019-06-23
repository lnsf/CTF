#include <iostream>
#include <fstream>
#include <vector>

#include "../encrypt/xor4file.h"

using namespace std;

void showStartMessage();
bool isStrContainsOnlyNum(const string&);
void showFlag();
void showCode();
string showAsciiAsStr(const vector<int>&);

long age;
string age_s;

const vector<int> flagAscii = {99,116,102,52,98,45,107,111,115,101,110,123,121,48,117,
                               95,103,48,116,95,116,104,49,115,95,102,108,97,103,125};

int main(){
    string dummy = "ctf4b-kosen-hint{__INPUT_TO_AGE> SHOW_CODE}";
    string name;
    time_t now = time(0);

    showStartMessage();

    cout << "Type your name > ";
    cin >> name;

    cout << "Hello " << name << endl;

    while(true){
        cout << "Type your age > ";
        cin >> age_s;

        if(age_s[0] == '-'){
            cout << "Wow! Are you OK?" << endl;
            cout << "Age starts from 0" << endl;
        }
        else if(age_s == "SHOW_CODE"){
            cout << "OK" << endl << endl;

            showCode();
        }
        else if(!isStrContainsOnlyNum(age_s)){
            cout << "You can input only 0,1,...,9" << endl;
        }

        else{
            try{age = stol(age_s);}
            catch (out_of_range& e){
                cout << "Toooooooo big number orz..." << endl;
                cout << "Try again with others" << endl;

                continue;
            }
            if((int)age == -((localtime(&now)->tm_mday))){
                showFlag();
                break;
            }
        }
    }

    return 0;
}

void showStartMessage(){
    cout <<  "  _____ _______ ______ " << endl;
    cout <<  " / ____|__   __|  ____|" << endl;
    cout <<  "| |       | |  | |__   " << endl;
    cout <<  "| |       | |  |  __|  " << endl;
    cout <<  "| |____   | |  | |     " << endl;
    cout << " \\_____|  |_|  |_|     " << endl;

    cout << "Welcome to my question!" << endl;
}

void showCode(){
    ifstream is;

    string key = showAsciiAsStr(flagAscii);
    try{
        is.open("./.hint");
        cout << doXor2File(is, key) << endl;

        is.close();
    }
    catch (exception& e){
        cerr << e.what() << endl;

        is.close();
    }
}

bool isStrContainsOnlyNum(const string& s){
    for(char c : s)
        if(!isdigit(c)) return false;
    return true;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
void showFlag(){


    if (!(age & ((long) INT32_MAX + 1))) {
        cout << "Missing!" << endl;
    } else {
        cout << showAsciiAsStr(flagAscii) << endl;
    }

}
#pragma clang diagnostic pop

string showAsciiAsStr(const vector<int> &arr){
    string after;

    for(int i : arr)
        after.push_back((char) i);

    return after;
}

