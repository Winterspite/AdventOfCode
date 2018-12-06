//
//  Challenges.cpp
//  CodeAdvent
//
//  Created by Joe Barrett on 12/5/18.
//  Copyright © 2018 Joe Barrett. All rights reserved.
//
#include "Advent.h"
#include "Challenges.h"

int ChallengeDay01Problem01(FileReader& fileReader)
{
    int total = 0;
    
    for (std::string line : fileReader.GetLines())
    {
        int temp = atoi(line.c_str());
        total += temp;
    }
    
    printf("%s: %d\n", __func__, total);
    return total;
}

int ChallengeDay01Problem02(FileReader& fileReader)
{
    std::vector<int> freqs;
    int frequency = 0;
    bool bDuplicateFound = false;
    
    while (!bDuplicateFound)
    {
        for (std::string line : fileReader.GetLines())
        {
            int temp = atoi(line.c_str());
            frequency += temp;
            
            /* Check and see if vector contains new frequency */
            if(std::find(freqs.begin(), freqs.end(), frequency) != freqs.end())
            {
                printf("%s: %d\n", __func__, frequency);
                bDuplicateFound = true;
                return frequency;
            }
            
            /* Add new frequency to list */
            freqs.push_back(frequency);
            //printf("Adding frequency %d\n", frequency);
        }
    }
    return -1337;
}


int ChallengeDay02Problem01(FileReader& fileReader)
{
    return 0;
}
int ChallengeDay02Problem02(FileReader& fileReader)
{
    return 0;
}

int ChallengeDay03Problem01(FileReader& fileReader)
{
    return 0;
}
int ChallengeDay03Problem02(FileReader& fileReader)
{
    return 0;
}

int ChallengeDay04Problem01(FileReader& fileReader)
{
    return 0;
}
int ChallengeDay04Problem02(FileReader& fileReader)
{
    return 0;
}

int ChallengeDay05Problem01(FileReader& fileReader)
{
    std::string Polymer;
    
    for (std::string line : fileReader.GetLines())
    {
        Polymer = line;
        int caseDifference = 'a' - 'A'; // 97 - 65
        // Convert to a vector of chars for faster manipulation
        std::vector<char> polyVec;
        for (int Idx = 0; Idx < Polymer.size(); Idx++)
        {
            polyVec.push_back(Polymer[Idx]);
        }
        
        int numChanges = 0;
        int Idx = 0;
        
        do
        {
            numChanges = 0;
            bool bMatch = (
                (polyVec[Idx] == (polyVec[Idx+1] + caseDifference))
             || (polyVec[Idx] == (polyVec[Idx+1] - caseDifference))
            );
            if (bMatch)
            {
                numChanges++;
                polyVec.erase(polyVec.begin()+Idx,polyVec.begin()+Idx+2); // Removing two characters
                Idx = 0;
            }
            else
            {
                Idx++;
            }
        } while (Idx < polyVec.size());
        
        Polymer.erase();
        for (char c : polyVec)
        {
            Polymer += c;
        }
    }
    
    printf("%s: %ld\n", __func__, Polymer.size());

    return (int)Polymer.size();
}

int ChallengeDay05Problem02(FileReader& fileReader)
{
    std::string Polymer;
    std::string GoodString;
    bool bSet = false;
    
    for (std::string line : fileReader.GetLines())
    {
        // Rotate through alphabet removing each letter in turn
        for (int AlphaIdx = 0; AlphaIdx < 26; AlphaIdx++)
        {
            Polymer = line;
            int caseDifference = 'a' - 'A'; // 97 - 65
            // Remove this iteration's letter, case insensitive
            Polymer.erase(std::remove(Polymer.begin(), Polymer.end(), (char)('a'+AlphaIdx)), Polymer.end());
            Polymer.erase(std::remove(Polymer.begin(), Polymer.end(), (char)('A'+AlphaIdx)), Polymer.end());

            // Convert to a vector of chars for faster manipulation
            int maxArrSize = (int)Polymer.size();
            char polyArr[maxArrSize];
            for (int Idx = 0; Idx < Polymer.size(); Idx++)
            {
                polyArr[Idx] = Polymer[Idx];
            }
            
            int Idx = 0;
            
            do
            {
                bool bMatch = (
                               (polyArr[Idx] == (polyArr[Idx+1] + caseDifference))
                               || (polyArr[Idx] == (polyArr[Idx+1] - caseDifference))
                               );
                if (bMatch)
                {
                    // Removing the two characters
                    //polyArr[Idx] = polyArr[Idx+2]; // Jump two ahead
                    for (int SkipIdx = Idx + 2; Idx < maxArrSize - 2; SkipIdx++, Idx++)
                    {
                        polyArr[Idx] = polyArr[SkipIdx];
                    }
                    polyArr[maxArrSize-2] = 0;
                    polyArr[maxArrSize-1] = 0;
                    
                    Idx = 0;
                }
                else
                {
                    Idx++;
                }
            } while (Idx < maxArrSize);
            
            Polymer.clear();
            for (char c : polyArr)
            {
                Polymer += c;
            }
            
            if (!bSet)
            {
                bSet = true;
                GoodString = Polymer;
            }
            if (strlen(Polymer.c_str()) < strlen(GoodString.c_str()))
            {
                GoodString = Polymer;
            }
        }
    }
    
    printf("%s: %ld\n", __func__, strlen(GoodString.c_str()));

    return strlen(GoodString.c_str());
}
