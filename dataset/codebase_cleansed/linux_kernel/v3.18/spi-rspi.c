static void rspi_write8(const struct rspi_data *rspi, u8 data, u16 offset)
{
iowrite8(data, rspi->addr + offset);
}
static void rspi_write16(const struct rspi_data *rspi, u16 data, u16 offset)
{
iowrite16(data, rspi->addr + offset);
}
static void rspi_write32(const struct rspi_data *rspi, u32 data, u16 offset)
{
iowrite32(data, rspi->addr + offset);
}
static u8 rspi_read8(const struct rspi_data *rspi, u16 offset)
{
return ioread8(rspi->addr + offset);
}
static u16 rspi_read16(const struct rspi_data *rspi, u16 offset)
{
return ioread16(rspi->addr + offset);
}
static void rspi_write_data(const struct rspi_data *rspi, u16 data)
{
if (rspi->byte_access)
rspi_write8(rspi, data, RSPI_SPDR);
else
rspi_write16(rspi, data, RSPI_SPDR);
}
static u16 rspi_read_data(const struct rspi_data *rspi)
{
if (rspi->byte_access)
return rspi_read8(rspi, RSPI_SPDR);
else
return rspi_read16(rspi, RSPI_SPDR);
}
static int rspi_set_config_register(struct rspi_data *rspi, int access_size)
{
int spbr;
rspi_write8(rspi, rspi->sppcr, RSPI_SPPCR);
spbr = DIV_ROUND_UP(clk_get_rate(rspi->clk),
2 * rspi->max_speed_hz) - 1;
rspi_write8(rspi, clamp(spbr, 0, 255), RSPI_SPBR);
rspi_write8(rspi, 0, RSPI_SPDCR);
rspi->byte_access = 0;
rspi_write8(rspi, 0x00, RSPI_SPCKD);
rspi_write8(rspi, 0x00, RSPI_SSLND);
rspi_write8(rspi, 0x00, RSPI_SPND);
rspi_write8(rspi, 0x00, RSPI_SPCR2);
rspi->spcmd |= SPCMD_SPB_8_TO_16(access_size);
rspi_write16(rspi, rspi->spcmd, RSPI_SPCMD0);
rspi_write8(rspi, SPCR_MSTR, RSPI_SPCR);
return 0;
}
static int rspi_rz_set_config_register(struct rspi_data *rspi, int access_size)
{
int spbr;
rspi_write8(rspi, rspi->sppcr, RSPI_SPPCR);
spbr = DIV_ROUND_UP(clk_get_rate(rspi->clk),
2 * rspi->max_speed_hz) - 1;
rspi_write8(rspi, clamp(spbr, 0, 255), RSPI_SPBR);
rspi_write8(rspi, SPDCR_SPLBYTE, RSPI_SPDCR);
rspi->byte_access = 1;
rspi_write8(rspi, 0x00, RSPI_SPCKD);
rspi_write8(rspi, 0x00, RSPI_SSLND);
rspi_write8(rspi, 0x00, RSPI_SPND);
rspi->spcmd |= SPCMD_SPB_8_TO_16(access_size);
rspi_write16(rspi, rspi->spcmd, RSPI_SPCMD0);
rspi_write8(rspi, SPCR_MSTR, RSPI_SPCR);
return 0;
}
static int qspi_set_config_register(struct rspi_data *rspi, int access_size)
{
int spbr;
rspi_write8(rspi, rspi->sppcr, RSPI_SPPCR);
spbr = DIV_ROUND_UP(clk_get_rate(rspi->clk), 2 * rspi->max_speed_hz);
rspi_write8(rspi, clamp(spbr, 0, 255), RSPI_SPBR);
rspi_write8(rspi, 0, RSPI_SPDCR);
rspi->byte_access = 1;
rspi_write8(rspi, 0x00, RSPI_SPCKD);
rspi_write8(rspi, 0x00, RSPI_SSLND);
rspi_write8(rspi, 0x00, RSPI_SPND);
if (access_size == 8)
rspi->spcmd |= SPCMD_SPB_8BIT;
else if (access_size == 16)
rspi->spcmd |= SPCMD_SPB_16BIT;
else
rspi->spcmd |= SPCMD_SPB_32BIT;
rspi->spcmd |= SPCMD_SCKDEN | SPCMD_SLNDEN | SPCMD_SPNDEN;
rspi_write32(rspi, 0, QSPI_SPBMUL0);
rspi_write8(rspi, SPBFCR_TXRST | SPBFCR_RXRST, QSPI_SPBFCR);
rspi_write8(rspi, 0x00, QSPI_SPBFCR);
rspi_write16(rspi, rspi->spcmd, RSPI_SPCMD0);
rspi_write8(rspi, SPCR_SPE | SPCR_MSTR, RSPI_SPCR);
return 0;
}
static void rspi_enable_irq(const struct rspi_data *rspi, u8 enable)
{
rspi_write8(rspi, rspi_read8(rspi, RSPI_SPCR) | enable, RSPI_SPCR);
}
static void rspi_disable_irq(const struct rspi_data *rspi, u8 disable)
{
rspi_write8(rspi, rspi_read8(rspi, RSPI_SPCR) & ~disable, RSPI_SPCR);
}
static int rspi_wait_for_interrupt(struct rspi_data *rspi, u8 wait_mask,
u8 enable_bit)
{
int ret;
rspi->spsr = rspi_read8(rspi, RSPI_SPSR);
if (rspi->spsr & wait_mask)
return 0;
rspi_enable_irq(rspi, enable_bit);
ret = wait_event_timeout(rspi->wait, rspi->spsr & wait_mask, HZ);
if (ret == 0 && !(rspi->spsr & wait_mask))
return -ETIMEDOUT;
return 0;
}
static inline int rspi_wait_for_tx_empty(struct rspi_data *rspi)
{
return rspi_wait_for_interrupt(rspi, SPSR_SPTEF, SPCR_SPTIE);
}
static inline int rspi_wait_for_rx_full(struct rspi_data *rspi)
{
return rspi_wait_for_interrupt(rspi, SPSR_SPRF, SPCR_SPRIE);
}
static int rspi_data_out(struct rspi_data *rspi, u8 data)
{
int error = rspi_wait_for_tx_empty(rspi);
if (error < 0) {
dev_err(&rspi->master->dev, "transmit timeout\n");
return error;
}
rspi_write_data(rspi, data);
return 0;
}
static int rspi_data_in(struct rspi_data *rspi)
{
int error;
u8 data;
error = rspi_wait_for_rx_full(rspi);
if (error < 0) {
dev_err(&rspi->master->dev, "receive timeout\n");
return error;
}
data = rspi_read_data(rspi);
return data;
}
static int rspi_pio_transfer(struct rspi_data *rspi, const u8 *tx, u8 *rx,
unsigned int n)
{
while (n-- > 0) {
if (tx) {
int ret = rspi_data_out(rspi, *tx++);
if (ret < 0)
return ret;
}
if (rx) {
int ret = rspi_data_in(rspi);
if (ret < 0)
return ret;
*rx++ = ret;
}
}
return 0;
}
static void rspi_dma_complete(void *arg)
{
struct rspi_data *rspi = arg;
rspi->dma_callbacked = 1;
wake_up_interruptible(&rspi->wait);
}
static int rspi_dma_transfer(struct rspi_data *rspi, struct sg_table *tx,
struct sg_table *rx)
{
struct dma_async_tx_descriptor *desc_tx = NULL, *desc_rx = NULL;
u8 irq_mask = 0;
unsigned int other_irq = 0;
dma_cookie_t cookie;
int ret;
if (rx) {
desc_rx = dmaengine_prep_slave_sg(rspi->master->dma_rx,
rx->sgl, rx->nents, DMA_FROM_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc_rx) {
ret = -EAGAIN;
goto no_dma_rx;
}
desc_rx->callback = rspi_dma_complete;
desc_rx->callback_param = rspi;
cookie = dmaengine_submit(desc_rx);
if (dma_submit_error(cookie)) {
ret = cookie;
goto no_dma_rx;
}
irq_mask |= SPCR_SPRIE;
}
if (tx) {
desc_tx = dmaengine_prep_slave_sg(rspi->master->dma_tx,
tx->sgl, tx->nents, DMA_TO_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc_tx) {
ret = -EAGAIN;
goto no_dma_tx;
}
if (rx) {
desc_tx->callback = NULL;
} else {
desc_tx->callback = rspi_dma_complete;
desc_tx->callback_param = rspi;
}
cookie = dmaengine_submit(desc_tx);
if (dma_submit_error(cookie)) {
ret = cookie;
goto no_dma_tx;
}
irq_mask |= SPCR_SPTIE;
}
if (tx)
disable_irq(other_irq = rspi->tx_irq);
if (rx && rspi->rx_irq != other_irq)
disable_irq(rspi->rx_irq);
rspi_enable_irq(rspi, irq_mask);
rspi->dma_callbacked = 0;
if (rx)
dma_async_issue_pending(rspi->master->dma_rx);
if (tx)
dma_async_issue_pending(rspi->master->dma_tx);
ret = wait_event_interruptible_timeout(rspi->wait,
rspi->dma_callbacked, HZ);
if (ret > 0 && rspi->dma_callbacked)
ret = 0;
else if (!ret) {
dev_err(&rspi->master->dev, "DMA timeout\n");
ret = -ETIMEDOUT;
if (tx)
dmaengine_terminate_all(rspi->master->dma_tx);
if (rx)
dmaengine_terminate_all(rspi->master->dma_rx);
}
rspi_disable_irq(rspi, irq_mask);
if (tx)
enable_irq(rspi->tx_irq);
if (rx && rspi->rx_irq != other_irq)
enable_irq(rspi->rx_irq);
return ret;
no_dma_tx:
if (rx)
dmaengine_terminate_all(rspi->master->dma_rx);
no_dma_rx:
if (ret == -EAGAIN) {
pr_warn_once("%s %s: DMA not available, falling back to PIO\n",
dev_driver_string(&rspi->master->dev),
dev_name(&rspi->master->dev));
}
return ret;
}
static void rspi_receive_init(const struct rspi_data *rspi)
{
u8 spsr;
spsr = rspi_read8(rspi, RSPI_SPSR);
if (spsr & SPSR_SPRF)
rspi_read_data(rspi);
if (spsr & SPSR_OVRF)
rspi_write8(rspi, rspi_read8(rspi, RSPI_SPSR) & ~SPSR_OVRF,
RSPI_SPSR);
}
static void rspi_rz_receive_init(const struct rspi_data *rspi)
{
rspi_receive_init(rspi);
rspi_write8(rspi, SPBFCR_TXRST | SPBFCR_RXRST, RSPI_SPBFCR);
rspi_write8(rspi, 0, RSPI_SPBFCR);
}
static void qspi_receive_init(const struct rspi_data *rspi)
{
u8 spsr;
spsr = rspi_read8(rspi, RSPI_SPSR);
if (spsr & SPSR_SPRF)
rspi_read_data(rspi);
rspi_write8(rspi, SPBFCR_TXRST | SPBFCR_RXRST, QSPI_SPBFCR);
rspi_write8(rspi, 0, QSPI_SPBFCR);
}
static bool __rspi_can_dma(const struct rspi_data *rspi,
const struct spi_transfer *xfer)
{
return xfer->len > rspi->ops->fifo_size;
}
static bool rspi_can_dma(struct spi_master *master, struct spi_device *spi,
struct spi_transfer *xfer)
{
struct rspi_data *rspi = spi_master_get_devdata(master);
return __rspi_can_dma(rspi, xfer);
}
static int rspi_common_transfer(struct rspi_data *rspi,
struct spi_transfer *xfer)
{
int ret;
if (rspi->master->can_dma && __rspi_can_dma(rspi, xfer)) {
ret = rspi_dma_transfer(rspi, &xfer->tx_sg,
xfer->rx_buf ? &xfer->rx_sg : NULL);
if (ret != -EAGAIN)
return ret;
}
ret = rspi_pio_transfer(rspi, xfer->tx_buf, xfer->rx_buf, xfer->len);
if (ret < 0)
return ret;
rspi_wait_for_tx_empty(rspi);
return 0;
}
static int rspi_transfer_one(struct spi_master *master, struct spi_device *spi,
struct spi_transfer *xfer)
{
struct rspi_data *rspi = spi_master_get_devdata(master);
u8 spcr;
spcr = rspi_read8(rspi, RSPI_SPCR);
if (xfer->rx_buf) {
rspi_receive_init(rspi);
spcr &= ~SPCR_TXMD;
} else {
spcr |= SPCR_TXMD;
}
rspi_write8(rspi, spcr, RSPI_SPCR);
return rspi_common_transfer(rspi, xfer);
}
static int rspi_rz_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct rspi_data *rspi = spi_master_get_devdata(master);
rspi_rz_receive_init(rspi);
return rspi_common_transfer(rspi, xfer);
}
static int qspi_transfer_out_in(struct rspi_data *rspi,
struct spi_transfer *xfer)
{
qspi_receive_init(rspi);
return rspi_common_transfer(rspi, xfer);
}
static int qspi_transfer_out(struct rspi_data *rspi, struct spi_transfer *xfer)
{
int ret;
if (rspi->master->can_dma && __rspi_can_dma(rspi, xfer)) {
ret = rspi_dma_transfer(rspi, &xfer->tx_sg, NULL);
if (ret != -EAGAIN)
return ret;
}
ret = rspi_pio_transfer(rspi, xfer->tx_buf, NULL, xfer->len);
if (ret < 0)
return ret;
rspi_wait_for_tx_empty(rspi);
return 0;
}
static int qspi_transfer_in(struct rspi_data *rspi, struct spi_transfer *xfer)
{
if (rspi->master->can_dma && __rspi_can_dma(rspi, xfer)) {
int ret = rspi_dma_transfer(rspi, NULL, &xfer->rx_sg);
if (ret != -EAGAIN)
return ret;
}
return rspi_pio_transfer(rspi, NULL, xfer->rx_buf, xfer->len);
}
static int qspi_transfer_one(struct spi_master *master, struct spi_device *spi,
struct spi_transfer *xfer)
{
struct rspi_data *rspi = spi_master_get_devdata(master);
if (spi->mode & SPI_LOOP) {
return qspi_transfer_out_in(rspi, xfer);
} else if (xfer->tx_nbits > SPI_NBITS_SINGLE) {
return qspi_transfer_out(rspi, xfer);
} else if (xfer->rx_nbits > SPI_NBITS_SINGLE) {
return qspi_transfer_in(rspi, xfer);
} else {
return qspi_transfer_out_in(rspi, xfer);
}
}
static int rspi_setup(struct spi_device *spi)
{
struct rspi_data *rspi = spi_master_get_devdata(spi->master);
rspi->max_speed_hz = spi->max_speed_hz;
rspi->spcmd = SPCMD_SSLKP;
if (spi->mode & SPI_CPOL)
rspi->spcmd |= SPCMD_CPOL;
if (spi->mode & SPI_CPHA)
rspi->spcmd |= SPCMD_CPHA;
rspi->sppcr = 0;
if (spi->mode & SPI_LOOP)
rspi->sppcr |= SPPCR_SPLP;
set_config_register(rspi, 8);
return 0;
}
static u16 qspi_transfer_mode(const struct spi_transfer *xfer)
{
if (xfer->tx_buf)
switch (xfer->tx_nbits) {
case SPI_NBITS_QUAD:
return SPCMD_SPIMOD_QUAD;
case SPI_NBITS_DUAL:
return SPCMD_SPIMOD_DUAL;
default:
return 0;
}
if (xfer->rx_buf)
switch (xfer->rx_nbits) {
case SPI_NBITS_QUAD:
return SPCMD_SPIMOD_QUAD | SPCMD_SPRW;
case SPI_NBITS_DUAL:
return SPCMD_SPIMOD_DUAL | SPCMD_SPRW;
default:
return 0;
}
return 0;
}
static int qspi_setup_sequencer(struct rspi_data *rspi,
const struct spi_message *msg)
{
const struct spi_transfer *xfer;
unsigned int i = 0, len = 0;
u16 current_mode = 0xffff, mode;
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
mode = qspi_transfer_mode(xfer);
if (mode == current_mode) {
len += xfer->len;
continue;
}
if (i) {
rspi_write32(rspi, len, QSPI_SPBMUL(i - 1));
}
if (i >= QSPI_NUM_SPCMD) {
dev_err(&msg->spi->dev,
"Too many different transfer modes");
return -EINVAL;
}
rspi_write16(rspi, rspi->spcmd | mode, RSPI_SPCMD(i));
current_mode = mode;
len = xfer->len;
i++;
}
if (i) {
rspi_write32(rspi, len, QSPI_SPBMUL(i - 1));
rspi_write8(rspi, i - 1, RSPI_SPSCR);
}
return 0;
}
static int rspi_prepare_message(struct spi_master *master,
struct spi_message *msg)
{
struct rspi_data *rspi = spi_master_get_devdata(master);
int ret;
if (msg->spi->mode &
(SPI_TX_DUAL | SPI_TX_QUAD | SPI_RX_DUAL | SPI_RX_QUAD)) {
ret = qspi_setup_sequencer(rspi, msg);
if (ret < 0)
return ret;
}
rspi_write8(rspi, rspi_read8(rspi, RSPI_SPCR) | SPCR_SPE, RSPI_SPCR);
return 0;
}
static int rspi_unprepare_message(struct spi_master *master,
struct spi_message *msg)
{
struct rspi_data *rspi = spi_master_get_devdata(master);
rspi_write8(rspi, rspi_read8(rspi, RSPI_SPCR) & ~SPCR_SPE, RSPI_SPCR);
rspi_write16(rspi, rspi->spcmd, RSPI_SPCMD0);
rspi_write8(rspi, 0, RSPI_SPSCR);
return 0;
}
static irqreturn_t rspi_irq_mux(int irq, void *_sr)
{
struct rspi_data *rspi = _sr;
u8 spsr;
irqreturn_t ret = IRQ_NONE;
u8 disable_irq = 0;
rspi->spsr = spsr = rspi_read8(rspi, RSPI_SPSR);
if (spsr & SPSR_SPRF)
disable_irq |= SPCR_SPRIE;
if (spsr & SPSR_SPTEF)
disable_irq |= SPCR_SPTIE;
if (disable_irq) {
ret = IRQ_HANDLED;
rspi_disable_irq(rspi, disable_irq);
wake_up(&rspi->wait);
}
return ret;
}
static irqreturn_t rspi_irq_rx(int irq, void *_sr)
{
struct rspi_data *rspi = _sr;
u8 spsr;
rspi->spsr = spsr = rspi_read8(rspi, RSPI_SPSR);
if (spsr & SPSR_SPRF) {
rspi_disable_irq(rspi, SPCR_SPRIE);
wake_up(&rspi->wait);
return IRQ_HANDLED;
}
return 0;
}
static irqreturn_t rspi_irq_tx(int irq, void *_sr)
{
struct rspi_data *rspi = _sr;
u8 spsr;
rspi->spsr = spsr = rspi_read8(rspi, RSPI_SPSR);
if (spsr & SPSR_SPTEF) {
rspi_disable_irq(rspi, SPCR_SPTIE);
wake_up(&rspi->wait);
return IRQ_HANDLED;
}
return 0;
}
static struct dma_chan *rspi_request_dma_chan(struct device *dev,
enum dma_transfer_direction dir,
unsigned int id,
dma_addr_t port_addr)
{
dma_cap_mask_t mask;
struct dma_chan *chan;
struct dma_slave_config cfg;
int ret;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
chan = dma_request_slave_channel_compat(mask, shdma_chan_filter,
(void *)(unsigned long)id, dev,
dir == DMA_MEM_TO_DEV ? "tx" : "rx");
if (!chan) {
dev_warn(dev, "dma_request_slave_channel_compat failed\n");
return NULL;
}
memset(&cfg, 0, sizeof(cfg));
cfg.slave_id = id;
cfg.direction = dir;
if (dir == DMA_MEM_TO_DEV) {
cfg.dst_addr = port_addr;
cfg.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
} else {
cfg.src_addr = port_addr;
cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
}
ret = dmaengine_slave_config(chan, &cfg);
if (ret) {
dev_warn(dev, "dmaengine_slave_config failed %d\n", ret);
dma_release_channel(chan);
return NULL;
}
return chan;
}
static int rspi_request_dma(struct device *dev, struct spi_master *master,
const struct resource *res)
{
const struct rspi_plat_data *rspi_pd = dev_get_platdata(dev);
unsigned int dma_tx_id, dma_rx_id;
if (dev->of_node) {
dma_tx_id = 0;
dma_rx_id = 0;
} else if (rspi_pd && rspi_pd->dma_tx_id && rspi_pd->dma_rx_id) {
dma_tx_id = rspi_pd->dma_tx_id;
dma_rx_id = rspi_pd->dma_rx_id;
} else {
return 0;
}
master->dma_tx = rspi_request_dma_chan(dev, DMA_MEM_TO_DEV, dma_tx_id,
res->start + RSPI_SPDR);
if (!master->dma_tx)
return -ENODEV;
master->dma_rx = rspi_request_dma_chan(dev, DMA_DEV_TO_MEM, dma_rx_id,
res->start + RSPI_SPDR);
if (!master->dma_rx) {
dma_release_channel(master->dma_tx);
master->dma_tx = NULL;
return -ENODEV;
}
master->can_dma = rspi_can_dma;
dev_info(dev, "DMA available");
return 0;
}
static void rspi_release_dma(struct spi_master *master)
{
if (master->dma_tx)
dma_release_channel(master->dma_tx);
if (master->dma_rx)
dma_release_channel(master->dma_rx);
}
static int rspi_remove(struct platform_device *pdev)
{
struct rspi_data *rspi = platform_get_drvdata(pdev);
rspi_release_dma(rspi->master);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int rspi_parse_dt(struct device *dev, struct spi_master *master)
{
u32 num_cs;
int error;
error = of_property_read_u32(dev->of_node, "num-cs", &num_cs);
if (error) {
dev_err(dev, "of_property_read_u32 num-cs failed %d\n", error);
return error;
}
master->num_chipselect = num_cs;
return 0;
}
static inline int rspi_parse_dt(struct device *dev, struct spi_master *master)
{
return -EINVAL;
}
static int rspi_request_irq(struct device *dev, unsigned int irq,
irq_handler_t handler, const char *suffix,
void *dev_id)
{
const char *name = devm_kasprintf(dev, GFP_KERNEL, "%s:%s",
dev_name(dev), suffix);
if (!name)
return -ENOMEM;
return devm_request_irq(dev, irq, handler, 0, name, dev_id);
}
static int rspi_probe(struct platform_device *pdev)
{
struct resource *res;
struct spi_master *master;
struct rspi_data *rspi;
int ret;
const struct of_device_id *of_id;
const struct rspi_plat_data *rspi_pd;
const struct spi_ops *ops;
master = spi_alloc_master(&pdev->dev, sizeof(struct rspi_data));
if (master == NULL) {
dev_err(&pdev->dev, "spi_alloc_master error.\n");
return -ENOMEM;
}
of_id = of_match_device(rspi_of_match, &pdev->dev);
if (of_id) {
ops = of_id->data;
ret = rspi_parse_dt(&pdev->dev, master);
if (ret)
goto error1;
} else {
ops = (struct spi_ops *)pdev->id_entry->driver_data;
rspi_pd = dev_get_platdata(&pdev->dev);
if (rspi_pd && rspi_pd->num_chipselect)
master->num_chipselect = rspi_pd->num_chipselect;
else
master->num_chipselect = 2;
}
if (!ops->set_config_register) {
dev_err(&pdev->dev, "there is no set_config_register\n");
ret = -ENODEV;
goto error1;
}
rspi = spi_master_get_devdata(master);
platform_set_drvdata(pdev, rspi);
rspi->ops = ops;
rspi->master = master;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rspi->addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rspi->addr)) {
ret = PTR_ERR(rspi->addr);
goto error1;
}
rspi->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(rspi->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
ret = PTR_ERR(rspi->clk);
goto error1;
}
pm_runtime_enable(&pdev->dev);
init_waitqueue_head(&rspi->wait);
master->bus_num = pdev->id;
master->setup = rspi_setup;
master->auto_runtime_pm = true;
master->transfer_one = ops->transfer_one;
master->prepare_message = rspi_prepare_message;
master->unprepare_message = rspi_unprepare_message;
master->mode_bits = ops->mode_bits;
master->flags = ops->flags;
master->dev.of_node = pdev->dev.of_node;
ret = platform_get_irq_byname(pdev, "rx");
if (ret < 0) {
ret = platform_get_irq_byname(pdev, "mux");
if (ret < 0)
ret = platform_get_irq(pdev, 0);
if (ret >= 0)
rspi->rx_irq = rspi->tx_irq = ret;
} else {
rspi->rx_irq = ret;
ret = platform_get_irq_byname(pdev, "tx");
if (ret >= 0)
rspi->tx_irq = ret;
}
if (ret < 0) {
dev_err(&pdev->dev, "platform_get_irq error\n");
goto error2;
}
if (rspi->rx_irq == rspi->tx_irq) {
ret = rspi_request_irq(&pdev->dev, rspi->rx_irq, rspi_irq_mux,
"mux", rspi);
} else {
ret = rspi_request_irq(&pdev->dev, rspi->rx_irq, rspi_irq_rx,
"rx", rspi);
if (!ret)
ret = rspi_request_irq(&pdev->dev, rspi->tx_irq,
rspi_irq_tx, "tx", rspi);
}
if (ret < 0) {
dev_err(&pdev->dev, "request_irq error\n");
goto error2;
}
ret = rspi_request_dma(&pdev->dev, master, res);
if (ret < 0)
dev_warn(&pdev->dev, "DMA not available, using PIO\n");
ret = devm_spi_register_master(&pdev->dev, master);
if (ret < 0) {
dev_err(&pdev->dev, "spi_register_master error.\n");
goto error3;
}
dev_info(&pdev->dev, "probed\n");
return 0;
error3:
rspi_release_dma(master);
error2:
pm_runtime_disable(&pdev->dev);
error1:
spi_master_put(master);
return ret;
}
