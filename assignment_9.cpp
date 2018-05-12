#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define SPELL_CHECKER

#ifdef SPELL_CHECKER

#define SIZE 10000                /* Number of elements in table */
#define WORD_SIZE 100             /* Max size of word */

typedef struct CHAINELEMENTS
{
    char word[100];               /* word to be saved in list */
    struct CHAINELEMENTS *next;   /* pointer to next element  */
}chainelements;

typedef struct TBLELEMENTS
{
    int total_elements;           /* total elements in chain  - Not used here so far  */
    chainelements *baseelement;   /* Pointer to chained linked list of words */
}tblelements;

typedef struct HASHTABLE
{
    int size;                     /* Number of table elements in hashtable */
    tblelements *base;            /* Pointer to first table element */
}hashtable;


/* 
  Below functions accomplish task as listed
  1. Create HASHTABLE
  2. For given string find its key and hash index
  3. Search the word in hashtable
  4. if word doesnt exist insert the word
 */

hashtable* createHashTable(int size);

int getKey(char *string);

void insertWord(hashtable *phashtable, char *str);

bool searchWord(hashtable *phashtable, char *str);


int main(void)
{
    FILE *fp1;
    char oneword[WORD_SIZE];
    char c;
    char *searchword = "abash";
    bool ispresent;
    hashtable *phashtable = createHashTable(SIZE);

    fp1 = fopen("snippet.txt", "r");

    do
    {
        c = fscanf(fp1, "%s", oneword); /* got one word from the file */
        printf("%s \n", oneword);       /* display it on the monitor  */
        insertWord(phashtable, oneword);
        insertWord(phashtable, oneword);  /* Test code to check insert does not happen again*/

    } while (c != EOF);


    ispresent = searchWord(phashtable, searchword);

    printf("IS the searchword  %s   present  -- %d \n", searchword, ispresent);

    fclose(fp1);
    return 0;
}

/*
    Funcntion    - searchWord(hashtable *phashtable, char *str)
    Input params - pointer to hashtable and word to be searched
    Return value - returns 1 if word is present else 0
    Task         - for given string finds it's hashindex
                   and searches all nodes in that chain to see if
                   word is present
 */
bool searchWord(hashtable *phashtable, char *str)
{
    /* error condition check */
    if (phashtable == NULL || str == NULL)
    {
        fprintf(stderr, " -- invalid pointer to string or hashtable -- \n");
        return false;
    }

    int hashindex = getKey(str);

    /* error condition check */
    if (hashindex > SIZE)
    {
        fprintf(stderr, " -- invalid hashindex -- \n");
        return false;
    }

    /* pointer to first element of the chained linked list */
    chainelements *pchainelements = phashtable->base[hashindex].baseelement;

    while (pchainelements != NULL)
    {
        /* compares the given word with present in node */
        if (!strcmp(pchainelements->word, str))
        {
            return true;
        }
        pchainelements = pchainelements->next;
    }

    return false;
}

/*
    Funcntion    - insertWord(hashtable *phashtable, char *str)
    Input params - pointer to hashtable and word to be inserted
    Return value - none
    Task         - for given string finds it's hashindex
                   and searches all nodes in that chain to see if
                   word is present if it's not present creates a 
                   new node and appends the word at the end of chain
*/
void insertWord(hashtable *phashtable, char *str)
{   
    if (phashtable == NULL || str == NULL)
    {
        return;
    }

    bool ispresent;
    int hashindex = getKey(str);

    if (hashindex > SIZE)
    {
        fprintf(stderr, " -- invalid hashindex -- \n");
        return;
    }

    chainelements *pchainelements = phashtable->base[hashindex].baseelement;

    /* if no elements are present - insert word */
    if (!pchainelements)
    {
        pchainelements = (chainelements *)malloc(sizeof(chainelements));
        if (pchainelements == NULL)
        {
            fprintf(stderr, " -- memory allocation failed for the word -- \n");
        }
        phashtable->base[hashindex].baseelement = pchainelements;
        strcpy(pchainelements->word, str);
        pchainelements->next = NULL;
    }
    else
    {
        /* Check if the word is already present if not insert*/
        ispresent = searchWord(phashtable, str);

        if (ispresent == 0)
        {
            printf("insert word   is not present - so inserting %s \n", str);

            /* Can this part be optimized ?? while searching we already reached
               till the end of loop now again before inserting we have to traverse 
               Another option is to do compare here only but that would result in
               same code present at two point - What is better stratergy ?
             */
            while (pchainelements->next != NULL)
            {
                pchainelements = pchainelements->next;
            }

            pchainelements->next = (chainelements *)malloc(sizeof(chainelements));
            if (pchainelements->next == NULL)
            {
                fprintf(stderr, " -- memory allocation failed for the word -- \n");
            }

            pchainelements = pchainelements->next;
            strcpy(pchainelements->word, str);
            pchainelements->next = NULL;
        }
    }
}

/*
    Funcntion    - getKey(char *string)
    Input params - string for which key is needed
    Return value - Returns the hashindex based on key
    Task         - for given string finds it's key.
                   for key generation a simple multiplcation 
                   is done, no logic used and once key is 
                   generated mod is performed based on size 
                   of hashtable
*/
int getKey(char *string)
{
    unsigned int key = 0;
    char *pstring = string;

    while (*pstring != '\0' && key < ULONG_MAX)
    {
        key += *pstring * 32;
        pstring++;
    }

    key = key % SIZE;

    return key;
} 

/*
    Funcntion    - createHashTable(int size)
    Input params - Table size 
    Return value - pointer to created hashtable
    Task         - hashtable is created based on given
                   size and all the hash table elements are 
                   initialized to NULL
*/

hashtable* createHashTable(int size)
{
    int i;

    /* error condition check */
    if (size < 1 || size > SIZE)
    {
        fprintf(stderr, " invalid size of hashtable suggested exiting ...\n");
        exit(1);
    }

    hashtable *phashtable = (hashtable *)malloc(sizeof(hashtable));

    if (phashtable == NULL)
    {
        fprintf(stderr, "memory allocation failed for hashtable...\n");
    }

    phashtable->size = size;

    if (size > 0)
    {
        phashtable->base = (tblelements *)malloc(sizeof(tblelements) * phashtable->size);

        if (phashtable->base == NULL)
        {
            fprintf(stderr, "memory allocation failed for table elements ... \n");
        }

        for (i = 0; i < size; i++)
        {
            phashtable->base[i].baseelement = NULL;
        }
    }

    return phashtable;
}