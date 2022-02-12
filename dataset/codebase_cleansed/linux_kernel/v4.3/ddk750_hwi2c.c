int hwI2CInit(
unsigned char busSpeedMode
)
{
unsigned int value;
value = PEEK32(GPIO_MUX);
value = FIELD_SET(value, GPIO_MUX, 30, I2C) |
FIELD_SET(0, GPIO_MUX, 31, I2C);
POKE32(GPIO_MUX, value);
enableI2C(1);
value = PEEK32(I2C_CTRL);
if (busSpeedMode == 0)
value = FIELD_SET(value, I2C_CTRL, MODE, STANDARD);
else
value = FIELD_SET(value, I2C_CTRL, MODE, FAST);
value = FIELD_SET(value, I2C_CTRL, EN, ENABLE);
POKE32(I2C_CTRL, value);
return 0;
}
void hwI2CClose(void)
{
unsigned int value;
value = PEEK32(I2C_CTRL);
value = FIELD_SET(value, I2C_CTRL, EN, DISABLE);
POKE32(I2C_CTRL, value);
enableI2C(0);
value = PEEK32(GPIO_MUX);
value = FIELD_SET(value, GPIO_MUX, 30, GPIO);
value = FIELD_SET(value, GPIO_MUX, 31, GPIO);
POKE32(GPIO_MUX, value);
}
static long hwI2CWaitTXDone(void)
{
unsigned int timeout;
timeout = HWI2C_WAIT_TIMEOUT;
while ((FIELD_GET(PEEK32(I2C_STATUS), I2C_STATUS, TX) != I2C_STATUS_TX_COMPLETED) &&
(timeout != 0))
timeout--;
if (timeout == 0)
return (-1);
return 0;
}
static unsigned int hwI2CWriteData(
unsigned char deviceAddress,
unsigned int length,
unsigned char *pBuffer
)
{
unsigned char count, i;
unsigned int totalBytes = 0;
POKE32(I2C_SLAVE_ADDRESS, deviceAddress & ~0x01);
do {
POKE32(I2C_RESET, 0);
if (length < MAX_HWI2C_FIFO)
count = length - 1;
else
count = MAX_HWI2C_FIFO - 1;
POKE32(I2C_BYTE_COUNT, count);
for (i = 0; i <= count; i++)
POKE32(I2C_DATA0 + i, *pBuffer++);
POKE32(I2C_CTRL, FIELD_SET(PEEK32(I2C_CTRL), I2C_CTRL, CTRL, START));
if (hwI2CWaitTXDone() != 0)
break;
length -= (count + 1);
totalBytes += (count + 1);
} while (length > 0);
return totalBytes;
}
static unsigned int hwI2CReadData(
unsigned char deviceAddress,
unsigned int length,
unsigned char *pBuffer
)
{
unsigned char count, i;
unsigned int totalBytes = 0;
POKE32(I2C_SLAVE_ADDRESS, deviceAddress | 0x01);
do {
POKE32(I2C_RESET, 0);
if (length <= MAX_HWI2C_FIFO)
count = length - 1;
else
count = MAX_HWI2C_FIFO - 1;
POKE32(I2C_BYTE_COUNT, count);
POKE32(I2C_CTRL, FIELD_SET(PEEK32(I2C_CTRL), I2C_CTRL, CTRL, START));
if (hwI2CWaitTXDone() != 0)
break;
for (i = 0; i <= count; i++)
*pBuffer++ = PEEK32(I2C_DATA0 + i);
length -= (count + 1);
totalBytes += (count + 1);
} while (length > 0);
return totalBytes;
}
unsigned char hwI2CReadReg(
unsigned char deviceAddress,
unsigned char registerIndex
)
{
unsigned char value = (0xFF);
if (hwI2CWriteData(deviceAddress, 1, &registerIndex) == 1)
hwI2CReadData(deviceAddress, 1, &value);
return value;
}
int hwI2CWriteReg(
unsigned char deviceAddress,
unsigned char registerIndex,
unsigned char data
)
{
unsigned char value[2];
value[0] = registerIndex;
value[1] = data;
if (hwI2CWriteData(deviceAddress, 2, value) == 2)
return 0;
return (-1);
}
