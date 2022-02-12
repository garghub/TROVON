static inline unsigned int sio_in(struct uart_txx9_port *up, int offset)
{
switch (up->port.iotype) {
default:
return __raw_readl(up->port.membase + offset);
case UPIO_PORT:
return inl(up->port.iobase + offset);
}
}
static inline void
sio_out(struct uart_txx9_port *up, int offset, int value)
{
switch (up->port.iotype) {
default:
__raw_writel(value, up->port.membase + offset);
break;
case UPIO_PORT:
outl(value, up->port.iobase + offset);
break;
}
}
static inline void
sio_mask(struct uart_txx9_port *up, int offset, unsigned int value)
{
sio_out(up, offset, sio_in(up, offset) & ~value);
}
static inline void
sio_set(struct uart_txx9_port *up, int offset, unsigned int value)
{
sio_out(up, offset, sio_in(up, offset) | value);
}
static inline void
sio_quot_set(struct uart_txx9_port *up, int quot)
{
quot >>= 1;
if (quot < 256)
sio_out(up, TXX9_SIBGR, quot | TXX9_SIBGR_BCLK_T0);
else if (quot < (256 << 2))
sio_out(up, TXX9_SIBGR, (quot >> 2) | TXX9_SIBGR_BCLK_T2);
else if (quot < (256 << 4))
sio_out(up, TXX9_SIBGR, (quot >> 4) | TXX9_SIBGR_BCLK_T4);
else if (quot < (256 << 6))
sio_out(up, TXX9_SIBGR, (quot >> 6) | TXX9_SIBGR_BCLK_T6);
else
sio_out(up, TXX9_SIBGR, 0xff | TXX9_SIBGR_BCLK_T6);
}
static struct uart_txx9_port *to_uart_txx9_port(struct uart_port *port)
{
return container_of(port, struct uart_txx9_port, port);
}
static void serial_txx9_stop_tx(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
sio_mask(up, TXX9_SIDICR, TXX9_SIDICR_TIE);
}
static void serial_txx9_start_tx(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
sio_set(up, TXX9_SIDICR, TXX9_SIDICR_TIE);
}
static void serial_txx9_stop_rx(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
up->port.read_status_mask &= ~TXX9_SIDISR_RDIS;
}
static void serial_txx9_enable_ms(struct uart_port *port)
{
}
static void serial_txx9_initialize(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
unsigned int tmout = 10000;
sio_out(up, TXX9_SIFCR, TXX9_SIFCR_SWRST);
mmiowb();
udelay(1);
while ((sio_in(up, TXX9_SIFCR) & TXX9_SIFCR_SWRST) && --tmout)
udelay(1);
sio_set(up, TXX9_SIFCR,
TXX9_SIFCR_TDIL_MAX | TXX9_SIFCR_RDIL_1);
sio_out(up, TXX9_SILCR,
TXX9_SILCR_UMODE_8BIT | TXX9_SILCR_USBL_1BIT |
((up->port.flags & UPF_TXX9_USE_SCLK) ?
TXX9_SILCR_SCS_SCLK_BG : TXX9_SILCR_SCS_IMCLK_BG));
sio_quot_set(up, uart_get_divisor(port, 9600));
sio_out(up, TXX9_SIFLCR, TXX9_SIFLCR_RTSTL_MAX );
sio_out(up, TXX9_SIDICR, 0);
}
static inline void
receive_chars(struct uart_txx9_port *up, unsigned int *status)
{
struct tty_struct *tty = up->port.state->port.tty;
unsigned char ch;
unsigned int disr = *status;
int max_count = 256;
char flag;
unsigned int next_ignore_status_mask;
do {
ch = sio_in(up, TXX9_SIRFIFO);
flag = TTY_NORMAL;
up->port.icount.rx++;
next_ignore_status_mask =
up->port.ignore_status_mask & ~TXX9_SIDISR_RFDN_MASK;
if (unlikely(disr & (TXX9_SIDISR_UBRK | TXX9_SIDISR_UPER |
TXX9_SIDISR_UFER | TXX9_SIDISR_UOER))) {
if (disr & TXX9_SIDISR_UBRK) {
disr &= ~(TXX9_SIDISR_UFER | TXX9_SIDISR_UPER);
up->port.icount.brk++;
if (uart_handle_break(&up->port))
goto ignore_char;
} else if (disr & TXX9_SIDISR_UPER)
up->port.icount.parity++;
else if (disr & TXX9_SIDISR_UFER)
up->port.icount.frame++;
if (disr & TXX9_SIDISR_UOER) {
up->port.icount.overrun++;
next_ignore_status_mask |=
TXX9_SIDISR_RFDN_MASK;
}
disr &= up->port.read_status_mask;
if (disr & TXX9_SIDISR_UBRK) {
flag = TTY_BREAK;
} else if (disr & TXX9_SIDISR_UPER)
flag = TTY_PARITY;
else if (disr & TXX9_SIDISR_UFER)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(&up->port, ch))
goto ignore_char;
uart_insert_char(&up->port, disr, TXX9_SIDISR_UOER, ch, flag);
ignore_char:
up->port.ignore_status_mask = next_ignore_status_mask;
disr = sio_in(up, TXX9_SIDISR);
} while (!(disr & TXX9_SIDISR_UVALID) && (max_count-- > 0));
spin_unlock(&up->port.lock);
tty_flip_buffer_push(tty);
spin_lock(&up->port.lock);
*status = disr;
}
static inline void transmit_chars(struct uart_txx9_port *up)
{
struct circ_buf *xmit = &up->port.state->xmit;
int count;
if (up->port.x_char) {
sio_out(up, TXX9_SITFIFO, up->port.x_char);
up->port.icount.tx++;
up->port.x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&up->port)) {
serial_txx9_stop_tx(&up->port);
return;
}
count = TXX9_SIO_TX_FIFO;
do {
sio_out(up, TXX9_SITFIFO, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
up->port.icount.tx++;
if (uart_circ_empty(xmit))
break;
} while (--count > 0);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
if (uart_circ_empty(xmit))
serial_txx9_stop_tx(&up->port);
}
static irqreturn_t serial_txx9_interrupt(int irq, void *dev_id)
{
int pass_counter = 0;
struct uart_txx9_port *up = dev_id;
unsigned int status;
while (1) {
spin_lock(&up->port.lock);
status = sio_in(up, TXX9_SIDISR);
if (!(sio_in(up, TXX9_SIDICR) & TXX9_SIDICR_TIE))
status &= ~TXX9_SIDISR_TDIS;
if (!(status & (TXX9_SIDISR_TDIS | TXX9_SIDISR_RDIS |
TXX9_SIDISR_TOUT))) {
spin_unlock(&up->port.lock);
break;
}
if (status & TXX9_SIDISR_RDIS)
receive_chars(up, &status);
if (status & TXX9_SIDISR_TDIS)
transmit_chars(up);
sio_mask(up, TXX9_SIDISR,
TXX9_SIDISR_TDIS | TXX9_SIDISR_RDIS |
TXX9_SIDISR_TOUT);
spin_unlock(&up->port.lock);
if (pass_counter++ > PASS_LIMIT)
break;
}
return pass_counter ? IRQ_HANDLED : IRQ_NONE;
}
static unsigned int serial_txx9_tx_empty(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
unsigned long flags;
unsigned int ret;
spin_lock_irqsave(&up->port.lock, flags);
ret = (sio_in(up, TXX9_SICISR) & TXX9_SICISR_TXALS) ? TIOCSER_TEMT : 0;
spin_unlock_irqrestore(&up->port.lock, flags);
return ret;
}
static unsigned int serial_txx9_get_mctrl(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
unsigned int ret;
ret = TIOCM_CAR | TIOCM_DSR;
ret |= (sio_in(up, TXX9_SIFLCR) & TXX9_SIFLCR_RTSSC) ? 0 : TIOCM_RTS;
ret |= (sio_in(up, TXX9_SICISR) & TXX9_SICISR_CTSS) ? 0 : TIOCM_CTS;
return ret;
}
static void serial_txx9_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
if (mctrl & TIOCM_RTS)
sio_mask(up, TXX9_SIFLCR, TXX9_SIFLCR_RTSSC);
else
sio_set(up, TXX9_SIFLCR, TXX9_SIFLCR_RTSSC);
}
static void serial_txx9_break_ctl(struct uart_port *port, int break_state)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
unsigned long flags;
spin_lock_irqsave(&up->port.lock, flags);
if (break_state == -1)
sio_set(up, TXX9_SIFLCR, TXX9_SIFLCR_TBRK);
else
sio_mask(up, TXX9_SIFLCR, TXX9_SIFLCR_TBRK);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static void wait_for_xmitr(struct uart_txx9_port *up)
{
unsigned int tmout = 10000;
while (--tmout &&
!(sio_in(up, TXX9_SICISR) & TXX9_SICISR_TXALS))
udelay(1);
if (up->port.flags & UPF_CONS_FLOW) {
tmout = 1000000;
while (--tmout &&
(sio_in(up, TXX9_SICISR) & TXX9_SICISR_CTSS))
udelay(1);
}
}
static int serial_txx9_get_poll_char(struct uart_port *port)
{
unsigned int ier;
unsigned char c;
struct uart_txx9_port *up = to_uart_txx9_port(port);
ier = sio_in(up, TXX9_SIDICR);
sio_out(up, TXX9_SIDICR, 0);
while (sio_in(up, TXX9_SIDISR) & TXX9_SIDISR_UVALID)
;
c = sio_in(up, TXX9_SIRFIFO);
sio_mask(up, TXX9_SIDISR, TXX9_SIDISR_RDIS);
sio_out(up, TXX9_SIDICR, ier);
return c;
}
static void serial_txx9_put_poll_char(struct uart_port *port, unsigned char c)
{
unsigned int ier;
struct uart_txx9_port *up = to_uart_txx9_port(port);
ier = sio_in(up, TXX9_SIDICR);
sio_out(up, TXX9_SIDICR, 0);
wait_for_xmitr(up);
sio_out(up, TXX9_SITFIFO, c);
if (c == 10) {
wait_for_xmitr(up);
sio_out(up, TXX9_SITFIFO, 13);
}
wait_for_xmitr(up);
sio_out(up, TXX9_SIDICR, ier);
}
static int serial_txx9_startup(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
unsigned long flags;
int retval;
sio_set(up, TXX9_SIFCR,
TXX9_SIFCR_TFRST | TXX9_SIFCR_RFRST | TXX9_SIFCR_FRSTE);
sio_mask(up, TXX9_SIFCR,
TXX9_SIFCR_TFRST | TXX9_SIFCR_RFRST | TXX9_SIFCR_FRSTE);
sio_out(up, TXX9_SIDICR, 0);
sio_out(up, TXX9_SIDISR, 0);
retval = request_irq(up->port.irq, serial_txx9_interrupt,
IRQF_SHARED, "serial_txx9", up);
if (retval)
return retval;
spin_lock_irqsave(&up->port.lock, flags);
serial_txx9_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
sio_mask(up, TXX9_SIFLCR, TXX9_SIFLCR_RSDE | TXX9_SIFLCR_TSDE);
sio_set(up, TXX9_SIDICR, TXX9_SIDICR_RIE);
return 0;
}
static void serial_txx9_shutdown(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
unsigned long flags;
sio_out(up, TXX9_SIDICR, 0);
spin_lock_irqsave(&up->port.lock, flags);
serial_txx9_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
sio_mask(up, TXX9_SIFLCR, TXX9_SIFLCR_TBRK);
#ifdef CONFIG_SERIAL_TXX9_CONSOLE
if (up->port.cons && up->port.line == up->port.cons->index) {
free_irq(up->port.irq, up);
return;
}
#endif
sio_set(up, TXX9_SIFCR,
TXX9_SIFCR_TFRST | TXX9_SIFCR_RFRST | TXX9_SIFCR_FRSTE);
sio_mask(up, TXX9_SIFCR,
TXX9_SIFCR_TFRST | TXX9_SIFCR_RFRST | TXX9_SIFCR_FRSTE);
sio_set(up, TXX9_SIFLCR, TXX9_SIFLCR_RSDE | TXX9_SIFLCR_TSDE);
free_irq(up->port.irq, up);
}
static void
serial_txx9_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
unsigned int cval, fcr = 0;
unsigned long flags;
unsigned int baud, quot;
termios->c_cflag &= ~(HUPCL | CMSPAR);
termios->c_cflag |= CLOCAL;
cval = sio_in(up, TXX9_SILCR);
cval &= ~TXX9_SILCR_UMODE_MASK;
switch (termios->c_cflag & CSIZE) {
case CS7:
cval |= TXX9_SILCR_UMODE_7BIT;
break;
default:
case CS5:
case CS6:
case CS8:
cval |= TXX9_SILCR_UMODE_8BIT;
break;
}
cval &= ~TXX9_SILCR_USBL_MASK;
if (termios->c_cflag & CSTOPB)
cval |= TXX9_SILCR_USBL_2BIT;
else
cval |= TXX9_SILCR_USBL_1BIT;
cval &= ~(TXX9_SILCR_UPEN | TXX9_SILCR_UEPS);
if (termios->c_cflag & PARENB)
cval |= TXX9_SILCR_UPEN;
if (!(termios->c_cflag & PARODD))
cval |= TXX9_SILCR_UEPS;
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/16/2);
quot = uart_get_divisor(port, baud);
fcr = TXX9_SIFCR_TDIL_MAX | TXX9_SIFCR_RDIL_1;
spin_lock_irqsave(&up->port.lock, flags);
uart_update_timeout(port, termios->c_cflag, baud);
up->port.read_status_mask = TXX9_SIDISR_UOER |
TXX9_SIDISR_TDIS | TXX9_SIDISR_RDIS;
if (termios->c_iflag & INPCK)
up->port.read_status_mask |= TXX9_SIDISR_UFER | TXX9_SIDISR_UPER;
if (termios->c_iflag & (BRKINT | PARMRK))
up->port.read_status_mask |= TXX9_SIDISR_UBRK;
up->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
up->port.ignore_status_mask |= TXX9_SIDISR_UPER | TXX9_SIDISR_UFER;
if (termios->c_iflag & IGNBRK) {
up->port.ignore_status_mask |= TXX9_SIDISR_UBRK;
if (termios->c_iflag & IGNPAR)
up->port.ignore_status_mask |= TXX9_SIDISR_UOER;
}
if ((termios->c_cflag & CREAD) == 0)
up->port.ignore_status_mask |= TXX9_SIDISR_RDIS;
if ((termios->c_cflag & CRTSCTS) &&
(up->port.flags & UPF_TXX9_HAVE_CTS_LINE)) {
sio_set(up, TXX9_SIFLCR,
TXX9_SIFLCR_RCS | TXX9_SIFLCR_TES);
} else {
sio_mask(up, TXX9_SIFLCR,
TXX9_SIFLCR_RCS | TXX9_SIFLCR_TES);
}
sio_out(up, TXX9_SILCR, cval);
sio_quot_set(up, quot);
sio_out(up, TXX9_SIFCR, fcr);
serial_txx9_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static void
serial_txx9_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
if (state == 0 && oldstate != -1)
serial_txx9_initialize(port);
}
static int serial_txx9_request_resource(struct uart_txx9_port *up)
{
unsigned int size = TXX9_REGION_SIZE;
int ret = 0;
switch (up->port.iotype) {
default:
if (!up->port.mapbase)
break;
if (!request_mem_region(up->port.mapbase, size, "serial_txx9")) {
ret = -EBUSY;
break;
}
if (up->port.flags & UPF_IOREMAP) {
up->port.membase = ioremap(up->port.mapbase, size);
if (!up->port.membase) {
release_mem_region(up->port.mapbase, size);
ret = -ENOMEM;
}
}
break;
case UPIO_PORT:
if (!request_region(up->port.iobase, size, "serial_txx9"))
ret = -EBUSY;
break;
}
return ret;
}
static void serial_txx9_release_resource(struct uart_txx9_port *up)
{
unsigned int size = TXX9_REGION_SIZE;
switch (up->port.iotype) {
default:
if (!up->port.mapbase)
break;
if (up->port.flags & UPF_IOREMAP) {
iounmap(up->port.membase);
up->port.membase = NULL;
}
release_mem_region(up->port.mapbase, size);
break;
case UPIO_PORT:
release_region(up->port.iobase, size);
break;
}
}
static void serial_txx9_release_port(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
serial_txx9_release_resource(up);
}
static int serial_txx9_request_port(struct uart_port *port)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
return serial_txx9_request_resource(up);
}
static void serial_txx9_config_port(struct uart_port *port, int uflags)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
int ret;
ret = serial_txx9_request_resource(up);
if (ret < 0)
return;
port->type = PORT_TXX9;
up->port.fifosize = TXX9_SIO_TX_FIFO;
#ifdef CONFIG_SERIAL_TXX9_CONSOLE
if (up->port.line == up->port.cons->index)
return;
#endif
serial_txx9_initialize(port);
}
static const char *
serial_txx9_type(struct uart_port *port)
{
return "txx9";
}
static void __init serial_txx9_register_ports(struct uart_driver *drv,
struct device *dev)
{
int i;
for (i = 0; i < UART_NR; i++) {
struct uart_txx9_port *up = &serial_txx9_ports[i];
up->port.line = i;
up->port.ops = &serial_txx9_pops;
up->port.dev = dev;
if (up->port.iobase || up->port.mapbase)
uart_add_one_port(drv, &up->port);
}
}
static void serial_txx9_console_putchar(struct uart_port *port, int ch)
{
struct uart_txx9_port *up = to_uart_txx9_port(port);
wait_for_xmitr(up);
sio_out(up, TXX9_SITFIFO, ch);
}
static void
serial_txx9_console_write(struct console *co, const char *s, unsigned int count)
{
struct uart_txx9_port *up = &serial_txx9_ports[co->index];
unsigned int ier, flcr;
ier = sio_in(up, TXX9_SIDICR);
sio_out(up, TXX9_SIDICR, 0);
flcr = sio_in(up, TXX9_SIFLCR);
if (!(up->port.flags & UPF_CONS_FLOW) && (flcr & TXX9_SIFLCR_TES))
sio_out(up, TXX9_SIFLCR, flcr & ~TXX9_SIFLCR_TES);
uart_console_write(&up->port, s, count, serial_txx9_console_putchar);
wait_for_xmitr(up);
sio_out(up, TXX9_SIFLCR, flcr);
sio_out(up, TXX9_SIDICR, ier);
}
static int __init serial_txx9_console_setup(struct console *co, char *options)
{
struct uart_port *port;
struct uart_txx9_port *up;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index >= UART_NR)
co->index = 0;
up = &serial_txx9_ports[co->index];
port = &up->port;
if (!port->ops)
return -ENODEV;
serial_txx9_initialize(&up->port);
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init serial_txx9_console_init(void)
{
register_console(&serial_txx9_console);
return 0;
}
int __init early_serial_txx9_setup(struct uart_port *port)
{
if (port->line >= ARRAY_SIZE(serial_txx9_ports))
return -ENODEV;
serial_txx9_ports[port->line].port = *port;
serial_txx9_ports[port->line].port.ops = &serial_txx9_pops;
serial_txx9_ports[port->line].port.flags |=
UPF_BOOT_AUTOCONF | UPF_FIXED_PORT;
return 0;
}
static int __devinit serial_txx9_register_port(struct uart_port *port)
{
int i;
struct uart_txx9_port *uart;
int ret = -ENOSPC;
mutex_lock(&serial_txx9_mutex);
for (i = 0; i < UART_NR; i++) {
uart = &serial_txx9_ports[i];
if (uart_match_port(&uart->port, port)) {
uart_remove_one_port(&serial_txx9_reg, &uart->port);
break;
}
}
if (i == UART_NR) {
for (i = 0; i < UART_NR; i++) {
uart = &serial_txx9_ports[i];
if (!(uart->port.iobase || uart->port.mapbase))
break;
}
}
if (i < UART_NR) {
uart->port.iobase = port->iobase;
uart->port.membase = port->membase;
uart->port.irq = port->irq;
uart->port.uartclk = port->uartclk;
uart->port.iotype = port->iotype;
uart->port.flags = port->flags
| UPF_BOOT_AUTOCONF | UPF_FIXED_PORT;
uart->port.mapbase = port->mapbase;
if (port->dev)
uart->port.dev = port->dev;
ret = uart_add_one_port(&serial_txx9_reg, &uart->port);
if (ret == 0)
ret = uart->port.line;
}
mutex_unlock(&serial_txx9_mutex);
return ret;
}
static void __devexit serial_txx9_unregister_port(int line)
{
struct uart_txx9_port *uart = &serial_txx9_ports[line];
mutex_lock(&serial_txx9_mutex);
uart_remove_one_port(&serial_txx9_reg, &uart->port);
uart->port.flags = 0;
uart->port.type = PORT_UNKNOWN;
uart->port.iobase = 0;
uart->port.mapbase = 0;
uart->port.membase = NULL;
uart->port.dev = NULL;
mutex_unlock(&serial_txx9_mutex);
}
static int __devinit serial_txx9_probe(struct platform_device *dev)
{
struct uart_port *p = dev->dev.platform_data;
struct uart_port port;
int ret, i;
memset(&port, 0, sizeof(struct uart_port));
for (i = 0; p && p->uartclk != 0; p++, i++) {
port.iobase = p->iobase;
port.membase = p->membase;
port.irq = p->irq;
port.uartclk = p->uartclk;
port.iotype = p->iotype;
port.flags = p->flags;
port.mapbase = p->mapbase;
port.dev = &dev->dev;
ret = serial_txx9_register_port(&port);
if (ret < 0) {
dev_err(&dev->dev, "unable to register port at index %d "
"(IO%lx MEM%llx IRQ%d): %d\n", i,
p->iobase, (unsigned long long)p->mapbase,
p->irq, ret);
}
}
return 0;
}
static int __devexit serial_txx9_remove(struct platform_device *dev)
{
int i;
for (i = 0; i < UART_NR; i++) {
struct uart_txx9_port *up = &serial_txx9_ports[i];
if (up->port.dev == &dev->dev)
serial_txx9_unregister_port(i);
}
return 0;
}
static int serial_txx9_suspend(struct platform_device *dev, pm_message_t state)
{
int i;
for (i = 0; i < UART_NR; i++) {
struct uart_txx9_port *up = &serial_txx9_ports[i];
if (up->port.type != PORT_UNKNOWN && up->port.dev == &dev->dev)
uart_suspend_port(&serial_txx9_reg, &up->port);
}
return 0;
}
static int serial_txx9_resume(struct platform_device *dev)
{
int i;
for (i = 0; i < UART_NR; i++) {
struct uart_txx9_port *up = &serial_txx9_ports[i];
if (up->port.type != PORT_UNKNOWN && up->port.dev == &dev->dev)
uart_resume_port(&serial_txx9_reg, &up->port);
}
return 0;
}
static int __devinit
pciserial_txx9_init_one(struct pci_dev *dev, const struct pci_device_id *ent)
{
struct uart_port port;
int line;
int rc;
rc = pci_enable_device(dev);
if (rc)
return rc;
memset(&port, 0, sizeof(port));
port.ops = &serial_txx9_pops;
port.flags |= UPF_TXX9_HAVE_CTS_LINE;
port.uartclk = 66670000;
port.irq = dev->irq;
port.iotype = UPIO_PORT;
port.iobase = pci_resource_start(dev, 1);
port.dev = &dev->dev;
line = serial_txx9_register_port(&port);
if (line < 0) {
printk(KERN_WARNING "Couldn't register serial port %s: %d\n", pci_name(dev), line);
pci_disable_device(dev);
return line;
}
pci_set_drvdata(dev, &serial_txx9_ports[line]);
return 0;
}
static void __devexit pciserial_txx9_remove_one(struct pci_dev *dev)
{
struct uart_txx9_port *up = pci_get_drvdata(dev);
pci_set_drvdata(dev, NULL);
if (up) {
serial_txx9_unregister_port(up->port.line);
pci_disable_device(dev);
}
}
static int pciserial_txx9_suspend_one(struct pci_dev *dev, pm_message_t state)
{
struct uart_txx9_port *up = pci_get_drvdata(dev);
if (up)
uart_suspend_port(&serial_txx9_reg, &up->port);
pci_save_state(dev);
pci_set_power_state(dev, pci_choose_state(dev, state));
return 0;
}
static int pciserial_txx9_resume_one(struct pci_dev *dev)
{
struct uart_txx9_port *up = pci_get_drvdata(dev);
pci_set_power_state(dev, PCI_D0);
pci_restore_state(dev);
if (up)
uart_resume_port(&serial_txx9_reg, &up->port);
return 0;
}
static int __init serial_txx9_init(void)
{
int ret;
printk(KERN_INFO "%s version %s\n", serial_name, serial_version);
ret = uart_register_driver(&serial_txx9_reg);
if (ret)
goto out;
serial_txx9_plat_devs = platform_device_alloc("serial_txx9", -1);
if (!serial_txx9_plat_devs) {
ret = -ENOMEM;
goto unreg_uart_drv;
}
ret = platform_device_add(serial_txx9_plat_devs);
if (ret)
goto put_dev;
serial_txx9_register_ports(&serial_txx9_reg,
&serial_txx9_plat_devs->dev);
ret = platform_driver_register(&serial_txx9_plat_driver);
if (ret)
goto del_dev;
#ifdef ENABLE_SERIAL_TXX9_PCI
ret = pci_register_driver(&serial_txx9_pci_driver);
#endif
if (ret == 0)
goto out;
del_dev:
platform_device_del(serial_txx9_plat_devs);
put_dev:
platform_device_put(serial_txx9_plat_devs);
unreg_uart_drv:
uart_unregister_driver(&serial_txx9_reg);
out:
return ret;
}
static void __exit serial_txx9_exit(void)
{
int i;
#ifdef ENABLE_SERIAL_TXX9_PCI
pci_unregister_driver(&serial_txx9_pci_driver);
#endif
platform_driver_unregister(&serial_txx9_plat_driver);
platform_device_unregister(serial_txx9_plat_devs);
for (i = 0; i < UART_NR; i++) {
struct uart_txx9_port *up = &serial_txx9_ports[i];
if (up->port.iobase || up->port.mapbase)
uart_remove_one_port(&serial_txx9_reg, &up->port);
}
uart_unregister_driver(&serial_txx9_reg);
}
