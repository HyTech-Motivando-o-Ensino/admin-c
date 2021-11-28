#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void creatAdminArchive(char *text)
{
        FILE *archiveAdmin;
        archiveAdmin = fopen("adminArchive.sql", "w");

        fprintf(archiveAdmin, "%s\n", text);

        fclose(archiveAdmin);
}