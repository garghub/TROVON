static int ni6527_di_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni6527_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
unsigned int interval;
if (insn->n != 2)
return -EINVAL;
if (data[0] != INSN_CONFIG_FILTER)
return -EINVAL;
if (data[1]) {
interval = (data[1] + 100) / 200;
data[1] = interval * 200;
if (interval != devpriv->filter_interval) {
writeb(interval & 0xff,
devpriv->mite->daq_io_addr + Filter_Interval(0));
writeb((interval >> 8) & 0xff,
devpriv->mite->daq_io_addr + Filter_Interval(1));
writeb((interval >> 16) & 0x0f,
devpriv->mite->daq_io_addr + Filter_Interval(2));
writeb(ClrInterval,
devpriv->mite->daq_io_addr + Clear_Register);
devpriv->filter_interval = interval;
}
devpriv->filter_enable |= 1 << chan;
} else {
devpriv->filter_enable &= ~(1 << chan);
}
writeb(devpriv->filter_enable,
devpriv->mite->daq_io_addr + Filter_Enable(0));
writeb(devpriv->filter_enable >> 8,
devpriv->mite->daq_io_addr + Filter_Enable(1));
writeb(devpriv->filter_enable >> 16,
devpriv->mite->daq_io_addr + Filter_Enable(2));
return 2;
}
static int ni6527_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni6527_private *devpriv = dev->private;
data[1] = readb(devpriv->mite->daq_io_addr + Port_Register(0));
data[1] |= readb(devpriv->mite->daq_io_addr + Port_Register(1)) << 8;
data[1] |= readb(devpriv->mite->daq_io_addr + Port_Register(2)) << 16;
return insn->n;
}
static int ni6527_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni6527_private *devpriv = dev->private;
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
if (data[0] & 0x0000ff) {
writeb((s->state ^ 0xff),
devpriv->mite->daq_io_addr + Port_Register(3));
}
if (data[0] & 0x00ff00) {
writeb((s->state >> 8) ^ 0xff,
devpriv->mite->daq_io_addr + Port_Register(4));
}
if (data[0] & 0xff0000) {
writeb((s->state >> 16) ^ 0xff,
devpriv->mite->daq_io_addr + Port_Register(5));
}
}
data[1] = s->state;
return insn->n;
}
static irqreturn_t ni6527_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct ni6527_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[2];
unsigned int status;
status = readb(devpriv->mite->daq_io_addr + Change_Status);
if ((status & MasterInterruptStatus) == 0)
return IRQ_NONE;
if ((status & EdgeStatus) == 0)
return IRQ_NONE;
writeb(ClrEdge | ClrOverflow,
devpriv->mite->daq_io_addr + Clear_Register);
comedi_buf_put(s->async, 0);
s->async->events |= COMEDI_CB_EOS;
comedi_event(dev, s);
return IRQ_HANDLED;
}
static int ni6527_intr_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_OTHER);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT);
if (err)
return 1;
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, 1);
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (err)
return 4;
return 0;
}
static int ni6527_intr_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni6527_private *devpriv = dev->private;
writeb(ClrEdge | ClrOverflow,
devpriv->mite->daq_io_addr + Clear_Register);
writeb(FallingEdgeIntEnable | RisingEdgeIntEnable |
MasterInterruptEnable | EdgeIntEnable,
devpriv->mite->daq_io_addr + Master_Interrupt_Control);
return 0;
}
static int ni6527_intr_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni6527_private *devpriv = dev->private;
writeb(0x00, devpriv->mite->daq_io_addr + Master_Interrupt_Control);
return 0;
}
static int ni6527_intr_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = 0;
return insn->n;
}
static int ni6527_intr_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni6527_private *devpriv = dev->private;
if (insn->n < 1)
return -EINVAL;
if (data[0] != INSN_CONFIG_CHANGE_NOTIFY)
return -EINVAL;
writeb(data[1],
devpriv->mite->daq_io_addr + Rising_Edge_Detection_Enable(0));
writeb(data[1] >> 8,
devpriv->mite->daq_io_addr + Rising_Edge_Detection_Enable(1));
writeb(data[1] >> 16,
devpriv->mite->daq_io_addr + Rising_Edge_Detection_Enable(2));
writeb(data[2],
devpriv->mite->daq_io_addr + Falling_Edge_Detection_Enable(0));
writeb(data[2] >> 8,
devpriv->mite->daq_io_addr + Falling_Edge_Detection_Enable(1));
writeb(data[2] >> 16,
devpriv->mite->daq_io_addr + Falling_Edge_Detection_Enable(2));
return 2;
}
static int ni6527_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct ni6527_board *board = NULL;
struct ni6527_private *devpriv;
struct comedi_subdevice *s;
int ret;
if (context < ARRAY_SIZE(ni6527_boards))
board = &ni6527_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
devpriv->mite = mite_alloc(pcidev);
if (!devpriv->mite)
return -ENOMEM;
ret = mite_setup(devpriv->mite);
if (ret < 0) {
dev_err(dev->class_dev, "error setting up mite\n");
return ret;
}
dev_info(dev->class_dev, "board: %s, ID=0x%02x\n", dev->board_name,
readb(devpriv->mite->daq_io_addr + ID_Register));
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 24;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_config = ni6527_di_insn_config;
s->insn_bits = ni6527_di_insn_bits;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 24;
s->range_table = &range_unknown;
s->maxdata = 1;
s->insn_bits = ni6527_do_insn_bits;
s = &dev->subdevices[2];
dev->read_subdev = s;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
s->n_chan = 1;
s->range_table = &range_unknown;
s->maxdata = 1;
s->do_cmdtest = ni6527_intr_cmdtest;
s->do_cmd = ni6527_intr_cmd;
s->cancel = ni6527_intr_cancel;
s->insn_bits = ni6527_intr_insn_bits;
s->insn_config = ni6527_intr_insn_config;
writeb(0x00, devpriv->mite->daq_io_addr + Filter_Enable(0));
writeb(0x00, devpriv->mite->daq_io_addr + Filter_Enable(1));
writeb(0x00, devpriv->mite->daq_io_addr + Filter_Enable(2));
writeb(ClrEdge | ClrOverflow | ClrFilter | ClrInterval,
devpriv->mite->daq_io_addr + Clear_Register);
writeb(0x00, devpriv->mite->daq_io_addr + Master_Interrupt_Control);
ret = request_irq(mite_irq(devpriv->mite), ni6527_interrupt,
IRQF_SHARED, DRIVER_NAME, dev);
if (ret < 0)
dev_warn(dev->class_dev, "irq not available\n");
else
dev->irq = mite_irq(devpriv->mite);
return 0;
}
static void ni6527_detach(struct comedi_device *dev)
{
struct ni6527_private *devpriv = dev->private;
if (devpriv && devpriv->mite && devpriv->mite->daq_io_addr)
writeb(0x00,
devpriv->mite->daq_io_addr + Master_Interrupt_Control);
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv && devpriv->mite) {
mite_unsetup(devpriv->mite);
mite_free(devpriv->mite);
}
comedi_pci_disable(dev);
}
static int ni6527_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &ni6527_driver, id->driver_data);
}
