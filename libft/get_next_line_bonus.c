/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:26:38 by migmarti          #+#    #+#             */
/*   Updated: 2022/11/28 12:25:39 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get(char *line)
{
	size_t	size;
	char	*file;

	size = 0;
	while (line[size] != '\n' && line[size])
		size++;
	if (!line[size])
		return (0);
	file = ft_substr(line, size + 1, ft_strlen(line) - size);
	if (file[0] == '\0')
	{
		free(file);
		file = 0;
	}
	line[size + 1] = '\0';
	return (file);
}

static char	*read_file(int fd, char *buffer, char *file)
{
	int		count;
	char	*temp;

	count = 1;
	while (count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (0);
		if (count == 0)
			break ;
		buffer[count] = '\0';
		if (!file)
			file = ft_strdup("");
		temp = file;
		file = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file[1024];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = read_file(fd, buffer, file[fd]);
	free (buffer);
	if (!line)
	{
		free (file[fd]);
		file[fd] = 0;
		return (file[fd]);
	}
	file[fd] = ft_get(line);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (1)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		if (!line)
			break ;
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
*/
