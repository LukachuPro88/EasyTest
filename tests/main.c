#include <stdio.h>

#include "easytest/tests.h"
#include "easytest/assert.h"

void test_pass()
{
    assert_true(1 + 1 == 2);
}

void test_fail()
{
    assert_true(1 + 1 == 3);
}

void long_test_name()
{
    assert_true(1 + 1 == 2);
}

void test_pass_close()
{
    assert_close(0.1 + 0.2, 0.3, 1e-6);
}

void test_fail_close()
{
    assert_close(0.30001, 0.3, 1e-6);
}

void test_pass_string()
{
    assert_string_equal("hello world", "hello world");
}

void test_fail_string()
{
    assert_string_equal("bye world", "hello world");
}


int main()
{
    test("passing test", test_pass);
    test("failing test", test_fail);
    test("super duper long test name", long_test_name);
    test("close passing test", test_pass_close);
    test("close failing test", test_fail_close);
    test("string passing test", test_pass_string);
    test("string failing test", test_fail_string);


    printf("Fail count: %d\n", run_tests());

    return 0;
}
