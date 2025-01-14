//================================================================
// Nome: sopradora 2024
// Atualizado em : 30/10/2024
//================================================================
//Portas de controle dos reles 

  const int rele01 = 35;   //balao de areia (1)
  const int rele02 = 37;   //Apertar balao (2)
  const int rele03 = 39;   //Abastecer balao de areia (3)
  const int rele04 = 41;   //Maçarico (4)
  const int rele05 = 43;   //Porta (5)
  const int rele06 = 45;   //Vareta (6)  
  const int rele07 = 49;   //Injetar areia (7)  
  const int rele08 = 47;   //Gas e ar do maçarico (8) 
  const int rele09 = 51;   //forma esquerda (9)
  const int rele10 = 53;   //forma direita (10) 
//===================================
//Botoes e chaves 

  int botao1 = 27;   // Botao de start frontal
  int sensor1 = 33;  // Sensor da vareta
  int sensor2 = 32;  //sensor do balao
  int chave1 = 26;   // Chave trocar entre furadinho e chave 2
  int chave2 = 25;   // chave trocar entre longo e curto

//================================================================
//Variaveis para armazenar dados

  int counter;     // Contador 
  int tempoBalao;  //"Tempo" maximo de achar o senso do balao

//================================================================
//Parametros para as funçoes

  unsigned long contador1 = millis();                    //Configuraçao do contador 
  void (*funcReset)() = 0;                               //Configuraçao da funçao de reset
//=========================================================================================================
void setup(){
//================================
//Desliga todos os reles
  digitalWrite(rele01, HIGH);  
  digitalWrite(rele02, HIGH);  
  digitalWrite(rele03, HIGH);  
  digitalWrite(rele04, HIGH);  
  digitalWrite(rele05, HIGH);  
  digitalWrite(rele06, HIGH);  
  digitalWrite(rele07, HIGH);  
  digitalWrite(rele08, HIGH);  
  digitalWrite(rele09, HIGH);  
  digitalWrite(rele10, HIGH); 
//================================
//Define as portas como saida
  pinMode(rele01, OUTPUT);
  pinMode(rele02, OUTPUT);
  pinMode(rele03, OUTPUT); 
  pinMode(rele04, OUTPUT);
  pinMode(rele05, OUTPUT);
  pinMode(rele06, OUTPUT);
  pinMode(rele07, OUTPUT);
  pinMode(rele08, OUTPUT); 
  pinMode(rele09, OUTPUT);
  pinMode(rele10, OUTPUT);
//========================
  pinMode(botao1, OUTPUT);
  pinMode(sensor1, OUTPUT);
  pinMode(sensor2, OUTPUT);
  pinMode(chave1, OUTPUT);
  pinMode(chave2, OUTPUT);
//================================
//inicia as comunicaçoes
  Serial.begin(9600);  //Liga a comunicaçao serial
}  
//=========================================================================================================
void loop(){
//================================
//Desliga todos os reles
  digitalWrite(rele01, HIGH);  
  digitalWrite(rele02, HIGH);  
  digitalWrite(rele03, HIGH);  
  digitalWrite(rele04, HIGH);  
  digitalWrite(rele05, HIGH);  
  digitalWrite(rele06, HIGH);  
  digitalWrite(rele07, HIGH);  
  digitalWrite(rele08, HIGH);  
  digitalWrite(rele09, HIGH);  
  digitalWrite(rele10, HIGH); 
//================================  
//Seleçao do Furadinho
if (digitalRead(chave1) == HIGH) {
//================================
  if (digitalRead(botao1) == HIGH) {
	  for (counter = 0; counter < 1; ++counter) {
	  tempofuradinho();} delay(1000);}
}
//================================================

//Seleçao do macho curto
else if (digitalRead(chave2) == HIGH) {
//================================
 
  if (digitalRead(sensor1) == HIGH && digitalRead(botao1) == HIGH) {
	  while (digitalRead(chave2) == HIGH) {
	  tempocurto();} delay(2000);}
}
//================================================
//seleçao do macho longo
else {
  if (digitalRead(sensor1) == HIGH) { 
    if (digitalRead(sensor1) == HIGH && digitalRead(botao1) == HIGH) {
	    while (digitalRead(chave2) == LOW && digitalRead(chave1) == LOW) {
      tempolongo();} delay(2000);}}
}}
//================================================================
//Tempo de ficar segurando o botao antes de começar furadinho
void tempofuradinho(){
  delay(1000);
  if (digitalRead(botao1) == HIGH) {
    furadinho45s();}
  else Serial.println("Reset!");
    delay(300);
  funcReset();
  }
//================================================================
//Tempo de ficar segurando o botao antes de começar Macho Curto
void tempocurto(){
  delay(1000);
  if (digitalRead(botao1) == HIGH) {
    while (digitalRead(chave2) == HIGH) {
	  machocurto();} delay(2000);}
  else Serial.println("Reset!");
    delay(300);
  funcReset();
  }
  
//================================================================
//Tempo de ficar segurando o botao antes de começar Macho longo
void tempolongo(){
  delay(1000);
  if (digitalRead(botao1) == HIGH) {
    while (digitalRead(chave2) == LOW && digitalRead(chave1) == LOW) {
      macholongo();} delay(2000);}
  else Serial.println("Reset!");
    delay(300);
  funcReset();
  }
//=========================================================================================================
void furadinho45s(){Serial.println("Furadinho rodando!");
//==========================================
//Inicio do programa do furadinho
//=========================== 
  digitalWrite(rele05, LOW);   //fechar as portas
  Serial.println("Fechando as portas");
  digitalWrite(rele09, LOW);  //fechar a forma direita
  digitalWrite(rele10, LOW);  //fechar a forma esquerda
  Serial.println("Fechando as formas");
//=========================== 
  delay(3000); // 3 segundos
//===========================
  digitalWrite(rele01, LOW);   //levar o Balão de areia 
  Serial.println("Balao de areia acionado");
//===========================  
  delay(2000); // 2 segundos
//===========================
  digitalWrite(rele02, LOW);   //Apertar balao de areia 
  Serial.println("Balao apertado");  
//============================
  delay(1000);  // 1 segundo
//============================
  digitalWrite(rele07, LOW);   //Liga Injetar areia
  Serial.println("Injetando areia!");
//============================
  delay(3000);  // 3 segundos
//============================
  digitalWrite(rele07, HIGH);  //Desliga Injetar areia
  Serial.println("Areia injetada");
//===========================
  delay(1000); // 1 segundos
//===========================
  digitalWrite(rele02, HIGH);  //Desapertar balao de areia
  Serial.println("Desapertando balao");
//===========================
  delay(1000); // 1 segundo
//===========================
  digitalWrite(rele01, HIGH);  //Voltar balao de areia
  Serial.println("Balao retornando");
//===========================
  delay(3000); // 3 segundos
//===========================
  digitalWrite(rele08, LOW); //Liga o Gas do maçarico
  Serial.println("Gas do maçarico acionado");
//===========================
  delay(1000); // 1 segundo
//===========================
  digitalWrite(rele02, LOW);    //Apertar balao de areia
  Serial.println("Balao apertado");
  digitalWrite(rele04, LOW);    //Levar maçarico
  Serial.println("Maçarico acionado"); 
//===========================
  delay(1000); // 1 segundos
//===========================
  digitalWrite(rele03, LOW);  //Liga abastecer balao de areia
  Serial.println("Abastecendo balao areia!");
//===========================
  delay(9000); // 9 segundos
//===========================
  digitalWrite(rele04, HIGH);   //Trazer maçarico
  digitalWrite(rele08, HIGH);   //Desliga o gas do maçarico
  Serial.println("Gas e maçarico desligados");
//===========================
  delay(11000); // 11 segundos  
//===========================
  digitalWrite(rele05, HIGH);  //Abrir as portas
  Serial.println("Abrindo as portas");
//===========================
  delay(2000); // 2 segundos
//===========================
  digitalWrite(rele09, HIGH);  //Abrir a forma direita
  digitalWrite(rele10, HIGH);  //Abrir a forma esquerda
  digitalWrite(rele03, HIGH);  //Desliga abastecer balao de areia
  Serial.println("Balao areia abstecido!");
  Serial.println("Abrindo as formas");
//===========================  
 delay(2000); // 2 segundos
//=========================== 
  Serial.println("Furadinho finalizado!");
  delay(300);
//===========================
}  
//=========================================================================================================

void machocurto(){Serial.println("Macho curto rodando!");   
if (digitalRead(sensor1) == HIGH) {  //Verifica se o pistao esta na posiçao de começar
//========================  
//Contagem regressiva das tentativas de ler o sensor magnetico do pistao do balao

    tempoBalao = 200;  //O numero sera multiplicado por 0.1 segundos (10 e igual a 1 segundo)

//========================
  Serial.println("Fechando as formas");
  digitalWrite(rele05, LOW);   //fechar porta de segurança
  digitalWrite(rele09, LOW);   //fechar a forma direita
  digitalWrite(rele10, LOW);   //fechar a forma esquerda 
//========================
  delay(3000); // 3 segundos
//========================
  digitalWrite(rele01, LOW);  //levar balao de areia
  Serial.println("Balao de areia acionado");
//=================================================================
//Le se o sensor do pistao do balao foi acionado

    while (digitalRead(sensor2) == LOW && (tempoBalao) > 0){  //leitura do sensor
    Serial.println("Balao fora da posiçao");
    delay(10);    //espera 0.05 segundo
    tempoBalao--;  //Tira 1 da contagem regressiva
    }

  Serial.println(tempoBalao);

//=================================================================
//Ve se o sensor do pistao do balao foi acionado para injetar areia

  if (tempoBalao > 0) {
    digitalWrite(rele02, LOW);  //Apertar balao de areia
    Serial.println("Balao apertado");
    digitalWrite(rele07, LOW);  //Liga Injetar areia na forma
    Serial.println("Injetando areia!");
  //========================
    delay(3000);  // 3 segundos
  //======================== 
  }

//=================================================================
  digitalWrite(rele01, HIGH); //Voltar balao de areia
  Serial.println("Balao retornando");
  digitalWrite(rele02, HIGH); //Desapertar balao de areia 
  Serial.println("Desapertando balao"); 
  digitalWrite(rele07, HIGH); //Desliga Injetar areia a forma   
  Serial.println("Areia injetada");
//========================
  delay(3000); // 3 segundos
//========================
  digitalWrite(rele08, LOW); //Liga o gas do maçarico
  Serial.println("Gas do maçarico acionado");
//========================
  delay(1000); // 1 segundo
//========================
  digitalWrite(rele04, LOW);  //Levar maçarico     
  Serial.println("Maçarico acionado"); 
//========================  
  delay(2000); // 2 segundos
//========================  
  digitalWrite(rele03, LOW);  //Liga abastecer balao de areia
  Serial.println("Abastecendo balao areia!");
//========================  
  delay(10000); // 10 segundos
//========================
  digitalWrite(rele04, HIGH);  //Trazer maçarico
  digitalWrite(rele08, HIGH); //Desliga o gas do maçarico
  Serial.println("Gas e maçarico desligados");
//========================     
  delay(2000); // 2 segundos
//========================
  digitalWrite(rele03, HIGH);  //Desliga Injetar areia
//========================     
  delay(1000); // 1 segundo
//========================
  digitalWrite(rele09, HIGH); //Abrir a Forma direita
  digitalWrite(rele10, HIGH); //Abrir a Forma esquerda
  Serial.println("Abrindo as formas");
//===========================    
  delay(1000); // 1 segundo
//===========================
  Serial.println("Levantar machos");
  digitalWrite(rele06, LOW); //levantando machos
//================================================
//Verifica se o pistao levantou antes de continuar
  Serial.println("Testando posiçao do pistao!");
  while (digitalRead(sensor1) == HIGH){
    Serial.println("Pistao fora da posiçao");
    delay(500);}
//================================================
  Serial.println("Pistao acionado continuando!");
//======================== 
  delay(1000); // 1 segundo
//========================
  digitalWrite(rele06, HIGH);  //Abaixar vareta
//========================
  Serial.println("Macho curto finalizado!");
  delay(1000);
//========================
}
else {
 Serial.println("Pistao fora da posiçao!");
 delay(2000);
}}
//=========================================================================================================
void macholongo(){Serial.println("Macho longo rodando!");   
//==========================================
if (digitalRead(sensor1) == HIGH) {  //Verifica se o pistao esta na posiçao de começar
  Serial.println("Fechando as formas");
  digitalWrite(rele09, LOW);   //fechar a forma direita
  digitalWrite(rele10, LOW);   //fechar a forma esquerda
  digitalWrite(rele05, LOW);   //fechar porta de segurança
//========================
  delay(3000); // 3 segundos
//========================
  digitalWrite(rele01, LOW);  //levar balao de areia
  Serial.println("Balao de areia acionado");
//========================
  delay(2000); // 2 segundos
//========================
  digitalWrite(rele02, LOW);  //Apertar balao de areia
  Serial.println("Balao apertado");
//========================  
  delay(1000);  // 1 segundo
//========================
  digitalWrite(rele07, LOW);  //Liga Injetar areia na forma
  Serial.println("Injetando areia!");
//========================
  delay(2000);  // 2 segundo
//========================
  digitalWrite(rele07, HIGH); //Desliga Injetar areia a forma   
  Serial.println("Areia injetada");
//========================  
  delay(2000); // 2 segundo
//========================
  digitalWrite(rele02, HIGH); //Desapertar balao de areia 
  Serial.println("Desapertando balao");
//========================
  delay(1000); // 1 segundo
//========================
  digitalWrite(rele01, HIGH); //Voltar balao de areia
  Serial.println("Balao retornando");
//========================
  delay(3000); // 3 segundos
//========================
  digitalWrite(rele08, LOW); //Liga o gas do maçarico
  Serial.println("Gas do maçarico acionado");
//========================
  delay(1000); // 1 segundo
//========================
  digitalWrite(rele02, LOW);  //Apertar balao de areia
  Serial.println("Balao apertado");
  digitalWrite(rele04, LOW);  //Levar maçarico     
  Serial.println("Maçarico acionado"); 
//========================  
  delay(2000); // 2 segundos
//========================  
  digitalWrite(rele03, LOW);  //Liga abastecer balao de areia
  Serial.println("Abastecendo balao areia!");
//========================  
  delay(14000); // 14 segundos
//========================
  digitalWrite(rele04, HIGH);  //Trazer maçarico
  digitalWrite(rele08, HIGH); //Desliga o gas do maçarico
  Serial.println("Gas e maçarico desligados");
//========================     
  delay(3000); // 3 segundos
//========================
  digitalWrite(rele09, HIGH); //Abrir a Forma direita
  digitalWrite(rele10, HIGH); //Abrir a Forma esquerda
  Serial.println("Abrindo as formas");
//===========================    
  delay(1000); // 1 segundos  
//===========================
  Serial.println("Levantar machos");
  digitalWrite(rele06, LOW); //levantando machos
//===========================
//Verifica se o pistao levantou antes de continuar
  Serial.println("Testando posiçao do pistao!");
  while (digitalRead(sensor1) == HIGH){
    Serial.println("Pistao fora da posiçao");
    delay(500);
  }
//======================== 
  Serial.println("Pistao acionado continuando!");
  delay(1000); // 1 segundos
//========================
  digitalWrite(rele02, HIGH);  //Desliga apertar balao de areia
  digitalWrite(rele03, HIGH);  //Desliga Injetar areia
  digitalWrite(rele06, HIGH);  //Abaixar vareta
//========================
  Serial.println("Macho longo finalizado!");
  delay(1000);
//========================
}
else {
 Serial.println("Pistao fora da posiçao!");
 delay(2000);
}
}
//=========================================================================================================
