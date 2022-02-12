static irqreturn_t pvr2_dma_interrupt(int irq, void *dev_id)
{
if (get_dma_residue(PVR2_CASCADE_CHAN)) {
printk(KERN_WARNING "DMA: SH DMAC did not complete transfer "
"on channel %d, waiting..\n", PVR2_CASCADE_CHAN);
dma_wait_for_completion(PVR2_CASCADE_CHAN);
}
if (count++ < 10)
pr_debug("Got a pvr2 dma interrupt for channel %d\n",
irq - HW_EVENT_PVR2_DMA);
xfer_complete = 1;
return IRQ_HANDLED;
}
static int pvr2_request_dma(struct dma_channel *chan)
{
if (__raw_readl(PVR2_DMA_MODE) != 0)
return -EBUSY;
__raw_writel(0, PVR2_DMA_LMMODE0);
return 0;
}
static int pvr2_get_dma_residue(struct dma_channel *chan)
{
return xfer_complete == 0;
}
static int pvr2_xfer_dma(struct dma_channel *chan)
{
if (chan->sar || !chan->dar)
return -EINVAL;
xfer_complete = 0;
__raw_writel(chan->dar, PVR2_DMA_ADDR);
__raw_writel(chan->count, PVR2_DMA_COUNT);
__raw_writel(chan->mode & DMA_MODE_MASK, PVR2_DMA_MODE);
return 0;
}
static int __init pvr2_dma_init(void)
{
setup_irq(HW_EVENT_PVR2_DMA, &pvr2_dma_irq);
request_dma(PVR2_CASCADE_CHAN, "pvr2 cascade");
return register_dmac(&pvr2_dma_info);
}
static void __exit pvr2_dma_exit(void)
{
free_dma(PVR2_CASCADE_CHAN);
free_irq(HW_EVENT_PVR2_DMA, 0);
unregister_dmac(&pvr2_dma_info);
}
