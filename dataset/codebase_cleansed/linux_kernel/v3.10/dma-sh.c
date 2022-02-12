static unsigned long dma_find_base(unsigned int chan)
{
unsigned long base = SH_DMAC_BASE0;
#ifdef SH_DMAC_BASE1
if (chan >= 6)
base = SH_DMAC_BASE1;
#endif
return base;
}
static unsigned long dma_base_addr(unsigned int chan)
{
unsigned long base = dma_find_base(chan);
if (chan >= 9)
chan -= 6;
if (chan >= 4)
base += 0x10;
return base + (chan * 0x10);
}
static inline unsigned int get_dmte_irq(unsigned int chan)
{
return chan >= 6 ? DMTE6_IRQ : DMTE0_IRQ;
}
static inline unsigned int get_dmte_irq(unsigned int chan)
{
return dmte_irq_map[chan];
}
static inline unsigned int calc_xmit_shift(struct dma_channel *chan)
{
u32 chcr = __raw_readl(dma_base_addr(chan->chan) + CHCR);
int cnt = ((chcr & CHCR_TS_LOW_MASK) >> CHCR_TS_LOW_SHIFT) |
((chcr & CHCR_TS_HIGH_MASK) >> CHCR_TS_HIGH_SHIFT);
return ts_shift[cnt];
}
static irqreturn_t dma_tei(int irq, void *dev_id)
{
struct dma_channel *chan = dev_id;
u32 chcr;
chcr = __raw_readl(dma_base_addr(chan->chan) + CHCR);
if (!(chcr & CHCR_TE))
return IRQ_NONE;
chcr &= ~(CHCR_IE | CHCR_DE);
__raw_writel(chcr, (dma_base_addr(chan->chan) + CHCR));
wake_up(&chan->wait_queue);
return IRQ_HANDLED;
}
static int sh_dmac_request_dma(struct dma_channel *chan)
{
if (unlikely(!(chan->flags & DMA_TEI_CAPABLE)))
return 0;
return request_irq(get_dmte_irq(chan->chan), dma_tei, IRQF_SHARED,
chan->dev_id, chan);
}
static void sh_dmac_free_dma(struct dma_channel *chan)
{
free_irq(get_dmte_irq(chan->chan), chan);
}
static int
sh_dmac_configure_channel(struct dma_channel *chan, unsigned long chcr)
{
if (!chcr)
chcr = RS_DUAL | CHCR_IE;
if (chcr & CHCR_IE) {
chcr &= ~CHCR_IE;
chan->flags |= DMA_TEI_CAPABLE;
} else {
chan->flags &= ~DMA_TEI_CAPABLE;
}
__raw_writel(chcr, (dma_base_addr(chan->chan) + CHCR));
chan->flags |= DMA_CONFIGURED;
return 0;
}
static void sh_dmac_enable_dma(struct dma_channel *chan)
{
int irq;
u32 chcr;
chcr = __raw_readl(dma_base_addr(chan->chan) + CHCR);
chcr |= CHCR_DE;
if (chan->flags & DMA_TEI_CAPABLE)
chcr |= CHCR_IE;
__raw_writel(chcr, (dma_base_addr(chan->chan) + CHCR));
if (chan->flags & DMA_TEI_CAPABLE) {
irq = get_dmte_irq(chan->chan);
enable_irq(irq);
}
}
static void sh_dmac_disable_dma(struct dma_channel *chan)
{
int irq;
u32 chcr;
if (chan->flags & DMA_TEI_CAPABLE) {
irq = get_dmte_irq(chan->chan);
disable_irq(irq);
}
chcr = __raw_readl(dma_base_addr(chan->chan) + CHCR);
chcr &= ~(CHCR_DE | CHCR_TE | CHCR_IE);
__raw_writel(chcr, (dma_base_addr(chan->chan) + CHCR));
}
static int sh_dmac_xfer_dma(struct dma_channel *chan)
{
if (unlikely(!(chan->flags & DMA_CONFIGURED)))
sh_dmac_configure_channel(chan, 0);
sh_dmac_disable_dma(chan);
if (chan->sar || (mach_is_dreamcast() &&
chan->chan == PVR2_CASCADE_CHAN))
__raw_writel(chan->sar, (dma_base_addr(chan->chan) + SAR));
if (chan->dar || (mach_is_dreamcast() &&
chan->chan == PVR2_CASCADE_CHAN))
__raw_writel(chan->dar, (dma_base_addr(chan->chan) + DAR));
__raw_writel(chan->count >> calc_xmit_shift(chan),
(dma_base_addr(chan->chan) + TCR));
sh_dmac_enable_dma(chan);
return 0;
}
static int sh_dmac_get_dma_residue(struct dma_channel *chan)
{
if (!(__raw_readl(dma_base_addr(chan->chan) + CHCR) & CHCR_DE))
return 0;
return __raw_readl(dma_base_addr(chan->chan) + TCR)
<< calc_xmit_shift(chan);
}
static inline int dmaor_reset(int no)
{
unsigned long dmaor = dmaor_read_reg(no);
dmaor &= ~(DMAOR_NMIF | DMAOR_AE);
dmaor_write_reg(no, dmaor);
dmaor |= DMAOR_INIT;
dmaor_write_reg(no, dmaor);
if ((dmaor_read_reg(no) & (DMAOR_AE | DMAOR_NMIF))) {
printk(KERN_ERR "dma-sh: Can't initialize DMAOR.\n");
return -EINVAL;
}
return 0;
}
static inline unsigned int get_dma_error_irq(int n)
{
return get_dmte_irq(n * 6);
}
static inline unsigned int get_dma_error_irq(int n)
{
return dmae_irq_map[n];
}
static irqreturn_t dma_err(int irq, void *dummy)
{
int i;
for (i = 0; i < NR_DMAOR; i++)
dmaor_reset(i);
disable_irq(irq);
return IRQ_HANDLED;
}
static int dmae_irq_init(void)
{
int n;
for (n = 0; n < NR_DMAE; n++) {
int i = request_irq(get_dma_error_irq(n), dma_err,
IRQF_SHARED, dmae_name[n], (void *)dmae_name[n]);
if (unlikely(i < 0)) {
printk(KERN_ERR "%s request_irq fail\n", dmae_name[n]);
return i;
}
}
return 0;
}
static void dmae_irq_free(void)
{
int n;
for (n = 0; n < NR_DMAE; n++)
free_irq(get_dma_error_irq(n), NULL);
}
static inline int dmae_irq_init(void)
{
return 0;
}
static void dmae_irq_free(void)
{
}
static int __init sh_dmac_init(void)
{
struct dma_info *info = &sh_dmac_info;
int i, rc;
rc = dmae_irq_init();
if (unlikely(rc != 0))
return rc;
for (i = 0; i < NR_DMAOR; i++) {
rc = dmaor_reset(i);
if (unlikely(rc != 0))
return rc;
}
return register_dmac(info);
}
static void __exit sh_dmac_exit(void)
{
dmae_irq_free();
unregister_dmac(&sh_dmac_info);
}
