//
//  main.cpp
//  CodeAdvent
//
//  Created by Joe Barrett on 12/5/18.
//  Copyright © 2018 Joe Barrett. All rights reserved.
//

#include <iostream>
#include "Advent.h"
#include "FileReader.h"
#include "Challenges.h"
#include "Tests.h"

int main(int argc, const char * argv[]) {
    
    const bool bReal = false;
    
    TestHarness testHarness;
    testHarness.RunTestHarness();
    
    
    if (bReal)
    {
        FileReader fDay01("01_input.txt");
        ChallengeDay01Problem01(fDay01);
        ChallengeDay01Problem02(fDay01);
        
        
    }
    
    
    return 0;
}
