 /**
  * @file student.h
  * @author Ameer Hamoodi (hamoodia@mcmaster.ca)
  * @brief Define the interfaces for the student library functions and for the struct
  * @date 2022-04-09
  * 
  */

/**
 * Student type with frields, first_name, last_name, id, grades and num_grades
 * 
 */
typedef struct _student 
{ 
  char first_name[50]; /** <the student's first name */
  char last_name[50];/** <the student's last name */
  char id[11];/** <the student's id */
  double *grades; /** <an array of the student's grades */
  int num_grades; /** <the total number of grades */
} Student;

/**
 * Add a grade to the students grades array
 * 
 * @param student A student struct 
 * @param grade The grade you want to add to the students grade array
 * @return nothing
 */
void add_grade(Student *student, double grade);

/**
 * Calculate the average grade based on all of the students grades
 * 
 * @param student The student whose grades you want to find the average of 
 * @return double The mean grade of the students grades
 */
double average(Student *student);

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
void print_student(Student *student);

/**
 * Generates a random student from a list of random first and last names
 * Also creates a certain number of random grades with minimum being 25% and maximum being 100%
 * 
 * @param grades The number of grades you want to randomly generate
 * @return Student* The randomly generated student
 */
Student* generate_random_student(int grades); 
