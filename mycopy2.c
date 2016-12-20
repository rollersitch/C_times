#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFSIZE 512

main(argc,argv)
int argc;
char *argv[];
{
 int fdr,fdw;
 char buff[BUFSIZE];
 int num;

 if (argc < 3) {
    fprintf(stderr,"Usage : %s file1 file2\n",argv[0]);
    exit(-1);
    }

 if ((fdr = open(argv[1],O_RDONLY | O_BINARY,0)) == -1) {
    perror(argv[1]);
    exit(-1);
    }

 if ((fdw = open(argv[2],O_WRONLY | O_CREAT | O_BINARY, 0777)) == -1) {
    perror(argv[2]);
    exit(-1);
    }

    while ((num = read(fdr,buff,BUFSIZ)) > 0) {
	printf("%d\n",num);
	write(fdw,buff,num);
	}
 close(fdr);
 close(fdw);
}
