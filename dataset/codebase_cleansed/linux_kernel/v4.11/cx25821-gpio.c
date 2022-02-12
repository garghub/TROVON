void cx25821_set_gpiopin_direction(struct cx25821_dev *dev,
int pin_number, int pin_logic_value)
{
int bit = pin_number;
u32 gpio_oe_reg = GPIO_LO_OE;
u32 gpio_register = 0;
u32 value = 0;
if (pin_number >= 47)
return;
if (pin_number > 31) {
bit = pin_number - 31;
gpio_oe_reg = GPIO_HI_OE;
}
gpio_register = cx_read(gpio_oe_reg);
if (pin_logic_value == 1)
value = gpio_register | Set_GPIO_Bit(bit);
else
value = gpio_register & Clear_GPIO_Bit(bit);
cx_write(gpio_oe_reg, value);
}
static void cx25821_set_gpiopin_logicvalue(struct cx25821_dev *dev,
int pin_number, int pin_logic_value)
{
int bit = pin_number;
u32 gpio_reg = GPIO_LO;
u32 value = 0;
if (pin_number >= 47)
return;
cx25821_set_gpiopin_direction(dev, pin_number, 0);
if (pin_number > 31) {
bit = pin_number - 31;
gpio_reg = GPIO_HI;
}
value = cx_read(gpio_reg);
if (pin_logic_value == 0)
value &= Clear_GPIO_Bit(bit);
else
value |= Set_GPIO_Bit(bit);
cx_write(gpio_reg, value);
}
void cx25821_gpio_init(struct cx25821_dev *dev)
{
if (dev == NULL)
return;
switch (dev->board) {
case CX25821_BOARD_CONEXANT_ATHENA10:
default:
cx25821_set_gpiopin_logicvalue(dev, 5, 1);
mdelay(20);
break;
}
}
