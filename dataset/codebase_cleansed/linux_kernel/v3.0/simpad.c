long get_cs3_shadow(void)
{
return cs3_shadow;
}
void set_cs3(long value)
{
*(CS3BUSTYPE *)(CS3_BASE) = cs3_shadow = value;
}
void set_cs3_bit(int value)
{
cs3_shadow |= value;
*(CS3BUSTYPE *)(CS3_BASE) = cs3_shadow;
}
void clear_cs3_bit(int value)
{
cs3_shadow &= ~value;
*(CS3BUSTYPE *)(CS3_BASE) = cs3_shadow;
}
static void simpad_uart_pm(struct uart_port *port, u_int state, u_int oldstate)
{
if (port->mapbase == (u_int)&Ser1UTCR0) {
if (state)
{
clear_cs3_bit(RS232_ON);
clear_cs3_bit(DECT_POWER_ON);
}else
{
set_cs3_bit(RS232_ON);
set_cs3_bit(DECT_POWER_ON);
}
}
}
static void __init simpad_map_io(void)
{
sa1100_map_io();
iotable_init(simpad_io_desc, ARRAY_SIZE(simpad_io_desc));
set_cs3_bit (EN1 | EN0 | LED2_ON | DISPLAY_ON | RS232_ON |
ENABLE_5V | RESET_SIMCARD | DECT_POWER_ON);
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
set_cs3(0x800);
PCFR = (PCFR_OPDE | PCFR_FP | PCFR_FS);
PWER = GFER = GRER = 1;
PSPR = 0;
PGSR = 0;
PMCR = PMCR_SF;
while(1);
local_irq_enable();
}
static int __init simpad_init(void)
{
int ret;
pm_power_off = simpad_power_off;
sa11x0_register_mtd(&simpad_flash_data, simpad_flash_resources,
ARRAY_SIZE(simpad_flash_resources));
sa11x0_register_mcp(&simpad_mcp_data);
ret = platform_add_devices(devices, ARRAY_SIZE(devices));
if(ret)
printk(KERN_WARNING "simpad: Unable to register mq200 framebuffer device");
return 0;
}
