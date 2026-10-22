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

void test_pass_close()
{
    assert_close(0.1 + 0.2, 0.3, 1e-6, "Expected PASS");
}

void test_fail_close()
{
    assert_close(0.30001, 0.3, 1e-6, "Expected FAIL");
}

int main()
{
    test("passing test", test_pass);
    test("failing test", test_fail);
    test("super duper long test name", long_test_name);
    test("close passing test", test_pass_close);
    test("close failing test", test_fail_close);

    run_tests();

    return 0;
}
