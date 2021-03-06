#include "Hashtable.h"
#include "stdlib.h"
#include "LinkedList.h"
#include "bst.h"
//Creates and initializes a new hashtable, with linked lists
Hashtable *newHashtable(int sz, int Threshold) {
    Hashtable* Table = (Hashtable*) malloc(sizeof(Hashtable));
    Table->size = sz;
    Table->table = (void **)calloc(sz , sizeof(void *));
    for(int i = 0; i < Table->size; i++)
    {
        Table->table[i] = (list*)(malloc(sizeof(list)));
    }
    Table->threshold = Threshold;
    Table->aboveThreshold = (int *)calloc(sz, sizeof(int));
    return Table;
};
void insert(Hashtable *t, student* s){
    int index = s->getId().hashValue;
    if(t->aboveThreshold[index] == 0)
    {
        list* add = (list*)t->table[index];
        ListInsert(add, s);
    }
    else{
        BinarySearchTree* add = (BinarySearchTree*)t->table[index];
        insertStudent(add, s);
    }
}
student* search(Hashtable *t, Id* id){
    int index = id->hashValue;
    if(t->aboveThreshold[index] == 0)
    {
        list* add = (list*)t->table[index];
        searchInList(add, id);
    }
    else{
        BinarySearchTree* add = (BinarySearchTree*)t->table[index];
        TreeSearch(add->root, id);
    }
}