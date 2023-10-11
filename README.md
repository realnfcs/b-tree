# b-tree
A B-tree exercise for gym client management. 

- [x] Criação dos métodos e operações de Input
- [ ] Criação dos arquivos de header
- [ ] Criação das operações envolvendo o arquivo de dados (data.dat)
- [ ] Criação das operações envolvendo o arquivo de índices primários
- [ ] Criação das operações envolvendo o arquivo de índices secundários de modalidade e sexo
- [ ] Desenvolvimento da estrutura e das operações da Árvore B
- [ ] Criação dos métodos e operações de Output
- [ ] Testes

# O Arquivo de Dados:

- número fixo de campos, assim não há necessidade de separador **entre registros** (por exemplo #)
- campos de tamanho variado
- tamanho do registro delimitado no início de cada registro

**exemplo do arquivo dados.dat:**

	tam1login1|modalidade1|sexo1|tam2login2|modalidade2|sexo2|...

# O Arquivo de índice primário:

Server como um RNN para cada registro dentro do arquivo de dados.

- deve ser binário
- deve armazenar o RRN da raiz da Árvore-B (int)
- e em seguida deve armazenar uma sequência de registros representando cada página da Árvore-B com 3 campos representando:
	- Númedo de chaves na página
	- Vetor de 3 posições de structs contendo
		- Chaves: vetor de 21 caracteres (20 para a login, 1 para o ‘\0’).
		- Offset (RNN) do registro no arquivo de dados
	- Vetor de 4 inteiros para RRN’s dos filhos da página

O arquivo deve ser chamado index.dat. Como nã há exemplo, vamos interpretar a organização do arquivo da seguinte forma:

	raiz|numero_chaves|chaves|offset|filhos
	
# Arquivo de índice secundário

Os índices secundários servem para possibilitar a pesquisa de um ou mais de um registro dado uma chave secundária.

## Índice secundário (modalidade)
- deve ser binário
- armazenar registros com 2 campos
	- um para a chave secundária
	- vetor ordenado de chaves primárias
- deve ser mantido ordenado dentro do arquivo por chave secundária
- a chave secundária deve ser declarada como um vetor de 21 caracteres (20 para a modalidade, 1 para o ‘\0’)
- o campo das chaves primárias deve ser um vetor de 15 chaves primárias ou lista (ORDENADOS) representadas da mesma 
  forma que no índice primário.
 
O arquivo deve ser chamado como "index1.dat"

Como não há exemplo da organização do arquivo, podemos interpretar da seguinte forma:

## Índice secundário (gênero)

- deve ser binário
- armazenar registros com 2 campos
	- um para a chave secundária
	- vetor ordenado de chaves primárias
- deve ser mantido ordenado dentro do arquivo por chave secundária
- a chave secundária é representada por 1 caractere
- o campo das chaves primárias deve ser um vetor de 50 chaves primáriasou lista (ORDENADOS) representadas da mesma 
  forma que no índiceprimário.
 
O arquivo deve ser chamado como "index2.dat"

# Referências gerais

- [GeeksforGeeks](https://www.geeksforgeeks.org/introduction-of-b-tree-2/)
- [Programiz](https://www.programiz.com/dsa/b-tree)

# Recomendações

Slides de arquivos disponibilizados pela professora	
