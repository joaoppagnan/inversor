/* Data de submissao:16/03/2020
 * Nome:João Pedro de Oliveira Pagnan
 * RA:199727
 */

#include <stdio.h>
#include <string.h> /* inclui essa biblioteca pois precisaremos utilizar a funcao strlen() pra medir o tamanho da string de entrada */

const int tam_buffer=100; /* definição do tamanho do buffer de entrada */

void inverter(char* str_pointer, int index_ini, int index_fim){ /*funcao responsavel por inverter a ordem das letras nas palavras */
   if(index_ini >= index_fim){ /*confere se ele ja chegou no fim da checagem*/
     return;
   }
   char letra_ini = *(str_pointer + index_ini); /* basicamente, a funcao troca o primeiro caractere pelo ultimo, o segundo pelo penultimo, etc. */
   *(str_pointer + index_ini) = *(str_pointer + index_fim); /*ele faz isso de maneira recursiva, mudando só o indice dos caracteres que ele vai fazer a troca */
   *(str_pointer + index_fim) = letra_ini;
   inverter(str_pointer, ++index_ini, --index_fim);
}

void intervalo(char* entrada_ptr, int tam_entrada){ /* essa funcao servira para separarmos as palavras recebidas na entrada, utilizando o cactere ' ' como divisor */
  int index_check = 0; /* esses indices que ele define no comeco sao os que serao enviados para a inversao */
  int index_envio_ini = 0; /* vamos usar um indice de inicio e um de termino,ambos contendo inicialmente os "limites" da entrada, ie, indice 0 e indice tamanho_da_string -1 */
  int index_envio_fim = tam_entrada; /* a funcao tambem usara um outro indice que servira para fazermos a varredura na string e encontrarmos os pontos de divisao, o index_check */
  while(index_check < tam_entrada - 1){ /* colocamos um loop que servira para vermos se ja chegamos no fim da checagem */
   char car_check = *(entrada_ptr + index_check); /*pega o caractere atual apontado pelo pointeiro da entrada + indice atual */
      if(car_check == ' '){ /*aqui ele checa se esse caractere e igual ao ' ', nosso divisor */
        index_envio_fim = index_check - 1; /* caso for igual, ele atualizara o indice de fim, no caso, um anterior do que ele esta */
        inverter(entrada_ptr, index_envio_ini, index_envio_fim); /* e envia esses indices, junto com o ponteiro da string de entrada, para serem invertidos na funcao acima */
        index_envio_ini = ++index_check; /* por fim, ele atualiza o indice de incio que sera enviado numa proxima chamada para a funcao de inverter, agora esse indice e um depois do indice que continha o caractere ' ' */
      }
    ++index_check; /* vai para o proximo indice */
  }
  index_envio_fim = index_check; /* aqui, o indice de checagem atingiu o limite da string, portanto, determina que esse sera o ultimo indice de final a ser enviado */
  inverter(entrada_ptr, index_envio_ini, index_envio_fim); /* chama a funcao de inverter uma ultima vez */
  return; 
}

int main() { /* esse e o loop principal, ele nao faz muita coisa */
  char buffer[tam_buffer];
  fgets(buffer, tam_buffer, stdin); /* ele so recebe a string de entrada */
  intervalo(buffer, strlen(buffer) - 1); /*e nvia a string para a funcao que dividira as palavras */
  printf("%s", buffer); /* e, apos ser realizada toda a operacao de inversao, printa o resultado na tela */
  return 0;
}
