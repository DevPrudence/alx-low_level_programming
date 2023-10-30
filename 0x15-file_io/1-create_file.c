#include "main.h"

/**
 * create_file - creates a file.
 * @filename: name of the file to create.
 * @text_content: a NULL terminated string to write to the file.
 *
 * Description: The created file must have those permissions: rw-------.
 *              If the file already exists, do not change the permissions.
 *              If the file already exists, truncate it.
 *              If filename is NULL return -1. If text_content is NULL create
 *              an empty file.
 *
 * Return: 1 on success, -1 on failure (file can not be created, file can not
 *         be written, write “fails”, etc…)
 */
int create_file(const char *filename, char *text_content)
{
	/* wc1 and wc2 for write count, fp for file pointer */
	int write_count1 = 0, write_count2, file_pointer;

	if (!filename) /* Check if filename is NULL */
		return (-1);

	/* Open or create file with rw------- permissions */
	file_pointer = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (file_pointer < 0) /* Check if file was opened/created successfully */
		return (-1);

	if (text_content) /* Check if text_content is not NULL */
	{
		/* Count number of characters in text_content */
		while (text_content[write_count1])
			write_count1++;

		/* Write text_content to file */
		write_count2 = write(file_pointer, text_content, write_count1);
		if (write_count2 != write_count1) /* Check if write was successful */
			return (-1);
	}

	close(file_pointer); /* Close file */

	return (1); /* Return 1 on success */
}
