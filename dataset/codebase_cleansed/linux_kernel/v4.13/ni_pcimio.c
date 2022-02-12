static int pcimio_ai_change(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_private *devpriv = dev->private;
int ret;
ret = mite_buf_change(devpriv->ai_mite_ring, s);
if (ret < 0)
return ret;
return 0;
}
static int pcimio_ao_change(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_private *devpriv = dev->private;
int ret;
ret = mite_buf_change(devpriv->ao_mite_ring, s);
if (ret < 0)
return ret;
return 0;
}
static int pcimio_gpct0_change(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_private *devpriv = dev->private;
int ret;
ret = mite_buf_change(devpriv->gpct_mite_ring[0], s);
if (ret < 0)
return ret;
return 0;
}
static int pcimio_gpct1_change(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_private *devpriv = dev->private;
int ret;
ret = mite_buf_change(devpriv->gpct_mite_ring[1], s);
if (ret < 0)
return ret;
return 0;
}
static int pcimio_dio_change(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct ni_private *devpriv = dev->private;
int ret;
ret = mite_buf_change(devpriv->cdo_mite_ring, s);
if (ret < 0)
return ret;
return 0;
}
static void m_series_init_eeprom_buffer(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
struct mite *mite = devpriv->mite;
resource_size_t daq_phys_addr;
static const int Start_Cal_EEPROM = 0x400;
static const unsigned int window_size = 10;
unsigned int old_iodwbsr_bits;
unsigned int old_iodwbsr1_bits;
unsigned int old_iodwcr1_bits;
int i;
daq_phys_addr = pci_resource_start(mite->pcidev, 1);
old_iodwbsr_bits = readl(mite->mmio + MITE_IODWBSR);
old_iodwbsr1_bits = readl(mite->mmio + MITE_IODWBSR_1);
old_iodwcr1_bits = readl(mite->mmio + MITE_IODWCR_1);
writel(0x0, mite->mmio + MITE_IODWBSR);
writel(((0x80 | window_size) | daq_phys_addr),
mite->mmio + MITE_IODWBSR_1);
writel(0x1 | old_iodwcr1_bits, mite->mmio + MITE_IODWCR_1);
writel(0xf, mite->mmio + 0x30);
for (i = 0; i < M_SERIES_EEPROM_SIZE; ++i)
devpriv->eeprom_buffer[i] = ni_readb(dev, Start_Cal_EEPROM + i);
writel(old_iodwbsr1_bits, mite->mmio + MITE_IODWBSR_1);
writel(old_iodwbsr_bits, mite->mmio + MITE_IODWBSR);
writel(old_iodwcr1_bits, mite->mmio + MITE_IODWCR_1);
writel(0x0, mite->mmio + 0x30);
}
static void init_6143(struct comedi_device *dev)
{
const struct ni_board_struct *board = dev->board_ptr;
struct ni_private *devpriv = dev->private;
ni_stc_writew(dev, 0, NISTC_INT_CTRL_REG);
ni_writeb(dev, 0x00, NI6143_MAGIC_REG);
ni_writeb(dev, 0x80, NI6143_PIPELINE_DELAY_REG);
ni_writeb(dev, 0x00, NI6143_EOC_SET_REG);
ni_writel(dev, board->ai_fifo_depth / 2, NI6143_AI_FIFO_FLAG_REG);
devpriv->ai_calib_source_enabled = 0;
ni_writew(dev, devpriv->ai_calib_source | NI6143_CALIB_CHAN_RELAY_OFF,
NI6143_CALIB_CHAN_REG);
ni_writew(dev, devpriv->ai_calib_source, NI6143_CALIB_CHAN_REG);
}
static void pcimio_detach(struct comedi_device *dev)
{
struct ni_private *devpriv = dev->private;
mio_common_detach(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
mite_free_ring(devpriv->ai_mite_ring);
mite_free_ring(devpriv->ao_mite_ring);
mite_free_ring(devpriv->cdo_mite_ring);
mite_free_ring(devpriv->gpct_mite_ring[0]);
mite_free_ring(devpriv->gpct_mite_ring[1]);
mite_detach(devpriv->mite);
}
if (dev->mmio)
iounmap(dev->mmio);
comedi_pci_disable(dev);
}
static int pcimio_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct ni_board_struct *board = NULL;
struct ni_private *devpriv;
unsigned int irq;
int ret;
if (context < ARRAY_SIZE(ni_boards))
board = &ni_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
ret = ni_alloc_private(dev);
if (ret)
return ret;
devpriv = dev->private;
devpriv->mite = mite_attach(dev, false);
if (!devpriv->mite)
return -ENOMEM;
if (board->reg_type & ni_reg_m_series_mask)
devpriv->is_m_series = 1;
if (board->reg_type & ni_reg_6xxx_mask)
devpriv->is_6xxx = 1;
if (board->reg_type == ni_reg_611x)
devpriv->is_611x = 1;
if (board->reg_type == ni_reg_6143)
devpriv->is_6143 = 1;
if (board->reg_type == ni_reg_622x)
devpriv->is_622x = 1;
if (board->reg_type == ni_reg_625x)
devpriv->is_625x = 1;
if (board->reg_type == ni_reg_628x)
devpriv->is_628x = 1;
if (board->reg_type & ni_reg_67xx_mask)
devpriv->is_67xx = 1;
if (board->reg_type == ni_reg_6711)
devpriv->is_6711 = 1;
if (board->reg_type == ni_reg_6713)
devpriv->is_6713 = 1;
devpriv->ai_mite_ring = mite_alloc_ring(devpriv->mite);
if (!devpriv->ai_mite_ring)
return -ENOMEM;
devpriv->ao_mite_ring = mite_alloc_ring(devpriv->mite);
if (!devpriv->ao_mite_ring)
return -ENOMEM;
devpriv->cdo_mite_ring = mite_alloc_ring(devpriv->mite);
if (!devpriv->cdo_mite_ring)
return -ENOMEM;
devpriv->gpct_mite_ring[0] = mite_alloc_ring(devpriv->mite);
if (!devpriv->gpct_mite_ring[0])
return -ENOMEM;
devpriv->gpct_mite_ring[1] = mite_alloc_ring(devpriv->mite);
if (!devpriv->gpct_mite_ring[1])
return -ENOMEM;
if (devpriv->is_m_series)
m_series_init_eeprom_buffer(dev);
if (devpriv->is_6143)
init_6143(dev);
irq = pcidev->irq;
if (irq) {
ret = request_irq(irq, ni_E_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = irq;
}
ret = ni_E_init(dev, 0, 1);
if (ret < 0)
return ret;
dev->subdevices[NI_AI_SUBDEV].buf_change = &pcimio_ai_change;
dev->subdevices[NI_AO_SUBDEV].buf_change = &pcimio_ao_change;
dev->subdevices[NI_GPCT_SUBDEV(0)].buf_change = &pcimio_gpct0_change;
dev->subdevices[NI_GPCT_SUBDEV(1)].buf_change = &pcimio_gpct1_change;
dev->subdevices[NI_DIO_SUBDEV].buf_change = &pcimio_dio_change;
return 0;
}
static int ni_pcimio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &ni_pcimio_driver, id->driver_data);
}
