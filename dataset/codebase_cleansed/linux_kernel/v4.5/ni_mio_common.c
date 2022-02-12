static inline unsigned NI_GPCT_SUBDEV(unsigned counter_index)
{
switch (counter_index) {
case 0:
return NI_GPCT0_SUBDEV;
case 1:
return NI_GPCT1_SUBDEV;
default:
break;
}
BUG();
return NI_GPCT0_SUBDEV;
}
static void ni_writel(struct comedi_device *dev, uint32_t data, int reg)
{
if (dev->mmio)
writel(data, dev->mmio + reg);
outl(data, dev->iobase + reg);
}
static void ni_writew(struct comedi_device *dev, uint16_t data, int reg)
{
if (dev->mmio)
writew(data, dev->mmio + reg);
outw(data, dev->iobase + reg);
}
static void ni_writeb(struct comedi_device *dev, uint8_t data, int reg)
{
if (dev->mmio)
writeb(data, dev->mmio + reg);
outb(data, dev->iobase + reg);
}
static uint32_t ni_readl(struct comedi_device *dev, int reg)
{
if (dev->mmio)
return readl(dev->mmio + reg);
return inl(dev->iobase + reg);
}
static uint16_t ni_readw(struct comedi_device *dev, int reg)
{
if (dev->mmio)
return readw(dev->mmio + reg);
return inw(dev->iobase + reg);
}
static uint8_t ni_readb(struct comedi_device *dev, int reg)
{
if (dev->mmio)
return readb(dev->mmio + reg);
return inb(dev->iobase + reg);
}
static void m_series_stc_write(struct comedi_device *dev,
unsigned int data, unsigned int reg)
{
const struct mio_regmap *regmap;
if (reg < ARRAY_SIZE(m_series_stc_write_regmap)) {
regmap = &m_series_stc_write_regmap[reg];
} else {
dev_warn(dev->class_dev, "%s: unhandled register=0x%x\n",
__func__, reg);
return;
}
switch (regmap->size) {
case 4:
ni_writel(dev, data, regmap->mio_reg);
break;
case 2:
ni_writew(dev, data, regmap->mio_reg);
break;
default:
dev_warn(dev->class_dev, "%s: unmapped register=0x%x\n",
__func__, reg);
break;
}
}
static unsigned int m_series_stc_read(struct comedi_device *dev,
unsigned int reg)
{
const struct mio_regmap *regmap;
if (reg < ARRAY_SIZE(m_series_stc_read_regmap)) {
regmap = &m_series_stc_read_regmap[reg];
} else {
dev_warn(dev->class_dev, "%s: unhandled register=0x%x\n",
__func__, reg);
return 0;
}
switch (regmap->size) {
case 4:
return ni_readl(dev, regmap->mio_reg);
case 2:
return ni_readw(dev, regmap->mio_reg);
case 1:
return ni_readb(dev, regmap->mio_reg);
default:
dev_warn(dev->class_dev, "%s: unmapped register=0x%x\n",
__func__, reg);
return 0;
}
}
static void ni_stc_writew(struct comedi_device *dev, uint16_t data, int reg)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
if (devpriv->is_m_series) {
m_series_stc_write(dev, data, reg);
} else {
spin_lock_irqsave(&devpriv->window_lock, flags);
if (!devpriv->mite && reg < 8) {
ni_writew(dev, data, reg * 2);
} else {
ni_writew(dev, reg, NI_E_STC_WINDOW_ADDR_REG);
ni_writew(dev, data, NI_E_STC_WINDOW_DATA_REG);
}
spin_unlock_irqrestore(&devpriv->window_lock, flags);
}
}
static void ni_stc_writel(struct comedi_device *dev, uint32_t data, int reg)
{
struct ni_private *devpriv = dev->private;
if (devpriv->is_m_series) {
m_series_stc_write(dev, data, reg);
} else {
ni_stc_writew(dev, data >> 16, reg);
ni_stc_writew(dev, data & 0xffff, reg + 1);
}
}
static uint16_t ni_stc_readw(struct comedi_device *dev, int reg)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
uint16_t val;
if (devpriv->is_m_series) {
val = m_series_stc_read(dev, reg);
} else {
spin_lock_irqsave(&devpriv->window_lock, flags);
if (!devpriv->mite && reg < 8) {
val = ni_readw(dev, reg * 2);
} else {
ni_writew(dev, reg, NI_E_STC_WINDOW_ADDR_REG);
val = ni_readw(dev, NI_E_STC_WINDOW_DATA_REG);
}
spin_unlock_irqrestore(&devpriv->window_lock, flags);
}
return val;
}
static uint32_t ni_stc_readl(struct comedi_device *dev, int reg)
{
struct ni_private *devpriv = dev->private;
uint32_t val;
if (devpriv->is_m_series) {
val = m_series_stc_read(dev, reg);
} else {
val = ni_stc_readw(dev, reg) << 16;
val |= ni_stc_readw(dev, reg + 1);
}
return val;
}
static inline void ni_set_bitfield(struct comedi_device *dev, int reg,
unsigned bit_mask, unsigned bit_values)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->soft_reg_copy_lock, flags);
switch (reg) {
case NISTC_INTA_ENA_REG:
devpriv->int_a_enable_reg &= ~bit_mask;
devpriv->int_a_enable_reg |= bit_values & bit_mask;
ni_stc_writew(dev, devpriv->int_a_enable_reg, reg);
break;
case NISTC_INTB_ENA_REG:
devpriv->int_b_enable_reg &= ~bit_mask;
devpriv->int_b_enable_reg |= bit_values & bit_mask;
ni_stc_writew(dev, devpriv->int_b_enable_reg, reg);
break;
case NISTC_IO_BIDIR_PIN_REG:
devpriv->io_bidirection_pin_reg &= ~bit_mask;
devpriv->io_bidirection_pin_reg |= bit_values & bit_mask;
ni_stc_writew(dev, devpriv->io_bidirection_pin_reg, reg);
break;
case NI_E_DMA_AI_AO_SEL_REG:
devpriv->ai_ao_select_reg &= ~bit_mask;
devpriv->ai_ao_select_reg |= bit_values & bit_mask;
ni_writeb(dev, devpriv->ai_ao_select_reg, reg);
break;
case NI_E_DMA_G0_G1_SEL_REG:
devpriv->g0_g1_select_reg &= ~bit_mask;
devpriv->g0_g1_select_reg |= bit_values & bit_mask;
ni_writeb(dev, devpriv->g0_g1_select_reg, reg);
break;
default:
dev_err(dev->class_dev, "called with invalid register %d\n",
reg);
break;
}
mmiowb();
spin_unlock_irqrestore(&devpriv->soft_reg_copy_lock, flags);
}
static inline unsigned ni_stc_dma_channel_select_bitfield(unsigned channel)
{
if (channel < 4)
return 1 << channel;
if (channel == 4)
return 0x3;
if (channel == 5)
return 0x5;
BUG();
return 0;
}
static inline void ni_set_ai_dma_channel(struct comedi_device *dev,
unsigned channel)
{
unsigned bits = ni_stc_dma_channel_select_bitfield(channel);
ni_set_bitfield(dev, NI_E_DMA_AI_AO_SEL_REG,
NI_E_DMA_AI_SEL_MASK, NI_E_DMA_AI_SEL(bits));
}
static inline void ni_set_ai_dma_no_channel(struct comedi_device *dev)
{
ni_set_bitfield(dev, NI_E_DMA_AI_AO_SEL_REG, NI_E_DMA_AI_SEL_MASK, 0);
}
static inline void ni_set_ao_dma_channel(struct comedi_device *dev,
unsigned channel)
{
unsigned bits = ni_stc_dma_channel_select_bitfield(channel);
ni_set_bitfield(dev, NI_E_DMA_AI_AO_SEL_REG,
NI_E_DMA_AO_SEL_MASK, NI_E_DMA_AO_SEL(bits));
}
static inline void ni_set_ao_dma_no_channel(struct comedi_device *dev)
{
ni_set_bitfield(dev, NI_E_DMA_AI_AO_SEL_REG, NI_E_DMA_AO_SEL_MASK, 0);
}
static inline void ni_set_gpct_dma_channel(struct comedi_device *dev,
unsigned gpct_index,
unsigned channel)
{
unsigned bits = ni_stc_dma_channel_select_bitfield(channel);
ni_set_bitfield(dev, NI_E_DMA_G0_G1_SEL_REG,
NI_E_DMA_G0_G1_SEL_MASK(gpct_index),
NI_E_DMA_G0_G1_SEL(gpct_index, bits));
}
static inline void ni_set_gpct_dma_no_channel(struct comedi_device *dev,
unsigned gpct_index)
{
ni_set_bitfield(dev, NI_E_DMA_G0_G1_SEL_REG,
NI_E_DMA_G0_G1_SEL_MASK(gpct_index), 0);
}
static inline void ni_set_cdo_dma_channel(struct comedi_device *dev,
unsigned mite_channel)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
unsigned bits;
spin_lock_irqsave(&devpriv->soft_reg_copy_lock, flags);
devpriv->cdio_dma_select_reg &= ~NI_M_CDIO_DMA_SEL_CDO_MASK;
bits = ni_stc_dma_channel_select_bitfield(mite_channel);
devpriv->cdio_dma_select_reg |= NI_M_CDIO_DMA_SEL_CDO(bits);
ni_writeb(dev, devpriv->cdio_dma_select_reg, NI_M_CDIO_DMA_SEL_REG);
mmiowb();
spin_unlock_irqrestore(&devpriv->soft_reg_copy_lock, flags);
}
static inline void ni_set_cdo_dma_no_channel(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->soft_reg_copy_lock, flags);
devpriv->cdio_dma_select_reg &= ~NI_M_CDIO_DMA_SEL_CDO_MASK;
ni_writeb(dev, devpriv->cdio_dma_select_reg, NI_M_CDIO_DMA_SEL_REG);
mmiowb();
spin_unlock_irqrestore(&devpriv->soft_reg_copy_lock, flags);
}
static int ni_request_ai_mite_channel(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
BUG_ON(devpriv->ai_mite_chan);
devpriv->ai_mite_chan =
mite_request_channel(devpriv->mite, devpriv->ai_mite_ring);
if (!devpriv->ai_mite_chan) {
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
dev_err(dev->class_dev,
"failed to reserve mite dma channel for analog input\n");
return -EBUSY;
}
devpriv->ai_mite_chan->dir = COMEDI_INPUT;
ni_set_ai_dma_channel(dev, devpriv->ai_mite_chan->channel);
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
return 0;
}
static int ni_request_ao_mite_channel(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
BUG_ON(devpriv->ao_mite_chan);
devpriv->ao_mite_chan =
mite_request_channel(devpriv->mite, devpriv->ao_mite_ring);
if (!devpriv->ao_mite_chan) {
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
dev_err(dev->class_dev,
"failed to reserve mite dma channel for analog outut\n");
return -EBUSY;
}
devpriv->ao_mite_chan->dir = COMEDI_OUTPUT;
ni_set_ao_dma_channel(dev, devpriv->ao_mite_chan->channel);
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
return 0;
}
static int ni_request_gpct_mite_channel(struct comedi_device *dev,
unsigned gpct_index,
enum comedi_io_direction direction)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
struct mite_channel *mite_chan;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
BUG_ON(devpriv->counter_dev->counters[gpct_index].mite_chan);
mite_chan =
mite_request_channel(devpriv->mite,
devpriv->gpct_mite_ring[gpct_index]);
if (!mite_chan) {
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
dev_err(dev->class_dev,
"failed to reserve mite dma channel for counter\n");
return -EBUSY;
}
mite_chan->dir = direction;
ni_tio_set_mite_channel(&devpriv->counter_dev->counters[gpct_index],
mite_chan);
ni_set_gpct_dma_channel(dev, gpct_index, mite_chan->channel);
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
return 0;
}
static int ni_request_cdo_mite_channel(struct comedi_device *dev)
{
#ifdef PCIDMA
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
BUG_ON(devpriv->cdo_mite_chan);
devpriv->cdo_mite_chan =
mite_request_channel(devpriv->mite, devpriv->cdo_mite_ring);
if (!devpriv->cdo_mite_chan) {
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
dev_err(dev->class_dev,
"failed to reserve mite dma channel for correlated digital output\n");
return -EBUSY;
}
devpriv->cdo_mite_chan->dir = COMEDI_OUTPUT;
ni_set_cdo_dma_channel(dev, devpriv->cdo_mite_chan->channel);
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
#endif
return 0;
}
static void ni_release_ai_mite_channel(struct comedi_device *dev)
{
#ifdef PCIDMA
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->ai_mite_chan) {
ni_set_ai_dma_no_channel(dev);
mite_release_channel(devpriv->ai_mite_chan);
devpriv->ai_mite_chan = NULL;
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
#endif
}
static void ni_release_ao_mite_channel(struct comedi_device *dev)
{
#ifdef PCIDMA
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->ao_mite_chan) {
ni_set_ao_dma_no_channel(dev);
mite_release_channel(devpriv->ao_mite_chan);
devpriv->ao_mite_chan = NULL;
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
#endif
}
static void ni_release_gpct_mite_channel(struct comedi_device *dev,
unsigned gpct_index)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->counter_dev->counters[gpct_index].mite_chan) {
struct mite_channel *mite_chan =
devpriv->counter_dev->counters[gpct_index].mite_chan;
ni_set_gpct_dma_no_channel(dev, gpct_index);
ni_tio_set_mite_channel(&devpriv->
counter_dev->counters[gpct_index],
NULL);
mite_release_channel(mite_chan);
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
}
static void ni_release_cdo_mite_channel(struct comedi_device *dev)
{
#ifdef PCIDMA
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->cdo_mite_chan) {
ni_set_cdo_dma_no_channel(dev);
mite_release_channel(devpriv->cdo_mite_chan);
devpriv->cdo_mite_chan = NULL;
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
#endif
}
static void ni_e_series_enable_second_irq(struct comedi_device *dev,
unsigned gpct_index, short enable)
{
struct ni_private *devpriv = dev->private;
uint16_t val = 0;
int reg;
if (devpriv->is_m_series || gpct_index > 1)
return;
if (gpct_index == 0) {
reg = NISTC_INTA2_ENA_REG;
if (enable)
val = NISTC_INTA_ENA_G0_GATE;
} else {
reg = NISTC_INTB2_ENA_REG;
if (enable)
val = NISTC_INTB_ENA_G1_GATE;
}
ni_stc_writew(dev, val, reg);
}
static void ni_clear_ai_fifo(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
static const int timeout = 10000;
int i;
if (devpriv->is_6143) {
ni_writel(dev, 0x10, NI6143_AI_FIFO_CTRL_REG);
ni_writel(dev, 0x00, NI6143_AI_FIFO_CTRL_REG);
for (i = 0; i < timeout; i++) {
if (!(ni_readl(dev, NI6143_AI_FIFO_STATUS_REG) & 0x10))
break;
udelay(1);
}
if (i == timeout)
dev_err(dev->class_dev, "FIFO flush timeout\n");
} else {
ni_stc_writew(dev, 1, NISTC_ADC_FIFO_CLR_REG);
if (devpriv->is_625x) {
ni_writeb(dev, 0, NI_M_STATIC_AI_CTRL_REG(0));
ni_writeb(dev, 1, NI_M_STATIC_AI_CTRL_REG(0));
#if 0
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
#endif
}
}
}
static inline void ni_ao_win_outw(struct comedi_device *dev, uint16_t data,
int addr)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->window_lock, flags);
ni_writew(dev, addr, NI611X_AO_WINDOW_ADDR_REG);
ni_writew(dev, data, NI611X_AO_WINDOW_DATA_REG);
spin_unlock_irqrestore(&devpriv->window_lock, flags);
}
static inline void ni_ao_win_outl(struct comedi_device *dev, uint32_t data,
int addr)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&devpriv->window_lock, flags);
ni_writew(dev, addr, NI611X_AO_WINDOW_ADDR_REG);
ni_writel(dev, data, NI611X_AO_WINDOW_DATA_REG);
spin_unlock_irqrestore(&devpriv->window_lock, flags);
}
static inline unsigned short ni_ao_win_inw(struct comedi_device *dev, int addr)
{
struct ni_private *devpriv = dev->private;
unsigned long flags;
unsigned short data;
spin_lock_irqsave(&devpriv->window_lock, flags);
ni_writew(dev, addr, NI611X_AO_WINDOW_ADDR_REG);
data = ni_readw(dev, NI611X_AO_WINDOW_DATA_REG);
spin_unlock_irqrestore(&devpriv->window_lock, flags);
return data;
}
static inline void ni_set_bits(struct comedi_device *dev, int reg,
unsigned bits, unsigned value)
{
unsigned bit_values;
if (value)
bit_values = bits;
else
bit_values = 0;
ni_set_bitfield(dev, reg, bits, bit_values);
}
static void ni_sync_ai_dma(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->ai_mite_chan)
mite_sync_input_dma(devpriv->ai_mite_chan, s);
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
}
static int ni_ai_drain_dma(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
int i;
static const int timeout = 10000;
unsigned long flags;
int retval = 0;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->ai_mite_chan) {
for (i = 0; i < timeout; i++) {
if ((ni_stc_readw(dev, NISTC_AI_STATUS1_REG) &
NISTC_AI_STATUS1_FIFO_E)
&& mite_bytes_in_transit(devpriv->ai_mite_chan) ==
0)
break;
udelay(5);
}
if (i == timeout) {
dev_err(dev->class_dev, "timed out\n");
dev_err(dev->class_dev,
"mite_bytes_in_transit=%i, AI_Status1_Register=0x%x\n",
mite_bytes_in_transit(devpriv->ai_mite_chan),
ni_stc_readw(dev, NISTC_AI_STATUS1_REG));
retval = -1;
}
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
ni_sync_ai_dma(dev);
return retval;
}
static void mite_handle_b_linkc(struct mite_struct *mite,
struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->write_subdev;
unsigned long flags;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->ao_mite_chan)
mite_sync_output_dma(devpriv->ao_mite_chan, s);
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
}
static int ni_ao_wait_for_dma_load(struct comedi_device *dev)
{
static const int timeout = 10000;
int i;
for (i = 0; i < timeout; i++) {
unsigned short b_status;
b_status = ni_stc_readw(dev, NISTC_AO_STATUS1_REG);
if (b_status & NISTC_AO_STATUS1_FIFO_HF)
break;
udelay(10);
}
if (i == timeout) {
dev_err(dev->class_dev, "timed out waiting for dma load\n");
return -EPIPE;
}
return 0;
}
static void ni_ao_fifo_load(struct comedi_device *dev,
struct comedi_subdevice *s, int n)
{
struct ni_private *devpriv = dev->private;
int i;
unsigned short d;
u32 packed_data;
for (i = 0; i < n; i++) {
comedi_buf_read_samples(s, &d, 1);
if (devpriv->is_6xxx) {
packed_data = d & 0xffff;
if (!devpriv->is_6711) {
comedi_buf_read_samples(s, &d, 1);
i++;
packed_data |= (d << 16) & 0xffff0000;
}
ni_writel(dev, packed_data, NI611X_AO_FIFO_DATA_REG);
} else {
ni_writew(dev, d, NI_E_AO_FIFO_DATA_REG);
}
}
}
static int ni_ao_fifo_half_empty(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct ni_board_struct *board = dev->board_ptr;
unsigned int nbytes;
unsigned int nsamples;
nbytes = comedi_buf_read_n_available(s);
if (nbytes == 0) {
s->async->events |= COMEDI_CB_OVERFLOW;
return 0;
}
nsamples = comedi_bytes_to_samples(s, nbytes);
if (nsamples > board->ao_fifo_depth / 2)
nsamples = board->ao_fifo_depth / 2;
ni_ao_fifo_load(dev, s, nsamples);
return 1;
}
static int ni_ao_prep_fifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
unsigned int nbytes;
unsigned int nsamples;
ni_stc_writew(dev, 1, NISTC_DAC_FIFO_CLR_REG);
if (devpriv->is_6xxx)
ni_ao_win_outl(dev, 0x6, NI611X_AO_FIFO_OFFSET_LOAD_REG);
nbytes = comedi_buf_read_n_available(s);
if (nbytes == 0)
return 0;
nsamples = comedi_bytes_to_samples(s, nbytes);
if (nsamples > board->ao_fifo_depth)
nsamples = board->ao_fifo_depth;
ni_ao_fifo_load(dev, s, nsamples);
return nsamples;
}
static void ni_ai_fifo_read(struct comedi_device *dev,
struct comedi_subdevice *s, int n)
{
struct ni_private *devpriv = dev->private;
struct comedi_async *async = s->async;
u32 dl;
unsigned short data;
int i;
if (devpriv->is_611x) {
for (i = 0; i < n / 2; i++) {
dl = ni_readl(dev, NI611X_AI_FIFO_DATA_REG);
data = (dl >> 16) & 0xffff;
comedi_buf_write_samples(s, &data, 1);
data = dl & 0xffff;
comedi_buf_write_samples(s, &data, 1);
}
if (n % 2) {
dl = ni_readl(dev, NI611X_AI_FIFO_DATA_REG);
data = dl & 0xffff;
comedi_buf_write_samples(s, &data, 1);
}
} else if (devpriv->is_6143) {
for (i = 0; i < n / 2; i++) {
dl = ni_readl(dev, NI6143_AI_FIFO_DATA_REG);
data = (dl >> 16) & 0xffff;
comedi_buf_write_samples(s, &data, 1);
data = dl & 0xffff;
comedi_buf_write_samples(s, &data, 1);
}
if (n % 2) {
ni_writel(dev, 0x01, NI6143_AI_FIFO_CTRL_REG);
dl = ni_readl(dev, NI6143_AI_FIFO_DATA_REG);
data = (dl >> 16) & 0xffff;
comedi_buf_write_samples(s, &data, 1);
}
} else {
if (n > sizeof(devpriv->ai_fifo_buffer) /
sizeof(devpriv->ai_fifo_buffer[0])) {
dev_err(dev->class_dev,
"bug! ai_fifo_buffer too small\n");
async->events |= COMEDI_CB_ERROR;
return;
}
for (i = 0; i < n; i++) {
devpriv->ai_fifo_buffer[i] =
ni_readw(dev, NI_E_AI_FIFO_DATA_REG);
}
comedi_buf_write_samples(s, devpriv->ai_fifo_buffer, n);
}
}
static void ni_handle_fifo_half_full(struct comedi_device *dev)
{
const struct ni_board_struct *board = dev->board_ptr;
struct comedi_subdevice *s = dev->read_subdev;
int n;
n = board->ai_fifo_depth / 2;
ni_ai_fifo_read(dev, s, n);
}
static void ni_handle_fifo_dregs(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
u32 dl;
unsigned short data;
unsigned short fifo_empty;
int i;
if (devpriv->is_611x) {
while ((ni_stc_readw(dev, NISTC_AI_STATUS1_REG) &
NISTC_AI_STATUS1_FIFO_E) == 0) {
dl = ni_readl(dev, NI611X_AI_FIFO_DATA_REG);
data = dl >> 16;
comedi_buf_write_samples(s, &data, 1);
data = dl & 0xffff;
comedi_buf_write_samples(s, &data, 1);
}
} else if (devpriv->is_6143) {
i = 0;
while (ni_readl(dev, NI6143_AI_FIFO_STATUS_REG) & 0x04) {
dl = ni_readl(dev, NI6143_AI_FIFO_DATA_REG);
data = dl >> 16;
comedi_buf_write_samples(s, &data, 1);
data = dl & 0xffff;
comedi_buf_write_samples(s, &data, 1);
i += 2;
}
if (ni_readl(dev, NI6143_AI_FIFO_STATUS_REG) & 0x01) {
ni_writel(dev, 0x01, NI6143_AI_FIFO_CTRL_REG);
dl = ni_readl(dev, NI6143_AI_FIFO_DATA_REG);
data = (dl >> 16) & 0xffff;
comedi_buf_write_samples(s, &data, 1);
}
} else {
fifo_empty = ni_stc_readw(dev, NISTC_AI_STATUS1_REG) &
NISTC_AI_STATUS1_FIFO_E;
while (fifo_empty == 0) {
for (i = 0;
i <
sizeof(devpriv->ai_fifo_buffer) /
sizeof(devpriv->ai_fifo_buffer[0]); i++) {
fifo_empty = ni_stc_readw(dev,
NISTC_AI_STATUS1_REG) &
NISTC_AI_STATUS1_FIFO_E;
if (fifo_empty)
break;
devpriv->ai_fifo_buffer[i] =
ni_readw(dev, NI_E_AI_FIFO_DATA_REG);
}
comedi_buf_write_samples(s, devpriv->ai_fifo_buffer, i);
}
}
}
static void get_last_sample_611x(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
unsigned short data;
u32 dl;
if (!devpriv->is_611x)
return;
if (ni_readb(dev, NI_E_STATUS_REG) & 0x80) {
dl = ni_readl(dev, NI611X_AI_FIFO_DATA_REG);
data = dl & 0xffff;
comedi_buf_write_samples(s, &data, 1);
}
}
static void get_last_sample_6143(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
unsigned short data;
u32 dl;
if (!devpriv->is_6143)
return;
if (ni_readl(dev, NI6143_AI_FIFO_STATUS_REG) & 0x01) {
ni_writel(dev, 0x01, NI6143_AI_FIFO_CTRL_REG);
dl = ni_readl(dev, NI6143_AI_FIFO_DATA_REG);
data = (dl >> 16) & 0xffff;
comedi_buf_write_samples(s, &data, 1);
}
}
static void shutdown_ai_command(struct comedi_device *dev)
{
struct comedi_subdevice *s = dev->read_subdev;
#ifdef PCIDMA
ni_ai_drain_dma(dev);
#endif
ni_handle_fifo_dregs(dev);
get_last_sample_611x(dev);
get_last_sample_6143(dev);
s->async->events |= COMEDI_CB_EOA;
}
static void ni_handle_eos(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct ni_private *devpriv = dev->private;
if (devpriv->aimode == AIMODE_SCAN) {
#ifdef PCIDMA
static const int timeout = 10;
int i;
for (i = 0; i < timeout; i++) {
ni_sync_ai_dma(dev);
if ((s->async->events & COMEDI_CB_EOS))
break;
udelay(1);
}
#else
ni_handle_fifo_dregs(dev);
s->async->events |= COMEDI_CB_EOS;
#endif
}
if (devpriv->ai_cmd2 & NISTC_AI_CMD2_END_ON_EOS)
shutdown_ai_command(dev);
}
static void handle_gpct_interrupt(struct comedi_device *dev,
unsigned short counter_index)
{
#ifdef PCIDMA
struct ni_private *devpriv = dev->private;
struct comedi_subdevice *s;
s = &dev->subdevices[NI_GPCT_SUBDEV(counter_index)];
ni_tio_handle_interrupt(&devpriv->counter_dev->counters[counter_index],
s);
comedi_handle_events(dev, s);
#endif
}
static void ack_a_interrupt(struct comedi_device *dev, unsigned short a_status)
{
unsigned short ack = 0;
if (a_status & NISTC_AI_STATUS1_SC_TC)
ack |= NISTC_INTA_ACK_AI_SC_TC;
if (a_status & NISTC_AI_STATUS1_START1)
ack |= NISTC_INTA_ACK_AI_START1;
if (a_status & NISTC_AI_STATUS1_START)
ack |= NISTC_INTA_ACK_AI_START;
if (a_status & NISTC_AI_STATUS1_STOP)
ack |= NISTC_INTA_ACK_AI_STOP;
if (ack)
ni_stc_writew(dev, ack, NISTC_INTA_ACK_REG);
}
static void handle_a_interrupt(struct comedi_device *dev, unsigned short status,
unsigned ai_mite_status)
{
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_cmd *cmd = &s->async->cmd;
if (s->type == COMEDI_SUBD_UNUSED)
return;
#ifdef PCIDMA
if (ai_mite_status & CHSR_LINKC)
ni_sync_ai_dma(dev);
if (ai_mite_status & ~(CHSR_INT | CHSR_LINKC | CHSR_DONE | CHSR_MRDY |
CHSR_DRDY | CHSR_DRQ1 | CHSR_DRQ0 | CHSR_ERROR |
CHSR_SABORT | CHSR_XFERR | CHSR_LxERR_mask)) {
dev_err(dev->class_dev,
"unknown mite interrupt (ai_mite_status=%08x)\n",
ai_mite_status);
s->async->events |= COMEDI_CB_ERROR;
}
#endif
if (status & (NISTC_AI_STATUS1_ERR |
NISTC_AI_STATUS1_SC_TC | NISTC_AI_STATUS1_START1)) {
if (status == 0xffff) {
dev_err(dev->class_dev, "Card removed?\n");
if (comedi_is_subdevice_running(s)) {
s->async->events |= COMEDI_CB_ERROR;
comedi_handle_events(dev, s);
}
return;
}
if (status & NISTC_AI_STATUS1_ERR) {
dev_err(dev->class_dev, "ai error a_status=%04x\n",
status);
shutdown_ai_command(dev);
s->async->events |= COMEDI_CB_ERROR;
if (status & NISTC_AI_STATUS1_OVER)
s->async->events |= COMEDI_CB_OVERFLOW;
comedi_handle_events(dev, s);
return;
}
if (status & NISTC_AI_STATUS1_SC_TC) {
if (cmd->stop_src == TRIG_COUNT)
shutdown_ai_command(dev);
}
}
#ifndef PCIDMA
if (status & NISTC_AI_STATUS1_FIFO_HF) {
int i;
static const int timeout = 10;
for (i = 0; i < timeout; ++i) {
ni_handle_fifo_half_full(dev);
if ((ni_stc_readw(dev, NISTC_AI_STATUS1_REG) &
NISTC_AI_STATUS1_FIFO_HF) == 0)
break;
}
}
#endif
if (status & NISTC_AI_STATUS1_STOP)
ni_handle_eos(dev, s);
comedi_handle_events(dev, s);
}
static void ack_b_interrupt(struct comedi_device *dev, unsigned short b_status)
{
unsigned short ack = 0;
if (b_status & NISTC_AO_STATUS1_BC_TC)
ack |= NISTC_INTB_ACK_AO_BC_TC;
if (b_status & NISTC_AO_STATUS1_OVERRUN)
ack |= NISTC_INTB_ACK_AO_ERR;
if (b_status & NISTC_AO_STATUS1_START)
ack |= NISTC_INTB_ACK_AO_START;
if (b_status & NISTC_AO_STATUS1_START1)
ack |= NISTC_INTB_ACK_AO_START1;
if (b_status & NISTC_AO_STATUS1_UC_TC)
ack |= NISTC_INTB_ACK_AO_UC_TC;
if (b_status & NISTC_AO_STATUS1_UI2_TC)
ack |= NISTC_INTB_ACK_AO_UI2_TC;
if (b_status & NISTC_AO_STATUS1_UPDATE)
ack |= NISTC_INTB_ACK_AO_UPDATE;
if (ack)
ni_stc_writew(dev, ack, NISTC_INTB_ACK_REG);
}
static void handle_b_interrupt(struct comedi_device *dev,
unsigned short b_status, unsigned ao_mite_status)
{
struct comedi_subdevice *s = dev->write_subdev;
#ifdef PCIDMA
if (ao_mite_status & CHSR_LINKC) {
struct ni_private *devpriv = dev->private;
mite_handle_b_linkc(devpriv->mite, dev);
}
if (ao_mite_status & ~(CHSR_INT | CHSR_LINKC | CHSR_DONE | CHSR_MRDY |
CHSR_DRDY | CHSR_DRQ1 | CHSR_DRQ0 | CHSR_ERROR |
CHSR_SABORT | CHSR_XFERR | CHSR_LxERR_mask)) {
dev_err(dev->class_dev,
"unknown mite interrupt (ao_mite_status=%08x)\n",
ao_mite_status);
s->async->events |= COMEDI_CB_ERROR;
}
#endif
if (b_status == 0xffff)
return;
if (b_status & NISTC_AO_STATUS1_OVERRUN) {
dev_err(dev->class_dev,
"AO FIFO underrun status=0x%04x status2=0x%04x\n",
b_status, ni_stc_readw(dev, NISTC_AO_STATUS2_REG));
s->async->events |= COMEDI_CB_OVERFLOW;
}
if (b_status & NISTC_AO_STATUS1_BC_TC)
s->async->events |= COMEDI_CB_EOA;
#ifndef PCIDMA
if (b_status & NISTC_AO_STATUS1_FIFO_REQ) {
int ret;
ret = ni_ao_fifo_half_empty(dev, s);
if (!ret) {
dev_err(dev->class_dev, "AO buffer underrun\n");
ni_set_bits(dev, NISTC_INTB_ENA_REG,
NISTC_INTB_ENA_AO_FIFO |
NISTC_INTB_ENA_AO_ERR, 0);
s->async->events |= COMEDI_CB_OVERFLOW;
}
}
#endif
comedi_handle_events(dev, s);
}
static void ni_ai_munge(struct comedi_device *dev, struct comedi_subdevice *s,
void *data, unsigned int num_bytes,
unsigned int chan_index)
{
struct ni_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int nsamples = comedi_bytes_to_samples(s, num_bytes);
unsigned short *array = data;
unsigned int *larray = data;
unsigned int i;
#ifdef PCIDMA
__le16 *barray = data;
__le32 *blarray = data;
#endif
for (i = 0; i < nsamples; i++) {
#ifdef PCIDMA
if (s->subdev_flags & SDF_LSAMPL)
larray[i] = le32_to_cpu(blarray[i]);
else
array[i] = le16_to_cpu(barray[i]);
#endif
if (s->subdev_flags & SDF_LSAMPL)
larray[i] += devpriv->ai_offset[chan_index];
else
array[i] += devpriv->ai_offset[chan_index];
chan_index++;
chan_index %= cmd->chanlist_len;
}
}
static int ni_ai_setup_MITE_dma(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
int retval;
unsigned long flags;
retval = ni_request_ai_mite_channel(dev);
if (retval)
return retval;
comedi_buf_write_alloc(s, s->async->prealloc_bufsz);
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (!devpriv->ai_mite_chan) {
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
return -EIO;
}
if (devpriv->is_611x || devpriv->is_6143)
mite_prep_dma(devpriv->ai_mite_chan, 32, 16);
else if (devpriv->is_628x)
mite_prep_dma(devpriv->ai_mite_chan, 32, 32);
else
mite_prep_dma(devpriv->ai_mite_chan, 16, 16);
mite_dma_arm(devpriv->ai_mite_chan);
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
return 0;
}
static int ni_ao_setup_MITE_dma(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->write_subdev;
int retval;
unsigned long flags;
retval = ni_request_ao_mite_channel(dev);
if (retval)
return retval;
comedi_buf_read_alloc(s, s->async->prealloc_bufsz);
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->ao_mite_chan) {
if (devpriv->is_611x || devpriv->is_6713) {
mite_prep_dma(devpriv->ao_mite_chan, 32, 32);
} else {
mite_prep_dma(devpriv->ao_mite_chan, 16, 32);
}
mite_dma_arm(devpriv->ao_mite_chan);
} else {
retval = -EIO;
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
return retval;
}
static int ni_ai_reset(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct ni_private *devpriv = dev->private;
unsigned ai_personal;
unsigned ai_out_ctrl;
ni_release_ai_mite_channel(dev);
ni_stc_writew(dev, NISTC_RESET_AI_CFG_START | NISTC_RESET_AI,
NISTC_RESET_REG);
ni_set_bits(dev, NISTC_INTA_ENA_REG, NISTC_INTA_ENA_AI_MASK, 0);
ni_clear_ai_fifo(dev);
if (!devpriv->is_6143)
ni_writeb(dev, NI_E_MISC_CMD_EXT_ATRIG, NI_E_MISC_CMD_REG);
ni_stc_writew(dev, NISTC_AI_CMD1_DISARM, NISTC_AI_CMD1_REG);
ni_stc_writew(dev, NISTC_AI_MODE1_START_STOP |
NISTC_AI_MODE1_RSVD
,
NISTC_AI_MODE1_REG);
ni_stc_writew(dev, 0, NISTC_AI_MODE2_REG);
ni_stc_writew(dev, NISTC_AI_MODE3_FIFO_MODE_NE,
NISTC_AI_MODE3_REG);
ai_personal = NISTC_AI_PERSONAL_SHIFTIN_PW |
NISTC_AI_PERSONAL_SOC_POLARITY |
NISTC_AI_PERSONAL_LOCALMUX_CLK_PW;
ai_out_ctrl = NISTC_AI_OUT_CTRL_SCAN_IN_PROG_SEL(3) |
NISTC_AI_OUT_CTRL_EXTMUX_CLK_SEL(0) |
NISTC_AI_OUT_CTRL_LOCALMUX_CLK_SEL(2) |
NISTC_AI_OUT_CTRL_SC_TC_SEL(3);
if (devpriv->is_611x) {
ai_out_ctrl |= NISTC_AI_OUT_CTRL_CONVERT_HIGH;
} else if (devpriv->is_6143) {
ai_out_ctrl |= NISTC_AI_OUT_CTRL_CONVERT_LOW;
} else {
ai_personal |= NISTC_AI_PERSONAL_CONVERT_PW;
if (devpriv->is_622x)
ai_out_ctrl |= NISTC_AI_OUT_CTRL_CONVERT_HIGH;
else
ai_out_ctrl |= NISTC_AI_OUT_CTRL_CONVERT_LOW;
}
ni_stc_writew(dev, ai_personal, NISTC_AI_PERSONAL_REG);
ni_stc_writew(dev, ai_out_ctrl, NISTC_AI_OUT_CTRL_REG);
ni_stc_writew(dev, NISTC_INTA_ACK_AI_ALL, NISTC_INTA_ACK_REG);
ni_stc_writew(dev, NISTC_RESET_AI_CFG_END, NISTC_RESET_REG);
return 0;
}
static int ni_ai_poll(struct comedi_device *dev, struct comedi_subdevice *s)
{
unsigned long flags;
int count;
spin_lock_irqsave(&dev->spinlock, flags);
#ifndef PCIDMA
ni_handle_fifo_dregs(dev);
#else
ni_sync_ai_dma(dev);
#endif
count = comedi_buf_n_bytes_ready(s);
spin_unlock_irqrestore(&dev->spinlock, flags);
return count;
}
static void ni_prime_channelgain_list(struct comedi_device *dev)
{
int i;
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE, NISTC_AI_CMD1_REG);
for (i = 0; i < NI_TIMEOUT; ++i) {
if (!(ni_stc_readw(dev, NISTC_AI_STATUS1_REG) &
NISTC_AI_STATUS1_FIFO_E)) {
ni_stc_writew(dev, 1, NISTC_ADC_FIFO_CLR_REG);
return;
}
udelay(1);
}
dev_err(dev->class_dev, "timeout loading channel/gain list\n");
}
static void ni_m_series_load_channelgain_list(struct comedi_device *dev,
unsigned int n_chan,
unsigned int *list)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
unsigned int chan, range, aref;
unsigned int i;
unsigned int dither;
unsigned range_code;
ni_stc_writew(dev, 1, NISTC_CFG_MEM_CLR_REG);
if ((list[0] & CR_ALT_SOURCE)) {
unsigned bypass_bits;
chan = CR_CHAN(list[0]);
range = CR_RANGE(list[0]);
range_code = ni_gainlkup[board->gainlkup][range];
dither = (list[0] & CR_ALT_FILTER) != 0;
bypass_bits = NI_M_CFG_BYPASS_FIFO |
NI_M_CFG_BYPASS_AI_CHAN(chan) |
NI_M_CFG_BYPASS_AI_GAIN(range_code) |
devpriv->ai_calib_source;
if (dither)
bypass_bits |= NI_M_CFG_BYPASS_AI_DITHER;
bypass_bits |= NI_M_CFG_BYPASS_AI_POLARITY;
ni_writel(dev, bypass_bits, NI_M_CFG_BYPASS_FIFO_REG);
} else {
ni_writel(dev, 0, NI_M_CFG_BYPASS_FIFO_REG);
}
for (i = 0; i < n_chan; i++) {
unsigned config_bits = 0;
chan = CR_CHAN(list[i]);
aref = CR_AREF(list[i]);
range = CR_RANGE(list[i]);
dither = (list[i] & CR_ALT_FILTER) != 0;
range_code = ni_gainlkup[board->gainlkup][range];
devpriv->ai_offset[i] = 0;
switch (aref) {
case AREF_DIFF:
config_bits |= NI_M_AI_CFG_CHAN_TYPE_DIFF;
break;
case AREF_COMMON:
config_bits |= NI_M_AI_CFG_CHAN_TYPE_COMMON;
break;
case AREF_GROUND:
config_bits |= NI_M_AI_CFG_CHAN_TYPE_GROUND;
break;
case AREF_OTHER:
break;
}
config_bits |= NI_M_AI_CFG_CHAN_SEL(chan);
config_bits |= NI_M_AI_CFG_BANK_SEL(chan);
config_bits |= NI_M_AI_CFG_GAIN(range_code);
if (i == n_chan - 1)
config_bits |= NI_M_AI_CFG_LAST_CHAN;
if (dither)
config_bits |= NI_M_AI_CFG_DITHER;
config_bits |= NI_M_AI_CFG_POLARITY;
ni_writew(dev, config_bits, NI_M_AI_CFG_FIFO_DATA_REG);
}
ni_prime_channelgain_list(dev);
}
static void ni_load_channelgain_list(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int n_chan, unsigned int *list)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
unsigned int offset = (s->maxdata + 1) >> 1;
unsigned int chan, range, aref;
unsigned int i;
unsigned int hi, lo;
unsigned int dither;
if (devpriv->is_m_series) {
ni_m_series_load_channelgain_list(dev, n_chan, list);
return;
}
if (n_chan == 1 && !devpriv->is_611x && !devpriv->is_6143) {
if (devpriv->changain_state
&& devpriv->changain_spec == list[0]) {
return;
}
devpriv->changain_state = 1;
devpriv->changain_spec = list[0];
} else {
devpriv->changain_state = 0;
}
ni_stc_writew(dev, 1, NISTC_CFG_MEM_CLR_REG);
if (devpriv->is_6143) {
if ((list[0] & CR_ALT_SOURCE)
&& !devpriv->ai_calib_source_enabled) {
ni_writew(dev, devpriv->ai_calib_source |
NI6143_CALIB_CHAN_RELAY_ON,
NI6143_CALIB_CHAN_REG);
ni_writew(dev, devpriv->ai_calib_source,
NI6143_CALIB_CHAN_REG);
devpriv->ai_calib_source_enabled = 1;
msleep_interruptible(100);
} else if (!(list[0] & CR_ALT_SOURCE)
&& devpriv->ai_calib_source_enabled) {
ni_writew(dev, devpriv->ai_calib_source |
NI6143_CALIB_CHAN_RELAY_OFF,
NI6143_CALIB_CHAN_REG);
ni_writew(dev, devpriv->ai_calib_source,
NI6143_CALIB_CHAN_REG);
devpriv->ai_calib_source_enabled = 0;
msleep_interruptible(100);
}
}
for (i = 0; i < n_chan; i++) {
if (!devpriv->is_6143 && (list[i] & CR_ALT_SOURCE))
chan = devpriv->ai_calib_source;
else
chan = CR_CHAN(list[i]);
aref = CR_AREF(list[i]);
range = CR_RANGE(list[i]);
dither = (list[i] & CR_ALT_FILTER) != 0;
range = ni_gainlkup[board->gainlkup][range];
if (devpriv->is_611x)
devpriv->ai_offset[i] = offset;
else
devpriv->ai_offset[i] = (range & 0x100) ? 0 : offset;
hi = 0;
if ((list[i] & CR_ALT_SOURCE)) {
if (devpriv->is_611x)
ni_writew(dev, CR_CHAN(list[i]) & 0x0003,
NI611X_CALIB_CHAN_SEL_REG);
} else {
if (devpriv->is_611x)
aref = AREF_DIFF;
else if (devpriv->is_6143)
aref = AREF_OTHER;
switch (aref) {
case AREF_DIFF:
hi |= NI_E_AI_CFG_HI_TYPE_DIFF;
break;
case AREF_COMMON:
hi |= NI_E_AI_CFG_HI_TYPE_COMMON;
break;
case AREF_GROUND:
hi |= NI_E_AI_CFG_HI_TYPE_GROUND;
break;
case AREF_OTHER:
break;
}
}
hi |= NI_E_AI_CFG_HI_CHAN(chan);
ni_writew(dev, hi, NI_E_AI_CFG_HI_REG);
if (!devpriv->is_6143) {
lo = NI_E_AI_CFG_LO_GAIN(range);
if (i == n_chan - 1)
lo |= NI_E_AI_CFG_LO_LAST_CHAN;
if (dither)
lo |= NI_E_AI_CFG_LO_DITHER;
ni_writew(dev, lo, NI_E_AI_CFG_LO_REG);
}
}
if (!devpriv->is_611x && !devpriv->is_6143)
ni_prime_channelgain_list(dev);
}
static int ni_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
unsigned int mask = (s->maxdata + 1) >> 1;
int i, n;
unsigned signbits;
unsigned int d;
unsigned long dl;
ni_load_channelgain_list(dev, s, 1, &insn->chanspec);
ni_clear_ai_fifo(dev);
signbits = devpriv->ai_offset[0];
if (devpriv->is_611x) {
for (n = 0; n < num_adc_stages_611x; n++) {
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
udelay(1);
}
for (n = 0; n < insn->n; n++) {
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
d = 0;
for (i = 0; i < NI_TIMEOUT; i++) {
if (ni_readb(dev, NI_E_STATUS_REG) & 0x80) {
d = ni_readl(dev,
NI611X_AI_FIFO_DATA_REG);
d >>= 16;
d &= 0xffff;
break;
}
if (!(ni_stc_readw(dev, NISTC_AI_STATUS1_REG) &
NISTC_AI_STATUS1_FIFO_E)) {
d = ni_readl(dev,
NI611X_AI_FIFO_DATA_REG);
d &= 0xffff;
break;
}
}
if (i == NI_TIMEOUT) {
dev_err(dev->class_dev, "timeout\n");
return -ETIME;
}
d += signbits;
data[n] = d;
}
} else if (devpriv->is_6143) {
for (n = 0; n < insn->n; n++) {
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
dl = 0;
for (i = 0; i < NI_TIMEOUT; i++) {
if (ni_readl(dev, NI6143_AI_FIFO_STATUS_REG) &
0x01) {
ni_writel(dev, 0x01,
NI6143_AI_FIFO_CTRL_REG);
dl = ni_readl(dev,
NI6143_AI_FIFO_DATA_REG);
break;
}
}
if (i == NI_TIMEOUT) {
dev_err(dev->class_dev, "timeout\n");
return -ETIME;
}
data[n] = (((dl >> 16) & 0xFFFF) + signbits) & 0xFFFF;
}
} else {
for (n = 0; n < insn->n; n++) {
ni_stc_writew(dev, NISTC_AI_CMD1_CONVERT_PULSE,
NISTC_AI_CMD1_REG);
for (i = 0; i < NI_TIMEOUT; i++) {
if (!(ni_stc_readw(dev, NISTC_AI_STATUS1_REG) &
NISTC_AI_STATUS1_FIFO_E))
break;
}
if (i == NI_TIMEOUT) {
dev_err(dev->class_dev, "timeout\n");
return -ETIME;
}
if (devpriv->is_m_series) {
dl = ni_readl(dev, NI_M_AI_FIFO_DATA_REG);
dl &= mask;
data[n] = dl;
} else {
d = ni_readw(dev, NI_E_AI_FIFO_DATA_REG);
d += signbits;
data[n] = d;
}
}
}
return insn->n;
}
static int ni_ns_to_timer(const struct comedi_device *dev, unsigned nanosec,
unsigned int flags)
{
struct ni_private *devpriv = dev->private;
int divider;
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
divider = (nanosec + devpriv->clock_ns / 2) / devpriv->clock_ns;
break;
case CMDF_ROUND_DOWN:
divider = (nanosec) / devpriv->clock_ns;
break;
case CMDF_ROUND_UP:
divider = (nanosec + devpriv->clock_ns - 1) / devpriv->clock_ns;
break;
}
return divider - 1;
}
static unsigned ni_timer_to_ns(const struct comedi_device *dev, int timer)
{
struct ni_private *devpriv = dev->private;
return devpriv->clock_ns * (timer + 1);
}
static unsigned ni_min_ai_scan_period_ns(struct comedi_device *dev,
unsigned num_channels)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
if (devpriv->is_611x || devpriv->is_6143)
return board->ai_speed;
return board->ai_speed * num_channels;
}
static int ni_ai_cmdtest(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
int err = 0;
unsigned int tmp;
unsigned int sources;
err |= comedi_check_trigger_src(&cmd->start_src,
TRIG_NOW | TRIG_INT | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
sources = TRIG_TIMER | TRIG_EXT;
if (devpriv->is_611x || devpriv->is_6143)
sources |= TRIG_NOW;
err |= comedi_check_trigger_src(&cmd->convert_src, sources);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
err |= comedi_check_trigger_is_unique(cmd->convert_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
switch (cmd->start_src) {
case TRIG_NOW:
case TRIG_INT:
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
break;
case TRIG_EXT:
tmp = CR_CHAN(cmd->start_arg);
if (tmp > 16)
tmp = 16;
tmp |= (cmd->start_arg & (CR_INVERT | CR_EDGE));
err |= comedi_check_trigger_arg_is(&cmd->start_arg, tmp);
break;
}
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
ni_min_ai_scan_period_ns(dev, cmd->chanlist_len));
err |= comedi_check_trigger_arg_max(&cmd->scan_begin_arg,
devpriv->clock_ns *
0xffffff);
} else if (cmd->scan_begin_src == TRIG_EXT) {
unsigned int tmp = CR_CHAN(cmd->scan_begin_arg);
if (tmp > 16)
tmp = 16;
tmp |= (cmd->scan_begin_arg & (CR_INVERT | CR_EDGE));
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, tmp);
} else {
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
}
if (cmd->convert_src == TRIG_TIMER) {
if (devpriv->is_611x || devpriv->is_6143) {
err |= comedi_check_trigger_arg_is(&cmd->convert_arg,
0);
} else {
err |= comedi_check_trigger_arg_min(&cmd->convert_arg,
board->ai_speed);
err |= comedi_check_trigger_arg_max(&cmd->convert_arg,
devpriv->clock_ns *
0xffff);
}
} else if (cmd->convert_src == TRIG_EXT) {
unsigned int tmp = CR_CHAN(cmd->convert_arg);
if (tmp > 16)
tmp = 16;
tmp |= (cmd->convert_arg & (CR_ALT_FILTER | CR_INVERT));
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, tmp);
} else if (cmd->convert_src == TRIG_NOW) {
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
}
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT) {
unsigned int max_count = 0x01000000;
if (devpriv->is_611x)
max_count -= num_adc_stages_611x;
err |= comedi_check_trigger_arg_max(&cmd->stop_arg, max_count);
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
} else {
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
}
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
cmd->scan_begin_arg =
ni_timer_to_ns(dev, ni_ns_to_timer(dev,
cmd->scan_begin_arg,
cmd->flags));
if (tmp != cmd->scan_begin_arg)
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
if (!devpriv->is_611x && !devpriv->is_6143) {
tmp = cmd->convert_arg;
cmd->convert_arg =
ni_timer_to_ns(dev, ni_ns_to_timer(dev,
cmd->convert_arg,
cmd->flags));
if (tmp != cmd->convert_arg)
err++;
if (cmd->scan_begin_src == TRIG_TIMER &&
cmd->scan_begin_arg <
cmd->convert_arg * cmd->scan_end_arg) {
cmd->scan_begin_arg =
cmd->convert_arg * cmd->scan_end_arg;
err++;
}
}
}
if (err)
return 4;
return 0;
}
static int ni_ai_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct ni_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
if (trig_num != cmd->start_arg)
return -EINVAL;
ni_stc_writew(dev, NISTC_AI_CMD2_START1_PULSE | devpriv->ai_cmd2,
NISTC_AI_CMD2_REG);
s->async->inttrig = NULL;
return 1;
}
static int ni_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct ni_private *devpriv = dev->private;
const struct comedi_cmd *cmd = &s->async->cmd;
int timer;
int mode1 = 0;
int mode2 = 0;
int start_stop_select = 0;
unsigned int stop_count;
int interrupt_a_enable = 0;
unsigned ai_trig;
if (dev->irq == 0) {
dev_err(dev->class_dev, "cannot run command without an irq\n");
return -EIO;
}
ni_clear_ai_fifo(dev);
ni_load_channelgain_list(dev, s, cmd->chanlist_len, cmd->chanlist);
ni_stc_writew(dev, NISTC_RESET_AI_CFG_START, NISTC_RESET_REG);
devpriv->an_trig_etc_reg &= ~NISTC_ATRIG_ETC_ENA;
ni_stc_writew(dev, devpriv->an_trig_etc_reg, NISTC_ATRIG_ETC_REG);
ai_trig = NISTC_AI_TRIG_START2_SEL(0) | NISTC_AI_TRIG_START1_SYNC;
switch (cmd->start_src) {
case TRIG_INT:
case TRIG_NOW:
ai_trig |= NISTC_AI_TRIG_START1_EDGE |
NISTC_AI_TRIG_START1_SEL(0);
break;
case TRIG_EXT:
ai_trig |= NISTC_AI_TRIG_START1_SEL(CR_CHAN(cmd->start_arg) +
1);
if (cmd->start_arg & CR_INVERT)
ai_trig |= NISTC_AI_TRIG_START1_POLARITY;
if (cmd->start_arg & CR_EDGE)
ai_trig |= NISTC_AI_TRIG_START1_EDGE;
break;
}
ni_stc_writew(dev, ai_trig, NISTC_AI_TRIG_SEL_REG);
mode2 &= ~NISTC_AI_MODE2_PRE_TRIGGER;
mode2 &= ~NISTC_AI_MODE2_SC_INIT_LOAD_SRC;
mode2 &= ~NISTC_AI_MODE2_SC_RELOAD_MODE;
ni_stc_writew(dev, mode2, NISTC_AI_MODE2_REG);
if (cmd->chanlist_len == 1 || devpriv->is_611x || devpriv->is_6143) {
start_stop_select |= NISTC_AI_STOP_POLARITY |
NISTC_AI_STOP_SEL(31) |
NISTC_AI_STOP_SYNC;
} else {
start_stop_select |= NISTC_AI_STOP_SEL(19);
}
ni_stc_writew(dev, start_stop_select, NISTC_AI_START_STOP_REG);
devpriv->ai_cmd2 = 0;
switch (cmd->stop_src) {
case TRIG_COUNT:
stop_count = cmd->stop_arg - 1;
if (devpriv->is_611x) {
stop_count += num_adc_stages_611x;
}
ni_stc_writel(dev, stop_count, NISTC_AI_SC_LOADA_REG);
mode1 |= NISTC_AI_MODE1_START_STOP |
NISTC_AI_MODE1_RSVD |
NISTC_AI_MODE1_TRIGGER_ONCE;
ni_stc_writew(dev, mode1, NISTC_AI_MODE1_REG);
ni_stc_writew(dev, NISTC_AI_CMD1_SC_LOAD, NISTC_AI_CMD1_REG);
if (stop_count == 0) {
devpriv->ai_cmd2 |= NISTC_AI_CMD2_END_ON_EOS;
interrupt_a_enable |= NISTC_INTA_ENA_AI_STOP;
if (cmd->chanlist_len > 1)
start_stop_select |= NISTC_AI_STOP_POLARITY |
NISTC_AI_STOP_EDGE;
}
break;
case TRIG_NONE:
ni_stc_writel(dev, 0, NISTC_AI_SC_LOADA_REG);
mode1 |= NISTC_AI_MODE1_START_STOP |
NISTC_AI_MODE1_RSVD |
NISTC_AI_MODE1_CONTINUOUS;
ni_stc_writew(dev, mode1, NISTC_AI_MODE1_REG);
ni_stc_writew(dev, NISTC_AI_CMD1_SC_LOAD, NISTC_AI_CMD1_REG);
break;
}
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
start_stop_select |= NISTC_AI_START_EDGE | NISTC_AI_START_SYNC;
ni_stc_writew(dev, start_stop_select, NISTC_AI_START_STOP_REG);
mode2 &= ~NISTC_AI_MODE2_SI_INIT_LOAD_SRC;
mode2 |= NISTC_AI_MODE2_SI_RELOAD_MODE(0);
ni_stc_writew(dev, mode2, NISTC_AI_MODE2_REG);
timer = ni_ns_to_timer(dev, cmd->scan_begin_arg,
CMDF_ROUND_NEAREST);
ni_stc_writel(dev, timer, NISTC_AI_SI_LOADA_REG);
ni_stc_writew(dev, NISTC_AI_CMD1_SI_LOAD, NISTC_AI_CMD1_REG);
break;
case TRIG_EXT:
if (cmd->scan_begin_arg & CR_EDGE)
start_stop_select |= NISTC_AI_START_EDGE;
if (cmd->scan_begin_arg & CR_INVERT)
start_stop_select |= NISTC_AI_START_POLARITY;
if (cmd->scan_begin_src != cmd->convert_src ||
(cmd->scan_begin_arg & ~CR_EDGE) !=
(cmd->convert_arg & ~CR_EDGE))
start_stop_select |= NISTC_AI_START_SYNC;
start_stop_select |=
NISTC_AI_START_SEL(1 + CR_CHAN(cmd->scan_begin_arg));
ni_stc_writew(dev, start_stop_select, NISTC_AI_START_STOP_REG);
break;
}
switch (cmd->convert_src) {
case TRIG_TIMER:
case TRIG_NOW:
if (cmd->convert_arg == 0 || cmd->convert_src == TRIG_NOW)
timer = 1;
else
timer = ni_ns_to_timer(dev, cmd->convert_arg,
CMDF_ROUND_NEAREST);
ni_stc_writew(dev, 1, NISTC_AI_SI2_LOADA_REG);
ni_stc_writew(dev, timer, NISTC_AI_SI2_LOADB_REG);
mode2 &= ~NISTC_AI_MODE2_SI2_INIT_LOAD_SRC;
mode2 |= NISTC_AI_MODE2_SI2_RELOAD_MODE;
ni_stc_writew(dev, mode2, NISTC_AI_MODE2_REG);
ni_stc_writew(dev, NISTC_AI_CMD1_SI2_LOAD, NISTC_AI_CMD1_REG);
mode2 |= NISTC_AI_MODE2_SI2_INIT_LOAD_SRC;
mode2 |= NISTC_AI_MODE2_SI2_RELOAD_MODE;
ni_stc_writew(dev, mode2, NISTC_AI_MODE2_REG);
break;
case TRIG_EXT:
mode1 |= NISTC_AI_MODE1_CONVERT_SRC(1 + cmd->convert_arg);
if ((cmd->convert_arg & CR_INVERT) == 0)
mode1 |= NISTC_AI_MODE1_CONVERT_POLARITY;
ni_stc_writew(dev, mode1, NISTC_AI_MODE1_REG);
mode2 |= NISTC_AI_MODE2_SC_GATE_ENA |
NISTC_AI_MODE2_START_STOP_GATE_ENA;
ni_stc_writew(dev, mode2, NISTC_AI_MODE2_REG);
break;
}
if (dev->irq) {
interrupt_a_enable |= NISTC_INTA_ENA_AI_ERR |
NISTC_INTA_ENA_AI_SC_TC;
#ifndef PCIDMA
interrupt_a_enable |= NISTC_INTA_ENA_AI_FIFO;
#endif
if ((cmd->flags & CMDF_WAKE_EOS) ||
(devpriv->ai_cmd2 & NISTC_AI_CMD2_END_ON_EOS)) {
devpriv->aimode = AIMODE_SCAN;
} else {
devpriv->aimode = AIMODE_HALF_FULL;
}
switch (devpriv->aimode) {
case AIMODE_HALF_FULL:
#ifdef PCIDMA
ni_stc_writew(dev, NISTC_AI_MODE3_FIFO_MODE_HF_E,
NISTC_AI_MODE3_REG);
#else
ni_stc_writew(dev, NISTC_AI_MODE3_FIFO_MODE_HF,
NISTC_AI_MODE3_REG);
#endif
break;
case AIMODE_SAMPLE:
ni_stc_writew(dev, NISTC_AI_MODE3_FIFO_MODE_NE,
NISTC_AI_MODE3_REG);
break;
case AIMODE_SCAN:
#ifdef PCIDMA
ni_stc_writew(dev, NISTC_AI_MODE3_FIFO_MODE_NE,
NISTC_AI_MODE3_REG);
#else
ni_stc_writew(dev, NISTC_AI_MODE3_FIFO_MODE_HF,
NISTC_AI_MODE3_REG);
#endif
interrupt_a_enable |= NISTC_INTA_ENA_AI_STOP;
break;
default:
break;
}
ni_stc_writew(dev, NISTC_INTA_ACK_AI_ALL, NISTC_INTA_ACK_REG);
ni_set_bits(dev, NISTC_INTA_ENA_REG, interrupt_a_enable, 1);
} else {
ni_set_bits(dev, NISTC_INTA_ENA_REG, ~0, 0);
}
ni_stc_writew(dev, NISTC_RESET_AI_CFG_END, NISTC_RESET_REG);
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
ni_stc_writew(dev, NISTC_AI_CMD1_SI2_ARM |
NISTC_AI_CMD1_SI_ARM |
NISTC_AI_CMD1_DIV_ARM |
NISTC_AI_CMD1_SC_ARM,
NISTC_AI_CMD1_REG);
break;
case TRIG_EXT:
ni_stc_writew(dev, NISTC_AI_CMD1_SI2_ARM |
NISTC_AI_CMD1_SI_ARM |
NISTC_AI_CMD1_DIV_ARM |
NISTC_AI_CMD1_SC_ARM,
NISTC_AI_CMD1_REG);
break;
}
#ifdef PCIDMA
{
int retval = ni_ai_setup_MITE_dma(dev);
if (retval)
return retval;
}
#endif
if (cmd->start_src == TRIG_NOW) {
ni_stc_writew(dev, NISTC_AI_CMD2_START1_PULSE |
devpriv->ai_cmd2,
NISTC_AI_CMD2_REG);
s->async->inttrig = NULL;
} else if (cmd->start_src == TRIG_EXT) {
s->async->inttrig = NULL;
} else {
s->async->inttrig = ni_ai_inttrig;
}
return 0;
}
static int ni_ai_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni_private *devpriv = dev->private;
if (insn->n < 1)
return -EINVAL;
switch (data[0]) {
case INSN_CONFIG_ALT_SOURCE:
if (devpriv->is_m_series) {
if (data[1] & ~NI_M_CFG_BYPASS_AI_CAL_MASK)
return -EINVAL;
devpriv->ai_calib_source = data[1];
} else if (devpriv->is_6143) {
unsigned int calib_source;
calib_source = data[1] & 0xf;
devpriv->ai_calib_source = calib_source;
ni_writew(dev, calib_source, NI6143_CALIB_CHAN_REG);
} else {
unsigned int calib_source;
unsigned int calib_source_adjust;
calib_source = data[1] & 0xf;
calib_source_adjust = (data[1] >> 4) & 0xff;
if (calib_source >= 8)
return -EINVAL;
devpriv->ai_calib_source = calib_source;
if (devpriv->is_611x) {
ni_writeb(dev, calib_source_adjust,
NI611X_CAL_GAIN_SEL_REG);
}
}
return 2;
default:
break;
}
return -EINVAL;
}
static void ni_ao_munge(struct comedi_device *dev, struct comedi_subdevice *s,
void *data, unsigned int num_bytes,
unsigned int chan_index)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int nsamples = comedi_bytes_to_samples(s, num_bytes);
unsigned short *array = data;
unsigned int i;
#ifdef PCIDMA
__le16 buf, *barray = data;
#endif
for (i = 0; i < nsamples; i++) {
unsigned int range = CR_RANGE(cmd->chanlist[chan_index]);
unsigned short val = array[i];
if (comedi_range_is_bipolar(s, range))
val = comedi_offset_munge(s, val);
#ifdef PCIDMA
buf = cpu_to_le16(val);
barray[i] = buf;
#else
array[i] = val;
#endif
chan_index++;
chan_index %= cmd->chanlist_len;
}
}
static int ni_m_series_ao_config_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chanspec[],
unsigned int n_chans, int timed)
{
struct ni_private *devpriv = dev->private;
unsigned int range;
unsigned int chan;
unsigned int conf;
int i;
int invert = 0;
if (timed) {
for (i = 0; i < s->n_chan; ++i) {
devpriv->ao_conf[i] &= ~NI_M_AO_CFG_BANK_UPDATE_TIMED;
ni_writeb(dev, devpriv->ao_conf[i],
NI_M_AO_CFG_BANK_REG(i));
ni_writeb(dev, 0xf, NI_M_AO_WAVEFORM_ORDER_REG(i));
}
}
for (i = 0; i < n_chans; i++) {
const struct comedi_krange *krange;
chan = CR_CHAN(chanspec[i]);
range = CR_RANGE(chanspec[i]);
krange = s->range_table->range + range;
invert = 0;
conf = 0;
switch (krange->max - krange->min) {
case 20000000:
conf |= NI_M_AO_CFG_BANK_REF_INT_10V;
ni_writeb(dev, 0, NI_M_AO_REF_ATTENUATION_REG(chan));
break;
case 10000000:
conf |= NI_M_AO_CFG_BANK_REF_INT_5V;
ni_writeb(dev, 0, NI_M_AO_REF_ATTENUATION_REG(chan));
break;
case 4000000:
conf |= NI_M_AO_CFG_BANK_REF_INT_10V;
ni_writeb(dev, NI_M_AO_REF_ATTENUATION_X5,
NI_M_AO_REF_ATTENUATION_REG(chan));
break;
case 2000000:
conf |= NI_M_AO_CFG_BANK_REF_INT_5V;
ni_writeb(dev, NI_M_AO_REF_ATTENUATION_X5,
NI_M_AO_REF_ATTENUATION_REG(chan));
break;
default:
dev_err(dev->class_dev,
"bug! unhandled ao reference voltage\n");
break;
}
switch (krange->max + krange->min) {
case 0:
conf |= NI_M_AO_CFG_BANK_OFFSET_0V;
break;
case 10000000:
conf |= NI_M_AO_CFG_BANK_OFFSET_5V;
break;
default:
dev_err(dev->class_dev,
"bug! unhandled ao offset voltage\n");
break;
}
if (timed)
conf |= NI_M_AO_CFG_BANK_UPDATE_TIMED;
ni_writeb(dev, conf, NI_M_AO_CFG_BANK_REG(chan));
devpriv->ao_conf[chan] = conf;
ni_writeb(dev, i, NI_M_AO_WAVEFORM_ORDER_REG(chan));
}
return invert;
}
static int ni_old_ao_config_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chanspec[],
unsigned int n_chans)
{
struct ni_private *devpriv = dev->private;
unsigned int range;
unsigned int chan;
unsigned int conf;
int i;
int invert = 0;
for (i = 0; i < n_chans; i++) {
chan = CR_CHAN(chanspec[i]);
range = CR_RANGE(chanspec[i]);
conf = NI_E_AO_DACSEL(chan);
if (comedi_range_is_bipolar(s, range)) {
conf |= NI_E_AO_CFG_BIP;
invert = (s->maxdata + 1) >> 1;
} else {
invert = 0;
}
if (comedi_range_is_external(s, range))
conf |= NI_E_AO_EXT_REF;
if (chanspec[i] & CR_DEGLITCH)
conf |= NI_E_AO_DEGLITCH;
if (CR_AREF(chanspec[i]) == AREF_OTHER)
conf |= NI_E_AO_GROUND_REF;
ni_writew(dev, conf, NI_E_AO_CFG_REG);
devpriv->ao_conf[chan] = conf;
}
return invert;
}
static int ni_ao_config_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chanspec[], unsigned int n_chans,
int timed)
{
struct ni_private *devpriv = dev->private;
if (devpriv->is_m_series)
return ni_m_series_ao_config_chanlist(dev, s, chanspec, n_chans,
timed);
else
return ni_old_ao_config_chanlist(dev, s, chanspec, n_chans);
}
static int ni_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
int reg;
int i;
if (devpriv->is_6xxx) {
ni_ao_win_outw(dev, 1 << chan, NI671X_AO_IMMEDIATE_REG);
reg = NI671X_DAC_DIRECT_DATA_REG(chan);
} else if (devpriv->is_m_series) {
reg = NI_M_DAC_DIRECT_DATA_REG(chan);
} else {
reg = NI_E_DAC_DIRECT_DATA_REG(chan);
}
ni_ao_config_chanlist(dev, s, &insn->chanspec, 1, 0);
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
s->readback[chan] = val;
if (devpriv->is_6xxx) {
val = comedi_offset_munge(s, val);
ni_ao_win_outw(dev, val, reg);
} else if (devpriv->is_m_series) {
ni_writew(dev, val, reg);
} else {
if (comedi_range_is_bipolar(s, range))
val = comedi_offset_munge(s, val);
ni_writew(dev, val, reg);
}
}
return insn->n;
}
static int ni_ao_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
unsigned int nbytes;
switch (data[0]) {
case INSN_CONFIG_GET_HARDWARE_BUFFER_SIZE:
switch (data[1]) {
case COMEDI_OUTPUT:
nbytes = comedi_samples_to_bytes(s,
board->ao_fifo_depth);
data[2] = 1 + nbytes;
if (devpriv->mite)
data[2] += devpriv->mite->fifo_size;
break;
case COMEDI_INPUT:
data[2] = 0;
break;
default:
return -EINVAL;
}
return 0;
default:
break;
}
return -EINVAL;
}
static int ni_ao_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct ni_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int ret;
int interrupt_b_bits;
int i;
static const int timeout = 1000;
if (trig_num != cmd->start_arg)
return -EINVAL;
s->async->inttrig = NULL;
ni_set_bits(dev, NISTC_INTB_ENA_REG,
NISTC_INTB_ENA_AO_FIFO | NISTC_INTB_ENA_AO_ERR, 0);
interrupt_b_bits = NISTC_INTB_ENA_AO_ERR;
#ifdef PCIDMA
ni_stc_writew(dev, 1, NISTC_DAC_FIFO_CLR_REG);
if (devpriv->is_6xxx)
ni_ao_win_outl(dev, 0x6, NI611X_AO_FIFO_OFFSET_LOAD_REG);
ret = ni_ao_setup_MITE_dma(dev);
if (ret)
return ret;
ret = ni_ao_wait_for_dma_load(dev);
if (ret < 0)
return ret;
#else
ret = ni_ao_prep_fifo(dev, s);
if (ret == 0)
return -EPIPE;
interrupt_b_bits |= NISTC_INTB_ENA_AO_FIFO;
#endif
ni_stc_writew(dev, devpriv->ao_mode3 | NISTC_AO_MODE3_NOT_AN_UPDATE,
NISTC_AO_MODE3_REG);
ni_stc_writew(dev, devpriv->ao_mode3, NISTC_AO_MODE3_REG);
for (i = 0; i < timeout; i++) {
udelay(1);
if ((ni_stc_readw(dev, NISTC_STATUS2_REG) &
NISTC_STATUS2_AO_TMRDACWRS_IN_PROGRESS) == 0)
break;
}
if (i == timeout) {
dev_err(dev->class_dev,
"timed out waiting for AO_TMRDACWRs_In_Progress_St to clear\n");
return -EIO;
}
ni_stc_writew(dev, NISTC_INTB_ACK_AO_ERR, NISTC_INTB_ACK_REG);
ni_set_bits(dev, NISTC_INTB_ENA_REG, interrupt_b_bits, 1);
ni_stc_writew(dev, NISTC_AO_CMD1_UI_ARM |
NISTC_AO_CMD1_UC_ARM |
NISTC_AO_CMD1_BC_ARM |
NISTC_AO_CMD1_DAC1_UPDATE_MODE |
NISTC_AO_CMD1_DAC0_UPDATE_MODE |
devpriv->ao_cmd1,
NISTC_AO_CMD1_REG);
ni_stc_writew(dev, NISTC_AO_CMD2_START1_PULSE | devpriv->ao_cmd2,
NISTC_AO_CMD2_REG);
return 0;
}
static int ni_ao_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
const struct comedi_cmd *cmd = &s->async->cmd;
int bits;
int i;
unsigned trigvar;
unsigned val;
if (dev->irq == 0) {
dev_err(dev->class_dev, "cannot run command without an irq\n");
return -EIO;
}
ni_stc_writew(dev, NISTC_RESET_AO_CFG_START, NISTC_RESET_REG);
ni_stc_writew(dev, NISTC_AO_CMD1_DISARM, NISTC_AO_CMD1_REG);
if (devpriv->is_6xxx) {
ni_ao_win_outw(dev, NI611X_AO_MISC_CLEAR_WG,
NI611X_AO_MISC_REG);
bits = 0;
for (i = 0; i < cmd->chanlist_len; i++) {
int chan;
chan = CR_CHAN(cmd->chanlist[i]);
bits |= 1 << chan;
ni_ao_win_outw(dev, chan, NI611X_AO_WAVEFORM_GEN_REG);
}
ni_ao_win_outw(dev, bits, NI611X_AO_TIMED_REG);
}
ni_ao_config_chanlist(dev, s, cmd->chanlist, cmd->chanlist_len, 1);
if (cmd->stop_src == TRIG_NONE) {
devpriv->ao_mode1 |= NISTC_AO_MODE1_CONTINUOUS;
devpriv->ao_mode1 &= ~NISTC_AO_MODE1_TRIGGER_ONCE;
} else {
devpriv->ao_mode1 &= ~NISTC_AO_MODE1_CONTINUOUS;
devpriv->ao_mode1 |= NISTC_AO_MODE1_TRIGGER_ONCE;
}
ni_stc_writew(dev, devpriv->ao_mode1, NISTC_AO_MODE1_REG);
val = devpriv->ao_trigger_select;
switch (cmd->start_src) {
case TRIG_INT:
case TRIG_NOW:
val &= ~(NISTC_AO_TRIG_START1_POLARITY |
NISTC_AO_TRIG_START1_SEL_MASK);
val |= NISTC_AO_TRIG_START1_EDGE |
NISTC_AO_TRIG_START1_SYNC;
break;
case TRIG_EXT:
val = NISTC_AO_TRIG_START1_SEL(CR_CHAN(cmd->start_arg) + 1);
if (cmd->start_arg & CR_INVERT) {
val |= NISTC_AO_TRIG_START1_POLARITY;
}
if (cmd->start_arg & CR_EDGE) {
val |= NISTC_AO_TRIG_START1_EDGE;
}
ni_stc_writew(dev, devpriv->ao_trigger_select,
NISTC_AO_TRIG_SEL_REG);
break;
default:
BUG();
break;
}
devpriv->ao_trigger_select = val;
ni_stc_writew(dev, devpriv->ao_trigger_select, NISTC_AO_TRIG_SEL_REG);
devpriv->ao_mode3 &= ~NISTC_AO_MODE3_TRIG_LEN;
ni_stc_writew(dev, devpriv->ao_mode3, NISTC_AO_MODE3_REG);
ni_stc_writew(dev, devpriv->ao_mode1, NISTC_AO_MODE1_REG);
devpriv->ao_mode2 &= ~NISTC_AO_MODE2_BC_INIT_LOAD_SRC;
ni_stc_writew(dev, devpriv->ao_mode2, NISTC_AO_MODE2_REG);
if (cmd->stop_src == TRIG_NONE)
ni_stc_writel(dev, 0xffffff, NISTC_AO_BC_LOADA_REG);
else
ni_stc_writel(dev, 0, NISTC_AO_BC_LOADA_REG);
ni_stc_writew(dev, NISTC_AO_CMD1_BC_LOAD, NISTC_AO_CMD1_REG);
devpriv->ao_mode2 &= ~NISTC_AO_MODE2_UC_INIT_LOAD_SRC;
ni_stc_writew(dev, devpriv->ao_mode2, NISTC_AO_MODE2_REG);
switch (cmd->stop_src) {
case TRIG_COUNT:
if (devpriv->is_m_series) {
ni_stc_writel(dev, cmd->stop_arg - 1,
NISTC_AO_UC_LOADA_REG);
ni_stc_writew(dev, NISTC_AO_CMD1_UC_LOAD,
NISTC_AO_CMD1_REG);
} else {
ni_stc_writel(dev, cmd->stop_arg,
NISTC_AO_UC_LOADA_REG);
ni_stc_writew(dev, NISTC_AO_CMD1_UC_LOAD,
NISTC_AO_CMD1_REG);
ni_stc_writel(dev, cmd->stop_arg - 1,
NISTC_AO_UC_LOADA_REG);
}
break;
case TRIG_NONE:
ni_stc_writel(dev, 0xffffff, NISTC_AO_UC_LOADA_REG);
ni_stc_writew(dev, NISTC_AO_CMD1_UC_LOAD, NISTC_AO_CMD1_REG);
ni_stc_writel(dev, 0xffffff, NISTC_AO_UC_LOADA_REG);
break;
default:
ni_stc_writel(dev, 0, NISTC_AO_UC_LOADA_REG);
ni_stc_writew(dev, NISTC_AO_CMD1_UC_LOAD, NISTC_AO_CMD1_REG);
ni_stc_writel(dev, cmd->stop_arg, NISTC_AO_UC_LOADA_REG);
}
devpriv->ao_mode1 &= ~(NISTC_AO_MODE1_UPDATE_SRC_MASK |
NISTC_AO_MODE1_UI_SRC_MASK |
NISTC_AO_MODE1_UPDATE_SRC_POLARITY |
NISTC_AO_MODE1_UI_SRC_POLARITY);
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
devpriv->ao_cmd2 &= ~NISTC_AO_CMD2_BC_GATE_ENA;
trigvar =
ni_ns_to_timer(dev, cmd->scan_begin_arg,
CMDF_ROUND_NEAREST);
ni_stc_writel(dev, 1, NISTC_AO_UI_LOADA_REG);
ni_stc_writew(dev, NISTC_AO_CMD1_UI_LOAD, NISTC_AO_CMD1_REG);
ni_stc_writel(dev, trigvar, NISTC_AO_UI_LOADA_REG);
break;
case TRIG_EXT:
devpriv->ao_mode1 |=
NISTC_AO_MODE1_UPDATE_SRC(cmd->scan_begin_arg);
if (cmd->scan_begin_arg & CR_INVERT)
devpriv->ao_mode1 |= NISTC_AO_MODE1_UPDATE_SRC_POLARITY;
devpriv->ao_cmd2 |= NISTC_AO_CMD2_BC_GATE_ENA;
break;
default:
BUG();
break;
}
ni_stc_writew(dev, devpriv->ao_cmd2, NISTC_AO_CMD2_REG);
ni_stc_writew(dev, devpriv->ao_mode1, NISTC_AO_MODE1_REG);
devpriv->ao_mode2 &= ~(NISTC_AO_MODE2_UI_RELOAD_MODE(3) |
NISTC_AO_MODE2_UI_INIT_LOAD_SRC);
ni_stc_writew(dev, devpriv->ao_mode2, NISTC_AO_MODE2_REG);
if (cmd->scan_end_arg > 1) {
devpriv->ao_mode1 |= NISTC_AO_MODE1_MULTI_CHAN;
ni_stc_writew(dev,
NISTC_AO_OUT_CTRL_CHANS(cmd->scan_end_arg - 1) |
NISTC_AO_OUT_CTRL_UPDATE_SEL_HIGHZ,
NISTC_AO_OUT_CTRL_REG);
} else {
unsigned bits;
devpriv->ao_mode1 &= ~NISTC_AO_MODE1_MULTI_CHAN;
bits = NISTC_AO_OUT_CTRL_UPDATE_SEL_HIGHZ;
if (devpriv->is_m_series || devpriv->is_6xxx) {
bits |= NISTC_AO_OUT_CTRL_CHANS(0);
} else {
bits |=
NISTC_AO_OUT_CTRL_CHANS(CR_CHAN(cmd->chanlist[0]));
}
ni_stc_writew(dev, bits, NISTC_AO_OUT_CTRL_REG);
}
ni_stc_writew(dev, devpriv->ao_mode1, NISTC_AO_MODE1_REG);
ni_stc_writew(dev, NISTC_AO_CMD1_DAC1_UPDATE_MODE |
NISTC_AO_CMD1_DAC0_UPDATE_MODE,
NISTC_AO_CMD1_REG);
devpriv->ao_mode3 |= NISTC_AO_MODE3_STOP_ON_OVERRUN_ERR;
ni_stc_writew(dev, devpriv->ao_mode3, NISTC_AO_MODE3_REG);
devpriv->ao_mode2 &= ~NISTC_AO_MODE2_FIFO_MODE_MASK;
#ifdef PCIDMA
devpriv->ao_mode2 |= NISTC_AO_MODE2_FIFO_MODE_HF_F;
#else
devpriv->ao_mode2 |= NISTC_AO_MODE2_FIFO_MODE_HF;
#endif
devpriv->ao_mode2 &= ~NISTC_AO_MODE2_FIFO_REXMIT_ENA;
ni_stc_writew(dev, devpriv->ao_mode2, NISTC_AO_MODE2_REG);
bits = NISTC_AO_PERSONAL_BC_SRC_SEL |
NISTC_AO_PERSONAL_UPDATE_PW |
NISTC_AO_PERSONAL_TMRDACWR_PW;
if (board->ao_fifo_depth)
bits |= NISTC_AO_PERSONAL_FIFO_ENA;
else
bits |= NISTC_AO_PERSONAL_DMA_PIO_CTRL;
#if 0
if (devpriv->is_m_series)
bits |= NISTC_AO_PERSONAL_NUM_DAC;
#endif
ni_stc_writew(dev, bits, NISTC_AO_PERSONAL_REG);
ni_stc_writew(dev, NISTC_AO_START_AOFREQ_ENA, NISTC_AO_START_SEL_REG);
ni_stc_writew(dev, NISTC_RESET_AO_CFG_END, NISTC_RESET_REG);
if (cmd->stop_src == TRIG_COUNT) {
ni_stc_writew(dev, NISTC_INTB_ACK_AO_BC_TC,
NISTC_INTB_ACK_REG);
ni_set_bits(dev, NISTC_INTB_ENA_REG,
NISTC_INTB_ENA_AO_BC_TC, 1);
}
s->async->inttrig = ni_ao_inttrig;
return 0;
}
static int ni_ao_cmdtest(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
int err = 0;
unsigned int tmp;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_INT | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->start_src);
err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
switch (cmd->start_src) {
case TRIG_INT:
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
break;
case TRIG_EXT:
tmp = CR_CHAN(cmd->start_arg);
if (tmp > 18)
tmp = 18;
tmp |= (cmd->start_arg & (CR_INVERT | CR_EDGE));
err |= comedi_check_trigger_arg_is(&cmd->start_arg, tmp);
break;
}
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
board->ao_speed);
err |= comedi_check_trigger_arg_max(&cmd->scan_begin_arg,
devpriv->clock_ns *
0xffffff);
}
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_max(&cmd->stop_arg, 0x00ffffff);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
cmd->scan_begin_arg =
ni_timer_to_ns(dev, ni_ns_to_timer(dev,
cmd->scan_begin_arg,
cmd->flags));
if (tmp != cmd->scan_begin_arg)
err++;
}
if (err)
return 4;
return 0;
}
static int ni_ao_reset(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct ni_private *devpriv = dev->private;
ni_release_ao_mite_channel(dev);
ni_stc_writew(dev, NISTC_RESET_AO_CFG_START, NISTC_RESET_REG);
ni_stc_writew(dev, NISTC_AO_CMD1_DISARM, NISTC_AO_CMD1_REG);
ni_set_bits(dev, NISTC_INTB_ENA_REG, ~0, 0);
ni_stc_writew(dev, NISTC_AO_PERSONAL_BC_SRC_SEL, NISTC_AO_PERSONAL_REG);
ni_stc_writew(dev, NISTC_INTB_ACK_AO_ALL, NISTC_INTB_ACK_REG);
ni_stc_writew(dev, NISTC_AO_PERSONAL_BC_SRC_SEL |
NISTC_AO_PERSONAL_UPDATE_PW |
NISTC_AO_PERSONAL_TMRDACWR_PW,
NISTC_AO_PERSONAL_REG);
ni_stc_writew(dev, 0, NISTC_AO_OUT_CTRL_REG);
ni_stc_writew(dev, 0, NISTC_AO_START_SEL_REG);
devpriv->ao_cmd1 = 0;
ni_stc_writew(dev, devpriv->ao_cmd1, NISTC_AO_CMD1_REG);
devpriv->ao_cmd2 = 0;
ni_stc_writew(dev, devpriv->ao_cmd2, NISTC_AO_CMD2_REG);
devpriv->ao_mode1 = 0;
ni_stc_writew(dev, devpriv->ao_mode1, NISTC_AO_MODE1_REG);
devpriv->ao_mode2 = 0;
ni_stc_writew(dev, devpriv->ao_mode2, NISTC_AO_MODE2_REG);
if (devpriv->is_m_series)
devpriv->ao_mode3 = NISTC_AO_MODE3_LAST_GATE_DISABLE;
else
devpriv->ao_mode3 = 0;
ni_stc_writew(dev, devpriv->ao_mode3, NISTC_AO_MODE3_REG);
devpriv->ao_trigger_select = 0;
ni_stc_writew(dev, devpriv->ao_trigger_select,
NISTC_AO_TRIG_SEL_REG);
if (devpriv->is_6xxx) {
unsigned immediate_bits = 0;
unsigned i;
for (i = 0; i < s->n_chan; ++i)
immediate_bits |= 1 << i;
ni_ao_win_outw(dev, immediate_bits, NI671X_AO_IMMEDIATE_REG);
ni_ao_win_outw(dev, NI611X_AO_MISC_CLEAR_WG,
NI611X_AO_MISC_REG);
}
ni_stc_writew(dev, NISTC_RESET_AO_CFG_END, NISTC_RESET_REG);
return 0;
}
static int ni_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
devpriv->dio_control &= ~NISTC_DIO_CTRL_DIR_MASK;
devpriv->dio_control |= NISTC_DIO_CTRL_DIR(s->io_bits);
ni_stc_writew(dev, devpriv->dio_control, NISTC_DIO_CTRL_REG);
return insn->n;
}
static int ni_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
if ((data[0] & (NISTC_DIO_SDIN | NISTC_DIO_SDOUT)) &&
devpriv->serial_interval_ns)
return -EBUSY;
if (comedi_dio_update_state(s, data)) {
devpriv->dio_output &= ~NISTC_DIO_OUT_PARALLEL_MASK;
devpriv->dio_output |= NISTC_DIO_OUT_PARALLEL(s->state);
ni_stc_writew(dev, devpriv->dio_output, NISTC_DIO_OUT_REG);
}
data[1] = ni_stc_readw(dev, NISTC_DIO_IN_REG);
return insn->n;
}
static int ni_m_series_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
ni_writel(dev, s->io_bits, NI_M_DIO_DIR_REG);
return insn->n;
}
static int ni_m_series_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
ni_writel(dev, s->state, NI_M_DIO_REG);
data[1] = ni_readl(dev, NI_M_DIO_REG);
return insn->n;
}
static int ni_cdio_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int i;
for (i = 0; i < cmd->chanlist_len; ++i) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
if (chan != i)
return -EINVAL;
}
return 0;
}
static int ni_cdio_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_INT);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
tmp = cmd->scan_begin_arg;
tmp &= CR_PACK_FLAGS(NI_M_CDO_MODE_SAMPLE_SRC_MASK, 0, 0, CR_INVERT);
if (tmp != cmd->scan_begin_arg)
err |= -EINVAL;
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= ni_cdio_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int ni_cdo_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct comedi_cmd *cmd = &s->async->cmd;
const unsigned timeout = 1000;
int retval = 0;
unsigned i;
#ifdef PCIDMA
struct ni_private *devpriv = dev->private;
unsigned long flags;
#endif
if (trig_num != cmd->start_arg)
return -EINVAL;
s->async->inttrig = NULL;
comedi_buf_read_alloc(s, s->async->prealloc_bufsz);
#ifdef PCIDMA
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->cdo_mite_chan) {
mite_prep_dma(devpriv->cdo_mite_chan, 32, 32);
mite_dma_arm(devpriv->cdo_mite_chan);
} else {
dev_err(dev->class_dev, "BUG: no cdo mite channel?\n");
retval = -EIO;
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
if (retval < 0)
return retval;
#endif
for (i = 0; i < timeout; ++i) {
if (ni_readl(dev, NI_M_CDIO_STATUS_REG) &
NI_M_CDIO_STATUS_CDO_FIFO_FULL)
break;
udelay(10);
}
if (i == timeout) {
dev_err(dev->class_dev, "dma failed to fill cdo fifo!\n");
s->cancel(dev, s);
return -EIO;
}
ni_writel(dev, NI_M_CDO_CMD_ARM |
NI_M_CDO_CMD_ERR_INT_ENA_SET |
NI_M_CDO_CMD_F_E_INT_ENA_SET,
NI_M_CDIO_CMD_REG);
return retval;
}
static int ni_cdio_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
const struct comedi_cmd *cmd = &s->async->cmd;
unsigned cdo_mode_bits;
int retval;
ni_writel(dev, NI_M_CDO_CMD_RESET, NI_M_CDIO_CMD_REG);
cdo_mode_bits = NI_M_CDO_MODE_FIFO_MODE |
NI_M_CDO_MODE_HALT_ON_ERROR |
NI_M_CDO_MODE_SAMPLE_SRC(CR_CHAN(cmd->scan_begin_arg));
if (cmd->scan_begin_arg & CR_INVERT)
cdo_mode_bits |= NI_M_CDO_MODE_POLARITY;
ni_writel(dev, cdo_mode_bits, NI_M_CDO_MODE_REG);
if (s->io_bits) {
ni_writel(dev, s->state, NI_M_CDO_FIFO_DATA_REG);
ni_writel(dev, NI_M_CDO_CMD_SW_UPDATE, NI_M_CDIO_CMD_REG);
ni_writel(dev, s->io_bits, NI_M_CDO_MASK_ENA_REG);
} else {
dev_err(dev->class_dev,
"attempted to run digital output command with no lines configured as outputs\n");
return -EIO;
}
retval = ni_request_cdo_mite_channel(dev);
if (retval < 0)
return retval;
s->async->inttrig = ni_cdo_inttrig;
return 0;
}
static int ni_cdio_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
ni_writel(dev, NI_M_CDO_CMD_DISARM |
NI_M_CDO_CMD_ERR_INT_ENA_CLR |
NI_M_CDO_CMD_F_E_INT_ENA_CLR |
NI_M_CDO_CMD_F_REQ_INT_ENA_CLR,
NI_M_CDIO_CMD_REG);
ni_writel(dev, 0, NI_M_CDO_MASK_ENA_REG);
ni_release_cdo_mite_channel(dev);
return 0;
}
static void handle_cdio_interrupt(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
unsigned cdio_status;
struct comedi_subdevice *s = &dev->subdevices[NI_DIO_SUBDEV];
#ifdef PCIDMA
unsigned long flags;
#endif
if (!devpriv->is_m_series)
return;
#ifdef PCIDMA
spin_lock_irqsave(&devpriv->mite_channel_lock, flags);
if (devpriv->cdo_mite_chan) {
unsigned cdo_mite_status =
mite_get_status(devpriv->cdo_mite_chan);
if (cdo_mite_status & CHSR_LINKC) {
writel(CHOR_CLRLC,
devpriv->mite->mite_io_addr +
MITE_CHOR(devpriv->cdo_mite_chan->channel));
}
mite_sync_output_dma(devpriv->cdo_mite_chan, s);
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags);
#endif
cdio_status = ni_readl(dev, NI_M_CDIO_STATUS_REG);
if (cdio_status & NI_M_CDIO_STATUS_CDO_ERROR) {
ni_writel(dev, NI_M_CDO_CMD_ERR_INT_CONFIRM,
NI_M_CDIO_CMD_REG);
s->async->events |= COMEDI_CB_OVERFLOW;
}
if (cdio_status & NI_M_CDIO_STATUS_CDO_FIFO_EMPTY) {
ni_writel(dev, NI_M_CDO_CMD_F_E_INT_ENA_CLR,
NI_M_CDIO_CMD_REG);
}
comedi_handle_events(dev, s);
}
static int ni_serial_hw_readwrite8(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned char data_out,
unsigned char *data_in)
{
struct ni_private *devpriv = dev->private;
unsigned int status1;
int err = 0, count = 20;
devpriv->dio_output &= ~NISTC_DIO_OUT_SERIAL_MASK;
devpriv->dio_output |= NISTC_DIO_OUT_SERIAL(data_out);
ni_stc_writew(dev, devpriv->dio_output, NISTC_DIO_OUT_REG);
status1 = ni_stc_readw(dev, NISTC_STATUS1_REG);
if (status1 & NISTC_STATUS1_SERIO_IN_PROG) {
err = -EBUSY;
goto Error;
}
devpriv->dio_control |= NISTC_DIO_CTRL_HW_SER_START;
ni_stc_writew(dev, devpriv->dio_control, NISTC_DIO_CTRL_REG);
devpriv->dio_control &= ~NISTC_DIO_CTRL_HW_SER_START;
while ((status1 = ni_stc_readw(dev, NISTC_STATUS1_REG)) &
NISTC_STATUS1_SERIO_IN_PROG) {
udelay((devpriv->serial_interval_ns + 999) / 1000);
if (--count < 0) {
dev_err(dev->class_dev,
"SPI serial I/O didn't finish in time!\n");
err = -ETIME;
goto Error;
}
}
udelay((devpriv->serial_interval_ns + 999) / 1000);
if (data_in)
*data_in = ni_stc_readw(dev, NISTC_DIO_SERIAL_IN_REG);
Error:
ni_stc_writew(dev, devpriv->dio_control, NISTC_DIO_CTRL_REG);
return err;
}
static int ni_serial_sw_readwrite8(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned char data_out,
unsigned char *data_in)
{
struct ni_private *devpriv = dev->private;
unsigned char mask, input = 0;
udelay((devpriv->serial_interval_ns + 999) / 1000);
for (mask = 0x80; mask; mask >>= 1) {
devpriv->dio_output &= ~NISTC_DIO_SDOUT;
if (data_out & mask)
devpriv->dio_output |= NISTC_DIO_SDOUT;
ni_stc_writew(dev, devpriv->dio_output, NISTC_DIO_OUT_REG);
devpriv->dio_control |= NISTC_DIO_SDCLK;
ni_stc_writew(dev, devpriv->dio_control, NISTC_DIO_CTRL_REG);
udelay((devpriv->serial_interval_ns + 999) / 2000);
devpriv->dio_control &= ~NISTC_DIO_SDCLK;
ni_stc_writew(dev, devpriv->dio_control, NISTC_DIO_CTRL_REG);
udelay((devpriv->serial_interval_ns + 999) / 2000);
if (ni_stc_readw(dev, NISTC_DIO_IN_REG) & NISTC_DIO_SDIN)
input |= mask;
}
if (data_in)
*data_in = input;
return 0;
}
static int ni_serial_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
unsigned clk_fout = devpriv->clock_and_fout;
int err = insn->n;
unsigned char byte_out, byte_in = 0;
if (insn->n != 2)
return -EINVAL;
switch (data[0]) {
case INSN_CONFIG_SERIAL_CLOCK:
devpriv->serial_hw_mode = 1;
devpriv->dio_control |= NISTC_DIO_CTRL_HW_SER_ENA;
if (data[1] == SERIAL_DISABLED) {
devpriv->serial_hw_mode = 0;
devpriv->dio_control &= ~(NISTC_DIO_CTRL_HW_SER_ENA |
NISTC_DIO_SDCLK);
data[1] = SERIAL_DISABLED;
devpriv->serial_interval_ns = data[1];
} else if (data[1] <= SERIAL_600NS) {
devpriv->dio_control &= ~NISTC_DIO_CTRL_HW_SER_TIMEBASE;
clk_fout |= NISTC_CLK_FOUT_SLOW_TIMEBASE;
clk_fout &= ~NISTC_CLK_FOUT_DIO_SER_OUT_DIV2;
data[1] = SERIAL_600NS;
devpriv->serial_interval_ns = data[1];
} else if (data[1] <= SERIAL_1_2US) {
devpriv->dio_control &= ~NISTC_DIO_CTRL_HW_SER_TIMEBASE;
clk_fout |= NISTC_CLK_FOUT_SLOW_TIMEBASE |
NISTC_CLK_FOUT_DIO_SER_OUT_DIV2;
data[1] = SERIAL_1_2US;
devpriv->serial_interval_ns = data[1];
} else if (data[1] <= SERIAL_10US) {
devpriv->dio_control |= NISTC_DIO_CTRL_HW_SER_TIMEBASE;
clk_fout |= NISTC_CLK_FOUT_SLOW_TIMEBASE |
NISTC_CLK_FOUT_DIO_SER_OUT_DIV2;
data[1] = SERIAL_10US;
devpriv->serial_interval_ns = data[1];
} else {
devpriv->dio_control &= ~(NISTC_DIO_CTRL_HW_SER_ENA |
NISTC_DIO_SDCLK);
devpriv->serial_hw_mode = 0;
data[1] = (data[1] / 1000) * 1000;
devpriv->serial_interval_ns = data[1];
}
devpriv->clock_and_fout = clk_fout;
ni_stc_writew(dev, devpriv->dio_control, NISTC_DIO_CTRL_REG);
ni_stc_writew(dev, devpriv->clock_and_fout, NISTC_CLK_FOUT_REG);
return 1;
case INSN_CONFIG_BIDIRECTIONAL_DATA:
if (devpriv->serial_interval_ns == 0)
return -EINVAL;
byte_out = data[1] & 0xFF;
if (devpriv->serial_hw_mode) {
err = ni_serial_hw_readwrite8(dev, s, byte_out,
&byte_in);
} else if (devpriv->serial_interval_ns > 0) {
err = ni_serial_sw_readwrite8(dev, s, byte_out,
&byte_in);
} else {
dev_err(dev->class_dev, "serial disabled!\n");
return -EINVAL;
}
if (err < 0)
return err;
data[1] = byte_in & 0xFF;
return insn->n;
break;
default:
return -EINVAL;
}
}
static void init_ao_67xx(struct comedi_device *dev, struct comedi_subdevice *s)
{
int i;
for (i = 0; i < s->n_chan; i++) {
ni_ao_win_outw(dev, NI_E_AO_DACSEL(i) | 0x0,
NI67XX_AO_CFG2_REG);
}
ni_ao_win_outw(dev, 0x0, NI67XX_AO_SP_UPDATES_REG);
}
static unsigned int ni_gpct_to_stc_register(struct comedi_device *dev,
enum ni_gpct_register reg)
{
const struct mio_regmap *regmap;
if (reg < ARRAY_SIZE(ni_gpct_to_stc_regmap)) {
regmap = &ni_gpct_to_stc_regmap[reg];
} else {
dev_warn(dev->class_dev, "%s: unhandled register=0x%x\n",
__func__, reg);
return 0;
}
return regmap->mio_reg;
}
static void ni_gpct_write_register(struct ni_gpct *counter, unsigned bits,
enum ni_gpct_register reg)
{
struct comedi_device *dev = counter->counter_dev->dev;
unsigned int stc_register = ni_gpct_to_stc_register(dev, reg);
static const unsigned gpct_interrupt_a_enable_mask =
NISTC_INTA_ENA_G0_GATE | NISTC_INTA_ENA_G0_TC;
static const unsigned gpct_interrupt_b_enable_mask =
NISTC_INTB_ENA_G1_GATE | NISTC_INTB_ENA_G1_TC;
if (stc_register == 0)
return;
switch (reg) {
case NITIO_G0_CNT_MODE:
case NITIO_G1_CNT_MODE:
case NITIO_G0_GATE2:
case NITIO_G1_GATE2:
case NITIO_G0_DMA_CFG:
case NITIO_G1_DMA_CFG:
case NITIO_G0_ABZ:
case NITIO_G1_ABZ:
ni_writew(dev, bits, stc_register);
break;
case NITIO_G0_LOADA:
case NITIO_G1_LOADA:
case NITIO_G0_LOADB:
case NITIO_G1_LOADB:
ni_stc_writel(dev, bits, stc_register);
break;
case NITIO_G0_INT_ENA:
BUG_ON(bits & ~gpct_interrupt_a_enable_mask);
ni_set_bitfield(dev, stc_register,
gpct_interrupt_a_enable_mask, bits);
break;
case NITIO_G1_INT_ENA:
BUG_ON(bits & ~gpct_interrupt_b_enable_mask);
ni_set_bitfield(dev, stc_register,
gpct_interrupt_b_enable_mask, bits);
break;
case NITIO_G01_RESET:
BUG_ON(bits & ~(NISTC_RESET_G0 | NISTC_RESET_G1));
default:
ni_stc_writew(dev, bits, stc_register);
}
}
static unsigned ni_gpct_read_register(struct ni_gpct *counter,
enum ni_gpct_register reg)
{
struct comedi_device *dev = counter->counter_dev->dev;
unsigned int stc_register = ni_gpct_to_stc_register(dev, reg);
if (stc_register == 0)
return 0;
switch (reg) {
case NITIO_G0_DMA_STATUS:
case NITIO_G1_DMA_STATUS:
return ni_readw(dev, stc_register);
case NITIO_G0_HW_SAVE:
case NITIO_G1_HW_SAVE:
case NITIO_G0_SW_SAVE:
case NITIO_G1_SW_SAVE:
return ni_stc_readl(dev, stc_register);
default:
return ni_stc_readw(dev, stc_register);
}
}
static int ni_freq_out_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
unsigned int val = NISTC_CLK_FOUT_TO_DIVIDER(devpriv->clock_and_fout);
int i;
for (i = 0; i < insn->n; i++)
data[i] = val;
return insn->n;
}
static int ni_freq_out_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
if (insn->n) {
unsigned int val = data[insn->n - 1];
devpriv->clock_and_fout &= ~NISTC_CLK_FOUT_ENA;
ni_stc_writew(dev, devpriv->clock_and_fout, NISTC_CLK_FOUT_REG);
devpriv->clock_and_fout &= ~NISTC_CLK_FOUT_DIVIDER_MASK;
devpriv->clock_and_fout |= NISTC_CLK_FOUT_DIVIDER(val);
devpriv->clock_and_fout |= NISTC_CLK_FOUT_ENA;
ni_stc_writew(dev, devpriv->clock_and_fout, NISTC_CLK_FOUT_REG);
}
return insn->n;
}
static int ni_freq_out_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
switch (data[0]) {
case INSN_CONFIG_SET_CLOCK_SRC:
switch (data[1]) {
case NI_FREQ_OUT_TIMEBASE_1_DIV_2_CLOCK_SRC:
devpriv->clock_and_fout &= ~NISTC_CLK_FOUT_TIMEBASE_SEL;
break;
case NI_FREQ_OUT_TIMEBASE_2_CLOCK_SRC:
devpriv->clock_and_fout |= NISTC_CLK_FOUT_TIMEBASE_SEL;
break;
default:
return -EINVAL;
}
ni_stc_writew(dev, devpriv->clock_and_fout, NISTC_CLK_FOUT_REG);
break;
case INSN_CONFIG_GET_CLOCK_SRC:
if (devpriv->clock_and_fout & NISTC_CLK_FOUT_TIMEBASE_SEL) {
data[1] = NI_FREQ_OUT_TIMEBASE_2_CLOCK_SRC;
data[2] = TIMEBASE_2_NS;
} else {
data[1] = NI_FREQ_OUT_TIMEBASE_1_DIV_2_CLOCK_SRC;
data[2] = TIMEBASE_1_NS * 2;
}
break;
default:
return -EINVAL;
}
return insn->n;
}
static int ni_8255_callback(struct comedi_device *dev,
int dir, int port, int data, unsigned long iobase)
{
if (dir) {
ni_writeb(dev, data, iobase + 2 * port);
return 0;
}
return ni_readb(dev, iobase + 2 * port);
}
static int ni_get_pwm_config(struct comedi_device *dev, unsigned int *data)
{
struct ni_private *devpriv = dev->private;
data[1] = devpriv->pwm_up_count * devpriv->clock_ns;
data[2] = devpriv->pwm_down_count * devpriv->clock_ns;
return 3;
}
static int ni_m_series_pwm_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
unsigned up_count, down_count;
switch (data[0]) {
case INSN_CONFIG_PWM_OUTPUT:
switch (data[1]) {
case CMDF_ROUND_NEAREST:
up_count =
(data[2] +
devpriv->clock_ns / 2) / devpriv->clock_ns;
break;
case CMDF_ROUND_DOWN:
up_count = data[2] / devpriv->clock_ns;
break;
case CMDF_ROUND_UP:
up_count =
(data[2] + devpriv->clock_ns -
1) / devpriv->clock_ns;
break;
default:
return -EINVAL;
}
switch (data[3]) {
case CMDF_ROUND_NEAREST:
down_count =
(data[4] +
devpriv->clock_ns / 2) / devpriv->clock_ns;
break;
case CMDF_ROUND_DOWN:
down_count = data[4] / devpriv->clock_ns;
break;
case CMDF_ROUND_UP:
down_count =
(data[4] + devpriv->clock_ns -
1) / devpriv->clock_ns;
break;
default:
return -EINVAL;
}
if (up_count * devpriv->clock_ns != data[2] ||
down_count * devpriv->clock_ns != data[4]) {
data[2] = up_count * devpriv->clock_ns;
data[4] = down_count * devpriv->clock_ns;
return -EAGAIN;
}
ni_writel(dev, NI_M_CAL_PWM_HIGH_TIME(up_count) |
NI_M_CAL_PWM_LOW_TIME(down_count),
NI_M_CAL_PWM_REG);
devpriv->pwm_up_count = up_count;
devpriv->pwm_down_count = down_count;
return 5;
case INSN_CONFIG_GET_PWM_OUTPUT:
return ni_get_pwm_config(dev, data);
default:
return -EINVAL;
}
return 0;
}
static int ni_6143_pwm_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
unsigned up_count, down_count;
switch (data[0]) {
case INSN_CONFIG_PWM_OUTPUT:
switch (data[1]) {
case CMDF_ROUND_NEAREST:
up_count =
(data[2] +
devpriv->clock_ns / 2) / devpriv->clock_ns;
break;
case CMDF_ROUND_DOWN:
up_count = data[2] / devpriv->clock_ns;
break;
case CMDF_ROUND_UP:
up_count =
(data[2] + devpriv->clock_ns -
1) / devpriv->clock_ns;
break;
default:
return -EINVAL;
}
switch (data[3]) {
case CMDF_ROUND_NEAREST:
down_count =
(data[4] +
devpriv->clock_ns / 2) / devpriv->clock_ns;
break;
case CMDF_ROUND_DOWN:
down_count = data[4] / devpriv->clock_ns;
break;
case CMDF_ROUND_UP:
down_count =
(data[4] + devpriv->clock_ns -
1) / devpriv->clock_ns;
break;
default:
return -EINVAL;
}
if (up_count * devpriv->clock_ns != data[2] ||
down_count * devpriv->clock_ns != data[4]) {
data[2] = up_count * devpriv->clock_ns;
data[4] = down_count * devpriv->clock_ns;
return -EAGAIN;
}
ni_writel(dev, up_count, NI6143_CALIB_HI_TIME_REG);
devpriv->pwm_up_count = up_count;
ni_writel(dev, down_count, NI6143_CALIB_LO_TIME_REG);
devpriv->pwm_down_count = down_count;
return 5;
case INSN_CONFIG_GET_PWM_OUTPUT:
return ni_get_pwm_config(dev, data);
default:
return -EINVAL;
}
return 0;
}
static int pack_mb88341(int addr, int val, int *bitstring)
{
addr++;
*bitstring = ((addr & 0x1) << 11) |
((addr & 0x2) << 9) |
((addr & 0x4) << 7) | ((addr & 0x8) << 5) | (val & 0xff);
return 12;
}
static int pack_dac8800(int addr, int val, int *bitstring)
{
*bitstring = ((addr & 0x7) << 8) | (val & 0xff);
return 11;
}
static int pack_dac8043(int addr, int val, int *bitstring)
{
*bitstring = val & 0xfff;
return 12;
}
static int pack_ad8522(int addr, int val, int *bitstring)
{
*bitstring = (val & 0xfff) | (addr ? 0xc000 : 0xa000);
return 16;
}
static int pack_ad8804(int addr, int val, int *bitstring)
{
*bitstring = ((addr & 0xf) << 8) | (val & 0xff);
return 12;
}
static int pack_ad8842(int addr, int val, int *bitstring)
{
*bitstring = ((addr + 1) << 8) | (val & 0xff);
return 12;
}
static void ni_write_caldac(struct comedi_device *dev, int addr, int val)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
unsigned int loadbit = 0, bits = 0, bit, bitstring = 0;
unsigned int cmd;
int i;
int type;
if (devpriv->caldacs[addr] == val)
return;
devpriv->caldacs[addr] = val;
for (i = 0; i < 3; i++) {
type = board->caldac[i];
if (type == caldac_none)
break;
if (addr < caldacs[type].n_chans) {
bits = caldacs[type].packbits(addr, val, &bitstring);
loadbit = NI_E_SERIAL_CMD_DAC_LD(i);
break;
}
addr -= caldacs[type].n_chans;
}
if (bits == 0)
return;
for (bit = 1 << (bits - 1); bit; bit >>= 1) {
cmd = (bit & bitstring) ? NI_E_SERIAL_CMD_SDATA : 0;
ni_writeb(dev, cmd, NI_E_SERIAL_CMD_REG);
udelay(1);
ni_writeb(dev, NI_E_SERIAL_CMD_SCLK | cmd, NI_E_SERIAL_CMD_REG);
udelay(1);
}
ni_writeb(dev, loadbit, NI_E_SERIAL_CMD_REG);
udelay(1);
ni_writeb(dev, 0, NI_E_SERIAL_CMD_REG);
}
static int ni_calib_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
ni_write_caldac(dev, CR_CHAN(insn->chanspec), data[0]);
return 1;
}
static int ni_calib_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
data[0] = devpriv->caldacs[CR_CHAN(insn->chanspec)];
return 1;
}
static void caldac_setup(struct comedi_device *dev, struct comedi_subdevice *s)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
int i, j;
int n_dacs;
int n_chans = 0;
int n_bits;
int diffbits = 0;
int type;
int chan;
type = board->caldac[0];
if (type == caldac_none)
return;
n_bits = caldacs[type].n_bits;
for (i = 0; i < 3; i++) {
type = board->caldac[i];
if (type == caldac_none)
break;
if (caldacs[type].n_bits != n_bits)
diffbits = 1;
n_chans += caldacs[type].n_chans;
}
n_dacs = i;
s->n_chan = n_chans;
if (diffbits) {
unsigned int *maxdata_list;
if (n_chans > MAX_N_CALDACS)
dev_err(dev->class_dev,
"BUG! MAX_N_CALDACS too small\n");
s->maxdata_list = maxdata_list = devpriv->caldac_maxdata_list;
chan = 0;
for (i = 0; i < n_dacs; i++) {
type = board->caldac[i];
for (j = 0; j < caldacs[type].n_chans; j++) {
maxdata_list[chan] =
(1 << caldacs[type].n_bits) - 1;
chan++;
}
}
for (chan = 0; chan < s->n_chan; chan++)
ni_write_caldac(dev, i, s->maxdata_list[i] / 2);
} else {
type = board->caldac[0];
s->maxdata = (1 << caldacs[type].n_bits) - 1;
for (chan = 0; chan < s->n_chan; chan++)
ni_write_caldac(dev, i, s->maxdata / 2);
}
}
static int ni_read_eeprom(struct comedi_device *dev, int addr)
{
unsigned int cmd = NI_E_SERIAL_CMD_EEPROM_CS;
int bit;
int bitstring;
bitstring = 0x0300 | ((addr & 0x100) << 3) | (addr & 0xff);
ni_writeb(dev, cmd, NI_E_SERIAL_CMD_REG);
for (bit = 0x8000; bit; bit >>= 1) {
if (bit & bitstring)
cmd |= NI_E_SERIAL_CMD_SDATA;
else
cmd &= ~NI_E_SERIAL_CMD_SDATA;
ni_writeb(dev, cmd, NI_E_SERIAL_CMD_REG);
ni_writeb(dev, NI_E_SERIAL_CMD_SCLK | cmd, NI_E_SERIAL_CMD_REG);
}
cmd = NI_E_SERIAL_CMD_EEPROM_CS;
bitstring = 0;
for (bit = 0x80; bit; bit >>= 1) {
ni_writeb(dev, cmd, NI_E_SERIAL_CMD_REG);
ni_writeb(dev, NI_E_SERIAL_CMD_SCLK | cmd, NI_E_SERIAL_CMD_REG);
if (ni_readb(dev, NI_E_STATUS_REG) & NI_E_STATUS_PROMOUT)
bitstring |= bit;
}
ni_writeb(dev, 0, NI_E_SERIAL_CMD_REG);
return bitstring;
}
static int ni_eeprom_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[0] = ni_read_eeprom(dev, CR_CHAN(insn->chanspec));
return 1;
}
static int ni_m_series_eeprom_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
data[0] = devpriv->eeprom_buffer[CR_CHAN(insn->chanspec)];
return 1;
}
static unsigned ni_old_get_pfi_routing(struct comedi_device *dev,
unsigned chan)
{
switch (chan) {
case 0:
return NI_PFI_OUTPUT_AI_START1;
case 1:
return NI_PFI_OUTPUT_AI_START2;
case 2:
return NI_PFI_OUTPUT_AI_CONVERT;
case 3:
return NI_PFI_OUTPUT_G_SRC1;
case 4:
return NI_PFI_OUTPUT_G_GATE1;
case 5:
return NI_PFI_OUTPUT_AO_UPDATE_N;
case 6:
return NI_PFI_OUTPUT_AO_START1;
case 7:
return NI_PFI_OUTPUT_AI_START_PULSE;
case 8:
return NI_PFI_OUTPUT_G_SRC0;
case 9:
return NI_PFI_OUTPUT_G_GATE0;
default:
dev_err(dev->class_dev, "bug, unhandled case in switch.\n");
break;
}
return 0;
}
static int ni_old_set_pfi_routing(struct comedi_device *dev,
unsigned chan, unsigned source)
{
if (source != ni_old_get_pfi_routing(dev, chan))
return -EINVAL;
return 2;
}
static unsigned ni_m_series_get_pfi_routing(struct comedi_device *dev,
unsigned chan)
{
struct ni_private *devpriv = dev->private;
const unsigned array_offset = chan / 3;
return NI_M_PFI_OUT_SEL_TO_SRC(chan,
devpriv->pfi_output_select_reg[array_offset]);
}
static int ni_m_series_set_pfi_routing(struct comedi_device *dev,
unsigned chan, unsigned source)
{
struct ni_private *devpriv = dev->private;
unsigned index = chan / 3;
unsigned short val = devpriv->pfi_output_select_reg[index];
if ((source & 0x1f) != source)
return -EINVAL;
val &= ~NI_M_PFI_OUT_SEL_MASK(chan);
val |= NI_M_PFI_OUT_SEL(chan, source);
ni_writew(dev, val, NI_M_PFI_OUT_SEL_REG(index));
devpriv->pfi_output_select_reg[index] = val;
return 2;
}
static unsigned ni_get_pfi_routing(struct comedi_device *dev, unsigned chan)
{
struct ni_private *devpriv = dev->private;
return (devpriv->is_m_series)
? ni_m_series_get_pfi_routing(dev, chan)
: ni_old_get_pfi_routing(dev, chan);
}
static int ni_set_pfi_routing(struct comedi_device *dev, unsigned chan,
unsigned source)
{
struct ni_private *devpriv = dev->private;
return (devpriv->is_m_series)
? ni_m_series_set_pfi_routing(dev, chan, source)
: ni_old_set_pfi_routing(dev, chan, source);
}
static int ni_config_filter(struct comedi_device *dev,
unsigned pfi_channel,
enum ni_pfi_filter_select filter)
{
struct ni_private *devpriv = dev->private;
unsigned bits;
if (!devpriv->is_m_series)
return -ENOTSUPP;
bits = ni_readl(dev, NI_M_PFI_FILTER_REG);
bits &= ~NI_M_PFI_FILTER_SEL_MASK(pfi_channel);
bits |= NI_M_PFI_FILTER_SEL(pfi_channel, filter);
ni_writel(dev, bits, NI_M_PFI_FILTER_REG);
return 0;
}
static int ni_pfi_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
unsigned int chan;
if (insn->n < 1)
return -EINVAL;
chan = CR_CHAN(insn->chanspec);
switch (data[0]) {
case COMEDI_OUTPUT:
ni_set_bits(dev, NISTC_IO_BIDIR_PIN_REG, 1 << chan, 1);
break;
case COMEDI_INPUT:
ni_set_bits(dev, NISTC_IO_BIDIR_PIN_REG, 1 << chan, 0);
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(devpriv->io_bidirection_pin_reg & (1 << chan)) ?
COMEDI_OUTPUT : COMEDI_INPUT;
return 0;
case INSN_CONFIG_SET_ROUTING:
return ni_set_pfi_routing(dev, chan, data[1]);
case INSN_CONFIG_GET_ROUTING:
data[1] = ni_get_pfi_routing(dev, chan);
break;
case INSN_CONFIG_FILTER:
return ni_config_filter(dev, chan, data[1]);
default:
return -EINVAL;
}
return 0;
}
static int ni_pfi_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
if (!devpriv->is_m_series)
return -ENOTSUPP;
if (comedi_dio_update_state(s, data))
ni_writew(dev, s->state, NI_M_PFI_DO_REG);
data[1] = ni_readw(dev, NI_M_PFI_DI_REG);
return insn->n;
}
static int cs5529_wait_for_idle(struct comedi_device *dev)
{
unsigned short status;
const int timeout = HZ;
int i;
for (i = 0; i < timeout; i++) {
status = ni_ao_win_inw(dev, NI67XX_CAL_STATUS_REG);
if ((status & NI67XX_CAL_STATUS_BUSY) == 0)
break;
set_current_state(TASK_INTERRUPTIBLE);
if (schedule_timeout(1))
return -EIO;
}
if (i == timeout) {
dev_err(dev->class_dev, "timeout\n");
return -ETIME;
}
return 0;
}
static void cs5529_command(struct comedi_device *dev, unsigned short value)
{
static const int timeout = 100;
int i;
ni_ao_win_outw(dev, value, NI67XX_CAL_CMD_REG);
for (i = 0; i < timeout; i++) {
if (ni_ao_win_inw(dev, NI67XX_CAL_STATUS_REG) &
NI67XX_CAL_STATUS_BUSY)
break;
udelay(1);
}
if (i == timeout)
dev_err(dev->class_dev,
"possible problem - never saw adc go busy?\n");
}
static int cs5529_do_conversion(struct comedi_device *dev,
unsigned short *data)
{
int retval;
unsigned short status;
cs5529_command(dev, CS5529_CMD_CB | CS5529_CMD_SINGLE_CONV);
retval = cs5529_wait_for_idle(dev);
if (retval) {
dev_err(dev->class_dev,
"timeout or signal in cs5529_do_conversion()\n");
return -ETIME;
}
status = ni_ao_win_inw(dev, NI67XX_CAL_STATUS_REG);
if (status & NI67XX_CAL_STATUS_OSC_DETECT) {
dev_err(dev->class_dev,
"cs5529 conversion error, status CSS_OSC_DETECT\n");
return -EIO;
}
if (status & NI67XX_CAL_STATUS_OVERRANGE) {
dev_err(dev->class_dev,
"cs5529 conversion error, overrange (ignoring)\n");
}
if (data) {
*data = ni_ao_win_inw(dev, NI67XX_CAL_DATA_REG);
*data ^= (1 << 15);
}
return 0;
}
static int cs5529_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int n, retval;
unsigned short sample;
unsigned int channel_select;
const unsigned int INTERNAL_REF = 0x1000;
if (insn->chanspec & CR_ALT_SOURCE)
channel_select = INTERNAL_REF;
else
channel_select = CR_CHAN(insn->chanspec);
ni_ao_win_outw(dev, channel_select, NI67XX_AO_CAL_CHAN_SEL_REG);
for (n = 0; n < insn->n; n++) {
retval = cs5529_do_conversion(dev, &sample);
if (retval < 0)
return retval;
data[n] = sample;
}
return insn->n;
}
static void cs5529_config_write(struct comedi_device *dev, unsigned int value,
unsigned int reg_select_bits)
{
ni_ao_win_outw(dev, (value >> 16) & 0xff, NI67XX_CAL_CFG_HI_REG);
ni_ao_win_outw(dev, value & 0xffff, NI67XX_CAL_CFG_LO_REG);
reg_select_bits &= CS5529_CMD_REG_MASK;
cs5529_command(dev, CS5529_CMD_CB | reg_select_bits);
if (cs5529_wait_for_idle(dev))
dev_err(dev->class_dev,
"timeout or signal in %s\n", __func__);
}
static int init_cs5529(struct comedi_device *dev)
{
unsigned int config_bits = CS5529_CFG_PORT_FLAG |
CS5529_CFG_WORD_RATE_2180;
#if 1
cs5529_config_write(dev, config_bits | CS5529_CFG_CALIB_BOTH_SELF,
CS5529_CFG_REG);
cs5529_do_conversion(dev, NULL);
#else
cs5529_config_write(dev, 0x400000, CS5529_GAIN_REG);
cs5529_config_write(dev, config_bits | CS5529_CFG_CALIB_OFFSET_SELF,
CS5529_CFG_REG);
if (cs5529_wait_for_idle(dev))
dev_err(dev->class_dev,
"timeout or signal in %s\n", __func__);
#endif
return 0;
}
static int ni_mseries_get_pll_parameters(unsigned reference_period_ns,
unsigned *freq_divider,
unsigned *freq_multiplier,
unsigned *actual_period_ns)
{
unsigned div;
unsigned best_div = 1;
unsigned mult;
unsigned best_mult = 1;
static const unsigned pico_per_nano = 1000;
const unsigned reference_picosec = reference_period_ns * pico_per_nano;
static const unsigned target_picosec = 12500;
static const unsigned fudge_factor_80_to_20Mhz = 4;
int best_period_picosec = 0;
for (div = 1; div <= NI_M_PLL_MAX_DIVISOR; ++div) {
for (mult = 1; mult <= NI_M_PLL_MAX_MULTIPLIER; ++mult) {
unsigned new_period_ps =
(reference_picosec * div) / mult;
if (abs(new_period_ps - target_picosec) <
abs(best_period_picosec - target_picosec)) {
best_period_picosec = new_period_ps;
best_div = div;
best_mult = mult;
}
}
}
if (best_period_picosec == 0)
return -EIO;
*freq_divider = best_div;
*freq_multiplier = best_mult;
*actual_period_ns =
(best_period_picosec * fudge_factor_80_to_20Mhz +
(pico_per_nano / 2)) / pico_per_nano;
return 0;
}
static int ni_mseries_set_pll_master_clock(struct comedi_device *dev,
unsigned source, unsigned period_ns)
{
struct ni_private *devpriv = dev->private;
static const unsigned min_period_ns = 50;
static const unsigned max_period_ns = 1000;
static const unsigned timeout = 1000;
unsigned pll_control_bits;
unsigned freq_divider;
unsigned freq_multiplier;
unsigned rtsi;
unsigned i;
int retval;
if (source == NI_MIO_PLL_PXI10_CLOCK)
period_ns = 100;
if (period_ns < min_period_ns || period_ns > max_period_ns) {
dev_err(dev->class_dev,
"%s: you must specify an input clock frequency between %i and %i nanosec for the phased-lock loop\n",
__func__, min_period_ns, max_period_ns);
return -EINVAL;
}
devpriv->rtsi_trig_direction_reg &= ~NISTC_RTSI_TRIG_USE_CLK;
ni_stc_writew(dev, devpriv->rtsi_trig_direction_reg,
NISTC_RTSI_TRIG_DIR_REG);
pll_control_bits = NI_M_PLL_CTRL_ENA | NI_M_PLL_CTRL_VCO_MODE_75_150MHZ;
devpriv->clock_and_fout2 |= NI_M_CLK_FOUT2_TIMEBASE1_PLL |
NI_M_CLK_FOUT2_TIMEBASE3_PLL;
devpriv->clock_and_fout2 &= ~NI_M_CLK_FOUT2_PLL_SRC_MASK;
switch (source) {
case NI_MIO_PLL_PXI_STAR_TRIGGER_CLOCK:
devpriv->clock_and_fout2 |= NI_M_CLK_FOUT2_PLL_SRC_STAR;
break;
case NI_MIO_PLL_PXI10_CLOCK:
devpriv->clock_and_fout2 |= NI_M_CLK_FOUT2_PLL_SRC_PXI10;
break;
default:
for (rtsi = 0; rtsi <= NI_M_MAX_RTSI_CHAN; ++rtsi) {
if (source == NI_MIO_PLL_RTSI_CLOCK(rtsi)) {
devpriv->clock_and_fout2 |=
NI_M_CLK_FOUT2_PLL_SRC_RTSI(rtsi);
break;
}
}
if (rtsi > NI_M_MAX_RTSI_CHAN)
return -EINVAL;
break;
}
retval = ni_mseries_get_pll_parameters(period_ns,
&freq_divider,
&freq_multiplier,
&devpriv->clock_ns);
if (retval < 0) {
dev_err(dev->class_dev,
"bug, failed to find pll parameters\n");
return retval;
}
ni_writew(dev, devpriv->clock_and_fout2, NI_M_CLK_FOUT2_REG);
pll_control_bits |= NI_M_PLL_CTRL_DIVISOR(freq_divider) |
NI_M_PLL_CTRL_MULTIPLIER(freq_multiplier);
ni_writew(dev, pll_control_bits, NI_M_PLL_CTRL_REG);
devpriv->clock_source = source;
for (i = 0; i < timeout; ++i) {
if (ni_readw(dev, NI_M_PLL_STATUS_REG) & NI_M_PLL_STATUS_LOCKED)
break;
udelay(1);
}
if (i == timeout) {
dev_err(dev->class_dev,
"%s: timed out waiting for PLL to lock to reference clock source %i with period %i ns\n",
__func__, source, period_ns);
return -ETIMEDOUT;
}
return 3;
}
static int ni_set_master_clock(struct comedi_device *dev,
unsigned source, unsigned period_ns)
{
struct ni_private *devpriv = dev->private;
if (source == NI_MIO_INTERNAL_CLOCK) {
devpriv->rtsi_trig_direction_reg &= ~NISTC_RTSI_TRIG_USE_CLK;
ni_stc_writew(dev, devpriv->rtsi_trig_direction_reg,
NISTC_RTSI_TRIG_DIR_REG);
devpriv->clock_ns = TIMEBASE_1_NS;
if (devpriv->is_m_series) {
devpriv->clock_and_fout2 &=
~(NI_M_CLK_FOUT2_TIMEBASE1_PLL |
NI_M_CLK_FOUT2_TIMEBASE3_PLL);
ni_writew(dev, devpriv->clock_and_fout2,
NI_M_CLK_FOUT2_REG);
ni_writew(dev, 0, NI_M_PLL_CTRL_REG);
}
devpriv->clock_source = source;
} else {
if (devpriv->is_m_series) {
return ni_mseries_set_pll_master_clock(dev, source,
period_ns);
} else {
if (source == NI_MIO_RTSI_CLOCK) {
devpriv->rtsi_trig_direction_reg |=
NISTC_RTSI_TRIG_USE_CLK;
ni_stc_writew(dev,
devpriv->rtsi_trig_direction_reg,
NISTC_RTSI_TRIG_DIR_REG);
if (period_ns == 0) {
dev_err(dev->class_dev,
"we don't handle an unspecified clock period correctly yet, returning error\n");
return -EINVAL;
}
devpriv->clock_ns = period_ns;
devpriv->clock_source = source;
} else {
return -EINVAL;
}
}
}
return 3;
}
static int ni_valid_rtsi_output_source(struct comedi_device *dev,
unsigned chan, unsigned source)
{
struct ni_private *devpriv = dev->private;
if (chan >= NISTC_RTSI_TRIG_NUM_CHAN(devpriv->is_m_series)) {
if (chan == NISTC_RTSI_TRIG_OLD_CLK_CHAN) {
if (source == NI_RTSI_OUTPUT_RTSI_OSC)
return 1;
dev_err(dev->class_dev,
"%s: invalid source for channel=%i, channel %i is always the RTSI clock for pre-m-series boards\n",
__func__, chan, NISTC_RTSI_TRIG_OLD_CLK_CHAN);
return 0;
}
return 0;
}
switch (source) {
case NI_RTSI_OUTPUT_ADR_START1:
case NI_RTSI_OUTPUT_ADR_START2:
case NI_RTSI_OUTPUT_SCLKG:
case NI_RTSI_OUTPUT_DACUPDN:
case NI_RTSI_OUTPUT_DA_START1:
case NI_RTSI_OUTPUT_G_SRC0:
case NI_RTSI_OUTPUT_G_GATE0:
case NI_RTSI_OUTPUT_RGOUT0:
case NI_RTSI_OUTPUT_RTSI_BRD_0:
return 1;
case NI_RTSI_OUTPUT_RTSI_OSC:
return (devpriv->is_m_series) ? 1 : 0;
default:
return 0;
}
}
static int ni_set_rtsi_routing(struct comedi_device *dev,
unsigned chan, unsigned src)
{
struct ni_private *devpriv = dev->private;
if (ni_valid_rtsi_output_source(dev, chan, src) == 0)
return -EINVAL;
if (chan < 4) {
devpriv->rtsi_trig_a_output_reg &= ~NISTC_RTSI_TRIG_MASK(chan);
devpriv->rtsi_trig_a_output_reg |= NISTC_RTSI_TRIG(chan, src);
ni_stc_writew(dev, devpriv->rtsi_trig_a_output_reg,
NISTC_RTSI_TRIGA_OUT_REG);
} else if (chan < 8) {
devpriv->rtsi_trig_b_output_reg &= ~NISTC_RTSI_TRIG_MASK(chan);
devpriv->rtsi_trig_b_output_reg |= NISTC_RTSI_TRIG(chan, src);
ni_stc_writew(dev, devpriv->rtsi_trig_b_output_reg,
NISTC_RTSI_TRIGB_OUT_REG);
}
return 2;
}
static unsigned ni_get_rtsi_routing(struct comedi_device *dev, unsigned chan)
{
struct ni_private *devpriv = dev->private;
if (chan < 4) {
return NISTC_RTSI_TRIG_TO_SRC(chan,
devpriv->rtsi_trig_a_output_reg);
} else if (chan < NISTC_RTSI_TRIG_NUM_CHAN(devpriv->is_m_series)) {
return NISTC_RTSI_TRIG_TO_SRC(chan,
devpriv->rtsi_trig_b_output_reg);
} else {
if (chan == NISTC_RTSI_TRIG_OLD_CLK_CHAN)
return NI_RTSI_OUTPUT_RTSI_OSC;
dev_err(dev->class_dev, "bug! should never get here?\n");
return 0;
}
}
static int ni_rtsi_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int max_chan = NISTC_RTSI_TRIG_NUM_CHAN(devpriv->is_m_series);
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
if (chan < max_chan) {
devpriv->rtsi_trig_direction_reg |=
NISTC_RTSI_TRIG_DIR(chan, devpriv->is_m_series);
} else if (chan == NISTC_RTSI_TRIG_OLD_CLK_CHAN) {
devpriv->rtsi_trig_direction_reg |=
NISTC_RTSI_TRIG_DRV_CLK;
}
ni_stc_writew(dev, devpriv->rtsi_trig_direction_reg,
NISTC_RTSI_TRIG_DIR_REG);
break;
case INSN_CONFIG_DIO_INPUT:
if (chan < max_chan) {
devpriv->rtsi_trig_direction_reg &=
~NISTC_RTSI_TRIG_DIR(chan, devpriv->is_m_series);
} else if (chan == NISTC_RTSI_TRIG_OLD_CLK_CHAN) {
devpriv->rtsi_trig_direction_reg &=
~NISTC_RTSI_TRIG_DRV_CLK;
}
ni_stc_writew(dev, devpriv->rtsi_trig_direction_reg,
NISTC_RTSI_TRIG_DIR_REG);
break;
case INSN_CONFIG_DIO_QUERY:
if (chan < max_chan) {
data[1] =
(devpriv->rtsi_trig_direction_reg &
NISTC_RTSI_TRIG_DIR(chan, devpriv->is_m_series))
? INSN_CONFIG_DIO_OUTPUT
: INSN_CONFIG_DIO_INPUT;
} else if (chan == NISTC_RTSI_TRIG_OLD_CLK_CHAN) {
data[1] = (devpriv->rtsi_trig_direction_reg &
NISTC_RTSI_TRIG_DRV_CLK)
? INSN_CONFIG_DIO_OUTPUT
: INSN_CONFIG_DIO_INPUT;
}
return 2;
case INSN_CONFIG_SET_CLOCK_SRC:
return ni_set_master_clock(dev, data[1], data[2]);
case INSN_CONFIG_GET_CLOCK_SRC:
data[1] = devpriv->clock_source;
data[2] = devpriv->clock_ns;
return 3;
case INSN_CONFIG_SET_ROUTING:
return ni_set_rtsi_routing(dev, chan, data[1]);
case INSN_CONFIG_GET_ROUTING:
data[1] = ni_get_rtsi_routing(dev, chan);
return 2;
default:
return -EINVAL;
}
return 1;
}
static int ni_rtsi_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = 0;
return insn->n;
}
static void ni_rtsi_init(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
devpriv->clock_and_fout2 = NI_M_CLK_FOUT2_RTSI_10MHZ;
if (ni_set_master_clock(dev, NI_MIO_INTERNAL_CLOCK, 0) < 0)
dev_err(dev->class_dev, "ni_set_master_clock failed, bug?\n");
devpriv->rtsi_trig_a_output_reg =
NISTC_RTSI_TRIG(0, NI_RTSI_OUTPUT_ADR_START1) |
NISTC_RTSI_TRIG(1, NI_RTSI_OUTPUT_ADR_START2) |
NISTC_RTSI_TRIG(2, NI_RTSI_OUTPUT_SCLKG) |
NISTC_RTSI_TRIG(3, NI_RTSI_OUTPUT_DACUPDN);
ni_stc_writew(dev, devpriv->rtsi_trig_a_output_reg,
NISTC_RTSI_TRIGA_OUT_REG);
devpriv->rtsi_trig_b_output_reg =
NISTC_RTSI_TRIG(4, NI_RTSI_OUTPUT_DA_START1) |
NISTC_RTSI_TRIG(5, NI_RTSI_OUTPUT_G_SRC0) |
NISTC_RTSI_TRIG(6, NI_RTSI_OUTPUT_G_GATE0);
if (devpriv->is_m_series)
devpriv->rtsi_trig_b_output_reg |=
NISTC_RTSI_TRIG(7, NI_RTSI_OUTPUT_RTSI_OSC);
ni_stc_writew(dev, devpriv->rtsi_trig_b_output_reg,
NISTC_RTSI_TRIGB_OUT_REG);
}
static int ni_gpct_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct ni_gpct *counter = s->private;
int retval;
retval = ni_request_gpct_mite_channel(dev, counter->counter_index,
COMEDI_INPUT);
if (retval) {
dev_err(dev->class_dev,
"no dma channel available for use by counter\n");
return retval;
}
ni_tio_acknowledge(counter);
ni_e_series_enable_second_irq(dev, counter->counter_index, 1);
return ni_tio_cmd(dev, s);
}
static int ni_gpct_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct ni_gpct *counter = s->private;
int retval;
retval = ni_tio_cancel(counter);
ni_e_series_enable_second_irq(dev, counter->counter_index, 0);
ni_release_gpct_mite_channel(dev, counter->counter_index);
return retval;
}
static irqreturn_t ni_E_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
unsigned short a_status;
unsigned short b_status;
unsigned int ai_mite_status = 0;
unsigned int ao_mite_status = 0;
unsigned long flags;
#ifdef PCIDMA
struct ni_private *devpriv = dev->private;
struct mite_struct *mite = devpriv->mite;
#endif
if (!dev->attached)
return IRQ_NONE;
smp_mb();
spin_lock_irqsave(&dev->spinlock, flags);
a_status = ni_stc_readw(dev, NISTC_AI_STATUS1_REG);
b_status = ni_stc_readw(dev, NISTC_AO_STATUS1_REG);
#ifdef PCIDMA
if (mite) {
struct ni_private *devpriv = dev->private;
unsigned long flags_too;
spin_lock_irqsave(&devpriv->mite_channel_lock, flags_too);
if (devpriv->ai_mite_chan) {
ai_mite_status = mite_get_status(devpriv->ai_mite_chan);
if (ai_mite_status & CHSR_LINKC)
writel(CHOR_CLRLC,
devpriv->mite->mite_io_addr +
MITE_CHOR(devpriv->
ai_mite_chan->channel));
}
if (devpriv->ao_mite_chan) {
ao_mite_status = mite_get_status(devpriv->ao_mite_chan);
if (ao_mite_status & CHSR_LINKC)
writel(CHOR_CLRLC,
mite->mite_io_addr +
MITE_CHOR(devpriv->
ao_mite_chan->channel));
}
spin_unlock_irqrestore(&devpriv->mite_channel_lock, flags_too);
}
#endif
ack_a_interrupt(dev, a_status);
ack_b_interrupt(dev, b_status);
if ((a_status & NISTC_AI_STATUS1_INTA) || (ai_mite_status & CHSR_INT))
handle_a_interrupt(dev, a_status, ai_mite_status);
if ((b_status & NISTC_AO_STATUS1_INTB) || (ao_mite_status & CHSR_INT))
handle_b_interrupt(dev, b_status, ao_mite_status);
handle_gpct_interrupt(dev, 0);
handle_gpct_interrupt(dev, 1);
handle_cdio_interrupt(dev);
spin_unlock_irqrestore(&dev->spinlock, flags);
return IRQ_HANDLED;
}
static int ni_alloc_private(struct comedi_device *dev)
{
struct ni_private *devpriv;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
spin_lock_init(&devpriv->window_lock);
spin_lock_init(&devpriv->soft_reg_copy_lock);
spin_lock_init(&devpriv->mite_channel_lock);
return 0;
}
static int ni_E_init(struct comedi_device *dev,
unsigned interrupt_pin, unsigned irq_polarity)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
struct comedi_subdevice *s;
int ret;
int i;
if (board->n_aochan > MAX_N_AO_CHAN) {
dev_err(dev->class_dev, "bug! n_aochan > MAX_N_AO_CHAN\n");
return -EINVAL;
}
devpriv->clock_and_fout = NISTC_CLK_FOUT_SLOW_DIV2 |
NISTC_CLK_FOUT_SLOW_TIMEBASE |
NISTC_CLK_FOUT_TO_BOARD_DIV2 |
NISTC_CLK_FOUT_TO_BOARD;
if (!devpriv->is_6xxx) {
devpriv->clock_and_fout |= (NISTC_CLK_FOUT_AI_OUT_DIV2 |
NISTC_CLK_FOUT_AO_OUT_DIV2);
}
ni_stc_writew(dev, devpriv->clock_and_fout, NISTC_CLK_FOUT_REG);
ret = comedi_alloc_subdevices(dev, NI_NUM_SUBDEVICES);
if (ret)
return ret;
s = &dev->subdevices[NI_AI_SUBDEV];
if (board->n_adchan) {
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF | SDF_DITHER;
if (!devpriv->is_611x)
s->subdev_flags |= SDF_GROUND | SDF_COMMON | SDF_OTHER;
if (board->ai_maxdata > 0xffff)
s->subdev_flags |= SDF_LSAMPL;
if (devpriv->is_m_series)
s->subdev_flags |= SDF_SOFT_CALIBRATED;
s->n_chan = board->n_adchan;
s->maxdata = board->ai_maxdata;
s->range_table = ni_range_lkup[board->gainlkup];
s->insn_read = ni_ai_insn_read;
s->insn_config = ni_ai_insn_config;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 512;
s->do_cmdtest = ni_ai_cmdtest;
s->do_cmd = ni_ai_cmd;
s->cancel = ni_ai_reset;
s->poll = ni_ai_poll;
s->munge = ni_ai_munge;
if (devpriv->mite)
s->async_dma_dir = DMA_FROM_DEVICE;
}
ni_ai_reset(dev, s);
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[NI_AO_SUBDEV];
if (board->n_aochan) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_DEGLITCH | SDF_GROUND;
if (devpriv->is_m_series)
s->subdev_flags |= SDF_SOFT_CALIBRATED;
s->n_chan = board->n_aochan;
s->maxdata = board->ao_maxdata;
s->range_table = board->ao_range_table;
s->insn_config = ni_ao_insn_config;
s->insn_write = ni_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
if (dev->irq && (board->ao_fifo_depth || devpriv->mite)) {
dev->write_subdev = s;
s->subdev_flags |= SDF_CMD_WRITE;
s->len_chanlist = s->n_chan;
s->do_cmdtest = ni_ao_cmdtest;
s->do_cmd = ni_ao_cmd;
s->cancel = ni_ao_reset;
if (!devpriv->is_m_series)
s->munge = ni_ao_munge;
if (devpriv->mite)
s->async_dma_dir = DMA_TO_DEVICE;
}
if (devpriv->is_67xx)
init_ao_67xx(dev, s);
ni_ao_reset(dev, s);
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[NI_DIO_SUBDEV];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = board->has_32dio_chan ? 32 : 8;
s->maxdata = 1;
s->range_table = &range_digital;
if (devpriv->is_m_series) {
s->subdev_flags |= SDF_LSAMPL;
s->insn_bits = ni_m_series_dio_insn_bits;
s->insn_config = ni_m_series_dio_insn_config;
if (dev->irq) {
s->subdev_flags |= SDF_CMD_WRITE ;
s->len_chanlist = s->n_chan;
s->do_cmdtest = ni_cdio_cmdtest;
s->do_cmd = ni_cdio_cmd;
s->cancel = ni_cdio_cancel;
s->async_dma_dir = DMA_BIDIRECTIONAL;
}
ni_writel(dev, NI_M_CDO_CMD_RESET |
NI_M_CDI_CMD_RESET,
NI_M_CDIO_CMD_REG);
ni_writel(dev, s->io_bits, NI_M_DIO_DIR_REG);
} else {
s->insn_bits = ni_dio_insn_bits;
s->insn_config = ni_dio_insn_config;
devpriv->dio_control = NISTC_DIO_CTRL_DIR(s->io_bits);
ni_writew(dev, devpriv->dio_control, NISTC_DIO_CTRL_REG);
}
s = &dev->subdevices[NI_8255_DIO_SUBDEV];
if (board->has_8255) {
ret = subdev_8255_init(dev, s, ni_8255_callback,
NI_E_8255_BASE);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[NI_UNUSED_SUBDEV];
s->type = COMEDI_SUBD_UNUSED;
s = &dev->subdevices[NI_CALIBRATION_SUBDEV];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_INTERNAL;
s->n_chan = 1;
s->maxdata = 0;
if (devpriv->is_m_series) {
s->insn_config = ni_m_series_pwm_config;
ni_writel(dev, 0x0, NI_M_CAL_PWM_REG);
} else if (devpriv->is_6143) {
s->insn_config = ni_6143_pwm_config;
} else {
s->subdev_flags |= SDF_WRITABLE;
s->insn_read = ni_calib_insn_read;
s->insn_write = ni_calib_insn_write;
caldac_setup(dev, s);
}
s = &dev->subdevices[NI_EEPROM_SUBDEV];
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE | SDF_INTERNAL;
s->maxdata = 0xff;
if (devpriv->is_m_series) {
s->n_chan = M_SERIES_EEPROM_SIZE;
s->insn_read = ni_m_series_eeprom_insn_read;
} else {
s->n_chan = 512;
s->insn_read = ni_eeprom_insn_read;
}
s = &dev->subdevices[NI_PFI_DIO_SUBDEV];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->maxdata = 1;
if (devpriv->is_m_series) {
s->n_chan = 16;
s->insn_bits = ni_pfi_insn_bits;
ni_writew(dev, s->state, NI_M_PFI_DO_REG);
for (i = 0; i < NUM_PFI_OUTPUT_SELECT_REGS; ++i) {
ni_writew(dev, devpriv->pfi_output_select_reg[i],
NI_M_PFI_OUT_SEL_REG(i));
}
} else {
s->n_chan = 10;
}
s->insn_config = ni_pfi_insn_config;
ni_set_bits(dev, NISTC_IO_BIDIR_PIN_REG, ~0, 0);
s = &dev->subdevices[NI_CS5529_CALIBRATION_SUBDEV];
if (devpriv->is_67xx) {
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF | SDF_INTERNAL;
s->n_chan = board->n_aochan;
s->maxdata = (1 << 16) - 1;
s->range_table = &range_unknown;
s->insn_read = cs5529_ai_insn_read;
s->insn_config = NULL;
init_cs5529(dev);
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[NI_SERIAL_SUBDEV];
s->type = COMEDI_SUBD_SERIAL;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 1;
s->maxdata = 0xff;
s->insn_config = ni_serial_insn_config;
devpriv->serial_interval_ns = 0;
devpriv->serial_hw_mode = 0;
s = &dev->subdevices[NI_RTSI_SUBDEV];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 8;
s->maxdata = 1;
s->insn_bits = ni_rtsi_insn_bits;
s->insn_config = ni_rtsi_insn_config;
ni_rtsi_init(dev);
devpriv->counter_dev = ni_gpct_device_construct(dev,
ni_gpct_write_register,
ni_gpct_read_register,
(devpriv->is_m_series)
? ni_gpct_variant_m_series
: ni_gpct_variant_e_series,
NUM_GPCT);
if (!devpriv->counter_dev)
return -ENOMEM;
for (i = 0; i < NUM_GPCT; ++i) {
struct ni_gpct *gpct = &devpriv->counter_dev->counters[i];
gpct->chip_index = 0;
gpct->counter_index = i;
ni_tio_init_counter(gpct);
s = &dev->subdevices[NI_GPCT_SUBDEV(i)];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_LSAMPL;
s->n_chan = 3;
s->maxdata = (devpriv->is_m_series) ? 0xffffffff
: 0x00ffffff;
s->insn_read = ni_tio_insn_read;
s->insn_write = ni_tio_insn_read;
s->insn_config = ni_tio_insn_config;
#ifdef PCIDMA
if (dev->irq && devpriv->mite) {
s->subdev_flags |= SDF_CMD_READ ;
s->len_chanlist = 1;
s->do_cmdtest = ni_tio_cmdtest;
s->do_cmd = ni_gpct_cmd;
s->cancel = ni_gpct_cancel;
s->async_dma_dir = DMA_BIDIRECTIONAL;
}
#endif
s->private = gpct;
}
s = &dev->subdevices[NI_FREQ_OUT_SUBDEV];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 1;
s->maxdata = 0xf;
s->insn_read = ni_freq_out_insn_read;
s->insn_write = ni_freq_out_insn_write;
s->insn_config = ni_freq_out_insn_config;
if (dev->irq) {
ni_stc_writew(dev,
(irq_polarity ? NISTC_INT_CTRL_INT_POL : 0) |
(NISTC_INT_CTRL_3PIN_INT & 0) |
NISTC_INT_CTRL_INTA_ENA |
NISTC_INT_CTRL_INTB_ENA |
NISTC_INT_CTRL_INTA_SEL(interrupt_pin) |
NISTC_INT_CTRL_INTB_SEL(interrupt_pin),
NISTC_INT_CTRL_REG);
}
ni_writeb(dev, devpriv->ai_ao_select_reg, NI_E_DMA_AI_AO_SEL_REG);
ni_writeb(dev, devpriv->g0_g1_select_reg, NI_E_DMA_G0_G1_SEL_REG);
if (devpriv->is_6xxx) {
ni_writeb(dev, 0, NI611X_MAGIC_REG);
} else if (devpriv->is_m_series) {
int channel;
for (channel = 0; channel < board->n_aochan; ++channel) {
ni_writeb(dev, 0xf,
NI_M_AO_WAVEFORM_ORDER_REG(channel));
ni_writeb(dev, 0x0,
NI_M_AO_REF_ATTENUATION_REG(channel));
}
ni_writeb(dev, 0x0, NI_M_AO_CALIB_REG);
}
return 0;
}
static void mio_common_detach(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
if (devpriv) {
if (devpriv->counter_dev)
ni_gpct_device_destroy(devpriv->counter_dev);
}
}
