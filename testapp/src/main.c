#include <stdio.h>
#include "Add.h"
#include "StringView.h"

int main() {
    printf("Result %d\n", add(1, 2));
    String_View s = sv("   Hello, World       ");
    sv_trim(&s);
    String_View hello = sv_chop_by_delim(&s, ',');
    sv_print(s);
    sv_print(hello);
    return 0;
}