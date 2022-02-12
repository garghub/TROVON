static void __init hackkit_map_io(void)
{
sa1100_map_io();
iotable_init(hackkit_io_desc, ARRAY_SIZE(hackkit_io_desc));
sa1100_register_uart_fns(&hackkit_port_fns);
sa1100_register_uart(0, 1);
sa1100_register_uart(1, 2);
sa1100_register_uart(2, 3);
Ser1SDCR0 |= SDCR0_SUS;
}
static void hackkit_uart_pm(struct uart_port *port, u_int state, u_int oldstate)
{
}
static void hackkit_set_mctrl(struct uart_port *port, u_int mctrl)
{
#if 0
if (port->mapbase == _Ser1UTCR0) {
u_int set = 0, clear = 0;
if (mctrl & TIOCM_RTS)
set |= PT_CTRL2_RS1_RTS;
else
clear |= PT_CTRL2_RS1_RTS;
if (mctrl & TIOCM_DTR)
set |= PT_CTRL2_RS1_DTR;
else
clear |= PT_CTRL2_RS1_DTR;
PTCTRL2_clear(clear);
PTCTRL2_set(set);
}
#endif
}
static u_int hackkit_get_mctrl(struct uart_port *port)
{
u_int ret = 0;
#if 0
u_int irqsr = PT_IRQSR;
irqsr = PT_IRQSR;
#endif
ret = TIOCM_CD | TIOCM_CTS | TIOCM_DSR;
return ret;
}
static void __init hackkit_init(void)
{
sa11x0_register_mtd(&hackkit_flash_data, &hackkit_flash_resource, 1);
}
