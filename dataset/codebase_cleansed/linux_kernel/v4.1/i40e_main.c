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
} else {
i += j;
}
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
static void i40e_service_event_schedule(struct i40e_pf *pf)
{
if (!test_bit(__I40E_DOWN, &pf->state) &&
!test_bit(__I40E_RESET_RECOVERY_PENDING, &pf->state) &&
!test_and_set_bit(__I40E_SERVICE_SCHED, &pf->state))
schedule_work(&pf->service_task);
}
static inline void i40e_release_rx_desc(struct i40e_ring *rx_ring, u32 val)
{
rx_ring->next_to_use = val;
wmb();
writel(val, rx_ring->tail);
}
struct rtnl_link_stats64 *i40e_get_vsi_stats_struct(struct i40e_vsi *vsi)
{
return &vsi->net_stats;
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
memset(&vsi->rx_rings[i]->stats, 0 ,
sizeof(vsi->rx_rings[i]->stats));
memset(&vsi->rx_rings[i]->rx_stats, 0 ,
sizeof(vsi->rx_rings[i]->rx_stats));
memset(&vsi->tx_rings[i]->stats, 0 ,
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
*stat = (new_data + ((u64)1 << 48)) - *offset;
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
*stat = (u32)((new_data + ((u64)1 << 32)) - *offset);
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
int idx = 0;
idx = veb->stats_idx;
es = &veb->stats;
oes = &veb->stats_offsets;
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
veb->stat_offsets_loaded = true;
}
static void i40e_update_fcoe_stats(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
struct i40e_fcoe_stats *ofs;
struct i40e_fcoe_stats *fs;
int idx;
if (vsi->type != I40E_VSI_FCOE)
return;
idx = (pf->pf_seid - I40E_BASE_PF_SEID) + I40E_FCOE_PF_STAT_OFFSET;
fs = &vsi->fcoe_stats;
ofs = &vsi->fcoe_stats_offsets;
i40e_stat_update32(hw, I40E_GL_FCOEPRC(idx),
vsi->fcoe_stat_offsets_loaded,
&ofs->rx_fcoe_packets, &fs->rx_fcoe_packets);
i40e_stat_update48(hw, I40E_GL_FCOEDWRCH(idx), I40E_GL_FCOEDWRCL(idx),
vsi->fcoe_stat_offsets_loaded,
&ofs->rx_fcoe_dwords, &fs->rx_fcoe_dwords);
i40e_stat_update32(hw, I40E_GL_FCOERPDC(idx),
vsi->fcoe_stat_offsets_loaded,
&ofs->rx_fcoe_dropped, &fs->rx_fcoe_dropped);
i40e_stat_update32(hw, I40E_GL_FCOEPTC(idx),
vsi->fcoe_stat_offsets_loaded,
&ofs->tx_fcoe_packets, &fs->tx_fcoe_packets);
i40e_stat_update48(hw, I40E_GL_FCOEDWTCH(idx), I40E_GL_FCOEDWTCL(idx),
vsi->fcoe_stat_offsets_loaded,
&ofs->tx_fcoe_dwords, &fs->tx_fcoe_dwords);
i40e_stat_update32(hw, I40E_GL_FCOECRC(idx),
vsi->fcoe_stat_offsets_loaded,
&ofs->fcoe_bad_fccrc, &fs->fcoe_bad_fccrc);
i40e_stat_update32(hw, I40E_GL_FCOELAST(idx),
vsi->fcoe_stat_offsets_loaded,
&ofs->fcoe_last_error, &fs->fcoe_last_error);
i40e_stat_update32(hw, I40E_GL_FCOEDDPC(idx),
vsi->fcoe_stat_offsets_loaded,
&ofs->fcoe_ddp_count, &fs->fcoe_ddp_count);
vsi->fcoe_stat_offsets_loaded = true;
}
static void i40e_update_link_xoff_rx(struct i40e_pf *pf)
{
struct i40e_hw_port_stats *osd = &pf->stats_offsets;
struct i40e_hw_port_stats *nsd = &pf->stats;
struct i40e_hw *hw = &pf->hw;
u64 xoff = 0;
u16 i, v;
if ((hw->fc.current_mode != I40E_FC_FULL) &&
(hw->fc.current_mode != I40E_FC_RX_PAUSE))
return;
xoff = nsd->link_xoff_rx;
i40e_stat_update32(hw, I40E_GLPRT_LXOFFRXC(hw->port),
pf->stat_offsets_loaded,
&osd->link_xoff_rx, &nsd->link_xoff_rx);
if (!(nsd->link_xoff_rx - xoff))
return;
for (v = 0; v < pf->num_alloc_vsi; v++) {
struct i40e_vsi *vsi = pf->vsi[v];
if (!vsi || !vsi->tx_rings[0])
continue;
for (i = 0; i < vsi->num_queue_pairs; i++) {
struct i40e_ring *ring = vsi->tx_rings[i];
clear_bit(__I40E_HANG_CHECK_ARMED, &ring->state);
}
}
}
static void i40e_update_prio_xoff_rx(struct i40e_pf *pf)
{
struct i40e_hw_port_stats *osd = &pf->stats_offsets;
struct i40e_hw_port_stats *nsd = &pf->stats;
bool xoff[I40E_MAX_TRAFFIC_CLASS] = {false};
struct i40e_dcbx_config *dcb_cfg;
struct i40e_hw *hw = &pf->hw;
u16 i, v;
u8 tc;
dcb_cfg = &hw->local_dcbx_config;
if (!(pf->flags & I40E_FLAG_DCB_ENABLED) ||
!(dcb_cfg->pfc.pfcenable)) {
i40e_update_link_xoff_rx(pf);
return;
}
for (i = 0; i < I40E_MAX_USER_PRIORITY; i++) {
u64 prio_xoff = nsd->priority_xoff_rx[i];
i40e_stat_update32(hw, I40E_GLPRT_PXOFFRXC(hw->port, i),
pf->stat_offsets_loaded,
&osd->priority_xoff_rx[i],
&nsd->priority_xoff_rx[i]);
if (!(nsd->priority_xoff_rx[i] - prio_xoff))
continue;
tc = dcb_cfg->etscfg.prioritytable[i];
xoff[tc] = true;
}
for (v = 0; v < pf->num_alloc_vsi; v++) {
struct i40e_vsi *vsi = pf->vsi[v];
if (!vsi || !vsi->tx_rings[0])
continue;
for (i = 0; i < vsi->num_queue_pairs; i++) {
struct i40e_ring *ring = vsi->tx_rings[i];
tc = ring->dcb_tc;
if (xoff[tc])
clear_bit(__I40E_HANG_CHECK_ARMED,
&ring->state);
}
}
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
u64 rx_p, rx_b;
u64 tx_p, tx_b;
u16 q;
if (test_bit(__I40E_DOWN, &vsi->state) ||
test_bit(__I40E_CONFIG_BUSY, &pf->state))
return;
ns = i40e_get_vsi_stats_struct(vsi);
ons = &vsi->net_stats_offsets;
es = &vsi->eth_stats;
oes = &vsi->eth_stats_offsets;
rx_b = rx_p = 0;
tx_b = tx_p = 0;
tx_restart = tx_busy = 0;
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
i40e_update_prio_xoff_rx(pf);
i40e_stat_update32(hw, I40E_GLPRT_LXOFFTXC(hw->port),
pf->stat_offsets_loaded,
&osd->link_xoff_tx, &nsd->link_xoff_tx);
for (i = 0; i < 8; i++) {
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
i40e_stat_update32(hw, I40E_GLQF_PCNT(pf->fd_atr_cnt_idx),
pf->stat_offsets_loaded,
&osd->fd_atr_match, &nsd->fd_atr_match);
i40e_stat_update32(hw, I40E_GLQF_PCNT(pf->fd_sb_cnt_idx),
pf->stat_offsets_loaded,
&osd->fd_sb_match, &nsd->fd_sb_match);
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
pf->stat_offsets_loaded = true;
}
void i40e_update_stats(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
if (vsi == pf->vsi[pf->lan_vsi])
i40e_update_pf_stats(pf);
i40e_update_vsi_stats(vsi);
#ifdef I40E_FCOE
i40e_update_fcoe_stats(vsi);
#endif
}
static struct i40e_mac_filter *i40e_find_filter(struct i40e_vsi *vsi,
u8 *macaddr, s16 vlan,
bool is_vf, bool is_netdev)
{
struct i40e_mac_filter *f;
if (!vsi || !macaddr)
return NULL;
list_for_each_entry(f, &vsi->mac_filter_list, list) {
if ((ether_addr_equal(macaddr, f->macaddr)) &&
(vlan == f->vlan) &&
(!is_vf || f->is_vf) &&
(!is_netdev || f->is_netdev))
return f;
}
return NULL;
}
struct i40e_mac_filter *i40e_find_mac(struct i40e_vsi *vsi, u8 *macaddr,
bool is_vf, bool is_netdev)
{
struct i40e_mac_filter *f;
if (!vsi || !macaddr)
return NULL;
list_for_each_entry(f, &vsi->mac_filter_list, list) {
if ((ether_addr_equal(macaddr, f->macaddr)) &&
(!is_vf || f->is_vf) &&
(!is_netdev || f->is_netdev))
return f;
}
return NULL;
}
bool i40e_is_vsi_in_vlan(struct i40e_vsi *vsi)
{
struct i40e_mac_filter *f;
list_for_each_entry(f, &vsi->mac_filter_list, list) {
if (f->vlan >= 0)
return true;
}
return false;
}
struct i40e_mac_filter *i40e_put_mac_in_vlan(struct i40e_vsi *vsi, u8 *macaddr,
bool is_vf, bool is_netdev)
{
struct i40e_mac_filter *f;
list_for_each_entry(f, &vsi->mac_filter_list, list) {
if (!i40e_find_filter(vsi, macaddr, f->vlan,
is_vf, is_netdev)) {
if (!i40e_add_filter(vsi, macaddr, f->vlan,
is_vf, is_netdev))
return NULL;
}
}
return list_first_entry_or_null(&vsi->mac_filter_list,
struct i40e_mac_filter, list);
}
static int i40e_rm_default_mac_filter(struct i40e_vsi *vsi, u8 *macaddr)
{
struct i40e_aqc_remove_macvlan_element_data element;
struct i40e_pf *pf = vsi->back;
i40e_status aq_ret;
if (vsi->type != I40E_VSI_MAIN)
return -EINVAL;
memset(&element, 0, sizeof(element));
ether_addr_copy(element.mac_addr, macaddr);
element.vlan_tag = 0;
element.flags = I40E_AQC_MACVLAN_DEL_PERFECT_MATCH |
I40E_AQC_MACVLAN_DEL_IGNORE_VLAN;
aq_ret = i40e_aq_remove_macvlan(&pf->hw, vsi->seid, &element, 1, NULL);
if (aq_ret)
return -ENOENT;
return 0;
}
struct i40e_mac_filter *i40e_add_filter(struct i40e_vsi *vsi,
u8 *macaddr, s16 vlan,
bool is_vf, bool is_netdev)
{
struct i40e_mac_filter *f;
if (!vsi || !macaddr)
return NULL;
f = i40e_find_filter(vsi, macaddr, vlan, is_vf, is_netdev);
if (!f) {
f = kzalloc(sizeof(*f), GFP_ATOMIC);
if (!f)
goto add_filter_out;
ether_addr_copy(f->macaddr, macaddr);
f->vlan = vlan;
f->changed = true;
INIT_LIST_HEAD(&f->list);
list_add(&f->list, &vsi->mac_filter_list);
}
if (is_vf) {
if (!f->is_vf) {
f->is_vf = true;
f->counter++;
}
} else if (is_netdev) {
if (!f->is_netdev) {
f->is_netdev = true;
f->counter++;
}
} else {
f->counter++;
}
if (f->changed) {
vsi->flags |= I40E_VSI_FLAG_FILTER_CHANGED;
vsi->back->flags |= I40E_FLAG_FILTER_SYNC;
}
add_filter_out:
return f;
}
void i40e_del_filter(struct i40e_vsi *vsi,
u8 *macaddr, s16 vlan,
bool is_vf, bool is_netdev)
{
struct i40e_mac_filter *f;
if (!vsi || !macaddr)
return;
f = i40e_find_filter(vsi, macaddr, vlan, is_vf, is_netdev);
if (!f || f->counter == 0)
return;
if (is_vf) {
if (f->is_vf) {
f->is_vf = false;
f->counter--;
}
} else if (is_netdev) {
if (f->is_netdev) {
f->is_netdev = false;
f->counter--;
}
} else {
int min_f = 0;
min_f += (f->is_vf ? 1 : 0);
min_f += (f->is_netdev ? 1 : 0);
if (f->counter > min_f)
f->counter--;
}
if (f->counter == 0) {
f->changed = true;
vsi->flags |= I40E_VSI_FLAG_FILTER_CHANGED;
vsi->back->flags |= I40E_FLAG_FILTER_SYNC;
}
}
int i40e_sync_vsi_filters(struct i40e_vsi *vsi)
{
struct i40e_mac_filter *f, *ftmp;
bool promisc_forced_on = false;
bool add_happened = false;
int filter_list_len = 0;
u32 changed_flags = 0;
i40e_status aq_ret = 0;
struct i40e_pf *pf;
int num_add = 0;
int num_del = 0;
u16 cmd_flags;
struct i40e_aqc_add_macvlan_element_data *add_list;
struct i40e_aqc_remove_macvlan_element_data *del_list;
while (test_and_set_bit(__I40E_CONFIG_BUSY, &vsi->state))
usleep_range(1000, 2000);
pf = vsi->back;
if (vsi->netdev) {
changed_flags = vsi->current_netdev_flags ^ vsi->netdev->flags;
vsi->current_netdev_flags = vsi->netdev->flags;
}
if (vsi->flags & I40E_VSI_FLAG_FILTER_CHANGED) {
vsi->flags &= ~I40E_VSI_FLAG_FILTER_CHANGED;
filter_list_len = pf->hw.aq.asq_buf_size /
sizeof(struct i40e_aqc_remove_macvlan_element_data);
del_list = kcalloc(filter_list_len,
sizeof(struct i40e_aqc_remove_macvlan_element_data),
GFP_KERNEL);
if (!del_list)
return -ENOMEM;
list_for_each_entry_safe(f, ftmp, &vsi->mac_filter_list, list) {
if (!f->changed)
continue;
if (f->counter != 0)
continue;
f->changed = false;
cmd_flags = 0;
ether_addr_copy(del_list[num_del].mac_addr, f->macaddr);
del_list[num_del].vlan_tag =
cpu_to_le16((u16)(f->vlan ==
I40E_VLAN_ANY ? 0 : f->vlan));
cmd_flags |= I40E_AQC_MACVLAN_DEL_PERFECT_MATCH;
del_list[num_del].flags = cmd_flags;
num_del++;
list_del(&f->list);
kfree(f);
if (num_del == filter_list_len) {
aq_ret = i40e_aq_remove_macvlan(&pf->hw,
vsi->seid, del_list, num_del,
NULL);
num_del = 0;
memset(del_list, 0, sizeof(*del_list));
if (aq_ret &&
pf->hw.aq.asq_last_status !=
I40E_AQ_RC_ENOENT)
dev_info(&pf->pdev->dev,
"ignoring delete macvlan error, err %d, aq_err %d while flushing a full buffer\n",
aq_ret,
pf->hw.aq.asq_last_status);
}
}
if (num_del) {
aq_ret = i40e_aq_remove_macvlan(&pf->hw, vsi->seid,
del_list, num_del, NULL);
num_del = 0;
if (aq_ret &&
pf->hw.aq.asq_last_status != I40E_AQ_RC_ENOENT)
dev_info(&pf->pdev->dev,
"ignoring delete macvlan error, err %d, aq_err %d\n",
aq_ret, pf->hw.aq.asq_last_status);
}
kfree(del_list);
del_list = NULL;
filter_list_len = pf->hw.aq.asq_buf_size /
sizeof(struct i40e_aqc_add_macvlan_element_data),
add_list = kcalloc(filter_list_len,
sizeof(struct i40e_aqc_add_macvlan_element_data),
GFP_KERNEL);
if (!add_list)
return -ENOMEM;
list_for_each_entry_safe(f, ftmp, &vsi->mac_filter_list, list) {
if (!f->changed)
continue;
if (f->counter == 0)
continue;
f->changed = false;
add_happened = true;
cmd_flags = 0;
ether_addr_copy(add_list[num_add].mac_addr, f->macaddr);
add_list[num_add].vlan_tag =
cpu_to_le16(
(u16)(f->vlan == I40E_VLAN_ANY ? 0 : f->vlan));
add_list[num_add].queue_number = 0;
cmd_flags |= I40E_AQC_MACVLAN_ADD_PERFECT_MATCH;
add_list[num_add].flags = cpu_to_le16(cmd_flags);
num_add++;
if (num_add == filter_list_len) {
aq_ret = i40e_aq_add_macvlan(&pf->hw, vsi->seid,
add_list, num_add,
NULL);
num_add = 0;
if (aq_ret)
break;
memset(add_list, 0, sizeof(*add_list));
}
}
if (num_add) {
aq_ret = i40e_aq_add_macvlan(&pf->hw, vsi->seid,
add_list, num_add, NULL);
num_add = 0;
}
kfree(add_list);
add_list = NULL;
if (add_happened && aq_ret &&
pf->hw.aq.asq_last_status != I40E_AQ_RC_EINVAL) {
dev_info(&pf->pdev->dev,
"add filter failed, err %d, aq_err %d\n",
aq_ret, pf->hw.aq.asq_last_status);
if ((pf->hw.aq.asq_last_status == I40E_AQ_RC_ENOSPC) &&
!test_bit(__I40E_FILTER_OVERFLOW_PROMISC,
&vsi->state)) {
promisc_forced_on = true;
set_bit(__I40E_FILTER_OVERFLOW_PROMISC,
&vsi->state);
dev_info(&pf->pdev->dev, "promiscuous mode forced on\n");
}
}
}
if (changed_flags & IFF_ALLMULTI) {
bool cur_multipromisc;
cur_multipromisc = !!(vsi->current_netdev_flags & IFF_ALLMULTI);
aq_ret = i40e_aq_set_vsi_multicast_promiscuous(&vsi->back->hw,
vsi->seid,
cur_multipromisc,
NULL);
if (aq_ret)
dev_info(&pf->pdev->dev,
"set multi promisc failed, err %d, aq_err %d\n",
aq_ret, pf->hw.aq.asq_last_status);
}
if ((changed_flags & IFF_PROMISC) || promisc_forced_on) {
bool cur_promisc;
cur_promisc = (!!(vsi->current_netdev_flags & IFF_PROMISC) ||
test_bit(__I40E_FILTER_OVERFLOW_PROMISC,
&vsi->state));
aq_ret = i40e_aq_set_vsi_unicast_promiscuous(&vsi->back->hw,
vsi->seid,
cur_promisc, NULL);
if (aq_ret)
dev_info(&pf->pdev->dev,
"set uni promisc failed, err %d, aq_err %d\n",
aq_ret, pf->hw.aq.asq_last_status);
aq_ret = i40e_aq_set_vsi_broadcast(&vsi->back->hw,
vsi->seid,
cur_promisc, NULL);
if (aq_ret)
dev_info(&pf->pdev->dev,
"set brdcast promisc failed, err %d, aq_err %d\n",
aq_ret, pf->hw.aq.asq_last_status);
}
clear_bit(__I40E_CONFIG_BUSY, &vsi->state);
return 0;
}
static void i40e_sync_filters_subtask(struct i40e_pf *pf)
{
int v;
if (!pf || !(pf->flags & I40E_FLAG_FILTER_SYNC))
return;
pf->flags &= ~I40E_FLAG_FILTER_SYNC;
for (v = 0; v < pf->num_alloc_vsi; v++) {
if (pf->vsi[v] &&
(pf->vsi[v]->flags & I40E_VSI_FLAG_FILTER_CHANGED))
i40e_sync_vsi_filters(pf->vsi[v]);
}
}
static int i40e_change_mtu(struct net_device *netdev, int new_mtu)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN;
struct i40e_vsi *vsi = np->vsi;
if ((new_mtu < 68) || (max_frame > I40E_MAX_RXBUFFER))
return -EINVAL;
netdev_info(netdev, "changing MTU from %d to %d\n",
netdev->mtu, new_mtu);
netdev->mtu = new_mtu;
if (netif_running(netdev))
i40e_vsi_reinit_locked(vsi);
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
"%s: update vsi failed, aq_err=%d\n",
__func__, vsi->back->hw.aq.asq_last_status);
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
"%s: update vsi failed, aq_err=%d\n",
__func__, vsi->back->hw.aq.asq_last_status);
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
int i40e_vsi_add_vlan(struct i40e_vsi *vsi, s16 vid)
{
struct i40e_mac_filter *f, *add_f;
bool is_netdev, is_vf;
is_vf = (vsi->type == I40E_VSI_SRIOV);
is_netdev = !!(vsi->netdev);
if (is_netdev) {
add_f = i40e_add_filter(vsi, vsi->netdev->dev_addr, vid,
is_vf, is_netdev);
if (!add_f) {
dev_info(&vsi->back->pdev->dev,
"Could not add vlan filter %d for %pM\n",
vid, vsi->netdev->dev_addr);
return -ENOMEM;
}
}
list_for_each_entry(f, &vsi->mac_filter_list, list) {
add_f = i40e_add_filter(vsi, f->macaddr, vid, is_vf, is_netdev);
if (!add_f) {
dev_info(&vsi->back->pdev->dev,
"Could not add vlan filter %d for %pM\n",
vid, f->macaddr);
return -ENOMEM;
}
}
if (vid > 0) {
if (is_netdev && i40e_find_filter(vsi, vsi->netdev->dev_addr,
I40E_VLAN_ANY,
is_vf, is_netdev)) {
i40e_del_filter(vsi, vsi->netdev->dev_addr,
I40E_VLAN_ANY, is_vf, is_netdev);
add_f = i40e_add_filter(vsi, vsi->netdev->dev_addr, 0,
is_vf, is_netdev);
if (!add_f) {
dev_info(&vsi->back->pdev->dev,
"Could not add filter 0 for %pM\n",
vsi->netdev->dev_addr);
return -ENOMEM;
}
}
}
if (vid > 0 && !vsi->info.pvid) {
list_for_each_entry(f, &vsi->mac_filter_list, list) {
if (i40e_find_filter(vsi, f->macaddr, I40E_VLAN_ANY,
is_vf, is_netdev)) {
i40e_del_filter(vsi, f->macaddr, I40E_VLAN_ANY,
is_vf, is_netdev);
add_f = i40e_add_filter(vsi, f->macaddr,
0, is_vf, is_netdev);
if (!add_f) {
dev_info(&vsi->back->pdev->dev,
"Could not add filter 0 for %pM\n",
f->macaddr);
return -ENOMEM;
}
}
}
}
if (test_bit(__I40E_DOWN, &vsi->back->state) ||
test_bit(__I40E_RESET_RECOVERY_PENDING, &vsi->back->state))
return 0;
return i40e_sync_vsi_filters(vsi);
}
int i40e_vsi_kill_vlan(struct i40e_vsi *vsi, s16 vid)
{
struct net_device *netdev = vsi->netdev;
struct i40e_mac_filter *f, *add_f;
bool is_vf, is_netdev;
int filter_count = 0;
is_vf = (vsi->type == I40E_VSI_SRIOV);
is_netdev = !!(netdev);
if (is_netdev)
i40e_del_filter(vsi, netdev->dev_addr, vid, is_vf, is_netdev);
list_for_each_entry(f, &vsi->mac_filter_list, list)
i40e_del_filter(vsi, f->macaddr, vid, is_vf, is_netdev);
list_for_each_entry(f, &vsi->mac_filter_list, list) {
if (is_netdev) {
if (f->vlan &&
ether_addr_equal(netdev->dev_addr, f->macaddr))
filter_count++;
}
if (f->vlan)
filter_count++;
}
if (!filter_count && is_netdev) {
i40e_del_filter(vsi, netdev->dev_addr, 0, is_vf, is_netdev);
f = i40e_add_filter(vsi, netdev->dev_addr, I40E_VLAN_ANY,
is_vf, is_netdev);
if (!f) {
dev_info(&vsi->back->pdev->dev,
"Could not add filter %d for %pM\n",
I40E_VLAN_ANY, netdev->dev_addr);
return -ENOMEM;
}
}
if (!filter_count) {
list_for_each_entry(f, &vsi->mac_filter_list, list) {
i40e_del_filter(vsi, f->macaddr, 0, is_vf, is_netdev);
add_f = i40e_add_filter(vsi, f->macaddr, I40E_VLAN_ANY,
is_vf, is_netdev);
if (!add_f) {
dev_info(&vsi->back->pdev->dev,
"Could not add filter %d for %pM\n",
I40E_VLAN_ANY, f->macaddr);
return -ENOMEM;
}
}
}
if (test_bit(__I40E_DOWN, &vsi->back->state) ||
test_bit(__I40E_RESET_RECOVERY_PENDING, &vsi->back->state))
return 0;
return i40e_sync_vsi_filters(vsi);
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
i40e_status aq_ret;
vsi->info.valid_sections = cpu_to_le16(I40E_AQ_VSI_PROP_VLAN_VALID);
vsi->info.pvid = cpu_to_le16(vid);
vsi->info.port_vlan_flags = I40E_AQ_VSI_PVLAN_MODE_TAGGED |
I40E_AQ_VSI_PVLAN_INSERT_PVID |
I40E_AQ_VSI_PVLAN_EMOD_STR;
ctxt.seid = vsi->seid;
ctxt.info = vsi->info;
aq_ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (aq_ret) {
dev_info(&vsi->back->pdev->dev,
"%s: update vsi failed, aq_err=%d\n",
__func__, vsi->back->hw.aq.asq_last_status);
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
#ifdef I40E_FCOE
i40e_fcoe_setup_ddp_resources(vsi);
#endif
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
#ifdef I40E_FCOE
i40e_fcoe_free_ddp_resources(vsi);
#endif
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
#ifdef I40E_FCOE
tx_ctx.fc_ena = (vsi->type == I40E_VSI_FCOE);
#endif
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
clear_bit(__I40E_HANG_CHECK_ARMED, &ring->state);
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
ring->rx_hdr_len = vsi->rx_hdr_len;
rx_ctx.dbuff = ring->rx_buf_len >> I40E_RXQ_CTX_DBUFF_SHIFT;
rx_ctx.hbuff = ring->rx_hdr_len >> I40E_RXQ_CTX_HBUFF_SHIFT;
rx_ctx.base = (ring->dma / 128);
rx_ctx.qlen = ring->count;
if (vsi->back->flags & I40E_FLAG_16BYTE_RX_DESC_ENABLED) {
set_ring_16byte_desc_enabled(ring);
rx_ctx.dsize = 0;
} else {
rx_ctx.dsize = 1;
}
rx_ctx.dtype = vsi->dtype;
if (vsi->dtype) {
set_ring_ps_enabled(ring);
rx_ctx.hsplit_0 = I40E_RX_SPLIT_L2 |
I40E_RX_SPLIT_IP |
I40E_RX_SPLIT_TCP_UDP |
I40E_RX_SPLIT_SCTP;
} else {
rx_ctx.hsplit_0 = 0;
}
rx_ctx.rxmax = min_t(u16, vsi->max_frame,
(chain_len * ring->rx_buf_len));
if (hw->revision_id == 0)
rx_ctx.lrxqthresh = 0;
else
rx_ctx.lrxqthresh = 2;
rx_ctx.crcstrip = 1;
rx_ctx.l2tsel = 1;
rx_ctx.showiv = 1;
#ifdef I40E_FCOE
rx_ctx.fc_ena = (vsi->type == I40E_VSI_FCOE);
#endif
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
ring->tail = hw->hw_addr + I40E_QRX_TAIL(pf_q);
writel(0, ring->tail);
if (ring_is_ps_enabled(ring)) {
i40e_alloc_rx_headers(ring);
i40e_alloc_rx_buffers_ps(ring, I40E_DESC_UNUSED(ring));
} else {
i40e_alloc_rx_buffers_1buf(ring, I40E_DESC_UNUSED(ring));
}
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
if (vsi->netdev && (vsi->netdev->mtu > ETH_DATA_LEN))
vsi->max_frame = vsi->netdev->mtu + ETH_HLEN
+ ETH_FCS_LEN + VLAN_HLEN;
else
vsi->max_frame = I40E_RXBUFFER_2048;
switch (vsi->back->flags & (I40E_FLAG_RX_1BUF_ENABLED |
I40E_FLAG_RX_PS_ENABLED)) {
case I40E_FLAG_RX_1BUF_ENABLED:
vsi->rx_hdr_len = 0;
vsi->rx_buf_len = vsi->max_frame;
vsi->dtype = I40E_RX_DTYPE_NO_SPLIT;
break;
case I40E_FLAG_RX_PS_ENABLED:
vsi->rx_hdr_len = I40E_RX_HDR_SIZE;
vsi->rx_buf_len = I40E_RXBUFFER_2048;
vsi->dtype = I40E_RX_DTYPE_HEADER_SPLIT;
break;
default:
vsi->rx_hdr_len = I40E_RX_HDR_SIZE;
vsi->rx_buf_len = I40E_RXBUFFER_2048;
vsi->dtype = I40E_RX_DTYPE_SPLIT_ALWAYS;
break;
}
#ifdef I40E_FCOE
if ((vsi->type == I40E_VSI_FCOE) &&
(vsi->back->flags & I40E_FLAG_FCOE_ENABLED)) {
vsi->rx_hdr_len = 0;
vsi->rx_buf_len = I40E_RXBUFFER_3072;
vsi->max_frame = I40E_RXBUFFER_3072;
vsi->dtype = I40E_RX_DTYPE_NO_SPLIT;
}
#endif
vsi->rx_hdr_len = ALIGN(vsi->rx_hdr_len,
(1 << I40E_RXQ_CTX_HBUFF_SHIFT));
vsi->rx_buf_len = ALIGN(vsi->rx_buf_len,
(1 << I40E_RXQ_CTX_DBUFF_SHIFT));
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
if (!(vsi->tc_config.enabled_tc & (1 << n)))
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
if (vsi->netdev)
i40e_set_rx_mode(vsi->netdev);
}
static void i40e_fdir_filter_restore(struct i40e_vsi *vsi)
{
struct i40e_fdir_filter *filter;
struct i40e_pf *pf = vsi->back;
struct hlist_node *node;
if (!(pf->flags & I40E_FLAG_FD_SB_ENABLED))
return;
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
struct i40e_q_vector *q_vector;
struct i40e_hw *hw = &pf->hw;
u16 vector;
int i, q;
u32 val;
u32 qp;
qp = vsi->base_queue;
vector = vsi->base_vector;
for (i = 0; i < vsi->num_q_vectors; i++, vector++) {
q_vector = vsi->q_vectors[i];
q_vector->rx.itr = ITR_TO_REG(vsi->rx_itr_setting);
q_vector->rx.latency_range = I40E_LOW_LATENCY;
wr32(hw, I40E_PFINT_ITRN(I40E_RX_ITR, vector - 1),
q_vector->rx.itr);
q_vector->tx.itr = ITR_TO_REG(vsi->tx_itr_setting);
q_vector->tx.latency_range = I40E_LOW_LATENCY;
wr32(hw, I40E_PFINT_ITRN(I40E_TX_ITR, vector - 1),
q_vector->tx.itr);
wr32(hw, I40E_PFINT_LNKLSTN(vector - 1), qp);
for (q = 0; q < q_vector->num_ringpairs; q++) {
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
q_vector->rx.itr = ITR_TO_REG(vsi->rx_itr_setting);
q_vector->rx.latency_range = I40E_LOW_LATENCY;
wr32(hw, I40E_PFINT_ITR0(I40E_RX_ITR), q_vector->rx.itr);
q_vector->tx.itr = ITR_TO_REG(vsi->tx_itr_setting);
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
void i40e_irq_dynamic_enable_icr0(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
u32 val;
val = I40E_PFINT_DYN_CTL0_INTENA_MASK |
I40E_PFINT_DYN_CTL0_CLEARPBA_MASK |
(I40E_ITR_NONE << I40E_PFINT_DYN_CTL0_ITR_INDX_SHIFT);
wr32(hw, I40E_PFINT_DYN_CTL0, val);
i40e_flush(hw);
}
void i40e_irq_dynamic_enable(struct i40e_vsi *vsi, int vector)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
u32 val;
val = I40E_PFINT_DYN_CTLN_INTENA_MASK |
I40E_PFINT_DYN_CTLN_CLEARPBA_MASK |
(I40E_ITR_NONE << I40E_PFINT_DYN_CTLN_ITR_INDX_SHIFT);
wr32(hw, I40E_PFINT_DYN_CTLN(vector - 1), val);
}
void i40e_irq_dynamic_disable(struct i40e_vsi *vsi, int vector)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
u32 val;
val = I40E_ITR_NONE << I40E_PFINT_DYN_CTLN_ITR_INDX_SHIFT;
wr32(hw, I40E_PFINT_DYN_CTLN(vector - 1), val);
i40e_flush(hw);
}
static irqreturn_t i40e_msix_clean_rings(int irq, void *data)
{
struct i40e_q_vector *q_vector = data;
if (!q_vector->tx.ring && !q_vector->rx.ring)
return IRQ_HANDLED;
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static int i40e_vsi_request_irq_msix(struct i40e_vsi *vsi, char *basename)
{
int q_vectors = vsi->num_q_vectors;
struct i40e_pf *pf = vsi->back;
int base = vsi->base_vector;
int rx_int_idx = 0;
int tx_int_idx = 0;
int vector, err;
for (vector = 0; vector < q_vectors; vector++) {
struct i40e_q_vector *q_vector = vsi->q_vectors[vector];
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
err = request_irq(pf->msix_entries[base + vector].vector,
vsi->irq_handler,
0,
q_vector->name,
q_vector);
if (err) {
dev_info(&pf->pdev->dev,
"%s: request_irq failed, error: %d\n",
__func__, err);
goto free_queue_irqs;
}
irq_set_affinity_hint(pf->msix_entries[base + vector].vector,
&q_vector->affinity_mask);
}
vsi->irqs_ready = true;
return 0;
free_queue_irqs:
while (vector) {
vector--;
irq_set_affinity_hint(pf->msix_entries[base + vector].vector,
NULL);
free_irq(pf->msix_entries[base + vector].vector,
&(vsi->q_vectors[vector]));
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
for (i = vsi->base_vector;
i < (vsi->num_q_vectors + vsi->base_vector); i++)
i40e_irq_dynamic_enable(vsi, i);
} else {
i40e_irq_dynamic_enable_icr0(pf);
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
if (icr0 & I40E_PFINT_ICR0_QUEUE_0_MASK) {
u32 qval = rd32(hw, I40E_QINT_RQCTL(0));
qval &= ~I40E_QINT_RQCTL_CAUSE_ENA_MASK;
wr32(hw, I40E_QINT_RQCTL(0), qval);
qval = rd32(hw, I40E_QINT_TQCTL(0));
qval &= ~I40E_QINT_TQCTL_CAUSE_ENA_MASK;
wr32(hw, I40E_QINT_TQCTL(0), qval);
if (!test_bit(__I40E_DOWN, &pf->state))
napi_schedule(&pf->vsi[pf->lan_vsi]->q_vectors[0]->napi);
}
if (icr0 & I40E_PFINT_ICR0_ADMINQ_MASK) {
ena_mask &= ~I40E_PFINT_ICR0_ENA_ADMINQ_MASK;
set_bit(__I40E_ADMINQ_EVENT_PENDING, &pf->state);
}
if (icr0 & I40E_PFINT_ICR0_MAL_DETECT_MASK) {
ena_mask &= ~I40E_PFINT_ICR0_ENA_MAL_DETECT_MASK;
set_bit(__I40E_MDD_EVENT_PENDING, &pf->state);
}
if (icr0 & I40E_PFINT_ICR0_VFLR_MASK) {
ena_mask &= ~I40E_PFINT_ICR0_ENA_VFLR_MASK;
set_bit(__I40E_VFLR_EVENT_PENDING, &pf->state);
}
if (icr0 & I40E_PFINT_ICR0_GRST_MASK) {
if (!test_bit(__I40E_RESET_RECOVERY_PENDING, &pf->state))
set_bit(__I40E_RESET_INTR_RECEIVED, &pf->state);
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
set_bit(__I40E_EMP_RESET_INTR_RECEIVED, &pf->state);
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
set_bit(__I40E_PF_RESET_REQUESTED, &pf->state);
i40e_service_event_schedule(pf);
}
ena_mask &= ~icr0_remaining;
}
ret = IRQ_HANDLED;
enable_intr:
wr32(hw, I40E_PFINT_ICR0_ENA, ena_mask);
if (!test_bit(__I40E_DOWN, &pf->state)) {
i40e_service_event_schedule(pf);
i40e_irq_dynamic_enable_icr0(pf);
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
if (vsi->back->flags & I40E_FLAG_MSIX_ENABLED) {
i40e_irq_dynamic_enable(vsi,
tx_ring->q_vector->v_idx + vsi->base_vector);
}
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
static void map_vector_to_qp(struct i40e_vsi *vsi, int v_idx, int qp_idx)
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
map_vector_to_qp(vsi, v_start, qp_idx);
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
static int i40e_vsi_control_tx(struct i40e_vsi *vsi, bool enable)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
int i, j, pf_q, ret = 0;
u32 tx_reg;
pf_q = vsi->base_queue;
for (i = 0; i < vsi->num_queue_pairs; i++, pf_q++) {
i40e_pre_tx_queue_cfg(&pf->hw, pf_q, enable);
if (!enable)
usleep_range(10, 20);
for (j = 0; j < 50; j++) {
tx_reg = rd32(hw, I40E_QTX_ENA(pf_q));
if (((tx_reg >> I40E_QTX_ENA_QENA_REQ_SHIFT) & 1) ==
((tx_reg >> I40E_QTX_ENA_QENA_STAT_SHIFT) & 1))
break;
usleep_range(1000, 2000);
}
if (enable == !!(tx_reg & I40E_QTX_ENA_QENA_STAT_MASK))
continue;
if (enable) {
wr32(hw, I40E_QTX_HEAD(pf_q), 0);
tx_reg |= I40E_QTX_ENA_QENA_REQ_MASK;
} else {
tx_reg &= ~I40E_QTX_ENA_QENA_REQ_MASK;
}
wr32(hw, I40E_QTX_ENA(pf_q), tx_reg);
if (!enable && test_bit(__I40E_PORT_TX_SUSPENDED, &pf->state))
continue;
ret = i40e_pf_txq_wait(pf, pf_q, enable);
if (ret) {
dev_info(&pf->pdev->dev,
"%s: VSI seid %d Tx ring %d %sable timeout\n",
__func__, vsi->seid, pf_q,
(enable ? "en" : "dis"));
break;
}
}
if (hw->revision_id == 0)
mdelay(50);
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
static int i40e_vsi_control_rx(struct i40e_vsi *vsi, bool enable)
{
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
int i, j, pf_q, ret = 0;
u32 rx_reg;
pf_q = vsi->base_queue;
for (i = 0; i < vsi->num_queue_pairs; i++, pf_q++) {
for (j = 0; j < 50; j++) {
rx_reg = rd32(hw, I40E_QRX_ENA(pf_q));
if (((rx_reg >> I40E_QRX_ENA_QENA_REQ_SHIFT) & 1) ==
((rx_reg >> I40E_QRX_ENA_QENA_STAT_SHIFT) & 1))
break;
usleep_range(1000, 2000);
}
if (enable == !!(rx_reg & I40E_QRX_ENA_QENA_STAT_MASK))
continue;
if (enable)
rx_reg |= I40E_QRX_ENA_QENA_REQ_MASK;
else
rx_reg &= ~I40E_QRX_ENA_QENA_REQ_MASK;
wr32(hw, I40E_QRX_ENA(pf_q), rx_reg);
ret = i40e_pf_rxq_wait(pf, pf_q, enable);
if (ret) {
dev_info(&pf->pdev->dev,
"%s: VSI seid %d Rx ring %d %sable timeout\n",
__func__, vsi->seid, pf_q,
(enable ? "en" : "dis"));
break;
}
}
return ret;
}
int i40e_vsi_control_rings(struct i40e_vsi *vsi, bool request)
{
int ret = 0;
if (request) {
ret = i40e_vsi_control_rx(vsi, request);
if (ret)
return ret;
ret = i40e_vsi_control_tx(vsi, request);
} else {
i40e_vsi_control_tx(vsi, request);
i40e_vsi_control_rx(vsi, request);
}
return ret;
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
u16 vector = i + base;
if (!vsi->q_vectors[i] ||
!vsi->q_vectors[i]->num_ringpairs)
continue;
irq_set_affinity_hint(pf->msix_entries[vector].vector,
NULL);
free_irq(pf->msix_entries[vector].vector,
vsi->q_vectors[i]);
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
if (pf->flags & I40E_FLAG_MSIX_ENABLED) {
synchronize_irq(pf->msix_entries[0].vector);
free_irq(pf->msix_entries[0].vector, pf);
}
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
for (q_idx = 0; q_idx < vsi->num_q_vectors; q_idx++)
napi_enable(&vsi->q_vectors[q_idx]->napi);
}
static void i40e_napi_disable_all(struct i40e_vsi *vsi)
{
int q_idx;
if (!vsi->netdev)
return;
for (q_idx = 0; q_idx < vsi->num_q_vectors; q_idx++)
napi_disable(&vsi->q_vectors[q_idx]->napi);
}
static void i40e_vsi_close(struct i40e_vsi *vsi)
{
if (!test_and_set_bit(__I40E_DOWN, &vsi->state))
i40e_down(vsi);
i40e_vsi_free_irq(vsi);
i40e_vsi_free_tx_resources(vsi);
i40e_vsi_free_rx_resources(vsi);
}
static void i40e_quiesce_vsi(struct i40e_vsi *vsi)
{
if (test_bit(__I40E_DOWN, &vsi->state))
return;
if ((test_bit(__I40E_PORT_TX_SUSPENDED, &vsi->back->state)) &&
vsi->type == I40E_VSI_FCOE) {
dev_dbg(&vsi->back->pdev->dev,
"%s: VSI seid %d skipping FCoE VSI disable\n",
__func__, vsi->seid);
return;
}
set_bit(__I40E_NEEDS_RESTART, &vsi->state);
if (vsi->netdev && netif_running(vsi->netdev)) {
vsi->netdev->netdev_ops->ndo_stop(vsi->netdev);
} else {
i40e_vsi_close(vsi);
}
}
static void i40e_unquiesce_vsi(struct i40e_vsi *vsi)
{
if (!test_bit(__I40E_NEEDS_RESTART, &vsi->state))
return;
clear_bit(__I40E_NEEDS_RESTART, &vsi->state);
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
static int i40e_vsi_wait_txq_disabled(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
int i, pf_q, ret;
pf_q = vsi->base_queue;
for (i = 0; i < vsi->num_queue_pairs; i++, pf_q++) {
ret = i40e_pf_txq_wait(pf, pf_q, false);
if (ret) {
dev_info(&pf->pdev->dev,
"%s: VSI seid %d Tx ring %d disable timeout\n",
__func__, vsi->seid, pf_q);
return ret;
}
}
return 0;
}
static int i40e_pf_wait_txq_disabled(struct i40e_pf *pf)
{
int v, ret = 0;
for (v = 0; v < pf->hw.func_caps.num_vsis; v++) {
if (pf->vsi[v] && pf->vsi[v]->type != I40E_VSI_FCOE) {
ret = i40e_vsi_wait_txq_disabled(pf->vsi[v]);
if (ret)
break;
}
}
return ret;
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
enabled_tc |= (1 << tc);
break;
}
}
return enabled_tc;
}
static u8 i40e_dcb_get_num_tc(struct i40e_dcbx_config *dcbcfg)
{
u8 num_tc = 0;
int i;
for (i = 0; i < I40E_MAX_USER_PRIORITY; i++) {
if (dcbcfg->etscfg.prioritytable[i] > num_tc)
num_tc = dcbcfg->etscfg.prioritytable[i];
}
return num_tc + 1;
}
static u8 i40e_dcb_get_enabled_tc(struct i40e_dcbx_config *dcbcfg)
{
u8 num_tc = i40e_dcb_get_num_tc(dcbcfg);
u8 enabled_tc = 1;
u8 i;
for (i = 0; i < num_tc; i++)
enabled_tc |= 1 << i;
return enabled_tc;
}
static u8 i40e_pf_get_num_tc(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
u8 i, enabled_tc;
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
enabled_tc = (enabled_tc ? enabled_tc : 0x1);
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (enabled_tc & (1 << i))
num_tc++;
}
return num_tc;
}
static u8 i40e_pf_get_default_tc(struct i40e_pf *pf)
{
u8 enabled_tc = pf->hw.func_caps.enabled_tcmap;
u8 i = 0;
if (!enabled_tc)
return 0x1;
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (enabled_tc & (1 << i))
break;
}
return 1 << i;
}
static u8 i40e_pf_get_tc_map(struct i40e_pf *pf)
{
if (!(pf->flags & I40E_FLAG_DCB_ENABLED))
return i40e_pf_get_default_tc(pf);
if (!(pf->flags & I40E_FLAG_MFP_ENABLED))
return i40e_dcb_get_enabled_tc(&pf->hw.local_dcbx_config);
if (pf->hw.func_caps.iscsi)
return i40e_get_iscsi_tc_map(pf);
else
return i40e_pf_get_default_tc(pf);
}
static int i40e_vsi_get_bw_info(struct i40e_vsi *vsi)
{
struct i40e_aqc_query_vsi_ets_sla_config_resp bw_ets_config = {0};
struct i40e_aqc_query_vsi_bw_config_resp bw_config = {0};
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
i40e_status aq_ret;
u32 tc_bw_max;
int i;
aq_ret = i40e_aq_query_vsi_bw_config(hw, vsi->seid, &bw_config, NULL);
if (aq_ret) {
dev_info(&pf->pdev->dev,
"couldn't get PF vsi bw config, err %d, aq_err %d\n",
aq_ret, pf->hw.aq.asq_last_status);
return -EINVAL;
}
aq_ret = i40e_aq_query_vsi_ets_sla_config(hw, vsi->seid, &bw_ets_config,
NULL);
if (aq_ret) {
dev_info(&pf->pdev->dev,
"couldn't get PF vsi ets bw config, err %d, aq_err %d\n",
aq_ret, pf->hw.aq.asq_last_status);
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
i40e_status aq_ret;
int i;
bw_data.tc_valid_bits = enabled_tc;
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++)
bw_data.tc_bw_credits[i] = bw_share[i];
aq_ret = i40e_aq_config_vsi_tc_bw(&vsi->back->hw, vsi->seid, &bw_data,
NULL);
if (aq_ret) {
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
if (vsi->tc_config.enabled_tc & (1 << i))
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
if (enabled_tc & (1 << i))
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
ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"update vsi failed, aq_err=%d\n",
vsi->back->hw.aq.asq_last_status);
goto out;
}
i40e_vsi_update_queue_map(vsi, &ctxt);
vsi->info.valid_sections = 0;
ret = i40e_vsi_get_bw_info(vsi);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"Failed updating vsi bw info, aq_err=%d\n",
vsi->back->hw.aq.asq_last_status);
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
if (enabled_tc & (1 << i))
bw_data.tc_bw_share_credits[i] = 1;
}
ret = i40e_aq_config_switch_comp_bw_config(&pf->hw, veb->seid,
&bw_data, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"veb bw config failed, aq_err=%d\n",
pf->hw.aq.asq_last_status);
goto out;
}
ret = i40e_veb_get_bw_info(veb);
if (ret) {
dev_info(&pf->pdev->dev,
"Failed getting veb bw config, aq_err=%d\n",
pf->hw.aq.asq_last_status);
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
tc_map = i40e_pf_get_default_tc(pf);
#ifdef I40E_FCOE
if (pf->vsi[v]->type == I40E_VSI_FCOE)
tc_map = i40e_get_fcoe_tc_map(pf);
#endif
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
"AQ command Resume Port Tx failed = %d\n",
pf->hw.aq.asq_last_status);
set_bit(__I40E_PF_RESET_REQUESTED, &pf->state);
i40e_service_event_schedule(pf);
}
return ret;
}
static int i40e_init_pf_dcb(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
int err = 0;
if (((pf->hw.aq.fw_maj_ver == 4) && (pf->hw.aq.fw_min_ver < 33)) ||
(pf->hw.aq.fw_maj_ver < 4))
goto out;
err = i40e_init_dcb(hw);
if (!err) {
if ((!hw->func_caps.dcb) ||
(hw->dcbx_status == I40E_DCBX_STATUS_DISABLED)) {
dev_info(&pf->pdev->dev,
"DCBX offload is not supported or is disabled for this PF.\n");
if (pf->flags & I40E_FLAG_MFP_ENABLED)
goto out;
} else {
pf->dcbx_cap = DCB_CAP_DCBX_LLD_MANAGED |
DCB_CAP_DCBX_VER_IEEE;
pf->flags |= I40E_FLAG_DCB_CAPABLE;
if (i40e_dcb_get_num_tc(&hw->local_dcbx_config) > 1)
pf->flags |= I40E_FLAG_DCB_ENABLED;
dev_dbg(&pf->pdev->dev,
"DCBX offload is supported for this PF.\n");
}
} else {
dev_info(&pf->pdev->dev,
"AQ Querying DCB configuration failed: aq_err %d\n",
pf->hw.aq.asq_last_status);
}
out:
return err;
}
static void i40e_print_link_message(struct i40e_vsi *vsi, bool isup)
{
char speed[SPEED_SIZE] = "Unknown";
char fc[FC_SIZE] = "RX/TX";
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
strlcpy(speed, "40 Gbps", SPEED_SIZE);
break;
case I40E_LINK_SPEED_20GB:
strncpy(speed, "20 Gbps", SPEED_SIZE);
break;
case I40E_LINK_SPEED_10GB:
strlcpy(speed, "10 Gbps", SPEED_SIZE);
break;
case I40E_LINK_SPEED_1GB:
strlcpy(speed, "1000 Mbps", SPEED_SIZE);
break;
case I40E_LINK_SPEED_100MB:
strncpy(speed, "100 Mbps", SPEED_SIZE);
break;
default:
break;
}
switch (vsi->back->hw.fc.current_mode) {
case I40E_FC_FULL:
strlcpy(fc, "RX/TX", FC_SIZE);
break;
case I40E_FC_TX_PAUSE:
strlcpy(fc, "TX", FC_SIZE);
break;
case I40E_FC_RX_PAUSE:
strlcpy(fc, "RX", FC_SIZE);
break;
default:
strlcpy(fc, "None", FC_SIZE);
break;
}
netdev_info(vsi->netdev, "NIC Link is Up %s Full Duplex, Flow Control: %s\n",
speed, fc);
}
static int i40e_up_complete(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
int err;
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
i40e_vsi_configure_msix(vsi);
else
i40e_configure_msi_and_legacy(vsi);
err = i40e_vsi_control_rings(vsi, true);
if (err)
return err;
clear_bit(__I40E_DOWN, &vsi->state);
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
pf->fd_add_err = pf->fd_atr_cnt = 0;
if (pf->fd_tcp_rule > 0) {
pf->flags &= ~I40E_FLAG_FD_ATR_ENABLED;
dev_info(&pf->pdev->dev, "Forcing ATR off, sideband rules for TCP/IPv4 exist\n");
pf->fd_tcp_rule = 0;
}
i40e_fdir_filter_restore(vsi);
}
i40e_service_event_schedule(pf);
return 0;
}
static void i40e_vsi_reinit_locked(struct i40e_vsi *vsi)
{
struct i40e_pf *pf = vsi->back;
WARN_ON(in_interrupt());
while (test_and_set_bit(__I40E_CONFIG_BUSY, &pf->state))
usleep_range(1000, 2000);
i40e_down(vsi);
if (vsi->type == I40E_VSI_SRIOV)
msleep(2000);
i40e_up(vsi);
clear_bit(__I40E_CONFIG_BUSY, &pf->state);
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
i40e_vsi_control_rings(vsi, false);
i40e_napi_disable_all(vsi);
for (i = 0; i < vsi->num_queue_pairs; i++) {
i40e_clean_tx_ring(vsi->tx_rings[i]);
i40e_clean_rx_ring(vsi->rx_rings[i]);
}
}
int i40e_open(struct net_device *netdev)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
int err;
if (test_bit(__I40E_TESTING, &pf->state) ||
test_bit(__I40E_BAD_EEPROM, &pf->state))
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
#ifdef CONFIG_I40E_VXLAN
vxlan_get_rx_port(netdev);
#endif
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
i40e_do_reset(pf, (1 << __I40E_PF_RESET_REQUESTED));
return err;
}
static void i40e_fdir_filter_exit(struct i40e_pf *pf)
{
struct i40e_fdir_filter *filter;
struct hlist_node *node2;
hlist_for_each_entry_safe(filter, node2,
&pf->fdir_filter_list, fdir_node) {
hlist_del(&filter->fdir_node);
kfree(filter);
}
pf->fdir_pf_active_filters = 0;
}
void i40e_do_reset(struct i40e_pf *pf, u32 reset_flags)
{
u32 val;
WARN_ON(in_interrupt());
if (i40e_check_asq_alive(&pf->hw))
i40e_vc_notify_reset(pf);
if (reset_flags & (1 << __I40E_GLOBAL_RESET_REQUESTED)) {
dev_dbg(&pf->pdev->dev, "GlobalR requested\n");
val = rd32(&pf->hw, I40E_GLGEN_RTRIG);
val |= I40E_GLGEN_RTRIG_GLOBR_MASK;
wr32(&pf->hw, I40E_GLGEN_RTRIG, val);
} else if (reset_flags & (1 << __I40E_CORE_RESET_REQUESTED)) {
dev_dbg(&pf->pdev->dev, "CoreR requested\n");
val = rd32(&pf->hw, I40E_GLGEN_RTRIG);
val |= I40E_GLGEN_RTRIG_CORER_MASK;
wr32(&pf->hw, I40E_GLGEN_RTRIG, val);
i40e_flush(&pf->hw);
} else if (reset_flags & (1 << __I40E_PF_RESET_REQUESTED)) {
dev_dbg(&pf->pdev->dev, "PFR requested\n");
i40e_handle_reset_warning(pf);
} else if (reset_flags & (1 << __I40E_REINIT_REQUESTED)) {
int v;
dev_info(&pf->pdev->dev,
"VSI reinit requested\n");
for (v = 0; v < pf->num_alloc_vsi; v++) {
struct i40e_vsi *vsi = pf->vsi[v];
if (vsi != NULL &&
test_bit(__I40E_REINIT_REQUESTED, &vsi->state)) {
i40e_vsi_reinit_locked(pf->vsi[v]);
clear_bit(__I40E_REINIT_REQUESTED, &vsi->state);
}
}
return;
} else if (reset_flags & (1 << __I40E_DOWN_REQUESTED)) {
int v;
dev_info(&pf->pdev->dev, "VSI down requested\n");
for (v = 0; v < pf->num_alloc_vsi; v++) {
struct i40e_vsi *vsi = pf->vsi[v];
if (vsi != NULL &&
test_bit(__I40E_DOWN_REQUESTED, &vsi->state)) {
set_bit(__I40E_DOWN, &vsi->state);
i40e_down(vsi);
clear_bit(__I40E_DOWN_REQUESTED, &vsi->state);
}
}
return;
} else {
dev_info(&pf->pdev->dev,
"bad reset request 0x%08x\n", reset_flags);
return;
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
dev_dbg(&pf->pdev->dev, "%s: need_reconfig=%d\n", __func__,
need_reconfig);
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
dev_dbg(&pf->pdev->dev,
"%s: LLDP event mib bridge type 0x%x\n", __func__, type);
if (type != I40E_AQ_LLDP_BRIDGE_TYPE_NEAREST_BRIDGE)
return ret;
type = mib->type & I40E_AQ_LLDP_MIB_TYPE_MASK;
dev_dbg(&pf->pdev->dev,
"%s: LLDP event mib type %s\n", __func__,
type ? "remote" : "local");
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
dev_info(&pf->pdev->dev, "Failed querying DCB configuration data from firmware.\n");
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
set_bit(__I40E_PORT_TX_SUSPENDED, &pf->state);
i40e_pf_quiesce_all_vsi(pf);
i40e_dcb_reconfigure(pf);
ret = i40e_resume_port_tx(pf);
clear_bit(__I40E_PORT_TX_SUSPENDED, &pf->state);
if (ret)
goto exit;
ret = i40e_pf_wait_txq_disabled(pf);
if (ret) {
set_bit(__I40E_PF_RESET_REQUESTED, &pf->state);
i40e_service_event_schedule(pf);
} else {
i40e_pf_unquiesce_all_vsi(pf);
}
exit:
return ret;
}
void i40e_do_reset_safe(struct i40e_pf *pf, u32 reset_flags)
{
rtnl_lock();
i40e_do_reset(pf, reset_flags);
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
static void i40e_service_event_complete(struct i40e_pf *pf)
{
BUG_ON(!test_bit(__I40E_SERVICE_SCHED, &pf->state));
smp_mb__before_atomic();
clear_bit(__I40E_SERVICE_SCHED, &pf->state);
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
u32 fcnt_prog, fcnt_avail;
if (test_bit(__I40E_FD_FLUSH_REQUESTED, &pf->state))
return;
fcnt_prog = i40e_get_global_fd_count(pf);
fcnt_avail = pf->fdir_pf_filter_count;
if ((fcnt_prog < (fcnt_avail - I40E_FDIR_BUFFER_HEAD_ROOM)) ||
(pf->fd_add_err == 0) ||
(i40e_get_current_atr_cnt(pf) < pf->fd_atr_cnt)) {
if ((pf->flags & I40E_FLAG_FD_SB_ENABLED) &&
(pf->auto_disable_flags & I40E_FLAG_FD_SB_ENABLED)) {
pf->auto_disable_flags &= ~I40E_FLAG_FD_SB_ENABLED;
dev_info(&pf->pdev->dev, "FD Sideband/ntuple is being enabled since we have space in the table now\n");
}
}
if (fcnt_prog < (fcnt_avail - I40E_FDIR_BUFFER_HEAD_ROOM * 2)) {
if ((pf->flags & I40E_FLAG_FD_ATR_ENABLED) &&
(pf->auto_disable_flags & I40E_FLAG_FD_ATR_ENABLED)) {
pf->auto_disable_flags &= ~I40E_FLAG_FD_ATR_ENABLED;
dev_info(&pf->pdev->dev, "ATR is being enabled since we have space in the table now\n");
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
if (!(pf->flags & (I40E_FLAG_FD_SB_ENABLED | I40E_FLAG_FD_ATR_ENABLED)))
return;
if (time_after(jiffies, pf->fd_flush_timestamp +
(I40E_MIN_FD_FLUSH_INTERVAL * HZ))) {
min_flush_time = pf->fd_flush_timestamp
+ (I40E_MIN_FD_FLUSH_SB_ATR_UNSTABLE * HZ);
fd_room = pf->fdir_pf_filter_count - pf->fdir_pf_active_filters;
if (!(time_after(jiffies, min_flush_time)) &&
(fd_room < I40E_FDIR_BUFFER_HEAD_ROOM_FOR_ATR)) {
dev_info(&pf->pdev->dev, "ATR disabled, not enough FD filter space.\n");
disable_atr = true;
}
pf->fd_flush_timestamp = jiffies;
pf->flags &= ~I40E_FLAG_FD_ATR_ENABLED;
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
if (!disable_atr)
pf->flags |= I40E_FLAG_FD_ATR_ENABLED;
clear_bit(__I40E_FD_FLUSH_REQUESTED, &pf->state);
dev_info(&pf->pdev->dev, "FD Filter table flushed and FD-SB replayed.\n");
}
}
}
u32 i40e_get_current_atr_cnt(struct i40e_pf *pf)
{
return i40e_get_current_fd_count(pf) - pf->fdir_pf_active_filters;
}
static void i40e_fdir_reinit_subtask(struct i40e_pf *pf)
{
if (test_bit(__I40E_DOWN, &pf->state))
return;
if (!(pf->flags & (I40E_FLAG_FD_SB_ENABLED | I40E_FLAG_FD_ATR_ENABLED)))
return;
if (test_bit(__I40E_FD_FLUSH_REQUESTED, &pf->state))
i40e_fdir_flush_and_replay(pf);
i40e_fdir_check_and_reenable(pf);
}
static void i40e_vsi_link_event(struct i40e_vsi *vsi, bool link_up)
{
if (!vsi || test_bit(__I40E_DOWN, &vsi->state))
return;
switch (vsi->type) {
case I40E_VSI_MAIN:
#ifdef I40E_FCOE
case I40E_VSI_FCOE:
#endif
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
bool new_link, old_link;
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
u8 new_link_speed, old_link_speed;
pf->hw.phy.get_link_info = true;
old_link = (pf->hw.phy.link_info_old.link_info & I40E_AQ_LINK_UP);
new_link = i40e_get_link_status(&pf->hw);
old_link_speed = pf->hw.phy.link_info_old.link_speed;
new_link_speed = pf->hw.phy.link_info.link_speed;
if (new_link == old_link &&
new_link_speed == old_link_speed &&
(test_bit(__I40E_DOWN, &vsi->state) ||
new_link == netif_carrier_ok(vsi->netdev)))
return;
if (!test_bit(__I40E_DOWN, &vsi->state))
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
static void i40e_check_hang_subtask(struct i40e_pf *pf)
{
int i, v;
if (test_bit(__I40E_DOWN, &pf->state) ||
test_bit(__I40E_CONFIG_BUSY, &pf->state))
return;
for (v = 0; v < pf->num_alloc_vsi; v++) {
struct i40e_vsi *vsi = pf->vsi[v];
int armed = 0;
if (!pf->vsi[v] ||
test_bit(__I40E_DOWN, &vsi->state) ||
(vsi->netdev && !netif_carrier_ok(vsi->netdev)))
continue;
for (i = 0; i < vsi->num_queue_pairs; i++) {
set_check_for_tx_hang(vsi->tx_rings[i]);
if (test_bit(__I40E_HANG_CHECK_ARMED,
&vsi->tx_rings[i]->state))
armed++;
}
if (armed) {
if (!(pf->flags & I40E_FLAG_MSIX_ENABLED)) {
wr32(&vsi->back->hw, I40E_PFINT_DYN_CTL0,
(I40E_PFINT_DYN_CTL0_INTENA_MASK |
I40E_PFINT_DYN_CTL0_SWINT_TRIG_MASK |
I40E_PFINT_DYN_CTL0_ITR_INDX_MASK |
I40E_PFINT_DYN_CTL0_SW_ITR_INDX_ENA_MASK |
I40E_PFINT_DYN_CTL0_SW_ITR_INDX_MASK));
} else {
u16 vec = vsi->base_vector - 1;
u32 val = (I40E_PFINT_DYN_CTLN_INTENA_MASK |
I40E_PFINT_DYN_CTLN_SWINT_TRIG_MASK |
I40E_PFINT_DYN_CTLN_ITR_INDX_MASK |
I40E_PFINT_DYN_CTLN_SW_ITR_INDX_ENA_MASK |
I40E_PFINT_DYN_CTLN_SW_ITR_INDX_MASK);
for (i = 0; i < vsi->num_q_vectors; i++, vec++)
wr32(&vsi->back->hw,
I40E_PFINT_DYN_CTLN(vec), val);
}
i40e_flush(&vsi->back->hw);
}
}
}
static void i40e_watchdog_subtask(struct i40e_pf *pf)
{
int i;
if (test_bit(__I40E_DOWN, &pf->state) ||
test_bit(__I40E_CONFIG_BUSY, &pf->state))
return;
if (time_before(jiffies, (pf->service_timer_previous +
pf->service_timer_period)))
return;
pf->service_timer_previous = jiffies;
i40e_check_hang_subtask(pf);
i40e_link_event(pf);
for (i = 0; i < pf->num_alloc_vsi; i++)
if (pf->vsi[i] && pf->vsi[i]->netdev)
i40e_update_stats(pf->vsi[i]);
for (i = 0; i < I40E_MAX_VEB; i++)
if (pf->veb[i])
i40e_update_veb_stats(pf->veb[i]);
i40e_ptp_rx_hang(pf->vsi[pf->lan_vsi]);
}
static void i40e_reset_subtask(struct i40e_pf *pf)
{
u32 reset_flags = 0;
rtnl_lock();
if (test_bit(__I40E_REINIT_REQUESTED, &pf->state)) {
reset_flags |= (1 << __I40E_REINIT_REQUESTED);
clear_bit(__I40E_REINIT_REQUESTED, &pf->state);
}
if (test_bit(__I40E_PF_RESET_REQUESTED, &pf->state)) {
reset_flags |= (1 << __I40E_PF_RESET_REQUESTED);
clear_bit(__I40E_PF_RESET_REQUESTED, &pf->state);
}
if (test_bit(__I40E_CORE_RESET_REQUESTED, &pf->state)) {
reset_flags |= (1 << __I40E_CORE_RESET_REQUESTED);
clear_bit(__I40E_CORE_RESET_REQUESTED, &pf->state);
}
if (test_bit(__I40E_GLOBAL_RESET_REQUESTED, &pf->state)) {
reset_flags |= (1 << __I40E_GLOBAL_RESET_REQUESTED);
clear_bit(__I40E_GLOBAL_RESET_REQUESTED, &pf->state);
}
if (test_bit(__I40E_DOWN_REQUESTED, &pf->state)) {
reset_flags |= (1 << __I40E_DOWN_REQUESTED);
clear_bit(__I40E_DOWN_REQUESTED, &pf->state);
}
if (test_bit(__I40E_RESET_INTR_RECEIVED, &pf->state)) {
i40e_handle_reset_warning(pf);
goto unlock;
}
if (reset_flags &&
!test_bit(__I40E_DOWN, &pf->state) &&
!test_bit(__I40E_CONFIG_BUSY, &pf->state))
i40e_do_reset(pf, reset_flags);
unlock:
rtnl_unlock();
}
static void i40e_handle_link_event(struct i40e_pf *pf,
struct i40e_arq_event_info *e)
{
struct i40e_hw *hw = &pf->hw;
struct i40e_aqc_get_link_status *status =
(struct i40e_aqc_get_link_status *)&e->desc.params.raw;
hw->phy.link_info_old = hw->phy.link_info;
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
if (test_bit(__I40E_RESET_FAILED, &pf->state))
return;
val = rd32(&pf->hw, pf->hw.aq.arq.len);
oldval = val;
if (val & I40E_PF_ARQLEN_ARQVFE_MASK) {
dev_info(&pf->pdev->dev, "ARQ VF Error detected\n");
val &= ~I40E_PF_ARQLEN_ARQVFE_MASK;
}
if (val & I40E_PF_ARQLEN_ARQOVFL_MASK) {
dev_info(&pf->pdev->dev, "ARQ Overflow Error detected\n");
val &= ~I40E_PF_ARQLEN_ARQOVFL_MASK;
}
if (val & I40E_PF_ARQLEN_ARQCRIT_MASK) {
dev_info(&pf->pdev->dev, "ARQ Critical Error detected\n");
val &= ~I40E_PF_ARQLEN_ARQCRIT_MASK;
}
if (oldval != val)
wr32(&pf->hw, pf->hw.aq.arq.len, val);
val = rd32(&pf->hw, pf->hw.aq.asq.len);
oldval = val;
if (val & I40E_PF_ATQLEN_ATQVFE_MASK) {
dev_info(&pf->pdev->dev, "ASQ VF Error detected\n");
val &= ~I40E_PF_ATQLEN_ATQVFE_MASK;
}
if (val & I40E_PF_ATQLEN_ATQOVFL_MASK) {
dev_info(&pf->pdev->dev, "ASQ Overflow Error detected\n");
val &= ~I40E_PF_ATQLEN_ATQOVFL_MASK;
}
if (val & I40E_PF_ATQLEN_ATQCRIT_MASK) {
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
i40e_debug(&pf->hw, I40E_DEBUG_NVM, "ARQ NVM operation completed\n");
break;
default:
dev_info(&pf->pdev->dev,
"ARQ Error: Unknown event 0x%04x received\n",
opcode);
break;
}
} while (pending && (i++ < pf->adminq_work_limit));
clear_bit(__I40E_ADMINQ_EVENT_PENDING, &pf->state);
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
set_bit(__I40E_BAD_EEPROM, &pf->state);
}
}
if (!err && test_bit(__I40E_BAD_EEPROM, &pf->state)) {
dev_info(&pf->pdev->dev, "eeprom check passed, Tx/Rx traffic enabled\n");
clear_bit(__I40E_BAD_EEPROM, &pf->state);
}
}
static void i40e_enable_pf_switch_lb(struct i40e_pf *pf)
{
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
struct i40e_vsi_context ctxt;
int aq_ret;
ctxt.seid = pf->main_vsi_seid;
ctxt.pf_num = pf->hw.pf_id;
ctxt.vf_num = 0;
aq_ret = i40e_aq_get_vsi_params(&pf->hw, &ctxt, NULL);
if (aq_ret) {
dev_info(&pf->pdev->dev,
"%s couldn't get PF vsi config, err %d, aq_err %d\n",
__func__, aq_ret, pf->hw.aq.asq_last_status);
return;
}
ctxt.flags = I40E_AQ_VSI_TYPE_PF;
ctxt.info.valid_sections = cpu_to_le16(I40E_AQ_VSI_PROP_SWITCH_VALID);
ctxt.info.switch_id |= cpu_to_le16(I40E_AQ_VSI_SW_ID_FLAG_ALLOW_LB);
aq_ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (aq_ret) {
dev_info(&pf->pdev->dev,
"%s: update vsi switch failed, aq_err=%d\n",
__func__, vsi->back->hw.aq.asq_last_status);
}
}
static void i40e_disable_pf_switch_lb(struct i40e_pf *pf)
{
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
struct i40e_vsi_context ctxt;
int aq_ret;
ctxt.seid = pf->main_vsi_seid;
ctxt.pf_num = pf->hw.pf_id;
ctxt.vf_num = 0;
aq_ret = i40e_aq_get_vsi_params(&pf->hw, &ctxt, NULL);
if (aq_ret) {
dev_info(&pf->pdev->dev,
"%s couldn't get PF vsi config, err %d, aq_err %d\n",
__func__, aq_ret, pf->hw.aq.asq_last_status);
return;
}
ctxt.flags = I40E_AQ_VSI_TYPE_PF;
ctxt.info.valid_sections = cpu_to_le16(I40E_AQ_VSI_PROP_SWITCH_VALID);
ctxt.info.switch_id &= ~cpu_to_le16(I40E_AQ_VSI_SW_ID_FLAG_ALLOW_LB);
aq_ret = i40e_aq_update_vsi_params(&vsi->back->hw, &ctxt, NULL);
if (aq_ret) {
dev_info(&pf->pdev->dev,
"%s: update vsi switch failed, aq_err=%d\n",
__func__, vsi->back->hw.aq.asq_last_status);
}
}
static void i40e_config_bridge_mode(struct i40e_veb *veb)
{
struct i40e_pf *pf = veb->pf;
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
"rebuild of owner VSI failed: %d\n", ret);
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
"capability discovery failed: aq=%d\n",
pf->hw.aq.asq_last_status);
return -ENODEV;
}
} while (err);
if (((pf->hw.aq.fw_maj_ver == 2) && (pf->hw.aq.fw_min_ver < 22)) ||
(pf->hw.aq.fw_maj_ver < 2)) {
pf->hw.func_caps.num_msix_vectors++;
pf->hw.func_caps.num_msix_vectors_vf++;
}
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
int i;
if (!rd32(&pf->hw, I40E_GLQF_HKEY(0))) {
static const u32 hkey[] = {
0xe640d33f, 0xcdfe98ab, 0x73fa7161, 0x0d7a7d36,
0xeacb7d61, 0xaa4f05b6, 0x9c5c89ed, 0xfc425ddb,
0xa4654832, 0xfc7461d4, 0x8f827619, 0xf5c63c21,
0x95b3a76d};
for (i = 0; i <= I40E_GLQF_HKEY_MAX_INDEX; i++)
wr32(&pf->hw, I40E_GLQF_HKEY(i), hkey[i]);
}
if (!(pf->flags & I40E_FLAG_FD_SB_ENABLED))
return;
vsi = NULL;
for (i = 0; i < pf->num_alloc_vsi; i++) {
if (pf->vsi[i] && pf->vsi[i]->type == I40E_VSI_FDIR) {
vsi = pf->vsi[i];
break;
}
}
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
int i;
i40e_fdir_filter_exit(pf);
for (i = 0; i < pf->num_alloc_vsi; i++) {
if (pf->vsi[i] && pf->vsi[i]->type == I40E_VSI_FDIR) {
i40e_vsi_release(pf->vsi[i]);
break;
}
}
}
static void i40e_prep_for_reset(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
i40e_status ret = 0;
u32 v;
clear_bit(__I40E_RESET_INTR_RECEIVED, &pf->state);
if (test_and_set_bit(__I40E_RESET_RECOVERY_PENDING, &pf->state))
return;
dev_dbg(&pf->pdev->dev, "Tearing down internal switch for reset\n");
i40e_pf_quiesce_all_vsi(pf);
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
static void i40e_reset_and_rebuild(struct i40e_pf *pf, bool reinit)
{
struct i40e_hw *hw = &pf->hw;
u8 set_fc_aq_fail = 0;
i40e_status ret;
u32 v;
ret = i40e_pf_reset(hw);
if (ret) {
dev_info(&pf->pdev->dev, "PF reset failed, %d\n", ret);
set_bit(__I40E_RESET_FAILED, &pf->state);
goto clear_recovery;
}
pf->pfr_count++;
if (test_bit(__I40E_DOWN, &pf->state))
goto clear_recovery;
dev_dbg(&pf->pdev->dev, "Rebuilding internal switch\n");
ret = i40e_init_adminq(&pf->hw);
if (ret) {
dev_info(&pf->pdev->dev, "Rebuild AdminQ failed, %d\n", ret);
goto clear_recovery;
}
if (test_and_clear_bit(__I40E_EMP_RESET_INTR_RECEIVED, &pf->state))
i40e_verify_eeprom(pf);
i40e_clear_pxe_mode(hw);
ret = i40e_get_capabilities(pf);
if (ret) {
dev_info(&pf->pdev->dev, "i40e_get_capabilities failed, %d\n",
ret);
goto end_core_reset;
}
ret = i40e_init_lan_hmc(hw, hw->func_caps.num_tx_qp,
hw->func_caps.num_rx_qp,
pf->fcoe_hmc_cntx_num, pf->fcoe_hmc_filt_num);
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
#ifdef I40E_FCOE
ret = i40e_init_pf_fcoe(pf);
if (ret)
dev_info(&pf->pdev->dev, "init_pf_fcoe failed: %d\n", ret);
#endif
ret = i40e_setup_pf_switch(pf, reinit);
if (ret)
goto end_core_reset;
ret = i40e_aq_set_phy_int_mask(&pf->hw,
I40E_AQ_EVENT_LINK_UPDOWN |
I40E_AQ_EVENT_MODULE_QUAL_FAIL, NULL);
if (ret)
dev_info(&pf->pdev->dev, "set phy mask fail, aq_err %d\n", ret);
ret = i40e_set_fc(&pf->hw, &set_fc_aq_fail, true);
if (ret)
dev_info(&pf->pdev->dev, "set fc fail, aq_err %d\n", ret);
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
goto end_core_reset;
}
}
if (((pf->hw.aq.fw_maj_ver == 4) && (pf->hw.aq.fw_min_ver < 33)) ||
(pf->hw.aq.fw_maj_ver < 4)) {
msleep(75);
ret = i40e_aq_set_link_restart_an(&pf->hw, true, NULL);
if (ret)
dev_info(&pf->pdev->dev, "link restart failed, aq_err=%d\n",
pf->hw.aq.asq_last_status);
}
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
ret = i40e_setup_misc_vector(pf);
i40e_pf_unquiesce_all_vsi(pf);
if (pf->num_alloc_vfs) {
for (v = 0; v < pf->num_alloc_vfs; v++)
i40e_reset_vf(&pf->vf[v], true);
}
i40e_send_version(pf);
end_core_reset:
clear_bit(__I40E_RESET_FAILED, &pf->state);
clear_recovery:
clear_bit(__I40E_RESET_RECOVERY_PENDING, &pf->state);
}
static void i40e_handle_reset_warning(struct i40e_pf *pf)
{
i40e_prep_for_reset(pf);
i40e_reset_and_rebuild(pf, false);
}
static void i40e_handle_mdd_event(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
bool mdd_detected = false;
bool pf_mdd_detected = false;
struct i40e_vf *vf;
u32 reg;
int i;
if (!test_bit(__I40E_MDD_EVENT_PENDING, &pf->state))
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
set_bit(__I40E_PF_RESET_REQUESTED, &pf->state);
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
set_bit(I40E_VF_STAT_DISABLED, &vf->vf_states);
}
}
clear_bit(__I40E_MDD_EVENT_PENDING, &pf->state);
reg = rd32(hw, I40E_PFINT_ICR0_ENA);
reg |= I40E_PFINT_ICR0_ENA_MAL_DETECT_MASK;
wr32(hw, I40E_PFINT_ICR0_ENA, reg);
i40e_flush(hw);
}
static void i40e_sync_vxlan_filters_subtask(struct i40e_pf *pf)
{
struct i40e_hw *hw = &pf->hw;
i40e_status ret;
__be16 port;
int i;
if (!(pf->flags & I40E_FLAG_VXLAN_FILTER_SYNC))
return;
pf->flags &= ~I40E_FLAG_VXLAN_FILTER_SYNC;
for (i = 0; i < I40E_MAX_PF_UDP_OFFLOAD_PORTS; i++) {
if (pf->pending_vxlan_bitmap & (1 << i)) {
pf->pending_vxlan_bitmap &= ~(1 << i);
port = pf->vxlan_ports[i];
if (port)
ret = i40e_aq_add_udp_tunnel(hw, ntohs(port),
I40E_AQC_TUNNEL_TYPE_VXLAN,
NULL, NULL);
else
ret = i40e_aq_del_udp_tunnel(hw, i, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"%s vxlan port %d, index %d failed, err %d, aq_err %d\n",
port ? "add" : "delete",
ntohs(port), i, ret,
pf->hw.aq.asq_last_status);
pf->vxlan_ports[i] = 0;
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
if (test_bit(__I40E_RESET_RECOVERY_PENDING, &pf->state)) {
i40e_service_event_complete(pf);
return;
}
i40e_reset_subtask(pf);
i40e_handle_mdd_event(pf);
i40e_vc_process_vflr_event(pf);
i40e_watchdog_subtask(pf);
i40e_fdir_reinit_subtask(pf);
i40e_sync_filters_subtask(pf);
#ifdef CONFIG_I40E_VXLAN
i40e_sync_vxlan_filters_subtask(pf);
#endif
i40e_clean_adminq_subtask(pf);
i40e_service_event_complete(pf);
if (time_after(jiffies, (start_time + pf->service_timer_period)) ||
test_bit(__I40E_ADMINQ_EVENT_PENDING, &pf->state) ||
test_bit(__I40E_MDD_EVENT_PENDING, &pf->state) ||
test_bit(__I40E_VFLR_EVENT_PENDING, &pf->state))
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
vsi->num_q_vectors = 1;
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
#ifdef I40E_FCOE
case I40E_VSI_FCOE:
vsi->alloc_queue_pairs = pf->num_fcoe_qps;
vsi->num_desc = ALIGN(I40E_DEFAULT_NUM_DESCRIPTORS,
I40E_REQ_DESCRIPTOR_MULTIPLE);
vsi->num_q_vectors = pf->num_fcoe_msix;
break;
#endif
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
set_bit(__I40E_DOWN, &vsi->state);
vsi->flags = 0;
vsi->idx = vsi_idx;
vsi->rx_itr_setting = pf->rx_itr_default;
vsi->tx_itr_setting = pf->tx_itr_default;
vsi->rss_table_size = (vsi->type == I40E_VSI_MAIN) ?
pf->rss_table_size : 64;
vsi->netdev_registered = false;
vsi->work_limit = I40E_DEFAULT_IRQ_WORK;
INIT_LIST_HEAD(&vsi->mac_filter_list);
vsi->irqs_ready = false;
ret = i40e_set_num_rings_in_vsi(vsi);
if (ret)
goto err_rings;
ret = i40e_vsi_alloc_arrays(vsi, true);
if (ret)
goto err_rings;
i40e_vsi_setup_irqhandler(vsi, i40e_msix_clean_rings);
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
if (pf->flags & I40E_FLAG_16BYTE_RX_DESC_ENABLED)
set_ring_16byte_desc_enabled(rx_ring);
else
clear_ring_16byte_desc_enabled(rx_ring);
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
int vectors_left;
int v_budget, i;
int v_actual;
if (!(pf->flags & I40E_FLAG_MSIX_ENABLED))
return -ENODEV;
vectors_left = hw->func_caps.num_msix_vectors;
v_budget = 0;
if (vectors_left) {
v_budget++;
vectors_left--;
}
pf->num_lan_msix = min_t(int, num_online_cpus(), vectors_left);
vectors_left -= pf->num_lan_msix;
v_budget += pf->num_lan_msix;
if (pf->flags & I40E_FLAG_FD_SB_ENABLED) {
if (vectors_left) {
v_budget++;
vectors_left--;
} else {
pf->flags &= ~I40E_FLAG_FD_SB_ENABLED;
}
}
#ifdef I40E_FCOE
if (pf->flags & I40E_FLAG_FCOE_ENABLED) {
if (!vectors_left)
pf->num_fcoe_msix = 0;
else if (vectors_left >= pf->num_fcoe_qps)
pf->num_fcoe_msix = pf->num_fcoe_qps;
else
pf->num_fcoe_msix = 1;
v_budget += pf->num_fcoe_msix;
vectors_left -= pf->num_fcoe_msix;
}
#endif
if (pf->flags & I40E_FLAG_VMDQ_ENABLED) {
int vmdq_vecs_wanted = pf->num_vmdq_vsis * pf->num_vmdq_qps;
int vmdq_vecs = min_t(int, vectors_left, vmdq_vecs_wanted);
if (vmdq_vecs < vmdq_vecs_wanted)
pf->num_vmdq_qps = 1;
pf->num_vmdq_msix = pf->num_vmdq_qps;
v_budget += vmdq_vecs;
vectors_left -= vmdq_vecs;
}
pf->msix_entries = kcalloc(v_budget, sizeof(struct msix_entry),
GFP_KERNEL);
if (!pf->msix_entries)
return -ENOMEM;
for (i = 0; i < v_budget; i++)
pf->msix_entries[i].entry = i;
v_actual = i40e_reserve_msix_vectors(pf, v_budget);
if (v_actual != v_budget) {
#ifdef I40E_FCOE
pf->num_fcoe_qps = 0;
pf->num_fcoe_msix = 0;
#endif
pf->num_vmdq_msix = 0;
}
if (v_actual < I40E_MIN_MSIX) {
pf->flags &= ~I40E_FLAG_MSIX_ENABLED;
kfree(pf->msix_entries);
pf->msix_entries = NULL;
return -ENODEV;
} else if (v_actual == I40E_MIN_MSIX) {
pf->num_vmdq_vsis = 0;
pf->num_vmdq_qps = 0;
pf->num_lan_qps = 1;
pf->num_lan_msix = 1;
} else if (v_actual != v_budget) {
int vec;
vec = v_actual - 1;
pf->num_vmdq_msix = 1;
pf->num_vmdq_vsis = 1;
pf->num_vmdq_qps = 1;
pf->flags &= ~I40E_FLAG_FD_SB_ENABLED;
switch (vec) {
case 2:
pf->num_lan_msix = 1;
break;
case 3:
#ifdef I40E_FCOE
if (pf->flags & I40E_FLAG_FCOE_ENABLED) {
pf->num_lan_msix = 1;
pf->num_fcoe_msix = 1;
}
#else
pf->num_lan_msix = 2;
#endif
break;
default:
#ifdef I40E_FCOE
if (pf->flags & I40E_FLAG_FCOE_ENABLED) {
pf->num_fcoe_msix = 1;
vec--;
}
#endif
pf->num_lan_msix = min_t(int, vec, pf->num_lan_qps);
break;
}
}
if ((pf->flags & I40E_FLAG_VMDQ_ENABLED) &&
(pf->num_vmdq_msix == 0)) {
dev_info(&pf->pdev->dev, "VMDq disabled, not enough MSI-X vectors\n");
pf->flags &= ~I40E_FLAG_VMDQ_ENABLED;
}
#ifdef I40E_FCOE
if ((pf->flags & I40E_FLAG_FCOE_ENABLED) && (pf->num_fcoe_msix == 0)) {
dev_info(&pf->pdev->dev, "FCOE disabled, not enough MSI-X vectors\n");
pf->flags &= ~I40E_FLAG_FCOE_ENABLED;
}
#endif
return v_actual;
}
static int i40e_vsi_alloc_q_vector(struct i40e_vsi *vsi, int v_idx)
{
struct i40e_q_vector *q_vector;
q_vector = kzalloc(sizeof(struct i40e_q_vector), GFP_KERNEL);
if (!q_vector)
return -ENOMEM;
q_vector->vsi = vsi;
q_vector->v_idx = v_idx;
cpumask_set_cpu(v_idx, &q_vector->affinity_mask);
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
int v_idx, num_q_vectors;
int err;
if (pf->flags & I40E_FLAG_MSIX_ENABLED)
num_q_vectors = vsi->num_q_vectors;
else if (vsi == pf->vsi[pf->lan_vsi])
num_q_vectors = 1;
else
return -EINVAL;
for (v_idx = 0; v_idx < num_q_vectors; v_idx++) {
err = i40e_vsi_alloc_q_vector(vsi, v_idx);
if (err)
goto err_out;
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
#ifdef I40E_FCOE
I40E_FLAG_FCOE_ENABLED |
#endif
I40E_FLAG_RSS_ENABLED |
I40E_FLAG_DCB_CAPABLE |
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
if (!test_bit(__I40E_RESET_RECOVERY_PENDING, &pf->state)) {
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
i40e_irq_dynamic_enable_icr0(pf);
return err;
}
static int i40e_config_rss(struct i40e_pf *pf)
{
u32 rss_key[I40E_PFQF_HKEY_MAX_INDEX + 1];
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
struct i40e_hw *hw = &pf->hw;
u32 lut = 0;
int i, j;
u64 hena;
u32 reg_val;
netdev_rss_key_fill(rss_key, sizeof(rss_key));
for (i = 0; i <= I40E_PFQF_HKEY_MAX_INDEX; i++)
wr32(hw, I40E_PFQF_HKEY(i), rss_key[i]);
hena = (u64)rd32(hw, I40E_PFQF_HENA(0)) |
((u64)rd32(hw, I40E_PFQF_HENA(1)) << 32);
hena |= I40E_DEFAULT_RSS_HENA;
wr32(hw, I40E_PFQF_HENA(0), (u32)hena);
wr32(hw, I40E_PFQF_HENA(1), (u32)(hena >> 32));
vsi->rss_size = min_t(int, pf->rss_size, vsi->num_queue_pairs);
reg_val = rd32(hw, I40E_PFQF_CTL_0);
if (pf->rss_table_size == 512)
reg_val |= I40E_PFQF_CTL_0_HASHLUTSIZE_512;
else
reg_val &= ~I40E_PFQF_CTL_0_HASHLUTSIZE_512;
wr32(hw, I40E_PFQF_CTL_0, reg_val);
for (i = 0, j = 0; i < pf->rss_table_size; i++, j++) {
if (j == vsi->rss_size)
j = 0;
lut = (lut << 8) | (j &
((0x1 << pf->hw.func_caps.rss_table_entry_width) - 1));
if ((i & 3) == 3)
wr32(hw, I40E_PFQF_HLUT(i >> 2), lut);
}
i40e_flush(hw);
return 0;
}
int i40e_reconfig_rss_queues(struct i40e_pf *pf, int queue_count)
{
struct i40e_vsi *vsi = pf->vsi[pf->lan_vsi];
int new_rss_size;
if (!(pf->flags & I40E_FLAG_RSS_ENABLED))
return 0;
new_rss_size = min_t(int, queue_count, pf->rss_size_max);
if (queue_count != vsi->num_queue_pairs) {
vsi->req_queue_pairs = queue_count;
i40e_prep_for_reset(pf);
pf->rss_size = new_rss_size;
i40e_reset_and_rebuild(pf, true);
i40e_config_rss(pf);
}
dev_info(&pf->pdev->dev, "RSS count: %d\n", pf->rss_size);
return pf->rss_size;
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
bw_data.pf_valid_bits = cpu_to_le16(1 << pf->hw.pf_id);
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
"Cannot acquire NVM for read access, err %d: aq_err %d\n",
ret, last_aq_status);
goto bw_commit_out;
}
ret = i40e_aq_read_nvm(&pf->hw,
I40E_SR_NVM_CONTROL_WORD,
0x10, sizeof(nvm_word), &nvm_word,
false, NULL);
last_aq_status = pf->hw.aq.asq_last_status;
i40e_release_nvm(&pf->hw);
if (ret) {
dev_info(&pf->pdev->dev, "NVM read error, err %d aq_err %d\n",
ret, last_aq_status);
goto bw_commit_out;
}
msleep(50);
ret = i40e_acquire_nvm(&pf->hw, I40E_RESOURCE_WRITE);
last_aq_status = pf->hw.aq.asq_last_status;
if (ret) {
dev_info(&pf->pdev->dev,
"Cannot acquire NVM for write access, err %d: aq_err %d\n",
ret, last_aq_status);
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
"BW settings NOT SAVED, err %d aq_err %d\n",
ret, last_aq_status);
bw_commit_out:
return ret;
}
static int i40e_sw_init(struct i40e_pf *pf)
{
int err = 0;
int size;
pf->msg_enable = netif_msg_init(I40E_DEFAULT_MSG_ENABLE,
(NETIF_MSG_DRV|NETIF_MSG_PROBE|NETIF_MSG_LINK));
pf->hw.debug_mask = pf->msg_enable | I40E_DEBUG_DIAG;
if (debug != -1 && debug != I40E_DEFAULT_MSG_ENABLE) {
if (I40E_DEBUG_USER & debug)
pf->hw.debug_mask = debug;
pf->msg_enable = netif_msg_init((debug & ~I40E_DEBUG_USER),
I40E_DEFAULT_MSG_ENABLE);
}
pf->flags = I40E_FLAG_RX_CSUM_ENABLED |
I40E_FLAG_MSI_ENABLED |
I40E_FLAG_MSIX_ENABLED;
if (iommu_present(&pci_bus_type))
pf->flags |= I40E_FLAG_RX_PS_ENABLED;
else
pf->flags |= I40E_FLAG_RX_1BUF_ENABLED;
pf->rx_itr_default = I40E_ITR_DYNAMIC | I40E_ITR_RX_DEF;
pf->tx_itr_default = I40E_ITR_DYNAMIC | I40E_ITR_TX_DEF;
pf->rss_size_max = 0x1 << pf->hw.func_caps.rss_table_entry_width;
pf->rss_size = 1;
pf->rss_table_size = pf->hw.func_caps.rss_table_size;
pf->rss_size_max = min_t(int, pf->rss_size_max,
pf->hw.func_caps.num_tx_qp);
if (pf->hw.func_caps.rss) {
pf->flags |= I40E_FLAG_RSS_ENABLED;
pf->rss_size = min_t(int, pf->rss_size_max, num_online_cpus());
}
if (pf->hw.func_caps.npar_enable || pf->hw.func_caps.mfp_mode_1) {
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
pf->fd_atr_cnt_idx = I40E_FD_ATR_STAT_IDX(pf->hw.pf_id);
if (!(pf->flags & I40E_FLAG_MFP_ENABLED)) {
pf->flags |= I40E_FLAG_FD_SB_ENABLED;
pf->fd_sb_cnt_idx = I40E_FD_SB_STAT_IDX(pf->hw.pf_id);
} else {
dev_info(&pf->pdev->dev,
"Flow Director Sideband mode Disabled in MFP mode\n");
}
pf->fdir_pf_filter_count =
pf->hw.func_caps.fd_filters_guaranteed;
pf->hw.fdir_shared_filter_count =
pf->hw.func_caps.fd_filters_best_effort;
}
if (pf->hw.func_caps.vmdq) {
pf->flags |= I40E_FLAG_VMDQ_ENABLED;
pf->num_vmdq_vsis = I40E_DEFAULT_NUM_VMDQ_VSI;
pf->num_vmdq_qps = I40E_DEFAULT_QUEUES_PER_VMDQ;
}
#ifdef I40E_FCOE
err = i40e_init_pf_fcoe(pf);
if (err)
dev_info(&pf->pdev->dev, "init_pf_fcoe failed: %d\n", err);
#endif
#ifdef CONFIG_PCI_IOV
if (pf->hw.func_caps.num_vfs && pf->hw.partition_id == 1) {
pf->num_vf_qps = I40E_DEFAULT_QUEUES_PER_VF;
pf->flags |= I40E_FLAG_SRIOV_ENABLED;
pf->num_req_vfs = min_t(int,
pf->hw.func_caps.num_vfs,
I40E_MAX_VF_COUNT);
}
#endif
pf->eeprom_version = 0xDEAD;
pf->lan_veb = I40E_NO_VEB;
pf->lan_vsi = I40E_NO_VSI;
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
pf->flags |= I40E_FLAG_FD_SB_ENABLED;
} else {
if (pf->flags & I40E_FLAG_FD_SB_ENABLED) {
need_reset = true;
i40e_fdir_filter_exit(pf);
}
pf->flags &= ~I40E_FLAG_FD_SB_ENABLED;
pf->auto_disable_flags &= ~I40E_FLAG_FD_SB_ENABLED;
pf->fd_add_err = pf->fd_atr_cnt = pf->fd_tcp_rule = 0;
pf->fdir_pf_active_filters = 0;
pf->flags |= I40E_FLAG_FD_ATR_ENABLED;
dev_info(&pf->pdev->dev, "ATR re-enabled.\n");
if ((pf->flags & I40E_FLAG_FD_ATR_ENABLED) &&
(pf->auto_disable_flags & I40E_FLAG_FD_ATR_ENABLED))
pf->auto_disable_flags &= ~I40E_FLAG_FD_ATR_ENABLED;
}
return need_reset;
}
static int i40e_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
bool need_reset;
if (features & NETIF_F_HW_VLAN_CTAG_RX)
i40e_vlan_stripping_enable(vsi);
else
i40e_vlan_stripping_disable(vsi);
need_reset = i40e_set_ntuple(pf, features);
if (need_reset)
i40e_do_reset(pf, (1 << __I40E_PF_RESET_REQUESTED));
return 0;
}
static u8 i40e_get_vxlan_port_idx(struct i40e_pf *pf, __be16 port)
{
u8 i;
for (i = 0; i < I40E_MAX_PF_UDP_OFFLOAD_PORTS; i++) {
if (pf->vxlan_ports[i] == port)
return i;
}
return i;
}
static void i40e_add_vxlan_port(struct net_device *netdev,
sa_family_t sa_family, __be16 port)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
u8 next_idx;
u8 idx;
if (sa_family == AF_INET6)
return;
idx = i40e_get_vxlan_port_idx(pf, port);
if (idx < I40E_MAX_PF_UDP_OFFLOAD_PORTS) {
netdev_info(netdev, "vxlan port %d already offloaded\n",
ntohs(port));
return;
}
next_idx = i40e_get_vxlan_port_idx(pf, 0);
if (next_idx == I40E_MAX_PF_UDP_OFFLOAD_PORTS) {
netdev_info(netdev, "maximum number of vxlan UDP ports reached, not adding port %d\n",
ntohs(port));
return;
}
pf->vxlan_ports[next_idx] = port;
pf->pending_vxlan_bitmap |= (1 << next_idx);
pf->flags |= I40E_FLAG_VXLAN_FILTER_SYNC;
dev_info(&pf->pdev->dev, "adding vxlan port %d\n", ntohs(port));
}
static void i40e_del_vxlan_port(struct net_device *netdev,
sa_family_t sa_family, __be16 port)
{
struct i40e_netdev_priv *np = netdev_priv(netdev);
struct i40e_vsi *vsi = np->vsi;
struct i40e_pf *pf = vsi->back;
u8 idx;
if (sa_family == AF_INET6)
return;
idx = i40e_get_vxlan_port_idx(pf, port);
if (idx < I40E_MAX_PF_UDP_OFFLOAD_PORTS) {
pf->vxlan_ports[idx] = 0;
pf->pending_vxlan_bitmap |= (1 << idx);
pf->flags |= I40E_FLAG_VXLAN_FILTER_SYNC;
dev_info(&pf->pdev->dev, "deleting vxlan port %d\n",
ntohs(port));
} else {
netdev_warn(netdev, "vxlan port %d was not found, not deleting\n",
ntohs(port));
}
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
struct nlmsghdr *nlh)
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
i40e_do_reset(pf, BIT_ULL(__I40E_PF_RESET_REQUESTED));
break;
}
}
return 0;
}
static int i40e_config_netdev(struct i40e_vsi *vsi)
{
u8 brdcast[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
struct i40e_netdev_priv *np;
struct net_device *netdev;
u8 mac_addr[ETH_ALEN];
int etherdev_size;
etherdev_size = sizeof(struct i40e_netdev_priv);
netdev = alloc_etherdev_mq(etherdev_size, vsi->alloc_queue_pairs);
if (!netdev)
return -ENOMEM;
vsi->netdev = netdev;
np = netdev_priv(netdev);
np->vsi = vsi;
netdev->hw_enc_features |= NETIF_F_IP_CSUM |
NETIF_F_GSO_UDP_TUNNEL |
NETIF_F_TSO;
netdev->features = NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_SCTP_CSUM |
NETIF_F_HIGHDMA |
NETIF_F_GSO_UDP_TUNNEL |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_FILTER |
NETIF_F_IPV6_CSUM |
NETIF_F_TSO |
NETIF_F_TSO_ECN |
NETIF_F_TSO6 |
NETIF_F_RXCSUM |
NETIF_F_RXHASH |
0;
if (!(pf->flags & I40E_FLAG_MFP_ENABLED))
netdev->features |= NETIF_F_NTUPLE;
netdev->hw_features |= netdev->features;
if (vsi->type == I40E_VSI_MAIN) {
SET_NETDEV_DEV(netdev, &pf->pdev->dev);
ether_addr_copy(mac_addr, hw->mac.perm_addr);
if (!i40e_rm_default_mac_filter(vsi, mac_addr))
i40e_add_filter(vsi, mac_addr,
I40E_VLAN_ANY, false, true);
} else {
snprintf(netdev->name, IFNAMSIZ, "%sv%%d",
pf->vsi[pf->lan_vsi]->netdev->name);
random_ether_addr(mac_addr);
i40e_add_filter(vsi, mac_addr, I40E_VLAN_ANY, false, false);
}
i40e_add_filter(vsi, brdcast, I40E_VLAN_ANY, false, false);
ether_addr_copy(netdev->dev_addr, mac_addr);
ether_addr_copy(netdev->perm_addr, mac_addr);
netdev->vlan_features = netdev->features & ~(NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_FILTER);
netdev->priv_flags |= IFF_UNICAST_FLT;
netdev->priv_flags |= IFF_SUPP_NOFCS;
i40e_vsi_config_netdev_tc(vsi, vsi->tc_config.enabled_tc);
netdev->netdev_ops = &i40e_netdev_ops;
netdev->watchdog_timeo = 5 * HZ;
i40e_set_ethtool_ops(netdev);
#ifdef I40E_FCOE
i40e_fcoe_config_netdev(netdev, vsi);
#endif
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
if (veb && (veb->bridge_mode & BRIDGE_MODE_VEPA))
return 0;
return 1;
}
static int i40e_add_vsi(struct i40e_vsi *vsi)
{
int ret = -ENODEV;
struct i40e_mac_filter *f, *ftmp;
struct i40e_pf *pf = vsi->back;
struct i40e_hw *hw = &pf->hw;
struct i40e_vsi_context ctxt;
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
"couldn't get PF vsi config, err %d, aq_err %d\n",
ret, pf->hw.aq.asq_last_status);
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
"update vsi failed, aq_err=%d\n",
pf->hw.aq.asq_last_status);
ret = -ENOENT;
goto err;
}
i40e_vsi_update_queue_map(vsi, &ctxt);
vsi->info.valid_sections = 0;
} else {
ret = i40e_vsi_config_tc(vsi, enabled_tc);
if (ret) {
dev_info(&pf->pdev->dev,
"failed to configure TCs for main VSI tc_map 0x%08x, err %d, aq_err %d\n",
enabled_tc, ret,
pf->hw.aq.asq_last_status);
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
#ifdef I40E_FCOE
case I40E_VSI_FCOE:
ret = i40e_fcoe_vsi_init(vsi, &ctxt);
if (ret) {
dev_info(&pf->pdev->dev, "failed to initialize FCoE VSI\n");
return ret;
}
break;
#endif
default:
return -ENODEV;
}
if (vsi->type != I40E_VSI_MAIN) {
ret = i40e_aq_add_vsi(hw, &ctxt, NULL);
if (ret) {
dev_info(&vsi->back->pdev->dev,
"add vsi failed, aq_err=%d\n",
vsi->back->hw.aq.asq_last_status);
ret = -ENOENT;
goto err;
}
vsi->info = ctxt.info;
vsi->info.valid_sections = 0;
vsi->seid = ctxt.seid;
vsi->id = ctxt.vsi_number;
}
list_for_each_entry_safe(f, ftmp, &vsi->mac_filter_list, list) {
f->changed = true;
f_count++;
if (f->is_laa && vsi->type == I40E_VSI_MAIN) {
struct i40e_aqc_remove_macvlan_element_data element;
memset(&element, 0, sizeof(element));
ether_addr_copy(element.mac_addr, f->macaddr);
element.flags = I40E_AQC_MACVLAN_DEL_PERFECT_MATCH;
ret = i40e_aq_remove_macvlan(hw, vsi->seid,
&element, 1, NULL);
if (ret) {
element.flags |=
I40E_AQC_MACVLAN_DEL_IGNORE_VLAN;
i40e_aq_remove_macvlan(hw, vsi->seid,
&element, 1, NULL);
}
i40e_aq_mac_address_write(hw,
I40E_AQC_WRITE_TYPE_LAA_WOL,
f->macaddr, NULL);
}
}
if (f_count) {
vsi->flags |= I40E_VSI_FLAG_FILTER_CHANGED;
pf->flags |= I40E_FLAG_FILTER_SYNC;
}
ret = i40e_vsi_get_bw_info(vsi);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't get vsi bw info, err %d, aq_err %d\n",
ret, pf->hw.aq.asq_last_status);
ret = 0;
}
err:
return ret;
}
int i40e_vsi_release(struct i40e_vsi *vsi)
{
struct i40e_mac_filter *f, *ftmp;
struct i40e_veb *veb = NULL;
struct i40e_pf *pf;
u16 uplink_seid;
int i, n;
pf = vsi->back;
if (vsi->flags & I40E_VSI_FLAG_VEB_OWNER) {
dev_info(&pf->pdev->dev, "VSI %d has existing VEB %d\n",
vsi->seid, vsi->uplink_seid);
return -ENODEV;
}
if (vsi == pf->vsi[pf->lan_vsi] &&
!test_bit(__I40E_DOWN, &pf->state)) {
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
list_for_each_entry_safe(f, ftmp, &vsi->mac_filter_list, list)
i40e_del_filter(vsi, f->macaddr, f->vlan,
f->is_vf, f->is_netdev);
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
struct i40e_pf *pf = vsi->back;
u8 enabled_tc;
int ret;
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
"failed to get tracking for %d queues for VSI %d err=%d\n",
vsi->alloc_queue_pairs, vsi->seid, ret);
goto err_vsi;
}
vsi->base_queue = ret;
enabled_tc = pf->vsi[pf->lan_vsi]->tc_config.enabled_tc;
pf->vsi[pf->lan_vsi]->tc_config.enabled_tc = 0;
pf->vsi[pf->lan_vsi]->seid = pf->main_vsi_seid;
i40e_vsi_config_tc(pf->vsi[pf->lan_vsi], enabled_tc);
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
"%s: New VSI creation error, uplink seid of LAN VSI expected.\n",
__func__);
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
case I40E_VSI_VMDQ2:
case I40E_VSI_FCOE:
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
"query veb bw config failed, aq_err=%d\n",
hw->aq.asq_last_status);
goto out;
}
ret = i40e_aq_query_switch_comp_ets_config(hw, veb->seid,
&ets_data, NULL);
if (ret) {
dev_info(&pf->pdev->dev,
"query veb bw ets config failed, aq_err=%d\n",
hw->aq.asq_last_status);
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
bool is_default = false;
bool is_cloud = false;
int ret;
ret = i40e_aq_add_veb(&veb->pf->hw, veb->uplink_seid, vsi->seid,
veb->enabled_tc, is_default,
is_cloud, &veb->seid, NULL);
if (ret) {
dev_info(&veb->pf->pdev->dev,
"couldn't add VEB, err %d, aq_err %d\n",
ret, veb->pf->hw.aq.asq_last_status);
return -EPERM;
}
ret = i40e_aq_get_veb_parameters(&veb->pf->hw, veb->seid, NULL, NULL,
&veb->stats_idx, NULL, NULL, NULL);
if (ret) {
dev_info(&veb->pf->pdev->dev,
"couldn't get VEB statistics idx, err %d, aq_err %d\n",
ret, veb->pf->hw.aq.asq_last_status);
return -EPERM;
}
ret = i40e_veb_get_bw_info(veb);
if (ret) {
dev_info(&veb->pf->pdev->dev,
"couldn't get VEB bw info, err %d, aq_err %d\n",
ret, veb->pf->hw.aq.asq_last_status);
i40e_aq_delete_element(&veb->pf->hw, veb->seid, NULL);
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
"get switch config failed %d aq_err=%x\n",
ret, pf->hw.aq.asq_last_status);
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
int ret;
ret = i40e_fetch_switch_configuration(pf, false);
if (ret) {
dev_info(&pf->pdev->dev,
"couldn't fetch switch config, err %d, aq_err %d\n",
ret, pf->hw.aq.asq_last_status);
return ret;
}
i40e_pf_reset_stats(pf);
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
i40e_config_rss(pf);
i40e_aq_get_link_info(&pf->hw, true, NULL, NULL);
i40e_link_event(pf);
pf->fc_autoneg_status = ((pf->hw.phy.link_info.an_info &
I40E_AQ_AN_COMPLETED) ? true : false);
i40e_ptp_init(pf);
return ret;
}
static void i40e_determine_queue_usage(struct i40e_pf *pf)
{
int queues_left;
pf->num_lan_qps = 0;
#ifdef I40E_FCOE
pf->num_fcoe_qps = 0;
#endif
queues_left = pf->hw.func_caps.num_tx_qp;
if ((queues_left == 1) ||
!(pf->flags & I40E_FLAG_MSIX_ENABLED)) {
queues_left = 0;
pf->rss_size = pf->num_lan_qps = 1;
pf->flags &= ~(I40E_FLAG_RSS_ENABLED |
#ifdef I40E_FCOE
I40E_FLAG_FCOE_ENABLED |
#endif
I40E_FLAG_FD_SB_ENABLED |
I40E_FLAG_FD_ATR_ENABLED |
I40E_FLAG_DCB_CAPABLE |
I40E_FLAG_SRIOV_ENABLED |
I40E_FLAG_VMDQ_ENABLED);
} else if (!(pf->flags & (I40E_FLAG_RSS_ENABLED |
I40E_FLAG_FD_SB_ENABLED |
I40E_FLAG_FD_ATR_ENABLED |
I40E_FLAG_DCB_CAPABLE))) {
pf->rss_size = pf->num_lan_qps = 1;
queues_left -= pf->num_lan_qps;
pf->flags &= ~(I40E_FLAG_RSS_ENABLED |
#ifdef I40E_FCOE
I40E_FLAG_FCOE_ENABLED |
#endif
I40E_FLAG_FD_SB_ENABLED |
I40E_FLAG_FD_ATR_ENABLED |
I40E_FLAG_DCB_ENABLED |
I40E_FLAG_VMDQ_ENABLED);
} else {
if ((pf->flags & I40E_FLAG_DCB_CAPABLE) &&
(queues_left < I40E_MAX_TRAFFIC_CLASS)) {
pf->flags &= ~I40E_FLAG_DCB_CAPABLE;
dev_info(&pf->pdev->dev, "not enough queues for DCB. DCB is disabled.\n");
}
pf->num_lan_qps = max_t(int, pf->rss_size_max,
num_online_cpus());
pf->num_lan_qps = min_t(int, pf->num_lan_qps,
pf->hw.func_caps.num_tx_qp);
queues_left -= pf->num_lan_qps;
}
#ifdef I40E_FCOE
if (pf->flags & I40E_FLAG_FCOE_ENABLED) {
if (I40E_DEFAULT_FCOE <= queues_left) {
pf->num_fcoe_qps = I40E_DEFAULT_FCOE;
} else if (I40E_MINIMUM_FCOE <= queues_left) {
pf->num_fcoe_qps = I40E_MINIMUM_FCOE;
} else {
pf->num_fcoe_qps = 0;
pf->flags &= ~I40E_FLAG_FCOE_ENABLED;
dev_info(&pf->pdev->dev, "not enough queues for FCoE. FCoE feature will be disabled\n");
}
queues_left -= pf->num_fcoe_qps;
}
#endif
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
#ifdef I40E_FCOE
dev_info(&pf->pdev->dev, "fcoe queues = %d\n", pf->num_fcoe_qps);
#endif
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
char *buf, *string;
string = kzalloc(INFO_STRING_LEN, GFP_KERNEL);
if (!string) {
dev_err(&pf->pdev->dev, "Features string allocation failed\n");
return;
}
buf = string;
buf += sprintf(string, "Features: PF-id[%d] ", hw->pf_id);
#ifdef CONFIG_PCI_IOV
buf += sprintf(buf, "VFs: %d ", pf->num_req_vfs);
#endif
buf += sprintf(buf, "VSIs: %d QP: %d RX: %s ",
pf->hw.func_caps.num_vsis,
pf->vsi[pf->lan_vsi]->num_queue_pairs,
pf->flags & I40E_FLAG_RX_PS_ENABLED ? "PS" : "1BUF");
if (pf->flags & I40E_FLAG_RSS_ENABLED)
buf += sprintf(buf, "RSS ");
if (pf->flags & I40E_FLAG_FD_ATR_ENABLED)
buf += sprintf(buf, "FD_ATR ");
if (pf->flags & I40E_FLAG_FD_SB_ENABLED) {
buf += sprintf(buf, "FD_SB ");
buf += sprintf(buf, "NTUPLE ");
}
if (pf->flags & I40E_FLAG_DCB_CAPABLE)
buf += sprintf(buf, "DCB ");
if (pf->flags & I40E_FLAG_PTP)
buf += sprintf(buf, "PTP ");
#ifdef I40E_FCOE
if (pf->flags & I40E_FLAG_FCOE_ENABLED)
buf += sprintf(buf, "FCOE ");
#endif
BUG_ON(buf > (string + INFO_STRING_LEN));
dev_info(&pf->pdev->dev, "%s\n", string);
kfree(string);
}
static int i40e_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct i40e_aq_get_phy_abilities_resp abilities;
unsigned long ioremap_len;
struct i40e_pf *pf;
struct i40e_hw *hw;
static u16 pfs_found;
u16 link_status;
int err = 0;
u32 len;
u32 i;
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
err = pci_request_selected_regions(pdev, pci_select_bars(pdev,
IORESOURCE_MEM), i40e_driver_name);
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
set_bit(__I40E_DOWN, &pf->state);
hw = &pf->hw;
hw->back = pf;
ioremap_len = min_t(unsigned long, pci_resource_len(pdev, 0),
I40E_MAX_CSR_SPACE);
hw->hw_addr = ioremap(pci_resource_start(pdev, 0), ioremap_len);
if (!hw->hw_addr) {
err = -EIO;
dev_info(&pdev->dev, "ioremap(0x%04x, 0x%04x) failed: 0x%x\n",
(unsigned int)pci_resource_start(pdev, 0),
(unsigned int)pci_resource_len(pdev, 0), err);
goto err_ioremap;
}
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
pci_read_config_byte(pdev, PCI_REVISION_ID, &hw->revision_id);
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
hw->bus.device = PCI_SLOT(pdev->devfn);
hw->bus.func = PCI_FUNC(pdev->devfn);
pf->instance = pfs_found;
if (debug != -1) {
pf->msg_enable = pf->hw.debug_mask;
pf->msg_enable = debug;
}
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
dev_info(&pdev->dev, "init_shared_code failed: %d\n", err);
goto err_pf_reset;
}
pf->hw.fc.requested_mode = I40E_FC_NONE;
err = i40e_init_adminq(hw);
dev_info(&pdev->dev, "%s\n", i40e_fw_version_str(hw));
if (err) {
dev_info(&pdev->dev,
"The driver for the device stopped because the NVM image is newer than expected. You must install the most recent version of the network driver.\n");
goto err_pf_reset;
}
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
hw->func_caps.num_rx_qp,
pf->fcoe_hmc_cntx_num, pf->fcoe_hmc_filt_num);
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
if (((pf->hw.aq.fw_maj_ver == 4) && (pf->hw.aq.fw_min_ver < 3)) ||
(pf->hw.aq.fw_maj_ver < 4)) {
dev_info(&pdev->dev, "Stopping firmware LLDP agent.\n");
i40e_aq_stop_lldp(hw, true, NULL);
}
i40e_get_mac_addr(hw, hw->mac.addr);
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
#ifdef I40E_FCOE
err = i40e_get_san_mac_addr(hw, hw->mac.san_addr);
if (err)
dev_info(&pdev->dev,
"(non-fatal) SAN MAC retrieval failed: %d\n", err);
if (!is_valid_ether_addr(hw->mac.san_addr)) {
dev_warn(&pdev->dev, "invalid SAN MAC address %pM, falling back to LAN MAC\n",
hw->mac.san_addr);
ether_addr_copy(hw->mac.san_addr, hw->mac.addr);
}
dev_info(&pf->pdev->dev, "SAN MAC: %pM\n", hw->mac.san_addr);
#endif
pci_set_drvdata(pdev, pf);
pci_save_state(pdev);
#ifdef CONFIG_I40E_DCB
err = i40e_init_pf_dcb(pf);
if (err) {
dev_info(&pdev->dev, "DCB init failed %d, disabled\n", err);
pf->flags &= ~I40E_FLAG_DCB_CAPABLE;
}
#endif
setup_timer(&pf->service_timer, i40e_service_timer, (unsigned long)pf);
pf->service_timer_period = HZ;
INIT_WORK(&pf->service_task, i40e_service_task);
clear_bit(__I40E_SERVICE_SCHED, &pf->state);
pf->flags |= I40E_FLAG_NEED_LINK_UPDATE;
pf->link_check_timeout = jiffies;
pf->wol_en = false;
device_set_wakeup_enable(&pf->pdev->dev, pf->wol_en);
i40e_determine_queue_usage(pf);
err = i40e_init_interrupt_scheme(pf);
if (err)
goto err_switch_setup;
if (pf->hw.func_caps.num_vsis < I40E_MIN_VSI_ALLOC)
pf->num_alloc_vsi = I40E_MIN_VSI_ALLOC;
else
pf->num_alloc_vsi = pf->hw.func_caps.num_vsis;
len = sizeof(struct i40e_vsi *) * pf->num_alloc_vsi;
pf->vsi = kzalloc(len, GFP_KERNEL);
if (!pf->vsi) {
err = -ENOMEM;
goto err_switch_setup;
}
#ifdef CONFIG_PCI_IOV
if ((pf->flags & I40E_FLAG_SRIOV_ENABLED) &&
(pf->flags & I40E_FLAG_MSIX_ENABLED) &&
!test_bit(__I40E_BAD_EEPROM, &pf->state)) {
if (pci_num_vf(pdev))
pf->flags |= I40E_FLAG_VEB_MODE_ENABLED;
}
#endif
err = i40e_setup_pf_switch(pf, false);
if (err) {
dev_info(&pdev->dev, "setup_pf_switch failed: %d\n", err);
goto err_vsis;
}
for (i = 0; i < pf->num_alloc_vsi; i++) {
if (pf->vsi[i] && pf->vsi[i]->type == I40E_VSI_FDIR) {
i40e_vsi_open(pf->vsi[i]);
break;
}
}
err = i40e_aq_set_phy_int_mask(&pf->hw,
I40E_AQ_EVENT_LINK_UPDOWN |
I40E_AQ_EVENT_MODULE_QUAL_FAIL, NULL);
if (err)
dev_info(&pf->pdev->dev, "set phy mask fail, aq_err %d\n", err);
if (((pf->hw.aq.fw_maj_ver == 4) && (pf->hw.aq.fw_min_ver < 33)) ||
(pf->hw.aq.fw_maj_ver < 4)) {
msleep(75);
err = i40e_aq_set_link_restart_an(&pf->hw, true, NULL);
if (err)
dev_info(&pf->pdev->dev, "link restart failed, aq_err=%d\n",
pf->hw.aq.asq_last_status);
}
clear_bit(__I40E_DOWN, &pf->state);
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
!test_bit(__I40E_BAD_EEPROM, &pf->state)) {
u32 val;
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
pfs_found++;
i40e_dbg_pf_init(pf);
i40e_send_version(pf);
mod_timer(&pf->service_timer,
round_jiffies(jiffies + pf->service_timer_period));
#ifdef I40E_FCOE
i40e_fcoe_vsi_setup(pf);
#endif
pcie_capability_read_word(pf->pdev, PCI_EXP_LNKSTA, &link_status);
i40e_set_pci_config_data(hw, link_status);
dev_info(&pdev->dev, "PCI-Express: %s %s\n",
(hw->bus.speed == i40e_bus_speed_8000 ? "Speed 8.0GT/s" :
hw->bus.speed == i40e_bus_speed_5000 ? "Speed 5.0GT/s" :
hw->bus.speed == i40e_bus_speed_2500 ? "Speed 2.5GT/s" :
"Unknown"),
(hw->bus.width == i40e_bus_width_pcie_x8 ? "Width x8" :
hw->bus.width == i40e_bus_width_pcie_x4 ? "Width x4" :
hw->bus.width == i40e_bus_width_pcie_x2 ? "Width x2" :
hw->bus.width == i40e_bus_width_pcie_x1 ? "Width x1" :
"Unknown"));
if (hw->bus.width < i40e_bus_width_pcie_x8 ||
hw->bus.speed < i40e_bus_speed_8000) {
dev_warn(&pdev->dev, "PCI-Express bandwidth available for this device may be insufficient for optimal performance.\n");
dev_warn(&pdev->dev, "Please move the device to a different PCI-e link with more lanes and/or higher transfer rate.\n");
}
err = i40e_aq_get_phy_capabilities(hw, false, false, &abilities, NULL);
if (err)
dev_info(&pf->pdev->dev, "get phy abilities failed, aq_err %d, advertised speed settings may not be correct\n",
err);
pf->hw.phy.link_info.requested_speeds = abilities.link_speed;
i40e_print_features(pf);
return 0;
err_vsis:
set_bit(__I40E_DOWN, &pf->state);
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
(void)i40e_shutdown_adminq(hw);
err_pf_reset:
iounmap(hw->hw_addr);
err_ioremap:
kfree(pf);
err_pf_alloc:
pci_disable_pcie_error_reporting(pdev);
pci_release_selected_regions(pdev,
pci_select_bars(pdev, IORESOURCE_MEM));
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static void i40e_remove(struct pci_dev *pdev)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
i40e_status ret_code;
int i;
i40e_dbg_pf_exit(pf);
i40e_ptp_stop(pf);
set_bit(__I40E_DOWN, &pf->state);
del_timer_sync(&pf->service_timer);
cancel_work_sync(&pf->service_task);
i40e_fdir_teardown(pf);
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
if (pf->hw.hmc.hmc_obj) {
ret_code = i40e_shutdown_lan_hmc(&pf->hw);
if (ret_code)
dev_warn(&pdev->dev,
"Failed to destroy the HMC resources: %d\n",
ret_code);
}
ret_code = i40e_shutdown_adminq(&pf->hw);
if (ret_code)
dev_warn(&pdev->dev,
"Failed to destroy the Admin Queue resources: %d\n",
ret_code);
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
iounmap(pf->hw.hw_addr);
kfree(pf);
pci_release_selected_regions(pdev,
pci_select_bars(pdev, IORESOURCE_MEM));
pci_disable_pcie_error_reporting(pdev);
pci_disable_device(pdev);
}
static pci_ers_result_t i40e_pci_error_detected(struct pci_dev *pdev,
enum pci_channel_state error)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
dev_info(&pdev->dev, "%s: error %d\n", __func__, error);
if (!test_bit(__I40E_SUSPENDED, &pf->state)) {
rtnl_lock();
i40e_prep_for_reset(pf);
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
dev_info(&pdev->dev, "%s\n", __func__);
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
dev_info(&pdev->dev, "%s\n", __func__);
if (test_bit(__I40E_SUSPENDED, &pf->state))
return;
rtnl_lock();
i40e_handle_reset_warning(pf);
rtnl_lock();
}
static void i40e_shutdown(struct pci_dev *pdev)
{
struct i40e_pf *pf = pci_get_drvdata(pdev);
struct i40e_hw *hw = &pf->hw;
set_bit(__I40E_SUSPENDED, &pf->state);
set_bit(__I40E_DOWN, &pf->state);
rtnl_lock();
i40e_prep_for_reset(pf);
rtnl_unlock();
wr32(hw, I40E_PFPM_APM, (pf->wol_en ? I40E_PFPM_APM_APME_MASK : 0));
wr32(hw, I40E_PFPM_WUFC, (pf->wol_en ? I40E_PFPM_WUFC_MAG_MASK : 0));
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
set_bit(__I40E_SUSPENDED, &pf->state);
set_bit(__I40E_DOWN, &pf->state);
del_timer_sync(&pf->service_timer);
cancel_work_sync(&pf->service_task);
i40e_fdir_teardown(pf);
rtnl_lock();
i40e_prep_for_reset(pf);
rtnl_unlock();
wr32(hw, I40E_PFPM_APM, (pf->wol_en ? I40E_PFPM_APM_APME_MASK : 0));
wr32(hw, I40E_PFPM_WUFC, (pf->wol_en ? I40E_PFPM_WUFC_MAG_MASK : 0));
pci_wake_from_d3(pdev, pf->wol_en);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
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
dev_err(&pdev->dev,
"%s: Cannot enable PCI device from suspend\n",
__func__);
return err;
}
pci_set_master(pdev);
pci_wake_from_d3(pdev, false);
if (test_and_clear_bit(__I40E_SUSPENDED, &pf->state)) {
clear_bit(__I40E_DOWN, &pf->state);
rtnl_lock();
i40e_reset_and_rebuild(pf, false);
rtnl_unlock();
}
return 0;
}
static int __init i40e_init_module(void)
{
pr_info("%s: %s - version %s\n", i40e_driver_name,
i40e_driver_string, i40e_driver_version_str);
pr_info("%s: %s\n", i40e_driver_name, i40e_copyright);
i40e_dbg_init();
return pci_register_driver(&i40e_driver);
}
static void __exit i40e_exit_module(void)
{
pci_unregister_driver(&i40e_driver);
i40e_dbg_exit();
}
