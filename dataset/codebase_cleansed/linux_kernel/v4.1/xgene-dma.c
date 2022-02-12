static bool is_pq_enabled(struct xgene_dma *pdma)
{
u32 val;
val = ioread32(pdma->csr_efuse + XGENE_SOC_JTAG1_SHADOW);
return !(val & XGENE_DMA_PQ_DISABLE_MASK);
}
static void xgene_dma_cpu_to_le64(u64 *desc, int count)
{
int i;
for (i = 0; i < count; i++)
desc[i] = cpu_to_le64(desc[i]);
}
static u16 xgene_dma_encode_len(u32 len)
{
return (len < XGENE_DMA_MAX_BYTE_CNT) ?
len : XGENE_DMA_16K_BUFFER_LEN_CODE;
}
static u8 xgene_dma_encode_xor_flyby(u32 src_cnt)
{
static u8 flyby_type[] = {
FLYBY_2SRC_XOR,
FLYBY_2SRC_XOR,
FLYBY_2SRC_XOR,
FLYBY_3SRC_XOR,
FLYBY_4SRC_XOR,
FLYBY_5SRC_XOR
};
return flyby_type[src_cnt];
}
static u32 xgene_dma_ring_desc_cnt(struct xgene_dma_ring *ring)
{
u32 __iomem *cmd_base = ring->cmd_base;
u32 ring_state = ioread32(&cmd_base[1]);
return XGENE_DMA_RING_DESC_CNT(ring_state);
}
static void xgene_dma_set_src_buffer(void *ext8, size_t *len,
dma_addr_t *paddr)
{
size_t nbytes = (*len < XGENE_DMA_MAX_BYTE_CNT) ?
*len : XGENE_DMA_MAX_BYTE_CNT;
XGENE_DMA_DESC_BUFADDR_SET(ext8, *paddr);
XGENE_DMA_DESC_BUFLEN_SET(ext8, xgene_dma_encode_len(nbytes));
*len -= nbytes;
*paddr += nbytes;
}
static void xgene_dma_invalidate_buffer(void *ext8)
{
XGENE_DMA_DESC_BUFLEN_SET(ext8, XGENE_DMA_INVALID_LEN_CODE);
}
static void *xgene_dma_lookup_ext8(u64 *desc, int idx)
{
return (idx % 2) ? (desc + idx - 1) : (desc + idx + 1);
}
static void xgene_dma_init_desc(void *desc, u16 dst_ring_num)
{
XGENE_DMA_DESC_C_SET(desc);
XGENE_DMA_DESC_IN_SET(desc);
XGENE_DMA_DESC_H0ENQ_NUM_SET(desc, dst_ring_num);
XGENE_DMA_DESC_RTYPE_SET(desc, XGENE_DMA_RING_OWNER_DMA);
}
static void xgene_dma_prep_cpy_desc(struct xgene_dma_chan *chan,
struct xgene_dma_desc_sw *desc_sw,
dma_addr_t dst, dma_addr_t src,
size_t len)
{
void *desc1, *desc2;
int i;
desc1 = &desc_sw->desc1;
xgene_dma_init_desc(desc1, chan->tx_ring.dst_ring_num);
XGENE_DMA_DESC_DR_SET(desc1);
XGENE_DMA_DESC_DST_ADDR_SET(desc1, dst);
xgene_dma_set_src_buffer(desc1 + 8, &len, &src);
if (len <= 0) {
desc2 = NULL;
goto skip_additional_src;
}
desc2 = &desc_sw->desc2;
XGENE_DMA_DESC_NV_SET(desc1);
for (i = 0; i < 4 && len; i++)
xgene_dma_set_src_buffer(xgene_dma_lookup_ext8(desc2, i),
&len, &src);
for (; i < 4; i++)
xgene_dma_invalidate_buffer(xgene_dma_lookup_ext8(desc2, i));
desc_sw->flags |= XGENE_DMA_FLAG_64B_DESC;
skip_additional_src:
xgene_dma_cpu_to_le64(desc1, 4);
if (desc2)
xgene_dma_cpu_to_le64(desc2, 4);
}
static void xgene_dma_prep_xor_desc(struct xgene_dma_chan *chan,
struct xgene_dma_desc_sw *desc_sw,
dma_addr_t *dst, dma_addr_t *src,
u32 src_cnt, size_t *nbytes,
const u8 *scf)
{
void *desc1, *desc2;
size_t len = *nbytes;
int i;
desc1 = &desc_sw->desc1;
desc2 = &desc_sw->desc2;
xgene_dma_init_desc(desc1, chan->tx_ring.dst_ring_num);
XGENE_DMA_DESC_DR_SET(desc1);
XGENE_DMA_DESC_DST_ADDR_SET(desc1, *dst);
XGENE_DMA_DESC_NV_SET(desc1);
XGENE_DMA_DESC_FLYBY_SET(desc1, xgene_dma_encode_xor_flyby(src_cnt));
for (i = 0; i < src_cnt; i++) {
len = *nbytes;
xgene_dma_set_src_buffer((i == 0) ? (desc1 + 8) :
xgene_dma_lookup_ext8(desc2, i - 1),
&len, &src[i]);
XGENE_DMA_DESC_MULTI_SET(desc1, scf[i], i);
}
xgene_dma_cpu_to_le64(desc1, 4);
xgene_dma_cpu_to_le64(desc2, 4);
*nbytes = len;
*dst += XGENE_DMA_MAX_BYTE_CNT;
desc_sw->flags |= XGENE_DMA_FLAG_64B_DESC;
}
static dma_cookie_t xgene_dma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct xgene_dma_desc_sw *desc;
struct xgene_dma_chan *chan;
dma_cookie_t cookie;
if (unlikely(!tx))
return -EINVAL;
chan = to_dma_chan(tx->chan);
desc = to_dma_desc_sw(tx);
spin_lock_bh(&chan->lock);
cookie = dma_cookie_assign(tx);
list_splice_tail_init(&desc->tx_list, &chan->ld_pending);
spin_unlock_bh(&chan->lock);
return cookie;
}
static void xgene_dma_clean_descriptor(struct xgene_dma_chan *chan,
struct xgene_dma_desc_sw *desc)
{
list_del(&desc->node);
chan_dbg(chan, "LD %p free\n", desc);
dma_pool_free(chan->desc_pool, desc, desc->tx.phys);
}
static struct xgene_dma_desc_sw *xgene_dma_alloc_descriptor(
struct xgene_dma_chan *chan)
{
struct xgene_dma_desc_sw *desc;
dma_addr_t phys;
desc = dma_pool_alloc(chan->desc_pool, GFP_NOWAIT, &phys);
if (!desc) {
chan_err(chan, "Failed to allocate LDs\n");
return NULL;
}
memset(desc, 0, sizeof(*desc));
INIT_LIST_HEAD(&desc->tx_list);
desc->tx.phys = phys;
desc->tx.tx_submit = xgene_dma_tx_submit;
dma_async_tx_descriptor_init(&desc->tx, &chan->dma_chan);
chan_dbg(chan, "LD %p allocated\n", desc);
return desc;
}
static void xgene_dma_clean_completed_descriptor(struct xgene_dma_chan *chan)
{
struct xgene_dma_desc_sw *desc, *_desc;
list_for_each_entry_safe(desc, _desc, &chan->ld_completed, node) {
if (async_tx_test_ack(&desc->tx))
xgene_dma_clean_descriptor(chan, desc);
}
}
static void xgene_dma_run_tx_complete_actions(struct xgene_dma_chan *chan,
struct xgene_dma_desc_sw *desc)
{
struct dma_async_tx_descriptor *tx = &desc->tx;
if (tx->cookie == 0)
return;
dma_cookie_complete(tx);
if (tx->callback)
tx->callback(tx->callback_param);
dma_descriptor_unmap(tx);
dma_run_dependencies(tx);
}
static void xgene_dma_clean_running_descriptor(struct xgene_dma_chan *chan,
struct xgene_dma_desc_sw *desc)
{
list_del(&desc->node);
if (!async_tx_test_ack(&desc->tx)) {
list_add_tail(&desc->node, &chan->ld_completed);
return;
}
chan_dbg(chan, "LD %p free\n", desc);
dma_pool_free(chan->desc_pool, desc, desc->tx.phys);
}
static int xgene_chan_xfer_request(struct xgene_dma_ring *ring,
struct xgene_dma_desc_sw *desc_sw)
{
struct xgene_dma_desc_hw *desc_hw;
if (xgene_dma_ring_desc_cnt(ring) > (ring->slots - 2))
return -EBUSY;
desc_hw = &ring->desc_hw[ring->head];
if (++ring->head == ring->slots)
ring->head = 0;
memcpy(desc_hw, &desc_sw->desc1, sizeof(*desc_hw));
if (desc_sw->flags & XGENE_DMA_FLAG_64B_DESC) {
desc_hw = &ring->desc_hw[ring->head];
if (++ring->head == ring->slots)
ring->head = 0;
memcpy(desc_hw, &desc_sw->desc2, sizeof(*desc_hw));
}
iowrite32((desc_sw->flags & XGENE_DMA_FLAG_64B_DESC) ?
2 : 1, ring->cmd);
return 0;
}
static void xgene_chan_xfer_ld_pending(struct xgene_dma_chan *chan)
{
struct xgene_dma_desc_sw *desc_sw, *_desc_sw;
int ret;
if (list_empty(&chan->ld_pending)) {
chan_dbg(chan, "No pending LDs\n");
return;
}
list_for_each_entry_safe(desc_sw, _desc_sw, &chan->ld_pending, node) {
if (chan->pending >= chan->max_outstanding)
return;
ret = xgene_chan_xfer_request(&chan->tx_ring, desc_sw);
if (ret)
return;
list_move_tail(&desc_sw->node, &chan->ld_running);
chan->pending++;
}
}
static void xgene_dma_cleanup_descriptors(struct xgene_dma_chan *chan)
{
struct xgene_dma_ring *ring = &chan->rx_ring;
struct xgene_dma_desc_sw *desc_sw, *_desc_sw;
struct xgene_dma_desc_hw *desc_hw;
u8 status;
xgene_dma_clean_completed_descriptor(chan);
list_for_each_entry_safe(desc_sw, _desc_sw, &chan->ld_running, node) {
desc_hw = &ring->desc_hw[ring->head];
if (unlikely(XGENE_DMA_DESC_IS_EMPTY(desc_hw)))
break;
if (++ring->head == ring->slots)
ring->head = 0;
status = XGENE_DMA_DESC_STATUS(
XGENE_DMA_DESC_ELERR_RD(le64_to_cpu(
desc_hw->m0)),
XGENE_DMA_DESC_LERR_RD(le64_to_cpu(
desc_hw->m0)));
if (status) {
chan_err(chan, "%s\n", xgene_dma_desc_err[status]);
XGENE_DMA_DESC_DUMP(&desc_sw->desc1,
"X-Gene DMA TX DESC1: ");
if (desc_sw->flags & XGENE_DMA_FLAG_64B_DESC)
XGENE_DMA_DESC_DUMP(&desc_sw->desc2,
"X-Gene DMA TX DESC2: ");
XGENE_DMA_DESC_DUMP(desc_hw,
"X-Gene DMA RX ERR DESC: ");
}
iowrite32(-1, ring->cmd);
XGENE_DMA_DESC_SET_EMPTY(desc_hw);
xgene_dma_run_tx_complete_actions(chan, desc_sw);
xgene_dma_clean_running_descriptor(chan, desc_sw);
chan->pending--;
}
xgene_chan_xfer_ld_pending(chan);
}
static int xgene_dma_alloc_chan_resources(struct dma_chan *dchan)
{
struct xgene_dma_chan *chan = to_dma_chan(dchan);
if (chan->desc_pool)
return 1;
chan->desc_pool = dma_pool_create(chan->name, chan->dev,
sizeof(struct xgene_dma_desc_sw),
0, 0);
if (!chan->desc_pool) {
chan_err(chan, "Failed to allocate descriptor pool\n");
return -ENOMEM;
}
chan_dbg(chan, "Allocate descripto pool\n");
return 1;
}
static void xgene_dma_free_desc_list(struct xgene_dma_chan *chan,
struct list_head *list)
{
struct xgene_dma_desc_sw *desc, *_desc;
list_for_each_entry_safe(desc, _desc, list, node)
xgene_dma_clean_descriptor(chan, desc);
}
static void xgene_dma_free_tx_desc_list(struct xgene_dma_chan *chan,
struct list_head *list)
{
struct xgene_dma_desc_sw *desc, *_desc;
list_for_each_entry_safe(desc, _desc, list, node)
xgene_dma_clean_descriptor(chan, desc);
}
static void xgene_dma_free_chan_resources(struct dma_chan *dchan)
{
struct xgene_dma_chan *chan = to_dma_chan(dchan);
chan_dbg(chan, "Free all resources\n");
if (!chan->desc_pool)
return;
spin_lock_bh(&chan->lock);
xgene_dma_cleanup_descriptors(chan);
xgene_dma_free_desc_list(chan, &chan->ld_pending);
xgene_dma_free_desc_list(chan, &chan->ld_running);
xgene_dma_free_desc_list(chan, &chan->ld_completed);
spin_unlock_bh(&chan->lock);
dma_pool_destroy(chan->desc_pool);
chan->desc_pool = NULL;
}
static struct dma_async_tx_descriptor *xgene_dma_prep_memcpy(
struct dma_chan *dchan, dma_addr_t dst, dma_addr_t src,
size_t len, unsigned long flags)
{
struct xgene_dma_desc_sw *first = NULL, *new;
struct xgene_dma_chan *chan;
size_t copy;
if (unlikely(!dchan || !len))
return NULL;
chan = to_dma_chan(dchan);
do {
new = xgene_dma_alloc_descriptor(chan);
if (!new)
goto fail;
copy = min_t(size_t, len, XGENE_DMA_MAX_64B_DESC_BYTE_CNT);
xgene_dma_prep_cpy_desc(chan, new, dst, src, copy);
if (!first)
first = new;
new->tx.cookie = 0;
async_tx_ack(&new->tx);
len -= copy;
dst += copy;
src += copy;
list_add_tail(&new->node, &first->tx_list);
} while (len);
new->tx.flags = flags;
new->tx.cookie = -EBUSY;
list_splice(&first->tx_list, &new->tx_list);
return &new->tx;
fail:
if (!first)
return NULL;
xgene_dma_free_tx_desc_list(chan, &first->tx_list);
return NULL;
}
static struct dma_async_tx_descriptor *xgene_dma_prep_sg(
struct dma_chan *dchan, struct scatterlist *dst_sg,
u32 dst_nents, struct scatterlist *src_sg,
u32 src_nents, unsigned long flags)
{
struct xgene_dma_desc_sw *first = NULL, *new = NULL;
struct xgene_dma_chan *chan;
size_t dst_avail, src_avail;
dma_addr_t dst, src;
size_t len;
if (unlikely(!dchan))
return NULL;
if (unlikely(!dst_nents || !src_nents))
return NULL;
if (unlikely(!dst_sg || !src_sg))
return NULL;
chan = to_dma_chan(dchan);
dst_avail = sg_dma_len(dst_sg);
src_avail = sg_dma_len(src_sg);
dst_nents--;
src_nents--;
while (true) {
len = min_t(size_t, src_avail, dst_avail);
len = min_t(size_t, len, XGENE_DMA_MAX_64B_DESC_BYTE_CNT);
if (len == 0)
goto fetch;
dst = sg_dma_address(dst_sg) + sg_dma_len(dst_sg) - dst_avail;
src = sg_dma_address(src_sg) + sg_dma_len(src_sg) - src_avail;
new = xgene_dma_alloc_descriptor(chan);
if (!new)
goto fail;
xgene_dma_prep_cpy_desc(chan, new, dst, src, len);
if (!first)
first = new;
new->tx.cookie = 0;
async_tx_ack(&new->tx);
dst_avail -= len;
src_avail -= len;
list_add_tail(&new->node, &first->tx_list);
fetch:
if (dst_avail == 0) {
if (dst_nents == 0)
break;
dst_sg = sg_next(dst_sg);
if (!dst_sg)
break;
dst_nents--;
dst_avail = sg_dma_len(dst_sg);
}
if (src_avail == 0) {
if (src_nents == 0)
break;
src_sg = sg_next(src_sg);
if (!src_sg)
break;
src_nents--;
src_avail = sg_dma_len(src_sg);
}
}
if (!new)
return NULL;
new->tx.flags = flags;
new->tx.cookie = -EBUSY;
list_splice(&first->tx_list, &new->tx_list);
return &new->tx;
fail:
if (!first)
return NULL;
xgene_dma_free_tx_desc_list(chan, &first->tx_list);
return NULL;
}
static struct dma_async_tx_descriptor *xgene_dma_prep_xor(
struct dma_chan *dchan, dma_addr_t dst, dma_addr_t *src,
u32 src_cnt, size_t len, unsigned long flags)
{
struct xgene_dma_desc_sw *first = NULL, *new;
struct xgene_dma_chan *chan;
static u8 multi[XGENE_DMA_MAX_XOR_SRC] = {
0x01, 0x01, 0x01, 0x01, 0x01};
if (unlikely(!dchan || !len))
return NULL;
chan = to_dma_chan(dchan);
do {
new = xgene_dma_alloc_descriptor(chan);
if (!new)
goto fail;
xgene_dma_prep_xor_desc(chan, new, &dst, src,
src_cnt, &len, multi);
if (!first)
first = new;
new->tx.cookie = 0;
async_tx_ack(&new->tx);
list_add_tail(&new->node, &first->tx_list);
} while (len);
new->tx.flags = flags;
new->tx.cookie = -EBUSY;
list_splice(&first->tx_list, &new->tx_list);
return &new->tx;
fail:
if (!first)
return NULL;
xgene_dma_free_tx_desc_list(chan, &first->tx_list);
return NULL;
}
static struct dma_async_tx_descriptor *xgene_dma_prep_pq(
struct dma_chan *dchan, dma_addr_t *dst, dma_addr_t *src,
u32 src_cnt, const u8 *scf, size_t len, unsigned long flags)
{
struct xgene_dma_desc_sw *first = NULL, *new;
struct xgene_dma_chan *chan;
size_t _len = len;
dma_addr_t _src[XGENE_DMA_MAX_XOR_SRC];
static u8 multi[XGENE_DMA_MAX_XOR_SRC] = {0x01, 0x01, 0x01, 0x01, 0x01};
if (unlikely(!dchan || !len))
return NULL;
chan = to_dma_chan(dchan);
memcpy(_src, src, sizeof(*src) * src_cnt);
if (flags & DMA_PREP_PQ_DISABLE_P)
len = 0;
if (flags & DMA_PREP_PQ_DISABLE_Q)
_len = 0;
do {
new = xgene_dma_alloc_descriptor(chan);
if (!new)
goto fail;
if (!first)
first = new;
new->tx.cookie = 0;
async_tx_ack(&new->tx);
list_add_tail(&new->node, &first->tx_list);
if (len) {
xgene_dma_prep_xor_desc(chan, new, &dst[0], src,
src_cnt, &len, multi);
continue;
}
if (_len) {
xgene_dma_prep_xor_desc(chan, new, &dst[1], _src,
src_cnt, &_len, scf);
}
} while (len || _len);
new->tx.flags = flags;
new->tx.cookie = -EBUSY;
list_splice(&first->tx_list, &new->tx_list);
return &new->tx;
fail:
if (!first)
return NULL;
xgene_dma_free_tx_desc_list(chan, &first->tx_list);
return NULL;
}
static void xgene_dma_issue_pending(struct dma_chan *dchan)
{
struct xgene_dma_chan *chan = to_dma_chan(dchan);
spin_lock_bh(&chan->lock);
xgene_chan_xfer_ld_pending(chan);
spin_unlock_bh(&chan->lock);
}
static enum dma_status xgene_dma_tx_status(struct dma_chan *dchan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
return dma_cookie_status(dchan, cookie, txstate);
}
static void xgene_dma_tasklet_cb(unsigned long data)
{
struct xgene_dma_chan *chan = (struct xgene_dma_chan *)data;
spin_lock_bh(&chan->lock);
xgene_dma_cleanup_descriptors(chan);
enable_irq(chan->rx_irq);
spin_unlock_bh(&chan->lock);
}
static irqreturn_t xgene_dma_chan_ring_isr(int irq, void *id)
{
struct xgene_dma_chan *chan = (struct xgene_dma_chan *)id;
BUG_ON(!chan);
disable_irq_nosync(chan->rx_irq);
tasklet_schedule(&chan->tasklet);
return IRQ_HANDLED;
}
static irqreturn_t xgene_dma_err_isr(int irq, void *id)
{
struct xgene_dma *pdma = (struct xgene_dma *)id;
unsigned long int_mask;
u32 val, i;
val = ioread32(pdma->csr_dma + XGENE_DMA_INT);
iowrite32(val, pdma->csr_dma + XGENE_DMA_INT);
int_mask = val >> XGENE_DMA_INT_MASK_SHIFT;
for_each_set_bit(i, &int_mask, ARRAY_SIZE(xgene_dma_err))
dev_err(pdma->dev,
"Interrupt status 0x%08X %s\n", val, xgene_dma_err[i]);
return IRQ_HANDLED;
}
static void xgene_dma_wr_ring_state(struct xgene_dma_ring *ring)
{
int i;
iowrite32(ring->num, ring->pdma->csr_ring + XGENE_DMA_RING_STATE);
for (i = 0; i < XGENE_DMA_RING_NUM_CONFIG; i++)
iowrite32(ring->state[i], ring->pdma->csr_ring +
XGENE_DMA_RING_STATE_WR_BASE + (i * 4));
}
static void xgene_dma_clr_ring_state(struct xgene_dma_ring *ring)
{
memset(ring->state, 0, sizeof(u32) * XGENE_DMA_RING_NUM_CONFIG);
xgene_dma_wr_ring_state(ring);
}
static void xgene_dma_setup_ring(struct xgene_dma_ring *ring)
{
void *ring_cfg = ring->state;
u64 addr = ring->desc_paddr;
void *desc;
u32 i, val;
ring->slots = ring->size / XGENE_DMA_RING_WQ_DESC_SIZE;
xgene_dma_clr_ring_state(ring);
XGENE_DMA_RING_TYPE_SET(ring_cfg, XGENE_DMA_RING_TYPE_REGULAR);
if (ring->owner == XGENE_DMA_RING_OWNER_DMA) {
XGENE_DMA_RING_RECOMBBUF_SET(ring_cfg);
XGENE_DMA_RING_RECOMTIMEOUTL_SET(ring_cfg);
XGENE_DMA_RING_RECOMTIMEOUTH_SET(ring_cfg);
}
XGENE_DMA_RING_SELTHRSH_SET(ring_cfg);
XGENE_DMA_RING_ACCEPTLERR_SET(ring_cfg);
XGENE_DMA_RING_COHERENT_SET(ring_cfg);
XGENE_DMA_RING_ADDRL_SET(ring_cfg, addr);
XGENE_DMA_RING_ADDRH_SET(ring_cfg, addr);
XGENE_DMA_RING_SIZE_SET(ring_cfg, ring->cfgsize);
xgene_dma_wr_ring_state(ring);
iowrite32(XGENE_DMA_RING_ID_SETUP(ring->id),
ring->pdma->csr_ring + XGENE_DMA_RING_ID);
iowrite32(XGENE_DMA_RING_ID_BUF_SETUP(ring->num),
ring->pdma->csr_ring + XGENE_DMA_RING_ID_BUF);
if (ring->owner != XGENE_DMA_RING_OWNER_CPU)
return;
for (i = 0; i < ring->slots; i++) {
desc = &ring->desc_hw[i];
XGENE_DMA_DESC_SET_EMPTY(desc);
}
val = ioread32(ring->pdma->csr_ring + XGENE_DMA_RING_NE_INT_MODE);
XGENE_DMA_RING_NE_INT_MODE_SET(val, ring->buf_num);
iowrite32(val, ring->pdma->csr_ring + XGENE_DMA_RING_NE_INT_MODE);
}
static void xgene_dma_clear_ring(struct xgene_dma_ring *ring)
{
u32 ring_id, val;
if (ring->owner == XGENE_DMA_RING_OWNER_CPU) {
val = ioread32(ring->pdma->csr_ring +
XGENE_DMA_RING_NE_INT_MODE);
XGENE_DMA_RING_NE_INT_MODE_RESET(val, ring->buf_num);
iowrite32(val, ring->pdma->csr_ring +
XGENE_DMA_RING_NE_INT_MODE);
}
ring_id = XGENE_DMA_RING_ID_SETUP(ring->id);
iowrite32(ring_id, ring->pdma->csr_ring + XGENE_DMA_RING_ID);
iowrite32(0, ring->pdma->csr_ring + XGENE_DMA_RING_ID_BUF);
xgene_dma_clr_ring_state(ring);
}
static void xgene_dma_set_ring_cmd(struct xgene_dma_ring *ring)
{
ring->cmd_base = ring->pdma->csr_ring_cmd +
XGENE_DMA_RING_CMD_BASE_OFFSET((ring->num -
XGENE_DMA_RING_NUM));
ring->cmd = ring->cmd_base + XGENE_DMA_RING_CMD_OFFSET;
}
static int xgene_dma_get_ring_size(struct xgene_dma_chan *chan,
enum xgene_dma_ring_cfgsize cfgsize)
{
int size;
switch (cfgsize) {
case XGENE_DMA_RING_CFG_SIZE_512B:
size = 0x200;
break;
case XGENE_DMA_RING_CFG_SIZE_2KB:
size = 0x800;
break;
case XGENE_DMA_RING_CFG_SIZE_16KB:
size = 0x4000;
break;
case XGENE_DMA_RING_CFG_SIZE_64KB:
size = 0x10000;
break;
case XGENE_DMA_RING_CFG_SIZE_512KB:
size = 0x80000;
break;
default:
chan_err(chan, "Unsupported cfg ring size %d\n", cfgsize);
return -EINVAL;
}
return size;
}
static void xgene_dma_delete_ring_one(struct xgene_dma_ring *ring)
{
xgene_dma_clear_ring(ring);
if (ring->desc_vaddr) {
dma_free_coherent(ring->pdma->dev, ring->size,
ring->desc_vaddr, ring->desc_paddr);
ring->desc_vaddr = NULL;
}
}
static void xgene_dma_delete_chan_rings(struct xgene_dma_chan *chan)
{
xgene_dma_delete_ring_one(&chan->rx_ring);
xgene_dma_delete_ring_one(&chan->tx_ring);
}
static int xgene_dma_create_ring_one(struct xgene_dma_chan *chan,
struct xgene_dma_ring *ring,
enum xgene_dma_ring_cfgsize cfgsize)
{
ring->pdma = chan->pdma;
ring->cfgsize = cfgsize;
ring->num = chan->pdma->ring_num++;
ring->id = XGENE_DMA_RING_ID_GET(ring->owner, ring->buf_num);
ring->size = xgene_dma_get_ring_size(chan, cfgsize);
if (ring->size <= 0)
return ring->size;
ring->desc_vaddr = dma_zalloc_coherent(chan->dev, ring->size,
&ring->desc_paddr, GFP_KERNEL);
if (!ring->desc_vaddr) {
chan_err(chan, "Failed to allocate ring desc\n");
return -ENOMEM;
}
xgene_dma_set_ring_cmd(ring);
xgene_dma_setup_ring(ring);
return 0;
}
static int xgene_dma_create_chan_rings(struct xgene_dma_chan *chan)
{
struct xgene_dma_ring *rx_ring = &chan->rx_ring;
struct xgene_dma_ring *tx_ring = &chan->tx_ring;
int ret;
rx_ring->owner = XGENE_DMA_RING_OWNER_CPU;
rx_ring->buf_num = XGENE_DMA_CPU_BUFNUM + chan->id;
ret = xgene_dma_create_ring_one(chan, rx_ring,
XGENE_DMA_RING_CFG_SIZE_64KB);
if (ret)
return ret;
chan_dbg(chan, "Rx ring id 0x%X num %d desc 0x%p\n",
rx_ring->id, rx_ring->num, rx_ring->desc_vaddr);
tx_ring->owner = XGENE_DMA_RING_OWNER_DMA;
tx_ring->buf_num = XGENE_DMA_BUFNUM + chan->id;
ret = xgene_dma_create_ring_one(chan, tx_ring,
XGENE_DMA_RING_CFG_SIZE_64KB);
if (ret) {
xgene_dma_delete_ring_one(rx_ring);
return ret;
}
tx_ring->dst_ring_num = XGENE_DMA_RING_DST_ID(rx_ring->num);
chan_dbg(chan,
"Tx ring id 0x%X num %d desc 0x%p\n",
tx_ring->id, tx_ring->num, tx_ring->desc_vaddr);
chan->max_outstanding = rx_ring->slots;
return ret;
}
static int xgene_dma_init_rings(struct xgene_dma *pdma)
{
int ret, i, j;
for (i = 0; i < XGENE_DMA_MAX_CHANNEL; i++) {
ret = xgene_dma_create_chan_rings(&pdma->chan[i]);
if (ret) {
for (j = 0; j < i; j++)
xgene_dma_delete_chan_rings(&pdma->chan[j]);
return ret;
}
}
return ret;
}
static void xgene_dma_enable(struct xgene_dma *pdma)
{
u32 val;
val = ioread32(pdma->csr_dma + XGENE_DMA_GCR);
XGENE_DMA_CH_SETUP(val);
XGENE_DMA_ENABLE(val);
iowrite32(val, pdma->csr_dma + XGENE_DMA_GCR);
}
static void xgene_dma_disable(struct xgene_dma *pdma)
{
u32 val;
val = ioread32(pdma->csr_dma + XGENE_DMA_GCR);
XGENE_DMA_DISABLE(val);
iowrite32(val, pdma->csr_dma + XGENE_DMA_GCR);
}
static void xgene_dma_mask_interrupts(struct xgene_dma *pdma)
{
iowrite32(XGENE_DMA_INT_ALL_MASK,
pdma->csr_dma + XGENE_DMA_RING_INT0_MASK);
iowrite32(XGENE_DMA_INT_ALL_MASK,
pdma->csr_dma + XGENE_DMA_RING_INT1_MASK);
iowrite32(XGENE_DMA_INT_ALL_MASK,
pdma->csr_dma + XGENE_DMA_RING_INT2_MASK);
iowrite32(XGENE_DMA_INT_ALL_MASK,
pdma->csr_dma + XGENE_DMA_RING_INT3_MASK);
iowrite32(XGENE_DMA_INT_ALL_MASK,
pdma->csr_dma + XGENE_DMA_RING_INT4_MASK);
iowrite32(XGENE_DMA_INT_ALL_MASK, pdma->csr_dma + XGENE_DMA_INT_MASK);
}
static void xgene_dma_unmask_interrupts(struct xgene_dma *pdma)
{
iowrite32(XGENE_DMA_INT_ALL_UNMASK,
pdma->csr_dma + XGENE_DMA_RING_INT0_MASK);
iowrite32(XGENE_DMA_INT_ALL_UNMASK,
pdma->csr_dma + XGENE_DMA_RING_INT1_MASK);
iowrite32(XGENE_DMA_INT_ALL_UNMASK,
pdma->csr_dma + XGENE_DMA_RING_INT2_MASK);
iowrite32(XGENE_DMA_INT_ALL_UNMASK,
pdma->csr_dma + XGENE_DMA_RING_INT3_MASK);
iowrite32(XGENE_DMA_INT_ALL_UNMASK,
pdma->csr_dma + XGENE_DMA_RING_INT4_MASK);
iowrite32(XGENE_DMA_INT_ALL_UNMASK,
pdma->csr_dma + XGENE_DMA_INT_MASK);
}
static void xgene_dma_init_hw(struct xgene_dma *pdma)
{
u32 val;
iowrite32(XGENE_DMA_ASSOC_RING_MNGR1,
pdma->csr_dma + XGENE_DMA_CFG_RING_WQ_ASSOC);
if (is_pq_enabled(pdma))
iowrite32(XGENE_DMA_RAID6_MULTI_CTRL(0x1D),
pdma->csr_dma + XGENE_DMA_RAID6_CONT);
else
dev_info(pdma->dev, "PQ is disabled in HW\n");
xgene_dma_enable(pdma);
xgene_dma_unmask_interrupts(pdma);
val = ioread32(pdma->csr_dma + XGENE_DMA_IPBRR);
dev_info(pdma->dev,
"X-Gene DMA v%d.%02d.%02d driver registered %d channels",
XGENE_DMA_REV_NO_RD(val), XGENE_DMA_BUS_ID_RD(val),
XGENE_DMA_DEV_ID_RD(val), XGENE_DMA_MAX_CHANNEL);
}
static int xgene_dma_init_ring_mngr(struct xgene_dma *pdma)
{
if (ioread32(pdma->csr_ring + XGENE_DMA_RING_CLKEN) &&
(!ioread32(pdma->csr_ring + XGENE_DMA_RING_SRST)))
return 0;
iowrite32(0x3, pdma->csr_ring + XGENE_DMA_RING_CLKEN);
iowrite32(0x0, pdma->csr_ring + XGENE_DMA_RING_SRST);
iowrite32(0x0, pdma->csr_ring + XGENE_DMA_RING_MEM_RAM_SHUTDOWN);
ioread32(pdma->csr_ring + XGENE_DMA_RING_MEM_RAM_SHUTDOWN);
usleep_range(1000, 1100);
if (ioread32(pdma->csr_ring + XGENE_DMA_RING_BLK_MEM_RDY)
!= XGENE_DMA_RING_BLK_MEM_RDY_VAL) {
dev_err(pdma->dev,
"Failed to release ring mngr memory from shutdown\n");
return -ENODEV;
}
iowrite32(XGENE_DMA_RING_THRESLD0_SET1_VAL,
pdma->csr_ring + XGENE_DMA_RING_THRESLD0_SET1);
iowrite32(XGENE_DMA_RING_THRESLD1_SET1_VAL,
pdma->csr_ring + XGENE_DMA_RING_THRESLD1_SET1);
iowrite32(XGENE_DMA_RING_HYSTERESIS_VAL,
pdma->csr_ring + XGENE_DMA_RING_HYSTERESIS);
iowrite32(XGENE_DMA_RING_ENABLE,
pdma->csr_ring + XGENE_DMA_RING_CONFIG);
return 0;
}
static int xgene_dma_init_mem(struct xgene_dma *pdma)
{
int ret;
ret = xgene_dma_init_ring_mngr(pdma);
if (ret)
return ret;
iowrite32(0x0, pdma->csr_dma + XGENE_DMA_MEM_RAM_SHUTDOWN);
ioread32(pdma->csr_dma + XGENE_DMA_MEM_RAM_SHUTDOWN);
usleep_range(1000, 1100);
if (ioread32(pdma->csr_dma + XGENE_DMA_BLK_MEM_RDY)
!= XGENE_DMA_BLK_MEM_RDY_VAL) {
dev_err(pdma->dev,
"Failed to release DMA memory from shutdown\n");
return -ENODEV;
}
return 0;
}
static int xgene_dma_request_irqs(struct xgene_dma *pdma)
{
struct xgene_dma_chan *chan;
int ret, i, j;
ret = devm_request_irq(pdma->dev, pdma->err_irq, xgene_dma_err_isr,
0, "dma_error", pdma);
if (ret) {
dev_err(pdma->dev,
"Failed to register error IRQ %d\n", pdma->err_irq);
return ret;
}
for (i = 0; i < XGENE_DMA_MAX_CHANNEL; i++) {
chan = &pdma->chan[i];
ret = devm_request_irq(chan->dev, chan->rx_irq,
xgene_dma_chan_ring_isr,
0, chan->name, chan);
if (ret) {
chan_err(chan, "Failed to register Rx IRQ %d\n",
chan->rx_irq);
devm_free_irq(pdma->dev, pdma->err_irq, pdma);
for (j = 0; j < i; j++) {
chan = &pdma->chan[i];
devm_free_irq(chan->dev, chan->rx_irq, chan);
}
return ret;
}
}
return 0;
}
static void xgene_dma_free_irqs(struct xgene_dma *pdma)
{
struct xgene_dma_chan *chan;
int i;
devm_free_irq(pdma->dev, pdma->err_irq, pdma);
for (i = 0; i < XGENE_DMA_MAX_CHANNEL; i++) {
chan = &pdma->chan[i];
devm_free_irq(chan->dev, chan->rx_irq, chan);
}
}
static void xgene_dma_set_caps(struct xgene_dma_chan *chan,
struct dma_device *dma_dev)
{
dma_cap_zero(dma_dev->cap_mask);
dma_cap_set(DMA_MEMCPY, dma_dev->cap_mask);
dma_cap_set(DMA_SG, dma_dev->cap_mask);
if ((chan->id == XGENE_DMA_PQ_CHANNEL) &&
is_pq_enabled(chan->pdma)) {
dma_cap_set(DMA_PQ, dma_dev->cap_mask);
dma_cap_set(DMA_XOR, dma_dev->cap_mask);
} else if ((chan->id == XGENE_DMA_XOR_CHANNEL) &&
!is_pq_enabled(chan->pdma)) {
dma_cap_set(DMA_XOR, dma_dev->cap_mask);
}
dma_dev->dev = chan->dev;
dma_dev->device_alloc_chan_resources = xgene_dma_alloc_chan_resources;
dma_dev->device_free_chan_resources = xgene_dma_free_chan_resources;
dma_dev->device_issue_pending = xgene_dma_issue_pending;
dma_dev->device_tx_status = xgene_dma_tx_status;
dma_dev->device_prep_dma_memcpy = xgene_dma_prep_memcpy;
dma_dev->device_prep_dma_sg = xgene_dma_prep_sg;
if (dma_has_cap(DMA_XOR, dma_dev->cap_mask)) {
dma_dev->device_prep_dma_xor = xgene_dma_prep_xor;
dma_dev->max_xor = XGENE_DMA_MAX_XOR_SRC;
dma_dev->xor_align = XGENE_DMA_XOR_ALIGNMENT;
}
if (dma_has_cap(DMA_PQ, dma_dev->cap_mask)) {
dma_dev->device_prep_dma_pq = xgene_dma_prep_pq;
dma_dev->max_pq = XGENE_DMA_MAX_XOR_SRC;
dma_dev->pq_align = XGENE_DMA_XOR_ALIGNMENT;
}
}
static int xgene_dma_async_register(struct xgene_dma *pdma, int id)
{
struct xgene_dma_chan *chan = &pdma->chan[id];
struct dma_device *dma_dev = &pdma->dma_dev[id];
int ret;
chan->dma_chan.device = dma_dev;
spin_lock_init(&chan->lock);
INIT_LIST_HEAD(&chan->ld_pending);
INIT_LIST_HEAD(&chan->ld_running);
INIT_LIST_HEAD(&chan->ld_completed);
tasklet_init(&chan->tasklet, xgene_dma_tasklet_cb,
(unsigned long)chan);
chan->pending = 0;
chan->desc_pool = NULL;
dma_cookie_init(&chan->dma_chan);
xgene_dma_set_caps(chan, dma_dev);
INIT_LIST_HEAD(&dma_dev->channels);
list_add_tail(&chan->dma_chan.device_node, &dma_dev->channels);
ret = dma_async_device_register(dma_dev);
if (ret) {
chan_err(chan, "Failed to register async device %d", ret);
tasklet_kill(&chan->tasklet);
return ret;
}
dev_info(pdma->dev,
"%s: CAPABILITY ( %s%s%s%s)\n", dma_chan_name(&chan->dma_chan),
dma_has_cap(DMA_MEMCPY, dma_dev->cap_mask) ? "MEMCPY " : "",
dma_has_cap(DMA_SG, dma_dev->cap_mask) ? "SGCPY " : "",
dma_has_cap(DMA_XOR, dma_dev->cap_mask) ? "XOR " : "",
dma_has_cap(DMA_PQ, dma_dev->cap_mask) ? "PQ " : "");
return 0;
}
static int xgene_dma_init_async(struct xgene_dma *pdma)
{
int ret, i, j;
for (i = 0; i < XGENE_DMA_MAX_CHANNEL ; i++) {
ret = xgene_dma_async_register(pdma, i);
if (ret) {
for (j = 0; j < i; j++) {
dma_async_device_unregister(&pdma->dma_dev[j]);
tasklet_kill(&pdma->chan[j].tasklet);
}
return ret;
}
}
return ret;
}
static void xgene_dma_async_unregister(struct xgene_dma *pdma)
{
int i;
for (i = 0; i < XGENE_DMA_MAX_CHANNEL; i++)
dma_async_device_unregister(&pdma->dma_dev[i]);
}
static void xgene_dma_init_channels(struct xgene_dma *pdma)
{
struct xgene_dma_chan *chan;
int i;
pdma->ring_num = XGENE_DMA_RING_NUM;
for (i = 0; i < XGENE_DMA_MAX_CHANNEL; i++) {
chan = &pdma->chan[i];
chan->dev = pdma->dev;
chan->pdma = pdma;
chan->id = i;
snprintf(chan->name, sizeof(chan->name), "dmachan%d", chan->id);
}
}
static int xgene_dma_get_resources(struct platform_device *pdev,
struct xgene_dma *pdma)
{
struct resource *res;
int irq, i;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get csr region\n");
return -ENXIO;
}
pdma->csr_dma = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!pdma->csr_dma) {
dev_err(&pdev->dev, "Failed to ioremap csr region");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
dev_err(&pdev->dev, "Failed to get ring csr region\n");
return -ENXIO;
}
pdma->csr_ring = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!pdma->csr_ring) {
dev_err(&pdev->dev, "Failed to ioremap ring csr region");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
if (!res) {
dev_err(&pdev->dev, "Failed to get ring cmd csr region\n");
return -ENXIO;
}
pdma->csr_ring_cmd = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!pdma->csr_ring_cmd) {
dev_err(&pdev->dev, "Failed to ioremap ring cmd csr region");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 3);
if (!res) {
dev_err(&pdev->dev, "Failed to get efuse csr region\n");
return -ENXIO;
}
pdma->csr_efuse = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!pdma->csr_efuse) {
dev_err(&pdev->dev, "Failed to ioremap efuse csr region");
return -ENOMEM;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev, "Failed to get Error IRQ\n");
return -ENXIO;
}
pdma->err_irq = irq;
for (i = 1; i <= XGENE_DMA_MAX_CHANNEL; i++) {
irq = platform_get_irq(pdev, i);
if (irq <= 0) {
dev_err(&pdev->dev, "Failed to get Rx IRQ\n");
return -ENXIO;
}
pdma->chan[i - 1].rx_irq = irq;
}
return 0;
}
static int xgene_dma_probe(struct platform_device *pdev)
{
struct xgene_dma *pdma;
int ret, i;
pdma = devm_kzalloc(&pdev->dev, sizeof(*pdma), GFP_KERNEL);
if (!pdma)
return -ENOMEM;
pdma->dev = &pdev->dev;
platform_set_drvdata(pdev, pdma);
ret = xgene_dma_get_resources(pdev, pdma);
if (ret)
return ret;
pdma->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(pdma->clk)) {
dev_err(&pdev->dev, "Failed to get clk\n");
return PTR_ERR(pdma->clk);
}
ret = clk_prepare_enable(pdma->clk);
if (ret) {
dev_err(&pdev->dev, "Failed to enable clk %d\n", ret);
return ret;
}
ret = xgene_dma_init_mem(pdma);
if (ret)
goto err_clk_enable;
ret = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(42));
if (ret) {
dev_err(&pdev->dev, "No usable DMA configuration\n");
goto err_dma_mask;
}
xgene_dma_init_channels(pdma);
ret = xgene_dma_init_rings(pdma);
if (ret)
goto err_clk_enable;
ret = xgene_dma_request_irqs(pdma);
if (ret)
goto err_request_irq;
xgene_dma_init_hw(pdma);
ret = xgene_dma_init_async(pdma);
if (ret)
goto err_async_init;
return 0;
err_async_init:
xgene_dma_free_irqs(pdma);
err_request_irq:
for (i = 0; i < XGENE_DMA_MAX_CHANNEL; i++)
xgene_dma_delete_chan_rings(&pdma->chan[i]);
err_dma_mask:
err_clk_enable:
clk_disable_unprepare(pdma->clk);
return ret;
}
static int xgene_dma_remove(struct platform_device *pdev)
{
struct xgene_dma *pdma = platform_get_drvdata(pdev);
struct xgene_dma_chan *chan;
int i;
xgene_dma_async_unregister(pdma);
xgene_dma_mask_interrupts(pdma);
xgene_dma_disable(pdma);
xgene_dma_free_irqs(pdma);
for (i = 0; i < XGENE_DMA_MAX_CHANNEL; i++) {
chan = &pdma->chan[i];
tasklet_kill(&chan->tasklet);
xgene_dma_delete_chan_rings(chan);
}
clk_disable_unprepare(pdma->clk);
return 0;
}
