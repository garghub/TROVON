static struct at_desc *atc_first_active(struct at_dma_chan *atchan)
{
return list_first_entry(&atchan->active_list,
struct at_desc, desc_node);
}
static struct at_desc *atc_first_queued(struct at_dma_chan *atchan)
{
return list_first_entry(&atchan->queue,
struct at_desc, desc_node);
}
static struct at_desc *atc_alloc_descriptor(struct dma_chan *chan,
gfp_t gfp_flags)
{
struct at_desc *desc = NULL;
struct at_dma *atdma = to_at_dma(chan->device);
dma_addr_t phys;
desc = dma_pool_alloc(atdma->dma_desc_pool, gfp_flags, &phys);
if (desc) {
memset(desc, 0, sizeof(struct at_desc));
INIT_LIST_HEAD(&desc->tx_list);
dma_async_tx_descriptor_init(&desc->txd, chan);
desc->txd.flags = DMA_CTRL_ACK;
desc->txd.tx_submit = atc_tx_submit;
desc->txd.phys = phys;
}
return desc;
}
static struct at_desc *atc_desc_get(struct at_dma_chan *atchan)
{
struct at_desc *desc, *_desc;
struct at_desc *ret = NULL;
unsigned long flags;
unsigned int i = 0;
LIST_HEAD(tmp_list);
spin_lock_irqsave(&atchan->lock, flags);
list_for_each_entry_safe(desc, _desc, &atchan->free_list, desc_node) {
i++;
if (async_tx_test_ack(&desc->txd)) {
list_del(&desc->desc_node);
ret = desc;
break;
}
dev_dbg(chan2dev(&atchan->chan_common),
"desc %p not ACKed\n", desc);
}
spin_unlock_irqrestore(&atchan->lock, flags);
dev_vdbg(chan2dev(&atchan->chan_common),
"scanned %u descriptors on freelist\n", i);
if (!ret) {
ret = atc_alloc_descriptor(&atchan->chan_common, GFP_ATOMIC);
if (ret) {
spin_lock_irqsave(&atchan->lock, flags);
atchan->descs_allocated++;
spin_unlock_irqrestore(&atchan->lock, flags);
} else {
dev_err(chan2dev(&atchan->chan_common),
"not enough descriptors available\n");
}
}
return ret;
}
static void atc_desc_put(struct at_dma_chan *atchan, struct at_desc *desc)
{
if (desc) {
struct at_desc *child;
unsigned long flags;
spin_lock_irqsave(&atchan->lock, flags);
list_for_each_entry(child, &desc->tx_list, desc_node)
dev_vdbg(chan2dev(&atchan->chan_common),
"moving child desc %p to freelist\n",
child);
list_splice_init(&desc->tx_list, &atchan->free_list);
dev_vdbg(chan2dev(&atchan->chan_common),
"moving desc %p to freelist\n", desc);
list_add(&desc->desc_node, &atchan->free_list);
spin_unlock_irqrestore(&atchan->lock, flags);
}
}
static void atc_desc_chain(struct at_desc **first, struct at_desc **prev,
struct at_desc *desc)
{
if (!(*first)) {
*first = desc;
} else {
(*prev)->lli.dscr = desc->txd.phys;
list_add_tail(&desc->desc_node,
&(*first)->tx_list);
}
*prev = desc;
}
static void atc_dostart(struct at_dma_chan *atchan, struct at_desc *first)
{
struct at_dma *atdma = to_at_dma(atchan->chan_common.device);
if (atc_chan_is_enabled(atchan)) {
dev_err(chan2dev(&atchan->chan_common),
"BUG: Attempted to start non-idle channel\n");
dev_err(chan2dev(&atchan->chan_common),
" channel: s0x%x d0x%x ctrl0x%x:0x%x l0x%x\n",
channel_readl(atchan, SADDR),
channel_readl(atchan, DADDR),
channel_readl(atchan, CTRLA),
channel_readl(atchan, CTRLB),
channel_readl(atchan, DSCR));
return;
}
vdbg_dump_regs(atchan);
channel_writel(atchan, SADDR, 0);
channel_writel(atchan, DADDR, 0);
channel_writel(atchan, CTRLA, 0);
channel_writel(atchan, CTRLB, 0);
channel_writel(atchan, DSCR, first->txd.phys);
dma_writel(atdma, CHER, atchan->mask);
vdbg_dump_regs(atchan);
}
static void
atc_chain_complete(struct at_dma_chan *atchan, struct at_desc *desc)
{
struct dma_async_tx_descriptor *txd = &desc->txd;
dev_vdbg(chan2dev(&atchan->chan_common),
"descriptor %u complete\n", txd->cookie);
if (!atc_chan_is_cyclic(atchan))
dma_cookie_complete(txd);
list_splice_init(&desc->tx_list, &atchan->free_list);
list_move(&desc->desc_node, &atchan->free_list);
if (!atchan->chan_common.private) {
struct device *parent = chan2parent(&atchan->chan_common);
if (!(txd->flags & DMA_COMPL_SKIP_DEST_UNMAP)) {
if (txd->flags & DMA_COMPL_DEST_UNMAP_SINGLE)
dma_unmap_single(parent,
desc->lli.daddr,
desc->len, DMA_FROM_DEVICE);
else
dma_unmap_page(parent,
desc->lli.daddr,
desc->len, DMA_FROM_DEVICE);
}
if (!(txd->flags & DMA_COMPL_SKIP_SRC_UNMAP)) {
if (txd->flags & DMA_COMPL_SRC_UNMAP_SINGLE)
dma_unmap_single(parent,
desc->lli.saddr,
desc->len, DMA_TO_DEVICE);
else
dma_unmap_page(parent,
desc->lli.saddr,
desc->len, DMA_TO_DEVICE);
}
}
if (!atc_chan_is_cyclic(atchan)) {
dma_async_tx_callback callback = txd->callback;
void *param = txd->callback_param;
if (callback)
callback(param);
}
dma_run_dependencies(txd);
}
static void atc_complete_all(struct at_dma_chan *atchan)
{
struct at_desc *desc, *_desc;
LIST_HEAD(list);
dev_vdbg(chan2dev(&atchan->chan_common), "complete all\n");
BUG_ON(atc_chan_is_enabled(atchan));
if (!list_empty(&atchan->queue))
atc_dostart(atchan, atc_first_queued(atchan));
list_splice_init(&atchan->active_list, &list);
list_splice_init(&atchan->queue, &atchan->active_list);
list_for_each_entry_safe(desc, _desc, &list, desc_node)
atc_chain_complete(atchan, desc);
}
static void atc_cleanup_descriptors(struct at_dma_chan *atchan)
{
struct at_desc *desc, *_desc;
struct at_desc *child;
dev_vdbg(chan2dev(&atchan->chan_common), "cleanup descriptors\n");
list_for_each_entry_safe(desc, _desc, &atchan->active_list, desc_node) {
if (!(desc->lli.ctrla & ATC_DONE))
return;
list_for_each_entry(child, &desc->tx_list, desc_node)
if (!(child->lli.ctrla & ATC_DONE))
return;
atc_chain_complete(atchan, desc);
}
}
static void atc_advance_work(struct at_dma_chan *atchan)
{
dev_vdbg(chan2dev(&atchan->chan_common), "advance_work\n");
if (list_empty(&atchan->active_list) ||
list_is_singular(&atchan->active_list)) {
atc_complete_all(atchan);
} else {
atc_chain_complete(atchan, atc_first_active(atchan));
atc_dostart(atchan, atc_first_active(atchan));
}
}
static void atc_handle_error(struct at_dma_chan *atchan)
{
struct at_desc *bad_desc;
struct at_desc *child;
bad_desc = atc_first_active(atchan);
list_del_init(&bad_desc->desc_node);
list_splice_init(&atchan->queue, atchan->active_list.prev);
if (!list_empty(&atchan->active_list))
atc_dostart(atchan, atc_first_active(atchan));
dev_crit(chan2dev(&atchan->chan_common),
"Bad descriptor submitted for DMA!\n");
dev_crit(chan2dev(&atchan->chan_common),
" cookie: %d\n", bad_desc->txd.cookie);
atc_dump_lli(atchan, &bad_desc->lli);
list_for_each_entry(child, &bad_desc->tx_list, desc_node)
atc_dump_lli(atchan, &child->lli);
atc_chain_complete(atchan, bad_desc);
}
static void atc_handle_cyclic(struct at_dma_chan *atchan)
{
struct at_desc *first = atc_first_active(atchan);
struct dma_async_tx_descriptor *txd = &first->txd;
dma_async_tx_callback callback = txd->callback;
void *param = txd->callback_param;
dev_vdbg(chan2dev(&atchan->chan_common),
"new cyclic period llp 0x%08x\n",
channel_readl(atchan, DSCR));
if (callback)
callback(param);
}
static void atc_tasklet(unsigned long data)
{
struct at_dma_chan *atchan = (struct at_dma_chan *)data;
unsigned long flags;
spin_lock_irqsave(&atchan->lock, flags);
if (test_and_clear_bit(ATC_IS_ERROR, &atchan->status))
atc_handle_error(atchan);
else if (atc_chan_is_cyclic(atchan))
atc_handle_cyclic(atchan);
else
atc_advance_work(atchan);
spin_unlock_irqrestore(&atchan->lock, flags);
}
static irqreturn_t at_dma_interrupt(int irq, void *dev_id)
{
struct at_dma *atdma = (struct at_dma *)dev_id;
struct at_dma_chan *atchan;
int i;
u32 status, pending, imr;
int ret = IRQ_NONE;
do {
imr = dma_readl(atdma, EBCIMR);
status = dma_readl(atdma, EBCISR);
pending = status & imr;
if (!pending)
break;
dev_vdbg(atdma->dma_common.dev,
"interrupt: status = 0x%08x, 0x%08x, 0x%08x\n",
status, imr, pending);
for (i = 0; i < atdma->dma_common.chancnt; i++) {
atchan = &atdma->chan[i];
if (pending & (AT_DMA_BTC(i) | AT_DMA_ERR(i))) {
if (pending & AT_DMA_ERR(i)) {
dma_writel(atdma, CHDR,
AT_DMA_RES(i) | atchan->mask);
set_bit(ATC_IS_ERROR, &atchan->status);
}
tasklet_schedule(&atchan->tasklet);
ret = IRQ_HANDLED;
}
}
} while (pending);
return ret;
}
static dma_cookie_t atc_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct at_desc *desc = txd_to_at_desc(tx);
struct at_dma_chan *atchan = to_at_dma_chan(tx->chan);
dma_cookie_t cookie;
unsigned long flags;
spin_lock_irqsave(&atchan->lock, flags);
cookie = dma_cookie_assign(tx);
if (list_empty(&atchan->active_list)) {
dev_vdbg(chan2dev(tx->chan), "tx_submit: started %u\n",
desc->txd.cookie);
atc_dostart(atchan, desc);
list_add_tail(&desc->desc_node, &atchan->active_list);
} else {
dev_vdbg(chan2dev(tx->chan), "tx_submit: queued %u\n",
desc->txd.cookie);
list_add_tail(&desc->desc_node, &atchan->queue);
}
spin_unlock_irqrestore(&atchan->lock, flags);
return cookie;
}
static struct dma_async_tx_descriptor *
atc_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long flags)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
struct at_desc *desc = NULL;
struct at_desc *first = NULL;
struct at_desc *prev = NULL;
size_t xfer_count;
size_t offset;
unsigned int src_width;
unsigned int dst_width;
u32 ctrla;
u32 ctrlb;
dev_vdbg(chan2dev(chan), "prep_dma_memcpy: d0x%x s0x%x l0x%zx f0x%lx\n",
dest, src, len, flags);
if (unlikely(!len)) {
dev_dbg(chan2dev(chan), "prep_dma_memcpy: length is zero!\n");
return NULL;
}
ctrla = ATC_DEFAULT_CTRLA;
ctrlb = ATC_DEFAULT_CTRLB | ATC_IEN
| ATC_SRC_ADDR_MODE_INCR
| ATC_DST_ADDR_MODE_INCR
| ATC_FC_MEM2MEM;
if (!((src | dest | len) & 3)) {
ctrla |= ATC_SRC_WIDTH_WORD | ATC_DST_WIDTH_WORD;
src_width = dst_width = 2;
} else if (!((src | dest | len) & 1)) {
ctrla |= ATC_SRC_WIDTH_HALFWORD | ATC_DST_WIDTH_HALFWORD;
src_width = dst_width = 1;
} else {
ctrla |= ATC_SRC_WIDTH_BYTE | ATC_DST_WIDTH_BYTE;
src_width = dst_width = 0;
}
for (offset = 0; offset < len; offset += xfer_count << src_width) {
xfer_count = min_t(size_t, (len - offset) >> src_width,
ATC_BTSIZE_MAX);
desc = atc_desc_get(atchan);
if (!desc)
goto err_desc_get;
desc->lli.saddr = src + offset;
desc->lli.daddr = dest + offset;
desc->lli.ctrla = ctrla | xfer_count;
desc->lli.ctrlb = ctrlb;
desc->txd.cookie = 0;
atc_desc_chain(&first, &prev, desc);
}
first->txd.cookie = -EBUSY;
first->len = len;
set_desc_eol(desc);
first->txd.flags = flags;
return &first->txd;
err_desc_get:
atc_desc_put(atchan, first);
return NULL;
}
static struct dma_async_tx_descriptor *
atc_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
struct at_dma_slave *atslave = chan->private;
struct dma_slave_config *sconfig = &atchan->dma_sconfig;
struct at_desc *first = NULL;
struct at_desc *prev = NULL;
u32 ctrla;
u32 ctrlb;
dma_addr_t reg;
unsigned int reg_width;
unsigned int mem_width;
unsigned int i;
struct scatterlist *sg;
size_t total_len = 0;
dev_vdbg(chan2dev(chan), "prep_slave_sg (%d): %s f0x%lx\n",
sg_len,
direction == DMA_MEM_TO_DEV ? "TO DEVICE" : "FROM DEVICE",
flags);
if (unlikely(!atslave || !sg_len)) {
dev_dbg(chan2dev(chan), "prep_dma_memcpy: length is zero!\n");
return NULL;
}
ctrla = ATC_DEFAULT_CTRLA | atslave->ctrla;
ctrlb = ATC_IEN;
switch (direction) {
case DMA_MEM_TO_DEV:
reg_width = convert_buswidth(sconfig->dst_addr_width);
ctrla |= ATC_DST_WIDTH(reg_width);
ctrlb |= ATC_DST_ADDR_MODE_FIXED
| ATC_SRC_ADDR_MODE_INCR
| ATC_FC_MEM2PER
| ATC_SIF(AT_DMA_MEM_IF) | ATC_DIF(AT_DMA_PER_IF);
reg = sconfig->dst_addr;
for_each_sg(sgl, sg, sg_len, i) {
struct at_desc *desc;
u32 len;
u32 mem;
desc = atc_desc_get(atchan);
if (!desc)
goto err_desc_get;
mem = sg_dma_address(sg);
len = sg_dma_len(sg);
mem_width = 2;
if (unlikely(mem & 3 || len & 3))
mem_width = 0;
desc->lli.saddr = mem;
desc->lli.daddr = reg;
desc->lli.ctrla = ctrla
| ATC_SRC_WIDTH(mem_width)
| len >> mem_width;
desc->lli.ctrlb = ctrlb;
atc_desc_chain(&first, &prev, desc);
total_len += len;
}
break;
case DMA_DEV_TO_MEM:
reg_width = convert_buswidth(sconfig->src_addr_width);
ctrla |= ATC_SRC_WIDTH(reg_width);
ctrlb |= ATC_DST_ADDR_MODE_INCR
| ATC_SRC_ADDR_MODE_FIXED
| ATC_FC_PER2MEM
| ATC_SIF(AT_DMA_PER_IF) | ATC_DIF(AT_DMA_MEM_IF);
reg = sconfig->src_addr;
for_each_sg(sgl, sg, sg_len, i) {
struct at_desc *desc;
u32 len;
u32 mem;
desc = atc_desc_get(atchan);
if (!desc)
goto err_desc_get;
mem = sg_dma_address(sg);
len = sg_dma_len(sg);
mem_width = 2;
if (unlikely(mem & 3 || len & 3))
mem_width = 0;
desc->lli.saddr = reg;
desc->lli.daddr = mem;
desc->lli.ctrla = ctrla
| ATC_DST_WIDTH(mem_width)
| len >> reg_width;
desc->lli.ctrlb = ctrlb;
atc_desc_chain(&first, &prev, desc);
total_len += len;
}
break;
default:
return NULL;
}
set_desc_eol(prev);
first->txd.cookie = -EBUSY;
first->len = total_len;
first->txd.flags = flags;
return &first->txd;
err_desc_get:
dev_err(chan2dev(chan), "not enough descriptors available\n");
atc_desc_put(atchan, first);
return NULL;
}
static int
atc_dma_cyclic_check_values(unsigned int reg_width, dma_addr_t buf_addr,
size_t period_len, enum dma_transfer_direction direction)
{
if (period_len > (ATC_BTSIZE_MAX << reg_width))
goto err_out;
if (unlikely(period_len & ((1 << reg_width) - 1)))
goto err_out;
if (unlikely(buf_addr & ((1 << reg_width) - 1)))
goto err_out;
if (unlikely(!(direction & (DMA_DEV_TO_MEM | DMA_MEM_TO_DEV))))
goto err_out;
return 0;
err_out:
return -EINVAL;
}
static int
atc_dma_cyclic_fill_desc(struct dma_chan *chan, struct at_desc *desc,
unsigned int period_index, dma_addr_t buf_addr,
unsigned int reg_width, size_t period_len,
enum dma_transfer_direction direction)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
struct at_dma_slave *atslave = chan->private;
struct dma_slave_config *sconfig = &atchan->dma_sconfig;
u32 ctrla;
ctrla = ATC_DEFAULT_CTRLA | atslave->ctrla
| ATC_DST_WIDTH(reg_width)
| ATC_SRC_WIDTH(reg_width)
| period_len >> reg_width;
switch (direction) {
case DMA_MEM_TO_DEV:
desc->lli.saddr = buf_addr + (period_len * period_index);
desc->lli.daddr = sconfig->dst_addr;
desc->lli.ctrla = ctrla;
desc->lli.ctrlb = ATC_DST_ADDR_MODE_FIXED
| ATC_SRC_ADDR_MODE_INCR
| ATC_FC_MEM2PER
| ATC_SIF(AT_DMA_MEM_IF)
| ATC_DIF(AT_DMA_PER_IF);
break;
case DMA_DEV_TO_MEM:
desc->lli.saddr = sconfig->src_addr;
desc->lli.daddr = buf_addr + (period_len * period_index);
desc->lli.ctrla = ctrla;
desc->lli.ctrlb = ATC_DST_ADDR_MODE_INCR
| ATC_SRC_ADDR_MODE_FIXED
| ATC_FC_PER2MEM
| ATC_SIF(AT_DMA_PER_IF)
| ATC_DIF(AT_DMA_MEM_IF);
break;
default:
return -EINVAL;
}
return 0;
}
static struct dma_async_tx_descriptor *
atc_prep_dma_cyclic(struct dma_chan *chan, dma_addr_t buf_addr, size_t buf_len,
size_t period_len, enum dma_transfer_direction direction,
void *context)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
struct at_dma_slave *atslave = chan->private;
struct dma_slave_config *sconfig = &atchan->dma_sconfig;
struct at_desc *first = NULL;
struct at_desc *prev = NULL;
unsigned long was_cyclic;
unsigned int reg_width;
unsigned int periods = buf_len / period_len;
unsigned int i;
dev_vdbg(chan2dev(chan), "prep_dma_cyclic: %s buf@0x%08x - %d (%d/%d)\n",
direction == DMA_MEM_TO_DEV ? "TO DEVICE" : "FROM DEVICE",
buf_addr,
periods, buf_len, period_len);
if (unlikely(!atslave || !buf_len || !period_len)) {
dev_dbg(chan2dev(chan), "prep_dma_cyclic: length is zero!\n");
return NULL;
}
was_cyclic = test_and_set_bit(ATC_IS_CYCLIC, &atchan->status);
if (was_cyclic) {
dev_dbg(chan2dev(chan), "prep_dma_cyclic: channel in use!\n");
return NULL;
}
if (sconfig->direction == DMA_MEM_TO_DEV)
reg_width = convert_buswidth(sconfig->dst_addr_width);
else
reg_width = convert_buswidth(sconfig->src_addr_width);
if (atc_dma_cyclic_check_values(reg_width, buf_addr,
period_len, direction))
goto err_out;
for (i = 0; i < periods; i++) {
struct at_desc *desc;
desc = atc_desc_get(atchan);
if (!desc)
goto err_desc_get;
if (atc_dma_cyclic_fill_desc(chan, desc, i, buf_addr,
reg_width, period_len, direction))
goto err_desc_get;
atc_desc_chain(&first, &prev, desc);
}
prev->lli.dscr = first->txd.phys;
first->txd.cookie = -EBUSY;
first->len = buf_len;
return &first->txd;
err_desc_get:
dev_err(chan2dev(chan), "not enough descriptors available\n");
atc_desc_put(atchan, first);
err_out:
clear_bit(ATC_IS_CYCLIC, &atchan->status);
return NULL;
}
static int set_runtime_config(struct dma_chan *chan,
struct dma_slave_config *sconfig)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
if (!chan->private)
return -EINVAL;
memcpy(&atchan->dma_sconfig, sconfig, sizeof(*sconfig));
convert_burst(&atchan->dma_sconfig.src_maxburst);
convert_burst(&atchan->dma_sconfig.dst_maxburst);
return 0;
}
static int atc_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
struct at_dma *atdma = to_at_dma(chan->device);
int chan_id = atchan->chan_common.chan_id;
unsigned long flags;
LIST_HEAD(list);
dev_vdbg(chan2dev(chan), "atc_control (%d)\n", cmd);
if (cmd == DMA_PAUSE) {
spin_lock_irqsave(&atchan->lock, flags);
dma_writel(atdma, CHER, AT_DMA_SUSP(chan_id));
set_bit(ATC_IS_PAUSED, &atchan->status);
spin_unlock_irqrestore(&atchan->lock, flags);
} else if (cmd == DMA_RESUME) {
if (!atc_chan_is_paused(atchan))
return 0;
spin_lock_irqsave(&atchan->lock, flags);
dma_writel(atdma, CHDR, AT_DMA_RES(chan_id));
clear_bit(ATC_IS_PAUSED, &atchan->status);
spin_unlock_irqrestore(&atchan->lock, flags);
} else if (cmd == DMA_TERMINATE_ALL) {
struct at_desc *desc, *_desc;
spin_lock_irqsave(&atchan->lock, flags);
dma_writel(atdma, CHDR, AT_DMA_RES(chan_id) | atchan->mask);
while (dma_readl(atdma, CHSR) & atchan->mask)
cpu_relax();
list_splice_init(&atchan->queue, &list);
list_splice_init(&atchan->active_list, &list);
list_for_each_entry_safe(desc, _desc, &list, desc_node)
atc_chain_complete(atchan, desc);
clear_bit(ATC_IS_PAUSED, &atchan->status);
clear_bit(ATC_IS_CYCLIC, &atchan->status);
spin_unlock_irqrestore(&atchan->lock, flags);
} else if (cmd == DMA_SLAVE_CONFIG) {
return set_runtime_config(chan, (struct dma_slave_config *)arg);
} else {
return -ENXIO;
}
return 0;
}
static enum dma_status
atc_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
dma_cookie_t last_used;
dma_cookie_t last_complete;
unsigned long flags;
enum dma_status ret;
spin_lock_irqsave(&atchan->lock, flags);
ret = dma_cookie_status(chan, cookie, txstate);
if (ret != DMA_SUCCESS) {
atc_cleanup_descriptors(atchan);
ret = dma_cookie_status(chan, cookie, txstate);
}
last_complete = chan->completed_cookie;
last_used = chan->cookie;
spin_unlock_irqrestore(&atchan->lock, flags);
if (ret != DMA_SUCCESS)
dma_set_residue(txstate, atc_first_active(atchan)->len);
if (atc_chan_is_paused(atchan))
ret = DMA_PAUSED;
dev_vdbg(chan2dev(chan), "tx_status %d: cookie = %d (d%d, u%d)\n",
ret, cookie, last_complete ? last_complete : 0,
last_used ? last_used : 0);
return ret;
}
static void atc_issue_pending(struct dma_chan *chan)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
unsigned long flags;
dev_vdbg(chan2dev(chan), "issue_pending\n");
if (atc_chan_is_cyclic(atchan))
return;
spin_lock_irqsave(&atchan->lock, flags);
if (!atc_chan_is_enabled(atchan)) {
atc_advance_work(atchan);
}
spin_unlock_irqrestore(&atchan->lock, flags);
}
static int atc_alloc_chan_resources(struct dma_chan *chan)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
struct at_dma *atdma = to_at_dma(chan->device);
struct at_desc *desc;
struct at_dma_slave *atslave;
unsigned long flags;
int i;
u32 cfg;
LIST_HEAD(tmp_list);
dev_vdbg(chan2dev(chan), "alloc_chan_resources\n");
if (atc_chan_is_enabled(atchan)) {
dev_dbg(chan2dev(chan), "DMA channel not idle ?\n");
return -EIO;
}
cfg = ATC_DEFAULT_CFG;
atslave = chan->private;
if (atslave) {
BUG_ON(!atslave->dma_dev || atslave->dma_dev != atdma->dma_common.dev);
if (atslave->cfg)
cfg = atslave->cfg;
}
if (!list_empty(&atchan->free_list))
return atchan->descs_allocated;
for (i = 0; i < init_nr_desc_per_channel; i++) {
desc = atc_alloc_descriptor(chan, GFP_KERNEL);
if (!desc) {
dev_err(atdma->dma_common.dev,
"Only %d initial descriptors\n", i);
break;
}
list_add_tail(&desc->desc_node, &tmp_list);
}
spin_lock_irqsave(&atchan->lock, flags);
atchan->descs_allocated = i;
list_splice(&tmp_list, &atchan->free_list);
dma_cookie_init(chan);
spin_unlock_irqrestore(&atchan->lock, flags);
channel_writel(atchan, CFG, cfg);
dev_dbg(chan2dev(chan),
"alloc_chan_resources: allocated %d descriptors\n",
atchan->descs_allocated);
return atchan->descs_allocated;
}
static void atc_free_chan_resources(struct dma_chan *chan)
{
struct at_dma_chan *atchan = to_at_dma_chan(chan);
struct at_dma *atdma = to_at_dma(chan->device);
struct at_desc *desc, *_desc;
LIST_HEAD(list);
dev_dbg(chan2dev(chan), "free_chan_resources: (descs allocated=%u)\n",
atchan->descs_allocated);
BUG_ON(!list_empty(&atchan->active_list));
BUG_ON(!list_empty(&atchan->queue));
BUG_ON(atc_chan_is_enabled(atchan));
list_for_each_entry_safe(desc, _desc, &atchan->free_list, desc_node) {
dev_vdbg(chan2dev(chan), " freeing descriptor %p\n", desc);
list_del(&desc->desc_node);
dma_pool_free(atdma->dma_desc_pool, desc, desc->txd.phys);
}
list_splice_init(&atchan->free_list, &list);
atchan->descs_allocated = 0;
atchan->status = 0;
dev_vdbg(chan2dev(chan), "free_chan_resources: done\n");
}
static inline struct at_dma_platform_data * __init at_dma_get_driver_data(
struct platform_device *pdev)
{
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(atmel_dma_dt_ids, pdev->dev.of_node);
if (match == NULL)
return NULL;
return match->data;
}
return (struct at_dma_platform_data *)
platform_get_device_id(pdev)->driver_data;
}
static void at_dma_off(struct at_dma *atdma)
{
dma_writel(atdma, EN, 0);
dma_writel(atdma, EBCIDR, -1L);
while (dma_readl(atdma, CHSR) & atdma->all_chan_mask)
cpu_relax();
}
static int __init at_dma_probe(struct platform_device *pdev)
{
struct resource *io;
struct at_dma *atdma;
size_t size;
int irq;
int err;
int i;
struct at_dma_platform_data *plat_dat;
dma_cap_set(DMA_MEMCPY, at91sam9rl_config.cap_mask);
dma_cap_set(DMA_MEMCPY, at91sam9g45_config.cap_mask);
dma_cap_set(DMA_SLAVE, at91sam9g45_config.cap_mask);
plat_dat = at_dma_get_driver_data(pdev);
if (!plat_dat)
return -ENODEV;
io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!io)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
size = sizeof(struct at_dma);
size += plat_dat->nr_channels * sizeof(struct at_dma_chan);
atdma = kzalloc(size, GFP_KERNEL);
if (!atdma)
return -ENOMEM;
atdma->dma_common.cap_mask = plat_dat->cap_mask;
atdma->all_chan_mask = (1 << plat_dat->nr_channels) - 1;
size = resource_size(io);
if (!request_mem_region(io->start, size, pdev->dev.driver->name)) {
err = -EBUSY;
goto err_kfree;
}
atdma->regs = ioremap(io->start, size);
if (!atdma->regs) {
err = -ENOMEM;
goto err_release_r;
}
atdma->clk = clk_get(&pdev->dev, "dma_clk");
if (IS_ERR(atdma->clk)) {
err = PTR_ERR(atdma->clk);
goto err_clk;
}
clk_enable(atdma->clk);
at_dma_off(atdma);
err = request_irq(irq, at_dma_interrupt, 0, "at_hdmac", atdma);
if (err)
goto err_irq;
platform_set_drvdata(pdev, atdma);
atdma->dma_desc_pool = dma_pool_create("at_hdmac_desc_pool",
&pdev->dev, sizeof(struct at_desc),
4 , 0);
if (!atdma->dma_desc_pool) {
dev_err(&pdev->dev, "No memory for descriptors dma pool\n");
err = -ENOMEM;
goto err_pool_create;
}
while (dma_readl(atdma, EBCISR))
cpu_relax();
INIT_LIST_HEAD(&atdma->dma_common.channels);
for (i = 0; i < plat_dat->nr_channels; i++) {
struct at_dma_chan *atchan = &atdma->chan[i];
atchan->chan_common.device = &atdma->dma_common;
dma_cookie_init(&atchan->chan_common);
list_add_tail(&atchan->chan_common.device_node,
&atdma->dma_common.channels);
atchan->ch_regs = atdma->regs + ch_regs(i);
spin_lock_init(&atchan->lock);
atchan->mask = 1 << i;
INIT_LIST_HEAD(&atchan->active_list);
INIT_LIST_HEAD(&atchan->queue);
INIT_LIST_HEAD(&atchan->free_list);
tasklet_init(&atchan->tasklet, atc_tasklet,
(unsigned long)atchan);
atc_enable_chan_irq(atdma, i);
}
atdma->dma_common.device_alloc_chan_resources = atc_alloc_chan_resources;
atdma->dma_common.device_free_chan_resources = atc_free_chan_resources;
atdma->dma_common.device_tx_status = atc_tx_status;
atdma->dma_common.device_issue_pending = atc_issue_pending;
atdma->dma_common.dev = &pdev->dev;
if (dma_has_cap(DMA_MEMCPY, atdma->dma_common.cap_mask))
atdma->dma_common.device_prep_dma_memcpy = atc_prep_dma_memcpy;
if (dma_has_cap(DMA_SLAVE, atdma->dma_common.cap_mask)) {
atdma->dma_common.device_prep_slave_sg = atc_prep_slave_sg;
dma_cap_set(DMA_CYCLIC, atdma->dma_common.cap_mask);
atdma->dma_common.device_prep_dma_cyclic = atc_prep_dma_cyclic;
atdma->dma_common.device_control = atc_control;
}
dma_writel(atdma, EN, AT_DMA_ENABLE);
dev_info(&pdev->dev, "Atmel AHB DMA Controller ( %s%s), %d channels\n",
dma_has_cap(DMA_MEMCPY, atdma->dma_common.cap_mask) ? "cpy " : "",
dma_has_cap(DMA_SLAVE, atdma->dma_common.cap_mask) ? "slave " : "",
plat_dat->nr_channels);
dma_async_device_register(&atdma->dma_common);
return 0;
err_pool_create:
platform_set_drvdata(pdev, NULL);
free_irq(platform_get_irq(pdev, 0), atdma);
err_irq:
clk_disable(atdma->clk);
clk_put(atdma->clk);
err_clk:
iounmap(atdma->regs);
atdma->regs = NULL;
err_release_r:
release_mem_region(io->start, size);
err_kfree:
kfree(atdma);
return err;
}
static int __exit at_dma_remove(struct platform_device *pdev)
{
struct at_dma *atdma = platform_get_drvdata(pdev);
struct dma_chan *chan, *_chan;
struct resource *io;
at_dma_off(atdma);
dma_async_device_unregister(&atdma->dma_common);
dma_pool_destroy(atdma->dma_desc_pool);
platform_set_drvdata(pdev, NULL);
free_irq(platform_get_irq(pdev, 0), atdma);
list_for_each_entry_safe(chan, _chan, &atdma->dma_common.channels,
device_node) {
struct at_dma_chan *atchan = to_at_dma_chan(chan);
atc_disable_chan_irq(atdma, chan->chan_id);
tasklet_disable(&atchan->tasklet);
tasklet_kill(&atchan->tasklet);
list_del(&chan->device_node);
}
clk_disable(atdma->clk);
clk_put(atdma->clk);
iounmap(atdma->regs);
atdma->regs = NULL;
io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(io->start, resource_size(io));
kfree(atdma);
return 0;
}
static void at_dma_shutdown(struct platform_device *pdev)
{
struct at_dma *atdma = platform_get_drvdata(pdev);
at_dma_off(platform_get_drvdata(pdev));
clk_disable(atdma->clk);
}
static int at_dma_prepare(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct at_dma *atdma = platform_get_drvdata(pdev);
struct dma_chan *chan, *_chan;
list_for_each_entry_safe(chan, _chan, &atdma->dma_common.channels,
device_node) {
struct at_dma_chan *atchan = to_at_dma_chan(chan);
if (atc_chan_is_enabled(atchan) && !atc_chan_is_cyclic(atchan))
return -EAGAIN;
}
return 0;
}
static void atc_suspend_cyclic(struct at_dma_chan *atchan)
{
struct dma_chan *chan = &atchan->chan_common;
if (!atc_chan_is_paused(atchan)) {
dev_warn(chan2dev(chan),
"cyclic channel not paused, should be done by channel user\n");
atc_control(chan, DMA_PAUSE, 0);
}
atchan->save_dscr = channel_readl(atchan, DSCR);
vdbg_dump_regs(atchan);
}
static int at_dma_suspend_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct at_dma *atdma = platform_get_drvdata(pdev);
struct dma_chan *chan, *_chan;
list_for_each_entry_safe(chan, _chan, &atdma->dma_common.channels,
device_node) {
struct at_dma_chan *atchan = to_at_dma_chan(chan);
if (atc_chan_is_cyclic(atchan))
atc_suspend_cyclic(atchan);
atchan->save_cfg = channel_readl(atchan, CFG);
}
atdma->save_imr = dma_readl(atdma, EBCIMR);
at_dma_off(atdma);
clk_disable(atdma->clk);
return 0;
}
static void atc_resume_cyclic(struct at_dma_chan *atchan)
{
struct at_dma *atdma = to_at_dma(atchan->chan_common.device);
channel_writel(atchan, SADDR, 0);
channel_writel(atchan, DADDR, 0);
channel_writel(atchan, CTRLA, 0);
channel_writel(atchan, CTRLB, 0);
channel_writel(atchan, DSCR, atchan->save_dscr);
dma_writel(atdma, CHER, atchan->mask);
vdbg_dump_regs(atchan);
}
static int at_dma_resume_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct at_dma *atdma = platform_get_drvdata(pdev);
struct dma_chan *chan, *_chan;
clk_enable(atdma->clk);
dma_writel(atdma, EN, AT_DMA_ENABLE);
while (dma_readl(atdma, EBCISR))
cpu_relax();
dma_writel(atdma, EBCIER, atdma->save_imr);
list_for_each_entry_safe(chan, _chan, &atdma->dma_common.channels,
device_node) {
struct at_dma_chan *atchan = to_at_dma_chan(chan);
channel_writel(atchan, CFG, atchan->save_cfg);
if (atc_chan_is_cyclic(atchan))
atc_resume_cyclic(atchan);
}
return 0;
}
static int __init at_dma_init(void)
{
return platform_driver_probe(&at_dma_driver, at_dma_probe);
}
static void __exit at_dma_exit(void)
{
platform_driver_unregister(&at_dma_driver);
}
