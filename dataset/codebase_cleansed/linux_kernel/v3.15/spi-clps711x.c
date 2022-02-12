static int spi_clps711x_setup(struct spi_device *spi)
{
gpio_direction_output(spi->cs_gpio, !(spi->mode & SPI_CS_HIGH));
return 0;
}
static void spi_clps711x_setup_xfer(struct spi_device *spi,
struct spi_transfer *xfer)
{
struct spi_master *master = spi->master;
struct spi_clps711x_data *hw = spi_master_get_devdata(master);
if (xfer->speed_hz >= master->max_speed_hz)
regmap_update_bits(hw->syscon1, SYSCON_OFFSET,
SYSCON1_ADCKSEL_MASK, SYSCON1_ADCKSEL(3));
else if (xfer->speed_hz >= (master->max_speed_hz / 2))
regmap_update_bits(hw->syscon1, SYSCON_OFFSET,
SYSCON1_ADCKSEL_MASK, SYSCON1_ADCKSEL(2));
else if (xfer->speed_hz >= (master->max_speed_hz / 8))
regmap_update_bits(hw->syscon1, SYSCON_OFFSET,
SYSCON1_ADCKSEL_MASK, SYSCON1_ADCKSEL(1));
else
regmap_update_bits(hw->syscon1, SYSCON_OFFSET,
SYSCON1_ADCKSEL_MASK, SYSCON1_ADCKSEL(0));
}
static int spi_clps711x_prepare_message(struct spi_master *master,
struct spi_message *msg)
{
struct spi_clps711x_data *hw = spi_master_get_devdata(master);
struct spi_device *spi = msg->spi;
return regmap_update_bits(hw->syscon, SYSCON_OFFSET, SYSCON3_ADCCKNSEN,
(spi->mode & SPI_CPHA) ?
SYSCON3_ADCCKNSEN : 0);
}
static int spi_clps711x_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct spi_clps711x_data *hw = spi_master_get_devdata(master);
u8 data;
spi_clps711x_setup_xfer(spi, xfer);
hw->len = xfer->len;
hw->bpw = xfer->bits_per_word;
hw->tx_buf = (u8 *)xfer->tx_buf;
hw->rx_buf = (u8 *)xfer->rx_buf;
data = hw->tx_buf ? *hw->tx_buf++ : 0;
writel(data | SYNCIO_FRMLEN(hw->bpw) | SYNCIO_TXFRMEN, hw->syncio);
return 1;
}
static irqreturn_t spi_clps711x_isr(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct spi_clps711x_data *hw = spi_master_get_devdata(master);
u8 data;
data = readb(hw->syncio);
if (hw->rx_buf)
*hw->rx_buf++ = data;
if (--hw->len > 0) {
data = hw->tx_buf ? *hw->tx_buf++ : 0;
writel(data | SYNCIO_FRMLEN(hw->bpw) | SYNCIO_TXFRMEN,
hw->syncio);
} else
spi_finalize_current_transfer(master);
return IRQ_HANDLED;
}
static int spi_clps711x_probe(struct platform_device *pdev)
{
struct spi_clps711x_data *hw;
struct spi_clps711x_pdata *pdata = dev_get_platdata(&pdev->dev);
struct spi_master *master;
struct resource *res;
int i, irq, ret;
if (!pdata) {
dev_err(&pdev->dev, "No platform data supplied\n");
return -EINVAL;
}
if (pdata->num_chipselect < 1) {
dev_err(&pdev->dev, "At least one CS must be defined\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
master = spi_alloc_master(&pdev->dev, sizeof(*hw));
if (!master)
return -ENOMEM;
master->cs_gpios = devm_kzalloc(&pdev->dev, sizeof(int) *
pdata->num_chipselect, GFP_KERNEL);
if (!master->cs_gpios) {
ret = -ENOMEM;
goto err_out;
}
master->bus_num = pdev->id;
master->mode_bits = SPI_CPHA | SPI_CS_HIGH;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(1, 8);
master->num_chipselect = pdata->num_chipselect;
master->setup = spi_clps711x_setup;
master->prepare_message = spi_clps711x_prepare_message;
master->transfer_one = spi_clps711x_transfer_one;
hw = spi_master_get_devdata(master);
for (i = 0; i < master->num_chipselect; i++) {
master->cs_gpios[i] = pdata->chipselect[i];
ret = devm_gpio_request(&pdev->dev, master->cs_gpios[i],
DRIVER_NAME);
if (ret) {
dev_err(&pdev->dev, "Can't get CS GPIO %i\n", i);
goto err_out;
}
}
hw->spi_clk = devm_clk_get(&pdev->dev, "spi");
if (IS_ERR(hw->spi_clk)) {
dev_err(&pdev->dev, "Can't get clocks\n");
ret = PTR_ERR(hw->spi_clk);
goto err_out;
}
master->max_speed_hz = clk_get_rate(hw->spi_clk);
platform_set_drvdata(pdev, master);
hw->syscon = syscon_regmap_lookup_by_pdevname("syscon.3");
if (IS_ERR(hw->syscon)) {
ret = PTR_ERR(hw->syscon);
goto err_out;
}
hw->syscon1 = syscon_regmap_lookup_by_pdevname("syscon.1");
if (IS_ERR(hw->syscon1)) {
ret = PTR_ERR(hw->syscon1);
goto err_out;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hw->syncio = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hw->syncio)) {
ret = PTR_ERR(hw->syncio);
goto err_out;
}
regmap_update_bits(hw->syscon, SYSCON_OFFSET, SYSCON3_ADCCON, 0);
readl(hw->syncio);
ret = devm_request_irq(&pdev->dev, irq, spi_clps711x_isr, 0,
dev_name(&pdev->dev), master);
if (ret)
goto err_out;
ret = devm_spi_register_master(&pdev->dev, master);
if (!ret) {
dev_info(&pdev->dev,
"SPI bus driver initialized. Master clock %u Hz\n",
master->max_speed_hz);
return 0;
}
dev_err(&pdev->dev, "Failed to register master\n");
err_out:
spi_master_put(master);
return ret;
}
