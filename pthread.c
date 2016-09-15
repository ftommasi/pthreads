#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct thread_entry_args{
  int arg1;
  char* arg2;
  int ret;
};



void* thread_entry(void* args){
  struct thread_entry_args* my_args = (struct thread_entry_args*) args;
  printf("Hello from thread_entry\n");
  printf("THREAD_ENTRY: arg1 %d arg2 %s\n",my_args->arg1,my_args->arg2);
  printf("Setting ret to 420 in thread_entry\n");
  my_args->ret = 420;
  return NULL;
}

int main(int argc, char** argv){
  unsigned bufSize = 100;
  int n = atoi(argv[1]);
  struct thread_entry_args arg_array[n];
  pthread_t threads[n];
  int i =0;
  for( i = 0; i < n; i++ ){
    pthread_t id;
    struct thread_entry_args args;
    args.arg1 = 10;
    args.arg2 = (char*)malloc(246*sizeof(char));
    arg_array[i] = args;
    threads[i] = id;
    snprintf(arg_array[i].arg2, bufSize, "This is thread %d", i);
    int create_error= pthread_create(threads[i],NULL,thread_entry,&args);
    if(create_error != 0){
      printf("ERROR IN CREATE\n") ;
    }

    int join_error= pthread_join(id,NULL);
    if(join_error!=0){
      printf("ERROR IN JOIN\n");
    }

  }
    //printf("MAIN: arg1 %d arg2 %s\n",args.arg1,args.arg2);
     //  printf("ret is %d in main\n",args.ret);
    //free(args.arg2);
  return 0;
}
