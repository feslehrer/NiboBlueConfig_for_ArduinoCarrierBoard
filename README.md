# NiboBlueConfig für das Arduino-Carrier-Board
Hex-File zur Konfiguration des Nibo Bluetooth-Adapters mit dem Arduino-Carrier-Board. Das Tool ist insbesondere nützlich, wenn für den Unterricht mehrere NiboBlues konfiguriert werden müssen. Damit hat jeder BT-Dongel im Klassenraum einen eindeutigen Namen, der leicht zugeordnet werden kann.  
<br>Diese Beschreibung geht von folgender Hardware aus:
- <a href="https://ase-schlierbach.de">Arduino-Carrier-Board </a> (AS-Elektronik)
- <a href="https://ase-schlierbach.de/produkt/atmel-studio/">ATmega328pXplained-Mini</a> (AS-Elektronik)
- <a href="https://www.reichelt.de/bluetooth-modul-fuer-nibobee-nibo-bee-blue-p129272.html?&nbc=1&trstct=lsbght_sldr::91023">NiboBee Bluetooth Adapter</a> (Reichelt)

<br><img src="https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/21ef073d-c8ab-4bad-b23e-c3f9dcc63723" alt="Anschluss des NiboBee-Bluetooth-Adapter" width="600">

## Konfiguration des Nibo-Bluetooth-Adapters

Der NiboBee-Bluetooth-Adapter wird über die serielle Schnittstelle mit sogenannten AT-Befehlen konfiguriert. Dazu existiert ein Konfigurationsprogramm  für den ATmega328P-Controller, in dem der Name, die PIN und die Baudrate des Adapters eingestellt werden kann. 
### Vorbereitung Hardware/Firmware
1.	Verbinden Sie den NiboBee-Bluetooth-Adapter gemäß dem Schaltschema oben mit dem Carrier-Board.

2.	Programmieren Sie die Firmware **niboConfigAVR.elf** mit einem geeigneten Programmiertool. Z.B. Microchip-Studio/DeviceProgramming. 
<br><t><img src="https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/85b13a33-4f7d-408b-80d8-36e6db6d7200" alt="Microchip-Studio: Device Programming" width="500">

### Anleitung Konfigurationsprogramm
1.	Namensprefix (Robby) und Pin (1234) des Adapters sind in der Firmware vorgegeben. Eigene Anpassungen können im MicrochipStudio-Projekt im Ordner "niboConfigAVR" vorgenommen werden. Das Projekt wurde mit Hilfe der Technischen Richtlinie FA205 umgesetzt.

2.	Zu Beginn muss die aktuelle Baudrate des NiboBlue eingestellt werden: 9600, 19200, 38400, 57600. 
<t><img src="https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/51ad9f2d-c4b5-4f66-aff2-4c88e22559fe" alt="Baudraten-Einstellung" width="300">
<br>Bei falscher Baudrate wird „Error“ angezeigt und es kann erneut eingestellt werden.

3.	Nun wird die Verbindung geprüft und die Firmware abgefragt.

4.	Anschließend muss eine Nummer eingestellt werden, die an den Prefix-Namen Robby angehängt wird. Wichtig: Diese sollte eindeutig sein!
<br><t><img src="https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/65a58bee-b0c8-443d-9368-e3a264cae643" alt="Robby-Nr. einstellen" width="300">

5.	Abschließend kann eine neue Baudrate eingestellt werden.

6.	Das Programm ist bereit zur Konfiguration des nächsten Adapters. Die Nummer wird fortlaufend erhöht.

## Sonstige Ressourcen
Das Arduino-Carrier-Board ist unter www.ase-schlierbach.de erhältlich
<br><img src="https://user-images.githubusercontent.com/24614659/236320998-94544814-81e8-421b-9627-0c5e2c16ead0.png" alt="Arduino-Carrier-Board" width="600">
<br>Weitere Ressourcen zum Carrier-Board sind:
+ ATmega328P-Xplained Mini mit Microchip-Studio: https://github.com/feslehrer/FA205.git
+ ArduinoUno/Nano mit ATmega328P und ArduinoIDE: https://github.com/feslehrer/FA205_Library_for_Arduino.git

letzte Änderung: 25.3.2024@Rah
