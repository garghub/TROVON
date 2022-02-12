int tty_chars_in_buffer(struct tty_struct *tty)
{
if (tty->ops->chars_in_buffer)
return tty->ops->chars_in_buffer(tty);
else
return 0;
}
int tty_write_room(struct tty_struct *tty)
{
if (tty->ops->write_room)
return tty->ops->write_room(tty);
return 2048;
}
void tty_driver_flush_buffer(struct tty_struct *tty)
{
if (tty->ops->flush_buffer)
tty->ops->flush_buffer(tty);
}
void tty_throttle(struct tty_struct *tty)
{
down_write(&tty->termios_rwsem);
if (!test_and_set_bit(TTY_THROTTLED, &tty->flags) &&
tty->ops->throttle)
tty->ops->throttle(tty);
tty->flow_change = 0;
up_write(&tty->termios_rwsem);
}
void tty_unthrottle(struct tty_struct *tty)
{
down_write(&tty->termios_rwsem);
if (test_and_clear_bit(TTY_THROTTLED, &tty->flags) &&
tty->ops->unthrottle)
tty->ops->unthrottle(tty);
tty->flow_change = 0;
up_write(&tty->termios_rwsem);
}
int tty_throttle_safe(struct tty_struct *tty)
{
int ret = 0;
mutex_lock(&tty->throttle_mutex);
if (!test_bit(TTY_THROTTLED, &tty->flags)) {
if (tty->flow_change != TTY_THROTTLE_SAFE)
ret = 1;
else {
set_bit(TTY_THROTTLED, &tty->flags);
if (tty->ops->throttle)
tty->ops->throttle(tty);
}
}
mutex_unlock(&tty->throttle_mutex);
return ret;
}
int tty_unthrottle_safe(struct tty_struct *tty)
{
int ret = 0;
mutex_lock(&tty->throttle_mutex);
if (test_bit(TTY_THROTTLED, &tty->flags)) {
if (tty->flow_change != TTY_UNTHROTTLE_SAFE)
ret = 1;
else {
clear_bit(TTY_THROTTLED, &tty->flags);
if (tty->ops->unthrottle)
tty->ops->unthrottle(tty);
}
}
mutex_unlock(&tty->throttle_mutex);
return ret;
}
void tty_wait_until_sent(struct tty_struct *tty, long timeout)
{
tty_debug_wait_until_sent(tty, "\n");
if (!timeout)
timeout = MAX_SCHEDULE_TIMEOUT;
timeout = wait_event_interruptible_timeout(tty->write_wait,
!tty_chars_in_buffer(tty), timeout);
if (timeout <= 0)
return;
if (timeout == MAX_SCHEDULE_TIMEOUT)
timeout = 0;
if (tty->ops->wait_until_sent)
tty->ops->wait_until_sent(tty, timeout);
}
static void unset_locked_termios(struct ktermios *termios,
struct ktermios *old,
struct ktermios *locked)
{
int i;
#define NOSET_MASK(x, y, z) (x = ((x) & ~(z)) | ((y) & (z)))
if (!locked) {
printk(KERN_WARNING "Warning?!? termios_locked is NULL.\n");
return;
}
NOSET_MASK(termios->c_iflag, old->c_iflag, locked->c_iflag);
NOSET_MASK(termios->c_oflag, old->c_oflag, locked->c_oflag);
NOSET_MASK(termios->c_cflag, old->c_cflag, locked->c_cflag);
NOSET_MASK(termios->c_lflag, old->c_lflag, locked->c_lflag);
termios->c_line = locked->c_line ? old->c_line : termios->c_line;
for (i = 0; i < NCCS; i++)
termios->c_cc[i] = locked->c_cc[i] ?
old->c_cc[i] : termios->c_cc[i];
}
speed_t tty_termios_baud_rate(struct ktermios *termios)
{
unsigned int cbaud;
cbaud = termios->c_cflag & CBAUD;
#ifdef BOTHER
if (cbaud == BOTHER)
return termios->c_ospeed;
#endif
if (cbaud & CBAUDEX) {
cbaud &= ~CBAUDEX;
if (cbaud < 1 || cbaud + 15 > n_baud_table)
termios->c_cflag &= ~CBAUDEX;
else
cbaud += 15;
}
return baud_table[cbaud];
}
speed_t tty_termios_input_baud_rate(struct ktermios *termios)
{
#ifdef IBSHIFT
unsigned int cbaud = (termios->c_cflag >> IBSHIFT) & CBAUD;
if (cbaud == B0)
return tty_termios_baud_rate(termios);
if (cbaud == BOTHER)
return termios->c_ispeed;
if (cbaud & CBAUDEX) {
cbaud &= ~CBAUDEX;
if (cbaud < 1 || cbaud + 15 > n_baud_table)
termios->c_cflag &= ~(CBAUDEX << IBSHIFT);
else
cbaud += 15;
}
return baud_table[cbaud];
#else
return tty_termios_baud_rate(termios);
#endif
}
void tty_termios_encode_baud_rate(struct ktermios *termios,
speed_t ibaud, speed_t obaud)
{
int i = 0;
int ifound = -1, ofound = -1;
int iclose = ibaud/50, oclose = obaud/50;
int ibinput = 0;
if (obaud == 0)
ibaud = 0;
termios->c_ispeed = ibaud;
termios->c_ospeed = obaud;
#ifdef BOTHER
if ((termios->c_cflag & CBAUD) == BOTHER)
oclose = 0;
if (((termios->c_cflag >> IBSHIFT) & CBAUD) == BOTHER)
iclose = 0;
if ((termios->c_cflag >> IBSHIFT) & CBAUD)
ibinput = 1;
#endif
termios->c_cflag &= ~CBAUD;
do {
if (obaud - oclose <= baud_table[i] &&
obaud + oclose >= baud_table[i]) {
termios->c_cflag |= baud_bits[i];
ofound = i;
}
if (ibaud - iclose <= baud_table[i] &&
ibaud + iclose >= baud_table[i]) {
if (ofound == i && !ibinput)
ifound = i;
#ifdef IBSHIFT
else {
ifound = i;
termios->c_cflag |= (baud_bits[i] << IBSHIFT);
}
#endif
}
} while (++i < n_baud_table);
#ifdef BOTHER
if (ofound == -1)
termios->c_cflag |= BOTHER;
if (ifound == -1 && (ibaud != obaud || ibinput))
termios->c_cflag |= (BOTHER << IBSHIFT);
#else
if (ifound == -1 || ofound == -1) {
printk_once(KERN_WARNING "tty: Unable to return correct "
"speed data as your architecture needs updating.\n");
}
#endif
}
void tty_encode_baud_rate(struct tty_struct *tty, speed_t ibaud, speed_t obaud)
{
tty_termios_encode_baud_rate(&tty->termios, ibaud, obaud);
}
void tty_termios_copy_hw(struct ktermios *new, struct ktermios *old)
{
new->c_cflag &= HUPCL | CREAD | CLOCAL;
new->c_cflag |= old->c_cflag & ~(HUPCL | CREAD | CLOCAL);
new->c_ispeed = old->c_ispeed;
new->c_ospeed = old->c_ospeed;
}
int tty_termios_hw_change(struct ktermios *a, struct ktermios *b)
{
if (a->c_ispeed != b->c_ispeed || a->c_ospeed != b->c_ospeed)
return 1;
if ((a->c_cflag ^ b->c_cflag) & ~(HUPCL | CREAD | CLOCAL))
return 1;
return 0;
}
int tty_set_termios(struct tty_struct *tty, struct ktermios *new_termios)
{
struct ktermios old_termios;
struct tty_ldisc *ld;
WARN_ON(tty->driver->type == TTY_DRIVER_TYPE_PTY &&
tty->driver->subtype == PTY_TYPE_MASTER);
down_write(&tty->termios_rwsem);
old_termios = tty->termios;
tty->termios = *new_termios;
unset_locked_termios(&tty->termios, &old_termios, &tty->termios_locked);
if (tty->ops->set_termios)
tty->ops->set_termios(tty, &old_termios);
else
tty_termios_copy_hw(&tty->termios, &old_termios);
ld = tty_ldisc_ref(tty);
if (ld != NULL) {
if (ld->ops->set_termios)
ld->ops->set_termios(tty, &old_termios);
tty_ldisc_deref(ld);
}
up_write(&tty->termios_rwsem);
return 0;
}
static int set_termios(struct tty_struct *tty, void __user *arg, int opt)
{
struct ktermios tmp_termios;
struct tty_ldisc *ld;
int retval = tty_check_change(tty);
if (retval)
return retval;
down_read(&tty->termios_rwsem);
tmp_termios = tty->termios;
up_read(&tty->termios_rwsem);
if (opt & TERMIOS_TERMIO) {
if (user_termio_to_kernel_termios(&tmp_termios,
(struct termio __user *)arg))
return -EFAULT;
#ifdef TCGETS2
} else if (opt & TERMIOS_OLD) {
if (user_termios_to_kernel_termios_1(&tmp_termios,
(struct termios __user *)arg))
return -EFAULT;
} else {
if (user_termios_to_kernel_termios(&tmp_termios,
(struct termios2 __user *)arg))
return -EFAULT;
}
#else
}
void copy_termios(struct tty_struct *tty, struct ktermios *kterm)
{
down_read(&tty->termios_rwsem);
*kterm = tty->termios;
up_read(&tty->termios_rwsem);
}
static void copy_termios_locked(struct tty_struct *tty, struct ktermios *kterm)
{
down_read(&tty->termios_rwsem);
*kterm = tty->termios_locked;
up_read(&tty->termios_rwsem);
}
static int get_termio(struct tty_struct *tty, struct termio __user *termio)
{
struct ktermios kterm;
copy_termios(tty, &kterm);
if (kernel_termios_to_user_termio(termio, &kterm))
return -EFAULT;
return 0;
}
static int set_termiox(struct tty_struct *tty, void __user *arg, int opt)
{
struct termiox tnew;
struct tty_ldisc *ld;
if (tty->termiox == NULL)
return -EINVAL;
if (copy_from_user(&tnew, arg, sizeof(struct termiox)))
return -EFAULT;
ld = tty_ldisc_ref(tty);
if (ld != NULL) {
if ((opt & TERMIOS_FLUSH) && ld->ops->flush_buffer)
ld->ops->flush_buffer(tty);
tty_ldisc_deref(ld);
}
if (opt & TERMIOS_WAIT) {
tty_wait_until_sent(tty, 0);
if (signal_pending(current))
return -ERESTARTSYS;
}
down_write(&tty->termios_rwsem);
if (tty->ops->set_termiox)
tty->ops->set_termiox(tty, &tnew);
up_write(&tty->termios_rwsem);
return 0;
}
static int get_sgflags(struct tty_struct *tty)
{
int flags = 0;
if (!(tty->termios.c_lflag & ICANON)) {
if (tty->termios.c_lflag & ISIG)
flags |= 0x02;
else
flags |= 0x20;
}
if (tty->termios.c_lflag & ECHO)
flags |= 0x08;
if (tty->termios.c_oflag & OPOST)
if (tty->termios.c_oflag & ONLCR)
flags |= 0x10;
return flags;
}
static int get_sgttyb(struct tty_struct *tty, struct sgttyb __user *sgttyb)
{
struct sgttyb tmp;
down_read(&tty->termios_rwsem);
tmp.sg_ispeed = tty->termios.c_ispeed;
tmp.sg_ospeed = tty->termios.c_ospeed;
tmp.sg_erase = tty->termios.c_cc[VERASE];
tmp.sg_kill = tty->termios.c_cc[VKILL];
tmp.sg_flags = get_sgflags(tty);
up_read(&tty->termios_rwsem);
return copy_to_user(sgttyb, &tmp, sizeof(tmp)) ? -EFAULT : 0;
}
static void set_sgflags(struct ktermios *termios, int flags)
{
termios->c_iflag = ICRNL | IXON;
termios->c_oflag = 0;
termios->c_lflag = ISIG | ICANON;
if (flags & 0x02) {
termios->c_iflag = 0;
termios->c_lflag &= ~ICANON;
}
if (flags & 0x08) {
termios->c_lflag |= ECHO | ECHOE | ECHOK |
ECHOCTL | ECHOKE | IEXTEN;
}
if (flags & 0x10) {
termios->c_oflag |= OPOST | ONLCR;
}
if (flags & 0x20) {
termios->c_iflag = 0;
termios->c_lflag &= ~(ISIG | ICANON);
}
if (!(termios->c_lflag & ICANON)) {
termios->c_cc[VMIN] = 1;
termios->c_cc[VTIME] = 0;
}
}
static int set_sgttyb(struct tty_struct *tty, struct sgttyb __user *sgttyb)
{
int retval;
struct sgttyb tmp;
struct ktermios termios;
retval = tty_check_change(tty);
if (retval)
return retval;
if (copy_from_user(&tmp, sgttyb, sizeof(tmp)))
return -EFAULT;
down_write(&tty->termios_rwsem);
termios = tty->termios;
termios.c_cc[VERASE] = tmp.sg_erase;
termios.c_cc[VKILL] = tmp.sg_kill;
set_sgflags(&termios, tmp.sg_flags);
#ifdef BOTHER
tty_termios_encode_baud_rate(&termios, termios.c_ispeed,
termios.c_ospeed);
#endif
up_write(&tty->termios_rwsem);
tty_set_termios(tty, &termios);
return 0;
}
static int get_tchars(struct tty_struct *tty, struct tchars __user *tchars)
{
struct tchars tmp;
down_read(&tty->termios_rwsem);
tmp.t_intrc = tty->termios.c_cc[VINTR];
tmp.t_quitc = tty->termios.c_cc[VQUIT];
tmp.t_startc = tty->termios.c_cc[VSTART];
tmp.t_stopc = tty->termios.c_cc[VSTOP];
tmp.t_eofc = tty->termios.c_cc[VEOF];
tmp.t_brkc = tty->termios.c_cc[VEOL2];
up_read(&tty->termios_rwsem);
return copy_to_user(tchars, &tmp, sizeof(tmp)) ? -EFAULT : 0;
}
static int set_tchars(struct tty_struct *tty, struct tchars __user *tchars)
{
struct tchars tmp;
if (copy_from_user(&tmp, tchars, sizeof(tmp)))
return -EFAULT;
down_write(&tty->termios_rwsem);
tty->termios.c_cc[VINTR] = tmp.t_intrc;
tty->termios.c_cc[VQUIT] = tmp.t_quitc;
tty->termios.c_cc[VSTART] = tmp.t_startc;
tty->termios.c_cc[VSTOP] = tmp.t_stopc;
tty->termios.c_cc[VEOF] = tmp.t_eofc;
tty->termios.c_cc[VEOL2] = tmp.t_brkc;
up_write(&tty->termios_rwsem);
return 0;
}
static int get_ltchars(struct tty_struct *tty, struct ltchars __user *ltchars)
{
struct ltchars tmp;
down_read(&tty->termios_rwsem);
tmp.t_suspc = tty->termios.c_cc[VSUSP];
tmp.t_dsuspc = tty->termios.c_cc[VSUSP];
tmp.t_rprntc = tty->termios.c_cc[VREPRINT];
tmp.t_flushc = tty->termios.c_cc[VEOL2];
tmp.t_werasc = tty->termios.c_cc[VWERASE];
tmp.t_lnextc = tty->termios.c_cc[VLNEXT];
up_read(&tty->termios_rwsem);
return copy_to_user(ltchars, &tmp, sizeof(tmp)) ? -EFAULT : 0;
}
static int set_ltchars(struct tty_struct *tty, struct ltchars __user *ltchars)
{
struct ltchars tmp;
if (copy_from_user(&tmp, ltchars, sizeof(tmp)))
return -EFAULT;
down_write(&tty->termios_rwsem);
tty->termios.c_cc[VSUSP] = tmp.t_suspc;
tty->termios.c_cc[VEOL2] = tmp.t_dsuspc;
tty->termios.c_cc[VREPRINT] = tmp.t_rprntc;
tty->termios.c_cc[VEOL2] = tmp.t_flushc;
tty->termios.c_cc[VWERASE] = tmp.t_werasc;
tty->termios.c_cc[VLNEXT] = tmp.t_lnextc;
up_write(&tty->termios_rwsem);
return 0;
}
static int tty_change_softcar(struct tty_struct *tty, int arg)
{
int ret = 0;
int bit = arg ? CLOCAL : 0;
struct ktermios old;
down_write(&tty->termios_rwsem);
old = tty->termios;
tty->termios.c_cflag &= ~CLOCAL;
tty->termios.c_cflag |= bit;
if (tty->ops->set_termios)
tty->ops->set_termios(tty, &old);
if ((tty->termios.c_cflag & CLOCAL) != bit)
ret = -EINVAL;
up_write(&tty->termios_rwsem);
return ret;
}
int tty_mode_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct tty_struct *real_tty;
void __user *p = (void __user *)arg;
int ret = 0;
struct ktermios kterm;
BUG_ON(file == NULL);
if (tty->driver->type == TTY_DRIVER_TYPE_PTY &&
tty->driver->subtype == PTY_TYPE_MASTER)
real_tty = tty->link;
else
real_tty = tty;
switch (cmd) {
#ifdef TIOCGETP
case TIOCGETP:
return get_sgttyb(real_tty, (struct sgttyb __user *) arg);
case TIOCSETP:
case TIOCSETN:
return set_sgttyb(real_tty, (struct sgttyb __user *) arg);
#endif
#ifdef TIOCGETC
case TIOCGETC:
return get_tchars(real_tty, p);
case TIOCSETC:
return set_tchars(real_tty, p);
#endif
#ifdef TIOCGLTC
case TIOCGLTC:
return get_ltchars(real_tty, p);
case TIOCSLTC:
return set_ltchars(real_tty, p);
#endif
case TCSETSF:
return set_termios(real_tty, p, TERMIOS_FLUSH | TERMIOS_WAIT | TERMIOS_OLD);
case TCSETSW:
return set_termios(real_tty, p, TERMIOS_WAIT | TERMIOS_OLD);
case TCSETS:
return set_termios(real_tty, p, TERMIOS_OLD);
#ifndef TCGETS2
case TCGETS:
copy_termios(real_tty, &kterm);
if (kernel_termios_to_user_termios((struct termios __user *)arg, &kterm))
ret = -EFAULT;
return ret;
#else
case TCGETS:
copy_termios(real_tty, &kterm);
if (kernel_termios_to_user_termios_1((struct termios __user *)arg, &kterm))
ret = -EFAULT;
return ret;
case TCGETS2:
copy_termios(real_tty, &kterm);
if (kernel_termios_to_user_termios((struct termios2 __user *)arg, &kterm))
ret = -EFAULT;
return ret;
case TCSETSF2:
return set_termios(real_tty, p, TERMIOS_FLUSH | TERMIOS_WAIT);
case TCSETSW2:
return set_termios(real_tty, p, TERMIOS_WAIT);
case TCSETS2:
return set_termios(real_tty, p, 0);
#endif
case TCGETA:
return get_termio(real_tty, p);
case TCSETAF:
return set_termios(real_tty, p, TERMIOS_FLUSH | TERMIOS_WAIT | TERMIOS_TERMIO);
case TCSETAW:
return set_termios(real_tty, p, TERMIOS_WAIT | TERMIOS_TERMIO);
case TCSETA:
return set_termios(real_tty, p, TERMIOS_TERMIO);
#ifndef TCGETS2
case TIOCGLCKTRMIOS:
copy_termios_locked(real_tty, &kterm);
if (kernel_termios_to_user_termios((struct termios __user *)arg, &kterm))
ret = -EFAULT;
return ret;
case TIOCSLCKTRMIOS:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
copy_termios_locked(real_tty, &kterm);
if (user_termios_to_kernel_termios(&kterm,
(struct termios __user *) arg))
return -EFAULT;
down_write(&real_tty->termios_rwsem);
real_tty->termios_locked = kterm;
up_write(&real_tty->termios_rwsem);
return 0;
#else
case TIOCGLCKTRMIOS:
copy_termios_locked(real_tty, &kterm);
if (kernel_termios_to_user_termios_1((struct termios __user *)arg, &kterm))
ret = -EFAULT;
return ret;
case TIOCSLCKTRMIOS:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
copy_termios_locked(real_tty, &kterm);
if (user_termios_to_kernel_termios_1(&kterm,
(struct termios __user *) arg))
return -EFAULT;
down_write(&real_tty->termios_rwsem);
real_tty->termios_locked = kterm;
up_write(&real_tty->termios_rwsem);
return ret;
#endif
#ifdef TCGETX
case TCGETX: {
struct termiox ktermx;
if (real_tty->termiox == NULL)
return -EINVAL;
down_read(&real_tty->termios_rwsem);
memcpy(&ktermx, real_tty->termiox, sizeof(struct termiox));
up_read(&real_tty->termios_rwsem);
if (copy_to_user(p, &ktermx, sizeof(struct termiox)))
ret = -EFAULT;
return ret;
}
case TCSETX:
return set_termiox(real_tty, p, 0);
case TCSETXW:
return set_termiox(real_tty, p, TERMIOS_WAIT);
case TCSETXF:
return set_termiox(real_tty, p, TERMIOS_FLUSH);
#endif
case TIOCGSOFTCAR:
copy_termios(real_tty, &kterm);
ret = put_user((kterm.c_cflag & CLOCAL) ? 1 : 0,
(int __user *)arg);
return ret;
case TIOCSSOFTCAR:
if (get_user(arg, (unsigned int __user *) arg))
return -EFAULT;
return tty_change_softcar(real_tty, arg);
default:
return -ENOIOCTLCMD;
}
}
static int __tty_perform_flush(struct tty_struct *tty, unsigned long arg)
{
struct tty_ldisc *ld = tty->ldisc;
switch (arg) {
case TCIFLUSH:
if (ld && ld->ops->flush_buffer) {
ld->ops->flush_buffer(tty);
tty_unthrottle(tty);
}
break;
case TCIOFLUSH:
if (ld && ld->ops->flush_buffer) {
ld->ops->flush_buffer(tty);
tty_unthrottle(tty);
}
case TCOFLUSH:
tty_driver_flush_buffer(tty);
break;
default:
return -EINVAL;
}
return 0;
}
int tty_perform_flush(struct tty_struct *tty, unsigned long arg)
{
struct tty_ldisc *ld;
int retval = tty_check_change(tty);
if (retval)
return retval;
ld = tty_ldisc_ref_wait(tty);
retval = __tty_perform_flush(tty, arg);
if (ld)
tty_ldisc_deref(ld);
return retval;
}
int n_tty_ioctl_helper(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
int retval;
switch (cmd) {
case TCXONC:
retval = tty_check_change(tty);
if (retval)
return retval;
switch (arg) {
case TCOOFF:
spin_lock_irq(&tty->flow_lock);
if (!tty->flow_stopped) {
tty->flow_stopped = 1;
__stop_tty(tty);
}
spin_unlock_irq(&tty->flow_lock);
break;
case TCOON:
spin_lock_irq(&tty->flow_lock);
if (tty->flow_stopped) {
tty->flow_stopped = 0;
__start_tty(tty);
}
spin_unlock_irq(&tty->flow_lock);
break;
case TCIOFF:
down_read(&tty->termios_rwsem);
if (STOP_CHAR(tty) != __DISABLED_CHAR)
retval = tty_send_xchar(tty, STOP_CHAR(tty));
up_read(&tty->termios_rwsem);
break;
case TCION:
down_read(&tty->termios_rwsem);
if (START_CHAR(tty) != __DISABLED_CHAR)
retval = tty_send_xchar(tty, START_CHAR(tty));
up_read(&tty->termios_rwsem);
break;
default:
return -EINVAL;
}
return retval;
case TCFLSH:
retval = tty_check_change(tty);
if (retval)
return retval;
return __tty_perform_flush(tty, arg);
default:
return tty_mode_ioctl(tty, file, cmd, arg);
}
}
long n_tty_compat_ioctl_helper(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case TIOCGLCKTRMIOS:
case TIOCSLCKTRMIOS:
return tty_mode_ioctl(tty, file, cmd, (unsigned long) compat_ptr(arg));
default:
return -ENOIOCTLCMD;
}
}
