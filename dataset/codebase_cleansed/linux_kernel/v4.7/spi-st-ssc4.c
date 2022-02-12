static int spi_st_clk_enable(struct spi_st *spi_st)
{
return 0;
return clk_prepare_enable(spi_st->clk);
}
static void spi_st_clk_disable(struct spi_st *spi_st)
{
return;
clk_disable_unprepare(spi_st->clk);
}
static void ssc_write_tx_fifo(struct spi_st *spi_st)
{
unsigned int count, i;
uint32_t word = 0;
if (spi_st->words_remaining > FIFO_SIZE)
count = FIFO_SIZE;
else
count = spi_st->words_remaining;
for (i = 0; i < count; i++) {
if (spi_st->tx_ptr) {
if (spi_st->bytes_per_word == 1) {
word = *spi_st->tx_ptr++;
} else {
word = *spi_st->tx_ptr++;
word = *spi_st->tx_ptr++ | (word << 8);
}
}
writel_relaxed(word, spi_st->base + SSC_TBUF);
}
}
static void ssc_read_rx_fifo(struct spi_st *spi_st)
{
unsigned int count, i;
uint32_t word = 0;
if (spi_st->words_remaining > FIFO_SIZE)
count = FIFO_SIZE;
else
count = spi_st->words_remaining;
for (i = 0; i < count; i++) {
word = readl_relaxed(spi_st->base + SSC_RBUF);
if (spi_st->rx_ptr) {
if (spi_st->bytes_per_word == 1) {
*spi_st->rx_ptr++ = (uint8_t)word;
} else {
*spi_st->rx_ptr++ = (word >> 8);
*spi_st->rx_ptr++ = word & 0xff;
}
}
}
spi_st->words_remaining -= count;
}
static int spi_st_transfer_one(struct spi_master *master,
struct spi_device *spi, struct spi_transfer *t)
{
struct spi_st *spi_st = spi_master_get_devdata(master);
uint32_t ctl = 0;
spi_st->tx_ptr = t->tx_buf;
spi_st->rx_ptr = t->rx_buf;
if (spi->bits_per_word > 8) {
spi_st->bytes_per_word = 2;
spi_st->words_remaining = t->len / 2;
} else if (spi->bits_per_word == 8 && !(t->len & 0x1)) {
spi_st->bytes_per_word = 2;
spi_st->words_remaining = t->len / 2;
ctl = readl_relaxed(spi_st->base + SSC_CTL);
writel_relaxed((ctl | 0xf), spi_st->base + SSC_CTL);
readl_relaxed(spi_st->base + SSC_RBUF);
} else {
spi_st->bytes_per_word = 1;
spi_st->words_remaining = t->len;
}
reinit_completion(&spi_st->done);
ssc_write_tx_fifo(spi_st);
writel_relaxed(SSC_IEN_TEEN, spi_st->base + SSC_IEN);
wait_for_completion(&spi_st->done);
if (ctl)
writel_relaxed(ctl, spi_st->base + SSC_CTL);
spi_finalize_current_transfer(spi->master);
return t->len;
}
static void spi_st_cleanup(struct spi_device *spi)
{
int cs = spi->cs_gpio;
if (gpio_is_valid(cs))
devm_gpio_free(&spi->dev, cs);
}
static int spi_st_setup(struct spi_device *spi)
{
struct spi_st *spi_st = spi_master_get_devdata(spi->master);
u32 spi_st_clk, sscbrg, var;
u32 hz = spi->max_speed_hz;
int cs = spi->cs_gpio;
int ret;
if (!hz) {
dev_err(&spi->dev, "max_speed_hz unspecified\n");
return -EINVAL;
}
if (!gpio_is_valid(cs)) {
dev_err(&spi->dev, "%d is not a valid gpio\n", cs);
return -EINVAL;
}
if (devm_gpio_request(&spi->dev, cs, dev_name(&spi->dev))) {
dev_err(&spi->dev, "could not request gpio:%d\n", cs);
return -EINVAL;
}
ret = gpio_direction_output(cs, spi->mode & SPI_CS_HIGH);
if (ret)
return ret;
spi_st_clk = clk_get_rate(spi_st->clk);
sscbrg = spi_st_clk / (2 * hz);
if (sscbrg < 0x07 || sscbrg > BIT(16)) {
dev_err(&spi->dev,
"baudrate %d outside valid range %d\n", sscbrg, hz);
return -EINVAL;
}
spi_st->baud = spi_st_clk / (2 * sscbrg);
if (sscbrg == BIT(16))
sscbrg = 0x0;
writel_relaxed(sscbrg, spi_st->base + SSC_BRG);
dev_dbg(&spi->dev,
"setting baudrate:target= %u hz, actual= %u hz, sscbrg= %u\n",
hz, spi_st->baud, sscbrg);
var = readl_relaxed(spi_st->base + SSC_CTL);
var |= SSC_CTL_MS;
if (spi->mode & SPI_CPOL)
var |= SSC_CTL_PO;
else
var &= ~SSC_CTL_PO;
if (spi->mode & SPI_CPHA)
var |= SSC_CTL_PH;
else
var &= ~SSC_CTL_PH;
if ((spi->mode & SPI_LSB_FIRST) == 0)
var |= SSC_CTL_HB;
else
var &= ~SSC_CTL_HB;
if (spi->mode & SPI_LOOP)
var |= SSC_CTL_LPB;
else
var &= ~SSC_CTL_LPB;
var &= ~SSC_CTL_DATA_WIDTH_MSK;
var |= (spi->bits_per_word - 1);
var |= SSC_CTL_EN_TX_FIFO | SSC_CTL_EN_RX_FIFO;
var |= SSC_CTL_EN;
writel_relaxed(var, spi_st->base + SSC_CTL);
readl_relaxed(spi_st->base + SSC_RBUF);
return 0;
}
static irqreturn_t spi_st_irq(int irq, void *dev_id)
{
struct spi_st *spi_st = (struct spi_st *)dev_id;
ssc_read_rx_fifo(spi_st);
if (spi_st->words_remaining) {
ssc_write_tx_fifo(spi_st);
} else {
writel_relaxed(0x0, spi_st->base + SSC_IEN);
readl(spi_st->base + SSC_IEN);
complete(&spi_st->done);
}
return IRQ_HANDLED;
}
static int spi_st_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct spi_master *master;
struct resource *res;
struct spi_st *spi_st;
int irq, ret = 0;
u32 var;
master = spi_alloc_master(&pdev->dev, sizeof(*spi_st));
if (!master)
return -ENOMEM;
master->dev.of_node = np;
master->mode_bits = MODEBITS;
master->setup = spi_st_setup;
master->cleanup = spi_st_cleanup;
master->transfer_one = spi_st_transfer_one;
master->bits_per_word_mask = SPI_BPW_MASK(8) | SPI_BPW_MASK(16);
master->auto_runtime_pm = true;
master->bus_num = pdev->id;
spi_st = spi_master_get_devdata(master);
spi_st->clk = devm_clk_get(&pdev->dev, "ssc");
if (IS_ERR(spi_st->clk)) {
dev_err(&pdev->dev, "Unable to request clock\n");
ret = PTR_ERR(spi_st->clk);
goto put_master;
}
ret = spi_st_clk_enable(spi_st);
if (ret)
goto put_master;
init_completion(&spi_st->done);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
spi_st->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(spi_st->base)) {
ret = PTR_ERR(spi_st->base);
goto clk_disable;
}
writel_relaxed(0x0, spi_st->base + SSC_I2C);
var = readw_relaxed(spi_st->base + SSC_CTL);
var |= SSC_CTL_SR;
writel_relaxed(var, spi_st->base + SSC_CTL);
udelay(1);
var = readl_relaxed(spi_st->base + SSC_CTL);
var &= ~SSC_CTL_SR;
writel_relaxed(var, spi_st->base + SSC_CTL);
var = readl_relaxed(spi_st->base + SSC_CTL);
var &= ~SSC_CTL_MS;
writel_relaxed(var, spi_st->base + SSC_CTL);
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
dev_err(&pdev->dev, "IRQ missing or invalid\n");
ret = -EINVAL;
goto clk_disable;
}
ret = devm_request_irq(&pdev->dev, irq, spi_st_irq, 0,
pdev->name, spi_st);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq %d\n", irq);
goto clk_disable;
}
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
platform_set_drvdata(pdev, master);
ret = devm_spi_register_master(&pdev->dev, master);
if (ret) {
dev_err(&pdev->dev, "Failed to register master\n");
goto clk_disable;
}
return 0;
clk_disable:
spi_st_clk_disable(spi_st);
put_master:
spi_master_put(master);
return ret;
}
static int spi_st_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct spi_st *spi_st = spi_master_get_devdata(master);
spi_st_clk_disable(spi_st);
pinctrl_pm_select_sleep_state(&pdev->dev);
return 0;
}
static int spi_st_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct spi_st *spi_st = spi_master_get_devdata(master);
writel_relaxed(0, spi_st->base + SSC_IEN);
pinctrl_pm_select_sleep_state(dev);
spi_st_clk_disable(spi_st);
return 0;
}
static int spi_st_runtime_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct spi_st *spi_st = spi_master_get_devdata(master);
int ret;
ret = spi_st_clk_enable(spi_st);
pinctrl_pm_select_default_state(dev);
return ret;
}
static int spi_st_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
int ret;
ret = spi_master_suspend(master);
if (ret)
return ret;
return pm_runtime_force_suspend(dev);
}
static int spi_st_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
int ret;
ret = spi_master_resume(master);
if (ret)
return ret;
return pm_runtime_force_resume(dev);
}
