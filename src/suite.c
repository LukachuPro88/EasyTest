#include <stdlib.h>

#include "easytest/tests.h"

TestSuite suite;

int test(char *name, void (*function)(void))
{ 
    // Use 1 (true) as default for a test case. If error has occurred
    // assert macro turns it into 0.
    struct Test test = {name, function, 1};
    
    Test *tmp_tests = realloc(
            suite.tests,
            sizeof(*suite.tests) * (suite.count + 1)
            );

    if (tmp_tests != NULL)
    {
        suite.tests = tmp_tests;
    } else
    {
        return -1;
    }

    suite.tests[suite.count] = test;
    suite.count++;
    
    return 0;
}
