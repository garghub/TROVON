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
int scale_needed, scale, minscale = INT_MAX;
int i, j;
scale_needed = clkrate / speed_hz;
if (clkrate % speed_hz)
scale_needed++;
for (i = 0; i < ARRAY_SIZE(brs); i++)
for (j = 0; j < ARRAY_SIZE(pbr_tbl); j++) {
scale = brs[i] * pbr_tbl[j];
if (scale >= scale_needed) {
if (scale < minscale) {
minscale = scale;
*br = i;
*pbr = j;
}
break;
}
}
if (minscale == INT_MAX) {
pr_warn("Can not find valid baud rate,speed_hz is %d,clkrate is %ld, we use the max prescaler value.\n",
speed_hz, clkrate);
*pbr = ARRAY_SIZE(pbr_tbl) - 1;
*br = ARRAY_SIZE(brs) - 1;
}
}
static void ns_delay_scale(char *psc, char *sc, int delay_ns,
unsigned long clkrate)
{
int pscale_tbl[4] = {1, 3, 5, 7};
int scale_needed, scale, minscale = INT_MAX;
int i, j;
u32 remainder;
scale_needed = div_u64_rem((u64)delay_ns * clkrate, NSEC_PER_SEC,
&remainder);
if (remainder)
scale_needed++;
for (i = 0; i < ARRAY_SIZE(pscale_tbl); i++)
for (j = 0; j <= SPI_CTAR_SCALE_BITS; j++) {
scale = pscale_tbl[i] * (2 << j);
if (scale >= scale_needed) {
if (scale < minscale) {
minscale = scale;
*psc = i;
*sc = j;
}
break;
}
}
if (minscale == INT_MAX) {
pr_warn("Cannot find correct scale values for %dns delay at clkrate %ld, using max prescaler value",
delay_ns, clkrate);
*psc = ARRAY_SIZE(pscale_tbl) - 1;
*sc = SPI_CTAR_SCALE_BITS;
}
}
static u32 dspi_data_to_pushr(struct fsl_dspi *dspi, int tx_word)
{
u16 d16;
if (!(dspi->dataflags & TRAN_STATE_TX_VOID))
d16 = tx_word ? *(u16 *)dspi->tx : *(u8 *)dspi->tx;
else
d16 = dspi->void_write_data;
dspi->tx += tx_word + 1;
dspi->len -= tx_word + 1;
return SPI_PUSHR_TXDATA(d16) |
SPI_PUSHR_PCS(dspi->cs) |
SPI_PUSHR_CTAS(dspi->cs) |
SPI_PUSHR_CONT;
}
static void dspi_data_from_popr(struct fsl_dspi *dspi, int rx_word)
{
u16 d;
unsigned int val;
regmap_read(dspi->regmap, SPI_POPR, &val);
d = SPI_POPR_RXDATA(val);
if (!(dspi->dataflags & TRAN_STATE_RX_VOID))
rx_word ? (*(u16 *)dspi->rx = d) : (*(u8 *)dspi->rx = d);
dspi->rx += rx_word + 1;
}
static int dspi_eoq_write(struct fsl_dspi *dspi)
{
int tx_count = 0;
int tx_word;
u32 dspi_pushr = 0;
tx_word = is_double_byte_mode(dspi);
while (dspi->len && (tx_count < DSPI_FIFO_SIZE)) {
if (tx_word && (dspi->len == 1)) {
dspi->dataflags |= TRAN_STATE_WORD_ODD_NUM;
regmap_update_bits(dspi->regmap, SPI_CTAR(dspi->cs),
SPI_FRAME_BITS_MASK, SPI_FRAME_BITS(8));
tx_word = 0;
}
dspi_pushr = dspi_data_to_pushr(dspi, tx_word);
if (dspi->len == 0 || tx_count == DSPI_FIFO_SIZE - 1) {
dspi_pushr |= SPI_PUSHR_EOQ;
if ((dspi->cs_change) && (!dspi->len))
dspi_pushr &= ~SPI_PUSHR_CONT;
} else if (tx_word && (dspi->len == 1))
dspi_pushr |= SPI_PUSHR_EOQ;
regmap_write(dspi->regmap, SPI_PUSHR, dspi_pushr);
tx_count++;
}
return tx_count * (tx_word + 1);
}
static int dspi_eoq_read(struct fsl_dspi *dspi)
{
int rx_count = 0;
int rx_word = is_double_byte_mode(dspi);
while ((dspi->rx < dspi->rx_end)
&& (rx_count < DSPI_FIFO_SIZE)) {
if (rx_word && (dspi->rx_end - dspi->rx) == 1)
rx_word = 0;
dspi_data_from_popr(dspi, rx_word);
rx_count++;
}
return rx_count;
}
static int dspi_tcfq_write(struct fsl_dspi *dspi)
{
int tx_word;
u32 dspi_pushr = 0;
tx_word = is_double_byte_mode(dspi);
if (tx_word && (dspi->len == 1)) {
dspi->dataflags |= TRAN_STATE_WORD_ODD_NUM;
regmap_update_bits(dspi->regmap, SPI_CTAR(dspi->cs),
SPI_FRAME_BITS_MASK, SPI_FRAME_BITS(8));
tx_word = 0;
}
dspi_pushr = dspi_data_to_pushr(dspi, tx_word);
if ((dspi->cs_change) && (!dspi->len))
dspi_pushr &= ~SPI_PUSHR_CONT;
regmap_write(dspi->regmap, SPI_PUSHR, dspi_pushr);
return tx_word + 1;
}
static void dspi_tcfq_read(struct fsl_dspi *dspi)
{
int rx_word = is_double_byte_mode(dspi);
if (rx_word && (dspi->rx_end - dspi->rx) == 1)
rx_word = 0;
dspi_data_from_popr(dspi, rx_word);
}
static int dspi_transfer_one_message(struct spi_master *master,
struct spi_message *message)
{
struct fsl_dspi *dspi = spi_master_get_devdata(master);
struct spi_device *spi = message->spi;
struct spi_transfer *transfer;
int status = 0;
enum dspi_trans_mode trans_mode;
u32 spi_tcr;
regmap_read(dspi->regmap, SPI_TCR, &spi_tcr);
dspi->spi_tcnt = SPI_TCR_GET_TCNT(spi_tcr);
message->actual_length = 0;
list_for_each_entry(transfer, &message->transfers, transfer_list) {
dspi->cur_transfer = transfer;
dspi->cur_msg = message;
dspi->cur_chip = spi_get_ctldata(spi);
dspi->cs = spi->chip_select;
dspi->cs_change = 0;
if (dspi->cur_transfer->transfer_list.next
== &dspi->cur_msg->transfers)
dspi->cs_change = 1;
dspi->void_write_data = dspi->cur_chip->void_write_data;
dspi->dataflags = 0;
dspi->tx = (void *)transfer->tx_buf;
dspi->tx_end = dspi->tx + transfer->len;
dspi->rx = transfer->rx_buf;
dspi->rx_end = dspi->rx + transfer->len;
dspi->len = transfer->len;
if (!dspi->rx)
dspi->dataflags |= TRAN_STATE_RX_VOID;
if (!dspi->tx)
dspi->dataflags |= TRAN_STATE_TX_VOID;
regmap_write(dspi->regmap, SPI_MCR, dspi->cur_chip->mcr_val);
regmap_update_bits(dspi->regmap, SPI_MCR,
SPI_MCR_CLR_TXF | SPI_MCR_CLR_RXF,
SPI_MCR_CLR_TXF | SPI_MCR_CLR_RXF);
regmap_write(dspi->regmap, SPI_CTAR(dspi->cs),
dspi->cur_chip->ctar_val);
if (transfer->speed_hz)
regmap_write(dspi->regmap, SPI_CTAR(dspi->cs),
dspi->cur_chip->ctar_val);
trans_mode = dspi->devtype_data->trans_mode;
switch (trans_mode) {
case DSPI_EOQ_MODE:
regmap_write(dspi->regmap, SPI_RSER, SPI_RSER_EOQFE);
dspi_eoq_write(dspi);
break;
case DSPI_TCFQ_MODE:
regmap_write(dspi->regmap, SPI_RSER, SPI_RSER_TCFQE);
dspi_tcfq_write(dspi);
break;
default:
dev_err(&dspi->pdev->dev, "unsupported trans_mode %u\n",
trans_mode);
status = -EINVAL;
goto out;
}
if (wait_event_interruptible(dspi->waitq, dspi->waitflags))
dev_err(&dspi->pdev->dev, "wait transfer complete fail!\n");
dspi->waitflags = 0;
if (transfer->delay_usecs)
udelay(transfer->delay_usecs);
}
out:
message->status = status;
spi_finalize_current_message(master);
return status;
}
static int dspi_setup(struct spi_device *spi)
{
struct chip_data *chip;
struct fsl_dspi *dspi = spi_master_get_devdata(spi->master);
u32 cs_sck_delay = 0, sck_cs_delay = 0;
unsigned char br = 0, pbr = 0, pcssck = 0, cssck = 0;
unsigned char pasc = 0, asc = 0, fmsz = 0;
unsigned long clkrate;
if ((spi->bits_per_word >= 4) && (spi->bits_per_word <= 16)) {
fmsz = spi->bits_per_word - 1;
} else {
pr_err("Invalid wordsize\n");
return -ENODEV;
}
chip = spi_get_ctldata(spi);
if (chip == NULL) {
chip = kzalloc(sizeof(struct chip_data), GFP_KERNEL);
if (!chip)
return -ENOMEM;
}
of_property_read_u32(spi->dev.of_node, "fsl,spi-cs-sck-delay",
&cs_sck_delay);
of_property_read_u32(spi->dev.of_node, "fsl,spi-sck-cs-delay",
&sck_cs_delay);
chip->mcr_val = SPI_MCR_MASTER | SPI_MCR_PCSIS |
SPI_MCR_CLR_TXF | SPI_MCR_CLR_RXF;
chip->void_write_data = 0;
clkrate = clk_get_rate(dspi->clk);
hz_to_spi_baud(&pbr, &br, spi->max_speed_hz, clkrate);
ns_delay_scale(&pcssck, &cssck, cs_sck_delay, clkrate);
ns_delay_scale(&pasc, &asc, sck_cs_delay, clkrate);
chip->ctar_val = SPI_CTAR_FMSZ(fmsz)
| SPI_CTAR_CPOL(spi->mode & SPI_CPOL ? 1 : 0)
| SPI_CTAR_CPHA(spi->mode & SPI_CPHA ? 1 : 0)
| SPI_CTAR_LSBFE(spi->mode & SPI_LSB_FIRST ? 1 : 0)
| SPI_CTAR_PCSSCK(pcssck)
| SPI_CTAR_CSSCK(cssck)
| SPI_CTAR_PASC(pasc)
| SPI_CTAR_ASC(asc)
| SPI_CTAR_PBR(pbr)
| SPI_CTAR_BR(br);
spi_set_ctldata(spi, chip);
return 0;
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
struct spi_message *msg = dspi->cur_msg;
enum dspi_trans_mode trans_mode;
u32 spi_sr, spi_tcr;
u32 spi_tcnt, tcnt_diff;
int tx_word;
regmap_read(dspi->regmap, SPI_SR, &spi_sr);
regmap_write(dspi->regmap, SPI_SR, spi_sr);
if (spi_sr & (SPI_SR_EOQF | SPI_SR_TCFQF)) {
tx_word = is_double_byte_mode(dspi);
regmap_read(dspi->regmap, SPI_TCR, &spi_tcr);
spi_tcnt = SPI_TCR_GET_TCNT(spi_tcr);
tcnt_diff = ((spi_tcnt + SPI_TCR_TCNT_MAX) - dspi->spi_tcnt)
% SPI_TCR_TCNT_MAX;
tcnt_diff *= (tx_word + 1);
if (dspi->dataflags & TRAN_STATE_WORD_ODD_NUM)
tcnt_diff--;
msg->actual_length += tcnt_diff;
dspi->spi_tcnt = spi_tcnt;
trans_mode = dspi->devtype_data->trans_mode;
switch (trans_mode) {
case DSPI_EOQ_MODE:
dspi_eoq_read(dspi);
break;
case DSPI_TCFQ_MODE:
dspi_tcfq_read(dspi);
break;
default:
dev_err(&dspi->pdev->dev, "unsupported trans_mode %u\n",
trans_mode);
return IRQ_HANDLED;
}
if (!dspi->len) {
if (dspi->dataflags & TRAN_STATE_WORD_ODD_NUM) {
regmap_update_bits(dspi->regmap,
SPI_CTAR(dspi->cs),
SPI_FRAME_BITS_MASK,
SPI_FRAME_BITS(16));
dspi->dataflags &= ~TRAN_STATE_WORD_ODD_NUM;
}
dspi->waitflags = 1;
wake_up_interruptible(&dspi->waitq);
} else {
switch (trans_mode) {
case DSPI_EOQ_MODE:
dspi_eoq_write(dspi);
break;
case DSPI_TCFQ_MODE:
dspi_tcfq_write(dspi);
break;
default:
dev_err(&dspi->pdev->dev,
"unsupported trans_mode %u\n",
trans_mode);
}
}
}
return IRQ_HANDLED;
}
static int dspi_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct fsl_dspi *dspi = spi_master_get_devdata(master);
spi_master_suspend(master);
clk_disable_unprepare(dspi->clk);
pinctrl_pm_select_sleep_state(dev);
return 0;
}
static int dspi_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct fsl_dspi *dspi = spi_master_get_devdata(master);
pinctrl_pm_select_default_state(dev);
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
const struct of_device_id *of_id =
of_match_device(fsl_dspi_dt_ids, &pdev->dev);
master = spi_alloc_master(&pdev->dev, sizeof(struct fsl_dspi));
if (!master)
return -ENOMEM;
dspi = spi_master_get_devdata(master);
dspi->pdev = pdev;
dspi->master = master;
master->transfer = NULL;
master->setup = dspi_setup;
master->transfer_one_message = dspi_transfer_one_message;
master->dev.of_node = pdev->dev.of_node;
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
dspi->devtype_data = (struct fsl_dspi_devtype_data *)of_id->data;
if (!dspi->devtype_data) {
dev_err(&pdev->dev, "can't get devtype_data\n");
ret = -EFAULT;
goto out_master_put;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base)) {
ret = PTR_ERR(base);
goto out_master_put;
}
dspi->regmap = devm_regmap_init_mmio_clk(&pdev->dev, NULL, base,
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
ret = spi_register_master(master);
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
clk_disable_unprepare(dspi->clk);
spi_unregister_master(dspi->master);
spi_master_put(dspi->master);
return 0;
}
