#include <stdlib.h>
#include <stdio.h>  

#include "easytest/tests.h"

TestCase *current_test = NULL;
TestCase *tests = NULL;
int test_count = 0;

void register_test(TestCase test)
{
    TestCase *tmp = realloc(
        tests,
        (test_count + 1) * sizeof(TestCase)
    );

    if (tmp == NULL)
        return;

    tests = tmp;
    tests[test_count++] = test;
}

void run_test()
{
    for (size_t i = 0; i < test_count; ++i)
    {
        current_test = &tests[i];

        tests[i].passed = 1;

        tests[i].function();

        printf(
            "TEST CASE | %s .......... %s\n",
            tests[i].name,
            tests[i].passed ? "PASS" : "FAIL"
        );
    }
}
