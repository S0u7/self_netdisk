#include "head.h"

int gets_file(int sockfd, const char *filename)
{
    int fileFd = open(filename, O_RDWR | O_CREAT, 0666);
    ERROR_CHECK(fileFd, -1, "client open file");

    off_t fileSize = 0;
    recv(sockfd, &fileSize, sizeof(off_t), 0);
    printf("filesize = %ld\n", fileSize);

    char gets_buf[4096] = {0};
    off_t recvLen = 0;

    int ret;

    while (recvLen < fileSize)
    {
        memset(gets_buf, 0, 4096);

        ret = recv(sockfd, gets_buf, sizeof(gets_buf), 0);
        ERROR_CHECK(ret, -1, "client recv file");

        ret = write(fileFd, gets_buf, ret);
        ERROR_CHECK(ret, -1, "client write file");

        recvLen += ret;
    }
    close(fileFd);
    return 0;
}

int puts_file(int sockfd, const char *filename)
{
    int fileFd = open(filename, O_RDWR | O_CREAT, 0666);
    ERROR_CHECK(fileFd, -1, "client open file");

    struct stat fileStat;
    memset(&fileStat, 0, sizeof(fileStat));
    fstat(fileFd, &fileStat);

    off_t fileSize = 0;
    recv(sockfd, &fileSize, sizeof(off_t), 0);
    printf("server filesize = %ld\n", fileSize);

    // lseek(fileFd, fileSize, SEEK_SET);

    // char puts_buf[4096] = {0};
    // off_t recvLen = 0;
    off_t needLen = fileStat.st_size - fileSize;
    printf("need len = %ld\n", needLen);

    // int ret;

    // while (recvLen < needLen)
    // {
    //     memset(puts_buf, 0, 4096);

    //     ret = read(fileFd, puts_buf, 4096);

    //     ret = send(sockfd, puts_buf, ret, MSG_WAITALL);

    //     recvLen += ret;
    // }

    sendfile(sockfd, fileFd, &fileSize, needLen);

    close(fileFd);
    return 0;
}

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(sockfd, -1, "socket");

    int udp_fd = socket(AF_INET, SOCK_DGRAM, 0);
    ERROR_CHECK(udp_fd, -1, "socket udp");

    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr("192.168.23.128");
    serAddr.sin_port = htons(2000);

    int ret = connect(sockfd, (struct sockaddr *)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "connect");

    //下载小文件
    // gets_file(sockfd, "picture.png");
    // printf("1111111\n");

    // 下载大文件
    gets_file(sockfd, "string.avi");
    printf("22222222\n");

    // //上传新文件
    // puts_file(sockfd, "user2_picture.png");
    // printf("33333333\n");

    // sleep(3);
    // //上传非完整的已存在的文件
    // puts_file(sockfd, "file1_user2");
    // printf("44444444\n");

    close(sockfd);
    return 0;
}