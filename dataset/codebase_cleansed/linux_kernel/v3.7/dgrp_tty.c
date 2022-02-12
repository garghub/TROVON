static int calc_baud_rate(struct un_struct *un)
{
int i;
int brate;
struct baud_rates {
unsigned int rate;
unsigned int cflag;
};
static struct baud_rates baud_rates[] = {
{ 921600, B921600 },
{ 460800, B460800 },
{ 230400, B230400 },
{ 115200, B115200 },
{ 57600, B57600 },
{ 38400, B38400 },
{ 19200, B19200 },
{ 9600, B9600 },
{ 4800, B4800 },
{ 2400, B2400 },
{ 1200, B1200 },
{ 600, B600 },
{ 300, B300 },
{ 200, B200 },
{ 150, B150 },
{ 134, B134 },
{ 110, B110 },
{ 75, B75 },
{ 50, B50 },
{ 0, B9600 }
};
brate = C_BAUD(un->un_tty);
for (i = 0; baud_rates[i].rate; i++) {
if (baud_rates[i].cflag == brate)
break;
}
return baud_rates[i].rate;
}
static int calc_fastbaud_rate(struct un_struct *un, struct ktermios *uts)
{
int i;
int brate;
ulong bauds[2][16] = {
{
0, 57600, 76800, 115200,
131657, 153600, 230400, 460800,
921600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 },
{
0, 57600, 115200, 230400,
460800, 150, 200, 921600,
600, 1200, 1800, 2400,
4800, 9600, 19200, 38400 }
};
brate = C_BAUD(un->un_tty) & 0xff;
i = (uts->c_cflag & CBAUDEX) ? 1 : 0;
if ((i >= 0) && (i < 2) && (brate >= 0) && (brate < 16))
brate = bauds[i][brate];
else
brate = 0;
return brate;
}
static void drp_param(struct ch_struct *ch)
{
struct nd_struct *nd;
struct un_struct *un;
int brate;
int mflow;
int xflag;
int iflag;
struct ktermios *tts, *pts, *uts;
nd = ch->ch_nd;
if (ch->ch_tun.un_open_count) {
un = &ch->ch_tun;
tts = &ch->ch_tun.un_tty->termios;
if (ch->ch_pun.un_open_count) {
pts = &ch->ch_pun.un_tty->termios;
pts->c_cflag ^=
(pts->c_cflag ^ tts->c_cflag) &
(CBAUD | CSIZE | CSTOPB | CREAD | PARENB |
PARODD | HUPCL | CLOCAL);
pts->c_iflag ^=
(pts->c_iflag ^ tts->c_iflag) &
(IGNBRK | BRKINT | IGNPAR | PARMRK | INPCK |
ISTRIP | IXON | IXANY | IXOFF);
pts->c_cc[VSTART] = tts->c_cc[VSTART];
pts->c_cc[VSTOP] = tts->c_cc[VSTOP];
}
} else if (ch->ch_pun.un_open_count == 0) {
pr_warn("%s - ch_pun.un_open_count shouldn't be 0\n",
__func__);
return;
} else {
un = &ch->ch_pun;
}
uts = &un->un_tty->termios;
if ((ch->ch_digi.digi_flags & DIGI_COOK) != 0 &&
(ch->ch_tun.un_open_count != 0) &&
!((un->un_tty)->ldisc->ops->flags & LDISC_FLAG_DEFINED) &&
!(L_XCASE(un->un_tty))) {
ch->ch_flag |= CH_FAST_WRITE;
} else {
ch->ch_flag &= ~CH_FAST_WRITE;
}
if ((ch->ch_flag & CH_FAST_WRITE) &&
O_OPOST(un->un_tty) != 0) {
int oflag = tty_to_ch_flags(un->un_tty, 'o');
ch->ch_ocook |= oflag & (OF_OLCUC |
OF_ONLCR |
OF_OCRNL |
OF_ONLRET |
OF_TABDLY);
oflag = ch_to_tty_flags(ch->ch_ocook, 'o');
uts->c_oflag &= ~oflag;
} else {
int oflag = ch_to_tty_flags(ch->ch_ocook, 'o');
uts->c_oflag |= oflag;
ch->ch_ocook = 0;
}
ch->ch_oflag = ch->ch_ocook;
ch->ch_flag &= ~CH_FAST_READ;
if (C_BAUD(un->un_tty) == B0) {
if (!(ch->ch_flag & CH_BAUD0)) {
ch->ch_tout = ch->ch_tin;
ch->ch_rout = ch->ch_rin;
ch->ch_break_time = 0;
ch->ch_send |= RR_TX_FLUSH | RR_RX_FLUSH;
ch->ch_mout &= ~(DM_DTR | DM_RTS);
ch->ch_flag |= CH_BAUD0;
}
} else if (ch->ch_custom_speed) {
ch->ch_brate = PORTSERVER_DIVIDEND / ch->ch_custom_speed ;
if (ch->ch_flag & CH_BAUD0) {
ch->ch_mout |= DM_DTR | DM_RTS;
ch->ch_flag &= ~CH_BAUD0;
}
} else {
if (!(ch->ch_digi.digi_flags & DIGI_FAST))
brate = calc_baud_rate(un);
else
brate = calc_fastbaud_rate(un, uts);
if (brate == 0)
brate = 9600;
ch->ch_brate = PORTSERVER_DIVIDEND / brate;
if (ch->ch_flag & CH_BAUD0) {
ch->ch_mout |= DM_DTR | DM_RTS;
ch->ch_flag &= ~CH_BAUD0;
}
}
ch->ch_cflag = tty_to_ch_flags(un->un_tty, 'c');
iflag = (int) tty_to_ch_flags(un->un_tty, 'i');
if (START_CHAR(un->un_tty) == _POSIX_VDISABLE ||
STOP_CHAR(un->un_tty) == _POSIX_VDISABLE) {
iflag &= ~(IF_IXON | IF_IXANY | IF_IXOFF);
}
ch->ch_iflag = iflag;
if (uts->c_cc[VSTART] != _POSIX_VDISABLE)
ch->ch_xon = uts->c_cc[VSTART];
if (uts->c_cc[VSTOP] != _POSIX_VDISABLE)
ch->ch_xoff = uts->c_cc[VSTOP];
ch->ch_lnext = (uts->c_cc[VLNEXT] == _POSIX_VDISABLE ? 0 :
uts->c_cc[VLNEXT]);
if ((uts->c_cc[VSTART] == _POSIX_VDISABLE) ||
(uts->c_cc[VSTOP] == _POSIX_VDISABLE))
ch->ch_iflag &= ~(IF_IXOFF | IF_IXON);
xflag = 0;
if (ch->ch_digi.digi_flags & DIGI_AIXON)
xflag = XF_XIXON;
if ((ch->ch_xxon == _POSIX_VDISABLE) ||
(ch->ch_xxoff == _POSIX_VDISABLE))
xflag &= ~XF_XIXON;
ch->ch_xflag = xflag;
if (C_CLOCAL(un->un_tty))
ch->ch_flag |= CH_CLOCAL;
else
ch->ch_flag &= ~CH_CLOCAL;
dgrp_carrier(ch);
mflow = 0;
if (C_CRTSCTS(un->un_tty))
mflow |= (DM_RTS | DM_CTS);
if (ch->ch_digi.digi_flags & RTSPACE)
mflow |= DM_RTS;
if (ch->ch_digi.digi_flags & DTRPACE)
mflow |= DM_DTR;
if (ch->ch_digi.digi_flags & CTSPACE)
mflow |= DM_CTS;
if (ch->ch_digi.digi_flags & DSRPACE)
mflow |= DM_DSR;
if (ch->ch_digi.digi_flags & DCDPACE)
mflow |= DM_CD;
if (ch->ch_digi.digi_flags & DIGI_RTS_TOGGLE)
mflow |= DM_RTS_TOGGLE;
ch->ch_mflow = mflow;
ch->ch_flag |= CH_PARAM;
(ch->ch_nd)->nd_tx_work = 1;
if (waitqueue_active(&ch->ch_flag_wait))
wake_up_interruptible(&ch->ch_flag_wait);
}
static void wake_up_drp_sleep_timer(unsigned long ptr)
{
struct ch_struct *ch = (struct ch_struct *) ptr;
if (ch)
wake_up(&ch->ch_sleep);
}
static void drp_my_sleep(struct ch_struct *ch)
{
struct timer_list drp_wakeup_timer;
DECLARE_WAITQUEUE(wait, current);
add_wait_queue(&ch->ch_sleep, &wait);
current->state = TASK_UNINTERRUPTIBLE;
init_timer(&drp_wakeup_timer);
drp_wakeup_timer.function = wake_up_drp_sleep_timer;
drp_wakeup_timer.data = (unsigned long) ch;
drp_wakeup_timer.expires = jiffies + (1 * HZ);
add_timer(&drp_wakeup_timer);
schedule();
del_timer(&drp_wakeup_timer);
remove_wait_queue(&ch->ch_sleep, &wait);
}
static int dgrp_tty_open(struct tty_struct *tty, struct file *file)
{
int retval = 0;
struct nd_struct *nd;
struct ch_struct *ch;
struct un_struct *un;
int port;
int delay_error;
int otype;
int unf;
int wait_carrier;
int category;
int counts_were_incremented = 0;
ulong lock_flags;
DECLARE_WAITQUEUE(wait, current);
nd = nd_struct_get(MAJOR(tty_devnum(tty)));
port = PORT_NUM(MINOR(tty_devnum(tty)));
category = OPEN_CATEGORY(MINOR(tty_devnum(tty)));
if (!nd)
return -ENODEV;
if (port >= CHAN_MAX)
return -ENODEV;
ch = nd->nd_chan + port;
un = IS_PRINT(MINOR(tty_devnum(tty))) ? &ch->ch_pun : &ch->ch_tun;
un->un_tty = tty;
tty->driver_data = un;
if (tty_hung_up_p(file)) {
retval = ((un->un_flag & UN_HUP_NOTIFY) ?
-EAGAIN : -ERESTARTSYS);
goto done;
}
retval = wait_event_interruptible(un->un_close_wait,
((un->un_flag & UN_CLOSING) == 0));
if (retval)
goto done;
retval = wait_event_interruptible(ch->ch_flag_wait,
((ch->ch_flag & CH_PORT_GONE) == 0));
if (retval)
goto done;
if (tty->driver->subtype == SERIAL_TYPE_CALLOUT) {
if (un->un_flag & UN_NORMAL_ACTIVE) {
retval = -EBUSY;
goto done;
} else {
un->un_flag |= UN_CALLOUT_ACTIVE;
}
}
spin_lock_irqsave(&nd->nd_lock, lock_flags);
nd->nd_tx_work = 1;
for (;;) {
wait_carrier = 0;
if (test_bit(TTY_IO_ERROR, &tty->flags)) {
if (un->un_flag & UN_CALLOUT_ACTIVE)
retval = -EBUSY;
else
un->un_flag |= UN_NORMAL_ACTIVE;
goto unlock;
}
if (file->f_flags & O_NONBLOCK) {
otype = OTYPE_IMMEDIATE;
delay_error = -EAGAIN;
} else if (!OPEN_WAIT_AVAIL(category) ||
(file->f_flags & O_NDELAY) != 0) {
otype = OTYPE_IMMEDIATE;
delay_error = -EBUSY;
} else if (!OPEN_WAIT_CARRIER(category) ||
((ch->ch_digi.digi_flags & DIGI_FORCEDCD) != 0) ||
C_CLOCAL(tty)) {
otype = OTYPE_PERSISTENT;
delay_error = 0;
} else {
otype = OTYPE_INCOMING;
delay_error = 0;
}
if (port >= nd->nd_chan_count) {
if (otype == OTYPE_IMMEDIATE) {
retval = (nd->nd_state == NS_READY) ?
-ENXIO : -EAGAIN;
goto unlock;
}
}
else if (ch->ch_open_count == 0) {
if (ch->ch_open_error != 0 && otype == ch->ch_otype) {
retval = (ch->ch_open_error <= 2) ?
delay_error : -ENXIO ;
goto unlock;
}
if (nd->nd_state != NS_READY &&
otype == OTYPE_IMMEDIATE) {
retval = -EAGAIN;
goto unlock;
}
if (ch->ch_state == CS_READY && ch->ch_otype == otype)
break;
}
else if ((ch->ch_category == category) ||
IS_PRINT(MINOR(tty_devnum(tty)))) {
unf = ch->ch_tun.un_flag | ch->ch_pun.un_flag;
if ((file->f_flags & O_EXCL) || (unf & UN_EXCL)) {
retval = -EBUSY;
goto unlock;
}
if (ch->ch_flag & CH_HANGUP) {
retval = -ENXIO;
goto unlock;
}
if (ch->ch_state == CS_READY &&
(otype != OTYPE_INCOMING ||
ch->ch_flag & CH_VIRT_CD))
break;
wait_carrier = 1;
}
else {
if (otype == OTYPE_IMMEDIATE) {
retval = delay_error;
goto unlock;
}
}
ch->ch_wait_count[otype]++;
if (wait_carrier)
ch->ch_wait_carrier++;
add_wait_queue(&ch->ch_flag_wait, &wait);
current->state = TASK_INTERRUPTIBLE;
spin_unlock_irqrestore(&nd->nd_lock, lock_flags);
schedule();
remove_wait_queue(&ch->ch_flag_wait, &wait);
spin_lock_irqsave(&nd->nd_lock, lock_flags);
current->state = TASK_RUNNING;
ch->ch_wait_count[otype]--;
if (wait_carrier)
ch->ch_wait_carrier--;
nd->nd_tx_work = 1;
if (signal_pending(current)) {
retval = -EINTR;
goto unlock;
}
}
counts_were_incremented = 1;
un->un_open_count++;
ch->ch_open_count++;
if (ch->ch_open_count == 1) {
ch->ch_flag = 0;
ch->ch_inwait = 0;
ch->ch_category = category;
ch->ch_pscan_state = 0;
ch->ch_send = RR_TX_START | RR_RX_START;
if (C_CLOCAL(tty) ||
ch->ch_s_mlast & DM_CD ||
ch->ch_digi.digi_flags & DIGI_FORCEDCD)
ch->ch_flag |= CH_VIRT_CD;
else if (OPEN_FORCES_CARRIER(category))
ch->ch_flag |= CH_VIRT_CD;
}
if (un->un_open_count == 1) {
un->un_flag &= ~UN_DIGI_MASK;
if (file->f_flags & O_EXCL)
un->un_flag |= UN_EXCL;
drp_param(ch);
}
un->un_flag |= UN_INITIALIZED;
retval = 0;
unlock:
spin_unlock_irqrestore(&nd->nd_lock, lock_flags);
done:
if (!counts_were_incremented) {
un->un_open_count++;
ch->ch_open_count++;
}
if (retval)
dev_err(tty->dev, "tty open bad return (%i)\n", retval);
return retval;
}
static void dgrp_tty_close(struct tty_struct *tty, struct file *file)
{
struct ch_struct *ch;
struct un_struct *un;
struct nd_struct *nd;
int tpos;
int port;
int err = 0;
int s = 0;
ulong waketime;
ulong lock_flags;
int sent_printer_offstr = 0;
port = PORT_NUM(MINOR(tty_devnum(tty)));
un = tty->driver_data;
if (!un)
return;
ch = un->un_ch;
if (!ch)
return;
nd = ch->ch_nd;
if (!nd)
return;
spin_lock_irqsave(&nd->nd_lock, lock_flags);
if (un->un_open_count != 1)
goto unlock;
un->un_flag |= UN_CLOSING;
tty->closing = 1;
if (ch->ch_open_count == 1) {
if (IS_PRINT(MINOR(tty_devnum(tty))) &&
(((ch->ch_tout - ch->ch_tin - 1) & TBUF_MASK) <
ch->ch_digi.digi_offlen))
ch->ch_tin = ch->ch_tout;
if ((ch->ch_flag & CH_PRON) != 0) {
drp_wmove(ch, 0, ch->ch_digi.digi_offstr,
ch->ch_digi.digi_offlen);
ch->ch_flag &= ~CH_PRON;
sent_printer_offstr = 1;
}
}
tpos = ch->ch_s_tpos;
waketime = jiffies + 15 * HZ;
for (;;) {
if (port >= nd->nd_chan_count) {
err = 1;
break;
}
if (signal_pending(current)) {
err = 1;
break;
}
if (ch->ch_state == CS_IDLE)
break;
nd->nd_tx_work = 1;
if ((un->un_tty)->ops->chars_in_buffer ?
((un->un_tty)->ops->chars_in_buffer)(un->un_tty) == 0 : 1) {
if (ch->ch_open_count != un->un_open_count)
break;
if (ch->ch_tin == ch->ch_tout &&
ch->ch_s_tin == ch->ch_s_tpos &&
(ch->ch_send & RR_TX_BREAK) == 0) {
break;
}
}
if ((file->f_flags & (O_NDELAY | O_NONBLOCK)) ||
((long)(jiffies - waketime) >= 0 &&
(ch->ch_digi.digi_flags & DIGI_PRINTER) == 0)) {
if (!sent_printer_offstr)
dgrp_tty_flush_buffer(tty);
tty_ldisc_flush(tty);
break;
}
ch->ch_flag |= CH_DRAIN;
spin_unlock_irqrestore(&nd->nd_lock, lock_flags);
schedule_timeout_interruptible(1);
s = signal_pending(current);
spin_lock_irqsave(&nd->nd_lock, lock_flags);
if (s) {
if (sent_printer_offstr) {
spin_unlock_irqrestore(&nd->nd_lock,
lock_flags);
drp_my_sleep(ch);
spin_lock_irqsave(&nd->nd_lock, lock_flags);
} else {
err = 1;
break;
}
}
if (ch->ch_s_tpos != tpos) {
tpos = ch->ch_s_tpos;
waketime = jiffies + 15 * HZ;
}
}
if (!IS_PRINT(MINOR(tty_devnum(tty))))
ch->ch_rout = ch->ch_rin;
if ((err != 1) && (ch->ch_state != CS_IDLE)) {
spin_unlock_irqrestore(&nd->nd_lock, lock_flags);
s = wait_event_interruptible(ch->ch_flag_wait,
((ch->ch_flag & (CH_WAITING_SYNC | CH_PARAM)) == 0));
spin_lock_irqsave(&nd->nd_lock, lock_flags);
}
if (ch->ch_open_count == 1) {
ch->ch_flag = 0;
ch->ch_category = 0;
ch->ch_send = 0;
ch->ch_expect = 0;
ch->ch_tout = ch->ch_tin;
if (ch->ch_state == CS_READY)
ch->ch_state = CS_SEND_CLOSE;
}
if (ch->ch_state != CS_IDLE) {
ch->ch_flag |= CH_PARAM;
wake_up_interruptible(&ch->ch_flag_wait);
}
nd->nd_tx_work = 1;
nd->nd_tx_ready = 1;
unlock:
tty->closing = 0;
if (ch->ch_open_count <= 0)
dev_info(tty->dev,
"%s - unexpected value for ch->ch_open_count: %i\n",
__func__, ch->ch_open_count);
else
ch->ch_open_count--;
if (un->un_open_count <= 0)
dev_info(tty->dev,
"%s - unexpected value for un->un_open_count: %i\n",
__func__, un->un_open_count);
else
un->un_open_count--;
un->un_flag &= ~(UN_NORMAL_ACTIVE | UN_CALLOUT_ACTIVE | UN_CLOSING);
if (waitqueue_active(&un->un_close_wait))
wake_up_interruptible(&un->un_close_wait);
spin_unlock_irqrestore(&nd->nd_lock, lock_flags);
return;
}
static void drp_wmove(struct ch_struct *ch, int from_user, void *buf, int count)
{
int n;
int ret = 0;
ch->ch_nd->nd_tx_work = 1;
n = TBUF_MAX - ch->ch_tin;
if (count >= n) {
if (from_user)
ret = copy_from_user(ch->ch_tbuf + ch->ch_tin,
(void __user *) buf, n);
else
memcpy(ch->ch_tbuf + ch->ch_tin, buf, n);
buf = (char *) buf + n;
count -= n;
ch->ch_tin = 0;
}
if (from_user)
ret = copy_from_user(ch->ch_tbuf + ch->ch_tin,
(void __user *) buf, count);
else
memcpy(ch->ch_tbuf + ch->ch_tin, buf, count);
ch->ch_tin += count;
}
static int dgrp_calculate_txprint_bounds(struct ch_struct *ch, int space,
int *un_flag)
{
clock_t tt;
clock_t mt;
unsigned short tmax = 0;
if (ch->ch_tun.un_open_count != 0 &&
ch->ch_tun.un_tty->ops->chars_in_buffer &&
((ch->ch_tun.un_tty->ops->chars_in_buffer)(ch->ch_tun.un_tty) != 0)) {
*un_flag = UN_PWAIT;
return 0;
}
space -= ch->ch_digi.digi_offlen;
if (space <= 0) {
*un_flag = UN_EMPTY;
return 0;
}
tt = jiffies - ch->ch_cpstime;
mt = HZ * ch->ch_digi.digi_bufsize / ch->ch_digi.digi_maxcps;
if ((clock_t)(tt + HZ) > (clock_t)(mt + HZ)) {
tmax = ch->ch_digi.digi_bufsize;
ch->ch_cpstime = jiffies - mt;
} else {
tmax = ch->ch_digi.digi_maxcps * tt / HZ;
}
if (tmax < space) {
*un_flag = UN_TIME;
space = tmax;
}
tmax = (ch->ch_digi.digi_maxchar -
((ch->ch_tin - ch->ch_tout) & TBUF_MASK) -
((ch->ch_s_tin - ch->ch_s_tpos) & 0xffff));
if (space > tmax) {
*un_flag = UN_EMPTY;
space = tmax;
}
if (space <= 0)
*un_flag |= UN_EMPTY;
return space;
}
static int dgrp_tty_write(struct tty_struct *tty,
const unsigned char *buf,
int count)
{
struct nd_struct *nd;
struct un_struct *un;
struct ch_struct *ch;
int space;
int n;
int t;
int sendcount;
int un_flag;
ulong lock_flags;
if (tty == NULL)
return 0;
un = tty->driver_data;
if (!un)
return 0;
ch = un->un_ch;
if (!ch)
return 0;
nd = ch->ch_nd;
if (!nd)
return 0;
if (ch->ch_state != CS_READY)
return 0;
spin_lock_irqsave(&dgrp_poll_data.poll_lock, lock_flags);
if ((un->un_flag & (UN_EMPTY | UN_LOW | UN_TIME | UN_PWAIT)) != 0) {
count = 0;
goto out;
}
if (nd->nd_dpa_debug && nd->nd_dpa_flag & DPA_WAIT_SPACE &&
nd->nd_dpa_port == MINOR(tty_devnum(ch->ch_tun.un_tty))) {
count = 0;
goto out;
}
sendcount = 0;
space = (ch->ch_tout - ch->ch_tin - 1) & TBUF_MASK;
un_flag = UN_LOW;
if (IS_PRINT(MINOR(tty_devnum(tty)))) {
clock_t tt;
clock_t mt;
unsigned short tmax = 0;
if (ch->ch_tun.un_open_count != 0 &&
((ch->ch_tun.un_tty->ops->chars_in_buffer)(ch->ch_tun.un_tty) != 0)) {
un->un_flag |= UN_PWAIT;
count = 0;
goto out;
}
space -= ch->ch_digi.digi_offlen;
if ((ch->ch_flag & CH_PRON) == 0) {
space -= ch->ch_digi.digi_onlen;
if (space < 0) {
un->un_flag |= UN_EMPTY;
(ch->ch_nd)->nd_tx_work = 1;
count = 0;
goto out;
}
drp_wmove(ch, 0, ch->ch_digi.digi_onstr,
ch->ch_digi.digi_onlen);
ch->ch_flag |= CH_PRON;
}
tt = jiffies - ch->ch_cpstime;
mt = HZ * ch->ch_digi.digi_bufsize / ch->ch_digi.digi_maxcps;
if ((clock_t)(tt + HZ) > (clock_t)(mt + HZ)) {
tmax = ch->ch_digi.digi_bufsize;
ch->ch_cpstime = jiffies - mt;
} else {
tmax = ch->ch_digi.digi_maxcps * tt / HZ;
}
if (tmax < space) {
space = tmax;
un_flag = UN_TIME;
}
tmax = (ch->ch_digi.digi_maxchar -
((ch->ch_tin - ch->ch_tout) & TBUF_MASK) -
((ch->ch_s_tin - ch->ch_s_tpos) & 0xffff));
if (space > tmax) {
space = tmax;
un_flag = UN_EMPTY;
}
}
else {
if ((ch->ch_flag & CH_PRON) != 0) {
space -= ch->ch_digi.digi_offlen;
drp_wmove(ch, 0, ch->ch_digi.digi_offstr,
ch->ch_digi.digi_offlen);
ch->ch_flag &= ~CH_PRON;
}
}
if (space <= 0) {
un->un_flag |= UN_EMPTY;
(ch->ch_nd)->nd_tx_work = 1;
count = 0;
goto out;
}
count = min(count, space);
if (count > 0) {
un->un_tbusy++;
t = TBUF_MAX - ch->ch_tin;
n = count;
if (n >= t) {
memcpy(ch->ch_tbuf + ch->ch_tin, buf, t);
if (nd->nd_dpa_debug && nd->nd_dpa_port == PORT_NUM(MINOR(tty_devnum(un->un_tty))))
dgrp_dpa_data(nd, 0, (char *) buf, t);
buf += t;
n -= t;
ch->ch_tin = 0;
sendcount += n;
}
memcpy(ch->ch_tbuf + ch->ch_tin, buf, n);
if (nd->nd_dpa_debug && nd->nd_dpa_port == PORT_NUM(MINOR(tty_devnum(un->un_tty))))
dgrp_dpa_data(nd, 0, (char *) buf, n);
buf += n;
ch->ch_tin += n;
sendcount += n;
un->un_tbusy--;
(ch->ch_nd)->nd_tx_work = 1;
if (ch->ch_edelay != DGRP_RTIME) {
(ch->ch_nd)->nd_tx_ready = 1;
wake_up_interruptible(&nd->nd_tx_waitq);
}
}
ch->ch_txcount += count;
if (IS_PRINT(MINOR(tty_devnum(tty)))) {
if (sendcount > 0) {
int cc = HZ * sendcount + ch->ch_cpsrem;
ch->ch_cpstime += cc / ch->ch_digi.digi_maxcps;
ch->ch_cpsrem = cc % ch->ch_digi.digi_maxcps;
}
if ((un_flag & UN_TIME) != 0) {
ch->ch_waketime = (ch->ch_cpstime +
(ch->ch_digi.digi_maxchar * HZ /
ch->ch_digi.digi_maxcps));
}
}
if ((ch->ch_pun.un_flag & UN_PWAIT) != 0)
(ch->ch_nd)->nd_tx_work = 1;
out:
spin_unlock_irqrestore(&dgrp_poll_data.poll_lock, lock_flags);
return count;
}
static int dgrp_tty_put_char(struct tty_struct *tty, unsigned char new_char)
{
struct un_struct *un;
struct ch_struct *ch;
ulong lock_flags;
int space;
int retval = 0;
if (tty == NULL)
return 0;
un = tty->driver_data;
if (!un)
return 0;
ch = un->un_ch;
if (!ch)
return 0;
if (ch->ch_state != CS_READY)
return 0;
spin_lock_irqsave(&dgrp_poll_data.poll_lock, lock_flags);
space = (ch->ch_tout - ch->ch_tin - 1) & TBUF_MASK;
un->un_tbusy++;
if (IS_PRINT(MINOR(tty_devnum(tty))) && (ch->ch_flag & CH_PRON) == 0) {
if (space < ch->ch_digi.digi_onlen) {
un->un_tbusy--;
goto out;
}
space -= ch->ch_digi.digi_onlen;
drp_wmove(ch, 0, ch->ch_digi.digi_onstr,
ch->ch_digi.digi_onlen);
ch->ch_flag |= CH_PRON;
}
if (!IS_PRINT(MINOR(tty_devnum(tty))) &&
((ch->ch_flag & CH_PRON) != 0)) {
if (space < ch->ch_digi.digi_offlen) {
un->un_tbusy--;
goto out;
}
space -= ch->ch_digi.digi_offlen;
drp_wmove(ch, 0, ch->ch_digi.digi_offstr,
ch->ch_digi.digi_offlen);
ch->ch_flag &= ~CH_PRON;
}
if (!space) {
un->un_tbusy--;
goto out;
}
ch->ch_tbuf[ch->ch_tin] = new_char;
ch->ch_tin = (1 + ch->ch_tin) & TBUF_MASK;
if (IS_PRINT(MINOR(tty_devnum(tty)))) {
int cc = HZ + ch->ch_cpsrem;
ch->ch_cpstime += cc / ch->ch_digi.digi_maxcps;
ch->ch_cpsrem = cc % ch->ch_digi.digi_maxcps;
ch->ch_waketime = (ch->ch_cpstime +
(ch->ch_digi.digi_maxchar * HZ /
ch->ch_digi.digi_maxcps));
}
un->un_tbusy--;
(ch->ch_nd)->nd_tx_work = 1;
retval = 1;
out:
spin_unlock_irqrestore(&dgrp_poll_data.poll_lock, lock_flags);
return retval;
}
static void dgrp_tty_flush_buffer(struct tty_struct *tty)
{
struct un_struct *un;
struct ch_struct *ch;
if (!tty)
return;
un = tty->driver_data;
if (!un)
return;
ch = un->un_ch;
if (!ch)
return;
ch->ch_tout = ch->ch_tin;
ch->ch_send |= RR_TX_FLUSH;
(ch->ch_nd)->nd_tx_ready = 1;
(ch->ch_nd)->nd_tx_work = 1;
wake_up_interruptible(&(ch->ch_nd)->nd_tx_waitq);
if (waitqueue_active(&tty->write_wait))
wake_up_interruptible(&tty->write_wait);
tty_wakeup(tty);
}
static int dgrp_tty_write_room(struct tty_struct *tty)
{
struct un_struct *un;
struct ch_struct *ch;
int count;
if (!tty)
return 0;
un = tty->driver_data;
if (!un)
return 0;
ch = un->un_ch;
if (!ch)
return 0;
count = (ch->ch_tout - ch->ch_tin - 1) & TBUF_MASK;
if (IS_PRINT(MINOR(tty_devnum(tty)))) {
int un_flag = 0;
count = dgrp_calculate_txprint_bounds(ch, count, &un_flag);
if (count <= 0)
count = 0;
ch->ch_pun.un_flag |= un_flag;
(ch->ch_nd)->nd_tx_work = 1;
}
return count;
}
static int dgrp_tty_chars_in_buffer(struct tty_struct *tty)
{
struct un_struct *un;
struct ch_struct *ch;
int count;
int count1;
if (!tty)
return 0;
un = tty->driver_data;
if (!un)
return 0;
ch = un->un_ch;
if (!ch)
return 0;
count1 = count = (ch->ch_tin - ch->ch_tout) & TBUF_MASK;
count += (ch->ch_s_tin - ch->ch_s_tpos) & 0xffff;
count += un->un_tbusy;
return count;
}
static tcflag_t ch_to_tty_flags(ushort ch_flag, char flagtype)
{
tcflag_t retval = 0;
switch (flagtype) {
case 'i':
retval = ((ch_flag & IF_IGNBRK) ? IGNBRK : 0)
| ((ch_flag & IF_BRKINT) ? BRKINT : 0)
| ((ch_flag & IF_IGNPAR) ? IGNPAR : 0)
| ((ch_flag & IF_PARMRK) ? PARMRK : 0)
| ((ch_flag & IF_INPCK) ? INPCK : 0)
| ((ch_flag & IF_ISTRIP) ? ISTRIP : 0)
| ((ch_flag & IF_IXON) ? IXON : 0)
| ((ch_flag & IF_IXANY) ? IXANY : 0)
| ((ch_flag & IF_IXOFF) ? IXOFF : 0);
break;
case 'o':
retval = ((ch_flag & OF_OLCUC) ? OLCUC : 0)
| ((ch_flag & OF_ONLCR) ? ONLCR : 0)
| ((ch_flag & OF_OCRNL) ? OCRNL : 0)
| ((ch_flag & OF_ONOCR) ? ONOCR : 0)
| ((ch_flag & OF_ONLRET) ? ONLRET : 0)
| ((ch_flag & OF_TABDLY) ? TABDLY : 0);
break;
case 'c':
retval = ((ch_flag & CF_CSTOPB) ? CSTOPB : 0)
| ((ch_flag & CF_CREAD) ? CREAD : 0)
| ((ch_flag & CF_PARENB) ? PARENB : 0)
| ((ch_flag & CF_PARODD) ? PARODD : 0)
| ((ch_flag & CF_HUPCL) ? HUPCL : 0);
switch (ch_flag & CF_CSIZE) {
case CF_CS5:
retval |= CS5;
break;
case CF_CS6:
retval |= CS6;
break;
case CF_CS7:
retval |= CS7;
break;
case CF_CS8:
retval |= CS8;
break;
default:
retval |= CS8;
break;
}
break;
case 'x':
break;
case 'l':
break;
default:
return 0;
}
return retval;
}
static ushort tty_to_ch_flags(struct tty_struct *tty, char flagtype)
{
ushort retval = 0;
tcflag_t tflag = 0;
switch (flagtype) {
case 'i':
tflag = tty->termios.c_iflag;
retval = (I_IGNBRK(tty) ? IF_IGNBRK : 0)
| (I_BRKINT(tty) ? IF_BRKINT : 0)
| (I_IGNPAR(tty) ? IF_IGNPAR : 0)
| (I_PARMRK(tty) ? IF_PARMRK : 0)
| (I_INPCK(tty) ? IF_INPCK : 0)
| (I_ISTRIP(tty) ? IF_ISTRIP : 0)
| (I_IXON(tty) ? IF_IXON : 0)
| (I_IXANY(tty) ? IF_IXANY : 0)
| (I_IXOFF(tty) ? IF_IXOFF : 0);
break;
case 'o':
tflag = tty->termios.c_oflag;
if (!O_OPOST(tty))
retval = 0;
else
retval = (O_OLCUC(tty) ? OF_OLCUC : 0)
| (O_ONLCR(tty) ? OF_ONLCR : 0)
| (O_OCRNL(tty) ? OF_OCRNL : 0)
| (O_ONOCR(tty) ? OF_ONOCR : 0)
| (O_ONLRET(tty) ? OF_ONLRET : 0)
| (O_TABDLY(tty) ? OF_TABDLY : 0);
break;
case 'c':
tflag = tty->termios.c_cflag;
retval = (C_CSTOPB(tty) ? CF_CSTOPB : 0)
| (C_CREAD(tty) ? CF_CREAD : 0)
| (C_PARENB(tty) ? CF_PARENB : 0)
| (C_PARODD(tty) ? CF_PARODD : 0)
| (C_HUPCL(tty) ? CF_HUPCL : 0);
switch (C_CSIZE(tty)) {
case CS8:
retval |= CF_CS8;
break;
case CS7:
retval |= CF_CS7;
break;
case CS6:
retval |= CF_CS6;
break;
case CS5:
retval |= CF_CS5;
break;
default:
retval |= CF_CS8;
break;
}
break;
case 'x':
break;
case 'l':
break;
default:
return 0;
}
return retval;
}
static int dgrp_tty_send_break(struct tty_struct *tty, int msec)
{
struct un_struct *un;
struct ch_struct *ch;
int ret = -EIO;
if (!tty)
return ret;
un = tty->driver_data;
if (!un)
return ret;
ch = un->un_ch;
if (!ch)
return ret;
dgrp_send_break(ch, msec);
return 0;
}
static int dgrp_send_break(struct ch_struct *ch, int msec)
{
ulong x;
wait_event_interruptible(ch->ch_flag_wait,
((ch->ch_flag & CH_TX_BREAK) == 0));
ch->ch_break_time += max(msec, 250);
ch->ch_send |= RR_TX_BREAK;
ch->ch_flag |= CH_TX_BREAK;
(ch->ch_nd)->nd_tx_work = 1;
x = (msec * HZ) / 1000;
wake_up_interruptible(&(ch->ch_nd)->nd_tx_waitq);
return 0;
}
static int dgrp_tty_tiocmget(struct tty_struct *tty)
{
unsigned int mlast;
struct un_struct *un = tty->driver_data;
struct ch_struct *ch;
if (!un)
return -ENODEV;
ch = un->un_ch;
if (!ch)
return -ENODEV;
mlast = ((ch->ch_s_mlast & ~(DM_RTS | DM_DTR)) |
(ch->ch_mout & (DM_RTS | DM_DTR)));
mlast = ((mlast & DM_RTS) ? TIOCM_RTS : 0)
| ((mlast & DM_DTR) ? TIOCM_DTR : 0)
| ((mlast & DM_CD) ? TIOCM_CAR : 0)
| ((mlast & DM_RI) ? TIOCM_RNG : 0)
| ((mlast & DM_DSR) ? TIOCM_DSR : 0)
| ((mlast & DM_CTS) ? TIOCM_CTS : 0);
return mlast;
}
static int dgrp_tty_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
ulong lock_flags;
struct un_struct *un = tty->driver_data;
struct ch_struct *ch;
if (!un)
return -ENODEV;
ch = un->un_ch;
if (!ch)
return -ENODEV;
if (set & TIOCM_RTS)
ch->ch_mout |= DM_RTS;
if (set & TIOCM_DTR)
ch->ch_mout |= DM_DTR;
if (clear & TIOCM_RTS)
ch->ch_mout &= ~(DM_RTS);
if (clear & TIOCM_DTR)
ch->ch_mout &= ~(DM_DTR);
spin_lock_irqsave(&(ch->ch_nd)->nd_lock, lock_flags);
ch->ch_flag |= CH_PARAM;
(ch->ch_nd)->nd_tx_work = 1;
wake_up_interruptible(&ch->ch_flag_wait);
spin_unlock_irqrestore(&(ch->ch_nd)->nd_lock, lock_flags);
return 0;
}
static int get_modem_info(struct ch_struct *ch, unsigned int *value)
{
unsigned int mlast;
mlast = ((ch->ch_s_mlast & ~(DM_RTS | DM_DTR)) |
(ch->ch_mout & (DM_RTS | DM_DTR)));
mlast = ((mlast & DM_RTS) ? TIOCM_RTS : 0)
| ((mlast & DM_DTR) ? TIOCM_DTR : 0)
| ((mlast & DM_CD) ? TIOCM_CAR : 0)
| ((mlast & DM_RI) ? TIOCM_RNG : 0)
| ((mlast & DM_DSR) ? TIOCM_DSR : 0)
| ((mlast & DM_CTS) ? TIOCM_CTS : 0);
put_user(mlast, (unsigned int __user *) value);
return 0;
}
static int set_modem_info(struct ch_struct *ch, unsigned int command,
unsigned int *value)
{
int error;
unsigned int arg;
int mval = 0;
ulong lock_flags;
error = access_ok(VERIFY_READ, (void __user *) value, sizeof(int));
if (error == 0)
return -EFAULT;
get_user(arg, (unsigned int __user *) value);
mval |= ((arg & TIOCM_RTS) ? DM_RTS : 0)
| ((arg & TIOCM_DTR) ? DM_DTR : 0);
switch (command) {
case TIOCMBIS:
ch->ch_mout |= mval;
break;
case TIOCMBIC:
ch->ch_mout &= ~mval;
break;
case TIOCMSET:
ch->ch_mout = mval;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&(ch->ch_nd)->nd_lock, lock_flags);
ch->ch_flag |= CH_PARAM;
(ch->ch_nd)->nd_tx_work = 1;
wake_up_interruptible(&ch->ch_flag_wait);
spin_unlock_irqrestore(&(ch->ch_nd)->nd_lock, lock_flags);
return 0;
}
static void dgrp_set_custom_speed(struct ch_struct *ch, int newrate)
{
int testdiv;
int testrate_high;
int testrate_low;
int deltahigh, deltalow;
if (newrate < 0)
newrate = 0;
if (newrate && newrate < ((PORTSERVER_DIVIDEND / 0xFFFF) + 1))
newrate = ((PORTSERVER_DIVIDEND / 0xFFFF) + 1);
if (newrate && newrate > PORTSERVER_DIVIDEND)
newrate = PORTSERVER_DIVIDEND;
while (newrate > 0) {
testdiv = PORTSERVER_DIVIDEND / newrate;
testrate_high = PORTSERVER_DIVIDEND / testdiv;
testrate_low = PORTSERVER_DIVIDEND / (testdiv + 1);
if (testrate_high == newrate)
break;
deltahigh = testrate_high - newrate;
deltalow = newrate - testrate_low;
if (deltahigh < deltalow)
newrate = testrate_high;
else
newrate = testrate_low;
break;
}
ch->ch_custom_speed = newrate;
drp_param(ch);
return;
}
static int dgrp_tty_digiseta(struct tty_struct *tty,
struct digi_struct *new_info)
{
struct un_struct *un = tty->driver_data;
struct ch_struct *ch;
if (!un)
return -ENODEV;
ch = un->un_ch;
if (!ch)
return -ENODEV;
if (copy_from_user(&ch->ch_digi, (void __user *) new_info,
sizeof(struct digi_struct)))
return -EFAULT;
if ((ch->ch_digi.digi_flags & RTSPACE) ||
(ch->ch_digi.digi_flags & CTSPACE))
tty->termios.c_cflag |= CRTSCTS;
else
tty->termios.c_cflag &= ~CRTSCTS;
if (ch->ch_digi.digi_maxcps < 1)
ch->ch_digi.digi_maxcps = 1;
if (ch->ch_digi.digi_maxcps > 10000)
ch->ch_digi.digi_maxcps = 10000;
if (ch->ch_digi.digi_bufsize < 10)
ch->ch_digi.digi_bufsize = 10;
if (ch->ch_digi.digi_maxchar < 1)
ch->ch_digi.digi_maxchar = 1;
if (ch->ch_digi.digi_maxchar > ch->ch_digi.digi_bufsize)
ch->ch_digi.digi_maxchar = ch->ch_digi.digi_bufsize;
if (ch->ch_digi.digi_onlen > DIGI_PLEN)
ch->ch_digi.digi_onlen = DIGI_PLEN;
if (ch->ch_digi.digi_offlen > DIGI_PLEN)
ch->ch_digi.digi_offlen = DIGI_PLEN;
drp_param(ch);
return 0;
}
static int dgrp_tty_digigetedelay(struct tty_struct *tty, int *retinfo)
{
struct un_struct *un;
struct ch_struct *ch;
int tmp;
if (!retinfo)
return -EFAULT;
if (!tty || tty->magic != TTY_MAGIC)
return -EFAULT;
un = tty->driver_data;
if (!un)
return -ENODEV;
ch = un->un_ch;
if (!ch)
return -ENODEV;
tmp = ch->ch_edelay;
if (copy_to_user((void __user *) retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int dgrp_tty_digisetedelay(struct tty_struct *tty, int *new_info)
{
struct un_struct *un;
struct ch_struct *ch;
int new_digi;
if (!tty || tty->magic != TTY_MAGIC)
return -EFAULT;
un = tty->driver_data;
if (!un)
return -ENODEV;
ch = un->un_ch;
if (!ch)
return -ENODEV;
if (copy_from_user(&new_digi, (void __user *)new_info, sizeof(int)))
return -EFAULT;
ch->ch_edelay = new_digi;
drp_param(ch);
return 0;
}
static int dgrp_tty_ioctl(struct tty_struct *tty, unsigned int cmd,
unsigned long arg)
{
struct un_struct *un;
struct ch_struct *ch;
int rc;
struct digiflow_struct dflow;
if (!tty)
return -ENODEV;
un = tty->driver_data;
if (!un)
return -ENODEV;
ch = un->un_ch;
if (!ch)
return -ENODEV;
switch (cmd) {
case TCSBRK:
rc = tty_check_change(tty);
if (rc)
return rc;
tty_wait_until_sent(tty, 0);
if (!arg)
rc = dgrp_send_break(ch, 250);
if (dgrp_tty_chars_in_buffer(tty) != 0)
return -EINTR;
return 0;
case TCSBRKP:
rc = tty_check_change(tty);
if (rc)
return rc;
tty_wait_until_sent(tty, 0);
rc = dgrp_send_break(ch, arg ? arg*250 : 250);
if (dgrp_tty_chars_in_buffer(tty) != 0)
return -EINTR;
return 0;
case TIOCSBRK:
rc = tty_check_change(tty);
if (rc)
return rc;
tty_wait_until_sent(tty, 0);
rc = dgrp_send_break(ch, 250);
if (dgrp_tty_chars_in_buffer(tty) != 0)
return -EINTR;
return 0;
case TIOCCBRK:
return 0;
case TIOCGSOFTCAR:
rc = access_ok(VERIFY_WRITE, (void __user *) arg,
sizeof(long));
if (rc == 0)
return -EFAULT;
put_user(C_CLOCAL(tty) ? 1 : 0, (unsigned long __user *) arg);
return 0;
case TIOCSSOFTCAR:
get_user(arg, (unsigned long __user *) arg);
tty->termios.c_cflag =
((tty->termios.c_cflag & ~CLOCAL) |
(arg ? CLOCAL : 0));
return 0;
case TIOCMGET:
rc = access_ok(VERIFY_WRITE, (void __user *) arg,
sizeof(unsigned int));
if (rc == 0)
return -EFAULT;
return get_modem_info(ch, (unsigned int *) arg);
case TIOCMBIS:
case TIOCMBIC:
case TIOCMSET:
return set_modem_info(ch, cmd, (unsigned int *) arg);
case TCFLSH:
rc = tty_check_change(tty);
if (rc)
return rc;
switch (arg) {
case TCIFLUSH:
case TCIOFLUSH:
if (!IS_PRINT(MINOR(tty_devnum(tty)))) {
ch->ch_rout = ch->ch_rin;
ch->ch_send |= RR_RX_FLUSH;
(ch->ch_nd)->nd_tx_work = 1;
(ch->ch_nd)->nd_tx_ready = 1;
wake_up_interruptible(&(ch->ch_nd)->nd_tx_waitq);
}
if (arg == TCIFLUSH)
break;
case TCOFLUSH:
break;
default:
return -EINVAL;
}
return -ENOIOCTLCMD;
#ifdef TIOCGETP
case TIOCGETP:
#endif
case TCGETS:
case TCGETA:
return -ENOIOCTLCMD;
case TCSETAW:
case TCSETAF:
case TCSETSF:
case TCSETSW:
if (!IS_PRINT(MINOR(tty_devnum(tty))) ||
!ch->ch_tun.un_open_count) {
rc = tty_check_change(tty);
if (rc)
return rc;
}
tty_wait_until_sent(tty, 0);
if ((cmd == TCSETSF) || (cmd == TCSETAF)) {
ch->ch_send |= RR_RX_FLUSH;
(ch->ch_nd)->nd_tx_ready = 1;
(ch->ch_nd)->nd_tx_work = 1;
wake_up_interruptible(&(ch->ch_nd)->nd_tx_waitq);
ch->ch_rout = ch->ch_rin;
}
return -ENOIOCTLCMD;
case TCXONC:
rc = tty_check_change(tty);
if (rc)
return rc;
switch (arg) {
case TCOON:
dgrp_tty_start(tty);
return 0;
case TCOOFF:
dgrp_tty_stop(tty);
return 0;
case TCION:
dgrp_tty_input_start(tty);
return 0;
case TCIOFF:
dgrp_tty_input_stop(tty);
return 0;
default:
return -EINVAL;
}
case DIGI_GETA:
if (copy_to_user((struct digi_struct __user *) arg,
&ch->ch_digi, sizeof(struct digi_struct)))
return -EFAULT;
break;
case DIGI_SETAW:
case DIGI_SETAF:
tty_wait_until_sent(tty, 0);
if (cmd == DIGI_SETAF) {
ch->ch_send |= RR_RX_FLUSH;
(ch->ch_nd)->nd_tx_ready = 1;
(ch->ch_nd)->nd_tx_work = 1;
wake_up_interruptible(&(ch->ch_nd)->nd_tx_waitq);
ch->ch_rout = ch->ch_rin;
}
case DIGI_SETA:
return dgrp_tty_digiseta(tty, (struct digi_struct *) arg);
case DIGI_SEDELAY:
return dgrp_tty_digisetedelay(tty, (int *) arg);
case DIGI_GEDELAY:
return dgrp_tty_digigetedelay(tty, (int *) arg);
case DIGI_GETFLOW:
case DIGI_GETAFLOW:
if (cmd == (DIGI_GETFLOW)) {
dflow.startc = tty->termios.c_cc[VSTART];
dflow.stopc = tty->termios.c_cc[VSTOP];
} else {
dflow.startc = ch->ch_xxon;
dflow.stopc = ch->ch_xxoff;
}
if (copy_to_user((char __user *)arg, &dflow, sizeof(dflow)))
return -EFAULT;
break;
case DIGI_SETFLOW:
case DIGI_SETAFLOW:
if (copy_from_user(&dflow, (char __user *)arg, sizeof(dflow)))
return -EFAULT;
if (cmd == (DIGI_SETFLOW)) {
tty->termios.c_cc[VSTART] = dflow.startc;
tty->termios.c_cc[VSTOP] = dflow.stopc;
} else {
ch->ch_xxon = dflow.startc;
ch->ch_xxoff = dflow.stopc;
}
break;
case DIGI_GETCUSTOMBAUD:
rc = access_ok(VERIFY_WRITE, (void __user *) arg, sizeof(int));
if (rc == 0)
return -EFAULT;
put_user(ch->ch_custom_speed, (unsigned int __user *) arg);
break;
case DIGI_SETCUSTOMBAUD:
{
int new_rate;
get_user(new_rate, (unsigned int __user *) arg);
dgrp_set_custom_speed(ch, new_rate);
break;
}
default:
return -ENOIOCTLCMD;
}
return 0;
}
static void dgrp_tty_set_termios(struct tty_struct *tty, struct ktermios *old)
{
struct ktermios *ts;
struct ch_struct *ch;
struct un_struct *un;
if (!tty)
return;
un = tty->driver_data;
if (!un)
return;
ts = &tty->termios;
ch = un->un_ch;
if (!ch)
return;
drp_param(ch);
if (!(old->c_cflag & CLOCAL) && C_CLOCAL(tty))
wake_up_interruptible(&un->un_open_wait);
}
static void dgrp_tty_throttle(struct tty_struct *tty)
{
struct ch_struct *ch;
if (!tty)
return;
ch = ((struct un_struct *) tty->driver_data)->un_ch;
if (!ch)
return;
ch->ch_flag |= CH_RXSTOP;
}
static void dgrp_tty_unthrottle(struct tty_struct *tty)
{
struct ch_struct *ch;
if (!tty)
return;
ch = ((struct un_struct *) tty->driver_data)->un_ch;
if (!ch)
return;
ch->ch_flag &= ~CH_RXSTOP;
}
static void dgrp_tty_stop(struct tty_struct *tty)
{
struct ch_struct *ch;
if (!tty)
return;
ch = ((struct un_struct *) tty->driver_data)->un_ch;
if (!ch)
return;
ch->ch_send |= RR_TX_STOP;
ch->ch_send &= ~RR_TX_START;
(ch->ch_nd)->nd_tx_ready = 1;
if (waitqueue_active(&(ch->ch_nd)->nd_tx_waitq))
wake_up_interruptible(&(ch->ch_nd)->nd_tx_waitq);
}
static void dgrp_tty_start(struct tty_struct *tty)
{
struct ch_struct *ch;
if (!tty)
return;
ch = ((struct un_struct *) tty->driver_data)->un_ch;
if (!ch)
return;
ch->ch_send |= RR_TX_START;
ch->ch_send &= ~RR_TX_STOP;
(ch->ch_nd)->nd_tx_ready = 1;
(ch->ch_nd)->nd_tx_work = 1;
if (waitqueue_active(&(ch->ch_nd)->nd_tx_waitq))
wake_up_interruptible(&(ch->ch_nd)->nd_tx_waitq);
}
static void dgrp_tty_input_stop(struct tty_struct *tty)
{
struct ch_struct *ch;
if (!tty)
return;
ch = ((struct un_struct *) tty->driver_data)->un_ch;
if (!ch)
return;
ch->ch_send |= RR_RX_STOP;
ch->ch_send &= ~RR_RX_START;
(ch->ch_nd)->nd_tx_ready = 1;
if (waitqueue_active(&(ch->ch_nd)->nd_tx_waitq))
wake_up_interruptible(&(ch->ch_nd)->nd_tx_waitq);
}
static void dgrp_tty_send_xchar(struct tty_struct *tty, char c)
{
struct un_struct *un;
struct ch_struct *ch;
if (!tty)
return;
un = tty->driver_data;
if (!un)
return;
ch = un->un_ch;
if (!ch)
return;
if (c == STOP_CHAR(tty))
ch->ch_send |= RR_RX_STOP;
else if (c == START_CHAR(tty))
ch->ch_send |= RR_RX_START;
ch->ch_nd->nd_tx_ready = 1;
ch->ch_nd->nd_tx_work = 1;
return;
}
static void dgrp_tty_input_start(struct tty_struct *tty)
{
struct ch_struct *ch;
if (!tty)
return;
ch = ((struct un_struct *) tty->driver_data)->un_ch;
if (!ch)
return;
ch->ch_send |= RR_RX_START;
ch->ch_send &= ~RR_RX_STOP;
(ch->ch_nd)->nd_tx_ready = 1;
(ch->ch_nd)->nd_tx_work = 1;
if (waitqueue_active(&(ch->ch_nd)->nd_tx_waitq))
wake_up_interruptible(&(ch->ch_nd)->nd_tx_waitq);
}
static void dgrp_tty_hangup(struct tty_struct *tty)
{
struct ch_struct *ch;
struct nd_struct *nd;
struct un_struct *un;
if (!tty)
return;
un = tty->driver_data;
if (!un)
return;
ch = un->un_ch;
if (!ch)
return;
nd = ch->ch_nd;
if (C_HUPCL(tty)) {
ch->ch_mout &= ~DM_DTR;
ch->ch_nd->nd_tx_ready = 1;
ch->ch_nd->nd_tx_work = 1;
if (waitqueue_active(&ch->ch_flag_wait))
wake_up_interruptible(&ch->ch_flag_wait);
}
}
void
dgrp_tty_uninit(struct nd_struct *nd)
{
char id[3];
ID_TO_CHAR(nd->nd_ID, id);
if (nd->nd_ttdriver_flags & SERIAL_TTDRV_REG) {
tty_unregister_driver(nd->nd_serial_ttdriver);
kfree(nd->nd_serial_ttdriver->ttys);
nd->nd_serial_ttdriver->ttys = NULL;
put_tty_driver(nd->nd_serial_ttdriver);
nd->nd_ttdriver_flags &= ~SERIAL_TTDRV_REG;
}
if (nd->nd_ttdriver_flags & CALLOUT_TTDRV_REG) {
tty_unregister_driver(nd->nd_callout_ttdriver);
kfree(nd->nd_callout_ttdriver->ttys);
nd->nd_callout_ttdriver->ttys = NULL;
put_tty_driver(nd->nd_callout_ttdriver);
nd->nd_ttdriver_flags &= ~CALLOUT_TTDRV_REG;
}
if (nd->nd_ttdriver_flags & XPRINT_TTDRV_REG) {
tty_unregister_driver(nd->nd_xprint_ttdriver);
kfree(nd->nd_xprint_ttdriver->ttys);
nd->nd_xprint_ttdriver->ttys = NULL;
put_tty_driver(nd->nd_xprint_ttdriver);
nd->nd_ttdriver_flags &= ~XPRINT_TTDRV_REG;
}
}
int
dgrp_tty_init(struct nd_struct *nd)
{
char id[3];
int rc;
int i;
ID_TO_CHAR(nd->nd_ID, id);
nd->nd_serial_ttdriver = alloc_tty_driver(CHAN_MAX);
if (!nd->nd_serial_ttdriver)
return -ENOMEM;
sprintf(nd->nd_serial_name, "tty_dgrp_%s_", id);
nd->nd_serial_ttdriver->owner = THIS_MODULE;
nd->nd_serial_ttdriver->name = nd->nd_serial_name;
nd->nd_serial_ttdriver->name_base = 0;
nd->nd_serial_ttdriver->major = 0;
nd->nd_serial_ttdriver->minor_start = 0;
nd->nd_serial_ttdriver->type = TTY_DRIVER_TYPE_SERIAL;
nd->nd_serial_ttdriver->subtype = SERIAL_TYPE_NORMAL;
nd->nd_serial_ttdriver->init_termios = DefaultTermios;
nd->nd_serial_ttdriver->driver_name = "dgrp";
nd->nd_serial_ttdriver->flags = (TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV |
TTY_DRIVER_HARDWARE_BREAK);
nd->nd_serial_ttdriver->ttys =
kzalloc(CHAN_MAX * sizeof(struct tty_struct *), GFP_KERNEL);
if (!nd->nd_serial_ttdriver->ttys)
return -ENOMEM;
tty_set_operations(nd->nd_serial_ttdriver, &dgrp_tty_ops);
if (!(nd->nd_ttdriver_flags & SERIAL_TTDRV_REG)) {
rc = tty_register_driver(nd->nd_serial_ttdriver);
if (rc < 0) {
if (rc == -EBUSY) {
int i;
int max_majors = 1U << (32 - MINORBITS);
for (i = 256; i < max_majors; i++) {
nd->nd_serial_ttdriver->major = i;
rc = tty_register_driver(nd->nd_serial_ttdriver);
if (rc >= 0)
break;
}
if (i == max_majors)
return rc;
} else {
return rc;
}
}
nd->nd_ttdriver_flags |= SERIAL_TTDRV_REG;
}
nd->nd_callout_ttdriver = alloc_tty_driver(CHAN_MAX);
if (!nd->nd_callout_ttdriver)
return -ENOMEM;
sprintf(nd->nd_callout_name, "cu_dgrp_%s_", id);
nd->nd_callout_ttdriver->owner = THIS_MODULE;
nd->nd_callout_ttdriver->name = nd->nd_callout_name;
nd->nd_callout_ttdriver->name_base = 0;
nd->nd_callout_ttdriver->major = nd->nd_serial_ttdriver->major;
nd->nd_callout_ttdriver->minor_start = 0x40;
nd->nd_callout_ttdriver->type = TTY_DRIVER_TYPE_SERIAL;
nd->nd_callout_ttdriver->subtype = SERIAL_TYPE_CALLOUT;
nd->nd_callout_ttdriver->init_termios = DefaultTermios;
nd->nd_callout_ttdriver->driver_name = "dgrp";
nd->nd_callout_ttdriver->flags = (TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV |
TTY_DRIVER_HARDWARE_BREAK);
nd->nd_callout_ttdriver->ttys =
kzalloc(CHAN_MAX * sizeof(struct tty_struct *), GFP_KERNEL);
if (!nd->nd_callout_ttdriver->ttys)
return -ENOMEM;
tty_set_operations(nd->nd_callout_ttdriver, &dgrp_tty_ops);
if (dgrp_register_cudevices) {
if (!(nd->nd_ttdriver_flags & CALLOUT_TTDRV_REG)) {
rc = tty_register_driver(nd->nd_callout_ttdriver);
if (rc < 0)
return rc;
nd->nd_ttdriver_flags |= CALLOUT_TTDRV_REG;
}
}
nd->nd_xprint_ttdriver = alloc_tty_driver(CHAN_MAX);
if (!nd->nd_xprint_ttdriver)
return -ENOMEM;
sprintf(nd->nd_xprint_name, "pr_dgrp_%s_", id);
nd->nd_xprint_ttdriver->owner = THIS_MODULE;
nd->nd_xprint_ttdriver->name = nd->nd_xprint_name;
nd->nd_xprint_ttdriver->name_base = 0;
nd->nd_xprint_ttdriver->major = nd->nd_serial_ttdriver->major;
nd->nd_xprint_ttdriver->minor_start = 0x80;
nd->nd_xprint_ttdriver->type = TTY_DRIVER_TYPE_SERIAL;
nd->nd_xprint_ttdriver->subtype = SERIAL_TYPE_XPRINT;
nd->nd_xprint_ttdriver->init_termios = DefaultTermios;
nd->nd_xprint_ttdriver->driver_name = "dgrp";
nd->nd_xprint_ttdriver->flags = (TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV |
TTY_DRIVER_HARDWARE_BREAK);
nd->nd_xprint_ttdriver->ttys =
kzalloc(CHAN_MAX * sizeof(struct tty_struct *), GFP_KERNEL);
if (!nd->nd_xprint_ttdriver->ttys)
return -ENOMEM;
tty_set_operations(nd->nd_xprint_ttdriver, &dgrp_tty_ops);
if (dgrp_register_prdevices) {
if (!(nd->nd_ttdriver_flags & XPRINT_TTDRV_REG)) {
rc = tty_register_driver(nd->nd_xprint_ttdriver);
if (rc < 0)
return rc;
nd->nd_ttdriver_flags |= XPRINT_TTDRV_REG;
}
}
for (i = 0; i < CHAN_MAX; i++) {
struct ch_struct *ch = nd->nd_chan + i;
ch->ch_nd = nd;
ch->ch_digi = digi_init;
ch->ch_edelay = 100;
ch->ch_custom_speed = 0;
ch->ch_portnum = i;
ch->ch_tun.un_ch = ch;
ch->ch_pun.un_ch = ch;
ch->ch_tun.un_type = SERIAL_TYPE_NORMAL;
ch->ch_pun.un_type = SERIAL_TYPE_XPRINT;
init_waitqueue_head(&(ch->ch_flag_wait));
init_waitqueue_head(&(ch->ch_sleep));
init_waitqueue_head(&(ch->ch_tun.un_open_wait));
init_waitqueue_head(&(ch->ch_tun.un_close_wait));
init_waitqueue_head(&(ch->ch_pun.un_open_wait));
init_waitqueue_head(&(ch->ch_pun.un_close_wait));
tty_port_init(&ch->port);
tty_port_init(&ch->port);
}
return 0;
}
