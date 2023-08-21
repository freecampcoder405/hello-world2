#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct token
{
	char token_name [100];
	int index;
	unsigned int row,col; //Line numbers.
	char type[110];
};
char keywords[][20] = {
        "auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
};

int main() {
    char c, buf[10];
    FILE *fp = fopen("q1stdin.c", "r");
    int row = 1, col = 1;

    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(0);
    }

    c = fgetc(fp);
    while (c != EOF) {
        if (isspace(c)) {
            if (c == '\n') {
                row++;
                col = 1;
            } else {
                col++;
            }
            c = fgetc(fp);
            continue;
        }

        // Handle rel operators
        int i=0;
        buf[i++] = c; // Store the first character
	buf[i] = '\0'; // Null-terminate the string

	if (c == '=') {
    		c = fgetc(fp);
    		if (c == '=') {
        		buf[i++] = c;
        		buf[i] = '\0';
        		printf("<%s,%d,%d>", buf, row, col);
   		 } else {
        		printf("<%s,%d,%d>", buf, row, col);
   		 }
	} else if (c == '<' || c == '>' || c == '!') {
    		c = fgetc(fp);
    		if (c == '=') {
       		 buf[i++] = c;
    		}
    		buf[i] = '\0';
   		 printf("<%s,%d,%d>", buf, row, col);
	} else {
   		 buf[i] = '\0';
	}

        // Handle identifiers and keywords
        int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
	if (isspace(c)) {
            if (c == '\n') {
                row++;
                col = 1;
            } else {
                col++;
            }
            c = fgetc(fp);
            continue;
        }
        if (isalpha(c) || c == '_') {
            int i = 0;
            buf[i++] = c;
            c = fgetc(fp);
            while (isalnum(c) || c == '_') {
                buf[i++] = c;
                c = fgetc(fp);
            }
            buf[i] = '\0';

            int isKeyword = 0;
            for (int j = 0; j < numKeywords; j++) {
                if (strcmp(buf, keywords[j]) == 0) {
                    printf("<KEYWORD,%d,%d,%s>\n", row, col, buf);
                    isKeyword = 1;
                    break;
                }
            }

            if (!isKeyword) {
                printf("<IDENTIFIER,%d,%d,%s>\n", row, col, buf);
            }

            col += i;
            continue;
        }

        // Handle numerical constants
        if (isdigit(c)) {
            int i = 0;
            buf[i++] = c;
            c = fgetc(fp);
            while (isdigit(c)) {
                buf[i++] = c;
                c = fgetc(fp);
            }
            buf[i] = '\0';
            printf("<NUMERICAL_CONSTANT,%d,%d,%s>\n", row, col, buf);
            col += i;
            continue;
        }

        // Handle string literals
        if (c == '"') {
            int i = 0;
            buf[i++] = c;
            c = fgetc(fp);
            while (c != EOF && c != '"') {
                buf[i++] = c;
                c = fgetc(fp);
            }
            if (c == '"') {
                buf[i++] = c;
                buf[i] = '\0';
                printf("<STRING_LITERAL,%d,%d,%s>\n", row, col, buf);
            } else {
                // Handle unterminated string literal
                printf("<UNTERMINATED_STRING_LITERAL,%d,%d,%s>\n", row, col, buf);
            }
            col += i;
            c = fgetc(fp); // Move past the closing double quote or EOF
            continue;
        }

        col++;
        c = fgetc(fp);
}

    fclose(fp);
    return 0;
}
