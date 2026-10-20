# Dynamic Memory Allocation
allows programs to request memory to store data. Mostly used when data is of unknown size, for example, user input.
## Functions
stdlib.h - library
1. void *malloc(size_t size);
  - brings back a pointer to a selected type memory
2. void *calloc(size_t num, size_t size);
  - brings back a pointer to a selected type memory
3. void free(void *block);
  - releases previously allocated memory
4. sizeof( data type );
  - brings back selected data type memory size in bytes.

