static bool atmel_spi_is_v2(void)
{
return !cpu_is_at91rm9200();
}
static void cs_activate(struct atmel_spi *as, struct spi_device *spi)
{
struct atmel_spi_device *asd = spi->controller_state;
unsigned active = spi->mode & SPI_CS_HIGH;
u32 mr;
if (atmel_spi_is_v2()) {
spi_writel(as, CSR0, asd->csr);
spi_writel(as, MR, SPI_BF(PCS, 0x0e) | SPI_BIT(MODFDIS)
| SPI_BIT(MSTR));
mr = spi_readl(as, MR);
gpio_set_value(asd->npcs_pin, active);
} else {
u32 cpol = (spi->mode & SPI_CPOL) ? SPI_BIT(CPOL) : 0;
int i;
u32 csr;
for (i = 0; i < spi->master->num_chipselect; i++) {
csr = spi_readl(as, CSR0 + 4 * i);
if ((csr ^ cpol) & SPI_BIT(CPOL))
spi_writel(as, CSR0 + 4 * i,
csr ^ SPI_BIT(CPOL));
}
mr = spi_readl(as, MR);
mr = SPI_BFINS(PCS, ~(1 << spi->chip_select), mr);
if (spi->chip_select != 0)
gpio_set_value(asd->npcs_pin, active);
spi_writel(as, MR, mr);
}
dev_dbg(&spi->dev, "activate %u%s, mr %08x\n",
asd->npcs_pin, active ? " (high)" : "",
mr);
}
static void cs_deactivate(struct atmel_spi *as, struct spi_device *spi)
{
struct atmel_spi_device *asd = spi->controller_state;
unsigned active = spi->mode & SPI_CS_HIGH;
u32 mr;
mr = spi_readl(as, MR);
if (~SPI_BFEXT(PCS, mr) & (1 << spi->chip_select)) {
mr = SPI_BFINS(PCS, 0xf, mr);
spi_writel(as, MR, mr);
}
dev_dbg(&spi->dev, "DEactivate %u%s, mr %08x\n",
asd->npcs_pin, active ? " (low)" : "",
mr);
if (atmel_spi_is_v2() || spi->chip_select != 0)
gpio_set_value(asd->npcs_pin, !active);
}
static inline int atmel_spi_xfer_is_last(struct spi_message *msg,
struct spi_transfer *xfer)
{
return msg->transfers.prev == &xfer->transfer_list;
}
static inline int atmel_spi_xfer_can_be_chained(struct spi_transfer *xfer)
{
return xfer->delay_usecs == 0 && !xfer->cs_change;
}
static void atmel_spi_next_xfer_data(struct spi_master *master,
struct spi_transfer *xfer,
dma_addr_t *tx_dma,
dma_addr_t *rx_dma,
u32 *plen)
{
struct atmel_spi *as = spi_master_get_devdata(master);
u32 len = *plen;
if (xfer->rx_buf)
*rx_dma = xfer->rx_dma + xfer->len - *plen;
else {
*rx_dma = as->buffer_dma;
if (len > BUFFER_SIZE)
len = BUFFER_SIZE;
}
if (xfer->tx_buf)
*tx_dma = xfer->tx_dma + xfer->len - *plen;
else {
*tx_dma = as->buffer_dma;
if (len > BUFFER_SIZE)
len = BUFFER_SIZE;
memset(as->buffer, 0, len);
dma_sync_single_for_device(&as->pdev->dev,
as->buffer_dma, len, DMA_TO_DEVICE);
}
*plen = len;
}
static void atmel_spi_next_xfer(struct spi_master *master,
struct spi_message *msg)
{
struct atmel_spi *as = spi_master_get_devdata(master);
struct spi_transfer *xfer;
u32 len, remaining;
u32 ieval;
dma_addr_t tx_dma, rx_dma;
if (!as->current_transfer)
xfer = list_entry(msg->transfers.next,
struct spi_transfer, transfer_list);
else if (!as->next_transfer)
xfer = list_entry(as->current_transfer->transfer_list.next,
struct spi_transfer, transfer_list);
else
xfer = NULL;
if (xfer) {
spi_writel(as, PTCR, SPI_BIT(RXTDIS) | SPI_BIT(TXTDIS));
len = xfer->len;
atmel_spi_next_xfer_data(master, xfer, &tx_dma, &rx_dma, &len);
remaining = xfer->len - len;
spi_writel(as, RPR, rx_dma);
spi_writel(as, TPR, tx_dma);
if (msg->spi->bits_per_word > 8)
len >>= 1;
spi_writel(as, RCR, len);
spi_writel(as, TCR, len);
dev_dbg(&msg->spi->dev,
" start xfer %p: len %u tx %p/%08x rx %p/%08x\n",
xfer, xfer->len, xfer->tx_buf, xfer->tx_dma,
xfer->rx_buf, xfer->rx_dma);
} else {
xfer = as->next_transfer;
remaining = as->next_remaining_bytes;
}
as->current_transfer = xfer;
as->current_remaining_bytes = remaining;
if (remaining > 0)
len = remaining;
else if (!atmel_spi_xfer_is_last(msg, xfer)
&& atmel_spi_xfer_can_be_chained(xfer)) {
xfer = list_entry(xfer->transfer_list.next,
struct spi_transfer, transfer_list);
len = xfer->len;
} else
xfer = NULL;
as->next_transfer = xfer;
if (xfer) {
u32 total;
total = len;
atmel_spi_next_xfer_data(master, xfer, &tx_dma, &rx_dma, &len);
as->next_remaining_bytes = total - len;
spi_writel(as, RNPR, rx_dma);
spi_writel(as, TNPR, tx_dma);
if (msg->spi->bits_per_word > 8)
len >>= 1;
spi_writel(as, RNCR, len);
spi_writel(as, TNCR, len);
dev_dbg(&msg->spi->dev,
" next xfer %p: len %u tx %p/%08x rx %p/%08x\n",
xfer, xfer->len, xfer->tx_buf, xfer->tx_dma,
xfer->rx_buf, xfer->rx_dma);
ieval = SPI_BIT(ENDRX) | SPI_BIT(OVRES);
} else {
spi_writel(as, RNCR, 0);
spi_writel(as, TNCR, 0);
ieval = SPI_BIT(RXBUFF) | SPI_BIT(ENDRX) | SPI_BIT(OVRES);
}
spi_writel(as, IER, ieval);
spi_writel(as, PTCR, SPI_BIT(TXTEN) | SPI_BIT(RXTEN));
}
static void atmel_spi_next_message(struct spi_master *master)
{
struct atmel_spi *as = spi_master_get_devdata(master);
struct spi_message *msg;
struct spi_device *spi;
BUG_ON(as->current_transfer);
msg = list_entry(as->queue.next, struct spi_message, queue);
spi = msg->spi;
dev_dbg(master->dev.parent, "start message %p for %s\n",
msg, dev_name(&spi->dev));
if (as->stay) {
if (as->stay != spi) {
cs_deactivate(as, as->stay);
cs_activate(as, spi);
}
as->stay = NULL;
} else
cs_activate(as, spi);
atmel_spi_next_xfer(master, msg);
}
static int
atmel_spi_dma_map_xfer(struct atmel_spi *as, struct spi_transfer *xfer)
{
struct device *dev = &as->pdev->dev;
xfer->tx_dma = xfer->rx_dma = INVALID_DMA_ADDRESS;
if (xfer->tx_buf) {
void *nonconst_tx = (void *)xfer->tx_buf;
xfer->tx_dma = dma_map_single(dev,
nonconst_tx, xfer->len,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, xfer->tx_dma))
return -ENOMEM;
}
if (xfer->rx_buf) {
xfer->rx_dma = dma_map_single(dev,
xfer->rx_buf, xfer->len,
DMA_FROM_DEVICE);
if (dma_mapping_error(dev, xfer->rx_dma)) {
if (xfer->tx_buf)
dma_unmap_single(dev,
xfer->tx_dma, xfer->len,
DMA_TO_DEVICE);
return -ENOMEM;
}
}
return 0;
}
static void atmel_spi_dma_unmap_xfer(struct spi_master *master,
struct spi_transfer *xfer)
{
if (xfer->tx_dma != INVALID_DMA_ADDRESS)
dma_unmap_single(master->dev.parent, xfer->tx_dma,
xfer->len, DMA_TO_DEVICE);
if (xfer->rx_dma != INVALID_DMA_ADDRESS)
dma_unmap_single(master->dev.parent, xfer->rx_dma,
xfer->len, DMA_FROM_DEVICE);
}
static void
atmel_spi_msg_done(struct spi_master *master, struct atmel_spi *as,
struct spi_message *msg, int status, int stay)
{
if (!stay || status < 0)
cs_deactivate(as, msg->spi);
else
as->stay = msg->spi;
list_del(&msg->queue);
msg->status = status;
dev_dbg(master->dev.parent,
"xfer complete: %u bytes transferred\n",
msg->actual_length);
spin_unlock(&as->lock);
msg->complete(msg->context);
spin_lock(&as->lock);
as->current_transfer = NULL;
as->next_transfer = NULL;
if (list_empty(&as->queue) || as->stopping)
spi_writel(as, PTCR, SPI_BIT(RXTDIS) | SPI_BIT(TXTDIS));
else
atmel_spi_next_message(master);
}
static irqreturn_t
atmel_spi_interrupt(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct atmel_spi *as = spi_master_get_devdata(master);
struct spi_message *msg;
struct spi_transfer *xfer;
u32 status, pending, imr;
int ret = IRQ_NONE;
spin_lock(&as->lock);
xfer = as->current_transfer;
msg = list_entry(as->queue.next, struct spi_message, queue);
imr = spi_readl(as, IMR);
status = spi_readl(as, SR);
pending = status & imr;
if (pending & SPI_BIT(OVRES)) {
int timeout;
ret = IRQ_HANDLED;
spi_writel(as, IDR, (SPI_BIT(RXBUFF) | SPI_BIT(ENDRX)
| SPI_BIT(OVRES)));
spi_writel(as, PTCR, SPI_BIT(RXTDIS) | SPI_BIT(TXTDIS));
if (!msg->is_dma_mapped)
atmel_spi_dma_unmap_xfer(master, xfer);
if (xfer->delay_usecs)
udelay(xfer->delay_usecs);
dev_warn(master->dev.parent, "overrun (%u/%u remaining)\n",
spi_readl(as, TCR), spi_readl(as, RCR));
spi_writel(as, RNCR, 0);
spi_writel(as, TNCR, 0);
spi_writel(as, RCR, 0);
spi_writel(as, TCR, 0);
for (timeout = 1000; timeout; timeout--)
if (spi_readl(as, SR) & SPI_BIT(TXEMPTY))
break;
if (!timeout)
dev_warn(master->dev.parent,
"timeout waiting for TXEMPTY");
while (spi_readl(as, SR) & SPI_BIT(RDRF))
spi_readl(as, RDR);
spi_readl(as, SR);
atmel_spi_msg_done(master, as, msg, -EIO, 0);
} else if (pending & (SPI_BIT(RXBUFF) | SPI_BIT(ENDRX))) {
ret = IRQ_HANDLED;
spi_writel(as, IDR, pending);
if (as->current_remaining_bytes == 0) {
msg->actual_length += xfer->len;
if (!msg->is_dma_mapped)
atmel_spi_dma_unmap_xfer(master, xfer);
if (xfer->delay_usecs)
udelay(xfer->delay_usecs);
if (atmel_spi_xfer_is_last(msg, xfer)) {
atmel_spi_msg_done(master, as, msg, 0,
xfer->cs_change);
} else {
if (xfer->cs_change) {
cs_deactivate(as, msg->spi);
udelay(1);
cs_activate(as, msg->spi);
}
atmel_spi_next_xfer(master, msg);
}
} else {
atmel_spi_next_xfer(master, msg);
}
}
spin_unlock(&as->lock);
return ret;
}
static int atmel_spi_setup(struct spi_device *spi)
{
struct atmel_spi *as;
struct atmel_spi_device *asd;
u32 scbr, csr;
unsigned int bits = spi->bits_per_word;
unsigned long bus_hz;
unsigned int npcs_pin;
int ret;
as = spi_master_get_devdata(spi->master);
if (as->stopping)
return -ESHUTDOWN;
if (spi->chip_select > spi->master->num_chipselect) {
dev_dbg(&spi->dev,
"setup: invalid chipselect %u (%u defined)\n",
spi->chip_select, spi->master->num_chipselect);
return -EINVAL;
}
if (bits < 8 || bits > 16) {
dev_dbg(&spi->dev,
"setup: invalid bits_per_word %u (8 to 16)\n",
bits);
return -EINVAL;
}
if (!atmel_spi_is_v2()
&& spi->chip_select == 0
&& (spi->mode & SPI_CS_HIGH)) {
dev_dbg(&spi->dev, "setup: can't be active-high\n");
return -EINVAL;
}
bus_hz = clk_get_rate(as->clk);
if (!atmel_spi_is_v2())
bus_hz /= 2;
if (spi->max_speed_hz) {
scbr = DIV_ROUND_UP(bus_hz, spi->max_speed_hz);
if (scbr >= (1 << SPI_SCBR_SIZE)) {
dev_dbg(&spi->dev,
"setup: %d Hz too slow, scbr %u; min %ld Hz\n",
spi->max_speed_hz, scbr, bus_hz/255);
return -EINVAL;
}
} else
scbr = 0xff;
csr = SPI_BF(SCBR, scbr) | SPI_BF(BITS, bits - 8);
if (spi->mode & SPI_CPOL)
csr |= SPI_BIT(CPOL);
if (!(spi->mode & SPI_CPHA))
csr |= SPI_BIT(NCPHA);
csr |= SPI_BF(DLYBS, 0);
csr |= SPI_BF(DLYBCT, 0);
npcs_pin = (unsigned int)spi->controller_data;
asd = spi->controller_state;
if (!asd) {
asd = kzalloc(sizeof(struct atmel_spi_device), GFP_KERNEL);
if (!asd)
return -ENOMEM;
ret = gpio_request(npcs_pin, dev_name(&spi->dev));
if (ret) {
kfree(asd);
return ret;
}
asd->npcs_pin = npcs_pin;
spi->controller_state = asd;
gpio_direction_output(npcs_pin, !(spi->mode & SPI_CS_HIGH));
} else {
unsigned long flags;
spin_lock_irqsave(&as->lock, flags);
if (as->stay == spi)
as->stay = NULL;
cs_deactivate(as, spi);
spin_unlock_irqrestore(&as->lock, flags);
}
asd->csr = csr;
dev_dbg(&spi->dev,
"setup: %lu Hz bpw %u mode 0x%x -> csr%d %08x\n",
bus_hz / scbr, bits, spi->mode, spi->chip_select, csr);
if (!atmel_spi_is_v2())
spi_writel(as, CSR0 + 4 * spi->chip_select, csr);
return 0;
}
static int atmel_spi_transfer(struct spi_device *spi, struct spi_message *msg)
{
struct atmel_spi *as;
struct spi_transfer *xfer;
unsigned long flags;
struct device *controller = spi->master->dev.parent;
u8 bits;
struct atmel_spi_device *asd;
as = spi_master_get_devdata(spi->master);
dev_dbg(controller, "new message %p submitted for %s\n",
msg, dev_name(&spi->dev));
if (unlikely(list_empty(&msg->transfers)))
return -EINVAL;
if (as->stopping)
return -ESHUTDOWN;
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
if (!(xfer->tx_buf || xfer->rx_buf) && xfer->len) {
dev_dbg(&spi->dev, "missing rx or tx buf\n");
return -EINVAL;
}
if (xfer->bits_per_word) {
asd = spi->controller_state;
bits = (asd->csr >> 4) & 0xf;
if (bits != xfer->bits_per_word - 8) {
dev_dbg(&spi->dev, "you can't yet change "
"bits_per_word in transfers\n");
return -ENOPROTOOPT;
}
}
if (xfer->speed_hz) {
dev_dbg(&spi->dev, "no protocol options yet\n");
return -ENOPROTOOPT;
}
if (!msg->is_dma_mapped) {
if (atmel_spi_dma_map_xfer(as, xfer) < 0)
return -ENOMEM;
}
}
#ifdef VERBOSE
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
dev_dbg(controller,
" xfer %p: len %u tx %p/%08x rx %p/%08x\n",
xfer, xfer->len,
xfer->tx_buf, xfer->tx_dma,
xfer->rx_buf, xfer->rx_dma);
}
#endif
msg->status = -EINPROGRESS;
msg->actual_length = 0;
spin_lock_irqsave(&as->lock, flags);
list_add_tail(&msg->queue, &as->queue);
if (!as->current_transfer)
atmel_spi_next_message(spi->master);
spin_unlock_irqrestore(&as->lock, flags);
return 0;
}
static void atmel_spi_cleanup(struct spi_device *spi)
{
struct atmel_spi *as = spi_master_get_devdata(spi->master);
struct atmel_spi_device *asd = spi->controller_state;
unsigned gpio = (unsigned) spi->controller_data;
unsigned long flags;
if (!asd)
return;
spin_lock_irqsave(&as->lock, flags);
if (as->stay == spi) {
as->stay = NULL;
cs_deactivate(as, spi);
}
spin_unlock_irqrestore(&as->lock, flags);
spi->controller_state = NULL;
gpio_free(gpio);
kfree(asd);
}
static int __init atmel_spi_probe(struct platform_device *pdev)
{
struct resource *regs;
int irq;
struct clk *clk;
int ret;
struct spi_master *master;
struct atmel_spi *as;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs)
return -ENXIO;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
clk = clk_get(&pdev->dev, "spi_clk");
if (IS_ERR(clk))
return PTR_ERR(clk);
ret = -ENOMEM;
master = spi_alloc_master(&pdev->dev, sizeof *as);
if (!master)
goto out_free;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->bus_num = pdev->id;
master->num_chipselect = 4;
master->setup = atmel_spi_setup;
master->transfer = atmel_spi_transfer;
master->cleanup = atmel_spi_cleanup;
platform_set_drvdata(pdev, master);
as = spi_master_get_devdata(master);
as->buffer = dma_alloc_coherent(&pdev->dev, BUFFER_SIZE,
&as->buffer_dma, GFP_KERNEL);
if (!as->buffer)
goto out_free;
spin_lock_init(&as->lock);
INIT_LIST_HEAD(&as->queue);
as->pdev = pdev;
as->regs = ioremap(regs->start, resource_size(regs));
if (!as->regs)
goto out_free_buffer;
as->irq = irq;
as->clk = clk;
ret = request_irq(irq, atmel_spi_interrupt, 0,
dev_name(&pdev->dev), master);
if (ret)
goto out_unmap_regs;
clk_enable(clk);
spi_writel(as, CR, SPI_BIT(SWRST));
spi_writel(as, CR, SPI_BIT(SWRST));
spi_writel(as, MR, SPI_BIT(MSTR) | SPI_BIT(MODFDIS));
spi_writel(as, PTCR, SPI_BIT(RXTDIS) | SPI_BIT(TXTDIS));
spi_writel(as, CR, SPI_BIT(SPIEN));
dev_info(&pdev->dev, "Atmel SPI Controller at 0x%08lx (irq %d)\n",
(unsigned long)regs->start, irq);
ret = spi_register_master(master);
if (ret)
goto out_reset_hw;
return 0;
out_reset_hw:
spi_writel(as, CR, SPI_BIT(SWRST));
spi_writel(as, CR, SPI_BIT(SWRST));
clk_disable(clk);
free_irq(irq, master);
out_unmap_regs:
iounmap(as->regs);
out_free_buffer:
dma_free_coherent(&pdev->dev, BUFFER_SIZE, as->buffer,
as->buffer_dma);
out_free:
clk_put(clk);
spi_master_put(master);
return ret;
}
static int __exit atmel_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct atmel_spi *as = spi_master_get_devdata(master);
struct spi_message *msg;
spin_lock_irq(&as->lock);
as->stopping = 1;
spi_writel(as, CR, SPI_BIT(SWRST));
spi_writel(as, CR, SPI_BIT(SWRST));
spi_readl(as, SR);
spin_unlock_irq(&as->lock);
list_for_each_entry(msg, &as->queue, queue) {
msg->status = -ESHUTDOWN;
msg->complete(msg->context);
}
dma_free_coherent(&pdev->dev, BUFFER_SIZE, as->buffer,
as->buffer_dma);
clk_disable(as->clk);
clk_put(as->clk);
free_irq(as->irq, master);
iounmap(as->regs);
spi_unregister_master(master);
return 0;
}
static int atmel_spi_suspend(struct platform_device *pdev, pm_message_t mesg)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct atmel_spi *as = spi_master_get_devdata(master);
clk_disable(as->clk);
return 0;
}
static int atmel_spi_resume(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct atmel_spi *as = spi_master_get_devdata(master);
clk_enable(as->clk);
return 0;
}
static int __init atmel_spi_init(void)
{
return platform_driver_probe(&atmel_spi_driver, atmel_spi_probe);
}
static void __exit atmel_spi_exit(void)
{
platform_driver_unregister(&atmel_spi_driver);
}
