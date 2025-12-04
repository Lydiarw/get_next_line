/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:22:48 by si-wong           #+#    #+#             */
/*   Updated: 2025/12/04 11:22:49 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (!res)
		res = ft_calloc(1, sizeof(char));
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		res = ft_strljoin(res, buffer, bytes_read);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_line(char *buffer)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
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
	size_t	i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	i++; /* skip newline */
	res = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer[fd], 0) < 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	res = get_line(buffer[fd]);
	buffer[fd] = following_line(buffer[fd]);
	return (res);
}

// int	main(void)
// {
// 	int	fd;
// 	int	fd1;
// 	int	fd2;

// 	fd = open("text.txt", O_RDONLY);
// 	fd1 = open("meow.txt", O_RDONLY);
// 	fd2 = open("woof.txt", O_RDONLY);
// 	printf("%s", get_next_line_bonus(fd));
// 	printf("%s", get_next_line_bonus(fd1));
// 	printf("%s", get_next_line_bonus(fd2));
// 	printf("%s", get_next_line_bonus(fd1));
// 	printf("%s", get_next_line_bonus(fd));
// 	printf("%s", get_next_line_bonus(fd2));
// 	printf("%s", get_next_line_bonus(fd2));
// 	printf("%s", get_next_line_bonus(fd));
// 	printf("%s", get_next_line_bonus(fd1));
// 	printf("%s", get_next_line_bonus(fd));
// 	printf("%s", get_next_line_bonus(fd));
// 	printf("%s", get_next_line_bonus(fd1));
// 	printf("%s", get_next_line_bonus(fd1));
// 	close(fd);
// }

// int	main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	// int fd1 = open("meow.txt", O_RDONLY);
// 	// int fd2 = open("woof.txt", O_RDONLY);
// 	printf("1ST: %s", get_next_line(fd));
// 	printf("2ND: %s", get_next_line(fd));
// 	printf("3RD: %s", get_next_line(fd));
// 	printf("4TH: %s", get_next_line(fd));
// 	printf("5TH: %s", get_next_line(fd));
// printf("\n---------------\n");
// printf("1ST: %s", get_next_line(fd1));
// printf("2ND: %s", get_next_line(fd1));
// printf("3RD: %s", get_next_line(fd1));
// printf("4TH: %s", get_next_line(fd1));
// printf("5TH: %s", get_next_line(fd1));
// printf("\n---------------\n");
// printf("1ST: %s", get_next_line(fd2));
// printf("2ND: %s", get_next_line(fd2));
// printf("3RD: %s", get_next_line(fd2));
// printf("4TH: %s", get_next_line(fd2));
// printf("5TH: %s", get_next_line(fd2));
// 	close(fd);
// }