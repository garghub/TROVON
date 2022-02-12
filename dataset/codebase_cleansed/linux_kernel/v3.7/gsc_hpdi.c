int command_channel_valid(unsigned int channel)
{
if (channel == 0 || channel > 6) {
printk(KERN_WARNING
"gsc_hpdi: bug! invalid cable command channel\n");
return 0;
}
return 1;
}
int firmware_revision(uint32_t fwr_bits)
{
return fwr_bits & 0xff;
}
int pcb_revision(uint32_t fwr_bits)
{
return (fwr_bits >> 8) & 0xff;
}
int hpdi_subid(uint32_t fwr_bits)
{
return (fwr_bits >> 16) & 0xff;
}
uint32_t command_discrete_output_bits(unsigned int channel, int output,
int output_value)
{
uint32_t bits = 0;
if (command_channel_valid(channel) == 0)
return 0;
if (output) {
bits |= 0x1 << (16 + channel);
if (output_value)
bits |= 0x1 << (24 + channel);
} else
bits |= 0x1 << (24 + channel);
return bits;
}
uint32_t almost_full_bits(unsigned int num_words)
{
return (num_words << 16) & 0xff0000;
}
uint32_t almost_empty_bits(unsigned int num_words)
{
return num_words & 0xffff;
}
unsigned int almost_full_num_words(uint32_t bits)
{
return (bits >> 16) & 0xffff;
}
unsigned int almost_empty_num_words(uint32_t bits)
{
return bits & 0xffff;
}
int command_intr_source(unsigned int channel)
{
if (command_channel_valid(channel) == 0)
channel = 1;
return channel + 1;
}
uint32_t intr_bit(int interrupt_source)
{
return 0x1 << interrupt_source;
}
uint32_t tx_clock_divisor_bits(unsigned int divisor)
{
return divisor & 0xff;
}
unsigned int fifo_size(uint32_t fifo_size_bits)
{
return fifo_size_bits & 0xfffff;
}
unsigned int fifo_words(uint32_t fifo_words_bits)
{
return fifo_words_bits & 0xfffff;
}
uint32_t intr_edge_bit(int interrupt_source)
{
return 0x1 << interrupt_source;
}
uint32_t intr_active_high_bit(int interrupt_source)
{
return 0x1 << interrupt_source;
}
static inline struct hpdi_board *board(const struct comedi_device *dev)
{
return (struct hpdi_board *)dev->board_ptr;
}
static inline struct hpdi_private *priv(struct comedi_device *dev)
{
return dev->private;
}
static int dio_config_insn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
priv(dev)->dio_config_output = 1;
return insn->n;
break;
case INSN_CONFIG_DIO_INPUT:
priv(dev)->dio_config_output = 0;
return insn->n;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
priv(dev)->dio_config_output ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
case INSN_CONFIG_BLOCK_SIZE:
return dio_config_block_size(dev, data);
break;
default:
break;
}
return -EINVAL;
}
static void disable_plx_interrupts(struct comedi_device *dev)
{
writel(0, priv(dev)->plx9080_iobase + PLX_INTRCS_REG);
}
static void init_plx9080(struct comedi_device *dev)
{
uint32_t bits;
void __iomem *plx_iobase = priv(dev)->plx9080_iobase;
DEBUG_PRINT(" plx interrupt status 0x%x\n",
readl(plx_iobase + PLX_INTRCS_REG));
DEBUG_PRINT(" plx id bits 0x%x\n", readl(plx_iobase + PLX_ID_REG));
DEBUG_PRINT(" plx control reg 0x%x\n",
readl(priv(dev)->plx9080_iobase + PLX_CONTROL_REG));
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
writel(bits, priv(dev)->plx9080_iobase + PLX_BIGEND_REG);
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
uint32_t plx_intcsr_bits;
writel(BOARD_RESET_BIT, priv(dev)->hpdi_iobase + BOARD_CONTROL_REG);
udelay(10);
writel(almost_empty_bits(32) | almost_full_bits(32),
priv(dev)->hpdi_iobase + RX_PROG_ALMOST_REG);
writel(almost_empty_bits(32) | almost_full_bits(32),
priv(dev)->hpdi_iobase + TX_PROG_ALMOST_REG);
priv(dev)->tx_fifo_size = fifo_size(readl(priv(dev)->hpdi_iobase +
TX_FIFO_SIZE_REG));
priv(dev)->rx_fifo_size = fifo_size(readl(priv(dev)->hpdi_iobase +
RX_FIFO_SIZE_REG));
writel(0, priv(dev)->hpdi_iobase + INTERRUPT_CONTROL_REG);
plx_intcsr_bits =
ICS_AERR | ICS_PERR | ICS_PIE | ICS_PLIE | ICS_PAIE | ICS_LIE |
ICS_DMA0_E;
writel(plx_intcsr_bits, priv(dev)->plx9080_iobase + PLX_INTRCS_REG);
return 0;
}
static int setup_dma_descriptors(struct comedi_device *dev,
unsigned int transfer_size)
{
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
(unsigned long)priv(dev)->dma_desc_phys_addr);
buffer_offset = 0;
buffer_index = 0;
for (i = 0; i < NUM_DMA_DESCRIPTORS &&
buffer_index < NUM_DMA_BUFFERS; i++) {
priv(dev)->dma_desc[i].pci_start_addr =
cpu_to_le32(priv(dev)->dio_buffer_phys_addr[buffer_index] +
buffer_offset);
priv(dev)->dma_desc[i].local_start_addr = cpu_to_le32(FIFO_REG);
priv(dev)->dma_desc[i].transfer_size =
cpu_to_le32(transfer_size);
priv(dev)->dma_desc[i].next =
cpu_to_le32((priv(dev)->dma_desc_phys_addr + (i +
1) *
sizeof(priv(dev)->dma_desc[0])) | next_bits);
priv(dev)->desc_dio_buffer[i] =
priv(dev)->dio_buffer[buffer_index] +
(buffer_offset / sizeof(uint32_t));
buffer_offset += transfer_size;
if (transfer_size + buffer_offset > DMA_BUFFER_SIZE) {
buffer_offset = 0;
buffer_index++;
}
DEBUG_PRINT(" desc %i\n", i);
DEBUG_PRINT(" start addr virt 0x%p, phys 0x%lx\n",
priv(dev)->desc_dio_buffer[i],
(unsigned long)priv(dev)->dma_desc[i].
pci_start_addr);
DEBUG_PRINT(" next 0x%lx\n",
(unsigned long)priv(dev)->dma_desc[i].next);
}
priv(dev)->num_dma_descriptors = i;
priv(dev)->dma_desc[i - 1].next =
cpu_to_le32(priv(dev)->dma_desc_phys_addr | next_bits);
DEBUG_PRINT(" desc %i next fixup 0x%lx\n", i - 1,
(unsigned long)priv(dev)->dma_desc[i - 1].next);
priv(dev)->block_size = transfer_size;
return transfer_size;
}
static int hpdi_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct pci_dev *pcidev;
int i;
int retval;
printk(KERN_WARNING "comedi%d: gsc_hpdi\n", dev->minor);
if (alloc_private(dev, sizeof(struct hpdi_private)) < 0)
return -ENOMEM;
pcidev = NULL;
for (i = 0; i < ARRAY_SIZE(hpdi_boards) &&
dev->board_ptr == NULL; i++) {
do {
pcidev = pci_get_subsys(PCI_VENDOR_ID_PLX,
hpdi_boards[i].device_id,
PCI_VENDOR_ID_PLX,
hpdi_boards[i].subdevice_id,
pcidev);
if (it->options[0] || it->options[1]) {
if (pcidev->bus->number != it->options[0] ||
PCI_SLOT(pcidev->devfn) != it->options[1])
continue;
}
if (pcidev) {
priv(dev)->hw_dev = pcidev;
dev->board_ptr = hpdi_boards + i;
break;
}
} while (pcidev != NULL);
}
if (dev->board_ptr == NULL) {
printk(KERN_WARNING "gsc_hpdi: no hpdi card found\n");
return -EIO;
}
printk(KERN_WARNING
"gsc_hpdi: found %s on bus %i, slot %i\n", board(dev)->name,
pcidev->bus->number, PCI_SLOT(pcidev->devfn));
if (comedi_pci_enable(pcidev, dev->driver->driver_name)) {
printk(KERN_WARNING
" failed enable PCI device and request regions\n");
return -EIO;
}
pci_set_master(pcidev);
dev->board_name = board(dev)->name;
priv(dev)->plx9080_phys_iobase =
pci_resource_start(pcidev, PLX9080_BADDRINDEX);
priv(dev)->hpdi_phys_iobase =
pci_resource_start(pcidev, HPDI_BADDRINDEX);
priv(dev)->plx9080_iobase = ioremap(priv(dev)->plx9080_phys_iobase,
pci_resource_len(pcidev,
PLX9080_BADDRINDEX));
priv(dev)->hpdi_iobase =
ioremap(priv(dev)->hpdi_phys_iobase,
pci_resource_len(pcidev, HPDI_BADDRINDEX));
if (!priv(dev)->plx9080_iobase || !priv(dev)->hpdi_iobase) {
printk(KERN_WARNING " failed to remap io memory\n");
return -ENOMEM;
}
DEBUG_PRINT(" plx9080 remapped to 0x%p\n", priv(dev)->plx9080_iobase);
DEBUG_PRINT(" hpdi remapped to 0x%p\n", priv(dev)->hpdi_iobase);
init_plx9080(dev);
if (request_irq(pcidev->irq, handle_interrupt, IRQF_SHARED,
dev->driver->driver_name, dev)) {
printk(KERN_WARNING
" unable to allocate irq %u\n", pcidev->irq);
return -EINVAL;
}
dev->irq = pcidev->irq;
printk(KERN_WARNING " irq %u\n", dev->irq);
for (i = 0; i < NUM_DMA_BUFFERS; i++) {
priv(dev)->dio_buffer[i] =
pci_alloc_consistent(priv(dev)->hw_dev, DMA_BUFFER_SIZE,
&priv(dev)->dio_buffer_phys_addr[i]);
DEBUG_PRINT("dio_buffer at virt 0x%p, phys 0x%lx\n",
priv(dev)->dio_buffer[i],
(unsigned long)priv(dev)->dio_buffer_phys_addr[i]);
}
priv(dev)->dma_desc = pci_alloc_consistent(priv(dev)->hw_dev,
sizeof(struct plx_dma_desc) *
NUM_DMA_DESCRIPTORS,
&priv(dev)->
dma_desc_phys_addr);
if (priv(dev)->dma_desc_phys_addr & 0xf) {
printk(KERN_WARNING
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
unsigned int i;
if (dev->irq)
free_irq(dev->irq, dev);
if ((priv(dev)) && (priv(dev)->hw_dev)) {
if (priv(dev)->plx9080_iobase) {
disable_plx_interrupts(dev);
iounmap(priv(dev)->plx9080_iobase);
}
if (priv(dev)->hpdi_iobase)
iounmap(priv(dev)->hpdi_iobase);
for (i = 0; i < NUM_DMA_BUFFERS; i++) {
if (priv(dev)->dio_buffer[i])
pci_free_consistent(priv(dev)->hw_dev,
DMA_BUFFER_SIZE,
priv(dev)->
dio_buffer[i],
priv
(dev)->dio_buffer_phys_addr
[i]);
}
if (priv(dev)->dma_desc)
pci_free_consistent(priv(dev)->hw_dev,
sizeof(struct plx_dma_desc)
* NUM_DMA_DESCRIPTORS,
priv(dev)->dma_desc,
priv(dev)->
dma_desc_phys_addr);
if (priv(dev)->hpdi_phys_iobase)
comedi_pci_disable(priv(dev)->hw_dev);
pci_dev_put(priv(dev)->hw_dev);
}
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
err++;
}
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
switch (cmd->stop_src) {
case TRIG_COUNT:
if (!cmd->stop_arg) {
cmd->stop_arg = 1;
err++;
}
break;
case TRIG_NONE:
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
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
if (priv(dev)->dio_config_output)
return -EINVAL;
else
return di_cmd_test(dev, s, cmd);
}
static inline void hpdi_writel(struct comedi_device *dev, uint32_t bits,
unsigned int offset)
{
writel(bits | priv(dev)->bits[offset / sizeof(uint32_t)],
priv(dev)->hpdi_iobase + offset);
}
static int di_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
uint32_t bits;
unsigned long flags;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
hpdi_writel(dev, RX_FIFO_RESET_BIT, BOARD_CONTROL_REG);
DEBUG_PRINT("hpdi: in di_cmd\n");
abort_dma(dev, 0);
priv(dev)->dma_desc_index = 0;
writel(0, priv(dev)->plx9080_iobase + PLX_DMA0_TRANSFER_SIZE_REG);
writel(0, priv(dev)->plx9080_iobase + PLX_DMA0_PCI_ADDRESS_REG);
writel(0, priv(dev)->plx9080_iobase + PLX_DMA0_LOCAL_ADDRESS_REG);
bits =
priv(dev)->dma_desc_phys_addr | PLX_DESC_IN_PCI_BIT |
PLX_INTR_TERM_COUNT | PLX_XFER_LOCAL_TO_PCI;
writel(bits, priv(dev)->plx9080_iobase + PLX_DMA0_DESCRIPTOR_REG);
spin_lock_irqsave(&dev->spinlock, flags);
writeb(PLX_DMA_EN_BIT | PLX_DMA_START_BIT | PLX_CLEAR_DMA_INTR_BIT,
priv(dev)->plx9080_iobase + PLX_DMA0_CS_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
if (cmd->stop_src == TRIG_COUNT)
priv(dev)->dio_count = cmd->stop_arg;
else
priv(dev)->dio_count = 1;
writel(RX_UNDERRUN_BIT | RX_OVERRUN_BIT,
priv(dev)->hpdi_iobase + BOARD_STATUS_REG);
writel(intr_bit(RX_FULL_INTR),
priv(dev)->hpdi_iobase + INTERRUPT_CONTROL_REG);
DEBUG_PRINT("hpdi: starting rx\n");
hpdi_writel(dev, RX_ENABLE_BIT, BOARD_CONTROL_REG);
return 0;
}
static int hpdi_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
if (priv(dev)->dio_config_output)
return -EINVAL;
else
return di_cmd(dev, s);
}
static void drain_dma_buffers(struct comedi_device *dev, unsigned int channel)
{
struct comedi_async *async = dev->read_subdev->async;
uint32_t next_transfer_addr;
int j;
int num_samples = 0;
void __iomem *pci_addr_reg;
if (channel)
pci_addr_reg =
priv(dev)->plx9080_iobase + PLX_DMA1_PCI_ADDRESS_REG;
else
pci_addr_reg =
priv(dev)->plx9080_iobase + PLX_DMA0_PCI_ADDRESS_REG;
j = 0;
for (next_transfer_addr = readl(pci_addr_reg);
(next_transfer_addr <
le32_to_cpu(priv(dev)->dma_desc[priv(dev)->dma_desc_index].
pci_start_addr)
|| next_transfer_addr >=
le32_to_cpu(priv(dev)->dma_desc[priv(dev)->dma_desc_index].
pci_start_addr) + priv(dev)->block_size)
&& j < priv(dev)->num_dma_descriptors; j++) {
num_samples = priv(dev)->block_size / sizeof(uint32_t);
if (async->cmd.stop_src == TRIG_COUNT) {
if (num_samples > priv(dev)->dio_count)
num_samples = priv(dev)->dio_count;
priv(dev)->dio_count -= num_samples;
}
cfc_write_array_to_buffer(dev->read_subdev,
priv(dev)->desc_dio_buffer[priv(dev)->
dma_desc_index],
num_samples * sizeof(uint32_t));
priv(dev)->dma_desc_index++;
priv(dev)->dma_desc_index %= priv(dev)->num_dma_descriptors;
DEBUG_PRINT("next desc addr 0x%lx\n", (unsigned long)
priv(dev)->dma_desc[priv(dev)->dma_desc_index].
next);
DEBUG_PRINT("pci addr reg 0x%x\n", next_transfer_addr);
}
}
static irqreturn_t handle_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
uint32_t hpdi_intr_status, hpdi_board_status;
uint32_t plx_status;
uint32_t plx_bits;
uint8_t dma0_status, dma1_status;
unsigned long flags;
if (!dev->attached)
return IRQ_NONE;
plx_status = readl(priv(dev)->plx9080_iobase + PLX_INTRCS_REG);
if ((plx_status & (ICS_DMA0_A | ICS_DMA1_A | ICS_LIA)) == 0)
return IRQ_NONE;
hpdi_intr_status = readl(priv(dev)->hpdi_iobase + INTERRUPT_STATUS_REG);
hpdi_board_status = readl(priv(dev)->hpdi_iobase + BOARD_STATUS_REG);
async->events = 0;
if (hpdi_intr_status) {
DEBUG_PRINT("hpdi: intr status 0x%x, ", hpdi_intr_status);
writel(hpdi_intr_status,
priv(dev)->hpdi_iobase + INTERRUPT_STATUS_REG);
}
spin_lock_irqsave(&dev->spinlock, flags);
dma0_status = readb(priv(dev)->plx9080_iobase + PLX_DMA0_CS_REG);
if (plx_status & ICS_DMA0_A) {
writeb((dma0_status & PLX_DMA_EN_BIT) | PLX_CLEAR_DMA_INTR_BIT,
priv(dev)->plx9080_iobase + PLX_DMA0_CS_REG);
DEBUG_PRINT("dma0 status 0x%x\n", dma0_status);
if (dma0_status & PLX_DMA_EN_BIT)
drain_dma_buffers(dev, 0);
DEBUG_PRINT(" cleared dma ch0 interrupt\n");
}
spin_unlock_irqrestore(&dev->spinlock, flags);
spin_lock_irqsave(&dev->spinlock, flags);
dma1_status = readb(priv(dev)->plx9080_iobase + PLX_DMA1_CS_REG);
if (plx_status & ICS_DMA1_A) {
writeb((dma1_status & PLX_DMA_EN_BIT) | PLX_CLEAR_DMA_INTR_BIT,
priv(dev)->plx9080_iobase + PLX_DMA1_CS_REG);
DEBUG_PRINT("dma1 status 0x%x\n", dma1_status);
DEBUG_PRINT(" cleared dma ch1 interrupt\n");
}
spin_unlock_irqrestore(&dev->spinlock, flags);
if (plx_status & ICS_LDIA) {
plx_bits = readl(priv(dev)->plx9080_iobase + PLX_DBR_OUT_REG);
writel(plx_bits, priv(dev)->plx9080_iobase + PLX_DBR_OUT_REG);
DEBUG_PRINT(" cleared local doorbell bits 0x%x\n", plx_bits);
}
if (hpdi_board_status & RX_OVERRUN_BIT) {
comedi_error(dev, "rx fifo overrun");
async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
DEBUG_PRINT("dma0_status 0x%x\n",
(int)readb(priv(dev)->plx9080_iobase +
PLX_DMA0_CS_REG));
}
if (hpdi_board_status & RX_UNDERRUN_BIT) {
comedi_error(dev, "rx fifo underrun");
async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
}
if (priv(dev)->dio_count == 0)
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
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
plx9080_abort_dma(priv(dev)->plx9080_iobase, channel);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
static int hpdi_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
hpdi_writel(dev, 0, BOARD_CONTROL_REG);
writel(0, priv(dev)->hpdi_iobase + INTERRUPT_CONTROL_REG);
abort_dma(dev, 0);
return 0;
}
static int __devinit gsc_hpdi_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &gsc_hpdi_driver);
}
static void __devexit gsc_hpdi_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
