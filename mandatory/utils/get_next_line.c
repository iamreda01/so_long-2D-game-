/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:32:05 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/13 13:16:26 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nline(char *data)
{
	int	i;

	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (data[i] == '\n')
		i++;
	return (i);
}

char	*update_line(char *data)
{
	int		i;
	int		s;
	char	*update;

	s = 0;
	i = nline(data);
	if (!data[i])
		return (free(data), NULL);
	update = ft_calloc((ft_strlen(data) - i) + 1, sizeof(char));
	while (data[i])
		update[s++] = data[i++];
	free(data);
	return (update);
}

char	*extract_line(char *data)
{
	char	*line;
	int		i;

	i = nline(data);
	line = ft_calloc(i + 1, sizeof(char));
	ft_memcpy(line, data, i);
	return (line);
}

char	*read_fd(int fd, char *data)
{
	ssize_t		byte;
	char		*tmp;

	if (!data)
		data = ft_calloc(1, 1);
	tmp = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	byte = 1;
	while (byte > 0 && !ft_strchr(tmp, '\n'))
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte < 0)
		{
			free(data);
			free(tmp);
			return (NULL);
		}
		tmp[byte] = '\0';
		data = ft_strjoin(data, tmp);
	}
	free(tmp);
	tmp = NULL;
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	data = read_fd(fd, data);
	if (!data)
		return (NULL);
	if (nline(data) == 0)
	{
		free(data);
		data = NULL;
		return (NULL);
	}
	line = extract_line(data);
	data = update_line(data);
	return (line);
}
