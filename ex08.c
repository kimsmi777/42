#include <stdio.h>

char* my_strncpy(char* dest, const char* src, size_t count)
{
	size_t i;
	const char* s = src;
	char* d = dest;

	for (i = 0; i < count; i++) {
		if (*s) {
			*d++ = *s++;
		}
		else {
			*d++ = NULL;
		}
	}
	return dest;
}

size_t my_strlen(const char* str)
{
	const char* p;

	for (p = str;*p;p++) { ; }
	return p - str;
}

char* my_strncat(char* dest, const char* src, size_t count)
{
	int dlen = my_strlen(dest);

	my_strncpy(dest + dlen, src, count);
	dest[dlen + count] = 0;
	return dest;
}

char* ft_strncat(char* s1, const char* s2, size_t count) {
	char* start = s1;
	while (*s1++)
		;
	s1--;
	while (count--) {
		// 널문자까지 찾는다 , 널문자를 만나면 조건문이 충족을 못함
		if (!(*s1++ = *s2++)) return start;
	}
	*s1 = '\0';
	return start;
}

int	ft_isspace(char c)
{
	if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9'))
		return 1;
	return 0;
}

char* ft_strcapitalize(char* str)
{
	char* back_up;
	int space;

	back_up = str;
	space = 1;
	while (*str)
	{
		if (ft_isspace(*str))
		{
			space = 1;
		}
		else
		{
			if (space == 1 && (*str >= 'a' && *str <= 'z'))
				*str = *str - ('a' - 'A');
			if (space == 0 && (*str >= 'A' && *str <= 'Z'))
				*str = *str + ('a' - 'A');
			space = 0;
		}
		str++;
	}

	return back_up;
}
int main()
{
	char str[100] = "ORANGE STRAW+BERRY+COFFEE";

	printf("%s ", ft_strcapitalize(str));

	//char str1[100] = "salut, comment tu vas ? 42mots quet-des; cinqu+et+un";
	//char str2[100] = "";
	//char str3[100] = "HellO, I AM sryou. ????is gOOD FOR ;;42's 42HELLO";
	//printf("----ex09----\n");
	//printf("Before Change\n%s\n%s\n%s\n", str1, str2, str3);
	//printf("Changed Str : %s\n", ft_strcapitalize(str1));
	//printf("Changed Str : %s\n", ft_strcapitalize(str2));
	//printf("Changed Str : %s\n", ft_strcapitalize(str3));
	//printf("After Change\n%s\n%s\n%s\n", str1, str2, str3);


    /*
	* char ar1[100] = "apple ";
	char ar2[100] = "pie";
	
	my_strncat(ar1, ar2, 3);
	printf("%s ", ar1);

	ft_strncat(ar1, ar2, 3);
	printf("%s ", ar1);
	*/

	return 0;
}