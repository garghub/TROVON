static inline unsigned int serial_in(struct uart_pxa_port *up, int offset)
{
offset <<= 2;
return readl(up->port.membase + offset);
}
static inline void serial_out(struct uart_pxa_port *up, int offset, int value)
{
offset <<= 2;
writel(value, up->port.membase + offset);
}
static void serial_pxa_enable_ms(struct uart_port *port)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
up->ier |= UART_IER_MSI;
serial_out(up, UART_IER, up->ier);
}
static void serial_pxa_stop_tx(struct uart_port *port)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
if (up->ier & UART_IER_THRI) {
up->ier &= ~UART_IER_THRI;
serial_out(up, UART_IER, up->ier);
}
}
static void serial_pxa_stop_rx(struct uart_port *port)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
up->ier &= ~UART_IER_RLSI;
up->port.read_status_mask &= ~UART_LSR_DR;
serial_out(up, UART_IER, up->ier);
}
static inline void receive_chars(struct uart_pxa_port *up, int *status)
{
struct tty_struct *tty = up->port.state->port.tty;
unsigned int ch, flag;
int max_count = 256;
do {
up->ier &= ~UART_IER_RTOIE;
serial_out(up, UART_IER, up->ier);
ch = serial_in(up, UART_RX);
flag = TTY_NORMAL;
up->port.icount.rx++;
if (unlikely(*status & (UART_LSR_BI | UART_LSR_PE |
UART_LSR_FE | UART_LSR_OE))) {
if (*status & UART_LSR_BI) {
*status &= ~(UART_LSR_FE | UART_LSR_PE);
up->port.icount.brk++;
if (uart_handle_break(&up->port))
goto ignore_char;
} else if (*status & UART_LSR_PE)
up->port.icount.parity++;
else if (*status & UART_LSR_FE)
up->port.icount.frame++;
if (*status & UART_LSR_OE)
up->port.icount.overrun++;
*status &= up->port.read_status_mask;
#ifdef CONFIG_SERIAL_PXA_CONSOLE
if (up->port.line == up->port.cons->index) {
*status |= up->lsr_break_flag;
up->lsr_break_flag = 0;
}
#endif
if (*status & UART_LSR_BI) {
flag = TTY_BREAK;
} else if (*status & UART_LSR_PE)
flag = TTY_PARITY;
else if (*status & UART_LSR_FE)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(&up->port, ch))
goto ignore_char;
uart_insert_char(&up->port, *status, UART_LSR_OE, ch, flag);
ignore_char:
*status = serial_in(up, UART_LSR);
} while ((*status & UART_LSR_DR) && (max_count-- > 0));
tty_flip_buffer_push(tty);
up->ier |= UART_IER_RTOIE;
serial_out(up, UART_IER, up->ier);
}
static void transmit_chars(struct uart_pxa_port *up)
{
struct circ_buf *xmit = &up->port.state->xmit;
int count;
if (up->port.x_char) {
serial_out(up, UART_TX, up->port.x_char);
up->port.icount.tx++;
up->port.x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&up->port)) {
serial_pxa_stop_tx(&up->port);
return;
}
count = up->port.fifosize / 2;
do {
serial_out(up, UART_TX, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
up->port.icount.tx++;
if (uart_circ_empty(xmit))
break;
} while (--count > 0);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
if (uart_circ_empty(xmit))
serial_pxa_stop_tx(&up->port);
}
static void serial_pxa_start_tx(struct uart_port *port)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
if (!(up->ier & UART_IER_THRI)) {
up->ier |= UART_IER_THRI;
serial_out(up, UART_IER, up->ier);
}
}
static inline void check_modem_status(struct uart_pxa_port *up)
{
int status;
status = serial_in(up, UART_MSR);
if ((status & UART_MSR_ANY_DELTA) == 0)
return;
if (status & UART_MSR_TERI)
up->port.icount.rng++;
if (status & UART_MSR_DDSR)
up->port.icount.dsr++;
if (status & UART_MSR_DDCD)
uart_handle_dcd_change(&up->port, status & UART_MSR_DCD);
if (status & UART_MSR_DCTS)
uart_handle_cts_change(&up->port, status & UART_MSR_CTS);
wake_up_interruptible(&up->port.state->port.delta_msr_wait);
}
static inline irqreturn_t serial_pxa_irq(int irq, void *dev_id)
{
struct uart_pxa_port *up = dev_id;
unsigned int iir, lsr;
iir = serial_in(up, UART_IIR);
if (iir & UART_IIR_NO_INT)
return IRQ_NONE;
lsr = serial_in(up, UART_LSR);
if (lsr & UART_LSR_DR)
receive_chars(up, &lsr);
check_modem_status(up);
if (lsr & UART_LSR_THRE)
transmit_chars(up);
return IRQ_HANDLED;
}
static unsigned int serial_pxa_tx_empty(struct uart_port *port)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
unsigned long flags;
unsigned int ret;
spin_lock_irqsave(&up->port.lock, flags);
ret = serial_in(up, UART_LSR) & UART_LSR_TEMT ? TIOCSER_TEMT : 0;
spin_unlock_irqrestore(&up->port.lock, flags);
return ret;
}
static unsigned int serial_pxa_get_mctrl(struct uart_port *port)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
unsigned char status;
unsigned int ret;
status = serial_in(up, UART_MSR);
ret = 0;
if (status & UART_MSR_DCD)
ret |= TIOCM_CAR;
if (status & UART_MSR_RI)
ret |= TIOCM_RNG;
if (status & UART_MSR_DSR)
ret |= TIOCM_DSR;
if (status & UART_MSR_CTS)
ret |= TIOCM_CTS;
return ret;
}
static void serial_pxa_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
unsigned char mcr = 0;
if (mctrl & TIOCM_RTS)
mcr |= UART_MCR_RTS;
if (mctrl & TIOCM_DTR)
mcr |= UART_MCR_DTR;
if (mctrl & TIOCM_OUT1)
mcr |= UART_MCR_OUT1;
if (mctrl & TIOCM_OUT2)
mcr |= UART_MCR_OUT2;
if (mctrl & TIOCM_LOOP)
mcr |= UART_MCR_LOOP;
mcr |= up->mcr;
serial_out(up, UART_MCR, mcr);
}
static void serial_pxa_break_ctl(struct uart_port *port, int break_state)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
unsigned long flags;
spin_lock_irqsave(&up->port.lock, flags);
if (break_state == -1)
up->lcr |= UART_LCR_SBC;
else
up->lcr &= ~UART_LCR_SBC;
serial_out(up, UART_LCR, up->lcr);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static int serial_pxa_startup(struct uart_port *port)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
unsigned long flags;
int retval;
if (port->line == 3)
up->mcr |= UART_MCR_AFE;
else
up->mcr = 0;
up->port.uartclk = clk_get_rate(up->clk);
retval = request_irq(up->port.irq, serial_pxa_irq, 0, up->name, up);
if (retval)
return retval;
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
serial_out(up, UART_FCR, 0);
(void) serial_in(up, UART_LSR);
(void) serial_in(up, UART_RX);
(void) serial_in(up, UART_IIR);
(void) serial_in(up, UART_MSR);
serial_out(up, UART_LCR, UART_LCR_WLEN8);
spin_lock_irqsave(&up->port.lock, flags);
up->port.mctrl |= TIOCM_OUT2;
serial_pxa_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
up->ier = UART_IER_RLSI | UART_IER_RDI | UART_IER_RTOIE | UART_IER_UUE;
serial_out(up, UART_IER, up->ier);
(void) serial_in(up, UART_LSR);
(void) serial_in(up, UART_RX);
(void) serial_in(up, UART_IIR);
(void) serial_in(up, UART_MSR);
return 0;
}
static void serial_pxa_shutdown(struct uart_port *port)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
unsigned long flags;
free_irq(up->port.irq, up);
up->ier = 0;
serial_out(up, UART_IER, 0);
spin_lock_irqsave(&up->port.lock, flags);
up->port.mctrl &= ~TIOCM_OUT2;
serial_pxa_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
serial_out(up, UART_LCR, serial_in(up, UART_LCR) & ~UART_LCR_SBC);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR |
UART_FCR_CLEAR_XMIT);
serial_out(up, UART_FCR, 0);
}
static void
serial_pxa_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
unsigned char cval, fcr = 0;
unsigned long flags;
unsigned int baud, quot;
unsigned int dll;
switch (termios->c_cflag & CSIZE) {
case CS5:
cval = UART_LCR_WLEN5;
break;
case CS6:
cval = UART_LCR_WLEN6;
break;
case CS7:
cval = UART_LCR_WLEN7;
break;
default:
case CS8:
cval = UART_LCR_WLEN8;
break;
}
if (termios->c_cflag & CSTOPB)
cval |= UART_LCR_STOP;
if (termios->c_cflag & PARENB)
cval |= UART_LCR_PARITY;
if (!(termios->c_cflag & PARODD))
cval |= UART_LCR_EPAR;
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/16);
quot = uart_get_divisor(port, baud);
if ((up->port.uartclk / quot) < (2400 * 16))
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_PXAR1;
else if ((up->port.uartclk / quot) < (230400 * 16))
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_PXAR8;
else
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_PXAR32;
spin_lock_irqsave(&up->port.lock, flags);
up->ier |= UART_IER_UUE;
uart_update_timeout(port, termios->c_cflag, baud);
up->port.read_status_mask = UART_LSR_OE | UART_LSR_THRE | UART_LSR_DR;
if (termios->c_iflag & INPCK)
up->port.read_status_mask |= UART_LSR_FE | UART_LSR_PE;
if (termios->c_iflag & (BRKINT | PARMRK))
up->port.read_status_mask |= UART_LSR_BI;
up->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
up->port.ignore_status_mask |= UART_LSR_PE | UART_LSR_FE;
if (termios->c_iflag & IGNBRK) {
up->port.ignore_status_mask |= UART_LSR_BI;
if (termios->c_iflag & IGNPAR)
up->port.ignore_status_mask |= UART_LSR_OE;
}
if ((termios->c_cflag & CREAD) == 0)
up->port.ignore_status_mask |= UART_LSR_DR;
up->ier &= ~UART_IER_MSI;
if (UART_ENABLE_MS(&up->port, termios->c_cflag))
up->ier |= UART_IER_MSI;
serial_out(up, UART_IER, up->ier);
if (termios->c_cflag & CRTSCTS)
up->mcr |= UART_MCR_AFE;
else
up->mcr &= ~UART_MCR_AFE;
serial_out(up, UART_LCR, cval | UART_LCR_DLAB);
serial_out(up, UART_DLL, quot & 0xff);
dll = serial_in(up, UART_DLL);
WARN_ON(dll != (quot & 0xff));
serial_out(up, UART_DLM, quot >> 8);
serial_out(up, UART_LCR, cval);
up->lcr = cval;
serial_pxa_set_mctrl(&up->port, up->port.mctrl);
serial_out(up, UART_FCR, fcr);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static void
serial_pxa_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
if (!state)
clk_enable(up->clk);
else
clk_disable(up->clk);
}
static void serial_pxa_release_port(struct uart_port *port)
{
}
static int serial_pxa_request_port(struct uart_port *port)
{
return 0;
}
static void serial_pxa_config_port(struct uart_port *port, int flags)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
up->port.type = PORT_PXA;
}
static int
serial_pxa_verify_port(struct uart_port *port, struct serial_struct *ser)
{
return -EINVAL;
}
static const char *
serial_pxa_type(struct uart_port *port)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
return up->name;
}
static inline void wait_for_xmitr(struct uart_pxa_port *up)
{
unsigned int status, tmout = 10000;
do {
status = serial_in(up, UART_LSR);
if (status & UART_LSR_BI)
up->lsr_break_flag = UART_LSR_BI;
if (--tmout == 0)
break;
udelay(1);
} while ((status & BOTH_EMPTY) != BOTH_EMPTY);
if (up->port.flags & UPF_CONS_FLOW) {
tmout = 1000000;
while (--tmout &&
((serial_in(up, UART_MSR) & UART_MSR_CTS) == 0))
udelay(1);
}
}
static void serial_pxa_console_putchar(struct uart_port *port, int ch)
{
struct uart_pxa_port *up = (struct uart_pxa_port *)port;
wait_for_xmitr(up);
serial_out(up, UART_TX, ch);
}
static void
serial_pxa_console_write(struct console *co, const char *s, unsigned int count)
{
struct uart_pxa_port *up = serial_pxa_ports[co->index];
unsigned int ier;
clk_enable(up->clk);
ier = serial_in(up, UART_IER);
serial_out(up, UART_IER, UART_IER_UUE);
uart_console_write(&up->port, s, count, serial_pxa_console_putchar);
wait_for_xmitr(up);
serial_out(up, UART_IER, ier);
clk_disable(up->clk);
}
static int __init
serial_pxa_console_setup(struct console *co, char *options)
{
struct uart_pxa_port *up;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index == -1 || co->index >= serial_pxa_reg.nr)
co->index = 0;
up = serial_pxa_ports[co->index];
if (!up)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(&up->port, co, baud, parity, bits, flow);
}
static int serial_pxa_suspend(struct device *dev)
{
struct uart_pxa_port *sport = dev_get_drvdata(dev);
if (sport)
uart_suspend_port(&serial_pxa_reg, &sport->port);
return 0;
}
static int serial_pxa_resume(struct device *dev)
{
struct uart_pxa_port *sport = dev_get_drvdata(dev);
if (sport)
uart_resume_port(&serial_pxa_reg, &sport->port);
return 0;
}
static int serial_pxa_probe(struct platform_device *dev)
{
struct uart_pxa_port *sport;
struct resource *mmres, *irqres;
int ret;
mmres = platform_get_resource(dev, IORESOURCE_MEM, 0);
irqres = platform_get_resource(dev, IORESOURCE_IRQ, 0);
if (!mmres || !irqres)
return -ENODEV;
sport = kzalloc(sizeof(struct uart_pxa_port), GFP_KERNEL);
if (!sport)
return -ENOMEM;
sport->clk = clk_get(&dev->dev, NULL);
if (IS_ERR(sport->clk)) {
ret = PTR_ERR(sport->clk);
goto err_free;
}
sport->port.type = PORT_PXA;
sport->port.iotype = UPIO_MEM;
sport->port.mapbase = mmres->start;
sport->port.irq = irqres->start;
sport->port.fifosize = 64;
sport->port.ops = &serial_pxa_pops;
sport->port.line = dev->id;
sport->port.dev = &dev->dev;
sport->port.flags = UPF_IOREMAP | UPF_BOOT_AUTOCONF;
sport->port.uartclk = clk_get_rate(sport->clk);
switch (dev->id) {
case 0: sport->name = "FFUART"; break;
case 1: sport->name = "BTUART"; break;
case 2: sport->name = "STUART"; break;
case 3: sport->name = "HWUART"; break;
default:
sport->name = "???";
break;
}
sport->port.membase = ioremap(mmres->start, resource_size(mmres));
if (!sport->port.membase) {
ret = -ENOMEM;
goto err_clk;
}
serial_pxa_ports[dev->id] = sport;
uart_add_one_port(&serial_pxa_reg, &sport->port);
platform_set_drvdata(dev, sport);
return 0;
err_clk:
clk_put(sport->clk);
err_free:
kfree(sport);
return ret;
}
static int serial_pxa_remove(struct platform_device *dev)
{
struct uart_pxa_port *sport = platform_get_drvdata(dev);
platform_set_drvdata(dev, NULL);
uart_remove_one_port(&serial_pxa_reg, &sport->port);
clk_put(sport->clk);
kfree(sport);
return 0;
}
int __init serial_pxa_init(void)
{
int ret;
ret = uart_register_driver(&serial_pxa_reg);
if (ret != 0)
return ret;
ret = platform_driver_register(&serial_pxa_driver);
if (ret != 0)
uart_unregister_driver(&serial_pxa_reg);
return ret;
}
void __exit serial_pxa_exit(void)
{
platform_driver_unregister(&serial_pxa_driver);
uart_unregister_driver(&serial_pxa_reg);
}
