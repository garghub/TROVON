static uint32_t almost_full_bits(unsigned int num_words)
{
return (num_words << 16) & 0xff0000;
}
static uint32_t almost_empty_bits(unsigned int num_words)
{
return num_words & 0xffff;
}
static uint32_t intr_bit(int interrupt_source)
{
return 0x1 << interrupt_source;
}
static unsigned int fifo_size(uint32_t fifo_size_bits)
{
return fifo_size_bits & 0xfffff;
}
static int dio_config_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
switch (data[0]) {
case INSN_CONFIG_BLOCK_SIZE:
return dio_config_block_size(dev, data);
default:
ret = comedi_dio_insn_config(dev, s, insn, data, 0xffffffff);
if (ret)
return ret;
break;
}
return insn->n;
}
static void disable_plx_interrupts(struct comedi_device *dev)
{
struct hpdi_private *devpriv = dev->private;
writel(0, devpriv->plx9080_iobase + PLX_INTRCS_REG);
}
static void init_plx9080(struct comedi_device *dev)
{
struct hpdi_private *devpriv = dev->private;
uint32_t bits;
void __iomem *plx_iobase = devpriv->plx9080_iobase;
DEBUG_PRINT(" plx interrupt status 0x%x\n",
readl(plx_iobase + PLX_INTRCS_REG));
DEBUG_PRINT(" plx id bits 0x%x\n", readl(plx_iobase + PLX_ID_REG));
DEBUG_PRINT(" plx control reg 0x%x\n",
readl(devpriv->plx9080_iobase + PLX_CONTROL_REG));
DEBUG_PRINT(" plx revision 0x%x\n",
readl(plx_iobase + PLX_REVISION_REG));
DEBUG_PRINT(" plx dma channel 0 mode 0x%x\n",
readl(plx_iobase + PLX_DMA0_MODE_REG));
DEBUG_PRINT(" plx dma channel 1 mode 0x%x\n",
readl(plx_iobase + PLX_DMA1_MODE_REG));
DEBUG_PRINT(" plx dma channel 0 pci address 0x%x\n",
readl(plx_iobase + PLX_DMA0_PCI_ADDRESS_REG));
DEBUG_PRINT(" plx dma channel 0 local address 0x%x\n",
readl(plx_iobase + PLX_DMA0_LOCAL_ADDRESS_REG));
DEBUG_PRINT(" plx dma channel 0 transfer size 0x%x\n",
readl(plx_iobase + PLX_DMA0_TRANSFER_SIZE_REG));
DEBUG_PRINT(" plx dma channel 0 descriptor 0x%x\n",
readl(plx_iobase + PLX_DMA0_DESCRIPTOR_REG));
DEBUG_PRINT(" plx dma channel 0 command status 0x%x\n",
readb(plx_iobase + PLX_DMA0_CS_REG));
DEBUG_PRINT(" plx dma channel 0 threshold 0x%x\n",
readl(plx_iobase + PLX_DMA0_THRESHOLD_REG));
DEBUG_PRINT(" plx bigend 0x%x\n", readl(plx_iobase + PLX_BIGEND_REG));
#ifdef __BIG_ENDIAN
bits = BIGEND_DMA0 | BIGEND_DMA1;
#else
bits = 0;
#endif
writel(bits, devpriv->plx9080_iobase + PLX_BIGEND_REG);
disable_plx_interrupts(dev);
abort_dma(dev, 0);
abort_dma(dev, 1);
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
static int setup_subdevices(struct comedi_device *dev)
{
struct comedi_subdevice *s;
int ret;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags =
SDF_READABLE | SDF_WRITEABLE | SDF_LSAMPL | SDF_CMD_READ;
s->n_chan = 32;
s->len_chanlist = 32;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = dio_config_insn;
s->do_cmd = hpdi_cmd;
s->do_cmdtest = hpdi_cmd_test;
s->cancel = hpdi_cancel;
return 0;
}
static int init_hpdi(struct comedi_device *dev)
{
struct hpdi_private *devpriv = dev->private;
uint32_t plx_intcsr_bits;
writel(BOARD_RESET_BIT, devpriv->hpdi_iobase + BOARD_CONTROL_REG);
udelay(10);
writel(almost_empty_bits(32) | almost_full_bits(32),
devpriv->hpdi_iobase + RX_PROG_ALMOST_REG);
writel(almost_empty_bits(32) | almost_full_bits(32),
devpriv->hpdi_iobase + TX_PROG_ALMOST_REG);
devpriv->tx_fifo_size = fifo_size(readl(devpriv->hpdi_iobase +
TX_FIFO_SIZE_REG));
devpriv->rx_fifo_size = fifo_size(readl(devpriv->hpdi_iobase +
RX_FIFO_SIZE_REG));
writel(0, devpriv->hpdi_iobase + INTERRUPT_CONTROL_REG);
plx_intcsr_bits =
ICS_AERR | ICS_PERR | ICS_PIE | ICS_PLIE | ICS_PAIE | ICS_LIE |
ICS_DMA0_E;
writel(plx_intcsr_bits, devpriv->plx9080_iobase + PLX_INTRCS_REG);
return 0;
}
static int setup_dma_descriptors(struct comedi_device *dev,
unsigned int transfer_size)
{
struct hpdi_private *devpriv = dev->private;
unsigned int buffer_index, buffer_offset;
uint32_t next_bits = PLX_DESC_IN_PCI_BIT | PLX_INTR_TERM_COUNT |
PLX_XFER_LOCAL_TO_PCI;
unsigned int i;
if (transfer_size > DMA_BUFFER_SIZE)
transfer_size = DMA_BUFFER_SIZE;
transfer_size -= transfer_size % sizeof(uint32_t);
if (transfer_size == 0)
return -1;
DEBUG_PRINT(" transfer_size %i\n", transfer_size);
DEBUG_PRINT(" descriptors at 0x%lx\n",
(unsigned long)devpriv->dma_desc_phys_addr);
buffer_offset = 0;
buffer_index = 0;
for (i = 0; i < NUM_DMA_DESCRIPTORS &&
buffer_index < NUM_DMA_BUFFERS; i++) {
devpriv->dma_desc[i].pci_start_addr =
cpu_to_le32(devpriv->dio_buffer_phys_addr[buffer_index] +
buffer_offset);
devpriv->dma_desc[i].local_start_addr = cpu_to_le32(FIFO_REG);
devpriv->dma_desc[i].transfer_size =
cpu_to_le32(transfer_size);
devpriv->dma_desc[i].next =
cpu_to_le32((devpriv->dma_desc_phys_addr + (i +
1) *
sizeof(devpriv->dma_desc[0])) | next_bits);
devpriv->desc_dio_buffer[i] =
devpriv->dio_buffer[buffer_index] +
(buffer_offset / sizeof(uint32_t));
buffer_offset += transfer_size;
if (transfer_size + buffer_offset > DMA_BUFFER_SIZE) {
buffer_offset = 0;
buffer_index++;
}
DEBUG_PRINT(" desc %i\n", i);
DEBUG_PRINT(" start addr virt 0x%p, phys 0x%lx\n",
devpriv->desc_dio_buffer[i],
(unsigned long)devpriv->dma_desc[i].
pci_start_addr);
DEBUG_PRINT(" next 0x%lx\n",
(unsigned long)devpriv->dma_desc[i].next);
}
devpriv->num_dma_descriptors = i;
devpriv->dma_desc[i - 1].next =
cpu_to_le32(devpriv->dma_desc_phys_addr | next_bits);
DEBUG_PRINT(" desc %i next fixup 0x%lx\n", i - 1,
(unsigned long)devpriv->dma_desc[i - 1].next);
devpriv->block_size = transfer_size;
return transfer_size;
}
static const struct hpdi_board *hpdi_find_board(struct pci_dev *pcidev)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(hpdi_boards); i++)
if (pcidev->device == hpdi_boards[i].device_id &&
pcidev->subsystem_device == hpdi_boards[i].subdevice_id)
return &hpdi_boards[i];
return NULL;
}
static int hpdi_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct hpdi_board *thisboard;
struct hpdi_private *devpriv;
int i;
int retval;
thisboard = hpdi_find_board(pcidev);
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
devpriv->plx9080_iobase = pci_ioremap_bar(pcidev, 0);
devpriv->hpdi_iobase = pci_ioremap_bar(pcidev, 2);
if (!devpriv->plx9080_iobase || !devpriv->hpdi_iobase) {
dev_warn(dev->class_dev, "failed to remap io memory\n");
return -ENOMEM;
}
DEBUG_PRINT(" plx9080 remapped to 0x%p\n", devpriv->plx9080_iobase);
DEBUG_PRINT(" hpdi remapped to 0x%p\n", devpriv->hpdi_iobase);
init_plx9080(dev);
if (request_irq(pcidev->irq, handle_interrupt, IRQF_SHARED,
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
DEBUG_PRINT("dio_buffer at virt 0x%p, phys 0x%lx\n",
devpriv->dio_buffer[i],
(unsigned long)devpriv->dio_buffer_phys_addr[i]);
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
retval = setup_dma_descriptors(dev, 0x1000);
if (retval < 0)
return retval;
retval = setup_subdevices(dev);
if (retval < 0)
return retval;
return init_hpdi(dev);
}
static void hpdi_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct hpdi_private *devpriv = dev->private;
unsigned int i;
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
if (devpriv->plx9080_iobase) {
disable_plx_interrupts(dev);
iounmap(devpriv->plx9080_iobase);
}
if (devpriv->hpdi_iobase)
iounmap(devpriv->hpdi_iobase);
for (i = 0; i < NUM_DMA_BUFFERS; i++) {
if (devpriv->dio_buffer[i])
pci_free_consistent(pcidev,
DMA_BUFFER_SIZE,
devpriv->dio_buffer[i],
devpriv->
dio_buffer_phys_addr[i]);
}
if (devpriv->dma_desc)
pci_free_consistent(pcidev,
sizeof(struct plx_dma_desc) *
NUM_DMA_DESCRIPTORS,
devpriv->dma_desc,
devpriv->dma_desc_phys_addr);
}
comedi_pci_disable(dev);
}
static int dio_config_block_size(struct comedi_device *dev, unsigned int *data)
{
unsigned int requested_block_size;
int retval;
requested_block_size = data[1];
retval = setup_dma_descriptors(dev, requested_block_size);
if (retval < 0)
return retval;
data[1] = retval;
return 2;
}
static int di_cmd_test(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
int i;
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
if (!cmd->chanlist_len) {
cmd->chanlist_len = 32;
err |= -EINVAL;
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
switch (cmd->stop_src) {
case TRIG_COUNT:
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
break;
case TRIG_NONE:
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
break;
default:
break;
}
if (err)
return 3;
if (err)
return 4;
if (!cmd->chanlist)
return 0;
for (i = 1; i < cmd->chanlist_len; i++) {
if (CR_CHAN(cmd->chanlist[i]) != i) {
comedi_error(dev,
"chanlist must be ch 0 to 31 in order");
err++;
break;
}
}
if (err)
return 5;
return 0;
}
static int hpdi_cmd_test(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
if (s->io_bits)
return -EINVAL;
else
return di_cmd_test(dev, s, cmd);
}
static inline void hpdi_writel(struct comedi_device *dev, uint32_t bits,
unsigned int offset)
{
struct hpdi_private *devpriv = dev->private;
writel(bits | devpriv->bits[offset / sizeof(uint32_t)],
devpriv->hpdi_iobase + offset);
}
static int di_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct hpdi_private *devpriv = dev->private;
uint32_t bits;
unsigned long flags;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
hpdi_writel(dev, RX_FIFO_RESET_BIT, BOARD_CONTROL_REG);
DEBUG_PRINT("hpdi: in di_cmd\n");
abort_dma(dev, 0);
devpriv->dma_desc_index = 0;
writel(0, devpriv->plx9080_iobase + PLX_DMA0_TRANSFER_SIZE_REG);
writel(0, devpriv->plx9080_iobase + PLX_DMA0_PCI_ADDRESS_REG);
writel(0, devpriv->plx9080_iobase + PLX_DMA0_LOCAL_ADDRESS_REG);
bits =
devpriv->dma_desc_phys_addr | PLX_DESC_IN_PCI_BIT |
PLX_INTR_TERM_COUNT | PLX_XFER_LOCAL_TO_PCI;
writel(bits, devpriv->plx9080_iobase + PLX_DMA0_DESCRIPTOR_REG);
spin_lock_irqsave(&dev->spinlock, flags);
writeb(PLX_DMA_EN_BIT | PLX_DMA_START_BIT | PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_iobase + PLX_DMA0_CS_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
if (cmd->stop_src == TRIG_COUNT)
devpriv->dio_count = cmd->stop_arg;
else
devpriv->dio_count = 1;
writel(RX_UNDERRUN_BIT | RX_OVERRUN_BIT,
devpriv->hpdi_iobase + BOARD_STATUS_REG);
writel(intr_bit(RX_FULL_INTR),
devpriv->hpdi_iobase + INTERRUPT_CONTROL_REG);
DEBUG_PRINT("hpdi: starting rx\n");
hpdi_writel(dev, RX_ENABLE_BIT, BOARD_CONTROL_REG);
return 0;
}
static int hpdi_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
if (s->io_bits)
return -EINVAL;
else
return di_cmd(dev, s);
}
static void drain_dma_buffers(struct comedi_device *dev, unsigned int channel)
{
struct hpdi_private *devpriv = dev->private;
struct comedi_async *async = dev->read_subdev->async;
uint32_t next_transfer_addr;
int j;
int num_samples = 0;
void __iomem *pci_addr_reg;
if (channel)
pci_addr_reg =
devpriv->plx9080_iobase + PLX_DMA1_PCI_ADDRESS_REG;
else
pci_addr_reg =
devpriv->plx9080_iobase + PLX_DMA0_PCI_ADDRESS_REG;
j = 0;
for (next_transfer_addr = readl(pci_addr_reg);
(next_transfer_addr <
le32_to_cpu(devpriv->dma_desc[devpriv->dma_desc_index].
pci_start_addr)
|| next_transfer_addr >=
le32_to_cpu(devpriv->dma_desc[devpriv->dma_desc_index].
pci_start_addr) + devpriv->block_size)
&& j < devpriv->num_dma_descriptors; j++) {
num_samples = devpriv->block_size / sizeof(uint32_t);
if (async->cmd.stop_src == TRIG_COUNT) {
if (num_samples > devpriv->dio_count)
num_samples = devpriv->dio_count;
devpriv->dio_count -= num_samples;
}
cfc_write_array_to_buffer(dev->read_subdev,
devpriv->desc_dio_buffer[devpriv->
dma_desc_index],
num_samples * sizeof(uint32_t));
devpriv->dma_desc_index++;
devpriv->dma_desc_index %= devpriv->num_dma_descriptors;
DEBUG_PRINT("next desc addr 0x%lx\n", (unsigned long)
devpriv->dma_desc[devpriv->dma_desc_index].
next);
DEBUG_PRINT("pci addr reg 0x%x\n", next_transfer_addr);
}
}
static irqreturn_t handle_interrupt(int irq, void *d)
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
plx_status = readl(devpriv->plx9080_iobase + PLX_INTRCS_REG);
if ((plx_status & (ICS_DMA0_A | ICS_DMA1_A | ICS_LIA)) == 0)
return IRQ_NONE;
hpdi_intr_status = readl(devpriv->hpdi_iobase + INTERRUPT_STATUS_REG);
hpdi_board_status = readl(devpriv->hpdi_iobase + BOARD_STATUS_REG);
async->events = 0;
if (hpdi_intr_status) {
DEBUG_PRINT("hpdi: intr status 0x%x, ", hpdi_intr_status);
writel(hpdi_intr_status,
devpriv->hpdi_iobase + INTERRUPT_STATUS_REG);
}
spin_lock_irqsave(&dev->spinlock, flags);
dma0_status = readb(devpriv->plx9080_iobase + PLX_DMA0_CS_REG);
if (plx_status & ICS_DMA0_A) {
writeb((dma0_status & PLX_DMA_EN_BIT) | PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_iobase + PLX_DMA0_CS_REG);
DEBUG_PRINT("dma0 status 0x%x\n", dma0_status);
if (dma0_status & PLX_DMA_EN_BIT)
drain_dma_buffers(dev, 0);
DEBUG_PRINT(" cleared dma ch0 interrupt\n");
}
spin_unlock_irqrestore(&dev->spinlock, flags);
spin_lock_irqsave(&dev->spinlock, flags);
dma1_status = readb(devpriv->plx9080_iobase + PLX_DMA1_CS_REG);
if (plx_status & ICS_DMA1_A) {
writeb((dma1_status & PLX_DMA_EN_BIT) | PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_iobase + PLX_DMA1_CS_REG);
DEBUG_PRINT("dma1 status 0x%x\n", dma1_status);
DEBUG_PRINT(" cleared dma ch1 interrupt\n");
}
spin_unlock_irqrestore(&dev->spinlock, flags);
if (plx_status & ICS_LDIA) {
plx_bits = readl(devpriv->plx9080_iobase + PLX_DBR_OUT_REG);
writel(plx_bits, devpriv->plx9080_iobase + PLX_DBR_OUT_REG);
DEBUG_PRINT(" cleared local doorbell bits 0x%x\n", plx_bits);
}
if (hpdi_board_status & RX_OVERRUN_BIT) {
comedi_error(dev, "rx fifo overrun");
async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
DEBUG_PRINT("dma0_status 0x%x\n",
(int)readb(devpriv->plx9080_iobase +
PLX_DMA0_CS_REG));
}
if (hpdi_board_status & RX_UNDERRUN_BIT) {
comedi_error(dev, "rx fifo underrun");
async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
}
if (devpriv->dio_count == 0)
async->events |= COMEDI_CB_EOA;
DEBUG_PRINT("board status 0x%x, ", hpdi_board_status);
DEBUG_PRINT("plx status 0x%x\n", plx_status);
if (async->events)
DEBUG_PRINT(" events 0x%x\n", async->events);
cfc_handle_events(dev, s);
return IRQ_HANDLED;
}
static void abort_dma(struct comedi_device *dev, unsigned int channel)
{
struct hpdi_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
plx9080_abort_dma(devpriv->plx9080_iobase, channel);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
static int hpdi_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct hpdi_private *devpriv = dev->private;
hpdi_writel(dev, 0, BOARD_CONTROL_REG);
writel(0, devpriv->hpdi_iobase + INTERRUPT_CONTROL_REG);
abort_dma(dev, 0);
return 0;
}
static int gsc_hpdi_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &gsc_hpdi_driver, id->driver_data);
}
