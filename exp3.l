%{
#include <stdio.h>
int lc=0,sc=0,tc=0,cc=0;
%}

%%
[ ]+	sc++;
\n	lc++;
\t	tc++;
.	cc++;
%%

int main(){
	FILE *fp;
	fp=fopen("prgrm.txt","r");
	yyin=fp;
	yylex();
	fclose(fp);
	printf("sc=%d,lc=%d,tc=%d,cc=%d",sc,lc,tc,cc);
	return 0;
	}
int yywrap(){
	return 1;
	}


/*%{
    #include<stdio.h>
    int lines = 0, words = 0, letters = 0, num = 0, spl_char = 0, total = 0;
    int in_word = 0;  // To keep track if we are inside a word
%}

%%
\n { lines++; in_word = 0; }
[ \t]+ { in_word = 0; }
[a-zA-Z] { letters++; if (!in_word) { words++; in_word = 1; } }
[0-9] { num++; if (!in_word) { words++; in_word = 1; } }
. { spl_char++; }
%%

int main(void)
{
    yylex();
    total = letters + num + spl_char;
    printf("\n%d lines.", lines);
    printf("\n%d words.", words);
    printf("\n%d characters (letters, numbers, special characters): %d.\n", total, total);
    return 0;
}

int yywrap()
{
    return 1;
}

*/
