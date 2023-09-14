#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getTokens(char *s, char ***args)
{
    int stringLength = strlen(s);

    if (stringLength == 0) // Ends program if string has no length or if inputString breaks for some reason
    {
        return -1;
    }

    *args = malloc(sizeof(char **)); // Allocate a pointer-sized memory piece for token storage
    if (*args == NULL)
    {
        return -1;
    }

    int tokenCount = 0;   // Number of token's counted
    int startOfToken = 0; // Start of each counted token
    int endOfToken = 0;   // End of each counted token. The start value will be subtracted from the end value to determine each token length

    char **tokenStorage = *args;

    while (startOfToken < stringLength)
    {
        while (s[endOfToken] != ' ' && endOfToken < stringLength)
        {
            endOfToken++;
            // If the current character isn't a space, increment the token ending point
        }

        int tokenLength = endOfToken - startOfToken; // Token length calculation

        char *token = malloc(sizeof(char) * (tokenLength + 1)); // Allocating memory for the counted token AND the null terminator at the end

        memcpy(token, s + startOfToken, tokenLength); // memcpy function given by Ol' Walt

        token[tokenLength] = '\0'; // Add the null terminator onto the counted token

        tokenStorage[tokenCount] = token;
        tokenCount++;

        tokenStorage = realloc(tokenStorage, sizeof(char **) * (tokenCount + 1));
        *args = tokenStorage;

        startOfToken = endOfToken + 1; // Set the token starting point to the start of the next token
        endOfToken = startOfToken;     // Set the token ending point to the starting point to repeat the process
    }

    return tokenCount;
}

void displayTokens(char **tokens, int numberOfTokens)
{
    printf("Number of tokens: %d\n", numberOfTokens);
    for (int i = 0; i <= numberOfTokens; i++)
    {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        // It has to be "i + 1" so the tokens won't displayTokens as "0, 1, 2, 3, ..." as they are located in the array
    }
}

int main()
{
    char inputString[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", inputString);

    char **tokens;
    int numberOfTokens = getTokens(inputString, &tokens);
    displayTokens(tokens, numberOfTokens);
}