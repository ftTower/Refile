#ifndef REFILE_H
# define REFILE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <time.h>

#include "./refile_types.h"

t_vector_content *create_vector_content(size_t initial_capacity);
bool			add_line_to_vector(t_vector_content *vector, const char *line);
void	print_vector_content(t_vector_content vector);
void	free_vector_content(t_vector_content *vector);

void	file_print_name(t_file file);
void	file_print_content(t_file file);
void	print_file(t_file file);

# endif