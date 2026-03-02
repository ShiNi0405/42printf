#include "ft_printf.h"
int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_str(char *s)
{
	int	count;

	count = ft_putstr_fd_len(s, 1);
	return (count);
}

int print_int(int i){
	int	count;
	count = ft_putnbr_fd_len(i, 1);
	return (count);
}

int		handle_pointer(void *ptr){
   int count=0;
    if(!ptr){
        print_str("(nil)");
    }
    else{
        print_str("0x");
        print_digit((unsigned long)ptr, 16,"0123456789abcdef");
    }
	return count;
};

int		print_digit(unsigned long n, int base, char *symbols){
   
    int count=0;
	unsigned long	nbr;

	nbr = n;
		long long nbr_cpy=nbr;

	
	while(nbr_cpy>0){
	    nbr_cpy=nbr_cpy/base;
	    count++;
	}
	if (nbr > (unsigned int)base-1){
		print_digit((unsigned long)(nbr / base), base,symbols);
	    char *end = symbols + nbr % base;
	ft_putchar_fd(*end,1);}

	return count;
};
