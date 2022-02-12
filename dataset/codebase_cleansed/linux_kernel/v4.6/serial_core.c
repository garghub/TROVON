static int uart_dcd_enabled(struct uart_port *uport)
{
return !!(uport->status & UPSTAT_DCD_ENABLE);
}
void uart_write_wakeup(struct uart_port *port)
{
struct uart_state *state = port->state;
BUG_ON(!state);
tty_wakeup(state->port.tty);
}
static void uart_stop(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port = state->uart_port;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
port->ops->stop_tx(port);
spin_unlock_irqrestore(&port->lock, flags);
}
static void __uart_start(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port = state->uart_port;
if (!uart_tx_stopped(port))
port->ops->start_tx(port);
}
static void uart_start(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port = state->uart_port;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
__uart_start(tty);
spin_unlock_irqrestore(&port->lock, flags);
}
static void
uart_update_mctrl(struct uart_port *port, unsigned int set, unsigned int clear)
{
unsigned long flags;
unsigned int old;
spin_lock_irqsave(&port->lock, flags);
old = port->mctrl;
port->mctrl = (old & ~clear) | set;
if (old != port->mctrl)
port->ops->set_mctrl(port, port->mctrl);
spin_unlock_irqrestore(&port->lock, flags);
}
static int uart_port_startup(struct tty_struct *tty, struct uart_state *state,
int init_hw)
{
struct uart_port *uport = state->uart_port;
unsigned long page;
int retval = 0;
if (uport->type == PORT_UNKNOWN)
return 1;
uart_change_pm(state, UART_PM_STATE_ON);
if (!state->xmit.buf) {
page = get_zeroed_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
state->xmit.buf = (unsigned char *) page;
uart_circ_clear(&state->xmit);
}
retval = uport->ops->startup(uport);
if (retval == 0) {
if (uart_console(uport) && uport->cons->cflag) {
tty->termios.c_cflag = uport->cons->cflag;
uport->cons->cflag = 0;
}
uart_change_speed(tty, state, NULL);
if (init_hw && C_BAUD(tty))
uart_set_mctrl(uport, TIOCM_RTS | TIOCM_DTR);
}
if (retval && capable(CAP_SYS_ADMIN))
return 1;
return retval;
}
static int uart_startup(struct tty_struct *tty, struct uart_state *state,
int init_hw)
{
struct tty_port *port = &state->port;
int retval;
if (port->flags & ASYNC_INITIALIZED)
return 0;
set_bit(TTY_IO_ERROR, &tty->flags);
retval = uart_port_startup(tty, state, init_hw);
if (!retval) {
set_bit(ASYNCB_INITIALIZED, &port->flags);
clear_bit(TTY_IO_ERROR, &tty->flags);
} else if (retval > 0)
retval = 0;
return retval;
}
static void uart_shutdown(struct tty_struct *tty, struct uart_state *state)
{
struct uart_port *uport = state->uart_port;
struct tty_port *port = &state->port;
if (tty)
set_bit(TTY_IO_ERROR, &tty->flags);
if (test_and_clear_bit(ASYNCB_INITIALIZED, &port->flags)) {
if (uart_console(uport) && tty)
uport->cons->cflag = tty->termios.c_cflag;
if (!tty || C_HUPCL(tty))
uart_clear_mctrl(uport, TIOCM_DTR | TIOCM_RTS);
uart_port_shutdown(port);
}
clear_bit(ASYNCB_SUSPENDED, &port->flags);
if (state->xmit.buf) {
free_page((unsigned long)state->xmit.buf);
state->xmit.buf = NULL;
}
}
void
uart_update_timeout(struct uart_port *port, unsigned int cflag,
unsigned int baud)
{
unsigned int bits;
switch (cflag & CSIZE) {
case CS5:
bits = 7;
break;
case CS6:
bits = 8;
break;
case CS7:
bits = 9;
break;
default:
bits = 10;
break;
}
if (cflag & CSTOPB)
bits++;
if (cflag & PARENB)
bits++;
bits = bits * port->fifosize;
port->timeout = (HZ * bits) / baud + HZ/50;
}
unsigned int
uart_get_baud_rate(struct uart_port *port, struct ktermios *termios,
struct ktermios *old, unsigned int min, unsigned int max)
{
unsigned int try;
unsigned int baud;
unsigned int altbaud;
int hung_up = 0;
upf_t flags = port->flags & UPF_SPD_MASK;
switch (flags) {
case UPF_SPD_HI:
altbaud = 57600;
break;
case UPF_SPD_VHI:
altbaud = 115200;
break;
case UPF_SPD_SHI:
altbaud = 230400;
break;
case UPF_SPD_WARP:
altbaud = 460800;
break;
default:
altbaud = 38400;
break;
}
for (try = 0; try < 2; try++) {
baud = tty_termios_baud_rate(termios);
if (try == 0 && baud == 38400)
baud = altbaud;
if (baud == 0) {
hung_up = 1;
baud = 9600;
}
if (baud >= min && baud <= max)
return baud;
termios->c_cflag &= ~CBAUD;
if (old) {
baud = tty_termios_baud_rate(old);
if (!hung_up)
tty_termios_encode_baud_rate(termios,
baud, baud);
old = NULL;
continue;
}
if (!hung_up) {
if (baud <= min)
tty_termios_encode_baud_rate(termios,
min + 1, min + 1);
else
tty_termios_encode_baud_rate(termios,
max - 1, max - 1);
}
}
WARN_ON(1);
return 0;
}
unsigned int
uart_get_divisor(struct uart_port *port, unsigned int baud)
{
unsigned int quot;
if (baud == 38400 && (port->flags & UPF_SPD_MASK) == UPF_SPD_CUST)
quot = port->custom_divisor;
else
quot = DIV_ROUND_CLOSEST(port->uartclk, 16 * baud);
return quot;
}
static void uart_change_speed(struct tty_struct *tty, struct uart_state *state,
struct ktermios *old_termios)
{
struct uart_port *uport = state->uart_port;
struct ktermios *termios;
int hw_stopped;
if (!tty || uport->type == PORT_UNKNOWN)
return;
termios = &tty->termios;
uport->ops->set_termios(uport, termios, old_termios);
spin_lock_irq(&uport->lock);
if (termios->c_cflag & CRTSCTS)
uport->status |= UPSTAT_CTS_ENABLE;
else
uport->status &= ~UPSTAT_CTS_ENABLE;
if (termios->c_cflag & CLOCAL)
uport->status &= ~UPSTAT_DCD_ENABLE;
else
uport->status |= UPSTAT_DCD_ENABLE;
hw_stopped = uport->hw_stopped;
uport->hw_stopped = uart_softcts_mode(uport) &&
!(uport->ops->get_mctrl(uport) & TIOCM_CTS);
if (uport->hw_stopped) {
if (!hw_stopped)
uport->ops->stop_tx(uport);
} else {
if (hw_stopped)
__uart_start(tty);
}
spin_unlock_irq(&uport->lock);
}
static int uart_put_char(struct tty_struct *tty, unsigned char c)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port = state->uart_port;
struct circ_buf *circ;
unsigned long flags;
int ret = 0;
circ = &state->xmit;
if (!circ->buf)
return 0;
spin_lock_irqsave(&port->lock, flags);
if (uart_circ_chars_free(circ) != 0) {
circ->buf[circ->head] = c;
circ->head = (circ->head + 1) & (UART_XMIT_SIZE - 1);
ret = 1;
}
spin_unlock_irqrestore(&port->lock, flags);
return ret;
}
static void uart_flush_chars(struct tty_struct *tty)
{
uart_start(tty);
}
static int uart_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port;
struct circ_buf *circ;
unsigned long flags;
int c, ret = 0;
if (!state) {
WARN_ON(1);
return -EL3HLT;
}
port = state->uart_port;
circ = &state->xmit;
if (!circ->buf)
return 0;
spin_lock_irqsave(&port->lock, flags);
while (1) {
c = CIRC_SPACE_TO_END(circ->head, circ->tail, UART_XMIT_SIZE);
if (count < c)
c = count;
if (c <= 0)
break;
memcpy(circ->buf + circ->head, buf, c);
circ->head = (circ->head + c) & (UART_XMIT_SIZE - 1);
buf += c;
count -= c;
ret += c;
}
__uart_start(tty);
spin_unlock_irqrestore(&port->lock, flags);
return ret;
}
static int uart_write_room(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
unsigned long flags;
int ret;
spin_lock_irqsave(&state->uart_port->lock, flags);
ret = uart_circ_chars_free(&state->xmit);
spin_unlock_irqrestore(&state->uart_port->lock, flags);
return ret;
}
static int uart_chars_in_buffer(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
unsigned long flags;
int ret;
spin_lock_irqsave(&state->uart_port->lock, flags);
ret = uart_circ_chars_pending(&state->xmit);
spin_unlock_irqrestore(&state->uart_port->lock, flags);
return ret;
}
static void uart_flush_buffer(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port;
unsigned long flags;
if (!state) {
WARN_ON(1);
return;
}
port = state->uart_port;
pr_debug("uart_flush_buffer(%d) called\n", tty->index);
spin_lock_irqsave(&port->lock, flags);
uart_circ_clear(&state->xmit);
if (port->ops->flush_buffer)
port->ops->flush_buffer(port);
spin_unlock_irqrestore(&port->lock, flags);
tty_wakeup(tty);
}
static void uart_send_xchar(struct tty_struct *tty, char ch)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port = state->uart_port;
unsigned long flags;
if (port->ops->send_xchar)
port->ops->send_xchar(port, ch);
else {
spin_lock_irqsave(&port->lock, flags);
port->x_char = ch;
if (ch)
port->ops->start_tx(port);
spin_unlock_irqrestore(&port->lock, flags);
}
}
static void uart_throttle(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port = state->uart_port;
upstat_t mask = 0;
if (I_IXOFF(tty))
mask |= UPSTAT_AUTOXOFF;
if (C_CRTSCTS(tty))
mask |= UPSTAT_AUTORTS;
if (port->status & mask) {
port->ops->throttle(port);
mask &= ~port->status;
}
if (mask & UPSTAT_AUTORTS)
uart_clear_mctrl(port, TIOCM_RTS);
if (mask & UPSTAT_AUTOXOFF)
uart_send_xchar(tty, STOP_CHAR(tty));
}
static void uart_unthrottle(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port = state->uart_port;
upstat_t mask = 0;
if (I_IXOFF(tty))
mask |= UPSTAT_AUTOXOFF;
if (C_CRTSCTS(tty))
mask |= UPSTAT_AUTORTS;
if (port->status & mask) {
port->ops->unthrottle(port);
mask &= ~port->status;
}
if (mask & UPSTAT_AUTORTS)
uart_set_mctrl(port, TIOCM_RTS);
if (mask & UPSTAT_AUTOXOFF)
uart_send_xchar(tty, START_CHAR(tty));
}
static void uart_get_info(struct tty_port *port, struct serial_struct *retinfo)
{
struct uart_state *state = container_of(port, struct uart_state, port);
struct uart_port *uport = state->uart_port;
memset(retinfo, 0, sizeof(*retinfo));
mutex_lock(&port->mutex);
retinfo->type = uport->type;
retinfo->line = uport->line;
retinfo->port = uport->iobase;
if (HIGH_BITS_OFFSET)
retinfo->port_high = (long) uport->iobase >> HIGH_BITS_OFFSET;
retinfo->irq = uport->irq;
retinfo->flags = uport->flags;
retinfo->xmit_fifo_size = uport->fifosize;
retinfo->baud_base = uport->uartclk / 16;
retinfo->close_delay = jiffies_to_msecs(port->close_delay) / 10;
retinfo->closing_wait = port->closing_wait == ASYNC_CLOSING_WAIT_NONE ?
ASYNC_CLOSING_WAIT_NONE :
jiffies_to_msecs(port->closing_wait) / 10;
retinfo->custom_divisor = uport->custom_divisor;
retinfo->hub6 = uport->hub6;
retinfo->io_type = uport->iotype;
retinfo->iomem_reg_shift = uport->regshift;
retinfo->iomem_base = (void *)(unsigned long)uport->mapbase;
mutex_unlock(&port->mutex);
}
static int uart_get_info_user(struct tty_port *port,
struct serial_struct __user *retinfo)
{
struct serial_struct tmp;
uart_get_info(port, &tmp);
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int uart_set_info(struct tty_struct *tty, struct tty_port *port,
struct uart_state *state,
struct serial_struct *new_info)
{
struct uart_port *uport = state->uart_port;
unsigned long new_port;
unsigned int change_irq, change_port, closing_wait;
unsigned int old_custom_divisor, close_delay;
upf_t old_flags, new_flags;
int retval = 0;
new_port = new_info->port;
if (HIGH_BITS_OFFSET)
new_port += (unsigned long) new_info->port_high << HIGH_BITS_OFFSET;
new_info->irq = irq_canonicalize(new_info->irq);
close_delay = msecs_to_jiffies(new_info->close_delay * 10);
closing_wait = new_info->closing_wait == ASYNC_CLOSING_WAIT_NONE ?
ASYNC_CLOSING_WAIT_NONE :
msecs_to_jiffies(new_info->closing_wait * 10);
change_irq = !(uport->flags & UPF_FIXED_PORT)
&& new_info->irq != uport->irq;
change_port = !(uport->flags & UPF_FIXED_PORT)
&& (new_port != uport->iobase ||
(unsigned long)new_info->iomem_base != uport->mapbase ||
new_info->hub6 != uport->hub6 ||
new_info->io_type != uport->iotype ||
new_info->iomem_reg_shift != uport->regshift ||
new_info->type != uport->type);
old_flags = uport->flags;
new_flags = new_info->flags;
old_custom_divisor = uport->custom_divisor;
if (!capable(CAP_SYS_ADMIN)) {
retval = -EPERM;
if (change_irq || change_port ||
(new_info->baud_base != uport->uartclk / 16) ||
(close_delay != port->close_delay) ||
(closing_wait != port->closing_wait) ||
(new_info->xmit_fifo_size &&
new_info->xmit_fifo_size != uport->fifosize) ||
(((new_flags ^ old_flags) & ~UPF_USR_MASK) != 0))
goto exit;
uport->flags = ((uport->flags & ~UPF_USR_MASK) |
(new_flags & UPF_USR_MASK));
uport->custom_divisor = new_info->custom_divisor;
goto check_and_exit;
}
if (uport->ops->verify_port)
retval = uport->ops->verify_port(uport, new_info);
if ((new_info->irq >= nr_irqs) || (new_info->irq < 0) ||
(new_info->baud_base < 9600))
retval = -EINVAL;
if (retval)
goto exit;
if (change_port || change_irq) {
retval = -EBUSY;
if (tty_port_users(port) > 1)
goto exit;
uart_shutdown(tty, state);
}
if (change_port) {
unsigned long old_iobase, old_mapbase;
unsigned int old_type, old_iotype, old_hub6, old_shift;
old_iobase = uport->iobase;
old_mapbase = uport->mapbase;
old_type = uport->type;
old_hub6 = uport->hub6;
old_iotype = uport->iotype;
old_shift = uport->regshift;
if (old_type != PORT_UNKNOWN)
uport->ops->release_port(uport);
uport->iobase = new_port;
uport->type = new_info->type;
uport->hub6 = new_info->hub6;
uport->iotype = new_info->io_type;
uport->regshift = new_info->iomem_reg_shift;
uport->mapbase = (unsigned long)new_info->iomem_base;
if (uport->type != PORT_UNKNOWN) {
retval = uport->ops->request_port(uport);
} else {
retval = 0;
}
if (retval) {
uport->iobase = old_iobase;
uport->type = old_type;
uport->hub6 = old_hub6;
uport->iotype = old_iotype;
uport->regshift = old_shift;
uport->mapbase = old_mapbase;
if (old_type != PORT_UNKNOWN) {
retval = uport->ops->request_port(uport);
if (retval)
uport->type = PORT_UNKNOWN;
retval = -EBUSY;
}
goto exit;
}
}
if (change_irq)
uport->irq = new_info->irq;
if (!(uport->flags & UPF_FIXED_PORT))
uport->uartclk = new_info->baud_base * 16;
uport->flags = (uport->flags & ~UPF_CHANGE_MASK) |
(new_flags & UPF_CHANGE_MASK);
uport->custom_divisor = new_info->custom_divisor;
port->close_delay = close_delay;
port->closing_wait = closing_wait;
if (new_info->xmit_fifo_size)
uport->fifosize = new_info->xmit_fifo_size;
port->low_latency = (uport->flags & UPF_LOW_LATENCY) ? 1 : 0;
check_and_exit:
retval = 0;
if (uport->type == PORT_UNKNOWN)
goto exit;
if (port->flags & ASYNC_INITIALIZED) {
if (((old_flags ^ uport->flags) & UPF_SPD_MASK) ||
old_custom_divisor != uport->custom_divisor) {
if (uport->flags & UPF_SPD_MASK) {
dev_notice(uport->dev,
"%s sets custom speed on %s. This is deprecated.\n",
current->comm,
tty_name(port->tty));
}
uart_change_speed(tty, state, NULL);
}
} else
retval = uart_startup(tty, state, 1);
exit:
return retval;
}
static int uart_set_info_user(struct tty_struct *tty, struct uart_state *state,
struct serial_struct __user *newinfo)
{
struct serial_struct new_serial;
struct tty_port *port = &state->port;
int retval;
if (copy_from_user(&new_serial, newinfo, sizeof(new_serial)))
return -EFAULT;
mutex_lock(&port->mutex);
retval = uart_set_info(tty, port, state, &new_serial);
mutex_unlock(&port->mutex);
return retval;
}
static int uart_get_lsr_info(struct tty_struct *tty,
struct uart_state *state, unsigned int __user *value)
{
struct uart_port *uport = state->uart_port;
unsigned int result;
result = uport->ops->tx_empty(uport);
if (uport->x_char ||
((uart_circ_chars_pending(&state->xmit) > 0) &&
!uart_tx_stopped(uport)))
result &= ~TIOCSER_TEMT;
return put_user(result, value);
}
static int uart_tiocmget(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
struct tty_port *port = &state->port;
struct uart_port *uport = state->uart_port;
int result = -EIO;
mutex_lock(&port->mutex);
if (!(tty->flags & (1 << TTY_IO_ERROR))) {
result = uport->mctrl;
spin_lock_irq(&uport->lock);
result |= uport->ops->get_mctrl(uport);
spin_unlock_irq(&uport->lock);
}
mutex_unlock(&port->mutex);
return result;
}
static int
uart_tiocmset(struct tty_struct *tty, unsigned int set, unsigned int clear)
{
struct uart_state *state = tty->driver_data;
struct uart_port *uport = state->uart_port;
struct tty_port *port = &state->port;
int ret = -EIO;
mutex_lock(&port->mutex);
if (!(tty->flags & (1 << TTY_IO_ERROR))) {
uart_update_mctrl(uport, set, clear);
ret = 0;
}
mutex_unlock(&port->mutex);
return ret;
}
static int uart_break_ctl(struct tty_struct *tty, int break_state)
{
struct uart_state *state = tty->driver_data;
struct tty_port *port = &state->port;
struct uart_port *uport = state->uart_port;
mutex_lock(&port->mutex);
if (uport->type != PORT_UNKNOWN)
uport->ops->break_ctl(uport, break_state);
mutex_unlock(&port->mutex);
return 0;
}
static int uart_do_autoconfig(struct tty_struct *tty,struct uart_state *state)
{
struct uart_port *uport = state->uart_port;
struct tty_port *port = &state->port;
int flags, ret;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (mutex_lock_interruptible(&port->mutex))
return -ERESTARTSYS;
ret = -EBUSY;
if (tty_port_users(port) == 1) {
uart_shutdown(tty, state);
if (uport->type != PORT_UNKNOWN)
uport->ops->release_port(uport);
flags = UART_CONFIG_TYPE;
if (uport->flags & UPF_AUTO_IRQ)
flags |= UART_CONFIG_IRQ;
uport->ops->config_port(uport, flags);
ret = uart_startup(tty, state, 1);
}
mutex_unlock(&port->mutex);
return ret;
}
static void uart_enable_ms(struct uart_port *uport)
{
if (uport->ops->enable_ms)
uport->ops->enable_ms(uport);
}
static int
uart_wait_modem_status(struct uart_state *state, unsigned long arg)
{
struct uart_port *uport = state->uart_port;
struct tty_port *port = &state->port;
DECLARE_WAITQUEUE(wait, current);
struct uart_icount cprev, cnow;
int ret;
spin_lock_irq(&uport->lock);
memcpy(&cprev, &uport->icount, sizeof(struct uart_icount));
uart_enable_ms(uport);
spin_unlock_irq(&uport->lock);
add_wait_queue(&port->delta_msr_wait, &wait);
for (;;) {
spin_lock_irq(&uport->lock);
memcpy(&cnow, &uport->icount, sizeof(struct uart_icount));
spin_unlock_irq(&uport->lock);
set_current_state(TASK_INTERRUPTIBLE);
if (((arg & TIOCM_RNG) && (cnow.rng != cprev.rng)) ||
((arg & TIOCM_DSR) && (cnow.dsr != cprev.dsr)) ||
((arg & TIOCM_CD) && (cnow.dcd != cprev.dcd)) ||
((arg & TIOCM_CTS) && (cnow.cts != cprev.cts))) {
ret = 0;
break;
}
schedule();
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
cprev = cnow;
}
__set_current_state(TASK_RUNNING);
remove_wait_queue(&port->delta_msr_wait, &wait);
return ret;
}
static int uart_get_icount(struct tty_struct *tty,
struct serial_icounter_struct *icount)
{
struct uart_state *state = tty->driver_data;
struct uart_icount cnow;
struct uart_port *uport = state->uart_port;
spin_lock_irq(&uport->lock);
memcpy(&cnow, &uport->icount, sizeof(struct uart_icount));
spin_unlock_irq(&uport->lock);
icount->cts = cnow.cts;
icount->dsr = cnow.dsr;
icount->rng = cnow.rng;
icount->dcd = cnow.dcd;
icount->rx = cnow.rx;
icount->tx = cnow.tx;
icount->frame = cnow.frame;
icount->overrun = cnow.overrun;
icount->parity = cnow.parity;
icount->brk = cnow.brk;
icount->buf_overrun = cnow.buf_overrun;
return 0;
}
static int uart_get_rs485_config(struct uart_port *port,
struct serial_rs485 __user *rs485)
{
unsigned long flags;
struct serial_rs485 aux;
spin_lock_irqsave(&port->lock, flags);
aux = port->rs485;
spin_unlock_irqrestore(&port->lock, flags);
if (copy_to_user(rs485, &aux, sizeof(aux)))
return -EFAULT;
return 0;
}
static int uart_set_rs485_config(struct uart_port *port,
struct serial_rs485 __user *rs485_user)
{
struct serial_rs485 rs485;
int ret;
unsigned long flags;
if (!port->rs485_config)
return -ENOIOCTLCMD;
if (copy_from_user(&rs485, rs485_user, sizeof(*rs485_user)))
return -EFAULT;
spin_lock_irqsave(&port->lock, flags);
ret = port->rs485_config(port, &rs485);
spin_unlock_irqrestore(&port->lock, flags);
if (ret)
return ret;
if (copy_to_user(rs485_user, &port->rs485, sizeof(port->rs485)))
return -EFAULT;
return 0;
}
static int
uart_ioctl(struct tty_struct *tty, unsigned int cmd,
unsigned long arg)
{
struct uart_state *state = tty->driver_data;
struct tty_port *port = &state->port;
void __user *uarg = (void __user *)arg;
int ret = -ENOIOCTLCMD;
switch (cmd) {
case TIOCGSERIAL:
ret = uart_get_info_user(port, uarg);
break;
case TIOCSSERIAL:
down_write(&tty->termios_rwsem);
ret = uart_set_info_user(tty, state, uarg);
up_write(&tty->termios_rwsem);
break;
case TIOCSERCONFIG:
down_write(&tty->termios_rwsem);
ret = uart_do_autoconfig(tty, state);
up_write(&tty->termios_rwsem);
break;
case TIOCSERGWILD:
case TIOCSERSWILD:
ret = 0;
break;
}
if (ret != -ENOIOCTLCMD)
goto out;
if (tty->flags & (1 << TTY_IO_ERROR)) {
ret = -EIO;
goto out;
}
switch (cmd) {
case TIOCMIWAIT:
ret = uart_wait_modem_status(state, arg);
break;
}
if (ret != -ENOIOCTLCMD)
goto out;
mutex_lock(&port->mutex);
if (tty->flags & (1 << TTY_IO_ERROR)) {
ret = -EIO;
goto out_up;
}
switch (cmd) {
case TIOCSERGETLSR:
ret = uart_get_lsr_info(tty, state, uarg);
break;
case TIOCGRS485:
ret = uart_get_rs485_config(state->uart_port, uarg);
break;
case TIOCSRS485:
ret = uart_set_rs485_config(state->uart_port, uarg);
break;
default: {
struct uart_port *uport = state->uart_port;
if (uport->ops->ioctl)
ret = uport->ops->ioctl(uport, cmd, arg);
break;
}
}
out_up:
mutex_unlock(&port->mutex);
out:
return ret;
}
static void uart_set_ldisc(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
struct uart_port *uport = state->uart_port;
if (uport->ops->set_ldisc) {
mutex_lock(&state->port.mutex);
uport->ops->set_ldisc(uport, &tty->termios);
mutex_unlock(&state->port.mutex);
}
}
static void uart_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct uart_state *state = tty->driver_data;
struct uart_port *uport = state->uart_port;
unsigned int cflag = tty->termios.c_cflag;
unsigned int iflag_mask = IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK;
bool sw_changed = false;
if (uport->flags & UPF_SOFT_FLOW) {
iflag_mask |= IXANY|IXON|IXOFF;
sw_changed =
tty->termios.c_cc[VSTART] != old_termios->c_cc[VSTART] ||
tty->termios.c_cc[VSTOP] != old_termios->c_cc[VSTOP];
}
if ((cflag ^ old_termios->c_cflag) == 0 &&
tty->termios.c_ospeed == old_termios->c_ospeed &&
tty->termios.c_ispeed == old_termios->c_ispeed &&
((tty->termios.c_iflag ^ old_termios->c_iflag) & iflag_mask) == 0 &&
!sw_changed) {
return;
}
mutex_lock(&state->port.mutex);
uart_change_speed(tty, state, old_termios);
mutex_unlock(&state->port.mutex);
cflag = tty->termios.c_cflag;
if ((old_termios->c_cflag & CBAUD) && !(cflag & CBAUD))
uart_clear_mctrl(uport, TIOCM_RTS | TIOCM_DTR);
else if (!(old_termios->c_cflag & CBAUD) && (cflag & CBAUD)) {
unsigned int mask = TIOCM_DTR;
if (!(cflag & CRTSCTS) || !test_bit(TTY_THROTTLED, &tty->flags))
mask |= TIOCM_RTS;
uart_set_mctrl(uport, mask);
}
}
static void uart_close(struct tty_struct *tty, struct file *filp)
{
struct uart_state *state = tty->driver_data;
struct tty_port *port;
struct uart_port *uport;
if (!state) {
struct uart_driver *drv = tty->driver->driver_state;
state = drv->state + tty->index;
port = &state->port;
spin_lock_irq(&port->lock);
--port->count;
spin_unlock_irq(&port->lock);
return;
}
uport = state->uart_port;
port = &state->port;
pr_debug("uart_close(%d) called\n", tty->index);
if (!port->count || tty_port_close_start(port, tty, filp) == 0)
return;
if (port->flags & ASYNC_INITIALIZED) {
spin_lock_irq(&uport->lock);
uport->ops->stop_rx(uport);
spin_unlock_irq(&uport->lock);
uart_wait_until_sent(tty, uport->timeout);
}
mutex_lock(&port->mutex);
uart_shutdown(tty, state);
tty_port_tty_set(port, NULL);
spin_lock_irq(&port->lock);
if (port->blocked_open) {
spin_unlock_irq(&port->lock);
if (port->close_delay)
msleep_interruptible(jiffies_to_msecs(port->close_delay));
spin_lock_irq(&port->lock);
} else if (!uart_console(uport)) {
spin_unlock_irq(&port->lock);
uart_change_pm(state, UART_PM_STATE_OFF);
spin_lock_irq(&port->lock);
}
clear_bit(ASYNCB_NORMAL_ACTIVE, &port->flags);
spin_unlock_irq(&port->lock);
wake_up_interruptible(&port->open_wait);
mutex_unlock(&port->mutex);
tty_ldisc_flush(tty);
tty->closing = 0;
}
static void uart_wait_until_sent(struct tty_struct *tty, int timeout)
{
struct uart_state *state = tty->driver_data;
struct uart_port *port = state->uart_port;
unsigned long char_time, expire;
if (port->type == PORT_UNKNOWN || port->fifosize == 0)
return;
char_time = (port->timeout - HZ/50) / port->fifosize;
char_time = char_time / 5;
if (char_time == 0)
char_time = 1;
if (timeout && timeout < char_time)
char_time = timeout;
if (timeout == 0 || timeout > 2 * port->timeout)
timeout = 2 * port->timeout;
expire = jiffies + timeout;
pr_debug("uart_wait_until_sent(%d), jiffies=%lu, expire=%lu...\n",
port->line, jiffies, expire);
while (!port->ops->tx_empty(port)) {
msleep_interruptible(jiffies_to_msecs(char_time));
if (signal_pending(current))
break;
if (time_after(jiffies, expire))
break;
}
}
static void uart_hangup(struct tty_struct *tty)
{
struct uart_state *state = tty->driver_data;
struct tty_port *port = &state->port;
unsigned long flags;
pr_debug("uart_hangup(%d)\n", tty->index);
mutex_lock(&port->mutex);
if (port->flags & ASYNC_NORMAL_ACTIVE) {
uart_flush_buffer(tty);
uart_shutdown(tty, state);
spin_lock_irqsave(&port->lock, flags);
port->count = 0;
clear_bit(ASYNCB_NORMAL_ACTIVE, &port->flags);
spin_unlock_irqrestore(&port->lock, flags);
tty_port_tty_set(port, NULL);
if (!uart_console(state->uart_port))
uart_change_pm(state, UART_PM_STATE_OFF);
wake_up_interruptible(&port->open_wait);
wake_up_interruptible(&port->delta_msr_wait);
}
mutex_unlock(&port->mutex);
}
static void uart_port_shutdown(struct tty_port *port)
{
struct uart_state *state = container_of(port, struct uart_state, port);
struct uart_port *uport = state->uart_port;
wake_up_interruptible(&port->delta_msr_wait);
uport->ops->shutdown(uport);
synchronize_irq(uport->irq);
}
static int uart_carrier_raised(struct tty_port *port)
{
struct uart_state *state = container_of(port, struct uart_state, port);
struct uart_port *uport = state->uart_port;
int mctrl;
spin_lock_irq(&uport->lock);
uart_enable_ms(uport);
mctrl = uport->ops->get_mctrl(uport);
spin_unlock_irq(&uport->lock);
if (mctrl & TIOCM_CAR)
return 1;
return 0;
}
static void uart_dtr_rts(struct tty_port *port, int onoff)
{
struct uart_state *state = container_of(port, struct uart_state, port);
struct uart_port *uport = state->uart_port;
if (onoff)
uart_set_mctrl(uport, TIOCM_DTR | TIOCM_RTS);
else
uart_clear_mctrl(uport, TIOCM_DTR | TIOCM_RTS);
}
static int uart_open(struct tty_struct *tty, struct file *filp)
{
struct uart_driver *drv = tty->driver->driver_state;
int retval, line = tty->index;
struct uart_state *state = drv->state + line;
struct tty_port *port = &state->port;
pr_debug("uart_open(%d) called\n", line);
spin_lock_irq(&port->lock);
++port->count;
spin_unlock_irq(&port->lock);
if (mutex_lock_interruptible(&port->mutex)) {
retval = -ERESTARTSYS;
goto end;
}
if (!state->uart_port || state->uart_port->flags & UPF_DEAD) {
retval = -ENXIO;
goto err_unlock;
}
tty->driver_data = state;
state->uart_port->state = state;
state->port.low_latency =
(state->uart_port->flags & UPF_LOW_LATENCY) ? 1 : 0;
tty_port_tty_set(port, tty);
retval = uart_startup(tty, state, 0);
err_unlock:
mutex_unlock(&port->mutex);
if (retval == 0)
retval = tty_port_block_til_ready(port, tty, filp);
end:
return retval;
}
static const char *uart_type(struct uart_port *port)
{
const char *str = NULL;
if (port->ops->type)
str = port->ops->type(port);
if (!str)
str = "unknown";
return str;
}
static void uart_line_info(struct seq_file *m, struct uart_driver *drv, int i)
{
struct uart_state *state = drv->state + i;
struct tty_port *port = &state->port;
enum uart_pm_state pm_state;
struct uart_port *uport = state->uart_port;
char stat_buf[32];
unsigned int status;
int mmio;
if (!uport)
return;
mmio = uport->iotype >= UPIO_MEM;
seq_printf(m, "%d: uart:%s %s%08llX irq:%d",
uport->line, uart_type(uport),
mmio ? "mmio:0x" : "port:",
mmio ? (unsigned long long)uport->mapbase
: (unsigned long long)uport->iobase,
uport->irq);
if (uport->type == PORT_UNKNOWN) {
seq_putc(m, '\n');
return;
}
if (capable(CAP_SYS_ADMIN)) {
mutex_lock(&port->mutex);
pm_state = state->pm_state;
if (pm_state != UART_PM_STATE_ON)
uart_change_pm(state, UART_PM_STATE_ON);
spin_lock_irq(&uport->lock);
status = uport->ops->get_mctrl(uport);
spin_unlock_irq(&uport->lock);
if (pm_state != UART_PM_STATE_ON)
uart_change_pm(state, pm_state);
mutex_unlock(&port->mutex);
seq_printf(m, " tx:%d rx:%d",
uport->icount.tx, uport->icount.rx);
if (uport->icount.frame)
seq_printf(m, " fe:%d", uport->icount.frame);
if (uport->icount.parity)
seq_printf(m, " pe:%d", uport->icount.parity);
if (uport->icount.brk)
seq_printf(m, " brk:%d", uport->icount.brk);
if (uport->icount.overrun)
seq_printf(m, " oe:%d", uport->icount.overrun);
#define INFOBIT(bit, str) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define STATBIT(bit, str) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
stat_buf[0] = '\0';
stat_buf[1] = '\0';
INFOBIT(TIOCM_RTS, "|RTS");
STATBIT(TIOCM_CTS, "|CTS");
INFOBIT(TIOCM_DTR, "|DTR");
STATBIT(TIOCM_DSR, "|DSR");
STATBIT(TIOCM_CAR, "|CD");
STATBIT(TIOCM_RNG, "|RI");
if (stat_buf[0])
stat_buf[0] = ' ';
seq_puts(m, stat_buf);
}
seq_putc(m, '\n');
#undef STATBIT
#undef INFOBIT
}
static int uart_proc_show(struct seq_file *m, void *v)
{
struct tty_driver *ttydrv = m->private;
struct uart_driver *drv = ttydrv->driver_state;
int i;
seq_printf(m, "serinfo:1.0 driver%s%s revision:%s\n", "", "", "");
for (i = 0; i < drv->nr; i++)
uart_line_info(m, drv, i);
return 0;
}
static int uart_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, uart_proc_show, PDE_DATA(inode));
}
void uart_console_write(struct uart_port *port, const char *s,
unsigned int count,
void (*putchar)(struct uart_port *, int))
{
unsigned int i;
for (i = 0; i < count; i++, s++) {
if (*s == '\n')
putchar(port, '\r');
putchar(port, *s);
}
}
struct uart_port * __init
uart_get_console(struct uart_port *ports, int nr, struct console *co)
{
int idx = co->index;
if (idx < 0 || idx >= nr || (ports[idx].iobase == 0 &&
ports[idx].membase == NULL))
for (idx = 0; idx < nr; idx++)
if (ports[idx].iobase != 0 ||
ports[idx].membase != NULL)
break;
co->index = idx;
return ports + idx;
}
int uart_parse_earlycon(char *p, unsigned char *iotype, unsigned long *addr,
char **options)
{
if (strncmp(p, "mmio,", 5) == 0) {
*iotype = UPIO_MEM;
p += 5;
} else if (strncmp(p, "mmio16,", 7) == 0) {
*iotype = UPIO_MEM16;
p += 7;
} else if (strncmp(p, "mmio32,", 7) == 0) {
*iotype = UPIO_MEM32;
p += 7;
} else if (strncmp(p, "mmio32be,", 9) == 0) {
*iotype = UPIO_MEM32BE;
p += 9;
} else if (strncmp(p, "mmio32native,", 13) == 0) {
*iotype = IS_ENABLED(CONFIG_CPU_BIG_ENDIAN) ?
UPIO_MEM32BE : UPIO_MEM32;
p += 13;
} else if (strncmp(p, "io,", 3) == 0) {
*iotype = UPIO_PORT;
p += 3;
} else if (strncmp(p, "0x", 2) == 0) {
*iotype = UPIO_MEM;
} else {
return -EINVAL;
}
*addr = simple_strtoul(p, NULL, 0);
p = strchr(p, ',');
if (p)
p++;
*options = p;
return 0;
}
void
uart_parse_options(char *options, int *baud, int *parity, int *bits, int *flow)
{
char *s = options;
*baud = simple_strtoul(s, NULL, 10);
while (*s >= '0' && *s <= '9')
s++;
if (*s)
*parity = *s++;
if (*s)
*bits = *s++ - '0';
if (*s)
*flow = *s;
}
int
uart_set_options(struct uart_port *port, struct console *co,
int baud, int parity, int bits, int flow)
{
struct ktermios termios;
static struct ktermios dummy;
if (!(uart_console(port) && (port->cons->flags & CON_ENABLED))) {
spin_lock_init(&port->lock);
lockdep_set_class(&port->lock, &port_lock_key);
}
memset(&termios, 0, sizeof(struct ktermios));
termios.c_cflag |= CREAD | HUPCL | CLOCAL;
tty_termios_encode_baud_rate(&termios, baud, baud);
if (bits == 7)
termios.c_cflag |= CS7;
else
termios.c_cflag |= CS8;
switch (parity) {
case 'o': case 'O':
termios.c_cflag |= PARODD;
case 'e': case 'E':
termios.c_cflag |= PARENB;
break;
}
if (flow == 'r')
termios.c_cflag |= CRTSCTS;
port->mctrl |= TIOCM_DTR;
port->ops->set_termios(port, &termios, &dummy);
if (co)
co->cflag = termios.c_cflag;
return 0;
}
static void uart_change_pm(struct uart_state *state,
enum uart_pm_state pm_state)
{
struct uart_port *port = state->uart_port;
if (state->pm_state != pm_state) {
if (port->ops->pm)
port->ops->pm(port, pm_state, state->pm_state);
state->pm_state = pm_state;
}
}
static int serial_match_port(struct device *dev, void *data)
{
struct uart_match *match = data;
struct tty_driver *tty_drv = match->driver->tty_driver;
dev_t devt = MKDEV(tty_drv->major, tty_drv->minor_start) +
match->port->line;
return dev->devt == devt;
}
int uart_suspend_port(struct uart_driver *drv, struct uart_port *uport)
{
struct uart_state *state = drv->state + uport->line;
struct tty_port *port = &state->port;
struct device *tty_dev;
struct uart_match match = {uport, drv};
mutex_lock(&port->mutex);
tty_dev = device_find_child(uport->dev, &match, serial_match_port);
if (device_may_wakeup(tty_dev)) {
if (!enable_irq_wake(uport->irq))
uport->irq_wake = 1;
put_device(tty_dev);
mutex_unlock(&port->mutex);
return 0;
}
put_device(tty_dev);
if (!console_suspend_enabled && uart_console(uport))
goto unlock;
uport->suspended = 1;
if (port->flags & ASYNC_INITIALIZED) {
const struct uart_ops *ops = uport->ops;
int tries;
set_bit(ASYNCB_SUSPENDED, &port->flags);
clear_bit(ASYNCB_INITIALIZED, &port->flags);
spin_lock_irq(&uport->lock);
ops->stop_tx(uport);
ops->set_mctrl(uport, 0);
ops->stop_rx(uport);
spin_unlock_irq(&uport->lock);
for (tries = 3; !ops->tx_empty(uport) && tries; tries--)
msleep(10);
if (!tries)
dev_err(uport->dev, "%s%d: Unable to drain transmitter\n",
drv->dev_name,
drv->tty_driver->name_base + uport->line);
ops->shutdown(uport);
}
if (uart_console(uport))
console_stop(uport->cons);
uart_change_pm(state, UART_PM_STATE_OFF);
unlock:
mutex_unlock(&port->mutex);
return 0;
}
int uart_resume_port(struct uart_driver *drv, struct uart_port *uport)
{
struct uart_state *state = drv->state + uport->line;
struct tty_port *port = &state->port;
struct device *tty_dev;
struct uart_match match = {uport, drv};
struct ktermios termios;
mutex_lock(&port->mutex);
tty_dev = device_find_child(uport->dev, &match, serial_match_port);
if (!uport->suspended && device_may_wakeup(tty_dev)) {
if (uport->irq_wake) {
disable_irq_wake(uport->irq);
uport->irq_wake = 0;
}
put_device(tty_dev);
mutex_unlock(&port->mutex);
return 0;
}
put_device(tty_dev);
uport->suspended = 0;
if (uart_console(uport)) {
memset(&termios, 0, sizeof(struct ktermios));
termios.c_cflag = uport->cons->cflag;
if (port->tty && termios.c_cflag == 0)
termios = port->tty->termios;
if (console_suspend_enabled)
uart_change_pm(state, UART_PM_STATE_ON);
uport->ops->set_termios(uport, &termios, NULL);
if (console_suspend_enabled)
console_start(uport->cons);
}
if (port->flags & ASYNC_SUSPENDED) {
const struct uart_ops *ops = uport->ops;
int ret;
uart_change_pm(state, UART_PM_STATE_ON);
spin_lock_irq(&uport->lock);
ops->set_mctrl(uport, 0);
spin_unlock_irq(&uport->lock);
if (console_suspend_enabled || !uart_console(uport)) {
struct tty_struct *tty = port->tty;
ret = ops->startup(uport);
if (ret == 0) {
if (tty)
uart_change_speed(tty, state, NULL);
spin_lock_irq(&uport->lock);
ops->set_mctrl(uport, uport->mctrl);
ops->start_tx(uport);
spin_unlock_irq(&uport->lock);
set_bit(ASYNCB_INITIALIZED, &port->flags);
} else {
uart_shutdown(tty, state);
}
}
clear_bit(ASYNCB_SUSPENDED, &port->flags);
}
mutex_unlock(&port->mutex);
return 0;
}
static inline void
uart_report_port(struct uart_driver *drv, struct uart_port *port)
{
char address[64];
switch (port->iotype) {
case UPIO_PORT:
snprintf(address, sizeof(address), "I/O 0x%lx", port->iobase);
break;
case UPIO_HUB6:
snprintf(address, sizeof(address),
"I/O 0x%lx offset 0x%x", port->iobase, port->hub6);
break;
case UPIO_MEM:
case UPIO_MEM16:
case UPIO_MEM32:
case UPIO_MEM32BE:
case UPIO_AU:
case UPIO_TSI:
snprintf(address, sizeof(address),
"MMIO 0x%llx", (unsigned long long)port->mapbase);
break;
default:
strlcpy(address, "*unknown*", sizeof(address));
break;
}
printk(KERN_INFO "%s%s%s%d at %s (irq = %d, base_baud = %d) is a %s\n",
port->dev ? dev_name(port->dev) : "",
port->dev ? ": " : "",
drv->dev_name,
drv->tty_driver->name_base + port->line,
address, port->irq, port->uartclk / 16, uart_type(port));
}
static void
uart_configure_port(struct uart_driver *drv, struct uart_state *state,
struct uart_port *port)
{
unsigned int flags;
if (!port->iobase && !port->mapbase && !port->membase)
return;
flags = 0;
if (port->flags & UPF_AUTO_IRQ)
flags |= UART_CONFIG_IRQ;
if (port->flags & UPF_BOOT_AUTOCONF) {
if (!(port->flags & UPF_FIXED_TYPE)) {
port->type = PORT_UNKNOWN;
flags |= UART_CONFIG_TYPE;
}
port->ops->config_port(port, flags);
}
if (port->type != PORT_UNKNOWN) {
unsigned long flags;
uart_report_port(drv, port);
uart_change_pm(state, UART_PM_STATE_ON);
spin_lock_irqsave(&port->lock, flags);
port->ops->set_mctrl(port, port->mctrl & TIOCM_DTR);
spin_unlock_irqrestore(&port->lock, flags);
if (port->cons && !(port->cons->flags & CON_ENABLED))
register_console(port->cons);
if (!uart_console(port))
uart_change_pm(state, UART_PM_STATE_OFF);
}
}
static int uart_poll_init(struct tty_driver *driver, int line, char *options)
{
struct uart_driver *drv = driver->driver_state;
struct uart_state *state = drv->state + line;
struct uart_port *port;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
int ret;
if (!state || !state->uart_port)
return -1;
port = state->uart_port;
if (!(port->ops->poll_get_char && port->ops->poll_put_char))
return -1;
if (port->ops->poll_init) {
struct tty_port *tport = &state->port;
ret = 0;
mutex_lock(&tport->mutex);
if (!test_bit(ASYNCB_INITIALIZED, &tport->flags))
ret = port->ops->poll_init(port);
mutex_unlock(&tport->mutex);
if (ret)
return ret;
}
if (options) {
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, NULL, baud, parity, bits, flow);
}
return 0;
}
static int uart_poll_get_char(struct tty_driver *driver, int line)
{
struct uart_driver *drv = driver->driver_state;
struct uart_state *state = drv->state + line;
struct uart_port *port;
if (!state || !state->uart_port)
return -1;
port = state->uart_port;
return port->ops->poll_get_char(port);
}
static void uart_poll_put_char(struct tty_driver *driver, int line, char ch)
{
struct uart_driver *drv = driver->driver_state;
struct uart_state *state = drv->state + line;
struct uart_port *port;
if (!state || !state->uart_port)
return;
port = state->uart_port;
if (ch == '\n')
port->ops->poll_put_char(port, '\r');
port->ops->poll_put_char(port, ch);
}
int uart_register_driver(struct uart_driver *drv)
{
struct tty_driver *normal;
int i, retval;
BUG_ON(drv->state);
drv->state = kzalloc(sizeof(struct uart_state) * drv->nr, GFP_KERNEL);
if (!drv->state)
goto out;
normal = alloc_tty_driver(drv->nr);
if (!normal)
goto out_kfree;
drv->tty_driver = normal;
normal->driver_name = drv->driver_name;
normal->name = drv->dev_name;
normal->major = drv->major;
normal->minor_start = drv->minor;
normal->type = TTY_DRIVER_TYPE_SERIAL;
normal->subtype = SERIAL_TYPE_NORMAL;
normal->init_termios = tty_std_termios;
normal->init_termios.c_cflag = B9600 | CS8 | CREAD | HUPCL | CLOCAL;
normal->init_termios.c_ispeed = normal->init_termios.c_ospeed = 9600;
normal->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
normal->driver_state = drv;
tty_set_operations(normal, &uart_ops);
for (i = 0; i < drv->nr; i++) {
struct uart_state *state = drv->state + i;
struct tty_port *port = &state->port;
tty_port_init(port);
port->ops = &uart_port_ops;
}
retval = tty_register_driver(normal);
if (retval >= 0)
return retval;
for (i = 0; i < drv->nr; i++)
tty_port_destroy(&drv->state[i].port);
put_tty_driver(normal);
out_kfree:
kfree(drv->state);
out:
return -ENOMEM;
}
void uart_unregister_driver(struct uart_driver *drv)
{
struct tty_driver *p = drv->tty_driver;
unsigned int i;
tty_unregister_driver(p);
put_tty_driver(p);
for (i = 0; i < drv->nr; i++)
tty_port_destroy(&drv->state[i].port);
kfree(drv->state);
drv->state = NULL;
drv->tty_driver = NULL;
}
struct tty_driver *uart_console_device(struct console *co, int *index)
{
struct uart_driver *p = co->data;
*index = co->index;
return p->tty_driver;
}
static ssize_t uart_get_attr_uartclk(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.baud_base * 16);
}
static ssize_t uart_get_attr_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.type);
}
static ssize_t uart_get_attr_line(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.line);
}
static ssize_t uart_get_attr_port(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
unsigned long ioaddr;
uart_get_info(port, &tmp);
ioaddr = tmp.port;
if (HIGH_BITS_OFFSET)
ioaddr |= (unsigned long)tmp.port_high << HIGH_BITS_OFFSET;
return snprintf(buf, PAGE_SIZE, "0x%lX\n", ioaddr);
}
static ssize_t uart_get_attr_irq(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.irq);
}
static ssize_t uart_get_attr_flags(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "0x%X\n", tmp.flags);
}
static ssize_t uart_get_attr_xmit_fifo_size(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.xmit_fifo_size);
}
static ssize_t uart_get_attr_close_delay(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.close_delay);
}
static ssize_t uart_get_attr_closing_wait(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.closing_wait);
}
static ssize_t uart_get_attr_custom_divisor(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.custom_divisor);
}
static ssize_t uart_get_attr_io_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.io_type);
}
static ssize_t uart_get_attr_iomem_base(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "0x%lX\n", (unsigned long)tmp.iomem_base);
}
static ssize_t uart_get_attr_iomem_reg_shift(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct serial_struct tmp;
struct tty_port *port = dev_get_drvdata(dev);
uart_get_info(port, &tmp);
return snprintf(buf, PAGE_SIZE, "%d\n", tmp.iomem_reg_shift);
}
int uart_add_one_port(struct uart_driver *drv, struct uart_port *uport)
{
struct uart_state *state;
struct tty_port *port;
int ret = 0;
struct device *tty_dev;
int num_groups;
BUG_ON(in_interrupt());
if (uport->line >= drv->nr)
return -EINVAL;
state = drv->state + uport->line;
port = &state->port;
mutex_lock(&port_mutex);
mutex_lock(&port->mutex);
if (state->uart_port) {
ret = -EINVAL;
goto out;
}
state->uart_port = uport;
uport->state = state;
state->pm_state = UART_PM_STATE_UNDEFINED;
uport->cons = drv->cons;
uport->minor = drv->tty_driver->minor_start + uport->line;
if (!(uart_console(uport) && (uport->cons->flags & CON_ENABLED))) {
spin_lock_init(&uport->lock);
lockdep_set_class(&uport->lock, &port_lock_key);
}
if (uport->cons && uport->dev)
of_console_check(uport->dev->of_node, uport->cons->name, uport->line);
uart_configure_port(drv, state, uport);
num_groups = 2;
if (uport->attr_group)
num_groups++;
uport->tty_groups = kcalloc(num_groups, sizeof(*uport->tty_groups),
GFP_KERNEL);
if (!uport->tty_groups) {
ret = -ENOMEM;
goto out;
}
uport->tty_groups[0] = &tty_dev_attr_group;
if (uport->attr_group)
uport->tty_groups[1] = uport->attr_group;
tty_dev = tty_port_register_device_attr(port, drv->tty_driver,
uport->line, uport->dev, port, uport->tty_groups);
if (likely(!IS_ERR(tty_dev))) {
device_set_wakeup_capable(tty_dev, 1);
} else {
dev_err(uport->dev, "Cannot register tty device on line %d\n",
uport->line);
}
uport->flags &= ~UPF_DEAD;
out:
mutex_unlock(&port->mutex);
mutex_unlock(&port_mutex);
return ret;
}
int uart_remove_one_port(struct uart_driver *drv, struct uart_port *uport)
{
struct uart_state *state = drv->state + uport->line;
struct tty_port *port = &state->port;
struct tty_struct *tty;
int ret = 0;
BUG_ON(in_interrupt());
if (state->uart_port != uport)
dev_alert(uport->dev, "Removing wrong port: %p != %p\n",
state->uart_port, uport);
mutex_lock(&port_mutex);
mutex_lock(&port->mutex);
if (!state->uart_port) {
mutex_unlock(&port->mutex);
ret = -EINVAL;
goto out;
}
uport->flags |= UPF_DEAD;
mutex_unlock(&port->mutex);
tty_unregister_device(drv->tty_driver, uport->line);
tty = tty_port_tty_get(port);
if (tty) {
tty_vhangup(port->tty);
tty_kref_put(tty);
}
if (uart_console(uport))
unregister_console(uport->cons);
if (uport->type != PORT_UNKNOWN)
uport->ops->release_port(uport);
kfree(uport->tty_groups);
uport->type = PORT_UNKNOWN;
state->uart_port = NULL;
out:
mutex_unlock(&port_mutex);
return ret;
}
int uart_match_port(struct uart_port *port1, struct uart_port *port2)
{
if (port1->iotype != port2->iotype)
return 0;
switch (port1->iotype) {
case UPIO_PORT:
return (port1->iobase == port2->iobase);
case UPIO_HUB6:
return (port1->iobase == port2->iobase) &&
(port1->hub6 == port2->hub6);
case UPIO_MEM:
case UPIO_MEM16:
case UPIO_MEM32:
case UPIO_MEM32BE:
case UPIO_AU:
case UPIO_TSI:
return (port1->mapbase == port2->mapbase);
}
return 0;
}
void uart_handle_dcd_change(struct uart_port *uport, unsigned int status)
{
struct tty_port *port = &uport->state->port;
struct tty_struct *tty = port->tty;
struct tty_ldisc *ld;
lockdep_assert_held_once(&uport->lock);
if (tty) {
ld = tty_ldisc_ref(tty);
if (ld) {
if (ld->ops->dcd_change)
ld->ops->dcd_change(tty, status);
tty_ldisc_deref(ld);
}
}
uport->icount.dcd++;
if (uart_dcd_enabled(uport)) {
if (status)
wake_up_interruptible(&port->open_wait);
else if (tty)
tty_hangup(tty);
}
}
void uart_handle_cts_change(struct uart_port *uport, unsigned int status)
{
lockdep_assert_held_once(&uport->lock);
uport->icount.cts++;
if (uart_softcts_mode(uport)) {
if (uport->hw_stopped) {
if (status) {
uport->hw_stopped = 0;
uport->ops->start_tx(uport);
uart_write_wakeup(uport);
}
} else {
if (!status) {
uport->hw_stopped = 1;
uport->ops->stop_tx(uport);
}
}
}
}
void uart_insert_char(struct uart_port *port, unsigned int status,
unsigned int overrun, unsigned int ch, unsigned int flag)
{
struct tty_port *tport = &port->state->port;
if ((status & port->ignore_status_mask & ~overrun) == 0)
if (tty_insert_flip_char(tport, ch, flag) == 0)
++port->icount.buf_overrun;
if (status & ~port->ignore_status_mask & overrun)
if (tty_insert_flip_char(tport, 0, TTY_OVERRUN) == 0)
++port->icount.buf_overrun;
}
