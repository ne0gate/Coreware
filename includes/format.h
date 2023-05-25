/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-damian.gil
** File description:
** format
*/

#ifndef FORMAT_H_
    #define FORMAT_H_

    #include <stdbool.h>
    #include <errno.h>
    #include <stdio.h>
    #include "op.h"

    #ifndef ERRNO_ASM_NAMES
        #define ERRNO_ASM_NAMES
        #define WRONG_ARG EINVAL
        #define UNKNOWN_REGISTER EFAULT
        #define NO_COMMENT ENOMSG
        #define NO_NAME ENOKEY
    #endif

bool is_dir(char *arg);
bool is_reg(char *arg);
bool is_ind(char *arg);
bool is_lab_arg(char *arg);

typedef struct type_of_args_s type_of_args_t;

struct type_of_args_s{
    args_type_t args[4];
    type_of_args_t *next;
};

typedef struct {
    char name[PROG_NAME_LENGTH];
    char comment[COMMENT_LENGTH];
    char **lines;
} file_info_t;

bool main_asm(FILE *rfile, char const *wfilepath);
bool asm_loop(const char *const *file_lines, FILE *file);
bool execute(unsigned int line_of_op_tab, char **arg, FILE *file);
bool is_dir(char *arg);
bool is_reg(char *arg);
bool is_ind(char *arg);
bool is_lab_arg(char *arg);
bool fill_lines(file_info_t *sfile, FILE *rfile);
int my_strlen_until(char const *str, char c);
bool errno_error_test(unsigned int line);

//lib my
bool pointer_add_to_list(void ***arr, void **ptr);
int fclose_protected(FILE *flux);
bool set_rand(void);
int get_rand(void);
int get_randint(int min, int max);
size_t my_strlen(char const *str);
char *my_strnbr_base(int nbr, char const *base);
void *malloc_empty(size_t size);
int my_strncmp(const char* s1, const char* s2, int n);
size_t my_array_len(void *ptr);
char *my_strcpy(char *dest, char const *src);
void rm_2d_array(char **map);
int my_getnbr(char const *str);

#endif
