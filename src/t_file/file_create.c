#include "../include/refile.h"

t_file *create_file(void)
{
	t_file *file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = " default";
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

t_file *get_file(char *name, char *path, int permissions)
{
	t_file *file = create_file();
	if (!file || !path)
		return (free(file), NULL);
	file->fd = open_file(path, permissions);
	file->is_open = true;
	file->content = get_vector_content(file->fd);
	if (name)
		file->name = name;
	file->path = path;
	file->permissions = permissions;
	//file->creation = 
	//file->modification_time = 
	//file->size = 
	return (file);
}

void	free_file(t_file *file)
{
	if (file){
		free_vector_content(file->content);
		free(file);
	}
}
