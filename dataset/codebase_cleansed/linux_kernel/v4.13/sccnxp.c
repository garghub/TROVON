static inline u8 sccnxp_read(struct uart_port *port, u8 reg)
{
return readb(port->membase + (reg << port->regshift));
}
static inline void sccnxp_write(struct uart_port *port, u8 reg, u8 v)
{
writeb(v, port->membase + (reg << port->regshift));
}
static inline u8 sccnxp_port_read(struct uart_port *port, u8 reg)
{
return sccnxp_read(port, (port->line << 3) + reg);
}
static inline void sccnxp_port_write(struct uart_port *port, u8 reg, u8 v)
{
sccnxp_write(port, (port->line << 3) + reg, v);
}
static int sccnxp_update_best_err(int a, int b, int *besterr)
{
int err = abs(a - b);
if ((*besterr < 0) || (*besterr > err)) {
*besterr = err;
return 0;
}
return 1;
}
static int sccnxp_set_baud(struct uart_port *port, int baud)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
int div_std, tmp_baud, bestbaud = baud, besterr = -1;
struct sccnxp_chip *chip = s->chip;
u8 i, acr = 0, csr = 0, mr0 = 0;
for (i = 0; baud_std[i].baud && besterr; i++) {
if (baud_std[i].mr0 && !(chip->flags & SCCNXP_HAVE_MR0))
continue;
div_std = DIV_ROUND_CLOSEST(chip->freq_std, baud_std[i].baud);
tmp_baud = DIV_ROUND_CLOSEST(port->uartclk, div_std);
if (!sccnxp_update_best_err(baud, tmp_baud, &besterr)) {
acr = baud_std[i].acr;
csr = baud_std[i].csr;
mr0 = baud_std[i].mr0;
bestbaud = tmp_baud;
}
}
if (chip->flags & SCCNXP_HAVE_MR0) {
mr0 |= MR0_FIFO | MR0_TXLVL;
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_MRPTR0);
sccnxp_port_write(port, SCCNXP_MR_REG, mr0);
}
sccnxp_port_write(port, SCCNXP_ACR_REG, acr | ACR_TIMER_MODE);
sccnxp_port_write(port, SCCNXP_CSR_REG, (csr << 4) | csr);
if (baud != bestbaud)
dev_dbg(port->dev, "Baudrate desired: %i, calculated: %i\n",
baud, bestbaud);
return bestbaud;
}
static void sccnxp_enable_irq(struct uart_port *port, int mask)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
s->imr |= mask << (port->line * 4);
sccnxp_write(port, SCCNXP_IMR_REG, s->imr);
}
static void sccnxp_disable_irq(struct uart_port *port, int mask)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
s->imr &= ~(mask << (port->line * 4));
sccnxp_write(port, SCCNXP_IMR_REG, s->imr);
}
static void sccnxp_set_bit(struct uart_port *port, int sig, int state)
{
u8 bitmask;
struct sccnxp_port *s = dev_get_drvdata(port->dev);
if (s->pdata.mctrl_cfg[port->line] & MCTRL_MASK(sig)) {
bitmask = 1 << MCTRL_OBIT(s->pdata.mctrl_cfg[port->line], sig);
if (state)
sccnxp_write(port, SCCNXP_SOP_REG, bitmask);
else
sccnxp_write(port, SCCNXP_ROP_REG, bitmask);
}
}
static void sccnxp_handle_rx(struct uart_port *port)
{
u8 sr;
unsigned int ch, flag;
for (;;) {
sr = sccnxp_port_read(port, SCCNXP_SR_REG);
if (!(sr & SR_RXRDY))
break;
sr &= SR_PE | SR_FE | SR_OVR | SR_BRK;
ch = sccnxp_port_read(port, SCCNXP_RHR_REG);
port->icount.rx++;
flag = TTY_NORMAL;
if (unlikely(sr)) {
if (sr & SR_BRK) {
port->icount.brk++;
sccnxp_port_write(port, SCCNXP_CR_REG,
CR_CMD_BREAK_RESET);
if (uart_handle_break(port))
continue;
} else if (sr & SR_PE)
port->icount.parity++;
else if (sr & SR_FE)
port->icount.frame++;
else if (sr & SR_OVR) {
port->icount.overrun++;
sccnxp_port_write(port, SCCNXP_CR_REG,
CR_CMD_STATUS_RESET);
}
sr &= port->read_status_mask;
if (sr & SR_BRK)
flag = TTY_BREAK;
else if (sr & SR_PE)
flag = TTY_PARITY;
else if (sr & SR_FE)
flag = TTY_FRAME;
else if (sr & SR_OVR)
flag = TTY_OVERRUN;
}
if (uart_handle_sysrq_char(port, ch))
continue;
if (sr & port->ignore_status_mask)
continue;
uart_insert_char(port, sr, SR_OVR, ch, flag);
}
tty_flip_buffer_push(&port->state->port);
}
static void sccnxp_handle_tx(struct uart_port *port)
{
u8 sr;
struct circ_buf *xmit = &port->state->xmit;
struct sccnxp_port *s = dev_get_drvdata(port->dev);
if (unlikely(port->x_char)) {
sccnxp_port_write(port, SCCNXP_THR_REG, port->x_char);
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
if (sccnxp_port_read(port, SCCNXP_SR_REG) & SR_TXEMT) {
sccnxp_disable_irq(port, IMR_TXRDY);
if (s->chip->flags & SCCNXP_HAVE_IO)
sccnxp_set_bit(port, DIR_OP, 0);
}
return;
}
while (!uart_circ_empty(xmit)) {
sr = sccnxp_port_read(port, SCCNXP_SR_REG);
if (!(sr & SR_TXRDY))
break;
sccnxp_port_write(port, SCCNXP_THR_REG, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
static void sccnxp_handle_events(struct sccnxp_port *s)
{
int i;
u8 isr;
do {
isr = sccnxp_read(&s->port[0], SCCNXP_ISR_REG);
isr &= s->imr;
if (!isr)
break;
for (i = 0; i < s->uart.nr; i++) {
if (s->opened[i] && (isr & ISR_RXRDY(i)))
sccnxp_handle_rx(&s->port[i]);
if (s->opened[i] && (isr & ISR_TXRDY(i)))
sccnxp_handle_tx(&s->port[i]);
}
} while (1);
}
static void sccnxp_timer(unsigned long data)
{
struct sccnxp_port *s = (struct sccnxp_port *)data;
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
sccnxp_handle_events(s);
spin_unlock_irqrestore(&s->lock, flags);
mod_timer(&s->timer, jiffies + usecs_to_jiffies(s->pdata.poll_time_us));
}
static irqreturn_t sccnxp_ist(int irq, void *dev_id)
{
struct sccnxp_port *s = (struct sccnxp_port *)dev_id;
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
sccnxp_handle_events(s);
spin_unlock_irqrestore(&s->lock, flags);
return IRQ_HANDLED;
}
static void sccnxp_start_tx(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
if (s->chip->flags & SCCNXP_HAVE_IO)
sccnxp_set_bit(port, DIR_OP, 1);
sccnxp_enable_irq(port, IMR_TXRDY);
spin_unlock_irqrestore(&s->lock, flags);
}
static void sccnxp_stop_tx(struct uart_port *port)
{
}
static void sccnxp_stop_rx(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_RX_DISABLE);
spin_unlock_irqrestore(&s->lock, flags);
}
static unsigned int sccnxp_tx_empty(struct uart_port *port)
{
u8 val;
unsigned long flags;
struct sccnxp_port *s = dev_get_drvdata(port->dev);
spin_lock_irqsave(&s->lock, flags);
val = sccnxp_port_read(port, SCCNXP_SR_REG);
spin_unlock_irqrestore(&s->lock, flags);
return (val & SR_TXEMT) ? TIOCSER_TEMT : 0;
}
static void sccnxp_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
unsigned long flags;
if (!(s->chip->flags & SCCNXP_HAVE_IO))
return;
spin_lock_irqsave(&s->lock, flags);
sccnxp_set_bit(port, DTR_OP, mctrl & TIOCM_DTR);
sccnxp_set_bit(port, RTS_OP, mctrl & TIOCM_RTS);
spin_unlock_irqrestore(&s->lock, flags);
}
static unsigned int sccnxp_get_mctrl(struct uart_port *port)
{
u8 bitmask, ipr;
unsigned long flags;
struct sccnxp_port *s = dev_get_drvdata(port->dev);
unsigned int mctrl = TIOCM_DSR | TIOCM_CTS | TIOCM_CAR;
if (!(s->chip->flags & SCCNXP_HAVE_IO))
return mctrl;
spin_lock_irqsave(&s->lock, flags);
ipr = ~sccnxp_read(port, SCCNXP_IPCR_REG);
if (s->pdata.mctrl_cfg[port->line] & MCTRL_MASK(DSR_IP)) {
bitmask = 1 << MCTRL_IBIT(s->pdata.mctrl_cfg[port->line],
DSR_IP);
mctrl &= ~TIOCM_DSR;
mctrl |= (ipr & bitmask) ? TIOCM_DSR : 0;
}
if (s->pdata.mctrl_cfg[port->line] & MCTRL_MASK(CTS_IP)) {
bitmask = 1 << MCTRL_IBIT(s->pdata.mctrl_cfg[port->line],
CTS_IP);
mctrl &= ~TIOCM_CTS;
mctrl |= (ipr & bitmask) ? TIOCM_CTS : 0;
}
if (s->pdata.mctrl_cfg[port->line] & MCTRL_MASK(DCD_IP)) {
bitmask = 1 << MCTRL_IBIT(s->pdata.mctrl_cfg[port->line],
DCD_IP);
mctrl &= ~TIOCM_CAR;
mctrl |= (ipr & bitmask) ? TIOCM_CAR : 0;
}
if (s->pdata.mctrl_cfg[port->line] & MCTRL_MASK(RNG_IP)) {
bitmask = 1 << MCTRL_IBIT(s->pdata.mctrl_cfg[port->line],
RNG_IP);
mctrl &= ~TIOCM_RNG;
mctrl |= (ipr & bitmask) ? TIOCM_RNG : 0;
}
spin_unlock_irqrestore(&s->lock, flags);
return mctrl;
}
static void sccnxp_break_ctl(struct uart_port *port, int break_state)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
sccnxp_port_write(port, SCCNXP_CR_REG, break_state ?
CR_CMD_START_BREAK : CR_CMD_STOP_BREAK);
spin_unlock_irqrestore(&s->lock, flags);
}
static void sccnxp_set_termios(struct uart_port *port,
struct ktermios *termios, struct ktermios *old)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
unsigned long flags;
u8 mr1, mr2;
int baud;
spin_lock_irqsave(&s->lock, flags);
termios->c_cflag &= ~CMSPAR;
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_RX_RESET |
CR_RX_DISABLE | CR_TX_DISABLE);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_TX_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_STATUS_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_BREAK_RESET);
switch (termios->c_cflag & CSIZE) {
case CS5:
mr1 = MR1_BITS_5;
break;
case CS6:
mr1 = MR1_BITS_6;
break;
case CS7:
mr1 = MR1_BITS_7;
break;
case CS8:
default:
mr1 = MR1_BITS_8;
break;
}
if (termios->c_cflag & PARENB) {
if (termios->c_cflag & PARODD)
mr1 |= MR1_PAR_ODD;
} else
mr1 |= MR1_PAR_NO;
mr2 = (termios->c_cflag & CSTOPB) ? MR2_STOP2 : MR2_STOP1;
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_MRPTR1);
sccnxp_port_write(port, SCCNXP_MR_REG, mr1);
sccnxp_port_write(port, SCCNXP_MR_REG, mr2);
port->read_status_mask = SR_OVR;
if (termios->c_iflag & INPCK)
port->read_status_mask |= SR_PE | SR_FE;
if (termios->c_iflag & (IGNBRK | BRKINT | PARMRK))
port->read_status_mask |= SR_BRK;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNBRK)
port->ignore_status_mask |= SR_BRK;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= SR_PE;
if (!(termios->c_cflag & CREAD))
port->ignore_status_mask |= SR_PE | SR_OVR | SR_FE | SR_BRK;
baud = uart_get_baud_rate(port, termios, old, 50,
(s->chip->flags & SCCNXP_HAVE_MR0) ?
230400 : 38400);
baud = sccnxp_set_baud(port, baud);
uart_update_timeout(port, termios->c_cflag, baud);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_RX_ENABLE | CR_TX_ENABLE);
spin_unlock_irqrestore(&s->lock, flags);
}
static int sccnxp_startup(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
if (s->chip->flags & SCCNXP_HAVE_IO) {
sccnxp_write(port, SCCNXP_OPCR_REG, 0);
}
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_RX_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_TX_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_STATUS_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_BREAK_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_RX_ENABLE | CR_TX_ENABLE);
sccnxp_enable_irq(port, IMR_RXRDY);
s->opened[port->line] = 1;
spin_unlock_irqrestore(&s->lock, flags);
return 0;
}
static void sccnxp_shutdown(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
s->opened[port->line] = 0;
sccnxp_disable_irq(port, IMR_TXRDY | IMR_RXRDY);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_RX_DISABLE | CR_TX_DISABLE);
if (s->chip->flags & SCCNXP_HAVE_IO)
sccnxp_set_bit(port, DIR_OP, 0);
spin_unlock_irqrestore(&s->lock, flags);
}
static const char *sccnxp_type(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
return (port->type == PORT_SC26XX) ? s->chip->name : NULL;
}
static void sccnxp_release_port(struct uart_port *port)
{
}
static int sccnxp_request_port(struct uart_port *port)
{
return 0;
}
static void sccnxp_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_SC26XX;
}
static int sccnxp_verify_port(struct uart_port *port, struct serial_struct *s)
{
if ((s->type == PORT_UNKNOWN) || (s->type == PORT_SC26XX))
return 0;
if (s->irq == port->irq)
return 0;
return -EINVAL;
}
static void sccnxp_console_putchar(struct uart_port *port, int c)
{
int tryes = 100000;
while (tryes--) {
if (sccnxp_port_read(port, SCCNXP_SR_REG) & SR_TXRDY) {
sccnxp_port_write(port, SCCNXP_THR_REG, c);
break;
}
barrier();
}
}
static void sccnxp_console_write(struct console *co, const char *c, unsigned n)
{
struct sccnxp_port *s = (struct sccnxp_port *)co->data;
struct uart_port *port = &s->port[co->index];
unsigned long flags;
spin_lock_irqsave(&s->lock, flags);
uart_console_write(port, c, n, sccnxp_console_putchar);
spin_unlock_irqrestore(&s->lock, flags);
}
static int sccnxp_console_setup(struct console *co, char *options)
{
struct sccnxp_port *s = (struct sccnxp_port *)co->data;
struct uart_port *port = &s->port[(co->index > 0) ? co->index : 0];
int baud = 9600, bits = 8, parity = 'n', flow = 'n';
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int sccnxp_probe(struct platform_device *pdev)
{
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct sccnxp_pdata *pdata = dev_get_platdata(&pdev->dev);
int i, ret, uartclk;
struct sccnxp_port *s;
void __iomem *membase;
struct clk *clk;
membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(membase))
return PTR_ERR(membase);
s = devm_kzalloc(&pdev->dev, sizeof(struct sccnxp_port), GFP_KERNEL);
if (!s) {
dev_err(&pdev->dev, "Error allocating port structure\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, s);
spin_lock_init(&s->lock);
s->chip = (struct sccnxp_chip *)pdev->id_entry->driver_data;
s->regulator = devm_regulator_get(&pdev->dev, "vcc");
if (!IS_ERR(s->regulator)) {
ret = regulator_enable(s->regulator);
if (ret) {
dev_err(&pdev->dev,
"Failed to enable regulator: %i\n", ret);
return ret;
}
} else if (PTR_ERR(s->regulator) == -EPROBE_DEFER)
return -EPROBE_DEFER;
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
if (ret == -EPROBE_DEFER)
goto err_out;
uartclk = 0;
} else {
clk_prepare_enable(clk);
uartclk = clk_get_rate(clk);
}
if (!uartclk) {
dev_notice(&pdev->dev, "Using default clock frequency\n");
uartclk = s->chip->freq_std;
}
if ((uartclk < s->chip->freq_min) || (uartclk > s->chip->freq_max)) {
dev_err(&pdev->dev, "Frequency out of bounds\n");
ret = -EINVAL;
goto err_out;
}
if (pdata)
memcpy(&s->pdata, pdata, sizeof(struct sccnxp_pdata));
if (s->pdata.poll_time_us) {
dev_info(&pdev->dev, "Using poll mode, resolution %u usecs\n",
s->pdata.poll_time_us);
s->poll = 1;
}
if (!s->poll) {
s->irq = platform_get_irq(pdev, 0);
if (s->irq < 0) {
dev_err(&pdev->dev, "Missing irq resource data\n");
ret = -ENXIO;
goto err_out;
}
}
s->uart.owner = THIS_MODULE;
s->uart.dev_name = "ttySC";
s->uart.major = SCCNXP_MAJOR;
s->uart.minor = SCCNXP_MINOR;
s->uart.nr = s->chip->nr;
#ifdef CONFIG_SERIAL_SCCNXP_CONSOLE
s->uart.cons = &s->console;
s->uart.cons->device = uart_console_device;
s->uart.cons->write = sccnxp_console_write;
s->uart.cons->setup = sccnxp_console_setup;
s->uart.cons->flags = CON_PRINTBUFFER;
s->uart.cons->index = -1;
s->uart.cons->data = s;
strcpy(s->uart.cons->name, "ttySC");
#endif
ret = uart_register_driver(&s->uart);
if (ret) {
dev_err(&pdev->dev, "Registering UART driver failed\n");
goto err_out;
}
for (i = 0; i < s->uart.nr; i++) {
s->port[i].line = i;
s->port[i].dev = &pdev->dev;
s->port[i].irq = s->irq;
s->port[i].type = PORT_SC26XX;
s->port[i].fifosize = s->chip->fifosize;
s->port[i].flags = UPF_SKIP_TEST | UPF_FIXED_TYPE;
s->port[i].iotype = UPIO_MEM;
s->port[i].mapbase = res->start;
s->port[i].membase = membase;
s->port[i].regshift = s->pdata.reg_shift;
s->port[i].uartclk = uartclk;
s->port[i].ops = &sccnxp_ops;
uart_add_one_port(&s->uart, &s->port[i]);
if (s->chip->flags & SCCNXP_HAVE_IO)
sccnxp_set_bit(&s->port[i], DIR_OP, 0);
}
s->imr = 0;
sccnxp_write(&s->port[0], SCCNXP_IMR_REG, 0);
if (!s->poll) {
ret = devm_request_threaded_irq(&pdev->dev, s->irq, NULL,
sccnxp_ist,
IRQF_TRIGGER_FALLING |
IRQF_ONESHOT,
dev_name(&pdev->dev), s);
if (!ret)
return 0;
dev_err(&pdev->dev, "Unable to reguest IRQ %i\n", s->irq);
} else {
init_timer(&s->timer);
setup_timer(&s->timer, sccnxp_timer, (unsigned long)s);
mod_timer(&s->timer, jiffies +
usecs_to_jiffies(s->pdata.poll_time_us));
return 0;
}
uart_unregister_driver(&s->uart);
err_out:
if (!IS_ERR(s->regulator))
return regulator_disable(s->regulator);
return ret;
}
static int sccnxp_remove(struct platform_device *pdev)
{
int i;
struct sccnxp_port *s = platform_get_drvdata(pdev);
if (!s->poll)
devm_free_irq(&pdev->dev, s->irq, s);
else
del_timer_sync(&s->timer);
for (i = 0; i < s->uart.nr; i++)
uart_remove_one_port(&s->uart, &s->port[i]);
uart_unregister_driver(&s->uart);
if (!IS_ERR(s->regulator))
return regulator_disable(s->regulator);
return 0;
}
