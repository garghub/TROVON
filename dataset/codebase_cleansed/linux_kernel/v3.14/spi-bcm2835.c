static inline u32 bcm2835_rd(struct bcm2835_spi *bs, unsigned reg)
{
return readl(bs->regs + reg);
}
static inline void bcm2835_wr(struct bcm2835_spi *bs, unsigned reg, u32 val)
{
writel(val, bs->regs + reg);
}
static inline void bcm2835_rd_fifo(struct bcm2835_spi *bs, int len)
{
u8 byte;
while (len--) {
byte = bcm2835_rd(bs, BCM2835_SPI_FIFO);
if (bs->rx_buf)
*bs->rx_buf++ = byte;
}
}
static inline void bcm2835_wr_fifo(struct bcm2835_spi *bs, int len)
{
u8 byte;
if (len > bs->len)
len = bs->len;
while (len--) {
byte = bs->tx_buf ? *bs->tx_buf++ : 0;
bcm2835_wr(bs, BCM2835_SPI_FIFO, byte);
bs->len--;
}
}
static irqreturn_t bcm2835_spi_interrupt(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct bcm2835_spi *bs = spi_master_get_devdata(master);
u32 cs = bcm2835_rd(bs, BCM2835_SPI_CS);
if (bs->len && (cs & BCM2835_SPI_CS_RXR)) {
bcm2835_rd_fifo(bs, 12);
bcm2835_wr_fifo(bs, 12);
return IRQ_HANDLED;
}
if (cs & BCM2835_SPI_CS_DONE) {
if (bs->len) {
bcm2835_wr_fifo(bs, 16);
} else {
cs &= ~(BCM2835_SPI_CS_INTR | BCM2835_SPI_CS_INTD);
bcm2835_wr(bs, BCM2835_SPI_CS, cs);
complete(&bs->done);
}
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int bcm2835_spi_start_transfer(struct spi_device *spi,
struct spi_transfer *tfr)
{
struct bcm2835_spi *bs = spi_master_get_devdata(spi->master);
unsigned long spi_hz, clk_hz, cdiv;
u32 cs = BCM2835_SPI_CS_INTR | BCM2835_SPI_CS_INTD | BCM2835_SPI_CS_TA;
spi_hz = tfr->speed_hz;
clk_hz = clk_get_rate(bs->clk);
if (spi_hz >= clk_hz / 2) {
cdiv = 2;
} else if (spi_hz) {
cdiv = roundup_pow_of_two(DIV_ROUND_UP(clk_hz, spi_hz));
if (cdiv >= 65536)
cdiv = 0;
} else
cdiv = 0;
if (spi->mode & SPI_CPOL)
cs |= BCM2835_SPI_CS_CPOL;
if (spi->mode & SPI_CPHA)
cs |= BCM2835_SPI_CS_CPHA;
if (!(spi->mode & SPI_NO_CS)) {
if (spi->mode & SPI_CS_HIGH) {
cs |= BCM2835_SPI_CS_CSPOL;
cs |= BCM2835_SPI_CS_CSPOL0 << spi->chip_select;
}
cs |= spi->chip_select;
}
reinit_completion(&bs->done);
bs->tx_buf = tfr->tx_buf;
bs->rx_buf = tfr->rx_buf;
bs->len = tfr->len;
bcm2835_wr(bs, BCM2835_SPI_CLK, cdiv);
bcm2835_wr(bs, BCM2835_SPI_CS, cs);
return 0;
}
static int bcm2835_spi_finish_transfer(struct spi_device *spi,
struct spi_transfer *tfr, bool cs_change)
{
struct bcm2835_spi *bs = spi_master_get_devdata(spi->master);
u32 cs = bcm2835_rd(bs, BCM2835_SPI_CS);
while (cs & BCM2835_SPI_CS_RXD) {
bcm2835_rd_fifo(bs, 1);
cs = bcm2835_rd(bs, BCM2835_SPI_CS);
}
if (tfr->delay_usecs)
udelay(tfr->delay_usecs);
if (cs_change)
bcm2835_wr(bs, BCM2835_SPI_CS, cs & ~BCM2835_SPI_CS_TA);
return 0;
}
static int bcm2835_spi_transfer_one(struct spi_master *master,
struct spi_message *mesg)
{
struct bcm2835_spi *bs = spi_master_get_devdata(master);
struct spi_transfer *tfr;
struct spi_device *spi = mesg->spi;
int err = 0;
unsigned int timeout;
bool cs_change;
list_for_each_entry(tfr, &mesg->transfers, transfer_list) {
err = bcm2835_spi_start_transfer(spi, tfr);
if (err)
goto out;
timeout = wait_for_completion_timeout(&bs->done,
msecs_to_jiffies(BCM2835_SPI_TIMEOUT_MS));
if (!timeout) {
err = -ETIMEDOUT;
goto out;
}
cs_change = tfr->cs_change ||
list_is_last(&tfr->transfer_list, &mesg->transfers);
err = bcm2835_spi_finish_transfer(spi, tfr, cs_change);
if (err)
goto out;
mesg->actual_length += (tfr->len - bs->len);
}
out:
bcm2835_wr(bs, BCM2835_SPI_CS,
BCM2835_SPI_CS_CLEAR_RX | BCM2835_SPI_CS_CLEAR_TX);
mesg->status = err;
spi_finalize_current_message(master);
return 0;
}
static int bcm2835_spi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct bcm2835_spi *bs;
struct resource *res;
int err;
master = spi_alloc_master(&pdev->dev, sizeof(*bs));
if (!master) {
dev_err(&pdev->dev, "spi_alloc_master() failed\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, master);
master->mode_bits = BCM2835_SPI_MODE_BITS;
master->bits_per_word_mask = SPI_BPW_MASK(8);
master->bus_num = -1;
master->num_chipselect = 3;
master->transfer_one_message = bcm2835_spi_transfer_one;
master->dev.of_node = pdev->dev.of_node;
bs = spi_master_get_devdata(master);
init_completion(&bs->done);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
bs->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(bs->regs)) {
err = PTR_ERR(bs->regs);
goto out_master_put;
}
bs->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(bs->clk)) {
err = PTR_ERR(bs->clk);
dev_err(&pdev->dev, "could not get clk: %d\n", err);
goto out_master_put;
}
bs->irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
if (bs->irq <= 0) {
dev_err(&pdev->dev, "could not get IRQ: %d\n", bs->irq);
err = bs->irq ? bs->irq : -ENODEV;
goto out_master_put;
}
clk_prepare_enable(bs->clk);
err = devm_request_irq(&pdev->dev, bs->irq, bcm2835_spi_interrupt, 0,
dev_name(&pdev->dev), master);
if (err) {
dev_err(&pdev->dev, "could not request IRQ: %d\n", err);
goto out_clk_disable;
}
bcm2835_wr(bs, BCM2835_SPI_CS,
BCM2835_SPI_CS_CLEAR_RX | BCM2835_SPI_CS_CLEAR_TX);
err = devm_spi_register_master(&pdev->dev, master);
if (err) {
dev_err(&pdev->dev, "could not register SPI master: %d\n", err);
goto out_clk_disable;
}
return 0;
out_clk_disable:
clk_disable_unprepare(bs->clk);
out_master_put:
spi_master_put(master);
return err;
}
static int bcm2835_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct bcm2835_spi *bs = spi_master_get_devdata(master);
bcm2835_wr(bs, BCM2835_SPI_CS,
BCM2835_SPI_CS_CLEAR_RX | BCM2835_SPI_CS_CLEAR_TX);
clk_disable_unprepare(bs->clk);
return 0;
}
