static void swI2CWait(void)
{
#if 0
while (peekIO(0x3ce, 0x61) & 0x10);
#else
int i, Temp;
for (i = 0; i < 600; i++) {
Temp = i;
Temp += i;
}
#endif
}
void swI2CSCL(unsigned char value)
{
unsigned long ulGPIOData;
unsigned long ulGPIODirection;
ulGPIODirection = PEEK32(g_i2cClkGPIODataDirReg);
if (value) {
ulGPIODirection &= ~(1 << g_i2cClockGPIO);
POKE32(g_i2cClkGPIODataDirReg, ulGPIODirection);
} else {
ulGPIOData = PEEK32(g_i2cClkGPIODataReg);
ulGPIOData &= ~(1 << g_i2cClockGPIO);
POKE32(g_i2cClkGPIODataReg, ulGPIOData);
ulGPIODirection |= (1 << g_i2cClockGPIO);
POKE32(g_i2cClkGPIODataDirReg, ulGPIODirection);
}
}
void swI2CSDA(unsigned char value)
{
unsigned long ulGPIOData;
unsigned long ulGPIODirection;
ulGPIODirection = PEEK32(g_i2cDataGPIODataDirReg);
if (value) {
ulGPIODirection &= ~(1 << g_i2cDataGPIO);
POKE32(g_i2cDataGPIODataDirReg, ulGPIODirection);
} else {
ulGPIOData = PEEK32(g_i2cDataGPIODataReg);
ulGPIOData &= ~(1 << g_i2cDataGPIO);
POKE32(g_i2cDataGPIODataReg, ulGPIOData);
ulGPIODirection |= (1 << g_i2cDataGPIO);
POKE32(g_i2cDataGPIODataDirReg, ulGPIODirection);
}
}
static unsigned char swI2CReadSDA(void)
{
unsigned long ulGPIODirection;
unsigned long ulGPIOData;
ulGPIODirection = PEEK32(g_i2cDataGPIODataDirReg);
if ((ulGPIODirection & (1 << g_i2cDataGPIO)) != (~(1 << g_i2cDataGPIO))) {
ulGPIODirection &= ~(1 << g_i2cDataGPIO);
POKE32(g_i2cDataGPIODataDirReg, ulGPIODirection);
}
ulGPIOData = PEEK32(g_i2cDataGPIODataReg);
if (ulGPIOData & (1 << g_i2cDataGPIO))
return 1;
else
return 0;
}
static void swI2CAck(void)
{
return;
}
static void swI2CStart(void)
{
swI2CSDA(1);
swI2CSCL(1);
swI2CSDA(0);
}
static void swI2CStop(void)
{
swI2CSCL(1);
swI2CSDA(0);
swI2CSDA(1);
}
static long swI2CWriteByte(unsigned char data)
{
unsigned char value = data;
int i;
for (i = 0; i < 8; i++) {
swI2CSCL(0);
if ((value & 0x80) != 0)
swI2CSDA(1);
else
swI2CSDA(0);
swI2CWait();
swI2CSCL(1);
swI2CWait();
value = value << 1;
}
swI2CSCL(0);
swI2CSDA(1);
swI2CWait();
swI2CSCL(1);
swI2CWait();
for (i = 0; i < 0xff; i++) {
if (!swI2CReadSDA())
break;
swI2CSCL(0);
swI2CWait();
swI2CSCL(1);
swI2CWait();
}
swI2CSCL(0);
swI2CSDA(1);
if (i < 0xff)
return 0;
else
return -1;
}
static unsigned char swI2CReadByte(unsigned char ack)
{
int i;
unsigned char data = 0;
for (i = 7; i >= 0; i--) {
swI2CSCL(0);
swI2CSDA(1);
swI2CWait();
swI2CSCL(1);
swI2CWait();
data |= (swI2CReadSDA() << i);
}
if (ack)
swI2CAck();
swI2CSCL(0);
swI2CSDA(1);
return data;
}
static long swI2CInit_SM750LE(unsigned char i2cClkGPIO,
unsigned char i2cDataGPIO)
{
int i;
g_i2cClkGPIODataReg = GPIO_DATA_SM750LE;
g_i2cClkGPIODataDirReg = GPIO_DATA_DIRECTION_SM750LE;
g_i2cClockGPIO = i2cClkGPIO;
g_i2cDataGPIODataReg = GPIO_DATA_SM750LE;
g_i2cDataGPIODataDirReg = GPIO_DATA_DIRECTION_SM750LE;
g_i2cDataGPIO = i2cDataGPIO;
for (i = 0; i < 9; i++)
swI2CStop();
return 0;
}
long swI2CInit(
unsigned char i2cClkGPIO,
unsigned char i2cDataGPIO
)
{
int i;
if ((i2cClkGPIO > 31) || (i2cDataGPIO > 31))
return -1;
if (getChipType() == SM750LE)
return swI2CInit_SM750LE(i2cClkGPIO, i2cDataGPIO);
g_i2cClkGPIOMuxReg = GPIO_MUX;
g_i2cClkGPIODataReg = GPIO_DATA;
g_i2cClkGPIODataDirReg = GPIO_DATA_DIRECTION;
g_i2cClockGPIO = i2cClkGPIO;
g_i2cDataGPIOMuxReg = GPIO_MUX;
g_i2cDataGPIODataReg = GPIO_DATA;
g_i2cDataGPIODataDirReg = GPIO_DATA_DIRECTION;
g_i2cDataGPIO = i2cDataGPIO;
POKE32(g_i2cClkGPIOMuxReg,
PEEK32(g_i2cClkGPIOMuxReg) & ~(1 << g_i2cClockGPIO));
POKE32(g_i2cDataGPIOMuxReg,
PEEK32(g_i2cDataGPIOMuxReg) & ~(1 << g_i2cDataGPIO));
enableGPIO(1);
for (i = 0; i < 9; i++)
swI2CStop();
return 0;
}
unsigned char swI2CReadReg(
unsigned char deviceAddress,
unsigned char registerIndex
)
{
unsigned char data;
swI2CStart();
swI2CWriteByte(deviceAddress);
swI2CWriteByte(registerIndex);
swI2CStart();
swI2CWriteByte(deviceAddress + 1);
data = swI2CReadByte(1);
swI2CStop();
return data;
}
long swI2CWriteReg(
unsigned char deviceAddress,
unsigned char registerIndex,
unsigned char data
)
{
long returnValue = 0;
swI2CStart();
if ((swI2CWriteByte(deviceAddress) != 0) ||
(swI2CWriteByte(registerIndex) != 0) ||
(swI2CWriteByte(data) != 0)) {
returnValue = -1;
}
swI2CStop();
return returnValue;
}
