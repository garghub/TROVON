static inline unsigned Port_Data(unsigned port)
{
return 0x40 + port * ni_65xx_port_offset;
}
static inline unsigned Port_Select(unsigned port)
{
return 0x41 + port * ni_65xx_port_offset;
}
static inline unsigned Rising_Edge_Detection_Enable(unsigned port)
{
return 0x42 + port * ni_65xx_port_offset;
}
static inline unsigned Falling_Edge_Detection_Enable(unsigned port)
{
return 0x43 + port * ni_65xx_port_offset;
}
static inline unsigned Filter_Enable(unsigned port)
{
return 0x44 + port * ni_65xx_port_offset;
}
static inline const struct ni_65xx_board *board(struct comedi_device *dev)
{
return dev->board_ptr;
}
static inline unsigned ni_65xx_port_by_channel(unsigned channel)
{
return channel / ni_65xx_channels_per_port;
}
static inline unsigned ni_65xx_total_num_ports(const struct ni_65xx_board
*board)
{
return board->num_dio_ports + board->num_di_ports + board->num_do_ports;
}
static inline struct ni_65xx_subdevice_private *sprivate(struct comedi_subdevice
*subdev)
{
return subdev->private;
}
static struct ni_65xx_subdevice_private *ni_65xx_alloc_subdevice_private(void)
{
struct ni_65xx_subdevice_private *subdev_private =
kzalloc(sizeof(struct ni_65xx_subdevice_private), GFP_KERNEL);
if (subdev_private == NULL)
return NULL;
return subdev_private;
}
static int ni_65xx_config_filter(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni_65xx_private *devpriv = dev->private;
const unsigned chan = CR_CHAN(insn->chanspec);
const unsigned port =
sprivate(s)->base_port + ni_65xx_port_by_channel(chan);
if (data[0] != INSN_CONFIG_FILTER)
return -EINVAL;
if (data[1]) {
static const unsigned filter_resolution_ns = 200;
static const unsigned max_filter_interval = 0xfffff;
unsigned interval =
(data[1] +
(filter_resolution_ns / 2)) / filter_resolution_ns;
if (interval > max_filter_interval)
interval = max_filter_interval;
data[1] = interval * filter_resolution_ns;
if (interval != devpriv->filter_interval) {
writeb(interval,
devpriv->mite->daq_io_addr +
Filter_Interval);
devpriv->filter_interval = interval;
}
devpriv->filter_enable[port] |=
1 << (chan % ni_65xx_channels_per_port);
} else {
devpriv->filter_enable[port] &=
~(1 << (chan % ni_65xx_channels_per_port));
}
writeb(devpriv->filter_enable[port],
devpriv->mite->daq_io_addr + Filter_Enable(port));
return 2;
}
static int ni_65xx_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni_65xx_private *devpriv = dev->private;
unsigned port;
if (insn->n < 1)
return -EINVAL;
port = sprivate(s)->base_port +
ni_65xx_port_by_channel(CR_CHAN(insn->chanspec));
switch (data[0]) {
case INSN_CONFIG_FILTER:
return ni_65xx_config_filter(dev, s, insn, data);
break;
case INSN_CONFIG_DIO_OUTPUT:
if (s->type != COMEDI_SUBD_DIO)
return -EINVAL;
devpriv->dio_direction[port] = COMEDI_OUTPUT;
writeb(0, devpriv->mite->daq_io_addr + Port_Select(port));
return 1;
break;
case INSN_CONFIG_DIO_INPUT:
if (s->type != COMEDI_SUBD_DIO)
return -EINVAL;
devpriv->dio_direction[port] = COMEDI_INPUT;
writeb(1, devpriv->mite->daq_io_addr + Port_Select(port));
return 1;
break;
case INSN_CONFIG_DIO_QUERY:
if (s->type != COMEDI_SUBD_DIO)
return -EINVAL;
data[1] = devpriv->dio_direction[port];
return insn->n;
break;
default:
break;
}
return -EINVAL;
}
static int ni_65xx_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni_65xx_private *devpriv = dev->private;
unsigned base_bitfield_channel;
const unsigned max_ports_per_bitfield = 5;
unsigned read_bits = 0;
unsigned j;
base_bitfield_channel = CR_CHAN(insn->chanspec);
for (j = 0; j < max_ports_per_bitfield; ++j) {
const unsigned port_offset =
ni_65xx_port_by_channel(base_bitfield_channel) + j;
const unsigned port =
sprivate(s)->base_port + port_offset;
unsigned base_port_channel;
unsigned port_mask, port_data, port_read_bits;
int bitshift;
if (port >= ni_65xx_total_num_ports(board(dev)))
break;
base_port_channel = port_offset * ni_65xx_channels_per_port;
port_mask = data[0];
port_data = data[1];
bitshift = base_port_channel - base_bitfield_channel;
if (bitshift >= 32 || bitshift <= -32)
break;
if (bitshift > 0) {
port_mask >>= bitshift;
port_data >>= bitshift;
} else {
port_mask <<= -bitshift;
port_data <<= -bitshift;
}
port_mask &= 0xff;
port_data &= 0xff;
if (port_mask) {
unsigned bits;
devpriv->output_bits[port] &= ~port_mask;
devpriv->output_bits[port] |=
port_data & port_mask;
bits = devpriv->output_bits[port];
if (board(dev)->invert_outputs)
bits = ~bits;
writeb(bits,
devpriv->mite->daq_io_addr +
Port_Data(port));
}
port_read_bits =
readb(devpriv->mite->daq_io_addr + Port_Data(port));
if (s->type == COMEDI_SUBD_DO && board(dev)->invert_outputs) {
port_read_bits ^= 0xFF;
}
if (bitshift > 0)
port_read_bits <<= bitshift;
else
port_read_bits >>= -bitshift;
read_bits |= port_read_bits;
}
data[1] = read_bits;
return insn->n;
}
static irqreturn_t ni_65xx_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct ni_65xx_private *devpriv = dev->private;
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
static int ni_65xx_intr_cmdtest(struct comedi_device *dev,
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
static int ni_65xx_intr_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_65xx_private *devpriv = dev->private;
writeb(ClrEdge | ClrOverflow,
devpriv->mite->daq_io_addr + Clear_Register);
writeb(FallingEdgeIntEnable | RisingEdgeIntEnable |
MasterInterruptEnable | EdgeIntEnable,
devpriv->mite->daq_io_addr + Master_Interrupt_Control);
return 0;
}
static int ni_65xx_intr_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_65xx_private *devpriv = dev->private;
writeb(0x00, devpriv->mite->daq_io_addr + Master_Interrupt_Control);
return 0;
}
static int ni_65xx_intr_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = 0;
return insn->n;
}
static int ni_65xx_intr_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_65xx_private *devpriv = dev->private;
if (insn->n < 1)
return -EINVAL;
if (data[0] != INSN_CONFIG_CHANGE_NOTIFY)
return -EINVAL;
writeb(data[1],
devpriv->mite->daq_io_addr +
Rising_Edge_Detection_Enable(0));
writeb(data[1] >> 8,
devpriv->mite->daq_io_addr +
Rising_Edge_Detection_Enable(0x10));
writeb(data[1] >> 16,
devpriv->mite->daq_io_addr +
Rising_Edge_Detection_Enable(0x20));
writeb(data[1] >> 24,
devpriv->mite->daq_io_addr +
Rising_Edge_Detection_Enable(0x30));
writeb(data[2],
devpriv->mite->daq_io_addr +
Falling_Edge_Detection_Enable(0));
writeb(data[2] >> 8,
devpriv->mite->daq_io_addr +
Falling_Edge_Detection_Enable(0x10));
writeb(data[2] >> 16,
devpriv->mite->daq_io_addr +
Falling_Edge_Detection_Enable(0x20));
writeb(data[2] >> 24,
devpriv->mite->daq_io_addr +
Falling_Edge_Detection_Enable(0x30));
return 2;
}
static const struct ni_65xx_board *
ni_65xx_find_boardinfo(struct pci_dev *pcidev)
{
unsigned int dev_id = pcidev->device;
unsigned int n;
for (n = 0; n < ARRAY_SIZE(ni_65xx_boards); n++) {
const struct ni_65xx_board *board = &ni_65xx_boards[n];
if (board->dev_id == dev_id)
return board;
}
return NULL;
}
static int ni_65xx_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct ni_65xx_private *devpriv;
struct comedi_subdevice *s;
unsigned i;
int ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
dev->board_ptr = ni_65xx_find_boardinfo(pcidev);
if (!dev->board_ptr)
return -ENODEV;
devpriv->mite = mite_alloc(pcidev);
if (!devpriv->mite)
return -ENOMEM;
ret = mite_setup(devpriv->mite);
if (ret < 0) {
dev_warn(dev->class_dev, "error setting up mite\n");
return ret;
}
dev->board_name = board(dev)->name;
dev->irq = mite_irq(devpriv->mite);
dev_info(dev->class_dev, "board: %s, ID=0x%02x", dev->board_name,
readb(devpriv->mite->daq_io_addr + ID_Register));
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
if (board(dev)->num_di_ports) {
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan =
board(dev)->num_di_ports * ni_65xx_channels_per_port;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_config = ni_65xx_dio_insn_config;
s->insn_bits = ni_65xx_dio_insn_bits;
s->private = ni_65xx_alloc_subdevice_private();
if (s->private == NULL)
return -ENOMEM;
sprivate(s)->base_port = 0;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[1];
if (board(dev)->num_do_ports) {
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan =
board(dev)->num_do_ports * ni_65xx_channels_per_port;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_bits = ni_65xx_dio_insn_bits;
s->private = ni_65xx_alloc_subdevice_private();
if (s->private == NULL)
return -ENOMEM;
sprivate(s)->base_port = board(dev)->num_di_ports;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
if (board(dev)->num_dio_ports) {
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan =
board(dev)->num_dio_ports * ni_65xx_channels_per_port;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_config = ni_65xx_dio_insn_config;
s->insn_bits = ni_65xx_dio_insn_bits;
s->private = ni_65xx_alloc_subdevice_private();
if (s->private == NULL)
return -ENOMEM;
sprivate(s)->base_port = 0;
for (i = 0; i < board(dev)->num_dio_ports; ++i) {
writeb(0x1,
devpriv->mite->daq_io_addr +
Port_Select(i));
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[3];
dev->read_subdev = s;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
s->n_chan = 1;
s->range_table = &range_unknown;
s->maxdata = 1;
s->do_cmdtest = ni_65xx_intr_cmdtest;
s->do_cmd = ni_65xx_intr_cmd;
s->cancel = ni_65xx_intr_cancel;
s->insn_bits = ni_65xx_intr_insn_bits;
s->insn_config = ni_65xx_intr_insn_config;
for (i = 0; i < ni_65xx_total_num_ports(board(dev)); ++i) {
writeb(0x00,
devpriv->mite->daq_io_addr + Filter_Enable(i));
if (board(dev)->invert_outputs)
writeb(0x01,
devpriv->mite->daq_io_addr + Port_Data(i));
else
writeb(0x00,
devpriv->mite->daq_io_addr + Port_Data(i));
}
writeb(ClrEdge | ClrOverflow,
devpriv->mite->daq_io_addr + Clear_Register);
writeb(0x00,
devpriv->mite->daq_io_addr + Master_Interrupt_Control);
writeb(0x00000000, devpriv->mite->daq_io_addr + Filter_Interval);
ret = request_irq(dev->irq, ni_65xx_interrupt, IRQF_SHARED,
"ni_65xx", dev);
if (ret < 0) {
dev->irq = 0;
dev_warn(dev->class_dev, "irq not available\n");
}
return 0;
}
static void ni_65xx_detach(struct comedi_device *dev)
{
struct ni_65xx_private *devpriv = dev->private;
if (devpriv && devpriv->mite && devpriv->mite->daq_io_addr) {
writeb(0x00,
devpriv->mite->daq_io_addr +
Master_Interrupt_Control);
}
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
struct comedi_subdevice *s;
unsigned i;
for (i = 0; i < dev->n_subdevices; ++i) {
s = &dev->subdevices[i];
kfree(s->private);
s->private = NULL;
}
if (devpriv->mite) {
mite_unsetup(devpriv->mite);
mite_free(devpriv->mite);
}
}
}
static int ni_65xx_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &ni_65xx_driver);
}
static void ni_65xx_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
