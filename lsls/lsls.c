#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Create variables for opening and reading directory.
  char *dirname = malloc(sizeof(char) * 30);
  DIR *dp = NULL;
  struct dirent *d;
  struct stat fileinfo;

  // Parse command line.
  // If user didn't input a directory, use ".".
  if (argc == 1) {
    strcpy(dirname, ".");
  // Otherwise try opening directory that use specified.
  } else if (argc == 2) {
    // Grab second argument that user inputted.
    strcpy(dirname, argv[1]);
  // If command line arguments not in the right format, present error to user.
  } else {
    dirname = NULL;
    printf("Error. Not the right format. Try: './lsls DIRECTORY_NAME' or './lsls'\n");
  }

  // Open directory
  // Check if dirname and directory for dirname equal NULL.
  if ((dirname != NULL) && ((dp = opendir(dirname)) != NULL)) {

    // Repeatly read and print entries
    // Loop through all directory entries until yoxu reach the end (NULL).
    while((d = readdir(dp)) != NULL) {
      
      // Copy dirname to build path to file name.
      char *copydirname = malloc(sizeof(char) * 30);
      strcpy(copydirname, dirname);
      // Add slash between directory and file name.
      copydirname[strlen(copydirname)] = '/';
      // Create path to file name.
      char *path = strcat(copydirname, d->d_name);

      // Use stat to find file info for each file name path from directory entry.
      if(!stat(path, &fileinfo)) {

        // Print file size and file name with left and right alignments.
        printf("%10lld %-14s\n", fileinfo.st_size, d->d_name);
      
      // Present no fileinfo error for file name to user.
      } else {
        printf("No fileinfo for file: %s\n", d->d_name);
      }
    }

  // If can't open directory, present error.
  } else {
    printf("Error: Unable to open directory.\nCould be directory doesn't exist or was spelled incorrectly(case sensitive).\n");
  }

  // Close directory
  closedir(dp);
  free(dirname);

  return 0;
}