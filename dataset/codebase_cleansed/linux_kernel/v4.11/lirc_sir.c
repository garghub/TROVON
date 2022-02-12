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
static int sir_tx_ir(struct rc_dev *dev, unsigned int *tx_buf,
unsigned int count)
{
unsigned long flags;
int i;
local_irq_save(flags);
for (i = 0; i < count;) {
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
return count;
}
static void add_read_queue(int flag, unsigned long val)
{
DEFINE_IR_RAW_EVENT(ev);
pr_debug("add flag %d with val %lu\n", flag, val);
if (flag) {
if (val > TIME_CONST / 2)
val -= TIME_CONST / 2;
else
val = 1;
ev.pulse = true;
} else {
val += TIME_CONST / 2;
}
ev.duration = US_TO_NS(val);
ir_raw_event_store_with_filter(rcdev, &ev);
}
static int init_chrdev(void)
{
rcdev = devm_rc_allocate_device(&sir_ir_dev->dev, RC_DRIVER_IR_RAW);
if (!rcdev)
return -ENOMEM;
rcdev->input_phys = KBUILD_MODNAME "/input0";
rcdev->input_id.bustype = BUS_HOST;
rcdev->input_id.vendor = 0x0001;
rcdev->input_id.product = 0x0001;
rcdev->input_id.version = 0x0100;
rcdev->tx_ir = sir_tx_ir;
rcdev->allowed_protocols = RC_BIT_ALL_IR_DECODER;
rcdev->map_name = RC_MAP_RC6_MCE;
rcdev->timeout = IR_DEFAULT_TIMEOUT;
rcdev->dev.parent = &sir_ir_dev->dev;
return devm_rc_register_device(&sir_ir_dev->dev, rcdev);
}
static void sir_timeout(unsigned long data)
{
unsigned long flags;
unsigned long pulse_end;
spin_lock_irqsave(&timer_lock, flags);
if (last_value) {
outb(UART_FCR_CLEAR_RCVR, io + UART_FCR);
pulse_end = min_t(unsigned long,
ktime_us_delta(last, last_intr_time),
IR_MAX_DURATION);
dev_dbg(&sir_ir_dev->dev, "timeout add %d for %lu usec\n",
last_value, pulse_end);
add_read_queue(last_value, pulse_end);
last_value = 0;
last = last_intr_time;
}
spin_unlock_irqrestore(&timer_lock, flags);
ir_raw_event_handle(rcdev);
}
static irqreturn_t sir_interrupt(int irq, void *dev_id)
{
unsigned char data;
ktime_t curr_time;
static unsigned long delt;
unsigned long deltintr;
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
curr_time = ktime_get();
delt = min_t(unsigned long,
ktime_us_delta(last, curr_time),
IR_MAX_DURATION);
deltintr = min_t(unsigned long,
ktime_us_delta(last_intr_time,
curr_time),
IR_MAX_DURATION);
dev_dbg(&sir_ir_dev->dev, "t %lu, d %d\n",
deltintr, (int)data);
if (deltintr > TIME_CONST * threshold) {
if (last_value) {
dev_dbg(&sir_ir_dev->dev, "GAP\n");
add_read_queue(last_value,
delt -
deltintr);
last_value = 0;
last = last_intr_time;
delt = deltintr;
}
}
data = 1;
if (data ^ last_value) {
add_read_queue(last_value,
delt-TIME_CONST);
last_value = data;
last = curr_time;
last = ktime_sub_us(last,
TIME_CONST);
}
last_intr_time = curr_time;
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
ir_raw_event_handle(rcdev);
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
if (!request_region(io, 8, KBUILD_MODNAME)) {
pr_err("i/o port 0x%.4x already in use.\n", io);
return -EBUSY;
}
retval = request_irq(irq, sir_interrupt, 0,
KBUILD_MODNAME, NULL);
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
static int init_sir_ir(void)
{
int retval;
retval = init_port();
if (retval < 0)
return retval;
init_hardware();
pr_info("Installed.\n");
return 0;
}
static int sir_ir_probe(struct platform_device *dev)
{
return 0;
}
static int sir_ir_remove(struct platform_device *dev)
{
return 0;
}
static int __init sir_ir_init(void)
{
int retval;
retval = platform_driver_register(&sir_ir_driver);
if (retval) {
pr_err("Platform driver register failed!\n");
return -ENODEV;
}
sir_ir_dev = platform_device_alloc("sir_ir", 0);
if (!sir_ir_dev) {
pr_err("Platform device alloc failed!\n");
retval = -ENOMEM;
goto pdev_alloc_fail;
}
retval = platform_device_add(sir_ir_dev);
if (retval) {
pr_err("Platform device add failed!\n");
retval = -ENODEV;
goto pdev_add_fail;
}
retval = init_chrdev();
if (retval < 0)
goto fail;
retval = init_sir_ir();
if (retval)
goto fail;
return 0;
fail:
platform_device_del(sir_ir_dev);
pdev_add_fail:
platform_device_put(sir_ir_dev);
pdev_alloc_fail:
platform_driver_unregister(&sir_ir_driver);
return retval;
}
static void __exit sir_ir_exit(void)
{
drop_hardware();
drop_port();
platform_device_unregister(sir_ir_dev);
platform_driver_unregister(&sir_ir_driver);
pr_info("Uninstalled.\n");
}
