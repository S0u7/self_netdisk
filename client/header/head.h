#ifndef __HEAD_H__
#define __HEAD_H__

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

#define ERROR_CHECK(ret, num, msg) \
    {                              \
        if (ret == num)            \
        {                          \
            perror(msg);           \
            return -1;             \
        }                          \
    }

#endif