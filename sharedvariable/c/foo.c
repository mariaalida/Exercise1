// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>

int i = 0;
pthread_mutex_t lock;

// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    for (int j=0; j<1000000; j++){
        pthread_mutex_lock(&lock);
        i++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    for (int j=0; j<1000000; j++){
        pthread_mutex_lock(&lock);
        i--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}


int main(){

    pthread_t id[2];
    
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init has failed\n"); 
        return 1;
    }
   
    if (pthread_create(&id[0], 0, incrementingThreadFunction, 0) != 0){
        printf("Error when creating thread 1");
        return 1;
    }

    if (pthread_create(&id[1], 0, decrementingThreadFunction, 0) != 0){
        printf("Error when creating thread 2");
        return 1;
    }

    pthread_join(id[0], NULL);
    pthread_join(id[1], NULL); 
    
    pthread_mutex_destroy(&lock);
    printf("The magic number is: %d\n", i);
    return 0;
}
