static unsigned int __i8254_read(struct comedi_8254 *i8254, unsigned int reg)
{
unsigned int reg_offset = (reg * i8254->iosize) << i8254->regshift;
unsigned int val;
switch (i8254->iosize) {
default:
case I8254_IO8:
if (i8254->mmio)
val = readb(i8254->mmio + reg_offset);
else
val = inb(i8254->iobase + reg_offset);
break;
case I8254_IO16:
if (i8254->mmio)
val = readw(i8254->mmio + reg_offset);
else
val = inw(i8254->iobase + reg_offset);
break;
case I8254_IO32:
if (i8254->mmio)
val = readl(i8254->mmio + reg_offset);
else
val = inl(i8254->iobase + reg_offset);
break;
}
return val & 0xff;
}
static void __i8254_write(struct comedi_8254 *i8254,
unsigned int val, unsigned int reg)
{
unsigned int reg_offset = (reg * i8254->iosize) << i8254->regshift;
switch (i8254->iosize) {
default:
case I8254_IO8:
if (i8254->mmio)
writeb(val, i8254->mmio + reg_offset);
else
outb(val, i8254->iobase + reg_offset);
break;
case I8254_IO16:
if (i8254->mmio)
writew(val, i8254->mmio + reg_offset);
else
outw(val, i8254->iobase + reg_offset);
break;
case I8254_IO32:
if (i8254->mmio)
writel(val, i8254->mmio + reg_offset);
else
outl(val, i8254->iobase + reg_offset);
break;
}
}
unsigned int comedi_8254_status(struct comedi_8254 *i8254, unsigned int counter)
{
unsigned int cmd;
if (counter > 2)
return 0;
cmd = I8254_CTRL_READBACK_STATUS | I8254_CTRL_READBACK_SEL_CTR(counter);
__i8254_write(i8254, cmd, I8254_CTRL_REG);
return __i8254_read(i8254, counter);
}
unsigned int comedi_8254_read(struct comedi_8254 *i8254, unsigned int counter)
{
unsigned int val;
if (counter > 2)
return 0;
__i8254_write(i8254, I8254_CTRL_SEL_CTR(counter) | I8254_CTRL_LATCH,
I8254_CTRL_REG);
val = __i8254_read(i8254, counter);
val |= (__i8254_read(i8254, counter) << 8);
return val;
}
void comedi_8254_write(struct comedi_8254 *i8254,
unsigned int counter, unsigned int val)
{
unsigned int byte;
if (counter > 2)
return;
if (val > 0xffff)
return;
byte = val & 0xff;
__i8254_write(i8254, byte, counter);
byte = (val >> 8) & 0xff;
__i8254_write(i8254, byte, counter);
}
int comedi_8254_set_mode(struct comedi_8254 *i8254, unsigned int counter,
unsigned int mode)
{
unsigned int byte;
if (counter > 2)
return -EINVAL;
if (mode > (I8254_MODE5 | I8254_BCD))
return -EINVAL;
byte = I8254_CTRL_SEL_CTR(counter) |
I8254_CTRL_LSB_MSB |
mode;
__i8254_write(i8254, byte, I8254_CTRL_REG);
return 0;
}
int comedi_8254_load(struct comedi_8254 *i8254, unsigned int counter,
unsigned int val, unsigned int mode)
{
if (counter > 2)
return -EINVAL;
if (val > 0xffff)
return -EINVAL;
if (mode > (I8254_MODE5 | I8254_BCD))
return -EINVAL;
comedi_8254_set_mode(i8254, counter, mode);
comedi_8254_write(i8254, counter, val);
return 0;
}
void comedi_8254_pacer_enable(struct comedi_8254 *i8254,
unsigned int counter1,
unsigned int counter2,
bool enable)
{
unsigned int mode;
if (counter1 > 2 || counter2 > 2 || counter1 == counter2)
return;
if (enable)
mode = I8254_MODE2 | I8254_BINARY;
else
mode = I8254_MODE0 | I8254_BINARY;
comedi_8254_set_mode(i8254, counter1, mode);
comedi_8254_set_mode(i8254, counter2, mode);
if (enable) {
comedi_8254_write(i8254, counter2, i8254->divisor2);
comedi_8254_write(i8254, counter1, i8254->divisor1);
}
}
void comedi_8254_update_divisors(struct comedi_8254 *i8254)
{
i8254->divisor = i8254->next_div & 0xffff;
i8254->divisor1 = i8254->next_div1 & 0xffff;
i8254->divisor2 = i8254->next_div2 & 0xffff;
}
void comedi_8254_cascade_ns_to_timer(struct comedi_8254 *i8254,
unsigned int *nanosec,
unsigned int flags)
{
unsigned int d1 = i8254->next_div1 ? i8254->next_div1 : I8254_MAX_COUNT;
unsigned int d2 = i8254->next_div2 ? i8254->next_div2 : I8254_MAX_COUNT;
unsigned int div = d1 * d2;
unsigned int ns_lub = 0xffffffff;
unsigned int ns_glb = 0;
unsigned int d1_lub = 0;
unsigned int d1_glb = 0;
unsigned int d2_lub = 0;
unsigned int d2_glb = 0;
unsigned int start;
unsigned int ns;
unsigned int ns_low;
unsigned int ns_high;
if (div * i8254->osc_base == *nanosec &&
d1 > 1 && d1 <= I8254_MAX_COUNT &&
d2 > 1 && d2 <= I8254_MAX_COUNT &&
div > d1 && div > d2 &&
div * i8254->osc_base > div &&
div * i8254->osc_base > i8254->osc_base)
return;
div = *nanosec / i8254->osc_base;
d2 = I8254_MAX_COUNT;
start = div / d2;
if (start < 2)
start = 2;
for (d1 = start; d1 <= div / d1 + 1 && d1 <= I8254_MAX_COUNT; d1++) {
for (d2 = div / d1;
d1 * d2 <= div + d1 + 1 && d2 <= I8254_MAX_COUNT; d2++) {
ns = i8254->osc_base * d1 * d2;
if (ns <= *nanosec && ns > ns_glb) {
ns_glb = ns;
d1_glb = d1;
d2_glb = d2;
}
if (ns >= *nanosec && ns < ns_lub) {
ns_lub = ns;
d1_lub = d1;
d2_lub = d2;
}
}
}
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
ns_high = d1_lub * d2_lub * i8254->osc_base;
ns_low = d1_glb * d2_glb * i8254->osc_base;
if (ns_high - *nanosec < *nanosec - ns_low) {
d1 = d1_lub;
d2 = d2_lub;
} else {
d1 = d1_glb;
d2 = d2_glb;
}
break;
case CMDF_ROUND_UP:
d1 = d1_lub;
d2 = d2_lub;
break;
case CMDF_ROUND_DOWN:
d1 = d1_glb;
d2 = d2_glb;
break;
}
*nanosec = d1 * d2 * i8254->osc_base;
i8254->next_div1 = d1;
i8254->next_div2 = d2;
}
void comedi_8254_ns_to_timer(struct comedi_8254 *i8254,
unsigned int *nanosec, unsigned int flags)
{
unsigned int divisor;
switch (flags & CMDF_ROUND_MASK) {
default:
case CMDF_ROUND_NEAREST:
divisor = DIV_ROUND_CLOSEST(*nanosec, i8254->osc_base);
break;
case CMDF_ROUND_UP:
divisor = DIV_ROUND_UP(*nanosec, i8254->osc_base);
break;
case CMDF_ROUND_DOWN:
divisor = *nanosec / i8254->osc_base;
break;
}
if (divisor < 2)
divisor = 2;
if (divisor > I8254_MAX_COUNT)
divisor = I8254_MAX_COUNT;
*nanosec = divisor * i8254->osc_base;
i8254->next_div = divisor;
}
void comedi_8254_set_busy(struct comedi_8254 *i8254,
unsigned int counter, bool busy)
{
if (counter < 3)
i8254->busy[counter] = busy;
}
static int comedi_8254_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct comedi_8254 *i8254 = s->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
if (i8254->busy[chan])
return -EBUSY;
for (i = 0; i < insn->n; i++)
data[i] = comedi_8254_read(i8254, chan);
return insn->n;
}
static int comedi_8254_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct comedi_8254 *i8254 = s->private;
unsigned int chan = CR_CHAN(insn->chanspec);
if (i8254->busy[chan])
return -EBUSY;
if (insn->n)
comedi_8254_write(i8254, chan, data[insn->n - 1]);
return insn->n;
}
static int comedi_8254_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct comedi_8254 *i8254 = s->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int ret;
if (i8254->busy[chan])
return -EBUSY;
switch (data[0]) {
case INSN_CONFIG_RESET:
ret = comedi_8254_set_mode(i8254, chan,
I8254_MODE0 | I8254_BINARY);
if (ret)
return ret;
break;
case INSN_CONFIG_SET_COUNTER_MODE:
ret = comedi_8254_set_mode(i8254, chan, data[1]);
if (ret)
return ret;
break;
case INSN_CONFIG_8254_READ_STATUS:
data[1] = comedi_8254_status(i8254, chan);
break;
default:
if (i8254->insn_config)
return i8254->insn_config(dev, s, insn, data);
return -EINVAL;
}
return insn->n;
}
void comedi_8254_subdevice_init(struct comedi_subdevice *s,
struct comedi_8254 *i8254)
{
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 3;
s->maxdata = 0xffff;
s->range_table = &range_unknown;
s->insn_read = comedi_8254_insn_read;
s->insn_write = comedi_8254_insn_write;
s->insn_config = comedi_8254_insn_config;
s->private = i8254;
}
static struct comedi_8254 *__i8254_init(unsigned long iobase,
void __iomem *mmio,
unsigned int osc_base,
unsigned int iosize,
unsigned int regshift)
{
struct comedi_8254 *i8254;
int i;
if (!(iosize == I8254_IO8 || iosize == I8254_IO16 ||
iosize == I8254_IO32))
return NULL;
i8254 = kzalloc(sizeof(*i8254), GFP_KERNEL);
if (!i8254)
return NULL;
i8254->iobase = iobase;
i8254->mmio = mmio;
i8254->iosize = iosize;
i8254->regshift = regshift;
i8254->osc_base = osc_base ? osc_base : I8254_OSC_BASE_10MHZ;
for (i = 0; i < 3; i++)
comedi_8254_set_mode(i8254, i, I8254_MODE0 | I8254_BINARY);
return i8254;
}
struct comedi_8254 *comedi_8254_init(unsigned long iobase,
unsigned int osc_base,
unsigned int iosize,
unsigned int regshift)
{
return __i8254_init(iobase, NULL, osc_base, iosize, regshift);
}
struct comedi_8254 *comedi_8254_mm_init(void __iomem *mmio,
unsigned int osc_base,
unsigned int iosize,
unsigned int regshift)
{
return __i8254_init(0, mmio, osc_base, iosize, regshift);
}
static int __init comedi_8254_module_init(void)
{
return 0;
}
static void __exit comedi_8254_module_exit(void)
{
}
