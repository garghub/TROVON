static void efm32_spi_write32(struct efm32_spi_ddata *ddata,
u32 value, unsigned offset)
{
writel_relaxed(value, ddata->base + offset);
}
static u32 efm32_spi_read32(struct efm32_spi_ddata *ddata, unsigned offset)
{
return readl_relaxed(ddata->base + offset);
}
static void efm32_spi_chipselect(struct spi_device *spi, int is_on)
{
struct efm32_spi_ddata *ddata = spi_master_get_devdata(spi->master);
int value = !(spi->mode & SPI_CS_HIGH) == !(is_on == BITBANG_CS_ACTIVE);
gpio_set_value(ddata->csgpio[spi->chip_select], value);
}
static int efm32_spi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct efm32_spi_ddata *ddata = spi_master_get_devdata(spi->master);
unsigned bpw = t->bits_per_word ?: spi->bits_per_word;
unsigned speed = t->speed_hz ?: spi->max_speed_hz;
unsigned long clkfreq = clk_get_rate(ddata->clk);
u32 clkdiv;
efm32_spi_write32(ddata, REG_CTRL_SYNC | REG_CTRL_MSBF |
(spi->mode & SPI_CPHA ? REG_CTRL_CLKPHA : 0) |
(spi->mode & SPI_CPOL ? REG_CTRL_CLKPOL : 0), REG_CTRL);
efm32_spi_write32(ddata,
REG_FRAME_DATABITS(bpw), REG_FRAME);
if (2 * speed >= clkfreq)
clkdiv = 0;
else
clkdiv = 64 * (DIV_ROUND_UP(2 * clkfreq, speed) - 4);
if (clkdiv > (1U << 21))
return -EINVAL;
efm32_spi_write32(ddata, clkdiv, REG_CLKDIV);
efm32_spi_write32(ddata, REG_CMD_MASTEREN, REG_CMD);
efm32_spi_write32(ddata, REG_CMD_RXEN | REG_CMD_TXEN, REG_CMD);
return 0;
}
static void efm32_spi_tx_u8(struct efm32_spi_ddata *ddata)
{
u8 val = 0;
if (ddata->tx_buf) {
val = *ddata->tx_buf;
ddata->tx_buf++;
}
ddata->tx_len--;
efm32_spi_write32(ddata, val, REG_TXDATA);
efm32_spi_vdbg(ddata, "%s: tx 0x%x\n", __func__, val);
}
static void efm32_spi_rx_u8(struct efm32_spi_ddata *ddata)
{
u32 rxdata = efm32_spi_read32(ddata, REG_RXDATAX);
efm32_spi_vdbg(ddata, "%s: rx 0x%x\n", __func__, rxdata);
if (ddata->rx_buf) {
*ddata->rx_buf = rxdata;
ddata->rx_buf++;
}
ddata->rx_len--;
}
static void efm32_spi_filltx(struct efm32_spi_ddata *ddata)
{
while (ddata->tx_len &&
ddata->tx_len + 2 > ddata->rx_len &&
efm32_spi_read32(ddata, REG_STATUS) & REG_STATUS_TXBL) {
efm32_spi_tx_u8(ddata);
}
}
static int efm32_spi_txrx_bufs(struct spi_device *spi, struct spi_transfer *t)
{
struct efm32_spi_ddata *ddata = spi_master_get_devdata(spi->master);
int ret = -EBUSY;
spin_lock_irq(&ddata->lock);
if (ddata->tx_buf || ddata->rx_buf)
goto out_unlock;
ddata->tx_buf = t->tx_buf;
ddata->rx_buf = t->rx_buf;
ddata->tx_len = ddata->rx_len =
t->len * DIV_ROUND_UP(t->bits_per_word, 8);
efm32_spi_filltx(ddata);
init_completion(&ddata->done);
efm32_spi_write32(ddata, REG_IF_TXBL | REG_IF_RXDATAV, REG_IEN);
spin_unlock_irq(&ddata->lock);
wait_for_completion(&ddata->done);
spin_lock_irq(&ddata->lock);
ret = t->len - max(ddata->tx_len, ddata->rx_len);
efm32_spi_write32(ddata, 0, REG_IEN);
ddata->tx_buf = ddata->rx_buf = NULL;
out_unlock:
spin_unlock_irq(&ddata->lock);
return ret;
}
static irqreturn_t efm32_spi_rxirq(int irq, void *data)
{
struct efm32_spi_ddata *ddata = data;
irqreturn_t ret = IRQ_NONE;
spin_lock(&ddata->lock);
while (ddata->rx_len > 0 &&
efm32_spi_read32(ddata, REG_STATUS) &
REG_STATUS_RXDATAV) {
efm32_spi_rx_u8(ddata);
ret = IRQ_HANDLED;
}
if (!ddata->rx_len) {
u32 ien = efm32_spi_read32(ddata, REG_IEN);
ien &= ~REG_IF_RXDATAV;
efm32_spi_write32(ddata, ien, REG_IEN);
complete(&ddata->done);
}
spin_unlock(&ddata->lock);
return ret;
}
static irqreturn_t efm32_spi_txirq(int irq, void *data)
{
struct efm32_spi_ddata *ddata = data;
efm32_spi_vdbg(ddata,
"%s: txlen = %u, rxlen = %u, if=0x%08x, stat=0x%08x\n",
__func__, ddata->tx_len, ddata->rx_len,
efm32_spi_read32(ddata, REG_IF),
efm32_spi_read32(ddata, REG_STATUS));
spin_lock(&ddata->lock);
efm32_spi_filltx(ddata);
efm32_spi_vdbg(ddata, "%s: txlen = %u, rxlen = %u\n",
__func__, ddata->tx_len, ddata->rx_len);
if (!ddata->tx_len) {
u32 ien = efm32_spi_read32(ddata, REG_IEN);
ien &= ~REG_IF_TXBL;
efm32_spi_write32(ddata, ien, REG_IEN);
efm32_spi_vdbg(ddata, "disable TXBL\n");
}
spin_unlock(&ddata->lock);
return IRQ_HANDLED;
}
static u32 efm32_spi_get_configured_location(struct efm32_spi_ddata *ddata)
{
u32 reg = efm32_spi_read32(ddata, REG_ROUTE);
return (reg & REG_ROUTE_LOCATION__MASK) >> __ffs(REG_ROUTE_LOCATION__MASK);
}
static int efm32_spi_probe_dt(struct platform_device *pdev,
struct spi_master *master, struct efm32_spi_ddata *ddata)
{
struct device_node *np = pdev->dev.of_node;
u32 location;
int ret;
if (!np)
return 1;
ret = of_property_read_u32(np, "location", &location);
if (!ret) {
dev_dbg(&pdev->dev, "using location %u\n", location);
} else {
location = efm32_spi_get_configured_location(ddata);
dev_info(&pdev->dev, "fall back to location %u\n", location);
}
ddata->pdata.location = location;
master->bus_num = -1;
return 0;
}
static int efm32_spi_probe(struct platform_device *pdev)
{
struct efm32_spi_ddata *ddata;
struct resource *res;
int ret;
struct spi_master *master;
struct device_node *np = pdev->dev.of_node;
unsigned int num_cs, i;
num_cs = of_gpio_named_count(np, "cs-gpios");
master = spi_alloc_master(&pdev->dev,
sizeof(*ddata) + num_cs * sizeof(unsigned));
if (!master) {
dev_dbg(&pdev->dev,
"failed to allocate spi master controller\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, master);
master->dev.of_node = pdev->dev.of_node;
master->num_chipselect = num_cs;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 16);
ddata = spi_master_get_devdata(master);
ddata->bitbang.master = master;
ddata->bitbang.chipselect = efm32_spi_chipselect;
ddata->bitbang.setup_transfer = efm32_spi_setup_transfer;
ddata->bitbang.txrx_bufs = efm32_spi_txrx_bufs;
spin_lock_init(&ddata->lock);
ddata->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(ddata->clk)) {
ret = PTR_ERR(ddata->clk);
dev_err(&pdev->dev, "failed to get clock: %d\n", ret);
goto err;
}
for (i = 0; i < num_cs; ++i) {
ret = of_get_named_gpio(np, "cs-gpios", i);
if (ret < 0) {
dev_err(&pdev->dev, "failed to get csgpio#%u (%d)\n",
i, ret);
goto err;
}
ddata->csgpio[i] = ret;
dev_dbg(&pdev->dev, "csgpio#%u = %u\n", i, ddata->csgpio[i]);
ret = devm_gpio_request_one(&pdev->dev, ddata->csgpio[i],
GPIOF_OUT_INIT_LOW, DRIVER_NAME);
if (ret < 0) {
dev_err(&pdev->dev,
"failed to configure csgpio#%u (%d)\n",
i, ret);
goto err;
}
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENODEV;
dev_err(&pdev->dev, "failed to determine base address\n");
goto err;
}
if (resource_size(res) < 0x60) {
ret = -EINVAL;
dev_err(&pdev->dev, "memory resource too small\n");
goto err;
}
ddata->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ddata->base)) {
ret = PTR_ERR(ddata->base);
goto err;
}
ret = platform_get_irq(pdev, 0);
if (ret <= 0) {
dev_err(&pdev->dev, "failed to get rx irq (%d)\n", ret);
goto err;
}
ddata->rxirq = ret;
ret = platform_get_irq(pdev, 1);
if (ret <= 0)
ret = ddata->rxirq + 1;
ddata->txirq = ret;
ret = clk_prepare_enable(ddata->clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable clock (%d)\n", ret);
goto err;
}
ret = efm32_spi_probe_dt(pdev, master, ddata);
if (ret > 0) {
const struct efm32_spi_pdata *pdata =
dev_get_platdata(&pdev->dev);
if (pdata)
ddata->pdata = *pdata;
else
ddata->pdata.location =
efm32_spi_get_configured_location(ddata);
master->bus_num = pdev->id;
} else if (ret < 0) {
goto err_disable_clk;
}
efm32_spi_write32(ddata, 0, REG_IEN);
efm32_spi_write32(ddata, REG_ROUTE_TXPEN | REG_ROUTE_RXPEN |
REG_ROUTE_CLKPEN |
REG_ROUTE_LOCATION(ddata->pdata.location), REG_ROUTE);
ret = request_irq(ddata->rxirq, efm32_spi_rxirq,
0, DRIVER_NAME " rx", ddata);
if (ret) {
dev_err(&pdev->dev, "failed to register rxirq (%d)\n", ret);
goto err_disable_clk;
}
ret = request_irq(ddata->txirq, efm32_spi_txirq,
0, DRIVER_NAME " tx", ddata);
if (ret) {
dev_err(&pdev->dev, "failed to register txirq (%d)\n", ret);
goto err_free_rx_irq;
}
ret = spi_bitbang_start(&ddata->bitbang);
if (ret) {
dev_err(&pdev->dev, "spi_bitbang_start failed (%d)\n", ret);
free_irq(ddata->txirq, ddata);
err_free_rx_irq:
free_irq(ddata->rxirq, ddata);
err_disable_clk:
clk_disable_unprepare(ddata->clk);
err:
spi_master_put(master);
}
return ret;
}
static int efm32_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct efm32_spi_ddata *ddata = spi_master_get_devdata(master);
spi_bitbang_stop(&ddata->bitbang);
efm32_spi_write32(ddata, 0, REG_IEN);
free_irq(ddata->txirq, ddata);
free_irq(ddata->rxirq, ddata);
clk_disable_unprepare(ddata->clk);
spi_master_put(master);
return 0;
}
