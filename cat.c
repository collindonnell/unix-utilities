#include <stdio.h>
#include <stdlib.h>

char *progname = NULL;

int cat(FILE* fp)
{
	char buf[BUFSIZ];

	while (fgets(buf, BUFSIZ, fp) != NULL) {
		if (fputs(buf, stdout) == EOF) {
			fprintf(stderr, "%s: write error", progname);
			return 1;
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	progname = argv[0] != NULL ? argv[0] : "cat";
	
	if (argc <= 1) {
		return cat(stdin);
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		FILE* fp;
		if ((fp = fopen(argv[i], "r")) == NULL) {
			fprintf(stderr, "%s: cannot open %s\n", progname, argv[i]);
			continue;
		}
		cat(fp);
		fclose(fp);
	}
	
	return 0;
}
