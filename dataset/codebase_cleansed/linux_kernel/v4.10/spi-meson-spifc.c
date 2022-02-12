static int meson_spifc_wait_ready(struct meson_spifc *spifc)
{
unsigned long deadline = jiffies + msecs_to_jiffies(5);
u32 data;
do {
regmap_read(spifc->regmap, REG_SLAVE, &data);
if (data & SLAVE_TRST_DONE)
return 0;
cond_resched();
} while (!time_after(jiffies, deadline));
return -ETIMEDOUT;
}
static void meson_spifc_drain_buffer(struct meson_spifc *spifc, u8 *buf,
int len)
{
u32 data;
int i = 0;
while (i < len) {
regmap_read(spifc->regmap, REG_C0 + i, &data);
if (len - i >= 4) {
*((u32 *)buf) = data;
buf += 4;
} else {
memcpy(buf, &data, len - i);
break;
}
i += 4;
}
}
static void meson_spifc_fill_buffer(struct meson_spifc *spifc, const u8 *buf,
int len)
{
u32 data;
int i = 0;
while (i < len) {
if (len - i >= 4)
data = *(u32 *)buf;
else
memcpy(&data, buf, len - i);
regmap_write(spifc->regmap, REG_C0 + i, data);
buf += 4;
i += 4;
}
}
static void meson_spifc_setup_speed(struct meson_spifc *spifc, u32 speed)
{
unsigned long parent, value;
int n;
parent = clk_get_rate(spifc->clk);
n = max_t(int, parent / speed - 1, 1);
dev_dbg(spifc->dev, "parent %lu, speed %u, n %d\n", parent,
speed, n);
value = (n << CLOCK_DIV_SHIFT) & CLOCK_DIV_MASK;
value |= (n << CLOCK_CNT_LOW_SHIFT) & CLOCK_CNT_LOW_MASK;
value |= (((n + 1) / 2 - 1) << CLOCK_CNT_HIGH_SHIFT) &
CLOCK_CNT_HIGH_MASK;
regmap_write(spifc->regmap, REG_CLOCK, value);
}
static int meson_spifc_txrx(struct meson_spifc *spifc,
struct spi_transfer *xfer,
int offset, int len, bool last_xfer,
bool last_chunk)
{
bool keep_cs = true;
int ret;
if (xfer->tx_buf)
meson_spifc_fill_buffer(spifc, xfer->tx_buf + offset, len);
regmap_update_bits(spifc->regmap, REG_USER, USER_UC_MASK,
USER_UC_DOUT_SEL);
regmap_write(spifc->regmap, REG_USER1,
(8 * len - 1) << USER1_BN_UC_DOUT_SHIFT);
regmap_update_bits(spifc->regmap, REG_USER, USER_DIN_EN_MS,
USER_DIN_EN_MS);
if (last_chunk) {
if (last_xfer)
keep_cs = xfer->cs_change;
else
keep_cs = !xfer->cs_change;
}
regmap_update_bits(spifc->regmap, REG_USER4, USER4_CS_ACT,
keep_cs ? USER4_CS_ACT : 0);
regmap_update_bits(spifc->regmap, REG_SLAVE, SLAVE_TRST_DONE, 0);
regmap_update_bits(spifc->regmap, REG_CMD, CMD_USER, CMD_USER);
ret = meson_spifc_wait_ready(spifc);
if (!ret && xfer->rx_buf)
meson_spifc_drain_buffer(spifc, xfer->rx_buf + offset, len);
return ret;
}
static int meson_spifc_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct meson_spifc *spifc = spi_master_get_devdata(master);
int len, done = 0, ret = 0;
meson_spifc_setup_speed(spifc, xfer->speed_hz);
regmap_update_bits(spifc->regmap, REG_CTRL, CTRL_ENABLE_AHB, 0);
while (done < xfer->len && !ret) {
len = min_t(int, xfer->len - done, SPIFC_BUFFER_SIZE);
ret = meson_spifc_txrx(spifc, xfer, done, len,
spi_transfer_is_last(master, xfer),
done + len >= xfer->len);
done += len;
}
regmap_update_bits(spifc->regmap, REG_CTRL, CTRL_ENABLE_AHB,
CTRL_ENABLE_AHB);
return ret;
}
static void meson_spifc_hw_init(struct meson_spifc *spifc)
{
regmap_update_bits(spifc->regmap, REG_SLAVE, SLAVE_SW_RST,
SLAVE_SW_RST);
regmap_update_bits(spifc->regmap, REG_USER, USER_CMP_MODE, 0);
regmap_update_bits(spifc->regmap, REG_SLAVE, SLAVE_OP_MODE, 0);
}
static int meson_spifc_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct meson_spifc *spifc;
struct resource *res;
void __iomem *base;
unsigned int rate;
int ret = 0;
master = spi_alloc_master(&pdev->dev, sizeof(struct meson_spifc));
if (!master)
return -ENOMEM;
platform_set_drvdata(pdev, master);
spifc = spi_master_get_devdata(master);
spifc->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(spifc->dev, res);
if (IS_ERR(base)) {
ret = PTR_ERR(base);
goto out_err;
}
spifc->regmap = devm_regmap_init_mmio(spifc->dev, base,
&spifc_regmap_config);
if (IS_ERR(spifc->regmap)) {
ret = PTR_ERR(spifc->regmap);
goto out_err;
}
spifc->clk = devm_clk_get(spifc->dev, NULL);
if (IS_ERR(spifc->clk)) {
dev_err(spifc->dev, "missing clock\n");
ret = PTR_ERR(spifc->clk);
goto out_err;
}
ret = clk_prepare_enable(spifc->clk);
if (ret) {
dev_err(spifc->dev, "can't prepare clock\n");
goto out_err;
}
rate = clk_get_rate(spifc->clk);
master->num_chipselect = 1;
master->dev.of_node = pdev->dev.of_node;
master->bits_per_word_mask = SPI_BPW_MASK(8);
master->auto_runtime_pm = true;
master->transfer_one = meson_spifc_transfer_one;
master->min_speed_hz = rate >> 6;
master->max_speed_hz = rate >> 1;
meson_spifc_hw_init(spifc);
pm_runtime_set_active(spifc->dev);
pm_runtime_enable(spifc->dev);
ret = devm_spi_register_master(spifc->dev, master);
if (ret) {
dev_err(spifc->dev, "failed to register spi master\n");
goto out_clk;
}
return 0;
out_clk:
clk_disable_unprepare(spifc->clk);
out_err:
spi_master_put(master);
return ret;
}
static int meson_spifc_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct meson_spifc *spifc = spi_master_get_devdata(master);
pm_runtime_get_sync(&pdev->dev);
clk_disable_unprepare(spifc->clk);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int meson_spifc_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct meson_spifc *spifc = spi_master_get_devdata(master);
int ret;
ret = spi_master_suspend(master);
if (ret)
return ret;
if (!pm_runtime_suspended(dev))
clk_disable_unprepare(spifc->clk);
return 0;
}
static int meson_spifc_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct meson_spifc *spifc = spi_master_get_devdata(master);
int ret;
if (!pm_runtime_suspended(dev)) {
ret = clk_prepare_enable(spifc->clk);
if (ret)
return ret;
}
meson_spifc_hw_init(spifc);
ret = spi_master_resume(master);
if (ret)
clk_disable_unprepare(spifc->clk);
return ret;
}
static int meson_spifc_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct meson_spifc *spifc = spi_master_get_devdata(master);
clk_disable_unprepare(spifc->clk);
return 0;
}
static int meson_spifc_runtime_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct meson_spifc *spifc = spi_master_get_devdata(master);
return clk_prepare_enable(spifc->clk);
}
