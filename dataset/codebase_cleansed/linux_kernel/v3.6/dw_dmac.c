static struct device *chan2dev(struct dma_chan *chan)
{
return &chan->dev->device;
}
static struct device *chan2parent(struct dma_chan *chan)
{
return chan->dev->device.parent;
}
static struct dw_desc *dwc_first_active(struct dw_dma_chan *dwc)
{
return list_entry(dwc->active_list.next, struct dw_desc, desc_node);
}
static struct dw_desc *dwc_desc_get(struct dw_dma_chan *dwc)
{
struct dw_desc *desc, *_desc;
struct dw_desc *ret = NULL;
unsigned int i = 0;
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
list_for_each_entry_safe(desc, _desc, &dwc->free_list, desc_node) {
i++;
if (async_tx_test_ack(&desc->txd)) {
list_del(&desc->desc_node);
ret = desc;
break;
}
dev_dbg(chan2dev(&dwc->chan), "desc %p not ACKed\n", desc);
}
spin_unlock_irqrestore(&dwc->lock, flags);
dev_vdbg(chan2dev(&dwc->chan), "scanned %u descriptors on freelist\n", i);
return ret;
}
static void dwc_sync_desc_for_cpu(struct dw_dma_chan *dwc, struct dw_desc *desc)
{
struct dw_desc *child;
list_for_each_entry(child, &desc->tx_list, desc_node)
dma_sync_single_for_cpu(chan2parent(&dwc->chan),
child->txd.phys, sizeof(child->lli),
DMA_TO_DEVICE);
dma_sync_single_for_cpu(chan2parent(&dwc->chan),
desc->txd.phys, sizeof(desc->lli),
DMA_TO_DEVICE);
}
static void dwc_desc_put(struct dw_dma_chan *dwc, struct dw_desc *desc)
{
unsigned long flags;
if (desc) {
struct dw_desc *child;
dwc_sync_desc_for_cpu(dwc, desc);
spin_lock_irqsave(&dwc->lock, flags);
list_for_each_entry(child, &desc->tx_list, desc_node)
dev_vdbg(chan2dev(&dwc->chan),
"moving child desc %p to freelist\n",
child);
list_splice_init(&desc->tx_list, &dwc->free_list);
dev_vdbg(chan2dev(&dwc->chan), "moving desc %p to freelist\n", desc);
list_add(&desc->desc_node, &dwc->free_list);
spin_unlock_irqrestore(&dwc->lock, flags);
}
}
static void dwc_initialize(struct dw_dma_chan *dwc)
{
struct dw_dma *dw = to_dw_dma(dwc->chan.device);
struct dw_dma_slave *dws = dwc->chan.private;
u32 cfghi = DWC_CFGH_FIFO_MODE;
u32 cfglo = DWC_CFGL_CH_PRIOR(dwc->priority);
if (dwc->initialized == true)
return;
if (dws) {
BUG_ON(!dws->dma_dev || dws->dma_dev != dw->dma.dev);
cfghi = dws->cfg_hi;
cfglo |= dws->cfg_lo & ~DWC_CFGL_CH_PRIOR_MASK;
}
channel_writel(dwc, CFG_LO, cfglo);
channel_writel(dwc, CFG_HI, cfghi);
channel_set_bit(dw, MASK.XFER, dwc->mask);
channel_set_bit(dw, MASK.ERROR, dwc->mask);
dwc->initialized = true;
}
static inline unsigned int dwc_fast_fls(unsigned long long v)
{
if (!(v & 7))
return 3;
else if (!(v & 3))
return 2;
else if (!(v & 1))
return 1;
return 0;
}
static void dwc_dump_chan_regs(struct dw_dma_chan *dwc)
{
dev_err(chan2dev(&dwc->chan),
" SAR: 0x%x DAR: 0x%x LLP: 0x%x CTL: 0x%x:%08x\n",
channel_readl(dwc, SAR),
channel_readl(dwc, DAR),
channel_readl(dwc, LLP),
channel_readl(dwc, CTL_HI),
channel_readl(dwc, CTL_LO));
}
static inline void dwc_chan_disable(struct dw_dma *dw, struct dw_dma_chan *dwc)
{
channel_clear_bit(dw, CH_EN, dwc->mask);
while (dma_readl(dw, CH_EN) & dwc->mask)
cpu_relax();
}
static void dwc_dostart(struct dw_dma_chan *dwc, struct dw_desc *first)
{
struct dw_dma *dw = to_dw_dma(dwc->chan.device);
if (dma_readl(dw, CH_EN) & dwc->mask) {
dev_err(chan2dev(&dwc->chan),
"BUG: Attempted to start non-idle channel\n");
dwc_dump_chan_regs(dwc);
return;
}
dwc_initialize(dwc);
channel_writel(dwc, LLP, first->txd.phys);
channel_writel(dwc, CTL_LO,
DWC_CTLL_LLP_D_EN | DWC_CTLL_LLP_S_EN);
channel_writel(dwc, CTL_HI, 0);
channel_set_bit(dw, CH_EN, dwc->mask);
}
static void
dwc_descriptor_complete(struct dw_dma_chan *dwc, struct dw_desc *desc,
bool callback_required)
{
dma_async_tx_callback callback = NULL;
void *param = NULL;
struct dma_async_tx_descriptor *txd = &desc->txd;
struct dw_desc *child;
unsigned long flags;
dev_vdbg(chan2dev(&dwc->chan), "descriptor %u complete\n", txd->cookie);
spin_lock_irqsave(&dwc->lock, flags);
dma_cookie_complete(txd);
if (callback_required) {
callback = txd->callback;
param = txd->callback_param;
}
dwc_sync_desc_for_cpu(dwc, desc);
list_for_each_entry(child, &desc->tx_list, desc_node)
async_tx_ack(&child->txd);
async_tx_ack(&desc->txd);
list_splice_init(&desc->tx_list, &dwc->free_list);
list_move(&desc->desc_node, &dwc->free_list);
if (!dwc->chan.private) {
struct device *parent = chan2parent(&dwc->chan);
if (!(txd->flags & DMA_COMPL_SKIP_DEST_UNMAP)) {
if (txd->flags & DMA_COMPL_DEST_UNMAP_SINGLE)
dma_unmap_single(parent, desc->lli.dar,
desc->len, DMA_FROM_DEVICE);
else
dma_unmap_page(parent, desc->lli.dar,
desc->len, DMA_FROM_DEVICE);
}
if (!(txd->flags & DMA_COMPL_SKIP_SRC_UNMAP)) {
if (txd->flags & DMA_COMPL_SRC_UNMAP_SINGLE)
dma_unmap_single(parent, desc->lli.sar,
desc->len, DMA_TO_DEVICE);
else
dma_unmap_page(parent, desc->lli.sar,
desc->len, DMA_TO_DEVICE);
}
}
spin_unlock_irqrestore(&dwc->lock, flags);
if (callback_required && callback)
callback(param);
}
static void dwc_complete_all(struct dw_dma *dw, struct dw_dma_chan *dwc)
{
struct dw_desc *desc, *_desc;
LIST_HEAD(list);
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
if (dma_readl(dw, CH_EN) & dwc->mask) {
dev_err(chan2dev(&dwc->chan),
"BUG: XFER bit set, but channel not idle!\n");
dwc_chan_disable(dw, dwc);
}
list_splice_init(&dwc->active_list, &list);
if (!list_empty(&dwc->queue)) {
list_move(dwc->queue.next, &dwc->active_list);
dwc_dostart(dwc, dwc_first_active(dwc));
}
spin_unlock_irqrestore(&dwc->lock, flags);
list_for_each_entry_safe(desc, _desc, &list, desc_node)
dwc_descriptor_complete(dwc, desc, true);
}
static void dwc_scan_descriptors(struct dw_dma *dw, struct dw_dma_chan *dwc)
{
dma_addr_t llp;
struct dw_desc *desc, *_desc;
struct dw_desc *child;
u32 status_xfer;
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
llp = channel_readl(dwc, LLP);
status_xfer = dma_readl(dw, RAW.XFER);
if (status_xfer & dwc->mask) {
dma_writel(dw, CLEAR.XFER, dwc->mask);
spin_unlock_irqrestore(&dwc->lock, flags);
dwc_complete_all(dw, dwc);
return;
}
if (list_empty(&dwc->active_list)) {
spin_unlock_irqrestore(&dwc->lock, flags);
return;
}
dev_vdbg(chan2dev(&dwc->chan), "%s: llp=0x%llx\n", __func__,
(unsigned long long)llp);
list_for_each_entry_safe(desc, _desc, &dwc->active_list, desc_node) {
if (desc->txd.phys == llp) {
spin_unlock_irqrestore(&dwc->lock, flags);
return;
}
if (desc->lli.llp == llp) {
spin_unlock_irqrestore(&dwc->lock, flags);
return;
}
list_for_each_entry(child, &desc->tx_list, desc_node)
if (child->lli.llp == llp) {
spin_unlock_irqrestore(&dwc->lock, flags);
return;
}
spin_unlock_irqrestore(&dwc->lock, flags);
dwc_descriptor_complete(dwc, desc, true);
spin_lock_irqsave(&dwc->lock, flags);
}
dev_err(chan2dev(&dwc->chan),
"BUG: All descriptors done, but channel not idle!\n");
dwc_chan_disable(dw, dwc);
if (!list_empty(&dwc->queue)) {
list_move(dwc->queue.next, &dwc->active_list);
dwc_dostart(dwc, dwc_first_active(dwc));
}
spin_unlock_irqrestore(&dwc->lock, flags);
}
static inline void dwc_dump_lli(struct dw_dma_chan *dwc, struct dw_lli *lli)
{
dev_printk(KERN_CRIT, chan2dev(&dwc->chan),
" desc: s0x%x d0x%x l0x%x c0x%x:%x\n",
lli->sar, lli->dar, lli->llp, lli->ctlhi, lli->ctllo);
}
static void dwc_handle_error(struct dw_dma *dw, struct dw_dma_chan *dwc)
{
struct dw_desc *bad_desc;
struct dw_desc *child;
unsigned long flags;
dwc_scan_descriptors(dw, dwc);
spin_lock_irqsave(&dwc->lock, flags);
bad_desc = dwc_first_active(dwc);
list_del_init(&bad_desc->desc_node);
list_move(dwc->queue.next, dwc->active_list.prev);
dma_writel(dw, CLEAR.ERROR, dwc->mask);
if (!list_empty(&dwc->active_list))
dwc_dostart(dwc, dwc_first_active(dwc));
dev_printk(KERN_CRIT, chan2dev(&dwc->chan),
"Bad descriptor submitted for DMA!\n");
dev_printk(KERN_CRIT, chan2dev(&dwc->chan),
" cookie: %d\n", bad_desc->txd.cookie);
dwc_dump_lli(dwc, &bad_desc->lli);
list_for_each_entry(child, &bad_desc->tx_list, desc_node)
dwc_dump_lli(dwc, &child->lli);
spin_unlock_irqrestore(&dwc->lock, flags);
dwc_descriptor_complete(dwc, bad_desc, true);
}
inline dma_addr_t dw_dma_get_src_addr(struct dma_chan *chan)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
return channel_readl(dwc, SAR);
}
inline dma_addr_t dw_dma_get_dst_addr(struct dma_chan *chan)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
return channel_readl(dwc, DAR);
}
static void dwc_handle_cyclic(struct dw_dma *dw, struct dw_dma_chan *dwc,
u32 status_err, u32 status_xfer)
{
unsigned long flags;
if (dwc->mask) {
void (*callback)(void *param);
void *callback_param;
dev_vdbg(chan2dev(&dwc->chan), "new cyclic period llp 0x%08x\n",
channel_readl(dwc, LLP));
callback = dwc->cdesc->period_callback;
callback_param = dwc->cdesc->period_callback_param;
if (callback)
callback(callback_param);
}
if (unlikely(status_err & dwc->mask) ||
unlikely(status_xfer & dwc->mask)) {
int i;
dev_err(chan2dev(&dwc->chan), "cyclic DMA unexpected %s "
"interrupt, stopping DMA transfer\n",
status_xfer ? "xfer" : "error");
spin_lock_irqsave(&dwc->lock, flags);
dwc_dump_chan_regs(dwc);
dwc_chan_disable(dw, dwc);
channel_writel(dwc, LLP, 0);
channel_writel(dwc, CTL_LO, 0);
channel_writel(dwc, CTL_HI, 0);
dma_writel(dw, CLEAR.ERROR, dwc->mask);
dma_writel(dw, CLEAR.XFER, dwc->mask);
for (i = 0; i < dwc->cdesc->periods; i++)
dwc_dump_lli(dwc, &dwc->cdesc->desc[i]->lli);
spin_unlock_irqrestore(&dwc->lock, flags);
}
}
static void dw_dma_tasklet(unsigned long data)
{
struct dw_dma *dw = (struct dw_dma *)data;
struct dw_dma_chan *dwc;
u32 status_xfer;
u32 status_err;
int i;
status_xfer = dma_readl(dw, RAW.XFER);
status_err = dma_readl(dw, RAW.ERROR);
dev_vdbg(dw->dma.dev, "%s: status_err=%x\n", __func__, status_err);
for (i = 0; i < dw->dma.chancnt; i++) {
dwc = &dw->chan[i];
if (test_bit(DW_DMA_IS_CYCLIC, &dwc->flags))
dwc_handle_cyclic(dw, dwc, status_err, status_xfer);
else if (status_err & (1 << i))
dwc_handle_error(dw, dwc);
else if (status_xfer & (1 << i))
dwc_scan_descriptors(dw, dwc);
}
channel_set_bit(dw, MASK.XFER, dw->all_chan_mask);
channel_set_bit(dw, MASK.ERROR, dw->all_chan_mask);
}
static irqreturn_t dw_dma_interrupt(int irq, void *dev_id)
{
struct dw_dma *dw = dev_id;
u32 status;
dev_vdbg(dw->dma.dev, "%s: status=0x%x\n", __func__,
dma_readl(dw, STATUS_INT));
channel_clear_bit(dw, MASK.XFER, dw->all_chan_mask);
channel_clear_bit(dw, MASK.ERROR, dw->all_chan_mask);
status = dma_readl(dw, STATUS_INT);
if (status) {
dev_err(dw->dma.dev,
"BUG: Unexpected interrupts pending: 0x%x\n",
status);
channel_clear_bit(dw, MASK.XFER, (1 << 8) - 1);
channel_clear_bit(dw, MASK.SRC_TRAN, (1 << 8) - 1);
channel_clear_bit(dw, MASK.DST_TRAN, (1 << 8) - 1);
channel_clear_bit(dw, MASK.ERROR, (1 << 8) - 1);
}
tasklet_schedule(&dw->tasklet);
return IRQ_HANDLED;
}
static dma_cookie_t dwc_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct dw_desc *desc = txd_to_dw_desc(tx);
struct dw_dma_chan *dwc = to_dw_dma_chan(tx->chan);
dma_cookie_t cookie;
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
cookie = dma_cookie_assign(tx);
if (list_empty(&dwc->active_list)) {
dev_vdbg(chan2dev(tx->chan), "%s: started %u\n", __func__,
desc->txd.cookie);
list_add_tail(&desc->desc_node, &dwc->active_list);
dwc_dostart(dwc, dwc_first_active(dwc));
} else {
dev_vdbg(chan2dev(tx->chan), "%s: queued %u\n", __func__,
desc->txd.cookie);
list_add_tail(&desc->desc_node, &dwc->queue);
}
spin_unlock_irqrestore(&dwc->lock, flags);
return cookie;
}
static struct dma_async_tx_descriptor *
dwc_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long flags)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
struct dw_desc *desc;
struct dw_desc *first;
struct dw_desc *prev;
size_t xfer_count;
size_t offset;
unsigned int src_width;
unsigned int dst_width;
u32 ctllo;
dev_vdbg(chan2dev(chan),
"%s: d0x%llx s0x%llx l0x%zx f0x%lx\n", __func__,
(unsigned long long)dest, (unsigned long long)src,
len, flags);
if (unlikely(!len)) {
dev_dbg(chan2dev(chan), "%s: length is zero!\n", __func__);
return NULL;
}
src_width = dst_width = dwc_fast_fls(src | dest | len);
ctllo = DWC_DEFAULT_CTLLO(chan)
| DWC_CTLL_DST_WIDTH(dst_width)
| DWC_CTLL_SRC_WIDTH(src_width)
| DWC_CTLL_DST_INC
| DWC_CTLL_SRC_INC
| DWC_CTLL_FC_M2M;
prev = first = NULL;
for (offset = 0; offset < len; offset += xfer_count << src_width) {
xfer_count = min_t(size_t, (len - offset) >> src_width,
DWC_MAX_COUNT);
desc = dwc_desc_get(dwc);
if (!desc)
goto err_desc_get;
desc->lli.sar = src + offset;
desc->lli.dar = dest + offset;
desc->lli.ctllo = ctllo;
desc->lli.ctlhi = xfer_count;
if (!first) {
first = desc;
} else {
prev->lli.llp = desc->txd.phys;
dma_sync_single_for_device(chan2parent(chan),
prev->txd.phys, sizeof(prev->lli),
DMA_TO_DEVICE);
list_add_tail(&desc->desc_node,
&first->tx_list);
}
prev = desc;
}
if (flags & DMA_PREP_INTERRUPT)
prev->lli.ctllo |= DWC_CTLL_INT_EN;
prev->lli.llp = 0;
dma_sync_single_for_device(chan2parent(chan),
prev->txd.phys, sizeof(prev->lli),
DMA_TO_DEVICE);
first->txd.flags = flags;
first->len = len;
return &first->txd;
err_desc_get:
dwc_desc_put(dwc, first);
return NULL;
}
static struct dma_async_tx_descriptor *
dwc_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
struct dw_dma_slave *dws = chan->private;
struct dma_slave_config *sconfig = &dwc->dma_sconfig;
struct dw_desc *prev;
struct dw_desc *first;
u32 ctllo;
dma_addr_t reg;
unsigned int reg_width;
unsigned int mem_width;
unsigned int i;
struct scatterlist *sg;
size_t total_len = 0;
dev_vdbg(chan2dev(chan), "%s\n", __func__);
if (unlikely(!dws || !sg_len))
return NULL;
prev = first = NULL;
switch (direction) {
case DMA_MEM_TO_DEV:
reg_width = __fls(sconfig->dst_addr_width);
reg = sconfig->dst_addr;
ctllo = (DWC_DEFAULT_CTLLO(chan)
| DWC_CTLL_DST_WIDTH(reg_width)
| DWC_CTLL_DST_FIX
| DWC_CTLL_SRC_INC);
ctllo |= sconfig->device_fc ? DWC_CTLL_FC(DW_DMA_FC_P_M2P) :
DWC_CTLL_FC(DW_DMA_FC_D_M2P);
for_each_sg(sgl, sg, sg_len, i) {
struct dw_desc *desc;
u32 len, dlen, mem;
mem = sg_dma_address(sg);
len = sg_dma_len(sg);
mem_width = dwc_fast_fls(mem | len);
slave_sg_todev_fill_desc:
desc = dwc_desc_get(dwc);
if (!desc) {
dev_err(chan2dev(chan),
"not enough descriptors available\n");
goto err_desc_get;
}
desc->lli.sar = mem;
desc->lli.dar = reg;
desc->lli.ctllo = ctllo | DWC_CTLL_SRC_WIDTH(mem_width);
if ((len >> mem_width) > DWC_MAX_COUNT) {
dlen = DWC_MAX_COUNT << mem_width;
mem += dlen;
len -= dlen;
} else {
dlen = len;
len = 0;
}
desc->lli.ctlhi = dlen >> mem_width;
if (!first) {
first = desc;
} else {
prev->lli.llp = desc->txd.phys;
dma_sync_single_for_device(chan2parent(chan),
prev->txd.phys,
sizeof(prev->lli),
DMA_TO_DEVICE);
list_add_tail(&desc->desc_node,
&first->tx_list);
}
prev = desc;
total_len += dlen;
if (len)
goto slave_sg_todev_fill_desc;
}
break;
case DMA_DEV_TO_MEM:
reg_width = __fls(sconfig->src_addr_width);
reg = sconfig->src_addr;
ctllo = (DWC_DEFAULT_CTLLO(chan)
| DWC_CTLL_SRC_WIDTH(reg_width)
| DWC_CTLL_DST_INC
| DWC_CTLL_SRC_FIX);
ctllo |= sconfig->device_fc ? DWC_CTLL_FC(DW_DMA_FC_P_P2M) :
DWC_CTLL_FC(DW_DMA_FC_D_P2M);
for_each_sg(sgl, sg, sg_len, i) {
struct dw_desc *desc;
u32 len, dlen, mem;
mem = sg_dma_address(sg);
len = sg_dma_len(sg);
mem_width = dwc_fast_fls(mem | len);
slave_sg_fromdev_fill_desc:
desc = dwc_desc_get(dwc);
if (!desc) {
dev_err(chan2dev(chan),
"not enough descriptors available\n");
goto err_desc_get;
}
desc->lli.sar = reg;
desc->lli.dar = mem;
desc->lli.ctllo = ctllo | DWC_CTLL_DST_WIDTH(mem_width);
if ((len >> reg_width) > DWC_MAX_COUNT) {
dlen = DWC_MAX_COUNT << reg_width;
mem += dlen;
len -= dlen;
} else {
dlen = len;
len = 0;
}
desc->lli.ctlhi = dlen >> reg_width;
if (!first) {
first = desc;
} else {
prev->lli.llp = desc->txd.phys;
dma_sync_single_for_device(chan2parent(chan),
prev->txd.phys,
sizeof(prev->lli),
DMA_TO_DEVICE);
list_add_tail(&desc->desc_node,
&first->tx_list);
}
prev = desc;
total_len += dlen;
if (len)
goto slave_sg_fromdev_fill_desc;
}
break;
default:
return NULL;
}
if (flags & DMA_PREP_INTERRUPT)
prev->lli.ctllo |= DWC_CTLL_INT_EN;
prev->lli.llp = 0;
dma_sync_single_for_device(chan2parent(chan),
prev->txd.phys, sizeof(prev->lli),
DMA_TO_DEVICE);
first->len = total_len;
return &first->txd;
err_desc_get:
dwc_desc_put(dwc, first);
return NULL;
}
static inline void convert_burst(u32 *maxburst)
{
if (*maxburst > 1)
*maxburst = fls(*maxburst) - 2;
else
*maxburst = 0;
}
static int
set_runtime_config(struct dma_chan *chan, struct dma_slave_config *sconfig)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
if (!chan->private)
return -EINVAL;
memcpy(&dwc->dma_sconfig, sconfig, sizeof(*sconfig));
convert_burst(&dwc->dma_sconfig.src_maxburst);
convert_burst(&dwc->dma_sconfig.dst_maxburst);
return 0;
}
static int dwc_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
struct dw_dma *dw = to_dw_dma(chan->device);
struct dw_desc *desc, *_desc;
unsigned long flags;
u32 cfglo;
LIST_HEAD(list);
if (cmd == DMA_PAUSE) {
spin_lock_irqsave(&dwc->lock, flags);
cfglo = channel_readl(dwc, CFG_LO);
channel_writel(dwc, CFG_LO, cfglo | DWC_CFGL_CH_SUSP);
while (!(channel_readl(dwc, CFG_LO) & DWC_CFGL_FIFO_EMPTY))
cpu_relax();
dwc->paused = true;
spin_unlock_irqrestore(&dwc->lock, flags);
} else if (cmd == DMA_RESUME) {
if (!dwc->paused)
return 0;
spin_lock_irqsave(&dwc->lock, flags);
cfglo = channel_readl(dwc, CFG_LO);
channel_writel(dwc, CFG_LO, cfglo & ~DWC_CFGL_CH_SUSP);
dwc->paused = false;
spin_unlock_irqrestore(&dwc->lock, flags);
} else if (cmd == DMA_TERMINATE_ALL) {
spin_lock_irqsave(&dwc->lock, flags);
dwc_chan_disable(dw, dwc);
dwc->paused = false;
list_splice_init(&dwc->queue, &list);
list_splice_init(&dwc->active_list, &list);
spin_unlock_irqrestore(&dwc->lock, flags);
list_for_each_entry_safe(desc, _desc, &list, desc_node)
dwc_descriptor_complete(dwc, desc, false);
} else if (cmd == DMA_SLAVE_CONFIG) {
return set_runtime_config(chan, (struct dma_slave_config *)arg);
} else {
return -ENXIO;
}
return 0;
}
static enum dma_status
dwc_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
enum dma_status ret;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret != DMA_SUCCESS) {
dwc_scan_descriptors(to_dw_dma(chan->device), dwc);
ret = dma_cookie_status(chan, cookie, txstate);
}
if (ret != DMA_SUCCESS)
dma_set_residue(txstate, dwc_first_active(dwc)->len);
if (dwc->paused)
return DMA_PAUSED;
return ret;
}
static void dwc_issue_pending(struct dma_chan *chan)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
if (!list_empty(&dwc->queue))
dwc_scan_descriptors(to_dw_dma(chan->device), dwc);
}
static int dwc_alloc_chan_resources(struct dma_chan *chan)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
struct dw_dma *dw = to_dw_dma(chan->device);
struct dw_desc *desc;
int i;
unsigned long flags;
dev_vdbg(chan2dev(chan), "%s\n", __func__);
if (dma_readl(dw, CH_EN) & dwc->mask) {
dev_dbg(chan2dev(chan), "DMA channel not idle?\n");
return -EIO;
}
dma_cookie_init(chan);
spin_lock_irqsave(&dwc->lock, flags);
i = dwc->descs_allocated;
while (dwc->descs_allocated < NR_DESCS_PER_CHANNEL) {
spin_unlock_irqrestore(&dwc->lock, flags);
desc = kzalloc(sizeof(struct dw_desc), GFP_KERNEL);
if (!desc) {
dev_info(chan2dev(chan),
"only allocated %d descriptors\n", i);
spin_lock_irqsave(&dwc->lock, flags);
break;
}
INIT_LIST_HEAD(&desc->tx_list);
dma_async_tx_descriptor_init(&desc->txd, chan);
desc->txd.tx_submit = dwc_tx_submit;
desc->txd.flags = DMA_CTRL_ACK;
desc->txd.phys = dma_map_single(chan2parent(chan), &desc->lli,
sizeof(desc->lli), DMA_TO_DEVICE);
dwc_desc_put(dwc, desc);
spin_lock_irqsave(&dwc->lock, flags);
i = ++dwc->descs_allocated;
}
spin_unlock_irqrestore(&dwc->lock, flags);
dev_dbg(chan2dev(chan), "%s: allocated %d descriptors\n", __func__, i);
return i;
}
static void dwc_free_chan_resources(struct dma_chan *chan)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
struct dw_dma *dw = to_dw_dma(chan->device);
struct dw_desc *desc, *_desc;
unsigned long flags;
LIST_HEAD(list);
dev_dbg(chan2dev(chan), "%s: descs allocated=%u\n", __func__,
dwc->descs_allocated);
BUG_ON(!list_empty(&dwc->active_list));
BUG_ON(!list_empty(&dwc->queue));
BUG_ON(dma_readl(to_dw_dma(chan->device), CH_EN) & dwc->mask);
spin_lock_irqsave(&dwc->lock, flags);
list_splice_init(&dwc->free_list, &list);
dwc->descs_allocated = 0;
dwc->initialized = false;
channel_clear_bit(dw, MASK.XFER, dwc->mask);
channel_clear_bit(dw, MASK.ERROR, dwc->mask);
spin_unlock_irqrestore(&dwc->lock, flags);
list_for_each_entry_safe(desc, _desc, &list, desc_node) {
dev_vdbg(chan2dev(chan), " freeing descriptor %p\n", desc);
dma_unmap_single(chan2parent(chan), desc->txd.phys,
sizeof(desc->lli), DMA_TO_DEVICE);
kfree(desc);
}
dev_vdbg(chan2dev(chan), "%s: done\n", __func__);
}
int dw_dma_cyclic_start(struct dma_chan *chan)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
struct dw_dma *dw = to_dw_dma(dwc->chan.device);
unsigned long flags;
if (!test_bit(DW_DMA_IS_CYCLIC, &dwc->flags)) {
dev_err(chan2dev(&dwc->chan), "missing prep for cyclic DMA\n");
return -ENODEV;
}
spin_lock_irqsave(&dwc->lock, flags);
if (dma_readl(dw, CH_EN) & dwc->mask) {
dev_err(chan2dev(&dwc->chan),
"BUG: Attempted to start non-idle channel\n");
dwc_dump_chan_regs(dwc);
spin_unlock_irqrestore(&dwc->lock, flags);
return -EBUSY;
}
dma_writel(dw, CLEAR.ERROR, dwc->mask);
dma_writel(dw, CLEAR.XFER, dwc->mask);
channel_writel(dwc, LLP, dwc->cdesc->desc[0]->txd.phys);
channel_writel(dwc, CTL_LO, DWC_CTLL_LLP_D_EN | DWC_CTLL_LLP_S_EN);
channel_writel(dwc, CTL_HI, 0);
channel_set_bit(dw, CH_EN, dwc->mask);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
void dw_dma_cyclic_stop(struct dma_chan *chan)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
struct dw_dma *dw = to_dw_dma(dwc->chan.device);
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
dwc_chan_disable(dw, dwc);
spin_unlock_irqrestore(&dwc->lock, flags);
}
struct dw_cyclic_desc *dw_dma_cyclic_prep(struct dma_chan *chan,
dma_addr_t buf_addr, size_t buf_len, size_t period_len,
enum dma_transfer_direction direction)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
struct dma_slave_config *sconfig = &dwc->dma_sconfig;
struct dw_cyclic_desc *cdesc;
struct dw_cyclic_desc *retval = NULL;
struct dw_desc *desc;
struct dw_desc *last = NULL;
unsigned long was_cyclic;
unsigned int reg_width;
unsigned int periods;
unsigned int i;
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
if (!list_empty(&dwc->queue) || !list_empty(&dwc->active_list)) {
spin_unlock_irqrestore(&dwc->lock, flags);
dev_dbg(chan2dev(&dwc->chan),
"queue and/or active list are not empty\n");
return ERR_PTR(-EBUSY);
}
was_cyclic = test_and_set_bit(DW_DMA_IS_CYCLIC, &dwc->flags);
spin_unlock_irqrestore(&dwc->lock, flags);
if (was_cyclic) {
dev_dbg(chan2dev(&dwc->chan),
"channel already prepared for cyclic DMA\n");
return ERR_PTR(-EBUSY);
}
retval = ERR_PTR(-EINVAL);
if (direction == DMA_MEM_TO_DEV)
reg_width = __ffs(sconfig->dst_addr_width);
else
reg_width = __ffs(sconfig->src_addr_width);
periods = buf_len / period_len;
if (period_len > (DWC_MAX_COUNT << reg_width))
goto out_err;
if (unlikely(period_len & ((1 << reg_width) - 1)))
goto out_err;
if (unlikely(buf_addr & ((1 << reg_width) - 1)))
goto out_err;
if (unlikely(!(direction & (DMA_MEM_TO_DEV | DMA_DEV_TO_MEM))))
goto out_err;
retval = ERR_PTR(-ENOMEM);
if (periods > NR_DESCS_PER_CHANNEL)
goto out_err;
cdesc = kzalloc(sizeof(struct dw_cyclic_desc), GFP_KERNEL);
if (!cdesc)
goto out_err;
cdesc->desc = kzalloc(sizeof(struct dw_desc *) * periods, GFP_KERNEL);
if (!cdesc->desc)
goto out_err_alloc;
for (i = 0; i < periods; i++) {
desc = dwc_desc_get(dwc);
if (!desc)
goto out_err_desc_get;
switch (direction) {
case DMA_MEM_TO_DEV:
desc->lli.dar = sconfig->dst_addr;
desc->lli.sar = buf_addr + (period_len * i);
desc->lli.ctllo = (DWC_DEFAULT_CTLLO(chan)
| DWC_CTLL_DST_WIDTH(reg_width)
| DWC_CTLL_SRC_WIDTH(reg_width)
| DWC_CTLL_DST_FIX
| DWC_CTLL_SRC_INC
| DWC_CTLL_INT_EN);
desc->lli.ctllo |= sconfig->device_fc ?
DWC_CTLL_FC(DW_DMA_FC_P_M2P) :
DWC_CTLL_FC(DW_DMA_FC_D_M2P);
break;
case DMA_DEV_TO_MEM:
desc->lli.dar = buf_addr + (period_len * i);
desc->lli.sar = sconfig->src_addr;
desc->lli.ctllo = (DWC_DEFAULT_CTLLO(chan)
| DWC_CTLL_SRC_WIDTH(reg_width)
| DWC_CTLL_DST_WIDTH(reg_width)
| DWC_CTLL_DST_INC
| DWC_CTLL_SRC_FIX
| DWC_CTLL_INT_EN);
desc->lli.ctllo |= sconfig->device_fc ?
DWC_CTLL_FC(DW_DMA_FC_P_P2M) :
DWC_CTLL_FC(DW_DMA_FC_D_P2M);
break;
default:
break;
}
desc->lli.ctlhi = (period_len >> reg_width);
cdesc->desc[i] = desc;
if (last) {
last->lli.llp = desc->txd.phys;
dma_sync_single_for_device(chan2parent(chan),
last->txd.phys, sizeof(last->lli),
DMA_TO_DEVICE);
}
last = desc;
}
last->lli.llp = cdesc->desc[0]->txd.phys;
dma_sync_single_for_device(chan2parent(chan), last->txd.phys,
sizeof(last->lli), DMA_TO_DEVICE);
dev_dbg(chan2dev(&dwc->chan), "cyclic prepared buf 0x%llx len %zu "
"period %zu periods %d\n", (unsigned long long)buf_addr,
buf_len, period_len, periods);
cdesc->periods = periods;
dwc->cdesc = cdesc;
return cdesc;
out_err_desc_get:
while (i--)
dwc_desc_put(dwc, cdesc->desc[i]);
out_err_alloc:
kfree(cdesc);
out_err:
clear_bit(DW_DMA_IS_CYCLIC, &dwc->flags);
return (struct dw_cyclic_desc *)retval;
}
void dw_dma_cyclic_free(struct dma_chan *chan)
{
struct dw_dma_chan *dwc = to_dw_dma_chan(chan);
struct dw_dma *dw = to_dw_dma(dwc->chan.device);
struct dw_cyclic_desc *cdesc = dwc->cdesc;
int i;
unsigned long flags;
dev_dbg(chan2dev(&dwc->chan), "%s\n", __func__);
if (!cdesc)
return;
spin_lock_irqsave(&dwc->lock, flags);
dwc_chan_disable(dw, dwc);
dma_writel(dw, CLEAR.ERROR, dwc->mask);
dma_writel(dw, CLEAR.XFER, dwc->mask);
spin_unlock_irqrestore(&dwc->lock, flags);
for (i = 0; i < cdesc->periods; i++)
dwc_desc_put(dwc, cdesc->desc[i]);
kfree(cdesc->desc);
kfree(cdesc);
clear_bit(DW_DMA_IS_CYCLIC, &dwc->flags);
}
static void dw_dma_off(struct dw_dma *dw)
{
int i;
dma_writel(dw, CFG, 0);
channel_clear_bit(dw, MASK.XFER, dw->all_chan_mask);
channel_clear_bit(dw, MASK.SRC_TRAN, dw->all_chan_mask);
channel_clear_bit(dw, MASK.DST_TRAN, dw->all_chan_mask);
channel_clear_bit(dw, MASK.ERROR, dw->all_chan_mask);
while (dma_readl(dw, CFG) & DW_CFG_DMA_EN)
cpu_relax();
for (i = 0; i < dw->dma.chancnt; i++)
dw->chan[i].initialized = false;
}
static int __devinit dw_probe(struct platform_device *pdev)
{
struct dw_dma_platform_data *pdata;
struct resource *io;
struct dw_dma *dw;
size_t size;
int irq;
int err;
int i;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata || pdata->nr_channels > DW_DMA_MAX_NR_CHANNELS)
return -EINVAL;
io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!io)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
size = sizeof(struct dw_dma);
size += pdata->nr_channels * sizeof(struct dw_dma_chan);
dw = kzalloc(size, GFP_KERNEL);
if (!dw)
return -ENOMEM;
if (!request_mem_region(io->start, DW_REGLEN, pdev->dev.driver->name)) {
err = -EBUSY;
goto err_kfree;
}
dw->regs = ioremap(io->start, DW_REGLEN);
if (!dw->regs) {
err = -ENOMEM;
goto err_release_r;
}
dw->clk = clk_get(&pdev->dev, "hclk");
if (IS_ERR(dw->clk)) {
err = PTR_ERR(dw->clk);
goto err_clk;
}
clk_prepare_enable(dw->clk);
dw->all_chan_mask = (1 << pdata->nr_channels) - 1;
dw_dma_off(dw);
channel_clear_bit(dw, MASK.BLOCK, dw->all_chan_mask);
err = request_irq(irq, dw_dma_interrupt, 0, "dw_dmac", dw);
if (err)
goto err_irq;
platform_set_drvdata(pdev, dw);
tasklet_init(&dw->tasklet, dw_dma_tasklet, (unsigned long)dw);
INIT_LIST_HEAD(&dw->dma.channels);
for (i = 0; i < pdata->nr_channels; i++) {
struct dw_dma_chan *dwc = &dw->chan[i];
dwc->chan.device = &dw->dma;
dma_cookie_init(&dwc->chan);
if (pdata->chan_allocation_order == CHAN_ALLOCATION_ASCENDING)
list_add_tail(&dwc->chan.device_node,
&dw->dma.channels);
else
list_add(&dwc->chan.device_node, &dw->dma.channels);
if (pdata->chan_priority == CHAN_PRIORITY_ASCENDING)
dwc->priority = pdata->nr_channels - i - 1;
else
dwc->priority = i;
dwc->ch_regs = &__dw_regs(dw)->CHAN[i];
spin_lock_init(&dwc->lock);
dwc->mask = 1 << i;
INIT_LIST_HEAD(&dwc->active_list);
INIT_LIST_HEAD(&dwc->queue);
INIT_LIST_HEAD(&dwc->free_list);
channel_clear_bit(dw, CH_EN, dwc->mask);
}
dma_writel(dw, CLEAR.XFER, dw->all_chan_mask);
dma_writel(dw, CLEAR.BLOCK, dw->all_chan_mask);
dma_writel(dw, CLEAR.SRC_TRAN, dw->all_chan_mask);
dma_writel(dw, CLEAR.DST_TRAN, dw->all_chan_mask);
dma_writel(dw, CLEAR.ERROR, dw->all_chan_mask);
dma_cap_set(DMA_MEMCPY, dw->dma.cap_mask);
dma_cap_set(DMA_SLAVE, dw->dma.cap_mask);
if (pdata->is_private)
dma_cap_set(DMA_PRIVATE, dw->dma.cap_mask);
dw->dma.dev = &pdev->dev;
dw->dma.device_alloc_chan_resources = dwc_alloc_chan_resources;
dw->dma.device_free_chan_resources = dwc_free_chan_resources;
dw->dma.device_prep_dma_memcpy = dwc_prep_dma_memcpy;
dw->dma.device_prep_slave_sg = dwc_prep_slave_sg;
dw->dma.device_control = dwc_control;
dw->dma.device_tx_status = dwc_tx_status;
dw->dma.device_issue_pending = dwc_issue_pending;
dma_writel(dw, CFG, DW_CFG_DMA_EN);
printk(KERN_INFO "%s: DesignWare DMA Controller, %d channels\n",
dev_name(&pdev->dev), pdata->nr_channels);
dma_async_device_register(&dw->dma);
return 0;
err_irq:
clk_disable_unprepare(dw->clk);
clk_put(dw->clk);
err_clk:
iounmap(dw->regs);
dw->regs = NULL;
err_release_r:
release_resource(io);
err_kfree:
kfree(dw);
return err;
}
static int __devexit dw_remove(struct platform_device *pdev)
{
struct dw_dma *dw = platform_get_drvdata(pdev);
struct dw_dma_chan *dwc, *_dwc;
struct resource *io;
dw_dma_off(dw);
dma_async_device_unregister(&dw->dma);
free_irq(platform_get_irq(pdev, 0), dw);
tasklet_kill(&dw->tasklet);
list_for_each_entry_safe(dwc, _dwc, &dw->dma.channels,
chan.device_node) {
list_del(&dwc->chan.device_node);
channel_clear_bit(dw, CH_EN, dwc->mask);
}
clk_disable_unprepare(dw->clk);
clk_put(dw->clk);
iounmap(dw->regs);
dw->regs = NULL;
io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(io->start, DW_REGLEN);
kfree(dw);
return 0;
}
static void dw_shutdown(struct platform_device *pdev)
{
struct dw_dma *dw = platform_get_drvdata(pdev);
dw_dma_off(platform_get_drvdata(pdev));
clk_disable_unprepare(dw->clk);
}
static int dw_suspend_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dw_dma *dw = platform_get_drvdata(pdev);
dw_dma_off(platform_get_drvdata(pdev));
clk_disable_unprepare(dw->clk);
return 0;
}
static int dw_resume_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct dw_dma *dw = platform_get_drvdata(pdev);
clk_prepare_enable(dw->clk);
dma_writel(dw, CFG, DW_CFG_DMA_EN);
return 0;
}
static int __init dw_init(void)
{
return platform_driver_probe(&dw_driver, dw_probe);
}
static void __exit dw_exit(void)
{
platform_driver_unregister(&dw_driver);
}
