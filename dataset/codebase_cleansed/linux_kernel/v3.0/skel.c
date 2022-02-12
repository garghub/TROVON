static int skel_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
pr_info("comedi%d: skel: ", dev->minor);
dev->board_name = thisboard->name;
if (alloc_private(dev, sizeof(struct skel_private)) < 0)
return -ENOMEM;
if (alloc_subdevices(dev, 3) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = thisboard->ai_chans;
s->maxdata = (1 << thisboard->ai_bits) - 1;
s->range_table = &range_bipolar10;
s->len_chanlist = 16;
s->insn_read = skel_ai_rinsn;
s->do_cmdtest = skel_ai_cmdtest;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 1;
s->maxdata = 0xffff;
s->range_table = &range_bipolar5;
s->insn_write = skel_ao_winsn;
s->insn_read = skel_ao_rinsn;
s = dev->subdevices + 2;
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
pr_info("attached\n");
return 0;
}
static int skel_detach(struct comedi_device *dev)
{
pr_info("comedi%d: skel: remove\n", dev->minor);
return 0;
}
static int skel_ai_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n, i;
unsigned int d;
unsigned int status;
for (n = 0; n < insn->n; n++) {
#define TIMEOUT 100
for (i = 0; i < TIMEOUT; i++) {
status = 1;
if (status)
break;
}
if (i == TIMEOUT) {
pr_info("timeout\n");
return -ETIMEDOUT;
}
d = 0;
d ^= 1 << (thisboard->ai_bits - 1);
data[n] = d;
}
return n;
}
static int skel_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
tmp = cmd->start_src;
cmd->start_src &= TRIG_NOW;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_TIMER | TRIG_EXT;
if (!cmd->scan_begin_src || tmp != cmd->scan_begin_src)
err++;
tmp = cmd->convert_src;
cmd->convert_src &= TRIG_TIMER | TRIG_EXT;
if (!cmd->convert_src || tmp != cmd->convert_src)
err++;
tmp = cmd->scan_end_src;
cmd->scan_end_src &= TRIG_COUNT;
if (!cmd->scan_end_src || tmp != cmd->scan_end_src)
err++;
tmp = cmd->stop_src;
cmd->stop_src &= TRIG_COUNT | TRIG_NONE;
if (!cmd->stop_src || tmp != cmd->stop_src)
err++;
if (err)
return 1;
if (cmd->scan_begin_src != TRIG_TIMER &&
cmd->scan_begin_src != TRIG_EXT)
err++;
if (cmd->convert_src != TRIG_TIMER && cmd->convert_src != TRIG_EXT)
err++;
if (cmd->stop_src != TRIG_COUNT && cmd->stop_src != TRIG_NONE)
err++;
if (err)
return 2;
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
#define MAX_SPEED 10000
#define MIN_SPEED 1000000000
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->scan_begin_arg < MAX_SPEED) {
cmd->scan_begin_arg = MAX_SPEED;
err++;
}
if (cmd->scan_begin_arg > MIN_SPEED) {
cmd->scan_begin_arg = MIN_SPEED;
err++;
}
} else {
if (cmd->scan_begin_arg > 9) {
cmd->scan_begin_arg = 9;
err++;
}
}
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->convert_arg < MAX_SPEED) {
cmd->convert_arg = MAX_SPEED;
err++;
}
if (cmd->convert_arg > MIN_SPEED) {
cmd->convert_arg = MIN_SPEED;
err++;
}
} else {
if (cmd->convert_arg > 9) {
cmd->convert_arg = 9;
err++;
}
}
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
if (cmd->stop_src == TRIG_COUNT) {
if (cmd->stop_arg > 0x00ffffff) {
cmd->stop_arg = 0x00ffffff;
err++;
}
} else {
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
}
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
skel_ns_to_timer(&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
skel_ns_to_timer(&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
if (cmd->scan_begin_src == TRIG_TIMER &&
cmd->scan_begin_arg <
cmd->convert_arg * cmd->scan_end_arg) {
cmd->scan_begin_arg =
cmd->convert_arg * cmd->scan_end_arg;
err++;
}
}
if (err)
return 4;
return 0;
}
static int skel_ns_to_timer(unsigned int *ns, int round)
{
return *ns;
}
static int skel_ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
pr_info("skel_ao_winsn\n");
for (i = 0; i < insn->n; i++) {
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int skel_ao_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int skel_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
}
return 2;
}
static int skel_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= 1 << chan;
break;
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~(1 << chan);
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->io_bits & (1 << chan)) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
break;
}
return insn->n;
}
static int __devinit driver_skel_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, driver_skel.driver_name);
}
static void __devexit driver_skel_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_skel_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_skel);
if (retval < 0)
return retval;
driver_skel_pci_driver.name = (char *)driver_skel.driver_name;
return pci_register_driver(&driver_skel_pci_driver);
}
static void __exit driver_skel_cleanup_module(void)
{
pci_unregister_driver(&driver_skel_pci_driver);
comedi_driver_unregister(&driver_skel);
}
static int __init driver_skel_init_module(void)
{
return comedi_driver_register(&driver_skel);
}
static void __exit driver_skel_cleanup_module(void)
{
comedi_driver_unregister(&driver_skel);
}
