int i40e_allocate_dma_mem_d(struct i40e_hw *hw, struct i40e_dma_mem *mem,
u64 size, u32 alignment)
{
struct i40e_pf *pf = (struct i40e_pf *)hw->back;
mem->size = ALIGN(size, alignment);
mem->va = dma_zalloc_coherent(&pf->pdev->dev, mem->size,
&mem->pa, GFP_KERNEL);
if (!mem->va)
return -ENOMEM;
return 0;
}
int i40e_free_dma_mem_d(struct i40e_hw *hw, struct i40e_dma_mem *mem)
{
struct i40e_pf *pf = (struct i40e_pf *)hw->back;
dma_free_coherent(&pf->pdev->dev, mem->size, mem->va, mem->pa);
mem->va = NULL;
mem->pa = 0;
mem->size = 0;
return 0;
}
int i40e_allocate_virt_mem_d(struct i40e_hw *hw, struct i40e_virt_mem *mem,
u32 size)
{
mem->size = size;
mem->va = kzalloc(size, GFP_KERNEL);
if (!mem->va)
return -ENOMEM;
return 0;
}
int i40e_free_virt_mem_d(struct i40e_hw *hw, struct i40e_virt_mem *mem)
{
kfree(mem->va);
mem->va = NULL;
mem->size = 0;
return 0;
}
static int i40e_get_lump(struct i40e_pf *pf, struct i40e_lump_tracking *pile,
u16 needed, u16 id)
{
int ret = -ENOMEM;
int i, j;
if (!pile || needed == 0 || id >= I40E_PILE_VALID_BIT) {
dev_info(&pf->pdev->dev,
"param err: pile=%p needed=%d id=0x%04x\n",
pile, needed, id);
return -EINVAL;
}
i = pile->search_hint;
while (i < pile->num_entries) {
if (pile->list[i] & I40E_PILE_VALID_BIT) {
i++;
continue;
}
for (j = 0; (j < needed) && ((i+j) < pile->num_entries); j++) {
if (pile->list[i+j] & I40E_PILE_VALID_BIT)
break;
}
if (j == needed) {
for (j = 0; j < needed; j++)
pile->list[i+j] = id | I40E_PILE_VALID_BIT;
ret = i;
pile->search_hint = i + j;
break;
}
i += j;
}
return ret;
}
static int i40e_put_lump(struct i40e_lump_tracking *pile, u16 index, u16 id)
{
int valid_id = (id | I40E_PILE_VALID_BIT);
int count = 0;
int i;
if (!pile || index >= pile->num_entries)
return -EINVAL;
for (i = index;
i < pile->num_entries && pile->list[i] == valid_id;
i++) {
pile->list[i] = 0;
count++;
}
if (count && index < pile->search_hint)
pile->search_hint = index;
return count;
}
struct i40e_vsi *i40e_find_vsi_from_id(struct i40e_pf *pf, u16 id)
{
int i;
for (i = 0; i < pf->num_alloc_vsi; i++)
if (pf->vsi[i] && (pf->vsi[i]->id == id))
return pf->vsi[i];
return NULL;
}
void i40e_service_event_schedule(struct i40e_pf *pf)
{
if (!test_bit(__I40E_DOWN, pf->state) &&
!test_bit(__I40E_RESET_RECOVERY_PENDING, pf->state))
queue_work(i40e_wq, &pf->service_task);
}
static void i40e_tx_timeout(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
struct i40e_ring *tx_ring = NULL;
unsigned int i, hung_queue = 0;
u32 head, val;
pf->tx_timeout_count++;
for (i = 0; i < netdev->num_tx_queues; i++) {
struct netdev_queue *q;
unsigned long trans_start;
q = netdev_get_tx_queue(netdev, i);
trans_start = q->trans_start;
if (netif_xmit_stopped(q) &&
time_after(jiffies,
(trans_start + netdev->watchdog_timeo))) {
hung_queue = i;
break;
}
}
if (i == netdev->num_tx_queues) {
netdev_info(netdev, "tx_timeout: no netdev hung queue found\n");
} else {
for (i = 0; i < vsi->num_queue_pairs; i++) {
if (vsi->tx_rings[i] && vsi->tx_rings[i]->desc) {
if (hung_queue ==
vsi->tx_rings[i]->queue_index) {
tx_ring = vsi->tx_rings[i];
break;
}
}
}
}
if (time_after(jiffies, (pf->tx_timeout_last_recovery + HZ*20)))
pf->tx_timeout_recovery_level = 1;
else if (time_before(jiffies,
(pf->tx_timeout_last_recovery + netdev->watchdog_timeo)))
return;
if (tx_ring) {
head = i40e_get_head(tx_ring);
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
val = rd32(&pf->hw,
I40E_PFINT_DYN_CTLN(tx_ring->q_vector->v_idx +
tx_ring->vsi->base_vector - 1));
else
val = rd32(&pf->hw, I40E_PFINT_DYN_CTL0);
netdev_info(netdev, "tx_timeout: VSI_seid: %d, Q %d, NTC: 0x%x, HWB: 0x%x, NTU: 0x%x, TAIL: 0x%x, INT: 0x%x\n",
vsi->seid, hung_queue, tx_ring->next_to_clean,
head, tx_ring->next_to_use,
readl(tx_ring->tail), val);
}
pf->tx_timeout_last_recovery = jiffies;
netdev_info(netdev, "tx_timeout recovery level %d, hung_queue %d\n",
pf->tx_timeout_recovery_level, hung_queue);
switch (pf->tx_timeout_recovery_level) {
case 1:
set_bit(__I40E_PF_RESET_REQUESTED, pf->state);
break;
case 2:
set_bit(__I40E_CORE_RESET_REQUESTED, pf->state);
break;
case 3:
set_bit(__I40E_GLOBAL_RESET_REQUESTED, pf->state);
break;
default:
netdev_err(netdev, "tx_timeout recovery unsuccessful\n");
break;
}
i40e_service_event_schedule(pf);
pf->tx_timeout_recovery_level++;
}
struct rtnl_link_stats64 *i40e_get_vsi_stats_struct(struct i40e_vsi *vsi)
{
return &vsi->net_stats;
}
static void i40e_get_netdev_stats_struct(struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_ring *tx_ring, *rx_ring;
struct i40e_vsi *vsi = np->vsi;
struct rtnl_link_stats64 *vsi_stats = i40e_get_vsi_stats_struct(vsi);
int i;
if (test_bit(__I40E_VSI_DOWN, vsi->state))
return;
if (!vsi->tx_rings)
return;
rcu_read_lock();
for (i = 0; i < vsi->num_queue_pairs; i++) {
u64 bytes, packets;
unsigned int start;
tx_ring = ACCESS_ONCE(vsi->tx_rings[i]);
if (!tx_ring)
continue;
do {
start = u64_stats_fetch_begin_irq(&tx_ring->syncp);
packets = tx_ring->stats.packets;
bytes = tx_ring->stats.bytes;
} while (u64_stats_fetch_retry_irq(&tx_ring->syncp, start));
stats->tx_packets += packets;
stats->tx_bytes += bytes;
rx_ring = &tx_ring[1];
do {
start = u64_stats_fetch_begin_irq(&rx_ring->syncp);
packets = rx_ring->stats.packets;
bytes = rx_ring->stats.bytes;
} while (u64_stats_fetch_retry_irq(&rx_ring->syncp, start));
stats->rx_packets += packets;
stats->rx_bytes += bytes;
}
rcu_read_unlock();
stats->multicast = vsi_stats->multicast;
stats->tx_errors = vsi_stats->tx_errors;
stats->tx_dropped = vsi_stats->tx_dropped;
stats->rx_errors = vsi_stats->rx_errors;
stats->rx_dropped = vsi_stats->rx_dropped;
stats->rx_crc_errors = vsi_stats->rx_crc_errors;
stats->rx_length_errors = vsi_stats->rx_length_errors;
}
void i40e_vsi_reset_stats(struct i40e_vsi *vsi)
{
struct rtnl_link_stats64 *ns;
int i;
if (!vsi)
return;
ns = i40e_get_vsi_stats_struct(vsi);
memset(ns, 0, sizeof(*ns));
memset(&vsi->net_stats_offsets, 0, sizeof(vsi->net_stats_offsets));
memset(&vsi->eth_stats, 0, sizeof(vsi->eth_stats));
memset(&vsi->eth_stats_offsets, 0, sizeof(vsi->eth_stats_offsets));
if (vsi->rx_rings && vsi->rx_rings[0]) {
for (i = 0; i < vsi->num_queue_pairs; i++) {
memset(&vsi->rx_rings[i]->stats, 0,
sizeof(vsi->rx_rings[i]->stats));
memset(&vsi->rx_rings[i]->rx_stats, 0,
sizeof(vsi->rx_rings[i]->rx_stats));
memset(&vsi->tx_rings[i]->stats, 0,
sizeof(vsi->tx_rings[i]->stats));
memset(&vsi->tx_rings[i]->tx_stats, 0,
sizeof(vsi->tx_rings[i]->tx_stats));
}
}
vsi->stat_offsets_loaded = false;
}
void i40e_pf_reset_stats(struct i40e_pf *pf)
{
int i;
memset(&pf->stats, 0, sizeof(pf->stats));
memset(&pf->stats_offsets, 0, sizeof(pf->stats_offsets));
pf->stat_offsets_loaded = false;
for (i = 0; i < I40E_MAX_VEB; i++) {
if (pf->veb[i]) {
memset(&pf->veb[i]->stats, 0,
sizeof(pf->veb[i]->stats));
memset(&pf->veb[i]->stats_offsets, 0,
sizeof(pf->veb[i]->stats_offsets));
pf->veb[i]->stat_offsets_loaded = false;
}
}
pf->hw_csum_rx_error = 0;
}
static void i40e_stat_update48(struct i40e_hw *hw, u32 hireg, u32 loreg,
bool offset_loaded, u64 *offset, u64 *stat)
{
u64 new_data;
if (hw->device_id == I40E_DEV_ID_QEMU) {
new_data = rd32(hw, loreg);
new_data |= ((u64)(rd32(hw, hireg) & 0xFFFF)) << 32;
} else {
new_data = rd64(hw, loreg);
}
if (!offset_loaded)
*offset = new_data;
if (likely(new_data >= *offset))
*stat = new_data - *offset;
else
*stat = (new_data + BIT_ULL(48)) - *offset;
*stat &= 0xFFFFFFFFFFFFULL;
}
static void i40e_stat_update32(struct i40e_hw *hw, u32 reg,
bool offset_loaded, u64 *offset, u64 *stat)
{
u32 new_data;
new_data = rd32(hw, reg);
if (!offset_loaded)
*offset = new_data;
if (likely(new_data >= *offset))
*stat = (u32)(new_data - *offset);
else
*stat = (u32)((new_data + BIT_ULL(32)) - *offset);
}
void i40e_update_eth_stats(struct i40e_vsi *vsi)
{
int stat_idx = le16_to_cpu(vsi->info.stat_counter_idx);
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
struct i40e_eth_stats *oes;
struct i40e_eth_stats *es;
es = &vsi->eth_stats;
oes = &vsi->eth_stats_offsets;
i40e_stat_update32(hw, I40E_GLV_TEPC(stat_idx),
vsi->stat_offsets_loaded,
&oes->tx_errors, &es->tx_errors);
i40e_stat_update32(hw, I40E_GLV_RDPC(stat_idx),
vsi->stat_offsets_loaded,
&oes->rx_discards, &es->rx_discards);
i40e_stat_update32(hw, I40E_GLV_RUPP(stat_idx),
vsi->stat_offsets_loaded,
&oes->rx_unknown_protocol, &es->rx_unknown_protocol);
i40e_stat_update32(hw, I40E_GLV_TEPC(stat_idx),
vsi->stat_offsets_loaded,
&oes->tx_errors, &es->tx_errors);
i40e_stat_update48(hw, I40E_GLV_GORCH(stat_idx),
I40E_GLV_GORCL(stat_idx),
vsi->stat_offsets_loaded,
&oes->rx_bytes, &es->rx_bytes);
i40e_stat_update48(hw, I40E_GLV_UPRCH(stat_idx),
I40E_GLV_UPRCL(stat_idx),
vsi->stat_offsets_loaded,
&oes->rx_unicast, &es->rx_unicast);
i40e_stat_update48(hw, I40E_GLV_MPRCH(stat_idx),
I40E_GLV_MPRCL(stat_idx),
vsi->stat_offsets_loaded,
&oes->rx_multicast, &es->rx_multicast);
i40e_stat_update48(hw, I40E_GLV_BPRCH(stat_idx),
I40E_GLV_BPRCL(stat_idx),
vsi->stat_offsets_loaded,
&oes->rx_broadcast, &es->rx_broadcast);
i40e_stat_update48(hw, I40E_GLV_GOTCH(stat_idx),
I40E_GLV_GOTCL(stat_idx),
vsi->stat_offsets_loaded,
&oes->tx_bytes, &es->tx_bytes);
i40e_stat_update48(hw, I40E_GLV_UPTCH(stat_idx),
I40E_GLV_UPTCL(stat_idx),
vsi->stat_offsets_loaded,
&oes->tx_unicast, &es->tx_unicast);
i40e_stat_update48(hw, I40E_GLV_MPTCH(stat_idx),
I40E_GLV_MPTCL(stat_idx),
vsi->stat_offsets_loaded,
&oes->tx_multicast, &es->tx_multicast);
i40e_stat_update48(hw, I40E_GLV_BPTCH(stat_idx),
I40E_GLV_BPTCL(stat_idx),
vsi->stat_offsets_loaded,
&oes->tx_broadcast, &es->tx_broadcast);
vsi->stat_offsets_loaded = true;
}
static void i40e_update_veb_stats(struct i40e_veb *veb)
{
struct i40e_pf *pf = veb->pf;
struct i40e_hw *hw = &pf->hw;
struct i40e_eth_stats *oes;
struct i40e_eth_stats *es;
struct i40e_veb_tc_stats *veb_oes;
struct i40e_veb_tc_stats *veb_es;
int i, idx = 0;
idx = veb->stats_idx;
es = &veb->stats;
oes = &veb->stats_offsets;
veb_es = &veb->tc_stats;
veb_oes = &veb->tc_stats_offsets;
i40e_stat_update32(hw, I40E_GLSW_TDPC(idx),
veb->stat_offsets_loaded,
&oes->tx_discards, &es->tx_discards);
if (hw->revision_id > 0)
i40e_stat_update32(hw, I40E_GLSW_RUPP(idx),
veb->stat_offsets_loaded,
&oes->rx_unknown_protocol,
&es->rx_unknown_protocol);
i40e_stat_update48(hw, I40E_GLSW_GORCH(idx), I40E_GLSW_GORCL(idx),
veb->stat_offsets_loaded,
&oes->rx_bytes, &es->rx_bytes);
i40e_stat_update48(hw, I40E_GLSW_UPRCH(idx), I40E_GLSW_UPRCL(idx),
veb->stat_offsets_loaded,
&oes->rx_unicast, &es->rx_unicast);
i40e_stat_update48(hw, I40E_GLSW_MPRCH(idx), I40E_GLSW_MPRCL(idx),
veb->stat_offsets_loaded,
&oes->rx_multicast, &es->rx_multicast);
i40e_stat_update48(hw, I40E_GLSW_BPRCH(idx), I40E_GLSW_BPRCL(idx),
veb->stat_offsets_loaded,
&oes->rx_broadcast, &es->rx_broadcast);
i40e_stat_update48(hw, I40E_GLSW_GOTCH(idx), I40E_GLSW_GOTCL(idx),
veb->stat_offsets_loaded,
&oes->tx_bytes, &es->tx_bytes);
i40e_stat_update48(hw, I40E_GLSW_UPTCH(idx), I40E_GLSW_UPTCL(idx),
veb->stat_offsets_loaded,
&oes->tx_unicast, &es->tx_unicast);
i40e_stat_update48(hw, I40E_GLSW_MPTCH(idx), I40E_GLSW_MPTCL(idx),
veb->stat_offsets_loaded,
&oes->tx_multicast, &es->tx_multicast);
i40e_stat_update48(hw, I40E_GLSW_BPTCH(idx), I40E_GLSW_BPTCL(idx),
veb->stat_offsets_loaded,
&oes->tx_broadcast, &es->tx_broadcast);
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
i40e_stat_update48(hw, I40E_GLVEBTC_RPCH(i, idx),
I40E_GLVEBTC_RPCL(i, idx),
veb->stat_offsets_loaded,
&veb_oes->tc_rx_packets[i],
&veb_es->tc_rx_packets[i]);
i40e_stat_update48(hw, I40E_GLVEBTC_RBCH(i, idx),
I40E_GLVEBTC_RBCL(i, idx),
veb->stat_offsets_loaded,
&veb_oes->tc_rx_bytes[i],
&veb_es->tc_rx_bytes[i]);
i40e_stat_update48(hw, I40E_GLVEBTC_TPCH(i, idx),
I40E_GLVEBTC_TPCL(i, idx),
veb->stat_offsets_loaded,
&veb_oes->tc_tx_packets[i],
&veb_es->tc_tx_packets[i]);
i40e_stat_update48(hw, I40E_GLVEBTC_TBCH(i, idx),
I40E_GLVEBTC_TBCL(i, idx),
veb->stat_offsets_loaded,
&veb_oes->tc_tx_bytes[i],
&veb_es->tc_tx_bytes[i]);
}
veb->stat_offsets_loaded = true;
}
static void i40e_update_vsi_stats(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
struct rtnl_link_stats64 *ons;
struct rtnl_link_stats64 *ns;
struct i40e_eth_stats *oes;
struct i40e_eth_stats *es;
u32 tx_restart, tx_busy;
struct i40e_ring *p;
u32 rx_page, rx_buf;
u64 bytes, packets;
unsigned int start;
u64 tx_linearize;
u64 tx_force_wb;
u64 rx_p, rx_b;
u64 tx_p, tx_b;
u16 q;
if (test_bit(__I40E_VSI_DOWN, vsi->state) ||
test_bit(__I40E_CONFIG_BUSY, pf->state))
return;
ns = i40e_get_vsi_stats_struct(vsi);
ons = &vsi->net_stats_offsets;
es = &vsi->eth_stats;
oes = &vsi->eth_stats_offsets;
rx_b = rx_p = 0;
tx_b = tx_p = 0;
tx_restart = tx_busy = tx_linearize = tx_force_wb = 0;
rx_page = 0;
rx_buf = 0;
rcu_read_lock();
for (q = 0; q < vsi->num_queue_pairs; q++) {
p = ACCESS_ONCE(vsi->tx_rings[q]);
do {
start = u64_stats_fetch_begin_irq(&p->syncp);
packets = p->stats.packets;
bytes = p->stats.bytes;
} while (u64_stats_fetch_retry_irq(&p->syncp, start));
tx_b += bytes;
tx_p += packets;
tx_restart += p->tx_stats.restart_queue;
tx_busy += p->tx_stats.tx_busy;
tx_linearize += p->tx_stats.tx_linearize;
tx_force_wb += p->tx_stats.tx_force_wb;
p = &p[1];
do {
start = u64_stats_fetch_begin_irq(&p->syncp);
packets = p->stats.packets;
bytes = p->stats.bytes;
} while (u64_stats_fetch_retry_irq(&p->syncp, start));
rx_b += bytes;
rx_p += packets;
rx_buf += p->rx_stats.alloc_buff_failed;
rx_page += p->rx_stats.alloc_page_failed;
}
rcu_read_unlock();
vsi->tx_restart = tx_restart;
vsi->tx_busy = tx_busy;
vsi->tx_linearize = tx_linearize;
vsi->tx_force_wb = tx_force_wb;
vsi->rx_page_failed = rx_page;
vsi->rx_buf_failed = rx_buf;
ns->rx_packets = rx_p;
ns->rx_bytes = rx_b;
ns->tx_packets = tx_p;
ns->tx_bytes = tx_b;
i40e_update_eth_stats(vsi);
ons->tx_errors = oes->tx_errors;
ns->tx_errors = es->tx_errors;
ons->multicast = oes->rx_multicast;
ns->multicast = es->rx_multicast;
ons->rx_dropped = oes->rx_discards;
ns->rx_dropped = es->rx_discards;
ons->tx_dropped = oes->tx_discards;
ns->tx_dropped = es->tx_discards;
if (vsi == pf->vsi[pf->lan_vsi]) {
ns->rx_crc_errors = pf->stats.crc_errors;
ns->rx_errors = pf->stats.crc_errors + pf->stats.illegal_bytes;
ns->rx_length_errors = pf->stats.rx_length_errors;
}
}
static void i40e_update_pf_stats(struct i40e_pf *pf)
{
struct i40e_hw_port_stats *osd = &pf->stats_offsets;
struct i40e_hw_port_stats *nsd = &pf->stats;
struct i40e_hw *hw = &pf->hw;
u32 val;
int i;
i40e_stat_update48(hw, I40E_GLPRT_GORCH(hw->port),
I40E_GLPRT_GORCL(hw->port),
pf->stat_offsets_loaded,
&osd->eth.rx_bytes, &nsd->eth.rx_bytes);
i40e_stat_update48(hw, I40E_GLPRT_GOTCH(hw->port),
I40E_GLPRT_GOTCL(hw->port),
pf->stat_offsets_loaded,
&osd->eth.tx_bytes, &nsd->eth.tx_bytes);
i40e_stat_update32(hw, I40E_GLPRT_RDPC(hw->port),
pf->stat_offsets_loaded,
&osd->eth.rx_discards,
&nsd->eth.rx_discards);
i40e_stat_update48(hw, I40E_GLPRT_UPRCH(hw->port),
I40E_GLPRT_UPRCL(hw->port),
pf->stat_offsets_loaded,
&osd->eth.rx_unicast,
&nsd->eth.rx_unicast);
i40e_stat_update48(hw, I40E_GLPRT_MPRCH(hw->port),
I40E_GLPRT_MPRCL(hw->port),
pf->stat_offsets_loaded,
&osd->eth.rx_multicast,
&nsd->eth.rx_multicast);
i40e_stat_update48(hw, I40E_GLPRT_BPRCH(hw->port),
I40E_GLPRT_BPRCL(hw->port),
pf->stat_offsets_loaded,
&osd->eth.rx_broadcast,
&nsd->eth.rx_broadcast);
i40e_stat_update48(hw, I40E_GLPRT_UPTCH(hw->port),
I40E_GLPRT_UPTCL(hw->port),
pf->stat_offsets_loaded,
&osd->eth.tx_unicast,
&nsd->eth.tx_unicast);
i40e_stat_update48(hw, I40E_GLPRT_MPTCH(hw->port),
I40E_GLPRT_MPTCL(hw->port),
pf->stat_offsets_loaded,
&osd->eth.tx_multicast,
&nsd->eth.tx_multicast);
i40e_stat_update48(hw, I40E_GLPRT_BPTCH(hw->port),
I40E_GLPRT_BPTCL(hw->port),
pf->stat_offsets_loaded,
&osd->eth.tx_broadcast,
&nsd->eth.tx_broadcast);
i40e_stat_update32(hw, I40E_GLPRT_TDOLD(hw->port),
pf->stat_offsets_loaded,
&osd->tx_dropped_link_down,
&nsd->tx_dropped_link_down);
i40e_stat_update32(hw, I40E_GLPRT_CRCERRS(hw->port),
pf->stat_offsets_loaded,
&osd->crc_errors, &nsd->crc_errors);
i40e_stat_update32(hw, I40E_GLPRT_ILLERRC(hw->port),
pf->stat_offsets_loaded,
&osd->illegal_bytes, &nsd->illegal_bytes);
i40e_stat_update32(hw, I40E_GLPRT_MLFC(hw->port),
pf->stat_offsets_loaded,
&osd->mac_local_faults,
&nsd->mac_local_faults);
i40e_stat_update32(hw, I40E_GLPRT_MRFC(hw->port),
pf->stat_offsets_loaded,
&osd->mac_remote_faults,
&nsd->mac_remote_faults);
i40e_stat_update32(hw, I40E_GLPRT_RLEC(hw->port),
pf->stat_offsets_loaded,
&osd->rx_length_errors,
&nsd->rx_length_errors);
i40e_stat_update32(hw, I40E_GLPRT_LXONRXC(hw->port),
pf->stat_offsets_loaded,
&osd->link_xon_rx, &nsd->link_xon_rx);
i40e_stat_update32(hw, I40E_GLPRT_LXONTXC(hw->port),
pf->stat_offsets_loaded,
&osd->link_xon_tx, &nsd->link_xon_tx);
i40e_stat_update32(hw, I40E_GLPRT_LXOFFRXC(hw->port),
pf->stat_offsets_loaded,
&osd->link_xoff_rx, &nsd->link_xoff_rx);
i40e_stat_update32(hw, I40E_GLPRT_LXOFFTXC(hw->port),
pf->stat_offsets_loaded,
&osd->link_xoff_tx, &nsd->link_xoff_tx);
for (i = 0; i < 8; i++) {
i40e_stat_update32(hw, I40E_GLPRT_PXOFFRXC(hw->port, i),
pf->stat_offsets_loaded,
&osd->priority_xoff_rx[i],
&nsd->priority_xoff_rx[i]);
i40e_stat_update32(hw, I40E_GLPRT_PXONRXC(hw->port, i),
pf->stat_offsets_loaded,
&osd->priority_xon_rx[i],
&nsd->priority_xon_rx[i]);
i40e_stat_update32(hw, I40E_GLPRT_PXONTXC(hw->port, i),
pf->stat_offsets_loaded,
&osd->priority_xon_tx[i],
&nsd->priority_xon_tx[i]);
i40e_stat_update32(hw, I40E_GLPRT_PXOFFTXC(hw->port, i),
pf->stat_offsets_loaded,
&osd->priority_xoff_tx[i],
&nsd->priority_xoff_tx[i]);
i40e_stat_update32(hw,
I40E_GLPRT_RXON2OFFCNT(hw->port, i),
pf->stat_offsets_loaded,
&osd->priority_xon_2_xoff[i],
&nsd->priority_xon_2_xoff[i]);
}
i40e_stat_update48(hw, I40E_GLPRT_PRC64H(hw->port),
I40E_GLPRT_PRC64L(hw->port),
pf->stat_offsets_loaded,
&osd->rx_size_64, &nsd->rx_size_64);
i40e_stat_update48(hw, I40E_GLPRT_PRC127H(hw->port),
I40E_GLPRT_PRC127L(hw->port),
pf->stat_offsets_loaded,
&osd->rx_size_127, &nsd->rx_size_127);
i40e_stat_update48(hw, I40E_GLPRT_PRC255H(hw->port),
I40E_GLPRT_PRC255L(hw->port),
pf->stat_offsets_loaded,
&osd->rx_size_255, &nsd->rx_size_255);
i40e_stat_update48(hw, I40E_GLPRT_PRC511H(hw->port),
I40E_GLPRT_PRC511L(hw->port),
pf->stat_offsets_loaded,
&osd->rx_size_511, &nsd->rx_size_511);
i40e_stat_update48(hw, I40E_GLPRT_PRC1023H(hw->port),
I40E_GLPRT_PRC1023L(hw->port),
pf->stat_offsets_loaded,
&osd->rx_size_1023, &nsd->rx_size_1023);
i40e_stat_update48(hw, I40E_GLPRT_PRC1522H(hw->port),
I40E_GLPRT_PRC1522L(hw->port),
pf->stat_offsets_loaded,
&osd->rx_size_1522, &nsd->rx_size_1522);
i40e_stat_update48(hw, I40E_GLPRT_PRC9522H(hw->port),
I40E_GLPRT_PRC9522L(hw->port),
pf->stat_offsets_loaded,
&osd->rx_size_big, &nsd->rx_size_big);
i40e_stat_update48(hw, I40E_GLPRT_PTC64H(hw->port),
I40E_GLPRT_PTC64L(hw->port),
pf->stat_offsets_loaded,
&osd->tx_size_64, &nsd->tx_size_64);
i40e_stat_update48(hw, I40E_GLPRT_PTC127H(hw->port),
I40E_GLPRT_PTC127L(hw->port),
pf->stat_offsets_loaded,
&osd->tx_size_127, &nsd->tx_size_127);
i40e_stat_update48(hw, I40E_GLPRT_PTC255H(hw->port),
I40E_GLPRT_PTC255L(hw->port),
pf->stat_offsets_loaded,
&osd->tx_size_255, &nsd->tx_size_255);
i40e_stat_update48(hw, I40E_GLPRT_PTC511H(hw->port),
I40E_GLPRT_PTC511L(hw->port),
pf->stat_offsets_loaded,
&osd->tx_size_511, &nsd->tx_size_511);
i40e_stat_update48(hw, I40E_GLPRT_PTC1023H(hw->port),
I40E_GLPRT_PTC1023L(hw->port),
pf->stat_offsets_loaded,
&osd->tx_size_1023, &nsd->tx_size_1023);
i40e_stat_update48(hw, I40E_GLPRT_PTC1522H(hw->port),
I40E_GLPRT_PTC1522L(hw->port),
pf->stat_offsets_loaded,
&osd->tx_size_1522, &nsd->tx_size_1522);
i40e_stat_update48(hw, I40E_GLPRT_PTC9522H(hw->port),
I40E_GLPRT_PTC9522L(hw->port),
pf->stat_offsets_loaded,
&osd->tx_size_big, &nsd->tx_size_big);
i40e_stat_update32(hw, I40E_GLPRT_RUC(hw->port),
pf->stat_offsets_loaded,
&osd->rx_undersize, &nsd->rx_undersize);
i40e_stat_update32(hw, I40E_GLPRT_RFC(hw->port),
pf->stat_offsets_loaded,
&osd->rx_fragments, &nsd->rx_fragments);
i40e_stat_update32(hw, I40E_GLPRT_ROC(hw->port),
pf->stat_offsets_loaded,
&osd->rx_oversize, &nsd->rx_oversize);
i40e_stat_update32(hw, I40E_GLPRT_RJC(hw->port),
pf->stat_offsets_loaded,
&osd->rx_jabber, &nsd->rx_jabber);
i40e_stat_update32(hw,
I40E_GLQF_PCNT(I40E_FD_ATR_STAT_IDX(pf->hw.pf_id)),
pf->stat_offsets_loaded,
&osd->fd_atr_match, &nsd->fd_atr_match);
i40e_stat_update32(hw,
I40E_GLQF_PCNT(I40E_FD_SB_STAT_IDX(pf->hw.pf_id)),
pf->stat_offsets_loaded,
&osd->fd_sb_match, &nsd->fd_sb_match);
i40e_stat_update32(hw,
I40E_GLQF_PCNT(I40E_FD_ATR_TUNNEL_STAT_IDX(pf->hw.pf_id)),
pf->stat_offsets_loaded,
&osd->fd_atr_tunnel_match, &nsd->fd_atr_tunnel_match);
val = rd32(hw, I40E_PRTPM_EEE_STAT);
nsd->tx_lpi_status =
(val & I40E_PRTPM_EEE_STAT_TX_LPI_STATUS_MASK) >>
I40E_PRTPM_EEE_STAT_TX_LPI_STATUS_SHIFT;
nsd->rx_lpi_status =
(val & I40E_PRTPM_EEE_STAT_RX_LPI_STATUS_MASK) >>
I40E_PRTPM_EEE_STAT_RX_LPI_STATUS_SHIFT;
i40e_stat_update32(hw, I40E_PRTPM_TLPIC,
pf->stat_offsets_loaded,
&osd->tx_lpi_count, &nsd->tx_lpi_count);
i40e_stat_update32(hw, I40E_PRTPM_RLPIC,
pf->stat_offsets_loaded,
&osd->rx_lpi_count, &nsd->rx_lpi_count);
if (pf->flags & I40E_FLAG_FD_SB_ENABLED &&
!(pf->flags & I40E_FLAG_FD_SB_AUTO_DISABLED))
nsd->fd_sb_status = true;
else
nsd->fd_sb_status = false;
if (pf->flags & I40E_FLAG_FD_ATR_ENABLED &&
!(pf->flags & I40E_FLAG_FD_ATR_AUTO_DISABLED))
nsd->fd_atr_status = true;
else
nsd->fd_atr_status = false;
pf->stat_offsets_loaded = true;
}
void i40e_update_stats(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
if (vsi == pf->vsi[pf->lan_vsi])
i40e_update_pf_stats(pf);
i40e_update_vsi_stats(vsi);
}
static struct i40e_mac_filter *i40e_find_filter(struct i40e_vsi *vsi,
const u8 *macaddr, s16 vlan)
{
struct i40e_mac_filter *f;
u64 key;
if (!vsi || !macaddr)
return NULL;
key = i40e_addr_to_hkey(macaddr);
hash_for_each_possible(vsi->mac_filter_hash, f, hlist, key) {
if ((ether_addr_equal(macaddr, f->macaddr)) &&
(vlan == f->vlan))
return f;
}
return NULL;
}
struct i40e_mac_filter *i40e_find_mac(struct i40e_vsi *vsi, const u8 *macaddr)
{
struct i40e_mac_filter *f;
u64 key;
if (!vsi || !macaddr)
return NULL;
key = i40e_addr_to_hkey(macaddr);
hash_for_each_possible(vsi->mac_filter_hash, f, hlist, key) {
if ((ether_addr_equal(macaddr, f->macaddr)))
return f;
}
return NULL;
}
bool i40e_is_vsi_in_vlan(struct i40e_vsi *vsi)
{
if (vsi->info.pvid)
return true;
return vsi->has_vlan_filter;
}
static int i40e_correct_mac_vlan_filters(struct i40e_vsi *vsi,
struct hlist_head *tmp_add_list,
struct hlist_head *tmp_del_list,
int vlan_filters)
{
s16 pvid = le16_to_cpu(vsi->info.pvid);
struct i40e_mac_filter *f, *add_head;
struct i40e_new_mac_filter *new;
struct hlist_node *h;
int bkt, new_vlan;
hlist_for_each_entry(new, tmp_add_list, hlist) {
if (pvid && new->f->vlan != pvid)
new->f->vlan = pvid;
else if (vlan_filters && new->f->vlan == I40E_VLAN_ANY)
new->f->vlan = 0;
else if (!vlan_filters && new->f->vlan == 0)
new->f->vlan = I40E_VLAN_ANY;
}
hash_for_each_safe(vsi->mac_filter_hash, bkt, h, f, hlist) {
if ((pvid && f->vlan != pvid) ||
(vlan_filters && f->vlan == I40E_VLAN_ANY) ||
(!vlan_filters && f->vlan == 0)) {
if (pvid)
new_vlan = pvid;
else if (vlan_filters)
new_vlan = 0;
else
new_vlan = I40E_VLAN_ANY;
add_head = i40e_add_filter(vsi, f->macaddr, new_vlan);
if (!add_head)
return -ENOMEM;
new = kzalloc(sizeof(*new), GFP_ATOMIC);
if (!new)
return -ENOMEM;
new->f = add_head;
new->state = add_head->state;
hlist_add_head(&new->hlist, tmp_add_list);
f->state = I40E_FILTER_REMOVE;
hash_del(&f->hlist);
hlist_add_head(&f->hlist, tmp_del_list);
}
}
vsi->has_vlan_filter = !!vlan_filters;
return 0;
}
static void i40e_rm_default_mac_filter(struct i40e_vsi *vsi, u8 *macaddr)
{
struct i40e_aqc_remove_macvlan_element_data element;
struct i40e_pf *pf = vsi->back;
if (vsi->type != I40E_VSI_MAIN)
return;
memset(&element, 0, sizeof(element));
ether_addr_copy(element.mac_addr, macaddr);
element.vlan_tag = 0;
element.flags = I40E_AQC_MACVLAN_DEL_PERFECT_MATCH;
i40e_aq_remove_macvlan(&pf->hw, vsi->seid, &element, 1, NULL);
memset(&element, 0, sizeof(element));
ether_addr_copy(element.mac_addr, macaddr);
element.vlan_tag = 0;
element.flags = I40E_AQC_MACVLAN_DEL_PERFECT_MATCH |
I40E_AQC_MACVLAN_DEL_IGNORE_VLAN;
i40e_aq_remove_macvlan(&pf->hw, vsi->seid, &element, 1, NULL);
}
struct i40e_mac_filter *i40e_add_filter(struct i40e_vsi *vsi,
const u8 *macaddr, s16 vlan)
{
struct i40e_mac_filter *f;
u64 key;
if (!vsi || !macaddr)
return NULL;
f = i40e_find_filter(vsi, macaddr, vlan);
if (!f) {
f = kzalloc(sizeof(*f), GFP_ATOMIC);
if (!f)
return NULL;
if (vlan >= 0)
vsi->has_vlan_filter = true;
ether_addr_copy(f->macaddr, macaddr);
f->vlan = vlan;
if (test_bit(__I40E_VSI_OVERFLOW_PROMISC, vsi->state))
f->state = I40E_FILTER_FAILED;
else
f->state = I40E_FILTER_NEW;
INIT_HLIST_NODE(&f->hlist);
key = i40e_addr_to_hkey(macaddr);
hash_add(vsi->mac_filter_hash, &f->hlist, key);
vsi->flags |= I40E_VSI_FLAG_FILTER_CHANGED;
vsi->back->flags |= I40E_FLAG_FILTER_SYNC;
}
if (f->state == I40E_FILTER_REMOVE)
f->state = I40E_FILTER_ACTIVE;
return f;
}
void __i40e_del_filter(struct i40e_vsi *vsi, struct i40e_mac_filter *f)
{
if (!f)
return;
if ((f->state == I40E_FILTER_FAILED) ||
(f->state == I40E_FILTER_NEW)) {
hash_del(&f->hlist);
kfree(f);
} else {
f->state = I40E_FILTER_REMOVE;
}
vsi->flags |= I40E_VSI_FLAG_FILTER_CHANGED;
vsi->back->flags |= I40E_FLAG_FILTER_SYNC;
}
void i40e_del_filter(struct i40e_vsi *vsi, const u8 *macaddr, s16 vlan)
{
struct i40e_mac_filter *f;
if (!vsi || !macaddr)
return;
f = i40e_find_filter(vsi, macaddr, vlan);
__i40e_del_filter(vsi, f);
}
struct i40e_mac_filter *i40e_add_mac_filter(struct i40e_vsi *vsi,
const u8 *macaddr)
{
struct i40e_mac_filter *f, *add = NULL;
struct hlist_node *h;
int bkt;
if (vsi->info.pvid)
return i40e_add_filter(vsi, macaddr,
le16_to_cpu(vsi->info.pvid));
if (!i40e_is_vsi_in_vlan(vsi))
return i40e_add_filter(vsi, macaddr, I40E_VLAN_ANY);
hash_for_each_safe(vsi->mac_filter_hash, bkt, h, f, hlist) {
if (f->state == I40E_FILTER_REMOVE)
continue;
add = i40e_add_filter(vsi, macaddr, f->vlan);
if (!add)
return NULL;
}
return add;
}
int i40e_del_mac_filter(struct i40e_vsi *vsi, const u8 *macaddr)
{
struct i40e_mac_filter *f;
struct hlist_node *h;
bool found = false;
int bkt;
WARN(!spin_is_locked(&vsi->mac_filter_hash_lock),
"Missing mac_filter_hash_lock\n");
hash_for_each_safe(vsi->mac_filter_hash, bkt, h, f, hlist) {
if (ether_addr_equal(macaddr, f->macaddr)) {
__i40e_del_filter(vsi, f);
found = true;
}
}
if (found)
return 0;
else
return -ENOENT;
}
static int i40e_set_mac(struct net_device *netdev, void *p)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
if (ether_addr_equal(netdev->dev_addr, addr->sa_data)) {
netdev_info(netdev, "already using mac address %pM\n",
addr->sa_data);
return 0;
}
if (test_bit(__I40E_VSI_DOWN, vsi->back->state) ||
test_bit(__I40E_RESET_RECOVERY_PENDING, vsi->back->state))
return -EADDRNOTAVAIL;
if (ether_addr_equal(hw->mac.addr, addr->sa_data))
netdev_info(netdev, "returning to hw mac address %pM\n",
hw->mac.addr);
else
netdev_info(netdev, "set new mac address %pM\n", addr->sa_data);
spin_lock_bh(&vsi->mac_filter_hash_lock);
i40e_del_mac_filter(vsi, netdev->dev_addr);
i40e_add_mac_filter(vsi, addr->sa_data);
spin_unlock_bh(&vsi->mac_filter_hash_lock);
ether_addr_copy(netdev->dev_addr, addr->sa_data);
if (vsi->type == I40E_VSI_MAIN) {
i40e_status ret;
ret = i40e_aq_mac_address_write(&vsi->back->hw,
I40E_AQC_WRITE_TYPE_LAA_WOL,
addr->sa_data, NULL);
if (ret)
netdev_info(netdev, "Ignoring error from firmware on LAA update, status %s, AQ ret %s\n",
i40e_stat_str(hw, ret),
i40e_aq_str(hw, hw->aq.asq_last_status));
}
i40e_service_event_schedule(vsi->back);
return 0;
}
static void i40e_vsi_setup_queue_map(struct i40e_vsi *vsi,
struct i40e_vsi_context *ctxt,
u8 enabled_tc,
bool is_add)
{
struct i40e_pf *pf = vsi->back;
u16 sections = 0;
u8 netdev_tc = 0;
u16 numtc = 0;
u16 qcount;
u8 offset;
u16 qmap;
int i;
u16 num_tc_qps = 0;
sections = I40E_AQ_VSI_PROP_QUEUE_MAP_VALID;
offset = 0;
if (enabled_tc && (vsi->back->flags & I40E_FLAG_DCB_ENABLED)) {
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (enabled_tc & BIT(i))
numtc++;
}
if (!numtc) {
dev_warn(&pf->pdev->dev, "DCB is enabled but no TC enabled, forcing TC0\n");
numtc = 1;
}
} else {
numtc = 1;
}
vsi->tc_config.numtc = numtc;
vsi->tc_config.enabled_tc = enabled_tc ? enabled_tc : 1;
qcount = vsi->alloc_queue_pairs;
num_tc_qps = qcount / numtc;
num_tc_qps = min_t(int, num_tc_qps, i40e_pf_get_max_q_per_tc(pf));
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (vsi->tc_config.enabled_tc & BIT(i)) {
int pow, num_qps;
switch (vsi->type) {
case I40E_VSI_MAIN:
qcount = min_t(int, pf->alloc_rss_size,
num_tc_qps);
break;
case I40E_VSI_FDIR:
case I40E_VSI_SRIOV:
case I40E_VSI_VMDQ2:
default:
qcount = num_tc_qps;
WARN_ON(i != 0);
break;
}
vsi->tc_config.tc_info[i].qoffset = offset;
vsi->tc_config.tc_info[i].qcount = qcount;
num_qps = qcount;
pow = 0;
while (num_qps && (BIT_ULL(pow) < qcount)) {
pow++;
num_qps >>= 1;
}
vsi->tc_config.tc_info[i].netdev_tc = netdev_tc++;
qmap =
(offset << I40E_AQ_VSI_TC_QUE_OFFSET_SHIFT) |
(pow << I40E_AQ_VSI_TC_QUE_NUMBER_SHIFT);
offset += qcount;
} else {
vsi->tc_config.tc_info[i].qoffset = 0;
vsi->tc_config.tc_info[i].qcount = 1;
vsi->tc_config.tc_info[i].netdev_tc = 0;
qmap = 0;
}
ctxt->info.tc_mapping[i] = cpu_to_le16(qmap);
}
vsi->num_queue_pairs = offset;
if ((vsi->type == I40E_VSI_MAIN) && (numtc == 1)) {
if (vsi->req_queue_pairs > 0)
vsi->num_queue_pairs = vsi->req_queue_pairs;
else if (pf->flags & I40E_FLAG_MSIX_ENABLED)
vsi->num_queue_pairs = pf->num_lan_msix;
}
if (is_add) {
sections |= I40E_AQ_VSI_PROP_SCHED_VALID;
ctxt->info.up_enable_bits = enabled_tc;
}
if (vsi->type == I40E_VSI_SRIOV) {
ctxt->info.mapping_flags |=
cpu_to_le16(I40E_AQ_VSI_QUE_MAP_NONCONTIG);
for (i = 0; i < vsi->num_queue_pairs; i++)
ctxt->info.queue_mapping[i] =
cpu_to_le16(vsi->base_queue + i);
} else {
ctxt->info.mapping_flags |=
cpu_to_le16(I40E_AQ_VSI_QUE_MAP_CONTIG);
ctxt->info.queue_mapping[0] = cpu_to_le16(vsi->base_queue);
}
ctxt->info.valid_sections |= cpu_to_le16(sections);
}
static int i40e_addr_sync(struct net_device *netdev, const u8 *addr)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
if (i40e_add_mac_filter(vsi, addr))
return 0;
else
return -ENOMEM;
}
static int i40e_addr_unsync(struct net_device *netdev, const u8 *addr)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
i40e_del_mac_filter(vsi, addr);
return 0;
}
static void i40e_set_rx_mode(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
spin_lock_bh(&vsi->mac_filter_hash_lock);
__dev_uc_sync(netdev, i40e_addr_sync, i40e_addr_unsync);
__dev_mc_sync(netdev, i40e_addr_sync, i40e_addr_unsync);
spin_unlock_bh(&vsi->mac_filter_hash_lock);
if (vsi->current_netdev_flags != vsi->netdev->flags) {
vsi->flags |= I40E_VSI_FLAG_FILTER_CHANGED;
vsi->back->flags |= I40E_FLAG_FILTER_SYNC;
}
i40e_service_event_schedule(vsi->back);
}
static void i40e_undo_del_filter_entries(struct i40e_vsi *vsi,
struct hlist_head *from)
{
struct i40e_mac_filter *f;
struct hlist_node *h;
hlist_for_each_entry_safe(f, h, from, hlist) {
u64 key = i40e_addr_to_hkey(f->macaddr);
hlist_del(&f->hlist);
hash_add(vsi->mac_filter_hash, &f->hlist, key);
}
}
static void i40e_undo_add_filter_entries(struct i40e_vsi *vsi,
struct hlist_head *from)
{
struct i40e_new_mac_filter *new;
struct hlist_node *h;
hlist_for_each_entry_safe(new, h, from, hlist) {
hlist_del(&new->hlist);
kfree(new);
}
}
static
struct i40e_new_mac_filter *i40e_next_filter(struct i40e_new_mac_filter *next)
{
hlist_for_each_entry_continue(next, hlist) {
if (!is_broadcast_ether_addr(next->f->macaddr))
return next;
}
return NULL;
}
static int
i40e_update_filter_state(int count,
struct i40e_aqc_add_macvlan_element_data *add_list,
struct i40e_new_mac_filter *add_head)
{
int retval = 0;
int i;
for (i = 0; i < count; i++) {
if (add_list[i].match_method == I40E_AQC_MM_ERR_NO_RES) {
add_head->state = I40E_FILTER_FAILED;
} else {
add_head->state = I40E_FILTER_ACTIVE;
retval++;
}
add_head = i40e_next_filter(add_head);
if (!add_head)
break;
}
return retval;
}
static
void i40e_aqc_del_filters(struct i40e_vsi *vsi, const char *vsi_name,
struct i40e_aqc_remove_macvlan_element_data *list,
int num_del, int *retval)
{
struct i40e_hw *hw = &vsi->back->hw;
i40e_status aq_ret;
int aq_err;
aq_ret = i40e_aq_remove_macvlan(hw, vsi->seid, list, num_del, NULL);
aq_err = hw->aq.asq_last_status;
if (aq_ret && !(aq_err == I40E_AQ_RC_ENOENT)) {
*retval = -EIO;
dev_info(&vsi->back->pdev->dev,
"ignoring delete macvlan error on %s, err %s, aq_err %s\n",
vsi_name, i40e_stat_str(hw, aq_ret),
i40e_aq_str(hw, aq_err));
}
}
static
void i40e_aqc_add_filters(struct i40e_vsi *vsi, const char *vsi_name,
struct i40e_aqc_add_macvlan_element_data *list,
struct i40e_new_mac_filter *add_head,
int num_add, bool *promisc_changed)
{
struct i40e_hw *hw = &vsi->back->hw;
int aq_err, fcnt;
i40e_aq_add_macvlan(hw, vsi->seid, list, num_add, NULL);
aq_err = hw->aq.asq_last_status;
fcnt = i40e_update_filter_state(num_add, list, add_head);
if (fcnt != num_add) {
*promisc_changed = true;
set_bit(__I40E_VSI_OVERFLOW_PROMISC, vsi->state);
dev_warn(&vsi->back->pdev->dev,
"Error %s adding RX filters on %s, promiscuous mode forced on\n",
i40e_aq_str(hw, aq_err),
vsi_name);
}
}
static i40e_status
i40e_aqc_broadcast_filter(struct i40e_vsi *vsi, const char *vsi_name,
struct i40e_mac_filter *f)
{
bool enable = f->state == I40E_FILTER_NEW;
struct i40e_hw *hw = &vsi->back->hw;
i40e_status aq_ret;
if (f->vlan == I40E_VLAN_ANY) {
aq_ret = i40e_aq_set_vsi_broadcast(hw,
vsi->seid,
enable,
NULL);
} else {
aq_ret = i40e_aq_set_vsi_bc_promisc_on_vlan(hw,
vsi->seid,
enable,
f->vlan,
NULL);
}
if (aq_ret)
dev_warn(&vsi->back->pdev->dev,
"Error %s setting broadcast promiscuous mode on %s\n",
i40e_aq_str(hw, hw->aq.asq_last_status),
vsi_name);
return aq_ret;
}
int i40e_sync_vsi_filters(struct i40e_vsi *vsi)
{
struct hlist_head tmp_add_list, tmp_del_list;
struct i40e_mac_filter *f;
struct i40e_new_mac_filter *new, *add_head = NULL;
struct i40e_hw *hw = &vsi->back->hw;
unsigned int failed_filters = 0;
unsigned int vlan_filters = 0;
bool promisc_changed = false;
char vsi_name[16] = "PF";
int filter_list_len = 0;
i40e_status aq_ret = 0;
u32 changed_flags = 0;
struct hlist_node *h;
struct i40e_pf *pf;
int num_add = 0;
int num_del = 0;
int retval = 0;
u16 cmd_flags;
int list_size;
int bkt;
struct i40e_aqc_add_macvlan_element_data *add_list;
struct i40e_aqc_remove_macvlan_element_data *del_list;
while (test_and_set_bit(__I40E_VSI_SYNCING_FILTERS, vsi->state))
usleep_range(1000, 2000);
pf = vsi->back;
if (vsi->netdev) {
changed_flags = vsi->current_netdev_flags ^ vsi->netdev->flags;
vsi->current_netdev_flags = vsi->netdev->flags;
}
INIT_HLIST_HEAD(&tmp_add_list);
INIT_HLIST_HEAD(&tmp_del_list);
if (vsi->type == I40E_VSI_SRIOV)
snprintf(vsi_name, sizeof(vsi_name) - 1, "VF %d", vsi->vf_id);
else if (vsi->type != I40E_VSI_MAIN)
snprintf(vsi_name, sizeof(vsi_name) - 1, "vsi %d", vsi->seid);
if (vsi->flags & I40E_VSI_FLAG_FILTER_CHANGED) {
vsi->flags &= ~I40E_VSI_FLAG_FILTER_CHANGED;
spin_lock_bh(&vsi->mac_filter_hash_lock);
hash_for_each_safe(vsi->mac_filter_hash, bkt, h, f, hlist) {
if (f->state == I40E_FILTER_REMOVE) {
hash_del(&f->hlist);
hlist_add_head(&f->hlist, &tmp_del_list);
continue;
}
if (f->state == I40E_FILTER_NEW) {
new = kzalloc(sizeof(*new), GFP_ATOMIC);
if (!new)
goto err_no_memory_locked;
new->f = f;
new->state = f->state;
hlist_add_head(&new->hlist, &tmp_add_list);
}
if (f->vlan > 0)
vlan_filters++;
}
retval = i40e_correct_mac_vlan_filters(vsi,
&tmp_add_list,
&tmp_del_list,
vlan_filters);
if (retval)
goto err_no_memory_locked;
spin_unlock_bh(&vsi->mac_filter_hash_lock);
}
if (!hlist_empty(&tmp_del_list)) {
filter_list_len = hw->aq.asq_buf_size /
sizeof(struct i40e_aqc_remove_macvlan_element_data);
list_size = filter_list_len *
sizeof(struct i40e_aqc_remove_macvlan_element_data);
del_list = kzalloc(list_size, GFP_ATOMIC);
if (!del_list)
goto err_no_memory;
hlist_for_each_entry_safe(f, h, &tmp_del_list, hlist) {
cmd_flags = 0;
if (is_broadcast_ether_addr(f->macaddr)) {
i40e_aqc_broadcast_filter(vsi, vsi_name, f);
hlist_del(&f->hlist);
kfree(f);
continue;
}
ether_addr_copy(del_list[num_del].mac_addr, f->macaddr);
if (f->vlan == I40E_VLAN_ANY) {
del_list[num_del].vlan_tag = 0;
cmd_flags |= I40E_AQC_MACVLAN_DEL_IGNORE_VLAN;
} else {
del_list[num_del].vlan_tag =
cpu_to_le16((u16)(f->vlan));
}
cmd_flags |= I40E_AQC_MACVLAN_DEL_PERFECT_MATCH;
del_list[num_del].flags = cmd_flags;
num_del++;
if (num_del == filter_list_len) {
i40e_aqc_del_filters(vsi, vsi_name, del_list,
num_del, &retval);
memset(del_list, 0, list_size);
num_del = 0;
}
hlist_del(&f->hlist);
kfree(f);
}
if (num_del) {
i40e_aqc_del_filters(vsi, vsi_name, del_list,
num_del, &retval);
}
kfree(del_list);
del_list = NULL;
}
if (!hlist_empty(&tmp_add_list)) {
filter_list_len = hw->aq.asq_buf_size /
sizeof(struct i40e_aqc_add_macvlan_element_data);
list_size = filter_list_len *
sizeof(struct i40e_aqc_add_macvlan_element_data);
add_list = kzalloc(list_size, GFP_ATOMIC);
if (!add_list)
goto err_no_memory;
num_add = 0;
hlist_for_each_entry_safe(new, h, &tmp_add_list, hlist) {
if (test_bit(__I40E_VSI_OVERFLOW_PROMISC,
vsi->state)) {
new->state = I40E_FILTER_FAILED;
continue;
}
if (is_broadcast_ether_addr(new->f->macaddr)) {
if (i40e_aqc_broadcast_filter(vsi, vsi_name,
new->f))
new->state = I40E_FILTER_FAILED;
else
new->state = I40E_FILTER_ACTIVE;
continue;
}
if (num_add == 0)
add_head = new;
cmd_flags = 0;
ether_addr_copy(add_list[num_add].mac_addr,
new->f->macaddr);
if (new->f->vlan == I40E_VLAN_ANY) {
add_list[num_add].vlan_tag = 0;
cmd_flags |= I40E_AQC_MACVLAN_ADD_IGNORE_VLAN;
} else {
add_list[num_add].vlan_tag =
cpu_to_le16((u16)(new->f->vlan));
}
add_list[num_add].queue_number = 0;
add_list[num_add].match_method = I40E_AQC_MM_ERR_NO_RES;
cmd_flags |= I40E_AQC_MACVLAN_ADD_PERFECT_MATCH;
add_list[num_add].flags = cpu_to_le16(cmd_flags);
num_add++;
if (num_add == filter_list_len) {
i40e_aqc_add_filters(vsi, vsi_name, add_list,
add_head, num_add,
&promisc_changed);
memset(add_list, 0, list_size);
num_add = 0;
}
}
if (num_add) {
i40e_aqc_add_filters(vsi, vsi_name, add_list, add_head,
num_add, &promisc_changed);
}
spin_lock_bh(&vsi->mac_filter_hash_lock);
hlist_for_each_entry_safe(new, h, &tmp_add_list, hlist) {
if (new->f->state == I40E_FILTER_NEW)
new->f->state = new->state;
hlist_del(&new->hlist);
kfree(new);
}
spin_unlock_bh(&vsi->mac_filter_hash_lock);
kfree(add_list);
add_list = NULL;
}
spin_lock_bh(&vsi->mac_filter_hash_lock);
vsi->active_filters = 0;
hash_for_each(vsi->mac_filter_hash, bkt, f, hlist) {
if (f->state == I40E_FILTER_ACTIVE)
vsi->active_filters++;
else if (f->state == I40E_FILTER_FAILED)
failed_filters++;
}
spin_unlock_bh(&vsi->mac_filter_hash_lock);
if (promisc_changed)
vsi->promisc_threshold = (vsi->active_filters * 3) / 4;
if (test_bit(__I40E_VSI_OVERFLOW_PROMISC, vsi->state) &&
!promisc_changed && !failed_filters &&
(vsi->active_filters < vsi->promisc_threshold)) {
dev_info(&pf->pdev->dev,
"filter logjam cleared on %s, leaving overflow promiscuous mode\n",
vsi_name);
clear_bit(__I40E_VSI_OVERFLOW_PROMISC, vsi->state);
promisc_changed = true;
vsi->promisc_threshold = 0;
}
if ((vsi->type == I40E_VSI_SRIOV) && !pf->vf[vsi->vf_id].trusted) {
clear_bit(__I40E_VSI_OVERFLOW_PROMISC, vsi->state);
goto out;
}
if (changed_flags & IFF_ALLMULTI) {
bool cur_multipromisc;
cur_multipromisc = !!(vsi->current_netdev_flags & IFF_ALLMULTI);
aq_ret = i40e_aq_set_vsi_multicast_promiscuous(&vsi->back->hw,
vsi->seid,
cur_multipromisc,
NULL);
if (aq_ret) {
retval = i40e_aq_rc_to_posix(aq_ret,
hw->aq.asq_last_status);
dev_info(&pf->pdev->dev,
"set multi promisc failed on %s, err %s aq_err %s\n",
vsi_name,
i40e_stat_str(hw, aq_ret),
i40e_aq_str(hw, hw->aq.asq_last_status));
}
}
if ((changed_flags & IFF_PROMISC) ||
(promisc_changed &&
test_bit(__I40E_VSI_OVERFLOW_PROMISC, vsi->state))) {
bool cur_promisc;
cur_promisc = (!!(vsi->current_netdev_flags & IFF_PROMISC) ||
test_bit(__I40E_VSI_OVERFLOW_PROMISC,
vsi->state));
if ((vsi->type == I40E_VSI_MAIN) &&
(pf->lan_veb != I40E_NO_VEB) &&
!(pf->flags & I40E_FLAG_MFP_ENABLED)) {
if (pf->cur_promisc != cur_promisc) {
pf->cur_promisc = cur_promisc;
if (cur_promisc)
aq_ret =
i40e_aq_set_default_vsi(hw,
vsi->seid,
NULL);
else
aq_ret =
i40e_aq_clear_default_vsi(hw,
vsi->seid,
NULL);
if (aq_ret) {
retval = i40e_aq_rc_to_posix(aq_ret,
hw->aq.asq_last_status);
dev_info(&pf->pdev->dev,
"Set default VSI failed on %s, err %s, aq_err %s\n",
vsi_name,
i40e_stat_str(hw, aq_ret),
i40e_aq_str(hw,
hw->aq.asq_last_status));
}
}
} else {
aq_ret = i40e_aq_set_vsi_unicast_promiscuous(
hw,
vsi->seid,
cur_promisc, NULL,
true);
if (aq_ret) {
retval =
i40e_aq_rc_to_posix(aq_ret,
hw->aq.asq_last_status);
dev_info(&pf->pdev->dev,
"set unicast promisc failed on %s, err %s, aq_err %s\n",
vsi_name,
i40e_stat_str(hw, aq_ret),
i40e_aq_str(hw,
hw->aq.asq_last_status));
}
aq_ret = i40e_aq_set_vsi_multicast_promiscuous(
hw,
vsi->seid,
cur_promisc, NULL);
if (aq_ret) {
retval =
i40e_aq_rc_to_posix(aq_ret,
hw->aq.asq_last_status);
dev_info(&pf->pdev->dev,
"set multicast promisc failed on %s, err %s, aq_err %s\n",
vsi_name,
i40e_stat_str(hw, aq_ret),
i40e_aq_str(hw,
hw->aq.asq_last_status));
}
}
aq_ret = i40e_aq_set_vsi_broadcast(&vsi->back->hw,
vsi->seid,
cur_promisc, NULL);
if (aq_ret) {
retval = i40e_aq_rc_to_posix(aq_ret,
pf->hw.aq.asq_last_status);
dev_info(&pf->pdev->dev,
"set brdcast promisc failed, err %s, aq_err %s\n",
i40e_stat_str(hw, aq_ret),
i40e_aq_str(hw,
hw->aq.asq_last_status));
}
}
out:
if (retval)
vsi->flags |= I40E_VSI_FLAG_FILTER_CHANGED;
clear_bit(__I40E_VSI_SYNCING_FILTERS, vsi->state);
return retval;
err_no_memory:
spin_lock_bh(&vsi->mac_filter_hash_lock);
err_no_memory_locked:
i40e_undo_del_filter_entries(vsi, &tmp_del_list);
i40e_undo_add_filter_entries(vsi, &tmp_add_list);
spin_unlock_bh(&vsi->mac_filter_hash_lock);
vsi->flags |= I40E_VSI_FLAG_FILTER_CHANGED;
clear_bit(__I40E_VSI_SYNCING_FILTERS, vsi->state);
return -ENOMEM;
}
static void i40e_sync_filters_subtask(struct i40e_pf *pf)
{
int v;
if (!pf || !(pf->flags & I40E_FLAG_FILTER_SYNC))
return;
pf->flags &= ~I40E_FLAG_FILTER_SYNC;
for (v = 0; v < pf->num_alloc_vsi; v++) {
if (pf->vsi[v] &&
(pf->vsi[v]->flags & I40E_VSI_FLAG_FILTER_CHANGED)) {
int ret = i40e_sync_vsi_filters(pf->vsi[v]);
if (ret) {
pf->flags |= I40E_FLAG_FILTER_SYNC;
break;
}
}
}
}
static int i40e_change_mtu(struct net_device *netdev, int new_mtu)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
netdev_info(netdev, "changing MTU from %d to %d\n",
netdev->mtu, new_mtu);
netdev->mtu = new_mtu;
if (netif_running(netdev))
i40e_vsi_reinit_locked(vsi);
pf->flags |= (I40E_FLAG_SERVICE_CLIENT_REQUESTED |
I40E_FLAG_CLIENT_L2_CHANGE);
return 0;
}
int i40e_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
switch (cmd) {
case SIOCGHWTSTAMP:
return i40e_ptp_get_ts_config(pf, ifr);
case SIOCSHWTSTAMP:
return i40e_ptp_set_ts_config(pf, ifr);
default:
return -EOPNOTSUPP;
}
}
void i40e_vlan_stripping_enable(struct i40e_vsi *vsi)
{
struct i40e_vsi_context ctxt;
i40e_status ret;
if ((vsi->info.valid_sections &
cpu_to_le16(I40E_AQ_VSI_PROP_VLAN_VALID)) &&
((vsi->info.port_vlan_flags & I40E_AQ_VSI_PVLAN_MODE_MASK) == 0))
return;
vsi->info.valid_sections = cpu_to_le16(I40E_AQ_VSI_PROP_VLAN_VALID);
vsi->info.port_vlan_flags = I40E_AQ_VSI_PVLAN_MODE_ALL |
I40E_AQ_VSI_PVLAN_EMOD_STR_BOTH;
ctxt.seid = vsi->seid;
ctxt.info = vsi->info;
ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"update vlan stripping failed, err %s aq_err %s\n",
i40e_stat_str(&vsi->back->hw, ret),
i40e_aq_str(&vsi->back->hw,
vsi->back->hw.aq.asq_last_status));
}
}
void i40e_vlan_stripping_disable(struct i40e_vsi *vsi)
{
struct i40e_vsi_context ctxt;
i40e_status ret;
if ((vsi->info.valid_sections &
cpu_to_le16(I40E_AQ_VSI_PROP_VLAN_VALID)) &&
((vsi->info.port_vlan_flags & I40E_AQ_VSI_PVLAN_EMOD_MASK) ==
I40E_AQ_VSI_PVLAN_EMOD_MASK))
return;
vsi->info.valid_sections = cpu_to_le16(I40E_AQ_VSI_PROP_VLAN_VALID);
vsi->info.port_vlan_flags = I40E_AQ_VSI_PVLAN_MODE_ALL |
I40E_AQ_VSI_PVLAN_EMOD_NOTHING;
ctxt.seid = vsi->seid;
ctxt.info = vsi->info;
ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"update vlan stripping failed, err %s aq_err %s\n",
i40e_stat_str(&vsi->back->hw, ret),
i40e_aq_str(&vsi->back->hw,
vsi->back->hw.aq.asq_last_status));
}
}
static void i40e_vlan_rx_register(struct net_device *netdev, u32 features)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
if (features & NETIF_F_HW_VLAN_CTAG_RX)
i40e_vlan_stripping_enable(vsi);
else
i40e_vlan_stripping_disable(vsi);
}
int i40e_add_vlan_all_mac(struct i40e_vsi *vsi, s16 vid)
{
struct i40e_mac_filter *f, *add_f;
struct hlist_node *h;
int bkt;
hash_for_each_safe(vsi->mac_filter_hash, bkt, h, f, hlist) {
if (f->state == I40E_FILTER_REMOVE)
continue;
add_f = i40e_add_filter(vsi, f->macaddr, vid);
if (!add_f) {
dev_info(&vsi->back->pdev->dev,
"Could not add vlan filter %d for %pM\n",
vid, f->macaddr);
return -ENOMEM;
}
}
return 0;
}
int i40e_vsi_add_vlan(struct i40e_vsi *vsi, u16 vid)
{
int err;
if (!vid || vsi->info.pvid)
return -EINVAL;
spin_lock_bh(&vsi->mac_filter_hash_lock);
err = i40e_add_vlan_all_mac(vsi, vid);
spin_unlock_bh(&vsi->mac_filter_hash_lock);
if (err)
return err;
i40e_service_event_schedule(vsi->back);
return 0;
}
void i40e_rm_vlan_all_mac(struct i40e_vsi *vsi, s16 vid)
{
struct i40e_mac_filter *f;
struct hlist_node *h;
int bkt;
hash_for_each_safe(vsi->mac_filter_hash, bkt, h, f, hlist) {
if (f->vlan == vid)
__i40e_del_filter(vsi, f);
}
}
void i40e_vsi_kill_vlan(struct i40e_vsi *vsi, u16 vid)
{
if (!vid || vsi->info.pvid)
return;
spin_lock_bh(&vsi->mac_filter_hash_lock);
i40e_rm_vlan_all_mac(vsi, vid);
spin_unlock_bh(&vsi->mac_filter_hash_lock);
i40e_service_event_schedule(vsi->back);
}
static int i40e_vlan_rx_add_vid(struct net_device *netdev,
__always_unused __be16 proto, u16 vid)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
int ret = 0;
if (vid >= VLAN_N_VID)
return -EINVAL;
if (vid)
ret = i40e_vsi_add_vlan(vsi, vid);
if (!ret)
set_bit(vid, vsi->active_vlans);
return ret;
}
static int i40e_vlan_rx_kill_vid(struct net_device *netdev,
__always_unused __be16 proto, u16 vid)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
i40e_vsi_kill_vlan(vsi, vid);
clear_bit(vid, vsi->active_vlans);
return 0;
}
static int i40e_macaddr_init(struct i40e_vsi *vsi, u8 *macaddr)
{
int ret;
struct i40e_aqc_add_macvlan_element_data element;
ret = i40e_aq_mac_address_write(&vsi->back->hw,
I40E_AQC_WRITE_TYPE_LAA_WOL,
macaddr, NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"Addr change for VSI failed: %d\n", ret);
return -EADDRNOTAVAIL;
}
memset(&element, 0, sizeof(element));
ether_addr_copy(element.mac_addr, macaddr);
element.flags = cpu_to_le16(I40E_AQC_MACVLAN_ADD_PERFECT_MATCH);
ret = i40e_aq_add_macvlan(&vsi->back->hw, vsi->seid, &element, 1, NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"add filter failed err %s aq_err %s\n",
i40e_stat_str(&vsi->back->hw, ret),
i40e_aq_str(&vsi->back->hw,
vsi->back->hw.aq.asq_last_status));
}
return ret;
}
static void i40e_restore_vlan(struct i40e_vsi *vsi)
{
u16 vid;
if (!vsi->netdev)
return;
i40e_vlan_rx_register(vsi->netdev, vsi->netdev->features);
for_each_set_bit(vid, vsi->active_vlans, VLAN_N_VID)
i40e_vlan_rx_add_vid(vsi->netdev, htons(ETH_P_8021Q),
vid);
}
int i40e_vsi_add_pvid(struct i40e_vsi *vsi, u16 vid)
{
struct i40e_vsi_context ctxt;
i40e_status ret;
vsi->info.valid_sections = cpu_to_le16(I40E_AQ_VSI_PROP_VLAN_VALID);
vsi->info.pvid = cpu_to_le16(vid);
vsi->info.port_vlan_flags = I40E_AQ_VSI_PVLAN_MODE_TAGGED |
I40E_AQ_VSI_PVLAN_INSERT_PVID |
I40E_AQ_VSI_PVLAN_EMOD_STR;
ctxt.seid = vsi->seid;
ctxt.info = vsi->info;
ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"add pvid failed, err %s aq_err %s\n",
i40e_stat_str(&vsi->back->hw, ret),
i40e_aq_str(&vsi->back->hw,
vsi->back->hw.aq.asq_last_status));
return -ENOENT;
}
return 0;
}
void i40e_vsi_remove_pvid(struct i40e_vsi *vsi)
{
i40e_vlan_stripping_disable(vsi);
vsi->info.pvid = 0;
}
static int i40e_vsi_setup_tx_resources(struct i40e_vsi *vsi)
{
int i, err = 0;
for (i = 0; i < vsi->num_queue_pairs && !err; i++)
err = i40e_setup_tx_descriptors(vsi->tx_rings[i]);
return err;
}
static void i40e_vsi_free_tx_resources(struct i40e_vsi *vsi)
{
int i;
if (!vsi->tx_rings)
return;
for (i = 0; i < vsi->num_queue_pairs; i++)
if (vsi->tx_rings[i] && vsi->tx_rings[i]->desc)
i40e_free_tx_resources(vsi->tx_rings[i]);
}
static int i40e_vsi_setup_rx_resources(struct i40e_vsi *vsi)
{
int i, err = 0;
for (i = 0; i < vsi->num_queue_pairs && !err; i++)
err = i40e_setup_rx_descriptors(vsi->rx_rings[i]);
return err;
}
static void i40e_vsi_free_rx_resources(struct i40e_vsi *vsi)
{
int i;
if (!vsi->rx_rings)
return;
for (i = 0; i < vsi->num_queue_pairs; i++)
if (vsi->rx_rings[i] && vsi->rx_rings[i]->desc)
i40e_free_rx_resources(vsi->rx_rings[i]);
}
static void i40e_config_xps_tx_ring(struct i40e_ring *ring)
{
struct i40e_vsi *vsi = ring->vsi;
cpumask_var_t mask;
if (!ring->q_vector || !ring->netdev)
return;
if (vsi->tc_config.numtc <= 1) {
if (!test_and_set_bit(__I40E_TX_XPS_INIT_DONE, &ring->state))
netif_set_xps_queue(ring->netdev,
&ring->q_vector->affinity_mask,
ring->queue_index);
} else if (alloc_cpumask_var(&mask, GFP_KERNEL)) {
bitmap_zero(cpumask_bits(mask), nr_cpumask_bits);
netif_set_xps_queue(ring->netdev, mask, ring->queue_index);
free_cpumask_var(mask);
}
i40e_service_event_schedule(vsi->back);
}
static int i40e_configure_tx_ring(struct i40e_ring *ring)
{
struct i40e_vsi *vsi = ring->vsi;
u16 pf_q = vsi->base_queue + ring->queue_index;
struct i40e_hw *hw = &vsi->back->hw;
struct i40e_hmc_obj_txq tx_ctx;
i40e_status err = 0;
u32 qtx_ctl = 0;
if (vsi->back->flags & I40E_FLAG_FD_ATR_ENABLED) {
ring->atr_sample_rate = vsi->back->atr_sample_rate;
ring->atr_count = 0;
} else {
ring->atr_sample_rate = 0;
}
i40e_config_xps_tx_ring(ring);
memset(&tx_ctx, 0, sizeof(tx_ctx));
tx_ctx.new_context = 1;
tx_ctx.base = (ring->dma / 128);
tx_ctx.qlen = ring->count;
tx_ctx.fd_ena = !!(vsi->back->flags & (I40E_FLAG_FD_SB_ENABLED |
I40E_FLAG_FD_ATR_ENABLED));
tx_ctx.timesync_ena = !!(vsi->back->flags & I40E_FLAG_PTP);
if (vsi->type != I40E_VSI_FDIR)
tx_ctx.head_wb_ena = 1;
tx_ctx.head_wb_addr = ring->dma +
(ring->count * sizeof(struct i40e_tx_desc));
tx_ctx.rdylist = le16_to_cpu(vsi->info.qs_handle[ring->dcb_tc]);
tx_ctx.rdylist_act = 0;
err = i40e_clear_lan_tx_queue_context(hw, pf_q);
if (err) {
dev_info(&vsi->back->pdev->dev,
"Failed to clear LAN Tx queue context on Tx ring %d (pf_q %d), error: %d\n",
ring->queue_index, pf_q, err);
return -ENOMEM;
}
err = i40e_set_lan_tx_queue_context(hw, pf_q, &tx_ctx);
if (err) {
dev_info(&vsi->back->pdev->dev,
"Failed to set LAN Tx queue context on Tx ring %d (pf_q %d, error: %d\n",
ring->queue_index, pf_q, err);
return -ENOMEM;
}
if (vsi->type == I40E_VSI_VMDQ2) {
qtx_ctl = I40E_QTX_CTL_VM_QUEUE;
qtx_ctl |= ((vsi->id) << I40E_QTX_CTL_VFVM_INDX_SHIFT) &
I40E_QTX_CTL_VFVM_INDX_MASK;
} else {
qtx_ctl = I40E_QTX_CTL_PF_QUEUE;
}
qtx_ctl |= ((hw->pf_id << I40E_QTX_CTL_PF_INDX_SHIFT) &
I40E_QTX_CTL_PF_INDX_MASK);
wr32(hw, I40E_QTX_CTL(pf_q), qtx_ctl);
i40e_flush(hw);
ring->tail = hw->hw_addr + I40E_QTX_TAIL(pf_q);
return 0;
}
static int i40e_configure_rx_ring(struct i40e_ring *ring)
{
struct i40e_vsi *vsi = ring->vsi;
u32 chain_len = vsi->back->hw.func_caps.rx_buf_chain_len;
u16 pf_q = vsi->base_queue + ring->queue_index;
struct i40e_hw *hw = &vsi->back->hw;
struct i40e_hmc_obj_rxq rx_ctx;
i40e_status err = 0;
ring->state = 0;
memset(&rx_ctx, 0, sizeof(rx_ctx));
ring->rx_buf_len = vsi->rx_buf_len;
rx_ctx.dbuff = DIV_ROUND_UP(ring->rx_buf_len,
BIT_ULL(I40E_RXQ_CTX_DBUFF_SHIFT));
rx_ctx.base = (ring->dma / 128);
rx_ctx.qlen = ring->count;
rx_ctx.dsize = 1;
rx_ctx.hsplit_0 = 0;
rx_ctx.rxmax = min_t(u16, vsi->max_frame, chain_len * ring->rx_buf_len);
if (hw->revision_id == 0)
rx_ctx.lrxqthresh = 0;
else
rx_ctx.lrxqthresh = 2;
rx_ctx.crcstrip = 1;
rx_ctx.l2tsel = 1;
rx_ctx.showiv = 0;
rx_ctx.prefena = 1;
err = i40e_clear_lan_rx_queue_context(hw, pf_q);
if (err) {
dev_info(&vsi->back->pdev->dev,
"Failed to clear LAN Rx queue context on Rx ring %d (pf_q %d), error: %d\n",
ring->queue_index, pf_q, err);
return -ENOMEM;
}
err = i40e_set_lan_rx_queue_context(hw, pf_q, &rx_ctx);
if (err) {
dev_info(&vsi->back->pdev->dev,
"Failed to set LAN Rx queue context on Rx ring %d (pf_q %d), error: %d\n",
ring->queue_index, pf_q, err);
return -ENOMEM;
}
if (!vsi->netdev || (vsi->back->flags & I40E_FLAG_LEGACY_RX))
clear_ring_build_skb_enabled(ring);
else
set_ring_build_skb_enabled(ring);
ring->tail = hw->hw_addr + I40E_QRX_TAIL(pf_q);
writel(0, ring->tail);
i40e_alloc_rx_buffers(ring, I40E_DESC_UNUSED(ring));
return 0;
}
static int i40e_vsi_configure_tx(struct i40e_vsi *vsi)
{
int err = 0;
u16 i;
for (i = 0; (i < vsi->num_queue_pairs) && !err; i++)
err = i40e_configure_tx_ring(vsi->tx_rings[i]);
return err;
}
static int i40e_vsi_configure_rx(struct i40e_vsi *vsi)
{
int err = 0;
u16 i;
if (!vsi->netdev || (vsi->back->flags & I40E_FLAG_LEGACY_RX)) {
vsi->max_frame = I40E_MAX_RXBUFFER;
vsi->rx_buf_len = I40E_RXBUFFER_2048;
#if (PAGE_SIZE < 8192)
} else if (!I40E_2K_TOO_SMALL_WITH_PADDING &&
(vsi->netdev->mtu <= ETH_DATA_LEN)) {
vsi->max_frame = I40E_RXBUFFER_1536 - NET_IP_ALIGN;
vsi->rx_buf_len = I40E_RXBUFFER_1536 - NET_IP_ALIGN;
#endif
} else {
vsi->max_frame = I40E_MAX_RXBUFFER;
vsi->rx_buf_len = (PAGE_SIZE < 8192) ? I40E_RXBUFFER_3072 :
I40E_RXBUFFER_2048;
}
for (i = 0; i < vsi->num_queue_pairs && !err; i++)
err = i40e_configure_rx_ring(vsi->rx_rings[i]);
return err;
}
static void i40e_vsi_config_dcb_rings(struct i40e_vsi *vsi)
{
struct i40e_ring *tx_ring, *rx_ring;
u16 qoffset, qcount;
int i, n;
if (!(vsi->back->flags & I40E_FLAG_DCB_ENABLED)) {
for (i = 0; i < vsi->num_queue_pairs; i++) {
rx_ring = vsi->rx_rings[i];
tx_ring = vsi->tx_rings[i];
rx_ring->dcb_tc = 0;
tx_ring->dcb_tc = 0;
}
}
for (n = 0; n < I40E_MAX_TRAFFIC_CLASS; n++) {
if (!(vsi->tc_config.enabled_tc & BIT_ULL(n)))
continue;
qoffset = vsi->tc_config.tc_info[n].qoffset;
qcount = vsi->tc_config.tc_info[n].qcount;
for (i = qoffset; i < (qoffset + qcount); i++) {
rx_ring = vsi->rx_rings[i];
tx_ring = vsi->tx_rings[i];
rx_ring->dcb_tc = n;
tx_ring->dcb_tc = n;
}
}
}
static void i40e_set_vsi_rx_mode(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
int err;
if (vsi->netdev)
i40e_set_rx_mode(vsi->netdev);
if (!!(pf->flags & I40E_FLAG_PF_MAC)) {
err = i40e_macaddr_init(vsi, pf->hw.mac.addr);
if (err) {
dev_warn(&pf->pdev->dev,
"could not set up macaddr; err %d\n", err);
}
}
}
static void i40e_fdir_filter_restore(struct i40e_vsi *vsi)
{
struct i40e_fdir_filter *filter;
struct i40e_pf *pf = vsi->back;
struct hlist_node *node;
if (!(pf->flags & I40E_FLAG_FD_SB_ENABLED))
return;
pf->fd_tcp4_filter_cnt = 0;
pf->fd_udp4_filter_cnt = 0;
pf->fd_sctp4_filter_cnt = 0;
pf->fd_ip4_filter_cnt = 0;
hlist_for_each_entry_safe(filter, node,
&pf->fdir_filter_list, fdir_node) {
i40e_add_del_fdir(vsi, filter, true);
}
}
static int i40e_vsi_configure(struct i40e_vsi *vsi)
{
int err;
i40e_set_vsi_rx_mode(vsi);
i40e_restore_vlan(vsi);
i40e_vsi_config_dcb_rings(vsi);
err = i40e_vsi_configure_tx(vsi);
if (!err)
err = i40e_vsi_configure_rx(vsi);
return err;
}
static void i40e_vsi_configure_msix(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
u16 vector;
int i, q;
u32 qp;
qp = vsi->base_queue;
vector = vsi->base_vector;
for (i = 0; i < vsi->num_q_vectors; i++, vector++) {
struct i40e_q_vector *q_vector = vsi->q_vectors[i];
q_vector->itr_countdown = ITR_COUNTDOWN_START;
q_vector->rx.itr = ITR_TO_REG(vsi->rx_rings[i]->rx_itr_setting);
q_vector->rx.latency_range = I40E_LOW_LATENCY;
wr32(hw, I40E_PFINT_ITRN(I40E_RX_ITR, vector - 1),
q_vector->rx.itr);
q_vector->tx.itr = ITR_TO_REG(vsi->tx_rings[i]->tx_itr_setting);
q_vector->tx.latency_range = I40E_LOW_LATENCY;
wr32(hw, I40E_PFINT_ITRN(I40E_TX_ITR, vector - 1),
q_vector->tx.itr);
wr32(hw, I40E_PFINT_RATEN(vector - 1),
i40e_intrl_usec_to_reg(vsi->int_rate_limit));
wr32(hw, I40E_PFINT_LNKLSTN(vector - 1), qp);
for (q = 0; q < q_vector->num_ringpairs; q++) {
u32 val;
val = I40E_QINT_RQCTL_CAUSE_ENA_MASK |
(I40E_RX_ITR << I40E_QINT_RQCTL_ITR_INDX_SHIFT) |
(vector << I40E_QINT_RQCTL_MSIX_INDX_SHIFT) |
(qp << I40E_QINT_RQCTL_NEXTQ_INDX_SHIFT)|
(I40E_QUEUE_TYPE_TX
<< I40E_QINT_RQCTL_NEXTQ_TYPE_SHIFT);
wr32(hw, I40E_QINT_RQCTL(qp), val);
val = I40E_QINT_TQCTL_CAUSE_ENA_MASK |
(I40E_TX_ITR << I40E_QINT_TQCTL_ITR_INDX_SHIFT) |
(vector << I40E_QINT_TQCTL_MSIX_INDX_SHIFT) |
((qp+1) << I40E_QINT_TQCTL_NEXTQ_INDX_SHIFT)|
(I40E_QUEUE_TYPE_RX
<< I40E_QINT_TQCTL_NEXTQ_TYPE_SHIFT);
if (q == (q_vector->num_ringpairs - 1))
val |= (I40E_QUEUE_END_OF_LIST
<< I40E_QINT_TQCTL_NEXTQ_INDX_SHIFT);
wr32(hw, I40E_QINT_TQCTL(qp), val);
qp++;
}
}
i40e_flush(hw);
}
static void i40e_enable_misc_int_causes(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
u32 val;
wr32(hw, I40E_PFINT_ICR0_ENA, 0);
rd32(hw, I40E_PFINT_ICR0);
val = I40E_PFINT_ICR0_ENA_ECC_ERR_MASK |
I40E_PFINT_ICR0_ENA_MAL_DETECT_MASK |
I40E_PFINT_ICR0_ENA_GRST_MASK |
I40E_PFINT_ICR0_ENA_PCI_EXCEPTION_MASK |
I40E_PFINT_ICR0_ENA_GPIO_MASK |
I40E_PFINT_ICR0_ENA_HMC_ERR_MASK |
I40E_PFINT_ICR0_ENA_VFLR_MASK |
I40E_PFINT_ICR0_ENA_ADMINQ_MASK;
if (pf->flags & I40E_FLAG_IWARP_ENABLED)
val |= I40E_PFINT_ICR0_ENA_PE_CRITERR_MASK;
if (pf->flags & I40E_FLAG_PTP)
val |= I40E_PFINT_ICR0_ENA_TIMESYNC_MASK;
wr32(hw, I40E_PFINT_ICR0_ENA, val);
wr32(hw, I40E_PFINT_DYN_CTL0, I40E_PFINT_DYN_CTL0_SW_ITR_INDX_MASK |
I40E_PFINT_DYN_CTL0_INTENA_MSK_MASK);
wr32(hw, I40E_PFINT_STAT_CTL0, 0);
}
static void i40e_configure_msi_and_legacy(struct i40e_vsi *vsi)
{
struct i40e_q_vector *q_vector = vsi->q_vectors[0];
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
u32 val;
q_vector->itr_countdown = ITR_COUNTDOWN_START;
q_vector->rx.itr = ITR_TO_REG(vsi->rx_rings[0]->rx_itr_setting);
q_vector->rx.latency_range = I40E_LOW_LATENCY;
wr32(hw, I40E_PFINT_ITR0(I40E_RX_ITR), q_vector->rx.itr);
q_vector->tx.itr = ITR_TO_REG(vsi->tx_rings[0]->tx_itr_setting);
q_vector->tx.latency_range = I40E_LOW_LATENCY;
wr32(hw, I40E_PFINT_ITR0(I40E_TX_ITR), q_vector->tx.itr);
i40e_enable_misc_int_causes(pf);
wr32(hw, I40E_PFINT_LNKLST0, 0);
val = I40E_QINT_RQCTL_CAUSE_ENA_MASK |
(I40E_RX_ITR << I40E_QINT_RQCTL_ITR_INDX_SHIFT) |
(I40E_QUEUE_TYPE_TX << I40E_QINT_TQCTL_NEXTQ_TYPE_SHIFT);
wr32(hw, I40E_QINT_RQCTL(0), val);
val = I40E_QINT_TQCTL_CAUSE_ENA_MASK |
(I40E_TX_ITR << I40E_QINT_TQCTL_ITR_INDX_SHIFT) |
(I40E_QUEUE_END_OF_LIST << I40E_QINT_TQCTL_NEXTQ_INDX_SHIFT);
wr32(hw, I40E_QINT_TQCTL(0), val);
i40e_flush(hw);
}
void i40e_irq_dynamic_disable_icr0(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
wr32(hw, I40E_PFINT_DYN_CTL0,
I40E_ITR_NONE << I40E_PFINT_DYN_CTLN_ITR_INDX_SHIFT);
i40e_flush(hw);
}
void i40e_irq_dynamic_enable_icr0(struct i40e_pf *pf, bool clearpba)
{
struct i40e_hw *hw = &pf->hw;
u32 val;
val = I40E_PFINT_DYN_CTL0_INTENA_MASK |
(clearpba ? I40E_PFINT_DYN_CTL0_CLEARPBA_MASK : 0) |
(I40E_ITR_NONE << I40E_PFINT_DYN_CTL0_ITR_INDX_SHIFT);
wr32(hw, I40E_PFINT_DYN_CTL0, val);
i40e_flush(hw);
}
static irqreturn_t i40e_msix_clean_rings(int irq, void *data)
{
struct i40e_q_vector *q_vector = data;
if (!q_vector->tx.ring && !q_vector->rx.ring)
return IRQ_HANDLED;
napi_schedule_irqoff(&q_vector->napi);
return IRQ_HANDLED;
}
static void i40e_irq_affinity_notify(struct irq_affinity_notify *notify,
const cpumask_t *mask)
{
struct i40e_q_vector *q_vector =
container_of(notify, struct i40e_q_vector, affinity_notify);
q_vector->affinity_mask = *mask;
}
static void i40e_irq_affinity_release(struct kref *ref) {}
static int i40e_vsi_request_irq_msix(struct i40e_vsi *vsi, char *basename)
{
int q_vectors = vsi->num_q_vectors;
struct i40e_pf *pf = vsi->back;
int base = vsi->base_vector;
int rx_int_idx = 0;
int tx_int_idx = 0;
int vector, err;
int irq_num;
for (vector = 0; vector < q_vectors; vector++) {
struct i40e_q_vector *q_vector = vsi->q_vectors[vector];
irq_num = pf->msix_entries[base + vector].vector;
if (q_vector->tx.ring && q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", basename, "TxRx", rx_int_idx++);
tx_int_idx++;
} else if (q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", basename, "rx", rx_int_idx++);
} else if (q_vector->tx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", basename, "tx", tx_int_idx++);
} else {
continue;
}
err = request_irq(irq_num,
vsi->irq_handler,
0,
q_vector->name,
q_vector);
if (err) {
dev_info(&pf->pdev->dev,
"MSIX request_irq failed, error: %d\n", err);
goto free_queue_irqs;
}
q_vector->affinity_notify.notify = i40e_irq_affinity_notify;
q_vector->affinity_notify.release = i40e_irq_affinity_release;
irq_set_affinity_notifier(irq_num, &q_vector->affinity_notify);
irq_set_affinity_hint(irq_num, &q_vector->affinity_mask);
}
vsi->irqs_ready = true;
return 0;
free_queue_irqs:
while (vector) {
vector--;
irq_num = pf->msix_entries[base + vector].vector;
irq_set_affinity_notifier(irq_num, NULL);
irq_set_affinity_hint(irq_num, NULL);
free_irq(irq_num, &vsi->q_vectors[vector]);
}
return err;
}
static void i40e_vsi_disable_irq(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
int base = vsi->base_vector;
int i;
for (i = 0; i < vsi->num_queue_pairs; i++) {
wr32(hw, I40E_QINT_TQCTL(vsi->tx_rings[i]->reg_idx), 0);
wr32(hw, I40E_QINT_RQCTL(vsi->rx_rings[i]->reg_idx), 0);
}
if (pf->flags & I40E_FLAG_MSIX_ENABLED) {
for (i = vsi->base_vector;
i < (vsi->num_q_vectors + vsi->base_vector); i++)
wr32(hw, I40E_PFINT_DYN_CTLN(i - 1), 0);
i40e_flush(hw);
for (i = 0; i < vsi->num_q_vectors; i++)
synchronize_irq(pf->msix_entries[i + base].vector);
} else {
wr32(hw, I40E_PFINT_ICR0_ENA, 0);
wr32(hw, I40E_PFINT_DYN_CTL0, 0);
i40e_flush(hw);
synchronize_irq(pf->pdev->irq);
}
}
static int i40e_vsi_enable_irq(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
int i;
if (pf->flags & I40E_FLAG_MSIX_ENABLED) {
for (i = 0; i < vsi->num_q_vectors; i++)
i40e_irq_dynamic_enable(vsi, i);
} else {
i40e_irq_dynamic_enable_icr0(pf, true);
}
i40e_flush(&pf->hw);
return 0;
}
static void i40e_stop_misc_vector(struct i40e_pf *pf)
{
wr32(&pf->hw, I40E_PFINT_ICR0_ENA, 0);
i40e_flush(&pf->hw);
}
static irqreturn_t i40e_intr(int irq, void *data)
{
struct i40e_pf *pf = (struct i40e_pf *)data;
struct i40e_hw *hw = &pf->hw;
irqreturn_t ret = IRQ_NONE;
u32 icr0, icr0_remaining;
u32 val, ena_mask;
icr0 = rd32(hw, I40E_PFINT_ICR0);
ena_mask = rd32(hw, I40E_PFINT_ICR0_ENA);
if ((icr0 & I40E_PFINT_ICR0_INTEVENT_MASK) == 0)
goto enable_intr;
if (((icr0 & ~I40E_PFINT_ICR0_INTEVENT_MASK) == 0) ||
(icr0 & I40E_PFINT_ICR0_SWINT_MASK))
pf->sw_int_count++;
if ((pf->flags & I40E_FLAG_IWARP_ENABLED) &&
(ena_mask & I40E_PFINT_ICR0_ENA_PE_CRITERR_MASK)) {
ena_mask &= ~I40E_PFINT_ICR0_ENA_PE_CRITERR_MASK;
icr0 &= ~I40E_PFINT_ICR0_ENA_PE_CRITERR_MASK;
dev_dbg(&pf->pdev->dev, "cleared PE_CRITERR\n");
}
if (icr0 & I40E_PFINT_ICR0_QUEUE_0_MASK) {
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
struct i40e_q_vector *q_vector = vsi->q_vectors[0];
if (!test_bit(__I40E_DOWN, pf->state))
napi_schedule_irqoff(&q_vector->napi);
}
if (icr0 & I40E_PFINT_ICR0_ADMINQ_MASK) {
ena_mask &= ~I40E_PFINT_ICR0_ENA_ADMINQ_MASK;
set_bit(__I40E_ADMINQ_EVENT_PENDING, pf->state);
i40e_debug(&pf->hw, I40E_DEBUG_NVM, "AdminQ event\n");
}
if (icr0 & I40E_PFINT_ICR0_MAL_DETECT_MASK) {
ena_mask &= ~I40E_PFINT_ICR0_ENA_MAL_DETECT_MASK;
set_bit(__I40E_MDD_EVENT_PENDING, pf->state);
}
if (icr0 & I40E_PFINT_ICR0_VFLR_MASK) {
ena_mask &= ~I40E_PFINT_ICR0_ENA_VFLR_MASK;
set_bit(__I40E_VFLR_EVENT_PENDING, pf->state);
}
if (icr0 & I40E_PFINT_ICR0_GRST_MASK) {
if (!test_bit(__I40E_RESET_RECOVERY_PENDING, pf->state))
set_bit(__I40E_RESET_INTR_RECEIVED, pf->state);
ena_mask &= ~I40E_PFINT_ICR0_ENA_GRST_MASK;
val = rd32(hw, I40E_GLGEN_RSTAT);
val = (val & I40E_GLGEN_RSTAT_RESET_TYPE_MASK)
>> I40E_GLGEN_RSTAT_RESET_TYPE_SHIFT;
if (val == I40E_RESET_CORER) {
pf->corer_count++;
} else if (val == I40E_RESET_GLOBR) {
pf->globr_count++;
} else if (val == I40E_RESET_EMPR) {
pf->empr_count++;
set_bit(__I40E_EMP_RESET_INTR_RECEIVED, pf->state);
}
}
if (icr0 & I40E_PFINT_ICR0_HMC_ERR_MASK) {
icr0 &= ~I40E_PFINT_ICR0_HMC_ERR_MASK;
dev_info(&pf->pdev->dev, "HMC error interrupt\n");
dev_info(&pf->pdev->dev, "HMC error info 0x%x, HMC error data 0x%x\n",
rd32(hw, I40E_PFHMC_ERRORINFO),
rd32(hw, I40E_PFHMC_ERRORDATA));
}
if (icr0 & I40E_PFINT_ICR0_TIMESYNC_MASK) {
u32 prttsyn_stat = rd32(hw, I40E_PRTTSYN_STAT_0);
if (prttsyn_stat & I40E_PRTTSYN_STAT_0_TXTIME_MASK) {
icr0 &= ~I40E_PFINT_ICR0_ENA_TIMESYNC_MASK;
i40e_ptp_tx_hwtstamp(pf);
}
}
icr0_remaining = icr0 & ena_mask;
if (icr0_remaining) {
dev_info(&pf->pdev->dev, "unhandled interrupt icr0=0x%08x\n",
icr0_remaining);
if ((icr0_remaining & I40E_PFINT_ICR0_PE_CRITERR_MASK) ||
(icr0_remaining & I40E_PFINT_ICR0_PCI_EXCEPTION_MASK) ||
(icr0_remaining & I40E_PFINT_ICR0_ECC_ERR_MASK)) {
dev_info(&pf->pdev->dev, "device will be reset\n");
set_bit(__I40E_PF_RESET_REQUESTED, pf->state);
i40e_service_event_schedule(pf);
}
ena_mask &= ~icr0_remaining;
}
ret = IRQ_HANDLED;
enable_intr:
wr32(hw, I40E_PFINT_ICR0_ENA, ena_mask);
if (!test_bit(__I40E_DOWN, pf->state)) {
i40e_service_event_schedule(pf);
i40e_irq_dynamic_enable_icr0(pf, false);
}
return ret;
}
static bool i40e_clean_fdir_tx_irq(struct i40e_ring *tx_ring, int budget)
{
struct i40e_vsi *vsi = tx_ring->vsi;
u16 i = tx_ring->next_to_clean;
struct i40e_tx_buffer *tx_buf;
struct i40e_tx_desc *tx_desc;
tx_buf = &tx_ring->tx_bi[i];
tx_desc = I40E_TX_DESC(tx_ring, i);
i -= tx_ring->count;
do {
struct i40e_tx_desc *eop_desc = tx_buf->next_to_watch;
if (!eop_desc)
break;
read_barrier_depends();
if (!(eop_desc->cmd_type_offset_bsz &
cpu_to_le64(I40E_TX_DESC_DTYPE_DESC_DONE)))
break;
tx_buf->next_to_watch = NULL;
tx_desc->buffer_addr = 0;
tx_desc->cmd_type_offset_bsz = 0;
tx_buf++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buf = tx_ring->tx_bi;
tx_desc = I40E_TX_DESC(tx_ring, 0);
}
dma_unmap_single(tx_ring->dev,
dma_unmap_addr(tx_buf, dma),
dma_unmap_len(tx_buf, len),
DMA_TO_DEVICE);
if (tx_buf->tx_flags & I40E_TX_FLAGS_FD_SB)
kfree(tx_buf->raw_buf);
tx_buf->raw_buf = NULL;
tx_buf->tx_flags = 0;
tx_buf->next_to_watch = NULL;
dma_unmap_len_set(tx_buf, len, 0);
tx_desc->buffer_addr = 0;
tx_desc->cmd_type_offset_bsz = 0;
tx_buf++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buf = tx_ring->tx_bi;
tx_desc = I40E_TX_DESC(tx_ring, 0);
}
budget--;
} while (likely(budget));
i += tx_ring->count;
tx_ring->next_to_clean = i;
if (vsi->back->flags & I40E_FLAG_MSIX_ENABLED)
i40e_irq_dynamic_enable(vsi, tx_ring->q_vector->v_idx);
return budget > 0;
}
static irqreturn_t i40e_fdir_clean_ring(int irq, void *data)
{
struct i40e_q_vector *q_vector = data;
struct i40e_vsi *vsi;
if (!q_vector->tx.ring)
return IRQ_HANDLED;
vsi = q_vector->tx.ring->vsi;
i40e_clean_fdir_tx_irq(q_vector->tx.ring, vsi->work_limit);
return IRQ_HANDLED;
}
static void i40e_map_vector_to_qp(struct i40e_vsi *vsi, int v_idx, int qp_idx)
{
struct i40e_q_vector *q_vector = vsi->q_vectors[v_idx];
struct i40e_ring *tx_ring = vsi->tx_rings[qp_idx];
struct i40e_ring *rx_ring = vsi->rx_rings[qp_idx];
tx_ring->q_vector = q_vector;
tx_ring->next = q_vector->tx.ring;
q_vector->tx.ring = tx_ring;
q_vector->tx.count++;
rx_ring->q_vector = q_vector;
rx_ring->next = q_vector->rx.ring;
q_vector->rx.ring = rx_ring;
q_vector->rx.count++;
}
static void i40e_vsi_map_rings_to_vectors(struct i40e_vsi *vsi)
{
int qp_remaining = vsi->num_queue_pairs;
int q_vectors = vsi->num_q_vectors;
int num_ringpairs;
int v_start = 0;
int qp_idx = 0;
for (; v_start < q_vectors; v_start++) {
struct i40e_q_vector *q_vector = vsi->q_vectors[v_start];
num_ringpairs = DIV_ROUND_UP(qp_remaining, q_vectors - v_start);
q_vector->num_ringpairs = num_ringpairs;
q_vector->rx.count = 0;
q_vector->tx.count = 0;
q_vector->rx.ring = NULL;
q_vector->tx.ring = NULL;
while (num_ringpairs--) {
i40e_map_vector_to_qp(vsi, v_start, qp_idx);
qp_idx++;
qp_remaining--;
}
}
}
static int i40e_vsi_request_irq(struct i40e_vsi *vsi, char *basename)
{
struct i40e_pf *pf = vsi->back;
int err;
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
err = i40e_vsi_request_irq_msix(vsi, basename);
else if (pf->flags & I40E_FLAG_MSI_ENABLED)
err = request_irq(pf->pdev->irq, i40e_intr, 0,
pf->int_name, pf);
else
err = request_irq(pf->pdev->irq, i40e_intr, IRQF_SHARED,
pf->int_name, pf);
if (err)
dev_info(&pf->pdev->dev, "request_irq failed, Error %d\n", err);
return err;
}
static void i40e_netpoll(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
int i;
if (test_bit(__I40E_VSI_DOWN, vsi->state))
return;
if (pf->flags & I40E_FLAG_MSIX_ENABLED) {
for (i = 0; i < vsi->num_q_vectors; i++)
i40e_msix_clean_rings(0, vsi->q_vectors[i]);
} else {
i40e_intr(pf->pdev->irq, netdev);
}
}
static int i40e_pf_txq_wait(struct i40e_pf *pf, int pf_q, bool enable)
{
int i;
u32 tx_reg;
for (i = 0; i < I40E_QUEUE_WAIT_RETRY_LIMIT; i++) {
tx_reg = rd32(&pf->hw, I40E_QTX_ENA(pf_q));
if (enable == !!(tx_reg & I40E_QTX_ENA_QENA_STAT_MASK))
break;
usleep_range(10, 20);
}
if (i >= I40E_QUEUE_WAIT_RETRY_LIMIT)
return -ETIMEDOUT;
return 0;
}
static void i40e_control_tx_q(struct i40e_pf *pf, int pf_q, bool enable)
{
struct i40e_hw *hw = &pf->hw;
u32 tx_reg;
int i;
i40e_pre_tx_queue_cfg(&pf->hw, pf_q, enable);
if (!enable)
usleep_range(10, 20);
for (i = 0; i < I40E_QTX_ENA_WAIT_COUNT; i++) {
tx_reg = rd32(hw, I40E_QTX_ENA(pf_q));
if (((tx_reg >> I40E_QTX_ENA_QENA_REQ_SHIFT) & 1) ==
((tx_reg >> I40E_QTX_ENA_QENA_STAT_SHIFT) & 1))
break;
usleep_range(1000, 2000);
}
if (enable == !!(tx_reg & I40E_QTX_ENA_QENA_STAT_MASK))
return;
if (enable) {
wr32(hw, I40E_QTX_HEAD(pf_q), 0);
tx_reg |= I40E_QTX_ENA_QENA_REQ_MASK;
} else {
tx_reg &= ~I40E_QTX_ENA_QENA_REQ_MASK;
}
wr32(hw, I40E_QTX_ENA(pf_q), tx_reg);
}
static int i40e_vsi_control_tx(struct i40e_vsi *vsi, bool enable)
{
struct i40e_pf *pf = vsi->back;
int i, pf_q, ret = 0;
pf_q = vsi->base_queue;
for (i = 0; i < vsi->num_queue_pairs; i++, pf_q++) {
i40e_control_tx_q(pf, pf_q, enable);
ret = i40e_pf_txq_wait(pf, pf_q, enable);
if (ret) {
dev_info(&pf->pdev->dev,
"VSI seid %d Tx ring %d %sable timeout\n",
vsi->seid, pf_q, (enable ? "en" : "dis"));
break;
}
}
return ret;
}
static int i40e_pf_rxq_wait(struct i40e_pf *pf, int pf_q, bool enable)
{
int i;
u32 rx_reg;
for (i = 0; i < I40E_QUEUE_WAIT_RETRY_LIMIT; i++) {
rx_reg = rd32(&pf->hw, I40E_QRX_ENA(pf_q));
if (enable == !!(rx_reg & I40E_QRX_ENA_QENA_STAT_MASK))
break;
usleep_range(10, 20);
}
if (i >= I40E_QUEUE_WAIT_RETRY_LIMIT)
return -ETIMEDOUT;
return 0;
}
static void i40e_control_rx_q(struct i40e_pf *pf, int pf_q, bool enable)
{
struct i40e_hw *hw = &pf->hw;
u32 rx_reg;
int i;
for (i = 0; i < I40E_QTX_ENA_WAIT_COUNT; i++) {
rx_reg = rd32(hw, I40E_QRX_ENA(pf_q));
if (((rx_reg >> I40E_QRX_ENA_QENA_REQ_SHIFT) & 1) ==
((rx_reg >> I40E_QRX_ENA_QENA_STAT_SHIFT) & 1))
break;
usleep_range(1000, 2000);
}
if (enable == !!(rx_reg & I40E_QRX_ENA_QENA_STAT_MASK))
return;
if (enable)
rx_reg |= I40E_QRX_ENA_QENA_REQ_MASK;
else
rx_reg &= ~I40E_QRX_ENA_QENA_REQ_MASK;
wr32(hw, I40E_QRX_ENA(pf_q), rx_reg);
}
static int i40e_vsi_control_rx(struct i40e_vsi *vsi, bool enable)
{
struct i40e_pf *pf = vsi->back;
int i, pf_q, ret = 0;
pf_q = vsi->base_queue;
for (i = 0; i < vsi->num_queue_pairs; i++, pf_q++) {
i40e_control_rx_q(pf, pf_q, enable);
ret = i40e_pf_rxq_wait(pf, pf_q, enable);
if (ret) {
dev_info(&pf->pdev->dev,
"VSI seid %d Rx ring %d %sable timeout\n",
vsi->seid, pf_q, (enable ? "en" : "dis"));
break;
}
}
if (!enable)
mdelay(50);
return ret;
}
int i40e_vsi_start_rings(struct i40e_vsi *vsi)
{
int ret = 0;
ret = i40e_vsi_control_rx(vsi, true);
if (ret)
return ret;
ret = i40e_vsi_control_tx(vsi, true);
return ret;
}
void i40e_vsi_stop_rings(struct i40e_vsi *vsi)
{
if (test_bit(__I40E_PORT_SUSPENDED, vsi->back->state))
return i40e_vsi_stop_rings_no_wait(vsi);
i40e_vsi_control_tx(vsi, false);
i40e_vsi_control_rx(vsi, false);
}
void i40e_vsi_stop_rings_no_wait(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
int i, pf_q;
pf_q = vsi->base_queue;
for (i = 0; i < vsi->num_queue_pairs; i++, pf_q++) {
i40e_control_tx_q(pf, pf_q, false);
i40e_control_rx_q(pf, pf_q, false);
}
}
static void i40e_vsi_free_irq(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
int base = vsi->base_vector;
u32 val, qp;
int i;
if (pf->flags & I40E_FLAG_MSIX_ENABLED) {
if (!vsi->q_vectors)
return;
if (!vsi->irqs_ready)
return;
vsi->irqs_ready = false;
for (i = 0; i < vsi->num_q_vectors; i++) {
int irq_num;
u16 vector;
vector = i + base;
irq_num = pf->msix_entries[vector].vector;
if (!vsi->q_vectors[i] ||
!vsi->q_vectors[i]->num_ringpairs)
continue;
irq_set_affinity_notifier(irq_num, NULL);
irq_set_affinity_hint(irq_num, NULL);
synchronize_irq(irq_num);
free_irq(irq_num, vsi->q_vectors[i]);
val = rd32(hw, I40E_PFINT_LNKLSTN(vector - 1));
qp = (val & I40E_PFINT_LNKLSTN_FIRSTQ_INDX_MASK)
>> I40E_PFINT_LNKLSTN_FIRSTQ_INDX_SHIFT;
val |= I40E_QUEUE_END_OF_LIST
<< I40E_PFINT_LNKLSTN_FIRSTQ_INDX_SHIFT;
wr32(hw, I40E_PFINT_LNKLSTN(vector - 1), val);
while (qp != I40E_QUEUE_END_OF_LIST) {
u32 next;
val = rd32(hw, I40E_QINT_RQCTL(qp));
val &= ~(I40E_QINT_RQCTL_MSIX_INDX_MASK |
I40E_QINT_RQCTL_MSIX0_INDX_MASK |
I40E_QINT_RQCTL_CAUSE_ENA_MASK |
I40E_QINT_RQCTL_INTEVENT_MASK);
val |= (I40E_QINT_RQCTL_ITR_INDX_MASK |
I40E_QINT_RQCTL_NEXTQ_INDX_MASK);
wr32(hw, I40E_QINT_RQCTL(qp), val);
val = rd32(hw, I40E_QINT_TQCTL(qp));
next = (val & I40E_QINT_TQCTL_NEXTQ_INDX_MASK)
>> I40E_QINT_TQCTL_NEXTQ_INDX_SHIFT;
val &= ~(I40E_QINT_TQCTL_MSIX_INDX_MASK |
I40E_QINT_TQCTL_MSIX0_INDX_MASK |
I40E_QINT_TQCTL_CAUSE_ENA_MASK |
I40E_QINT_TQCTL_INTEVENT_MASK);
val |= (I40E_QINT_TQCTL_ITR_INDX_MASK |
I40E_QINT_TQCTL_NEXTQ_INDX_MASK);
wr32(hw, I40E_QINT_TQCTL(qp), val);
qp = next;
}
}
} else {
free_irq(pf->pdev->irq, pf);
val = rd32(hw, I40E_PFINT_LNKLST0);
qp = (val & I40E_PFINT_LNKLSTN_FIRSTQ_INDX_MASK)
>> I40E_PFINT_LNKLSTN_FIRSTQ_INDX_SHIFT;
val |= I40E_QUEUE_END_OF_LIST
<< I40E_PFINT_LNKLST0_FIRSTQ_INDX_SHIFT;
wr32(hw, I40E_PFINT_LNKLST0, val);
val = rd32(hw, I40E_QINT_RQCTL(qp));
val &= ~(I40E_QINT_RQCTL_MSIX_INDX_MASK |
I40E_QINT_RQCTL_MSIX0_INDX_MASK |
I40E_QINT_RQCTL_CAUSE_ENA_MASK |
I40E_QINT_RQCTL_INTEVENT_MASK);
val |= (I40E_QINT_RQCTL_ITR_INDX_MASK |
I40E_QINT_RQCTL_NEXTQ_INDX_MASK);
wr32(hw, I40E_QINT_RQCTL(qp), val);
val = rd32(hw, I40E_QINT_TQCTL(qp));
val &= ~(I40E_QINT_TQCTL_MSIX_INDX_MASK |
I40E_QINT_TQCTL_MSIX0_INDX_MASK |
I40E_QINT_TQCTL_CAUSE_ENA_MASK |
I40E_QINT_TQCTL_INTEVENT_MASK);
val |= (I40E_QINT_TQCTL_ITR_INDX_MASK |
I40E_QINT_TQCTL_NEXTQ_INDX_MASK);
wr32(hw, I40E_QINT_TQCTL(qp), val);
}
}
static void i40e_free_q_vector(struct i40e_vsi *vsi, int v_idx)
{
struct i40e_q_vector *q_vector = vsi->q_vectors[v_idx];
struct i40e_ring *ring;
if (!q_vector)
return;
i40e_for_each_ring(ring, q_vector->tx)
ring->q_vector = NULL;
i40e_for_each_ring(ring, q_vector->rx)
ring->q_vector = NULL;
if (vsi->netdev)
netif_napi_del(&q_vector->napi);
vsi->q_vectors[v_idx] = NULL;
kfree_rcu(q_vector, rcu);
}
static void i40e_vsi_free_q_vectors(struct i40e_vsi *vsi)
{
int v_idx;
for (v_idx = 0; v_idx < vsi->num_q_vectors; v_idx++)
i40e_free_q_vector(vsi, v_idx);
}
static void i40e_reset_interrupt_capability(struct i40e_pf *pf)
{
if (pf->flags & I40E_FLAG_MSIX_ENABLED) {
pci_disable_msix(pf->pdev);
kfree(pf->msix_entries);
pf->msix_entries = NULL;
kfree(pf->irq_pile);
pf->irq_pile = NULL;
} else if (pf->flags & I40E_FLAG_MSI_ENABLED) {
pci_disable_msi(pf->pdev);
}
pf->flags &= ~(I40E_FLAG_MSIX_ENABLED | I40E_FLAG_MSI_ENABLED);
}
static void i40e_clear_interrupt_scheme(struct i40e_pf *pf)
{
int i;
i40e_stop_misc_vector(pf);
if (pf->flags & I40E_FLAG_MSIX_ENABLED && pf->msix_entries) {
synchronize_irq(pf->msix_entries[0].vector);
free_irq(pf->msix_entries[0].vector, pf);
}
i40e_put_lump(pf->irq_pile, pf->iwarp_base_vector,
I40E_IWARP_IRQ_PILE_ID);
i40e_put_lump(pf->irq_pile, 0, I40E_PILE_VALID_BIT-1);
for (i = 0; i < pf->num_alloc_vsi; i++)
if (pf->vsi[i])
i40e_vsi_free_q_vectors(pf->vsi[i]);
i40e_reset_interrupt_capability(pf);
}
static void i40e_napi_enable_all(struct i40e_vsi *vsi)
{
int q_idx;
if (!vsi->netdev)
return;
for (q_idx = 0; q_idx < vsi->num_q_vectors; q_idx++) {
struct i40e_q_vector *q_vector = vsi->q_vectors[q_idx];
if (q_vector->rx.ring || q_vector->tx.ring)
napi_enable(&q_vector->napi);
}
}
static void i40e_napi_disable_all(struct i40e_vsi *vsi)
{
int q_idx;
if (!vsi->netdev)
return;
for (q_idx = 0; q_idx < vsi->num_q_vectors; q_idx++) {
struct i40e_q_vector *q_vector = vsi->q_vectors[q_idx];
if (q_vector->rx.ring || q_vector->tx.ring)
napi_disable(&q_vector->napi);
}
}
static void i40e_vsi_close(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
if (!test_and_set_bit(__I40E_VSI_DOWN, vsi->state))
i40e_down(vsi);
i40e_vsi_free_irq(vsi);
i40e_vsi_free_tx_resources(vsi);
i40e_vsi_free_rx_resources(vsi);
vsi->current_netdev_flags = 0;
pf->flags |= I40E_FLAG_SERVICE_CLIENT_REQUESTED;
if (test_bit(__I40E_RESET_RECOVERY_PENDING, pf->state))
pf->flags |= I40E_FLAG_CLIENT_RESET;
}
static void i40e_quiesce_vsi(struct i40e_vsi *vsi)
{
if (test_bit(__I40E_VSI_DOWN, vsi->state))
return;
set_bit(__I40E_VSI_NEEDS_RESTART, vsi->state);
if (vsi->netdev && netif_running(vsi->netdev))
vsi->netdev->netdev_ops->ndo_stop(vsi->netdev);
else
i40e_vsi_close(vsi);
}
static void i40e_unquiesce_vsi(struct i40e_vsi *vsi)
{
if (!test_and_clear_bit(__I40E_VSI_NEEDS_RESTART, vsi->state))
return;
if (vsi->netdev && netif_running(vsi->netdev))
vsi->netdev->netdev_ops->ndo_open(vsi->netdev);
else
i40e_vsi_open(vsi);
}
static void i40e_pf_quiesce_all_vsi(struct i40e_pf *pf)
{
int v;
for (v = 0; v < pf->num_alloc_vsi; v++) {
if (pf->vsi[v])
i40e_quiesce_vsi(pf->vsi[v]);
}
}
static void i40e_pf_unquiesce_all_vsi(struct i40e_pf *pf)
{
int v;
for (v = 0; v < pf->num_alloc_vsi; v++) {
if (pf->vsi[v])
i40e_unquiesce_vsi(pf->vsi[v]);
}
}
int i40e_vsi_wait_queues_disabled(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
int i, pf_q, ret;
pf_q = vsi->base_queue;
for (i = 0; i < vsi->num_queue_pairs; i++, pf_q++) {
ret = i40e_pf_txq_wait(pf, pf_q, false);
if (ret) {
dev_info(&pf->pdev->dev,
"VSI seid %d Tx ring %d disable timeout\n",
vsi->seid, pf_q);
return ret;
}
ret = i40e_pf_rxq_wait(pf, pf_q, false);
if (ret) {
dev_info(&pf->pdev->dev,
"VSI seid %d Rx ring %d disable timeout\n",
vsi->seid, pf_q);
return ret;
}
}
return 0;
}
static int i40e_pf_wait_queues_disabled(struct i40e_pf *pf)
{
int v, ret = 0;
for (v = 0; v < pf->hw.func_caps.num_vsis; v++) {
if (pf->vsi[v]) {
ret = i40e_vsi_wait_queues_disabled(pf->vsi[v]);
if (ret)
break;
}
}
return ret;
}
static void i40e_detect_recover_hung_queue(int q_idx, struct i40e_vsi *vsi)
{
struct i40e_ring *tx_ring = NULL;
struct i40e_pf *pf;
u32 val, tx_pending;
int i;
pf = vsi->back;
for (i = 0; i < vsi->num_queue_pairs; i++) {
if (vsi->tx_rings[i] && vsi->tx_rings[i]->desc) {
if (q_idx == vsi->tx_rings[i]->queue_index) {
tx_ring = vsi->tx_rings[i];
break;
}
}
}
if (!tx_ring)
return;
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
val = rd32(&pf->hw,
I40E_PFINT_DYN_CTLN(tx_ring->q_vector->v_idx +
tx_ring->vsi->base_vector - 1));
else
val = rd32(&pf->hw, I40E_PFINT_DYN_CTL0);
tx_pending = i40e_get_tx_pending(tx_ring);
if (tx_pending && (!(val & I40E_PFINT_DYN_CTLN_INTENA_MASK)))
i40e_force_wb(vsi, tx_ring->q_vector);
}
static void i40e_detect_recover_hung(struct i40e_pf *pf)
{
struct net_device *netdev;
struct i40e_vsi *vsi;
int i;
vsi = pf->vsi[pf->lan_vsi];
if (!vsi)
return;
if (test_bit(__I40E_VSI_DOWN, vsi->back->state) ||
test_bit(__I40E_RESET_RECOVERY_PENDING, vsi->back->state))
return;
if (vsi->type != I40E_VSI_MAIN)
return;
netdev = vsi->netdev;
if (!netdev)
return;
if (!netif_carrier_ok(netdev))
return;
for (i = 0; i < netdev->num_tx_queues; i++) {
struct netdev_queue *q;
q = netdev_get_tx_queue(netdev, i);
if (q)
i40e_detect_recover_hung_queue(i, vsi);
}
}
static u8 i40e_get_iscsi_tc_map(struct i40e_pf *pf)
{
struct i40e_dcb_app_priority_table app;
struct i40e_hw *hw = &pf->hw;
u8 enabled_tc = 1;
u8 tc, i;
struct i40e_dcbx_config *dcbcfg = &hw->local_dcbx_config;
for (i = 0; i < dcbcfg->numapps; i++) {
app = dcbcfg->app[i];
if (app.selector == I40E_APP_SEL_TCPIP &&
app.protocolid == I40E_APP_PROTOID_ISCSI) {
tc = dcbcfg->etscfg.prioritytable[app.priority];
enabled_tc |= BIT(tc);
break;
}
}
return enabled_tc;
}
static u8 i40e_dcb_get_num_tc(struct i40e_dcbx_config *dcbcfg)
{
int i, tc_unused = 0;
u8 num_tc = 0;
u8 ret = 0;
for (i = 0; i < I40E_MAX_USER_PRIORITY; i++)
num_tc |= BIT(dcbcfg->etscfg.prioritytable[i]);
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (num_tc & BIT(i)) {
if (!tc_unused) {
ret++;
} else {
pr_err("Non-contiguous TC - Disabling DCB\n");
return 1;
}
} else {
tc_unused = 1;
}
}
if (!ret)
ret = 1;
return ret;
}
static u8 i40e_dcb_get_enabled_tc(struct i40e_dcbx_config *dcbcfg)
{
u8 num_tc = i40e_dcb_get_num_tc(dcbcfg);
u8 enabled_tc = 1;
u8 i;
for (i = 0; i < num_tc; i++)
enabled_tc |= BIT(i);
return enabled_tc;
}
static u8 i40e_pf_get_num_tc(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
u8 i, enabled_tc = 1;
u8 num_tc = 0;
struct i40e_dcbx_config *dcbcfg = &hw->local_dcbx_config;
if (!(pf->flags & I40E_FLAG_DCB_ENABLED))
return 1;
if (!(pf->flags & I40E_FLAG_MFP_ENABLED))
return i40e_dcb_get_num_tc(dcbcfg);
if (pf->hw.func_caps.iscsi)
enabled_tc = i40e_get_iscsi_tc_map(pf);
else
return 1;
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (enabled_tc & BIT(i))
num_tc++;
}
return num_tc;
}
static u8 i40e_pf_get_tc_map(struct i40e_pf *pf)
{
if (!(pf->flags & I40E_FLAG_DCB_ENABLED))
return I40E_DEFAULT_TRAFFIC_CLASS;
if (!(pf->flags & I40E_FLAG_MFP_ENABLED))
return i40e_dcb_get_enabled_tc(&pf->hw.local_dcbx_config);
if (pf->hw.func_caps.iscsi)
return i40e_get_iscsi_tc_map(pf);
else
return I40E_DEFAULT_TRAFFIC_CLASS;
}
static int i40e_vsi_get_bw_info(struct i40e_vsi *vsi)
{
struct i40e_aqc_query_vsi_ets_sla_config_resp bw_ets_config = {0};
struct i40e_aqc_query_vsi_bw_config_resp bw_config = {0};
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
i40e_status ret;
u32 tc_bw_max;
int i;
ret = i40e_aq_query_vsi_bw_config(hw, vsi->seid, &bw_config, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't get PF vsi bw config, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
return -EINVAL;
}
ret = i40e_aq_query_vsi_ets_sla_config(hw, vsi->seid, &bw_ets_config,
NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't get PF vsi ets bw config, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
return -EINVAL;
}
if (bw_config.tc_valid_bits != bw_ets_config.tc_valid_bits) {
dev_info(&pf->pdev->dev,
"Enabled TCs mismatch from querying VSI BW info 0x%08x 0x%08x\n",
bw_config.tc_valid_bits,
bw_ets_config.tc_valid_bits);
}
vsi->bw_limit = le16_to_cpu(bw_config.port_bw_limit);
vsi->bw_max_quanta = bw_config.max_bw;
tc_bw_max = le16_to_cpu(bw_ets_config.tc_bw_max[0]) |
(le16_to_cpu(bw_ets_config.tc_bw_max[1]) << 16);
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
vsi->bw_ets_share_credits[i] = bw_ets_config.share_credits[i];
vsi->bw_ets_limit_credits[i] =
le16_to_cpu(bw_ets_config.credits[i]);
vsi->bw_ets_max_quanta[i] = (u8)((tc_bw_max >> (i*4)) & 0x7);
}
return 0;
}
static int i40e_vsi_configure_bw_alloc(struct i40e_vsi *vsi, u8 enabled_tc,
u8 *bw_share)
{
struct i40e_aqc_configure_vsi_tc_bw_data bw_data;
i40e_status ret;
int i;
bw_data.tc_valid_bits = enabled_tc;
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++)
bw_data.tc_bw_credits[i] = bw_share[i];
ret = i40e_aq_config_vsi_tc_bw(&vsi->back->hw, vsi->seid, &bw_data,
NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"AQ command Config VSI BW allocation per TC failed = %d\n",
vsi->back->hw.aq.asq_last_status);
return -EINVAL;
}
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++)
vsi->info.qs_handle[i] = bw_data.qs_handles[i];
return 0;
}
static void i40e_vsi_config_netdev_tc(struct i40e_vsi *vsi, u8 enabled_tc)
{
struct net_device *netdev = vsi->netdev;
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
u8 netdev_tc = 0;
int i;
struct i40e_dcbx_config *dcbcfg = &hw->local_dcbx_config;
if (!netdev)
return;
if (!enabled_tc) {
netdev_reset_tc(netdev);
return;
}
if (netdev_set_num_tc(netdev, vsi->tc_config.numtc))
return;
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (vsi->tc_config.enabled_tc & BIT(i))
netdev_set_tc_queue(netdev,
vsi->tc_config.tc_info[i].netdev_tc,
vsi->tc_config.tc_info[i].qcount,
vsi->tc_config.tc_info[i].qoffset);
}
for (i = 0; i < I40E_MAX_USER_PRIORITY; i++) {
u8 ets_tc = dcbcfg->etscfg.prioritytable[i];
netdev_tc = vsi->tc_config.tc_info[ets_tc].netdev_tc;
netdev_set_prio_tc_map(netdev, i, netdev_tc);
}
}
static void i40e_vsi_update_queue_map(struct i40e_vsi *vsi,
struct i40e_vsi_context *ctxt)
{
vsi->info.mapping_flags = ctxt->info.mapping_flags;
memcpy(&vsi->info.queue_mapping,
&ctxt->info.queue_mapping, sizeof(vsi->info.queue_mapping));
memcpy(&vsi->info.tc_mapping, ctxt->info.tc_mapping,
sizeof(vsi->info.tc_mapping));
}
static int i40e_vsi_config_tc(struct i40e_vsi *vsi, u8 enabled_tc)
{
u8 bw_share[I40E_MAX_TRAFFIC_CLASS] = {0};
struct i40e_vsi_context ctxt;
int ret = 0;
int i;
if (vsi->tc_config.enabled_tc == enabled_tc)
return ret;
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (enabled_tc & BIT(i))
bw_share[i] = 1;
}
ret = i40e_vsi_configure_bw_alloc(vsi, enabled_tc, bw_share);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"Failed configuring TC map %d for VSI %d\n",
enabled_tc, vsi->seid);
goto out;
}
ctxt.seid = vsi->seid;
ctxt.pf_num = vsi->back->hw.pf_id;
ctxt.vf_num = 0;
ctxt.uplink_seid = vsi->uplink_seid;
ctxt.info = vsi->info;
i40e_vsi_setup_queue_map(vsi, &ctxt, enabled_tc, false);
if (vsi->back->flags & I40E_FLAG_IWARP_ENABLED) {
ctxt.info.valid_sections |=
cpu_to_le16(I40E_AQ_VSI_PROP_QUEUE_OPT_VALID);
ctxt.info.queueing_opt_flags |= I40E_AQ_VSI_QUE_OPT_TCP_ENA;
}
ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"Update vsi tc config failed, err %s aq_err %s\n",
i40e_stat_str(&vsi->back->hw, ret),
i40e_aq_str(&vsi->back->hw,
vsi->back->hw.aq.asq_last_status));
goto out;
}
i40e_vsi_update_queue_map(vsi, &ctxt);
vsi->info.valid_sections = 0;
ret = i40e_vsi_get_bw_info(vsi);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"Failed updating vsi bw info, err %s aq_err %s\n",
i40e_stat_str(&vsi->back->hw, ret),
i40e_aq_str(&vsi->back->hw,
vsi->back->hw.aq.asq_last_status));
goto out;
}
i40e_vsi_config_netdev_tc(vsi, enabled_tc);
out:
return ret;
}
int i40e_veb_config_tc(struct i40e_veb *veb, u8 enabled_tc)
{
struct i40e_aqc_configure_switching_comp_bw_config_data bw_data = {0};
struct i40e_pf *pf = veb->pf;
int ret = 0;
int i;
if (!enabled_tc || veb->enabled_tc == enabled_tc)
return ret;
bw_data.tc_valid_bits = enabled_tc;
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (enabled_tc & BIT(i))
bw_data.tc_bw_share_credits[i] = 1;
}
ret = i40e_aq_config_switch_comp_bw_config(&pf->hw, veb->seid,
&bw_data, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"VEB bw config failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
goto out;
}
ret = i40e_veb_get_bw_info(veb);
if (ret) {
dev_info(&pf->pdev->dev,
"Failed getting veb bw config, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
}
out:
return ret;
}
static void i40e_dcb_reconfigure(struct i40e_pf *pf)
{
u8 tc_map = 0;
int ret;
u8 v;
tc_map = i40e_pf_get_tc_map(pf);
for (v = 0; v < I40E_MAX_VEB; v++) {
if (!pf->veb[v])
continue;
ret = i40e_veb_config_tc(pf->veb[v], tc_map);
if (ret) {
dev_info(&pf->pdev->dev,
"Failed configuring TC for VEB seid=%d\n",
pf->veb[v]->seid);
}
}
for (v = 0; v < pf->num_alloc_vsi; v++) {
if (!pf->vsi[v])
continue;
if (v == pf->lan_vsi)
tc_map = i40e_pf_get_tc_map(pf);
else
tc_map = I40E_DEFAULT_TRAFFIC_CLASS;
ret = i40e_vsi_config_tc(pf->vsi[v], tc_map);
if (ret) {
dev_info(&pf->pdev->dev,
"Failed configuring TC for VSI seid=%d\n",
pf->vsi[v]->seid);
} else {
i40e_vsi_map_rings_to_vectors(pf->vsi[v]);
if (pf->vsi[v]->netdev)
i40e_dcbnl_set_all(pf->vsi[v]);
}
}
}
static int i40e_resume_port_tx(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
int ret;
ret = i40e_aq_resume_port_tx(hw, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"Resume Port Tx failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
set_bit(__I40E_PF_RESET_REQUESTED, pf->state);
i40e_service_event_schedule(pf);
}
return ret;
}
static int i40e_init_pf_dcb(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
int err = 0;
if (pf->flags & I40E_FLAG_NO_DCB_SUPPORT)
goto out;
err = i40e_init_dcb(hw);
if (!err) {
if ((!hw->func_caps.dcb) ||
(hw->dcbx_status == I40E_DCBX_STATUS_DISABLED)) {
dev_info(&pf->pdev->dev,
"DCBX offload is not supported or is disabled for this PF.\n");
} else {
pf->dcbx_cap = DCB_CAP_DCBX_LLD_MANAGED |
DCB_CAP_DCBX_VER_IEEE;
pf->flags |= I40E_FLAG_DCB_CAPABLE;
if (i40e_dcb_get_num_tc(&hw->local_dcbx_config) > 1)
pf->flags |= I40E_FLAG_DCB_ENABLED;
else
pf->flags &= ~I40E_FLAG_DCB_ENABLED;
dev_dbg(&pf->pdev->dev,
"DCBX offload is supported for this PF.\n");
}
} else {
dev_info(&pf->pdev->dev,
"Query for DCB configuration failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, err),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
}
out:
return err;
}
void i40e_print_link_message(struct i40e_vsi *vsi, bool isup)
{
enum i40e_aq_link_speed new_speed;
char *speed = "Unknown";
char *fc = "Unknown";
char *fec = "";
char *an = "";
new_speed = vsi->back->hw.phy.link_info.link_speed;
if ((vsi->current_isup == isup) && (vsi->current_speed == new_speed))
return;
vsi->current_isup = isup;
vsi->current_speed = new_speed;
if (!isup) {
netdev_info(vsi->netdev, "NIC Link is Down\n");
return;
}
if (vsi->back->hw.func_caps.npar_enable &&
(vsi->back->hw.phy.link_info.link_speed == I40E_LINK_SPEED_1GB ||
vsi->back->hw.phy.link_info.link_speed == I40E_LINK_SPEED_100MB))
netdev_warn(vsi->netdev,
"The partition detected link speed that is less than 10Gbps\n");
switch (vsi->back->hw.phy.link_info.link_speed) {
case I40E_LINK_SPEED_40GB:
speed = "40 G";
break;
case I40E_LINK_SPEED_20GB:
speed = "20 G";
break;
case I40E_LINK_SPEED_25GB:
speed = "25 G";
break;
case I40E_LINK_SPEED_10GB:
speed = "10 G";
break;
case I40E_LINK_SPEED_1GB:
speed = "1000 M";
break;
case I40E_LINK_SPEED_100MB:
speed = "100 M";
break;
default:
break;
}
switch (vsi->back->hw.fc.current_mode) {
case I40E_FC_FULL:
fc = "RX/TX";
break;
case I40E_FC_TX_PAUSE:
fc = "TX";
break;
case I40E_FC_RX_PAUSE:
fc = "RX";
break;
default:
fc = "None";
break;
}
if (vsi->back->hw.phy.link_info.link_speed == I40E_LINK_SPEED_25GB) {
fec = ", FEC: None";
an = ", Autoneg: False";
if (vsi->back->hw.phy.link_info.an_info & I40E_AQ_AN_COMPLETED)
an = ", Autoneg: True";
if (vsi->back->hw.phy.link_info.fec_info &
I40E_AQ_CONFIG_FEC_KR_ENA)
fec = ", FEC: CL74 FC-FEC/BASE-R";
else if (vsi->back->hw.phy.link_info.fec_info &
I40E_AQ_CONFIG_FEC_RS_ENA)
fec = ", FEC: CL108 RS-FEC";
}
netdev_info(vsi->netdev, "NIC Link is Up, %sbps Full Duplex%s%s, Flow Control: %s\n",
speed, fec, an, fc);
}
static int i40e_up_complete(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
int err;
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
i40e_vsi_configure_msix(vsi);
else
i40e_configure_msi_and_legacy(vsi);
err = i40e_vsi_start_rings(vsi);
if (err)
return err;
clear_bit(__I40E_VSI_DOWN, vsi->state);
i40e_napi_enable_all(vsi);
i40e_vsi_enable_irq(vsi);
if ((pf->hw.phy.link_info.link_info & I40E_AQ_LINK_UP) &&
(vsi->netdev)) {
i40e_print_link_message(vsi, true);
netif_tx_start_all_queues(vsi->netdev);
netif_carrier_on(vsi->netdev);
} else if (vsi->netdev) {
i40e_print_link_message(vsi, false);
if ((pf->hw.phy.link_info.link_info &
I40E_AQ_MEDIA_AVAILABLE) &&
(!(pf->hw.phy.link_info.an_info &
I40E_AQ_QUALIFIED_MODULE)))
netdev_err(vsi->netdev,
"the driver failed to link because an unqualified module was detected.");
}
if (vsi->type == I40E_VSI_FDIR) {
pf->fd_add_err = 0;
pf->fd_atr_cnt = 0;
i40e_fdir_filter_restore(vsi);
}
pf->flags |= I40E_FLAG_SERVICE_CLIENT_REQUESTED;
i40e_service_event_schedule(pf);
return 0;
}
static void i40e_vsi_reinit_locked(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
WARN_ON(in_interrupt());
while (test_and_set_bit(__I40E_CONFIG_BUSY, pf->state))
usleep_range(1000, 2000);
i40e_down(vsi);
i40e_up(vsi);
clear_bit(__I40E_CONFIG_BUSY, pf->state);
}
int i40e_up(struct i40e_vsi *vsi)
{
int err;
err = i40e_vsi_configure(vsi);
if (!err)
err = i40e_up_complete(vsi);
return err;
}
void i40e_down(struct i40e_vsi *vsi)
{
int i;
if (vsi->netdev) {
netif_carrier_off(vsi->netdev);
netif_tx_disable(vsi->netdev);
}
i40e_vsi_disable_irq(vsi);
i40e_vsi_stop_rings(vsi);
i40e_napi_disable_all(vsi);
for (i = 0; i < vsi->num_queue_pairs; i++) {
i40e_clean_tx_ring(vsi->tx_rings[i]);
i40e_clean_rx_ring(vsi->rx_rings[i]);
}
}
static int i40e_setup_tc(struct net_device *netdev, u8 tc)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
u8 enabled_tc = 0;
int ret = -EINVAL;
int i;
if (!(pf->flags & I40E_FLAG_DCB_ENABLED)) {
netdev_info(netdev, "DCB is not enabled for adapter\n");
goto exit;
}
if (pf->flags & I40E_FLAG_MFP_ENABLED) {
netdev_info(netdev, "Configuring TC not supported in MFP mode\n");
goto exit;
}
if (tc > i40e_pf_get_num_tc(pf)) {
netdev_info(netdev, "TC count greater than enabled on link for adapter\n");
goto exit;
}
for (i = 0; i < tc; i++)
enabled_tc |= BIT(i);
if (enabled_tc == vsi->tc_config.enabled_tc)
return 0;
i40e_quiesce_vsi(vsi);
ret = i40e_vsi_config_tc(vsi, enabled_tc);
if (ret) {
netdev_info(netdev, "Failed configuring TC for VSI seid=%d\n",
vsi->seid);
goto exit;
}
i40e_unquiesce_vsi(vsi);
exit:
return ret;
}
static int __i40e_setup_tc(struct net_device *netdev, u32 handle, __be16 proto,
struct tc_to_netdev *tc)
{
if (tc->type != TC_SETUP_MQPRIO)
return -EINVAL;
tc->mqprio->hw = TC_MQPRIO_HW_OFFLOAD_TCS;
return i40e_setup_tc(netdev, tc->mqprio->num_tc);
}
int i40e_open(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
int err;
if (test_bit(__I40E_TESTING, pf->state) ||
test_bit(__I40E_BAD_EEPROM, pf->state))
return -EBUSY;
netif_carrier_off(netdev);
err = i40e_vsi_open(vsi);
if (err)
return err;
wr32(&pf->hw, I40E_GLLAN_TSOMSK_F, be32_to_cpu(TCP_FLAG_PSH |
TCP_FLAG_FIN) >> 16);
wr32(&pf->hw, I40E_GLLAN_TSOMSK_M, be32_to_cpu(TCP_FLAG_PSH |
TCP_FLAG_FIN |
TCP_FLAG_CWR) >> 16);
wr32(&pf->hw, I40E_GLLAN_TSOMSK_L, be32_to_cpu(TCP_FLAG_CWR) >> 16);
udp_tunnel_get_rx_info(netdev);
return 0;
}
int i40e_vsi_open(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
char int_name[I40E_INT_NAME_STR_LEN];
int err;
err = i40e_vsi_setup_tx_resources(vsi);
if (err)
goto err_setup_tx;
err = i40e_vsi_setup_rx_resources(vsi);
if (err)
goto err_setup_rx;
err = i40e_vsi_configure(vsi);
if (err)
goto err_setup_rx;
if (vsi->netdev) {
snprintf(int_name, sizeof(int_name) - 1, "%s-%s",
dev_driver_string(&pf->pdev->dev), vsi->netdev->name);
err = i40e_vsi_request_irq(vsi, int_name);
if (err)
goto err_setup_rx;
err = netif_set_real_num_tx_queues(vsi->netdev,
vsi->num_queue_pairs);
if (err)
goto err_set_queues;
err = netif_set_real_num_rx_queues(vsi->netdev,
vsi->num_queue_pairs);
if (err)
goto err_set_queues;
} else if (vsi->type == I40E_VSI_FDIR) {
snprintf(int_name, sizeof(int_name) - 1, "%s-%s:fdir",
dev_driver_string(&pf->pdev->dev),
dev_name(&pf->pdev->dev));
err = i40e_vsi_request_irq(vsi, int_name);
} else {
err = -EINVAL;
goto err_setup_rx;
}
err = i40e_up_complete(vsi);
if (err)
goto err_up_complete;
return 0;
err_up_complete:
i40e_down(vsi);
err_set_queues:
i40e_vsi_free_irq(vsi);
err_setup_rx:
i40e_vsi_free_rx_resources(vsi);
err_setup_tx:
i40e_vsi_free_tx_resources(vsi);
if (vsi == pf->vsi[pf->lan_vsi])
i40e_do_reset(pf, BIT_ULL(__I40E_PF_RESET_REQUESTED), true);
return err;
}
static void i40e_fdir_filter_exit(struct i40e_pf *pf)
{
struct i40e_fdir_filter *filter;
struct i40e_flex_pit *pit_entry, *tmp;
struct hlist_node *node2;
hlist_for_each_entry_safe(filter, node2,
&pf->fdir_filter_list, fdir_node) {
hlist_del(&filter->fdir_node);
kfree(filter);
}
list_for_each_entry_safe(pit_entry, tmp, &pf->l3_flex_pit_list, list) {
list_del(&pit_entry->list);
kfree(pit_entry);
}
INIT_LIST_HEAD(&pf->l3_flex_pit_list);
list_for_each_entry_safe(pit_entry, tmp, &pf->l4_flex_pit_list, list) {
list_del(&pit_entry->list);
kfree(pit_entry);
}
INIT_LIST_HEAD(&pf->l4_flex_pit_list);
pf->fdir_pf_active_filters = 0;
pf->fd_tcp4_filter_cnt = 0;
pf->fd_udp4_filter_cnt = 0;
pf->fd_sctp4_filter_cnt = 0;
pf->fd_ip4_filter_cnt = 0;
i40e_write_fd_input_set(pf, I40E_FILTER_PCTYPE_NONF_IPV4_TCP,
I40E_L3_SRC_MASK | I40E_L3_DST_MASK |
I40E_L4_SRC_MASK | I40E_L4_DST_MASK);
i40e_write_fd_input_set(pf, I40E_FILTER_PCTYPE_NONF_IPV4_UDP,
I40E_L3_SRC_MASK | I40E_L3_DST_MASK |
I40E_L4_SRC_MASK | I40E_L4_DST_MASK);
i40e_write_fd_input_set(pf, I40E_FILTER_PCTYPE_NONF_IPV4_SCTP,
I40E_L3_SRC_MASK | I40E_L3_DST_MASK |
I40E_L4_SRC_MASK | I40E_L4_DST_MASK);
i40e_write_fd_input_set(pf, I40E_FILTER_PCTYPE_NONF_IPV4_OTHER,
I40E_L3_SRC_MASK | I40E_L3_DST_MASK);
}
int i40e_close(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
i40e_vsi_close(vsi);
return 0;
}
void i40e_do_reset(struct i40e_pf *pf, u32 reset_flags, bool lock_acquired)
{
u32 val;
WARN_ON(in_interrupt());
if (reset_flags & BIT_ULL(__I40E_GLOBAL_RESET_REQUESTED)) {
dev_dbg(&pf->pdev->dev, "GlobalR requested\n");
val = rd32(&pf->hw, I40E_GLGEN_RTRIG);
val |= I40E_GLGEN_RTRIG_GLOBR_MASK;
wr32(&pf->hw, I40E_GLGEN_RTRIG, val);
} else if (reset_flags & BIT_ULL(__I40E_CORE_RESET_REQUESTED)) {
dev_dbg(&pf->pdev->dev, "CoreR requested\n");
val = rd32(&pf->hw, I40E_GLGEN_RTRIG);
val |= I40E_GLGEN_RTRIG_CORER_MASK;
wr32(&pf->hw, I40E_GLGEN_RTRIG, val);
i40e_flush(&pf->hw);
} else if (reset_flags & BIT_ULL(__I40E_PF_RESET_REQUESTED)) {
dev_dbg(&pf->pdev->dev, "PFR requested\n");
i40e_handle_reset_warning(pf, lock_acquired);
} else if (reset_flags & BIT_ULL(__I40E_REINIT_REQUESTED)) {
int v;
dev_info(&pf->pdev->dev,
"VSI reinit requested\n");
for (v = 0; v < pf->num_alloc_vsi; v++) {
struct i40e_vsi *vsi = pf->vsi[v];
if (vsi != NULL &&
test_and_clear_bit(__I40E_VSI_REINIT_REQUESTED,
vsi->state))
i40e_vsi_reinit_locked(pf->vsi[v]);
}
} else if (reset_flags & BIT_ULL(__I40E_DOWN_REQUESTED)) {
int v;
dev_info(&pf->pdev->dev, "VSI down requested\n");
for (v = 0; v < pf->num_alloc_vsi; v++) {
struct i40e_vsi *vsi = pf->vsi[v];
if (vsi != NULL &&
test_and_clear_bit(__I40E_VSI_DOWN_REQUESTED,
vsi->state)) {
set_bit(__I40E_VSI_DOWN, vsi->state);
i40e_down(vsi);
}
}
} else {
dev_info(&pf->pdev->dev,
"bad reset request 0x%08x\n", reset_flags);
}
}
bool i40e_dcb_need_reconfig(struct i40e_pf *pf,
struct i40e_dcbx_config *old_cfg,
struct i40e_dcbx_config *new_cfg)
{
bool need_reconfig = false;
if (memcmp(&new_cfg->etscfg,
&old_cfg->etscfg,
sizeof(new_cfg->etscfg))) {
if (memcmp(&new_cfg->etscfg.prioritytable,
&old_cfg->etscfg.prioritytable,
sizeof(new_cfg->etscfg.prioritytable))) {
need_reconfig = true;
dev_dbg(&pf->pdev->dev, "ETS UP2TC changed.\n");
}
if (memcmp(&new_cfg->etscfg.tcbwtable,
&old_cfg->etscfg.tcbwtable,
sizeof(new_cfg->etscfg.tcbwtable)))
dev_dbg(&pf->pdev->dev, "ETS TC BW Table changed.\n");
if (memcmp(&new_cfg->etscfg.tsatable,
&old_cfg->etscfg.tsatable,
sizeof(new_cfg->etscfg.tsatable)))
dev_dbg(&pf->pdev->dev, "ETS TSA Table changed.\n");
}
if (memcmp(&new_cfg->pfc,
&old_cfg->pfc,
sizeof(new_cfg->pfc))) {
need_reconfig = true;
dev_dbg(&pf->pdev->dev, "PFC config change detected.\n");
}
if (memcmp(&new_cfg->app,
&old_cfg->app,
sizeof(new_cfg->app))) {
need_reconfig = true;
dev_dbg(&pf->pdev->dev, "APP Table change detected.\n");
}
dev_dbg(&pf->pdev->dev, "dcb need_reconfig=%d\n", need_reconfig);
return need_reconfig;
}
static int i40e_handle_lldp_event(struct i40e_pf *pf,
struct i40e_arq_event_info *e)
{
struct i40e_aqc_lldp_get_mib *mib =
(struct i40e_aqc_lldp_get_mib *)&e->desc.params.raw;
struct i40e_hw *hw = &pf->hw;
struct i40e_dcbx_config tmp_dcbx_cfg;
bool need_reconfig = false;
int ret = 0;
u8 type;
if (!(pf->flags & I40E_FLAG_DCB_CAPABLE))
return ret;
type = ((mib->type >> I40E_AQ_LLDP_BRIDGE_TYPE_SHIFT)
& I40E_AQ_LLDP_BRIDGE_TYPE_MASK);
dev_dbg(&pf->pdev->dev, "LLDP event mib bridge type 0x%x\n", type);
if (type != I40E_AQ_LLDP_BRIDGE_TYPE_NEAREST_BRIDGE)
return ret;
type = mib->type & I40E_AQ_LLDP_MIB_TYPE_MASK;
dev_dbg(&pf->pdev->dev,
"LLDP event mib type %s\n", type ? "remote" : "local");
if (type == I40E_AQ_LLDP_MIB_REMOTE) {
ret = i40e_aq_get_dcb_config(hw, I40E_AQ_LLDP_MIB_REMOTE,
I40E_AQ_LLDP_BRIDGE_TYPE_NEAREST_BRIDGE,
&hw->remote_dcbx_config);
goto exit;
}
tmp_dcbx_cfg = hw->local_dcbx_config;
memset(&hw->local_dcbx_config, 0, sizeof(hw->local_dcbx_config));
ret = i40e_get_dcb_config(&pf->hw);
if (ret) {
dev_info(&pf->pdev->dev,
"Failed querying DCB configuration data from firmware, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
goto exit;
}
if (!memcmp(&tmp_dcbx_cfg, &hw->local_dcbx_config,
sizeof(tmp_dcbx_cfg))) {
dev_dbg(&pf->pdev->dev, "No change detected in DCBX configuration.\n");
goto exit;
}
need_reconfig = i40e_dcb_need_reconfig(pf, &tmp_dcbx_cfg,
&hw->local_dcbx_config);
i40e_dcbnl_flush_apps(pf, &tmp_dcbx_cfg, &hw->local_dcbx_config);
if (!need_reconfig)
goto exit;
if (i40e_dcb_get_num_tc(&hw->local_dcbx_config) > 1)
pf->flags |= I40E_FLAG_DCB_ENABLED;
else
pf->flags &= ~I40E_FLAG_DCB_ENABLED;
set_bit(__I40E_PORT_SUSPENDED, pf->state);
i40e_pf_quiesce_all_vsi(pf);
i40e_dcb_reconfigure(pf);
ret = i40e_resume_port_tx(pf);
clear_bit(__I40E_PORT_SUSPENDED, pf->state);
if (ret)
goto exit;
ret = i40e_pf_wait_queues_disabled(pf);
if (ret) {
set_bit(__I40E_PF_RESET_REQUESTED, pf->state);
i40e_service_event_schedule(pf);
} else {
i40e_pf_unquiesce_all_vsi(pf);
pf->flags |= (I40E_FLAG_SERVICE_CLIENT_REQUESTED |
I40E_FLAG_CLIENT_L2_CHANGE);
}
exit:
return ret;
}
void i40e_do_reset_safe(struct i40e_pf *pf, u32 reset_flags)
{
rtnl_lock();
i40e_do_reset(pf, reset_flags, true);
rtnl_unlock();
}
static void i40e_handle_lan_overflow_event(struct i40e_pf *pf,
struct i40e_arq_event_info *e)
{
struct i40e_aqc_lan_overflow *data =
(struct i40e_aqc_lan_overflow *)&e->desc.params.raw;
u32 queue = le32_to_cpu(data->prtdcb_rupto);
u32 qtx_ctl = le32_to_cpu(data->otx_ctl);
struct i40e_hw *hw = &pf->hw;
struct i40e_vf *vf;
u16 vf_id;
dev_dbg(&pf->pdev->dev, "overflow Rx Queue Number = %d QTX_CTL=0x%08x\n",
queue, qtx_ctl);
if (((qtx_ctl & I40E_QTX_CTL_PFVF_Q_MASK)
>> I40E_QTX_CTL_PFVF_Q_SHIFT) == I40E_QTX_CTL_VF_QUEUE) {
vf_id = (u16)((qtx_ctl & I40E_QTX_CTL_VFVM_INDX_MASK)
>> I40E_QTX_CTL_VFVM_INDX_SHIFT);
vf_id -= hw->func_caps.vf_base_id;
vf = &pf->vf[vf_id];
i40e_vc_notify_vf_reset(vf);
msleep(20);
i40e_reset_vf(vf, false);
}
}
u32 i40e_get_cur_guaranteed_fd_count(struct i40e_pf *pf)
{
u32 val, fcnt_prog;
val = rd32(&pf->hw, I40E_PFQF_FDSTAT);
fcnt_prog = (val & I40E_PFQF_FDSTAT_GUARANT_CNT_MASK);
return fcnt_prog;
}
u32 i40e_get_current_fd_count(struct i40e_pf *pf)
{
u32 val, fcnt_prog;
val = rd32(&pf->hw, I40E_PFQF_FDSTAT);
fcnt_prog = (val & I40E_PFQF_FDSTAT_GUARANT_CNT_MASK) +
((val & I40E_PFQF_FDSTAT_BEST_CNT_MASK) >>
I40E_PFQF_FDSTAT_BEST_CNT_SHIFT);
return fcnt_prog;
}
u32 i40e_get_global_fd_count(struct i40e_pf *pf)
{
u32 val, fcnt_prog;
val = rd32(&pf->hw, I40E_GLQF_FDCNT_0);
fcnt_prog = (val & I40E_GLQF_FDCNT_0_GUARANT_CNT_MASK) +
((val & I40E_GLQF_FDCNT_0_BESTCNT_MASK) >>
I40E_GLQF_FDCNT_0_BESTCNT_SHIFT);
return fcnt_prog;
}
void i40e_fdir_check_and_reenable(struct i40e_pf *pf)
{
struct i40e_fdir_filter *filter;
u32 fcnt_prog, fcnt_avail;
struct hlist_node *node;
if (test_bit(__I40E_FD_FLUSH_REQUESTED, pf->state))
return;
fcnt_prog = i40e_get_global_fd_count(pf);
fcnt_avail = pf->fdir_pf_filter_count;
if ((fcnt_prog < (fcnt_avail - I40E_FDIR_BUFFER_HEAD_ROOM)) ||
(pf->fd_add_err == 0) ||
(i40e_get_current_atr_cnt(pf) < pf->fd_atr_cnt)) {
if (pf->flags & I40E_FLAG_FD_SB_AUTO_DISABLED) {
pf->flags &= ~I40E_FLAG_FD_SB_AUTO_DISABLED;
if ((pf->flags & I40E_FLAG_FD_SB_ENABLED) &&
(I40E_DEBUG_FD & pf->hw.debug_mask))
dev_info(&pf->pdev->dev, "FD Sideband/ntuple is being enabled since we have space in the table now\n");
}
}
if ((fcnt_prog < (fcnt_avail - I40E_FDIR_BUFFER_HEAD_ROOM_FOR_ATR)) &&
(pf->fd_tcp4_filter_cnt == 0)) {
if (pf->flags & I40E_FLAG_FD_ATR_AUTO_DISABLED) {
pf->flags &= ~I40E_FLAG_FD_ATR_AUTO_DISABLED;
if ((pf->flags & I40E_FLAG_FD_ATR_ENABLED) &&
(I40E_DEBUG_FD & pf->hw.debug_mask))
dev_info(&pf->pdev->dev, "ATR is being enabled since we have space in the table and there are no conflicting ntuple rules\n");
}
}
if (pf->fd_inv > 0) {
hlist_for_each_entry_safe(filter, node,
&pf->fdir_filter_list, fdir_node) {
if (filter->fd_id == pf->fd_inv) {
hlist_del(&filter->fdir_node);
kfree(filter);
pf->fdir_pf_active_filters--;
}
}
}
}
static void i40e_fdir_flush_and_replay(struct i40e_pf *pf)
{
unsigned long min_flush_time;
int flush_wait_retry = 50;
bool disable_atr = false;
int fd_room;
int reg;
if (!time_after(jiffies, pf->fd_flush_timestamp +
(I40E_MIN_FD_FLUSH_INTERVAL * HZ)))
return;
min_flush_time = pf->fd_flush_timestamp +
(I40E_MIN_FD_FLUSH_SB_ATR_UNSTABLE * HZ);
fd_room = pf->fdir_pf_filter_count - pf->fdir_pf_active_filters;
if (!(time_after(jiffies, min_flush_time)) &&
(fd_room < I40E_FDIR_BUFFER_HEAD_ROOM_FOR_ATR)) {
if (I40E_DEBUG_FD & pf->hw.debug_mask)
dev_info(&pf->pdev->dev, "ATR disabled, not enough FD filter space.\n");
disable_atr = true;
}
pf->fd_flush_timestamp = jiffies;
pf->flags |= I40E_FLAG_FD_ATR_AUTO_DISABLED;
wr32(&pf->hw, I40E_PFQF_CTL_1,
I40E_PFQF_CTL_1_CLEARFDTABLE_MASK);
i40e_flush(&pf->hw);
pf->fd_flush_cnt++;
pf->fd_add_err = 0;
do {
usleep_range(5000, 6000);
reg = rd32(&pf->hw, I40E_PFQF_CTL_1);
if (!(reg & I40E_PFQF_CTL_1_CLEARFDTABLE_MASK))
break;
} while (flush_wait_retry--);
if (reg & I40E_PFQF_CTL_1_CLEARFDTABLE_MASK) {
dev_warn(&pf->pdev->dev, "FD table did not flush, needs more time\n");
} else {
i40e_fdir_filter_restore(pf->vsi[pf->lan_vsi]);
if (!disable_atr && !pf->fd_tcp4_filter_cnt)
pf->flags &= ~I40E_FLAG_FD_ATR_AUTO_DISABLED;
clear_bit(__I40E_FD_FLUSH_REQUESTED, pf->state);
if (I40E_DEBUG_FD & pf->hw.debug_mask)
dev_info(&pf->pdev->dev, "FD Filter table flushed and FD-SB replayed.\n");
}
}
u32 i40e_get_current_atr_cnt(struct i40e_pf *pf)
{
return i40e_get_current_fd_count(pf) - pf->fdir_pf_active_filters;
}
static void i40e_fdir_reinit_subtask(struct i40e_pf *pf)
{
if (test_bit(__I40E_DOWN, pf->state))
return;
if (test_bit(__I40E_FD_FLUSH_REQUESTED, pf->state))
i40e_fdir_flush_and_replay(pf);
i40e_fdir_check_and_reenable(pf);
}
static void i40e_vsi_link_event(struct i40e_vsi *vsi, bool link_up)
{
if (!vsi || test_bit(__I40E_VSI_DOWN, vsi->state))
return;
switch (vsi->type) {
case I40E_VSI_MAIN:
if (!vsi->netdev || !vsi->netdev_registered)
break;
if (link_up) {
netif_carrier_on(vsi->netdev);
netif_tx_wake_all_queues(vsi->netdev);
} else {
netif_carrier_off(vsi->netdev);
netif_tx_stop_all_queues(vsi->netdev);
}
break;
case I40E_VSI_SRIOV:
case I40E_VSI_VMDQ2:
case I40E_VSI_CTRL:
case I40E_VSI_IWARP:
case I40E_VSI_MIRROR:
default:
break;
}
}
static void i40e_veb_link_event(struct i40e_veb *veb, bool link_up)
{
struct i40e_pf *pf;
int i;
if (!veb || !veb->pf)
return;
pf = veb->pf;
for (i = 0; i < I40E_MAX_VEB; i++)
if (pf->veb[i] && (pf->veb[i]->uplink_seid == veb->seid))
i40e_veb_link_event(pf->veb[i], link_up);
for (i = 0; i < pf->num_alloc_vsi; i++)
if (pf->vsi[i] && (pf->vsi[i]->uplink_seid == veb->seid))
i40e_vsi_link_event(pf->vsi[i], link_up);
}
static void i40e_link_event(struct i40e_pf *pf)
{
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
u8 new_link_speed, old_link_speed;
i40e_status status;
bool new_link, old_link;
pf->hw.phy.link_info_old = pf->hw.phy.link_info;
pf->hw.phy.get_link_info = true;
old_link = (pf->hw.phy.link_info_old.link_info & I40E_AQ_LINK_UP);
status = i40e_get_link_status(&pf->hw, &new_link);
if (status == I40E_SUCCESS) {
if (pf->flags & I40E_FLAG_TEMP_LINK_POLLING)
pf->flags &= ~I40E_FLAG_TEMP_LINK_POLLING;
} else {
pf->flags |= I40E_FLAG_TEMP_LINK_POLLING;
dev_dbg(&pf->pdev->dev, "couldn't get link state, status: %d\n",
status);
return;
}
old_link_speed = pf->hw.phy.link_info_old.link_speed;
new_link_speed = pf->hw.phy.link_info.link_speed;
if (new_link == old_link &&
new_link_speed == old_link_speed &&
(test_bit(__I40E_VSI_DOWN, vsi->state) ||
new_link == netif_carrier_ok(vsi->netdev)))
return;
if (!test_bit(__I40E_VSI_DOWN, vsi->state))
i40e_print_link_message(vsi, new_link);
if (pf->lan_veb != I40E_NO_VEB && pf->veb[pf->lan_veb])
i40e_veb_link_event(pf->veb[pf->lan_veb], new_link);
else
i40e_vsi_link_event(vsi, new_link);
if (pf->vf)
i40e_vc_notify_link_state(pf);
if (pf->flags & I40E_FLAG_PTP)
i40e_ptp_set_increment(pf);
}
static void i40e_watchdog_subtask(struct i40e_pf *pf)
{
int i;
if (test_bit(__I40E_DOWN, pf->state) ||
test_bit(__I40E_CONFIG_BUSY, pf->state))
return;
if (time_before(jiffies, (pf->service_timer_previous +
pf->service_timer_period)))
return;
pf->service_timer_previous = jiffies;
if ((pf->flags & I40E_FLAG_LINK_POLLING_ENABLED) ||
(pf->flags & I40E_FLAG_TEMP_LINK_POLLING))
i40e_link_event(pf);
for (i = 0; i < pf->num_alloc_vsi; i++)
if (pf->vsi[i] && pf->vsi[i]->netdev)
i40e_update_stats(pf->vsi[i]);
if (pf->flags & I40E_FLAG_VEB_STATS_ENABLED) {
for (i = 0; i < I40E_MAX_VEB; i++)
if (pf->veb[i])
i40e_update_veb_stats(pf->veb[i]);
}
i40e_ptp_rx_hang(pf->vsi[pf->lan_vsi]);
}
static void i40e_reset_subtask(struct i40e_pf *pf)
{
u32 reset_flags = 0;
if (test_bit(__I40E_REINIT_REQUESTED, pf->state)) {
reset_flags |= BIT(__I40E_REINIT_REQUESTED);
clear_bit(__I40E_REINIT_REQUESTED, pf->state);
}
if (test_bit(__I40E_PF_RESET_REQUESTED, pf->state)) {
reset_flags |= BIT(__I40E_PF_RESET_REQUESTED);
clear_bit(__I40E_PF_RESET_REQUESTED, pf->state);
}
if (test_bit(__I40E_CORE_RESET_REQUESTED, pf->state)) {
reset_flags |= BIT(__I40E_CORE_RESET_REQUESTED);
clear_bit(__I40E_CORE_RESET_REQUESTED, pf->state);
}
if (test_bit(__I40E_GLOBAL_RESET_REQUESTED, pf->state)) {
reset_flags |= BIT(__I40E_GLOBAL_RESET_REQUESTED);
clear_bit(__I40E_GLOBAL_RESET_REQUESTED, pf->state);
}
if (test_bit(__I40E_DOWN_REQUESTED, pf->state)) {
reset_flags |= BIT(__I40E_DOWN_REQUESTED);
clear_bit(__I40E_DOWN_REQUESTED, pf->state);
}
if (test_bit(__I40E_RESET_INTR_RECEIVED, pf->state)) {
i40e_prep_for_reset(pf, false);
i40e_reset(pf);
i40e_rebuild(pf, false, false);
}
if (reset_flags &&
!test_bit(__I40E_DOWN, pf->state) &&
!test_bit(__I40E_CONFIG_BUSY, pf->state)) {
rtnl_lock();
i40e_do_reset(pf, reset_flags, true);
rtnl_unlock();
}
}
static void i40e_handle_link_event(struct i40e_pf *pf,
struct i40e_arq_event_info *e)
{
struct i40e_aqc_get_link_status *status =
(struct i40e_aqc_get_link_status *)&e->desc.params.raw;
i40e_link_event(pf);
if ((status->link_info & I40E_AQ_MEDIA_AVAILABLE) &&
(!(status->an_info & I40E_AQ_QUALIFIED_MODULE)) &&
(!(status->link_info & I40E_AQ_LINK_UP)))
dev_err(&pf->pdev->dev,
"The driver failed to link because an unqualified module was detected.\n");
}
static void i40e_clean_adminq_subtask(struct i40e_pf *pf)
{
struct i40e_arq_event_info event;
struct i40e_hw *hw = &pf->hw;
u16 pending, i = 0;
i40e_status ret;
u16 opcode;
u32 oldval;
u32 val;
if (test_bit(__I40E_RESET_FAILED, pf->state))
return;
val = rd32(&pf->hw, pf->hw.aq.arq.len);
oldval = val;
if (val & I40E_PF_ARQLEN_ARQVFE_MASK) {
if (hw->debug_mask & I40E_DEBUG_AQ)
dev_info(&pf->pdev->dev, "ARQ VF Error detected\n");
val &= ~I40E_PF_ARQLEN_ARQVFE_MASK;
}
if (val & I40E_PF_ARQLEN_ARQOVFL_MASK) {
if (hw->debug_mask & I40E_DEBUG_AQ)
dev_info(&pf->pdev->dev, "ARQ Overflow Error detected\n");
val &= ~I40E_PF_ARQLEN_ARQOVFL_MASK;
pf->arq_overflows++;
}
if (val & I40E_PF_ARQLEN_ARQCRIT_MASK) {
if (hw->debug_mask & I40E_DEBUG_AQ)
dev_info(&pf->pdev->dev, "ARQ Critical Error detected\n");
val &= ~I40E_PF_ARQLEN_ARQCRIT_MASK;
}
if (oldval != val)
wr32(&pf->hw, pf->hw.aq.arq.len, val);
val = rd32(&pf->hw, pf->hw.aq.asq.len);
oldval = val;
if (val & I40E_PF_ATQLEN_ATQVFE_MASK) {
if (pf->hw.debug_mask & I40E_DEBUG_AQ)
dev_info(&pf->pdev->dev, "ASQ VF Error detected\n");
val &= ~I40E_PF_ATQLEN_ATQVFE_MASK;
}
if (val & I40E_PF_ATQLEN_ATQOVFL_MASK) {
if (pf->hw.debug_mask & I40E_DEBUG_AQ)
dev_info(&pf->pdev->dev, "ASQ Overflow Error detected\n");
val &= ~I40E_PF_ATQLEN_ATQOVFL_MASK;
}
if (val & I40E_PF_ATQLEN_ATQCRIT_MASK) {
if (pf->hw.debug_mask & I40E_DEBUG_AQ)
dev_info(&pf->pdev->dev, "ASQ Critical Error detected\n");
val &= ~I40E_PF_ATQLEN_ATQCRIT_MASK;
}
if (oldval != val)
wr32(&pf->hw, pf->hw.aq.asq.len, val);
event.buf_len = I40E_MAX_AQ_BUF_SIZE;
event.msg_buf = kzalloc(event.buf_len, GFP_KERNEL);
if (!event.msg_buf)
return;
do {
ret = i40e_clean_arq_element(hw, &event, &pending);
if (ret == I40E_ERR_ADMIN_QUEUE_NO_WORK)
break;
else if (ret) {
dev_info(&pf->pdev->dev, "ARQ event error %d\n", ret);
break;
}
opcode = le16_to_cpu(event.desc.opcode);
switch (opcode) {
case i40e_aqc_opc_get_link_status:
i40e_handle_link_event(pf, &event);
break;
case i40e_aqc_opc_send_msg_to_pf:
ret = i40e_vc_process_vf_msg(pf,
le16_to_cpu(event.desc.retval),
le32_to_cpu(event.desc.cookie_high),
le32_to_cpu(event.desc.cookie_low),
event.msg_buf,
event.msg_len);
break;
case i40e_aqc_opc_lldp_update_mib:
dev_dbg(&pf->pdev->dev, "ARQ: Update LLDP MIB event received\n");
#ifdef CONFIG_I40E_DCB
rtnl_lock();
ret = i40e_handle_lldp_event(pf, &event);
rtnl_unlock();
#endif
break;
case i40e_aqc_opc_event_lan_overflow:
dev_dbg(&pf->pdev->dev, "ARQ LAN queue overflow event received\n");
i40e_handle_lan_overflow_event(pf, &event);
break;
case i40e_aqc_opc_send_msg_to_peer:
dev_info(&pf->pdev->dev, "ARQ: Msg from other pf\n");
break;
case i40e_aqc_opc_nvm_erase:
case i40e_aqc_opc_nvm_update:
case i40e_aqc_opc_oem_post_update:
i40e_debug(&pf->hw, I40E_DEBUG_NVM,
"ARQ NVM operation 0x%04x completed\n",
opcode);
break;
default:
dev_info(&pf->pdev->dev,
"ARQ: Unknown event 0x%04x ignored\n",
opcode);
break;
}
} while (i++ < pf->adminq_work_limit);
if (i < pf->adminq_work_limit)
clear_bit(__I40E_ADMINQ_EVENT_PENDING, pf->state);
val = rd32(hw, I40E_PFINT_ICR0_ENA);
val |= I40E_PFINT_ICR0_ENA_ADMINQ_MASK;
wr32(hw, I40E_PFINT_ICR0_ENA, val);
i40e_flush(hw);
kfree(event.msg_buf);
}
static void i40e_verify_eeprom(struct i40e_pf *pf)
{
int err;
err = i40e_diag_eeprom_test(&pf->hw);
if (err) {
err = i40e_diag_eeprom_test(&pf->hw);
if (err) {
dev_info(&pf->pdev->dev, "eeprom check failed (%d), Tx/Rx traffic disabled\n",
err);
set_bit(__I40E_BAD_EEPROM, pf->state);
}
}
if (!err && test_bit(__I40E_BAD_EEPROM, pf->state)) {
dev_info(&pf->pdev->dev, "eeprom check passed, Tx/Rx traffic enabled\n");
clear_bit(__I40E_BAD_EEPROM, pf->state);
}
}
static void i40e_enable_pf_switch_lb(struct i40e_pf *pf)
{
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
struct i40e_vsi_context ctxt;
int ret;
ctxt.seid = pf->main_vsi_seid;
ctxt.pf_num = pf->hw.pf_id;
ctxt.vf_num = 0;
ret = i40e_aq_get_vsi_params(&pf->hw, &ctxt, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't get PF vsi config, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
return;
}
ctxt.flags = I40E_AQ_VSI_TYPE_PF;
ctxt.info.valid_sections = cpu_to_le16(I40E_AQ_VSI_PROP_SWITCH_VALID);
ctxt.info.switch_id |= cpu_to_le16(I40E_AQ_VSI_SW_ID_FLAG_ALLOW_LB);
ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"update vsi switch failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
}
}
static void i40e_disable_pf_switch_lb(struct i40e_pf *pf)
{
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
struct i40e_vsi_context ctxt;
int ret;
ctxt.seid = pf->main_vsi_seid;
ctxt.pf_num = pf->hw.pf_id;
ctxt.vf_num = 0;
ret = i40e_aq_get_vsi_params(&pf->hw, &ctxt, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't get PF vsi config, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
return;
}
ctxt.flags = I40E_AQ_VSI_TYPE_PF;
ctxt.info.valid_sections = cpu_to_le16(I40E_AQ_VSI_PROP_SWITCH_VALID);
ctxt.info.switch_id &= ~cpu_to_le16(I40E_AQ_VSI_SW_ID_FLAG_ALLOW_LB);
ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"update vsi switch failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
}
}
static void i40e_config_bridge_mode(struct i40e_veb *veb)
{
struct i40e_pf *pf = veb->pf;
if (pf->hw.debug_mask & I40E_DEBUG_LAN)
dev_info(&pf->pdev->dev, "enabling bridge mode: %s\n",
veb->bridge_mode == BRIDGE_MODE_VEPA ? "VEPA" : "VEB");
if (veb->bridge_mode & BRIDGE_MODE_VEPA)
i40e_disable_pf_switch_lb(pf);
else
i40e_enable_pf_switch_lb(pf);
}
static int i40e_reconstitute_veb(struct i40e_veb *veb)
{
struct i40e_vsi *ctl_vsi = NULL;
struct i40e_pf *pf = veb->pf;
int v, veb_idx;
int ret;
for (v = 0; v < pf->num_alloc_vsi && !ctl_vsi; v++) {
if (pf->vsi[v] &&
pf->vsi[v]->veb_idx == veb->idx &&
pf->vsi[v]->flags & I40E_VSI_FLAG_VEB_OWNER) {
ctl_vsi = pf->vsi[v];
break;
}
}
if (!ctl_vsi) {
dev_info(&pf->pdev->dev,
"missing owner VSI for veb_idx %d\n", veb->idx);
ret = -ENOENT;
goto end_reconstitute;
}
if (ctl_vsi != pf->vsi[pf->lan_vsi])
ctl_vsi->uplink_seid = pf->vsi[pf->lan_vsi]->uplink_seid;
ret = i40e_add_vsi(ctl_vsi);
if (ret) {
dev_info(&pf->pdev->dev,
"rebuild of veb_idx %d owner VSI failed: %d\n",
veb->idx, ret);
goto end_reconstitute;
}
i40e_vsi_reset_stats(ctl_vsi);
ret = i40e_add_veb(veb, ctl_vsi);
if (ret)
goto end_reconstitute;
if (pf->flags & I40E_FLAG_VEB_MODE_ENABLED)
veb->bridge_mode = BRIDGE_MODE_VEB;
else
veb->bridge_mode = BRIDGE_MODE_VEPA;
i40e_config_bridge_mode(veb);
for (v = 0; v < pf->num_alloc_vsi; v++) {
if (!pf->vsi[v] || pf->vsi[v] == ctl_vsi)
continue;
if (pf->vsi[v]->veb_idx == veb->idx) {
struct i40e_vsi *vsi = pf->vsi[v];
vsi->uplink_seid = veb->seid;
ret = i40e_add_vsi(vsi);
if (ret) {
dev_info(&pf->pdev->dev,
"rebuild of vsi_idx %d failed: %d\n",
v, ret);
goto end_reconstitute;
}
i40e_vsi_reset_stats(vsi);
}
}
for (veb_idx = 0; veb_idx < I40E_MAX_VEB; veb_idx++) {
if (pf->veb[veb_idx] && pf->veb[veb_idx]->veb_idx == veb->idx) {
pf->veb[veb_idx]->uplink_seid = veb->seid;
ret = i40e_reconstitute_veb(pf->veb[veb_idx]);
if (ret)
break;
}
}
end_reconstitute:
return ret;
}
static int i40e_get_capabilities(struct i40e_pf *pf)
{
struct i40e_aqc_list_capabilities_element_resp *cap_buf;
u16 data_size;
int buf_len;
int err;
buf_len = 40 * sizeof(struct i40e_aqc_list_capabilities_element_resp);
do {
cap_buf = kzalloc(buf_len, GFP_KERNEL);
if (!cap_buf)
return -ENOMEM;
err = i40e_aq_discover_capabilities(&pf->hw, cap_buf, buf_len,
&data_size,
i40e_aqc_opc_list_func_capabilities,
NULL);
kfree(cap_buf);
if (pf->hw.aq.asq_last_status == I40E_AQ_RC_ENOMEM) {
buf_len = data_size;
} else if (pf->hw.aq.asq_last_status != I40E_AQ_RC_OK) {
dev_info(&pf->pdev->dev,
"capability discovery failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, err),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
return -ENODEV;
}
} while (err);
if (pf->hw.debug_mask & I40E_DEBUG_USER)
dev_info(&pf->pdev->dev,
"pf=%d, num_vfs=%d, msix_pf=%d, msix_vf=%d, fd_g=%d, fd_b=%d, pf_max_q=%d num_vsi=%d\n",
pf->hw.pf_id, pf->hw.func_caps.num_vfs,
pf->hw.func_caps.num_msix_vectors,
pf->hw.func_caps.num_msix_vectors_vf,
pf->hw.func_caps.fd_filters_guaranteed,
pf->hw.func_caps.fd_filters_best_effort,
pf->hw.func_caps.num_tx_qp,
pf->hw.func_caps.num_vsis);
#define DEF_NUM_VSI (1 + (pf->hw.func_caps.fcoe ? 1 : 0) \
+ pf->hw.func_caps.num_vfs)
if (pf->hw.revision_id == 0 && (DEF_NUM_VSI > pf->hw.func_caps.num_vsis)) {
dev_info(&pf->pdev->dev,
"got num_vsis %d, setting num_vsis to %d\n",
pf->hw.func_caps.num_vsis, DEF_NUM_VSI);
pf->hw.func_caps.num_vsis = DEF_NUM_VSI;
}
return 0;
}
static void i40e_fdir_sb_setup(struct i40e_pf *pf)
{
struct i40e_vsi *vsi;
if (!rd32(&pf->hw, I40E_GLQF_HKEY(0))) {
static const u32 hkey[] = {
0xe640d33f, 0xcdfe98ab, 0x73fa7161, 0x0d7a7d36,
0xeacb7d61, 0xaa4f05b6, 0x9c5c89ed, 0xfc425ddb,
0xa4654832, 0xfc7461d4, 0x8f827619, 0xf5c63c21,
0x95b3a76d};
int i;
for (i = 0; i <= I40E_GLQF_HKEY_MAX_INDEX; i++)
wr32(&pf->hw, I40E_GLQF_HKEY(i), hkey[i]);
}
if (!(pf->flags & I40E_FLAG_FD_SB_ENABLED))
return;
vsi = i40e_find_vsi_by_type(pf, I40E_VSI_FDIR);
if (!vsi) {
vsi = i40e_vsi_setup(pf, I40E_VSI_FDIR,
pf->vsi[pf->lan_vsi]->seid, 0);
if (!vsi) {
dev_info(&pf->pdev->dev, "Couldn't create FDir VSI\n");
pf->flags &= ~I40E_FLAG_FD_SB_ENABLED;
return;
}
}
i40e_vsi_setup_irqhandler(vsi, i40e_fdir_clean_ring);
}
static void i40e_fdir_teardown(struct i40e_pf *pf)
{
struct i40e_vsi *vsi;
i40e_fdir_filter_exit(pf);
vsi = i40e_find_vsi_by_type(pf, I40E_VSI_FDIR);
if (vsi)
i40e_vsi_release(vsi);
}
static void i40e_prep_for_reset(struct i40e_pf *pf, bool lock_acquired)
{
struct i40e_hw *hw = &pf->hw;
i40e_status ret = 0;
u32 v;
clear_bit(__I40E_RESET_INTR_RECEIVED, pf->state);
if (test_and_set_bit(__I40E_RESET_RECOVERY_PENDING, pf->state))
return;
if (i40e_check_asq_alive(&pf->hw))
i40e_vc_notify_reset(pf);
dev_dbg(&pf->pdev->dev, "Tearing down internal switch for reset\n");
if (!lock_acquired)
rtnl_lock();
i40e_pf_quiesce_all_vsi(pf);
if (!lock_acquired)
rtnl_unlock();
for (v = 0; v < pf->num_alloc_vsi; v++) {
if (pf->vsi[v])
pf->vsi[v]->seid = 0;
}
i40e_shutdown_adminq(&pf->hw);
if (hw->hmc.hmc_obj) {
ret = i40e_shutdown_lan_hmc(hw);
if (ret)
dev_warn(&pf->pdev->dev,
"shutdown_lan_hmc failed: %d\n", ret);
}
}
static void i40e_send_version(struct i40e_pf *pf)
{
struct i40e_driver_version dv;
dv.major_version = DRV_VERSION_MAJOR;
dv.minor_version = DRV_VERSION_MINOR;
dv.build_version = DRV_VERSION_BUILD;
dv.subbuild_version = 0;
strlcpy(dv.driver_string, DRV_VERSION, sizeof(dv.driver_string));
i40e_aq_send_driver_version(&pf->hw, &dv, NULL);
}
static int i40e_reset(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
i40e_status ret;
ret = i40e_pf_reset(hw);
if (ret) {
dev_info(&pf->pdev->dev, "PF reset failed, %d\n", ret);
set_bit(__I40E_RESET_FAILED, pf->state);
clear_bit(__I40E_RESET_RECOVERY_PENDING, pf->state);
} else {
pf->pfr_count++;
}
return ret;
}
static void i40e_rebuild(struct i40e_pf *pf, bool reinit, bool lock_acquired)
{
struct i40e_hw *hw = &pf->hw;
u8 set_fc_aq_fail = 0;
i40e_status ret;
u32 val;
int v;
if (test_bit(__I40E_DOWN, pf->state))
goto clear_recovery;
dev_dbg(&pf->pdev->dev, "Rebuilding internal switch\n");
ret = i40e_init_adminq(&pf->hw);
if (ret) {
dev_info(&pf->pdev->dev, "Rebuild AdminQ failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
goto clear_recovery;
}
if (test_and_clear_bit(__I40E_EMP_RESET_INTR_RECEIVED, pf->state))
i40e_verify_eeprom(pf);
i40e_clear_pxe_mode(hw);
ret = i40e_get_capabilities(pf);
if (ret)
goto end_core_reset;
ret = i40e_init_lan_hmc(hw, hw->func_caps.num_tx_qp,
hw->func_caps.num_rx_qp, 0, 0);
if (ret) {
dev_info(&pf->pdev->dev, "init_lan_hmc failed: %d\n", ret);
goto end_core_reset;
}
ret = i40e_configure_lan_hmc(hw, I40E_HMC_MODEL_DIRECT_ONLY);
if (ret) {
dev_info(&pf->pdev->dev, "configure_lan_hmc failed: %d\n", ret);
goto end_core_reset;
}
#ifdef CONFIG_I40E_DCB
ret = i40e_init_pf_dcb(pf);
if (ret) {
dev_info(&pf->pdev->dev, "DCB init failed %d, disabled\n", ret);
pf->flags &= ~I40E_FLAG_DCB_CAPABLE;
}
#endif
if (!lock_acquired)
rtnl_lock();
ret = i40e_setup_pf_switch(pf, reinit);
if (ret)
goto end_unlock;
ret = i40e_aq_set_phy_int_mask(&pf->hw,
~(I40E_AQ_EVENT_LINK_UPDOWN |
I40E_AQ_EVENT_MEDIA_NA |
I40E_AQ_EVENT_MODULE_QUAL_FAIL), NULL);
if (ret)
dev_info(&pf->pdev->dev, "set phy mask fail, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
ret = i40e_set_fc(&pf->hw, &set_fc_aq_fail, true);
if (ret)
dev_dbg(&pf->pdev->dev, "setting flow control: ret = %s last_status = %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
if (pf->vsi[pf->lan_vsi]->uplink_seid != pf->mac_seid) {
dev_dbg(&pf->pdev->dev, "attempting to rebuild switch\n");
for (v = 0; v < I40E_MAX_VEB; v++) {
if (!pf->veb[v])
continue;
if (pf->veb[v]->uplink_seid == pf->mac_seid ||
pf->veb[v]->uplink_seid == 0) {
ret = i40e_reconstitute_veb(pf->veb[v]);
if (!ret)
continue;
if (pf->veb[v]->uplink_seid == pf->mac_seid) {
dev_info(&pf->pdev->dev,
"rebuild of switch failed: %d, will try to set up simple PF connection\n",
ret);
pf->vsi[pf->lan_vsi]->uplink_seid
= pf->mac_seid;
break;
} else if (pf->veb[v]->uplink_seid == 0) {
dev_info(&pf->pdev->dev,
"rebuild of orphan VEB failed: %d\n",
ret);
}
}
}
}
if (pf->vsi[pf->lan_vsi]->uplink_seid == pf->mac_seid) {
dev_dbg(&pf->pdev->dev, "attempting to rebuild PF VSI\n");
ret = i40e_add_vsi(pf->vsi[pf->lan_vsi]);
if (ret) {
dev_info(&pf->pdev->dev,
"rebuild of Main VSI failed: %d\n", ret);
goto end_unlock;
}
}
#define I40E_REG_MSS 0x000E64DC
#define I40E_REG_MSS_MIN_MASK 0x3FF0000
#define I40E_64BYTE_MSS 0x400000
val = rd32(hw, I40E_REG_MSS);
if ((val & I40E_REG_MSS_MIN_MASK) > I40E_64BYTE_MSS) {
val &= ~I40E_REG_MSS_MIN_MASK;
val |= I40E_64BYTE_MSS;
wr32(hw, I40E_REG_MSS, val);
}
if (pf->flags & I40E_FLAG_RESTART_AUTONEG) {
msleep(75);
ret = i40e_aq_set_link_restart_an(&pf->hw, true, NULL);
if (ret)
dev_info(&pf->pdev->dev, "link restart failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
}
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
ret = i40e_setup_misc_vector(pf);
i40e_add_filter_to_drop_tx_flow_control_frames(&pf->hw,
pf->main_vsi_seid);
i40e_pf_unquiesce_all_vsi(pf);
if (!lock_acquired)
rtnl_unlock();
i40e_reset_all_vfs(pf, true);
i40e_send_version(pf);
goto end_core_reset;
end_unlock:
if (!lock_acquired)
rtnl_unlock();
end_core_reset:
clear_bit(__I40E_RESET_FAILED, pf->state);
clear_recovery:
clear_bit(__I40E_RESET_RECOVERY_PENDING, pf->state);
}
static void i40e_reset_and_rebuild(struct i40e_pf *pf, bool reinit,
bool lock_acquired)
{
int ret;
ret = i40e_reset(pf);
if (!ret)
i40e_rebuild(pf, reinit, lock_acquired);
}
static void i40e_handle_reset_warning(struct i40e_pf *pf, bool lock_acquired)
{
i40e_prep_for_reset(pf, lock_acquired);
i40e_reset_and_rebuild(pf, false, lock_acquired);
}
static void i40e_handle_mdd_event(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
bool mdd_detected = false;
bool pf_mdd_detected = false;
struct i40e_vf *vf;
u32 reg;
int i;
if (!test_bit(__I40E_MDD_EVENT_PENDING, pf->state))
return;
reg = rd32(hw, I40E_GL_MDET_TX);
if (reg & I40E_GL_MDET_TX_VALID_MASK) {
u8 pf_num = (reg & I40E_GL_MDET_TX_PF_NUM_MASK) >>
I40E_GL_MDET_TX_PF_NUM_SHIFT;
u16 vf_num = (reg & I40E_GL_MDET_TX_VF_NUM_MASK) >>
I40E_GL_MDET_TX_VF_NUM_SHIFT;
u8 event = (reg & I40E_GL_MDET_TX_EVENT_MASK) >>
I40E_GL_MDET_TX_EVENT_SHIFT;
u16 queue = ((reg & I40E_GL_MDET_TX_QUEUE_MASK) >>
I40E_GL_MDET_TX_QUEUE_SHIFT) -
pf->hw.func_caps.base_queue;
if (netif_msg_tx_err(pf))
dev_info(&pf->pdev->dev, "Malicious Driver Detection event 0x%02x on TX queue %d PF number 0x%02x VF number 0x%02x\n",
event, queue, pf_num, vf_num);
wr32(hw, I40E_GL_MDET_TX, 0xffffffff);
mdd_detected = true;
}
reg = rd32(hw, I40E_GL_MDET_RX);
if (reg & I40E_GL_MDET_RX_VALID_MASK) {
u8 func = (reg & I40E_GL_MDET_RX_FUNCTION_MASK) >>
I40E_GL_MDET_RX_FUNCTION_SHIFT;
u8 event = (reg & I40E_GL_MDET_RX_EVENT_MASK) >>
I40E_GL_MDET_RX_EVENT_SHIFT;
u16 queue = ((reg & I40E_GL_MDET_RX_QUEUE_MASK) >>
I40E_GL_MDET_RX_QUEUE_SHIFT) -
pf->hw.func_caps.base_queue;
if (netif_msg_rx_err(pf))
dev_info(&pf->pdev->dev, "Malicious Driver Detection event 0x%02x on RX queue %d of function 0x%02x\n",
event, queue, func);
wr32(hw, I40E_GL_MDET_RX, 0xffffffff);
mdd_detected = true;
}
if (mdd_detected) {
reg = rd32(hw, I40E_PF_MDET_TX);
if (reg & I40E_PF_MDET_TX_VALID_MASK) {
wr32(hw, I40E_PF_MDET_TX, 0xFFFF);
dev_info(&pf->pdev->dev, "TX driver issue detected, PF reset issued\n");
pf_mdd_detected = true;
}
reg = rd32(hw, I40E_PF_MDET_RX);
if (reg & I40E_PF_MDET_RX_VALID_MASK) {
wr32(hw, I40E_PF_MDET_RX, 0xFFFF);
dev_info(&pf->pdev->dev, "RX driver issue detected, PF reset issued\n");
pf_mdd_detected = true;
}
if (pf_mdd_detected) {
set_bit(__I40E_PF_RESET_REQUESTED, pf->state);
i40e_service_event_schedule(pf);
}
}
for (i = 0; i < pf->num_alloc_vfs && mdd_detected; i++) {
vf = &(pf->vf[i]);
reg = rd32(hw, I40E_VP_MDET_TX(i));
if (reg & I40E_VP_MDET_TX_VALID_MASK) {
wr32(hw, I40E_VP_MDET_TX(i), 0xFFFF);
vf->num_mdd_events++;
dev_info(&pf->pdev->dev, "TX driver issue detected on VF %d\n",
i);
}
reg = rd32(hw, I40E_VP_MDET_RX(i));
if (reg & I40E_VP_MDET_RX_VALID_MASK) {
wr32(hw, I40E_VP_MDET_RX(i), 0xFFFF);
vf->num_mdd_events++;
dev_info(&pf->pdev->dev, "RX driver issue detected on VF %d\n",
i);
}
if (vf->num_mdd_events > I40E_DEFAULT_NUM_MDD_EVENTS_ALLOWED) {
dev_info(&pf->pdev->dev,
"Too many MDD events on VF %d, disabled\n", i);
dev_info(&pf->pdev->dev,
"Use PF Control I/F to re-enable the VF\n");
set_bit(I40E_VF_STATE_DISABLED, &vf->vf_states);
}
}
clear_bit(__I40E_MDD_EVENT_PENDING, pf->state);
reg = rd32(hw, I40E_PFINT_ICR0_ENA);
reg |= I40E_PFINT_ICR0_ENA_MAL_DETECT_MASK;
wr32(hw, I40E_PFINT_ICR0_ENA, reg);
i40e_flush(hw);
}
static void i40e_sync_udp_filters(struct i40e_pf *pf)
{
int i;
for (i = 0; i < I40E_MAX_PF_UDP_OFFLOAD_PORTS; i++) {
if (pf->udp_ports[i].port)
pf->pending_udp_bitmap |= BIT_ULL(i);
}
pf->flags |= I40E_FLAG_UDP_FILTER_SYNC;
}
static void i40e_sync_udp_filters_subtask(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
i40e_status ret;
u16 port;
int i;
if (!(pf->flags & I40E_FLAG_UDP_FILTER_SYNC))
return;
pf->flags &= ~I40E_FLAG_UDP_FILTER_SYNC;
for (i = 0; i < I40E_MAX_PF_UDP_OFFLOAD_PORTS; i++) {
if (pf->pending_udp_bitmap & BIT_ULL(i)) {
pf->pending_udp_bitmap &= ~BIT_ULL(i);
port = pf->udp_ports[i].port;
if (port)
ret = i40e_aq_add_udp_tunnel(hw, port,
pf->udp_ports[i].type,
NULL, NULL);
else
ret = i40e_aq_del_udp_tunnel(hw, i, NULL);
if (ret) {
dev_dbg(&pf->pdev->dev,
"%s %s port %d, index %d failed, err %s aq_err %s\n",
pf->udp_ports[i].type ? "vxlan" : "geneve",
port ? "add" : "delete",
port, i,
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
pf->udp_ports[i].port = 0;
}
}
}
}
static void i40e_service_task(struct work_struct *work)
{
struct i40e_pf *pf = container_of(work,
struct i40e_pf,
service_task);
unsigned long start_time = jiffies;
if (test_bit(__I40E_RESET_RECOVERY_PENDING, pf->state))
return;
if (test_and_set_bit(__I40E_SERVICE_SCHED, pf->state))
return;
i40e_detect_recover_hung(pf);
i40e_sync_filters_subtask(pf);
i40e_reset_subtask(pf);
i40e_handle_mdd_event(pf);
i40e_vc_process_vflr_event(pf);
i40e_watchdog_subtask(pf);
i40e_fdir_reinit_subtask(pf);
if (pf->flags & I40E_FLAG_CLIENT_RESET) {
i40e_notify_client_of_netdev_close(pf->vsi[pf->lan_vsi], true);
pf->flags &= ~I40E_FLAG_CLIENT_RESET;
} else {
i40e_client_subtask(pf);
if (pf->flags & I40E_FLAG_CLIENT_L2_CHANGE) {
i40e_notify_client_of_l2_param_changes(
pf->vsi[pf->lan_vsi]);
pf->flags &= ~I40E_FLAG_CLIENT_L2_CHANGE;
}
}
i40e_sync_filters_subtask(pf);
i40e_sync_udp_filters_subtask(pf);
i40e_clean_adminq_subtask(pf);
smp_mb__before_atomic();
clear_bit(__I40E_SERVICE_SCHED, pf->state);
if (time_after(jiffies, (start_time + pf->service_timer_period)) ||
test_bit(__I40E_ADMINQ_EVENT_PENDING, pf->state) ||
test_bit(__I40E_MDD_EVENT_PENDING, pf->state) ||
test_bit(__I40E_VFLR_EVENT_PENDING, pf->state))
i40e_service_event_schedule(pf);
}
static void i40e_service_timer(unsigned long data)
{
struct i40e_pf *pf = (struct i40e_pf *)data;
mod_timer(&pf->service_timer,
round_jiffies(jiffies + pf->service_timer_period));
i40e_service_event_schedule(pf);
}
static int i40e_set_num_rings_in_vsi(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
switch (vsi->type) {
case I40E_VSI_MAIN:
vsi->alloc_queue_pairs = pf->num_lan_qps;
vsi->num_desc = ALIGN(I40E_DEFAULT_NUM_DESCRIPTORS,
I40E_REQ_DESCRIPTOR_MULTIPLE);
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
vsi->num_q_vectors = pf->num_lan_msix;
else
vsi->num_q_vectors = 1;
break;
case I40E_VSI_FDIR:
vsi->alloc_queue_pairs = 1;
vsi->num_desc = ALIGN(I40E_FDIR_RING_COUNT,
I40E_REQ_DESCRIPTOR_MULTIPLE);
vsi->num_q_vectors = pf->num_fdsb_msix;
break;
case I40E_VSI_VMDQ2:
vsi->alloc_queue_pairs = pf->num_vmdq_qps;
vsi->num_desc = ALIGN(I40E_DEFAULT_NUM_DESCRIPTORS,
I40E_REQ_DESCRIPTOR_MULTIPLE);
vsi->num_q_vectors = pf->num_vmdq_msix;
break;
case I40E_VSI_SRIOV:
vsi->alloc_queue_pairs = pf->num_vf_qps;
vsi->num_desc = ALIGN(I40E_DEFAULT_NUM_DESCRIPTORS,
I40E_REQ_DESCRIPTOR_MULTIPLE);
break;
default:
WARN_ON(1);
return -ENODATA;
}
return 0;
}
static int i40e_vsi_alloc_arrays(struct i40e_vsi *vsi, bool alloc_qvectors)
{
int size;
int ret = 0;
size = sizeof(struct i40e_ring *) * vsi->alloc_queue_pairs * 2;
vsi->tx_rings = kzalloc(size, GFP_KERNEL);
if (!vsi->tx_rings)
return -ENOMEM;
vsi->rx_rings = &vsi->tx_rings[vsi->alloc_queue_pairs];
if (alloc_qvectors) {
size = sizeof(struct i40e_q_vector *) * vsi->num_q_vectors;
vsi->q_vectors = kzalloc(size, GFP_KERNEL);
if (!vsi->q_vectors) {
ret = -ENOMEM;
goto err_vectors;
}
}
return ret;
err_vectors:
kfree(vsi->tx_rings);
return ret;
}
static int i40e_vsi_mem_alloc(struct i40e_pf *pf, enum i40e_vsi_type type)
{
int ret = -ENODEV;
struct i40e_vsi *vsi;
int vsi_idx;
int i;
mutex_lock(&pf->switch_mutex);
i = pf->next_vsi;
while (i < pf->num_alloc_vsi && pf->vsi[i])
i++;
if (i >= pf->num_alloc_vsi) {
i = 0;
while (i < pf->next_vsi && pf->vsi[i])
i++;
}
if (i < pf->num_alloc_vsi && !pf->vsi[i]) {
vsi_idx = i;
} else {
ret = -ENODEV;
goto unlock_pf;
}
pf->next_vsi = ++i;
vsi = kzalloc(sizeof(*vsi), GFP_KERNEL);
if (!vsi) {
ret = -ENOMEM;
goto unlock_pf;
}
vsi->type = type;
vsi->back = pf;
set_bit(__I40E_VSI_DOWN, vsi->state);
vsi->flags = 0;
vsi->idx = vsi_idx;
vsi->int_rate_limit = 0;
vsi->rss_table_size = (vsi->type == I40E_VSI_MAIN) ?
pf->rss_table_size : 64;
vsi->netdev_registered = false;
vsi->work_limit = I40E_DEFAULT_IRQ_WORK;
hash_init(vsi->mac_filter_hash);
vsi->irqs_ready = false;
ret = i40e_set_num_rings_in_vsi(vsi);
if (ret)
goto err_rings;
ret = i40e_vsi_alloc_arrays(vsi, true);
if (ret)
goto err_rings;
i40e_vsi_setup_irqhandler(vsi, i40e_msix_clean_rings);
spin_lock_init(&vsi->mac_filter_hash_lock);
pf->vsi[vsi_idx] = vsi;
ret = vsi_idx;
goto unlock_pf;
err_rings:
pf->next_vsi = i - 1;
kfree(vsi);
unlock_pf:
mutex_unlock(&pf->switch_mutex);
return ret;
}
static void i40e_vsi_free_arrays(struct i40e_vsi *vsi, bool free_qvectors)
{
if (free_qvectors) {
kfree(vsi->q_vectors);
vsi->q_vectors = NULL;
}
kfree(vsi->tx_rings);
vsi->tx_rings = NULL;
vsi->rx_rings = NULL;
}
static void i40e_clear_rss_config_user(struct i40e_vsi *vsi)
{
if (!vsi)
return;
kfree(vsi->rss_hkey_user);
vsi->rss_hkey_user = NULL;
kfree(vsi->rss_lut_user);
vsi->rss_lut_user = NULL;
}
static int i40e_vsi_clear(struct i40e_vsi *vsi)
{
struct i40e_pf *pf;
if (!vsi)
return 0;
if (!vsi->back)
goto free_vsi;
pf = vsi->back;
mutex_lock(&pf->switch_mutex);
if (!pf->vsi[vsi->idx]) {
dev_err(&pf->pdev->dev, "pf->vsi[%d] is NULL, just free vsi[%d](%p,type %d)\n",
vsi->idx, vsi->idx, vsi, vsi->type);
goto unlock_vsi;
}
if (pf->vsi[vsi->idx] != vsi) {
dev_err(&pf->pdev->dev,
"pf->vsi[%d](%p, type %d) != vsi[%d](%p,type %d): no free!\n",
pf->vsi[vsi->idx]->idx,
pf->vsi[vsi->idx],
pf->vsi[vsi->idx]->type,
vsi->idx, vsi, vsi->type);
goto unlock_vsi;
}
i40e_put_lump(pf->qp_pile, vsi->base_queue, vsi->idx);
i40e_put_lump(pf->irq_pile, vsi->base_vector, vsi->idx);
i40e_vsi_free_arrays(vsi, true);
i40e_clear_rss_config_user(vsi);
pf->vsi[vsi->idx] = NULL;
if (vsi->idx < pf->next_vsi)
pf->next_vsi = vsi->idx;
unlock_vsi:
mutex_unlock(&pf->switch_mutex);
free_vsi:
kfree(vsi);
return 0;
}
static void i40e_vsi_clear_rings(struct i40e_vsi *vsi)
{
int i;
if (vsi->tx_rings && vsi->tx_rings[0]) {
for (i = 0; i < vsi->alloc_queue_pairs; i++) {
kfree_rcu(vsi->tx_rings[i], rcu);
vsi->tx_rings[i] = NULL;
vsi->rx_rings[i] = NULL;
}
}
}
static int i40e_alloc_rings(struct i40e_vsi *vsi)
{
struct i40e_ring *tx_ring, *rx_ring;
struct i40e_pf *pf = vsi->back;
int i;
for (i = 0; i < vsi->alloc_queue_pairs; i++) {
tx_ring = kzalloc(sizeof(struct i40e_ring) * 2, GFP_KERNEL);
if (!tx_ring)
goto err_out;
tx_ring->queue_index = i;
tx_ring->reg_idx = vsi->base_queue + i;
tx_ring->ring_active = false;
tx_ring->vsi = vsi;
tx_ring->netdev = vsi->netdev;
tx_ring->dev = &pf->pdev->dev;
tx_ring->count = vsi->num_desc;
tx_ring->size = 0;
tx_ring->dcb_tc = 0;
if (vsi->back->flags & I40E_FLAG_WB_ON_ITR_CAPABLE)
tx_ring->flags = I40E_TXR_FLAGS_WB_ON_ITR;
tx_ring->tx_itr_setting = pf->tx_itr_default;
vsi->tx_rings[i] = tx_ring;
rx_ring = &tx_ring[1];
rx_ring->queue_index = i;
rx_ring->reg_idx = vsi->base_queue + i;
rx_ring->ring_active = false;
rx_ring->vsi = vsi;
rx_ring->netdev = vsi->netdev;
rx_ring->dev = &pf->pdev->dev;
rx_ring->count = vsi->num_desc;
rx_ring->size = 0;
rx_ring->dcb_tc = 0;
rx_ring->rx_itr_setting = pf->rx_itr_default;
vsi->rx_rings[i] = rx_ring;
}
return 0;
err_out:
i40e_vsi_clear_rings(vsi);
return -ENOMEM;
}
static int i40e_reserve_msix_vectors(struct i40e_pf *pf, int vectors)
{
vectors = pci_enable_msix_range(pf->pdev, pf->msix_entries,
I40E_MIN_MSIX, vectors);
if (vectors < 0) {
dev_info(&pf->pdev->dev,
"MSI-X vector reservation failed: %d\n", vectors);
vectors = 0;
}
return vectors;
}
static int i40e_init_msix(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
int cpus, extra_vectors;
int vectors_left;
int v_budget, i;
int v_actual;
int iwarp_requested = 0;
if (!(pf->flags & I40E_FLAG_MSIX_ENABLED))
return -ENODEV;
vectors_left = hw->func_caps.num_msix_vectors;
v_budget = 0;
if (vectors_left) {
v_budget++;
vectors_left--;
}
cpus = num_online_cpus();
pf->num_lan_msix = min_t(int, cpus, vectors_left / 2);
vectors_left -= pf->num_lan_msix;
if (pf->flags & I40E_FLAG_FD_SB_ENABLED) {
if (vectors_left) {
pf->num_fdsb_msix = 1;
v_budget++;
vectors_left--;
} else {
pf->num_fdsb_msix = 0;
}
}
if (pf->flags & I40E_FLAG_IWARP_ENABLED) {
iwarp_requested = pf->num_iwarp_msix;
if (!vectors_left)
pf->num_iwarp_msix = 0;
else if (vectors_left < pf->num_iwarp_msix)
pf->num_iwarp_msix = 1;
v_budget += pf->num_iwarp_msix;
vectors_left -= pf->num_iwarp_msix;
}
if (pf->flags & I40E_FLAG_VMDQ_ENABLED) {
int vmdq_vecs_wanted = pf->num_vmdq_vsis * pf->num_vmdq_qps;
int vmdq_vecs = min_t(int, vectors_left, vmdq_vecs_wanted);
if (!vectors_left) {
pf->num_vmdq_msix = 0;
pf->num_vmdq_qps = 0;
} else {
if (vmdq_vecs < vmdq_vecs_wanted)
pf->num_vmdq_qps = 1;
pf->num_vmdq_msix = pf->num_vmdq_qps;
v_budget += vmdq_vecs;
vectors_left -= vmdq_vecs;
}
}
extra_vectors = min_t(int, cpus - pf->num_lan_msix, vectors_left);
pf->num_lan_msix += extra_vectors;
vectors_left -= extra_vectors;
WARN(vectors_left < 0,
"Calculation of remaining vectors underflowed. This is an accounting bug when determining total MSI-X vectors.\n");
v_budget += pf->num_lan_msix;
pf->msix_entries = kcalloc(v_budget, sizeof(struct msix_entry),
GFP_KERNEL);
if (!pf->msix_entries)
return -ENOMEM;
for (i = 0; i < v_budget; i++)
pf->msix_entries[i].entry = i;
v_actual = i40e_reserve_msix_vectors(pf, v_budget);
if (v_actual < I40E_MIN_MSIX) {
pf->flags &= ~I40E_FLAG_MSIX_ENABLED;
kfree(pf->msix_entries);
pf->msix_entries = NULL;
pci_disable_msix(pf->pdev);
return -ENODEV;
} else if (v_actual == I40E_MIN_MSIX) {
pf->num_vmdq_vsis = 0;
pf->num_vmdq_qps = 0;
pf->num_lan_qps = 1;
pf->num_lan_msix = 1;
} else if (!vectors_left) {
int vec;
dev_info(&pf->pdev->dev,
"MSI-X vector limit reached, attempting to redistribute vectors\n");
vec = v_actual - 1;
pf->num_vmdq_msix = 1;
pf->num_vmdq_vsis = 1;
pf->num_vmdq_qps = 1;
switch (vec) {
case 2:
pf->num_lan_msix = 1;
break;
case 3:
if (pf->flags & I40E_FLAG_IWARP_ENABLED) {
pf->num_lan_msix = 1;
pf->num_iwarp_msix = 1;
} else {
pf->num_lan_msix = 2;
}
break;
default:
if (pf->flags & I40E_FLAG_IWARP_ENABLED) {
pf->num_iwarp_msix = min_t(int, (vec / 3),
iwarp_requested);
pf->num_vmdq_vsis = min_t(int, (vec / 3),
I40E_DEFAULT_NUM_VMDQ_VSI);
} else {
pf->num_vmdq_vsis = min_t(int, (vec / 2),
I40E_DEFAULT_NUM_VMDQ_VSI);
}
if (pf->flags & I40E_FLAG_FD_SB_ENABLED) {
pf->num_fdsb_msix = 1;
vec--;
}
pf->num_lan_msix = min_t(int,
(vec - (pf->num_iwarp_msix + pf->num_vmdq_vsis)),
pf->num_lan_msix);
pf->num_lan_qps = pf->num_lan_msix;
break;
}
}
if ((pf->flags & I40E_FLAG_FD_SB_ENABLED) &&
(pf->num_fdsb_msix == 0)) {
dev_info(&pf->pdev->dev, "Sideband Flowdir disabled, not enough MSI-X vectors\n");
pf->flags &= ~I40E_FLAG_FD_SB_ENABLED;
}
if ((pf->flags & I40E_FLAG_VMDQ_ENABLED) &&
(pf->num_vmdq_msix == 0)) {
dev_info(&pf->pdev->dev, "VMDq disabled, not enough MSI-X vectors\n");
pf->flags &= ~I40E_FLAG_VMDQ_ENABLED;
}
if ((pf->flags & I40E_FLAG_IWARP_ENABLED) &&
(pf->num_iwarp_msix == 0)) {
dev_info(&pf->pdev->dev, "IWARP disabled, not enough MSI-X vectors\n");
pf->flags &= ~I40E_FLAG_IWARP_ENABLED;
}
i40e_debug(&pf->hw, I40E_DEBUG_INIT,
"MSI-X vector distribution: PF %d, VMDq %d, FDSB %d, iWARP %d\n",
pf->num_lan_msix,
pf->num_vmdq_msix * pf->num_vmdq_vsis,
pf->num_fdsb_msix,
pf->num_iwarp_msix);
return v_actual;
}
static int i40e_vsi_alloc_q_vector(struct i40e_vsi *vsi, int v_idx, int cpu)
{
struct i40e_q_vector *q_vector;
q_vector = kzalloc(sizeof(struct i40e_q_vector), GFP_KERNEL);
if (!q_vector)
return -ENOMEM;
q_vector->vsi = vsi;
q_vector->v_idx = v_idx;
cpumask_set_cpu(cpu, &q_vector->affinity_mask);
if (vsi->netdev)
netif_napi_add(vsi->netdev, &q_vector->napi,
i40e_napi_poll, NAPI_POLL_WEIGHT);
q_vector->rx.latency_range = I40E_LOW_LATENCY;
q_vector->tx.latency_range = I40E_LOW_LATENCY;
vsi->q_vectors[v_idx] = q_vector;
return 0;
}
static int i40e_vsi_alloc_q_vectors(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
int err, v_idx, num_q_vectors, current_cpu;
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
num_q_vectors = vsi->num_q_vectors;
else if (vsi == pf->vsi[pf->lan_vsi])
num_q_vectors = 1;
else
return -EINVAL;
current_cpu = cpumask_first(cpu_online_mask);
for (v_idx = 0; v_idx < num_q_vectors; v_idx++) {
err = i40e_vsi_alloc_q_vector(vsi, v_idx, current_cpu);
if (err)
goto err_out;
current_cpu = cpumask_next(current_cpu, cpu_online_mask);
if (unlikely(current_cpu >= nr_cpu_ids))
current_cpu = cpumask_first(cpu_online_mask);
}
return 0;
err_out:
while (v_idx--)
i40e_free_q_vector(vsi, v_idx);
return err;
}
static int i40e_init_interrupt_scheme(struct i40e_pf *pf)
{
int vectors = 0;
ssize_t size;
if (pf->flags & I40E_FLAG_MSIX_ENABLED) {
vectors = i40e_init_msix(pf);
if (vectors < 0) {
pf->flags &= ~(I40E_FLAG_MSIX_ENABLED |
I40E_FLAG_IWARP_ENABLED |
I40E_FLAG_RSS_ENABLED |
I40E_FLAG_DCB_CAPABLE |
I40E_FLAG_DCB_ENABLED |
I40E_FLAG_SRIOV_ENABLED |
I40E_FLAG_FD_SB_ENABLED |
I40E_FLAG_FD_ATR_ENABLED |
I40E_FLAG_VMDQ_ENABLED);
i40e_determine_queue_usage(pf);
}
}
if (!(pf->flags & I40E_FLAG_MSIX_ENABLED) &&
(pf->flags & I40E_FLAG_MSI_ENABLED)) {
dev_info(&pf->pdev->dev, "MSI-X not available, trying MSI\n");
vectors = pci_enable_msi(pf->pdev);
if (vectors < 0) {
dev_info(&pf->pdev->dev, "MSI init failed - %d\n",
vectors);
pf->flags &= ~I40E_FLAG_MSI_ENABLED;
}
vectors = 1;
}
if (!(pf->flags & (I40E_FLAG_MSIX_ENABLED | I40E_FLAG_MSI_ENABLED)))
dev_info(&pf->pdev->dev, "MSI-X and MSI not available, falling back to Legacy IRQ\n");
size = sizeof(struct i40e_lump_tracking) + (sizeof(u16) * vectors);
pf->irq_pile = kzalloc(size, GFP_KERNEL);
if (!pf->irq_pile) {
dev_err(&pf->pdev->dev, "error allocating irq_pile memory\n");
return -ENOMEM;
}
pf->irq_pile->num_entries = vectors;
pf->irq_pile->search_hint = 0;
(void)i40e_get_lump(pf, pf->irq_pile, 1, I40E_PILE_VALID_BIT - 1);
return 0;
}
static int i40e_setup_misc_vector(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
int err = 0;
if (!test_bit(__I40E_RESET_RECOVERY_PENDING, pf->state)) {
err = request_irq(pf->msix_entries[0].vector,
i40e_intr, 0, pf->int_name, pf);
if (err) {
dev_info(&pf->pdev->dev,
"request_irq for %s failed: %d\n",
pf->int_name, err);
return -EFAULT;
}
}
i40e_enable_misc_int_causes(pf);
wr32(hw, I40E_PFINT_LNKLST0, I40E_QUEUE_END_OF_LIST);
wr32(hw, I40E_PFINT_ITR0(I40E_RX_ITR), I40E_ITR_8K);
i40e_flush(hw);
i40e_irq_dynamic_enable_icr0(pf, true);
return err;
}
static int i40e_config_rss_aq(struct i40e_vsi *vsi, const u8 *seed,
u8 *lut, u16 lut_size)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
int ret = 0;
if (seed) {
struct i40e_aqc_get_set_rss_key_data *seed_dw =
(struct i40e_aqc_get_set_rss_key_data *)seed;
ret = i40e_aq_set_rss_key(hw, vsi->id, seed_dw);
if (ret) {
dev_info(&pf->pdev->dev,
"Cannot set RSS key, err %s aq_err %s\n",
i40e_stat_str(hw, ret),
i40e_aq_str(hw, hw->aq.asq_last_status));
return ret;
}
}
if (lut) {
bool pf_lut = vsi->type == I40E_VSI_MAIN ? true : false;
ret = i40e_aq_set_rss_lut(hw, vsi->id, pf_lut, lut, lut_size);
if (ret) {
dev_info(&pf->pdev->dev,
"Cannot set RSS lut, err %s aq_err %s\n",
i40e_stat_str(hw, ret),
i40e_aq_str(hw, hw->aq.asq_last_status));
return ret;
}
}
return ret;
}
static int i40e_get_rss_aq(struct i40e_vsi *vsi, const u8 *seed,
u8 *lut, u16 lut_size)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
int ret = 0;
if (seed) {
ret = i40e_aq_get_rss_key(hw, vsi->id,
(struct i40e_aqc_get_set_rss_key_data *)seed);
if (ret) {
dev_info(&pf->pdev->dev,
"Cannot get RSS key, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
return ret;
}
}
if (lut) {
bool pf_lut = vsi->type == I40E_VSI_MAIN ? true : false;
ret = i40e_aq_get_rss_lut(hw, vsi->id, pf_lut, lut, lut_size);
if (ret) {
dev_info(&pf->pdev->dev,
"Cannot get RSS lut, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
return ret;
}
}
return ret;
}
static int i40e_vsi_config_rss(struct i40e_vsi *vsi)
{
u8 seed[I40E_HKEY_ARRAY_SIZE];
struct i40e_pf *pf = vsi->back;
u8 *lut;
int ret;
if (!(pf->flags & I40E_FLAG_RSS_AQ_CAPABLE))
return 0;
if (!vsi->rss_size)
vsi->rss_size = min_t(int, pf->alloc_rss_size,
vsi->num_queue_pairs);
if (!vsi->rss_size)
return -EINVAL;
lut = kzalloc(vsi->rss_table_size, GFP_KERNEL);
if (!lut)
return -ENOMEM;
if (vsi->rss_lut_user)
memcpy(lut, vsi->rss_lut_user, vsi->rss_table_size);
else
i40e_fill_rss_lut(pf, lut, vsi->rss_table_size, vsi->rss_size);
if (vsi->rss_hkey_user)
memcpy(seed, vsi->rss_hkey_user, I40E_HKEY_ARRAY_SIZE);
else
netdev_rss_key_fill((void *)seed, I40E_HKEY_ARRAY_SIZE);
ret = i40e_config_rss_aq(vsi, seed, lut, vsi->rss_table_size);
kfree(lut);
return ret;
}
static int i40e_config_rss_reg(struct i40e_vsi *vsi, const u8 *seed,
const u8 *lut, u16 lut_size)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
u16 vf_id = vsi->vf_id;
u8 i;
if (seed) {
u32 *seed_dw = (u32 *)seed;
if (vsi->type == I40E_VSI_MAIN) {
for (i = 0; i <= I40E_PFQF_HKEY_MAX_INDEX; i++)
wr32(hw, I40E_PFQF_HKEY(i), seed_dw[i]);
} else if (vsi->type == I40E_VSI_SRIOV) {
for (i = 0; i <= I40E_VFQF_HKEY1_MAX_INDEX; i++)
wr32(hw, I40E_VFQF_HKEY1(i, vf_id), seed_dw[i]);
} else {
dev_err(&pf->pdev->dev, "Cannot set RSS seed - invalid VSI type\n");
}
}
if (lut) {
u32 *lut_dw = (u32 *)lut;
if (vsi->type == I40E_VSI_MAIN) {
if (lut_size != I40E_HLUT_ARRAY_SIZE)
return -EINVAL;
for (i = 0; i <= I40E_PFQF_HLUT_MAX_INDEX; i++)
wr32(hw, I40E_PFQF_HLUT(i), lut_dw[i]);
} else if (vsi->type == I40E_VSI_SRIOV) {
if (lut_size != I40E_VF_HLUT_ARRAY_SIZE)
return -EINVAL;
for (i = 0; i <= I40E_VFQF_HLUT_MAX_INDEX; i++)
wr32(hw, I40E_VFQF_HLUT1(i, vf_id), lut_dw[i]);
} else {
dev_err(&pf->pdev->dev, "Cannot set RSS LUT - invalid VSI type\n");
}
}
i40e_flush(hw);
return 0;
}
static int i40e_get_rss_reg(struct i40e_vsi *vsi, u8 *seed,
u8 *lut, u16 lut_size)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
u16 i;
if (seed) {
u32 *seed_dw = (u32 *)seed;
for (i = 0; i <= I40E_PFQF_HKEY_MAX_INDEX; i++)
seed_dw[i] = i40e_read_rx_ctl(hw, I40E_PFQF_HKEY(i));
}
if (lut) {
u32 *lut_dw = (u32 *)lut;
if (lut_size != I40E_HLUT_ARRAY_SIZE)
return -EINVAL;
for (i = 0; i <= I40E_PFQF_HLUT_MAX_INDEX; i++)
lut_dw[i] = rd32(hw, I40E_PFQF_HLUT(i));
}
return 0;
}
int i40e_config_rss(struct i40e_vsi *vsi, u8 *seed, u8 *lut, u16 lut_size)
{
struct i40e_pf *pf = vsi->back;
if (pf->flags & I40E_FLAG_RSS_AQ_CAPABLE)
return i40e_config_rss_aq(vsi, seed, lut, lut_size);
else
return i40e_config_rss_reg(vsi, seed, lut, lut_size);
}
int i40e_get_rss(struct i40e_vsi *vsi, u8 *seed, u8 *lut, u16 lut_size)
{
struct i40e_pf *pf = vsi->back;
if (pf->flags & I40E_FLAG_RSS_AQ_CAPABLE)
return i40e_get_rss_aq(vsi, seed, lut, lut_size);
else
return i40e_get_rss_reg(vsi, seed, lut, lut_size);
}
void i40e_fill_rss_lut(struct i40e_pf *pf, u8 *lut,
u16 rss_table_size, u16 rss_size)
{
u16 i;
for (i = 0; i < rss_table_size; i++)
lut[i] = i % rss_size;
}
static int i40e_pf_config_rss(struct i40e_pf *pf)
{
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
u8 seed[I40E_HKEY_ARRAY_SIZE];
u8 *lut;
struct i40e_hw *hw = &pf->hw;
u32 reg_val;
u64 hena;
int ret;
hena = (u64)i40e_read_rx_ctl(hw, I40E_PFQF_HENA(0)) |
((u64)i40e_read_rx_ctl(hw, I40E_PFQF_HENA(1)) << 32);
hena |= i40e_pf_get_default_rss_hena(pf);
i40e_write_rx_ctl(hw, I40E_PFQF_HENA(0), (u32)hena);
i40e_write_rx_ctl(hw, I40E_PFQF_HENA(1), (u32)(hena >> 32));
reg_val = i40e_read_rx_ctl(hw, I40E_PFQF_CTL_0);
reg_val = (pf->rss_table_size == 512) ?
(reg_val | I40E_PFQF_CTL_0_HASHLUTSIZE_512) :
(reg_val & ~I40E_PFQF_CTL_0_HASHLUTSIZE_512);
i40e_write_rx_ctl(hw, I40E_PFQF_CTL_0, reg_val);
if (!vsi->rss_size) {
u16 qcount;
qcount = vsi->num_queue_pairs / vsi->tc_config.numtc;
vsi->rss_size = min_t(int, pf->alloc_rss_size, qcount);
}
if (!vsi->rss_size)
return -EINVAL;
lut = kzalloc(vsi->rss_table_size, GFP_KERNEL);
if (!lut)
return -ENOMEM;
if (vsi->rss_lut_user)
memcpy(lut, vsi->rss_lut_user, vsi->rss_table_size);
else
i40e_fill_rss_lut(pf, lut, vsi->rss_table_size, vsi->rss_size);
if (vsi->rss_hkey_user)
memcpy(seed, vsi->rss_hkey_user, I40E_HKEY_ARRAY_SIZE);
else
netdev_rss_key_fill((void *)seed, I40E_HKEY_ARRAY_SIZE);
ret = i40e_config_rss(vsi, seed, lut, vsi->rss_table_size);
kfree(lut);
return ret;
}
int i40e_reconfig_rss_queues(struct i40e_pf *pf, int queue_count)
{
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
int new_rss_size;
if (!(pf->flags & I40E_FLAG_RSS_ENABLED))
return 0;
new_rss_size = min_t(int, queue_count, pf->rss_size_max);
if (queue_count != vsi->num_queue_pairs) {
u16 qcount;
vsi->req_queue_pairs = queue_count;
i40e_prep_for_reset(pf, true);
pf->alloc_rss_size = new_rss_size;
i40e_reset_and_rebuild(pf, true, true);
if (queue_count < vsi->rss_size) {
i40e_clear_rss_config_user(vsi);
dev_dbg(&pf->pdev->dev,
"discard user configured hash keys and lut\n");
}
qcount = vsi->num_queue_pairs / vsi->tc_config.numtc;
vsi->rss_size = min_t(int, pf->alloc_rss_size, qcount);
i40e_pf_config_rss(pf);
}
dev_info(&pf->pdev->dev, "User requested queue count/HW max RSS count: %d/%d\n",
vsi->req_queue_pairs, pf->rss_size_max);
return pf->alloc_rss_size;
}
i40e_status i40e_get_npar_bw_setting(struct i40e_pf *pf)
{
i40e_status status;
bool min_valid, max_valid;
u32 max_bw, min_bw;
status = i40e_read_bw_from_alt_ram(&pf->hw, &max_bw, &min_bw,
&min_valid, &max_valid);
if (!status) {
if (min_valid)
pf->npar_min_bw = min_bw;
if (max_valid)
pf->npar_max_bw = max_bw;
}
return status;
}
i40e_status i40e_set_npar_bw_setting(struct i40e_pf *pf)
{
struct i40e_aqc_configure_partition_bw_data bw_data;
i40e_status status;
bw_data.pf_valid_bits = cpu_to_le16(BIT(pf->hw.pf_id));
bw_data.max_bw[pf->hw.pf_id] = pf->npar_max_bw & I40E_ALT_BW_VALUE_MASK;
bw_data.min_bw[pf->hw.pf_id] = pf->npar_min_bw & I40E_ALT_BW_VALUE_MASK;
status = i40e_aq_configure_partition_bw(&pf->hw, &bw_data, NULL);
return status;
}
i40e_status i40e_commit_npar_bw_setting(struct i40e_pf *pf)
{
enum i40e_admin_queue_err last_aq_status;
i40e_status ret;
u16 nvm_word;
if (pf->hw.partition_id != 1) {
dev_info(&pf->pdev->dev,
"Commit BW only works on partition 1! This is partition %d",
pf->hw.partition_id);
ret = I40E_NOT_SUPPORTED;
goto bw_commit_out;
}
ret = i40e_acquire_nvm(&pf->hw, I40E_RESOURCE_READ);
last_aq_status = pf->hw.aq.asq_last_status;
if (ret) {
dev_info(&pf->pdev->dev,
"Cannot acquire NVM for read access, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, last_aq_status));
goto bw_commit_out;
}
ret = i40e_aq_read_nvm(&pf->hw,
I40E_SR_NVM_CONTROL_WORD,
0x10, sizeof(nvm_word), &nvm_word,
false, NULL);
last_aq_status = pf->hw.aq.asq_last_status;
i40e_release_nvm(&pf->hw);
if (ret) {
dev_info(&pf->pdev->dev, "NVM read error, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, last_aq_status));
goto bw_commit_out;
}
msleep(50);
ret = i40e_acquire_nvm(&pf->hw, I40E_RESOURCE_WRITE);
last_aq_status = pf->hw.aq.asq_last_status;
if (ret) {
dev_info(&pf->pdev->dev,
"Cannot acquire NVM for write access, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, last_aq_status));
goto bw_commit_out;
}
ret = i40e_aq_update_nvm(&pf->hw,
I40E_SR_NVM_CONTROL_WORD,
0x10, sizeof(nvm_word),
&nvm_word, true, NULL);
last_aq_status = pf->hw.aq.asq_last_status;
i40e_release_nvm(&pf->hw);
if (ret)
dev_info(&pf->pdev->dev,
"BW settings NOT SAVED, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, last_aq_status));
bw_commit_out:
return ret;
}
static int i40e_sw_init(struct i40e_pf *pf)
{
int err = 0;
int size;
pf->flags = I40E_FLAG_RX_CSUM_ENABLED |
I40E_FLAG_MSI_ENABLED |
I40E_FLAG_MSIX_ENABLED;
pf->rx_itr_default = I40E_ITR_DYNAMIC | I40E_ITR_RX_DEF;
pf->tx_itr_default = I40E_ITR_DYNAMIC | I40E_ITR_TX_DEF;
pf->rss_size_max = BIT(pf->hw.func_caps.rss_table_entry_width);
pf->alloc_rss_size = 1;
pf->rss_table_size = pf->hw.func_caps.rss_table_size;
pf->rss_size_max = min_t(int, pf->rss_size_max,
pf->hw.func_caps.num_tx_qp);
if (pf->hw.func_caps.rss) {
pf->flags |= I40E_FLAG_RSS_ENABLED;
pf->alloc_rss_size = min_t(int, pf->rss_size_max,
num_online_cpus());
}
if (pf->hw.func_caps.npar_enable || pf->hw.func_caps.flex10_enable) {
pf->flags |= I40E_FLAG_MFP_ENABLED;
dev_info(&pf->pdev->dev, "MFP mode Enabled\n");
if (i40e_get_npar_bw_setting(pf))
dev_warn(&pf->pdev->dev,
"Could not get NPAR bw settings\n");
else
dev_info(&pf->pdev->dev,
"Min BW = %8.8x, Max BW = %8.8x\n",
pf->npar_min_bw, pf->npar_max_bw);
}
if ((pf->hw.func_caps.fd_filters_guaranteed > 0) ||
(pf->hw.func_caps.fd_filters_best_effort > 0)) {
pf->flags |= I40E_FLAG_FD_ATR_ENABLED;
pf->atr_sample_rate = I40E_DEFAULT_ATR_SAMPLE_RATE;
if (pf->flags & I40E_FLAG_MFP_ENABLED &&
pf->hw.num_partitions > 1)
dev_info(&pf->pdev->dev,
"Flow Director Sideband mode Disabled in MFP mode\n");
else
pf->flags |= I40E_FLAG_FD_SB_ENABLED;
pf->fdir_pf_filter_count =
pf->hw.func_caps.fd_filters_guaranteed;
pf->hw.fdir_shared_filter_count =
pf->hw.func_caps.fd_filters_best_effort;
}
if ((pf->hw.mac.type == I40E_MAC_XL710) &&
(((pf->hw.aq.fw_maj_ver == 4) && (pf->hw.aq.fw_min_ver < 33)) ||
(pf->hw.aq.fw_maj_ver < 4))) {
pf->flags |= I40E_FLAG_RESTART_AUTONEG;
pf->flags |= I40E_FLAG_NO_DCB_SUPPORT;
}
if ((pf->hw.mac.type == I40E_MAC_XL710) &&
(((pf->hw.aq.fw_maj_ver == 4) && (pf->hw.aq.fw_min_ver < 3)) ||
(pf->hw.aq.fw_maj_ver < 4)))
pf->flags |= I40E_FLAG_STOP_FW_LLDP;
if ((pf->hw.mac.type == I40E_MAC_XL710) &&
(((pf->hw.aq.fw_maj_ver == 4) && (pf->hw.aq.fw_min_ver >= 40)) ||
(pf->hw.aq.fw_maj_ver >= 5)))
pf->flags |= I40E_FLAG_USE_SET_LLDP_MIB;
if (pf->hw.func_caps.vmdq) {
pf->num_vmdq_vsis = I40E_DEFAULT_NUM_VMDQ_VSI;
pf->flags |= I40E_FLAG_VMDQ_ENABLED;
pf->num_vmdq_qps = i40e_default_queues_per_vmdq(pf);
}
if (pf->hw.func_caps.iwarp) {
pf->flags |= I40E_FLAG_IWARP_ENABLED;
pf->num_iwarp_msix = (int)num_online_cpus() + 1;
}
#ifdef CONFIG_PCI_IOV
if (pf->hw.func_caps.num_vfs && pf->hw.partition_id == 1) {
pf->num_vf_qps = I40E_DEFAULT_QUEUES_PER_VF;
pf->flags |= I40E_FLAG_SRIOV_ENABLED;
pf->num_req_vfs = min_t(int,
pf->hw.func_caps.num_vfs,
I40E_MAX_VF_COUNT);
}
#endif
if (pf->hw.mac.type == I40E_MAC_X722) {
pf->flags |= I40E_FLAG_RSS_AQ_CAPABLE
| I40E_FLAG_128_QP_RSS_CAPABLE
| I40E_FLAG_HW_ATR_EVICT_CAPABLE
| I40E_FLAG_OUTER_UDP_CSUM_CAPABLE
| I40E_FLAG_WB_ON_ITR_CAPABLE
| I40E_FLAG_MULTIPLE_TCP_UDP_RSS_PCTYPE
| I40E_FLAG_NO_PCI_LINK_CHECK
| I40E_FLAG_USE_SET_LLDP_MIB
| I40E_FLAG_GENEVE_OFFLOAD_CAPABLE
| I40E_FLAG_PTP_L4_CAPABLE
| I40E_FLAG_WOL_MC_MAGIC_PKT_WAKE;
} else if ((pf->hw.aq.api_maj_ver > 1) ||
((pf->hw.aq.api_maj_ver == 1) &&
(pf->hw.aq.api_min_ver > 4))) {
pf->flags |= I40E_FLAG_GENEVE_OFFLOAD_CAPABLE;
}
if (pf->flags & I40E_FLAG_HW_ATR_EVICT_CAPABLE)
pf->flags |= I40E_FLAG_HW_ATR_EVICT_ENABLED;
pf->eeprom_version = 0xDEAD;
pf->lan_veb = I40E_NO_VEB;
pf->lan_vsi = I40E_NO_VSI;
pf->flags &= ~I40E_FLAG_VEB_STATS_ENABLED;
size = sizeof(struct i40e_lump_tracking)
+ (sizeof(u16) * pf->hw.func_caps.num_tx_qp);
pf->qp_pile = kzalloc(size, GFP_KERNEL);
if (!pf->qp_pile) {
err = -ENOMEM;
goto sw_init_done;
}
pf->qp_pile->num_entries = pf->hw.func_caps.num_tx_qp;
pf->qp_pile->search_hint = 0;
pf->tx_timeout_recovery_level = 1;
mutex_init(&pf->switch_mutex);
if (pf->hw.func_caps.npar_enable && (!i40e_get_npar_bw_setting(pf)))
i40e_set_npar_bw_setting(pf);
sw_init_done:
return err;
}
bool i40e_set_ntuple(struct i40e_pf *pf, netdev_features_t features)
{
bool need_reset = false;
if (features & NETIF_F_NTUPLE) {
if (!(pf->flags & I40E_FLAG_FD_SB_ENABLED))
need_reset = true;
if (pf->num_fdsb_msix > 0)
pf->flags |= I40E_FLAG_FD_SB_ENABLED;
} else {
if (pf->flags & I40E_FLAG_FD_SB_ENABLED) {
need_reset = true;
i40e_fdir_filter_exit(pf);
}
pf->flags &= ~(I40E_FLAG_FD_SB_ENABLED |
I40E_FLAG_FD_SB_AUTO_DISABLED);
pf->fd_add_err = 0;
pf->fd_atr_cnt = 0;
if (pf->flags & I40E_FLAG_FD_ATR_AUTO_DISABLED) {
pf->flags &= ~I40E_FLAG_FD_ATR_AUTO_DISABLED;
if ((pf->flags & I40E_FLAG_FD_ATR_ENABLED) &&
(I40E_DEBUG_FD & pf->hw.debug_mask))
dev_info(&pf->pdev->dev, "ATR re-enabled.\n");
}
}
return need_reset;
}
static void i40e_clear_rss_lut(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
u16 vf_id = vsi->vf_id;
u8 i;
if (vsi->type == I40E_VSI_MAIN) {
for (i = 0; i <= I40E_PFQF_HLUT_MAX_INDEX; i++)
wr32(hw, I40E_PFQF_HLUT(i), 0);
} else if (vsi->type == I40E_VSI_SRIOV) {
for (i = 0; i <= I40E_VFQF_HLUT_MAX_INDEX; i++)
i40e_write_rx_ctl(hw, I40E_VFQF_HLUT1(i, vf_id), 0);
} else {
dev_err(&pf->pdev->dev, "Cannot set RSS LUT - invalid VSI type\n");
}
}
static int i40e_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
bool need_reset;
if (features & NETIF_F_RXHASH && !(netdev->features & NETIF_F_RXHASH))
i40e_pf_config_rss(pf);
else if (!(features & NETIF_F_RXHASH) &&
netdev->features & NETIF_F_RXHASH)
i40e_clear_rss_lut(vsi);
if (features & NETIF_F_HW_VLAN_CTAG_RX)
i40e_vlan_stripping_enable(vsi);
else
i40e_vlan_stripping_disable(vsi);
need_reset = i40e_set_ntuple(pf, features);
if (need_reset)
i40e_do_reset(pf, BIT_ULL(__I40E_PF_RESET_REQUESTED), true);
return 0;
}
static u8 i40e_get_udp_port_idx(struct i40e_pf *pf, u16 port)
{
u8 i;
for (i = 0; i < I40E_MAX_PF_UDP_OFFLOAD_PORTS; i++) {
if (pf->udp_ports[i].port == port)
return i;
}
return i;
}
static void i40e_udp_tunnel_add(struct net_device *netdev,
struct udp_tunnel_info *ti)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
u16 port = ntohs(ti->port);
u8 next_idx;
u8 idx;
idx = i40e_get_udp_port_idx(pf, port);
if (idx < I40E_MAX_PF_UDP_OFFLOAD_PORTS) {
netdev_info(netdev, "port %d already offloaded\n", port);
return;
}
next_idx = i40e_get_udp_port_idx(pf, 0);
if (next_idx == I40E_MAX_PF_UDP_OFFLOAD_PORTS) {
netdev_info(netdev, "maximum number of offloaded UDP ports reached, not adding port %d\n",
port);
return;
}
switch (ti->type) {
case UDP_TUNNEL_TYPE_VXLAN:
pf->udp_ports[next_idx].type = I40E_AQC_TUNNEL_TYPE_VXLAN;
break;
case UDP_TUNNEL_TYPE_GENEVE:
if (!(pf->flags & I40E_FLAG_GENEVE_OFFLOAD_CAPABLE))
return;
pf->udp_ports[next_idx].type = I40E_AQC_TUNNEL_TYPE_NGE;
break;
default:
return;
}
pf->udp_ports[next_idx].port = port;
pf->pending_udp_bitmap |= BIT_ULL(next_idx);
pf->flags |= I40E_FLAG_UDP_FILTER_SYNC;
}
static void i40e_udp_tunnel_del(struct net_device *netdev,
struct udp_tunnel_info *ti)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
u16 port = ntohs(ti->port);
u8 idx;
idx = i40e_get_udp_port_idx(pf, port);
if (idx >= I40E_MAX_PF_UDP_OFFLOAD_PORTS)
goto not_found;
switch (ti->type) {
case UDP_TUNNEL_TYPE_VXLAN:
if (pf->udp_ports[idx].type != I40E_AQC_TUNNEL_TYPE_VXLAN)
goto not_found;
break;
case UDP_TUNNEL_TYPE_GENEVE:
if (pf->udp_ports[idx].type != I40E_AQC_TUNNEL_TYPE_NGE)
goto not_found;
break;
default:
goto not_found;
}
pf->udp_ports[idx].port = 0;
pf->pending_udp_bitmap |= BIT_ULL(idx);
pf->flags |= I40E_FLAG_UDP_FILTER_SYNC;
return;
not_found:
netdev_warn(netdev, "UDP port %d was not found, not deleting\n",
port);
}
static int i40e_get_phys_port_id(struct net_device *netdev,
struct netdev_phys_item_id *ppid)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_pf *pf = np->vsi->back;
struct i40e_hw *hw = &pf->hw;
if (!(pf->flags & I40E_FLAG_PORT_ID_VALID))
return -EOPNOTSUPP;
ppid->id_len = min_t(int, sizeof(hw->mac.port_addr), sizeof(ppid->id));
memcpy(ppid->id, hw->mac.port_addr, ppid->id_len);
return 0;
}
static int i40e_ndo_fdb_add(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev,
const unsigned char *addr, u16 vid,
u16 flags)
{
struct i40e_netdev_priv *np = netdev_priv(dev);
struct i40e_pf *pf = np->vsi->back;
int err = 0;
if (!(pf->flags & I40E_FLAG_SRIOV_ENABLED))
return -EOPNOTSUPP;
if (vid) {
pr_info("%s: vlans aren't supported yet for dev_uc|mc_add()\n", dev->name);
return -EINVAL;
}
if (ndm->ndm_state && !(ndm->ndm_state & NUD_PERMANENT)) {
netdev_info(dev, "FDB only supports static addresses\n");
return -EINVAL;
}
if (is_unicast_ether_addr(addr) || is_link_local_ether_addr(addr))
err = dev_uc_add_excl(dev, addr);
else if (is_multicast_ether_addr(addr))
err = dev_mc_add_excl(dev, addr);
else
err = -EINVAL;
if (err == -EEXIST && !(flags & NLM_F_EXCL))
err = 0;
return err;
}
static int i40e_ndo_bridge_setlink(struct net_device *dev,
struct nlmsghdr *nlh,
u16 flags)
{
struct i40e_netdev_priv *np = netdev_priv(dev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
struct i40e_veb *veb = NULL;
struct nlattr *attr, *br_spec;
int i, rem;
if (vsi->seid != pf->vsi[pf->lan_vsi]->seid)
return -EOPNOTSUPP;
for (i = 0; i < I40E_MAX_VEB && !veb; i++) {
if (pf->veb[i] && pf->veb[i]->seid == vsi->uplink_seid)
veb = pf->veb[i];
}
br_spec = nlmsg_find_attr(nlh, sizeof(struct ifinfomsg), IFLA_AF_SPEC);
nla_for_each_nested(attr, br_spec, rem) {
__u16 mode;
if (nla_type(attr) != IFLA_BRIDGE_MODE)
continue;
mode = nla_get_u16(attr);
if ((mode != BRIDGE_MODE_VEPA) &&
(mode != BRIDGE_MODE_VEB))
return -EINVAL;
if (!veb) {
veb = i40e_veb_setup(pf, 0, vsi->uplink_seid, vsi->seid,
vsi->tc_config.enabled_tc);
if (veb) {
veb->bridge_mode = mode;
i40e_config_bridge_mode(veb);
} else {
return -ENOENT;
}
break;
} else if (mode != veb->bridge_mode) {
veb->bridge_mode = mode;
if (mode == BRIDGE_MODE_VEB)
pf->flags |= I40E_FLAG_VEB_MODE_ENABLED;
else
pf->flags &= ~I40E_FLAG_VEB_MODE_ENABLED;
i40e_do_reset(pf, BIT_ULL(__I40E_PF_RESET_REQUESTED),
true);
break;
}
}
return 0;
}
static int i40e_ndo_bridge_getlink(struct sk_buff *skb, u32 pid, u32 seq,
struct net_device *dev,
u32 __always_unused filter_mask,
int nlflags)
{
struct i40e_netdev_priv *np = netdev_priv(dev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
struct i40e_veb *veb = NULL;
int i;
if (vsi->seid != pf->vsi[pf->lan_vsi]->seid)
return -EOPNOTSUPP;
for (i = 0; i < I40E_MAX_VEB && !veb; i++) {
if (pf->veb[i] && pf->veb[i]->seid == vsi->uplink_seid)
veb = pf->veb[i];
}
if (!veb)
return 0;
return ndo_dflt_bridge_getlink(skb, pid, seq, dev, veb->bridge_mode,
0, 0, nlflags, filter_mask, NULL);
}
static netdev_features_t i40e_features_check(struct sk_buff *skb,
struct net_device *dev,
netdev_features_t features)
{
size_t len;
if (skb->ip_summed != CHECKSUM_PARTIAL)
return features;
if (skb_is_gso(skb) && (skb_shinfo(skb)->gso_size < 64))
features &= ~NETIF_F_GSO_MASK;
len = skb_network_header(skb) - skb->data;
if (len & ~(63 * 2))
goto out_err;
len = skb_transport_header(skb) - skb_network_header(skb);
if (len & ~(127 * 4))
goto out_err;
if (skb->encapsulation) {
len = skb_inner_network_header(skb) - skb_transport_header(skb);
if (len & ~(127 * 2))
goto out_err;
len = skb_inner_transport_header(skb) -
skb_inner_network_header(skb);
if (len & ~(127 * 4))
goto out_err;
}
return features;
out_err:
return features & ~(NETIF_F_CSUM_MASK | NETIF_F_GSO_MASK);
}
static int i40e_config_netdev(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
struct i40e_netdev_priv *np;
struct net_device *netdev;
u8 broadcast[ETH_ALEN];
u8 mac_addr[ETH_ALEN];
int etherdev_size;
netdev_features_t hw_enc_features;
netdev_features_t hw_features;
etherdev_size = sizeof(struct i40e_netdev_priv);
netdev = alloc_etherdev_mq(etherdev_size, vsi->alloc_queue_pairs);
if (!netdev)
return -ENOMEM;
vsi->netdev = netdev;
np = netdev_priv(netdev);
np->vsi = vsi;
hw_enc_features = NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_HIGHDMA |
NETIF_F_SOFT_FEATURES |
NETIF_F_TSO |
NETIF_F_TSO_ECN |
NETIF_F_TSO6 |
NETIF_F_GSO_GRE |
NETIF_F_GSO_GRE_CSUM |
NETIF_F_GSO_PARTIAL |
NETIF_F_GSO_UDP_TUNNEL |
NETIF_F_GSO_UDP_TUNNEL_CSUM |
NETIF_F_SCTP_CRC |
NETIF_F_RXHASH |
NETIF_F_RXCSUM |
0;
if (!(pf->flags & I40E_FLAG_OUTER_UDP_CSUM_CAPABLE))
netdev->gso_partial_features |= NETIF_F_GSO_UDP_TUNNEL_CSUM;
netdev->gso_partial_features |= NETIF_F_GSO_GRE_CSUM;
netdev->hw_enc_features |= hw_enc_features;
netdev->vlan_features |= hw_enc_features | NETIF_F_TSO_MANGLEID;
if (!(pf->flags & I40E_FLAG_MFP_ENABLED))
netdev->hw_features |= NETIF_F_NTUPLE;
hw_features = hw_enc_features |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX;
netdev->hw_features |= hw_features;
netdev->features |= hw_features | NETIF_F_HW_VLAN_CTAG_FILTER;
netdev->hw_enc_features |= NETIF_F_TSO_MANGLEID;
if (vsi->type == I40E_VSI_MAIN) {
SET_NETDEV_DEV(netdev, &pf->pdev->dev);
ether_addr_copy(mac_addr, hw->mac.perm_addr);
i40e_rm_default_mac_filter(vsi, mac_addr);
spin_lock_bh(&vsi->mac_filter_hash_lock);
i40e_add_mac_filter(vsi, mac_addr);
spin_unlock_bh(&vsi->mac_filter_hash_lock);
} else {
snprintf(netdev->name, IFNAMSIZ, "%sv%%d",
pf->vsi[pf->lan_vsi]->netdev->name);
random_ether_addr(mac_addr);
spin_lock_bh(&vsi->mac_filter_hash_lock);
i40e_add_mac_filter(vsi, mac_addr);
spin_unlock_bh(&vsi->mac_filter_hash_lock);
}
eth_broadcast_addr(broadcast);
spin_lock_bh(&vsi->mac_filter_hash_lock);
i40e_add_mac_filter(vsi, broadcast);
spin_unlock_bh(&vsi->mac_filter_hash_lock);
ether_addr_copy(netdev->dev_addr, mac_addr);
ether_addr_copy(netdev->perm_addr, mac_addr);
netdev->priv_flags |= IFF_UNICAST_FLT;
netdev->priv_flags |= IFF_SUPP_NOFCS;
i40e_vsi_config_netdev_tc(vsi, vsi->tc_config.enabled_tc);
netdev->netdev_ops = &i40e_netdev_ops;
netdev->watchdog_timeo = 5 * HZ;
i40e_set_ethtool_ops(netdev);
netdev->min_mtu = ETH_MIN_MTU;
netdev->max_mtu = I40E_MAX_RXBUFFER -
(ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN);
return 0;
}
static void i40e_vsi_delete(struct i40e_vsi *vsi)
{
if (vsi == vsi->back->vsi[vsi->back->lan_vsi])
return;
i40e_aq_delete_element(&vsi->back->hw, vsi->seid, NULL);
}
int i40e_is_vsi_uplink_mode_veb(struct i40e_vsi *vsi)
{
struct i40e_veb *veb;
struct i40e_pf *pf = vsi->back;
if (vsi->veb_idx == I40E_NO_VEB)
return 1;
veb = pf->veb[vsi->veb_idx];
if (!veb) {
dev_info(&pf->pdev->dev,
"There is no veb associated with the bridge\n");
return -ENOENT;
}
if (veb->bridge_mode & BRIDGE_MODE_VEPA) {
return 0;
} else {
return 1;
}
return 0;
}
static int i40e_add_vsi(struct i40e_vsi *vsi)
{
int ret = -ENODEV;
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
struct i40e_vsi_context ctxt;
struct i40e_mac_filter *f;
struct hlist_node *h;
int bkt;
u8 enabled_tc = 0x1;
int f_count = 0;
memset(&ctxt, 0, sizeof(ctxt));
switch (vsi->type) {
case I40E_VSI_MAIN:
ctxt.seid = pf->main_vsi_seid;
ctxt.pf_num = pf->hw.pf_id;
ctxt.vf_num = 0;
ret = i40e_aq_get_vsi_params(&pf->hw, &ctxt, NULL);
ctxt.flags = I40E_AQ_VSI_TYPE_PF;
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't get PF vsi config, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
return -ENOENT;
}
vsi->info = ctxt.info;
vsi->info.valid_sections = 0;
vsi->seid = ctxt.seid;
vsi->id = ctxt.vsi_number;
enabled_tc = i40e_pf_get_tc_map(pf);
if ((pf->flags & I40E_FLAG_MFP_ENABLED) &&
!(pf->hw.func_caps.iscsi)) {
memset(&ctxt, 0, sizeof(ctxt));
ctxt.seid = pf->main_vsi_seid;
ctxt.pf_num = pf->hw.pf_id;
ctxt.vf_num = 0;
i40e_vsi_setup_queue_map(vsi, &ctxt, enabled_tc, false);
ret = i40e_aq_update_vsi_params(hw, &ctxt, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"update vsi failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
ret = -ENOENT;
goto err;
}
i40e_vsi_update_queue_map(vsi, &ctxt);
vsi->info.valid_sections = 0;
} else {
ret = i40e_vsi_config_tc(vsi, enabled_tc);
if (ret) {
dev_info(&pf->pdev->dev,
"failed to configure TCs for main VSI tc_map 0x%08x, err %s aq_err %s\n",
enabled_tc,
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
ret = -ENOENT;
}
}
break;
case I40E_VSI_FDIR:
ctxt.pf_num = hw->pf_id;
ctxt.vf_num = 0;
ctxt.uplink_seid = vsi->uplink_seid;
ctxt.connection_type = I40E_AQ_VSI_CONN_TYPE_NORMAL;
ctxt.flags = I40E_AQ_VSI_TYPE_PF;
if ((pf->flags & I40E_FLAG_VEB_MODE_ENABLED) &&
(i40e_is_vsi_uplink_mode_veb(vsi))) {
ctxt.info.valid_sections |=
cpu_to_le16(I40E_AQ_VSI_PROP_SWITCH_VALID);
ctxt.info.switch_id =
cpu_to_le16(I40E_AQ_VSI_SW_ID_FLAG_ALLOW_LB);
}
i40e_vsi_setup_queue_map(vsi, &ctxt, enabled_tc, true);
break;
case I40E_VSI_VMDQ2:
ctxt.pf_num = hw->pf_id;
ctxt.vf_num = 0;
ctxt.uplink_seid = vsi->uplink_seid;
ctxt.connection_type = I40E_AQ_VSI_CONN_TYPE_NORMAL;
ctxt.flags = I40E_AQ_VSI_TYPE_VMDQ2;
if (i40e_is_vsi_uplink_mode_veb(vsi)) {
ctxt.info.valid_sections |=
cpu_to_le16(I40E_AQ_VSI_PROP_SWITCH_VALID);
ctxt.info.switch_id =
cpu_to_le16(I40E_AQ_VSI_SW_ID_FLAG_ALLOW_LB);
}
i40e_vsi_setup_queue_map(vsi, &ctxt, enabled_tc, true);
break;
case I40E_VSI_SRIOV:
ctxt.pf_num = hw->pf_id;
ctxt.vf_num = vsi->vf_id + hw->func_caps.vf_base_id;
ctxt.uplink_seid = vsi->uplink_seid;
ctxt.connection_type = I40E_AQ_VSI_CONN_TYPE_NORMAL;
ctxt.flags = I40E_AQ_VSI_TYPE_VF;
if (i40e_is_vsi_uplink_mode_veb(vsi)) {
ctxt.info.valid_sections |=
cpu_to_le16(I40E_AQ_VSI_PROP_SWITCH_VALID);
ctxt.info.switch_id =
cpu_to_le16(I40E_AQ_VSI_SW_ID_FLAG_ALLOW_LB);
}
if (vsi->back->flags & I40E_FLAG_IWARP_ENABLED) {
ctxt.info.valid_sections |=
cpu_to_le16(I40E_AQ_VSI_PROP_QUEUE_OPT_VALID);
ctxt.info.queueing_opt_flags |=
(I40E_AQ_VSI_QUE_OPT_TCP_ENA |
I40E_AQ_VSI_QUE_OPT_RSS_LUT_VSI);
}
ctxt.info.valid_sections |= cpu_to_le16(I40E_AQ_VSI_PROP_VLAN_VALID);
ctxt.info.port_vlan_flags |= I40E_AQ_VSI_PVLAN_MODE_ALL;
if (pf->vf[vsi->vf_id].spoofchk) {
ctxt.info.valid_sections |=
cpu_to_le16(I40E_AQ_VSI_PROP_SECURITY_VALID);
ctxt.info.sec_flags |=
(I40E_AQ_VSI_SEC_FLAG_ENABLE_VLAN_CHK |
I40E_AQ_VSI_SEC_FLAG_ENABLE_MAC_CHK);
}
i40e_vsi_setup_queue_map(vsi, &ctxt, enabled_tc, true);
break;
case I40E_VSI_IWARP:
break;
default:
return -ENODEV;
}
if (vsi->type != I40E_VSI_MAIN) {
ret = i40e_aq_add_vsi(hw, &ctxt, NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"add vsi failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
ret = -ENOENT;
goto err;
}
vsi->info = ctxt.info;
vsi->info.valid_sections = 0;
vsi->seid = ctxt.seid;
vsi->id = ctxt.vsi_number;
}
vsi->active_filters = 0;
clear_bit(__I40E_VSI_OVERFLOW_PROMISC, vsi->state);
spin_lock_bh(&vsi->mac_filter_hash_lock);
hash_for_each_safe(vsi->mac_filter_hash, bkt, h, f, hlist) {
f->state = I40E_FILTER_NEW;
f_count++;
}
spin_unlock_bh(&vsi->mac_filter_hash_lock);
if (f_count) {
vsi->flags |= I40E_VSI_FLAG_FILTER_CHANGED;
pf->flags |= I40E_FLAG_FILTER_SYNC;
}
ret = i40e_vsi_get_bw_info(vsi);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't get vsi bw info, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
ret = 0;
}
err:
return ret;
}
int i40e_vsi_release(struct i40e_vsi *vsi)
{
struct i40e_mac_filter *f;
struct hlist_node *h;
struct i40e_veb *veb = NULL;
struct i40e_pf *pf;
u16 uplink_seid;
int i, n, bkt;
pf = vsi->back;
if (vsi->flags & I40E_VSI_FLAG_VEB_OWNER) {
dev_info(&pf->pdev->dev, "VSI %d has existing VEB %d\n",
vsi->seid, vsi->uplink_seid);
return -ENODEV;
}
if (vsi == pf->vsi[pf->lan_vsi] &&
!test_bit(__I40E_DOWN, pf->state)) {
dev_info(&pf->pdev->dev, "Can't remove PF VSI\n");
return -ENODEV;
}
uplink_seid = vsi->uplink_seid;
if (vsi->type != I40E_VSI_SRIOV) {
if (vsi->netdev_registered) {
vsi->netdev_registered = false;
if (vsi->netdev) {
unregister_netdev(vsi->netdev);
}
} else {
i40e_vsi_close(vsi);
}
i40e_vsi_disable_irq(vsi);
}
spin_lock_bh(&vsi->mac_filter_hash_lock);
if (vsi->netdev) {
__dev_uc_unsync(vsi->netdev, NULL);
__dev_mc_unsync(vsi->netdev, NULL);
}
hash_for_each_safe(vsi->mac_filter_hash, bkt, h, f, hlist)
__i40e_del_filter(vsi, f);
spin_unlock_bh(&vsi->mac_filter_hash_lock);
i40e_sync_vsi_filters(vsi);
i40e_vsi_delete(vsi);
i40e_vsi_free_q_vectors(vsi);
if (vsi->netdev) {
free_netdev(vsi->netdev);
vsi->netdev = NULL;
}
i40e_vsi_clear_rings(vsi);
i40e_vsi_clear(vsi);
for (n = 0, i = 0; i < pf->num_alloc_vsi; i++) {
if (pf->vsi[i] &&
pf->vsi[i]->uplink_seid == uplink_seid &&
(pf->vsi[i]->flags & I40E_VSI_FLAG_VEB_OWNER) == 0) {
n++;
}
}
for (i = 0; i < I40E_MAX_VEB; i++) {
if (!pf->veb[i])
continue;
if (pf->veb[i]->uplink_seid == uplink_seid)
n++;
if (pf->veb[i]->seid == uplink_seid)
veb = pf->veb[i];
}
if (n == 0 && veb && veb->uplink_seid != 0)
i40e_veb_release(veb);
return 0;
}
static int i40e_vsi_setup_vectors(struct i40e_vsi *vsi)
{
int ret = -ENOENT;
struct i40e_pf *pf = vsi->back;
if (vsi->q_vectors[0]) {
dev_info(&pf->pdev->dev, "VSI %d has existing q_vectors\n",
vsi->seid);
return -EEXIST;
}
if (vsi->base_vector) {
dev_info(&pf->pdev->dev, "VSI %d has non-zero base vector %d\n",
vsi->seid, vsi->base_vector);
return -EEXIST;
}
ret = i40e_vsi_alloc_q_vectors(vsi);
if (ret) {
dev_info(&pf->pdev->dev,
"failed to allocate %d q_vector for VSI %d, ret=%d\n",
vsi->num_q_vectors, vsi->seid, ret);
vsi->num_q_vectors = 0;
goto vector_setup_out;
}
if (!(pf->flags & I40E_FLAG_MSIX_ENABLED))
return ret;
if (vsi->num_q_vectors)
vsi->base_vector = i40e_get_lump(pf, pf->irq_pile,
vsi->num_q_vectors, vsi->idx);
if (vsi->base_vector < 0) {
dev_info(&pf->pdev->dev,
"failed to get tracking for %d vectors for VSI %d, err=%d\n",
vsi->num_q_vectors, vsi->seid, vsi->base_vector);
i40e_vsi_free_q_vectors(vsi);
ret = -ENOENT;
goto vector_setup_out;
}
vector_setup_out:
return ret;
}
static struct i40e_vsi *i40e_vsi_reinit_setup(struct i40e_vsi *vsi)
{
struct i40e_pf *pf;
u8 enabled_tc;
int ret;
if (!vsi)
return NULL;
pf = vsi->back;
i40e_put_lump(pf->qp_pile, vsi->base_queue, vsi->idx);
i40e_vsi_clear_rings(vsi);
i40e_vsi_free_arrays(vsi, false);
i40e_set_num_rings_in_vsi(vsi);
ret = i40e_vsi_alloc_arrays(vsi, false);
if (ret)
goto err_vsi;
ret = i40e_get_lump(pf, pf->qp_pile, vsi->alloc_queue_pairs, vsi->idx);
if (ret < 0) {
dev_info(&pf->pdev->dev,
"failed to get tracking for %d queues for VSI %d err %d\n",
vsi->alloc_queue_pairs, vsi->seid, ret);
goto err_vsi;
}
vsi->base_queue = ret;
enabled_tc = pf->vsi[pf->lan_vsi]->tc_config.enabled_tc;
pf->vsi[pf->lan_vsi]->tc_config.enabled_tc = 0;
pf->vsi[pf->lan_vsi]->seid = pf->main_vsi_seid;
i40e_vsi_config_tc(pf->vsi[pf->lan_vsi], enabled_tc);
if (vsi->type == I40E_VSI_MAIN)
i40e_rm_default_mac_filter(vsi, pf->hw.mac.perm_addr);
ret = i40e_alloc_rings(vsi);
if (ret)
goto err_rings;
i40e_vsi_map_rings_to_vectors(vsi);
return vsi;
err_rings:
i40e_vsi_free_q_vectors(vsi);
if (vsi->netdev_registered) {
vsi->netdev_registered = false;
unregister_netdev(vsi->netdev);
free_netdev(vsi->netdev);
vsi->netdev = NULL;
}
i40e_aq_delete_element(&pf->hw, vsi->seid, NULL);
err_vsi:
i40e_vsi_clear(vsi);
return NULL;
}
struct i40e_vsi *i40e_vsi_setup(struct i40e_pf *pf, u8 type,
u16 uplink_seid, u32 param1)
{
struct i40e_vsi *vsi = NULL;
struct i40e_veb *veb = NULL;
int ret, i;
int v_idx;
for (i = 0; i < I40E_MAX_VEB; i++) {
if (pf->veb[i] && pf->veb[i]->seid == uplink_seid) {
veb = pf->veb[i];
break;
}
}
if (!veb && uplink_seid != pf->mac_seid) {
for (i = 0; i < pf->num_alloc_vsi; i++) {
if (pf->vsi[i] && pf->vsi[i]->seid == uplink_seid) {
vsi = pf->vsi[i];
break;
}
}
if (!vsi) {
dev_info(&pf->pdev->dev, "no such uplink_seid %d\n",
uplink_seid);
return NULL;
}
if (vsi->uplink_seid == pf->mac_seid)
veb = i40e_veb_setup(pf, 0, pf->mac_seid, vsi->seid,
vsi->tc_config.enabled_tc);
else if ((vsi->flags & I40E_VSI_FLAG_VEB_OWNER) == 0)
veb = i40e_veb_setup(pf, 0, vsi->uplink_seid, vsi->seid,
vsi->tc_config.enabled_tc);
if (veb) {
if (vsi->seid != pf->vsi[pf->lan_vsi]->seid) {
dev_info(&vsi->back->pdev->dev,
"New VSI creation error, uplink seid of LAN VSI expected.\n");
return NULL;
}
if (!(pf->flags & I40E_FLAG_VEB_MODE_ENABLED)) {
veb->bridge_mode = BRIDGE_MODE_VEPA;
pf->flags &= ~I40E_FLAG_VEB_MODE_ENABLED;
}
i40e_config_bridge_mode(veb);
}
for (i = 0; i < I40E_MAX_VEB && !veb; i++) {
if (pf->veb[i] && pf->veb[i]->seid == vsi->uplink_seid)
veb = pf->veb[i];
}
if (!veb) {
dev_info(&pf->pdev->dev, "couldn't add VEB\n");
return NULL;
}
vsi->flags |= I40E_VSI_FLAG_VEB_OWNER;
uplink_seid = veb->seid;
}
v_idx = i40e_vsi_mem_alloc(pf, type);
if (v_idx < 0)
goto err_alloc;
vsi = pf->vsi[v_idx];
if (!vsi)
goto err_alloc;
vsi->type = type;
vsi->veb_idx = (veb ? veb->idx : I40E_NO_VEB);
if (type == I40E_VSI_MAIN)
pf->lan_vsi = v_idx;
else if (type == I40E_VSI_SRIOV)
vsi->vf_id = param1;
ret = i40e_get_lump(pf, pf->qp_pile, vsi->alloc_queue_pairs,
vsi->idx);
if (ret < 0) {
dev_info(&pf->pdev->dev,
"failed to get tracking for %d queues for VSI %d err=%d\n",
vsi->alloc_queue_pairs, vsi->seid, ret);
goto err_vsi;
}
vsi->base_queue = ret;
vsi->uplink_seid = uplink_seid;
ret = i40e_add_vsi(vsi);
if (ret)
goto err_vsi;
switch (vsi->type) {
case I40E_VSI_MAIN:
if (!!(pf->flags & I40E_FLAG_PF_MAC)) {
ret = i40e_macaddr_init(vsi, pf->hw.mac.addr);
if (ret) {
dev_warn(&pf->pdev->dev,
"could not set up macaddr; err %d\n",
ret);
}
}
case I40E_VSI_VMDQ2:
ret = i40e_config_netdev(vsi);
if (ret)
goto err_netdev;
ret = register_netdev(vsi->netdev);
if (ret)
goto err_netdev;
vsi->netdev_registered = true;
netif_carrier_off(vsi->netdev);
#ifdef CONFIG_I40E_DCB
i40e_dcbnl_setup(vsi);
#endif
case I40E_VSI_FDIR:
ret = i40e_vsi_setup_vectors(vsi);
if (ret)
goto err_msix;
ret = i40e_alloc_rings(vsi);
if (ret)
goto err_rings;
i40e_vsi_map_rings_to_vectors(vsi);
i40e_vsi_reset_stats(vsi);
break;
default:
break;
}
if ((pf->flags & I40E_FLAG_RSS_AQ_CAPABLE) &&
(vsi->type == I40E_VSI_VMDQ2)) {
ret = i40e_vsi_config_rss(vsi);
}
return vsi;
err_rings:
i40e_vsi_free_q_vectors(vsi);
err_msix:
if (vsi->netdev_registered) {
vsi->netdev_registered = false;
unregister_netdev(vsi->netdev);
free_netdev(vsi->netdev);
vsi->netdev = NULL;
}
err_netdev:
i40e_aq_delete_element(&pf->hw, vsi->seid, NULL);
err_vsi:
i40e_vsi_clear(vsi);
err_alloc:
return NULL;
}
static int i40e_veb_get_bw_info(struct i40e_veb *veb)
{
struct i40e_aqc_query_switching_comp_ets_config_resp ets_data;
struct i40e_aqc_query_switching_comp_bw_config_resp bw_data;
struct i40e_pf *pf = veb->pf;
struct i40e_hw *hw = &pf->hw;
u32 tc_bw_max;
int ret = 0;
int i;
ret = i40e_aq_query_switch_comp_bw_config(hw, veb->seid,
&bw_data, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"query veb bw config failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, hw->aq.asq_last_status));
goto out;
}
ret = i40e_aq_query_switch_comp_ets_config(hw, veb->seid,
&ets_data, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"query veb bw ets config failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, hw->aq.asq_last_status));
goto out;
}
veb->bw_limit = le16_to_cpu(ets_data.port_bw_limit);
veb->bw_max_quanta = ets_data.tc_bw_max;
veb->is_abs_credits = bw_data.absolute_credits_enable;
veb->enabled_tc = ets_data.tc_valid_bits;
tc_bw_max = le16_to_cpu(bw_data.tc_bw_max[0]) |
(le16_to_cpu(bw_data.tc_bw_max[1]) << 16);
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
veb->bw_tc_share_credits[i] = bw_data.tc_bw_share_credits[i];
veb->bw_tc_limit_credits[i] =
le16_to_cpu(bw_data.tc_bw_limits[i]);
veb->bw_tc_max_quanta[i] = ((tc_bw_max >> (i*4)) & 0x7);
}
out:
return ret;
}
static int i40e_veb_mem_alloc(struct i40e_pf *pf)
{
int ret = -ENOENT;
struct i40e_veb *veb;
int i;
mutex_lock(&pf->switch_mutex);
i = 0;
while ((i < I40E_MAX_VEB) && (pf->veb[i] != NULL))
i++;
if (i >= I40E_MAX_VEB) {
ret = -ENOMEM;
goto err_alloc_veb;
}
veb = kzalloc(sizeof(*veb), GFP_KERNEL);
if (!veb) {
ret = -ENOMEM;
goto err_alloc_veb;
}
veb->pf = pf;
veb->idx = i;
veb->enabled_tc = 1;
pf->veb[i] = veb;
ret = i;
err_alloc_veb:
mutex_unlock(&pf->switch_mutex);
return ret;
}
static void i40e_switch_branch_release(struct i40e_veb *branch)
{
struct i40e_pf *pf = branch->pf;
u16 branch_seid = branch->seid;
u16 veb_idx = branch->idx;
int i;
for (i = 0; i < I40E_MAX_VEB; i++) {
if (!pf->veb[i])
continue;
if (pf->veb[i]->uplink_seid == branch->seid)
i40e_switch_branch_release(pf->veb[i]);
}
for (i = 0; i < pf->num_alloc_vsi; i++) {
if (!pf->vsi[i])
continue;
if (pf->vsi[i]->uplink_seid == branch_seid &&
(pf->vsi[i]->flags & I40E_VSI_FLAG_VEB_OWNER) == 0) {
i40e_vsi_release(pf->vsi[i]);
}
}
if (pf->veb[veb_idx])
i40e_veb_release(pf->veb[veb_idx]);
}
static void i40e_veb_clear(struct i40e_veb *veb)
{
if (!veb)
return;
if (veb->pf) {
struct i40e_pf *pf = veb->pf;
mutex_lock(&pf->switch_mutex);
if (pf->veb[veb->idx] == veb)
pf->veb[veb->idx] = NULL;
mutex_unlock(&pf->switch_mutex);
}
kfree(veb);
}
void i40e_veb_release(struct i40e_veb *veb)
{
struct i40e_vsi *vsi = NULL;
struct i40e_pf *pf;
int i, n = 0;
pf = veb->pf;
for (i = 0; i < pf->num_alloc_vsi; i++) {
if (pf->vsi[i] && pf->vsi[i]->uplink_seid == veb->seid) {
n++;
vsi = pf->vsi[i];
}
}
if (n != 1) {
dev_info(&pf->pdev->dev,
"can't remove VEB %d with %d VSIs left\n",
veb->seid, n);
return;
}
vsi->flags &= ~I40E_VSI_FLAG_VEB_OWNER;
if (veb->uplink_seid) {
vsi->uplink_seid = veb->uplink_seid;
if (veb->uplink_seid == pf->mac_seid)
vsi->veb_idx = I40E_NO_VEB;
else
vsi->veb_idx = veb->veb_idx;
} else {
vsi->uplink_seid = pf->vsi[pf->lan_vsi]->uplink_seid;
vsi->veb_idx = pf->vsi[pf->lan_vsi]->veb_idx;
}
i40e_aq_delete_element(&pf->hw, veb->seid, NULL);
i40e_veb_clear(veb);
}
static int i40e_add_veb(struct i40e_veb *veb, struct i40e_vsi *vsi)
{
struct i40e_pf *pf = veb->pf;
bool enable_stats = !!(pf->flags & I40E_FLAG_VEB_STATS_ENABLED);
int ret;
ret = i40e_aq_add_veb(&pf->hw, veb->uplink_seid, vsi->seid,
veb->enabled_tc, false,
&veb->seid, enable_stats, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't add VEB, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
return -EPERM;
}
ret = i40e_aq_get_veb_parameters(&pf->hw, veb->seid, NULL, NULL,
&veb->stats_idx, NULL, NULL, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't get VEB statistics idx, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
return -EPERM;
}
ret = i40e_veb_get_bw_info(veb);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't get VEB bw info, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
i40e_aq_delete_element(&pf->hw, veb->seid, NULL);
return -ENOENT;
}
vsi->uplink_seid = veb->seid;
vsi->veb_idx = veb->idx;
vsi->flags |= I40E_VSI_FLAG_VEB_OWNER;
return 0;
}
struct i40e_veb *i40e_veb_setup(struct i40e_pf *pf, u16 flags,
u16 uplink_seid, u16 vsi_seid,
u8 enabled_tc)
{
struct i40e_veb *veb, *uplink_veb = NULL;
int vsi_idx, veb_idx;
int ret;
if ((uplink_seid == 0 || vsi_seid == 0) &&
(uplink_seid + vsi_seid != 0)) {
dev_info(&pf->pdev->dev,
"one, not both seid's are 0: uplink=%d vsi=%d\n",
uplink_seid, vsi_seid);
return NULL;
}
for (vsi_idx = 0; vsi_idx < pf->num_alloc_vsi; vsi_idx++)
if (pf->vsi[vsi_idx] && pf->vsi[vsi_idx]->seid == vsi_seid)
break;
if (vsi_idx >= pf->num_alloc_vsi && vsi_seid != 0) {
dev_info(&pf->pdev->dev, "vsi seid %d not found\n",
vsi_seid);
return NULL;
}
if (uplink_seid && uplink_seid != pf->mac_seid) {
for (veb_idx = 0; veb_idx < I40E_MAX_VEB; veb_idx++) {
if (pf->veb[veb_idx] &&
pf->veb[veb_idx]->seid == uplink_seid) {
uplink_veb = pf->veb[veb_idx];
break;
}
}
if (!uplink_veb) {
dev_info(&pf->pdev->dev,
"uplink seid %d not found\n", uplink_seid);
return NULL;
}
}
veb_idx = i40e_veb_mem_alloc(pf);
if (veb_idx < 0)
goto err_alloc;
veb = pf->veb[veb_idx];
veb->flags = flags;
veb->uplink_seid = uplink_seid;
veb->veb_idx = (uplink_veb ? uplink_veb->idx : I40E_NO_VEB);
veb->enabled_tc = (enabled_tc ? enabled_tc : 0x1);
ret = i40e_add_veb(veb, pf->vsi[vsi_idx]);
if (ret)
goto err_veb;
if (vsi_idx == pf->lan_vsi)
pf->lan_veb = veb->idx;
return veb;
err_veb:
i40e_veb_clear(veb);
err_alloc:
return NULL;
}
static void i40e_setup_pf_switch_element(struct i40e_pf *pf,
struct i40e_aqc_switch_config_element_resp *ele,
u16 num_reported, bool printconfig)
{
u16 downlink_seid = le16_to_cpu(ele->downlink_seid);
u16 uplink_seid = le16_to_cpu(ele->uplink_seid);
u8 element_type = ele->element_type;
u16 seid = le16_to_cpu(ele->seid);
if (printconfig)
dev_info(&pf->pdev->dev,
"type=%d seid=%d uplink=%d downlink=%d\n",
element_type, seid, uplink_seid, downlink_seid);
switch (element_type) {
case I40E_SWITCH_ELEMENT_TYPE_MAC:
pf->mac_seid = seid;
break;
case I40E_SWITCH_ELEMENT_TYPE_VEB:
if (uplink_seid != pf->mac_seid)
break;
if (pf->lan_veb == I40E_NO_VEB) {
int v;
for (v = 0; v < I40E_MAX_VEB; v++) {
if (pf->veb[v] && (pf->veb[v]->seid == seid)) {
pf->lan_veb = v;
break;
}
}
if (pf->lan_veb == I40E_NO_VEB) {
v = i40e_veb_mem_alloc(pf);
if (v < 0)
break;
pf->lan_veb = v;
}
}
pf->veb[pf->lan_veb]->seid = seid;
pf->veb[pf->lan_veb]->uplink_seid = pf->mac_seid;
pf->veb[pf->lan_veb]->pf = pf;
pf->veb[pf->lan_veb]->veb_idx = I40E_NO_VEB;
break;
case I40E_SWITCH_ELEMENT_TYPE_VSI:
if (num_reported != 1)
break;
pf->mac_seid = uplink_seid;
pf->pf_seid = downlink_seid;
pf->main_vsi_seid = seid;
if (printconfig)
dev_info(&pf->pdev->dev,
"pf_seid=%d main_vsi_seid=%d\n",
pf->pf_seid, pf->main_vsi_seid);
break;
case I40E_SWITCH_ELEMENT_TYPE_PF:
case I40E_SWITCH_ELEMENT_TYPE_VF:
case I40E_SWITCH_ELEMENT_TYPE_EMP:
case I40E_SWITCH_ELEMENT_TYPE_BMC:
case I40E_SWITCH_ELEMENT_TYPE_PE:
case I40E_SWITCH_ELEMENT_TYPE_PA:
break;
default:
dev_info(&pf->pdev->dev, "unknown element type=%d seid=%d\n",
element_type, seid);
break;
}
}
int i40e_fetch_switch_configuration(struct i40e_pf *pf, bool printconfig)
{
struct i40e_aqc_get_switch_config_resp *sw_config;
u16 next_seid = 0;
int ret = 0;
u8 *aq_buf;
int i;
aq_buf = kzalloc(I40E_AQ_LARGE_BUF, GFP_KERNEL);
if (!aq_buf)
return -ENOMEM;
sw_config = (struct i40e_aqc_get_switch_config_resp *)aq_buf;
do {
u16 num_reported, num_total;
ret = i40e_aq_get_switch_config(&pf->hw, sw_config,
I40E_AQ_LARGE_BUF,
&next_seid, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"get switch config failed err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
kfree(aq_buf);
return -ENOENT;
}
num_reported = le16_to_cpu(sw_config->header.num_reported);
num_total = le16_to_cpu(sw_config->header.num_total);
if (printconfig)
dev_info(&pf->pdev->dev,
"header: %d reported %d total\n",
num_reported, num_total);
for (i = 0; i < num_reported; i++) {
struct i40e_aqc_switch_config_element_resp *ele =
&sw_config->element[i];
i40e_setup_pf_switch_element(pf, ele, num_reported,
printconfig);
}
} while (next_seid != 0);
kfree(aq_buf);
return ret;
}
static int i40e_setup_pf_switch(struct i40e_pf *pf, bool reinit)
{
u16 flags = 0;
int ret;
ret = i40e_fetch_switch_configuration(pf, false);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't fetch switch config, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
return ret;
}
i40e_pf_reset_stats(pf);
if ((pf->hw.pf_id == 0) &&
!(pf->flags & I40E_FLAG_TRUE_PROMISC_SUPPORT))
flags = I40E_AQ_SET_SWITCH_CFG_PROMISC;
if (pf->hw.pf_id == 0) {
u16 valid_flags;
valid_flags = I40E_AQ_SET_SWITCH_CFG_PROMISC;
ret = i40e_aq_set_switch_config(&pf->hw, flags, valid_flags,
NULL);
if (ret && pf->hw.aq.asq_last_status != I40E_AQ_RC_ESRCH) {
dev_info(&pf->pdev->dev,
"couldn't set switch config bits, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, ret),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
}
}
if (pf->lan_vsi == I40E_NO_VSI || reinit) {
struct i40e_vsi *vsi = NULL;
u16 uplink_seid;
if (pf->lan_veb != I40E_NO_VEB && pf->veb[pf->lan_veb])
uplink_seid = pf->veb[pf->lan_veb]->seid;
else
uplink_seid = pf->mac_seid;
if (pf->lan_vsi == I40E_NO_VSI)
vsi = i40e_vsi_setup(pf, I40E_VSI_MAIN, uplink_seid, 0);
else if (reinit)
vsi = i40e_vsi_reinit_setup(pf->vsi[pf->lan_vsi]);
if (!vsi) {
dev_info(&pf->pdev->dev, "setup of MAIN VSI failed\n");
i40e_fdir_teardown(pf);
return -EAGAIN;
}
} else {
u8 enabled_tc = pf->vsi[pf->lan_vsi]->tc_config.enabled_tc;
pf->vsi[pf->lan_vsi]->tc_config.enabled_tc = 0;
pf->vsi[pf->lan_vsi]->seid = pf->main_vsi_seid;
i40e_vsi_config_tc(pf->vsi[pf->lan_vsi], enabled_tc);
}
i40e_vlan_stripping_disable(pf->vsi[pf->lan_vsi]);
i40e_fdir_sb_setup(pf);
ret = i40e_setup_pf_filter_control(pf);
if (ret) {
dev_info(&pf->pdev->dev, "setup_pf_filter_control failed: %d\n",
ret);
}
if ((pf->flags & I40E_FLAG_RSS_ENABLED))
i40e_pf_config_rss(pf);
i40e_link_event(pf);
pf->fc_autoneg_status = ((pf->hw.phy.link_info.an_info &
I40E_AQ_AN_COMPLETED) ? true : false);
i40e_ptp_init(pf);
i40e_sync_udp_filters(pf);
return ret;
}
static void i40e_determine_queue_usage(struct i40e_pf *pf)
{
int queues_left;
pf->num_lan_qps = 0;
queues_left = pf->hw.func_caps.num_tx_qp;
if ((queues_left == 1) ||
!(pf->flags & I40E_FLAG_MSIX_ENABLED)) {
queues_left = 0;
pf->alloc_rss_size = pf->num_lan_qps = 1;
pf->flags &= ~(I40E_FLAG_RSS_ENABLED |
I40E_FLAG_IWARP_ENABLED |
I40E_FLAG_FD_SB_ENABLED |
I40E_FLAG_FD_ATR_ENABLED |
I40E_FLAG_DCB_CAPABLE |
I40E_FLAG_DCB_ENABLED |
I40E_FLAG_SRIOV_ENABLED |
I40E_FLAG_VMDQ_ENABLED);
} else if (!(pf->flags & (I40E_FLAG_RSS_ENABLED |
I40E_FLAG_FD_SB_ENABLED |
I40E_FLAG_FD_ATR_ENABLED |
I40E_FLAG_DCB_CAPABLE))) {
pf->alloc_rss_size = pf->num_lan_qps = 1;
queues_left -= pf->num_lan_qps;
pf->flags &= ~(I40E_FLAG_RSS_ENABLED |
I40E_FLAG_IWARP_ENABLED |
I40E_FLAG_FD_SB_ENABLED |
I40E_FLAG_FD_ATR_ENABLED |
I40E_FLAG_DCB_ENABLED |
I40E_FLAG_VMDQ_ENABLED);
} else {
if ((pf->flags & I40E_FLAG_DCB_CAPABLE) &&
(queues_left < I40E_MAX_TRAFFIC_CLASS)) {
pf->flags &= ~(I40E_FLAG_DCB_CAPABLE |
I40E_FLAG_DCB_ENABLED);
dev_info(&pf->pdev->dev, "not enough queues for DCB. DCB is disabled.\n");
}
pf->num_lan_qps = max_t(int, pf->rss_size_max,
num_online_cpus());
pf->num_lan_qps = min_t(int, pf->num_lan_qps,
pf->hw.func_caps.num_tx_qp);
queues_left -= pf->num_lan_qps;
}
if (pf->flags & I40E_FLAG_FD_SB_ENABLED) {
if (queues_left > 1) {
queues_left -= 1;
} else {
pf->flags &= ~I40E_FLAG_FD_SB_ENABLED;
dev_info(&pf->pdev->dev, "not enough queues for Flow Director. Flow Director feature is disabled\n");
}
}
if ((pf->flags & I40E_FLAG_SRIOV_ENABLED) &&
pf->num_vf_qps && pf->num_req_vfs && queues_left) {
pf->num_req_vfs = min_t(int, pf->num_req_vfs,
(queues_left / pf->num_vf_qps));
queues_left -= (pf->num_req_vfs * pf->num_vf_qps);
}
if ((pf->flags & I40E_FLAG_VMDQ_ENABLED) &&
pf->num_vmdq_vsis && pf->num_vmdq_qps && queues_left) {
pf->num_vmdq_vsis = min_t(int, pf->num_vmdq_vsis,
(queues_left / pf->num_vmdq_qps));
queues_left -= (pf->num_vmdq_vsis * pf->num_vmdq_qps);
}
pf->queues_left = queues_left;
dev_dbg(&pf->pdev->dev,
"qs_avail=%d FD SB=%d lan_qs=%d lan_tc0=%d vf=%d*%d vmdq=%d*%d, remaining=%d\n",
pf->hw.func_caps.num_tx_qp,
!!(pf->flags & I40E_FLAG_FD_SB_ENABLED),
pf->num_lan_qps, pf->alloc_rss_size, pf->num_req_vfs,
pf->num_vf_qps, pf->num_vmdq_vsis, pf->num_vmdq_qps,
queues_left);
}
static int i40e_setup_pf_filter_control(struct i40e_pf *pf)
{
struct i40e_filter_control_settings *settings = &pf->filter_settings;
settings->hash_lut_size = I40E_HASH_LUT_SIZE_128;
if (pf->flags & (I40E_FLAG_FD_SB_ENABLED | I40E_FLAG_FD_ATR_ENABLED))
settings->enable_fdir = true;
settings->enable_ethtype = true;
settings->enable_macvlan = true;
if (i40e_set_filter_control(&pf->hw, settings))
return -ENOENT;
return 0;
}
static void i40e_print_features(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
char *buf;
int i;
buf = kmalloc(INFO_STRING_LEN, GFP_KERNEL);
if (!buf)
return;
i = snprintf(buf, INFO_STRING_LEN, "Features: PF-id[%d]", hw->pf_id);
#ifdef CONFIG_PCI_IOV
i += snprintf(&buf[i], REMAIN(i), " VFs: %d", pf->num_req_vfs);
#endif
i += snprintf(&buf[i], REMAIN(i), " VSIs: %d QP: %d",
pf->hw.func_caps.num_vsis,
pf->vsi[pf->lan_vsi]->num_queue_pairs);
if (pf->flags & I40E_FLAG_RSS_ENABLED)
i += snprintf(&buf[i], REMAIN(i), " RSS");
if (pf->flags & I40E_FLAG_FD_ATR_ENABLED)
i += snprintf(&buf[i], REMAIN(i), " FD_ATR");
if (pf->flags & I40E_FLAG_FD_SB_ENABLED) {
i += snprintf(&buf[i], REMAIN(i), " FD_SB");
i += snprintf(&buf[i], REMAIN(i), " NTUPLE");
}
if (pf->flags & I40E_FLAG_DCB_CAPABLE)
i += snprintf(&buf[i], REMAIN(i), " DCB");
i += snprintf(&buf[i], REMAIN(i), " VxLAN");
i += snprintf(&buf[i], REMAIN(i), " Geneve");
if (pf->flags & I40E_FLAG_PTP)
i += snprintf(&buf[i], REMAIN(i), " PTP");
if (pf->flags & I40E_FLAG_VEB_MODE_ENABLED)
i += snprintf(&buf[i], REMAIN(i), " VEB");
else
i += snprintf(&buf[i], REMAIN(i), " VEPA");
dev_info(&pf->pdev->dev, "%s\n", buf);
kfree(buf);
WARN_ON(i > INFO_STRING_LEN);
}
static void i40e_get_platform_mac_addr(struct pci_dev *pdev, struct i40e_pf *pf)
{
if (eth_platform_get_mac_address(&pdev->dev, pf->hw.mac.addr))
i40e_get_mac_addr(&pf->hw, pf->hw.mac.addr);
}
static int i40e_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct i40e_aq_get_phy_abilities_resp abilities;
struct i40e_pf *pf;
struct i40e_hw *hw;
static u16 pfs_found;
u16 wol_nvm_bits;
u16 link_status;
int err;
u32 val;
u32 i;
u8 set_fc_aq_fail;
err = pci_enable_device_mem(pdev);
if (err)
return err;
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
if (err) {
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev,
"DMA configuration failed: 0x%x\n", err);
goto err_dma;
}
}
err = pci_request_mem_regions(pdev, i40e_driver_name);
if (err) {
dev_info(&pdev->dev,
"pci_request_selected_regions failed %d\n", err);
goto err_pci_reg;
}
pci_enable_pcie_error_reporting(pdev);
pci_set_master(pdev);
pf = kzalloc(sizeof(*pf), GFP_KERNEL);
if (!pf) {
err = -ENOMEM;
goto err_pf_alloc;
}
pf->next_vsi = 0;
pf->pdev = pdev;
set_bit(__I40E_DOWN, pf->state);
hw = &pf->hw;
hw->back = pf;
pf->ioremap_len = min_t(int, pci_resource_len(pdev, 0),
I40E_MAX_CSR_SPACE);
hw->hw_addr = ioremap(pci_resource_start(pdev, 0), pf->ioremap_len);
if (!hw->hw_addr) {
err = -EIO;
dev_info(&pdev->dev, "ioremap(0x%04x, 0x%04x) failed: 0x%x\n",
(unsigned int)pci_resource_start(pdev, 0),
pf->ioremap_len, err);
goto err_ioremap;
}
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
pci_read_config_byte(pdev, PCI_REVISION_ID, &hw->revision_id);
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
hw->bus.device = PCI_SLOT(pdev->devfn);
hw->bus.func = PCI_FUNC(pdev->devfn);
hw->bus.bus_id = pdev->bus->number;
pf->instance = pfs_found;
INIT_LIST_HEAD(&pf->l3_flex_pit_list);
INIT_LIST_HEAD(&pf->l4_flex_pit_list);
mutex_init(&hw->aq.asq_mutex);
mutex_init(&hw->aq.arq_mutex);
pf->msg_enable = netif_msg_init(debug,
NETIF_MSG_DRV |
NETIF_MSG_PROBE |
NETIF_MSG_LINK);
if (debug < -1)
pf->hw.debug_mask = debug;
if (hw->revision_id == 0 &&
(rd32(hw, I40E_GLLAN_RCTL_0) & I40E_GLLAN_RCTL_0_PXE_MODE_MASK)) {
wr32(hw, I40E_GLGEN_RTRIG, I40E_GLGEN_RTRIG_CORER_MASK);
i40e_flush(hw);
msleep(200);
pf->corer_count++;
i40e_clear_pxe_mode(hw);
}
i40e_clear_hw(hw);
err = i40e_pf_reset(hw);
if (err) {
dev_info(&pdev->dev, "Initial pf_reset failed: %d\n", err);
goto err_pf_reset;
}
pf->pfr_count++;
hw->aq.num_arq_entries = I40E_AQ_LEN;
hw->aq.num_asq_entries = I40E_AQ_LEN;
hw->aq.arq_buf_size = I40E_MAX_AQ_BUF_SIZE;
hw->aq.asq_buf_size = I40E_MAX_AQ_BUF_SIZE;
pf->adminq_work_limit = I40E_AQ_WORK_LIMIT;
snprintf(pf->int_name, sizeof(pf->int_name) - 1,
"%s-%s:misc",
dev_driver_string(&pf->pdev->dev), dev_name(&pdev->dev));
err = i40e_init_shared_code(hw);
if (err) {
dev_warn(&pdev->dev, "unidentified MAC or BLANK NVM: %d\n",
err);
goto err_pf_reset;
}
pf->hw.fc.requested_mode = I40E_FC_NONE;
err = i40e_init_adminq(hw);
if (err) {
if (err == I40E_ERR_FIRMWARE_API_VERSION)
dev_info(&pdev->dev,
"The driver for the device stopped because the NVM image is newer than expected. You must install the most recent version of the network driver.\n");
else
dev_info(&pdev->dev,
"The driver for the device stopped because the device firmware failed to init. Try updating your NVM image.\n");
goto err_pf_reset;
}
dev_info(&pdev->dev, "fw %d.%d.%05d api %d.%d nvm %s\n",
hw->aq.fw_maj_ver, hw->aq.fw_min_ver, hw->aq.fw_build,
hw->aq.api_maj_ver, hw->aq.api_min_ver,
i40e_nvm_version_str(hw));
if (hw->aq.api_maj_ver == I40E_FW_API_VERSION_MAJOR &&
hw->aq.api_min_ver > I40E_FW_API_VERSION_MINOR)
dev_info(&pdev->dev,
"The driver for the device detected a newer version of the NVM image than expected. Please install the most recent version of the network driver.\n");
else if (hw->aq.api_maj_ver < I40E_FW_API_VERSION_MAJOR ||
hw->aq.api_min_ver < (I40E_FW_API_VERSION_MINOR - 1))
dev_info(&pdev->dev,
"The driver for the device detected an older version of the NVM image than expected. Please update the NVM image.\n");
i40e_verify_eeprom(pf);
if (hw->revision_id < 1)
dev_warn(&pdev->dev, "This device is a pre-production adapter/LOM. Please be aware there may be issues with your hardware. If you are experiencing problems please contact your Intel or hardware representative who provided you with this hardware.\n");
i40e_clear_pxe_mode(hw);
err = i40e_get_capabilities(pf);
if (err)
goto err_adminq_setup;
err = i40e_sw_init(pf);
if (err) {
dev_info(&pdev->dev, "sw_init failed: %d\n", err);
goto err_sw_init;
}
err = i40e_init_lan_hmc(hw, hw->func_caps.num_tx_qp,
hw->func_caps.num_rx_qp, 0, 0);
if (err) {
dev_info(&pdev->dev, "init_lan_hmc failed: %d\n", err);
goto err_init_lan_hmc;
}
err = i40e_configure_lan_hmc(hw, I40E_HMC_MODEL_DIRECT_ONLY);
if (err) {
dev_info(&pdev->dev, "configure_lan_hmc failed: %d\n", err);
err = -ENOENT;
goto err_configure_lan_hmc;
}
if (pf->flags & I40E_FLAG_STOP_FW_LLDP) {
dev_info(&pdev->dev, "Stopping firmware LLDP agent.\n");
i40e_aq_stop_lldp(hw, true, NULL);
}
i40e_get_platform_mac_addr(pdev, pf);
if (!is_valid_ether_addr(hw->mac.addr)) {
dev_info(&pdev->dev, "invalid MAC address %pM\n", hw->mac.addr);
err = -EIO;
goto err_mac_addr;
}
dev_info(&pdev->dev, "MAC address: %pM\n", hw->mac.addr);
ether_addr_copy(hw->mac.perm_addr, hw->mac.addr);
i40e_get_port_mac_addr(hw, hw->mac.port_addr);
if (is_valid_ether_addr(hw->mac.port_addr))
pf->flags |= I40E_FLAG_PORT_ID_VALID;
pci_set_drvdata(pdev, pf);
pci_save_state(pdev);
#ifdef CONFIG_I40E_DCB
err = i40e_init_pf_dcb(pf);
if (err) {
dev_info(&pdev->dev, "DCB init failed %d, disabled\n", err);
pf->flags &= ~(I40E_FLAG_DCB_CAPABLE | I40E_FLAG_DCB_ENABLED);
}
#endif
setup_timer(&pf->service_timer, i40e_service_timer, (unsigned long)pf);
pf->service_timer_period = HZ;
INIT_WORK(&pf->service_task, i40e_service_task);
clear_bit(__I40E_SERVICE_SCHED, pf->state);
i40e_read_nvm_word(hw, I40E_SR_NVM_WAKE_ON_LAN, &wol_nvm_bits);
if (BIT (hw->port) & wol_nvm_bits || hw->partition_id != 1)
pf->wol_en = false;
else
pf->wol_en = true;
device_set_wakeup_enable(&pf->pdev->dev, pf->wol_en);
i40e_determine_queue_usage(pf);
err = i40e_init_interrupt_scheme(pf);
if (err)
goto err_switch_setup;
if (pf->hw.func_caps.num_vsis < I40E_MIN_VSI_ALLOC)
pf->num_alloc_vsi = I40E_MIN_VSI_ALLOC;
else
pf->num_alloc_vsi = pf->hw.func_caps.num_vsis;
pf->vsi = kcalloc(pf->num_alloc_vsi, sizeof(struct i40e_vsi *),
GFP_KERNEL);
if (!pf->vsi) {
err = -ENOMEM;
goto err_switch_setup;
}
#ifdef CONFIG_PCI_IOV
if ((pf->flags & I40E_FLAG_SRIOV_ENABLED) &&
(pf->flags & I40E_FLAG_MSIX_ENABLED) &&
!test_bit(__I40E_BAD_EEPROM, pf->state)) {
if (pci_num_vf(pdev))
pf->flags |= I40E_FLAG_VEB_MODE_ENABLED;
}
#endif
err = i40e_setup_pf_switch(pf, false);
if (err) {
dev_info(&pdev->dev, "setup_pf_switch failed: %d\n", err);
goto err_vsis;
}
err = i40e_set_fc(hw, &set_fc_aq_fail, true);
if (set_fc_aq_fail & I40E_SET_FC_AQ_FAIL_GET)
dev_dbg(&pf->pdev->dev,
"Set fc with err %s aq_err %s on get_phy_cap\n",
i40e_stat_str(hw, err),
i40e_aq_str(hw, hw->aq.asq_last_status));
if (set_fc_aq_fail & I40E_SET_FC_AQ_FAIL_SET)
dev_dbg(&pf->pdev->dev,
"Set fc with err %s aq_err %s on set_phy_config\n",
i40e_stat_str(hw, err),
i40e_aq_str(hw, hw->aq.asq_last_status));
if (set_fc_aq_fail & I40E_SET_FC_AQ_FAIL_UPDATE)
dev_dbg(&pf->pdev->dev,
"Set fc with err %s aq_err %s on get_link_info\n",
i40e_stat_str(hw, err),
i40e_aq_str(hw, hw->aq.asq_last_status));
for (i = 0; i < pf->num_alloc_vsi; i++) {
if (pf->vsi[i] && pf->vsi[i]->type == I40E_VSI_FDIR) {
i40e_vsi_open(pf->vsi[i]);
break;
}
}
err = i40e_aq_set_phy_int_mask(&pf->hw,
~(I40E_AQ_EVENT_LINK_UPDOWN |
I40E_AQ_EVENT_MEDIA_NA |
I40E_AQ_EVENT_MODULE_QUAL_FAIL), NULL);
if (err)
dev_info(&pf->pdev->dev, "set phy mask fail, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, err),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
val = rd32(hw, I40E_REG_MSS);
if ((val & I40E_REG_MSS_MIN_MASK) > I40E_64BYTE_MSS) {
val &= ~I40E_REG_MSS_MIN_MASK;
val |= I40E_64BYTE_MSS;
wr32(hw, I40E_REG_MSS, val);
}
if (pf->flags & I40E_FLAG_RESTART_AUTONEG) {
msleep(75);
err = i40e_aq_set_link_restart_an(&pf->hw, true, NULL);
if (err)
dev_info(&pf->pdev->dev, "link restart failed, err %s aq_err %s\n",
i40e_stat_str(&pf->hw, err),
i40e_aq_str(&pf->hw,
pf->hw.aq.asq_last_status));
}
clear_bit(__I40E_DOWN, pf->state);
if (pf->flags & I40E_FLAG_MSIX_ENABLED) {
err = i40e_setup_misc_vector(pf);
if (err) {
dev_info(&pdev->dev,
"setup of misc vector failed: %d\n", err);
goto err_vsis;
}
}
#ifdef CONFIG_PCI_IOV
if ((pf->flags & I40E_FLAG_SRIOV_ENABLED) &&
(pf->flags & I40E_FLAG_MSIX_ENABLED) &&
!test_bit(__I40E_BAD_EEPROM, pf->state)) {
val = rd32(hw, I40E_PFGEN_PORTMDIO_NUM);
val &= ~I40E_PFGEN_PORTMDIO_NUM_VFLINK_STAT_ENA_MASK;
wr32(hw, I40E_PFGEN_PORTMDIO_NUM, val);
i40e_flush(hw);
if (pci_num_vf(pdev)) {
dev_info(&pdev->dev,
"Active VFs found, allocating resources.\n");
err = i40e_alloc_vfs(pf, pci_num_vf(pdev));
if (err)
dev_info(&pdev->dev,
"Error %d allocating resources for existing VFs\n",
err);
}
}
#endif
if (pf->flags & I40E_FLAG_IWARP_ENABLED) {
pf->iwarp_base_vector = i40e_get_lump(pf, pf->irq_pile,
pf->num_iwarp_msix,
I40E_IWARP_IRQ_PILE_ID);
if (pf->iwarp_base_vector < 0) {
dev_info(&pdev->dev,
"failed to get tracking for %d vectors for IWARP err=%d\n",
pf->num_iwarp_msix, pf->iwarp_base_vector);
pf->flags &= ~I40E_FLAG_IWARP_ENABLED;
}
}
i40e_dbg_pf_init(pf);
i40e_send_version(pf);
mod_timer(&pf->service_timer,
round_jiffies(jiffies + pf->service_timer_period));
if (pf->flags & I40E_FLAG_IWARP_ENABLED) {
err = i40e_lan_add_device(pf);
if (err)
dev_info(&pdev->dev, "Failed to add PF to client API service list: %d\n",
err);
}
#define PCI_SPEED_SIZE 8
#define PCI_WIDTH_SIZE 8
if (!(pf->flags & I40E_FLAG_NO_PCI_LINK_CHECK)) {
char speed[PCI_SPEED_SIZE] = "Unknown";
char width[PCI_WIDTH_SIZE] = "Unknown";
pcie_capability_read_word(pf->pdev, PCI_EXP_LNKSTA,
&link_status);
i40e_set_pci_config_data(hw, link_status);
switch (hw->bus.speed) {
case i40e_bus_speed_8000:
strncpy(speed, "8.0", PCI_SPEED_SIZE); break;
case i40e_bus_speed_5000:
strncpy(speed, "5.0", PCI_SPEED_SIZE); break;
case i40e_bus_speed_2500:
strncpy(speed, "2.5", PCI_SPEED_SIZE); break;
default:
break;
}
switch (hw->bus.width) {
case i40e_bus_width_pcie_x8:
strncpy(width, "8", PCI_WIDTH_SIZE); break;
case i40e_bus_width_pcie_x4:
strncpy(width, "4", PCI_WIDTH_SIZE); break;
case i40e_bus_width_pcie_x2:
strncpy(width, "2", PCI_WIDTH_SIZE); break;
case i40e_bus_width_pcie_x1:
strncpy(width, "1", PCI_WIDTH_SIZE); break;
default:
break;
}
dev_info(&pdev->dev, "PCI-Express: Speed %sGT/s Width x%s\n",
speed, width);
if (hw->bus.width < i40e_bus_width_pcie_x8 ||
hw->bus.speed < i40e_bus_speed_8000) {
dev_warn(&pdev->dev, "PCI-Express bandwidth available for this device may be insufficient for optimal performance.\n");
dev_warn(&pdev->dev, "Please move the device to a different PCI-e link with more lanes and/or higher transfer rate.\n");
}
}
err = i40e_aq_get_phy_capabilities(hw, false, false, &abilities, NULL);
if (err)
dev_dbg(&pf->pdev->dev, "get requested speeds ret = %s last_status = %s\n",
i40e_stat_str(&pf->hw, err),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
pf->hw.phy.link_info.requested_speeds = abilities.link_speed;
err = i40e_aq_get_phy_capabilities(hw, false, true, &abilities, NULL);
if (err)
dev_dbg(&pf->pdev->dev, "get supported phy types ret = %s last_status = %s\n",
i40e_stat_str(&pf->hw, err),
i40e_aq_str(&pf->hw, pf->hw.aq.asq_last_status));
i40e_add_filter_to_drop_tx_flow_control_frames(&pf->hw,
pf->main_vsi_seid);
if ((pf->hw.device_id == I40E_DEV_ID_10G_BASE_T) ||
(pf->hw.device_id == I40E_DEV_ID_10G_BASE_T4))
pf->flags |= I40E_FLAG_PHY_CONTROLS_LEDS;
if (pf->hw.device_id == I40E_DEV_ID_SFP_I_X722)
pf->flags |= I40E_FLAG_HAVE_CRT_RETIMER;
i40e_print_features(pf);
return 0;
err_vsis:
set_bit(__I40E_DOWN, pf->state);
i40e_clear_interrupt_scheme(pf);
kfree(pf->vsi);
err_switch_setup:
i40e_reset_interrupt_capability(pf);
del_timer_sync(&pf->service_timer);
err_mac_addr:
err_configure_lan_hmc:
(void)i40e_shutdown_lan_hmc(hw);
err_init_lan_hmc:
kfree(pf->qp_pile);
err_sw_init:
err_adminq_setup:
err_pf_reset:
iounmap(hw->hw_addr);
err_ioremap:
kfree(pf);
err_pf_alloc:
pci_disable_pcie_error_reporting(pdev);
pci_release_mem_regions(pdev);
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static void i40e_remove(struct pci_dev *pdev)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
struct i40e_hw *hw = &pf->hw;
i40e_status ret_code;
int i;
i40e_dbg_pf_exit(pf);
i40e_ptp_stop(pf);
i40e_write_rx_ctl(hw, I40E_PFQF_HENA(0), 0);
i40e_write_rx_ctl(hw, I40E_PFQF_HENA(1), 0);
set_bit(__I40E_SUSPENDED, pf->state);
set_bit(__I40E_DOWN, pf->state);
if (pf->service_timer.data)
del_timer_sync(&pf->service_timer);
if (pf->service_task.func)
cancel_work_sync(&pf->service_task);
i40e_notify_client_of_netdev_close(pf->vsi[pf->lan_vsi], false);
if (pf->flags & I40E_FLAG_SRIOV_ENABLED) {
i40e_free_vfs(pf);
pf->flags &= ~I40E_FLAG_SRIOV_ENABLED;
}
i40e_fdir_teardown(pf);
for (i = 0; i < I40E_MAX_VEB; i++) {
if (!pf->veb[i])
continue;
if (pf->veb[i]->uplink_seid == pf->mac_seid ||
pf->veb[i]->uplink_seid == 0)
i40e_switch_branch_release(pf->veb[i]);
}
if (pf->vsi[pf->lan_vsi])
i40e_vsi_release(pf->vsi[pf->lan_vsi]);
if (pf->flags & I40E_FLAG_IWARP_ENABLED) {
ret_code = i40e_lan_del_device(pf);
if (ret_code)
dev_warn(&pdev->dev, "Failed to delete client device: %d\n",
ret_code);
}
if (hw->hmc.hmc_obj) {
ret_code = i40e_shutdown_lan_hmc(hw);
if (ret_code)
dev_warn(&pdev->dev,
"Failed to destroy the HMC resources: %d\n",
ret_code);
}
i40e_shutdown_adminq(hw);
mutex_destroy(&hw->aq.arq_mutex);
mutex_destroy(&hw->aq.asq_mutex);
i40e_clear_interrupt_scheme(pf);
for (i = 0; i < pf->num_alloc_vsi; i++) {
if (pf->vsi[i]) {
i40e_vsi_clear_rings(pf->vsi[i]);
i40e_vsi_clear(pf->vsi[i]);
pf->vsi[i] = NULL;
}
}
for (i = 0; i < I40E_MAX_VEB; i++) {
kfree(pf->veb[i]);
pf->veb[i] = NULL;
}
kfree(pf->qp_pile);
kfree(pf->vsi);
iounmap(hw->hw_addr);
kfree(pf);
pci_release_mem_regions(pdev);
pci_disable_pcie_error_reporting(pdev);
pci_disable_device(pdev);
}
static pci_ers_result_t i40e_pci_error_detected(struct pci_dev *pdev,
enum pci_channel_state error)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
dev_info(&pdev->dev, "%s: error %d\n", __func__, error);
if (!pf) {
dev_info(&pdev->dev,
"Cannot recover - error happened during device probe\n");
return PCI_ERS_RESULT_DISCONNECT;
}
if (!test_bit(__I40E_SUSPENDED, pf->state)) {
rtnl_lock();
i40e_prep_for_reset(pf, true);
rtnl_unlock();
}
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t i40e_pci_error_slot_reset(struct pci_dev *pdev)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
pci_ers_result_t result;
int err;
u32 reg;
dev_dbg(&pdev->dev, "%s\n", __func__);
if (pci_enable_device_mem(pdev)) {
dev_info(&pdev->dev,
"Cannot re-enable PCI device after reset.\n");
result = PCI_ERS_RESULT_DISCONNECT;
} else {
pci_set_master(pdev);
pci_restore_state(pdev);
pci_save_state(pdev);
pci_wake_from_d3(pdev, false);
reg = rd32(&pf->hw, I40E_GLGEN_RTRIG);
if (reg == 0)
result = PCI_ERS_RESULT_RECOVERED;
else
result = PCI_ERS_RESULT_DISCONNECT;
}
err = pci_cleanup_aer_uncorrect_error_status(pdev);
if (err) {
dev_info(&pdev->dev,
"pci_cleanup_aer_uncorrect_error_status failed 0x%0x\n",
err);
}
return result;
}
static void i40e_pci_error_resume(struct pci_dev *pdev)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
dev_dbg(&pdev->dev, "%s\n", __func__);
if (test_bit(__I40E_SUSPENDED, pf->state))
return;
rtnl_lock();
i40e_handle_reset_warning(pf, true);
rtnl_unlock();
}
static void i40e_enable_mc_magic_wake(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
i40e_status ret;
u8 mac_addr[6];
u16 flags = 0;
if (pf->vsi[pf->lan_vsi] && pf->vsi[pf->lan_vsi]->netdev) {
ether_addr_copy(mac_addr,
pf->vsi[pf->lan_vsi]->netdev->dev_addr);
} else {
dev_err(&pf->pdev->dev,
"Failed to retrieve MAC address; using default\n");
ether_addr_copy(mac_addr, hw->mac.addr);
}
flags = I40E_AQC_WRITE_TYPE_LAA_WOL;
if (hw->func_caps.flex10_enable && hw->partition_id != 1)
flags = I40E_AQC_WRITE_TYPE_LAA_ONLY;
ret = i40e_aq_mac_address_write(hw, flags, mac_addr, NULL);
if (ret) {
dev_err(&pf->pdev->dev,
"Failed to update MAC address registers; cannot enable Multicast Magic packet wake up");
return;
}
flags = I40E_AQC_MC_MAG_EN
| I40E_AQC_WOL_PRESERVE_ON_PFR
| I40E_AQC_WRITE_TYPE_UPDATE_MC_MAG;
ret = i40e_aq_mac_address_write(hw, flags, mac_addr, NULL);
if (ret)
dev_err(&pf->pdev->dev,
"Failed to enable Multicast Magic Packet wake up\n");
}
static void i40e_shutdown(struct pci_dev *pdev)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
struct i40e_hw *hw = &pf->hw;
set_bit(__I40E_SUSPENDED, pf->state);
set_bit(__I40E_DOWN, pf->state);
rtnl_lock();
i40e_prep_for_reset(pf, true);
rtnl_unlock();
wr32(hw, I40E_PFPM_APM, (pf->wol_en ? I40E_PFPM_APM_APME_MASK : 0));
wr32(hw, I40E_PFPM_WUFC, (pf->wol_en ? I40E_PFPM_WUFC_MAG_MASK : 0));
del_timer_sync(&pf->service_timer);
cancel_work_sync(&pf->service_task);
i40e_fdir_teardown(pf);
i40e_notify_client_of_netdev_close(pf->vsi[pf->lan_vsi], false);
if (pf->wol_en && (pf->flags & I40E_FLAG_WOL_MC_MAGIC_PKT_WAKE))
i40e_enable_mc_magic_wake(pf);
rtnl_lock();
i40e_prep_for_reset(pf, true);
rtnl_unlock();
wr32(hw, I40E_PFPM_APM,
(pf->wol_en ? I40E_PFPM_APM_APME_MASK : 0));
wr32(hw, I40E_PFPM_WUFC,
(pf->wol_en ? I40E_PFPM_WUFC_MAG_MASK : 0));
i40e_clear_interrupt_scheme(pf);
if (system_state == SYSTEM_POWER_OFF) {
pci_wake_from_d3(pdev, pf->wol_en);
pci_set_power_state(pdev, PCI_D3hot);
}
}
static int i40e_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
struct i40e_hw *hw = &pf->hw;
int retval = 0;
set_bit(__I40E_SUSPENDED, pf->state);
set_bit(__I40E_DOWN, pf->state);
if (pf->wol_en && (pf->flags & I40E_FLAG_WOL_MC_MAGIC_PKT_WAKE))
i40e_enable_mc_magic_wake(pf);
rtnl_lock();
i40e_prep_for_reset(pf, true);
rtnl_unlock();
wr32(hw, I40E_PFPM_APM, (pf->wol_en ? I40E_PFPM_APM_APME_MASK : 0));
wr32(hw, I40E_PFPM_WUFC, (pf->wol_en ? I40E_PFPM_WUFC_MAG_MASK : 0));
i40e_stop_misc_vector(pf);
retval = pci_save_state(pdev);
if (retval)
return retval;
pci_wake_from_d3(pdev, pf->wol_en);
pci_set_power_state(pdev, PCI_D3hot);
return retval;
}
static int i40e_resume(struct pci_dev *pdev)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
u32 err;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
pci_save_state(pdev);
err = pci_enable_device_mem(pdev);
if (err) {
dev_err(&pdev->dev, "Cannot enable PCI device from suspend\n");
return err;
}
pci_set_master(pdev);
pci_wake_from_d3(pdev, false);
if (test_and_clear_bit(__I40E_SUSPENDED, pf->state)) {
clear_bit(__I40E_DOWN, pf->state);
rtnl_lock();
i40e_reset_and_rebuild(pf, false, true);
rtnl_unlock();
}
return 0;
}
static int __init i40e_init_module(void)
{
pr_info("%s: %s - version %s\n", i40e_driver_name,
i40e_driver_string, i40e_driver_version_str);
pr_info("%s: %s\n", i40e_driver_name, i40e_copyright);
i40e_wq = alloc_workqueue("%s", WQ_UNBOUND | WQ_MEM_RECLAIM, 1,
i40e_driver_name);
if (!i40e_wq) {
pr_err("%s: Failed to create workqueue\n", i40e_driver_name);
return -ENOMEM;
}
i40e_dbg_init();
return pci_register_driver(&i40e_driver);
}
static void __exit i40e_exit_module(void)
{
pci_unregister_driver(&i40e_driver);
destroy_workqueue(i40e_wq);
i40e_dbg_exit();
}
