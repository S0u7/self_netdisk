#include "head.h"

int main()
{
    MYSQL *dbConnect = database_connect("11111111", "small_target_100k", "localhost", "root");
    self_ls(1, dbConnect);

    self_ls(5,dbConnect);

    self_ls(6,dbConnect);
    return 0;
}