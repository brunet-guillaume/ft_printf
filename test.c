#include "libft/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>
int main()
{
	printf("%d", printf(NULL));
	printf("%d", ft_printf(NULL));
	ft_printf(NULL);
	return (0);
}
