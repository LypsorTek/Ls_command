/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_ls
*/


#include "includes/my.h"

int countfiles(char *path)
{
    char *path_str = path;
    DIR *dir = opendir(path_str);
    struct dirent *entry;
    int count = 0;

    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.') {
            count++;
        }
    }
    closedir(dir);
    return count;
}

void print_space_if_not_last(int index, int count)
{
    if (index != count - 1) {
        my_putchar(' ');
    }
}

void my_ls(char *path)
{
    char *path_str = path;
    DIR *dir = opendir(path_str);
    struct dirent *entry;
    int index = 0;

    checkdev(path_str, dir);
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.') {
            write(1, entry->d_name, my_strlen(entry->d_name));
            print_space_if_not_last(index, countfiles(path));
            index++;
        }
    }
    closedir(dir);
}

void checkflag( char **av , int i)
{
    if (av[i][0] == '-') {
        if (av[i][1] == 'a') {
            my_ls_a(".");
        }
        if (av[i][1] == 'd') {
            my_ls_d(".");
        }
        if (av[i][1] == 'l') {
            my_ls_l(".");
        }
        if (av[i][1] == 'r') {
            my_ls_r(".");
        }
        if (av[i][1] == 'R') {
            printfirstdirectory(".");
            my_ls_majr(".");
        }
        } else {
            my_ls(av[i]);
        }
}

void checksecondlfag(char **av, int j)
{
    if (av[j][1] == 'a') {
        my_ls_a(av[j + 1]);
    }
    if (av[j][1] == 'd') {
        my_ls_d(av[j + 1]);
    }
    if (av[j][1] == 'l') {
        my_ls_l(av[j + 1]);
    }
    if (av[j][1] == 'r') {
        my_ls_r(av[j + 1]);
    }
    if (av[j][1] == 'R') {
        printfirstdirectory(av[j + 1]);
        my_ls_majr(av[j + 1]);
    }
}
