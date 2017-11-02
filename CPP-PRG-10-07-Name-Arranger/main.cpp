//
//  main.cpp
//  CPP-PRG-10-07-Name-Arranger
//
//  Created by Keith Smith on 11/2/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that asks for the user's first, middle, and last names. The names
//  should be stored in three different character arrays. The program should then store,
//  in a fourth array, the name arranged in the following manner: the last name followed
//  by a comma and a space, followed by the first name and a space, followed by the
//  middle name. For example, if the user entered "Carol Lynn Smith", it should store
//  "Smith, Carol Lynn" in the fourth array. Display the contents of the fourth array
//  on the screen.
//
//

#include <iostream>
#include <cstring>

using namespace std;

const int INT_ARR_SIZE = 20;

char *getNameInfo();
char *joinNames(char *, char *, char *);

int main()
{
    char *chrNameFirst = nullptr;
    char *chrNameMiddle = nullptr;
    char *chrNameLast = nullptr;
    char *chrNameConcatenated = nullptr;
    
    cout << "Please enter your first name:\n";
    chrNameFirst = getNameInfo();
    
    cout << "Please enter your middle name:\n";
    chrNameMiddle = getNameInfo();
    
    cout << "Please enter your last name:\n";
    chrNameLast = getNameInfo();
    
    chrNameConcatenated = joinNames(chrNameFirst, chrNameMiddle, chrNameLast);
    
//    cout << "The proper way to write " << *chrNameFirst << " ";
//    cout << *chrNameMiddle << " " << *chrNameLast << " is:\n";
//    cout << *chrNameConcatenated << endl;
    int i = 0;
    
    while (chrNameConcatenated[i] != '\0')
    {
        cout << chrNameConcatenated[i];
        i++;
    }
    cout << endl;
    
    return 0;
}

char *getNameInfo()
{
    char *chrTemp = nullptr;
    chrTemp = new char[INT_ARR_SIZE];
    
    cin.getline(chrTemp, INT_ARR_SIZE * 3);
    
    return chrTemp;
}

char *joinNames(char *chrFirst, char *chrMiddle, char *chrLast)
{
    char *chrTemp = nullptr;
    chrTemp = new char[INT_ARR_SIZE * 3];
    
    int *intTempCounterLast = nullptr;
    intTempCounterLast = new int;
    *intTempCounterLast = 0;
    
    int *intTempCounterFirst = nullptr;
    intTempCounterFirst = new int;
    *intTempCounterFirst = 0;
    
    for (int i = 0 ; i < INT_ARR_SIZE ; i++)
    {
        *intTempCounterLast += 1;
        if(chrLast[i] == '\0')
        {
            chrLast[i + 2] = chrLast[i];
            chrLast[i + 1] = ' ';
            chrLast[i] = ',';
            break;
        }
    }
    
    for (int i = 0 ; i < INT_ARR_SIZE ; i++)
    {
        *intTempCounterFirst += 1;
        if(chrFirst[i] == '\0')
        {
            chrFirst[i + 1] = chrFirst[i];
            chrFirst[i] = ' ';
            break;
        }
    }
    
    chrTemp = strncat(chrLast, chrFirst, *intTempCounterLast);
    chrTemp = strncat(chrTemp, chrMiddle, *intTempCounterFirst);
    
    return chrTemp;
}
