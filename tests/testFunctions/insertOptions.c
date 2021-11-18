#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void insertCourse(char *name, char *timeCourseAmount, char *type, char *operation_test)
{
        
        char operation[200];
        strcpy(operation, "INSERT INTO `courses` (`id`,`name`,`periods`,`type`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, name);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, timeCourseAmount);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, type);
        strcat(operation, "\'");
        strcat(operation, ")");
        strcat(operation, ";");
        
        strcpy(operation_test, operation);
}


char *insertClass(char *courseId, char *period, char *link)
{
        
        char operation[200];
        strcpy(operation, "INSERT INTO `class` (`id`,`course_id`,`period`,`zoom_id`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, courseId);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, period);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, link);
        strcat(operation, "\'");
        strcat(operation, ")");
        strcat(operation, ";");

        return operation;
}


char *insertProfessor(char *slack, char *name, char *email, char *whatsapp, char *favoriteContact, char *professorId)
{

        char operation[200];
        strcpy(operation, "INSERT INTO `professor` (`id`,`name`,`slack`,`email`,`whatsapp`,`contact`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, name);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, slack);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, email);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, whatsapp);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, favoriteContact);
        strcat(operation, "\'");
        strcat(operation, ")");
        strcat(operation, ";");

        return operation;
        
}


char *insertProfCourse(int courseId, char *professor_id)
{       
        char course_id[10];

        sprintf(course_id, "%d", courseId);

        char operation[200];
        strcpy(operation, "INSERT INTO `professor_course` (`id`,`professor_id`,`course_id`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, professor_id);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, course_id);
        strcat(operation, "\'");
        strcat(operation, ")");
        strcat(operation, ";");

        return operation;
}


char *insertProfSubject(int subjectId, char *professor_id)
{
        char subject_id[10];
        sprintf(subject_id, "%d", subjectId);

        char operation[200];
        strcpy(operation, "INSERT INTO `professor_class` (`id`,`professor_id`,`subject_id`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, professor_id);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, subject_id);
        strcat(operation, "\'");
        strcat(operation, ")");
        strcat(operation, ";");

        return operation;
}


char *insertSubject(char *name, char *period)
{

        char operation[200];
        strcpy(operation, "INSERT INTO `subjects` (`id`,`name`,`period`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, name);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, period);
        strcat(operation, "\'");
        strcat(operation, ")");
        strcat(operation, ";");

        return operation;
}


char *insertClassroomCode(char *subjectId, char *classId, char *classroomId)
{

        char operation[200];
        strcpy(operation, "INSERT INTO `classroom_code` (`id`,`subject_id`,`class_id`,`classroom_id`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, subjectId);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, classId);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, classroomId);
        strcat(operation, "\'");
        strcat(operation, ")");
        strcat(operation, ";");

        return operation;
}