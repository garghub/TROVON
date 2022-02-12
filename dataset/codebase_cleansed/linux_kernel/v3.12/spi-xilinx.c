static void xspi_write32(u32 val, void __iomem *addr)
{
iowrite32(val, addr);
}
static unsigned int xspi_read32(void __iomem *addr)
{
return ioread32(addr);
}
static void xspi_write32_be(u32 val, void __iomem *addr)
{
iowrite32be(val, addr);
}
static unsigned int xspi_read32_be(void __iomem *addr)
{
return ioread32be(addr);
}
static void xspi_tx8(struct xilinx_spi *xspi)
{
xspi->write_fn(*xspi->tx_ptr, xspi->regs + XSPI_TXD_OFFSET);
xspi->tx_ptr++;
}
static void xspi_tx16(struct xilinx_spi *xspi)
{
xspi->write_fn(*(u16 *)(xspi->tx_ptr), xspi->regs + XSPI_TXD_OFFSET);
xspi->tx_ptr += 2;
}
static void xspi_tx32(struct xilinx_spi *xspi)
{
xspi->write_fn(*(u32 *)(xspi->tx_ptr), xspi->regs + XSPI_TXD_OFFSET);
xspi->tx_ptr += 4;
}
static void xspi_rx8(struct xilinx_spi *xspi)
{
u32 data = xspi->read_fn(xspi->regs + XSPI_RXD_OFFSET);
if (xspi->rx_ptr) {
*xspi->rx_ptr = data & 0xff;
xspi->rx_ptr++;
}
}
static void xspi_rx16(struct xilinx_spi *xspi)
{
u32 data = xspi->read_fn(xspi->regs + XSPI_RXD_OFFSET);
if (xspi->rx_ptr) {
*(u16 *)(xspi->rx_ptr) = data & 0xffff;
xspi->rx_ptr += 2;
}
}
static void xspi_rx32(struct xilinx_spi *xspi)
{
u32 data = xspi->read_fn(xspi->regs + XSPI_RXD_OFFSET);
if (xspi->rx_ptr) {
*(u32 *)(xspi->rx_ptr) = data;
xspi->rx_ptr += 4;
}
}
static void xspi_init_hw(struct xilinx_spi *xspi)
{
void __iomem *regs_base = xspi->regs;
xspi->write_fn(XIPIF_V123B_RESET_MASK,
regs_base + XIPIF_V123B_RESETR_OFFSET);
xspi->write_fn(0, regs_base + XIPIF_V123B_IIER_OFFSET);
xspi->write_fn(XIPIF_V123B_GINTR_ENABLE,
regs_base + XIPIF_V123B_DGIER_OFFSET);
xspi->write_fn(0xffff, regs_base + XSPI_SSR_OFFSET);
xspi->write_fn(XSPI_CR_TRANS_INHIBIT | XSPI_CR_MANUAL_SSELECT |
XSPI_CR_MASTER_MODE | XSPI_CR_ENABLE | XSPI_CR_TXFIFO_RESET |
XSPI_CR_RXFIFO_RESET, regs_base + XSPI_CR_OFFSET);
}
static void xilinx_spi_chipselect(struct spi_device *spi, int is_on)
{
struct xilinx_spi *xspi = spi_master_get_devdata(spi->master);
if (is_on == BITBANG_CS_INACTIVE) {
xspi->write_fn(0xffff, xspi->regs + XSPI_SSR_OFFSET);
} else if (is_on == BITBANG_CS_ACTIVE) {
u16 cr = xspi->read_fn(xspi->regs + XSPI_CR_OFFSET)
& ~XSPI_CR_MODE_MASK;
if (spi->mode & SPI_CPHA)
cr |= XSPI_CR_CPHA;
if (spi->mode & SPI_CPOL)
cr |= XSPI_CR_CPOL;
xspi->write_fn(cr, xspi->regs + XSPI_CR_OFFSET);
xspi->write_fn(~(0x0001 << spi->chip_select),
xspi->regs + XSPI_SSR_OFFSET);
}
}
static int xilinx_spi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct xilinx_spi *xspi = spi_master_get_devdata(spi->master);
u8 bits_per_word;
bits_per_word = (t && t->bits_per_word)
? t->bits_per_word : spi->bits_per_word;
if (bits_per_word != xspi->bits_per_word) {
dev_err(&spi->dev, "%s, unsupported bits_per_word=%d\n",
__func__, bits_per_word);
return -EINVAL;
}
return 0;
}
static void xilinx_spi_fill_tx_fifo(struct xilinx_spi *xspi)
{
u8 sr;
sr = xspi->read_fn(xspi->regs + XSPI_SR_OFFSET);
while ((sr & XSPI_SR_TX_FULL_MASK) == 0 && xspi->remaining_bytes > 0) {
if (xspi->tx_ptr)
xspi->tx_fn(xspi);
else
xspi->write_fn(0, xspi->regs + XSPI_TXD_OFFSET);
xspi->remaining_bytes -= xspi->bits_per_word / 8;
sr = xspi->read_fn(xspi->regs + XSPI_SR_OFFSET);
}
}
static int xilinx_spi_txrx_bufs(struct spi_device *spi, struct spi_transfer *t)
{
struct xilinx_spi *xspi = spi_master_get_devdata(spi->master);
u32 ipif_ier;
xspi->tx_ptr = t->tx_buf;
xspi->rx_ptr = t->rx_buf;
xspi->remaining_bytes = t->len;
INIT_COMPLETION(xspi->done);
ipif_ier = xspi->read_fn(xspi->regs + XIPIF_V123B_IIER_OFFSET);
xspi->write_fn(ipif_ier | XSPI_INTR_TX_EMPTY,
xspi->regs + XIPIF_V123B_IIER_OFFSET);
for (;;) {
u16 cr;
u8 sr;
xilinx_spi_fill_tx_fifo(xspi);
cr = xspi->read_fn(xspi->regs + XSPI_CR_OFFSET) &
~XSPI_CR_TRANS_INHIBIT;
xspi->write_fn(cr, xspi->regs + XSPI_CR_OFFSET);
wait_for_completion(&xspi->done);
cr = xspi->read_fn(xspi->regs + XSPI_CR_OFFSET);
xspi->write_fn(cr | XSPI_CR_TRANS_INHIBIT,
xspi->regs + XSPI_CR_OFFSET);
sr = xspi->read_fn(xspi->regs + XSPI_SR_OFFSET);
while ((sr & XSPI_SR_RX_EMPTY_MASK) == 0) {
xspi->rx_fn(xspi);
sr = xspi->read_fn(xspi->regs + XSPI_SR_OFFSET);
}
if (xspi->remaining_bytes <= 0)
break;
}
xspi->write_fn(ipif_ier, xspi->regs + XIPIF_V123B_IIER_OFFSET);
return t->len - xspi->remaining_bytes;
}
static irqreturn_t xilinx_spi_irq(int irq, void *dev_id)
{
struct xilinx_spi *xspi = dev_id;
u32 ipif_isr;
ipif_isr = xspi->read_fn(xspi->regs + XIPIF_V123B_IISR_OFFSET);
xspi->write_fn(ipif_isr, xspi->regs + XIPIF_V123B_IISR_OFFSET);
if (ipif_isr & XSPI_INTR_TX_EMPTY) {
complete(&xspi->done);
}
return IRQ_HANDLED;
}
static int xilinx_spi_probe(struct platform_device *pdev)
{
struct xilinx_spi *xspi;
struct xspi_platform_data *pdata;
struct resource *res;
int ret, num_cs = 0, bits_per_word = 8;
struct spi_master *master;
u32 tmp;
u8 i;
pdata = dev_get_platdata(&pdev->dev);
if (pdata) {
num_cs = pdata->num_chipselect;
bits_per_word = pdata->bits_per_word;
} else {
of_property_read_u32(pdev->dev.of_node, "xlnx,num-ss-bits",
&num_cs);
}
if (!num_cs) {
dev_err(&pdev->dev,
"Missing slave select configuration data\n");
return -EINVAL;
}
master = spi_alloc_master(&pdev->dev, sizeof(struct xilinx_spi));
if (!master)
return -ENODEV;
master->mode_bits = SPI_CPOL | SPI_CPHA;
xspi = spi_master_get_devdata(master);
xspi->bitbang.master = spi_master_get(master);
xspi->bitbang.chipselect = xilinx_spi_chipselect;
xspi->bitbang.setup_transfer = xilinx_spi_setup_transfer;
xspi->bitbang.txrx_bufs = xilinx_spi_txrx_bufs;
init_completion(&xspi->done);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xspi->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xspi->regs)) {
ret = PTR_ERR(xspi->regs);
goto put_master;
}
master->bus_num = pdev->dev.id;
master->num_chipselect = num_cs;
master->dev.of_node = pdev->dev.of_node;
xspi->read_fn = xspi_read32;
xspi->write_fn = xspi_write32;
xspi->write_fn(XSPI_CR_LOOP, xspi->regs + XSPI_CR_OFFSET);
tmp = xspi->read_fn(xspi->regs + XSPI_CR_OFFSET);
tmp &= XSPI_CR_LOOP;
if (tmp != XSPI_CR_LOOP) {
xspi->read_fn = xspi_read32_be;
xspi->write_fn = xspi_write32_be;
}
xspi->bits_per_word = bits_per_word;
if (xspi->bits_per_word == 8) {
xspi->tx_fn = xspi_tx8;
xspi->rx_fn = xspi_rx8;
} else if (xspi->bits_per_word == 16) {
xspi->tx_fn = xspi_tx16;
xspi->rx_fn = xspi_rx16;
} else if (xspi->bits_per_word == 32) {
xspi->tx_fn = xspi_tx32;
xspi->rx_fn = xspi_rx32;
} else {
ret = -EINVAL;
goto put_master;
}
xspi_init_hw(xspi);
xspi->irq = platform_get_irq(pdev, 0);
if (xspi->irq < 0) {
ret = xspi->irq;
goto put_master;
}
ret = devm_request_irq(&pdev->dev, xspi->irq, xilinx_spi_irq, 0,
dev_name(&pdev->dev), xspi);
if (ret)
goto put_master;
ret = spi_bitbang_start(&xspi->bitbang);
if (ret) {
dev_err(&pdev->dev, "spi_bitbang_start FAILED\n");
goto put_master;
}
dev_info(&pdev->dev, "at 0x%08llX mapped to 0x%p, irq=%d\n",
(unsigned long long)res->start, xspi->regs, xspi->irq);
if (pdata) {
for (i = 0; i < pdata->num_devices; i++)
spi_new_device(master, pdata->devices + i);
}
platform_set_drvdata(pdev, master);
return 0;
put_master:
spi_master_put(master);
return ret;
}
static int xilinx_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct xilinx_spi *xspi = spi_master_get_devdata(master);
void __iomem *regs_base = xspi->regs;
spi_bitbang_stop(&xspi->bitbang);
xspi->write_fn(0, regs_base + XIPIF_V123B_IIER_OFFSET);
xspi->write_fn(0, regs_base + XIPIF_V123B_DGIER_OFFSET);
spi_master_put(xspi->bitbang.master);
return 0;
}
