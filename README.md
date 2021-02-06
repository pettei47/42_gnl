# get_next_line
This is one of 42 project's output.

### Prototype:
	int	get_next_line(int fd, char **line);

### Description:  
This function returns a line read from a
file descriptor, without the newline.

### Parameters:  
- #1. file descriptor for reading  
- #2. The value of what has been read

### Return:  
- 1 : A line has been read
- 0 : EOF has been reached
- -1 : An error happened

## Compilation
	make
then you can get libgnl.a  
and at the directry your main.c exists  

	gcc main.c -L"filepath of lingnl.a" -lasm
