
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "easytest/tests.h"

TestSuite suite = {0};
Test *current_test = NULL;

int test(char *name, void (*function)(void))
{
    Test new_test = {name, function, 1, NULL};

    Test *tmp_tests = realloc(
        suite.tests,
        sizeof(*suite.tests) * (suite.count + 1)
    );

    if (tmp_tests == NULL)
    {
        return -1;
    }

    suite.tests = tmp_tests;
    suite.tests[suite.count] = new_test;
    suite.count++;

    return 0;
}

int run_tests(void)
{

    int fail_count = 0;
    size_t max_width = 0;

    for (size_t i = 0; i < suite.count; ++i)
    {
        size_t width = strlen(suite.tests[i].name);

        if (width > max_width)
        {
            max_width = width;
        }
    }

    for (size_t i = 0; i < suite.count; ++i)
    {
        current_test = &suite.tests[i];
        current_test->function();

        printf("%s%s%s ", BOLD, current_test->name, RESET);

        size_t name_width = strlen(current_test->name);
        size_t dots = max_width - name_width + 3;

        for (size_t j = 0; j < dots; ++j)
        {
            printf(".");
        }

        if (current_test->passed)
        {
            printf(" %sPASS%s\n", GREEN, RESET);
        }
        else
        {
            printf(" %sFAIL%s\n", RED, RESET);
        }

        if (!current_test->passed &&
            current_test->fail_msg != NULL)
        {
            fail_count += 1;
            printf("%s\n\n", current_test->fail_msg);
        }

        free(current_test->fail_msg);
        current_test->fail_msg = NULL;
    }

    current_test = NULL;

    return fail_count;
}

