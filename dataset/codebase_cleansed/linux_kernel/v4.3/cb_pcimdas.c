static int cb_pcimdas_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int status;
status = inb(devpriv->BADR3 + PCIMDAS_STATUS_REG);
if ((status & PCIMDAS_STATUS_EOC) == 0)
return 0;
return -EBUSY;
}
static int cb_pcimdas_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
int n;
unsigned int d;
int ret;
d = inb(devpriv->BADR3 + PCIMDAS_PACER_REG);
if ((d & PCIMDAS_PACER_SRC_MASK) != PCIMDAS_PACER_SRC_POLLED) {
d &= ~PCIMDAS_PACER_SRC_MASK;
d |= PCIMDAS_PACER_SRC_POLLED;
outb(d, devpriv->BADR3 + PCIMDAS_PACER_REG);
}
outb(PCIMDAS_BURST_CONV_EN, devpriv->BADR3 + PCIMDAS_BURST_REG);
outb(range, devpriv->BADR3 + PCIMDAS_GAIN_REG);
outb(PCIMDAS_MUX(chan, chan), devpriv->BADR3 + PCIMDAS_MUX_REG);
for (n = 0; n < insn->n; n++) {
outw(0, devpriv->daqio + PCIMDAS_AI_SOFTTRIG_REG);
ret = comedi_timeout(dev, s, insn, cb_pcimdas_ai_eoc, 0);
if (ret)
return ret;
data[n] = inw(devpriv->daqio + PCIMDAS_AI_REG);
}
return n;
}
static int cb_pcimdas_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, devpriv->daqio + PCIMDAS_AO_REG(chan));
}
s->readback[chan] = val;
return insn->n;
}
static int cb_pcimdas_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int val;
val = inb(devpriv->BADR3 + PCIMDAS_DI_DO_REG);
data[1] = val & 0x0f;
return insn->n;
}
static int cb_pcimdas_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
if (comedi_dio_update_state(s, data))
outb(s->state, devpriv->BADR3 + PCIMDAS_DI_DO_REG);
data[1] = s->state;
return insn->n;
}
static int cb_pcimdas_counter_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int ctrl;
switch (data[0]) {
case INSN_CONFIG_SET_CLOCK_SRC:
switch (data[1]) {
case 0:
ctrl = PCIMDAS_USER_CNTR_CTR1_CLK_SEL;
break;
case 1:
ctrl = 0;
break;
default:
return -EINVAL;
}
outb(ctrl, devpriv->BADR3 + PCIMDAS_USER_CNTR_REG);
break;
case INSN_CONFIG_GET_CLOCK_SRC:
ctrl = inb(devpriv->BADR3 + PCIMDAS_USER_CNTR_REG);
if (ctrl & PCIMDAS_USER_CNTR_CTR1_CLK_SEL) {
data[1] = 0;
data[2] = I8254_OSC_BASE_100KHZ;
} else {
data[1] = 1;
data[2] = 0;
}
break;
default:
return -EINVAL;
}
return insn->n;
}
static unsigned int cb_pcimdas_pacer_clk(struct comedi_device *dev)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int status;
status = inb(devpriv->BADR3 + PCIMDAS_STATUS_REG);
if (status & PCIMDAS_STATUS_CLK)
return I8254_OSC_BASE_10MHZ;
return I8254_OSC_BASE_1MHZ;
}
static bool cb_pcimdas_is_ai_se(struct comedi_device *dev)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int status;
status = inb(devpriv->BADR3 + PCIMDAS_STATUS_REG);
return status & PCIMDAS_STATUS_MUX;
}
static bool cb_pcimdas_is_ai_uni(struct comedi_device *dev)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int status;
status = inb(devpriv->BADR3 + PCIMDAS_STATUS_REG);
return status & PCIMDAS_STATUS_UB;
}
static int cb_pcimdas_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct cb_pcimdas_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv->daqio = pci_resource_start(pcidev, 2);
devpriv->BADR3 = pci_resource_start(pcidev, 3);
dev->iobase = pci_resource_start(pcidev, 4);
dev->pacer = comedi_8254_init(devpriv->BADR3 + PCIMDAS_8254_BASE,
cb_pcimdas_pacer_clk(dev),
I8254_IO8, 0);
if (!dev->pacer)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 6);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE;
if (cb_pcimdas_is_ai_se(dev)) {
s->subdev_flags |= SDF_GROUND;
s->n_chan = 16;
} else {
s->subdev_flags |= SDF_DIFF;
s->n_chan = 8;
}
s->maxdata = 0xffff;
s->range_table = cb_pcimdas_is_ai_uni(dev) ? &cb_pcimdas_ai_uni_range
: &cb_pcimdas_ai_bip_range;
s->insn_read = cb_pcimdas_ai_insn_read;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0xfff;
s->range_table = &cb_pcimdas_ao_range;
s->insn_write = cb_pcimdas_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
ret = subdev_8255_init(dev, s, NULL, PCIMDAS_8255_BASE);
if (ret)
return ret;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = cb_pcimdas_di_insn_bits;
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = cb_pcimdas_do_insn_bits;
s = &dev->subdevices[5];
comedi_8254_subdevice_init(s, dev->pacer);
dev->pacer->insn_config = cb_pcimdas_counter_insn_config;
comedi_8254_set_busy(dev->pacer, 1, true);
comedi_8254_set_busy(dev->pacer, 2, true);
return 0;
}
static int cb_pcimdas_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &cb_pcimdas_driver,
id->driver_data);
}
