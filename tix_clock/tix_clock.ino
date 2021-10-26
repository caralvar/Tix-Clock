const int MINUTES_BUTTON_PIN = 5;
const int HOURS_BUTTON_PIN = 6;
const int MODIFY_HOUR_PIN = 7;
const int NUMBER_OF_INPUT_PINS = 3;
int INPUT_PINS[] = {MINUTES_BUTTON_PIN, HOURS_BUTTON_PIN, MODIFY_HOUR_PIN};
const int DATA_PIN = 2;
const int LATCH_PIN = 3;
const int CLOCK_PIN = 4;
const int NUMBER_OF_OUTPUT_PINS = 3;
int OUTPUT_PINS[] = {DATA_PIN, LATCH_PIN, CLOCK_PIN};
const int SECONDS_PERIOD_IN_MS = 1000;
const int SQUARE_MATRIX_SIZE = 8;
const int hourTensNumberOfPossibleLeds = 2;
const int hourUnitsNumberOfPossibleLeds = 9;
const int minuteTensNumberOfPossibleLeds = 6;
const int minuteUnitsNumberOfPossibleLeds = 9;
int hour = 0;
int minute = 0;
int second = 0;
int hourTens = 0;
int hourUnits = 0;
int minuteTens = 0;
int minuteUnits = 0;
int tixClock[SQUARE_MATRIX_SIZE][SQUARE_MATRIX_SIZE] = {{0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0}};
int hourTensPossibleleds[hourTensNumberOfPossibleLeds][2] = {{0,1},
                                                             {1,0}};
int hourUnitsPossibleleds[hourUnitsNumberOfPossibleLeds][2] = {{0,4},
                                                               {0,5},
                                                               {0,6},
                                                               {1,4},
                                                               {1,5},
                                                               {1,6},
                                                               {2,4},
                                                               {2,5},
                                                               {2,6}};
int minuteTensPossibleLeds[6][2] = {{5,1},
                                    {5,2},
                                    {6,1},
                                    {6,2},
                                    {7,1},
                                    {7,2}};
int minuteUnitsPossibleLeds[9][2] = {{5,4},
                                     {5,5},
                                     {5,6},
                                     {6,4},
                                     {6,5},
                                     {6,6},
                                     {7,4},
                                     {7,5},
                                     {7,6}};

void SetInputPins(int[], int);
void SetOutputPins(int[], int);
int GetTensFromNumber(int);
int GetUnitsFromNumber(int);
int GiveMeRandomNumber(int, int);
int AddOneBasedOnInput(int, int);
void UpdateClock();
void PrintEightByEightMatrix(int[][8]);
void PrintIntArray(int[], int);
bool IsIntegerInArray(int [], int, int);

void setup() 
{
    SetInputPins(INPUT_PINS, NUMBER_OF_INPUT_PINS);
    SetOutputPins(OUTPUT_PINS, NUMBER_OF_OUTPUT_PINS);
    Serial.begin(9600);
}

void loop() 
{
    if (digitalRead(MODIFY_HOUR_PIN))
    {
        second = -1;
        hour = AddOneBasedOnInput(HOURS_BUTTON_PIN, hour);
        minute = AddOneBasedOnInput(MINUTES_BUTTON_PIN, minute);    
    } 
    UpdateClock();
    Serial.print(hour);
    Serial.print(" : ");
    Serial.print(minute);
    Serial.print(" : ");
    Serial.println(second);
  
    //Getting digite from clock
    hourTens = GetTensFromNumber(hour);
    hourUnits = GetUnitsFromNumber(hour);
    minuteTens = GetTensFromNumber(minute);
    minuteUnits = GetUnitsFromNumber(minute);
    Serial.print("HourTens: ");
    Serial.print(hourTens);
    Serial.print(" HourUnits: ");
    Serial.print(hourUnits);
    Serial.print(" MinuteTens: ");
    Serial.print(minuteTens);
    Serial.print(" MinuteUnits: ");
    Serial.println(minuteUnits);
    PrintEightByEightMatrix(tixClock);
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

int AddOneBasedOnInput(int inputPin, int numberToUpdate)
{
    if (digitalRead(inputPin))
    {
        numberToUpdate++; 
    }
    return(numberToUpdate);
}

int GetTensFromNumber(int number)
{
    int tensNumber;
    tensNumber = number / 10;
    return tensNumber;
}

int GetUnitsFromNumber(int number)
{
    int unitsNumber;
    unitsNumber = number % 10;
    return unitsNumber;  
}

int GiveMeRandomNumber(int lowerLimit, int upperLimit)
{
    int randomNumber;
    randomNumber = random(lowerLimit, upperLimit + 1);
    return randomNumber;
}

void UpdateClock() 
{
    second = second + 1;
    if(second == 60)
    {
        second = 0;
        minute = minute + 1; 
    }  
    if(minute == 60)
    {
        minute = 0;
        hour = hour + 1;  
    }  
    if (hour == 24)
    {
        hour = 0;  
    }
}

void PrintEightByEightMatrix(int matrix[8][8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {    
            Serial.print(matrix[i][j]);
        } 
        Serial.println();
    }
    Serial.println();
}


bool IsIntegerInArray(int array[], int lenght, int numberToCheck)
{
    for(int i = 0; i < lenght; i++)
    {
        if (array[i] == numberToCheck)
        {
            return true;
        }
    }
    return false;  
}

void PrintIntArray(int array[], int lenght)
{  
    for(int i = 0; i < lenght; i++)
    {
        Serial.print(array[i]);
        Serial.print(",");
    }
    Serial.println();
}
