#include <stdio.h>
#include <stdlib.h>

#include "../lib/queue.h"

int main() {
    /* Create queue */
    q_head *handle = queue.q_init();
    
    /* Put stuff into queue */
    int elems[101];
    for (int i = 0; i <= 100; i++) {
        elems[i] = i;
        queue.put(handle, &elems[i]);
    }
    
    /* Print stuff from queue */
    int *mem;
    while ((mem = queue.get(handle)) != NULL) {
        printf("%d, ", *mem);
    }
    printf("\n");
    
    /* free queue */
    queue.q_free(handle);
    
    return 0;
}

