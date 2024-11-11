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
	
