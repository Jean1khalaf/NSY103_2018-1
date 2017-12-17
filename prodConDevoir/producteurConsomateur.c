#include "BufferCirc.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define N 10

pthread_mutex_t mutex;
sem_t vide;
sem_t plein;

/** Exercice AFAIRE
 * ajouter l'utilisation des semaphores aux 2 threads
 * 1 producteur
 * 1 consomateur
 * dans le buffer
 * Il y a 2 problèmes a resoudres
 * A: La synchronisation entre producteur et consomateur et la taille du buffer
 * B: La resource critique qui sont les indexs du Buffer (debut,fin et nb)
 */

 // Le buffer un donné globale partagée par tous les threads
struct _buffer_circ *buff;


//---------------------------------------------------------
// test produire et consomer 2 fonctions qui simulent la production de quelques choses
// -------------------------------------------------------
int produire() {
  int res;
  res = rand();
  printf("J'ai produit %d\n", res);
  return res;
}
void consomer(int elem) { printf("Je consome %d\n", elem); }

// Les fonctions (thread) pour simuler les "services" de production et consomation
// Le squelette des 2 threads===============================
/**
 * produire indéfiniment
 * ALGO
 *   produire quelque chose
 *   le déposer dans le buffer
 */
void *producteur(void *args) {
  int data;
  while (1) {
    data = produire();
    sem_wait(&vide);
    pthread_mutex_lock(&mutex);
    ajouterBC(buff, (void *)(intptr_t)data);
    pthread_mutex_unlock(&mutex);
    sem_post(&plein);
  }
}

/**
 * consomer indéfiniment
 * ALGO
 *   recuperer quleue chose du buffer
 *   puis le consomer (ie le traiter)
 */
void *consomateur(void *args) {
  int data;
  while (1) {
      sem_wait(&plein);
      pthread_mutex_lock(&mutex);
      data = (int)(intptr_t)retirer(buff);
      consomer(data);
      pthread_mutex_unlock(&mutex);
      sem_post(&vide);
  }
}
//
// La question! comment savoir que tous les messages produits seront consomés correctement???
// Réponse: D'apres le console, on peut regarder la production et la consomation par ordre
//J'ai produit 470211272
//Je consome 1144108930
//J'ai produit 101027544
//Je consome 470211272
//J'ai produit 1457850878
//Je consome 101027544
//J'ai produit 1458777923
//Je consome 1457850878
//J'ai produit 2007237709
//Je consome 1458777923
//J'ai produit 823564440
//Je consome 2007237709
//J'ai produit 1115438165
//Je consome 823564440
//J'ai produit 1784484492
//==========================================================

/**
 * main : initialisation et lancement des 2 Threads
 */
int main() {
  int i;
  pthread_mutex_init(&mutex, NULL);
  sem_init(&vide, 0 , N);
  sem_init(&plein, 0 , 0);
  // tester le buffer
  buff = newBufferCirc(10);
  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1, 0, producteur, 0);
  pthread_create(&t2, 0, consomateur, 0);

  pthread_join(t1, 0);
  pthread_join(t2, 0);
}
