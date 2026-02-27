#include <stdio.h>
#include <time.h>

#include <stdlib.h>

struct datanode {
    unsigned char dat;
    unsigned char is;
};

/*
  definicion de la funcion recursiva utilizada:

  recur(0,b) = b%71
  recur(a,255) = recur(a-1,97) + recur(a-1,56) + recur(a,0)
  recur(a,b) = recur(a-1,b+1)

 */

unsigned char RecurwMem(unsigned char A, unsigned char B, struct datanode ** mem){
    unsigned char aux;

    putchar('+');
    if(mem[A][B].is == 0){
        putchar('R');
        if(A == 0) aux = B % 71;
        else if (B == 255) aux = RecurwMem(A-1,97,mem) + RecurwMem(A-1,56,mem) + RecurwMem(A,0,mem);
        else aux = RecurwMem(A-1,B+1,mem);

        mem[A][B].is = 1;
        mem[A][B].dat = aux;
        return aux;
    } else {
        putchar('T');
        return mem[A][B].dat;
    }
}
//
int main()
{
    FILE * values = fopen("values.bin","rb"), * dataf = fopen("DATA","r+b");

    struct {
        unsigned char a,b;
    } pos;
    unsigned char result;
    struct datanode ** DATA = calloc(256,sizeof(struct datanode *)); // data[a][b] = Recur(a,b)
    for(int i = 0; i < 256 ; i++){
        DATA[i] = calloc(256, sizeof(struct datanode));
    }

    unsigned long long cntr = 0;

    if(values == NULL){
        puts("no values file");
        if(dataf == NULL){
            puts("no data file");
            return 0;
        } else {
            puts("closing data file");
            fclose(dataf);
            return 0;
        }
    }

    if(dataf == NULL){
        dataf = fopen("DATA","w");
        if(dataf == NULL){
            puts("failure . .");
            fclose(values);
            return 0;
        }
    } else {
        fseek(dataf,0,SEEK_SET);
        for(int b = 0, a = 0; a<256; b++, a+=(b>=256), b%=256){
            fread(&DATA[a][b],sizeof(struct datanode),1,dataf);
        }
    }

    fseek(values,0,SEEK_SET);

    fread(&pos,sizeof(pos),1,values);

    while(feof(values) == 0){

        printf("{%llu} [%u , %u] -> ",cntr,pos.a,pos.b); cntr++;
        result = RecurwMem(pos.a,pos.b,(struct datanode **)DATA);

        printf(" -> %u\n", result);

        fread(&pos,sizeof(pos),1,values);
    }

    printf("listo \a\n");

    fclose(values);

    fseek(dataf,0,SEEK_SET);
    for(int b = 0, a = 0; a<256; b++, a+=(b>=256), b%=256){
        fwrite(&DATA[a][b],sizeof(struct datanode),1,dataf);
    }
    fclose(dataf);

    for(int i = 0; i < 256 ; i++){
        free(DATA[i]);
    }
    free(DATA);

    return 0;
}
//*/








