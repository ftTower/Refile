#ifndef FILE_H
# define FILE_H

t_file 				*create_file(void);
t_file 				*get_file(char *path, int permissions);
void				free_file(t_file *file);

void				file_print_name(t_file file);
void				file_print_content(t_file file, ssize_t size);
void				file_print_path(t_file file, size_t size);
void				put_load_bar(size_t size, size_t v1, size_t v2);

void				display_file(t_file *file, t_display_lvl level);


#endif