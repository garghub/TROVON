static inline void pic32_setbits(void __iomem *reg, u32 set)
{
writel(readl(reg) | set, reg);
}
static inline void pic32_clrbits(void __iomem *reg, u32 clr)
{
writel(readl(reg) & ~clr, reg);
}
static int pic32_sqi_set_clk_rate(struct pic32_sqi *sqi, u32 sck)
{
u32 val, div;
div = clk_get_rate(sqi->base_clk) / (2 * sck);
div &= PESQI_CLKDIV;
val = readl(sqi->regs + PESQI_CLK_CTRL_REG);
val &= ~(PESQI_CLK_STABLE | (PESQI_CLKDIV << PESQI_CLKDIV_SHIFT));
val |= div << PESQI_CLKDIV_SHIFT;
writel(val, sqi->regs + PESQI_CLK_CTRL_REG);
return readl_poll_timeout(sqi->regs + PESQI_CLK_CTRL_REG, val,
val & PESQI_CLK_STABLE, 1, 5000);
}
static inline void pic32_sqi_enable_int(struct pic32_sqi *sqi)
{
u32 mask = PESQI_DMAERR | PESQI_BDDONE | PESQI_PKTCOMP;
writel(mask, sqi->regs + PESQI_INT_ENABLE_REG);
writel(mask, sqi->regs + PESQI_INT_SIGEN_REG);
}
static inline void pic32_sqi_disable_int(struct pic32_sqi *sqi)
{
writel(0, sqi->regs + PESQI_INT_ENABLE_REG);
writel(0, sqi->regs + PESQI_INT_SIGEN_REG);
}
static irqreturn_t pic32_sqi_isr(int irq, void *dev_id)
{
struct pic32_sqi *sqi = dev_id;
u32 enable, status;
enable = readl(sqi->regs + PESQI_INT_ENABLE_REG);
status = readl(sqi->regs + PESQI_INT_STAT_REG);
if (!status)
return IRQ_NONE;
if (status & PESQI_DMAERR) {
enable = 0;
goto irq_done;
}
if (status & PESQI_TXTHR)
enable &= ~(PESQI_TXTHR | PESQI_TXFULL | PESQI_TXEMPTY);
if (status & PESQI_RXTHR)
enable &= ~(PESQI_RXTHR | PESQI_RXFULL | PESQI_RXEMPTY);
if (status & PESQI_BDDONE)
enable &= ~PESQI_BDDONE;
if (status & PESQI_PKTCOMP) {
enable = 0;
complete(&sqi->xfer_done);
}
irq_done:
writel(enable, sqi->regs + PESQI_INT_ENABLE_REG);
return IRQ_HANDLED;
}
static struct ring_desc *ring_desc_get(struct pic32_sqi *sqi)
{
struct ring_desc *rdesc;
if (list_empty(&sqi->bd_list_free))
return NULL;
rdesc = list_first_entry(&sqi->bd_list_free, struct ring_desc, list);
list_del(&rdesc->list);
list_add_tail(&rdesc->list, &sqi->bd_list_used);
return rdesc;
}
static void ring_desc_put(struct pic32_sqi *sqi, struct ring_desc *rdesc)
{
list_del(&rdesc->list);
list_add(&rdesc->list, &sqi->bd_list_free);
}
static int pic32_sqi_one_transfer(struct pic32_sqi *sqi,
struct spi_message *mesg,
struct spi_transfer *xfer)
{
struct spi_device *spi = mesg->spi;
struct scatterlist *sg, *sgl;
struct ring_desc *rdesc;
struct buf_desc *bd;
int nents, i;
u32 bd_ctrl;
u32 nbits;
bd_ctrl = spi->chip_select << BD_DEVSEL_SHIFT;
if (xfer->rx_buf) {
bd_ctrl |= BD_DATA_RECV;
nbits = xfer->rx_nbits;
sgl = xfer->rx_sg.sgl;
nents = xfer->rx_sg.nents;
} else {
nbits = xfer->tx_nbits;
sgl = xfer->tx_sg.sgl;
nents = xfer->tx_sg.nents;
}
if (nbits & SPI_NBITS_QUAD)
bd_ctrl |= BD_QUAD;
else if (nbits & SPI_NBITS_DUAL)
bd_ctrl |= BD_DUAL;
if (spi->mode & SPI_LSB_FIRST)
bd_ctrl |= BD_LSBF;
bd_ctrl |= BD_EN;
for_each_sg(sgl, sg, nents, i) {
rdesc = ring_desc_get(sqi);
if (!rdesc)
break;
bd = rdesc->bd;
rdesc->xfer_len = sg_dma_len(sg);
bd->bd_ctrl = bd_ctrl;
bd->bd_ctrl |= rdesc->xfer_len;
bd->bd_status = 0;
bd->bd_addr = sg->dma_address;
}
return 0;
}
static int pic32_sqi_prepare_hardware(struct spi_master *master)
{
struct pic32_sqi *sqi = spi_master_get_devdata(master);
pic32_setbits(sqi->regs + PESQI_CONF_REG, PESQI_EN);
pic32_setbits(sqi->regs + PESQI_CLK_CTRL_REG, PESQI_CLK_EN);
return 0;
}
static bool pic32_sqi_can_dma(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *x)
{
return true;
}
static int pic32_sqi_one_message(struct spi_master *master,
struct spi_message *msg)
{
struct spi_device *spi = msg->spi;
struct ring_desc *rdesc, *next;
struct spi_transfer *xfer;
struct pic32_sqi *sqi;
int ret = 0, mode;
u32 val;
sqi = spi_master_get_devdata(master);
reinit_completion(&sqi->xfer_done);
msg->actual_length = 0;
if (sqi->cur_spi != spi) {
if (sqi->cur_speed != spi->max_speed_hz) {
sqi->cur_speed = spi->max_speed_hz;
ret = pic32_sqi_set_clk_rate(sqi, spi->max_speed_hz);
if (ret)
dev_warn(&spi->dev, "set_clk, %d\n", ret);
}
mode = spi->mode & (SPI_MODE_3 | SPI_LSB_FIRST);
if (sqi->cur_mode != mode) {
val = readl(sqi->regs + PESQI_CONF_REG);
val &= ~(PESQI_CPOL | PESQI_CPHA | PESQI_LSBF);
if (mode & SPI_CPOL)
val |= PESQI_CPOL;
if (mode & SPI_LSB_FIRST)
val |= PESQI_LSBF;
val |= PESQI_CPHA;
writel(val, sqi->regs + PESQI_CONF_REG);
sqi->cur_mode = mode;
}
sqi->cur_spi = spi;
}
list_for_each_entry(xfer, &msg->transfers, transfer_list) {
ret = pic32_sqi_one_transfer(sqi, msg, xfer);
if (ret) {
dev_err(&spi->dev, "xfer %p err\n", xfer);
goto xfer_out;
}
}
rdesc = list_last_entry(&sqi->bd_list_used, struct ring_desc, list);
rdesc->bd->bd_ctrl |= BD_LAST | BD_CS_DEASSERT |
BD_LIFM | BD_PKT_INT_EN;
rdesc = list_first_entry(&sqi->bd_list_used, struct ring_desc, list);
writel(rdesc->bd_dma, sqi->regs + PESQI_BD_BASE_ADDR_REG);
pic32_sqi_enable_int(sqi);
val = PESQI_DMA_EN | PESQI_POLL_EN | PESQI_BDP_START;
writel(val, sqi->regs + PESQI_BD_CTRL_REG);
ret = wait_for_completion_timeout(&sqi->xfer_done, 5 * HZ);
if (ret <= 0) {
dev_err(&sqi->master->dev, "wait timedout/interrupted\n");
ret = -EIO;
msg->status = ret;
} else {
msg->status = 0;
ret = 0;
}
writel(0, sqi->regs + PESQI_BD_CTRL_REG);
pic32_sqi_disable_int(sqi);
xfer_out:
list_for_each_entry_safe_reverse(rdesc, next,
&sqi->bd_list_used, list) {
msg->actual_length += rdesc->xfer_len;
ring_desc_put(sqi, rdesc);
}
spi_finalize_current_message(spi->master);
return ret;
}
static int pic32_sqi_unprepare_hardware(struct spi_master *master)
{
struct pic32_sqi *sqi = spi_master_get_devdata(master);
pic32_clrbits(sqi->regs + PESQI_CLK_CTRL_REG, PESQI_CLK_EN);
pic32_clrbits(sqi->regs + PESQI_CONF_REG, PESQI_EN);
return 0;
}
static int ring_desc_ring_alloc(struct pic32_sqi *sqi)
{
struct ring_desc *rdesc;
struct buf_desc *bd;
int i;
sqi->bd = dma_zalloc_coherent(&sqi->master->dev,
sizeof(*bd) * PESQI_BD_COUNT,
&sqi->bd_dma, GFP_DMA32);
if (!sqi->bd) {
dev_err(&sqi->master->dev, "failed allocating dma buffer\n");
return -ENOMEM;
}
sqi->ring = kcalloc(PESQI_BD_COUNT, sizeof(*rdesc), GFP_KERNEL);
if (!sqi->ring) {
dma_free_coherent(&sqi->master->dev,
sizeof(*bd) * PESQI_BD_COUNT,
sqi->bd, sqi->bd_dma);
return -ENOMEM;
}
bd = (struct buf_desc *)sqi->bd;
INIT_LIST_HEAD(&sqi->bd_list_free);
INIT_LIST_HEAD(&sqi->bd_list_used);
for (i = 0, rdesc = sqi->ring; i < PESQI_BD_COUNT; i++, rdesc++) {
INIT_LIST_HEAD(&rdesc->list);
rdesc->bd = &bd[i];
rdesc->bd_dma = sqi->bd_dma + (void *)&bd[i] - (void *)bd;
list_add_tail(&rdesc->list, &sqi->bd_list_free);
}
for (i = 0, rdesc = sqi->ring; i < PESQI_BD_COUNT - 1; i++)
bd[i].bd_nextp = rdesc[i + 1].bd_dma;
bd[PESQI_BD_COUNT - 1].bd_nextp = 0;
return 0;
}
static void ring_desc_ring_free(struct pic32_sqi *sqi)
{
dma_free_coherent(&sqi->master->dev,
sizeof(struct buf_desc) * PESQI_BD_COUNT,
sqi->bd, sqi->bd_dma);
kfree(sqi->ring);
}
static void pic32_sqi_hw_init(struct pic32_sqi *sqi)
{
unsigned long flags;
u32 val;
local_irq_save(flags);
writel(PESQI_SOFT_RESET, sqi->regs + PESQI_CONF_REG);
readl_poll_timeout_atomic(sqi->regs + PESQI_CONF_REG, val,
!(val & PESQI_SOFT_RESET), 1, 5000);
pic32_sqi_disable_int(sqi);
local_irq_restore(flags);
val = readl(sqi->regs + PESQI_CMD_THRES_REG);
val &= ~(PESQI_TXTHR_MASK << PESQI_TXTHR_SHIFT);
val &= ~(PESQI_RXTHR_MASK << PESQI_RXTHR_SHIFT);
val |= (1U << PESQI_TXTHR_SHIFT) | (1U << PESQI_RXTHR_SHIFT);
writel(val, sqi->regs + PESQI_CMD_THRES_REG);
val = readl(sqi->regs + PESQI_INT_THRES_REG);
val &= ~(PESQI_TXTHR_MASK << PESQI_TXTHR_SHIFT);
val &= ~(PESQI_RXTHR_MASK << PESQI_RXTHR_SHIFT);
val |= (1U << PESQI_TXTHR_SHIFT) | (1U << PESQI_RXTHR_SHIFT);
writel(val, sqi->regs + PESQI_INT_THRES_REG);
val = readl(sqi->regs + PESQI_CONF_REG);
val &= ~PESQI_MODE;
val |= PESQI_MODE_DMA << PESQI_MODE_SHIFT;
writel(val, sqi->regs + PESQI_CONF_REG);
val |= PESQI_QUAD_LANE << PESQI_LANES_SHIFT;
val |= PESQI_BURST_EN;
val |= 3U << PESQI_CSEN_SHIFT;
writel(val, sqi->regs + PESQI_CONF_REG);
writel(0, sqi->regs + PESQI_BD_POLL_CTRL_REG);
sqi->cur_speed = 0;
sqi->cur_mode = -1;
}
static int pic32_sqi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct pic32_sqi *sqi;
struct resource *reg;
int ret;
master = spi_alloc_master(&pdev->dev, sizeof(*sqi));
if (!master)
return -ENOMEM;
sqi = spi_master_get_devdata(master);
sqi->master = master;
reg = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sqi->regs = devm_ioremap_resource(&pdev->dev, reg);
if (IS_ERR(sqi->regs)) {
ret = PTR_ERR(sqi->regs);
goto err_free_master;
}
sqi->irq = platform_get_irq(pdev, 0);
if (sqi->irq < 0) {
dev_err(&pdev->dev, "no irq found\n");
ret = sqi->irq;
goto err_free_master;
}
sqi->sys_clk = devm_clk_get(&pdev->dev, "reg_ck");
if (IS_ERR(sqi->sys_clk)) {
ret = PTR_ERR(sqi->sys_clk);
dev_err(&pdev->dev, "no sys_clk ?\n");
goto err_free_master;
}
sqi->base_clk = devm_clk_get(&pdev->dev, "spi_ck");
if (IS_ERR(sqi->base_clk)) {
ret = PTR_ERR(sqi->base_clk);
dev_err(&pdev->dev, "no base clk ?\n");
goto err_free_master;
}
ret = clk_prepare_enable(sqi->sys_clk);
if (ret) {
dev_err(&pdev->dev, "sys clk enable failed\n");
goto err_free_master;
}
ret = clk_prepare_enable(sqi->base_clk);
if (ret) {
dev_err(&pdev->dev, "base clk enable failed\n");
clk_disable_unprepare(sqi->sys_clk);
goto err_free_master;
}
init_completion(&sqi->xfer_done);
pic32_sqi_hw_init(sqi);
ret = ring_desc_ring_alloc(sqi);
if (ret) {
dev_err(&pdev->dev, "ring alloc failed\n");
goto err_disable_clk;
}
ret = request_irq(sqi->irq, pic32_sqi_isr, 0,
dev_name(&pdev->dev), sqi);
if (ret < 0) {
dev_err(&pdev->dev, "request_irq(%d), failed\n", sqi->irq);
goto err_free_ring;
}
master->num_chipselect = 2;
master->max_speed_hz = clk_get_rate(sqi->base_clk);
master->dma_alignment = 32;
master->max_dma_len = PESQI_BD_BUF_LEN_MAX;
master->dev.of_node = of_node_get(pdev->dev.of_node);
master->mode_bits = SPI_MODE_3 | SPI_MODE_0 | SPI_TX_DUAL |
SPI_RX_DUAL | SPI_TX_QUAD | SPI_RX_QUAD;
master->flags = SPI_MASTER_HALF_DUPLEX;
master->can_dma = pic32_sqi_can_dma;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(8, 32);
master->transfer_one_message = pic32_sqi_one_message;
master->prepare_transfer_hardware = pic32_sqi_prepare_hardware;
master->unprepare_transfer_hardware = pic32_sqi_unprepare_hardware;
ret = devm_spi_register_master(&pdev->dev, master);
if (ret) {
dev_err(&master->dev, "failed registering spi master\n");
free_irq(sqi->irq, sqi);
goto err_free_ring;
}
platform_set_drvdata(pdev, sqi);
return 0;
err_free_ring:
ring_desc_ring_free(sqi);
err_disable_clk:
clk_disable_unprepare(sqi->base_clk);
clk_disable_unprepare(sqi->sys_clk);
err_free_master:
spi_master_put(master);
return ret;
}
static int pic32_sqi_remove(struct platform_device *pdev)
{
struct pic32_sqi *sqi = platform_get_drvdata(pdev);
free_irq(sqi->irq, sqi);
ring_desc_ring_free(sqi);
clk_disable_unprepare(sqi->base_clk);
clk_disable_unprepare(sqi->sys_clk);
return 0;
}
