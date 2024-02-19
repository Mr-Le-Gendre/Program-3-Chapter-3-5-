// Program 3 (Chapter 3 & 5).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open input files and output file for merging
    ifstream file1("File1.txt");
    ifstream file2("File2.txt");
    ofstream outputFile("Output.txt");

    // Check if files are opened successfully
    if (!file1 || !file2 || !outputFile) {
        cerr << "Error: Unable to open files." << endl;
        return 1;
    }

    string str1, str2; // Hold lines read from file1 and file2
    bool endOfFile1 = false, endOfFile2 = false;

    // Merge lines from file1 and file2 into outputFile
    if (getline(file1, str1) && getline(file2, str2)) {
        while (!endOfFile1 && !endOfFile2) {
            // Compare lines from file1 and file2, write the smaller one to outputFile
            if (str1 < str2) {
                outputFile << str1 << endl;
                // Read next line from file1
                if (!getline(file1, str1)) {
                    endOfFile1 = true;
                }
            }
            else {
                outputFile << str2 << endl;
                // Read next line from file2
                if (!getline(file2, str2)) {
                    endOfFile2 = true;
                }
            }
        }
    }

    // Write remaining lines from file1 to outputFile
    while (!endOfFile1) {
        outputFile << str1 << endl;
        if (!getline(file1, str1)) {
            endOfFile1 = true;
        }
    }

    // Write remaining lines from file2 to outputFile
    while (!endOfFile2) {
        outputFile << str2 << endl;
        if (!getline(file2, str2)) {
            endOfFile2 = true;
        }
    }

    // Close all files
    file1.close();
    file2.close();
    outputFile.close();

    cout << "Files merged successfully." << endl;

    return 0;
}
