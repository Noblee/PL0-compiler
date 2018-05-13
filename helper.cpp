#include <iostream>
#include <string>

using namespace std;

FILE* readFile(string name) {
    FILE *fp;
    fp = fopen (name.c_str(),"r");
    if (fp == NULL) {
        cout << "File not created okay, errno = " << name << endl;
        return nullptr;
    } else {
        return fp;
    }

}
