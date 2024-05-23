%{
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int idCount = 0;
typedef int bool;
#define true 1
#define false 0
typedef struct {
    char* key;
    bool seen;
} IdentifierMap;

IdentifierMap* idMap;
%}

DIGIT       [0-9]
LETTER      [a-zA-Z]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT})*
INTEGER     -?{DIGIT}+
REAL        -?{DIGIT}+"."{DIGIT}+
DELIMITER   [()[\]{},;]

%%
{INTEGER}       { printf("Integer: %s\n", yytext); }
{REAL}          { printf("Real: %s\n", yytext); }
{DELIMITER}     { printf("Delimiter: %s\n", yytext); }
{IDENTIFIER}    {
                    char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while","main"};
                    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
                    int i;
                    int is_keyword = 0;

                    for (i = 0; i < 33; ++i) {
                        if (strcmp(yytext, keywords[i]) == 0) {
                            printf("Keyword: %s\n", yytext);
                            is_keyword = 1;
                            break;
                        }
                    }

                    if (!is_keyword) {
      int found = 0;
                      for (int i = 0; i < idCount; i++) {
                          if (strcmp(yytext, idMap[i].key) == 0) {
                               found = 1;
                              break;
                          }
                     }
                      if (!found) {
                           // Allocate memory for the new identifier
                          idMap = (IdentifierMap*)realloc(idMap, (idCount + 1) * sizeof(IdentifierMap));
                          idMap[idCount].key = strdup(yytext); // Store a copy of the identifier
                          idMap[idCount].seen = true;
                          idCount++;
                      }
      printf("Identifier = %s\n",yytext);
                    }

                }
.               { printf("Invalid token: %s\n", yytext); }

%%

int main() {
    FILE* file;
    char filename[100];
    scanf("%s",filename);
    file = fopen(filename,"r");
    if(file==NULL){return 0;}
    yyin=file;
    yylex();
    printf("Identifier Count = %d\n",idCount);
    return 0;
}

int yywrap() {
    return 1;
}

