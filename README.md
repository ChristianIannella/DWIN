# DWIN
Esempi per display DWIN
(gli esempi sono per schermi con risoluzione 480x272)


![This is an image](https://github.com/ChristianIannella/DWIN/blob/main/Doc/DMG48270C043.jpg)


Qui troverai alcuni esempi per utilizzare display [DWIN](https://www.dwin-global.com/) con Arduino.

Questi display sono molto economici dispongono di un touch screen capacitivo e di un buzzer per il feedback.

Per cominciare avrai bisogno di un dispaly come [questo](https://www.dwin-global.com/4-3-inch-intelligent-display-dmg48270c043_04wcommercial-grade-product/), per caricare i dati sul display avrai bisogno di una microSD o del adattatore USB in dotazione.


Dal sito ufficiale scarica il software di sviluppo [DGUS_V7642](https://www.dwin-global.com/tool-page/) poi scarica i file da questo repository.
Potresti aver bisogno di installare questi driver [XR21X141X Driver](https://www.dwin-global.com/tool-page/)


Se vuoi utilizzare la microSD per caricare i dati nel display aassicurati che sia vuota, copia al suo interno la cartella `DWIN_SET`, inserisci la memoria nel display, accendilo, aspetta che completi le operazioni indicate sullo schermo, poi spegi e rimuovila. Alla prossima accensione il display mostrerà quello che hai caricato.

Se carichi i dati tramite adattatore apri il programma DGUS, importa o crea il tuo progetto, premi sull icona DGUS, si aprirà il Dwin PCKit clicca `Select Directory`
e seleziona la cartella `DWIN_SET` dopo di che fai clic su `Start Downloading`

Ora passiamo alla scheda Arduino. Il codice è scritto per un Arduino Uno ma potenzialmente funziona per qualsiasi scheda purche lavori a 5v, nel caso vogliate usare schede che lavorano a 3.3v abbaite cura di utilizzare un adattatore di livello.

Carica il file `arduino_switch_example` sulla tua scheda  e collegala al display.


![image](https://github.com/ChristianIannella/DWIN/blob/main/Doc/collegamenti.png)

Se tutto è andato a buon fine dovresti essere in grado di vedere un semplice menu e accendere o spegnere il led sul pin 13.

Per maggiori dettagli rimando alla [docomentazione ufficiale](https://github.com/ChristianIannella/DWIN/blob/main/Doc/DWIN%20DGUS%20DEV%20GUIDE_V43_2015.pdf)
