int mlx4_en_create_tx_ring(struct mlx4_en_priv *priv,
struct mlx4_en_tx_ring **pring, int qpn, u32 size,
u16 stride, int node, int queue_index)
{
struct mlx4_en_dev *mdev = priv->mdev;
struct mlx4_en_tx_ring *ring;
int tmp;
int err;
ring = kzalloc_node(sizeof(*ring), GFP_KERNEL, node);
if (!ring) {
ring = kzalloc(sizeof(*ring), GFP_KERNEL);
if (!ring) {
en_err(priv, "Failed allocating TX ring\n");
return -ENOMEM;
}
}
ring->size = size;
ring->size_mask = size - 1;
ring->stride = stride;
ring->inline_thold = priv->prof->inline_thold;
tmp = size * sizeof(struct mlx4_en_tx_info);
ring->tx_info = vmalloc_node(tmp, node);
if (!ring->tx_info) {
ring->tx_info = vmalloc(tmp);
if (!ring->tx_info) {
err = -ENOMEM;
goto err_ring;
}
}
en_dbg(DRV, priv, "Allocated tx_info ring at addr:%p size:%d\n",
ring->tx_info, tmp);
ring->bounce_buf = kmalloc_node(MAX_DESC_SIZE, GFP_KERNEL, node);
if (!ring->bounce_buf) {
ring->bounce_buf = kmalloc(MAX_DESC_SIZE, GFP_KERNEL);
if (!ring->bounce_buf) {
err = -ENOMEM;
goto err_info;
}
}
ring->buf_size = ALIGN(size * ring->stride, MLX4_EN_PAGE_SIZE);
set_dev_node(&mdev->dev->pdev->dev, node);
err = mlx4_alloc_hwq_res(mdev->dev, &ring->wqres, ring->buf_size,
2 * PAGE_SIZE);
set_dev_node(&mdev->dev->pdev->dev, mdev->dev->numa_node);
if (err) {
en_err(priv, "Failed allocating hwq resources\n");
goto err_bounce;
}
err = mlx4_en_map_buffer(&ring->wqres.buf);
if (err) {
en_err(priv, "Failed to map TX buffer\n");
goto err_hwq_res;
}
ring->buf = ring->wqres.buf.direct.buf;
en_dbg(DRV, priv, "Allocated TX ring (addr:%p) - buf:%p size:%d buf_size:%d dma:%llx\n",
ring, ring->buf, ring->size, ring->buf_size,
(unsigned long long) ring->wqres.buf.direct.map);
ring->qpn = qpn;
err = mlx4_qp_alloc(mdev->dev, ring->qpn, &ring->qp, GFP_KERNEL);
if (err) {
en_err(priv, "Failed allocating qp %d\n", ring->qpn);
goto err_map;
}
ring->qp.event = mlx4_en_sqp_event;
err = mlx4_bf_alloc(mdev->dev, &ring->bf, node);
if (err) {
en_dbg(DRV, priv, "working without blueflame (%d)\n", err);
ring->bf.uar = &mdev->priv_uar;
ring->bf.uar->map = mdev->uar_map;
ring->bf_enabled = false;
ring->bf_alloced = false;
priv->pflags &= ~MLX4_EN_PRIV_FLAGS_BLUEFLAME;
} else {
ring->bf_alloced = true;
ring->bf_enabled = !!(priv->pflags &
MLX4_EN_PRIV_FLAGS_BLUEFLAME);
}
ring->hwtstamp_tx_type = priv->hwtstamp_config.tx_type;
ring->queue_index = queue_index;
if (queue_index < priv->num_tx_rings_p_up && cpu_online(queue_index))
cpumask_set_cpu(queue_index, &ring->affinity_mask);
*pring = ring;
return 0;
err_map:
mlx4_en_unmap_buffer(&ring->wqres.buf);
err_hwq_res:
mlx4_free_hwq_res(mdev->dev, &ring->wqres, ring->buf_size);
err_bounce:
kfree(ring->bounce_buf);
ring->bounce_buf = NULL;
err_info:
vfree(ring->tx_info);
ring->tx_info = NULL;
err_ring:
kfree(ring);
*pring = NULL;
return err;
}
void mlx4_en_destroy_tx_ring(struct mlx4_en_priv *priv,
struct mlx4_en_tx_ring **pring)
{
struct mlx4_en_dev *mdev = priv->mdev;
struct mlx4_en_tx_ring *ring = *pring;
en_dbg(DRV, priv, "Destroying tx ring, qpn: %d\n", ring->qpn);
if (ring->bf_alloced)
mlx4_bf_free(mdev->dev, &ring->bf);
mlx4_qp_remove(mdev->dev, &ring->qp);
mlx4_qp_free(mdev->dev, &ring->qp);
mlx4_en_unmap_buffer(&ring->wqres.buf);
mlx4_free_hwq_res(mdev->dev, &ring->wqres, ring->buf_size);
kfree(ring->bounce_buf);
ring->bounce_buf = NULL;
vfree(ring->tx_info);
ring->tx_info = NULL;
kfree(ring);
*pring = NULL;
}
int mlx4_en_activate_tx_ring(struct mlx4_en_priv *priv,
struct mlx4_en_tx_ring *ring,
int cq, int user_prio)
{
struct mlx4_en_dev *mdev = priv->mdev;
int err;
ring->cqn = cq;
ring->prod = 0;
ring->cons = 0xffffffff;
ring->last_nr_txbb = 1;
ring->poll_cnt = 0;
memset(ring->tx_info, 0, ring->size * sizeof(struct mlx4_en_tx_info));
memset(ring->buf, 0, ring->buf_size);
ring->qp_state = MLX4_QP_STATE_RST;
ring->doorbell_qpn = ring->qp.qpn << 8;
mlx4_en_fill_qp_context(priv, ring->size, ring->stride, 1, 0, ring->qpn,
ring->cqn, user_prio, &ring->context);
if (ring->bf_alloced)
ring->context.usr_page = cpu_to_be32(ring->bf.uar->index);
err = mlx4_qp_to_ready(mdev->dev, &ring->wqres.mtt, &ring->context,
&ring->qp, &ring->qp_state);
if (!user_prio && cpu_online(ring->queue_index))
netif_set_xps_queue(priv->dev, &ring->affinity_mask,
ring->queue_index);
return err;
}
void mlx4_en_deactivate_tx_ring(struct mlx4_en_priv *priv,
struct mlx4_en_tx_ring *ring)
{
struct mlx4_en_dev *mdev = priv->mdev;
mlx4_qp_modify(mdev->dev, NULL, ring->qp_state,
MLX4_QP_STATE_RST, NULL, 0, 0, &ring->qp);
}
static void mlx4_en_stamp_wqe(struct mlx4_en_priv *priv,
struct mlx4_en_tx_ring *ring, int index,
u8 owner)
{
__be32 stamp = cpu_to_be32(STAMP_VAL | (!!owner << STAMP_SHIFT));
struct mlx4_en_tx_desc *tx_desc = ring->buf + index * TXBB_SIZE;
struct mlx4_en_tx_info *tx_info = &ring->tx_info[index];
void *end = ring->buf + ring->buf_size;
__be32 *ptr = (__be32 *)tx_desc;
int i;
if (likely((void *)tx_desc + tx_info->nr_txbb * TXBB_SIZE <= end)) {
for (i = 0; i < tx_info->nr_txbb * TXBB_SIZE;
i += STAMP_STRIDE) {
*ptr = stamp;
ptr += STAMP_DWORDS;
}
} else {
for (i = 0; i < tx_info->nr_txbb * TXBB_SIZE;
i += STAMP_STRIDE) {
*ptr = stamp;
ptr += STAMP_DWORDS;
if ((void *)ptr >= end) {
ptr = ring->buf;
stamp ^= cpu_to_be32(0x80000000);
}
}
}
}
static u32 mlx4_en_free_tx_desc(struct mlx4_en_priv *priv,
struct mlx4_en_tx_ring *ring,
int index, u8 owner, u64 timestamp)
{
struct mlx4_en_dev *mdev = priv->mdev;
struct mlx4_en_tx_info *tx_info = &ring->tx_info[index];
struct mlx4_en_tx_desc *tx_desc = ring->buf + index * TXBB_SIZE;
struct mlx4_wqe_data_seg *data = (void *) tx_desc + tx_info->data_offset;
struct sk_buff *skb = tx_info->skb;
struct skb_frag_struct *frag;
void *end = ring->buf + ring->buf_size;
int frags = skb_shinfo(skb)->nr_frags;
int i;
struct skb_shared_hwtstamps hwts;
if (timestamp) {
mlx4_en_fill_hwtstamps(mdev, &hwts, timestamp);
skb_tstamp_tx(skb, &hwts);
}
if (likely((void *) tx_desc + tx_info->nr_txbb * TXBB_SIZE <= end)) {
if (!tx_info->inl) {
if (tx_info->linear) {
dma_unmap_single(priv->ddev,
(dma_addr_t) be64_to_cpu(data->addr),
be32_to_cpu(data->byte_count),
PCI_DMA_TODEVICE);
++data;
}
for (i = 0; i < frags; i++) {
frag = &skb_shinfo(skb)->frags[i];
dma_unmap_page(priv->ddev,
(dma_addr_t) be64_to_cpu(data[i].addr),
skb_frag_size(frag), PCI_DMA_TODEVICE);
}
}
} else {
if (!tx_info->inl) {
if ((void *) data >= end) {
data = ring->buf + ((void *)data - end);
}
if (tx_info->linear) {
dma_unmap_single(priv->ddev,
(dma_addr_t) be64_to_cpu(data->addr),
be32_to_cpu(data->byte_count),
PCI_DMA_TODEVICE);
++data;
}
for (i = 0; i < frags; i++) {
if ((void *) data >= end)
data = ring->buf;
frag = &skb_shinfo(skb)->frags[i];
dma_unmap_page(priv->ddev,
(dma_addr_t) be64_to_cpu(data->addr),
skb_frag_size(frag), PCI_DMA_TODEVICE);
++data;
}
}
}
dev_kfree_skb_any(skb);
return tx_info->nr_txbb;
}
int mlx4_en_free_tx_buf(struct net_device *dev, struct mlx4_en_tx_ring *ring)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
int cnt = 0;
ring->cons += ring->last_nr_txbb;
en_dbg(DRV, priv, "Freeing Tx buf - cons:0x%x prod:0x%x\n",
ring->cons, ring->prod);
if ((u32) (ring->prod - ring->cons) > ring->size) {
if (netif_msg_tx_err(priv))
en_warn(priv, "Tx consumer passed producer!\n");
return 0;
}
while (ring->cons != ring->prod) {
ring->last_nr_txbb = mlx4_en_free_tx_desc(priv, ring,
ring->cons & ring->size_mask,
!!(ring->cons & ring->size), 0);
ring->cons += ring->last_nr_txbb;
cnt++;
}
netdev_tx_reset_queue(ring->tx_queue);
if (cnt)
en_dbg(DRV, priv, "Freed %d uncompleted tx descriptors\n", cnt);
return cnt;
}
static bool mlx4_en_process_tx_cq(struct net_device *dev,
struct mlx4_en_cq *cq)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
struct mlx4_cq *mcq = &cq->mcq;
struct mlx4_en_tx_ring *ring = priv->tx_ring[cq->ring];
struct mlx4_cqe *cqe;
u16 index;
u16 new_index, ring_index, stamp_index;
u32 txbbs_skipped = 0;
u32 txbbs_stamp = 0;
u32 cons_index = mcq->cons_index;
int size = cq->size;
u32 size_mask = ring->size_mask;
struct mlx4_cqe *buf = cq->buf;
u32 packets = 0;
u32 bytes = 0;
int factor = priv->cqe_factor;
u64 timestamp = 0;
int done = 0;
int budget = priv->tx_work_limit;
if (!priv->port_up)
return true;
index = cons_index & size_mask;
cqe = &buf[(index << factor) + factor];
ring_index = ring->cons & size_mask;
stamp_index = ring_index;
while (XNOR(cqe->owner_sr_opcode & MLX4_CQE_OWNER_MASK,
cons_index & size) && (done < budget)) {
rmb();
if (unlikely((cqe->owner_sr_opcode & MLX4_CQE_OPCODE_MASK) ==
MLX4_CQE_OPCODE_ERROR)) {
struct mlx4_err_cqe *cqe_err = (struct mlx4_err_cqe *)cqe;
en_err(priv, "CQE error - vendor syndrome: 0x%x syndrome: 0x%x\n",
cqe_err->vendor_err_syndrome,
cqe_err->syndrome);
}
new_index = be16_to_cpu(cqe->wqe_index) & size_mask;
do {
txbbs_skipped += ring->last_nr_txbb;
ring_index = (ring_index + ring->last_nr_txbb) & size_mask;
if (ring->tx_info[ring_index].ts_requested)
timestamp = mlx4_en_get_cqe_ts(cqe);
ring->last_nr_txbb = mlx4_en_free_tx_desc(
priv, ring, ring_index,
!!((ring->cons + txbbs_skipped) &
ring->size), timestamp);
mlx4_en_stamp_wqe(priv, ring, stamp_index,
!!((ring->cons + txbbs_stamp) &
ring->size));
stamp_index = ring_index;
txbbs_stamp = txbbs_skipped;
packets++;
bytes += ring->tx_info[ring_index].nr_bytes;
} while ((++done < budget) && (ring_index != new_index));
++cons_index;
index = cons_index & size_mask;
cqe = &buf[(index << factor) + factor];
}
mcq->cons_index = cons_index;
mlx4_cq_set_ci(mcq);
wmb();
ring->cons += txbbs_skipped;
netdev_tx_completed_queue(ring->tx_queue, packets, bytes);
if (netif_tx_queue_stopped(ring->tx_queue) && txbbs_skipped > 0) {
netif_tx_wake_queue(ring->tx_queue);
ring->wake_queue++;
}
return done < budget;
}
void mlx4_en_tx_irq(struct mlx4_cq *mcq)
{
struct mlx4_en_cq *cq = container_of(mcq, struct mlx4_en_cq, mcq);
struct mlx4_en_priv *priv = netdev_priv(cq->dev);
if (priv->port_up)
napi_schedule(&cq->napi);
else
mlx4_en_arm_cq(priv, cq);
}
int mlx4_en_poll_tx_cq(struct napi_struct *napi, int budget)
{
struct mlx4_en_cq *cq = container_of(napi, struct mlx4_en_cq, napi);
struct net_device *dev = cq->dev;
struct mlx4_en_priv *priv = netdev_priv(dev);
int clean_complete;
clean_complete = mlx4_en_process_tx_cq(dev, cq);
if (!clean_complete)
return budget;
napi_complete(napi);
mlx4_en_arm_cq(priv, cq);
return 0;
}
static struct mlx4_en_tx_desc *mlx4_en_bounce_to_desc(struct mlx4_en_priv *priv,
struct mlx4_en_tx_ring *ring,
u32 index,
unsigned int desc_size)
{
u32 copy = (ring->size - index) * TXBB_SIZE;
int i;
for (i = desc_size - copy - 4; i >= 0; i -= 4) {
if ((i & (TXBB_SIZE - 1)) == 0)
wmb();
*((u32 *) (ring->buf + i)) =
*((u32 *) (ring->bounce_buf + copy + i));
}
for (i = copy - 4; i >= 4 ; i -= 4) {
if ((i & (TXBB_SIZE - 1)) == 0)
wmb();
*((u32 *) (ring->buf + index * TXBB_SIZE + i)) =
*((u32 *) (ring->bounce_buf + i));
}
return ring->buf + index * TXBB_SIZE;
}
static int is_inline(int inline_thold, struct sk_buff *skb, void **pfrag)
{
void *ptr;
if (inline_thold && !skb_is_gso(skb) && skb->len <= inline_thold) {
if (skb_shinfo(skb)->nr_frags == 1) {
ptr = skb_frag_address_safe(&skb_shinfo(skb)->frags[0]);
if (unlikely(!ptr))
return 0;
if (pfrag)
*pfrag = ptr;
return 1;
} else if (unlikely(skb_shinfo(skb)->nr_frags))
return 0;
else
return 1;
}
return 0;
}
static int inline_size(struct sk_buff *skb)
{
if (skb->len + CTRL_SIZE + sizeof(struct mlx4_wqe_inline_seg)
<= MLX4_INLINE_ALIGN)
return ALIGN(skb->len + CTRL_SIZE +
sizeof(struct mlx4_wqe_inline_seg), 16);
else
return ALIGN(skb->len + CTRL_SIZE + 2 *
sizeof(struct mlx4_wqe_inline_seg), 16);
}
static int get_real_size(struct sk_buff *skb, struct net_device *dev,
int *lso_header_size)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
int real_size;
if (skb_is_gso(skb)) {
if (skb->encapsulation)
*lso_header_size = (skb_inner_transport_header(skb) - skb->data) + inner_tcp_hdrlen(skb);
else
*lso_header_size = skb_transport_offset(skb) + tcp_hdrlen(skb);
real_size = CTRL_SIZE + skb_shinfo(skb)->nr_frags * DS_SIZE +
ALIGN(*lso_header_size + 4, DS_SIZE);
if (unlikely(*lso_header_size != skb_headlen(skb))) {
if (*lso_header_size < skb_headlen(skb))
real_size += DS_SIZE;
else {
if (netif_msg_tx_err(priv))
en_warn(priv, "Non-linear headers\n");
return 0;
}
}
} else {
*lso_header_size = 0;
if (!is_inline(priv->prof->inline_thold, skb, NULL))
real_size = CTRL_SIZE + (skb_shinfo(skb)->nr_frags + 1) * DS_SIZE;
else
real_size = inline_size(skb);
}
return real_size;
}
static void build_inline_wqe(struct mlx4_en_tx_desc *tx_desc, struct sk_buff *skb,
int real_size, u16 *vlan_tag, int tx_ind, void *fragptr)
{
struct mlx4_wqe_inline_seg *inl = &tx_desc->inl;
int spc = MLX4_INLINE_ALIGN - CTRL_SIZE - sizeof *inl;
if (skb->len <= spc) {
if (likely(skb->len >= MIN_PKT_LEN)) {
inl->byte_count = cpu_to_be32(1 << 31 | skb->len);
} else {
inl->byte_count = cpu_to_be32(1 << 31 | MIN_PKT_LEN);
memset(((void *)(inl + 1)) + skb->len, 0,
MIN_PKT_LEN - skb->len);
}
skb_copy_from_linear_data(skb, inl + 1, skb_headlen(skb));
if (skb_shinfo(skb)->nr_frags)
memcpy(((void *)(inl + 1)) + skb_headlen(skb), fragptr,
skb_frag_size(&skb_shinfo(skb)->frags[0]));
} else {
inl->byte_count = cpu_to_be32(1 << 31 | spc);
if (skb_headlen(skb) <= spc) {
skb_copy_from_linear_data(skb, inl + 1, skb_headlen(skb));
if (skb_headlen(skb) < spc) {
memcpy(((void *)(inl + 1)) + skb_headlen(skb),
fragptr, spc - skb_headlen(skb));
fragptr += spc - skb_headlen(skb);
}
inl = (void *) (inl + 1) + spc;
memcpy(((void *)(inl + 1)), fragptr, skb->len - spc);
} else {
skb_copy_from_linear_data(skb, inl + 1, spc);
inl = (void *) (inl + 1) + spc;
skb_copy_from_linear_data_offset(skb, spc, inl + 1,
skb_headlen(skb) - spc);
if (skb_shinfo(skb)->nr_frags)
memcpy(((void *)(inl + 1)) + skb_headlen(skb) - spc,
fragptr, skb_frag_size(&skb_shinfo(skb)->frags[0]));
}
wmb();
inl->byte_count = cpu_to_be32(1 << 31 | (skb->len - spc));
}
}
u16 mlx4_en_select_queue(struct net_device *dev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
u16 rings_p_up = priv->num_tx_rings_p_up;
u8 up = 0;
if (dev->num_tc)
return skb_tx_hash(dev, skb);
if (vlan_tx_tag_present(skb))
up = vlan_tx_tag_get(skb) >> VLAN_PRIO_SHIFT;
return fallback(dev, skb) % rings_p_up + up * rings_p_up;
}
static void mlx4_bf_copy(void __iomem *dst, unsigned long *src, unsigned bytecnt)
{
__iowrite64_copy(dst, src, bytecnt / 8);
}
netdev_tx_t mlx4_en_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
struct mlx4_en_dev *mdev = priv->mdev;
struct device *ddev = priv->ddev;
struct mlx4_en_tx_ring *ring;
struct mlx4_en_tx_desc *tx_desc;
struct mlx4_wqe_data_seg *data;
struct mlx4_en_tx_info *tx_info;
int tx_ind = 0;
int nr_txbb;
int desc_size;
int real_size;
u32 index, bf_index;
__be32 op_own;
u16 vlan_tag = 0;
int i;
int lso_header_size;
void *fragptr;
bool bounce = false;
if (!priv->port_up)
goto tx_drop;
real_size = get_real_size(skb, dev, &lso_header_size);
if (unlikely(!real_size))
goto tx_drop;
desc_size = ALIGN(real_size, TXBB_SIZE);
nr_txbb = desc_size / TXBB_SIZE;
if (unlikely(nr_txbb > MAX_DESC_TXBBS)) {
if (netif_msg_tx_err(priv))
en_warn(priv, "Oversized header or SG list\n");
goto tx_drop;
}
tx_ind = skb->queue_mapping;
ring = priv->tx_ring[tx_ind];
if (vlan_tx_tag_present(skb))
vlan_tag = vlan_tx_tag_get(skb);
if (unlikely(((int)(ring->prod - ring->cons)) >
ring->size - HEADROOM - MAX_DESC_TXBBS)) {
netif_tx_stop_queue(ring->tx_queue);
ring->queue_stopped++;
wmb();
if (unlikely(((int)(ring->prod - ring->cons)) <=
ring->size - HEADROOM - MAX_DESC_TXBBS)) {
netif_tx_wake_queue(ring->tx_queue);
ring->wake_queue++;
} else {
return NETDEV_TX_BUSY;
}
}
AVG_PERF_COUNTER(priv->pstats.inflight_avg,
(u32) (ring->prod - ring->cons - 1));
index = ring->prod & ring->size_mask;
bf_index = ring->prod;
if (likely(index + nr_txbb <= ring->size))
tx_desc = ring->buf + index * TXBB_SIZE;
else {
tx_desc = (struct mlx4_en_tx_desc *) ring->bounce_buf;
bounce = true;
}
tx_info = &ring->tx_info[index];
tx_info->skb = skb;
tx_info->nr_txbb = nr_txbb;
if (lso_header_size)
data = ((void *)&tx_desc->lso + ALIGN(lso_header_size + 4,
DS_SIZE));
else
data = &tx_desc->data;
tx_info->data_offset = (void *)data - (void *)tx_desc;
tx_info->linear = (lso_header_size < skb_headlen(skb) &&
!is_inline(ring->inline_thold, skb, NULL)) ? 1 : 0;
data += skb_shinfo(skb)->nr_frags + tx_info->linear - 1;
if (is_inline(ring->inline_thold, skb, &fragptr)) {
tx_info->inl = 1;
} else {
for (i = skb_shinfo(skb)->nr_frags - 1; i >= 0; i--) {
struct skb_frag_struct *frag;
dma_addr_t dma;
frag = &skb_shinfo(skb)->frags[i];
dma = skb_frag_dma_map(ddev, frag,
0, skb_frag_size(frag),
DMA_TO_DEVICE);
if (dma_mapping_error(ddev, dma))
goto tx_drop_unmap;
data->addr = cpu_to_be64(dma);
data->lkey = cpu_to_be32(mdev->mr.key);
wmb();
data->byte_count = cpu_to_be32(skb_frag_size(frag));
--data;
}
if (tx_info->linear) {
u32 byte_count = skb_headlen(skb) - lso_header_size;
dma_addr_t dma;
dma = dma_map_single(ddev, skb->data +
lso_header_size, byte_count,
PCI_DMA_TODEVICE);
if (dma_mapping_error(ddev, dma))
goto tx_drop_unmap;
data->addr = cpu_to_be64(dma);
data->lkey = cpu_to_be32(mdev->mr.key);
wmb();
data->byte_count = cpu_to_be32(byte_count);
}
tx_info->inl = 0;
}
if (ring->hwtstamp_tx_type == HWTSTAMP_TX_ON &&
skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
tx_info->ts_requested = 1;
}
tx_desc->ctrl.vlan_tag = cpu_to_be16(vlan_tag);
tx_desc->ctrl.ins_vlan = MLX4_WQE_CTRL_INS_VLAN *
!!vlan_tx_tag_present(skb);
tx_desc->ctrl.fence_size = (real_size / 16) & 0x3f;
tx_desc->ctrl.srcrb_flags = priv->ctrl_flags;
if (likely(skb->ip_summed == CHECKSUM_PARTIAL)) {
tx_desc->ctrl.srcrb_flags |= cpu_to_be32(MLX4_WQE_CTRL_IP_CSUM |
MLX4_WQE_CTRL_TCP_UDP_CSUM);
ring->tx_csum++;
}
if (priv->flags & MLX4_EN_FLAG_ENABLE_HW_LOOPBACK) {
struct ethhdr *ethh;
ethh = (struct ethhdr *)skb->data;
tx_desc->ctrl.srcrb_flags16[0] = get_unaligned((__be16 *)ethh->h_dest);
tx_desc->ctrl.imm = get_unaligned((__be32 *)(ethh->h_dest + 2));
}
if (lso_header_size) {
op_own = cpu_to_be32(MLX4_OPCODE_LSO | (1 << 6)) |
((ring->prod & ring->size) ?
cpu_to_be32(MLX4_EN_BIT_DESC_OWN) : 0);
tx_desc->lso.mss_hdr_size = cpu_to_be32(
skb_shinfo(skb)->gso_size << 16 | lso_header_size);
memcpy(tx_desc->lso.header, skb->data, lso_header_size);
priv->port_stats.tso_packets++;
i = ((skb->len - lso_header_size) / skb_shinfo(skb)->gso_size) +
!!((skb->len - lso_header_size) % skb_shinfo(skb)->gso_size);
tx_info->nr_bytes = skb->len + (i - 1) * lso_header_size;
ring->packets += i;
} else {
op_own = cpu_to_be32(MLX4_OPCODE_SEND) |
((ring->prod & ring->size) ?
cpu_to_be32(MLX4_EN_BIT_DESC_OWN) : 0);
tx_info->nr_bytes = max_t(unsigned int, skb->len, ETH_ZLEN);
ring->packets++;
}
ring->bytes += tx_info->nr_bytes;
netdev_tx_sent_queue(ring->tx_queue, tx_info->nr_bytes);
AVG_PERF_COUNTER(priv->pstats.tx_pktsz_avg, skb->len);
if (tx_info->inl) {
build_inline_wqe(tx_desc, skb, real_size, &vlan_tag, tx_ind, fragptr);
tx_info->inl = 1;
}
if (skb->encapsulation) {
struct iphdr *ipv4 = (struct iphdr *)skb_inner_network_header(skb);
if (ipv4->protocol == IPPROTO_TCP || ipv4->protocol == IPPROTO_UDP)
op_own |= cpu_to_be32(MLX4_WQE_CTRL_IIP | MLX4_WQE_CTRL_ILP);
else
op_own |= cpu_to_be32(MLX4_WQE_CTRL_IIP);
}
ring->prod += nr_txbb;
if (bounce)
tx_desc = mlx4_en_bounce_to_desc(priv, ring, index, desc_size);
skb_tx_timestamp(skb);
if (ring->bf_enabled && desc_size <= MAX_BF && !bounce && !vlan_tx_tag_present(skb)) {
tx_desc->ctrl.bf_qpn |= cpu_to_be32(ring->doorbell_qpn);
op_own |= htonl((bf_index & 0xffff) << 8);
wmb();
tx_desc->ctrl.owner_opcode = op_own;
wmb();
mlx4_bf_copy(ring->bf.reg + ring->bf.offset, (unsigned long *) &tx_desc->ctrl,
desc_size);
wmb();
ring->bf.offset ^= ring->bf.buf_size;
} else {
wmb();
tx_desc->ctrl.owner_opcode = op_own;
wmb();
iowrite32be(ring->doorbell_qpn, ring->bf.uar->map + MLX4_SEND_DOORBELL);
}
return NETDEV_TX_OK;
tx_drop_unmap:
en_err(priv, "DMA mapping error\n");
for (i++; i < skb_shinfo(skb)->nr_frags; i++) {
data++;
dma_unmap_page(ddev, (dma_addr_t) be64_to_cpu(data->addr),
be32_to_cpu(data->byte_count),
PCI_DMA_TODEVICE);
}
tx_drop:
dev_kfree_skb_any(skb);
priv->stats.tx_dropped++;
return NETDEV_TX_OK;
}
