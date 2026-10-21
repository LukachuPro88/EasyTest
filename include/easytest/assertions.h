#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            report_fail(current_test); \
        } \
    } while (0)
