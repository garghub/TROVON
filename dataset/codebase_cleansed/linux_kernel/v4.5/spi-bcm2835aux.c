static inline u32 bcm2835aux_rd(struct bcm2835aux_spi *bs, unsigned reg)
{
return readl(bs->regs + reg);
}
static inline void bcm2835aux_wr(struct bcm2835aux_spi *bs, unsigned reg,
u32 val)
{
writel(val, bs->regs + reg);
}
static inline void bcm2835aux_rd_fifo(struct bcm2835aux_spi *bs)
{
u32 data;
int count = min(bs->rx_len, 3);
data = bcm2835aux_rd(bs, BCM2835_AUX_SPI_IO);
if (bs->rx_buf) {
switch (count) {
case 4:
*bs->rx_buf++ = (data >> 24) & 0xff;
case 3:
*bs->rx_buf++ = (data >> 16) & 0xff;
case 2:
*bs->rx_buf++ = (data >> 8) & 0xff;
case 1:
*bs->rx_buf++ = (data >> 0) & 0xff;
}
}
bs->rx_len -= count;
bs->pending -= count;
}
static inline void bcm2835aux_wr_fifo(struct bcm2835aux_spi *bs)
{
u32 data;
u8 byte;
int count;
int i;
count = min(bs->tx_len, 3);
data = 0;
for (i = 0; i < count; i++) {
byte = bs->tx_buf ? *bs->tx_buf++ : 0;
data |= byte << (8 * (2 - i));
}
data |= (count * 8) << 24;
bs->tx_len -= count;
bs->pending += count;
if (bs->tx_len)
bcm2835aux_wr(bs, BCM2835_AUX_SPI_TXHOLD, data);
else
bcm2835aux_wr(bs, BCM2835_AUX_SPI_IO, data);
}
static void bcm2835aux_spi_reset_hw(struct bcm2835aux_spi *bs)
{
bcm2835aux_wr(bs, BCM2835_AUX_SPI_CNTL1, 0);
bcm2835aux_wr(bs, BCM2835_AUX_SPI_CNTL0,
BCM2835_AUX_SPI_CNTL0_CLEARFIFO);
}
static irqreturn_t bcm2835aux_spi_interrupt(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct bcm2835aux_spi *bs = spi_master_get_devdata(master);
irqreturn_t ret = IRQ_NONE;
while (bs->rx_len &&
(!(bcm2835aux_rd(bs, BCM2835_AUX_SPI_STAT) &
BCM2835_AUX_SPI_STAT_RX_EMPTY))) {
bcm2835aux_rd_fifo(bs);
ret = IRQ_HANDLED;
}
while (bs->tx_len &&
(bs->pending < 12) &&
(!(bcm2835aux_rd(bs, BCM2835_AUX_SPI_STAT) &
BCM2835_AUX_SPI_STAT_TX_FULL))) {
bcm2835aux_wr_fifo(bs);
ret = IRQ_HANDLED;
}
while (bs->rx_len &&
(!(bcm2835aux_rd(bs, BCM2835_AUX_SPI_STAT) &
BCM2835_AUX_SPI_STAT_BUSY))) {
bcm2835aux_rd_fifo(bs);
ret = IRQ_HANDLED;
}
if (!bs->rx_len) {
bcm2835aux_spi_reset_hw(bs);
complete(&master->xfer_completion);
}
return ret;
}
static int __bcm2835aux_spi_transfer_one_irq(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr)
{
struct bcm2835aux_spi *bs = spi_master_get_devdata(master);
bcm2835aux_wr(bs, BCM2835_AUX_SPI_CNTL1, bs->cntl[1] |
BCM2835_AUX_SPI_CNTL1_TXEMPTY |
BCM2835_AUX_SPI_CNTL1_IDLE);
return 1;
}
static int bcm2835aux_spi_transfer_one_irq(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr)
{
struct bcm2835aux_spi *bs = spi_master_get_devdata(master);
bcm2835aux_wr(bs, BCM2835_AUX_SPI_CNTL1, bs->cntl[1]);
bcm2835aux_wr(bs, BCM2835_AUX_SPI_CNTL0, bs->cntl[0]);
while ((bs->tx_len) &&
(bs->pending < 12) &&
(!(bcm2835aux_rd(bs, BCM2835_AUX_SPI_STAT) &
BCM2835_AUX_SPI_STAT_TX_FULL))) {
bcm2835aux_wr_fifo(bs);
}
return __bcm2835aux_spi_transfer_one_irq(master, spi, tfr);
}
static int bcm2835aux_spi_transfer_one_poll(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr)
{
struct bcm2835aux_spi *bs = spi_master_get_devdata(master);
unsigned long timeout;
u32 stat;
bcm2835aux_wr(bs, BCM2835_AUX_SPI_CNTL1, bs->cntl[1]);
bcm2835aux_wr(bs, BCM2835_AUX_SPI_CNTL0, bs->cntl[0]);
timeout = jiffies + BCM2835_AUX_SPI_POLLING_JIFFIES;
while (bs->rx_len) {
stat = bcm2835aux_rd(bs, BCM2835_AUX_SPI_STAT);
if ((bs->tx_len) && (!(stat & BCM2835_AUX_SPI_STAT_TX_FULL))) {
bcm2835aux_wr_fifo(bs);
continue;
}
if (!(stat & BCM2835_AUX_SPI_STAT_RX_EMPTY)) {
bcm2835aux_rd_fifo(bs);
continue;
}
if (!(stat & BCM2835_AUX_SPI_STAT_BUSY)) {
bcm2835aux_rd_fifo(bs);
continue;
}
if (bs->rx_len && time_after(jiffies, timeout)) {
dev_dbg_ratelimited(&spi->dev,
"timeout period reached: jiffies: %lu remaining tx/rx: %d/%d - falling back to interrupt mode\n",
jiffies - timeout,
bs->tx_len, bs->rx_len);
return __bcm2835aux_spi_transfer_one_irq(master,
spi, tfr);
}
}
bcm2835aux_spi_reset_hw(bs);
return 0;
}
static int bcm2835aux_spi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr)
{
struct bcm2835aux_spi *bs = spi_master_get_devdata(master);
unsigned long spi_hz, clk_hz, speed;
unsigned long spi_used_hz;
unsigned long long xfer_time_us;
bs->cntl[0] = BCM2835_AUX_SPI_CNTL0_ENABLE |
BCM2835_AUX_SPI_CNTL0_VAR_WIDTH |
BCM2835_AUX_SPI_CNTL0_MSBF_OUT;
bs->cntl[1] = BCM2835_AUX_SPI_CNTL1_MSBF_IN;
spi_hz = tfr->speed_hz;
clk_hz = clk_get_rate(bs->clk);
if (spi_hz >= clk_hz / 2) {
speed = 0;
} else if (spi_hz) {
speed = DIV_ROUND_UP(clk_hz, 2 * spi_hz) - 1;
if (speed > BCM2835_AUX_SPI_CNTL0_SPEED_MAX)
speed = BCM2835_AUX_SPI_CNTL0_SPEED_MAX;
} else {
speed = BCM2835_AUX_SPI_CNTL0_SPEED_MAX;
}
bs->cntl[0] |= speed << BCM2835_AUX_SPI_CNTL0_SPEED_SHIFT;
spi_used_hz = clk_hz / (2 * (speed + 1));
if (spi->mode & SPI_CPOL)
bs->cntl[0] |= BCM2835_AUX_SPI_CNTL0_CPOL;
if (spi->mode & SPI_CPHA)
bs->cntl[0] |= BCM2835_AUX_SPI_CNTL0_CPHA_OUT |
BCM2835_AUX_SPI_CNTL0_CPHA_IN;
bs->tx_buf = tfr->tx_buf;
bs->rx_buf = tfr->rx_buf;
bs->tx_len = tfr->len;
bs->rx_len = tfr->len;
bs->pending = 0;
xfer_time_us = tfr->len * 9 * 1000000;
do_div(xfer_time_us, spi_used_hz);
if (xfer_time_us < BCM2835_AUX_SPI_POLLING_LIMIT_US)
return bcm2835aux_spi_transfer_one_poll(master, spi, tfr);
return bcm2835aux_spi_transfer_one_irq(master, spi, tfr);
}
static void bcm2835aux_spi_handle_err(struct spi_master *master,
struct spi_message *msg)
{
struct bcm2835aux_spi *bs = spi_master_get_devdata(master);
bcm2835aux_spi_reset_hw(bs);
}
static int bcm2835aux_spi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct bcm2835aux_spi *bs;
struct resource *res;
unsigned long clk_hz;
int err;
master = spi_alloc_master(&pdev->dev, sizeof(*bs));
if (!master) {
dev_err(&pdev->dev, "spi_alloc_master() failed\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, master);
master->mode_bits = BCM2835_AUX_SPI_MODE_BITS;
master->bits_per_word_mask = SPI_BPW_MASK(8);
master->num_chipselect = -1;
master->transfer_one = bcm2835aux_spi_transfer_one;
master->handle_err = bcm2835aux_spi_handle_err;
master->dev.of_node = pdev->dev.of_node;
bs = spi_master_get_devdata(master);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
bs->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(bs->regs)) {
err = PTR_ERR(bs->regs);
goto out_master_put;
}
bs->clk = devm_clk_get(&pdev->dev, NULL);
if ((!bs->clk) || (IS_ERR(bs->clk))) {
err = PTR_ERR(bs->clk);
dev_err(&pdev->dev, "could not get clk: %d\n", err);
goto out_master_put;
}
bs->irq = platform_get_irq(pdev, 0);
if (bs->irq <= 0) {
dev_err(&pdev->dev, "could not get IRQ: %d\n", bs->irq);
err = bs->irq ? bs->irq : -ENODEV;
goto out_master_put;
}
err = clk_prepare_enable(bs->clk);
if (err) {
dev_err(&pdev->dev, "could not prepare clock: %d\n", err);
goto out_master_put;
}
clk_hz = clk_get_rate(bs->clk);
if (!clk_hz) {
dev_err(&pdev->dev, "clock returns 0 Hz\n");
err = -ENODEV;
goto out_clk_disable;
}
bcm2835aux_spi_reset_hw(bs);
err = devm_request_irq(&pdev->dev, bs->irq,
bcm2835aux_spi_interrupt,
IRQF_SHARED,
dev_name(&pdev->dev), master);
if (err) {
dev_err(&pdev->dev, "could not request IRQ: %d\n", err);
goto out_clk_disable;
}
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
static int bcm2835aux_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct bcm2835aux_spi *bs = spi_master_get_devdata(master);
bcm2835aux_spi_reset_hw(bs);
clk_disable_unprepare(bs->clk);
return 0;
}
