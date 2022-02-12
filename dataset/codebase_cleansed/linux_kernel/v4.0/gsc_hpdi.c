static void gsc_hpdi_drain_dma(struct comedi_device *dev, unsigned int channel)
{
struct hpdi_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int idx;
unsigned int start;
unsigned int desc;
unsigned int size;
unsigned int next;
if (channel)
next = readl(devpriv->plx9080_mmio + PLX_DMA1_PCI_ADDRESS_REG);
else
next = readl(devpriv->plx9080_mmio + PLX_DMA0_PCI_ADDRESS_REG);
idx = devpriv->dma_desc_index;
start = le32_to_cpu(devpriv->dma_desc[idx].pci_start_addr);
for (desc = 0; (next < start || next >= start + devpriv->block_size) &&
desc < devpriv->num_dma_descriptors; desc++) {
size = devpriv->block_size / sizeof(uint32_t);
if (cmd->stop_src == TRIG_COUNT) {
if (size > devpriv->dio_count)
size = devpriv->dio_count;
devpriv->dio_count -= size;
}
comedi_buf_write_samples(s, devpriv->desc_dio_buffer[idx],
size);
idx++;
idx %= devpriv->num_dma_descriptors;
start = le32_to_cpu(devpriv->dma_desc[idx].pci_start_addr);
devpriv->dma_desc_index = idx;
}
}
static irqreturn_t gsc_hpdi_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct hpdi_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
uint32_t hpdi_intr_status, hpdi_board_status;
uint32_t plx_status;
uint32_t plx_bits;
uint8_t dma0_status, dma1_status;
unsigned long flags;
if (!dev->attached)
return IRQ_NONE;
plx_status = readl(devpriv->plx9080_mmio + PLX_INTRCS_REG);
if ((plx_status & (ICS_DMA0_A | ICS_DMA1_A | ICS_LIA)) == 0)
return IRQ_NONE;
hpdi_intr_status = readl(dev->mmio + INTERRUPT_STATUS_REG);
hpdi_board_status = readl(dev->mmio + BOARD_STATUS_REG);
if (hpdi_intr_status)
writel(hpdi_intr_status, dev->mmio + INTERRUPT_STATUS_REG);
spin_lock_irqsave(&dev->spinlock, flags);
dma0_status = readb(devpriv->plx9080_mmio + PLX_DMA0_CS_REG);
if (plx_status & ICS_DMA0_A) {
writeb((dma0_status & PLX_DMA_EN_BIT) | PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_mmio + PLX_DMA0_CS_REG);
if (dma0_status & PLX_DMA_EN_BIT)
gsc_hpdi_drain_dma(dev, 0);
}
spin_unlock_irqrestore(&dev->spinlock, flags);
spin_lock_irqsave(&dev->spinlock, flags);
dma1_status = readb(devpriv->plx9080_mmio + PLX_DMA1_CS_REG);
if (plx_status & ICS_DMA1_A) {
writeb((dma1_status & PLX_DMA_EN_BIT) | PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_mmio + PLX_DMA1_CS_REG);
}
spin_unlock_irqrestore(&dev->spinlock, flags);
if (plx_status & ICS_LDIA) {
plx_bits = readl(devpriv->plx9080_mmio + PLX_DBR_OUT_REG);
writel(plx_bits, devpriv->plx9080_mmio + PLX_DBR_OUT_REG);
}
if (hpdi_board_status & RX_OVERRUN_BIT) {
dev_err(dev->class_dev, "rx fifo overrun\n");
async->events |= COMEDI_CB_ERROR;
}
if (hpdi_board_status & RX_UNDERRUN_BIT) {
dev_err(dev->class_dev, "rx fifo underrun\n");
async->events |= COMEDI_CB_ERROR;
}
if (devpriv->dio_count == 0)
async->events |= COMEDI_CB_EOA;
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static void gsc_hpdi_abort_dma(struct comedi_device *dev, unsigned int channel)
{
struct hpdi_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
plx9080_abort_dma(devpriv->plx9080_mmio, channel);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
static int gsc_hpdi_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
writel(0, dev->mmio + BOARD_CONTROL_REG);
writel(0, dev->mmio + INTERRUPT_CONTROL_REG);
gsc_hpdi_abort_dma(dev, 0);
return 0;
}
static int gsc_hpdi_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct hpdi_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned long flags;
uint32_t bits;
if (s->io_bits)
return -EINVAL;
writel(RX_FIFO_RESET_BIT, dev->mmio + BOARD_CONTROL_REG);
gsc_hpdi_abort_dma(dev, 0);
devpriv->dma_desc_index = 0;
writel(0, devpriv->plx9080_mmio + PLX_DMA0_TRANSFER_SIZE_REG);
writel(0, devpriv->plx9080_mmio + PLX_DMA0_PCI_ADDRESS_REG);
writel(0, devpriv->plx9080_mmio + PLX_DMA0_LOCAL_ADDRESS_REG);
bits = devpriv->dma_desc_phys_addr | PLX_DESC_IN_PCI_BIT |
PLX_INTR_TERM_COUNT | PLX_XFER_LOCAL_TO_PCI;
writel(bits, devpriv->plx9080_mmio + PLX_DMA0_DESCRIPTOR_REG);
spin_lock_irqsave(&dev->spinlock, flags);
writeb(PLX_DMA_EN_BIT | PLX_DMA_START_BIT | PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_mmio + PLX_DMA0_CS_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
if (cmd->stop_src == TRIG_COUNT)
devpriv->dio_count = cmd->stop_arg;
else
devpriv->dio_count = 1;
writel(RX_UNDERRUN_BIT | RX_OVERRUN_BIT, dev->mmio + BOARD_STATUS_REG);
writel(RX_FULL_INTR, dev->mmio + INTERRUPT_CONTROL_REG);
writel(RX_ENABLE_BIT, dev->mmio + BOARD_CONTROL_REG);
return 0;
}
static int gsc_hpdi_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int i;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
if (chan != i) {
dev_dbg(dev->class_dev,
"chanlist must be ch 0 to 31 in order\n");
return -EINVAL;
}
}
return 0;
}
static int gsc_hpdi_cmd_test(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
if (s->io_bits)
return -EINVAL;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (!cmd->chanlist_len || !cmd->chanlist) {
cmd->chanlist_len = 32;
err |= -EINVAL;
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= gsc_hpdi_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int gsc_hpdi_setup_dma_descriptors(struct comedi_device *dev,
unsigned int len)
{
struct hpdi_private *devpriv = dev->private;
dma_addr_t phys_addr = devpriv->dma_desc_phys_addr;
uint32_t next_bits = PLX_DESC_IN_PCI_BIT | PLX_INTR_TERM_COUNT |
PLX_XFER_LOCAL_TO_PCI;
unsigned int offset = 0;
unsigned int idx = 0;
unsigned int i;
if (len > DMA_BUFFER_SIZE)
len = DMA_BUFFER_SIZE;
len -= len % sizeof(uint32_t);
if (len == 0)
return -EINVAL;
for (i = 0; i < NUM_DMA_DESCRIPTORS && idx < NUM_DMA_BUFFERS; i++) {
devpriv->dma_desc[i].pci_start_addr =
cpu_to_le32(devpriv->dio_buffer_phys_addr[idx] + offset);
devpriv->dma_desc[i].local_start_addr = cpu_to_le32(FIFO_REG);
devpriv->dma_desc[i].transfer_size = cpu_to_le32(len);
devpriv->dma_desc[i].next = cpu_to_le32((phys_addr +
(i + 1) * sizeof(devpriv->dma_desc[0])) | next_bits);
devpriv->desc_dio_buffer[i] = devpriv->dio_buffer[idx] +
(offset / sizeof(uint32_t));
offset += len;
if (len + offset > DMA_BUFFER_SIZE) {
offset = 0;
idx++;
}
}
devpriv->num_dma_descriptors = i;
devpriv->dma_desc[i - 1].next = cpu_to_le32(phys_addr | next_bits);
devpriv->block_size = len;
return len;
}
static int gsc_hpdi_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
switch (data[0]) {
case INSN_CONFIG_BLOCK_SIZE:
ret = gsc_hpdi_setup_dma_descriptors(dev, data[1]);
if (ret)
return ret;
data[1] = ret;
break;
default:
ret = comedi_dio_insn_config(dev, s, insn, data, 0xffffffff);
if (ret)
return ret;
break;
}
return insn->n;
}
static void gsc_hpdi_free_dma(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct hpdi_private *devpriv = dev->private;
int i;
if (!devpriv)
return;
for (i = 0; i < NUM_DMA_BUFFERS; i++) {
if (devpriv->dio_buffer[i])
pci_free_consistent(pcidev,
DMA_BUFFER_SIZE,
devpriv->dio_buffer[i],
devpriv->dio_buffer_phys_addr[i]);
}
if (devpriv->dma_desc)
pci_free_consistent(pcidev,
sizeof(struct plx_dma_desc) *
NUM_DMA_DESCRIPTORS,
devpriv->dma_desc,
devpriv->dma_desc_phys_addr);
}
static int gsc_hpdi_init(struct comedi_device *dev)
{
struct hpdi_private *devpriv = dev->private;
uint32_t plx_intcsr_bits;
writel(BOARD_RESET_BIT, dev->mmio + BOARD_CONTROL_REG);
udelay(10);
writel(ALMOST_EMPTY_BITS(32) | ALMOST_FULL_BITS(32),
dev->mmio + RX_PROG_ALMOST_REG);
writel(ALMOST_EMPTY_BITS(32) | ALMOST_FULL_BITS(32),
dev->mmio + TX_PROG_ALMOST_REG);
devpriv->tx_fifo_size = readl(dev->mmio + TX_FIFO_SIZE_REG) &
FIFO_SIZE_MASK;
devpriv->rx_fifo_size = readl(dev->mmio + RX_FIFO_SIZE_REG) &
FIFO_SIZE_MASK;
writel(0, dev->mmio + INTERRUPT_CONTROL_REG);
plx_intcsr_bits =
ICS_AERR | ICS_PERR | ICS_PIE | ICS_PLIE | ICS_PAIE | ICS_LIE |
ICS_DMA0_E;
writel(plx_intcsr_bits, devpriv->plx9080_mmio + PLX_INTRCS_REG);
return 0;
}
static void gsc_hpdi_init_plx9080(struct comedi_device *dev)
{
struct hpdi_private *devpriv = dev->private;
uint32_t bits;
void __iomem *plx_iobase = devpriv->plx9080_mmio;
#ifdef __BIG_ENDIAN
bits = BIGEND_DMA0 | BIGEND_DMA1;
#else
bits = 0;
#endif
writel(bits, devpriv->plx9080_mmio + PLX_BIGEND_REG);
writel(0, devpriv->plx9080_mmio + PLX_INTRCS_REG);
gsc_hpdi_abort_dma(dev, 0);
gsc_hpdi_abort_dma(dev, 1);
bits = 0;
bits |= PLX_DMA_EN_READYIN_BIT;
bits |= PLX_EN_CHAIN_BIT;
bits |= PLX_EN_DMA_DONE_INTR_BIT;
bits |= PLX_LOCAL_ADDR_CONST_BIT;
bits |= PLX_DMA_INTR_PCI_BIT;
bits |= PLX_DEMAND_MODE_BIT;
bits |= PLX_DMA_LOCAL_BURST_EN_BIT;
bits |= PLX_LOCAL_BUS_32_WIDE_BITS;
writel(bits, plx_iobase + PLX_DMA0_MODE_REG);
}
static const struct hpdi_board *gsc_hpdi_find_board(struct pci_dev *pcidev)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(hpdi_boards); i++)
if (pcidev->device == hpdi_boards[i].device_id &&
pcidev->subsystem_device == hpdi_boards[i].subdevice_id)
return &hpdi_boards[i];
return NULL;
}
static int gsc_hpdi_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct hpdi_board *thisboard;
struct hpdi_private *devpriv;
struct comedi_subdevice *s;
int i;
int retval;
thisboard = gsc_hpdi_find_board(pcidev);
if (!thisboard) {
dev_err(dev->class_dev, "gsc_hpdi: pci %s not supported\n",
pci_name(pcidev));
return -EINVAL;
}
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
retval = comedi_pci_enable(dev);
if (retval)
return retval;
pci_set_master(pcidev);
devpriv->plx9080_mmio = pci_ioremap_bar(pcidev, 0);
dev->mmio = pci_ioremap_bar(pcidev, 2);
if (!devpriv->plx9080_mmio || !dev->mmio) {
dev_warn(dev->class_dev, "failed to remap io memory\n");
return -ENOMEM;
}
gsc_hpdi_init_plx9080(dev);
if (request_irq(pcidev->irq, gsc_hpdi_interrupt, IRQF_SHARED,
dev->board_name, dev)) {
dev_warn(dev->class_dev,
"unable to allocate irq %u\n", pcidev->irq);
return -EINVAL;
}
dev->irq = pcidev->irq;
dev_dbg(dev->class_dev, " irq %u\n", dev->irq);
for (i = 0; i < NUM_DMA_BUFFERS; i++) {
devpriv->dio_buffer[i] =
pci_alloc_consistent(pcidev, DMA_BUFFER_SIZE,
&devpriv->dio_buffer_phys_addr[i]);
}
devpriv->dma_desc = pci_alloc_consistent(pcidev,
sizeof(struct plx_dma_desc) *
NUM_DMA_DESCRIPTORS,
&devpriv->dma_desc_phys_addr);
if (devpriv->dma_desc_phys_addr & 0xf) {
dev_warn(dev->class_dev,
" dma descriptors not quad-word aligned (bug)\n");
return -EIO;
}
retval = gsc_hpdi_setup_dma_descriptors(dev, 0x1000);
if (retval < 0)
return retval;
retval = comedi_alloc_subdevices(dev, 1);
if (retval)
return retval;
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_LSAMPL |
SDF_CMD_READ;
s->n_chan = 32;
s->len_chanlist = 32;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = gsc_hpdi_dio_insn_config;
s->do_cmd = gsc_hpdi_cmd;
s->do_cmdtest = gsc_hpdi_cmd_test;
s->cancel = gsc_hpdi_cancel;
return gsc_hpdi_init(dev);
}
static void gsc_hpdi_detach(struct comedi_device *dev)
{
struct hpdi_private *devpriv = dev->private;
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
if (devpriv->plx9080_mmio) {
writel(0, devpriv->plx9080_mmio + PLX_INTRCS_REG);
iounmap(devpriv->plx9080_mmio);
}
if (dev->mmio)
iounmap(dev->mmio);
}
comedi_pci_disable(dev);
gsc_hpdi_free_dma(dev);
}
static int gsc_hpdi_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &gsc_hpdi_driver, id->driver_data);
}
