#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t		i;

	if ((count != 0 && count > UINT_MAX / size) || (size != 0 && size > UINT_MAX
			/ count))
		return (NULL);
	res = (char *)malloc(count * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count * size)
		res[i++] = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	char	*res;

	res = (char *)str;
	while (*res)
	{
		if (*res == (unsigned char)c)
			return (res);
		res++;
	}
	if (*res == '\0' && (unsigned char)c == '\0')
		return (res);
	return (NULL);
}

char	*ft_strljoin(char *dest, char *src, int len)
{
	char	*res;
	int		i;
	int		k;

	if (!dest || !src)
		return (NULL);
	res = (char *)ft_calloc((ft_strlen(dest) + ft_strlen(src) + 1),
			sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (dest[i])
	{
		res[i] = dest[i];
		i++;
	}
	while (src[k] && k < len)
		res[i++] = src[k++];
	free(dest);
	return (res);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char *res;
	size_t i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	res = ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while ((i + start) < ft_strlen(s) && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}