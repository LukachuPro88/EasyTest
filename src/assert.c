#include <stdlib.h>
#include <stdio.h>

#include "easytest/assert.h"
#include "easytest/tests.h"

void assert_true(int condition)
{
    if (!condition)
    {
        current_test->passed = 0;
        current_test->fail_msg = build_fail_message(condition, 1);
    }
}

void assert_close(
        double input,
        double expected, 
        double toleranc
        )
{
    if (tolerance == 0.0)
    {
        tolerance = 1e-4;
    }

    if (input >= expected - tolerance && input <= expected + tolerance)
    {
        return;
    }

    current_test->passed = 0;
    current_test->fail_msg = build_fail_message(input, expected);
}

char *build_fail_message(double input, double expected)
{
    int size = snprintf(NULL, 0, "Expected %g got %g", expected, input);

    if (size < 0)
    {
        return NULL;
    }

    char *message = malloc((size_t)size + 1);

    if (message == NULL)
    {
        return NULL;
    }

    snprintf(message, (size_t)size + 1, "Expected %g got %g", expected, input);

    return message;
}
