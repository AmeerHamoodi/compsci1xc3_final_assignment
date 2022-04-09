/**
 * @mainpage MATH101 statistics code
 * 
 * Creates the MATH101, enrols a series of random students then prints a summary of the course and prints the top student 
 * along with all the passing students and the total number of passing students
 * 
 * 
 * @file main.c
 * @author Ameer Hamoodi (hamoodia@mcmaster.ca)
 * @brief Creates course and enrols random students into the course, then prints out course stats. 
 * @date 2022-04-09
 * 
 */
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * Creates the MATH101 course with 20 random students and prints the course statistics
 * Course statistics include:
 * - Top student
 * - Total passing
 * - Passing students
 */
int main()
{
  // Seed the random number generator (allows us to use the random number generator)
  srand((unsigned) time(NULL));

  // Create the MATH101 course and assign the following properties: (name -> Basics of Mathematics, code -> MATH 101)
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  // Create and enrol 20 students with 8 grades into the MATH101 course
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  // Store the top student in the student pointer then print them using the print_student function
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  // Calculate the total number of passing students and print all of the passing students
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}