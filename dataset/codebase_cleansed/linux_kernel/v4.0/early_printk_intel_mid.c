void hsu_early_console_init(const char *s)
{
unsigned long paddr, port = 0;
u8 lcr;
if (*s && !kstrtoul(s, 10, &port))
port = clamp_val(port, 0, 2);
paddr = HSU_PORT_BASE + port * 0x80;
phsu = (void __iomem *)set_fixmap_offset_nocache(FIX_EARLYCON_MEM_BASE, paddr);
writeb(0x0, phsu + UART_FCR);
lcr = readb(phsu + UART_LCR);
writeb((0x80 | lcr), phsu + UART_LCR);
writeb(0x18, phsu + UART_DLL);
writeb(lcr, phsu + UART_LCR);
writel(0x3600, phsu + UART_MUL*4);
writeb(0x8, phsu + UART_MCR);
writeb(0x7, phsu + UART_FCR);
writeb(0x3, phsu + UART_LCR);
readb(phsu + UART_LSR);
readb(phsu + UART_RX);
readb(phsu + UART_IIR);
readb(phsu + UART_MSR);
writeb(0x7, phsu + UART_FCR);
}
static void early_hsu_putc(char ch)
{
unsigned int timeout = 10000;
u8 status;
while (--timeout) {
status = readb(phsu + UART_LSR);
if (status & BOTH_EMPTY)
break;
udelay(1);
}
if (timeout)
writeb(ch, phsu + UART_TX);
}
static void early_hsu_write(struct console *con, const char *str, unsigned n)
{
int i;
for (i = 0; i < n && *str; i++) {
if (*str == '\n')
early_hsu_putc('\r');
early_hsu_putc(*str);
str++;
}
}
