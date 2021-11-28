#include "Unity/unity.h"
#include "testFunctions/archiveFunction.h"
#include <stdlib.h>



//EXECUTED BEFOREE ALL TESTS
void setUp()
{
        creatAdminArchive("Test01");  
};


//EXECUTED AFTER ALL TESTS DEPOIS DE TODOS OS TESTES
void tearDown(){};


//TESTS
void test_creatAdminArchive()
{       
        FILE *test_archiveAdmin;
        char archive_text[255];
        test_archiveAdmin = fopen("adminArchive.sql", "r");

        fgets(archive_text,255,test_archiveAdmin);

        fclose(test_archiveAdmin);
        TEST_ASSERT_EQUAL_STRING("Test01\n",archive_text);
}

int main(void) 
{
        UNITY_BEGIN();
        RUN_TEST(test_creatAdminArchive);
        return UNITY_END();
}