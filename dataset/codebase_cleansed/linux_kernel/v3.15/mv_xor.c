static void mv_desc_init(struct mv_xor_desc_slot *desc, unsigned long flags)
{
struct mv_xor_desc *hw_desc = desc->hw_desc;
hw_desc->status = (1 << 31);
hw_desc->phy_next_desc = 0;
hw_desc->desc_command = (1 << 31);
}
static void mv_desc_set_byte_count(struct mv_xor_desc_slot *desc,
u32 byte_count)
{
struct mv_xor_desc *hw_desc = desc->hw_desc;
hw_desc->byte_count = byte_count;
}
static void mv_desc_set_next_desc(struct mv_xor_desc_slot *desc,
u32 next_desc_addr)
{
struct mv_xor_desc *hw_desc = desc->hw_desc;
BUG_ON(hw_desc->phy_next_desc);
hw_desc->phy_next_desc = next_desc_addr;
}
static void mv_desc_clear_next_desc(struct mv_xor_desc_slot *desc)
{
struct mv_xor_desc *hw_desc = desc->hw_desc;
hw_desc->phy_next_desc = 0;
}
static void mv_desc_set_dest_addr(struct mv_xor_desc_slot *desc,
dma_addr_t addr)
{
struct mv_xor_desc *hw_desc = desc->hw_desc;
hw_desc->phy_dest_addr = addr;
}
static int mv_chan_memset_slot_count(size_t len)
{
return 1;
}
static void mv_desc_set_src_addr(struct mv_xor_desc_slot *desc,
int index, dma_addr_t addr)
{
struct mv_xor_desc *hw_desc = desc->hw_desc;
hw_desc->phy_src_addr[mv_phy_src_idx(index)] = addr;
if (desc->type == DMA_XOR)
hw_desc->desc_command |= (1 << index);
}
static u32 mv_chan_get_current_desc(struct mv_xor_chan *chan)
{
return readl_relaxed(XOR_CURR_DESC(chan));
}
static void mv_chan_set_next_descriptor(struct mv_xor_chan *chan,
u32 next_desc_addr)
{
writel_relaxed(next_desc_addr, XOR_NEXT_DESC(chan));
}
static void mv_chan_unmask_interrupts(struct mv_xor_chan *chan)
{
u32 val = readl_relaxed(XOR_INTR_MASK(chan));
val |= XOR_INTR_MASK_VALUE << (chan->idx * 16);
writel_relaxed(val, XOR_INTR_MASK(chan));
}
static u32 mv_chan_get_intr_cause(struct mv_xor_chan *chan)
{
u32 intr_cause = readl_relaxed(XOR_INTR_CAUSE(chan));
intr_cause = (intr_cause >> (chan->idx * 16)) & 0xFFFF;
return intr_cause;
}
static int mv_is_err_intr(u32 intr_cause)
{
if (intr_cause & ((1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8)|(1<<9)))
return 1;
return 0;
}
static void mv_xor_device_clear_eoc_cause(struct mv_xor_chan *chan)
{
u32 val = ~(1 << (chan->idx * 16));
dev_dbg(mv_chan_to_devp(chan), "%s, val 0x%08x\n", __func__, val);
writel_relaxed(val, XOR_INTR_CAUSE(chan));
}
static void mv_xor_device_clear_err_status(struct mv_xor_chan *chan)
{
u32 val = 0xFFFF0000 >> (chan->idx * 16);
writel_relaxed(val, XOR_INTR_CAUSE(chan));
}
static int mv_can_chain(struct mv_xor_desc_slot *desc)
{
struct mv_xor_desc_slot *chain_old_tail = list_entry(
desc->chain_node.prev, struct mv_xor_desc_slot, chain_node);
if (chain_old_tail->type != desc->type)
return 0;
return 1;
}
static void mv_set_mode(struct mv_xor_chan *chan,
enum dma_transaction_type type)
{
u32 op_mode;
u32 config = readl_relaxed(XOR_CONFIG(chan));
switch (type) {
case DMA_XOR:
op_mode = XOR_OPERATION_MODE_XOR;
break;
case DMA_MEMCPY:
op_mode = XOR_OPERATION_MODE_MEMCPY;
break;
default:
dev_err(mv_chan_to_devp(chan),
"error: unsupported operation %d\n",
type);
BUG();
return;
}
config &= ~0x7;
config |= op_mode;
#if defined(__BIG_ENDIAN)
config |= XOR_DESCRIPTOR_SWAP;
#else
config &= ~XOR_DESCRIPTOR_SWAP;
#endif
writel_relaxed(config, XOR_CONFIG(chan));
chan->current_type = type;
}
static void mv_chan_activate(struct mv_xor_chan *chan)
{
dev_dbg(mv_chan_to_devp(chan), " activate chan.\n");
writel(BIT(0), XOR_ACTIVATION(chan));
}
static char mv_chan_is_busy(struct mv_xor_chan *chan)
{
u32 state = readl_relaxed(XOR_ACTIVATION(chan));
state = (state >> 4) & 0x3;
return (state == 1) ? 1 : 0;
}
static int mv_chan_xor_slot_count(size_t len, int src_cnt)
{
return 1;
}
static void mv_xor_free_slots(struct mv_xor_chan *mv_chan,
struct mv_xor_desc_slot *slot)
{
dev_dbg(mv_chan_to_devp(mv_chan), "%s %d slot %p\n",
__func__, __LINE__, slot);
slot->slots_per_op = 0;
}
static void mv_xor_start_new_chain(struct mv_xor_chan *mv_chan,
struct mv_xor_desc_slot *sw_desc)
{
dev_dbg(mv_chan_to_devp(mv_chan), "%s %d: sw_desc %p\n",
__func__, __LINE__, sw_desc);
if (sw_desc->type != mv_chan->current_type)
mv_set_mode(mv_chan, sw_desc->type);
mv_chan_set_next_descriptor(mv_chan, sw_desc->async_tx.phys);
mv_chan->pending += sw_desc->slot_cnt;
mv_xor_issue_pending(&mv_chan->dmachan);
}
static dma_cookie_t
mv_xor_run_tx_complete_actions(struct mv_xor_desc_slot *desc,
struct mv_xor_chan *mv_chan, dma_cookie_t cookie)
{
BUG_ON(desc->async_tx.cookie < 0);
if (desc->async_tx.cookie > 0) {
cookie = desc->async_tx.cookie;
if (desc->async_tx.callback)
desc->async_tx.callback(
desc->async_tx.callback_param);
dma_descriptor_unmap(&desc->async_tx);
if (desc->group_head)
desc->group_head = NULL;
}
dma_run_dependencies(&desc->async_tx);
return cookie;
}
static int
mv_xor_clean_completed_slots(struct mv_xor_chan *mv_chan)
{
struct mv_xor_desc_slot *iter, *_iter;
dev_dbg(mv_chan_to_devp(mv_chan), "%s %d\n", __func__, __LINE__);
list_for_each_entry_safe(iter, _iter, &mv_chan->completed_slots,
completed_node) {
if (async_tx_test_ack(&iter->async_tx)) {
list_del(&iter->completed_node);
mv_xor_free_slots(mv_chan, iter);
}
}
return 0;
}
static int
mv_xor_clean_slot(struct mv_xor_desc_slot *desc,
struct mv_xor_chan *mv_chan)
{
dev_dbg(mv_chan_to_devp(mv_chan), "%s %d: desc %p flags %d\n",
__func__, __LINE__, desc, desc->async_tx.flags);
list_del(&desc->chain_node);
if (!async_tx_test_ack(&desc->async_tx)) {
list_add_tail(&desc->completed_node, &mv_chan->completed_slots);
return 0;
}
mv_xor_free_slots(mv_chan, desc);
return 0;
}
static void __mv_xor_slot_cleanup(struct mv_xor_chan *mv_chan)
{
struct mv_xor_desc_slot *iter, *_iter;
dma_cookie_t cookie = 0;
int busy = mv_chan_is_busy(mv_chan);
u32 current_desc = mv_chan_get_current_desc(mv_chan);
int seen_current = 0;
dev_dbg(mv_chan_to_devp(mv_chan), "%s %d\n", __func__, __LINE__);
dev_dbg(mv_chan_to_devp(mv_chan), "current_desc %x\n", current_desc);
mv_xor_clean_completed_slots(mv_chan);
list_for_each_entry_safe(iter, _iter, &mv_chan->chain,
chain_node) {
prefetch(_iter);
prefetch(&_iter->async_tx);
if (seen_current)
break;
if (iter->async_tx.phys == current_desc) {
seen_current = 1;
if (busy)
break;
}
cookie = mv_xor_run_tx_complete_actions(iter, mv_chan, cookie);
if (mv_xor_clean_slot(iter, mv_chan))
break;
}
if ((busy == 0) && !list_empty(&mv_chan->chain)) {
struct mv_xor_desc_slot *chain_head;
chain_head = list_entry(mv_chan->chain.next,
struct mv_xor_desc_slot,
chain_node);
mv_xor_start_new_chain(mv_chan, chain_head);
}
if (cookie > 0)
mv_chan->dmachan.completed_cookie = cookie;
}
static void
mv_xor_slot_cleanup(struct mv_xor_chan *mv_chan)
{
spin_lock_bh(&mv_chan->lock);
__mv_xor_slot_cleanup(mv_chan);
spin_unlock_bh(&mv_chan->lock);
}
static void mv_xor_tasklet(unsigned long data)
{
struct mv_xor_chan *chan = (struct mv_xor_chan *) data;
mv_xor_slot_cleanup(chan);
}
static struct mv_xor_desc_slot *
mv_xor_alloc_slots(struct mv_xor_chan *mv_chan, int num_slots,
int slots_per_op)
{
struct mv_xor_desc_slot *iter, *_iter, *alloc_start = NULL;
LIST_HEAD(chain);
int slots_found, retry = 0;
retry:
slots_found = 0;
if (retry == 0)
iter = mv_chan->last_used;
else
iter = list_entry(&mv_chan->all_slots,
struct mv_xor_desc_slot,
slot_node);
list_for_each_entry_safe_continue(
iter, _iter, &mv_chan->all_slots, slot_node) {
prefetch(_iter);
prefetch(&_iter->async_tx);
if (iter->slots_per_op) {
if (retry)
break;
slots_found = 0;
continue;
}
if (!slots_found++)
alloc_start = iter;
if (slots_found == num_slots) {
struct mv_xor_desc_slot *alloc_tail = NULL;
struct mv_xor_desc_slot *last_used = NULL;
iter = alloc_start;
while (num_slots) {
int i;
async_tx_ack(&iter->async_tx);
list_add_tail(&iter->chain_node, &chain);
alloc_tail = iter;
iter->async_tx.cookie = 0;
iter->slot_cnt = num_slots;
iter->xor_check_result = NULL;
for (i = 0; i < slots_per_op; i++) {
iter->slots_per_op = slots_per_op - i;
last_used = iter;
iter = list_entry(iter->slot_node.next,
struct mv_xor_desc_slot,
slot_node);
}
num_slots -= slots_per_op;
}
alloc_tail->group_head = alloc_start;
alloc_tail->async_tx.cookie = -EBUSY;
list_splice(&chain, &alloc_tail->tx_list);
mv_chan->last_used = last_used;
mv_desc_clear_next_desc(alloc_start);
mv_desc_clear_next_desc(alloc_tail);
return alloc_tail;
}
}
if (!retry++)
goto retry;
tasklet_schedule(&mv_chan->irq_tasklet);
return NULL;
}
static dma_cookie_t
mv_xor_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct mv_xor_desc_slot *sw_desc = to_mv_xor_slot(tx);
struct mv_xor_chan *mv_chan = to_mv_xor_chan(tx->chan);
struct mv_xor_desc_slot *grp_start, *old_chain_tail;
dma_cookie_t cookie;
int new_hw_chain = 1;
dev_dbg(mv_chan_to_devp(mv_chan),
"%s sw_desc %p: async_tx %p\n",
__func__, sw_desc, &sw_desc->async_tx);
grp_start = sw_desc->group_head;
spin_lock_bh(&mv_chan->lock);
cookie = dma_cookie_assign(tx);
if (list_empty(&mv_chan->chain))
list_splice_init(&sw_desc->tx_list, &mv_chan->chain);
else {
new_hw_chain = 0;
old_chain_tail = list_entry(mv_chan->chain.prev,
struct mv_xor_desc_slot,
chain_node);
list_splice_init(&grp_start->tx_list,
&old_chain_tail->chain_node);
if (!mv_can_chain(grp_start))
goto submit_done;
dev_dbg(mv_chan_to_devp(mv_chan), "Append to last desc %pa\n",
&old_chain_tail->async_tx.phys);
mv_desc_set_next_desc(old_chain_tail, grp_start->async_tx.phys);
if (!mv_chan_is_busy(mv_chan)) {
u32 current_desc = mv_chan_get_current_desc(mv_chan);
if (current_desc == old_chain_tail->async_tx.phys)
new_hw_chain = 1;
}
}
if (new_hw_chain)
mv_xor_start_new_chain(mv_chan, grp_start);
submit_done:
spin_unlock_bh(&mv_chan->lock);
return cookie;
}
static int mv_xor_alloc_chan_resources(struct dma_chan *chan)
{
void *virt_desc;
dma_addr_t dma_desc;
int idx;
struct mv_xor_chan *mv_chan = to_mv_xor_chan(chan);
struct mv_xor_desc_slot *slot = NULL;
int num_descs_in_pool = MV_XOR_POOL_SIZE/MV_XOR_SLOT_SIZE;
idx = mv_chan->slots_allocated;
while (idx < num_descs_in_pool) {
slot = kzalloc(sizeof(*slot), GFP_KERNEL);
if (!slot) {
printk(KERN_INFO "MV XOR Channel only initialized"
" %d descriptor slots", idx);
break;
}
virt_desc = mv_chan->dma_desc_pool_virt;
slot->hw_desc = virt_desc + idx * MV_XOR_SLOT_SIZE;
dma_async_tx_descriptor_init(&slot->async_tx, chan);
slot->async_tx.tx_submit = mv_xor_tx_submit;
INIT_LIST_HEAD(&slot->chain_node);
INIT_LIST_HEAD(&slot->slot_node);
INIT_LIST_HEAD(&slot->tx_list);
dma_desc = mv_chan->dma_desc_pool;
slot->async_tx.phys = dma_desc + idx * MV_XOR_SLOT_SIZE;
slot->idx = idx++;
spin_lock_bh(&mv_chan->lock);
mv_chan->slots_allocated = idx;
list_add_tail(&slot->slot_node, &mv_chan->all_slots);
spin_unlock_bh(&mv_chan->lock);
}
if (mv_chan->slots_allocated && !mv_chan->last_used)
mv_chan->last_used = list_entry(mv_chan->all_slots.next,
struct mv_xor_desc_slot,
slot_node);
dev_dbg(mv_chan_to_devp(mv_chan),
"allocated %d descriptor slots last_used: %p\n",
mv_chan->slots_allocated, mv_chan->last_used);
return mv_chan->slots_allocated ? : -ENOMEM;
}
static struct dma_async_tx_descriptor *
mv_xor_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long flags)
{
struct mv_xor_chan *mv_chan = to_mv_xor_chan(chan);
struct mv_xor_desc_slot *sw_desc, *grp_start;
int slot_cnt;
dev_dbg(mv_chan_to_devp(mv_chan),
"%s dest: %pad src %pad len: %u flags: %ld\n",
__func__, &dest, &src, len, flags);
if (unlikely(len < MV_XOR_MIN_BYTE_COUNT))
return NULL;
BUG_ON(len > MV_XOR_MAX_BYTE_COUNT);
spin_lock_bh(&mv_chan->lock);
slot_cnt = mv_chan_memcpy_slot_count(len);
sw_desc = mv_xor_alloc_slots(mv_chan, slot_cnt, 1);
if (sw_desc) {
sw_desc->type = DMA_MEMCPY;
sw_desc->async_tx.flags = flags;
grp_start = sw_desc->group_head;
mv_desc_init(grp_start, flags);
mv_desc_set_byte_count(grp_start, len);
mv_desc_set_dest_addr(sw_desc->group_head, dest);
mv_desc_set_src_addr(grp_start, 0, src);
sw_desc->unmap_src_cnt = 1;
sw_desc->unmap_len = len;
}
spin_unlock_bh(&mv_chan->lock);
dev_dbg(mv_chan_to_devp(mv_chan),
"%s sw_desc %p async_tx %p\n",
__func__, sw_desc, sw_desc ? &sw_desc->async_tx : NULL);
return sw_desc ? &sw_desc->async_tx : NULL;
}
static struct dma_async_tx_descriptor *
mv_xor_prep_dma_xor(struct dma_chan *chan, dma_addr_t dest, dma_addr_t *src,
unsigned int src_cnt, size_t len, unsigned long flags)
{
struct mv_xor_chan *mv_chan = to_mv_xor_chan(chan);
struct mv_xor_desc_slot *sw_desc, *grp_start;
int slot_cnt;
if (unlikely(len < MV_XOR_MIN_BYTE_COUNT))
return NULL;
BUG_ON(len > MV_XOR_MAX_BYTE_COUNT);
dev_dbg(mv_chan_to_devp(mv_chan),
"%s src_cnt: %d len: %u dest %pad flags: %ld\n",
__func__, src_cnt, len, &dest, flags);
spin_lock_bh(&mv_chan->lock);
slot_cnt = mv_chan_xor_slot_count(len, src_cnt);
sw_desc = mv_xor_alloc_slots(mv_chan, slot_cnt, 1);
if (sw_desc) {
sw_desc->type = DMA_XOR;
sw_desc->async_tx.flags = flags;
grp_start = sw_desc->group_head;
mv_desc_init(grp_start, flags);
mv_desc_set_byte_count(grp_start, len);
mv_desc_set_dest_addr(sw_desc->group_head, dest);
sw_desc->unmap_src_cnt = src_cnt;
sw_desc->unmap_len = len;
while (src_cnt--)
mv_desc_set_src_addr(grp_start, src_cnt, src[src_cnt]);
}
spin_unlock_bh(&mv_chan->lock);
dev_dbg(mv_chan_to_devp(mv_chan),
"%s sw_desc %p async_tx %p \n",
__func__, sw_desc, &sw_desc->async_tx);
return sw_desc ? &sw_desc->async_tx : NULL;
}
static void mv_xor_free_chan_resources(struct dma_chan *chan)
{
struct mv_xor_chan *mv_chan = to_mv_xor_chan(chan);
struct mv_xor_desc_slot *iter, *_iter;
int in_use_descs = 0;
mv_xor_slot_cleanup(mv_chan);
spin_lock_bh(&mv_chan->lock);
list_for_each_entry_safe(iter, _iter, &mv_chan->chain,
chain_node) {
in_use_descs++;
list_del(&iter->chain_node);
}
list_for_each_entry_safe(iter, _iter, &mv_chan->completed_slots,
completed_node) {
in_use_descs++;
list_del(&iter->completed_node);
}
list_for_each_entry_safe_reverse(
iter, _iter, &mv_chan->all_slots, slot_node) {
list_del(&iter->slot_node);
kfree(iter);
mv_chan->slots_allocated--;
}
mv_chan->last_used = NULL;
dev_dbg(mv_chan_to_devp(mv_chan), "%s slots_allocated %d\n",
__func__, mv_chan->slots_allocated);
spin_unlock_bh(&mv_chan->lock);
if (in_use_descs)
dev_err(mv_chan_to_devp(mv_chan),
"freeing %d in use descriptors!\n", in_use_descs);
}
static enum dma_status mv_xor_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct mv_xor_chan *mv_chan = to_mv_xor_chan(chan);
enum dma_status ret;
ret = dma_cookie_status(chan, cookie, txstate);
if (ret == DMA_COMPLETE) {
mv_xor_clean_completed_slots(mv_chan);
return ret;
}
mv_xor_slot_cleanup(mv_chan);
return dma_cookie_status(chan, cookie, txstate);
}
static void mv_dump_xor_regs(struct mv_xor_chan *chan)
{
u32 val;
val = readl_relaxed(XOR_CONFIG(chan));
dev_err(mv_chan_to_devp(chan), "config 0x%08x\n", val);
val = readl_relaxed(XOR_ACTIVATION(chan));
dev_err(mv_chan_to_devp(chan), "activation 0x%08x\n", val);
val = readl_relaxed(XOR_INTR_CAUSE(chan));
dev_err(mv_chan_to_devp(chan), "intr cause 0x%08x\n", val);
val = readl_relaxed(XOR_INTR_MASK(chan));
dev_err(mv_chan_to_devp(chan), "intr mask 0x%08x\n", val);
val = readl_relaxed(XOR_ERROR_CAUSE(chan));
dev_err(mv_chan_to_devp(chan), "error cause 0x%08x\n", val);
val = readl_relaxed(XOR_ERROR_ADDR(chan));
dev_err(mv_chan_to_devp(chan), "error addr 0x%08x\n", val);
}
static void mv_xor_err_interrupt_handler(struct mv_xor_chan *chan,
u32 intr_cause)
{
if (intr_cause & (1 << 4)) {
dev_dbg(mv_chan_to_devp(chan),
"ignore this error\n");
return;
}
dev_err(mv_chan_to_devp(chan),
"error on chan %d. intr cause 0x%08x\n",
chan->idx, intr_cause);
mv_dump_xor_regs(chan);
BUG();
}
static irqreturn_t mv_xor_interrupt_handler(int irq, void *data)
{
struct mv_xor_chan *chan = data;
u32 intr_cause = mv_chan_get_intr_cause(chan);
dev_dbg(mv_chan_to_devp(chan), "intr cause %x\n", intr_cause);
if (mv_is_err_intr(intr_cause))
mv_xor_err_interrupt_handler(chan, intr_cause);
tasklet_schedule(&chan->irq_tasklet);
mv_xor_device_clear_eoc_cause(chan);
return IRQ_HANDLED;
}
static void mv_xor_issue_pending(struct dma_chan *chan)
{
struct mv_xor_chan *mv_chan = to_mv_xor_chan(chan);
if (mv_chan->pending >= MV_XOR_THRESHOLD) {
mv_chan->pending = 0;
mv_chan_activate(mv_chan);
}
}
static int mv_xor_memcpy_self_test(struct mv_xor_chan *mv_chan)
{
int i;
void *src, *dest;
dma_addr_t src_dma, dest_dma;
struct dma_chan *dma_chan;
dma_cookie_t cookie;
struct dma_async_tx_descriptor *tx;
struct dmaengine_unmap_data *unmap;
int err = 0;
src = kmalloc(sizeof(u8) * PAGE_SIZE, GFP_KERNEL);
if (!src)
return -ENOMEM;
dest = kzalloc(sizeof(u8) * PAGE_SIZE, GFP_KERNEL);
if (!dest) {
kfree(src);
return -ENOMEM;
}
for (i = 0; i < PAGE_SIZE; i++)
((u8 *) src)[i] = (u8)i;
dma_chan = &mv_chan->dmachan;
if (mv_xor_alloc_chan_resources(dma_chan) < 1) {
err = -ENODEV;
goto out;
}
unmap = dmaengine_get_unmap_data(dma_chan->device->dev, 2, GFP_KERNEL);
if (!unmap) {
err = -ENOMEM;
goto free_resources;
}
src_dma = dma_map_page(dma_chan->device->dev, virt_to_page(src), 0,
PAGE_SIZE, DMA_TO_DEVICE);
unmap->to_cnt = 1;
unmap->addr[0] = src_dma;
dest_dma = dma_map_page(dma_chan->device->dev, virt_to_page(dest), 0,
PAGE_SIZE, DMA_FROM_DEVICE);
unmap->from_cnt = 1;
unmap->addr[1] = dest_dma;
unmap->len = PAGE_SIZE;
tx = mv_xor_prep_dma_memcpy(dma_chan, dest_dma, src_dma,
PAGE_SIZE, 0);
cookie = mv_xor_tx_submit(tx);
mv_xor_issue_pending(dma_chan);
async_tx_ack(tx);
msleep(1);
if (mv_xor_status(dma_chan, cookie, NULL) !=
DMA_COMPLETE) {
dev_err(dma_chan->device->dev,
"Self-test copy timed out, disabling\n");
err = -ENODEV;
goto free_resources;
}
dma_sync_single_for_cpu(dma_chan->device->dev, dest_dma,
PAGE_SIZE, DMA_FROM_DEVICE);
if (memcmp(src, dest, PAGE_SIZE)) {
dev_err(dma_chan->device->dev,
"Self-test copy failed compare, disabling\n");
err = -ENODEV;
goto free_resources;
}
free_resources:
dmaengine_unmap_put(unmap);
mv_xor_free_chan_resources(dma_chan);
out:
kfree(src);
kfree(dest);
return err;
}
static int
mv_xor_xor_self_test(struct mv_xor_chan *mv_chan)
{
int i, src_idx;
struct page *dest;
struct page *xor_srcs[MV_XOR_NUM_SRC_TEST];
dma_addr_t dma_srcs[MV_XOR_NUM_SRC_TEST];
dma_addr_t dest_dma;
struct dma_async_tx_descriptor *tx;
struct dmaengine_unmap_data *unmap;
struct dma_chan *dma_chan;
dma_cookie_t cookie;
u8 cmp_byte = 0;
u32 cmp_word;
int err = 0;
int src_count = MV_XOR_NUM_SRC_TEST;
for (src_idx = 0; src_idx < src_count; src_idx++) {
xor_srcs[src_idx] = alloc_page(GFP_KERNEL);
if (!xor_srcs[src_idx]) {
while (src_idx--)
__free_page(xor_srcs[src_idx]);
return -ENOMEM;
}
}
dest = alloc_page(GFP_KERNEL);
if (!dest) {
while (src_idx--)
__free_page(xor_srcs[src_idx]);
return -ENOMEM;
}
for (src_idx = 0; src_idx < src_count; src_idx++) {
u8 *ptr = page_address(xor_srcs[src_idx]);
for (i = 0; i < PAGE_SIZE; i++)
ptr[i] = (1 << src_idx);
}
for (src_idx = 0; src_idx < src_count; src_idx++)
cmp_byte ^= (u8) (1 << src_idx);
cmp_word = (cmp_byte << 24) | (cmp_byte << 16) |
(cmp_byte << 8) | cmp_byte;
memset(page_address(dest), 0, PAGE_SIZE);
dma_chan = &mv_chan->dmachan;
if (mv_xor_alloc_chan_resources(dma_chan) < 1) {
err = -ENODEV;
goto out;
}
unmap = dmaengine_get_unmap_data(dma_chan->device->dev, src_count + 1,
GFP_KERNEL);
if (!unmap) {
err = -ENOMEM;
goto free_resources;
}
for (i = 0; i < src_count; i++) {
unmap->addr[i] = dma_map_page(dma_chan->device->dev, xor_srcs[i],
0, PAGE_SIZE, DMA_TO_DEVICE);
dma_srcs[i] = unmap->addr[i];
unmap->to_cnt++;
}
unmap->addr[src_count] = dma_map_page(dma_chan->device->dev, dest, 0, PAGE_SIZE,
DMA_FROM_DEVICE);
dest_dma = unmap->addr[src_count];
unmap->from_cnt = 1;
unmap->len = PAGE_SIZE;
tx = mv_xor_prep_dma_xor(dma_chan, dest_dma, dma_srcs,
src_count, PAGE_SIZE, 0);
cookie = mv_xor_tx_submit(tx);
mv_xor_issue_pending(dma_chan);
async_tx_ack(tx);
msleep(8);
if (mv_xor_status(dma_chan, cookie, NULL) !=
DMA_COMPLETE) {
dev_err(dma_chan->device->dev,
"Self-test xor timed out, disabling\n");
err = -ENODEV;
goto free_resources;
}
dma_sync_single_for_cpu(dma_chan->device->dev, dest_dma,
PAGE_SIZE, DMA_FROM_DEVICE);
for (i = 0; i < (PAGE_SIZE / sizeof(u32)); i++) {
u32 *ptr = page_address(dest);
if (ptr[i] != cmp_word) {
dev_err(dma_chan->device->dev,
"Self-test xor failed compare, disabling. index %d, data %x, expected %x\n",
i, ptr[i], cmp_word);
err = -ENODEV;
goto free_resources;
}
}
free_resources:
dmaengine_unmap_put(unmap);
mv_xor_free_chan_resources(dma_chan);
out:
src_idx = src_count;
while (src_idx--)
__free_page(xor_srcs[src_idx]);
__free_page(dest);
return err;
}
static int
mv_xor_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
return -ENOSYS;
}
static int mv_xor_channel_remove(struct mv_xor_chan *mv_chan)
{
struct dma_chan *chan, *_chan;
struct device *dev = mv_chan->dmadev.dev;
dma_async_device_unregister(&mv_chan->dmadev);
dma_free_coherent(dev, MV_XOR_POOL_SIZE,
mv_chan->dma_desc_pool_virt, mv_chan->dma_desc_pool);
list_for_each_entry_safe(chan, _chan, &mv_chan->dmadev.channels,
device_node) {
list_del(&chan->device_node);
}
free_irq(mv_chan->irq, mv_chan);
return 0;
}
static struct mv_xor_chan *
mv_xor_channel_add(struct mv_xor_device *xordev,
struct platform_device *pdev,
int idx, dma_cap_mask_t cap_mask, int irq)
{
int ret = 0;
struct mv_xor_chan *mv_chan;
struct dma_device *dma_dev;
mv_chan = devm_kzalloc(&pdev->dev, sizeof(*mv_chan), GFP_KERNEL);
if (!mv_chan)
return ERR_PTR(-ENOMEM);
mv_chan->idx = idx;
mv_chan->irq = irq;
dma_dev = &mv_chan->dmadev;
mv_chan->dma_desc_pool_virt =
dma_alloc_writecombine(&pdev->dev, MV_XOR_POOL_SIZE,
&mv_chan->dma_desc_pool, GFP_KERNEL);
if (!mv_chan->dma_desc_pool_virt)
return ERR_PTR(-ENOMEM);
dma_dev->cap_mask = cap_mask;
INIT_LIST_HEAD(&dma_dev->channels);
dma_dev->device_alloc_chan_resources = mv_xor_alloc_chan_resources;
dma_dev->device_free_chan_resources = mv_xor_free_chan_resources;
dma_dev->device_tx_status = mv_xor_status;
dma_dev->device_issue_pending = mv_xor_issue_pending;
dma_dev->device_control = mv_xor_control;
dma_dev->dev = &pdev->dev;
if (dma_has_cap(DMA_MEMCPY, dma_dev->cap_mask))
dma_dev->device_prep_dma_memcpy = mv_xor_prep_dma_memcpy;
if (dma_has_cap(DMA_XOR, dma_dev->cap_mask)) {
dma_dev->max_xor = 8;
dma_dev->device_prep_dma_xor = mv_xor_prep_dma_xor;
}
mv_chan->mmr_base = xordev->xor_base;
mv_chan->mmr_high_base = xordev->xor_high_base;
tasklet_init(&mv_chan->irq_tasklet, mv_xor_tasklet, (unsigned long)
mv_chan);
mv_xor_device_clear_err_status(mv_chan);
ret = request_irq(mv_chan->irq, mv_xor_interrupt_handler,
0, dev_name(&pdev->dev), mv_chan);
if (ret)
goto err_free_dma;
mv_chan_unmask_interrupts(mv_chan);
mv_set_mode(mv_chan, DMA_MEMCPY);
spin_lock_init(&mv_chan->lock);
INIT_LIST_HEAD(&mv_chan->chain);
INIT_LIST_HEAD(&mv_chan->completed_slots);
INIT_LIST_HEAD(&mv_chan->all_slots);
mv_chan->dmachan.device = dma_dev;
dma_cookie_init(&mv_chan->dmachan);
list_add_tail(&mv_chan->dmachan.device_node, &dma_dev->channels);
if (dma_has_cap(DMA_MEMCPY, dma_dev->cap_mask)) {
ret = mv_xor_memcpy_self_test(mv_chan);
dev_dbg(&pdev->dev, "memcpy self test returned %d\n", ret);
if (ret)
goto err_free_irq;
}
if (dma_has_cap(DMA_XOR, dma_dev->cap_mask)) {
ret = mv_xor_xor_self_test(mv_chan);
dev_dbg(&pdev->dev, "xor self test returned %d\n", ret);
if (ret)
goto err_free_irq;
}
dev_info(&pdev->dev, "Marvell XOR: ( %s%s%s)\n",
dma_has_cap(DMA_XOR, dma_dev->cap_mask) ? "xor " : "",
dma_has_cap(DMA_MEMCPY, dma_dev->cap_mask) ? "cpy " : "",
dma_has_cap(DMA_INTERRUPT, dma_dev->cap_mask) ? "intr " : "");
dma_async_device_register(dma_dev);
return mv_chan;
err_free_irq:
free_irq(mv_chan->irq, mv_chan);
err_free_dma:
dma_free_coherent(&pdev->dev, MV_XOR_POOL_SIZE,
mv_chan->dma_desc_pool_virt, mv_chan->dma_desc_pool);
return ERR_PTR(ret);
}
static void
mv_xor_conf_mbus_windows(struct mv_xor_device *xordev,
const struct mbus_dram_target_info *dram)
{
void __iomem *base = xordev->xor_high_base;
u32 win_enable = 0;
int i;
for (i = 0; i < 8; i++) {
writel(0, base + WINDOW_BASE(i));
writel(0, base + WINDOW_SIZE(i));
if (i < 4)
writel(0, base + WINDOW_REMAP_HIGH(i));
}
for (i = 0; i < dram->num_cs; i++) {
const struct mbus_dram_window *cs = dram->cs + i;
writel((cs->base & 0xffff0000) |
(cs->mbus_attr << 8) |
dram->mbus_dram_target_id, base + WINDOW_BASE(i));
writel((cs->size - 1) & 0xffff0000, base + WINDOW_SIZE(i));
win_enable |= (1 << i);
win_enable |= 3 << (16 + (2 * i));
}
writel(win_enable, base + WINDOW_BAR_ENABLE(0));
writel(win_enable, base + WINDOW_BAR_ENABLE(1));
writel(0, base + WINDOW_OVERRIDE_CTRL(0));
writel(0, base + WINDOW_OVERRIDE_CTRL(1));
}
static int mv_xor_probe(struct platform_device *pdev)
{
const struct mbus_dram_target_info *dram;
struct mv_xor_device *xordev;
struct mv_xor_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct resource *res;
int i, ret;
dev_notice(&pdev->dev, "Marvell shared XOR driver\n");
xordev = devm_kzalloc(&pdev->dev, sizeof(*xordev), GFP_KERNEL);
if (!xordev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
xordev->xor_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!xordev->xor_base)
return -EBUSY;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res)
return -ENODEV;
xordev->xor_high_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!xordev->xor_high_base)
return -EBUSY;
platform_set_drvdata(pdev, xordev);
dram = mv_mbus_dram_info();
if (dram)
mv_xor_conf_mbus_windows(xordev, dram);
xordev->clk = clk_get(&pdev->dev, NULL);
if (!IS_ERR(xordev->clk))
clk_prepare_enable(xordev->clk);
if (pdev->dev.of_node) {
struct device_node *np;
int i = 0;
for_each_child_of_node(pdev->dev.of_node, np) {
struct mv_xor_chan *chan;
dma_cap_mask_t cap_mask;
int irq;
dma_cap_zero(cap_mask);
if (of_property_read_bool(np, "dmacap,memcpy"))
dma_cap_set(DMA_MEMCPY, cap_mask);
if (of_property_read_bool(np, "dmacap,xor"))
dma_cap_set(DMA_XOR, cap_mask);
if (of_property_read_bool(np, "dmacap,interrupt"))
dma_cap_set(DMA_INTERRUPT, cap_mask);
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
ret = -ENODEV;
goto err_channel_add;
}
chan = mv_xor_channel_add(xordev, pdev, i,
cap_mask, irq);
if (IS_ERR(chan)) {
ret = PTR_ERR(chan);
irq_dispose_mapping(irq);
goto err_channel_add;
}
xordev->channels[i] = chan;
i++;
}
} else if (pdata && pdata->channels) {
for (i = 0; i < MV_XOR_MAX_CHANNELS; i++) {
struct mv_xor_channel_data *cd;
struct mv_xor_chan *chan;
int irq;
cd = &pdata->channels[i];
if (!cd) {
ret = -ENODEV;
goto err_channel_add;
}
irq = platform_get_irq(pdev, i);
if (irq < 0) {
ret = irq;
goto err_channel_add;
}
chan = mv_xor_channel_add(xordev, pdev, i,
cd->cap_mask, irq);
if (IS_ERR(chan)) {
ret = PTR_ERR(chan);
goto err_channel_add;
}
xordev->channels[i] = chan;
}
}
return 0;
err_channel_add:
for (i = 0; i < MV_XOR_MAX_CHANNELS; i++)
if (xordev->channels[i]) {
mv_xor_channel_remove(xordev->channels[i]);
if (pdev->dev.of_node)
irq_dispose_mapping(xordev->channels[i]->irq);
}
if (!IS_ERR(xordev->clk)) {
clk_disable_unprepare(xordev->clk);
clk_put(xordev->clk);
}
return ret;
}
static int mv_xor_remove(struct platform_device *pdev)
{
struct mv_xor_device *xordev = platform_get_drvdata(pdev);
int i;
for (i = 0; i < MV_XOR_MAX_CHANNELS; i++) {
if (xordev->channels[i])
mv_xor_channel_remove(xordev->channels[i]);
}
if (!IS_ERR(xordev->clk)) {
clk_disable_unprepare(xordev->clk);
clk_put(xordev->clk);
}
return 0;
}
static int __init mv_xor_init(void)
{
return platform_driver_register(&mv_xor_driver);
}
