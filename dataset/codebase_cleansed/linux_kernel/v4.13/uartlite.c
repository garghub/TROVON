static int uartlite_open(void)
{
out_be32(reg_base + ULITE_CONTROL, ULITE_CONTROL_RST_RX);
return 0;
}
static void uartlite_putc(unsigned char c)
{
u32 reg = ULITE_STATUS_TXFULL;
while (reg & ULITE_STATUS_TXFULL)
reg = in_be32(reg_base + ULITE_STATUS);
out_be32(reg_base + ULITE_TX, c);
}
static unsigned char uartlite_getc(void)
{
u32 reg = 0;
while (!(reg & ULITE_STATUS_RXVALID))
reg = in_be32(reg_base + ULITE_STATUS);
return in_be32(reg_base + ULITE_RX);
}
static u8 uartlite_tstc(void)
{
u32 reg = in_be32(reg_base + ULITE_STATUS);
return reg & ULITE_STATUS_RXVALID;
}
int uartlite_console_init(void *devp, struct serial_console_data *scdp)
{
int n;
unsigned long reg_phys;
n = getprop(devp, "virtual-reg", &reg_base, sizeof(reg_base));
if (n != sizeof(reg_base)) {
if (!dt_xlate_reg(devp, 0, &reg_phys, NULL))
return -1;
reg_base = (void *)reg_phys;
}
scdp->open = uartlite_open;
scdp->putc = uartlite_putc;
scdp->getc = uartlite_getc;
scdp->tstc = uartlite_tstc;
scdp->close = NULL;
return 0;
}
