#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assembler.h"



int main(int argc, char** argv) {
    if (argc < 2) {
        printf("USAGE: k16-assembler -i [source-file.k16] -o [output-file]");
    }
    char source_file_name[MAX_PATH];
    char output_file_name[MAX_PATH];

    if (get_input_output_file_names(source_file_name, output_file_name, argc, argv)) return 1;

    // The buffers for each file
    size_t input_file_len;
    char* input_file = read_file(source_file_name, &input_file_len);
    if (!input_file) {
        fprintf(stderr, "Error Opening %s\n", source_file_name);
        return 1;
    }
    // to ensure the file is a valid C-string, null terminate the file buffer
    input_file[input_file_len] = '\0';

    size_t output_file_size = 0;
    char* machine_code = assemble(input_file, &output_file_size);
    if (!machine_code) {
        fprintf(stderr, "Error Assembling\n");
        return 1;
    }
    if (write_file(output_file_name, output_file_size, machine_code)) {
        fprintf(stderr, "Error writing to %s\n", output_file_name);
        return 1;
    }

    return 0;
}

int get_input_output_file_names(char* src_file, char* out_file, int argc, char** argv) {
    bool src_file_set = false;
    bool out_file_set = false;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-o")) {
            if (i+1 >= argc) {
                fprintf(stderr, "ERROR:\nNo File Given after -o\n");
                return 1;
            }
            strcpy(out_file, argv[i+1]);
            out_file_set = true;
            i++;
        } else if (!strcmp(argv[i], "-i")) {
            if (i+1 >= argc) {
                fprintf(stderr, "ERROR:\nNo File Given after -i\n");
                return 1;
            }
            strcpy(src_file, argv[i+1]);
            src_file_set = true;
            i++;
        } else {
            fprintf(stderr, "ERROR:\nUnrecognized Keyword: %s\n", argv[i]);
            return 1;
        }
    }

    if (src_file_set == false || out_file_set == false) {
        fprintf(stderr, "USAGE: k16-assembler -i [source-file.k16] -o [output-file]\n");
        return 1;
    }

    return 0;
}

char* read_file(char* path, size_t* file_len) {
    FILE* file = fopen(path, "r");
    if (!file) return NULL;
    fseek (file, 0, SEEK_END);
    size_t length = ftell (file);
    *file_len = length;
    fseek (file, 0, SEEK_SET);
    uint8_t* buffer = malloc (length);
    if (!buffer) return NULL;
    fread (buffer, 1, length, file);
    fclose (file);
    return (char*)buffer;
}

int write_file(char* path, size_t file_len, char* write_contents) {
    FILE* file = fopen(path, "wb");
    if (!file) return 1;
    if (fwrite(write_contents, 1, file_len, file) != file_len) return 1;
    fclose(file);
    return 0;
}

char* assemble(char* input_buf, size_t* output_file_size) {
    // For now, create an abusurdly large buffer to write to
    char* output_file_buf = malloc(32767);
    size_t token_count = 0;
    tokenize_input(input_buf, &token_count);


    // This assembler is very simple, go through each instruction and translate it directly to the OPCODE
    return 0;
}

// Essentially a lexer, turns the input file into a vector of tokens
token* tokenize_input(char* input, size_t* token_amount) {
    token* token_vec = malloc(sizeof(token)*50);
    size_t token_amt = 0;
    char* cur = input;

    char current_tok[16] = {0};
    int i = 0;
    while(*cur != '\0') {
        if (*cur == ' ' || *cur == '\n') {
            if (!strcmp(current_tok, "LDA")) {
                token_vec[token_amt] = LDA;
                i = 0;
                token_amt++;
            } else if (!strcmp(current_tok, "LDB")) {
                token_vec[token_amt] = LDB;
                i = 0;
                token_amt++;
            } else {
                fprintf(stderr, "ERROR: Unrecognized Token: %s\n", current_tok);
                printf("len: %ld\n", strlen(current_tok));
                exit(1);
            }
        } else {
            current_tok[i] = *cur;
            i++;
        }     
        cur++;  
    }
    *token_amount = token_amt;
}