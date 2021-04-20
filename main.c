#include "libft.h"

int	main(void)
{
	char buf[1000];

	ft_putnbr_base_fd(1588237, "01234567", 1);
	ft_putstr("\n");
	ft_memmove(buf, "\nslipknot is good, so is rafale  \n", 35);
	ft_memmove(buf + 25, buf + 1, 8);
	ft_memmove(buf + 1, "rafale  ", 8);
	ft_putstr(buf);


	void *ptr1 = ft_malloc(1000);
	ft_malloc(9);
	ft_malloc(63);
	show_alloc_mem();
	for (unsigned i = 0; i < 600; ++i)
	{
		//ft_free(ptr1);
		ptr1 = ft_malloc(10000);
		((char *)ptr1)[100] = 10;
	}
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
	ft_free(ft_malloc(110));
	ft_free(ft_malloc(163));
	ft_free(ft_malloc(110));
	ft_free(ft_malloc(163));
	ft_free(ft_malloc(2100));
	ft_free(ft_malloc(4095));
	// ft_malloc(4096);
	// ft_malloc(4097);
	// ft_malloc(12001);
	show_alloc_mem();
	ft_free(ptr1);
	ft_putstr("\n");
	show_alloc_mem();
	//while (1);
	return (0);
}