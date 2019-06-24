#include <iostream>
#include <fstream>

#include "../include/xor4file.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Invalid Arguments" << endl;
        return 1;
    }

    string key = argv[1];

    ifstream is;

    try {
        is.open(argv[2]);
        cout << doXor2File(is, key);

        is.close();
    }
    catch (exception &e) {
        cerr << e.what() << endl;

        is.close();
    }
}

