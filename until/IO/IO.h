#ifndef __IO_H
#define __IO_H

int     io_init(char *filename);
off64_t io_seekend(int fd);
ssize_t io_write(int fd, void *buffer, size_t offset, size_t size);
ssize_t io_read(int fd, void *buffer, size_t offset, size_t size);
void    io_close(int fd);

#endif