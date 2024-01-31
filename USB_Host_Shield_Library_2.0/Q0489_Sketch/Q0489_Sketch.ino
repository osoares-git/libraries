/*
     Q0489
     AUTOR:   BrincandoComIdeias
     LINK:    https://www.youtube.com/brincandocomideias ; https://cursodearduino.net/
     COMPRE:  https://www.arducore.com.br/
     SKETCH:  USB HOST SHIELD
     DATA:    14/08/2019
*/

// INCLUSÃO DE BIBLIOTECAS
#include <hidboot.h>
#include <usbhub.h>
#include <SPI.h>

// DEFINIÇÕES


// DECLARAÇÃO DE VARIÁVEIS GLOBAIS
String codigoLido="";
bool leituraRealizada = false;

// INCLUSÃO DOS DEMAIS ARQUIVOS
#include "Leitor.h"

// ***************** INÍCIO DO SETUP *************************
void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando USB Host Shield");

  if (Usb.Init() == -1) {
    Serial.println("Algo deu errado :( ");
    Serial.println("Confira o Sketch");
  }
  delay( 200 );

  // CONFIGURA O OBJETO DO LEITOR DE CODIGO DE BARRAS
  Serial.println("Iniciando Leitor de Código de Barras");
  HidKeyboard.SetReportParser(0, &Prs);

  Serial.println("Setup concluído");
}
// ***************** FIM DO SETUP ***************************

// ***************** INÍCIO DO LOOP *************************
void loop() {
  // REALIZA A LEITURA DA PORTA USB DA SHIELD
  Usb.Task();

  // EXECUTA AS FUNÇÕES APÓS TER IDENTIFICADO UMA LEITURA COMPLETA
  if(leituraRealizada){
      
    Serial.print("Código lido: ");
    Serial.println(codigoLido);
   
    leituraRealizada = false;
    codigoLido = "";
  }

}
// ***************** FIM DO LOOP ***************************
