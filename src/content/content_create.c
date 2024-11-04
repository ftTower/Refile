#include "../include/refile.h"

t_vector_content *get_vector_content(int fd)
{
    t_vector_content *vector = create_vector_content(1, 20000);
    if (!vector)
        return (NULL);

    char *buf = NULL;
    while ((buf = get_next_line(fd)) != NULL)
    {
        if (add_line_to_vector(vector, buf)) {
            free(buf);
            free_vector_content(vector);
            return NULL;
        }
        free(buf);
    }
    return vector;
}

t_vector_content *create_vector_content(size_t initial_capacity, size_t max_capacity)
{
    t_vector_content *vector = malloc(sizeof(t_vector_content));
    if (!vector)
        return (NULL);

    vector->lines = malloc(initial_capacity * sizeof(char *));
    if (!vector->lines) {
        free(vector);
        return (NULL);
    }

    vector->size = 0;
    vector->capacity = initial_capacity;
    vector->max_capacity = max_capacity;
    return vector;
}

bool add_line_to_vector(t_vector_content *vector, const char *line)
{
    if (!vector || !line)
        return true;
    if (vector->size >= vector->capacity)
    {
        size_t new_capacity = vector->capacity * 2;
        if (new_capacity > vector->max_capacity)
            new_capacity = vector->max_capacity;

        char **new_lines = realloc(vector->lines, new_capacity * sizeof(char *));
        if (!new_lines)
            return true;

        vector->lines = new_lines;
        vector->capacity = new_capacity;
    }
    vector->lines[vector->size] = strdup(line);
    if (!vector->lines[vector->size])
        return true;

    vector->size++;
    return false;
}

void	print_vector_content(t_vector_content vector)
{
	for (size_t i = 0; i < vector.size; i++)
		printf("line %zu: %s\n", i + 1, vector.lines[i]);
}

void free_vector_content(t_vector_content *vector)
{
    if (vector) {
        if (vector->lines) {
            for (size_t i = 0; i < vector->size; i++) {
                if (vector->lines[i])
                    free(vector->lines[i]);
            }
            free(vector->lines);
        }
        free(vector);
    }
}