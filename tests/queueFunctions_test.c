#include "Unity/unity.h"
#include "testFunctions/queueFunctions.h"
#include <stdlib.h>
#include <stdio.h>

struct Queue{
	struct element *start;
	struct element *end;
	int size;
};

struct element{
	char operation[200];
	struct element *next;
};

//Struct
struct Queue *queue;

//EXECUTADA ANTES DE TODOS OS TESTES
void setUp(){
	queue = malloc(sizeof(struct Queue));
	queue->start = NULL;
	queue->end = NULL;
	queue->size = 0;
	insert(queue,"test1");
	insert(queue,"test2");
};


//EXECUTADA DEPOIS DE TODOS OS TESTES
void tearDown(){};


//TESTS
void test_amount()
{	
	TEST_ASSERT_EQUAL(2,queue->size);
}

void test_empty()
{
	pop(queue);
	pop(queue);
	TEST_ASSERT_NULL(queue->start);
}

int main(void) 
{
        UNITY_BEGIN();
        RUN_TEST(test_amount);
        RUN_TEST(test_empty);
        return UNITY_END();
}