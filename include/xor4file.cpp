//
// Created by lnsf on 6/23/19.
//

#include "xor4file.h"

using namespace std;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
string doXor2File(ifstream& f, string& key){
    int keyIndex = 0, keyLength = key.length();
    char c;
    string after;

    while(f.get(c)) {
        after.push_back(c ^ key[keyIndex]);

        if(++keyIndex == keyLength) keyIndex = 0;
    }

    return after;
}
#pragma clang diagnostic pop