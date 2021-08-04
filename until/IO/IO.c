#include "IO.h"

#define	_FILE_OFFSET_BITS	64
#define _LARGEFILE_SOURCE
#define _LARGEFILE64_SOURCE

int 
io_init(char *filename){
	int fd = open(filename,
			 O_RDWR | O_LARGEFILE | O_CREAT, 
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

	if(fd <= 0){
		perror("function io_init open file fail.");
		return -1;
	}
		 
	return fd;
}

off64_t 
io_seekend(int fd){
	if(fd <= 0){
		perror("the fd which function io_seekend got invaild");
		return -1;
	}
	
	off64_t seek = lseek64(fd, 0, SEEK_END);
	if(seek <= 0){
		perror("function io_seekend seek fail");
		return -1;
	}
	
	return seek;
}

ssize_t 
io_write(int fd, void *buffer, size_t offset, size_t size){
	if(fd <= 0){
		perror("the fd which function io_write got invaild");
		return -1;
	}
	
	off64_t seek = lseek64(fd, offset, SEEK_SET);
	if(seek <= 0){
		perror("function io_write seek fail");
		return -1;
	}
	
	ssize_t bytes = write(fd, buffer, offset);
	if(bytes == -1){
		perror("function io_write write fail");
		return -1;
	}
	
	return bytes;
}

ssize_t 
io_read(int fd, void *buffer, size_t offset, size_t size){
	if(fd <= 0){
		perror("the fd which function io_read got invaild");
		return -1;
	}
	
	off64_t seek = lseek64(fd, offset, SEEK_SET);
	if(seek <= 0){
		perror("function io_read seek fail");
		return -1;
	}
	
	ssize_t bytes = 0;
	ssize_t temp_bytes = 0;
	size_t toread = size;
	void *temp = buffer;
	
	while(toread > 0){
		temp_bytes = read(fd, temp, size);
		if(temp_bytes == -1){
			perror("read fail in function io_read");
			return -1;
		}else if(temp_bytes == 0){
			return bytes;
		}
		
		bytes += temp_bytes;
		temp += temp_bytes;
		toread -= temp_bytes;
	}
	
	return bytes;
}

void    
io_close(int fd){
	close(fd);
}