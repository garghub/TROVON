static int apci2200_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
data[1] = inw(devpriv->iobase + APCI2200_DIGITAL_IP);
return insn->n;
}
static int apci2200_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int mask = data[0];
unsigned int bits = data[1];
s->state = inw(devpriv->iobase + APCI2200_DIGITAL_OP);
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
outw(s->state, devpriv->iobase + APCI2200_DIGITAL_OP);
}
data[1] = s->state;
return insn->n;
}
static int i_APCI2200_ConfigWatchdog(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
if (data[0] == 0) {
outw(0x0,
devpriv->iobase + APCI2200_WATCHDOG +
APCI2200_WATCHDOG_ENABLEDISABLE);
outw(data[1],
devpriv->iobase + APCI2200_WATCHDOG +
APCI2200_WATCHDOG_RELOAD_VALUE);
data[1] = data[1] >> 16;
outw(data[1],
devpriv->iobase + APCI2200_WATCHDOG +
APCI2200_WATCHDOG_RELOAD_VALUE + 2);
}
else {
printk("\nThe input parameters are wrong\n");
return -EINVAL;
}
return insn->n;
}
static int i_APCI2200_StartStopWriteWatchdog(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
switch (data[0]) {
case 0:
outw(0x0, devpriv->iobase + APCI2200_WATCHDOG + APCI2200_WATCHDOG_ENABLEDISABLE);
break;
case 1:
outw(0x0001,
devpriv->iobase + APCI2200_WATCHDOG +
APCI2200_WATCHDOG_ENABLEDISABLE);
break;
case 2:
outw(0x0201,
devpriv->iobase + APCI2200_WATCHDOG +
APCI2200_WATCHDOG_ENABLEDISABLE);
break;
default:
printk("\nSpecified functionality does not exist\n");
return -EINVAL;
}
return insn->n;
}
static int i_APCI2200_ReadWatchdog(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
data[0] =
inw(devpriv->iobase + APCI2200_WATCHDOG +
APCI2200_WATCHDOG_STATUS) & 0x1;
return insn->n;
}
static int i_APCI2200_Reset(struct comedi_device *dev)
{
struct addi_private *devpriv = dev->private;
outw(0x0, devpriv->iobase + APCI2200_DIGITAL_OP);
outw(0x0,
devpriv->iobase + APCI2200_WATCHDOG +
APCI2200_WATCHDOG_ENABLEDISABLE);
outw(0x0,
devpriv->iobase + APCI2200_WATCHDOG +
APCI2200_WATCHDOG_RELOAD_VALUE);
outw(0x0,
devpriv->iobase + APCI2200_WATCHDOG +
APCI2200_WATCHDOG_RELOAD_VALUE + 2);
return 0;
}
