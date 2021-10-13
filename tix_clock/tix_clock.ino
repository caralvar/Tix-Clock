const int MINUTES_BUTTON_PIN = 5;
const int HOURS_BUTTON_PIN = 6;
const int NUMBER_OF_INPUT_PINS = 2;
int INPUT_PINS[] = {MINUTES_BUTTON_PIN,HOURS_BUTTON_PIN};
const int DATA_PIN = 2;
const int LATCH_PIN = 3;
const int CLOCK_PIN = 4;
const int NUMBER_OF_OUTPUT_PINS = 3;
int OUTPUT_PINS[] = {DATA_PIN, LATCH_PIN, CLOCK_PIN};
int horadecimas;
int horaunidades;
int minutosdecimas;
int minutosunidades;
int h = 20;
int m = 57;
int s = 0;

void SetInputPins(int[], int);
void SetOutputPins(int[], int);

void setup() 
{
    SetInputPins(INPUT_PINS, NUMBER_OF_INPUT_PINS);
    SetOutputPins(OUTPUT_PINS, NUMBER_OF_OUTPUT_PINS);
}

void loop() 
{

}
  
void SetInputPins(int inputPins[], int numberOfInputPins)
{
    for (int i = 0; i < numberOfInputPins; i++)
    {
        pinMode(inputPins[i], INPUT);
    }
}

void SetOutputPins(int outputPins[], int numberOfPins)
{
    for (int i = 0; i < numberOfPins; i++)
    {
        pinMode(outputPins[i], OUTPUT);
    }
}
