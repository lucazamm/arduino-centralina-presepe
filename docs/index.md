## Centralina Presepe per Arduino

L'obiettivo del progetto è stato di realizzare un algoritmo molto basilare per gestire le luci di un presepe.

La centralina permette di eseguire, durante una giornata virtuale di 24 ore, gli scenari di:

- Alba
- Giorno
- Tramonto
- Notte

## Note sul software

Definisce la durata della giornata
``` #define DAY_HOURS 24 ```


Imposta il timeout di 125 millisecondi per ogni ciclo
```
#define CYCLE_TIMEOUT 125
```

Imposta di quanti millisecondi incrementare il tempo della giornata dopo ogni ciclo
```
#define CYCLE_INCREMENT 120
```

Successivamente è calcolata l'ora del giorno e sulla base di essa sono pilotate le uscite dei Mosfet per gestire:
- il progresso dell'alba (normalmente led bianco caldo)
- l'accensione della luce del giorno (normalmente led bianco caldo)
- il progresso del tramonto (normalmente led rosso)
- l'accensione delle luci della notte (es.: le luci delle case)

## Hardware necessario

**Alimentatore 12V** 

L'alimentatore è usato per alimentare l'arduino e le strisce LED

**Striscia LED monocolore**

Importante monocolore a 12V

**Arduino Uno Rev 3**


**MOSFET** per il dimmer delle strisce LED

Sono caratterizzati per gestire in ingresso la tensione dell'alimentatore così da fornirla in uscita alla striscia LED secondo le direttive del software.

https://www.amazon.it/ICQUANZX-interruttore-Regolazione-Interruttore-elettronico/dp/B07VRCXGFY/ref=sr_1_20?__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2XUOCD8QXUWQF&keywords=pwm+arduino&qid=1648549221&sprefix=pwm+arduino%2Caps%2C116&sr=8-20


## Pinout

Di seguito le uscite PWM di Arduino da collegare ai circuiti Mosfet.
```
#define PWM_PIN1 3 //Alba
#define PWM_PIN2 5 //Giorno
#define PWM_PIN3 6 //Tramonto
#define PWM_PIN4 9 //Notte
```

Impostazioni sulla durata del ciclo del giorno

