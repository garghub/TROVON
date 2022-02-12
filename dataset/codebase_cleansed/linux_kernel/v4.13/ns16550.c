static int ns16550_open(void)
{
out_8(reg_base + (UART_FCR << reg_shift), 0x06);
return 0;
}
static void ns16550_putc(unsigned char c)
{
while ((in_8(reg_base + (UART_LSR << reg_shift)) & UART_LSR_THRE) == 0);
out_8(reg_base, c);
}
static unsigned char ns16550_getc(void)
{
while ((in_8(reg_base + (UART_LSR << reg_shift)) & UART_LSR_DR) == 0);
return in_8(reg_base);
}
static u8 ns16550_tstc(void)
{
return ((in_8(reg_base + (UART_LSR << reg_shift)) & UART_LSR_DR) != 0);
}
int ns16550_console_init(void *devp, struct serial_console_data *scdp)
{
int n;
u32 reg_offset;
if (dt_get_virtual_reg(devp, (void **)&reg_base, 1) < 1)
return -1;
n = getprop(devp, "reg-offset", &reg_offset, sizeof(reg_offset));
if (n == sizeof(reg_offset))
reg_base += reg_offset;
n = getprop(devp, "reg-shift", &reg_shift, sizeof(reg_shift));
if (n != sizeof(reg_shift))
reg_shift = 0;
scdp->open = ns16550_open;
scdp->putc = ns16550_putc;
scdp->getc = ns16550_getc;
scdp->tstc = ns16550_tstc;
scdp->close = NULL;
return 0;
}
