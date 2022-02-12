static inline struct asc_port *to_asc_port(struct uart_port *port)
{
return container_of(port, struct asc_port, port);
}
static inline u32 asc_in(struct uart_port *port, u32 offset)
{
#ifdef readl_relaxed
return readl_relaxed(port->membase + offset);
#else
return readl(port->membase + offset);
#endif
}
static inline void asc_out(struct uart_port *port, u32 offset, u32 value)
{
#ifdef writel_relaxed
writel_relaxed(value, port->membase + offset);
#else
writel(value, port->membase + offset);
#endif
}
static inline void asc_disable_tx_interrupts(struct uart_port *port)
{
u32 intenable = asc_in(port, ASC_INTEN) & ~ASC_INTEN_THE;
asc_out(port, ASC_INTEN, intenable);
(void)asc_in(port, ASC_INTEN);
}
static inline void asc_enable_tx_interrupts(struct uart_port *port)
{
u32 intenable = asc_in(port, ASC_INTEN) | ASC_INTEN_THE;
asc_out(port, ASC_INTEN, intenable);
}
static inline void asc_disable_rx_interrupts(struct uart_port *port)
{
u32 intenable = asc_in(port, ASC_INTEN) & ~ASC_INTEN_RBE;
asc_out(port, ASC_INTEN, intenable);
(void)asc_in(port, ASC_INTEN);
}
static inline void asc_enable_rx_interrupts(struct uart_port *port)
{
u32 intenable = asc_in(port, ASC_INTEN) | ASC_INTEN_RBE;
asc_out(port, ASC_INTEN, intenable);
}
static inline u32 asc_txfifo_is_empty(struct uart_port *port)
{
return asc_in(port, ASC_STA) & ASC_STA_TE;
}
static inline u32 asc_txfifo_is_half_empty(struct uart_port *port)
{
return asc_in(port, ASC_STA) & ASC_STA_THE;
}
static inline const char *asc_port_name(struct uart_port *port)
{
return to_platform_device(port->dev)->name;
}
static inline unsigned asc_hw_txroom(struct uart_port *port)
{
u32 status = asc_in(port, ASC_STA);
if (status & ASC_STA_THE)
return port->fifosize / 2;
else if (!(status & ASC_STA_TF))
return 1;
return 0;
}
static void asc_transmit_chars(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
int txroom;
unsigned char c;
txroom = asc_hw_txroom(port);
if ((txroom != 0) && port->x_char) {
c = port->x_char;
port->x_char = 0;
asc_out(port, ASC_TXBUF, c);
port->icount.tx++;
txroom = asc_hw_txroom(port);
}
if (uart_tx_stopped(port)) {
asc_disable_tx_interrupts(port);
return;
}
if (uart_circ_empty(xmit)) {
asc_disable_tx_interrupts(port);
return;
}
if (txroom == 0)
return;
do {
c = xmit->buf[xmit->tail];
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
asc_out(port, ASC_TXBUF, c);
port->icount.tx++;
txroom--;
} while ((txroom > 0) && (!uart_circ_empty(xmit)));
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit))
asc_disable_tx_interrupts(port);
}
static void asc_receive_chars(struct uart_port *port)
{
struct tty_port *tport = &port->state->port;
unsigned long status, mode;
unsigned long c = 0;
char flag;
bool ignore_pe = false;
mode = asc_in(port, ASC_CTL) & ASC_CTL_MODE_MSK;
if (mode == ASC_CTL_MODE_8BIT || mode == ASC_CTL_MODE_8BIT_PAR)
ignore_pe = true;
if (irqd_is_wakeup_set(irq_get_irq_data(port->irq)))
pm_wakeup_event(tport->tty->dev, 0);
while ((status = asc_in(port, ASC_STA)) & ASC_STA_RBF) {
c = asc_in(port, ASC_RXBUF) | ASC_RXBUF_DUMMY_RX;
flag = TTY_NORMAL;
port->icount.rx++;
if (status & ASC_STA_OE || c & ASC_RXBUF_FE ||
(c & ASC_RXBUF_PE && !ignore_pe)) {
if (c & ASC_RXBUF_FE) {
if (c == (ASC_RXBUF_FE | ASC_RXBUF_DUMMY_RX)) {
port->icount.brk++;
if (uart_handle_break(port))
continue;
c |= ASC_RXBUF_DUMMY_BE;
} else {
port->icount.frame++;
}
} else if (c & ASC_RXBUF_PE) {
port->icount.parity++;
}
if (status & ASC_STA_OE) {
port->icount.overrun++;
c |= ASC_RXBUF_DUMMY_OE;
}
c &= port->read_status_mask;
if (c & ASC_RXBUF_DUMMY_BE)
flag = TTY_BREAK;
else if (c & ASC_RXBUF_PE)
flag = TTY_PARITY;
else if (c & ASC_RXBUF_FE)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(port, c & 0xff))
continue;
uart_insert_char(port, c, ASC_RXBUF_DUMMY_OE, c & 0xff, flag);
}
tty_flip_buffer_push(tport);
}
static irqreturn_t asc_interrupt(int irq, void *ptr)
{
struct uart_port *port = ptr;
u32 status;
spin_lock(&port->lock);
status = asc_in(port, ASC_STA);
if (status & ASC_STA_RBF) {
asc_receive_chars(port);
}
if ((status & ASC_STA_THE) &&
(asc_in(port, ASC_INTEN) & ASC_INTEN_THE)) {
asc_transmit_chars(port);
}
spin_unlock(&port->lock);
return IRQ_HANDLED;
}
static unsigned int asc_tx_empty(struct uart_port *port)
{
return asc_txfifo_is_empty(port) ? TIOCSER_TEMT : 0;
}
static void asc_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct asc_port *ascport = to_asc_port(port);
if (!ascport->rts)
return;
if (asc_in(port, ASC_CTL) & ASC_CTL_CTSENABLE)
return;
gpiod_set_value(ascport->rts, mctrl & TIOCM_RTS);
}
static unsigned int asc_get_mctrl(struct uart_port *port)
{
return TIOCM_CAR | TIOCM_DSR | TIOCM_CTS;
}
static void asc_start_tx(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
if (!uart_circ_empty(xmit))
asc_enable_tx_interrupts(port);
}
static void asc_stop_tx(struct uart_port *port)
{
asc_disable_tx_interrupts(port);
}
static void asc_stop_rx(struct uart_port *port)
{
asc_disable_rx_interrupts(port);
}
static void asc_break_ctl(struct uart_port *port, int break_state)
{
}
static int asc_startup(struct uart_port *port)
{
if (request_irq(port->irq, asc_interrupt, 0,
asc_port_name(port), port)) {
dev_err(port->dev, "cannot allocate irq.\n");
return -ENODEV;
}
asc_transmit_chars(port);
asc_enable_rx_interrupts(port);
return 0;
}
static void asc_shutdown(struct uart_port *port)
{
asc_disable_tx_interrupts(port);
asc_disable_rx_interrupts(port);
free_irq(port->irq, port);
}
static void asc_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct asc_port *ascport = to_asc_port(port);
unsigned long flags = 0;
u32 ctl;
switch (state) {
case UART_PM_STATE_ON:
clk_prepare_enable(ascport->clk);
break;
case UART_PM_STATE_OFF:
spin_lock_irqsave(&port->lock, flags);
ctl = asc_in(port, ASC_CTL) & ~ASC_CTL_RUN;
asc_out(port, ASC_CTL, ctl);
spin_unlock_irqrestore(&port->lock, flags);
clk_disable_unprepare(ascport->clk);
break;
}
}
static void asc_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct asc_port *ascport = to_asc_port(port);
struct device_node *np = port->dev->of_node;
struct gpio_desc *gpiod;
unsigned int baud;
u32 ctrl_val;
tcflag_t cflag;
unsigned long flags;
termios->c_cflag &= ~(CMSPAR |
(ascport->hw_flow_control ? 0 : CRTSCTS));
port->uartclk = clk_get_rate(ascport->clk);
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/16);
cflag = termios->c_cflag;
spin_lock_irqsave(&port->lock, flags);
ctrl_val = asc_in(port, ASC_CTL);
asc_out(port, ASC_CTL, (ctrl_val & ~ASC_CTL_RUN));
ctrl_val = ASC_CTL_RXENABLE | ASC_CTL_FIFOENABLE;
asc_out(port, ASC_TXRESET, 1);
asc_out(port, ASC_RXRESET, 1);
if ((cflag & CSIZE) == CS7) {
ctrl_val |= ASC_CTL_MODE_7BIT_PAR;
} else {
ctrl_val |= (cflag & PARENB) ? ASC_CTL_MODE_8BIT_PAR :
ASC_CTL_MODE_8BIT;
}
ctrl_val |= (cflag & CSTOPB) ? ASC_CTL_STOP_2BIT : ASC_CTL_STOP_1BIT;
if (cflag & PARODD)
ctrl_val |= ASC_CTL_PARITYODD;
if ((cflag & CRTSCTS)) {
ctrl_val |= ASC_CTL_CTSENABLE;
if (ascport->rts) {
devm_gpiod_put(port->dev, ascport->rts);
ascport->rts = NULL;
pinctrl_select_state(ascport->pinctrl,
ascport->states[DEFAULT]);
}
} else {
if (!ascport->rts && ascport->states[NO_HW_FLOWCTRL]) {
pinctrl_select_state(ascport->pinctrl,
ascport->states[NO_HW_FLOWCTRL]);
gpiod = devm_fwnode_get_gpiod_from_child(port->dev,
"rts",
&np->fwnode,
GPIOD_OUT_LOW,
np->name);
if (!IS_ERR(gpiod))
ascport->rts = gpiod;
}
}
if ((baud < 19200) && !ascport->force_m1) {
asc_out(port, ASC_BAUDRATE, (port->uartclk / (16 * baud)));
} else {
u64 dividend = (u64)baud * (1 << 16);
do_div(dividend, port->uartclk / 16);
asc_out(port, ASC_BAUDRATE, dividend);
ctrl_val |= ASC_CTL_BAUDMODE;
}
uart_update_timeout(port, cflag, baud);
ascport->port.read_status_mask = ASC_RXBUF_DUMMY_OE;
if (termios->c_iflag & INPCK)
ascport->port.read_status_mask |= ASC_RXBUF_FE | ASC_RXBUF_PE;
if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
ascport->port.read_status_mask |= ASC_RXBUF_DUMMY_BE;
ascport->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
ascport->port.ignore_status_mask |= ASC_RXBUF_FE | ASC_RXBUF_PE;
if (termios->c_iflag & IGNBRK) {
ascport->port.ignore_status_mask |= ASC_RXBUF_DUMMY_BE;
if (termios->c_iflag & IGNPAR)
ascport->port.ignore_status_mask |= ASC_RXBUF_DUMMY_OE;
}
if (!(termios->c_cflag & CREAD))
ascport->port.ignore_status_mask |= ASC_RXBUF_DUMMY_RX;
asc_out(port, ASC_TIMEOUT, 20);
asc_out(port, ASC_CTL, (ctrl_val | ASC_CTL_RUN));
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *asc_type(struct uart_port *port)
{
return (port->type == PORT_ASC) ? DRIVER_NAME : NULL;
}
static void asc_release_port(struct uart_port *port)
{
}
static int asc_request_port(struct uart_port *port)
{
return 0;
}
static void asc_config_port(struct uart_port *port, int flags)
{
if ((flags & UART_CONFIG_TYPE))
port->type = PORT_ASC;
}
static int
asc_verify_port(struct uart_port *port, struct serial_struct *ser)
{
return -EINVAL;
}
static int asc_get_poll_char(struct uart_port *port)
{
if (!(asc_in(port, ASC_STA) & ASC_STA_RBF))
return NO_POLL_CHAR;
return asc_in(port, ASC_RXBUF);
}
static void asc_put_poll_char(struct uart_port *port, unsigned char c)
{
while (!asc_txfifo_is_half_empty(port))
cpu_relax();
asc_out(port, ASC_TXBUF, c);
}
static int asc_init_port(struct asc_port *ascport,
struct platform_device *pdev)
{
struct uart_port *port = &ascport->port;
struct resource *res;
int ret;
port->iotype = UPIO_MEM;
port->flags = UPF_BOOT_AUTOCONF;
port->ops = &asc_uart_ops;
port->fifosize = ASC_FIFO_SIZE;
port->dev = &pdev->dev;
port->irq = platform_get_irq(pdev, 0);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
port->membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(port->membase))
return PTR_ERR(port->membase);
port->mapbase = res->start;
spin_lock_init(&port->lock);
ascport->clk = devm_clk_get(&pdev->dev, NULL);
if (WARN_ON(IS_ERR(ascport->clk)))
return -EINVAL;
clk_prepare_enable(ascport->clk);
ascport->port.uartclk = clk_get_rate(ascport->clk);
WARN_ON(ascport->port.uartclk == 0);
clk_disable_unprepare(ascport->clk);
ascport->pinctrl = devm_pinctrl_get(&pdev->dev);
if (IS_ERR(ascport->pinctrl)) {
ret = PTR_ERR(ascport->pinctrl);
dev_err(&pdev->dev, "Failed to get Pinctrl: %d\n", ret);
return ret;
}
ascport->states[DEFAULT] =
pinctrl_lookup_state(ascport->pinctrl, "default");
if (IS_ERR(ascport->states[DEFAULT])) {
ret = PTR_ERR(ascport->states[DEFAULT]);
dev_err(&pdev->dev,
"Failed to look up Pinctrl state 'default': %d\n", ret);
return ret;
}
ascport->states[NO_HW_FLOWCTRL] =
pinctrl_lookup_state(ascport->pinctrl, "no-hw-flowctrl");
if (IS_ERR(ascport->states[NO_HW_FLOWCTRL]))
ascport->states[NO_HW_FLOWCTRL] = NULL;
return 0;
}
static struct asc_port *asc_of_get_asc_port(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int id;
if (!np)
return NULL;
id = of_alias_get_id(np, ASC_SERIAL_NAME);
if (id < 0)
id = 0;
if (WARN_ON(id >= ASC_MAX_PORTS))
return NULL;
asc_ports[id].hw_flow_control = of_property_read_bool(np,
"uart-has-rtscts");
asc_ports[id].force_m1 = of_property_read_bool(np, "st,force_m1");
asc_ports[id].port.line = id;
asc_ports[id].rts = NULL;
return &asc_ports[id];
}
static int asc_serial_probe(struct platform_device *pdev)
{
int ret;
struct asc_port *ascport;
ascport = asc_of_get_asc_port(pdev);
if (!ascport)
return -ENODEV;
ret = asc_init_port(ascport, pdev);
if (ret)
return ret;
ret = uart_add_one_port(&asc_uart_driver, &ascport->port);
if (ret)
return ret;
platform_set_drvdata(pdev, &ascport->port);
return 0;
}
static int asc_serial_remove(struct platform_device *pdev)
{
struct uart_port *port = platform_get_drvdata(pdev);
return uart_remove_one_port(&asc_uart_driver, port);
}
static int asc_serial_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct uart_port *port = platform_get_drvdata(pdev);
return uart_suspend_port(&asc_uart_driver, port);
}
static int asc_serial_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct uart_port *port = platform_get_drvdata(pdev);
return uart_resume_port(&asc_uart_driver, port);
}
static void asc_console_putchar(struct uart_port *port, int ch)
{
unsigned int timeout = 1000000;
while (--timeout && !asc_txfifo_is_half_empty(port))
udelay(1);
asc_out(port, ASC_TXBUF, ch);
}
static void asc_console_write(struct console *co, const char *s, unsigned count)
{
struct uart_port *port = &asc_ports[co->index].port;
unsigned long flags;
unsigned long timeout = 1000000;
int locked = 1;
u32 intenable;
if (port->sysrq)
locked = 0;
else if (oops_in_progress)
locked = spin_trylock_irqsave(&port->lock, flags);
else
spin_lock_irqsave(&port->lock, flags);
intenable = asc_in(port, ASC_INTEN);
asc_out(port, ASC_INTEN, 0);
(void)asc_in(port, ASC_INTEN);
uart_console_write(port, s, count, asc_console_putchar);
while (--timeout && !asc_txfifo_is_empty(port))
udelay(1);
asc_out(port, ASC_INTEN, intenable);
if (locked)
spin_unlock_irqrestore(&port->lock, flags);
}
static int asc_console_setup(struct console *co, char *options)
{
struct asc_port *ascport;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index >= ASC_MAX_PORTS)
return -ENODEV;
ascport = &asc_ports[co->index];
if (ascport->port.mapbase == 0 || ascport->port.membase == NULL)
return -ENXIO;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(&ascport->port, co, baud, parity, bits, flow);
}
static int __init asc_init(void)
{
int ret;
static const char banner[] __initconst =
KERN_INFO "STMicroelectronics ASC driver initialized\n";
printk(banner);
ret = uart_register_driver(&asc_uart_driver);
if (ret)
return ret;
ret = platform_driver_register(&asc_serial_driver);
if (ret)
uart_unregister_driver(&asc_uart_driver);
return ret;
}
static void __exit asc_exit(void)
{
platform_driver_unregister(&asc_serial_driver);
uart_unregister_driver(&asc_uart_driver);
}
