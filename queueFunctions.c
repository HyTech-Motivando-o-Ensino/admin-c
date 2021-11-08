#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Queue{
	struct element *start;
	struct element *end;
	int size;
};

struct element{
	char operation [100];
	struct element *next;
};

void insert(struct Queue *queue, char *operation)
{

	struct element *new;
	new = malloc(sizeof(struct element));

	new->next = NULL;
	strcpy(new->operation,operation);

	if (queue->start == NULL) {
		queue->end = new;
		queue->start = new;
		queue->size = queue->size + 1;
	} else {
		queue->end->next = new;
		queue->end = new;
		queue->size = queue->size + 1;
	}
}

char *pop(struct Queue *queue)
{
	struct element *out;
	char info[100];

	if (queue->start == NULL) {
		queue->end = NULL;
	}

	out = queue->start;
	queue->start = out->next;
	queue->size = queue->size - 1;

	strcpy(info, out->operation);
	free(out);
	return info;
}