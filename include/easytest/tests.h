typedef struct
{
    const char *name;
    void (*function)(void);
    int passed;
} TestCase;

void register_test(TestCase test);
void run_test(void);

#define TEST(name) \
    static void test_##name(void); \
    static TestCase case_##name = {#name, test_##name, 0}; \
    static void test_##name(void) \
    register_test(case_##name) \
    run_test()
