/**
 * @file student.c
 * @author Ameer Hamoodi (hamoodia@mcmaster.ca)
 * @brief Library with student helper functions
 * @date 2022-04-09
 *  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * Add a grade to the students grades array
 * 
 * @param student A student struct 
 * @param grade The grade you want to add to the students grade array
 * @return nothing
 */
void add_grade(Student* student, double grade)
{
  // Increase the total number of grades the student has
  student->num_grades++;
  // If the student originally had no grades, allocate memory for a new array of doubles to represent the students grades
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else 
  {
    // Resize the grades array to allow an additional entry
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  // Store the grade at the end of the array
  student->grades[student->num_grades - 1] = grade;
}

/**
 * Calculate the average grade based on all of the students grades
 * 
 * @param student The student whose grades you want to find the average of 
 * @return double The mean grade of the students grades
 */
double average(Student* student)
{
  // Cannot divide the total grades by 0, so exit
  if (student->num_grades == 0) return 0;

  double total = 0;
  // loop through each of the students grades and add it to the total grade value
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  // return the mean grade by dividing the total grade by the number of grades the student has
  return total / ((double) student->num_grades);
}

/**
 * Prints a summary of the student including:
 * - Name
 * - ID
 * - Grades
 * - Average
 * 
 * @param student The student you want to print
 * @return nothing
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  // Loop through each of the students grades and print them, allowing only 2 decimal places
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
 * Generates a random student from a list of random first and last names
 * Also creates a certain number of random grades with minimum being 25% and maximum being 100%
 * 
 * @param grades The number of grades you want to randomly generate
 * @return Student* The randomly generated student
 */
Student* generate_random_student(int grades)
{
  // List of possible first names
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  // List of possible last names
  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student));

  // Randomly assign a first name and last name to the new student from the list of possible first and last names
  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  // The id is 11 characters long, so we loop 10 times and each time assign the current index a random number casted as a char
  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  // End requires a \0 to indicate the end of the string
  new_student->id[10] = '\0';

  // Add "grades" number of random grades to the student, min grade: 25 max grade: 100
  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  // Return the newly constructed and processed student
  return new_student;
}