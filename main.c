#include "libft.h"

int	main(void)
{
	void *ptr1 = malloc(1000);
	malloc(9);
	void *ptr2 = malloc(42);
	void *ptr3 = malloc(69420);
	malloc(63);
	for (unsigned i = 0; i < 1; ++i)
	{
		ptr1 = malloc(10);
		((char *)ptr1)[1] = 10;
	}
	show_alloc_mem();
		free(ptr1);
	malloc(1);
	malloc(10);
	malloc(9);
	malloc(63);
	malloc(1);
	malloc(2);
	malloc(11);
	malloc(21);
	malloc(19);
	malloc(11);
	malloc(19);
	free(malloc(110));
	free(malloc(163));
	free(malloc(110));
	free(malloc(163));
	free(malloc(2100));
	free(malloc(4095));
	malloc(4096);
	malloc(4097);
	malloc(12001);
	show_alloc_mem();
	free(ptr1);
	free(ptr1);
	ft_putstr("\n");
	
	show_alloc_mem();

	// ft_free(ptr2);
	ptr2 = realloc(ptr2, 16);
	ptr2 = realloc(ptr2, 16);
	ptr2 = realloc(ptr2, 16);
	ptr2 = realloc(ptr2, 16);
	ptr2 = realloc(ptr2, 16);

	ptr3 = realloc(ptr3, 4200);
	ptr3 = realloc(ptr3, 42000);
	ptr3 = realloc(ptr3, 420000);
	ptr3 = realloc(ptr3, 42000);
	ptr3 = realloc(ptr3, 4200);
	ptr3 = realloc(ptr3, 420);
	ptr3 = realloc(ptr3, 42000);
	ptr3 = realloc(ptr3, 420000);
	ptr3 = realloc(ptr3, 42000);
	ptr3 = realloc(ptr3, 4200);
	ptr3 = realloc(ptr3, 420);
	ptr2 = realloc(ptr2, 42000);

	ft_putstr("\n");
	char *str = malloc(10);
	ft_memmove(str, "rafale !\n", 10);
	ft_putstr(str);
	show_alloc_mem();

	str = realloc(str, 10000);
	ft_memmove(str, "rafale ! rafale ! rafale !\n", 28);
	ft_putstr(str);
	show_alloc_mem();
	str = realloc(str, 6);
	str[5] = 0;
	ft_putstr(str);
	show_alloc_mem();
	//while(1);
	return (0);
}