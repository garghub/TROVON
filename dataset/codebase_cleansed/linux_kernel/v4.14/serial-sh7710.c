static void sh7710_sci_init_pins(struct uart_port *port, unsigned int cflag)
{
if (port->mapbase == 0xA4400000) {
__raw_writew(__raw_readw(PACR) & 0xffc0, PACR);
__raw_writew(__raw_readw(PBCR) & 0x0fff, PBCR);
} else if (port->mapbase == 0xA4410000)
__raw_writew(__raw_readw(PBCR) & 0xf003, PBCR);
}
