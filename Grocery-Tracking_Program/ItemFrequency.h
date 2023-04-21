/*
 * Grocery-Tracking Program
 *
 *  Date: 04-12-2023
 *  Author: Crailin Mogged
 */
 
#ifndef ITEMFREQUENCY_H
#define ITEMFREQUENCY_H

#include <vector>
using namespace std;


class ItemFrequency {
    public:
        void itemFrequencyList();
        void getItemFrequency();
        void itemHistogram();
        bool itemFrequencyToFile();
   private:
        bool readFile(vector<string>& fileData);
        void groupItems(vector<string>& line);
};

#endif

