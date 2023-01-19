// AUthor - Ritesh Saha

#ifndef _SPELLER_H_
#define _SPELLER_H_
#define BUFFER_SIZE 50
#include <stdbool.h>

bool load_dictionary(const char *file_path);
bool spell_check(const char *file_path);
bool unload_dictionary(void);

#endif // _SPELLER_H_