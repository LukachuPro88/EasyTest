#include "easytest/tests.h"

void report_fail(TestCase *test)
{
    test->passed = 0;
}
