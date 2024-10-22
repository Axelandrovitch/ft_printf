#include "../ft_printf.h"
#include <stdio.h>
#include <assert.h>

void	test_ft_printf_length()
{
	
	char	*str1 = "Hello";
	char	*str2 = "this will pass";
	char	*str3 = "please make it work";
	char	*str4 = "testing is an important part of software development";

	int	original;
	int	implementation;
	// %i conversion
	original = printf("%i\n", -541155487);
	implementation = ft_printf("%i\n", -541155487);
	assert(original == implementation);
	original = printf("%i\n", -54);
	implementation = ft_printf("%i\n", -54);
	assert(original == implementation);
	original = printf("%i\n", -545);
	implementation = ft_printf("%i\n", -545);
	assert(original == implementation);
	ft_printf("\n");
	ft_printf("################################################\n");
	ft_printf("#    All tests for %%i conversion passed !      #\n");
	ft_printf("################################################\n\n");

	// %d conversion
	original = printf("%d\n", -541155487);
	implementation = ft_printf("%d\n", -541155487);
	assert(original == implementation);
	original = printf("%d\n", 278);
	implementation = ft_printf("%d\n", 278);
	assert(original == implementation);
	original = printf("%d\n", -54545);
	implementation = ft_printf("%d\n", -54545);
	assert(original == implementation);
	ft_printf("\n");
	ft_printf("################################################\n");
	ft_printf("#     All tests for %%d conversion passed !     #\n");
	ft_printf("################################################\n\n");
	// %s conversion
	original = printf("%s %s %s!! Because %s\n", str1, str2, str3, str4);
	implementation = ft_printf("%s %s %s!! Because %s\n", str1, str2, str3, str4);
	assert(original == implementation);
	original = printf("%s %s\n", "Hello World!", "Will this \0 work ! :/");
	implementation = printf("%s %s\n", "Hello World!", "Will this \0 work ! :/");
	assert(original == implementation);
	original = printf("%s", "");
	implementation = ft_printf("%s", "");
	assert(original == implementation);
	char	*null_str = NULL;
	original = printf("%s\n", null_str);
	implementation = ft_printf("%s\n", null_str);
	assert(original == implementation);

	ft_printf("\n");
	ft_printf("################################################\n");
	ft_printf("#      All tests for %%s conversion passed !    #\n");
	ft_printf("################################################\n\n");


	// %c conversion
	original = printf("%%%c\n", 'C');
	implementation = ft_printf("%%%c\n", 'C');
	assert(original == implementation);

	original = printf("My name is %c%c%c%c\n", 'A', 'x', 'e', 'l');
	implementation = ft_printf("My name is %c%c%c%c\n", 'A', 'x', 'e', 'l');
	assert(original == implementation);

	ft_printf("\n");
	ft_printf("################################################\n");
	ft_printf("#   All tests for %%c conversion passed !       #\n");
	ft_printf("################################################\n\n");

	//%x conversion
	original = printf("%x\n", 12345678);
	implementation = ft_printf("%x\n", 12345678);
	assert(original == implementation);

	original = printf("%x\n", 0);
	implementation = ft_printf("%x\n", 0);
	assert(original == implementation);

	original = printf("%x\n", -1);
	implementation = ft_printf("%x\n", -1);
	assert(original == implementation);

	original = printf("%x\n", 4294967295U);  // Valeur non signée maximale pour 32 bits
	implementation = ft_printf("%x\n", 4294967295U);
	assert(original == implementation);

	ft_printf("\n");
	ft_printf("################################################\n");
	ft_printf("#   All tests for %%x conversion passed !       #\n");
	ft_printf("################################################\n\n");

	//%X conversion
	original = printf("%X\n", 78877878);
	implementation = ft_printf("%X\n", 78877878);
	assert(original == implementation);

	original = printf("%X\n", 1548);
	implementation = ft_printf("%X\n", 1548);
	assert(original == implementation);

	original = printf("%X\n", -42);
	implementation = ft_printf("%X\n", -42);
	assert(original == implementation);

	original = printf("%X\n", 4294967295U);  // Valeur non signée maximale pour 32 bits
	implementation = ft_printf("%X\n", 4294967295U);
	assert(original == implementation);

	ft_printf("\n");
	ft_printf("################################################\n");
	ft_printf("#   All tests for %%X conversion passed !       #\n");
	ft_printf("################################################\n\n");

	// %u conversion
	
	original = printf("%u\n", 0);
	implementation = ft_printf("%u\n", 0);

	original = printf("%u\n", 12345);
	implementation = ft_printf("%u\n", 12345);
	assert(original == implementation);

	original = printf("%u\n", 4294967295U);
	implementation = ft_printf("%u\n", 4294967295U);
	assert(original == implementation);

	original = printf("%u\n", -1);
	implementation = ft_printf("%u\n", -1);
	assert(original == implementation);

	original = printf("%u\n", 987654);
	implementation = ft_printf("%u\n", 987654);
	assert(original == implementation);

	ft_printf("\n");
	ft_printf("################################################\n");
	ft_printf("#   All tests for %%u conversion passed !       #\n");
	ft_printf("################################################\n\n");

	// %p conversion
	int x = 42;
	int *ptr = &x;

	original = printf("%p\n", (void *)ptr);  
	implementation = ft_printf("%p\n", (void *)ptr);
	assert(original == implementation);

	original = printf("%p\n", NULL);  
	implementation = ft_printf("%p\n", NULL);
	assert(original == implementation);

	original = printf("%p\n", (void *)&x);
	implementation = ft_printf("%p\n", (void *)&x);
	assert(original == implementation);

	char *str = "Hello";
	original = printf("%p\n", (void *)str);
	implementation = ft_printf("%p\n", (void *)str);
	assert(original == implementation);

	int y = 100;
	original = printf("%p\n", (void *)&y);
	implementation = ft_printf("%p\n", (void *)&y);
	assert(original == implementation);

	ft_printf("\n");
	ft_printf("################################################\n");
	ft_printf("#   All tests for %%p conversion passed !       #\n");
	ft_printf("################################################\n\n");

	// combined conversion
	char c = 'C';
	char *str_test = "is such a blast !";
	int num1 = 42;
	int *p = &num1;
	unsigned int u_num = 4294967295U;
	int hex_num = 255; 

	original = printf("%c %s\n", c, str_test);
	implementation = ft_printf("%c %s\n", c, str_test);
	assert(original == implementation);

	original = printf("%p %d %i\n", (void *)ptr, -num1, num1);
	implementation = ft_printf("%p %d %i\n", (void *)p, -num1, num1);
	assert(original == implementation);

	original = printf("%u %x %X\n", u_num, hex_num, hex_num);
	implementation = ft_printf("%u %x %X\n", u_num, hex_num, hex_num);
	assert(original == implementation);

	original = printf("Print a percent sign: %%\n");
	implementation = ft_printf("Print a percent sign: %%\n");
	assert(original == implementation);

	ft_printf("\n");
	ft_printf("################################################\n");
	ft_printf("#   All tests for combined conversion passed !  #\n");
	ft_printf("################################################\n\n");

	ft_printf("-------------------------------------------------");
	ft_printf("\n");

	ft_printf("\n");
	ft_printf("#################################################\n");
	ft_printf("#           All length tests passed !           #\n");
	ft_printf("#################################################\n\n");
	
}
int	main(void)
{ 
	ft_printf("The following test only asserts the returned value of ft_printf\nNot the stdout...\nYou will have to use your eyes :(\n");
	ft_printf("################################################\n");
	ft_printf("\n");
	test_ft_printf_length();
	return (0);
}
