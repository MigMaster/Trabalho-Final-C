#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//pthread_mutex_t trava;

int num_threads;
int num;
int resultado=1;

void *calcular_fatorial(void *arg) {
    int *id = (int *)arg;
    int ini = (*id * num) / num_threads + 1;
    int fim = ((*id + 1) * num) / num_threads;
    int resultado_local = 1;
    for (int i = ini; i <= fim; i++) {
        resultado_local *= i;
    }
    resultado *= resultado_local;
    pthread_exit(NULL);
}

int main() {
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &num);
    printf("Digite o número de threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];
    int ids[num_threads];
    for (int i = 0; i < num_threads; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, calcular_fatorial, (void *)&ids[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("%d! = %d\n", num, resultado);
    return 0;
}
