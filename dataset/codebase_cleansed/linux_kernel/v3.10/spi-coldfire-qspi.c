static void mcfqspi_wr_qmr(struct mcfqspi *mcfqspi, u16 val)
{
writew(val, mcfqspi->iobase + MCFQSPI_QMR);
}
static void mcfqspi_wr_qdlyr(struct mcfqspi *mcfqspi, u16 val)
{
writew(val, mcfqspi->iobase + MCFQSPI_QDLYR);
}
static u16 mcfqspi_rd_qdlyr(struct mcfqspi *mcfqspi)
{
return readw(mcfqspi->iobase + MCFQSPI_QDLYR);
}
static void mcfqspi_wr_qwr(struct mcfqspi *mcfqspi, u16 val)
{
writew(val, mcfqspi->iobase + MCFQSPI_QWR);
}
static void mcfqspi_wr_qir(struct mcfqspi *mcfqspi, u16 val)
{
writew(val, mcfqspi->iobase + MCFQSPI_QIR);
}
static void mcfqspi_wr_qar(struct mcfqspi *mcfqspi, u16 val)
{
writew(val, mcfqspi->iobase + MCFQSPI_QAR);
}
static void mcfqspi_wr_qdr(struct mcfqspi *mcfqspi, u16 val)
{
writew(val, mcfqspi->iobase + MCFQSPI_QDR);
}
static u16 mcfqspi_rd_qdr(struct mcfqspi *mcfqspi)
{
return readw(mcfqspi->iobase + MCFQSPI_QDR);
}
static void mcfqspi_cs_select(struct mcfqspi *mcfqspi, u8 chip_select,
bool cs_high)
{
mcfqspi->cs_control->select(mcfqspi->cs_control, chip_select, cs_high);
}
static void mcfqspi_cs_deselect(struct mcfqspi *mcfqspi, u8 chip_select,
bool cs_high)
{
mcfqspi->cs_control->deselect(mcfqspi->cs_control, chip_select, cs_high);
}
static int mcfqspi_cs_setup(struct mcfqspi *mcfqspi)
{
return (mcfqspi->cs_control && mcfqspi->cs_control->setup) ?
mcfqspi->cs_control->setup(mcfqspi->cs_control) : 0;
}
static void mcfqspi_cs_teardown(struct mcfqspi *mcfqspi)
{
if (mcfqspi->cs_control && mcfqspi->cs_control->teardown)
mcfqspi->cs_control->teardown(mcfqspi->cs_control);
}
static u8 mcfqspi_qmr_baud(u32 speed_hz)
{
return clamp((MCFQSPI_BUSCLK + speed_hz - 1) / speed_hz, 2u, 255u);
}
static bool mcfqspi_qdlyr_spe(struct mcfqspi *mcfqspi)
{
return mcfqspi_rd_qdlyr(mcfqspi) & MCFQSPI_QDLYR_SPE;
}
static irqreturn_t mcfqspi_irq_handler(int this_irq, void *dev_id)
{
struct mcfqspi *mcfqspi = dev_id;
mcfqspi_wr_qir(mcfqspi, MCFQSPI_QIR_SPIFE | MCFQSPI_QIR_SPIF);
wake_up(&mcfqspi->waitq);
return IRQ_HANDLED;
}
static void mcfqspi_transfer_msg8(struct mcfqspi *mcfqspi, unsigned count,
const u8 *txbuf, u8 *rxbuf)
{
unsigned i, n, offset = 0;
n = min(count, 16u);
mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_CMDBUF);
for (i = 0; i < n; ++i)
mcfqspi_wr_qdr(mcfqspi, MCFQSPI_QCR_BITSE);
mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_TXBUF);
if (txbuf)
for (i = 0; i < n; ++i)
mcfqspi_wr_qdr(mcfqspi, *txbuf++);
else
for (i = 0; i < count; ++i)
mcfqspi_wr_qdr(mcfqspi, 0);
count -= n;
if (count) {
u16 qwr = 0xf08;
mcfqspi_wr_qwr(mcfqspi, 0x700);
mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
do {
wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
mcfqspi_wr_qwr(mcfqspi, qwr);
mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
if (rxbuf) {
mcfqspi_wr_qar(mcfqspi,
MCFQSPI_QAR_RXBUF + offset);
for (i = 0; i < 8; ++i)
*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
}
n = min(count, 8u);
if (txbuf) {
mcfqspi_wr_qar(mcfqspi,
MCFQSPI_QAR_TXBUF + offset);
for (i = 0; i < n; ++i)
mcfqspi_wr_qdr(mcfqspi, *txbuf++);
}
qwr = (offset ? 0x808 : 0) + ((n - 1) << 8);
offset ^= 8;
count -= n;
} while (count);
wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
mcfqspi_wr_qwr(mcfqspi, qwr);
mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
if (rxbuf) {
mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_RXBUF + offset);
for (i = 0; i < 8; ++i)
*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
offset ^= 8;
}
} else {
mcfqspi_wr_qwr(mcfqspi, (n - 1) << 8);
mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
}
wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
if (rxbuf) {
mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_RXBUF + offset);
for (i = 0; i < n; ++i)
*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
}
}
static void mcfqspi_transfer_msg16(struct mcfqspi *mcfqspi, unsigned count,
const u16 *txbuf, u16 *rxbuf)
{
unsigned i, n, offset = 0;
n = min(count, 16u);
mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_CMDBUF);
for (i = 0; i < n; ++i)
mcfqspi_wr_qdr(mcfqspi, MCFQSPI_QCR_BITSE);
mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_TXBUF);
if (txbuf)
for (i = 0; i < n; ++i)
mcfqspi_wr_qdr(mcfqspi, *txbuf++);
else
for (i = 0; i < count; ++i)
mcfqspi_wr_qdr(mcfqspi, 0);
count -= n;
if (count) {
u16 qwr = 0xf08;
mcfqspi_wr_qwr(mcfqspi, 0x700);
mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
do {
wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
mcfqspi_wr_qwr(mcfqspi, qwr);
mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
if (rxbuf) {
mcfqspi_wr_qar(mcfqspi,
MCFQSPI_QAR_RXBUF + offset);
for (i = 0; i < 8; ++i)
*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
}
n = min(count, 8u);
if (txbuf) {
mcfqspi_wr_qar(mcfqspi,
MCFQSPI_QAR_TXBUF + offset);
for (i = 0; i < n; ++i)
mcfqspi_wr_qdr(mcfqspi, *txbuf++);
}
qwr = (offset ? 0x808 : 0x000) + ((n - 1) << 8);
offset ^= 8;
count -= n;
} while (count);
wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
mcfqspi_wr_qwr(mcfqspi, qwr);
mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
if (rxbuf) {
mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_RXBUF + offset);
for (i = 0; i < 8; ++i)
*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
offset ^= 8;
}
} else {
mcfqspi_wr_qwr(mcfqspi, (n - 1) << 8);
mcfqspi_wr_qdlyr(mcfqspi, MCFQSPI_QDLYR_SPE);
}
wait_event(mcfqspi->waitq, !mcfqspi_qdlyr_spe(mcfqspi));
if (rxbuf) {
mcfqspi_wr_qar(mcfqspi, MCFQSPI_QAR_RXBUF + offset);
for (i = 0; i < n; ++i)
*rxbuf++ = mcfqspi_rd_qdr(mcfqspi);
}
}
static int mcfqspi_transfer_one_message(struct spi_master *master,
struct spi_message *msg)
{
struct mcfqspi *mcfqspi = spi_master_get_devdata(master);
struct spi_device *spi = msg->spi;
struct spi_transfer *t;
int status = 0;
list_for_each_entry(t, &msg->transfers, transfer_list) {
bool cs_high = spi->mode & SPI_CS_HIGH;
u16 qmr = MCFQSPI_QMR_MSTR;
if (t->bits_per_word)
qmr |= t->bits_per_word << 10;
else
qmr |= spi->bits_per_word << 10;
if (spi->mode & SPI_CPHA)
qmr |= MCFQSPI_QMR_CPHA;
if (spi->mode & SPI_CPOL)
qmr |= MCFQSPI_QMR_CPOL;
if (t->speed_hz)
qmr |= mcfqspi_qmr_baud(t->speed_hz);
else
qmr |= mcfqspi_qmr_baud(spi->max_speed_hz);
mcfqspi_wr_qmr(mcfqspi, qmr);
mcfqspi_cs_select(mcfqspi, spi->chip_select, cs_high);
mcfqspi_wr_qir(mcfqspi, MCFQSPI_QIR_SPIFE);
if (t->bits_per_word == 8)
mcfqspi_transfer_msg8(mcfqspi, t->len, t->tx_buf,
t->rx_buf);
else
mcfqspi_transfer_msg16(mcfqspi, t->len / 2, t->tx_buf,
t->rx_buf);
mcfqspi_wr_qir(mcfqspi, 0);
if (t->delay_usecs)
udelay(t->delay_usecs);
if (t->cs_change) {
if (!list_is_last(&t->transfer_list, &msg->transfers))
mcfqspi_cs_deselect(mcfqspi, spi->chip_select,
cs_high);
} else {
if (list_is_last(&t->transfer_list, &msg->transfers))
mcfqspi_cs_deselect(mcfqspi, spi->chip_select,
cs_high);
}
msg->actual_length += t->len;
}
msg->status = status;
spi_finalize_current_message(master);
return status;
}
static int mcfqspi_prepare_transfer_hw(struct spi_master *master)
{
struct mcfqspi *mcfqspi = spi_master_get_devdata(master);
pm_runtime_get_sync(mcfqspi->dev);
return 0;
}
static int mcfqspi_unprepare_transfer_hw(struct spi_master *master)
{
struct mcfqspi *mcfqspi = spi_master_get_devdata(master);
pm_runtime_put_sync(mcfqspi->dev);
return 0;
}
static int mcfqspi_setup(struct spi_device *spi)
{
if ((spi->bits_per_word < 8) || (spi->bits_per_word > 16)) {
dev_dbg(&spi->dev, "%d bits per word is not supported\n",
spi->bits_per_word);
return -EINVAL;
}
if (spi->chip_select >= spi->master->num_chipselect) {
dev_dbg(&spi->dev, "%d chip select is out of range\n",
spi->chip_select);
return -EINVAL;
}
mcfqspi_cs_deselect(spi_master_get_devdata(spi->master),
spi->chip_select, spi->mode & SPI_CS_HIGH);
dev_dbg(&spi->dev,
"bits per word %d, chip select %d, speed %d KHz\n",
spi->bits_per_word, spi->chip_select,
(MCFQSPI_BUSCLK / mcfqspi_qmr_baud(spi->max_speed_hz))
/ 1000);
return 0;
}
static int mcfqspi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct mcfqspi *mcfqspi;
struct resource *res;
struct mcfqspi_platform_data *pdata;
int status;
master = spi_alloc_master(&pdev->dev, sizeof(*mcfqspi));
if (master == NULL) {
dev_dbg(&pdev->dev, "spi_alloc_master failed\n");
return -ENOMEM;
}
mcfqspi = spi_master_get_devdata(master);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_dbg(&pdev->dev, "platform_get_resource failed\n");
status = -ENXIO;
goto fail0;
}
if (!request_mem_region(res->start, resource_size(res), pdev->name)) {
dev_dbg(&pdev->dev, "request_mem_region failed\n");
status = -EBUSY;
goto fail0;
}
mcfqspi->iobase = ioremap(res->start, resource_size(res));
if (!mcfqspi->iobase) {
dev_dbg(&pdev->dev, "ioremap failed\n");
status = -ENOMEM;
goto fail1;
}
mcfqspi->irq = platform_get_irq(pdev, 0);
if (mcfqspi->irq < 0) {
dev_dbg(&pdev->dev, "platform_get_irq failed\n");
status = -ENXIO;
goto fail2;
}
status = request_irq(mcfqspi->irq, mcfqspi_irq_handler, 0,
pdev->name, mcfqspi);
if (status) {
dev_dbg(&pdev->dev, "request_irq failed\n");
goto fail2;
}
mcfqspi->clk = clk_get(&pdev->dev, "qspi_clk");
if (IS_ERR(mcfqspi->clk)) {
dev_dbg(&pdev->dev, "clk_get failed\n");
status = PTR_ERR(mcfqspi->clk);
goto fail3;
}
clk_enable(mcfqspi->clk);
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_dbg(&pdev->dev, "platform data is missing\n");
goto fail4;
}
master->bus_num = pdata->bus_num;
master->num_chipselect = pdata->num_chipselect;
mcfqspi->cs_control = pdata->cs_control;
status = mcfqspi_cs_setup(mcfqspi);
if (status) {
dev_dbg(&pdev->dev, "error initializing cs_control\n");
goto fail4;
}
init_waitqueue_head(&mcfqspi->waitq);
mcfqspi->dev = &pdev->dev;
master->mode_bits = SPI_CS_HIGH | SPI_CPOL | SPI_CPHA;
master->setup = mcfqspi_setup;
master->transfer_one_message = mcfqspi_transfer_one_message;
master->prepare_transfer_hardware = mcfqspi_prepare_transfer_hw;
master->unprepare_transfer_hardware = mcfqspi_unprepare_transfer_hw;
platform_set_drvdata(pdev, master);
status = spi_register_master(master);
if (status) {
dev_dbg(&pdev->dev, "spi_register_master failed\n");
goto fail5;
}
pm_runtime_enable(mcfqspi->dev);
dev_info(&pdev->dev, "Coldfire QSPI bus driver\n");
return 0;
fail5:
mcfqspi_cs_teardown(mcfqspi);
fail4:
clk_disable(mcfqspi->clk);
clk_put(mcfqspi->clk);
fail3:
free_irq(mcfqspi->irq, mcfqspi);
fail2:
iounmap(mcfqspi->iobase);
fail1:
release_mem_region(res->start, resource_size(res));
fail0:
spi_master_put(master);
dev_dbg(&pdev->dev, "Coldfire QSPI probe failed\n");
return status;
}
static int mcfqspi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct mcfqspi *mcfqspi = spi_master_get_devdata(master);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pm_runtime_disable(mcfqspi->dev);
mcfqspi_wr_qmr(mcfqspi, MCFQSPI_QMR_MSTR);
platform_set_drvdata(pdev, NULL);
mcfqspi_cs_teardown(mcfqspi);
clk_disable(mcfqspi->clk);
clk_put(mcfqspi->clk);
free_irq(mcfqspi->irq, mcfqspi);
iounmap(mcfqspi->iobase);
release_mem_region(res->start, resource_size(res));
spi_unregister_master(master);
return 0;
}
static int mcfqspi_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct mcfqspi *mcfqspi = spi_master_get_devdata(master);
spi_master_suspend(master);
clk_disable(mcfqspi->clk);
return 0;
}
static int mcfqspi_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct mcfqspi *mcfqspi = spi_master_get_devdata(master);
spi_master_resume(master);
clk_enable(mcfqspi->clk);
return 0;
}
static int mcfqspi_runtime_suspend(struct device *dev)
{
struct mcfqspi *mcfqspi = platform_get_drvdata(to_platform_device(dev));
clk_disable(mcfqspi->clk);
return 0;
}
static int mcfqspi_runtime_resume(struct device *dev)
{
struct mcfqspi *mcfqspi = platform_get_drvdata(to_platform_device(dev));
clk_enable(mcfqspi->clk);
return 0;
}
