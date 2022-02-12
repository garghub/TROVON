static inline void ath10k_ce_dest_ring_write_index_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
ath10k_pci_write32(ar, ce_ctrl_addr + DST_WR_INDEX_ADDRESS, n);
}
static inline u32 ath10k_ce_dest_ring_write_index_get(struct ath10k *ar,
u32 ce_ctrl_addr)
{
return ath10k_pci_read32(ar, ce_ctrl_addr + DST_WR_INDEX_ADDRESS);
}
static inline void ath10k_ce_src_ring_write_index_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
void __iomem *indicator_addr;
if (!test_bit(ATH10K_PCI_FEATURE_HW_1_0_WORKAROUND, ar_pci->features)) {
ath10k_pci_write32(ar, ce_ctrl_addr + SR_WR_INDEX_ADDRESS, n);
return;
}
indicator_addr = ar_pci->mem + ce_ctrl_addr + DST_WATERMARK_ADDRESS;
if (ce_ctrl_addr == ath10k_ce_base_address(CDC_WAR_DATA_CE)) {
iowrite32((CDC_WAR_MAGIC_STR | n), indicator_addr);
} else {
unsigned long irq_flags;
local_irq_save(irq_flags);
iowrite32(1, indicator_addr);
(void)ioread32(indicator_addr);
(void)ioread32(indicator_addr);
ath10k_pci_write32(ar, ce_ctrl_addr + SR_WR_INDEX_ADDRESS, n);
iowrite32(0, indicator_addr);
local_irq_restore(irq_flags);
}
}
static inline u32 ath10k_ce_src_ring_write_index_get(struct ath10k *ar,
u32 ce_ctrl_addr)
{
return ath10k_pci_read32(ar, ce_ctrl_addr + SR_WR_INDEX_ADDRESS);
}
static inline u32 ath10k_ce_src_ring_read_index_get(struct ath10k *ar,
u32 ce_ctrl_addr)
{
return ath10k_pci_read32(ar, ce_ctrl_addr + CURRENT_SRRI_ADDRESS);
}
static inline void ath10k_ce_src_ring_base_addr_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int addr)
{
ath10k_pci_write32(ar, ce_ctrl_addr + SR_BA_ADDRESS, addr);
}
static inline void ath10k_ce_src_ring_size_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
ath10k_pci_write32(ar, ce_ctrl_addr + SR_SIZE_ADDRESS, n);
}
static inline void ath10k_ce_src_ring_dmax_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
u32 ctrl1_addr = ath10k_pci_read32((ar),
(ce_ctrl_addr) + CE_CTRL1_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + CE_CTRL1_ADDRESS,
(ctrl1_addr & ~CE_CTRL1_DMAX_LENGTH_MASK) |
CE_CTRL1_DMAX_LENGTH_SET(n));
}
static inline void ath10k_ce_src_ring_byte_swap_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
u32 ctrl1_addr = ath10k_pci_read32(ar, ce_ctrl_addr + CE_CTRL1_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + CE_CTRL1_ADDRESS,
(ctrl1_addr & ~CE_CTRL1_SRC_RING_BYTE_SWAP_EN_MASK) |
CE_CTRL1_SRC_RING_BYTE_SWAP_EN_SET(n));
}
static inline void ath10k_ce_dest_ring_byte_swap_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
u32 ctrl1_addr = ath10k_pci_read32(ar, ce_ctrl_addr + CE_CTRL1_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + CE_CTRL1_ADDRESS,
(ctrl1_addr & ~CE_CTRL1_DST_RING_BYTE_SWAP_EN_MASK) |
CE_CTRL1_DST_RING_BYTE_SWAP_EN_SET(n));
}
static inline u32 ath10k_ce_dest_ring_read_index_get(struct ath10k *ar,
u32 ce_ctrl_addr)
{
return ath10k_pci_read32(ar, ce_ctrl_addr + CURRENT_DRRI_ADDRESS);
}
static inline void ath10k_ce_dest_ring_base_addr_set(struct ath10k *ar,
u32 ce_ctrl_addr,
u32 addr)
{
ath10k_pci_write32(ar, ce_ctrl_addr + DR_BA_ADDRESS, addr);
}
static inline void ath10k_ce_dest_ring_size_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
ath10k_pci_write32(ar, ce_ctrl_addr + DR_SIZE_ADDRESS, n);
}
static inline void ath10k_ce_src_ring_highmark_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
u32 addr = ath10k_pci_read32(ar, ce_ctrl_addr + SRC_WATERMARK_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + SRC_WATERMARK_ADDRESS,
(addr & ~SRC_WATERMARK_HIGH_MASK) |
SRC_WATERMARK_HIGH_SET(n));
}
static inline void ath10k_ce_src_ring_lowmark_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
u32 addr = ath10k_pci_read32(ar, ce_ctrl_addr + SRC_WATERMARK_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + SRC_WATERMARK_ADDRESS,
(addr & ~SRC_WATERMARK_LOW_MASK) |
SRC_WATERMARK_LOW_SET(n));
}
static inline void ath10k_ce_dest_ring_highmark_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
u32 addr = ath10k_pci_read32(ar, ce_ctrl_addr + DST_WATERMARK_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + DST_WATERMARK_ADDRESS,
(addr & ~DST_WATERMARK_HIGH_MASK) |
DST_WATERMARK_HIGH_SET(n));
}
static inline void ath10k_ce_dest_ring_lowmark_set(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int n)
{
u32 addr = ath10k_pci_read32(ar, ce_ctrl_addr + DST_WATERMARK_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + DST_WATERMARK_ADDRESS,
(addr & ~DST_WATERMARK_LOW_MASK) |
DST_WATERMARK_LOW_SET(n));
}
static inline void ath10k_ce_copy_complete_inter_enable(struct ath10k *ar,
u32 ce_ctrl_addr)
{
u32 host_ie_addr = ath10k_pci_read32(ar,
ce_ctrl_addr + HOST_IE_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + HOST_IE_ADDRESS,
host_ie_addr | HOST_IE_COPY_COMPLETE_MASK);
}
static inline void ath10k_ce_copy_complete_intr_disable(struct ath10k *ar,
u32 ce_ctrl_addr)
{
u32 host_ie_addr = ath10k_pci_read32(ar,
ce_ctrl_addr + HOST_IE_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + HOST_IE_ADDRESS,
host_ie_addr & ~HOST_IE_COPY_COMPLETE_MASK);
}
static inline void ath10k_ce_watermark_intr_disable(struct ath10k *ar,
u32 ce_ctrl_addr)
{
u32 host_ie_addr = ath10k_pci_read32(ar,
ce_ctrl_addr + HOST_IE_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + HOST_IE_ADDRESS,
host_ie_addr & ~CE_WATERMARK_MASK);
}
static inline void ath10k_ce_error_intr_enable(struct ath10k *ar,
u32 ce_ctrl_addr)
{
u32 misc_ie_addr = ath10k_pci_read32(ar,
ce_ctrl_addr + MISC_IE_ADDRESS);
ath10k_pci_write32(ar, ce_ctrl_addr + MISC_IE_ADDRESS,
misc_ie_addr | CE_ERROR_MASK);
}
static inline void ath10k_ce_engine_int_status_clear(struct ath10k *ar,
u32 ce_ctrl_addr,
unsigned int mask)
{
ath10k_pci_write32(ar, ce_ctrl_addr + HOST_IS_ADDRESS, mask);
}
static int ath10k_ce_send_nolock(struct ce_state *ce_state,
void *per_transfer_context,
u32 buffer,
unsigned int nbytes,
unsigned int transfer_id,
unsigned int flags)
{
struct ath10k *ar = ce_state->ar;
struct ce_ring_state *src_ring = ce_state->src_ring;
struct ce_desc *desc, *sdesc;
unsigned int nentries_mask = src_ring->nentries_mask;
unsigned int sw_index = src_ring->sw_index;
unsigned int write_index = src_ring->write_index;
u32 ctrl_addr = ce_state->ctrl_addr;
u32 desc_flags = 0;
int ret = 0;
if (nbytes > ce_state->src_sz_max)
ath10k_warn("%s: send more we can (nbytes: %d, max: %d)\n",
__func__, nbytes, ce_state->src_sz_max);
ath10k_pci_wake(ar);
if (unlikely(CE_RING_DELTA(nentries_mask,
write_index, sw_index - 1) <= 0)) {
ret = -EIO;
goto exit;
}
desc = CE_SRC_RING_TO_DESC(src_ring->base_addr_owner_space,
write_index);
sdesc = CE_SRC_RING_TO_DESC(src_ring->shadow_base, write_index);
desc_flags |= SM(transfer_id, CE_DESC_FLAGS_META_DATA);
if (flags & CE_SEND_FLAG_GATHER)
desc_flags |= CE_DESC_FLAGS_GATHER;
if (flags & CE_SEND_FLAG_BYTE_SWAP)
desc_flags |= CE_DESC_FLAGS_BYTE_SWAP;
sdesc->addr = __cpu_to_le32(buffer);
sdesc->nbytes = __cpu_to_le16(nbytes);
sdesc->flags = __cpu_to_le16(desc_flags);
*desc = *sdesc;
src_ring->per_transfer_context[write_index] = per_transfer_context;
write_index = CE_RING_IDX_INCR(nentries_mask, write_index);
if (!(flags & CE_SEND_FLAG_GATHER))
ath10k_ce_src_ring_write_index_set(ar, ctrl_addr, write_index);
src_ring->write_index = write_index;
exit:
ath10k_pci_sleep(ar);
return ret;
}
int ath10k_ce_send(struct ce_state *ce_state,
void *per_transfer_context,
u32 buffer,
unsigned int nbytes,
unsigned int transfer_id,
unsigned int flags)
{
struct ath10k *ar = ce_state->ar;
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
int ret;
spin_lock_bh(&ar_pci->ce_lock);
ret = ath10k_ce_send_nolock(ce_state, per_transfer_context,
buffer, nbytes, transfer_id, flags);
spin_unlock_bh(&ar_pci->ce_lock);
return ret;
}
void ath10k_ce_sendlist_buf_add(struct ce_sendlist *sendlist, u32 buffer,
unsigned int nbytes, u32 flags)
{
unsigned int num_items = sendlist->num_items;
struct ce_sendlist_item *item;
item = &sendlist->item[num_items];
item->data = buffer;
item->u.nbytes = nbytes;
item->flags = flags;
sendlist->num_items++;
}
int ath10k_ce_sendlist_send(struct ce_state *ce_state,
void *per_transfer_context,
struct ce_sendlist *sendlist,
unsigned int transfer_id)
{
struct ce_ring_state *src_ring = ce_state->src_ring;
struct ce_sendlist_item *item;
struct ath10k *ar = ce_state->ar;
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
unsigned int nentries_mask = src_ring->nentries_mask;
unsigned int num_items = sendlist->num_items;
unsigned int sw_index;
unsigned int write_index;
int i, delta, ret = -ENOMEM;
spin_lock_bh(&ar_pci->ce_lock);
sw_index = src_ring->sw_index;
write_index = src_ring->write_index;
delta = CE_RING_DELTA(nentries_mask, write_index, sw_index - 1);
if (delta >= num_items) {
for (i = 0; i < num_items - 1; i++) {
item = &sendlist->item[i];
ret = ath10k_ce_send_nolock(ce_state,
CE_SENDLIST_ITEM_CTXT,
(u32) item->data,
item->u.nbytes, transfer_id,
item->flags |
CE_SEND_FLAG_GATHER);
if (ret)
ath10k_warn("CE send failed for item: %d\n", i);
}
item = &sendlist->item[i];
ret = ath10k_ce_send_nolock(ce_state, per_transfer_context,
(u32) item->data, item->u.nbytes,
transfer_id, item->flags);
if (ret)
ath10k_warn("CE send failed for last item: %d\n", i);
}
spin_unlock_bh(&ar_pci->ce_lock);
return ret;
}
int ath10k_ce_recv_buf_enqueue(struct ce_state *ce_state,
void *per_recv_context,
u32 buffer)
{
struct ce_ring_state *dest_ring = ce_state->dest_ring;
u32 ctrl_addr = ce_state->ctrl_addr;
struct ath10k *ar = ce_state->ar;
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
unsigned int nentries_mask = dest_ring->nentries_mask;
unsigned int write_index;
unsigned int sw_index;
int ret;
spin_lock_bh(&ar_pci->ce_lock);
write_index = dest_ring->write_index;
sw_index = dest_ring->sw_index;
ath10k_pci_wake(ar);
if (CE_RING_DELTA(nentries_mask, write_index, sw_index - 1) > 0) {
struct ce_desc *base = dest_ring->base_addr_owner_space;
struct ce_desc *desc = CE_DEST_RING_TO_DESC(base, write_index);
desc->addr = __cpu_to_le32(buffer);
desc->nbytes = 0;
dest_ring->per_transfer_context[write_index] =
per_recv_context;
write_index = CE_RING_IDX_INCR(nentries_mask, write_index);
ath10k_ce_dest_ring_write_index_set(ar, ctrl_addr, write_index);
dest_ring->write_index = write_index;
ret = 0;
} else {
ret = -EIO;
}
ath10k_pci_sleep(ar);
spin_unlock_bh(&ar_pci->ce_lock);
return ret;
}
static int ath10k_ce_completed_recv_next_nolock(struct ce_state *ce_state,
void **per_transfer_contextp,
u32 *bufferp,
unsigned int *nbytesp,
unsigned int *transfer_idp,
unsigned int *flagsp)
{
struct ce_ring_state *dest_ring = ce_state->dest_ring;
unsigned int nentries_mask = dest_ring->nentries_mask;
unsigned int sw_index = dest_ring->sw_index;
struct ce_desc *base = dest_ring->base_addr_owner_space;
struct ce_desc *desc = CE_DEST_RING_TO_DESC(base, sw_index);
struct ce_desc sdesc;
u16 nbytes;
sdesc = *desc;
nbytes = __le16_to_cpu(sdesc.nbytes);
if (nbytes == 0) {
return -EIO;
}
desc->nbytes = 0;
*bufferp = __le32_to_cpu(sdesc.addr);
*nbytesp = nbytes;
*transfer_idp = MS(__le16_to_cpu(sdesc.flags), CE_DESC_FLAGS_META_DATA);
if (__le16_to_cpu(sdesc.flags) & CE_DESC_FLAGS_BYTE_SWAP)
*flagsp = CE_RECV_FLAG_SWAPPED;
else
*flagsp = 0;
if (per_transfer_contextp)
*per_transfer_contextp =
dest_ring->per_transfer_context[sw_index];
dest_ring->per_transfer_context[sw_index] = NULL;
sw_index = CE_RING_IDX_INCR(nentries_mask, sw_index);
dest_ring->sw_index = sw_index;
return 0;
}
int ath10k_ce_completed_recv_next(struct ce_state *ce_state,
void **per_transfer_contextp,
u32 *bufferp,
unsigned int *nbytesp,
unsigned int *transfer_idp,
unsigned int *flagsp)
{
struct ath10k *ar = ce_state->ar;
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
int ret;
spin_lock_bh(&ar_pci->ce_lock);
ret = ath10k_ce_completed_recv_next_nolock(ce_state,
per_transfer_contextp,
bufferp, nbytesp,
transfer_idp, flagsp);
spin_unlock_bh(&ar_pci->ce_lock);
return ret;
}
int ath10k_ce_revoke_recv_next(struct ce_state *ce_state,
void **per_transfer_contextp,
u32 *bufferp)
{
struct ce_ring_state *dest_ring;
unsigned int nentries_mask;
unsigned int sw_index;
unsigned int write_index;
int ret;
struct ath10k *ar;
struct ath10k_pci *ar_pci;
dest_ring = ce_state->dest_ring;
if (!dest_ring)
return -EIO;
ar = ce_state->ar;
ar_pci = ath10k_pci_priv(ar);
spin_lock_bh(&ar_pci->ce_lock);
nentries_mask = dest_ring->nentries_mask;
sw_index = dest_ring->sw_index;
write_index = dest_ring->write_index;
if (write_index != sw_index) {
struct ce_desc *base = dest_ring->base_addr_owner_space;
struct ce_desc *desc = CE_DEST_RING_TO_DESC(base, sw_index);
*bufferp = __le32_to_cpu(desc->addr);
if (per_transfer_contextp)
*per_transfer_contextp =
dest_ring->per_transfer_context[sw_index];
dest_ring->per_transfer_context[sw_index] = NULL;
sw_index = CE_RING_IDX_INCR(nentries_mask, sw_index);
dest_ring->sw_index = sw_index;
ret = 0;
} else {
ret = -EIO;
}
spin_unlock_bh(&ar_pci->ce_lock);
return ret;
}
static int ath10k_ce_completed_send_next_nolock(struct ce_state *ce_state,
void **per_transfer_contextp,
u32 *bufferp,
unsigned int *nbytesp,
unsigned int *transfer_idp)
{
struct ce_ring_state *src_ring = ce_state->src_ring;
u32 ctrl_addr = ce_state->ctrl_addr;
struct ath10k *ar = ce_state->ar;
unsigned int nentries_mask = src_ring->nentries_mask;
unsigned int sw_index = src_ring->sw_index;
unsigned int read_index;
int ret = -EIO;
if (src_ring->hw_index == sw_index) {
ath10k_pci_wake(ar);
src_ring->hw_index =
ath10k_ce_src_ring_read_index_get(ar, ctrl_addr);
src_ring->hw_index &= nentries_mask;
ath10k_pci_sleep(ar);
}
read_index = src_ring->hw_index;
if ((read_index != sw_index) && (read_index != 0xffffffff)) {
struct ce_desc *sbase = src_ring->shadow_base;
struct ce_desc *sdesc = CE_SRC_RING_TO_DESC(sbase, sw_index);
*bufferp = __le32_to_cpu(sdesc->addr);
*nbytesp = __le16_to_cpu(sdesc->nbytes);
*transfer_idp = MS(__le16_to_cpu(sdesc->flags),
CE_DESC_FLAGS_META_DATA);
if (per_transfer_contextp)
*per_transfer_contextp =
src_ring->per_transfer_context[sw_index];
src_ring->per_transfer_context[sw_index] = NULL;
sw_index = CE_RING_IDX_INCR(nentries_mask, sw_index);
src_ring->sw_index = sw_index;
ret = 0;
}
return ret;
}
int ath10k_ce_cancel_send_next(struct ce_state *ce_state,
void **per_transfer_contextp,
u32 *bufferp,
unsigned int *nbytesp,
unsigned int *transfer_idp)
{
struct ce_ring_state *src_ring;
unsigned int nentries_mask;
unsigned int sw_index;
unsigned int write_index;
int ret;
struct ath10k *ar;
struct ath10k_pci *ar_pci;
src_ring = ce_state->src_ring;
if (!src_ring)
return -EIO;
ar = ce_state->ar;
ar_pci = ath10k_pci_priv(ar);
spin_lock_bh(&ar_pci->ce_lock);
nentries_mask = src_ring->nentries_mask;
sw_index = src_ring->sw_index;
write_index = src_ring->write_index;
if (write_index != sw_index) {
struct ce_desc *base = src_ring->base_addr_owner_space;
struct ce_desc *desc = CE_SRC_RING_TO_DESC(base, sw_index);
*bufferp = __le32_to_cpu(desc->addr);
*nbytesp = __le16_to_cpu(desc->nbytes);
*transfer_idp = MS(__le16_to_cpu(desc->flags),
CE_DESC_FLAGS_META_DATA);
if (per_transfer_contextp)
*per_transfer_contextp =
src_ring->per_transfer_context[sw_index];
src_ring->per_transfer_context[sw_index] = NULL;
sw_index = CE_RING_IDX_INCR(nentries_mask, sw_index);
src_ring->sw_index = sw_index;
ret = 0;
} else {
ret = -EIO;
}
spin_unlock_bh(&ar_pci->ce_lock);
return ret;
}
int ath10k_ce_completed_send_next(struct ce_state *ce_state,
void **per_transfer_contextp,
u32 *bufferp,
unsigned int *nbytesp,
unsigned int *transfer_idp)
{
struct ath10k *ar = ce_state->ar;
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
int ret;
spin_lock_bh(&ar_pci->ce_lock);
ret = ath10k_ce_completed_send_next_nolock(ce_state,
per_transfer_contextp,
bufferp, nbytesp,
transfer_idp);
spin_unlock_bh(&ar_pci->ce_lock);
return ret;
}
void ath10k_ce_per_engine_service(struct ath10k *ar, unsigned int ce_id)
{
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
struct ce_state *ce_state = ar_pci->ce_id_to_state[ce_id];
u32 ctrl_addr = ce_state->ctrl_addr;
void *transfer_context;
u32 buf;
unsigned int nbytes;
unsigned int id;
unsigned int flags;
ath10k_pci_wake(ar);
spin_lock_bh(&ar_pci->ce_lock);
ath10k_ce_engine_int_status_clear(ar, ctrl_addr,
HOST_IS_COPY_COMPLETE_MASK);
if (ce_state->recv_cb) {
while (ath10k_ce_completed_recv_next_nolock(ce_state,
&transfer_context,
&buf, &nbytes,
&id, &flags) == 0) {
spin_unlock_bh(&ar_pci->ce_lock);
ce_state->recv_cb(ce_state, transfer_context, buf,
nbytes, id, flags);
spin_lock_bh(&ar_pci->ce_lock);
}
}
if (ce_state->send_cb) {
while (ath10k_ce_completed_send_next_nolock(ce_state,
&transfer_context,
&buf,
&nbytes,
&id) == 0) {
spin_unlock_bh(&ar_pci->ce_lock);
ce_state->send_cb(ce_state, transfer_context,
buf, nbytes, id);
spin_lock_bh(&ar_pci->ce_lock);
}
}
ath10k_ce_engine_int_status_clear(ar, ctrl_addr, CE_WATERMARK_MASK);
spin_unlock_bh(&ar_pci->ce_lock);
ath10k_pci_sleep(ar);
}
void ath10k_ce_per_engine_service_any(struct ath10k *ar)
{
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
int ce_id;
u32 intr_summary;
ath10k_pci_wake(ar);
intr_summary = CE_INTERRUPT_SUMMARY(ar);
for (ce_id = 0; intr_summary && (ce_id < ar_pci->ce_count); ce_id++) {
if (intr_summary & (1 << ce_id))
intr_summary &= ~(1 << ce_id);
else
continue;
ath10k_ce_per_engine_service(ar, ce_id);
}
ath10k_pci_sleep(ar);
}
static void ath10k_ce_per_engine_handler_adjust(struct ce_state *ce_state,
int disable_copy_compl_intr)
{
u32 ctrl_addr = ce_state->ctrl_addr;
struct ath10k *ar = ce_state->ar;
ath10k_pci_wake(ar);
if ((!disable_copy_compl_intr) &&
(ce_state->send_cb || ce_state->recv_cb))
ath10k_ce_copy_complete_inter_enable(ar, ctrl_addr);
else
ath10k_ce_copy_complete_intr_disable(ar, ctrl_addr);
ath10k_ce_watermark_intr_disable(ar, ctrl_addr);
ath10k_pci_sleep(ar);
}
void ath10k_ce_disable_interrupts(struct ath10k *ar)
{
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
int ce_id;
ath10k_pci_wake(ar);
for (ce_id = 0; ce_id < ar_pci->ce_count; ce_id++) {
struct ce_state *ce_state = ar_pci->ce_id_to_state[ce_id];
u32 ctrl_addr = ce_state->ctrl_addr;
ath10k_ce_copy_complete_intr_disable(ar, ctrl_addr);
}
ath10k_pci_sleep(ar);
}
void ath10k_ce_send_cb_register(struct ce_state *ce_state,
void (*send_cb) (struct ce_state *ce_state,
void *transfer_context,
u32 buffer,
unsigned int nbytes,
unsigned int transfer_id),
int disable_interrupts)
{
struct ath10k *ar = ce_state->ar;
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
spin_lock_bh(&ar_pci->ce_lock);
ce_state->send_cb = send_cb;
ath10k_ce_per_engine_handler_adjust(ce_state, disable_interrupts);
spin_unlock_bh(&ar_pci->ce_lock);
}
void ath10k_ce_recv_cb_register(struct ce_state *ce_state,
void (*recv_cb) (struct ce_state *ce_state,
void *transfer_context,
u32 buffer,
unsigned int nbytes,
unsigned int transfer_id,
unsigned int flags))
{
struct ath10k *ar = ce_state->ar;
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
spin_lock_bh(&ar_pci->ce_lock);
ce_state->recv_cb = recv_cb;
ath10k_ce_per_engine_handler_adjust(ce_state, 0);
spin_unlock_bh(&ar_pci->ce_lock);
}
static int ath10k_ce_init_src_ring(struct ath10k *ar,
unsigned int ce_id,
struct ce_state *ce_state,
const struct ce_attr *attr)
{
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
struct ce_ring_state *src_ring;
unsigned int nentries = attr->src_nentries;
unsigned int ce_nbytes;
u32 ctrl_addr = ath10k_ce_base_address(ce_id);
dma_addr_t base_addr;
char *ptr;
nentries = roundup_pow_of_two(nentries);
if (ce_state->src_ring) {
WARN_ON(ce_state->src_ring->nentries != nentries);
return 0;
}
ce_nbytes = sizeof(struct ce_ring_state) + (nentries * sizeof(void *));
ptr = kzalloc(ce_nbytes, GFP_KERNEL);
if (ptr == NULL)
return -ENOMEM;
ce_state->src_ring = (struct ce_ring_state *)ptr;
src_ring = ce_state->src_ring;
ptr += sizeof(struct ce_ring_state);
src_ring->nentries = nentries;
src_ring->nentries_mask = nentries - 1;
ath10k_pci_wake(ar);
src_ring->sw_index = ath10k_ce_src_ring_read_index_get(ar, ctrl_addr);
src_ring->sw_index &= src_ring->nentries_mask;
src_ring->hw_index = src_ring->sw_index;
src_ring->write_index =
ath10k_ce_src_ring_write_index_get(ar, ctrl_addr);
src_ring->write_index &= src_ring->nentries_mask;
ath10k_pci_sleep(ar);
src_ring->per_transfer_context = (void **)ptr;
src_ring->base_addr_owner_space_unaligned =
pci_alloc_consistent(ar_pci->pdev,
(nentries * sizeof(struct ce_desc) +
CE_DESC_RING_ALIGN),
&base_addr);
src_ring->base_addr_ce_space_unaligned = base_addr;
src_ring->base_addr_owner_space = PTR_ALIGN(
src_ring->base_addr_owner_space_unaligned,
CE_DESC_RING_ALIGN);
src_ring->base_addr_ce_space = ALIGN(
src_ring->base_addr_ce_space_unaligned,
CE_DESC_RING_ALIGN);
src_ring->shadow_base_unaligned =
kmalloc((nentries * sizeof(struct ce_desc) +
CE_DESC_RING_ALIGN), GFP_KERNEL);
src_ring->shadow_base = PTR_ALIGN(
src_ring->shadow_base_unaligned,
CE_DESC_RING_ALIGN);
ath10k_pci_wake(ar);
ath10k_ce_src_ring_base_addr_set(ar, ctrl_addr,
src_ring->base_addr_ce_space);
ath10k_ce_src_ring_size_set(ar, ctrl_addr, nentries);
ath10k_ce_src_ring_dmax_set(ar, ctrl_addr, attr->src_sz_max);
ath10k_ce_src_ring_byte_swap_set(ar, ctrl_addr, 0);
ath10k_ce_src_ring_lowmark_set(ar, ctrl_addr, 0);
ath10k_ce_src_ring_highmark_set(ar, ctrl_addr, nentries);
ath10k_pci_sleep(ar);
return 0;
}
static int ath10k_ce_init_dest_ring(struct ath10k *ar,
unsigned int ce_id,
struct ce_state *ce_state,
const struct ce_attr *attr)
{
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
struct ce_ring_state *dest_ring;
unsigned int nentries = attr->dest_nentries;
unsigned int ce_nbytes;
u32 ctrl_addr = ath10k_ce_base_address(ce_id);
dma_addr_t base_addr;
char *ptr;
nentries = roundup_pow_of_two(nentries);
if (ce_state->dest_ring) {
WARN_ON(ce_state->dest_ring->nentries != nentries);
return 0;
}
ce_nbytes = sizeof(struct ce_ring_state) + (nentries * sizeof(void *));
ptr = kzalloc(ce_nbytes, GFP_KERNEL);
if (ptr == NULL)
return -ENOMEM;
ce_state->dest_ring = (struct ce_ring_state *)ptr;
dest_ring = ce_state->dest_ring;
ptr += sizeof(struct ce_ring_state);
dest_ring->nentries = nentries;
dest_ring->nentries_mask = nentries - 1;
ath10k_pci_wake(ar);
dest_ring->sw_index = ath10k_ce_dest_ring_read_index_get(ar, ctrl_addr);
dest_ring->sw_index &= dest_ring->nentries_mask;
dest_ring->write_index =
ath10k_ce_dest_ring_write_index_get(ar, ctrl_addr);
dest_ring->write_index &= dest_ring->nentries_mask;
ath10k_pci_sleep(ar);
dest_ring->per_transfer_context = (void **)ptr;
dest_ring->base_addr_owner_space_unaligned =
pci_alloc_consistent(ar_pci->pdev,
(nentries * sizeof(struct ce_desc) +
CE_DESC_RING_ALIGN),
&base_addr);
dest_ring->base_addr_ce_space_unaligned = base_addr;
memset(dest_ring->base_addr_owner_space_unaligned, 0,
nentries * sizeof(struct ce_desc) + CE_DESC_RING_ALIGN);
dest_ring->base_addr_owner_space = PTR_ALIGN(
dest_ring->base_addr_owner_space_unaligned,
CE_DESC_RING_ALIGN);
dest_ring->base_addr_ce_space = ALIGN(
dest_ring->base_addr_ce_space_unaligned,
CE_DESC_RING_ALIGN);
ath10k_pci_wake(ar);
ath10k_ce_dest_ring_base_addr_set(ar, ctrl_addr,
dest_ring->base_addr_ce_space);
ath10k_ce_dest_ring_size_set(ar, ctrl_addr, nentries);
ath10k_ce_dest_ring_byte_swap_set(ar, ctrl_addr, 0);
ath10k_ce_dest_ring_lowmark_set(ar, ctrl_addr, 0);
ath10k_ce_dest_ring_highmark_set(ar, ctrl_addr, nentries);
ath10k_pci_sleep(ar);
return 0;
}
static struct ce_state *ath10k_ce_init_state(struct ath10k *ar,
unsigned int ce_id,
const struct ce_attr *attr)
{
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
struct ce_state *ce_state = NULL;
u32 ctrl_addr = ath10k_ce_base_address(ce_id);
spin_lock_bh(&ar_pci->ce_lock);
if (!ar_pci->ce_id_to_state[ce_id]) {
ce_state = kzalloc(sizeof(*ce_state), GFP_ATOMIC);
if (ce_state == NULL) {
spin_unlock_bh(&ar_pci->ce_lock);
return NULL;
}
ar_pci->ce_id_to_state[ce_id] = ce_state;
ce_state->ar = ar;
ce_state->id = ce_id;
ce_state->ctrl_addr = ctrl_addr;
ce_state->state = CE_RUNNING;
ce_state->attr_flags = attr->flags;
ce_state->src_sz_max = attr->src_sz_max;
}
spin_unlock_bh(&ar_pci->ce_lock);
return ce_state;
}
struct ce_state *ath10k_ce_init(struct ath10k *ar,
unsigned int ce_id,
const struct ce_attr *attr)
{
struct ce_state *ce_state;
u32 ctrl_addr = ath10k_ce_base_address(ce_id);
ce_state = ath10k_ce_init_state(ar, ce_id, attr);
if (!ce_state) {
ath10k_err("Failed to initialize CE state for ID: %d\n", ce_id);
return NULL;
}
if (attr->src_nentries) {
if (ath10k_ce_init_src_ring(ar, ce_id, ce_state, attr)) {
ath10k_err("Failed to initialize CE src ring for ID: %d\n",
ce_id);
ath10k_ce_deinit(ce_state);
return NULL;
}
}
if (attr->dest_nentries) {
if (ath10k_ce_init_dest_ring(ar, ce_id, ce_state, attr)) {
ath10k_err("Failed to initialize CE dest ring for ID: %d\n",
ce_id);
ath10k_ce_deinit(ce_state);
return NULL;
}
}
ath10k_pci_wake(ar);
ath10k_ce_error_intr_enable(ar, ctrl_addr);
ath10k_pci_sleep(ar);
return ce_state;
}
void ath10k_ce_deinit(struct ce_state *ce_state)
{
unsigned int ce_id = ce_state->id;
struct ath10k *ar = ce_state->ar;
struct ath10k_pci *ar_pci = ath10k_pci_priv(ar);
ce_state->state = CE_UNUSED;
ar_pci->ce_id_to_state[ce_id] = NULL;
if (ce_state->src_ring) {
kfree(ce_state->src_ring->shadow_base_unaligned);
pci_free_consistent(ar_pci->pdev,
(ce_state->src_ring->nentries *
sizeof(struct ce_desc) +
CE_DESC_RING_ALIGN),
ce_state->src_ring->base_addr_owner_space,
ce_state->src_ring->base_addr_ce_space);
kfree(ce_state->src_ring);
}
if (ce_state->dest_ring) {
pci_free_consistent(ar_pci->pdev,
(ce_state->dest_ring->nentries *
sizeof(struct ce_desc) +
CE_DESC_RING_ALIGN),
ce_state->dest_ring->base_addr_owner_space,
ce_state->dest_ring->base_addr_ce_space);
kfree(ce_state->dest_ring);
}
kfree(ce_state);
}
