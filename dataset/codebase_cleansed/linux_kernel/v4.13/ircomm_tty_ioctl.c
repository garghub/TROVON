static void ircomm_tty_change_speed(struct ircomm_tty_cb *self,
struct tty_struct *tty)
{
unsigned int cflag, cval;
int baud;
if (!self->ircomm)
return;
cflag = tty->termios.c_cflag;
switch (cflag & CSIZE) {
case CS5: cval = IRCOMM_WSIZE_5; break;
case CS6: cval = IRCOMM_WSIZE_6; break;
case CS7: cval = IRCOMM_WSIZE_7; break;
case CS8: cval = IRCOMM_WSIZE_8; break;
default: cval = IRCOMM_WSIZE_5; break;
}
if (cflag & CSTOPB)
cval |= IRCOMM_2_STOP_BIT;
if (cflag & PARENB)
cval |= IRCOMM_PARITY_ENABLE;
if (!(cflag & PARODD))
cval |= IRCOMM_PARITY_EVEN;
baud = tty_get_baud_rate(tty);
if (!baud)
baud = 9600;
self->settings.data_rate = baud;
ircomm_param_request(self, IRCOMM_DATA_RATE, FALSE);
tty_port_set_cts_flow(&self->port, cflag & CRTSCTS);
if (cflag & CRTSCTS) {
self->settings.flow_control |= IRCOMM_RTS_CTS_IN;
if (self->service_type == IRCOMM_3_WIRE_RAW)
net_warn_ratelimited("%s(), enabling RTS/CTS on link that doesn't support it (3-wire-raw)\n",
__func__);
} else {
self->settings.flow_control &= ~IRCOMM_RTS_CTS_IN;
}
tty_port_set_check_carrier(&self->port, ~cflag & CLOCAL);
self->settings.data_format = cval;
ircomm_param_request(self, IRCOMM_DATA_FORMAT, FALSE);
ircomm_param_request(self, IRCOMM_FLOW_CONTROL, TRUE);
}
void ircomm_tty_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
unsigned int cflag = tty->termios.c_cflag;
if ((cflag == old_termios->c_cflag) &&
(RELEVANT_IFLAG(tty->termios.c_iflag) ==
RELEVANT_IFLAG(old_termios->c_iflag)))
{
return;
}
ircomm_tty_change_speed(self, tty);
if ((old_termios->c_cflag & CBAUD) && !(cflag & CBAUD)) {
self->settings.dte &= ~(IRCOMM_DTR|IRCOMM_RTS);
ircomm_param_request(self, IRCOMM_DTE, TRUE);
}
if (!(old_termios->c_cflag & CBAUD) && (cflag & CBAUD)) {
self->settings.dte |= IRCOMM_DTR;
if (!C_CRTSCTS(tty) || !tty_throttled(tty))
self->settings.dte |= IRCOMM_RTS;
ircomm_param_request(self, IRCOMM_DTE, TRUE);
}
if ((old_termios->c_cflag & CRTSCTS) && !C_CRTSCTS(tty))
{
tty->hw_stopped = 0;
ircomm_tty_start(tty);
}
}
int ircomm_tty_tiocmget(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
unsigned int result;
if (tty_io_error(tty))
return -EIO;
result = ((self->settings.dte & IRCOMM_RTS) ? TIOCM_RTS : 0)
| ((self->settings.dte & IRCOMM_DTR) ? TIOCM_DTR : 0)
| ((self->settings.dce & IRCOMM_CD) ? TIOCM_CAR : 0)
| ((self->settings.dce & IRCOMM_RI) ? TIOCM_RNG : 0)
| ((self->settings.dce & IRCOMM_DSR) ? TIOCM_DSR : 0)
| ((self->settings.dce & IRCOMM_CTS) ? TIOCM_CTS : 0);
return result;
}
int ircomm_tty_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
if (tty_io_error(tty))
return -EIO;
IRDA_ASSERT(self != NULL, return -1;);
IRDA_ASSERT(self->magic == IRCOMM_TTY_MAGIC, return -1;);
if (set & TIOCM_RTS)
self->settings.dte |= IRCOMM_RTS;
if (set & TIOCM_DTR)
self->settings.dte |= IRCOMM_DTR;
if (clear & TIOCM_RTS)
self->settings.dte &= ~IRCOMM_RTS;
if (clear & TIOCM_DTR)
self->settings.dte &= ~IRCOMM_DTR;
if ((set|clear) & TIOCM_RTS)
self->settings.dte |= IRCOMM_DELTA_RTS;
if ((set|clear) & TIOCM_DTR)
self->settings.dte |= IRCOMM_DELTA_DTR;
ircomm_param_request(self, IRCOMM_DTE, TRUE);
return 0;
}
static int ircomm_tty_get_serial_info(struct ircomm_tty_cb *self,
struct serial_struct __user *retinfo)
{
struct serial_struct info;
memset(&info, 0, sizeof(info));
info.line = self->line;
info.flags = self->port.flags;
info.baud_base = self->settings.data_rate;
info.close_delay = self->port.close_delay;
info.closing_wait = self->port.closing_wait;
info.type = PORT_16550A;
if (copy_to_user(retinfo, &info, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int ircomm_tty_set_serial_info(struct ircomm_tty_cb *self,
struct serial_struct __user *new_info)
{
return 0;
}
int ircomm_tty_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
int ret = 0;
if ((cmd != TIOCGSERIAL) && (cmd != TIOCSSERIAL) &&
(cmd != TIOCSERCONFIG) && (cmd != TIOCSERGSTRUCT) &&
(cmd != TIOCMIWAIT) && (cmd != TIOCGICOUNT)) {
if (tty_io_error(tty))
return -EIO;
}
switch (cmd) {
case TIOCGSERIAL:
ret = ircomm_tty_get_serial_info(self, (struct serial_struct __user *) arg);
break;
case TIOCSSERIAL:
ret = ircomm_tty_set_serial_info(self, (struct serial_struct __user *) arg);
break;
case TIOCMIWAIT:
pr_debug("(), TIOCMIWAIT, not impl!\n");
break;
case TIOCGICOUNT:
pr_debug("%s(), TIOCGICOUNT not impl!\n", __func__);
return 0;
default:
ret = -ENOIOCTLCMD;
}
return ret;
}
