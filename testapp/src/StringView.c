
#include "StringView.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

String_View sv(const char *cstr) {
    return (String_View) {
        .data = cstr,
        .count = strlen(cstr)
    };
}

void sv_chop_left(String_View *sv, size_t n) {
    if(n > sv->count) n = sv->count;
    sv->count -= n;
    sv->data += n;
}

void sv_chop_right(String_View *sv, size_t n) {
    if(n > sv->count) n = sv->count;
    sv->count -= n;
}

String_View sv_chop_by_delim(String_View *sv, char delim) {
    size_t i = 0;
    
    // Incrementing index until delim is found or end of string reached
    while (i < sv->count && sv->data[i] != delim) {
        i += 1;
    }

    // If delim is found
    if (i < sv->count) {
        String_View result = {
            .data = sv->data,
            .count = i
        };
        // Mutating original sv
        sv_chop_left(sv, i + 1);

        // Returning what's left after delim
        return result;
    }

    // End of string reached
    String_View result = *sv;
    sv_chop_left(sv, sv->count); // Emptying original
    return result;
}

void sv_trim_left(String_View *sv) {
    while (sv->count > 0 && isspace(sv->data[0])) {
        sv_chop_left(sv, 1);
    }
}

void sv_trim_right(String_View *sv) {
    while (sv->count > 0 && isspace(sv->data[sv->count-1])) {
        sv_chop_right(sv, 1);
    }
}

void sv_trim(String_View *sv) {
    sv_trim_left(sv);
    sv_trim_right(sv);
}

void sv_print(String_View sv) {
    printf("|"SV_Fmt"|\n", SV_Arg(sv));
}