# NiboBlueConfig_for_ArduinoCarrierBoard
Hex-File zur Konfiguration des Nibo Bluetooth-Adapters mit dem Arduino-Carrier-Board.
![grafik](https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/21ef073d-c8ab-4bad-b23e-c3f9dcc63723)
<img src="https://user-images.githubusercontent.com/24614659/21ef073d-c8ab-4bad-b23e-c3f9dcc63723.jpg" alt="Anschluss des NiboBee-Bluetooth-Adapter" width="600">

Konfiguration des Nibo-Bluetooth-Adapters

Der NiboBee-Bluetooth-Adapter wird über die serielle Schnittstelle mit sogenannten AT-Befehlen konfiguriert. Dazu existiert ein Konfigurationsprogramm  für den ATmega328P-Controller, in dem der Name, die PIN und die Baudrate des Adapters eingestellt werden kann. 

1.	Verbinden Sie den NiboBee-Bluetooth-Adapter gemäß Anleitung mit dem Carrier-Board.

2.	Öffnen Sie das Projekt: „niboConfigAVR“ in Atmel Studio.

3.	Name und Pin können im Programmcode in den String-Variablen name[] und pin[] angepasst werden. Standard: Name = Robby, Pin = 1234
Vorsicht: Verwenden Sie keine Sonderzeichen.

4.	Übersetzen und Übertragen Sie das Programm auf den Controller.

5.	Zu Beginn muss die aktuelle Baudrate des NiboBlue eingestellt werden: 9600, 19200, 38400, 57600. 

![grafik](https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/51ad9f2d-c4b5-4f66-aff2-4c88e22559fe)
<p>Bei falscher Baudrate wird „Error“ angezeigt und es kann erneut eingestellt werden.

6.	Nun wird die Verbindung geprüft und die Firmware abgefragt.

7.	Anschließend muss eine Nummer eingestellt werden, die an den Namen des NiboBlue angehängt wird. Dieser sollte eindeutig sein. <p>

![grafik](https://github.com/feslehrer/NiboBlueConfig_for_ArduinoCarrierBoard/assets/24614659/65a58bee-b0c8-443d-9368-e3a264cae643)

8.	Zum Schluss kann eine neue Baudrate eingestellt werden.

