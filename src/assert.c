#include "easytest/assert.h"
#include "easytest/tests.h"

void assert(int condition, char *fail_msg)
{
    if (!condition)
    {
        current_test.passed = 0;
        current_test.fail_msg = fail_msg
    }
}
