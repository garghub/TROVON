static void wait_for_bits(struct nwpserial_port *up, int bits)
{
unsigned int status, tmout = 10000;
do {
status = dcr_read(up->dcr_host, UART_LSR);
if (--tmout == 0)
break;
udelay(1);
} while ((status & bits) != bits);
}
static void nwpserial_console_putchar(struct uart_port *port, int c)
{
struct nwpserial_port *up;
up = container_of(port, struct nwpserial_port, port);
wait_for_bits(up, UART_LSR_THRE);
dcr_write(up->dcr_host, UART_TX, c);
up->port.icount.tx++;
}
static void
nwpserial_console_write(struct console *co, const char *s, unsigned int count)
{
struct nwpserial_port *up = &nwpserial_ports[co->index];
unsigned long flags;
int locked = 1;
if (oops_in_progress)
locked = spin_trylock_irqsave(&up->port.lock, flags);
else
spin_lock_irqsave(&up->port.lock, flags);
up->ier = dcr_read(up->dcr_host, UART_IER);
dcr_write(up->dcr_host, UART_IER, up->ier & ~UART_IER_RDI);
uart_console_write(&up->port, s, count, nwpserial_console_putchar);
while ((dcr_read(up->dcr_host, UART_LSR) & UART_LSR_THRE) == 0)
cpu_relax();
dcr_write(up->dcr_host, UART_IER, up->ier);
if (locked)
spin_unlock_irqrestore(&up->port.lock, flags);
}
static int nwpserial_request_port(struct uart_port *port)
{
return 0;
}
static void nwpserial_release_port(struct uart_port *port)
{
}
static void nwpserial_config_port(struct uart_port *port, int flags)
{
port->type = PORT_NWPSERIAL;
}
static irqreturn_t nwpserial_interrupt(int irq, void *dev_id)
{
struct nwpserial_port *up = dev_id;
struct tty_port *port = &up->port.state->port;
irqreturn_t ret;
unsigned int iir;
unsigned char ch;
spin_lock(&up->port.lock);
iir = dcr_read(up->dcr_host, UART_IIR);
if (!iir) {
ret = IRQ_NONE;
goto out;
}
do {
up->port.icount.rx++;
ch = dcr_read(up->dcr_host, UART_RX);
if (up->port.ignore_status_mask != NWPSERIAL_STATUS_RXVALID)
tty_insert_flip_char(port, ch, TTY_NORMAL);
} while (dcr_read(up->dcr_host, UART_LSR) & UART_LSR_DR);
tty_flip_buffer_push(port);
ret = IRQ_HANDLED;
dcr_write(up->dcr_host, UART_IIR, 1);
out:
spin_unlock(&up->port.lock);
return ret;
}
static int nwpserial_startup(struct uart_port *port)
{
struct nwpserial_port *up;
int err;
up = container_of(port, struct nwpserial_port, port);
up->mcr = dcr_read(up->dcr_host, UART_MCR) & ~UART_MCR_AFE;
dcr_write(up->dcr_host, UART_MCR, up->mcr);
err = request_irq(up->port.irq, nwpserial_interrupt,
IRQF_SHARED, "nwpserial", up);
if (err)
return err;
up->ier = UART_IER_RDI;
dcr_write(up->dcr_host, UART_IER, up->ier);
up->port.ignore_status_mask &= ~NWPSERIAL_STATUS_RXVALID;
return 0;
}
static void nwpserial_shutdown(struct uart_port *port)
{
struct nwpserial_port *up;
up = container_of(port, struct nwpserial_port, port);
up->port.ignore_status_mask |= NWPSERIAL_STATUS_RXVALID;
up->ier = 0;
dcr_write(up->dcr_host, UART_IER, up->ier);
free_irq(up->port.irq, port);
}
static int nwpserial_verify_port(struct uart_port *port,
struct serial_struct *ser)
{
return -EINVAL;
}
static const char *nwpserial_type(struct uart_port *port)
{
return port->type == PORT_NWPSERIAL ? "nwpserial" : NULL;
}
static void nwpserial_set_termios(struct uart_port *port,
struct ktermios *termios, struct ktermios *old)
{
struct nwpserial_port *up;
up = container_of(port, struct nwpserial_port, port);
up->port.read_status_mask = NWPSERIAL_STATUS_RXVALID
| NWPSERIAL_STATUS_TXFULL;
up->port.ignore_status_mask = 0;
if ((termios->c_cflag & CREAD) == 0)
up->port.ignore_status_mask |= NWPSERIAL_STATUS_RXVALID;
if (old)
tty_termios_copy_hw(termios, old);
}
static void nwpserial_break_ctl(struct uart_port *port, int ctl)
{
}
static void nwpserial_enable_ms(struct uart_port *port)
{
}
static void nwpserial_stop_rx(struct uart_port *port)
{
struct nwpserial_port *up;
up = container_of(port, struct nwpserial_port, port);
up->port.ignore_status_mask = NWPSERIAL_STATUS_RXVALID;
}
static void nwpserial_putchar(struct nwpserial_port *up, unsigned char c)
{
wait_for_bits(up, UART_LSR_THRE);
dcr_write(up->dcr_host, UART_TX, c);
up->port.icount.tx++;
}
static void nwpserial_start_tx(struct uart_port *port)
{
struct nwpserial_port *up;
struct circ_buf *xmit;
up = container_of(port, struct nwpserial_port, port);
xmit = &up->port.state->xmit;
if (port->x_char) {
nwpserial_putchar(up, up->port.x_char);
port->x_char = 0;
}
while (!(uart_circ_empty(xmit) || uart_tx_stopped(&up->port))) {
nwpserial_putchar(up, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE-1);
}
}
static unsigned int nwpserial_get_mctrl(struct uart_port *port)
{
return 0;
}
static void nwpserial_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void nwpserial_stop_tx(struct uart_port *port)
{
}
static unsigned int nwpserial_tx_empty(struct uart_port *port)
{
struct nwpserial_port *up;
unsigned long flags;
int ret;
up = container_of(port, struct nwpserial_port, port);
spin_lock_irqsave(&up->port.lock, flags);
ret = dcr_read(up->dcr_host, UART_LSR);
spin_unlock_irqrestore(&up->port.lock, flags);
return ret & UART_LSR_TEMT ? TIOCSER_TEMT : 0;
}
int nwpserial_register_port(struct uart_port *port)
{
struct nwpserial_port *up = NULL;
int ret = -1;
int i;
static int first = 1;
int dcr_len;
int dcr_base;
struct device_node *dn;
mutex_lock(&nwpserial_mutex);
dn = port->dev->of_node;
if (dn == NULL)
goto out;
dcr_base = dcr_resource_start(dn, 0);
for (i = 0; i < NWPSERIAL_NR; i++)
if (nwpserial_ports[i].port.iobase == dcr_base) {
up = &nwpserial_ports[i];
break;
}
if (up == NULL)
for (i = 0; i < NWPSERIAL_NR; i++)
if (nwpserial_ports[i].port.type == PORT_UNKNOWN &&
nwpserial_ports[i].port.iobase == 0) {
up = &nwpserial_ports[i];
break;
}
if (up == NULL) {
ret = -EBUSY;
goto out;
}
if (first)
uart_register_driver(&nwpserial_reg);
first = 0;
up->port.membase = port->membase;
up->port.irq = port->irq;
up->port.uartclk = port->uartclk;
up->port.fifosize = port->fifosize;
up->port.regshift = port->regshift;
up->port.iotype = port->iotype;
up->port.flags = port->flags;
up->port.mapbase = port->mapbase;
up->port.private_data = port->private_data;
if (port->dev)
up->port.dev = port->dev;
if (up->port.iobase != dcr_base) {
up->port.ops = &nwpserial_pops;
up->port.fifosize = 16;
spin_lock_init(&up->port.lock);
up->port.iobase = dcr_base;
dcr_len = dcr_resource_len(dn, 0);
up->dcr_host = dcr_map(dn, dcr_base, dcr_len);
if (!DCR_MAP_OK(up->dcr_host)) {
printk(KERN_ERR "Cannot map DCR resources for NWPSERIAL");
goto out;
}
}
ret = uart_add_one_port(&nwpserial_reg, &up->port);
if (ret == 0)
ret = up->port.line;
out:
mutex_unlock(&nwpserial_mutex);
return ret;
}
void nwpserial_unregister_port(int line)
{
struct nwpserial_port *up = &nwpserial_ports[line];
mutex_lock(&nwpserial_mutex);
uart_remove_one_port(&nwpserial_reg, &up->port);
up->port.type = PORT_UNKNOWN;
mutex_unlock(&nwpserial_mutex);
}
static int __init nwpserial_console_init(void)
{
struct nwpserial_port *up = NULL;
struct device_node *dn;
const char *name;
int dcr_base;
int dcr_len;
int i;
for (i = 0; i < NWPSERIAL_NR; i++)
if (nwpserial_ports[i].port.type == PORT_UNKNOWN) {
up = &nwpserial_ports[i];
break;
}
if (up == NULL)
return -1;
name = of_get_property(of_chosen, "linux,stdout-path", NULL);
if (name == NULL)
return -1;
dn = of_find_node_by_path(name);
if (!dn)
return -1;
spin_lock_init(&up->port.lock);
up->port.ops = &nwpserial_pops;
up->port.type = PORT_NWPSERIAL;
up->port.fifosize = 16;
dcr_base = dcr_resource_start(dn, 0);
dcr_len = dcr_resource_len(dn, 0);
up->port.iobase = dcr_base;
up->dcr_host = dcr_map(dn, dcr_base, dcr_len);
if (!DCR_MAP_OK(up->dcr_host)) {
printk("Cannot map DCR resources for SERIAL");
return -1;
}
register_console(&nwpserial_console);
return 0;
}
