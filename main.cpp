#include <iostream>
#include <string>
#include "helper.h"
#include "data.h"

using namespace std;

string inputFileName = "input.txt";
string outputFileName = "output.txt";



int main() {
    FILE* inputFile = readFile(inputFileName);
    lex();

    return 0;
}
