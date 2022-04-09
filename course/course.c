/**
 * @file course.c
 * @author Ameer Hamoodi (hamoodia@mcmaster.ca)
 * @brief Module containing all the code for the course library functions
 * @date 2022-04-09
 *  
 */
#include "course.h"
#include <stdlib.h>
#include <stdio.h>
 
/**
  * Enrol a student in a specific course
  * 
  * @param course The course you want to enrol the student in
  * @param student The student you want to enrol in the course
  * @return nothing
*/
void enroll_student(Course *course, Student *student)
{
  // When enroling a stuednt increase the number of students by 1
  course->total_students++;
  if (course->total_students == 1) 
  {
    // Allocate a new array with size of 1 student if there are no students stored in the course 
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    // Reallocate the memory for the array of students to allow space for one more student
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  // Store the new student at the back of the students array
  course->students[course->total_students - 1] = *student;
}

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
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  // Loop through each student and print out the students summary
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
 * Get the top student of the course
 * 
 * @param course The course you want to get the top student of
 * @return Student* The top student of this course
*/
Student* top_student(Course* course)
{
  // If there are no students you can't possibly find a top student so return NULL
  if (course->total_students == 0) return NULL;
  
  // student_average represents the average of the current student in the loop below
  double student_average = 0;
  // max_average represents the current maximum average seen while looping through all the students
  double max_average = average(&course->students[0]);
  // student represents the current student with the highest average
  Student *student = &course->students[0];
 
  // Loop through each student and check if the current students average is greater than the max average
  // If it is greater than the max average, update the max average to be the current students average and 
  // update the student to be the current student in the loop
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  // Return the student with the max average
  return student;
}

/**
 * Get the students passing a specific course and the total number students passing
 * 
 * @param course The course you want to check
 * @param total_passing The variable you want to store the number of passing students in
 * @return Student* An array of all the passing students
*/
Student *passing(Course* course, int *total_passing)
{
  // The count variable keeps track of the total number of passing students
  // also used to allocate memory for the array of passing students
  int count = 0;
  Student *passing = NULL;
  
  // Loop through each student and see if the student is passing
  // if passing increase count by 1
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  // Allocate a new array of total number of students passing
  passing = calloc(count, sizeof(Student));

  // j represents the current position in the passing array
  int j = 0;
  // Loop through each student and if they're passing add them to the passing array
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      // After adding a student to the pasing array we need to increment our current position in the array
      // if we don't then students will keep getting overwritten
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}