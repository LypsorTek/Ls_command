/*
** EPITECH PROJECT, 2023
** my_ls_R
** File description:
** my_ls_R
*/

#include "../includes/my.h"

int my_ls_r(char *path)
{
    struct dirent *entry;
    char *path_str = path;
    DIR *dir = opendir(path_str);
    char *files[MAX_FILES];
    int i = 0;

    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.') {
            files[i] = entry->d_name;
            i++;
        }
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putstr(files[j]);
        my_putchar(' ');
    }
    closedir(dir);
    return (0);
}
