#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int MIN_LEN = 2;
int MAX_LEN = 10;

long long try = 0;
int catched = 0;

int main(int argc, char** argv) {
    if(argc == 1) return 0;

    char* password = argv[1];
    int pwlen = strlen(password);

    // lowercase test
    /*
    for(int len=MIN_LEN; len<=MAX_LEN && !catched; len++) {
        char* bfpw = (char*)malloc(sizeof(char)*len);
        for(int i=0; i<len; i++) bfpw[i] = 97;  // start from 'a'
        bfpw[len] = 0;

        while(bfpw[len-1] != 123 && !catched) {
            try++;

            if(strcmp(password, bfpw) == 0) {
                printf("catched! tried %lld\n", try);
                catched = 1;
            }

            bfpw[0]++;
            for(int i=0; i<len; i++) {
                if(bfpw[i] == 123 && i != len-1) {
                    bfpw[i+1]++;
                    bfpw[i] = 97;
                }
            }
        }
    }
    if(!catched) printf("not lowercase only, trying lowercase+number\n");
    */

    // lowercase & number test
    for(int len=MIN_LEN; len<=MAX_LEN && !catched; len++) {
        printf("trying lower&number with length %d\n", len);

        char* bfpw = (char*)malloc(sizeof(char)*len);
        for(int i=0; i<len; i++) bfpw[i] = 48; // start from '0'
        bfpw[len] = 0;

        while(bfpw[len-1] != 123 && !catched) {
            try++;
            // printf("%s\n", bfpw);

            if(strcmp(password, bfpw) == 0) {
                printf("catched! tried %lld\n", try);
                catched = 1;
            }

            bfpw[0]++;
            for(int i=0; i<len; i++) {
                if(bfpw[i] == 123 && i != len-1) {
                    bfpw[i+1]++;
                    bfpw[i] = 48;
                }
                if(bfpw[i] == 58) bfpw[i] = 97; // jump from num to lower
            }
        }
    }
    if(!catched) printf("not lower&number, trying lower&upper&number\n");

    // lowercase & uppercase & number test
    for(int len=MIN_LEN; len<=MAX_LEN && !catched; len++) {
        printf("trying lower&upper&number with length %d\n", len);

        char* bfpw = (char*)malloc(sizeof(char)*len);
        for(int i=0; i<len; i++) bfpw[i] = 48; // start from '0'
        bfpw[len] = 0;

        while(bfpw[len-1] != 123 && !catched) {
            try++;
            // printf("%s\n", bfpw);

            if(strcmp(password, bfpw) == 0) {
                printf("catched! tried %lld\n", try);
                catched = 1;
            }

            bfpw[0]++;
            for(int i=0; i<len; i++) {
                if(bfpw[i] == 123 && i != len-1) {
                    bfpw[i+1]++;
                    bfpw[i] = 48;
                }
                if(bfpw[i] == 58) bfpw[i] = 65; // jump from num to upper
                if(bfpw[i] == 91) bfpw[i] = 97; // jump from upper to lower
            }
        }
    }
    if(!catched) printf("not lower&upper&number, trying lower&upper&number&special\n");

    // lowercase & uppercase & number & special character test
    for(int len=MIN_LEN; len<=MAX_LEN && !catched; len++) {
        printf("trying lower&upper&number&special with length %d\n", len);

        char* bfpw = (char*)malloc(sizeof(char)*len);
        for(int i=0; i<len; i++) bfpw[i] = 33; // start from '0'
        bfpw[len] = 0;

        while(bfpw[len-1] != 127 && !catched) {
            try++;
            // printf("%s\n", bfpw);

            if(strcmp(password, bfpw) == 0) {
                printf("catched! tried %lld\n", try);
                catched = 1;
            }

            bfpw[0]++;
            for(int i=0; i<len; i++) {
                if(bfpw[i] == 127 && i != len-1) {
                    bfpw[i+1]++;
                    bfpw[i] = 33;
                }
            }
        }
    }
    if(!catched) printf("failed to crack!\n");


    return 0;
}