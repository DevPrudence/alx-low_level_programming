#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of the file to append the text to.
 * @text_content: NULL terminated string to append to the file.
 *
 * Description: If filename is NULL return -1. If text_content is NULL, do not
 *              add anything to the file. Return 1 if the file exists and -1 if
 *              the file does not exist or if you do not have the required
 *              permissions to write to the file.
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int write_count1 = 0, write_count2, file_pointer;
	/* wc1 and wc2 for write count, fp for file pointer */

	if (!filename) /* Check if filename is NULL */
		return (-1);

	/* Open file in append mode */
	file_pointer = open(filename, O_WRONLY | O_APPEND);
	if (file_pointer < 0) /* Check if file was opened successfully */
		return (-1);

	if (text_content) /* Check if text_content is not NULL */
	{
		while (text_content[write_count1])
			/* Count number of characters in text_content */
			write_count1++;

		/* Write text_content to end of file */
		write_count2 = write(file_pointer, text_content, write_count1);
		if (write_count2 != write_count1) /* Check if write was successful */
			return (-1);
	}

	close(file_pointer); /* Close file */

	return (1); /* Return 1 on success */
}
