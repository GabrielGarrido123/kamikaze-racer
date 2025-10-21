

void peri_setup(){
  pinMode(buzzer,OUTPUT);
  pinMode(boton,INPUT);
  pinMode(led,OUTPUT);
}

void bipBkn(int freq, int t, int espera){
  //hace un sonido personalizado
  freq = constrain(freq, 200, 20000);
  tone(buzzer,freq, t);
  delay(t + espera); //tiempo de espera adicional entre tonos
}

void bip(){
  //un sonidito generico
  tone(buzzer,2250, 100);
  delay(200);
}

void esperarBoton(){
  //para las pruebas de motores y sensores es util
  while (digitalRead(boton) == false);
  bip(); //avisa de que el boton si fue presionado
}