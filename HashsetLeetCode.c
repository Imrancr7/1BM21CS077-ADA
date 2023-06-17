#define hashvalue 1000000;
typedef struct {
    int set[1000000];
   
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet *ptr=malloc(sizeof(MyHashSet));
    return ptr;
}

void myHashSetAdd(MyHashSet* obj, int key) {
  int bucketvalue=key%hashvalue;

 
  obj->set[bucketvalue]=key;

}

void myHashSetRemove(MyHashSet* obj, int key) {
   int bucketvalue=key%hashvalue;
   

      obj->set[bucketvalue]=NULL;
  
 
  

}

bool myHashSetContains(MyHashSet* obj, int key) {
  int bucketvalue=key%hashvalue;

  if(obj->set[bucketvalue]==key){
      return true;
  }
 
else
  return false;

}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}
