#include "stringx.h"


/*
 * NAMING CONVENTIONS:
 * str - function takes in a string as a search term instead of a char
 * s - function searches from the starting index.
 * i - function searches the specified number of characters in a string.
 */

int strnicomp(const char *s1, const char *s2, size_t n) {
    int c1, c2;
    for (; n && *s1 && *s2; n--, s1++, s2++) {
        c1 = tolower(*s1);
        c2 = tolower(*s2);
        if (c1 != c2)
            return c1 - c2;
    }
    return n == 0 ? 0 : tolower(*s1) - tolower(*s2);
}

char *stristr(char *haystack, char *needle) {
    unsigned long long int n = strlen(needle),
            h = strlen(haystack) - n + 1;
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < n; j++)
            if (tolower(haystack[i + j]) != tolower(needle[j])) break;

        if (j == n)
            return (char *) haystack + i;
    }
    return NULL;
}

char **splitc(const char *str, const char delimiter) {
    unsigned long long int length = strlen(str);
    int count = 0;
    for (int i = 0; i < length; i++)
        if (str[i] == delimiter) count++;

    count++;

    char **arr = malloc(sizeof(const char *) * count);
    int index = 0;
    int start = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == delimiter || i == length - 1) {
            int size = i - start + 1;
            arr[index] = malloc(sizeof(const char) * size);
            strncpy((char *) arr[index], str + start, size);
            arr[index][size] = '\0';
            if (arr[index][size - 1] == delimiter)
                arr[index][size - 1] = '\0';
            start = i + 1;
            index++;
        }
    }

    return arr;
}

char **split(char *str, char *delimiter) {
    int str_len = strlen(str);
    int delimiter_len = strlen(delimiter);
    int count = 0;
    int i, j, k;
    for (i = 0; i <= str_len - delimiter_len; i++) {
        int match = 1;
        for (j = 0; j < delimiter_len; j++) {
            if (str[i + j] != delimiter[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            count++;
            i += delimiter_len - 1;
        }
    }
    char **result = (char **) malloc((count + 1) * sizeof(char *));
    int start = 0;
    int end = 0;
    int index = 0;
    for (i = 0; i <= str_len; i++) {
        int match = 1;
        for (j = 0; j < delimiter_len; j++) {
            if (str[i + j] != delimiter[j]) {
                match = 0;
                break;
            }
        }
        if (match || str[i] == '\0') {
            int length = i - start;
            result[index] = (char *) malloc(length + 1);
            for (k = 0; k < length; k++)
                result[index][k] = str[start + k];

            result[index][length] = '\0';
            index++;
            start = i + delimiter_len;
            i += delimiter_len - 1;
        }
    }
    result[++count] = NULL;
    return result;
}

char **split_s(char *str, char **delimiters, int delim_count) {
    int i, j, k;
    int start = 0;
    int end = 0;
    unsigned len = strlen(str);
    int split_count = 0;
    int is_delim = 0;
    char **splits;

    // Count the number of splits
    for (i = 0; i < len; i++) {
        is_delim = 0;
        for (j = 0; j < delim_count; j++) {
            if (strncmp(&str[i], delimiters[j], strlen(delimiters[j])) == 0) {
                split_count++;
                is_delim = 1;
                break;
            }
        }
        if (is_delim)
            i += strlen(delimiters[j]) - 1;
    }

    // Allocate memory for the splits array
    splits = (char **) malloc((split_count + 1) * sizeof(char *));

    // Split the string into separate pieces
    start = 0;
    end = 0;
    split_count = 0;
    for (i = 0; i < len; i++) {
        is_delim = 0;
        for (j = 0; j < delim_count; j++) {
            if (strncmp(&str[i], delimiters[j], strlen(delimiters[j])) == 0) {
                end = i;
                splits[split_count] = (char *) malloc((end - start + 1) * sizeof(char));
                for (k = 0; k < end - start; k++)
                    splits[split_count][k] = str[start + k];

                splits[split_count][end - start] = '\0';
                split_count++;
                start = i + strlen(delimiters[j]);
                is_delim = 1;
                break;
            }
        }
        if (is_delim)
            i += strlen(delimiters[j]) - 1;

    }

    // Add the last split to the splits array
    if (start < len) {
        splits[split_count] = (char *) malloc((len - start + 1) * sizeof(char));
        for (k = 0; k < len - start; k++)
            splits[split_count][k] = str[start + k];

        splits[split_count][len - start] = '\0';
        split_count++;
    }

    // Terminate the splits array with a null pointer
    splits[split_count] = NULL;

    return splits;
}

char *strndup_(const char *str, unsigned long long int chars) {
    char *buffer;
    int n;

    buffer = (char *) malloc(chars + 1);
    if (buffer) {
        for (n = 0; ((n < chars) && (str[n] != 0)); n++) buffer[n] = str[n];
        buffer[n] = 0;
    }
    return buffer;
}

char *substring(char *str, int start, int length) {
    size_t len = strlen(str);
    if (length > len || start > len || len == 0 || start < 0 || length < 0) return NULL;
    char *res = malloc(sizeof(char *) * abs(length - start));
    for (int i = start, j = 0; j < length; i++, j++)
        res[j] = str[i];

    res[abs(length - start)] = '\0';
    return res;
}

char *substr(char *str, int start, int end) {
    size_t len = strlen(str);
    if (end > len || start > len || len == 0 || start < 0 || end < 0) return NULL;
    char *res = malloc(sizeof(char *) * end - start);
    for (int i = start, j = 0; i < end; i++, j++)
        res[j] = str[i];

    res[abs(end - start)] = '\0';
    return res;
}

char *substring_s(char *str, int start) {
    size_t len = strlen(str);
    if (start > len || start < 0 || len == 0) return NULL;
    char *res = malloc(sizeof(char *) * (len - start));
    for (int i = start, j = 0; i < len; i++, j++)
        res[j] = str[i];

    res[len - start] = '\0';
    return res;
}

char *ltrim(char *s) {
    while (isspace(*s)) s++;
    return s;
}

char *rtrim(char *s) {
    int i;
    for (i = strlen(s) - 1; isspace(s[i]); i--);
    return substr(s, 0, i + 1);
}

char *trim(char *s) {
    return ltrim(rtrim(s));
}

char *replace(char *haystack, char *needle, char *replacement, int max_replacements) {
    char *result, *ins, *tmp;
    unsigned long long int len_rep, len_with, len_front, count;
    if (!haystack || !needle) return NULL;
    len_rep = strlen(needle);
    if (len_rep == 0) return NULL;
    if (!needle) needle = "";
    len_with = strlen(replacement);
    ins = haystack;
    for (count = 0; tmp = strstr(ins, needle); ++count) {
        ins = tmp + len_rep;
        if (max_replacements != -1 && count >= max_replacements) break;
    }
    tmp = result = malloc(strlen(haystack) + (len_with - len_rep) * count + 1);
    if (!result) return NULL;
    while (count--) {
        ins = strstr(haystack, needle);
        len_front = ins - haystack;
        tmp = strncpy(tmp, haystack, len_front) + len_front;
        tmp = strcpy(tmp, replacement) + len_with;
        haystack += len_front + len_rep;
    }
    strcpy(tmp, haystack);
    return result;
}

char *replacelast(const char *str, const char *target, const char *replacement, int count) {
    int targetLen = strlen(target), strLen = strlen(str),
            replacementLen = strlen(replacement);

    // Check if the target string is present in the source string
    int targetIndex = strilastindexof(str, target, strLen, false);
    if (targetIndex == -1) return strdup(str);
    // Calculate the length of the new string
    int newLen = strLen - targetLen + replacementLen;

    // Allocate memory for the new string
    char *newStr = (char *) malloc(newLen + 1);
    memset(newStr, 0, newLen + 1);
    // Copy the initial part of the source string to the new string
    strncpy(newStr, str, targetIndex);
    // Add the replacement string
    strncat(newStr, replacement, replacementLen);
    // Add the remaining part of the source string
    strncat(newStr, str + targetIndex + targetLen, strLen - targetIndex - targetLen);

    // If count is not equal to -1
    if (count != -1) {
        int replacements = 1;
        // Repeat the replacement for count times
        while (replacements < count) {
            int targetIndex = strilastindexof(newStr, target, newLen, false);
            if (targetIndex == -1) break;

            newLen = newLen - targetLen + replacementLen;

            // Reallocate memory for the new string
            char *temp = (char *) realloc(newStr, newLen + 1);
            if (!temp) {
                free(newStr);
                return NULL;
            }
            newStr = temp;

            // Add the replacement string
            memmove(newStr + targetIndex + replacementLen, newStr + targetIndex + targetLen,
                    newLen - targetIndex - replacementLen + 1);
            memcpy(newStr + targetIndex, replacement, replacementLen);

            replacements++;
        }
    } else {
        // Repeat the replacement until there are no more occurrences
        while (true) {
            int targetIndex = strilastindexof(newStr, target, newLen, false);
            if (targetIndex == -1) break;

            newLen = newLen - targetLen + replacementLen;
            // Reallocate memory for the new string
            char *temp = (char *) realloc(newStr, newLen + 1);
            if (!temp) {
                free(newStr);
                return NULL;
            }
            newStr = temp;

            // Add the replacement string
            memmove(newStr + targetIndex + replacementLen, newStr + targetIndex + targetLen,
                    newLen - targetIndex - replacementLen + 1);
            memcpy(newStr + targetIndex, replacement, replacementLen);
        }
    }
    return removenonascii(newStr);
}

char *removenonascii(const char *str) {
    int i = -1, j = -1;
    char *res = malloc(sizeof(char) * strlen(str) + 2);
    while (str[++i] != '\0') {
        if (!(str[i] >= 0 && str[i] <= 127)) continue;
        else res[++j] = str[i];
    }
    res[++j] = '\0';
    return res;
}

bool startswith(const char *str, const char *pre, bool $case) {
    return $case ? (strncmp(pre, str, strlen(pre)) == 0) :
           (strnicomp(pre, str, strlen(pre)) == 0);
}

bool endswith(const char *str, const char *suffix, bool $case) {
    if (!str || !suffix)
        return 0;
    size_t lenstr = strlen(str);
    size_t lensuffix = strlen(suffix);
    if (lensuffix > lenstr)
        return 0;
    return $case ? (strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0) :
           (strnicomp(str + lenstr - lensuffix, suffix, lensuffix) == 0);
}

bool contains(char *haystack, char *needle, bool $case) {
    return ($case ? strstr(haystack, needle) : stristr(haystack, needle)) != NULL;
}

char *insert(char *str, int start, char *value) {
    unsigned len = strlen(str),
            len2 = strlen(value);
    if (start < 0 || start > len) return NULL;
    char *res = malloc(sizeof(char *) * (len + len2) + 1);
    strncpy(res, str, start);
    strncpy(res + start, value, len2);
    strncpy(res + start + len2, str + start, strlen(str + start));
    res[len + len2] = '\0';
    return res;
}

char *join(void **arr, int size, char *delim, TYPE t) {
    char *result = (char *) malloc(sizeof(char) * 1024);
    result[0] = '\0';

    for (int i = 0; i < size; i++) {
        switch (t) {
            case INT:
                sprintf(result + strlen(result), "%d%s", *(int *) (arr[i]), delim);
                break;
            case DOUBLE:
                sprintf(result + strlen(result), "%f%s", *(double *) (arr[i]), delim);
                break;
            case FLOAT:
                sprintf(result + strlen(result), "%f%s", *(float *) (arr[i]), delim);
                break;
            case CHAR:
                sprintf(result + strlen(result), "%s%s", (char *) (arr[i]), delim);
                break;
        }
    }

    unsigned len = strlen(result);
    result[len - strlen(delim)] = '\0';

    return result;
}

char *concat(char *str1, char *str2) {
    char *res = malloc(strlen(str1) + strlen(str2) + 1);
    res[0] = '\0';
    strcat(res, str1);
    strcat(res, str2);
    return res;
}

char *concatc(char *str1, char c) {
    char *res = malloc(strlen(str1) + 1);
    res[0] = '\0';
    strcat(res, str1);
    res[strlen(str1)] = c;
    return res;
}

char *toupr(char *str) {
    size_t len = strlen(str), i;
    char *res = malloc(len);
    for (i = 0; i < len; i++)
        res[i] = toupper(str[i]);
    res[i] = '\0';
    return res;
}

char *tolwr(char *str) {
    size_t len = strlen(str), i;
    char *res = malloc(len);
    for (i = 0; i < len; i++)
        res[i] = tolower(str[i]);
    res[i] = '\0';
    return res;
}

char *reverse(char *str) {
    int len = strlen(str);
    char *res = malloc(sizeof(char *) * len);
    res[0] = '\0';
    for (int i = 0; i < len; i++)
        res[i] = str[len - i - 1];

    res[len] = '\0';
    return res;
}


//NOTE: COUNT
int count(char *haystack, char needle, bool $case) {
    int j = 0;
    for (int i = 0; i < strlen(haystack); ++i)
        if (haystack[i] == needle ||
            ($case && tolower(haystack[i]) == tolower(needle)))
            j++;
    return j;
}

int scount(char *haystack, char needle, int start, bool $case) {
    int j = 0;
    for (int i = start; i < start; ++i)
        if (haystack[i] == needle ||
            ($case && tolower(haystack[i]) == tolower(needle)))
            j++;
    return j;
}

int icount(char *haystack, char needle, int count, bool $case) {
    int j = 0;
    for (int i = 0; i < count; ++i)
        if (haystack[i] == needle ||
            ($case && tolower(haystack[i]) == tolower(needle)))
            j++;
    return j;
}

int iscount(char *haystack, char needle, int start, int count, bool $case) {
    int j = 0;
    for (int i = start; i < start + count; ++i)
        if (haystack[i] == needle ||
            ($case && tolower(haystack[i]) == tolower(needle)))
            j++;
    return j;
}

int strcount(char *haystack, char *needle, bool $case) {
    unsigned valueLength = strlen(needle);
    int ct = 0;
    for (int i = 0; i < strlen(haystack) - valueLength + 1; i++) {
        if (($case ? strncmp(haystack + i, needle, valueLength) :
             strnicomp(haystack + i, needle, valueLength)) == 0)
            ct++;
    }
    return ct;
}


int strscount(char *haystack, char *needle, int start, bool $case) {
    unsigned valueLength = strlen(needle);
    int ct = 0;
    for (int i = start; i < start - valueLength + 1; i++) {
        if (($case ? strncmp(haystack + i, needle, valueLength) :
             strnicomp(haystack + i, needle, valueLength)) == 0)
            ct++;
    }
    return ct;
}

int stricount(char *haystack, char *needle, int count, bool $case) {
    unsigned valueLength = strlen(needle);
    int ct = 0;
    for (int i = 0; i < count - valueLength + 1; i++) {
        if (($case ? strncmp(haystack + i, needle, valueLength) :
             strnicomp(haystack + i, needle, valueLength)) == 0)
            ct++;
    }
    return ct;
}

int striscount(char *haystack, char *needle, int start, int count, bool $case) {
    unsigned valueLength = strlen(needle);
    int ct = 0;
    for (int i = start; i < start + count - valueLength + 1; i++) {
        if (($case ? strncmp(haystack + i, needle, valueLength) :
             strnicomp(haystack + i, needle, valueLength)) == 0)
            ct++;
    }
    return ct;
}


//NOTE: INDEX OF
int indexof(char *str, char lookup, bool $case) {
    for (int i = 0; *str != '\0'; *str++, i++)
        if ((!$case && *str == lookup) ||
            (tolower(*str) == tolower(lookup)))
            return i;

    return -1;
}

int sindexof(const char *str, char c, int startIndex, bool $case) {
    for (int i = startIndex; i < strlen(str); i++)
        if (str[i] == c || (!$case && tolower(str[i]) == tolower(c)))
            return i;
    return -1;
}

int iindexof(char *str, int count, char value, bool $case) {
    unsigned strLength = strlen(str);

    // Check if the startIndex is within the range of the string

    // Check if the count is within the range of the string
    if (count < 0 || count > strLength)
        count = strLength;


    // Iterate through the string from startIndex to startIndex + count
    for (int i = 0; i < count; i++)
        // If the char is found, return its index
        if (str[i] == value || (!$case && tolower(str[i]) == tolower(value)))
            return i;

    // If the char is not found, return -1
    return -1;
}

// Find the index of a char in a string
int isindexof(char *str, int startIndex, int count, char value, bool $case) {
    unsigned strLength = strlen(str);

    // Check if the startIndex is within the range of the string
    if (startIndex < 0 || startIndex >= strLength)
        return -1;

    // Check if the count is within the range of the string
    if (count < 0 || count > strLength - startIndex)
        count = strLength - startIndex;


    // Iterate through the string from startIndex to startIndex + count
    for (int i = startIndex; i < startIndex + count; i++)
        // If the char is found, return its index
        if (str[i] == value || (!$case && tolower(str[i]) == tolower(value)))
            return i;

    // If the char is not found, return -1
    return -1;
}

int strindexof(const char *str, const char *value, bool $case) {
    unsigned valueLength = strlen(value);
    for (int i = 0; i < strlen(str) - valueLength + 1; i++) {
        if (($case ? strncmp(str + i, value, valueLength) :
             strnicomp(str + i, value, valueLength)) == 0)
            return i;
    }
    return -1;
}

int strsindexof(const char *str, const char *value, int startIndex, bool $case) {
    unsigned valueLength = strlen(value);
    for (int i = startIndex; i < strlen(str) - valueLength + 1; i++) {
        if (($case ? strncmp(str + i, value, valueLength) :
             strnicomp(str + i, value, valueLength)) == 0)
            return i;
    }
    return -1;
}

// Find the index of a string in a string
int striindexof(char *str, int count, char *value, bool $case) {
    unsigned strLength = strlen(str),
            valueLength = strlen(value);

    // Check if the count is within the range of the string
    if (count < 0 || count > strLength)
        count = strLength;

    // Iterate through the string from startIndex to startIndex + count
    for (int i = 0; i <= count - valueLength; i++)
        // Compare the substring with the value
        if (($case ? strncmp(str + i, value, valueLength) :
             strnicomp(str + i, value, valueLength)) == 0)
            // If the value is found, return its index
            return i;

    // If the value is not found, return -1
    return -1;
}

// Find the index of a string in a string
int strisindexof(char *str, int startIndex, int count, char *value, bool $case) {
    unsigned strLength = strlen(str),
            valueLength = strlen(value);

    // Check if the startIndex is within the range of the string
    if (startIndex < 0 || startIndex >= strLength)
        return -1;

    // Check if the count is within the range of the string
    if (count < 0 || count > strLength - startIndex)
        count = strLength - startIndex;

    // Iterate through the string from startIndex to startIndex + count
    for (int i = startIndex; i <= startIndex + count - valueLength; i++)
        // Compare the substring with the value
        if (($case ? strncmp(str + i, value, valueLength) :
             strnicomp(str + i, value, valueLength)) == 0)
            // If the value is found, return its index
            return i;

    // If the value is not found, return -1
    return -1;
}

int lastindexof(char *str, char lookup, bool $case) {
    for (int i = (int) strlen(str); i > 0; i--)
        if ((!$case && str[i] == lookup) ||
            (tolower(str[i]) == tolower(lookup)))
            return i;

    return -1;
}

// Returns the index of the last occurrence of a specified character
// in a string starting from a specified index.
int slastindexof(const char *str, char value, int startIndex, bool $case) {
    for (int i = startIndex; i >= 0; i--)
        if (str[i] == value || (!$case && tolower(str[i]) == tolower(value)))
            return i;

    return -1;
}

// Returns the index of the last occurrence of a specified character in a string starting from a specified index and searching only a specified number of characters.
int ilastindexof(const char *str, char value, int count, bool $case) {
    int startIndex = strlen(str);
    int endIndex = abs(startIndex - count + 1);
    for (int i = startIndex; i >= endIndex; i--)
        if (str[i] == value || ($case && tolower(str[i]) == tolower(value)))
            return i;

    return -1;
}

// Returns the index of the last occurrence of a specified character in a string starting from a specified index and searching only a specified number of characters.
int islastindexof(const char *str, char value, int startIndex, int count, bool $case) {
    int endIndex = startIndex - count + 1;
    for (int i = startIndex; i >= endIndex; i--)
        if (str[i] == value || ($case && tolower(str[i]) == tolower(value)))
            return i;

    return -1;
}

// Returns the index of the last occurrence of a specified string in a string.
int strlastindexof(const char *str, const char *value, bool $case) {
    unsigned len = strlen(str), valLen = strlen(value);

    for (int i = len - valLen; i >= 0; i--)
        if (($case ? strncmp(str + i, value, valLen) :
             strnicomp(str + i, value, valLen)) == 0)
            return i;

    return -1;
}

// Returns the index of the last occurrence of a specified string in a string starting from a specified index.
int strslastindexof(const char *str, const char *value, int startIndex, bool $case) {
    unsigned valLen = strlen(value);

    for (int i = startIndex - valLen + 1; i >= 0; i--)
        if (($case ? strncmp(str + i, value, valLen) :
             strnicomp(str + i, value, valLen)) == 0)
            return i;

    return -1;
}

// Returns the index of the last occurrence of a specified string in a string starting
// from a specified index and searching only a specified number of characters.
int strilastindexof(const char *str, const char *value, int count, bool $case) {
    unsigned valLen = strlen(value);
    int startIndex = strlen(str);

    int endIndex = startIndex - count + 1;
    for (int i = startIndex - valLen + 1; i >= endIndex; i--)
        if (($case ? strncmp(str + i, value, valLen) :
             strnicomp(str + i, value, valLen)) == 0)
            return i;

    return -1;
}

// Returns the index of the last occurrence of a specified string in a string starting
// from a specified index and searching only a specified number of characters.
int strislastindexof(const char *str, const char *value, int startIndex, int count, bool $case) {
    unsigned valLen = strlen(value);

    int endIndex = startIndex - count + 1;
    for (int i = startIndex - valLen + 1; i >= endIndex; i--)
        if (($case ? strncmp(str + i, value, valLen) :
             strnicomp(str + i, value, valLen)) == 0)
            return i;

    return -1;
}