static unsigned int ni_65xx_num_ports(struct comedi_device *dev)
{
const struct ni_65xx_board *board = comedi_board(dev);
return board->num_dio_ports + board->num_di_ports + board->num_do_ports;
}
static void ni_65xx_disable_input_filters(struct comedi_device *dev)
{
unsigned int num_ports = ni_65xx_num_ports(dev);
int i;
for (i = 0; i < num_ports; ++i)
writeb(0x00, dev->mmio + NI_65XX_FILTER_ENA(i));
writel(0x00000000, dev->mmio + NI_65XX_FILTER_REG);
}
static void ni_65xx_update_edge_detection(struct comedi_device *dev,
unsigned int base_chan,
unsigned int rising,
unsigned int falling)
{
unsigned int num_ports = ni_65xx_num_ports(dev);
unsigned int port;
if (base_chan >= NI_65XX_PORT_TO_CHAN(num_ports))
return;
for (port = NI_65XX_CHAN_TO_PORT(base_chan); port < num_ports; port++) {
int bitshift = (int)(NI_65XX_PORT_TO_CHAN(port) - base_chan);
unsigned int port_mask, port_rising, port_falling;
if (bitshift >= 32)
break;
if (bitshift >= 0) {
port_mask = ~0U >> bitshift;
port_rising = rising >> bitshift;
port_falling = falling >> bitshift;
} else {
port_mask = ~0U << -bitshift;
port_rising = rising << -bitshift;
port_falling = falling << -bitshift;
}
if (port_mask & 0xff) {
if (~port_mask & 0xff) {
port_rising |=
readb(dev->mmio +
NI_65XX_RISE_EDGE_ENA_REG(port)) &
~port_mask;
port_falling |=
readb(dev->mmio +
NI_65XX_FALL_EDGE_ENA_REG(port)) &
~port_mask;
}
writeb(port_rising & 0xff,
dev->mmio + NI_65XX_RISE_EDGE_ENA_REG(port));
writeb(port_falling & 0xff,
dev->mmio + NI_65XX_FALL_EDGE_ENA_REG(port));
}
}
}
static void ni_65xx_disable_edge_detection(struct comedi_device *dev)
{
ni_65xx_update_edge_detection(dev, 0, 0, 0);
ni_65xx_update_edge_detection(dev, 32, 0, 0);
ni_65xx_update_edge_detection(dev, 64, 0, 0);
}
static int ni_65xx_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long base_port = (unsigned long)s->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int chan_mask = NI_65XX_CHAN_TO_MASK(chan);
unsigned port = base_port + NI_65XX_CHAN_TO_PORT(chan);
unsigned int interval;
unsigned int val;
switch (data[0]) {
case INSN_CONFIG_FILTER:
interval = (data[1] + 100) / 200;
if (interval > 0xfffff)
interval = 0xfffff;
data[1] = interval * 200;
val = readb(dev->mmio + NI_65XX_FILTER_ENA(port));
if (interval) {
writel(interval, dev->mmio + NI_65XX_FILTER_REG);
val |= chan_mask;
} else {
val &= ~chan_mask;
}
writeb(val, dev->mmio + NI_65XX_FILTER_ENA(port));
break;
case INSN_CONFIG_DIO_OUTPUT:
if (s->type != COMEDI_SUBD_DIO)
return -EINVAL;
writeb(NI_65XX_IO_SEL_OUTPUT,
dev->mmio + NI_65XX_IO_SEL_REG(port));
break;
case INSN_CONFIG_DIO_INPUT:
if (s->type != COMEDI_SUBD_DIO)
return -EINVAL;
writeb(NI_65XX_IO_SEL_INPUT,
dev->mmio + NI_65XX_IO_SEL_REG(port));
break;
case INSN_CONFIG_DIO_QUERY:
if (s->type != COMEDI_SUBD_DIO)
return -EINVAL;
val = readb(dev->mmio + NI_65XX_IO_SEL_REG(port));
data[1] = (val == NI_65XX_IO_SEL_INPUT) ? COMEDI_INPUT
: COMEDI_OUTPUT;
break;
default:
return -EINVAL;
}
return insn->n;
}
static int ni_65xx_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long base_port = (unsigned long)s->private;
unsigned int base_chan = CR_CHAN(insn->chanspec);
int last_port_offset = NI_65XX_CHAN_TO_PORT(s->n_chan - 1);
unsigned read_bits = 0;
int port_offset;
for (port_offset = NI_65XX_CHAN_TO_PORT(base_chan);
port_offset <= last_port_offset; port_offset++) {
unsigned port = base_port + port_offset;
int base_port_channel = NI_65XX_PORT_TO_CHAN(port_offset);
unsigned port_mask, port_data, bits;
int bitshift = base_port_channel - base_chan;
if (bitshift >= 32)
break;
port_mask = data[0];
port_data = data[1];
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
bits = readb(dev->mmio + NI_65XX_IO_DATA_REG(port));
bits ^= s->io_bits;
bits &= ~port_mask;
bits |= (port_data & port_mask);
bits ^= s->io_bits;
writeb(bits, dev->mmio + NI_65XX_IO_DATA_REG(port));
}
bits = readb(dev->mmio + NI_65XX_IO_DATA_REG(port));
bits ^= s->io_bits;
if (bitshift > 0)
bits <<= bitshift;
else
bits >>= -bitshift;
read_bits |= bits;
}
data[1] = read_bits;
return insn->n;
}
static irqreturn_t ni_65xx_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int status;
status = readb(dev->mmio + NI_65XX_STATUS_REG);
if ((status & NI_65XX_STATUS_INT) == 0)
return IRQ_NONE;
if ((status & NI_65XX_STATUS_EDGE_INT) == 0)
return IRQ_NONE;
writeb(NI_65XX_CLR_EDGE_INT | NI_65XX_CLR_OVERFLOW_INT,
dev->mmio + NI_65XX_CLR_REG);
comedi_buf_put(s, 0);
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
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
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
writeb(NI_65XX_CLR_EDGE_INT | NI_65XX_CLR_OVERFLOW_INT,
dev->mmio + NI_65XX_CLR_REG);
writeb(NI_65XX_CTRL_FALL_EDGE_ENA | NI_65XX_CTRL_RISE_EDGE_ENA |
NI_65XX_CTRL_INT_ENA | NI_65XX_CTRL_EDGE_ENA,
dev->mmio + NI_65XX_CTRL_REG);
return 0;
}
static int ni_65xx_intr_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
writeb(0x00, dev->mmio + NI_65XX_CTRL_REG);
return 0;
}
static int ni_65xx_intr_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = 0;
return insn->n;
}
static int ni_65xx_intr_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
switch (data[0]) {
case INSN_CONFIG_CHANGE_NOTIFY:
if (insn->n != 3)
return -EINVAL;
ni_65xx_update_edge_detection(dev, 0, data[1], data[2]);
ni_65xx_update_edge_detection(dev, 32, 0, 0);
ni_65xx_update_edge_detection(dev, 64, 0, 0);
break;
case INSN_CONFIG_DIGITAL_TRIG:
if (data[1] != 0)
return -EINVAL;
switch (data[2]) {
case COMEDI_DIGITAL_TRIG_DISABLE:
ni_65xx_disable_edge_detection(dev);
break;
case COMEDI_DIGITAL_TRIG_ENABLE_EDGES:
ni_65xx_update_edge_detection(dev, data[3],
data[4], data[5]);
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return insn->n;
}
static int ni_65xx_mite_init(struct pci_dev *pcidev)
{
void __iomem *mite_base;
u32 main_phys_addr;
mite_base = pci_ioremap_bar(pcidev, 0);
if (!mite_base)
return -ENOMEM;
main_phys_addr = pci_resource_start(pcidev, 1);
writel(main_phys_addr | WENAB, mite_base + MITE_IODWBSR);
iounmap(mite_base);
return 0;
}
static int ni_65xx_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct ni_65xx_board *board = NULL;
struct comedi_subdevice *s;
unsigned i;
int ret;
if (context < ARRAY_SIZE(ni_65xx_boards))
board = &ni_65xx_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
ret = ni_65xx_mite_init(pcidev);
if (ret)
return ret;
dev->mmio = pci_ioremap_bar(pcidev, 1);
if (!dev->mmio)
return -ENOMEM;
writeb(NI_65XX_CLR_EDGE_INT | NI_65XX_CLR_OVERFLOW_INT,
dev->mmio + NI_65XX_CLR_REG);
writeb(0x00, dev->mmio + NI_65XX_CTRL_REG);
if (pcidev->irq) {
ret = request_irq(pcidev->irq, ni_65xx_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
dev_info(dev->class_dev, "board: %s, ID=0x%02x", dev->board_name,
readb(dev->mmio + NI_65XX_ID_REG));
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
if (board->num_di_ports) {
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = NI_65XX_PORT_TO_CHAN(board->num_di_ports);
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni_65xx_dio_insn_bits;
s->insn_config = ni_65xx_dio_insn_config;
s->private = (void *)0;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[1];
if (board->num_do_ports) {
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = NI_65XX_PORT_TO_CHAN(board->num_do_ports);
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni_65xx_dio_insn_bits;
s->private = (void *)(unsigned long)board->num_di_ports;
if (ni_65xx_legacy_invert_outputs && board->legacy_invert)
s->io_bits = 0xff;
for (i = 0; i < board->num_do_ports; ++i) {
writeb(s->io_bits,
dev->mmio +
NI_65XX_IO_DATA_REG(board->num_di_ports + i));
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
if (board->num_dio_ports) {
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = NI_65XX_PORT_TO_CHAN(board->num_dio_ports);
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni_65xx_dio_insn_bits;
s->insn_config = ni_65xx_dio_insn_config;
s->private = (void *)0;
for (i = 0; i < board->num_dio_ports; ++i) {
writeb(NI_65XX_IO_SEL_INPUT,
dev->mmio + NI_65XX_IO_SEL_REG(i));
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 1;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni_65xx_intr_insn_bits;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 1;
s->insn_config = ni_65xx_intr_insn_config;
s->do_cmdtest = ni_65xx_intr_cmdtest;
s->do_cmd = ni_65xx_intr_cmd;
s->cancel = ni_65xx_intr_cancel;
}
ni_65xx_disable_input_filters(dev);
ni_65xx_disable_edge_detection(dev);
return 0;
}
static void ni_65xx_detach(struct comedi_device *dev)
{
if (dev->mmio) {
writeb(0x00, dev->mmio + NI_65XX_CTRL_REG);
iounmap(dev->mmio);
}
if (dev->irq)
free_irq(dev->irq, dev);
comedi_pci_disable(dev);
}
static int ni_65xx_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &ni_65xx_driver, id->driver_data);
}
