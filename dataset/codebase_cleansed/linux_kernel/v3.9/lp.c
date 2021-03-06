static void lp_claim_parport_or_block(struct lp_struct *this_lp)
{
if (!test_and_set_bit(LP_PARPORT_CLAIMED, &this_lp->bits)) {
parport_claim_or_block (this_lp->dev);
}
}
static void lp_release_parport(struct lp_struct *this_lp)
{
if (test_and_clear_bit(LP_PARPORT_CLAIMED, &this_lp->bits)) {
parport_release (this_lp->dev);
}
}
static int lp_preempt(void *handle)
{
struct lp_struct *this_lp = (struct lp_struct *)handle;
set_bit(LP_PREEMPT_REQUEST, &this_lp->bits);
return (1);
}
static int lp_negotiate(struct parport * port, int mode)
{
if (parport_negotiate (port, mode) != 0) {
mode = IEEE1284_MODE_COMPAT;
parport_negotiate (port, mode);
}
return (mode);
}
static int lp_reset(int minor)
{
int retval;
lp_claim_parport_or_block (&lp_table[minor]);
w_ctr(minor, LP_PSELECP);
udelay (LP_DELAY);
w_ctr(minor, LP_PSELECP | LP_PINITP);
retval = r_str(minor);
lp_release_parport (&lp_table[minor]);
return retval;
}
static void lp_error (int minor)
{
DEFINE_WAIT(wait);
int polling;
if (LP_F(minor) & LP_ABORT)
return;
polling = lp_table[minor].dev->port->irq == PARPORT_IRQ_NONE;
if (polling) lp_release_parport (&lp_table[minor]);
prepare_to_wait(&lp_table[minor].waitq, &wait, TASK_INTERRUPTIBLE);
schedule_timeout(LP_TIMEOUT_POLLED);
finish_wait(&lp_table[minor].waitq, &wait);
if (polling) lp_claim_parport_or_block (&lp_table[minor]);
else parport_yield_blocking (lp_table[minor].dev);
}
static int lp_check_status(int minor)
{
int error = 0;
unsigned int last = lp_table[minor].last_error;
unsigned char status = r_str(minor);
if ((status & LP_PERRORP) && !(LP_F(minor) & LP_CAREFUL))
last = 0;
else if ((status & LP_POUTPA)) {
if (last != LP_POUTPA) {
last = LP_POUTPA;
printk(KERN_INFO "lp%d out of paper\n", minor);
}
error = -ENOSPC;
} else if (!(status & LP_PSELECD)) {
if (last != LP_PSELECD) {
last = LP_PSELECD;
printk(KERN_INFO "lp%d off-line\n", minor);
}
error = -EIO;
} else if (!(status & LP_PERRORP)) {
if (last != LP_PERRORP) {
last = LP_PERRORP;
printk(KERN_INFO "lp%d on fire\n", minor);
}
error = -EIO;
} else {
last = 0;
}
lp_table[minor].last_error = last;
if (last != 0)
lp_error(minor);
return error;
}
static int lp_wait_ready(int minor, int nonblock)
{
int error = 0;
if (lp_table[minor].current_mode != IEEE1284_MODE_COMPAT) {
return (0);
}
do {
error = lp_check_status (minor);
if (error && (nonblock || (LP_F(minor) & LP_ABORT)))
break;
if (signal_pending (current)) {
error = -EINTR;
break;
}
} while (error);
return error;
}
static ssize_t lp_write(struct file * file, const char __user * buf,
size_t count, loff_t *ppos)
{
unsigned int minor = iminor(file_inode(file));
struct parport *port = lp_table[minor].dev->port;
char *kbuf = lp_table[minor].lp_buffer;
ssize_t retv = 0;
ssize_t written;
size_t copy_size = count;
int nonblock = ((file->f_flags & O_NONBLOCK) ||
(LP_F(minor) & LP_ABORT));
#ifdef LP_STATS
if (time_after(jiffies, lp_table[minor].lastcall + LP_TIME(minor)))
lp_table[minor].runchars = 0;
lp_table[minor].lastcall = jiffies;
#endif
if (copy_size > LP_BUFFER_SIZE)
copy_size = LP_BUFFER_SIZE;
if (mutex_lock_interruptible(&lp_table[minor].port_mutex))
return -EINTR;
if (copy_from_user (kbuf, buf, copy_size)) {
retv = -EFAULT;
goto out_unlock;
}
lp_claim_parport_or_block (&lp_table[minor]);
lp_table[minor].current_mode = lp_negotiate (port,
lp_table[minor].best_mode);
parport_set_timeout (lp_table[minor].dev,
(nonblock ? PARPORT_INACTIVITY_O_NONBLOCK
: lp_table[minor].timeout));
if ((retv = lp_wait_ready (minor, nonblock)) == 0)
do {
written = parport_write (port, kbuf, copy_size);
if (written > 0) {
copy_size -= written;
count -= written;
buf += written;
retv += written;
}
if (signal_pending (current)) {
if (retv == 0)
retv = -EINTR;
break;
}
if (copy_size > 0) {
int error;
parport_negotiate (lp_table[minor].dev->port,
IEEE1284_MODE_COMPAT);
lp_table[minor].current_mode = IEEE1284_MODE_COMPAT;
error = lp_wait_ready (minor, nonblock);
if (error) {
if (retv == 0)
retv = error;
break;
} else if (nonblock) {
if (retv == 0)
retv = -EAGAIN;
break;
}
parport_yield_blocking (lp_table[minor].dev);
lp_table[minor].current_mode
= lp_negotiate (port,
lp_table[minor].best_mode);
} else if (need_resched())
schedule ();
if (count) {
copy_size = count;
if (copy_size > LP_BUFFER_SIZE)
copy_size = LP_BUFFER_SIZE;
if (copy_from_user(kbuf, buf, copy_size)) {
if (retv == 0)
retv = -EFAULT;
break;
}
}
} while (count > 0);
if (test_and_clear_bit(LP_PREEMPT_REQUEST,
&lp_table[minor].bits)) {
printk(KERN_INFO "lp%d releasing parport\n", minor);
parport_negotiate (lp_table[minor].dev->port,
IEEE1284_MODE_COMPAT);
lp_table[minor].current_mode = IEEE1284_MODE_COMPAT;
lp_release_parport (&lp_table[minor]);
}
out_unlock:
mutex_unlock(&lp_table[minor].port_mutex);
return retv;
}
static ssize_t lp_read(struct file * file, char __user * buf,
size_t count, loff_t *ppos)
{
DEFINE_WAIT(wait);
unsigned int minor=iminor(file_inode(file));
struct parport *port = lp_table[minor].dev->port;
ssize_t retval = 0;
char *kbuf = lp_table[minor].lp_buffer;
int nonblock = ((file->f_flags & O_NONBLOCK) ||
(LP_F(minor) & LP_ABORT));
if (count > LP_BUFFER_SIZE)
count = LP_BUFFER_SIZE;
if (mutex_lock_interruptible(&lp_table[minor].port_mutex))
return -EINTR;
lp_claim_parport_or_block (&lp_table[minor]);
parport_set_timeout (lp_table[minor].dev,
(nonblock ? PARPORT_INACTIVITY_O_NONBLOCK
: lp_table[minor].timeout));
parport_negotiate (lp_table[minor].dev->port, IEEE1284_MODE_COMPAT);
if (parport_negotiate (lp_table[minor].dev->port,
IEEE1284_MODE_NIBBLE)) {
retval = -EIO;
goto out;
}
while (retval == 0) {
retval = parport_read (port, kbuf, count);
if (retval > 0)
break;
if (nonblock) {
retval = -EAGAIN;
break;
}
if (lp_table[minor].dev->port->irq == PARPORT_IRQ_NONE) {
parport_negotiate (lp_table[minor].dev->port,
IEEE1284_MODE_COMPAT);
lp_error (minor);
if (parport_negotiate (lp_table[minor].dev->port,
IEEE1284_MODE_NIBBLE)) {
retval = -EIO;
goto out;
}
} else {
prepare_to_wait(&lp_table[minor].waitq, &wait, TASK_INTERRUPTIBLE);
schedule_timeout(LP_TIMEOUT_POLLED);
finish_wait(&lp_table[minor].waitq, &wait);
}
if (signal_pending (current)) {
retval = -ERESTARTSYS;
break;
}
cond_resched ();
}
parport_negotiate (lp_table[minor].dev->port, IEEE1284_MODE_COMPAT);
out:
lp_release_parport (&lp_table[minor]);
if (retval > 0 && copy_to_user (buf, kbuf, retval))
retval = -EFAULT;
mutex_unlock(&lp_table[minor].port_mutex);
return retval;
}
static int lp_open(struct inode * inode, struct file * file)
{
unsigned int minor = iminor(inode);
int ret = 0;
mutex_lock(&lp_mutex);
if (minor >= LP_NO) {
ret = -ENXIO;
goto out;
}
if ((LP_F(minor) & LP_EXIST) == 0) {
ret = -ENXIO;
goto out;
}
if (test_and_set_bit(LP_BUSY_BIT_POS, &LP_F(minor))) {
ret = -EBUSY;
goto out;
}
if ((LP_F(minor) & LP_ABORTOPEN) && !(file->f_flags & O_NONBLOCK)) {
int status;
lp_claim_parport_or_block (&lp_table[minor]);
status = r_str(minor);
lp_release_parport (&lp_table[minor]);
if (status & LP_POUTPA) {
printk(KERN_INFO "lp%d out of paper\n", minor);
LP_F(minor) &= ~LP_BUSY;
ret = -ENOSPC;
goto out;
} else if (!(status & LP_PSELECD)) {
printk(KERN_INFO "lp%d off-line\n", minor);
LP_F(minor) &= ~LP_BUSY;
ret = -EIO;
goto out;
} else if (!(status & LP_PERRORP)) {
printk(KERN_ERR "lp%d printer error\n", minor);
LP_F(minor) &= ~LP_BUSY;
ret = -EIO;
goto out;
}
}
lp_table[minor].lp_buffer = kmalloc(LP_BUFFER_SIZE, GFP_KERNEL);
if (!lp_table[minor].lp_buffer) {
LP_F(minor) &= ~LP_BUSY;
ret = -ENOMEM;
goto out;
}
lp_claim_parport_or_block (&lp_table[minor]);
if ( (lp_table[minor].dev->port->modes & PARPORT_MODE_ECP) &&
!parport_negotiate (lp_table[minor].dev->port,
IEEE1284_MODE_ECP)) {
printk (KERN_INFO "lp%d: ECP mode\n", minor);
lp_table[minor].best_mode = IEEE1284_MODE_ECP;
} else {
lp_table[minor].best_mode = IEEE1284_MODE_COMPAT;
}
parport_negotiate (lp_table[minor].dev->port, IEEE1284_MODE_COMPAT);
lp_release_parport (&lp_table[minor]);
lp_table[minor].current_mode = IEEE1284_MODE_COMPAT;
out:
mutex_unlock(&lp_mutex);
return ret;
}
static int lp_release(struct inode * inode, struct file * file)
{
unsigned int minor = iminor(inode);
lp_claim_parport_or_block (&lp_table[minor]);
parport_negotiate (lp_table[minor].dev->port, IEEE1284_MODE_COMPAT);
lp_table[minor].current_mode = IEEE1284_MODE_COMPAT;
lp_release_parport (&lp_table[minor]);
kfree(lp_table[minor].lp_buffer);
lp_table[minor].lp_buffer = NULL;
LP_F(minor) &= ~LP_BUSY;
return 0;
}
static int lp_do_ioctl(unsigned int minor, unsigned int cmd,
unsigned long arg, void __user *argp)
{
int status;
int retval = 0;
#ifdef LP_DEBUG
printk(KERN_DEBUG "lp%d ioctl, cmd: 0x%x, arg: 0x%lx\n", minor, cmd, arg);
#endif
if (minor >= LP_NO)
return -ENODEV;
if ((LP_F(minor) & LP_EXIST) == 0)
return -ENODEV;
switch ( cmd ) {
case LPTIME:
LP_TIME(minor) = arg * HZ/100;
break;
case LPCHAR:
LP_CHAR(minor) = arg;
break;
case LPABORT:
if (arg)
LP_F(minor) |= LP_ABORT;
else
LP_F(minor) &= ~LP_ABORT;
break;
case LPABORTOPEN:
if (arg)
LP_F(minor) |= LP_ABORTOPEN;
else
LP_F(minor) &= ~LP_ABORTOPEN;
break;
case LPCAREFUL:
if (arg)
LP_F(minor) |= LP_CAREFUL;
else
LP_F(minor) &= ~LP_CAREFUL;
break;
case LPWAIT:
LP_WAIT(minor) = arg;
break;
case LPSETIRQ:
return -EINVAL;
break;
case LPGETIRQ:
if (copy_to_user(argp, &LP_IRQ(minor),
sizeof(int)))
return -EFAULT;
break;
case LPGETSTATUS:
lp_claim_parport_or_block (&lp_table[minor]);
status = r_str(minor);
lp_release_parport (&lp_table[minor]);
if (copy_to_user(argp, &status, sizeof(int)))
return -EFAULT;
break;
case LPRESET:
lp_reset(minor);
break;
#ifdef LP_STATS
case LPGETSTATS:
if (copy_to_user(argp, &LP_STAT(minor),
sizeof(struct lp_stats)))
return -EFAULT;
if (capable(CAP_SYS_ADMIN))
memset(&LP_STAT(minor), 0,
sizeof(struct lp_stats));
break;
#endif
case LPGETFLAGS:
status = LP_F(minor);
if (copy_to_user(argp, &status, sizeof(int)))
return -EFAULT;
break;
default:
retval = -EINVAL;
}
return retval;
}
static int lp_set_timeout(unsigned int minor, struct timeval *par_timeout)
{
long to_jiffies;
if ((par_timeout->tv_sec < 0) ||
(par_timeout->tv_usec < 0)) {
return -EINVAL;
}
to_jiffies = DIV_ROUND_UP(par_timeout->tv_usec, 1000000/HZ);
to_jiffies += par_timeout->tv_sec * (long) HZ;
if (to_jiffies <= 0) {
return -EINVAL;
}
lp_table[minor].timeout = to_jiffies;
return 0;
}
static long lp_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
unsigned int minor;
struct timeval par_timeout;
int ret;
minor = iminor(file_inode(file));
mutex_lock(&lp_mutex);
switch (cmd) {
case LPSETTIMEOUT:
if (copy_from_user(&par_timeout, (void __user *)arg,
sizeof (struct timeval))) {
ret = -EFAULT;
break;
}
ret = lp_set_timeout(minor, &par_timeout);
break;
default:
ret = lp_do_ioctl(minor, cmd, arg, (void __user *)arg);
break;
}
mutex_unlock(&lp_mutex);
return ret;
}
static long lp_compat_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
unsigned int minor;
struct timeval par_timeout;
int ret;
minor = iminor(file_inode(file));
mutex_lock(&lp_mutex);
switch (cmd) {
case LPSETTIMEOUT:
if (compat_get_timeval(&par_timeout, compat_ptr(arg))) {
ret = -EFAULT;
break;
}
ret = lp_set_timeout(minor, &par_timeout);
break;
#ifdef LP_STATS
case LPGETSTATS:
ret = -EINVAL;
break;
#endif
default:
ret = lp_do_ioctl(minor, cmd, arg, compat_ptr(arg));
break;
}
mutex_unlock(&lp_mutex);
return ret;
}
static void lp_console_write (struct console *co, const char *s,
unsigned count)
{
struct pardevice *dev = lp_table[CONSOLE_LP].dev;
struct parport *port = dev->port;
ssize_t written;
if (parport_claim (dev))
return;
parport_set_timeout (dev, 0);
parport_negotiate (port, IEEE1284_MODE_COMPAT);
do {
ssize_t canwrite = count;
char *lf = memchr (s, '\n', count);
if (lf)
canwrite = lf - s;
if (canwrite > 0) {
written = parport_write (port, s, canwrite);
if (written <= 0)
continue;
s += written;
count -= written;
canwrite -= written;
}
if (lf && canwrite <= 0) {
const char *crlf = "\r\n";
int i = 2;
s++;
count--;
do {
written = parport_write (port, crlf, i);
if (written > 0)
i -= written, crlf += written;
} while (i > 0 && (CONSOLE_LP_STRICT || written > 0));
}
} while (count > 0 && (CONSOLE_LP_STRICT || written > 0));
parport_release (dev);
}
static int __init lp_setup (char *str)
{
static int parport_ptr;
int x;
if (get_option(&str, &x)) {
if (x == 0) {
parport_nr[0] = LP_PARPORT_OFF;
} else {
printk(KERN_WARNING "warning: 'lp=0x%x' is deprecated, ignored\n", x);
return 0;
}
} else if (!strncmp(str, "parport", 7)) {
int n = simple_strtoul(str+7, NULL, 10);
if (parport_ptr < LP_NO)
parport_nr[parport_ptr++] = n;
else
printk(KERN_INFO "lp: too many ports, %s ignored.\n",
str);
} else if (!strcmp(str, "auto")) {
parport_nr[0] = LP_PARPORT_AUTO;
} else if (!strcmp(str, "none")) {
parport_nr[parport_ptr++] = LP_PARPORT_NONE;
} else if (!strcmp(str, "reset")) {
reset = 1;
}
return 1;
}
static int lp_register(int nr, struct parport *port)
{
lp_table[nr].dev = parport_register_device(port, "lp",
lp_preempt, NULL, NULL, 0,
(void *) &lp_table[nr]);
if (lp_table[nr].dev == NULL)
return 1;
lp_table[nr].flags |= LP_EXIST;
if (reset)
lp_reset(nr);
device_create(lp_class, port->dev, MKDEV(LP_MAJOR, nr), NULL,
"lp%d", nr);
printk(KERN_INFO "lp%d: using %s (%s).\n", nr, port->name,
(port->irq == PARPORT_IRQ_NONE)?"polling":"interrupt-driven");
#ifdef CONFIG_LP_CONSOLE
if (!nr) {
if (port->modes & PARPORT_MODE_SAFEININT) {
register_console(&lpcons);
console_registered = port;
printk (KERN_INFO "lp%d: console ready\n", CONSOLE_LP);
} else
printk (KERN_ERR "lp%d: cannot run console on %s\n",
CONSOLE_LP, port->name);
}
#endif
return 0;
}
static void lp_attach (struct parport *port)
{
unsigned int i;
switch (parport_nr[0]) {
case LP_PARPORT_UNSPEC:
case LP_PARPORT_AUTO:
if (parport_nr[0] == LP_PARPORT_AUTO &&
port->probe_info[0].class != PARPORT_CLASS_PRINTER)
return;
if (lp_count == LP_NO) {
printk(KERN_INFO "lp: ignoring parallel port (max. %d)\n",LP_NO);
return;
}
if (!lp_register(lp_count, port))
lp_count++;
break;
default:
for (i = 0; i < LP_NO; i++) {
if (port->number == parport_nr[i]) {
if (!lp_register(i, port))
lp_count++;
break;
}
}
break;
}
}
static void lp_detach (struct parport *port)
{
#ifdef CONFIG_LP_CONSOLE
if (console_registered == port) {
unregister_console(&lpcons);
console_registered = NULL;
}
#endif
}
static int __init lp_init (void)
{
int i, err = 0;
if (parport_nr[0] == LP_PARPORT_OFF)
return 0;
for (i = 0; i < LP_NO; i++) {
lp_table[i].dev = NULL;
lp_table[i].flags = 0;
lp_table[i].chars = LP_INIT_CHAR;
lp_table[i].time = LP_INIT_TIME;
lp_table[i].wait = LP_INIT_WAIT;
lp_table[i].lp_buffer = NULL;
#ifdef LP_STATS
lp_table[i].lastcall = 0;
lp_table[i].runchars = 0;
memset (&lp_table[i].stats, 0, sizeof (struct lp_stats));
#endif
lp_table[i].last_error = 0;
init_waitqueue_head (&lp_table[i].waitq);
init_waitqueue_head (&lp_table[i].dataq);
mutex_init(&lp_table[i].port_mutex);
lp_table[i].timeout = 10 * HZ;
}
if (register_chrdev (LP_MAJOR, "lp", &lp_fops)) {
printk (KERN_ERR "lp: unable to get major %d\n", LP_MAJOR);
return -EIO;
}
lp_class = class_create(THIS_MODULE, "printer");
if (IS_ERR(lp_class)) {
err = PTR_ERR(lp_class);
goto out_reg;
}
if (parport_register_driver (&lp_driver)) {
printk (KERN_ERR "lp: unable to register with parport\n");
err = -EIO;
goto out_class;
}
if (!lp_count) {
printk (KERN_INFO "lp: driver loaded but no devices found\n");
#ifndef CONFIG_PARPORT_1284
if (parport_nr[0] == LP_PARPORT_AUTO)
printk (KERN_INFO "lp: (is IEEE 1284 support enabled?)\n");
#endif
}
return 0;
out_class:
class_destroy(lp_class);
out_reg:
unregister_chrdev(LP_MAJOR, "lp");
return err;
}
static int __init lp_init_module (void)
{
if (parport[0]) {
if (!strncmp(parport[0], "auto", 4))
parport_nr[0] = LP_PARPORT_AUTO;
else {
int n;
for (n = 0; n < LP_NO && parport[n]; n++) {
if (!strncmp(parport[n], "none", 4))
parport_nr[n] = LP_PARPORT_NONE;
else {
char *ep;
unsigned long r = simple_strtoul(parport[n], &ep, 0);
if (ep != parport[n])
parport_nr[n] = r;
else {
printk(KERN_ERR "lp: bad port specifier `%s'\n", parport[n]);
return -ENODEV;
}
}
}
}
}
return lp_init();
}
static void lp_cleanup_module (void)
{
unsigned int offset;
parport_unregister_driver (&lp_driver);
#ifdef CONFIG_LP_CONSOLE
unregister_console (&lpcons);
#endif
unregister_chrdev(LP_MAJOR, "lp");
for (offset = 0; offset < LP_NO; offset++) {
if (lp_table[offset].dev == NULL)
continue;
parport_unregister_device(lp_table[offset].dev);
device_destroy(lp_class, MKDEV(LP_MAJOR, offset));
}
class_destroy(lp_class);
}
