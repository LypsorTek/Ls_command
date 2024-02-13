/*
** EPITECH PROJECT, 2023
** my_ls_d
** File description:
** my_ls_d
*/

#include "../includes/my.h"


void my_ls_d(char *path)
{
    struct dirent *entry;
    char *path_str = path;
    DIR *dir = opendir(path_str);

    if (dir == NULL) {
        write(1, "cannot open directory\n", 23);
        exit(1);
    }
    my_putstr(path);
    closedir(dir);
}
