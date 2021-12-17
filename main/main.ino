#define PWM_PIN1 3 //Alba
#define PWM_PIN2 5 //Giorno
#define PWM_PIN3 6 //Tramonto
#define PWM_PIN4 9 //Notte

#define DAY_HOURS 24
#define CYCLE_TIMEOUT 300
#define CYCLE_INCREMENT 600

int cycleCount=0;

int hourOfDay=0;
int minute=0;

bool inc=true;
int valueSunrise = 0;
int valueSunset = 0;
int valueDay = 0;
int valueNight = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PWM_PIN1, OUTPUT);
  pinMode(PWM_PIN2, OUTPUT);
  pinMode(PWM_PIN3, OUTPUT);
  pinMode(PWM_PIN4, OUTPUT);
}

//ONE CYCLE IS ONE SECONDS
void loop() {
  cycleCount+=CYCLE_INCREMENT;
  Serial.write("ORA: ");
  Serial.println(hourOfDay);

  if(cycleCount>0 && (cycleCount % 60==0)){
    minute+=cycleCount/60;
    cycleCount=0;
  }

  if(minute>0 && minute % 60==0){
    minute=0;
    if(hourOfDay==23){
      hourOfDay=0;
    }else{
      hourOfDay++;
    }
  }
  
  if(hourOfDay>=0 && hourOfDay<=7){
    night();
  }
  if(hourOfDay>=5 && hourOfDay<=9){
    //PERIOD 4h
    sunrise((hourOfDay*60)+minute,300);
  }
  if(hourOfDay>9){
    sunrise(hourOfDay,0);
  }
  if(hourOfDay>=8 && hourOfDay<=19){
    day();
  }
  if(hourOfDay>=16 &&hourOfDay<=20){
    //PERIOD 4h
    sunset((hourOfDay*60)+minute,300);
  }
  if(hourOfDay>=20 && hourOfDay<=24){
    night();
  }
  if(hourOfDay>20){
    sunset(hourOfDay,0);
  }
  
  
  
  analogWrite(PWM_PIN1, valueSunrise);
  analogWrite(PWM_PIN2, valueDay);
  analogWrite(PWM_PIN3, valueSunset);
  analogWrite(PWM_PIN4, valueNight);

  delay(CYCLE_TIMEOUT);
}
