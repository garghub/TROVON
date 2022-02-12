static inline bool meson_spicc_txfull(struct meson_spicc_device *spicc)
{
return !!FIELD_GET(SPICC_TF,
readl_relaxed(spicc->base + SPICC_STATREG));
}
static inline bool meson_spicc_rxready(struct meson_spicc_device *spicc)
{
return FIELD_GET(SPICC_RH | SPICC_RR | SPICC_RF_EN,
readl_relaxed(spicc->base + SPICC_STATREG));
}
static inline u32 meson_spicc_pull_data(struct meson_spicc_device *spicc)
{
unsigned int bytes = spicc->bytes_per_word;
unsigned int byte_shift = 0;
u32 data = 0;
u8 byte;
while (bytes--) {
byte = *spicc->tx_buf++;
data |= (byte & 0xff) << byte_shift;
byte_shift += 8;
}
spicc->tx_remain--;
return data;
}
static inline void meson_spicc_push_data(struct meson_spicc_device *spicc,
u32 data)
{
unsigned int bytes = spicc->bytes_per_word;
unsigned int byte_shift = 0;
u8 byte;
while (bytes--) {
byte = (data >> byte_shift) & 0xff;
*spicc->rx_buf++ = byte;
byte_shift += 8;
}
spicc->rx_remain--;
}
static inline void meson_spicc_rx(struct meson_spicc_device *spicc)
{
while (spicc->rx_remain &&
meson_spicc_rxready(spicc))
meson_spicc_push_data(spicc,
readl_relaxed(spicc->base + SPICC_RXDATA));
}
static inline void meson_spicc_tx(struct meson_spicc_device *spicc)
{
while (spicc->tx_remain &&
!meson_spicc_txfull(spicc))
writel_relaxed(meson_spicc_pull_data(spicc),
spicc->base + SPICC_TXDATA);
}
static inline u32 meson_spicc_setup_rx_irq(struct meson_spicc_device *spicc,
u32 irq_ctrl)
{
if (spicc->rx_remain > SPICC_FIFO_HALF)
irq_ctrl |= SPICC_RH_EN;
else
irq_ctrl |= SPICC_RR_EN;
return irq_ctrl;
}
static inline void meson_spicc_setup_burst(struct meson_spicc_device *spicc,
unsigned int burst_len)
{
spicc->tx_remain = burst_len;
spicc->rx_remain = burst_len;
spicc->xfer_remain -= burst_len * spicc->bytes_per_word;
spicc->is_burst_end = false;
if (burst_len < SPICC_BURST_MAX || !spicc->xfer_remain)
spicc->is_last_burst = true;
else
spicc->is_last_burst = false;
writel_bits_relaxed(SPICC_BURSTLENGTH_MASK,
FIELD_PREP(SPICC_BURSTLENGTH_MASK,
burst_len),
spicc->base + SPICC_CONREG);
meson_spicc_tx(spicc);
}
static irqreturn_t meson_spicc_irq(int irq, void *data)
{
struct meson_spicc_device *spicc = (void *) data;
u32 ctrl = readl_relaxed(spicc->base + SPICC_INTREG);
u32 stat = readl_relaxed(spicc->base + SPICC_STATREG) & ctrl;
ctrl &= ~(SPICC_RH_EN | SPICC_RR_EN);
meson_spicc_rx(spicc);
if (!spicc->tx_remain && !spicc->rx_remain) {
spicc->is_burst_end = true;
ctrl |= SPICC_TC_EN;
stat = readl_relaxed(spicc->base + SPICC_STATREG) & ctrl;
}
if ((stat & SPICC_TC) && spicc->is_burst_end) {
unsigned int burst_len;
writel_relaxed(SPICC_TC, spicc->base + SPICC_STATREG);
ctrl &= ~SPICC_TC_EN;
if (spicc->is_last_burst) {
writel(0, spicc->base + SPICC_INTREG);
spi_finalize_current_transfer(spicc->master);
return IRQ_HANDLED;
}
burst_len = min_t(unsigned int,
spicc->xfer_remain / spicc->bytes_per_word,
SPICC_BURST_MAX);
meson_spicc_setup_burst(spicc, burst_len);
writel_bits_relaxed(SPICC_XCH, SPICC_XCH,
spicc->base + SPICC_CONREG);
}
ctrl = meson_spicc_setup_rx_irq(spicc, ctrl);
writel(ctrl, spicc->base + SPICC_INTREG);
return IRQ_HANDLED;
}
static u32 meson_spicc_setup_speed(struct meson_spicc_device *spicc, u32 conf,
u32 speed)
{
unsigned long parent, value;
unsigned int i, div;
parent = clk_get_rate(spicc->core);
for (i = 0 ; i < 7 ; ++i) {
value = parent >> (i + 2);
if (value <= speed)
break;
}
if (i > 7) {
div = 7;
dev_warn_once(&spicc->pdev->dev, "unable to get close to speed %u\n",
speed);
} else
div = i;
dev_dbg(&spicc->pdev->dev, "parent %lu, speed %u -> %lu (%u)\n",
parent, speed, value, div);
conf &= ~SPICC_DATARATE_MASK;
conf |= FIELD_PREP(SPICC_DATARATE_MASK, div);
return conf;
}
static void meson_spicc_setup_xfer(struct meson_spicc_device *spicc,
struct spi_transfer *xfer)
{
u32 conf, conf_orig;
conf = conf_orig = readl_relaxed(spicc->base + SPICC_CONREG);
conf = meson_spicc_setup_speed(spicc, conf, xfer->speed_hz);
conf &= ~SPICC_BITLENGTH_MASK;
conf |= FIELD_PREP(SPICC_BITLENGTH_MASK,
(spicc->bytes_per_word << 3) - 1);
if (conf != conf_orig)
writel_relaxed(conf, spicc->base + SPICC_CONREG);
}
static int meson_spicc_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct meson_spicc_device *spicc = spi_master_get_devdata(master);
unsigned int burst_len;
u32 irq = 0;
spicc->xfer = xfer;
spicc->tx_buf = (u8 *)xfer->tx_buf;
spicc->rx_buf = (u8 *)xfer->rx_buf;
spicc->xfer_remain = xfer->len;
spicc->bytes_per_word =
DIV_ROUND_UP(spicc->xfer->bits_per_word, 8);
meson_spicc_setup_xfer(spicc, xfer);
burst_len = min_t(unsigned int,
spicc->xfer_remain / spicc->bytes_per_word,
SPICC_BURST_MAX);
meson_spicc_setup_burst(spicc, burst_len);
irq = meson_spicc_setup_rx_irq(spicc, irq);
writel_bits_relaxed(SPICC_XCH, SPICC_XCH, spicc->base + SPICC_CONREG);
writel_relaxed(irq, spicc->base + SPICC_INTREG);
return 1;
}
static int meson_spicc_prepare_message(struct spi_master *master,
struct spi_message *message)
{
struct meson_spicc_device *spicc = spi_master_get_devdata(master);
struct spi_device *spi = message->spi;
u32 conf = 0;
spicc->message = message;
conf |= SPICC_ENABLE;
conf |= SPICC_MODE_MASTER;
if (spi->mode & SPI_CPOL)
conf |= SPICC_POL;
else
conf &= ~SPICC_POL;
if (spi->mode & SPI_CPHA)
conf |= SPICC_PHA;
else
conf &= ~SPICC_PHA;
if (spi->mode & SPI_CS_HIGH)
conf |= SPICC_SSPOL;
else
conf &= ~SPICC_SSPOL;
if (spi->mode & SPI_READY)
conf |= FIELD_PREP(SPICC_DRCTL_MASK, SPICC_DRCTL_LOWLEVEL);
else
conf |= FIELD_PREP(SPICC_DRCTL_MASK, SPICC_DRCTL_IGNORE);
conf |= FIELD_PREP(SPICC_CS_MASK, spi->chip_select);
conf |= FIELD_PREP(SPICC_BITLENGTH_MASK, 8 - 1);
writel_relaxed(conf, spicc->base + SPICC_CONREG);
writel_relaxed(0, spicc->base + SPICC_PERIODREG);
writel_bits_relaxed(BIT(24), BIT(24), spicc->base + SPICC_TESTREG);
return 0;
}
static int meson_spicc_unprepare_transfer(struct spi_master *master)
{
struct meson_spicc_device *spicc = spi_master_get_devdata(master);
writel(0, spicc->base + SPICC_INTREG);
writel_bits_relaxed(SPICC_ENABLE, 0, spicc->base + SPICC_CONREG);
device_reset_optional(&spicc->pdev->dev);
return 0;
}
static int meson_spicc_setup(struct spi_device *spi)
{
int ret = 0;
if (!spi->controller_state)
spi->controller_state = spi_master_get_devdata(spi->master);
else if (gpio_is_valid(spi->cs_gpio))
goto out_gpio;
else if (spi->cs_gpio == -ENOENT)
return 0;
if (gpio_is_valid(spi->cs_gpio)) {
ret = gpio_request(spi->cs_gpio, dev_name(&spi->dev));
if (ret) {
dev_err(&spi->dev, "failed to request cs gpio\n");
return ret;
}
}
out_gpio:
ret = gpio_direction_output(spi->cs_gpio,
!(spi->mode & SPI_CS_HIGH));
return ret;
}
static void meson_spicc_cleanup(struct spi_device *spi)
{
if (gpio_is_valid(spi->cs_gpio))
gpio_free(spi->cs_gpio);
spi->controller_state = NULL;
}
static int meson_spicc_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct meson_spicc_device *spicc;
struct resource *res;
int ret, irq, rate;
master = spi_alloc_master(&pdev->dev, sizeof(*spicc));
if (!master) {
dev_err(&pdev->dev, "master allocation failed\n");
return -ENOMEM;
}
spicc = spi_master_get_devdata(master);
spicc->master = master;
spicc->pdev = pdev;
platform_set_drvdata(pdev, spicc);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
spicc->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(spicc->base)) {
dev_err(&pdev->dev, "io resource mapping failed\n");
ret = PTR_ERR(spicc->base);
goto out_master;
}
writel_relaxed(0, spicc->base + SPICC_INTREG);
irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(&pdev->dev, irq, meson_spicc_irq,
0, NULL, spicc);
if (ret) {
dev_err(&pdev->dev, "irq request failed\n");
goto out_master;
}
spicc->core = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(spicc->core)) {
dev_err(&pdev->dev, "core clock request failed\n");
ret = PTR_ERR(spicc->core);
goto out_master;
}
ret = clk_prepare_enable(spicc->core);
if (ret) {
dev_err(&pdev->dev, "core clock enable failed\n");
goto out_master;
}
rate = clk_get_rate(spicc->core);
device_reset_optional(&pdev->dev);
master->num_chipselect = 4;
master->dev.of_node = pdev->dev.of_node;
master->mode_bits = SPI_CPHA | SPI_CPOL | SPI_CS_HIGH;
master->bits_per_word_mask = SPI_BPW_MASK(32) |
SPI_BPW_MASK(24) |
SPI_BPW_MASK(16) |
SPI_BPW_MASK(8);
master->flags = (SPI_MASTER_MUST_RX | SPI_MASTER_MUST_TX);
master->min_speed_hz = rate >> 9;
master->setup = meson_spicc_setup;
master->cleanup = meson_spicc_cleanup;
master->prepare_message = meson_spicc_prepare_message;
master->unprepare_transfer_hardware = meson_spicc_unprepare_transfer;
master->transfer_one = meson_spicc_transfer_one;
if ((rate >> 2) > SPICC_MAX_FREQ)
master->max_speed_hz = SPICC_MAX_FREQ;
else
master->max_speed_hz = rate >> 2;
ret = devm_spi_register_master(&pdev->dev, master);
if (!ret)
return 0;
dev_err(&pdev->dev, "spi master registration failed\n");
out_master:
spi_master_put(master);
return ret;
}
static int meson_spicc_remove(struct platform_device *pdev)
{
struct meson_spicc_device *spicc = platform_get_drvdata(pdev);
writel(0, spicc->base + SPICC_CONREG);
clk_disable_unprepare(spicc->core);
return 0;
}
