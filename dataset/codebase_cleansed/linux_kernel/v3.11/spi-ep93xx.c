static inline void
ep93xx_spi_write_u8(const struct ep93xx_spi *espi, u16 reg, u8 value)
{
__raw_writeb(value, espi->regs_base + reg);
}
static inline u8
ep93xx_spi_read_u8(const struct ep93xx_spi *spi, u16 reg)
{
return __raw_readb(spi->regs_base + reg);
}
static inline void
ep93xx_spi_write_u16(const struct ep93xx_spi *espi, u16 reg, u16 value)
{
__raw_writew(value, espi->regs_base + reg);
}
static inline u16
ep93xx_spi_read_u16(const struct ep93xx_spi *spi, u16 reg)
{
return __raw_readw(spi->regs_base + reg);
}
static int ep93xx_spi_enable(const struct ep93xx_spi *espi)
{
u8 regval;
int err;
err = clk_enable(espi->clk);
if (err)
return err;
regval = ep93xx_spi_read_u8(espi, SSPCR1);
regval |= SSPCR1_SSE;
ep93xx_spi_write_u8(espi, SSPCR1, regval);
return 0;
}
static void ep93xx_spi_disable(const struct ep93xx_spi *espi)
{
u8 regval;
regval = ep93xx_spi_read_u8(espi, SSPCR1);
regval &= ~SSPCR1_SSE;
ep93xx_spi_write_u8(espi, SSPCR1, regval);
clk_disable(espi->clk);
}
static void ep93xx_spi_enable_interrupts(const struct ep93xx_spi *espi)
{
u8 regval;
regval = ep93xx_spi_read_u8(espi, SSPCR1);
regval |= (SSPCR1_RORIE | SSPCR1_TIE | SSPCR1_RIE);
ep93xx_spi_write_u8(espi, SSPCR1, regval);
}
static void ep93xx_spi_disable_interrupts(const struct ep93xx_spi *espi)
{
u8 regval;
regval = ep93xx_spi_read_u8(espi, SSPCR1);
regval &= ~(SSPCR1_RORIE | SSPCR1_TIE | SSPCR1_RIE);
ep93xx_spi_write_u8(espi, SSPCR1, regval);
}
static int ep93xx_spi_calc_divisors(const struct ep93xx_spi *espi,
struct ep93xx_spi_chip *chip,
unsigned long rate)
{
unsigned long spi_clk_rate = clk_get_rate(espi->clk);
int cpsr, scr;
rate = clamp(rate, espi->min_rate, espi->max_rate);
for (cpsr = 2; cpsr <= 254; cpsr += 2) {
for (scr = 0; scr <= 255; scr++) {
if ((spi_clk_rate / (cpsr * (scr + 1))) <= rate) {
chip->div_scr = (u8)scr;
chip->div_cpsr = (u8)cpsr;
return 0;
}
}
}
return -EINVAL;
}
static void ep93xx_spi_cs_control(struct spi_device *spi, bool control)
{
struct ep93xx_spi_chip *chip = spi_get_ctldata(spi);
int value = (spi->mode & SPI_CS_HIGH) ? control : !control;
if (chip->ops && chip->ops->cs_control)
chip->ops->cs_control(spi, value);
}
static int ep93xx_spi_setup(struct spi_device *spi)
{
struct ep93xx_spi *espi = spi_master_get_devdata(spi->master);
struct ep93xx_spi_chip *chip;
chip = spi_get_ctldata(spi);
if (!chip) {
dev_dbg(&espi->pdev->dev, "initial setup for %s\n",
spi->modalias);
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->spi = spi;
chip->ops = spi->controller_data;
if (chip->ops && chip->ops->setup) {
int ret = chip->ops->setup(spi);
if (ret) {
kfree(chip);
return ret;
}
}
spi_set_ctldata(spi, chip);
}
if (spi->max_speed_hz != chip->rate) {
int err;
err = ep93xx_spi_calc_divisors(espi, chip, spi->max_speed_hz);
if (err != 0) {
spi_set_ctldata(spi, NULL);
kfree(chip);
return err;
}
chip->rate = spi->max_speed_hz;
}
chip->dss = bits_per_word_to_dss(spi->bits_per_word);
ep93xx_spi_cs_control(spi, false);
return 0;
}
static int ep93xx_spi_transfer(struct spi_device *spi, struct spi_message *msg)
{
struct ep93xx_spi *espi = spi_master_get_devdata(spi->master);
struct spi_transfer *t;
unsigned long flags;
if (!msg || !msg->complete)
return -EINVAL;
list_for_each_entry(t, &msg->transfers, transfer_list) {
if (t->speed_hz && t->speed_hz < espi->min_rate)
return -EINVAL;
}
msg->state = NULL;
msg->status = 0;
msg->actual_length = 0;
spin_lock_irqsave(&espi->lock, flags);
if (!espi->running) {
spin_unlock_irqrestore(&espi->lock, flags);
return -ESHUTDOWN;
}
list_add_tail(&msg->queue, &espi->msg_queue);
queue_work(espi->wq, &espi->msg_work);
spin_unlock_irqrestore(&espi->lock, flags);
return 0;
}
static void ep93xx_spi_cleanup(struct spi_device *spi)
{
struct ep93xx_spi_chip *chip;
chip = spi_get_ctldata(spi);
if (chip) {
if (chip->ops && chip->ops->cleanup)
chip->ops->cleanup(spi);
spi_set_ctldata(spi, NULL);
kfree(chip);
}
}
static void ep93xx_spi_chip_setup(const struct ep93xx_spi *espi,
const struct ep93xx_spi_chip *chip)
{
u16 cr0;
cr0 = chip->div_scr << SSPCR0_SCR_SHIFT;
cr0 |= (chip->spi->mode & (SPI_CPHA|SPI_CPOL)) << SSPCR0_MODE_SHIFT;
cr0 |= chip->dss;
dev_dbg(&espi->pdev->dev, "setup: mode %d, cpsr %d, scr %d, dss %d\n",
chip->spi->mode, chip->div_cpsr, chip->div_scr, chip->dss);
dev_dbg(&espi->pdev->dev, "setup: cr0 %#x", cr0);
ep93xx_spi_write_u8(espi, SSPCPSR, chip->div_cpsr);
ep93xx_spi_write_u16(espi, SSPCR0, cr0);
}
static inline int bits_per_word(const struct ep93xx_spi *espi)
{
struct spi_message *msg = espi->current_msg;
struct spi_transfer *t = msg->state;
return t->bits_per_word;
}
static void ep93xx_do_write(struct ep93xx_spi *espi, struct spi_transfer *t)
{
if (bits_per_word(espi) > 8) {
u16 tx_val = 0;
if (t->tx_buf)
tx_val = ((u16 *)t->tx_buf)[espi->tx];
ep93xx_spi_write_u16(espi, SSPDR, tx_val);
espi->tx += sizeof(tx_val);
} else {
u8 tx_val = 0;
if (t->tx_buf)
tx_val = ((u8 *)t->tx_buf)[espi->tx];
ep93xx_spi_write_u8(espi, SSPDR, tx_val);
espi->tx += sizeof(tx_val);
}
}
static void ep93xx_do_read(struct ep93xx_spi *espi, struct spi_transfer *t)
{
if (bits_per_word(espi) > 8) {
u16 rx_val;
rx_val = ep93xx_spi_read_u16(espi, SSPDR);
if (t->rx_buf)
((u16 *)t->rx_buf)[espi->rx] = rx_val;
espi->rx += sizeof(rx_val);
} else {
u8 rx_val;
rx_val = ep93xx_spi_read_u8(espi, SSPDR);
if (t->rx_buf)
((u8 *)t->rx_buf)[espi->rx] = rx_val;
espi->rx += sizeof(rx_val);
}
}
static int ep93xx_spi_read_write(struct ep93xx_spi *espi)
{
struct spi_message *msg = espi->current_msg;
struct spi_transfer *t = msg->state;
while ((ep93xx_spi_read_u8(espi, SSPSR) & SSPSR_RNE)) {
ep93xx_do_read(espi, t);
espi->fifo_level--;
}
while (espi->fifo_level < SPI_FIFO_SIZE && espi->tx < t->len) {
ep93xx_do_write(espi, t);
espi->fifo_level++;
}
if (espi->rx == t->len)
return 0;
return -EINPROGRESS;
}
static void ep93xx_spi_pio_transfer(struct ep93xx_spi *espi)
{
if (ep93xx_spi_read_write(espi)) {
ep93xx_spi_enable_interrupts(espi);
wait_for_completion(&espi->wait);
}
}
static struct dma_async_tx_descriptor *
ep93xx_spi_dma_prepare(struct ep93xx_spi *espi, enum dma_transfer_direction dir)
{
struct spi_transfer *t = espi->current_msg->state;
struct dma_async_tx_descriptor *txd;
enum dma_slave_buswidth buswidth;
struct dma_slave_config conf;
struct scatterlist *sg;
struct sg_table *sgt;
struct dma_chan *chan;
const void *buf, *pbuf;
size_t len = t->len;
int i, ret, nents;
if (bits_per_word(espi) > 8)
buswidth = DMA_SLAVE_BUSWIDTH_2_BYTES;
else
buswidth = DMA_SLAVE_BUSWIDTH_1_BYTE;
memset(&conf, 0, sizeof(conf));
conf.direction = dir;
if (dir == DMA_DEV_TO_MEM) {
chan = espi->dma_rx;
buf = t->rx_buf;
sgt = &espi->rx_sgt;
conf.src_addr = espi->sspdr_phys;
conf.src_addr_width = buswidth;
} else {
chan = espi->dma_tx;
buf = t->tx_buf;
sgt = &espi->tx_sgt;
conf.dst_addr = espi->sspdr_phys;
conf.dst_addr_width = buswidth;
}
ret = dmaengine_slave_config(chan, &conf);
if (ret)
return ERR_PTR(ret);
nents = DIV_ROUND_UP(len, PAGE_SIZE);
if (nents != sgt->nents) {
sg_free_table(sgt);
ret = sg_alloc_table(sgt, nents, GFP_KERNEL);
if (ret)
return ERR_PTR(ret);
}
pbuf = buf;
for_each_sg(sgt->sgl, sg, sgt->nents, i) {
size_t bytes = min_t(size_t, len, PAGE_SIZE);
if (buf) {
sg_set_page(sg, virt_to_page(pbuf), bytes,
offset_in_page(pbuf));
} else {
sg_set_page(sg, virt_to_page(espi->zeropage),
bytes, 0);
}
pbuf += bytes;
len -= bytes;
}
if (WARN_ON(len)) {
dev_warn(&espi->pdev->dev, "len = %d expected 0!", len);
return ERR_PTR(-EINVAL);
}
nents = dma_map_sg(chan->device->dev, sgt->sgl, sgt->nents, dir);
if (!nents)
return ERR_PTR(-ENOMEM);
txd = dmaengine_prep_slave_sg(chan, sgt->sgl, nents, dir, DMA_CTRL_ACK);
if (!txd) {
dma_unmap_sg(chan->device->dev, sgt->sgl, sgt->nents, dir);
return ERR_PTR(-ENOMEM);
}
return txd;
}
static void ep93xx_spi_dma_finish(struct ep93xx_spi *espi,
enum dma_transfer_direction dir)
{
struct dma_chan *chan;
struct sg_table *sgt;
if (dir == DMA_DEV_TO_MEM) {
chan = espi->dma_rx;
sgt = &espi->rx_sgt;
} else {
chan = espi->dma_tx;
sgt = &espi->tx_sgt;
}
dma_unmap_sg(chan->device->dev, sgt->sgl, sgt->nents, dir);
}
static void ep93xx_spi_dma_callback(void *callback_param)
{
complete(callback_param);
}
static void ep93xx_spi_dma_transfer(struct ep93xx_spi *espi)
{
struct spi_message *msg = espi->current_msg;
struct dma_async_tx_descriptor *rxd, *txd;
rxd = ep93xx_spi_dma_prepare(espi, DMA_DEV_TO_MEM);
if (IS_ERR(rxd)) {
dev_err(&espi->pdev->dev, "DMA RX failed: %ld\n", PTR_ERR(rxd));
msg->status = PTR_ERR(rxd);
return;
}
txd = ep93xx_spi_dma_prepare(espi, DMA_MEM_TO_DEV);
if (IS_ERR(txd)) {
ep93xx_spi_dma_finish(espi, DMA_DEV_TO_MEM);
dev_err(&espi->pdev->dev, "DMA TX failed: %ld\n", PTR_ERR(rxd));
msg->status = PTR_ERR(txd);
return;
}
rxd->callback = ep93xx_spi_dma_callback;
rxd->callback_param = &espi->wait;
dmaengine_submit(rxd);
dmaengine_submit(txd);
dma_async_issue_pending(espi->dma_rx);
dma_async_issue_pending(espi->dma_tx);
wait_for_completion(&espi->wait);
ep93xx_spi_dma_finish(espi, DMA_MEM_TO_DEV);
ep93xx_spi_dma_finish(espi, DMA_DEV_TO_MEM);
}
static void ep93xx_spi_process_transfer(struct ep93xx_spi *espi,
struct spi_message *msg,
struct spi_transfer *t)
{
struct ep93xx_spi_chip *chip = spi_get_ctldata(msg->spi);
msg->state = t;
if (t->speed_hz || t->bits_per_word) {
struct ep93xx_spi_chip tmp_chip = *chip;
if (t->speed_hz) {
int err;
err = ep93xx_spi_calc_divisors(espi, &tmp_chip,
t->speed_hz);
if (err) {
dev_err(&espi->pdev->dev,
"failed to adjust speed\n");
msg->status = err;
return;
}
}
if (t->bits_per_word)
tmp_chip.dss = bits_per_word_to_dss(t->bits_per_word);
ep93xx_spi_chip_setup(espi, &tmp_chip);
}
espi->rx = 0;
espi->tx = 0;
if (espi->dma_rx && t->len > SPI_FIFO_SIZE)
ep93xx_spi_dma_transfer(espi);
else
ep93xx_spi_pio_transfer(espi);
if (msg->status)
return;
msg->actual_length += t->len;
if (t->delay_usecs) {
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(usecs_to_jiffies(t->delay_usecs));
}
if (t->cs_change) {
if (!list_is_last(&t->transfer_list, &msg->transfers)) {
ep93xx_spi_cs_control(msg->spi, false);
cond_resched();
ep93xx_spi_cs_control(msg->spi, true);
}
}
if (t->speed_hz || t->bits_per_word)
ep93xx_spi_chip_setup(espi, chip);
}
static void ep93xx_spi_process_message(struct ep93xx_spi *espi,
struct spi_message *msg)
{
unsigned long timeout;
struct spi_transfer *t;
int err;
err = ep93xx_spi_enable(espi);
if (err) {
dev_err(&espi->pdev->dev, "failed to enable SPI controller\n");
msg->status = err;
return;
}
timeout = jiffies + msecs_to_jiffies(SPI_TIMEOUT);
while (ep93xx_spi_read_u16(espi, SSPSR) & SSPSR_RNE) {
if (time_after(jiffies, timeout)) {
dev_warn(&espi->pdev->dev,
"timeout while flushing RX FIFO\n");
msg->status = -ETIMEDOUT;
return;
}
ep93xx_spi_read_u16(espi, SSPDR);
}
espi->fifo_level = 0;
ep93xx_spi_chip_setup(espi, spi_get_ctldata(msg->spi));
ep93xx_spi_cs_control(msg->spi, true);
list_for_each_entry(t, &msg->transfers, transfer_list) {
ep93xx_spi_process_transfer(espi, msg, t);
if (msg->status)
break;
}
ep93xx_spi_cs_control(msg->spi, false);
ep93xx_spi_disable(espi);
}
static void ep93xx_spi_work(struct work_struct *work)
{
struct ep93xx_spi *espi = work_to_espi(work);
struct spi_message *msg;
spin_lock_irq(&espi->lock);
if (!espi->running || espi->current_msg ||
list_empty(&espi->msg_queue)) {
spin_unlock_irq(&espi->lock);
return;
}
msg = list_first_entry(&espi->msg_queue, struct spi_message, queue);
list_del_init(&msg->queue);
espi->current_msg = msg;
spin_unlock_irq(&espi->lock);
ep93xx_spi_process_message(espi, msg);
spin_lock_irq(&espi->lock);
espi->current_msg = NULL;
if (espi->running && !list_empty(&espi->msg_queue))
queue_work(espi->wq, &espi->msg_work);
spin_unlock_irq(&espi->lock);
msg->complete(msg->context);
}
static irqreturn_t ep93xx_spi_interrupt(int irq, void *dev_id)
{
struct ep93xx_spi *espi = dev_id;
u8 irq_status = ep93xx_spi_read_u8(espi, SSPIIR);
if (unlikely(irq_status & SSPIIR_RORIS)) {
ep93xx_spi_write_u8(espi, SSPICR, 0);
dev_warn(&espi->pdev->dev,
"receive overrun, aborting the message\n");
espi->current_msg->status = -EIO;
} else {
if (ep93xx_spi_read_write(espi)) {
return IRQ_HANDLED;
}
}
ep93xx_spi_disable_interrupts(espi);
complete(&espi->wait);
return IRQ_HANDLED;
}
static bool ep93xx_spi_dma_filter(struct dma_chan *chan, void *filter_param)
{
if (ep93xx_dma_chan_is_m2p(chan))
return false;
chan->private = filter_param;
return true;
}
static int ep93xx_spi_setup_dma(struct ep93xx_spi *espi)
{
dma_cap_mask_t mask;
int ret;
espi->zeropage = (void *)get_zeroed_page(GFP_KERNEL);
if (!espi->zeropage)
return -ENOMEM;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
espi->dma_rx_data.port = EP93XX_DMA_SSP;
espi->dma_rx_data.direction = DMA_DEV_TO_MEM;
espi->dma_rx_data.name = "ep93xx-spi-rx";
espi->dma_rx = dma_request_channel(mask, ep93xx_spi_dma_filter,
&espi->dma_rx_data);
if (!espi->dma_rx) {
ret = -ENODEV;
goto fail_free_page;
}
espi->dma_tx_data.port = EP93XX_DMA_SSP;
espi->dma_tx_data.direction = DMA_MEM_TO_DEV;
espi->dma_tx_data.name = "ep93xx-spi-tx";
espi->dma_tx = dma_request_channel(mask, ep93xx_spi_dma_filter,
&espi->dma_tx_data);
if (!espi->dma_tx) {
ret = -ENODEV;
goto fail_release_rx;
}
return 0;
fail_release_rx:
dma_release_channel(espi->dma_rx);
espi->dma_rx = NULL;
fail_free_page:
free_page((unsigned long)espi->zeropage);
return ret;
}
static void ep93xx_spi_release_dma(struct ep93xx_spi *espi)
{
if (espi->dma_rx) {
dma_release_channel(espi->dma_rx);
sg_free_table(&espi->rx_sgt);
}
if (espi->dma_tx) {
dma_release_channel(espi->dma_tx);
sg_free_table(&espi->tx_sgt);
}
if (espi->zeropage)
free_page((unsigned long)espi->zeropage);
}
static int ep93xx_spi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct ep93xx_spi_info *info;
struct ep93xx_spi *espi;
struct resource *res;
int irq;
int error;
info = pdev->dev.platform_data;
master = spi_alloc_master(&pdev->dev, sizeof(*espi));
if (!master) {
dev_err(&pdev->dev, "failed to allocate spi master\n");
return -ENOMEM;
}
master->setup = ep93xx_spi_setup;
master->transfer = ep93xx_spi_transfer;
master->cleanup = ep93xx_spi_cleanup;
master->bus_num = pdev->id;
master->num_chipselect = info->num_chipselect;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 16);
platform_set_drvdata(pdev, master);
espi = spi_master_get_devdata(master);
espi->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(espi->clk)) {
dev_err(&pdev->dev, "unable to get spi clock\n");
error = PTR_ERR(espi->clk);
goto fail_release_master;
}
spin_lock_init(&espi->lock);
init_completion(&espi->wait);
espi->max_rate = clk_get_rate(espi->clk) / 2;
espi->min_rate = clk_get_rate(espi->clk) / (254 * 256);
espi->pdev = pdev;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
error = -EBUSY;
dev_err(&pdev->dev, "failed to get irq resources\n");
goto fail_put_clock;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "unable to get iomem resource\n");
error = -ENODEV;
goto fail_put_clock;
}
espi->sspdr_phys = res->start + SSPDR;
espi->regs_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(espi->regs_base)) {
error = PTR_ERR(espi->regs_base);
goto fail_put_clock;
}
error = devm_request_irq(&pdev->dev, irq, ep93xx_spi_interrupt,
0, "ep93xx-spi", espi);
if (error) {
dev_err(&pdev->dev, "failed to request irq\n");
goto fail_put_clock;
}
if (info->use_dma && ep93xx_spi_setup_dma(espi))
dev_warn(&pdev->dev, "DMA setup failed. Falling back to PIO\n");
espi->wq = create_singlethread_workqueue("ep93xx_spid");
if (!espi->wq) {
dev_err(&pdev->dev, "unable to create workqueue\n");
error = -ENOMEM;
goto fail_free_dma;
}
INIT_WORK(&espi->msg_work, ep93xx_spi_work);
INIT_LIST_HEAD(&espi->msg_queue);
espi->running = true;
ep93xx_spi_write_u8(espi, SSPCR1, 0);
error = spi_register_master(master);
if (error) {
dev_err(&pdev->dev, "failed to register SPI master\n");
goto fail_free_queue;
}
dev_info(&pdev->dev, "EP93xx SPI Controller at 0x%08lx irq %d\n",
(unsigned long)res->start, irq);
return 0;
fail_free_queue:
destroy_workqueue(espi->wq);
fail_free_dma:
ep93xx_spi_release_dma(espi);
fail_put_clock:
clk_put(espi->clk);
fail_release_master:
spi_master_put(master);
return error;
}
static int ep93xx_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct ep93xx_spi *espi = spi_master_get_devdata(master);
spin_lock_irq(&espi->lock);
espi->running = false;
spin_unlock_irq(&espi->lock);
destroy_workqueue(espi->wq);
spin_lock_irq(&espi->lock);
while (!list_empty(&espi->msg_queue)) {
struct spi_message *msg;
msg = list_first_entry(&espi->msg_queue,
struct spi_message, queue);
list_del_init(&msg->queue);
msg->status = -ESHUTDOWN;
spin_unlock_irq(&espi->lock);
msg->complete(msg->context);
spin_lock_irq(&espi->lock);
}
spin_unlock_irq(&espi->lock);
ep93xx_spi_release_dma(espi);
clk_put(espi->clk);
spi_unregister_master(master);
return 0;
}
