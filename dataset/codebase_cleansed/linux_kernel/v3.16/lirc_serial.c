static u8 sinp(int offset)
{
if (iommap != 0)
offset <<= ioshift;
return inb(io + offset);
}
static void soutp(int offset, u8 value)
{
if (iommap != 0)
offset <<= ioshift;
outb(value, io + offset);
}
static void on(void)
{
if (txsense)
soutp(UART_MCR, hardware[type].off);
else
soutp(UART_MCR, hardware[type].on);
}
static void off(void)
{
if (txsense)
soutp(UART_MCR, hardware[type].on);
else
soutp(UART_MCR, hardware[type].off);
}
static void safe_udelay(unsigned long usecs)
{
while (usecs > MAX_UDELAY_US) {
udelay(MAX_UDELAY_US);
usecs -= MAX_UDELAY_US;
}
udelay(usecs);
}
static int init_timing_params(unsigned int new_duty_cycle,
unsigned int new_freq)
{
__u64 loops_per_sec, work;
duty_cycle = new_duty_cycle;
freq = new_freq;
loops_per_sec = __this_cpu_read(cpu.info.loops_per_jiffy);
loops_per_sec *= HZ;
work = loops_per_sec;
work *= 4295;
conv_us_to_clocks = (work >> 32);
period = loops_per_sec >> 3;
period /= (freq >> 3);
pulse_width = period * duty_cycle / 100;
space_width = period - pulse_width;
dprintk("in init_timing_params, freq=%d, duty_cycle=%d, "
"clk/jiffy=%ld, pulse=%ld, space=%ld, "
"conv_us_to_clocks=%ld\n",
freq, duty_cycle, __this_cpu_read(cpu_info.loops_per_jiffy),
pulse_width, space_width, conv_us_to_clocks);
return 0;
}
static int init_timing_params(unsigned int new_duty_cycle,
unsigned int new_freq)
{
if (256 * 1000000L / new_freq * new_duty_cycle / 100 <=
LIRC_SERIAL_TRANSMITTER_LATENCY)
return -EINVAL;
if (256 * 1000000L / new_freq * (100 - new_duty_cycle) / 100 <=
LIRC_SERIAL_TRANSMITTER_LATENCY)
return -EINVAL;
duty_cycle = new_duty_cycle;
freq = new_freq;
period = 256 * 1000000L / freq;
pulse_width = period * duty_cycle / 100;
space_width = period - pulse_width;
dprintk("in init_timing_params, freq=%d pulse=%ld, space=%ld\n",
freq, pulse_width, space_width);
return 0;
}
static long send_pulse_irdeo(unsigned long length)
{
long rawbits, ret;
int i;
unsigned char output;
unsigned char chunk, shifted;
rawbits = length * 1152 / 10000;
if (duty_cycle > 50)
chunk = 3;
else
chunk = 1;
for (i = 0, output = 0x7f; rawbits > 0; rawbits -= 3) {
shifted = chunk << (i * 3);
shifted >>= 1;
output &= (~shifted);
i++;
if (i == 3) {
soutp(UART_TX, output);
while (!(sinp(UART_LSR) & UART_LSR_THRE))
;
output = 0x7f;
i = 0;
}
}
if (i != 0) {
soutp(UART_TX, output);
while (!(sinp(UART_LSR) & UART_LSR_TEMT))
;
}
if (i == 0)
ret = (-rawbits) * 10000 / 1152;
else
ret = (3 - i) * 3 * 10000 / 1152 + (-rawbits) * 10000 / 1152;
return ret;
}
static long send_pulse_homebrew_softcarrier(unsigned long length)
{
int flag;
unsigned long target, start, now;
rdtscl(start);
on();
length *= conv_us_to_clocks;
now = start;
target = pulse_width;
flag = 1;
while ((now - start) < length) {
do {
rdtscl(now);
} while ((now - start) < target);
if (flag) {
rdtscl(now);
off();
target += space_width;
} else {
rdtscl(now); on();
target += pulse_width;
}
flag = !flag;
}
rdtscl(now);
return ((now - start) - length) / conv_us_to_clocks;
}
static long send_pulse_homebrew_softcarrier(unsigned long length)
{
int flag;
unsigned long actual, target, d;
length <<= 8;
actual = 0; target = 0; flag = 0;
while (actual < length) {
if (flag) {
off();
target += space_width;
} else {
on();
target += pulse_width;
}
d = (target - actual -
LIRC_SERIAL_TRANSMITTER_LATENCY + 128) >> 8;
udelay(d);
actual += (d << 8) + LIRC_SERIAL_TRANSMITTER_LATENCY;
flag = !flag;
}
return (actual-length) >> 8;
}
static long send_pulse_homebrew(unsigned long length)
{
if (length <= 0)
return 0;
if (softcarrier)
return send_pulse_homebrew_softcarrier(length);
else {
on();
safe_udelay(length);
return 0;
}
}
static void send_space_irdeo(long length)
{
if (length <= 0)
return;
safe_udelay(length);
}
static void send_space_homebrew(long length)
{
off();
if (length <= 0)
return;
safe_udelay(length);
}
static void rbwrite(int l)
{
if (lirc_buffer_full(&rbuf)) {
dprintk("Buffer overrun\n");
return;
}
lirc_buffer_write(&rbuf, (void *)&l);
}
static void frbwrite(int l)
{
static int pulse, space;
static unsigned int ptr;
if (ptr > 0 && (l & PULSE_BIT)) {
pulse += l & PULSE_MASK;
if (pulse > 250) {
rbwrite(space);
rbwrite(pulse | PULSE_BIT);
ptr = 0;
pulse = 0;
}
return;
}
if (!(l & PULSE_BIT)) {
if (ptr == 0) {
if (l > 20000) {
space = l;
ptr++;
return;
}
} else {
if (l > 20000) {
space += pulse;
if (space > PULSE_MASK)
space = PULSE_MASK;
space += l;
if (space > PULSE_MASK)
space = PULSE_MASK;
pulse = 0;
return;
}
rbwrite(space);
rbwrite(pulse | PULSE_BIT);
ptr = 0;
pulse = 0;
}
}
rbwrite(l);
}
static irqreturn_t lirc_irq_handler(int i, void *blah)
{
struct timeval tv;
int counter, dcd;
u8 status;
long deltv;
int data;
static int last_dcd = -1;
if ((sinp(UART_IIR) & UART_IIR_NO_INT)) {
return IRQ_NONE;
}
counter = 0;
do {
counter++;
status = sinp(UART_MSR);
if (counter > RS_ISR_PASS_LIMIT) {
pr_warn("AIEEEE: We're caught!\n");
break;
}
if ((status & hardware[type].signal_pin_change)
&& sense != -1) {
do_gettimeofday(&tv);
dcd = (status & hardware[type].signal_pin) ? 1 : 0;
if (dcd == last_dcd) {
pr_warn("ignoring spike: %d %d %lx %lx %lx %lx\n",
dcd, sense,
tv.tv_sec, lasttv.tv_sec,
(unsigned long)tv.tv_usec,
(unsigned long)lasttv.tv_usec);
continue;
}
deltv = tv.tv_sec-lasttv.tv_sec;
if (tv.tv_sec < lasttv.tv_sec ||
(tv.tv_sec == lasttv.tv_sec &&
tv.tv_usec < lasttv.tv_usec)) {
pr_warn("AIEEEE: your clock just jumped backwards\n");
pr_warn("%d %d %lx %lx %lx %lx\n",
dcd, sense,
tv.tv_sec, lasttv.tv_sec,
(unsigned long)tv.tv_usec,
(unsigned long)lasttv.tv_usec);
data = PULSE_MASK;
} else if (deltv > 15) {
data = PULSE_MASK;
if (!(dcd^sense)) {
pr_warn("AIEEEE: %d %d %lx %lx %lx %lx\n",
dcd, sense,
tv.tv_sec, lasttv.tv_sec,
(unsigned long)tv.tv_usec,
(unsigned long)lasttv.tv_usec);
sense = sense ? 0 : 1;
}
} else
data = (int) (deltv*1000000 +
tv.tv_usec -
lasttv.tv_usec);
frbwrite(dcd^sense ? data : (data|PULSE_BIT));
lasttv = tv;
last_dcd = dcd;
wake_up_interruptible(&rbuf.wait_poll);
}
} while (!(sinp(UART_IIR) & UART_IIR_NO_INT));
return IRQ_HANDLED;
}
static int hardware_init_port(void)
{
u8 scratch, scratch2, scratch3;
scratch = sinp(UART_IER);
soutp(UART_IER, 0);
#ifdef __i386__
outb(0xff, 0x080);
#endif
scratch2 = sinp(UART_IER) & 0x0f;
soutp(UART_IER, 0x0f);
#ifdef __i386__
outb(0x00, 0x080);
#endif
scratch3 = sinp(UART_IER) & 0x0f;
soutp(UART_IER, scratch);
if (scratch2 != 0 || scratch3 != 0x0f) {
pr_err("port existence test failed, cannot continue\n");
return -ENODEV;
}
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_IER, sinp(UART_IER) &
(~(UART_IER_MSI|UART_IER_RLSI|UART_IER_THRI|UART_IER_RDI)));
sinp(UART_LSR);
sinp(UART_RX);
sinp(UART_IIR);
sinp(UART_MSR);
off();
sinp(UART_LSR);
sinp(UART_RX);
sinp(UART_IIR);
sinp(UART_MSR);
switch (type) {
case LIRC_IRDEO:
case LIRC_IRDEO_REMOTE:
soutp(UART_LCR, sinp(UART_LCR) | UART_LCR_DLAB);
soutp(UART_DLM, 0);
soutp(UART_DLL, 1);
soutp(UART_LCR, UART_LCR_WLEN7);
break;
default:
break;
}
return 0;
}
static int lirc_serial_probe(struct platform_device *dev)
{
int i, nlow, nhigh, result;
result = request_irq(irq, lirc_irq_handler,
(share_irq ? IRQF_SHARED : 0),
LIRC_DRIVER_NAME, (void *)&hardware);
if (result < 0) {
if (result == -EBUSY)
dev_err(&dev->dev, "IRQ %d busy\n", irq);
else if (result == -EINVAL)
dev_err(&dev->dev, "Bad irq number or handler\n");
return result;
}
if (((iommap != 0)
&& (request_mem_region(iommap, 8 << ioshift,
LIRC_DRIVER_NAME) == NULL))
|| ((iommap == 0)
&& (request_region(io, 8, LIRC_DRIVER_NAME) == NULL))) {
dev_err(&dev->dev, "port %04x already in use\n", io);
dev_warn(&dev->dev, "use 'setserial /dev/ttySX uart none'\n");
dev_warn(&dev->dev,
"or compile the serial port driver as module and\n");
dev_warn(&dev->dev, "make sure this module is loaded first\n");
result = -EBUSY;
goto exit_free_irq;
}
result = hardware_init_port();
if (result < 0)
goto exit_release_region;
init_timing_params(duty_cycle, freq);
if (sense == -1) {
msleep(500);
nlow = 0;
nhigh = 0;
for (i = 0; i < 9; i++) {
if (sinp(UART_MSR) & hardware[type].signal_pin)
nlow++;
else
nhigh++;
msleep(40);
}
sense = (nlow >= nhigh ? 1 : 0);
dev_info(&dev->dev, "auto-detected active %s receiver\n",
sense ? "low" : "high");
} else
dev_info(&dev->dev, "Manually using active %s receiver\n",
sense ? "low" : "high");
dprintk("Interrupt %d, port %04x obtained\n", irq, io);
return 0;
exit_release_region:
if (iommap != 0)
release_mem_region(iommap, 8 << ioshift);
else
release_region(io, 8);
exit_free_irq:
free_irq(irq, (void *)&hardware);
return result;
}
static int lirc_serial_remove(struct platform_device *dev)
{
free_irq(irq, (void *)&hardware);
if (iommap != 0)
release_mem_region(iommap, 8 << ioshift);
else
release_region(io, 8);
return 0;
}
static int set_use_inc(void *data)
{
unsigned long flags;
do_gettimeofday(&lasttv);
spin_lock_irqsave(&hardware[type].lock, flags);
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_IER, sinp(UART_IER)|UART_IER_MSI);
spin_unlock_irqrestore(&hardware[type].lock, flags);
return 0;
}
static void set_use_dec(void *data)
{ unsigned long flags;
spin_lock_irqsave(&hardware[type].lock, flags);
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_IER, sinp(UART_IER) &
(~(UART_IER_MSI|UART_IER_RLSI|UART_IER_THRI|UART_IER_RDI)));
spin_unlock_irqrestore(&hardware[type].lock, flags);
}
static ssize_t lirc_write(struct file *file, const char __user *buf,
size_t n, loff_t *ppos)
{
int i, count;
unsigned long flags;
long delta = 0;
int *wbuf;
if (!(hardware[type].features & LIRC_CAN_SEND_PULSE))
return -EPERM;
count = n / sizeof(int);
if (n % sizeof(int) || count % 2 == 0)
return -EINVAL;
wbuf = memdup_user(buf, n);
if (IS_ERR(wbuf))
return PTR_ERR(wbuf);
spin_lock_irqsave(&hardware[type].lock, flags);
if (type == LIRC_IRDEO) {
on();
}
for (i = 0; i < count; i++) {
if (i%2)
hardware[type].send_space(wbuf[i] - delta);
else
delta = hardware[type].send_pulse(wbuf[i]);
}
off();
spin_unlock_irqrestore(&hardware[type].lock, flags);
kfree(wbuf);
return n;
}
static long lirc_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
int result;
u32 __user *uptr = (u32 __user *)arg;
u32 value;
switch (cmd) {
case LIRC_GET_SEND_MODE:
if (!(hardware[type].features&LIRC_CAN_SEND_MASK))
return -ENOIOCTLCMD;
result = put_user(LIRC_SEND2MODE
(hardware[type].features&LIRC_CAN_SEND_MASK),
uptr);
if (result)
return result;
break;
case LIRC_SET_SEND_MODE:
if (!(hardware[type].features&LIRC_CAN_SEND_MASK))
return -ENOIOCTLCMD;
result = get_user(value, uptr);
if (result)
return result;
if (value != LIRC_MODE_PULSE)
return -EINVAL;
break;
case LIRC_GET_LENGTH:
return -ENOIOCTLCMD;
break;
case LIRC_SET_SEND_DUTY_CYCLE:
dprintk("SET_SEND_DUTY_CYCLE\n");
if (!(hardware[type].features&LIRC_CAN_SET_SEND_DUTY_CYCLE))
return -ENOIOCTLCMD;
result = get_user(value, uptr);
if (result)
return result;
if (value <= 0 || value > 100)
return -EINVAL;
return init_timing_params(value, freq);
break;
case LIRC_SET_SEND_CARRIER:
dprintk("SET_SEND_CARRIER\n");
if (!(hardware[type].features&LIRC_CAN_SET_SEND_CARRIER))
return -ENOIOCTLCMD;
result = get_user(value, uptr);
if (result)
return result;
if (value > 500000 || value < 20000)
return -EINVAL;
return init_timing_params(duty_cycle, value);
break;
default:
return lirc_dev_fop_ioctl(filep, cmd, arg);
}
return 0;
}
static int lirc_serial_suspend(struct platform_device *dev,
pm_message_t state)
{
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_IER, sinp(UART_IER) &
(~(UART_IER_MSI|UART_IER_RLSI|UART_IER_THRI|UART_IER_RDI)));
sinp(UART_LSR);
sinp(UART_RX);
sinp(UART_IIR);
sinp(UART_MSR);
return 0;
}
static int lirc_serial_resume(struct platform_device *dev)
{
unsigned long flags;
int result;
result = hardware_init_port();
if (result < 0)
return result;
spin_lock_irqsave(&hardware[type].lock, flags);
do_gettimeofday(&lasttv);
soutp(UART_IER, sinp(UART_IER)|UART_IER_MSI);
off();
lirc_buffer_clear(&rbuf);
spin_unlock_irqrestore(&hardware[type].lock, flags);
return 0;
}
static int __init lirc_serial_init(void)
{
int result;
result = lirc_buffer_init(&rbuf, sizeof(int), RBUF_LEN);
if (result < 0)
return result;
result = platform_driver_register(&lirc_serial_driver);
if (result) {
printk("lirc register returned %d\n", result);
goto exit_buffer_free;
}
lirc_serial_dev = platform_device_alloc("lirc_serial", 0);
if (!lirc_serial_dev) {
result = -ENOMEM;
goto exit_driver_unregister;
}
result = platform_device_add(lirc_serial_dev);
if (result)
goto exit_device_put;
return 0;
exit_device_put:
platform_device_put(lirc_serial_dev);
exit_driver_unregister:
platform_driver_unregister(&lirc_serial_driver);
exit_buffer_free:
lirc_buffer_free(&rbuf);
return result;
}
static void lirc_serial_exit(void)
{
platform_device_unregister(lirc_serial_dev);
platform_driver_unregister(&lirc_serial_driver);
lirc_buffer_free(&rbuf);
}
static int __init lirc_serial_init_module(void)
{
int result;
switch (type) {
case LIRC_HOMEBREW:
case LIRC_IRDEO:
case LIRC_IRDEO_REMOTE:
case LIRC_ANIMAX:
case LIRC_IGOR:
io = io ? io : 0x3f8;
irq = irq ? irq : 4;
break;
default:
return -EINVAL;
}
if (!softcarrier) {
switch (type) {
case LIRC_HOMEBREW:
case LIRC_IGOR:
hardware[type].features &=
~(LIRC_CAN_SET_SEND_DUTY_CYCLE|
LIRC_CAN_SET_SEND_CARRIER);
break;
}
}
if (sense != -1)
sense = !!sense;
result = lirc_serial_init();
if (result)
return result;
driver.features = hardware[type].features;
driver.dev = &lirc_serial_dev->dev;
driver.minor = lirc_register_driver(&driver);
if (driver.minor < 0) {
pr_err("register_chrdev failed!\n");
lirc_serial_exit();
return driver.minor;
}
return 0;
}
static void __exit lirc_serial_exit_module(void)
{
lirc_unregister_driver(driver.minor);
lirc_serial_exit();
dprintk("cleaned up module\n");
}
