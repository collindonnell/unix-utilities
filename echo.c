#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (--argc == 0) {
		putchar('\n');
		exit(0);
	}
	
	// Loop through each space separated argument.
	for (int i = 1; i <= argc; i++) {
		// Loop every argument and print each character for each line
		// until *cp is NULL.
		for (char *cp = argv[i]; *cp; cp++) {
			// Handle and print escape characters.
			if (*cp == '\\') {
				// If the current character is an escape character, increment
				// cp to the next character and if it is a valid escape code,
				// print it.
				switch (*++cp) {
					case 'b':
						putchar('\b');
						break;
					case 'f':
						putchar('\f');
						break;
					case 'n':
						putchar('\n');
						break;
					case 'r':
						putchar('\r');
						break;
					case 't':
						putchar('\t');
						break;
					case 'v':
						putchar('\v');
						break;
					case '\\':
						putchar('\\');
						break;
					default:
						*cp--;
				}
			} else {
				putchar(*cp);
			}
		}
		
		// If this is the last argument, print a newline, otherwise print a
		// space between each word.
		putchar(i == argc ? '\n' : ' ');
	}
	
	return 0;
}