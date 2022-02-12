static inline void pic32_wait_deplete_txbuf(struct pic32_sport *sport)
{
while (!(pic32_uart_readl(sport, PIC32_UART_STA) & PIC32_UART_STA_TRMT))
udelay(1);
}
static inline int pic32_enable_clock(struct pic32_sport *sport)
{
int ret = clk_prepare_enable(sport->clk);
if (ret)
return ret;
sport->ref_clk++;
return 0;
}
static inline void pic32_disable_clock(struct pic32_sport *sport)
{
sport->ref_clk--;
clk_disable_unprepare(sport->clk);
}
static unsigned int pic32_uart_tx_empty(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
u32 val = pic32_uart_readl(sport, PIC32_UART_STA);
return (val & PIC32_UART_STA_TRMT) ? 1 : 0;
}
static void pic32_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct pic32_sport *sport = to_pic32_sport(port);
if (mctrl & TIOCM_LOOP)
pic32_uart_writel(sport, PIC32_SET(PIC32_UART_MODE),
PIC32_UART_MODE_LPBK);
else
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_LPBK);
}
static unsigned int get_cts_state(struct pic32_sport *sport)
{
if (gpio_is_valid(sport->cts_gpio))
return !gpio_get_value(sport->cts_gpio);
return 1;
}
static unsigned int pic32_uart_get_mctrl(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
unsigned int mctrl = 0;
if (!sport->hw_flow_ctrl)
mctrl |= TIOCM_CTS;
else if (get_cts_state(sport))
mctrl |= TIOCM_CTS;
mctrl |= TIOCM_CD;
mctrl |= TIOCM_DSR;
return mctrl;
}
static inline void pic32_uart_irqtxen(struct pic32_sport *sport, u8 en)
{
if (en && !tx_irq_enabled(sport)) {
enable_irq(sport->irq_tx);
tx_irq_enabled(sport) = 1;
} else if (!en && tx_irq_enabled(sport)) {
disable_irq_nosync(sport->irq_tx);
tx_irq_enabled(sport) = 0;
}
}
static void pic32_uart_stop_tx(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
if (!(pic32_uart_readl(sport, PIC32_UART_MODE) & PIC32_UART_MODE_ON))
return;
if (!(pic32_uart_readl(sport, PIC32_UART_STA) & PIC32_UART_STA_UTXEN))
return;
pic32_wait_deplete_txbuf(sport);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_STA),
PIC32_UART_STA_UTXEN);
pic32_uart_irqtxen(sport, 0);
}
static void pic32_uart_start_tx(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
pic32_uart_irqtxen(sport, 1);
pic32_uart_writel(sport, PIC32_SET(PIC32_UART_STA),
PIC32_UART_STA_UTXEN);
}
static void pic32_uart_stop_rx(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
disable_irq(sport->irq_rx);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_STA),
PIC32_UART_STA_URXEN);
}
static void pic32_uart_break_ctl(struct uart_port *port, int ctl)
{
struct pic32_sport *sport = to_pic32_sport(port);
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
if (ctl)
pic32_uart_writel(sport, PIC32_SET(PIC32_UART_STA),
PIC32_UART_STA_UTXBRK);
else
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_STA),
PIC32_UART_STA_UTXBRK);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *pic32_uart_type(struct uart_port *port)
{
return (port->type == PORT_PIC32) ? PIC32_DEV_NAME : NULL;
}
static void pic32_uart_do_rx(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
struct tty_port *tty;
unsigned int max_count;
max_count = PIC32_UART_RX_FIFO_DEPTH;
spin_lock(&port->lock);
tty = &port->state->port;
do {
u32 sta_reg, c;
char flag;
sta_reg = pic32_uart_readl(sport, PIC32_UART_STA);
if (unlikely(sta_reg & PIC32_UART_STA_OERR)) {
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_STA),
PIC32_UART_STA_OERR);
port->icount.overrun++;
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
}
if (!(sta_reg & PIC32_UART_STA_URXDA))
break;
c = pic32_uart_readl(sport, PIC32_UART_RX);
port->icount.rx++;
flag = TTY_NORMAL;
c &= 0xff;
if (unlikely((sta_reg & PIC32_UART_STA_PERR) ||
(sta_reg & PIC32_UART_STA_FERR))) {
if (sta_reg & PIC32_UART_STA_PERR)
port->icount.parity++;
if (sta_reg & PIC32_UART_STA_FERR)
port->icount.frame++;
sta_reg &= port->read_status_mask;
if (sta_reg & PIC32_UART_STA_FERR)
flag = TTY_FRAME;
if (sta_reg & PIC32_UART_STA_PERR)
flag = TTY_PARITY;
}
if (uart_handle_sysrq_char(port, c))
continue;
if ((sta_reg & port->ignore_status_mask) == 0)
tty_insert_flip_char(tty, c, flag);
} while (--max_count);
spin_unlock(&port->lock);
tty_flip_buffer_push(tty);
}
static void pic32_uart_do_tx(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
struct circ_buf *xmit = &port->state->xmit;
unsigned int max_count = PIC32_UART_TX_FIFO_DEPTH;
if (port->x_char) {
pic32_uart_writel(sport, PIC32_UART_TX, port->x_char);
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_tx_stopped(port)) {
pic32_uart_stop_tx(port);
return;
}
if (uart_circ_empty(xmit))
goto txq_empty;
while (!(PIC32_UART_STA_UTXBF &
pic32_uart_readl(sport, PIC32_UART_STA))) {
unsigned int c = xmit->buf[xmit->tail];
pic32_uart_writel(sport, PIC32_UART_TX, c);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_empty(xmit))
break;
if (--max_count == 0)
break;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit))
goto txq_empty;
return;
txq_empty:
pic32_uart_irqtxen(sport, 0);
}
static irqreturn_t pic32_uart_rx_interrupt(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
pic32_uart_do_rx(port);
return IRQ_HANDLED;
}
static irqreturn_t pic32_uart_tx_interrupt(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
pic32_uart_do_tx(port);
spin_unlock_irqrestore(&port->lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t pic32_uart_fault_interrupt(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static void pic32_uart_en_and_unmask(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
pic32_uart_writel(sport, PIC32_SET(PIC32_UART_STA),
PIC32_UART_STA_UTXEN | PIC32_UART_STA_URXEN);
pic32_uart_writel(sport, PIC32_SET(PIC32_UART_MODE),
PIC32_UART_MODE_ON);
}
static void pic32_uart_dsbl_and_mask(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
pic32_wait_deplete_txbuf(sport);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_STA),
PIC32_UART_STA_UTXEN | PIC32_UART_STA_URXEN);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_ON);
}
static int pic32_uart_startup(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
u32 dflt_baud = (port->uartclk / PIC32_UART_DFLT_BRATE / 16) - 1;
unsigned long flags;
int ret;
local_irq_save(flags);
ret = pic32_enable_clock(sport);
if (ret) {
local_irq_restore(flags);
goto out_done;
}
pic32_uart_writel(sport, PIC32_UART_MODE, 0);
pic32_uart_writel(sport, PIC32_UART_STA, 0);
pic32_uart_dsbl_and_mask(port);
pic32_uart_writel(sport, PIC32_UART_BRG, dflt_baud);
local_irq_restore(flags);
tx_irq_enabled(sport) = 0;
sport->irq_fault_name = kasprintf(GFP_KERNEL, "%s%d-fault",
pic32_uart_type(port),
sport->idx);
if (!sport->irq_fault_name) {
dev_err(port->dev, "%s: kasprintf err!", __func__);
ret = -ENOMEM;
goto out_done;
}
irq_set_status_flags(sport->irq_fault, IRQ_NOAUTOEN);
ret = request_irq(sport->irq_fault, pic32_uart_fault_interrupt,
sport->irqflags_fault, sport->irq_fault_name, port);
if (ret) {
dev_err(port->dev, "%s: request irq(%d) err! ret:%d name:%s\n",
__func__, sport->irq_fault, ret,
pic32_uart_type(port));
goto out_f;
}
sport->irq_rx_name = kasprintf(GFP_KERNEL, "%s%d-rx",
pic32_uart_type(port),
sport->idx);
if (!sport->irq_rx_name) {
dev_err(port->dev, "%s: kasprintf err!", __func__);
ret = -ENOMEM;
goto out_f;
}
irq_set_status_flags(sport->irq_rx, IRQ_NOAUTOEN);
ret = request_irq(sport->irq_rx, pic32_uart_rx_interrupt,
sport->irqflags_rx, sport->irq_rx_name, port);
if (ret) {
dev_err(port->dev, "%s: request irq(%d) err! ret:%d name:%s\n",
__func__, sport->irq_rx, ret,
pic32_uart_type(port));
goto out_r;
}
sport->irq_tx_name = kasprintf(GFP_KERNEL, "%s%d-tx",
pic32_uart_type(port),
sport->idx);
if (!sport->irq_tx_name) {
dev_err(port->dev, "%s: kasprintf err!", __func__);
ret = -ENOMEM;
goto out_r;
}
irq_set_status_flags(sport->irq_tx, IRQ_NOAUTOEN);
ret = request_irq(sport->irq_tx, pic32_uart_tx_interrupt,
sport->irqflags_tx, sport->irq_tx_name, port);
if (ret) {
dev_err(port->dev, "%s: request irq(%d) err! ret:%d name:%s\n",
__func__, sport->irq_tx, ret,
pic32_uart_type(port));
goto out_t;
}
local_irq_save(flags);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_STA),
PIC32_UART_STA_URXISEL1 | PIC32_UART_STA_URXISEL0);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_STA),
PIC32_UART_STA_UTXISEL1);
pic32_uart_en_and_unmask(port);
enable_irq(sport->irq_rx);
return 0;
out_t:
kfree(sport->irq_tx_name);
free_irq(sport->irq_tx, sport);
out_r:
kfree(sport->irq_rx_name);
free_irq(sport->irq_rx, sport);
out_f:
kfree(sport->irq_fault_name);
free_irq(sport->irq_fault, sport);
out_done:
return ret;
}
static void pic32_uart_shutdown(struct uart_port *port)
{
struct pic32_sport *sport = to_pic32_sport(port);
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
pic32_uart_dsbl_and_mask(port);
spin_unlock_irqrestore(&port->lock, flags);
pic32_disable_clock(sport);
free_irq(sport->irq_fault, port);
free_irq(sport->irq_tx, port);
free_irq(sport->irq_rx, port);
}
static void pic32_uart_set_termios(struct uart_port *port,
struct ktermios *new,
struct ktermios *old)
{
struct pic32_sport *sport = to_pic32_sport(port);
unsigned int baud;
unsigned int quot;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
pic32_uart_dsbl_and_mask(port);
if (new->c_cflag & CSTOPB)
pic32_uart_writel(sport, PIC32_SET(PIC32_UART_MODE),
PIC32_UART_MODE_STSEL);
else
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_STSEL);
if (new->c_cflag & PARENB) {
if (new->c_cflag & PARODD) {
pic32_uart_writel(sport, PIC32_SET(PIC32_UART_MODE),
PIC32_UART_MODE_PDSEL1);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_PDSEL0);
} else {
pic32_uart_writel(sport, PIC32_SET(PIC32_UART_MODE),
PIC32_UART_MODE_PDSEL0);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_PDSEL1);
}
} else {
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_PDSEL1 |
PIC32_UART_MODE_PDSEL0);
}
if ((new->c_cflag & CRTSCTS) && sport->hw_flow_ctrl) {
pic32_uart_writel(sport, PIC32_SET(PIC32_UART_MODE),
PIC32_UART_MODE_UEN1);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_UEN0);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_RTSMD);
} else {
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_UEN1);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_UEN0);
pic32_uart_writel(sport, PIC32_CLR(PIC32_UART_MODE),
PIC32_UART_MODE_RTSMD);
}
new->c_cflag |= CS8;
new->c_cflag &= ~CMSPAR;
baud = uart_get_baud_rate(port, new, old, 0, port->uartclk / 16);
quot = uart_get_divisor(port, baud) - 1;
pic32_uart_writel(sport, PIC32_UART_BRG, quot);
uart_update_timeout(port, new->c_cflag, baud);
if (tty_termios_baud_rate(new))
tty_termios_encode_baud_rate(new, baud, baud);
pic32_uart_en_and_unmask(port);
spin_unlock_irqrestore(&port->lock, flags);
}
static int pic32_uart_request_port(struct uart_port *port)
{
struct platform_device *pdev = to_platform_device(port->dev);
struct resource *res_mem;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!res_mem))
return -EINVAL;
if (!request_mem_region(port->mapbase, resource_size(res_mem),
"pic32_uart_mem"))
return -EBUSY;
port->membase = devm_ioremap_nocache(port->dev, port->mapbase,
resource_size(res_mem));
if (!port->membase) {
dev_err(port->dev, "Unable to map registers\n");
release_mem_region(port->mapbase, resource_size(res_mem));
return -ENOMEM;
}
return 0;
}
static void pic32_uart_release_port(struct uart_port *port)
{
struct platform_device *pdev = to_platform_device(port->dev);
struct resource *res_mem;
unsigned int res_size;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!res_mem))
return;
res_size = resource_size(res_mem);
release_mem_region(port->mapbase, res_size);
}
static void pic32_uart_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE) {
if (pic32_uart_request_port(port))
return;
port->type = PORT_PIC32;
}
}
static int pic32_uart_verify_port(struct uart_port *port,
struct serial_struct *serinfo)
{
if (port->type != PORT_PIC32)
return -EINVAL;
if (port->irq != serinfo->irq)
return -EINVAL;
if (port->iotype != serinfo->io_type)
return -EINVAL;
if (port->mapbase != (unsigned long)serinfo->iomem_base)
return -EINVAL;
return 0;
}
static void pic32_console_putchar(struct uart_port *port, int ch)
{
struct pic32_sport *sport = to_pic32_sport(port);
if (!(pic32_uart_readl(sport, PIC32_UART_MODE) & PIC32_UART_MODE_ON))
return;
if (!(pic32_uart_readl(sport, PIC32_UART_STA) & PIC32_UART_STA_UTXEN))
return;
pic32_wait_deplete_txbuf(sport);
pic32_uart_writel(sport, PIC32_UART_TX, ch & 0xff);
}
static void pic32_console_write(struct console *co, const char *s,
unsigned int count)
{
struct pic32_sport *sport = pic32_sports[co->index];
struct uart_port *port = pic32_get_port(sport);
uart_console_write(port, s, count, pic32_console_putchar);
}
static int pic32_console_setup(struct console *co, char *options)
{
struct pic32_sport *sport;
struct uart_port *port = NULL;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
int ret = 0;
if (unlikely(co->index < 0 || co->index >= PIC32_MAX_UARTS))
return -ENODEV;
sport = pic32_sports[co->index];
if (!sport)
return -ENODEV;
port = pic32_get_port(sport);
ret = pic32_enable_clock(sport);
if (ret)
return ret;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init pic32_console_init(void)
{
register_console(&pic32_console);
return 0;
}
static inline bool is_pic32_console_port(struct uart_port *port)
{
return port->cons && port->cons->index == port->line;
}
static int __init pic32_late_console_init(void)
{
if (!(pic32_console.flags & CON_ENABLED))
register_console(&pic32_console);
return 0;
}
static int pic32_uart_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct pic32_sport *sport;
int uart_idx = 0;
struct resource *res_mem;
struct uart_port *port;
int ret;
uart_idx = of_alias_get_id(np, "serial");
if (uart_idx < 0 || uart_idx >= PIC32_MAX_UARTS)
return -EINVAL;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res_mem)
return -EINVAL;
sport = devm_kzalloc(&pdev->dev, sizeof(*sport), GFP_KERNEL);
if (!sport)
return -ENOMEM;
sport->idx = uart_idx;
sport->irq_fault = irq_of_parse_and_map(np, 0);
sport->irqflags_fault = IRQF_NO_THREAD;
sport->irq_rx = irq_of_parse_and_map(np, 1);
sport->irqflags_rx = IRQF_NO_THREAD;
sport->irq_tx = irq_of_parse_and_map(np, 2);
sport->irqflags_tx = IRQF_NO_THREAD;
sport->clk = devm_clk_get(&pdev->dev, NULL);
sport->cts_gpio = -EINVAL;
sport->dev = &pdev->dev;
sport->hw_flow_ctrl = false;
sport->cts_gpio = of_get_named_gpio(np, "cts-gpios", 0);
if (gpio_is_valid(sport->cts_gpio)) {
sport->hw_flow_ctrl = true;
ret = devm_gpio_request(sport->dev,
sport->cts_gpio, "CTS");
if (ret) {
dev_err(&pdev->dev,
"error requesting CTS GPIO\n");
goto err;
}
ret = gpio_direction_input(sport->cts_gpio);
if (ret) {
dev_err(&pdev->dev, "error setting CTS GPIO\n");
goto err;
}
}
pic32_sports[uart_idx] = sport;
port = &sport->port;
memset(port, 0, sizeof(*port));
port->iotype = UPIO_MEM;
port->mapbase = res_mem->start;
port->ops = &pic32_uart_ops;
port->flags = UPF_BOOT_AUTOCONF;
port->dev = &pdev->dev;
port->fifosize = PIC32_UART_TX_FIFO_DEPTH;
port->uartclk = clk_get_rate(sport->clk);
port->line = uart_idx;
ret = uart_add_one_port(&pic32_uart_driver, port);
if (ret) {
port->membase = NULL;
dev_err(port->dev, "%s: uart add port error!\n", __func__);
goto err;
}
#ifdef CONFIG_SERIAL_PIC32_CONSOLE
if (is_pic32_console_port(port) &&
(pic32_console.flags & CON_ENABLED)) {
pic32_disable_clock(sport);
}
#endif
platform_set_drvdata(pdev, port);
dev_info(&pdev->dev, "%s: uart(%d) driver initialized.\n",
__func__, uart_idx);
return 0;
err:
return ret;
}
static int pic32_uart_remove(struct platform_device *pdev)
{
struct uart_port *port = platform_get_drvdata(pdev);
struct pic32_sport *sport = to_pic32_sport(port);
uart_remove_one_port(&pic32_uart_driver, port);
pic32_disable_clock(sport);
platform_set_drvdata(pdev, NULL);
pic32_sports[sport->idx] = NULL;
return 0;
}
static int __init pic32_uart_init(void)
{
int ret;
ret = uart_register_driver(&pic32_uart_driver);
if (ret) {
pr_err("failed to register %s:%d\n",
pic32_uart_driver.driver_name, ret);
return ret;
}
ret = platform_driver_register(&pic32_uart_platform_driver);
if (ret) {
pr_err("fail to register pic32 uart\n");
uart_unregister_driver(&pic32_uart_driver);
}
return ret;
}
static void __exit pic32_uart_exit(void)
{
#ifdef CONFIG_SERIAL_PIC32_CONSOLE
unregister_console(&pic32_console);
#endif
platform_driver_unregister(&pic32_uart_platform_driver);
uart_unregister_driver(&pic32_uart_driver);
}
