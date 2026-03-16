/**
 * @file StudentRecord.hpp
 * @brief Functions for working with student records using tuples
 *
 * This file demonstrates std::tuple, std::get, std::tie, and
 * std::make_tuple for representing and manipulating student data.
 *
 * A StudentRecord is a tuple of (string name, int id, double grade).
 *
 * Students must implement the corresponding StudentRecord.cpp file.
 *
 * Topics covered:
 * - std::tuple creation and access
 * - std::get<N> for element access
 * - std::tie for unpacking tuples
 * - std::vector of tuples
 * - Sorting and filtering tuples
 */

#ifndef STUDENTRECORD_HPP
#define STUDENTRECORD_HPP

#include <string>
#include <tuple>
#include <vector>

namespace registration {

    // Type alias for a student record: (name, ID, grade)
    using StudentRecord = std::tuple<std::string, int, double>;

    /**
     * @brief Create a new student record
     * @param name Student name
     * @param id Student ID (must be > 0)
     * @param grade Student grade (must be between 0.0 and 100.0)
     * @return A StudentRecord tuple
     * @throws std::invalid_argument if id <= 0 or grade is out of range
     * Must be implemented in StudentRecord.cpp.
     */
    StudentRecord createRecord(const std::string& name, int id, double grade);

    /**
     * @brief Get the student's name from a record
     * @param record The student record
     * @return The name
     * Must be implemented in StudentRecord.cpp.
     */
    std::string getName(const StudentRecord& record);

    /**
     * @brief Get the student's ID from a record
     * @param record The student record
     * @return The ID
     * Must be implemented in StudentRecord.cpp.
     */
    int getId(const StudentRecord& record);

    /**
     * @brief Get the student's grade from a record
     * @param record The student record
     * @return The grade
     * Must be implemented in StudentRecord.cpp.
     */
    double getGrade(const StudentRecord& record);

    /**
     * @brief Unpack a record into individual variables using std::tie
     * @param record The student record
     * @param name Output: student name
     * @param id Output: student ID
     * @param grade Output: student grade
     * Must be implemented in StudentRecord.cpp.
     */
    void unpackRecord(const StudentRecord& record,
                      std::string& name, int& id, double& grade);

    /**
     * @brief Format a record as a string
     * Format: "Name (ID: <id>, Grade: <grade>)"
     * Grade should be displayed with 1 decimal place.
     * Example: "Alice (ID: 12345, Grade: 92.5)"
     * @param record The student record
     * @return The formatted string
     * Must be implemented in StudentRecord.cpp.
     */
    std::string formatRecord(const StudentRecord& record);

    /**
     * @brief Calculate average grade from a vector of records
     * @param records The vector of student records
     * @return The average grade
     * @throws std::invalid_argument if the vector is empty
     * Must be implemented in StudentRecord.cpp.
     */
    double averageGrade(const std::vector<StudentRecord>& records);

    /**
     * @brief Find the record with the highest grade
     * @param records The vector of student records
     * @return The record with the highest grade
     * @throws std::invalid_argument if the vector is empty
     * Must be implemented in StudentRecord.cpp.
     */
    StudentRecord bestStudent(const std::vector<StudentRecord>& records);

    /**
     * @brief Sort records by grade in descending order
     * Returns a NEW sorted vector (does not modify the original).
     * @param records The vector of student records
     * @return A new vector sorted by grade (highest first)
     * Must be implemented in StudentRecord.cpp.
     */
    std::vector<StudentRecord> sortByGrade(const std::vector<StudentRecord>& records);

    /**
     * @brief Sort records by name in ascending alphabetical order
     * Returns a NEW sorted vector.
     * @param records The vector of student records
     * @return A new vector sorted by name (A-Z)
     * Must be implemented in StudentRecord.cpp.
     */
    std::vector<StudentRecord> sortByName(const std::vector<StudentRecord>& records);

    /**
     * @brief Filter records that have a grade above a threshold
     * @param records The vector of student records
     * @param threshold The minimum grade (exclusive)
     * @return A new vector with only records where grade > threshold
     * Must be implemented in StudentRecord.cpp.
     */
    std::vector<StudentRecord> filterByGrade(
        const std::vector<StudentRecord>& records, double threshold);

} // namespace registration

#endif // STUDENTRECORD_HPP