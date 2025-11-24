const int flamePin = 8;    // Pino do Arduino ligado à saída digital (D0) do sensor de chama
const int clkPin = 9;      // Pino do Arduino ligado ao pino CLK do 74HC74
const int resetPin = 7;    // Pino do Arduino ligado ao pino CLR do 74HC74

void setup() {
Serial.begin(9600);      // Inicializa a comunicação serial para monitorar valores no computador

pinMode(flamePin, INPUT);   // Define o pino do sensor como entrada (lê HIGH ou LOW)
pinMode(clkPin, OUTPUT);    // Define o pino que gera o pulso de clock como saída
pinMode(resetPin, OUTPUT);  // Define o pino que controla o reset do 74HC74 como saída

// ------- RESET AUTOMÁTICO DO SISTEMA AO LIGAR -------
// O flip-flop 74HC74 liga em estado indefinido. Essas linhas garantem que ele
// comece desligado (Q = 0) quando o Arduino iniciar.

digitalWrite(resetPin, LOW);   // Força o CLR do 74HC74 para nível baixo → limpa o flip-flop
delay(50);                     // Pequeno atraso para garantir o reset
digitalWrite(resetPin, HIGH);  // Retorna o CLR para nível alto → operação normal
}

void loop() {
int estado = digitalRead(flamePin);  // Lê o valor digital do sensor:
// LOW  = chama detectada
// HIGH = sem chama

Serial.println(estado);              // Mostra no monitor serial (para depuração)

// ------- DETECÇÃO DE CHAMA -------
// Se o sensor detectar fogo (estado LOW), o Arduino envia um pulso no pino CLK.
// Esse pulso faz o 74HC74 mudar o estado de Q para 1, acionando o alarme.

if (estado == LOW) {          // Se chama for detectada...
digitalWrite(clkPin, HIGH); // Sobe o clock
delay(10);                  // Mantém por alguns milissegundos
digitalWrite(clkPin, LOW);  // Desce o clock → Flip-flop registra o pulso
}

delay(200);   // Aguarda 200 ms para evitar leituras muito rápidas
}
