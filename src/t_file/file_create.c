#include "../include/refile.h"

t_file *create_file(void)
{
	t_file *file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = NULL;
	file->content = NULL;
	file->path = NULL;
	file->permissions = -1;
	file->fd = -1;
	file->is_open = false;
	file->creation_time = -1;
	file->modification_time = -1;
	file->size = 0;
	return (file);
}

int		open_file(char *path, int permissions)
{
	int	fd = open(path, permissions);
	if (fd == -1) {
		perror("Failed to open file");
		switch (errno)
		{
			case EACCES:
				printf("Error : Permission denied\n");
				break;
			case ENOENT:
				printf("Error : File doesn't exist\n");
				break;
		
			default:
				printf("Error Unknow\n");
		}
	}
	return (fd);
}

void	free_tab(char **buf)
{
	if (!buf)
		return ;
	for(size_t i = 0; buf[i]; i++)
		free(buf[i]);
	free(buf);
}

char   *get_name(char *path)
{
	char **buf = ft_split(path, "/");
	if (!buf || !*buf)
		return (free_tab(buf), NULL);
	ssize_t i = 0;
	while (buf[++i])
		;
	char *ret = ft_strdup(buf[--i]);
	return (free_tab(buf),  ret);
}

t_file *get_file(char *path, int permissions)
{
	t_file *file = create_file();
	if (!file || !path)
		return (free(file), NULL);
	file->fd = open_file(path, permissions);
	if (file->fd == -1)
		return (free(file), NULL);
	file->is_open = true;
	file->name = get_name(path);
	file->path = ft_strdup(path);
	file->content = get_vector_content(file->fd);

	file->permissions = permissions;
	//file->creation = 
	//file->modification_time = 
	//file->size = 
	return (file);
}

void	free_file(t_file *file)
{
	if (file){
		if (file->is_open)
			close(file->fd);
		free_vector_content(file->content);
		free(file->name);
		free(file->path);
		free(file);
	}
}
