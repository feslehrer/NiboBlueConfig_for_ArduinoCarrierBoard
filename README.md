# NiboBlueConfig für das Arduino-Carrier-Board
Hex-File zur Konfiguration des Nibo Bluetooth-Adapters mit dem Arduino-Carrier-Board.
Diese Beschreibung geht von folgender Hardware aus:
- Arduino-Carrier-Board
- ATmega328P-Xplained-mini
- NiboBee Bluetooth Adapter

<br><img src="https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/21ef073d-c8ab-4bad-b23e-c3f9dcc63723" alt="Anschluss des NiboBee-Bluetooth-Adapter" width="600">

## Konfiguration des Nibo-Bluetooth-Adapters

Der NiboBee-Bluetooth-Adapter wird über die serielle Schnittstelle mit sogenannten AT-Befehlen konfiguriert. Dazu existiert ein Konfigurationsprogramm  für den ATmega328P-Controller, in dem der Name, die PIN und die Baudrate des Adapters eingestellt werden kann. 

1.	Verbinden Sie den NiboBee-Bluetooth-Adapter gemäß des Schaltschemas oben mit dem Carrier-Board.

3.	Programmieren Sie den NiboBlue-Adapter (Datei: niboConfigAVR.elf) mit einem geeigneten Programmiertool. Z.B. Microchip-Studio/DeviceProgramming. 
<t><img src="https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/85b13a33-4f7d-408b-80d8-36e6db6d7200" alt="Microchip-Studio: Device Programming" width="500">

4.	Name und Pin können im Programmcode in den String-Variablen name[] und pin[] angepasst werden. Standard: Name = Robby, Pin = 1234
Vorsicht: Verwenden Sie keine Sonderzeichen.

5.	Übersetzen und Übertragen Sie das Programm auf den Controller.

6.	Zu Beginn muss die aktuelle Baudrate des NiboBlue eingestellt werden: 9600, 19200, 38400, 57600. 
<t><img src="https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/51ad9f2d-c4b5-4f66-aff2-4c88e22559fe" alt="Baudraten-Einstellung" width="300">
<br>Bei falscher Baudrate wird „Error“ angezeigt und es kann erneut eingestellt werden.

7.	Nun wird die Verbindung geprüft und die Firmware abgefragt.

8.	Anschließend muss eine Nummer eingestellt werden, die an den Namen des NiboBlue angehängt wird. Dieser sollte eindeutig sein.
<br><t><img src="https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/65a58bee-b0c8-443d-9368-e3a264cae643" alt="Robby-Nr. einstellen" width="300">

9.	Zum Schluss kann eine neue Baudrate eingestellt werden.

<p>Das Arduino-Carrier-Board ist unter www.ase-schlierbach.de erhältlich
![image](https://github.com/feslehrer/FA205_Library_for_Arduino/assets/24614659/97ba22d6-7ddc-4444-a178-783176a95a53)
<br> Weitere Ressourcen sind:
+ ATmega328P-Xplained Mini mit Microchip-Studio: https://github.com/feslehrer/FA205.git
+ ArduinoUno/Nano mit ATmega328P und ArduinoIDE: https://github.com/feslehrer/FA205_Library_for_Arduino.git
