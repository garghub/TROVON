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
static void xilinx_spi_tx(struct xilinx_spi *xspi)
{
u32 data = 0;
if (!xspi->tx_ptr) {
xspi->write_fn(0, xspi->regs + XSPI_TXD_OFFSET);
return;
}
switch (xspi->bytes_per_word) {
case 1:
data = *(u8 *)(xspi->tx_ptr);
break;
case 2:
data = *(u16 *)(xspi->tx_ptr);
break;
case 4:
data = *(u32 *)(xspi->tx_ptr);
break;
}
xspi->write_fn(data, xspi->regs + XSPI_TXD_OFFSET);
xspi->tx_ptr += xspi->bytes_per_word;
}
static void xilinx_spi_rx(struct xilinx_spi *xspi)
{
u32 data = xspi->read_fn(xspi->regs + XSPI_RXD_OFFSET);
if (!xspi->rx_ptr)
return;
switch (xspi->bytes_per_word) {
case 1:
*(u8 *)(xspi->rx_ptr) = data;
break;
case 2:
*(u16 *)(xspi->rx_ptr) = data;
break;
case 4:
*(u32 *)(xspi->rx_ptr) = data;
break;
}
xspi->rx_ptr += xspi->bytes_per_word;
}
static void xspi_init_hw(struct xilinx_spi *xspi)
{
void __iomem *regs_base = xspi->regs;
xspi->write_fn(XIPIF_V123B_RESET_MASK,
regs_base + XIPIF_V123B_RESETR_OFFSET);
xspi->write_fn(XSPI_INTR_TX_EMPTY,
regs_base + XIPIF_V123B_IIER_OFFSET);
xspi->write_fn(0, regs_base + XIPIF_V123B_DGIER_OFFSET);
xspi->write_fn(0xffff, regs_base + XSPI_SSR_OFFSET);
xspi->write_fn(XSPI_CR_MANUAL_SSELECT | XSPI_CR_MASTER_MODE |
XSPI_CR_ENABLE | XSPI_CR_TXFIFO_RESET | XSPI_CR_RXFIFO_RESET,
regs_base + XSPI_CR_OFFSET);
}
static void xilinx_spi_chipselect(struct spi_device *spi, int is_on)
{
struct xilinx_spi *xspi = spi_master_get_devdata(spi->master);
u16 cr;
u32 cs;
if (is_on == BITBANG_CS_INACTIVE) {
xspi->write_fn(xspi->cs_inactive, xspi->regs + XSPI_SSR_OFFSET);
return;
}
cr = xspi->read_fn(xspi->regs + XSPI_CR_OFFSET) & ~XSPI_CR_MODE_MASK;
if (spi->mode & SPI_CPHA)
cr |= XSPI_CR_CPHA;
if (spi->mode & SPI_CPOL)
cr |= XSPI_CR_CPOL;
if (spi->mode & SPI_LSB_FIRST)
cr |= XSPI_CR_LSB_FIRST;
if (spi->mode & SPI_LOOP)
cr |= XSPI_CR_LOOP;
xspi->write_fn(cr, xspi->regs + XSPI_CR_OFFSET);
cs = xspi->cs_inactive;
cs ^= BIT(spi->chip_select);
xspi->write_fn(cs, xspi->regs + XSPI_SSR_OFFSET);
}
static int xilinx_spi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct xilinx_spi *xspi = spi_master_get_devdata(spi->master);
if (spi->mode & SPI_CS_HIGH)
xspi->cs_inactive &= ~BIT(spi->chip_select);
else
xspi->cs_inactive |= BIT(spi->chip_select);
return 0;
}
static int xilinx_spi_txrx_bufs(struct spi_device *spi, struct spi_transfer *t)
{
struct xilinx_spi *xspi = spi_master_get_devdata(spi->master);
int remaining_words;
bool use_irq = false;
u16 cr = 0;
xspi->tx_ptr = t->tx_buf;
xspi->rx_ptr = t->rx_buf;
remaining_words = t->len / xspi->bytes_per_word;
reinit_completion(&xspi->done);
if (xspi->irq >= 0 && remaining_words > xspi->buffer_size) {
use_irq = true;
xspi->write_fn(XSPI_INTR_TX_EMPTY,
xspi->regs + XIPIF_V123B_IISR_OFFSET);
xspi->write_fn(XIPIF_V123B_GINTR_ENABLE,
xspi->regs + XIPIF_V123B_DGIER_OFFSET);
cr = xspi->read_fn(xspi->regs + XSPI_CR_OFFSET);
xspi->write_fn(cr | XSPI_CR_TRANS_INHIBIT,
xspi->regs + XSPI_CR_OFFSET);
}
while (remaining_words) {
int n_words, tx_words, rx_words;
n_words = min(remaining_words, xspi->buffer_size);
tx_words = n_words;
while (tx_words--)
xilinx_spi_tx(xspi);
if (use_irq) {
xspi->write_fn(cr, xspi->regs + XSPI_CR_OFFSET);
wait_for_completion(&xspi->done);
} else
while (!(xspi->read_fn(xspi->regs + XSPI_SR_OFFSET) &
XSPI_SR_TX_EMPTY_MASK))
;
if (use_irq)
xspi->write_fn(cr | XSPI_CR_TRANS_INHIBIT,
xspi->regs + XSPI_CR_OFFSET);
rx_words = n_words;
while (rx_words--)
xilinx_spi_rx(xspi);
remaining_words -= n_words;
}
if (use_irq)
xspi->write_fn(0, xspi->regs + XIPIF_V123B_DGIER_OFFSET);
return t->len;
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
static int xilinx_spi_find_buffer_size(struct xilinx_spi *xspi)
{
u8 sr;
int n_words = 0;
xspi->write_fn(XIPIF_V123B_RESET_MASK,
xspi->regs + XIPIF_V123B_RESETR_OFFSET);
do {
xspi->write_fn(0, xspi->regs + XSPI_TXD_OFFSET);
sr = xspi->read_fn(xspi->regs + XSPI_SR_OFFSET);
n_words++;
} while (!(sr & XSPI_SR_TX_FULL_MASK));
return n_words;
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
if (num_cs > XILINX_SPI_MAX_CS) {
dev_err(&pdev->dev, "Invalid number of spi slaves\n");
return -EINVAL;
}
master = spi_alloc_master(&pdev->dev, sizeof(struct xilinx_spi));
if (!master)
return -ENODEV;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_LSB_FIRST | SPI_LOOP |
SPI_CS_HIGH;
xspi = spi_master_get_devdata(master);
xspi->cs_inactive = 0xffffffff;
xspi->bitbang.master = master;
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
master->bus_num = pdev->id;
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
master->bits_per_word_mask = SPI_BPW_MASK(bits_per_word);
xspi->bytes_per_word = bits_per_word / 8;
xspi->buffer_size = xilinx_spi_find_buffer_size(xspi);
xspi->irq = platform_get_irq(pdev, 0);
if (xspi->irq >= 0) {
ret = devm_request_irq(&pdev->dev, xspi->irq, xilinx_spi_irq, 0,
dev_name(&pdev->dev), xspi);
if (ret)
goto put_master;
}
xspi_init_hw(xspi);
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
