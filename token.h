#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayTokens(char **tokens, int numberOfTokens);
int getTokens(char *s, char ***args);

#endif