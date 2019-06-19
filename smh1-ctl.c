 /* shm2-ctl.c */ 
 #include <stdio.h> 
 #include <unistd.h> 
 #include <sys/ipc.h> 
 #include <sys/shm.h> 
 #include <sys/types.h>
  #define  KEY_NUM     773500 
  #define  MEM_SIZE    1024
  int main(void) { 
	  int    shm_id; 
	  void  *shm_addr; 
	  struct shmid_ds shm_info;
	  if( -1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT|0666))) {
		  printf( ".....gksrmf\n");
		  return -1; 
		  }  
	  else { 
		  printf( ".. ... .. ..\n");
		  }   
	  if((void *)-1 == (shm_addr = shmat(shm_id, (void *)0, 0))) {
		  printf( ".. ... .. ..\n"); 
		  return -1; 
		  }   
	  else { 
		  printf( ".. ... .. ..\n");
		  } 
	  if( -1 == shmctl(shm_id, IPC_STAT, &shm_info)) {
		  printf( ".. ... .. .... .......\n"); 
		  return -1;
		  }
	  printf( ".. .... .... ..... .. : %ld\n", shm_info.shm_nattch);
	  if( -1 == shmdt(shm_addr)) {
		  printf( ".. ... .. ..\n"); 
		  return -1;
		  } 
	  else { 
		  printf( ".. ... .. ..\n");
		  }
	  if( -1 == shmctl(shm_id, IPC_RMID, 0)) { 
		  printf( ".. ... .. ..\n");
		  return -1; 
		  } 
	  else { 
		  printf( ".. ... .. ..\n");
		  }
	  return 0; 
	  }
