//
//  Tests.h
//  CodeAdvent
//
//  Created by Joe Barrett on 12/5/18.
//  Copyright © 2018 Joe Barrett. All rights reserved.
//

#ifndef Tests_h
#define Tests_h

class TestHarness
{
public:
    TestHarness();
    bool RunTestHarness();

    bool TestDay01Challenge01();
    bool TestDay01Challenge02();
    
protected:
    int NumTests;
    int NumPass;
    int NumFail;
};
#endif /* Tests_h */
