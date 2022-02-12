static ssize_t dw_spi_show_regs(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct dw_spi *dws = file->private_data;
char *buf;
u32 len = 0;
ssize_t ret;
buf = kzalloc(SPI_REGS_BUFSIZE, GFP_KERNEL);
if (!buf)
return 0;
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"%s registers:\n", dev_name(&dws->master->dev));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"=================================\n");
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"CTRL0: \t\t0x%08x\n", dw_readl(dws, DW_SPI_CTRL0));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"CTRL1: \t\t0x%08x\n", dw_readl(dws, DW_SPI_CTRL1));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"SSIENR: \t0x%08x\n", dw_readl(dws, DW_SPI_SSIENR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"SER: \t\t0x%08x\n", dw_readl(dws, DW_SPI_SER));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"BAUDR: \t\t0x%08x\n", dw_readl(dws, DW_SPI_BAUDR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"TXFTLR: \t0x%08x\n", dw_readl(dws, DW_SPI_TXFLTR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"RXFTLR: \t0x%08x\n", dw_readl(dws, DW_SPI_RXFLTR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"TXFLR: \t\t0x%08x\n", dw_readl(dws, DW_SPI_TXFLR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"RXFLR: \t\t0x%08x\n", dw_readl(dws, DW_SPI_RXFLR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"SR: \t\t0x%08x\n", dw_readl(dws, DW_SPI_SR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"IMR: \t\t0x%08x\n", dw_readl(dws, DW_SPI_IMR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"ISR: \t\t0x%08x\n", dw_readl(dws, DW_SPI_ISR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"DMACR: \t\t0x%08x\n", dw_readl(dws, DW_SPI_DMACR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"DMATDLR: \t0x%08x\n", dw_readl(dws, DW_SPI_DMATDLR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"DMARDLR: \t0x%08x\n", dw_readl(dws, DW_SPI_DMARDLR));
len += snprintf(buf + len, SPI_REGS_BUFSIZE - len,
"=================================\n");
ret = simple_read_from_buffer(user_buf, count, ppos, buf, len);
kfree(buf);
return ret;
}
static int dw_spi_debugfs_init(struct dw_spi *dws)
{
dws->debugfs = debugfs_create_dir("dw_spi", NULL);
if (!dws->debugfs)
return -ENOMEM;
debugfs_create_file("registers", S_IFREG | S_IRUGO,
dws->debugfs, (void *)dws, &dw_spi_regs_ops);
return 0;
}
static void dw_spi_debugfs_remove(struct dw_spi *dws)
{
debugfs_remove_recursive(dws->debugfs);
}
static inline int dw_spi_debugfs_init(struct dw_spi *dws)
{
return 0;
}
static inline void dw_spi_debugfs_remove(struct dw_spi *dws)
{
}
static void dw_spi_set_cs(struct spi_device *spi, bool enable)
{
struct dw_spi *dws = spi_master_get_devdata(spi->master);
struct chip_data *chip = spi_get_ctldata(spi);
if (chip && chip->cs_control)
chip->cs_control(!enable);
if (!enable)
dw_writel(dws, DW_SPI_SER, BIT(spi->chip_select));
}
static inline u32 tx_max(struct dw_spi *dws)
{
u32 tx_left, tx_room, rxtx_gap;
tx_left = (dws->tx_end - dws->tx) / dws->n_bytes;
tx_room = dws->fifo_len - dw_readl(dws, DW_SPI_TXFLR);
rxtx_gap = ((dws->rx_end - dws->rx) - (dws->tx_end - dws->tx))
/ dws->n_bytes;
return min3(tx_left, tx_room, (u32) (dws->fifo_len - rxtx_gap));
}
static inline u32 rx_max(struct dw_spi *dws)
{
u32 rx_left = (dws->rx_end - dws->rx) / dws->n_bytes;
return min_t(u32, rx_left, dw_readl(dws, DW_SPI_RXFLR));
}
static void dw_writer(struct dw_spi *dws)
{
u32 max = tx_max(dws);
u16 txw = 0;
while (max--) {
if (dws->tx_end - dws->len) {
if (dws->n_bytes == 1)
txw = *(u8 *)(dws->tx);
else
txw = *(u16 *)(dws->tx);
}
dw_write_io_reg(dws, DW_SPI_DR, txw);
dws->tx += dws->n_bytes;
}
}
static void dw_reader(struct dw_spi *dws)
{
u32 max = rx_max(dws);
u16 rxw;
while (max--) {
rxw = dw_read_io_reg(dws, DW_SPI_DR);
if (dws->rx_end - dws->len) {
if (dws->n_bytes == 1)
*(u8 *)(dws->rx) = rxw;
else
*(u16 *)(dws->rx) = rxw;
}
dws->rx += dws->n_bytes;
}
}
static void int_error_stop(struct dw_spi *dws, const char *msg)
{
spi_reset_chip(dws);
dev_err(&dws->master->dev, "%s\n", msg);
dws->master->cur_msg->status = -EIO;
spi_finalize_current_transfer(dws->master);
}
static irqreturn_t interrupt_transfer(struct dw_spi *dws)
{
u16 irq_status = dw_readl(dws, DW_SPI_ISR);
if (irq_status & (SPI_INT_TXOI | SPI_INT_RXOI | SPI_INT_RXUI)) {
dw_readl(dws, DW_SPI_ICR);
int_error_stop(dws, "interrupt_transfer: fifo overrun/underrun");
return IRQ_HANDLED;
}
dw_reader(dws);
if (dws->rx_end == dws->rx) {
spi_mask_intr(dws, SPI_INT_TXEI);
spi_finalize_current_transfer(dws->master);
return IRQ_HANDLED;
}
if (irq_status & SPI_INT_TXEI) {
spi_mask_intr(dws, SPI_INT_TXEI);
dw_writer(dws);
spi_umask_intr(dws, SPI_INT_TXEI);
}
return IRQ_HANDLED;
}
static irqreturn_t dw_spi_irq(int irq, void *dev_id)
{
struct spi_master *master = dev_id;
struct dw_spi *dws = spi_master_get_devdata(master);
u16 irq_status = dw_readl(dws, DW_SPI_ISR) & 0x3f;
if (!irq_status)
return IRQ_NONE;
if (!master->cur_msg) {
spi_mask_intr(dws, SPI_INT_TXEI);
return IRQ_HANDLED;
}
return dws->transfer_handler(dws);
}
static int poll_transfer(struct dw_spi *dws)
{
do {
dw_writer(dws);
dw_reader(dws);
cpu_relax();
} while (dws->rx_end > dws->rx);
return 0;
}
static int dw_spi_transfer_one(struct spi_master *master,
struct spi_device *spi, struct spi_transfer *transfer)
{
struct dw_spi *dws = spi_master_get_devdata(master);
struct chip_data *chip = spi_get_ctldata(spi);
u8 imask = 0;
u16 txlevel = 0;
u16 clk_div;
u32 cr0;
int ret;
dws->dma_mapped = 0;
dws->tx = (void *)transfer->tx_buf;
dws->tx_end = dws->tx + transfer->len;
dws->rx = transfer->rx_buf;
dws->rx_end = dws->rx + transfer->len;
dws->len = transfer->len;
spi_enable_chip(dws, 0);
if (transfer->speed_hz != chip->speed_hz) {
clk_div = (dws->max_freq / transfer->speed_hz + 1) & 0xfffe;
chip->speed_hz = transfer->speed_hz;
chip->clk_div = clk_div;
spi_set_clk(dws, chip->clk_div);
}
if (transfer->bits_per_word == 8) {
dws->n_bytes = 1;
dws->dma_width = 1;
} else if (transfer->bits_per_word == 16) {
dws->n_bytes = 2;
dws->dma_width = 2;
} else {
return -EINVAL;
}
cr0 = (transfer->bits_per_word - 1)
| (chip->type << SPI_FRF_OFFSET)
| (spi->mode << SPI_MODE_OFFSET)
| (chip->tmode << SPI_TMOD_OFFSET);
if (chip->cs_control) {
if (dws->rx && dws->tx)
chip->tmode = SPI_TMOD_TR;
else if (dws->rx)
chip->tmode = SPI_TMOD_RO;
else
chip->tmode = SPI_TMOD_TO;
cr0 &= ~SPI_TMOD_MASK;
cr0 |= (chip->tmode << SPI_TMOD_OFFSET);
}
dw_writel(dws, DW_SPI_CTRL0, cr0);
if (master->can_dma && master->can_dma(master, spi, transfer))
dws->dma_mapped = master->cur_msg_mapped;
spi_mask_intr(dws, 0xff);
if (dws->dma_mapped) {
ret = dws->dma_ops->dma_setup(dws, transfer);
if (ret < 0) {
spi_enable_chip(dws, 1);
return ret;
}
} else if (!chip->poll_mode) {
txlevel = min_t(u16, dws->fifo_len / 2, dws->len / dws->n_bytes);
dw_writel(dws, DW_SPI_TXFLTR, txlevel);
imask |= SPI_INT_TXEI | SPI_INT_TXOI |
SPI_INT_RXUI | SPI_INT_RXOI;
spi_umask_intr(dws, imask);
dws->transfer_handler = interrupt_transfer;
}
spi_enable_chip(dws, 1);
if (dws->dma_mapped) {
ret = dws->dma_ops->dma_transfer(dws, transfer);
if (ret < 0)
return ret;
}
if (chip->poll_mode)
return poll_transfer(dws);
return 1;
}
static void dw_spi_handle_err(struct spi_master *master,
struct spi_message *msg)
{
struct dw_spi *dws = spi_master_get_devdata(master);
if (dws->dma_mapped)
dws->dma_ops->dma_stop(dws);
spi_reset_chip(dws);
}
static int dw_spi_setup(struct spi_device *spi)
{
struct dw_spi_chip *chip_info = NULL;
struct chip_data *chip;
int ret;
chip = spi_get_ctldata(spi);
if (!chip) {
chip = kzalloc(sizeof(struct chip_data), GFP_KERNEL);
if (!chip)
return -ENOMEM;
spi_set_ctldata(spi, chip);
}
chip_info = spi->controller_data;
if (chip_info) {
if (chip_info->cs_control)
chip->cs_control = chip_info->cs_control;
chip->poll_mode = chip_info->poll_mode;
chip->type = chip_info->type;
}
chip->tmode = 0;
if (gpio_is_valid(spi->cs_gpio)) {
ret = gpio_direction_output(spi->cs_gpio,
!(spi->mode & SPI_CS_HIGH));
if (ret)
return ret;
}
return 0;
}
static void dw_spi_cleanup(struct spi_device *spi)
{
struct chip_data *chip = spi_get_ctldata(spi);
kfree(chip);
spi_set_ctldata(spi, NULL);
}
static void spi_hw_init(struct device *dev, struct dw_spi *dws)
{
spi_reset_chip(dws);
if (!dws->fifo_len) {
u32 fifo;
for (fifo = 1; fifo < 256; fifo++) {
dw_writel(dws, DW_SPI_TXFLTR, fifo);
if (fifo != dw_readl(dws, DW_SPI_TXFLTR))
break;
}
dw_writel(dws, DW_SPI_TXFLTR, 0);
dws->fifo_len = (fifo == 1) ? 0 : fifo;
dev_dbg(dev, "Detected FIFO size: %u bytes\n", dws->fifo_len);
}
}
int dw_spi_add_host(struct device *dev, struct dw_spi *dws)
{
struct spi_master *master;
int ret;
BUG_ON(dws == NULL);
master = spi_alloc_master(dev, 0);
if (!master)
return -ENOMEM;
dws->master = master;
dws->type = SSI_MOTO_SPI;
dws->dma_inited = 0;
dws->dma_addr = (dma_addr_t)(dws->paddr + DW_SPI_DR);
snprintf(dws->name, sizeof(dws->name), "dw_spi%d", dws->bus_num);
ret = request_irq(dws->irq, dw_spi_irq, IRQF_SHARED, dws->name, master);
if (ret < 0) {
dev_err(dev, "can not get IRQ\n");
goto err_free_master;
}
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_LOOP;
master->bits_per_word_mask = SPI_BPW_MASK(8) | SPI_BPW_MASK(16);
master->bus_num = dws->bus_num;
master->num_chipselect = dws->num_cs;
master->setup = dw_spi_setup;
master->cleanup = dw_spi_cleanup;
master->set_cs = dw_spi_set_cs;
master->transfer_one = dw_spi_transfer_one;
master->handle_err = dw_spi_handle_err;
master->max_speed_hz = dws->max_freq;
master->dev.of_node = dev->of_node;
spi_hw_init(dev, dws);
if (dws->dma_ops && dws->dma_ops->dma_init) {
ret = dws->dma_ops->dma_init(dws);
if (ret) {
dev_warn(dev, "DMA init failed\n");
dws->dma_inited = 0;
} else {
master->can_dma = dws->dma_ops->can_dma;
}
}
spi_master_set_devdata(master, dws);
ret = devm_spi_register_master(dev, master);
if (ret) {
dev_err(&master->dev, "problem registering spi master\n");
goto err_dma_exit;
}
dw_spi_debugfs_init(dws);
return 0;
err_dma_exit:
if (dws->dma_ops && dws->dma_ops->dma_exit)
dws->dma_ops->dma_exit(dws);
spi_enable_chip(dws, 0);
free_irq(dws->irq, master);
err_free_master:
spi_master_put(master);
return ret;
}
void dw_spi_remove_host(struct dw_spi *dws)
{
dw_spi_debugfs_remove(dws);
if (dws->dma_ops && dws->dma_ops->dma_exit)
dws->dma_ops->dma_exit(dws);
spi_shutdown_chip(dws);
free_irq(dws->irq, dws->master);
}
int dw_spi_suspend_host(struct dw_spi *dws)
{
int ret;
ret = spi_master_suspend(dws->master);
if (ret)
return ret;
spi_shutdown_chip(dws);
return 0;
}
int dw_spi_resume_host(struct dw_spi *dws)
{
int ret;
spi_hw_init(&dws->master->dev, dws);
ret = spi_master_resume(dws->master);
if (ret)
dev_err(&dws->master->dev, "fail to start queue (%d)\n", ret);
return ret;
}
