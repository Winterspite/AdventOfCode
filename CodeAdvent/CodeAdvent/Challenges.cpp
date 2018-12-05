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

std::string ChallengeDay05Problem01(FileReader& fileReader)
{
    return "";
}

int ChallengeDay05Problem02(FileReader& fileReader)
{
    return 0;
}
