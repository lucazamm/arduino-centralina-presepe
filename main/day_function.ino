

int internalHourSunrise=0;
void sunrise(long hourOfDay,long period){
  
  if(period==0){
    valueSunrise=0;
    internalHourSunrise=0;
  }else{
    if(internalHourSunrise==0){
      internalHourSunrise=hourOfDay;
    }
    int uno=hourOfDay-internalHourSunrise;
    //uno=period-uno;
    //Serial.println(hourOfDay);
    //Serial.println(internalHourSunrise);
    //Serial.println(uno);
    valueSunrise=(period/255)*uno;
    Serial.write("SUNRISE: ");
    Serial.println(valueSunrise);
  }
  
}

int internalHourSunset=0;
void sunset(long hourOfDay,long period){
  if(period==0){
    valueSunset=0;
    internalHourSunset=0;
  }else{  
    if(internalHourSunset==0){
      internalHourSunset=hourOfDay;
    }  
    int uno=hourOfDay-internalHourSunset;
    uno=period-uno;
    Serial.println(uno);
    valueSunset=(period/255)*uno;
    Serial.write("SUNSET: ");
    Serial.println(valueSunset);
  } 
  
}

void night(){
  Serial.println("NIGHT");
  valueNight=255;
  valueDay=0;
}
void day(){
  Serial.println("DAY");
  valueDay=255;
  valueNight=0;
}
