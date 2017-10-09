#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
    (*argv)=(char**)malloc(100*sizeof(char*));

	int i=0;
	(*argv)[i]=(char*)malloc(100*sizeof(char));
	
	char* str=(char*)malloc((strlen(command)+1)* sizeof(char));
	strcpy(str, command);
	
	char* tok=strtok(str, " \n\t");
	if(tok==NULL){
		*argc=1;
		strcpy((*argv)[0],"");
		return;
	}

	while(tok!=NULL){
		strcpy((*argv)[i],tok);
		i++;
		(*argv)[i]=(char*)malloc(100*sizeof(char));
		tok=strtok(NULL, " \n\t");
	}
	*argc=i;
	return;
}
