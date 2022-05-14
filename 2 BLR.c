#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	int k;
	int lm;
	char s[20];
	char sc[2], c;
	char* s1;
	char* s2;
	/*char v='1';*/
	int i;
	FILE* f;
	FILE* g;
	f = fopen("blr.in", "rt");
	g = fopen("blr.out", "wt");

	fseek(f, 0, SEEK_END);//seteaza poz cursorului la sfarsitu fisierului
	lm = ftell(f);//calculeaza lungimea fisierului
	fseek(f, 0, SEEK_SET);//reseteaza poz cursorului

	fscanf(f, "%d %s", &k, sc);

	c = sc[0];//caracterul

	s1 = (char*)calloc(k, sizeof(char));
	s2 = (char*)malloc(k * sizeof(char));
	strset(s2, c);
	strncat(s1, s2, k);



	while (ftell(f) != lm)
	{
		fscanf(f, "%s", s);
		if ((s[0] > 'A' && s[0] < 'Z') || s[0] == 'A' || s[0] == 'Z')
		{
			fprintf(g, "%s", s1);
			if (isalnum(s[strlen(s) - 1]) == 0)
				fprintf(g, "%c", s[strlen(s) - 1]);
			fprintf(g, " ");
		}
		else
			fprintf(g, "%s ", s);
	}

	fclose(f);
	fclose(g);

	return 0;
}