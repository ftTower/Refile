#include "../include/refile.h"

t_vector_content *create_vector_content(size_t initial_capacity)
{
	t_vector_content *vector = malloc(sizeof(t_vector_content));
	if (!vector)
		return (NULL);
	vector->lines = malloc(initial_capacity * sizeof(char *));
	if (!vector->lines)
		return (free(vector), NULL);
	vector->size = 0;
	vector->capacity = initial_capacity;
	return (vector);
}

bool	add_line_to_vector(t_vector_content *vector, const char *line)
{
	if (vector->size >= vector->capacity)
	{
		printf("upgrade capacity to %ld\n", vector->capacity *2);
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
	for(size_t i = 0; i < vector->size; i++)
		free(vector->lines[i]);
	free(vector->lines);
	free(vector);
}