#include <stddef.h>

#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

typedef struct
{
    const char *name;
    void (*function)(void);
    int passed;
    const char *fail_msg;
} Test;

typedef struct
{
    Test *tests;
    size_t count;
} TestSuite;

extern Test *current_test;

/**
 * @brief Adds the given test to the test suite.
 *
 * @param name The test's name.
 * @param function The test function.
 *
 * @returns 0 if test was added successfully. 
 * -1 if realloc failed.
 *
 * @usage
 * test("my test", my_test);
 *
 * @note
 * -1 return = realloc failed.
 */
int test(char *name, void (*function)(void));

/**
 * @brief Runs the tests registered in the suite.
 */
void run_tests(void);
