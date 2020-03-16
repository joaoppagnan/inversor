/* Data de submissao:15/03/2020
 * Nome:João Pedro de Oliveira Pagnan
 * RA:199727
 */

#include <stdio.h>
#include <string.h>

const int tam_buffer=100; /* definição do tamanho do buffer de entrada */

void inverter(char* str_pointer, int index_ini, int index_fim){
   if(index_ini >= index_fim){
     return;
   }
   char letra_ini = *(str_pointer + index_ini);
   *(str_pointer + index_ini) = *(str_pointer + index_fim);
   *(str_pointer + index_fim) = letra_ini;
   inverter(str_pointer, ++index_ini, --index_fim);
}

void intervalo(char* entrada_ptr, int tam_entrada){
  int index_check = 0;
  int index_envio_ini = 0;
  int index_envio_fim = tam_entrada;
  while(index_check < tam_entrada - 1){
   char car_check = *(entrada_ptr + index_check);
      if(car_check == ' '){
        index_envio_fim = index_check - 1;
        inverter(entrada_ptr, index_envio_ini, index_envio_fim);
        index_envio_ini = ++index_check;
      }
    ++index_check;
  }
  index_envio_fim = index_check;
  inverter(entrada_ptr, index_envio_ini, index_envio_fim);
  return;
}


int main() {
  char buffer[tam_buffer];
  fgets(buffer, tam_buffer, stdin);
  intervalo(buffer, strlen(buffer) - 1);
  printf("%s", buffer);
  return 0;
}
