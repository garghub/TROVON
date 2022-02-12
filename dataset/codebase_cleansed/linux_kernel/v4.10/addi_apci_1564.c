static int apci1564_reset(struct comedi_device *dev)
{
struct apci1564_private *devpriv = dev->private;
outl(0x0, dev->iobase + APCI1564_DI_IRQ_REG);
inl(dev->iobase + APCI1564_DI_INT_STATUS_REG);
outl(0x0, dev->iobase + APCI1564_DI_INT_MODE1_REG);
outl(0x0, dev->iobase + APCI1564_DI_INT_MODE2_REG);
outl(0x0, dev->iobase + APCI1564_DO_REG);
outl(0x0, dev->iobase + APCI1564_DO_INT_CTRL_REG);
addi_watchdog_reset(dev->iobase + APCI1564_WDOG_IOBASE);
outl(0x0, devpriv->timer + ADDI_TCW_CTRL_REG);
outl(0x0, devpriv->timer + ADDI_TCW_RELOAD_REG);
if (devpriv->counters) {
unsigned long iobase = devpriv->counters + ADDI_TCW_CTRL_REG;
outl(0x0, iobase + APCI1564_COUNTER(0));
outl(0x0, iobase + APCI1564_COUNTER(1));
outl(0x0, iobase + APCI1564_COUNTER(2));
}
return 0;
}
static irqreturn_t apci1564_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct apci1564_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int status;
unsigned int ctrl;
unsigned int chan;
s->state &= ~APCI1564_EVENT_MASK;
status = inl(dev->iobase + APCI1564_DI_IRQ_REG);
if (status & APCI1564_DI_IRQ_ENA) {
s->state = inl(dev->iobase + APCI1564_DI_INT_STATUS_REG);
s->state &= APCI1564_DI_INT_MODE_MASK;
s->state |= APCI1564_EVENT_COS;
outl(status & ~APCI1564_DI_IRQ_ENA,
dev->iobase + APCI1564_DI_IRQ_REG);
outl(status, dev->iobase + APCI1564_DI_IRQ_REG);
}
status = inl(devpriv->timer + ADDI_TCW_IRQ_REG);
if (status & ADDI_TCW_IRQ) {
s->state |= APCI1564_EVENT_TIMER;
ctrl = inl(devpriv->timer + ADDI_TCW_CTRL_REG);
outl(0x0, devpriv->timer + ADDI_TCW_CTRL_REG);
outl(ctrl, devpriv->timer + ADDI_TCW_CTRL_REG);
}
if (devpriv->counters) {
for (chan = 0; chan < 3; chan++) {
unsigned long iobase;
iobase = devpriv->counters + APCI1564_COUNTER(chan);
status = inl(iobase + ADDI_TCW_IRQ_REG);
if (status & ADDI_TCW_IRQ) {
s->state |= APCI1564_EVENT_COUNTER(chan);
ctrl = inl(iobase + ADDI_TCW_CTRL_REG);
outl(0x0, iobase + ADDI_TCW_CTRL_REG);
outl(ctrl, iobase + ADDI_TCW_CTRL_REG);
}
}
}
if (s->state & APCI1564_EVENT_MASK) {
comedi_buf_write_samples(s, &s->state, 1);
comedi_handle_events(dev, s);
}
return IRQ_HANDLED;
}
static int apci1564_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inl(dev->iobase + APCI1564_DI_REG);
return insn->n;
}
static int apci1564_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
s->state = inl(dev->iobase + APCI1564_DO_REG);
if (comedi_dio_update_state(s, data))
outl(s->state, dev->iobase + APCI1564_DO_REG);
data[1] = s->state;
return insn->n;
}
static int apci1564_diag_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inl(dev->iobase + APCI1564_DO_INT_STATUS_REG) & 3;
return insn->n;
}
static int apci1564_cos_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int shift, oldmask;
switch (data[0]) {
case INSN_CONFIG_DIGITAL_TRIG:
if (data[1] != 0)
return -EINVAL;
shift = data[3];
oldmask = (1U << shift) - 1;
switch (data[2]) {
case COMEDI_DIGITAL_TRIG_DISABLE:
devpriv->ctrl = 0;
devpriv->mode1 = 0;
devpriv->mode2 = 0;
outl(0x0, dev->iobase + APCI1564_DI_IRQ_REG);
inl(dev->iobase + APCI1564_DI_INT_STATUS_REG);
outl(0x0, dev->iobase + APCI1564_DI_INT_MODE1_REG);
outl(0x0, dev->iobase + APCI1564_DI_INT_MODE2_REG);
break;
case COMEDI_DIGITAL_TRIG_ENABLE_EDGES:
if (devpriv->ctrl != APCI1564_DI_IRQ_ENA) {
devpriv->ctrl = APCI1564_DI_IRQ_ENA;
devpriv->mode1 = 0;
devpriv->mode2 = 0;
} else {
devpriv->mode1 &= oldmask;
devpriv->mode2 &= oldmask;
}
devpriv->mode1 |= data[4] << shift;
devpriv->mode2 |= data[5] << shift;
break;
case COMEDI_DIGITAL_TRIG_ENABLE_LEVELS:
if (devpriv->ctrl != (APCI1564_DI_IRQ_ENA |
APCI1564_DI_IRQ_MODE)) {
devpriv->ctrl = APCI1564_DI_IRQ_ENA |
APCI1564_DI_IRQ_MODE;
devpriv->mode1 = 0;
devpriv->mode2 = 0;
} else {
devpriv->mode1 &= oldmask;
devpriv->mode2 &= oldmask;
}
devpriv->mode1 |= data[4] << shift;
devpriv->mode2 |= data[5] << shift;
break;
default:
return -EINVAL;
}
devpriv->mode1 &= APCI1564_DI_INT_MODE_MASK;
devpriv->mode2 &= APCI1564_DI_INT_MODE_MASK;
break;
default:
return -EINVAL;
}
return insn->n;
}
static int apci1564_cos_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = s->state;
return 0;
}
static int apci1564_cos_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
return 0;
}
static int apci1564_cos_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct apci1564_private *devpriv = dev->private;
if (!devpriv->ctrl && !(devpriv->mode1 || devpriv->mode2)) {
dev_warn(dev->class_dev,
"Interrupts disabled due to mode configuration!\n");
return -EINVAL;
}
outl(devpriv->mode1, dev->iobase + APCI1564_DI_INT_MODE1_REG);
outl(devpriv->mode2, dev->iobase + APCI1564_DI_INT_MODE2_REG);
outl(devpriv->ctrl, dev->iobase + APCI1564_DI_IRQ_REG);
return 0;
}
static int apci1564_cos_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
outl(0x0, dev->iobase + APCI1564_DI_IRQ_REG);
inl(dev->iobase + APCI1564_DI_INT_STATUS_REG);
outl(0x0, dev->iobase + APCI1564_DI_INT_MODE1_REG);
outl(0x0, dev->iobase + APCI1564_DI_INT_MODE2_REG);
return 0;
}
static int apci1564_timer_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
unsigned int val;
switch (data[0]) {
case INSN_CONFIG_ARM:
if (data[1] > s->maxdata)
return -EINVAL;
outl(data[1], devpriv->timer + ADDI_TCW_RELOAD_REG);
outl(ADDI_TCW_CTRL_IRQ_ENA | ADDI_TCW_CTRL_TIMER_ENA,
devpriv->timer + ADDI_TCW_CTRL_REG);
break;
case INSN_CONFIG_DISARM:
outl(0x0, devpriv->timer + ADDI_TCW_CTRL_REG);
break;
case INSN_CONFIG_GET_COUNTER_STATUS:
data[1] = 0;
val = inl(devpriv->timer + ADDI_TCW_CTRL_REG);
if (val & ADDI_TCW_CTRL_IRQ_ENA)
data[1] |= COMEDI_COUNTER_ARMED;
if (val & ADDI_TCW_CTRL_TIMER_ENA)
data[1] |= COMEDI_COUNTER_COUNTING;
val = inl(devpriv->timer + ADDI_TCW_STATUS_REG);
if (val & ADDI_TCW_STATUS_OVERFLOW)
data[1] |= COMEDI_COUNTER_TERMINAL_COUNT;
data[2] = COMEDI_COUNTER_ARMED | COMEDI_COUNTER_COUNTING |
COMEDI_COUNTER_TERMINAL_COUNT;
break;
case INSN_CONFIG_SET_CLOCK_SRC:
if (data[2] > s->maxdata)
return -EINVAL;
outl(data[1], devpriv->timer + ADDI_TCW_TIMEBASE_REG);
outl(data[2], devpriv->timer + ADDI_TCW_RELOAD_REG);
break;
case INSN_CONFIG_GET_CLOCK_SRC:
data[1] = inl(devpriv->timer + ADDI_TCW_TIMEBASE_REG);
data[2] = inl(devpriv->timer + ADDI_TCW_RELOAD_REG);
break;
default:
return -EINVAL;
}
return insn->n;
}
static int apci1564_timer_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
if (insn->n) {
unsigned int val = data[insn->n - 1];
outl(val, devpriv->timer + ADDI_TCW_RELOAD_REG);
}
return insn->n;
}
static int apci1564_timer_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct apci1564_private *devpriv = dev->private;
int i;
for (i = 0; i < insn->n; i++)
data[i] = inl(devpriv->timer + ADDI_TCW_VAL_REG);
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
unsigned int val;
switch (data[0]) {
case INSN_CONFIG_ARM:
val = inl(iobase + ADDI_TCW_CTRL_REG);
val |= ADDI_TCW_CTRL_IRQ_ENA | ADDI_TCW_CTRL_CNTR_ENA;
outl(data[1], iobase + ADDI_TCW_RELOAD_REG);
outl(val, iobase + ADDI_TCW_CTRL_REG);
break;
case INSN_CONFIG_DISARM:
val = inl(iobase + ADDI_TCW_CTRL_REG);
val &= ~(ADDI_TCW_CTRL_IRQ_ENA | ADDI_TCW_CTRL_CNTR_ENA);
outl(val, iobase + ADDI_TCW_CTRL_REG);
break;
case INSN_CONFIG_SET_COUNTER_MODE:
outl(data[1], iobase + ADDI_TCW_CTRL_REG);
break;
case INSN_CONFIG_GET_COUNTER_STATUS:
data[1] = 0;
val = inl(iobase + ADDI_TCW_CTRL_REG);
if (val & ADDI_TCW_CTRL_IRQ_ENA)
data[1] |= COMEDI_COUNTER_ARMED;
if (val & ADDI_TCW_CTRL_CNTR_ENA)
data[1] |= COMEDI_COUNTER_COUNTING;
val = inl(iobase + ADDI_TCW_STATUS_REG);
if (val & ADDI_TCW_STATUS_OVERFLOW)
data[1] |= COMEDI_COUNTER_TERMINAL_COUNT;
data[2] = COMEDI_COUNTER_ARMED | COMEDI_COUNTER_COUNTING |
COMEDI_COUNTER_TERMINAL_COUNT;
break;
default:
return -EINVAL;
}
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
if (insn->n) {
unsigned int val = data[insn->n - 1];
outl(val, iobase + ADDI_TCW_RELOAD_REG);
}
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
int i;
for (i = 0; i < insn->n; i++)
data[i] = inl(iobase + ADDI_TCW_VAL_REG);
return insn->n;
}
static int apci1564_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct apci1564_private *devpriv;
struct comedi_subdevice *s;
unsigned int val;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv->eeprom = pci_resource_start(pcidev, 0);
val = inl(devpriv->eeprom + APCI1564_EEPROM_REG);
if (APCI1564_EEPROM_TO_REV(val) == 0) {
dev->iobase = pci_resource_start(pcidev, 1) +
APCI1564_REV1_MAIN_IOBASE;
devpriv->timer = devpriv->eeprom + APCI1564_REV1_TIMER_IOBASE;
} else {
dev->iobase = devpriv->eeprom + APCI1564_REV2_MAIN_IOBASE;
devpriv->timer = devpriv->eeprom + APCI1564_REV2_TIMER_IOBASE;
devpriv->counters = pci_resource_start(pcidev, 1);
}
apci1564_reset(dev);
if (pcidev->irq > 0) {
ret = request_irq(pcidev->irq, apci1564_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
ret = comedi_alloc_subdevices(dev, 7);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 32;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci1564_di_insn_bits;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 32;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci1564_do_insn_bits;
s = &dev->subdevices[2];
if (dev->irq) {
dev->read_subdev = s;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ | SDF_LSAMPL;
s->n_chan = 1;
s->maxdata = 1;
s->range_table = &range_digital;
s->len_chanlist = 1;
s->insn_config = apci1564_cos_insn_config;
s->insn_bits = apci1564_cos_insn_bits;
s->do_cmdtest = apci1564_cos_cmdtest;
s->do_cmd = apci1564_cos_cmd;
s->cancel = apci1564_cos_cancel;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_TIMER;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 1;
s->maxdata = 0x0fff;
s->range_table = &range_digital;
s->insn_config = apci1564_timer_insn_config;
s->insn_write = apci1564_timer_insn_write;
s->insn_read = apci1564_timer_insn_read;
s = &dev->subdevices[4];
if (devpriv->counters) {
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE | SDF_LSAMPL;
s->n_chan = 3;
s->maxdata = 0xffffffff;
s->range_table = &range_digital;
s->insn_config = apci1564_counter_insn_config;
s->insn_write = apci1564_counter_insn_write;
s->insn_read = apci1564_counter_insn_read;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[5];
ret = addi_watchdog_init(s, dev->iobase + APCI1564_WDOG_IOBASE);
if (ret)
return ret;
s = &dev->subdevices[6];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 2;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci1564_diag_insn_bits;
return 0;
}
static void apci1564_detach(struct comedi_device *dev)
{
if (dev->iobase)
apci1564_reset(dev);
comedi_pci_detach(dev);
}
static int apci1564_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci1564_driver, id->driver_data);
}
