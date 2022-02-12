static int mxs_spi_setup_transfer(struct spi_device *dev,
struct spi_transfer *t)
{
struct mxs_spi *spi = spi_master_get_devdata(dev->master);
struct mxs_ssp *ssp = &spi->ssp;
uint8_t bits_per_word;
uint32_t hz = 0;
bits_per_word = dev->bits_per_word;
if (t && t->bits_per_word)
bits_per_word = t->bits_per_word;
if (bits_per_word != 8) {
dev_err(&dev->dev, "%s, unsupported bits_per_word=%d\n",
__func__, bits_per_word);
return -EINVAL;
}
hz = dev->max_speed_hz;
if (t && t->speed_hz)
hz = min(hz, t->speed_hz);
if (hz == 0) {
dev_err(&dev->dev, "Cannot continue with zero clock\n");
return -EINVAL;
}
mxs_ssp_set_clk_rate(ssp, hz);
writel(BF_SSP_CTRL1_SSP_MODE(BV_SSP_CTRL1_SSP_MODE__SPI) |
BF_SSP_CTRL1_WORD_LENGTH
(BV_SSP_CTRL1_WORD_LENGTH__EIGHT_BITS) |
((dev->mode & SPI_CPOL) ? BM_SSP_CTRL1_POLARITY : 0) |
((dev->mode & SPI_CPHA) ? BM_SSP_CTRL1_PHASE : 0),
ssp->base + HW_SSP_CTRL1(ssp));
writel(0x0, ssp->base + HW_SSP_CMD0);
writel(0x0, ssp->base + HW_SSP_CMD1);
return 0;
}
static int mxs_spi_setup(struct spi_device *dev)
{
int err = 0;
if (!dev->bits_per_word)
dev->bits_per_word = 8;
if (dev->mode & ~(SPI_CPOL | SPI_CPHA))
return -EINVAL;
err = mxs_spi_setup_transfer(dev, NULL);
if (err) {
dev_err(&dev->dev,
"Failed to setup transfer, error = %d\n", err);
}
return err;
}
static uint32_t mxs_spi_cs_to_reg(unsigned cs)
{
uint32_t select = 0;
if (cs & 1)
select |= BM_SSP_CTRL0_WAIT_FOR_CMD;
if (cs & 2)
select |= BM_SSP_CTRL0_WAIT_FOR_IRQ;
return select;
}
static void mxs_spi_set_cs(struct mxs_spi *spi, unsigned cs)
{
const uint32_t mask =
BM_SSP_CTRL0_WAIT_FOR_CMD | BM_SSP_CTRL0_WAIT_FOR_IRQ;
uint32_t select;
struct mxs_ssp *ssp = &spi->ssp;
writel(mask, ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_CLR);
select = mxs_spi_cs_to_reg(cs);
writel(select, ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_SET);
}
static inline void mxs_spi_enable(struct mxs_spi *spi)
{
struct mxs_ssp *ssp = &spi->ssp;
writel(BM_SSP_CTRL0_LOCK_CS,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_SET);
writel(BM_SSP_CTRL0_IGNORE_CRC,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_CLR);
}
static inline void mxs_spi_disable(struct mxs_spi *spi)
{
struct mxs_ssp *ssp = &spi->ssp;
writel(BM_SSP_CTRL0_LOCK_CS,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_CLR);
writel(BM_SSP_CTRL0_IGNORE_CRC,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_SET);
}
static int mxs_ssp_wait(struct mxs_spi *spi, int offset, int mask, bool set)
{
const unsigned long timeout = jiffies + msecs_to_jiffies(SSP_TIMEOUT);
struct mxs_ssp *ssp = &spi->ssp;
uint32_t reg;
do {
reg = readl_relaxed(ssp->base + offset);
if (!set)
reg = ~reg;
reg &= mask;
if (reg == mask)
return 0;
} while (time_before(jiffies, timeout));
return -ETIMEDOUT;
}
static void mxs_ssp_dma_irq_callback(void *param)
{
struct mxs_spi *spi = param;
complete(&spi->c);
}
static irqreturn_t mxs_ssp_irq_handler(int irq, void *dev_id)
{
struct mxs_ssp *ssp = dev_id;
dev_err(ssp->dev, "%s[%i] CTRL1=%08x STATUS=%08x\n",
__func__, __LINE__,
readl(ssp->base + HW_SSP_CTRL1(ssp)),
readl(ssp->base + HW_SSP_STATUS(ssp)));
return IRQ_HANDLED;
}
static int mxs_spi_txrx_dma(struct mxs_spi *spi, int cs,
unsigned char *buf, int len,
int *first, int *last, int write)
{
struct mxs_ssp *ssp = &spi->ssp;
struct dma_async_tx_descriptor *desc = NULL;
const bool vmalloced_buf = is_vmalloc_addr(buf);
const int desc_len = vmalloced_buf ? PAGE_SIZE : SG_MAXLEN;
const int sgs = DIV_ROUND_UP(len, desc_len);
int sg_count;
int min, ret;
uint32_t ctrl0;
struct page *vm_page;
void *sg_buf;
struct {
uint32_t pio[4];
struct scatterlist sg;
} *dma_xfer;
if (!len)
return -EINVAL;
dma_xfer = kzalloc(sizeof(*dma_xfer) * sgs, GFP_KERNEL);
if (!dma_xfer)
return -ENOMEM;
INIT_COMPLETION(spi->c);
ctrl0 = readl(ssp->base + HW_SSP_CTRL0);
ctrl0 |= BM_SSP_CTRL0_DATA_XFER | mxs_spi_cs_to_reg(cs);
if (*first)
ctrl0 |= BM_SSP_CTRL0_LOCK_CS;
if (!write)
ctrl0 |= BM_SSP_CTRL0_READ;
for (sg_count = 0; sg_count < sgs; sg_count++) {
min = min(len, desc_len);
if ((sg_count + 1 == sgs) && *last)
ctrl0 |= BM_SSP_CTRL0_IGNORE_CRC;
if (ssp->devid == IMX23_SSP)
ctrl0 |= min;
dma_xfer[sg_count].pio[0] = ctrl0;
dma_xfer[sg_count].pio[3] = min;
if (vmalloced_buf) {
vm_page = vmalloc_to_page(buf);
if (!vm_page) {
ret = -ENOMEM;
goto err_vmalloc;
}
sg_buf = page_address(vm_page) +
((size_t)buf & ~PAGE_MASK);
} else {
sg_buf = buf;
}
sg_init_one(&dma_xfer[sg_count].sg, sg_buf, min);
ret = dma_map_sg(ssp->dev, &dma_xfer[sg_count].sg, 1,
write ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
len -= min;
buf += min;
desc = dmaengine_prep_slave_sg(ssp->dmach,
(struct scatterlist *)dma_xfer[sg_count].pio,
(ssp->devid == IMX23_SSP) ? 1 : 4,
DMA_TRANS_NONE,
sg_count ? DMA_PREP_INTERRUPT : 0);
if (!desc) {
dev_err(ssp->dev,
"Failed to get PIO reg. write descriptor.\n");
ret = -EINVAL;
goto err_mapped;
}
desc = dmaengine_prep_slave_sg(ssp->dmach,
&dma_xfer[sg_count].sg, 1,
write ? DMA_MEM_TO_DEV : DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(ssp->dev,
"Failed to get DMA data write descriptor.\n");
ret = -EINVAL;
goto err_mapped;
}
}
desc->callback = mxs_ssp_dma_irq_callback;
desc->callback_param = spi;
dmaengine_submit(desc);
dma_async_issue_pending(ssp->dmach);
ret = wait_for_completion_timeout(&spi->c,
msecs_to_jiffies(SSP_TIMEOUT));
if (!ret) {
dev_err(ssp->dev, "DMA transfer timeout\n");
ret = -ETIMEDOUT;
dmaengine_terminate_all(ssp->dmach);
goto err_vmalloc;
}
ret = 0;
err_vmalloc:
while (--sg_count >= 0) {
err_mapped:
dma_unmap_sg(ssp->dev, &dma_xfer[sg_count].sg, 1,
write ? DMA_TO_DEVICE : DMA_FROM_DEVICE);
}
kfree(dma_xfer);
return ret;
}
static int mxs_spi_txrx_pio(struct mxs_spi *spi, int cs,
unsigned char *buf, int len,
int *first, int *last, int write)
{
struct mxs_ssp *ssp = &spi->ssp;
if (*first)
mxs_spi_enable(spi);
mxs_spi_set_cs(spi, cs);
while (len--) {
if (*last && len == 0)
mxs_spi_disable(spi);
if (ssp->devid == IMX23_SSP) {
writel(BM_SSP_CTRL0_XFER_COUNT,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_CLR);
writel(1,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_SET);
} else {
writel(1, ssp->base + HW_SSP_XFER_SIZE);
}
if (write)
writel(BM_SSP_CTRL0_READ,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_CLR);
else
writel(BM_SSP_CTRL0_READ,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_SET);
writel(BM_SSP_CTRL0_RUN,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_SET);
if (mxs_ssp_wait(spi, HW_SSP_CTRL0, BM_SSP_CTRL0_RUN, 1))
return -ETIMEDOUT;
if (write)
writel(*buf, ssp->base + HW_SSP_DATA(ssp));
writel(BM_SSP_CTRL0_DATA_XFER,
ssp->base + HW_SSP_CTRL0 + STMP_OFFSET_REG_SET);
if (!write) {
if (mxs_ssp_wait(spi, HW_SSP_STATUS(ssp),
BM_SSP_STATUS_FIFO_EMPTY, 0))
return -ETIMEDOUT;
*buf = (readl(ssp->base + HW_SSP_DATA(ssp)) & 0xff);
}
if (mxs_ssp_wait(spi, HW_SSP_CTRL0, BM_SSP_CTRL0_RUN, 0))
return -ETIMEDOUT;
buf++;
}
if (len <= 0)
return 0;
return -ETIMEDOUT;
}
static int mxs_spi_transfer_one(struct spi_master *master,
struct spi_message *m)
{
struct mxs_spi *spi = spi_master_get_devdata(master);
struct mxs_ssp *ssp = &spi->ssp;
int first, last;
struct spi_transfer *t, *tmp_t;
int status = 0;
int cs;
first = last = 0;
cs = m->spi->chip_select;
list_for_each_entry_safe(t, tmp_t, &m->transfers, transfer_list) {
status = mxs_spi_setup_transfer(m->spi, t);
if (status)
break;
if (&t->transfer_list == m->transfers.next)
first = 1;
if (&t->transfer_list == m->transfers.prev)
last = 1;
if ((t->rx_buf && t->tx_buf) || (t->rx_dma && t->tx_dma)) {
dev_err(ssp->dev,
"Cannot send and receive simultaneously\n");
status = -EINVAL;
break;
}
if (t->len < 32) {
writel(BM_SSP_CTRL1_DMA_ENABLE,
ssp->base + HW_SSP_CTRL1(ssp) +
STMP_OFFSET_REG_CLR);
if (t->tx_buf)
status = mxs_spi_txrx_pio(spi, cs,
(void *)t->tx_buf,
t->len, &first, &last, 1);
if (t->rx_buf)
status = mxs_spi_txrx_pio(spi, cs,
t->rx_buf, t->len,
&first, &last, 0);
} else {
writel(BM_SSP_CTRL1_DMA_ENABLE,
ssp->base + HW_SSP_CTRL1(ssp) +
STMP_OFFSET_REG_SET);
if (t->tx_buf)
status = mxs_spi_txrx_dma(spi, cs,
(void *)t->tx_buf, t->len,
&first, &last, 1);
if (t->rx_buf)
status = mxs_spi_txrx_dma(spi, cs,
t->rx_buf, t->len,
&first, &last, 0);
}
if (status) {
stmp_reset_block(ssp->base);
break;
}
m->actual_length += t->len;
first = last = 0;
}
m->status = status;
spi_finalize_current_message(master);
return status;
}
static bool mxs_ssp_dma_filter(struct dma_chan *chan, void *param)
{
struct mxs_ssp *ssp = param;
if (!mxs_dma_is_apbh(chan))
return false;
if (chan->chan_id != ssp->dma_channel)
return false;
chan->private = &ssp->dma_data;
return true;
}
static int mxs_spi_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(mxs_spi_dt_ids, &pdev->dev);
struct device_node *np = pdev->dev.of_node;
struct spi_master *master;
struct mxs_spi *spi;
struct mxs_ssp *ssp;
struct resource *iores, *dmares;
struct pinctrl *pinctrl;
struct clk *clk;
void __iomem *base;
int devid, dma_channel, clk_freq;
int ret = 0, irq_err, irq_dma;
dma_cap_mask_t mask;
const int clk_freq_default = 160000000;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq_err = platform_get_irq(pdev, 0);
irq_dma = platform_get_irq(pdev, 1);
if (!iores || irq_err < 0 || irq_dma < 0)
return -EINVAL;
base = devm_request_and_ioremap(&pdev->dev, iores);
if (!base)
return -EADDRNOTAVAIL;
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl))
return PTR_ERR(pinctrl);
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
if (np) {
devid = (enum mxs_ssp_id) of_id->data;
ret = of_property_read_u32(np, "fsl,ssp-dma-channel",
&dma_channel);
if (ret) {
dev_err(&pdev->dev,
"Failed to get DMA channel\n");
return -EINVAL;
}
ret = of_property_read_u32(np, "clock-frequency",
&clk_freq);
if (ret)
clk_freq = clk_freq_default;
} else {
dmares = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!dmares)
return -EINVAL;
devid = pdev->id_entry->driver_data;
dma_channel = dmares->start;
clk_freq = clk_freq_default;
}
master = spi_alloc_master(&pdev->dev, sizeof(*spi));
if (!master)
return -ENOMEM;
master->transfer_one_message = mxs_spi_transfer_one;
master->setup = mxs_spi_setup;
master->mode_bits = SPI_CPOL | SPI_CPHA;
master->num_chipselect = 3;
master->dev.of_node = np;
master->flags = SPI_MASTER_HALF_DUPLEX;
spi = spi_master_get_devdata(master);
ssp = &spi->ssp;
ssp->dev = &pdev->dev;
ssp->clk = clk;
ssp->base = base;
ssp->devid = devid;
ssp->dma_channel = dma_channel;
init_completion(&spi->c);
ret = devm_request_irq(&pdev->dev, irq_err, mxs_ssp_irq_handler, 0,
DRIVER_NAME, ssp);
if (ret)
goto out_master_free;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
ssp->dma_data.chan_irq = irq_dma;
ssp->dmach = dma_request_channel(mask, mxs_ssp_dma_filter, ssp);
if (!ssp->dmach) {
dev_err(ssp->dev, "Failed to request DMA\n");
goto out_master_free;
}
clk_prepare_enable(ssp->clk);
clk_set_rate(ssp->clk, clk_freq);
ssp->clk_rate = clk_get_rate(ssp->clk) / 1000;
stmp_reset_block(ssp->base);
platform_set_drvdata(pdev, master);
ret = spi_register_master(master);
if (ret) {
dev_err(&pdev->dev, "Cannot register SPI master, %d\n", ret);
goto out_free_dma;
}
return 0;
out_free_dma:
dma_release_channel(ssp->dmach);
clk_disable_unprepare(ssp->clk);
out_master_free:
spi_master_put(master);
return ret;
}
static int mxs_spi_remove(struct platform_device *pdev)
{
struct spi_master *master;
struct mxs_spi *spi;
struct mxs_ssp *ssp;
master = spi_master_get(platform_get_drvdata(pdev));
spi = spi_master_get_devdata(master);
ssp = &spi->ssp;
spi_unregister_master(master);
dma_release_channel(ssp->dmach);
clk_disable_unprepare(ssp->clk);
spi_master_put(master);
return 0;
}
