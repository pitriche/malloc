#include "libft.h"

int main(void)
{
	char buf[1000];

	ft_memmove(buf, "slipknot is good, so is rafale  ", 33);
	ft_memmove(buf + 24, buf, 8);
	ft_memmove(buf, "rafale  ", 8);
	ft_putstr(buf);
	return (0);
}