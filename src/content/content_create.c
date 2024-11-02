#include "../include/refile.h"

t_vector_content *get_vector_content(int fd)
{
	t_vector_content *vector = create_vector_content(1, 20000);
	if (!vector)
		return (NULL);
	char *buf;

	buf = get_next_line(fd);
	if (!buf || add_line_to_vector(vector, buf))
		return (free_vector_content(vector), NULL);
	while(buf)
	{
		free(buf);
		buf = get_next_line(fd);
		if (add_line_to_vector(vector, buf))
			return (free(buf), vector);
	}
	return (free(buf), vector);
}

t_vector_content *create_vector_content(size_t initial_capacity, size_t max_capacity)
{
	t_vector_content *vector = malloc(sizeof(t_vector_content));
	if (!vector)
		return (free_vector_content(vector), NULL);
	vector->lines = malloc(initial_capacity * sizeof(char *));
	if (!vector->lines)
		return (free_vector_content(vector), NULL);
	vector->size = 0;
	vector->capacity = initial_capacity;
	vector->max_capacity = max_capacity;
	return (vector);
}

bool	add_line_to_vector(t_vector_content *vector, const char *line)
{
	if (!vector || !line)
		return (true);
	if (vector->size >= vector->capacity)
	{
		if (vector->capacity >= vector->max_capacity)
			return (printf("Vector content is full !\n"),true);
		char **new_lines = realloc(vector->lines, (vector->capacity * 2) * sizeof(char *));
		if (!new_lines) return (true);
		vector->lines = new_lines;
		vector->capacity = (vector->capacity * 2);
	}
	vector->lines[vector->size] = strdup(line);
	if (!vector->lines[vector->size]) return (true);
	return (vector->size++, false);
}

void	print_vector_content(t_vector_content vector)
{
	for (size_t i = 0; i < vector.size; i++)
		printf("line %zu: %s\n", i + 1, vector.lines[i]);
}

void	free_vector_content(t_vector_content *vector)
{
	if (vector && vector->lines) {
		for(size_t i = 0; i < vector->size; i++)
			free(vector->lines[i]);
		free(vector->lines);

	}
	if (vector)
		free(vector);
}