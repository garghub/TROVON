static inline struct stm32_port *to_stm32_port(struct uart_port *port)
{
return container_of(port, struct stm32_port, port);
}
static void stm32_set_bits(struct uart_port *port, u32 reg, u32 bits)
{
u32 val;
val = readl_relaxed(port->membase + reg);
val |= bits;
writel_relaxed(val, port->membase + reg);
}
static void stm32_clr_bits(struct uart_port *port, u32 reg, u32 bits)
{
u32 val;
val = readl_relaxed(port->membase + reg);
val &= ~bits;
writel_relaxed(val, port->membase + reg);
}
static void stm32_receive_chars(struct uart_port *port)
{
struct tty_port *tport = &port->state->port;
unsigned long c;
u32 sr;
char flag;
if (port->irq_wake)
pm_wakeup_event(tport->tty->dev, 0);
while ((sr = readl_relaxed(port->membase + USART_SR)) & USART_SR_RXNE) {
sr |= USART_SR_DUMMY_RX;
c = readl_relaxed(port->membase + USART_DR);
flag = TTY_NORMAL;
port->icount.rx++;
if (sr & USART_SR_ERR_MASK) {
if (sr & USART_SR_LBD) {
port->icount.brk++;
if (uart_handle_break(port))
continue;
} else if (sr & USART_SR_ORE) {
port->icount.overrun++;
} else if (sr & USART_SR_PE) {
port->icount.parity++;
} else if (sr & USART_SR_FE) {
port->icount.frame++;
}
sr &= port->read_status_mask;
if (sr & USART_SR_LBD)
flag = TTY_BREAK;
else if (sr & USART_SR_PE)
flag = TTY_PARITY;
else if (sr & USART_SR_FE)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(port, c))
continue;
uart_insert_char(port, sr, USART_SR_ORE, c, flag);
}
spin_unlock(&port->lock);
tty_flip_buffer_push(tport);
spin_lock(&port->lock);
}
static void stm32_transmit_chars(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
if (port->x_char) {
writel_relaxed(port->x_char, port->membase + USART_DR);
port->x_char = 0;
port->icount.tx++;
return;
}
if (uart_tx_stopped(port)) {
stm32_stop_tx(port);
return;
}
if (uart_circ_empty(xmit)) {
stm32_stop_tx(port);
return;
}
writel_relaxed(xmit->buf[xmit->tail], port->membase + USART_DR);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit))
stm32_stop_tx(port);
}
static irqreturn_t stm32_interrupt(int irq, void *ptr)
{
struct uart_port *port = ptr;
u32 sr;
spin_lock(&port->lock);
sr = readl_relaxed(port->membase + USART_SR);
if (sr & USART_SR_RXNE)
stm32_receive_chars(port);
if (sr & USART_SR_TXE)
stm32_transmit_chars(port);
spin_unlock(&port->lock);
return IRQ_HANDLED;
}
static unsigned int stm32_tx_empty(struct uart_port *port)
{
return readl_relaxed(port->membase + USART_SR) & USART_SR_TXE;
}
static void stm32_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
if ((mctrl & TIOCM_RTS) && (port->status & UPSTAT_AUTORTS))
stm32_set_bits(port, USART_CR3, USART_CR3_RTSE);
else
stm32_clr_bits(port, USART_CR3, USART_CR3_RTSE);
}
static unsigned int stm32_get_mctrl(struct uart_port *port)
{
return TIOCM_CAR | TIOCM_DSR | TIOCM_CTS;
}
static void stm32_stop_tx(struct uart_port *port)
{
stm32_clr_bits(port, USART_CR1, USART_CR1_TXEIE);
}
static void stm32_start_tx(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
if (uart_circ_empty(xmit))
return;
stm32_set_bits(port, USART_CR1, USART_CR1_TXEIE | USART_CR1_TE);
}
static void stm32_throttle(struct uart_port *port)
{
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
stm32_clr_bits(port, USART_CR1, USART_CR1_RXNEIE);
spin_unlock_irqrestore(&port->lock, flags);
}
static void stm32_unthrottle(struct uart_port *port)
{
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
stm32_set_bits(port, USART_CR1, USART_CR1_RXNEIE);
spin_unlock_irqrestore(&port->lock, flags);
}
static void stm32_stop_rx(struct uart_port *port)
{
stm32_clr_bits(port, USART_CR1, USART_CR1_RXNEIE);
}
static void stm32_break_ctl(struct uart_port *port, int break_state)
{
}
static int stm32_startup(struct uart_port *port)
{
const char *name = to_platform_device(port->dev)->name;
u32 val;
int ret;
ret = request_irq(port->irq, stm32_interrupt, 0, name, port);
if (ret)
return ret;
val = USART_CR1_RXNEIE | USART_CR1_TE | USART_CR1_RE;
stm32_set_bits(port, USART_CR1, val);
return 0;
}
static void stm32_shutdown(struct uart_port *port)
{
u32 val;
val = USART_CR1_TXEIE | USART_CR1_RXNEIE | USART_CR1_TE | USART_CR1_RE;
stm32_set_bits(port, USART_CR1, val);
free_irq(port->irq, port);
}
static void stm32_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct stm32_port *stm32_port = to_stm32_port(port);
unsigned int baud;
u32 usartdiv, mantissa, fraction, oversampling;
tcflag_t cflag = termios->c_cflag;
u32 cr1, cr2, cr3;
unsigned long flags;
if (!stm32_port->hw_flow_control)
cflag &= ~CRTSCTS;
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk / 8);
spin_lock_irqsave(&port->lock, flags);
writel_relaxed(0, port->membase + USART_CR1);
cr1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_UE | USART_CR1_RXNEIE;
cr2 = 0;
cr3 = 0;
if (cflag & CSTOPB)
cr2 |= USART_CR2_STOP_2B;
if (cflag & PARENB) {
cr1 |= USART_CR1_PCE;
if ((cflag & CSIZE) == CS8)
cr1 |= USART_CR1_M;
}
if (cflag & PARODD)
cr1 |= USART_CR1_PS;
port->status &= ~(UPSTAT_AUTOCTS | UPSTAT_AUTORTS);
if (cflag & CRTSCTS) {
port->status |= UPSTAT_AUTOCTS | UPSTAT_AUTORTS;
cr3 |= USART_CR3_CTSE;
}
usartdiv = DIV_ROUND_CLOSEST(port->uartclk, baud);
if (usartdiv < 16) {
oversampling = 8;
stm32_set_bits(port, USART_CR1, USART_CR1_OVER8);
} else {
oversampling = 16;
stm32_clr_bits(port, USART_CR1, USART_CR1_OVER8);
}
mantissa = (usartdiv / oversampling) << USART_BRR_DIV_M_SHIFT;
fraction = usartdiv % oversampling;
writel_relaxed(mantissa | fraction, port->membase + USART_BRR);
uart_update_timeout(port, cflag, baud);
port->read_status_mask = USART_SR_ORE;
if (termios->c_iflag & INPCK)
port->read_status_mask |= USART_SR_PE | USART_SR_FE;
if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
port->read_status_mask |= USART_SR_LBD;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask = USART_SR_PE | USART_SR_FE;
if (termios->c_iflag & IGNBRK) {
port->ignore_status_mask |= USART_SR_LBD;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= USART_SR_ORE;
}
if ((termios->c_cflag & CREAD) == 0)
port->ignore_status_mask |= USART_SR_DUMMY_RX;
writel_relaxed(cr3, port->membase + USART_CR3);
writel_relaxed(cr2, port->membase + USART_CR2);
writel_relaxed(cr1, port->membase + USART_CR1);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *stm32_type(struct uart_port *port)
{
return (port->type == PORT_STM32) ? DRIVER_NAME : NULL;
}
static void stm32_release_port(struct uart_port *port)
{
}
static int stm32_request_port(struct uart_port *port)
{
return 0;
}
static void stm32_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_STM32;
}
static int
stm32_verify_port(struct uart_port *port, struct serial_struct *ser)
{
return -EINVAL;
}
static void stm32_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct stm32_port *stm32port = container_of(port,
struct stm32_port, port);
unsigned long flags = 0;
switch (state) {
case UART_PM_STATE_ON:
clk_prepare_enable(stm32port->clk);
break;
case UART_PM_STATE_OFF:
spin_lock_irqsave(&port->lock, flags);
stm32_clr_bits(port, USART_CR1, USART_CR1_UE);
spin_unlock_irqrestore(&port->lock, flags);
clk_disable_unprepare(stm32port->clk);
break;
}
}
static int stm32_init_port(struct stm32_port *stm32port,
struct platform_device *pdev)
{
struct uart_port *port = &stm32port->port;
struct resource *res;
int ret;
port->iotype = UPIO_MEM;
port->flags = UPF_BOOT_AUTOCONF;
port->ops = &stm32_uart_ops;
port->dev = &pdev->dev;
port->irq = platform_get_irq(pdev, 0);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
port->membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(port->membase))
return PTR_ERR(port->membase);
port->mapbase = res->start;
spin_lock_init(&port->lock);
stm32port->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(stm32port->clk))
return PTR_ERR(stm32port->clk);
ret = clk_prepare_enable(stm32port->clk);
if (ret)
return ret;
stm32port->port.uartclk = clk_get_rate(stm32port->clk);
if (!stm32port->port.uartclk)
ret = -EINVAL;
clk_disable_unprepare(stm32port->clk);
return ret;
}
static struct stm32_port *stm32_of_get_stm32_port(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int id;
if (!np)
return NULL;
id = of_alias_get_id(np, "serial");
if (id < 0)
id = 0;
if (WARN_ON(id >= STM32_MAX_PORTS))
return NULL;
stm32_ports[id].hw_flow_control = of_property_read_bool(np,
"auto-flow-control");
stm32_ports[id].port.line = id;
return &stm32_ports[id];
}
static int stm32_serial_probe(struct platform_device *pdev)
{
int ret;
struct stm32_port *stm32port;
stm32port = stm32_of_get_stm32_port(pdev);
if (!stm32port)
return -ENODEV;
ret = stm32_init_port(stm32port, pdev);
if (ret)
return ret;
ret = uart_add_one_port(&stm32_usart_driver, &stm32port->port);
if (ret)
return ret;
platform_set_drvdata(pdev, &stm32port->port);
return 0;
}
static int stm32_serial_remove(struct platform_device *pdev)
{
struct uart_port *port = platform_get_drvdata(pdev);
return uart_remove_one_port(&stm32_usart_driver, port);
}
static void stm32_console_putchar(struct uart_port *port, int ch)
{
while (!(readl_relaxed(port->membase + USART_SR) & USART_SR_TXE))
cpu_relax();
writel_relaxed(ch, port->membase + USART_DR);
}
static void stm32_console_write(struct console *co, const char *s, unsigned cnt)
{
struct uart_port *port = &stm32_ports[co->index].port;
unsigned long flags;
u32 old_cr1, new_cr1;
int locked = 1;
local_irq_save(flags);
if (port->sysrq)
locked = 0;
else if (oops_in_progress)
locked = spin_trylock(&port->lock);
else
spin_lock(&port->lock);
old_cr1 = readl_relaxed(port->membase + USART_CR1);
new_cr1 = old_cr1 & ~USART_CR1_IE_MASK;
writel_relaxed(new_cr1, port->membase + USART_CR1);
uart_console_write(port, s, cnt, stm32_console_putchar);
writel_relaxed(old_cr1, port->membase + USART_CR1);
if (locked)
spin_unlock(&port->lock);
local_irq_restore(flags);
}
static int stm32_console_setup(struct console *co, char *options)
{
struct stm32_port *stm32port;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index >= STM32_MAX_PORTS)
return -ENODEV;
stm32port = &stm32_ports[co->index];
if (stm32port->port.mapbase == 0 || stm32port->port.membase == NULL)
return -ENXIO;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(&stm32port->port, co, baud, parity, bits, flow);
}
static int __init usart_init(void)
{
static char banner[] __initdata = "STM32 USART driver initialized";
int ret;
pr_info("%s\n", banner);
ret = uart_register_driver(&stm32_usart_driver);
if (ret)
return ret;
ret = platform_driver_register(&stm32_serial_driver);
if (ret)
uart_unregister_driver(&stm32_usart_driver);
return ret;
}
static void __exit usart_exit(void)
{
platform_driver_unregister(&stm32_serial_driver);
uart_unregister_driver(&stm32_usart_driver);
}
