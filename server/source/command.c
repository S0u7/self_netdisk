#include "command.h"

#define QUERY_LEN 128

int self_ls(int fatherId, MYSQL *dbConnect)
{
    char query[QUERY_LEN] = {0};
    sprintf(query, "select file_name from file where father_id = %d", fatherId);
    char **result = NULL;
    int num = database_operate(dbConnect, query, &result);
    // printf("num = %d\n",num);
    for (int i = 0; i < num; i++)
    {
        printf("%s", result[i]);
        if (i < num - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

int self_pwd(int id, char **curPath, MYSQL *dbConnect)
{
    char query[QUERY_LEN] = {0};
    sprintf(query, "select file_name from file where id = %d", id);
    char **result = NULL;
    int num = database_operate(dbConnect, query, &result);
    return 0;
}