static inline unsigned int sinp(int offset)
{
return inb(io + offset);
}
static inline void soutp(int offset, int value)
{
outb(value, io + offset);
}
static void safe_udelay(unsigned long usecs)
{
while (usecs > MAX_UDELAY_US) {
udelay(MAX_UDELAY_US);
usecs -= MAX_UDELAY_US;
}
udelay(usecs);
}
static unsigned int lirc_poll(struct file *file, poll_table *wait)
{
poll_wait(file, &lirc_read_queue, wait);
if (rx_head != rx_tail)
return POLLIN | POLLRDNORM;
return 0;
}
static ssize_t lirc_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
int n = 0;
int retval = 0;
DECLARE_WAITQUEUE(wait, current);
if (count % sizeof(int))
return -EINVAL;
add_wait_queue(&lirc_read_queue, &wait);
set_current_state(TASK_INTERRUPTIBLE);
while (n < count) {
if (rx_head != rx_tail) {
if (copy_to_user(buf + n,
rx_buf + rx_head,
sizeof(int))) {
retval = -EFAULT;
break;
}
rx_head = (rx_head + 1) & (RBUF_LEN - 1);
n += sizeof(int);
} else {
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
break;
}
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
schedule();
set_current_state(TASK_INTERRUPTIBLE);
}
}
remove_wait_queue(&lirc_read_queue, &wait);
set_current_state(TASK_RUNNING);
return n ? n : retval;
}
static ssize_t lirc_write(struct file *file, const char __user *buf, size_t n,
loff_t *pos)
{
unsigned long flags;
int i, count;
int *tx_buf;
count = n / sizeof(int);
if (n % sizeof(int) || count % 2 == 0)
return -EINVAL;
tx_buf = memdup_user(buf, n);
if (IS_ERR(tx_buf))
return PTR_ERR(tx_buf);
i = 0;
local_irq_save(flags);
while (1) {
if (i >= count)
break;
if (tx_buf[i])
send_pulse(tx_buf[i]);
i++;
if (i >= count)
break;
if (tx_buf[i])
send_space(tx_buf[i]);
i++;
}
local_irq_restore(flags);
kfree(tx_buf);
return count;
}
static long lirc_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
u32 __user *uptr = (u32 __user *)arg;
int retval = 0;
u32 value = 0;
if (cmd == LIRC_GET_FEATURES)
value = LIRC_CAN_SEND_PULSE | LIRC_CAN_REC_MODE2;
else if (cmd == LIRC_GET_SEND_MODE)
value = LIRC_MODE_PULSE;
else if (cmd == LIRC_GET_REC_MODE)
value = LIRC_MODE_MODE2;
switch (cmd) {
case LIRC_GET_FEATURES:
case LIRC_GET_SEND_MODE:
case LIRC_GET_REC_MODE:
retval = put_user(value, uptr);
break;
case LIRC_SET_SEND_MODE:
case LIRC_SET_REC_MODE:
retval = get_user(value, uptr);
break;
default:
retval = -ENOIOCTLCMD;
}
if (retval)
return retval;
if (cmd == LIRC_SET_REC_MODE) {
if (value != LIRC_MODE_MODE2)
retval = -ENOSYS;
} else if (cmd == LIRC_SET_SEND_MODE) {
if (value != LIRC_MODE_PULSE)
retval = -ENOSYS;
}
return retval;
}
static void add_read_queue(int flag, unsigned long val)
{
unsigned int new_rx_tail;
int newval;
pr_debug("add flag %d with val %lu\n", flag, val);
newval = val & PULSE_MASK;
if (flag) {
if (newval > TIME_CONST/2)
newval -= TIME_CONST/2;
else
newval = 1;
newval |= PULSE_BIT;
} else {
newval += TIME_CONST/2;
}
new_rx_tail = (rx_tail + 1) & (RBUF_LEN - 1);
if (new_rx_tail == rx_head) {
pr_debug("Buffer overrun.\n");
return;
}
rx_buf[rx_tail] = newval;
rx_tail = new_rx_tail;
wake_up_interruptible(&lirc_read_queue);
}
static int set_use_inc(void *data)
{
return 0;
}
static void set_use_dec(void *data)
{
}
static int init_chrdev(void)
{
driver.dev = &lirc_sir_dev->dev;
driver.minor = lirc_register_driver(&driver);
if (driver.minor < 0) {
pr_err("init_chrdev() failed.\n");
return -EIO;
}
return 0;
}
static void drop_chrdev(void)
{
lirc_unregister_driver(driver.minor);
}
static long delta(struct timeval *tv1, struct timeval *tv2)
{
unsigned long deltv;
deltv = tv2->tv_sec - tv1->tv_sec;
if (deltv > 15)
deltv = 0xFFFFFF;
else
deltv = deltv*1000000 +
tv2->tv_usec -
tv1->tv_usec;
return deltv;
}
static void sir_timeout(unsigned long data)
{
unsigned long flags;
unsigned long pulse_end;
spin_lock_irqsave(&timer_lock, flags);
if (last_value) {
outb(UART_FCR_CLEAR_RCVR, io + UART_FCR);
pulse_end = delta(&last_tv, &last_intr_tv);
dev_dbg(driver.dev, "timeout add %d for %lu usec\n",
last_value, pulse_end);
add_read_queue(last_value, pulse_end);
last_value = 0;
last_tv = last_intr_tv;
}
spin_unlock_irqrestore(&timer_lock, flags);
}
static irqreturn_t sir_interrupt(int irq, void *dev_id)
{
unsigned char data;
struct timeval curr_tv;
static unsigned long deltv;
unsigned long deltintrtv;
unsigned long flags;
int iir, lsr;
while ((iir = inb(io + UART_IIR) & UART_IIR_ID)) {
switch (iir&UART_IIR_ID) {
case UART_IIR_MSI:
(void) inb(io + UART_MSR);
break;
case UART_IIR_RLSI:
(void) inb(io + UART_LSR);
break;
case UART_IIR_THRI:
#if 0
if (lsr & UART_LSR_THRE)
outb(data, io + UART_TX)
#endif
break;
case UART_IIR_RDI:
spin_lock_irqsave(&timer_lock, flags);
do {
del_timer(&timerlist);
data = inb(io + UART_RX);
do_gettimeofday(&curr_tv);
deltv = delta(&last_tv, &curr_tv);
deltintrtv = delta(&last_intr_tv, &curr_tv);
dev_dbg(driver.dev, "t %lu, d %d\n",
deltintrtv, (int)data);
if (deltintrtv > TIME_CONST * threshold) {
if (last_value) {
dev_dbg(driver.dev, "GAP\n");
add_read_queue(last_value,
deltv -
deltintrtv);
last_value = 0;
last_tv.tv_sec =
last_intr_tv.tv_sec;
last_tv.tv_usec =
last_intr_tv.tv_usec;
deltv = deltintrtv;
}
}
data = 1;
if (data ^ last_value) {
add_read_queue(last_value,
deltv-TIME_CONST);
last_value = data;
last_tv = curr_tv;
if (last_tv.tv_usec >= TIME_CONST) {
last_tv.tv_usec -= TIME_CONST;
} else {
last_tv.tv_sec--;
last_tv.tv_usec += 1000000 -
TIME_CONST;
}
}
last_intr_tv = curr_tv;
if (data) {
timerlist.expires = jiffies +
SIR_TIMEOUT;
add_timer(&timerlist);
}
lsr = inb(io + UART_LSR);
} while (lsr & UART_LSR_DR);
spin_unlock_irqrestore(&timer_lock, flags);
break;
default:
break;
}
}
return IRQ_RETVAL(IRQ_HANDLED);
}
static void send_space(unsigned long len)
{
safe_udelay(len);
}
static void send_pulse(unsigned long len)
{
long bytes_out = len / TIME_CONST;
if (bytes_out == 0)
bytes_out++;
while (bytes_out--) {
outb(PULSE, io + UART_TX);
while (!(inb(io + UART_LSR) & UART_LSR_THRE))
;
}
}
static int init_hardware(void)
{
unsigned long flags;
spin_lock_irqsave(&hardware_lock, flags);
#if defined(LIRC_SIR_TEKRAM)
soutp(UART_FCR,
UART_FCR_CLEAR_RCVR|
UART_FCR_CLEAR_XMIT|
UART_FCR_TRIGGER_1);
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_IER, sinp(UART_IER) &
(~(UART_IER_MSI|UART_IER_RLSI|UART_IER_THRI|UART_IER_RDI)));
soutp(UART_LCR, sinp(UART_LCR) | UART_LCR_DLAB);
soutp(UART_DLM, 0);
soutp(UART_DLL, 12);
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_DTR|UART_MCR_OUT2);
safe_udelay(50*1000);
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_OUT2);
udelay(1*1000);
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_DTR|UART_MCR_OUT2);
udelay(100);
soutp(UART_MCR, UART_MCR_DTR|UART_MCR_OUT2);
udelay(7);
soutp(UART_TX, TEKRAM_115200|TEKRAM_PW);
udelay(1500);
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_DTR|UART_MCR_OUT2);
udelay(50);
udelay(1500);
pr_info("0x%02x\n", sinp(UART_RX));
soutp(UART_LCR, sinp(UART_LCR) | UART_LCR_DLAB);
soutp(UART_DLM, 0);
soutp(UART_DLL, 1);
soutp(UART_LCR, UART_LCR_WLEN8);
soutp(UART_IER, sinp(UART_IER)|UART_IER_RDI);
#else
outb(0, io + UART_MCR);
outb(0, io + UART_IER);
outb(UART_LCR_DLAB | UART_LCR_WLEN7, io + UART_LCR);
outb(1, io + UART_DLL); outb(0, io + UART_DLM);
outb(UART_LCR_WLEN7, io + UART_LCR);
outb(UART_FCR_ENABLE_FIFO, io + UART_FCR);
outb(UART_IER_RDI, io + UART_IER);
outb(UART_MCR_DTR|UART_MCR_RTS|UART_MCR_OUT2, io + UART_MCR);
#ifdef LIRC_SIR_ACTISYS_ACT200L
init_act200();
#elif defined(LIRC_SIR_ACTISYS_ACT220L)
init_act220();
#endif
#endif
spin_unlock_irqrestore(&hardware_lock, flags);
return 0;
}
static void drop_hardware(void)
{
unsigned long flags;
spin_lock_irqsave(&hardware_lock, flags);
outb(0, io + UART_IER);
spin_unlock_irqrestore(&hardware_lock, flags);
}
static int init_port(void)
{
int retval;
if (request_region(io, 8, LIRC_DRIVER_NAME) == NULL) {
pr_err("i/o port 0x%.4x already in use.\n", io);
return -EBUSY;
}
retval = request_irq(irq, sir_interrupt, 0,
LIRC_DRIVER_NAME, NULL);
if (retval < 0) {
release_region(io, 8);
pr_err("IRQ %d already in use.\n", irq);
return retval;
}
pr_info("I/O port 0x%.4x, IRQ %d.\n", io, irq);
setup_timer(&timerlist, sir_timeout, 0);
return 0;
}
static void drop_port(void)
{
free_irq(irq, NULL);
del_timer_sync(&timerlist);
release_region(io, 8);
}
static void init_act200(void)
{
int i;
__u8 control[] = {
ACT200L_REG15,
ACT200L_REG13 | ACT200L_SHDW,
ACT200L_REG21 | ACT200L_EXCK | ACT200L_OSCL,
ACT200L_REG13,
ACT200L_REG7 | ACT200L_ENPOS,
ACT200L_REG6 | ACT200L_RS0 | ACT200L_RS1,
ACT200L_REG5 | ACT200L_RWIDL,
ACT200L_REG4 | ACT200L_OP0 | ACT200L_OP1 | ACT200L_BLKR,
ACT200L_REG3 | ACT200L_B0,
ACT200L_REG0 | ACT200L_TXEN | ACT200L_RXEN,
ACT200L_REG8 | (ACT200L_115200 & 0x0f),
ACT200L_REG9 | ((ACT200L_115200 >> 4) & 0x0f),
ACT200L_REG1 | ACT200L_LODB | ACT200L_WIDE
};
soutp(UART_LCR, UART_LCR_DLAB | UART_LCR_WLEN8);
soutp(UART_DLM, 0);
soutp(UART_DLL, 12);
soutp(UART_LCR, UART_LCR_WLEN8);
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_DTR|UART_MCR_OUT2);
for (i = 0; i < 50; i++)
safe_udelay(1000);
soutp(UART_MCR, UART_MCR_DTR|UART_MCR_OUT2);
for (i = 0; i < 25; i++)
udelay(1000);
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_DTR|UART_MCR_OUT2);
udelay(100);
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_OUT2);
udelay(7);
for (i = 0; i < sizeof(control); i++) {
soutp(UART_TX, control[i]);
udelay(1500);
}
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_DTR|UART_MCR_OUT2);
udelay(50);
udelay(1500);
soutp(UART_LCR, sinp(UART_LCR) | UART_LCR_DLAB);
soutp(UART_LCR, UART_LCR_DLAB | UART_LCR_WLEN7);
soutp(UART_DLM, 0);
soutp(UART_DLL, 1);
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_LCR, UART_LCR_WLEN7);
soutp(UART_IER, sinp(UART_IER)|UART_IER_RDI);
}
void init_act220(void)
{
int i;
soutp(UART_LCR, UART_LCR_DLAB|UART_LCR_WLEN7);
soutp(UART_DLM, 0);
soutp(UART_DLL, 12);
soutp(UART_LCR, UART_LCR_WLEN7);
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_OUT2);
udelay(10);
soutp(UART_MCR, UART_MCR_DTR|UART_MCR_RTS|UART_MCR_OUT2);
for (i = 0; i < 3; i++) {
udelay(10);
soutp(UART_MCR, UART_MCR_DTR|UART_MCR_OUT2);
udelay(10);
soutp(UART_MCR, UART_MCR_RTS|UART_MCR_DTR|UART_MCR_OUT2);
}
udelay(1500);
soutp(UART_LCR, UART_LCR_DLAB | UART_LCR_WLEN7);
soutp(UART_DLM, 0);
soutp(UART_DLL, 1);
soutp(UART_LCR, UART_LCR_WLEN7);
soutp(UART_IER, UART_IER_RDI);
}
static int init_lirc_sir(void)
{
int retval;
init_waitqueue_head(&lirc_read_queue);
retval = init_port();
if (retval < 0)
return retval;
init_hardware();
pr_info("Installed.\n");
return 0;
}
static int lirc_sir_probe(struct platform_device *dev)
{
return 0;
}
static int lirc_sir_remove(struct platform_device *dev)
{
return 0;
}
static int __init lirc_sir_init(void)
{
int retval;
retval = platform_driver_register(&lirc_sir_driver);
if (retval) {
pr_err("Platform driver register failed!\n");
return -ENODEV;
}
lirc_sir_dev = platform_device_alloc("lirc_dev", 0);
if (!lirc_sir_dev) {
pr_err("Platform device alloc failed!\n");
retval = -ENOMEM;
goto pdev_alloc_fail;
}
retval = platform_device_add(lirc_sir_dev);
if (retval) {
pr_err("Platform device add failed!\n");
retval = -ENODEV;
goto pdev_add_fail;
}
retval = init_chrdev();
if (retval < 0)
goto fail;
retval = init_lirc_sir();
if (retval) {
drop_chrdev();
goto fail;
}
return 0;
fail:
platform_device_del(lirc_sir_dev);
pdev_add_fail:
platform_device_put(lirc_sir_dev);
pdev_alloc_fail:
platform_driver_unregister(&lirc_sir_driver);
return retval;
}
static void __exit lirc_sir_exit(void)
{
drop_hardware();
drop_chrdev();
drop_port();
platform_device_unregister(lirc_sir_dev);
platform_driver_unregister(&lirc_sir_driver);
pr_info("Uninstalled.\n");
}
