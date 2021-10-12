const int DATA_PIN = 2;
const int LATCH_PIN = 3;
const int CLOCK_PIN = 4;
const int NUMBER_OF_OUTPUT_PINS = 3;
int OUTPUT_PINS[] = {DATA_PIN, LATCH_PIN, CLOCK_PIN};

void SetOutputPins(int[], int);

void setup() 
{
  SetOutputPins(OUTPUT_PINS, NUMBER_OF_OUTPUT_PINS);
}

void loop() 
{

}

void SetOutputPins(int outputPins[], int numberOfPins);
{
  for (int i = 0; i < numberOfPins; i++)
  {
    pinMode(outputPins[i], OUTPUT);
  }
}
