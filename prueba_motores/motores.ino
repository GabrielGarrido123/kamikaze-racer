//define pines (motor A es el izquierdo, y el B el derecho)
//en el driver, los pines A estan conectados al motor B, y viceversa. Los pines los defini para seguir la idea de A es izquierda y B es derecha
//o sea, los que dicen A efectivamente van a mover al motor A en el codigo (aunque realmente estamos moviendo al BINx del driver)
#define PWMA 5 //segun esquematico, pin 6
#define AIN1 8 //segun esquematico, pin 4
#define AIN2 9 //segun esquematico, pin 7

#define PWMB 6 //segun esquematico, pin 5
#define BIN1 4 //segun esquematico, pin 8
#define BIN2 7 //segun esquematico, pin 9

void driverM_setup(){
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(PWMB,OUTPUT);
}

void motorI(int num){
  if (num >= 0){
    //avanza
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else {
    //retrocede
    digitalWrite(AIN2, HIGH);
    digitalWrite(AIN1, LOW);
    num = num * (-1);
  }

  //mover el motor
  analogWrite(PWMA, num);
}

void motorD(int num){
  if (num >= 0){
    //avanza
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  } else {
    //retrocede
    digitalWrite(BIN2, HIGH);
    digitalWrite(BIN1, LOW);
    num = num * (-1);
  }

  //mover el motor
  analogWrite(PWMB, num);
}

void motores(int izq, int der){
  motorI(izq);
  motorD(der);
}