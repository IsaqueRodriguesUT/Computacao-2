const int flamePin = A0;    
const int clkPin = 9;
const int resetPin = 7;

void setup() {
Serial.begin(9600);

pinMode(clkPin, OUTPUT);
pinMode(resetPin, OUTPUT);

digitalWrite(resetPin, LOW);
delay(50);
digitalWrite(resetPin, HIGH);
}

void loop() {
int valor = analogRead(flamePin);  

Serial.println(valor);

// quanto menor o valor, mais forte a chama
if (valor < 300) {   
digitalWrite(clkPin, HIGH);
delay(10);
digitalWrite(clkPin, LOW);
}

delay(200);
}
