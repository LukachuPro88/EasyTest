#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "easytest/assert.h"
#include "easytest/tests.h"

#define TRUE 1
#define FALSE 0

static char *build_fail_message(double input, double expected, int is_boolean);
static char *build_string_fail_message(const char *input, const char *expected);

void assert_true(int condition)
{
    if (!condition)
    {
        current_test->passed = 0;
        current_test->fail_msg = build_fail_message(condition, 1, TRUE);
    }
}

void assert_close(
        double input,
        double expected, 
        double tolerance
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
    current_test->fail_msg = build_fail_message(input, expected, FALSE);
}

void assert_string_equal(const char *input, const char *expected)
{
    if (strcmp(input, expected) == 0)
    {
        return;
    }

    current_test->passed = FALSE;
    current_test->fail_msg = build_string_fail_message(input, expected);

}

static char *build_fail_message(double input, double expected, int is_boolean)
{
    const char *format = is_boolean
        ? "Expected %s got %s"
        : "Expected %g got %g";

    const char *expected_bool = expected == 1 ? "TRUE" : "FALSE";
    const char *input_bool = input == 1 ? "TRUE" : "FALSE";

    int size;

    if (is_boolean)
    {
        size = snprintf(NULL, 0, format, expected_bool, input_bool);
    }
    else
    {
        size = snprintf(NULL, 0, format, expected, input);
    }

    if (size < 0)
    {
        return NULL;
    }

    char *message = malloc((size_t)size + 1);

    if (message == NULL)
    {
        return NULL;
    }

    if (is_boolean)
    {
        snprintf(message, (size_t)size + 1, format, expected_bool, input_bool);
    }
    else
    {
        snprintf(message, (size_t)size + 1, format, expected, input);
    }

    return message;
}

char *build_string_fail_message(const char *input, const char *expected)
{
    int size = snprintf(NULL, 0, "Expected '%s' got '%s'", expected, input);

    if (size < 0)
    {
        return NULL;
    }

    char *message = malloc((size_t)size + 1);

    if (message == NULL)
    {
        return NULL;
    }

    snprintf(message,
            (size_t)size + 1,
            "Expected '%s' got '%s'",
            expected,
            input
            );

    return message;
}

