#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

MYSQL *database_connect(const char *password, const char *database,const char *server,const char *user);
int database_operate(MYSQL *db_connect, const char *query, char ***result);
void database_close(MYSQL *db_connect);

#endif