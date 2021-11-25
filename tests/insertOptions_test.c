#include "Unity/unity.h"
#include "testFunctions/insertOptions.h"
#include "string.h"

//EXECUTADA ANTES DE TODOS OS TESTES
void setUp(){};

//EXECUTADA DEPOIS DE TODOS OS TESTES
void tearDown(){};

//TESTS
char operation_test[200];

void test_insertCourse()
{
        //TEST 1
        insertCourse("Ciencia da Computacao", "8", "1", operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `courses` (`id`,`name`,`periods`,`type`) VALUES (NULL,'Ciencia da Computacao',8,1);", operation_test);

        //TEST 2
        insertCourse("Desing", "8", "1", operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `courses` (`id`,`name`,`periods`,`type`) VALUES (NULL,'Desing',8,1);", operation_test);
}

void test_insertClass()
{
        //TEST 1
        insertClass("1","2","https://cesar.zoom.us/j/72922457322",operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `class` (`id`,`course_id`,`period`,`zoom_id`) VALUES (NULL,1,2,'https://cesar.zoom.us/j/72922457322');", operation_test);

        //TEST 2
        insertClass("2","2","https://cesar.zoom.us/j/23452457322",operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `class` (`id`,`course_id`,`period`,`zoom_id`) VALUES (NULL,2,2,'https://cesar.zoom.us/j/23452457322');", operation_test);
}

void test_insertProfessor()
{
        //TEST 1
        insertProfessor("@FDS", "Ricardo Costa", "ricardo@cesar.school", "81999999999","1","NULL",operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `professor` (`id`,`name`,`slack`,`email`,`whatsapp`,`other`,`favorite`) VALUES (NULL,'Ricardo Costa','@FDS','ricardo@cesar.school','81999999999',NULL,1);",operation_test);
}

void test_insertProfPeriods()
{
        //TEST 1
        insertProfPeriods("1",2,operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `professor_periods` (`id`,`professor_id`,`periods`) VALUES (NULL,1,2);",operation_test);

        //TEST 2
        insertProfPeriods("1",5,operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `professor_periods` (`id`,`professor_id`,`periods`) VALUES (NULL,1,5);",operation_test);
}

void test_insertProfCourse()
{
        //TEST 1
        insertProfCourse(1,"1",operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `professor_course` (`id`,`professor_id`,`course_id`) VALUES (NULL,1,1);",operation_test);
}

void test_insertProfSubject()
{
        //TEST 1
        insertProfSubject(1,"1",operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `professor_class` (`id`,`professor_id`,`subject_id`) VALUES (NULL,1,1);",operation_test);
}

void test_insertSubject()
{
        //TEST 1
        insertSubject("Fundamento de Desenvolvimento de Software","2",operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `subjects` (`id`,`name`,`period`) VALUES (NULL,'Fundamento de Desenvolvimento de Software',2);",operation_test);
}

void test_insertClassroomCode()
{
        //TEST 1
        insertClassroomCode("1","2","FDS#2021",operation_test);
        TEST_ASSERT_EQUAL_STRING("INSERT INTO `classroom_code` (`id`,`subject_id`,`class_id`,`classroom_id`) VALUES (NULL,1,2,'FDS#2021');", operation_test);
}

int main(void) 
{
        UNITY_BEGIN();
        RUN_TEST(test_insertCourse);
        RUN_TEST(test_insertClass);
        RUN_TEST(test_insertProfessor);
        RUN_TEST(test_insertProfPeriods);
        RUN_TEST(test_insertProfCourse);
        RUN_TEST(test_insertProfSubject);
        RUN_TEST(test_insertSubject);
        RUN_TEST(test_insertClassroomCode);
        return UNITY_END();
}