static int apci1564_timer_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
devpriv->tsk_current = current;
if (data[0] == ADDIDATA_TIMER) {
ul_Command1 = inl(devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1, devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
devpriv->timer_select_mode = ADDIDATA_TIMER;
if (data[1] == 1) {
outl(0x02, devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
outl(0x0, devpriv->amcc_iobase + APCI1564_DI_IRQ_REG);
outl(0x0, devpriv->amcc_iobase + APCI1564_DO_IRQ_REG);
outl(0x0, devpriv->amcc_iobase + APCI1564_WDOG_IRQ_REG);
outl(0x0, dev->iobase +
APCI1564_COUNTER_IRQ_REG(APCI1564_COUNTER1));
outl(0x0, dev->iobase +
APCI1564_COUNTER_IRQ_REG(APCI1564_COUNTER2));
outl(0x0, dev->iobase +
APCI1564_COUNTER_IRQ_REG(APCI1564_COUNTER3));
outl(0x0, dev->iobase +
APCI1564_COUNTER_IRQ_REG(APCI1564_COUNTER4));
} else {
outl(0x0, devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
}
outl(data[2], devpriv->amcc_iobase + APCI1564_TIMER_TIMEBASE_REG);
outl(data[3], devpriv->amcc_iobase + APCI1564_TIMER_RELOAD_REG);
ul_Command1 = inl(devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
ul_Command1 = (ul_Command1 & 0xFFF719E2UL) | 2UL << 13UL | 0x10UL;
outl(ul_Command1, devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
} else if (data[0] == ADDIDATA_COUNTER) {
devpriv->timer_select_mode = ADDIDATA_COUNTER;
devpriv->mode_select_register = data[5];
ul_Command1 = inl(dev->iobase +
APCI1564_COUNTER_CTRL_REG(data[5] - 1));
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1, dev->iobase +
APCI1564_COUNTER_CTRL_REG(data[5] - 1));
outl(data[3], dev->iobase +
APCI1564_COUNTER_RELOAD_REG(data[5] - 1));
ul_Command1 =
(ul_Command1 & 0xFFFC19E2UL) | 0x80000UL |
(unsigned int) ((unsigned int) data[4] << 16UL);
outl(ul_Command1, dev->iobase +
APCI1564_COUNTER_CTRL_REG(data[5] - 1));
ul_Command1 = (ul_Command1 & 0xFFFFF9FD) | (data[1] << 1);
outl(ul_Command1, dev->iobase +
APCI1564_COUNTER_CTRL_REG(data[5] - 1));
ul_Command1 = (ul_Command1 & 0xFFFBF9FFUL) | (data[6] << 18);
outl(ul_Command1, dev->iobase +
APCI1564_COUNTER_CTRL_REG(data[5] - 1));
} else {
dev_err(dev->class_dev, "Invalid subdevice.\n");
}
return insn->n;
}
static int apci1564_timer_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
if (devpriv->timer_select_mode == ADDIDATA_TIMER) {
if (data[1] == 1) {
ul_Command1 = inl(devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x1UL;
outl(ul_Command1, devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
} else if (data[1] == 0) {
ul_Command1 = inl(devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1, devpriv->amcc_iobase + APCI1564_TIMER_CTRL_REG);
}
} else if (devpriv->timer_select_mode == ADDIDATA_COUNTER) {
ul_Command1 =
inl(dev->iobase +
APCI1564_COUNTER_CTRL_REG(devpriv->mode_select_register - 1));
if (data[1] == 1) {
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x1UL;
} else if (data[1] == 0) {
ul_Command1 = 0;
} else if (data[1] == 2) {
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x400;
}
outl(ul_Command1, dev->iobase +
APCI1564_COUNTER_CTRL_REG(devpriv->mode_select_register - 1));
} else {
dev_err(dev->class_dev, "Invalid subdevice.\n");
}
return insn->n;
}
static int apci1564_timer_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
if (devpriv->timer_select_mode == ADDIDATA_TIMER) {
data[0] = inl(devpriv->amcc_iobase + APCI1564_TIMER_STATUS_REG) & 0x1;
data[1] = inl(devpriv->amcc_iobase + APCI1564_TIMER_REG);
} else if (devpriv->timer_select_mode == ADDIDATA_COUNTER) {
data[0] =
inl(dev->iobase +
APCI1564_COUNTER_REG(devpriv->mode_select_register - 1));
ul_Command1 =
inl(dev->iobase +
APCI1564_COUNTER_STATUS_REG(devpriv->mode_select_register - 1));
data[1] = (unsigned char) ((ul_Command1 >> 1) & 1);
data[2] = (unsigned char) ((ul_Command1 >> 2) & 1);
data[3] = (unsigned char) ((ul_Command1 >> 3) & 1);
data[4] = (unsigned char) ((ul_Command1 >> 0) & 1);
} else {
dev_err(dev->class_dev, "Invalid subdevice.\n");
}
return insn->n;
}
