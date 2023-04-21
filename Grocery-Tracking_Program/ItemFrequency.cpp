/*
 * Grocery-Tracking Program
 *
 *  Date: 04-12-2023
 *  Author: Crailin Mogged
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "ItemFrequency.h"

using namespace std;


bool ItemFrequency::readFile(vector<string>& fileData)
{
    ifstream inFS;
    string line;
    
    // open text file and check for errors
    inFS.open("CS210_Project_Three_Input_File.txt");
    if (!inFS.is_open())
    {
        cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
        return 1; // 1 indicates error
    }
    
    // read file line by line into the string vector variable
    while (getline(inFS, line, '\n'))
    {
        if (line.at(line.size()-1) == '\r') // remove carriage returns if any
        line.erase(line.size()-1);
        
        fileData.push_back(line);
    }
    
    inFS.close();
    
    return 0;
}

void ItemFrequency::groupItems(vector<string>& line)
{
    unsigned int i, j;
    
    // rearrange items into groups
    for (i=0; i < line.size(); i++)
    for (j=i+1; j < line.size(); j++)
    {
        if (line.at(i) == line.at(j)) // if items are the same
        {
            // move second item in front of first
            line.insert(line.begin()+i, line.at(j));
            line.erase(line.begin()+j+1);
            i++;
        }
    }
}

void ItemFrequency::getItemFrequency()
{
    unsigned int i, iCurr = 0;
    string input;
    vector<string> item;
    
    if (readFile(item)) // if file cannot be read
    {
        cout << "Cannot read file." << endl;
        return;
    }
    
    groupItems(item);
    item.push_back(""); // add ending element for comparison
    
    cout << "Enter item:" << endl;
    getline(cin, input); // read input from user
    
    for (i=0; i < item.size(); i++)
    if (input == item.at(i)) // find item's current location in vector
    {
        iCurr = i;
        break;
    }
    
    if (iCurr != i) // if no item found print 0
    {
        cout << 0 << endl;
        return;
    }
    
    for (i=iCurr+1; i < item.size(); i++)
    if (item.at(iCurr) != item.at(i)) // loop until next item group
    {
        // print item frequency
        cout << i - iCurr << endl;
        break;
    }
}

void ItemFrequency::itemFrequencyList()
{
    unsigned int i, iCurr = 0;
    vector<string> item;
    
    if (readFile(item)) // if file cannot be read
    {
        cout << "Cannot read file." << endl;
        return;
    }
    
    groupItems(item);
    
    // print items and their frequency
    item.push_back(""); // add ending element for comparison
    
    for (i=1; i < item.size(); i++)
    if (item.at(iCurr) != item.at(i)) // loop until next item group
    {
        // print item and its frequency
        cout << item.at(iCurr) << " " << i - iCurr << endl;
        iCurr = i;
    }
}

void ItemFrequency::itemHistogram()
{
    unsigned int i, j, iCurr = 0;
    unsigned int maxStr = 0;
    vector<string> item;
    
    if (readFile(item)) // if file cannot be read
    {
        cout << "Cannot read file." << endl;
        return;
    }
    
    groupItems(item);
    item.push_back(""); // add ending element for comparison
    
    // find longest string
    for (i=0; i < item.size(); i++)
    if (item.at(i).length() > maxStr)
    maxStr = item.at(i).length();
    
    // print item histogram
    for (i=1; i < item.size(); i++)
    if (item.at(iCurr) != item.at(i)) // loop until next item group
    {
        // format and print item
        cout << left << setfill(' ') << setw(maxStr+1) << item.at(iCurr);
        
        // print frequency indication
        for (j=0; j < i - iCurr; j++)
        cout << "*";
        
        cout << endl;
        iCurr = i;
    }
}

bool ItemFrequency::itemFrequencyToFile()
{
    unsigned int i, iCurr = 0;
    vector<string> item;
    ofstream outFS;
    
    if (readFile(item)) // if file cannot be read
    {
        cout << "Cannot read file." << endl;
        return 1;
    }
    
    // open output file
    outFS.open("frequency.dat");

    if (!outFS.is_open())
    {
        cout << "Could not open file frequency.dat." << endl;
        return 1;
    }
    
    groupItems(item);
    
    // print items and their frequency to file
    item.push_back(""); // add ending element for comparison
    
    for (i=1; i < item.size(); i++)
    if (item.at(iCurr) != item.at(i)) // loop until next item group
    {
        // print item and its frequency to file
        outFS << item.at(iCurr) << " " << i - iCurr << endl;
        iCurr = i;
    }
    
    outFS.close();
    return 0;
}

