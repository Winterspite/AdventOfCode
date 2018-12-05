//
//  FileReader.h
//  CodeAdvent
//
//  Created by Joe Barrett on 12/5/18.
//  Copyright © 2018 Joe Barrett. All rights reserved.
//

#ifndef FileReader_h
#define FileReader_h

#include "Advent.h"

class FileReader {
    
    
public:
    FileReader (const char* inFile);
    void Read();
    std::vector<std::string> GetLines();
protected:
    std::string Filename;
    std::vector<std::string> Lines;
};

#endif /* FileReader_h */
