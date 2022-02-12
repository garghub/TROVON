static void h3xxx_set_vpp(int vpp)
{
gpio_set_value(H3XXX_EGPIO_VPP_ON, vpp);
}
static int h3xxx_flash_init(void)
{
int err = gpio_request(H3XXX_EGPIO_VPP_ON, "Flash Vpp");
if (err) {
pr_err("%s: can't request H3XXX_EGPIO_VPP_ON\n", __func__);
return err;
}
err = gpio_direction_output(H3XXX_EGPIO_VPP_ON, 0);
if (err)
gpio_free(H3XXX_EGPIO_VPP_ON);
return err;
}
static void h3xxx_flash_exit(void)
{
gpio_free(H3XXX_EGPIO_VPP_ON);
}
static bool h3xxx_uart_request_gpios(void)
{
static bool h3xxx_uart_gpio_ok;
int rc;
if (h3xxx_uart_gpio_ok)
return true;
rc = gpio_request_array(h3xxx_uart_gpio, ARRAY_SIZE(h3xxx_uart_gpio));
if (rc)
pr_err("h3xxx_uart_request_gpios: error %d\n", rc);
else
h3xxx_uart_gpio_ok = true;
return h3xxx_uart_gpio_ok;
}
static void h3xxx_uart_set_mctrl(struct uart_port *port, u_int mctrl)
{
if (port->mapbase == _Ser3UTCR0) {
if (!h3xxx_uart_request_gpios())
return;
gpio_set_value(H3XXX_GPIO_COM_RTS, !(mctrl & TIOCM_RTS));
}
}
static u_int h3xxx_uart_get_mctrl(struct uart_port *port)
{
u_int ret = TIOCM_CD | TIOCM_CTS | TIOCM_DSR;
if (port->mapbase == _Ser3UTCR0) {
if (!h3xxx_uart_request_gpios())
return ret;
if (gpio_get_value(H3XXX_GPIO_COM_DCD))
ret &= ~TIOCM_CD;
if (gpio_get_value(H3XXX_GPIO_COM_CTS))
ret &= ~TIOCM_CTS;
}
return ret;
}
static void h3xxx_uart_pm(struct uart_port *port, u_int state, u_int oldstate)
{
if (port->mapbase == _Ser3UTCR0) {
if (!gpio_request(H3XXX_EGPIO_RS232_ON, "RS232 transceiver")) {
gpio_direction_output(H3XXX_EGPIO_RS232_ON, !state);
gpio_free(H3XXX_EGPIO_RS232_ON);
} else {
pr_err("%s: can't request H3XXX_EGPIO_RS232_ON\n",
__func__);
}
}
}
static int h3xxx_uart_set_wake(struct uart_port *port, u_int enable)
{
int err = -EINVAL;
if (port->mapbase == _Ser3UTCR0) {
if (enable)
PWER |= PWER_GPIO23 | PWER_GPIO25;
else
PWER &= ~(PWER_GPIO23 | PWER_GPIO25);
err = 0;
}
return err;
}
void __init h3xxx_mach_init(void)
{
sa1100_register_uart_fns(&h3xxx_port_fns);
sa11x0_register_mtd(&h3xxx_flash_data, &h3xxx_flash_resource, 1);
platform_add_devices(h3xxx_devices, ARRAY_SIZE(h3xxx_devices));
}
void __init h3xxx_map_io(void)
{
sa1100_map_io();
iotable_init(h3600_io_desc, ARRAY_SIZE(h3600_io_desc));
sa1100_register_uart(0, 3);
PPDR |= PPC_TXD4 | PPC_SCLK | PPC_SFRM;
PPSR &= ~(PPC_TXD4 | PPC_SCLK | PPC_SFRM);
PGSR = 0;
PCFR = PCFR_OPDE;
PSDR = 0;
GPCR = 0x0fffffff;
GPDR = 0;
}
