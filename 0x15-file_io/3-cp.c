#include "main.h"

/**
 * printErrorMessage - Prints an error message to the standard error output.
 * @fileDescriptor: The file descriptor that caused the error.
 *
 * Description: This function is called when a file cannot be closed. It prints
 *              an error message to the standard error output and exits with a
 *              status of 100.
 *
 * Return: None.
 */
void printErrorMessage(int fileDescriptor)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileDescriptor);
	exit(100);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command line arguments.
 * @argv: An array containing the program command line arguments.
 *
 * Description: This program copies the content of a file to another file. It
 *              takes two command line arguments: the name of the file to copy
 *              from and the name of the file to copy to. If the number of
 *              arguments is not exactly 3, or if either file cannot be opened,
 *              read from, or written to, it prints an error message to the
 *              standard error output and exits with a status of 97, 98, or 99,
 *              respectively. If a file cannot be closed, it calls the
 *              print_error function.
 *
 * Return: 0 on success, or exits with 97, 98, 99, or 100 on failure.
 */
int main(int argc, char *argv[])
{
	int sourceFile, destinationFile, writeCount;
	char buffer[1024]; /* Buffer to hold file content */

	if (argc != 3) /* Check if number of arguments is not exactly 3 */
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97); }
	sourceFile = open(argv[1], O_RDONLY); /* Open source file */
	if (argv[1] == NULL || sourceFile < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }

	destinationFile = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (destinationFile < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(sourceFile);
		exit(99); }
	while ((writeCount = read(sourceFile, buffer, 1024)) > 0)
	{
		if (writeCount != write(destinationFile, buffer, writeCount))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(sourceFile);
			close(destinationFile);
			exit(99);
	}}
	if (writeCount < 0) /* Check if read was successful */
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }
	if (close(sourceFile) < 0) /* Close source file */
		print_error(sourceFile);
	if (close(destinationFile) < 0) /* Close destination file */
		print_error(destinationFile);
	return (0); /* Return 0 on success */
}
