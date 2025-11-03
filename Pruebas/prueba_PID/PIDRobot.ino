int ref = 0; //valor al q queremos llegar
int Tp = 100; //velocidad base. Si no me equivoco, esta deberia variar en el tiempo en base a que tan rapido quiere ir el robot :o
int error = 0; //aca se almacena el error
int integral = 0; //aca la integral
int lastError = 0; //aca el ultimo error
int derivada = 0; //aca la derivada

int vIzq = 0;
int vDer = 0;

int PID(int posicion, float Kp, float Ki, float Kd){
  error = posicion - ref;
  integral = integral + error;
  derivada = error - lastError;
  float giro = Kp * error + Ki * integral + Kd * derivada;
  lastError = error; //para guardar el ultimo error

  return constrain(int(giro),-255,255);
}

//void loop(){
//  int pos = lecturaSensores();
//  PID(pos);
//  moverMotores(vIzq, vDer);
//  
//}