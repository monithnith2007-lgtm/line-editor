#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

/* Insert a new line */
void insertLine()
{
    int position;
    char text[MAX_LENGTH];

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    printf("Enter line number: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0';

    for (int i = lineCount; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], text);
    lineCount++;

    printf("Line inserted successfully.\n");
}

/* Delete a line */
void deleteLine()
{
    int position;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("Enter line number: ");
    scanf("%d", &position);
    getchar();

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (int i = position - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

/* Display document */
void displayDocument()
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n===== DOCUMENT =====\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }
}

/* Save document */
void saveDocument()
{
    FILE *file = fopen("document.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("Document saved successfully.\n");
}

/* Load document */
void loadDocument()
{
    FILE *file = fopen("document.txt", "r");

    if (file == NULL)
    {
        printf("No saved document found.\n");
        return;
    }

    lineCount = 0;

    while (lineCount < MAX_LINES &&
           fgets(lines[lineCount], MAX_LENGTH, file) != NULL)
    {
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0';
        lineCount++;
    }

    fclose(file);

    printf("Document loaded successfully.\n");
}

/* Main function */
int main()
{
    char command[20];

    printf("===== SIMPLE LINE EDITOR =====\n");
    printf("Commands: insert, delete, display, save, load, exit\n");

    while (1)
    {
        printf("\n> ");
        scanf("%19s", command);

        if (strcmp(command, "insert") == 0)
        {
            insertLine();
        }
        else if (strcmp(command, "delete") == 0)
        {
            deleteLine();
        }
        else if (strcmp(command, "display") == 0)
        {
            displayDocument();
        }
        else if (strcmp(command, "save") == 0)
        {
            saveDocument();
        }
        else if (strcmp(command, "load") == 0)
        {
            loadDocument();
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Exiting editor...\n");
            break;
        }
        else
        {
            printf("Unknown command.\n");
            printf("Available commands: insert, delete, display, save, load, exit\n");
        }
    }

    return 0;
}