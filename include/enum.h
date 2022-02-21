#include "flag.h"

typedef struct Enum Enum;

Enum* new_e (char *names, uint32_t len);
void del_e (Enum* self);

char* getNames_e (Enum *self);
void setNames_e (Enum *self, char *newNames);

void init_e (Enum* self, char* names, uint32_t len);
uint32_t len_e (Enum* self);
uint32_t get_e (Enum* self);
bool is_e (Enum* self, uint32_t aFlag);
void set_e (Enum* self, uint32_t anEnum); 
void set_all_e (Enum* self, void *enums, uint32_t enums_len);
void reset_e (Enum* self, uint32_t anEnum);
void reset_all_e (Enum *self, void *enums, uint32_t enums_len);
void print_e(Enum* self);

typedef struct Enum {
    Flag flag;
    uint32_t __len;
    
    char* (*getNames) (Enum *self);
    void (*setNames) (Enum *self, char *newNames);

    void (*init) (Enum* self, char *names, uint32_t len);
    uint32_t (*len) (Enum* self);
    uint32_t (*get) (Enum* self);
    
    bool (*is) (Enum* self, uint32_t anEnum);
    void (*set) (Enum* self, uint32_t anEnum);
    void (*reset) (Enum* self, uint32_t anEnum);
    
    void (*set_all) (Enum* self, void *enums, uint32_t enums_len); 
    void (*reset_all) (Enum* self, void *enums, uint32_t enums_len);
    
    void (*print) (Enum* self);
} Enum;