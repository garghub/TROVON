static inline u32 cdns_spi_read(struct cdns_spi *xspi, u32 offset)
{
return readl_relaxed(xspi->regs + offset);
}
static inline void cdns_spi_write(struct cdns_spi *xspi, u32 offset, u32 val)
{
writel_relaxed(val, xspi->regs + offset);
}
static void cdns_spi_init_hw(struct cdns_spi *xspi)
{
u32 ctrl_reg = CDNS_SPI_CR_DEFAULT;
if (xspi->is_decoded_cs)
ctrl_reg |= CDNS_SPI_CR_PERI_SEL;
cdns_spi_write(xspi, CDNS_SPI_ER, CDNS_SPI_ER_DISABLE);
cdns_spi_write(xspi, CDNS_SPI_IDR, CDNS_SPI_IXR_ALL);
while (cdns_spi_read(xspi, CDNS_SPI_ISR) & CDNS_SPI_IXR_RXNEMTY)
cdns_spi_read(xspi, CDNS_SPI_RXD);
cdns_spi_write(xspi, CDNS_SPI_ISR, CDNS_SPI_IXR_ALL);
cdns_spi_write(xspi, CDNS_SPI_CR, ctrl_reg);
cdns_spi_write(xspi, CDNS_SPI_ER, CDNS_SPI_ER_ENABLE);
}
static void cdns_spi_chipselect(struct spi_device *spi, bool is_high)
{
struct cdns_spi *xspi = spi_master_get_devdata(spi->master);
u32 ctrl_reg;
ctrl_reg = cdns_spi_read(xspi, CDNS_SPI_CR);
if (is_high) {
ctrl_reg |= CDNS_SPI_CR_SSCTRL;
} else {
ctrl_reg &= ~CDNS_SPI_CR_SSCTRL;
if (!(xspi->is_decoded_cs))
ctrl_reg |= ((~(CDNS_SPI_SS0 << spi->chip_select)) <<
CDNS_SPI_SS_SHIFT) &
CDNS_SPI_CR_SSCTRL;
else
ctrl_reg |= (spi->chip_select << CDNS_SPI_SS_SHIFT) &
CDNS_SPI_CR_SSCTRL;
}
cdns_spi_write(xspi, CDNS_SPI_CR, ctrl_reg);
}
static void cdns_spi_config_clock_mode(struct spi_device *spi)
{
struct cdns_spi *xspi = spi_master_get_devdata(spi->master);
u32 ctrl_reg, new_ctrl_reg;
new_ctrl_reg = cdns_spi_read(xspi, CDNS_SPI_CR);
ctrl_reg = new_ctrl_reg;
new_ctrl_reg &= ~(CDNS_SPI_CR_CPHA | CDNS_SPI_CR_CPOL);
if (spi->mode & SPI_CPHA)
new_ctrl_reg |= CDNS_SPI_CR_CPHA;
if (spi->mode & SPI_CPOL)
new_ctrl_reg |= CDNS_SPI_CR_CPOL;
if (new_ctrl_reg != ctrl_reg) {
cdns_spi_write(xspi, CDNS_SPI_ER, CDNS_SPI_ER_DISABLE);
cdns_spi_write(xspi, CDNS_SPI_CR, new_ctrl_reg);
cdns_spi_write(xspi, CDNS_SPI_ER, CDNS_SPI_ER_ENABLE);
}
}
static void cdns_spi_config_clock_freq(struct spi_device *spi,
struct spi_transfer *transfer)
{
struct cdns_spi *xspi = spi_master_get_devdata(spi->master);
u32 ctrl_reg, baud_rate_val;
unsigned long frequency;
frequency = clk_get_rate(xspi->ref_clk);
ctrl_reg = cdns_spi_read(xspi, CDNS_SPI_CR);
if (xspi->speed_hz != transfer->speed_hz) {
baud_rate_val = CDNS_SPI_BAUD_DIV_MIN;
while ((baud_rate_val < CDNS_SPI_BAUD_DIV_MAX) &&
(frequency / (2 << baud_rate_val)) > transfer->speed_hz)
baud_rate_val++;
ctrl_reg &= ~CDNS_SPI_CR_BAUD_DIV;
ctrl_reg |= baud_rate_val << CDNS_SPI_BAUD_DIV_SHIFT;
xspi->speed_hz = frequency / (2 << baud_rate_val);
}
cdns_spi_write(xspi, CDNS_SPI_CR, ctrl_reg);
}
static int cdns_spi_setup_transfer(struct spi_device *spi,
struct spi_transfer *transfer)
{
struct cdns_spi *xspi = spi_master_get_devdata(spi->master);
cdns_spi_config_clock_freq(spi, transfer);
dev_dbg(&spi->dev, "%s, mode %d, %u bits/w, %u clock speed\n",
__func__, spi->mode, spi->bits_per_word,
xspi->speed_hz);
return 0;
}
static void cdns_spi_fill_tx_fifo(struct cdns_spi *xspi)
{
unsigned long trans_cnt = 0;
while ((trans_cnt < CDNS_SPI_FIFO_DEPTH) &&
(xspi->tx_bytes > 0)) {
if (xspi->txbuf)
cdns_spi_write(xspi, CDNS_SPI_TXD, *xspi->txbuf++);
else
cdns_spi_write(xspi, CDNS_SPI_TXD, 0);
xspi->tx_bytes--;
trans_cnt++;
}
}
static irqreturn_t cdns_spi_irq(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct cdns_spi *xspi = spi_master_get_devdata(master);
u32 intr_status, status;
status = IRQ_NONE;
intr_status = cdns_spi_read(xspi, CDNS_SPI_ISR);
cdns_spi_write(xspi, CDNS_SPI_ISR, intr_status);
if (intr_status & CDNS_SPI_IXR_MODF) {
cdns_spi_write(xspi, CDNS_SPI_IDR, CDNS_SPI_IXR_DEFAULT);
spi_finalize_current_transfer(master);
status = IRQ_HANDLED;
} else if (intr_status & CDNS_SPI_IXR_TXOW) {
unsigned long trans_cnt;
trans_cnt = xspi->rx_bytes - xspi->tx_bytes;
while (trans_cnt) {
u8 data;
data = cdns_spi_read(xspi, CDNS_SPI_RXD);
if (xspi->rxbuf)
*xspi->rxbuf++ = data;
xspi->rx_bytes--;
trans_cnt--;
}
if (xspi->tx_bytes) {
cdns_spi_fill_tx_fifo(xspi);
} else {
cdns_spi_write(xspi, CDNS_SPI_IDR,
CDNS_SPI_IXR_DEFAULT);
spi_finalize_current_transfer(master);
}
status = IRQ_HANDLED;
}
return status;
}
static int cdns_prepare_message(struct spi_master *master,
struct spi_message *msg)
{
cdns_spi_config_clock_mode(msg->spi);
return 0;
}
static int cdns_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *transfer)
{
struct cdns_spi *xspi = spi_master_get_devdata(master);
xspi->txbuf = transfer->tx_buf;
xspi->rxbuf = transfer->rx_buf;
xspi->tx_bytes = transfer->len;
xspi->rx_bytes = transfer->len;
cdns_spi_setup_transfer(spi, transfer);
cdns_spi_fill_tx_fifo(xspi);
cdns_spi_write(xspi, CDNS_SPI_IER, CDNS_SPI_IXR_DEFAULT);
return transfer->len;
}
static int cdns_prepare_transfer_hardware(struct spi_master *master)
{
struct cdns_spi *xspi = spi_master_get_devdata(master);
cdns_spi_write(xspi, CDNS_SPI_ER, CDNS_SPI_ER_ENABLE);
return 0;
}
static int cdns_unprepare_transfer_hardware(struct spi_master *master)
{
struct cdns_spi *xspi = spi_master_get_devdata(master);
cdns_spi_write(xspi, CDNS_SPI_ER, CDNS_SPI_ER_DISABLE);
return 0;
}
static int cdns_spi_setup(struct spi_device *spi)
{
int ret = -EINVAL;
struct cdns_spi_device_data *cdns_spi_data = spi_get_ctldata(spi);
if (spi->cs_gpio == -ENOENT)
return 0;
if (!cdns_spi_data) {
cdns_spi_data = kzalloc(sizeof(*cdns_spi_data), GFP_KERNEL);
if (!cdns_spi_data)
return -ENOMEM;
cdns_spi_data->gpio_requested = false;
spi_set_ctldata(spi, cdns_spi_data);
}
if (!cdns_spi_data->gpio_requested && gpio_is_valid(spi->cs_gpio)) {
ret = gpio_request_one(spi->cs_gpio,
(spi->mode & SPI_CS_HIGH) ?
GPIOF_OUT_INIT_LOW : GPIOF_OUT_INIT_HIGH,
dev_name(&spi->dev));
if (ret)
dev_err(&spi->dev, "can't request chipselect gpio %d\n",
spi->cs_gpio);
else
cdns_spi_data->gpio_requested = true;
} else {
if (gpio_is_valid(spi->cs_gpio)) {
int mode = ((spi->mode & SPI_CS_HIGH) ?
GPIOF_OUT_INIT_LOW : GPIOF_OUT_INIT_HIGH);
ret = gpio_direction_output(spi->cs_gpio, mode);
if (ret)
dev_err(&spi->dev, "chipselect gpio %d setup failed (%d)\n",
spi->cs_gpio, ret);
}
}
return ret;
}
static void cdns_spi_cleanup(struct spi_device *spi)
{
struct cdns_spi_device_data *cdns_spi_data = spi_get_ctldata(spi);
if (cdns_spi_data) {
if (cdns_spi_data->gpio_requested)
gpio_free(spi->cs_gpio);
kfree(cdns_spi_data);
spi_set_ctldata(spi, NULL);
}
}
static int cdns_spi_probe(struct platform_device *pdev)
{
int ret = 0, irq;
struct spi_master *master;
struct cdns_spi *xspi;
struct resource *res;
u32 num_cs;
master = spi_alloc_master(&pdev->dev, sizeof(*xspi));
if (!master)
return -ENOMEM;
xspi = spi_master_get_devdata(master);
master->dev.of_node = pdev->dev.of_node;
platform_set_drvdata(pdev, master);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xspi->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xspi->regs)) {
ret = PTR_ERR(xspi->regs);
goto remove_master;
}
xspi->pclk = devm_clk_get(&pdev->dev, "pclk");
if (IS_ERR(xspi->pclk)) {
dev_err(&pdev->dev, "pclk clock not found.\n");
ret = PTR_ERR(xspi->pclk);
goto remove_master;
}
xspi->ref_clk = devm_clk_get(&pdev->dev, "ref_clk");
if (IS_ERR(xspi->ref_clk)) {
dev_err(&pdev->dev, "ref_clk clock not found.\n");
ret = PTR_ERR(xspi->ref_clk);
goto remove_master;
}
ret = clk_prepare_enable(xspi->pclk);
if (ret) {
dev_err(&pdev->dev, "Unable to enable APB clock.\n");
goto remove_master;
}
ret = clk_prepare_enable(xspi->ref_clk);
if (ret) {
dev_err(&pdev->dev, "Unable to enable device clock.\n");
goto clk_dis_apb;
}
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, SPI_AUTOSUSPEND_TIMEOUT);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
ret = of_property_read_u32(pdev->dev.of_node, "num-cs", &num_cs);
if (ret < 0)
master->num_chipselect = CDNS_SPI_DEFAULT_NUM_CS;
else
master->num_chipselect = num_cs;
ret = of_property_read_u32(pdev->dev.of_node, "is-decoded-cs",
&xspi->is_decoded_cs);
if (ret < 0)
xspi->is_decoded_cs = 0;
cdns_spi_init_hw(xspi);
pm_runtime_mark_last_busy(&pdev->dev);
pm_runtime_put_autosuspend(&pdev->dev);
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
ret = -ENXIO;
dev_err(&pdev->dev, "irq number is invalid\n");
goto clk_dis_all;
}
ret = devm_request_irq(&pdev->dev, irq, cdns_spi_irq,
0, pdev->name, master);
if (ret != 0) {
ret = -ENXIO;
dev_err(&pdev->dev, "request_irq failed\n");
goto clk_dis_all;
}
master->prepare_transfer_hardware = cdns_prepare_transfer_hardware;
master->prepare_message = cdns_prepare_message;
master->transfer_one = cdns_transfer_one;
master->unprepare_transfer_hardware = cdns_unprepare_transfer_hardware;
master->set_cs = cdns_spi_chipselect;
master->setup = cdns_spi_setup;
master->cleanup = cdns_spi_cleanup;
master->auto_runtime_pm = true;
master->mode_bits = SPI_CPOL | SPI_CPHA;
master->max_speed_hz = clk_get_rate(xspi->ref_clk) / 4;
xspi->speed_hz = master->max_speed_hz;
master->bits_per_word_mask = SPI_BPW_MASK(8);
ret = spi_register_master(master);
if (ret) {
dev_err(&pdev->dev, "spi_register_master failed\n");
goto clk_dis_all;
}
return ret;
clk_dis_all:
pm_runtime_set_suspended(&pdev->dev);
pm_runtime_disable(&pdev->dev);
clk_disable_unprepare(xspi->ref_clk);
clk_dis_apb:
clk_disable_unprepare(xspi->pclk);
remove_master:
spi_master_put(master);
return ret;
}
static int cdns_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct cdns_spi *xspi = spi_master_get_devdata(master);
cdns_spi_write(xspi, CDNS_SPI_ER, CDNS_SPI_ER_DISABLE);
clk_disable_unprepare(xspi->ref_clk);
clk_disable_unprepare(xspi->pclk);
pm_runtime_set_suspended(&pdev->dev);
pm_runtime_disable(&pdev->dev);
spi_unregister_master(master);
return 0;
}
static int __maybe_unused cdns_spi_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct spi_master *master = platform_get_drvdata(pdev);
return spi_master_suspend(master);
}
static int __maybe_unused cdns_spi_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct spi_master *master = platform_get_drvdata(pdev);
struct cdns_spi *xspi = spi_master_get_devdata(master);
cdns_spi_init_hw(xspi);
return spi_master_resume(master);
}
static int __maybe_unused cnds_runtime_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct cdns_spi *xspi = spi_master_get_devdata(master);
int ret;
ret = clk_prepare_enable(xspi->pclk);
if (ret) {
dev_err(dev, "Cannot enable APB clock.\n");
return ret;
}
ret = clk_prepare_enable(xspi->ref_clk);
if (ret) {
dev_err(dev, "Cannot enable device clock.\n");
clk_disable(xspi->pclk);
return ret;
}
return 0;
}
static int __maybe_unused cnds_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct cdns_spi *xspi = spi_master_get_devdata(master);
clk_disable_unprepare(xspi->ref_clk);
clk_disable_unprepare(xspi->pclk);
return 0;
}
