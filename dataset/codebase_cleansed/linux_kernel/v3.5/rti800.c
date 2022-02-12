static irqreturn_t rti800_interrupt(int irq, void *dev)
{
return IRQ_HANDLED;
}
static int rti800_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i, t;
int status;
int chan = CR_CHAN(insn->chanspec);
unsigned gain = CR_RANGE(insn->chanspec);
unsigned muxgain_bits;
inb(dev->iobase + RTI800_ADCHI);
outb(0, dev->iobase + RTI800_CLRFLAGS);
muxgain_bits = chan | (gain << 5);
if (muxgain_bits != devpriv->muxgain_bits) {
devpriv->muxgain_bits = muxgain_bits;
outb(devpriv->muxgain_bits, dev->iobase + RTI800_MUXGAIN);
if (insn->n > 0) {
BUG_ON(gain >= ARRAY_SIZE(gaindelay));
udelay(gaindelay[gain]);
}
}
for (i = 0; i < insn->n; i++) {
outb(0, dev->iobase + RTI800_CONVERT);
for (t = RTI800_TIMEOUT; t; t--) {
status = inb(dev->iobase + RTI800_CSR);
if (status & RTI800_OVERRUN) {
printk(KERN_WARNING "rti800: a/d overrun\n");
outb(0, dev->iobase + RTI800_CLRFLAGS);
return -EIO;
}
if (status & RTI800_DONE)
break;
udelay(1);
}
if (t == 0) {
printk(KERN_WARNING "rti800: timeout\n");
return -ETIME;
}
data[i] = inb(dev->iobase + RTI800_ADCLO);
data[i] |= (0xf & inb(dev->iobase + RTI800_ADCHI)) << 8;
if (devpriv->adc_coding == adc_2comp)
data[i] ^= 0x800;
}
return i;
}
static int rti800_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int rti800_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
int d;
int i;
for (i = 0; i < insn->n; i++) {
devpriv->ao_readback[chan] = d = data[i];
if (devpriv->dac0_coding == dac_2comp)
d ^= 0x800;
outb(d & 0xff,
dev->iobase + (chan ? RTI800_DAC1LO : RTI800_DAC0LO));
outb(d >> 8,
dev->iobase + (chan ? RTI800_DAC1HI : RTI800_DAC0HI));
}
return i;
}
static int rti800_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
data[1] = inb(dev->iobase + RTI800_DI);
return 2;
}
static int rti800_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
outb(s->state ^ 0xff, dev->iobase + RTI800_DO);
}
data[1] = s->state;
return 2;
}
static int rti800_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
unsigned int irq;
unsigned long iobase;
int ret;
struct comedi_subdevice *s;
iobase = it->options[0];
printk(KERN_INFO "comedi%d: rti800: 0x%04lx\n", dev->minor, iobase);
if (!request_region(iobase, RTI800_SIZE, "rti800")) {
printk(KERN_WARNING "I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
#ifdef DEBUG
printk(KERN_DEBUG "fingerprint=%x,%x,%x,%x,%x ",
inb(dev->iobase + 0),
inb(dev->iobase + 1),
inb(dev->iobase + 2),
inb(dev->iobase + 3), inb(dev->iobase + 4));
#endif
outb(0, dev->iobase + RTI800_CSR);
inb(dev->iobase + RTI800_ADCHI);
outb(0, dev->iobase + RTI800_CLRFLAGS);
irq = it->options[1];
if (irq) {
printk(KERN_INFO "( irq = %u )\n", irq);
ret = request_irq(irq, rti800_interrupt, 0, "rti800", dev);
if (ret < 0) {
printk(KERN_WARNING " Failed to allocate IRQ\n");
return ret;
}
dev->irq = irq;
} else {
printk(KERN_INFO "( no irq )\n");
}
dev->board_name = this_board->name;
ret = alloc_subdevices(dev, 4);
if (ret < 0)
return ret;
ret = alloc_private(dev, sizeof(struct rti800_private));
if (ret < 0)
return ret;
devpriv->adc_mux = it->options[2];
devpriv->adc_range = it->options[3];
devpriv->adc_coding = it->options[4];
devpriv->dac0_range = it->options[5];
devpriv->dac0_coding = it->options[6];
devpriv->dac1_range = it->options[7];
devpriv->dac1_coding = it->options[8];
devpriv->muxgain_bits = -1;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = (devpriv->adc_mux ? 16 : 8);
s->insn_read = rti800_ai_insn_read;
s->maxdata = 0xfff;
switch (devpriv->adc_range) {
case adc_bipolar10:
s->range_table = &range_rti800_ai_10_bipolar;
break;
case adc_bipolar5:
s->range_table = &range_rti800_ai_5_bipolar;
break;
case adc_unipolar10:
s->range_table = &range_rti800_ai_unipolar;
break;
}
s++;
if (this_board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->insn_read = rti800_ao_insn_read;
s->insn_write = rti800_ao_insn_write;
s->maxdata = 0xfff;
s->range_table_list = devpriv->ao_range_type_list;
switch (devpriv->dac0_range) {
case dac_bipolar10:
devpriv->ao_range_type_list[0] = &range_bipolar10;
break;
case dac_unipolar10:
devpriv->ao_range_type_list[0] = &range_unipolar10;
break;
}
switch (devpriv->dac1_range) {
case dac_bipolar10:
devpriv->ao_range_type_list[1] = &range_bipolar10;
break;
case dac_unipolar10:
devpriv->ao_range_type_list[1] = &range_unipolar10;
break;
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s++;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 8;
s->insn_bits = rti800_di_insn_bits;
s->maxdata = 1;
s->range_table = &range_digital;
s++;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 8;
s->insn_bits = rti800_do_insn_bits;
s->maxdata = 1;
s->range_table = &range_digital;
#if 0
s++;
s->type = COMEDI_SUBD_TIMER;
#endif
return 0;
}
static void rti800_detach(struct comedi_device *dev)
{
if (dev->iobase)
release_region(dev->iobase, RTI800_SIZE);
if (dev->irq)
free_irq(dev->irq, dev);
}
