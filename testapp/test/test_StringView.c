
#ifdef TEST

#include "unity.h"

#include "StringView.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_StringView_chopping_nothing(void)
{
    const char *testString = "hello";
    String_View test_sv = sv(testString);
    sv_chop_left(&test_sv, 0);
    sv_chop_right(&test_sv, 0);
    TEST_ASSERT_EQUAL_PTR(testString, test_sv.data);    // checks pointer didn't move
    TEST_ASSERT_EQUAL_INT(5, test_sv.count);    // checks count didn't change
}

void test_StringView_chop_left_normal(void)
{
    String_View test_sv = sv("hello");

    sv_chop_left(&test_sv, 2);

    TEST_ASSERT_EQUAL_INT(3, test_sv.count);
    TEST_ASSERT_EQUAL_CHAR('l', test_sv.data[0]);
}

void test_StringView_chop_left_overflow(void)
{
    String_View test_sv = sv("hello");
    
    sv_chop_left(&test_sv, 99);

    TEST_ASSERT_EQUAL_INT(0, test_sv.count);
}

void test_StringView_chop_right_normal(void)
{
    String_View test_sv = sv("hello");

    sv_chop_right(&test_sv, 2);

    TEST_ASSERT_EQUAL_INT(3, test_sv.count);
    TEST_ASSERT_EQUAL_CHAR('h', test_sv.data[0]);
}

void test_StringView_chop_right_overflow(void)
{
    String_View test_sv = sv("hello");

    sv_chop_right(&test_sv, 99);

    TEST_ASSERT_EQUAL_INT(0, test_sv.count);
}

void test_StringView_chop_by_delim_found(void)
{
    String_View test_sv = sv("hello,world");

    String_View token = sv_chop_by_delim(&test_sv, ',');

    // token should be "hello"
    TEST_ASSERT_EQUAL_INT(5, token.count);
    TEST_ASSERT_EQUAL_CHAR('h', token.data[0]);

    // sv should be "world"
    TEST_ASSERT_EQUAL_INT(5, test_sv.count);
    TEST_ASSERT_EQUAL_CHAR('w', test_sv.data[0]);
}

void test_StringView_chop_by_delim_not_found(void)
{
    String_View test_sv = sv("hello");

    String_View token = sv_chop_by_delim(&test_sv, ',');

    // token should be the whole string
    TEST_ASSERT_EQUAL_INT(5, token.count);
    TEST_ASSERT_EQUAL_CHAR('h', token.data[0]);

    // sv should be empty
    TEST_ASSERT_EQUAL_INT(0, test_sv.count);
}

void test_StringView_trim_left(void)
{
    String_View test_sv = sv("   hello");

    sv_trim_left(&test_sv);

    TEST_ASSERT_EQUAL_INT(5, test_sv.count);
    TEST_ASSERT_EQUAL_CHAR('h', test_sv.data[0]);
}

void test_StringView_trim_right(void)
{
    String_View test_sv = sv("hello   ");

    sv_trim_right(&test_sv);

    TEST_ASSERT_EQUAL_INT(5, test_sv.count);
    TEST_ASSERT_EQUAL_CHAR('o', test_sv.data[test_sv.count - 1]);
}

void test_StringView_trim_both(void)
{
    String_View test_sv = sv("   hello   ");

    sv_trim_left(&test_sv);
    sv_trim_right(&test_sv);
    
    TEST_ASSERT_EQUAL_INT(5, test_sv.count);
    TEST_ASSERT_EQUAL_CHAR('h', test_sv.data[0]);
    TEST_ASSERT_EQUAL_CHAR('o', test_sv.data[test_sv.count - 1]);
}

#endif // TEST
