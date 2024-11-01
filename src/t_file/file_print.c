#include "../include/refile.h"

// ╔══════╗
// ║      ║
// ╠══════╣
// ║      ║
// ╚══════╝

const char *colors[] = {
    "\033[30m", // Noir
    "\033[31m", // Rouge
    "\033[32m", // Vert
    "\033[33m", // Jaune
    "\033[34m", // Bleu
    "\033[35m", // Magenta
    "\033[36m", // Cyan
    "\033[37m", // Blanc
    "\033[90m", // Gris
    "\033[91m", // Rouge clair
    "\033[92m", // Vert clair
    "\033[93m", // Jaune clair
    "\033[94m", // Bleu clair
    "\033[95m", // Magenta clair
    "\033[96m", // Cyan clair
    "\033[97m", // Blanc clair
    "\033[40m", // Arrière-plan noir
    "\033[41m", // Arrière-plan rouge
    "\033[42m", // Arrière-plan vert
    "\033[43m", // Arrière-plan jaune
    "\033[44m", // Arrière-plan bleu
    "\033[45m", // Arrière-plan magenta
    "\033[46m", // Arrière-plan cyan
    "\033[47m", // Arrière-plan blanc
    "\033[100m", // Arrière-plan gris
    "\033[101m", // Arrière-plan rouge clair
    "\033[102m", // Arrière-plan vert clair
    "\033[103m", // Arrière-plan jaune clair
    "\033[104m", // Arrière-plan bleu clair
    "\033[105m", // Arrière-plan magenta clair
    "\033[106m", // Arrière-plan cyan clair
    "\033[107m", // Arrière-plan blanc clair
    "\033[0m"   // Reset
};

void	file_print_name(t_file file)
{
	printf("📄 %s%s%s",colors[4] ,file.name, colors[32]);
}

void    putstr_line(char *line)
{
    ssize_t i;

    i = -1;
    write(1, "\t> ", 3);
    while(line[++i])
    {
        if (line[i] != '\n')
            write(1, &line[i], 1);
    }
    write(1, "\n", 1);
}

void	file_print_content(t_file file, ssize_t size)
{
    if (file.content == NULL) {
        return ( printf("📁 %scontent is empty%s\n", colors[3], colors[32]), (void)NULL);
    }
    printf("📁 %slines%s", colors[3], colors[32]);
    printf("[%s%zu%s/%s%zu%s]", colors[4], file.content->capacity,colors[32], colors[2], file.content->capacity,colors[32]);
    if (size <= 0)
        return (printf("\n"), (void)NULL);
    if (file.content->lines == NULL) {
        return (printf(" %s lines is NULL%s\n", colors[27], colors[32]), (void)NULL);
    }
    printf("\n");
    for (size_t i = 0; i < file.content->size && i < (size_t)size; i++)
        putstr_line(file.content->lines[i]);
        // printf(" %s %-3zu%s%s%s%s\n", colors[27], i + 1, colors[32], colors[13], file.content->lines[i], colors[32]);
}

void	file_print_path()
{

}

void	file_print_permissions()
{

}

void	file_print_fd()
{

}

void	file_print_is_open()
{

}

void	file_print_creation_time()
{

}

void	file_print_modification_time()
{

}

void	file_print_size()
{

}