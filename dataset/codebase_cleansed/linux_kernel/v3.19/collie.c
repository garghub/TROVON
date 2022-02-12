static int collie_ir_startup(struct device *dev)
{
int rc = gpio_request(COLLIE_GPIO_IR_ON, "IrDA");
if (rc)
return rc;
rc = gpio_direction_output(COLLIE_GPIO_IR_ON, 1);
if (!rc)
return 0;
gpio_free(COLLIE_GPIO_IR_ON);
return rc;
}
static void collie_ir_shutdown(struct device *dev)
{
gpio_free(COLLIE_GPIO_IR_ON);
}
static int collie_ir_set_power(struct device *dev, unsigned int state)
{
gpio_set_value(COLLIE_GPIO_IR_ON, !state);
return 0;
}
static void collie_uart_set_mctrl(struct uart_port *port, u_int mctrl)
{
if (mctrl & TIOCM_RTS)
locomo_gpio_write(&collie_locomo_device.dev, LOCOMO_GPIO_RTS, 0);
else
locomo_gpio_write(&collie_locomo_device.dev, LOCOMO_GPIO_RTS, 1);
if (mctrl & TIOCM_DTR)
locomo_gpio_write(&collie_locomo_device.dev, LOCOMO_GPIO_DTR, 0);
else
locomo_gpio_write(&collie_locomo_device.dev, LOCOMO_GPIO_DTR, 1);
}
static u_int collie_uart_get_mctrl(struct uart_port *port)
{
int ret = TIOCM_CD;
unsigned int r;
r = locomo_gpio_read_output(&collie_locomo_device.dev, LOCOMO_GPIO_CTS & LOCOMO_GPIO_DSR);
if (r == -ENODEV)
return ret;
if (r & LOCOMO_GPIO_CTS)
ret |= TIOCM_CTS;
if (r & LOCOMO_GPIO_DSR)
ret |= TIOCM_DSR;
return ret;
}
static int collie_uart_probe(struct locomo_dev *dev)
{
return 0;
}
static int collie_uart_remove(struct locomo_dev *dev)
{
return 0;
}
static int __init collie_uart_init(void)
{
return locomo_driver_register(&collie_uart_driver);
}
static int collie_flash_init(void)
{
int rc = gpio_request(COLLIE_GPIO_VPEN, "flash Vpp enable");
if (rc)
return rc;
rc = gpio_direction_output(COLLIE_GPIO_VPEN, 1);
if (rc)
gpio_free(COLLIE_GPIO_VPEN);
return rc;
}
static void collie_set_vpp(int vpp)
{
gpio_set_value(COLLIE_GPIO_VPEN, vpp);
}
static void collie_flash_exit(void)
{
gpio_free(COLLIE_GPIO_VPEN);
}
static void __init collie_init(void)
{
int ret = 0;
GAFR = GPIO_SSP_TXD | GPIO_SSP_SCLK | GPIO_SSP_SFRM | GPIO_SSP_CLK |
GPIO_MCP_CLK | GPIO_32_768kHz;
GPDR = GPIO_LDD8 | GPIO_LDD9 | GPIO_LDD10 | GPIO_LDD11 | GPIO_LDD12 |
GPIO_LDD13 | GPIO_LDD14 | GPIO_LDD15 | GPIO_SSP_TXD |
GPIO_SSP_SCLK | GPIO_SSP_SFRM | GPIO_SDLC_SCLK |
_COLLIE_GPIO_UCB1x00_RESET | _COLLIE_GPIO_nMIC_ON |
_COLLIE_GPIO_nREMOCON_ON | GPIO_32_768kHz;
PPDR = PPC_LDD0 | PPC_LDD1 | PPC_LDD2 | PPC_LDD3 | PPC_LDD4 | PPC_LDD5 |
PPC_LDD6 | PPC_LDD7 | PPC_L_PCLK | PPC_L_LCLK | PPC_L_FCLK | PPC_L_BIAS |
PPC_TXD1 | PPC_TXD2 | PPC_TXD3 | PPC_TXD4 | PPC_SCLK | PPC_SFRM;
PWER = _COLLIE_GPIO_AC_IN | _COLLIE_GPIO_CO | _COLLIE_GPIO_ON_KEY |
_COLLIE_GPIO_WAKEUP | _COLLIE_GPIO_nREMOCON_INT | PWER_RTC;
PGSR = _COLLIE_GPIO_nREMOCON_ON;
PSDR = PPC_RXD1 | PPC_RXD2 | PPC_RXD3 | PPC_RXD4;
PCFR = PCFR_OPDE;
GPSR |= _COLLIE_GPIO_UCB1x00_RESET;
sa11x0_ppc_configure_mcp();
platform_scoop_config = &collie_pcmcia_config;
ret = platform_add_devices(devices, ARRAY_SIZE(devices));
if (ret) {
printk(KERN_WARNING "collie: Unable to register LoCoMo device\n");
}
sa11x0_register_lcd(&collie_lcd_info);
sa11x0_register_mtd(&collie_flash_data, collie_flash_resources,
ARRAY_SIZE(collie_flash_resources));
sa11x0_register_mcp(&collie_mcp_data);
sa11x0_register_irda(&collie_ir_data);
sharpsl_save_param();
}
static void __init collie_map_io(void)
{
sa1100_map_io();
iotable_init(collie_io_desc, ARRAY_SIZE(collie_io_desc));
#ifdef CONFIG_SHARP_LOCOMO
sa1100_register_uart_fns(&collie_port_fns);
#endif
sa1100_register_uart(0, 3);
sa1100_register_uart(1, 1);
}
