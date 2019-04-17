#include <stdio.h>
#include <stdlib.h>

#include "../lib/queue.h"

char *random_string(size_t length) {
    static char charset[] = 
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    char *rs = NULL;

    if (length) {
        rs = malloc((length + 1) * sizeof(char));
        if (rs) {
            for (int n = 0; n < length; n++) {
                int key = rand() % ((int) sizeof(charset) - 1);
                rs[n] = charset[key];
            }

            rs[length] = '\0';
        }
    }
    return rs;
}

int main() {
    q_head *handle = queue.q_init();
    
    char *elems[100];
    for (int i = 0; i < 100; i++) {
        elems[i] = random_string(20);
        queue.put(handle, &elems[i]);
    }
    
    char **mem;
    while ((mem = queue.get(handle)) != NULL) {
        printf("%s\n", *mem);
    }
    
    queue.q_free(handle);
    return 0;
}

