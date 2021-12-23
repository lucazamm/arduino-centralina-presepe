#define PWM_PIN1 3 //Alba
#define PWM_PIN2 5 //Giorno
#define PWM_PIN3 6 //Tramonto
#define PWM_PIN4 9 //Notte

#define DAY_HOURS 24

/*
  with CYCLE_TIMEOUT=500:
  CYCLE_INCREMENT=240: about 6 minutes to complete one day
  CYCLE_INCREMENT=480: about 3 minutes to complete one day

  with CYCLE_TIMEOUT=250:
  CYCLE_INCREMENT=120: about 6 minutes to complete one day
  CYCLE_INCREMENT=240: about 3 minutes to complete one day


  
*/
#define CYCLE_TIMEOUT 125
#define CYCLE_INCREMENT 120

#define DAY_MAX_VALUE 100
#define SUNRISE_MAX_VALUE 100


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
  Serial.println("==== CENTRALINA PRESEPE 1.0 ====");
  pinMode(PWM_PIN1, OUTPUT);
  pinMode(PWM_PIN2, OUTPUT);
  pinMode(PWM_PIN3, OUTPUT);
  pinMode(PWM_PIN4, OUTPUT);
}

//ONE CYCLE IS ONE SECOND
void loop() {
  cycleCount+=CYCLE_INCREMENT;
  
  
  

  if(cycleCount>0 && (cycleCount % 60==0)){
    minute+=cycleCount/60;
    cycleCount=0;
  }

  if(minute>0 && minute>=60){
    minute=minute % 60;
    if(hourOfDay==23){
      hourOfDay=0;
    }else{
      hourOfDay++;
    }
  }
  //NIGHT
  if(hourOfDay>=0 && hourOfDay<=7){
    night(false);
  }//NIGHT - END
  if(hourOfDay>7){
    night(true);
  }
  //SUNRISE START
  if(hourOfDay>=5 && hourOfDay<=9){
    //PERIOD 4h 
    sunrise((hourOfDay*60)+minute,250);
  }
  //SUNRISE END
  if(hourOfDay>8){
    sunrise(hourOfDay,0);
  }
  //DAY START
  if(hourOfDay>=9 && hourOfDay<=15){
    day(false,false,0);
  }
  //DAY FADE OUT
  if(hourOfDay>15 && hourOfDay<=19){
    day(false,true,240);
  }
  //SUNSET START
  if(hourOfDay>=15 &&hourOfDay<=20){
    //PERIOD 4h
    sunset((hourOfDay*60)+minute,250);
  }
  //DAY END
  if(hourOfDay>19){
    day(true,false,0);
  }
  //NIGHT START
  if(hourOfDay>=17 && hourOfDay<=24){
    night(false);
  }
  //SUNSENT END
  if(hourOfDay>20){
    sunset(hourOfDay,0);
  }
  
  
  
  analogWrite(PWM_PIN1, valueSunrise);
  analogWrite(PWM_PIN2, valueDay);
  analogWrite(PWM_PIN3, valueSunset);
  analogWrite(PWM_PIN4, valueNight);

  /*Serial.println("====== VALUES ======");
  Serial.print("TIME\t\t");
  Serial.print(hourOfDay);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(cycleCount);
  
  Serial.print("valueDay\t"); Serial.println(valueDay); 
  Serial.print("valueSunrise\t"); Serial.println(valueSunrise); 
  Serial.print("valueSunset\t"); Serial.println(valueSunset); 
  Serial.print("valueNight\t"); Serial.println(valueNight); 

  Serial.println("===================");*/

  delay(CYCLE_TIMEOUT);
}
