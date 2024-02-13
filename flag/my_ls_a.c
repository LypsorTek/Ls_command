/*
** EPITECH PROJECT, 2023
** my_ls_a
** File description:
** my_ls_a
*/

#include "../includes/my.h"

void my_ls_a(char *path)
{
    struct dirent *entry;
    char *path_str = path;
    DIR *dir = opendir(path_str);

    if (dir == NULL) {
        write(1, "cannot open directory\n", 23);
        exit(1);
    }
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        write(1, entry->d_name, my_strlen(entry->d_name));
        my_putchar(' ');
    }
    closedir(dir);
}
