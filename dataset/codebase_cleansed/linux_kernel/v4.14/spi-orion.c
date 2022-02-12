static inline void __iomem *spi_reg(struct orion_spi *orion_spi, u32 reg)
{
return orion_spi->base + reg;
}
static inline void
orion_spi_setbits(struct orion_spi *orion_spi, u32 reg, u32 mask)
{
void __iomem *reg_addr = spi_reg(orion_spi, reg);
u32 val;
val = readl(reg_addr);
val |= mask;
writel(val, reg_addr);
}
static inline void
orion_spi_clrbits(struct orion_spi *orion_spi, u32 reg, u32 mask)
{
void __iomem *reg_addr = spi_reg(orion_spi, reg);
u32 val;
val = readl(reg_addr);
val &= ~mask;
writel(val, reg_addr);
}
static int orion_spi_baudrate_set(struct spi_device *spi, unsigned int speed)
{
u32 tclk_hz;
u32 rate;
u32 prescale;
u32 reg;
struct orion_spi *orion_spi;
const struct orion_spi_dev *devdata;
orion_spi = spi_master_get_devdata(spi->master);
devdata = orion_spi->devdata;
tclk_hz = clk_get_rate(orion_spi->clk);
if (devdata->typ == ARMADA_SPI) {
unsigned divider = DIV_ROUND_UP(tclk_hz, speed);
unsigned spr, sppr;
if (divider < 16) {
spr = divider;
sppr = 0;
} else {
unsigned two_pow_sppr;
sppr = fls(divider) - 4;
two_pow_sppr = 1 << sppr;
divider = (divider + two_pow_sppr - 1) & -two_pow_sppr;
sppr = fls(divider) - 4;
spr = divider >> sppr;
if (sppr > 7)
return -EINVAL;
}
prescale = ((sppr & 0x6) << 5) | ((sppr & 0x1) << 4) | spr;
} else {
rate = DIV_ROUND_UP(tclk_hz, speed);
rate = roundup(rate, 2);
if (rate > 30)
return -EINVAL;
if (rate < 4)
rate = 4;
prescale = 0x10 + rate/2;
}
reg = readl(spi_reg(orion_spi, ORION_SPI_IF_CONFIG_REG));
reg = ((reg & ~devdata->prescale_mask) | prescale);
writel(reg, spi_reg(orion_spi, ORION_SPI_IF_CONFIG_REG));
return 0;
}
static void
orion_spi_mode_set(struct spi_device *spi)
{
u32 reg;
struct orion_spi *orion_spi;
orion_spi = spi_master_get_devdata(spi->master);
reg = readl(spi_reg(orion_spi, ORION_SPI_IF_CONFIG_REG));
reg &= ~ORION_SPI_MODE_MASK;
if (spi->mode & SPI_CPOL)
reg |= ORION_SPI_MODE_CPOL;
if (spi->mode & SPI_CPHA)
reg |= ORION_SPI_MODE_CPHA;
if (spi->mode & SPI_LSB_FIRST)
reg |= ORION_SPI_IF_RXLSBF | ORION_SPI_IF_TXLSBF;
else
reg &= ~(ORION_SPI_IF_RXLSBF | ORION_SPI_IF_TXLSBF);
writel(reg, spi_reg(orion_spi, ORION_SPI_IF_CONFIG_REG));
}
static void
orion_spi_50mhz_ac_timing_erratum(struct spi_device *spi, unsigned int speed)
{
u32 reg;
struct orion_spi *orion_spi;
orion_spi = spi_master_get_devdata(spi->master);
reg = readl(spi_reg(orion_spi, ORION_SPI_TIMING_PARAMS_REG));
reg &= ~ORION_SPI_TMISO_SAMPLE_MASK;
if (clk_get_rate(orion_spi->clk) == 250000000 &&
speed == 50000000 && spi->mode & SPI_CPOL &&
spi->mode & SPI_CPHA)
reg |= ORION_SPI_TMISO_SAMPLE_2;
else
reg |= ORION_SPI_TMISO_SAMPLE_1;
writel(reg, spi_reg(orion_spi, ORION_SPI_TIMING_PARAMS_REG));
}
static int
orion_spi_setup_transfer(struct spi_device *spi, struct spi_transfer *t)
{
struct orion_spi *orion_spi;
unsigned int speed = spi->max_speed_hz;
unsigned int bits_per_word = spi->bits_per_word;
int rc;
orion_spi = spi_master_get_devdata(spi->master);
if ((t != NULL) && t->speed_hz)
speed = t->speed_hz;
if ((t != NULL) && t->bits_per_word)
bits_per_word = t->bits_per_word;
orion_spi_mode_set(spi);
if (orion_spi->devdata->is_errata_50mhz_ac)
orion_spi_50mhz_ac_timing_erratum(spi, speed);
rc = orion_spi_baudrate_set(spi, speed);
if (rc)
return rc;
if (bits_per_word == 16)
orion_spi_setbits(orion_spi, ORION_SPI_IF_CONFIG_REG,
ORION_SPI_IF_8_16_BIT_MODE);
else
orion_spi_clrbits(orion_spi, ORION_SPI_IF_CONFIG_REG,
ORION_SPI_IF_8_16_BIT_MODE);
return 0;
}
static void orion_spi_set_cs(struct spi_device *spi, bool enable)
{
struct orion_spi *orion_spi;
int cs;
if (gpio_is_valid(spi->cs_gpio))
cs = 0;
else
cs = spi->chip_select;
orion_spi = spi_master_get_devdata(spi->master);
orion_spi_clrbits(orion_spi, ORION_SPI_IF_CTRL_REG, ORION_SPI_CS_MASK);
orion_spi_setbits(orion_spi, ORION_SPI_IF_CTRL_REG,
ORION_SPI_CS(cs));
if (!enable)
orion_spi_setbits(orion_spi, ORION_SPI_IF_CTRL_REG, 0x1);
else
orion_spi_clrbits(orion_spi, ORION_SPI_IF_CTRL_REG, 0x1);
}
static inline int orion_spi_wait_till_ready(struct orion_spi *orion_spi)
{
int i;
for (i = 0; i < ORION_SPI_WAIT_RDY_MAX_LOOP; i++) {
if (readl(spi_reg(orion_spi, ORION_SPI_INT_CAUSE_REG)))
return 1;
udelay(1);
}
return -1;
}
static inline int
orion_spi_write_read_8bit(struct spi_device *spi,
const u8 **tx_buf, u8 **rx_buf)
{
void __iomem *tx_reg, *rx_reg, *int_reg;
struct orion_spi *orion_spi;
orion_spi = spi_master_get_devdata(spi->master);
tx_reg = spi_reg(orion_spi, ORION_SPI_DATA_OUT_REG);
rx_reg = spi_reg(orion_spi, ORION_SPI_DATA_IN_REG);
int_reg = spi_reg(orion_spi, ORION_SPI_INT_CAUSE_REG);
writel(0x0, int_reg);
if (tx_buf && *tx_buf)
writel(*(*tx_buf)++, tx_reg);
else
writel(0, tx_reg);
if (orion_spi_wait_till_ready(orion_spi) < 0) {
dev_err(&spi->dev, "TXS timed out\n");
return -1;
}
if (rx_buf && *rx_buf)
*(*rx_buf)++ = readl(rx_reg);
return 1;
}
static inline int
orion_spi_write_read_16bit(struct spi_device *spi,
const u16 **tx_buf, u16 **rx_buf)
{
void __iomem *tx_reg, *rx_reg, *int_reg;
struct orion_spi *orion_spi;
orion_spi = spi_master_get_devdata(spi->master);
tx_reg = spi_reg(orion_spi, ORION_SPI_DATA_OUT_REG);
rx_reg = spi_reg(orion_spi, ORION_SPI_DATA_IN_REG);
int_reg = spi_reg(orion_spi, ORION_SPI_INT_CAUSE_REG);
writel(0x0, int_reg);
if (tx_buf && *tx_buf)
writel(__cpu_to_le16(get_unaligned((*tx_buf)++)), tx_reg);
else
writel(0, tx_reg);
if (orion_spi_wait_till_ready(orion_spi) < 0) {
dev_err(&spi->dev, "TXS timed out\n");
return -1;
}
if (rx_buf && *rx_buf)
put_unaligned(__le16_to_cpu(readl(rx_reg)), (*rx_buf)++);
return 1;
}
static unsigned int
orion_spi_write_read(struct spi_device *spi, struct spi_transfer *xfer)
{
unsigned int count;
int word_len;
struct orion_spi *orion_spi;
int cs = spi->chip_select;
word_len = spi->bits_per_word;
count = xfer->len;
orion_spi = spi_master_get_devdata(spi->master);
if ((orion_spi->direct_access[cs].vaddr) && (xfer->tx_buf) &&
(word_len == 8)) {
unsigned int cnt = count / 4;
unsigned int rem = count % 4;
iowrite32_rep(orion_spi->direct_access[cs].vaddr,
xfer->tx_buf, cnt);
if (rem) {
u32 *buf = (u32 *)xfer->tx_buf;
iowrite8_rep(orion_spi->direct_access[cs].vaddr,
&buf[cnt], rem);
}
return count;
}
if (word_len == 8) {
const u8 *tx = xfer->tx_buf;
u8 *rx = xfer->rx_buf;
do {
if (orion_spi_write_read_8bit(spi, &tx, &rx) < 0)
goto out;
count--;
} while (count);
} else if (word_len == 16) {
const u16 *tx = xfer->tx_buf;
u16 *rx = xfer->rx_buf;
do {
if (orion_spi_write_read_16bit(spi, &tx, &rx) < 0)
goto out;
count -= 2;
} while (count);
}
out:
return xfer->len - count;
}
static int orion_spi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *t)
{
int status = 0;
status = orion_spi_setup_transfer(spi, t);
if (status < 0)
return status;
if (t->len)
orion_spi_write_read(spi, t);
return status;
}
static int orion_spi_setup(struct spi_device *spi)
{
return orion_spi_setup_transfer(spi, NULL);
}
static int orion_spi_reset(struct orion_spi *orion_spi)
{
orion_spi_clrbits(orion_spi, ORION_SPI_IF_CTRL_REG, 0x1);
writel(0, spi_reg(orion_spi, SPI_DIRECT_WRITE_CONFIG_REG));
return 0;
}
static int orion_spi_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
const struct orion_spi_dev *devdata;
struct spi_master *master;
struct orion_spi *spi;
struct resource *r;
unsigned long tclk_hz;
int status = 0;
struct device_node *np;
master = spi_alloc_master(&pdev->dev, sizeof(*spi));
if (master == NULL) {
dev_dbg(&pdev->dev, "master allocation failed\n");
return -ENOMEM;
}
if (pdev->id != -1)
master->bus_num = pdev->id;
if (pdev->dev.of_node) {
u32 cell_index;
if (!of_property_read_u32(pdev->dev.of_node, "cell-index",
&cell_index))
master->bus_num = cell_index;
}
master->mode_bits = SPI_CPHA | SPI_CPOL | SPI_LSB_FIRST;
master->set_cs = orion_spi_set_cs;
master->transfer_one = orion_spi_transfer_one;
master->num_chipselect = ORION_NUM_CHIPSELECTS;
master->setup = orion_spi_setup;
master->bits_per_word_mask = SPI_BPW_MASK(8) | SPI_BPW_MASK(16);
master->auto_runtime_pm = true;
master->flags = SPI_MASTER_GPIO_SS;
platform_set_drvdata(pdev, master);
spi = spi_master_get_devdata(master);
spi->master = master;
of_id = of_match_device(orion_spi_of_match_table, &pdev->dev);
devdata = (of_id) ? of_id->data : &orion_spi_dev_data;
spi->devdata = devdata;
spi->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(spi->clk)) {
status = PTR_ERR(spi->clk);
goto out;
}
status = clk_prepare_enable(spi->clk);
if (status)
goto out;
tclk_hz = clk_get_rate(spi->clk);
if (of_device_is_compatible(pdev->dev.of_node,
"marvell,armada-370-spi"))
master->max_speed_hz = min(devdata->max_hz,
DIV_ROUND_UP(tclk_hz, devdata->min_divisor));
else if (devdata->min_divisor)
master->max_speed_hz =
DIV_ROUND_UP(tclk_hz, devdata->min_divisor);
else
master->max_speed_hz = devdata->max_hz;
master->min_speed_hz = DIV_ROUND_UP(tclk_hz, devdata->max_divisor);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
spi->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(spi->base)) {
status = PTR_ERR(spi->base);
goto out_rel_clk;
}
for_each_available_child_of_node(pdev->dev.of_node, np) {
u32 cs;
status = of_property_read_u32(np, "reg", &cs);
if (status) {
dev_err(&pdev->dev,
"%pOF has no valid 'reg' property (%d)\n",
np, status);
status = 0;
continue;
}
status = of_address_to_resource(pdev->dev.of_node, cs + 1, r);
if (status)
continue;
spi->direct_access[cs].vaddr = devm_ioremap(&pdev->dev,
r->start,
PAGE_SIZE);
if (!spi->direct_access[cs].vaddr) {
status = -ENOMEM;
goto out_rel_clk;
}
spi->direct_access[cs].size = PAGE_SIZE;
dev_info(&pdev->dev, "CS%d configured for direct access\n", cs);
}
pm_runtime_set_active(&pdev->dev);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, SPI_AUTOSUSPEND_TIMEOUT);
pm_runtime_enable(&pdev->dev);
status = orion_spi_reset(spi);
if (status < 0)
goto out_rel_pm;
pm_runtime_mark_last_busy(&pdev->dev);
pm_runtime_put_autosuspend(&pdev->dev);
master->dev.of_node = pdev->dev.of_node;
status = spi_register_master(master);
if (status < 0)
goto out_rel_pm;
return status;
out_rel_pm:
pm_runtime_disable(&pdev->dev);
out_rel_clk:
clk_disable_unprepare(spi->clk);
out:
spi_master_put(master);
return status;
}
static int orion_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct orion_spi *spi = spi_master_get_devdata(master);
pm_runtime_get_sync(&pdev->dev);
clk_disable_unprepare(spi->clk);
spi_unregister_master(master);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int orion_spi_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct orion_spi *spi = spi_master_get_devdata(master);
clk_disable_unprepare(spi->clk);
return 0;
}
static int orion_spi_runtime_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct orion_spi *spi = spi_master_get_devdata(master);
return clk_prepare_enable(spi->clk);
}
