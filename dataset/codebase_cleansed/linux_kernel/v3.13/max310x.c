static u8 max310x_port_read(struct uart_port *port, u8 reg)
{
struct max310x_port *s = dev_get_drvdata(port->dev);
unsigned int val = 0;
regmap_read(s->regmap, port->iobase + reg, &val);
return val;
}
static void max310x_port_write(struct uart_port *port, u8 reg, u8 val)
{
struct max310x_port *s = dev_get_drvdata(port->dev);
regmap_write(s->regmap, port->iobase + reg, val);
}
static void max310x_port_update(struct uart_port *port, u8 reg, u8 mask, u8 val)
{
struct max310x_port *s = dev_get_drvdata(port->dev);
regmap_update_bits(s->regmap, port->iobase + reg, mask, val);
}
static int max3107_detect(struct device *dev)
{
struct max310x_port *s = dev_get_drvdata(dev);
unsigned int val = 0;
int ret;
ret = regmap_read(s->regmap, MAX310X_REVID_REG, &val);
if (ret)
return ret;
if (((val & MAX310x_REV_MASK) != MAX3107_REV_ID)) {
dev_err(dev,
"%s ID 0x%02x does not match\n", s->devtype->name, val);
return -ENODEV;
}
return 0;
}
static int max3108_detect(struct device *dev)
{
struct max310x_port *s = dev_get_drvdata(dev);
unsigned int val = 0;
int ret;
ret = regmap_read(s->regmap, MAX310X_CLKSRC_REG, &val);
if (ret)
return ret;
if (val != (MAX310X_CLKSRC_EXTCLK_BIT | MAX310X_CLKSRC_PLLBYP_BIT)) {
dev_err(dev, "%s not present\n", s->devtype->name);
return -ENODEV;
}
return 0;
}
static int max3109_detect(struct device *dev)
{
struct max310x_port *s = dev_get_drvdata(dev);
unsigned int val = 0;
int ret;
ret = regmap_read(s->regmap, MAX310X_REVID_REG, &val);
if (ret)
return ret;
if (((val & MAX310x_REV_MASK) != MAX3109_REV_ID)) {
dev_err(dev,
"%s ID 0x%02x does not match\n", s->devtype->name, val);
return -ENODEV;
}
return 0;
}
static void max310x_power(struct uart_port *port, int on)
{
max310x_port_update(port, MAX310X_MODE1_REG,
MAX310X_MODE1_FORCESLEEP_BIT,
on ? 0 : MAX310X_MODE1_FORCESLEEP_BIT);
if (on)
msleep(50);
}
static int max14830_detect(struct device *dev)
{
struct max310x_port *s = dev_get_drvdata(dev);
unsigned int val = 0;
int ret;
ret = regmap_write(s->regmap, MAX310X_GLOBALCMD_REG,
MAX310X_EXTREG_ENBL);
if (ret)
return ret;
regmap_read(s->regmap, MAX310X_REVID_EXTREG, &val);
regmap_write(s->regmap, MAX310X_GLOBALCMD_REG, MAX310X_EXTREG_DSBL);
if (((val & MAX310x_REV_MASK) != MAX14830_REV_ID)) {
dev_err(dev,
"%s ID 0x%02x does not match\n", s->devtype->name, val);
return -ENODEV;
}
return 0;
}
static void max14830_power(struct uart_port *port, int on)
{
max310x_port_update(port, MAX310X_BRGCFG_REG,
MAX14830_BRGCFG_CLKDIS_BIT,
on ? 0 : MAX14830_BRGCFG_CLKDIS_BIT);
if (on)
msleep(50);
}
static bool max310x_reg_writeable(struct device *dev, unsigned int reg)
{
switch (reg & 0x1f) {
case MAX310X_IRQSTS_REG:
case MAX310X_LSR_IRQSTS_REG:
case MAX310X_SPCHR_IRQSTS_REG:
case MAX310X_STS_IRQSTS_REG:
case MAX310X_TXFIFOLVL_REG:
case MAX310X_RXFIFOLVL_REG:
return false;
default:
break;
}
return true;
}
static bool max310x_reg_volatile(struct device *dev, unsigned int reg)
{
switch (reg & 0x1f) {
case MAX310X_RHR_REG:
case MAX310X_IRQSTS_REG:
case MAX310X_LSR_IRQSTS_REG:
case MAX310X_SPCHR_IRQSTS_REG:
case MAX310X_STS_IRQSTS_REG:
case MAX310X_TXFIFOLVL_REG:
case MAX310X_RXFIFOLVL_REG:
case MAX310X_GPIODATA_REG:
case MAX310X_BRGDIVLSB_REG:
case MAX310X_REG_05:
case MAX310X_REG_1F:
return true;
default:
break;
}
return false;
}
static bool max310x_reg_precious(struct device *dev, unsigned int reg)
{
switch (reg & 0x1f) {
case MAX310X_RHR_REG:
case MAX310X_IRQSTS_REG:
case MAX310X_SPCHR_IRQSTS_REG:
case MAX310X_STS_IRQSTS_REG:
return true;
default:
break;
}
return false;
}
static void max310x_set_baud(struct uart_port *port, int baud)
{
unsigned int mode = 0, div = port->uartclk / baud;
if (!(div / 16)) {
mode = MAX310X_BRGCFG_2XMODE_BIT;
div = (port->uartclk * 2) / baud;
}
if (!(div / 16)) {
mode = MAX310X_BRGCFG_4XMODE_BIT;
div = (port->uartclk * 4) / baud;
}
max310x_port_write(port, MAX310X_BRGDIVMSB_REG, (div / 16) >> 8);
max310x_port_write(port, MAX310X_BRGDIVLSB_REG, div / 16);
max310x_port_write(port, MAX310X_BRGCFG_REG, (div % 16) | mode);
}
static int max310x_update_best_err(unsigned long f, long *besterr)
{
long err = f % (115200 * 16);
if ((*besterr < 0) || (*besterr > err)) {
*besterr = err;
return 0;
}
return 1;
}
static int max310x_set_ref_clk(struct max310x_port *s)
{
unsigned int div, clksrc, pllcfg = 0;
long besterr = -1;
unsigned long fdiv, fmul, bestfreq = s->pdata->frequency;
max310x_update_best_err(s->pdata->frequency, &besterr);
for (div = 1; (div <= 63) && besterr; div++) {
fdiv = DIV_ROUND_CLOSEST(s->pdata->frequency, div);
fmul = fdiv * 6;
if ((fdiv >= 500000) && (fdiv <= 800000))
if (!max310x_update_best_err(fmul, &besterr)) {
pllcfg = (0 << 6) | div;
bestfreq = fmul;
}
fmul = fdiv * 48;
if ((fdiv >= 850000) && (fdiv <= 1200000))
if (!max310x_update_best_err(fmul, &besterr)) {
pllcfg = (1 << 6) | div;
bestfreq = fmul;
}
fmul = fdiv * 96;
if ((fdiv >= 425000) && (fdiv <= 1000000))
if (!max310x_update_best_err(fmul, &besterr)) {
pllcfg = (2 << 6) | div;
bestfreq = fmul;
}
fmul = fdiv * 144;
if ((fdiv >= 390000) && (fdiv <= 667000))
if (!max310x_update_best_err(fmul, &besterr)) {
pllcfg = (3 << 6) | div;
bestfreq = fmul;
}
}
if (s->pdata->driver_flags & MAX310X_EXT_CLK)
clksrc = MAX310X_CLKSRC_EXTCLK_BIT;
else
clksrc = MAX310X_CLKSRC_CRYST_BIT;
if (pllcfg) {
clksrc |= MAX310X_CLKSRC_PLL_BIT;
regmap_write(s->regmap, MAX310X_PLLCFG_REG, pllcfg);
} else
clksrc |= MAX310X_CLKSRC_PLLBYP_BIT;
regmap_write(s->regmap, MAX310X_CLKSRC_REG, clksrc);
if (pllcfg && !(s->pdata->driver_flags & MAX310X_EXT_CLK))
msleep(10);
return (int)bestfreq;
}
static void max310x_handle_rx(struct uart_port *port, unsigned int rxlen)
{
unsigned int sts, ch, flag;
if (unlikely(rxlen >= port->fifosize)) {
dev_warn_ratelimited(port->dev,
"Port %i: Possible RX FIFO overrun\n",
port->line);
port->icount.buf_overrun++;
rxlen = port->fifosize;
}
while (rxlen--) {
ch = max310x_port_read(port, MAX310X_RHR_REG);
sts = max310x_port_read(port, MAX310X_LSR_IRQSTS_REG);
sts &= MAX310X_LSR_RXPAR_BIT | MAX310X_LSR_FRERR_BIT |
MAX310X_LSR_RXOVR_BIT | MAX310X_LSR_RXBRK_BIT;
port->icount.rx++;
flag = TTY_NORMAL;
if (unlikely(sts)) {
if (sts & MAX310X_LSR_RXBRK_BIT) {
port->icount.brk++;
if (uart_handle_break(port))
continue;
} else if (sts & MAX310X_LSR_RXPAR_BIT)
port->icount.parity++;
else if (sts & MAX310X_LSR_FRERR_BIT)
port->icount.frame++;
else if (sts & MAX310X_LSR_RXOVR_BIT)
port->icount.overrun++;
sts &= port->read_status_mask;
if (sts & MAX310X_LSR_RXBRK_BIT)
flag = TTY_BREAK;
else if (sts & MAX310X_LSR_RXPAR_BIT)
flag = TTY_PARITY;
else if (sts & MAX310X_LSR_FRERR_BIT)
flag = TTY_FRAME;
else if (sts & MAX310X_LSR_RXOVR_BIT)
flag = TTY_OVERRUN;
}
if (uart_handle_sysrq_char(port, ch))
continue;
if (sts & port->ignore_status_mask)
continue;
uart_insert_char(port, sts, MAX310X_LSR_RXOVR_BIT, ch, flag);
}
tty_flip_buffer_push(&port->state->port);
}
static void max310x_handle_tx(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
unsigned int txlen, to_send;
if (unlikely(port->x_char)) {
max310x_port_write(port, MAX310X_THR_REG, port->x_char);
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port))
return;
to_send = uart_circ_chars_pending(xmit);
if (likely(to_send)) {
txlen = max310x_port_read(port, MAX310X_TXFIFOLVL_REG);
txlen = port->fifosize - txlen;
to_send = (to_send > txlen) ? txlen : to_send;
port->icount.tx += to_send;
while (to_send--) {
max310x_port_write(port, MAX310X_THR_REG,
xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
}
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
static void max310x_port_irq(struct max310x_port *s, int portno)
{
struct uart_port *port = &s->p[portno].port;
do {
unsigned int ists, lsr, rxlen;
ists = max310x_port_read(port, MAX310X_IRQSTS_REG);
rxlen = max310x_port_read(port, MAX310X_RXFIFOLVL_REG);
if (!ists && !rxlen)
break;
if (ists & MAX310X_IRQ_CTS_BIT) {
lsr = max310x_port_read(port, MAX310X_LSR_IRQSTS_REG);
uart_handle_cts_change(port,
!!(lsr & MAX310X_LSR_CTS_BIT));
}
if (rxlen)
max310x_handle_rx(port, rxlen);
if (ists & MAX310X_IRQ_TXEMPTY_BIT) {
mutex_lock(&s->mutex);
max310x_handle_tx(port);
mutex_unlock(&s->mutex);
}
} while (1);
}
static irqreturn_t max310x_ist(int irq, void *dev_id)
{
struct max310x_port *s = (struct max310x_port *)dev_id;
if (s->uart.nr > 1) {
do {
unsigned int val = ~0;
WARN_ON_ONCE(regmap_read(s->regmap,
MAX310X_GLOBALIRQ_REG, &val));
val = ((1 << s->uart.nr) - 1) & ~val;
if (!val)
break;
max310x_port_irq(s, fls(val) - 1);
} while (1);
} else
max310x_port_irq(s, 0);
return IRQ_HANDLED;
}
static void max310x_wq_proc(struct work_struct *ws)
{
struct max310x_one *one = container_of(ws, struct max310x_one, tx_work);
struct max310x_port *s = dev_get_drvdata(one->port.dev);
mutex_lock(&s->mutex);
max310x_handle_tx(&one->port);
mutex_unlock(&s->mutex);
}
static void max310x_start_tx(struct uart_port *port)
{
struct max310x_one *one = container_of(port, struct max310x_one, port);
if (!work_pending(&one->tx_work))
schedule_work(&one->tx_work);
}
static unsigned int max310x_tx_empty(struct uart_port *port)
{
unsigned int lvl, sts;
lvl = max310x_port_read(port, MAX310X_TXFIFOLVL_REG);
sts = max310x_port_read(port, MAX310X_IRQSTS_REG);
return ((sts & MAX310X_IRQ_TXEMPTY_BIT) && !lvl) ? TIOCSER_TEMT : 0;
}
static unsigned int max310x_get_mctrl(struct uart_port *port)
{
return TIOCM_DSR | TIOCM_CAR;
}
static void max310x_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void max310x_break_ctl(struct uart_port *port, int break_state)
{
max310x_port_update(port, MAX310X_LCR_REG,
MAX310X_LCR_TXBREAK_BIT,
break_state ? MAX310X_LCR_TXBREAK_BIT : 0);
}
static void max310x_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
unsigned int lcr, flow = 0;
int baud;
termios->c_cflag &= ~CMSPAR;
switch (termios->c_cflag & CSIZE) {
case CS5:
lcr = MAX310X_LCR_WORD_LEN_5;
break;
case CS6:
lcr = MAX310X_LCR_WORD_LEN_6;
break;
case CS7:
lcr = MAX310X_LCR_WORD_LEN_7;
break;
case CS8:
default:
lcr = MAX310X_LCR_WORD_LEN_8;
break;
}
if (termios->c_cflag & PARENB) {
lcr |= MAX310X_LCR_PARITY_BIT;
if (!(termios->c_cflag & PARODD))
lcr |= MAX310X_LCR_EVENPARITY_BIT;
}
if (termios->c_cflag & CSTOPB)
lcr |= MAX310X_LCR_STOPLEN_BIT;
max310x_port_write(port, MAX310X_LCR_REG, lcr);
port->read_status_mask = MAX310X_LSR_RXOVR_BIT;
if (termios->c_iflag & INPCK)
port->read_status_mask |= MAX310X_LSR_RXPAR_BIT |
MAX310X_LSR_FRERR_BIT;
if (termios->c_iflag & (BRKINT | PARMRK))
port->read_status_mask |= MAX310X_LSR_RXBRK_BIT;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNBRK)
port->ignore_status_mask |= MAX310X_LSR_RXBRK_BIT;
if (!(termios->c_cflag & CREAD))
port->ignore_status_mask |= MAX310X_LSR_RXPAR_BIT |
MAX310X_LSR_RXOVR_BIT |
MAX310X_LSR_FRERR_BIT |
MAX310X_LSR_RXBRK_BIT;
max310x_port_write(port, MAX310X_XON1_REG, termios->c_cc[VSTART]);
max310x_port_write(port, MAX310X_XOFF1_REG, termios->c_cc[VSTOP]);
if (termios->c_cflag & CRTSCTS)
flow |= MAX310X_FLOWCTRL_AUTOCTS_BIT |
MAX310X_FLOWCTRL_AUTORTS_BIT;
if (termios->c_iflag & IXON)
flow |= MAX310X_FLOWCTRL_SWFLOW3_BIT |
MAX310X_FLOWCTRL_SWFLOWEN_BIT;
if (termios->c_iflag & IXOFF)
flow |= MAX310X_FLOWCTRL_SWFLOW1_BIT |
MAX310X_FLOWCTRL_SWFLOWEN_BIT;
max310x_port_write(port, MAX310X_FLOWCTRL_REG, flow);
baud = uart_get_baud_rate(port, termios, old,
port->uartclk / 16 / 0xffff,
port->uartclk / 4);
max310x_set_baud(port, baud);
uart_update_timeout(port, termios->c_cflag, baud);
}
static int max310x_startup(struct uart_port *port)
{
unsigned int val, line = port->line;
struct max310x_port *s = dev_get_drvdata(port->dev);
s->devtype->power(port, 1);
max310x_set_baud(port, 9600);
max310x_port_write(port, MAX310X_LCR_REG, MAX310X_LCR_WORD_LEN_8);
max310x_port_update(port, MAX310X_MODE1_REG,
MAX310X_MODE1_TRNSCVCTRL_BIT,
(s->pdata->uart_flags[line] & MAX310X_AUTO_DIR_CTRL)
? MAX310X_MODE1_TRNSCVCTRL_BIT : 0);
val = MAX310X_MODE2_RXEMPTINV_BIT;
if (s->pdata->uart_flags[line] & MAX310X_LOOPBACK)
val |= MAX310X_MODE2_LOOPBACK_BIT;
if (s->pdata->uart_flags[line] & MAX310X_ECHO_SUPRESS)
val |= MAX310X_MODE2_ECHOSUPR_BIT;
val |= MAX310X_MODE2_FIFORST_BIT;
max310x_port_write(port, MAX310X_MODE2_REG, val);
max310x_port_update(port, MAX310X_MODE2_REG,
MAX310X_MODE2_FIFORST_BIT, 0);
max310x_port_write(port, MAX310X_FLOWLVL_REG,
MAX310X_FLOWLVL_RES(48) | MAX310X_FLOWLVL_HALT(96));
max310x_port_read(port, MAX310X_IRQSTS_REG);
val = MAX310X_IRQ_RXEMPTY_BIT | MAX310X_IRQ_TXEMPTY_BIT;
max310x_port_write(port, MAX310X_IRQEN_REG, val | MAX310X_IRQ_CTS_BIT);
return 0;
}
static void max310x_shutdown(struct uart_port *port)
{
struct max310x_port *s = dev_get_drvdata(port->dev);
max310x_port_write(port, MAX310X_IRQEN_REG, 0);
s->devtype->power(port, 0);
}
static const char *max310x_type(struct uart_port *port)
{
struct max310x_port *s = dev_get_drvdata(port->dev);
return (port->type == PORT_MAX310X) ? s->devtype->name : NULL;
}
static int max310x_request_port(struct uart_port *port)
{
return 0;
}
static void max310x_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_MAX310X;
}
static int max310x_verify_port(struct uart_port *port, struct serial_struct *s)
{
if ((s->type != PORT_UNKNOWN) && (s->type != PORT_MAX310X))
return -EINVAL;
if (s->irq != port->irq)
return -EINVAL;
return 0;
}
static void max310x_null_void(struct uart_port *port)
{
}
static int __maybe_unused max310x_suspend(struct device *dev)
{
struct max310x_port *s = dev_get_drvdata(dev);
int i;
for (i = 0; i < s->uart.nr; i++) {
uart_suspend_port(&s->uart, &s->p[i].port);
s->devtype->power(&s->p[i].port, 0);
}
return 0;
}
static int __maybe_unused max310x_resume(struct device *dev)
{
struct max310x_port *s = dev_get_drvdata(dev);
int i;
for (i = 0; i < s->uart.nr; i++) {
s->devtype->power(&s->p[i].port, 1);
uart_resume_port(&s->uart, &s->p[i].port);
}
return 0;
}
static int max310x_gpio_get(struct gpio_chip *chip, unsigned offset)
{
unsigned int val;
struct max310x_port *s = container_of(chip, struct max310x_port, gpio);
struct uart_port *port = &s->p[offset / 4].port;
val = max310x_port_read(port, MAX310X_GPIODATA_REG);
return !!((val >> 4) & (1 << (offset % 4)));
}
static void max310x_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct max310x_port *s = container_of(chip, struct max310x_port, gpio);
struct uart_port *port = &s->p[offset / 4].port;
max310x_port_update(port, MAX310X_GPIODATA_REG, 1 << (offset % 4),
value ? 1 << (offset % 4) : 0);
}
static int max310x_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct max310x_port *s = container_of(chip, struct max310x_port, gpio);
struct uart_port *port = &s->p[offset / 4].port;
max310x_port_update(port, MAX310X_GPIOCFG_REG, 1 << (offset % 4), 0);
return 0;
}
static int max310x_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct max310x_port *s = container_of(chip, struct max310x_port, gpio);
struct uart_port *port = &s->p[offset / 4].port;
max310x_port_update(port, MAX310X_GPIODATA_REG, 1 << (offset % 4),
value ? 1 << (offset % 4) : 0);
max310x_port_update(port, MAX310X_GPIOCFG_REG, 1 << (offset % 4),
1 << (offset % 4));
return 0;
}
static int max310x_probe(struct device *dev, int is_spi,
struct max310x_devtype *devtype, int irq)
{
struct max310x_port *s;
struct max310x_pdata *pdata = dev_get_platdata(dev);
int i, ret, uartclk;
if (irq <= 0) {
dev_err(dev, "No IRQ specified\n");
return -ENOTSUPP;
}
if (!pdata) {
dev_err(dev, "No platform data supplied\n");
return -EINVAL;
}
s = devm_kzalloc(dev, sizeof(*s) +
sizeof(struct max310x_one) * devtype->nr, GFP_KERNEL);
if (!s) {
dev_err(dev, "Error allocating port structure\n");
return -ENOMEM;
}
if ((pdata->driver_flags & MAX310X_EXT_CLK) &&
((pdata->frequency < 500000) || (pdata->frequency > 35000000)))
goto err_freq;
if (!(pdata->driver_flags & MAX310X_EXT_CLK) &&
((pdata->frequency < 1000000) || (pdata->frequency > 4000000)))
goto err_freq;
s->pdata = pdata;
s->devtype = devtype;
dev_set_drvdata(dev, s);
mutex_init(&s->mutex);
s->regcfg.reg_bits = 8;
s->regcfg.val_bits = 8;
s->regcfg.read_flag_mask = 0x00;
s->regcfg.write_flag_mask = 0x80;
s->regcfg.cache_type = REGCACHE_RBTREE;
s->regcfg.writeable_reg = max310x_reg_writeable;
s->regcfg.volatile_reg = max310x_reg_volatile;
s->regcfg.precious_reg = max310x_reg_precious;
s->regcfg.max_register = devtype->nr * 0x20 - 1;
if (IS_ENABLED(CONFIG_SPI_MASTER) && is_spi) {
struct spi_device *spi = to_spi_device(dev);
s->regmap = devm_regmap_init_spi(spi, &s->regcfg);
} else
return -ENOTSUPP;
if (IS_ERR(s->regmap)) {
dev_err(dev, "Failed to initialize register map\n");
return PTR_ERR(s->regmap);
}
if (s->pdata->init)
s->pdata->init();
ret = devtype->detect(dev);
if (ret)
return ret;
for (i = 0; i < devtype->nr; i++) {
unsigned int offs = i << 5;
regmap_write(s->regmap, MAX310X_MODE2_REG + offs,
MAX310X_MODE2_RST_BIT);
regmap_write(s->regmap, MAX310X_MODE2_REG + offs, 0);
do {
regmap_read(s->regmap,
MAX310X_BRGDIVLSB_REG + offs, &ret);
} while (ret != 0x01);
regmap_update_bits(s->regmap, MAX310X_MODE1_REG + offs,
MAX310X_MODE1_AUTOSLEEP_BIT,
MAX310X_MODE1_AUTOSLEEP_BIT);
}
uartclk = max310x_set_ref_clk(s);
dev_dbg(dev, "Reference clock set to %i Hz\n", uartclk);
s->uart.owner = THIS_MODULE;
s->uart.dev_name = "ttyMAX";
s->uart.major = MAX310X_MAJOR;
s->uart.minor = MAX310X_MINOR;
s->uart.nr = devtype->nr;
ret = uart_register_driver(&s->uart);
if (ret) {
dev_err(dev, "Registering UART driver failed\n");
return ret;
}
for (i = 0; i < devtype->nr; i++) {
s->p[i].port.line = i;
s->p[i].port.dev = dev;
s->p[i].port.irq = irq;
s->p[i].port.type = PORT_MAX310X;
s->p[i].port.fifosize = MAX310X_FIFO_SIZE;
s->p[i].port.flags = UPF_SKIP_TEST | UPF_FIXED_TYPE |
UPF_LOW_LATENCY;
s->p[i].port.iotype = UPIO_PORT;
s->p[i].port.iobase = i * 0x20;
s->p[i].port.membase = (void __iomem *)~0;
s->p[i].port.uartclk = uartclk;
s->p[i].port.ops = &max310x_ops;
max310x_port_write(&s->p[i].port, MAX310X_IRQEN_REG, 0);
max310x_port_read(&s->p[i].port, MAX310X_IRQSTS_REG);
max310x_port_update(&s->p[i].port, MAX310X_MODE1_REG,
MAX310X_MODE1_IRQSEL_BIT,
MAX310X_MODE1_IRQSEL_BIT);
INIT_WORK(&s->p[i].tx_work, max310x_wq_proc);
uart_add_one_port(&s->uart, &s->p[i].port);
devtype->power(&s->p[i].port, 0);
}
#ifdef CONFIG_GPIOLIB
if (s->pdata->gpio_base) {
s->gpio.owner = THIS_MODULE;
s->gpio.dev = dev;
s->gpio.label = dev_name(dev);
s->gpio.direction_input = max310x_gpio_direction_input;
s->gpio.get = max310x_gpio_get;
s->gpio.direction_output= max310x_gpio_direction_output;
s->gpio.set = max310x_gpio_set;
s->gpio.base = s->pdata->gpio_base;
s->gpio.ngpio = devtype->nr * 4;
s->gpio.can_sleep = 1;
if (!gpiochip_add(&s->gpio))
s->gpio_used = 1;
} else
dev_info(dev, "GPIO support not enabled\n");
#endif
ret = devm_request_threaded_irq(dev, irq, NULL, max310x_ist,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
dev_name(dev), s);
if (ret) {
dev_err(dev, "Unable to reguest IRQ %i\n", irq);
#ifdef CONFIG_GPIOLIB
if (s->gpio_used)
WARN_ON(gpiochip_remove(&s->gpio));
#endif
}
return ret;
err_freq:
dev_err(dev, "Frequency parameter incorrect\n");
return -EINVAL;
}
static int max310x_remove(struct device *dev)
{
struct max310x_port *s = dev_get_drvdata(dev);
int i, ret = 0;
for (i = 0; i < s->uart.nr; i++) {
cancel_work_sync(&s->p[i].tx_work);
uart_remove_one_port(&s->uart, &s->p[i].port);
s->devtype->power(&s->p[i].port, 0);
}
uart_unregister_driver(&s->uart);
#ifdef CONFIG_GPIOLIB
if (s->gpio_used)
ret = gpiochip_remove(&s->gpio);
#endif
if (s->pdata->exit)
s->pdata->exit();
return ret;
}
static int max310x_spi_probe(struct spi_device *spi)
{
struct max310x_devtype *devtype =
(struct max310x_devtype *)spi_get_device_id(spi)->driver_data;
int ret;
spi->bits_per_word = 8;
spi->mode = spi->mode ? : SPI_MODE_0;
spi->max_speed_hz = spi->max_speed_hz ? : 26000000;
ret = spi_setup(spi);
if (ret) {
dev_err(&spi->dev, "SPI setup failed\n");
return ret;
}
return max310x_probe(&spi->dev, 1, devtype, spi->irq);
}
static int max310x_spi_remove(struct spi_device *spi)
{
return max310x_remove(&spi->dev);
}
