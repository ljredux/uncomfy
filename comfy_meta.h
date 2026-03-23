#ifndef COMFY_META_H
#define COMFY_META_H

#include <stdio.h>

// Public function: extract metadata associated with a key in a comfyUI generated file
// Returns dynamically allocated string (free this!) or NULL if not found
char *get_metadata(const char *filename, const char *key);

#endif