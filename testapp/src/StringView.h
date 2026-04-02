
#include <stddef.h>

#ifndef STRINGVIEW_H
#define STRINGVIEW_H

#define SV_Fmt "%.*s"
#define SV_Arg(s) (s).count, (s).data

typedef struct {
    const char *data;
    size_t count;
} String_View;

void sv_chop_left(String_View *sv, size_t n);
void sv_chop_right(String_View *sv, size_t n);
String_View sv_chop_by_delim(String_View *sv, char delim);

void sv_trim_left(String_View *sv);
void sv_trim_right(String_View *sv);

void sv_trim(String_View *sv);

void sv_print(String_View sv);

String_View sv(const char *cstr);

#endif // STRINGVIEW_H
