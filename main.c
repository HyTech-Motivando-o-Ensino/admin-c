#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librarys/insertOptions.h"
#include "librarys/archiveFunction.h"

struct Queue{
	struct element *start;
	struct element *end;
	int size;
};

struct element{
	char operation[200];
	struct element *next;
};

void main(void)
{
	int option;
	struct Queue *queue;

    	queue = malloc(sizeof(struct Queue));
        
        queue->start = NULL;
        queue->end = NULL;

	while (option != 6) {

		printf("\n\n#===========MENU==========#");
		printf("\n  1 - Inserir Curso       ");
		printf("\n  2 - Inserir Disciplina  ");
		printf("\n  3 - Inserir Professor   ");
		printf("\n  4 - Inserir Turma       ");
		printf("\n  5 - Inserir Classroom   ");
		printf("\n  6 - Sair                ");
    		printf("\n  Opcao: ");
		scanf("%d", &option);

		while (option < 1 || option > 6) {
			printf("\n  Error - Opcao Invalida");
			printf("\n  Opcao: ");
			scanf(" %d", &option);
        	}
		printf("#=========================#");
		
		if (option == 1) {
			insertCourse(queue);
		} else if (option == 2) {
			insertSubject(queue);
		} else if (option == 3) {
			insertProfessor(queue);
		} else if (option == 4) {
			insertClass(queue);
		} else if (option == 5) {
			insertClassroomCode(queue);
		}

	}
	
        creatAdminArchive(queue);
}