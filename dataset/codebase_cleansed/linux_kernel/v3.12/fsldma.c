static void set_sr(struct fsldma_chan *chan, u32 val)
{
DMA_OUT(chan, &chan->regs->sr, val, 32);
}
static u32 get_sr(struct fsldma_chan *chan)
{
return DMA_IN(chan, &chan->regs->sr, 32);
}
static void set_cdar(struct fsldma_chan *chan, dma_addr_t addr)
{
DMA_OUT(chan, &chan->regs->cdar, addr | FSL_DMA_SNEN, 64);
}
static dma_addr_t get_cdar(struct fsldma_chan *chan)
{
return DMA_IN(chan, &chan->regs->cdar, 64) & ~FSL_DMA_SNEN;
}
static u32 get_bcr(struct fsldma_chan *chan)
{
return DMA_IN(chan, &chan->regs->bcr, 32);
}
static void set_desc_cnt(struct fsldma_chan *chan,
struct fsl_dma_ld_hw *hw, u32 count)
{
hw->count = CPU_TO_DMA(chan, count, 32);
}
static u32 get_desc_cnt(struct fsldma_chan *chan, struct fsl_desc_sw *desc)
{
return DMA_TO_CPU(chan, desc->hw.count, 32);
}
static void set_desc_src(struct fsldma_chan *chan,
struct fsl_dma_ld_hw *hw, dma_addr_t src)
{
u64 snoop_bits;
snoop_bits = ((chan->feature & FSL_DMA_IP_MASK) == FSL_DMA_IP_85XX)
? ((u64)FSL_DMA_SATR_SREADTYPE_SNOOP_READ << 32) : 0;
hw->src_addr = CPU_TO_DMA(chan, snoop_bits | src, 64);
}
static dma_addr_t get_desc_src(struct fsldma_chan *chan,
struct fsl_desc_sw *desc)
{
u64 snoop_bits;
snoop_bits = ((chan->feature & FSL_DMA_IP_MASK) == FSL_DMA_IP_85XX)
? ((u64)FSL_DMA_SATR_SREADTYPE_SNOOP_READ << 32) : 0;
return DMA_TO_CPU(chan, desc->hw.src_addr, 64) & ~snoop_bits;
}
static void set_desc_dst(struct fsldma_chan *chan,
struct fsl_dma_ld_hw *hw, dma_addr_t dst)
{
u64 snoop_bits;
snoop_bits = ((chan->feature & FSL_DMA_IP_MASK) == FSL_DMA_IP_85XX)
? ((u64)FSL_DMA_DATR_DWRITETYPE_SNOOP_WRITE << 32) : 0;
hw->dst_addr = CPU_TO_DMA(chan, snoop_bits | dst, 64);
}
static dma_addr_t get_desc_dst(struct fsldma_chan *chan,
struct fsl_desc_sw *desc)
{
u64 snoop_bits;
snoop_bits = ((chan->feature & FSL_DMA_IP_MASK) == FSL_DMA_IP_85XX)
? ((u64)FSL_DMA_DATR_DWRITETYPE_SNOOP_WRITE << 32) : 0;
return DMA_TO_CPU(chan, desc->hw.dst_addr, 64) & ~snoop_bits;
}
static void set_desc_next(struct fsldma_chan *chan,
struct fsl_dma_ld_hw *hw, dma_addr_t next)
{
u64 snoop_bits;
snoop_bits = ((chan->feature & FSL_DMA_IP_MASK) == FSL_DMA_IP_83XX)
? FSL_DMA_SNEN : 0;
hw->next_ln_addr = CPU_TO_DMA(chan, snoop_bits | next, 64);
}
static void set_ld_eol(struct fsldma_chan *chan, struct fsl_desc_sw *desc)
{
u64 snoop_bits;
snoop_bits = ((chan->feature & FSL_DMA_IP_MASK) == FSL_DMA_IP_83XX)
? FSL_DMA_SNEN : 0;
desc->hw.next_ln_addr = CPU_TO_DMA(chan,
DMA_TO_CPU(chan, desc->hw.next_ln_addr, 64) | FSL_DMA_EOL
| snoop_bits, 64);
}
static void dma_init(struct fsldma_chan *chan)
{
DMA_OUT(chan, &chan->regs->mr, 0, 32);
switch (chan->feature & FSL_DMA_IP_MASK) {
case FSL_DMA_IP_85XX:
DMA_OUT(chan, &chan->regs->mr, FSL_DMA_MR_BWC
| FSL_DMA_MR_EIE | FSL_DMA_MR_EOLNIE, 32);
break;
case FSL_DMA_IP_83XX:
DMA_OUT(chan, &chan->regs->mr, FSL_DMA_MR_EOTIE
| FSL_DMA_MR_PRC_RM, 32);
break;
}
}
static int dma_is_idle(struct fsldma_chan *chan)
{
u32 sr = get_sr(chan);
return (!(sr & FSL_DMA_SR_CB)) || (sr & FSL_DMA_SR_CH);
}
static void dma_start(struct fsldma_chan *chan)
{
u32 mode;
mode = DMA_IN(chan, &chan->regs->mr, 32);
if (chan->feature & FSL_DMA_CHAN_PAUSE_EXT) {
DMA_OUT(chan, &chan->regs->bcr, 0, 32);
mode |= FSL_DMA_MR_EMP_EN;
} else {
mode &= ~FSL_DMA_MR_EMP_EN;
}
if (chan->feature & FSL_DMA_CHAN_START_EXT) {
mode |= FSL_DMA_MR_EMS_EN;
} else {
mode &= ~FSL_DMA_MR_EMS_EN;
mode |= FSL_DMA_MR_CS;
}
DMA_OUT(chan, &chan->regs->mr, mode, 32);
}
static void dma_halt(struct fsldma_chan *chan)
{
u32 mode;
int i;
mode = DMA_IN(chan, &chan->regs->mr, 32);
if ((chan->feature & FSL_DMA_IP_MASK) == FSL_DMA_IP_85XX) {
mode |= FSL_DMA_MR_CA;
DMA_OUT(chan, &chan->regs->mr, mode, 32);
mode &= ~FSL_DMA_MR_CA;
}
mode &= ~(FSL_DMA_MR_CS | FSL_DMA_MR_EMS_EN);
DMA_OUT(chan, &chan->regs->mr, mode, 32);
for (i = 0; i < 100; i++) {
if (dma_is_idle(chan))
return;
udelay(10);
}
if (!dma_is_idle(chan))
chan_err(chan, "DMA halt timeout!\n");
}
static void fsl_chan_set_src_loop_size(struct fsldma_chan *chan, int size)
{
u32 mode;
mode = DMA_IN(chan, &chan->regs->mr, 32);
switch (size) {
case 0:
mode &= ~FSL_DMA_MR_SAHE;
break;
case 1:
case 2:
case 4:
case 8:
mode |= FSL_DMA_MR_SAHE | (__ilog2(size) << 14);
break;
}
DMA_OUT(chan, &chan->regs->mr, mode, 32);
}
static void fsl_chan_set_dst_loop_size(struct fsldma_chan *chan, int size)
{
u32 mode;
mode = DMA_IN(chan, &chan->regs->mr, 32);
switch (size) {
case 0:
mode &= ~FSL_DMA_MR_DAHE;
break;
case 1:
case 2:
case 4:
case 8:
mode |= FSL_DMA_MR_DAHE | (__ilog2(size) << 16);
break;
}
DMA_OUT(chan, &chan->regs->mr, mode, 32);
}
static void fsl_chan_set_request_count(struct fsldma_chan *chan, int size)
{
u32 mode;
BUG_ON(size > 1024);
mode = DMA_IN(chan, &chan->regs->mr, 32);
mode |= (__ilog2(size) << 24) & 0x0f000000;
DMA_OUT(chan, &chan->regs->mr, mode, 32);
}
static void fsl_chan_toggle_ext_pause(struct fsldma_chan *chan, int enable)
{
if (enable)
chan->feature |= FSL_DMA_CHAN_PAUSE_EXT;
else
chan->feature &= ~FSL_DMA_CHAN_PAUSE_EXT;
}
static void fsl_chan_toggle_ext_start(struct fsldma_chan *chan, int enable)
{
if (enable)
chan->feature |= FSL_DMA_CHAN_START_EXT;
else
chan->feature &= ~FSL_DMA_CHAN_START_EXT;
}
static void append_ld_queue(struct fsldma_chan *chan, struct fsl_desc_sw *desc)
{
struct fsl_desc_sw *tail = to_fsl_desc(chan->ld_pending.prev);
if (list_empty(&chan->ld_pending))
goto out_splice;
set_desc_next(chan, &tail->hw, desc->async_tx.phys);
out_splice:
list_splice_tail_init(&desc->tx_list, &chan->ld_pending);
}
static dma_cookie_t fsl_dma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct fsldma_chan *chan = to_fsl_chan(tx->chan);
struct fsl_desc_sw *desc = tx_to_fsl_desc(tx);
struct fsl_desc_sw *child;
unsigned long flags;
dma_cookie_t cookie;
spin_lock_irqsave(&chan->desc_lock, flags);
list_for_each_entry(child, &desc->tx_list, node) {
cookie = dma_cookie_assign(&child->async_tx);
}
append_ld_queue(chan, desc);
spin_unlock_irqrestore(&chan->desc_lock, flags);
return cookie;
}
static struct fsl_desc_sw *fsl_dma_alloc_descriptor(struct fsldma_chan *chan)
{
struct fsl_desc_sw *desc;
dma_addr_t pdesc;
desc = dma_pool_alloc(chan->desc_pool, GFP_ATOMIC, &pdesc);
if (!desc) {
chan_dbg(chan, "out of memory for link descriptor\n");
return NULL;
}
memset(desc, 0, sizeof(*desc));
INIT_LIST_HEAD(&desc->tx_list);
dma_async_tx_descriptor_init(&desc->async_tx, &chan->common);
desc->async_tx.tx_submit = fsl_dma_tx_submit;
desc->async_tx.phys = pdesc;
#ifdef FSL_DMA_LD_DEBUG
chan_dbg(chan, "LD %p allocated\n", desc);
#endif
return desc;
}
static int fsl_dma_alloc_chan_resources(struct dma_chan *dchan)
{
struct fsldma_chan *chan = to_fsl_chan(dchan);
if (chan->desc_pool)
return 1;
chan->desc_pool = dma_pool_create(chan->name, chan->dev,
sizeof(struct fsl_desc_sw),
__alignof__(struct fsl_desc_sw), 0);
if (!chan->desc_pool) {
chan_err(chan, "unable to allocate descriptor pool\n");
return -ENOMEM;
}
return 1;
}
static void fsldma_free_desc_list(struct fsldma_chan *chan,
struct list_head *list)
{
struct fsl_desc_sw *desc, *_desc;
list_for_each_entry_safe(desc, _desc, list, node) {
list_del(&desc->node);
#ifdef FSL_DMA_LD_DEBUG
chan_dbg(chan, "LD %p free\n", desc);
#endif
dma_pool_free(chan->desc_pool, desc, desc->async_tx.phys);
}
}
static void fsldma_free_desc_list_reverse(struct fsldma_chan *chan,
struct list_head *list)
{
struct fsl_desc_sw *desc, *_desc;
list_for_each_entry_safe_reverse(desc, _desc, list, node) {
list_del(&desc->node);
#ifdef FSL_DMA_LD_DEBUG
chan_dbg(chan, "LD %p free\n", desc);
#endif
dma_pool_free(chan->desc_pool, desc, desc->async_tx.phys);
}
}
static void fsl_dma_free_chan_resources(struct dma_chan *dchan)
{
struct fsldma_chan *chan = to_fsl_chan(dchan);
unsigned long flags;
chan_dbg(chan, "free all channel resources\n");
spin_lock_irqsave(&chan->desc_lock, flags);
fsldma_free_desc_list(chan, &chan->ld_pending);
fsldma_free_desc_list(chan, &chan->ld_running);
spin_unlock_irqrestore(&chan->desc_lock, flags);
dma_pool_destroy(chan->desc_pool);
chan->desc_pool = NULL;
}
static struct dma_async_tx_descriptor *
fsl_dma_prep_interrupt(struct dma_chan *dchan, unsigned long flags)
{
struct fsldma_chan *chan;
struct fsl_desc_sw *new;
if (!dchan)
return NULL;
chan = to_fsl_chan(dchan);
new = fsl_dma_alloc_descriptor(chan);
if (!new) {
chan_err(chan, "%s\n", msg_ld_oom);
return NULL;
}
new->async_tx.cookie = -EBUSY;
new->async_tx.flags = flags;
list_add_tail(&new->node, &new->tx_list);
set_ld_eol(chan, new);
return &new->async_tx;
}
static struct dma_async_tx_descriptor *
fsl_dma_prep_memcpy(struct dma_chan *dchan,
dma_addr_t dma_dst, dma_addr_t dma_src,
size_t len, unsigned long flags)
{
struct fsldma_chan *chan;
struct fsl_desc_sw *first = NULL, *prev = NULL, *new;
size_t copy;
if (!dchan)
return NULL;
if (!len)
return NULL;
chan = to_fsl_chan(dchan);
do {
new = fsl_dma_alloc_descriptor(chan);
if (!new) {
chan_err(chan, "%s\n", msg_ld_oom);
goto fail;
}
copy = min(len, (size_t)FSL_DMA_BCR_MAX_CNT);
set_desc_cnt(chan, &new->hw, copy);
set_desc_src(chan, &new->hw, dma_src);
set_desc_dst(chan, &new->hw, dma_dst);
if (!first)
first = new;
else
set_desc_next(chan, &prev->hw, new->async_tx.phys);
new->async_tx.cookie = 0;
async_tx_ack(&new->async_tx);
prev = new;
len -= copy;
dma_src += copy;
dma_dst += copy;
list_add_tail(&new->node, &first->tx_list);
} while (len);
new->async_tx.flags = flags;
new->async_tx.cookie = -EBUSY;
set_ld_eol(chan, new);
return &first->async_tx;
fail:
if (!first)
return NULL;
fsldma_free_desc_list_reverse(chan, &first->tx_list);
return NULL;
}
static struct dma_async_tx_descriptor *fsl_dma_prep_sg(struct dma_chan *dchan,
struct scatterlist *dst_sg, unsigned int dst_nents,
struct scatterlist *src_sg, unsigned int src_nents,
unsigned long flags)
{
struct fsl_desc_sw *first = NULL, *prev = NULL, *new = NULL;
struct fsldma_chan *chan = to_fsl_chan(dchan);
size_t dst_avail, src_avail;
dma_addr_t dst, src;
size_t len;
if (dst_nents == 0 || src_nents == 0)
return NULL;
if (dst_sg == NULL || src_sg == NULL)
return NULL;
dst_avail = sg_dma_len(dst_sg);
src_avail = sg_dma_len(src_sg);
while (true) {
len = min_t(size_t, src_avail, dst_avail);
len = min_t(size_t, len, FSL_DMA_BCR_MAX_CNT);
if (len == 0)
goto fetch;
dst = sg_dma_address(dst_sg) + sg_dma_len(dst_sg) - dst_avail;
src = sg_dma_address(src_sg) + sg_dma_len(src_sg) - src_avail;
new = fsl_dma_alloc_descriptor(chan);
if (!new) {
chan_err(chan, "%s\n", msg_ld_oom);
goto fail;
}
set_desc_cnt(chan, &new->hw, len);
set_desc_src(chan, &new->hw, src);
set_desc_dst(chan, &new->hw, dst);
if (!first)
first = new;
else
set_desc_next(chan, &prev->hw, new->async_tx.phys);
new->async_tx.cookie = 0;
async_tx_ack(&new->async_tx);
prev = new;
list_add_tail(&new->node, &first->tx_list);
dst_avail -= len;
src_avail -= len;
fetch:
if (dst_avail == 0) {
if (dst_nents == 0)
break;
dst_sg = sg_next(dst_sg);
if (dst_sg == NULL)
break;
dst_nents--;
dst_avail = sg_dma_len(dst_sg);
}
if (src_avail == 0) {
if (src_nents == 0)
break;
src_sg = sg_next(src_sg);
if (src_sg == NULL)
break;
src_nents--;
src_avail = sg_dma_len(src_sg);
}
}
new->async_tx.flags = flags;
new->async_tx.cookie = -EBUSY;
set_ld_eol(chan, new);
return &first->async_tx;
fail:
if (!first)
return NULL;
fsldma_free_desc_list_reverse(chan, &first->tx_list);
return NULL;
}
static struct dma_async_tx_descriptor *fsl_dma_prep_slave_sg(
struct dma_chan *dchan, struct scatterlist *sgl, unsigned int sg_len,
enum dma_transfer_direction direction, unsigned long flags,
void *context)
{
return NULL;
}
static int fsl_dma_device_control(struct dma_chan *dchan,
enum dma_ctrl_cmd cmd, unsigned long arg)
{
struct dma_slave_config *config;
struct fsldma_chan *chan;
unsigned long flags;
int size;
if (!dchan)
return -EINVAL;
chan = to_fsl_chan(dchan);
switch (cmd) {
case DMA_TERMINATE_ALL:
spin_lock_irqsave(&chan->desc_lock, flags);
dma_halt(chan);
fsldma_free_desc_list(chan, &chan->ld_pending);
fsldma_free_desc_list(chan, &chan->ld_running);
chan->idle = true;
spin_unlock_irqrestore(&chan->desc_lock, flags);
return 0;
case DMA_SLAVE_CONFIG:
config = (struct dma_slave_config *)arg;
if (!chan->set_request_count)
return -ENXIO;
if (config->direction == DMA_MEM_TO_DEV)
size = config->dst_addr_width * config->dst_maxburst;
else
size = config->src_addr_width * config->src_maxburst;
chan->set_request_count(chan, size);
return 0;
case FSLDMA_EXTERNAL_START:
if (!chan->toggle_ext_start)
return -ENXIO;
chan->toggle_ext_start(chan, arg);
return 0;
default:
return -ENXIO;
}
return 0;
}
static void fsldma_cleanup_descriptor(struct fsldma_chan *chan,
struct fsl_desc_sw *desc)
{
struct dma_async_tx_descriptor *txd = &desc->async_tx;
struct device *dev = chan->common.device->dev;
dma_addr_t src = get_desc_src(chan, desc);
dma_addr_t dst = get_desc_dst(chan, desc);
u32 len = get_desc_cnt(chan, desc);
if (txd->callback) {
#ifdef FSL_DMA_LD_DEBUG
chan_dbg(chan, "LD %p callback\n", desc);
#endif
txd->callback(txd->callback_param);
}
dma_run_dependencies(txd);
if (!(txd->flags & DMA_COMPL_SKIP_DEST_UNMAP)) {
if (txd->flags & DMA_COMPL_DEST_UNMAP_SINGLE)
dma_unmap_single(dev, dst, len, DMA_FROM_DEVICE);
else
dma_unmap_page(dev, dst, len, DMA_FROM_DEVICE);
}
if (!(txd->flags & DMA_COMPL_SKIP_SRC_UNMAP)) {
if (txd->flags & DMA_COMPL_SRC_UNMAP_SINGLE)
dma_unmap_single(dev, src, len, DMA_TO_DEVICE);
else
dma_unmap_page(dev, src, len, DMA_TO_DEVICE);
}
#ifdef FSL_DMA_LD_DEBUG
chan_dbg(chan, "LD %p free\n", desc);
#endif
dma_pool_free(chan->desc_pool, desc, txd->phys);
}
static void fsl_chan_xfer_ld_queue(struct fsldma_chan *chan)
{
struct fsl_desc_sw *desc;
if (list_empty(&chan->ld_pending)) {
chan_dbg(chan, "no pending LDs\n");
return;
}
if (!chan->idle) {
chan_dbg(chan, "DMA controller still busy\n");
return;
}
chan_dbg(chan, "idle, starting controller\n");
desc = list_first_entry(&chan->ld_pending, struct fsl_desc_sw, node);
list_splice_tail_init(&chan->ld_pending, &chan->ld_running);
if ((chan->feature & FSL_DMA_IP_MASK) == FSL_DMA_IP_85XX) {
u32 mode;
mode = DMA_IN(chan, &chan->regs->mr, 32);
mode &= ~FSL_DMA_MR_CS;
DMA_OUT(chan, &chan->regs->mr, mode, 32);
}
set_cdar(chan, desc->async_tx.phys);
get_cdar(chan);
dma_start(chan);
chan->idle = false;
}
static void fsl_dma_memcpy_issue_pending(struct dma_chan *dchan)
{
struct fsldma_chan *chan = to_fsl_chan(dchan);
unsigned long flags;
spin_lock_irqsave(&chan->desc_lock, flags);
fsl_chan_xfer_ld_queue(chan);
spin_unlock_irqrestore(&chan->desc_lock, flags);
}
static enum dma_status fsl_tx_status(struct dma_chan *dchan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
return dma_cookie_status(dchan, cookie, txstate);
}
static irqreturn_t fsldma_chan_irq(int irq, void *data)
{
struct fsldma_chan *chan = data;
u32 stat;
stat = get_sr(chan);
set_sr(chan, stat);
chan_dbg(chan, "irq: stat = 0x%x\n", stat);
stat &= ~(FSL_DMA_SR_CB | FSL_DMA_SR_CH);
if (!stat)
return IRQ_NONE;
if (stat & FSL_DMA_SR_TE)
chan_err(chan, "Transfer Error!\n");
if (stat & FSL_DMA_SR_PE) {
chan_dbg(chan, "irq: Programming Error INT\n");
stat &= ~FSL_DMA_SR_PE;
if (get_bcr(chan) != 0)
chan_err(chan, "Programming Error!\n");
}
if (stat & FSL_DMA_SR_EOCDI) {
chan_dbg(chan, "irq: End-of-Chain link INT\n");
stat &= ~FSL_DMA_SR_EOCDI;
}
if (stat & FSL_DMA_SR_EOLNI) {
chan_dbg(chan, "irq: End-of-link INT\n");
stat &= ~FSL_DMA_SR_EOLNI;
}
if (!dma_is_idle(chan))
chan_err(chan, "irq: controller not idle!\n");
if (stat)
chan_err(chan, "irq: unhandled sr 0x%08x\n", stat);
tasklet_schedule(&chan->tasklet);
chan_dbg(chan, "irq: Exit\n");
return IRQ_HANDLED;
}
static void dma_do_tasklet(unsigned long data)
{
struct fsldma_chan *chan = (struct fsldma_chan *)data;
struct fsl_desc_sw *desc, *_desc;
LIST_HEAD(ld_cleanup);
unsigned long flags;
chan_dbg(chan, "tasklet entry\n");
spin_lock_irqsave(&chan->desc_lock, flags);
if (!list_empty(&chan->ld_running)) {
dma_cookie_t cookie;
desc = to_fsl_desc(chan->ld_running.prev);
cookie = desc->async_tx.cookie;
dma_cookie_complete(&desc->async_tx);
chan_dbg(chan, "completed_cookie=%d\n", cookie);
}
list_splice_tail_init(&chan->ld_running, &ld_cleanup);
chan->idle = true;
fsl_chan_xfer_ld_queue(chan);
spin_unlock_irqrestore(&chan->desc_lock, flags);
list_for_each_entry_safe(desc, _desc, &ld_cleanup, node) {
list_del(&desc->node);
fsldma_cleanup_descriptor(chan, desc);
}
chan_dbg(chan, "tasklet exit\n");
}
static irqreturn_t fsldma_ctrl_irq(int irq, void *data)
{
struct fsldma_device *fdev = data;
struct fsldma_chan *chan;
unsigned int handled = 0;
u32 gsr, mask;
int i;
gsr = (fdev->feature & FSL_DMA_BIG_ENDIAN) ? in_be32(fdev->regs)
: in_le32(fdev->regs);
mask = 0xff000000;
dev_dbg(fdev->dev, "IRQ: gsr 0x%.8x\n", gsr);
for (i = 0; i < FSL_DMA_MAX_CHANS_PER_DEVICE; i++) {
chan = fdev->chan[i];
if (!chan)
continue;
if (gsr & mask) {
dev_dbg(fdev->dev, "IRQ: chan %d\n", chan->id);
fsldma_chan_irq(irq, chan);
handled++;
}
gsr &= ~mask;
mask >>= 8;
}
return IRQ_RETVAL(handled);
}
static void fsldma_free_irqs(struct fsldma_device *fdev)
{
struct fsldma_chan *chan;
int i;
if (fdev->irq != NO_IRQ) {
dev_dbg(fdev->dev, "free per-controller IRQ\n");
free_irq(fdev->irq, fdev);
return;
}
for (i = 0; i < FSL_DMA_MAX_CHANS_PER_DEVICE; i++) {
chan = fdev->chan[i];
if (chan && chan->irq != NO_IRQ) {
chan_dbg(chan, "free per-channel IRQ\n");
free_irq(chan->irq, chan);
}
}
}
static int fsldma_request_irqs(struct fsldma_device *fdev)
{
struct fsldma_chan *chan;
int ret;
int i;
if (fdev->irq != NO_IRQ) {
dev_dbg(fdev->dev, "request per-controller IRQ\n");
ret = request_irq(fdev->irq, fsldma_ctrl_irq, IRQF_SHARED,
"fsldma-controller", fdev);
return ret;
}
for (i = 0; i < FSL_DMA_MAX_CHANS_PER_DEVICE; i++) {
chan = fdev->chan[i];
if (!chan)
continue;
if (chan->irq == NO_IRQ) {
chan_err(chan, "interrupts property missing in device tree\n");
ret = -ENODEV;
goto out_unwind;
}
chan_dbg(chan, "request per-channel IRQ\n");
ret = request_irq(chan->irq, fsldma_chan_irq, IRQF_SHARED,
"fsldma-chan", chan);
if (ret) {
chan_err(chan, "unable to request per-channel IRQ\n");
goto out_unwind;
}
}
return 0;
out_unwind:
for (; i >= 0; i--) {
chan = fdev->chan[i];
if (!chan)
continue;
if (chan->irq == NO_IRQ)
continue;
free_irq(chan->irq, chan);
}
return ret;
}
static int fsl_dma_chan_probe(struct fsldma_device *fdev,
struct device_node *node, u32 feature, const char *compatible)
{
struct fsldma_chan *chan;
struct resource res;
int err;
chan = kzalloc(sizeof(*chan), GFP_KERNEL);
if (!chan) {
dev_err(fdev->dev, "no free memory for DMA channels!\n");
err = -ENOMEM;
goto out_return;
}
chan->regs = of_iomap(node, 0);
if (!chan->regs) {
dev_err(fdev->dev, "unable to ioremap registers\n");
err = -ENOMEM;
goto out_free_chan;
}
err = of_address_to_resource(node, 0, &res);
if (err) {
dev_err(fdev->dev, "unable to find 'reg' property\n");
goto out_iounmap_regs;
}
chan->feature = feature;
if (!fdev->feature)
fdev->feature = chan->feature;
WARN_ON(fdev->feature != chan->feature);
chan->dev = fdev->dev;
chan->id = ((res.start - 0x100) & 0xfff) >> 7;
if (chan->id >= FSL_DMA_MAX_CHANS_PER_DEVICE) {
dev_err(fdev->dev, "too many channels for device\n");
err = -EINVAL;
goto out_iounmap_regs;
}
fdev->chan[chan->id] = chan;
tasklet_init(&chan->tasklet, dma_do_tasklet, (unsigned long)chan);
snprintf(chan->name, sizeof(chan->name), "chan%d", chan->id);
dma_init(chan);
set_cdar(chan, 0);
switch (chan->feature & FSL_DMA_IP_MASK) {
case FSL_DMA_IP_85XX:
chan->toggle_ext_pause = fsl_chan_toggle_ext_pause;
case FSL_DMA_IP_83XX:
chan->toggle_ext_start = fsl_chan_toggle_ext_start;
chan->set_src_loop_size = fsl_chan_set_src_loop_size;
chan->set_dst_loop_size = fsl_chan_set_dst_loop_size;
chan->set_request_count = fsl_chan_set_request_count;
}
spin_lock_init(&chan->desc_lock);
INIT_LIST_HEAD(&chan->ld_pending);
INIT_LIST_HEAD(&chan->ld_running);
chan->idle = true;
chan->common.device = &fdev->common;
dma_cookie_init(&chan->common);
chan->irq = irq_of_parse_and_map(node, 0);
list_add_tail(&chan->common.device_node, &fdev->common.channels);
fdev->common.chancnt++;
dev_info(fdev->dev, "#%d (%s), irq %d\n", chan->id, compatible,
chan->irq != NO_IRQ ? chan->irq : fdev->irq);
return 0;
out_iounmap_regs:
iounmap(chan->regs);
out_free_chan:
kfree(chan);
out_return:
return err;
}
static void fsl_dma_chan_remove(struct fsldma_chan *chan)
{
irq_dispose_mapping(chan->irq);
list_del(&chan->common.device_node);
iounmap(chan->regs);
kfree(chan);
}
static int fsldma_of_probe(struct platform_device *op)
{
struct fsldma_device *fdev;
struct device_node *child;
int err;
fdev = kzalloc(sizeof(*fdev), GFP_KERNEL);
if (!fdev) {
dev_err(&op->dev, "No enough memory for 'priv'\n");
err = -ENOMEM;
goto out_return;
}
fdev->dev = &op->dev;
INIT_LIST_HEAD(&fdev->common.channels);
fdev->regs = of_iomap(op->dev.of_node, 0);
if (!fdev->regs) {
dev_err(&op->dev, "unable to ioremap registers\n");
err = -ENOMEM;
goto out_free_fdev;
}
fdev->irq = irq_of_parse_and_map(op->dev.of_node, 0);
dma_cap_set(DMA_MEMCPY, fdev->common.cap_mask);
dma_cap_set(DMA_INTERRUPT, fdev->common.cap_mask);
dma_cap_set(DMA_SG, fdev->common.cap_mask);
dma_cap_set(DMA_SLAVE, fdev->common.cap_mask);
fdev->common.device_alloc_chan_resources = fsl_dma_alloc_chan_resources;
fdev->common.device_free_chan_resources = fsl_dma_free_chan_resources;
fdev->common.device_prep_dma_interrupt = fsl_dma_prep_interrupt;
fdev->common.device_prep_dma_memcpy = fsl_dma_prep_memcpy;
fdev->common.device_prep_dma_sg = fsl_dma_prep_sg;
fdev->common.device_tx_status = fsl_tx_status;
fdev->common.device_issue_pending = fsl_dma_memcpy_issue_pending;
fdev->common.device_prep_slave_sg = fsl_dma_prep_slave_sg;
fdev->common.device_control = fsl_dma_device_control;
fdev->common.dev = &op->dev;
dma_set_mask(&(op->dev), DMA_BIT_MASK(36));
platform_set_drvdata(op, fdev);
for_each_child_of_node(op->dev.of_node, child) {
if (of_device_is_compatible(child, "fsl,eloplus-dma-channel")) {
fsl_dma_chan_probe(fdev, child,
FSL_DMA_IP_85XX | FSL_DMA_BIG_ENDIAN,
"fsl,eloplus-dma-channel");
}
if (of_device_is_compatible(child, "fsl,elo-dma-channel")) {
fsl_dma_chan_probe(fdev, child,
FSL_DMA_IP_83XX | FSL_DMA_LITTLE_ENDIAN,
"fsl,elo-dma-channel");
}
}
err = fsldma_request_irqs(fdev);
if (err) {
dev_err(fdev->dev, "unable to request IRQs\n");
goto out_free_fdev;
}
dma_async_device_register(&fdev->common);
return 0;
out_free_fdev:
irq_dispose_mapping(fdev->irq);
kfree(fdev);
out_return:
return err;
}
static int fsldma_of_remove(struct platform_device *op)
{
struct fsldma_device *fdev;
unsigned int i;
fdev = platform_get_drvdata(op);
dma_async_device_unregister(&fdev->common);
fsldma_free_irqs(fdev);
for (i = 0; i < FSL_DMA_MAX_CHANS_PER_DEVICE; i++) {
if (fdev->chan[i])
fsl_dma_chan_remove(fdev->chan[i]);
}
iounmap(fdev->regs);
kfree(fdev);
return 0;
}
static __init int fsldma_init(void)
{
pr_info("Freescale Elo / Elo Plus DMA driver\n");
return platform_driver_register(&fsldma_of_driver);
}
static void __exit fsldma_exit(void)
{
platform_driver_unregister(&fsldma_of_driver);
}
