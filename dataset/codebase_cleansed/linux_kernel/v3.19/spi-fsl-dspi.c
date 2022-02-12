static inline int is_double_byte_mode(struct fsl_dspi *dspi)
{
unsigned int val;
regmap_read(dspi->regmap, SPI_CTAR(dspi->cs), &val);
return ((val & SPI_FRAME_BITS_MASK) == SPI_FRAME_BITS(8)) ? 0 : 1;
}
static void hz_to_spi_baud(char *pbr, char *br, int speed_hz,
unsigned long clkrate)
{
int pbr_tbl[4] = {2, 3, 5, 7};
int brs[16] = { 2, 4, 6, 8,
16, 32, 64, 128,
256, 512, 1024, 2048,
4096, 8192, 16384, 32768 };
int temp, i = 0, j = 0;
temp = clkrate / 2 / speed_hz;
for (i = 0; i < ARRAY_SIZE(pbr_tbl); i++)
for (j = 0; j < ARRAY_SIZE(brs); j++) {
if (pbr_tbl[i] * brs[j] >= temp) {
*pbr = i;
*br = j;
return;
}
}
pr_warn("Can not find valid baud rate,speed_hz is %d,clkrate is %ld\
,we use the max prescaler value.\n", speed_hz, clkrate);
*pbr = ARRAY_SIZE(pbr_tbl) - 1;
*br = ARRAY_SIZE(brs) - 1;
}
static int dspi_transfer_write(struct fsl_dspi *dspi)
{
int tx_count = 0;
int tx_word;
u16 d16;
u8 d8;
u32 dspi_pushr = 0;
int first = 1;
tx_word = is_double_byte_mode(dspi);
if (tx_word && (dspi->len == 1)) {
dspi->dataflags |= TRAN_STATE_WORD_ODD_NUM;
regmap_update_bits(dspi->regmap, SPI_CTAR(dspi->cs),
SPI_FRAME_BITS_MASK, SPI_FRAME_BITS(8));
tx_word = 0;
}
while (dspi->len && (tx_count < DSPI_FIFO_SIZE)) {
if (tx_word) {
if (dspi->len == 1)
break;
if (!(dspi->dataflags & TRAN_STATE_TX_VOID)) {
d16 = *(u16 *)dspi->tx;
dspi->tx += 2;
} else {
d16 = dspi->void_write_data;
}
dspi_pushr = SPI_PUSHR_TXDATA(d16) |
SPI_PUSHR_PCS(dspi->cs) |
SPI_PUSHR_CTAS(dspi->cs) |
SPI_PUSHR_CONT;
dspi->len -= 2;
} else {
if (!(dspi->dataflags & TRAN_STATE_TX_VOID)) {
d8 = *(u8 *)dspi->tx;
dspi->tx++;
} else {
d8 = (u8)dspi->void_write_data;
}
dspi_pushr = SPI_PUSHR_TXDATA(d8) |
SPI_PUSHR_PCS(dspi->cs) |
SPI_PUSHR_CTAS(dspi->cs) |
SPI_PUSHR_CONT;
dspi->len--;
}
if (dspi->len == 0 || tx_count == DSPI_FIFO_SIZE - 1) {
dspi_pushr |= SPI_PUSHR_EOQ;
} else if (tx_word && (dspi->len == 1))
dspi_pushr |= SPI_PUSHR_EOQ;
if (first) {
first = 0;
dspi_pushr |= SPI_PUSHR_CTCNT;
}
regmap_write(dspi->regmap, SPI_PUSHR, dspi_pushr);
tx_count++;
}
return tx_count * (tx_word + 1);
}
static int dspi_transfer_read(struct fsl_dspi *dspi)
{
int rx_count = 0;
int rx_word = is_double_byte_mode(dspi);
u16 d;
while ((dspi->rx < dspi->rx_end)
&& (rx_count < DSPI_FIFO_SIZE)) {
if (rx_word) {
unsigned int val;
if ((dspi->rx_end - dspi->rx) == 1)
break;
regmap_read(dspi->regmap, SPI_POPR, &val);
d = SPI_POPR_RXDATA(val);
if (!(dspi->dataflags & TRAN_STATE_RX_VOID))
*(u16 *)dspi->rx = d;
dspi->rx += 2;
} else {
unsigned int val;
regmap_read(dspi->regmap, SPI_POPR, &val);
d = SPI_POPR_RXDATA(val);
if (!(dspi->dataflags & TRAN_STATE_RX_VOID))
*(u8 *)dspi->rx = d;
dspi->rx++;
}
rx_count++;
}
return rx_count;
}
static int dspi_txrx_transfer(struct spi_device *spi, struct spi_transfer *t)
{
struct fsl_dspi *dspi = spi_master_get_devdata(spi->master);
dspi->cur_transfer = t;
dspi->cur_chip = spi_get_ctldata(spi);
dspi->cs = spi->chip_select;
dspi->void_write_data = dspi->cur_chip->void_write_data;
dspi->dataflags = 0;
dspi->tx = (void *)t->tx_buf;
dspi->tx_end = dspi->tx + t->len;
dspi->rx = t->rx_buf;
dspi->rx_end = dspi->rx + t->len;
dspi->len = t->len;
if (!dspi->rx)
dspi->dataflags |= TRAN_STATE_RX_VOID;
if (!dspi->tx)
dspi->dataflags |= TRAN_STATE_TX_VOID;
regmap_write(dspi->regmap, SPI_MCR, dspi->cur_chip->mcr_val);
regmap_write(dspi->regmap, SPI_CTAR(dspi->cs), dspi->cur_chip->ctar_val);
regmap_write(dspi->regmap, SPI_RSER, SPI_RSER_EOQFE);
if (t->speed_hz)
regmap_write(dspi->regmap, SPI_CTAR(dspi->cs),
dspi->cur_chip->ctar_val);
dspi_transfer_write(dspi);
if (wait_event_interruptible(dspi->waitq, dspi->waitflags))
dev_err(&dspi->pdev->dev, "wait transfer complete fail!\n");
dspi->waitflags = 0;
return t->len - dspi->len;
}
static void dspi_chipselect(struct spi_device *spi, int value)
{
struct fsl_dspi *dspi = spi_master_get_devdata(spi->master);
unsigned int pushr;
regmap_read(dspi->regmap, SPI_PUSHR, &pushr);
switch (value) {
case BITBANG_CS_ACTIVE:
pushr |= SPI_PUSHR_CONT;
break;
case BITBANG_CS_INACTIVE:
pushr &= ~SPI_PUSHR_CONT;
break;
}
regmap_write(dspi->regmap, SPI_PUSHR, pushr);
}
static int dspi_setup_transfer(struct spi_device *spi, struct spi_transfer *t)
{
struct chip_data *chip;
struct fsl_dspi *dspi = spi_master_get_devdata(spi->master);
unsigned char br = 0, pbr = 0, fmsz = 0;
chip = spi_get_ctldata(spi);
if (chip == NULL) {
chip = kzalloc(sizeof(struct chip_data), GFP_KERNEL);
if (!chip)
return -ENOMEM;
}
chip->mcr_val = SPI_MCR_MASTER | SPI_MCR_PCSIS |
SPI_MCR_CLR_TXF | SPI_MCR_CLR_RXF;
if ((spi->bits_per_word >= 4) && (spi->bits_per_word <= 16)) {
fmsz = spi->bits_per_word - 1;
} else {
pr_err("Invalid wordsize\n");
return -ENODEV;
}
chip->void_write_data = 0;
hz_to_spi_baud(&pbr, &br,
spi->max_speed_hz, clk_get_rate(dspi->clk));
chip->ctar_val = SPI_CTAR_FMSZ(fmsz)
| SPI_CTAR_CPOL(spi->mode & SPI_CPOL ? 1 : 0)
| SPI_CTAR_CPHA(spi->mode & SPI_CPHA ? 1 : 0)
| SPI_CTAR_LSBFE(spi->mode & SPI_LSB_FIRST ? 1 : 0)
| SPI_CTAR_PBR(pbr)
| SPI_CTAR_BR(br);
spi_set_ctldata(spi, chip);
return 0;
}
static int dspi_setup(struct spi_device *spi)
{
if (!spi->max_speed_hz)
return -EINVAL;
return dspi_setup_transfer(spi, NULL);
}
static void dspi_cleanup(struct spi_device *spi)
{
struct chip_data *chip = spi_get_ctldata((struct spi_device *)spi);
dev_dbg(&spi->dev, "spi_device %u.%u cleanup\n",
spi->master->bus_num, spi->chip_select);
kfree(chip);
}
static irqreturn_t dspi_interrupt(int irq, void *dev_id)
{
struct fsl_dspi *dspi = (struct fsl_dspi *)dev_id;
regmap_write(dspi->regmap, SPI_SR, SPI_SR_EOQF);
dspi_transfer_read(dspi);
if (!dspi->len) {
if (dspi->dataflags & TRAN_STATE_WORD_ODD_NUM)
regmap_update_bits(dspi->regmap, SPI_CTAR(dspi->cs),
SPI_FRAME_BITS_MASK, SPI_FRAME_BITS(16));
dspi->waitflags = 1;
wake_up_interruptible(&dspi->waitq);
} else {
dspi_transfer_write(dspi);
return IRQ_HANDLED;
}
return IRQ_HANDLED;
}
static int dspi_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct fsl_dspi *dspi = spi_master_get_devdata(master);
spi_master_suspend(master);
clk_disable_unprepare(dspi->clk);
return 0;
}
static int dspi_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct fsl_dspi *dspi = spi_master_get_devdata(master);
clk_prepare_enable(dspi->clk);
spi_master_resume(master);
return 0;
}
static int dspi_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct spi_master *master;
struct fsl_dspi *dspi;
struct resource *res;
void __iomem *base;
int ret = 0, cs_num, bus_num;
master = spi_alloc_master(&pdev->dev, sizeof(struct fsl_dspi));
if (!master)
return -ENOMEM;
dspi = spi_master_get_devdata(master);
dspi->pdev = pdev;
dspi->bitbang.master = master;
dspi->bitbang.chipselect = dspi_chipselect;
dspi->bitbang.setup_transfer = dspi_setup_transfer;
dspi->bitbang.txrx_bufs = dspi_txrx_transfer;
dspi->bitbang.master->setup = dspi_setup;
dspi->bitbang.master->dev.of_node = pdev->dev.of_node;
master->cleanup = dspi_cleanup;
master->mode_bits = SPI_CPOL | SPI_CPHA;
master->bits_per_word_mask = SPI_BPW_MASK(4) | SPI_BPW_MASK(8) |
SPI_BPW_MASK(16);
ret = of_property_read_u32(np, "spi-num-chipselects", &cs_num);
if (ret < 0) {
dev_err(&pdev->dev, "can't get spi-num-chipselects\n");
goto out_master_put;
}
master->num_chipselect = cs_num;
ret = of_property_read_u32(np, "bus-num", &bus_num);
if (ret < 0) {
dev_err(&pdev->dev, "can't get bus-num\n");
goto out_master_put;
}
master->bus_num = bus_num;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base)) {
ret = PTR_ERR(base);
goto out_master_put;
}
dspi->regmap = devm_regmap_init_mmio_clk(&pdev->dev, "dspi", base,
&dspi_regmap_config);
if (IS_ERR(dspi->regmap)) {
dev_err(&pdev->dev, "failed to init regmap: %ld\n",
PTR_ERR(dspi->regmap));
return PTR_ERR(dspi->regmap);
}
dspi->irq = platform_get_irq(pdev, 0);
if (dspi->irq < 0) {
dev_err(&pdev->dev, "can't get platform irq\n");
ret = dspi->irq;
goto out_master_put;
}
ret = devm_request_irq(&pdev->dev, dspi->irq, dspi_interrupt, 0,
pdev->name, dspi);
if (ret < 0) {
dev_err(&pdev->dev, "Unable to attach DSPI interrupt\n");
goto out_master_put;
}
dspi->clk = devm_clk_get(&pdev->dev, "dspi");
if (IS_ERR(dspi->clk)) {
ret = PTR_ERR(dspi->clk);
dev_err(&pdev->dev, "unable to get clock\n");
goto out_master_put;
}
clk_prepare_enable(dspi->clk);
init_waitqueue_head(&dspi->waitq);
platform_set_drvdata(pdev, master);
ret = spi_bitbang_start(&dspi->bitbang);
if (ret != 0) {
dev_err(&pdev->dev, "Problem registering DSPI master\n");
goto out_clk_put;
}
return ret;
out_clk_put:
clk_disable_unprepare(dspi->clk);
out_master_put:
spi_master_put(master);
return ret;
}
static int dspi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct fsl_dspi *dspi = spi_master_get_devdata(master);
spi_bitbang_stop(&dspi->bitbang);
clk_disable_unprepare(dspi->clk);
spi_master_put(dspi->bitbang.master);
return 0;
}
