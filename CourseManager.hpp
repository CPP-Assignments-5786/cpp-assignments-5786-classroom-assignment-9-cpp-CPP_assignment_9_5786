/**
 * @file CourseManager.hpp
 * @brief Class for managing courses and student enrollments
 *
 * This class uses std::map, std::set, and std::vector to manage
 * a course registration system.
 *
 * Students must implement the corresponding CourseManager.cpp file.
 *
 * Topics covered:
 * - std::map for course → enrolled students mapping
 * - std::set for unique student IDs per course
 * - std::vector for ordered student lists
 * - Iteration over STL containers
 */

#ifndef COURSEMANAGER_HPP
#define COURSEMANAGER_HPP

#include "StudentRecord.hpp"
#include <string>
#include <map>
#include <set>
#include <vector>

namespace registration {

    class CourseManager {
    private:
        // Maps course name to a set of enrolled student IDs
        std::map<std::string, std::set<int>> courseEnrollments;

        // Maps student ID to their record
        std::map<int, StudentRecord> studentDatabase;

        // Maps course name to a vector of grades for that course
        std::map<std::string, std::vector<double>> courseGrades;

    public:

        /**
         * @brief Add a student to the database
         * @param record The student record to add
         * @throws std::invalid_argument if a student with this ID already exists
         * Must be implemented in CourseManager.cpp.
         */
        void addStudent(const StudentRecord& record);

        /**
         * @brief Create a new course
         * @param courseName The name of the course
         * @throws std::invalid_argument if the course already exists
         * Must be implemented in CourseManager.cpp.
         */
        void createCourse(const std::string& courseName);

        /**
         * @brief Enroll a student in a course
         * @param studentId The student's ID
         * @param courseName The course name
         * @throws std::invalid_argument if the student doesn't exist
         * @throws std::invalid_argument if the course doesn't exist
         * @throws std::invalid_argument if the student is already enrolled
         * Must be implemented in CourseManager.cpp.
         */
        void enrollStudent(int studentId, const std::string& courseName);

        /**
         * @brief Remove a student from a course
         * @param studentId The student's ID
         * @param courseName The course name
         * @throws std::invalid_argument if the student is not enrolled in this course
         * Must be implemented in CourseManager.cpp.
         */
        void removeStudent(int studentId, const std::string& courseName);

        /**
         * @brief Assign a grade to a student in a course
         *
         * Each call appends a new grade entry for the course.
         * If a student is graded multiple times, all entries are
         * included when computing the course average via getCourseAverage().
         *
         * @param studentId The student's ID
         * @param courseName The course name
         * @param grade The grade (0.0 to 100.0)
         * @throws std::invalid_argument if student is not enrolled in the course
         * @throws std::invalid_argument if grade is out of range
         * Must be implemented in CourseManager.cpp.
         */
        void assignGrade(int studentId, const std::string& courseName, double grade);

        /**
         * @brief Check if a student is enrolled in a course
         * @param studentId The student's ID
         * @param courseName The course name
         * @return true if enrolled
         * Must be implemented in CourseManager.cpp.
         */
        bool isEnrolled(int studentId, const std::string& courseName) const;

        /**
         * @brief Get the number of students enrolled in a course
         * @param courseName The course name
         * @return Number of enrolled students
         * @throws std::invalid_argument if the course doesn't exist
         * Must be implemented in CourseManager.cpp.
         */
        int getEnrollmentCount(const std::string& courseName) const;

        /**
         * @brief Get all student IDs enrolled in a course (as a sorted vector)
         * @param courseName The course name
         * @return Vector of student IDs (sorted, since sets are ordered)
         * @throws std::invalid_argument if the course doesn't exist
         * Must be implemented in CourseManager.cpp.
         */
        std::vector<int> getEnrolledStudents(const std::string& courseName) const;

        /**
         * @brief Get all courses a student is enrolled in
         * @param studentId The student's ID
         * @return Vector of course names the student is enrolled in
         * Must be implemented in CourseManager.cpp.
         */
        std::vector<std::string> getStudentCourses(int studentId) const;

        /**
         * @brief Get a student record by ID
         * @param studentId The student's ID
         * @return The student record
         * @throws std::invalid_argument if student doesn't exist
         * Must be implemented in CourseManager.cpp.
         */
        StudentRecord getStudent(int studentId) const;

        /**
         * @brief Get all course names
         * @return Vector of all course names (sorted alphabetically)
         * Must be implemented in CourseManager.cpp.
         */
        std::vector<std::string> getAllCourses() const;

        /**
         * @brief Get all student IDs
         * @return Vector of all student IDs (sorted)
         * Must be implemented in CourseManager.cpp.
         */
        std::vector<int> getAllStudentIds() const;

        /**
         * @brief Get the total number of students in the database
         * @return Number of students
         * Must be implemented in CourseManager.cpp.
         */
        int getTotalStudents() const;

        /**
         * @brief Get the total number of courses
         * @return Number of courses
         * Must be implemented in CourseManager.cpp.
         */
        int getTotalCourses() const;

        /**
         * @brief Find students enrolled in BOTH of two courses
         * @param course1 First course name
         * @param course2 Second course name
         * @return Vector of student IDs enrolled in both courses
         * Must be implemented in CourseManager.cpp.
         */
        std::vector<int> studentsInBothCourses(
            const std::string& course1, const std::string& course2) const;

        /**
         * @brief Find students enrolled in EITHER of two courses (union)
         * @param course1 First course name
         * @param course2 Second course name
         * @return Vector of student IDs enrolled in at least one course
         * Must be implemented in CourseManager.cpp.
         */
        std::vector<int> studentsInEitherCourse(
            const std::string& course1, const std::string& course2) const;

        /**
         * @brief Get the average of all grades assigned in a course
         * @param courseName The course name
         * @return The average grade
         * @throws std::invalid_argument if no grades exist for this course
         * Must be implemented in CourseManager.cpp.
         */
        double getCourseAverage(const std::string& courseName) const;
    };

} // namespace registration

#endif // COURSEMANAGER_HPP