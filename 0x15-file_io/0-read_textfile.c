#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX std output.
 * @filename: String representing the name of the file to read.
 * @letters: Number of letters it should read and print.
 *
 * Description: If filename is NULL or cannot be opened or read, the function
 *              will return 0. If write fails or does not write the expected
 *              amount of bytes, the function will return 0.
 *
 * Return: Actual number of letters it could read and print. If the file
 *         can not be opened or read, or if write fails or does not write
 *         the expected amount of bytes, or if malloc fails, the function
 *         should return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd; /* File descriptor */
	ssize_t nrd, nwr; /* Number of bytes read and written */
	char *buf; /* Buffer to hold file content */

	if (!filename) /* Check if filename is NULL */
		return (0);

	fd = open(filename, O_RDONLY); /* Open file */

	if (fd == -1) /* Check if file was opened successfully */
		return (0);

	buf = malloc(sizeof(char) * (letters));
	/* Allocate memory for buffer */
	if (!buf) /* Check if memory was allocated successfully */
		return (0);

	nrd = read(fd, buf, letters); /* Read file content into buffer */
	nwr = write(STDOUT_FILENO, buf, nrd);
	close(fd); /* Close file */

	free(buf); /* Free buffer memory */

	return (nwr); /* Return number of bytes written */
}

