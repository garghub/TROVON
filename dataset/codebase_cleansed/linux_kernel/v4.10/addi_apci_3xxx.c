static irqreturn_t apci3xxx_irq_handler(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int status;
unsigned int val;
status = readl(dev->mmio + 16);
if ((status & 0x2) == 0x2) {
writel(status, dev->mmio + 16);
val = readl(dev->mmio + 28);
comedi_buf_write_samples(s, &val, 1);
s->async->events |= COMEDI_CB_EOA;
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int apci3xxx_ai_started(struct comedi_device *dev)
{
if ((readl(dev->mmio + 8) & 0x80000) == 0x80000)
return 1;
return 0;
}
static int apci3xxx_ai_setup(struct comedi_device *dev, unsigned int chanspec)
{
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
unsigned int delay_mode;
unsigned int val;
if (apci3xxx_ai_started(dev))
return -EBUSY;
writel(0x10000, dev->mmio + 12);
delay_mode = readl(dev->mmio + 4);
delay_mode &= 0xfffffef0;
writel(delay_mode, dev->mmio + 4);
val = (range & 3) | ((range >> 2) << 6) |
((aref == AREF_DIFF) << 7);
writel(val, dev->mmio + 0);
writel(delay_mode | 0x100, dev->mmio + 4);
writel(chan, dev->mmio + 0);
writel(delay_mode, dev->mmio + 4);
writel(1, dev->mmio + 48);
return 0;
}
static int apci3xxx_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = readl(dev->mmio + 20);
if (status & 0x1)
return 0;
return -EBUSY;
}
static int apci3xxx_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
int i;
ret = apci3xxx_ai_setup(dev, insn->chanspec);
if (ret)
return ret;
for (i = 0; i < insn->n; i++) {
writel(0x80000, dev->mmio + 8);
ret = comedi_timeout(dev, s, insn, apci3xxx_ai_eoc, 0);
if (ret)
return ret;
data[i] = readl(dev->mmio + 28);
}
return insn->n;
}
static int apci3xxx_ai_ns_to_timer(struct comedi_device *dev,
unsigned int *ns, unsigned int flags)
{
const struct apci3xxx_boardinfo *board = dev->board_ptr;
struct apci3xxx_private *devpriv = dev->private;
unsigned int base;
unsigned int timer;
int time_base;
for (time_base = 0; time_base < 3; time_base++) {
if (!(board->ai_conv_units & (1 << time_base)))
continue;
switch (time_base) {
case 0:
base = 1;
break;
case 1:
base = 1000;
break;
case 2:
base = 1000000;
break;
}
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
timer = DIV_ROUND_CLOSEST(*ns, base);
break;
case CMDF_ROUND_DOWN:
timer = *ns / base;
break;
case CMDF_ROUND_UP:
timer = (*ns + base - 1) / base;
break;
}
if (timer < 0x10000) {
devpriv->ai_time_base = time_base;
devpriv->ai_timer = timer;
*ns = timer * time_base;
return 0;
}
}
return -EINVAL;
}
static int apci3xxx_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct apci3xxx_boardinfo *board = dev->board_ptr;
int err = 0;
unsigned int arg;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= comedi_check_trigger_arg_min(&cmd->convert_arg,
board->ai_min_acq_ns);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
arg = cmd->convert_arg;
err |= apci3xxx_ai_ns_to_timer(dev, &arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
if (err)
return 4;
return 0;
}
static int apci3xxx_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct apci3xxx_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int ret;
ret = apci3xxx_ai_setup(dev, cmd->chanlist[0]);
if (ret)
return ret;
writel(devpriv->ai_time_base, dev->mmio + 36);
writel(devpriv->ai_timer, dev->mmio + 32);
writel(0x180000, dev->mmio + 8);
return 0;
}
static int apci3xxx_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
return 0;
}
static int apci3xxx_ao_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = readl(dev->mmio + 96);
if (status & 0x100)
return 0;
return -EBUSY;
}
static int apci3xxx_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
int ret;
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
writel(range, dev->mmio + 96);
writel((val << 8) | chan, dev->mmio + 100);
ret = comedi_timeout(dev, s, insn, apci3xxx_ao_eoc, 0);
if (ret)
return ret;
s->readback[chan] = val;
}
return insn->n;
}
static int apci3xxx_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inl(dev->iobase + 32) & 0xf;
return insn->n;
}
static int apci3xxx_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
s->state = inl(dev->iobase + 48) & 0xf;
if (comedi_dio_update_state(s, data))
outl(s->state, dev->iobase + 48);
data[1] = s->state;
return insn->n;
}
static int apci3xxx_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask = 0;
int ret;
if (data[0] != INSN_CONFIG_DIO_QUERY) {
if (chan < 16)
return -EINVAL;
mask = 0xff0000;
}
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
outl((s->io_bits >> 24) & 0xff, dev->iobase + 224);
return insn->n;
}
static int apci3xxx_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask;
unsigned int val;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (mask & 0xff)
outl(s->state & 0xff, dev->iobase + 80);
if (mask & 0xff0000)
outl((s->state >> 16) & 0xff, dev->iobase + 112);
}
val = inl(dev->iobase + 80);
val |= (inl(dev->iobase + 64) << 8);
if (s->io_bits & 0xff0000)
val |= (inl(dev->iobase + 112) << 16);
else
val |= (inl(dev->iobase + 96) << 16);
data[1] = val;
return insn->n;
}
static int apci3xxx_reset(struct comedi_device *dev)
{
unsigned int val;
int i;
disable_irq(dev->irq);
writel(0, dev->mmio + 8);
val = readl(dev->mmio + 16);
writel(val, dev->mmio + 16);
readl(dev->mmio + 20);
for (i = 0; i < 16; i++)
val = readl(dev->mmio + 28);
enable_irq(dev->irq);
return 0;
}
static int apci3xxx_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct apci3xxx_boardinfo *board = NULL;
struct apci3xxx_private *devpriv;
struct comedi_subdevice *s;
int n_subdevices;
int subdev;
int ret;
if (context < ARRAY_SIZE(apci3xxx_boardtypes))
board = &apci3xxx_boardtypes[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
dev->mmio = pci_ioremap_bar(pcidev, 3);
if (pcidev->irq > 0) {
ret = request_irq(pcidev->irq, apci3xxx_irq_handler,
IRQF_SHARED, dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
n_subdevices = (board->ai_n_chan ? 0 : 1) + board->has_ao +
board->has_dig_in + board->has_dig_out +
board->has_ttl_io;
ret = comedi_alloc_subdevices(dev, n_subdevices);
if (ret)
return ret;
subdev = 0;
if (board->ai_n_chan) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | board->ai_subdev_flags;
s->n_chan = board->ai_n_chan;
s->maxdata = board->ai_maxdata;
s->range_table = &apci3xxx_ai_range;
s->insn_read = apci3xxx_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 1;
s->do_cmdtest = apci3xxx_ai_cmdtest;
s->do_cmd = apci3xxx_ai_cmd;
s->cancel = apci3xxx_ai_cancel;
}
subdev++;
}
if (board->has_ao) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 4;
s->maxdata = 0x0fff;
s->range_table = &apci3xxx_ao_range;
s->insn_write = apci3xxx_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
subdev++;
}
if (board->has_dig_in) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci3xxx_di_insn_bits;
subdev++;
}
if (board->has_dig_out) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci3xxx_do_insn_bits;
subdev++;
}
if (board->has_ttl_io) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 24;
s->maxdata = 1;
s->io_bits = 0xff;
s->range_table = &range_digital;
s->insn_config = apci3xxx_dio_insn_config;
s->insn_bits = apci3xxx_dio_insn_bits;
subdev++;
}
apci3xxx_reset(dev);
return 0;
}
static void apci3xxx_detach(struct comedi_device *dev)
{
if (dev->iobase)
apci3xxx_reset(dev);
comedi_pci_detach(dev);
}
static int apci3xxx_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci3xxx_driver, id->driver_data);
}
