static u32 uartlite_inbe32(void __iomem *addr)
{
return ioread32be(addr);
}
static void uartlite_outbe32(u32 val, void __iomem *addr)
{
iowrite32be(val, addr);
}
static u32 uartlite_inle32(void __iomem *addr)
{
return ioread32(addr);
}
static void uartlite_outle32(u32 val, void __iomem *addr)
{
iowrite32(val, addr);
}
static inline u32 uart_in32(u32 offset, struct uart_port *port)
{
struct uartlite_reg_ops *reg_ops = port->private_data;
return reg_ops->in(port->membase + offset);
}
static inline void uart_out32(u32 val, u32 offset, struct uart_port *port)
{
struct uartlite_reg_ops *reg_ops = port->private_data;
reg_ops->out(val, port->membase + offset);
}
static int ulite_receive(struct uart_port *port, int stat)
{
struct tty_port *tport = &port->state->port;
unsigned char ch = 0;
char flag = TTY_NORMAL;
if ((stat & (ULITE_STATUS_RXVALID | ULITE_STATUS_OVERRUN
| ULITE_STATUS_FRAME)) == 0)
return 0;
if (stat & ULITE_STATUS_RXVALID) {
port->icount.rx++;
ch = uart_in32(ULITE_RX, port);
if (stat & ULITE_STATUS_PARITY)
port->icount.parity++;
}
if (stat & ULITE_STATUS_OVERRUN)
port->icount.overrun++;
if (stat & ULITE_STATUS_FRAME)
port->icount.frame++;
if (stat & port->ignore_status_mask & ULITE_STATUS_PARITY)
stat &= ~ULITE_STATUS_RXVALID;
stat &= port->read_status_mask;
if (stat & ULITE_STATUS_PARITY)
flag = TTY_PARITY;
stat &= ~port->ignore_status_mask;
if (stat & ULITE_STATUS_RXVALID)
tty_insert_flip_char(tport, ch, flag);
if (stat & ULITE_STATUS_FRAME)
tty_insert_flip_char(tport, 0, TTY_FRAME);
if (stat & ULITE_STATUS_OVERRUN)
tty_insert_flip_char(tport, 0, TTY_OVERRUN);
return 1;
}
static int ulite_transmit(struct uart_port *port, int stat)
{
struct circ_buf *xmit = &port->state->xmit;
if (stat & ULITE_STATUS_TXFULL)
return 0;
if (port->x_char) {
uart_out32(port->x_char, ULITE_TX, port);
port->x_char = 0;
port->icount.tx++;
return 1;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port))
return 0;
uart_out32(xmit->buf[xmit->tail], ULITE_TX, port);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE-1);
port->icount.tx++;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
return 1;
}
static irqreturn_t ulite_isr(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
int busy, n = 0;
do {
int stat = uart_in32(ULITE_STATUS, port);
busy = ulite_receive(port, stat);
busy |= ulite_transmit(port, stat);
n++;
} while (busy);
if (n > 1) {
tty_flip_buffer_push(&port->state->port);
return IRQ_HANDLED;
} else {
return IRQ_NONE;
}
}
static unsigned int ulite_tx_empty(struct uart_port *port)
{
unsigned long flags;
unsigned int ret;
spin_lock_irqsave(&port->lock, flags);
ret = uart_in32(ULITE_STATUS, port);
spin_unlock_irqrestore(&port->lock, flags);
return ret & ULITE_STATUS_TXEMPTY ? TIOCSER_TEMT : 0;
}
static unsigned int ulite_get_mctrl(struct uart_port *port)
{
return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
}
static void ulite_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void ulite_stop_tx(struct uart_port *port)
{
}
static void ulite_start_tx(struct uart_port *port)
{
ulite_transmit(port, uart_in32(ULITE_STATUS, port));
}
static void ulite_stop_rx(struct uart_port *port)
{
port->ignore_status_mask = ULITE_STATUS_RXVALID | ULITE_STATUS_PARITY
| ULITE_STATUS_FRAME | ULITE_STATUS_OVERRUN;
}
static void ulite_break_ctl(struct uart_port *port, int ctl)
{
}
static int ulite_startup(struct uart_port *port)
{
int ret;
ret = request_irq(port->irq, ulite_isr, IRQF_SHARED, "uartlite", port);
if (ret)
return ret;
uart_out32(ULITE_CONTROL_RST_RX | ULITE_CONTROL_RST_TX,
ULITE_CONTROL, port);
uart_out32(ULITE_CONTROL_IE, ULITE_CONTROL, port);
return 0;
}
static void ulite_shutdown(struct uart_port *port)
{
uart_out32(0, ULITE_CONTROL, port);
uart_in32(ULITE_CONTROL, port);
free_irq(port->irq, port);
}
static void ulite_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
unsigned long flags;
unsigned int baud;
spin_lock_irqsave(&port->lock, flags);
port->read_status_mask = ULITE_STATUS_RXVALID | ULITE_STATUS_OVERRUN
| ULITE_STATUS_TXFULL;
if (termios->c_iflag & INPCK)
port->read_status_mask |=
ULITE_STATUS_PARITY | ULITE_STATUS_FRAME;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= ULITE_STATUS_PARITY
| ULITE_STATUS_FRAME | ULITE_STATUS_OVERRUN;
if ((termios->c_cflag & CREAD) == 0)
port->ignore_status_mask |=
ULITE_STATUS_RXVALID | ULITE_STATUS_PARITY
| ULITE_STATUS_FRAME | ULITE_STATUS_OVERRUN;
baud = uart_get_baud_rate(port, termios, old, 0, 460800);
uart_update_timeout(port, termios->c_cflag, baud);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *ulite_type(struct uart_port *port)
{
return port->type == PORT_UARTLITE ? "uartlite" : NULL;
}
static void ulite_release_port(struct uart_port *port)
{
release_mem_region(port->mapbase, ULITE_REGION);
iounmap(port->membase);
port->membase = NULL;
}
static int ulite_request_port(struct uart_port *port)
{
int ret;
pr_debug("ulite console: port=%p; port->mapbase=%llx\n",
port, (unsigned long long) port->mapbase);
if (!request_mem_region(port->mapbase, ULITE_REGION, "uartlite")) {
dev_err(port->dev, "Memory region busy\n");
return -EBUSY;
}
port->membase = ioremap(port->mapbase, ULITE_REGION);
if (!port->membase) {
dev_err(port->dev, "Unable to map registers\n");
release_mem_region(port->mapbase, ULITE_REGION);
return -EBUSY;
}
port->private_data = &uartlite_be;
ret = uart_in32(ULITE_CONTROL, port);
uart_out32(ULITE_CONTROL_RST_TX, ULITE_CONTROL, port);
ret = uart_in32(ULITE_STATUS, port);
if ((ret & ULITE_STATUS_TXEMPTY) != ULITE_STATUS_TXEMPTY)
port->private_data = &uartlite_le;
return 0;
}
static void ulite_config_port(struct uart_port *port, int flags)
{
if (!ulite_request_port(port))
port->type = PORT_UARTLITE;
}
static int ulite_verify_port(struct uart_port *port, struct serial_struct *ser)
{
return -EINVAL;
}
static int ulite_get_poll_char(struct uart_port *port)
{
if (!(uart_in32(ULITE_STATUS, port) & ULITE_STATUS_RXVALID))
return NO_POLL_CHAR;
return uart_in32(ULITE_RX, port);
}
static void ulite_put_poll_char(struct uart_port *port, unsigned char ch)
{
while (uart_in32(ULITE_STATUS, port) & ULITE_STATUS_TXFULL)
cpu_relax();
uart_out32(ch, ULITE_TX, port);
}
static void ulite_console_wait_tx(struct uart_port *port)
{
u8 val;
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(1000);
while (1) {
val = uart_in32(ULITE_STATUS, port);
if ((val & ULITE_STATUS_TXFULL) == 0)
break;
if (time_after(jiffies, timeout)) {
dev_warn(port->dev,
"timeout waiting for TX buffer empty\n");
break;
}
cpu_relax();
}
}
static void ulite_console_putchar(struct uart_port *port, int ch)
{
ulite_console_wait_tx(port);
uart_out32(ch, ULITE_TX, port);
}
static void ulite_console_write(struct console *co, const char *s,
unsigned int count)
{
struct uart_port *port = &ulite_ports[co->index];
unsigned long flags;
unsigned int ier;
int locked = 1;
if (oops_in_progress) {
locked = spin_trylock_irqsave(&port->lock, flags);
} else
spin_lock_irqsave(&port->lock, flags);
ier = uart_in32(ULITE_STATUS, port) & ULITE_STATUS_IE;
uart_out32(0, ULITE_CONTROL, port);
uart_console_write(port, s, count, ulite_console_putchar);
ulite_console_wait_tx(port);
if (ier)
uart_out32(ULITE_CONTROL_IE, ULITE_CONTROL, port);
if (locked)
spin_unlock_irqrestore(&port->lock, flags);
}
static int ulite_console_setup(struct console *co, char *options)
{
struct uart_port *port;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index < 0 || co->index >= ULITE_NR_UARTS)
return -EINVAL;
port = &ulite_ports[co->index];
if (!port->mapbase) {
pr_debug("console on ttyUL%i not present\n", co->index);
return -ENODEV;
}
if (!port->membase) {
if (ulite_request_port(port))
return -ENODEV;
}
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init ulite_console_init(void)
{
register_console(&ulite_console);
return 0;
}
static int ulite_assign(struct device *dev, int id, u32 base, int irq)
{
struct uart_port *port;
int rc;
if (id < 0) {
for (id = 0; id < ULITE_NR_UARTS; id++)
if (ulite_ports[id].mapbase == 0)
break;
}
if (id < 0 || id >= ULITE_NR_UARTS) {
dev_err(dev, "%s%i too large\n", ULITE_NAME, id);
return -EINVAL;
}
if ((ulite_ports[id].mapbase) && (ulite_ports[id].mapbase != base)) {
dev_err(dev, "cannot assign to %s%i; it is already in use\n",
ULITE_NAME, id);
return -EBUSY;
}
port = &ulite_ports[id];
spin_lock_init(&port->lock);
port->fifosize = 16;
port->regshift = 2;
port->iotype = UPIO_MEM;
port->iobase = 1;
port->mapbase = base;
port->membase = NULL;
port->ops = &ulite_ops;
port->irq = irq;
port->flags = UPF_BOOT_AUTOCONF;
port->dev = dev;
port->type = PORT_UNKNOWN;
port->line = id;
dev_set_drvdata(dev, port);
rc = uart_add_one_port(&ulite_uart_driver, port);
if (rc) {
dev_err(dev, "uart_add_one_port() failed; err=%i\n", rc);
port->mapbase = 0;
dev_set_drvdata(dev, NULL);
return rc;
}
return 0;
}
static int ulite_release(struct device *dev)
{
struct uart_port *port = dev_get_drvdata(dev);
int rc = 0;
if (port) {
rc = uart_remove_one_port(&ulite_uart_driver, port);
dev_set_drvdata(dev, NULL);
port->mapbase = 0;
}
return rc;
}
static int ulite_probe(struct platform_device *pdev)
{
struct resource *res;
int irq;
int id = pdev->id;
#ifdef CONFIG_OF
const __be32 *prop;
prop = of_get_property(pdev->dev.of_node, "port-number", NULL);
if (prop)
id = be32_to_cpup(prop);
#endif
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return -ENXIO;
return ulite_assign(&pdev->dev, id, res->start, irq);
}
static int ulite_remove(struct platform_device *pdev)
{
return ulite_release(&pdev->dev);
}
static int __init ulite_init(void)
{
int ret;
pr_debug("uartlite: calling uart_register_driver()\n");
ret = uart_register_driver(&ulite_uart_driver);
if (ret)
goto err_uart;
pr_debug("uartlite: calling platform_driver_register()\n");
ret = platform_driver_register(&ulite_platform_driver);
if (ret)
goto err_plat;
return 0;
err_plat:
uart_unregister_driver(&ulite_uart_driver);
err_uart:
pr_err("registering uartlite driver failed: err=%i", ret);
return ret;
}
static void __exit ulite_exit(void)
{
platform_driver_unregister(&ulite_platform_driver);
uart_unregister_driver(&ulite_uart_driver);
}
