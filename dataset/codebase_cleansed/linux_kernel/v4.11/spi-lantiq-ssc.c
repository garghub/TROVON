static u32 lantiq_ssc_readl(const struct lantiq_ssc_spi *spi, u32 reg)
{
return __raw_readl(spi->regbase + reg);
}
static void lantiq_ssc_writel(const struct lantiq_ssc_spi *spi, u32 val,
u32 reg)
{
__raw_writel(val, spi->regbase + reg);
}
static void lantiq_ssc_maskl(const struct lantiq_ssc_spi *spi, u32 clr,
u32 set, u32 reg)
{
u32 val = __raw_readl(spi->regbase + reg);
val &= ~clr;
val |= set;
__raw_writel(val, spi->regbase + reg);
}
static unsigned int tx_fifo_level(const struct lantiq_ssc_spi *spi)
{
u32 fstat = lantiq_ssc_readl(spi, SPI_FSTAT);
return (fstat & SPI_FSTAT_TXFFL_M) >> SPI_FSTAT_TXFFL_S;
}
static unsigned int rx_fifo_level(const struct lantiq_ssc_spi *spi)
{
u32 fstat = lantiq_ssc_readl(spi, SPI_FSTAT);
return fstat & SPI_FSTAT_RXFFL_M;
}
static unsigned int tx_fifo_free(const struct lantiq_ssc_spi *spi)
{
return spi->tx_fifo_size - tx_fifo_level(spi);
}
static void rx_fifo_reset(const struct lantiq_ssc_spi *spi)
{
u32 val = spi->rx_fifo_size << SPI_RXFCON_RXFITL_S;
val |= SPI_RXFCON_RXFEN | SPI_RXFCON_RXFLU;
lantiq_ssc_writel(spi, val, SPI_RXFCON);
}
static void tx_fifo_reset(const struct lantiq_ssc_spi *spi)
{
u32 val = 1 << SPI_TXFCON_TXFITL_S;
val |= SPI_TXFCON_TXFEN | SPI_TXFCON_TXFLU;
lantiq_ssc_writel(spi, val, SPI_TXFCON);
}
static void rx_fifo_flush(const struct lantiq_ssc_spi *spi)
{
lantiq_ssc_maskl(spi, 0, SPI_RXFCON_RXFLU, SPI_RXFCON);
}
static void tx_fifo_flush(const struct lantiq_ssc_spi *spi)
{
lantiq_ssc_maskl(spi, 0, SPI_TXFCON_TXFLU, SPI_TXFCON);
}
static void hw_enter_config_mode(const struct lantiq_ssc_spi *spi)
{
lantiq_ssc_writel(spi, SPI_WHBSTATE_CLREN, SPI_WHBSTATE);
}
static void hw_enter_active_mode(const struct lantiq_ssc_spi *spi)
{
lantiq_ssc_writel(spi, SPI_WHBSTATE_SETEN, SPI_WHBSTATE);
}
static void hw_setup_speed_hz(const struct lantiq_ssc_spi *spi,
unsigned int max_speed_hz)
{
u32 spi_clk, brt;
spi_clk = clk_get_rate(spi->fpi_clk) / 2;
if (max_speed_hz > spi_clk)
brt = 0;
else
brt = spi_clk / max_speed_hz - 1;
if (brt > 0xFFFF)
brt = 0xFFFF;
dev_dbg(spi->dev, "spi_clk %u, max_speed_hz %u, brt %u\n",
spi_clk, max_speed_hz, brt);
lantiq_ssc_writel(spi, brt, SPI_BRT);
}
static void hw_setup_bits_per_word(const struct lantiq_ssc_spi *spi,
unsigned int bits_per_word)
{
u32 bm;
bm = (bits_per_word - 1) << SPI_CON_BM_S;
lantiq_ssc_maskl(spi, SPI_CON_BM_M, bm, SPI_CON);
}
static void hw_setup_clock_mode(const struct lantiq_ssc_spi *spi,
unsigned int mode)
{
u32 con_set = 0, con_clr = 0;
if (mode & SPI_CPHA)
con_clr |= SPI_CON_PH;
else
con_set |= SPI_CON_PH;
if (mode & SPI_CPOL)
con_set |= SPI_CON_PO | SPI_CON_IDLE;
else
con_clr |= SPI_CON_PO | SPI_CON_IDLE;
if (mode & SPI_LSB_FIRST)
con_clr |= SPI_CON_HB;
else
con_set |= SPI_CON_HB;
if (mode & SPI_LOOP)
con_set |= SPI_CON_LB;
else
con_clr |= SPI_CON_LB;
lantiq_ssc_maskl(spi, con_clr, con_set, SPI_CON);
}
static void lantiq_ssc_hw_init(const struct lantiq_ssc_spi *spi)
{
const struct lantiq_ssc_hwcfg *hwcfg = spi->hwcfg;
lantiq_ssc_writel(spi, 1 << SPI_CLC_RMC_S, SPI_CLC);
hw_enter_config_mode(spi);
lantiq_ssc_maskl(spi, 0, SPI_WHBSTATE_CLR_ERRORS, SPI_WHBSTATE);
lantiq_ssc_writel(spi, SPI_CON_RUEN | SPI_CON_AEN | SPI_CON_TEN |
SPI_CON_REN | SPI_CON_TXOFF | SPI_CON_RXOFF, SPI_CON);
hw_setup_bits_per_word(spi, spi->bits_per_word);
hw_setup_clock_mode(spi, SPI_MODE_0);
lantiq_ssc_writel(spi, SPI_WHBSTATE_SETMS | SPI_WHBSTATE_CLR_ERRORS,
SPI_WHBSTATE);
lantiq_ssc_writel(spi, 0, SPI_GPOCON);
lantiq_ssc_writel(spi, 0xFF00, SPI_FPGO);
rx_fifo_reset(spi);
tx_fifo_reset(spi);
lantiq_ssc_writel(spi, hwcfg->irnen_t | hwcfg->irnen_r | SPI_IRNEN_E,
SPI_IRNEN);
}
static int lantiq_ssc_setup(struct spi_device *spidev)
{
struct spi_master *master = spidev->master;
struct lantiq_ssc_spi *spi = spi_master_get_devdata(master);
unsigned int cs = spidev->chip_select;
u32 gpocon;
if (gpio_is_valid(spidev->cs_gpio))
return 0;
dev_dbg(spi->dev, "using internal chipselect %u\n", cs);
if (cs < spi->base_cs) {
dev_err(spi->dev,
"chipselect %i too small (min %i)\n", cs, spi->base_cs);
return -EINVAL;
}
gpocon = 1 << ((cs - spi->base_cs) + SPI_GPOCON_ISCSBN_S);
if (spidev->mode & SPI_CS_HIGH)
gpocon |= 1 << (cs - spi->base_cs);
lantiq_ssc_maskl(spi, 0, gpocon, SPI_GPOCON);
return 0;
}
static int lantiq_ssc_prepare_message(struct spi_master *master,
struct spi_message *message)
{
struct lantiq_ssc_spi *spi = spi_master_get_devdata(master);
hw_enter_config_mode(spi);
hw_setup_clock_mode(spi, message->spi->mode);
hw_enter_active_mode(spi);
return 0;
}
static void hw_setup_transfer(struct lantiq_ssc_spi *spi,
struct spi_device *spidev, struct spi_transfer *t)
{
unsigned int speed_hz = t->speed_hz;
unsigned int bits_per_word = t->bits_per_word;
u32 con;
if (bits_per_word != spi->bits_per_word ||
speed_hz != spi->speed_hz) {
hw_enter_config_mode(spi);
hw_setup_speed_hz(spi, speed_hz);
hw_setup_bits_per_word(spi, bits_per_word);
hw_enter_active_mode(spi);
spi->speed_hz = speed_hz;
spi->bits_per_word = bits_per_word;
}
con = lantiq_ssc_readl(spi, SPI_CON);
if (t->tx_buf)
con &= ~SPI_CON_TXOFF;
else
con |= SPI_CON_TXOFF;
if (t->rx_buf)
con &= ~SPI_CON_RXOFF;
else
con |= SPI_CON_RXOFF;
lantiq_ssc_writel(spi, con, SPI_CON);
}
static int lantiq_ssc_unprepare_message(struct spi_master *master,
struct spi_message *message)
{
struct lantiq_ssc_spi *spi = spi_master_get_devdata(master);
flush_workqueue(spi->wq);
lantiq_ssc_maskl(spi, 0, SPI_CON_TXOFF | SPI_CON_RXOFF, SPI_CON);
return 0;
}
static void tx_fifo_write(struct lantiq_ssc_spi *spi)
{
const u8 *tx8;
const u16 *tx16;
const u32 *tx32;
u32 data;
unsigned int tx_free = tx_fifo_free(spi);
while (spi->tx_todo && tx_free) {
switch (spi->bits_per_word) {
case 2 ... 8:
tx8 = spi->tx;
data = *tx8;
spi->tx_todo--;
spi->tx++;
break;
case 16:
tx16 = (u16 *) spi->tx;
data = *tx16;
spi->tx_todo -= 2;
spi->tx += 2;
break;
case 32:
tx32 = (u32 *) spi->tx;
data = *tx32;
spi->tx_todo -= 4;
spi->tx += 4;
break;
default:
WARN_ON(1);
data = 0;
break;
}
lantiq_ssc_writel(spi, data, SPI_TB);
tx_free--;
}
}
static void rx_fifo_read_full_duplex(struct lantiq_ssc_spi *spi)
{
u8 *rx8;
u16 *rx16;
u32 *rx32;
u32 data;
unsigned int rx_fill = rx_fifo_level(spi);
while (rx_fill) {
data = lantiq_ssc_readl(spi, SPI_RB);
switch (spi->bits_per_word) {
case 2 ... 8:
rx8 = spi->rx;
*rx8 = data;
spi->rx_todo--;
spi->rx++;
break;
case 16:
rx16 = (u16 *) spi->rx;
*rx16 = data;
spi->rx_todo -= 2;
spi->rx += 2;
break;
case 32:
rx32 = (u32 *) spi->rx;
*rx32 = data;
spi->rx_todo -= 4;
spi->rx += 4;
break;
default:
WARN_ON(1);
break;
}
rx_fill--;
}
}
static void rx_fifo_read_half_duplex(struct lantiq_ssc_spi *spi)
{
u32 data, *rx32;
u8 *rx8;
unsigned int rxbv, shift;
unsigned int rx_fill = rx_fifo_level(spi);
while (rx_fill) {
if (spi->rx_todo < 4) {
rxbv = (lantiq_ssc_readl(spi, SPI_STAT) &
SPI_STAT_RXBV_M) >> SPI_STAT_RXBV_S;
data = lantiq_ssc_readl(spi, SPI_RB);
shift = (rxbv - 1) * 8;
rx8 = spi->rx;
while (rxbv) {
*rx8++ = (data >> shift) & 0xFF;
rxbv--;
shift -= 8;
spi->rx_todo--;
spi->rx++;
}
} else {
data = lantiq_ssc_readl(spi, SPI_RB);
rx32 = (u32 *) spi->rx;
*rx32++ = data;
spi->rx_todo -= 4;
spi->rx += 4;
}
rx_fill--;
}
}
static void rx_request(struct lantiq_ssc_spi *spi)
{
unsigned int rxreq, rxreq_max;
rxreq = spi->rx_todo;
rxreq_max = spi->rx_fifo_size * 4;
if (rxreq > rxreq_max)
rxreq = rxreq_max;
lantiq_ssc_writel(spi, rxreq, SPI_RXREQ);
}
static irqreturn_t lantiq_ssc_xmit_interrupt(int irq, void *data)
{
struct lantiq_ssc_spi *spi = data;
if (spi->tx) {
if (spi->rx && spi->rx_todo)
rx_fifo_read_full_duplex(spi);
if (spi->tx_todo)
tx_fifo_write(spi);
else if (!tx_fifo_level(spi))
goto completed;
} else if (spi->rx) {
if (spi->rx_todo) {
rx_fifo_read_half_duplex(spi);
if (spi->rx_todo)
rx_request(spi);
else
goto completed;
} else {
goto completed;
}
}
return IRQ_HANDLED;
completed:
queue_work(spi->wq, &spi->work);
return IRQ_HANDLED;
}
static irqreturn_t lantiq_ssc_err_interrupt(int irq, void *data)
{
struct lantiq_ssc_spi *spi = data;
u32 stat = lantiq_ssc_readl(spi, SPI_STAT);
if (!(stat & SPI_STAT_ERRORS))
return IRQ_NONE;
if (stat & SPI_STAT_RUE)
dev_err(spi->dev, "receive underflow error\n");
if (stat & SPI_STAT_TUE)
dev_err(spi->dev, "transmit underflow error\n");
if (stat & SPI_STAT_AE)
dev_err(spi->dev, "abort error\n");
if (stat & SPI_STAT_RE)
dev_err(spi->dev, "receive overflow error\n");
if (stat & SPI_STAT_TE)
dev_err(spi->dev, "transmit overflow error\n");
if (stat & SPI_STAT_ME)
dev_err(spi->dev, "mode error\n");
lantiq_ssc_maskl(spi, 0, SPI_WHBSTATE_CLR_ERRORS, SPI_WHBSTATE);
if (spi->master->cur_msg)
spi->master->cur_msg->status = -EIO;
queue_work(spi->wq, &spi->work);
return IRQ_HANDLED;
}
static int transfer_start(struct lantiq_ssc_spi *spi, struct spi_device *spidev,
struct spi_transfer *t)
{
unsigned long flags;
spin_lock_irqsave(&spi->lock, flags);
spi->tx = t->tx_buf;
spi->rx = t->rx_buf;
if (t->tx_buf) {
spi->tx_todo = t->len;
tx_fifo_write(spi);
}
if (spi->rx) {
spi->rx_todo = t->len;
if (!spi->tx)
rx_request(spi);
}
spin_unlock_irqrestore(&spi->lock, flags);
return t->len;
}
static void lantiq_ssc_bussy_work(struct work_struct *work)
{
struct lantiq_ssc_spi *spi;
unsigned long long timeout = 8LL * 1000LL;
unsigned long end;
spi = container_of(work, typeof(*spi), work);
do_div(timeout, spi->speed_hz);
timeout += timeout + 100;
end = jiffies + msecs_to_jiffies(timeout);
do {
u32 stat = lantiq_ssc_readl(spi, SPI_STAT);
if (!(stat & SPI_STAT_BSY)) {
spi_finalize_current_transfer(spi->master);
return;
}
cond_resched();
} while (!time_after_eq(jiffies, end));
if (spi->master->cur_msg)
spi->master->cur_msg->status = -EIO;
spi_finalize_current_transfer(spi->master);
}
static void lantiq_ssc_handle_err(struct spi_master *master,
struct spi_message *message)
{
struct lantiq_ssc_spi *spi = spi_master_get_devdata(master);
rx_fifo_flush(spi);
tx_fifo_flush(spi);
}
static void lantiq_ssc_set_cs(struct spi_device *spidev, bool enable)
{
struct lantiq_ssc_spi *spi = spi_master_get_devdata(spidev->master);
unsigned int cs = spidev->chip_select;
u32 fgpo;
if (!!(spidev->mode & SPI_CS_HIGH) == enable)
fgpo = (1 << (cs - spi->base_cs));
else
fgpo = (1 << (cs - spi->base_cs + SPI_FGPO_SETOUTN_S));
lantiq_ssc_writel(spi, fgpo, SPI_FPGO);
}
static int lantiq_ssc_transfer_one(struct spi_master *master,
struct spi_device *spidev,
struct spi_transfer *t)
{
struct lantiq_ssc_spi *spi = spi_master_get_devdata(master);
hw_setup_transfer(spi, spidev, t);
return transfer_start(spi, spidev, t);
}
static int lantiq_ssc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct spi_master *master;
struct resource *res;
struct lantiq_ssc_spi *spi;
const struct lantiq_ssc_hwcfg *hwcfg;
const struct of_device_id *match;
int err, rx_irq, tx_irq, err_irq;
u32 id, supports_dma, revision;
unsigned int num_cs;
match = of_match_device(lantiq_ssc_match, dev);
if (!match) {
dev_err(dev, "no device match\n");
return -EINVAL;
}
hwcfg = match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "failed to get resources\n");
return -ENXIO;
}
rx_irq = platform_get_irq_byname(pdev, SPI_RX_IRQ_NAME);
if (rx_irq < 0) {
dev_err(dev, "failed to get %s\n", SPI_RX_IRQ_NAME);
return -ENXIO;
}
tx_irq = platform_get_irq_byname(pdev, SPI_TX_IRQ_NAME);
if (tx_irq < 0) {
dev_err(dev, "failed to get %s\n", SPI_TX_IRQ_NAME);
return -ENXIO;
}
err_irq = platform_get_irq_byname(pdev, SPI_ERR_IRQ_NAME);
if (err_irq < 0) {
dev_err(dev, "failed to get %s\n", SPI_ERR_IRQ_NAME);
return -ENXIO;
}
master = spi_alloc_master(dev, sizeof(struct lantiq_ssc_spi));
if (!master)
return -ENOMEM;
spi = spi_master_get_devdata(master);
spi->master = master;
spi->dev = dev;
spi->hwcfg = hwcfg;
platform_set_drvdata(pdev, spi);
spi->regbase = devm_ioremap_resource(dev, res);
if (IS_ERR(spi->regbase)) {
err = PTR_ERR(spi->regbase);
goto err_master_put;
}
err = devm_request_irq(dev, rx_irq, lantiq_ssc_xmit_interrupt,
0, SPI_RX_IRQ_NAME, spi);
if (err)
goto err_master_put;
err = devm_request_irq(dev, tx_irq, lantiq_ssc_xmit_interrupt,
0, SPI_TX_IRQ_NAME, spi);
if (err)
goto err_master_put;
err = devm_request_irq(dev, err_irq, lantiq_ssc_err_interrupt,
0, SPI_ERR_IRQ_NAME, spi);
if (err)
goto err_master_put;
spi->spi_clk = devm_clk_get(dev, "gate");
if (IS_ERR(spi->spi_clk)) {
err = PTR_ERR(spi->spi_clk);
goto err_master_put;
}
err = clk_prepare_enable(spi->spi_clk);
if (err)
goto err_master_put;
#if defined(CONFIG_LANTIQ) && !defined(CONFIG_COMMON_CLK)
spi->fpi_clk = clk_get_fpi();
#else
spi->fpi_clk = clk_get(dev, "freq");
#endif
if (IS_ERR(spi->fpi_clk)) {
err = PTR_ERR(spi->fpi_clk);
goto err_clk_disable;
}
num_cs = 8;
of_property_read_u32(pdev->dev.of_node, "num-cs", &num_cs);
spi->base_cs = 1;
of_property_read_u32(pdev->dev.of_node, "base-cs", &spi->base_cs);
spin_lock_init(&spi->lock);
spi->bits_per_word = 8;
spi->speed_hz = 0;
master->dev.of_node = pdev->dev.of_node;
master->num_chipselect = num_cs;
master->setup = lantiq_ssc_setup;
master->set_cs = lantiq_ssc_set_cs;
master->handle_err = lantiq_ssc_handle_err;
master->prepare_message = lantiq_ssc_prepare_message;
master->unprepare_message = lantiq_ssc_unprepare_message;
master->transfer_one = lantiq_ssc_transfer_one;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_LSB_FIRST | SPI_CS_HIGH |
SPI_LOOP;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(2, 8) |
SPI_BPW_MASK(16) | SPI_BPW_MASK(32);
spi->wq = alloc_ordered_workqueue(dev_name(dev), 0);
if (!spi->wq) {
err = -ENOMEM;
goto err_clk_put;
}
INIT_WORK(&spi->work, lantiq_ssc_bussy_work);
id = lantiq_ssc_readl(spi, SPI_ID);
spi->tx_fifo_size = (id & SPI_ID_TXFS_M) >> SPI_ID_TXFS_S;
spi->rx_fifo_size = (id & SPI_ID_RXFS_M) >> SPI_ID_RXFS_S;
supports_dma = (id & SPI_ID_CFG_M) >> SPI_ID_CFG_S;
revision = id & SPI_ID_REV_M;
lantiq_ssc_hw_init(spi);
dev_info(dev,
"Lantiq SSC SPI controller (Rev %i, TXFS %u, RXFS %u, DMA %u)\n",
revision, spi->tx_fifo_size, spi->rx_fifo_size, supports_dma);
err = devm_spi_register_master(dev, master);
if (err) {
dev_err(dev, "failed to register spi_master\n");
goto err_wq_destroy;
}
return 0;
err_wq_destroy:
destroy_workqueue(spi->wq);
err_clk_put:
clk_put(spi->fpi_clk);
err_clk_disable:
clk_disable_unprepare(spi->spi_clk);
err_master_put:
spi_master_put(master);
return err;
}
static int lantiq_ssc_remove(struct platform_device *pdev)
{
struct lantiq_ssc_spi *spi = platform_get_drvdata(pdev);
lantiq_ssc_writel(spi, 0, SPI_IRNEN);
lantiq_ssc_writel(spi, 0, SPI_CLC);
rx_fifo_flush(spi);
tx_fifo_flush(spi);
hw_enter_config_mode(spi);
destroy_workqueue(spi->wq);
clk_disable_unprepare(spi->spi_clk);
clk_put(spi->fpi_clk);
return 0;
}
