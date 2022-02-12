static void msp_serial_out(struct uart_port *p, int offset, int value)
{
struct msp_uart_data *d = p->private_data;
if (offset == UART_LCR)
d->last_lcr = value;
offset <<= p->regshift;
writeb(value, p->membase + offset);
}
static unsigned int msp_serial_in(struct uart_port *p, int offset)
{
offset <<= p->regshift;
return readb(p->membase + offset);
}
static int msp_serial_handle_irq(struct uart_port *p)
{
struct msp_uart_data *d = p->private_data;
unsigned int iir = readb(p->membase + (UART_IIR << p->regshift));
if (serial8250_handle_irq(p, iir)) {
return 1;
} else if ((iir & UART_IIR_BUSY) == UART_IIR_BUSY) {
(void)readb(p->membase + 0xc0);
writeb(d->last_lcr, p->membase + (UART_LCR << p->regshift));
return 1;
}
return 0;
}
void __init msp_serial_setup(void)
{
char *s;
char *endp;
struct uart_port up;
unsigned int uartclk;
memset(&up, 0, sizeof(up));
s = prom_getenv("uartfreqhz");
if(!(s && *s && (uartclk = simple_strtoul(s, &endp, 10)) && *endp == 0))
uartclk = MSP_BASE_BAUD;
ppfinit("UART clock set to %d\n", uartclk);
up.mapbase = MSP_UART0_BASE;
up.membase = ioremap_nocache(up.mapbase, MSP_UART_REG_LEN);
up.irq = MSP_INT_UART0;
up.uartclk = uartclk;
up.regshift = 2;
up.iotype = UPIO_MEM;
up.flags = UPF_BOOT_AUTOCONF | UPF_SKIP_TEST;
up.type = PORT_16550A;
up.line = 0;
up.serial_out = msp_serial_out;
up.serial_in = msp_serial_in;
up.handle_irq = msp_serial_handle_irq;
up.private_data = kzalloc(sizeof(struct msp_uart_data), GFP_KERNEL);
if (!up.private_data) {
pr_err("failed to allocate uart private data\n");
return;
}
if (early_serial_setup(&up)) {
kfree(up.private_data);
pr_err("Early serial init of port 0 failed\n");
}
switch (mips_machtype) {
case MACH_MSP4200_EVAL:
case MACH_MSP4200_GW:
case MACH_MSP4200_FPGA:
case MACH_MSP7120_EVAL:
case MACH_MSP7120_GW:
case MACH_MSP7120_FPGA:
*GPIO_CFG2_REG = 0x00002299;
break;
default:
return;
}
up.mapbase = MSP_UART1_BASE;
up.membase = ioremap_nocache(up.mapbase, MSP_UART_REG_LEN);
up.irq = MSP_INT_UART1;
up.line = 1;
up.private_data = (void*)UART1_STATUS_REG;
if (early_serial_setup(&up)) {
kfree(up.private_data);
pr_err("Early serial init of port 1 failed\n");
}
}
