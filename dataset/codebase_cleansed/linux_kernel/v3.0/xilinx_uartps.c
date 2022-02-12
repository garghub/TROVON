static irqreturn_t xuartps_isr(int irq, void *dev_id)
{
struct uart_port *port = (struct uart_port *)dev_id;
struct tty_struct *tty;
unsigned long flags;
unsigned int isrstatus, numbytes;
unsigned int data;
char status = TTY_NORMAL;
tty = tty_port_tty_get(&port->state->port);
spin_lock_irqsave(&port->lock, flags);
isrstatus = xuartps_readl(XUARTPS_ISR_OFFSET);
if (isrstatus & port->ignore_status_mask & XUARTPS_IXR_PARITY)
isrstatus &= ~(XUARTPS_IXR_RXTRIG | XUARTPS_IXR_TOUT);
isrstatus &= port->read_status_mask;
isrstatus &= ~port->ignore_status_mask;
if ((isrstatus & XUARTPS_IXR_TOUT) ||
(isrstatus & XUARTPS_IXR_RXTRIG)) {
while ((xuartps_readl(XUARTPS_SR_OFFSET) &
XUARTPS_SR_RXEMPTY) != XUARTPS_SR_RXEMPTY) {
data = xuartps_readl(XUARTPS_FIFO_OFFSET);
port->icount.rx++;
if (isrstatus & XUARTPS_IXR_PARITY) {
port->icount.parity++;
status = TTY_PARITY;
} else if (isrstatus & XUARTPS_IXR_FRAMING) {
port->icount.frame++;
status = TTY_FRAME;
} else if (isrstatus & XUARTPS_IXR_OVERRUN)
port->icount.overrun++;
if (tty)
uart_insert_char(port, isrstatus,
XUARTPS_IXR_OVERRUN, data,
status);
}
spin_unlock(&port->lock);
if (tty)
tty_flip_buffer_push(tty);
spin_lock(&port->lock);
}
if ((isrstatus & XUARTPS_IXR_TXEMPTY) == XUARTPS_IXR_TXEMPTY) {
if (uart_circ_empty(&port->state->xmit)) {
xuartps_writel(XUARTPS_IXR_TXEMPTY,
XUARTPS_IDR_OFFSET);
} else {
numbytes = port->fifosize;
while (numbytes--) {
if (uart_circ_empty(&port->state->xmit))
break;
xuartps_writel(
port->state->xmit.buf[port->state->xmit.
tail], XUARTPS_FIFO_OFFSET);
port->icount.tx++;
port->state->xmit.tail =
(port->state->xmit.tail + 1) & \
(UART_XMIT_SIZE - 1);
}
if (uart_circ_chars_pending(
&port->state->xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
}
xuartps_writel(isrstatus, XUARTPS_ISR_OFFSET);
spin_unlock_irqrestore(&port->lock, flags);
tty_kref_put(tty);
return IRQ_HANDLED;
}
static unsigned int xuartps_set_baud_rate(struct uart_port *port,
unsigned int baud)
{
unsigned int sel_clk;
unsigned int calc_baud = 0;
unsigned int brgr_val, brdiv_val;
unsigned int bauderror;
sel_clk = port->uartclk;
if (xuartps_readl(XUARTPS_MR_OFFSET) & XUARTPS_MR_CLKSEL)
sel_clk = sel_clk / 8;
for (brdiv_val = 4; brdiv_val < 255; brdiv_val++) {
brgr_val = sel_clk / (baud * (brdiv_val + 1));
if (brgr_val < 2 || brgr_val > 65535)
continue;
calc_baud = sel_clk / (brgr_val * (brdiv_val + 1));
if (baud > calc_baud)
bauderror = baud - calc_baud;
else
bauderror = calc_baud - baud;
if (((bauderror * 100) / baud) < 3) {
calc_baud = baud;
break;
}
}
xuartps_writel(brgr_val, XUARTPS_BAUDGEN_OFFSET);
xuartps_writel(brdiv_val, XUARTPS_BAUDDIV_OFFSET);
return calc_baud;
}
static void xuartps_start_tx(struct uart_port *port)
{
unsigned int status, numbytes = port->fifosize;
if (uart_circ_empty(&port->state->xmit) || uart_tx_stopped(port))
return;
status = xuartps_readl(XUARTPS_CR_OFFSET);
xuartps_writel((status & ~XUARTPS_CR_TX_DIS) | XUARTPS_CR_TX_EN,
XUARTPS_CR_OFFSET);
while (numbytes-- && ((xuartps_readl(XUARTPS_SR_OFFSET)
& XUARTPS_SR_TXFULL)) != XUARTPS_SR_TXFULL) {
if (uart_circ_empty(&port->state->xmit))
break;
xuartps_writel(
port->state->xmit.buf[port->state->xmit.tail],
XUARTPS_FIFO_OFFSET);
port->icount.tx++;
port->state->xmit.tail = (port->state->xmit.tail + 1) &
(UART_XMIT_SIZE - 1);
}
xuartps_writel(XUARTPS_IXR_TXEMPTY, XUARTPS_IER_OFFSET);
if (uart_circ_chars_pending(&port->state->xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
static void xuartps_stop_tx(struct uart_port *port)
{
unsigned int regval;
regval = xuartps_readl(XUARTPS_CR_OFFSET);
regval |= XUARTPS_CR_TX_DIS;
xuartps_writel(regval, XUARTPS_CR_OFFSET);
}
static void xuartps_stop_rx(struct uart_port *port)
{
unsigned int regval;
regval = xuartps_readl(XUARTPS_CR_OFFSET);
regval |= XUARTPS_CR_RX_DIS;
xuartps_writel(regval, XUARTPS_CR_OFFSET);
}
static unsigned int xuartps_tx_empty(struct uart_port *port)
{
unsigned int status;
status = xuartps_readl(XUARTPS_ISR_OFFSET) & XUARTPS_IXR_TXEMPTY;
return status ? TIOCSER_TEMT : 0;
}
static void xuartps_break_ctl(struct uart_port *port, int ctl)
{
unsigned int status;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
status = xuartps_readl(XUARTPS_CR_OFFSET);
if (ctl == -1)
xuartps_writel(XUARTPS_CR_STARTBRK | status,
XUARTPS_CR_OFFSET);
else {
if ((status & XUARTPS_CR_STOPBRK) == 0)
xuartps_writel(XUARTPS_CR_STOPBRK | status,
XUARTPS_CR_OFFSET);
}
spin_unlock_irqrestore(&port->lock, flags);
}
static void xuartps_set_termios(struct uart_port *port,
struct ktermios *termios, struct ktermios *old)
{
unsigned int cval = 0;
unsigned int baud;
unsigned long flags;
unsigned int ctrl_reg, mode_reg;
spin_lock_irqsave(&port->lock, flags);
while ((xuartps_readl(XUARTPS_SR_OFFSET) &
XUARTPS_SR_RXEMPTY) != XUARTPS_SR_RXEMPTY) {
xuartps_readl(XUARTPS_FIFO_OFFSET);
}
xuartps_writel(xuartps_readl(XUARTPS_CR_OFFSET) |
(XUARTPS_CR_TX_DIS | XUARTPS_CR_RX_DIS),
XUARTPS_CR_OFFSET);
baud = uart_get_baud_rate(port, termios, old, 0, 10000000);
baud = xuartps_set_baud_rate(port, baud);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
uart_update_timeout(port, termios->c_cflag, baud);
xuartps_writel(xuartps_readl(XUARTPS_CR_OFFSET) |
(XUARTPS_CR_TXRST | XUARTPS_CR_RXRST),
XUARTPS_CR_OFFSET);
ctrl_reg = xuartps_readl(XUARTPS_CR_OFFSET);
xuartps_writel(
(ctrl_reg & ~(XUARTPS_CR_TX_DIS | XUARTPS_CR_RX_DIS))
| (XUARTPS_CR_TX_EN | XUARTPS_CR_RX_EN),
XUARTPS_CR_OFFSET);
xuartps_writel(10, XUARTPS_RXTOUT_OFFSET);
port->read_status_mask = XUARTPS_IXR_TXEMPTY | XUARTPS_IXR_RXTRIG |
XUARTPS_IXR_OVERRUN | XUARTPS_IXR_TOUT;
port->ignore_status_mask = 0;
if (termios->c_iflag & INPCK)
port->read_status_mask |= XUARTPS_IXR_PARITY |
XUARTPS_IXR_FRAMING;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= XUARTPS_IXR_PARITY |
XUARTPS_IXR_FRAMING | XUARTPS_IXR_OVERRUN;
if ((termios->c_cflag & CREAD) == 0)
port->ignore_status_mask |= XUARTPS_IXR_RXTRIG |
XUARTPS_IXR_TOUT | XUARTPS_IXR_PARITY |
XUARTPS_IXR_FRAMING | XUARTPS_IXR_OVERRUN;
mode_reg = xuartps_readl(XUARTPS_MR_OFFSET);
switch (termios->c_cflag & CSIZE) {
case CS6:
cval |= XUARTPS_MR_CHARLEN_6_BIT;
break;
case CS7:
cval |= XUARTPS_MR_CHARLEN_7_BIT;
break;
default:
case CS8:
cval |= XUARTPS_MR_CHARLEN_8_BIT;
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= CS8;
break;
}
if (termios->c_cflag & CSTOPB)
cval |= XUARTPS_MR_STOPMODE_2_BIT;
else
cval |= XUARTPS_MR_STOPMODE_1_BIT;
if (termios->c_cflag & PARENB) {
if (termios->c_cflag & CMSPAR) {
if (termios->c_cflag & PARODD)
cval |= XUARTPS_MR_PARITY_MARK;
else
cval |= XUARTPS_MR_PARITY_SPACE;
} else if (termios->c_cflag & PARODD)
cval |= XUARTPS_MR_PARITY_ODD;
else
cval |= XUARTPS_MR_PARITY_EVEN;
} else
cval |= XUARTPS_MR_PARITY_NONE;
xuartps_writel(cval , XUARTPS_MR_OFFSET);
spin_unlock_irqrestore(&port->lock, flags);
}
static int xuartps_startup(struct uart_port *port)
{
unsigned int retval = 0, status = 0;
retval = request_irq(port->irq, xuartps_isr, 0, XUARTPS_NAME,
(void *)port);
if (retval)
return retval;
xuartps_writel(XUARTPS_CR_TX_DIS | XUARTPS_CR_RX_DIS,
XUARTPS_CR_OFFSET);
xuartps_writel(XUARTPS_CR_TXRST | XUARTPS_CR_RXRST,
XUARTPS_CR_OFFSET);
status = xuartps_readl(XUARTPS_CR_OFFSET);
xuartps_writel((status & ~(XUARTPS_CR_TX_DIS | XUARTPS_CR_RX_DIS))
| (XUARTPS_CR_TX_EN | XUARTPS_CR_RX_EN |
XUARTPS_CR_STOPBRK), XUARTPS_CR_OFFSET);
xuartps_writel(XUARTPS_MR_CHMODE_NORM | XUARTPS_MR_STOPMODE_1_BIT
| XUARTPS_MR_PARITY_NONE | XUARTPS_MR_CHARLEN_8_BIT,
XUARTPS_MR_OFFSET);
xuartps_writel(14, XUARTPS_RXWM_OFFSET);
xuartps_writel(10, XUARTPS_RXTOUT_OFFSET);
xuartps_writel(XUARTPS_IXR_TXEMPTY | XUARTPS_IXR_PARITY |
XUARTPS_IXR_FRAMING | XUARTPS_IXR_OVERRUN |
XUARTPS_IXR_RXTRIG | XUARTPS_IXR_TOUT, XUARTPS_IER_OFFSET);
xuartps_writel(~(XUARTPS_IXR_TXEMPTY | XUARTPS_IXR_PARITY |
XUARTPS_IXR_FRAMING | XUARTPS_IXR_OVERRUN |
XUARTPS_IXR_RXTRIG | XUARTPS_IXR_TOUT), XUARTPS_IDR_OFFSET);
return retval;
}
static void xuartps_shutdown(struct uart_port *port)
{
int status;
status = xuartps_readl(XUARTPS_IMR_OFFSET);
xuartps_writel(status, XUARTPS_IDR_OFFSET);
xuartps_writel(XUARTPS_CR_TX_DIS | XUARTPS_CR_RX_DIS,
XUARTPS_CR_OFFSET);
free_irq(port->irq, port);
}
static const char *xuartps_type(struct uart_port *port)
{
return port->type == PORT_XUARTPS ? XUARTPS_NAME : NULL;
}
static int xuartps_verify_port(struct uart_port *port,
struct serial_struct *ser)
{
if (ser->type != PORT_UNKNOWN && ser->type != PORT_XUARTPS)
return -EINVAL;
if (port->irq != ser->irq)
return -EINVAL;
if (ser->io_type != UPIO_MEM)
return -EINVAL;
if (port->iobase != ser->port)
return -EINVAL;
if (ser->hub6 != 0)
return -EINVAL;
return 0;
}
static int xuartps_request_port(struct uart_port *port)
{
if (!request_mem_region(port->mapbase, XUARTPS_REGISTER_SPACE,
XUARTPS_NAME)) {
return -ENOMEM;
}
port->membase = ioremap(port->mapbase, XUARTPS_REGISTER_SPACE);
if (!port->membase) {
dev_err(port->dev, "Unable to map registers\n");
release_mem_region(port->mapbase, XUARTPS_REGISTER_SPACE);
return -ENOMEM;
}
return 0;
}
static void xuartps_release_port(struct uart_port *port)
{
release_mem_region(port->mapbase, XUARTPS_REGISTER_SPACE);
iounmap(port->membase);
port->membase = NULL;
}
static void xuartps_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE && xuartps_request_port(port) == 0)
port->type = PORT_XUARTPS;
}
static unsigned int xuartps_get_mctrl(struct uart_port *port)
{
return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
}
static void xuartps_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void xuartps_enable_ms(struct uart_port *port)
{
}
static struct uart_port *xuartps_get_port(void)
{
struct uart_port *port;
int id;
for (id = 0; id < XUARTPS_NR_PORTS; id++)
if (xuartps_port[id].mapbase == 0)
break;
if (id >= XUARTPS_NR_PORTS)
return NULL;
port = &xuartps_port[id];
spin_lock_init(&port->lock);
port->membase = NULL;
port->iobase = 1;
port->irq = 0;
port->type = PORT_UNKNOWN;
port->iotype = UPIO_MEM32;
port->flags = UPF_BOOT_AUTOCONF;
port->ops = &xuartps_ops;
port->fifosize = XUARTPS_FIFO_SIZE;
port->line = id;
port->dev = NULL;
return port;
}
static void xuartps_console_wait_tx(struct uart_port *port)
{
while ((xuartps_readl(XUARTPS_SR_OFFSET) & XUARTPS_SR_TXEMPTY)
!= XUARTPS_SR_TXEMPTY)
barrier();
}
static void xuartps_console_putchar(struct uart_port *port, int ch)
{
xuartps_console_wait_tx(port);
xuartps_writel(ch, XUARTPS_FIFO_OFFSET);
}
static void xuartps_console_write(struct console *co, const char *s,
unsigned int count)
{
struct uart_port *port = &xuartps_port[co->index];
unsigned long flags;
unsigned int imr;
int locked = 1;
if (oops_in_progress)
locked = spin_trylock_irqsave(&port->lock, flags);
else
spin_lock_irqsave(&port->lock, flags);
imr = xuartps_readl(XUARTPS_IMR_OFFSET);
xuartps_writel(imr, XUARTPS_IDR_OFFSET);
uart_console_write(port, s, count, xuartps_console_putchar);
xuartps_console_wait_tx(port);
xuartps_writel(~imr, XUARTPS_IDR_OFFSET);
xuartps_writel(imr, XUARTPS_IER_OFFSET);
if (locked)
spin_unlock_irqrestore(&port->lock, flags);
}
static int __init xuartps_console_setup(struct console *co, char *options)
{
struct uart_port *port = &xuartps_port[co->index];
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index < 0 || co->index >= XUARTPS_NR_PORTS)
return -EINVAL;
if (!port->mapbase) {
pr_debug("console on ttyPS%i not present\n", co->index);
return -ENODEV;
}
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init xuartps_console_init(void)
{
register_console(&xuartps_console);
return 0;
}
static int __devinit xuartps_probe(struct platform_device *pdev)
{
int rc;
struct uart_port *port;
struct resource *res, *res2;
int clk = 0;
#ifdef CONFIG_OF
const unsigned int *prop;
prop = of_get_property(pdev->dev.of_node, "clock", NULL);
if (prop)
clk = be32_to_cpup(prop);
#else
clk = *((unsigned int *)(pdev->dev.platform_data));
#endif
if (!clk) {
dev_err(&pdev->dev, "no clock specified\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
res2 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res2)
return -ENODEV;
port = xuartps_get_port();
if (!port) {
dev_err(&pdev->dev, "Cannot get uart_port structure\n");
return -ENODEV;
} else {
port->mapbase = res->start;
port->irq = res2->start;
port->dev = &pdev->dev;
port->uartclk = clk;
dev_set_drvdata(&pdev->dev, port);
rc = uart_add_one_port(&xuartps_uart_driver, port);
if (rc) {
dev_err(&pdev->dev,
"uart_add_one_port() failed; err=%i\n", rc);
dev_set_drvdata(&pdev->dev, NULL);
return rc;
}
return 0;
}
}
static int __devexit xuartps_remove(struct platform_device *pdev)
{
struct uart_port *port = dev_get_drvdata(&pdev->dev);
int rc = 0;
if (port) {
rc = uart_remove_one_port(&xuartps_uart_driver, port);
dev_set_drvdata(&pdev->dev, NULL);
port->mapbase = 0;
}
return rc;
}
static int xuartps_suspend(struct platform_device *pdev, pm_message_t state)
{
uart_suspend_port(&xuartps_uart_driver, &xuartps_port[pdev->id]);
return 0;
}
static int xuartps_resume(struct platform_device *pdev)
{
uart_resume_port(&xuartps_uart_driver, &xuartps_port[pdev->id]);
return 0;
}
static int __init xuartps_init(void)
{
int retval = 0;
retval = uart_register_driver(&xuartps_uart_driver);
if (retval)
return retval;
retval = platform_driver_register(&xuartps_platform_driver);
if (retval)
uart_unregister_driver(&xuartps_uart_driver);
return retval;
}
static void __exit xuartps_exit(void)
{
platform_driver_unregister(&xuartps_platform_driver);
uart_unregister_driver(&xuartps_uart_driver);
}
