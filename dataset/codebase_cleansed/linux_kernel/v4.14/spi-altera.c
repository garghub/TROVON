static inline struct altera_spi *altera_spi_to_hw(struct spi_device *sdev)
{
return spi_master_get_devdata(sdev->master);
}
static void altera_spi_set_cs(struct spi_device *spi, bool is_high)
{
struct altera_spi *hw = altera_spi_to_hw(spi);
if (is_high) {
hw->imr &= ~ALTERA_SPI_CONTROL_SSO_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
writel(0, hw->base + ALTERA_SPI_SLAVE_SEL);
} else {
writel(BIT(spi->chip_select), hw->base + ALTERA_SPI_SLAVE_SEL);
hw->imr |= ALTERA_SPI_CONTROL_SSO_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
}
}
static void altera_spi_tx_word(struct altera_spi *hw)
{
unsigned int txd = 0;
if (hw->tx) {
switch (hw->bytes_per_word) {
case 1:
txd = hw->tx[hw->count];
break;
case 2:
txd = (hw->tx[hw->count * 2]
| (hw->tx[hw->count * 2 + 1] << 8));
break;
}
}
writel(txd, hw->base + ALTERA_SPI_TXDATA);
}
static void altera_spi_rx_word(struct altera_spi *hw)
{
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
}
static int altera_spi_txrx(struct spi_master *master,
struct spi_device *spi, struct spi_transfer *t)
{
struct altera_spi *hw = spi_master_get_devdata(master);
hw->tx = t->tx_buf;
hw->rx = t->rx_buf;
hw->count = 0;
hw->bytes_per_word = DIV_ROUND_UP(t->bits_per_word, 8);
hw->len = t->len / hw->bytes_per_word;
if (hw->irq >= 0) {
hw->imr |= ALTERA_SPI_CONTROL_IRRDY_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
altera_spi_tx_word(hw);
} else {
while (hw->count < hw->len) {
altera_spi_tx_word(hw);
while (!(readl(hw->base + ALTERA_SPI_STATUS) &
ALTERA_SPI_STATUS_RRDY_MSK))
cpu_relax();
altera_spi_rx_word(hw);
}
spi_finalize_current_transfer(master);
}
return t->len;
}
static irqreturn_t altera_spi_irq(int irq, void *dev)
{
struct spi_master *master = dev;
struct altera_spi *hw = spi_master_get_devdata(master);
altera_spi_rx_word(hw);
if (hw->count < hw->len) {
altera_spi_tx_word(hw);
} else {
hw->imr &= ~ALTERA_SPI_CONTROL_IRRDY_MSK;
writel(hw->imr, hw->base + ALTERA_SPI_CONTROL);
spi_finalize_current_transfer(master);
}
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
master->transfer_one = altera_spi_txrx;
master->set_cs = altera_spi_set_cs;
hw = spi_master_get_devdata(master);
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
err = devm_request_irq(&pdev->dev, hw->irq, altera_spi_irq, 0,
pdev->name, master);
if (err)
goto exit;
}
err = devm_spi_register_master(&pdev->dev, master);
if (err)
goto exit;
dev_info(&pdev->dev, "base %p, irq %d\n", hw->base, hw->irq);
return 0;
exit:
spi_master_put(master);
return err;
}
