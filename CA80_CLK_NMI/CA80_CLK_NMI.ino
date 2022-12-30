#define   RESET_        4     // Z80 RESET
#define   NMI           9     // NMI generowane przez TIMER1
#define   CLK           3     // Z80 CLK generowane przez TIMER2
#define   clockMode     1     // 0 - 8 MHz, 1 - 4 MHz


void setup()
{
  pinMode(RESET_, OUTPUT);                        
  digitalWrite(RESET_, LOW);                      

  // Initialize CLK @ 4/8MHz (@ Fosc = 16MHz). Z80 clock_freq = (Atmega_clock) / ((OCR2 + 1) * 2)
  ASSR &= ~(1 << AS2);                            // Set Timer2 clock from system clock
  TCCR2B |= (1 << CS20);                          // Set Timer2 clock to "no prescaling"
  TCCR2B &= ~((1 << CS21) | (1 << CS22));
  TCCR2A |= (1 << WGM21);                         // Set Timer2 CTC mode
  TCCR2A &= ~(1 << WGM20);
  TCCR2A |= (1 <<  COM2B0);                       // Set "toggle OC2 on compare match"
  TCCR2A &= ~(1 << COM2B1);                       // toggle - to znaczy zmien na przeciwny
  OCR2A = clockMode;                              // Set the compare value to toggle OC2 (0 = low or 1 = high)
  OCR2B = clockMode;
  pinMode(CLK, OUTPUT);                           // Set OC2 as output and start to output the clock

  // Leave the Z80 CPU running
  delay(1);                                       
  digitalWrite(RESET_, HIGH);                     // konczymy RESET
  delay(5);                                       // Dla pewnosci, ze CA80 ustawi wszystkie rejestry (zwlaszcza SP)
  // TIMER1 ustawiamy na 1000 Hz: czyli zmieniamy stan co 1 ms, wiec na wyjsciu otrzymamy 500 Hz
  TCCR1A = 0;                                     // zerujemy TCCR1A
  TCCR1A |= (0 << COM1A1) | (1 << COM1A0);         // D9 500 Hz NMI
  TCCR1B = 0;                                     // zerujemy TCCR1B
  TCCR1C |= (1 << FOC1A);
  TCNT1  = 0;                                     // zerujemy licznik
  // CTC mode
  TCCR1B |= (1 << WGM12);
  // ustawiamy prescaler
  TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10);
  //  1000 Hz
  OCR1A = 15999; // = 16000000 / (1 * 1000) - 1 (musi byc <65536)
  OCR1B = 15999; // wartosc prawie dowolna
  pinMode(NMI, OUTPUT);                           // D9 jako wyjscie
}


void loop()
{
  // put your main code here, to run repeatedly:

}
