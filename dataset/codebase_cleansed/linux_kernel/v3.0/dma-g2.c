static irqreturn_t g2_dma_interrupt(int irq, void *dev_id)
{
int i;
for (i = 0; i < G2_NR_DMA_CHANNELS; i++) {
if (g2_dma->status[i].status & 0x20000000) {
unsigned int bytes = g2_bytes_remaining(i);
if (likely(bytes == 0)) {
struct dma_info *info = dev_id;
struct dma_channel *chan = info->channels + i;
wake_up(&chan->wait_queue);
return IRQ_HANDLED;
}
}
}
return IRQ_NONE;
}
static int g2_enable_dma(struct dma_channel *chan)
{
unsigned int chan_nr = chan->chan;
g2_dma->channel[chan_nr].chan_enable = 1;
g2_dma->channel[chan_nr].xfer_enable = 1;
return 0;
}
static int g2_disable_dma(struct dma_channel *chan)
{
unsigned int chan_nr = chan->chan;
g2_dma->channel[chan_nr].chan_enable = 0;
g2_dma->channel[chan_nr].xfer_enable = 0;
return 0;
}
static int g2_xfer_dma(struct dma_channel *chan)
{
unsigned int chan_nr = chan->chan;
if (chan->sar & 31) {
printk("g2dma: unaligned source 0x%lx\n", chan->sar);
return -EINVAL;
}
if (chan->dar & 31) {
printk("g2dma: unaligned dest 0x%lx\n", chan->dar);
return -EINVAL;
}
if (chan->count & 31)
chan->count = (chan->count + (32 - 1)) & ~(32 - 1);
chan->dar += 0xa0800000;
chan->mode = !chan->mode;
flush_icache_range((unsigned long)chan->sar, chan->count);
g2_disable_dma(chan);
g2_dma->channel[chan_nr].g2_addr = chan->dar & 0x1fffffe0;
g2_dma->channel[chan_nr].root_addr = chan->sar & 0x1fffffe0;
g2_dma->channel[chan_nr].size = (chan->count & ~31) | 0x80000000;
g2_dma->channel[chan_nr].direction = chan->mode;
g2_dma->channel[chan_nr].ctrl = 5;
g2_enable_dma(chan);
pr_debug("count, sar, dar, mode, ctrl, chan, xfer: %ld, 0x%08lx, "
"0x%08lx, %ld, %ld, %ld, %ld\n",
g2_dma->channel[chan_nr].size,
g2_dma->channel[chan_nr].root_addr,
g2_dma->channel[chan_nr].g2_addr,
g2_dma->channel[chan_nr].direction,
g2_dma->channel[chan_nr].ctrl,
g2_dma->channel[chan_nr].chan_enable,
g2_dma->channel[chan_nr].xfer_enable);
return 0;
}
static int g2_get_residue(struct dma_channel *chan)
{
return g2_bytes_remaining(chan->chan);
}
static int __init g2_dma_init(void)
{
int ret;
ret = request_irq(HW_EVENT_G2_DMA, g2_dma_interrupt, IRQF_DISABLED,
"g2 DMA handler", &g2_dma_info);
if (unlikely(ret))
return -EINVAL;
g2_dma->wait_state = 27;
g2_dma->magic = 0x4659404f;
ret = register_dmac(&g2_dma_info);
if (unlikely(ret != 0))
free_irq(HW_EVENT_G2_DMA, 0);
return ret;
}
static void __exit g2_dma_exit(void)
{
free_irq(HW_EVENT_G2_DMA, 0);
unregister_dmac(&g2_dma_info);
}
