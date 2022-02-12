long simpad_get_cs3_ro(void)
{
return readl(CS3_BASE);
}
long simpad_get_cs3_shadow(void)
{
return cs3_shadow;
}
static void __simpad_write_cs3(void)
{
writel(cs3_shadow, CS3_BASE);
}
void simpad_set_cs3_bit(int value)
{
unsigned long flags;
spin_lock_irqsave(&cs3_lock, flags);
cs3_shadow |= value;
__simpad_write_cs3();
spin_unlock_irqrestore(&cs3_lock, flags);
}
void simpad_clear_cs3_bit(int value)
{
unsigned long flags;
spin_lock_irqsave(&cs3_lock, flags);
cs3_shadow &= ~value;
__simpad_write_cs3();
spin_unlock_irqrestore(&cs3_lock, flags);
}
static void cs3_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
if (offset > 15)
return;
if (value)
simpad_set_cs3_bit(1 << offset);
else
simpad_clear_cs3_bit(1 << offset);
}
static int cs3_gpio_get(struct gpio_chip *chip, unsigned offset)
{
if (offset > 15)
return !!(simpad_get_cs3_ro() & (1 << (offset - 16)));
return !!(simpad_get_cs3_shadow() & (1 << offset));
}
static int cs3_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
if (offset > 15)
return 0;
return -EINVAL;
}
static int cs3_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
if (offset > 15)
return -EINVAL;
cs3_gpio_set(chip, offset, value);
return 0;
}
static void simpad_uart_pm(struct uart_port *port, u_int state, u_int oldstate)
{
if (port->mapbase == (u_int)&Ser1UTCR0) {
if (state)
{
simpad_clear_cs3_bit(RS232_ON);
simpad_clear_cs3_bit(DECT_POWER_ON);
}else
{
simpad_set_cs3_bit(RS232_ON);
simpad_set_cs3_bit(DECT_POWER_ON);
}
}
}
static void __init simpad_map_io(void)
{
sa1100_map_io();
iotable_init(simpad_io_desc, ARRAY_SIZE(simpad_io_desc));
cs3_shadow = (EN1 | EN0 | LED2_ON | DISPLAY_ON |
RS232_ON | ENABLE_5V | RESET_SIMCARD | DECT_POWER_ON);
__simpad_write_cs3();
sa1100_register_uart_fns(&simpad_port_fns);
sa1100_register_uart(0, 3);
sa1100_register_uart(1, 1);
GAFR |= GPIO_UART_TXD | GPIO_UART_RXD;
GPDR |= GPIO_UART_TXD | GPIO_LDD13 | GPIO_LDD15;
GPDR &= ~GPIO_UART_RXD;
PPAR |= PPAR_UPR;
PWER = PWER_GPIO0| PWER_RTC;
PGSR = 0x818;
PCFR = 0;
PSDR = 0;
}
static void simpad_power_off(void)
{
local_irq_disable();
cs3_shadow = SD_MEDIAQ;
__simpad_write_cs3();
PCFR = (PCFR_OPDE | PCFR_FP | PCFR_FS);
PWER = GFER = GRER = PWER_GPIO0;
PSPR = 0;
PGSR = 0;
PMCR = PMCR_SF;
while(1);
local_irq_enable();
}
static int __init simpad_init(void)
{
int ret;
spin_lock_init(&cs3_lock);
cs3_gpio.label = "simpad_cs3";
cs3_gpio.base = SIMPAD_CS3_GPIO_BASE;
cs3_gpio.ngpio = 24;
cs3_gpio.set = cs3_gpio_set;
cs3_gpio.get = cs3_gpio_get;
cs3_gpio.direction_input = cs3_gpio_direction_input;
cs3_gpio.direction_output = cs3_gpio_direction_output;
ret = gpiochip_add(&cs3_gpio);
if (ret)
printk(KERN_WARNING "simpad: Unable to register cs3 GPIO device");
pm_power_off = simpad_power_off;
sa11x0_ppc_configure_mcp();
sa11x0_register_mtd(&simpad_flash_data, simpad_flash_resources,
ARRAY_SIZE(simpad_flash_resources));
sa11x0_register_mcp(&simpad_mcp_data);
ret = platform_add_devices(devices, ARRAY_SIZE(devices));
if(ret)
printk(KERN_WARNING "simpad: Unable to register mq200 framebuffer device");
return 0;
}
