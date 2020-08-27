/* CS 265 Assignment 3
 Man Yi (Ariel) Yeung*/

#include <stdio.h>
#include <string.h>

void delnewline(char* s);
int foo(char* s);
int eep(char* s);
int op(char* s);
int ork(char* s);

int main(int argc, char **argv)
{
    FILE *fp=stdin;
    char text[100];
    int len;
	if (argc == 2){
		fp=fopen(argv[1],"r");
		if (fp == NULL){
			printf("File cannot be opened.\n");
			return -1;
		}
	}
	if (argc > 2){
	   printf("Wrong number of arguments.\n");
	   return -1;
	}
	
	while (fgets(text,sizeof(text),fp)!=NULL){
	   len=strlen(text);
	   while (text[len-1]=='\n' || text[len-1]==' ' || text[len-1]=='\t'){				/*remove any trailing whitespace*/
		  text[len-1]='\0';
		  len=strlen(text);
	   }
	   if (strlen(text)>0){				/*check for non-empty string*/
		  printf("%s ",text);
		  if (foo(text) || eep(text) || op(text) || ork(text)){
				printf("OK\n");
			}else{
			 	printf("Failed\n");
			}	
	   }
	}
		return 0;
}

int foo(char* s){
   if (strncmp(&s[0],"E",1)==0){                 /*first is E*/
	  memmove(s,s+1,strlen(s));
	  if ( strncmp(&s[0],"0",1)!=0 && strncmp(&s[0],"1",1)!=0 && strncmp(&s[0],"2",1)!=0){		/*next is 0,1,2*/
			return 0;
			}
	  while (strncmp(&s[0],"0",1)==0 || strncmp(&s[0],"1",1)==0 || strncmp(&s[0],"2",1)==0){	/*repeating 0,1,2*/
		 memmove(s,s+1,strlen(s));
		 }
	  if (strncmp(&s[0],"F",1)==0){				/*last is F*/
		 memmove(s,s+1,strlen(s));
		 if (strlen(s)==0){	
		 	return 1;
	    	}
	  }
	}
    return 0;
}

int eep(char* s){
   if (strncmp(&s[0],"P",1)==0){				/*first is P*/ 
		memmove(s,s+1,strlen(s));
		if (strlen(s)==0){						/*if P only*/
		  return 1;
	   }
	   while (strncmp(&s[0],"B",1)==0 || strncmp(&s[0],"C",1)==0){			/*B or C*/
		  if (strncmp(&s[0],"B",1)==0){			/*next is B*/
			 memmove(s,s+1,strlen(s));
		  	if (strncmp(&s[0],"C",1)==0){		/*C after B*/
			   memmove(s,s+1,strlen(s));
			   if (strlen(s)==0){			
				  return 1;
				 }
		  	}
		  }
	   }
	}
	   return 0;
}

int op(char* s){
   if (strncmp(&s[0],"Q",1)==0){				/*first is Q*/ 
	  memmove(s,s+1,strlen(s));
	  while (strncmp(&s[0],"6",1)==0 || strncmp(&s[0],"7",1)==0){			/*6 or 7*/
	  		while (strncmp(&s[0],"6",1)==0){				/*repeating 6*/ 
	  			memmove(s,s+1,strlen(s));
			}
	  		if (strncmp(&s[0],"7",1)==0){				/*next is 7*/ 
	  			memmove(s,s+1,strlen(s));
				if (strlen(s)==0){						/*last is 7*/
			   		return 1;
				}		
	  			while (strncmp(&s[0],"6",1)==0){				/*repeating 6*/ 
	  				memmove(s,s+1,strlen(s));
					if (strlen(s)==0){					/*last is 6*/
					   return 1;
					}
				}	
				if (strncmp(&s[0],"7",1)==0){			/*7 after 7*/
					 memmove(s,s+1,strlen(s));
				}
			}
	  	}
   }	  
	  return 0;
}

int ork(char* s){
	if (strncmp(&s[0],"M",1)==0){				/*first is M*/ 
		memmove(s,s+1,strlen(s));
		if ( s[0] >= '0' && s[0] <= '9' ){		/*second is decimal*/
			memmove(s,s+1,strlen(s));
			if ( s[0] >= '0' && s[0] <= '9' ){	/*third is decimal*/
				memmove(s,s+1,strlen(s));
	   			if (foo(s) || eep(s)){			/*rest follows foo or eep*/
				   return 1;
				}
			}
		}
	}
   return 0;
}
