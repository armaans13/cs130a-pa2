#include <iostream>
#include <string>

#include "Quash.h"

using namespace std;

int main(int argc, char* argv[]) {
    Quash quasher;
    int counter = 1;
    std::string function = "";
    std::string number = "";
    int realNum;
    while(counter < argc) {
        function = argv[counter];
        if ( function == "insert" || function == "lookup" ||function == "delete" ) {
            number = argv[counter + 1];
            if (number.back() == ',')
                number.pop_back();
            realNum = stoi(number);
            if ( function == "insert" ) {
                quasher.insert(realNum);
                //cout << "doing insert.." << endl;
            } else if (function == "lookup") {
                quasher.lookup(realNum);
                //cout << "doing lookup.." << endl;
            } else if (function == "delete") {
                quasher.deleter(realNum);
                //cout << "doing delete.." << endl;
            }
            counter += 2;
        } else if (function == "print," || function == "print") {
            if(function.back() == ',')
                function.pop_back();
            quasher.print();
            counter++;
        } else if (function == "deleteMin," || function == "deleteMin") {
            if(function.back() == ',')
                function.pop_back();
            quasher.deleteMin();
            counter++;
        } else {
            cout << "Invalid Command" << endl;
            counter++;
        }

    }

    /*cout << argc << endl;
    for (int i = 0; i < argc; i++)
        cout << argv[i] << endl;

    int e = stoi(argv[2]);
    cout << e;8?
    return 0;*/
}