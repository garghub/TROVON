static inline void xtfpga_spi_write32(const struct xtfpga_spi *spi,
unsigned addr, u32 val)
{
iowrite32(val, spi->regs + addr);
}
static inline unsigned int xtfpga_spi_read32(const struct xtfpga_spi *spi,
unsigned addr)
{
return ioread32(spi->regs + addr);
}
static inline void xtfpga_spi_wait_busy(struct xtfpga_spi *xspi)
{
unsigned i;
for (i = 0; xtfpga_spi_read32(xspi, XTFPGA_SPI_BUSY) &&
i < BUSY_WAIT_US; ++i)
udelay(1);
WARN_ON_ONCE(i == BUSY_WAIT_US);
}
static u32 xtfpga_spi_txrx_word(struct spi_device *spi, unsigned nsecs,
u32 v, u8 bits)
{
struct xtfpga_spi *xspi = spi_master_get_devdata(spi->master);
xspi->data = (xspi->data << bits) | (v & GENMASK(bits - 1, 0));
xspi->data_sz += bits;
if (xspi->data_sz >= 16) {
xtfpga_spi_write32(xspi, XTFPGA_SPI_DATA,
xspi->data >> (xspi->data_sz - 16));
xspi->data_sz -= 16;
xtfpga_spi_write32(xspi, XTFPGA_SPI_START, 1);
xtfpga_spi_wait_busy(xspi);
xtfpga_spi_write32(xspi, XTFPGA_SPI_START, 0);
}
return 0;
}
static void xtfpga_spi_chipselect(struct spi_device *spi, int is_on)
{
struct xtfpga_spi *xspi = spi_master_get_devdata(spi->master);
WARN_ON(xspi->data_sz != 0);
xspi->data_sz = 0;
}
static int xtfpga_spi_probe(struct platform_device *pdev)
{
struct xtfpga_spi *xspi;
struct resource *mem;
int ret;
struct spi_master *master;
master = spi_alloc_master(&pdev->dev, sizeof(struct xtfpga_spi));
if (!master)
return -ENOMEM;
master->flags = SPI_MASTER_NO_RX;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(1, 16);
master->bus_num = pdev->dev.id;
master->dev.of_node = pdev->dev.of_node;
xspi = spi_master_get_devdata(master);
xspi->bitbang.master = master;
xspi->bitbang.chipselect = xtfpga_spi_chipselect;
xspi->bitbang.txrx_word[SPI_MODE_0] = xtfpga_spi_txrx_word;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "No memory resource\n");
ret = -ENODEV;
goto err;
}
xspi->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(xspi->regs)) {
ret = PTR_ERR(xspi->regs);
goto err;
}
xtfpga_spi_write32(xspi, XTFPGA_SPI_START, 0);
usleep_range(1000, 2000);
if (xtfpga_spi_read32(xspi, XTFPGA_SPI_BUSY)) {
dev_err(&pdev->dev, "Device stuck in busy state\n");
ret = -EBUSY;
goto err;
}
ret = spi_bitbang_start(&xspi->bitbang);
if (ret < 0) {
dev_err(&pdev->dev, "spi_bitbang_start failed\n");
goto err;
}
platform_set_drvdata(pdev, master);
return 0;
err:
spi_master_put(master);
return ret;
}
static int xtfpga_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct xtfpga_spi *xspi = spi_master_get_devdata(master);
spi_bitbang_stop(&xspi->bitbang);
spi_master_put(master);
return 0;
}
