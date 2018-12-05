//
//  Tests.cpp
//  CodeAdvent
//
//  Created by Joe Barrett on 12/5/18.
//  Copyright © 2018 Joe Barrett. All rights reserved.
//

#include "Advent.h"
#include "FileReader.h"
#include "Challenges.h"
#include "Tests.h"

bool TestHarness::RunTestHarness()
{
    bool bPassTests = true;
    
    bPassTests = bPassTests | TestDay01Challenge01();
    bPassTests = bPassTests | TestDay01Challenge02();

    
    printf("\nTests: %d\n", NumTests);
    printf("  Success: %d\n", NumPass);
    printf("  Failure: %d\n", NumFail);
    return bPassTests;
}

bool TestHarness::TestDay01Challenge01()
{
    ++NumTests;
    FileReader fr("01_sample.txt");
    const int ExpectedResult = 3;

    int TestResult = ChallengeDay01Problem01(fr);
    const bool bTestResult = (TestResult == ExpectedResult);
    
    if (!bTestResult)
    {
        printf("%s: Fail: %d != %d\n", __func__, ExpectedResult, TestResult);
    }
    bTestResult ? ++NumPass : ++NumFail;
    return bTestResult;
}

bool TestHarness::TestDay01Challenge02()
{
    ++NumTests;
    FileReader fr("01_sample.txt");
    const int ExpectedResult = 2;
    
    int TestResult = ChallengeDay01Problem02(fr);
    const bool bTestResult = (TestResult == ExpectedResult);
    
    if (!bTestResult)
    {
        printf("%s: Fail: %d != %d\n", __func__, ExpectedResult, TestResult);
    }
    bTestResult ? ++NumPass : ++NumFail;
    return bTestResult;
}


TestHarness::TestHarness()
{
    NumTests = 0;
    NumPass = 0;
    NumFail = 0;
}