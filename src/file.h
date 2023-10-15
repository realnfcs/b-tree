// definição dos métodos e estruturas relacionados aos arquivos
// de dados e de índices e suas operações

extern const char* DATA_FILE;
extern const char* INDEX_FILE;
extern const char* MODALITY_INDEX_FILE;
extern const char* GENDER_MODALITY_FILE;

/*
* ********************************************************
* estrutura que representa os dados dos clientes dentro do
* arquivo data.dat
* ********************************************************
*/

// estrutura de gerenciamento do arquivo "data.dat"
typedef struct {
    // armazena o tamanho do último registro adicionado no arquivo
    int _last_rnn;
    // armazena o número de registro dentro do arquivo
    int _num_records;
} _record_tb_info;

// estrutura que representa um cliente dentro do arquivo "data.dat"
typedef struct {
    // Byte Offset de deslocamento do registro dentro do 
    // arquivo
    int _rnn;
    // informações de dentro do registro
    char *login, *modality, *gender;
} client_data;

// funções com operações dentro do arquivo de dados.dat
int write_data(char *login, char *modality, char *gender);
int read_data(int rnn, client_data *c);
int get_rnn(char *login);

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
} bt_root;

// SEÇÃO INSEGURA
// deve ser visto é determinado a assinatura das funções relacionados
// com as operações no arquivo de índices primários (index.dat)
// funções com operações dentro do arquivo de index1.dat
int write_index();
int read_index(int rnn);

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
    struct _pk *next;
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