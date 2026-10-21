#include "easytest/assertions.h"
#include "easytest/tests.h"

TEST(passing)
{
    ASSERT(2 + 2 == 4);
}

TEST(failing)
{
    ASSERT(2 + 2 == 5);
}
