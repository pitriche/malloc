#include "libft.h"

int	main(void)
{
	// char buf[1000];

	// ft_putnbr_base_fd(1588237, "01234567", 1);
	// ft_putstr("\n");
	// ft_memmove(buf, "\nslipknot is good, so is rafale  \n", 35);
	// ft_memmove(buf + 25, buf + 1, 8);
	// ft_memmove(buf + 1, "rafale  ", 8);
	// ft_putstr(buf);


	void *ptr1 = malloc(1000);
	malloc(9);
	void *ptr2 = malloc(42);
	void *ptr3 = malloc(69420);
	//ft_malloc(63);
	for (unsigned i = 0; i < 1; ++i)
	{
		ptr1 = malloc(10);
		((char *)ptr1)[1] = 10;
	}
	//show_alloc_mem();
		free(ptr1);
	// ft_malloc(1);
	// ft_malloc(10);
	// ft_malloc(9);
	// ft_malloc(63);
	// ft_malloc(1);
	// ft_malloc(2);
	// ft_malloc(11);
	// ft_malloc(21);
	// ft_malloc(19);
	// ft_malloc(11);
	// ft_malloc(19);
	free(malloc(110));
	free(malloc(163));
	free(malloc(110));
	free(malloc(163));
	free(malloc(2100));
	free(malloc(4095));
	// ft_malloc(4096);
	// ft_malloc(4097);
	// ft_malloc(12001);
	//show_alloc_mem();
	free(ptr1);
	free(ptr1);
	//ft_putstr("\n");
	
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



	// while (1);
	return (0);
}