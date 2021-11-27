#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
	struct element *start;
	struct element *end;
	int size;
};

struct element{
	char operation[200];
	struct element *next;
};

void insert(struct Queue *queue, char *operation)
{
	struct element *new;
	new = malloc(sizeof(struct element));
	new->next = NULL;
	strcpy(new->operation,operation);

	if (queue->start == NULL) {
                queue->start = new;
		queue->end = new;
		queue->size = queue->size + 1;
	} else {
		queue->end->next = new;
		queue->end = new;
		queue->size = queue->size + 1;
	}
}

void *pop(struct Queue *queue)
{
	struct element *out;

	if (queue->start == NULL) {
		queue->end = NULL;
	}

	out = queue->start;
	queue->start = out->next;
	queue->size = queue->size - 1;

	free(out);
}