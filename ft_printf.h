#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

/*
** Main Function
*/
int		ft_printf(const char *format, ...);

/*
** Helper functions for conversions
** These usually go in your utils.c
*/
int		print_char(int c);
int		print_str(char *str);
int		print_int(int n);
int		handle_pointer(void *ptr);
int		print_digit(unsigned long n, int base, char *symbols);

#endif
