#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 10 // Define o número máximo de livros que podem ser armazenados

void limparConsole() {
  // Se houver problemas, comente a linha do sistema não compatível
  // system("cls"); // Windows
  system("clear"); // MacOs ou Linux
}

// função para não dar erro no scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// criei a struct global para facilitar a entrada nas funções
struct infoLivros {
  char nomeLivro[50];
  char autorLivro[20];
  char editoraLivro[20];
  int anoPublicacao;
  int idDoLivro;
  char descricaoDoLivro[200];
  int disponibilidade; // 1 = disponível, 0 = indisponível
};

// Ponteiro global para os livros
struct infoLivros *infoLivro;

// Ponteiro para a pilha de livros excluídos
struct infoLivros *pilhaLivrosExcluidos;
// Contador para o tamanho da pilha (funciona como o topo)
int tamanhoPilha = 0;

// contador de livros
int i = 0;

// função para modificar as informações dos livros
void editarLivroPorID(struct infoLivros *livro) {
  limparConsole();

  printf(" ================================================================== \n");
  printf("                       INFORMAÇõES DO LIVRO                         \n");
  printf(" ================================================================== \n");
  printf(" Nome do livro: %s\n", livro->nomeLivro);
  printf(" Autor do livro: %s\n", livro->autorLivro);
  printf(" Editora do livro: %s\n", livro->editoraLivro);
  printf(" Ano de publicação: %d\n", livro->anoPublicacao);
  printf(" ID do livro: %d\n", livro->idDoLivro);
  printf(" Descrição: %s\n", livro->descricaoDoLivro);
  printf(" Disponibilidade: %s\n", livro->disponibilidade ? "Disponível" : "Indisponível");
  printf(" ================================================================== \n");

  // pergunta ao usuario sele quer mudar a disponibilidade do livro 
  int opcaoMudar;
  printf("\nO que você deseja editar?\nNome (1)\nAutor (2)\nEditora (3)\nAno de Publicação (4)\nDescrição (5)\nDisponibilidade (6)\nOpção: ");
  scanf("%d", &opcaoMudar);

  switch (opcaoMudar) {
    case 1:
      limparConsole();
      printf(" ================================================================== \n");
      printf("            DIGITE O NOME DO LIVRO QUE DESEJA ADICIONAR:            \n");
      printf(" ================================================================== \n");
      printf(" Nome: ");
      limparBufferEntrada();
      scanf("%[^\n]", livro->nomeLivro);
    break;

    case 2:
      limparConsole();
      printf(" ================================================================== \n");
      printf("           DIGITE O AUTOR DO LIVRO QUE DESEJA ADICIONAR:            \n");
      printf(" ================================================================== \n");
      printf(" Autor: ");
      limparBufferEntrada();
      scanf("%[^\n]", livro->autorLivro);
    break;

    case 3:
      limparConsole();
      printf(" ================================================================== \n");
      printf("          DIGITE A EDITORA DO LIVRO QUE DESEJA ADICIONAR:           \n");
      printf(" ================================================================== \n");
      printf(" Editora: ");
      limparBufferEntrada();
      scanf("%[^\n]", livro->editoraLivro);
    break;

    case 4:
      limparConsole();
      printf(" ================================================================== \n");
      printf("     DIGITE O ANO DE PUBLICAÇãO DO LIVRO QUE DESEJA ADICIONAR:      \n");
      printf(" ================================================================== \n");
      printf(" Ano de publicação: ");
      limparBufferEntrada();
      scanf("%d", &livro->anoPublicacao);
    break;

    case 5:
      limparConsole();
      printf(" ================================================================== \n");
      printf("        DIGITE UMA DESCRIÇãO DO LIVRO QUE DESEJA ADICIONAR:         \n");
      printf(" ================================================================== \n");
      printf(" Descrição: ");
      limparBufferEntrada();
      scanf("%[^\n]", livro->descricaoDoLivro);
    break;

    case 6:
      limparConsole();
      printf(" ================================================================== \n");
      printf("       DIGITE A DISPONIBILIDADE DO LIVRO QUE DESEJA ADICIONAR       \n");
      printf(" ================================================================== \n");
      printf(" (1 = Disponível, 0 = Indisponível)\n");
      printf(" Descrição: ");
      limparBufferEntrada();
      scanf("%d", &livro->disponibilidade);
    break;

    default:
      printf("ERRO, TENTE NOVAMENTE\n");
    break;
  }

  limparConsole();
  printf("Livro alterado com sucesso! \n");

}

// função para perguntar o ID para modificar o livro
void pergunteIdParaModificar() {
  int id;
  // vai solicitar ao usuario o id do livro
  printf("Digite o ID do livro que deseja modificar: ");
  scanf("%d", &id);

  // verifica se o id é existente
  if (id >= 0 && id < i) {
    // chama a função modificar livro que vai receber o endereço do livro
    editarLivroPorID(&infoLivro[id]);
  } else {
    printf("\n ID inválido! Tente novamente.\n");
  }
}

// Função para adicionar livros
void addLivros() {
    printf(" ================================================================== \n");
    printf("            DIGITE O NOME DO LIVRO QUE DESEJA ADICIONAR:            \n");
    printf(" ================================================================== \n");
    printf("Nome do livro: ");
    limparBufferEntrada(); // ele vai garantir que nenhuma quebra de linha atrapalhe a leitura do scanf...
    scanf("%[^\n]", infoLivro[i].nomeLivro);
    limparConsole();

    printf(" ================================================================== \n");
    printf("           DIGITE O AUTOR DO LIVRO QUE DESEJA ADICIONAR:            \n");
    printf(" ================================================================== \n");
    printf("Nome do Autor: ");
    limparBufferEntrada(); // ele vai garantir que nenhuma quebra de linha atrapalhe a leitura do scanf... 
    scanf("%[^\n]", infoLivro[i].autorLivro);
    limparConsole();

    printf(" ================================================================== \n");
    printf("          DIGITE A EDITORA DO LIVRO QUE DESEJA ADICIONAR:           \n");
    printf(" ================================================================== \n");
    printf("Nome da Editora: ");
    limparBufferEntrada(); // ele vai garantir que nenhuma quebra de linha atrapalhe a leitura do scanf... 
    scanf("%[^\n]", infoLivro[i].editoraLivro);
    limparConsole();

    printf(" ================================================================== \n");
    printf("     DIGITE O ANO DE PUBLICAÇãO DO LIVRO QUE DESEJA ADICIONAR:      \n");
    printf(" ================================================================== \n");
    printf("Ano de publicação: ");
    scanf("%d", &infoLivro[i].anoPublicacao);
    limparConsole();

    printf(" ================================================================== \n");
    printf("        DIGITE UMA DESCRIÇãO DO LIVRO QUE DESEJA ADICIONAR:         \n");
    printf(" ================================================================== \n");
    printf("Descrição (max 200 caracteres): ");
    limparBufferEntrada(); // ele vai garantir que nenhuma quebra de linha atrapalhe a leitura do scanf... 
    scanf("%[^\n]", infoLivro[i].descricaoDoLivro);
    limparConsole();

    infoLivro[i].idDoLivro = i; // aqui ele esta dando o valor de ID, com base na quantidade na posição da array livros que está
    infoLivro[i].disponibilidade = 1; // aqui eu to deixando disponivel assim que vc adiciona o livro

    printf(" ================================================================== \n");
    printf("                    LIVRO ADICIONADO COM SUCESSO!                   \n");
    printf(" ================================================================== \n");
    printf("Nome do livro: %s\n", infoLivro[i].nomeLivro);
    printf("Autor do livro: %s\n", infoLivro[i].autorLivro);
    printf("Editora do livro: %s\n", infoLivro[i].editoraLivro);
    printf("Ano de publicação: %d\n", infoLivro[i].anoPublicacao);
    printf("ID do livro: %d\n", infoLivro[i].idDoLivro);
    printf("Descrição: %s\n", infoLivro[i].descricaoDoLivro);
    printf("Disponibilidade: Disponível\n");
    printf("Endereço da alocação dinâmica: %p\n", (void*)&infoLivro[i]);
    printf(" ================================================================== \n");

    i++;
}

void mostrarLivroLooping(int j) {
  if (j < i) {
    printf("================================================================== \n");
    printf("                       INFORMAÇõES DO LIVRO (%d)                    \n", j);
    printf("================================================================== \n");
    printf("Nome do livro: %s\n", infoLivro[j].nomeLivro);
    printf("Autor do livro: %s\n", infoLivro[j].autorLivro);
    printf("Editora do livro: %s\n", infoLivro[j].editoraLivro);
    printf("Ano de publicação: %d\n", infoLivro[j].anoPublicacao);
    printf("Descrição: %s\n", infoLivro[j].descricaoDoLivro);
    printf("Disponibilidade: %s\n", infoLivro[j].disponibilidade ? "Disponível" : "Indisponível");
    printf("ID do livro: %d\n", infoLivro[j].idDoLivro);
    printf("Endereço da alocação dinâmica: %p\n", (void*)&infoLivro[j]);

    mostrarLivroLooping(j + 1);
  }
}

void mostrarLivrosAdicionados() {
  limparConsole(); 

  if (i > 0) {
    mostrarLivroLooping(0);
  } else {
    printf("Nenhum livro adicionado ainda!\n");
  }
}

// Função que exclui os livros
void excluirLivro() {
  int id;
  printf("Digite o ID do livro que deseja excluir: ");
  scanf("%d", &id);

  if (id >= 0 && id < i) {
    if (tamanhoPilha >= MAX_LIVROS) {
      printf("Não é possível excluir. A pilha de 'desfazer' está cheia.\n");
      return;
    }

    // Empilhar - Copia o livro a ser excluído para a pilha
    pilhaLivrosExcluidos[tamanhoPilha] = infoLivro[id];
    tamanhoPilha++; // Aumenta o tamanho da pilha

    // Remove o livro da lista principal
    for (int j = id; j < i - 1; j++) {
      infoLivro[j] = infoLivro[j + 1];
      infoLivro[j].idDoLivro = j;
    }
    printf("Livro '%s' excluído com sucesso! (Movido para a lista de 'desfazer')\n", pilhaLivrosExcluidos[tamanhoPilha - 1].nomeLivro);
    i--; // Diminui o contador de livros

  } else {
    printf("ID inválido!\n");
  }
}

// Função para desfazer a exclusão (desempilhar)
void desfazerExclusao() {
  limparConsole();
  printf(" ================================================================== \n");
  printf("                     DESFAZER ÚLTIMA EXCLUSÃO                       \n");
  printf(" ================================================================== \n");

  if (tamanhoPilha == 0) {
    printf("Não há nenhuma exclusão para ser desfeita.\n");
    return;
  }

  if (i >= MAX_LIVROS) {
    printf("A biblioteca está cheia. Não é possível restaurar o livro.\n");
    return;
  }

  // Pega o livro do topo da pilha e diminui o contador da pilha
  tamanhoPilha--;
  struct infoLivros livroRestaurado = pilhaLivrosExcluidos[tamanhoPilha];

  // Adiciona o livro de volta à lista principal
  infoLivro[i] = livroRestaurado;
  // O livro restaurado recebe o próximo ID disponível
  infoLivro[i].idDoLivro = i;
  i++;

  printf("\nLivro '%s' foi restaurado com sucesso!\n", livroRestaurado.nomeLivro);
}

// Função que escolha se você vai buscar ou adicionar os Livros
int perguntePerfil() {
  int escolherPerfil;
  printf("========================================================================================================= \n");
  printf("                              BEM-VINDO AO SISTEMA DE GERENCIAMENTO DE BIBLIOTECA                         \n");
  printf("========================================================================================================= \n");
  printf("(1) Ver lista de livros cadastrados\n");
  printf("(2) Adicionar novo livro\n");
  printf("(3) Editar informações de um livro existente\n");
  printf("(4) Excluir um livro\n");
  printf("(5) Desfazer última exclusão\n");
  printf("(6) Sair do sistema\n");
  printf("========================================================================================================= \n");
  printf ("Opção: ");
  scanf ("%d", &escolherPerfil);
  limparConsole();

  return escolherPerfil;
}

// Aqui vai pegar o valor da função(perguntePerfil) e colocar dentro dela para separar BUSCAR e ADICIONAR...
int escolhaPerfil(int opcaoPerfil) {
  int numMenuBuscarLivros;
  switch (opcaoPerfil) {

    //BUSCAR
    case 1:
      mostrarLivrosAdicionados();

      // Lopping
        int escolhaContinuarSair1;
        printf("\nAperte 1 (Continuar) ou 2 (Sair): ");
        scanf("%d", &escolhaContinuarSair1);

        if (escolhaContinuarSair1 == 1) {
          // caso ele digite 1(Continuar) ele vai limpar o console e começar tudo de novo...
          limparConsole(); 
          // a mesma coisa do main, vai criar uma variavel com o valor de pergunteperfil() chamar ele, salvar o valor, e chamar a escolha perfil com base no que ele digitou
          int numPerfil = perguntePerfil();
          escolhaPerfil(numPerfil);
        } // se ele nao digitar 1 para ficar, vai sair...
    break;
    
    // ADICIONAR
    case 2:
      addLivros();

      // Lopping
        int escolhaContinuarSair2; // criei essa variavel para ele escolher se depois de adicionar o livro vai continuar ou sair...
        printf("\nAperte 1 (Continuar) ou 2 (Sair): ");
        scanf("%d", &escolhaContinuarSair2);

        if (escolhaContinuarSair2 == 1) {
          // caso ele digite 1(Continuar) ele vai limpar o console e começar tudo de novo...
          limparConsole(); 
          // a mesma coisa do main, vai criar uma variavel com o valor de pergunteperfil() chamar ele, salvar o valor, e chamar a escolha perfil com base no que ele digitou
          int numPerfil = perguntePerfil();
          escolhaPerfil(numPerfil);
        } // se ele nao digitar 1 para ficar, vai sair...
    break;

    // EDITAR
    case 3:
      pergunteIdParaModificar();

      // Lopping
        int escolhaContinuarSair3; // criei essa variavel para ele escolher se depois de adicionar o livro vai continuar ou sair...
        printf("\nAperte 1 (Continuar) ou 2 (Sair): ");
        scanf("%d", &escolhaContinuarSair3);

        if (escolhaContinuarSair3 == 1) {
          // caso ele digite 1(Continuar) ele vai limpar o console e começar tudo de novo...
          limparConsole(); 
          // a mesma coisa do main, vai criar uma variavel com o valor de pergunteperfil() chamar ele, salvar o valor, e chamar a escolha perfil com base no que ele digitou
          int numPerfil = perguntePerfil();
          escolhaPerfil(numPerfil);
        } // se ele nao digitar 1 para ficar, vai sair...
    break;

    // EXCLUIR
    case 4:
      excluirLivro();

      // Lopping
      int escolhaContinuarSair4; // criei essa variavel para ele escolher se depois de adicionar o livro vai continuar ou sair...
        printf("\nAperte 1 (Continuar) ou 2 (Sair): ");
        scanf("%d", &escolhaContinuarSair4);

        if (escolhaContinuarSair4 == 1) {
          // caso ele digite 1(Continuar) ele vai limpar o console e começar tudo de novo...
          limparConsole(); 
          // a mesma coisa do main, vai criar uma variavel com o valor de pergunteperfil() chamar ele, salvar o valor, e chamar a escolha perfil com base no que ele digitou
          int numPerfil = perguntePerfil();
          escolhaPerfil(numPerfil);
        } // se ele nao digitar 1 para ficar, vai sair...
    break;

    // Desfazer exclusão
    case 5:
      desfazerExclusao();

      // Lopping
      int escolhaContinuarSair5; // criei essa variavel para ele escolher se depois de adicionar o livro vai continuar ou sair...
        printf("\nAperte 1 (Continuar) ou 2 (Sair): ");
        scanf("%d", &escolhaContinuarSair5);

        if (escolhaContinuarSair5 == 1) {

          // caso ele digite 1(Continuar) ele vai limpar o console e começar tudo de novo...
          limparConsole();
          // a mesma coisa do main, vai criar uma variavel com o valor de pergunteperfil() chamar ele, salvar o valor, e chamar a escolha perfil com base no que ele digitou
          int numPerfil = perguntePerfil();
          escolhaPerfil(numPerfil);
        } // se ele nao digitar 1 para ficar, vai sair...
    break;

    // SAIR
    case 6:
    break;

    default:
      printf("ERRO, TENTE NOVAMENTE\n");
    break;
  }

  return opcaoPerfil;
}

// Função que vai salvar todos os livros adicionados em um arquivo
void salvarEmArquivo() {
  FILE *arquivo = fopen("livros.txt", "w");
  if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo para escrita.\n");
      return;
  }
  // ele vai fazer um looping salvado todos os livros adicionados
  for (int j = 0; j < i; j++) {
    fprintf(arquivo, "Nome: %s\n", infoLivro[j].nomeLivro);
    fprintf(arquivo, "Autor: %s\n", infoLivro[j].autorLivro);
    fprintf(arquivo, "Editora: %s\n", infoLivro[j].editoraLivro);
    fprintf(arquivo, "Ano de Publicação: %d\n", infoLivro[j].anoPublicacao);
    fprintf(arquivo, "Descrição: %s\n", infoLivro[j].descricaoDoLivro);
    fprintf(arquivo, "ID: %d\n", infoLivro[j].idDoLivro);
    fprintf(arquivo, "Disponibilidade: %d\n", infoLivro[j].disponibilidade);
  }

  fclose(arquivo);
  printf("\nTodos os dados salvos com sucesso em 'livros.txt'\n");
}

// Função que vai carregar todos os livros no arquivo antes de rodar adicionando eles no array
void carregarLivrosDoArquivo() {
  FILE *arquivo = fopen("livros.txt", "r"); // read (ler)
  if (arquivo == NULL) {
      printf("Arquivo não encontrado ou erro ao abrir.\n");
      return;
  }

  // Loop para carregar até o fim do arquivo
  while (1) { // Loop infinito, ele só vai parar se falhar na leitura
    // Le o arquivo e adiciona em infoLivro[i]
    if (fscanf(arquivo, "Nome: %[^\n]\n", infoLivro[i].nomeLivro) != 1) break;
    if (fscanf(arquivo, "Autor: %[^\n]\n", infoLivro[i].autorLivro) != 1) break;
    if (fscanf(arquivo, "Editora: %[^\n]\n", infoLivro[i].editoraLivro) != 1) break;
    if (fscanf(arquivo, "Ano de Publicação: %d\n", &infoLivro[i].anoPublicacao) != 1) break;
    if (fscanf(arquivo, "Descrição: %[^\n]\n", infoLivro[i].descricaoDoLivro) != 1) break;
    if (fscanf(arquivo, "ID: %d\n", &infoLivro[i].idDoLivro) != 1) break;
    if (fscanf(arquivo, "Disponibilidade: %d\n", &infoLivro[i].disponibilidade) != 1) break;

    // Aumenta o contador de livros
    i++;
  }
  

  fclose(arquivo);
}

int main() {
  //Criando a alocação dinâmica
  infoLivro = (struct infoLivros*) malloc(MAX_LIVROS * sizeof(struct infoLivros));
  if (infoLivro == NULL) {
    printf("Erro ao alocar memória.\n");
    return 1;
  }

  // Criamos a alocação dinâmica para a pilha de excluídos
  pilhaLivrosExcluidos = (struct infoLivros*) malloc(MAX_LIVROS * sizeof(struct infoLivros));
  if (pilhaLivrosExcluidos == NULL) {
    printf("Erro ao alocar memória para a pilha.\n");
    free(infoLivro); // Libera a memória já alocada
    return 1;
  }

  // Carregar todos os arquivos salvos em livros.txt
  carregarLivrosDoArquivo();

  // Chamar o programa
  limparConsole();
  int numPerfil = perguntePerfil(); // Primeiro ele vai criar essa variavel para guardar o valor da funcão 'perguntePerfil', se vai buscar ou adicionar livros

  escolhaPerfil(numPerfil); // Aqui ele vai chamar a função(escolhaPerfil) e enviar o valor de numPerfil
  // Salva os dados antes de sair
  salvarEmArquivo();

  // Liberar memoria do nosso pc da alocação dinamica criada
  free(infoLivro); 
  free(pilhaLivrosExcluidos);
  
  return 0;
}