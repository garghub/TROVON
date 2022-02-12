static u8 sc16is7xx_port_read(struct uart_port *port, u8 reg)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
unsigned int val = 0;
regmap_read(s->regmap,
(reg << SC16IS7XX_REG_SHIFT) | port->line, &val);
return val;
}
static void sc16is7xx_port_write(struct uart_port *port, u8 reg, u8 val)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
regmap_write(s->regmap,
(reg << SC16IS7XX_REG_SHIFT) | port->line, val);
}
static void sc16is7xx_fifo_read(struct uart_port *port, unsigned int rxlen)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
u8 addr = (SC16IS7XX_RHR_REG << SC16IS7XX_REG_SHIFT) | port->line;
regcache_cache_bypass(s->regmap, true);
regmap_raw_read(s->regmap, addr, s->buf, rxlen);
regcache_cache_bypass(s->regmap, false);
}
static void sc16is7xx_fifo_write(struct uart_port *port, u8 to_send)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
u8 addr = (SC16IS7XX_THR_REG << SC16IS7XX_REG_SHIFT) | port->line;
regcache_cache_bypass(s->regmap, true);
regmap_raw_write(s->regmap, addr, s->buf, to_send);
regcache_cache_bypass(s->regmap, false);
}
static void sc16is7xx_port_update(struct uart_port *port, u8 reg,
u8 mask, u8 val)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
regmap_update_bits(s->regmap,
(reg << SC16IS7XX_REG_SHIFT) | port->line,
mask, val);
}
static void sc16is7xx_power(struct uart_port *port, int on)
{
sc16is7xx_port_update(port, SC16IS7XX_IER_REG,
SC16IS7XX_IER_SLEEP_BIT,
on ? 0 : SC16IS7XX_IER_SLEEP_BIT);
}
static bool sc16is7xx_regmap_volatile(struct device *dev, unsigned int reg)
{
switch (reg >> SC16IS7XX_REG_SHIFT) {
case SC16IS7XX_RHR_REG:
case SC16IS7XX_IIR_REG:
case SC16IS7XX_LSR_REG:
case SC16IS7XX_MSR_REG:
case SC16IS7XX_TXLVL_REG:
case SC16IS7XX_RXLVL_REG:
case SC16IS7XX_IOSTATE_REG:
return true;
default:
break;
}
return false;
}
static bool sc16is7xx_regmap_precious(struct device *dev, unsigned int reg)
{
switch (reg >> SC16IS7XX_REG_SHIFT) {
case SC16IS7XX_RHR_REG:
return true;
default:
break;
}
return false;
}
static int sc16is7xx_set_baud(struct uart_port *port, int baud)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
u8 lcr;
u8 prescaler = 0;
unsigned long clk = port->uartclk, div = clk / 16 / baud;
if (div > 0xffff) {
prescaler = SC16IS7XX_MCR_CLKSEL_BIT;
div /= 4;
}
lcr = sc16is7xx_port_read(port, SC16IS7XX_LCR_REG);
sc16is7xx_port_write(port, SC16IS7XX_LCR_REG,
SC16IS7XX_LCR_CONF_MODE_B);
regcache_cache_bypass(s->regmap, true);
sc16is7xx_port_write(port, SC16IS7XX_EFR_REG,
SC16IS7XX_EFR_ENABLE_BIT);
regcache_cache_bypass(s->regmap, false);
sc16is7xx_port_write(port, SC16IS7XX_LCR_REG, lcr);
sc16is7xx_port_update(port, SC16IS7XX_MCR_REG,
SC16IS7XX_MCR_CLKSEL_BIT,
prescaler);
sc16is7xx_port_write(port, SC16IS7XX_LCR_REG,
SC16IS7XX_LCR_CONF_MODE_A);
regcache_cache_bypass(s->regmap, true);
sc16is7xx_port_write(port, SC16IS7XX_DLH_REG, div / 256);
sc16is7xx_port_write(port, SC16IS7XX_DLL_REG, div % 256);
regcache_cache_bypass(s->regmap, false);
sc16is7xx_port_write(port, SC16IS7XX_LCR_REG, lcr);
return DIV_ROUND_CLOSEST(clk / 16, div);
}
static void sc16is7xx_handle_rx(struct uart_port *port, unsigned int rxlen,
unsigned int iir)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
unsigned int lsr = 0, ch, flag, bytes_read, i;
bool read_lsr = (iir == SC16IS7XX_IIR_RLSE_SRC) ? true : false;
if (unlikely(rxlen >= sizeof(s->buf))) {
dev_warn_ratelimited(port->dev,
"Port %i: Possible RX FIFO overrun: %d\n",
port->line, rxlen);
port->icount.buf_overrun++;
rxlen = sizeof(s->buf);
}
while (rxlen) {
if (read_lsr) {
lsr = sc16is7xx_port_read(port, SC16IS7XX_LSR_REG);
if (!(lsr & SC16IS7XX_LSR_FIFOE_BIT))
read_lsr = false;
} else
lsr = 0;
if (read_lsr) {
s->buf[0] = sc16is7xx_port_read(port, SC16IS7XX_RHR_REG);
bytes_read = 1;
} else {
sc16is7xx_fifo_read(port, rxlen);
bytes_read = rxlen;
}
lsr &= SC16IS7XX_LSR_BRK_ERROR_MASK;
port->icount.rx++;
flag = TTY_NORMAL;
if (unlikely(lsr)) {
if (lsr & SC16IS7XX_LSR_BI_BIT) {
port->icount.brk++;
if (uart_handle_break(port))
continue;
} else if (lsr & SC16IS7XX_LSR_PE_BIT)
port->icount.parity++;
else if (lsr & SC16IS7XX_LSR_FE_BIT)
port->icount.frame++;
else if (lsr & SC16IS7XX_LSR_OE_BIT)
port->icount.overrun++;
lsr &= port->read_status_mask;
if (lsr & SC16IS7XX_LSR_BI_BIT)
flag = TTY_BREAK;
else if (lsr & SC16IS7XX_LSR_PE_BIT)
flag = TTY_PARITY;
else if (lsr & SC16IS7XX_LSR_FE_BIT)
flag = TTY_FRAME;
else if (lsr & SC16IS7XX_LSR_OE_BIT)
flag = TTY_OVERRUN;
}
for (i = 0; i < bytes_read; ++i) {
ch = s->buf[i];
if (uart_handle_sysrq_char(port, ch))
continue;
if (lsr & port->ignore_status_mask)
continue;
uart_insert_char(port, lsr, SC16IS7XX_LSR_OE_BIT, ch,
flag);
}
rxlen -= bytes_read;
}
tty_flip_buffer_push(&port->state->port);
}
static void sc16is7xx_handle_tx(struct uart_port *port)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
struct circ_buf *xmit = &port->state->xmit;
unsigned int txlen, to_send, i;
if (unlikely(port->x_char)) {
sc16is7xx_port_write(port, SC16IS7XX_THR_REG, port->x_char);
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port))
return;
to_send = uart_circ_chars_pending(xmit);
if (likely(to_send)) {
txlen = sc16is7xx_port_read(port, SC16IS7XX_TXLVL_REG);
to_send = (to_send > txlen) ? txlen : to_send;
port->icount.tx += to_send;
for (i = 0; i < to_send; ++i) {
s->buf[i] = xmit->buf[xmit->tail];
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
}
sc16is7xx_fifo_write(port, to_send);
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
static void sc16is7xx_port_irq(struct sc16is7xx_port *s, int portno)
{
struct uart_port *port = &s->p[portno].port;
do {
unsigned int iir, msr, rxlen;
iir = sc16is7xx_port_read(port, SC16IS7XX_IIR_REG);
if (iir & SC16IS7XX_IIR_NO_INT_BIT)
break;
iir &= SC16IS7XX_IIR_ID_MASK;
switch (iir) {
case SC16IS7XX_IIR_RDI_SRC:
case SC16IS7XX_IIR_RLSE_SRC:
case SC16IS7XX_IIR_RTOI_SRC:
case SC16IS7XX_IIR_XOFFI_SRC:
rxlen = sc16is7xx_port_read(port, SC16IS7XX_RXLVL_REG);
if (rxlen)
sc16is7xx_handle_rx(port, rxlen, iir);
break;
case SC16IS7XX_IIR_CTSRTS_SRC:
msr = sc16is7xx_port_read(port, SC16IS7XX_MSR_REG);
uart_handle_cts_change(port,
!!(msr & SC16IS7XX_MSR_CTS_BIT));
break;
case SC16IS7XX_IIR_THRI_SRC:
sc16is7xx_handle_tx(port);
break;
default:
dev_err_ratelimited(port->dev,
"Port %i: Unexpected interrupt: %x",
port->line, iir);
break;
}
} while (1);
}
static void sc16is7xx_ist(struct kthread_work *ws)
{
struct sc16is7xx_port *s = to_sc16is7xx_port(ws, irq_work);
int i;
for (i = 0; i < s->uart.nr; ++i)
sc16is7xx_port_irq(s, i);
}
static irqreturn_t sc16is7xx_irq(int irq, void *dev_id)
{
struct sc16is7xx_port *s = (struct sc16is7xx_port *)dev_id;
queue_kthread_work(&s->kworker, &s->irq_work);
return IRQ_HANDLED;
}
static void sc16is7xx_tx_proc(struct kthread_work *ws)
{
struct uart_port *port = &(to_sc16is7xx_one(ws, tx_work)->port);
if ((port->rs485.flags & SER_RS485_ENABLED) &&
(port->rs485.delay_rts_before_send > 0))
msleep(port->rs485.delay_rts_before_send);
sc16is7xx_handle_tx(port);
}
static void sc16is7xx_reconf_rs485(struct uart_port *port)
{
const u32 mask = SC16IS7XX_EFCR_AUTO_RS485_BIT |
SC16IS7XX_EFCR_RTS_INVERT_BIT;
u32 efcr = 0;
struct serial_rs485 *rs485 = &port->rs485;
unsigned long irqflags;
spin_lock_irqsave(&port->lock, irqflags);
if (rs485->flags & SER_RS485_ENABLED) {
efcr |= SC16IS7XX_EFCR_AUTO_RS485_BIT;
if (rs485->flags & SER_RS485_RTS_AFTER_SEND)
efcr |= SC16IS7XX_EFCR_RTS_INVERT_BIT;
}
spin_unlock_irqrestore(&port->lock, irqflags);
sc16is7xx_port_update(port, SC16IS7XX_EFCR_REG, mask, efcr);
}
static void sc16is7xx_reg_proc(struct kthread_work *ws)
{
struct sc16is7xx_one *one = to_sc16is7xx_one(ws, reg_work);
struct sc16is7xx_one_config config;
unsigned long irqflags;
spin_lock_irqsave(&one->port.lock, irqflags);
config = one->config;
memset(&one->config, 0, sizeof(one->config));
spin_unlock_irqrestore(&one->port.lock, irqflags);
if (config.flags & SC16IS7XX_RECONF_MD)
sc16is7xx_port_update(&one->port, SC16IS7XX_MCR_REG,
SC16IS7XX_MCR_LOOP_BIT,
(one->port.mctrl & TIOCM_LOOP) ?
SC16IS7XX_MCR_LOOP_BIT : 0);
if (config.flags & SC16IS7XX_RECONF_IER)
sc16is7xx_port_update(&one->port, SC16IS7XX_IER_REG,
config.ier_clear, 0);
if (config.flags & SC16IS7XX_RECONF_RS485)
sc16is7xx_reconf_rs485(&one->port);
}
static void sc16is7xx_ier_clear(struct uart_port *port, u8 bit)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
struct sc16is7xx_one *one = to_sc16is7xx_one(port, port);
one->config.flags |= SC16IS7XX_RECONF_IER;
one->config.ier_clear |= bit;
queue_kthread_work(&s->kworker, &one->reg_work);
}
static void sc16is7xx_stop_tx(struct uart_port *port)
{
sc16is7xx_ier_clear(port, SC16IS7XX_IER_THRI_BIT);
}
static void sc16is7xx_stop_rx(struct uart_port *port)
{
sc16is7xx_ier_clear(port, SC16IS7XX_IER_RDI_BIT);
}
static void sc16is7xx_start_tx(struct uart_port *port)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
struct sc16is7xx_one *one = to_sc16is7xx_one(port, port);
queue_kthread_work(&s->kworker, &one->tx_work);
}
static unsigned int sc16is7xx_tx_empty(struct uart_port *port)
{
unsigned int lsr;
lsr = sc16is7xx_port_read(port, SC16IS7XX_LSR_REG);
return (lsr & SC16IS7XX_LSR_TEMT_BIT) ? TIOCSER_TEMT : 0;
}
static unsigned int sc16is7xx_get_mctrl(struct uart_port *port)
{
return TIOCM_DSR | TIOCM_CAR;
}
static void sc16is7xx_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
struct sc16is7xx_one *one = to_sc16is7xx_one(port, port);
one->config.flags |= SC16IS7XX_RECONF_MD;
queue_kthread_work(&s->kworker, &one->reg_work);
}
static void sc16is7xx_break_ctl(struct uart_port *port, int break_state)
{
sc16is7xx_port_update(port, SC16IS7XX_LCR_REG,
SC16IS7XX_LCR_TXBREAK_BIT,
break_state ? SC16IS7XX_LCR_TXBREAK_BIT : 0);
}
static void sc16is7xx_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
unsigned int lcr, flow = 0;
int baud;
termios->c_cflag &= ~CMSPAR;
switch (termios->c_cflag & CSIZE) {
case CS5:
lcr = SC16IS7XX_LCR_WORD_LEN_5;
break;
case CS6:
lcr = SC16IS7XX_LCR_WORD_LEN_6;
break;
case CS7:
lcr = SC16IS7XX_LCR_WORD_LEN_7;
break;
case CS8:
lcr = SC16IS7XX_LCR_WORD_LEN_8;
break;
default:
lcr = SC16IS7XX_LCR_WORD_LEN_8;
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= CS8;
break;
}
if (termios->c_cflag & PARENB) {
lcr |= SC16IS7XX_LCR_PARITY_BIT;
if (!(termios->c_cflag & PARODD))
lcr |= SC16IS7XX_LCR_EVENPARITY_BIT;
}
if (termios->c_cflag & CSTOPB)
lcr |= SC16IS7XX_LCR_STOPLEN_BIT;
port->read_status_mask = SC16IS7XX_LSR_OE_BIT;
if (termios->c_iflag & INPCK)
port->read_status_mask |= SC16IS7XX_LSR_PE_BIT |
SC16IS7XX_LSR_FE_BIT;
if (termios->c_iflag & (BRKINT | PARMRK))
port->read_status_mask |= SC16IS7XX_LSR_BI_BIT;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNBRK)
port->ignore_status_mask |= SC16IS7XX_LSR_BI_BIT;
if (!(termios->c_cflag & CREAD))
port->ignore_status_mask |= SC16IS7XX_LSR_BRK_ERROR_MASK;
sc16is7xx_port_write(port, SC16IS7XX_LCR_REG,
SC16IS7XX_LCR_CONF_MODE_B);
regcache_cache_bypass(s->regmap, true);
sc16is7xx_port_write(port, SC16IS7XX_XON1_REG, termios->c_cc[VSTART]);
sc16is7xx_port_write(port, SC16IS7XX_XOFF1_REG, termios->c_cc[VSTOP]);
if (termios->c_cflag & CRTSCTS)
flow |= SC16IS7XX_EFR_AUTOCTS_BIT |
SC16IS7XX_EFR_AUTORTS_BIT;
if (termios->c_iflag & IXON)
flow |= SC16IS7XX_EFR_SWFLOW3_BIT;
if (termios->c_iflag & IXOFF)
flow |= SC16IS7XX_EFR_SWFLOW1_BIT;
sc16is7xx_port_write(port, SC16IS7XX_EFR_REG, flow);
regcache_cache_bypass(s->regmap, false);
sc16is7xx_port_write(port, SC16IS7XX_LCR_REG, lcr);
baud = uart_get_baud_rate(port, termios, old,
port->uartclk / 16 / 4 / 0xffff,
port->uartclk / 16);
baud = sc16is7xx_set_baud(port, baud);
uart_update_timeout(port, termios->c_cflag, baud);
}
static int sc16is7xx_config_rs485(struct uart_port *port,
struct serial_rs485 *rs485)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
struct sc16is7xx_one *one = to_sc16is7xx_one(port, port);
if (rs485->flags & SER_RS485_ENABLED) {
bool rts_during_rx, rts_during_tx;
rts_during_rx = rs485->flags & SER_RS485_RTS_AFTER_SEND;
rts_during_tx = rs485->flags & SER_RS485_RTS_ON_SEND;
if (rts_during_rx == rts_during_tx)
dev_err(port->dev,
"unsupported RTS signalling on_send:%d after_send:%d - exactly one of RS485 RTS flags should be set\n",
rts_during_tx, rts_during_rx);
if (rs485->delay_rts_after_send)
return -EINVAL;
}
port->rs485 = *rs485;
one->config.flags |= SC16IS7XX_RECONF_RS485;
queue_kthread_work(&s->kworker, &one->reg_work);
return 0;
}
static int sc16is7xx_startup(struct uart_port *port)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
unsigned int val;
sc16is7xx_power(port, 1);
val = SC16IS7XX_FCR_RXRESET_BIT | SC16IS7XX_FCR_TXRESET_BIT;
sc16is7xx_port_write(port, SC16IS7XX_FCR_REG, val);
udelay(5);
sc16is7xx_port_write(port, SC16IS7XX_FCR_REG,
SC16IS7XX_FCR_FIFO_BIT);
sc16is7xx_port_write(port, SC16IS7XX_LCR_REG,
SC16IS7XX_LCR_CONF_MODE_B);
regcache_cache_bypass(s->regmap, true);
sc16is7xx_port_write(port, SC16IS7XX_EFR_REG,
SC16IS7XX_EFR_ENABLE_BIT);
sc16is7xx_port_update(port, SC16IS7XX_MCR_REG,
SC16IS7XX_MCR_TCRTLR_BIT,
SC16IS7XX_MCR_TCRTLR_BIT);
sc16is7xx_port_write(port, SC16IS7XX_TCR_REG,
SC16IS7XX_TCR_RX_RESUME(24) |
SC16IS7XX_TCR_RX_HALT(48));
regcache_cache_bypass(s->regmap, false);
sc16is7xx_port_write(port, SC16IS7XX_LCR_REG, SC16IS7XX_LCR_WORD_LEN_8);
sc16is7xx_port_update(port, SC16IS7XX_EFCR_REG,
SC16IS7XX_EFCR_RXDISABLE_BIT |
SC16IS7XX_EFCR_TXDISABLE_BIT,
0);
val = SC16IS7XX_IER_RDI_BIT | SC16IS7XX_IER_THRI_BIT |
SC16IS7XX_IER_CTSI_BIT;
sc16is7xx_port_write(port, SC16IS7XX_IER_REG, val);
return 0;
}
static void sc16is7xx_shutdown(struct uart_port *port)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
sc16is7xx_port_write(port, SC16IS7XX_IER_REG, 0);
sc16is7xx_port_update(port, SC16IS7XX_EFCR_REG,
SC16IS7XX_EFCR_RXDISABLE_BIT |
SC16IS7XX_EFCR_TXDISABLE_BIT,
SC16IS7XX_EFCR_RXDISABLE_BIT |
SC16IS7XX_EFCR_TXDISABLE_BIT);
sc16is7xx_power(port, 0);
flush_kthread_worker(&s->kworker);
}
static const char *sc16is7xx_type(struct uart_port *port)
{
struct sc16is7xx_port *s = dev_get_drvdata(port->dev);
return (port->type == PORT_SC16IS7XX) ? s->devtype->name : NULL;
}
static int sc16is7xx_request_port(struct uart_port *port)
{
return 0;
}
static void sc16is7xx_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_SC16IS7XX;
}
static int sc16is7xx_verify_port(struct uart_port *port,
struct serial_struct *s)
{
if ((s->type != PORT_UNKNOWN) && (s->type != PORT_SC16IS7XX))
return -EINVAL;
if (s->irq != port->irq)
return -EINVAL;
return 0;
}
static void sc16is7xx_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
sc16is7xx_power(port, (state == UART_PM_STATE_ON) ? 1 : 0);
}
static void sc16is7xx_null_void(struct uart_port *port)
{
}
static int sc16is7xx_gpio_get(struct gpio_chip *chip, unsigned offset)
{
unsigned int val;
struct sc16is7xx_port *s = container_of(chip, struct sc16is7xx_port,
gpio);
struct uart_port *port = &s->p[0].port;
val = sc16is7xx_port_read(port, SC16IS7XX_IOSTATE_REG);
return !!(val & BIT(offset));
}
static void sc16is7xx_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
struct sc16is7xx_port *s = container_of(chip, struct sc16is7xx_port,
gpio);
struct uart_port *port = &s->p[0].port;
sc16is7xx_port_update(port, SC16IS7XX_IOSTATE_REG, BIT(offset),
val ? BIT(offset) : 0);
}
static int sc16is7xx_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
struct sc16is7xx_port *s = container_of(chip, struct sc16is7xx_port,
gpio);
struct uart_port *port = &s->p[0].port;
sc16is7xx_port_update(port, SC16IS7XX_IODIR_REG, BIT(offset), 0);
return 0;
}
static int sc16is7xx_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int val)
{
struct sc16is7xx_port *s = container_of(chip, struct sc16is7xx_port,
gpio);
struct uart_port *port = &s->p[0].port;
sc16is7xx_port_update(port, SC16IS7XX_IOSTATE_REG, BIT(offset),
val ? BIT(offset) : 0);
sc16is7xx_port_update(port, SC16IS7XX_IODIR_REG, BIT(offset),
BIT(offset));
return 0;
}
static int sc16is7xx_probe(struct device *dev,
struct sc16is7xx_devtype *devtype,
struct regmap *regmap, int irq, unsigned long flags)
{
struct sched_param sched_param = { .sched_priority = MAX_RT_PRIO / 2 };
unsigned long freq, *pfreq = dev_get_platdata(dev);
int i, ret;
struct sc16is7xx_port *s;
if (IS_ERR(regmap))
return PTR_ERR(regmap);
s = devm_kzalloc(dev, sizeof(*s) +
sizeof(struct sc16is7xx_one) * devtype->nr_uart,
GFP_KERNEL);
if (!s) {
dev_err(dev, "Error allocating port structure\n");
return -ENOMEM;
}
s->clk = devm_clk_get(dev, NULL);
if (IS_ERR(s->clk)) {
if (pfreq)
freq = *pfreq;
else
return PTR_ERR(s->clk);
} else {
clk_prepare_enable(s->clk);
freq = clk_get_rate(s->clk);
}
s->regmap = regmap;
s->devtype = devtype;
dev_set_drvdata(dev, s);
s->uart.owner = THIS_MODULE;
s->uart.dev_name = "ttySC";
s->uart.nr = devtype->nr_uart;
ret = uart_register_driver(&s->uart);
if (ret) {
dev_err(dev, "Registering UART driver failed\n");
goto out_clk;
}
init_kthread_worker(&s->kworker);
init_kthread_work(&s->irq_work, sc16is7xx_ist);
s->kworker_task = kthread_run(kthread_worker_fn, &s->kworker,
"sc16is7xx");
if (IS_ERR(s->kworker_task)) {
ret = PTR_ERR(s->kworker_task);
goto out_uart;
}
sched_setscheduler(s->kworker_task, SCHED_FIFO, &sched_param);
#ifdef CONFIG_GPIOLIB
if (devtype->nr_gpio) {
s->gpio.owner = THIS_MODULE;
s->gpio.dev = dev;
s->gpio.label = dev_name(dev);
s->gpio.direction_input = sc16is7xx_gpio_direction_input;
s->gpio.get = sc16is7xx_gpio_get;
s->gpio.direction_output = sc16is7xx_gpio_direction_output;
s->gpio.set = sc16is7xx_gpio_set;
s->gpio.base = -1;
s->gpio.ngpio = devtype->nr_gpio;
s->gpio.can_sleep = 1;
ret = gpiochip_add(&s->gpio);
if (ret)
goto out_thread;
}
#endif
for (i = 0; i < devtype->nr_uart; ++i) {
s->p[i].port.line = i;
s->p[i].port.dev = dev;
s->p[i].port.irq = irq;
s->p[i].port.type = PORT_SC16IS7XX;
s->p[i].port.fifosize = SC16IS7XX_FIFO_SIZE;
s->p[i].port.flags = UPF_FIXED_TYPE | UPF_LOW_LATENCY;
s->p[i].port.iotype = UPIO_PORT;
s->p[i].port.uartclk = freq;
s->p[i].port.rs485_config = sc16is7xx_config_rs485;
s->p[i].port.ops = &sc16is7xx_ops;
sc16is7xx_port_write(&s->p[i].port, SC16IS7XX_IER_REG, 0);
sc16is7xx_port_write(&s->p[i].port, SC16IS7XX_EFCR_REG,
SC16IS7XX_EFCR_RXDISABLE_BIT |
SC16IS7XX_EFCR_TXDISABLE_BIT);
init_kthread_work(&s->p[i].tx_work, sc16is7xx_tx_proc);
init_kthread_work(&s->p[i].reg_work, sc16is7xx_reg_proc);
uart_add_one_port(&s->uart, &s->p[i].port);
sc16is7xx_power(&s->p[i].port, 0);
}
ret = devm_request_irq(dev, irq, sc16is7xx_irq,
IRQF_ONESHOT | flags, dev_name(dev), s);
if (!ret)
return 0;
for (i = 0; i < s->uart.nr; i++)
uart_remove_one_port(&s->uart, &s->p[i].port);
#ifdef CONFIG_GPIOLIB
if (devtype->nr_gpio)
gpiochip_remove(&s->gpio);
out_thread:
#endif
kthread_stop(s->kworker_task);
out_uart:
uart_unregister_driver(&s->uart);
out_clk:
if (!IS_ERR(s->clk))
clk_disable_unprepare(s->clk);
return ret;
}
static int sc16is7xx_remove(struct device *dev)
{
struct sc16is7xx_port *s = dev_get_drvdata(dev);
int i;
#ifdef CONFIG_GPIOLIB
if (s->devtype->nr_gpio)
gpiochip_remove(&s->gpio);
#endif
for (i = 0; i < s->uart.nr; i++) {
uart_remove_one_port(&s->uart, &s->p[i].port);
sc16is7xx_power(&s->p[i].port, 0);
}
flush_kthread_worker(&s->kworker);
kthread_stop(s->kworker_task);
uart_unregister_driver(&s->uart);
if (!IS_ERR(s->clk))
clk_disable_unprepare(s->clk);
return 0;
}
static int sc16is7xx_spi_probe(struct spi_device *spi)
{
struct sc16is7xx_devtype *devtype;
unsigned long flags = 0;
struct regmap *regmap;
int ret;
spi->bits_per_word = 8;
spi->mode = spi->mode ? : SPI_MODE_0;
spi->max_speed_hz = spi->max_speed_hz ? : 15000000;
ret = spi_setup(spi);
if (ret)
return ret;
if (spi->dev.of_node) {
const struct of_device_id *of_id =
of_match_device(sc16is7xx_dt_ids, &spi->dev);
devtype = (struct sc16is7xx_devtype *)of_id->data;
} else {
const struct spi_device_id *id_entry = spi_get_device_id(spi);
devtype = (struct sc16is7xx_devtype *)id_entry->driver_data;
flags = IRQF_TRIGGER_FALLING;
}
regcfg.max_register = (0xf << SC16IS7XX_REG_SHIFT) |
(devtype->nr_uart - 1);
regmap = devm_regmap_init_spi(spi, &regcfg);
return sc16is7xx_probe(&spi->dev, devtype, regmap, spi->irq, flags);
}
static int sc16is7xx_spi_remove(struct spi_device *spi)
{
return sc16is7xx_remove(&spi->dev);
}
static int sc16is7xx_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct sc16is7xx_devtype *devtype;
unsigned long flags = 0;
struct regmap *regmap;
if (i2c->dev.of_node) {
const struct of_device_id *of_id =
of_match_device(sc16is7xx_dt_ids, &i2c->dev);
devtype = (struct sc16is7xx_devtype *)of_id->data;
} else {
devtype = (struct sc16is7xx_devtype *)id->driver_data;
flags = IRQF_TRIGGER_FALLING;
}
regcfg.max_register = (0xf << SC16IS7XX_REG_SHIFT) |
(devtype->nr_uart - 1);
regmap = devm_regmap_init_i2c(i2c, &regcfg);
return sc16is7xx_probe(&i2c->dev, devtype, regmap, i2c->irq, flags);
}
static int sc16is7xx_i2c_remove(struct i2c_client *client)
{
return sc16is7xx_remove(&client->dev);
}
static int __init sc16is7xx_init(void)
{
int ret = 0;
#ifdef CONFIG_SERIAL_SC16IS7XX_I2C
ret = i2c_add_driver(&sc16is7xx_i2c_uart_driver);
if (ret < 0) {
pr_err("failed to init sc16is7xx i2c --> %d\n", ret);
return ret;
}
#endif
#ifdef CONFIG_SERIAL_SC16IS7XX_SPI
ret = spi_register_driver(&sc16is7xx_spi_uart_driver);
if (ret < 0) {
pr_err("failed to init sc16is7xx spi --> %d\n", ret);
return ret;
}
#endif
return ret;
}
static void __exit sc16is7xx_exit(void)
{
#ifdef CONFIG_SERIAL_SC16IS7XX_I2C
i2c_del_driver(&sc16is7xx_i2c_uart_driver);
#endif
#ifdef CONFIG_SERIAL_SC16IS7XX_SPI
spi_unregister_driver(&sc16is7xx_spi_uart_driver);
#endif
}
