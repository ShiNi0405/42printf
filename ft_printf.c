#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++; // Move past the '%' to the specifier
			if (*format == 'c')
				count += print_char(va_arg(ap, int));
			else if (*format == 's')
				count += print_str(va_arg(ap, char *));
			else if (*format == 'p')
				count += handle_pointer(va_arg(ap, void *)); //handle pointer include see if pointer is null then printdigit pointer
			else if (*format == 'd' || *format == 'i')
				count += print_int(va_arg(ap, int));
			else if (*format == 'u')
				count += print_digit(va_arg(ap, unsigned int), 10, "0123456789");
			else if (*format == 'x')
				count += print_digit(va_arg(ap, unsigned int), 16, "0123456789abcdef");
			else if (*format == 'X')
				count += print_digit(va_arg(ap, unsigned int), 16, "0123456789ABCDEF");
			else if (*format == '%')
				count += print_char('%');
		}
		else
			count += print_char(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
