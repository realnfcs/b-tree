// definição dos métodos e estruturas relacionados aos arquivos
// de dados e de índices e suas operações

/*
* ********************************************************
* estrutura que representa os dados dos clientes dentro do
* arquivo data.dat
* ********************************************************
*/

// estrutura que representa
typedef struct {
    int _rnn;
    char *login, *modality, *gender;
} client_data;

// funções com operações dentro do arquivo de dados.dat
int write_data(char *login, char *modality, char *gender);
int read_data(int rnn, client_data *c);

/*
* ********************************************************
* estruturas que representa os índeces primários dentro do
* arquivo index.dat
* ********************************************************
*/

// estrutura que representa as chaves dentro de uma página
typedef struct {
    // rnn que identifica o deslocamento para dentro do arquivo
    // dados.dat para obtenção do registro em questão.
    int rnn;
    // string que funciona como um valor a ser comparado no processo
    // de pesquisa dentro de uma árvore B
    char *value;
} key;

// estrutura que representa a página dentro da árvore B
typedef struct {
    // número que identifica a página
    int num;
    // arrays de chaves
    key *keys;
    // RNN dos filhos das chaves da página
    int* childs_rnn;
} page;

// estrutura que representa a raíz da árvore B no arquivo index.dat
typedef struct {
    // raíz da árvore B
    int root_rnn;
    // páginas contidas na árvore B
    page *pages;
};

// SEÇÃO INSEGURA
// deve ser visto é determinado a assinatura das funções relacionados
// com as operações no arquivo de índices primários (index.dat)
// funções com operações dentro do arquivo de index1.dat
int write_index();
int read_index(int rnn);
int binary_encode();
int binary_decode();

/*
* **********************************************************
* estrutura que representa os índices secundários dentro dos
* arquivos index1.dat e index2.dat
* **********************************************************
*/

// estrutura que representa os índices primários conectados como uma 
// Linked List e identificado pelo índice secundário de modalidade
typedef struct _pk {
    // a chave em si com RNN e o valor do registro em questão
    key key;
    // ponteiro para o próximo registro
    _pk *next;
} primary_keys;

// estrutura que representa a lista inversa com índice secundário que
// aponta para uma lista de índices primários no arquivo de index1.dat
typedef struct {
    // valor do índice secundário
    char *idx;
    // lista de índices primários
    primary_keys *keys;
} modality_index;

// SEÇÃO INSEGURA
// deve ser visto é determinado a assinatura das funções relacionados
// com as operações no arquivo de índices secundários (index1.dat)
//
// funções com operações dentro do arquivo de index1.dat
int write_mod_idx();
int read_mod_idx();
int binary_encode_mod_idx();
int binary_decode_mod_idx();

// estrutura que representa a lista inversa com índice secundário que
// aponta para uma lista de índices primários no arquivo de index2.dat
typedef struct {
    // valor do índice secundário
    char *idx;
    // lista de índices primários
    primary_keys *keys;
} gender_index;

// SEÇÃO INSEGURA
// deve ser visto é determinado a assinatura das funções relacionados
// com as operações no arquivo de índices secundários (index2.dat)
//
// funções com operações dentro do arquivo de index2.dat
int write_gen_idx();
int read_gen_idx();
int binary_encode_gen_idx();
int binary_decode_gen_idx();