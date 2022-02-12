static void sh770x_sci_init_pins(struct uart_port *port, unsigned int cflag)
{
unsigned short data;
data = __raw_readw(SCPCR);
__raw_writew(data & 0x0fcf, SCPCR);
if (!(cflag & CRTSCTS)) {
data = __raw_readw(SCPCR);
__raw_writew((data & 0x0fcf) | 0x1000, SCPCR);
data = __raw_readb(SCPDR);
__raw_writeb(data & 0xbf, SCPDR);
}
}
