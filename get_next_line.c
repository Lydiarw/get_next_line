#include "get_next_line.h"

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		bytes_read;
	char	*dest;

	buffer = ft_calloc(buf_size + 1, sizeof(char));
	dest = ft_calloc(1, sizeof(char));
	if (!buffer || !dest)
		return (NULL);
	if (res)
	{
		dest = ft_strljoin(dest, res, ft_strlen(res));
		res = NULL;
	}
	while (1)
	{
		bytes_read = read(fd, buffer, buf_size);
		if (bytes_read <= 0)
			break ;
        buffer[bytes_read] = '\0';
		dest = ft_strljoin(dest, buffer, bytes_read);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (dest);
}
//if res is empty, just initialize ta shi empty string
//REUSE RES

char	*get_line(char *buffer)
{
	int		i;
	char	*dest;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++; /* to include the newline */
	dest = ft_substr(buffer, 0, i);
	return (dest);
}

char	*following_line(char *buffer)
{
	char	*res;
	int		i;

	if (!buffer)
		return (NULL);
    i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
    i++; /* skip newline */
	res = ft_substr(buffer, i, ft_strlen(buffer) - i);
    free (buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;

    if (fd < 0)
        return (NULL);
	buffer = read_file(fd, buffer);
    if (!buffer)
        return (NULL);
	res = get_line(buffer);
	buffer = following_line(buffer);
	return (res);
}

int	main(void)
{
	int	fd;
	int	count;

	fd = open("text.txt", O_RDONLY);
	printf("1ST: %s", get_next_line(fd));
	printf("2ND: %s", get_next_line(fd));
	printf("3RD: %s", get_next_line(fd));
	close(fd);
}