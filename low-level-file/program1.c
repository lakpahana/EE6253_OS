#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

// 4. Create and open a file doc3.txt with read,write,execute privileges and close it.
// Then, change the mode to read only privileges without opening it. Open doc3.txt as
// read only and Write a program with error handling to write a sentence to it?

int main()
{
    // 1. Create a text file named as doc1.txt and write name and age the user input using
    // standard input to doc1.txt with possible error handling. If doc1.txt exists; the
    // program should truncate it and rewrite.
    int fd1 = open("doc1.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
    if (fd1 == -1)
    {
        perror("Error in opening file");
        return -1;
    }
    printf("file descriptor: %d\n", fd1);

    char name[100];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); // Use fgets to allow spaces in the name
    name[strcspn(name, "\n")] = '\0'; // Remove newline character if present

    char age[100];
    printf("Enter your age: ");
    fgets(age, sizeof(age), stdin); // Use fgets to allow spaces in the age
    age[strcspn(age, "\n")] = '\0'; // Remove newline character if present

    ssize_t bytes_written = write(fd1, name, strlen(name)); // Write the actual length of the string
    if (bytes_written == -1)
    {
        perror("Error in writing to file");
        close(fd1);
        return -1;
    }

    bytes_written = write(fd1, "\n", 1); // Optionally, add a newline after the name

    bytes_written = write(fd1, age, strlen(age)); // Write the actual length of the string
    if (bytes_written == -1)
    {
        perror("Error in writing to file");
        close(fd1);
        return -1;
    }

    close(fd1);
    // 2. Copy doc1.txt into another file doc2.txt with possible error handling.
    int fd2 = open("doc1.txt", O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);

    if (fd2 == -1)
    {
        perror("Error in opening file");
        return -1;
    }

    char buffer[100];

    ssize_t bytes_read = read(fd2, buffer, sizeof(buffer));

    if (bytes_read == -1)
    {
        perror("Error in reading from file");
        close(fd2);
        return -1;
    }

    close(fd2);

    int fd3 = open("doc2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);

    if (fd3 == -1)
    {
        perror("Error in opening file");
        return -1;
    }

    bytes_written = write(fd3, buffer, bytes_read);

    if (bytes_written == -1)
    {
        perror("Error in writing to file");
        close(fd3);
        return -1;
    }

    close(fd3);
    // 3. Write a program to read from 15th byte to 30th byte and 40th byte to 50th byte
    // from a doc1.txt and write to doc2.txt?

    int fd4 = open("doc1.txt", O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);

    if (fd4 == -1)
    {
        perror("Error in opening file");
        return -1;
    }

    lseek(fd4, 15, SEEK_SET); // Move the file pointer to the 15th byte

    char buffer1[16]; // 15th to 30th byte is 16 bytes

    bytes_read = read(fd4, buffer1, sizeof(buffer1));

    if (bytes_read == -1)
    {
        perror("Error in reading from file");
        close(fd4);
        return -1;
    }

    close(fd4);

    int fd5 = open("doc2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);

    if (fd5 == -1)
    {
        perror("Error in opening file");
        return -1;
    }

    bytes_written = write(fd5, buffer1, bytes_read);

    if (bytes_written == -1)
    {
        perror("Error in writing to file");
        close(fd5);
        return -1;
    }

    int fd6 = open("doc1.txt", O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);

    if (fd6 == -1)
    {
        perror("Error in opening file");
        return -1;
    }

    lseek(fd6, 40, SEEK_SET); // Move the file pointer to the 40th byte

    char buffer2[11]; // 40th to 50th byte is 11 bytes

    bytes_read = read(fd6, buffer2, sizeof(buffer2));

    if (bytes_read == -1)
    {
        perror("Error in reading from file");
        close(fd6);
        return -1;
    }

    close(fd6);

    bytes_written = write(fd5, buffer2, bytes_read);

    if (bytes_written == -1)
    {
        perror("Error in writing to file");
        close(fd5);
        return -1;
    }

    close(fd5);

    return 0;
}