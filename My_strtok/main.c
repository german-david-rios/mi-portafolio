#include <stdio.h>
#include <string.h> // for strlen()

// my strtok funcition takes 3 parameters besides the original wich takes 2 an are
char * my_strtokplus(const char * work_str,  const char * tokens_s, int * n);
// work_str : same as the first in strtok, but it's guaranteed to remaind unchange; for NULL it use the inner rem char*.
// tokens_s : an string that has all serched tokens in the working string, they are not take in later NULL calls.
// n : is a pointer to an int value that will be use to return the length of the founded section until the first token.

int main()
{
    char buffer[500], *aux;
    int i = 1, wlen;

    fgets(buffer, sizeof(buffer), stdin);

    puts("input word's:");

    aux = my_strtokplus(buffer," ",&wlen);
    while(aux){
        printf("word #%d: %.*s\n", i++, wlen, aux);
        aux = my_strtokplus(NULL, " ", &wlen);
    }

    printf("complete input: %s\n",buffer);

    return 0;
}

char * my_strtokplus(const char * work_str,  const char * tokens_s, int * n){
    static char * rem = NULL;
    int ret_n = 0;

    if(work_str == NULL){
        if(rem == NULL){
            *n = 0;
            return NULL;
        } else {
            work_str = rem;
        }
    }

    while(work_str[ret_n] != '\0'){
        for(int i = 0; i < (int) strlen(tokens_s); i++){
            if(work_str[ret_n] == tokens_s[i]){
                rem = (char *) work_str+ret_n+1;
                goto outside_while;
            }
        }
        ret_n++;
    }
    outside_while:

    if(work_str[ret_n] == '\0' || *rem == '\0'){
        rem = NULL;
    }

    *n = ret_n;
    return (char *) work_str;
}
