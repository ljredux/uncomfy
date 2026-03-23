#include "comfy_meta.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static bool is_png(FILE *fp);
static char *extract_from_png(FILE *fp, const char *key);
static char *extract_from_mp4(FILE *fp, const char *key);

// Main public function
char *get_metadata(const char *filename, const char *key) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    char *result = NULL;

    if (is_png(fp)) {
        result = extract_from_png(fp, key);
    } else {
        // Assume MP4
        rewind(fp);
        result = extract_from_mp4(fp, key);
    }

    fclose(fp);
    return result;
}

static bool is_png(FILE *fp) {
    unsigned char sig[8];

    long pos = ftell(fp);

    // Read and check file signature
    if (fread(sig, 1, 8, fp) != 8) {
        fseek(fp, pos, SEEK_SET);
        return false;
    }
    static const unsigned char png_sig[8] = {137, 80, 78, 71, 13, 10, 26, 10};
    bool result = (memcmp(sig, png_sig, 8) == 0);

    fseek(fp, pos, SEEK_SET);

    return result;
}

// Placeholder methods
static char *extract_from_png(FILE *fp, const char *key) {
    (void)fp;
    (void)key;

    printf("It's a PNG!");
    return NULL;
}

static char *extract_from_mp4(FILE *fp, const char *key) {
    (void)fp;
    (void)key;
    return NULL;
}