static inline unsigned int ar933x_uart_read(struct ar933x_uart_port *up,
int offset)
{
return readl(up->port.membase + offset);
}
static inline void ar933x_uart_write(struct ar933x_uart_port *up,
int offset, unsigned int value)
{
writel(value, up->port.membase + offset);
}
static inline void ar933x_uart_rmw(struct ar933x_uart_port *up,
unsigned int offset,
unsigned int mask,
unsigned int val)
{
unsigned int t;
t = ar933x_uart_read(up, offset);
t &= ~mask;
t |= val;
ar933x_uart_write(up, offset, t);
}
static inline void ar933x_uart_rmw_set(struct ar933x_uart_port *up,
unsigned int offset,
unsigned int val)
{
ar933x_uart_rmw(up, offset, 0, val);
}
static inline void ar933x_uart_rmw_clear(struct ar933x_uart_port *up,
unsigned int offset,
unsigned int val)
{
ar933x_uart_rmw(up, offset, val, 0);
}
static inline void ar933x_uart_start_tx_interrupt(struct ar933x_uart_port *up)
{
up->ier |= AR933X_UART_INT_TX_EMPTY;
ar933x_uart_write(up, AR933X_UART_INT_EN_REG, up->ier);
}
static inline void ar933x_uart_stop_tx_interrupt(struct ar933x_uart_port *up)
{
up->ier &= ~AR933X_UART_INT_TX_EMPTY;
ar933x_uart_write(up, AR933X_UART_INT_EN_REG, up->ier);
}
static inline void ar933x_uart_putc(struct ar933x_uart_port *up, int ch)
{
unsigned int rdata;
rdata = ch & AR933X_UART_DATA_TX_RX_MASK;
rdata |= AR933X_UART_DATA_TX_CSR;
ar933x_uart_write(up, AR933X_UART_DATA_REG, rdata);
}
static unsigned int ar933x_uart_tx_empty(struct uart_port *port)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
unsigned long flags;
unsigned int rdata;
spin_lock_irqsave(&up->port.lock, flags);
rdata = ar933x_uart_read(up, AR933X_UART_DATA_REG);
spin_unlock_irqrestore(&up->port.lock, flags);
return (rdata & AR933X_UART_DATA_TX_CSR) ? 0 : TIOCSER_TEMT;
}
static unsigned int ar933x_uart_get_mctrl(struct uart_port *port)
{
return TIOCM_CAR;
}
static void ar933x_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void ar933x_uart_start_tx(struct uart_port *port)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
ar933x_uart_start_tx_interrupt(up);
}
static void ar933x_uart_stop_tx(struct uart_port *port)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
ar933x_uart_stop_tx_interrupt(up);
}
static void ar933x_uart_stop_rx(struct uart_port *port)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
up->ier &= ~AR933X_UART_INT_RX_VALID;
ar933x_uart_write(up, AR933X_UART_INT_EN_REG, up->ier);
}
static void ar933x_uart_break_ctl(struct uart_port *port, int break_state)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
unsigned long flags;
spin_lock_irqsave(&up->port.lock, flags);
if (break_state == -1)
ar933x_uart_rmw_set(up, AR933X_UART_CS_REG,
AR933X_UART_CS_TX_BREAK);
else
ar933x_uart_rmw_clear(up, AR933X_UART_CS_REG,
AR933X_UART_CS_TX_BREAK);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static void ar933x_uart_enable_ms(struct uart_port *port)
{
}
static unsigned long ar933x_uart_get_baud(unsigned int clk,
unsigned int scale,
unsigned int step)
{
u64 t;
u32 div;
div = (2 << 16) * (scale + 1);
t = clk;
t *= step;
t += (div / 2);
do_div(t, div);
return t;
}
static void ar933x_uart_get_scale_step(unsigned int clk,
unsigned int baud,
unsigned int *scale,
unsigned int *step)
{
unsigned int tscale;
long min_diff;
*scale = 0;
*step = 0;
min_diff = baud;
for (tscale = 0; tscale < AR933X_UART_MAX_SCALE; tscale++) {
u64 tstep;
int diff;
tstep = baud * (tscale + 1);
tstep *= (2 << 16);
do_div(tstep, clk);
if (tstep > AR933X_UART_MAX_STEP)
break;
diff = abs(ar933x_uart_get_baud(clk, tscale, tstep) - baud);
if (diff < min_diff) {
min_diff = diff;
*scale = tscale;
*step = tstep;
}
}
}
static void ar933x_uart_set_termios(struct uart_port *port,
struct ktermios *new,
struct ktermios *old)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
unsigned int cs;
unsigned long flags;
unsigned int baud, scale, step;
new->c_cflag &= ~CSIZE;
new->c_cflag |= CS8;
new->c_cflag &= ~CSTOPB;
cs = 0;
if (new->c_cflag & PARENB) {
if (!(new->c_cflag & PARODD))
cs |= AR933X_UART_CS_PARITY_EVEN;
else
cs |= AR933X_UART_CS_PARITY_ODD;
} else {
cs |= AR933X_UART_CS_PARITY_NONE;
}
new->c_cflag &= ~CMSPAR;
baud = uart_get_baud_rate(port, new, old, up->min_baud, up->max_baud);
ar933x_uart_get_scale_step(port->uartclk, baud, &scale, &step);
spin_lock_irqsave(&up->port.lock, flags);
ar933x_uart_rmw_clear(up, AR933X_UART_CS_REG,
AR933X_UART_CS_IF_MODE_M << AR933X_UART_CS_IF_MODE_S);
uart_update_timeout(port, new->c_cflag, baud);
up->port.ignore_status_mask = 0;
if ((new->c_cflag & CREAD) == 0)
up->port.ignore_status_mask |= AR933X_DUMMY_STATUS_RD;
ar933x_uart_write(up, AR933X_UART_CLOCK_REG,
scale << AR933X_UART_CLOCK_SCALE_S | step);
ar933x_uart_rmw(up, AR933X_UART_CS_REG, AR933X_UART_CS_PARITY_M, cs);
ar933x_uart_rmw_set(up, AR933X_UART_CS_REG,
AR933X_UART_CS_HOST_INT_EN);
ar933x_uart_rmw(up, AR933X_UART_CS_REG,
AR933X_UART_CS_IF_MODE_M << AR933X_UART_CS_IF_MODE_S,
AR933X_UART_CS_IF_MODE_DCE << AR933X_UART_CS_IF_MODE_S);
spin_unlock_irqrestore(&up->port.lock, flags);
if (tty_termios_baud_rate(new))
tty_termios_encode_baud_rate(new, baud, baud);
}
static void ar933x_uart_rx_chars(struct ar933x_uart_port *up)
{
struct tty_port *port = &up->port.state->port;
int max_count = 256;
do {
unsigned int rdata;
unsigned char ch;
rdata = ar933x_uart_read(up, AR933X_UART_DATA_REG);
if ((rdata & AR933X_UART_DATA_RX_CSR) == 0)
break;
ar933x_uart_write(up, AR933X_UART_DATA_REG,
AR933X_UART_DATA_RX_CSR);
up->port.icount.rx++;
ch = rdata & AR933X_UART_DATA_TX_RX_MASK;
if (uart_handle_sysrq_char(&up->port, ch))
continue;
if ((up->port.ignore_status_mask & AR933X_DUMMY_STATUS_RD) == 0)
tty_insert_flip_char(port, ch, TTY_NORMAL);
} while (max_count-- > 0);
tty_flip_buffer_push(port);
}
static void ar933x_uart_tx_chars(struct ar933x_uart_port *up)
{
struct circ_buf *xmit = &up->port.state->xmit;
int count;
if (uart_tx_stopped(&up->port))
return;
count = up->port.fifosize;
do {
unsigned int rdata;
rdata = ar933x_uart_read(up, AR933X_UART_DATA_REG);
if ((rdata & AR933X_UART_DATA_TX_CSR) == 0)
break;
if (up->port.x_char) {
ar933x_uart_putc(up, up->port.x_char);
up->port.icount.tx++;
up->port.x_char = 0;
continue;
}
if (uart_circ_empty(xmit))
break;
ar933x_uart_putc(up, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
up->port.icount.tx++;
} while (--count > 0);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
if (!uart_circ_empty(xmit))
ar933x_uart_start_tx_interrupt(up);
}
static irqreturn_t ar933x_uart_interrupt(int irq, void *dev_id)
{
struct ar933x_uart_port *up = dev_id;
unsigned int status;
status = ar933x_uart_read(up, AR933X_UART_CS_REG);
if ((status & AR933X_UART_CS_HOST_INT) == 0)
return IRQ_NONE;
spin_lock(&up->port.lock);
status = ar933x_uart_read(up, AR933X_UART_INT_REG);
status &= ar933x_uart_read(up, AR933X_UART_INT_EN_REG);
if (status & AR933X_UART_INT_RX_VALID) {
ar933x_uart_write(up, AR933X_UART_INT_REG,
AR933X_UART_INT_RX_VALID);
ar933x_uart_rx_chars(up);
}
if (status & AR933X_UART_INT_TX_EMPTY) {
ar933x_uart_write(up, AR933X_UART_INT_REG,
AR933X_UART_INT_TX_EMPTY);
ar933x_uart_stop_tx_interrupt(up);
ar933x_uart_tx_chars(up);
}
spin_unlock(&up->port.lock);
return IRQ_HANDLED;
}
static int ar933x_uart_startup(struct uart_port *port)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
unsigned long flags;
int ret;
ret = request_irq(up->port.irq, ar933x_uart_interrupt,
up->port.irqflags, dev_name(up->port.dev), up);
if (ret)
return ret;
spin_lock_irqsave(&up->port.lock, flags);
ar933x_uart_rmw_set(up, AR933X_UART_CS_REG,
AR933X_UART_CS_HOST_INT_EN);
up->ier = AR933X_UART_INT_RX_VALID;
ar933x_uart_write(up, AR933X_UART_INT_EN_REG, up->ier);
spin_unlock_irqrestore(&up->port.lock, flags);
return 0;
}
static void ar933x_uart_shutdown(struct uart_port *port)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
up->ier = 0;
ar933x_uart_write(up, AR933X_UART_INT_EN_REG, up->ier);
ar933x_uart_rmw_clear(up, AR933X_UART_CS_REG,
AR933X_UART_CS_TX_BREAK);
free_irq(up->port.irq, up);
}
static const char *ar933x_uart_type(struct uart_port *port)
{
return (port->type == PORT_AR933X) ? "AR933X UART" : NULL;
}
static void ar933x_uart_release_port(struct uart_port *port)
{
}
static int ar933x_uart_request_port(struct uart_port *port)
{
return 0;
}
static void ar933x_uart_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_AR933X;
}
static int ar933x_uart_verify_port(struct uart_port *port,
struct serial_struct *ser)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
if (ser->type != PORT_UNKNOWN &&
ser->type != PORT_AR933X)
return -EINVAL;
if (ser->irq < 0 || ser->irq >= NR_IRQS)
return -EINVAL;
if (ser->baud_base < up->min_baud ||
ser->baud_base > up->max_baud)
return -EINVAL;
return 0;
}
static void ar933x_uart_wait_xmitr(struct ar933x_uart_port *up)
{
unsigned int status;
unsigned int timeout = 60000;
do {
status = ar933x_uart_read(up, AR933X_UART_DATA_REG);
if (--timeout == 0)
break;
udelay(1);
} while ((status & AR933X_UART_DATA_TX_CSR) == 0);
}
static void ar933x_uart_console_putchar(struct uart_port *port, int ch)
{
struct ar933x_uart_port *up = (struct ar933x_uart_port *) port;
ar933x_uart_wait_xmitr(up);
ar933x_uart_putc(up, ch);
}
static void ar933x_uart_console_write(struct console *co, const char *s,
unsigned int count)
{
struct ar933x_uart_port *up = ar933x_console_ports[co->index];
unsigned long flags;
unsigned int int_en;
int locked = 1;
local_irq_save(flags);
if (up->port.sysrq)
locked = 0;
else if (oops_in_progress)
locked = spin_trylock(&up->port.lock);
else
spin_lock(&up->port.lock);
int_en = ar933x_uart_read(up, AR933X_UART_INT_EN_REG);
ar933x_uart_write(up, AR933X_UART_INT_EN_REG, 0);
uart_console_write(&up->port, s, count, ar933x_uart_console_putchar);
ar933x_uart_wait_xmitr(up);
ar933x_uart_write(up, AR933X_UART_INT_EN_REG, int_en);
ar933x_uart_write(up, AR933X_UART_INT_REG, AR933X_UART_INT_ALLINTS);
if (locked)
spin_unlock(&up->port.lock);
local_irq_restore(flags);
}
static int ar933x_uart_console_setup(struct console *co, char *options)
{
struct ar933x_uart_port *up;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index < 0 || co->index >= CONFIG_SERIAL_AR933X_NR_UARTS)
return -EINVAL;
up = ar933x_console_ports[co->index];
if (!up)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(&up->port, co, baud, parity, bits, flow);
}
static void ar933x_uart_add_console_port(struct ar933x_uart_port *up)
{
ar933x_console_ports[up->port.line] = up;
}
static inline void ar933x_uart_add_console_port(struct ar933x_uart_port *up) {}
static int ar933x_uart_probe(struct platform_device *pdev)
{
struct ar933x_uart_platform_data *pdata;
struct ar933x_uart_port *up;
struct uart_port *port;
struct resource *mem_res;
struct resource *irq_res;
unsigned int baud;
int id;
int ret;
pdata = pdev->dev.platform_data;
if (!pdata)
return -EINVAL;
id = pdev->id;
if (id == -1)
id = 0;
if (id > CONFIG_SERIAL_AR933X_NR_UARTS)
return -EINVAL;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem_res) {
dev_err(&pdev->dev, "no MEM resource\n");
return -EINVAL;
}
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq_res) {
dev_err(&pdev->dev, "no IRQ resource\n");
return -EINVAL;
}
up = kzalloc(sizeof(struct ar933x_uart_port), GFP_KERNEL);
if (!up)
return -ENOMEM;
port = &up->port;
port->mapbase = mem_res->start;
port->membase = ioremap(mem_res->start, AR933X_UART_REGS_SIZE);
if (!port->membase) {
ret = -ENOMEM;
goto err_free_up;
}
port->line = id;
port->irq = irq_res->start;
port->dev = &pdev->dev;
port->type = PORT_AR933X;
port->iotype = UPIO_MEM32;
port->uartclk = pdata->uartclk;
port->regshift = 2;
port->fifosize = AR933X_UART_FIFO_SIZE;
port->ops = &ar933x_uart_ops;
baud = ar933x_uart_get_baud(port->uartclk, AR933X_UART_MAX_SCALE, 1);
up->min_baud = max_t(unsigned int, baud, AR933X_UART_MIN_BAUD);
baud = ar933x_uart_get_baud(port->uartclk, 0, AR933X_UART_MAX_STEP);
up->max_baud = min_t(unsigned int, baud, AR933X_UART_MAX_BAUD);
ar933x_uart_add_console_port(up);
ret = uart_add_one_port(&ar933x_uart_driver, &up->port);
if (ret)
goto err_unmap;
platform_set_drvdata(pdev, up);
return 0;
err_unmap:
iounmap(up->port.membase);
err_free_up:
kfree(up);
return ret;
}
static int ar933x_uart_remove(struct platform_device *pdev)
{
struct ar933x_uart_port *up;
up = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
if (up) {
uart_remove_one_port(&ar933x_uart_driver, &up->port);
iounmap(up->port.membase);
kfree(up);
}
return 0;
}
static int __init ar933x_uart_init(void)
{
int ret;
ar933x_uart_driver.nr = CONFIG_SERIAL_AR933X_NR_UARTS;
ret = uart_register_driver(&ar933x_uart_driver);
if (ret)
goto err_out;
ret = platform_driver_register(&ar933x_uart_platform_driver);
if (ret)
goto err_unregister_uart_driver;
return 0;
err_unregister_uart_driver:
uart_unregister_driver(&ar933x_uart_driver);
err_out:
return ret;
}
static void __exit ar933x_uart_exit(void)
{
platform_driver_unregister(&ar933x_uart_platform_driver);
uart_unregister_driver(&ar933x_uart_driver);
}
