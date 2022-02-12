static void on(void)
{
PPSR |= PPC_TXD2;
}
static void off(void)
{
PPSR &= ~PPC_TXD2;
}
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
static ssize_t lirc_read(struct file *file, char *buf, size_t count,
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
if (copy_to_user((void *) buf + n,
(void *) (rx_buf + rx_head),
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
static ssize_t lirc_write(struct file *file, const char *buf, size_t n,
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
#ifdef LIRC_ON_SA1100
Ser2UTCR3 = 0;
#endif
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
#ifdef LIRC_ON_SA1100
off();
udelay(1000);
Ser2UTCR3 = 0;
Ser2UTSR0 &= (UTSR0_RID | UTSR0_RBB | UTSR0_REB);
Ser2UTCR3 = UTCR3_RXE|UTCR3_RIE;
#endif
kfree(tx_buf);
return count;
}
static long lirc_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
int retval = 0;
__u32 value = 0;
#ifdef LIRC_ON_SA1100
if (cmd == LIRC_GET_FEATURES)
value = LIRC_CAN_SEND_PULSE |
LIRC_CAN_SET_SEND_DUTY_CYCLE |
LIRC_CAN_SET_SEND_CARRIER |
LIRC_CAN_REC_MODE2;
else if (cmd == LIRC_GET_SEND_MODE)
value = LIRC_MODE_PULSE;
else if (cmd == LIRC_GET_REC_MODE)
value = LIRC_MODE_MODE2;
#else
if (cmd == LIRC_GET_FEATURES)
value = LIRC_CAN_SEND_PULSE | LIRC_CAN_REC_MODE2;
else if (cmd == LIRC_GET_SEND_MODE)
value = LIRC_MODE_PULSE;
else if (cmd == LIRC_GET_REC_MODE)
value = LIRC_MODE_MODE2;
#endif
switch (cmd) {
case LIRC_GET_FEATURES:
case LIRC_GET_SEND_MODE:
case LIRC_GET_REC_MODE:
retval = put_user(value, (__u32 *) arg);
break;
case LIRC_SET_SEND_MODE:
case LIRC_SET_REC_MODE:
retval = get_user(value, (__u32 *) arg);
break;
#ifdef LIRC_ON_SA1100
case LIRC_SET_SEND_DUTY_CYCLE:
retval = get_user(value, (__u32 *) arg);
if (retval)
return retval;
if (value <= 0 || value > 100)
return -EINVAL;
duty_cycle = value;
pulse_width = (unsigned long) duty_cycle*10000/freq;
space_width = (unsigned long) 1000000L/freq-pulse_width;
if (pulse_width >= LIRC_ON_SA1100_TRANSMITTER_LATENCY)
pulse_width -= LIRC_ON_SA1100_TRANSMITTER_LATENCY;
if (space_width >= LIRC_ON_SA1100_TRANSMITTER_LATENCY)
space_width -= LIRC_ON_SA1100_TRANSMITTER_LATENCY;
break;
case LIRC_SET_SEND_CARRIER:
retval = get_user(value, (__u32 *) arg);
if (retval)
return retval;
if (value > 500000 || value < 20000)
return -EINVAL;
freq = value;
pulse_width = (unsigned long) duty_cycle*10000/freq;
space_width = (unsigned long) 1000000L/freq-pulse_width;
if (pulse_width >= LIRC_ON_SA1100_TRANSMITTER_LATENCY)
pulse_width -= LIRC_ON_SA1100_TRANSMITTER_LATENCY;
if (space_width >= LIRC_ON_SA1100_TRANSMITTER_LATENCY)
space_width -= LIRC_ON_SA1100_TRANSMITTER_LATENCY;
break;
#endif
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
dprintk("add flag %d with val %lu\n", flag, val);
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
dprintk("Buffer overrun.\n");
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
driver.minor = lirc_register_driver(&driver);
if (driver.minor < 0) {
printk(KERN_ERR LIRC_DRIVER_NAME ": init_chrdev() failed.\n");
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
#ifndef LIRC_ON_SA1100
outb(UART_FCR_CLEAR_RCVR, io + UART_FCR);
#endif
pulse_end = delta(&last_tv, &last_intr_tv);
dprintk("timeout add %d for %lu usec\n", last_value, pulse_end);
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
#ifdef LIRC_ON_SA1100
int status;
static int n;
status = Ser2UTSR0;
while (status & UTSR0_EIF) {
int bstat;
if (debug) {
dprintk("EIF\n");
bstat = Ser2UTSR1;
if (bstat & UTSR1_FRE)
dprintk("frame error\n");
if (bstat & UTSR1_ROR)
dprintk("receive fifo overrun\n");
if (bstat & UTSR1_PRE)
dprintk("parity error\n");
}
bstat = Ser2UTDR;
n++;
status = Ser2UTSR0;
}
if (status & (UTSR0_RFS | UTSR0_RID)) {
do_gettimeofday(&curr_tv);
deltv = delta(&last_tv, &curr_tv);
do {
data = Ser2UTDR;
dprintk("%d data: %u\n", n, (unsigned int) data);
n++;
} while (status & UTSR0_RID &&
Ser2UTSR1 & UTSR1_RNE);
if (status&UTSR0_RID) {
add_read_queue(0 , deltv - n * TIME_CONST);
add_read_queue(1, n * TIME_CONST);
n = 0;
last_tv = curr_tv;
}
}
if (status & UTSR0_TFS)
printk(KERN_ERR "transmit fifo not full, shouldn't happen\n");
status &= (UTSR0_RID | UTSR0_RBB | UTSR0_REB);
if (status)
Ser2UTSR0 = status;
#else
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
dprintk("t %lu, d %d\n", deltintrtv, (int)data);
if (deltintrtv > TIME_CONST * threshold) {
if (last_value) {
dprintk("GAP\n");
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
#endif
return IRQ_RETVAL(IRQ_HANDLED);
}
static void send_pulse(unsigned long length)
{
unsigned long k, delay;
int flag;
if (length == 0)
return;
for (k = flag = 0; k < length; k += delay, flag = !flag) {
if (flag) {
off();
delay = space_width;
} else {
on();
delay = pulse_width;
}
safe_udelay(delay);
}
off();
}
static void send_space(unsigned long length)
{
if (length == 0)
return;
off();
safe_udelay(length);
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
static int sa1100_irda_set_power_collie(int state)
{
if (state) {
ucb1200_set_io_direction(TC35143_GPIO_IR_ON,
TC35143_IODIR_OUTPUT);
ucb1200_set_io(TC35143_GPIO_IR_ON, TC35143_IODAT_LOW);
udelay(100);
} else {
ucb1200_set_io_direction(TC35143_GPIO_IR_ON,
TC35143_IODIR_OUTPUT);
ucb1200_set_io(TC35143_GPIO_IR_ON, TC35143_IODAT_HIGH);
}
return 0;
}
static int init_hardware(void)
{
unsigned long flags;
spin_lock_irqsave(&hardware_lock, flags);
#ifdef LIRC_ON_SA1100
#ifdef CONFIG_SA1100_BITSY
if (machine_is_bitsy()) {
printk(KERN_INFO "Power on IR module\n");
set_bitsy_egpio(EGPIO_BITSY_IR_ON);
}
#endif
#ifdef CONFIG_SA1100_COLLIE
sa1100_irda_set_power_collie(3);
#endif
sr.hscr0 = Ser2HSCR0;
sr.utcr0 = Ser2UTCR0;
sr.utcr1 = Ser2UTCR1;
sr.utcr2 = Ser2UTCR2;
sr.utcr3 = Ser2UTCR3;
sr.utcr4 = Ser2UTCR4;
sr.utdr = Ser2UTDR;
sr.utsr0 = Ser2UTSR0;
sr.utsr1 = Ser2UTSR1;
PPDR |= PPC_TXD2;
PSDR |= PPC_TXD2;
off();
Ser2UTCR3 = 0;
Ser2HSCR0 = sr.hscr0 & (~HSCR0_HSSP);
Ser2UTSR0 &= (UTSR0_RID | UTSR0_RBB | UTSR0_REB);
Ser2UTCR0 = UTCR0_1StpBit|UTCR0_7BitData;
Ser2UTCR1 = 0;
Ser2UTCR2 = 1;
Ser2UTCR4 = UTCR4_HPSIR|UTCR4_Z1_6us;
Ser2UTCR3 = UTCR3_RXE|UTCR3_RIE;
Ser2UTSR0 &= (UTSR0_RID | UTSR0_RBB | UTSR0_REB);
#elif defined(LIRC_SIR_TEKRAM)
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
printk(KERN_INFO LIRC_DRIVER_NAME
": 0x%02x\n", sinp(UART_RX));
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
#ifdef LIRC_ON_SA1100
Ser2UTCR3 = 0;
Ser2UTCR0 = sr.utcr0;
Ser2UTCR1 = sr.utcr1;
Ser2UTCR2 = sr.utcr2;
Ser2UTCR4 = sr.utcr4;
Ser2UTCR3 = sr.utcr3;
Ser2HSCR0 = sr.hscr0;
#ifdef CONFIG_SA1100_BITSY
if (machine_is_bitsy())
clr_bitsy_egpio(EGPIO_BITSY_IR_ON);
#endif
#ifdef CONFIG_SA1100_COLLIE
sa1100_irda_set_power_collie(0);
#endif
#else
outb(0, io + UART_IER);
#endif
spin_unlock_irqrestore(&hardware_lock, flags);
}
static int init_port(void)
{
int retval;
#ifndef LIRC_ON_SA1100
if (request_region(io, 8, LIRC_DRIVER_NAME) == NULL) {
printk(KERN_ERR LIRC_DRIVER_NAME
": i/o port 0x%.4x already in use.\n", io);
return -EBUSY;
}
#endif
retval = request_irq(irq, sir_interrupt, IRQF_DISABLED,
LIRC_DRIVER_NAME, NULL);
if (retval < 0) {
# ifndef LIRC_ON_SA1100
release_region(io, 8);
# endif
printk(KERN_ERR LIRC_DRIVER_NAME
": IRQ %d already in use.\n",
irq);
return retval;
}
#ifndef LIRC_ON_SA1100
printk(KERN_INFO LIRC_DRIVER_NAME
": I/O port 0x%.4x, IRQ %d.\n",
io, irq);
#endif
init_timer(&timerlist);
timerlist.function = sir_timeout;
timerlist.data = 0xabadcafe;
return 0;
}
static void drop_port(void)
{
free_irq(irq, NULL);
del_timer_sync(&timerlist);
#ifndef LIRC_ON_SA1100
release_region(io, 8);
#endif
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
printk(KERN_INFO LIRC_DRIVER_NAME
": Installed.\n");
return 0;
}
static int __init lirc_sir_init(void)
{
int retval;
retval = init_chrdev();
if (retval < 0)
return retval;
retval = init_lirc_sir();
if (retval) {
drop_chrdev();
return retval;
}
return 0;
}
static void __exit lirc_sir_exit(void)
{
drop_hardware();
drop_chrdev();
drop_port();
printk(KERN_INFO LIRC_DRIVER_NAME ": Uninstalled.\n");
}
