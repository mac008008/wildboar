#define BLUE_LED 26
#define LED_ON LOW
#define LED_OFF HIGH
#define SUBGHZ_CH		36			// channel number (frequency)
#define SUBGHZ_PANID	0xABCD		// panid
#define HOST_ADDRESS	0xAC96		// distination address

unsigned char gateopen[] = {"gate_open"};

void setup(void)
{
	SubGHz.init();					// initializing Sub-GHz
	pinMode(BLUE_LED,OUTPUT);
	pinMode(2,INPUT_PULLUP);
	digitalWrite(BLUE_LED,LED_ON);
	Serial.begin( 115200 ); 
}

void loop() {
	if (digitalRead(2) == HIGH){ 
		digitalWrite(BLUE_LED,LED_OFF);
		// Initializing
		SubGHz.begin(SUBGHZ_CH, SUBGHZ_PANID,  SUBGHZ_100KBPS, SUBGHZ_PWR_1MW);		// start Sub-GHz
		// preparing data
		SubGHz.send(SUBGHZ_PANID, HOST_ADDRESS, &gateopen, sizeof(gateopen),NULL);// send data	
		Serial.println(&gateopen);	
		// close
		SubGHz.close();																// Sub-GHz module sets into power down mode.
		sleep(1000);																// sleep
		return;
	} 
	else{ 
		digitalWrite(BLUE_LED,LED_ON);
	} 
}
 

