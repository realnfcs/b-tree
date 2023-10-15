// definição da estrutura do node da B-Tree
typedef struct node {
    // keys: array de chaves que identificam os arquivos
    // k_num: número atual de chaves
    // k_minimun_qtt: quantidade mínima de chaves
    unsigned int *keys, k_num, k_minimum_qtt;
    // link: array de ponteiros de descendentes
    struct node **childs;
    // leaf: variável booleana denotando se o node é folha
    //       ou não.
    bool leaf;    
} BT_node;

typedef struct {
    BT_node *root;
    unsigned int min_degree;
} BTree;
