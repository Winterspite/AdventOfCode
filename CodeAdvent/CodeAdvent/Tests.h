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
    
    bool TestDay02Challenge01();
    bool TestDay02Challenge02();

    bool TestDay03Challenge01();
    bool TestDay03Challenge02();

    bool TestDay04Challenge01();
    bool TestDay04Challenge02();

    bool TestDay05Challenge01();
    bool TestDay05Challenge02();

    
protected:
    int NumTests;
    int NumPass;
    int NumFail;
};
#endif /* Tests_h */
