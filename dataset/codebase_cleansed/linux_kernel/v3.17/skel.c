static int skel_ns_to_timer(unsigned int *ns, unsigned int flags)
{
return *ns;
}
static int skel_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = 1;
if (status)
return 0;
return -EBUSY;
}
static int skel_ai_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct skel_board *thisboard = comedi_board(dev);
int n;
unsigned int d;
int ret;
for (n = 0; n < insn->n; n++) {
ret = comedi_timeout(dev, s, insn, skel_ai_eoc, 0);
if (ret)
return ret;
d = 0;
d ^= 1 << (thisboard->ai_bits - 1);
data[n] = d;
}
return n;
}
static int skel_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
#define MAX_SPEED 10000
#define MIN_SPEED 1000000000
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
MAX_SPEED);
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg,
MIN_SPEED);
} else {
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg, 9);
}
if (cmd->convert_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->convert_arg, MAX_SPEED);
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, MIN_SPEED);
} else {
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg, 9);
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_max(&cmd->stop_arg, 0x00ffffff);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
skel_ns_to_timer(&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
skel_ns_to_timer(&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->convert_arg * cmd->scan_end_arg;
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
arg);
}
}
if (err)
return 4;
return 0;
}
static int skel_ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct skel_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int skel_ao_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct skel_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int skel_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data)) {
}
return insn->n;
}
static int skel_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
return insn->n;
}
static int skel_common_attach(struct comedi_device *dev)
{
const struct skel_board *thisboard = comedi_board(dev);
struct comedi_subdevice *s;
int ret;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = thisboard->ai_chans;
s->maxdata = (1 << thisboard->ai_bits) - 1;
s->range_table = &range_bipolar10;
s->len_chanlist = 16;
s->insn_read = skel_ai_rinsn;
s->do_cmdtest = skel_ai_cmdtest;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 1;
s->maxdata = 0xffff;
s->range_table = &range_bipolar5;
s->insn_write = skel_ao_winsn;
s->insn_read = skel_ao_rinsn;
s = &dev->subdevices[2];
if (thisboard->have_dio) {
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = skel_dio_insn_bits;
s->insn_config = skel_dio_insn_config;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
return 0;
}
static int skel_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct skel_board *thisboard;
struct skel_private *devpriv;
thisboard = comedi_board(dev);
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
return skel_common_attach(dev);
}
static int skel_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct skel_board *thisboard = NULL;
struct skel_private *devpriv;
int ret;
if (!IS_ENABLED(CONFIG_COMEDI_PCI_DRIVERS))
return -EINVAL;
if (context < ARRAY_SIZE(skel_boards))
thisboard = &skel_boards[context];
if (!thisboard)
return -ENODEV;
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 0);
return skel_common_attach(dev);
}
static void skel_detach(struct comedi_device *dev)
{
const struct skel_board *thisboard = comedi_board(dev);
struct skel_private *devpriv = dev->private;
if (!thisboard || !devpriv)
return;
if (IS_ENABLED(CONFIG_COMEDI_PCI_DRIVERS) ) {
comedi_pci_disable(dev);
} else {
comedi_legacy_detach(dev);
}
}
static int skel_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &skel_driver, id->driver_data);
}
