
#include <stdio.h>

void menu(void) {
  printf("\n\n============================================");
  printf("\n\nC BANK");
  printf("\n\nMENU:");
  printf("\n");
  printf("\n1. CADASTRAR CLIENTE");
  printf("\n2. SAQUE");
  printf("\n3. DEPÓSITO");
  printf("\n4. TRANSFERÊNCIA");
  printf("\n5. CONSULTAR SALDO");
  printf("\n6. ENCERRAR PROGRAMA");
}

void clientes(int codigoCliente, int codigo[100], int agencia[100], long int numConta[100], float saldo[100], char cliente[100][150]){

  printf("\n\nCONTAS CADASTRADAS");
  printf("\n------------------------");
  
  for (int i = 0; i < codigoCliente; i++) {

      printf("\n\nCódigo da conta: %d", i);
      printf("\nAgência: %d", agencia[i]);
      printf("\nConta: %ld", numConta[i]);
      printf("\nCliente: %s", cliente[i]);
      printf("\nSaldo atual: R$%.2f", saldo[i]);
      printf("\n------------------------");
  }

  return;
}

int main(void) {
  int i, j, destino, opcao, codigoCliente = 0, cadastro = 1, pesquisa,
                            codigo[100], agencia[100];
  long int numConta[100];
  float saque, deposito, transferencia, saldo[100];
  char cliente[100][150];

  do {
    menu();
    
    printf(
        "\n\nDigite o número correspondente a operação que deseja realizar: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
      for (i = 0; i < 100 && cadastro == 1; i++) {

        codigo[i] = codigoCliente++;

        printf("\nCódigo do cliente: %d", codigo[i]);

        printf("\n\nNome do cliente: ");
        scanf("%s", cliente[i]);

        printf("\nNúmero da agência: ");
        scanf("%d", &agencia[i]);

        printf("\nNúmero da conta: ");
        scanf("%ld", &numConta[i]);

        printf("\nSaldo atual: R$");
        scanf("%f", &saldo[i]);

        printf("\n\nCADASTRAR OUTRO CLIENTE:");
        printf("\n\n1. SIM");
        printf("\n2. NÃO");
        printf("\n\nOPÇÃO: ");
        scanf("%d", &cadastro);

        if (cadastro == 2) {
          cadastro = 1;
          break;
        }
      }
    } else if (opcao == 2) {

      clientes(codigoCliente, codigo, agencia, numConta, saldo, cliente);

      printf("\n\nDigite o código da conta que deseja sacar: ");
      scanf("%d", &pesquisa);

      if (pesquisa < 0 || pesquisa >= codigoCliente){
        printf("\nConta não existente");
      } else{
      for (i = 0; i < 100; i++) {
        if (pesquisa == codigo[i]) {
          printf("\n\nAgência: %d", agencia[i]);
          printf("\nConta: %ld", numConta[i]);
          printf("\nCliente: %s", cliente[i]);
          printf("\nSaldo atual: R$%.2f", saldo[i]);

          printf("\n\nValor a sacar: R$");
          scanf("%f", &saque);

          if (saldo[i] >= saque) {
            saldo[i] = saldo[i] - saque;
            printf("\nSaldo da conta: R$%.2f", saldo[i]);
          } else {
            printf("\nSaldo insuficiente para o saque.");
          }

          break;
        }
      }
     }
    } else if (opcao == 3) {

      clientes(codigoCliente, codigo, agencia, numConta, saldo, cliente);

      printf("\n\nDigite o código da conta que deseja depositar: ");
      scanf("%d", &pesquisa);
      if(pesquisa < 0 || pesquisa >= codigoCliente){
        printf("\nConta não existente");
      } else{
      for (i = 0; i < 100; i++) {
        if (pesquisa == codigo[i]) {
          printf("\n\nAgência: %d", agencia[i]);
          printf("\nConta: %ld", numConta[i]);
          printf("\nCliente: %s", cliente[i]);
          printf("\nSaldo atual: R$%.2f", saldo[i]);

          printf("\n\nQuanto deseja depositar: R$");
          scanf("%f", &deposito);

          saldo[i] = saldo[i] + deposito;

          printf("\nDepósito realizado");
          printf("\n\nSaldo atual: R$%.2f", saldo[i]);

          break;
        }
      }
     }   
    } else if (opcao == 4) {

      if (codigoCliente < 2) {
        printf("\n\nApenas um cliente cadastrado. Não é possível realizar uma "
               "transferência.");
      } else {

        clientes(codigoCliente, codigo, agencia, numConta, saldo, cliente);
        
        printf("\n\nDigite o código da conta que irá realizar a transferência: ");
        scanf("%d", &pesquisa);

        if(pesquisa < 0 || pesquisa >= codigoCliente){
          printf("\nConta não existente");
        } else{
        for (i = 0; i < 100; i++) {
          if (pesquisa == codigo[i]) {
            printf("\n\nAgência: %d", agencia[i]);
            printf("\nConta: %ld", numConta[i]);
            printf("\nCliente: %s", cliente[i]);
            printf("\nSaldo atual: R$%.2f", saldo[i]);

            printf("\n\nQuanto deseja transferir: R$");
            scanf("%f", &transferencia);

            if (saldo[i] < transferencia) {
              printf("\nSaldo insuficiente para o transferência.");
              break;
            } else {
              printf("\n\nCódigo da conta para qual deseja transferir: ");
              scanf("%d", &destino);
              if(pesquisa < 0 || pesquisa >= codigoCliente){
                printf("\nConta não existente");
              } else{
              for (j = 0; j < 100; j++) {
                if (destino == codigo[j]) {
                  printf("\n\nAgência: %d", agencia[j]);
                  printf("\nConta: %ld", numConta[j]);
                  printf("\nCliente: %s", cliente[j]);

                  saldo[j] = saldo[j] + transferencia;
                  saldo[i] = saldo[i] - transferencia;

                  printf("\n\nTRANSFERÊNCIA REALIZADA");
                  printf("\nSaldo atual: R$%.2f", saldo[i]);
                  break;
                }
              }
            }

              break;
            }
          }
        }
      }   
      }
    } else if (opcao == 5) {

      for (int i = 0; i < codigoCliente; i++) {

          printf("\n\nCódigo da conta: %d", i);
          printf("\nAgência: %d", agencia[i]);
          printf("\nConta: %ld", numConta[i]);
          printf("\nCliente: %s", cliente[i]);
          printf("\n------------------------");
      }
      
      printf("\n\nDigite o código da conta: ");
      scanf("%d", &pesquisa);

      if(pesquisa < 0 || pesquisa >= codigoCliente){
        printf("\nConta não existente");
      } else{
      for (i = 0; i < 100; i++) {
        if (pesquisa == codigo[i]) {
          printf("\n\nAgência: %d", agencia[i]);
          printf("\nConta: %ld", numConta[i]);
          printf("\nCliente: %s", cliente[i]);
          printf("\n\nSaldo atual: R$%.2f", saldo[i]);

          break;
        }
      }
     }   
    }
  } while (opcao != 6);

  return 0;
}
