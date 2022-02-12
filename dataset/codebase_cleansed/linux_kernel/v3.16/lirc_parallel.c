static unsigned int in(int offset)
{
switch (offset) {
case LIRC_LP_BASE:
return parport_read_data(pport);
case LIRC_LP_STATUS:
return parport_read_status(pport);
case LIRC_LP_CONTROL:
return parport_read_control(pport);
}
return 0;
}
static void out(int offset, int value)
{
switch (offset) {
case LIRC_LP_BASE:
parport_write_data(pport, value);
break;
case LIRC_LP_CONTROL:
parport_write_control(pport, value);
break;
case LIRC_LP_STATUS:
pr_info("attempt to write to status register\n");
break;
}
}
static unsigned int lirc_get_timer(void)
{
return in(LIRC_PORT_TIMER) & LIRC_PORT_TIMER_BIT;
}
static unsigned int lirc_get_signal(void)
{
return in(LIRC_PORT_SIGNAL) & LIRC_PORT_SIGNAL_BIT;
}
static void lirc_on(void)
{
out(LIRC_PORT_DATA, tx_mask);
}
static void lirc_off(void)
{
out(LIRC_PORT_DATA, 0);
}
static unsigned int init_lirc_timer(void)
{
struct timeval tv, now;
unsigned int level, newlevel, timeelapsed, newtimer;
int count = 0;
do_gettimeofday(&tv);
tv.tv_sec++;
level = lirc_get_timer();
do {
newlevel = lirc_get_timer();
if (level == 0 && newlevel != 0)
count++;
level = newlevel;
do_gettimeofday(&now);
} while (count < 1000 && (now.tv_sec < tv.tv_sec
|| (now.tv_sec == tv.tv_sec
&& now.tv_usec < tv.tv_usec)));
timeelapsed = ((now.tv_sec + 1 - tv.tv_sec)*1000000
+ (now.tv_usec - tv.tv_usec));
if (count >= 1000 && timeelapsed > 0) {
if (default_timer == 0) {
newtimer = (1000000*count)/timeelapsed;
pr_info("%u Hz timer detected\n", newtimer);
return newtimer;
} else {
newtimer = (1000000*count)/timeelapsed;
if (abs(newtimer - default_timer) > default_timer/10) {
pr_notice("bad timer: %u Hz\n", newtimer);
pr_notice("using default timer: %u Hz\n",
default_timer);
return default_timer;
} else {
pr_info("%u Hz timer detected\n", newtimer);
return newtimer;
}
}
} else {
pr_notice("no timer detected\n");
return 0;
}
}
static int lirc_claim(void)
{
if (parport_claim(ppdevice) != 0) {
pr_warn("could not claim port\n");
pr_warn("waiting for port becoming available\n");
if (parport_claim_or_block(ppdevice) < 0) {
pr_notice("could not claim port, giving up\n");
return 0;
}
}
out(LIRC_LP_CONTROL, LP_PSELECP|LP_PINITP);
is_claimed = 1;
return 1;
}
static void rbuf_write(int signal)
{
unsigned int nwptr;
nwptr = (wptr + 1) & (RBUF_SIZE - 1);
if (nwptr == rptr) {
lost_irqs++;
pr_notice("buffer overrun\n");
return;
}
rbuf[wptr] = signal;
wptr = nwptr;
}
static void lirc_lirc_irq_handler(void *blah)
{
struct timeval tv;
static struct timeval lasttv;
static int init;
long signal;
int data;
unsigned int level, newlevel;
unsigned int timeout;
if (!is_open)
return;
if (!is_claimed)
return;
#if 0
disable_irq(irq);
out(LIRC_PORT_IRQ, in(LIRC_PORT_IRQ) & (~LP_PINTEN));
#endif
if (check_pselecd && (in(1) & LP_PSELECD))
return;
#ifdef LIRC_TIMER
if (init) {
do_gettimeofday(&tv);
signal = tv.tv_sec - lasttv.tv_sec;
if (signal > 15)
data = PULSE_MASK;
else
data = (int) (signal*1000000 +
tv.tv_usec - lasttv.tv_usec +
LIRC_SFH506_DELAY);
rbuf_write(data);
} else {
if (timer == 0) {
timer = init_lirc_timer();
return;
}
init = 1;
}
timeout = timer/10;
signal = 1;
level = lirc_get_timer();
do {
newlevel = lirc_get_timer();
if (level == 0 && newlevel != 0)
signal++;
level = newlevel;
if (signal > timeout
|| (check_pselecd && (in(1) & LP_PSELECD))) {
signal = 0;
pr_notice("timeout\n");
break;
}
} while (lirc_get_signal());
if (signal != 0) {
__u64 helper;
helper = ((__u64) signal)*1000000;
do_div(helper, timer);
signal = (long) helper;
if (signal > LIRC_SFH506_DELAY)
data = signal - LIRC_SFH506_DELAY;
else
data = 1;
rbuf_write(PULSE_BIT|data);
}
do_gettimeofday(&lasttv);
#else
#endif
wake_up_interruptible(&lirc_wait);
}
static loff_t lirc_lseek(struct file *filep, loff_t offset, int orig)
{
return -ESPIPE;
}
static ssize_t lirc_read(struct file *filep, char __user *buf, size_t n,
loff_t *ppos)
{
int result = 0;
int count = 0;
DECLARE_WAITQUEUE(wait, current);
if (n % sizeof(int))
return -EINVAL;
add_wait_queue(&lirc_wait, &wait);
set_current_state(TASK_INTERRUPTIBLE);
while (count < n) {
if (rptr != wptr) {
if (copy_to_user(buf+count, (char *) &rbuf[rptr],
sizeof(int))) {
result = -EFAULT;
break;
}
rptr = (rptr + 1) & (RBUF_SIZE - 1);
count += sizeof(int);
} else {
if (filep->f_flags & O_NONBLOCK) {
result = -EAGAIN;
break;
}
if (signal_pending(current)) {
result = -ERESTARTSYS;
break;
}
schedule();
set_current_state(TASK_INTERRUPTIBLE);
}
}
remove_wait_queue(&lirc_wait, &wait);
set_current_state(TASK_RUNNING);
return count ? count : result;
}
static ssize_t lirc_write(struct file *filep, const char __user *buf, size_t n,
loff_t *ppos)
{
int count;
unsigned int i;
unsigned int level, newlevel;
unsigned long flags;
int counttimer;
int *wbuf;
ssize_t ret;
if (!is_claimed)
return -EBUSY;
count = n / sizeof(int);
if (n % sizeof(int) || count % 2 == 0)
return -EINVAL;
wbuf = memdup_user(buf, n);
if (IS_ERR(wbuf))
return PTR_ERR(wbuf);
#ifdef LIRC_TIMER
if (timer == 0) {
timer = init_lirc_timer();
if (timer == 0) {
ret = -EIO;
goto out;
}
}
for (i = 0; i < count; i++) {
__u64 helper;
helper = ((__u64) wbuf[i])*timer;
do_div(helper, 1000000);
wbuf[i] = (int) helper;
}
local_irq_save(flags);
i = 0;
while (i < count) {
level = lirc_get_timer();
counttimer = 0;
lirc_on();
do {
newlevel = lirc_get_timer();
if (level == 0 && newlevel != 0)
counttimer++;
level = newlevel;
if (check_pselecd && (in(1) & LP_PSELECD)) {
lirc_off();
local_irq_restore(flags);
ret = -EIO;
goto out;
}
} while (counttimer < wbuf[i]);
i++;
lirc_off();
if (i == count)
break;
counttimer = 0;
do {
newlevel = lirc_get_timer();
if (level == 0 && newlevel != 0)
counttimer++;
level = newlevel;
if (check_pselecd && (in(1) & LP_PSELECD)) {
local_irq_restore(flags);
ret = -EIO;
goto out;
}
} while (counttimer < wbuf[i]);
i++;
}
local_irq_restore(flags);
#else
#endif
ret = n;
out:
kfree(wbuf);
return ret;
}
static unsigned int lirc_poll(struct file *file, poll_table *wait)
{
poll_wait(file, &lirc_wait, wait);
if (rptr != wptr)
return POLLIN | POLLRDNORM;
return 0;
}
static long lirc_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
int result;
u32 __user *uptr = (u32 __user *)arg;
u32 features = LIRC_CAN_SET_TRANSMITTER_MASK |
LIRC_CAN_SEND_PULSE | LIRC_CAN_REC_MODE2;
u32 mode;
u32 value;
switch (cmd) {
case LIRC_GET_FEATURES:
result = put_user(features, uptr);
if (result)
return result;
break;
case LIRC_GET_SEND_MODE:
result = put_user(LIRC_MODE_PULSE, uptr);
if (result)
return result;
break;
case LIRC_GET_REC_MODE:
result = put_user(LIRC_MODE_MODE2, uptr);
if (result)
return result;
break;
case LIRC_SET_SEND_MODE:
result = get_user(mode, uptr);
if (result)
return result;
if (mode != LIRC_MODE_PULSE)
return -EINVAL;
break;
case LIRC_SET_REC_MODE:
result = get_user(mode, uptr);
if (result)
return result;
if (mode != LIRC_MODE_MODE2)
return -ENOSYS;
break;
case LIRC_SET_TRANSMITTER_MASK:
result = get_user(value, uptr);
if (result)
return result;
if ((value & LIRC_PARALLEL_TRANSMITTER_MASK) != value)
return LIRC_PARALLEL_MAX_TRANSMITTERS;
tx_mask = value;
break;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static int lirc_open(struct inode *node, struct file *filep)
{
if (is_open || !lirc_claim())
return -EBUSY;
parport_enable_irq(pport);
rptr = 0;
wptr = 0;
lost_irqs = 0;
is_open = 1;
return 0;
}
static int lirc_close(struct inode *node, struct file *filep)
{
if (is_claimed) {
is_claimed = 0;
parport_release(ppdevice);
}
is_open = 0;
return 0;
}
static int set_use_inc(void *data)
{
return 0;
}
static void set_use_dec(void *data)
{
}
static int lirc_parallel_probe(struct platform_device *dev)
{
return 0;
}
static int lirc_parallel_remove(struct platform_device *dev)
{
return 0;
}
static int lirc_parallel_suspend(struct platform_device *dev,
pm_message_t state)
{
return 0;
}
static int lirc_parallel_resume(struct platform_device *dev)
{
return 0;
}
static int pf(void *handle)
{
parport_disable_irq(pport);
is_claimed = 0;
return 0;
}
static void kf(void *handle)
{
if (!is_open)
return;
if (!lirc_claim())
return;
parport_enable_irq(pport);
lirc_off();
}
static int __init lirc_parallel_init(void)
{
int result;
result = platform_driver_register(&lirc_parallel_driver);
if (result) {
pr_notice("platform_driver_register returned %d\n", result);
return result;
}
lirc_parallel_dev = platform_device_alloc(LIRC_DRIVER_NAME, 0);
if (!lirc_parallel_dev) {
result = -ENOMEM;
goto exit_driver_unregister;
}
result = platform_device_add(lirc_parallel_dev);
if (result)
goto exit_device_put;
pport = parport_find_base(io);
if (pport == NULL) {
pr_notice("no port at %x found\n", io);
result = -ENXIO;
goto exit_device_put;
}
ppdevice = parport_register_device(pport, LIRC_DRIVER_NAME,
pf, kf, lirc_lirc_irq_handler, 0, NULL);
parport_put_port(pport);
if (ppdevice == NULL) {
pr_notice("parport_register_device() failed\n");
result = -ENXIO;
goto exit_device_put;
}
if (parport_claim(ppdevice) != 0)
goto skip_init;
is_claimed = 1;
out(LIRC_LP_CONTROL, LP_PSELECP|LP_PINITP);
#ifdef LIRC_TIMER
if (debug)
out(LIRC_PORT_DATA, tx_mask);
timer = init_lirc_timer();
#if 0
if (timer == 0) {
is_claimed = 0;
parport_release(pport);
parport_unregister_device(ppdevice);
result = -EIO;
goto exit_device_put;
}
#endif
if (debug)
out(LIRC_PORT_DATA, 0);
#endif
is_claimed = 0;
parport_release(ppdevice);
skip_init:
driver.dev = &lirc_parallel_dev->dev;
driver.minor = lirc_register_driver(&driver);
if (driver.minor < 0) {
pr_notice("register_chrdev() failed\n");
parport_unregister_device(ppdevice);
result = -EIO;
goto exit_device_put;
}
pr_info("installed using port 0x%04x irq %d\n", io, irq);
return 0;
exit_device_put:
platform_device_put(lirc_parallel_dev);
exit_driver_unregister:
platform_driver_unregister(&lirc_parallel_driver);
return result;
}
static void __exit lirc_parallel_exit(void)
{
parport_unregister_device(ppdevice);
lirc_unregister_driver(driver.minor);
platform_device_unregister(lirc_parallel_dev);
platform_driver_unregister(&lirc_parallel_driver);
}
