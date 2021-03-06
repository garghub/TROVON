static void chclr_write(struct sh_dmae_chan *sh_dc, u32 data)
{
struct sh_dmae_device *shdev = to_sh_dev(sh_dc);
__raw_writel(data, shdev->chan_reg +
shdev->pdata->channel[sh_dc->id].chclr_offset);
}
static void sh_dmae_writel(struct sh_dmae_chan *sh_dc, u32 data, u32 reg)
{
__raw_writel(data, sh_dc->base + reg / sizeof(u32));
}
static u32 sh_dmae_readl(struct sh_dmae_chan *sh_dc, u32 reg)
{
return __raw_readl(sh_dc->base + reg / sizeof(u32));
}
static u16 dmaor_read(struct sh_dmae_device *shdev)
{
u32 __iomem *addr = shdev->chan_reg + DMAOR / sizeof(u32);
if (shdev->pdata->dmaor_is_32bit)
return __raw_readl(addr);
else
return __raw_readw(addr);
}
static void dmaor_write(struct sh_dmae_device *shdev, u16 data)
{
u32 __iomem *addr = shdev->chan_reg + DMAOR / sizeof(u32);
if (shdev->pdata->dmaor_is_32bit)
__raw_writel(data, addr);
else
__raw_writew(data, addr);
}
static void chcr_write(struct sh_dmae_chan *sh_dc, u32 data)
{
struct sh_dmae_device *shdev = to_sh_dev(sh_dc);
__raw_writel(data, sh_dc->base + shdev->chcr_offset / sizeof(u32));
}
static u32 chcr_read(struct sh_dmae_chan *sh_dc)
{
struct sh_dmae_device *shdev = to_sh_dev(sh_dc);
return __raw_readl(sh_dc->base + shdev->chcr_offset / sizeof(u32));
}
static void sh_dmae_ctl_stop(struct sh_dmae_device *shdev)
{
unsigned short dmaor;
unsigned long flags;
spin_lock_irqsave(&sh_dmae_lock, flags);
dmaor = dmaor_read(shdev);
dmaor_write(shdev, dmaor & ~(DMAOR_NMIF | DMAOR_AE | DMAOR_DME));
spin_unlock_irqrestore(&sh_dmae_lock, flags);
}
static int sh_dmae_rst(struct sh_dmae_device *shdev)
{
unsigned short dmaor;
unsigned long flags;
spin_lock_irqsave(&sh_dmae_lock, flags);
dmaor = dmaor_read(shdev) & ~(DMAOR_NMIF | DMAOR_AE | DMAOR_DME);
if (shdev->pdata->chclr_present) {
int i;
for (i = 0; i < shdev->pdata->channel_num; i++) {
struct sh_dmae_chan *sh_chan = shdev->chan[i];
if (sh_chan)
chclr_write(sh_chan, 0);
}
}
dmaor_write(shdev, dmaor | shdev->pdata->dmaor_init);
dmaor = dmaor_read(shdev);
spin_unlock_irqrestore(&sh_dmae_lock, flags);
if (dmaor & (DMAOR_AE | DMAOR_NMIF)) {
dev_warn(shdev->common.dev, "Can't initialize DMAOR.\n");
return -EIO;
}
if (shdev->pdata->dmaor_init & ~dmaor)
dev_warn(shdev->common.dev,
"DMAOR=0x%x hasn't latched the initial value 0x%x.\n",
dmaor, shdev->pdata->dmaor_init);
return 0;
}
static bool dmae_is_busy(struct sh_dmae_chan *sh_chan)
{
u32 chcr = chcr_read(sh_chan);
if ((chcr & (CHCR_DE | CHCR_TE)) == CHCR_DE)
return true;
return false;
}
static unsigned int calc_xmit_shift(struct sh_dmae_chan *sh_chan, u32 chcr)
{
struct sh_dmae_device *shdev = to_sh_dev(sh_chan);
struct sh_dmae_pdata *pdata = shdev->pdata;
int cnt = ((chcr & pdata->ts_low_mask) >> pdata->ts_low_shift) |
((chcr & pdata->ts_high_mask) >> pdata->ts_high_shift);
if (cnt >= pdata->ts_shift_num)
cnt = 0;
return pdata->ts_shift[cnt];
}
static u32 log2size_to_chcr(struct sh_dmae_chan *sh_chan, int l2size)
{
struct sh_dmae_device *shdev = to_sh_dev(sh_chan);
struct sh_dmae_pdata *pdata = shdev->pdata;
int i;
for (i = 0; i < pdata->ts_shift_num; i++)
if (pdata->ts_shift[i] == l2size)
break;
if (i == pdata->ts_shift_num)
i = 0;
return ((i << pdata->ts_low_shift) & pdata->ts_low_mask) |
((i << pdata->ts_high_shift) & pdata->ts_high_mask);
}
static void dmae_set_reg(struct sh_dmae_chan *sh_chan, struct sh_dmae_regs *hw)
{
sh_dmae_writel(sh_chan, hw->sar, SAR);
sh_dmae_writel(sh_chan, hw->dar, DAR);
sh_dmae_writel(sh_chan, hw->tcr >> sh_chan->xmit_shift, TCR);
}
static void dmae_start(struct sh_dmae_chan *sh_chan)
{
struct sh_dmae_device *shdev = to_sh_dev(sh_chan);
u32 chcr = chcr_read(sh_chan);
if (shdev->pdata->needs_tend_set)
sh_dmae_writel(sh_chan, 0xFFFFFFFF, TEND);
chcr |= CHCR_DE | shdev->chcr_ie_bit;
chcr_write(sh_chan, chcr & ~CHCR_TE);
}
static void dmae_halt(struct sh_dmae_chan *sh_chan)
{
struct sh_dmae_device *shdev = to_sh_dev(sh_chan);
u32 chcr = chcr_read(sh_chan);
chcr &= ~(CHCR_DE | CHCR_TE | shdev->chcr_ie_bit);
chcr_write(sh_chan, chcr);
}
static void dmae_init(struct sh_dmae_chan *sh_chan)
{
u32 chcr = DM_INC | SM_INC | 0x400 | log2size_to_chcr(sh_chan,
LOG2_DEFAULT_XFER_SIZE);
sh_chan->xmit_shift = calc_xmit_shift(sh_chan, chcr);
chcr_write(sh_chan, chcr);
}
static int dmae_set_chcr(struct sh_dmae_chan *sh_chan, u32 val)
{
if (dmae_is_busy(sh_chan))
return -EBUSY;
sh_chan->xmit_shift = calc_xmit_shift(sh_chan, val);
chcr_write(sh_chan, val);
return 0;
}
static int dmae_set_dmars(struct sh_dmae_chan *sh_chan, u16 val)
{
struct sh_dmae_device *shdev = to_sh_dev(sh_chan);
struct sh_dmae_pdata *pdata = shdev->pdata;
const struct sh_dmae_channel *chan_pdata = &pdata->channel[sh_chan->id];
u16 __iomem *addr = shdev->dmars;
unsigned int shift = chan_pdata->dmars_bit;
if (dmae_is_busy(sh_chan))
return -EBUSY;
if (pdata->no_dmars)
return 0;
if (!addr)
addr = (u16 __iomem *)shdev->chan_reg;
addr += chan_pdata->dmars / sizeof(u16);
__raw_writew((__raw_readw(addr) & (0xff00 >> shift)) | (val << shift),
addr);
return 0;
}
static dma_cookie_t sh_dmae_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct sh_desc *desc = tx_to_sh_desc(tx), *chunk, *last = desc, *c;
struct sh_dmae_chan *sh_chan = to_sh_chan(tx->chan);
struct sh_dmae_slave *param = tx->chan->private;
dma_async_tx_callback callback = tx->callback;
dma_cookie_t cookie;
bool power_up;
spin_lock_irq(&sh_chan->desc_lock);
if (list_empty(&sh_chan->ld_queue))
power_up = true;
else
power_up = false;
cookie = dma_cookie_assign(tx);
list_for_each_entry_safe(chunk, c, desc->node.prev, node) {
if (chunk != desc && (chunk->mark == DESC_IDLE ||
chunk->async_tx.cookie > 0 ||
chunk->async_tx.cookie == -EBUSY ||
&chunk->node == &sh_chan->ld_free))
break;
chunk->mark = DESC_SUBMITTED;
chunk->async_tx.callback = NULL;
chunk->cookie = cookie;
list_move_tail(&chunk->node, &sh_chan->ld_queue);
last = chunk;
}
last->async_tx.callback = callback;
last->async_tx.callback_param = tx->callback_param;
dev_dbg(sh_chan->dev, "submit #%d@%p on %d: %x[%d] -> %x\n",
tx->cookie, &last->async_tx, sh_chan->id,
desc->hw.sar, desc->hw.tcr, desc->hw.dar);
if (power_up) {
sh_chan->pm_state = DMAE_PM_BUSY;
pm_runtime_get(sh_chan->dev);
spin_unlock_irq(&sh_chan->desc_lock);
pm_runtime_barrier(sh_chan->dev);
spin_lock_irq(&sh_chan->desc_lock);
if (sh_chan->pm_state != DMAE_PM_ESTABLISHED) {
dev_dbg(sh_chan->dev, "Bring up channel %d\n",
sh_chan->id);
if (param) {
const struct sh_dmae_slave_config *cfg =
param->config;
dmae_set_dmars(sh_chan, cfg->mid_rid);
dmae_set_chcr(sh_chan, cfg->chcr);
} else {
dmae_init(sh_chan);
}
if (sh_chan->pm_state == DMAE_PM_PENDING)
sh_chan_xfer_ld_queue(sh_chan);
sh_chan->pm_state = DMAE_PM_ESTABLISHED;
}
} else {
sh_chan->pm_state = DMAE_PM_PENDING;
}
spin_unlock_irq(&sh_chan->desc_lock);
return cookie;
}
static struct sh_desc *sh_dmae_get_desc(struct sh_dmae_chan *sh_chan)
{
struct sh_desc *desc;
list_for_each_entry(desc, &sh_chan->ld_free, node)
if (desc->mark != DESC_PREPARED) {
BUG_ON(desc->mark != DESC_IDLE);
list_del(&desc->node);
return desc;
}
return NULL;
}
static const struct sh_dmae_slave_config *sh_dmae_find_slave(
struct sh_dmae_chan *sh_chan, struct sh_dmae_slave *param)
{
struct sh_dmae_device *shdev = to_sh_dev(sh_chan);
struct sh_dmae_pdata *pdata = shdev->pdata;
int i;
if (param->slave_id >= SH_DMA_SLAVE_NUMBER)
return NULL;
for (i = 0; i < pdata->slave_num; i++)
if (pdata->slave[i].slave_id == param->slave_id)
return pdata->slave + i;
return NULL;
}
static int sh_dmae_alloc_chan_resources(struct dma_chan *chan)
{
struct sh_dmae_chan *sh_chan = to_sh_chan(chan);
struct sh_desc *desc;
struct sh_dmae_slave *param = chan->private;
int ret;
if (param) {
const struct sh_dmae_slave_config *cfg;
cfg = sh_dmae_find_slave(sh_chan, param);
if (!cfg) {
ret = -EINVAL;
goto efindslave;
}
if (test_and_set_bit(param->slave_id, sh_dmae_slave_used)) {
ret = -EBUSY;
goto etestused;
}
param->config = cfg;
}
while (sh_chan->descs_allocated < NR_DESCS_PER_CHANNEL) {
desc = kzalloc(sizeof(struct sh_desc), GFP_KERNEL);
if (!desc)
break;
dma_async_tx_descriptor_init(&desc->async_tx,
&sh_chan->common);
desc->async_tx.tx_submit = sh_dmae_tx_submit;
desc->mark = DESC_IDLE;
list_add(&desc->node, &sh_chan->ld_free);
sh_chan->descs_allocated++;
}
if (!sh_chan->descs_allocated) {
ret = -ENOMEM;
goto edescalloc;
}
return sh_chan->descs_allocated;
edescalloc:
if (param)
clear_bit(param->slave_id, sh_dmae_slave_used);
etestused:
efindslave:
chan->private = NULL;
return ret;
}
static void sh_dmae_free_chan_resources(struct dma_chan *chan)
{
struct sh_dmae_chan *sh_chan = to_sh_chan(chan);
struct sh_desc *desc, *_desc;
LIST_HEAD(list);
spin_lock_irq(&sh_chan->desc_lock);
dmae_halt(sh_chan);
spin_unlock_irq(&sh_chan->desc_lock);
if (!list_empty(&sh_chan->ld_queue))
sh_dmae_chan_ld_cleanup(sh_chan, true);
if (chan->private) {
struct sh_dmae_slave *param = chan->private;
clear_bit(param->slave_id, sh_dmae_slave_used);
chan->private = NULL;
}
spin_lock_irq(&sh_chan->desc_lock);
list_splice_init(&sh_chan->ld_free, &list);
sh_chan->descs_allocated = 0;
spin_unlock_irq(&sh_chan->desc_lock);
list_for_each_entry_safe(desc, _desc, &list, node)
kfree(desc);
}
static struct sh_desc *sh_dmae_add_desc(struct sh_dmae_chan *sh_chan,
unsigned long flags, dma_addr_t *dest, dma_addr_t *src, size_t *len,
struct sh_desc **first, enum dma_transfer_direction direction)
{
struct sh_desc *new;
size_t copy_size;
if (!*len)
return NULL;
new = sh_dmae_get_desc(sh_chan);
if (!new) {
dev_err(sh_chan->dev, "No free link descriptor available\n");
return NULL;
}
copy_size = min(*len, (size_t)SH_DMA_TCR_MAX + 1);
new->hw.sar = *src;
new->hw.dar = *dest;
new->hw.tcr = copy_size;
if (!*first) {
new->async_tx.cookie = -EBUSY;
*first = new;
} else {
new->async_tx.cookie = -EINVAL;
}
dev_dbg(sh_chan->dev,
"chaining (%u/%u)@%x -> %x with %p, cookie %d, shift %d\n",
copy_size, *len, *src, *dest, &new->async_tx,
new->async_tx.cookie, sh_chan->xmit_shift);
new->mark = DESC_PREPARED;
new->async_tx.flags = flags;
new->direction = direction;
*len -= copy_size;
if (direction == DMA_MEM_TO_MEM || direction == DMA_MEM_TO_DEV)
*src += copy_size;
if (direction == DMA_MEM_TO_MEM || direction == DMA_DEV_TO_MEM)
*dest += copy_size;
return new;
}
static struct dma_async_tx_descriptor *sh_dmae_prep_sg(struct sh_dmae_chan *sh_chan,
struct scatterlist *sgl, unsigned int sg_len, dma_addr_t *addr,
enum dma_transfer_direction direction, unsigned long flags)
{
struct scatterlist *sg;
struct sh_desc *first = NULL, *new = NULL ;
LIST_HEAD(tx_list);
int chunks = 0;
unsigned long irq_flags;
int i;
if (!sg_len)
return NULL;
for_each_sg(sgl, sg, sg_len, i)
chunks += (sg_dma_len(sg) + SH_DMA_TCR_MAX) /
(SH_DMA_TCR_MAX + 1);
spin_lock_irqsave(&sh_chan->desc_lock, irq_flags);
for_each_sg(sgl, sg, sg_len, i) {
dma_addr_t sg_addr = sg_dma_address(sg);
size_t len = sg_dma_len(sg);
if (!len)
goto err_get_desc;
do {
dev_dbg(sh_chan->dev, "Add SG #%d@%p[%d], dma %llx\n",
i, sg, len, (unsigned long long)sg_addr);
if (direction == DMA_DEV_TO_MEM)
new = sh_dmae_add_desc(sh_chan, flags,
&sg_addr, addr, &len, &first,
direction);
else
new = sh_dmae_add_desc(sh_chan, flags,
addr, &sg_addr, &len, &first,
direction);
if (!new)
goto err_get_desc;
new->chunks = chunks--;
list_add_tail(&new->node, &tx_list);
} while (len);
}
if (new != first)
new->async_tx.cookie = -ENOSPC;
list_splice_tail(&tx_list, &sh_chan->ld_free);
spin_unlock_irqrestore(&sh_chan->desc_lock, irq_flags);
return &first->async_tx;
err_get_desc:
list_for_each_entry(new, &tx_list, node)
new->mark = DESC_IDLE;
list_splice(&tx_list, &sh_chan->ld_free);
spin_unlock_irqrestore(&sh_chan->desc_lock, irq_flags);
return NULL;
}
static struct dma_async_tx_descriptor *sh_dmae_prep_memcpy(
struct dma_chan *chan, dma_addr_t dma_dest, dma_addr_t dma_src,
size_t len, unsigned long flags)
{
struct sh_dmae_chan *sh_chan;
struct scatterlist sg;
if (!chan || !len)
return NULL;
sh_chan = to_sh_chan(chan);
sg_init_table(&sg, 1);
sg_set_page(&sg, pfn_to_page(PFN_DOWN(dma_src)), len,
offset_in_page(dma_src));
sg_dma_address(&sg) = dma_src;
sg_dma_len(&sg) = len;
return sh_dmae_prep_sg(sh_chan, &sg, 1, &dma_dest, DMA_MEM_TO_MEM,
flags);
}
static struct dma_async_tx_descriptor *sh_dmae_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl, unsigned int sg_len,
enum dma_transfer_direction direction, unsigned long flags,
void *context)
{
struct sh_dmae_slave *param;
struct sh_dmae_chan *sh_chan;
dma_addr_t slave_addr;
if (!chan)
return NULL;
sh_chan = to_sh_chan(chan);
param = chan->private;
if (!param || !sg_len) {
dev_warn(sh_chan->dev, "%s: bad parameter: %p, %d, %d\n",
__func__, param, sg_len, param ? param->slave_id : -1);
return NULL;
}
slave_addr = param->config->addr;
return sh_dmae_prep_sg(sh_chan, sgl, sg_len, &slave_addr,
direction, flags);
}
static int sh_dmae_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct sh_dmae_chan *sh_chan = to_sh_chan(chan);
unsigned long flags;
if (cmd != DMA_TERMINATE_ALL)
return -ENXIO;
if (!chan)
return -EINVAL;
spin_lock_irqsave(&sh_chan->desc_lock, flags);
dmae_halt(sh_chan);
if (!list_empty(&sh_chan->ld_queue)) {
struct sh_desc *desc = list_entry(sh_chan->ld_queue.next,
struct sh_desc, node);
desc->partial = (desc->hw.tcr - sh_dmae_readl(sh_chan, TCR)) <<
sh_chan->xmit_shift;
}
spin_unlock_irqrestore(&sh_chan->desc_lock, flags);
sh_dmae_chan_ld_cleanup(sh_chan, true);
return 0;
}
static dma_async_tx_callback __ld_cleanup(struct sh_dmae_chan *sh_chan, bool all)
{
struct sh_desc *desc, *_desc;
bool head_acked = false;
dma_cookie_t cookie = 0;
dma_async_tx_callback callback = NULL;
void *param = NULL;
unsigned long flags;
spin_lock_irqsave(&sh_chan->desc_lock, flags);
list_for_each_entry_safe(desc, _desc, &sh_chan->ld_queue, node) {
struct dma_async_tx_descriptor *tx = &desc->async_tx;
BUG_ON(tx->cookie > 0 && tx->cookie != desc->cookie);
BUG_ON(desc->mark != DESC_SUBMITTED &&
desc->mark != DESC_COMPLETED &&
desc->mark != DESC_WAITING);
if (!all && desc->mark == DESC_SUBMITTED &&
desc->cookie != cookie)
break;
if (tx->cookie > 0)
cookie = tx->cookie;
if (desc->mark == DESC_COMPLETED && desc->chunks == 1) {
if (sh_chan->common.completed_cookie != desc->cookie - 1)
dev_dbg(sh_chan->dev,
"Completing cookie %d, expected %d\n",
desc->cookie,
sh_chan->common.completed_cookie + 1);
sh_chan->common.completed_cookie = desc->cookie;
}
if (desc->mark == DESC_COMPLETED && tx->callback) {
desc->mark = DESC_WAITING;
callback = tx->callback;
param = tx->callback_param;
dev_dbg(sh_chan->dev, "descriptor #%d@%p on %d callback\n",
tx->cookie, tx, sh_chan->id);
BUG_ON(desc->chunks != 1);
break;
}
if (tx->cookie > 0 || tx->cookie == -EBUSY) {
if (desc->mark == DESC_COMPLETED) {
BUG_ON(tx->cookie < 0);
desc->mark = DESC_WAITING;
}
head_acked = async_tx_test_ack(tx);
} else {
switch (desc->mark) {
case DESC_COMPLETED:
desc->mark = DESC_WAITING;
case DESC_WAITING:
if (head_acked)
async_tx_ack(&desc->async_tx);
}
}
dev_dbg(sh_chan->dev, "descriptor %p #%d completed.\n",
tx, tx->cookie);
if (((desc->mark == DESC_COMPLETED ||
desc->mark == DESC_WAITING) &&
async_tx_test_ack(&desc->async_tx)) || all) {
desc->mark = DESC_IDLE;
list_move(&desc->node, &sh_chan->ld_free);
if (list_empty(&sh_chan->ld_queue)) {
dev_dbg(sh_chan->dev, "Bring down channel %d\n", sh_chan->id);
pm_runtime_put(sh_chan->dev);
}
}
}
if (all && !callback)
sh_chan->common.completed_cookie = sh_chan->common.cookie;
spin_unlock_irqrestore(&sh_chan->desc_lock, flags);
if (callback)
callback(param);
return callback;
}
static void sh_dmae_chan_ld_cleanup(struct sh_dmae_chan *sh_chan, bool all)
{
while (__ld_cleanup(sh_chan, all))
;
}
static void sh_chan_xfer_ld_queue(struct sh_dmae_chan *sh_chan)
{
struct sh_desc *desc;
if (dmae_is_busy(sh_chan))
return;
list_for_each_entry(desc, &sh_chan->ld_queue, node)
if (desc->mark == DESC_SUBMITTED) {
dev_dbg(sh_chan->dev, "Queue #%d to %d: %u@%x -> %x\n",
desc->async_tx.cookie, sh_chan->id,
desc->hw.tcr, desc->hw.sar, desc->hw.dar);
dmae_set_reg(sh_chan, &desc->hw);
dmae_start(sh_chan);
break;
}
}
static void sh_dmae_memcpy_issue_pending(struct dma_chan *chan)
{
struct sh_dmae_chan *sh_chan = to_sh_chan(chan);
spin_lock_irq(&sh_chan->desc_lock);
if (sh_chan->pm_state == DMAE_PM_ESTABLISHED)
sh_chan_xfer_ld_queue(sh_chan);
else
sh_chan->pm_state = DMAE_PM_PENDING;
spin_unlock_irq(&sh_chan->desc_lock);
}
static enum dma_status sh_dmae_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct sh_dmae_chan *sh_chan = to_sh_chan(chan);
enum dma_status status;
unsigned long flags;
sh_dmae_chan_ld_cleanup(sh_chan, false);
spin_lock_irqsave(&sh_chan->desc_lock, flags);
status = dma_cookie_status(chan, cookie, txstate);
if (status != DMA_SUCCESS) {
struct sh_desc *desc;
status = DMA_ERROR;
list_for_each_entry(desc, &sh_chan->ld_queue, node)
if (desc->cookie == cookie) {
status = DMA_IN_PROGRESS;
break;
}
}
spin_unlock_irqrestore(&sh_chan->desc_lock, flags);
return status;
}
static irqreturn_t sh_dmae_interrupt(int irq, void *data)
{
irqreturn_t ret = IRQ_NONE;
struct sh_dmae_chan *sh_chan = data;
u32 chcr;
spin_lock(&sh_chan->desc_lock);
chcr = chcr_read(sh_chan);
if (chcr & CHCR_TE) {
dmae_halt(sh_chan);
ret = IRQ_HANDLED;
tasklet_schedule(&sh_chan->tasklet);
}
spin_unlock(&sh_chan->desc_lock);
return ret;
}
static bool sh_dmae_reset(struct sh_dmae_device *shdev)
{
unsigned int handled = 0;
int i;
sh_dmae_ctl_stop(shdev);
for (i = 0; i < SH_DMAC_MAX_CHANNELS; i++) {
struct sh_dmae_chan *sh_chan = shdev->chan[i];
struct sh_desc *desc;
LIST_HEAD(dl);
if (!sh_chan)
continue;
spin_lock(&sh_chan->desc_lock);
dmae_halt(sh_chan);
list_splice_init(&sh_chan->ld_queue, &dl);
if (!list_empty(&dl)) {
dev_dbg(sh_chan->dev, "Bring down channel %d\n", sh_chan->id);
pm_runtime_put(sh_chan->dev);
}
sh_chan->pm_state = DMAE_PM_ESTABLISHED;
spin_unlock(&sh_chan->desc_lock);
list_for_each_entry(desc, &dl, node) {
struct dma_async_tx_descriptor *tx = &desc->async_tx;
desc->mark = DESC_IDLE;
if (tx->callback)
tx->callback(tx->callback_param);
}
spin_lock(&sh_chan->desc_lock);
list_splice(&dl, &sh_chan->ld_free);
spin_unlock(&sh_chan->desc_lock);
handled++;
}
sh_dmae_rst(shdev);
return !!handled;
}
static irqreturn_t sh_dmae_err(int irq, void *data)
{
struct sh_dmae_device *shdev = data;
if (!(dmaor_read(shdev) & DMAOR_AE))
return IRQ_NONE;
sh_dmae_reset(data);
return IRQ_HANDLED;
}
static void dmae_do_tasklet(unsigned long data)
{
struct sh_dmae_chan *sh_chan = (struct sh_dmae_chan *)data;
struct sh_desc *desc;
u32 sar_buf = sh_dmae_readl(sh_chan, SAR);
u32 dar_buf = sh_dmae_readl(sh_chan, DAR);
spin_lock_irq(&sh_chan->desc_lock);
list_for_each_entry(desc, &sh_chan->ld_queue, node) {
if (desc->mark == DESC_SUBMITTED &&
((desc->direction == DMA_DEV_TO_MEM &&
(desc->hw.dar + desc->hw.tcr) == dar_buf) ||
(desc->hw.sar + desc->hw.tcr) == sar_buf)) {
dev_dbg(sh_chan->dev, "done #%d@%p dst %u\n",
desc->async_tx.cookie, &desc->async_tx,
desc->hw.dar);
desc->mark = DESC_COMPLETED;
break;
}
}
sh_chan_xfer_ld_queue(sh_chan);
spin_unlock_irq(&sh_chan->desc_lock);
sh_dmae_chan_ld_cleanup(sh_chan, false);
}
static bool sh_dmae_nmi_notify(struct sh_dmae_device *shdev)
{
if ((dmaor_read(shdev) & DMAOR_NMIF) == 0)
return false;
return sh_dmae_reset(shdev);
}
static int sh_dmae_nmi_handler(struct notifier_block *self,
unsigned long cmd, void *data)
{
struct sh_dmae_device *shdev;
int ret = NOTIFY_DONE;
bool triggered;
if (!in_nmi())
return NOTIFY_DONE;
rcu_read_lock();
list_for_each_entry_rcu(shdev, &sh_dmae_devices, node) {
triggered = sh_dmae_nmi_notify(shdev);
if (triggered == true)
ret = NOTIFY_OK;
}
rcu_read_unlock();
return ret;
}
static int __devinit sh_dmae_chan_probe(struct sh_dmae_device *shdev, int id,
int irq, unsigned long flags)
{
int err;
const struct sh_dmae_channel *chan_pdata = &shdev->pdata->channel[id];
struct platform_device *pdev = to_platform_device(shdev->common.dev);
struct sh_dmae_chan *new_sh_chan;
new_sh_chan = kzalloc(sizeof(struct sh_dmae_chan), GFP_KERNEL);
if (!new_sh_chan) {
dev_err(shdev->common.dev,
"No free memory for allocating dma channels!\n");
return -ENOMEM;
}
new_sh_chan->pm_state = DMAE_PM_ESTABLISHED;
new_sh_chan->common.device = &shdev->common;
dma_cookie_init(&new_sh_chan->common);
new_sh_chan->dev = shdev->common.dev;
new_sh_chan->id = id;
new_sh_chan->irq = irq;
new_sh_chan->base = shdev->chan_reg + chan_pdata->offset / sizeof(u32);
tasklet_init(&new_sh_chan->tasklet, dmae_do_tasklet,
(unsigned long)new_sh_chan);
spin_lock_init(&new_sh_chan->desc_lock);
INIT_LIST_HEAD(&new_sh_chan->ld_queue);
INIT_LIST_HEAD(&new_sh_chan->ld_free);
list_add_tail(&new_sh_chan->common.device_node,
&shdev->common.channels);
shdev->common.chancnt++;
if (pdev->id >= 0)
snprintf(new_sh_chan->dev_id, sizeof(new_sh_chan->dev_id),
"sh-dmae%d.%d", pdev->id, new_sh_chan->id);
else
snprintf(new_sh_chan->dev_id, sizeof(new_sh_chan->dev_id),
"sh-dma%d", new_sh_chan->id);
err = request_irq(irq, &sh_dmae_interrupt, flags,
new_sh_chan->dev_id, new_sh_chan);
if (err) {
dev_err(shdev->common.dev, "DMA channel %d request_irq error "
"with return %d\n", id, err);
goto err_no_irq;
}
shdev->chan[id] = new_sh_chan;
return 0;
err_no_irq:
list_del(&new_sh_chan->common.device_node);
kfree(new_sh_chan);
return err;
}
static void sh_dmae_chan_remove(struct sh_dmae_device *shdev)
{
int i;
for (i = shdev->common.chancnt - 1 ; i >= 0 ; i--) {
if (shdev->chan[i]) {
struct sh_dmae_chan *sh_chan = shdev->chan[i];
free_irq(sh_chan->irq, sh_chan);
list_del(&sh_chan->common.device_node);
kfree(sh_chan);
shdev->chan[i] = NULL;
}
}
shdev->common.chancnt = 0;
}
static int __init sh_dmae_probe(struct platform_device *pdev)
{
struct sh_dmae_pdata *pdata = pdev->dev.platform_data;
unsigned long irqflags = IRQF_DISABLED,
chan_flag[SH_DMAC_MAX_CHANNELS] = {};
int errirq, chan_irq[SH_DMAC_MAX_CHANNELS];
int err, i, irq_cnt = 0, irqres = 0, irq_cap = 0;
struct sh_dmae_device *shdev;
struct resource *chan, *dmars, *errirq_res, *chanirq_res;
if (!pdata || !pdata->channel_num)
return -ENODEV;
chan = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dmars = platform_get_resource(pdev, IORESOURCE_MEM, 1);
errirq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!chan || !errirq_res)
return -ENODEV;
if (!request_mem_region(chan->start, resource_size(chan), pdev->name)) {
dev_err(&pdev->dev, "DMAC register region already claimed\n");
return -EBUSY;
}
if (dmars && !request_mem_region(dmars->start, resource_size(dmars), pdev->name)) {
dev_err(&pdev->dev, "DMAC DMARS region already claimed\n");
err = -EBUSY;
goto ermrdmars;
}
err = -ENOMEM;
shdev = kzalloc(sizeof(struct sh_dmae_device), GFP_KERNEL);
if (!shdev) {
dev_err(&pdev->dev, "Not enough memory\n");
goto ealloc;
}
shdev->chan_reg = ioremap(chan->start, resource_size(chan));
if (!shdev->chan_reg)
goto emapchan;
if (dmars) {
shdev->dmars = ioremap(dmars->start, resource_size(dmars));
if (!shdev->dmars)
goto emapdmars;
}
shdev->pdata = pdata;
if (pdata->chcr_offset)
shdev->chcr_offset = pdata->chcr_offset;
else
shdev->chcr_offset = CHCR;
if (pdata->chcr_ie_bit)
shdev->chcr_ie_bit = pdata->chcr_ie_bit;
else
shdev->chcr_ie_bit = CHCR_IE;
platform_set_drvdata(pdev, shdev);
shdev->common.dev = &pdev->dev;
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
spin_lock_irq(&sh_dmae_lock);
list_add_tail_rcu(&shdev->node, &sh_dmae_devices);
spin_unlock_irq(&sh_dmae_lock);
err = sh_dmae_rst(shdev);
if (err)
goto rst_err;
INIT_LIST_HEAD(&shdev->common.channels);
if (!pdata->slave_only)
dma_cap_set(DMA_MEMCPY, shdev->common.cap_mask);
if (pdata->slave && pdata->slave_num)
dma_cap_set(DMA_SLAVE, shdev->common.cap_mask);
shdev->common.device_alloc_chan_resources
= sh_dmae_alloc_chan_resources;
shdev->common.device_free_chan_resources = sh_dmae_free_chan_resources;
shdev->common.device_prep_dma_memcpy = sh_dmae_prep_memcpy;
shdev->common.device_tx_status = sh_dmae_tx_status;
shdev->common.device_issue_pending = sh_dmae_memcpy_issue_pending;
shdev->common.device_prep_slave_sg = sh_dmae_prep_slave_sg;
shdev->common.device_control = sh_dmae_control;
shdev->common.copy_align = LOG2_DEFAULT_XFER_SIZE;
#if defined(CONFIG_CPU_SH4) || defined(CONFIG_ARCH_SHMOBILE)
chanirq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 1);
if (!chanirq_res)
chanirq_res = errirq_res;
else
irqres++;
if (chanirq_res == errirq_res ||
(errirq_res->flags & IORESOURCE_BITS) == IORESOURCE_IRQ_SHAREABLE)
irqflags = IRQF_SHARED;
errirq = errirq_res->start;
err = request_irq(errirq, sh_dmae_err, irqflags,
"DMAC Address Error", shdev);
if (err) {
dev_err(&pdev->dev,
"DMA failed requesting irq #%d, error %d\n",
errirq, err);
goto eirq_err;
}
#else
chanirq_res = errirq_res;
#endif
if (chanirq_res->start == chanirq_res->end &&
!platform_get_resource(pdev, IORESOURCE_IRQ, 1)) {
for (; irq_cnt < pdata->channel_num; irq_cnt++) {
if (irq_cnt < SH_DMAC_MAX_CHANNELS) {
chan_irq[irq_cnt] = chanirq_res->start;
chan_flag[irq_cnt] = IRQF_SHARED;
} else {
irq_cap = 1;
break;
}
}
} else {
do {
for (i = chanirq_res->start; i <= chanirq_res->end; i++) {
if (irq_cnt >= SH_DMAC_MAX_CHANNELS) {
irq_cap = 1;
break;
}
if ((errirq_res->flags & IORESOURCE_BITS) ==
IORESOURCE_IRQ_SHAREABLE)
chan_flag[irq_cnt] = IRQF_SHARED;
else
chan_flag[irq_cnt] = IRQF_DISABLED;
dev_dbg(&pdev->dev,
"Found IRQ %d for channel %d\n",
i, irq_cnt);
chan_irq[irq_cnt++] = i;
}
if (irq_cnt >= SH_DMAC_MAX_CHANNELS)
break;
chanirq_res = platform_get_resource(pdev,
IORESOURCE_IRQ, ++irqres);
} while (irq_cnt < pdata->channel_num && chanirq_res);
}
for (i = 0; i < irq_cnt; i++) {
err = sh_dmae_chan_probe(shdev, i, chan_irq[i], chan_flag[i]);
if (err)
goto chan_probe_err;
}
if (irq_cap)
dev_notice(&pdev->dev, "Attempting to register %d DMA "
"channels when a maximum of %d are supported.\n",
pdata->channel_num, SH_DMAC_MAX_CHANNELS);
pm_runtime_put(&pdev->dev);
dma_async_device_register(&shdev->common);
return err;
chan_probe_err:
sh_dmae_chan_remove(shdev);
#if defined(CONFIG_CPU_SH4) || defined(CONFIG_ARCH_SHMOBILE)
free_irq(errirq, shdev);
eirq_err:
#endif
rst_err:
spin_lock_irq(&sh_dmae_lock);
list_del_rcu(&shdev->node);
spin_unlock_irq(&sh_dmae_lock);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (dmars)
iounmap(shdev->dmars);
platform_set_drvdata(pdev, NULL);
emapdmars:
iounmap(shdev->chan_reg);
synchronize_rcu();
emapchan:
kfree(shdev);
ealloc:
if (dmars)
release_mem_region(dmars->start, resource_size(dmars));
ermrdmars:
release_mem_region(chan->start, resource_size(chan));
return err;
}
static int __exit sh_dmae_remove(struct platform_device *pdev)
{
struct sh_dmae_device *shdev = platform_get_drvdata(pdev);
struct resource *res;
int errirq = platform_get_irq(pdev, 0);
dma_async_device_unregister(&shdev->common);
if (errirq > 0)
free_irq(errirq, shdev);
spin_lock_irq(&sh_dmae_lock);
list_del_rcu(&shdev->node);
spin_unlock_irq(&sh_dmae_lock);
sh_dmae_chan_remove(shdev);
pm_runtime_disable(&pdev->dev);
if (shdev->dmars)
iounmap(shdev->dmars);
iounmap(shdev->chan_reg);
platform_set_drvdata(pdev, NULL);
synchronize_rcu();
kfree(shdev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res)
release_mem_region(res->start, resource_size(res));
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (res)
release_mem_region(res->start, resource_size(res));
return 0;
}
static void sh_dmae_shutdown(struct platform_device *pdev)
{
struct sh_dmae_device *shdev = platform_get_drvdata(pdev);
sh_dmae_ctl_stop(shdev);
}
static int sh_dmae_runtime_suspend(struct device *dev)
{
return 0;
}
static int sh_dmae_runtime_resume(struct device *dev)
{
struct sh_dmae_device *shdev = dev_get_drvdata(dev);
return sh_dmae_rst(shdev);
}
static int sh_dmae_suspend(struct device *dev)
{
return 0;
}
static int sh_dmae_resume(struct device *dev)
{
struct sh_dmae_device *shdev = dev_get_drvdata(dev);
int i, ret;
ret = sh_dmae_rst(shdev);
if (ret < 0)
dev_err(dev, "Failed to reset!\n");
for (i = 0; i < shdev->pdata->channel_num; i++) {
struct sh_dmae_chan *sh_chan = shdev->chan[i];
struct sh_dmae_slave *param = sh_chan->common.private;
if (!sh_chan->descs_allocated)
continue;
if (param) {
const struct sh_dmae_slave_config *cfg = param->config;
dmae_set_dmars(sh_chan, cfg->mid_rid);
dmae_set_chcr(sh_chan, cfg->chcr);
} else {
dmae_init(sh_chan);
}
}
return 0;
}
static int __init sh_dmae_init(void)
{
int err = register_die_notifier(&sh_dmae_nmi_notifier);
if (err)
return err;
return platform_driver_probe(&sh_dmae_driver, sh_dmae_probe);
}
static void __exit sh_dmae_exit(void)
{
platform_driver_unregister(&sh_dmae_driver);
unregister_die_notifier(&sh_dmae_nmi_notifier);
}
