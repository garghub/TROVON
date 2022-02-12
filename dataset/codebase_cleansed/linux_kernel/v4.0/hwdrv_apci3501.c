static int apci3501_config_insn_timer(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci3501_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
devpriv->tsk_Current = current;
if (data[0] == ADDIDATA_WATCHDOG) {
devpriv->b_TimerSelectMode = ADDIDATA_WATCHDOG;
outl(0x0, dev->iobase + APCI3501_TIMER_CTRL_REG);
if (data[1] == 1) {
outl(0x02, dev->iobase + APCI3501_TIMER_CTRL_REG);
} else {
outl(0x0, dev->iobase + APCI3501_TIMER_CTRL_REG);
}
outl(data[2], dev->iobase + APCI3501_TIMER_TIMEBASE_REG);
outl(data[3], dev->iobase + APCI3501_TIMER_RELOAD_REG);
ul_Command1 = inl(dev->iobase + APCI3501_TIMER_CTRL_REG) | 0xFFF819E0UL;
outl(ul_Command1, dev->iobase + APCI3501_TIMER_CTRL_REG);
}
else if (data[0] == ADDIDATA_TIMER) {
ul_Command1 = inl(dev->iobase + APCI3501_TIMER_CTRL_REG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1, dev->iobase + APCI3501_TIMER_CTRL_REG);
devpriv->b_TimerSelectMode = ADDIDATA_TIMER;
if (data[1] == 1) {
outl(0x02, dev->iobase + APCI3501_TIMER_CTRL_REG);
} else {
outl(0x0, dev->iobase + APCI3501_TIMER_CTRL_REG);
}
outl(data[2], dev->iobase + APCI3501_TIMER_TIMEBASE_REG);
outl(data[3], dev->iobase + APCI3501_TIMER_RELOAD_REG);
ul_Command1 = inl(dev->iobase + APCI3501_TIMER_CTRL_REG);
ul_Command1 =
(ul_Command1 & 0xFFF719E2UL) | 2UL << 13UL | 0x10UL;
outl(ul_Command1, dev->iobase + APCI3501_TIMER_CTRL_REG);
}
return insn->n;
}
static int apci3501_write_insn_timer(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci3501_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
if (devpriv->b_TimerSelectMode == ADDIDATA_WATCHDOG) {
if (data[1] == 1) {
ul_Command1 = inl(dev->iobase + APCI3501_TIMER_CTRL_REG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x1UL;
outl(ul_Command1, dev->iobase + APCI3501_TIMER_CTRL_REG);
} else if (data[1] == 0) {
ul_Command1 = inl(dev->iobase + APCI3501_TIMER_CTRL_REG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(0x0, dev->iobase + APCI3501_TIMER_CTRL_REG);
} else if (data[1] == 2) {
ul_Command1 = inl(dev->iobase + APCI3501_TIMER_CTRL_REG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x200UL;
outl(ul_Command1, dev->iobase + APCI3501_TIMER_CTRL_REG);
}
}
if (devpriv->b_TimerSelectMode == ADDIDATA_TIMER) {
if (data[1] == 1) {
ul_Command1 = inl(dev->iobase + APCI3501_TIMER_CTRL_REG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x1UL;
outl(ul_Command1, dev->iobase + APCI3501_TIMER_CTRL_REG);
} else if (data[1] == 0) {
ul_Command1 = inl(dev->iobase + APCI3501_TIMER_CTRL_REG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1, dev->iobase + APCI3501_TIMER_CTRL_REG);
}
else if (data[1] == 2) {
ul_Command1 = inl(dev->iobase + APCI3501_TIMER_CTRL_REG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x200UL;
outl(ul_Command1, dev->iobase + APCI3501_TIMER_CTRL_REG);
}
}
inl(dev->iobase + APCI3501_TIMER_STATUS_REG);
return insn->n;
}
static int apci3501_read_insn_timer(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci3501_private *devpriv = dev->private;
if (devpriv->b_TimerSelectMode == ADDIDATA_WATCHDOG) {
data[0] = inl(dev->iobase + APCI3501_TIMER_STATUS_REG) & 0x1;
data[1] = inl(dev->iobase + APCI3501_TIMER_SYNC_REG);
}
else if (devpriv->b_TimerSelectMode == ADDIDATA_TIMER) {
data[0] = inl(dev->iobase + APCI3501_TIMER_STATUS_REG) & 0x1;
data[1] = inl(dev->iobase + APCI3501_TIMER_SYNC_REG);
}
else if ((devpriv->b_TimerSelectMode != ADDIDATA_TIMER)
&& (devpriv->b_TimerSelectMode != ADDIDATA_WATCHDOG)) {
dev_err(dev->class_dev, "Invalid subdevice.\n");
}
return insn->n;
}
