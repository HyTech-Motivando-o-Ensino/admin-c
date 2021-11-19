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
        archiveAdmin = fopen("adminArchive.sql", "a");

        while (queue->start != NULL) {
                fprintf(archiveAdmin, "%s\n", queue->start->operation);
                pop(queue);
        }

        fclose(archiveAdmin);

        printf("\n\n#=====Arquivo Criado Com Sucesso=====#");
        printf("\n#=======Nome: adminArchive.sql=======#");
}