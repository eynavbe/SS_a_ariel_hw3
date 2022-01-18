#include "stringClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT 1024
#define WORD 30

int main(){
    char * wordS;
    char charToWordS;
    char charToTxtS;
    char * txtS;
    wordS = (char*)malloc(WORD*sizeof(char));
    if(wordS==NULL) printf("error\n"); 
    txtS = (char*)malloc(TXT*sizeof(char));
    if(txtS==NULL) printf("error\n"); 
    scanf("%c", &charToWordS);
    int i = 0;
    while (charToWordS != '\n' && charToWordS != '\t' && charToWordS != ' ' && i < WORD){
        *(wordS+i) = charToWordS;
        i++;
        scanf("%c", &charToWordS);
    }
    scanf("%c", &charToTxtS);
    i = 0;
    while (charToTxtS != '~' && i < TXT){
         *(txtS+i) = charToTxtS;
        i++;
        scanf("%c", &charToTxtS);
    }
    char* gematriaSequencesW = gematriaSequences(wordS,txtS);
    printf("Gematria Sequences: %s\n", gematriaSequencesW);

    char* atbashSequencesW = atbashSequences(wordS,txtS);
    printf("Atbash Sequences: %s\n",atbashSequencesW);

    char* anagramSequencesW = anagramSequences(wordS,txtS);
    printf("Anagram Sequences: %s",anagramSequencesW); 
    
}