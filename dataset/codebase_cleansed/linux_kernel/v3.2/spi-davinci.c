static void davinci_spi_rx_buf_u8(u32 data, struct davinci_spi *dspi)
{
if (dspi->rx) {
u8 *rx = dspi->rx;
*rx++ = (u8)data;
dspi->rx = rx;
}
}
static void davinci_spi_rx_buf_u16(u32 data, struct davinci_spi *dspi)
{
if (dspi->rx) {
u16 *rx = dspi->rx;
*rx++ = (u16)data;
dspi->rx = rx;
}
}
static u32 davinci_spi_tx_buf_u8(struct davinci_spi *dspi)
{
u32 data = 0;
if (dspi->tx) {
const u8 *tx = dspi->tx;
data = *tx++;
dspi->tx = tx;
}
return data;
}
static u32 davinci_spi_tx_buf_u16(struct davinci_spi *dspi)
{
u32 data = 0;
if (dspi->tx) {
const u16 *tx = dspi->tx;
data = *tx++;
dspi->tx = tx;
}
return data;
}
static inline void set_io_bits(void __iomem *addr, u32 bits)
{
u32 v = ioread32(addr);
v |= bits;
iowrite32(v, addr);
}
static inline void clear_io_bits(void __iomem *addr, u32 bits)
{
u32 v = ioread32(addr);
v &= ~bits;
iowrite32(v, addr);
}
static void davinci_spi_chipselect(struct spi_device *spi, int value)
{
struct davinci_spi *dspi;
struct davinci_spi_platform_data *pdata;
u8 chip_sel = spi->chip_select;
u16 spidat1 = CS_DEFAULT;
bool gpio_chipsel = false;
dspi = spi_master_get_devdata(spi->master);
pdata = dspi->pdata;
if (pdata->chip_sel && chip_sel < pdata->num_chipselect &&
pdata->chip_sel[chip_sel] != SPI_INTERN_CS)
gpio_chipsel = true;
if (gpio_chipsel) {
if (value == BITBANG_CS_ACTIVE)
gpio_set_value(pdata->chip_sel[chip_sel], 0);
else
gpio_set_value(pdata->chip_sel[chip_sel], 1);
} else {
if (value == BITBANG_CS_ACTIVE) {
spidat1 |= SPIDAT1_CSHOLD_MASK;
spidat1 &= ~(0x1 << chip_sel);
}
iowrite16(spidat1, dspi->base + SPIDAT1 + 2);
}
}
static inline int davinci_spi_get_prescale(struct davinci_spi *dspi,
u32 max_speed_hz)
{
int ret;
ret = DIV_ROUND_UP(clk_get_rate(dspi->clk), max_speed_hz);
if (ret < 3 || ret > 256)
return -EINVAL;
return ret - 1;
}
static int davinci_spi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct davinci_spi *dspi;
struct davinci_spi_config *spicfg;
u8 bits_per_word = 0;
u32 hz = 0, spifmt = 0, prescale = 0;
dspi = spi_master_get_devdata(spi->master);
spicfg = (struct davinci_spi_config *)spi->controller_data;
if (!spicfg)
spicfg = &davinci_spi_default_cfg;
if (t) {
bits_per_word = t->bits_per_word;
hz = t->speed_hz;
}
if (!bits_per_word)
bits_per_word = spi->bits_per_word;
if (bits_per_word <= 8 && bits_per_word >= 2) {
dspi->get_rx = davinci_spi_rx_buf_u8;
dspi->get_tx = davinci_spi_tx_buf_u8;
dspi->bytes_per_word[spi->chip_select] = 1;
} else if (bits_per_word <= 16 && bits_per_word >= 2) {
dspi->get_rx = davinci_spi_rx_buf_u16;
dspi->get_tx = davinci_spi_tx_buf_u16;
dspi->bytes_per_word[spi->chip_select] = 2;
} else
return -EINVAL;
if (!hz)
hz = spi->max_speed_hz;
prescale = davinci_spi_get_prescale(dspi, hz);
if (prescale < 0)
return prescale;
spifmt = (prescale << SPIFMT_PRESCALE_SHIFT) | (bits_per_word & 0x1f);
if (spi->mode & SPI_LSB_FIRST)
spifmt |= SPIFMT_SHIFTDIR_MASK;
if (spi->mode & SPI_CPOL)
spifmt |= SPIFMT_POLARITY_MASK;
if (!(spi->mode & SPI_CPHA))
spifmt |= SPIFMT_PHASE_MASK;
if (dspi->version == SPI_VERSION_2) {
u32 delay = 0;
spifmt |= ((spicfg->wdelay << SPIFMT_WDELAY_SHIFT)
& SPIFMT_WDELAY_MASK);
if (spicfg->odd_parity)
spifmt |= SPIFMT_ODD_PARITY_MASK;
if (spicfg->parity_enable)
spifmt |= SPIFMT_PARITYENA_MASK;
if (spicfg->timer_disable) {
spifmt |= SPIFMT_DISTIMER_MASK;
} else {
delay |= (spicfg->c2tdelay << SPIDELAY_C2TDELAY_SHIFT)
& SPIDELAY_C2TDELAY_MASK;
delay |= (spicfg->t2cdelay << SPIDELAY_T2CDELAY_SHIFT)
& SPIDELAY_T2CDELAY_MASK;
}
if (spi->mode & SPI_READY) {
spifmt |= SPIFMT_WAITENA_MASK;
delay |= (spicfg->t2edelay << SPIDELAY_T2EDELAY_SHIFT)
& SPIDELAY_T2EDELAY_MASK;
delay |= (spicfg->c2edelay << SPIDELAY_C2EDELAY_SHIFT)
& SPIDELAY_C2EDELAY_MASK;
}
iowrite32(delay, dspi->base + SPIDELAY);
}
iowrite32(spifmt, dspi->base + SPIFMT0);
return 0;
}
static int davinci_spi_setup(struct spi_device *spi)
{
int retval = 0;
struct davinci_spi *dspi;
struct davinci_spi_platform_data *pdata;
dspi = spi_master_get_devdata(spi->master);
pdata = dspi->pdata;
if (!spi->bits_per_word)
spi->bits_per_word = 8;
if (!(spi->mode & SPI_NO_CS)) {
if ((pdata->chip_sel == NULL) ||
(pdata->chip_sel[spi->chip_select] == SPI_INTERN_CS))
set_io_bits(dspi->base + SPIPC0, 1 << spi->chip_select);
}
if (spi->mode & SPI_READY)
set_io_bits(dspi->base + SPIPC0, SPIPC0_SPIENA_MASK);
if (spi->mode & SPI_LOOP)
set_io_bits(dspi->base + SPIGCR1, SPIGCR1_LOOPBACK_MASK);
else
clear_io_bits(dspi->base + SPIGCR1, SPIGCR1_LOOPBACK_MASK);
return retval;
}
static int davinci_spi_check_error(struct davinci_spi *dspi, int int_status)
{
struct device *sdev = dspi->bitbang.master->dev.parent;
if (int_status & SPIFLG_TIMEOUT_MASK) {
dev_dbg(sdev, "SPI Time-out Error\n");
return -ETIMEDOUT;
}
if (int_status & SPIFLG_DESYNC_MASK) {
dev_dbg(sdev, "SPI Desynchronization Error\n");
return -EIO;
}
if (int_status & SPIFLG_BITERR_MASK) {
dev_dbg(sdev, "SPI Bit error\n");
return -EIO;
}
if (dspi->version == SPI_VERSION_2) {
if (int_status & SPIFLG_DLEN_ERR_MASK) {
dev_dbg(sdev, "SPI Data Length Error\n");
return -EIO;
}
if (int_status & SPIFLG_PARERR_MASK) {
dev_dbg(sdev, "SPI Parity Error\n");
return -EIO;
}
if (int_status & SPIFLG_OVRRUN_MASK) {
dev_dbg(sdev, "SPI Data Overrun error\n");
return -EIO;
}
if (int_status & SPIFLG_BUF_INIT_ACTIVE_MASK) {
dev_dbg(sdev, "SPI Buffer Init Active\n");
return -EBUSY;
}
}
return 0;
}
static int davinci_spi_process_events(struct davinci_spi *dspi)
{
u32 buf, status, errors = 0, spidat1;
buf = ioread32(dspi->base + SPIBUF);
if (dspi->rcount > 0 && !(buf & SPIBUF_RXEMPTY_MASK)) {
dspi->get_rx(buf & 0xFFFF, dspi);
dspi->rcount--;
}
status = ioread32(dspi->base + SPIFLG);
if (unlikely(status & SPIFLG_ERROR_MASK)) {
errors = status & SPIFLG_ERROR_MASK;
goto out;
}
if (dspi->wcount > 0 && !(buf & SPIBUF_TXFULL_MASK)) {
spidat1 = ioread32(dspi->base + SPIDAT1);
dspi->wcount--;
spidat1 &= ~0xFFFF;
spidat1 |= 0xFFFF & dspi->get_tx(dspi);
iowrite32(spidat1, dspi->base + SPIDAT1);
}
out:
return errors;
}
static void davinci_spi_dma_callback(unsigned lch, u16 status, void *data)
{
struct davinci_spi *dspi = data;
struct davinci_spi_dma *dma = &dspi->dma;
edma_stop(lch);
if (status == DMA_COMPLETE) {
if (lch == dma->rx_channel)
dspi->rcount = 0;
if (lch == dma->tx_channel)
dspi->wcount = 0;
}
if ((!dspi->wcount && !dspi->rcount) || (status != DMA_COMPLETE))
complete(&dspi->done);
}
static int davinci_spi_bufs(struct spi_device *spi, struct spi_transfer *t)
{
struct davinci_spi *dspi;
int data_type, ret;
u32 tx_data, spidat1;
u32 errors = 0;
struct davinci_spi_config *spicfg;
struct davinci_spi_platform_data *pdata;
unsigned uninitialized_var(rx_buf_count);
struct device *sdev;
dspi = spi_master_get_devdata(spi->master);
pdata = dspi->pdata;
spicfg = (struct davinci_spi_config *)spi->controller_data;
if (!spicfg)
spicfg = &davinci_spi_default_cfg;
sdev = dspi->bitbang.master->dev.parent;
data_type = dspi->bytes_per_word[spi->chip_select];
dspi->tx = t->tx_buf;
dspi->rx = t->rx_buf;
dspi->wcount = t->len / data_type;
dspi->rcount = dspi->wcount;
spidat1 = ioread32(dspi->base + SPIDAT1);
clear_io_bits(dspi->base + SPIGCR1, SPIGCR1_POWERDOWN_MASK);
set_io_bits(dspi->base + SPIGCR1, SPIGCR1_SPIENA_MASK);
INIT_COMPLETION(dspi->done);
if (spicfg->io_type == SPI_IO_TYPE_INTR)
set_io_bits(dspi->base + SPIINT, SPIINT_MASKINT);
if (spicfg->io_type != SPI_IO_TYPE_DMA) {
dspi->wcount--;
tx_data = dspi->get_tx(dspi);
spidat1 &= 0xFFFF0000;
spidat1 |= tx_data & 0xFFFF;
iowrite32(spidat1, dspi->base + SPIDAT1);
} else {
struct davinci_spi_dma *dma;
unsigned long tx_reg, rx_reg;
struct edmacc_param param;
void *rx_buf;
int b, c;
dma = &dspi->dma;
tx_reg = (unsigned long)dspi->pbase + SPIDAT1;
rx_reg = (unsigned long)dspi->pbase + SPIBUF;
if (t->tx_buf) {
t->tx_dma = dma_map_single(&spi->dev, (void *)t->tx_buf,
t->len, DMA_TO_DEVICE);
if (dma_mapping_error(&spi->dev, t->tx_dma)) {
dev_dbg(sdev, "Unable to DMA map %d bytes"
"TX buffer\n", t->len);
return -ENOMEM;
}
}
c = dspi->wcount / (SZ_64K - 1);
b = dspi->wcount - c * (SZ_64K - 1);
if (b)
c++;
else
b = SZ_64K - 1;
param.opt = TCINTEN | EDMA_TCC(dma->tx_channel);
param.src = t->tx_buf ? t->tx_dma : tx_reg;
param.a_b_cnt = b << 16 | data_type;
param.dst = tx_reg;
param.src_dst_bidx = t->tx_buf ? data_type : 0;
param.link_bcntrld = 0xffffffff;
param.src_dst_cidx = t->tx_buf ? data_type : 0;
param.ccnt = c;
edma_write_slot(dma->tx_channel, &param);
edma_link(dma->tx_channel, dma->dummy_param_slot);
if (t->rx_buf) {
rx_buf = t->rx_buf;
rx_buf_count = t->len;
} else {
rx_buf = dspi->rx_tmp_buf;
rx_buf_count = sizeof(dspi->rx_tmp_buf);
}
t->rx_dma = dma_map_single(&spi->dev, rx_buf, rx_buf_count,
DMA_FROM_DEVICE);
if (dma_mapping_error(&spi->dev, t->rx_dma)) {
dev_dbg(sdev, "Couldn't DMA map a %d bytes RX buffer\n",
rx_buf_count);
if (t->tx_buf)
dma_unmap_single(NULL, t->tx_dma, t->len,
DMA_TO_DEVICE);
return -ENOMEM;
}
param.opt = TCINTEN | EDMA_TCC(dma->rx_channel);
param.src = rx_reg;
param.a_b_cnt = b << 16 | data_type;
param.dst = t->rx_dma;
param.src_dst_bidx = (t->rx_buf ? data_type : 0) << 16;
param.link_bcntrld = 0xffffffff;
param.src_dst_cidx = (t->rx_buf ? data_type : 0) << 16;
param.ccnt = c;
edma_write_slot(dma->rx_channel, &param);
if (pdata->cshold_bug)
iowrite16(spidat1 >> 16, dspi->base + SPIDAT1 + 2);
edma_start(dma->rx_channel);
edma_start(dma->tx_channel);
set_io_bits(dspi->base + SPIINT, SPIINT_DMA_REQ_EN);
}
if (spicfg->io_type != SPI_IO_TYPE_POLL) {
wait_for_completion_interruptible(&(dspi->done));
} else {
while (dspi->rcount > 0 || dspi->wcount > 0) {
errors = davinci_spi_process_events(dspi);
if (errors)
break;
cpu_relax();
}
}
clear_io_bits(dspi->base + SPIINT, SPIINT_MASKALL);
if (spicfg->io_type == SPI_IO_TYPE_DMA) {
if (t->tx_buf)
dma_unmap_single(NULL, t->tx_dma, t->len,
DMA_TO_DEVICE);
dma_unmap_single(NULL, t->rx_dma, rx_buf_count,
DMA_FROM_DEVICE);
clear_io_bits(dspi->base + SPIINT, SPIINT_DMA_REQ_EN);
}
clear_io_bits(dspi->base + SPIGCR1, SPIGCR1_SPIENA_MASK);
set_io_bits(dspi->base + SPIGCR1, SPIGCR1_POWERDOWN_MASK);
if (errors) {
ret = davinci_spi_check_error(dspi, errors);
WARN(!ret, "%s: error reported but no error found!\n",
dev_name(&spi->dev));
return ret;
}
if (dspi->rcount != 0 || dspi->wcount != 0) {
dev_err(sdev, "SPI data transfer error\n");
return -EIO;
}
return t->len;
}
static irqreturn_t davinci_spi_irq(s32 irq, void *data)
{
struct davinci_spi *dspi = data;
int status;
status = davinci_spi_process_events(dspi);
if (unlikely(status != 0))
clear_io_bits(dspi->base + SPIINT, SPIINT_MASKINT);
if ((!dspi->rcount && !dspi->wcount) || status)
complete(&dspi->done);
return IRQ_HANDLED;
}
static int davinci_spi_request_dma(struct davinci_spi *dspi)
{
int r;
struct davinci_spi_dma *dma = &dspi->dma;
r = edma_alloc_channel(dma->rx_channel, davinci_spi_dma_callback, dspi,
dma->eventq);
if (r < 0) {
pr_err("Unable to request DMA channel for SPI RX\n");
r = -EAGAIN;
goto rx_dma_failed;
}
r = edma_alloc_channel(dma->tx_channel, davinci_spi_dma_callback, dspi,
dma->eventq);
if (r < 0) {
pr_err("Unable to request DMA channel for SPI TX\n");
r = -EAGAIN;
goto tx_dma_failed;
}
r = edma_alloc_slot(EDMA_CTLR(dma->tx_channel), EDMA_SLOT_ANY);
if (r < 0) {
pr_err("Unable to request SPI TX DMA param slot\n");
r = -EAGAIN;
goto param_failed;
}
dma->dummy_param_slot = r;
edma_link(dma->dummy_param_slot, dma->dummy_param_slot);
return 0;
param_failed:
edma_free_channel(dma->tx_channel);
tx_dma_failed:
edma_free_channel(dma->rx_channel);
rx_dma_failed:
return r;
}
static int __devinit davinci_spi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct davinci_spi *dspi;
struct davinci_spi_platform_data *pdata;
struct resource *r, *mem;
resource_size_t dma_rx_chan = SPI_NO_RESOURCE;
resource_size_t dma_tx_chan = SPI_NO_RESOURCE;
int i = 0, ret = 0;
u32 spipc0;
pdata = pdev->dev.platform_data;
if (pdata == NULL) {
ret = -ENODEV;
goto err;
}
master = spi_alloc_master(&pdev->dev, sizeof(struct davinci_spi));
if (master == NULL) {
ret = -ENOMEM;
goto err;
}
dev_set_drvdata(&pdev->dev, master);
dspi = spi_master_get_devdata(master);
if (dspi == NULL) {
ret = -ENOENT;
goto free_master;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL) {
ret = -ENOENT;
goto free_master;
}
dspi->pbase = r->start;
dspi->pdata = pdata;
mem = request_mem_region(r->start, resource_size(r), pdev->name);
if (mem == NULL) {
ret = -EBUSY;
goto free_master;
}
dspi->base = ioremap(r->start, resource_size(r));
if (dspi->base == NULL) {
ret = -ENOMEM;
goto release_region;
}
dspi->irq = platform_get_irq(pdev, 0);
if (dspi->irq <= 0) {
ret = -EINVAL;
goto unmap_io;
}
ret = request_irq(dspi->irq, davinci_spi_irq, 0, dev_name(&pdev->dev),
dspi);
if (ret)
goto unmap_io;
dspi->bitbang.master = spi_master_get(master);
if (dspi->bitbang.master == NULL) {
ret = -ENODEV;
goto irq_free;
}
dspi->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(dspi->clk)) {
ret = -ENODEV;
goto put_master;
}
clk_enable(dspi->clk);
master->bus_num = pdev->id;
master->num_chipselect = pdata->num_chipselect;
master->setup = davinci_spi_setup;
dspi->bitbang.chipselect = davinci_spi_chipselect;
dspi->bitbang.setup_transfer = davinci_spi_setup_transfer;
dspi->version = pdata->version;
dspi->bitbang.flags = SPI_NO_CS | SPI_LSB_FIRST | SPI_LOOP;
if (dspi->version == SPI_VERSION_2)
dspi->bitbang.flags |= SPI_READY;
r = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (r)
dma_rx_chan = r->start;
r = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (r)
dma_tx_chan = r->start;
dspi->bitbang.txrx_bufs = davinci_spi_bufs;
if (dma_rx_chan != SPI_NO_RESOURCE &&
dma_tx_chan != SPI_NO_RESOURCE) {
dspi->dma.rx_channel = dma_rx_chan;
dspi->dma.tx_channel = dma_tx_chan;
dspi->dma.eventq = pdata->dma_event_q;
ret = davinci_spi_request_dma(dspi);
if (ret)
goto free_clk;
dev_info(&pdev->dev, "DMA: supported\n");
dev_info(&pdev->dev, "DMA: RX channel: %d, TX channel: %d, "
"event queue: %d\n", dma_rx_chan, dma_tx_chan,
pdata->dma_event_q);
}
dspi->get_rx = davinci_spi_rx_buf_u8;
dspi->get_tx = davinci_spi_tx_buf_u8;
init_completion(&dspi->done);
iowrite32(0, dspi->base + SPIGCR0);
udelay(100);
iowrite32(1, dspi->base + SPIGCR0);
spipc0 = SPIPC0_DIFUN_MASK | SPIPC0_DOFUN_MASK | SPIPC0_CLKFUN_MASK;
iowrite32(spipc0, dspi->base + SPIPC0);
if (pdata->chip_sel) {
for (i = 0; i < pdata->num_chipselect; i++) {
if (pdata->chip_sel[i] != SPI_INTERN_CS)
gpio_direction_output(pdata->chip_sel[i], 1);
}
}
if (pdata->intr_line)
iowrite32(SPI_INTLVL_1, dspi->base + SPILVL);
else
iowrite32(SPI_INTLVL_0, dspi->base + SPILVL);
iowrite32(CS_DEFAULT, dspi->base + SPIDEF);
set_io_bits(dspi->base + SPIGCR1, SPIGCR1_CLKMOD_MASK);
set_io_bits(dspi->base + SPIGCR1, SPIGCR1_MASTER_MASK);
set_io_bits(dspi->base + SPIGCR1, SPIGCR1_POWERDOWN_MASK);
ret = spi_bitbang_start(&dspi->bitbang);
if (ret)
goto free_dma;
dev_info(&pdev->dev, "Controller at 0x%p\n", dspi->base);
return ret;
free_dma:
edma_free_channel(dspi->dma.tx_channel);
edma_free_channel(dspi->dma.rx_channel);
edma_free_slot(dspi->dma.dummy_param_slot);
free_clk:
clk_disable(dspi->clk);
clk_put(dspi->clk);
put_master:
spi_master_put(master);
irq_free:
free_irq(dspi->irq, dspi);
unmap_io:
iounmap(dspi->base);
release_region:
release_mem_region(dspi->pbase, resource_size(r));
free_master:
kfree(master);
err:
return ret;
}
static int __devexit davinci_spi_remove(struct platform_device *pdev)
{
struct davinci_spi *dspi;
struct spi_master *master;
struct resource *r;
master = dev_get_drvdata(&pdev->dev);
dspi = spi_master_get_devdata(master);
spi_bitbang_stop(&dspi->bitbang);
clk_disable(dspi->clk);
clk_put(dspi->clk);
spi_master_put(master);
free_irq(dspi->irq, dspi);
iounmap(dspi->base);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(dspi->pbase, resource_size(r));
return 0;
}
