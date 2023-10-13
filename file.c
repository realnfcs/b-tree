// implementações dos métodos do arquivo de header
#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int read_data(int rnn, client_data *c);