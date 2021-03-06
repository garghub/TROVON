static void ircomm_tty_change_speed(struct ircomm_tty_cb *self)
{
unsigned cflag, cval;
int baud;
IRDA_DEBUG(2, "%s()\n", __func__ );
if (!self->tty || !self->tty->termios || !self->ircomm)
return;
cflag = self->tty->termios->c_cflag;
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
baud = tty_get_baud_rate(self->tty);
if (!baud)
baud = 9600;
self->settings.data_rate = baud;
ircomm_param_request(self, IRCOMM_DATA_RATE, FALSE);
if (cflag & CRTSCTS) {
self->flags |= ASYNC_CTS_FLOW;
self->settings.flow_control |= IRCOMM_RTS_CTS_IN;
if (self->service_type == IRCOMM_3_WIRE_RAW)
IRDA_WARNING("%s(), enabling RTS/CTS on link that doesn't support it (3-wire-raw)\n", __func__);
} else {
self->flags &= ~ASYNC_CTS_FLOW;
self->settings.flow_control &= ~IRCOMM_RTS_CTS_IN;
}
if (cflag & CLOCAL)
self->flags &= ~ASYNC_CHECK_CD;
else
self->flags |= ASYNC_CHECK_CD;
#if 0
if (I_INPCK(self->tty))
driver->read_status_mask |= LSR_FE | LSR_PE;
if (I_BRKINT(driver->tty) || I_PARMRK(driver->tty))
driver->read_status_mask |= LSR_BI;
driver->ignore_status_mask = 0;
if (I_IGNPAR(driver->tty))
driver->ignore_status_mask |= LSR_PE | LSR_FE;
if (I_IGNBRK(self->tty)) {
self->ignore_status_mask |= LSR_BI;
if (I_IGNPAR(self->tty))
self->ignore_status_mask |= LSR_OE;
}
#endif
self->settings.data_format = cval;
ircomm_param_request(self, IRCOMM_DATA_FORMAT, FALSE);
ircomm_param_request(self, IRCOMM_FLOW_CONTROL, TRUE);
}
void ircomm_tty_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
unsigned int cflag = tty->termios->c_cflag;
IRDA_DEBUG(2, "%s()\n", __func__ );
if ((cflag == old_termios->c_cflag) &&
(RELEVANT_IFLAG(tty->termios->c_iflag) ==
RELEVANT_IFLAG(old_termios->c_iflag)))
{
return;
}
ircomm_tty_change_speed(self);
if ((old_termios->c_cflag & CBAUD) &&
!(cflag & CBAUD)) {
self->settings.dte &= ~(IRCOMM_DTR|IRCOMM_RTS);
ircomm_param_request(self, IRCOMM_DTE, TRUE);
}
if (!(old_termios->c_cflag & CBAUD) &&
(cflag & CBAUD)) {
self->settings.dte |= IRCOMM_DTR;
if (!(tty->termios->c_cflag & CRTSCTS) ||
!test_bit(TTY_THROTTLED, &tty->flags)) {
self->settings.dte |= IRCOMM_RTS;
}
ircomm_param_request(self, IRCOMM_DTE, TRUE);
}
if ((old_termios->c_cflag & CRTSCTS) &&
!(tty->termios->c_cflag & CRTSCTS))
{
tty->hw_stopped = 0;
ircomm_tty_start(tty);
}
}
int ircomm_tty_tiocmget(struct tty_struct *tty)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
unsigned int result;
IRDA_DEBUG(2, "%s()\n", __func__ );
if (tty->flags & (1 << TTY_IO_ERROR))
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
IRDA_DEBUG(2, "%s()\n", __func__ );
if (tty->flags & (1 << TTY_IO_ERROR))
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
if (!retinfo)
return -EFAULT;
IRDA_DEBUG(2, "%s()\n", __func__ );
memset(&info, 0, sizeof(info));
info.line = self->line;
info.flags = self->flags;
info.baud_base = self->settings.data_rate;
info.close_delay = self->close_delay;
info.closing_wait = self->closing_wait;
info.type = PORT_16550A;
info.port = 0;
info.irq = 0;
info.xmit_fifo_size = 0;
info.hub6 = 0;
info.custom_divisor = 0;
if (copy_to_user(retinfo, &info, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int ircomm_tty_set_serial_info(struct ircomm_tty_cb *self,
struct serial_struct __user *new_info)
{
#if 0
struct serial_struct new_serial;
struct ircomm_tty_cb old_state, *state;
IRDA_DEBUG(0, "%s()\n", __func__ );
if (copy_from_user(&new_serial,new_info,sizeof(new_serial)))
return -EFAULT;
state = self
old_state = *self;
if (!capable(CAP_SYS_ADMIN)) {
if ((new_serial.baud_base != state->settings.data_rate) ||
(new_serial.close_delay != state->close_delay) ||
((new_serial.flags & ~ASYNC_USR_MASK) !=
(self->flags & ~ASYNC_USR_MASK)))
return -EPERM;
state->flags = ((state->flags & ~ASYNC_USR_MASK) |
(new_serial.flags & ASYNC_USR_MASK));
self->flags = ((self->flags & ~ASYNC_USR_MASK) |
(new_serial.flags & ASYNC_USR_MASK));
goto check_and_exit;
}
if (self->settings.data_rate != new_serial.baud_base) {
self->settings.data_rate = new_serial.baud_base;
ircomm_param_request(self, IRCOMM_DATA_RATE, TRUE);
}
self->close_delay = new_serial.close_delay * HZ/100;
self->closing_wait = new_serial.closing_wait * HZ/100;
self->flags = ((self->flags & ~ASYNC_FLAGS) |
(new_serial.flags & ASYNC_FLAGS));
self->tty->low_latency = (self->flags & ASYNC_LOW_LATENCY) ? 1 : 0;
check_and_exit:
if (self->flags & ASYNC_INITIALIZED) {
if (((old_state.flags & ASYNC_SPD_MASK) !=
(self->flags & ASYNC_SPD_MASK)) ||
(old_driver.custom_divisor != driver->custom_divisor)) {
if ((driver->flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
driver->tty->alt_speed = 57600;
if ((driver->flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
driver->tty->alt_speed = 115200;
if ((driver->flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
driver->tty->alt_speed = 230400;
if ((driver->flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
driver->tty->alt_speed = 460800;
ircomm_tty_change_speed(driver);
}
}
#endif
return 0;
}
int ircomm_tty_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct ircomm_tty_cb *self = (struct ircomm_tty_cb *) tty->driver_data;
int ret = 0;
IRDA_DEBUG(2, "%s()\n", __func__ );
if ((cmd != TIOCGSERIAL) && (cmd != TIOCSSERIAL) &&
(cmd != TIOCSERCONFIG) && (cmd != TIOCSERGSTRUCT) &&
(cmd != TIOCMIWAIT) && (cmd != TIOCGICOUNT)) {
if (tty->flags & (1 << TTY_IO_ERROR))
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
IRDA_DEBUG(0, "(), TIOCMIWAIT, not impl!\n");
break;
case TIOCGICOUNT:
IRDA_DEBUG(0, "%s(), TIOCGICOUNT not impl!\n", __func__ );
#if 0
save_flags(flags); cli();
cnow = driver->icount;
restore_flags(flags);
p_cuser = (struct serial_icounter_struct __user *) arg;
if (put_user(cnow.cts, &p_cuser->cts) ||
put_user(cnow.dsr, &p_cuser->dsr) ||
put_user(cnow.rng, &p_cuser->rng) ||
put_user(cnow.dcd, &p_cuser->dcd) ||
put_user(cnow.rx, &p_cuser->rx) ||
put_user(cnow.tx, &p_cuser->tx) ||
put_user(cnow.frame, &p_cuser->frame) ||
put_user(cnow.overrun, &p_cuser->overrun) ||
put_user(cnow.parity, &p_cuser->parity) ||
put_user(cnow.brk, &p_cuser->brk) ||
put_user(cnow.buf_overrun, &p_cuser->buf_overrun))
return -EFAULT;
#endif
return 0;
default:
ret = -ENOIOCTLCMD;
}
return ret;
}
