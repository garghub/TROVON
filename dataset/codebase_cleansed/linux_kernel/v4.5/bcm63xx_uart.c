static inline unsigned int bcm_uart_readl(struct uart_port *port,
unsigned int offset)
{
return __raw_readl(port->membase + offset);
}
static inline void bcm_uart_writel(struct uart_port *port,
unsigned int value, unsigned int offset)
{
__raw_writel(value, port->membase + offset);
}
static unsigned int bcm_uart_tx_empty(struct uart_port *port)
{
unsigned int val;
val = bcm_uart_readl(port, UART_IR_REG);
return (val & UART_IR_STAT(UART_IR_TXEMPTY)) ? 1 : 0;
}
static void bcm_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
unsigned int val;
val = bcm_uart_readl(port, UART_MCTL_REG);
val &= ~(UART_MCTL_DTR_MASK | UART_MCTL_RTS_MASK);
if (!(mctrl & TIOCM_DTR))
val |= UART_MCTL_DTR_MASK;
if (!(mctrl & TIOCM_RTS))
val |= UART_MCTL_RTS_MASK;
bcm_uart_writel(port, val, UART_MCTL_REG);
val = bcm_uart_readl(port, UART_CTL_REG);
if (mctrl & TIOCM_LOOP)
val |= UART_CTL_LOOPBACK_MASK;
else
val &= ~UART_CTL_LOOPBACK_MASK;
bcm_uart_writel(port, val, UART_CTL_REG);
}
static unsigned int bcm_uart_get_mctrl(struct uart_port *port)
{
unsigned int val, mctrl;
mctrl = 0;
val = bcm_uart_readl(port, UART_EXTINP_REG);
if (val & UART_EXTINP_RI_MASK)
mctrl |= TIOCM_RI;
if (val & UART_EXTINP_CTS_MASK)
mctrl |= TIOCM_CTS;
if (val & UART_EXTINP_DCD_MASK)
mctrl |= TIOCM_CD;
if (val & UART_EXTINP_DSR_MASK)
mctrl |= TIOCM_DSR;
return mctrl;
}
static void bcm_uart_stop_tx(struct uart_port *port)
{
unsigned int val;
val = bcm_uart_readl(port, UART_CTL_REG);
val &= ~(UART_CTL_TXEN_MASK);
bcm_uart_writel(port, val, UART_CTL_REG);
val = bcm_uart_readl(port, UART_IR_REG);
val &= ~UART_TX_INT_MASK;
bcm_uart_writel(port, val, UART_IR_REG);
}
static void bcm_uart_start_tx(struct uart_port *port)
{
unsigned int val;
val = bcm_uart_readl(port, UART_IR_REG);
val |= UART_TX_INT_MASK;
bcm_uart_writel(port, val, UART_IR_REG);
val = bcm_uart_readl(port, UART_CTL_REG);
val |= UART_CTL_TXEN_MASK;
bcm_uart_writel(port, val, UART_CTL_REG);
}
static void bcm_uart_stop_rx(struct uart_port *port)
{
unsigned int val;
val = bcm_uart_readl(port, UART_IR_REG);
val &= ~UART_RX_INT_MASK;
bcm_uart_writel(port, val, UART_IR_REG);
}
static void bcm_uart_enable_ms(struct uart_port *port)
{
unsigned int val;
val = bcm_uart_readl(port, UART_IR_REG);
val |= UART_IR_MASK(UART_IR_EXTIP);
bcm_uart_writel(port, val, UART_IR_REG);
}
static void bcm_uart_break_ctl(struct uart_port *port, int ctl)
{
unsigned long flags;
unsigned int val;
spin_lock_irqsave(&port->lock, flags);
val = bcm_uart_readl(port, UART_CTL_REG);
if (ctl)
val |= UART_CTL_XMITBRK_MASK;
else
val &= ~UART_CTL_XMITBRK_MASK;
bcm_uart_writel(port, val, UART_CTL_REG);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *bcm_uart_type(struct uart_port *port)
{
return (port->type == PORT_BCM63XX) ? "bcm63xx_uart" : NULL;
}
static void bcm_uart_do_rx(struct uart_port *port)
{
struct tty_port *tty_port = &port->state->port;
unsigned int max_count;
max_count = 32;
do {
unsigned int iestat, c, cstat;
char flag;
iestat = bcm_uart_readl(port, UART_IR_REG);
if (unlikely(iestat & UART_IR_STAT(UART_IR_RXOVER))) {
unsigned int val;
val = bcm_uart_readl(port, UART_CTL_REG);
val |= UART_CTL_RSTRXFIFO_MASK;
bcm_uart_writel(port, val, UART_CTL_REG);
port->icount.overrun++;
tty_insert_flip_char(tty_port, 0, TTY_OVERRUN);
}
if (!(iestat & UART_IR_STAT(UART_IR_RXNOTEMPTY)))
break;
cstat = c = bcm_uart_readl(port, UART_FIFO_REG);
port->icount.rx++;
flag = TTY_NORMAL;
c &= 0xff;
if (unlikely((cstat & UART_FIFO_ANYERR_MASK))) {
if (cstat & UART_FIFO_BRKDET_MASK) {
port->icount.brk++;
if (uart_handle_break(port))
continue;
}
if (cstat & UART_FIFO_PARERR_MASK)
port->icount.parity++;
if (cstat & UART_FIFO_FRAMEERR_MASK)
port->icount.frame++;
cstat &= port->read_status_mask;
if (cstat & UART_FIFO_BRKDET_MASK)
flag = TTY_BREAK;
if (cstat & UART_FIFO_FRAMEERR_MASK)
flag = TTY_FRAME;
if (cstat & UART_FIFO_PARERR_MASK)
flag = TTY_PARITY;
}
if (uart_handle_sysrq_char(port, c))
continue;
if ((cstat & port->ignore_status_mask) == 0)
tty_insert_flip_char(tty_port, c, flag);
} while (--max_count);
spin_unlock(&port->lock);
tty_flip_buffer_push(tty_port);
spin_lock(&port->lock);
}
static void bcm_uart_do_tx(struct uart_port *port)
{
struct circ_buf *xmit;
unsigned int val, max_count;
if (port->x_char) {
bcm_uart_writel(port, port->x_char, UART_FIFO_REG);
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_tx_stopped(port)) {
bcm_uart_stop_tx(port);
return;
}
xmit = &port->state->xmit;
if (uart_circ_empty(xmit))
goto txq_empty;
val = bcm_uart_readl(port, UART_MCTL_REG);
val = (val & UART_MCTL_TXFIFOFILL_MASK) >> UART_MCTL_TXFIFOFILL_SHIFT;
max_count = port->fifosize - val;
while (max_count--) {
unsigned int c;
c = xmit->buf[xmit->tail];
bcm_uart_writel(port, c, UART_FIFO_REG);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_empty(xmit))
break;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit))
goto txq_empty;
return;
txq_empty:
val = bcm_uart_readl(port, UART_IR_REG);
val &= ~UART_TX_INT_MASK;
bcm_uart_writel(port, val, UART_IR_REG);
return;
}
static irqreturn_t bcm_uart_interrupt(int irq, void *dev_id)
{
struct uart_port *port;
unsigned int irqstat;
port = dev_id;
spin_lock(&port->lock);
irqstat = bcm_uart_readl(port, UART_IR_REG);
if (irqstat & UART_RX_INT_STAT)
bcm_uart_do_rx(port);
if (irqstat & UART_TX_INT_STAT)
bcm_uart_do_tx(port);
if (irqstat & UART_IR_MASK(UART_IR_EXTIP)) {
unsigned int estat;
estat = bcm_uart_readl(port, UART_EXTINP_REG);
if (estat & UART_EXTINP_IRSTAT(UART_EXTINP_IR_CTS))
uart_handle_cts_change(port,
estat & UART_EXTINP_CTS_MASK);
if (estat & UART_EXTINP_IRSTAT(UART_EXTINP_IR_DCD))
uart_handle_dcd_change(port,
estat & UART_EXTINP_DCD_MASK);
}
spin_unlock(&port->lock);
return IRQ_HANDLED;
}
static void bcm_uart_enable(struct uart_port *port)
{
unsigned int val;
val = bcm_uart_readl(port, UART_CTL_REG);
val |= (UART_CTL_BRGEN_MASK | UART_CTL_TXEN_MASK | UART_CTL_RXEN_MASK);
bcm_uart_writel(port, val, UART_CTL_REG);
}
static void bcm_uart_disable(struct uart_port *port)
{
unsigned int val;
val = bcm_uart_readl(port, UART_CTL_REG);
val &= ~(UART_CTL_BRGEN_MASK | UART_CTL_TXEN_MASK |
UART_CTL_RXEN_MASK);
bcm_uart_writel(port, val, UART_CTL_REG);
}
static void bcm_uart_flush(struct uart_port *port)
{
unsigned int val;
val = bcm_uart_readl(port, UART_CTL_REG);
val |= UART_CTL_RSTRXFIFO_MASK | UART_CTL_RSTTXFIFO_MASK;
bcm_uart_writel(port, val, UART_CTL_REG);
(void)bcm_uart_readl(port, UART_FIFO_REG);
}
static int bcm_uart_startup(struct uart_port *port)
{
unsigned int val;
int ret;
bcm_uart_disable(port);
bcm_uart_writel(port, 0, UART_IR_REG);
bcm_uart_flush(port);
(void)bcm_uart_readl(port, UART_EXTINP_REG);
val = bcm_uart_readl(port, UART_MCTL_REG);
val &= ~(UART_MCTL_RXFIFOTHRESH_MASK | UART_MCTL_TXFIFOTHRESH_MASK);
val |= (port->fifosize / 2) << UART_MCTL_RXFIFOTHRESH_SHIFT;
val |= (port->fifosize / 2) << UART_MCTL_TXFIFOTHRESH_SHIFT;
bcm_uart_writel(port, val, UART_MCTL_REG);
val = bcm_uart_readl(port, UART_CTL_REG);
val &= ~UART_CTL_RXTMOUTCNT_MASK;
val |= 1 << UART_CTL_RXTMOUTCNT_SHIFT;
bcm_uart_writel(port, val, UART_CTL_REG);
val = UART_EXTINP_INT_MASK;
val |= UART_EXTINP_DCD_NOSENSE_MASK;
val |= UART_EXTINP_CTS_NOSENSE_MASK;
bcm_uart_writel(port, val, UART_EXTINP_REG);
ret = request_irq(port->irq, bcm_uart_interrupt, 0,
dev_name(port->dev), port);
if (ret)
return ret;
bcm_uart_writel(port, UART_RX_INT_MASK, UART_IR_REG);
bcm_uart_enable(port);
return 0;
}
static void bcm_uart_shutdown(struct uart_port *port)
{
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
bcm_uart_writel(port, 0, UART_IR_REG);
spin_unlock_irqrestore(&port->lock, flags);
bcm_uart_disable(port);
bcm_uart_flush(port);
free_irq(port->irq, port);
}
static void bcm_uart_set_termios(struct uart_port *port,
struct ktermios *new,
struct ktermios *old)
{
unsigned int ctl, baud, quot, ier;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
bcm_uart_disable(port);
bcm_uart_flush(port);
ctl = bcm_uart_readl(port, UART_CTL_REG);
ctl &= ~UART_CTL_BITSPERSYM_MASK;
switch (new->c_cflag & CSIZE) {
case CS5:
ctl |= (0 << UART_CTL_BITSPERSYM_SHIFT);
break;
case CS6:
ctl |= (1 << UART_CTL_BITSPERSYM_SHIFT);
break;
case CS7:
ctl |= (2 << UART_CTL_BITSPERSYM_SHIFT);
break;
default:
ctl |= (3 << UART_CTL_BITSPERSYM_SHIFT);
break;
}
ctl &= ~UART_CTL_STOPBITS_MASK;
if (new->c_cflag & CSTOPB)
ctl |= UART_CTL_STOPBITS_2;
else
ctl |= UART_CTL_STOPBITS_1;
ctl &= ~(UART_CTL_RXPAREN_MASK | UART_CTL_TXPAREN_MASK);
if (new->c_cflag & PARENB)
ctl |= (UART_CTL_RXPAREN_MASK | UART_CTL_TXPAREN_MASK);
ctl &= ~(UART_CTL_RXPAREVEN_MASK | UART_CTL_TXPAREVEN_MASK);
if (new->c_cflag & PARODD)
ctl |= (UART_CTL_RXPAREVEN_MASK | UART_CTL_TXPAREVEN_MASK);
bcm_uart_writel(port, ctl, UART_CTL_REG);
baud = uart_get_baud_rate(port, new, old, 0, port->uartclk / 16);
quot = uart_get_divisor(port, baud) - 1;
bcm_uart_writel(port, quot, UART_BAUD_REG);
ier = bcm_uart_readl(port, UART_IR_REG);
ier &= ~UART_IR_MASK(UART_IR_EXTIP);
if (UART_ENABLE_MS(port, new->c_cflag))
ier |= UART_IR_MASK(UART_IR_EXTIP);
bcm_uart_writel(port, ier, UART_IR_REG);
port->read_status_mask = UART_FIFO_VALID_MASK;
if (new->c_iflag & INPCK) {
port->read_status_mask |= UART_FIFO_FRAMEERR_MASK;
port->read_status_mask |= UART_FIFO_PARERR_MASK;
}
if (new->c_iflag & (IGNBRK | BRKINT))
port->read_status_mask |= UART_FIFO_BRKDET_MASK;
port->ignore_status_mask = 0;
if (new->c_iflag & IGNPAR)
port->ignore_status_mask |= UART_FIFO_PARERR_MASK;
if (new->c_iflag & IGNBRK)
port->ignore_status_mask |= UART_FIFO_BRKDET_MASK;
if (!(new->c_cflag & CREAD))
port->ignore_status_mask |= UART_FIFO_VALID_MASK;
uart_update_timeout(port, new->c_cflag, baud);
bcm_uart_enable(port);
spin_unlock_irqrestore(&port->lock, flags);
}
static int bcm_uart_request_port(struct uart_port *port)
{
return 0;
}
static void bcm_uart_release_port(struct uart_port *port)
{
}
static void bcm_uart_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE) {
if (bcm_uart_request_port(port))
return;
port->type = PORT_BCM63XX;
}
}
static int bcm_uart_verify_port(struct uart_port *port,
struct serial_struct *serinfo)
{
if (port->type != PORT_BCM63XX)
return -EINVAL;
if (port->irq != serinfo->irq)
return -EINVAL;
if (port->iotype != serinfo->io_type)
return -EINVAL;
if (port->mapbase != (unsigned long)serinfo->iomem_base)
return -EINVAL;
return 0;
}
static void wait_for_xmitr(struct uart_port *port)
{
unsigned int tmout;
tmout = 10000;
while (--tmout) {
unsigned int val;
val = bcm_uart_readl(port, UART_IR_REG);
if (val & UART_IR_STAT(UART_IR_TXEMPTY))
break;
udelay(1);
}
if (port->flags & UPF_CONS_FLOW) {
tmout = 1000000;
while (--tmout) {
unsigned int val;
val = bcm_uart_readl(port, UART_EXTINP_REG);
if (val & UART_EXTINP_CTS_MASK)
break;
udelay(1);
}
}
}
static void bcm_console_putchar(struct uart_port *port, int ch)
{
wait_for_xmitr(port);
bcm_uart_writel(port, ch, UART_FIFO_REG);
}
static void bcm_console_write(struct console *co, const char *s,
unsigned int count)
{
struct uart_port *port;
unsigned long flags;
int locked;
port = &ports[co->index];
local_irq_save(flags);
if (port->sysrq) {
locked = 0;
} else if (oops_in_progress) {
locked = spin_trylock(&port->lock);
} else {
spin_lock(&port->lock);
locked = 1;
}
uart_console_write(port, s, count, bcm_console_putchar);
wait_for_xmitr(port);
if (locked)
spin_unlock(&port->lock);
local_irq_restore(flags);
}
static int bcm_console_setup(struct console *co, char *options)
{
struct uart_port *port;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index < 0 || co->index >= BCM63XX_NR_UARTS)
return -EINVAL;
port = &ports[co->index];
if (!port->membase)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init bcm63xx_console_init(void)
{
register_console(&bcm63xx_console);
return 0;
}
static void bcm_early_write(struct console *con, const char *s, unsigned n)
{
struct earlycon_device *dev = con->data;
uart_console_write(&dev->port, s, n, bcm_console_putchar);
wait_for_xmitr(&dev->port);
}
static int __init bcm_early_console_setup(struct earlycon_device *device,
const char *opt)
{
if (!device->port.membase)
return -ENODEV;
device->con->write = bcm_early_write;
return 0;
}
static int bcm_uart_probe(struct platform_device *pdev)
{
struct resource *res_mem, *res_irq;
struct uart_port *port;
struct clk *clk;
int ret;
if (pdev->dev.of_node)
pdev->id = of_alias_get_id(pdev->dev.of_node, "uart");
if (pdev->id < 0 || pdev->id >= BCM63XX_NR_UARTS)
return -EINVAL;
port = &ports[pdev->id];
if (port->membase)
return -EBUSY;
memset(port, 0, sizeof(*port));
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res_mem)
return -ENODEV;
port->mapbase = res_mem->start;
port->membase = devm_ioremap_resource(&pdev->dev, res_mem);
if (IS_ERR(port->membase))
return PTR_ERR(port->membase);
res_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res_irq)
return -ENODEV;
clk = pdev->dev.of_node ? of_clk_get(pdev->dev.of_node, 0) :
clk_get(&pdev->dev, "periph");
if (IS_ERR(clk))
return -ENODEV;
port->iotype = UPIO_MEM;
port->irq = res_irq->start;
port->ops = &bcm_uart_ops;
port->flags = UPF_BOOT_AUTOCONF;
port->dev = &pdev->dev;
port->fifosize = 16;
port->uartclk = clk_get_rate(clk) / 2;
port->line = pdev->id;
clk_put(clk);
ret = uart_add_one_port(&bcm_uart_driver, port);
if (ret) {
ports[pdev->id].membase = NULL;
return ret;
}
platform_set_drvdata(pdev, port);
return 0;
}
static int bcm_uart_remove(struct platform_device *pdev)
{
struct uart_port *port;
port = platform_get_drvdata(pdev);
uart_remove_one_port(&bcm_uart_driver, port);
ports[pdev->id].membase = NULL;
return 0;
}
static int __init bcm_uart_init(void)
{
int ret;
ret = uart_register_driver(&bcm_uart_driver);
if (ret)
return ret;
ret = platform_driver_register(&bcm_uart_platform_driver);
if (ret)
uart_unregister_driver(&bcm_uart_driver);
return ret;
}
static void __exit bcm_uart_exit(void)
{
platform_driver_unregister(&bcm_uart_platform_driver);
uart_unregister_driver(&bcm_uart_driver);
}
