#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "queueFunctions.h"

void insertCourse(struct Queue *queue)
{
        char name[255];
        char timeCourseAmount[3];
        char type[3];

        printf("\n\n#=============Inserir Curso============#");
        printf("\n  Qual o nome do curso? ");
        scanf(" %[^\n]", name);
        printf("  Quantos periodos tem o curso? ");
        scanf(" %s", timeCourseAmount);
        printf("  Qual o tipo?");
        printf("\n  1 - Graduacao");
        printf("\n  2 - Mestrado");
        printf("\n  3 - Doutorado");
        printf("\n  4 - Extensao");
        printf("\n  Opcao: ");
        scanf(" %s", type);
        while (atoi(type) < 1 || atoi(type) > 4) {
                printf("\n  Error - Opcao Invalida");
                printf("\n  Opcao: ");
                scanf(" %s", type);
        }
        printf("#======================================#");
        

        char operation[200];
        strcpy(operation, "INSERT INTO `courses` (`id`,`name`,`periods`,`type`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, name);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, timeCourseAmount);
        strcat(operation, ",");
        strcat(operation, type);
        strcat(operation, ")");
        strcat(operation, ";");
        
        insert(queue, operation);
}


void insertClass(struct Queue *queue)
{
        char courseId[10];
        char period[3];
        char link[255];

        printf("\n\n#=============Inserir Turma============#");
        printf("\n  Qual o id do curso? ");
        scanf("%s", courseId);
        printf("  Qual o periodo da turma? ");
        scanf("%s", period);
        printf("  Qual o link do zoom da turma? ");
        scanf("%s", link);
        printf("#======================================#");
        

        char operation[200];
        strcpy(operation, "INSERT INTO `class` (`id`,`course_id`,`period`,`zoom_id`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, courseId);
        strcat(operation, ",");
        strcat(operation, period);
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, link);
        strcat(operation, "\'");
        strcat(operation, ")");
        strcat(operation, ";");

        insert(queue, operation);
}

void insertProfessor(struct Queue *queue)
{
        //id, name, slack, email, whatsapp, favoriteContact

        char slack[255], name[255], email[255], whatsapp[255], favoriteContact[3], professorId[10];
        int  courseAmount, subjectAmount, periodAmount;

        printf("\n\n#=============Inserir Professor============#");
        printf("\n  Nome? ");
        scanf(" %[^\n]", name);
        printf("  Seu id? ");
        scanf("%s", professorId);
        printf("  Slack? ");
        scanf("%s", slack);
        printf("  Email? ");
        scanf("%s", email);
        printf("  Whatsapp? ");
        scanf("%s", whatsapp);
        printf("  Contato favorito? ");
        printf("\n  1 - Slack ");
        printf("\n  2 - Email ");
        printf("\n  3 - Whatsapp ");
        printf("\n  Opcao: ");
        scanf("%s", favoriteContact);
        while (atoi(favoriteContact) < 1 || atoi(favoriteContact) > 3) {
                printf("\n  Error - Opcao Invalida");
                printf("\n  Opcao: ");
                scanf("%s", favoriteContact);
        }

        printf("  Esta em quantos cursos? ");
        scanf("%d", &courseAmount);

        int coursesId[courseAmount];
        for (int i = 1; i <= courseAmount; i++) {
                printf("  Id curso %d: ", i);
                scanf("%d", &coursesId[i-1]);
        }

        printf("  Ensina quantas disciplinas? ");
        scanf("%d", &subjectAmount);

        int subjectsId[subjectAmount];
        for (int i = 1; i <= subjectAmount; i++) {
                printf("  Id disciplina %d: ", i);
                scanf("%d", &subjectsId[i-1]);
        }

        printf("  Ensina em quantos periodos? ");
        scanf("%d", &periodAmount);

        int periods[periodAmount];
        for (int i = 1; i <= periodAmount; i++) {
                printf("  Periodo %d: ", i);
                scanf("%d", &periods[i-1]);
        }
        printf("#==========================================#");

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
        strcat(operation, favoriteContact);
        strcat(operation, ")");
        strcat(operation, ";");

        insert(queue, operation);
        
        //Inserir na tabela que relaciona o professor a algum curso
        for (int i = 0; i < courseAmount; i++) {
                insertProfCourse(queue, coursesId[i], professorId);
        }

        //Inserir na tabela que relaciona o professor as matérias que ele ensina
        for (int i = 0; i < subjectAmount; i++) {
                insertProfSubject(queue, subjectsId[i], professorId);
        }

        //Inserir na tabela que relaciona o professor aos períodos que ele ensina
        for (int i = 0; i < periodAmount; i++) {
                insertProfPeriods(queue, professorId, periods[i]);
        }
}

void insertProfPeriods(struct Queue *queue, char *professorId, int period)
{
        char period_char[3];

        sprintf(period_char,"%d",period);

        char operation[200];
        strcpy(operation, "INSERT INTO `professor_periods` (`id`,`professor_id`,`periods`) VALUES (");
        strcat(operation,"NULL");
        strcat(operation,",");
        strcat(operation,professorId);
        strcat(operation,",");
        strcat(operation,period_char);
        strcat(operation,")");
        strcat(operation,";");

        insert(queue, operation);
}

void insertProfCourse(struct Queue *queue, int courseId, char *professor_id)
{       
        char course_id[10];

        sprintf(course_id, "%d", courseId);

        char operation[200];
        strcpy(operation, "INSERT INTO `professor_course` (`id`,`professor_id`,`course_id`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, professor_id);
        strcat(operation, ",");
        strcat(operation, course_id);
        strcat(operation, ")");
        strcat(operation, ";");

        insert(queue, operation);
}


void insertProfSubject(struct Queue *queue, int subjectId, char *professor_id)
{
        char subject_id[10];

        sprintf(subject_id, "%d", subjectId);

        char operation[200];
        strcpy(operation, "INSERT INTO `professor_class` (`id`,`professor_id`,`subject_id`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, professor_id);
        strcat(operation, ",");
        strcat(operation, subject_id);
        strcat(operation, ")");
        strcat(operation, ";");

        insert(queue, operation);
}

void insertSubject(struct Queue *queue)
{
        //id, name, period

        char name[255];
        char period[3];
        printf("\n\n#=============Inserir Disciplina============#");
        printf("\n  Qual o nome da disciplina? ");
        scanf(" %[^\n]", name);
        printf("  Qual o periodo da disciplina? ");
        scanf("%s", period);
        printf("#===========================================#");

        char operation[200];
        strcpy(operation, "INSERT INTO `subjects` (`id`,`name`,`period`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, name);
        strcat(operation, "\'");
        strcat(operation, ",");
        strcat(operation, period);
        strcat(operation, ")");
        strcat(operation, ";");

        insert(queue, operation);
}


void insertClassroomCode(struct Queue *queue)
{
        //id, subject_id, classId, classroom_id
        char subjectId[255], classId[10], classroomId[255];
        printf("\n\n#=============Inserir Classroom============#");
        printf("\n  Qual o ID da disciplina? ");
        scanf("%s", subjectId);
        printf("  Qual o ID da turma? ");
        scanf("%s", classId);
        printf("  Qual o ID do classroom? ");
        scanf("%s", classroomId);
        printf("#==========================================#");

        char operation[200];
        strcpy(operation, "INSERT INTO `classroom_code` (`id`,`subject_id`,`class_id`,`classroom_id`) VALUES (");
        strcat(operation, "NULL");
        strcat(operation, ",");
        strcat(operation, subjectId);
        strcat(operation, ",");
        strcat(operation, classId);
        strcat(operation, ",");
        strcat(operation, "\'");
        strcat(operation, classroomId);
        strcat(operation, "\'");
        strcat(operation, ")");
        strcat(operation, ";");

        insert(queue, operation);
}