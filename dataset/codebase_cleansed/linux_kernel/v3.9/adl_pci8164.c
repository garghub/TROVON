static void adl_pci8164_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data,
char *action, unsigned short offset)
{
int axis, axis_reg;
char axisname;
axis = CR_CHAN(insn->chanspec);
switch (axis) {
case 0:
axis_reg = PCI8164_AXIS_X;
axisname = 'X';
break;
case 1:
axis_reg = PCI8164_AXIS_Y;
axisname = 'Y';
break;
case 2:
axis_reg = PCI8164_AXIS_Z;
axisname = 'Z';
break;
case 3:
axis_reg = PCI8164_AXIS_U;
axisname = 'U';
break;
default:
axis_reg = PCI8164_AXIS_X;
axisname = 'X';
}
data[0] = inw(dev->iobase + axis_reg + offset);
dev_dbg(dev->class_dev,
"pci8164 %s read -> %04X:%04X on axis %c\n",
action, data[0], data[1], axisname);
}
static int adl_pci8164_insn_read_msts(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
adl_pci8164_insn_read(dev, s, insn, data, "MSTS", PCI8164_MSTS);
return 2;
}
static int adl_pci8164_insn_read_ssts(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
adl_pci8164_insn_read(dev, s, insn, data, "SSTS", PCI8164_SSTS);
return 2;
}
static int adl_pci8164_insn_read_buf0(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
adl_pci8164_insn_read(dev, s, insn, data, "BUF0", PCI8164_BUF0);
return 2;
}
static int adl_pci8164_insn_read_buf1(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
adl_pci8164_insn_read(dev, s, insn, data, "BUF1", PCI8164_BUF1);
return 2;
}
static void adl_pci8164_insn_out(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data,
char *action, unsigned short offset)
{
unsigned int axis, axis_reg;
char axisname;
axis = CR_CHAN(insn->chanspec);
switch (axis) {
case 0:
axis_reg = PCI8164_AXIS_X;
axisname = 'X';
break;
case 1:
axis_reg = PCI8164_AXIS_Y;
axisname = 'Y';
break;
case 2:
axis_reg = PCI8164_AXIS_Z;
axisname = 'Z';
break;
case 3:
axis_reg = PCI8164_AXIS_U;
axisname = 'U';
break;
default:
axis_reg = PCI8164_AXIS_X;
axisname = 'X';
}
outw(data[0], dev->iobase + axis_reg + offset);
dev_dbg(dev->class_dev,
"pci8164 %s write -> %04X:%04X on axis %c\n",
action, data[0], data[1], axisname);
}
static int adl_pci8164_insn_write_cmd(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
adl_pci8164_insn_out(dev, s, insn, data, "CMD", PCI8164_CMD);
return 2;
}
static int adl_pci8164_insn_write_otp(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
adl_pci8164_insn_out(dev, s, insn, data, "OTP", PCI8164_OTP);
return 2;
}
static int adl_pci8164_insn_write_buf0(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
adl_pci8164_insn_out(dev, s, insn, data, "BUF0", PCI8164_BUF0);
return 2;
}
static int adl_pci8164_insn_write_buf1(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
adl_pci8164_insn_out(dev, s, insn, data, "BUF1", PCI8164_BUF1);
return 2;
}
static int adl_pci8164_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
int ret;
dev->board_name = dev->driver->driver_name;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_PROC;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->len_chanlist = 4;
s->insn_read = adl_pci8164_insn_read_msts;
s->insn_write = adl_pci8164_insn_write_cmd;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_PROC;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->len_chanlist = 4;
s->insn_read = adl_pci8164_insn_read_ssts;
s->insn_write = adl_pci8164_insn_write_otp;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_PROC;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->len_chanlist = 4;
s->insn_read = adl_pci8164_insn_read_buf0;
s->insn_write = adl_pci8164_insn_write_buf0;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_PROC;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->len_chanlist = 4;
s->insn_read = adl_pci8164_insn_read_buf1;
s->insn_write = adl_pci8164_insn_write_buf1;
dev_info(dev->class_dev, "%s attached\n", dev->board_name);
return 0;
}
static void adl_pci8164_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int adl_pci8164_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adl_pci8164_driver);
}
