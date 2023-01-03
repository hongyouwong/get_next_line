#include <unistd.h>
#include <stdlib.h>

size_t	slen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*output;

	i = 0;
	len = slen(s1) + slen(s2);
	output = (char *) malloc (sizeof(char) * len + 1);
	while (*s1)
		output[i++] = *s1++;
	while (*s2)
		output[i++] = *s2++;
	output[i] = '\0';
	return (output);
}

char    *get_next_line(int fd)
{
    static char    buffer[FOPEN_MAX + 1][BUFFER_SIZE + 1];
    char        *line;
    int            i;
    int            j;
    int            flag;

    if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
        return (NULL);
    line = NULL;
    flag = 0;
    while (!flag && (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE) > 0)))
    {
        line = ft_strjoin(line, buffer[fd]);
        i = 0;
        j = 0;
        while (buffer[fd][i])
        {
            if (flag)
                buffer[fd][j++] = buffer[fd][i];
            if (buffer[fd][i] == '\n')
                flag = 1;
            buffer[fd][i++] = 0;
        }
    }
    return (line);
}
