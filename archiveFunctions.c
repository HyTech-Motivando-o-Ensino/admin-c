#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queueFunctions.h"

struct Queue{
	struct element *start;
	struct element *end;
	int size;
};

struct element{
	char operation [200];
	struct element *next;
};

void creatAdminArchive(struct Queue *queue)
{
        FILE *archiveAdmin;
        char text[200];
        archiveAdmin = fopen("adminArchive.sql", "a");

        while (queue->start != NULL) {
                strcpy(text,pop(queue));
                fprintf(archiveAdmin, "%s\n", text);
        }

        fclose(archiveAdmin);

        printf("\n=====Arquivo Criado Com Sucesso=====");
        printf("\n=======Nome: adminArchive.sql=======");
}