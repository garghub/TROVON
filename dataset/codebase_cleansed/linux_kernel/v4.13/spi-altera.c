static inline struct altera_spi *altera_spi_to_hw(struct spi_device *sdev)
{
return spi_master_get_devdata(sdev->master);
}
static void altera_spi_chipsel(struct spi_device *spi, int value)
{
struct altera_spi *hw = altera_spi_to_hw(spi);
if (spi->mode & SPI_CS_HIGH) {
switch (value) {
case BITBANG_CS_INACTIVE:
writel(1 << spi->chip_select,
hw->base + ALTERA_SPI_SLAVE_SEL);
hw->imr |= ALTERA_SPI_CONTROL_SSO_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
break;
case BITBANG_CS_ACTIVE:
hw->imr &= ~ALTERA_SPI_CONTROL_SSO_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
writel(0, hw->base + ALTERA_SPI_SLAVE_SEL);
break;
}
} else {
switch (value) {
case BITBANG_CS_INACTIVE:
hw->imr &= ~ALTERA_SPI_CONTROL_SSO_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
break;
case BITBANG_CS_ACTIVE:
writel(1 << spi->chip_select,
hw->base + ALTERA_SPI_SLAVE_SEL);
hw->imr |= ALTERA_SPI_CONTROL_SSO_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
break;
}
}
}
static inline unsigned int hw_txbyte(struct altera_spi *hw, int count)
{
if (hw->tx) {
switch (hw->bytes_per_word) {
case 1:
return hw->tx[count];
case 2:
return (hw->tx[count * 2]
| (hw->tx[count * 2 + 1] << 8));
}
}
return 0;
}
static int altera_spi_txrx(struct spi_device *spi, struct spi_transfer *t)
{
struct altera_spi *hw = altera_spi_to_hw(spi);
hw->tx = t->tx_buf;
hw->rx = t->rx_buf;
hw->count = 0;
hw->bytes_per_word = DIV_ROUND_UP(t->bits_per_word, 8);
hw->len = t->len / hw->bytes_per_word;
if (hw->irq >= 0) {
hw->imr |= ALTERA_SPI_CONTROL_IRRDY_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
writel(hw_txbyte(hw, 0), hw->base + ALTERA_SPI_TXDATA);
wait_for_completion(&hw->done);
hw->imr &= ~ALTERA_SPI_CONTROL_IRRDY_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
} else {
while (hw->count < hw->len) {
unsigned int rxd;
writel(hw_txbyte(hw, hw->count),
hw->base + ALTERA_SPI_TXDATA);
while (!(readl(hw->base + ALTERA_SPI_STATUS) &
ALTERA_SPI_STATUS_RRDY_MSK))
cpu_relax();
rxd = readl(hw->base + ALTERA_SPI_RXDATA);
if (hw->rx) {
switch (hw->bytes_per_word) {
case 1:
hw->rx[hw->count] = rxd;
break;
case 2:
hw->rx[hw->count * 2] = rxd;
hw->rx[hw->count * 2 + 1] = rxd >> 8;
break;
}
}
hw->count++;
}
}
return hw->count * hw->bytes_per_word;
}
static irqreturn_t altera_spi_irq(int irq, void *dev)
{
struct altera_spi *hw = dev;
unsigned int rxd;
rxd = readl(hw->base + ALTERA_SPI_RXDATA);
if (hw->rx) {
switch (hw->bytes_per_word) {
case 1:
hw->rx[hw->count] = rxd;
break;
case 2:
hw->rx[hw->count * 2] = rxd;
hw->rx[hw->count * 2 + 1] = rxd >> 8;
break;
}
}
hw->count++;
if (hw->count < hw->len)
writel(hw_txbyte(hw, hw->count), hw->base + ALTERA_SPI_TXDATA);
else
complete(&hw->done);
return IRQ_HANDLED;
}
static int altera_spi_probe(struct platform_device *pdev)
{
struct altera_spi *hw;
struct spi_master *master;
struct resource *res;
int err = -ENODEV;
master = spi_alloc_master(&pdev->dev, sizeof(struct altera_spi));
if (!master)
return err;
master->bus_num = pdev->id;
master->num_chipselect = 16;
master->mode_bits = SPI_CS_HIGH;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(1, 16);
master->dev.of_node = pdev->dev.of_node;
hw = spi_master_get_devdata(master);
platform_set_drvdata(pdev, hw);
hw->bitbang.master = master;
hw->bitbang.chipselect = altera_spi_chipsel;
hw->bitbang.txrx_bufs = altera_spi_txrx;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hw->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hw->base)) {
err = PTR_ERR(hw->base);
goto exit;
}
hw->imr = 0;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
writel(0, hw->base + ALTERA_SPI_STATUS);
if (readl(hw->base + ALTERA_SPI_STATUS) & ALTERA_SPI_STATUS_RRDY_MSK)
readl(hw->base + ALTERA_SPI_RXDATA);
hw->irq = platform_get_irq(pdev, 0);
if (hw->irq >= 0) {
init_completion(&hw->done);
err = devm_request_irq(&pdev->dev, hw->irq, altera_spi_irq, 0,
pdev->name, hw);
if (err)
goto exit;
}
err = spi_bitbang_start(&hw->bitbang);
if (err)
goto exit;
dev_info(&pdev->dev, "base %p, irq %d\n", hw->base, hw->irq);
return 0;
exit:
spi_master_put(master);
return err;
}
static int altera_spi_remove(struct platform_device *dev)
{
struct altera_spi *hw = platform_get_drvdata(dev);
struct spi_master *master = hw->bitbang.master;
spi_bitbang_stop(&hw->bitbang);
spi_master_put(master);
return 0;
}
