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
spbr = clk_get_rate(rspi->clk) / (2 * rspi->max_speed_hz) - 1;
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
spbr = clk_get_rate(rspi->clk) / (2 * rspi->max_speed_hz) - 1;
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
spbr = clk_get_rate(rspi->clk) / (2 * rspi->max_speed_hz);
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
static int rspi_data_out(struct rspi_data *rspi, u8 data)
{
if (rspi_wait_for_interrupt(rspi, SPSR_SPTEF, SPCR_SPTIE) < 0) {
dev_err(&rspi->master->dev, "transmit timeout\n");
return -ETIMEDOUT;
}
rspi_write_data(rspi, data);
return 0;
}
static int rspi_data_in(struct rspi_data *rspi)
{
u8 data;
if (rspi_wait_for_interrupt(rspi, SPSR_SPRF, SPCR_SPRIE) < 0) {
dev_err(&rspi->master->dev, "receive timeout\n");
return -ETIMEDOUT;
}
data = rspi_read_data(rspi);
return data;
}
static int rspi_data_out_in(struct rspi_data *rspi, u8 data)
{
int ret;
ret = rspi_data_out(rspi, data);
if (ret < 0)
return ret;
return rspi_data_in(rspi);
}
static void rspi_dma_complete(void *arg)
{
struct rspi_data *rspi = arg;
rspi->dma_callbacked = 1;
wake_up_interruptible(&rspi->wait);
}
static int rspi_dma_map_sg(struct scatterlist *sg, const void *buf,
unsigned len, struct dma_chan *chan,
enum dma_transfer_direction dir)
{
sg_init_table(sg, 1);
sg_set_buf(sg, buf, len);
sg_dma_len(sg) = len;
return dma_map_sg(chan->device->dev, sg, 1, dir);
}
static void rspi_dma_unmap_sg(struct scatterlist *sg, struct dma_chan *chan,
enum dma_transfer_direction dir)
{
dma_unmap_sg(chan->device->dev, sg, 1, dir);
}
static void rspi_memory_to_8bit(void *buf, const void *data, unsigned len)
{
u16 *dst = buf;
const u8 *src = data;
while (len) {
*dst++ = (u16)(*src++);
len--;
}
}
static void rspi_memory_from_8bit(void *buf, const void *data, unsigned len)
{
u8 *dst = buf;
const u16 *src = data;
while (len) {
*dst++ = (u8)*src++;
len--;
}
}
static int rspi_send_dma(struct rspi_data *rspi, struct spi_transfer *t)
{
struct scatterlist sg;
const void *buf = NULL;
struct dma_async_tx_descriptor *desc;
unsigned int len;
int ret = 0;
if (rspi->dma_width_16bit) {
void *tmp;
len = t->len * 2;
tmp = kmalloc(len, GFP_KERNEL);
if (!tmp)
return -ENOMEM;
rspi_memory_to_8bit(tmp, t->tx_buf, t->len);
buf = tmp;
} else {
len = t->len;
buf = t->tx_buf;
}
if (!rspi_dma_map_sg(&sg, buf, len, rspi->chan_tx, DMA_TO_DEVICE)) {
ret = -EFAULT;
goto end_nomap;
}
desc = dmaengine_prep_slave_sg(rspi->chan_tx, &sg, 1, DMA_TO_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
ret = -EIO;
goto end;
}
disable_irq(rspi->tx_irq);
rspi_write8(rspi, rspi_read8(rspi, RSPI_SPCR) | SPCR_TXMD, RSPI_SPCR);
rspi_enable_irq(rspi, SPCR_SPTIE);
rspi->dma_callbacked = 0;
desc->callback = rspi_dma_complete;
desc->callback_param = rspi;
dmaengine_submit(desc);
dma_async_issue_pending(rspi->chan_tx);
ret = wait_event_interruptible_timeout(rspi->wait,
rspi->dma_callbacked, HZ);
if (ret > 0 && rspi->dma_callbacked)
ret = 0;
else if (!ret)
ret = -ETIMEDOUT;
rspi_disable_irq(rspi, SPCR_SPTIE);
enable_irq(rspi->tx_irq);
end:
rspi_dma_unmap_sg(&sg, rspi->chan_tx, DMA_TO_DEVICE);
end_nomap:
if (rspi->dma_width_16bit)
kfree(buf);
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
static int rspi_receive_dma(struct rspi_data *rspi, struct spi_transfer *t)
{
struct scatterlist sg, sg_dummy;
void *dummy = NULL, *rx_buf = NULL;
struct dma_async_tx_descriptor *desc, *desc_dummy;
unsigned int len;
int ret = 0;
if (rspi->dma_width_16bit) {
len = t->len * 2;
rx_buf = kmalloc(len, GFP_KERNEL);
if (!rx_buf)
return -ENOMEM;
} else {
len = t->len;
rx_buf = t->rx_buf;
}
dummy = kzalloc(len, GFP_KERNEL);
if (!dummy) {
ret = -ENOMEM;
goto end_nomap;
}
if (!rspi_dma_map_sg(&sg_dummy, dummy, len, rspi->chan_tx,
DMA_TO_DEVICE)) {
ret = -EFAULT;
goto end_nomap;
}
desc_dummy = dmaengine_prep_slave_sg(rspi->chan_tx, &sg_dummy, 1,
DMA_TO_DEVICE, DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc_dummy) {
ret = -EIO;
goto end_dummy_mapped;
}
if (!rspi_dma_map_sg(&sg, rx_buf, len, rspi->chan_rx,
DMA_FROM_DEVICE)) {
ret = -EFAULT;
goto end_dummy_mapped;
}
desc = dmaengine_prep_slave_sg(rspi->chan_rx, &sg, 1, DMA_FROM_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
ret = -EIO;
goto end;
}
rspi_receive_init(rspi);
disable_irq(rspi->tx_irq);
if (rspi->rx_irq != rspi->tx_irq)
disable_irq(rspi->rx_irq);
rspi_write8(rspi, rspi_read8(rspi, RSPI_SPCR) & ~SPCR_TXMD, RSPI_SPCR);
rspi_enable_irq(rspi, SPCR_SPTIE | SPCR_SPRIE);
rspi->dma_callbacked = 0;
desc->callback = rspi_dma_complete;
desc->callback_param = rspi;
dmaengine_submit(desc);
dma_async_issue_pending(rspi->chan_rx);
desc_dummy->callback = NULL;
dmaengine_submit(desc_dummy);
dma_async_issue_pending(rspi->chan_tx);
ret = wait_event_interruptible_timeout(rspi->wait,
rspi->dma_callbacked, HZ);
if (ret > 0 && rspi->dma_callbacked)
ret = 0;
else if (!ret)
ret = -ETIMEDOUT;
rspi_disable_irq(rspi, SPCR_SPTIE | SPCR_SPRIE);
enable_irq(rspi->tx_irq);
if (rspi->rx_irq != rspi->tx_irq)
enable_irq(rspi->rx_irq);
end:
rspi_dma_unmap_sg(&sg, rspi->chan_rx, DMA_FROM_DEVICE);
end_dummy_mapped:
rspi_dma_unmap_sg(&sg_dummy, rspi->chan_tx, DMA_TO_DEVICE);
end_nomap:
if (rspi->dma_width_16bit) {
if (!ret)
rspi_memory_from_8bit(t->rx_buf, rx_buf, t->len);
kfree(rx_buf);
}
kfree(dummy);
return ret;
}
static int rspi_is_dma(const struct rspi_data *rspi, struct spi_transfer *t)
{
if (t->tx_buf && rspi->chan_tx)
return 1;
if (t->rx_buf && rspi->chan_tx && rspi->chan_rx)
return 1;
return 0;
}
static int rspi_transfer_out_in(struct rspi_data *rspi,
struct spi_transfer *xfer)
{
int remain = xfer->len, ret;
const u8 *tx_buf = xfer->tx_buf;
u8 *rx_buf = xfer->rx_buf;
u8 spcr, data;
rspi_receive_init(rspi);
spcr = rspi_read8(rspi, RSPI_SPCR);
if (rx_buf)
spcr &= ~SPCR_TXMD;
else
spcr |= SPCR_TXMD;
rspi_write8(rspi, spcr, RSPI_SPCR);
while (remain > 0) {
data = tx_buf ? *tx_buf++ : DUMMY_DATA;
ret = rspi_data_out(rspi, data);
if (ret < 0)
return ret;
if (rx_buf) {
ret = rspi_data_in(rspi);
if (ret < 0)
return ret;
*rx_buf++ = ret;
}
remain--;
}
rspi_wait_for_interrupt(rspi, SPSR_SPTEF, SPCR_SPTIE);
return 0;
}
static int rspi_transfer_one(struct spi_master *master, struct spi_device *spi,
struct spi_transfer *xfer)
{
struct rspi_data *rspi = spi_master_get_devdata(master);
int ret;
if (!rspi_is_dma(rspi, xfer))
return rspi_transfer_out_in(rspi, xfer);
if (xfer->tx_buf) {
ret = rspi_send_dma(rspi, xfer);
if (ret < 0)
return ret;
}
if (xfer->rx_buf)
return rspi_receive_dma(rspi, xfer);
return 0;
}
static int rspi_rz_transfer_out_in(struct rspi_data *rspi,
struct spi_transfer *xfer)
{
int remain = xfer->len, ret;
const u8 *tx_buf = xfer->tx_buf;
u8 *rx_buf = xfer->rx_buf;
u8 data;
rspi_rz_receive_init(rspi);
while (remain > 0) {
data = tx_buf ? *tx_buf++ : DUMMY_DATA;
ret = rspi_data_out_in(rspi, data);
if (ret < 0)
return ret;
if (rx_buf)
*rx_buf++ = ret;
remain--;
}
rspi_wait_for_interrupt(rspi, SPSR_SPTEF, SPCR_SPTIE);
return 0;
}
static int rspi_rz_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct rspi_data *rspi = spi_master_get_devdata(master);
return rspi_rz_transfer_out_in(rspi, xfer);
}
static int qspi_transfer_out_in(struct rspi_data *rspi,
struct spi_transfer *xfer)
{
int remain = xfer->len, ret;
const u8 *tx_buf = xfer->tx_buf;
u8 *rx_buf = xfer->rx_buf;
u8 data;
qspi_receive_init(rspi);
while (remain > 0) {
data = tx_buf ? *tx_buf++ : DUMMY_DATA;
ret = rspi_data_out_in(rspi, data);
if (ret < 0)
return ret;
if (rx_buf)
*rx_buf++ = ret;
remain--;
}
rspi_wait_for_interrupt(rspi, SPSR_SPTEF, SPCR_SPTIE);
return 0;
}
static int qspi_transfer_out(struct rspi_data *rspi, struct spi_transfer *xfer)
{
const u8 *buf = xfer->tx_buf;
unsigned int i;
int ret;
for (i = 0; i < xfer->len; i++) {
ret = rspi_data_out(rspi, *buf++);
if (ret < 0)
return ret;
}
rspi_wait_for_interrupt(rspi, SPSR_SPTEF, SPCR_SPTIE);
return 0;
}
static int qspi_transfer_in(struct rspi_data *rspi, struct spi_transfer *xfer)
{
u8 *buf = xfer->rx_buf;
unsigned int i;
int ret;
for (i = 0; i < xfer->len; i++) {
ret = rspi_data_in(rspi);
if (ret < 0)
return ret;
*buf++ = ret;
}
return 0;
}
static int qspi_transfer_one(struct spi_master *master, struct spi_device *spi,
struct spi_transfer *xfer)
{
struct rspi_data *rspi = spi_master_get_devdata(master);
if (spi->mode & SPI_LOOP) {
return qspi_transfer_out_in(rspi, xfer);
} else if (xfer->tx_buf && xfer->tx_nbits > SPI_NBITS_SINGLE) {
return qspi_transfer_out(rspi, xfer);
} else if (xfer->rx_buf && xfer->rx_nbits > SPI_NBITS_SINGLE) {
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
static int rspi_request_dma(struct rspi_data *rspi,
struct platform_device *pdev)
{
const struct rspi_plat_data *rspi_pd = dev_get_platdata(&pdev->dev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dma_cap_mask_t mask;
struct dma_slave_config cfg;
int ret;
if (!res || !rspi_pd)
return 0;
rspi->dma_width_16bit = rspi_pd->dma_width_16bit;
if (rspi_pd->dma_rx_id && rspi_pd->dma_tx_id) {
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
rspi->chan_rx = dma_request_channel(mask, shdma_chan_filter,
(void *)rspi_pd->dma_rx_id);
if (rspi->chan_rx) {
cfg.slave_id = rspi_pd->dma_rx_id;
cfg.direction = DMA_DEV_TO_MEM;
cfg.dst_addr = 0;
cfg.src_addr = res->start + RSPI_SPDR;
ret = dmaengine_slave_config(rspi->chan_rx, &cfg);
if (!ret)
dev_info(&pdev->dev, "Use DMA when rx.\n");
else
return ret;
}
}
if (rspi_pd->dma_tx_id) {
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
rspi->chan_tx = dma_request_channel(mask, shdma_chan_filter,
(void *)rspi_pd->dma_tx_id);
if (rspi->chan_tx) {
cfg.slave_id = rspi_pd->dma_tx_id;
cfg.direction = DMA_MEM_TO_DEV;
cfg.dst_addr = res->start + RSPI_SPDR;
cfg.src_addr = 0;
ret = dmaengine_slave_config(rspi->chan_tx, &cfg);
if (!ret)
dev_info(&pdev->dev, "Use DMA when tx\n");
else
return ret;
}
}
return 0;
}
static void rspi_release_dma(struct rspi_data *rspi)
{
if (rspi->chan_tx)
dma_release_channel(rspi->chan_tx);
if (rspi->chan_rx)
dma_release_channel(rspi->chan_rx);
}
static int rspi_remove(struct platform_device *pdev)
{
struct rspi_data *rspi = platform_get_drvdata(pdev);
rspi_release_dma(rspi);
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
const char *base = dev_name(dev);
size_t len = strlen(base) + strlen(suffix) + 2;
char *name = devm_kzalloc(dev, len, GFP_KERNEL);
if (!name)
return -ENOMEM;
snprintf(name, len, "%s:%s", base, suffix);
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
};
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
ret = rspi_request_dma(rspi, pdev);
if (ret < 0) {
dev_err(&pdev->dev, "rspi_request_dma failed.\n");
goto error3;
}
ret = devm_spi_register_master(&pdev->dev, master);
if (ret < 0) {
dev_err(&pdev->dev, "spi_register_master error.\n");
goto error3;
}
dev_info(&pdev->dev, "probed\n");
return 0;
error3:
rspi_release_dma(rspi);
error2:
pm_runtime_disable(&pdev->dev);
error1:
spi_master_put(master);
return ret;
}
