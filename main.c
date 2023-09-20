#include "token.h"

int main()
{
    char inputString[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", inputString);

    char **tokens;
    int numberOfTokens = getTokens(inputString, &tokens);
    displayTokens(tokens, numberOfTokens);
}