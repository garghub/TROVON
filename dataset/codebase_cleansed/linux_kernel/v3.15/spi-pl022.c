static void null_cs_control(u32 command)
{
pr_debug("pl022: dummy chip select control, CS=0x%x\n", command);
}
static void pl022_cs_control(struct pl022 *pl022, u32 command)
{
if (gpio_is_valid(pl022->cur_cs))
gpio_set_value(pl022->cur_cs, command);
else
pl022->cur_chip->cs_control(command);
}
static void giveback(struct pl022 *pl022)
{
struct spi_transfer *last_transfer;
pl022->next_msg_cs_active = false;
last_transfer = list_last_entry(&pl022->cur_msg->transfers,
struct spi_transfer, transfer_list);
if (last_transfer->delay_usecs)
udelay(last_transfer->delay_usecs);
if (!last_transfer->cs_change) {
struct spi_message *next_msg;
next_msg = spi_get_next_queued_message(pl022->master);
if (next_msg && next_msg->spi != pl022->cur_msg->spi)
next_msg = NULL;
if (!next_msg || pl022->cur_msg->state == STATE_ERROR)
pl022_cs_control(pl022, SSP_CHIP_DESELECT);
else
pl022->next_msg_cs_active = true;
}
pl022->cur_msg = NULL;
pl022->cur_transfer = NULL;
pl022->cur_chip = NULL;
spi_finalize_current_message(pl022->master);
writew((readw(SSP_CR1(pl022->virtbase)) &
(~SSP_CR1_MASK_SSE)), SSP_CR1(pl022->virtbase));
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
pl022_cs_control(pl022, SSP_CHIP_DESELECT);
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
.direction = DMA_DEV_TO_MEM,
.device_fc = false,
};
struct dma_slave_config tx_conf = {
.dst_addr = SSP_DR(pl022->phybase),
.direction = DMA_MEM_TO_DEV,
.device_fc = false,
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
switch (pl022->rx_lev_trig) {
case SSP_RX_1_OR_MORE_ELEM:
rx_conf.src_maxburst = 1;
break;
case SSP_RX_4_OR_MORE_ELEM:
rx_conf.src_maxburst = 4;
break;
case SSP_RX_8_OR_MORE_ELEM:
rx_conf.src_maxburst = 8;
break;
case SSP_RX_16_OR_MORE_ELEM:
rx_conf.src_maxburst = 16;
break;
case SSP_RX_32_OR_MORE_ELEM:
rx_conf.src_maxburst = 32;
break;
default:
rx_conf.src_maxburst = pl022->vendor->fifodepth >> 1;
break;
}
switch (pl022->tx_lev_trig) {
case SSP_TX_1_OR_MORE_EMPTY_LOC:
tx_conf.dst_maxburst = 1;
break;
case SSP_TX_4_OR_MORE_EMPTY_LOC:
tx_conf.dst_maxburst = 4;
break;
case SSP_TX_8_OR_MORE_EMPTY_LOC:
tx_conf.dst_maxburst = 8;
break;
case SSP_TX_16_OR_MORE_EMPTY_LOC:
tx_conf.dst_maxburst = 16;
break;
case SSP_TX_32_OR_MORE_EMPTY_LOC:
tx_conf.dst_maxburst = 32;
break;
default:
tx_conf.dst_maxburst = pl022->vendor->fifodepth >> 1;
break;
}
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
pages = DIV_ROUND_UP(pl022->cur_transfer->len, PAGE_SIZE);
dev_dbg(&pl022->adev->dev, "using %d pages for transfer\n", pages);
ret = sg_alloc_table(&pl022->sgt_rx, pages, GFP_ATOMIC);
if (ret)
goto err_alloc_rx_sg;
ret = sg_alloc_table(&pl022->sgt_tx, pages, GFP_ATOMIC);
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
rxdesc = dmaengine_prep_slave_sg(rxchan,
pl022->sgt_rx.sgl,
rx_sglen,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!rxdesc)
goto err_rxdesc;
txdesc = dmaengine_prep_slave_sg(txchan,
pl022->sgt_tx.sgl,
tx_sglen,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!txdesc)
goto err_txdesc;
rxdesc->callback = dma_callback;
rxdesc->callback_param = pl022;
dmaengine_submit(rxdesc);
dmaengine_submit(txdesc);
dma_async_issue_pending(rxchan);
dma_async_issue_pending(txchan);
pl022->dma_running = true;
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
static int pl022_dma_probe(struct pl022 *pl022)
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
static int pl022_dma_autoprobe(struct pl022 *pl022)
{
struct device *dev = &pl022->adev->dev;
pl022->dma_rx_channel = dma_request_slave_channel(dev, "rx");
if (!pl022->dma_rx_channel)
goto err_no_rxchan;
pl022->dma_tx_channel = dma_request_slave_channel(dev, "tx");
if (!pl022->dma_tx_channel)
goto err_no_txchan;
pl022->dummypage = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!pl022->dummypage)
goto err_no_dummypage;
return 0;
err_no_dummypage:
dma_release_channel(pl022->dma_tx_channel);
pl022->dma_tx_channel = NULL;
err_no_txchan:
dma_release_channel(pl022->dma_rx_channel);
pl022->dma_rx_channel = NULL;
err_no_rxchan:
return -ENODEV;
}
static void terminate_dma(struct pl022 *pl022)
{
struct dma_chan *rxchan = pl022->dma_rx_channel;
struct dma_chan *txchan = pl022->dma_tx_channel;
dmaengine_terminate_all(rxchan);
dmaengine_terminate_all(txchan);
unmap_free_dma_scatter(pl022);
pl022->dma_running = false;
}
static void pl022_dma_remove(struct pl022 *pl022)
{
if (pl022->dma_running)
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
static inline int pl022_dma_autoprobe(struct pl022 *pl022)
{
return 0;
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
writew((readw(SSP_IMSC(pl022->virtbase)) &
~SSP_IMSC_MASK_TXIM) | SSP_IMSC_MASK_RXIM,
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
pl022_cs_control(pl022, SSP_CHIP_DESELECT);
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
pl022_cs_control(pl022, SSP_CHIP_SELECT);
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
writew(ENABLE_ALL_INTERRUPTS & ~SSP_IMSC_MASK_RXIM, SSP_IMSC(pl022->virtbase));
}
static void do_interrupt_dma_transfer(struct pl022 *pl022)
{
u32 irqflags = ENABLE_ALL_INTERRUPTS & ~SSP_IMSC_MASK_RXIM;
if (!pl022->next_msg_cs_active)
pl022_cs_control(pl022, SSP_CHIP_SELECT);
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
pl022_cs_control(pl022, SSP_CHIP_SELECT);
} else {
message->state = STATE_RUNNING;
if (!pl022->next_msg_cs_active)
pl022_cs_control(pl022, SSP_CHIP_SELECT);
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
pl022_cs_control(pl022, SSP_CHIP_DESELECT);
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
static int pl022_transfer_one_message(struct spi_master *master,
struct spi_message *msg)
{
struct pl022 *pl022 = spi_master_get_devdata(master);
pl022->cur_msg = msg;
msg->state = STATE_START;
pl022->cur_transfer = list_entry(msg->transfers.next,
struct spi_transfer, transfer_list);
pl022->cur_chip = spi_get_ctldata(msg->spi);
pl022->cur_cs = pl022->chipselects[msg->spi->chip_select];
restore_state(pl022);
flush(pl022);
if (pl022->cur_chip->xfer_type == POLLING_TRANSFER)
do_polling_transfer(pl022);
else
do_interrupt_dma_transfer(pl022);
return 0;
}
static int pl022_unprepare_transfer_hardware(struct spi_master *master)
{
struct pl022 *pl022 = spi_master_get_devdata(master);
writew((readw(SSP_CR1(pl022->virtbase)) &
(~SSP_CR1_MASK_SSE)), SSP_CR1(pl022->virtbase));
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
switch (chip_info->rx_lev_trig) {
case SSP_RX_1_OR_MORE_ELEM:
case SSP_RX_4_OR_MORE_ELEM:
case SSP_RX_8_OR_MORE_ELEM:
break;
case SSP_RX_16_OR_MORE_ELEM:
if (pl022->vendor->fifodepth < 16) {
dev_err(&pl022->adev->dev,
"RX FIFO Trigger Level is configured incorrectly\n");
return -EINVAL;
}
break;
case SSP_RX_32_OR_MORE_ELEM:
if (pl022->vendor->fifodepth < 32) {
dev_err(&pl022->adev->dev,
"RX FIFO Trigger Level is configured incorrectly\n");
return -EINVAL;
}
break;
default:
dev_err(&pl022->adev->dev,
"RX FIFO Trigger Level is configured incorrectly\n");
return -EINVAL;
}
switch (chip_info->tx_lev_trig) {
case SSP_TX_1_OR_MORE_EMPTY_LOC:
case SSP_TX_4_OR_MORE_EMPTY_LOC:
case SSP_TX_8_OR_MORE_EMPTY_LOC:
break;
case SSP_TX_16_OR_MORE_EMPTY_LOC:
if (pl022->vendor->fifodepth < 16) {
dev_err(&pl022->adev->dev,
"TX FIFO Trigger Level is configured incorrectly\n");
return -EINVAL;
}
break;
case SSP_TX_32_OR_MORE_EMPTY_LOC:
if (pl022->vendor->fifodepth < 32) {
dev_err(&pl022->adev->dev,
"TX FIFO Trigger Level is configured incorrectly\n");
return -EINVAL;
}
break;
default:
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
static inline u32 spi_rate(u32 rate, u16 cpsdvsr, u16 scr)
{
return rate / (cpsdvsr * (1 + scr));
}
static int calculate_effective_freq(struct pl022 *pl022, int freq, struct
ssp_clock_params * clk_freq)
{
u16 cpsdvsr = CPSDVR_MIN, scr = SCR_MIN;
u32 rate, max_tclk, min_tclk, best_freq = 0, best_cpsdvsr = 0,
best_scr = 0, tmp, found = 0;
rate = clk_get_rate(pl022->clk);
max_tclk = spi_rate(rate, CPSDVR_MIN, SCR_MIN);
min_tclk = spi_rate(rate, CPSDVR_MAX, SCR_MAX);
if (freq > max_tclk)
dev_warn(&pl022->adev->dev,
"Max speed that can be programmed is %d Hz, you requested %d\n",
max_tclk, freq);
if (freq < min_tclk) {
dev_err(&pl022->adev->dev,
"Requested frequency: %d Hz is less than minimum possible %d Hz\n",
freq, min_tclk);
return -EINVAL;
}
while ((cpsdvsr <= CPSDVR_MAX) && !found) {
while (scr <= SCR_MAX) {
tmp = spi_rate(rate, cpsdvsr, scr);
if (tmp > freq) {
scr++;
continue;
}
if (tmp > best_freq) {
best_freq = tmp;
best_cpsdvsr = cpsdvsr;
best_scr = scr;
if (tmp == freq)
found = 1;
}
break;
}
cpsdvsr += 2;
scr = SCR_MIN;
}
WARN(!best_freq, "pl022: Matching cpsdvsr and scr not found for %d Hz rate \n",
freq);
clk_freq->cpsdvsr = (u8) (best_cpsdvsr & 0xFF);
clk_freq->scr = (u8) (best_scr & 0xFF);
dev_dbg(&pl022->adev->dev,
"SSP Target Frequency is: %u, Effective Frequency is %u\n",
freq, best_freq);
dev_dbg(&pl022->adev->dev, "SSP cpsdvsr = %d, scr = %d\n",
clk_freq->cpsdvsr, clk_freq->scr);
return 0;
}
static int pl022_setup(struct spi_device *spi)
{
struct pl022_config_chip const *chip_info;
struct pl022_config_chip chip_info_dt;
struct chip_data *chip;
struct ssp_clock_params clk_freq = { .cpsdvsr = 0, .scr = 0};
int status = 0;
struct pl022 *pl022 = spi_master_get_devdata(spi->master);
unsigned int bits = spi->bits_per_word;
u32 tmp;
struct device_node *np = spi->dev.of_node;
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
if (np) {
chip_info_dt = pl022_default_chip_info;
chip_info_dt.hierarchy = SSP_MASTER;
of_property_read_u32(np, "pl022,interface",
&chip_info_dt.iface);
of_property_read_u32(np, "pl022,com-mode",
&chip_info_dt.com_mode);
of_property_read_u32(np, "pl022,rx-level-trig",
&chip_info_dt.rx_lev_trig);
of_property_read_u32(np, "pl022,tx-level-trig",
&chip_info_dt.tx_lev_trig);
of_property_read_u32(np, "pl022,ctrl-len",
&chip_info_dt.ctrl_len);
of_property_read_u32(np, "pl022,wait-state",
&chip_info_dt.wait_state);
of_property_read_u32(np, "pl022,duplex",
&chip_info_dt.duplex);
chip_info = &chip_info_dt;
} else {
chip_info = &pl022_default_chip_info;
dev_dbg(&spi->dev,
"using default controller_data settings\n");
}
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
pl022->rx_lev_trig = chip_info->rx_lev_trig;
pl022->tx_lev_trig = chip_info->tx_lev_trig;
chip->xfer_type = chip_info->com_mode;
if (!chip_info->cs_control) {
chip->cs_control = null_cs_control;
if (!gpio_is_valid(pl022->chipselects[spi->chip_select]))
dev_warn(&spi->dev,
"invalid chip select\n");
} else
chip->cs_control = chip_info->cs_control;
if ((bits <= 3) || (bits > pl022->vendor->max_bpw)) {
status = -ENOTSUPP;
dev_err(&spi->dev, "illegal data size for this controller!\n");
dev_err(&spi->dev, "This controller can only handle 4 <= n <= %d bit words\n",
pl022->vendor->max_bpw);
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
dev_dbg(&spi->dev, "17 <= n <= 32 bits per word\n");
chip->n_bytes = 4;
chip->read = READING_U32;
chip->write = WRITING_U32;
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
SSP_WRITE_BITS(chip->cr1, chip_info->slave_tx_disable, SSP_CR1_MASK_SOD,
3);
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
static struct pl022_ssp_controller *
pl022_platform_data_dt_get(struct device *dev)
{
struct device_node *np = dev->of_node;
struct pl022_ssp_controller *pd;
u32 tmp;
if (!np) {
dev_err(dev, "no dt node defined\n");
return NULL;
}
pd = devm_kzalloc(dev, sizeof(struct pl022_ssp_controller), GFP_KERNEL);
if (!pd) {
dev_err(dev, "cannot allocate platform data memory\n");
return NULL;
}
pd->bus_id = -1;
pd->enable_dma = 1;
of_property_read_u32(np, "num-cs", &tmp);
pd->num_chipselect = tmp;
of_property_read_u32(np, "pl022,autosuspend-delay",
&pd->autosuspend_delay);
pd->rt = of_property_read_bool(np, "pl022,rt");
return pd;
}
static int pl022_probe(struct amba_device *adev, const struct amba_id *id)
{
struct device *dev = &adev->dev;
struct pl022_ssp_controller *platform_info =
dev_get_platdata(&adev->dev);
struct spi_master *master;
struct pl022 *pl022 = NULL;
struct device_node *np = adev->dev.of_node;
int status = 0, i, num_cs;
dev_info(&adev->dev,
"ARM PL022 driver, device ID: 0x%08x\n", adev->periphid);
if (!platform_info && IS_ENABLED(CONFIG_OF))
platform_info = pl022_platform_data_dt_get(dev);
if (!platform_info) {
dev_err(dev, "probe: no platform data defined\n");
return -ENODEV;
}
if (platform_info->num_chipselect) {
num_cs = platform_info->num_chipselect;
} else {
dev_err(dev, "probe: no chip select defined\n");
return -ENODEV;
}
master = spi_alloc_master(dev, sizeof(struct pl022));
if (master == NULL) {
dev_err(&adev->dev, "probe - cannot alloc SPI master\n");
return -ENOMEM;
}
pl022 = spi_master_get_devdata(master);
pl022->master = master;
pl022->master_info = platform_info;
pl022->adev = adev;
pl022->vendor = id->data;
pl022->chipselects = devm_kzalloc(dev, num_cs * sizeof(int),
GFP_KERNEL);
master->bus_num = platform_info->bus_id;
master->num_chipselect = num_cs;
master->cleanup = pl022_cleanup;
master->setup = pl022_setup;
master->auto_runtime_pm = true;
master->transfer_one_message = pl022_transfer_one_message;
master->unprepare_transfer_hardware = pl022_unprepare_transfer_hardware;
master->rt = platform_info->rt;
master->dev.of_node = dev->of_node;
if (platform_info->num_chipselect && platform_info->chipselects) {
for (i = 0; i < num_cs; i++)
pl022->chipselects[i] = platform_info->chipselects[i];
} else if (IS_ENABLED(CONFIG_OF)) {
for (i = 0; i < num_cs; i++) {
int cs_gpio = of_get_named_gpio(np, "cs-gpios", i);
if (cs_gpio == -EPROBE_DEFER) {
status = -EPROBE_DEFER;
goto err_no_gpio;
}
pl022->chipselects[i] = cs_gpio;
if (gpio_is_valid(cs_gpio)) {
if (devm_gpio_request(dev, cs_gpio, "ssp-pl022"))
dev_err(&adev->dev,
"could not request %d gpio\n",
cs_gpio);
else if (gpio_direction_output(cs_gpio, 1))
dev_err(&adev->dev,
"could set gpio %d as output\n",
cs_gpio);
}
}
}
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH | SPI_LOOP;
if (pl022->vendor->extended_cr)
master->mode_bits |= SPI_LSB_FIRST;
dev_dbg(&adev->dev, "BUSNO: %d\n", master->bus_num);
status = amba_request_regions(adev, NULL);
if (status)
goto err_no_ioregion;
pl022->phybase = adev->res.start;
pl022->virtbase = devm_ioremap(dev, adev->res.start,
resource_size(&adev->res));
if (pl022->virtbase == NULL) {
status = -ENOMEM;
goto err_no_ioremap;
}
dev_info(&adev->dev, "mapped registers from %pa to %p\n",
&adev->res.start, pl022->virtbase);
pl022->clk = devm_clk_get(&adev->dev, NULL);
if (IS_ERR(pl022->clk)) {
status = PTR_ERR(pl022->clk);
dev_err(&adev->dev, "could not retrieve SSP/SPI bus clock\n");
goto err_no_clk;
}
status = clk_prepare_enable(pl022->clk);
if (status) {
dev_err(&adev->dev, "could not enable SSP/SPI bus clock\n");
goto err_no_clk_en;
}
tasklet_init(&pl022->pump_transfers, pump_transfers,
(unsigned long)pl022);
writew((readw(SSP_CR1(pl022->virtbase)) & (~SSP_CR1_MASK_SSE)),
SSP_CR1(pl022->virtbase));
load_ssp_default_config(pl022);
status = devm_request_irq(dev, adev->irq[0], pl022_interrupt_handler,
0, "pl022", pl022);
if (status < 0) {
dev_err(&adev->dev, "probe - cannot get IRQ (%d)\n", status);
goto err_no_irq;
}
status = pl022_dma_autoprobe(pl022);
if (status == 0)
platform_info->enable_dma = 1;
else if (platform_info->enable_dma) {
status = pl022_dma_probe(pl022);
if (status != 0)
platform_info->enable_dma = 0;
}
amba_set_drvdata(adev, pl022);
status = devm_spi_register_master(&adev->dev, master);
if (status != 0) {
dev_err(&adev->dev,
"probe - problem registering spi master\n");
goto err_spi_register;
}
dev_dbg(dev, "probe succeeded\n");
if (platform_info->autosuspend_delay > 0) {
dev_info(&adev->dev,
"will use autosuspend for runtime pm, delay %dms\n",
platform_info->autosuspend_delay);
pm_runtime_set_autosuspend_delay(dev,
platform_info->autosuspend_delay);
pm_runtime_use_autosuspend(dev);
}
pm_runtime_put(dev);
return 0;
err_spi_register:
if (platform_info->enable_dma)
pl022_dma_remove(pl022);
err_no_irq:
clk_disable_unprepare(pl022->clk);
err_no_clk_en:
err_no_clk:
err_no_ioremap:
amba_release_regions(adev);
err_no_ioregion:
err_no_gpio:
spi_master_put(master);
return status;
}
static int
pl022_remove(struct amba_device *adev)
{
struct pl022 *pl022 = amba_get_drvdata(adev);
if (!pl022)
return 0;
pm_runtime_get_noresume(&adev->dev);
load_ssp_default_config(pl022);
if (pl022->master_info->enable_dma)
pl022_dma_remove(pl022);
clk_disable_unprepare(pl022->clk);
amba_release_regions(adev);
tasklet_disable(&pl022->pump_transfers);
return 0;
}
static int pl022_suspend(struct device *dev)
{
struct pl022 *pl022 = dev_get_drvdata(dev);
int ret;
ret = spi_master_suspend(pl022->master);
if (ret) {
dev_warn(dev, "cannot suspend master\n");
return ret;
}
ret = pm_runtime_force_suspend(dev);
if (ret) {
spi_master_resume(pl022->master);
return ret;
}
pinctrl_pm_select_sleep_state(dev);
dev_dbg(dev, "suspended\n");
return 0;
}
static int pl022_resume(struct device *dev)
{
struct pl022 *pl022 = dev_get_drvdata(dev);
int ret;
ret = pm_runtime_force_resume(dev);
if (ret)
dev_err(dev, "problem resuming\n");
ret = spi_master_resume(pl022->master);
if (ret)
dev_err(dev, "problem starting queue (%d)\n", ret);
else
dev_dbg(dev, "resumed\n");
return ret;
}
static int pl022_runtime_suspend(struct device *dev)
{
struct pl022 *pl022 = dev_get_drvdata(dev);
clk_disable_unprepare(pl022->clk);
pinctrl_pm_select_idle_state(dev);
return 0;
}
static int pl022_runtime_resume(struct device *dev)
{
struct pl022 *pl022 = dev_get_drvdata(dev);
pinctrl_pm_select_default_state(dev);
clk_prepare_enable(pl022->clk);
return 0;
}
static int __init pl022_init(void)
{
return amba_driver_register(&pl022_driver);
}
static void __exit pl022_exit(void)
{
amba_driver_unregister(&pl022_driver);
}
