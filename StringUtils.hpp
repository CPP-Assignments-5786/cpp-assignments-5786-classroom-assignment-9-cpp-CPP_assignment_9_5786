/**
 * @file StringUtils.hpp
 * @brief Utility functions for string processing
 *
 * This file demonstrates std::string operations and algorithms
 * for text processing in the registration system.
 *
 * Students must implement the corresponding StringUtils.cpp file.
 *
 * Topics covered:
 * - std::string find, substr, replace
 * - String iteration and character manipulation
 * - String splitting and joining
 * - Basic string algorithms
 */

#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <string>
#include <vector>

namespace registration {

    /**
     * @brief Convert a string to uppercase
     * @param str The input string
     * @return A new string with all characters in uppercase
     * Must be implemented in StringUtils.cpp.
     */
    std::string toUpper(const std::string& str);

    /**
     * @brief Convert a string to lowercase
     * @param str The input string
     * @return A new string with all characters in lowercase
     * Must be implemented in StringUtils.cpp.
     */
    std::string toLower(const std::string& str);

    /**
     * @brief Trim whitespace from both ends of a string
     * @param str The input string
     * @return A new string with leading and trailing whitespace removed
     * Must be implemented in StringUtils.cpp.
     */
    std::string trim(const std::string& str);

    /**
     * @brief Split a string by a delimiter character
     * @param str The input string
     * @param delimiter The character to split on
     * @return A vector of substrings
     * Must be implemented in StringUtils.cpp.
     *
     * Example: split("a,b,c", ',') → {"a", "b", "c"}
     */
    std::vector<std::string> split(const std::string& str, char delimiter);

    /**
     * @brief Join a vector of strings with a separator
     * @param parts The strings to join
     * @param separator The separator string
     * @return The joined string
     * Must be implemented in StringUtils.cpp.
     *
     * Example: join({"a", "b", "c"}, ", ") → "a, b, c"
     */
    std::string join(const std::vector<std::string>& parts, const std::string& separator);

    /**
     * @brief Check if a string starts with a given prefix
     * @param str The string to check
     * @param prefix The prefix to look for
     * @return true if str starts with prefix
     * Must be implemented in StringUtils.cpp.
     */
    bool startsWith(const std::string& str, const std::string& prefix);

    /**
     * @brief Check if a string ends with a given suffix
     * @param str The string to check
     * @param suffix The suffix to look for
     * @return true if str ends with suffix
     * Must be implemented in StringUtils.cpp.
     */
    bool endsWith(const std::string& str, const std::string& suffix);

    /**
     * @brief Replace all occurrences of a substring with another
     * @param str The input string
     * @param from The substring to find. If empty, the original string is returned unchanged.
     * @param to The replacement string
     * @return A new string with all occurrences replaced.
     * Must be implemented in StringUtils.cpp.
     */
    std::string replaceAll(const std::string& str,
                           const std::string& from, const std::string& to);

    /**
     * @brief Count occurrences of a character in a string
     * @param str The input string
     * @param ch The character to count
     * @return The number of occurrences
     * Must be implemented in StringUtils.cpp.
     */
    int countChar(const std::string& str, char ch);

    /**
     * @brief Check if a string is a palindrome (ignoring case and spaces)
     * @param str The input string
     * @return true if the string is a palindrome
     * Must be implemented in StringUtils.cpp.
     *
     * Example: isPalindrome("Race Car") → true
     */
    bool isPalindrome(const std::string& str);

    /**
     * @brief Reverse a string
     * @param str The input string
     * @return A new string with characters reversed
     * Must be implemented in StringUtils.cpp.
     */
    std::string reverseString(const std::string& str);

} // namespace registration

#endif // STRINGUTILS_HPP