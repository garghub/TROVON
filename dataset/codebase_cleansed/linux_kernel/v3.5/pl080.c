int pl080_get_signal(struct pl08x_dma_chan *ch)
{
const struct pl08x_channel_data *cd = ch->cd;
unsigned int signal = cd->min_signal, val;
unsigned long flags;
spin_lock_irqsave(&lock, flags);
if (signals[signal].busy &&
(signals[signal].val != cd->muxval)) {
spin_unlock_irqrestore(&lock, flags);
return -EBUSY;
}
if (!signals[signal].busy) {
val = readl(DMA_CHN_CFG);
val &= ~(0x3 << (signal * 2));
val |= cd->muxval << (signal * 2);
writel(val, DMA_CHN_CFG);
}
signals[signal].busy++;
signals[signal].val = cd->muxval;
spin_unlock_irqrestore(&lock, flags);
return signal;
}
void pl080_put_signal(struct pl08x_dma_chan *ch)
{
const struct pl08x_channel_data *cd = ch->cd;
unsigned long flags;
spin_lock_irqsave(&lock, flags);
if (!signals[cd->min_signal].busy)
BUG();
signals[cd->min_signal].busy--;
spin_unlock_irqrestore(&lock, flags);
}
