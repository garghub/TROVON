static bool ixgbe_cache_ring_dcb_sriov(struct ixgbe_adapter *adapter)
{
#ifdef IXGBE_FCOE
struct ixgbe_ring_feature *fcoe = &adapter->ring_feature[RING_F_FCOE];
#endif
struct ixgbe_ring_feature *vmdq = &adapter->ring_feature[RING_F_VMDQ];
int i;
u16 reg_idx;
u8 tcs = netdev_get_num_tc(adapter->netdev);
if (tcs <= 1)
return false;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return false;
reg_idx = vmdq->offset * __ALIGN_MASK(1, ~vmdq->mask);
for (i = 0; i < adapter->num_rx_queues; i++, reg_idx++) {
if ((reg_idx & ~vmdq->mask) >= tcs)
reg_idx = __ALIGN_MASK(reg_idx, ~vmdq->mask);
adapter->rx_ring[i]->reg_idx = reg_idx;
}
reg_idx = vmdq->offset * __ALIGN_MASK(1, ~vmdq->mask);
for (i = 0; i < adapter->num_tx_queues; i++, reg_idx++) {
if ((reg_idx & ~vmdq->mask) >= tcs)
reg_idx = __ALIGN_MASK(reg_idx, ~vmdq->mask);
adapter->tx_ring[i]->reg_idx = reg_idx;
}
#ifdef IXGBE_FCOE
if (!(adapter->flags & IXGBE_FLAG_FCOE_ENABLED))
return true;
if (fcoe->offset < tcs)
return true;
if (fcoe->indices) {
u16 queues_per_pool = __ALIGN_MASK(1, ~vmdq->mask);
u8 fcoe_tc = ixgbe_fcoe_get_tc(adapter);
reg_idx = (vmdq->offset + vmdq->indices) * queues_per_pool;
for (i = fcoe->offset; i < adapter->num_rx_queues; i++) {
reg_idx = __ALIGN_MASK(reg_idx, ~vmdq->mask) + fcoe_tc;
adapter->rx_ring[i]->reg_idx = reg_idx;
reg_idx++;
}
reg_idx = (vmdq->offset + vmdq->indices) * queues_per_pool;
for (i = fcoe->offset; i < adapter->num_tx_queues; i++) {
reg_idx = __ALIGN_MASK(reg_idx, ~vmdq->mask) + fcoe_tc;
adapter->tx_ring[i]->reg_idx = reg_idx;
reg_idx++;
}
}
#endif
return true;
}
static void ixgbe_get_first_reg_idx(struct ixgbe_adapter *adapter, u8 tc,
unsigned int *tx, unsigned int *rx)
{
struct net_device *dev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
u8 num_tcs = netdev_get_num_tc(dev);
*tx = 0;
*rx = 0;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
*tx = tc << 2;
*rx = tc << 3;
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
if (num_tcs > 4) {
*rx = tc << 4;
if (tc < 3)
*tx = tc << 5;
else if (tc < 5)
*tx = (tc + 2) << 4;
else
*tx = (tc + 8) << 3;
} else {
*rx = tc << 5;
if (tc < 2)
*tx = tc << 6;
else
*tx = (tc + 4) << 4;
}
default:
break;
}
}
static bool ixgbe_cache_ring_dcb(struct ixgbe_adapter *adapter)
{
struct net_device *dev = adapter->netdev;
unsigned int tx_idx, rx_idx;
int tc, offset, rss_i, i;
u8 num_tcs = netdev_get_num_tc(dev);
if (num_tcs <= 1)
return false;
rss_i = adapter->ring_feature[RING_F_RSS].indices;
for (tc = 0, offset = 0; tc < num_tcs; tc++, offset += rss_i) {
ixgbe_get_first_reg_idx(adapter, tc, &tx_idx, &rx_idx);
for (i = 0; i < rss_i; i++, tx_idx++, rx_idx++) {
adapter->tx_ring[offset + i]->reg_idx = tx_idx;
adapter->rx_ring[offset + i]->reg_idx = rx_idx;
adapter->tx_ring[offset + i]->dcb_tc = tc;
adapter->rx_ring[offset + i]->dcb_tc = tc;
}
}
return true;
}
static bool ixgbe_cache_ring_sriov(struct ixgbe_adapter *adapter)
{
#ifdef IXGBE_FCOE
struct ixgbe_ring_feature *fcoe = &adapter->ring_feature[RING_F_FCOE];
#endif
struct ixgbe_ring_feature *vmdq = &adapter->ring_feature[RING_F_VMDQ];
struct ixgbe_ring_feature *rss = &adapter->ring_feature[RING_F_RSS];
int i;
u16 reg_idx;
if (!(adapter->flags & IXGBE_FLAG_VMDQ_ENABLED))
return false;
reg_idx = vmdq->offset * __ALIGN_MASK(1, ~vmdq->mask);
for (i = 0; i < adapter->num_rx_queues; i++, reg_idx++) {
#ifdef IXGBE_FCOE
if (fcoe->offset && (i > fcoe->offset))
break;
#endif
if ((reg_idx & ~vmdq->mask) >= rss->indices)
reg_idx = __ALIGN_MASK(reg_idx, ~vmdq->mask);
adapter->rx_ring[i]->reg_idx = reg_idx;
}
#ifdef IXGBE_FCOE
for (; i < adapter->num_rx_queues; i++, reg_idx++)
adapter->rx_ring[i]->reg_idx = reg_idx;
#endif
reg_idx = vmdq->offset * __ALIGN_MASK(1, ~vmdq->mask);
for (i = 0; i < adapter->num_tx_queues; i++, reg_idx++) {
#ifdef IXGBE_FCOE
if (fcoe->offset && (i > fcoe->offset))
break;
#endif
if ((reg_idx & rss->mask) >= rss->indices)
reg_idx = __ALIGN_MASK(reg_idx, ~vmdq->mask);
adapter->tx_ring[i]->reg_idx = reg_idx;
}
#ifdef IXGBE_FCOE
for (; i < adapter->num_tx_queues; i++, reg_idx++)
adapter->tx_ring[i]->reg_idx = reg_idx;
#endif
return true;
}
static bool ixgbe_cache_ring_rss(struct ixgbe_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
adapter->rx_ring[i]->reg_idx = i;
for (i = 0; i < adapter->num_tx_queues; i++)
adapter->tx_ring[i]->reg_idx = i;
return true;
}
static void ixgbe_cache_ring_register(struct ixgbe_adapter *adapter)
{
adapter->rx_ring[0]->reg_idx = 0;
adapter->tx_ring[0]->reg_idx = 0;
#ifdef CONFIG_IXGBE_DCB
if (ixgbe_cache_ring_dcb_sriov(adapter))
return;
if (ixgbe_cache_ring_dcb(adapter))
return;
#endif
if (ixgbe_cache_ring_sriov(adapter))
return;
ixgbe_cache_ring_rss(adapter);
}
static bool ixgbe_set_dcb_sriov_queues(struct ixgbe_adapter *adapter)
{
int i;
u16 vmdq_i = adapter->ring_feature[RING_F_VMDQ].limit;
u16 vmdq_m = 0;
#ifdef IXGBE_FCOE
u16 fcoe_i = 0;
#endif
u8 tcs = netdev_get_num_tc(adapter->netdev);
if (tcs <= 1)
return false;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return false;
vmdq_i += adapter->ring_feature[RING_F_VMDQ].offset;
if (tcs > 4) {
vmdq_i = min_t(u16, vmdq_i, 16);
vmdq_m = IXGBE_82599_VMDQ_8Q_MASK;
} else {
vmdq_i = min_t(u16, vmdq_i, 32);
vmdq_m = IXGBE_82599_VMDQ_4Q_MASK;
}
#ifdef IXGBE_FCOE
fcoe_i = (128 / __ALIGN_MASK(1, ~vmdq_m)) - vmdq_i;
#endif
vmdq_i -= adapter->ring_feature[RING_F_VMDQ].offset;
adapter->ring_feature[RING_F_VMDQ].indices = vmdq_i;
adapter->ring_feature[RING_F_VMDQ].mask = vmdq_m;
adapter->ring_feature[RING_F_RSS].indices = 1;
adapter->ring_feature[RING_F_RSS].mask = IXGBE_RSS_DISABLED_MASK;
adapter->flags &= ~IXGBE_FLAG_FDIR_HASH_CAPABLE;
adapter->num_rx_pools = vmdq_i;
adapter->num_rx_queues_per_pool = tcs;
adapter->num_tx_queues = vmdq_i * tcs;
adapter->num_rx_queues = vmdq_i * tcs;
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED) {
struct ixgbe_ring_feature *fcoe;
fcoe = &adapter->ring_feature[RING_F_FCOE];
fcoe_i = min_t(u16, fcoe_i, fcoe->limit);
if (fcoe_i) {
fcoe->indices = fcoe_i;
fcoe->offset = vmdq_i * tcs;
adapter->num_tx_queues += fcoe_i;
adapter->num_rx_queues += fcoe_i;
} else if (tcs > 1) {
fcoe->indices = 1;
fcoe->offset = ixgbe_fcoe_get_tc(adapter);
} else {
adapter->flags &= ~IXGBE_FLAG_FCOE_ENABLED;
fcoe->indices = 0;
fcoe->offset = 0;
}
}
#endif
for (i = 0; i < tcs; i++)
netdev_set_tc_queue(adapter->netdev, i, 1, i);
return true;
}
static bool ixgbe_set_dcb_queues(struct ixgbe_adapter *adapter)
{
struct net_device *dev = adapter->netdev;
struct ixgbe_ring_feature *f;
int rss_i, rss_m, i;
int tcs;
tcs = netdev_get_num_tc(dev);
if (tcs <= 1)
return false;
rss_i = dev->num_tx_queues / tcs;
if (adapter->hw.mac.type == ixgbe_mac_82598EB) {
rss_i = min_t(u16, rss_i, 4);
rss_m = IXGBE_RSS_4Q_MASK;
} else if (tcs > 4) {
rss_i = min_t(u16, rss_i, 8);
rss_m = IXGBE_RSS_8Q_MASK;
} else {
rss_i = min_t(u16, rss_i, 16);
rss_m = IXGBE_RSS_16Q_MASK;
}
f = &adapter->ring_feature[RING_F_RSS];
rss_i = min_t(int, rss_i, f->limit);
f->indices = rss_i;
f->mask = rss_m;
adapter->flags &= ~IXGBE_FLAG_FDIR_HASH_CAPABLE;
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED) {
u8 tc = ixgbe_fcoe_get_tc(adapter);
f = &adapter->ring_feature[RING_F_FCOE];
f->indices = min_t(u16, rss_i, f->limit);
f->offset = rss_i * tc;
}
#endif
for (i = 0; i < tcs; i++)
netdev_set_tc_queue(dev, i, rss_i, rss_i * i);
adapter->num_tx_queues = rss_i * tcs;
adapter->num_rx_queues = rss_i * tcs;
return true;
}
static bool ixgbe_set_sriov_queues(struct ixgbe_adapter *adapter)
{
u16 vmdq_i = adapter->ring_feature[RING_F_VMDQ].limit;
u16 vmdq_m = 0;
u16 rss_i = adapter->ring_feature[RING_F_RSS].limit;
u16 rss_m = IXGBE_RSS_DISABLED_MASK;
#ifdef IXGBE_FCOE
u16 fcoe_i = 0;
#endif
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return false;
vmdq_i += adapter->ring_feature[RING_F_VMDQ].offset;
vmdq_i = min_t(u16, IXGBE_MAX_VMDQ_INDICES, vmdq_i);
if ((vmdq_i > 32) || (rss_i < 4)) {
vmdq_m = IXGBE_82599_VMDQ_2Q_MASK;
rss_m = IXGBE_RSS_2Q_MASK;
rss_i = min_t(u16, rss_i, 2);
} else {
vmdq_m = IXGBE_82599_VMDQ_4Q_MASK;
rss_m = IXGBE_RSS_4Q_MASK;
rss_i = 4;
}
#ifdef IXGBE_FCOE
fcoe_i = 128 - (vmdq_i * __ALIGN_MASK(1, ~vmdq_m));
#endif
vmdq_i -= adapter->ring_feature[RING_F_VMDQ].offset;
adapter->ring_feature[RING_F_VMDQ].indices = vmdq_i;
adapter->ring_feature[RING_F_VMDQ].mask = vmdq_m;
adapter->ring_feature[RING_F_RSS].indices = rss_i;
adapter->ring_feature[RING_F_RSS].mask = rss_m;
adapter->num_rx_pools = vmdq_i;
adapter->num_rx_queues_per_pool = rss_i;
adapter->num_rx_queues = vmdq_i * rss_i;
adapter->num_tx_queues = vmdq_i * rss_i;
adapter->flags &= ~IXGBE_FLAG_FDIR_HASH_CAPABLE;
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED) {
struct ixgbe_ring_feature *fcoe;
fcoe = &adapter->ring_feature[RING_F_FCOE];
fcoe_i = min_t(u16, fcoe_i, fcoe->limit);
if (vmdq_i > 1 && fcoe_i) {
fcoe->indices = fcoe_i;
fcoe->offset = vmdq_i * rss_i;
} else {
fcoe_i = min_t(u16, fcoe_i + rss_i, num_online_cpus());
if (!(adapter->flags & IXGBE_FLAG_MSIX_ENABLED))
fcoe_i = rss_i;
fcoe->indices = min_t(u16, fcoe_i, fcoe->limit);
fcoe->offset = fcoe_i - fcoe->indices;
fcoe_i -= rss_i;
}
adapter->num_tx_queues += fcoe_i;
adapter->num_rx_queues += fcoe_i;
}
#endif
return true;
}
static bool ixgbe_set_rss_queues(struct ixgbe_adapter *adapter)
{
struct ixgbe_ring_feature *f;
u16 rss_i;
f = &adapter->ring_feature[RING_F_RSS];
rss_i = f->limit;
f->indices = rss_i;
f->mask = IXGBE_RSS_16Q_MASK;
adapter->flags &= ~IXGBE_FLAG_FDIR_HASH_CAPABLE;
if (rss_i > 1 && adapter->atr_sample_rate) {
f = &adapter->ring_feature[RING_F_FDIR];
rss_i = f->indices = f->limit;
if (!(adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE))
adapter->flags |= IXGBE_FLAG_FDIR_HASH_CAPABLE;
}
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED) {
struct net_device *dev = adapter->netdev;
u16 fcoe_i;
f = &adapter->ring_feature[RING_F_FCOE];
fcoe_i = min_t(u16, f->limit + rss_i, num_online_cpus());
fcoe_i = min_t(u16, fcoe_i, dev->num_tx_queues);
if (!(adapter->flags & IXGBE_FLAG_MSIX_ENABLED))
fcoe_i = rss_i;
f->indices = min_t(u16, fcoe_i, f->limit);
f->offset = fcoe_i - f->indices;
rss_i = max_t(u16, fcoe_i, rss_i);
}
#endif
adapter->num_rx_queues = rss_i;
adapter->num_tx_queues = rss_i;
return true;
}
static void ixgbe_set_num_queues(struct ixgbe_adapter *adapter)
{
adapter->num_rx_queues = 1;
adapter->num_tx_queues = 1;
adapter->num_rx_pools = adapter->num_rx_queues;
adapter->num_rx_queues_per_pool = 1;
#ifdef CONFIG_IXGBE_DCB
if (ixgbe_set_dcb_sriov_queues(adapter))
return;
if (ixgbe_set_dcb_queues(adapter))
return;
#endif
if (ixgbe_set_sriov_queues(adapter))
return;
ixgbe_set_rss_queues(adapter);
}
static void ixgbe_acquire_msix_vectors(struct ixgbe_adapter *adapter,
int vectors)
{
int err, vector_threshold;
vector_threshold = MIN_MSIX_COUNT;
while (vectors >= vector_threshold) {
err = pci_enable_msix(adapter->pdev, adapter->msix_entries,
vectors);
if (!err)
break;
else if (err < 0)
vectors = 0;
else
vectors = err;
}
if (vectors < vector_threshold) {
netif_printk(adapter, hw, KERN_DEBUG, adapter->netdev,
"Unable to allocate MSI-X interrupts\n");
adapter->flags &= ~IXGBE_FLAG_MSIX_ENABLED;
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
} else {
adapter->flags |= IXGBE_FLAG_MSIX_ENABLED;
vectors -= NON_Q_VECTORS;
adapter->num_q_vectors = min(vectors, adapter->max_q_vectors);
}
}
static void ixgbe_add_ring(struct ixgbe_ring *ring,
struct ixgbe_ring_container *head)
{
ring->next = head->ring;
head->ring = ring;
head->count++;
}
static int ixgbe_alloc_q_vector(struct ixgbe_adapter *adapter,
int v_count, int v_idx,
int txr_count, int txr_idx,
int rxr_count, int rxr_idx)
{
struct ixgbe_q_vector *q_vector;
struct ixgbe_ring *ring;
int node = NUMA_NO_NODE;
int cpu = -1;
int ring_count, size;
u8 tcs = netdev_get_num_tc(adapter->netdev);
ring_count = txr_count + rxr_count;
size = sizeof(struct ixgbe_q_vector) +
(sizeof(struct ixgbe_ring) * ring_count);
if ((tcs <= 1) && !(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)) {
u16 rss_i = adapter->ring_feature[RING_F_RSS].indices;
if (rss_i > 1 && adapter->atr_sample_rate) {
if (cpu_online(v_idx)) {
cpu = v_idx;
node = cpu_to_node(cpu);
}
}
}
q_vector = kzalloc_node(size, GFP_KERNEL, node);
if (!q_vector)
q_vector = kzalloc(size, GFP_KERNEL);
if (!q_vector)
return -ENOMEM;
if (cpu != -1)
cpumask_set_cpu(cpu, &q_vector->affinity_mask);
q_vector->numa_node = node;
#ifdef CONFIG_IXGBE_DCA
q_vector->cpu = -1;
#endif
netif_napi_add(adapter->netdev, &q_vector->napi,
ixgbe_poll, 64);
napi_hash_add(&q_vector->napi);
adapter->q_vector[v_idx] = q_vector;
q_vector->adapter = adapter;
q_vector->v_idx = v_idx;
q_vector->tx.work_limit = adapter->tx_work_limit;
ring = q_vector->ring;
if (txr_count && !rxr_count) {
if (adapter->tx_itr_setting == 1)
q_vector->itr = IXGBE_10K_ITR;
else
q_vector->itr = adapter->tx_itr_setting;
} else {
if (adapter->rx_itr_setting == 1)
q_vector->itr = IXGBE_20K_ITR;
else
q_vector->itr = adapter->rx_itr_setting;
}
while (txr_count) {
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
ring->q_vector = q_vector;
ixgbe_add_ring(ring, &q_vector->tx);
ring->count = adapter->tx_ring_count;
ring->queue_index = txr_idx;
adapter->tx_ring[txr_idx] = ring;
txr_count--;
txr_idx += v_count;
ring++;
}
while (rxr_count) {
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
ring->q_vector = q_vector;
ixgbe_add_ring(ring, &q_vector->rx);
if (adapter->hw.mac.type == ixgbe_mac_82599EB)
set_bit(__IXGBE_RX_CSUM_UDP_ZERO_ERR, &ring->state);
#ifdef IXGBE_FCOE
if (adapter->netdev->features & NETIF_F_FCOE_MTU) {
struct ixgbe_ring_feature *f;
f = &adapter->ring_feature[RING_F_FCOE];
if ((rxr_idx >= f->offset) &&
(rxr_idx < f->offset + f->indices))
set_bit(__IXGBE_RX_FCOE, &ring->state);
}
#endif
ring->count = adapter->rx_ring_count;
ring->queue_index = rxr_idx;
adapter->rx_ring[rxr_idx] = ring;
rxr_count--;
rxr_idx += v_count;
ring++;
}
return 0;
}
static void ixgbe_free_q_vector(struct ixgbe_adapter *adapter, int v_idx)
{
struct ixgbe_q_vector *q_vector = adapter->q_vector[v_idx];
struct ixgbe_ring *ring;
ixgbe_for_each_ring(ring, q_vector->tx)
adapter->tx_ring[ring->queue_index] = NULL;
ixgbe_for_each_ring(ring, q_vector->rx)
adapter->rx_ring[ring->queue_index] = NULL;
adapter->q_vector[v_idx] = NULL;
napi_hash_del(&q_vector->napi);
netif_napi_del(&q_vector->napi);
kfree_rcu(q_vector, rcu);
}
static int ixgbe_alloc_q_vectors(struct ixgbe_adapter *adapter)
{
int q_vectors = adapter->num_q_vectors;
int rxr_remaining = adapter->num_rx_queues;
int txr_remaining = adapter->num_tx_queues;
int rxr_idx = 0, txr_idx = 0, v_idx = 0;
int err;
if (!(adapter->flags & IXGBE_FLAG_MSIX_ENABLED))
q_vectors = 1;
if (q_vectors >= (rxr_remaining + txr_remaining)) {
for (; rxr_remaining; v_idx++) {
err = ixgbe_alloc_q_vector(adapter, q_vectors, v_idx,
0, 0, 1, rxr_idx);
if (err)
goto err_out;
rxr_remaining--;
rxr_idx++;
}
}
for (; v_idx < q_vectors; v_idx++) {
int rqpv = DIV_ROUND_UP(rxr_remaining, q_vectors - v_idx);
int tqpv = DIV_ROUND_UP(txr_remaining, q_vectors - v_idx);
err = ixgbe_alloc_q_vector(adapter, q_vectors, v_idx,
tqpv, txr_idx,
rqpv, rxr_idx);
if (err)
goto err_out;
rxr_remaining -= rqpv;
txr_remaining -= tqpv;
rxr_idx++;
txr_idx++;
}
return 0;
err_out:
adapter->num_tx_queues = 0;
adapter->num_rx_queues = 0;
adapter->num_q_vectors = 0;
while (v_idx--)
ixgbe_free_q_vector(adapter, v_idx);
return -ENOMEM;
}
static void ixgbe_free_q_vectors(struct ixgbe_adapter *adapter)
{
int v_idx = adapter->num_q_vectors;
adapter->num_tx_queues = 0;
adapter->num_rx_queues = 0;
adapter->num_q_vectors = 0;
while (v_idx--)
ixgbe_free_q_vector(adapter, v_idx);
}
static void ixgbe_reset_interrupt_capability(struct ixgbe_adapter *adapter)
{
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED) {
adapter->flags &= ~IXGBE_FLAG_MSIX_ENABLED;
pci_disable_msix(adapter->pdev);
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
} else if (adapter->flags & IXGBE_FLAG_MSI_ENABLED) {
adapter->flags &= ~IXGBE_FLAG_MSI_ENABLED;
pci_disable_msi(adapter->pdev);
}
}
static void ixgbe_set_interrupt_capability(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int vector, v_budget, err;
v_budget = max(adapter->num_rx_queues, adapter->num_tx_queues);
v_budget = min_t(int, v_budget, num_online_cpus());
v_budget += NON_Q_VECTORS;
v_budget = min_t(int, v_budget, hw->mac.max_msix_vectors);
adapter->msix_entries = kcalloc(v_budget,
sizeof(struct msix_entry), GFP_KERNEL);
if (adapter->msix_entries) {
for (vector = 0; vector < v_budget; vector++)
adapter->msix_entries[vector].entry = vector;
ixgbe_acquire_msix_vectors(adapter, v_budget);
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED)
return;
}
if (netdev_get_num_tc(adapter->netdev) > 1) {
e_err(probe, "num TCs exceeds number of queues - disabling DCB\n");
netdev_reset_tc(adapter->netdev);
if (adapter->hw.mac.type == ixgbe_mac_82598EB)
adapter->hw.fc.requested_mode = adapter->last_lfc_mode;
adapter->flags &= ~IXGBE_FLAG_DCB_ENABLED;
adapter->temp_dcb_cfg.pfc_mode_enable = false;
adapter->dcb_cfg.pfc_mode_enable = false;
}
adapter->dcb_cfg.num_tcs.pg_tcs = 1;
adapter->dcb_cfg.num_tcs.pfc_tcs = 1;
ixgbe_disable_sriov(adapter);
adapter->ring_feature[RING_F_RSS].limit = 1;
ixgbe_set_num_queues(adapter);
adapter->num_q_vectors = 1;
err = pci_enable_msi(adapter->pdev);
if (err) {
netif_printk(adapter, hw, KERN_DEBUG, adapter->netdev,
"Unable to allocate MSI interrupt, "
"falling back to legacy. Error: %d\n", err);
return;
}
adapter->flags |= IXGBE_FLAG_MSI_ENABLED;
}
int ixgbe_init_interrupt_scheme(struct ixgbe_adapter *adapter)
{
int err;
ixgbe_set_num_queues(adapter);
ixgbe_set_interrupt_capability(adapter);
err = ixgbe_alloc_q_vectors(adapter);
if (err) {
e_dev_err("Unable to allocate memory for queue vectors\n");
goto err_alloc_q_vectors;
}
ixgbe_cache_ring_register(adapter);
e_dev_info("Multiqueue %s: Rx Queue count = %u, Tx Queue count = %u\n",
(adapter->num_rx_queues > 1) ? "Enabled" : "Disabled",
adapter->num_rx_queues, adapter->num_tx_queues);
set_bit(__IXGBE_DOWN, &adapter->state);
return 0;
err_alloc_q_vectors:
ixgbe_reset_interrupt_capability(adapter);
return err;
}
void ixgbe_clear_interrupt_scheme(struct ixgbe_adapter *adapter)
{
adapter->num_tx_queues = 0;
adapter->num_rx_queues = 0;
ixgbe_free_q_vectors(adapter);
ixgbe_reset_interrupt_capability(adapter);
}
void ixgbe_tx_ctxtdesc(struct ixgbe_ring *tx_ring, u32 vlan_macip_lens,
u32 fcoe_sof_eof, u32 type_tucmd, u32 mss_l4len_idx)
{
struct ixgbe_adv_tx_context_desc *context_desc;
u16 i = tx_ring->next_to_use;
context_desc = IXGBE_TX_CTXTDESC(tx_ring, i);
i++;
tx_ring->next_to_use = (i < tx_ring->count) ? i : 0;
type_tucmd |= IXGBE_TXD_CMD_DEXT | IXGBE_ADVTXD_DTYP_CTXT;
context_desc->vlan_macip_lens = cpu_to_le32(vlan_macip_lens);
context_desc->seqnum_seed = cpu_to_le32(fcoe_sof_eof);
context_desc->type_tucmd_mlhl = cpu_to_le32(type_tucmd);
context_desc->mss_l4len_idx = cpu_to_le32(mss_l4len_idx);
}
