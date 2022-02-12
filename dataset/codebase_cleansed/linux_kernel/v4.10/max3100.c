static int max3100_do_parity(struct max3100_port *s, u16 c)
{
int parity;
if (s->parity & MAX3100_PARITY_ODD)
parity = 1;
else
parity = 0;
if (s->parity & MAX3100_7BIT)
c &= 0x7f;
else
c &= 0xff;
parity = parity ^ (hweight8(c) & 1);
return parity;
}
static int max3100_check_parity(struct max3100_port *s, u16 c)
{
return max3100_do_parity(s, c) == ((c >> 8) & 1);
}
static void max3100_calc_parity(struct max3100_port *s, u16 *c)
{
if (s->parity & MAX3100_7BIT)
*c &= 0x7f;
else
*c &= 0xff;
if (s->parity & MAX3100_PARITY_ON)
*c |= max3100_do_parity(s, *c) << 8;
}
static void max3100_dowork(struct max3100_port *s)
{
if (!s->force_end_work && !freezing(current) && !s->suspending)
queue_work(s->workqueue, &s->work);
}
static void max3100_timeout(unsigned long data)
{
struct max3100_port *s = (struct max3100_port *)data;
if (s->port.state) {
max3100_dowork(s);
mod_timer(&s->timer, jiffies + s->poll_time);
}
}
static int max3100_sr(struct max3100_port *s, u16 tx, u16 *rx)
{
struct spi_message message;
u16 etx, erx;
int status;
struct spi_transfer tran = {
.tx_buf = &etx,
.rx_buf = &erx,
.len = 2,
};
etx = cpu_to_be16(tx);
spi_message_init(&message);
spi_message_add_tail(&tran, &message);
status = spi_sync(s->spi, &message);
if (status) {
dev_warn(&s->spi->dev, "error while calling spi_sync\n");
return -EIO;
}
*rx = be16_to_cpu(erx);
s->tx_empty = (*rx & MAX3100_T) > 0;
dev_dbg(&s->spi->dev, "%04x - %04x\n", tx, *rx);
return 0;
}
static int max3100_handlerx(struct max3100_port *s, u16 rx)
{
unsigned int ch, flg, status = 0;
int ret = 0, cts;
if (rx & MAX3100_R && s->rx_enabled) {
dev_dbg(&s->spi->dev, "%s\n", __func__);
ch = rx & (s->parity & MAX3100_7BIT ? 0x7f : 0xff);
if (rx & MAX3100_RAFE) {
s->port.icount.frame++;
flg = TTY_FRAME;
status |= MAX3100_STATUS_FE;
} else {
if (s->parity & MAX3100_PARITY_ON) {
if (max3100_check_parity(s, rx)) {
s->port.icount.rx++;
flg = TTY_NORMAL;
} else {
s->port.icount.parity++;
flg = TTY_PARITY;
status |= MAX3100_STATUS_PE;
}
} else {
s->port.icount.rx++;
flg = TTY_NORMAL;
}
}
uart_insert_char(&s->port, status, MAX3100_STATUS_OE, ch, flg);
ret = 1;
}
cts = (rx & MAX3100_CTS) > 0;
if (s->cts != cts) {
s->cts = cts;
uart_handle_cts_change(&s->port, cts ? TIOCM_CTS : 0);
}
return ret;
}
static void max3100_work(struct work_struct *w)
{
struct max3100_port *s = container_of(w, struct max3100_port, work);
int rxchars;
u16 tx, rx;
int conf, cconf, rts, crts;
struct circ_buf *xmit = &s->port.state->xmit;
dev_dbg(&s->spi->dev, "%s\n", __func__);
rxchars = 0;
do {
spin_lock(&s->conf_lock);
conf = s->conf;
cconf = s->conf_commit;
s->conf_commit = 0;
rts = s->rts;
crts = s->rts_commit;
s->rts_commit = 0;
spin_unlock(&s->conf_lock);
if (cconf)
max3100_sr(s, MAX3100_WC | conf, &rx);
if (crts) {
max3100_sr(s, MAX3100_WD | MAX3100_TE |
(s->rts ? MAX3100_RTS : 0), &rx);
rxchars += max3100_handlerx(s, rx);
}
max3100_sr(s, MAX3100_RD, &rx);
rxchars += max3100_handlerx(s, rx);
if (rx & MAX3100_T) {
tx = 0xffff;
if (s->port.x_char) {
tx = s->port.x_char;
s->port.icount.tx++;
s->port.x_char = 0;
} else if (!uart_circ_empty(xmit) &&
!uart_tx_stopped(&s->port)) {
tx = xmit->buf[xmit->tail];
xmit->tail = (xmit->tail + 1) &
(UART_XMIT_SIZE - 1);
s->port.icount.tx++;
}
if (tx != 0xffff) {
max3100_calc_parity(s, &tx);
tx |= MAX3100_WD | (s->rts ? MAX3100_RTS : 0);
max3100_sr(s, tx, &rx);
rxchars += max3100_handlerx(s, rx);
}
}
if (rxchars > 16) {
tty_flip_buffer_push(&s->port.state->port);
rxchars = 0;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&s->port);
} while (!s->force_end_work &&
!freezing(current) &&
((rx & MAX3100_R) ||
(!uart_circ_empty(xmit) &&
!uart_tx_stopped(&s->port))));
if (rxchars > 0)
tty_flip_buffer_push(&s->port.state->port);
}
static irqreturn_t max3100_irq(int irqno, void *dev_id)
{
struct max3100_port *s = dev_id;
dev_dbg(&s->spi->dev, "%s\n", __func__);
max3100_dowork(s);
return IRQ_HANDLED;
}
static void max3100_enable_ms(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
if (s->poll_time > 0)
mod_timer(&s->timer, jiffies);
dev_dbg(&s->spi->dev, "%s\n", __func__);
}
static void max3100_start_tx(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
max3100_dowork(s);
}
static void max3100_stop_rx(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
s->rx_enabled = 0;
spin_lock(&s->conf_lock);
s->conf &= ~MAX3100_RM;
s->conf_commit = 1;
spin_unlock(&s->conf_lock);
max3100_dowork(s);
}
static unsigned int max3100_tx_empty(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
max3100_dowork(s);
return s->tx_empty;
}
static unsigned int max3100_get_mctrl(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
max3100_dowork(s);
return (s->cts ? TIOCM_CTS : 0) | TIOCM_DSR | TIOCM_CAR;
}
static void max3100_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
int rts;
dev_dbg(&s->spi->dev, "%s\n", __func__);
rts = (mctrl & TIOCM_RTS) > 0;
spin_lock(&s->conf_lock);
if (s->rts != rts) {
s->rts = rts;
s->rts_commit = 1;
max3100_dowork(s);
}
spin_unlock(&s->conf_lock);
}
static void
max3100_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
int baud = 0;
unsigned cflag;
u32 param_new, param_mask, parity = 0;
dev_dbg(&s->spi->dev, "%s\n", __func__);
cflag = termios->c_cflag;
param_new = 0;
param_mask = 0;
baud = tty_termios_baud_rate(termios);
param_new = s->conf & MAX3100_BAUD;
switch (baud) {
case 300:
if (s->crystal)
baud = s->baud;
else
param_new = 15;
break;
case 600:
param_new = 14 + s->crystal;
break;
case 1200:
param_new = 13 + s->crystal;
break;
case 2400:
param_new = 12 + s->crystal;
break;
case 4800:
param_new = 11 + s->crystal;
break;
case 9600:
param_new = 10 + s->crystal;
break;
case 19200:
param_new = 9 + s->crystal;
break;
case 38400:
param_new = 8 + s->crystal;
break;
case 57600:
param_new = 1 + s->crystal;
break;
case 115200:
param_new = 0 + s->crystal;
break;
case 230400:
if (s->crystal)
param_new = 0;
else
baud = s->baud;
break;
default:
baud = s->baud;
}
tty_termios_encode_baud_rate(termios, baud, baud);
s->baud = baud;
param_mask |= MAX3100_BAUD;
if ((cflag & CSIZE) == CS8) {
param_new &= ~MAX3100_L;
parity &= ~MAX3100_7BIT;
} else {
param_new |= MAX3100_L;
parity |= MAX3100_7BIT;
cflag = (cflag & ~CSIZE) | CS7;
}
param_mask |= MAX3100_L;
if (cflag & CSTOPB)
param_new |= MAX3100_ST;
else
param_new &= ~MAX3100_ST;
param_mask |= MAX3100_ST;
if (cflag & PARENB) {
param_new |= MAX3100_PE;
parity |= MAX3100_PARITY_ON;
} else {
param_new &= ~MAX3100_PE;
parity &= ~MAX3100_PARITY_ON;
}
param_mask |= MAX3100_PE;
if (cflag & PARODD)
parity |= MAX3100_PARITY_ODD;
else
parity &= ~MAX3100_PARITY_ODD;
cflag &= ~CMSPAR;
termios->c_cflag = cflag;
s->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
s->port.ignore_status_mask |=
MAX3100_STATUS_PE | MAX3100_STATUS_FE |
MAX3100_STATUS_OE;
s->port.state->port.low_latency = 1;
if (s->poll_time > 0)
del_timer_sync(&s->timer);
uart_update_timeout(port, termios->c_cflag, baud);
spin_lock(&s->conf_lock);
s->conf = (s->conf & ~param_mask) | (param_new & param_mask);
s->conf_commit = 1;
s->parity = parity;
spin_unlock(&s->conf_lock);
max3100_dowork(s);
if (UART_ENABLE_MS(&s->port, termios->c_cflag))
max3100_enable_ms(&s->port);
}
static void max3100_shutdown(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
if (s->suspending)
return;
s->force_end_work = 1;
if (s->poll_time > 0)
del_timer_sync(&s->timer);
if (s->workqueue) {
flush_workqueue(s->workqueue);
destroy_workqueue(s->workqueue);
s->workqueue = NULL;
}
if (s->irq)
free_irq(s->irq, s);
if (s->max3100_hw_suspend)
s->max3100_hw_suspend(1);
else {
u16 tx, rx;
tx = MAX3100_WC | MAX3100_SHDN;
max3100_sr(s, tx, &rx);
}
}
static int max3100_startup(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
char b[12];
dev_dbg(&s->spi->dev, "%s\n", __func__);
s->conf = MAX3100_RM;
s->baud = s->crystal ? 230400 : 115200;
s->rx_enabled = 1;
if (s->suspending)
return 0;
s->force_end_work = 0;
s->parity = 0;
s->rts = 0;
sprintf(b, "max3100-%d", s->minor);
s->workqueue = create_freezable_workqueue(b);
if (!s->workqueue) {
dev_warn(&s->spi->dev, "cannot create workqueue\n");
return -EBUSY;
}
INIT_WORK(&s->work, max3100_work);
if (request_irq(s->irq, max3100_irq,
IRQF_TRIGGER_FALLING, "max3100", s) < 0) {
dev_warn(&s->spi->dev, "cannot allocate irq %d\n", s->irq);
s->irq = 0;
destroy_workqueue(s->workqueue);
s->workqueue = NULL;
return -EBUSY;
}
if (s->loopback) {
u16 tx, rx;
tx = 0x4001;
max3100_sr(s, tx, &rx);
}
if (s->max3100_hw_suspend)
s->max3100_hw_suspend(0);
s->conf_commit = 1;
max3100_dowork(s);
msleep(50);
max3100_enable_ms(&s->port);
return 0;
}
static const char *max3100_type(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
return s->port.type == PORT_MAX3100 ? "MAX3100" : NULL;
}
static void max3100_release_port(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
}
static void max3100_config_port(struct uart_port *port, int flags)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
if (flags & UART_CONFIG_TYPE)
s->port.type = PORT_MAX3100;
}
static int max3100_verify_port(struct uart_port *port,
struct serial_struct *ser)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
int ret = -EINVAL;
dev_dbg(&s->spi->dev, "%s\n", __func__);
if (ser->type == PORT_UNKNOWN || ser->type == PORT_MAX3100)
ret = 0;
return ret;
}
static void max3100_stop_tx(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
}
static int max3100_request_port(struct uart_port *port)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
return 0;
}
static void max3100_break_ctl(struct uart_port *port, int break_state)
{
struct max3100_port *s = container_of(port,
struct max3100_port,
port);
dev_dbg(&s->spi->dev, "%s\n", __func__);
}
static int max3100_probe(struct spi_device *spi)
{
int i, retval;
struct plat_max3100 *pdata;
u16 tx, rx;
mutex_lock(&max3100s_lock);
if (!uart_driver_registered) {
uart_driver_registered = 1;
retval = uart_register_driver(&max3100_uart_driver);
if (retval) {
printk(KERN_ERR "Couldn't register max3100 uart driver\n");
mutex_unlock(&max3100s_lock);
return retval;
}
}
for (i = 0; i < MAX_MAX3100; i++)
if (!max3100s[i])
break;
if (i == MAX_MAX3100) {
dev_warn(&spi->dev, "too many MAX3100 chips\n");
mutex_unlock(&max3100s_lock);
return -ENOMEM;
}
max3100s[i] = kzalloc(sizeof(struct max3100_port), GFP_KERNEL);
if (!max3100s[i]) {
dev_warn(&spi->dev,
"kmalloc for max3100 structure %d failed!\n", i);
mutex_unlock(&max3100s_lock);
return -ENOMEM;
}
max3100s[i]->spi = spi;
max3100s[i]->irq = spi->irq;
spin_lock_init(&max3100s[i]->conf_lock);
spi_set_drvdata(spi, max3100s[i]);
pdata = dev_get_platdata(&spi->dev);
max3100s[i]->crystal = pdata->crystal;
max3100s[i]->loopback = pdata->loopback;
max3100s[i]->poll_time = msecs_to_jiffies(pdata->poll_time);
if (pdata->poll_time > 0 && max3100s[i]->poll_time == 0)
max3100s[i]->poll_time = 1;
max3100s[i]->max3100_hw_suspend = pdata->max3100_hw_suspend;
max3100s[i]->minor = i;
init_timer(&max3100s[i]->timer);
max3100s[i]->timer.function = max3100_timeout;
max3100s[i]->timer.data = (unsigned long) max3100s[i];
dev_dbg(&spi->dev, "%s: adding port %d\n", __func__, i);
max3100s[i]->port.irq = max3100s[i]->irq;
max3100s[i]->port.uartclk = max3100s[i]->crystal ? 3686400 : 1843200;
max3100s[i]->port.fifosize = 16;
max3100s[i]->port.ops = &max3100_ops;
max3100s[i]->port.flags = UPF_SKIP_TEST | UPF_BOOT_AUTOCONF;
max3100s[i]->port.line = i;
max3100s[i]->port.type = PORT_MAX3100;
max3100s[i]->port.dev = &spi->dev;
retval = uart_add_one_port(&max3100_uart_driver, &max3100s[i]->port);
if (retval < 0)
dev_warn(&spi->dev,
"uart_add_one_port failed for line %d with error %d\n",
i, retval);
if (max3100s[i]->max3100_hw_suspend)
max3100s[i]->max3100_hw_suspend(1);
else {
tx = MAX3100_WC | MAX3100_SHDN;
max3100_sr(max3100s[i], tx, &rx);
}
mutex_unlock(&max3100s_lock);
return 0;
}
static int max3100_remove(struct spi_device *spi)
{
struct max3100_port *s = spi_get_drvdata(spi);
int i;
mutex_lock(&max3100s_lock);
for (i = 0; i < MAX_MAX3100; i++)
if (max3100s[i] == s) {
dev_dbg(&spi->dev, "%s: removing port %d\n", __func__, i);
uart_remove_one_port(&max3100_uart_driver, &max3100s[i]->port);
kfree(max3100s[i]);
max3100s[i] = NULL;
break;
}
WARN_ON(i == MAX_MAX3100);
for (i = 0; i < MAX_MAX3100; i++)
if (max3100s[i]) {
mutex_unlock(&max3100s_lock);
return 0;
}
pr_debug("removing max3100 driver\n");
uart_unregister_driver(&max3100_uart_driver);
mutex_unlock(&max3100s_lock);
return 0;
}
static int max3100_suspend(struct device *dev)
{
struct max3100_port *s = dev_get_drvdata(dev);
dev_dbg(&s->spi->dev, "%s\n", __func__);
disable_irq(s->irq);
s->suspending = 1;
uart_suspend_port(&max3100_uart_driver, &s->port);
if (s->max3100_hw_suspend)
s->max3100_hw_suspend(1);
else {
u16 tx, rx;
tx = MAX3100_WC | MAX3100_SHDN;
max3100_sr(s, tx, &rx);
}
return 0;
}
static int max3100_resume(struct device *dev)
{
struct max3100_port *s = dev_get_drvdata(dev);
dev_dbg(&s->spi->dev, "%s\n", __func__);
if (s->max3100_hw_suspend)
s->max3100_hw_suspend(0);
uart_resume_port(&max3100_uart_driver, &s->port);
s->suspending = 0;
enable_irq(s->irq);
s->conf_commit = 1;
if (s->workqueue)
max3100_dowork(s);
return 0;
}
