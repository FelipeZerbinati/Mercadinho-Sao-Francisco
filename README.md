# 🛒 Mercadinho São Francisco

Este repositório contém o código-fonte de um sistema simples de controle de estoque desenvolvido em linguagem C. O projeto implementa as operações básicas de um CRUD (Create, Read, Update, Delete) para o gerenciamento de produtos.

## 🚀 Sobre o Projeto

O sistema foi desenvolvido como um projeto prático para aplicar conceitos de manipulação de dados e estruturas em C. Ele permite ao usuário realizar as seguintes operações em um controle de estoque:

* **C**reate (Cadastrar): Adicionar novos produtos ao estoque.
* **R**ead (Listar): Visualizar os produtos atualmente cadastrados.
* **U**pdate (Atualizar): Modificar informações de um produto existente.
* **D**elete (Remover): Excluir um produto do estoque.

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** 100% C
* **IDE:** O projeto inclui arquivos de configuração (`.cbp`, `.layout`) do [Code::Blocks](http://www.codeblocks.org/).

## ⚙️ Como Compilar e Executar

Existem duas maneiras principais de compilar este projeto:

### 1. Usando o Code::Blocks (Recomendado)

1.  Clone este repositório:
    ```bash
    git clone https://github.com/FelipeZerbinati/Mercadinho-Sao-Francisco.git
    ```
2.  Navegue até a pasta do projeto:
    ```bash
    cd Mercadinho-Sao-Francisco
    ```
3.  Abra o arquivo `Trabalho_CRUD.cbp` com o Code::Blocks.
4.  Clique em "Build and Run" (ou pressione F9) para compilar e executar o programa.

### 2. Manualmente (via Linha de Comando GCC)

1.  Certifique-se de ter o compilador GCC instalado.
2.  Clone o repositório e navegue até a pasta:
    ```bash
    git clone https://github.com/FelipeZerbinati/Mercadinho-Sao-Francisco.git
    cd Mercadinho-Sao-Francisco
    ```
3.  Compile os arquivos `.c` juntos:
    ```bash
    gcc main.c functions.c -o mercadinho
    ```
4.  Execute o programa compilado:
    ```bash
    ./mercadinho
    ```

## 📂 Estrutura de Arquivos

* `main.c`: Arquivo principal que contém o menu e a lógica de interação com o usuário.
* `functions.h`: Arquivo de cabeçalho (header) com as declarações das funções e estruturas.
* `functions.c`: Arquivo de implementação das funções do CRUD (cadastrar, listar, etc.).
* `Trabalho_CRUD.cbp`: Arquivo de projeto do Code::Blocks.

## 👨‍💻 Autores
