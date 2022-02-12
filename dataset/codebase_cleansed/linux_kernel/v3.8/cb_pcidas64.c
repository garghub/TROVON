static inline unsigned int dac_convert_reg(unsigned int channel)
{
return 0x70 + (2 * (channel & 0x1));
}
static inline unsigned int dac_lsb_4020_reg(unsigned int channel)
{
return 0x70 + (4 * (channel & 0x1));
}
static inline unsigned int dac_msb_4020_reg(unsigned int channel)
{
return 0x72 + (4 * (channel & 0x1));
}
static inline uint16_t analog_trig_low_threshold_bits(uint16_t threshold)
{
return threshold & 0xfff;
}
static inline uint16_t adc_lo_chan_4020_bits(unsigned int channel)
{
return (channel & 0x3) << 8;
}
static inline uint16_t adc_hi_chan_4020_bits(unsigned int channel)
{
return (channel & 0x3) << 10;
}
static inline uint16_t adc_mode_bits(unsigned int mode)
{
return (mode & 0xf) << 12;
}
static inline uint16_t adc_src_bits(unsigned int source)
{
return (source & 0xf) << 3;
}
static inline uint16_t adc_convert_chan_4020_bits(unsigned int channel)
{
return (channel & 0x3) << 8;
}
static inline uint16_t adc_chan_bits(unsigned int channel)
{
return channel & 0x3f;
}
static inline uint16_t pipe_full_bits(uint16_t hw_status_bits)
{
return (hw_status_bits >> 10) & 0x3;
}
static inline unsigned int dma_chain_flag_bits(uint16_t prepost_bits)
{
return (prepost_bits >> 6) & 0x3;
}
static inline unsigned int adc_upper_read_ptr_code(uint16_t prepost_bits)
{
return (prepost_bits >> 12) & 0x3;
}
static inline unsigned int adc_upper_write_ptr_code(uint16_t prepost_bits)
{
return (prepost_bits >> 14) & 0x3;
}
static inline uint8_t adc_src_4020_bits(unsigned int source)
{
return (source << 4) & ADC_SRC_4020_MASK;
}
static inline uint8_t attenuate_bit(unsigned int channel)
{
return 1 << (channel & 0x3);
}
static inline unsigned int ai_dma_ring_count(const struct pcidas64_board *board)
{
if (board->layout == LAYOUT_4020)
return MAX_AI_DMA_RING_COUNT;
else
return MIN_AI_DMA_RING_COUNT;
}
static inline unsigned short se_diff_bit_6xxx(struct comedi_device *dev,
int use_differential)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
if ((thisboard->layout == LAYOUT_64XX && !use_differential) ||
(thisboard->layout == LAYOUT_60XX && use_differential))
return ADC_SE_DIFF_BIT;
else
return 0;
}
static unsigned int ai_range_bits_6xxx(const struct comedi_device *dev,
unsigned int range_index)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
const struct comedi_krange *range =
&thisboard->ai_range_table->range[range_index];
unsigned int bits = 0;
switch (range->max) {
case 10000000:
bits = 0x000;
break;
case 5000000:
bits = 0x100;
break;
case 2000000:
case 2500000:
bits = 0x200;
break;
case 1000000:
case 1250000:
bits = 0x300;
break;
case 500000:
bits = 0x400;
break;
case 200000:
case 250000:
bits = 0x500;
break;
case 100000:
bits = 0x600;
break;
case 50000:
bits = 0x700;
break;
default:
comedi_error(dev, "bug! in ai_range_bits_6xxx");
break;
}
if (range->min == 0)
bits += 0x900;
return bits;
}
static unsigned int hw_revision(const struct comedi_device *dev,
uint16_t hw_status_bits)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
if (thisboard->layout == LAYOUT_4020)
return (hw_status_bits >> 13) & 0x7;
return (hw_status_bits >> 12) & 0xf;
}
static void set_dac_range_bits(struct comedi_device *dev,
volatile uint16_t *bits, unsigned int channel,
unsigned int range)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
unsigned int code = thisboard->ao_range_code[range];
if (channel > 1)
comedi_error(dev, "bug! bad channel?");
if (code & ~0x3)
comedi_error(dev, "bug! bad range code?");
*bits &= ~(0x3 << (2 * channel));
*bits |= code << (2 * channel);
}
static inline int ao_cmd_is_supported(const struct pcidas64_board *board)
{
return board->ao_nchan && board->layout != LAYOUT_4020;
}
static void abort_dma(struct comedi_device *dev, unsigned int channel)
{
struct pcidas64_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
plx9080_abort_dma(devpriv->plx9080_iobase, channel);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
static void disable_plx_interrupts(struct comedi_device *dev)
{
struct pcidas64_private *devpriv = dev->private;
devpriv->plx_intcsr_bits = 0;
writel(devpriv->plx_intcsr_bits,
devpriv->plx9080_iobase + PLX_INTRCS_REG);
}
static void disable_ai_interrupts(struct comedi_device *dev)
{
struct pcidas64_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->intr_enable_bits &=
~EN_ADC_INTR_SRC_BIT & ~EN_ADC_DONE_INTR_BIT &
~EN_ADC_ACTIVE_INTR_BIT & ~EN_ADC_STOP_INTR_BIT &
~EN_ADC_OVERRUN_BIT & ~ADC_INTR_SRC_MASK;
writew(devpriv->intr_enable_bits,
devpriv->main_iobase + INTR_ENABLE_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
DEBUG_PRINT("intr enable bits 0x%x\n", devpriv->intr_enable_bits);
}
static void enable_ai_interrupts(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
uint32_t bits;
unsigned long flags;
bits = EN_ADC_OVERRUN_BIT | EN_ADC_DONE_INTR_BIT |
EN_ADC_ACTIVE_INTR_BIT | EN_ADC_STOP_INTR_BIT;
if (cmd->flags & TRIG_WAKE_EOS) {
if (thisboard->layout != LAYOUT_4020)
bits |= ADC_INTR_EOSCAN_BITS | EN_ADC_INTR_SRC_BIT;
}
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->intr_enable_bits |= bits;
writew(devpriv->intr_enable_bits,
devpriv->main_iobase + INTR_ENABLE_REG);
DEBUG_PRINT("intr enable bits 0x%x\n", devpriv->intr_enable_bits);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
static void init_plx9080(struct comedi_device *dev)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
uint32_t bits;
void __iomem *plx_iobase = devpriv->plx9080_iobase;
devpriv->plx_control_bits =
readl(devpriv->plx9080_iobase + PLX_CONTROL_REG);
DEBUG_PRINT(" plx interrupt status 0x%x\n",
readl(plx_iobase + PLX_INTRCS_REG));
DEBUG_PRINT(" plx id bits 0x%x\n", readl(plx_iobase + PLX_ID_REG));
DEBUG_PRINT(" plx control reg 0x%x\n", devpriv->plx_control_bits);
DEBUG_PRINT(" plx mode/arbitration reg 0x%x\n",
readl(plx_iobase + PLX_MARB_REG));
DEBUG_PRINT(" plx region0 reg 0x%x\n",
readl(plx_iobase + PLX_REGION0_REG));
DEBUG_PRINT(" plx region1 reg 0x%x\n",
readl(plx_iobase + PLX_REGION1_REG));
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
bits |= PLX_EN_BTERM_BIT;
bits |= PLX_EN_CHAIN_BIT;
bits |= PLX_EN_DMA_DONE_INTR_BIT;
bits |= PLX_LOCAL_ADDR_CONST_BIT;
bits |= PLX_DMA_INTR_PCI_BIT;
bits |= PLX_DEMAND_MODE_BIT;
bits |= PLX_DMA_LOCAL_BURST_EN_BIT;
if (thisboard->layout == LAYOUT_4020)
bits |= PLX_LOCAL_BUS_32_WIDE_BITS;
else
bits |= PLX_LOCAL_BUS_16_WIDE_BITS;
writel(bits, plx_iobase + PLX_DMA1_MODE_REG);
if (ao_cmd_is_supported(thisboard))
writel(bits, plx_iobase + PLX_DMA0_MODE_REG);
devpriv->plx_intcsr_bits |=
ICS_AERR | ICS_PERR | ICS_PIE | ICS_PLIE | ICS_PAIE | ICS_LIE |
ICS_DMA0_E | ICS_DMA1_E;
writel(devpriv->plx_intcsr_bits,
devpriv->plx9080_iobase + PLX_INTRCS_REG);
}
static void disable_ai_pacing(struct comedi_device *dev)
{
struct pcidas64_private *devpriv = dev->private;
unsigned long flags;
disable_ai_interrupts(dev);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->adc_control1_bits &= ~ADC_SW_GATE_BIT;
writew(devpriv->adc_control1_bits,
devpriv->main_iobase + ADC_CONTROL1_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
writew(ADC_DMA_DISABLE_BIT | ADC_SOFT_GATE_BITS | ADC_GATE_LEVEL_BIT,
devpriv->main_iobase + ADC_CONTROL0_REG);
}
static int set_ai_fifo_segment_length(struct comedi_device *dev,
unsigned int num_entries)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
static const int increment_size = 0x100;
const struct hw_fifo_info *const fifo = thisboard->ai_fifo;
unsigned int num_increments;
uint16_t bits;
if (num_entries < increment_size)
num_entries = increment_size;
if (num_entries > fifo->max_segment_length)
num_entries = fifo->max_segment_length;
num_increments = (num_entries + increment_size / 2) / increment_size;
bits = (~(num_increments - 1)) & fifo->fifo_size_reg_mask;
devpriv->fifo_size_bits &= ~fifo->fifo_size_reg_mask;
devpriv->fifo_size_bits |= bits;
writew(devpriv->fifo_size_bits,
devpriv->main_iobase + FIFO_SIZE_REG);
devpriv->ai_fifo_segment_length = num_increments * increment_size;
DEBUG_PRINT("set hardware fifo segment length to %i\n",
devpriv->ai_fifo_segment_length);
return devpriv->ai_fifo_segment_length;
}
static int set_ai_fifo_size(struct comedi_device *dev, unsigned int num_samples)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
unsigned int num_fifo_entries;
int retval;
const struct hw_fifo_info *const fifo = thisboard->ai_fifo;
num_fifo_entries = num_samples / fifo->sample_packing_ratio;
retval = set_ai_fifo_segment_length(dev,
num_fifo_entries /
fifo->num_segments);
if (retval < 0)
return retval;
num_samples = retval * fifo->num_segments * fifo->sample_packing_ratio;
DEBUG_PRINT("set hardware fifo size to %i\n", num_samples);
return num_samples;
}
static unsigned int ai_fifo_size(struct comedi_device *dev)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
return devpriv->ai_fifo_segment_length *
thisboard->ai_fifo->num_segments *
thisboard->ai_fifo->sample_packing_ratio;
}
static void init_stc_registers(struct comedi_device *dev)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
uint16_t bits;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
if (1)
devpriv->adc_control1_bits |= ADC_QUEUE_CONFIG_BIT;
writew(devpriv->adc_control1_bits,
devpriv->main_iobase + ADC_CONTROL1_REG);
writew(0xff, devpriv->main_iobase + ADC_SAMPLE_INTERVAL_UPPER_REG);
bits = SLOW_DAC_BIT | DMA_CH_SELECT_BIT;
if (thisboard->layout == LAYOUT_4020)
bits |= INTERNAL_CLOCK_4020_BITS;
devpriv->hw_config_bits |= bits;
writew(devpriv->hw_config_bits,
devpriv->main_iobase + HW_CONFIG_REG);
writew(0, devpriv->main_iobase + DAQ_SYNC_REG);
writew(0, devpriv->main_iobase + CALIBRATION_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
devpriv->fifo_size_bits |= DAC_FIFO_BITS;
set_ai_fifo_segment_length(dev,
thisboard->ai_fifo->max_segment_length);
devpriv->dac_control1_bits = DAC_OUTPUT_ENABLE_BIT;
devpriv->intr_enable_bits =
EN_DAC_DONE_INTR_BIT | EN_DAC_UNDERRUN_BIT;
writew(devpriv->intr_enable_bits,
devpriv->main_iobase + INTR_ENABLE_REG);
disable_ai_pacing(dev);
}
static int alloc_and_init_dma_members(struct comedi_device *dev)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct pcidas64_private *devpriv = dev->private;
int i;
for (i = 0; i < ai_dma_ring_count(thisboard); i++) {
devpriv->ai_buffer[i] =
pci_alloc_consistent(pcidev, DMA_BUFFER_SIZE,
&devpriv->ai_buffer_bus_addr[i]);
if (devpriv->ai_buffer[i] == NULL)
return -ENOMEM;
}
for (i = 0; i < AO_DMA_RING_COUNT; i++) {
if (ao_cmd_is_supported(thisboard)) {
devpriv->ao_buffer[i] =
pci_alloc_consistent(pcidev, DMA_BUFFER_SIZE,
&devpriv->
ao_buffer_bus_addr[i]);
if (devpriv->ao_buffer[i] == NULL)
return -ENOMEM;
}
}
devpriv->ai_dma_desc =
pci_alloc_consistent(pcidev, sizeof(struct plx_dma_desc) *
ai_dma_ring_count(thisboard),
&devpriv->ai_dma_desc_bus_addr);
if (devpriv->ai_dma_desc == NULL)
return -ENOMEM;
DEBUG_PRINT("ai dma descriptors start at bus addr 0x%llx\n",
(unsigned long long)devpriv->ai_dma_desc_bus_addr);
if (ao_cmd_is_supported(thisboard)) {
devpriv->ao_dma_desc =
pci_alloc_consistent(pcidev,
sizeof(struct plx_dma_desc) *
AO_DMA_RING_COUNT,
&devpriv->ao_dma_desc_bus_addr);
if (devpriv->ao_dma_desc == NULL)
return -ENOMEM;
DEBUG_PRINT("ao dma descriptors start at bus addr 0x%llx\n",
(unsigned long long)devpriv->ao_dma_desc_bus_addr);
}
for (i = 0; i < ai_dma_ring_count(thisboard); i++) {
devpriv->ai_dma_desc[i].pci_start_addr =
cpu_to_le32(devpriv->ai_buffer_bus_addr[i]);
if (thisboard->layout == LAYOUT_4020)
devpriv->ai_dma_desc[i].local_start_addr =
cpu_to_le32(devpriv->local1_iobase +
ADC_FIFO_REG);
else
devpriv->ai_dma_desc[i].local_start_addr =
cpu_to_le32(devpriv->local0_iobase +
ADC_FIFO_REG);
devpriv->ai_dma_desc[i].transfer_size = cpu_to_le32(0);
devpriv->ai_dma_desc[i].next =
cpu_to_le32((devpriv->ai_dma_desc_bus_addr +
((i + 1) % ai_dma_ring_count(thisboard)) *
sizeof(devpriv->ai_dma_desc[0])) |
PLX_DESC_IN_PCI_BIT | PLX_INTR_TERM_COUNT |
PLX_XFER_LOCAL_TO_PCI);
}
if (ao_cmd_is_supported(thisboard)) {
for (i = 0; i < AO_DMA_RING_COUNT; i++) {
devpriv->ao_dma_desc[i].pci_start_addr =
cpu_to_le32(devpriv->ao_buffer_bus_addr[i]);
devpriv->ao_dma_desc[i].local_start_addr =
cpu_to_le32(devpriv->local0_iobase +
DAC_FIFO_REG);
devpriv->ao_dma_desc[i].transfer_size = cpu_to_le32(0);
devpriv->ao_dma_desc[i].next =
cpu_to_le32((devpriv->ao_dma_desc_bus_addr +
((i + 1) % (AO_DMA_RING_COUNT)) *
sizeof(devpriv->ao_dma_desc[0])) |
PLX_DESC_IN_PCI_BIT |
PLX_INTR_TERM_COUNT);
}
}
return 0;
}
static inline void warn_external_queue(struct comedi_device *dev)
{
comedi_error(dev,
"AO command and AI external channel queue cannot be used simultaneously.");
comedi_error(dev,
"Use internal AI channel queue (channels must be consecutive and use same range/aref)");
}
static void i2c_set_sda(struct comedi_device *dev, int state)
{
struct pcidas64_private *devpriv = dev->private;
static const int data_bit = CTL_EE_W;
void __iomem *plx_control_addr = devpriv->plx9080_iobase +
PLX_CONTROL_REG;
if (state) {
devpriv->plx_control_bits &= ~data_bit;
writel(devpriv->plx_control_bits, plx_control_addr);
udelay(i2c_high_udelay);
} else {
devpriv->plx_control_bits |= data_bit;
writel(devpriv->plx_control_bits, plx_control_addr);
udelay(i2c_low_udelay);
}
}
static void i2c_set_scl(struct comedi_device *dev, int state)
{
struct pcidas64_private *devpriv = dev->private;
static const int clock_bit = CTL_USERO;
void __iomem *plx_control_addr = devpriv->plx9080_iobase +
PLX_CONTROL_REG;
if (state) {
devpriv->plx_control_bits &= ~clock_bit;
writel(devpriv->plx_control_bits, plx_control_addr);
udelay(i2c_high_udelay);
} else {
devpriv->plx_control_bits |= clock_bit;
writel(devpriv->plx_control_bits, plx_control_addr);
udelay(i2c_low_udelay);
}
}
static void i2c_write_byte(struct comedi_device *dev, uint8_t byte)
{
uint8_t bit;
unsigned int num_bits = 8;
DEBUG_PRINT("writing to i2c byte 0x%x\n", byte);
for (bit = 1 << (num_bits - 1); bit; bit >>= 1) {
i2c_set_scl(dev, 0);
if ((byte & bit))
i2c_set_sda(dev, 1);
else
i2c_set_sda(dev, 0);
i2c_set_scl(dev, 1);
}
}
static int i2c_read_ack(struct comedi_device *dev)
{
i2c_set_scl(dev, 0);
i2c_set_sda(dev, 1);
i2c_set_scl(dev, 1);
return 0;
}
static void i2c_start(struct comedi_device *dev)
{
i2c_set_scl(dev, 1);
i2c_set_sda(dev, 1);
i2c_set_sda(dev, 0);
}
static void i2c_stop(struct comedi_device *dev)
{
i2c_set_scl(dev, 0);
i2c_set_sda(dev, 0);
i2c_set_scl(dev, 1);
i2c_set_sda(dev, 1);
}
static void i2c_write(struct comedi_device *dev, unsigned int address,
const uint8_t *data, unsigned int length)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int i;
uint8_t bitstream;
static const int read_bit = 0x1;
devpriv->plx_control_bits &= ~CTL_EE_CS;
i2c_stop(dev);
i2c_start(dev);
bitstream = (address << 1) & ~read_bit;
i2c_write_byte(dev, bitstream);
if (i2c_read_ack(dev) != 0) {
comedi_error(dev, "i2c write failed: no acknowledge");
i2c_stop(dev);
return;
}
for (i = 0; i < length; i++) {
i2c_write_byte(dev, data[i]);
if (i2c_read_ack(dev) != 0) {
comedi_error(dev, "i2c write failed: no acknowledge");
i2c_stop(dev);
return;
}
}
i2c_stop(dev);
}
static int ai_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
unsigned int bits = 0, n, i;
unsigned int channel, range, aref;
unsigned long flags;
static const int timeout = 100;
DEBUG_PRINT("chanspec 0x%x\n", insn->chanspec);
channel = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec);
aref = CR_AREF(insn->chanspec);
disable_ai_pacing(dev);
spin_lock_irqsave(&dev->spinlock, flags);
if (insn->chanspec & CR_ALT_FILTER)
devpriv->adc_control1_bits |= ADC_DITHER_BIT;
else
devpriv->adc_control1_bits &= ~ADC_DITHER_BIT;
writew(devpriv->adc_control1_bits,
devpriv->main_iobase + ADC_CONTROL1_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
if (thisboard->layout != LAYOUT_4020) {
devpriv->hw_config_bits &= ~EXT_QUEUE_BIT;
writew(devpriv->hw_config_bits,
devpriv->main_iobase + HW_CONFIG_REG);
if (insn->chanspec & CR_ALT_SOURCE) {
unsigned int cal_en_bit;
DEBUG_PRINT("reading calibration source\n");
if (thisboard->layout == LAYOUT_60XX)
cal_en_bit = CAL_EN_60XX_BIT;
else
cal_en_bit = CAL_EN_64XX_BIT;
writew(cal_en_bit |
adc_src_bits(devpriv->calibration_source),
devpriv->main_iobase + CALIBRATION_REG);
} else {
writew(0, devpriv->main_iobase + CALIBRATION_REG);
}
bits = 0;
bits |= ai_range_bits_6xxx(dev, CR_RANGE(insn->chanspec));
bits |= se_diff_bit_6xxx(dev, aref == AREF_DIFF);
if (aref == AREF_COMMON)
bits |= ADC_COMMON_BIT;
bits |= adc_chan_bits(channel);
writew(adc_chan_bits(channel),
devpriv->main_iobase + ADC_QUEUE_HIGH_REG);
writew(bits, devpriv->main_iobase + ADC_QUEUE_LOAD_REG);
} else {
uint8_t old_cal_range_bits = devpriv->i2c_cal_range_bits;
devpriv->i2c_cal_range_bits &= ~ADC_SRC_4020_MASK;
if (insn->chanspec & CR_ALT_SOURCE) {
DEBUG_PRINT("reading calibration source\n");
devpriv->i2c_cal_range_bits |=
adc_src_4020_bits(devpriv->calibration_source);
} else {
devpriv->i2c_cal_range_bits |= adc_src_4020_bits(4);
}
if (range == 0)
devpriv->i2c_cal_range_bits |= attenuate_bit(channel);
else
devpriv->i2c_cal_range_bits &= ~attenuate_bit(channel);
if (old_cal_range_bits != devpriv->i2c_cal_range_bits) {
uint8_t i2c_data = devpriv->i2c_cal_range_bits;
i2c_write(dev, RANGE_CAL_I2C_ADDR, &i2c_data,
sizeof(i2c_data));
}
writew(0, devpriv->main_iobase + ADC_SAMPLE_INTERVAL_UPPER_REG);
writew(2, devpriv->main_iobase + ADC_SAMPLE_INTERVAL_LOWER_REG);
}
for (n = 0; n < insn->n; n++) {
writew(0, devpriv->main_iobase + ADC_BUFFER_CLEAR_REG);
writew(adc_convert_chan_4020_bits(CR_CHAN(insn->chanspec)),
devpriv->main_iobase + ADC_CONVERT_REG);
for (i = 0; i < timeout; i++) {
bits = readw(devpriv->main_iobase + HW_STATUS_REG);
DEBUG_PRINT(" pipe bits 0x%x\n", pipe_full_bits(bits));
if (thisboard->layout == LAYOUT_4020) {
if (readw(devpriv->main_iobase +
ADC_WRITE_PNTR_REG))
break;
} else {
if (pipe_full_bits(bits))
break;
}
udelay(1);
}
DEBUG_PRINT(" looped %i times waiting for data\n", i);
if (i == timeout) {
comedi_error(dev, " analog input read insn timed out");
dev_info(dev->class_dev, "status 0x%x\n", bits);
return -ETIME;
}
if (thisboard->layout == LAYOUT_4020)
data[n] = readl(devpriv->dio_counter_iobase +
ADC_FIFO_REG) & 0xffff;
else
data[n] = readw(devpriv->main_iobase + PIPE1_READ_REG);
}
return n;
}
static int ai_config_calibration_source(struct comedi_device *dev,
unsigned int *data)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
unsigned int source = data[1];
int num_calibration_sources;
if (thisboard->layout == LAYOUT_60XX)
num_calibration_sources = 16;
else
num_calibration_sources = 8;
if (source >= num_calibration_sources) {
dev_dbg(dev->class_dev, "invalid calibration source: %i\n",
source);
return -EINVAL;
}
DEBUG_PRINT("setting calibration source to %i\n", source);
devpriv->calibration_source = source;
return 2;
}
static int ai_config_block_size(struct comedi_device *dev, unsigned int *data)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
int fifo_size;
const struct hw_fifo_info *const fifo = thisboard->ai_fifo;
unsigned int block_size, requested_block_size;
int retval;
requested_block_size = data[1];
if (requested_block_size) {
fifo_size = requested_block_size * fifo->num_segments /
bytes_in_sample;
retval = set_ai_fifo_size(dev, fifo_size);
if (retval < 0)
return retval;
}
block_size = ai_fifo_size(dev) / fifo->num_segments * bytes_in_sample;
data[1] = block_size;
return 2;
}
static int ai_config_master_clock_4020(struct comedi_device *dev,
unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int divisor = data[4];
int retval = 0;
if (divisor < 2) {
divisor = 2;
retval = -EAGAIN;
}
switch (data[1]) {
case COMEDI_EV_SCAN_BEGIN:
devpriv->ext_clock.divisor = divisor;
devpriv->ext_clock.chanspec = data[2];
break;
default:
return -EINVAL;
break;
}
data[4] = divisor;
return retval ? retval : 5;
}
static int ai_config_master_clock(struct comedi_device *dev, unsigned int *data)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
switch (thisboard->layout) {
case LAYOUT_4020:
return ai_config_master_clock_4020(dev, data);
break;
default:
return -EINVAL;
break;
}
return -EINVAL;
}
static int ai_config_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int id = data[0];
switch (id) {
case INSN_CONFIG_ALT_SOURCE:
return ai_config_calibration_source(dev, data);
break;
case INSN_CONFIG_BLOCK_SIZE:
return ai_config_block_size(dev, data);
break;
case INSN_CONFIG_TIMER_1:
return ai_config_master_clock(dev, data);
break;
default:
return -EINVAL;
break;
}
return -EINVAL;
}
static unsigned int get_divisor(unsigned int ns, unsigned int flags)
{
unsigned int divisor;
switch (flags & TRIG_ROUND_MASK) {
case TRIG_ROUND_UP:
divisor = (ns + TIMER_BASE - 1) / TIMER_BASE;
break;
case TRIG_ROUND_DOWN:
divisor = ns / TIMER_BASE;
break;
case TRIG_ROUND_NEAREST:
default:
divisor = (ns + TIMER_BASE / 2) / TIMER_BASE;
break;
}
return divisor;
}
static void check_adc_timing(struct comedi_device *dev, struct comedi_cmd *cmd)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
unsigned int convert_divisor = 0, scan_divisor;
static const int min_convert_divisor = 3;
static const int max_convert_divisor =
max_counter_value + min_convert_divisor;
static const int min_scan_divisor_4020 = 2;
unsigned long long max_scan_divisor, min_scan_divisor;
if (cmd->convert_src == TRIG_TIMER) {
if (thisboard->layout == LAYOUT_4020) {
cmd->convert_arg = 0;
} else {
convert_divisor = get_divisor(cmd->convert_arg,
cmd->flags);
if (convert_divisor > max_convert_divisor)
convert_divisor = max_convert_divisor;
if (convert_divisor < min_convert_divisor)
convert_divisor = min_convert_divisor;
cmd->convert_arg = convert_divisor * TIMER_BASE;
}
} else if (cmd->convert_src == TRIG_NOW) {
cmd->convert_arg = 0;
}
if (cmd->scan_begin_src == TRIG_TIMER) {
scan_divisor = get_divisor(cmd->scan_begin_arg, cmd->flags);
if (cmd->convert_src == TRIG_TIMER) {
min_scan_divisor = convert_divisor * cmd->chanlist_len;
max_scan_divisor =
(convert_divisor * cmd->chanlist_len - 1) +
max_counter_value;
} else {
min_scan_divisor = min_scan_divisor_4020;
max_scan_divisor = max_counter_value + min_scan_divisor;
}
if (scan_divisor > max_scan_divisor)
scan_divisor = max_scan_divisor;
if (scan_divisor < min_scan_divisor)
scan_divisor = min_scan_divisor;
cmd->scan_begin_arg = scan_divisor * TIMER_BASE;
}
return;
}
static int ai_cmdtest(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
int err = 0;
unsigned int tmp_arg, tmp_arg2;
int i;
int aref;
unsigned int triggers;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
triggers = TRIG_TIMER;
if (thisboard->layout == LAYOUT_4020)
triggers |= TRIG_OTHER;
else
triggers |= TRIG_FOLLOW;
err |= cfc_check_trigger_src(&cmd->scan_begin_src, triggers);
triggers = TRIG_TIMER;
if (thisboard->layout == LAYOUT_4020)
triggers |= TRIG_NOW;
else
triggers |= TRIG_EXT;
err |= cfc_check_trigger_src(&cmd->convert_src, triggers);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src,
TRIG_COUNT | TRIG_EXT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (cmd->convert_src == TRIG_EXT && cmd->scan_begin_src == TRIG_TIMER)
err |= -EINVAL;
if (cmd->stop_src != TRIG_COUNT &&
cmd->stop_src != TRIG_NONE && cmd->stop_src != TRIG_EXT)
err |= -EINVAL;
if (err)
return 2;
if (cmd->convert_src == TRIG_TIMER) {
if (thisboard->layout == LAYOUT_4020) {
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
} else {
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
thisboard->ai_speed);
if (cmd->scan_begin_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(
&cmd->scan_begin_arg,
cmd->convert_arg *
cmd->chanlist_len);
}
}
err |= cfc_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
switch (cmd->stop_src) {
case TRIG_EXT:
break;
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
if (cmd->convert_src == TRIG_TIMER) {
tmp_arg = cmd->convert_arg;
tmp_arg2 = cmd->scan_begin_arg;
check_adc_timing(dev, cmd);
if (tmp_arg != cmd->convert_arg)
err++;
if (tmp_arg2 != cmd->scan_begin_arg)
err++;
}
if (err)
return 4;
if (cmd->chanlist) {
aref = CR_AREF(cmd->chanlist[0]);
for (i = 1; i < cmd->chanlist_len; i++) {
if (aref != CR_AREF(cmd->chanlist[i])) {
comedi_error(dev,
"all elements in chanlist must use the same analog reference");
err++;
break;
}
}
if (thisboard->layout == LAYOUT_4020) {
unsigned int first_channel = CR_CHAN(cmd->chanlist[0]);
for (i = 1; i < cmd->chanlist_len; i++) {
if (CR_CHAN(cmd->chanlist[i]) !=
first_channel + i) {
comedi_error(dev,
"chanlist must use consecutive channels");
err++;
break;
}
}
if (cmd->chanlist_len == 3) {
comedi_error(dev,
"chanlist cannot be 3 channels long, use 1, 2, or 4 channels");
err++;
}
}
}
if (err)
return 5;
return 0;
}
static int use_hw_sample_counter(struct comedi_cmd *cmd)
{
return 0;
if (cmd->stop_src == TRIG_COUNT && cmd->stop_arg <= max_counter_value)
return 1;
else
return 0;
}
static void setup_sample_counters(struct comedi_device *dev,
struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
if (cmd->stop_src == TRIG_COUNT) {
devpriv->ai_count = cmd->stop_arg * cmd->chanlist_len;
}
if (use_hw_sample_counter(cmd)) {
writew(cmd->stop_arg & 0xffff,
devpriv->main_iobase + ADC_COUNT_LOWER_REG);
writew((cmd->stop_arg >> 16) & 0xff,
devpriv->main_iobase + ADC_COUNT_UPPER_REG);
} else {
writew(1, devpriv->main_iobase + ADC_COUNT_LOWER_REG);
}
}
static inline unsigned int dma_transfer_size(struct comedi_device *dev)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
unsigned int num_samples;
num_samples = devpriv->ai_fifo_segment_length *
thisboard->ai_fifo->sample_packing_ratio;
if (num_samples > DMA_BUFFER_SIZE / sizeof(uint16_t))
num_samples = DMA_BUFFER_SIZE / sizeof(uint16_t);
return num_samples;
}
static uint32_t ai_convert_counter_6xxx(const struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
return cmd->convert_arg / TIMER_BASE - 3;
}
static uint32_t ai_scan_counter_6xxx(struct comedi_device *dev,
struct comedi_cmd *cmd)
{
uint32_t count;
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
count = (cmd->scan_begin_arg -
(cmd->convert_arg * (cmd->chanlist_len - 1))) /
TIMER_BASE;
break;
case TRIG_FOLLOW:
count = cmd->convert_arg / TIMER_BASE;
break;
default:
return 0;
break;
}
return count - 3;
}
static uint32_t ai_convert_counter_4020(struct comedi_device *dev,
struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int divisor;
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
divisor = cmd->scan_begin_arg / TIMER_BASE;
break;
case TRIG_OTHER:
divisor = devpriv->ext_clock.divisor;
break;
default:
comedi_error(dev, "bug! failed to set ai pacing!");
divisor = 1000;
break;
}
return divisor - 2;
}
static void select_master_clock_4020(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
devpriv->hw_config_bits &= ~MASTER_CLOCK_4020_MASK;
if (cmd->scan_begin_src == TRIG_OTHER) {
int chanspec = devpriv->ext_clock.chanspec;
if (CR_CHAN(chanspec))
devpriv->hw_config_bits |= BNC_CLOCK_4020_BITS;
else
devpriv->hw_config_bits |= EXT_CLOCK_4020_BITS;
} else {
devpriv->hw_config_bits |= INTERNAL_CLOCK_4020_BITS;
}
writew(devpriv->hw_config_bits,
devpriv->main_iobase + HW_CONFIG_REG);
}
static void select_master_clock(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
switch (thisboard->layout) {
case LAYOUT_4020:
select_master_clock_4020(dev, cmd);
break;
default:
break;
}
}
static inline void dma_start_sync(struct comedi_device *dev,
unsigned int channel)
{
struct pcidas64_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
if (channel)
writeb(PLX_DMA_EN_BIT | PLX_DMA_START_BIT |
PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_iobase + PLX_DMA1_CS_REG);
else
writeb(PLX_DMA_EN_BIT | PLX_DMA_START_BIT |
PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_iobase + PLX_DMA0_CS_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
static void set_ai_pacing(struct comedi_device *dev, struct comedi_cmd *cmd)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
uint32_t convert_counter = 0, scan_counter = 0;
check_adc_timing(dev, cmd);
select_master_clock(dev, cmd);
if (thisboard->layout == LAYOUT_4020) {
convert_counter = ai_convert_counter_4020(dev, cmd);
} else {
convert_counter = ai_convert_counter_6xxx(dev, cmd);
scan_counter = ai_scan_counter_6xxx(dev, cmd);
}
writew(convert_counter & 0xffff,
devpriv->main_iobase + ADC_SAMPLE_INTERVAL_LOWER_REG);
DEBUG_PRINT("convert counter 0x%x\n", convert_counter);
writew((convert_counter >> 16) & 0xff,
devpriv->main_iobase + ADC_SAMPLE_INTERVAL_UPPER_REG);
writew(scan_counter & 0xffff,
devpriv->main_iobase + ADC_DELAY_INTERVAL_LOWER_REG);
writew((scan_counter >> 16) & 0xff,
devpriv->main_iobase + ADC_DELAY_INTERVAL_UPPER_REG);
DEBUG_PRINT("scan counter 0x%x\n", scan_counter);
}
static int use_internal_queue_6xxx(const struct comedi_cmd *cmd)
{
int i;
for (i = 0; i + 1 < cmd->chanlist_len; i++) {
if (CR_CHAN(cmd->chanlist[i + 1]) !=
CR_CHAN(cmd->chanlist[i]) + 1)
return 0;
if (CR_RANGE(cmd->chanlist[i + 1]) !=
CR_RANGE(cmd->chanlist[i]))
return 0;
if (CR_AREF(cmd->chanlist[i + 1]) != CR_AREF(cmd->chanlist[i]))
return 0;
}
return 1;
}
static int setup_channel_queue(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
unsigned short bits;
int i;
if (thisboard->layout != LAYOUT_4020) {
if (use_internal_queue_6xxx(cmd)) {
devpriv->hw_config_bits &= ~EXT_QUEUE_BIT;
writew(devpriv->hw_config_bits,
devpriv->main_iobase + HW_CONFIG_REG);
bits = 0;
bits |= adc_chan_bits(CR_CHAN(cmd->chanlist[0]));
bits |= ai_range_bits_6xxx(dev,
CR_RANGE(cmd->chanlist[0]));
bits |= se_diff_bit_6xxx(dev,
CR_AREF(cmd->chanlist[0]) ==
AREF_DIFF);
if (CR_AREF(cmd->chanlist[0]) == AREF_COMMON)
bits |= ADC_COMMON_BIT;
writew(adc_chan_bits
(CR_CHAN(cmd->chanlist[cmd->chanlist_len - 1])),
devpriv->main_iobase + ADC_QUEUE_HIGH_REG);
writew(bits,
devpriv->main_iobase + ADC_QUEUE_LOAD_REG);
} else {
if (dev->write_subdev && dev->write_subdev->busy) {
warn_external_queue(dev);
return -EBUSY;
}
devpriv->hw_config_bits |= EXT_QUEUE_BIT;
writew(devpriv->hw_config_bits,
devpriv->main_iobase + HW_CONFIG_REG);
writew(0,
devpriv->main_iobase + DAC_BUFFER_CLEAR_REG);
writew(0, devpriv->main_iobase + ADC_QUEUE_CLEAR_REG);
for (i = 0; i < cmd->chanlist_len; i++) {
bits = 0;
bits |= adc_chan_bits(CR_CHAN(cmd->
chanlist[i]));
bits |= ai_range_bits_6xxx(dev,
CR_RANGE(cmd->
chanlist
[i]));
bits |= se_diff_bit_6xxx(dev,
CR_AREF(cmd->
chanlist[i]) ==
AREF_DIFF);
if (CR_AREF(cmd->chanlist[i]) == AREF_COMMON)
bits |= ADC_COMMON_BIT;
if (i == cmd->chanlist_len - 1)
bits |= QUEUE_EOSCAN_BIT |
QUEUE_EOSEQ_BIT;
writew(bits,
devpriv->main_iobase +
ADC_QUEUE_FIFO_REG);
DEBUG_PRINT(
"wrote 0x%x to external channel queue\n",
bits);
}
writew(0, devpriv->main_iobase + ADC_QUEUE_CLEAR_REG);
writew(0, devpriv->main_iobase + ADC_QUEUE_LOAD_REG);
}
} else {
unsigned short old_cal_range_bits = devpriv->i2c_cal_range_bits;
devpriv->i2c_cal_range_bits &= ~ADC_SRC_4020_MASK;
devpriv->i2c_cal_range_bits |= adc_src_4020_bits(4);
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int channel = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
if (range == 0)
devpriv->i2c_cal_range_bits |=
attenuate_bit(channel);
else
devpriv->i2c_cal_range_bits &=
~attenuate_bit(channel);
}
if (old_cal_range_bits != devpriv->i2c_cal_range_bits) {
uint8_t i2c_data = devpriv->i2c_cal_range_bits;
i2c_write(dev, RANGE_CAL_I2C_ADDR, &i2c_data,
sizeof(i2c_data));
}
}
return 0;
}
static inline void load_first_dma_descriptor(struct comedi_device *dev,
unsigned int dma_channel,
unsigned int descriptor_bits)
{
struct pcidas64_private *devpriv = dev->private;
if (dma_channel) {
writel(0,
devpriv->plx9080_iobase + PLX_DMA1_TRANSFER_SIZE_REG);
writel(0, devpriv->plx9080_iobase + PLX_DMA1_PCI_ADDRESS_REG);
writel(0,
devpriv->plx9080_iobase + PLX_DMA1_LOCAL_ADDRESS_REG);
writel(descriptor_bits,
devpriv->plx9080_iobase + PLX_DMA1_DESCRIPTOR_REG);
} else {
writel(0,
devpriv->plx9080_iobase + PLX_DMA0_TRANSFER_SIZE_REG);
writel(0, devpriv->plx9080_iobase + PLX_DMA0_PCI_ADDRESS_REG);
writel(0,
devpriv->plx9080_iobase + PLX_DMA0_LOCAL_ADDRESS_REG);
writel(descriptor_bits,
devpriv->plx9080_iobase + PLX_DMA0_DESCRIPTOR_REG);
}
}
static int ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
uint32_t bits;
unsigned int i;
unsigned long flags;
int retval;
disable_ai_pacing(dev);
abort_dma(dev, 1);
retval = setup_channel_queue(dev, cmd);
if (retval < 0)
return retval;
writew(0, devpriv->main_iobase + CALIBRATION_REG);
set_ai_pacing(dev, cmd);
setup_sample_counters(dev, cmd);
enable_ai_interrupts(dev, cmd);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->adc_control1_bits |= ADC_SW_GATE_BIT;
devpriv->adc_control1_bits &= ~ADC_DITHER_BIT;
if (thisboard->layout != LAYOUT_4020) {
devpriv->adc_control1_bits &= ~ADC_MODE_MASK;
if (cmd->convert_src == TRIG_EXT)
devpriv->adc_control1_bits |= adc_mode_bits(13);
else
devpriv->adc_control1_bits |= adc_mode_bits(8);
} else {
devpriv->adc_control1_bits &= ~CHANNEL_MODE_4020_MASK;
if (cmd->chanlist_len == 4)
devpriv->adc_control1_bits |= FOUR_CHANNEL_4020_BITS;
else if (cmd->chanlist_len == 2)
devpriv->adc_control1_bits |= TWO_CHANNEL_4020_BITS;
devpriv->adc_control1_bits &= ~ADC_LO_CHANNEL_4020_MASK;
devpriv->adc_control1_bits |=
adc_lo_chan_4020_bits(CR_CHAN(cmd->chanlist[0]));
devpriv->adc_control1_bits &= ~ADC_HI_CHANNEL_4020_MASK;
devpriv->adc_control1_bits |=
adc_hi_chan_4020_bits(CR_CHAN(cmd->chanlist
[cmd->chanlist_len - 1]));
}
writew(devpriv->adc_control1_bits,
devpriv->main_iobase + ADC_CONTROL1_REG);
DEBUG_PRINT("control1 bits 0x%x\n", devpriv->adc_control1_bits);
spin_unlock_irqrestore(&dev->spinlock, flags);
writew(0, devpriv->main_iobase + ADC_BUFFER_CLEAR_REG);
if ((cmd->flags & TRIG_WAKE_EOS) == 0 ||
thisboard->layout == LAYOUT_4020) {
devpriv->ai_dma_index = 0;
for (i = 0; i < ai_dma_ring_count(thisboard); i++)
devpriv->ai_dma_desc[i].transfer_size =
cpu_to_le32(dma_transfer_size(dev) *
sizeof(uint16_t));
load_first_dma_descriptor(dev, 1,
devpriv->ai_dma_desc_bus_addr |
PLX_DESC_IN_PCI_BIT |
PLX_INTR_TERM_COUNT |
PLX_XFER_LOCAL_TO_PCI);
dma_start_sync(dev, 1);
}
if (thisboard->layout == LAYOUT_4020) {
bits = 0;
if (cmd->start_src == TRIG_EXT && CR_CHAN(cmd->start_arg))
bits |= EXT_START_TRIG_BNC_BIT;
if (cmd->stop_src == TRIG_EXT && CR_CHAN(cmd->stop_arg))
bits |= EXT_STOP_TRIG_BNC_BIT;
writew(bits, devpriv->main_iobase + DAQ_ATRIG_LOW_4020_REG);
}
spin_lock_irqsave(&dev->spinlock, flags);
bits = ADC_ENABLE_BIT | ADC_SOFT_GATE_BITS | ADC_GATE_LEVEL_BIT;
if (cmd->flags & TRIG_WAKE_EOS)
bits |= ADC_DMA_DISABLE_BIT;
if (cmd->start_src == TRIG_EXT) {
bits |= ADC_START_TRIG_EXT_BITS;
if (cmd->start_arg & CR_INVERT)
bits |= ADC_START_TRIG_FALLING_BIT;
} else if (cmd->start_src == TRIG_NOW)
bits |= ADC_START_TRIG_SOFT_BITS;
if (use_hw_sample_counter(cmd))
bits |= ADC_SAMPLE_COUNTER_EN_BIT;
writew(bits, devpriv->main_iobase + ADC_CONTROL0_REG);
DEBUG_PRINT("control0 bits 0x%x\n", bits);
devpriv->ai_cmd_running = 1;
spin_unlock_irqrestore(&dev->spinlock, flags);
if (cmd->start_src == TRIG_NOW) {
writew(0, devpriv->main_iobase + ADC_START_REG);
DEBUG_PRINT("soft trig\n");
}
return 0;
}
static void pio_drain_ai_fifo_16(struct comedi_device *dev)
{
struct pcidas64_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int i;
uint16_t prepost_bits;
int read_segment, read_index, write_segment, write_index;
int num_samples;
do {
read_index = readw(devpriv->main_iobase + ADC_READ_PNTR_REG) &
0x7fff;
write_index = readw(devpriv->main_iobase + ADC_WRITE_PNTR_REG) &
0x7fff;
prepost_bits = readw(devpriv->main_iobase + PREPOST_REG);
read_segment = adc_upper_read_ptr_code(prepost_bits);
write_segment = adc_upper_write_ptr_code(prepost_bits);
DEBUG_PRINT(" rd seg %i, wrt seg %i, rd idx %i, wrt idx %i\n",
read_segment, write_segment, read_index,
write_index);
if (read_segment != write_segment)
num_samples =
devpriv->ai_fifo_segment_length - read_index;
else
num_samples = write_index - read_index;
if (cmd->stop_src == TRIG_COUNT) {
if (devpriv->ai_count == 0)
break;
if (num_samples > devpriv->ai_count)
num_samples = devpriv->ai_count;
devpriv->ai_count -= num_samples;
}
if (num_samples < 0) {
dev_err(dev->class_dev,
"cb_pcidas64: bug! num_samples < 0\n");
break;
}
DEBUG_PRINT(" read %i samples from fifo\n", num_samples);
for (i = 0; i < num_samples; i++) {
cfc_write_to_buffer(s,
readw(devpriv->main_iobase +
ADC_FIFO_REG));
}
} while (read_segment != write_segment);
}
static void pio_drain_ai_fifo_32(struct comedi_device *dev)
{
struct pcidas64_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int i;
unsigned int max_transfer = 100000;
uint32_t fifo_data;
int write_code =
readw(devpriv->main_iobase + ADC_WRITE_PNTR_REG) & 0x7fff;
int read_code =
readw(devpriv->main_iobase + ADC_READ_PNTR_REG) & 0x7fff;
if (cmd->stop_src == TRIG_COUNT) {
if (max_transfer > devpriv->ai_count)
max_transfer = devpriv->ai_count;
}
for (i = 0; read_code != write_code && i < max_transfer;) {
fifo_data = readl(devpriv->dio_counter_iobase + ADC_FIFO_REG);
cfc_write_to_buffer(s, fifo_data & 0xffff);
i++;
if (i < max_transfer) {
cfc_write_to_buffer(s, (fifo_data >> 16) & 0xffff);
i++;
}
read_code = readw(devpriv->main_iobase + ADC_READ_PNTR_REG) &
0x7fff;
}
devpriv->ai_count -= i;
}
static void pio_drain_ai_fifo(struct comedi_device *dev)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
if (thisboard->layout == LAYOUT_4020)
pio_drain_ai_fifo_32(dev);
else
pio_drain_ai_fifo_16(dev);
}
static void drain_dma_buffers(struct comedi_device *dev, unsigned int channel)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
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
for (j = 0, next_transfer_addr = readl(pci_addr_reg);
(next_transfer_addr <
devpriv->ai_buffer_bus_addr[devpriv->ai_dma_index] ||
next_transfer_addr >=
devpriv->ai_buffer_bus_addr[devpriv->ai_dma_index] +
DMA_BUFFER_SIZE) && j < ai_dma_ring_count(thisboard); j++) {
num_samples = dma_transfer_size(dev);
if (async->cmd.stop_src == TRIG_COUNT) {
if (num_samples > devpriv->ai_count)
num_samples = devpriv->ai_count;
devpriv->ai_count -= num_samples;
}
cfc_write_array_to_buffer(dev->read_subdev,
devpriv->ai_buffer[devpriv->
ai_dma_index],
num_samples * sizeof(uint16_t));
devpriv->ai_dma_index = (devpriv->ai_dma_index + 1) %
ai_dma_ring_count(thisboard);
DEBUG_PRINT("next buffer addr 0x%lx\n",
(unsigned long)devpriv->
ai_buffer_bus_addr[devpriv->ai_dma_index]);
DEBUG_PRINT("pci addr reg 0x%x\n", next_transfer_addr);
}
}
static void handle_ai_interrupt(struct comedi_device *dev,
unsigned short status,
unsigned int plx_status)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
uint8_t dma1_status;
unsigned long flags;
if (status & ADC_OVERRUN_BIT) {
comedi_error(dev, "fifo overrun");
async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
}
spin_lock_irqsave(&dev->spinlock, flags);
dma1_status = readb(devpriv->plx9080_iobase + PLX_DMA1_CS_REG);
if (plx_status & ICS_DMA1_A) {
writeb((dma1_status & PLX_DMA_EN_BIT) | PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_iobase + PLX_DMA1_CS_REG);
DEBUG_PRINT("dma1 status 0x%x\n", dma1_status);
if (dma1_status & PLX_DMA_EN_BIT)
drain_dma_buffers(dev, 1);
DEBUG_PRINT(" cleared dma ch1 interrupt\n");
}
spin_unlock_irqrestore(&dev->spinlock, flags);
if (status & ADC_DONE_BIT)
DEBUG_PRINT("adc done interrupt\n");
if ((status & ADC_DONE_BIT) ||
((cmd->flags & TRIG_WAKE_EOS) &&
(status & ADC_INTR_PENDING_BIT) &&
(thisboard->layout != LAYOUT_4020))) {
DEBUG_PRINT("pio fifo drain\n");
spin_lock_irqsave(&dev->spinlock, flags);
if (devpriv->ai_cmd_running) {
spin_unlock_irqrestore(&dev->spinlock, flags);
pio_drain_ai_fifo(dev);
} else
spin_unlock_irqrestore(&dev->spinlock, flags);
}
if ((cmd->stop_src == TRIG_COUNT && (int)devpriv->ai_count <= 0) ||
(cmd->stop_src == TRIG_EXT && (status & ADC_STOP_BIT))) {
async->events |= COMEDI_CB_EOA;
}
cfc_handle_events(dev, s);
}
static inline unsigned int prev_ao_dma_index(struct comedi_device *dev)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int buffer_index;
if (devpriv->ao_dma_index == 0)
buffer_index = AO_DMA_RING_COUNT - 1;
else
buffer_index = devpriv->ao_dma_index - 1;
return buffer_index;
}
static int last_ao_dma_load_completed(struct comedi_device *dev)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int buffer_index;
unsigned int transfer_address;
unsigned short dma_status;
buffer_index = prev_ao_dma_index(dev);
dma_status = readb(devpriv->plx9080_iobase + PLX_DMA0_CS_REG);
if ((dma_status & PLX_DMA_DONE_BIT) == 0)
return 0;
transfer_address =
readl(devpriv->plx9080_iobase + PLX_DMA0_PCI_ADDRESS_REG);
if (transfer_address != devpriv->ao_buffer_bus_addr[buffer_index])
return 0;
return 1;
}
static int ao_stopped_by_error(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
if (cmd->stop_src == TRIG_NONE)
return 1;
if (cmd->stop_src == TRIG_COUNT) {
if (devpriv->ao_count)
return 1;
if (last_ao_dma_load_completed(dev) == 0)
return 1;
}
return 0;
}
static inline int ao_dma_needs_restart(struct comedi_device *dev,
unsigned short dma_status)
{
if ((dma_status & PLX_DMA_DONE_BIT) == 0 ||
(dma_status & PLX_DMA_EN_BIT) == 0)
return 0;
if (last_ao_dma_load_completed(dev))
return 0;
return 1;
}
static void restart_ao_dma(struct comedi_device *dev)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int dma_desc_bits;
dma_desc_bits =
readl(devpriv->plx9080_iobase + PLX_DMA0_DESCRIPTOR_REG);
dma_desc_bits &= ~PLX_END_OF_CHAIN_BIT;
DEBUG_PRINT("restarting ao dma, descriptor reg 0x%x\n", dma_desc_bits);
load_first_dma_descriptor(dev, 0, dma_desc_bits);
dma_start_sync(dev, 0);
}
static unsigned int load_ao_dma_buffer(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int num_bytes, buffer_index, prev_buffer_index;
unsigned int next_bits;
buffer_index = devpriv->ao_dma_index;
prev_buffer_index = prev_ao_dma_index(dev);
DEBUG_PRINT("attempting to load ao buffer %i (0x%llx)\n", buffer_index,
(unsigned long long)devpriv->ao_buffer_bus_addr[
buffer_index]);
num_bytes = comedi_buf_read_n_available(dev->write_subdev->async);
if (num_bytes > DMA_BUFFER_SIZE)
num_bytes = DMA_BUFFER_SIZE;
if (cmd->stop_src == TRIG_COUNT && num_bytes > devpriv->ao_count)
num_bytes = devpriv->ao_count;
num_bytes -= num_bytes % bytes_in_sample;
if (num_bytes == 0)
return 0;
DEBUG_PRINT("loading %i bytes\n", num_bytes);
num_bytes = cfc_read_array_from_buffer(dev->write_subdev,
devpriv->
ao_buffer[buffer_index],
num_bytes);
devpriv->ao_dma_desc[buffer_index].transfer_size =
cpu_to_le32(num_bytes);
next_bits = le32_to_cpu(devpriv->ao_dma_desc[buffer_index].next);
next_bits |= PLX_END_OF_CHAIN_BIT;
devpriv->ao_dma_desc[buffer_index].next = cpu_to_le32(next_bits);
next_bits = le32_to_cpu(devpriv->ao_dma_desc[prev_buffer_index].next);
next_bits &= ~PLX_END_OF_CHAIN_BIT;
devpriv->ao_dma_desc[prev_buffer_index].next = cpu_to_le32(next_bits);
devpriv->ao_dma_index = (buffer_index + 1) % AO_DMA_RING_COUNT;
devpriv->ao_count -= num_bytes;
return num_bytes;
}
static void load_ao_dma(struct comedi_device *dev, const struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int num_bytes;
unsigned int next_transfer_addr;
void __iomem *pci_addr_reg =
devpriv->plx9080_iobase + PLX_DMA0_PCI_ADDRESS_REG;
unsigned int buffer_index;
do {
buffer_index = devpriv->ao_dma_index;
next_transfer_addr = readl(pci_addr_reg);
if (next_transfer_addr >=
devpriv->ao_buffer_bus_addr[buffer_index] &&
next_transfer_addr <
devpriv->ao_buffer_bus_addr[buffer_index] +
DMA_BUFFER_SIZE)
return;
num_bytes = load_ao_dma_buffer(dev, cmd);
} while (num_bytes >= DMA_BUFFER_SIZE);
}
static void handle_ao_interrupt(struct comedi_device *dev,
unsigned short status, unsigned int plx_status)
{
struct pcidas64_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->write_subdev;
struct comedi_async *async;
struct comedi_cmd *cmd;
uint8_t dma0_status;
unsigned long flags;
if (s == NULL)
return;
async = s->async;
cmd = &async->cmd;
spin_lock_irqsave(&dev->spinlock, flags);
dma0_status = readb(devpriv->plx9080_iobase + PLX_DMA0_CS_REG);
if (plx_status & ICS_DMA0_A) {
if ((dma0_status & PLX_DMA_EN_BIT) &&
!(dma0_status & PLX_DMA_DONE_BIT))
writeb(PLX_DMA_EN_BIT | PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_iobase + PLX_DMA0_CS_REG);
else
writeb(PLX_CLEAR_DMA_INTR_BIT,
devpriv->plx9080_iobase + PLX_DMA0_CS_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
DEBUG_PRINT("dma0 status 0x%x\n", dma0_status);
if (dma0_status & PLX_DMA_EN_BIT) {
load_ao_dma(dev, cmd);
if (ao_dma_needs_restart(dev, dma0_status))
restart_ao_dma(dev);
}
DEBUG_PRINT(" cleared dma ch0 interrupt\n");
} else {
spin_unlock_irqrestore(&dev->spinlock, flags);
}
if ((status & DAC_DONE_BIT)) {
async->events |= COMEDI_CB_EOA;
if (ao_stopped_by_error(dev, cmd))
async->events |= COMEDI_CB_ERROR;
DEBUG_PRINT("plx dma0 desc reg 0x%x\n",
readl(devpriv->plx9080_iobase +
PLX_DMA0_DESCRIPTOR_REG));
DEBUG_PRINT("plx dma0 address reg 0x%x\n",
readl(devpriv->plx9080_iobase +
PLX_DMA0_PCI_ADDRESS_REG));
}
cfc_handle_events(dev, s);
}
static irqreturn_t handle_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcidas64_private *devpriv = dev->private;
unsigned short status;
uint32_t plx_status;
uint32_t plx_bits;
plx_status = readl(devpriv->plx9080_iobase + PLX_INTRCS_REG);
status = readw(devpriv->main_iobase + HW_STATUS_REG);
DEBUG_PRINT("hw status 0x%x, plx status 0x%x\n", status, plx_status);
if (dev->attached == 0) {
DEBUG_PRINT("premature interrupt, ignoring\n");
return IRQ_HANDLED;
}
handle_ai_interrupt(dev, status, plx_status);
handle_ao_interrupt(dev, status, plx_status);
if (plx_status & ICS_LDIA) {
plx_bits = readl(devpriv->plx9080_iobase + PLX_DBR_OUT_REG);
writel(plx_bits, devpriv->plx9080_iobase + PLX_DBR_OUT_REG);
DEBUG_PRINT(" cleared local doorbell bits 0x%x\n", plx_bits);
}
DEBUG_PRINT("exiting handler\n");
return IRQ_HANDLED;
}
static int ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcidas64_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
if (devpriv->ai_cmd_running == 0) {
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
devpriv->ai_cmd_running = 0;
spin_unlock_irqrestore(&dev->spinlock, flags);
disable_ai_pacing(dev);
abort_dma(dev, 1);
DEBUG_PRINT("ai canceled\n");
return 0;
}
static int ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int range = CR_RANGE(insn->chanspec);
writew(0, devpriv->main_iobase + DAC_CONTROL0_REG);
set_dac_range_bits(dev, &devpriv->dac_control1_bits, chan, range);
writew(devpriv->dac_control1_bits,
devpriv->main_iobase + DAC_CONTROL1_REG);
if (thisboard->layout == LAYOUT_4020) {
writew(data[0] & 0xff,
devpriv->main_iobase + dac_lsb_4020_reg(chan));
writew((data[0] >> 8) & 0xf,
devpriv->main_iobase + dac_msb_4020_reg(chan));
} else {
writew(data[0], devpriv->main_iobase + dac_convert_reg(chan));
}
devpriv->ao_value[chan] = data[0];
return 1;
}
static int ao_readback_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
data[0] = devpriv->ao_value[CR_CHAN(insn->chanspec)];
return 1;
}
static void set_dac_control0_reg(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int bits = DAC_ENABLE_BIT | WAVEFORM_GATE_LEVEL_BIT |
WAVEFORM_GATE_ENABLE_BIT | WAVEFORM_GATE_SELECT_BIT;
if (cmd->start_src == TRIG_EXT) {
bits |= WAVEFORM_TRIG_EXT_BITS;
if (cmd->start_arg & CR_INVERT)
bits |= WAVEFORM_TRIG_FALLING_BIT;
} else {
bits |= WAVEFORM_TRIG_SOFT_BITS;
}
if (cmd->scan_begin_src == TRIG_EXT) {
bits |= DAC_EXT_UPDATE_ENABLE_BIT;
if (cmd->scan_begin_arg & CR_INVERT)
bits |= DAC_EXT_UPDATE_FALLING_BIT;
}
writew(bits, devpriv->main_iobase + DAC_CONTROL0_REG);
}
static void set_dac_control1_reg(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
int i;
for (i = 0; i < cmd->chanlist_len; i++) {
int channel, range;
channel = CR_CHAN(cmd->chanlist[i]);
range = CR_RANGE(cmd->chanlist[i]);
set_dac_range_bits(dev, &devpriv->dac_control1_bits, channel,
range);
}
devpriv->dac_control1_bits |= DAC_SW_GATE_BIT;
writew(devpriv->dac_control1_bits,
devpriv->main_iobase + DAC_CONTROL1_REG);
}
static void set_dac_select_reg(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
uint16_t bits;
unsigned int first_channel, last_channel;
first_channel = CR_CHAN(cmd->chanlist[0]);
last_channel = CR_CHAN(cmd->chanlist[cmd->chanlist_len - 1]);
if (last_channel < first_channel)
comedi_error(dev, "bug! last ao channel < first ao channel");
bits = (first_channel & 0x7) | (last_channel & 0x7) << 3;
writew(bits, devpriv->main_iobase + DAC_SELECT_REG);
}
static unsigned int get_ao_divisor(unsigned int ns, unsigned int flags)
{
return get_divisor(ns, flags) - 2;
}
static void set_dac_interval_regs(struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int divisor;
if (cmd->scan_begin_src != TRIG_TIMER)
return;
divisor = get_ao_divisor(cmd->scan_begin_arg, cmd->flags);
if (divisor > max_counter_value) {
comedi_error(dev, "bug! ao divisor too big");
divisor = max_counter_value;
}
writew(divisor & 0xffff,
devpriv->main_iobase + DAC_SAMPLE_INTERVAL_LOWER_REG);
writew((divisor >> 16) & 0xff,
devpriv->main_iobase + DAC_SAMPLE_INTERVAL_UPPER_REG);
}
static int prep_ao_dma(struct comedi_device *dev, const struct comedi_cmd *cmd)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int num_bytes;
int i;
writew(0, devpriv->main_iobase + ADC_QUEUE_CLEAR_REG);
writew(0, devpriv->main_iobase + DAC_BUFFER_CLEAR_REG);
num_bytes = (DAC_FIFO_SIZE / 2) * bytes_in_sample;
if (cmd->stop_src == TRIG_COUNT &&
num_bytes / bytes_in_sample > devpriv->ao_count)
num_bytes = devpriv->ao_count * bytes_in_sample;
num_bytes = cfc_read_array_from_buffer(dev->write_subdev,
devpriv->ao_bounce_buffer,
num_bytes);
for (i = 0; i < num_bytes / bytes_in_sample; i++) {
writew(devpriv->ao_bounce_buffer[i],
devpriv->main_iobase + DAC_FIFO_REG);
}
devpriv->ao_count -= num_bytes / bytes_in_sample;
if (cmd->stop_src == TRIG_COUNT && devpriv->ao_count == 0)
return 0;
num_bytes = load_ao_dma_buffer(dev, cmd);
if (num_bytes == 0)
return -1;
if (num_bytes >= DMA_BUFFER_SIZE) ;
load_ao_dma(dev, cmd);
dma_start_sync(dev, 0);
return 0;
}
static inline int external_ai_queue_in_use(struct comedi_device *dev)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
if (dev->read_subdev->busy)
return 0;
if (thisboard->layout == LAYOUT_4020)
return 0;
else if (use_internal_queue_6xxx(&dev->read_subdev->async->cmd))
return 0;
return 1;
}
static int ao_inttrig(struct comedi_device *dev, struct comedi_subdevice *s,
unsigned int trig_num)
{
struct pcidas64_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int retval;
if (trig_num != 0)
return -EINVAL;
retval = prep_ao_dma(dev, cmd);
if (retval < 0)
return -EPIPE;
set_dac_control0_reg(dev, cmd);
if (cmd->start_src == TRIG_INT)
writew(0, devpriv->main_iobase + DAC_START_REG);
s->async->inttrig = NULL;
return 0;
}
static int ao_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcidas64_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
if (external_ai_queue_in_use(dev)) {
warn_external_queue(dev);
return -EBUSY;
}
writew(0x0, devpriv->main_iobase + DAC_CONTROL0_REG);
devpriv->ao_dma_index = 0;
devpriv->ao_count = cmd->stop_arg * cmd->chanlist_len;
set_dac_select_reg(dev, cmd);
set_dac_interval_regs(dev, cmd);
load_first_dma_descriptor(dev, 0, devpriv->ao_dma_desc_bus_addr |
PLX_DESC_IN_PCI_BIT | PLX_INTR_TERM_COUNT);
set_dac_control1_reg(dev, cmd);
s->async->inttrig = ao_inttrig;
return 0;
}
static int ao_cmdtest(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
int err = 0;
unsigned int tmp_arg;
int i;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_INT | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
if (cmd->convert_src == TRIG_EXT && cmd->scan_begin_src == TRIG_TIMER)
err |= -EINVAL;
if (cmd->stop_src != TRIG_COUNT &&
cmd->stop_src != TRIG_NONE && cmd->stop_src != TRIG_EXT)
err |= -EINVAL;
if (err)
return 2;
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
thisboard->ao_scan_speed);
if (get_ao_divisor(cmd->scan_begin_arg, cmd->flags) >
max_counter_value) {
cmd->scan_begin_arg = (max_counter_value + 2) *
TIMER_BASE;
err |= -EINVAL;
}
}
err |= cfc_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp_arg = cmd->scan_begin_arg;
cmd->scan_begin_arg = get_divisor(cmd->scan_begin_arg,
cmd->flags) * TIMER_BASE;
if (tmp_arg != cmd->scan_begin_arg)
err++;
}
if (err)
return 4;
if (cmd->chanlist) {
unsigned int first_channel = CR_CHAN(cmd->chanlist[0]);
for (i = 1; i < cmd->chanlist_len; i++) {
if (CR_CHAN(cmd->chanlist[i]) != first_channel + i) {
comedi_error(dev,
"chanlist must use consecutive channels");
err++;
break;
}
}
}
if (err)
return 5;
return 0;
}
static int ao_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcidas64_private *devpriv = dev->private;
writew(0x0, devpriv->main_iobase + DAC_CONTROL0_REG);
abort_dma(dev, 0);
return 0;
}
static int dio_callback(int dir, int port, int data, unsigned long arg)
{
void __iomem *iobase = (void __iomem *)arg;
if (dir) {
writeb(data, iobase + port);
DEBUG_PRINT("wrote 0x%x to port %i\n", data, port);
return 0;
} else {
return readb(iobase + port);
}
}
static int dio_callback_4020(int dir, int port, int data, unsigned long arg)
{
void __iomem *iobase = (void __iomem *)arg;
if (dir) {
writew(data, iobase + 2 * port);
return 0;
} else {
return readw(iobase + 2 * port);
}
}
static int di_rbits(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int bits;
bits = readb(devpriv->dio_counter_iobase + DI_REG);
bits &= 0xf;
data[1] = bits;
data[0] = 0;
return insn->n;
}
static int do_wbits(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
data[0] &= 0xf;
s->state &= ~data[0];
s->state |= data[0] & data[1];
writeb(s->state, devpriv->dio_counter_iobase + DO_REG);
data[1] = s->state;
return insn->n;
}
static int dio_60xx_config_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int mask;
mask = 1 << CR_CHAN(insn->chanspec);
switch (data[0]) {
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~mask;
break;
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= mask;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (s->io_bits & mask) ? COMEDI_OUTPUT : COMEDI_INPUT;
return 2;
default:
return -EINVAL;
}
writeb(s->io_bits,
devpriv->dio_counter_iobase + DIO_DIRECTION_60XX_REG);
return 1;
}
static int dio_60xx_wbits(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
writeb(s->state,
devpriv->dio_counter_iobase + DIO_DATA_60XX_REG);
}
data[1] = readb(devpriv->dio_counter_iobase + DIO_DATA_60XX_REG);
return insn->n;
}
static int caldac_8800_write(struct comedi_device *dev, unsigned int address,
uint8_t value)
{
struct pcidas64_private *devpriv = dev->private;
static const int num_caldac_channels = 8;
static const int bitstream_length = 11;
unsigned int bitstream = ((address & 0x7) << 8) | value;
unsigned int bit, register_bits;
static const int caldac_8800_udelay = 1;
if (address >= num_caldac_channels) {
comedi_error(dev, "illegal caldac channel");
return -1;
}
for (bit = 1 << (bitstream_length - 1); bit; bit >>= 1) {
register_bits = 0;
if (bitstream & bit)
register_bits |= SERIAL_DATA_IN_BIT;
udelay(caldac_8800_udelay);
writew(register_bits, devpriv->main_iobase + CALIBRATION_REG);
register_bits |= SERIAL_CLOCK_BIT;
udelay(caldac_8800_udelay);
writew(register_bits, devpriv->main_iobase + CALIBRATION_REG);
}
udelay(caldac_8800_udelay);
writew(SELECT_8800_BIT, devpriv->main_iobase + CALIBRATION_REG);
udelay(caldac_8800_udelay);
writew(0, devpriv->main_iobase + CALIBRATION_REG);
udelay(caldac_8800_udelay);
return 0;
}
static int caldac_i2c_write(struct comedi_device *dev,
unsigned int caldac_channel, unsigned int value)
{
uint8_t serial_bytes[3];
uint8_t i2c_addr;
enum pointer_bits {
OFFSET_0_2 = 0x1,
GAIN_0_2 = 0x2,
OFFSET_1_3 = 0x4,
GAIN_1_3 = 0x8,
};
enum data_bits {
NOT_CLEAR_REGISTERS = 0x20,
};
switch (caldac_channel) {
case 0:
i2c_addr = CALDAC0_I2C_ADDR;
serial_bytes[0] = OFFSET_0_2;
break;
case 1:
i2c_addr = CALDAC0_I2C_ADDR;
serial_bytes[0] = OFFSET_1_3;
break;
case 2:
i2c_addr = CALDAC1_I2C_ADDR;
serial_bytes[0] = OFFSET_0_2;
break;
case 3:
i2c_addr = CALDAC1_I2C_ADDR;
serial_bytes[0] = OFFSET_1_3;
break;
case 4:
i2c_addr = CALDAC0_I2C_ADDR;
serial_bytes[0] = GAIN_0_2;
break;
case 5:
i2c_addr = CALDAC0_I2C_ADDR;
serial_bytes[0] = GAIN_1_3;
break;
case 6:
i2c_addr = CALDAC1_I2C_ADDR;
serial_bytes[0] = GAIN_0_2;
break;
case 7:
i2c_addr = CALDAC1_I2C_ADDR;
serial_bytes[0] = GAIN_1_3;
break;
default:
comedi_error(dev, "invalid caldac channel\n");
return -1;
break;
}
serial_bytes[1] = NOT_CLEAR_REGISTERS | ((value >> 8) & 0xf);
serial_bytes[2] = value & 0xff;
i2c_write(dev, i2c_addr, serial_bytes, 3);
return 0;
}
static void caldac_write(struct comedi_device *dev, unsigned int channel,
unsigned int value)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
devpriv->caldac_state[channel] = value;
switch (thisboard->layout) {
case LAYOUT_60XX:
case LAYOUT_64XX:
caldac_8800_write(dev, channel, value);
break;
case LAYOUT_4020:
caldac_i2c_write(dev, channel, value);
break;
default:
break;
}
}
static int calib_write_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
int channel = CR_CHAN(insn->chanspec);
if (devpriv->caldac_state[channel] == data[0])
return 1;
caldac_write(dev, channel, data[0]);
return 1;
}
static int calib_read_insn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int channel = CR_CHAN(insn->chanspec);
data[0] = devpriv->caldac_state[channel];
return 1;
}
static void ad8402_write(struct comedi_device *dev, unsigned int channel,
unsigned int value)
{
struct pcidas64_private *devpriv = dev->private;
static const int bitstream_length = 10;
unsigned int bit, register_bits;
unsigned int bitstream = ((channel & 0x3) << 8) | (value & 0xff);
static const int ad8402_udelay = 1;
devpriv->ad8402_state[channel] = value;
register_bits = SELECT_8402_64XX_BIT;
udelay(ad8402_udelay);
writew(register_bits, devpriv->main_iobase + CALIBRATION_REG);
for (bit = 1 << (bitstream_length - 1); bit; bit >>= 1) {
if (bitstream & bit)
register_bits |= SERIAL_DATA_IN_BIT;
else
register_bits &= ~SERIAL_DATA_IN_BIT;
udelay(ad8402_udelay);
writew(register_bits, devpriv->main_iobase + CALIBRATION_REG);
udelay(ad8402_udelay);
writew(register_bits | SERIAL_CLOCK_BIT,
devpriv->main_iobase + CALIBRATION_REG);
}
udelay(ad8402_udelay);
writew(0, devpriv->main_iobase + CALIBRATION_REG);
}
static int ad8402_write_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
int channel = CR_CHAN(insn->chanspec);
if (devpriv->ad8402_state[channel] == data[0])
return 1;
devpriv->ad8402_state[channel] = data[0];
ad8402_write(dev, channel, data[0]);
return 1;
}
static int ad8402_read_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcidas64_private *devpriv = dev->private;
unsigned int channel = CR_CHAN(insn->chanspec);
data[0] = devpriv->ad8402_state[channel];
return 1;
}
static uint16_t read_eeprom(struct comedi_device *dev, uint8_t address)
{
struct pcidas64_private *devpriv = dev->private;
static const int bitstream_length = 11;
static const int read_command = 0x6;
unsigned int bitstream = (read_command << 8) | address;
unsigned int bit;
void __iomem * const plx_control_addr =
devpriv->plx9080_iobase + PLX_CONTROL_REG;
uint16_t value;
static const int value_length = 16;
static const int eeprom_udelay = 1;
udelay(eeprom_udelay);
devpriv->plx_control_bits &= ~CTL_EE_CLK & ~CTL_EE_CS;
devpriv->plx_control_bits |= CTL_USERO;
writel(devpriv->plx_control_bits, plx_control_addr);
udelay(eeprom_udelay);
devpriv->plx_control_bits |= CTL_EE_CS;
writel(devpriv->plx_control_bits, plx_control_addr);
for (bit = 1 << (bitstream_length - 1); bit; bit >>= 1) {
udelay(eeprom_udelay);
if (bitstream & bit)
devpriv->plx_control_bits |= CTL_EE_W;
else
devpriv->plx_control_bits &= ~CTL_EE_W;
writel(devpriv->plx_control_bits, plx_control_addr);
udelay(eeprom_udelay);
devpriv->plx_control_bits |= CTL_EE_CLK;
writel(devpriv->plx_control_bits, plx_control_addr);
udelay(eeprom_udelay);
devpriv->plx_control_bits &= ~CTL_EE_CLK;
writel(devpriv->plx_control_bits, plx_control_addr);
}
value = 0;
for (bit = 1 << (value_length - 1); bit; bit >>= 1) {
udelay(eeprom_udelay);
devpriv->plx_control_bits |= CTL_EE_CLK;
writel(devpriv->plx_control_bits, plx_control_addr);
udelay(eeprom_udelay);
devpriv->plx_control_bits &= ~CTL_EE_CLK;
writel(devpriv->plx_control_bits, plx_control_addr);
udelay(eeprom_udelay);
if (readl(plx_control_addr) & CTL_EE_R)
value |= bit;
}
udelay(eeprom_udelay);
devpriv->plx_control_bits &= ~CTL_EE_CS;
writel(devpriv->plx_control_bits, plx_control_addr);
return value;
}
static int eeprom_read_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = read_eeprom(dev, CR_CHAN(insn->chanspec));
return 1;
}
static int setup_subdevices(struct comedi_device *dev)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pcidas64_private *devpriv = dev->private;
struct comedi_subdevice *s;
void __iomem *dio_8255_iobase;
int i;
int ret;
ret = comedi_alloc_subdevices(dev, 10);
if (ret)
return ret;
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DITHER | SDF_CMD_READ;
if (thisboard->layout == LAYOUT_60XX)
s->subdev_flags |= SDF_COMMON | SDF_DIFF;
else if (thisboard->layout == LAYOUT_64XX)
s->subdev_flags |= SDF_DIFF;
s->n_chan = thisboard->ai_se_chans;
s->len_chanlist = 0x2000;
s->maxdata = (1 << thisboard->ai_bits) - 1;
s->range_table = thisboard->ai_range_table;
s->insn_read = ai_rinsn;
s->insn_config = ai_config_insn;
s->do_cmd = ai_cmd;
s->do_cmdtest = ai_cmdtest;
s->cancel = ai_cancel;
if (thisboard->layout == LAYOUT_4020) {
uint8_t data;
devpriv->i2c_cal_range_bits = adc_src_4020_bits(4);
for (i = 0; i < s->n_chan; i++)
devpriv->i2c_cal_range_bits |= attenuate_bit(i);
data = devpriv->i2c_cal_range_bits;
i2c_write(dev, RANGE_CAL_I2C_ADDR, &data, sizeof(data));
}
s = &dev->subdevices[1];
if (thisboard->ao_nchan) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE |
SDF_GROUND | SDF_CMD_WRITE;
s->n_chan = thisboard->ao_nchan;
s->maxdata = (1 << thisboard->ao_bits) - 1;
s->range_table = thisboard->ao_range_table;
s->insn_read = ao_readback_insn;
s->insn_write = ao_winsn;
if (ao_cmd_is_supported(thisboard)) {
dev->write_subdev = s;
s->do_cmdtest = ao_cmdtest;
s->do_cmd = ao_cmd;
s->len_chanlist = thisboard->ao_nchan;
s->cancel = ao_cancel;
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
if (thisboard->layout == LAYOUT_64XX) {
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = di_rbits;
} else
s->type = COMEDI_SUBD_UNUSED;
if (thisboard->layout == LAYOUT_64XX) {
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = do_wbits;
} else
s->type = COMEDI_SUBD_UNUSED;
s = &dev->subdevices[4];
if (thisboard->has_8255) {
if (thisboard->layout == LAYOUT_4020) {
dio_8255_iobase = devpriv->main_iobase + I8255_4020_REG;
subdev_8255_init(dev, s, dio_callback_4020,
(unsigned long)dio_8255_iobase);
} else {
dio_8255_iobase =
devpriv->dio_counter_iobase + DIO_8255_OFFSET;
subdev_8255_init(dev, s, dio_callback,
(unsigned long)dio_8255_iobase);
}
} else
s->type = COMEDI_SUBD_UNUSED;
s = &dev->subdevices[5];
if (thisboard->layout == LAYOUT_60XX) {
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = dio_60xx_config_insn;
s->insn_bits = dio_60xx_wbits;
} else
s->type = COMEDI_SUBD_UNUSED;
s = &dev->subdevices[6];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 8;
if (thisboard->layout == LAYOUT_4020)
s->maxdata = 0xfff;
else
s->maxdata = 0xff;
s->insn_read = calib_read_insn;
s->insn_write = calib_write_insn;
for (i = 0; i < s->n_chan; i++)
caldac_write(dev, i, s->maxdata / 2);
s = &dev->subdevices[7];
if (thisboard->layout == LAYOUT_64XX) {
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 2;
s->insn_read = ad8402_read_insn;
s->insn_write = ad8402_write_insn;
s->maxdata = 0xff;
for (i = 0; i < s->n_chan; i++)
ad8402_write(dev, i, s->maxdata / 2);
} else
s->type = COMEDI_SUBD_UNUSED;
s = &dev->subdevices[8];
if (readl(devpriv->plx9080_iobase + PLX_CONTROL_REG) & CTL_EECHK) {
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE | SDF_INTERNAL;
s->n_chan = 128;
s->maxdata = 0xffff;
s->insn_read = eeprom_read_insn;
} else
s->type = COMEDI_SUBD_UNUSED;
s = &dev->subdevices[9];
s->type = COMEDI_SUBD_UNUSED;
return 0;
}
static const struct pcidas64_board
*cb_pcidas64_find_pci_board(struct pci_dev *pcidev)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(pcidas64_boards); i++)
if (pcidev->device == pcidas64_boards[i].device_id)
return &pcidas64_boards[i];
return NULL;
}
static int auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
const struct pcidas64_board *thisboard;
struct pcidas64_private *devpriv;
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
uint32_t local_range, local_decode;
int retval;
dev->board_ptr = cb_pcidas64_find_pci_board(pcidev);
if (!dev->board_ptr) {
dev_err(dev->class_dev,
"cb_pcidas64: does not support pci %s\n",
pci_name(pcidev));
return -EINVAL;
}
thisboard = comedi_board(dev);
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
if (comedi_pci_enable(pcidev, dev->driver->driver_name)) {
dev_warn(dev->class_dev,
"failed to enable PCI device and request regions\n");
return -EIO;
}
pci_set_master(pcidev);
dev->board_name = thisboard->name;
dev->iobase = pci_resource_start(pcidev, MAIN_BADDRINDEX);
devpriv->plx9080_phys_iobase =
pci_resource_start(pcidev, PLX9080_BADDRINDEX);
devpriv->main_phys_iobase = dev->iobase;
devpriv->dio_counter_phys_iobase =
pci_resource_start(pcidev, DIO_COUNTER_BADDRINDEX);
devpriv->plx9080_iobase =
ioremap(devpriv->plx9080_phys_iobase,
pci_resource_len(pcidev, PLX9080_BADDRINDEX));
devpriv->main_iobase =
ioremap(devpriv->main_phys_iobase,
pci_resource_len(pcidev, MAIN_BADDRINDEX));
devpriv->dio_counter_iobase =
ioremap(devpriv->dio_counter_phys_iobase,
pci_resource_len(pcidev, DIO_COUNTER_BADDRINDEX));
if (!devpriv->plx9080_iobase || !devpriv->main_iobase
|| !devpriv->dio_counter_iobase) {
dev_warn(dev->class_dev, "failed to remap io memory\n");
return -ENOMEM;
}
DEBUG_PRINT(" plx9080 remapped to 0x%p\n", devpriv->plx9080_iobase);
DEBUG_PRINT(" main remapped to 0x%p\n", devpriv->main_iobase);
DEBUG_PRINT(" diocounter remapped to 0x%p\n",
devpriv->dio_counter_iobase);
local_range = readl(devpriv->plx9080_iobase + PLX_LAS0RNG_REG) &
LRNG_MEM_MASK;
local_decode = readl(devpriv->plx9080_iobase + PLX_LAS0MAP_REG) &
local_range & LMAP_MEM_MASK;
devpriv->local0_iobase = ((uint32_t)devpriv->main_phys_iobase &
~local_range) | local_decode;
local_range = readl(devpriv->plx9080_iobase + PLX_LAS1RNG_REG) &
LRNG_MEM_MASK;
local_decode = readl(devpriv->plx9080_iobase + PLX_LAS1MAP_REG) &
local_range & LMAP_MEM_MASK;
devpriv->local1_iobase = ((uint32_t)devpriv->dio_counter_phys_iobase &
~local_range) | local_decode;
DEBUG_PRINT(" local 0 io addr 0x%x\n", devpriv->local0_iobase);
DEBUG_PRINT(" local 1 io addr 0x%x\n", devpriv->local1_iobase);
retval = alloc_and_init_dma_members(dev);
if (retval < 0)
return retval;
devpriv->hw_revision =
hw_revision(dev, readw(devpriv->main_iobase + HW_STATUS_REG));
dev_dbg(dev->class_dev, "stc hardware revision %i\n",
devpriv->hw_revision);
init_plx9080(dev);
init_stc_registers(dev);
if (request_irq(pcidev->irq, handle_interrupt, IRQF_SHARED,
"cb_pcidas64", dev)) {
dev_dbg(dev->class_dev, "unable to allocate irq %u\n",
pcidev->irq);
return -EINVAL;
}
dev->irq = pcidev->irq;
dev_dbg(dev->class_dev, "irq %u\n", dev->irq);
retval = setup_subdevices(dev);
if (retval < 0)
return retval;
return 0;
}
static void detach(struct comedi_device *dev)
{
const struct pcidas64_board *thisboard = comedi_board(dev);
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct pcidas64_private *devpriv = dev->private;
unsigned int i;
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
if (pcidev) {
if (devpriv->plx9080_iobase) {
disable_plx_interrupts(dev);
iounmap(devpriv->plx9080_iobase);
}
if (devpriv->main_iobase)
iounmap(devpriv->main_iobase);
if (devpriv->dio_counter_iobase)
iounmap(devpriv->dio_counter_iobase);
for (i = 0; i < ai_dma_ring_count(thisboard); i++) {
if (devpriv->ai_buffer[i])
pci_free_consistent(pcidev,
DMA_BUFFER_SIZE,
devpriv->ai_buffer[i],
devpriv->ai_buffer_bus_addr[i]);
}
for (i = 0; i < AO_DMA_RING_COUNT; i++) {
if (devpriv->ao_buffer[i])
pci_free_consistent(pcidev,
DMA_BUFFER_SIZE,
devpriv->ao_buffer[i],
devpriv->ao_buffer_bus_addr[i]);
}
if (devpriv->ai_dma_desc)
pci_free_consistent(pcidev,
sizeof(struct plx_dma_desc) *
ai_dma_ring_count(thisboard),
devpriv->ai_dma_desc,
devpriv->ai_dma_desc_bus_addr);
if (devpriv->ao_dma_desc)
pci_free_consistent(pcidev,
sizeof(struct plx_dma_desc) *
AO_DMA_RING_COUNT,
devpriv->ao_dma_desc,
devpriv->ao_dma_desc_bus_addr);
}
}
if (dev->subdevices)
subdev_8255_cleanup(dev, &dev->subdevices[4]);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int cb_pcidas64_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &cb_pcidas64_driver);
}
static void cb_pcidas64_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
