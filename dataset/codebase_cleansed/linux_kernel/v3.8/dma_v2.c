void __ioat2_issue_pending(struct ioat2_dma_chan *ioat)
{
struct ioat_chan_common *chan = &ioat->base;
ioat->dmacount += ioat2_ring_pending(ioat);
ioat->issued = ioat->head;
writew(ioat->dmacount, chan->reg_base + IOAT_CHAN_DMACOUNT_OFFSET);
dev_dbg(to_dev(chan),
"%s: head: %#x tail: %#x issued: %#x count: %#x\n",
__func__, ioat->head, ioat->tail, ioat->issued, ioat->dmacount);
}
void ioat2_issue_pending(struct dma_chan *c)
{
struct ioat2_dma_chan *ioat = to_ioat2_chan(c);
if (ioat2_ring_pending(ioat)) {
spin_lock_bh(&ioat->prep_lock);
__ioat2_issue_pending(ioat);
spin_unlock_bh(&ioat->prep_lock);
}
}
static void ioat2_update_pending(struct ioat2_dma_chan *ioat)
{
if (ioat2_ring_pending(ioat) > ioat_pending_level)
__ioat2_issue_pending(ioat);
}
static void __ioat2_start_null_desc(struct ioat2_dma_chan *ioat)
{
struct ioat_ring_ent *desc;
struct ioat_dma_descriptor *hw;
if (ioat2_ring_space(ioat) < 1) {
dev_err(to_dev(&ioat->base),
"Unable to start null desc - ring full\n");
return;
}
dev_dbg(to_dev(&ioat->base), "%s: head: %#x tail: %#x issued: %#x\n",
__func__, ioat->head, ioat->tail, ioat->issued);
desc = ioat2_get_ring_ent(ioat, ioat->head);
hw = desc->hw;
hw->ctl = 0;
hw->ctl_f.null = 1;
hw->ctl_f.int_en = 1;
hw->ctl_f.compl_write = 1;
hw->size = NULL_DESC_BUFFER_SIZE;
hw->src_addr = 0;
hw->dst_addr = 0;
async_tx_ack(&desc->txd);
ioat2_set_chainaddr(ioat, desc->txd.phys);
dump_desc_dbg(ioat, desc);
wmb();
ioat->head += 1;
__ioat2_issue_pending(ioat);
}
static void ioat2_start_null_desc(struct ioat2_dma_chan *ioat)
{
spin_lock_bh(&ioat->prep_lock);
__ioat2_start_null_desc(ioat);
spin_unlock_bh(&ioat->prep_lock);
}
static void __cleanup(struct ioat2_dma_chan *ioat, dma_addr_t phys_complete)
{
struct ioat_chan_common *chan = &ioat->base;
struct dma_async_tx_descriptor *tx;
struct ioat_ring_ent *desc;
bool seen_current = false;
u16 active;
int idx = ioat->tail, i;
dev_dbg(to_dev(chan), "%s: head: %#x tail: %#x issued: %#x\n",
__func__, ioat->head, ioat->tail, ioat->issued);
active = ioat2_ring_active(ioat);
for (i = 0; i < active && !seen_current; i++) {
smp_read_barrier_depends();
prefetch(ioat2_get_ring_ent(ioat, idx + i + 1));
desc = ioat2_get_ring_ent(ioat, idx + i);
tx = &desc->txd;
dump_desc_dbg(ioat, desc);
if (tx->cookie) {
ioat_dma_unmap(chan, tx->flags, desc->len, desc->hw);
dma_cookie_complete(tx);
if (tx->callback) {
tx->callback(tx->callback_param);
tx->callback = NULL;
}
}
if (tx->phys == phys_complete)
seen_current = true;
}
smp_mb();
ioat->tail = idx + i;
BUG_ON(active && !seen_current);
chan->last_completion = phys_complete;
if (active - i == 0) {
dev_dbg(to_dev(chan), "%s: cancel completion timeout\n",
__func__);
clear_bit(IOAT_COMPLETION_PENDING, &chan->state);
mod_timer(&chan->timer, jiffies + IDLE_TIMEOUT);
}
}
static void ioat2_cleanup(struct ioat2_dma_chan *ioat)
{
struct ioat_chan_common *chan = &ioat->base;
dma_addr_t phys_complete;
spin_lock_bh(&chan->cleanup_lock);
if (ioat_cleanup_preamble(chan, &phys_complete))
__cleanup(ioat, phys_complete);
spin_unlock_bh(&chan->cleanup_lock);
}
void ioat2_cleanup_event(unsigned long data)
{
struct ioat2_dma_chan *ioat = to_ioat2_chan((void *) data);
ioat2_cleanup(ioat);
writew(IOAT_CHANCTRL_RUN, ioat->base.reg_base + IOAT_CHANCTRL_OFFSET);
}
void __ioat2_restart_chan(struct ioat2_dma_chan *ioat)
{
struct ioat_chan_common *chan = &ioat->base;
ioat->issued = ioat->tail;
ioat->dmacount = 0;
set_bit(IOAT_COMPLETION_PENDING, &chan->state);
mod_timer(&chan->timer, jiffies + COMPLETION_TIMEOUT);
dev_dbg(to_dev(chan),
"%s: head: %#x tail: %#x issued: %#x count: %#x\n",
__func__, ioat->head, ioat->tail, ioat->issued, ioat->dmacount);
if (ioat2_ring_pending(ioat)) {
struct ioat_ring_ent *desc;
desc = ioat2_get_ring_ent(ioat, ioat->tail);
ioat2_set_chainaddr(ioat, desc->txd.phys);
__ioat2_issue_pending(ioat);
} else
__ioat2_start_null_desc(ioat);
}
int ioat2_quiesce(struct ioat_chan_common *chan, unsigned long tmo)
{
unsigned long end = jiffies + tmo;
int err = 0;
u32 status;
status = ioat_chansts(chan);
if (is_ioat_active(status) || is_ioat_idle(status))
ioat_suspend(chan);
while (is_ioat_active(status) || is_ioat_idle(status)) {
if (tmo && time_after(jiffies, end)) {
err = -ETIMEDOUT;
break;
}
status = ioat_chansts(chan);
cpu_relax();
}
return err;
}
int ioat2_reset_sync(struct ioat_chan_common *chan, unsigned long tmo)
{
unsigned long end = jiffies + tmo;
int err = 0;
ioat_reset(chan);
while (ioat_reset_pending(chan)) {
if (end && time_after(jiffies, end)) {
err = -ETIMEDOUT;
break;
}
cpu_relax();
}
return err;
}
static void ioat2_restart_channel(struct ioat2_dma_chan *ioat)
{
struct ioat_chan_common *chan = &ioat->base;
dma_addr_t phys_complete;
ioat2_quiesce(chan, 0);
if (ioat_cleanup_preamble(chan, &phys_complete))
__cleanup(ioat, phys_complete);
__ioat2_restart_chan(ioat);
}
void ioat2_timer_event(unsigned long data)
{
struct ioat2_dma_chan *ioat = to_ioat2_chan((void *) data);
struct ioat_chan_common *chan = &ioat->base;
if (test_bit(IOAT_COMPLETION_PENDING, &chan->state)) {
dma_addr_t phys_complete;
u64 status;
status = ioat_chansts(chan);
if (is_ioat_halted(status)) {
u32 chanerr;
chanerr = readl(chan->reg_base + IOAT_CHANERR_OFFSET);
dev_err(to_dev(chan), "%s: Channel halted (%x)\n",
__func__, chanerr);
if (test_bit(IOAT_RUN, &chan->state))
BUG_ON(is_ioat_bug(chanerr));
else
return;
}
spin_lock_bh(&chan->cleanup_lock);
if (ioat_cleanup_preamble(chan, &phys_complete)) {
__cleanup(ioat, phys_complete);
} else if (test_bit(IOAT_COMPLETION_ACK, &chan->state)) {
spin_lock_bh(&ioat->prep_lock);
ioat2_restart_channel(ioat);
spin_unlock_bh(&ioat->prep_lock);
} else {
set_bit(IOAT_COMPLETION_ACK, &chan->state);
mod_timer(&chan->timer, jiffies + COMPLETION_TIMEOUT);
}
spin_unlock_bh(&chan->cleanup_lock);
} else {
u16 active;
spin_lock_bh(&chan->cleanup_lock);
spin_lock_bh(&ioat->prep_lock);
active = ioat2_ring_active(ioat);
if (active == 0 && ioat->alloc_order > ioat_get_alloc_order())
reshape_ring(ioat, ioat->alloc_order-1);
spin_unlock_bh(&ioat->prep_lock);
spin_unlock_bh(&chan->cleanup_lock);
if (ioat->alloc_order > ioat_get_alloc_order())
mod_timer(&chan->timer, jiffies + IDLE_TIMEOUT);
}
}
static int ioat2_reset_hw(struct ioat_chan_common *chan)
{
u32 chanerr;
ioat2_quiesce(chan, msecs_to_jiffies(100));
chanerr = readl(chan->reg_base + IOAT_CHANERR_OFFSET);
writel(chanerr, chan->reg_base + IOAT_CHANERR_OFFSET);
return ioat2_reset_sync(chan, msecs_to_jiffies(200));
}
int ioat2_enumerate_channels(struct ioatdma_device *device)
{
struct ioat2_dma_chan *ioat;
struct device *dev = &device->pdev->dev;
struct dma_device *dma = &device->common;
u8 xfercap_log;
int i;
INIT_LIST_HEAD(&dma->channels);
dma->chancnt = readb(device->reg_base + IOAT_CHANCNT_OFFSET);
dma->chancnt &= 0x1f;
if (dma->chancnt > ARRAY_SIZE(device->idx)) {
dev_warn(dev, "(%d) exceeds max supported channels (%zu)\n",
dma->chancnt, ARRAY_SIZE(device->idx));
dma->chancnt = ARRAY_SIZE(device->idx);
}
xfercap_log = readb(device->reg_base + IOAT_XFERCAP_OFFSET);
xfercap_log &= 0x1f;
if (xfercap_log == 0)
return 0;
dev_dbg(dev, "%s: xfercap = %d\n", __func__, 1 << xfercap_log);
#ifdef CONFIG_I7300_IDLE_IOAT_CHANNEL
if (i7300_idle_platform_probe(NULL, NULL, 1) == 0)
dma->chancnt--;
#endif
for (i = 0; i < dma->chancnt; i++) {
ioat = devm_kzalloc(dev, sizeof(*ioat), GFP_KERNEL);
if (!ioat)
break;
ioat_init_channel(device, &ioat->base, i);
ioat->xfercap_log = xfercap_log;
spin_lock_init(&ioat->prep_lock);
if (device->reset_hw(&ioat->base)) {
i = 0;
break;
}
}
dma->chancnt = i;
return i;
}
static dma_cookie_t ioat2_tx_submit_unlock(struct dma_async_tx_descriptor *tx)
{
struct dma_chan *c = tx->chan;
struct ioat2_dma_chan *ioat = to_ioat2_chan(c);
struct ioat_chan_common *chan = &ioat->base;
dma_cookie_t cookie;
cookie = dma_cookie_assign(tx);
dev_dbg(to_dev(&ioat->base), "%s: cookie: %d\n", __func__, cookie);
if (!test_and_set_bit(IOAT_COMPLETION_PENDING, &chan->state))
mod_timer(&chan->timer, jiffies + COMPLETION_TIMEOUT);
wmb();
ioat->head += ioat->produce;
ioat2_update_pending(ioat);
spin_unlock_bh(&ioat->prep_lock);
return cookie;
}
static struct ioat_ring_ent *ioat2_alloc_ring_ent(struct dma_chan *chan, gfp_t flags)
{
struct ioat_dma_descriptor *hw;
struct ioat_ring_ent *desc;
struct ioatdma_device *dma;
dma_addr_t phys;
dma = to_ioatdma_device(chan->device);
hw = pci_pool_alloc(dma->dma_pool, flags, &phys);
if (!hw)
return NULL;
memset(hw, 0, sizeof(*hw));
desc = kmem_cache_zalloc(ioat2_cache, flags);
if (!desc) {
pci_pool_free(dma->dma_pool, hw, phys);
return NULL;
}
dma_async_tx_descriptor_init(&desc->txd, chan);
desc->txd.tx_submit = ioat2_tx_submit_unlock;
desc->hw = hw;
desc->txd.phys = phys;
return desc;
}
static void ioat2_free_ring_ent(struct ioat_ring_ent *desc, struct dma_chan *chan)
{
struct ioatdma_device *dma;
dma = to_ioatdma_device(chan->device);
pci_pool_free(dma->dma_pool, desc->hw, desc->txd.phys);
kmem_cache_free(ioat2_cache, desc);
}
static struct ioat_ring_ent **ioat2_alloc_ring(struct dma_chan *c, int order, gfp_t flags)
{
struct ioat_ring_ent **ring;
int descs = 1 << order;
int i;
if (order > ioat_get_max_alloc_order())
return NULL;
ring = kcalloc(descs, sizeof(*ring), flags);
if (!ring)
return NULL;
for (i = 0; i < descs; i++) {
ring[i] = ioat2_alloc_ring_ent(c, flags);
if (!ring[i]) {
while (i--)
ioat2_free_ring_ent(ring[i], c);
kfree(ring);
return NULL;
}
set_desc_id(ring[i], i);
}
for (i = 0; i < descs-1; i++) {
struct ioat_ring_ent *next = ring[i+1];
struct ioat_dma_descriptor *hw = ring[i]->hw;
hw->next = next->txd.phys;
}
ring[i]->hw->next = ring[0]->txd.phys;
return ring;
}
int ioat2_alloc_chan_resources(struct dma_chan *c)
{
struct ioat2_dma_chan *ioat = to_ioat2_chan(c);
struct ioat_chan_common *chan = &ioat->base;
struct ioat_ring_ent **ring;
u64 status;
int order;
int i = 0;
if (ioat->ring)
return 1 << ioat->alloc_order;
writew(IOAT_CHANCTRL_RUN, chan->reg_base + IOAT_CHANCTRL_OFFSET);
chan->completion = pci_pool_alloc(chan->device->completion_pool,
GFP_KERNEL, &chan->completion_dma);
if (!chan->completion)
return -ENOMEM;
memset(chan->completion, 0, sizeof(*chan->completion));
writel(((u64) chan->completion_dma) & 0x00000000FFFFFFFF,
chan->reg_base + IOAT_CHANCMP_OFFSET_LOW);
writel(((u64) chan->completion_dma) >> 32,
chan->reg_base + IOAT_CHANCMP_OFFSET_HIGH);
order = ioat_get_alloc_order();
ring = ioat2_alloc_ring(c, order, GFP_KERNEL);
if (!ring)
return -ENOMEM;
spin_lock_bh(&chan->cleanup_lock);
spin_lock_bh(&ioat->prep_lock);
ioat->ring = ring;
ioat->head = 0;
ioat->issued = 0;
ioat->tail = 0;
ioat->alloc_order = order;
spin_unlock_bh(&ioat->prep_lock);
spin_unlock_bh(&chan->cleanup_lock);
tasklet_enable(&chan->cleanup_task);
ioat2_start_null_desc(ioat);
do {
udelay(1);
status = ioat_chansts(chan);
} while (i++ < 20 && !is_ioat_active(status) && !is_ioat_idle(status));
if (is_ioat_active(status) || is_ioat_idle(status)) {
set_bit(IOAT_RUN, &chan->state);
return 1 << ioat->alloc_order;
} else {
u32 chanerr = readl(chan->reg_base + IOAT_CHANERR_OFFSET);
dev_WARN(to_dev(chan),
"failed to start channel chanerr: %#x\n", chanerr);
ioat2_free_chan_resources(c);
return -EFAULT;
}
}
bool reshape_ring(struct ioat2_dma_chan *ioat, int order)
{
struct ioat_chan_common *chan = &ioat->base;
struct dma_chan *c = &chan->common;
const u32 curr_size = ioat2_ring_size(ioat);
const u16 active = ioat2_ring_active(ioat);
const u32 new_size = 1 << order;
struct ioat_ring_ent **ring;
u16 i;
if (order > ioat_get_max_alloc_order())
return false;
if (active == curr_size)
return false;
if (active >= new_size)
return false;
ring = kcalloc(new_size, sizeof(*ring), GFP_NOWAIT);
if (!ring)
return false;
if (new_size > curr_size) {
for (i = 0; i < curr_size; i++) {
u16 curr_idx = (ioat->tail+i) & (curr_size-1);
u16 new_idx = (ioat->tail+i) & (new_size-1);
ring[new_idx] = ioat->ring[curr_idx];
set_desc_id(ring[new_idx], new_idx);
}
for (i = curr_size; i < new_size; i++) {
u16 new_idx = (ioat->tail+i) & (new_size-1);
ring[new_idx] = ioat2_alloc_ring_ent(c, GFP_NOWAIT);
if (!ring[new_idx]) {
while (i--) {
u16 new_idx = (ioat->tail+i) & (new_size-1);
ioat2_free_ring_ent(ring[new_idx], c);
}
kfree(ring);
return false;
}
set_desc_id(ring[new_idx], new_idx);
}
for (i = curr_size-1; i < new_size; i++) {
u16 new_idx = (ioat->tail+i) & (new_size-1);
struct ioat_ring_ent *next = ring[(new_idx+1) & (new_size-1)];
struct ioat_dma_descriptor *hw = ring[new_idx]->hw;
hw->next = next->txd.phys;
}
} else {
struct ioat_dma_descriptor *hw;
struct ioat_ring_ent *next;
for (i = 0; i < new_size; i++) {
u16 curr_idx = (ioat->tail+i) & (curr_size-1);
u16 new_idx = (ioat->tail+i) & (new_size-1);
ring[new_idx] = ioat->ring[curr_idx];
set_desc_id(ring[new_idx], new_idx);
}
for (i = new_size; i < curr_size; i++) {
struct ioat_ring_ent *ent;
ent = ioat2_get_ring_ent(ioat, ioat->tail+i);
ioat2_free_ring_ent(ent, c);
}
hw = ring[(ioat->tail+new_size-1) & (new_size-1)]->hw;
next = ring[(ioat->tail+new_size) & (new_size-1)];
hw->next = next->txd.phys;
}
dev_dbg(to_dev(chan), "%s: allocated %d descriptors\n",
__func__, new_size);
kfree(ioat->ring);
ioat->ring = ring;
ioat->alloc_order = order;
return true;
}
int ioat2_check_space_lock(struct ioat2_dma_chan *ioat, int num_descs)
{
struct ioat_chan_common *chan = &ioat->base;
bool retry;
retry:
spin_lock_bh(&ioat->prep_lock);
if (likely(ioat2_ring_space(ioat) > num_descs)) {
dev_dbg(to_dev(chan), "%s: num_descs: %d (%x:%x:%x)\n",
__func__, num_descs, ioat->head, ioat->tail, ioat->issued);
ioat->produce = num_descs;
return 0;
}
retry = test_and_set_bit(IOAT_RESHAPE_PENDING, &chan->state);
spin_unlock_bh(&ioat->prep_lock);
if (retry)
goto retry;
spin_lock_bh(&chan->cleanup_lock);
spin_lock_bh(&ioat->prep_lock);
retry = reshape_ring(ioat, ioat->alloc_order + 1);
clear_bit(IOAT_RESHAPE_PENDING, &chan->state);
spin_unlock_bh(&ioat->prep_lock);
spin_unlock_bh(&chan->cleanup_lock);
if (retry)
goto retry;
if (printk_ratelimit())
dev_dbg(to_dev(chan), "%s: ring full! num_descs: %d (%x:%x:%x)\n",
__func__, num_descs, ioat->head, ioat->tail, ioat->issued);
if (jiffies > chan->timer.expires && timer_pending(&chan->timer)) {
struct ioatdma_device *device = chan->device;
mod_timer(&chan->timer, jiffies + COMPLETION_TIMEOUT);
device->timer_fn((unsigned long) &chan->common);
}
return -ENOMEM;
}
struct dma_async_tx_descriptor *
ioat2_dma_prep_memcpy_lock(struct dma_chan *c, dma_addr_t dma_dest,
dma_addr_t dma_src, size_t len, unsigned long flags)
{
struct ioat2_dma_chan *ioat = to_ioat2_chan(c);
struct ioat_dma_descriptor *hw;
struct ioat_ring_ent *desc;
dma_addr_t dst = dma_dest;
dma_addr_t src = dma_src;
size_t total_len = len;
int num_descs, idx, i;
num_descs = ioat2_xferlen_to_descs(ioat, len);
if (likely(num_descs) && ioat2_check_space_lock(ioat, num_descs) == 0)
idx = ioat->head;
else
return NULL;
i = 0;
do {
size_t copy = min_t(size_t, len, 1 << ioat->xfercap_log);
desc = ioat2_get_ring_ent(ioat, idx + i);
hw = desc->hw;
hw->size = copy;
hw->ctl = 0;
hw->src_addr = src;
hw->dst_addr = dst;
len -= copy;
dst += copy;
src += copy;
dump_desc_dbg(ioat, desc);
} while (++i < num_descs);
desc->txd.flags = flags;
desc->len = total_len;
hw->ctl_f.int_en = !!(flags & DMA_PREP_INTERRUPT);
hw->ctl_f.fence = !!(flags & DMA_PREP_FENCE);
hw->ctl_f.compl_write = 1;
dump_desc_dbg(ioat, desc);
return &desc->txd;
}
void ioat2_free_chan_resources(struct dma_chan *c)
{
struct ioat2_dma_chan *ioat = to_ioat2_chan(c);
struct ioat_chan_common *chan = &ioat->base;
struct ioatdma_device *device = chan->device;
struct ioat_ring_ent *desc;
const u16 total_descs = 1 << ioat->alloc_order;
int descs;
int i;
if (!ioat->ring)
return;
tasklet_disable(&chan->cleanup_task);
del_timer_sync(&chan->timer);
device->cleanup_fn((unsigned long) c);
device->reset_hw(chan);
clear_bit(IOAT_RUN, &chan->state);
spin_lock_bh(&chan->cleanup_lock);
spin_lock_bh(&ioat->prep_lock);
descs = ioat2_ring_space(ioat);
dev_dbg(to_dev(chan), "freeing %d idle descriptors\n", descs);
for (i = 0; i < descs; i++) {
desc = ioat2_get_ring_ent(ioat, ioat->head + i);
ioat2_free_ring_ent(desc, c);
}
if (descs < total_descs)
dev_err(to_dev(chan), "Freeing %d in use descriptors!\n",
total_descs - descs);
for (i = 0; i < total_descs - descs; i++) {
desc = ioat2_get_ring_ent(ioat, ioat->tail + i);
dump_desc_dbg(ioat, desc);
ioat2_free_ring_ent(desc, c);
}
kfree(ioat->ring);
ioat->ring = NULL;
ioat->alloc_order = 0;
pci_pool_free(device->completion_pool, chan->completion,
chan->completion_dma);
spin_unlock_bh(&ioat->prep_lock);
spin_unlock_bh(&chan->cleanup_lock);
chan->last_completion = 0;
chan->completion_dma = 0;
ioat->dmacount = 0;
}
static ssize_t ring_size_show(struct dma_chan *c, char *page)
{
struct ioat2_dma_chan *ioat = to_ioat2_chan(c);
return sprintf(page, "%d\n", (1 << ioat->alloc_order) & ~1);
}
static ssize_t ring_active_show(struct dma_chan *c, char *page)
{
struct ioat2_dma_chan *ioat = to_ioat2_chan(c);
return sprintf(page, "%d\n", ioat2_ring_active(ioat));
}
int ioat2_dma_probe(struct ioatdma_device *device, int dca)
{
struct pci_dev *pdev = device->pdev;
struct dma_device *dma;
struct dma_chan *c;
struct ioat_chan_common *chan;
int err;
device->enumerate_channels = ioat2_enumerate_channels;
device->reset_hw = ioat2_reset_hw;
device->cleanup_fn = ioat2_cleanup_event;
device->timer_fn = ioat2_timer_event;
device->self_test = ioat_dma_self_test;
dma = &device->common;
dma->device_prep_dma_memcpy = ioat2_dma_prep_memcpy_lock;
dma->device_issue_pending = ioat2_issue_pending;
dma->device_alloc_chan_resources = ioat2_alloc_chan_resources;
dma->device_free_chan_resources = ioat2_free_chan_resources;
dma->device_tx_status = ioat_dma_tx_status;
err = ioat_probe(device);
if (err)
return err;
ioat_set_tcp_copy_break(2048);
list_for_each_entry(c, &dma->channels, device_node) {
chan = to_chan_common(c);
writel(IOAT_DCACTRL_CMPL_WRITE_ENABLE | IOAT_DMA_DCA_ANY_CPU,
chan->reg_base + IOAT_DCACTRL_OFFSET);
}
err = ioat_register(device);
if (err)
return err;
ioat_kobject_add(device, &ioat2_ktype);
if (dca)
device->dca = ioat2_dca_init(pdev, device->reg_base);
return err;
}
