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
const int ONE_SECOND_PERIOD = 500;
const int CHANGE_CLOCK_OUTPUT_PERIOD = ONE_SECOND_PERIOD * 5;
const int SCREEN_REFRESH_PERIOD = 30;
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
int loopCounter = 0;
int tixClock[SQUARE_MATRIX_SIZE][SQUARE_MATRIX_SIZE] = {{0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
              const int MINUTES_BUTTON_PIN = 5;                                                                     //Se definen los numeros de los pins de los botones
const int HOURS_BUTTON_PIN = 6;                                                                       
const int MODIFY_HOUR_PIN = 7;                                                                        
const int NUMBER_OF_INPUT_PINS = 3;                                                                   //Se define cuantos pines de entrada se van a utilizar                                                               
int INPUT_PINS[] = {MINUTES_BUTTON_PIN, HOURS_BUTTON_PIN, MODIFY_HOUR_PIN};                           //Se define un array en el cual estan los pines de los botones
const int DATA_PIN = 2;                                                                               //Se definen las variables para los pines que se van a utilizar en el shift register
const int LATCH_PIN = 3;
const int CLOCK_PIN = 4;
const int NUMBER_OF_OUTPUT_PINS = 3;                                                                  //Se define cuantos pines de salida se van a utilizar      
int OUTPUT_PINS[] = {DATA_PIN, LATCH_PIN, CLOCK_PIN};                                                 //Se define un array en el cual estan los pines del shift register
const int ONE_SECOND_PERIOD = 500;                                                                    //Se define un delay 
const int CHANGE_CLOCK_OUTPUT_PERIOD = ONE_SECOND_PERIOD * 5;                                         //Se define un delay en base del delay de one second period
const int SCREEN_REFRESH_PERIOD = 30;                                                                 //Se define un delay para saber cada cuanto se cambia la pantalla
const int SQUARE_MATRIX_SIZE = 8;                                                                     //Se define una constante para saber que tan grande va a ser la matriz 
const int hourTensNumberOfPossibleLeds = 2;                                                           //Se define una constante que es igual a los posibles leds de las decenas de las horas
const int hourUnitsNumberOfPossibleLeds = 9;                                                          //Se define una constante que es igual a los posibles leds de las unidades de las horas
const int minuteTensNumberOfPossibleLeds = 6;                                                         //Se define una constante que es igual a los posibles leds de las decenas de los minutos
const int minuteUnitsNumberOfPossibleLeds = 9;                                                        //Se define una constante que es igual a los posibles leds de las unidades de los minutos
int hour = 0;                                                                                         //Se define una variable que es igual a la hora que van a ser cuando se inicie el circuito
int minute = 0;                                                                                       //Se define una variable que es igual a los minutos que van a ser cuando se inicie el circuito
int second = 0;                                                                                       //Se define una variable que es igual a los segundos que va a ser cuando se inicie el circuito
int hourTens = 0;                                                                                     //Se define una variable que es igual a las decenas de las horas
int hourUnits = 0;                                                                                    //Se define una variable que es igual a las unidades de las horas
int minuteTens = 0;                                                                                   //Se define una variable que es igual a las decenas de los minutos
int minuteUnits = 0;                                                                                  //Se define una variable que es igual a las decenas de las horas
int loopCounter = 0;                                                                                  //Se define una variable que es igual a las veces que se ha hecho el loop
int tixClock[SQUARE_MATRIX_SIZE][SQUARE_MATRIX_SIZE] = {{0,0,0,0,0,0,0,0},                            //Se define un array con la matriz
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0},
                                                        {0,0,0,0,0,0,0,0}};
int hourTensPossibleleds[hourTensNumberOfPossibleLeds][2] = {{0,1},                                   //Se define un array con las cordenadas de los posibles leds de las decenas de las horas
                                                             {1,0}};
int hourUnitsPossibleleds[hourUnitsNumberOfPossibleLeds][2] = {{0,4},                                 //Se define un array con las cordenadas de los posibles leds de las unidades de las horas
                                                               {0,5},
                                                               {0,6},
                                                               {1,4},
                                                               {1,5},
                                                               {1,6},
                                                               {2,4},
                                                               {2,5},
                                                               {2,6}};
int minuteTensPossibleLeds[6][2] = {{5,1},                                                            //Se define un array con las cordenadas de los posibles leds de las decenas de los minutos
                                    {5,2},
                                    {6,1},
                                    {6,2},
                                    {7,1},
                                    {7,2}};
int minuteUnitsPossibleLeds[9][2] = {{5,4},                                                           //Se define un array con las cordenadas de los posibles leds de las unidades de los minutos
                                     {5,5},
                                     {5,6},
                                     {6,4},
                                     {6,5},
                                     {6,6},
                                     {7,4},
                                     {7,5},
                                     {7,6}};

void SetInputPins(int[], int);                                                                        //Se definen todos los prototipos de las funciones
void SetOutputPins(int[], int);
int GetTensFromNumber(int);
int GetUnitsFromNumber(int);
int GiveMeRandomNumber(int, int);
int AddOneBasedOnInput(int, int);
void UpdateClock();
void PrintEightByEightMatrix(int[][8]);
void PrintIntArray(int[], int);
void ZeroOutEightByEightMatrix (int[][8]);
bool IsIntegerInArray(int [], int, int);
void LightUpChosenLeds(int , int , int [][2], int [][8]);
byte ConvertEightByEightArrayToByte(int []);
void ShiftOutEightByEightMatrixScreen(int [][8], int, int, int);
void FillArrayWithInteger(int [], int, int);

void setup() 
{
    SetInputPins(INPUT_PINS, NUMBER_OF_INPUT_PINS);                                                   //Se definen los pines de entrada como INPUT
    SetOutputPins(OUTPUT_PINS, NUMBER_OF_OUTPUT_PINS);                                                //Se definen los pines de entrada como OUTPUT
    Serial.begin(9600);                                                                               //Se inicia el monitor en serie 
}

void loop() 
{
    if ((digitalRead(MODIFY_HOUR_PIN) && (loopCounter % ONE_SECOND_PERIOD == 0)) || (loopCounter % CHANGE_CLOCK_OUTPUT_PERIOD == 0))   
    {
        hourTens = GetTensFromNumber(hour);                                                                                              //Dice que el resultado de la funcion GetTensFromNumber es igual a hourTens
        hourUnits = GetUnitsFromNumber(hour);                                                                                            //Dice que el resultado de la funcion GetUnitsFromNumber es igual a hourUnits
        minuteTens = GetTensFromNumber(minute);                                                                                          //Dice que el resultado de la funcion GetTensFromNumber es igual a minuteTens
        minuteUnits = GetUnitsFromNumber(minute);                                                                                        //Dice que el resultado de la funcion GetUnitsFromNumber es igual a minuteUnits
        ZeroOutEightByEightMatrix(tixClock);                                                                                             //Llama a la funcion ZeroOutEightByEightMatrix para poner el valor de la matrix a 0                                                      
        LightUpChosenLeds(hourTens, hourTensNumberOfPossibleLeds, hourTensPossibleleds, tixClock);                                       //LLama a la funcion LightUpChosenLeds para prender los leds de las decenas de la hora
        LightUpChosenLeds(hourUnits, hourUnitsNumberOfPossibleLeds, hourUnitsPossibleleds, tixClock);                                    //LLama a la funcion LightUpChosenLeds para prender los leds de las unidades de la hora
        LightUpChosenLeds(minuteTens, minuteTensNumberOfPossibleLeds, minuteTensPossibleLeds, tixClock);                                 //LLama a la funcion LightUpChosenLeds para prender los leds de las decenas de los minutos
        LightUpChosenLeds(minuteUnits, minuteUnitsNumberOfPossibleLeds, minuteUnitsPossibleLeds, tixClock);                              //LLama a la funcion LightUpChosenLeds para prender los leds de las unidades de los minutos
        if (digitalRead(MODIFY_HOUR_PIN))                                                                                                //Este if dice que si el pin de modificar hora se realizara lo que esta dentro del codigo
        {
            second = -1;                                                                                                                 //se define la variable del segundo igual a -1 
            hour = AddOneBasedOnInput(HOURS_BUTTON_PIN, hour);                                                                           //El resultado de la funcion AddOneBasedOnInput es igual a la hora
            minute = AddOneBasedOnInput(MINUTES_BUTTON_PIN, minute);                                                                     //El resultado de la funcion AddOneBasedOnInput es igual a los minutos
             
        } 
    }
    if (loopCounter % ONE_SECOND_PERIOD == 0)                                                                                            //Este if define que el reciduo entre las dos variables es igual a 0 se llama a la funcion UpdateClock
    {
        UpdateClock();
    }
    ShiftOutEightByEightMatrixScreen(tixClock, CLOCK_PIN, DATA_PIN, LATCH_PIN);                                                          //Se llama a la funcion ShiftOutEightByEightMatrixScreen para imprimir 
    loopCounter++;                                                                                                                       //Se le suma 1 a la variable loopCounter
}


void SetInputPins(int inputPins[], int numberOfInputPins)                                                                                //Esta funcion define los pines de entrada  
{
    for (int i = 0; i < numberOfInputPins; i++)                                                                                          //Este for dice que si i es menor al numero de pins de salida va a realizar lo que esta dentro del for
    {
        pinMode(inputPins[i], INPUT);                                                                                                    //Define el valor que tenga i como una salida
    }
}

void SetOutputPins(int outputPins[], int numberOfPins)                                                                                   //Esta funcion define los pines de entrada
{
    for (int i = 0; i < numberOfPins; i++)                                                                                               //Este for dice que si i es menor al numero de pins de entrada va a realizar lo que esta dentro del for
    {
        pinMode(outputPins[i], OUTPUT);                                                                                                  //Define el valor que tenga i como una entrada
    }
}

int AddOneBasedOnInput(int inputPin, int numberToUpdate)                                                                                 //Esta funcion lo que realiza es sumar uno a una variable con un boton 
{
    if (digitalRead(inputPin))                                                                                                           //Este if dice que si el pin de entrada esta en HIGH se realiza lo que esta dentro del if
    {
        numberToUpdate++;                                                                                                                //Le suma 1 a la variable que se ingresa al inicio
    }
    return(numberToUpdate);                                                                                                              //Devuelve el valor del numero que se sumó
}

int GetTensFromNumber(int number)                                                                                                        //Esta funcion realiza la funcion de obtener las decenas de un valor
{
    int tensNumber;                                                                                                                      //Se define una variable
    tensNumber = number / 10;                                                                                                            //Se divide el numero entre 10 y esto lo guarda el valor de tensNumber
    return tensNumber;                                                                                                                   //Devuelve el valor de tensNumber
}

int GetUnitsFromNumber(int number)                                                                                                       //Esta funcion realiza la funcion de obtener las unidades de un valor
{
    int unitsNumber;                                                                                                                     //Se define una variable
    unitsNumber = number % 10;                                                                                                           //Se saca el residuo del numero entre 10 y esto lo guarda el valor de tensNumber
    return unitsNumber;                                                                                                                  //Devuelve el valor de unitsNumber 
}

int GiveMeRandomNumber(int lowerLimit, int upperLimit)                                                                                   //Esta funcion da un numero random
{
    int randomNumber;                                                                                                                    //Se define una variable
    randomNumber = random(lowerLimit, upperLimit + 1);                                                                                   //La funcion random da un numero aleatorio y esto la guarda randomNumber
    return randomNumber;                                                                                                                 //Devuelve el valor de randomNumber 
}

void UpdateClock()                                                                                                                       //Esta funcion lo que hace es hacer el funcionamiento de un reloj
{
    second = second + 1;                                                                                                                 //Se le suma 1 a la variable de second
    if(second == 60)                                                                                                                     //Si second es igual a 60 se hace lo que esta dentro del if
    {
        second = 0;                                                                                                                      //Pone la variable second en 0
        minute = minute + 1;                                                                                                             //Le suma 1 a los minutos 
    }  
    if(minute == 60)                                                                                                                     //Si minute es igual a 60 se hace lo que esta dentro del if
    {
        minute = 0;                                                                                                                      //Pone la variable minute en 0
        hour = hour + 1;                                                                                                                 //Le suma 1 a los minutos 
    }  
    if (hour == 24)                                                                                                                      //Si hour es igual a 24 se hace lo que esta dentro del if
    {
        hour = 0;                                                                                                                        //Pone la variable hour en 0  
    }
}

void PrintEightByEightMatrix(int matrix[8][8])                                                                                           //Esta funcion imprime la matrix en el puerto en serie
{
    for(int i = 0; i < 8; i++)                                                                                                           //Este for dice que si i es menor a 8 va a realizar lo que esta dentro del for                                                                              
    {
        for(int j = 0; j < 8; j++)                                                                                                       //Este for dice que si j es menor a 8 va a realizar lo que esta dentro del for
        {    
            Serial.print(matrix[i][j]);                                                                                                  //imprime el valor i y j del array
        } 
        Serial.println();                                                                                                                
    }
    Serial.println();
}


bool IsIntegerInArray(int array[], int lenght, int numberToCheck)                                                                        //Esta funcion ve si hay un valor que se ingresa dentro del array
{
    for(int i = 0; i < lenght; i++)                                                                                                      //Este for dice que si i es menor a lengt va a realizar lo que esta dentro del for
    {
        if (array[i] == numberToCheck)                                                                                                   //Este if dice que si dentro del array esta el numero que se busca devuelva un true y si no un false
        {
            return true;
        }
    }
    return false;  
}

void PrintIntArray(int array[], int lenght)                                                                                              //Imprime un array
{  
    for(int i = 0; i < lenght; i++)                                                                                                      //Este for dice que si i es menor a lengt va a realizar lo que esta dentro del for
    {
        Serial.print(array[i]);                                                                                                          //Imprime el array
        Serial.print(",");
    }
    Serial.println();
}

void ZeroOutEightByEightMatrix (int matrix[8][8])                                                                                        //Esta funcion pone toda la matriz en 0
{
    for(int i = 0; i < 8; i++)                                                                                                          //Este for dice que si i es menor a 8 va a realizar lo que esta dentro del for
    {
        for(int j = 0; j < 8; j++)                                                                                                      //Este for dice que si j es menor a 8 va a realizar lo que esta dentro del for
        {
            matrix[i][j] = 0;                                                                                                           //Pone el valor del array de la matrix en 0
        }
    }
}

void LightUpChosenLeds(int numberOfLedsToChoose, int numberOfPossibleLeds, int ledsCoordinates[][2], int ledMatrix[][8])                //Se especifica que se utilizará que son 4 variables, la primera define los numeros de leds por escoger, la siguiente el número de los posibles leds, el que le sigue da un array de coordenadas y el ultimo da un array que tiene una matriz 8x8
{
    int chosenLeds[numberOfPossibleLeds];                                                                                               //Realiza un array de los posibles leds
    FillArrayWithInteger(chosenLeds, numberOfPossibleLeds, 42);                                                                         //Llama a la función FillArrayWithInteger para que rellene un array con un número que se le especifica
    int numberOfChosenLeds = 0;                                                                                                         //Se le especifica un valor a numberOfChosenLeds el que es 0
    int randomNumber;                                                                                                                   //Se define una variable
    while(numberOfChosenLeds < numberOfLedsToChoose)                                                                                    //Realiza una comparación donde si numberOfChosenLeds es menor numberOfLedsToChoosediciendo va a continuar con el código
    {
        randomNumber = GiveMeRandomNumber(0, numberOfPossibleLeds - 1);                                                                 //Da un número aleatorio basado el en los posibles numeros que se le dan
        if (!IsIntegerInArray(chosenLeds, numberOfLedsToChoose, randomNumber))                                                          //Si en el array no esta el número aleatorio lo va a guardar y usar en la siguiente función, si no va a volver a buscar otro número.
        {
            chosenLeds[numberOfChosenLeds] = randomNumber;                                                                              //Se le añade los números aleatorios a un array
            numberOfChosenLeds++;                                                                                                       //Se le suma 1 a numberOfChosenLeds
        }                     
    }
  
  for(int i = 0; i < numberOfLedsToChoose; i++)                                                                                         //if the variable i is less than number of leds to choose it will do the code that is inside the for.
    {
        int chosenLed = chosenLeds[i];                                                                                                  //The variable of chossen led equals of chosen leds that has the variable i 
        int chosenRow = ledsCoordinates[chosenLed][0];                                                                                  //Da las coordenadas de las filas
        int chosenColumn = ledsCoordinates[chosenLed][1];                                                                               //Da las coordenadas de las columnas
        ledMatrix[chosenRow][chosenColumn] = 1;                                                                                         //Recolecta las coordenadas y pone un 1 en esa posición en la matriz
    }
}

byte ConvertEightByEightArrayToByte(int array[])                                                                                        //Devuelve una variable byte, tambien se espeifica que se va a usar un array
{  
    byte resultingByte = 0;                                                                                                             //Se le especifica un valor a resultingByte el que es 0
    for(int j = 0; j < 8; j++)                                                                                                          //Hace un loop donde que se va hacer 8 veces y se va sumando por cada loop
    {
        resultingByte = resultingByte << 1;                                                                                             //Se mueve resultingByte un espacio hacia la izquierda
        resultingByte = resultingByte + array[j];                                                                                       //Se le suma 1 a resultingByte de un array
    }
    return resultingByte;                                                                                                               //Retorna el valor con el que terminó resultingByte
}

void ShiftOutEightByEightMatrixScreen(int matrix[][8], int clockPin, int dataPin, int latchPin)                                         //Se especifica que se usará un array con una matriz 8x8 y 3 variables que son los pines de los ShiftRegisters
{
    for(int j = 0; j < 8; j++)                                                                                                          //Hace un loop se va hacer 8 veces y se va sumando por cada loop
    {
        digitalWrite(latchPin,LOW);                                                                                                     //Apaga un pin digital
        byte rowData = 128 >> j;                                                                                                        //Se le asigna a rowData un valor de 128 y que se mueva a la derecha
        byte columnData = ~ConvertEightByEightArrayToByte(matrix[j]);                                                                   //Se le asigna a columnData la función ConvertEightByEightArrayToByte y se niega para que de unos
        shiftOut(dataPin, clockPin, MSBFIRST, columnData);                                                                              //Se especifica el pin de data, el pin de clock, despues se especifica si se usa más o menos significativo, y por último el valor de las columnas en byte
        shiftOut(dataPin, clockPin, MSBFIRST, rowData);                                                                                 //Se especifica el pin de data, el pin de clock, despues se especifica si se usa más o menos significativo, y por último el valor de las filas en byte
        digitalWrite(latchPin,HIGH);                                                                                                    //Prende un led digital
    }
}

void FillArrayWithInteger(int arrayToFill[], int arrayLength, int number)                                                               //Se especifica que se utilizará un array, una variable que especifica un largo y una especifica un número
{ 
    for (int i = 0; i < arrayLength; i++)                                                                                               //Hace un loop donde que se va hacer la cantidad de veces que especifique arrayLength y se va sumando por cada loop
    {
        arrayToFill[i] = number;                                                                                                        //Rellena un array con un número 
    }  
}
