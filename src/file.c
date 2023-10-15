// implementações dos métodos do arquivo de header
#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* DATA_FILE = "data.dat";
const char* INDEX_FILE = "index.dat";
const char* MODALITY_INDEX_FILE = "index1.dat";
const char* GENDER_MODALITY_FILE = "index2.dat";

// inicialização da estrutura de gerenciamento do arquivo "data.dat"
static _record_tb_info _managment_tb = {
    ._last_rnn = 0,
    ._num_records = 0
};

// funções com operações dentro do arquivo de dados.dat

int write_data(char *login, char *modality, char *gender) {

    FILE *f = fopen(DATA_FILE, "a");

    if (!f) {
        // TODO: better error print
        printf("write_data [error]: cannot open %s file", DATA_FILE);
        return 0;
    }

    int len_str = strlen(login) + strlen(modality) + strlen(gender);
    int tota_lenght = len_str + snprintf(NULL, 0, "%d", len_str) + 3;
    
    fprintf(f, "%d%s|%s|%s|", tota_lenght, login, modality, gender);

    fclose(f);

    _managment_tb._last_rnn += tota_lenght;
    _managment_tb._num_records++;

    return 1;
}

int read_data(int rnn, client_data *c) {

    FILE *f = fopen(DATA_FILE, "r");

    if (!f) {
        printf("read_data [error]: cannot open %s file", DATA_FILE);
        return 0;
    }

    if(fseek(f, rnn, SEEK_SET) != 0) {
        perror("read_data [error]: cannot read the record");
        fclose(f);
        return 0;
    }

    char *buffer = (char *) malloc(2 * sizeof(char));
    char digit;
    int i = 0;

    // laço de repetição para a obtenção do número que representa o tamanho da string
    while(1) {

        // Lê dígito por dígito inicial até encontrar um não-dígito
        if (fread(&digit, sizeof(char), 1, f) == 0) {
            perror("read_data [error]: cannot read digits");
            free(buffer);   
            fclose(f);
            return 1;
        }

        if (isdigit(digit)) {
            buffer[i] = digit;
            i++;
        } else {
            break;
        }

        if (i >= strlen(buffer)) {
            buffer = (char *) realloc(buffer, (i + 1) * sizeof(char));
        }
    }

    // Adiciona o terminador nulo para formar uma string válida
    buffer = (char *) realloc(buffer, (i + 1) * sizeof(char));
    buffer[i] = '\0';

    int tota_len = atoi(buffer);
    int data_len = tota_len - snprintf(NULL, 0, "%d", tota_len);

    memset(buffer, 0, sizeof(buffer));
    buffer = (char *) realloc(buffer, data_len * sizeof(char));

    if(fseek(f, rnn + snprintf(NULL, 0, "%d", tota_len), SEEK_SET) != 0) {
        perror("read_data [error]: cannot read the string");
        free(buffer);
        fclose(f);
        return 1;
    }

    if (fread(buffer, sizeof(char), data_len , f) == 0) {
        perror("read_data [error]: cannot read digits");
        free(buffer);   
        fclose(f);
        return 1;
    }

    char *pipe = strtok(buffer, "|");

    c->login = strdup(pipe);
    pipe = strtok(NULL, "|");
    c->modality = strdup(pipe);
    pipe = strtok(NULL, "|");
    c->gender = strdup(pipe);

    free(buffer);
    fclose(f);
    return 1;
}