static int ep93xx_spi_calc_divisors(struct spi_master *master,
u32 rate, u8 *div_cpsr, u8 *div_scr)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
unsigned long spi_clk_rate = clk_get_rate(espi->clk);
int cpsr, scr;
rate = clamp(rate, master->min_speed_hz, master->max_speed_hz);
for (cpsr = 2; cpsr <= 254; cpsr += 2) {
for (scr = 0; scr <= 255; scr++) {
if ((spi_clk_rate / (cpsr * (scr + 1))) <= rate) {
*div_scr = (u8)scr;
*div_cpsr = (u8)cpsr;
return 0;
}
}
}
return -EINVAL;
}
static int ep93xx_spi_chip_setup(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
u8 dss = bits_per_word_to_dss(xfer->bits_per_word);
u8 div_cpsr = 0;
u8 div_scr = 0;
u16 cr0;
int err;
err = ep93xx_spi_calc_divisors(master, xfer->speed_hz,
&div_cpsr, &div_scr);
if (err)
return err;
cr0 = div_scr << SSPCR0_SCR_SHIFT;
cr0 |= (spi->mode & (SPI_CPHA | SPI_CPOL)) << SSPCR0_MODE_SHIFT;
cr0 |= dss;
dev_dbg(&master->dev, "setup: mode %d, cpsr %d, scr %d, dss %d\n",
spi->mode, div_cpsr, div_scr, dss);
dev_dbg(&master->dev, "setup: cr0 %#x\n", cr0);
writel(div_cpsr, espi->mmio + SSPCPSR);
writel(cr0, espi->mmio + SSPCR0);
return 0;
}
static void ep93xx_do_write(struct spi_master *master)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
struct spi_transfer *xfer = master->cur_msg->state;
u32 val = 0;
if (xfer->bits_per_word > 8) {
if (xfer->tx_buf)
val = ((u16 *)xfer->tx_buf)[espi->tx];
espi->tx += 2;
} else {
if (xfer->tx_buf)
val = ((u8 *)xfer->tx_buf)[espi->tx];
espi->tx += 1;
}
writel(val, espi->mmio + SSPDR);
}
static void ep93xx_do_read(struct spi_master *master)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
struct spi_transfer *xfer = master->cur_msg->state;
u32 val;
val = readl(espi->mmio + SSPDR);
if (xfer->bits_per_word > 8) {
if (xfer->rx_buf)
((u16 *)xfer->rx_buf)[espi->rx] = val;
espi->rx += 2;
} else {
if (xfer->rx_buf)
((u8 *)xfer->rx_buf)[espi->rx] = val;
espi->rx += 1;
}
}
static int ep93xx_spi_read_write(struct spi_master *master)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
struct spi_transfer *xfer = master->cur_msg->state;
while ((readl(espi->mmio + SSPSR) & SSPSR_RNE)) {
ep93xx_do_read(master);
espi->fifo_level--;
}
while (espi->fifo_level < SPI_FIFO_SIZE && espi->tx < xfer->len) {
ep93xx_do_write(master);
espi->fifo_level++;
}
if (espi->rx == xfer->len)
return 0;
return -EINPROGRESS;
}
static struct dma_async_tx_descriptor *
ep93xx_spi_dma_prepare(struct spi_master *master,
enum dma_transfer_direction dir)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
struct spi_transfer *xfer = master->cur_msg->state;
struct dma_async_tx_descriptor *txd;
enum dma_slave_buswidth buswidth;
struct dma_slave_config conf;
struct scatterlist *sg;
struct sg_table *sgt;
struct dma_chan *chan;
const void *buf, *pbuf;
size_t len = xfer->len;
int i, ret, nents;
if (xfer->bits_per_word > 8)
buswidth = DMA_SLAVE_BUSWIDTH_2_BYTES;
else
buswidth = DMA_SLAVE_BUSWIDTH_1_BYTE;
memset(&conf, 0, sizeof(conf));
conf.direction = dir;
if (dir == DMA_DEV_TO_MEM) {
chan = espi->dma_rx;
buf = xfer->rx_buf;
sgt = &espi->rx_sgt;
conf.src_addr = espi->sspdr_phys;
conf.src_addr_width = buswidth;
} else {
chan = espi->dma_tx;
buf = xfer->tx_buf;
sgt = &espi->tx_sgt;
conf.dst_addr = espi->sspdr_phys;
conf.dst_addr_width = buswidth;
}
ret = dmaengine_slave_config(chan, &conf);
if (ret)
return ERR_PTR(ret);
nents = DIV_ROUND_UP(len, PAGE_SIZE);
if (nents != sgt->nents) {
sg_free_table(sgt);
ret = sg_alloc_table(sgt, nents, GFP_KERNEL);
if (ret)
return ERR_PTR(ret);
}
pbuf = buf;
for_each_sg(sgt->sgl, sg, sgt->nents, i) {
size_t bytes = min_t(size_t, len, PAGE_SIZE);
if (buf) {
sg_set_page(sg, virt_to_page(pbuf), bytes,
offset_in_page(pbuf));
} else {
sg_set_page(sg, virt_to_page(espi->zeropage),
bytes, 0);
}
pbuf += bytes;
len -= bytes;
}
if (WARN_ON(len)) {
dev_warn(&master->dev, "len = %zu expected 0!\n", len);
return ERR_PTR(-EINVAL);
}
nents = dma_map_sg(chan->device->dev, sgt->sgl, sgt->nents, dir);
if (!nents)
return ERR_PTR(-ENOMEM);
txd = dmaengine_prep_slave_sg(chan, sgt->sgl, nents, dir, DMA_CTRL_ACK);
if (!txd) {
dma_unmap_sg(chan->device->dev, sgt->sgl, sgt->nents, dir);
return ERR_PTR(-ENOMEM);
}
return txd;
}
static void ep93xx_spi_dma_finish(struct spi_master *master,
enum dma_transfer_direction dir)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
struct dma_chan *chan;
struct sg_table *sgt;
if (dir == DMA_DEV_TO_MEM) {
chan = espi->dma_rx;
sgt = &espi->rx_sgt;
} else {
chan = espi->dma_tx;
sgt = &espi->tx_sgt;
}
dma_unmap_sg(chan->device->dev, sgt->sgl, sgt->nents, dir);
}
static void ep93xx_spi_dma_callback(void *callback_param)
{
struct spi_master *master = callback_param;
ep93xx_spi_dma_finish(master, DMA_MEM_TO_DEV);
ep93xx_spi_dma_finish(master, DMA_DEV_TO_MEM);
spi_finalize_current_transfer(master);
}
static int ep93xx_spi_dma_transfer(struct spi_master *master)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
struct dma_async_tx_descriptor *rxd, *txd;
rxd = ep93xx_spi_dma_prepare(master, DMA_DEV_TO_MEM);
if (IS_ERR(rxd)) {
dev_err(&master->dev, "DMA RX failed: %ld\n", PTR_ERR(rxd));
return PTR_ERR(rxd);
}
txd = ep93xx_spi_dma_prepare(master, DMA_MEM_TO_DEV);
if (IS_ERR(txd)) {
ep93xx_spi_dma_finish(master, DMA_DEV_TO_MEM);
dev_err(&master->dev, "DMA TX failed: %ld\n", PTR_ERR(txd));
return PTR_ERR(txd);
}
rxd->callback = ep93xx_spi_dma_callback;
rxd->callback_param = master;
dmaengine_submit(rxd);
dmaengine_submit(txd);
dma_async_issue_pending(espi->dma_rx);
dma_async_issue_pending(espi->dma_tx);
return 1;
}
static irqreturn_t ep93xx_spi_interrupt(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct ep93xx_spi *espi = spi_master_get_devdata(master);
u32 val;
if (readl(espi->mmio + SSPIIR) & SSPIIR_RORIS) {
writel(0, espi->mmio + SSPICR);
dev_warn(&master->dev,
"receive overrun, aborting the message\n");
master->cur_msg->status = -EIO;
} else {
if (ep93xx_spi_read_write(master)) {
return IRQ_HANDLED;
}
}
val = readl(espi->mmio + SSPCR1);
val &= ~(SSPCR1_RORIE | SSPCR1_TIE | SSPCR1_RIE);
writel(val, espi->mmio + SSPCR1);
spi_finalize_current_transfer(master);
return IRQ_HANDLED;
}
static int ep93xx_spi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
u32 val;
int ret;
ret = ep93xx_spi_chip_setup(master, spi, xfer);
if (ret) {
dev_err(&master->dev, "failed to setup chip for transfer\n");
return ret;
}
master->cur_msg->state = xfer;
espi->rx = 0;
espi->tx = 0;
if (espi->dma_rx && xfer->len > SPI_FIFO_SIZE)
return ep93xx_spi_dma_transfer(master);
ep93xx_spi_read_write(master);
val = readl(espi->mmio + SSPCR1);
val |= (SSPCR1_RORIE | SSPCR1_TIE | SSPCR1_RIE);
writel(val, espi->mmio + SSPCR1);
return 1;
}
static int ep93xx_spi_prepare_message(struct spi_master *master,
struct spi_message *msg)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(SPI_TIMEOUT);
while (readl(espi->mmio + SSPSR) & SSPSR_RNE) {
if (time_after(jiffies, timeout)) {
dev_warn(&master->dev,
"timeout while flushing RX FIFO\n");
return -ETIMEDOUT;
}
readl(espi->mmio + SSPDR);
}
espi->fifo_level = 0;
return 0;
}
static int ep93xx_spi_prepare_hardware(struct spi_master *master)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
u32 val;
int ret;
ret = clk_enable(espi->clk);
if (ret)
return ret;
val = readl(espi->mmio + SSPCR1);
val |= SSPCR1_SSE;
writel(val, espi->mmio + SSPCR1);
return 0;
}
static int ep93xx_spi_unprepare_hardware(struct spi_master *master)
{
struct ep93xx_spi *espi = spi_master_get_devdata(master);
u32 val;
val = readl(espi->mmio + SSPCR1);
val &= ~SSPCR1_SSE;
writel(val, espi->mmio + SSPCR1);
clk_disable(espi->clk);
return 0;
}
static bool ep93xx_spi_dma_filter(struct dma_chan *chan, void *filter_param)
{
if (ep93xx_dma_chan_is_m2p(chan))
return false;
chan->private = filter_param;
return true;
}
static int ep93xx_spi_setup_dma(struct ep93xx_spi *espi)
{
dma_cap_mask_t mask;
int ret;
espi->zeropage = (void *)get_zeroed_page(GFP_KERNEL);
if (!espi->zeropage)
return -ENOMEM;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
espi->dma_rx_data.port = EP93XX_DMA_SSP;
espi->dma_rx_data.direction = DMA_DEV_TO_MEM;
espi->dma_rx_data.name = "ep93xx-spi-rx";
espi->dma_rx = dma_request_channel(mask, ep93xx_spi_dma_filter,
&espi->dma_rx_data);
if (!espi->dma_rx) {
ret = -ENODEV;
goto fail_free_page;
}
espi->dma_tx_data.port = EP93XX_DMA_SSP;
espi->dma_tx_data.direction = DMA_MEM_TO_DEV;
espi->dma_tx_data.name = "ep93xx-spi-tx";
espi->dma_tx = dma_request_channel(mask, ep93xx_spi_dma_filter,
&espi->dma_tx_data);
if (!espi->dma_tx) {
ret = -ENODEV;
goto fail_release_rx;
}
return 0;
fail_release_rx:
dma_release_channel(espi->dma_rx);
espi->dma_rx = NULL;
fail_free_page:
free_page((unsigned long)espi->zeropage);
return ret;
}
static void ep93xx_spi_release_dma(struct ep93xx_spi *espi)
{
if (espi->dma_rx) {
dma_release_channel(espi->dma_rx);
sg_free_table(&espi->rx_sgt);
}
if (espi->dma_tx) {
dma_release_channel(espi->dma_tx);
sg_free_table(&espi->tx_sgt);
}
if (espi->zeropage)
free_page((unsigned long)espi->zeropage);
}
static int ep93xx_spi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct ep93xx_spi_info *info;
struct ep93xx_spi *espi;
struct resource *res;
int irq;
int error;
int i;
info = dev_get_platdata(&pdev->dev);
if (!info) {
dev_err(&pdev->dev, "missing platform data\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get irq resources\n");
return -EBUSY;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "unable to get iomem resource\n");
return -ENODEV;
}
master = spi_alloc_master(&pdev->dev, sizeof(*espi));
if (!master)
return -ENOMEM;
master->prepare_transfer_hardware = ep93xx_spi_prepare_hardware;
master->unprepare_transfer_hardware = ep93xx_spi_unprepare_hardware;
master->prepare_message = ep93xx_spi_prepare_message;
master->transfer_one = ep93xx_spi_transfer_one;
master->bus_num = pdev->id;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 16);
master->num_chipselect = info->num_chipselect;
master->cs_gpios = devm_kzalloc(&master->dev,
sizeof(int) * master->num_chipselect,
GFP_KERNEL);
if (!master->cs_gpios) {
error = -ENOMEM;
goto fail_release_master;
}
for (i = 0; i < master->num_chipselect; i++) {
master->cs_gpios[i] = info->chipselect[i];
if (!gpio_is_valid(master->cs_gpios[i]))
continue;
error = devm_gpio_request_one(&pdev->dev, master->cs_gpios[i],
GPIOF_OUT_INIT_HIGH,
"ep93xx-spi");
if (error) {
dev_err(&pdev->dev, "could not request cs gpio %d\n",
master->cs_gpios[i]);
goto fail_release_master;
}
}
platform_set_drvdata(pdev, master);
espi = spi_master_get_devdata(master);
espi->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(espi->clk)) {
dev_err(&pdev->dev, "unable to get spi clock\n");
error = PTR_ERR(espi->clk);
goto fail_release_master;
}
master->max_speed_hz = clk_get_rate(espi->clk) / 2;
master->min_speed_hz = clk_get_rate(espi->clk) / (254 * 256);
espi->sspdr_phys = res->start + SSPDR;
espi->mmio = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(espi->mmio)) {
error = PTR_ERR(espi->mmio);
goto fail_release_master;
}
error = devm_request_irq(&pdev->dev, irq, ep93xx_spi_interrupt,
0, "ep93xx-spi", master);
if (error) {
dev_err(&pdev->dev, "failed to request irq\n");
goto fail_release_master;
}
if (info->use_dma && ep93xx_spi_setup_dma(espi))
dev_warn(&pdev->dev, "DMA setup failed. Falling back to PIO\n");
writel(0, espi->mmio + SSPCR1);
error = devm_spi_register_master(&pdev->dev, master);
if (error) {
dev_err(&pdev->dev, "failed to register SPI master\n");
goto fail_free_dma;
}
dev_info(&pdev->dev, "EP93xx SPI Controller at 0x%08lx irq %d\n",
(unsigned long)res->start, irq);
return 0;
fail_free_dma:
ep93xx_spi_release_dma(espi);
fail_release_master:
spi_master_put(master);
return error;
}
static int ep93xx_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct ep93xx_spi *espi = spi_master_get_devdata(master);
ep93xx_spi_release_dma(espi);
return 0;
}
