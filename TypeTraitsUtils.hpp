/**
 * @file TypeTraitsUtils.hpp
 * @brief Compile-time type checking utilities using type_traits
 *
 * This file demonstrates std::type_traits for compile-time type
 * introspection. Since these are templates, ALL code is in this header.
 *
 * Students must implement the functions marked with "Must be implemented".
 *
 * Topics covered:
 * - std::is_integral, std::is_floating_point, std::is_arithmetic
 * - std::is_same, std::is_pointer, std::is_const
 * - std::enable_if (SFINAE) for conditional compilation
 * - std::conditional for type selection
 * - constexpr functions with type traits
 */

#ifndef TYPETRAITSUTILS_HPP
#define TYPETRAITSUTILS_HPP

#include <type_traits>
#include <string>
#include <sstream>

namespace registration {

    // ============================================================
    //                COMPILE-TIME TYPE CHECKS
    // ============================================================

    /**
     * @brief Get a human-readable description of a type at compile time
     *
     * Returns:
     *   - "integral" if T is an integral type
     *   - "floating-point" if T is a floating-point type
     *   - "string" if T is std::string
     *   - "pointer" if T is a pointer type
     *   - "other" otherwise
     *
     * @tparam T The type to describe
     * @return A string description of the type
     * Must be implemented.
     */
    template <typename T>
    std::string describeType() {
        // Must be implemented
        return ""; // placeholder
    }

    /**
     * @brief Check if a type is a numeric type (integral or floating-point)
     * @tparam T The type to check
     * @return true if T is numeric
     * Must be implemented.
     */
    template <typename T>
    constexpr bool isNumeric() {
        // Must be implemented
        return false; // placeholder
    }

    /**
     * @brief Check if two types are the same
     * @tparam T First type
     * @tparam U Second type
     * @return true if T and U are the same type
     * Must be implemented.
     */
    template <typename T, typename U>
    constexpr bool areSameType() {
        // Must be implemented
        return false; // placeholder
    }

    // ============================================================
    //            SFINAE-BASED CONDITIONAL FUNCTIONS
    // ============================================================

    /**
     * @brief Convert a numeric value to a string (only for arithmetic types)
     *
     * Uses std::enable_if to only compile for arithmetic types.
     * For integral types: returns the number as a string
     * For floating-point types: returns with 2 decimal places
     *
     * @tparam T Must be an arithmetic type
     * @param value The value to convert
     * @return The string representation
     * Must be implemented.
     */
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, std::string>::type
    numericToString(T value) {
        // Must be implemented
        return ""; // placeholder
    }

    /**
     * @brief Safely add two values, returning the wider type
     *
     * Uses std::conditional to determine the return type:
     *   - If either type is floating-point, return double
     *   - Otherwise return long long
     *
     * @tparam T First operand type
     * @tparam U Second operand type
     * @return The sum in the wider type
     * Must be implemented.
     */
    template <typename T, typename U>
    auto safeAdd(T a, U b) ->
        typename std::conditional<
            std::is_floating_point<T>::value || std::is_floating_point<U>::value,
            double,
            long long
        >::type
    {
        // Must be implemented
        using ReturnType = typename std::conditional<
            std::is_floating_point<T>::value || std::is_floating_point<U>::value,
            double,
            long long
        >::type;
        return static_cast<ReturnType>(0); // placeholder
    }

    /**
     * @brief Get the zero value for a type
     *
     * Returns:
     *   - 0 for integral types
     *   - 0.0 for floating-point types
     *   - "" for std::string
     *   - T{} for other types
     *
     * @tparam T The type
     * @return The zero/default value
     * Must be implemented.
     */
    template <typename T>
    T getZero() {
        // Must be implemented using if constexpr with type traits
        // to return 0 for integral, 0.0 for floating-point,
        // "" for string, and T{} for other types.
        if constexpr (std::is_arithmetic_v<T>) {
            return static_cast<T>(1); // placeholder — wrong value
        } else {
            return T{}; // placeholder
        }
    }

} // namespace registration

#endif // TYPETRAITSUTILS_HPP