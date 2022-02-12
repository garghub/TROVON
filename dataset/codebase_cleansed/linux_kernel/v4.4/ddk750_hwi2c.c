int sm750_hw_i2c_init(
unsigned char bus_speed_mode
)
{
unsigned int value;
value = PEEK32(GPIO_MUX);
value = FIELD_SET(value, GPIO_MUX, 30, I2C) |
FIELD_SET(0, GPIO_MUX, 31, I2C);
POKE32(GPIO_MUX, value);
enableI2C(1);
value = PEEK32(I2C_CTRL);
if (bus_speed_mode == 0)
value = FIELD_SET(value, I2C_CTRL, MODE, STANDARD);
else
value = FIELD_SET(value, I2C_CTRL, MODE, FAST);
value = FIELD_SET(value, I2C_CTRL, EN, ENABLE);
POKE32(I2C_CTRL, value);
return 0;
}
void sm750_hw_i2c_close(void)
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
static long hw_i2c_wait_tx_done(void)
{
unsigned int timeout;
timeout = HWI2C_WAIT_TIMEOUT;
while ((FIELD_GET(PEEK32(I2C_STATUS),
I2C_STATUS, TX) != I2C_STATUS_TX_COMPLETED) &&
(timeout != 0))
timeout--;
if (timeout == 0)
return (-1);
return 0;
}
static unsigned int hw_i2c_write_data(
unsigned char addr,
unsigned int length,
unsigned char *buf
)
{
unsigned char count, i;
unsigned int total_bytes = 0;
POKE32(I2C_SLAVE_ADDRESS, addr & ~0x01);
do {
POKE32(I2C_RESET, 0);
if (length < MAX_HWI2C_FIFO)
count = length - 1;
else
count = MAX_HWI2C_FIFO - 1;
POKE32(I2C_BYTE_COUNT, count);
for (i = 0; i <= count; i++)
POKE32(I2C_DATA0 + i, *buf++);
POKE32(I2C_CTRL,
FIELD_SET(PEEK32(I2C_CTRL), I2C_CTRL, CTRL, START));
if (hw_i2c_wait_tx_done() != 0)
break;
length -= (count + 1);
total_bytes += (count + 1);
} while (length > 0);
return total_bytes;
}
static unsigned int hw_i2c_read_data(
unsigned char addr,
unsigned int length,
unsigned char *buf
)
{
unsigned char count, i;
unsigned int total_bytes = 0;
POKE32(I2C_SLAVE_ADDRESS, addr | 0x01);
do {
POKE32(I2C_RESET, 0);
if (length <= MAX_HWI2C_FIFO)
count = length - 1;
else
count = MAX_HWI2C_FIFO - 1;
POKE32(I2C_BYTE_COUNT, count);
POKE32(I2C_CTRL,
FIELD_SET(PEEK32(I2C_CTRL), I2C_CTRL, CTRL, START));
if (hw_i2c_wait_tx_done() != 0)
break;
for (i = 0; i <= count; i++)
*buf++ = PEEK32(I2C_DATA0 + i);
length -= (count + 1);
total_bytes += (count + 1);
} while (length > 0);
return total_bytes;
}
unsigned char sm750_hw_i2c_read_reg(
unsigned char addr,
unsigned char reg
)
{
unsigned char value = (0xFF);
if (hw_i2c_write_data(addr, 1, &reg) == 1)
hw_i2c_read_data(addr, 1, &value);
return value;
}
int sm750_hw_i2c_write_reg(
unsigned char addr,
unsigned char reg,
unsigned char data
)
{
unsigned char value[2];
value[0] = reg;
value[1] = data;
if (hw_i2c_write_data(addr, 2, value) == 2)
return 0;
return (-1);
}
