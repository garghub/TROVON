static inline void pic32_spi_enable(struct pic32_spi *pic32s)
{
writel(CTRL_ON | CTRL_SIDL, &pic32s->regs->ctrl_set);
}
static inline void pic32_spi_disable(struct pic32_spi *pic32s)
{
writel(CTRL_ON | CTRL_SIDL, &pic32s->regs->ctrl_clr);
ndelay(20);
}
static void pic32_spi_set_clk_rate(struct pic32_spi *pic32s, u32 spi_ck)
{
u32 div;
div = DIV_ROUND_CLOSEST(clk_get_rate(pic32s->clk), 2 * spi_ck) - 1;
writel(div & BAUD_MASK, &pic32s->regs->baud);
}
static inline u32 pic32_rx_fifo_level(struct pic32_spi *pic32s)
{
u32 sr = readl(&pic32s->regs->status);
return (sr >> STAT_RF_LVL_SHIFT) & STAT_RF_LVL_MASK;
}
static inline u32 pic32_tx_fifo_level(struct pic32_spi *pic32s)
{
u32 sr = readl(&pic32s->regs->status);
return (sr >> STAT_TF_LVL_SHIFT) & STAT_TF_LVL_MASK;
}
static u32 pic32_tx_max(struct pic32_spi *pic32s, int n_bytes)
{
u32 tx_left, tx_room, rxtx_gap;
tx_left = (pic32s->tx_end - pic32s->tx) / n_bytes;
tx_room = pic32s->fifo_n_elm - pic32_tx_fifo_level(pic32s);
rxtx_gap = ((pic32s->rx_end - pic32s->rx) -
(pic32s->tx_end - pic32s->tx)) / n_bytes;
return min3(tx_left, tx_room, (u32)(pic32s->fifo_n_elm - rxtx_gap));
}
static u32 pic32_rx_max(struct pic32_spi *pic32s, int n_bytes)
{
u32 rx_left = (pic32s->rx_end - pic32s->rx) / n_bytes;
return min_t(u32, rx_left, pic32_rx_fifo_level(pic32s));
}
static void pic32_err_stop(struct pic32_spi *pic32s, const char *msg)
{
disable_irq_nosync(pic32s->fault_irq);
disable_irq_nosync(pic32s->rx_irq);
disable_irq_nosync(pic32s->tx_irq);
dev_err(&pic32s->master->dev, "%s\n", msg);
if (pic32s->master->cur_msg)
pic32s->master->cur_msg->status = -EIO;
complete(&pic32s->xfer_done);
}
static irqreturn_t pic32_spi_fault_irq(int irq, void *dev_id)
{
struct pic32_spi *pic32s = dev_id;
u32 status;
status = readl(&pic32s->regs->status);
if (status & (STAT_RX_OV | STAT_TX_UR)) {
writel(STAT_RX_OV, &pic32s->regs->status_clr);
writel(STAT_TX_UR, &pic32s->regs->status_clr);
pic32_err_stop(pic32s, "err_irq: fifo ov/ur-run\n");
return IRQ_HANDLED;
}
if (status & STAT_FRM_ERR) {
pic32_err_stop(pic32s, "err_irq: frame error");
return IRQ_HANDLED;
}
if (!pic32s->master->cur_msg) {
pic32_err_stop(pic32s, "err_irq: no mesg");
return IRQ_NONE;
}
return IRQ_NONE;
}
static irqreturn_t pic32_spi_rx_irq(int irq, void *dev_id)
{
struct pic32_spi *pic32s = dev_id;
pic32s->rx_fifo(pic32s);
if (pic32s->rx_end == pic32s->rx) {
disable_irq_nosync(pic32s->fault_irq);
disable_irq_nosync(pic32s->rx_irq);
complete(&pic32s->xfer_done);
}
return IRQ_HANDLED;
}
static irqreturn_t pic32_spi_tx_irq(int irq, void *dev_id)
{
struct pic32_spi *pic32s = dev_id;
pic32s->tx_fifo(pic32s);
if (pic32s->tx_end == pic32s->tx)
disable_irq_nosync(pic32s->tx_irq);
return IRQ_HANDLED;
}
static void pic32_spi_dma_rx_notify(void *data)
{
struct pic32_spi *pic32s = data;
complete(&pic32s->xfer_done);
}
static int pic32_spi_dma_transfer(struct pic32_spi *pic32s,
struct spi_transfer *xfer)
{
struct spi_master *master = pic32s->master;
struct dma_async_tx_descriptor *desc_rx;
struct dma_async_tx_descriptor *desc_tx;
dma_cookie_t cookie;
int ret;
if (!master->dma_rx || !master->dma_tx)
return -ENODEV;
desc_rx = dmaengine_prep_slave_sg(master->dma_rx,
xfer->rx_sg.sgl,
xfer->rx_sg.nents,
DMA_FROM_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc_rx) {
ret = -EINVAL;
goto err_dma;
}
desc_tx = dmaengine_prep_slave_sg(master->dma_tx,
xfer->tx_sg.sgl,
xfer->tx_sg.nents,
DMA_TO_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc_tx) {
ret = -EINVAL;
goto err_dma;
}
desc_rx->callback = pic32_spi_dma_rx_notify;
desc_rx->callback_param = pic32s;
cookie = dmaengine_submit(desc_rx);
ret = dma_submit_error(cookie);
if (ret)
goto err_dma;
cookie = dmaengine_submit(desc_tx);
ret = dma_submit_error(cookie);
if (ret)
goto err_dma_tx;
dma_async_issue_pending(master->dma_rx);
dma_async_issue_pending(master->dma_tx);
return 0;
err_dma_tx:
dmaengine_terminate_all(master->dma_rx);
err_dma:
return ret;
}
static int pic32_spi_dma_config(struct pic32_spi *pic32s, u32 dma_width)
{
int buf_offset = offsetof(struct pic32_spi_regs, buf);
struct spi_master *master = pic32s->master;
struct dma_slave_config cfg;
int ret;
cfg.device_fc = true;
cfg.src_addr = pic32s->dma_base + buf_offset;
cfg.dst_addr = pic32s->dma_base + buf_offset;
cfg.src_maxburst = pic32s->fifo_n_elm / 2;
cfg.dst_maxburst = pic32s->fifo_n_elm / 2;
cfg.src_addr_width = dma_width;
cfg.dst_addr_width = dma_width;
cfg.slave_id = pic32s->tx_irq;
cfg.direction = DMA_MEM_TO_DEV;
ret = dmaengine_slave_config(master->dma_tx, &cfg);
if (ret) {
dev_err(&master->dev, "tx channel setup failed\n");
return ret;
}
cfg.slave_id = pic32s->rx_irq;
cfg.direction = DMA_DEV_TO_MEM;
ret = dmaengine_slave_config(master->dma_rx, &cfg);
if (ret)
dev_err(&master->dev, "rx channel setup failed\n");
return ret;
}
static int pic32_spi_set_word_size(struct pic32_spi *pic32s, u8 bits_per_word)
{
enum dma_slave_buswidth dmawidth;
u32 buswidth, v;
switch (bits_per_word) {
case 8:
pic32s->rx_fifo = pic32_spi_rx_byte;
pic32s->tx_fifo = pic32_spi_tx_byte;
buswidth = PIC32_BPW_8;
dmawidth = DMA_SLAVE_BUSWIDTH_1_BYTE;
break;
case 16:
pic32s->rx_fifo = pic32_spi_rx_word;
pic32s->tx_fifo = pic32_spi_tx_word;
buswidth = PIC32_BPW_16;
dmawidth = DMA_SLAVE_BUSWIDTH_2_BYTES;
break;
case 32:
pic32s->rx_fifo = pic32_spi_rx_dword;
pic32s->tx_fifo = pic32_spi_tx_dword;
buswidth = PIC32_BPW_32;
dmawidth = DMA_SLAVE_BUSWIDTH_4_BYTES;
break;
default:
return -EINVAL;
}
pic32s->fifo_n_elm = DIV_ROUND_UP(pic32s->fifo_n_byte,
bits_per_word / 8);
v = readl(&pic32s->regs->ctrl);
v &= ~(CTRL_BPW_MASK << CTRL_BPW_SHIFT);
v |= buswidth << CTRL_BPW_SHIFT;
writel(v, &pic32s->regs->ctrl);
if (test_bit(PIC32F_DMA_PREP, &pic32s->flags))
pic32_spi_dma_config(pic32s, dmawidth);
return 0;
}
static int pic32_spi_prepare_hardware(struct spi_master *master)
{
struct pic32_spi *pic32s = spi_master_get_devdata(master);
pic32_spi_enable(pic32s);
return 0;
}
static int pic32_spi_prepare_message(struct spi_master *master,
struct spi_message *msg)
{
struct pic32_spi *pic32s = spi_master_get_devdata(master);
struct spi_device *spi = msg->spi;
u32 val;
if (pic32s->bits_per_word != spi->bits_per_word) {
pic32_spi_set_word_size(pic32s, spi->bits_per_word);
pic32s->bits_per_word = spi->bits_per_word;
}
if (pic32s->speed_hz != spi->max_speed_hz) {
pic32_spi_set_clk_rate(pic32s, spi->max_speed_hz);
pic32s->speed_hz = spi->max_speed_hz;
}
if (pic32s->mode != spi->mode) {
val = readl(&pic32s->regs->ctrl);
if (spi->mode & SPI_CPOL)
val |= CTRL_CKP;
else
val &= ~CTRL_CKP;
if (spi->mode & SPI_CPHA)
val &= ~CTRL_CKE;
else
val |= CTRL_CKE;
val |= CTRL_SMP;
writel(val, &pic32s->regs->ctrl);
pic32s->mode = spi->mode;
}
return 0;
}
static bool pic32_spi_can_dma(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct pic32_spi *pic32s = spi_master_get_devdata(master);
return (xfer->len >= PIC32_DMA_LEN_MIN) &&
test_bit(PIC32F_DMA_PREP, &pic32s->flags);
}
static int pic32_spi_one_transfer(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *transfer)
{
struct pic32_spi *pic32s;
bool dma_issued = false;
unsigned long timeout;
int ret;
pic32s = spi_master_get_devdata(master);
if (transfer->bits_per_word &&
(transfer->bits_per_word != pic32s->bits_per_word)) {
ret = pic32_spi_set_word_size(pic32s, transfer->bits_per_word);
if (ret)
return ret;
pic32s->bits_per_word = transfer->bits_per_word;
}
if (transfer->speed_hz && (transfer->speed_hz != pic32s->speed_hz)) {
pic32_spi_set_clk_rate(pic32s, transfer->speed_hz);
pic32s->speed_hz = transfer->speed_hz;
}
reinit_completion(&pic32s->xfer_done);
if (transfer->rx_sg.nents && transfer->tx_sg.nents) {
ret = pic32_spi_dma_transfer(pic32s, transfer);
if (ret) {
dev_err(&spi->dev, "dma submit error\n");
return ret;
}
dma_issued = true;
} else {
pic32s->tx = (const void *)transfer->tx_buf;
pic32s->rx = (const void *)transfer->rx_buf;
pic32s->tx_end = pic32s->tx + transfer->len;
pic32s->rx_end = pic32s->rx + transfer->len;
pic32s->len = transfer->len;
enable_irq(pic32s->fault_irq);
enable_irq(pic32s->rx_irq);
enable_irq(pic32s->tx_irq);
}
timeout = wait_for_completion_timeout(&pic32s->xfer_done, 2 * HZ);
if (timeout == 0) {
dev_err(&spi->dev, "wait error/timedout\n");
if (dma_issued) {
dmaengine_terminate_all(master->dma_rx);
dmaengine_terminate_all(master->dma_rx);
}
ret = -ETIMEDOUT;
} else {
ret = 0;
}
return ret;
}
static int pic32_spi_unprepare_message(struct spi_master *master,
struct spi_message *msg)
{
return 0;
}
static int pic32_spi_unprepare_hardware(struct spi_master *master)
{
struct pic32_spi *pic32s = spi_master_get_devdata(master);
pic32_spi_disable(pic32s);
return 0;
}
static int pic32_spi_setup(struct spi_device *spi)
{
if (!spi->max_speed_hz) {
dev_err(&spi->dev, "No max speed HZ parameter\n");
return -EINVAL;
}
if (!gpio_is_valid(spi->cs_gpio))
return -EINVAL;
gpio_direction_output(spi->cs_gpio, !(spi->mode & SPI_CS_HIGH));
return 0;
}
static void pic32_spi_cleanup(struct spi_device *spi)
{
gpio_direction_output(spi->cs_gpio, !(spi->mode & SPI_CS_HIGH));
}
static void pic32_spi_dma_prep(struct pic32_spi *pic32s, struct device *dev)
{
struct spi_master *master = pic32s->master;
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
master->dma_rx = dma_request_slave_channel_compat(mask, NULL, NULL,
dev, "spi-rx");
if (!master->dma_rx) {
dev_warn(dev, "RX channel not found.\n");
goto out_err;
}
master->dma_tx = dma_request_slave_channel_compat(mask, NULL, NULL,
dev, "spi-tx");
if (!master->dma_tx) {
dev_warn(dev, "TX channel not found.\n");
goto out_err;
}
if (pic32_spi_dma_config(pic32s, DMA_SLAVE_BUSWIDTH_1_BYTE))
goto out_err;
set_bit(PIC32F_DMA_PREP, &pic32s->flags);
return;
out_err:
if (master->dma_rx)
dma_release_channel(master->dma_rx);
if (master->dma_tx)
dma_release_channel(master->dma_tx);
}
static void pic32_spi_dma_unprep(struct pic32_spi *pic32s)
{
if (!test_bit(PIC32F_DMA_PREP, &pic32s->flags))
return;
clear_bit(PIC32F_DMA_PREP, &pic32s->flags);
if (pic32s->master->dma_rx)
dma_release_channel(pic32s->master->dma_rx);
if (pic32s->master->dma_tx)
dma_release_channel(pic32s->master->dma_tx);
}
static void pic32_spi_hw_init(struct pic32_spi *pic32s)
{
u32 ctrl;
pic32_spi_disable(pic32s);
ctrl = readl(&pic32s->regs->ctrl);
ctrl |= CTRL_ENHBUF;
pic32s->fifo_n_byte = 16;
ctrl &= ~CTRL_FRMEN;
ctrl |= CTRL_MSTEN;
ctrl &= ~(0x3 << CTRL_TX_INT_SHIFT);
ctrl |= (TX_FIFO_HALF_EMPTY << CTRL_TX_INT_SHIFT);
ctrl &= ~(0x3 << CTRL_RX_INT_SHIFT);
ctrl |= (RX_FIFO_NOT_EMPTY << CTRL_RX_INT_SHIFT);
ctrl &= ~CTRL_MCLKSEL;
ctrl &= ~CTRL_MSSEN;
writel(ctrl, &pic32s->regs->ctrl);
ctrl = CTRL2_TX_UR_EN | CTRL2_RX_OV_EN | CTRL2_FRM_ERR_EN;
writel(ctrl, &pic32s->regs->ctrl2_set);
}
static int pic32_spi_hw_probe(struct platform_device *pdev,
struct pic32_spi *pic32s)
{
struct resource *mem;
int ret;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pic32s->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(pic32s->regs))
return PTR_ERR(pic32s->regs);
pic32s->dma_base = mem->start;
pic32s->fault_irq = platform_get_irq_byname(pdev, "fault");
if (pic32s->fault_irq < 0) {
dev_err(&pdev->dev, "fault-irq not found\n");
return pic32s->fault_irq;
}
pic32s->rx_irq = platform_get_irq_byname(pdev, "rx");
if (pic32s->rx_irq < 0) {
dev_err(&pdev->dev, "rx-irq not found\n");
return pic32s->rx_irq;
}
pic32s->tx_irq = platform_get_irq_byname(pdev, "tx");
if (pic32s->tx_irq < 0) {
dev_err(&pdev->dev, "tx-irq not found\n");
return pic32s->tx_irq;
}
pic32s->clk = devm_clk_get(&pdev->dev, "mck0");
if (IS_ERR(pic32s->clk)) {
dev_err(&pdev->dev, "clk not found\n");
ret = PTR_ERR(pic32s->clk);
goto err_unmap_mem;
}
ret = clk_prepare_enable(pic32s->clk);
if (ret)
goto err_unmap_mem;
pic32_spi_hw_init(pic32s);
return 0;
err_unmap_mem:
dev_err(&pdev->dev, "%s failed, err %d\n", __func__, ret);
return ret;
}
static int pic32_spi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct pic32_spi *pic32s;
int ret;
master = spi_alloc_master(&pdev->dev, sizeof(*pic32s));
if (!master)
return -ENOMEM;
pic32s = spi_master_get_devdata(master);
pic32s->master = master;
ret = pic32_spi_hw_probe(pdev, pic32s);
if (ret)
goto err_master;
master->dev.of_node = of_node_get(pdev->dev.of_node);
master->mode_bits = SPI_MODE_3 | SPI_MODE_0 | SPI_CS_HIGH;
master->num_chipselect = 1;
master->max_speed_hz = clk_get_rate(pic32s->clk);
master->setup = pic32_spi_setup;
master->cleanup = pic32_spi_cleanup;
master->flags = SPI_MASTER_MUST_TX | SPI_MASTER_MUST_RX;
master->bits_per_word_mask = SPI_BPW_MASK(8) | SPI_BPW_MASK(16) |
SPI_BPW_MASK(32);
master->transfer_one = pic32_spi_one_transfer;
master->prepare_message = pic32_spi_prepare_message;
master->unprepare_message = pic32_spi_unprepare_message;
master->prepare_transfer_hardware = pic32_spi_prepare_hardware;
master->unprepare_transfer_hardware = pic32_spi_unprepare_hardware;
pic32_spi_dma_prep(pic32s, &pdev->dev);
if (test_bit(PIC32F_DMA_PREP, &pic32s->flags))
master->can_dma = pic32_spi_can_dma;
init_completion(&pic32s->xfer_done);
pic32s->mode = -1;
irq_set_status_flags(pic32s->fault_irq, IRQ_NOAUTOEN);
ret = devm_request_irq(&pdev->dev, pic32s->fault_irq,
pic32_spi_fault_irq, IRQF_NO_THREAD,
dev_name(&pdev->dev), pic32s);
if (ret < 0) {
dev_err(&pdev->dev, "request fault-irq %d\n", pic32s->rx_irq);
goto err_bailout;
}
irq_set_status_flags(pic32s->rx_irq, IRQ_NOAUTOEN);
ret = devm_request_irq(&pdev->dev, pic32s->rx_irq,
pic32_spi_rx_irq, IRQF_NO_THREAD,
dev_name(&pdev->dev), pic32s);
if (ret < 0) {
dev_err(&pdev->dev, "request rx-irq %d\n", pic32s->rx_irq);
goto err_bailout;
}
irq_set_status_flags(pic32s->tx_irq, IRQ_NOAUTOEN);
ret = devm_request_irq(&pdev->dev, pic32s->tx_irq,
pic32_spi_tx_irq, IRQF_NO_THREAD,
dev_name(&pdev->dev), pic32s);
if (ret < 0) {
dev_err(&pdev->dev, "request tx-irq %d\n", pic32s->tx_irq);
goto err_bailout;
}
ret = devm_spi_register_master(&pdev->dev, master);
if (ret) {
dev_err(&master->dev, "failed registering spi master\n");
goto err_bailout;
}
platform_set_drvdata(pdev, pic32s);
return 0;
err_bailout:
clk_disable_unprepare(pic32s->clk);
err_master:
spi_master_put(master);
return ret;
}
static int pic32_spi_remove(struct platform_device *pdev)
{
struct pic32_spi *pic32s;
pic32s = platform_get_drvdata(pdev);
pic32_spi_disable(pic32s);
clk_disable_unprepare(pic32s->clk);
pic32_spi_dma_unprep(pic32s);
return 0;
}
