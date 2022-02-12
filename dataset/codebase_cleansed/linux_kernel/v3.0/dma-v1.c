static void imx_dmav1_writel(unsigned val, unsigned offset)
{
__raw_writel(val, imx_dmav1_baseaddr + offset);
}
static unsigned imx_dmav1_readl(unsigned offset)
{
return __raw_readl(imx_dmav1_baseaddr + offset);
}
static int imx_dma_hw_chain(struct imx_dma_channel *imxdma)
{
if (cpu_is_mx27())
return imxdma->hw_chaining;
else
return 0;
}
static inline int imx_dma_sg_next(int channel, struct scatterlist *sg)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
unsigned long now;
if (!imxdma->name) {
printk(KERN_CRIT "%s: called for not allocated channel %d\n",
__func__, channel);
return 0;
}
now = min(imxdma->resbytes, sg->length);
if (imxdma->resbytes != IMX_DMA_LENGTH_LOOP)
imxdma->resbytes -= now;
if ((imxdma->dma_mode & DMA_MODE_MASK) == DMA_MODE_READ)
imx_dmav1_writel(sg->dma_address, DMA_DAR(channel));
else
imx_dmav1_writel(sg->dma_address, DMA_SAR(channel));
imx_dmav1_writel(now, DMA_CNTR(channel));
pr_debug("imxdma%d: next sg chunk dst 0x%08x, src 0x%08x, "
"size 0x%08x\n", channel,
imx_dmav1_readl(DMA_DAR(channel)),
imx_dmav1_readl(DMA_SAR(channel)),
imx_dmav1_readl(DMA_CNTR(channel)));
return now;
}
int
imx_dma_setup_single(int channel, dma_addr_t dma_address,
unsigned int dma_length, unsigned int dev_addr,
unsigned int dmamode)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
imxdma->sg = NULL;
imxdma->dma_mode = dmamode;
if (!dma_address) {
printk(KERN_ERR "imxdma%d: imx_dma_setup_single null address\n",
channel);
return -EINVAL;
}
if (!dma_length) {
printk(KERN_ERR "imxdma%d: imx_dma_setup_single zero length\n",
channel);
return -EINVAL;
}
if ((dmamode & DMA_MODE_MASK) == DMA_MODE_READ) {
pr_debug("imxdma%d: %s dma_addressg=0x%08x dma_length=%d "
"dev_addr=0x%08x for read\n",
channel, __func__, (unsigned int)dma_address,
dma_length, dev_addr);
imx_dmav1_writel(dev_addr, DMA_SAR(channel));
imx_dmav1_writel(dma_address, DMA_DAR(channel));
imx_dmav1_writel(imxdma->ccr_from_device, DMA_CCR(channel));
} else if ((dmamode & DMA_MODE_MASK) == DMA_MODE_WRITE) {
pr_debug("imxdma%d: %s dma_addressg=0x%08x dma_length=%d "
"dev_addr=0x%08x for write\n",
channel, __func__, (unsigned int)dma_address,
dma_length, dev_addr);
imx_dmav1_writel(dma_address, DMA_SAR(channel));
imx_dmav1_writel(dev_addr, DMA_DAR(channel));
imx_dmav1_writel(imxdma->ccr_to_device,
DMA_CCR(channel));
} else {
printk(KERN_ERR "imxdma%d: imx_dma_setup_single bad dmamode\n",
channel);
return -EINVAL;
}
imx_dmav1_writel(dma_length, DMA_CNTR(channel));
return 0;
}
int
imx_dma_setup_sg(int channel,
struct scatterlist *sg, unsigned int sgcount,
unsigned int dma_length, unsigned int dev_addr,
unsigned int dmamode)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
if (imxdma->in_use)
return -EBUSY;
imxdma->sg = sg;
imxdma->dma_mode = dmamode;
imxdma->resbytes = dma_length;
if (!sg || !sgcount) {
printk(KERN_ERR "imxdma%d: imx_dma_setup_sg empty sg list\n",
channel);
return -EINVAL;
}
if (!sg->length) {
printk(KERN_ERR "imxdma%d: imx_dma_setup_sg zero length\n",
channel);
return -EINVAL;
}
if ((dmamode & DMA_MODE_MASK) == DMA_MODE_READ) {
pr_debug("imxdma%d: %s sg=%p sgcount=%d total length=%d "
"dev_addr=0x%08x for read\n",
channel, __func__, sg, sgcount, dma_length, dev_addr);
imx_dmav1_writel(dev_addr, DMA_SAR(channel));
imx_dmav1_writel(imxdma->ccr_from_device, DMA_CCR(channel));
} else if ((dmamode & DMA_MODE_MASK) == DMA_MODE_WRITE) {
pr_debug("imxdma%d: %s sg=%p sgcount=%d total length=%d "
"dev_addr=0x%08x for write\n",
channel, __func__, sg, sgcount, dma_length, dev_addr);
imx_dmav1_writel(dev_addr, DMA_DAR(channel));
imx_dmav1_writel(imxdma->ccr_to_device, DMA_CCR(channel));
} else {
printk(KERN_ERR "imxdma%d: imx_dma_setup_sg bad dmamode\n",
channel);
return -EINVAL;
}
imx_dma_sg_next(channel, sg);
return 0;
}
int
imx_dma_config_channel(int channel, unsigned int config_port,
unsigned int config_mem, unsigned int dmareq, int hw_chaining)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
u32 dreq = 0;
imxdma->hw_chaining = 0;
if (hw_chaining) {
imxdma->hw_chaining = 1;
if (!imx_dma_hw_chain(imxdma))
return -EINVAL;
}
if (dmareq)
dreq = CCR_REN;
imxdma->ccr_from_device = config_port | (config_mem << 2) | dreq;
imxdma->ccr_to_device = config_mem | (config_port << 2) | dreq;
imx_dmav1_writel(dmareq, DMA_RSSR(channel));
return 0;
}
void imx_dma_config_burstlen(int channel, unsigned int burstlen)
{
imx_dmav1_writel(burstlen, DMA_BLR(channel));
}
int
imx_dma_setup_handlers(int channel,
void (*irq_handler) (int, void *),
void (*err_handler) (int, void *, int),
void *data)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
unsigned long flags;
if (!imxdma->name) {
printk(KERN_CRIT "%s: called for not allocated channel %d\n",
__func__, channel);
return -ENODEV;
}
local_irq_save(flags);
imx_dmav1_writel(1 << channel, DMA_DISR);
imxdma->irq_handler = irq_handler;
imxdma->err_handler = err_handler;
imxdma->data = data;
local_irq_restore(flags);
return 0;
}
int
imx_dma_setup_progression_handler(int channel,
void (*prog_handler) (int, void*, struct scatterlist*))
{
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
unsigned long flags;
if (!imxdma->name) {
printk(KERN_CRIT "%s: called for not allocated channel %d\n",
__func__, channel);
return -ENODEV;
}
local_irq_save(flags);
imxdma->prog_handler = prog_handler;
local_irq_restore(flags);
return 0;
}
void imx_dma_enable(int channel)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
unsigned long flags;
pr_debug("imxdma%d: imx_dma_enable\n", channel);
if (!imxdma->name) {
printk(KERN_CRIT "%s: called for not allocated channel %d\n",
__func__, channel);
return;
}
if (imxdma->in_use)
return;
local_irq_save(flags);
imx_dmav1_writel(1 << channel, DMA_DISR);
imx_dmav1_writel(imx_dmav1_readl(DMA_DIMR) & ~(1 << channel), DMA_DIMR);
imx_dmav1_writel(imx_dmav1_readl(DMA_CCR(channel)) | CCR_CEN |
CCR_ACRPT, DMA_CCR(channel));
#ifdef CONFIG_ARCH_MX2
if ((cpu_is_mx21() || cpu_is_mx27()) &&
imxdma->sg && imx_dma_hw_chain(imxdma)) {
imxdma->sg = sg_next(imxdma->sg);
if (imxdma->sg) {
u32 tmp;
imx_dma_sg_next(channel, imxdma->sg);
tmp = imx_dmav1_readl(DMA_CCR(channel));
imx_dmav1_writel(tmp | CCR_RPT | CCR_ACRPT,
DMA_CCR(channel));
}
}
#endif
imxdma->in_use = 1;
local_irq_restore(flags);
}
void imx_dma_disable(int channel)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
unsigned long flags;
pr_debug("imxdma%d: imx_dma_disable\n", channel);
if (imx_dma_hw_chain(imxdma))
del_timer(&imxdma->watchdog);
local_irq_save(flags);
imx_dmav1_writel(imx_dmav1_readl(DMA_DIMR) | (1 << channel), DMA_DIMR);
imx_dmav1_writel(imx_dmav1_readl(DMA_CCR(channel)) & ~CCR_CEN,
DMA_CCR(channel));
imx_dmav1_writel(1 << channel, DMA_DISR);
imxdma->in_use = 0;
local_irq_restore(flags);
}
static void imx_dma_watchdog(unsigned long chno)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[chno];
imx_dmav1_writel(0, DMA_CCR(chno));
imxdma->in_use = 0;
imxdma->sg = NULL;
if (imxdma->err_handler)
imxdma->err_handler(chno, imxdma->data, IMX_DMA_ERR_TIMEOUT);
}
static irqreturn_t dma_err_handler(int irq, void *dev_id)
{
int i, disr;
struct imx_dma_channel *imxdma;
unsigned int err_mask;
int errcode;
disr = imx_dmav1_readl(DMA_DISR);
err_mask = imx_dmav1_readl(DMA_DBTOSR) |
imx_dmav1_readl(DMA_DRTOSR) |
imx_dmav1_readl(DMA_DSESR) |
imx_dmav1_readl(DMA_DBOSR);
if (!err_mask)
return IRQ_HANDLED;
imx_dmav1_writel(disr & err_mask, DMA_DISR);
for (i = 0; i < IMX_DMA_CHANNELS; i++) {
if (!(err_mask & (1 << i)))
continue;
imxdma = &imx_dma_channels[i];
errcode = 0;
if (imx_dmav1_readl(DMA_DBTOSR) & (1 << i)) {
imx_dmav1_writel(1 << i, DMA_DBTOSR);
errcode |= IMX_DMA_ERR_BURST;
}
if (imx_dmav1_readl(DMA_DRTOSR) & (1 << i)) {
imx_dmav1_writel(1 << i, DMA_DRTOSR);
errcode |= IMX_DMA_ERR_REQUEST;
}
if (imx_dmav1_readl(DMA_DSESR) & (1 << i)) {
imx_dmav1_writel(1 << i, DMA_DSESR);
errcode |= IMX_DMA_ERR_TRANSFER;
}
if (imx_dmav1_readl(DMA_DBOSR) & (1 << i)) {
imx_dmav1_writel(1 << i, DMA_DBOSR);
errcode |= IMX_DMA_ERR_BUFFER;
}
if (imxdma->name && imxdma->err_handler) {
imxdma->err_handler(i, imxdma->data, errcode);
continue;
}
imx_dma_channels[i].sg = NULL;
printk(KERN_WARNING
"DMA timeout on channel %d (%s) -%s%s%s%s\n",
i, imxdma->name,
errcode & IMX_DMA_ERR_BURST ? " burst" : "",
errcode & IMX_DMA_ERR_REQUEST ? " request" : "",
errcode & IMX_DMA_ERR_TRANSFER ? " transfer" : "",
errcode & IMX_DMA_ERR_BUFFER ? " buffer" : "");
}
return IRQ_HANDLED;
}
static void dma_irq_handle_channel(int chno)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[chno];
if (!imxdma->name) {
printk(KERN_WARNING
"spurious IRQ for DMA channel %d\n", chno);
return;
}
if (imxdma->sg) {
u32 tmp;
struct scatterlist *current_sg = imxdma->sg;
imxdma->sg = sg_next(imxdma->sg);
if (imxdma->sg) {
imx_dma_sg_next(chno, imxdma->sg);
tmp = imx_dmav1_readl(DMA_CCR(chno));
if (imx_dma_hw_chain(imxdma)) {
mod_timer(&imxdma->watchdog,
jiffies + msecs_to_jiffies(500));
tmp |= CCR_CEN | CCR_RPT | CCR_ACRPT;
imx_dmav1_writel(tmp, DMA_CCR(chno));
} else {
imx_dmav1_writel(tmp & ~CCR_CEN, DMA_CCR(chno));
tmp |= CCR_CEN;
}
imx_dmav1_writel(tmp, DMA_CCR(chno));
if (imxdma->prog_handler)
imxdma->prog_handler(chno, imxdma->data,
current_sg);
return;
}
if (imx_dma_hw_chain(imxdma)) {
del_timer(&imxdma->watchdog);
return;
}
}
imx_dmav1_writel(0, DMA_CCR(chno));
imxdma->in_use = 0;
if (imxdma->irq_handler)
imxdma->irq_handler(chno, imxdma->data);
}
static irqreturn_t dma_irq_handler(int irq, void *dev_id)
{
int i, disr;
#ifdef CONFIG_ARCH_MX2
if (cpu_is_mx21() || cpu_is_mx27())
dma_err_handler(irq, dev_id);
#endif
disr = imx_dmav1_readl(DMA_DISR);
pr_debug("imxdma: dma_irq_handler called, disr=0x%08x\n",
disr);
imx_dmav1_writel(disr, DMA_DISR);
for (i = 0; i < IMX_DMA_CHANNELS; i++) {
if (disr & (1 << i))
dma_irq_handle_channel(i);
}
return IRQ_HANDLED;
}
int imx_dma_request(int channel, const char *name)
{
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
unsigned long flags;
int ret = 0;
if (!name)
return -EINVAL;
if (channel >= IMX_DMA_CHANNELS) {
printk(KERN_CRIT "%s: called for non-existed channel %d\n",
__func__, channel);
return -EINVAL;
}
local_irq_save(flags);
if (imxdma->name) {
local_irq_restore(flags);
return -EBUSY;
}
memset(imxdma, 0, sizeof(*imxdma));
imxdma->name = name;
local_irq_restore(flags);
#ifdef CONFIG_ARCH_MX2
if (cpu_is_mx21() || cpu_is_mx27()) {
ret = request_irq(MX2x_INT_DMACH0 + channel,
dma_irq_handler, 0, "DMA", NULL);
if (ret) {
imxdma->name = NULL;
pr_crit("Can't register IRQ %d for DMA channel %d\n",
MX2x_INT_DMACH0 + channel, channel);
return ret;
}
init_timer(&imxdma->watchdog);
imxdma->watchdog.function = &imx_dma_watchdog;
imxdma->watchdog.data = channel;
}
#endif
return ret;
}
void imx_dma_free(int channel)
{
unsigned long flags;
struct imx_dma_channel *imxdma = &imx_dma_channels[channel];
if (!imxdma->name) {
printk(KERN_CRIT
"%s: trying to free free channel %d\n",
__func__, channel);
return;
}
local_irq_save(flags);
imx_dma_disable(channel);
imxdma->name = NULL;
#ifdef CONFIG_ARCH_MX2
if (cpu_is_mx21() || cpu_is_mx27())
free_irq(MX2x_INT_DMACH0 + channel, NULL);
#endif
local_irq_restore(flags);
}
int imx_dma_request_by_prio(const char *name, enum imx_dma_prio prio)
{
int i;
int best;
switch (prio) {
case (DMA_PRIO_HIGH):
best = 8;
break;
case (DMA_PRIO_MEDIUM):
best = 4;
break;
case (DMA_PRIO_LOW):
default:
best = 0;
break;
}
for (i = best; i < IMX_DMA_CHANNELS; i++)
if (!imx_dma_request(i, name))
return i;
for (i = best - 1; i >= 0; i--)
if (!imx_dma_request(i, name))
return i;
printk(KERN_ERR "%s: no free DMA channel found\n", __func__);
return -ENODEV;
}
static int __init imx_dma_init(void)
{
int ret = 0;
int i;
#ifdef CONFIG_ARCH_MX1
if (cpu_is_mx1())
imx_dmav1_baseaddr = MX1_IO_ADDRESS(MX1_DMA_BASE_ADDR);
else
#endif
#ifdef CONFIG_MACH_MX21
if (cpu_is_mx21())
imx_dmav1_baseaddr = MX21_IO_ADDRESS(MX21_DMA_BASE_ADDR);
else
#endif
#ifdef CONFIG_MACH_MX27
if (cpu_is_mx27())
imx_dmav1_baseaddr = MX27_IO_ADDRESS(MX27_DMA_BASE_ADDR);
else
#endif
return 0;
dma_clk = clk_get(NULL, "dma");
if (IS_ERR(dma_clk))
return PTR_ERR(dma_clk);
clk_enable(dma_clk);
imx_dmav1_writel(DCR_DRST, DMA_DCR);
#ifdef CONFIG_ARCH_MX1
if (cpu_is_mx1()) {
ret = request_irq(MX1_DMA_INT, dma_irq_handler, 0, "DMA", NULL);
if (ret) {
pr_crit("Wow! Can't register IRQ for DMA\n");
return ret;
}
ret = request_irq(MX1_DMA_ERR, dma_err_handler, 0, "DMA", NULL);
if (ret) {
pr_crit("Wow! Can't register ERRIRQ for DMA\n");
free_irq(MX1_DMA_INT, NULL);
return ret;
}
}
#endif
imx_dmav1_writel(DCR_DEN, DMA_DCR);
imx_dmav1_writel((1 << IMX_DMA_CHANNELS) - 1, DMA_DISR);
imx_dmav1_writel((1 << IMX_DMA_CHANNELS) - 1, DMA_DIMR);
for (i = 0; i < IMX_DMA_CHANNELS; i++) {
imx_dma_channels[i].sg = NULL;
imx_dma_channels[i].dma_num = i;
}
return ret;
}
