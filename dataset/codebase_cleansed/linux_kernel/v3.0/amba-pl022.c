static void null_cs_control(u32 command)
{
pr_debug("pl022: dummy chip select control, CS=0x%x\n", command);
}
static void giveback(struct pl022 *pl022)
{
struct spi_transfer *last_transfer;
unsigned long flags;
struct spi_message *msg;
void (*curr_cs_control) (u32 command);
curr_cs_control = pl022->cur_chip->cs_control;
spin_lock_irqsave(&pl022->queue_lock, flags);
msg = pl022->cur_msg;
pl022->cur_msg = NULL;
pl022->cur_transfer = NULL;
pl022->cur_chip = NULL;
queue_work(pl022->workqueue, &pl022->pump_messages);
spin_unlock_irqrestore(&pl022->queue_lock, flags);
last_transfer = list_entry(msg->transfers.prev,
struct spi_transfer,
transfer_list);
if (last_transfer->delay_usecs)
udelay(last_transfer->delay_usecs);
if (!last_transfer->cs_change)
curr_cs_control(SSP_CHIP_DESELECT);
else {
struct spi_message *next_msg;
spin_lock_irqsave(&pl022->queue_lock, flags);
if (list_empty(&pl022->queue))
next_msg = NULL;
else
next_msg = list_entry(pl022->queue.next,
struct spi_message, queue);
spin_unlock_irqrestore(&pl022->queue_lock, flags);
if (next_msg && next_msg->spi != msg->spi)
next_msg = NULL;
if (!next_msg || msg->state == STATE_ERROR)
curr_cs_control(SSP_CHIP_DESELECT);
}
msg->state = NULL;
if (msg->complete)
msg->complete(msg->context);
clk_disable(pl022->clk);
amba_pclk_disable(pl022->adev);
amba_vcore_disable(pl022->adev);
}
static int flush(struct pl022 *pl022)
{
unsigned long limit = loops_per_jiffy << 1;
dev_dbg(&pl022->adev->dev, "flush\n");
do {
while (readw(SSP_SR(pl022->virtbase)) & SSP_SR_MASK_RNE)
readw(SSP_DR(pl022->virtbase));
} while ((readw(SSP_SR(pl022->virtbase)) & SSP_SR_MASK_BSY) && limit--);
pl022->exp_fifo_level = 0;
return limit;
}
static void restore_state(struct pl022 *pl022)
{
struct chip_data *chip = pl022->cur_chip;
if (pl022->vendor->extended_cr)
writel(chip->cr0, SSP_CR0(pl022->virtbase));
else
writew(chip->cr0, SSP_CR0(pl022->virtbase));
writew(chip->cr1, SSP_CR1(pl022->virtbase));
writew(chip->dmacr, SSP_DMACR(pl022->virtbase));
writew(chip->cpsr, SSP_CPSR(pl022->virtbase));
writew(DISABLE_ALL_INTERRUPTS, SSP_IMSC(pl022->virtbase));
writew(CLEAR_ALL_INTERRUPTS, SSP_ICR(pl022->virtbase));
}
static void load_ssp_default_config(struct pl022 *pl022)
{
if (pl022->vendor->pl023) {
writel(DEFAULT_SSP_REG_CR0_ST_PL023, SSP_CR0(pl022->virtbase));
writew(DEFAULT_SSP_REG_CR1_ST_PL023, SSP_CR1(pl022->virtbase));
} else if (pl022->vendor->extended_cr) {
writel(DEFAULT_SSP_REG_CR0_ST, SSP_CR0(pl022->virtbase));
writew(DEFAULT_SSP_REG_CR1_ST, SSP_CR1(pl022->virtbase));
} else {
writew(DEFAULT_SSP_REG_CR0, SSP_CR0(pl022->virtbase));
writew(DEFAULT_SSP_REG_CR1, SSP_CR1(pl022->virtbase));
}
writew(DEFAULT_SSP_REG_DMACR, SSP_DMACR(pl022->virtbase));
writew(DEFAULT_SSP_REG_CPSR, SSP_CPSR(pl022->virtbase));
writew(DISABLE_ALL_INTERRUPTS, SSP_IMSC(pl022->virtbase));
writew(CLEAR_ALL_INTERRUPTS, SSP_ICR(pl022->virtbase));
}
static void readwriter(struct pl022 *pl022)
{
dev_dbg(&pl022->adev->dev,
"%s, rx: %p, rxend: %p, tx: %p, txend: %p\n",
__func__, pl022->rx, pl022->rx_end, pl022->tx, pl022->tx_end);
while ((readw(SSP_SR(pl022->virtbase)) & SSP_SR_MASK_RNE)
&& (pl022->rx < pl022->rx_end)) {
switch (pl022->read) {
case READING_NULL:
readw(SSP_DR(pl022->virtbase));
break;
case READING_U8:
*(u8 *) (pl022->rx) =
readw(SSP_DR(pl022->virtbase)) & 0xFFU;
break;
case READING_U16:
*(u16 *) (pl022->rx) =
(u16) readw(SSP_DR(pl022->virtbase));
break;
case READING_U32:
*(u32 *) (pl022->rx) =
readl(SSP_DR(pl022->virtbase));
break;
}
pl022->rx += (pl022->cur_chip->n_bytes);
pl022->exp_fifo_level--;
}
while ((pl022->exp_fifo_level < pl022->vendor->fifodepth)
&& (pl022->tx < pl022->tx_end)) {
switch (pl022->write) {
case WRITING_NULL:
writew(0x0, SSP_DR(pl022->virtbase));
break;
case WRITING_U8:
writew(*(u8 *) (pl022->tx), SSP_DR(pl022->virtbase));
break;
case WRITING_U16:
writew((*(u16 *) (pl022->tx)), SSP_DR(pl022->virtbase));
break;
case WRITING_U32:
writel(*(u32 *) (pl022->tx), SSP_DR(pl022->virtbase));
break;
}
pl022->tx += (pl022->cur_chip->n_bytes);
pl022->exp_fifo_level++;
while ((readw(SSP_SR(pl022->virtbase)) & SSP_SR_MASK_RNE)
&& (pl022->rx < pl022->rx_end)) {
switch (pl022->read) {
case READING_NULL:
readw(SSP_DR(pl022->virtbase));
break;
case READING_U8:
*(u8 *) (pl022->rx) =
readw(SSP_DR(pl022->virtbase)) & 0xFFU;
break;
case READING_U16:
*(u16 *) (pl022->rx) =
(u16) readw(SSP_DR(pl022->virtbase));
break;
case READING_U32:
*(u32 *) (pl022->rx) =
readl(SSP_DR(pl022->virtbase));
break;
}
pl022->rx += (pl022->cur_chip->n_bytes);
pl022->exp_fifo_level--;
}
}
}
static void *next_transfer(struct pl022 *pl022)
{
struct spi_message *msg = pl022->cur_msg;
struct spi_transfer *trans = pl022->cur_transfer;
if (trans->transfer_list.next != &msg->transfers) {
pl022->cur_transfer =
list_entry(trans->transfer_list.next,
struct spi_transfer, transfer_list);
return STATE_RUNNING;
}
return STATE_DONE;
}
static void unmap_free_dma_scatter(struct pl022 *pl022)
{
dma_unmap_sg(pl022->dma_tx_channel->device->dev, pl022->sgt_tx.sgl,
pl022->sgt_tx.nents, DMA_TO_DEVICE);
dma_unmap_sg(pl022->dma_rx_channel->device->dev, pl022->sgt_rx.sgl,
pl022->sgt_rx.nents, DMA_FROM_DEVICE);
sg_free_table(&pl022->sgt_rx);
sg_free_table(&pl022->sgt_tx);
}
static void dma_callback(void *data)
{
struct pl022 *pl022 = data;
struct spi_message *msg = pl022->cur_msg;
BUG_ON(!pl022->sgt_rx.sgl);
#ifdef VERBOSE_DEBUG
{
struct scatterlist *sg;
unsigned int i;
dma_sync_sg_for_cpu(&pl022->adev->dev,
pl022->sgt_rx.sgl,
pl022->sgt_rx.nents,
DMA_FROM_DEVICE);
for_each_sg(pl022->sgt_rx.sgl, sg, pl022->sgt_rx.nents, i) {
dev_dbg(&pl022->adev->dev, "SPI RX SG ENTRY: %d", i);
print_hex_dump(KERN_ERR, "SPI RX: ",
DUMP_PREFIX_OFFSET,
16,
1,
sg_virt(sg),
sg_dma_len(sg),
1);
}
for_each_sg(pl022->sgt_tx.sgl, sg, pl022->sgt_tx.nents, i) {
dev_dbg(&pl022->adev->dev, "SPI TX SG ENTRY: %d", i);
print_hex_dump(KERN_ERR, "SPI TX: ",
DUMP_PREFIX_OFFSET,
16,
1,
sg_virt(sg),
sg_dma_len(sg),
1);
}
}
#endif
unmap_free_dma_scatter(pl022);
msg->actual_length += pl022->cur_transfer->len;
if (pl022->cur_transfer->cs_change)
pl022->cur_chip->
cs_control(SSP_CHIP_DESELECT);
msg->state = next_transfer(pl022);
tasklet_schedule(&pl022->pump_transfers);
}
static void setup_dma_scatter(struct pl022 *pl022,
void *buffer,
unsigned int length,
struct sg_table *sgtab)
{
struct scatterlist *sg;
int bytesleft = length;
void *bufp = buffer;
int mapbytes;
int i;
if (buffer) {
for_each_sg(sgtab->sgl, sg, sgtab->nents, i) {
if (bytesleft < (PAGE_SIZE - offset_in_page(bufp)))
mapbytes = bytesleft;
else
mapbytes = PAGE_SIZE - offset_in_page(bufp);
sg_set_page(sg, virt_to_page(bufp),
mapbytes, offset_in_page(bufp));
bufp += mapbytes;
bytesleft -= mapbytes;
dev_dbg(&pl022->adev->dev,
"set RX/TX target page @ %p, %d bytes, %d left\n",
bufp, mapbytes, bytesleft);
}
} else {
for_each_sg(sgtab->sgl, sg, sgtab->nents, i) {
if (bytesleft < PAGE_SIZE)
mapbytes = bytesleft;
else
mapbytes = PAGE_SIZE;
sg_set_page(sg, virt_to_page(pl022->dummypage),
mapbytes, 0);
bytesleft -= mapbytes;
dev_dbg(&pl022->adev->dev,
"set RX/TX to dummy page %d bytes, %d left\n",
mapbytes, bytesleft);
}
}
BUG_ON(bytesleft);
}
static int configure_dma(struct pl022 *pl022)
{
struct dma_slave_config rx_conf = {
.src_addr = SSP_DR(pl022->phybase),
.direction = DMA_FROM_DEVICE,
.src_maxburst = pl022->vendor->fifodepth >> 1,
};
struct dma_slave_config tx_conf = {
.dst_addr = SSP_DR(pl022->phybase),
.direction = DMA_TO_DEVICE,
.dst_maxburst = pl022->vendor->fifodepth >> 1,
};
unsigned int pages;
int ret;
int rx_sglen, tx_sglen;
struct dma_chan *rxchan = pl022->dma_rx_channel;
struct dma_chan *txchan = pl022->dma_tx_channel;
struct dma_async_tx_descriptor *rxdesc;
struct dma_async_tx_descriptor *txdesc;
if (!rxchan || !txchan)
return -ENODEV;
switch (pl022->read) {
case READING_NULL:
rx_conf.src_addr_width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
break;
case READING_U8:
rx_conf.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
break;
case READING_U16:
rx_conf.src_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
break;
case READING_U32:
rx_conf.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
break;
}
switch (pl022->write) {
case WRITING_NULL:
tx_conf.dst_addr_width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
break;
case WRITING_U8:
tx_conf.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
break;
case WRITING_U16:
tx_conf.dst_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
break;
case WRITING_U32:
tx_conf.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
break;
}
if (rx_conf.src_addr_width == DMA_SLAVE_BUSWIDTH_UNDEFINED)
rx_conf.src_addr_width = tx_conf.dst_addr_width;
if (tx_conf.dst_addr_width == DMA_SLAVE_BUSWIDTH_UNDEFINED)
tx_conf.dst_addr_width = rx_conf.src_addr_width;
BUG_ON(rx_conf.src_addr_width != tx_conf.dst_addr_width);
dmaengine_slave_config(rxchan, &rx_conf);
dmaengine_slave_config(txchan, &tx_conf);
pages = (pl022->cur_transfer->len >> PAGE_SHIFT) + 1;
dev_dbg(&pl022->adev->dev, "using %d pages for transfer\n", pages);
ret = sg_alloc_table(&pl022->sgt_rx, pages, GFP_KERNEL);
if (ret)
goto err_alloc_rx_sg;
ret = sg_alloc_table(&pl022->sgt_tx, pages, GFP_KERNEL);
if (ret)
goto err_alloc_tx_sg;
setup_dma_scatter(pl022, pl022->rx,
pl022->cur_transfer->len, &pl022->sgt_rx);
setup_dma_scatter(pl022, pl022->tx,
pl022->cur_transfer->len, &pl022->sgt_tx);
rx_sglen = dma_map_sg(rxchan->device->dev, pl022->sgt_rx.sgl,
pl022->sgt_rx.nents, DMA_FROM_DEVICE);
if (!rx_sglen)
goto err_rx_sgmap;
tx_sglen = dma_map_sg(txchan->device->dev, pl022->sgt_tx.sgl,
pl022->sgt_tx.nents, DMA_TO_DEVICE);
if (!tx_sglen)
goto err_tx_sgmap;
rxdesc = rxchan->device->device_prep_slave_sg(rxchan,
pl022->sgt_rx.sgl,
rx_sglen,
DMA_FROM_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!rxdesc)
goto err_rxdesc;
txdesc = txchan->device->device_prep_slave_sg(txchan,
pl022->sgt_tx.sgl,
tx_sglen,
DMA_TO_DEVICE,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!txdesc)
goto err_txdesc;
rxdesc->callback = dma_callback;
rxdesc->callback_param = pl022;
dmaengine_submit(rxdesc);
dmaengine_submit(txdesc);
dma_async_issue_pending(rxchan);
dma_async_issue_pending(txchan);
return 0;
err_txdesc:
dmaengine_terminate_all(txchan);
err_rxdesc:
dmaengine_terminate_all(rxchan);
dma_unmap_sg(txchan->device->dev, pl022->sgt_tx.sgl,
pl022->sgt_tx.nents, DMA_TO_DEVICE);
err_tx_sgmap:
dma_unmap_sg(rxchan->device->dev, pl022->sgt_rx.sgl,
pl022->sgt_tx.nents, DMA_FROM_DEVICE);
err_rx_sgmap:
sg_free_table(&pl022->sgt_tx);
err_alloc_tx_sg:
sg_free_table(&pl022->sgt_rx);
err_alloc_rx_sg:
return -ENOMEM;
}
static int __init pl022_dma_probe(struct pl022 *pl022)
{
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
pl022->dma_rx_channel = dma_request_channel(mask,
pl022->master_info->dma_filter,
pl022->master_info->dma_rx_param);
if (!pl022->dma_rx_channel) {
dev_dbg(&pl022->adev->dev, "no RX DMA channel!\n");
goto err_no_rxchan;
}
pl022->dma_tx_channel = dma_request_channel(mask,
pl022->master_info->dma_filter,
pl022->master_info->dma_tx_param);
if (!pl022->dma_tx_channel) {
dev_dbg(&pl022->adev->dev, "no TX DMA channel!\n");
goto err_no_txchan;
}
pl022->dummypage = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!pl022->dummypage) {
dev_dbg(&pl022->adev->dev, "no DMA dummypage!\n");
goto err_no_dummypage;
}
dev_info(&pl022->adev->dev, "setup for DMA on RX %s, TX %s\n",
dma_chan_name(pl022->dma_rx_channel),
dma_chan_name(pl022->dma_tx_channel));
return 0;
err_no_dummypage:
dma_release_channel(pl022->dma_tx_channel);
err_no_txchan:
dma_release_channel(pl022->dma_rx_channel);
pl022->dma_rx_channel = NULL;
err_no_rxchan:
dev_err(&pl022->adev->dev,
"Failed to work in dma mode, work without dma!\n");
return -ENODEV;
}
static void terminate_dma(struct pl022 *pl022)
{
struct dma_chan *rxchan = pl022->dma_rx_channel;
struct dma_chan *txchan = pl022->dma_tx_channel;
dmaengine_terminate_all(rxchan);
dmaengine_terminate_all(txchan);
unmap_free_dma_scatter(pl022);
}
static void pl022_dma_remove(struct pl022 *pl022)
{
if (pl022->busy)
terminate_dma(pl022);
if (pl022->dma_tx_channel)
dma_release_channel(pl022->dma_tx_channel);
if (pl022->dma_rx_channel)
dma_release_channel(pl022->dma_rx_channel);
kfree(pl022->dummypage);
}
static inline int configure_dma(struct pl022 *pl022)
{
return -ENODEV;
}
static inline int pl022_dma_probe(struct pl022 *pl022)
{
return 0;
}
static inline void pl022_dma_remove(struct pl022 *pl022)
{
}
static irqreturn_t pl022_interrupt_handler(int irq, void *dev_id)
{
struct pl022 *pl022 = dev_id;
struct spi_message *msg = pl022->cur_msg;
u16 irq_status = 0;
u16 flag = 0;
if (unlikely(!msg)) {
dev_err(&pl022->adev->dev,
"bad message state in interrupt handler");
return IRQ_HANDLED;
}
irq_status = readw(SSP_MIS(pl022->virtbase));
if (unlikely(!irq_status))
return IRQ_NONE;
if (unlikely(irq_status & SSP_MIS_MASK_RORMIS)) {
dev_err(&pl022->adev->dev, "FIFO overrun\n");
if (readw(SSP_SR(pl022->virtbase)) & SSP_SR_MASK_RFF)
dev_err(&pl022->adev->dev,
"RXFIFO is full\n");
if (readw(SSP_SR(pl022->virtbase)) & SSP_SR_MASK_TNF)
dev_err(&pl022->adev->dev,
"TXFIFO is full\n");
writew(DISABLE_ALL_INTERRUPTS,
SSP_IMSC(pl022->virtbase));
writew(CLEAR_ALL_INTERRUPTS, SSP_ICR(pl022->virtbase));
writew((readw(SSP_CR1(pl022->virtbase)) &
(~SSP_CR1_MASK_SSE)), SSP_CR1(pl022->virtbase));
msg->state = STATE_ERROR;
tasklet_schedule(&pl022->pump_transfers);
return IRQ_HANDLED;
}
readwriter(pl022);
if ((pl022->tx == pl022->tx_end) && (flag == 0)) {
flag = 1;
writew(readw(SSP_IMSC(pl022->virtbase)) &
(~SSP_IMSC_MASK_TXIM),
SSP_IMSC(pl022->virtbase));
}
if (pl022->rx >= pl022->rx_end) {
writew(DISABLE_ALL_INTERRUPTS,
SSP_IMSC(pl022->virtbase));
writew(CLEAR_ALL_INTERRUPTS, SSP_ICR(pl022->virtbase));
if (unlikely(pl022->rx > pl022->rx_end)) {
dev_warn(&pl022->adev->dev, "read %u surplus "
"bytes (did you request an odd "
"number of bytes on a 16bit bus?)\n",
(u32) (pl022->rx - pl022->rx_end));
}
msg->actual_length += pl022->cur_transfer->len;
if (pl022->cur_transfer->cs_change)
pl022->cur_chip->
cs_control(SSP_CHIP_DESELECT);
msg->state = next_transfer(pl022);
tasklet_schedule(&pl022->pump_transfers);
return IRQ_HANDLED;
}
return IRQ_HANDLED;
}
static int set_up_next_transfer(struct pl022 *pl022,
struct spi_transfer *transfer)
{
int residue;
residue = pl022->cur_transfer->len % pl022->cur_chip->n_bytes;
if (unlikely(residue != 0)) {
dev_err(&pl022->adev->dev,
"message of %u bytes to transmit but the current "
"chip bus has a data width of %u bytes!\n",
pl022->cur_transfer->len,
pl022->cur_chip->n_bytes);
dev_err(&pl022->adev->dev, "skipping this message\n");
return -EIO;
}
pl022->tx = (void *)transfer->tx_buf;
pl022->tx_end = pl022->tx + pl022->cur_transfer->len;
pl022->rx = (void *)transfer->rx_buf;
pl022->rx_end = pl022->rx + pl022->cur_transfer->len;
pl022->write =
pl022->tx ? pl022->cur_chip->write : WRITING_NULL;
pl022->read = pl022->rx ? pl022->cur_chip->read : READING_NULL;
return 0;
}
static void pump_transfers(unsigned long data)
{
struct pl022 *pl022 = (struct pl022 *) data;
struct spi_message *message = NULL;
struct spi_transfer *transfer = NULL;
struct spi_transfer *previous = NULL;
message = pl022->cur_msg;
transfer = pl022->cur_transfer;
if (message->state == STATE_ERROR) {
message->status = -EIO;
giveback(pl022);
return;
}
if (message->state == STATE_DONE) {
message->status = 0;
giveback(pl022);
return;
}
if (message->state == STATE_RUNNING) {
previous = list_entry(transfer->transfer_list.prev,
struct spi_transfer,
transfer_list);
if (previous->delay_usecs)
udelay(previous->delay_usecs);
if (previous->cs_change)
pl022->cur_chip->cs_control(SSP_CHIP_SELECT);
} else {
message->state = STATE_RUNNING;
}
if (set_up_next_transfer(pl022, transfer)) {
message->state = STATE_ERROR;
message->status = -EIO;
giveback(pl022);
return;
}
flush(pl022);
if (pl022->cur_chip->enable_dma) {
if (configure_dma(pl022)) {
dev_dbg(&pl022->adev->dev,
"configuration of DMA failed, fall back to interrupt mode\n");
goto err_config_dma;
}
return;
}
err_config_dma:
writew(ENABLE_ALL_INTERRUPTS, SSP_IMSC(pl022->virtbase));
}
static void do_interrupt_dma_transfer(struct pl022 *pl022)
{
u32 irqflags = ENABLE_ALL_INTERRUPTS;
pl022->cur_chip->cs_control(SSP_CHIP_SELECT);
if (set_up_next_transfer(pl022, pl022->cur_transfer)) {
pl022->cur_msg->state = STATE_ERROR;
pl022->cur_msg->status = -EIO;
giveback(pl022);
return;
}
if (pl022->cur_chip->enable_dma) {
if (configure_dma(pl022)) {
dev_dbg(&pl022->adev->dev,
"configuration of DMA failed, fall back to interrupt mode\n");
goto err_config_dma;
}
irqflags = DISABLE_ALL_INTERRUPTS;
}
err_config_dma:
writew((readw(SSP_CR1(pl022->virtbase)) | SSP_CR1_MASK_SSE),
SSP_CR1(pl022->virtbase));
writew(irqflags, SSP_IMSC(pl022->virtbase));
}
static void do_polling_transfer(struct pl022 *pl022)
{
struct spi_message *message = NULL;
struct spi_transfer *transfer = NULL;
struct spi_transfer *previous = NULL;
struct chip_data *chip;
unsigned long time, timeout;
chip = pl022->cur_chip;
message = pl022->cur_msg;
while (message->state != STATE_DONE) {
if (message->state == STATE_ERROR)
break;
transfer = pl022->cur_transfer;
if (message->state == STATE_RUNNING) {
previous =
list_entry(transfer->transfer_list.prev,
struct spi_transfer, transfer_list);
if (previous->delay_usecs)
udelay(previous->delay_usecs);
if (previous->cs_change)
pl022->cur_chip->cs_control(SSP_CHIP_SELECT);
} else {
message->state = STATE_RUNNING;
pl022->cur_chip->cs_control(SSP_CHIP_SELECT);
}
if (set_up_next_transfer(pl022, transfer)) {
message->state = STATE_ERROR;
break;
}
flush(pl022);
writew((readw(SSP_CR1(pl022->virtbase)) | SSP_CR1_MASK_SSE),
SSP_CR1(pl022->virtbase));
dev_dbg(&pl022->adev->dev, "polling transfer ongoing ...\n");
timeout = jiffies + msecs_to_jiffies(SPI_POLLING_TIMEOUT);
while (pl022->tx < pl022->tx_end || pl022->rx < pl022->rx_end) {
time = jiffies;
readwriter(pl022);
if (time_after(time, timeout)) {
dev_warn(&pl022->adev->dev,
"%s: timeout!\n", __func__);
message->state = STATE_ERROR;
goto out;
}
cpu_relax();
}
message->actual_length += pl022->cur_transfer->len;
if (pl022->cur_transfer->cs_change)
pl022->cur_chip->cs_control(SSP_CHIP_DESELECT);
message->state = next_transfer(pl022);
}
out:
if (message->state == STATE_DONE)
message->status = 0;
else
message->status = -EIO;
giveback(pl022);
return;
}
static void pump_messages(struct work_struct *work)
{
struct pl022 *pl022 =
container_of(work, struct pl022, pump_messages);
unsigned long flags;
spin_lock_irqsave(&pl022->queue_lock, flags);
if (list_empty(&pl022->queue) || !pl022->running) {
pl022->busy = false;
spin_unlock_irqrestore(&pl022->queue_lock, flags);
return;
}
if (pl022->cur_msg) {
spin_unlock_irqrestore(&pl022->queue_lock, flags);
return;
}
pl022->cur_msg =
list_entry(pl022->queue.next, struct spi_message, queue);
list_del_init(&pl022->cur_msg->queue);
pl022->busy = true;
spin_unlock_irqrestore(&pl022->queue_lock, flags);
pl022->cur_msg->state = STATE_START;
pl022->cur_transfer = list_entry(pl022->cur_msg->transfers.next,
struct spi_transfer,
transfer_list);
pl022->cur_chip = spi_get_ctldata(pl022->cur_msg->spi);
amba_vcore_enable(pl022->adev);
amba_pclk_enable(pl022->adev);
clk_enable(pl022->clk);
restore_state(pl022);
flush(pl022);
if (pl022->cur_chip->xfer_type == POLLING_TRANSFER)
do_polling_transfer(pl022);
else
do_interrupt_dma_transfer(pl022);
}
static int __init init_queue(struct pl022 *pl022)
{
INIT_LIST_HEAD(&pl022->queue);
spin_lock_init(&pl022->queue_lock);
pl022->running = false;
pl022->busy = false;
tasklet_init(&pl022->pump_transfers,
pump_transfers, (unsigned long)pl022);
INIT_WORK(&pl022->pump_messages, pump_messages);
pl022->workqueue = create_singlethread_workqueue(
dev_name(pl022->master->dev.parent));
if (pl022->workqueue == NULL)
return -EBUSY;
return 0;
}
static int start_queue(struct pl022 *pl022)
{
unsigned long flags;
spin_lock_irqsave(&pl022->queue_lock, flags);
if (pl022->running || pl022->busy) {
spin_unlock_irqrestore(&pl022->queue_lock, flags);
return -EBUSY;
}
pl022->running = true;
pl022->cur_msg = NULL;
pl022->cur_transfer = NULL;
pl022->cur_chip = NULL;
spin_unlock_irqrestore(&pl022->queue_lock, flags);
queue_work(pl022->workqueue, &pl022->pump_messages);
return 0;
}
static int stop_queue(struct pl022 *pl022)
{
unsigned long flags;
unsigned limit = 500;
int status = 0;
spin_lock_irqsave(&pl022->queue_lock, flags);
while ((!list_empty(&pl022->queue) || pl022->busy) && limit--) {
spin_unlock_irqrestore(&pl022->queue_lock, flags);
msleep(10);
spin_lock_irqsave(&pl022->queue_lock, flags);
}
if (!list_empty(&pl022->queue) || pl022->busy)
status = -EBUSY;
else
pl022->running = false;
spin_unlock_irqrestore(&pl022->queue_lock, flags);
return status;
}
static int destroy_queue(struct pl022 *pl022)
{
int status;
status = stop_queue(pl022);
if (status != 0)
return status;
destroy_workqueue(pl022->workqueue);
return 0;
}
static int verify_controller_parameters(struct pl022 *pl022,
struct pl022_config_chip const *chip_info)
{
if ((chip_info->iface < SSP_INTERFACE_MOTOROLA_SPI)
|| (chip_info->iface > SSP_INTERFACE_UNIDIRECTIONAL)) {
dev_err(&pl022->adev->dev,
"interface is configured incorrectly\n");
return -EINVAL;
}
if ((chip_info->iface == SSP_INTERFACE_UNIDIRECTIONAL) &&
(!pl022->vendor->unidir)) {
dev_err(&pl022->adev->dev,
"unidirectional mode not supported in this "
"hardware version\n");
return -EINVAL;
}
if ((chip_info->hierarchy != SSP_MASTER)
&& (chip_info->hierarchy != SSP_SLAVE)) {
dev_err(&pl022->adev->dev,
"hierarchy is configured incorrectly\n");
return -EINVAL;
}
if ((chip_info->com_mode != INTERRUPT_TRANSFER)
&& (chip_info->com_mode != DMA_TRANSFER)
&& (chip_info->com_mode != POLLING_TRANSFER)) {
dev_err(&pl022->adev->dev,
"Communication mode is configured incorrectly\n");
return -EINVAL;
}
if ((chip_info->rx_lev_trig < SSP_RX_1_OR_MORE_ELEM)
|| (chip_info->rx_lev_trig > SSP_RX_32_OR_MORE_ELEM)) {
dev_err(&pl022->adev->dev,
"RX FIFO Trigger Level is configured incorrectly\n");
return -EINVAL;
}
if ((chip_info->tx_lev_trig < SSP_TX_1_OR_MORE_EMPTY_LOC)
|| (chip_info->tx_lev_trig > SSP_TX_32_OR_MORE_EMPTY_LOC)) {
dev_err(&pl022->adev->dev,
"TX FIFO Trigger Level is configured incorrectly\n");
return -EINVAL;
}
if (chip_info->iface == SSP_INTERFACE_NATIONAL_MICROWIRE) {
if ((chip_info->ctrl_len < SSP_BITS_4)
|| (chip_info->ctrl_len > SSP_BITS_32)) {
dev_err(&pl022->adev->dev,
"CTRL LEN is configured incorrectly\n");
return -EINVAL;
}
if ((chip_info->wait_state != SSP_MWIRE_WAIT_ZERO)
&& (chip_info->wait_state != SSP_MWIRE_WAIT_ONE)) {
dev_err(&pl022->adev->dev,
"Wait State is configured incorrectly\n");
return -EINVAL;
}
if (pl022->vendor->extended_cr) {
if ((chip_info->duplex !=
SSP_MICROWIRE_CHANNEL_FULL_DUPLEX)
&& (chip_info->duplex !=
SSP_MICROWIRE_CHANNEL_HALF_DUPLEX)) {
dev_err(&pl022->adev->dev,
"Microwire duplex mode is configured incorrectly\n");
return -EINVAL;
}
} else {
if (chip_info->duplex != SSP_MICROWIRE_CHANNEL_FULL_DUPLEX)
dev_err(&pl022->adev->dev,
"Microwire half duplex mode requested,"
" but this is only available in the"
" ST version of PL022\n");
return -EINVAL;
}
}
return 0;
}
static int pl022_transfer(struct spi_device *spi, struct spi_message *msg)
{
struct pl022 *pl022 = spi_master_get_devdata(spi->master);
unsigned long flags;
spin_lock_irqsave(&pl022->queue_lock, flags);
if (!pl022->running) {
spin_unlock_irqrestore(&pl022->queue_lock, flags);
return -ESHUTDOWN;
}
msg->actual_length = 0;
msg->status = -EINPROGRESS;
msg->state = STATE_START;
list_add_tail(&msg->queue, &pl022->queue);
if (pl022->running && !pl022->busy)
queue_work(pl022->workqueue, &pl022->pump_messages);
spin_unlock_irqrestore(&pl022->queue_lock, flags);
return 0;
}
static int calculate_effective_freq(struct pl022 *pl022,
int freq,
struct ssp_clock_params *clk_freq)
{
u16 cpsdvsr = 2;
u16 scr = 0;
bool freq_found = false;
u32 rate;
u32 max_tclk;
u32 min_tclk;
rate = clk_get_rate(pl022->clk);
max_tclk = (rate / (CPSDVR_MIN * (1 + SCR_MIN)));
min_tclk = (rate / (CPSDVR_MAX * (1 + SCR_MAX)));
if ((freq <= max_tclk) && (freq >= min_tclk)) {
while (cpsdvsr <= CPSDVR_MAX && !freq_found) {
while (scr <= SCR_MAX && !freq_found) {
if ((rate /
(cpsdvsr * (1 + scr))) > freq)
scr += 1;
else {
freq_found = true;
if ((rate /
(cpsdvsr * (1 + scr))) != freq) {
if (scr == SCR_MIN) {
cpsdvsr -= 2;
scr = SCR_MAX;
} else
scr -= 1;
}
}
}
if (!freq_found) {
cpsdvsr += 2;
scr = SCR_MIN;
}
}
if (cpsdvsr != 0) {
dev_dbg(&pl022->adev->dev,
"SSP Effective Frequency is %u\n",
(rate / (cpsdvsr * (1 + scr))));
clk_freq->cpsdvsr = (u8) (cpsdvsr & 0xFF);
clk_freq->scr = (u8) (scr & 0xFF);
dev_dbg(&pl022->adev->dev,
"SSP cpsdvsr = %d, scr = %d\n",
clk_freq->cpsdvsr, clk_freq->scr);
}
} else {
dev_err(&pl022->adev->dev,
"controller data is incorrect: out of range frequency");
return -EINVAL;
}
return 0;
}
static int pl022_setup(struct spi_device *spi)
{
struct pl022_config_chip const *chip_info;
struct chip_data *chip;
struct ssp_clock_params clk_freq = {0, };
int status = 0;
struct pl022 *pl022 = spi_master_get_devdata(spi->master);
unsigned int bits = spi->bits_per_word;
u32 tmp;
if (!spi->max_speed_hz)
return -EINVAL;
chip = spi_get_ctldata(spi);
if (chip == NULL) {
chip = kzalloc(sizeof(struct chip_data), GFP_KERNEL);
if (!chip) {
dev_err(&spi->dev,
"cannot allocate controller state\n");
return -ENOMEM;
}
dev_dbg(&spi->dev,
"allocated memory for controller's runtime state\n");
}
chip_info = spi->controller_data;
if (chip_info == NULL) {
chip_info = &pl022_default_chip_info;
dev_dbg(&spi->dev,
"using default controller_data settings\n");
} else
dev_dbg(&spi->dev,
"using user supplied controller_data settings\n");
if ((0 == chip_info->clk_freq.cpsdvsr)
&& (0 == chip_info->clk_freq.scr)) {
status = calculate_effective_freq(pl022,
spi->max_speed_hz,
&clk_freq);
if (status < 0)
goto err_config_params;
} else {
memcpy(&clk_freq, &chip_info->clk_freq, sizeof(clk_freq));
if ((clk_freq.cpsdvsr % 2) != 0)
clk_freq.cpsdvsr =
clk_freq.cpsdvsr - 1;
}
if ((clk_freq.cpsdvsr < CPSDVR_MIN)
|| (clk_freq.cpsdvsr > CPSDVR_MAX)) {
status = -EINVAL;
dev_err(&spi->dev,
"cpsdvsr is configured incorrectly\n");
goto err_config_params;
}
status = verify_controller_parameters(pl022, chip_info);
if (status) {
dev_err(&spi->dev, "controller data is incorrect");
goto err_config_params;
}
chip->xfer_type = chip_info->com_mode;
if (!chip_info->cs_control) {
chip->cs_control = null_cs_control;
dev_warn(&spi->dev,
"chip select function is NULL for this chip\n");
} else
chip->cs_control = chip_info->cs_control;
if (bits <= 3) {
status = -ENOTSUPP;
goto err_config_params;
} else if (bits <= 8) {
dev_dbg(&spi->dev, "4 <= n <=8 bits per word\n");
chip->n_bytes = 1;
chip->read = READING_U8;
chip->write = WRITING_U8;
} else if (bits <= 16) {
dev_dbg(&spi->dev, "9 <= n <= 16 bits per word\n");
chip->n_bytes = 2;
chip->read = READING_U16;
chip->write = WRITING_U16;
} else {
if (pl022->vendor->max_bpw >= 32) {
dev_dbg(&spi->dev, "17 <= n <= 32 bits per word\n");
chip->n_bytes = 4;
chip->read = READING_U32;
chip->write = WRITING_U32;
} else {
dev_err(&spi->dev,
"illegal data size for this controller!\n");
dev_err(&spi->dev,
"a standard pl022 can only handle "
"1 <= n <= 16 bit words\n");
status = -ENOTSUPP;
goto err_config_params;
}
}
chip->cr0 = 0;
chip->cr1 = 0;
chip->dmacr = 0;
chip->cpsr = 0;
if ((chip_info->com_mode == DMA_TRANSFER)
&& ((pl022->master_info)->enable_dma)) {
chip->enable_dma = true;
dev_dbg(&spi->dev, "DMA mode set in controller state\n");
SSP_WRITE_BITS(chip->dmacr, SSP_DMA_ENABLED,
SSP_DMACR_MASK_RXDMAE, 0);
SSP_WRITE_BITS(chip->dmacr, SSP_DMA_ENABLED,
SSP_DMACR_MASK_TXDMAE, 1);
} else {
chip->enable_dma = false;
dev_dbg(&spi->dev, "DMA mode NOT set in controller state\n");
SSP_WRITE_BITS(chip->dmacr, SSP_DMA_DISABLED,
SSP_DMACR_MASK_RXDMAE, 0);
SSP_WRITE_BITS(chip->dmacr, SSP_DMA_DISABLED,
SSP_DMACR_MASK_TXDMAE, 1);
}
chip->cpsr = clk_freq.cpsdvsr;
if (pl022->vendor->extended_cr) {
u32 etx;
if (pl022->vendor->pl023) {
SSP_WRITE_BITS(chip->cr1, chip_info->clkdelay,
SSP_CR1_MASK_FBCLKDEL_ST, 13);
} else {
SSP_WRITE_BITS(chip->cr0, chip_info->duplex,
SSP_CR0_MASK_HALFDUP_ST, 5);
SSP_WRITE_BITS(chip->cr0, chip_info->ctrl_len,
SSP_CR0_MASK_CSS_ST, 16);
SSP_WRITE_BITS(chip->cr0, chip_info->iface,
SSP_CR0_MASK_FRF_ST, 21);
SSP_WRITE_BITS(chip->cr1, chip_info->wait_state,
SSP_CR1_MASK_MWAIT_ST, 6);
}
SSP_WRITE_BITS(chip->cr0, bits - 1,
SSP_CR0_MASK_DSS_ST, 0);
if (spi->mode & SPI_LSB_FIRST) {
tmp = SSP_RX_LSB;
etx = SSP_TX_LSB;
} else {
tmp = SSP_RX_MSB;
etx = SSP_TX_MSB;
}
SSP_WRITE_BITS(chip->cr1, tmp, SSP_CR1_MASK_RENDN_ST, 4);
SSP_WRITE_BITS(chip->cr1, etx, SSP_CR1_MASK_TENDN_ST, 5);
SSP_WRITE_BITS(chip->cr1, chip_info->rx_lev_trig,
SSP_CR1_MASK_RXIFLSEL_ST, 7);
SSP_WRITE_BITS(chip->cr1, chip_info->tx_lev_trig,
SSP_CR1_MASK_TXIFLSEL_ST, 10);
} else {
SSP_WRITE_BITS(chip->cr0, bits - 1,
SSP_CR0_MASK_DSS, 0);
SSP_WRITE_BITS(chip->cr0, chip_info->iface,
SSP_CR0_MASK_FRF, 4);
}
if (spi->mode & SPI_CPOL)
tmp = SSP_CLK_POL_IDLE_HIGH;
else
tmp = SSP_CLK_POL_IDLE_LOW;
SSP_WRITE_BITS(chip->cr0, tmp, SSP_CR0_MASK_SPO, 6);
if (spi->mode & SPI_CPHA)
tmp = SSP_CLK_SECOND_EDGE;
else
tmp = SSP_CLK_FIRST_EDGE;
SSP_WRITE_BITS(chip->cr0, tmp, SSP_CR0_MASK_SPH, 7);
SSP_WRITE_BITS(chip->cr0, clk_freq.scr, SSP_CR0_MASK_SCR, 8);
if (pl022->vendor->loopback) {
if (spi->mode & SPI_LOOP)
tmp = LOOPBACK_ENABLED;
else
tmp = LOOPBACK_DISABLED;
SSP_WRITE_BITS(chip->cr1, tmp, SSP_CR1_MASK_LBM, 0);
}
SSP_WRITE_BITS(chip->cr1, SSP_DISABLED, SSP_CR1_MASK_SSE, 1);
SSP_WRITE_BITS(chip->cr1, chip_info->hierarchy, SSP_CR1_MASK_MS, 2);
SSP_WRITE_BITS(chip->cr1, chip_info->slave_tx_disable, SSP_CR1_MASK_SOD, 3);
spi_set_ctldata(spi, chip);
return status;
err_config_params:
spi_set_ctldata(spi, NULL);
kfree(chip);
return status;
}
static void pl022_cleanup(struct spi_device *spi)
{
struct chip_data *chip = spi_get_ctldata(spi);
spi_set_ctldata(spi, NULL);
kfree(chip);
}
static int __devinit
pl022_probe(struct amba_device *adev, const struct amba_id *id)
{
struct device *dev = &adev->dev;
struct pl022_ssp_controller *platform_info = adev->dev.platform_data;
struct spi_master *master;
struct pl022 *pl022 = NULL;
int status = 0;
dev_info(&adev->dev,
"ARM PL022 driver, device ID: 0x%08x\n", adev->periphid);
if (platform_info == NULL) {
dev_err(&adev->dev, "probe - no platform data supplied\n");
status = -ENODEV;
goto err_no_pdata;
}
master = spi_alloc_master(dev, sizeof(struct pl022));
if (master == NULL) {
dev_err(&adev->dev, "probe - cannot alloc SPI master\n");
status = -ENOMEM;
goto err_no_master;
}
pl022 = spi_master_get_devdata(master);
pl022->master = master;
pl022->master_info = platform_info;
pl022->adev = adev;
pl022->vendor = id->data;
master->bus_num = platform_info->bus_id;
master->num_chipselect = platform_info->num_chipselect;
master->cleanup = pl022_cleanup;
master->setup = pl022_setup;
master->transfer = pl022_transfer;
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LOOP;
if (pl022->vendor->extended_cr)
master->mode_bits |= SPI_LSB_FIRST;
dev_dbg(&adev->dev, "BUSNO: %d\n", master->bus_num);
status = amba_request_regions(adev, NULL);
if (status)
goto err_no_ioregion;
pl022->phybase = adev->res.start;
pl022->virtbase = ioremap(adev->res.start, resource_size(&adev->res));
if (pl022->virtbase == NULL) {
status = -ENOMEM;
goto err_no_ioremap;
}
printk(KERN_INFO "pl022: mapped registers from 0x%08x to %p\n",
adev->res.start, pl022->virtbase);
pl022->clk = clk_get(&adev->dev, NULL);
if (IS_ERR(pl022->clk)) {
status = PTR_ERR(pl022->clk);
dev_err(&adev->dev, "could not retrieve SSP/SPI bus clock\n");
goto err_no_clk;
}
writew((readw(SSP_CR1(pl022->virtbase)) & (~SSP_CR1_MASK_SSE)),
SSP_CR1(pl022->virtbase));
load_ssp_default_config(pl022);
status = request_irq(adev->irq[0], pl022_interrupt_handler, 0, "pl022",
pl022);
if (status < 0) {
dev_err(&adev->dev, "probe - cannot get IRQ (%d)\n", status);
goto err_no_irq;
}
if (platform_info->enable_dma) {
status = pl022_dma_probe(pl022);
if (status != 0)
platform_info->enable_dma = 0;
}
status = init_queue(pl022);
if (status != 0) {
dev_err(&adev->dev, "probe - problem initializing queue\n");
goto err_init_queue;
}
status = start_queue(pl022);
if (status != 0) {
dev_err(&adev->dev, "probe - problem starting queue\n");
goto err_start_queue;
}
amba_set_drvdata(adev, pl022);
status = spi_register_master(master);
if (status != 0) {
dev_err(&adev->dev,
"probe - problem registering spi master\n");
goto err_spi_register;
}
dev_dbg(dev, "probe succeeded\n");
amba_pclk_disable(adev);
amba_vcore_disable(adev);
return 0;
err_spi_register:
err_start_queue:
err_init_queue:
destroy_queue(pl022);
pl022_dma_remove(pl022);
free_irq(adev->irq[0], pl022);
err_no_irq:
clk_put(pl022->clk);
err_no_clk:
iounmap(pl022->virtbase);
err_no_ioremap:
amba_release_regions(adev);
err_no_ioregion:
spi_master_put(master);
err_no_master:
err_no_pdata:
return status;
}
static int __devexit
pl022_remove(struct amba_device *adev)
{
struct pl022 *pl022 = amba_get_drvdata(adev);
int status = 0;
if (!pl022)
return 0;
status = destroy_queue(pl022);
if (status != 0) {
dev_err(&adev->dev,
"queue remove failed (%d)\n", status);
return status;
}
load_ssp_default_config(pl022);
pl022_dma_remove(pl022);
free_irq(adev->irq[0], pl022);
clk_disable(pl022->clk);
clk_put(pl022->clk);
iounmap(pl022->virtbase);
amba_release_regions(adev);
tasklet_disable(&pl022->pump_transfers);
spi_unregister_master(pl022->master);
spi_master_put(pl022->master);
amba_set_drvdata(adev, NULL);
dev_dbg(&adev->dev, "remove succeeded\n");
return 0;
}
static int pl022_suspend(struct amba_device *adev, pm_message_t state)
{
struct pl022 *pl022 = amba_get_drvdata(adev);
int status = 0;
status = stop_queue(pl022);
if (status) {
dev_warn(&adev->dev, "suspend cannot stop queue\n");
return status;
}
amba_vcore_enable(adev);
amba_pclk_enable(adev);
load_ssp_default_config(pl022);
amba_pclk_disable(adev);
amba_vcore_disable(adev);
dev_dbg(&adev->dev, "suspended\n");
return 0;
}
static int pl022_resume(struct amba_device *adev)
{
struct pl022 *pl022 = amba_get_drvdata(adev);
int status = 0;
status = start_queue(pl022);
if (status)
dev_err(&adev->dev, "problem starting queue (%d)\n", status);
else
dev_dbg(&adev->dev, "resumed\n");
return status;
}
static int __init pl022_init(void)
{
return amba_driver_register(&pl022_driver);
}
static void __exit pl022_exit(void)
{
amba_driver_unregister(&pl022_driver);
}
