#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "grade_school.h"


roster_t roster ={0};

void init_roster(roster_t *roster) {
    roster->count = 0;
}

bool add_student_no_sort (roster_t *roster, char* name, int grade) {
    for(size_t i = 0; i < roster->count; i++) {
        student_t current_student = roster->students[i];
        if (!strcmp(current_student.name, name)) {
            // printf("Student %s found\n", name);
            return false;
        }
    }

    // printf("Done checking for repeated students\n");
    student_t student;
    student.grade = grade;
    strcpy(student.name, name);
    
    roster->students[roster->count] = student;
    roster->count++;

    // printf("Student added");

    return true;
}

bool add_student (roster_t *roster, char* name, int grade) {
    bool add_student_result = add_student_no_sort(roster, name, grade);

    if(!add_student_result) return false;

    roster_t sorted_roster;
    init_roster(&sorted_roster);
    for (size_t i = 1; i < 13; i++) {
        roster_t grade_roster = get_grade(roster, i);
        for (size_t j = 0; j < grade_roster.count; j++) {

            bool done = true;

            do
            {
                done = true;

                for (size_t k = 0; k + 1 < grade_roster.count; k++)
                {
                    int cmpResult = strcmp(grade_roster.students[k].name, grade_roster.students[k + 1].name);
                    // printf("%s - %s - %i\n", grade_roster.students[k].name, grade_roster.students[k + 1].name, cmpResult);

                    if (cmpResult > 0)
                    {
                        // printf("Switch %s and %s\n", grade_roster.students[k].name, grade_roster.students[k + 1].name);
                        student_t tmp = grade_roster.students[k];
                        grade_roster.students[k] = grade_roster.students[k + 1];
                        grade_roster.students[k + 1] = tmp;
                        done = false;
                    }
                }
            } while (!done);

            student_t student = grade_roster.students[j];
            // printf("Adding %s to grade %i\n", student.name, student.grade);
            add_student_no_sort(&sorted_roster, student.name, student.grade);
        }
    }

    *roster = sorted_roster;

    return true;
}

roster_t get_grade (roster_t *roster, int desired_grade) {
    roster_t new_roster = {0};
    for(size_t i = 0; i < roster->count; i++) {
        if (roster->students[i].grade == desired_grade) {
            new_roster.students[new_roster.count] = roster->students[i];
            new_roster.count++;
        }
    }
    return new_roster;
}