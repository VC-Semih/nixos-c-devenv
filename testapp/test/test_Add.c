
#ifdef TEST

#include "unity.h"

#include "Add.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Add_add_should_ReturnSum(void)
{
    TEST_ASSERT_EQUAL_INT(3, add(1, 2));
    TEST_ASSERT_EQUAL_INT(0, add(0, 0));
    TEST_ASSERT_EQUAL_INT(-1, add(1, -2));
}

#endif // TEST
