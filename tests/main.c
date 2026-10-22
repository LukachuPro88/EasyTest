#include "easytest/tests.h"
#include "easytest/assert.h"

void test_pass()
{
    assert_true(1 + 1 == 2, "Expected PASS");
}

void test_fail()
{
    assert_true(1 + 1 == 3, "Expected FAIL");
}

void long_test_name()
{
    assert_true(1 + 1 == 2, "Expected PASS");
}

int main()
{
    test("passing test", test_pass);
    test("failing test", test_fail);
    test("super duper long test name", long_test_name);

    run_tests();

    return 0;
}
