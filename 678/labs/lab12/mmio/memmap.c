/*
 * Example of using mmap. Taken from Advanced Programming in the Unix
 * Environment by Richard Stevens.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h> /* mmap() is defined in this header */
#include <fcntl.h>
#include <unistd.h>
#include <string.h>  /* memcpy */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void err_quit (const char * mesg)
{
	printf ("%s\n", mesg);
	exit(1);
}

void err_sys (const char * mesg)
{
	perror(mesg);
	exit(errno);
}

int main (int argc, char *argv[])
{
	int fdin, fdout, i;
	char *src, *dst, buf[256];
	struct stat statbuf;

	src = dst = NULL;

	if (argc != 3)
		err_quit ("usage: memmap <fromfile> <tofile>");

	/* 
	 * open the input file 
	 */
	if ((fdin = open (argv[1], O_RDONLY)) < 0) {
		sprintf(buf, "can't open %s for reading", argv[1]);
		perror(buf);
		exit(errno);
	}

	/* 
	 * open/create the output file 
	 */
	if ((fdout = open (argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0) {
		sprintf (buf, "can't create %s for writing", argv[2]);
		perror(buf);
		exit(errno);
	}

	/* 
	 * 1. find size of input file 
	 */
	struct stat stat_buf;
	int size = 0;
	if(fstat(fdin, &stat_buf) == 0)	{
		size = stat_buf.st_size;
	} else {
		printf("Ah crap got an erro with fstat\n");
		exit(1);
	}

	/* 
	 * 2. go to the location corresponding to the last byte 
	 */
	if(lseek(fdout, size - 1, SEEK_SET) == -1) {
		printf("Ah crap got an erro with fstat\n");
		exit(1);
	}

	/* 
	 * 3. write a dummy byte at the last location 
	 */
	if(write(fdout, "a", 1) == -1) {
		printf("Ah crap got an erro with fstat\n");
		exit(1);
	}

	/* 
	 * 4. mmap the input file 
	 */


	/* 
	 * 5. mmap the output file 
	 */

	/* 
	 * 6. copy the input file to the output file 
	 */
	/* Memory can be dereferenced using the * operator in C.  This line
	 * stores what is in the memory location pointed to by src into
	 * the memory location pointed to by dest.
	 */
	*dst = *src;
} 














