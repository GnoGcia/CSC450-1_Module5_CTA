#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    // Declare string value and stack <string> values
    string value;
    stack <string> values;

    // Prompt user for input and store in value
    cout << "Enter a phrase: ";
    getline(cin, value);

    // Create ofstream object outFile and open CSC450_CT5_mod5.txt
    // with the fstream::app argument
    ofstream outFile;
    outFile.open("CSC450_CT5_mod5.txt", fstream::app);
    // Use outFile to append value to CSC450_CT5_mod5.txt
    outFile << value;
    // Close CSC450_CT5_mod5.txt
    outFile.close();

    // Create ifstream object inFile and reopen CSC450_CT5_mod5.txt
    ifstream inFile;
    inFile.open("CSC450_CT5_mod5.txt");
    // Use inFile to store each line in CSC450_CT5_mod5.txt to value
    // Loops while getline returns data from inFile to value
    while(getline(inFile, value))
    {
        // Append value to values
        values.push(value);
    }
    // Close CSC450_CT5_mod5.txt
    inFile.close();

    // Use outFile to open CSC450-mod5-reverse.txt
    outFile.open("CSC450-mod5-reverse.txt");
    // Loops while values is not empty
    while(!values.empty())
    {
        // Assign value with top of values
        value = values.top();
        // Iterate through each character in value in reverse order
        for(int i = value.length() - 1; i >= 0; i--)
        {
            // Append the current value character to outFile
            outFile << value.at(i);
        }
        // Append a newline to outFile after every element in values
        outFile << "\n";
        // Remove the top element in values
        values.pop();
    }
    // Close CSC450-mod5-reverse.txt
    outFile.close();

    return 0;
}
