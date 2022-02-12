static inline u8 sccnxp_raw_read(void __iomem *base, u8 reg, u8 shift)
{
return readb(base + (reg << shift));
}
static inline void sccnxp_raw_write(void __iomem *base, u8 reg, u8 shift, u8 v)
{
writeb(v, base + (reg << shift));
}
static inline u8 sccnxp_read(struct uart_port *port, u8 reg)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
return sccnxp_raw_read(port->membase, reg & s->addr_mask,
port->regshift);
}
static inline void sccnxp_write(struct uart_port *port, u8 reg, u8 v)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
sccnxp_raw_write(port->membase, reg & s->addr_mask, port->regshift, v);
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
u8 i, acr = 0, csr = 0, mr0 = 0;
for (i = 0; baud_std[i].baud && besterr; i++) {
if (baud_std[i].mr0 && !(s->flags & SCCNXP_HAVE_MR0))
continue;
div_std = DIV_ROUND_CLOSEST(s->freq_std, baud_std[i].baud);
tmp_baud = DIV_ROUND_CLOSEST(port->uartclk, div_std);
if (!sccnxp_update_best_err(baud, tmp_baud, &besterr)) {
acr = baud_std[i].acr;
csr = baud_std[i].csr;
mr0 = baud_std[i].mr0;
bestbaud = tmp_baud;
}
}
if (s->flags & SCCNXP_HAVE_MR0) {
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
struct tty_struct *tty = tty_port_tty_get(&port->state->port);
if (!tty)
return;
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
if (uart_handle_break(port))
continue;
} else if (sr & SR_PE)
port->icount.parity++;
else if (sr & SR_FE)
port->icount.frame++;
else if (sr & SR_OVR)
port->icount.overrun++;
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
tty_flip_buffer_push(tty);
tty_kref_put(tty);
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
if (s->flags & SCCNXP_HAVE_IO)
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
static irqreturn_t sccnxp_ist(int irq, void *dev_id)
{
int i;
u8 isr;
struct sccnxp_port *s = (struct sccnxp_port *)dev_id;
mutex_lock(&s->sccnxp_mutex);
for (;;) {
isr = sccnxp_read(&s->port[0], SCCNXP_ISR_REG);
isr &= s->imr;
if (!isr)
break;
dev_dbg(s->port[0].dev, "IRQ status: 0x%02x\n", isr);
for (i = 0; i < s->uart.nr; i++) {
if (isr & ISR_RXRDY(i))
sccnxp_handle_rx(&s->port[i]);
if (isr & ISR_TXRDY(i))
sccnxp_handle_tx(&s->port[i]);
}
}
mutex_unlock(&s->sccnxp_mutex);
return IRQ_HANDLED;
}
static void sccnxp_start_tx(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
mutex_lock(&s->sccnxp_mutex);
if (s->flags & SCCNXP_HAVE_IO)
sccnxp_set_bit(port, DIR_OP, 1);
sccnxp_enable_irq(port, IMR_TXRDY);
mutex_unlock(&s->sccnxp_mutex);
}
static void sccnxp_stop_tx(struct uart_port *port)
{
}
static void sccnxp_stop_rx(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
mutex_lock(&s->sccnxp_mutex);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_RX_DISABLE);
mutex_unlock(&s->sccnxp_mutex);
}
static unsigned int sccnxp_tx_empty(struct uart_port *port)
{
u8 val;
struct sccnxp_port *s = dev_get_drvdata(port->dev);
mutex_lock(&s->sccnxp_mutex);
val = sccnxp_port_read(port, SCCNXP_SR_REG);
mutex_unlock(&s->sccnxp_mutex);
return (val & SR_TXEMT) ? TIOCSER_TEMT : 0;
}
static void sccnxp_enable_ms(struct uart_port *port)
{
}
static void sccnxp_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
if (!(s->flags & SCCNXP_HAVE_IO))
return;
mutex_lock(&s->sccnxp_mutex);
sccnxp_set_bit(port, DTR_OP, mctrl & TIOCM_DTR);
sccnxp_set_bit(port, RTS_OP, mctrl & TIOCM_RTS);
mutex_unlock(&s->sccnxp_mutex);
}
static unsigned int sccnxp_get_mctrl(struct uart_port *port)
{
u8 bitmask, ipr;
struct sccnxp_port *s = dev_get_drvdata(port->dev);
unsigned int mctrl = TIOCM_DSR | TIOCM_CTS | TIOCM_CAR;
if (!(s->flags & SCCNXP_HAVE_IO))
return mctrl;
mutex_lock(&s->sccnxp_mutex);
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
mutex_unlock(&s->sccnxp_mutex);
return mctrl;
}
static void sccnxp_break_ctl(struct uart_port *port, int break_state)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
mutex_lock(&s->sccnxp_mutex);
sccnxp_port_write(port, SCCNXP_CR_REG, break_state ?
CR_CMD_START_BREAK : CR_CMD_STOP_BREAK);
mutex_unlock(&s->sccnxp_mutex);
}
static void sccnxp_set_termios(struct uart_port *port,
struct ktermios *termios, struct ktermios *old)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
u8 mr1, mr2;
int baud;
mutex_lock(&s->sccnxp_mutex);
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
if (termios->c_iflag & (BRKINT | PARMRK))
port->read_status_mask |= SR_BRK;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNBRK)
port->ignore_status_mask |= SR_BRK;
if (!(termios->c_cflag & CREAD))
port->ignore_status_mask |= SR_PE | SR_OVR | SR_FE | SR_BRK;
baud = uart_get_baud_rate(port, termios, old, 50,
(s->flags & SCCNXP_HAVE_MR0) ?
230400 : 38400);
baud = sccnxp_set_baud(port, baud);
uart_update_timeout(port, termios->c_cflag, baud);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_RX_ENABLE | CR_TX_ENABLE);
mutex_unlock(&s->sccnxp_mutex);
}
static int sccnxp_startup(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
mutex_lock(&s->sccnxp_mutex);
if (s->flags & SCCNXP_HAVE_IO) {
sccnxp_write(port, SCCNXP_OPCR_REG, 0);
}
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_RX_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_TX_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_STATUS_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_CMD_BREAK_RESET);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_RX_ENABLE | CR_TX_ENABLE);
sccnxp_enable_irq(port, IMR_RXRDY);
mutex_unlock(&s->sccnxp_mutex);
return 0;
}
static void sccnxp_shutdown(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
mutex_lock(&s->sccnxp_mutex);
sccnxp_disable_irq(port, IMR_TXRDY | IMR_RXRDY);
sccnxp_port_write(port, SCCNXP_CR_REG, CR_RX_DISABLE | CR_TX_DISABLE);
if (s->flags & SCCNXP_HAVE_IO)
sccnxp_set_bit(port, DIR_OP, 0);
mutex_unlock(&s->sccnxp_mutex);
}
static const char *sccnxp_type(struct uart_port *port)
{
struct sccnxp_port *s = dev_get_drvdata(port->dev);
return (port->type == PORT_SC26XX) ? s->name : NULL;
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
mutex_lock(&s->sccnxp_mutex);
uart_console_write(port, c, n, sccnxp_console_putchar);
mutex_unlock(&s->sccnxp_mutex);
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
int chiptype = pdev->id_entry->driver_data;
struct sccnxp_pdata *pdata = dev_get_platdata(&pdev->dev);
int i, ret, fifosize, freq_min, freq_max;
struct sccnxp_port *s;
void __iomem *membase;
if (!res) {
dev_err(&pdev->dev, "Missing memory resource data\n");
return -EADDRNOTAVAIL;
}
dev_set_name(&pdev->dev, SCCNXP_NAME);
s = devm_kzalloc(&pdev->dev, sizeof(struct sccnxp_port), GFP_KERNEL);
if (!s) {
dev_err(&pdev->dev, "Error allocating port structure\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, s);
mutex_init(&s->sccnxp_mutex);
switch (chiptype) {
case SCCNXP_TYPE_SC2681:
s->name = "SC2681";
s->uart.nr = 2;
s->freq_std = 3686400;
s->addr_mask = 0x0f;
s->flags = SCCNXP_HAVE_IO;
fifosize = 3;
freq_min = 1000000;
freq_max = 4000000;
break;
case SCCNXP_TYPE_SC2691:
s->name = "SC2691";
s->uart.nr = 1;
s->freq_std = 3686400;
s->addr_mask = 0x07;
s->flags = 0;
fifosize = 3;
freq_min = 1000000;
freq_max = 4000000;
break;
case SCCNXP_TYPE_SC2692:
s->name = "SC2692";
s->uart.nr = 2;
s->freq_std = 3686400;
s->addr_mask = 0x0f;
s->flags = SCCNXP_HAVE_IO;
fifosize = 3;
freq_min = 1000000;
freq_max = 4000000;
break;
case SCCNXP_TYPE_SC2891:
s->name = "SC2891";
s->uart.nr = 1;
s->freq_std = 3686400;
s->addr_mask = 0x0f;
s->flags = SCCNXP_HAVE_IO | SCCNXP_HAVE_MR0;
fifosize = 16;
freq_min = 100000;
freq_max = 8000000;
break;
case SCCNXP_TYPE_SC2892:
s->name = "SC2892";
s->uart.nr = 2;
s->freq_std = 3686400;
s->addr_mask = 0x0f;
s->flags = SCCNXP_HAVE_IO | SCCNXP_HAVE_MR0;
fifosize = 16;
freq_min = 100000;
freq_max = 8000000;
break;
case SCCNXP_TYPE_SC28202:
s->name = "SC28202";
s->uart.nr = 2;
s->freq_std = 14745600;
s->addr_mask = 0x7f;
s->flags = SCCNXP_HAVE_IO | SCCNXP_HAVE_MR0;
fifosize = 256;
freq_min = 1000000;
freq_max = 50000000;
break;
case SCCNXP_TYPE_SC68681:
s->name = "SC68681";
s->uart.nr = 2;
s->freq_std = 3686400;
s->addr_mask = 0x0f;
s->flags = SCCNXP_HAVE_IO;
fifosize = 3;
freq_min = 1000000;
freq_max = 4000000;
break;
case SCCNXP_TYPE_SC68692:
s->name = "SC68692";
s->uart.nr = 2;
s->freq_std = 3686400;
s->addr_mask = 0x0f;
s->flags = SCCNXP_HAVE_IO;
fifosize = 3;
freq_min = 1000000;
freq_max = 4000000;
break;
default:
dev_err(&pdev->dev, "Unsupported chip type %i\n", chiptype);
ret = -ENOTSUPP;
goto err_out;
}
if (!pdata) {
dev_warn(&pdev->dev,
"No platform data supplied, using defaults\n");
s->pdata.frequency = s->freq_std;
} else
memcpy(&s->pdata, pdata, sizeof(struct sccnxp_pdata));
s->irq = platform_get_irq(pdev, 0);
if (s->irq <= 0) {
dev_err(&pdev->dev, "Missing irq resource data\n");
ret = -ENXIO;
goto err_out;
}
if ((s->pdata.frequency < freq_min) ||
(s->pdata.frequency > freq_max)) {
dev_err(&pdev->dev, "Frequency out of bounds\n");
ret = -EINVAL;
goto err_out;
}
membase = devm_request_and_ioremap(&pdev->dev, res);
if (!membase) {
dev_err(&pdev->dev, "Failed to ioremap\n");
ret = -EIO;
goto err_out;
}
s->uart.owner = THIS_MODULE;
s->uart.dev_name = "ttySC";
s->uart.major = SCCNXP_MAJOR;
s->uart.minor = SCCNXP_MINOR;
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
s->port[i].fifosize = fifosize;
s->port[i].flags = UPF_SKIP_TEST | UPF_FIXED_TYPE;
s->port[i].iotype = UPIO_MEM;
s->port[i].mapbase = res->start;
s->port[i].membase = membase;
s->port[i].regshift = s->pdata.reg_shift;
s->port[i].uartclk = s->pdata.frequency;
s->port[i].ops = &sccnxp_ops;
uart_add_one_port(&s->uart, &s->port[i]);
if (s->flags & SCCNXP_HAVE_IO)
sccnxp_set_bit(&s->port[i], DIR_OP, 0);
}
s->imr = 0;
sccnxp_write(&s->port[0], SCCNXP_IMR_REG, 0);
if (s->pdata.init)
s->pdata.init();
ret = devm_request_threaded_irq(&pdev->dev, s->irq, NULL, sccnxp_ist,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
dev_name(&pdev->dev), s);
if (!ret)
return 0;
dev_err(&pdev->dev, "Unable to reguest IRQ %i\n", s->irq);
err_out:
platform_set_drvdata(pdev, NULL);
return ret;
}
static int sccnxp_remove(struct platform_device *pdev)
{
int i;
struct sccnxp_port *s = platform_get_drvdata(pdev);
devm_free_irq(&pdev->dev, s->irq, s);
for (i = 0; i < s->uart.nr; i++)
uart_remove_one_port(&s->uart, &s->port[i]);
uart_unregister_driver(&s->uart);
platform_set_drvdata(pdev, NULL);
if (s->pdata.exit)
s->pdata.exit();
return 0;
}
