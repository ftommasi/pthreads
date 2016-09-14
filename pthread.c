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
  int n = atoi(argv[1]);
  struct thread_entry_args arg_array[n];
  int i =0;
  for(i; i<n; i++){
    pthread_t id;
    struct thread_entry_args args;
    args.arg1 = 10;
    args.arg2 = (char*)malloc(246*sizeof(char));
  
    strcpy(args.arg2,"Chris and Fausto\0");
  
    printf("MAIN: arg1 %d arg2 %s\n",args.arg1,args.arg2);
    int create_error= pthread_create(&id,NULL,thread_entry,&args);
    if(create_error != 0){
      printf("ERROR IN CREATE\n") ;
    }

    int join_error= pthread_join(id,NULL);
    if(join_error!=0){
      printf("ERROR IN JOIN\n");
    }
    printf("ret is %d in main\n",args.ret);
    free(args.arg2);
  }
  return 0;
}
