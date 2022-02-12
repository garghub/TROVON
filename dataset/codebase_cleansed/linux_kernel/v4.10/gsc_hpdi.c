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
next = readl(devpriv->plx9080_mmio + PLX_REG_DMAPADR(channel));
idx = devpriv->dma_desc_index;
start = le32_to_cpu(devpriv->dma_desc[idx].pci_start_addr);
for (desc = 0; (next < start || next >= start + devpriv->block_size) &&
desc < devpriv->num_dma_descriptors; desc++) {
size = devpriv->block_size / sizeof(u32);
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
u32 hpdi_intr_status, hpdi_board_status;
u32 plx_status;
u32 plx_bits;
u8 dma0_status, dma1_status;
unsigned long flags;
if (!dev->attached)
return IRQ_NONE;
plx_status = readl(devpriv->plx9080_mmio + PLX_REG_INTCSR);
if ((plx_status &
(PLX_INTCSR_DMA0IA | PLX_INTCSR_DMA1IA | PLX_INTCSR_PLIA)) == 0)
return IRQ_NONE;
hpdi_intr_status = readl(dev->mmio + INTERRUPT_STATUS_REG);
hpdi_board_status = readl(dev->mmio + BOARD_STATUS_REG);
if (hpdi_intr_status)
writel(hpdi_intr_status, dev->mmio + INTERRUPT_STATUS_REG);
spin_lock_irqsave(&dev->spinlock, flags);
dma0_status = readb(devpriv->plx9080_mmio + PLX_REG_DMACSR0);
if (plx_status & PLX_INTCSR_DMA0IA) {
writeb((dma0_status & PLX_DMACSR_ENABLE) | PLX_DMACSR_CLEARINTR,
devpriv->plx9080_mmio + PLX_REG_DMACSR0);
if (dma0_status & PLX_DMACSR_ENABLE)
gsc_hpdi_drain_dma(dev, 0);
}
spin_unlock_irqrestore(&dev->spinlock, flags);
spin_lock_irqsave(&dev->spinlock, flags);
dma1_status = readb(devpriv->plx9080_mmio + PLX_REG_DMACSR1);
if (plx_status & PLX_INTCSR_DMA1IA) {
writeb((dma1_status & PLX_DMACSR_ENABLE) | PLX_DMACSR_CLEARINTR,
devpriv->plx9080_mmio + PLX_REG_DMACSR1);
}
spin_unlock_irqrestore(&dev->spinlock, flags);
if (plx_status & PLX_INTCSR_LDBIA) {
plx_bits = readl(devpriv->plx9080_mmio + PLX_REG_L2PDBELL);
writel(plx_bits, devpriv->plx9080_mmio + PLX_REG_L2PDBELL);
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
u32 bits;
if (s->io_bits)
return -EINVAL;
writel(RX_FIFO_RESET_BIT, dev->mmio + BOARD_CONTROL_REG);
gsc_hpdi_abort_dma(dev, 0);
devpriv->dma_desc_index = 0;
writel(0, devpriv->plx9080_mmio + PLX_REG_DMASIZ0);
writel(0, devpriv->plx9080_mmio + PLX_REG_DMAPADR0);
writel(0, devpriv->plx9080_mmio + PLX_REG_DMALADR0);
bits = devpriv->dma_desc_phys_addr | PLX_DMADPR_DESCPCI |
PLX_DMADPR_TCINTR | PLX_DMADPR_XFERL2P;
writel(bits, devpriv->plx9080_mmio + PLX_REG_DMADPR0);
spin_lock_irqsave(&dev->spinlock, flags);
writeb(PLX_DMACSR_ENABLE | PLX_DMACSR_START | PLX_DMACSR_CLEARINTR,
devpriv->plx9080_mmio + PLX_REG_DMACSR0);
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
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (!cmd->chanlist_len || !cmd->chanlist) {
cmd->chanlist_len = 32;
err |= -EINVAL;
}
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
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
u32 next_bits = PLX_DMADPR_DESCPCI | PLX_DMADPR_TCINTR |
PLX_DMADPR_XFERL2P;
unsigned int offset = 0;
unsigned int idx = 0;
unsigned int i;
if (len > DMA_BUFFER_SIZE)
len = DMA_BUFFER_SIZE;
len -= len % sizeof(u32);
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
(offset / sizeof(u32));
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
dma_free_coherent(&pcidev->dev,
DMA_BUFFER_SIZE,
devpriv->dio_buffer[i],
devpriv->dio_buffer_phys_addr[i]);
}
if (devpriv->dma_desc)
dma_free_coherent(&pcidev->dev,
sizeof(struct plx_dma_desc) *
NUM_DMA_DESCRIPTORS,
devpriv->dma_desc,
devpriv->dma_desc_phys_addr);
}
static int gsc_hpdi_init(struct comedi_device *dev)
{
struct hpdi_private *devpriv = dev->private;
u32 plx_intcsr_bits;
writel(BOARD_RESET_BIT, dev->mmio + BOARD_CONTROL_REG);
usleep_range(10, 1000);
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
PLX_INTCSR_LSEABORTEN | PLX_INTCSR_LSEPARITYEN | PLX_INTCSR_PIEN |
PLX_INTCSR_PLIEN | PLX_INTCSR_PABORTIEN | PLX_INTCSR_LIOEN |
PLX_INTCSR_DMA0IEN;
writel(plx_intcsr_bits, devpriv->plx9080_mmio + PLX_REG_INTCSR);
return 0;
}
static void gsc_hpdi_init_plx9080(struct comedi_device *dev)
{
struct hpdi_private *devpriv = dev->private;
u32 bits;
void __iomem *plx_iobase = devpriv->plx9080_mmio;
#ifdef __BIG_ENDIAN
bits = PLX_BIGEND_DMA0 | PLX_BIGEND_DMA1;
#else
bits = 0;
#endif
writel(bits, devpriv->plx9080_mmio + PLX_REG_BIGEND);
writel(0, devpriv->plx9080_mmio + PLX_REG_INTCSR);
gsc_hpdi_abort_dma(dev, 0);
gsc_hpdi_abort_dma(dev, 1);
bits = 0;
bits |= PLX_DMAMODE_READYIEN;
bits |= PLX_DMAMODE_CHAINEN;
bits |= PLX_DMAMODE_DONEIEN;
bits |= PLX_DMAMODE_LACONST;
bits |= PLX_DMAMODE_INTRPCI;
bits |= PLX_DMAMODE_DEMAND;
bits |= PLX_DMAMODE_BURSTEN;
bits |= PLX_DMAMODE_WIDTH_32;
writel(bits, plx_iobase + PLX_REG_DMAMODE0);
}
static int gsc_hpdi_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct hpdi_private *devpriv;
struct comedi_subdevice *s;
int i;
int retval;
dev->board_name = "pci-hpdi32";
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
dma_alloc_coherent(&pcidev->dev, DMA_BUFFER_SIZE,
&devpriv->dio_buffer_phys_addr[i],
GFP_KERNEL);
}
devpriv->dma_desc = dma_alloc_coherent(&pcidev->dev,
sizeof(struct plx_dma_desc) *
NUM_DMA_DESCRIPTORS,
&devpriv->dma_desc_phys_addr,
GFP_KERNEL);
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
writel(0, devpriv->plx9080_mmio + PLX_REG_INTCSR);
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
