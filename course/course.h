 /**
  * @file course.h
  * @author Ameer Hamoodi (hamoodia@mcmaster.ca)
  * @brief Define the interfaces for the course library functions and for the struct
  * @date 2022-04-09
  * 
  */
#include "student.h"
#include <stdbool.h>

/**
 * Course type with fields, name, code, students and total_students
 * 
 */
typedef struct _course 
{
  char name[100]; /** <the course's name */
  char code[10];/** <the course's code */
  Student *students;/** <a list of the course's students */
  int total_students;/** <the total number of students enroled in the course */
} Course;

/**
  * Enrol a student in a specific course
  * 
  * @param course The course you want to enrol the student in
  * @param student The student you want to enrol in the course
  * @return nothing
*/
void enroll_student(Course *course, Student *student);

/**
 * Print a summary of the course, including:
 * - Name
 * - Code
 * - Total students
 * - A list of each student
 * 
 * @param course The course you want to print
 * @return nothing
*/
void print_course(Course *course);

/**
 * Get the top student of the course
 * 
 * @param course The course you want to get the top student of
 * @return Student* The top student of this course
*/
Student *top_student(Course* course);

/**
 * Get the students passing a specific course and the total number students passing
 * 
 * @param course The course you want to check
 * @param total_passing The variable you want to store the number of passing students in
 * @return Student* An array of all the passing students
*/
Student *passing(Course* course, int *total_passing);


