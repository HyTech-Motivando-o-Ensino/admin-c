#include "queueFunctions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void insertCourse(struct Queue *queue)
{
        char name[10];
        char timeCourseAmount[2];
        char type[2];

        printf("\n\n#=============Inserir Curso============#");
        printf("\n  Qual o nome do curso? ");
        scanf(" %s", name);
        printf("  Quantos periodos tem o curso? ");
        scanf(" %s", timeCourseAmount);
        printf("  Qual o tipo?");
        printf("\n  1 - Graduação");
        printf("\n  2 - Mestrado");
        printf("\n  3 - Doutorado");
        printf("\n  4 - Extensão");
        printf("\n  Opção: ");
        scanf(" %s", type);
        while (atoi(type) < 1 || atoi(type) > 4) {
                printf("\n  Error - Opção Invalida");
                printf("\n  Opção: ");
                scanf(" %s", type);
        }
        printf("#======================================#");
        

        char operation[100];
        strcpy(operation, "INSERT INTO CURSOS (name,timeCourseAmount,type) VALUES (");
        strcat(operation, "\"");
        strcat(operation, name);
        strcat(operation, "\"");
        strcat(operation, ",");
        strcat(operation, "\"");
        strcat(operation, timeCourseAmount);
        strcat(operation, "\"");
        strcat(operation, ",");
        strcat(operation, "\"");
        strcat(operation, type);
        strcat(operation, "\"");
        strcat(operation, ")");

        insert(queue, operation);
}