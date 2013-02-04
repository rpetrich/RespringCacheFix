#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

#define MATCHES_BAD_FILENAME(string, bad_filename) (memcmp(next_file->d_name, bad_filename, sizeof(bad_filename) - 1) == 0)

__attribute__((constructor))
static void everybody_everywhere(void) {
	DIR* dir;
	struct dirent *next_file;
	if(!(dir = opendir("/var/tmp/"))) {
		// Unable to read :(
		return;
	}
	
	while ((next_file = readdir(dir))) {
		const char *filename = next_file->d_name;
		size_t length = strlen(filename);
		if (length >= 17) {
			if (MATCHES_BAD_FILENAME(filename, "gridImages.") || MATCHES_BAD_FILENAME(filename, "iconImages.") || MATCHES_BAD_FILENAME(filename, "ghostlyIcons.") || MATCHES_BAD_FILENAME(filename, "iconLabels_gray.")) {
				char buffer[length + 10];
				memcpy(buffer, "/var/tmp/", 9);
				memcpy(&buffer[9], filename, length + 1);
				unlink(buffer);
			}
		}
    }
	
	closedir(dir);
}