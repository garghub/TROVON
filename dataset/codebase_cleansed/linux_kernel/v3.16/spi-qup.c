static inline bool spi_qup_is_valid_state(struct spi_qup *controller)
{
u32 opstate = readl_relaxed(controller->base + QUP_STATE);
return opstate & QUP_STATE_VALID;
}
static int spi_qup_set_state(struct spi_qup *controller, u32 state)
{
unsigned long loop;
u32 cur_state;
loop = 0;
while (!spi_qup_is_valid_state(controller)) {
usleep_range(SPI_DELAY_THRESHOLD, SPI_DELAY_THRESHOLD * 2);
if (++loop > SPI_DELAY_RETRY)
return -EIO;
}
if (loop)
dev_dbg(controller->dev, "invalid state for %ld,us %d\n",
loop, state);
cur_state = readl_relaxed(controller->base + QUP_STATE);
if (((cur_state & QUP_STATE_MASK) == QUP_STATE_PAUSE) &&
(state == QUP_STATE_RESET)) {
writel_relaxed(QUP_STATE_CLEAR, controller->base + QUP_STATE);
writel_relaxed(QUP_STATE_CLEAR, controller->base + QUP_STATE);
} else {
cur_state &= ~QUP_STATE_MASK;
cur_state |= state;
writel_relaxed(cur_state, controller->base + QUP_STATE);
}
loop = 0;
while (!spi_qup_is_valid_state(controller)) {
usleep_range(SPI_DELAY_THRESHOLD, SPI_DELAY_THRESHOLD * 2);
if (++loop > SPI_DELAY_RETRY)
return -EIO;
}
return 0;
}
static void spi_qup_fifo_read(struct spi_qup *controller,
struct spi_transfer *xfer)
{
u8 *rx_buf = xfer->rx_buf;
u32 word, state;
int idx, shift, w_size;
w_size = controller->w_size;
while (controller->rx_bytes < xfer->len) {
state = readl_relaxed(controller->base + QUP_OPERATIONAL);
if (0 == (state & QUP_OP_IN_FIFO_NOT_EMPTY))
break;
word = readl_relaxed(controller->base + QUP_INPUT_FIFO);
if (!rx_buf) {
controller->rx_bytes += w_size;
continue;
}
for (idx = 0; idx < w_size; idx++, controller->rx_bytes++) {
shift = BITS_PER_BYTE;
shift *= (w_size - idx - 1);
rx_buf[controller->rx_bytes] = word >> shift;
}
}
}
static void spi_qup_fifo_write(struct spi_qup *controller,
struct spi_transfer *xfer)
{
const u8 *tx_buf = xfer->tx_buf;
u32 word, state, data;
int idx, w_size;
w_size = controller->w_size;
while (controller->tx_bytes < xfer->len) {
state = readl_relaxed(controller->base + QUP_OPERATIONAL);
if (state & QUP_OP_OUT_FIFO_FULL)
break;
word = 0;
for (idx = 0; idx < w_size; idx++, controller->tx_bytes++) {
if (!tx_buf) {
controller->tx_bytes += w_size;
break;
}
data = tx_buf[controller->tx_bytes];
word |= data << (BITS_PER_BYTE * (3 - idx));
}
writel_relaxed(word, controller->base + QUP_OUTPUT_FIFO);
}
}
static irqreturn_t spi_qup_qup_irq(int irq, void *dev_id)
{
struct spi_qup *controller = dev_id;
struct spi_transfer *xfer;
u32 opflags, qup_err, spi_err;
unsigned long flags;
int error = 0;
spin_lock_irqsave(&controller->lock, flags);
xfer = controller->xfer;
controller->xfer = NULL;
spin_unlock_irqrestore(&controller->lock, flags);
qup_err = readl_relaxed(controller->base + QUP_ERROR_FLAGS);
spi_err = readl_relaxed(controller->base + SPI_ERROR_FLAGS);
opflags = readl_relaxed(controller->base + QUP_OPERATIONAL);
writel_relaxed(qup_err, controller->base + QUP_ERROR_FLAGS);
writel_relaxed(spi_err, controller->base + SPI_ERROR_FLAGS);
writel_relaxed(opflags, controller->base + QUP_OPERATIONAL);
if (!xfer) {
dev_err_ratelimited(controller->dev, "unexpected irq %08x %08x %08x\n",
qup_err, spi_err, opflags);
return IRQ_HANDLED;
}
if (qup_err) {
if (qup_err & QUP_ERROR_OUTPUT_OVER_RUN)
dev_warn(controller->dev, "OUTPUT_OVER_RUN\n");
if (qup_err & QUP_ERROR_INPUT_UNDER_RUN)
dev_warn(controller->dev, "INPUT_UNDER_RUN\n");
if (qup_err & QUP_ERROR_OUTPUT_UNDER_RUN)
dev_warn(controller->dev, "OUTPUT_UNDER_RUN\n");
if (qup_err & QUP_ERROR_INPUT_OVER_RUN)
dev_warn(controller->dev, "INPUT_OVER_RUN\n");
error = -EIO;
}
if (spi_err) {
if (spi_err & SPI_ERROR_CLK_OVER_RUN)
dev_warn(controller->dev, "CLK_OVER_RUN\n");
if (spi_err & SPI_ERROR_CLK_UNDER_RUN)
dev_warn(controller->dev, "CLK_UNDER_RUN\n");
error = -EIO;
}
if (opflags & QUP_OP_IN_SERVICE_FLAG)
spi_qup_fifo_read(controller, xfer);
if (opflags & QUP_OP_OUT_SERVICE_FLAG)
spi_qup_fifo_write(controller, xfer);
spin_lock_irqsave(&controller->lock, flags);
controller->error = error;
controller->xfer = xfer;
spin_unlock_irqrestore(&controller->lock, flags);
if (controller->rx_bytes == xfer->len || error)
complete(&controller->done);
return IRQ_HANDLED;
}
static int spi_qup_io_config(struct spi_device *spi, struct spi_transfer *xfer)
{
struct spi_qup *controller = spi_master_get_devdata(spi->master);
u32 config, iomode, mode;
int ret, n_words, w_size;
if (spi->mode & SPI_LOOP && xfer->len > controller->in_fifo_sz) {
dev_err(controller->dev, "too big size for loopback %d > %d\n",
xfer->len, controller->in_fifo_sz);
return -EIO;
}
ret = clk_set_rate(controller->cclk, xfer->speed_hz);
if (ret) {
dev_err(controller->dev, "fail to set frequency %d",
xfer->speed_hz);
return -EIO;
}
if (spi_qup_set_state(controller, QUP_STATE_RESET)) {
dev_err(controller->dev, "cannot set RESET state\n");
return -EIO;
}
w_size = 4;
if (xfer->bits_per_word <= 8)
w_size = 1;
else if (xfer->bits_per_word <= 16)
w_size = 2;
n_words = xfer->len / w_size;
controller->w_size = w_size;
if (n_words <= (controller->in_fifo_sz / sizeof(u32))) {
mode = QUP_IO_M_MODE_FIFO;
writel_relaxed(n_words, controller->base + QUP_MX_READ_CNT);
writel_relaxed(n_words, controller->base + QUP_MX_WRITE_CNT);
writel_relaxed(0, controller->base + QUP_MX_INPUT_CNT);
writel_relaxed(0, controller->base + QUP_MX_OUTPUT_CNT);
} else {
mode = QUP_IO_M_MODE_BLOCK;
writel_relaxed(n_words, controller->base + QUP_MX_INPUT_CNT);
writel_relaxed(n_words, controller->base + QUP_MX_OUTPUT_CNT);
writel_relaxed(0, controller->base + QUP_MX_READ_CNT);
writel_relaxed(0, controller->base + QUP_MX_WRITE_CNT);
}
iomode = readl_relaxed(controller->base + QUP_IO_M_MODES);
iomode &= ~(QUP_IO_M_INPUT_MODE_MASK | QUP_IO_M_OUTPUT_MODE_MASK);
iomode &= ~(QUP_IO_M_PACK_EN | QUP_IO_M_UNPACK_EN);
iomode |= (mode << QUP_IO_M_OUTPUT_MODE_MASK_SHIFT);
iomode |= (mode << QUP_IO_M_INPUT_MODE_MASK_SHIFT);
writel_relaxed(iomode, controller->base + QUP_IO_M_MODES);
config = readl_relaxed(controller->base + SPI_CONFIG);
if (spi->mode & SPI_LOOP)
config |= SPI_CONFIG_LOOPBACK;
else
config &= ~SPI_CONFIG_LOOPBACK;
if (spi->mode & SPI_CPHA)
config &= ~SPI_CONFIG_INPUT_FIRST;
else
config |= SPI_CONFIG_INPUT_FIRST;
if ((xfer->speed_hz >= SPI_HS_MIN_RATE) && !(spi->mode & SPI_LOOP))
config |= SPI_CONFIG_HS_MODE;
else
config &= ~SPI_CONFIG_HS_MODE;
writel_relaxed(config, controller->base + SPI_CONFIG);
config = readl_relaxed(controller->base + QUP_CONFIG);
config &= ~(QUP_CONFIG_NO_INPUT | QUP_CONFIG_NO_OUTPUT | QUP_CONFIG_N);
config |= xfer->bits_per_word - 1;
config |= QUP_CONFIG_SPI_MODE;
writel_relaxed(config, controller->base + QUP_CONFIG);
writel_relaxed(0, controller->base + QUP_OPERATIONAL_MASK);
return 0;
}
static int spi_qup_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct spi_qup *controller = spi_master_get_devdata(master);
unsigned long timeout, flags;
int ret = -EIO;
ret = spi_qup_io_config(spi, xfer);
if (ret)
return ret;
timeout = DIV_ROUND_UP(xfer->speed_hz, MSEC_PER_SEC);
timeout = DIV_ROUND_UP(xfer->len * 8, timeout);
timeout = 100 * msecs_to_jiffies(timeout);
reinit_completion(&controller->done);
spin_lock_irqsave(&controller->lock, flags);
controller->xfer = xfer;
controller->error = 0;
controller->rx_bytes = 0;
controller->tx_bytes = 0;
spin_unlock_irqrestore(&controller->lock, flags);
if (spi_qup_set_state(controller, QUP_STATE_RUN)) {
dev_warn(controller->dev, "cannot set RUN state\n");
goto exit;
}
if (spi_qup_set_state(controller, QUP_STATE_PAUSE)) {
dev_warn(controller->dev, "cannot set PAUSE state\n");
goto exit;
}
spi_qup_fifo_write(controller, xfer);
if (spi_qup_set_state(controller, QUP_STATE_RUN)) {
dev_warn(controller->dev, "cannot set EXECUTE state\n");
goto exit;
}
if (!wait_for_completion_timeout(&controller->done, timeout))
ret = -ETIMEDOUT;
exit:
spi_qup_set_state(controller, QUP_STATE_RESET);
spin_lock_irqsave(&controller->lock, flags);
controller->xfer = NULL;
if (!ret)
ret = controller->error;
spin_unlock_irqrestore(&controller->lock, flags);
return ret;
}
static int spi_qup_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct clk *iclk, *cclk;
struct spi_qup *controller;
struct resource *res;
struct device *dev;
void __iomem *base;
u32 data, max_freq, iomode;
int ret, irq, size;
dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
cclk = devm_clk_get(dev, "core");
if (IS_ERR(cclk))
return PTR_ERR(cclk);
iclk = devm_clk_get(dev, "iface");
if (IS_ERR(iclk))
return PTR_ERR(iclk);
if (of_property_read_u32(dev->of_node, "spi-max-frequency", &max_freq))
max_freq = SPI_MAX_RATE;
if (!max_freq || max_freq > SPI_MAX_RATE) {
dev_err(dev, "invalid clock frequency %d\n", max_freq);
return -ENXIO;
}
ret = clk_prepare_enable(cclk);
if (ret) {
dev_err(dev, "cannot enable core clock\n");
return ret;
}
ret = clk_prepare_enable(iclk);
if (ret) {
clk_disable_unprepare(cclk);
dev_err(dev, "cannot enable iface clock\n");
return ret;
}
data = readl_relaxed(base + QUP_HW_VERSION);
if (data < QUP_HW_VERSION_2_1_1) {
clk_disable_unprepare(cclk);
clk_disable_unprepare(iclk);
dev_err(dev, "v.%08x is not supported\n", data);
return -ENXIO;
}
master = spi_alloc_master(dev, sizeof(struct spi_qup));
if (!master) {
clk_disable_unprepare(cclk);
clk_disable_unprepare(iclk);
dev_err(dev, "cannot allocate master\n");
return -ENOMEM;
}
if (of_property_read_u16(dev->of_node, "num-cs",
&master->num_chipselect) ||
(master->num_chipselect > SPI_NUM_CHIPSELECTS))
master->num_chipselect = SPI_NUM_CHIPSELECTS;
master->bus_num = pdev->id;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LOOP;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 32);
master->max_speed_hz = max_freq;
master->transfer_one = spi_qup_transfer_one;
master->dev.of_node = pdev->dev.of_node;
master->auto_runtime_pm = true;
platform_set_drvdata(pdev, master);
controller = spi_master_get_devdata(master);
controller->dev = dev;
controller->base = base;
controller->iclk = iclk;
controller->cclk = cclk;
controller->irq = irq;
spin_lock_init(&controller->lock);
init_completion(&controller->done);
iomode = readl_relaxed(base + QUP_IO_M_MODES);
size = QUP_IO_M_OUTPUT_BLOCK_SIZE(iomode);
if (size)
controller->out_blk_sz = size * 16;
else
controller->out_blk_sz = 4;
size = QUP_IO_M_INPUT_BLOCK_SIZE(iomode);
if (size)
controller->in_blk_sz = size * 16;
else
controller->in_blk_sz = 4;
size = QUP_IO_M_OUTPUT_FIFO_SIZE(iomode);
controller->out_fifo_sz = controller->out_blk_sz * (2 << size);
size = QUP_IO_M_INPUT_FIFO_SIZE(iomode);
controller->in_fifo_sz = controller->in_blk_sz * (2 << size);
dev_info(dev, "v.%08x IN:block:%d, fifo:%d, OUT:block:%d, fifo:%d\n",
data, controller->in_blk_sz, controller->in_fifo_sz,
controller->out_blk_sz, controller->out_fifo_sz);
writel_relaxed(1, base + QUP_SW_RESET);
ret = spi_qup_set_state(controller, QUP_STATE_RESET);
if (ret) {
dev_err(dev, "cannot set RESET state\n");
goto error;
}
writel_relaxed(0, base + QUP_OPERATIONAL);
writel_relaxed(0, base + QUP_IO_M_MODES);
writel_relaxed(0, base + QUP_OPERATIONAL_MASK);
writel_relaxed(SPI_ERROR_CLK_UNDER_RUN | SPI_ERROR_CLK_OVER_RUN,
base + SPI_ERROR_FLAGS_EN);
writel_relaxed(0, base + SPI_CONFIG);
writel_relaxed(SPI_IO_C_NO_TRI_STATE, base + SPI_IO_CONTROL);
ret = devm_request_irq(dev, irq, spi_qup_qup_irq,
IRQF_TRIGGER_HIGH, pdev->name, controller);
if (ret)
goto error;
pm_runtime_set_autosuspend_delay(dev, MSEC_PER_SEC);
pm_runtime_use_autosuspend(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
ret = devm_spi_register_master(dev, master);
if (ret)
goto disable_pm;
return 0;
disable_pm:
pm_runtime_disable(&pdev->dev);
error:
clk_disable_unprepare(cclk);
clk_disable_unprepare(iclk);
spi_master_put(master);
return ret;
}
static int spi_qup_pm_suspend_runtime(struct device *device)
{
struct spi_master *master = dev_get_drvdata(device);
struct spi_qup *controller = spi_master_get_devdata(master);
u32 config;
config = readl(controller->base + QUP_CONFIG);
config |= QUP_CONFIG_CLOCK_AUTO_GATE;
writel_relaxed(config, controller->base + QUP_CONFIG);
return 0;
}
static int spi_qup_pm_resume_runtime(struct device *device)
{
struct spi_master *master = dev_get_drvdata(device);
struct spi_qup *controller = spi_master_get_devdata(master);
u32 config;
config = readl_relaxed(controller->base + QUP_CONFIG);
config &= ~QUP_CONFIG_CLOCK_AUTO_GATE;
writel_relaxed(config, controller->base + QUP_CONFIG);
return 0;
}
static int spi_qup_suspend(struct device *device)
{
struct spi_master *master = dev_get_drvdata(device);
struct spi_qup *controller = spi_master_get_devdata(master);
int ret;
ret = spi_master_suspend(master);
if (ret)
return ret;
ret = spi_qup_set_state(controller, QUP_STATE_RESET);
if (ret)
return ret;
clk_disable_unprepare(controller->cclk);
clk_disable_unprepare(controller->iclk);
return 0;
}
static int spi_qup_resume(struct device *device)
{
struct spi_master *master = dev_get_drvdata(device);
struct spi_qup *controller = spi_master_get_devdata(master);
int ret;
ret = clk_prepare_enable(controller->iclk);
if (ret)
return ret;
ret = clk_prepare_enable(controller->cclk);
if (ret)
return ret;
ret = spi_qup_set_state(controller, QUP_STATE_RESET);
if (ret)
return ret;
return spi_master_resume(master);
}
static int spi_qup_remove(struct platform_device *pdev)
{
struct spi_master *master = dev_get_drvdata(&pdev->dev);
struct spi_qup *controller = spi_master_get_devdata(master);
int ret;
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0)
return ret;
ret = spi_qup_set_state(controller, QUP_STATE_RESET);
if (ret)
return ret;
clk_disable_unprepare(controller->cclk);
clk_disable_unprepare(controller->iclk);
pm_runtime_put_noidle(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
