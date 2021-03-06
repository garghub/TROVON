static inline bool ite_is_high_carrier_freq(unsigned int freq)
{
return freq >= ITE_HCF_MIN_CARRIER_FREQ;
}
static u8 ite_get_carrier_freq_bits(unsigned int freq)
{
if (ite_is_high_carrier_freq(freq)) {
if (freq < 425000)
return ITE_CFQ_400;
else if (freq < 465000)
return ITE_CFQ_450;
else if (freq < 490000)
return ITE_CFQ_480;
else
return ITE_CFQ_500;
} else {
if (freq < ITE_LCF_MIN_CARRIER_FREQ)
freq = ITE_LCF_MIN_CARRIER_FREQ;
if (freq > ITE_LCF_MAX_CARRIER_FREQ)
freq = ITE_LCF_MAX_CARRIER_FREQ;
freq =
DIV_ROUND_CLOSEST(freq - ITE_LCF_MIN_CARRIER_FREQ,
1000);
return (u8) freq;
}
}
static u8 ite_get_pulse_width_bits(unsigned int freq, int duty_cycle)
{
unsigned long period_ns, on_ns;
if (freq < ITE_LCF_MIN_CARRIER_FREQ)
freq = ITE_LCF_MIN_CARRIER_FREQ;
if (freq > ITE_HCF_MAX_CARRIER_FREQ)
freq = ITE_HCF_MAX_CARRIER_FREQ;
period_ns = 1000000000UL / freq;
on_ns = period_ns * duty_cycle / 100;
if (ite_is_high_carrier_freq(freq)) {
if (on_ns < 750)
return ITE_TXMPW_A;
else if (on_ns < 850)
return ITE_TXMPW_B;
else if (on_ns < 950)
return ITE_TXMPW_C;
else if (on_ns < 1080)
return ITE_TXMPW_D;
else
return ITE_TXMPW_E;
} else {
if (on_ns < 6500)
return ITE_TXMPW_A;
else if (on_ns < 7850)
return ITE_TXMPW_B;
else if (on_ns < 9650)
return ITE_TXMPW_C;
else if (on_ns < 11950)
return ITE_TXMPW_D;
else
return ITE_TXMPW_E;
}
}
static void ite_decode_bytes(struct ite_dev *dev, const u8 * data, int
length)
{
u32 sample_period;
unsigned long *ldata;
unsigned int next_one, next_zero, size;
DEFINE_IR_RAW_EVENT(ev);
if (length == 0)
return;
sample_period = dev->params.sample_period;
ldata = (unsigned long *)data;
size = length << 3;
next_one = find_next_bit_le(ldata, size, 0);
if (next_one > 0) {
ev.pulse = true;
ev.duration =
ITE_BITS_TO_NS(next_one, sample_period);
ir_raw_event_store_with_filter(dev->rdev, &ev);
}
while (next_one < size) {
next_zero = find_next_zero_bit_le(ldata, size, next_one + 1);
ev.pulse = false;
ev.duration = ITE_BITS_TO_NS(next_zero - next_one, sample_period);
ir_raw_event_store_with_filter(dev->rdev, &ev);
if (next_zero < size) {
next_one =
find_next_bit_le(ldata,
size,
next_zero + 1);
ev.pulse = true;
ev.duration =
ITE_BITS_TO_NS(next_one - next_zero,
sample_period);
ir_raw_event_store_with_filter
(dev->rdev, &ev);
} else
next_one = size;
}
ir_raw_event_handle(dev->rdev);
ite_dbg_verbose("decoded %d bytes.", length);
}
static void ite_set_carrier_params(struct ite_dev *dev)
{
unsigned int freq, low_freq, high_freq;
int allowance;
bool use_demodulator;
bool for_tx = dev->transmitting;
ite_dbg("%s called", __func__);
if (for_tx) {
freq = dev->params.tx_carrier_freq;
allowance = ITE_RXDCR_DEFAULT;
use_demodulator = false;
} else {
low_freq = dev->params.rx_low_carrier_freq;
high_freq = dev->params.rx_high_carrier_freq;
if (low_freq == 0) {
freq =
ITE_DEFAULT_CARRIER_FREQ;
allowance = ITE_RXDCR_DEFAULT;
use_demodulator = false;
} else {
freq = (low_freq + high_freq) / 2;
allowance =
DIV_ROUND_CLOSEST(10000 * (high_freq - low_freq),
ITE_RXDCR_PER_10000_STEP
* (high_freq + low_freq));
if (allowance < 1)
allowance = 1;
if (allowance > ITE_RXDCR_MAX)
allowance = ITE_RXDCR_MAX;
}
}
dev->params.set_carrier_params(dev, ite_is_high_carrier_freq(freq),
use_demodulator, ite_get_carrier_freq_bits(freq), allowance,
ite_get_pulse_width_bits(freq, dev->params.tx_duty_cycle));
}
static irqreturn_t ite_cir_isr(int irq, void *data)
{
struct ite_dev *dev = data;
unsigned long flags;
irqreturn_t ret = IRQ_RETVAL(IRQ_NONE);
u8 rx_buf[ITE_RX_FIFO_LEN];
int rx_bytes;
int iflags;
ite_dbg_verbose("%s firing", __func__);
spin_lock_irqsave(&dev->lock, flags);
iflags = dev->params.get_irq_causes(dev);
if (iflags & (ITE_IRQ_RX_FIFO | ITE_IRQ_RX_FIFO_OVERRUN)) {
rx_bytes =
dev->params.get_rx_bytes(dev, rx_buf,
ITE_RX_FIFO_LEN);
if (rx_bytes > 0) {
spin_unlock_irqrestore(&dev->
lock,
flags);
ite_decode_bytes(dev, rx_buf,
rx_bytes);
spin_lock_irqsave(&dev->lock,
flags);
ret = IRQ_RETVAL(IRQ_HANDLED);
}
} else if (iflags & ITE_IRQ_TX_FIFO) {
ite_dbg_verbose("got interrupt for TX FIFO");
wake_up_interruptible(&dev->tx_queue);
ret = IRQ_RETVAL(IRQ_HANDLED);
}
spin_unlock_irqrestore(&dev->lock, flags);
ite_dbg_verbose("%s done returning %d", __func__, (int)ret);
return ret;
}
static int ite_set_rx_carrier_range(struct rc_dev *rcdev, u32 carrier_low, u32
carrier_high)
{
unsigned long flags;
struct ite_dev *dev = rcdev->priv;
spin_lock_irqsave(&dev->lock, flags);
dev->params.rx_low_carrier_freq = carrier_low;
dev->params.rx_high_carrier_freq = carrier_high;
ite_set_carrier_params(dev);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static int ite_set_tx_carrier(struct rc_dev *rcdev, u32 carrier)
{
unsigned long flags;
struct ite_dev *dev = rcdev->priv;
spin_lock_irqsave(&dev->lock, flags);
dev->params.tx_carrier_freq = carrier;
ite_set_carrier_params(dev);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static int ite_set_tx_duty_cycle(struct rc_dev *rcdev, u32 duty_cycle)
{
unsigned long flags;
struct ite_dev *dev = rcdev->priv;
spin_lock_irqsave(&dev->lock, flags);
dev->params.tx_duty_cycle = duty_cycle;
ite_set_carrier_params(dev);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static int ite_tx_ir(struct rc_dev *rcdev, unsigned *txbuf, unsigned n)
{
unsigned long flags;
struct ite_dev *dev = rcdev->priv;
bool is_pulse = false;
int remaining_us, fifo_avail, fifo_remaining, last_idx = 0;
int max_rle_us, next_rle_us;
int ret = n;
u8 last_sent[ITE_TX_FIFO_LEN];
u8 val;
ite_dbg("%s called", __func__);
memset(last_sent, 0, ARRAY_SIZE(last_sent));
spin_lock_irqsave(&dev->lock, flags);
dev->transmitting = true;
ite_set_carrier_params(dev);
max_rle_us =
(ITE_BAUDRATE_DIVISOR * dev->params.sample_period *
ITE_TX_MAX_RLE) / 1000;
dev->params.disable_rx(dev);
fifo_avail =
ITE_TX_FIFO_LEN - dev->params.get_tx_used_slots(dev);
while (n > 0 && dev->in_use) {
is_pulse = !is_pulse;
remaining_us = *(txbuf++);
n--;
ite_dbg("%s: %ld",
((is_pulse) ? "pulse" : "space"),
(long int)
remaining_us);
while (remaining_us > 0 && dev->in_use) {
if (remaining_us > max_rle_us)
next_rle_us = max_rle_us;
else
next_rle_us = remaining_us;
remaining_us -= next_rle_us;
val = (ITE_TX_MAX_RLE * next_rle_us) / max_rle_us;
last_sent[last_idx++] = val;
last_idx &= (ITE_TX_FIFO_LEN);
val = (val - 1) & ITE_TX_RLE_MASK;
if (is_pulse)
val |= ITE_TX_PULSE;
else
val |= ITE_TX_SPACE;
if (fifo_avail <= 0)
fifo_avail = ITE_TX_FIFO_LEN - dev->params.get_tx_used_slots(dev);
if (fifo_avail <= 0) {
dev->params.
enable_tx_interrupt(dev);
spin_unlock_irqrestore(&dev->lock, flags);
wait_event_interruptible(dev->tx_queue, (fifo_avail = ITE_TX_FIFO_LEN - dev->params.get_tx_used_slots(dev)) >= 8);
spin_lock_irqsave(&dev->lock, flags);
dev->params.
disable_tx_interrupt(dev);
}
dev->params.put_tx_byte(dev, val);
fifo_avail--;
}
}
fifo_remaining = dev->params.get_tx_used_slots(dev);
remaining_us = 0;
while (fifo_remaining > 0) {
fifo_remaining--;
last_idx--;
last_idx &= (ITE_TX_FIFO_LEN - 1);
remaining_us += last_sent[last_idx];
}
remaining_us = (remaining_us * max_rle_us) / (ITE_TX_MAX_RLE);
spin_unlock_irqrestore(&dev->lock, flags);
mdelay(DIV_ROUND_UP(remaining_us, 1000));
spin_lock_irqsave(&dev->lock, flags);
dev->transmitting = false;
ite_set_carrier_params(dev);
if (dev->in_use)
dev->params.enable_rx(dev);
wake_up_interruptible(&dev->tx_ended);
spin_unlock_irqrestore(&dev->lock, flags);
return ret;
}
static void ite_s_idle(struct rc_dev *rcdev, bool enable)
{
unsigned long flags;
struct ite_dev *dev = rcdev->priv;
ite_dbg("%s called", __func__);
if (enable) {
spin_lock_irqsave(&dev->lock, flags);
dev->params.idle_rx(dev);
spin_unlock_irqrestore(&dev->lock, flags);
}
}
static int it87_get_irq_causes(struct ite_dev *dev)
{
u8 iflags;
int ret = 0;
ite_dbg("%s called", __func__);
iflags = inb(dev->cir_addr + IT87_IIR) & IT87_II;
switch (iflags) {
case IT87_II_RXDS:
ret = ITE_IRQ_RX_FIFO;
break;
case IT87_II_RXFO:
ret = ITE_IRQ_RX_FIFO_OVERRUN;
break;
case IT87_II_TXLDL:
ret = ITE_IRQ_TX_FIFO;
break;
}
return ret;
}
static void it87_set_carrier_params(struct ite_dev *dev, bool high_freq,
bool use_demodulator,
u8 carrier_freq_bits, u8 allowance_bits,
u8 pulse_width_bits)
{
u8 val;
ite_dbg("%s called", __func__);
val = inb(dev->cir_addr + IT87_RCR)
& ~(IT87_HCFS | IT87_RXEND | IT87_RXDCR);
if (high_freq)
val |= IT87_HCFS;
if (use_demodulator)
val |= IT87_RXEND;
val |= allowance_bits;
outb(val, dev->cir_addr + IT87_RCR);
outb((carrier_freq_bits << IT87_CFQ_SHIFT) | pulse_width_bits,
dev->cir_addr + IT87_TCR2);
}
static int it87_get_rx_bytes(struct ite_dev *dev, u8 * buf, int buf_size)
{
int fifo, read = 0;
ite_dbg("%s called", __func__);
fifo = inb(dev->cir_addr + IT87_RSR) & IT87_RXFBC;
while (fifo > 0 && buf_size > 0) {
*(buf++) = inb(dev->cir_addr + IT87_DR);
fifo--;
read++;
buf_size--;
}
return read;
}
static int it87_get_tx_used_slots(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
return inb(dev->cir_addr + IT87_TSR) & IT87_TXFBC;
}
static void it87_put_tx_byte(struct ite_dev *dev, u8 value)
{
outb(value, dev->cir_addr + IT87_DR);
}
static void it87_idle_rx(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT87_RCR) | IT87_RXACT,
dev->cir_addr + IT87_RCR);
outb(inb(dev->cir_addr + IT87_TCR1) | IT87_FIFOCLR,
dev->cir_addr + IT87_TCR1);
}
static void it87_disable_rx(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT87_IER) & ~(IT87_RDAIE | IT87_RFOIE),
dev->cir_addr + IT87_IER);
outb(inb(dev->cir_addr + IT87_RCR) & ~IT87_RXEN,
dev->cir_addr + IT87_RCR);
it87_idle_rx(dev);
}
static void it87_enable_rx(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT87_RCR) | IT87_RXEN,
dev->cir_addr + IT87_RCR);
it87_idle_rx(dev);
outb(inb(dev->cir_addr + IT87_IER) | IT87_RDAIE | IT87_RFOIE | IT87_IEC,
dev->cir_addr + IT87_IER);
}
static void it87_disable_tx_interrupt(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT87_IER) & ~IT87_TLDLIE,
dev->cir_addr + IT87_IER);
}
static void it87_enable_tx_interrupt(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT87_IER) | IT87_TLDLIE | IT87_IEC,
dev->cir_addr + IT87_IER);
}
static void it87_disable(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT87_IER) &
~(IT87_IEC | IT87_RFOIE | IT87_RDAIE | IT87_TLDLIE),
dev->cir_addr + IT87_IER);
it87_disable_rx(dev);
outb(IT87_FIFOCLR | inb(dev->cir_addr + IT87_TCR1),
dev->cir_addr + IT87_TCR1);
}
static void it87_init_hardware(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb((inb(dev->cir_addr + IT87_IER) &
~(IT87_IEC | IT87_RFOIE | IT87_RDAIE | IT87_TLDLIE)) | IT87_BR,
dev->cir_addr + IT87_IER);
outb(ITE_BAUDRATE_DIVISOR & 0xff, dev->cir_addr + IT87_BDLR);
outb((ITE_BAUDRATE_DIVISOR >> 8) & 0xff, dev->cir_addr + IT87_BDHR);
outb(inb(dev->cir_addr + IT87_IER) & ~IT87_BR,
dev->cir_addr + IT87_IER);
outb(ITE_RXDCR_DEFAULT, dev->cir_addr + IT87_RCR);
outb(IT87_TXMPM_DEFAULT | IT87_TXENDF | IT87_TXRLE
| IT87_FIFOTL_DEFAULT | IT87_FIFOCLR,
dev->cir_addr + IT87_TCR1);
ite_set_carrier_params(dev);
}
static int it8708_get_irq_causes(struct ite_dev *dev)
{
u8 iflags;
int ret = 0;
ite_dbg("%s called", __func__);
iflags = inb(dev->cir_addr + IT8708_C0IIR);
if (iflags & IT85_TLDLI)
ret |= ITE_IRQ_TX_FIFO;
if (iflags & IT85_RDAI)
ret |= ITE_IRQ_RX_FIFO;
if (iflags & IT85_RFOI)
ret |= ITE_IRQ_RX_FIFO_OVERRUN;
return ret;
}
static void it8708_set_carrier_params(struct ite_dev *dev, bool high_freq,
bool use_demodulator,
u8 carrier_freq_bits, u8 allowance_bits,
u8 pulse_width_bits)
{
u8 val;
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT8708_BANKSEL) | IT8708_HRAE,
dev->cir_addr + IT8708_BANKSEL);
val = (inb(dev->cir_addr + IT8708_C0CFR)
& ~(IT85_HCFS | IT85_CFQ)) | carrier_freq_bits;
if (high_freq)
val |= IT85_HCFS;
outb(val, dev->cir_addr + IT8708_C0CFR);
outb(inb(dev->cir_addr + IT8708_BANKSEL) & ~IT8708_HRAE,
dev->cir_addr + IT8708_BANKSEL);
val = inb(dev->cir_addr + IT8708_C0RCR)
& ~(IT85_RXEND | IT85_RXDCR);
if (use_demodulator)
val |= IT85_RXEND;
val |= allowance_bits;
outb(val, dev->cir_addr + IT8708_C0RCR);
val = inb(dev->cir_addr + IT8708_C0TCR) & ~IT85_TXMPW;
val |= pulse_width_bits;
outb(val, dev->cir_addr + IT8708_C0TCR);
}
static int it8708_get_rx_bytes(struct ite_dev *dev, u8 * buf, int buf_size)
{
int fifo, read = 0;
ite_dbg("%s called", __func__);
fifo = inb(dev->cir_addr + IT8708_C0RFSR) & IT85_RXFBC;
while (fifo > 0 && buf_size > 0) {
*(buf++) = inb(dev->cir_addr + IT8708_C0DR);
fifo--;
read++;
buf_size--;
}
return read;
}
static int it8708_get_tx_used_slots(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
return inb(dev->cir_addr + IT8708_C0TFSR) & IT85_TXFBC;
}
static void it8708_put_tx_byte(struct ite_dev *dev, u8 value)
{
outb(value, dev->cir_addr + IT8708_C0DR);
}
static void it8708_idle_rx(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT8708_C0RCR) | IT85_RXACT,
dev->cir_addr + IT8708_C0RCR);
outb(inb(dev->cir_addr + IT8708_C0MSTCR) | IT85_FIFOCLR,
dev->cir_addr + IT8708_C0MSTCR);
}
static void it8708_disable_rx(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT8708_C0IER) &
~(IT85_RDAIE | IT85_RFOIE),
dev->cir_addr + IT8708_C0IER);
outb(inb(dev->cir_addr + IT8708_C0RCR) & ~IT85_RXEN,
dev->cir_addr + IT8708_C0RCR);
it8708_idle_rx(dev);
}
static void it8708_enable_rx(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT8708_C0RCR) | IT85_RXEN,
dev->cir_addr + IT8708_C0RCR);
it8708_idle_rx(dev);
outb(inb(dev->cir_addr + IT8708_C0IER)
|IT85_RDAIE | IT85_RFOIE | IT85_IEC,
dev->cir_addr + IT8708_C0IER);
}
static void it8708_disable_tx_interrupt(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT8708_C0IER) & ~IT85_TLDLIE,
dev->cir_addr + IT8708_C0IER);
}
static void it8708_enable_tx_interrupt(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT8708_C0IER)
|IT85_TLDLIE | IT85_IEC,
dev->cir_addr + IT8708_C0IER);
}
static void it8708_disable(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT8708_C0IER) &
~(IT85_IEC | IT85_RFOIE | IT85_RDAIE | IT85_TLDLIE),
dev->cir_addr + IT8708_C0IER);
it8708_disable_rx(dev);
outb(IT85_FIFOCLR | inb(dev->cir_addr + IT8708_C0MSTCR),
dev->cir_addr + IT8708_C0MSTCR);
}
static void it8708_init_hardware(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
outb(inb(dev->cir_addr + IT8708_C0IER) &
~(IT85_IEC | IT85_RFOIE | IT85_RDAIE | IT85_TLDLIE),
dev->cir_addr + IT8708_C0IER);
outb(inb(dev->cir_addr + IT8708_BANKSEL) | IT8708_HRAE,
dev->cir_addr + IT8708_BANKSEL);
outb(ITE_BAUDRATE_DIVISOR & 0xff, dev->cir_addr + IT8708_C0BDLR);
outb((ITE_BAUDRATE_DIVISOR >> 8) & 0xff,
dev->cir_addr + IT8708_C0BDHR);
outb(inb(dev->cir_addr + IT8708_BANKSEL) & ~IT8708_HRAE,
dev->cir_addr + IT8708_BANKSEL);
outb((inb(dev->cir_addr + IT8708_C0MSTCR) &
~(IT85_ILSEL | IT85_ILE | IT85_FIFOTL |
IT85_FIFOCLR | IT85_RESET)) |
IT85_FIFOTL_DEFAULT,
dev->cir_addr + IT8708_C0MSTCR);
outb((inb(dev->cir_addr + IT8708_C0RCR) &
~(IT85_RXEN | IT85_RDWOS | IT85_RXEND |
IT85_RXACT | IT85_RXDCR)) |
ITE_RXDCR_DEFAULT,
dev->cir_addr + IT8708_C0RCR);
outb((inb(dev->cir_addr + IT8708_C0TCR) &
~(IT85_TXMPM | IT85_TXMPW))
|IT85_TXRLE | IT85_TXENDF |
IT85_TXMPM_DEFAULT | IT85_TXMPW_DEFAULT,
dev->cir_addr + IT8708_C0TCR);
ite_set_carrier_params(dev);
}
static inline u8 it8709_rm(struct ite_dev *dev, int index)
{
outb(index, dev->cir_addr + IT8709_RAM_IDX);
return inb(dev->cir_addr + IT8709_RAM_VAL);
}
static inline void it8709_wm(struct ite_dev *dev, u8 val, int index)
{
outb(index, dev->cir_addr + IT8709_RAM_IDX);
outb(val, dev->cir_addr + IT8709_RAM_VAL);
}
static void it8709_wait(struct ite_dev *dev)
{
int i = 0;
for (i = 0; i < 15000; i++) {
udelay(2);
if (it8709_rm(dev, IT8709_MODE) == IT8709_IDLE)
break;
}
}
static u8 it8709_rr(struct ite_dev *dev, int index)
{
it8709_wait(dev);
it8709_wm(dev, index, IT8709_REG_IDX);
it8709_wm(dev, IT8709_READ, IT8709_MODE);
it8709_wait(dev);
return it8709_rm(dev, IT8709_REG_VAL);
}
static void it8709_wr(struct ite_dev *dev, u8 val, int index)
{
it8709_wait(dev);
it8709_wm(dev, val, IT8709_REG_VAL);
it8709_wm(dev, index, IT8709_REG_IDX);
it8709_wm(dev, IT8709_WRITE, IT8709_MODE);
}
static int it8709_get_irq_causes(struct ite_dev *dev)
{
u8 iflags;
int ret = 0;
ite_dbg("%s called", __func__);
iflags = it8709_rm(dev, IT8709_IIR);
if (iflags & IT85_TLDLI)
ret |= ITE_IRQ_TX_FIFO;
if (iflags & IT85_RDAI)
ret |= ITE_IRQ_RX_FIFO;
if (iflags & IT85_RFOI)
ret |= ITE_IRQ_RX_FIFO_OVERRUN;
return ret;
}
static void it8709_set_carrier_params(struct ite_dev *dev, bool high_freq,
bool use_demodulator,
u8 carrier_freq_bits, u8 allowance_bits,
u8 pulse_width_bits)
{
u8 val;
ite_dbg("%s called", __func__);
val = (it8709_rr(dev, IT85_C0CFR)
&~(IT85_HCFS | IT85_CFQ)) |
carrier_freq_bits;
if (high_freq)
val |= IT85_HCFS;
it8709_wr(dev, val, IT85_C0CFR);
val = it8709_rr(dev, IT85_C0RCR)
& ~(IT85_RXEND | IT85_RXDCR);
if (use_demodulator)
val |= IT85_RXEND;
val |= allowance_bits;
it8709_wr(dev, val, IT85_C0RCR);
val = it8709_rr(dev, IT85_C0TCR) & ~IT85_TXMPW;
val |= pulse_width_bits;
it8709_wr(dev, val, IT85_C0TCR);
}
static int it8709_get_rx_bytes(struct ite_dev *dev, u8 * buf, int buf_size)
{
int fifo, read = 0;
ite_dbg("%s called", __func__);
fifo = it8709_rm(dev, IT8709_RFSR) & IT85_RXFBC;
while (fifo > 0 && buf_size > 0) {
*(buf++) = it8709_rm(dev, IT8709_FIFO + read);
fifo--;
read++;
buf_size--;
}
it8709_wm(dev, 0, IT8709_RFSR);
return read;
}
static int it8709_get_tx_used_slots(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
return it8709_rr(dev, IT85_C0TFSR) & IT85_TXFBC;
}
static void it8709_put_tx_byte(struct ite_dev *dev, u8 value)
{
it8709_wr(dev, value, IT85_C0DR);
}
static void it8709_idle_rx(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
it8709_wr(dev, it8709_rr(dev, IT85_C0RCR) | IT85_RXACT,
IT85_C0RCR);
it8709_wr(dev, it8709_rr(dev, IT85_C0MSTCR) | IT85_FIFOCLR,
IT85_C0MSTCR);
}
static void it8709_disable_rx(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
it8709_wr(dev, it8709_rr(dev, IT85_C0IER) &
~(IT85_RDAIE | IT85_RFOIE),
IT85_C0IER);
it8709_wr(dev, it8709_rr(dev, IT85_C0RCR) & ~IT85_RXEN,
IT85_C0RCR);
it8709_idle_rx(dev);
}
static void it8709_enable_rx(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
it8709_wr(dev, it8709_rr(dev, IT85_C0RCR) | IT85_RXEN,
IT85_C0RCR);
it8709_idle_rx(dev);
it8709_wr(dev, it8709_rr(dev, IT85_C0IER)
|IT85_RDAIE | IT85_RFOIE | IT85_IEC,
IT85_C0IER);
}
static void it8709_disable_tx_interrupt(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
it8709_wr(dev, it8709_rr(dev, IT85_C0IER) & ~IT85_TLDLIE,
IT85_C0IER);
}
static void it8709_enable_tx_interrupt(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
it8709_wr(dev, it8709_rr(dev, IT85_C0IER)
|IT85_TLDLIE | IT85_IEC,
IT85_C0IER);
}
static void it8709_disable(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
it8709_wr(dev, it8709_rr(dev, IT85_C0IER) &
~(IT85_IEC | IT85_RFOIE | IT85_RDAIE | IT85_TLDLIE),
IT85_C0IER);
it8709_disable_rx(dev);
it8709_wr(dev, IT85_FIFOCLR | it8709_rr(dev, IT85_C0MSTCR),
IT85_C0MSTCR);
}
static void it8709_init_hardware(struct ite_dev *dev)
{
ite_dbg("%s called", __func__);
it8709_wr(dev, it8709_rr(dev, IT85_C0IER) &
~(IT85_IEC | IT85_RFOIE | IT85_RDAIE | IT85_TLDLIE),
IT85_C0IER);
it8709_wr(dev, ITE_BAUDRATE_DIVISOR & 0xff, IT85_C0BDLR);
it8709_wr(dev, (ITE_BAUDRATE_DIVISOR >> 8) & 0xff,
IT85_C0BDHR);
it8709_wr(dev, (it8709_rr(dev, IT85_C0MSTCR) &
~(IT85_ILSEL | IT85_ILE | IT85_FIFOTL
| IT85_FIFOCLR | IT85_RESET)) | IT85_FIFOTL_DEFAULT,
IT85_C0MSTCR);
it8709_wr(dev, (it8709_rr(dev, IT85_C0RCR) &
~(IT85_RXEN | IT85_RDWOS | IT85_RXEND | IT85_RXACT
| IT85_RXDCR)) | ITE_RXDCR_DEFAULT,
IT85_C0RCR);
it8709_wr(dev, (it8709_rr(dev, IT85_C0TCR) & ~(IT85_TXMPM | IT85_TXMPW))
| IT85_TXRLE | IT85_TXENDF | IT85_TXMPM_DEFAULT
| IT85_TXMPW_DEFAULT,
IT85_C0TCR);
ite_set_carrier_params(dev);
}
static int ite_open(struct rc_dev *rcdev)
{
struct ite_dev *dev = rcdev->priv;
unsigned long flags;
ite_dbg("%s called", __func__);
spin_lock_irqsave(&dev->lock, flags);
dev->in_use = true;
dev->params.enable_rx(dev);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static void ite_close(struct rc_dev *rcdev)
{
struct ite_dev *dev = rcdev->priv;
unsigned long flags;
ite_dbg("%s called", __func__);
spin_lock_irqsave(&dev->lock, flags);
dev->in_use = false;
spin_unlock_irqrestore(&dev->lock, flags);
wait_event_interruptible(dev->tx_ended, !dev->transmitting);
spin_lock_irqsave(&dev->lock, flags);
dev->params.disable(dev);
spin_unlock_irqrestore(&dev->lock, flags);
}
static int ite_probe(struct pnp_dev *pdev, const struct pnp_device_id
*dev_id)
{
const struct ite_dev_params *dev_desc = NULL;
struct ite_dev *itdev = NULL;
struct rc_dev *rdev = NULL;
int ret = -ENOMEM;
int model_no;
int io_rsrc_no;
ite_dbg("%s called", __func__);
itdev = kzalloc(sizeof(struct ite_dev), GFP_KERNEL);
if (!itdev)
return ret;
rdev = rc_allocate_device();
if (!rdev)
goto failure;
itdev->rdev = rdev;
ret = -ENODEV;
model_no = (int)dev_id->driver_data;
ite_pr(KERN_NOTICE, "Auto-detected model: %s\n",
ite_dev_descs[model_no].model);
if (model_number >= 0 && model_number < ARRAY_SIZE(ite_dev_descs)) {
model_no = model_number;
ite_pr(KERN_NOTICE, "The model has been fixed by a module "
"parameter.");
}
ite_pr(KERN_NOTICE, "Using model: %s\n", ite_dev_descs[model_no].model);
dev_desc = &ite_dev_descs[model_no];
io_rsrc_no = dev_desc->io_rsrc_no;
if (!pnp_port_valid(pdev, io_rsrc_no) ||
pnp_port_len(pdev, io_rsrc_no) != dev_desc->io_region_size) {
dev_err(&pdev->dev, "IR PNP Port not valid!\n");
goto failure;
}
if (!pnp_irq_valid(pdev, 0)) {
dev_err(&pdev->dev, "PNP IRQ not valid!\n");
goto failure;
}
itdev->cir_addr = pnp_port_start(pdev, io_rsrc_no);
itdev->cir_irq = pnp_irq(pdev, 0);
spin_lock_init(&itdev->lock);
init_ir_raw_event(&itdev->rawir);
pnp_set_drvdata(pdev, itdev);
itdev->pdev = pdev;
init_waitqueue_head(&itdev->tx_queue);
init_waitqueue_head(&itdev->tx_ended);
itdev->params = *dev_desc;
if (sample_period > 0)
itdev->params.sample_period = sample_period;
if (tx_carrier_freq > 0)
itdev->params.tx_carrier_freq = tx_carrier_freq;
if (tx_duty_cycle > 0 && tx_duty_cycle <= 100)
itdev->params.tx_duty_cycle = tx_duty_cycle;
if (rx_low_carrier_freq > 0)
itdev->params.rx_low_carrier_freq = rx_low_carrier_freq;
if (rx_high_carrier_freq > 0)
itdev->params.rx_high_carrier_freq = rx_high_carrier_freq;
ite_pr(KERN_NOTICE, "TX-capable: %d\n", (int)
itdev->params.hw_tx_capable);
ite_pr(KERN_NOTICE, "Sample period (ns): %ld\n", (long)
itdev->params.sample_period);
ite_pr(KERN_NOTICE, "TX carrier frequency (Hz): %d\n", (int)
itdev->params.tx_carrier_freq);
ite_pr(KERN_NOTICE, "TX duty cycle (%%): %d\n", (int)
itdev->params.tx_duty_cycle);
ite_pr(KERN_NOTICE, "RX low carrier frequency (Hz): %d\n", (int)
itdev->params.rx_low_carrier_freq);
ite_pr(KERN_NOTICE, "RX high carrier frequency (Hz): %d\n", (int)
itdev->params.rx_high_carrier_freq);
itdev->params.init_hardware(itdev);
rdev->priv = itdev;
rdev->driver_type = RC_DRIVER_IR_RAW;
rdev->allowed_protos = RC_BIT_ALL;
rdev->open = ite_open;
rdev->close = ite_close;
rdev->s_idle = ite_s_idle;
rdev->s_rx_carrier_range = ite_set_rx_carrier_range;
rdev->min_timeout = ITE_MIN_IDLE_TIMEOUT;
rdev->max_timeout = ITE_MAX_IDLE_TIMEOUT;
rdev->timeout = ITE_IDLE_TIMEOUT;
rdev->rx_resolution = ITE_BAUDRATE_DIVISOR *
itdev->params.sample_period;
rdev->tx_resolution = ITE_BAUDRATE_DIVISOR *
itdev->params.sample_period;
if (itdev->params.hw_tx_capable) {
rdev->tx_ir = ite_tx_ir;
rdev->s_tx_carrier = ite_set_tx_carrier;
rdev->s_tx_duty_cycle = ite_set_tx_duty_cycle;
}
rdev->input_name = dev_desc->model;
rdev->input_id.bustype = BUS_HOST;
rdev->input_id.vendor = PCI_VENDOR_ID_ITE;
rdev->input_id.product = 0;
rdev->input_id.version = 0;
rdev->driver_name = ITE_DRIVER_NAME;
rdev->map_name = RC_MAP_RC6_MCE;
ret = -EBUSY;
if (!request_region(itdev->cir_addr,
dev_desc->io_region_size, ITE_DRIVER_NAME))
goto failure;
if (request_irq(itdev->cir_irq, ite_cir_isr, IRQF_SHARED,
ITE_DRIVER_NAME, (void *)itdev))
goto failure2;
ret = rc_register_device(rdev);
if (ret)
goto failure3;
ite_pr(KERN_NOTICE, "driver has been successfully loaded\n");
return 0;
failure3:
free_irq(itdev->cir_irq, itdev);
failure2:
release_region(itdev->cir_addr, itdev->params.io_region_size);
failure:
rc_free_device(rdev);
kfree(itdev);
return ret;
}
static void ite_remove(struct pnp_dev *pdev)
{
struct ite_dev *dev = pnp_get_drvdata(pdev);
unsigned long flags;
ite_dbg("%s called", __func__);
spin_lock_irqsave(&dev->lock, flags);
dev->params.disable(dev);
spin_unlock_irqrestore(&dev->lock, flags);
free_irq(dev->cir_irq, dev);
release_region(dev->cir_addr, dev->params.io_region_size);
rc_unregister_device(dev->rdev);
kfree(dev);
}
static int ite_suspend(struct pnp_dev *pdev, pm_message_t state)
{
struct ite_dev *dev = pnp_get_drvdata(pdev);
unsigned long flags;
ite_dbg("%s called", __func__);
wait_event_interruptible(dev->tx_ended, !dev->transmitting);
spin_lock_irqsave(&dev->lock, flags);
dev->params.disable(dev);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static int ite_resume(struct pnp_dev *pdev)
{
int ret = 0;
struct ite_dev *dev = pnp_get_drvdata(pdev);
unsigned long flags;
ite_dbg("%s called", __func__);
spin_lock_irqsave(&dev->lock, flags);
dev->params.init_hardware(dev);
dev->params.enable_rx(dev);
spin_unlock_irqrestore(&dev->lock, flags);
return ret;
}
static void ite_shutdown(struct pnp_dev *pdev)
{
struct ite_dev *dev = pnp_get_drvdata(pdev);
unsigned long flags;
ite_dbg("%s called", __func__);
spin_lock_irqsave(&dev->lock, flags);
dev->params.disable(dev);
spin_unlock_irqrestore(&dev->lock, flags);
}
static int ite_init(void)
{
return pnp_register_driver(&ite_driver);
}
static void ite_exit(void)
{
pnp_unregister_driver(&ite_driver);
}
