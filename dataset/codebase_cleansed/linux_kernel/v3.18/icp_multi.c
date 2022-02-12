static void setup_channel_list(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int *chanlist, unsigned int n_chan)
{
struct icp_multi_private *devpriv = dev->private;
unsigned int i, range, chanprog;
unsigned int diff;
devpriv->act_chanlist_len = n_chan;
devpriv->act_chanlist_pos = 0;
for (i = 0; i < n_chan; i++) {
chanprog = CR_CHAN(chanlist[i]);
if (CR_AREF(chanlist[i]) == AREF_DIFF) {
diff = 1;
chanprog &= 0x0007;
} else {
diff = 0;
chanprog &= 0x000f;
}
devpriv->AdcCmdStatus &= 0xf00f;
if (diff) {
devpriv->AdcCmdStatus |= (chanprog << 9);
devpriv->AdcCmdStatus |= ADC_DI;
} else
devpriv->AdcCmdStatus |= (chanprog << 8);
range = range_codes_analog[CR_RANGE(chanlist[i])];
devpriv->AdcCmdStatus |= range;
writew(devpriv->AdcCmdStatus, dev->mmio + ICP_MULTI_ADC_CSR);
}
}
static int icp_multi_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = readw(dev->mmio + ICP_MULTI_ADC_CSR);
if ((status & ADC_BSY) == 0)
return 0;
return -EBUSY;
}
static int icp_multi_insn_read_ai(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct icp_multi_private *devpriv = dev->private;
int ret = 0;
int n;
devpriv->IntEnable &= ~ADC_READY;
writew(devpriv->IntEnable, dev->mmio + ICP_MULTI_INT_EN);
devpriv->IntStatus |= ADC_READY;
writew(devpriv->IntStatus, dev->mmio + ICP_MULTI_INT_STAT);
setup_channel_list(dev, s, &insn->chanspec, 1);
for (n = 0; n < insn->n; n++) {
devpriv->AdcCmdStatus |= ADC_ST;
writew(devpriv->AdcCmdStatus, dev->mmio + ICP_MULTI_ADC_CSR);
devpriv->AdcCmdStatus &= ~ADC_ST;
udelay(1);
ret = comedi_timeout(dev, s, insn, icp_multi_ai_eoc, 0);
if (ret)
break;
data[n] = (readw(dev->mmio + ICP_MULTI_AI) >> 4) & 0x0fff;
}
devpriv->IntEnable &= ~ADC_READY;
writew(devpriv->IntEnable, dev->mmio + ICP_MULTI_INT_EN);
devpriv->IntStatus |= ADC_READY;
writew(devpriv->IntStatus, dev->mmio + ICP_MULTI_INT_STAT);
return ret ? ret : n;
}
static int icp_multi_ao_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = readw(dev->mmio + ICP_MULTI_DAC_CSR);
if ((status & DAC_BSY) == 0)
return 0;
return -EBUSY;
}
static int icp_multi_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct icp_multi_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
int i;
devpriv->IntEnable &= ~DAC_READY;
writew(devpriv->IntEnable, dev->mmio + ICP_MULTI_INT_EN);
devpriv->IntStatus |= DAC_READY;
writew(devpriv->IntStatus, dev->mmio + ICP_MULTI_INT_STAT);
devpriv->DacCmdStatus &= 0xfccf;
devpriv->DacCmdStatus |= range_codes_analog[range];
devpriv->DacCmdStatus |= (chan << 8);
writew(devpriv->DacCmdStatus, dev->mmio + ICP_MULTI_DAC_CSR);
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
int ret;
ret = comedi_timeout(dev, s, insn, icp_multi_ao_eoc, 0);
if (ret) {
devpriv->IntEnable &= ~DAC_READY;
writew(devpriv->IntEnable,
dev->mmio + ICP_MULTI_INT_EN);
devpriv->IntStatus |= DAC_READY;
writew(devpriv->IntStatus,
dev->mmio + ICP_MULTI_INT_STAT);
return ret;
}
writew(val, dev->mmio + ICP_MULTI_AO);
devpriv->DacCmdStatus |= DAC_ST;
writew(devpriv->DacCmdStatus, dev->mmio + ICP_MULTI_DAC_CSR);
devpriv->DacCmdStatus &= ~DAC_ST;
s->readback[chan] = val;
}
return insn->n;
}
static int icp_multi_insn_bits_di(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = readw(dev->mmio + ICP_MULTI_DI);
return insn->n;
}
static int icp_multi_insn_bits_do(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
writew(s->state, dev->mmio + ICP_MULTI_DO);
data[1] = readw(dev->mmio + ICP_MULTI_DI);
return insn->n;
}
static int icp_multi_insn_read_ctr(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
return 0;
}
static int icp_multi_insn_write_ctr(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
return 0;
}
static irqreturn_t interrupt_service_icp_multi(int irq, void *d)
{
struct comedi_device *dev = d;
int int_no;
int_no = readw(dev->mmio + ICP_MULTI_INT_STAT) & Status_IRQ;
if (!int_no)
return IRQ_NONE;
switch (int_no) {
case ADC_READY:
break;
case DAC_READY:
break;
case DOUT_ERROR:
break;
case DIN_STATUS:
break;
case CIE0:
break;
case CIE1:
break;
case CIE2:
break;
case CIE3:
break;
default:
break;
}
return IRQ_HANDLED;
}
static int icp_multi_reset(struct comedi_device *dev)
{
struct icp_multi_private *devpriv = dev->private;
unsigned int i;
writew(0, dev->mmio + ICP_MULTI_INT_EN);
writew(0x00ff, dev->mmio + ICP_MULTI_INT_STAT);
for (i = 0; i < 4; i++) {
devpriv->DacCmdStatus &= 0xfcce;
devpriv->DacCmdStatus |= (i << 8);
writew(0, dev->mmio + ICP_MULTI_AO);
devpriv->DacCmdStatus |= DAC_ST;
writew(devpriv->DacCmdStatus, dev->mmio + ICP_MULTI_DAC_CSR);
udelay(1);
}
writew(0, dev->mmio + ICP_MULTI_DO);
return 0;
}
static int icp_multi_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct icp_multi_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->mmio = pci_ioremap_bar(pcidev, 2);
if (!dev->mmio)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 5);
if (ret)
return ret;
icp_multi_reset(dev);
if (pcidev->irq) {
ret = request_irq(pcidev->irq, interrupt_service_icp_multi,
IRQF_SHARED, dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_COMMON | SDF_GROUND | SDF_DIFF;
s->n_chan = 16;
s->maxdata = 0x0fff;
s->len_chanlist = 16;
s->range_table = &range_analog;
s->insn_read = icp_multi_insn_read_ai;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 4;
s->maxdata = 0x0fff;
s->len_chanlist = 4;
s->range_table = &range_analog;
s->insn_write = icp_multi_ao_insn_write;
s->insn_read = comedi_readback_insn_read;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->len_chanlist = 16;
s->range_table = &range_digital;
s->insn_bits = icp_multi_insn_bits_di;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 8;
s->maxdata = 1;
s->len_chanlist = 8;
s->range_table = &range_digital;
s->insn_bits = icp_multi_insn_bits_do;
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 4;
s->maxdata = 0xffff;
s->len_chanlist = 4;
s->state = 0;
s->insn_read = icp_multi_insn_read_ctr;
s->insn_write = icp_multi_insn_write_ctr;
return 0;
}
static void icp_multi_detach(struct comedi_device *dev)
{
if (dev->mmio)
icp_multi_reset(dev);
comedi_pci_detach(dev);
}
static int icp_multi_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &icp_multi_driver, id->driver_data);
}
