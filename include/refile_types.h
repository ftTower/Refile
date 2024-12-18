#ifndef REFILE_TYPE_H
# define REFILE_TYPE_H

typedef enum e_display_lvl{
	DISPLAY_LIGHT,
	DISPLAY_MEDIUM,
	DISPLAY_FULL,
}	t_display_lvl;

typedef struct s_vector_content {
	char		**lines;
	size_t		size;
	size_t		capacity;
	size_t		max_capacity;
}	t_vector_content;

typedef	struct s_file {
	char 	*name; 
	t_vector_content *content;

	char 	*path;
	int		permissions;
	int 	fd;
	bool	is_open;
	
	time_t 	creation_time;
	time_t 	modification_time;
	size_t 	size;

}	t_file;

#endif