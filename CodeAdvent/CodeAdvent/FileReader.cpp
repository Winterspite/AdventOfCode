//
//  FileReader.cpp
//  CodeAdvent
//
//  Created by Joe Barrett on 12/5/18.
//  Copyright © 2018 Joe Barrett. All rights reserved.
//

#include "FileReader.h"

FileReader::FileReader(const char* inFile)
{
    // Creates a filereader from a given input file
    Filename.append("../ChallengeInput/"); // Doing this to locate the input file
    Filename.append(inFile);
    
    Read();
}

void FileReader::Read()
{
    std::ifstream file(Filename);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            Lines.push_back(line);
        }
    }
    else
    {
        printf("FAIL: Couldn't open %s\n", Filename.c_str());
    }
}

std::vector<std::string> FileReader::GetLines()
{
    return Lines;
}
