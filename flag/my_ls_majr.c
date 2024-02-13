/*
** EPITECH PROJECT, 2023
** my_ls_rmaj
** File description:
** my_ls_rmaj
*/

#include "../includes/my.h"


void printfirstdirectory(char *path)
{
    char *path_str = path;
    DIR *dir = opendir(path_str);

    my_putstr(path);
    my_putchar(':');
    my_putchar('\n');
    my_ls(path_str);
    my_putchar('\n');
    my_putchar('\n');
}

int countdir(char *path)
{
    char *path_str = path;
    DIR *dir = opendir(path_str);
    struct dirent *entry;
    int count = 0;

    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.' && entry->d_type == DT_DIR) {
            count++;
        }
    }
    closedir(dir);
    return count;
}

void printfile(char *path, char *entryName, int *lastDir)
{
    char subdir_path[256];

    my_strcpy(subdir_path, path);
    my_strcat(subdir_path, "/");
    my_strcat(subdir_path, entryName);
    my_putstr("./");
    write(1, entryName, my_strlen(entryName));
    my_putchar(':');
    my_putchar('\n');
    my_ls(subdir_path);
    my_putchar('\n');
    if (subdir_path != NULL) {
        (*lastDir)++;
        my_ls_majr(subdir_path);
    }
    if (*lastDir < countdir(path)) {
        my_putchar('\n');
    }
}

void my_ls_majr(char *path)
{
    char *path_str = path;
    DIR *dir = opendir(path_str);
    struct dirent *entry;
    int last_dir = 0;

    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.' && entry->d_type == DT_DIR) {
            printfile(path_str, entry->d_name, &last_dir);
        }
    }
    closedir(dir);
}
