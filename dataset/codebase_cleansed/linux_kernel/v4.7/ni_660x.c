static void ni_660x_write(struct comedi_device *dev, unsigned int chip,
unsigned int bits, unsigned int reg)
{
unsigned int addr = (chip * NI660X_CHIP_OFFSET) +
ni_660x_reg_data[reg].offset;
if (ni_660x_reg_data[reg].size == 2)
writew(bits, dev->mmio + addr);
else
writel(bits, dev->mmio + addr);
}
static unsigned int ni_660x_read(struct comedi_device *dev,
unsigned int chip, unsigned int reg)
{
unsigned int addr = (chip * NI660X_CHIP_OFFSET) +
ni_660x_reg_data[reg].offset;
if (ni_660x_reg_data[reg].size == 2)
return readw(dev->mmio + addr);
return readl(dev->mmio + addr);
}
static void ni_660x_gpct_write(struct ni_gpct *counter, unsigned int bits,
enum ni_gpct_register reg)
{
struct comedi_device *dev = counter->counter_dev->dev;
ni_660x_write(dev, counter->chip_index, bits, reg);
}
static unsigned int ni_660x_gpct_read(struct ni_gpct *counter,
enum ni_gpct_register reg)
{
struct comedi_device *dev = counter->counter_dev->dev;
return ni_660x_read(dev, counter->chip_index, reg);
}
static inline void ni_660x_set_dma_channel(struct comedi_device *dev,
unsigned int mite_channel,
struct ni_gpct *counter)
{
struct ni_660x_private *devpriv = dev->private;
unsigned int chip = counter->chip_index;
devpriv->dma_cfg[chip] &= ~NI660X_DMA_CFG_SEL_MASK(mite_channel);
devpriv->dma_cfg[chip] |= NI660X_DMA_CFG_SEL(mite_channel,
counter->counter_index);
ni_660x_write(dev, chip, devpriv->dma_cfg[chip] |
NI660X_DMA_CFG_RESET(mite_channel),
NI660X_DMA_CFG);
mmiowb();
}
static inline void ni_660x_unset_dma_channel(struct comedi_device *dev,
unsigned int mite_channel,
struct ni_gpct *counter)
{
struct ni_660x_private *devpriv = dev->private;
unsigned int chip = counter->chip_index;
devpriv->dma_cfg[chip] &= ~NI660X_DMA_CFG_SEL_MASK(mite_channel);
devpriv->dma_cfg[chip] |= NI660X_DMA_CFG_SEL_NONE(mite_channel);
ni_660x_write(dev, chip, devpriv->dma_cfg[chip], NI660X_DMA_CFG);
mmiowb();
}
static int ni_660x_request_mite_channel(struct comedi_device *dev,
struct ni_gpct *counter,
enum comedi_io_direction direction)
{
struct ni_660x_private *devpriv = dev->private;
struct mite_ring *ring;
struct mite_channel *mite_chan;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
ring = devpriv->ring[counter->chip_index][counter->counter_index];
mite_chan = mite_request_channel(devpriv->mite, ring);
if (!mite_chan) {
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
dev_err(dev->class_dev,
"failed to reserve mite dma channel for counter\n");
return -EBUSY;
}
mite_chan->dir = direction;
ni_tio_set_mite_channel(counter, mite_chan);
ni_660x_set_dma_channel(dev, mite_chan->channel, counter);
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
return 0;
}
static void ni_660x_release_mite_channel(struct comedi_device *dev,
struct ni_gpct *counter)
{
struct ni_660x_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (counter->mite_chan) {
struct mite_channel *mite_chan = counter->mite_chan;
ni_660x_unset_dma_channel(dev, mite_chan->channel, counter);
ni_tio_set_mite_channel(counter, NULL);
mite_release_channel(mite_chan);
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
}
static int ni_660x_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct ni_gpct *counter = s->private;
int retval;
retval = ni_660x_request_mite_channel(dev, counter, COMEDI_INPUT);
if (retval) {
dev_err(dev->class_dev,
"no dma channel available for use by counter\n");
return retval;
}
ni_tio_acknowledge(counter);
return ni_tio_cmd(dev, s);
}
static int ni_660x_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct ni_gpct *counter = s->private;
int retval;
retval = ni_tio_cancel(counter);
ni_660x_release_mite_channel(dev, counter);
return retval;
}
static void set_tio_counterswap(struct comedi_device *dev, int chip)
{
unsigned int bits = 0;
if (chip)
bits = NI660X_CLK_CFG_COUNTER_SWAP;
ni_660x_write(dev, chip, bits, NI660X_CLK_CFG);
}
static void ni_660x_handle_gpct_interrupt(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_gpct *counter = s->private;
ni_tio_handle_interrupt(counter, s);
comedi_handle_events(dev, s);
}
static irqreturn_t ni_660x_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct ni_660x_private *devpriv = dev->private;
struct comedi_subdevice *s;
unsigned int i;
unsigned long flags;
if (!dev->attached)
return IRQ_NONE;
smp_mb();
spin_lock_irqsave(&devpriv->interrupt_lock, flags);
for (i = 0; i < dev->n_subdevices; ++i) {
s = &dev->subdevices[i];
if (s->type == COMEDI_SUBD_COUNTER)
ni_660x_handle_gpct_interrupt(dev, s);
}
spin_unlock_irqrestore(&devpriv->interrupt_lock, flags);
return IRQ_HANDLED;
}
static int ni_660x_input_poll(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_660x_private *devpriv = dev->private;
struct ni_gpct *counter = s->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->interrupt_lock, flags);
mite_sync_dma(counter->mite_chan, s);
spin_unlock_irqrestore(&devpriv->interrupt_lock, flags);
return comedi_buf_read_n_available(s);
}
static int ni_660x_buf_change(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_660x_private *devpriv = dev->private;
struct ni_gpct *counter = s->private;
struct mite_ring *ring;
int ret;
ring = devpriv->ring[counter->chip_index][counter->counter_index];
ret = mite_buf_change(ring, s);
if (ret < 0)
return ret;
return 0;
}
static int ni_660x_allocate_private(struct comedi_device *dev)
{
struct ni_660x_private *devpriv;
unsigned int i;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
spin_lock_init(&devpriv->mite_channel_lock);
spin_lock_init(&devpriv->interrupt_lock);
for (i = 0; i < NI660X_NUM_PFI_CHANNELS; ++i)
devpriv->io_cfg[i] = NI_660X_PFI_OUTPUT_COUNTER;
return 0;
}
static int ni_660x_alloc_mite_rings(struct comedi_device *dev)
{
const struct ni_660x_board *board = dev->board_ptr;
struct ni_660x_private *devpriv = dev->private;
unsigned int i;
unsigned int j;
for (i = 0; i < board->n_chips; ++i) {
for (j = 0; j < NI660X_COUNTERS_PER_CHIP; ++j) {
devpriv->ring[i][j] = mite_alloc_ring(devpriv->mite);
if (!devpriv->ring[i][j])
return -ENOMEM;
}
}
return 0;
}
static void ni_660x_free_mite_rings(struct comedi_device *dev)
{
const struct ni_660x_board *board = dev->board_ptr;
struct ni_660x_private *devpriv = dev->private;
unsigned int i;
unsigned int j;
for (i = 0; i < board->n_chips; ++i) {
for (j = 0; j < NI660X_COUNTERS_PER_CHIP; ++j)
mite_free_ring(devpriv->ring[i][j]);
}
}
static int ni_660x_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int shift = CR_CHAN(insn->chanspec);
unsigned int mask = data[0] << shift;
unsigned int bits = data[1] << shift;
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
ni_660x_write(dev, 0, s->state, NI660X_DIO32_OUTPUT);
}
data[1] = ni_660x_read(dev, 0, NI660X_DIO32_INPUT) >> shift;
return insn->n;
}
static void ni_660x_select_pfi_output(struct comedi_device *dev,
unsigned int chan, unsigned int out_sel)
{
const struct ni_660x_board *board = dev->board_ptr;
unsigned int active_chip = 0;
unsigned int idle_chip = 0;
unsigned int bits;
if (board->n_chips > 1) {
if (out_sel == NI_660X_PFI_OUTPUT_COUNTER &&
chan >= 8 && chan <= 23) {
active_chip = 1;
idle_chip = 0;
} else {
active_chip = 0;
idle_chip = 1;
}
}
if (idle_chip != active_chip) {
bits = ni_660x_read(dev, idle_chip, NI660X_IO_CFG(chan));
bits &= ~NI660X_IO_CFG_OUT_SEL_MASK(chan);
bits |= NI660X_IO_CFG_OUT_SEL(chan, 0);
ni_660x_write(dev, idle_chip, bits, NI660X_IO_CFG(chan));
}
bits = ni_660x_read(dev, active_chip, NI660X_IO_CFG(chan));
bits &= ~NI660X_IO_CFG_OUT_SEL_MASK(chan);
bits |= NI660X_IO_CFG_OUT_SEL(chan, out_sel);
ni_660x_write(dev, active_chip, bits, NI660X_IO_CFG(chan));
}
static int ni_660x_set_pfi_routing(struct comedi_device *dev,
unsigned int chan, unsigned int source)
{
struct ni_660x_private *devpriv = dev->private;
switch (source) {
case NI_660X_PFI_OUTPUT_COUNTER:
if (chan < 8)
return -EINVAL;
break;
case NI_660X_PFI_OUTPUT_DIO:
if (chan > 31)
return -EINVAL;
default:
return -EINVAL;
}
devpriv->io_cfg[chan] = source;
if (devpriv->io_dir & (1ULL << chan))
ni_660x_select_pfi_output(dev, chan, devpriv->io_cfg[chan]);
return 0;
}
static int ni_660x_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_660x_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
u64 bit = 1ULL << chan;
unsigned int val;
int ret;
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
devpriv->io_dir |= bit;
ni_660x_select_pfi_output(dev, chan, devpriv->io_cfg[chan]);
break;
case INSN_CONFIG_DIO_INPUT:
devpriv->io_dir &= ~bit;
ni_660x_select_pfi_output(dev, chan, 0);
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (devpriv->io_dir & bit) ? COMEDI_OUTPUT
: COMEDI_INPUT;
break;
case INSN_CONFIG_SET_ROUTING:
ret = ni_660x_set_pfi_routing(dev, chan, data[1]);
if (ret)
return ret;
break;
case INSN_CONFIG_GET_ROUTING:
data[1] = devpriv->io_cfg[chan];
break;
case INSN_CONFIG_FILTER:
val = ni_660x_read(dev, 0, NI660X_IO_CFG(chan));
val &= ~NI660X_IO_CFG_IN_SEL_MASK(chan);
val |= NI660X_IO_CFG_IN_SEL(chan, data[1]);
ni_660x_write(dev, 0, val, NI660X_IO_CFG(chan));
break;
default:
return -EINVAL;
}
return insn->n;
}
static void ni_660x_init_tio_chips(struct comedi_device *dev,
unsigned int n_chips)
{
struct ni_660x_private *devpriv = dev->private;
unsigned int chip;
unsigned int chan;
ni_660x_write(dev, 0, 0, NI660X_STC_DIO_CONTROL);
for (chip = 0; chip < n_chips; ++chip) {
devpriv->dma_cfg[chip] = 0;
for (chan = 0; chan < NI660X_MAX_DMA_CHANNEL; ++chan)
devpriv->dma_cfg[chip] |= NI660X_DMA_CFG_SEL_NONE(chan);
ni_660x_write(dev, chip, devpriv->dma_cfg[chip],
NI660X_DMA_CFG);
for (chan = 0; chan < NI660X_NUM_PFI_CHANNELS; ++chan)
ni_660x_write(dev, chip, 0, NI660X_IO_CFG(chan));
}
}
static int ni_660x_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct ni_660x_board *board = NULL;
struct ni_660x_private *devpriv;
struct comedi_subdevice *s;
struct ni_gpct_device *gpct_dev;
unsigned int n_counters;
int subdev;
int ret;
unsigned int i;
unsigned int global_interrupt_config_bits;
if (context < ARRAY_SIZE(ni_660x_boards))
board = &ni_660x_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
ret = ni_660x_allocate_private(dev);
if (ret < 0)
return ret;
devpriv = dev->private;
devpriv->mite = mite_attach(dev, true);
if (!devpriv->mite)
return -ENOMEM;
ret = ni_660x_alloc_mite_rings(dev);
if (ret < 0)
return ret;
ni_660x_init_tio_chips(dev, board->n_chips);
n_counters = board->n_chips * NI660X_COUNTERS_PER_CHIP;
gpct_dev = ni_gpct_device_construct(dev,
ni_660x_gpct_write,
ni_660x_gpct_read,
ni_gpct_variant_660x,
n_counters);
if (!gpct_dev)
return -ENOMEM;
devpriv->counter_dev = gpct_dev;
ret = comedi_alloc_subdevices(dev, 2 + NI660X_MAX_COUNTERS);
if (ret)
return ret;
subdev = 0;
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_UNUSED;
s = &dev->subdevices[subdev++];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = NI660X_NUM_PFI_CHANNELS;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni_660x_dio_insn_bits;
s->insn_config = ni_660x_dio_insn_config;
for (i = 0; i < s->n_chan; ++i) {
unsigned int source = (i < 8) ? NI_660X_PFI_OUTPUT_DIO
: NI_660X_PFI_OUTPUT_COUNTER;
ni_660x_set_pfi_routing(dev, i, source);
ni_660x_select_pfi_output(dev, i, 0);
}
for (i = 0; i < NI660X_MAX_COUNTERS; ++i) {
s = &dev->subdevices[subdev++];
if (i < n_counters) {
struct ni_gpct *counter = &gpct_dev->counters[i];
counter->chip_index = i / NI660X_COUNTERS_PER_CHIP;
counter->counter_index = i % NI660X_COUNTERS_PER_CHIP;
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE |
SDF_LSAMPL | SDF_CMD_READ;
s->n_chan = 3;
s->maxdata = 0xffffffff;
s->insn_read = ni_tio_insn_read;
s->insn_write = ni_tio_insn_write;
s->insn_config = ni_tio_insn_config;
s->len_chanlist = 1;
s->do_cmd = ni_660x_cmd;
s->do_cmdtest = ni_tio_cmdtest;
s->cancel = ni_660x_cancel;
s->poll = ni_660x_input_poll;
s->buf_change = ni_660x_buf_change;
s->async_dma_dir = DMA_BIDIRECTIONAL;
s->private = counter;
ni_tio_init_counter(counter);
} else {
s->type = COMEDI_SUBD_UNUSED;
}
}
for (i = 0; i < board->n_chips; ++i)
set_tio_counterswap(dev, i);
ret = request_irq(pcidev->irq, ni_660x_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret < 0) {
dev_warn(dev->class_dev, " irq not available\n");
return ret;
}
dev->irq = pcidev->irq;
global_interrupt_config_bits = NI660X_GLOBAL_INT_GLOBAL;
if (board->n_chips > 1)
global_interrupt_config_bits |= NI660X_GLOBAL_INT_CASCADE;
ni_660x_write(dev, 0, global_interrupt_config_bits,
NI660X_GLOBAL_INT_CFG);
return 0;
}
static void ni_660x_detach(struct comedi_device *dev)
{
struct ni_660x_private *devpriv = dev->private;
if (dev->irq) {
ni_660x_write(dev, 0, 0, NI660X_GLOBAL_INT_CFG);
free_irq(dev->irq, dev);
}
if (devpriv) {
ni_gpct_device_destroy(devpriv->counter_dev);
ni_660x_free_mite_rings(dev);
mite_detach(devpriv->mite);
}
if (dev->mmio)
iounmap(dev->mmio);
comedi_pci_disable(dev);
}
static int ni_660x_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &ni_660x_driver, id->driver_data);
}
