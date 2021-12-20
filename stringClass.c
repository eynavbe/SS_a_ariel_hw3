#include "StringClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define True 1
#define False 0

//Calculates the gematric value of a word
int gematricWord(char* wordS){
    int sumGematricWord = 0;
    while (*wordS != '\0'){ 
            int gematricChar = ((int) *(wordS))-64;
            if (gematricChar > 26 || gematricChar < 1)
            {
                gematricChar = gematricChar -32;
                if (gematricChar < 1 || gematricChar > 26)
                {
                    gematricChar = 0;
                } 
            }        
        sumGematricWord += gematricChar;
        wordS++;
    }
    return sumGematricWord;
}

//Checks if the gematric value of a character is 0 
//True - charToCheck gematric value is 0 else False
bool checksIfGematricCharIs0 (char *charToCheck){
    int gematricChar = ((int) (*charToCheck))-64;
        if (gematricChar > 26 || gematricChar < 1)
        {
            gematricChar = gematricChar -32;
            if (gematricChar < 1 || gematricChar > 26)
            {
                gematricChar = 0;
            } 
        }
    if (gematricChar == 0)
    {
        return True;
    }
    return False;
}

//Returns all the minimum sequences in a text with the same gematria value as the value of the word captured
char* gematriaSequences(char* wordS, char* txtS){
    int sumGematricWord = gematricWord(wordS);
    char*gematriaSequencesW = (char*)malloc(sizeof(char)*strlen(txtS)); 
    if(gematriaSequencesW==NULL) printf("error\n"); 
    char * copyTxtS = (char*)malloc(sizeof(char)*strlen(txtS)); 
    if(copyTxtS==NULL) printf("error\n"); 
    strcpy(copyTxtS, txtS);
    char * pointerCopyTxtS = copyTxtS;    
    for (int i = 0; i < strlen(copyTxtS); i++)
    {
        for (int j = i; j < strlen(copyTxtS); j++)
        {
            char txtSHelped[(j-i+1)];
            memcpy(txtSHelped, &copyTxtS[i], (j-i+1));
            txtSHelped[(j-i+1)] = '\0';
            if (gematricWord(txtSHelped) == sumGematricWord && !checksIfGematricCharIs0(&txtSHelped[0]) && !checksIfGematricCharIs0(&txtSHelped[strlen(txtSHelped)-1]))
            {
                if (strlen(gematriaSequencesW) > 0)
                {
                    char f = '~';
                    strncat(gematriaSequencesW, &f, 1);
                }
                strcat(gematriaSequencesW,txtSHelped);
            } 
        }
        copyTxtS = pointerCopyTxtS;

    }
    return gematriaSequencesW;
}

//returns the word hatbash
char hatbash(char charToReplace){
    int asciiChar = ((int) charToReplace);
    char charHatbash = charToReplace;
    if (((int) 'A' <= asciiChar ) && ((int) 'Z' >= asciiChar))
        {
            if (asciiChar-'A' <= 12)
            {
                charHatbash = 'A' + (25 -(asciiChar - 'A'));
            }else{
                charHatbash = 'Z' - (25 -('Z' - asciiChar));
            } 
        }else{
            if (((int) 'a' <= asciiChar ) && ((int) 'z' >= asciiChar))
            {
                if (asciiChar-'a' <= 12)
                {
                    charHatbash = 'a' + (25 -(asciiChar - 'a'));
                }else{
                    charHatbash = 'z' - (25 -('z' - asciiChar));
                } 
            }else{
            }
        }
    return charHatbash;
}

//All the minimal sequences in the text, so that ignoring blank characters, are identical to the word or the opposite in hatbash writing.
char* atbashSequences(char* wordS, char* txtS){
    char*atbashSequencesW = (char*)malloc(sizeof(char)*strlen(txtS)); 
    if(atbashSequencesW==NULL) printf("error\n"); 
    while (*atbashSequencesW != '\0'){atbashSequencesW++;}
    char * copyTxtS = (char*)malloc(sizeof(char)*strlen(txtS)); 
    if(copyTxtS==NULL) printf("error\n"); 
    while (*copyTxtS != '\0'){copyTxtS++;}
    strcpy(copyTxtS, txtS);
    char * pointerCopyTxtS = copyTxtS;
    for (int i = 0; i < strlen(copyTxtS); i++)
    {
        char*wordHatbashTxt = (char*)malloc(sizeof(char)*strlen(copyTxtS)); 
        if(wordHatbashTxt==NULL) printf("error\n"); 
        while (*wordHatbashTxt != '\0'){wordHatbashTxt++;}
        char*wordHatbashReverse = (char*)malloc(sizeof(char)*strlen(copyTxtS)); 
        if(wordHatbashReverse==NULL) printf("error\n"); 
        while (*wordHatbashReverse != '\0'){wordHatbashReverse++;}
        char*wordTxt = (char*)malloc(sizeof(char)*strlen(copyTxtS)); 
        if(wordTxt==NULL) printf("error\n"); 
        while (*wordTxt != '\0'){wordTxt++;}
        char*wordReverse = (char*)malloc(sizeof(char)*strlen(copyTxtS));
        if(wordReverse==NULL) printf("error\n"); 
        while (*wordReverse != '\0'){wordReverse++;}
        bool break1 = False;
        bool break2 = False; 
        for (int j = i; j < strlen(copyTxtS); j++)
        {
            char charTxt = copyTxtS[j];
            char charReverse = copyTxtS[strlen(copyTxtS)-j-1];
            char charHatbashTxt = hatbash(charTxt);
            char charHatbashReverse = hatbash(charReverse);
            if (((charHatbashTxt == charTxt) && (i == j))){break1 = True;}
            if (!break1)
            {
                strncat(wordHatbashReverse,&charTxt,1);
                if (charHatbashTxt != charTxt)
                {
                    strncat(wordHatbashTxt, &charHatbashTxt , 1);
                }
                if ((strcmp(wordHatbashTxt,wordS) == 0) )
                {
                    if (strlen(atbashSequencesW) > 0)
                    {
                        char f = '~';
                        strncat(atbashSequencesW, &f, 1);
                    }
                    strcat(atbashSequencesW,wordHatbashReverse);
                    break1 = True;
                }
            }
            if ((((charHatbashReverse == charReverse) && (i == j)))){break2 = True;}
            if (!break2)
            {
                strncat(wordReverse,&charReverse,1);
                if (charHatbashReverse != charReverse)
                {
                    strncat(wordTxt, &charHatbashReverse , 1);
                }
                if (strcmp(wordTxt,wordS) == 0)
                {
                    if (strlen(atbashSequencesW) > 0)
                    {
                        char f = '~';
                        strncat(atbashSequencesW, &f, 1);
                    }
                    char * wordReverseCopy =(char*) malloc(sizeof(char)*strlen(wordReverse));
                    if(wordReverseCopy==NULL) printf("error\n"); 
                    while (*wordReverseCopy != '\0'){wordReverseCopy++;}
                    for(int k = 0; k< strlen(wordReverse); k++){
                        char r = wordReverse[strlen(wordReverse) - k - 1];
                        strncat(wordReverseCopy,&r,1);
                    }
                    strcat(atbashSequencesW,wordReverseCopy);
                    if ( *wordReverseCopy != '\0'){free(wordReverseCopy);}
                    break2 = True;
                }
            }   
        }
        if ( *wordHatbashReverse != '\0'){free(wordHatbashReverse);}
        if ( *wordReverse != '\0'){free(wordReverse);}
        copyTxtS = pointerCopyTxtS;
    }
    if ( *pointerCopyTxtS != '\0'){free(pointerCopyTxtS);}
    return atbashSequencesW; 
}

//return All the minimal sequences in the text that consist of the characters of the recorded word and only blank characters.
char* anagramSequences(char* wordS, char* txtS){
    char*pointerWordS = wordS;    
    char*copyTxtS = (char*) malloc(sizeof(char)*(strlen(txtS)));
    if(copyTxtS==NULL) printf("error\n"); 
    char*anagramSequencesW = (char*) malloc(sizeof(char)*(strlen(txtS)));
    if(anagramSequencesW==NULL) printf("error\n"); 
    while (*anagramSequencesW != '\0'){anagramSequencesW++;}
    strcpy(copyTxtS, txtS);
    char * pointerCopyTxtS = copyTxtS;
    for (int i = 0; i < strlen(copyTxtS); i++)
    {
        char*wordSHelped = (char*) malloc(sizeof(char)*(strlen(wordS)));
        if(wordSHelped==NULL) printf("error\n"); 
        strcpy(wordSHelped, wordS);
        char*wordHatbashReverse =(char*)malloc(sizeof(char)*strlen(copyTxtS));
        if(wordHatbashReverse==NULL) printf("error\n"); 
        while (*wordHatbashReverse != '\0'){wordHatbashReverse++;}
        for(int j = i ; j< strlen(copyTxtS); j++){
            int  charOfTxtS =((int) copyTxtS[j]);
            if (charOfTxtS != ' ')
            {
                char * pointerOfChar = strchr(wordSHelped, charOfTxtS);
                if (pointerOfChar != NULL)
                {
                    strncat(wordHatbashReverse, &copyTxtS[j], 1);
                    int position = pointerOfChar - wordSHelped;
                    memmove(&wordSHelped[position], &wordSHelped[position + 1], strlen(wordSHelped) - position);
                }else{break;}
                
            }else{
                if (i == j){break;}
                else{
                   strncat(wordHatbashReverse, &copyTxtS[j], 1); 
                }
                
            }
            if (strlen(wordSHelped) == 0)
                {
                    if (strlen(anagramSequencesW) > 0)
                    {
                        char f = '~';
                        strncat(anagramSequencesW, &f, 1);
                    }
                    strcat(anagramSequencesW,wordHatbashReverse);
                    break;
                }
        }
        if ( *wordSHelped != '\0'){free(wordSHelped);}
        copyTxtS = pointerCopyTxtS;
        wordS = pointerWordS;
    }
    if ( *pointerCopyTxtS != '\0'){free(pointerCopyTxtS);}
    return anagramSequencesW;
}