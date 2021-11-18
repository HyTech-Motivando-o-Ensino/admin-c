#include "Unity/unity.h"
#include "testFunctions/insertOptions.h"
#include "string.h"

//EXECUTADA ANTES DE TODOS OS TESTES
void setUp(){}

//EXECUTADA DEPOIS DE TODOS OS TESTES
void tearDown(){}

//TEST
void test_insertCourse(){

        char operation_test[200];
        //TEST 1
        insertCourse("Ciencia da Computacao", "8", "1", operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `courses` (`id`,`name`,`periods`,`type`) VALUES (NULL,'Ciencia da Computacao','8','1');", operation_test);

        //TEST 2
        insertCourse("Desing", "8", "1", operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `courses` (`id`,`name`,`periods`,`type`) VALUES (NULL,'Desing','8','1');", operation_test);
}

int main(void) {
        UNITY_BEGIN();
        RUN_TEST(test_insertCourse);
        return UNITY_END();
}