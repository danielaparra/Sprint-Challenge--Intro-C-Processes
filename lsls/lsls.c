#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Create variables for opening and reading directory.
  char *dirname;
  DIR *dp
  struct dirent *d
  struct stat fileinfo;

  // Parse command line.
  // If user didn't input a directory, use ".".
  if (argc == 0) {
    dirname = ".";
  // Otherwise try opening directory that use specified.
  } else if (argc == 1) {
    // Grab second argument that user inputted.
    dirname = argv[1];
  // If command line arguments not in the right format, present error to user.
  } else {
    dirname = NULL;
    printf("Error. Not the right format. Try: './lsls DIRECTORY_NAME' or './lsls'");
  }

  // Open directory
  // Check if dirname and directory for dirname equal NULL.
  if (dirname != NULL && dp = opendir(dirname) != NULL) {
    
  // If can't open directory, present error.
  } else {
    printf("Error: Unable to open directory. Could be spelling or case error.\n");
    exit(0);
  }

  // Repeatly read and print entries

  // Close directory

  return 0;
}