#include <stdio.h>
#include <stdlib.h>
#include "insertOptions.h"
#include "archiveFunctions.h"

struct Queue{
	struct element *start;
	struct element *end;
	int size;
};

struct element{
	char operation [100];
	struct element *next;
};

int main(void)
{
	int option;
	struct Queue *queue;

    	queue = malloc(sizeof(struct Queue));

	while (option != 6) {

		printf("\n\n#===========MENU==========#");
		printf("\n  1 - Inserir Curso       ");
		printf("\n  2 - Inserir Professor   ");
		printf("\n  3 - Inserir Disciplina  ");
		printf("\n  4 - Inserir Turma       ");
		printf("\n  5 - Inserir Aluno       ");
		printf("\n  6 - Sair                ");
    		printf("\n  Option: ");
		scanf("%d", &option);

		while (option < 1 || option > 6) {
			printf("\n  Error - Opção Invalida");
			printf("\n  Opção: ");
			scanf(" %d", &option);
        	}
		printf("#=========================#");
		
		if (option == 1) {
			insertCourse(queue);
		} else if (option == 2) {
			//insertProfessor()
		} else if (option == 3) {
			//insertDisciplina()
		} else if (option == 4) {
			//insertTurma()
		} else if (option == 2) {
			//insertAluno()
		}
	}

	creatAdminArchive(queue);
}