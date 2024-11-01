#ifndef CONTENT_H
# define CONTENT_H

t_vector_content 	*create_vector_content(size_t initial_capacity, size_t max_capacity);
bool				add_line_to_vector(t_vector_content *vector, const char *line);
void				print_vector_content(t_vector_content vector);
void				free_vector_content(t_vector_content *vector);
t_vector_content 	*get_vector_content(int fd);


#endif