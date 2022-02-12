static int apci1564_timer_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int ctrl;
devpriv->tsk_current = current;
ctrl = inl(devpriv->timer + ADDI_TCW_CTRL_REG);
ctrl &= 0xfffff9fe;
outl(ctrl, devpriv->timer + ADDI_TCW_CTRL_REG);
if (data[1] == 1) {
outl(0x02, devpriv->timer + ADDI_TCW_CTRL_REG);
outl(0x0, dev->iobase + APCI1564_DI_IRQ_REG);
outl(0x0, dev->iobase + APCI1564_DO_IRQ_REG);
outl(0x0, dev->iobase + APCI1564_WDOG_IRQ_REG);
if (devpriv->counters) {
unsigned long iobase;
iobase = devpriv->counters + ADDI_TCW_IRQ_REG;
outl(0x0, iobase + APCI1564_COUNTER(0));
outl(0x0, iobase + APCI1564_COUNTER(1));
outl(0x0, iobase + APCI1564_COUNTER(2));
}
} else {
outl(0x0, devpriv->timer + ADDI_TCW_CTRL_REG);
}
outl(data[2], devpriv->timer + ADDI_TCW_TIMEBASE_REG);
outl(data[3], devpriv->timer + ADDI_TCW_RELOAD_REG);
ctrl = inl(devpriv->timer + ADDI_TCW_CTRL_REG);
ctrl &= 0xfff719e2;
ctrl |= (2 << 13) | 0x10;
outl(ctrl, devpriv->timer + ADDI_TCW_CTRL_REG);
return insn->n;
}
static int apci1564_timer_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int ctrl;
ctrl = inl(devpriv->timer + ADDI_TCW_CTRL_REG);
switch (data[1]) {
case 0:
ctrl &= 0xfffff9fe;
break;
case 1:
ctrl &= 0xfffff9ff;
ctrl |= 0x1;
break;
}
outl(ctrl, devpriv->timer + ADDI_TCW_CTRL_REG);
return insn->n;
}
static int apci1564_timer_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
data[0] = inl(devpriv->timer + ADDI_TCW_STATUS_REG) & 0x1;
data[1] = inl(devpriv->timer + ADDI_TCW_VAL_REG);
return insn->n;
}
static int apci1564_counter_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned long iobase = devpriv->counters + APCI1564_COUNTER(chan);
unsigned int ctrl;
devpriv->tsk_current = current;
ctrl = inl(iobase + ADDI_TCW_CTRL_REG);
ctrl &= 0xfffff9fe;
outl(ctrl, iobase + ADDI_TCW_CTRL_REG);
outl(data[3], iobase + ADDI_TCW_RELOAD_REG);
ctrl &= 0xfffc19e2;
ctrl |= 0x80000 | (data[4] << 16);
outl(ctrl, iobase + ADDI_TCW_CTRL_REG);
ctrl &= 0xfffff9fd;
ctrl |= (data[1] << 1);
outl(ctrl, iobase + ADDI_TCW_CTRL_REG);
ctrl &= 0xfffbf9ff;
ctrl |= (data[6] << 18);
outl(ctrl, iobase + ADDI_TCW_CTRL_REG);
return insn->n;
}
static int apci1564_counter_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned long iobase = devpriv->counters + APCI1564_COUNTER(chan);
unsigned int ctrl;
ctrl = inl(iobase + ADDI_TCW_CTRL_REG);
switch (data[1]) {
case 0:
ctrl = 0;
break;
case 1:
ctrl &= 0xfffff9ff;
ctrl |= 0x1;
break;
case 2:
ctrl &= 0xfffff9ff;
ctrl |= 0x400;
break;
}
outl(ctrl, iobase + ADDI_TCW_CTRL_REG);
return insn->n;
}
static int apci1564_counter_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned long iobase = devpriv->counters + APCI1564_COUNTER(chan);
unsigned int status;
data[0] = inl(iobase + ADDI_TCW_VAL_REG);
status = inl(iobase + ADDI_TCW_STATUS_REG);
data[1] = (status >> 1) & 1;
data[2] = (status >> 2) & 1;
data[3] = (status >> 3) & 1;
data[4] = (status >> 0) & 1;
return insn->n;
}
