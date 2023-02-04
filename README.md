# strext
## String Utility Functions
This library provides a set of functions for manipulating and working with strings in C and adds more functionality to string.h.

### Function Declarations

```c
int strnicomp(const char *s1, const char *s2, size_t n);
```
Compares two strings, ignoring case, for a specified number of characters. Returns the difference between the first two non-matching characters in the two strings, converted to lower case. If the two strings match for the given number of characters, the function returns 0.

```c
char *stristr(char *haystack, char *needle);
```
Finds the first occurrence of a substring, ignoring case. Returns a pointer to the first occurrence of the substring in the haystack string, ignoring case. If the substring is not found, the function returns NULL.

```c
char **split(const char *str, char delimiter);
```
Splits a string into an array of strings based on a delimiter. Returns an array of strings, with each element being a substring of the original string, separated by the specified delimiter. The returned array must be freed by the caller.

```c
char *strndup_(const char *str, unsigned long long int chars);
```
Duplicates a string for a specified number of characters. Returns a pointer to a newly allocated string, which is a duplicate of the first 'chars' characters of the original string. The returned string must be freed by the caller.

```c
char *substring(char *str, int start, int length);
```
Extracts a substring from a string, given a starting position and length. Returns a pointer to a newly allocated string, which is a copy of the specified substring of the original string. If the specified substring is outside the bounds of the original string, the function returns NULL. The returned string must be freed by the caller.

```c
char *substr(char *str, int start, int end);
```
Extracts a substring from a string, given a starting and ending position. Returns a pointer to a newly allocated string, which is a copy of the specified substring of the original string. If the specified substring is outside the bounds of the original string, the function returns NULL. The returned string must be freed by the caller.

```c
char *substring_s(char *str, int start);
```
Returns a substring from the given string, starting from the specified index. Returns the extracted substring, or NULL if the start index is invalid. The returned string must be freed by the caller.

```c
char *ltrim(char *s);
```
Trims the leading whitespaces from the given string. Returns the trimmed string.

```c
char *rtrim(char *s);
```
Trims the trailing whitespaces from the given string. Returns the trimmed string. The returned string must be freed by the caller.

```c
char *trim(char *s);
```
Trims the leading and trailing whitespaces from the given string. Returns the trimmed string.

```c
char *replace(char *haystack, char *needle, char *replacement, int max_replacements)
```
Replaces all occurrences of a given needle string in a haystack string with a replacement string.

```c
char *replaceLast(const char *str, const char *target, const char *replacement, int count)
```
Replaces the last occurrence of a specified string in a given string with another string

```c
char* removeNonAscii(const char* str)
```
Removes all non-ASCII characters from a string and returns a char pointer.

```c
bool startsWith(const char *str, const char *pre, bool $case)
```
Determines if a string starts with a given prefix string, with case sensitivity based on the provided flag.

```c
bool endsWith(const char *str, const char *suffix, bool $case)
```
Determines if a string ends with a given suffix string, with case sensitivity based on the provided flag.

```c
bool contains(char *haystack, char *needle, bool $case)
```
Determines if a haystack string contains a given needle string, with case sensitivity based on the provided flag.

```c
char *insert(char *str, int start, char *value)
```
Inserts a string into another string at a given start index.

generate markdown for a readme.md for the following header code. include function declarations and brief explanations
    
```c
char *join(char **str, int size, char *delim);
```
Joins an array of strings into a single string using a delimiter.

```c
char *concat(char *str1, char *str2);
```
Concatenates two strings into a single string.

```c
char *concatc(char *str1, char c);
```
Concatenates str1 and str2, a char into a single string.

```c
char *toupr(char *str);
```
Converts a string to uppercase.

```c
char *tolwr(char *str);
```
Converts a string to lowercase.

```c
char *reverse(char *str);
```
Reverse a string in-place.

```c
int count(char *haystack, char needle, bool $case);
```
Counts the number of occurrences of `needle` in the string `haystack`.

```c
int sCount(char *haystack, char needle, int start, bool $case);
```
Counts the number of occurrences of `needle` in the string `haystack` starting from the `start` index.

```c
int iCount(char *haystack, char needle, int count, bool $case);
```
Counts the number of occurrences of `needle` in the first `count` characters of the string `haystack`.

```c
int siCount(char *haystack, char needle, int start, int count, bool $case);
```
Counts the number of occurrences of `needle` in the string `haystack` starting from the `start` index for `count` characters.

```c
int strCount(char *haystack, char *needle, bool $case);
```
Counts the number of occurrences of `needle` (a string) in the string `haystack`.

```c
int strsCount(char *haystack, char *needle, int start, bool $case);
```
Finds the number of occurences of `needle` in `haystack` starting from a given `start` position and taking into account case sensitivity
as specified by `$case` flag.

```c
int striCount(char *haystack, char *needle, int count, bool $case);
```
Finds the number of occurences of `needle` in `haystack` for a given number of characters `count` and taking into account case sensitivity
as specified by `$case` flag.

```c
int strsiCount(char *haystack, char *needle, int start, int count, bool $case);
```
Finds the number of occurences of `needle` in `haystack` starting from a given `start` position and searching for a given number of characters `count`,
taking into account case sensitivity as specified by `$case` flag.

```c
int indexOf(char *str, char lookup, bool $case);
```
Finds the index of a specified character in a string.

```c
int sIndexOf(const char *str, char c, int startIndex, bool $case);
```
Finds the index of a specified character in a string, starting from a specified index.

```c
int iIndexOf(char *str, int count, char value, bool $case);
```
Finds the index of a specified character in a string and searching only a specified number of characters.

```c
int siIndexOf(char *str, int startIndex, int count, char value, bool $case);
```
Finds the index of a specified character in a string, starting from a specified index and searching only a specified number of characters.

```c
int strIndexOf(const char *str, const char *value, bool $case);
```
Finds the index of a specified string in another string.

```c
int strsIndexOf(const char *str, const char *value, int startIndex, bool $case);
```
Finds the index of a specified string in another string, starting from a specified index.

```c
int striIndexOf(char *str, int count, char *value, bool $case);
```
Finds the index of a specified string in a string and searching only a specified number of characters.

```c
int strsiIndexOf(char *str, int startIndex, int count, char *value, bool $case);
```
Finds the index of a specified string within another string, starting from a specified index 
and searching only a specified number of characters.

```c
int lastIndexOf(char *str, char lookup, bool $case);
```
Finds the index of the last occurrence of a specified character in a string.

```c
int sLastIndexOf(const char *str, char value, int startIndex, bool $case);
```
Finds the index of the last occurrence of a specified character in a string, starting from a specified index.

```c
int iLastIndexOf(const char *str, char value, int count, bool $case);
```
Finds the index of the last occurrence of a specified character in a string and searching only a specified number of characters.

```c
int siLastIndexOf(const char *str, char value, int startIndex, int count, bool $case);
```
Returns the index of the last occurrence of a specified character in a string starting
from a specified index and searching only a specified number of characters.

```c
int strLastIndexOf(const char *str, const char *value, bool $case);
```
Finds the index of the last occurrence of a specified string in a string.

```c
int strsLastIndexOf(const char *str, const char *value, int startIndex, bool $case);
```
Finds the index of the last occurrence of a specified string in a string, starting from a specified index.

```c
int striLastIndexOf(const char *str, const char *value, int count, bool $case);
```
Finds the index of the last occurrence of a specified string in a string and searching only a specified number of characters..

```c
int strsiLastIndexOf(const char *str, const char *value, int startIndex, int count, bool $case);
```
Returns the index of the last occurrence of a specified string in a string, starting from
a specified index and searching only a specified number of characters.

#### NAMING CONVENTIONS:
- str - function takes in a string as a search term instead of a char
- s - function searches from the starting index.
- i - function searches the specified number of characters in a string.

The `bool $case` parameter specifies whether the search is case sensitive.
