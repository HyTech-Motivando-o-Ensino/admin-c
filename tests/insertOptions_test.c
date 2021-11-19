#include "Unity/unity.h"
#include "testFunctions/insertOptions.h"
#include "string.h"

//EXECUTADA ANTES DE TODOS OS TESTES
void setUp(){}

//EXECUTADA DEPOIS DE TODOS OS TESTES
void tearDown(){}

//TESTS
char operation_test[200];

void test_insertCourse()
{

        
        //TEST 1
        insertCourse("Ciencia da Computacao", "8", "1", operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `courses` (`id`,`name`,`periods`,`type`) VALUES (NULL,'Ciencia da Computacao','8','1');", operation_test);

        //TEST 2
        insertCourse("Desing", "8", "1", operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `courses` (`id`,`name`,`periods`,`type`) VALUES (NULL,'Desing','8','1');", operation_test);
}

void test_insertClass()
{
        //TEST 1
        insertClass("1","2","https://cesar.zoom.us/j/72922457322",operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `class` (`id`,`course_id`,`period`,`zoom_id`) VALUES (NULL,'1','2','https://cesar.zoom.us/j/72922457322');", operation_test);

        //TEST 2
        insertClass("2","2","https://cesar.zoom.us/j/23452457322",operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `class` (`id`,`course_id`,`period`,`zoom_id`) VALUES (NULL,'2','2','https://cesar.zoom.us/j/23452457322');", operation_test);
}

//void test_insertClassroomCode(){};
//void test_insertProfCourse(){};
//void test_insertProfessor(){};
//void test_insertProfSubject(){};
//void test_insertSubject(){};
//void test_insertProfPeriods(){};

int main(void) {
        UNITY_BEGIN();
        RUN_TEST(test_insertCourse);
        RUN_TEST(test_insertClass);
        return UNITY_END();
}