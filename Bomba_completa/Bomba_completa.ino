#include <LiquidCrystal_I2C.h> //Biblioteca para o LCD funcionar
#include <Wire.h>

//Variaveis de conclusão dos desafios
int concluido1 = false;
int concluido2 = false;
int concluido3 = false;

//Configurar variaveis usadas no LCD
#define col 16 
#define lin 2 
#define ende 0x3F

int s = 300; 
int count = 1;

int hora, resto, minutos, segundos;

LiquidCrystal_I2C lcd_1(ende, col, lin);

unsigned long int tempoAnteriorCont;
unsigned long int tempoAnterior;
unsigned long int tempoAnterior1;
unsigned long int tempoAnterior2;

//Definindo botões e leds para desafio 3
const int botao1 = 50;
const int botao2 = 51;
const int botao3 = 52;
const int botao4 = 53;

const int led1 = 46;
const int led2 = 47;
const int led3 = 48;
const int led4 = 49; 

//Definindo pinos do visor que vai printar o hexadecimal
const int pinoA = 12; 
const int pinoB = 11; 
const int pinoC = 10; 
const int pinoD = 9; 
const int pinoE = 8; 
const int pinoF = 6; 
const int pinoG = 7; 
const int pinoPONTO = 5;
const int botao = 14;

const int led = 15;

int contador = 0;

//Função que printa A no visor
int functionA() {
  // acende os leds que são necessários para formar o número 0 (zero) e acende o ponto:
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, LOW);
  digitalWrite(pinoE, HIGH);
  digitalWrite(pinoF, HIGH);
  digitalWrite(pinoG, HIGH);
  digitalWrite(pinoPONTO, LOW);
  
  }

//Função que printa F no visor
int functionF() {
  // acende os leds que são necessários para formar o número 0 (zero) e acende o ponto:
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, LOW);
  digitalWrite(pinoE, HIGH);
  digitalWrite(pinoF, HIGH);
  digitalWrite(pinoG, HIGH);
  digitalWrite(pinoPONTO, LOW);
  
  }

//Função que printa 1 no visor
int function1() {
  // acende os leds que são necessários para formar o número 0 (zero) e acende o ponto:
  digitalWrite(pinoA, LOW);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, LOW);
  digitalWrite(pinoE, HIGH);
  digitalWrite(pinoF, HIGH);
  digitalWrite(pinoG, LOW);
  digitalWrite(pinoPONTO, LOW);
  
  }

//Função que apaga todo o visor
int functionLow() {
  
  digitalWrite(pinoA, LOW);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, LOW);
  digitalWrite(pinoE, LOW);
  digitalWrite(pinoF, LOW);
  digitalWrite(pinoG, LOW);
  digitalWrite(pinoPONTO, LOW);
  
  }

void setup() {

  //Limpa apaga e liga a luz de tras do LCD
  lcd_1.init(); 
  lcd_1.clear(); 
  lcd_1.backlight(); 

  //Colocando leds como saida
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);

//Colocando botões como entrada
pinMode(botao1, INPUT_PULLUP);
pinMode(botao2, INPUT_PULLUP);
pinMode(botao3, INPUT_PULLUP);
pinMode(botao4, INPUT_PULLUP);


  //Definindo os leds do visor como saida
  pinMode(pinoA, OUTPUT);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoC, OUTPUT);
  pinMode(pinoD, OUTPUT);
  pinMode(pinoE, OUTPUT);
  pinMode(pinoF, OUTPUT);
  pinMode(pinoG, OUTPUT);
  pinMode(pinoPONTO, OUTPUT);

  pinMode(led, OUTPUT);

  pinMode(botao, INPUT_PULLUP);

  //Definindo as portas do RGB e dos pontenciometros
  pinMode(A0 , INPUT);//vermelho
  pinMode(A1 , INPUT);//verde
  pinMode(A2 , INPUT); //azul
  pinMode(2 , OUTPUT);
  pinMode(3 , OUTPUT);
  pinMode(4 , OUTPUT);

  Serial.begin(9600);

}

//Função que transforma segundos em minutos e horas
void timer(int tempo){

  hora = tempo / 3600;
  resto = tempo % 3600;
  minutos = resto / 60;
  segundos = resto % 60;

}

//Função que liga a tela com as informações
void tela(){ 
  
  if (hora < 10){ 
    lcd_1.print(0);
    lcd_1.print(hora);
  }else{
    lcd_1.print(hora);
  }
  lcd_1.print(":");
  if (minutos < 10){
    lcd_1.print(0);
    lcd_1.print(minutos);
  }else{
    lcd_1.print(minutos);
  }
  lcd_1.print(":");
  if(segundos < 10){
    lcd_1.print(0);
    lcd_1.print(segundos);
  }else{
    lcd_1.print(segundos);
  }
  
}

void loop() {
  
  //Definindo a sequencia que o hexadecimal é mostrada
  if(millis()- tempoAnterior >= 500){
    tempoAnterior1 = millis();
    functionLow();
    function1();
  }
  if(millis()- tempoAnterior1 >= 1000){
    tempoAnterior2 = millis();
    functionLow();
    functionF();
    digitalWrite(pinoPONTO, HIGH);
  }
  if(millis()- tempoAnterior2 >= 1500){
    tempoAnterior = millis();
    functionLow();
    functionA();
    
  }

  //Clique dos botões para acender aas leds e resolver os desafios
if(digitalRead(botao1) == 0){
  
  digitalWrite(led1, HIGH);
  lcd_1.print(" Morte!!");
  delay(1000000);
  
  }
if(digitalRead(botao2) == 0){
  
  digitalWrite(led2, HIGH);
  Serial.print("FIO");
  concluido3 = true;
  
  }
if(digitalRead(botao3) == 0){
  
  digitalWrite(led3, HIGH);
  lcd_1.print(" Morte!!");
  delay(1000000);
  
  }
if(digitalRead(botao4) == 0){
  
  digitalWrite(led4, HIGH);
  lcd_1.print(" Morte!!");
  delay(1000000);
  }

  //Contando quantidade de cliques no botão
  if(digitalRead(botao) == LOW){
    digitalWrite(led, HIGH);
    contador++;
    delay(500);
  }else{
      digitalWrite(led, LOW);
  }
  if(contador == 7){
    digitalWrite(led, HIGH);
    Serial.print("HEXA");
    concluido1 = true;
  }
  if(contador > 7){
    lcd_1.print(" Morte!!");
    delay(1000000);
    }


 analogWrite(2, (analogRead(A2)/4)); // AnalogRead faz leituras entre 0 e 1023, enquanto analogWrite faz leituras entre 0 e 255. Dividindo o Read  por 4 faz com que ele possa ser recebido sem problemas pelo write ;) / Faz leitura da porta A2, divide o valor por 4, e envia para a porta A3.
 analogWrite(4, (analogRead(A0)/4)); // Faz leitura da porta A0, divide o valor por 4, e envia para a porta A4.
 analogWrite(3, (analogRead(A1)/4));// Faz leitura da porta A1, divide o valor por 4, e envia para a porta A5.

 
if((analogRead(A0) >= 500 and analogRead(A0) <= 690) and (analogRead(A2) >= 60 and analogRead(A2) <= 220) and ( analogRead(A1) <= 5)){
  Serial.println("RGB");
  concluido2 = true;
}

  lcd_1.setCursor(0, 0); 
  lcd_1.print("BOMBA 0193"); 
  lcd_1.setCursor(0, 1); 

  if (count == 1){ 
    if (s > 0){
      if (millis() - tempoAnteriorCont >= 1000){ 
        tempoAnteriorCont = millis();
        s--; 
        if (s == 0){
          count = 0; 
          lcd_1.print("Voce morreu!!");
          delay(1000000);
        }
      }
    }
  }
  //Ligar tela e timer
  timer(s);
  tela(); 

  
  if(concluido1 == true and concluido2 == true and concluido3 == true){
  lcd_1.clear();
  lcd_1.print("***Desarmado***");
  delay(1000000);
  }
}
