#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
} TYPE;

/**
 * @brief strnicomp - compare two strings, ignoring case, for a specified number of characters
 * @param s1: first string to compare
 * @param s2: second string to compare
 * @param n: the number of characters to compare
 *
 * @returns This function returns the difference between the first two non-matching characters
 * in the two strings, converted to lower case. If the two strings match for the given
 * number of characters, the function returns 0.
 */
int strnicomp(const char *s1, const char *s2, size_t n);

/**
 * @brief stristr - find the first occurrence of a substring, ignoring case
 * @param haystack: the string to search in
 * @param needle: the substring to search for
 *
 * @returns This function returns a pointer to the first occurrence of the substring in the
 * haystack string, ignoring case. If the substring is not found, the function returns
 * NULL.
 */
char *stristr(char *haystack, char *needle);

/**
 * @brief splitc - split a string into an array of strings based on a delimiter
 * @param str: the string to split
 * @param delimiter: the delimiter char to use for splitting
 *
 * @returns This function returns an array of strings, with each element being a substring of
 * the original string, separated by the specified delimiter. The returned array must
 * be freed by the caller.
 */
char **splitc(const char *str, char delimiter);

/**
 * @brief split - split a string into an array of strings based on a delimiter
 * @param str: the string to split
 * @param delimiter: the delimiter string to use for splitting
 *
 * @returns This function returns an array of strings, with each element being a substring of
 * the original string, separated by the specified delimiter. The returned array must
 * be freed by the caller.
 */
char **split(char *str, char* delimiter);

/**
 * @brief split_s - split a string into an array of strings based on delimiters
 * @param str: the string to split
 * @param delimiters: the array of delimiter strings to use for splitting
 *
 * @returns This function returns an array of strings, with each element being a substring of
 * the original string, separated by the specified delimiter. The returned array must
 * be freed by the caller.
 */
char **split_s(char *str, char **delimiters, int delim_count);

/**
 * @brief strndup_ - duplicate a string for a specified number of characters
 * @param str: the string to duplicate
 * @param chars: the number of characters to duplicate
 *
 * @returns This function returns a pointer to a newly allocated string, which is a duplicate of
 * the first 'chars' characters of the original string. The returned string must be
 * freed by the caller.
 */
char *strndup_(const char *str, unsigned long long int chars);

/**
 * @brief substring - extract a substring from a string, given a starting position and length
 * @param str: the string to extract from
 * @param start: the starting position of the substring
 * @param length: the length of the substring
 *
 * @returns This function returns a pointer to a newly allocated string, which is a copy of the
 * specified substring of the original string. If the specified substring is outside
 * the bounds of the original string, the function returns NULL. The returned string
 * must be freed by the caller.
 */
char *substring(char *str, int start, int length);

/**
 * @brief substr - extract a substring from a string, given a starting and ending position
 * @param str: the string to extract from
 * @param start: the starting position of the substring
 * @param end: the ending position of the substring
 *
 * @returns This function returns a pointer to a newly allocated string, which is a copy of the
 * specified substring of the original string. If the specified substring is outside
 * the bounds of the original string, the function returns NULL. The returned string
 * must be freed by the caller.
 */
char *substr(char *str, int start, int end);

/**
* 
* @brief Returns a substring from the given string, starting from the specified index.
* @param str The original string to extract a substring from.
* @param start The starting index for the substring.
* @return char* The extracted substring, or NULL if the start index is invalid. The returned string 
* must be freed by the caller.
*/
char *substring_s(char *str, int start);

/**
* 
* @brief Trims the leading whitespaces from the given string.
* @param s The original string to trim.
* @return char* The trimmed string.
*/
char *ltrim(char *s);

/**
* 
* @brief Trims the trailing whitespaces from the given string.
* @param s The original string to trim.
* @return char* The trimmed string. The returned string
* must be freed by the caller.
*/
char *rtrim(char *s);

/**
* 
* @brief Trims the leading and trailing whitespaces from the given string.
* @param s The original string to trim.
* @return char* The trimmed string.
*/
char *trim(char *s);

/**
* 
* @brief Replaces all occurrences of a given needle string in a haystack string with a replacement string.
* @param haystack The original string to perform the replacements in.
* @param needle The string to replace.
* @param replacement The string to replace the needle with.
* @param max_replacements The maximum number of replacements to perform.
*  -1 signifies that all replacements are to be made.
* @return char* The modified string with the replacements performed. The returned string
*  must be freed by the caller.
*/
char *replace(char *haystack, char *needle, char *replacement, int max_replacements);

/**
* 
* replaceLast - replaces the last occurrence of a specified string in a given string with another string
* @str: the string to search and replace in
* @target: the string to search for
* @replacement: the string to replace with
* @count: the number of replacements to be made
* Returns a char pointer to the resulting string. The returned string
* must be freed by the caller.
*/
char *replacelast(const char *str, const char *target, const char *replacement, int count);

/**
 * Removes all non-ASCII characters from a string and returns a char pointer.
 *
 * @param str A constant char pointer representing the input string
 * @return A char pointer representing the output string without non-ASCII characters. The returned string
 * must be freed by the caller.
 */
 char* removenonascii(const char* str);

/**
* 
* @brief Determines if a string starts with a given prefix string, with case sensitivity based on the provided flag.
* @param str The original string to check.
* @param pre The prefix string to check for.
* @param case A flag indicating whether the comparison should be case sensitive.
* @return bool True if the string starts with the given prefix, False otherwise.
*/
bool startswith(const char *str, const char *pre, bool $case);
/**
* 
* @brief Determines if a string ends with a given suffix string, with case sensitivity based on the provided flag.
* @param str The original string to check.
* @param suffix The suffix string to check for.
* @param case A flag indicating whether the comparison should be case sensitive.
* @return bool True if the string ends with the given suffix, False otherwise.
*/
bool endswith(const char *str, const char *suffix, bool $case);
/**
* 
* @brief Determines if a haystack string contains a given needle string, with case sensitivity based on the provided flag.
* @param haystack The original string to search.
* @param needle The string to search for.
* @param case A flag indicating whether the search should be case sensitive.
* @return bool True if the haystack string contains the needle, False otherwise.
*/
bool contains(char *haystack, char *needle, bool $case);

/**
 * Inserts a string into another string at a given start index.
 *
 * @param str The string to insert into.
 * @param start The index to start the insertion.
 * @param value The string to be inserted.
 * @return A new string with the insertion. Returns NULL if the start index is out of range. The returned string
 * must be freed by the caller.
 */
char *insert(char *str, int start, char *value);

/**
 * Joins an array of `char*`/`char[]`, `int`, `float`, `double` into a single string using a delimiter.
 *
 * @param arr The `char*`/`char[]`, `int`, `float`, `double` of strings to join.
 * @param size The number of strings in the array.
 * @param delim The delimiter to separate the strings.
 * @param t An enum consisting of CHAR, INT, FLOAT, DOUBLE denoting the type of arr
 * @return A new string with the joined strings. The returned string
 * must be freed by the caller.
 */
char *join(void **arr, int size, char *delim, TYPE t);

/**
 * Concatenates two strings into a single string.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 * @return A new string with the concatenated strings. The returned string
 * must be freed by the caller.
 */
char *concat(char *str1, char *str2);

/**
 * Concatenates str1 and c, a char, into a single string.
 *
 * @param str1 The first string.
 * @param str2 A char.
 * @return A new string with the concatenated string and char. The returned string
 * must be freed by the caller.
 */
char *concatc(char *str1, char c);

/**
 * Converts a string to uppercase.
 *
 * @param str The string to convert to uppercase.
 * @return A new string with the converted characters. The returned string
 * must be freed by the caller.
 */
char *toupr(char *str);

/**
 * Converts a string to lowercase.
 *
 * @param str The string to convert to lowercase.
 * @return A new string with the converted characters. The returned string
 * must be freed by the caller.
 */
char *tolwr(char *str);

/**
 * Reverse a string in-place.
 * 
 * @param str The input string.
 * @return The reversed string. The returned string must be freed by the caller.
 */
char *reverse(char *str);

/**
 * @brief Counts the number of occurrences of `needle` in the string `haystack`.
 *
 * @param haystack The string to search in.
 * @param needle The character to search for.
 * @param case Whether to perform a case-sensitive or case-insensitive search.
 * @return The number of occurrences of `needle` in `haystack`.
 */
int count(char *haystack, char needle, bool $case);

/**
 * @brief Counts the number of occurrences of `needle` in the string `haystack` starting from the `start` index.
 *
 * @param haystack The string to search in.
 * @param needle The character to search for.
 * @param start The index to start the search from.
 * @param case Whether to perform a case-sensitive or case-insensitive search.
 * @return The number of occurrences of `needle` in `haystack` starting from `start`.
 */
int scount(char *haystack, char needle, int start, bool $case);

/**
 * @brief Counts the number of occurrences of `needle` in the first `count` characters of the string `haystack`.
 *
 * @param haystack The string to search in.
 * @param needle The character to search for.
 * @param count The number of characters to search in `haystack`.
 * @param case Whether to perform a case-sensitive or case-insensitive search.
 * @return The number of occurrences of `needle` in the first `count` characters of `haystack`.
 */
int icount(char *haystack, char needle, int count, bool $case);

/**
 * @brief Counts the number of occurrences of `needle` in the string `haystack` starting
 * from the `start` index for `count` characters.
 *
 * @param haystack The string to search in.
 * @param needle The character to search for.
 * @param start The index to start the search from.
 * @param count The number of characters to search in `haystack` starting from `start`.
 * @param case Whether to perform a case-sensitive or case-insensitive search.
 * @return The number of occurrences of `needle` in `haystack` starting from `start` for `count` characters.
 */
int iscount(char *haystack, char needle, int start, int count, bool $case);

/**
 * @brief Counts the number of occurrences of `needle` (a string) in the string `haystack`.
 *
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @param case Whether to perform a case-sensitive or case-insensitive search.
 * @return The number of occurrences of `needle` in `haystack`.
 */
int strcount(char *haystack, char *needle, bool $case);

/**
 * @brief Finds the number of occurences of `needle` in `haystack`
 *        starting from a given `start` position and taking into account
 *        case sensitivity as specified by `$case` flag.
 *
 * @param haystack A string where the search is performed.
 * @param needle A string that is searched in `haystack`.
 * @param start An integer specifying the start position of the search.
 * @param case A boolean flag indicating whether the search should be case sensitive.
 *
 * @return The number of occurences of `needle` in `haystack`.
 */
int strscount(char *haystack, char *needle, int start, bool $case);

/**
 * @brief Finds the number of occurences of `needle` in `haystack`
 *        for a given number of characters `count` and taking into account
 *        case sensitivity as specified by `$case` flag.
 *
 * @param haystack A string where the search is performed.
 * @param needle A string that is searched in `haystack`.
 * @param count An integer specifying the number of characters to be searched.
 * @param case A boolean flag indicating whether the search should be case sensitive.
 *
 * @return The number of occurences of `needle` in `haystack`.
 */
int stricount(char *haystack, char *needle, int count, bool $case);

/**
 * @brief Finds the number of occurences of `needle` in `haystack`
 *        starting from a given `start` position and searching for a given number
 *        of characters `count`, taking into account case sensitivity
 *        as specified by `$case` flag.
 *
 * @param haystack A string where the search is performed.
 * @param needle A string that is searched in `haystack`.
 * @param start An integer specifying the start position of the search.
 * @param count An integer specifying the number of characters to be searched.
 * @param case A boolean flag indicating whether the search should be case sensitive.
 *
 * @return The number of occurences of `needle` in `haystack`.
 */
int striscount(char *haystack, char *needle, int start, int count, bool $case);


/**
* 
* @brief Finds the index of a specified character in a string.
* @param str Pointer to the string to be searched.
* @param lookup The character to search for.
* @param case Specifies whether the search should be case-sensitive (true) or case-insensitive (false).
* @return Returns the index of the first occurrence of the specified character in the string, or -1
*  if the character is not found.
*/
int indexof(char *str, char lookup, bool $case);

/**
* 
* @brief Finds the index of a specified character in a string starting from a specified index.
* @param str Pointer to the string to be searched.
* @param c The character to search for.
* @param startIndex The index to start the search from.
* @param case Specifies whether the search should be case-sensitive (true) or case-insensitive (false).
* @return Returns the index of the first occurrence of the specified character in the string starting
*  from the specified index, or -1 if the character is not found.
*/
int sindexof(const char *str, char c, int startIndex, bool $case);

/**
 * Finds the index of a specified character in a string.
 *
 * @param str The string to search in.
 * @param count The number of characters to search.
 * @param value The character to search for.
 * @param case Specifies whether to perform a case-sensitive search (true) or case-insensitive search (false).
 *
 * @return The index of the specified character in the string. Returns -1 if the character is not found.
 */
int iindexof(char *str, int count, char value, bool $case);

/**
* 
* @brief Finds the index of a specified character in a string within a specified range.
* @param str Pointer to the string to be searched.
* @param startIndex The index to start the search from.
* @param count The number of characters to search for the specified character.
* @param value The character to search for.
* @param case Specifies whether the search should be case-sensitive (true) or case-insensitive (false).
* @return Returns the index of the first occurrence of the specified character in the string
*  within the specified range, or -1 if the character is not found.
*/
int isindexof(char *str, int startIndex, int count, char value, bool $case);

/**
* 
* @brief Finds the index of a specified string in another string.
* @param str Pointer to the string to be searched.
* @param value The string to search for.
* @param case Specifies whether the search should be case-sensitive (true) or case-insensitive (false).
* @return Returns the index of the first occurrence of the specified string in the string,
*  or -1 if the string is not found.
*/
int strindexof(const char *str, const char *value, bool $case);

/**
* 
* @brief Finds the index of a specified string in another string starting from a specified index.
* @param str Pointer to the string to be searched.
* @param value The string to search for.
* @param startIndex The index to start the search from.
* @param case Specifies whether the search should be case-sensitive (true) or case-insensitive (false).
* @return Returns the index of the first occurrence of the specified string in the string starting
*  from the specified index, or -1 if the string is not found.
*/
int strsindexof(const char *str, const char *value, int startIndex, bool $case);

/**
 * Finds the index of a specified string in a string.
 *
 * @param str The string to search in.
 * @param count The number of characters to search.
 * @param value The string to search for.
 * @param case Specifies whether to perform a case-sensitive search (true) or case-insensitive search (false).
 *
 * @return The index of the specified string in the string. Returns -1 if the string is not found.
 */
int striindexof(char *str, int count, char *value, bool $case);

/**
* 
* @brief Finds the index of a specified string within another string.
* @param str The string to search in.
* @param startIndex The starting index to search from.
* @param count The number of characters to search.
* @param value The string to search for.
* @param case Whether the search should be case-sensitive or not.
* @return The index of the first occurrence of the value string in the str string, or -1 if the value is not found.
*/
int strisindexof(char *str, int startIndex, int count, char *value, bool $case);

/**
* 
* @brief Finds the index of the last occurrence of a specified character in a string.
* @param str The string to search in.
* @param lookup The character to search for.
* @param case Whether the search should be case-sensitive or not.
* @return The index of the last occurrence of the lookup character in the str string,
*  or -1 if the character is not found.
*/
int lastindexof(char *str, char lookup, bool $case);

/**
* 
* @brief Finds the index of the last occurrence of a specified character in a string starting from a specified index.
* @param str The string to search in.
* @param value The character to search for.
* @param startIndex The starting index to search from.
* @param case Whether the search should be case-sensitive or not.
* @return The index of the last occurrence of the value character in the str string starting
*  from the startIndex, or -1 if the character is not found.
*/
int slastindexof(const char *str, char value, int startIndex, bool $case);

/**
 * Finds the index of the last occurrence of a specified character in a string.
 *
 * @param str The string to search in.
 * @param value The character to search for.
 * @param count The number of characters to search.
 * @param case Specifies whether to perform a case-sensitive search (true) or case-insensitive search (false).
 *
 * @return The index of the last occurrence of the specified character in the string. Returns -1 if the character is not found.
 */
int ilastindexof(const char *str, char value, int count, bool $case);

/**
* 
* @brief Returns the index of the last occurrence of a specified character in a string starting
*  from a specified index and searching only a specified number of characters.
* @param str The input string.
* @param value The character to search for.
* @param startIndex The starting index in the input string.
* @param count The number of characters to search in the input string.
* @param case Indicates whether to perform a case-sensitive search (true) or case-insensitive search (false).
* @return The index of the last occurrence of the specified character in the input string,
*  or -1 if the character is not found.
*/
int islastindexof(const char *str, char value, int startIndex, int count, bool $case);

/**
*
*@brief Finds the index of the last occurrence of a specified string in a string.
*@param str The string to search in.
*@param value The string to search for.
*@param case Whether the search should be case-sensitive or not.
*@return The index of the last occurrence of the value string in the str string, or -1 if the value is not found.
*/
int strlastindexof(const char *str, const char *value, bool $case);

/**
* 
* @brief Finds the index of the last occurrence of a specified string in a string starting from a specified index.
* @param str The string to search in.
* @param value The string to search for.
* @param startIndex The starting index to search from.
* @param case Whether the search should be case-sensitive or not.
* @return The index of the last occurrence of the value string in the str string starting
*  from the startIndex, or -1 if the value is not found.
*/
int strslastindexof(const char *str, const char *value, int startIndex, bool $case);

/**
 * Finds the index of the last occurrence of a specified string in a string.
 *
 * @param str The string to search in.
 * @param value The string to search for.
 * @param count The number of characters to search.
 * @param case Specifies whether to perform a case-sensitive search (true) or case-insensitive search (false).
 *
 * @return The index of the last occurrence of the specified string in the string. Returns -1 if the string is not found.
 */
int strilastindexof(const char *str, const char *value, int count, bool $case);

/**
* 
* @brief Returns the index of the last occurrence of a specified string in a string starting from
*  a specified index and searching only a specified number of characters.
* @param str The input string.
* @param value The string to search for.
* @param startIndex The starting index in the input string.
* @param count The number of characters to search in the input string.
* @param case Indicates whether to perform a case-sensitive search (true) or case-insensitive search (false).
* @return The index of the last occurrence of the specified string in the input string,
*  or -1 if the string is not found.
*/
int strislastindexof(const char *str, const char *value, int startIndex, int count, bool $case);
