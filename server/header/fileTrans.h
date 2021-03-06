#ifndef __FILETRANS_H__
#define __FILETRANS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "CHECK.h"

#define SQL_NOT_HAVE_FILE -2
#define CLIENT_DISCONNECTION -3

int user_download(MYSQL *db_connect, int clientfd, int father_id, const char *filename, off_t file_offset);
int user_upload(MYSQL *db_connect, int clientfd, int father_id, const char *filename, const char *md5, off_t filesize, int user_id);
int get_file_size(const char *fileName, off_t fileOffset, int *clientFd, struct stat *fileStat);

#endif