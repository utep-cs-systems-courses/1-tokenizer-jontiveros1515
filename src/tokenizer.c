#include "tokenizer.h"
#include "stdio.h"
#include "stdlib.h"
#include "history.h"


// Function returns true if char is space, tab, or null

int space_char(char c){
  if (( c == ' ' || c == '\t') && c != '\0') return 1;

  return 0;
}



// Function returns true if char is not a space, tab, or null

int non_space_char(char c){
  if ( c == ' ' || c == '\t' || c == '\0') return 0;

  return 1;
}

char *word_start(char *str){

  while(non_space_char(*str) != 1){

    if(*str=='\0') {return NULL;}

    *str++;

  }

  //printf("%c", *str);

  return str;

}



char *word_terminator(char *word){

  if(*word == '\0') {return NULL;}

  while(non_space_char(*word) == 1){

    *word++;

  }

  //printf(" T-%c ",*word);

  return word;

}

int count_words(char *str){

  int cnt =0;

  while( str )

    {

      //print]f("%d",cnt);

      str =word_start(str);

      if(str){

	cnt++;

	str =word_terminator(str);

      }

      else{ break;}

    }

  //printf("\n");

  return cnt-1;

}


char *copy_str(char *inStr, short len) {



  char *newStr = malloc((len+1) *sizeof(char));

  if (newStr == NULL) {return NULL;}

  for(int i = 0; i<= len; i++)

    {

      newStr[i] = inStr[i];

    }

  newStr[len+1] = '\0';

  return newStr;

}

char **tokenize(char *str){

  int i = 0;

  int WC = count_words(str);

  char** tokens = malloc((WC+1) * sizeof(char*));

  if (tokens == NULL) {return NULL;}

  char** token_pointer = tokens;

  char* start = str;

  char* end = str;

  while (i < WC ) {

    start = word_start(end);

    //printf("start\n");

    end = word_terminator(start);

    //printf("end\n");



    *token_pointer = copy_str(str, end-start);

    //printf(token_pointer);

    *token_pointer++;

    i++;

  }

  *token_pointer = '\0';

  return tokens;

}
void print_tokens(char **tokens)



{



  int i;



  for (i = 0; tokens[i] != 0; i++) {



    printf("\nTokens[%d] : %s\n", i, tokens[i]);



  }



}







// Frees the memory allocated for an array of tokens



void free_tokens(char **tokens)



{



  char **temp = tokens;

  while (*temp != NULL) {

    free(temp);

    temp++;

  }

  free(tokens);

}
