#include <unistd.h>
#include <sanitizer/asan_interface.h>
  // In your code:
int	main()
{
	char*str=(char*)malloc(sizeof(char)*3);
	str = "12";
	//__asan_describe_address(str);
	free(str);
}
