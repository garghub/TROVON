static inline u32 bcm2835_rd(struct bcm2835_spi *bs, unsigned reg)
{
return readl(bs->regs + reg);
}
static inline void bcm2835_wr(struct bcm2835_spi *bs, unsigned reg, u32 val)
{
writel(val, bs->regs + reg);
}
static inline void bcm2835_rd_fifo(struct bcm2835_spi *bs)
{
u8 byte;
while ((bs->rx_len) &&
(bcm2835_rd(bs, BCM2835_SPI_CS) & BCM2835_SPI_CS_RXD)) {
byte = bcm2835_rd(bs, BCM2835_SPI_FIFO);
if (bs->rx_buf)
*bs->rx_buf++ = byte;
bs->rx_len--;
}
}
static inline void bcm2835_wr_fifo(struct bcm2835_spi *bs)
{
u8 byte;
while ((bs->tx_len) &&
(bcm2835_rd(bs, BCM2835_SPI_CS) & BCM2835_SPI_CS_TXD)) {
byte = bs->tx_buf ? *bs->tx_buf++ : 0;
bcm2835_wr(bs, BCM2835_SPI_FIFO, byte);
bs->tx_len--;
}
}
static void bcm2835_spi_reset_hw(struct spi_master *master)
{
struct bcm2835_spi *bs = spi_master_get_devdata(master);
u32 cs = bcm2835_rd(bs, BCM2835_SPI_CS);
cs &= ~(BCM2835_SPI_CS_INTR |
BCM2835_SPI_CS_INTD |
BCM2835_SPI_CS_DMAEN |
BCM2835_SPI_CS_TA);
cs |= BCM2835_SPI_CS_CLEAR_RX | BCM2835_SPI_CS_CLEAR_TX;
bcm2835_wr(bs, BCM2835_SPI_CS, cs);
bcm2835_wr(bs, BCM2835_SPI_DLEN, 0);
}
static irqreturn_t bcm2835_spi_interrupt(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct bcm2835_spi *bs = spi_master_get_devdata(master);
bcm2835_rd_fifo(bs);
bcm2835_wr_fifo(bs);
if (bcm2835_rd(bs, BCM2835_SPI_CS) & BCM2835_SPI_CS_DONE) {
bcm2835_spi_reset_hw(master);
complete(&master->xfer_completion);
}
return IRQ_HANDLED;
}
static int bcm2835_spi_transfer_one_irq(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr,
u32 cs)
{
struct bcm2835_spi *bs = spi_master_get_devdata(master);
if (gpio_is_valid(spi->cs_gpio)) {
bcm2835_wr(bs, BCM2835_SPI_CS,
cs | BCM2835_SPI_CS_TA);
bcm2835_wr_fifo(bs);
}
cs |= BCM2835_SPI_CS_INTR | BCM2835_SPI_CS_INTD | BCM2835_SPI_CS_TA;
bcm2835_wr(bs, BCM2835_SPI_CS, cs);
return 1;
}
static void bcm2835_spi_dma_done(void *data)
{
struct spi_master *master = data;
struct bcm2835_spi *bs = spi_master_get_devdata(master);
bcm2835_spi_reset_hw(master);
dmaengine_terminate_all(master->dma_tx);
bs->dma_pending = 0;
;
complete(&master->xfer_completion);
}
static int bcm2835_spi_prepare_sg(struct spi_master *master,
struct spi_transfer *tfr,
bool is_tx)
{
struct dma_chan *chan;
struct scatterlist *sgl;
unsigned int nents;
enum dma_transfer_direction dir;
unsigned long flags;
struct dma_async_tx_descriptor *desc;
dma_cookie_t cookie;
if (is_tx) {
dir = DMA_MEM_TO_DEV;
chan = master->dma_tx;
nents = tfr->tx_sg.nents;
sgl = tfr->tx_sg.sgl;
flags = 0 ;
} else {
dir = DMA_DEV_TO_MEM;
chan = master->dma_rx;
nents = tfr->rx_sg.nents;
sgl = tfr->rx_sg.sgl;
flags = DMA_PREP_INTERRUPT;
}
desc = dmaengine_prep_slave_sg(chan, sgl, nents, dir, flags);
if (!desc)
return -EINVAL;
if (!is_tx) {
desc->callback = bcm2835_spi_dma_done;
desc->callback_param = master;
}
cookie = dmaengine_submit(desc);
return dma_submit_error(cookie);
}
static inline int bcm2835_check_sg_length(struct sg_table *sgt)
{
int i;
struct scatterlist *sgl;
for_each_sg(sgt->sgl, sgl, (int)sgt->nents - 1, i) {
if (sg_dma_len(sgl) % 4)
return -EFAULT;
}
return 0;
}
static int bcm2835_spi_transfer_one_dma(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr,
u32 cs)
{
struct bcm2835_spi *bs = spi_master_get_devdata(master);
int ret;
if (bcm2835_check_sg_length(&tfr->tx_sg) ||
bcm2835_check_sg_length(&tfr->rx_sg)) {
dev_warn_once(&spi->dev,
"scatter gather segment length is not a multiple of 4 - falling back to interrupt mode\n");
return bcm2835_spi_transfer_one_irq(master, spi, tfr, cs);
}
ret = bcm2835_spi_prepare_sg(master, tfr, true);
if (ret)
return ret;
dma_async_issue_pending(master->dma_tx);
bs->dma_pending = 1;
bcm2835_wr(bs, BCM2835_SPI_DLEN, tfr->len);
bcm2835_wr(bs, BCM2835_SPI_CS,
cs | BCM2835_SPI_CS_TA | BCM2835_SPI_CS_DMAEN);
ret = bcm2835_spi_prepare_sg(master, tfr, false);
if (ret) {
dmaengine_terminate_all(master->dma_tx);
bcm2835_spi_reset_hw(master);
return ret;
}
dma_async_issue_pending(master->dma_rx);
return 1;
}
static bool bcm2835_spi_can_dma(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr)
{
if (!gpio_is_valid(spi->cs_gpio))
return false;
if (tfr->len < BCM2835_SPI_DMA_MIN_LENGTH)
return false;
if (tfr->len > 65535) {
dev_warn_once(&spi->dev,
"transfer size of %d too big for dma-transfer\n",
tfr->len);
return false;
}
if ((((size_t)tfr->rx_buf & 3) == 0) &&
(((size_t)tfr->tx_buf & 3) == 0))
return true;
if (((size_t)tfr->tx_buf & PAGE_MASK) + tfr->len > PAGE_SIZE) {
dev_warn_once(&spi->dev,
"Unaligned spi tx-transfer bridging page\n");
return false;
}
if (((size_t)tfr->rx_buf & PAGE_MASK) + tfr->len > PAGE_SIZE) {
dev_warn_once(&spi->dev,
"Unaligned spi tx-transfer bridging page\n");
return false;
}
return true;
}
static void bcm2835_dma_release(struct spi_master *master)
{
if (master->dma_tx) {
dmaengine_terminate_all(master->dma_tx);
dma_release_channel(master->dma_tx);
master->dma_tx = NULL;
}
if (master->dma_rx) {
dmaengine_terminate_all(master->dma_rx);
dma_release_channel(master->dma_rx);
master->dma_rx = NULL;
}
}
static void bcm2835_dma_init(struct spi_master *master, struct device *dev)
{
struct dma_slave_config slave_config;
const __be32 *addr;
dma_addr_t dma_reg_base;
int ret;
addr = of_get_address(master->dev.of_node, 0, NULL, NULL);
if (!addr) {
dev_err(dev, "could not get DMA-register address - not using dma mode\n");
goto err;
}
dma_reg_base = be32_to_cpup(addr);
master->dma_tx = dma_request_slave_channel(dev, "tx");
if (!master->dma_tx) {
dev_err(dev, "no tx-dma configuration found - not using dma mode\n");
goto err;
}
master->dma_rx = dma_request_slave_channel(dev, "rx");
if (!master->dma_rx) {
dev_err(dev, "no rx-dma configuration found - not using dma mode\n");
goto err_release;
}
slave_config.direction = DMA_MEM_TO_DEV;
slave_config.dst_addr = (u32)(dma_reg_base + BCM2835_SPI_FIFO);
slave_config.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
ret = dmaengine_slave_config(master->dma_tx, &slave_config);
if (ret)
goto err_config;
slave_config.direction = DMA_DEV_TO_MEM;
slave_config.src_addr = (u32)(dma_reg_base + BCM2835_SPI_FIFO);
slave_config.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
ret = dmaengine_slave_config(master->dma_rx, &slave_config);
if (ret)
goto err_config;
master->can_dma = bcm2835_spi_can_dma;
master->max_dma_len = 65535;
master->flags = SPI_MASTER_MUST_RX | SPI_MASTER_MUST_TX;
return;
err_config:
dev_err(dev, "issue configuring dma: %d - not using DMA mode\n",
ret);
err_release:
bcm2835_dma_release(master);
err:
return;
}
static int bcm2835_spi_transfer_one_poll(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr,
u32 cs,
unsigned long xfer_time_us)
{
struct bcm2835_spi *bs = spi_master_get_devdata(master);
unsigned long timeout;
bcm2835_wr(bs, BCM2835_SPI_CS, cs | BCM2835_SPI_CS_TA);
bcm2835_wr_fifo(bs);
timeout = jiffies + BCM2835_SPI_POLLING_JIFFIES;
while (bs->rx_len) {
bcm2835_wr_fifo(bs);
bcm2835_rd_fifo(bs);
if (bs->rx_len && time_after(jiffies, timeout)) {
dev_dbg_ratelimited(&spi->dev,
"timeout period reached: jiffies: %lu remaining tx/rx: %d/%d - falling back to interrupt mode\n",
jiffies - timeout,
bs->tx_len, bs->rx_len);
return bcm2835_spi_transfer_one_irq(master, spi,
tfr, cs);
}
}
bcm2835_spi_reset_hw(master);
return 0;
}
static int bcm2835_spi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *tfr)
{
struct bcm2835_spi *bs = spi_master_get_devdata(master);
unsigned long spi_hz, clk_hz, cdiv;
unsigned long spi_used_hz, xfer_time_us;
u32 cs = bcm2835_rd(bs, BCM2835_SPI_CS);
spi_hz = tfr->speed_hz;
clk_hz = clk_get_rate(bs->clk);
if (spi_hz >= clk_hz / 2) {
cdiv = 2;
} else if (spi_hz) {
cdiv = DIV_ROUND_UP(clk_hz, spi_hz);
cdiv += (cdiv % 2);
if (cdiv >= 65536)
cdiv = 0;
} else {
cdiv = 0;
}
spi_used_hz = cdiv ? (clk_hz / cdiv) : (clk_hz / 65536);
bcm2835_wr(bs, BCM2835_SPI_CLK, cdiv);
if ((spi->mode & SPI_3WIRE) && (tfr->rx_buf))
cs |= BCM2835_SPI_CS_REN;
if (spi->mode & SPI_CPOL)
cs |= BCM2835_SPI_CS_CPOL;
if (spi->mode & SPI_CPHA)
cs |= BCM2835_SPI_CS_CPHA;
if (gpio_is_valid(spi->cs_gpio) || (spi->mode & SPI_NO_CS))
cs |= BCM2835_SPI_CS_CS_10 | BCM2835_SPI_CS_CS_01;
bs->tx_buf = tfr->tx_buf;
bs->rx_buf = tfr->rx_buf;
bs->tx_len = tfr->len;
bs->rx_len = tfr->len;
xfer_time_us = tfr->len
* 9
* 1000000 / spi_used_hz;
if (xfer_time_us <= BCM2835_SPI_POLLING_LIMIT_US)
return bcm2835_spi_transfer_one_poll(master, spi, tfr,
cs, xfer_time_us);
if (master->can_dma && bcm2835_spi_can_dma(master, spi, tfr))
return bcm2835_spi_transfer_one_dma(master, spi, tfr, cs);
return bcm2835_spi_transfer_one_irq(master, spi, tfr, cs);
}
static void bcm2835_spi_handle_err(struct spi_master *master,
struct spi_message *msg)
{
struct bcm2835_spi *bs = spi_master_get_devdata(master);
if (bs->dma_pending) {
dmaengine_terminate_all(master->dma_tx);
dmaengine_terminate_all(master->dma_rx);
bs->dma_pending = 0;
}
bcm2835_spi_reset_hw(master);
}
static void bcm2835_spi_set_cs(struct spi_device *spi, bool gpio_level)
{
struct spi_master *master = spi->master;
struct bcm2835_spi *bs = spi_master_get_devdata(master);
u32 cs = bcm2835_rd(bs, BCM2835_SPI_CS);
bool enable;
enable = (spi->mode & SPI_CS_HIGH) ? gpio_level : !gpio_level;
if (spi->mode & SPI_CS_HIGH) {
cs |= BCM2835_SPI_CS_CSPOL;
cs |= BCM2835_SPI_CS_CSPOL0 << spi->chip_select;
} else {
cs &= ~BCM2835_SPI_CS_CSPOL;
cs &= ~(BCM2835_SPI_CS_CSPOL0 << spi->chip_select);
}
if (enable) {
if (spi->mode & SPI_NO_CS) {
cs |= BCM2835_SPI_CS_CS_10 | BCM2835_SPI_CS_CS_01;
} else {
cs &= ~(BCM2835_SPI_CS_CS_10 | BCM2835_SPI_CS_CS_01);
cs |= spi->chip_select;
}
} else {
cs &= ~BCM2835_SPI_CS_CSPOL;
cs |= BCM2835_SPI_CS_CS_10 | BCM2835_SPI_CS_CS_01;
}
bcm2835_wr(bs, BCM2835_SPI_CS, cs);
}
static int chip_match_name(struct gpio_chip *chip, void *data)
{
return !strcmp(chip->label, data);
}
static int bcm2835_spi_setup(struct spi_device *spi)
{
int err;
struct gpio_chip *chip;
if (spi->mode & SPI_NO_CS)
return 0;
if (gpio_is_valid(spi->cs_gpio))
return 0;
if (spi->chip_select > 1) {
dev_err(&spi->dev,
"setup: only two native chip-selects are supported\n");
return -EINVAL;
}
chip = gpiochip_find("pinctrl-bcm2835", chip_match_name);
if (!chip)
return 0;
spi->cs_gpio = chip->base + 8 - spi->chip_select;
dev_info(&spi->dev, "setting up native-CS%i as GPIO %i\n",
spi->chip_select, spi->cs_gpio);
err = gpio_direction_output(spi->cs_gpio,
(spi->mode & SPI_CS_HIGH) ? 0 : 1);
if (err) {
dev_err(&spi->dev,
"could not set CS%i gpio %i as output: %i",
spi->chip_select, spi->cs_gpio, err);
return err;
}
gpio_set_value(spi->cs_gpio, (spi->mode & SPI_CS_HIGH) ? 0 : 1);
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
master->num_chipselect = 3;
master->setup = bcm2835_spi_setup;
master->set_cs = bcm2835_spi_set_cs;
master->transfer_one = bcm2835_spi_transfer_one;
master->handle_err = bcm2835_spi_handle_err;
master->dev.of_node = pdev->dev.of_node;
bs = spi_master_get_devdata(master);
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
bcm2835_dma_init(master, &pdev->dev);
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
bcm2835_dma_release(master);
return 0;
}
