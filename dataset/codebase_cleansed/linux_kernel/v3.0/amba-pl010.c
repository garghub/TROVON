static void pl010_stop_tx(struct uart_port *port)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
unsigned int cr;
cr = readb(uap->port.membase + UART010_CR);
cr &= ~UART010_CR_TIE;
writel(cr, uap->port.membase + UART010_CR);
}
static void pl010_start_tx(struct uart_port *port)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
unsigned int cr;
cr = readb(uap->port.membase + UART010_CR);
cr |= UART010_CR_TIE;
writel(cr, uap->port.membase + UART010_CR);
}
static void pl010_stop_rx(struct uart_port *port)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
unsigned int cr;
cr = readb(uap->port.membase + UART010_CR);
cr &= ~(UART010_CR_RIE | UART010_CR_RTIE);
writel(cr, uap->port.membase + UART010_CR);
}
static void pl010_enable_ms(struct uart_port *port)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
unsigned int cr;
cr = readb(uap->port.membase + UART010_CR);
cr |= UART010_CR_MSIE;
writel(cr, uap->port.membase + UART010_CR);
}
static void pl010_rx_chars(struct uart_amba_port *uap)
{
struct tty_struct *tty = uap->port.state->port.tty;
unsigned int status, ch, flag, rsr, max_count = 256;
status = readb(uap->port.membase + UART01x_FR);
while (UART_RX_DATA(status) && max_count--) {
ch = readb(uap->port.membase + UART01x_DR);
flag = TTY_NORMAL;
uap->port.icount.rx++;
rsr = readb(uap->port.membase + UART01x_RSR) | UART_DUMMY_RSR_RX;
if (unlikely(rsr & UART01x_RSR_ANY)) {
writel(0, uap->port.membase + UART01x_ECR);
if (rsr & UART01x_RSR_BE) {
rsr &= ~(UART01x_RSR_FE | UART01x_RSR_PE);
uap->port.icount.brk++;
if (uart_handle_break(&uap->port))
goto ignore_char;
} else if (rsr & UART01x_RSR_PE)
uap->port.icount.parity++;
else if (rsr & UART01x_RSR_FE)
uap->port.icount.frame++;
if (rsr & UART01x_RSR_OE)
uap->port.icount.overrun++;
rsr &= uap->port.read_status_mask;
if (rsr & UART01x_RSR_BE)
flag = TTY_BREAK;
else if (rsr & UART01x_RSR_PE)
flag = TTY_PARITY;
else if (rsr & UART01x_RSR_FE)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(&uap->port, ch))
goto ignore_char;
uart_insert_char(&uap->port, rsr, UART01x_RSR_OE, ch, flag);
ignore_char:
status = readb(uap->port.membase + UART01x_FR);
}
spin_unlock(&uap->port.lock);
tty_flip_buffer_push(tty);
spin_lock(&uap->port.lock);
}
static void pl010_tx_chars(struct uart_amba_port *uap)
{
struct circ_buf *xmit = &uap->port.state->xmit;
int count;
if (uap->port.x_char) {
writel(uap->port.x_char, uap->port.membase + UART01x_DR);
uap->port.icount.tx++;
uap->port.x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&uap->port)) {
pl010_stop_tx(&uap->port);
return;
}
count = uap->port.fifosize >> 1;
do {
writel(xmit->buf[xmit->tail], uap->port.membase + UART01x_DR);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
uap->port.icount.tx++;
if (uart_circ_empty(xmit))
break;
} while (--count > 0);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&uap->port);
if (uart_circ_empty(xmit))
pl010_stop_tx(&uap->port);
}
static void pl010_modem_status(struct uart_amba_port *uap)
{
unsigned int status, delta;
writel(0, uap->port.membase + UART010_ICR);
status = readb(uap->port.membase + UART01x_FR) & UART01x_FR_MODEM_ANY;
delta = status ^ uap->old_status;
uap->old_status = status;
if (!delta)
return;
if (delta & UART01x_FR_DCD)
uart_handle_dcd_change(&uap->port, status & UART01x_FR_DCD);
if (delta & UART01x_FR_DSR)
uap->port.icount.dsr++;
if (delta & UART01x_FR_CTS)
uart_handle_cts_change(&uap->port, status & UART01x_FR_CTS);
wake_up_interruptible(&uap->port.state->port.delta_msr_wait);
}
static irqreturn_t pl010_int(int irq, void *dev_id)
{
struct uart_amba_port *uap = dev_id;
unsigned int status, pass_counter = AMBA_ISR_PASS_LIMIT;
int handled = 0;
spin_lock(&uap->port.lock);
status = readb(uap->port.membase + UART010_IIR);
if (status) {
do {
if (status & (UART010_IIR_RTIS | UART010_IIR_RIS))
pl010_rx_chars(uap);
if (status & UART010_IIR_MIS)
pl010_modem_status(uap);
if (status & UART010_IIR_TIS)
pl010_tx_chars(uap);
if (pass_counter-- == 0)
break;
status = readb(uap->port.membase + UART010_IIR);
} while (status & (UART010_IIR_RTIS | UART010_IIR_RIS |
UART010_IIR_TIS));
handled = 1;
}
spin_unlock(&uap->port.lock);
return IRQ_RETVAL(handled);
}
static unsigned int pl010_tx_empty(struct uart_port *port)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
unsigned int status = readb(uap->port.membase + UART01x_FR);
return status & UART01x_FR_BUSY ? 0 : TIOCSER_TEMT;
}
static unsigned int pl010_get_mctrl(struct uart_port *port)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
unsigned int result = 0;
unsigned int status;
status = readb(uap->port.membase + UART01x_FR);
if (status & UART01x_FR_DCD)
result |= TIOCM_CAR;
if (status & UART01x_FR_DSR)
result |= TIOCM_DSR;
if (status & UART01x_FR_CTS)
result |= TIOCM_CTS;
return result;
}
static void pl010_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
if (uap->data)
uap->data->set_mctrl(uap->dev, uap->port.membase, mctrl);
}
static void pl010_break_ctl(struct uart_port *port, int break_state)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
unsigned long flags;
unsigned int lcr_h;
spin_lock_irqsave(&uap->port.lock, flags);
lcr_h = readb(uap->port.membase + UART010_LCRH);
if (break_state == -1)
lcr_h |= UART01x_LCRH_BRK;
else
lcr_h &= ~UART01x_LCRH_BRK;
writel(lcr_h, uap->port.membase + UART010_LCRH);
spin_unlock_irqrestore(&uap->port.lock, flags);
}
static int pl010_startup(struct uart_port *port)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
int retval;
retval = clk_enable(uap->clk);
if (retval)
goto out;
uap->port.uartclk = clk_get_rate(uap->clk);
retval = request_irq(uap->port.irq, pl010_int, 0, "uart-pl010", uap);
if (retval)
goto clk_dis;
uap->old_status = readb(uap->port.membase + UART01x_FR) & UART01x_FR_MODEM_ANY;
writel(UART01x_CR_UARTEN | UART010_CR_RIE | UART010_CR_RTIE,
uap->port.membase + UART010_CR);
return 0;
clk_dis:
clk_disable(uap->clk);
out:
return retval;
}
static void pl010_shutdown(struct uart_port *port)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
free_irq(uap->port.irq, uap);
writel(0, uap->port.membase + UART010_CR);
writel(readb(uap->port.membase + UART010_LCRH) &
~(UART01x_LCRH_BRK | UART01x_LCRH_FEN),
uap->port.membase + UART010_LCRH);
clk_disable(uap->clk);
}
static void
pl010_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
unsigned int lcr_h, old_cr;
unsigned long flags;
unsigned int baud, quot;
baud = uart_get_baud_rate(port, termios, old, 0, uap->port.uartclk/16);
quot = uart_get_divisor(port, baud);
switch (termios->c_cflag & CSIZE) {
case CS5:
lcr_h = UART01x_LCRH_WLEN_5;
break;
case CS6:
lcr_h = UART01x_LCRH_WLEN_6;
break;
case CS7:
lcr_h = UART01x_LCRH_WLEN_7;
break;
default:
lcr_h = UART01x_LCRH_WLEN_8;
break;
}
if (termios->c_cflag & CSTOPB)
lcr_h |= UART01x_LCRH_STP2;
if (termios->c_cflag & PARENB) {
lcr_h |= UART01x_LCRH_PEN;
if (!(termios->c_cflag & PARODD))
lcr_h |= UART01x_LCRH_EPS;
}
if (uap->port.fifosize > 1)
lcr_h |= UART01x_LCRH_FEN;
spin_lock_irqsave(&uap->port.lock, flags);
uart_update_timeout(port, termios->c_cflag, baud);
uap->port.read_status_mask = UART01x_RSR_OE;
if (termios->c_iflag & INPCK)
uap->port.read_status_mask |= UART01x_RSR_FE | UART01x_RSR_PE;
if (termios->c_iflag & (BRKINT | PARMRK))
uap->port.read_status_mask |= UART01x_RSR_BE;
uap->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
uap->port.ignore_status_mask |= UART01x_RSR_FE | UART01x_RSR_PE;
if (termios->c_iflag & IGNBRK) {
uap->port.ignore_status_mask |= UART01x_RSR_BE;
if (termios->c_iflag & IGNPAR)
uap->port.ignore_status_mask |= UART01x_RSR_OE;
}
if ((termios->c_cflag & CREAD) == 0)
uap->port.ignore_status_mask |= UART_DUMMY_RSR_RX;
old_cr = readb(uap->port.membase + UART010_CR) & ~UART010_CR_MSIE;
if (UART_ENABLE_MS(port, termios->c_cflag))
old_cr |= UART010_CR_MSIE;
writel(0, uap->port.membase + UART010_CR);
quot -= 1;
writel((quot & 0xf00) >> 8, uap->port.membase + UART010_LCRM);
writel(quot & 0xff, uap->port.membase + UART010_LCRL);
writel(lcr_h, uap->port.membase + UART010_LCRH);
writel(old_cr, uap->port.membase + UART010_CR);
spin_unlock_irqrestore(&uap->port.lock, flags);
}
static void pl010_set_ldisc(struct uart_port *port, int new)
{
if (new == N_PPS) {
port->flags |= UPF_HARDPPS_CD;
pl010_enable_ms(port);
} else
port->flags &= ~UPF_HARDPPS_CD;
}
static const char *pl010_type(struct uart_port *port)
{
return port->type == PORT_AMBA ? "AMBA" : NULL;
}
static void pl010_release_port(struct uart_port *port)
{
release_mem_region(port->mapbase, UART_PORT_SIZE);
}
static int pl010_request_port(struct uart_port *port)
{
return request_mem_region(port->mapbase, UART_PORT_SIZE, "uart-pl010")
!= NULL ? 0 : -EBUSY;
}
static void pl010_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE) {
port->type = PORT_AMBA;
pl010_request_port(port);
}
}
static int pl010_verify_port(struct uart_port *port, struct serial_struct *ser)
{
int ret = 0;
if (ser->type != PORT_UNKNOWN && ser->type != PORT_AMBA)
ret = -EINVAL;
if (ser->irq < 0 || ser->irq >= nr_irqs)
ret = -EINVAL;
if (ser->baud_base < 9600)
ret = -EINVAL;
return ret;
}
static void pl010_console_putchar(struct uart_port *port, int ch)
{
struct uart_amba_port *uap = (struct uart_amba_port *)port;
unsigned int status;
do {
status = readb(uap->port.membase + UART01x_FR);
barrier();
} while (!UART_TX_READY(status));
writel(ch, uap->port.membase + UART01x_DR);
}
static void
pl010_console_write(struct console *co, const char *s, unsigned int count)
{
struct uart_amba_port *uap = amba_ports[co->index];
unsigned int status, old_cr;
clk_enable(uap->clk);
old_cr = readb(uap->port.membase + UART010_CR);
writel(UART01x_CR_UARTEN, uap->port.membase + UART010_CR);
uart_console_write(&uap->port, s, count, pl010_console_putchar);
do {
status = readb(uap->port.membase + UART01x_FR);
barrier();
} while (status & UART01x_FR_BUSY);
writel(old_cr, uap->port.membase + UART010_CR);
clk_disable(uap->clk);
}
static void __init
pl010_console_get_options(struct uart_amba_port *uap, int *baud,
int *parity, int *bits)
{
if (readb(uap->port.membase + UART010_CR) & UART01x_CR_UARTEN) {
unsigned int lcr_h, quot;
lcr_h = readb(uap->port.membase + UART010_LCRH);
*parity = 'n';
if (lcr_h & UART01x_LCRH_PEN) {
if (lcr_h & UART01x_LCRH_EPS)
*parity = 'e';
else
*parity = 'o';
}
if ((lcr_h & 0x60) == UART01x_LCRH_WLEN_7)
*bits = 7;
else
*bits = 8;
quot = readb(uap->port.membase + UART010_LCRL) |
readb(uap->port.membase + UART010_LCRM) << 8;
*baud = uap->port.uartclk / (16 * (quot + 1));
}
}
static int __init pl010_console_setup(struct console *co, char *options)
{
struct uart_amba_port *uap;
int baud = 38400;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index >= UART_NR)
co->index = 0;
uap = amba_ports[co->index];
if (!uap)
return -ENODEV;
uap->port.uartclk = clk_get_rate(uap->clk);
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
else
pl010_console_get_options(uap, &baud, &parity, &bits);
return uart_set_options(&uap->port, co, baud, parity, bits, flow);
}
static int pl010_probe(struct amba_device *dev, const struct amba_id *id)
{
struct uart_amba_port *uap;
void __iomem *base;
int i, ret;
for (i = 0; i < ARRAY_SIZE(amba_ports); i++)
if (amba_ports[i] == NULL)
break;
if (i == ARRAY_SIZE(amba_ports)) {
ret = -EBUSY;
goto out;
}
uap = kzalloc(sizeof(struct uart_amba_port), GFP_KERNEL);
if (!uap) {
ret = -ENOMEM;
goto out;
}
base = ioremap(dev->res.start, resource_size(&dev->res));
if (!base) {
ret = -ENOMEM;
goto free;
}
uap->clk = clk_get(&dev->dev, NULL);
if (IS_ERR(uap->clk)) {
ret = PTR_ERR(uap->clk);
goto unmap;
}
uap->port.dev = &dev->dev;
uap->port.mapbase = dev->res.start;
uap->port.membase = base;
uap->port.iotype = UPIO_MEM;
uap->port.irq = dev->irq[0];
uap->port.fifosize = 16;
uap->port.ops = &amba_pl010_pops;
uap->port.flags = UPF_BOOT_AUTOCONF;
uap->port.line = i;
uap->dev = dev;
uap->data = dev->dev.platform_data;
amba_ports[i] = uap;
amba_set_drvdata(dev, uap);
ret = uart_add_one_port(&amba_reg, &uap->port);
if (ret) {
amba_set_drvdata(dev, NULL);
amba_ports[i] = NULL;
clk_put(uap->clk);
unmap:
iounmap(base);
free:
kfree(uap);
}
out:
return ret;
}
static int pl010_remove(struct amba_device *dev)
{
struct uart_amba_port *uap = amba_get_drvdata(dev);
int i;
amba_set_drvdata(dev, NULL);
uart_remove_one_port(&amba_reg, &uap->port);
for (i = 0; i < ARRAY_SIZE(amba_ports); i++)
if (amba_ports[i] == uap)
amba_ports[i] = NULL;
iounmap(uap->port.membase);
clk_put(uap->clk);
kfree(uap);
return 0;
}
static int pl010_suspend(struct amba_device *dev, pm_message_t state)
{
struct uart_amba_port *uap = amba_get_drvdata(dev);
if (uap)
uart_suspend_port(&amba_reg, &uap->port);
return 0;
}
static int pl010_resume(struct amba_device *dev)
{
struct uart_amba_port *uap = amba_get_drvdata(dev);
if (uap)
uart_resume_port(&amba_reg, &uap->port);
return 0;
}
static int __init pl010_init(void)
{
int ret;
printk(KERN_INFO "Serial: AMBA driver\n");
ret = uart_register_driver(&amba_reg);
if (ret == 0) {
ret = amba_driver_register(&pl010_driver);
if (ret)
uart_unregister_driver(&amba_reg);
}
return ret;
}
static void __exit pl010_exit(void)
{
amba_driver_unregister(&pl010_driver);
uart_unregister_driver(&amba_reg);
}
