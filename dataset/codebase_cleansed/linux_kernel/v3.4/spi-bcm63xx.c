static inline u8 bcm_spi_readb(struct bcm63xx_spi *bs,
unsigned int offset)
{
return bcm_readb(bs->regs + bcm63xx_spireg(offset));
}
static inline u16 bcm_spi_readw(struct bcm63xx_spi *bs,
unsigned int offset)
{
return bcm_readw(bs->regs + bcm63xx_spireg(offset));
}
static inline void bcm_spi_writeb(struct bcm63xx_spi *bs,
u8 value, unsigned int offset)
{
bcm_writeb(value, bs->regs + bcm63xx_spireg(offset));
}
static inline void bcm_spi_writew(struct bcm63xx_spi *bs,
u16 value, unsigned int offset)
{
bcm_writew(value, bs->regs + bcm63xx_spireg(offset));
}
static int bcm63xx_spi_check_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
u8 bits_per_word;
bits_per_word = (t) ? t->bits_per_word : spi->bits_per_word;
if (bits_per_word != 8) {
dev_err(&spi->dev, "%s, unsupported bits_per_word=%d\n",
__func__, bits_per_word);
return -EINVAL;
}
if (spi->chip_select > spi->master->num_chipselect) {
dev_err(&spi->dev, "%s, unsupported slave %d\n",
__func__, spi->chip_select);
return -EINVAL;
}
return 0;
}
static void bcm63xx_spi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct bcm63xx_spi *bs = spi_master_get_devdata(spi->master);
u32 hz;
u8 clk_cfg, reg;
int i;
hz = (t) ? t->speed_hz : spi->max_speed_hz;
for (i = 0; i < SPI_CLK_MASK; i++) {
if (hz <= bcm63xx_spi_freq_table[i][0]) {
clk_cfg = bcm63xx_spi_freq_table[i][1];
break;
}
}
if (i == SPI_CLK_MASK)
clk_cfg = SPI_CLK_0_391MHZ;
reg = bcm_spi_readb(bs, SPI_CLK_CFG);
reg &= ~SPI_CLK_MASK;
reg |= clk_cfg;
bcm_spi_writeb(bs, reg, SPI_CLK_CFG);
dev_dbg(&spi->dev, "Setting clock register to %02x (hz %d)\n",
clk_cfg, hz);
}
static int bcm63xx_spi_setup(struct spi_device *spi)
{
struct bcm63xx_spi *bs;
int ret;
bs = spi_master_get_devdata(spi->master);
if (!spi->bits_per_word)
spi->bits_per_word = 8;
if (spi->mode & ~MODEBITS) {
dev_err(&spi->dev, "%s, unsupported mode bits %x\n",
__func__, spi->mode & ~MODEBITS);
return -EINVAL;
}
ret = bcm63xx_spi_check_transfer(spi, NULL);
if (ret < 0) {
dev_err(&spi->dev, "setup: unsupported mode bits %x\n",
spi->mode & ~MODEBITS);
return ret;
}
dev_dbg(&spi->dev, "%s, mode %d, %u bits/w, %u nsec/bit\n",
__func__, spi->mode & MODEBITS, spi->bits_per_word, 0);
return 0;
}
static void bcm63xx_spi_fill_tx_fifo(struct bcm63xx_spi *bs)
{
u8 size;
size = bs->remaining_bytes < bs->fifo_size ? bs->remaining_bytes :
bs->fifo_size;
memcpy_toio(bs->tx_io, bs->tx_ptr, size);
bs->remaining_bytes -= size;
}
static unsigned int bcm63xx_txrx_bufs(struct spi_device *spi,
struct spi_transfer *t)
{
struct bcm63xx_spi *bs = spi_master_get_devdata(spi->master);
u16 msg_ctl;
u16 cmd;
bcm_spi_writeb(bs, 0, SPI_INT_MASK);
dev_dbg(&spi->dev, "txrx: tx %p, rx %p, len %d\n",
t->tx_buf, t->rx_buf, t->len);
bs->tx_ptr = t->tx_buf;
bs->rx_ptr = t->rx_buf;
if (t->tx_buf) {
bs->remaining_bytes = t->len;
bcm63xx_spi_fill_tx_fifo(bs);
}
init_completion(&bs->done);
msg_ctl = (t->len << SPI_BYTE_CNT_SHIFT);
if (t->rx_buf && t->tx_buf)
msg_ctl |= (SPI_FD_RW << SPI_MSG_TYPE_SHIFT);
else if (t->rx_buf)
msg_ctl |= (SPI_HD_R << SPI_MSG_TYPE_SHIFT);
else if (t->tx_buf)
msg_ctl |= (SPI_HD_W << SPI_MSG_TYPE_SHIFT);
bcm_spi_writew(bs, msg_ctl, SPI_MSG_CTL);
cmd = SPI_CMD_START_IMMEDIATE;
cmd |= (0 << SPI_CMD_PREPEND_BYTE_CNT_SHIFT);
cmd |= (spi->chip_select << SPI_CMD_DEVICE_ID_SHIFT);
bcm_spi_writew(bs, cmd, SPI_CMD);
bcm_spi_writeb(bs, SPI_INTR_CMD_DONE, SPI_INT_MASK);
return t->len - bs->remaining_bytes;
}
static int bcm63xx_spi_prepare_transfer(struct spi_master *master)
{
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
pm_runtime_get_sync(&bs->pdev->dev);
return 0;
}
static int bcm63xx_spi_unprepare_transfer(struct spi_master *master)
{
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
pm_runtime_put(&bs->pdev->dev);
return 0;
}
static int bcm63xx_spi_transfer_one(struct spi_master *master,
struct spi_message *m)
{
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
struct spi_transfer *t;
struct spi_device *spi = m->spi;
int status = 0;
unsigned int timeout = 0;
list_for_each_entry(t, &m->transfers, transfer_list) {
unsigned int len = t->len;
u8 rx_tail;
status = bcm63xx_spi_check_transfer(spi, t);
if (status < 0)
goto exit;
bcm63xx_spi_setup_transfer(spi, t);
while (len) {
len -= bcm63xx_txrx_bufs(spi, t);
timeout = wait_for_completion_timeout(&bs->done, HZ);
if (!timeout) {
status = -ETIMEDOUT;
goto exit;
}
rx_tail = bcm_spi_readb(bs, SPI_RX_TAIL);
if (rx_tail)
memcpy_fromio(bs->rx_ptr, bs->rx_io, rx_tail);
}
m->actual_length += t->len;
}
exit:
m->status = status;
spi_finalize_current_message(master);
return 0;
}
static irqreturn_t bcm63xx_spi_interrupt(int irq, void *dev_id)
{
struct spi_master *master = (struct spi_master *)dev_id;
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
u8 intr;
intr = bcm_spi_readb(bs, SPI_INT_STATUS);
bcm_spi_writeb(bs, SPI_INTR_CLEAR_ALL, SPI_INT_STATUS);
bcm_spi_writeb(bs, 0, SPI_INT_MASK);
if (intr & SPI_INTR_CMD_DONE)
complete(&bs->done);
return IRQ_HANDLED;
}
static int __devinit bcm63xx_spi_probe(struct platform_device *pdev)
{
struct resource *r;
struct device *dev = &pdev->dev;
struct bcm63xx_spi_pdata *pdata = pdev->dev.platform_data;
int irq;
struct spi_master *master;
struct clk *clk;
struct bcm63xx_spi *bs;
int ret;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(dev, "no iomem\n");
ret = -ENXIO;
goto out;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "no irq\n");
ret = -ENXIO;
goto out;
}
clk = clk_get(dev, "spi");
if (IS_ERR(clk)) {
dev_err(dev, "no clock for device\n");
ret = PTR_ERR(clk);
goto out;
}
master = spi_alloc_master(dev, sizeof(*bs));
if (!master) {
dev_err(dev, "out of memory\n");
ret = -ENOMEM;
goto out_clk;
}
bs = spi_master_get_devdata(master);
platform_set_drvdata(pdev, master);
bs->pdev = pdev;
if (!devm_request_mem_region(&pdev->dev, r->start,
resource_size(r), PFX)) {
dev_err(dev, "iomem request failed\n");
ret = -ENXIO;
goto out_err;
}
bs->regs = devm_ioremap_nocache(&pdev->dev, r->start,
resource_size(r));
if (!bs->regs) {
dev_err(dev, "unable to ioremap regs\n");
ret = -ENOMEM;
goto out_err;
}
bs->irq = irq;
bs->clk = clk;
bs->fifo_size = pdata->fifo_size;
ret = devm_request_irq(&pdev->dev, irq, bcm63xx_spi_interrupt, 0,
pdev->name, master);
if (ret) {
dev_err(dev, "unable to request irq\n");
goto out_err;
}
master->bus_num = pdata->bus_num;
master->num_chipselect = pdata->num_chipselect;
master->setup = bcm63xx_spi_setup;
master->prepare_transfer_hardware = bcm63xx_spi_prepare_transfer;
master->unprepare_transfer_hardware = bcm63xx_spi_unprepare_transfer;
master->transfer_one_message = bcm63xx_spi_transfer_one;
master->mode_bits = MODEBITS;
bs->speed_hz = pdata->speed_hz;
bs->tx_io = (u8 *)(bs->regs + bcm63xx_spireg(SPI_MSG_DATA));
bs->rx_io = (const u8 *)(bs->regs + bcm63xx_spireg(SPI_RX_DATA));
clk_enable(bs->clk);
bcm_spi_writeb(bs, SPI_INTR_CLEAR_ALL, SPI_INT_STATUS);
ret = spi_register_master(master);
if (ret) {
dev_err(dev, "spi register failed\n");
goto out_clk_disable;
}
dev_info(dev, "at 0x%08x (irq %d, FIFOs size %d) v%s\n",
r->start, irq, bs->fifo_size, DRV_VER);
return 0;
out_clk_disable:
clk_disable(clk);
out_err:
platform_set_drvdata(pdev, NULL);
spi_master_put(master);
out_clk:
clk_put(clk);
out:
return ret;
}
static int __devexit bcm63xx_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
spi_unregister_master(master);
bcm_spi_writeb(bs, 0, SPI_INT_MASK);
clk_disable(bs->clk);
clk_put(bs->clk);
platform_set_drvdata(pdev, 0);
return 0;
}
static int bcm63xx_spi_suspend(struct device *dev)
{
struct spi_master *master =
platform_get_drvdata(to_platform_device(dev));
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
clk_disable(bs->clk);
return 0;
}
static int bcm63xx_spi_resume(struct device *dev)
{
struct spi_master *master =
platform_get_drvdata(to_platform_device(dev));
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
clk_enable(bs->clk);
return 0;
}
