/*
** EPITECH PROJECT, 2023
** my_ls_l
** File description:
** my_ls_l
*/

#include "../includes/my.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

struct dirent *entry;
struct stat sb;


static int printfichertype(void)
{
    if (S_ISDIR(sb.st_mode)) {
        my_putchar('d');
    } else {
        my_putchar('-');
    }
    return 0;
}

static int printpermissions(void)
{
    my_putchar(sb.st_mode & S_IRUSR ? 'r' : '-');
    my_putchar(sb.st_mode & S_IWUSR ? 'w' : '-');
    my_putchar(sb.st_mode & S_IXUSR ? 'x' : '-');
    my_putchar(sb.st_mode & S_IRGRP ? 'r' : '-');
    my_putchar(sb.st_mode & S_IWGRP ? 'w' : '-');
    my_putchar(sb.st_mode & S_IXGRP ? 'x' : '-');
    my_putchar(sb.st_mode & S_IROTH ? 'r' : '-');
    my_putchar(sb.st_mode & S_IWOTH ? 'w' : '-');
    my_putchar(sb.st_mode & S_IXOTH ? 'x' : '-');
}

void printfileinfo(void)
{
    struct group *grp = getgrgid(sb.st_gid);
    struct passwd *pwd = getpwuid(sb.st_uid);
    char *time_str = ctime(&sb.st_mtime);

    my_putchar(' ');
    my_put_nbr(1);
    my_putchar(' ');
    my_putstr(pwd->pw_name);
    my_putchar(' ');
    my_putstr(grp->gr_name);
    my_putchar(' ');
    my_put_nbr(sb.st_size);
    my_putchar(' ');
    time_str[my_strlen(time_str) - 9] = '\0';
    my_putstr(&time_str[3]);
    my_putchar(' ');
    my_putstr(entry->d_name);
    my_putchar('\n');
}

int printall(char *full_path)
{
    if (stat(full_path, &sb) == -1) {
        return 84;
    }
    printfichertype();
    printpermissions();
    printfileinfo();
    return 0;
}

void my_ls_l(char *path)
{
    char full_path[1024];
    char *path_str = path;
    DIR *dir = opendir(path_str);

    if (dir == NULL) {
        perror("cannot open directory");
        exit(1);
    }
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.') {
            my_strcpy(full_path, path_str);
            my_strcat(full_path, "/");
            my_strcat(full_path, entry->d_name);
            printall(full_path);
        }
    }
    closedir(dir);
}
