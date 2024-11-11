#include<stdio.h>
#include <stdio.h>
#include <string.h>

void main() {
    char icode[10][30], str[20], opr[10];
    int i = 0;

    printf("Enter the set of intermediate code (terminated by 'exit'):\n");
    do {
        scanf("%s", icode[i]);
    } while (strcmp(icode[i++], "exit") != 0);

    printf("\nTarget code generation");
    printf("\n*****************************");
    i = 0;

    do {
        strcpy(str, icode[i]);

        if (strcmp(str, "exit") == 0) break; // Exit when "exit" is found

        // Check the operator in the fourth character (str[3])
        switch (str[3]) {
            case '+':
                strcpy(opr, "ADD");
                break;
            case '-':
                strcpy(opr, "SUB");
                break;
            case '*':
                strcpy(opr, "MUL");
                break;
            case '/':
                strcpy(opr, "DIV");
                break;
            default:
                strcpy(opr, ""); // In case there's no valid operator
                break;
        }

        // Generating the target code
        printf("\n\tMov %c , R%d", str[2], i);
        printf("\n\t%s %c, R%d", opr, str[4], i);
        printf("\n\tMov R%d, %c", i, str[0]);

    } while (strcmp(icode[++i], "exit") != 0);
}






/*#include <stdio.h>
int main() {
  FILE *fp;
  char op[2], arg1[5], arg2[5], result[5];
  fp = fopen("in.txt", "r");
  while (fscanf(fp, "%s%s%s%s", op, arg1, arg2, result) != EOF)  {
    printf("MOV R0,%s\n", arg1);
    switch (op[0]) {
      case '+': printf("ADD R0,%s\n", arg2); break;
      case '-': printf("SUB R0,%s\n", arg2); break;
      case '*': printf("MUL R0,%s\n", arg2); break;
      case '/': printf("DIV R0,%s\n", arg2); break;
    }
    printf("MOV %s,R0\n", result);
  }
  fclose(fp);
  return 0;
}
*/
