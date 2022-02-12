static u8 ReadByteFromHwPort(unsigned long addr)
{
u8 result = inb(addr);
return result;
}
static void WriteByteToHwPort(unsigned long addr, u8 val)
{
outb_p(val, addr);
}
static void C6X_pwmInit(unsigned long baseAddr)
{
int timeout = 0;
WriteByteToHwPort(baseAddr, 0x70);
while (((ReadByteFromHwPort(baseAddr + 1) & 0x80) == 0)
&& (timeout < C6XDIGIO_TIME_OUT)) {
timeout++;
}
WriteByteToHwPort(baseAddr, 0x74);
timeout = 0;
while (((ReadByteFromHwPort(baseAddr + 1) & 0x80) == 0x80)
&& (timeout < C6XDIGIO_TIME_OUT)) {
timeout++;
}
WriteByteToHwPort(baseAddr, 0x70);
timeout = 0;
while (((ReadByteFromHwPort(baseAddr + 1) & 0x80) == 0x0)
&& (timeout < C6XDIGIO_TIME_OUT)) {
timeout++;
}
WriteByteToHwPort(baseAddr, 0x0);
timeout = 0;
while (((ReadByteFromHwPort(baseAddr + 1) & 0x80) == 0x80)
&& (timeout < C6XDIGIO_TIME_OUT)) {
timeout++;
}
}
static void C6X_pwmOutput(unsigned long baseAddr, unsigned channel, int value)
{
unsigned ppcmd;
union pwmcmdtype pwm;
int timeout = 0;
unsigned tmp;
pwm.cmd = value;
if (pwm.cmd > 498)
pwm.cmd = 498;
if (pwm.cmd < 2)
pwm.cmd = 2;
if (channel == 0) {
ppcmd = 0x28;
} else {
ppcmd = 0x30;
}
WriteByteToHwPort(baseAddr, ppcmd + pwm.bits.sb0);
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
WriteByteToHwPort(baseAddr, ppcmd + pwm.bits.sb1 + 0x4);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x80) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
WriteByteToHwPort(baseAddr, ppcmd + pwm.bits.sb2);
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
WriteByteToHwPort(baseAddr, ppcmd + pwm.bits.sb3 + 0x4);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x80) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
WriteByteToHwPort(baseAddr, ppcmd + pwm.bits.sb4);
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
WriteByteToHwPort(baseAddr, 0x0);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x80) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
}
static int C6X_encInput(unsigned long baseAddr, unsigned channel)
{
unsigned ppcmd;
union encvaluetype enc;
int timeout = 0;
int tmp;
enc.value = 0;
if (channel == 0)
ppcmd = 0x48;
else
ppcmd = 0x50;
WriteByteToHwPort(baseAddr, ppcmd);
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
enc.bits.sb0 = ((ReadByteFromHwPort(baseAddr + 1) >> 3) & 0x7);
WriteByteToHwPort(baseAddr, ppcmd + 0x4);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x80) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
enc.bits.sb1 = ((ReadByteFromHwPort(baseAddr + 1) >> 3) & 0x7);
WriteByteToHwPort(baseAddr, ppcmd);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
enc.bits.sb2 = ((ReadByteFromHwPort(baseAddr + 1) >> 3) & 0x7);
WriteByteToHwPort(baseAddr, ppcmd + 0x4);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x80) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
enc.bits.sb3 = ((ReadByteFromHwPort(baseAddr + 1) >> 3) & 0x7);
WriteByteToHwPort(baseAddr, ppcmd);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
enc.bits.sb4 = ((ReadByteFromHwPort(baseAddr + 1) >> 3) & 0x7);
WriteByteToHwPort(baseAddr, ppcmd + 0x4);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x80) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
enc.bits.sb5 = ((ReadByteFromHwPort(baseAddr + 1) >> 3) & 0x7);
WriteByteToHwPort(baseAddr, ppcmd);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x0) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
enc.bits.sb6 = ((ReadByteFromHwPort(baseAddr + 1) >> 3) & 0x7);
WriteByteToHwPort(baseAddr, ppcmd + 0x4);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x80) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
enc.bits.sb7 = ((ReadByteFromHwPort(baseAddr + 1) >> 3) & 0x7);
WriteByteToHwPort(baseAddr, ppcmd);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x0) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
WriteByteToHwPort(baseAddr, 0x0);
timeout = 0;
tmp = ReadByteFromHwPort(baseAddr + 1);
while (((tmp & 0x80) == 0x80) && (timeout < C6XDIGIO_TIME_OUT)) {
tmp = ReadByteFromHwPort(baseAddr + 1);
timeout++;
}
return enc.value ^ 0x800000;
}
static void C6X_encResetAll(unsigned long baseAddr)
{
unsigned timeout = 0;
WriteByteToHwPort(baseAddr, 0x68);
while (((ReadByteFromHwPort(baseAddr + 1) & 0x80) == 0)
&& (timeout < C6XDIGIO_TIME_OUT)) {
timeout++;
}
WriteByteToHwPort(baseAddr, 0x6C);
timeout = 0;
while (((ReadByteFromHwPort(baseAddr + 1) & 0x80) == 0x80)
&& (timeout < C6XDIGIO_TIME_OUT)) {
timeout++;
}
WriteByteToHwPort(baseAddr, 0x68);
timeout = 0;
while (((ReadByteFromHwPort(baseAddr + 1) & 0x80) == 0x0)
&& (timeout < C6XDIGIO_TIME_OUT)) {
timeout++;
}
WriteByteToHwPort(baseAddr, 0x0);
timeout = 0;
while (((ReadByteFromHwPort(baseAddr + 1) & 0x80) == 0x80)
&& (timeout < C6XDIGIO_TIME_OUT)) {
timeout++;
}
}
static int c6xdigio_pwmo_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
printk(KERN_DEBUG "c6xdigio_pwmo_insn_read %x\n", insn->n);
return insn->n;
}
static int c6xdigio_pwmo_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
C6X_pwmOutput(dev->iobase, chan, data[i]);
}
return i;
}
static int c6xdigio_ei_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++)
data[n] = (C6X_encInput(dev->iobase, chan) & 0xffffff);
return n;
}
static void board_init(struct comedi_device *dev)
{
C6X_pwmInit(dev->iobase);
C6X_encResetAll(dev->iobase);
}
static int c6xdigio_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
int result = 0;
unsigned long iobase;
unsigned int irq;
struct comedi_subdevice *s;
iobase = it->options[0];
printk(KERN_DEBUG "comedi%d: c6xdigio: 0x%04lx\n", dev->minor, iobase);
if (!request_region(iobase, C6XDIGIO_SIZE, "c6xdigio")) {
printk(KERN_ERR "comedi%d: I/O port conflict\n", dev->minor);
return -EIO;
}
dev->iobase = iobase;
dev->board_name = "c6xdigio";
result = alloc_subdevices(dev, 2);
if (result < 0)
return result;
pnp_register_driver(&c6xdigio_pnp_driver);
irq = it->options[1];
if (irq > 0)
printk(KERN_DEBUG "comedi%d: irq = %u ignored\n",
dev->minor, irq);
else if (irq == 0)
printk(KERN_DEBUG "comedi%d: no irq\n", dev->minor);
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 2;
s->insn_read = c6xdigio_pwmo_insn_read;
s->insn_write = c6xdigio_pwmo_insn_write;
s->maxdata = 500;
s->range_table = &range_bipolar10;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_LSAMPL;
s->n_chan = 2;
s->insn_read = c6xdigio_ei_insn_read;
s->maxdata = 0xffffff;
s->range_table = &range_unknown;
board_init(dev);
return 0;
}
static void c6xdigio_detach(struct comedi_device *dev)
{
if (dev->iobase)
release_region(dev->iobase, C6XDIGIO_SIZE);
if (dev->irq)
free_irq(dev->irq, dev);
pnp_unregister_driver(&c6xdigio_pnp_driver);
}
