/**
 * @file Riddles.hpp
 * @brief Logic puzzles solved using STL containers
 *
 * Each riddle uses STL containers (vectors, maps, sets) to solve
 * a specific problem. This tests the student's ability to choose
 * the right container and algorithm for each task.
 *
 * Students must implement the corresponding Riddles.cpp file.
 *
 * Topics covered:
 * - Choosing the right STL container for each problem
 * - std::vector, std::map, std::set operations
 * - Algorithm design with STL
 */

#ifndef RIDDLES_HPP
#define RIDDLES_HPP

#include <vector>
#include <string>
#include <map>
#include <set>

namespace registration {

    /**
     * @brief Riddle 1: Find two numbers in a vector that add up to a target
     *
     * Given a vector of integers and a target sum, find two distinct indices
     * whose values add up to the target. Return them as a pair (smaller index first).
     *
     * @param nums The vector of integers
     * @param target The target sum
     * @return A pair of indices (i, j) where i < j and nums[i] + nums[j] == target
     * @throws std::invalid_argument if no such pair exists
     *
     * Hint: Use a map to store value → index for O(n) solution.
     * Must be implemented in Riddles.cpp.
     */
    std::pair<int, int> twoSum(const std::vector<int>& nums, int target);

    /**
     * @brief Riddle 2: Find the first non-repeating character in a string
     *
     * @param str The input string
     * @return The first character that appears exactly once, or '\0' if none
     *
     * Hint: Use a map to count character frequencies, then find the first with count 1.
     * Must be implemented in Riddles.cpp.
     */
    char firstUniqueChar(const std::string& str);

    /**
     * @brief Riddle 3: Check if two strings are anagrams
     *
     * Two strings are anagrams if they contain the same characters
     * with the same frequencies (case-insensitive, ignoring spaces).
     *
     * @param str1 First string
     * @param str2 Second string
     * @return true if the strings are anagrams
     *
     * Hint: Use a map to count character frequencies.
     * Must be implemented in Riddles.cpp.
     */
    bool areAnagrams(const std::string& str1, const std::string& str2);

    /**
     * @brief Riddle 4: Find the longest sequence of consecutive integers
     *
     * Given a vector of unsorted integers, find the length of the longest
     * sequence of consecutive numbers (the order in the vector doesn't matter).
     *
     * Example: {100, 4, 200, 1, 3, 2} → 4 (because 1, 2, 3, 4 is consecutive)
     *
     * @param nums The vector of integers
     * @return Length of the longest consecutive sequence
     *
     * Hint: Use a set for O(1) lookups.
     * Must be implemented in Riddles.cpp.
     */
    int longestConsecutive(const std::vector<int>& nums);

    /**
     * @brief Riddle 5: Group words by their sorted character signature (anagram groups)
     *
     * Given a vector of strings, group all anagrams together.
     * Return a vector of groups (each group is a vector of strings).
     * Within each group, strings should be in the order they appeared in the input.
     * The groups can be in any order.
     *
     * Example: {"eat", "tea", "tan", "ate", "nat", "bat"}
     *   → {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}}
     *
     * @param words The vector of words
     * @return Vector of anagram groups
     *
     * Hint: Use a map with the sorted word as the key.
     * Must be implemented in Riddles.cpp.
     */
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& words);

    /**
     * @brief Riddle 6: Find the most frequent element in a vector
     *
     * If there is a tie, return the element that appears first in the vector.
     *
     * @param nums The vector of integers
     * @return The most frequent element
     * @throws std::invalid_argument if the vector is empty
     *
     * Hint: Use a map for counting.
     * Must be implemented in Riddles.cpp.
     */
    int mostFrequent(const std::vector<int>& nums);

    /**
     * @brief Riddle 7: Remove duplicate elements while preserving order
     *
     * @param nums The vector of integers
     * @return A new vector with duplicates removed, maintaining original order
     *
     * Hint: Use a set to track seen elements.
     * Must be implemented in Riddles.cpp.
     */
    std::vector<int> removeDuplicates(const std::vector<int>& nums);

} // namespace registration

#endif // RIDDLES_HPP