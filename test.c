#include <stdio.h>
#include <stdarg.h>

/*
int	is_flag(char c)
{
	
}
*/

bool	is_type_specifier(char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return true;
		set++;
	}
	return false;
}

char	*ft_convert(va_list ap, char c)
{

	switch (c)
	{
		case 'c':
			return ft_s()
	}

}

char	*ft_format(char *str, ...)
{
	va_list	ap;
	char	*formated;
	int	i;
	bool	f_specifier;

	va_start(ap, num);
	f_specifier = false;
	formated = NULL;
	if (!str)
	{
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] == '%')
			f_specifier = true;
		if (f_specifier && is_type_specifier(str[i], "cspdiuxX%"))
		{
			f_speficier = false;
			ft_convert();
		}
		i++;
	}
	return (formated);
}

int	main(void)
{
	printf("Hello my name ia too long: %.15s\n", "Aleosls"); //prints max 15
	printf("Hello my name ia too long: %15s\n", "Aleos"); //prints min 15 : fill with extra spaces in front of %s
	printf("Hello old man: %d\n", 29);
	printf("Hello old man: %.5d\n", 29);
	printf("Hello old man: %5d\n", 29);
	ft_format("Hello!%");

	return (0);
	
}
