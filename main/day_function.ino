

int internalHourSunrise=0;
void sunrise(long hourOfDay,float period){
  
  if(period==0){ //RESET SUNRISE
    valueSunrise=0;
    internalHourSunrise=0;
  }else{
    if(internalHourSunrise==0){
      internalHourSunrise=hourOfDay;
    }
    int uno=hourOfDay-internalHourSunrise; //DIFF from previous cycle
    /*Serial.print("VALUES ==> ");
    Serial.print(hourOfDay);
    Serial.print(" - ");
    Serial.print(internalHourSunrise);
    Serial.print(" - ");
    Serial.print(uno);
    Serial.print(" - ");
    Serial.println(255/period*uno);*/
    valueSunrise=SUNRISE_MAX_VALUE/period*uno;
    if(valueSunrise>SUNRISE_MAX_VALUE)
      valueSunrise=SUNRISE_MAX_VALUE;
    /*Serial.print("SUNRISE: ");
    Serial.println(valueSunrise);*/
  }
  
}

int internalHourSunset=0;
void sunset(long hourOfDay,float period){
  if(period==0){
    valueSunset=0;
    internalHourSunset=0;
  }else{  
    if(internalHourSunset==0){
      internalHourSunset=hourOfDay;
    }  
    int uno=hourOfDay-internalHourSunset; //DIFF from previous cycle
    valueSunset=(255/period)*uno;
    if(valueSunset>255)
      valueSunset=255;
    /*Serial.print("SUNSET: ");
    Serial.println(valueSunset);*/
  } 
  
}

void night(bool reset){
  //Serial.println("NIGHT");
  if(reset)
    valueNight=0;
  else{
    valueNight=255;
    valueDay=0; 
  }
}

int internalHourDay=0;

void day(bool reset,bool decrement,float period){
  //Serial.println("DAY");
  if(reset){
    valueDay=0;
    internalHourDay=0;
  }else{
    if(!decrement){
      valueDay=DAY_MAX_VALUE;
      valueNight=0;
    }else{
      if(internalHourDay==0){
        internalHourDay=hourOfDay;
      }
      int uno=hourOfDay-internalHourDay; //DIFF from previous cycle
      valueDay-=(period/DAY_MAX_VALUE);
      if(valueDay<0)
        valueDay=0;
    }
  }
}
