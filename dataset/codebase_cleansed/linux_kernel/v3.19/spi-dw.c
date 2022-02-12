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
static inline u32 tx_max(struct dw_spi *dws)
{
u32 tx_left, tx_room, rxtx_gap;
tx_left = (dws->tx_end - dws->tx) / dws->n_bytes;
tx_room = dws->fifo_len - dw_readw(dws, DW_SPI_TXFLR);
rxtx_gap = ((dws->rx_end - dws->rx) - (dws->tx_end - dws->tx))
/ dws->n_bytes;
return min3(tx_left, tx_room, (u32) (dws->fifo_len - rxtx_gap));
}
static inline u32 rx_max(struct dw_spi *dws)
{
u32 rx_left = (dws->rx_end - dws->rx) / dws->n_bytes;
return min_t(u32, rx_left, dw_readw(dws, DW_SPI_RXFLR));
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
dw_writew(dws, DW_SPI_DR, txw);
dws->tx += dws->n_bytes;
}
}
static void dw_reader(struct dw_spi *dws)
{
u32 max = rx_max(dws);
u16 rxw;
while (max--) {
rxw = dw_readw(dws, DW_SPI_DR);
if (dws->rx_end - dws->len) {
if (dws->n_bytes == 1)
*(u8 *)(dws->rx) = rxw;
else
*(u16 *)(dws->rx) = rxw;
}
dws->rx += dws->n_bytes;
}
}
static void *next_transfer(struct dw_spi *dws)
{
struct spi_message *msg = dws->cur_msg;
struct spi_transfer *trans = dws->cur_transfer;
if (trans->transfer_list.next != &msg->transfers) {
dws->cur_transfer =
list_entry(trans->transfer_list.next,
struct spi_transfer,
transfer_list);
return RUNNING_STATE;
}
return DONE_STATE;
}
static int map_dma_buffers(struct dw_spi *dws)
{
if (!dws->cur_msg->is_dma_mapped
|| !dws->dma_inited
|| !dws->cur_chip->enable_dma
|| !dws->dma_ops)
return 0;
if (dws->cur_transfer->tx_dma)
dws->tx_dma = dws->cur_transfer->tx_dma;
if (dws->cur_transfer->rx_dma)
dws->rx_dma = dws->cur_transfer->rx_dma;
return 1;
}
static void giveback(struct dw_spi *dws)
{
struct spi_transfer *last_transfer;
struct spi_message *msg;
msg = dws->cur_msg;
dws->cur_msg = NULL;
dws->cur_transfer = NULL;
dws->prev_chip = dws->cur_chip;
dws->cur_chip = NULL;
dws->dma_mapped = 0;
last_transfer = list_last_entry(&msg->transfers, struct spi_transfer,
transfer_list);
if (!last_transfer->cs_change)
spi_chip_sel(dws, msg->spi, 0);
spi_finalize_current_message(dws->master);
}
static void int_error_stop(struct dw_spi *dws, const char *msg)
{
spi_enable_chip(dws, 0);
dev_err(&dws->master->dev, "%s\n", msg);
dws->cur_msg->state = ERROR_STATE;
tasklet_schedule(&dws->pump_transfers);
}
void dw_spi_xfer_done(struct dw_spi *dws)
{
dws->cur_msg->actual_length += dws->len;
dws->cur_msg->state = next_transfer(dws);
if (dws->cur_msg->state == DONE_STATE) {
dws->cur_msg->status = 0;
giveback(dws);
} else
tasklet_schedule(&dws->pump_transfers);
}
static irqreturn_t interrupt_transfer(struct dw_spi *dws)
{
u16 irq_status = dw_readw(dws, DW_SPI_ISR);
if (irq_status & (SPI_INT_TXOI | SPI_INT_RXOI | SPI_INT_RXUI)) {
dw_readw(dws, DW_SPI_TXOICR);
dw_readw(dws, DW_SPI_RXOICR);
dw_readw(dws, DW_SPI_RXUICR);
int_error_stop(dws, "interrupt_transfer: fifo overrun/underrun");
return IRQ_HANDLED;
}
dw_reader(dws);
if (dws->rx_end == dws->rx) {
spi_mask_intr(dws, SPI_INT_TXEI);
dw_spi_xfer_done(dws);
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
struct dw_spi *dws = dev_id;
u16 irq_status = dw_readw(dws, DW_SPI_ISR) & 0x3f;
if (!irq_status)
return IRQ_NONE;
if (!dws->cur_msg) {
spi_mask_intr(dws, SPI_INT_TXEI);
return IRQ_HANDLED;
}
return dws->transfer_handler(dws);
}
static void poll_transfer(struct dw_spi *dws)
{
do {
dw_writer(dws);
dw_reader(dws);
cpu_relax();
} while (dws->rx_end > dws->rx);
dw_spi_xfer_done(dws);
}
static void pump_transfers(unsigned long data)
{
struct dw_spi *dws = (struct dw_spi *)data;
struct spi_message *message = NULL;
struct spi_transfer *transfer = NULL;
struct spi_transfer *previous = NULL;
struct spi_device *spi = NULL;
struct chip_data *chip = NULL;
u8 bits = 0;
u8 imask = 0;
u8 cs_change = 0;
u16 txint_level = 0;
u16 clk_div = 0;
u32 speed = 0;
u32 cr0 = 0;
message = dws->cur_msg;
transfer = dws->cur_transfer;
chip = dws->cur_chip;
spi = message->spi;
if (message->state == ERROR_STATE) {
message->status = -EIO;
goto early_exit;
}
if (message->state == DONE_STATE) {
message->status = 0;
goto early_exit;
}
if (message->state == RUNNING_STATE) {
previous = list_entry(transfer->transfer_list.prev,
struct spi_transfer,
transfer_list);
if (previous->delay_usecs)
udelay(previous->delay_usecs);
}
dws->n_bytes = chip->n_bytes;
dws->dma_width = chip->dma_width;
dws->cs_control = chip->cs_control;
dws->rx_dma = transfer->rx_dma;
dws->tx_dma = transfer->tx_dma;
dws->tx = (void *)transfer->tx_buf;
dws->tx_end = dws->tx + transfer->len;
dws->rx = transfer->rx_buf;
dws->rx_end = dws->rx + transfer->len;
dws->len = dws->cur_transfer->len;
if (chip != dws->prev_chip)
cs_change = 1;
cr0 = chip->cr0;
if (transfer->speed_hz) {
speed = chip->speed_hz;
if ((transfer->speed_hz != speed) || (!chip->clk_div)) {
speed = transfer->speed_hz;
clk_div = dws->max_freq / speed;
clk_div = (clk_div + 1) & 0xfffe;
chip->speed_hz = speed;
chip->clk_div = clk_div;
}
}
if (transfer->bits_per_word) {
bits = transfer->bits_per_word;
dws->n_bytes = dws->dma_width = bits >> 3;
cr0 = (bits - 1)
| (chip->type << SPI_FRF_OFFSET)
| (spi->mode << SPI_MODE_OFFSET)
| (chip->tmode << SPI_TMOD_OFFSET);
}
message->state = RUNNING_STATE;
if (dws->cs_control) {
if (dws->rx && dws->tx)
chip->tmode = SPI_TMOD_TR;
else if (dws->rx)
chip->tmode = SPI_TMOD_RO;
else
chip->tmode = SPI_TMOD_TO;
cr0 &= ~SPI_TMOD_MASK;
cr0 |= (chip->tmode << SPI_TMOD_OFFSET);
}
dws->dma_mapped = map_dma_buffers(dws);
if (!dws->dma_mapped && !chip->poll_mode) {
int templen = dws->len / dws->n_bytes;
txint_level = dws->fifo_len / 2;
txint_level = (templen > txint_level) ? txint_level : templen;
imask |= SPI_INT_TXEI | SPI_INT_TXOI |
SPI_INT_RXUI | SPI_INT_RXOI;
dws->transfer_handler = interrupt_transfer;
}
if (dw_readw(dws, DW_SPI_CTRL0) != cr0 || cs_change || clk_div || imask) {
spi_enable_chip(dws, 0);
if (dw_readw(dws, DW_SPI_CTRL0) != cr0)
dw_writew(dws, DW_SPI_CTRL0, cr0);
spi_set_clk(dws, clk_div ? clk_div : chip->clk_div);
spi_chip_sel(dws, spi, 1);
spi_mask_intr(dws, 0xff);
if (imask)
spi_umask_intr(dws, imask);
if (txint_level)
dw_writew(dws, DW_SPI_TXFLTR, txint_level);
spi_enable_chip(dws, 1);
if (cs_change)
dws->prev_chip = chip;
}
if (dws->dma_mapped)
dws->dma_ops->dma_transfer(dws, cs_change);
if (chip->poll_mode)
poll_transfer(dws);
return;
early_exit:
giveback(dws);
}
static int dw_spi_transfer_one_message(struct spi_master *master,
struct spi_message *msg)
{
struct dw_spi *dws = spi_master_get_devdata(master);
dws->cur_msg = msg;
dws->cur_msg->state = START_STATE;
dws->cur_transfer = list_entry(dws->cur_msg->transfers.next,
struct spi_transfer,
transfer_list);
dws->cur_chip = spi_get_ctldata(dws->cur_msg->spi);
tasklet_schedule(&dws->pump_transfers);
return 0;
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
chip->rx_threshold = 0;
chip->tx_threshold = 0;
chip->enable_dma = chip_info->enable_dma;
}
if (spi->bits_per_word == 8) {
chip->n_bytes = 1;
chip->dma_width = 1;
} else if (spi->bits_per_word == 16) {
chip->n_bytes = 2;
chip->dma_width = 2;
}
chip->bits_per_word = spi->bits_per_word;
if (!spi->max_speed_hz) {
dev_err(&spi->dev, "No max speed HZ parameter\n");
return -EINVAL;
}
chip->tmode = 0;
chip->cr0 = (chip->bits_per_word - 1)
| (chip->type << SPI_FRF_OFFSET)
| (spi->mode << SPI_MODE_OFFSET)
| (chip->tmode << SPI_TMOD_OFFSET);
if (spi->mode & SPI_LOOP)
chip->cr0 |= 1 << SPI_SRL_OFFSET;
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
static void spi_hw_init(struct dw_spi *dws)
{
spi_enable_chip(dws, 0);
spi_mask_intr(dws, 0xff);
spi_enable_chip(dws, 1);
if (!dws->fifo_len) {
u32 fifo;
for (fifo = 2; fifo <= 256; fifo++) {
dw_writew(dws, DW_SPI_TXFLTR, fifo);
if (fifo != dw_readw(dws, DW_SPI_TXFLTR))
break;
}
dws->fifo_len = (fifo == 2) ? 0 : fifo - 1;
dw_writew(dws, DW_SPI_TXFLTR, 0);
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
dws->prev_chip = NULL;
dws->dma_inited = 0;
dws->dma_addr = (dma_addr_t)(dws->paddr + 0x60);
snprintf(dws->name, sizeof(dws->name), "dw_spi%d", dws->bus_num);
ret = devm_request_irq(dev, dws->irq, dw_spi_irq, IRQF_SHARED,
dws->name, dws);
if (ret < 0) {
dev_err(&master->dev, "can not get IRQ\n");
goto err_free_master;
}
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_LOOP;
master->bits_per_word_mask = SPI_BPW_MASK(8) | SPI_BPW_MASK(16);
master->bus_num = dws->bus_num;
master->num_chipselect = dws->num_cs;
master->setup = dw_spi_setup;
master->cleanup = dw_spi_cleanup;
master->transfer_one_message = dw_spi_transfer_one_message;
master->max_speed_hz = dws->max_freq;
master->dev.of_node = dev->of_node;
spi_hw_init(dws);
if (dws->dma_ops && dws->dma_ops->dma_init) {
ret = dws->dma_ops->dma_init(dws);
if (ret) {
dev_warn(dev, "DMA init failed\n");
dws->dma_inited = 0;
}
}
tasklet_init(&dws->pump_transfers, pump_transfers, (unsigned long)dws);
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
err_free_master:
spi_master_put(master);
return ret;
}
void dw_spi_remove_host(struct dw_spi *dws)
{
if (!dws)
return;
dw_spi_debugfs_remove(dws);
if (dws->dma_ops && dws->dma_ops->dma_exit)
dws->dma_ops->dma_exit(dws);
spi_enable_chip(dws, 0);
spi_set_clk(dws, 0);
}
int dw_spi_suspend_host(struct dw_spi *dws)
{
int ret = 0;
ret = spi_master_suspend(dws->master);
if (ret)
return ret;
spi_enable_chip(dws, 0);
spi_set_clk(dws, 0);
return ret;
}
int dw_spi_resume_host(struct dw_spi *dws)
{
int ret;
spi_hw_init(dws);
ret = spi_master_resume(dws->master);
if (ret)
dev_err(&dws->master->dev, "fail to start queue (%d)\n", ret);
return ret;
}
