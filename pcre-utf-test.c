/* gcc pcre-utf-test.c pcre/.libs/libpcre.a -o pcre-utf-test && ./pcre-utf-test */


#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "pcre/pcre.h"

int main(int argc, char **argv) {
    pcre *re;
    const char *error;
    char *pattern;
    char *subject;
    int erroffset;
    int ovector[3];
    int subject_length;
    int rc, i;

    setlocale(LC_ALL, "");

    pattern = "(*UCP)(*UTF8)\\w+";

    subject = "   f\xc3\xb6retag   after"; /* företag */
    subject_length = strlen(subject);

    re = pcre_compile(
        pattern,              /* the pattern */
        0,                    /* default options */
        &error,               /* for error message */
        &erroffset,           /* for error offset */
        NULL);                /* use default character tables */

    rc = pcre_exec(
        re,                   /* the compiled pattern */
        NULL,                 /* no extra data - we didn't study the pattern */
        subject,              /* the subject string */
        subject_length,       /* the length of the subject */
        0,                    /* start at offset 0 in the subject */
        0,                    /* default options */
        ovector,              /* output vector for substring information */
        3);                   /* number of elements in the output vector */

    for (i = 0; i < rc; i++) {
        char *substring_start = subject + ovector[2*i];
        int substring_length = ovector[2*i+1] - ovector[2*i];
        printf("%2d: %.*s\n", i, substring_length, substring_start);
    }

    return 0;
}
