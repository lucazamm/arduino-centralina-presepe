#define PWM_PIN1 3
#define PWM_PIN2 5
#define PWM_PIN3 6
#define PWM_PIN4 9

int value = 0;
bool inc=true;

void setup() {
  Serial.begin(9600);
  pinMode(PWM_PIN1, OUTPUT);
  pinMode(PWM_PIN2, OUTPUT);
  pinMode(PWM_PIN3, OUTPUT);
  pinMode(PWM_PIN4, OUTPUT);
}

void loop() {
  /* analogWrite, come secondo parametro accetta valori da 0 a 
   * 255. 
  */
  analogWrite(PWM_PIN1, value);
  analogWrite(PWM_PIN2, value);
  analogWrite(PWM_PIN3, value);
  analogWrite(PWM_PIN4, value);
  if(inc)
    value++;
  else
    value--;

  if (value > 255){
    inc=false;
    value = 255;
  }
  if(value<0){
    inc=true;
    value=00;
  }
  delay(20);
}
