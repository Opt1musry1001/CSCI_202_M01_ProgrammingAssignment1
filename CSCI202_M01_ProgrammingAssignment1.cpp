/*
Author: Ryan Moore
Date: 10/30/23
File: CSCI202_M01_ProgrammingAssignment1.cpp
Purpose: Converts user-given Roman numeral to decimal equivalent.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Class for Roman numeral objects.
class romanType {
private:
    string romanNumeral;
    int decimalValue;

    // A mapping of Roman numerals to their corresponding decimal values
    static const unordered_map<char, int> romanToDecimal;

    // Input validation for Roman numeral passed to object.
    bool isValidRoman(const string& numeral) {
        for (char c : numeral) {
            if (c != 'I' && c != 'V' && c != 'X' && c != 'L' && c != 'C' && c != 'D' && c != 'M') {
                return false;
            }
        }
        return true;
    }

public:
    // Constructor for the object.
    romanType(const string& numeral) {
        if (!isValidRoman(numeral)) {
            cerr << "Invalid Roman numeral. Please enter a valid Roman numeral.\n";
            exit(EXIT_FAILURE);
        }

        setRomanNumeral(numeral);
        convertToDecimal();
    }

    // Function to set romanNumeral variable to given input.
    void setRomanNumeral(const string& numeral) {
        romanNumeral = numeral;
    }

    // Function to convert given Roman numeral to decimal value.
    void convertToDecimal() {
        decimalValue = 0;
        int prevValue = 0;

        for (int i = romanNumeral.size() - 1; i >= 0; i--) {
            int current = romanToDecimal.at(romanNumeral[i]);

            if (current < prevValue) {
                decimalValue -= current;
            } else {
                decimalValue += current;
            }

            prevValue = current;
        }
    }

    // Print the given Roman numeral.
    void printAsRomanNumeral() {
        cout << "Roman Numeral: " << romanNumeral << endl;
    }

    // Print the decimal equivalent of the given Roman numeral.
    void printAsDecimalNumber() {
        cout << "Decimal Number: " << decimalValue << endl;
    }
};

// Map of Roman numerals and their decimal equivalents.
const unordered_map<char, int> romanType::romanToDecimal = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

// Main function.
int main() {
    string inputRoman;
    bool flag;

    // Get input and check validity.
    do {
        cout << "Enter a Roman numeral: ";
        cin >> inputRoman;
        
        // Input validation.
        if (inputRoman.find_first_not_of("IVXLCDM") != string::npos) {
            cout << "Enter a valid Roman numeral (all caps): " << endl;
            flag = true;
        } else {
            flag = false;
        }

    } while (flag);

    // Create romanType object and use it to convert Roman numeral to decimal equivalent.
    romanType number(inputRoman);

    // Print the results.
    number.printAsRomanNumeral();
    number.printAsDecimalNumber();

    return 0;
}
