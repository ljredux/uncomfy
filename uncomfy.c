#include "comfy_meta.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

// Minimal cross-platform C rewrite in progress...

const char *get_basename(const char *argv0) {
    const char *name = strrchr(argv0, '/');
#ifdef _WIN32
    if (!name) name = strrchr(argv0, '\\');
#endif
    return name ? name + 1 : argv0;
}

void show_usage(const char *argv0) {
    printf("Usage: %s <file>\n", get_basename(argv0));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        show_usage(argv[0]);
        return 1;
    }

    struct stat st;
    if (stat(argv[1], &st) != 0 || !S_ISREG(st.st_mode)) {
        printf("Error: File '%s' does not exist or is not a regular file.\n", argv[1]);
        show_usage(argv[0]);
        return 1;
    }

    char *metadata = get_metadata(argv[1], "workflow");
    if (metadata) {
        printf("%s\n", metadata);
        free(metadata);
    }
    // TODO: finish the program 😏

    return 0;
}