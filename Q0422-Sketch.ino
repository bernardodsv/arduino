
bool leituraSensor;
bool leituraAnterior;

void setup() {
  
  //Entrada do sensor
  pinMode(8, INPUT);

  //Saida do sensor
  pinMode(12, OUTPUT);
  
  //Led
  pinMode(5, OUTPUT);  //liga led vermelho
  pinMode(6, OUTPUT);  //liga led amarelo
  pinMode(7, OUTPUT);  //liga led verde
}

void loop() {

  leituraSensor = digitalRead(8);

  if (leituraSensor == HIGH) {
     //Quando estiver precisando de água
     digitalWrite(5, HIGH);  //vermelho
     digitalWrite(7, LOW);   //verde
  } else {
     //Caso já esteja úmido
     digitalWrite(5, LOW);   //vermelho
     digitalWrite(7, HIGH);  //verde
  }

  //Quando entra no estado seco  
  if (leituraSensor && !leituraAnterior) {
     delay(5000);
     digitalWrite(5, LOW);   //vermelho
     digitalWrite(6, HIGH);  //amarelo

     while (digitalRead(8)) {
        digitalWrite(12, HIGH);   // faz uma leitura do sensor a cada 0,5 segundos para mandar água novamente
        delay(500);
        digitalWrite(12, LOW);   

        delay(10000);          
     }
     digitalWrite(6, LOW);  //se estiver entrando no estado de seco pisca o led amarelo
  }
  
  leituraAnterior = leituraSensor;
}
