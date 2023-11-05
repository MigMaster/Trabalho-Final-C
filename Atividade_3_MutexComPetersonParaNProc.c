#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>

//Demonstração da Solução de Peterson utilizando o pthread_mutex como base, para N processos desejando utilizar a região crítica.
int* flag;
int turn;
const int MAX = 1e9;
int ans = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Função para trancar
void lock(int self) {
    pthread_mutex_lock(&mutex);
    flag[self] = 1;
    turn = self;
    int i;
    for (i = 0; i < MAX; i++) {
        if (turn != self) {
            flag[self] = 0;
            while (turn != self);
            flag[self] = 1;
        }
    }
}

//Função para destrancar
void unlock(int self) {
    flag[self] = 0;
    pthread_mutex_unlock(&mutex);
}

//Função de trabalho
void* func(void* s) {
    int i = 0;
    intptr_t self = (intptr_t)s;
    printf("Esta é a thread: %ld\n", self);
    lock(self);
    for (i = 0; i < MAX; i++)
        ans++;
    unlock(self);
}

int main() {
    int n = 5; // número de threads. Também é possível implementar de maneira que o programa requisite ao usuário o número de threads para o teste, caso deseje.
    pthread_t threads[n];
    flag = malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
        flag[i] = 0;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < n; i++)
        pthread_create(&threads[i], NULL, func, (void*)(intptr_t)i);
    for (i = 0; i < n; i++)
        pthread_join(threads[i], NULL);
    printf("Contagem feita: %d | Contagem esperada: %d\n", ans, MAX * n);
    return 0;
}