#include <stdio.h>
#include <sys/stat.h>
// Workshop 5 - High Level File I/O
// 1. Create a text file named as doc1.txt.
// Write name and age the user input using
// standard input to doc1.txt with possible error
// handling.
// 2. Copy doc1.txt into another file doc2.txt
// with possible error handling.

int main()
{
    FILE *file = NULL;

    file = fopen("doc1.txt", "w+");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    char name[100];
    int age;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);

    fprintf(file, "Name: %s\n", name);
    fprintf(file, "Age: %d\n", age);

    fclose(file);

    FILE *fileToRead = NULL;

    fileToRead = fopen("doc1.txt", "r");

    if (fileToRead == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    FILE *fileToWrite = NULL;

    fileToWrite = fopen("doc2.txt", "w+");

    if (fileToWrite == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    char buf1[6];
    while (EOF != fscanf(fileToRead, "%s", buf1))
    {
        int bytes_written = fprintf(fileToWrite, "%s ", buf1);
        if (bytes_written == -1)
        {
            printf("\n doc2 could not be written.");
            perror("\n doc2.txt");
            printf("\n Error number is %d");
        }
    }

    // 3. Create and open a file doc1.txt and close
    // it.// Then give read only previleges and open it.
    // Write a program with error handling to write a
    // sentence to it.

    FILE *fileToRead2 = NULL;

    chmod("doc1.txt", S_IRUSR | S_IRGRP | S_IROTH);
    fileToRead2 = fopen("doc1.txt", "w");

    if (fileToRead2 == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // fclose(fileToRead2);

    return 0;
}
