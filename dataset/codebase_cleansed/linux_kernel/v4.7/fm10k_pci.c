u16 fm10k_read_pci_cfg_word(struct fm10k_hw *hw, u32 reg)
{
struct fm10k_intfc *interface = hw->back;
u16 value = 0;
if (FM10K_REMOVED(hw->hw_addr))
return ~value;
pci_read_config_word(interface->pdev, reg, &value);
if (value == 0xFFFF)
fm10k_write_flush(hw);
return value;
}
u32 fm10k_read_reg(struct fm10k_hw *hw, int reg)
{
u32 __iomem *hw_addr = ACCESS_ONCE(hw->hw_addr);
u32 value = 0;
if (FM10K_REMOVED(hw_addr))
return ~value;
value = readl(&hw_addr[reg]);
if (!(~value) && (!reg || !(~readl(hw_addr)))) {
struct fm10k_intfc *interface = hw->back;
struct net_device *netdev = interface->netdev;
hw->hw_addr = NULL;
netif_device_detach(netdev);
netdev_err(netdev, "PCIe link lost, device now detached\n");
}
return value;
}
static int fm10k_hw_ready(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
fm10k_write_flush(hw);
return FM10K_REMOVED(hw->hw_addr) ? -ENODEV : 0;
}
void fm10k_service_event_schedule(struct fm10k_intfc *interface)
{
if (!test_bit(__FM10K_SERVICE_DISABLE, &interface->state) &&
!test_and_set_bit(__FM10K_SERVICE_SCHED, &interface->state))
queue_work(fm10k_workqueue, &interface->service_task);
}
static void fm10k_service_event_complete(struct fm10k_intfc *interface)
{
WARN_ON(!test_bit(__FM10K_SERVICE_SCHED, &interface->state));
smp_mb__before_atomic();
clear_bit(__FM10K_SERVICE_SCHED, &interface->state);
}
static void fm10k_service_timer(unsigned long data)
{
struct fm10k_intfc *interface = (struct fm10k_intfc *)data;
mod_timer(&interface->service_timer, (HZ * 2) + jiffies);
fm10k_service_event_schedule(interface);
}
static void fm10k_detach_subtask(struct fm10k_intfc *interface)
{
struct net_device *netdev = interface->netdev;
if (netif_device_present(netdev) || interface->hw.hw_addr)
return;
rtnl_lock();
if (netif_running(netdev))
dev_close(netdev);
rtnl_unlock();
}
static void fm10k_reinit(struct fm10k_intfc *interface)
{
struct net_device *netdev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
int err;
WARN_ON(in_interrupt());
netif_trans_update(netdev);
while (test_and_set_bit(__FM10K_RESETTING, &interface->state))
usleep_range(1000, 2000);
rtnl_lock();
fm10k_iov_suspend(interface->pdev);
if (netif_running(netdev))
fm10k_close(netdev);
fm10k_mbx_free_irq(interface);
fm10k_clear_queueing_scheme(interface);
interface->last_reset = jiffies + (10 * HZ);
err = hw->mac.ops.reset_hw(hw);
if (err) {
dev_err(&interface->pdev->dev, "reset_hw failed: %d\n", err);
goto reinit_err;
}
err = hw->mac.ops.init_hw(hw);
if (err) {
dev_err(&interface->pdev->dev, "init_hw failed: %d\n", err);
goto reinit_err;
}
err = fm10k_init_queueing_scheme(interface);
if (err) {
dev_err(&interface->pdev->dev,
"init_queueing_scheme failed: %d\n", err);
goto reinit_err;
}
err = fm10k_mbx_request_irq(interface);
if (err)
goto err_mbx_irq;
err = fm10k_hw_ready(interface);
if (err)
goto err_open;
if (hw->mac.type == fm10k_mac_vf) {
if (is_valid_ether_addr(hw->mac.perm_addr)) {
ether_addr_copy(hw->mac.addr, hw->mac.perm_addr);
ether_addr_copy(netdev->perm_addr, hw->mac.perm_addr);
ether_addr_copy(netdev->dev_addr, hw->mac.perm_addr);
netdev->addr_assign_type &= ~NET_ADDR_RANDOM;
}
if (hw->mac.vlan_override)
netdev->features &= ~NETIF_F_HW_VLAN_CTAG_RX;
else
netdev->features |= NETIF_F_HW_VLAN_CTAG_RX;
}
err = netif_running(netdev) ? fm10k_open(netdev) : 0;
if (err)
goto err_open;
fm10k_iov_resume(interface->pdev);
rtnl_unlock();
clear_bit(__FM10K_RESETTING, &interface->state);
return;
err_open:
fm10k_mbx_free_irq(interface);
err_mbx_irq:
fm10k_clear_queueing_scheme(interface);
reinit_err:
netif_device_detach(netdev);
rtnl_unlock();
clear_bit(__FM10K_RESETTING, &interface->state);
}
static void fm10k_reset_subtask(struct fm10k_intfc *interface)
{
if (!(interface->flags & FM10K_FLAG_RESET_REQUESTED))
return;
interface->flags &= ~FM10K_FLAG_RESET_REQUESTED;
netdev_err(interface->netdev, "Reset interface\n");
fm10k_reinit(interface);
}
static void fm10k_configure_swpri_map(struct fm10k_intfc *interface)
{
struct net_device *netdev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
int i;
interface->flags &= ~FM10K_FLAG_SWPRI_CONFIG;
if (hw->mac.type != fm10k_mac_pf)
return;
for (i = 0; i < FM10K_SWPRI_MAX; i++)
fm10k_write_reg(hw, FM10K_SWPRI_MAP(i),
netdev_get_prio_tc_map(netdev, i));
}
static void fm10k_watchdog_update_host_state(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
s32 err;
if (test_bit(__FM10K_LINK_DOWN, &interface->state)) {
interface->host_ready = false;
if (time_is_after_jiffies(interface->link_down_event))
return;
clear_bit(__FM10K_LINK_DOWN, &interface->state);
}
if (interface->flags & FM10K_FLAG_SWPRI_CONFIG) {
if (rtnl_trylock()) {
fm10k_configure_swpri_map(interface);
rtnl_unlock();
}
}
fm10k_mbx_lock(interface);
err = hw->mac.ops.get_host_state(hw, &interface->host_ready);
if (err && time_is_before_jiffies(interface->last_reset))
interface->flags |= FM10K_FLAG_RESET_REQUESTED;
fm10k_mbx_unlock(interface);
}
static void fm10k_mbx_subtask(struct fm10k_intfc *interface)
{
fm10k_watchdog_update_host_state(interface);
fm10k_iov_mbx(interface);
}
static void fm10k_watchdog_host_is_ready(struct fm10k_intfc *interface)
{
struct net_device *netdev = interface->netdev;
if (netif_carrier_ok(netdev))
return;
netif_info(interface, drv, netdev, "NIC Link is up\n");
netif_carrier_on(netdev);
netif_tx_wake_all_queues(netdev);
}
static void fm10k_watchdog_host_not_ready(struct fm10k_intfc *interface)
{
struct net_device *netdev = interface->netdev;
if (!netif_carrier_ok(netdev))
return;
netif_info(interface, drv, netdev, "NIC Link is down\n");
netif_carrier_off(netdev);
netif_tx_stop_all_queues(netdev);
}
void fm10k_update_stats(struct fm10k_intfc *interface)
{
struct net_device_stats *net_stats = &interface->netdev->stats;
struct fm10k_hw *hw = &interface->hw;
u64 hw_csum_tx_good = 0, hw_csum_rx_good = 0, rx_length_errors = 0;
u64 rx_switch_errors = 0, rx_drops = 0, rx_pp_errors = 0;
u64 rx_link_errors = 0;
u64 rx_errors = 0, rx_csum_errors = 0, tx_csum_errors = 0;
u64 restart_queue = 0, tx_busy = 0, alloc_failed = 0;
u64 rx_bytes_nic = 0, rx_pkts_nic = 0, rx_drops_nic = 0;
u64 tx_bytes_nic = 0, tx_pkts_nic = 0;
u64 bytes, pkts;
int i;
interface->next_stats_update = jiffies + HZ;
for (bytes = 0, pkts = 0, i = 0; i < interface->num_tx_queues; i++) {
struct fm10k_ring *tx_ring = interface->tx_ring[i];
restart_queue += tx_ring->tx_stats.restart_queue;
tx_busy += tx_ring->tx_stats.tx_busy;
tx_csum_errors += tx_ring->tx_stats.csum_err;
bytes += tx_ring->stats.bytes;
pkts += tx_ring->stats.packets;
hw_csum_tx_good += tx_ring->tx_stats.csum_good;
}
interface->restart_queue = restart_queue;
interface->tx_busy = tx_busy;
net_stats->tx_bytes = bytes;
net_stats->tx_packets = pkts;
interface->tx_csum_errors = tx_csum_errors;
interface->hw_csum_tx_good = hw_csum_tx_good;
for (bytes = 0, pkts = 0, i = 0; i < interface->num_rx_queues; i++) {
struct fm10k_ring *rx_ring = interface->rx_ring[i];
bytes += rx_ring->stats.bytes;
pkts += rx_ring->stats.packets;
alloc_failed += rx_ring->rx_stats.alloc_failed;
rx_csum_errors += rx_ring->rx_stats.csum_err;
rx_errors += rx_ring->rx_stats.errors;
hw_csum_rx_good += rx_ring->rx_stats.csum_good;
rx_switch_errors += rx_ring->rx_stats.switch_errors;
rx_drops += rx_ring->rx_stats.drops;
rx_pp_errors += rx_ring->rx_stats.pp_errors;
rx_link_errors += rx_ring->rx_stats.link_errors;
rx_length_errors += rx_ring->rx_stats.length_errors;
}
net_stats->rx_bytes = bytes;
net_stats->rx_packets = pkts;
interface->alloc_failed = alloc_failed;
interface->rx_csum_errors = rx_csum_errors;
interface->hw_csum_rx_good = hw_csum_rx_good;
interface->rx_switch_errors = rx_switch_errors;
interface->rx_drops = rx_drops;
interface->rx_pp_errors = rx_pp_errors;
interface->rx_link_errors = rx_link_errors;
interface->rx_length_errors = rx_length_errors;
hw->mac.ops.update_hw_stats(hw, &interface->stats);
for (i = 0; i < hw->mac.max_queues; i++) {
struct fm10k_hw_stats_q *q = &interface->stats.q[i];
tx_bytes_nic += q->tx_bytes.count;
tx_pkts_nic += q->tx_packets.count;
rx_bytes_nic += q->rx_bytes.count;
rx_pkts_nic += q->rx_packets.count;
rx_drops_nic += q->rx_drops.count;
}
interface->tx_bytes_nic = tx_bytes_nic;
interface->tx_packets_nic = tx_pkts_nic;
interface->rx_bytes_nic = rx_bytes_nic;
interface->rx_packets_nic = rx_pkts_nic;
interface->rx_drops_nic = rx_drops_nic;
net_stats->rx_errors = rx_errors;
net_stats->rx_dropped = interface->stats.nodesc_drop.count;
}
static void fm10k_watchdog_flush_tx(struct fm10k_intfc *interface)
{
int some_tx_pending = 0;
int i;
if (netif_carrier_ok(interface->netdev))
return;
for (i = 0; i < interface->num_tx_queues; i++) {
struct fm10k_ring *tx_ring = interface->tx_ring[i];
if (tx_ring->next_to_use != tx_ring->next_to_clean) {
some_tx_pending = 1;
break;
}
}
if (some_tx_pending)
interface->flags |= FM10K_FLAG_RESET_REQUESTED;
}
static void fm10k_watchdog_subtask(struct fm10k_intfc *interface)
{
if (test_bit(__FM10K_DOWN, &interface->state) ||
test_bit(__FM10K_RESETTING, &interface->state))
return;
if (interface->host_ready)
fm10k_watchdog_host_is_ready(interface);
else
fm10k_watchdog_host_not_ready(interface);
if (time_is_before_jiffies(interface->next_stats_update))
fm10k_update_stats(interface);
fm10k_watchdog_flush_tx(interface);
}
static void fm10k_check_hang_subtask(struct fm10k_intfc *interface)
{
int i;
if (test_bit(__FM10K_DOWN, &interface->state) ||
test_bit(__FM10K_RESETTING, &interface->state))
return;
if (time_is_after_eq_jiffies(interface->next_tx_hang_check))
return;
interface->next_tx_hang_check = jiffies + (2 * HZ);
if (netif_carrier_ok(interface->netdev)) {
for (i = 0; i < interface->num_tx_queues; i++)
set_check_for_tx_hang(interface->tx_ring[i]);
for (i = 0; i < interface->num_q_vectors; i++) {
struct fm10k_q_vector *qv = interface->q_vector[i];
if (!qv->tx.count && !qv->rx.count)
continue;
writel(FM10K_ITR_ENABLE | FM10K_ITR_PENDING2, qv->itr);
}
}
}
static void fm10k_service_task(struct work_struct *work)
{
struct fm10k_intfc *interface;
interface = container_of(work, struct fm10k_intfc, service_task);
fm10k_mbx_subtask(interface);
fm10k_detach_subtask(interface);
fm10k_reset_subtask(interface);
fm10k_watchdog_subtask(interface);
fm10k_check_hang_subtask(interface);
fm10k_service_event_complete(interface);
}
static void fm10k_configure_tx_ring(struct fm10k_intfc *interface,
struct fm10k_ring *ring)
{
struct fm10k_hw *hw = &interface->hw;
u64 tdba = ring->dma;
u32 size = ring->count * sizeof(struct fm10k_tx_desc);
u32 txint = FM10K_INT_MAP_DISABLE;
u32 txdctl = BIT(FM10K_TXDCTL_MAX_TIME_SHIFT) | FM10K_TXDCTL_ENABLE;
u8 reg_idx = ring->reg_idx;
fm10k_write_reg(hw, FM10K_TXDCTL(reg_idx), 0);
fm10k_write_flush(hw);
fm10k_write_reg(hw, FM10K_TDBAL(reg_idx), tdba & DMA_BIT_MASK(32));
fm10k_write_reg(hw, FM10K_TDBAH(reg_idx), tdba >> 32);
fm10k_write_reg(hw, FM10K_TDLEN(reg_idx), size);
fm10k_write_reg(hw, FM10K_TDH(reg_idx), 0);
fm10k_write_reg(hw, FM10K_TDT(reg_idx), 0);
ring->tail = &interface->uc_addr[FM10K_TDT(reg_idx)];
ring->next_to_clean = 0;
ring->next_to_use = 0;
if (ring->q_vector) {
txint = ring->q_vector->v_idx + NON_Q_VECTORS(hw);
txint |= FM10K_INT_MAP_TIMER0;
}
fm10k_write_reg(hw, FM10K_TXINT(reg_idx), txint);
fm10k_write_reg(hw, FM10K_PFVTCTL(reg_idx),
FM10K_PFVTCTL_FTAG_DESC_ENABLE);
if (!test_and_set_bit(__FM10K_TX_XPS_INIT_DONE, &ring->state) &&
ring->q_vector)
netif_set_xps_queue(ring->netdev,
&ring->q_vector->affinity_mask,
ring->queue_index);
fm10k_write_reg(hw, FM10K_TXDCTL(reg_idx), txdctl);
}
static void fm10k_enable_tx_ring(struct fm10k_intfc *interface,
struct fm10k_ring *ring)
{
struct fm10k_hw *hw = &interface->hw;
int wait_loop = 10;
u32 txdctl;
u8 reg_idx = ring->reg_idx;
if (fm10k_read_reg(hw, FM10K_TXDCTL(reg_idx)) & FM10K_TXDCTL_ENABLE)
return;
do {
usleep_range(1000, 2000);
txdctl = fm10k_read_reg(hw, FM10K_TXDCTL(reg_idx));
} while (!(txdctl & FM10K_TXDCTL_ENABLE) && --wait_loop);
if (!wait_loop)
netif_err(interface, drv, interface->netdev,
"Could not enable Tx Queue %d\n", reg_idx);
}
static void fm10k_configure_tx(struct fm10k_intfc *interface)
{
int i;
for (i = 0; i < interface->num_tx_queues; i++)
fm10k_configure_tx_ring(interface, interface->tx_ring[i]);
for (i = 0; i < interface->num_tx_queues; i++)
fm10k_enable_tx_ring(interface, interface->tx_ring[i]);
}
static void fm10k_configure_rx_ring(struct fm10k_intfc *interface,
struct fm10k_ring *ring)
{
u64 rdba = ring->dma;
struct fm10k_hw *hw = &interface->hw;
u32 size = ring->count * sizeof(union fm10k_rx_desc);
u32 rxqctl = FM10K_RXQCTL_ENABLE | FM10K_RXQCTL_PF;
u32 rxdctl = FM10K_RXDCTL_WRITE_BACK_MIN_DELAY;
u32 srrctl = FM10K_SRRCTL_BUFFER_CHAINING_EN;
u32 rxint = FM10K_INT_MAP_DISABLE;
u8 rx_pause = interface->rx_pause;
u8 reg_idx = ring->reg_idx;
fm10k_write_reg(hw, FM10K_RXQCTL(reg_idx), 0);
fm10k_write_flush(hw);
fm10k_write_reg(hw, FM10K_RDBAL(reg_idx), rdba & DMA_BIT_MASK(32));
fm10k_write_reg(hw, FM10K_RDBAH(reg_idx), rdba >> 32);
fm10k_write_reg(hw, FM10K_RDLEN(reg_idx), size);
fm10k_write_reg(hw, FM10K_RDH(reg_idx), 0);
fm10k_write_reg(hw, FM10K_RDT(reg_idx), 0);
ring->tail = &interface->uc_addr[FM10K_RDT(reg_idx)];
ring->next_to_clean = 0;
ring->next_to_use = 0;
ring->next_to_alloc = 0;
srrctl |= FM10K_RX_BUFSZ >> FM10K_SRRCTL_BSIZEPKT_SHIFT;
srrctl |= FM10K_SRRCTL_LOOPBACK_SUPPRESS;
fm10k_write_reg(hw, FM10K_SRRCTL(reg_idx), srrctl);
#ifdef CONFIG_DCB
if (interface->pfc_en)
rx_pause = interface->pfc_en;
#endif
if (!(rx_pause & BIT(ring->qos_pc)))
rxdctl |= FM10K_RXDCTL_DROP_ON_EMPTY;
fm10k_write_reg(hw, FM10K_RXDCTL(reg_idx), rxdctl);
ring->vid = hw->mac.default_vid;
if (test_bit(hw->mac.default_vid, interface->active_vlans))
ring->vid |= FM10K_VLAN_CLEAR;
if (ring->q_vector) {
rxint = ring->q_vector->v_idx + NON_Q_VECTORS(hw);
rxint |= FM10K_INT_MAP_TIMER1;
}
fm10k_write_reg(hw, FM10K_RXINT(reg_idx), rxint);
fm10k_write_reg(hw, FM10K_RXQCTL(reg_idx), rxqctl);
fm10k_alloc_rx_buffers(ring, fm10k_desc_unused(ring));
}
void fm10k_update_rx_drop_en(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
u8 rx_pause = interface->rx_pause;
int i;
#ifdef CONFIG_DCB
if (interface->pfc_en)
rx_pause = interface->pfc_en;
#endif
for (i = 0; i < interface->num_rx_queues; i++) {
struct fm10k_ring *ring = interface->rx_ring[i];
u32 rxdctl = FM10K_RXDCTL_WRITE_BACK_MIN_DELAY;
u8 reg_idx = ring->reg_idx;
if (!(rx_pause & BIT(ring->qos_pc)))
rxdctl |= FM10K_RXDCTL_DROP_ON_EMPTY;
fm10k_write_reg(hw, FM10K_RXDCTL(reg_idx), rxdctl);
}
}
static void fm10k_configure_dglort(struct fm10k_intfc *interface)
{
struct fm10k_dglort_cfg dglort = { 0 };
struct fm10k_hw *hw = &interface->hw;
int i;
u32 mrqc;
for (i = 0; i < FM10K_RSSRK_SIZE; i++)
fm10k_write_reg(hw, FM10K_RSSRK(0, i), interface->rssrk[i]);
for (i = 0; i < FM10K_RETA_SIZE; i++)
fm10k_write_reg(hw, FM10K_RETA(0, i), interface->reta[i]);
mrqc = FM10K_MRQC_IPV4 |
FM10K_MRQC_TCP_IPV4 |
FM10K_MRQC_IPV6 |
FM10K_MRQC_TCP_IPV6;
if (interface->flags & FM10K_FLAG_RSS_FIELD_IPV4_UDP)
mrqc |= FM10K_MRQC_UDP_IPV4;
if (interface->flags & FM10K_FLAG_RSS_FIELD_IPV6_UDP)
mrqc |= FM10K_MRQC_UDP_IPV6;
fm10k_write_reg(hw, FM10K_MRQC(0), mrqc);
dglort.inner_rss = 1;
dglort.rss_l = fls(interface->ring_feature[RING_F_RSS].mask);
dglort.pc_l = fls(interface->ring_feature[RING_F_QOS].mask);
hw->mac.ops.configure_dglort_map(hw, &dglort);
if (interface->glort_count > 64) {
memset(&dglort, 0, sizeof(dglort));
dglort.inner_rss = 1;
dglort.glort = interface->glort + 64;
dglort.idx = fm10k_dglort_pf_queue;
dglort.queue_l = fls(interface->num_rx_queues - 1);
hw->mac.ops.configure_dglort_map(hw, &dglort);
}
memset(&dglort, 0, sizeof(dglort));
dglort.inner_rss = 1;
dglort.glort = interface->glort;
dglort.rss_l = fls(interface->ring_feature[RING_F_RSS].mask);
dglort.pc_l = fls(interface->ring_feature[RING_F_QOS].mask);
dglort.idx = fm10k_dglort_pf_rss;
if (interface->l2_accel)
dglort.shared_l = fls(interface->l2_accel->size);
hw->mac.ops.configure_dglort_map(hw, &dglort);
}
static void fm10k_configure_rx(struct fm10k_intfc *interface)
{
int i;
fm10k_configure_swpri_map(interface);
fm10k_configure_dglort(interface);
for (i = 0; i < interface->num_rx_queues; i++)
fm10k_configure_rx_ring(interface, interface->rx_ring[i]);
}
static void fm10k_napi_enable_all(struct fm10k_intfc *interface)
{
struct fm10k_q_vector *q_vector;
int q_idx;
for (q_idx = 0; q_idx < interface->num_q_vectors; q_idx++) {
q_vector = interface->q_vector[q_idx];
napi_enable(&q_vector->napi);
}
}
static irqreturn_t fm10k_msix_clean_rings(int __always_unused irq, void *data)
{
struct fm10k_q_vector *q_vector = data;
if (q_vector->rx.count || q_vector->tx.count)
napi_schedule_irqoff(&q_vector->napi);
return IRQ_HANDLED;
}
static irqreturn_t fm10k_msix_mbx_vf(int __always_unused irq, void *data)
{
struct fm10k_intfc *interface = data;
struct fm10k_hw *hw = &interface->hw;
struct fm10k_mbx_info *mbx = &hw->mbx;
fm10k_write_reg(hw, FM10K_VFITR(FM10K_MBX_VECTOR),
(FM10K_MBX_INT_DELAY >> hw->mac.itr_scale) |
FM10K_ITR_ENABLE);
if (fm10k_mbx_trylock(interface)) {
mbx->ops.process(hw, mbx);
fm10k_mbx_unlock(interface);
}
hw->mac.get_host_state = true;
fm10k_service_event_schedule(interface);
return IRQ_HANDLED;
}
void fm10k_netpoll(struct net_device *netdev)
{
struct fm10k_intfc *interface = netdev_priv(netdev);
int i;
if (test_bit(__FM10K_DOWN, &interface->state))
return;
for (i = 0; i < interface->num_q_vectors; i++)
fm10k_msix_clean_rings(0, interface->q_vector[i]);
}
static void fm10k_handle_fault(struct fm10k_intfc *interface, int type,
struct fm10k_fault *fault)
{
struct pci_dev *pdev = interface->pdev;
struct fm10k_hw *hw = &interface->hw;
struct fm10k_iov_data *iov_data = interface->iov_data;
char *error;
switch (type) {
case FM10K_PCA_FAULT:
switch (fault->type) {
default:
error = "Unknown PCA error";
break;
FM10K_ERR_MSG(PCA_NO_FAULT);
FM10K_ERR_MSG(PCA_UNMAPPED_ADDR);
FM10K_ERR_MSG(PCA_BAD_QACCESS_PF);
FM10K_ERR_MSG(PCA_BAD_QACCESS_VF);
FM10K_ERR_MSG(PCA_MALICIOUS_REQ);
FM10K_ERR_MSG(PCA_POISONED_TLP);
FM10K_ERR_MSG(PCA_TLP_ABORT);
}
break;
case FM10K_THI_FAULT:
switch (fault->type) {
default:
error = "Unknown THI error";
break;
FM10K_ERR_MSG(THI_NO_FAULT);
FM10K_ERR_MSG(THI_MAL_DIS_Q_FAULT);
}
break;
case FM10K_FUM_FAULT:
switch (fault->type) {
default:
error = "Unknown FUM error";
break;
FM10K_ERR_MSG(FUM_NO_FAULT);
FM10K_ERR_MSG(FUM_UNMAPPED_ADDR);
FM10K_ERR_MSG(FUM_BAD_VF_QACCESS);
FM10K_ERR_MSG(FUM_ADD_DECODE_ERR);
FM10K_ERR_MSG(FUM_RO_ERROR);
FM10K_ERR_MSG(FUM_QPRC_CRC_ERROR);
FM10K_ERR_MSG(FUM_CSR_TIMEOUT);
FM10K_ERR_MSG(FUM_INVALID_TYPE);
FM10K_ERR_MSG(FUM_INVALID_LENGTH);
FM10K_ERR_MSG(FUM_INVALID_BE);
FM10K_ERR_MSG(FUM_INVALID_ALIGN);
}
break;
default:
error = "Undocumented fault";
break;
}
dev_warn(&pdev->dev,
"%s Address: 0x%llx SpecInfo: 0x%x Func: %02x.%0x\n",
error, fault->address, fault->specinfo,
PCI_SLOT(fault->func), PCI_FUNC(fault->func));
if (fault->func && iov_data) {
int vf = fault->func - 1;
struct fm10k_vf_info *vf_info = &iov_data->vf_info[vf];
hw->iov.ops.reset_lport(hw, vf_info);
hw->iov.ops.reset_resources(hw, vf_info);
hw->iov.ops.set_lport(hw, vf_info, vf,
FM10K_VF_FLAG_MULTI_CAPABLE);
vf_info->mbx.ops.connect(hw, &vf_info->mbx);
}
}
static void fm10k_report_fault(struct fm10k_intfc *interface, u32 eicr)
{
struct fm10k_hw *hw = &interface->hw;
struct fm10k_fault fault = { 0 };
int type, err;
for (eicr &= FM10K_EICR_FAULT_MASK, type = FM10K_PCA_FAULT;
eicr;
eicr >>= 1, type += FM10K_FAULT_SIZE) {
if (!(eicr & 0x1))
continue;
err = hw->mac.ops.get_fault(hw, type, &fault);
if (err) {
dev_err(&interface->pdev->dev,
"error reading fault\n");
continue;
}
fm10k_handle_fault(interface, type, &fault);
}
}
static void fm10k_reset_drop_on_empty(struct fm10k_intfc *interface, u32 eicr)
{
struct fm10k_hw *hw = &interface->hw;
const u32 rxdctl = FM10K_RXDCTL_WRITE_BACK_MIN_DELAY;
u32 maxholdq;
int q;
if (!(eicr & FM10K_EICR_MAXHOLDTIME))
return;
maxholdq = fm10k_read_reg(hw, FM10K_MAXHOLDQ(7));
if (maxholdq)
fm10k_write_reg(hw, FM10K_MAXHOLDQ(7), maxholdq);
for (q = 255;;) {
if (maxholdq & BIT(31)) {
if (q < FM10K_MAX_QUEUES_PF) {
interface->rx_overrun_pf++;
fm10k_write_reg(hw, FM10K_RXDCTL(q), rxdctl);
} else {
interface->rx_overrun_vf++;
}
}
maxholdq *= 2;
if (!maxholdq)
q &= ~(32 - 1);
if (!q)
break;
if (q-- % 32)
continue;
maxholdq = fm10k_read_reg(hw, FM10K_MAXHOLDQ(q / 32));
if (maxholdq)
fm10k_write_reg(hw, FM10K_MAXHOLDQ(q / 32), maxholdq);
}
}
static irqreturn_t fm10k_msix_mbx_pf(int __always_unused irq, void *data)
{
struct fm10k_intfc *interface = data;
struct fm10k_hw *hw = &interface->hw;
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 eicr;
eicr = fm10k_read_reg(hw, FM10K_EICR);
fm10k_write_reg(hw, FM10K_EICR, eicr & (FM10K_EICR_MAILBOX |
FM10K_EICR_SWITCHREADY |
FM10K_EICR_SWITCHNOTREADY));
fm10k_report_fault(interface, eicr);
fm10k_reset_drop_on_empty(interface, eicr);
if (fm10k_mbx_trylock(interface)) {
mbx->ops.process(hw, mbx);
fm10k_iov_event(interface);
fm10k_mbx_unlock(interface);
}
if (eicr & FM10K_EICR_SWITCHNOTREADY) {
interface->link_down_event = jiffies + (4 * HZ);
set_bit(__FM10K_LINK_DOWN, &interface->state);
hw->mac.dglort_map = FM10K_DGLORTMAP_NONE;
}
hw->mac.get_host_state = true;
fm10k_service_event_schedule(interface);
fm10k_write_reg(hw, FM10K_ITR(FM10K_MBX_VECTOR),
(FM10K_MBX_INT_DELAY >> hw->mac.itr_scale) |
FM10K_ITR_ENABLE);
return IRQ_HANDLED;
}
void fm10k_mbx_free_irq(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
struct msix_entry *entry;
int itr_reg;
if (!interface->msix_entries)
return;
entry = &interface->msix_entries[FM10K_MBX_VECTOR];
hw->mbx.ops.disconnect(hw, &hw->mbx);
if (hw->mac.type == fm10k_mac_pf) {
fm10k_write_reg(hw, FM10K_EIMR,
FM10K_EIMR_DISABLE(PCA_FAULT) |
FM10K_EIMR_DISABLE(FUM_FAULT) |
FM10K_EIMR_DISABLE(MAILBOX) |
FM10K_EIMR_DISABLE(SWITCHREADY) |
FM10K_EIMR_DISABLE(SWITCHNOTREADY) |
FM10K_EIMR_DISABLE(SRAMERROR) |
FM10K_EIMR_DISABLE(VFLR) |
FM10K_EIMR_DISABLE(MAXHOLDTIME));
itr_reg = FM10K_ITR(FM10K_MBX_VECTOR);
} else {
itr_reg = FM10K_VFITR(FM10K_MBX_VECTOR);
}
fm10k_write_reg(hw, itr_reg, FM10K_ITR_MASK_SET);
free_irq(entry->vector, interface);
}
static s32 fm10k_mbx_mac_addr(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
bool vlan_override = hw->mac.vlan_override;
u16 default_vid = hw->mac.default_vid;
struct fm10k_intfc *interface;
s32 err;
err = fm10k_msg_mac_vlan_vf(hw, results, mbx);
if (err)
return err;
interface = container_of(hw, struct fm10k_intfc, hw);
if (is_valid_ether_addr(hw->mac.perm_addr) &&
!ether_addr_equal(hw->mac.perm_addr, hw->mac.addr))
interface->flags |= FM10K_FLAG_RESET_REQUESTED;
if ((vlan_override != hw->mac.vlan_override) ||
(default_vid != hw->mac.default_vid))
interface->flags |= FM10K_FLAG_RESET_REQUESTED;
return 0;
}
static s32 fm10k_mbx_error(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info __always_unused *mbx)
{
struct fm10k_intfc *interface;
struct pci_dev *pdev;
interface = container_of(hw, struct fm10k_intfc, hw);
pdev = interface->pdev;
dev_err(&pdev->dev, "Unknown message ID %u\n",
**results & FM10K_TLV_ID_MASK);
return 0;
}
static int fm10k_mbx_request_irq_vf(struct fm10k_intfc *interface)
{
struct msix_entry *entry = &interface->msix_entries[FM10K_MBX_VECTOR];
struct net_device *dev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
int err;
u32 itr = entry->entry | FM10K_INT_MAP_TIMER0;
err = hw->mbx.ops.register_handlers(&hw->mbx, vf_mbx_data);
if (err)
return err;
err = request_irq(entry->vector, fm10k_msix_mbx_vf, 0,
dev->name, interface);
if (err) {
netif_err(interface, probe, dev,
"request_irq for msix_mbx failed: %d\n", err);
return err;
}
fm10k_write_reg(hw, FM10K_VFINT_MAP, itr);
fm10k_write_reg(hw, FM10K_VFITR(entry->entry), FM10K_ITR_ENABLE);
return 0;
}
static s32 fm10k_lport_map(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
struct fm10k_intfc *interface;
u32 dglort_map = hw->mac.dglort_map;
s32 err;
interface = container_of(hw, struct fm10k_intfc, hw);
err = fm10k_msg_err_pf(hw, results, mbx);
if (!err && hw->swapi.status) {
interface->link_down_event = jiffies + (2 * HZ);
set_bit(__FM10K_LINK_DOWN, &interface->state);
hw->mac.dglort_map = FM10K_DGLORTMAP_NONE;
fm10k_service_event_schedule(interface);
if (interface->lport_map_failed)
return 0;
interface->lport_map_failed = true;
if (hw->swapi.status == FM10K_MSG_ERR_PEP_NOT_SCHEDULED)
dev_warn(&interface->pdev->dev,
"cannot obtain link because the host interface is configured for a PCIe host interface bandwidth of zero\n");
dev_warn(&interface->pdev->dev,
"request logical port map failed: %d\n",
hw->swapi.status);
return 0;
}
err = fm10k_msg_lport_map_pf(hw, results, mbx);
if (err)
return err;
interface->lport_map_failed = false;
if (dglort_map != hw->mac.dglort_map)
interface->flags |= FM10K_FLAG_RESET_REQUESTED;
return 0;
}
static s32 fm10k_update_pvid(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info __always_unused *mbx)
{
struct fm10k_intfc *interface;
u16 glort, pvid;
u32 pvid_update;
s32 err;
err = fm10k_tlv_attr_get_u32(results[FM10K_PF_ATTR_ID_UPDATE_PVID],
&pvid_update);
if (err)
return err;
glort = FM10K_MSG_HDR_FIELD_GET(pvid_update, UPDATE_PVID_GLORT);
pvid = FM10K_MSG_HDR_FIELD_GET(pvid_update, UPDATE_PVID_PVID);
if (!fm10k_glort_valid_pf(hw, glort))
return FM10K_ERR_PARAM;
if (pvid >= FM10K_VLAN_TABLE_VID_MAX)
return FM10K_ERR_PARAM;
interface = container_of(hw, struct fm10k_intfc, hw);
err = fm10k_iov_update_pvid(interface, glort, pvid);
if (!err)
return 0;
if (pvid != hw->mac.default_vid)
interface->flags |= FM10K_FLAG_RESET_REQUESTED;
hw->mac.default_vid = pvid;
return 0;
}
static int fm10k_mbx_request_irq_pf(struct fm10k_intfc *interface)
{
struct msix_entry *entry = &interface->msix_entries[FM10K_MBX_VECTOR];
struct net_device *dev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
int err;
u32 mbx_itr = entry->entry | FM10K_INT_MAP_TIMER0;
u32 other_itr = entry->entry | FM10K_INT_MAP_IMMEDIATE;
err = hw->mbx.ops.register_handlers(&hw->mbx, pf_mbx_data);
if (err)
return err;
err = request_irq(entry->vector, fm10k_msix_mbx_pf, 0,
dev->name, interface);
if (err) {
netif_err(interface, probe, dev,
"request_irq for msix_mbx failed: %d\n", err);
return err;
}
fm10k_write_reg(hw, FM10K_INT_MAP(fm10k_int_pcie_fault), other_itr);
fm10k_write_reg(hw, FM10K_INT_MAP(fm10k_int_switch_up_down), other_itr);
fm10k_write_reg(hw, FM10K_INT_MAP(fm10k_int_sram), other_itr);
fm10k_write_reg(hw, FM10K_INT_MAP(fm10k_int_max_hold_time), other_itr);
fm10k_write_reg(hw, FM10K_INT_MAP(fm10k_int_vflr), other_itr);
fm10k_write_reg(hw, FM10K_INT_MAP(fm10k_int_mailbox), mbx_itr);
fm10k_write_reg(hw, FM10K_EIMR, FM10K_EIMR_ENABLE(PCA_FAULT) |
FM10K_EIMR_ENABLE(FUM_FAULT) |
FM10K_EIMR_ENABLE(MAILBOX) |
FM10K_EIMR_ENABLE(SWITCHREADY) |
FM10K_EIMR_ENABLE(SWITCHNOTREADY) |
FM10K_EIMR_ENABLE(SRAMERROR) |
FM10K_EIMR_ENABLE(VFLR) |
FM10K_EIMR_ENABLE(MAXHOLDTIME));
fm10k_write_reg(hw, FM10K_ITR(entry->entry), FM10K_ITR_ENABLE);
return 0;
}
int fm10k_mbx_request_irq(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
int err;
if (hw->mac.type == fm10k_mac_pf)
err = fm10k_mbx_request_irq_pf(interface);
else
err = fm10k_mbx_request_irq_vf(interface);
if (err)
return err;
err = hw->mbx.ops.connect(hw, &hw->mbx);
if (err)
fm10k_mbx_free_irq(interface);
return err;
}
void fm10k_qv_free_irq(struct fm10k_intfc *interface)
{
int vector = interface->num_q_vectors;
struct fm10k_hw *hw = &interface->hw;
struct msix_entry *entry;
entry = &interface->msix_entries[NON_Q_VECTORS(hw) + vector];
while (vector) {
struct fm10k_q_vector *q_vector;
vector--;
entry--;
q_vector = interface->q_vector[vector];
if (!q_vector->tx.count && !q_vector->rx.count)
continue;
irq_set_affinity_hint(entry->vector, NULL);
writel(FM10K_ITR_MASK_SET, q_vector->itr);
free_irq(entry->vector, q_vector);
}
}
int fm10k_qv_request_irq(struct fm10k_intfc *interface)
{
struct net_device *dev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
struct msix_entry *entry;
int ri = 0, ti = 0;
int vector, err;
entry = &interface->msix_entries[NON_Q_VECTORS(hw)];
for (vector = 0; vector < interface->num_q_vectors; vector++) {
struct fm10k_q_vector *q_vector = interface->q_vector[vector];
if (q_vector->tx.count && q_vector->rx.count) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-TxRx-%d", dev->name, ri++);
ti++;
} else if (q_vector->rx.count) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-rx-%d", dev->name, ri++);
} else if (q_vector->tx.count) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-tx-%d", dev->name, ti++);
} else {
continue;
}
q_vector->itr = (hw->mac.type == fm10k_mac_pf) ?
&interface->uc_addr[FM10K_ITR(entry->entry)] :
&interface->uc_addr[FM10K_VFITR(entry->entry)];
err = request_irq(entry->vector, &fm10k_msix_clean_rings, 0,
q_vector->name, q_vector);
if (err) {
netif_err(interface, probe, dev,
"request_irq failed for MSIX interrupt Error: %d\n",
err);
goto err_out;
}
irq_set_affinity_hint(entry->vector, &q_vector->affinity_mask);
writel(FM10K_ITR_ENABLE, q_vector->itr);
entry++;
}
return 0;
err_out:
while (vector) {
struct fm10k_q_vector *q_vector;
entry--;
vector--;
q_vector = interface->q_vector[vector];
if (!q_vector->tx.count && !q_vector->rx.count)
continue;
irq_set_affinity_hint(entry->vector, NULL);
writel(FM10K_ITR_MASK_SET, q_vector->itr);
free_irq(entry->vector, q_vector);
}
return err;
}
void fm10k_up(struct fm10k_intfc *interface)
{
struct fm10k_hw *hw = &interface->hw;
hw->mac.ops.start_hw(hw);
fm10k_configure_tx(interface);
fm10k_configure_rx(interface);
hw->mac.ops.update_int_moderator(hw);
clear_bit(__FM10K_DOWN, &interface->state);
fm10k_napi_enable_all(interface);
fm10k_restore_rx_state(interface);
netif_tx_start_all_queues(interface->netdev);
hw->mac.get_host_state = true;
mod_timer(&interface->service_timer, jiffies);
}
static void fm10k_napi_disable_all(struct fm10k_intfc *interface)
{
struct fm10k_q_vector *q_vector;
int q_idx;
for (q_idx = 0; q_idx < interface->num_q_vectors; q_idx++) {
q_vector = interface->q_vector[q_idx];
napi_disable(&q_vector->napi);
}
}
void fm10k_down(struct fm10k_intfc *interface)
{
struct net_device *netdev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
int err;
set_bit(__FM10K_DOWN, &interface->state);
netif_carrier_off(netdev);
netif_tx_stop_all_queues(netdev);
netif_tx_disable(netdev);
fm10k_reset_rx_state(interface);
usleep_range(10000, 20000);
fm10k_napi_disable_all(interface);
fm10k_update_stats(interface);
err = hw->mac.ops.stop_hw(hw);
if (err)
dev_err(&interface->pdev->dev, "stop_hw failed: %d\n", err);
fm10k_clean_all_tx_rings(interface);
fm10k_clean_all_rx_rings(interface);
}
static int fm10k_sw_init(struct fm10k_intfc *interface,
const struct pci_device_id *ent)
{
const struct fm10k_info *fi = fm10k_info_tbl[ent->driver_data];
struct fm10k_hw *hw = &interface->hw;
struct pci_dev *pdev = interface->pdev;
struct net_device *netdev = interface->netdev;
u32 rss_key[FM10K_RSSRK_SIZE];
unsigned int rss;
int err;
hw->back = interface;
hw->hw_addr = interface->uc_addr;
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
hw->revision_id = pdev->revision;
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
memcpy(&hw->mac.ops, fi->mac_ops, sizeof(hw->mac.ops));
hw->mac.type = fi->mac;
if (fi->iov_ops)
memcpy(&hw->iov.ops, fi->iov_ops, sizeof(hw->iov.ops));
rss = min_t(int, FM10K_MAX_RSS_INDICES, num_online_cpus());
interface->ring_feature[RING_F_RSS].limit = rss;
fi->get_invariants(hw);
if (hw->mac.ops.get_bus_info)
hw->mac.ops.get_bus_info(hw);
if (hw->mac.ops.set_dma_mask)
hw->mac.ops.set_dma_mask(hw, dma_get_mask(&pdev->dev));
if (dma_get_mask(&pdev->dev) > DMA_BIT_MASK(32)) {
netdev->features |= NETIF_F_HIGHDMA;
netdev->vlan_features |= NETIF_F_HIGHDMA;
}
interface->last_reset = jiffies + (10 * HZ);
err = hw->mac.ops.reset_hw(hw);
if (err) {
dev_err(&pdev->dev, "reset_hw failed: %d\n", err);
return err;
}
err = hw->mac.ops.init_hw(hw);
if (err) {
dev_err(&pdev->dev, "init_hw failed: %d\n", err);
return err;
}
hw->mac.ops.update_hw_stats(hw, &interface->stats);
pci_sriov_set_totalvfs(pdev, hw->iov.total_vfs);
eth_random_addr(hw->mac.addr);
err = hw->mac.ops.read_mac_addr(hw);
if (err) {
dev_warn(&pdev->dev,
"Failed to obtain MAC address defaulting to random\n");
netdev->addr_assign_type |= NET_ADDR_RANDOM;
}
ether_addr_copy(netdev->dev_addr, hw->mac.addr);
ether_addr_copy(netdev->perm_addr, hw->mac.addr);
if (!is_valid_ether_addr(netdev->perm_addr)) {
dev_err(&pdev->dev, "Invalid MAC Address\n");
return -EIO;
}
fm10k_dcbnl_set_ops(netdev);
interface->tx_ring_count = FM10K_DEFAULT_TXD;
interface->rx_ring_count = FM10K_DEFAULT_RXD;
interface->tx_itr = FM10K_TX_ITR_DEFAULT;
interface->rx_itr = FM10K_ITR_ADAPTIVE | FM10K_RX_ITR_DEFAULT;
INIT_LIST_HEAD(&interface->vxlan_port);
netdev_rss_key_fill(rss_key, sizeof(rss_key));
memcpy(interface->rssrk, rss_key, sizeof(rss_key));
set_bit(__FM10K_DOWN, &interface->state);
return 0;
}
static void fm10k_slot_warn(struct fm10k_intfc *interface)
{
enum pcie_link_width width = PCIE_LNK_WIDTH_UNKNOWN;
enum pci_bus_speed speed = PCI_SPEED_UNKNOWN;
struct fm10k_hw *hw = &interface->hw;
int max_gts = 0, expected_gts = 0;
if (pcie_get_minimum_link(interface->pdev, &speed, &width) ||
speed == PCI_SPEED_UNKNOWN || width == PCIE_LNK_WIDTH_UNKNOWN) {
dev_warn(&interface->pdev->dev,
"Unable to determine PCI Express bandwidth.\n");
return;
}
switch (speed) {
case PCIE_SPEED_2_5GT:
max_gts = 2 * width;
break;
case PCIE_SPEED_5_0GT:
max_gts = 4 * width;
break;
case PCIE_SPEED_8_0GT:
max_gts = 8 * width;
break;
default:
dev_warn(&interface->pdev->dev,
"Unable to determine PCI Express bandwidth.\n");
return;
}
dev_info(&interface->pdev->dev,
"PCI Express bandwidth of %dGT/s available\n",
max_gts);
dev_info(&interface->pdev->dev,
"(Speed:%s, Width: x%d, Encoding Loss:%s, Payload:%s)\n",
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" :
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" :
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" :
"Unknown"),
hw->bus.width,
(speed == PCIE_SPEED_2_5GT ? "20%" :
speed == PCIE_SPEED_5_0GT ? "20%" :
speed == PCIE_SPEED_8_0GT ? "<2%" :
"Unknown"),
(hw->bus.payload == fm10k_bus_payload_128 ? "128B" :
hw->bus.payload == fm10k_bus_payload_256 ? "256B" :
hw->bus.payload == fm10k_bus_payload_512 ? "512B" :
"Unknown"));
switch (hw->bus_caps.speed) {
case fm10k_bus_speed_2500:
expected_gts = 2 * hw->bus_caps.width;
break;
case fm10k_bus_speed_5000:
expected_gts = 4 * hw->bus_caps.width;
break;
case fm10k_bus_speed_8000:
expected_gts = 8 * hw->bus_caps.width;
break;
default:
dev_warn(&interface->pdev->dev,
"Unable to determine expected PCI Express bandwidth.\n");
return;
}
if (max_gts >= expected_gts)
return;
dev_warn(&interface->pdev->dev,
"This device requires %dGT/s of bandwidth for optimal performance.\n",
expected_gts);
dev_warn(&interface->pdev->dev,
"A %sslot with x%d lanes is suggested.\n",
(hw->bus_caps.speed == fm10k_bus_speed_2500 ? "2.5GT/s " :
hw->bus_caps.speed == fm10k_bus_speed_5000 ? "5.0GT/s " :
hw->bus_caps.speed == fm10k_bus_speed_8000 ? "8.0GT/s " : ""),
hw->bus_caps.width);
}
static int fm10k_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev;
struct fm10k_intfc *interface;
int err;
err = pci_enable_device_mem(pdev);
if (err)
return err;
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(48));
if (err)
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev,
"DMA configuration failed: %d\n", err);
goto err_dma;
}
err = pci_request_selected_regions(pdev,
pci_select_bars(pdev,
IORESOURCE_MEM),
fm10k_driver_name);
if (err) {
dev_err(&pdev->dev,
"pci_request_selected_regions failed: %d\n", err);
goto err_pci_reg;
}
pci_enable_pcie_error_reporting(pdev);
pci_set_master(pdev);
pci_save_state(pdev);
netdev = fm10k_alloc_netdev(fm10k_info_tbl[ent->driver_data]);
if (!netdev) {
err = -ENOMEM;
goto err_alloc_netdev;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
interface = netdev_priv(netdev);
pci_set_drvdata(pdev, interface);
interface->netdev = netdev;
interface->pdev = pdev;
interface->uc_addr = ioremap(pci_resource_start(pdev, 0),
FM10K_UC_ADDR_SIZE);
if (!interface->uc_addr) {
err = -EIO;
goto err_ioremap;
}
err = fm10k_sw_init(interface, ent);
if (err)
goto err_sw_init;
fm10k_dbg_intfc_init(interface);
err = fm10k_init_queueing_scheme(interface);
if (err)
goto err_sw_init;
set_bit(__FM10K_SERVICE_DISABLE, &interface->state);
err = fm10k_mbx_request_irq(interface);
if (err)
goto err_mbx_interrupt;
err = fm10k_hw_ready(interface);
if (err)
goto err_register;
err = register_netdev(netdev);
if (err)
goto err_register;
netif_carrier_off(netdev);
netif_tx_stop_all_queues(netdev);
setup_timer(&interface->service_timer, &fm10k_service_timer,
(unsigned long)interface);
INIT_WORK(&interface->service_task, fm10k_service_task);
mod_timer(&interface->service_timer, (HZ * 2) + jiffies);
fm10k_slot_warn(interface);
dev_info(&pdev->dev, "%pM\n", netdev->dev_addr);
fm10k_iov_configure(pdev, 0);
clear_bit(__FM10K_SERVICE_DISABLE, &interface->state);
return 0;
err_register:
fm10k_mbx_free_irq(interface);
err_mbx_interrupt:
fm10k_clear_queueing_scheme(interface);
err_sw_init:
if (interface->sw_addr)
iounmap(interface->sw_addr);
iounmap(interface->uc_addr);
err_ioremap:
free_netdev(netdev);
err_alloc_netdev:
pci_release_selected_regions(pdev,
pci_select_bars(pdev, IORESOURCE_MEM));
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static void fm10k_remove(struct pci_dev *pdev)
{
struct fm10k_intfc *interface = pci_get_drvdata(pdev);
struct net_device *netdev = interface->netdev;
del_timer_sync(&interface->service_timer);
set_bit(__FM10K_SERVICE_DISABLE, &interface->state);
cancel_work_sync(&interface->service_task);
if (netdev->reg_state == NETREG_REGISTERED)
unregister_netdev(netdev);
fm10k_iov_disable(pdev);
fm10k_mbx_free_irq(interface);
fm10k_clear_queueing_scheme(interface);
fm10k_dbg_intfc_exit(interface);
if (interface->sw_addr)
iounmap(interface->sw_addr);
iounmap(interface->uc_addr);
free_netdev(netdev);
pci_release_selected_regions(pdev,
pci_select_bars(pdev, IORESOURCE_MEM));
pci_disable_pcie_error_reporting(pdev);
pci_disable_device(pdev);
}
static int fm10k_resume(struct pci_dev *pdev)
{
struct fm10k_intfc *interface = pci_get_drvdata(pdev);
struct net_device *netdev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
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
hw->hw_addr = interface->uc_addr;
err = hw->mac.ops.init_hw(&interface->hw);
if (err) {
dev_err(&pdev->dev, "init_hw failed: %d\n", err);
return err;
}
hw->mac.ops.rebind_hw_stats(hw, &interface->stats);
rtnl_lock();
err = fm10k_init_queueing_scheme(interface);
if (err)
goto err_queueing_scheme;
err = fm10k_mbx_request_irq(interface);
if (err)
goto err_mbx_irq;
err = fm10k_hw_ready(interface);
if (err)
goto err_open;
err = netif_running(netdev) ? fm10k_open(netdev) : 0;
if (err)
goto err_open;
rtnl_unlock();
interface->host_ready = false;
fm10k_watchdog_host_not_ready(interface);
clear_bit(__FM10K_SERVICE_DISABLE, &interface->state);
fm10k_service_event_schedule(interface);
fm10k_iov_resume(pdev);
netif_device_attach(netdev);
return 0;
err_open:
fm10k_mbx_free_irq(interface);
err_mbx_irq:
fm10k_clear_queueing_scheme(interface);
err_queueing_scheme:
rtnl_unlock();
return err;
}
static int fm10k_suspend(struct pci_dev *pdev,
pm_message_t __always_unused state)
{
struct fm10k_intfc *interface = pci_get_drvdata(pdev);
struct net_device *netdev = interface->netdev;
int err = 0;
netif_device_detach(netdev);
fm10k_iov_suspend(pdev);
set_bit(__FM10K_SERVICE_DISABLE, &interface->state);
cancel_work_sync(&interface->service_task);
rtnl_lock();
if (netif_running(netdev))
fm10k_close(netdev);
fm10k_mbx_free_irq(interface);
fm10k_clear_queueing_scheme(interface);
rtnl_unlock();
err = pci_save_state(pdev);
if (err)
return err;
pci_disable_device(pdev);
pci_wake_from_d3(pdev, false);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static pci_ers_result_t fm10k_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct fm10k_intfc *interface = pci_get_drvdata(pdev);
struct net_device *netdev = interface->netdev;
netif_device_detach(netdev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
rtnl_lock();
if (netif_running(netdev))
fm10k_close(netdev);
fm10k_mbx_free_irq(interface);
fm10k_clear_queueing_scheme(interface);
rtnl_unlock();
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t fm10k_io_slot_reset(struct pci_dev *pdev)
{
struct fm10k_intfc *interface = pci_get_drvdata(pdev);
pci_ers_result_t result;
if (pci_enable_device_mem(pdev)) {
dev_err(&pdev->dev,
"Cannot re-enable PCI device after reset.\n");
result = PCI_ERS_RESULT_DISCONNECT;
} else {
pci_set_master(pdev);
pci_restore_state(pdev);
pci_save_state(pdev);
pci_wake_from_d3(pdev, false);
interface->hw.hw_addr = interface->uc_addr;
interface->flags |= FM10K_FLAG_RESET_REQUESTED;
fm10k_service_event_schedule(interface);
result = PCI_ERS_RESULT_RECOVERED;
}
pci_cleanup_aer_uncorrect_error_status(pdev);
return result;
}
static void fm10k_io_resume(struct pci_dev *pdev)
{
struct fm10k_intfc *interface = pci_get_drvdata(pdev);
struct net_device *netdev = interface->netdev;
struct fm10k_hw *hw = &interface->hw;
int err = 0;
err = hw->mac.ops.init_hw(&interface->hw);
if (err) {
dev_err(&pdev->dev, "init_hw failed: %d\n", err);
return;
}
hw->mac.ops.rebind_hw_stats(hw, &interface->stats);
rtnl_lock();
err = fm10k_init_queueing_scheme(interface);
if (err) {
dev_err(&interface->pdev->dev,
"init_queueing_scheme failed: %d\n", err);
goto unlock;
}
fm10k_mbx_request_irq(interface);
rtnl_lock();
if (netif_running(netdev))
err = fm10k_open(netdev);
rtnl_unlock();
err = err ? : fm10k_hw_ready(interface);
if (!err)
netif_device_attach(netdev);
unlock:
rtnl_unlock();
}
int fm10k_register_pci_driver(void)
{
return pci_register_driver(&fm10k_driver);
}
void fm10k_unregister_pci_driver(void)
{
pci_unregister_driver(&fm10k_driver);
}
