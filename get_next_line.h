#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

size_t	ft_strlen(const char *str);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strljoin(char *dest, char *src, int len);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*read_file(int fd, char *res);
char	*get_line(char *buffer);
char	*following_line(char *buffer);
char	*get_next_line(int fd);

#endif