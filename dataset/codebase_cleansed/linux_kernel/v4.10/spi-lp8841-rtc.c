static inline void
setsck(struct spi_lp8841_rtc *data, int is_on)
{
if (is_on)
data->state |= SPI_LP8841_RTC_CLK;
else
data->state &= ~SPI_LP8841_RTC_CLK;
writeb(data->state, data->iomem);
}
static inline void
setmosi(struct spi_lp8841_rtc *data, int is_on)
{
if (is_on)
data->state |= SPI_LP8841_RTC_MOSI;
else
data->state &= ~SPI_LP8841_RTC_MOSI;
writeb(data->state, data->iomem);
}
static inline int
getmiso(struct spi_lp8841_rtc *data)
{
return ioread8(data->iomem) & SPI_LP8841_RTC_MISO;
}
static inline u32
bitbang_txrx_be_cpha0_lsb(struct spi_lp8841_rtc *data,
unsigned usecs, unsigned cpol, unsigned flags,
u32 word, u8 bits)
{
u32 shift = 32 - bits;
for (; likely(bits); bits--) {
if ((flags & SPI_MASTER_NO_TX) == 0)
setmosi(data, (word & 1));
usleep_range(usecs, usecs + 1);
word >>= 1;
if ((flags & SPI_MASTER_NO_RX) == 0)
word |= (getmiso(data) << 31);
setsck(data, !cpol);
usleep_range(usecs, usecs + 1);
setsck(data, cpol);
}
word >>= shift;
return word;
}
static int
spi_lp8841_rtc_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *t)
{
struct spi_lp8841_rtc *data = spi_master_get_devdata(master);
unsigned count = t->len;
const u8 *tx = t->tx_buf;
u8 *rx = t->rx_buf;
u8 word = 0;
int ret = 0;
if (tx) {
data->state &= ~SPI_LP8841_RTC_nWE;
writeb(data->state, data->iomem);
while (likely(count > 0)) {
word = *tx++;
bitbang_txrx_be_cpha0_lsb(data, 1, 0,
SPI_MASTER_NO_RX, word, 8);
count--;
}
} else if (rx) {
data->state |= SPI_LP8841_RTC_nWE;
writeb(data->state, data->iomem);
while (likely(count > 0)) {
word = bitbang_txrx_be_cpha0_lsb(data, 1, 0,
SPI_MASTER_NO_TX, word, 8);
*rx++ = word;
count--;
}
} else {
ret = -EINVAL;
}
spi_finalize_current_transfer(master);
return ret;
}
static void
spi_lp8841_rtc_set_cs(struct spi_device *spi, bool enable)
{
struct spi_lp8841_rtc *data = spi_master_get_devdata(spi->master);
data->state = 0;
writeb(data->state, data->iomem);
if (enable) {
usleep_range(4, 5);
data->state |= SPI_LP8841_RTC_CE;
writeb(data->state, data->iomem);
usleep_range(4, 5);
}
}
static int
spi_lp8841_rtc_setup(struct spi_device *spi)
{
if ((spi->mode & SPI_CS_HIGH) == 0) {
dev_err(&spi->dev, "unsupported active low chip select\n");
return -EINVAL;
}
if ((spi->mode & SPI_LSB_FIRST) == 0) {
dev_err(&spi->dev, "unsupported MSB first mode\n");
return -EINVAL;
}
if ((spi->mode & SPI_3WIRE) == 0) {
dev_err(&spi->dev, "unsupported wiring. 3 wires required\n");
return -EINVAL;
}
return 0;
}
static int
spi_lp8841_rtc_probe(struct platform_device *pdev)
{
int ret;
struct spi_master *master;
struct spi_lp8841_rtc *data;
void *iomem;
master = spi_alloc_master(&pdev->dev, sizeof(*data));
if (!master)
return -ENOMEM;
platform_set_drvdata(pdev, master);
master->flags = SPI_MASTER_HALF_DUPLEX;
master->mode_bits = SPI_CS_HIGH | SPI_3WIRE | SPI_LSB_FIRST;
master->bus_num = pdev->id;
master->num_chipselect = 1;
master->setup = spi_lp8841_rtc_setup;
master->set_cs = spi_lp8841_rtc_set_cs;
master->transfer_one = spi_lp8841_rtc_transfer_one;
master->bits_per_word_mask = SPI_BPW_MASK(8);
#ifdef CONFIG_OF
master->dev.of_node = pdev->dev.of_node;
#endif
data = spi_master_get_devdata(master);
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->iomem = devm_ioremap_resource(&pdev->dev, iomem);
ret = PTR_ERR_OR_ZERO(data->iomem);
if (ret) {
dev_err(&pdev->dev, "failed to get IO address\n");
goto err_put_master;
}
ret = devm_spi_register_master(&pdev->dev, master);
if (ret) {
dev_err(&pdev->dev, "cannot register spi master\n");
goto err_put_master;
}
return ret;
err_put_master:
spi_master_put(master);
return ret;
}
