#include "stringx.h"

int main() {
      char *str = "one,two,three,four,thirty two", *delimiters[] = {",", " "};
    int delim_count = sizeof(delimiters) / sizeof(delimiters[0]);
    char **arr1;
    int arr2[] = {1, 2, 3, 4, 5};
    float arr3[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    double arr4[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    void *vstr[5], *v2[5], *v3[5], *v4[5];

    char **arr = splitc(str, ',');
    int delim = 0;
    for (int j = 0; j < strlen(str); j++)
        if (str[j] == ',') delim++;
    delim++;

    printf("SPLIT:\n");
    for (int i = 0; i < delim; i++)
        printf("%s\n", arr[i]);

    printf("\n");
    arr1 = split(str, ",");
    for (int i = 0; i < delim; i++) {
        printf("%s\n", arr1[i]);
        free(arr1[i]);
    }

    printf("\n");
    arr1 = split_s(str, delimiters, delim_count);
    for (int i = 0; i < delim + 1; i++) {
        printf("%s\n", arr1[i]);
        free(arr1[i]);
    }

    for (int i = 0; i < delim; i++) {
        vstr[i] = arr[i];
        v2[i] = &arr2[i];
        v3[i] = &arr3[i];
        v4[i] = &arr4[i];
    }

    str = join(vstr, delim, " ", CHAR);
    printf("\nJOIN:\n%s\n", str);
    free(str);

    str = join(v2, delim, ", ", INT);
    printf("%s\n", str);
    free(str);

    str = join(v3, delim, " ", FLOAT);
    printf("%s\n", str);
    free(str);

    str = join(v4, delim, " and ", DOUBLE);
    printf("%s\n", str);
    free(str);

    str = concat(arr[1], arr[2]);
    printf("\nCONCAT:\n%s\n", str);
    free(str);

    free(arr);

    str = "   Hello world!  ";
    printf("\nORIGINAL:\n|%s|\n", str);
    char *str1 = trim(str);
    printf("TRIMMED:\n|%s|\n", str1);
    str1 = ltrim(str);
    printf("LTRIMMED:\n|%s|\n", str1);
    str1 = rtrim(str);
    printf("RTRIMMED:\n|%s|\n", str1);
    free(str1);

    str = "sea shells on sea shore";
    printf("\nORIGINAL:\n%s\n", str);
    str = replace(str, "sea", "lake", -1);
    printf("REPLACED:\n%s\n", str);
    str = replacelast(str, "lake", "sea", 1);
    printf("REPLACE LAST:\n%s\n", str);
    str = replacelast(str, "sh", "c", -1);
    printf("%s\n", str);
    free(str);

    str = "Hello world";
    printf("\nENDS WITH: \n%d\n%d\n", endswith(str, "Rld", true), endswith(str, "foo", true));
    printf("\n%d\n%d\n", endswith(str, "Rld", false), endswith(str, "foo", false));

    printf("\nSTARTS WITH: \n%d\n%d\n", startswith(str, "Hell", true), startswith(str, "foo", true));
    printf("\n%d\n%d\n", startswith(str, "hell", false), startswith(str, "foo", false));

    printf("\nINDEX OF: \n%d\n", indexof(str, 'O', true));
    printf("%d\n", indexof(str, 'O', false));

    printf("\nLAST INDEX OF: \n%d\n", lastindexof(str, 'O', true));
    printf("%d\n", lastindexof(str, 'O', false));

    printf("\nCONTAINS:\n%d\n%d\n", contains("Hello world", "pot", true),
           contains("Hello world", "pot", false));
    printf("%d\n%d\n", contains("Hello world", "WOR", true),
           contains("Hello world", "WOR", false));
    printf("%d\n%d\n", contains("Hello world", "wor", true),
           contains("Hello world", "wor", false));

    str = substring("Hello world", 6, 3);
    printf("\nSUBSTRING:\n%s\n", str);
    free(str);
    str = substring("Hello world", -1, 12);
    printf("|%s|\n", str);
    free(str);
    str = substring_s("Hello world", 6);
    printf("\n%s\n", str);
    free(str);
    str = substring_s("Hello world", 12);
    printf("|%s|\n", str);
    free(str);

    str = "Hello world";
    str = insert(str, 5, " new");
    printf("\nINSERT:\n%s\n", str);
    //free(str);

    str = "sea shells on sea shore";
    printf("\nCOUNT:\n%d\n%d\n", strcount(str, "SH", true),
           strcount(str, "SH", false));
    printf("%d\n%d\n", count(str, 'S', true),
           count(str, 'S', false));

    str = toupr(str);
    printf("\nUPPERCASE:\n%s\n", str);

    str = tolwr(str);
    printf("\nLOWERCASE:\n%s\n", str);

    str = reverse(str);
    printf("\nREVERSE:\n%s\n", str);
    free(str);

    return 0;
}