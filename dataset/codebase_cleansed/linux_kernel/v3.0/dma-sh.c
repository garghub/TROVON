static inline unsigned int get_dmte_irq(unsigned int chan)
{
unsigned int irq = 0;
if (chan < ARRAY_SIZE(dmte_irq_map))
irq = dmte_irq_map[chan];
#if defined(CONFIG_SH_DMA_IRQ_MULTI)
if (irq > DMTE6_IRQ)
return DMTE6_IRQ;
return DMTE0_IRQ;
#else
return irq;
#endif
}
static inline unsigned int calc_xmit_shift(struct dma_channel *chan)
{
u32 chcr = __raw_readl(dma_base_addr[chan->chan] + CHCR);
int cnt = ((chcr & CHCR_TS_LOW_MASK) >> CHCR_TS_LOW_SHIFT) |
((chcr & CHCR_TS_HIGH_MASK) >> CHCR_TS_HIGH_SHIFT);
return ts_shift[cnt];
}
static irqreturn_t dma_tei(int irq, void *dev_id)
{
struct dma_channel *chan = dev_id;
u32 chcr;
chcr = __raw_readl(dma_base_addr[chan->chan] + CHCR);
if (!(chcr & CHCR_TE))
return IRQ_NONE;
chcr &= ~(CHCR_IE | CHCR_DE);
__raw_writel(chcr, (dma_base_addr[chan->chan] + CHCR));
wake_up(&chan->wait_queue);
return IRQ_HANDLED;
}
static int sh_dmac_request_dma(struct dma_channel *chan)
{
if (unlikely(!(chan->flags & DMA_TEI_CAPABLE)))
return 0;
return request_irq(get_dmte_irq(chan->chan), dma_tei,
#if defined(CONFIG_SH_DMA_IRQ_MULTI)
IRQF_SHARED,
#else
IRQF_DISABLED,
#endif
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
__raw_writel(chcr, (dma_base_addr[chan->chan] + CHCR));
chan->flags |= DMA_CONFIGURED;
return 0;
}
static void sh_dmac_enable_dma(struct dma_channel *chan)
{
int irq;
u32 chcr;
chcr = __raw_readl(dma_base_addr[chan->chan] + CHCR);
chcr |= CHCR_DE;
if (chan->flags & DMA_TEI_CAPABLE)
chcr |= CHCR_IE;
__raw_writel(chcr, (dma_base_addr[chan->chan] + CHCR));
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
chcr = __raw_readl(dma_base_addr[chan->chan] + CHCR);
chcr &= ~(CHCR_DE | CHCR_TE | CHCR_IE);
__raw_writel(chcr, (dma_base_addr[chan->chan] + CHCR));
}
static int sh_dmac_xfer_dma(struct dma_channel *chan)
{
if (unlikely(!(chan->flags & DMA_CONFIGURED)))
sh_dmac_configure_channel(chan, 0);
sh_dmac_disable_dma(chan);
if (chan->sar || (mach_is_dreamcast() &&
chan->chan == PVR2_CASCADE_CHAN))
__raw_writel(chan->sar, (dma_base_addr[chan->chan]+SAR));
if (chan->dar || (mach_is_dreamcast() &&
chan->chan == PVR2_CASCADE_CHAN))
__raw_writel(chan->dar, (dma_base_addr[chan->chan] + DAR));
__raw_writel(chan->count >> calc_xmit_shift(chan),
(dma_base_addr[chan->chan] + TCR));
sh_dmac_enable_dma(chan);
return 0;
}
static int sh_dmac_get_dma_residue(struct dma_channel *chan)
{
if (!(__raw_readl(dma_base_addr[chan->chan] + CHCR) & CHCR_DE))
return 0;
return __raw_readl(dma_base_addr[chan->chan] + TCR)
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
static irqreturn_t dma_err(int irq, void *dummy)
{
#if defined(CONFIG_SH_DMA_IRQ_MULTI)
int cnt = 0;
switch (irq) {
#if defined(DMTE6_IRQ) && defined(DMAE1_IRQ)
case DMTE6_IRQ:
cnt++;
#endif
case DMTE0_IRQ:
if (dmaor_read_reg(cnt) & (DMAOR_NMIF | DMAOR_AE)) {
disable_irq(irq);
return IRQ_HANDLED;
}
default:
return IRQ_NONE;
}
#else
dmaor_reset(0);
#if defined(CONFIG_CPU_SUBTYPE_SH7723) || \
defined(CONFIG_CPU_SUBTYPE_SH7780) || \
defined(CONFIG_CPU_SUBTYPE_SH7785)
dmaor_reset(1);
#endif
disable_irq(irq);
return IRQ_HANDLED;
#endif
}
static unsigned int get_dma_error_irq(int n)
{
#if defined(CONFIG_SH_DMA_IRQ_MULTI)
return (n == 0) ? get_dmte_irq(0) : get_dmte_irq(6);
#else
return (n == 0) ? DMAE0_IRQ :
#if defined(DMAE1_IRQ)
DMAE1_IRQ;
#else
-1;
#endif
#endif
}
static int __init sh_dmac_init(void)
{
struct dma_info *info = &sh_dmac_info;
int i;
#ifdef CONFIG_CPU_SH4
int n;
for (n = 0; n < NR_DMAE; n++) {
i = request_irq(get_dma_error_irq(n), dma_err,
#if defined(CONFIG_SH_DMA_IRQ_MULTI)
IRQF_SHARED,
#else
IRQF_DISABLED,
#endif
dmae_name[n], (void *)dmae_name[n]);
if (unlikely(i < 0)) {
printk(KERN_ERR "%s request_irq fail\n", dmae_name[n]);
return i;
}
}
#endif
i = dmaor_reset(0);
if (unlikely(i != 0))
return i;
#if defined(CONFIG_CPU_SUBTYPE_SH7723) || \
defined(CONFIG_CPU_SUBTYPE_SH7780) || \
defined(CONFIG_CPU_SUBTYPE_SH7785)
i = dmaor_reset(1);
if (unlikely(i != 0))
return i;
#endif
return register_dmac(info);
}
static void __exit sh_dmac_exit(void)
{
#ifdef CONFIG_CPU_SH4
int n;
for (n = 0; n < NR_DMAE; n++) {
free_irq(get_dma_error_irq(n), (void *)dmae_name[n]);
}
#endif
unregister_dmac(&sh_dmac_info);
}
