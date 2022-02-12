static inline unsigned IOConfigReg(unsigned pfi_channel)
{
unsigned reg = NI660X_IO_CFG_0_1 + pfi_channel / 2;
BUG_ON(reg > NI660X_IO_CFG_38_39);
return reg;
}
static inline unsigned NI_660X_GPCT_SUBDEV(unsigned index)
{
return NI_660X_GPCT_SUBDEV_0 + index;
}
static inline unsigned ioconfig_bitshift(unsigned pfi_channel)
{
return (pfi_channel % 2) ? 0 : 8;
}
static inline unsigned pfi_output_select_mask(unsigned pfi_channel)
{
return 0x3 << ioconfig_bitshift(pfi_channel);
}
static inline unsigned pfi_output_select_bits(unsigned pfi_channel,
unsigned output_select)
{
return (output_select & 0x3) << ioconfig_bitshift(pfi_channel);
}
static inline unsigned pfi_input_select_mask(unsigned pfi_channel)
{
return 0x7 << (4 + ioconfig_bitshift(pfi_channel));
}
static inline unsigned pfi_input_select_bits(unsigned pfi_channel,
unsigned input_select)
{
return (input_select & 0x7) << (4 + ioconfig_bitshift(pfi_channel));
}
static inline unsigned dma_select_mask(unsigned dma_channel)
{
BUG_ON(dma_channel >= MAX_DMA_CHANNEL);
return 0x1f << (8 * dma_channel);
}
static inline unsigned dma_select_bits(unsigned dma_channel, unsigned selection)
{
BUG_ON(dma_channel >= MAX_DMA_CHANNEL);
return (selection << (8 * dma_channel)) & dma_select_mask(dma_channel);
}
static inline unsigned dma_reset_bit(unsigned dma_channel)
{
BUG_ON(dma_channel >= MAX_DMA_CHANNEL);
return 0x80 << (8 * dma_channel);
}
static inline unsigned ni_660x_num_counters(struct comedi_device *dev)
{
const struct ni_660x_board *board = comedi_board(dev);
return board->n_chips * counters_per_chip;
}
static enum ni_660x_register ni_gpct_to_660x_register(enum ni_gpct_register reg)
{
switch (reg) {
case NITIO_G0_AUTO_INC:
return NI660X_G0_AUTO_INC;
case NITIO_G1_AUTO_INC:
return NI660X_G1_AUTO_INC;
case NITIO_G2_AUTO_INC:
return NI660X_G2_AUTO_INC;
case NITIO_G3_AUTO_INC:
return NI660X_G3_AUTO_INC;
case NITIO_G0_CMD:
return NI660X_G0_CMD;
case NITIO_G1_CMD:
return NI660X_G1_CMD;
case NITIO_G2_CMD:
return NI660X_G2_CMD;
case NITIO_G3_CMD:
return NI660X_G3_CMD;
case NITIO_G0_HW_SAVE:
return NI660X_G0_HW_SAVE;
case NITIO_G1_HW_SAVE:
return NI660X_G1_HW_SAVE;
case NITIO_G2_HW_SAVE:
return NI660X_G2_HW_SAVE;
case NITIO_G3_HW_SAVE:
return NI660X_G3_HW_SAVE;
case NITIO_G0_SW_SAVE:
return NI660X_G0_SW_SAVE;
case NITIO_G1_SW_SAVE:
return NI660X_G1_SW_SAVE;
case NITIO_G2_SW_SAVE:
return NI660X_G2_SW_SAVE;
case NITIO_G3_SW_SAVE:
return NI660X_G3_SW_SAVE;
case NITIO_G0_MODE:
return NI660X_G0_MODE;
case NITIO_G1_MODE:
return NI660X_G1_MODE;
case NITIO_G2_MODE:
return NI660X_G2_MODE;
case NITIO_G3_MODE:
return NI660X_G3_MODE;
case NITIO_G0_LOADA:
return NI660X_G0_LOADA;
case NITIO_G1_LOADA:
return NI660X_G1_LOADA;
case NITIO_G2_LOADA:
return NI660X_G2_LOADA;
case NITIO_G3_LOADA:
return NI660X_G3_LOADA;
case NITIO_G0_LOADB:
return NI660X_G0_LOADB;
case NITIO_G1_LOADB:
return NI660X_G1_LOADB;
case NITIO_G2_LOADB:
return NI660X_G2_LOADB;
case NITIO_G3_LOADB:
return NI660X_G3_LOADB;
case NITIO_G0_INPUT_SEL:
return NI660X_G0_INPUT_SEL;
case NITIO_G1_INPUT_SEL:
return NI660X_G1_INPUT_SEL;
case NITIO_G2_INPUT_SEL:
return NI660X_G2_INPUT_SEL;
case NITIO_G3_INPUT_SEL:
return NI660X_G3_INPUT_SEL;
case NITIO_G01_STATUS:
return NI660X_G01_STATUS;
case NITIO_G23_STATUS:
return NI660X_G23_STATUS;
case NITIO_G01_RESET:
return NI660X_G01_RESET;
case NITIO_G23_RESET:
return NI660X_G23_RESET;
case NITIO_G01_STATUS1:
return NI660X_G01_STATUS1;
case NITIO_G23_STATUS1:
return NI660X_G23_STATUS1;
case NITIO_G01_STATUS2:
return NI660X_G01_STATUS2;
case NITIO_G23_STATUS2:
return NI660X_G23_STATUS2;
case NITIO_G0_CNT_MODE:
return NI660X_G0_CNT_MODE;
case NITIO_G1_CNT_MODE:
return NI660X_G1_CNT_MODE;
case NITIO_G2_CNT_MODE:
return NI660X_G2_CNT_MODE;
case NITIO_G3_CNT_MODE:
return NI660X_G3_CNT_MODE;
case NITIO_G0_GATE2:
return NI660X_G0_GATE2;
case NITIO_G1_GATE2:
return NI660X_G1_GATE2;
case NITIO_G2_GATE2:
return NI660X_G2_GATE2;
case NITIO_G3_GATE2:
return NI660X_G3_GATE2;
case NITIO_G0_DMA_CFG:
return NI660X_G0_DMA_CFG;
case NITIO_G0_DMA_STATUS:
return NI660X_G0_DMA_STATUS;
case NITIO_G1_DMA_CFG:
return NI660X_G1_DMA_CFG;
case NITIO_G1_DMA_STATUS:
return NI660X_G1_DMA_STATUS;
case NITIO_G2_DMA_CFG:
return NI660X_G2_DMA_CFG;
case NITIO_G2_DMA_STATUS:
return NI660X_G2_DMA_STATUS;
case NITIO_G3_DMA_CFG:
return NI660X_G3_DMA_CFG;
case NITIO_G3_DMA_STATUS:
return NI660X_G3_DMA_STATUS;
case NITIO_G0_INT_ACK:
return NI660X_G0_INT_ACK;
case NITIO_G1_INT_ACK:
return NI660X_G1_INT_ACK;
case NITIO_G2_INT_ACK:
return NI660X_G2_INT_ACK;
case NITIO_G3_INT_ACK:
return NI660X_G3_INT_ACK;
case NITIO_G0_STATUS:
return NI660X_G0_STATUS;
case NITIO_G1_STATUS:
return NI660X_G1_STATUS;
case NITIO_G2_STATUS:
return NI660X_G2_STATUS;
case NITIO_G3_STATUS:
return NI660X_G3_STATUS;
case NITIO_G0_INT_ENA:
return NI660X_G0_INT_ENA;
case NITIO_G1_INT_ENA:
return NI660X_G1_INT_ENA;
case NITIO_G2_INT_ENA:
return NI660X_G2_INT_ENA;
case NITIO_G3_INT_ENA:
return NI660X_G3_INT_ENA;
default:
BUG();
return 0;
}
}
static inline void ni_660x_write_register(struct comedi_device *dev,
unsigned chip, unsigned bits,
enum ni_660x_register reg)
{
unsigned int addr = GPCT_OFFSET[chip] + registerData[reg].offset;
switch (registerData[reg].size) {
case DATA_2B:
writew(bits, dev->mmio + addr);
break;
case DATA_4B:
writel(bits, dev->mmio + addr);
break;
default:
BUG();
break;
}
}
static inline unsigned ni_660x_read_register(struct comedi_device *dev,
unsigned chip,
enum ni_660x_register reg)
{
unsigned int addr = GPCT_OFFSET[chip] + registerData[reg].offset;
switch (registerData[reg].size) {
case DATA_2B:
return readw(dev->mmio + addr);
case DATA_4B:
return readl(dev->mmio + addr);
default:
BUG();
break;
}
return 0;
}
static void ni_gpct_write_register(struct ni_gpct *counter, unsigned bits,
enum ni_gpct_register reg)
{
struct comedi_device *dev = counter->counter_dev->dev;
enum ni_660x_register ni_660x_register = ni_gpct_to_660x_register(reg);
unsigned chip = counter->chip_index;
ni_660x_write_register(dev, chip, bits, ni_660x_register);
}
static unsigned ni_gpct_read_register(struct ni_gpct *counter,
enum ni_gpct_register reg)
{
struct comedi_device *dev = counter->counter_dev->dev;
enum ni_660x_register ni_660x_register = ni_gpct_to_660x_register(reg);
unsigned chip = counter->chip_index;
return ni_660x_read_register(dev, chip, ni_660x_register);
}
static inline struct mite_dma_descriptor_ring *mite_ring(struct ni_660x_private
*priv,
struct ni_gpct
*counter)
{
unsigned chip = counter->chip_index;
return priv->mite_rings[chip][counter->counter_index];
}
static inline void ni_660x_set_dma_channel(struct comedi_device *dev,
unsigned mite_channel,
struct ni_gpct *counter)
{
struct ni_660x_private *devpriv = dev->private;
unsigned chip = counter->chip_index;
unsigned long flags;
spin_lock_irqsave(&devpriv->soft_reg_copy_lock, flags);
devpriv->dma_configuration_soft_copies[chip] &=
~dma_select_mask(mite_channel);
devpriv->dma_configuration_soft_copies[chip] |=
dma_select_bits(mite_channel, counter->counter_index);
ni_660x_write_register(dev, chip,
devpriv->dma_configuration_soft_copies[chip] |
dma_reset_bit(mite_channel), NI660X_DMA_CFG);
mmiowb();
spin_unlock_irqrestore(&devpriv->soft_reg_copy_lock, flags);
}
static inline void ni_660x_unset_dma_channel(struct comedi_device *dev,
unsigned mite_channel,
struct ni_gpct *counter)
{
struct ni_660x_private *devpriv = dev->private;
unsigned chip = counter->chip_index;
unsigned long flags;
spin_lock_irqsave(&devpriv->soft_reg_copy_lock, flags);
devpriv->dma_configuration_soft_copies[chip] &=
~dma_select_mask(mite_channel);
devpriv->dma_configuration_soft_copies[chip] |=
dma_select_bits(mite_channel, dma_selection_none);
ni_660x_write_register(dev, chip,
devpriv->dma_configuration_soft_copies[chip],
NI660X_DMA_CFG);
mmiowb();
spin_unlock_irqrestore(&devpriv->soft_reg_copy_lock, flags);
}
static int ni_660x_request_mite_channel(struct comedi_device *dev,
struct ni_gpct *counter,
enum comedi_io_direction direction)
{
struct ni_660x_private *devpriv = dev->private;
unsigned long flags;
struct mite_channel *mite_chan;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
BUG_ON(counter->mite_chan);
mite_chan = mite_request_channel(devpriv->mite,
mite_ring(devpriv, counter));
if (mite_chan == NULL) {
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
unsigned bits = 0;
if (chip)
bits = CounterSwap;
ni_660x_write_register(dev, chip, bits, NI660X_CLK_CFG);
}
static void ni_660x_handle_gpct_interrupt(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_gpct *counter = s->private;
ni_tio_handle_interrupt(counter, s);
cfc_handle_events(dev, s);
}
static irqreturn_t ni_660x_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct ni_660x_private *devpriv = dev->private;
struct comedi_subdevice *s;
unsigned i;
unsigned long flags;
if (!dev->attached)
return IRQ_NONE;
spin_lock_irqsave(&devpriv->interrupt_lock, flags);
smp_mb();
for (i = 0; i < ni_660x_num_counters(dev); ++i) {
s = &dev->subdevices[NI_660X_GPCT_SUBDEV(i)];
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
mite_sync_input_dma(counter->mite_chan, s);
spin_unlock_irqrestore(&devpriv->interrupt_lock, flags);
return comedi_buf_read_n_available(s);
}
static int ni_660x_buf_change(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_660x_private *devpriv = dev->private;
struct ni_gpct *counter = s->private;
int ret;
ret = mite_buf_change(mite_ring(devpriv, counter), s);
if (ret < 0)
return ret;
return 0;
}
static int ni_660x_allocate_private(struct comedi_device *dev)
{
struct ni_660x_private *devpriv;
unsigned i;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
spin_lock_init(&devpriv->mite_channel_lock);
spin_lock_init(&devpriv->interrupt_lock);
spin_lock_init(&devpriv->soft_reg_copy_lock);
for (i = 0; i < NUM_PFI_CHANNELS; ++i)
devpriv->pfi_output_selects[i] = pfi_output_select_counter;
return 0;
}
static int ni_660x_alloc_mite_rings(struct comedi_device *dev)
{
const struct ni_660x_board *board = comedi_board(dev);
struct ni_660x_private *devpriv = dev->private;
unsigned i;
unsigned j;
for (i = 0; i < board->n_chips; ++i) {
for (j = 0; j < counters_per_chip; ++j) {
devpriv->mite_rings[i][j] =
mite_alloc_ring(devpriv->mite);
if (devpriv->mite_rings[i][j] == NULL)
return -ENOMEM;
}
}
return 0;
}
static void ni_660x_free_mite_rings(struct comedi_device *dev)
{
const struct ni_660x_board *board = comedi_board(dev);
struct ni_660x_private *devpriv = dev->private;
unsigned i;
unsigned j;
for (i = 0; i < board->n_chips; ++i) {
for (j = 0; j < counters_per_chip; ++j)
mite_free_ring(devpriv->mite_rings[i][j]);
}
}
static void init_tio_chip(struct comedi_device *dev, int chipset)
{
struct ni_660x_private *devpriv = dev->private;
unsigned i;
devpriv->dma_configuration_soft_copies[chipset] = 0;
for (i = 0; i < MAX_DMA_CHANNEL; ++i) {
devpriv->dma_configuration_soft_copies[chipset] |=
dma_select_bits(i, dma_selection_none) & dma_select_mask(i);
}
ni_660x_write_register(dev, chipset,
devpriv->dma_configuration_soft_copies[chipset],
NI660X_DMA_CFG);
for (i = 0; i < NUM_PFI_CHANNELS; ++i)
ni_660x_write_register(dev, chipset, 0, IOConfigReg(i));
}
static int ni_660x_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned base_bitfield_channel = CR_CHAN(insn->chanspec);
if (data[0]) {
s->state &= ~(data[0] << base_bitfield_channel);
s->state |= (data[0] & data[1]) << base_bitfield_channel;
ni_660x_write_register(dev, 0, s->state, NI660X_DIO32_OUTPUT);
}
data[1] = (ni_660x_read_register(dev, 0, NI660X_DIO32_INPUT) >>
base_bitfield_channel);
return insn->n;
}
static void ni_660x_select_pfi_output(struct comedi_device *dev,
unsigned pfi_channel,
unsigned output_select)
{
const struct ni_660x_board *board = comedi_board(dev);
static const unsigned counter_4_7_first_pfi = 8;
static const unsigned counter_4_7_last_pfi = 23;
unsigned active_chipset = 0;
unsigned idle_chipset = 0;
unsigned active_bits;
unsigned idle_bits;
if (board->n_chips > 1) {
if (output_select == pfi_output_select_counter &&
pfi_channel >= counter_4_7_first_pfi &&
pfi_channel <= counter_4_7_last_pfi) {
active_chipset = 1;
idle_chipset = 0;
} else {
active_chipset = 0;
idle_chipset = 1;
}
}
if (idle_chipset != active_chipset) {
idle_bits =
ni_660x_read_register(dev, idle_chipset,
IOConfigReg(pfi_channel));
idle_bits &= ~pfi_output_select_mask(pfi_channel);
idle_bits |=
pfi_output_select_bits(pfi_channel,
pfi_output_select_high_Z);
ni_660x_write_register(dev, idle_chipset, idle_bits,
IOConfigReg(pfi_channel));
}
active_bits =
ni_660x_read_register(dev, active_chipset,
IOConfigReg(pfi_channel));
active_bits &= ~pfi_output_select_mask(pfi_channel);
active_bits |= pfi_output_select_bits(pfi_channel, output_select);
ni_660x_write_register(dev, active_chipset, active_bits,
IOConfigReg(pfi_channel));
}
static int ni_660x_set_pfi_routing(struct comedi_device *dev, unsigned chan,
unsigned source)
{
struct ni_660x_private *devpriv = dev->private;
if (source > num_pfi_output_selects)
return -EINVAL;
if (source == pfi_output_select_high_Z)
return -EINVAL;
if (chan < min_counter_pfi_chan) {
if (source == pfi_output_select_counter)
return -EINVAL;
} else if (chan > max_dio_pfi_chan) {
if (source == pfi_output_select_do)
return -EINVAL;
}
devpriv->pfi_output_selects[chan] = source;
if (devpriv->pfi_direction_bits & (((uint64_t) 1) << chan))
ni_660x_select_pfi_output(dev, chan,
devpriv->pfi_output_selects[chan]);
return 0;
}
static int ni_660x_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_660x_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
uint64_t bit = 1ULL << chan;
unsigned int val;
int ret;
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
devpriv->pfi_direction_bits |= bit;
ni_660x_select_pfi_output(dev, chan,
devpriv->pfi_output_selects[chan]);
break;
case INSN_CONFIG_DIO_INPUT:
devpriv->pfi_direction_bits &= ~bit;
ni_660x_select_pfi_output(dev, chan, pfi_output_select_high_Z);
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (devpriv->pfi_direction_bits & bit) ? COMEDI_OUTPUT
: COMEDI_INPUT;
break;
case INSN_CONFIG_SET_ROUTING:
ret = ni_660x_set_pfi_routing(dev, chan, data[1]);
if (ret)
return ret;
break;
case INSN_CONFIG_GET_ROUTING:
data[1] = devpriv->pfi_output_selects[chan];
break;
case INSN_CONFIG_FILTER:
val = ni_660x_read_register(dev, 0, IOConfigReg(chan));
val &= ~pfi_input_select_mask(chan);
val |= pfi_input_select_bits(chan, data[1]);
ni_660x_write_register(dev, 0, val, IOConfigReg(chan));
break;
default:
return -EINVAL;
}
return insn->n;
}
static int ni_660x_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct ni_660x_board *board = NULL;
struct ni_660x_private *devpriv;
struct comedi_subdevice *s;
int ret;
unsigned i;
unsigned global_interrupt_config_bits;
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
devpriv->mite = mite_alloc(pcidev);
if (!devpriv->mite)
return -ENOMEM;
ret = mite_setup2(dev, devpriv->mite, true);
if (ret < 0)
return ret;
ret = ni_660x_alloc_mite_rings(dev);
if (ret < 0)
return ret;
ret = comedi_alloc_subdevices(dev, 2 + NI_660X_MAX_NUM_COUNTERS);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_UNUSED;
s = &dev->subdevices[NI_660X_DIO_SUBDEV];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = NUM_PFI_CHANNELS;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni_660x_dio_insn_bits;
s->insn_config = ni_660x_dio_insn_config;
ni_660x_write_register(dev, 0, 0, NI660X_STC_DIO_CONTROL);
devpriv->counter_dev = ni_gpct_device_construct(dev,
&ni_gpct_write_register,
&ni_gpct_read_register,
ni_gpct_variant_660x,
ni_660x_num_counters
(dev));
if (devpriv->counter_dev == NULL)
return -ENOMEM;
for (i = 0; i < NI_660X_MAX_NUM_COUNTERS; ++i) {
s = &dev->subdevices[NI_660X_GPCT_SUBDEV(i)];
if (i < ni_660x_num_counters(dev)) {
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE |
SDF_LSAMPL | SDF_CMD_READ;
s->n_chan = 3;
s->maxdata = 0xffffffff;
s->insn_read = ni_tio_insn_read;
s->insn_write = ni_tio_insn_write;
s->insn_config = ni_tio_insn_config;
s->do_cmd = &ni_660x_cmd;
s->len_chanlist = 1;
s->do_cmdtest = ni_tio_cmdtest;
s->cancel = &ni_660x_cancel;
s->poll = &ni_660x_input_poll;
s->async_dma_dir = DMA_BIDIRECTIONAL;
s->buf_change = &ni_660x_buf_change;
s->private = &devpriv->counter_dev->counters[i];
devpriv->counter_dev->counters[i].chip_index =
i / counters_per_chip;
devpriv->counter_dev->counters[i].counter_index =
i % counters_per_chip;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
}
for (i = 0; i < board->n_chips; ++i)
init_tio_chip(dev, i);
for (i = 0; i < ni_660x_num_counters(dev); ++i)
ni_tio_init_counter(&devpriv->counter_dev->counters[i]);
for (i = 0; i < NUM_PFI_CHANNELS; ++i) {
if (i < min_counter_pfi_chan)
ni_660x_set_pfi_routing(dev, i, pfi_output_select_do);
else
ni_660x_set_pfi_routing(dev, i,
pfi_output_select_counter);
ni_660x_select_pfi_output(dev, i, pfi_output_select_high_Z);
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
global_interrupt_config_bits = Global_Int_Enable_Bit;
if (board->n_chips > 1)
global_interrupt_config_bits |= Cascade_Int_Enable_Bit;
ni_660x_write_register(dev, 0, global_interrupt_config_bits,
NI660X_GLOBAL_INT_CFG);
return 0;
}
static void ni_660x_detach(struct comedi_device *dev)
{
struct ni_660x_private *devpriv = dev->private;
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
if (devpriv->counter_dev)
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
