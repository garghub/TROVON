static inline u8 bcm_spi_readb(struct bcm63xx_spi *bs,
unsigned int offset)
{
return readb(bs->regs + bs->reg_offsets[offset]);
}
static inline u16 bcm_spi_readw(struct bcm63xx_spi *bs,
unsigned int offset)
{
#ifdef CONFIG_CPU_BIG_ENDIAN
return ioread16be(bs->regs + bs->reg_offsets[offset]);
#else
return readw(bs->regs + bs->reg_offsets[offset]);
#endif
}
static inline void bcm_spi_writeb(struct bcm63xx_spi *bs,
u8 value, unsigned int offset)
{
writeb(value, bs->regs + bs->reg_offsets[offset]);
}
static inline void bcm_spi_writew(struct bcm63xx_spi *bs,
u16 value, unsigned int offset)
{
#ifdef CONFIG_CPU_BIG_ENDIAN
iowrite16be(value, bs->regs + bs->reg_offsets[offset]);
#else
writew(value, bs->regs + bs->reg_offsets[offset]);
#endif
}
static void bcm63xx_spi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct bcm63xx_spi *bs = spi_master_get_devdata(spi->master);
u8 clk_cfg, reg;
int i;
clk_cfg = SPI_CLK_0_391MHZ;
for (i = 0; i < SPI_CLK_MASK; i++) {
if (t->speed_hz >= bcm63xx_spi_freq_table[i][0]) {
clk_cfg = bcm63xx_spi_freq_table[i][1];
break;
}
}
reg = bcm_spi_readb(bs, SPI_CLK_CFG);
reg &= ~SPI_CLK_MASK;
reg |= clk_cfg;
bcm_spi_writeb(bs, reg, SPI_CLK_CFG);
dev_dbg(&spi->dev, "Setting clock register to %02x (hz %d)\n",
clk_cfg, t->speed_hz);
}
static int bcm63xx_txrx_bufs(struct spi_device *spi, struct spi_transfer *first,
unsigned int num_transfers)
{
struct bcm63xx_spi *bs = spi_master_get_devdata(spi->master);
u16 msg_ctl;
u16 cmd;
unsigned int i, timeout = 0, prepend_len = 0, len = 0;
struct spi_transfer *t = first;
bool do_rx = false;
bool do_tx = false;
bcm_spi_writeb(bs, 0, SPI_INT_MASK);
dev_dbg(&spi->dev, "txrx: tx %p, rx %p, len %d\n",
t->tx_buf, t->rx_buf, t->len);
if (num_transfers > 1 && t->tx_buf && t->len <= BCM63XX_SPI_MAX_PREPEND)
prepend_len = t->len;
for (i = 0; i < num_transfers; i++) {
if (t->tx_buf) {
do_tx = true;
memcpy_toio(bs->tx_io + len, t->tx_buf, t->len);
if (t != first)
prepend_len = 0;
}
if (t->rx_buf) {
do_rx = true;
if (t == first)
prepend_len = 0;
}
len += t->len;
t = list_entry(t->transfer_list.next, struct spi_transfer,
transfer_list);
}
reinit_completion(&bs->done);
msg_ctl = (len << SPI_BYTE_CNT_SHIFT);
if (do_rx && do_tx && prepend_len == 0)
msg_ctl |= (SPI_FD_RW << bs->msg_type_shift);
else if (do_rx)
msg_ctl |= (SPI_HD_R << bs->msg_type_shift);
else if (do_tx)
msg_ctl |= (SPI_HD_W << bs->msg_type_shift);
switch (bs->msg_ctl_width) {
case 8:
bcm_spi_writeb(bs, msg_ctl, SPI_MSG_CTL);
break;
case 16:
bcm_spi_writew(bs, msg_ctl, SPI_MSG_CTL);
break;
}
cmd = SPI_CMD_START_IMMEDIATE;
cmd |= (prepend_len << SPI_CMD_PREPEND_BYTE_CNT_SHIFT);
cmd |= (spi->chip_select << SPI_CMD_DEVICE_ID_SHIFT);
bcm_spi_writew(bs, cmd, SPI_CMD);
bcm_spi_writeb(bs, SPI_INTR_CMD_DONE, SPI_INT_MASK);
timeout = wait_for_completion_timeout(&bs->done, HZ);
if (!timeout)
return -ETIMEDOUT;
if (!do_rx)
return 0;
len = 0;
t = first;
for (i = 0; i < num_transfers; i++) {
if (t->rx_buf)
memcpy_fromio(t->rx_buf, bs->rx_io + len, t->len);
if (t != first || prepend_len == 0)
len += t->len;
t = list_entry(t->transfer_list.next, struct spi_transfer,
transfer_list);
}
return 0;
}
static int bcm63xx_spi_transfer_one(struct spi_master *master,
struct spi_message *m)
{
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
struct spi_transfer *t, *first = NULL;
struct spi_device *spi = m->spi;
int status = 0;
unsigned int n_transfers = 0, total_len = 0;
bool can_use_prepend = false;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (!first)
first = t;
n_transfers++;
total_len += t->len;
if (n_transfers == 2 && !first->rx_buf && !t->tx_buf &&
first->len <= BCM63XX_SPI_MAX_PREPEND)
can_use_prepend = true;
else if (can_use_prepend && t->tx_buf)
can_use_prepend = false;
if ((can_use_prepend &&
total_len > (bs->fifo_size + BCM63XX_SPI_MAX_PREPEND)) ||
(!can_use_prepend && total_len > bs->fifo_size)) {
dev_err(&spi->dev, "unable to do transfers larger than FIFO size (%i > %i)\n",
total_len, bs->fifo_size);
status = -EINVAL;
goto exit;
}
if (t->speed_hz != first->speed_hz) {
dev_err(&spi->dev, "unable to change speed between transfers\n");
status = -EINVAL;
goto exit;
}
if (t->delay_usecs) {
dev_err(&spi->dev, "unable to keep CS asserted after transfer\n");
status = -EINVAL;
goto exit;
}
if (t->cs_change ||
list_is_last(&t->transfer_list, &m->transfers)) {
bcm63xx_spi_setup_transfer(spi, first);
status = bcm63xx_txrx_bufs(spi, first, n_transfers);
if (status)
goto exit;
m->actual_length += total_len;
first = NULL;
n_transfers = 0;
total_len = 0;
can_use_prepend = false;
}
}
exit:
m->status = status;
spi_finalize_current_message(master);
return 0;
}
static irqreturn_t bcm63xx_spi_interrupt(int irq, void *dev_id)
{
struct spi_master *master = (struct spi_master *)dev_id;
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
u8 intr;
intr = bcm_spi_readb(bs, SPI_INT_STATUS);
bcm_spi_writeb(bs, SPI_INTR_CLEAR_ALL, SPI_INT_STATUS);
bcm_spi_writeb(bs, 0, SPI_INT_MASK);
if (intr & SPI_INTR_CMD_DONE)
complete(&bs->done);
return IRQ_HANDLED;
}
static size_t bcm63xx_spi_max_length(struct spi_device *spi)
{
struct bcm63xx_spi *bs = spi_master_get_devdata(spi->master);
return bs->fifo_size;
}
static int bcm63xx_spi_probe(struct platform_device *pdev)
{
struct resource *r;
const unsigned long *bcm63xx_spireg;
struct device *dev = &pdev->dev;
int irq, bus_num;
struct spi_master *master;
struct clk *clk;
struct bcm63xx_spi *bs;
int ret;
u32 num_cs = BCM63XX_SPI_MAX_CS;
if (dev->of_node) {
const struct of_device_id *match;
match = of_match_node(bcm63xx_spi_of_match, dev->of_node);
if (!match)
return -EINVAL;
bcm63xx_spireg = match->data;
of_property_read_u32(dev->of_node, "num-cs", &num_cs);
if (num_cs > BCM63XX_SPI_MAX_CS) {
dev_warn(dev, "unsupported number of cs (%i), reducing to 8\n",
num_cs);
num_cs = BCM63XX_SPI_MAX_CS;
}
bus_num = -1;
} else if (pdev->id_entry->driver_data) {
const struct platform_device_id *match = pdev->id_entry;
bcm63xx_spireg = (const unsigned long *)match->driver_data;
bus_num = BCM63XX_SPI_BUS_NUM;
} else {
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "no irq: %d\n", irq);
return irq;
}
clk = devm_clk_get(dev, "spi");
if (IS_ERR(clk)) {
dev_err(dev, "no clock for device\n");
return PTR_ERR(clk);
}
master = spi_alloc_master(dev, sizeof(*bs));
if (!master) {
dev_err(dev, "out of memory\n");
return -ENOMEM;
}
bs = spi_master_get_devdata(master);
init_completion(&bs->done);
platform_set_drvdata(pdev, master);
bs->pdev = pdev;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
bs->regs = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(bs->regs)) {
ret = PTR_ERR(bs->regs);
goto out_err;
}
bs->irq = irq;
bs->clk = clk;
bs->reg_offsets = bcm63xx_spireg;
bs->fifo_size = bs->reg_offsets[SPI_MSG_DATA_SIZE];
ret = devm_request_irq(&pdev->dev, irq, bcm63xx_spi_interrupt, 0,
pdev->name, master);
if (ret) {
dev_err(dev, "unable to request irq\n");
goto out_err;
}
master->dev.of_node = dev->of_node;
master->bus_num = bus_num;
master->num_chipselect = num_cs;
master->transfer_one_message = bcm63xx_spi_transfer_one;
master->mode_bits = MODEBITS;
master->bits_per_word_mask = SPI_BPW_MASK(8);
master->max_transfer_size = bcm63xx_spi_max_length;
master->max_message_size = bcm63xx_spi_max_length;
master->auto_runtime_pm = true;
bs->msg_type_shift = bs->reg_offsets[SPI_MSG_TYPE_SHIFT];
bs->msg_ctl_width = bs->reg_offsets[SPI_MSG_CTL_WIDTH];
bs->tx_io = (u8 *)(bs->regs + bs->reg_offsets[SPI_MSG_DATA]);
bs->rx_io = (const u8 *)(bs->regs + bs->reg_offsets[SPI_RX_DATA]);
ret = clk_prepare_enable(bs->clk);
if (ret)
goto out_err;
bcm_spi_writeb(bs, SPI_INTR_CLEAR_ALL, SPI_INT_STATUS);
ret = devm_spi_register_master(dev, master);
if (ret) {
dev_err(dev, "spi register failed\n");
goto out_clk_disable;
}
dev_info(dev, "at %pr (irq %d, FIFOs size %d)\n",
r, irq, bs->fifo_size);
return 0;
out_clk_disable:
clk_disable_unprepare(clk);
out_err:
spi_master_put(master);
return ret;
}
static int bcm63xx_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
bcm_spi_writeb(bs, 0, SPI_INT_MASK);
clk_disable_unprepare(bs->clk);
return 0;
}
static int bcm63xx_spi_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
spi_master_suspend(master);
clk_disable_unprepare(bs->clk);
return 0;
}
static int bcm63xx_spi_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct bcm63xx_spi *bs = spi_master_get_devdata(master);
int ret;
ret = clk_prepare_enable(bs->clk);
if (ret)
return ret;
spi_master_resume(master);
return 0;
}
