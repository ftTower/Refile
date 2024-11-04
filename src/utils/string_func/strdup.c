#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *src)
{
    int len = strlen(src);
    char *dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup) return NULL;

    for (int i = 0; i < len; i++)
        dup[i] = src[i];
    return (dup[len] = '\0', dup);
}