int sm750_hw_i2c_init(
unsigned char bus_speed_mode
)
{
unsigned int value;
value = peek32(GPIO_MUX);
value |= (GPIO_MUX_30 | GPIO_MUX_31);
poke32(GPIO_MUX, value);
sm750_enable_i2c(1);
value = peek32(I2C_CTRL) & ~(I2C_CTRL_MODE | I2C_CTRL_EN);
if (bus_speed_mode)
value |= I2C_CTRL_MODE;
value |= I2C_CTRL_EN;
poke32(I2C_CTRL, value);
return 0;
}
void sm750_hw_i2c_close(void)
{
unsigned int value;
value = peek32(I2C_CTRL) & ~I2C_CTRL_EN;
poke32(I2C_CTRL, value);
sm750_enable_i2c(0);
value = peek32(GPIO_MUX);
value &= ~GPIO_MUX_30;
value &= ~GPIO_MUX_31;
poke32(GPIO_MUX, value);
}
static long hw_i2c_wait_tx_done(void)
{
unsigned int timeout;
timeout = HWI2C_WAIT_TIMEOUT;
while (!(peek32(I2C_STATUS) & I2C_STATUS_TX) && (timeout != 0))
timeout--;
if (timeout == 0)
return -1;
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
poke32(I2C_SLAVE_ADDRESS, addr & ~0x01);
do {
poke32(I2C_RESET, 0);
if (length < MAX_HWI2C_FIFO)
count = length - 1;
else
count = MAX_HWI2C_FIFO - 1;
poke32(I2C_BYTE_COUNT, count);
for (i = 0; i <= count; i++)
poke32(I2C_DATA0 + i, *buf++);
poke32(I2C_CTRL, peek32(I2C_CTRL) | I2C_CTRL_CTRL);
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
poke32(I2C_SLAVE_ADDRESS, addr | 0x01);
do {
poke32(I2C_RESET, 0);
if (length <= MAX_HWI2C_FIFO)
count = length - 1;
else
count = MAX_HWI2C_FIFO - 1;
poke32(I2C_BYTE_COUNT, count);
poke32(I2C_CTRL, peek32(I2C_CTRL) | I2C_CTRL_CTRL);
if (hw_i2c_wait_tx_done() != 0)
break;
for (i = 0; i <= count; i++)
*buf++ = peek32(I2C_DATA0 + i);
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
unsigned char value = 0xFF;
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
return -1;
}
