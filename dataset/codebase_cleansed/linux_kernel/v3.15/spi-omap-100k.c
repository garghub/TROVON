static void spi100k_enable_clock(struct spi_master *master)
{
unsigned int val;
struct omap1_spi100k *spi100k = spi_master_get_devdata(master);
val = readw(spi100k->base + SPI_SETUP1);
val |= SPI_SETUP1_CLOCK_ENABLE;
writew(val, spi100k->base + SPI_SETUP1);
}
static void spi100k_disable_clock(struct spi_master *master)
{
unsigned int val;
struct omap1_spi100k *spi100k = spi_master_get_devdata(master);
val = readw(spi100k->base + SPI_SETUP1);
val &= ~SPI_SETUP1_CLOCK_ENABLE;
writew(val, spi100k->base + SPI_SETUP1);
}
static void spi100k_write_data(struct spi_master *master, int len, int data)
{
struct omap1_spi100k *spi100k = spi_master_get_devdata(master);
if (len <= 8) {
data <<= 8;
len = 16;
}
spi100k_enable_clock(master);
writew(data , spi100k->base + SPI_TX_MSB);
writew(SPI_CTRL_SEN(0) |
SPI_CTRL_WORD_SIZE(len) |
SPI_CTRL_WR,
spi100k->base + SPI_CTRL);
while ((readw(spi100k->base + SPI_STATUS) & SPI_STATUS_WE) != SPI_STATUS_WE)
;
udelay(1000);
spi100k_disable_clock(master);
}
static int spi100k_read_data(struct spi_master *master, int len)
{
int dataH, dataL;
struct omap1_spi100k *spi100k = spi_master_get_devdata(master);
if (len <= 8)
len = 16;
spi100k_enable_clock(master);
writew(SPI_CTRL_SEN(0) |
SPI_CTRL_WORD_SIZE(len) |
SPI_CTRL_RD,
spi100k->base + SPI_CTRL);
while ((readw(spi100k->base + SPI_STATUS) & SPI_STATUS_RD) != SPI_STATUS_RD)
;
udelay(1000);
dataL = readw(spi100k->base + SPI_RX_LSB);
dataH = readw(spi100k->base + SPI_RX_MSB);
spi100k_disable_clock(master);
return dataL;
}
static void spi100k_open(struct spi_master *master)
{
struct omap1_spi100k *spi100k = spi_master_get_devdata(master);
writew(SPI_SETUP1_INT_READ_ENABLE |
SPI_SETUP1_INT_WRITE_ENABLE |
SPI_SETUP1_CLOCK_DIVISOR(0), spi100k->base + SPI_SETUP1);
writew(SPI_SETUP2_ACTIVE_EDGE_FALLING |
SPI_SETUP2_NEGATIVE_LEVEL |
SPI_SETUP2_LEVEL_TRIGGER, spi100k->base + SPI_SETUP2);
}
static void omap1_spi100k_force_cs(struct omap1_spi100k *spi100k, int enable)
{
if (enable)
writew(0x05fc, spi100k->base + SPI_CTRL);
else
writew(0x05fd, spi100k->base + SPI_CTRL);
}
static unsigned
omap1_spi100k_txrx_pio(struct spi_device *spi, struct spi_transfer *xfer)
{
struct omap1_spi100k_cs *cs = spi->controller_state;
unsigned int count, c;
int word_len;
count = xfer->len;
c = count;
word_len = cs->word_len;
if (word_len <= 8) {
u8 *rx;
const u8 *tx;
rx = xfer->rx_buf;
tx = xfer->tx_buf;
do {
c -= 1;
if (xfer->tx_buf != NULL)
spi100k_write_data(spi->master, word_len, *tx++);
if (xfer->rx_buf != NULL)
*rx++ = spi100k_read_data(spi->master, word_len);
} while (c);
} else if (word_len <= 16) {
u16 *rx;
const u16 *tx;
rx = xfer->rx_buf;
tx = xfer->tx_buf;
do {
c -= 2;
if (xfer->tx_buf != NULL)
spi100k_write_data(spi->master, word_len, *tx++);
if (xfer->rx_buf != NULL)
*rx++ = spi100k_read_data(spi->master, word_len);
} while (c);
} else if (word_len <= 32) {
u32 *rx;
const u32 *tx;
rx = xfer->rx_buf;
tx = xfer->tx_buf;
do {
c -= 4;
if (xfer->tx_buf != NULL)
spi100k_write_data(spi->master, word_len, *tx);
if (xfer->rx_buf != NULL)
*rx = spi100k_read_data(spi->master, word_len);
} while (c);
}
return count - c;
}
static int omap1_spi100k_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct omap1_spi100k *spi100k = spi_master_get_devdata(spi->master);
struct omap1_spi100k_cs *cs = spi->controller_state;
u8 word_len = spi->bits_per_word;
if (t != NULL && t->bits_per_word)
word_len = t->bits_per_word;
if (!word_len)
word_len = 8;
if (spi->bits_per_word > 32)
return -EINVAL;
cs->word_len = word_len;
writew(0x3e , spi100k->base + SPI_SETUP1);
writew(0x00 , spi100k->base + SPI_STATUS);
writew(0x3e , spi100k->base + SPI_CTRL);
return 0;
}
static int omap1_spi100k_setup(struct spi_device *spi)
{
int ret;
struct omap1_spi100k *spi100k;
struct omap1_spi100k_cs *cs = spi->controller_state;
spi100k = spi_master_get_devdata(spi->master);
if (!cs) {
cs = devm_kzalloc(&spi->dev, sizeof(*cs), GFP_KERNEL);
if (!cs)
return -ENOMEM;
cs->base = spi100k->base + spi->chip_select * 0x14;
spi->controller_state = cs;
}
spi100k_open(spi->master);
clk_prepare_enable(spi100k->ick);
clk_prepare_enable(spi100k->fck);
ret = omap1_spi100k_setup_transfer(spi, NULL);
clk_disable_unprepare(spi100k->ick);
clk_disable_unprepare(spi100k->fck);
return ret;
}
static int omap1_spi100k_prepare_hardware(struct spi_master *master)
{
struct omap1_spi100k *spi100k = spi_master_get_devdata(master);
clk_prepare_enable(spi100k->ick);
clk_prepare_enable(spi100k->fck);
return 0;
}
static int omap1_spi100k_transfer_one_message(struct spi_master *master,
struct spi_message *m)
{
struct omap1_spi100k *spi100k = spi_master_get_devdata(master);
struct spi_device *spi = m->spi;
struct spi_transfer *t = NULL;
int cs_active = 0;
int par_override = 0;
int status = 0;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (t->tx_buf == NULL && t->rx_buf == NULL && t->len) {
status = -EINVAL;
break;
}
if (par_override || t->speed_hz || t->bits_per_word) {
par_override = 1;
status = omap1_spi100k_setup_transfer(spi, t);
if (status < 0)
break;
if (!t->speed_hz && !t->bits_per_word)
par_override = 0;
}
if (!cs_active) {
omap1_spi100k_force_cs(spi100k, 1);
cs_active = 1;
}
if (t->len) {
unsigned count;
count = omap1_spi100k_txrx_pio(spi, t);
m->actual_length += count;
if (count != t->len) {
status = -EIO;
break;
}
}
if (t->delay_usecs)
udelay(t->delay_usecs);
if (t->cs_change) {
omap1_spi100k_force_cs(spi100k, 0);
cs_active = 0;
}
}
if (par_override) {
par_override = 0;
status = omap1_spi100k_setup_transfer(spi, NULL);
}
if (cs_active)
omap1_spi100k_force_cs(spi100k, 0);
m->status = status;
spi_finalize_current_message(master);
return status;
}
static int omap1_spi100k_unprepare_hardware(struct spi_master *master)
{
struct omap1_spi100k *spi100k = spi_master_get_devdata(master);
clk_disable_unprepare(spi100k->ick);
clk_disable_unprepare(spi100k->fck);
return 0;
}
static int omap1_spi100k_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct omap1_spi100k *spi100k;
int status = 0;
if (!pdev->id)
return -EINVAL;
master = spi_alloc_master(&pdev->dev, sizeof(*spi100k));
if (master == NULL) {
dev_dbg(&pdev->dev, "master allocation failed\n");
return -ENOMEM;
}
if (pdev->id != -1)
master->bus_num = pdev->id;
master->setup = omap1_spi100k_setup;
master->transfer_one_message = omap1_spi100k_transfer_one_message;
master->prepare_transfer_hardware = omap1_spi100k_prepare_hardware;
master->unprepare_transfer_hardware = omap1_spi100k_unprepare_hardware;
master->cleanup = NULL;
master->num_chipselect = 2;
master->mode_bits = MODEBITS;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 32);
master->min_speed_hz = OMAP1_SPI100K_MAX_FREQ/(1<<16);
master->max_speed_hz = OMAP1_SPI100K_MAX_FREQ;
platform_set_drvdata(pdev, master);
spi100k = spi_master_get_devdata(master);
spi100k->base = (void __iomem *)dev_get_platdata(&pdev->dev);
spi100k->ick = devm_clk_get(&pdev->dev, "ick");
if (IS_ERR(spi100k->ick)) {
dev_dbg(&pdev->dev, "can't get spi100k_ick\n");
status = PTR_ERR(spi100k->ick);
goto err;
}
spi100k->fck = devm_clk_get(&pdev->dev, "fck");
if (IS_ERR(spi100k->fck)) {
dev_dbg(&pdev->dev, "can't get spi100k_fck\n");
status = PTR_ERR(spi100k->fck);
goto err;
}
status = devm_spi_register_master(&pdev->dev, master);
if (status < 0)
goto err;
return status;
err:
spi_master_put(master);
return status;
}
