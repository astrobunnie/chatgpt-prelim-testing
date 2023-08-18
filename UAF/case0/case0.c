#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void xor_encrypt(char* out, char* data, int data_len, char* key, int key_len);
void generate_output(char* data_a, int data_a_len, char* data_b, int data_b_len);
#define BUG_FIX *out_xor+=
//two arguments A and B are provided in argv[1] and argv[2]
//xor encrypt A with respect to B and B with respect to A and return both results
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Two arguments are required\n");
        return 1;
    }

    char* data_a = argv[1];
    int data_a_len = strlen(data_a);
    char* data_b = argv[2];
    int data_b_len = strlen(data_b);

    if(data_a_len != data_b_len) {
        printf("Two arguments must be of the same length\n");
        return 1;
    }

    generate_output(data_a, data_a_len, data_b, data_b_len); 
    return 0;
}

void xor_encrypt(char* out, char* data, int data_len, char* key, int key_len) {
    for(int i=0; i<data_len; i++) {
        out[i] = data[i] ^ key[i % key_len];
    }
}

void generate_output(char* data_a, int data_a_len, char* data_b, int data_b_len) {
    char* out_xor = (char*)malloc(data_a_len);
    xor_encrypt(out_xor, data_a, data_a_len, data_b, data_b_len);
    for(int i=0; i<data_a_len; i++) {
        printf("%2x ", out_xor[i]);
    }
    free(out_xor);
    BUG_FIX 5;
    printf("%s", out_xor);
}
