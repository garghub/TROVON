static inline unsigned primary_DMAChannel_bits(unsigned channel)
{
return channel & 0x3;
}
static inline unsigned secondary_DMAChannel_bits(unsigned channel)
{
return (channel << 2) & 0xc;
}
static int ni_pcidio_request_di_mite_channel(struct comedi_device *dev)
{
struct nidio96_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
BUG_ON(devpriv->di_mite_chan);
devpriv->di_mite_chan =
mite_request_channel_in_range(devpriv->mite,
devpriv->di_mite_ring, 1, 2);
if (devpriv->di_mite_chan == NULL) {
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
dev_err(dev->class_dev, "failed to reserve mite dma channel\n");
return -EBUSY;
}
devpriv->di_mite_chan->dir = COMEDI_INPUT;
writeb(primary_DMAChannel_bits(devpriv->di_mite_chan->channel) |
secondary_DMAChannel_bits(devpriv->di_mite_chan->channel),
dev->mmio + DMA_Line_Control_Group1);
mmiowb();
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
return 0;
}
static void ni_pcidio_release_di_mite_channel(struct comedi_device *dev)
{
struct nidio96_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->di_mite_chan) {
mite_dma_disarm(devpriv->di_mite_chan);
mite_dma_reset(devpriv->di_mite_chan);
mite_release_channel(devpriv->di_mite_chan);
devpriv->di_mite_chan = NULL;
writeb(primary_DMAChannel_bits(0) |
secondary_DMAChannel_bits(0),
dev->mmio + DMA_Line_Control_Group1);
mmiowb();
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
}
static int setup_mite_dma(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct nidio96_private *devpriv = dev->private;
int retval;
unsigned long flags;
retval = ni_pcidio_request_di_mite_channel(dev);
if (retval)
return retval;
comedi_buf_write_alloc(s, s->async->prealloc_bufsz);
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->di_mite_chan) {
mite_prep_dma(devpriv->di_mite_chan, 32, 32);
mite_dma_arm(devpriv->di_mite_chan);
} else
retval = -EIO;
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
return retval;
}
static int ni_pcidio_poll(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct nidio96_private *devpriv = dev->private;
unsigned long irq_flags;
int count;
spin_lock_irqsave(&dev->spinlock, irq_flags);
spin_lock(&devpriv->mite_channel_lock);
if (devpriv->di_mite_chan)
mite_sync_input_dma(devpriv->di_mite_chan, s);
spin_unlock(&devpriv->mite_channel_lock);
count = comedi_buf_n_bytes_ready(s);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
return count;
}
static irqreturn_t nidio_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct nidio96_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct mite_struct *mite = devpriv->mite;
unsigned int auxdata = 0;
unsigned short data1 = 0;
unsigned short data2 = 0;
int flags;
int status;
int work = 0;
unsigned int m_status = 0;
if (!dev->attached) {
return IRQ_NONE;
}
spin_lock(&dev->spinlock);
status = readb(dev->mmio + Interrupt_And_Window_Status);
flags = readb(dev->mmio + Group_1_Flags);
spin_lock(&devpriv->mite_channel_lock);
if (devpriv->di_mite_chan)
m_status = mite_get_status(devpriv->di_mite_chan);
if (m_status & CHSR_INT) {
if (m_status & CHSR_LINKC) {
writel(CHOR_CLRLC,
mite->mite_io_addr +
MITE_CHOR(devpriv->di_mite_chan->channel));
mite_sync_input_dma(devpriv->di_mite_chan, s);
}
if (m_status & ~(CHSR_INT | CHSR_LINKC | CHSR_DONE | CHSR_DRDY |
CHSR_DRQ1 | CHSR_MRDY)) {
dev_dbg(dev->class_dev,
"unknown mite interrupt, disabling IRQ\n");
async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
disable_irq(dev->irq);
}
}
spin_unlock(&devpriv->mite_channel_lock);
while (status & DataLeft) {
work++;
if (work > 20) {
dev_dbg(dev->class_dev, "too much work in interrupt\n");
writeb(0x00,
dev->mmio + Master_DMA_And_Interrupt_Control);
break;
}
flags &= IntEn;
if (flags & TransferReady) {
while (flags & TransferReady) {
work++;
if (work > 100) {
dev_dbg(dev->class_dev,
"too much work in interrupt\n");
writeb(0x00, dev->mmio +
Master_DMA_And_Interrupt_Control
);
goto out;
}
auxdata = readl(dev->mmio + Group_1_FIFO);
data1 = auxdata & 0xffff;
data2 = (auxdata & 0xffff0000) >> 16;
comedi_buf_put(s, data1);
comedi_buf_put(s, data2);
flags = readb(dev->mmio + Group_1_Flags);
}
async->events |= COMEDI_CB_BLOCK;
}
if (flags & CountExpired) {
writeb(ClearExpired, dev->mmio + Group_1_Second_Clear);
async->events |= COMEDI_CB_EOA;
writeb(0x00, dev->mmio + OpMode);
break;
} else if (flags & Waited) {
writeb(ClearWaited, dev->mmio + Group_1_First_Clear);
async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
break;
} else if (flags & PrimaryTC) {
writeb(ClearPrimaryTC,
dev->mmio + Group_1_First_Clear);
async->events |= COMEDI_CB_EOA;
} else if (flags & SecondaryTC) {
writeb(ClearSecondaryTC,
dev->mmio + Group_1_First_Clear);
async->events |= COMEDI_CB_EOA;
}
flags = readb(dev->mmio + Group_1_Flags);
status = readb(dev->mmio + Interrupt_And_Window_Status);
}
out:
cfc_handle_events(dev, s);
#if 0
if (!tag)
writeb(0x03, dev->mmio + Master_DMA_And_Interrupt_Control);
#endif
spin_unlock(&dev->spinlock);
return IRQ_HANDLED;
}
static int ni_pcidio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
writel(s->io_bits, dev->mmio + Port_Pin_Directions(0));
return insn->n;
}
static int ni_pcidio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
writel(s->state, dev->mmio + Port_IO(0));
data[1] = readl(dev->mmio + Port_IO(0));
return insn->n;
}
static int ni_pcidio_ns_to_timer(int *nanosec, unsigned int flags)
{
int divider, base;
base = TIMER_BASE;
switch (flags & TRIG_ROUND_MASK) {
case TRIG_ROUND_NEAREST:
default:
divider = (*nanosec + base / 2) / base;
break;
case TRIG_ROUND_DOWN:
divider = (*nanosec) / base;
break;
case TRIG_ROUND_UP:
divider = (*nanosec + base - 1) / base;
break;
}
*nanosec = base * divider;
return divider;
}
static int ni_pcidio_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_INT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
#define MAX_SPEED (TIMER_BASE)
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
MAX_SPEED);
} else {
if ((cmd->scan_begin_arg & ~(CR_EDGE | CR_INVERT)) != 0) {
cmd->scan_begin_arg &= (CR_EDGE | CR_INVERT);
err |= -EINVAL;
}
}
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT) {
} else {
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
}
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
ni_pcidio_ns_to_timer(&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (err)
return 4;
return 0;
}
static int ni_pcidio_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct nidio96_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
if (trig_num != cmd->start_arg)
return -EINVAL;
writeb(devpriv->OpModeBits, dev->mmio + OpMode);
s->async->inttrig = NULL;
return 1;
}
static int ni_pcidio_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct nidio96_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
writel(0x0000, dev->mmio + Port_Pin_Directions(0));
if (1) {
writeb(0x0f, dev->mmio + Data_Path);
writeb(TransferWidth(0) | TransferLength(0),
dev->mmio + Transfer_Size_Control);
} else {
writeb(0x03, dev->mmio + Data_Path);
writeb(TransferWidth(3) | TransferLength(0),
dev->mmio + Transfer_Size_Control);
}
if (cmd->scan_begin_src == TRIG_TIMER) {
writeb(0, dev->mmio + OpMode);
writeb(0x00, dev->mmio + ClockReg);
writeb(1, dev->mmio + Sequence);
writeb(0x04, dev->mmio + ReqReg);
writeb(4, dev->mmio + BlockMode);
writeb(3, dev->mmio + LinePolarities);
writeb(0xc0, dev->mmio + AckSer);
writel(ni_pcidio_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_NEAREST),
dev->mmio + StartDelay);
writeb(1, dev->mmio + ReqDelay);
writeb(1, dev->mmio + ReqNotDelay);
writeb(1, dev->mmio + AckDelay);
writeb(0x0b, dev->mmio + AckNotDelay);
writeb(0x01, dev->mmio + Data1Delay);
writew(0, dev->mmio + ClockSpeed);
writeb(0, dev->mmio + DAQOptions);
} else {
writeb(0, dev->mmio + OpMode);
writeb(0x00, dev->mmio + ClockReg);
writeb(0, dev->mmio + Sequence);
writeb(0x00, dev->mmio + ReqReg);
writeb(4, dev->mmio + BlockMode);
if (!(cmd->scan_begin_arg & CR_INVERT))
writeb(0, dev->mmio + LinePolarities);
else
writeb(2, dev->mmio + LinePolarities);
writeb(0x00, dev->mmio + AckSer);
writel(1, dev->mmio + StartDelay);
writeb(1, dev->mmio + ReqDelay);
writeb(1, dev->mmio + ReqNotDelay);
writeb(1, dev->mmio + AckDelay);
writeb(0x0C, dev->mmio + AckNotDelay);
writeb(0x10, dev->mmio + Data1Delay);
writew(0, dev->mmio + ClockSpeed);
writeb(0x60, dev->mmio + DAQOptions);
}
if (cmd->stop_src == TRIG_COUNT) {
writel(cmd->stop_arg,
dev->mmio + Transfer_Count);
} else {
}
#ifdef USE_DMA
writeb(ClearPrimaryTC | ClearSecondaryTC,
dev->mmio + Group_1_First_Clear);
{
int retval = setup_mite_dma(dev, s);
if (retval)
return retval;
}
#else
writeb(0x00, dev->mmio + DMA_Line_Control_Group1);
#endif
writeb(0x00, dev->mmio + DMA_Line_Control_Group2);
writeb(0xff, dev->mmio + Group_1_First_Clear);
writeb(IntEn, dev->mmio + Interrupt_Control);
writeb(0x03, dev->mmio + Master_DMA_And_Interrupt_Control);
if (cmd->stop_src == TRIG_NONE) {
devpriv->OpModeBits = DataLatching(0) | RunMode(7);
} else {
devpriv->OpModeBits = Numbered | RunMode(7);
}
if (cmd->start_src == TRIG_NOW) {
writeb(devpriv->OpModeBits, dev->mmio + OpMode);
s->async->inttrig = NULL;
} else {
s->async->inttrig = ni_pcidio_inttrig;
}
return 0;
}
static int ni_pcidio_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
writeb(0x00, dev->mmio + Master_DMA_And_Interrupt_Control);
ni_pcidio_release_di_mite_channel(dev);
return 0;
}
static int ni_pcidio_change(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct nidio96_private *devpriv = dev->private;
int ret;
ret = mite_buf_change(devpriv->di_mite_ring, s);
if (ret < 0)
return ret;
memset(s->async->prealloc_buf, 0xaa, s->async->prealloc_bufsz);
return 0;
}
static int pci_6534_load_fpga(struct comedi_device *dev,
const u8 *data, size_t data_len,
unsigned long context)
{
static const int timeout = 1000;
int fpga_index = context;
int i;
size_t j;
writew(0x80 | fpga_index, dev->mmio + Firmware_Control_Register);
writew(0xc0 | fpga_index, dev->mmio + Firmware_Control_Register);
for (i = 0;
(readw(dev->mmio + Firmware_Status_Register) & 0x2) == 0 &&
i < timeout; ++i) {
udelay(1);
}
if (i == timeout) {
dev_warn(dev->class_dev,
"ni_pcidio: failed to load fpga %i, waiting for status 0x2\n",
fpga_index);
return -EIO;
}
writew(0x80 | fpga_index, dev->mmio + Firmware_Control_Register);
for (i = 0;
readw(dev->mmio + Firmware_Status_Register) != 0x3 &&
i < timeout; ++i) {
udelay(1);
}
if (i == timeout) {
dev_warn(dev->class_dev,
"ni_pcidio: failed to load fpga %i, waiting for status 0x3\n",
fpga_index);
return -EIO;
}
for (j = 0; j + 1 < data_len;) {
unsigned int value = data[j++];
value |= data[j++] << 8;
writew(value, dev->mmio + Firmware_Data_Register);
for (i = 0;
(readw(dev->mmio + Firmware_Status_Register) & 0x2) == 0
&& i < timeout; ++i) {
udelay(1);
}
if (i == timeout) {
dev_warn(dev->class_dev,
"ni_pcidio: failed to load word into fpga %i\n",
fpga_index);
return -EIO;
}
if (need_resched())
schedule();
}
writew(0x0, dev->mmio + Firmware_Control_Register);
return 0;
}
static int pci_6534_reset_fpga(struct comedi_device *dev, int fpga_index)
{
return pci_6534_load_fpga(dev, NULL, 0, fpga_index);
}
static int pci_6534_reset_fpgas(struct comedi_device *dev)
{
int ret;
int i;
writew(0x0, dev->mmio + Firmware_Control_Register);
for (i = 0; i < 3; ++i) {
ret = pci_6534_reset_fpga(dev, i);
if (ret < 0)
break;
}
writew(0x0, dev->mmio + Firmware_Mask_Register);
return ret;
}
static void pci_6534_init_main_fpga(struct comedi_device *dev)
{
writel(0, dev->mmio + FPGA_Control1_Register);
writel(0, dev->mmio + FPGA_Control2_Register);
writel(0, dev->mmio + FPGA_SCALS_Counter_Register);
writel(0, dev->mmio + FPGA_SCAMS_Counter_Register);
writel(0, dev->mmio + FPGA_SCBLS_Counter_Register);
writel(0, dev->mmio + FPGA_SCBMS_Counter_Register);
}
static int pci_6534_upload_firmware(struct comedi_device *dev)
{
struct nidio96_private *devpriv = dev->private;
static const char *const fw_file[3] = {
FW_PCI_6534_SCARAB_DI,
FW_PCI_6534_SCARAB_DO,
FW_PCI_6534_MAIN,
};
int ret;
int n;
ret = pci_6534_reset_fpgas(dev);
if (ret < 0)
return ret;
for (n = 2; n >= 0; n--) {
ret = comedi_load_firmware(dev, &devpriv->mite->pcidev->dev,
fw_file[n],
pci_6534_load_fpga, n);
if (ret == 0 && n == 2)
pci_6534_init_main_fpga(dev);
if (ret < 0)
break;
}
return ret;
}
static void nidio_reset_board(struct comedi_device *dev)
{
writel(0, dev->mmio + Port_IO(0));
writel(0, dev->mmio + Port_Pin_Directions(0));
writel(0, dev->mmio + Port_Pin_Mask(0));
writeb(0, dev->mmio + Master_DMA_And_Interrupt_Control);
}
static int nidio_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct nidio_board *board = NULL;
struct nidio96_private *devpriv;
struct comedi_subdevice *s;
int ret;
unsigned int irq;
if (context < ARRAY_SIZE(nidio_boards))
board = &nidio_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
spin_lock_init(&devpriv->mite_channel_lock);
devpriv->mite = mite_alloc(pcidev);
if (!devpriv->mite)
return -ENOMEM;
ret = mite_setup(dev, devpriv->mite);
if (ret < 0)
return ret;
devpriv->di_mite_ring = mite_alloc_ring(devpriv->mite);
if (devpriv->di_mite_ring == NULL)
return -ENOMEM;
if (board->uses_firmware) {
ret = pci_6534_upload_firmware(dev);
if (ret < 0)
return ret;
}
nidio_reset_board(dev);
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
dev_info(dev->class_dev, "%s rev=%d\n", dev->board_name,
readb(dev->mmio + Chip_Version));
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags =
SDF_READABLE | SDF_WRITABLE | SDF_LSAMPL | SDF_PACKED |
SDF_CMD_READ;
s->n_chan = 32;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_config = &ni_pcidio_insn_config;
s->insn_bits = &ni_pcidio_insn_bits;
s->do_cmd = &ni_pcidio_cmd;
s->do_cmdtest = &ni_pcidio_cmdtest;
s->cancel = &ni_pcidio_cancel;
s->len_chanlist = 32;
s->buf_change = &ni_pcidio_change;
s->async_dma_dir = DMA_BIDIRECTIONAL;
s->poll = &ni_pcidio_poll;
irq = pcidev->irq;
if (irq) {
ret = request_irq(irq, nidio_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = irq;
}
return 0;
}
static void nidio_detach(struct comedi_device *dev)
{
struct nidio96_private *devpriv = dev->private;
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
if (devpriv->di_mite_ring) {
mite_free_ring(devpriv->di_mite_ring);
devpriv->di_mite_ring = NULL;
}
mite_detach(devpriv->mite);
}
if (dev->mmio)
iounmap(dev->mmio);
comedi_pci_disable(dev);
}
static int ni_pcidio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &ni_pcidio_driver, id->driver_data);
}
