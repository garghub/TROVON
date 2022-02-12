static u8 sinp(int offset)
{
if (iommap)
offset <<= ioshift;
return inb(io + offset);
}
static void soutp(int offset, u8 value)
{
if (iommap)
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
static void init_timing_params(unsigned int new_duty_cycle,
unsigned int new_freq)
{
serial_ir.duty_cycle = new_duty_cycle;
serial_ir.freq = new_freq;
serial_ir.pulse_width = DIV_ROUND_CLOSEST(
new_duty_cycle * NSEC_PER_SEC, new_freq * 100l);
serial_ir.space_width = DIV_ROUND_CLOSEST(
(100l - new_duty_cycle) * NSEC_PER_SEC, new_freq * 100l);
}
static void send_pulse_irdeo(unsigned int length, ktime_t target)
{
long rawbits;
int i;
unsigned char output;
unsigned char chunk, shifted;
rawbits = length * 1152 / 10000;
if (serial_ir.duty_cycle > 50)
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
}
static void send_space_irdeo(void)
{
}
static void send_pulse_homebrew_softcarrier(unsigned int length, ktime_t edge)
{
ktime_t now, target = ktime_add_us(edge, length);
s32 delta;
for (;;) {
now = ktime_get();
if (ktime_compare(now, target) >= 0)
break;
on();
edge = ktime_add_ns(edge, serial_ir.pulse_width);
delta = ktime_to_ns(ktime_sub(edge, now));
if (delta > 0)
ndelay(delta);
now = ktime_get();
off();
if (ktime_compare(now, target) >= 0)
break;
edge = ktime_add_ns(edge, serial_ir.space_width);
delta = ktime_to_ns(ktime_sub(edge, now));
if (delta > 0)
ndelay(delta);
}
}
static void send_pulse_homebrew(unsigned int length, ktime_t edge)
{
if (softcarrier)
send_pulse_homebrew_softcarrier(length, edge);
else
on();
}
static void send_space_homebrew(void)
{
off();
}
static void frbwrite(unsigned int l, bool is_pulse)
{
static unsigned int ptr, pulse, space;
DEFINE_IR_RAW_EVENT(ev);
if (ptr > 0 && is_pulse) {
pulse += l;
if (pulse > 250000) {
ev.duration = space;
ev.pulse = false;
ir_raw_event_store_with_filter(serial_ir.rcdev, &ev);
ev.duration = pulse;
ev.pulse = true;
ir_raw_event_store_with_filter(serial_ir.rcdev, &ev);
ptr = 0;
pulse = 0;
}
return;
}
if (!is_pulse) {
if (ptr == 0) {
if (l > 20000000) {
space = l;
ptr++;
return;
}
} else {
if (l > 20000000) {
space += pulse;
if (space > IR_MAX_DURATION)
space = IR_MAX_DURATION;
space += l;
if (space > IR_MAX_DURATION)
space = IR_MAX_DURATION;
pulse = 0;
return;
}
ev.duration = space;
ev.pulse = false;
ir_raw_event_store_with_filter(serial_ir.rcdev, &ev);
ev.duration = pulse;
ev.pulse = true;
ir_raw_event_store_with_filter(serial_ir.rcdev, &ev);
ptr = 0;
pulse = 0;
}
}
ev.duration = l;
ev.pulse = is_pulse;
ir_raw_event_store_with_filter(serial_ir.rcdev, &ev);
}
static irqreturn_t serial_ir_irq_handler(int i, void *blah)
{
ktime_t kt;
int counter, dcd;
u8 status;
ktime_t delkt;
unsigned int data;
static int last_dcd = -1;
if ((sinp(UART_IIR) & UART_IIR_NO_INT)) {
return IRQ_NONE;
}
counter = 0;
do {
counter++;
status = sinp(UART_MSR);
if (counter > RS_ISR_PASS_LIMIT) {
dev_err(&serial_ir.pdev->dev, "Trapped in interrupt");
break;
}
if ((status & hardware[type].signal_pin_change) &&
sense != -1) {
kt = ktime_get();
dcd = (status & hardware[type].signal_pin) ? 1 : 0;
if (dcd == last_dcd) {
dev_err(&serial_ir.pdev->dev,
"ignoring spike: %d %d %lldns %lldns\n",
dcd, sense, ktime_to_ns(kt),
ktime_to_ns(serial_ir.lastkt));
continue;
}
delkt = ktime_sub(kt, serial_ir.lastkt);
if (ktime_compare(delkt, ktime_set(15, 0)) > 0) {
data = IR_MAX_DURATION;
if (!(dcd ^ sense)) {
dev_err(&serial_ir.pdev->dev,
"dcd unexpected: %d %d %lldns %lldns\n",
dcd, sense, ktime_to_ns(kt),
ktime_to_ns(serial_ir.lastkt));
sense = sense ? 0 : 1;
}
} else {
data = ktime_to_ns(delkt);
}
frbwrite(data, !(dcd ^ sense));
serial_ir.lastkt = kt;
last_dcd = dcd;
}
} while (!(sinp(UART_IIR) & UART_IIR_NO_INT));
mod_timer(&serial_ir.timeout_timer,
jiffies + nsecs_to_jiffies(serial_ir.rcdev->timeout));
ir_raw_event_handle(serial_ir.rcdev);
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
(~(UART_IER_MSI | UART_IER_RLSI | UART_IER_THRI | UART_IER_RDI)));
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
case IR_IRDEO:
case IR_IRDEO_REMOTE:
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
static void serial_ir_timeout(unsigned long arg)
{
DEFINE_IR_RAW_EVENT(ev);
ev.timeout = true;
ev.duration = serial_ir.rcdev->timeout;
ir_raw_event_store_with_filter(serial_ir.rcdev, &ev);
ir_raw_event_handle(serial_ir.rcdev);
}
static int serial_ir_probe(struct platform_device *dev)
{
struct rc_dev *rcdev;
int i, nlow, nhigh, result;
rcdev = devm_rc_allocate_device(&dev->dev, RC_DRIVER_IR_RAW);
if (!rcdev)
return -ENOMEM;
if (hardware[type].send_pulse && hardware[type].send_space)
rcdev->tx_ir = serial_ir_tx;
if (hardware[type].set_send_carrier)
rcdev->s_tx_carrier = serial_ir_tx_carrier;
if (hardware[type].set_duty_cycle)
rcdev->s_tx_duty_cycle = serial_ir_tx_duty_cycle;
switch (type) {
case IR_HOMEBREW:
rcdev->input_name = "Serial IR type home-brew";
break;
case IR_IRDEO:
rcdev->input_name = "Serial IR type IRdeo";
break;
case IR_IRDEO_REMOTE:
rcdev->input_name = "Serial IR type IRdeo remote";
break;
case IR_ANIMAX:
rcdev->input_name = "Serial IR type AnimaX";
break;
case IR_IGOR:
rcdev->input_name = "Serial IR type IgorPlug";
break;
}
rcdev->input_phys = KBUILD_MODNAME "/input0";
rcdev->input_id.bustype = BUS_HOST;
rcdev->input_id.vendor = 0x0001;
rcdev->input_id.product = 0x0001;
rcdev->input_id.version = 0x0100;
rcdev->open = serial_ir_open;
rcdev->close = serial_ir_close;
rcdev->dev.parent = &serial_ir.pdev->dev;
rcdev->allowed_protocols = RC_BIT_ALL_IR_DECODER;
rcdev->driver_name = KBUILD_MODNAME;
rcdev->map_name = RC_MAP_RC6_MCE;
rcdev->min_timeout = 1;
rcdev->timeout = IR_DEFAULT_TIMEOUT;
rcdev->max_timeout = 10 * IR_DEFAULT_TIMEOUT;
rcdev->rx_resolution = 250000;
serial_ir.rcdev = rcdev;
setup_timer(&serial_ir.timeout_timer, serial_ir_timeout,
(unsigned long)&serial_ir);
result = devm_request_irq(&dev->dev, irq, serial_ir_irq_handler,
share_irq ? IRQF_SHARED : 0,
KBUILD_MODNAME, &hardware);
if (result < 0) {
if (result == -EBUSY)
dev_err(&dev->dev, "IRQ %d busy\n", irq);
else if (result == -EINVAL)
dev_err(&dev->dev, "Bad irq number or handler\n");
return result;
}
if ((iommap &&
(devm_request_mem_region(&dev->dev, iommap, 8 << ioshift,
KBUILD_MODNAME) == NULL)) ||
(!iommap && (devm_request_region(&dev->dev, io, 8,
KBUILD_MODNAME) == NULL))) {
dev_err(&dev->dev, "port %04x already in use\n", io);
dev_warn(&dev->dev, "use 'setserial /dev/ttySX uart none'\n");
dev_warn(&dev->dev,
"or compile the serial port driver as module and\n");
dev_warn(&dev->dev, "make sure this module is loaded first\n");
return -EBUSY;
}
result = hardware_init_port();
if (result < 0)
return result;
init_timing_params(50, 38000);
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
sense = nlow >= nhigh ? 1 : 0;
dev_info(&dev->dev, "auto-detected active %s receiver\n",
sense ? "low" : "high");
} else
dev_info(&dev->dev, "Manually using active %s receiver\n",
sense ? "low" : "high");
dev_dbg(&dev->dev, "Interrupt %d, port %04x obtained\n", irq, io);
return devm_rc_register_device(&dev->dev, rcdev);
}
static int serial_ir_open(struct rc_dev *rcdev)
{
unsigned long flags;
serial_ir.lastkt = ktime_get();
spin_lock_irqsave(&hardware[type].lock, flags);
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_IER, sinp(UART_IER) | UART_IER_MSI);
spin_unlock_irqrestore(&hardware[type].lock, flags);
return 0;
}
static void serial_ir_close(struct rc_dev *rcdev)
{
unsigned long flags;
spin_lock_irqsave(&hardware[type].lock, flags);
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_IER, sinp(UART_IER) &
(~(UART_IER_MSI | UART_IER_RLSI | UART_IER_THRI | UART_IER_RDI)));
spin_unlock_irqrestore(&hardware[type].lock, flags);
}
static int serial_ir_tx(struct rc_dev *dev, unsigned int *txbuf,
unsigned int count)
{
unsigned long flags;
ktime_t edge;
s64 delta;
int i;
spin_lock_irqsave(&hardware[type].lock, flags);
if (type == IR_IRDEO) {
on();
}
edge = ktime_get();
for (i = 0; i < count; i++) {
if (i % 2)
hardware[type].send_space();
else
hardware[type].send_pulse(txbuf[i], edge);
edge = ktime_add_us(edge, txbuf[i]);
delta = ktime_us_delta(edge, ktime_get());
if (delta > 25) {
spin_unlock_irqrestore(&hardware[type].lock, flags);
usleep_range(delta - 25, delta + 25);
spin_lock_irqsave(&hardware[type].lock, flags);
} else if (delta > 0) {
udelay(delta);
}
}
off();
spin_unlock_irqrestore(&hardware[type].lock, flags);
return count;
}
static int serial_ir_tx_duty_cycle(struct rc_dev *dev, u32 cycle)
{
init_timing_params(cycle, serial_ir.freq);
return 0;
}
static int serial_ir_tx_carrier(struct rc_dev *dev, u32 carrier)
{
if (carrier > 500000 || carrier < 20000)
return -EINVAL;
init_timing_params(serial_ir.duty_cycle, carrier);
return 0;
}
static int serial_ir_suspend(struct platform_device *dev,
pm_message_t state)
{
soutp(UART_LCR, sinp(UART_LCR) & (~UART_LCR_DLAB));
soutp(UART_IER, sinp(UART_IER) &
(~(UART_IER_MSI | UART_IER_RLSI | UART_IER_THRI | UART_IER_RDI)));
sinp(UART_LSR);
sinp(UART_RX);
sinp(UART_IIR);
sinp(UART_MSR);
return 0;
}
static int serial_ir_resume(struct platform_device *dev)
{
unsigned long flags;
int result;
result = hardware_init_port();
if (result < 0)
return result;
spin_lock_irqsave(&hardware[type].lock, flags);
serial_ir.lastkt = ktime_get();
soutp(UART_IER, sinp(UART_IER) | UART_IER_MSI);
off();
spin_unlock_irqrestore(&hardware[type].lock, flags);
return 0;
}
static int __init serial_ir_init(void)
{
int result;
result = platform_driver_register(&serial_ir_driver);
if (result)
return result;
serial_ir.pdev = platform_device_alloc("serial_ir", 0);
if (!serial_ir.pdev) {
result = -ENOMEM;
goto exit_driver_unregister;
}
result = platform_device_add(serial_ir.pdev);
if (result)
goto exit_device_put;
return 0;
exit_device_put:
platform_device_put(serial_ir.pdev);
exit_driver_unregister:
platform_driver_unregister(&serial_ir_driver);
return result;
}
static void serial_ir_exit(void)
{
platform_device_unregister(serial_ir.pdev);
platform_driver_unregister(&serial_ir_driver);
}
static int __init serial_ir_init_module(void)
{
int result;
switch (type) {
case IR_HOMEBREW:
case IR_IRDEO:
case IR_IRDEO_REMOTE:
case IR_ANIMAX:
case IR_IGOR:
io = io ? io : 0x3f8;
irq = irq ? irq : 4;
break;
default:
return -EINVAL;
}
if (!softcarrier) {
switch (type) {
case IR_HOMEBREW:
case IR_IGOR:
hardware[type].set_send_carrier = false;
hardware[type].set_duty_cycle = false;
break;
}
}
if (sense != -1)
sense = !!sense;
result = serial_ir_init();
if (!result)
return 0;
serial_ir_exit();
return result;
}
static void __exit serial_ir_exit_module(void)
{
del_timer_sync(&serial_ir.timeout_timer);
serial_ir_exit();
}
