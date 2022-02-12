static int dyna_pci10xx_insn_read_ai(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dyna_pci10xx_private *devpriv = dev->private;
int n, counter;
u16 d = 0;
unsigned int chan, range;
chan = CR_CHAN(insn->chanspec);
range = range_codes_pci1050_ai[CR_RANGE((insn->chanspec))];
mutex_lock(&devpriv->mutex);
for (n = 0; n < insn->n; n++) {
smp_mb();
outw_p(0x0000 + range + chan, dev->iobase + 2);
udelay(10);
for (counter = 0; counter < READ_TIMEOUT; counter++) {
d = inw_p(dev->iobase);
if (d & (1 << 15))
goto conv_finish;
}
data[n] = 0;
dev_dbg(dev->class_dev, "timeout reading analog input\n");
continue;
conv_finish:
d &= 0x0FFF;
data[n] = d;
}
mutex_unlock(&devpriv->mutex);
return n;
}
static int dyna_pci10xx_insn_write_ao(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dyna_pci10xx_private *devpriv = dev->private;
int n;
unsigned int chan, range;
chan = CR_CHAN(insn->chanspec);
range = range_codes_pci1050_ai[CR_RANGE((insn->chanspec))];
mutex_lock(&devpriv->mutex);
for (n = 0; n < insn->n; n++) {
smp_mb();
outw_p(data[n], dev->iobase);
udelay(10);
}
mutex_unlock(&devpriv->mutex);
return n;
}
static int dyna_pci10xx_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dyna_pci10xx_private *devpriv = dev->private;
u16 d = 0;
mutex_lock(&devpriv->mutex);
smp_mb();
d = inw_p(devpriv->BADR3);
udelay(10);
data[1] = d;
data[0] = s->state;
mutex_unlock(&devpriv->mutex);
return insn->n;
}
static int dyna_pci10xx_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct dyna_pci10xx_private *devpriv = dev->private;
mutex_lock(&devpriv->mutex);
if (comedi_dio_update_state(s, data)) {
smp_mb();
outw_p(s->state, devpriv->BADR3);
udelay(10);
}
data[1] = s->state;
mutex_unlock(&devpriv->mutex);
return insn->n;
}
static int dyna_pci10xx_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct dyna_pci10xx_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
devpriv->BADR3 = pci_resource_start(pcidev, 3);
mutex_init(&devpriv->mutex);
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 16;
s->maxdata = 0x0FFF;
s->range_table = &range_pci1050_ai;
s->len_chanlist = 16;
s->insn_read = dyna_pci10xx_insn_read_ai;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 0x0FFF;
s->range_table = &range_unipolar10;
s->len_chanlist = 16;
s->insn_write = dyna_pci10xx_insn_write_ao;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->len_chanlist = 16;
s->insn_bits = dyna_pci10xx_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->len_chanlist = 16;
s->state = 0;
s->insn_bits = dyna_pci10xx_do_insn_bits;
dev_info(dev->class_dev, "%s attached\n", dev->board_name);
return 0;
}
static void dyna_pci10xx_detach(struct comedi_device *dev)
{
struct dyna_pci10xx_private *devpriv = dev->private;
if (devpriv)
mutex_destroy(&devpriv->mutex);
comedi_pci_disable(dev);
}
static int dyna_pci10xx_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &dyna_pci10xx_driver,
id->driver_data);
}
