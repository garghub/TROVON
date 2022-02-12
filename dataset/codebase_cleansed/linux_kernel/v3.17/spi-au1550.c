static u32 au1550_spi_baudcfg(struct au1550_spi *hw, unsigned speed_hz)
{
u32 mainclk_hz = hw->pdata->mainclk_hz;
u32 div, brg;
for (div = 0; div < 4; div++) {
brg = mainclk_hz / speed_hz / (4 << div);
if (brg < (4 + 1)) {
brg = (4 + 1);
break;
}
if (brg <= (63 + 1))
break;
}
if (div == 4) {
div = 3;
brg = (63 + 1);
}
brg--;
return PSC_SPICFG_SET_BAUD(brg) | PSC_SPICFG_SET_DIV(div);
}
static inline void au1550_spi_mask_ack_all(struct au1550_spi *hw)
{
hw->regs->psc_spimsk =
PSC_SPIMSK_MM | PSC_SPIMSK_RR | PSC_SPIMSK_RO
| PSC_SPIMSK_RU | PSC_SPIMSK_TR | PSC_SPIMSK_TO
| PSC_SPIMSK_TU | PSC_SPIMSK_SD | PSC_SPIMSK_MD;
wmb();
hw->regs->psc_spievent =
PSC_SPIEVNT_MM | PSC_SPIEVNT_RR | PSC_SPIEVNT_RO
| PSC_SPIEVNT_RU | PSC_SPIEVNT_TR | PSC_SPIEVNT_TO
| PSC_SPIEVNT_TU | PSC_SPIEVNT_SD | PSC_SPIEVNT_MD;
wmb();
}
static void au1550_spi_reset_fifos(struct au1550_spi *hw)
{
u32 pcr;
hw->regs->psc_spipcr = PSC_SPIPCR_RC | PSC_SPIPCR_TC;
wmb();
do {
pcr = hw->regs->psc_spipcr;
wmb();
} while (pcr != 0);
}
static void au1550_spi_chipsel(struct spi_device *spi, int value)
{
struct au1550_spi *hw = spi_master_get_devdata(spi->master);
unsigned cspol = spi->mode & SPI_CS_HIGH ? 1 : 0;
u32 cfg, stat;
switch (value) {
case BITBANG_CS_INACTIVE:
if (hw->pdata->deactivate_cs)
hw->pdata->deactivate_cs(hw->pdata, spi->chip_select,
cspol);
break;
case BITBANG_CS_ACTIVE:
au1550_spi_bits_handlers_set(hw, spi->bits_per_word);
cfg = hw->regs->psc_spicfg;
wmb();
hw->regs->psc_spicfg = cfg & ~PSC_SPICFG_DE_ENABLE;
wmb();
if (spi->mode & SPI_CPOL)
cfg |= PSC_SPICFG_BI;
else
cfg &= ~PSC_SPICFG_BI;
if (spi->mode & SPI_CPHA)
cfg &= ~PSC_SPICFG_CDE;
else
cfg |= PSC_SPICFG_CDE;
if (spi->mode & SPI_LSB_FIRST)
cfg |= PSC_SPICFG_MLF;
else
cfg &= ~PSC_SPICFG_MLF;
if (hw->usedma && spi->bits_per_word <= 8)
cfg &= ~PSC_SPICFG_DD_DISABLE;
else
cfg |= PSC_SPICFG_DD_DISABLE;
cfg = PSC_SPICFG_CLR_LEN(cfg);
cfg |= PSC_SPICFG_SET_LEN(spi->bits_per_word);
cfg = PSC_SPICFG_CLR_BAUD(cfg);
cfg &= ~PSC_SPICFG_SET_DIV(3);
cfg |= au1550_spi_baudcfg(hw, spi->max_speed_hz);
hw->regs->psc_spicfg = cfg | PSC_SPICFG_DE_ENABLE;
wmb();
do {
stat = hw->regs->psc_spistat;
wmb();
} while ((stat & PSC_SPISTAT_DR) == 0);
if (hw->pdata->activate_cs)
hw->pdata->activate_cs(hw->pdata, spi->chip_select,
cspol);
break;
}
}
static int au1550_spi_setupxfer(struct spi_device *spi, struct spi_transfer *t)
{
struct au1550_spi *hw = spi_master_get_devdata(spi->master);
unsigned bpw, hz;
u32 cfg, stat;
bpw = spi->bits_per_word;
hz = spi->max_speed_hz;
if (t) {
if (t->bits_per_word)
bpw = t->bits_per_word;
if (t->speed_hz)
hz = t->speed_hz;
}
if (!hz)
return -EINVAL;
au1550_spi_bits_handlers_set(hw, spi->bits_per_word);
cfg = hw->regs->psc_spicfg;
wmb();
hw->regs->psc_spicfg = cfg & ~PSC_SPICFG_DE_ENABLE;
wmb();
if (hw->usedma && bpw <= 8)
cfg &= ~PSC_SPICFG_DD_DISABLE;
else
cfg |= PSC_SPICFG_DD_DISABLE;
cfg = PSC_SPICFG_CLR_LEN(cfg);
cfg |= PSC_SPICFG_SET_LEN(bpw);
cfg = PSC_SPICFG_CLR_BAUD(cfg);
cfg &= ~PSC_SPICFG_SET_DIV(3);
cfg |= au1550_spi_baudcfg(hw, hz);
hw->regs->psc_spicfg = cfg;
wmb();
if (cfg & PSC_SPICFG_DE_ENABLE) {
do {
stat = hw->regs->psc_spistat;
wmb();
} while ((stat & PSC_SPISTAT_DR) == 0);
}
au1550_spi_reset_fifos(hw);
au1550_spi_mask_ack_all(hw);
return 0;
}
static int au1550_spi_dma_rxtmp_alloc(struct au1550_spi *hw, unsigned size)
{
hw->dma_rx_tmpbuf = kmalloc(size, GFP_KERNEL);
if (!hw->dma_rx_tmpbuf)
return -ENOMEM;
hw->dma_rx_tmpbuf_size = size;
hw->dma_rx_tmpbuf_addr = dma_map_single(hw->dev, hw->dma_rx_tmpbuf,
size, DMA_FROM_DEVICE);
if (dma_mapping_error(hw->dev, hw->dma_rx_tmpbuf_addr)) {
kfree(hw->dma_rx_tmpbuf);
hw->dma_rx_tmpbuf = 0;
hw->dma_rx_tmpbuf_size = 0;
return -EFAULT;
}
return 0;
}
static void au1550_spi_dma_rxtmp_free(struct au1550_spi *hw)
{
dma_unmap_single(hw->dev, hw->dma_rx_tmpbuf_addr,
hw->dma_rx_tmpbuf_size, DMA_FROM_DEVICE);
kfree(hw->dma_rx_tmpbuf);
hw->dma_rx_tmpbuf = 0;
hw->dma_rx_tmpbuf_size = 0;
}
static int au1550_spi_dma_txrxb(struct spi_device *spi, struct spi_transfer *t)
{
struct au1550_spi *hw = spi_master_get_devdata(spi->master);
dma_addr_t dma_tx_addr;
dma_addr_t dma_rx_addr;
u32 res;
hw->len = t->len;
hw->tx_count = 0;
hw->rx_count = 0;
hw->tx = t->tx_buf;
hw->rx = t->rx_buf;
dma_tx_addr = t->tx_dma;
dma_rx_addr = t->rx_dma;
if (t->tx_buf) {
if (t->tx_dma == 0) {
dma_tx_addr = dma_map_single(hw->dev,
(void *)t->tx_buf,
t->len, DMA_TO_DEVICE);
if (dma_mapping_error(hw->dev, dma_tx_addr))
dev_err(hw->dev, "tx dma map error\n");
}
}
if (t->rx_buf) {
if (t->rx_dma == 0) {
dma_rx_addr = dma_map_single(hw->dev,
(void *)t->rx_buf,
t->len, DMA_FROM_DEVICE);
if (dma_mapping_error(hw->dev, dma_rx_addr))
dev_err(hw->dev, "rx dma map error\n");
}
} else {
if (t->len > hw->dma_rx_tmpbuf_size) {
int ret;
au1550_spi_dma_rxtmp_free(hw);
ret = au1550_spi_dma_rxtmp_alloc(hw, max(t->len,
AU1550_SPI_DMA_RXTMP_MINSIZE));
if (ret < 0)
return ret;
}
hw->rx = hw->dma_rx_tmpbuf;
dma_rx_addr = hw->dma_rx_tmpbuf_addr;
dma_sync_single_for_device(hw->dev, dma_rx_addr,
t->len, DMA_FROM_DEVICE);
}
if (!t->tx_buf) {
dma_sync_single_for_device(hw->dev, dma_rx_addr,
t->len, DMA_BIDIRECTIONAL);
hw->tx = hw->rx;
}
res = au1xxx_dbdma_put_dest(hw->dma_rx_ch, virt_to_phys(hw->rx),
t->len, DDMA_FLAGS_IE);
if (!res)
dev_err(hw->dev, "rx dma put dest error\n");
res = au1xxx_dbdma_put_source(hw->dma_tx_ch, virt_to_phys(hw->tx),
t->len, DDMA_FLAGS_IE);
if (!res)
dev_err(hw->dev, "tx dma put source error\n");
au1xxx_dbdma_start(hw->dma_rx_ch);
au1xxx_dbdma_start(hw->dma_tx_ch);
hw->regs->psc_spimsk = PSC_SPIMSK_SD;
wmb();
hw->regs->psc_spipcr = PSC_SPIPCR_MS;
wmb();
wait_for_completion(&hw->master_done);
au1xxx_dbdma_stop(hw->dma_tx_ch);
au1xxx_dbdma_stop(hw->dma_rx_ch);
if (!t->rx_buf) {
dma_sync_single_for_cpu(hw->dev, dma_rx_addr, t->len,
DMA_FROM_DEVICE);
}
if (t->rx_buf && t->rx_dma == 0 )
dma_unmap_single(hw->dev, dma_rx_addr, t->len,
DMA_FROM_DEVICE);
if (t->tx_buf && t->tx_dma == 0 )
dma_unmap_single(hw->dev, dma_tx_addr, t->len,
DMA_TO_DEVICE);
return hw->rx_count < hw->tx_count ? hw->rx_count : hw->tx_count;
}
static irqreturn_t au1550_spi_dma_irq_callback(struct au1550_spi *hw)
{
u32 stat, evnt;
stat = hw->regs->psc_spistat;
evnt = hw->regs->psc_spievent;
wmb();
if ((stat & PSC_SPISTAT_DI) == 0) {
dev_err(hw->dev, "Unexpected IRQ!\n");
return IRQ_NONE;
}
if ((evnt & (PSC_SPIEVNT_MM | PSC_SPIEVNT_RO
| PSC_SPIEVNT_RU | PSC_SPIEVNT_TO
| PSC_SPIEVNT_TU | PSC_SPIEVNT_SD))
!= 0) {
au1550_spi_mask_ack_all(hw);
au1xxx_dbdma_stop(hw->dma_rx_ch);
au1xxx_dbdma_stop(hw->dma_tx_ch);
hw->rx_count = hw->len - au1xxx_get_dma_residue(hw->dma_rx_ch);
hw->tx_count = hw->len - au1xxx_get_dma_residue(hw->dma_tx_ch);
au1xxx_dbdma_reset(hw->dma_rx_ch);
au1xxx_dbdma_reset(hw->dma_tx_ch);
au1550_spi_reset_fifos(hw);
if (evnt == PSC_SPIEVNT_RO)
dev_err(hw->dev,
"dma transfer: receive FIFO overflow!\n");
else
dev_err(hw->dev,
"dma transfer: unexpected SPI error "
"(event=0x%x stat=0x%x)!\n", evnt, stat);
complete(&hw->master_done);
return IRQ_HANDLED;
}
if ((evnt & PSC_SPIEVNT_MD) != 0) {
au1550_spi_mask_ack_all(hw);
hw->rx_count = hw->len;
hw->tx_count = hw->len;
complete(&hw->master_done);
}
return IRQ_HANDLED;
}
static int au1550_spi_pio_txrxb(struct spi_device *spi, struct spi_transfer *t)
{
u32 stat, mask;
struct au1550_spi *hw = spi_master_get_devdata(spi->master);
hw->tx = t->tx_buf;
hw->rx = t->rx_buf;
hw->len = t->len;
hw->tx_count = 0;
hw->rx_count = 0;
mask = PSC_SPIMSK_SD;
while (hw->tx_count < hw->len) {
hw->tx_word(hw);
if (hw->tx_count >= hw->len) {
mask |= PSC_SPIMSK_TR;
}
stat = hw->regs->psc_spistat;
wmb();
if (stat & PSC_SPISTAT_TF)
break;
}
hw->regs->psc_spimsk = mask;
wmb();
hw->regs->psc_spipcr = PSC_SPIPCR_MS;
wmb();
wait_for_completion(&hw->master_done);
return hw->rx_count < hw->tx_count ? hw->rx_count : hw->tx_count;
}
static irqreturn_t au1550_spi_pio_irq_callback(struct au1550_spi *hw)
{
int busy;
u32 stat, evnt;
stat = hw->regs->psc_spistat;
evnt = hw->regs->psc_spievent;
wmb();
if ((stat & PSC_SPISTAT_DI) == 0) {
dev_err(hw->dev, "Unexpected IRQ!\n");
return IRQ_NONE;
}
if ((evnt & (PSC_SPIEVNT_MM | PSC_SPIEVNT_RO
| PSC_SPIEVNT_RU | PSC_SPIEVNT_TO
| PSC_SPIEVNT_SD))
!= 0) {
au1550_spi_mask_ack_all(hw);
au1550_spi_reset_fifos(hw);
dev_err(hw->dev,
"pio transfer: unexpected SPI error "
"(event=0x%x stat=0x%x)!\n", evnt, stat);
complete(&hw->master_done);
return IRQ_HANDLED;
}
do {
busy = 0;
stat = hw->regs->psc_spistat;
wmb();
if (!(stat & PSC_SPISTAT_RE) && hw->rx_count < hw->len) {
hw->rx_word(hw);
busy = 1;
if (!(stat & PSC_SPISTAT_TF) && hw->tx_count < hw->len)
hw->tx_word(hw);
}
} while (busy);
hw->regs->psc_spievent = PSC_SPIEVNT_RR | PSC_SPIEVNT_TR;
wmb();
if (evnt & PSC_SPIEVNT_TU) {
hw->regs->psc_spievent = PSC_SPIEVNT_TU | PSC_SPIEVNT_MD;
wmb();
hw->regs->psc_spipcr = PSC_SPIPCR_MS;
wmb();
}
if (hw->rx_count >= hw->len) {
au1550_spi_mask_ack_all(hw);
complete(&hw->master_done);
}
return IRQ_HANDLED;
}
static int au1550_spi_txrx_bufs(struct spi_device *spi, struct spi_transfer *t)
{
struct au1550_spi *hw = spi_master_get_devdata(spi->master);
return hw->txrx_bufs(spi, t);
}
static irqreturn_t au1550_spi_irq(int irq, void *dev)
{
struct au1550_spi *hw = dev;
return hw->irq_callback(hw);
}
static void au1550_spi_bits_handlers_set(struct au1550_spi *hw, int bpw)
{
if (bpw <= 8) {
if (hw->usedma) {
hw->txrx_bufs = &au1550_spi_dma_txrxb;
hw->irq_callback = &au1550_spi_dma_irq_callback;
} else {
hw->rx_word = &au1550_spi_rx_word_8;
hw->tx_word = &au1550_spi_tx_word_8;
hw->txrx_bufs = &au1550_spi_pio_txrxb;
hw->irq_callback = &au1550_spi_pio_irq_callback;
}
} else if (bpw <= 16) {
hw->rx_word = &au1550_spi_rx_word_16;
hw->tx_word = &au1550_spi_tx_word_16;
hw->txrx_bufs = &au1550_spi_pio_txrxb;
hw->irq_callback = &au1550_spi_pio_irq_callback;
} else {
hw->rx_word = &au1550_spi_rx_word_32;
hw->tx_word = &au1550_spi_tx_word_32;
hw->txrx_bufs = &au1550_spi_pio_txrxb;
hw->irq_callback = &au1550_spi_pio_irq_callback;
}
}
static void au1550_spi_setup_psc_as_spi(struct au1550_spi *hw)
{
u32 stat, cfg;
hw->regs->psc_ctrl = PSC_CTRL_DISABLE;
wmb();
hw->regs->psc_sel = PSC_SEL_PS_SPIMODE;
wmb();
hw->regs->psc_spicfg = 0;
wmb();
hw->regs->psc_ctrl = PSC_CTRL_ENABLE;
wmb();
do {
stat = hw->regs->psc_spistat;
wmb();
} while ((stat & PSC_SPISTAT_SR) == 0);
cfg = hw->usedma ? 0 : PSC_SPICFG_DD_DISABLE;
cfg |= PSC_SPICFG_SET_LEN(8);
cfg |= PSC_SPICFG_RT_FIFO8 | PSC_SPICFG_TT_FIFO8;
cfg |= PSC_SPICFG_SET_BAUD(4) | PSC_SPICFG_SET_DIV(0);
#ifdef AU1550_SPI_DEBUG_LOOPBACK
cfg |= PSC_SPICFG_LB;
#endif
hw->regs->psc_spicfg = cfg;
wmb();
au1550_spi_mask_ack_all(hw);
hw->regs->psc_spicfg |= PSC_SPICFG_DE_ENABLE;
wmb();
do {
stat = hw->regs->psc_spistat;
wmb();
} while ((stat & PSC_SPISTAT_DR) == 0);
au1550_spi_reset_fifos(hw);
}
static int au1550_spi_probe(struct platform_device *pdev)
{
struct au1550_spi *hw;
struct spi_master *master;
struct resource *r;
int err = 0;
master = spi_alloc_master(&pdev->dev, sizeof(struct au1550_spi));
if (master == NULL) {
dev_err(&pdev->dev, "No memory for spi_master\n");
err = -ENOMEM;
goto err_nomem;
}
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LSB_FIRST;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 24);
hw = spi_master_get_devdata(master);
hw->master = master;
hw->pdata = dev_get_platdata(&pdev->dev);
hw->dev = &pdev->dev;
if (hw->pdata == NULL) {
dev_err(&pdev->dev, "No platform data supplied\n");
err = -ENOENT;
goto err_no_pdata;
}
r = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!r) {
dev_err(&pdev->dev, "no IRQ\n");
err = -ENODEV;
goto err_no_iores;
}
hw->irq = r->start;
hw->usedma = 0;
r = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (r) {
hw->dma_tx_id = r->start;
r = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (r) {
hw->dma_rx_id = r->start;
if (usedma && ddma_memid) {
if (pdev->dev.dma_mask == NULL)
dev_warn(&pdev->dev, "no dma mask\n");
else
hw->usedma = 1;
}
}
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "no mmio resource\n");
err = -ENODEV;
goto err_no_iores;
}
hw->ioarea = request_mem_region(r->start, sizeof(psc_spi_t),
pdev->name);
if (!hw->ioarea) {
dev_err(&pdev->dev, "Cannot reserve iomem region\n");
err = -ENXIO;
goto err_no_iores;
}
hw->regs = (psc_spi_t __iomem *)ioremap(r->start, sizeof(psc_spi_t));
if (!hw->regs) {
dev_err(&pdev->dev, "cannot ioremap\n");
err = -ENXIO;
goto err_ioremap;
}
platform_set_drvdata(pdev, hw);
init_completion(&hw->master_done);
hw->bitbang.master = hw->master;
hw->bitbang.setup_transfer = au1550_spi_setupxfer;
hw->bitbang.chipselect = au1550_spi_chipsel;
hw->bitbang.txrx_bufs = au1550_spi_txrx_bufs;
if (hw->usedma) {
hw->dma_tx_ch = au1xxx_dbdma_chan_alloc(ddma_memid,
hw->dma_tx_id, NULL, (void *)hw);
if (hw->dma_tx_ch == 0) {
dev_err(&pdev->dev,
"Cannot allocate tx dma channel\n");
err = -ENXIO;
goto err_no_txdma;
}
au1xxx_dbdma_set_devwidth(hw->dma_tx_ch, 8);
if (au1xxx_dbdma_ring_alloc(hw->dma_tx_ch,
AU1550_SPI_DBDMA_DESCRIPTORS) == 0) {
dev_err(&pdev->dev,
"Cannot allocate tx dma descriptors\n");
err = -ENXIO;
goto err_no_txdma_descr;
}
hw->dma_rx_ch = au1xxx_dbdma_chan_alloc(hw->dma_rx_id,
ddma_memid, NULL, (void *)hw);
if (hw->dma_rx_ch == 0) {
dev_err(&pdev->dev,
"Cannot allocate rx dma channel\n");
err = -ENXIO;
goto err_no_rxdma;
}
au1xxx_dbdma_set_devwidth(hw->dma_rx_ch, 8);
if (au1xxx_dbdma_ring_alloc(hw->dma_rx_ch,
AU1550_SPI_DBDMA_DESCRIPTORS) == 0) {
dev_err(&pdev->dev,
"Cannot allocate rx dma descriptors\n");
err = -ENXIO;
goto err_no_rxdma_descr;
}
err = au1550_spi_dma_rxtmp_alloc(hw,
AU1550_SPI_DMA_RXTMP_MINSIZE);
if (err < 0) {
dev_err(&pdev->dev,
"Cannot allocate initial rx dma tmp buffer\n");
goto err_dma_rxtmp_alloc;
}
}
au1550_spi_bits_handlers_set(hw, 8);
err = request_irq(hw->irq, au1550_spi_irq, 0, pdev->name, hw);
if (err) {
dev_err(&pdev->dev, "Cannot claim IRQ\n");
goto err_no_irq;
}
master->bus_num = pdev->id;
master->num_chipselect = hw->pdata->num_chipselect;
{
int min_div = (2 << 0) * (2 * (4 + 1));
int max_div = (2 << 3) * (2 * (63 + 1));
master->max_speed_hz = hw->pdata->mainclk_hz / min_div;
master->min_speed_hz =
hw->pdata->mainclk_hz / (max_div + 1) + 1;
}
au1550_spi_setup_psc_as_spi(hw);
err = spi_bitbang_start(&hw->bitbang);
if (err) {
dev_err(&pdev->dev, "Failed to register SPI master\n");
goto err_register;
}
dev_info(&pdev->dev,
"spi master registered: bus_num=%d num_chipselect=%d\n",
master->bus_num, master->num_chipselect);
return 0;
err_register:
free_irq(hw->irq, hw);
err_no_irq:
au1550_spi_dma_rxtmp_free(hw);
err_dma_rxtmp_alloc:
err_no_rxdma_descr:
if (hw->usedma)
au1xxx_dbdma_chan_free(hw->dma_rx_ch);
err_no_rxdma:
err_no_txdma_descr:
if (hw->usedma)
au1xxx_dbdma_chan_free(hw->dma_tx_ch);
err_no_txdma:
iounmap((void __iomem *)hw->regs);
err_ioremap:
release_mem_region(r->start, sizeof(psc_spi_t));
err_no_iores:
err_no_pdata:
spi_master_put(hw->master);
err_nomem:
return err;
}
static int au1550_spi_remove(struct platform_device *pdev)
{
struct au1550_spi *hw = platform_get_drvdata(pdev);
dev_info(&pdev->dev, "spi master remove: bus_num=%d\n",
hw->master->bus_num);
spi_bitbang_stop(&hw->bitbang);
free_irq(hw->irq, hw);
iounmap((void __iomem *)hw->regs);
release_mem_region(hw->ioarea->start, sizeof(psc_spi_t));
if (hw->usedma) {
au1550_spi_dma_rxtmp_free(hw);
au1xxx_dbdma_chan_free(hw->dma_rx_ch);
au1xxx_dbdma_chan_free(hw->dma_tx_ch);
}
spi_master_put(hw->master);
return 0;
}
static int __init au1550_spi_init(void)
{
switch (alchemy_get_cputype()) {
case ALCHEMY_CPU_AU1550:
case ALCHEMY_CPU_AU1200:
case ALCHEMY_CPU_AU1300:
break;
default:
return -ENODEV;
}
if (usedma) {
ddma_memid = au1xxx_ddma_add_device(&au1550_spi_mem_dbdev);
if (!ddma_memid)
printk(KERN_ERR "au1550-spi: cannot add memory"
"dbdma device\n");
}
return platform_driver_register(&au1550_spi_drv);
}
static void __exit au1550_spi_exit(void)
{
if (usedma && ddma_memid)
au1xxx_ddma_del_device(ddma_memid);
platform_driver_unregister(&au1550_spi_drv);
}
