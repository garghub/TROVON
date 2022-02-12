static inline void ixgbe_disable_sriov(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 gcr;
u32 gpie;
u32 vmdctl;
#ifdef CONFIG_PCI_IOV
pci_disable_sriov(adapter->pdev);
#endif
gcr = IXGBE_READ_REG(hw, IXGBE_GCR_EXT);
gcr &= ~(IXGBE_GCR_EXT_SRIOV);
IXGBE_WRITE_REG(hw, IXGBE_GCR_EXT, gcr);
gpie = IXGBE_READ_REG(hw, IXGBE_GPIE);
gpie &= ~IXGBE_GPIE_VTMODE_MASK;
IXGBE_WRITE_REG(hw, IXGBE_GPIE, gpie);
vmdctl = IXGBE_READ_REG(hw, IXGBE_VT_CTL);
vmdctl &= ~IXGBE_VT_CTL_POOL_MASK;
IXGBE_WRITE_REG(hw, IXGBE_VT_CTL, vmdctl);
msleep(100);
kfree(adapter->vfinfo);
adapter->vfinfo = NULL;
adapter->num_vfs = 0;
adapter->flags &= ~IXGBE_FLAG_SRIOV_ENABLED;
}
static void ixgbe_service_event_schedule(struct ixgbe_adapter *adapter)
{
if (!test_bit(__IXGBE_DOWN, &adapter->state) &&
!test_and_set_bit(__IXGBE_SERVICE_SCHED, &adapter->state))
schedule_work(&adapter->service_task);
}
static void ixgbe_service_event_complete(struct ixgbe_adapter *adapter)
{
BUG_ON(!test_bit(__IXGBE_SERVICE_SCHED, &adapter->state));
smp_mb__before_clear_bit();
clear_bit(__IXGBE_SERVICE_SCHED, &adapter->state);
}
static void ixgbe_regdump(struct ixgbe_hw *hw, struct ixgbe_reg_info *reginfo)
{
int i = 0, j = 0;
char rname[16];
u32 regs[64];
switch (reginfo->ofs) {
case IXGBE_SRRCTL(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_SRRCTL(i));
break;
case IXGBE_DCA_RXCTRL(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_DCA_RXCTRL(i));
break;
case IXGBE_RDLEN(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_RDLEN(i));
break;
case IXGBE_RDH(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_RDH(i));
break;
case IXGBE_RDT(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_RDT(i));
break;
case IXGBE_RXDCTL(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_RXDCTL(i));
break;
case IXGBE_RDBAL(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_RDBAL(i));
break;
case IXGBE_RDBAH(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_RDBAH(i));
break;
case IXGBE_TDBAL(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_TDBAL(i));
break;
case IXGBE_TDBAH(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_TDBAH(i));
break;
case IXGBE_TDLEN(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_TDLEN(i));
break;
case IXGBE_TDH(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_TDH(i));
break;
case IXGBE_TDT(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_TDT(i));
break;
case IXGBE_TXDCTL(0):
for (i = 0; i < 64; i++)
regs[i] = IXGBE_READ_REG(hw, IXGBE_TXDCTL(i));
break;
default:
pr_info("%-15s %08x\n", reginfo->name,
IXGBE_READ_REG(hw, reginfo->ofs));
return;
}
for (i = 0; i < 8; i++) {
snprintf(rname, 16, "%s[%d-%d]", reginfo->name, i*8, i*8+7);
pr_err("%-15s", rname);
for (j = 0; j < 8; j++)
pr_cont(" %08x", regs[i*8+j]);
pr_cont("\n");
}
}
static void ixgbe_dump(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_reg_info *reginfo;
int n = 0;
struct ixgbe_ring *tx_ring;
struct ixgbe_tx_buffer *tx_buffer_info;
union ixgbe_adv_tx_desc *tx_desc;
struct my_u0 { u64 a; u64 b; } *u0;
struct ixgbe_ring *rx_ring;
union ixgbe_adv_rx_desc *rx_desc;
struct ixgbe_rx_buffer *rx_buffer_info;
u32 staterr;
int i = 0;
if (!netif_msg_hw(adapter))
return;
if (netdev) {
dev_info(&adapter->pdev->dev, "Net device Info\n");
pr_info("Device Name state "
"trans_start last_rx\n");
pr_info("%-15s %016lX %016lX %016lX\n",
netdev->name,
netdev->state,
netdev->trans_start,
netdev->last_rx);
}
dev_info(&adapter->pdev->dev, "Register Dump\n");
pr_info(" Register Name Value\n");
for (reginfo = (struct ixgbe_reg_info *)ixgbe_reg_info_tbl;
reginfo->name; reginfo++) {
ixgbe_regdump(hw, reginfo);
}
if (!netdev || !netif_running(netdev))
goto exit;
dev_info(&adapter->pdev->dev, "TX Rings Summary\n");
pr_info("Queue [NTU] [NTC] [bi(ntc)->dma ] leng ntw timestamp\n");
for (n = 0; n < adapter->num_tx_queues; n++) {
tx_ring = adapter->tx_ring[n];
tx_buffer_info =
&tx_ring->tx_buffer_info[tx_ring->next_to_clean];
pr_info(" %5d %5X %5X %016llX %04X %3X %016llX\n",
n, tx_ring->next_to_use, tx_ring->next_to_clean,
(u64)tx_buffer_info->dma,
tx_buffer_info->length,
tx_buffer_info->next_to_watch,
(u64)tx_buffer_info->time_stamp);
}
if (!netif_msg_tx_done(adapter))
goto rx_ring_summary;
dev_info(&adapter->pdev->dev, "TX Rings Dump\n");
for (n = 0; n < adapter->num_tx_queues; n++) {
tx_ring = adapter->tx_ring[n];
pr_info("------------------------------------\n");
pr_info("TX QUEUE INDEX = %d\n", tx_ring->queue_index);
pr_info("------------------------------------\n");
pr_info("T [desc] [address 63:0 ] "
"[PlPOIdStDDt Ln] [bi->dma ] "
"leng ntw timestamp bi->skb\n");
for (i = 0; tx_ring->desc && (i < tx_ring->count); i++) {
tx_desc = IXGBE_TX_DESC_ADV(tx_ring, i);
tx_buffer_info = &tx_ring->tx_buffer_info[i];
u0 = (struct my_u0 *)tx_desc;
pr_info("T [0x%03X] %016llX %016llX %016llX"
" %04X %3X %016llX %p", i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
(u64)tx_buffer_info->dma,
tx_buffer_info->length,
tx_buffer_info->next_to_watch,
(u64)tx_buffer_info->time_stamp,
tx_buffer_info->skb);
if (i == tx_ring->next_to_use &&
i == tx_ring->next_to_clean)
pr_cont(" NTC/U\n");
else if (i == tx_ring->next_to_use)
pr_cont(" NTU\n");
else if (i == tx_ring->next_to_clean)
pr_cont(" NTC\n");
else
pr_cont("\n");
if (netif_msg_pktdata(adapter) &&
tx_buffer_info->dma != 0)
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS, 16, 1,
phys_to_virt(tx_buffer_info->dma),
tx_buffer_info->length, true);
}
}
rx_ring_summary:
dev_info(&adapter->pdev->dev, "RX Rings Summary\n");
pr_info("Queue [NTU] [NTC]\n");
for (n = 0; n < adapter->num_rx_queues; n++) {
rx_ring = adapter->rx_ring[n];
pr_info("%5d %5X %5X\n",
n, rx_ring->next_to_use, rx_ring->next_to_clean);
}
if (!netif_msg_rx_status(adapter))
goto exit;
dev_info(&adapter->pdev->dev, "RX Rings Dump\n");
for (n = 0; n < adapter->num_rx_queues; n++) {
rx_ring = adapter->rx_ring[n];
pr_info("------------------------------------\n");
pr_info("RX QUEUE INDEX = %d\n", rx_ring->queue_index);
pr_info("------------------------------------\n");
pr_info("R [desc] [ PktBuf A0] "
"[ HeadBuf DD] [bi->dma ] [bi->skb] "
"<-- Adv Rx Read format\n");
pr_info("RWB[desc] [PcsmIpSHl PtRs] "
"[vl er S cks ln] ---------------- [bi->skb] "
"<-- Adv Rx Write-Back format\n");
for (i = 0; i < rx_ring->count; i++) {
rx_buffer_info = &rx_ring->rx_buffer_info[i];
rx_desc = IXGBE_RX_DESC_ADV(rx_ring, i);
u0 = (struct my_u0 *)rx_desc;
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
if (staterr & IXGBE_RXD_STAT_DD) {
pr_info("RWB[0x%03X] %016llX "
"%016llX ---------------- %p", i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
rx_buffer_info->skb);
} else {
pr_info("R [0x%03X] %016llX "
"%016llX %016llX %p", i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
(u64)rx_buffer_info->dma,
rx_buffer_info->skb);
if (netif_msg_pktdata(adapter)) {
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS, 16, 1,
phys_to_virt(rx_buffer_info->dma),
rx_ring->rx_buf_len, true);
if (rx_ring->rx_buf_len
< IXGBE_RXBUFFER_2048)
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS, 16, 1,
phys_to_virt(
rx_buffer_info->page_dma +
rx_buffer_info->page_offset
),
PAGE_SIZE/2, true);
}
}
if (i == rx_ring->next_to_use)
pr_cont(" NTU\n");
else if (i == rx_ring->next_to_clean)
pr_cont(" NTC\n");
else
pr_cont("\n");
}
}
exit:
return;
}
static void ixgbe_release_hw_control(struct ixgbe_adapter *adapter)
{
u32 ctrl_ext;
ctrl_ext = IXGBE_READ_REG(&adapter->hw, IXGBE_CTRL_EXT);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_CTRL_EXT,
ctrl_ext & ~IXGBE_CTRL_EXT_DRV_LOAD);
}
static void ixgbe_get_hw_control(struct ixgbe_adapter *adapter)
{
u32 ctrl_ext;
ctrl_ext = IXGBE_READ_REG(&adapter->hw, IXGBE_CTRL_EXT);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_CTRL_EXT,
ctrl_ext | IXGBE_CTRL_EXT_DRV_LOAD);
}
static void ixgbe_set_ivar(struct ixgbe_adapter *adapter, s8 direction,
u8 queue, u8 msix_vector)
{
u32 ivar, index;
struct ixgbe_hw *hw = &adapter->hw;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
msix_vector |= IXGBE_IVAR_ALLOC_VAL;
if (direction == -1)
direction = 0;
index = (((direction * 64) + queue) >> 2) & 0x1F;
ivar = IXGBE_READ_REG(hw, IXGBE_IVAR(index));
ivar &= ~(0xFF << (8 * (queue & 0x3)));
ivar |= (msix_vector << (8 * (queue & 0x3)));
IXGBE_WRITE_REG(hw, IXGBE_IVAR(index), ivar);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
if (direction == -1) {
msix_vector |= IXGBE_IVAR_ALLOC_VAL;
index = ((queue & 1) * 8);
ivar = IXGBE_READ_REG(&adapter->hw, IXGBE_IVAR_MISC);
ivar &= ~(0xFF << index);
ivar |= (msix_vector << index);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_IVAR_MISC, ivar);
break;
} else {
msix_vector |= IXGBE_IVAR_ALLOC_VAL;
index = ((16 * (queue & 1)) + (8 * direction));
ivar = IXGBE_READ_REG(hw, IXGBE_IVAR(queue >> 1));
ivar &= ~(0xFF << index);
ivar |= (msix_vector << index);
IXGBE_WRITE_REG(hw, IXGBE_IVAR(queue >> 1), ivar);
break;
}
default:
break;
}
}
static inline void ixgbe_irq_rearm_queues(struct ixgbe_adapter *adapter,
u64 qmask)
{
u32 mask;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82598EB:
mask = (IXGBE_EIMS_RTX_QUEUE & qmask);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EICS, mask);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
mask = (qmask & 0xFFFFFFFF);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EICS_EX(0), mask);
mask = (qmask >> 32);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EICS_EX(1), mask);
break;
default:
break;
}
}
void ixgbe_unmap_and_free_tx_resource(struct ixgbe_ring *tx_ring,
struct ixgbe_tx_buffer *tx_buffer_info)
{
if (tx_buffer_info->dma) {
if (tx_buffer_info->mapped_as_page)
dma_unmap_page(tx_ring->dev,
tx_buffer_info->dma,
tx_buffer_info->length,
DMA_TO_DEVICE);
else
dma_unmap_single(tx_ring->dev,
tx_buffer_info->dma,
tx_buffer_info->length,
DMA_TO_DEVICE);
tx_buffer_info->dma = 0;
}
if (tx_buffer_info->skb) {
dev_kfree_skb_any(tx_buffer_info->skb);
tx_buffer_info->skb = NULL;
}
tx_buffer_info->time_stamp = 0;
}
static u8 ixgbe_dcb_txq_to_tc(struct ixgbe_adapter *adapter, u8 reg_idx)
{
int tc = -1;
int dcb_i = netdev_get_num_tc(adapter->netdev);
if (!(adapter->flags & IXGBE_FLAG_DCB_ENABLED))
return tc;
if (reg_idx >= adapter->hw.mac.max_tx_queues)
return tc;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82598EB:
tc = reg_idx >> 2;
break;
default:
if (dcb_i != 4 && dcb_i != 8)
break;
if (adapter->flags & (IXGBE_FLAG_SRIOV_ENABLED |
IXGBE_FLAG_VMDQ_ENABLED)) {
tc = reg_idx & (dcb_i - 1);
break;
}
tc = ((reg_idx & 0X1F) + 0x20) * dcb_i;
tc >>= 9 - (reg_idx >> 5);
}
return tc;
}
static void ixgbe_update_xoff_received(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_hw_stats *hwstats = &adapter->stats;
u32 data = 0;
u32 xoff[8] = {0};
int i;
if ((hw->fc.current_mode == ixgbe_fc_full) ||
(hw->fc.current_mode == ixgbe_fc_rx_pause)) {
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
data = IXGBE_READ_REG(hw, IXGBE_LXOFFRXC);
break;
default:
data = IXGBE_READ_REG(hw, IXGBE_LXOFFRXCNT);
}
hwstats->lxoffrxc += data;
if (!data)
return;
for (i = 0; i < adapter->num_tx_queues; i++)
clear_bit(__IXGBE_HANG_CHECK_ARMED,
&adapter->tx_ring[i]->state);
return;
} else if (!(adapter->dcb_cfg.pfc_mode_enable))
return;
for (i = 0; i < MAX_TX_PACKET_BUFFERS; i++) {
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
xoff[i] = IXGBE_READ_REG(hw, IXGBE_PXOFFRXC(i));
break;
default:
xoff[i] = IXGBE_READ_REG(hw, IXGBE_PXOFFRXCNT(i));
}
hwstats->pxoffrxc[i] += xoff[i];
}
for (i = 0; i < adapter->num_tx_queues; i++) {
struct ixgbe_ring *tx_ring = adapter->tx_ring[i];
u32 tc = ixgbe_dcb_txq_to_tc(adapter, tx_ring->reg_idx);
if (xoff[tc])
clear_bit(__IXGBE_HANG_CHECK_ARMED, &tx_ring->state);
}
}
static u64 ixgbe_get_tx_completed(struct ixgbe_ring *ring)
{
return ring->tx_stats.completed;
}
static u64 ixgbe_get_tx_pending(struct ixgbe_ring *ring)
{
struct ixgbe_adapter *adapter = netdev_priv(ring->netdev);
struct ixgbe_hw *hw = &adapter->hw;
u32 head = IXGBE_READ_REG(hw, IXGBE_TDH(ring->reg_idx));
u32 tail = IXGBE_READ_REG(hw, IXGBE_TDT(ring->reg_idx));
if (head != tail)
return (head < tail) ?
tail - head : (tail + ring->count - head);
return 0;
}
static inline bool ixgbe_check_tx_hang(struct ixgbe_ring *tx_ring)
{
u32 tx_done = ixgbe_get_tx_completed(tx_ring);
u32 tx_done_old = tx_ring->tx_stats.tx_done_old;
u32 tx_pending = ixgbe_get_tx_pending(tx_ring);
bool ret = false;
clear_check_for_tx_hang(tx_ring);
if ((tx_done_old == tx_done) && tx_pending) {
ret = test_and_set_bit(__IXGBE_HANG_CHECK_ARMED,
&tx_ring->state);
} else {
tx_ring->tx_stats.tx_done_old = tx_done;
clear_bit(__IXGBE_HANG_CHECK_ARMED, &tx_ring->state);
}
return ret;
}
static void ixgbe_tx_timeout_reset(struct ixgbe_adapter *adapter)
{
if (!test_bit(__IXGBE_DOWN, &adapter->state)) {
adapter->flags2 |= IXGBE_FLAG2_RESET_REQUESTED;
ixgbe_service_event_schedule(adapter);
}
}
static bool ixgbe_clean_tx_irq(struct ixgbe_q_vector *q_vector,
struct ixgbe_ring *tx_ring)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
union ixgbe_adv_tx_desc *tx_desc, *eop_desc;
struct ixgbe_tx_buffer *tx_buffer_info;
unsigned int total_bytes = 0, total_packets = 0;
u16 i, eop, count = 0;
i = tx_ring->next_to_clean;
eop = tx_ring->tx_buffer_info[i].next_to_watch;
eop_desc = IXGBE_TX_DESC_ADV(tx_ring, eop);
while ((eop_desc->wb.status & cpu_to_le32(IXGBE_TXD_STAT_DD)) &&
(count < tx_ring->work_limit)) {
bool cleaned = false;
rmb();
for ( ; !cleaned; count++) {
tx_desc = IXGBE_TX_DESC_ADV(tx_ring, i);
tx_buffer_info = &tx_ring->tx_buffer_info[i];
tx_desc->wb.status = 0;
cleaned = (i == eop);
i++;
if (i == tx_ring->count)
i = 0;
if (cleaned && tx_buffer_info->skb) {
total_bytes += tx_buffer_info->bytecount;
total_packets += tx_buffer_info->gso_segs;
}
ixgbe_unmap_and_free_tx_resource(tx_ring,
tx_buffer_info);
}
tx_ring->tx_stats.completed++;
eop = tx_ring->tx_buffer_info[i].next_to_watch;
eop_desc = IXGBE_TX_DESC_ADV(tx_ring, eop);
}
tx_ring->next_to_clean = i;
tx_ring->total_bytes += total_bytes;
tx_ring->total_packets += total_packets;
u64_stats_update_begin(&tx_ring->syncp);
tx_ring->stats.packets += total_packets;
tx_ring->stats.bytes += total_bytes;
u64_stats_update_end(&tx_ring->syncp);
if (check_for_tx_hang(tx_ring) && ixgbe_check_tx_hang(tx_ring)) {
struct ixgbe_hw *hw = &adapter->hw;
tx_desc = IXGBE_TX_DESC_ADV(tx_ring, eop);
e_err(drv, "Detected Tx Unit Hang\n"
" Tx Queue <%d>\n"
" TDH, TDT <%x>, <%x>\n"
" next_to_use <%x>\n"
" next_to_clean <%x>\n"
"tx_buffer_info[next_to_clean]\n"
" time_stamp <%lx>\n"
" jiffies <%lx>\n",
tx_ring->queue_index,
IXGBE_READ_REG(hw, IXGBE_TDH(tx_ring->reg_idx)),
IXGBE_READ_REG(hw, IXGBE_TDT(tx_ring->reg_idx)),
tx_ring->next_to_use, eop,
tx_ring->tx_buffer_info[eop].time_stamp, jiffies);
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
e_info(probe,
"tx hang %d detected on queue %d, resetting adapter\n",
adapter->tx_timeout_count + 1, tx_ring->queue_index);
ixgbe_tx_timeout_reset(adapter);
return true;
}
#define TX_WAKE_THRESHOLD (DESC_NEEDED * 2)
if (unlikely(count && netif_carrier_ok(tx_ring->netdev) &&
(IXGBE_DESC_UNUSED(tx_ring) >= TX_WAKE_THRESHOLD))) {
smp_mb();
if (__netif_subqueue_stopped(tx_ring->netdev, tx_ring->queue_index) &&
!test_bit(__IXGBE_DOWN, &adapter->state)) {
netif_wake_subqueue(tx_ring->netdev, tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
}
}
return count < tx_ring->work_limit;
}
static void ixgbe_update_rx_dca(struct ixgbe_adapter *adapter,
struct ixgbe_ring *rx_ring,
int cpu)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 rxctrl;
u8 reg_idx = rx_ring->reg_idx;
rxctrl = IXGBE_READ_REG(hw, IXGBE_DCA_RXCTRL(reg_idx));
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
rxctrl &= ~IXGBE_DCA_RXCTRL_CPUID_MASK;
rxctrl |= dca3_get_tag(&adapter->pdev->dev, cpu);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
rxctrl &= ~IXGBE_DCA_RXCTRL_CPUID_MASK_82599;
rxctrl |= (dca3_get_tag(&adapter->pdev->dev, cpu) <<
IXGBE_DCA_RXCTRL_CPUID_SHIFT_82599);
break;
default:
break;
}
rxctrl |= IXGBE_DCA_RXCTRL_DESC_DCA_EN;
rxctrl |= IXGBE_DCA_RXCTRL_HEAD_DCA_EN;
rxctrl &= ~(IXGBE_DCA_RXCTRL_DESC_RRO_EN);
IXGBE_WRITE_REG(hw, IXGBE_DCA_RXCTRL(reg_idx), rxctrl);
}
static void ixgbe_update_tx_dca(struct ixgbe_adapter *adapter,
struct ixgbe_ring *tx_ring,
int cpu)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 txctrl;
u8 reg_idx = tx_ring->reg_idx;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
txctrl = IXGBE_READ_REG(hw, IXGBE_DCA_TXCTRL(reg_idx));
txctrl &= ~IXGBE_DCA_TXCTRL_CPUID_MASK;
txctrl |= dca3_get_tag(&adapter->pdev->dev, cpu);
txctrl |= IXGBE_DCA_TXCTRL_DESC_DCA_EN;
IXGBE_WRITE_REG(hw, IXGBE_DCA_TXCTRL(reg_idx), txctrl);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
txctrl = IXGBE_READ_REG(hw, IXGBE_DCA_TXCTRL_82599(reg_idx));
txctrl &= ~IXGBE_DCA_TXCTRL_CPUID_MASK_82599;
txctrl |= (dca3_get_tag(&adapter->pdev->dev, cpu) <<
IXGBE_DCA_TXCTRL_CPUID_SHIFT_82599);
txctrl |= IXGBE_DCA_TXCTRL_DESC_DCA_EN;
IXGBE_WRITE_REG(hw, IXGBE_DCA_TXCTRL_82599(reg_idx), txctrl);
break;
default:
break;
}
}
static void ixgbe_update_dca(struct ixgbe_q_vector *q_vector)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
int cpu = get_cpu();
long r_idx;
int i;
if (q_vector->cpu == cpu)
goto out_no_update;
r_idx = find_first_bit(q_vector->txr_idx, adapter->num_tx_queues);
for (i = 0; i < q_vector->txr_count; i++) {
ixgbe_update_tx_dca(adapter, adapter->tx_ring[r_idx], cpu);
r_idx = find_next_bit(q_vector->txr_idx, adapter->num_tx_queues,
r_idx + 1);
}
r_idx = find_first_bit(q_vector->rxr_idx, adapter->num_rx_queues);
for (i = 0; i < q_vector->rxr_count; i++) {
ixgbe_update_rx_dca(adapter, adapter->rx_ring[r_idx], cpu);
r_idx = find_next_bit(q_vector->rxr_idx, adapter->num_rx_queues,
r_idx + 1);
}
q_vector->cpu = cpu;
out_no_update:
put_cpu();
}
static void ixgbe_setup_dca(struct ixgbe_adapter *adapter)
{
int num_q_vectors;
int i;
if (!(adapter->flags & IXGBE_FLAG_DCA_ENABLED))
return;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL, 2);
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED)
num_q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
else
num_q_vectors = 1;
for (i = 0; i < num_q_vectors; i++) {
adapter->q_vector[i]->cpu = -1;
ixgbe_update_dca(adapter->q_vector[i]);
}
}
static int __ixgbe_notify_dca(struct device *dev, void *data)
{
struct ixgbe_adapter *adapter = dev_get_drvdata(dev);
unsigned long event = *(unsigned long *)data;
if (!(adapter->flags & IXGBE_FLAG_DCA_ENABLED))
return 0;
switch (event) {
case DCA_PROVIDER_ADD:
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
break;
if (dca_add_requester(dev) == 0) {
adapter->flags |= IXGBE_FLAG_DCA_ENABLED;
ixgbe_setup_dca(adapter);
break;
}
case DCA_PROVIDER_REMOVE:
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED) {
dca_remove_requester(dev);
adapter->flags &= ~IXGBE_FLAG_DCA_ENABLED;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL, 1);
}
break;
}
return 0;
}
static inline void ixgbe_rx_hash(union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
skb->rxhash = le32_to_cpu(rx_desc->wb.lower.hi_dword.rss);
}
static void ixgbe_receive_skb(struct ixgbe_q_vector *q_vector,
struct sk_buff *skb, u8 status,
struct ixgbe_ring *ring,
union ixgbe_adv_rx_desc *rx_desc)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
struct napi_struct *napi = &q_vector->napi;
bool is_vlan = (status & IXGBE_RXD_STAT_VP);
u16 tag = le16_to_cpu(rx_desc->wb.upper.vlan);
if (is_vlan && (tag & VLAN_VID_MASK))
__vlan_hwaccel_put_tag(skb, tag);
if (!(adapter->flags & IXGBE_FLAG_IN_NETPOLL))
napi_gro_receive(napi, skb);
else
netif_rx(skb);
}
static inline void ixgbe_rx_checksum(struct ixgbe_adapter *adapter,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
u32 status_err = le32_to_cpu(rx_desc->wb.upper.status_error);
skb_checksum_none_assert(skb);
if (!(adapter->flags & IXGBE_FLAG_RX_CSUM_ENABLED))
return;
if ((status_err & IXGBE_RXD_STAT_IPCS) &&
(status_err & IXGBE_RXDADV_ERR_IPE)) {
adapter->hw_csum_rx_error++;
return;
}
if (!(status_err & IXGBE_RXD_STAT_L4CS))
return;
if (status_err & IXGBE_RXDADV_ERR_TCPE) {
u16 pkt_info = rx_desc->wb.lower.lo_dword.hs_rss.pkt_info;
if ((pkt_info & IXGBE_RXDADV_PKTTYPE_UDP) &&
(adapter->hw.mac.type == ixgbe_mac_82599EB))
return;
adapter->hw_csum_rx_error++;
return;
}
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
static inline void ixgbe_release_rx_desc(struct ixgbe_ring *rx_ring, u32 val)
{
wmb();
writel(val, rx_ring->tail);
}
void ixgbe_alloc_rx_buffers(struct ixgbe_ring *rx_ring, u16 cleaned_count)
{
union ixgbe_adv_rx_desc *rx_desc;
struct ixgbe_rx_buffer *bi;
struct sk_buff *skb;
u16 i = rx_ring->next_to_use;
if (!rx_ring->netdev)
return;
while (cleaned_count--) {
rx_desc = IXGBE_RX_DESC_ADV(rx_ring, i);
bi = &rx_ring->rx_buffer_info[i];
skb = bi->skb;
if (!skb) {
skb = netdev_alloc_skb_ip_align(rx_ring->netdev,
rx_ring->rx_buf_len);
if (!skb) {
rx_ring->rx_stats.alloc_rx_buff_failed++;
goto no_buffers;
}
skb_record_rx_queue(skb, rx_ring->queue_index);
bi->skb = skb;
}
if (!bi->dma) {
bi->dma = dma_map_single(rx_ring->dev,
skb->data,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev, bi->dma)) {
rx_ring->rx_stats.alloc_rx_buff_failed++;
bi->dma = 0;
goto no_buffers;
}
}
if (ring_is_ps_enabled(rx_ring)) {
if (!bi->page) {
bi->page = netdev_alloc_page(rx_ring->netdev);
if (!bi->page) {
rx_ring->rx_stats.alloc_rx_page_failed++;
goto no_buffers;
}
}
if (!bi->page_dma) {
bi->page_offset ^= PAGE_SIZE / 2;
bi->page_dma = dma_map_page(rx_ring->dev,
bi->page,
bi->page_offset,
PAGE_SIZE / 2,
DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev,
bi->page_dma)) {
rx_ring->rx_stats.alloc_rx_page_failed++;
bi->page_dma = 0;
goto no_buffers;
}
}
rx_desc->read.pkt_addr = cpu_to_le64(bi->page_dma);
rx_desc->read.hdr_addr = cpu_to_le64(bi->dma);
} else {
rx_desc->read.pkt_addr = cpu_to_le64(bi->dma);
rx_desc->read.hdr_addr = 0;
}
i++;
if (i == rx_ring->count)
i = 0;
}
no_buffers:
if (rx_ring->next_to_use != i) {
rx_ring->next_to_use = i;
ixgbe_release_rx_desc(rx_ring, i);
}
}
static inline u16 ixgbe_get_hlen(union ixgbe_adv_rx_desc *rx_desc)
{
u16 hdr_info = le16_to_cpu(rx_desc->wb.lower.lo_dword.hs_rss.hdr_info);
u16 hlen = (hdr_info & IXGBE_RXDADV_HDRBUFLEN_MASK) >>
IXGBE_RXDADV_HDRBUFLEN_SHIFT;
if (hlen > IXGBE_RX_HDR_SIZE)
hlen = IXGBE_RX_HDR_SIZE;
return hlen;
}
static inline struct sk_buff *ixgbe_transform_rsc_queue(struct sk_buff *skb)
{
unsigned int frag_list_size = 0;
unsigned int skb_cnt = 1;
while (skb->prev) {
struct sk_buff *prev = skb->prev;
frag_list_size += skb->len;
skb->prev = NULL;
skb = prev;
skb_cnt++;
}
skb_shinfo(skb)->frag_list = skb->next;
skb->next = NULL;
skb->len += frag_list_size;
skb->data_len += frag_list_size;
skb->truesize += frag_list_size;
IXGBE_RSC_CB(skb)->skb_cnt = skb_cnt;
return skb;
}
static inline bool ixgbe_get_rsc_state(union ixgbe_adv_rx_desc *rx_desc)
{
return !!(le32_to_cpu(rx_desc->wb.lower.lo_dword.data) &
IXGBE_RXDADV_RSCCNT_MASK);
}
static void ixgbe_clean_rx_irq(struct ixgbe_q_vector *q_vector,
struct ixgbe_ring *rx_ring,
int *work_done, int work_to_do)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
union ixgbe_adv_rx_desc *rx_desc, *next_rxd;
struct ixgbe_rx_buffer *rx_buffer_info, *next_buffer;
struct sk_buff *skb;
unsigned int total_rx_bytes = 0, total_rx_packets = 0;
const int current_node = numa_node_id();
#ifdef IXGBE_FCOE
int ddp_bytes = 0;
#endif
u32 staterr;
u16 i;
u16 cleaned_count = 0;
bool pkt_is_rsc = false;
i = rx_ring->next_to_clean;
rx_desc = IXGBE_RX_DESC_ADV(rx_ring, i);
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
while (staterr & IXGBE_RXD_STAT_DD) {
u32 upper_len = 0;
rmb();
rx_buffer_info = &rx_ring->rx_buffer_info[i];
skb = rx_buffer_info->skb;
rx_buffer_info->skb = NULL;
prefetch(skb->data);
if (ring_is_rsc_enabled(rx_ring))
pkt_is_rsc = ixgbe_get_rsc_state(rx_desc);
if (rx_buffer_info->dma) {
u16 hlen;
if (pkt_is_rsc &&
!(staterr & IXGBE_RXD_STAT_EOP) &&
!skb->prev) {
IXGBE_RSC_CB(skb)->delay_unmap = true;
IXGBE_RSC_CB(skb)->dma = rx_buffer_info->dma;
} else {
dma_unmap_single(rx_ring->dev,
rx_buffer_info->dma,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
}
rx_buffer_info->dma = 0;
if (ring_is_ps_enabled(rx_ring)) {
hlen = ixgbe_get_hlen(rx_desc);
upper_len = le16_to_cpu(rx_desc->wb.upper.length);
} else {
hlen = le16_to_cpu(rx_desc->wb.upper.length);
}
skb_put(skb, hlen);
} else {
upper_len = le16_to_cpu(rx_desc->wb.upper.length);
}
if (upper_len) {
dma_unmap_page(rx_ring->dev,
rx_buffer_info->page_dma,
PAGE_SIZE / 2,
DMA_FROM_DEVICE);
rx_buffer_info->page_dma = 0;
skb_fill_page_desc(skb, skb_shinfo(skb)->nr_frags,
rx_buffer_info->page,
rx_buffer_info->page_offset,
upper_len);
if ((page_count(rx_buffer_info->page) == 1) &&
(page_to_nid(rx_buffer_info->page) == current_node))
get_page(rx_buffer_info->page);
else
rx_buffer_info->page = NULL;
skb->len += upper_len;
skb->data_len += upper_len;
skb->truesize += upper_len;
}
i++;
if (i == rx_ring->count)
i = 0;
next_rxd = IXGBE_RX_DESC_ADV(rx_ring, i);
prefetch(next_rxd);
cleaned_count++;
if (pkt_is_rsc) {
u32 nextp = (staterr & IXGBE_RXDADV_NEXTP_MASK) >>
IXGBE_RXDADV_NEXTP_SHIFT;
next_buffer = &rx_ring->rx_buffer_info[nextp];
} else {
next_buffer = &rx_ring->rx_buffer_info[i];
}
if (!(staterr & IXGBE_RXD_STAT_EOP)) {
if (ring_is_ps_enabled(rx_ring)) {
rx_buffer_info->skb = next_buffer->skb;
rx_buffer_info->dma = next_buffer->dma;
next_buffer->skb = skb;
next_buffer->dma = 0;
} else {
skb->next = next_buffer->skb;
skb->next->prev = skb;
}
rx_ring->rx_stats.non_eop_descs++;
goto next_desc;
}
if (skb->prev) {
skb = ixgbe_transform_rsc_queue(skb);
if (!pkt_is_rsc) {
__pskb_trim(skb, 0);
rx_buffer_info->skb = skb;
goto next_desc;
}
}
if (ring_is_rsc_enabled(rx_ring)) {
if (IXGBE_RSC_CB(skb)->delay_unmap) {
dma_unmap_single(rx_ring->dev,
IXGBE_RSC_CB(skb)->dma,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
IXGBE_RSC_CB(skb)->dma = 0;
IXGBE_RSC_CB(skb)->delay_unmap = false;
}
}
if (pkt_is_rsc) {
if (ring_is_ps_enabled(rx_ring))
rx_ring->rx_stats.rsc_count +=
skb_shinfo(skb)->nr_frags;
else
rx_ring->rx_stats.rsc_count +=
IXGBE_RSC_CB(skb)->skb_cnt;
rx_ring->rx_stats.rsc_flush++;
}
if (staterr & IXGBE_RXDADV_ERR_FRAME_ERR_MASK) {
__pskb_trim(skb, 0);
rx_buffer_info->skb = skb;
goto next_desc;
}
ixgbe_rx_checksum(adapter, rx_desc, skb);
if (adapter->netdev->features & NETIF_F_RXHASH)
ixgbe_rx_hash(rx_desc, skb);
total_rx_bytes += skb->len;
total_rx_packets++;
skb->protocol = eth_type_trans(skb, rx_ring->netdev);
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED) {
ddp_bytes = ixgbe_fcoe_ddp(adapter, rx_desc, skb);
if (!ddp_bytes)
goto next_desc;
}
#endif
ixgbe_receive_skb(q_vector, skb, staterr, rx_ring, rx_desc);
next_desc:
rx_desc->wb.upper.status_error = 0;
(*work_done)++;
if (*work_done >= work_to_do)
break;
if (cleaned_count >= IXGBE_RX_BUFFER_WRITE) {
ixgbe_alloc_rx_buffers(rx_ring, cleaned_count);
cleaned_count = 0;
}
rx_desc = next_rxd;
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
}
rx_ring->next_to_clean = i;
cleaned_count = IXGBE_DESC_UNUSED(rx_ring);
if (cleaned_count)
ixgbe_alloc_rx_buffers(rx_ring, cleaned_count);
#ifdef IXGBE_FCOE
if (ddp_bytes > 0) {
unsigned int mss;
mss = rx_ring->netdev->mtu - sizeof(struct fcoe_hdr) -
sizeof(struct fc_frame_header) -
sizeof(struct fcoe_crc_eof);
if (mss > 512)
mss &= ~511;
total_rx_bytes += ddp_bytes;
total_rx_packets += DIV_ROUND_UP(ddp_bytes, mss);
}
#endif
rx_ring->total_packets += total_rx_packets;
rx_ring->total_bytes += total_rx_bytes;
u64_stats_update_begin(&rx_ring->syncp);
rx_ring->stats.packets += total_rx_packets;
rx_ring->stats.bytes += total_rx_bytes;
u64_stats_update_end(&rx_ring->syncp);
}
static void ixgbe_configure_msix(struct ixgbe_adapter *adapter)
{
struct ixgbe_q_vector *q_vector;
int i, q_vectors, v_idx, r_idx;
u32 mask;
q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (v_idx = 0; v_idx < q_vectors; v_idx++) {
q_vector = adapter->q_vector[v_idx];
r_idx = find_first_bit(q_vector->rxr_idx,
adapter->num_rx_queues);
for (i = 0; i < q_vector->rxr_count; i++) {
u8 reg_idx = adapter->rx_ring[r_idx]->reg_idx;
ixgbe_set_ivar(adapter, 0, reg_idx, v_idx);
r_idx = find_next_bit(q_vector->rxr_idx,
adapter->num_rx_queues,
r_idx + 1);
}
r_idx = find_first_bit(q_vector->txr_idx,
adapter->num_tx_queues);
for (i = 0; i < q_vector->txr_count; i++) {
u8 reg_idx = adapter->tx_ring[r_idx]->reg_idx;
ixgbe_set_ivar(adapter, 1, reg_idx, v_idx);
r_idx = find_next_bit(q_vector->txr_idx,
adapter->num_tx_queues,
r_idx + 1);
}
if (q_vector->txr_count && !q_vector->rxr_count)
q_vector->eitr = adapter->tx_eitr_param;
else if (q_vector->rxr_count)
q_vector->eitr = adapter->rx_eitr_param;
ixgbe_write_eitr(q_vector);
if ((adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) ||
(adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE)) {
if (!alloc_cpumask_var(&q_vector->affinity_mask,
GFP_KERNEL))
return;
cpumask_set_cpu(v_idx, q_vector->affinity_mask);
irq_set_affinity_hint(adapter->msix_entries[v_idx].vector,
q_vector->affinity_mask);
}
}
switch (adapter->hw.mac.type) {
case ixgbe_mac_82598EB:
ixgbe_set_ivar(adapter, -1, IXGBE_IVAR_OTHER_CAUSES_INDEX,
v_idx);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
ixgbe_set_ivar(adapter, -1, 1, v_idx);
break;
default:
break;
}
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EITR(v_idx), 1950);
mask = IXGBE_EIMS_ENABLE_MASK;
if (adapter->num_vfs)
mask &= ~(IXGBE_EIMS_OTHER |
IXGBE_EIMS_MAILBOX |
IXGBE_EIMS_LSC);
else
mask &= ~(IXGBE_EIMS_OTHER | IXGBE_EIMS_LSC);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIAC, mask);
}
static u8 ixgbe_update_itr(struct ixgbe_adapter *adapter,
u32 eitr, u8 itr_setting,
int packets, int bytes)
{
unsigned int retval = itr_setting;
u32 timepassed_us;
u64 bytes_perint;
if (packets == 0)
goto update_itr_done;
timepassed_us = 1000000/eitr;
bytes_perint = bytes / timepassed_us;
switch (itr_setting) {
case lowest_latency:
if (bytes_perint > adapter->eitr_low)
retval = low_latency;
break;
case low_latency:
if (bytes_perint > adapter->eitr_high)
retval = bulk_latency;
else if (bytes_perint <= adapter->eitr_low)
retval = lowest_latency;
break;
case bulk_latency:
if (bytes_perint <= adapter->eitr_high)
retval = low_latency;
break;
}
update_itr_done:
return retval;
}
void ixgbe_write_eitr(struct ixgbe_q_vector *q_vector)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_hw *hw = &adapter->hw;
int v_idx = q_vector->v_idx;
u32 itr_reg = EITR_INTS_PER_SEC_TO_REG(q_vector->eitr);
switch (adapter->hw.mac.type) {
case ixgbe_mac_82598EB:
itr_reg |= (itr_reg << 16);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
if (itr_reg == 8 &&
!(adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED))
itr_reg = 0;
itr_reg |= IXGBE_EITR_CNT_WDIS;
break;
default:
break;
}
IXGBE_WRITE_REG(hw, IXGBE_EITR(v_idx), itr_reg);
}
static void ixgbe_set_itr_msix(struct ixgbe_q_vector *q_vector)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
int i, r_idx;
u32 new_itr;
u8 current_itr, ret_itr;
r_idx = find_first_bit(q_vector->txr_idx, adapter->num_tx_queues);
for (i = 0; i < q_vector->txr_count; i++) {
struct ixgbe_ring *tx_ring = adapter->tx_ring[r_idx];
ret_itr = ixgbe_update_itr(adapter, q_vector->eitr,
q_vector->tx_itr,
tx_ring->total_packets,
tx_ring->total_bytes);
q_vector->tx_itr = ((q_vector->tx_itr > ret_itr) ?
q_vector->tx_itr - 1 : ret_itr);
r_idx = find_next_bit(q_vector->txr_idx, adapter->num_tx_queues,
r_idx + 1);
}
r_idx = find_first_bit(q_vector->rxr_idx, adapter->num_rx_queues);
for (i = 0; i < q_vector->rxr_count; i++) {
struct ixgbe_ring *rx_ring = adapter->rx_ring[r_idx];
ret_itr = ixgbe_update_itr(adapter, q_vector->eitr,
q_vector->rx_itr,
rx_ring->total_packets,
rx_ring->total_bytes);
q_vector->rx_itr = ((q_vector->rx_itr > ret_itr) ?
q_vector->rx_itr - 1 : ret_itr);
r_idx = find_next_bit(q_vector->rxr_idx, adapter->num_rx_queues,
r_idx + 1);
}
current_itr = max(q_vector->rx_itr, q_vector->tx_itr);
switch (current_itr) {
case lowest_latency:
new_itr = 100000;
break;
case low_latency:
new_itr = 20000;
break;
case bulk_latency:
default:
new_itr = 8000;
break;
}
if (new_itr != q_vector->eitr) {
new_itr = ((q_vector->eitr * 9) + new_itr)/10;
q_vector->eitr = new_itr;
ixgbe_write_eitr(q_vector);
}
}
static void ixgbe_check_overtemp_subtask(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 eicr = adapter->interrupt_event;
if (test_bit(__IXGBE_DOWN, &adapter->state))
return;
if (!(adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE) &&
!(adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_EVENT))
return;
adapter->flags2 &= ~IXGBE_FLAG2_TEMP_SENSOR_EVENT;
switch (hw->device_id) {
case IXGBE_DEV_ID_82599_T3_LOM:
if (!(eicr & IXGBE_EICR_GPI_SDP0) &&
!(eicr & IXGBE_EICR_LSC))
return;
if (!(eicr & IXGBE_EICR_LSC) && hw->mac.ops.check_link) {
u32 autoneg;
bool link_up = false;
hw->mac.ops.check_link(hw, &autoneg, &link_up, false);
if (link_up)
return;
}
if (hw->phy.ops.check_overtemp(hw) != IXGBE_ERR_OVERTEMP)
return;
break;
default:
if (!(eicr & IXGBE_EICR_GPI_SDP0))
return;
break;
}
e_crit(drv,
"Network adapter has been stopped because it has over heated. "
"Restart the computer. If the problem persists, "
"power off the system and replace the adapter\n");
adapter->interrupt_event = 0;
}
static void ixgbe_check_fan_failure(struct ixgbe_adapter *adapter, u32 eicr)
{
struct ixgbe_hw *hw = &adapter->hw;
if ((adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE) &&
(eicr & IXGBE_EICR_GPI_SDP1)) {
e_crit(probe, "Fan has stopped, replace the adapter\n");
IXGBE_WRITE_REG(hw, IXGBE_EICR, IXGBE_EICR_GPI_SDP1);
}
}
static void ixgbe_check_sfp_event(struct ixgbe_adapter *adapter, u32 eicr)
{
struct ixgbe_hw *hw = &adapter->hw;
if (eicr & IXGBE_EICR_GPI_SDP2) {
IXGBE_WRITE_REG(hw, IXGBE_EICR, IXGBE_EICR_GPI_SDP2);
if (!test_bit(__IXGBE_DOWN, &adapter->state)) {
adapter->flags2 |= IXGBE_FLAG2_SFP_NEEDS_RESET;
ixgbe_service_event_schedule(adapter);
}
}
if (eicr & IXGBE_EICR_GPI_SDP1) {
IXGBE_WRITE_REG(hw, IXGBE_EICR, IXGBE_EICR_GPI_SDP1);
if (!test_bit(__IXGBE_DOWN, &adapter->state)) {
adapter->flags |= IXGBE_FLAG_NEED_LINK_CONFIG;
ixgbe_service_event_schedule(adapter);
}
}
}
static void ixgbe_check_lsc(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
adapter->lsc_int++;
adapter->flags |= IXGBE_FLAG_NEED_LINK_UPDATE;
adapter->link_check_timeout = jiffies;
if (!test_bit(__IXGBE_DOWN, &adapter->state)) {
IXGBE_WRITE_REG(hw, IXGBE_EIMC, IXGBE_EIMC_LSC);
IXGBE_WRITE_FLUSH(hw);
ixgbe_service_event_schedule(adapter);
}
}
static irqreturn_t ixgbe_msix_lsc(int irq, void *data)
{
struct net_device *netdev = data;
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
u32 eicr;
eicr = IXGBE_READ_REG(hw, IXGBE_EICS);
IXGBE_WRITE_REG(hw, IXGBE_EICR, eicr);
if (eicr & IXGBE_EICR_LSC)
ixgbe_check_lsc(adapter);
if (eicr & IXGBE_EICR_MAILBOX)
ixgbe_msg_task(adapter);
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
if (eicr & IXGBE_EICR_FLOW_DIR) {
int reinit_count = 0;
int i;
for (i = 0; i < adapter->num_tx_queues; i++) {
struct ixgbe_ring *ring = adapter->tx_ring[i];
if (test_and_clear_bit(__IXGBE_TX_FDIR_INIT_DONE,
&ring->state))
reinit_count++;
}
if (reinit_count) {
IXGBE_WRITE_REG(hw, IXGBE_EIMC, IXGBE_EIMC_FLOW_DIR);
eicr &= ~IXGBE_EICR_FLOW_DIR;
adapter->flags2 |= IXGBE_FLAG2_FDIR_REQUIRES_REINIT;
ixgbe_service_event_schedule(adapter);
}
}
ixgbe_check_sfp_event(adapter, eicr);
if ((adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE) &&
((eicr & IXGBE_EICR_GPI_SDP0) || (eicr & IXGBE_EICR_LSC))) {
if (!test_bit(__IXGBE_DOWN, &adapter->state)) {
adapter->interrupt_event = eicr;
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_EVENT;
ixgbe_service_event_schedule(adapter);
}
}
break;
default:
break;
}
ixgbe_check_fan_failure(adapter, eicr);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
IXGBE_WRITE_REG(hw, IXGBE_EIMS, eicr &
~(IXGBE_EIMS_LSC | IXGBE_EIMS_RTX_QUEUE));
return IRQ_HANDLED;
}
static inline void ixgbe_irq_enable_queues(struct ixgbe_adapter *adapter,
u64 qmask)
{
u32 mask;
struct ixgbe_hw *hw = &adapter->hw;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
mask = (IXGBE_EIMS_RTX_QUEUE & qmask);
IXGBE_WRITE_REG(hw, IXGBE_EIMS, mask);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
mask = (qmask & 0xFFFFFFFF);
if (mask)
IXGBE_WRITE_REG(hw, IXGBE_EIMS_EX(0), mask);
mask = (qmask >> 32);
if (mask)
IXGBE_WRITE_REG(hw, IXGBE_EIMS_EX(1), mask);
break;
default:
break;
}
}
static inline void ixgbe_irq_disable_queues(struct ixgbe_adapter *adapter,
u64 qmask)
{
u32 mask;
struct ixgbe_hw *hw = &adapter->hw;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
mask = (IXGBE_EIMS_RTX_QUEUE & qmask);
IXGBE_WRITE_REG(hw, IXGBE_EIMC, mask);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
mask = (qmask & 0xFFFFFFFF);
if (mask)
IXGBE_WRITE_REG(hw, IXGBE_EIMC_EX(0), mask);
mask = (qmask >> 32);
if (mask)
IXGBE_WRITE_REG(hw, IXGBE_EIMC_EX(1), mask);
break;
default:
break;
}
}
static irqreturn_t ixgbe_msix_clean_tx(int irq, void *data)
{
struct ixgbe_q_vector *q_vector = data;
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *tx_ring;
int i, r_idx;
if (!q_vector->txr_count)
return IRQ_HANDLED;
r_idx = find_first_bit(q_vector->txr_idx, adapter->num_tx_queues);
for (i = 0; i < q_vector->txr_count; i++) {
tx_ring = adapter->tx_ring[r_idx];
tx_ring->total_bytes = 0;
tx_ring->total_packets = 0;
r_idx = find_next_bit(q_vector->txr_idx, adapter->num_tx_queues,
r_idx + 1);
}
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static irqreturn_t ixgbe_msix_clean_rx(int irq, void *data)
{
struct ixgbe_q_vector *q_vector = data;
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *rx_ring;
int r_idx;
int i;
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
ixgbe_update_dca(q_vector);
#endif
r_idx = find_first_bit(q_vector->rxr_idx, adapter->num_rx_queues);
for (i = 0; i < q_vector->rxr_count; i++) {
rx_ring = adapter->rx_ring[r_idx];
rx_ring->total_bytes = 0;
rx_ring->total_packets = 0;
r_idx = find_next_bit(q_vector->rxr_idx, adapter->num_rx_queues,
r_idx + 1);
}
if (!q_vector->rxr_count)
return IRQ_HANDLED;
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static irqreturn_t ixgbe_msix_clean_many(int irq, void *data)
{
struct ixgbe_q_vector *q_vector = data;
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *ring;
int r_idx;
int i;
if (!q_vector->txr_count && !q_vector->rxr_count)
return IRQ_HANDLED;
r_idx = find_first_bit(q_vector->txr_idx, adapter->num_tx_queues);
for (i = 0; i < q_vector->txr_count; i++) {
ring = adapter->tx_ring[r_idx];
ring->total_bytes = 0;
ring->total_packets = 0;
r_idx = find_next_bit(q_vector->txr_idx, adapter->num_tx_queues,
r_idx + 1);
}
r_idx = find_first_bit(q_vector->rxr_idx, adapter->num_rx_queues);
for (i = 0; i < q_vector->rxr_count; i++) {
ring = adapter->rx_ring[r_idx];
ring->total_bytes = 0;
ring->total_packets = 0;
r_idx = find_next_bit(q_vector->rxr_idx, adapter->num_rx_queues,
r_idx + 1);
}
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static int ixgbe_clean_rxonly(struct napi_struct *napi, int budget)
{
struct ixgbe_q_vector *q_vector =
container_of(napi, struct ixgbe_q_vector, napi);
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *rx_ring = NULL;
int work_done = 0;
long r_idx;
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
ixgbe_update_dca(q_vector);
#endif
r_idx = find_first_bit(q_vector->rxr_idx, adapter->num_rx_queues);
rx_ring = adapter->rx_ring[r_idx];
ixgbe_clean_rx_irq(q_vector, rx_ring, &work_done, budget);
if (work_done < budget) {
napi_complete(napi);
if (adapter->rx_itr_setting & 1)
ixgbe_set_itr_msix(q_vector);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable_queues(adapter,
((u64)1 << q_vector->v_idx));
}
return work_done;
}
static int ixgbe_clean_rxtx_many(struct napi_struct *napi, int budget)
{
struct ixgbe_q_vector *q_vector =
container_of(napi, struct ixgbe_q_vector, napi);
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *ring = NULL;
int work_done = 0, i;
long r_idx;
bool tx_clean_complete = true;
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
ixgbe_update_dca(q_vector);
#endif
r_idx = find_first_bit(q_vector->txr_idx, adapter->num_tx_queues);
for (i = 0; i < q_vector->txr_count; i++) {
ring = adapter->tx_ring[r_idx];
tx_clean_complete &= ixgbe_clean_tx_irq(q_vector, ring);
r_idx = find_next_bit(q_vector->txr_idx, adapter->num_tx_queues,
r_idx + 1);
}
budget /= (q_vector->rxr_count ?: 1);
budget = max(budget, 1);
r_idx = find_first_bit(q_vector->rxr_idx, adapter->num_rx_queues);
for (i = 0; i < q_vector->rxr_count; i++) {
ring = adapter->rx_ring[r_idx];
ixgbe_clean_rx_irq(q_vector, ring, &work_done, budget);
r_idx = find_next_bit(q_vector->rxr_idx, adapter->num_rx_queues,
r_idx + 1);
}
r_idx = find_first_bit(q_vector->rxr_idx, adapter->num_rx_queues);
ring = adapter->rx_ring[r_idx];
if (work_done < budget) {
napi_complete(napi);
if (adapter->rx_itr_setting & 1)
ixgbe_set_itr_msix(q_vector);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable_queues(adapter,
((u64)1 << q_vector->v_idx));
return 0;
}
return work_done;
}
static int ixgbe_clean_txonly(struct napi_struct *napi, int budget)
{
struct ixgbe_q_vector *q_vector =
container_of(napi, struct ixgbe_q_vector, napi);
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *tx_ring = NULL;
int work_done = 0;
long r_idx;
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
ixgbe_update_dca(q_vector);
#endif
r_idx = find_first_bit(q_vector->txr_idx, adapter->num_tx_queues);
tx_ring = adapter->tx_ring[r_idx];
if (!ixgbe_clean_tx_irq(q_vector, tx_ring))
work_done = budget;
if (work_done < budget) {
napi_complete(napi);
if (adapter->tx_itr_setting & 1)
ixgbe_set_itr_msix(q_vector);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable_queues(adapter,
((u64)1 << q_vector->v_idx));
}
return work_done;
}
static inline void map_vector_to_rxq(struct ixgbe_adapter *a, int v_idx,
int r_idx)
{
struct ixgbe_q_vector *q_vector = a->q_vector[v_idx];
struct ixgbe_ring *rx_ring = a->rx_ring[r_idx];
set_bit(r_idx, q_vector->rxr_idx);
q_vector->rxr_count++;
rx_ring->q_vector = q_vector;
}
static inline void map_vector_to_txq(struct ixgbe_adapter *a, int v_idx,
int t_idx)
{
struct ixgbe_q_vector *q_vector = a->q_vector[v_idx];
struct ixgbe_ring *tx_ring = a->tx_ring[t_idx];
set_bit(t_idx, q_vector->txr_idx);
q_vector->txr_count++;
tx_ring->q_vector = q_vector;
}
static int ixgbe_map_rings_to_vectors(struct ixgbe_adapter *adapter)
{
int q_vectors;
int v_start = 0;
int rxr_idx = 0, txr_idx = 0;
int rxr_remaining = adapter->num_rx_queues;
int txr_remaining = adapter->num_tx_queues;
int i, j;
int rqpv, tqpv;
int err = 0;
if (!(adapter->flags & IXGBE_FLAG_MSIX_ENABLED))
goto out;
q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
if (q_vectors == adapter->num_rx_queues + adapter->num_tx_queues) {
for (; rxr_idx < rxr_remaining; v_start++, rxr_idx++)
map_vector_to_rxq(adapter, v_start, rxr_idx);
for (; txr_idx < txr_remaining; v_start++, txr_idx++)
map_vector_to_txq(adapter, v_start, txr_idx);
goto out;
}
for (i = v_start; i < q_vectors; i++) {
rqpv = DIV_ROUND_UP(rxr_remaining, q_vectors - i);
for (j = 0; j < rqpv; j++) {
map_vector_to_rxq(adapter, i, rxr_idx);
rxr_idx++;
rxr_remaining--;
}
tqpv = DIV_ROUND_UP(txr_remaining, q_vectors - i);
for (j = 0; j < tqpv; j++) {
map_vector_to_txq(adapter, i, txr_idx);
txr_idx++;
txr_remaining--;
}
}
out:
return err;
}
static int ixgbe_request_msix_irqs(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
irqreturn_t (*handler)(int, void *);
int i, vector, q_vectors, err;
int ri = 0, ti = 0;
q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
err = ixgbe_map_rings_to_vectors(adapter);
if (err)
return err;
#define SET_HANDLER(_v) (((_v)->rxr_count && (_v)->txr_count) \
? &ixgbe_msix_clean_many : \
(_v)->rxr_count ? &ixgbe_msix_clean_rx : \
(_v)->txr_count ? &ixgbe_msix_clean_tx : \
NULL)
for (vector = 0; vector < q_vectors; vector++) {
struct ixgbe_q_vector *q_vector = adapter->q_vector[vector];
handler = SET_HANDLER(q_vector);
if (handler == &ixgbe_msix_clean_rx) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "rx", ri++);
} else if (handler == &ixgbe_msix_clean_tx) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "tx", ti++);
} else if (handler == &ixgbe_msix_clean_many) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "TxRx", ri++);
ti++;
} else {
continue;
}
err = request_irq(adapter->msix_entries[vector].vector,
handler, 0, q_vector->name,
q_vector);
if (err) {
e_err(probe, "request_irq failed for MSIX interrupt "
"Error: %d\n", err);
goto free_queue_irqs;
}
}
sprintf(adapter->lsc_int_name, "%s:lsc", netdev->name);
err = request_irq(adapter->msix_entries[vector].vector,
ixgbe_msix_lsc, 0, adapter->lsc_int_name, netdev);
if (err) {
e_err(probe, "request_irq for msix_lsc failed: %d\n", err);
goto free_queue_irqs;
}
return 0;
free_queue_irqs:
for (i = vector - 1; i >= 0; i--)
free_irq(adapter->msix_entries[--vector].vector,
adapter->q_vector[i]);
adapter->flags &= ~IXGBE_FLAG_MSIX_ENABLED;
pci_disable_msix(adapter->pdev);
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
return err;
}
static void ixgbe_set_itr(struct ixgbe_adapter *adapter)
{
struct ixgbe_q_vector *q_vector = adapter->q_vector[0];
struct ixgbe_ring *rx_ring = adapter->rx_ring[0];
struct ixgbe_ring *tx_ring = adapter->tx_ring[0];
u32 new_itr = q_vector->eitr;
u8 current_itr;
q_vector->tx_itr = ixgbe_update_itr(adapter, new_itr,
q_vector->tx_itr,
tx_ring->total_packets,
tx_ring->total_bytes);
q_vector->rx_itr = ixgbe_update_itr(adapter, new_itr,
q_vector->rx_itr,
rx_ring->total_packets,
rx_ring->total_bytes);
current_itr = max(q_vector->rx_itr, q_vector->tx_itr);
switch (current_itr) {
case lowest_latency:
new_itr = 100000;
break;
case low_latency:
new_itr = 20000;
break;
case bulk_latency:
new_itr = 8000;
break;
default:
break;
}
if (new_itr != q_vector->eitr) {
new_itr = ((q_vector->eitr * 9) + new_itr)/10;
q_vector->eitr = new_itr;
ixgbe_write_eitr(q_vector);
}
}
static inline void ixgbe_irq_enable(struct ixgbe_adapter *adapter, bool queues,
bool flush)
{
u32 mask;
mask = (IXGBE_EIMS_ENABLE_MASK & ~IXGBE_EIMS_RTX_QUEUE);
if (adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE)
mask |= IXGBE_EIMS_GPI_SDP0;
if (adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE)
mask |= IXGBE_EIMS_GPI_SDP1;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
mask |= IXGBE_EIMS_ECC;
mask |= IXGBE_EIMS_GPI_SDP1;
mask |= IXGBE_EIMS_GPI_SDP2;
if (adapter->num_vfs)
mask |= IXGBE_EIMS_MAILBOX;
break;
default:
break;
}
if (adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE ||
adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE)
mask |= IXGBE_EIMS_FLOW_DIR;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMS, mask);
if (queues)
ixgbe_irq_enable_queues(adapter, ~0);
if (flush)
IXGBE_WRITE_FLUSH(&adapter->hw);
if (adapter->num_vfs > 32) {
u32 eitrsel = (1 << (adapter->num_vfs - 32)) - 1;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EITRSEL, eitrsel);
}
}
static irqreturn_t ixgbe_intr(int irq, void *data)
{
struct net_device *netdev = data;
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_q_vector *q_vector = adapter->q_vector[0];
u32 eicr;
IXGBE_WRITE_REG(hw, IXGBE_EIMC, IXGBE_IRQ_CLEAR_MASK);
eicr = IXGBE_READ_REG(hw, IXGBE_EICR);
if (!eicr) {
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable(adapter, true, true);
return IRQ_NONE;
}
if (eicr & IXGBE_EICR_LSC)
ixgbe_check_lsc(adapter);
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
ixgbe_check_sfp_event(adapter, eicr);
if ((adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE) &&
((eicr & IXGBE_EICR_GPI_SDP0) || (eicr & IXGBE_EICR_LSC))) {
if (!test_bit(__IXGBE_DOWN, &adapter->state)) {
adapter->interrupt_event = eicr;
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_EVENT;
ixgbe_service_event_schedule(adapter);
}
}
break;
default:
break;
}
ixgbe_check_fan_failure(adapter, eicr);
if (napi_schedule_prep(&(q_vector->napi))) {
adapter->tx_ring[0]->total_packets = 0;
adapter->tx_ring[0]->total_bytes = 0;
adapter->rx_ring[0]->total_packets = 0;
adapter->rx_ring[0]->total_bytes = 0;
__napi_schedule(&(q_vector->napi));
}
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable(adapter, false, false);
return IRQ_HANDLED;
}
static inline void ixgbe_reset_q_vectors(struct ixgbe_adapter *adapter)
{
int i, q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (i = 0; i < q_vectors; i++) {
struct ixgbe_q_vector *q_vector = adapter->q_vector[i];
bitmap_zero(q_vector->rxr_idx, MAX_RX_QUEUES);
bitmap_zero(q_vector->txr_idx, MAX_TX_QUEUES);
q_vector->rxr_count = 0;
q_vector->txr_count = 0;
}
}
static int ixgbe_request_irq(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int err;
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED) {
err = ixgbe_request_msix_irqs(adapter);
} else if (adapter->flags & IXGBE_FLAG_MSI_ENABLED) {
err = request_irq(adapter->pdev->irq, ixgbe_intr, 0,
netdev->name, netdev);
} else {
err = request_irq(adapter->pdev->irq, ixgbe_intr, IRQF_SHARED,
netdev->name, netdev);
}
if (err)
e_err(probe, "request_irq failed, Error %d\n", err);
return err;
}
static void ixgbe_free_irq(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED) {
int i, q_vectors;
q_vectors = adapter->num_msix_vectors;
i = q_vectors - 1;
free_irq(adapter->msix_entries[i].vector, netdev);
i--;
for (; i >= 0; i--) {
if (!adapter->q_vector[i]->rxr_count &&
!adapter->q_vector[i]->txr_count)
continue;
free_irq(adapter->msix_entries[i].vector,
adapter->q_vector[i]);
}
ixgbe_reset_q_vectors(adapter);
} else {
free_irq(adapter->pdev->irq, netdev);
}
}
static inline void ixgbe_irq_disable(struct ixgbe_adapter *adapter)
{
switch (adapter->hw.mac.type) {
case ixgbe_mac_82598EB:
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC, ~0);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC, 0xFFFF0000);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC_EX(0), ~0);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC_EX(1), ~0);
if (adapter->num_vfs > 32)
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EITRSEL, 0);
break;
default:
break;
}
IXGBE_WRITE_FLUSH(&adapter->hw);
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED) {
int i;
for (i = 0; i < adapter->num_msix_vectors; i++)
synchronize_irq(adapter->msix_entries[i].vector);
} else {
synchronize_irq(adapter->pdev->irq);
}
}
static void ixgbe_configure_msi_and_legacy(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
IXGBE_WRITE_REG(hw, IXGBE_EITR(0),
EITR_INTS_PER_SEC_TO_REG(adapter->rx_eitr_param));
ixgbe_set_ivar(adapter, 0, 0, 0);
ixgbe_set_ivar(adapter, 1, 0, 0);
map_vector_to_rxq(adapter, 0, 0);
map_vector_to_txq(adapter, 0, 0);
e_info(hw, "Legacy interrupt IVAR setup done\n");
}
void ixgbe_configure_tx_ring(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u64 tdba = ring->dma;
int wait_loop = 10;
u32 txdctl;
u8 reg_idx = ring->reg_idx;
txdctl = IXGBE_READ_REG(hw, IXGBE_TXDCTL(reg_idx));
IXGBE_WRITE_REG(hw, IXGBE_TXDCTL(reg_idx),
txdctl & ~IXGBE_TXDCTL_ENABLE);
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_TDBAL(reg_idx),
(tdba & DMA_BIT_MASK(32)));
IXGBE_WRITE_REG(hw, IXGBE_TDBAH(reg_idx), (tdba >> 32));
IXGBE_WRITE_REG(hw, IXGBE_TDLEN(reg_idx),
ring->count * sizeof(union ixgbe_adv_tx_desc));
IXGBE_WRITE_REG(hw, IXGBE_TDH(reg_idx), 0);
IXGBE_WRITE_REG(hw, IXGBE_TDT(reg_idx), 0);
ring->tail = hw->hw_addr + IXGBE_TDT(reg_idx);
if (adapter->rx_itr_setting == 0) {
txdctl &= ~0x007F0000;
} else {
txdctl |= (8 << 16);
}
if (adapter->flags & IXGBE_FLAG_DCB_ENABLED) {
txdctl |= 32;
}
if ((adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) &&
adapter->atr_sample_rate) {
ring->atr_sample_rate = adapter->atr_sample_rate;
ring->atr_count = 0;
set_bit(__IXGBE_TX_FDIR_INIT_DONE, &ring->state);
} else {
ring->atr_sample_rate = 0;
}
clear_bit(__IXGBE_HANG_CHECK_ARMED, &ring->state);
txdctl |= IXGBE_TXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_TXDCTL(reg_idx), txdctl);
if (hw->mac.type == ixgbe_mac_82598EB &&
!(IXGBE_READ_REG(hw, IXGBE_LINKS) & IXGBE_LINKS_UP))
return;
do {
usleep_range(1000, 2000);
txdctl = IXGBE_READ_REG(hw, IXGBE_TXDCTL(reg_idx));
} while (--wait_loop && !(txdctl & IXGBE_TXDCTL_ENABLE));
if (!wait_loop)
e_err(drv, "Could not enable Tx Queue %d\n", reg_idx);
}
static void ixgbe_setup_mtqc(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 rttdcs;
u32 mask;
if (hw->mac.type == ixgbe_mac_82598EB)
return;
rttdcs = IXGBE_READ_REG(hw, IXGBE_RTTDCS);
rttdcs |= IXGBE_RTTDCS_ARBDIS;
IXGBE_WRITE_REG(hw, IXGBE_RTTDCS, rttdcs);
mask = (IXGBE_FLAG_SRIOV_ENABLED | IXGBE_FLAG_DCB_ENABLED);
switch (adapter->flags & mask) {
case (IXGBE_FLAG_SRIOV_ENABLED):
IXGBE_WRITE_REG(hw, IXGBE_MTQC,
(IXGBE_MTQC_VT_ENA | IXGBE_MTQC_64VF));
break;
case (IXGBE_FLAG_DCB_ENABLED):
IXGBE_WRITE_REG(hw, IXGBE_MTQC,
(IXGBE_MTQC_RT_ENA | IXGBE_MTQC_8TC_8TQ));
break;
default:
IXGBE_WRITE_REG(hw, IXGBE_MTQC, IXGBE_MTQC_64Q_1PB);
break;
}
rttdcs &= ~IXGBE_RTTDCS_ARBDIS;
IXGBE_WRITE_REG(hw, IXGBE_RTTDCS, rttdcs);
}
static void ixgbe_configure_tx(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 dmatxctl;
u32 i;
ixgbe_setup_mtqc(adapter);
if (hw->mac.type != ixgbe_mac_82598EB) {
dmatxctl = IXGBE_READ_REG(hw, IXGBE_DMATXCTL);
dmatxctl |= IXGBE_DMATXCTL_TE;
IXGBE_WRITE_REG(hw, IXGBE_DMATXCTL, dmatxctl);
}
for (i = 0; i < adapter->num_tx_queues; i++)
ixgbe_configure_tx_ring(adapter, adapter->tx_ring[i]);
}
static void ixgbe_configure_srrctl(struct ixgbe_adapter *adapter,
struct ixgbe_ring *rx_ring)
{
u32 srrctl;
u8 reg_idx = rx_ring->reg_idx;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82598EB: {
struct ixgbe_ring_feature *feature = adapter->ring_feature;
const int mask = feature[RING_F_RSS].mask;
reg_idx = reg_idx & mask;
}
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
default:
break;
}
srrctl = IXGBE_READ_REG(&adapter->hw, IXGBE_SRRCTL(reg_idx));
srrctl &= ~IXGBE_SRRCTL_BSIZEHDR_MASK;
srrctl &= ~IXGBE_SRRCTL_BSIZEPKT_MASK;
if (adapter->num_vfs)
srrctl |= IXGBE_SRRCTL_DROP_EN;
srrctl |= (IXGBE_RX_HDR_SIZE << IXGBE_SRRCTL_BSIZEHDRSIZE_SHIFT) &
IXGBE_SRRCTL_BSIZEHDR_MASK;
if (ring_is_ps_enabled(rx_ring)) {
#if (PAGE_SIZE / 2) > IXGBE_MAX_RXBUFFER
srrctl |= IXGBE_MAX_RXBUFFER >> IXGBE_SRRCTL_BSIZEPKT_SHIFT;
#else
srrctl |= (PAGE_SIZE / 2) >> IXGBE_SRRCTL_BSIZEPKT_SHIFT;
#endif
srrctl |= IXGBE_SRRCTL_DESCTYPE_HDR_SPLIT_ALWAYS;
} else {
srrctl |= ALIGN(rx_ring->rx_buf_len, 1024) >>
IXGBE_SRRCTL_BSIZEPKT_SHIFT;
srrctl |= IXGBE_SRRCTL_DESCTYPE_ADV_ONEBUF;
}
IXGBE_WRITE_REG(&adapter->hw, IXGBE_SRRCTL(reg_idx), srrctl);
}
static void ixgbe_setup_mrqc(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
static const u32 seed[10] = { 0xE291D73D, 0x1805EC6C, 0x2A94B30D,
0xA54F2BEC, 0xEA49AF7C, 0xE214AD3D, 0xB855AABE,
0x6A3E67EA, 0x14364D17, 0x3BED200D};
u32 mrqc = 0, reta = 0;
u32 rxcsum;
int i, j;
int mask;
for (i = 0; i < 10; i++)
IXGBE_WRITE_REG(hw, IXGBE_RSSRK(i), seed[i]);
for (i = 0, j = 0; i < 128; i++, j++) {
if (j == adapter->ring_feature[RING_F_RSS].indices)
j = 0;
reta = (reta << 8) | (j * 0x11);
if ((i & 3) == 3)
IXGBE_WRITE_REG(hw, IXGBE_RETA(i >> 2), reta);
}
rxcsum = IXGBE_READ_REG(hw, IXGBE_RXCSUM);
rxcsum |= IXGBE_RXCSUM_PCSD;
IXGBE_WRITE_REG(hw, IXGBE_RXCSUM, rxcsum);
if (adapter->hw.mac.type == ixgbe_mac_82598EB)
mask = adapter->flags & IXGBE_FLAG_RSS_ENABLED;
else
mask = adapter->flags & (IXGBE_FLAG_RSS_ENABLED
#ifdef CONFIG_IXGBE_DCB
| IXGBE_FLAG_DCB_ENABLED
#endif
| IXGBE_FLAG_SRIOV_ENABLED
);
switch (mask) {
#ifdef CONFIG_IXGBE_DCB
case (IXGBE_FLAG_DCB_ENABLED | IXGBE_FLAG_RSS_ENABLED):
mrqc = IXGBE_MRQC_RTRSS8TCEN;
break;
case (IXGBE_FLAG_DCB_ENABLED):
mrqc = IXGBE_MRQC_RT8TCEN;
break;
#endif
case (IXGBE_FLAG_RSS_ENABLED):
mrqc = IXGBE_MRQC_RSSEN;
break;
case (IXGBE_FLAG_SRIOV_ENABLED):
mrqc = IXGBE_MRQC_VMDQEN;
break;
default:
break;
}
mrqc |= IXGBE_MRQC_RSS_FIELD_IPV4
| IXGBE_MRQC_RSS_FIELD_IPV4_TCP
| IXGBE_MRQC_RSS_FIELD_IPV6
| IXGBE_MRQC_RSS_FIELD_IPV6_TCP;
IXGBE_WRITE_REG(hw, IXGBE_MRQC, mrqc);
}
void ixgbe_clear_rscctl(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 rscctrl;
u8 reg_idx = ring->reg_idx;
rscctrl = IXGBE_READ_REG(hw, IXGBE_RSCCTL(reg_idx));
rscctrl &= ~IXGBE_RSCCTL_RSCEN;
IXGBE_WRITE_REG(hw, IXGBE_RSCCTL(reg_idx), rscctrl);
}
void ixgbe_configure_rscctl(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 rscctrl;
int rx_buf_len;
u8 reg_idx = ring->reg_idx;
if (!ring_is_rsc_enabled(ring))
return;
rx_buf_len = ring->rx_buf_len;
rscctrl = IXGBE_READ_REG(hw, IXGBE_RSCCTL(reg_idx));
rscctrl |= IXGBE_RSCCTL_RSCEN;
if (ring_is_ps_enabled(ring)) {
#if (MAX_SKB_FRAGS > 16)
rscctrl |= IXGBE_RSCCTL_MAXDESC_16;
#elif (MAX_SKB_FRAGS > 8)
rscctrl |= IXGBE_RSCCTL_MAXDESC_8;
#elif (MAX_SKB_FRAGS > 4)
rscctrl |= IXGBE_RSCCTL_MAXDESC_4;
#else
rscctrl |= IXGBE_RSCCTL_MAXDESC_1;
#endif
} else {
if (rx_buf_len < IXGBE_RXBUFFER_4096)
rscctrl |= IXGBE_RSCCTL_MAXDESC_16;
else if (rx_buf_len < IXGBE_RXBUFFER_8192)
rscctrl |= IXGBE_RSCCTL_MAXDESC_8;
else
rscctrl |= IXGBE_RSCCTL_MAXDESC_4;
}
IXGBE_WRITE_REG(hw, IXGBE_RSCCTL(reg_idx), rscctrl);
}
static void ixgbe_set_uta(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int i;
if (hw->mac.type < ixgbe_mac_82599EB)
return;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return;
for (i = 0; i < 128; i++)
IXGBE_WRITE_REG(hw, IXGBE_UTA(i), ~0);
}
static void ixgbe_rx_desc_queue_enable(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
int wait_loop = IXGBE_MAX_RX_DESC_POLL;
u32 rxdctl;
u8 reg_idx = ring->reg_idx;
if (hw->mac.type == ixgbe_mac_82598EB &&
!(IXGBE_READ_REG(hw, IXGBE_LINKS) & IXGBE_LINKS_UP))
return;
do {
usleep_range(1000, 2000);
rxdctl = IXGBE_READ_REG(hw, IXGBE_RXDCTL(reg_idx));
} while (--wait_loop && !(rxdctl & IXGBE_RXDCTL_ENABLE));
if (!wait_loop) {
e_err(drv, "RXDCTL.ENABLE on Rx queue %d not set within "
"the polling period\n", reg_idx);
}
}
void ixgbe_disable_rx_queue(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
int wait_loop = IXGBE_MAX_RX_DESC_POLL;
u32 rxdctl;
u8 reg_idx = ring->reg_idx;
rxdctl = IXGBE_READ_REG(hw, IXGBE_RXDCTL(reg_idx));
rxdctl &= ~IXGBE_RXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_RXDCTL(reg_idx), rxdctl);
if (hw->mac.type == ixgbe_mac_82598EB &&
!(IXGBE_READ_REG(hw, IXGBE_LINKS) & IXGBE_LINKS_UP))
return;
do {
udelay(10);
rxdctl = IXGBE_READ_REG(hw, IXGBE_RXDCTL(reg_idx));
} while (--wait_loop && (rxdctl & IXGBE_RXDCTL_ENABLE));
if (!wait_loop) {
e_err(drv, "RXDCTL.ENABLE on Rx queue %d not cleared within "
"the polling period\n", reg_idx);
}
}
void ixgbe_configure_rx_ring(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u64 rdba = ring->dma;
u32 rxdctl;
u8 reg_idx = ring->reg_idx;
rxdctl = IXGBE_READ_REG(hw, IXGBE_RXDCTL(reg_idx));
ixgbe_disable_rx_queue(adapter, ring);
IXGBE_WRITE_REG(hw, IXGBE_RDBAL(reg_idx), (rdba & DMA_BIT_MASK(32)));
IXGBE_WRITE_REG(hw, IXGBE_RDBAH(reg_idx), (rdba >> 32));
IXGBE_WRITE_REG(hw, IXGBE_RDLEN(reg_idx),
ring->count * sizeof(union ixgbe_adv_rx_desc));
IXGBE_WRITE_REG(hw, IXGBE_RDH(reg_idx), 0);
IXGBE_WRITE_REG(hw, IXGBE_RDT(reg_idx), 0);
ring->tail = hw->hw_addr + IXGBE_RDT(reg_idx);
ixgbe_configure_srrctl(adapter, ring);
ixgbe_configure_rscctl(adapter, ring);
if ((adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) &&
hw->mac.type == ixgbe_mac_X540) {
rxdctl &= ~IXGBE_RXDCTL_RLPMLMASK;
rxdctl |= ((ring->netdev->mtu + ETH_HLEN +
ETH_FCS_LEN + VLAN_HLEN) | IXGBE_RXDCTL_RLPML_EN);
}
if (hw->mac.type == ixgbe_mac_82598EB) {
rxdctl &= ~0x3FFFFF;
rxdctl |= 0x080420;
}
rxdctl |= IXGBE_RXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_RXDCTL(reg_idx), rxdctl);
ixgbe_rx_desc_queue_enable(adapter, ring);
ixgbe_alloc_rx_buffers(ring, IXGBE_DESC_UNUSED(ring));
}
static void ixgbe_setup_psrtype(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int p;
u32 psrtype = IXGBE_PSRTYPE_TCPHDR |
IXGBE_PSRTYPE_UDPHDR |
IXGBE_PSRTYPE_IPV4HDR |
IXGBE_PSRTYPE_L2HDR |
IXGBE_PSRTYPE_IPV6HDR;
if (hw->mac.type == ixgbe_mac_82598EB)
return;
if (adapter->flags & IXGBE_FLAG_RSS_ENABLED)
psrtype |= (adapter->num_rx_queues_per_pool << 29);
for (p = 0; p < adapter->num_rx_pools; p++)
IXGBE_WRITE_REG(hw, IXGBE_PSRTYPE(adapter->num_vfs + p),
psrtype);
}
static void ixgbe_configure_virtualization(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 gcr_ext;
u32 vt_reg_bits;
u32 reg_offset, vf_shift;
u32 vmdctl;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return;
vmdctl = IXGBE_READ_REG(hw, IXGBE_VT_CTL);
vt_reg_bits = IXGBE_VMD_CTL_VMDQ_EN | IXGBE_VT_CTL_REPLEN;
vt_reg_bits |= (adapter->num_vfs << IXGBE_VT_CTL_POOL_SHIFT);
IXGBE_WRITE_REG(hw, IXGBE_VT_CTL, vmdctl | vt_reg_bits);
vf_shift = adapter->num_vfs % 32;
reg_offset = (adapter->num_vfs > 32) ? 1 : 0;
IXGBE_WRITE_REG(hw, IXGBE_VFRE(reg_offset), (1 << vf_shift));
IXGBE_WRITE_REG(hw, IXGBE_VFRE(reg_offset ^ 1), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFTE(reg_offset), (1 << vf_shift));
IXGBE_WRITE_REG(hw, IXGBE_VFTE(reg_offset ^ 1), 0);
IXGBE_WRITE_REG(hw, IXGBE_PFDTXGSWC, IXGBE_PFDTXGSWC_VT_LBEN);
hw->mac.ops.set_vmdq(hw, 0, adapter->num_vfs);
gcr_ext = IXGBE_READ_REG(hw, IXGBE_GCR_EXT);
gcr_ext |= IXGBE_GCR_EXT_MSIX_EN;
gcr_ext |= IXGBE_GCR_EXT_VT_MODE_64;
IXGBE_WRITE_REG(hw, IXGBE_GCR_EXT, gcr_ext);
IXGBE_WRITE_REG(hw, IXGBE_PFDTXGSWC, IXGBE_PFDTXGSWC_VT_LBEN);
hw->mac.ops.set_mac_anti_spoofing(hw,
(adapter->antispoofing_enabled =
(adapter->num_vfs != 0)),
adapter->num_vfs);
}
static void ixgbe_set_rx_buffer_len(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
int max_frame = netdev->mtu + ETH_HLEN + ETH_FCS_LEN;
int rx_buf_len;
struct ixgbe_ring *rx_ring;
int i;
u32 mhadd, hlreg0;
adapter->flags |= IXGBE_FLAG_RX_PS_ENABLED;
if (adapter->num_vfs)
adapter->flags &= ~IXGBE_FLAG_RX_PS_ENABLED;
if (hw->mac.type == ixgbe_mac_82599EB)
adapter->flags &= ~IXGBE_FLAG_RX_PS_ENABLED;
if (adapter->flags & IXGBE_FLAG_RX_PS_ENABLED) {
rx_buf_len = IXGBE_RX_HDR_SIZE;
} else {
if (!(adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED) &&
(netdev->mtu <= ETH_DATA_LEN))
rx_buf_len = MAXIMUM_ETHERNET_VLAN_SIZE;
else
rx_buf_len = ALIGN(max_frame + VLAN_HLEN, 1024);
}
#ifdef IXGBE_FCOE
if ((adapter->flags & IXGBE_FLAG_FCOE_ENABLED) &&
(max_frame < IXGBE_FCOE_JUMBO_FRAME_SIZE))
max_frame = IXGBE_FCOE_JUMBO_FRAME_SIZE;
#endif
mhadd = IXGBE_READ_REG(hw, IXGBE_MHADD);
if (max_frame != (mhadd >> IXGBE_MHADD_MFS_SHIFT)) {
mhadd &= ~IXGBE_MHADD_MFS_MASK;
mhadd |= max_frame << IXGBE_MHADD_MFS_SHIFT;
IXGBE_WRITE_REG(hw, IXGBE_MHADD, mhadd);
}
hlreg0 = IXGBE_READ_REG(hw, IXGBE_HLREG0);
hlreg0 |= IXGBE_HLREG0_JUMBOEN;
IXGBE_WRITE_REG(hw, IXGBE_HLREG0, hlreg0);
for (i = 0; i < adapter->num_rx_queues; i++) {
rx_ring = adapter->rx_ring[i];
rx_ring->rx_buf_len = rx_buf_len;
if (adapter->flags & IXGBE_FLAG_RX_PS_ENABLED)
set_ring_ps_enabled(rx_ring);
else
clear_ring_ps_enabled(rx_ring);
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)
set_ring_rsc_enabled(rx_ring);
else
clear_ring_rsc_enabled(rx_ring);
#ifdef IXGBE_FCOE
if (netdev->features & NETIF_F_FCOE_MTU) {
struct ixgbe_ring_feature *f;
f = &adapter->ring_feature[RING_F_FCOE];
if ((i >= f->mask) && (i < f->mask + f->indices)) {
clear_ring_ps_enabled(rx_ring);
if (rx_buf_len < IXGBE_FCOE_JUMBO_FRAME_SIZE)
rx_ring->rx_buf_len =
IXGBE_FCOE_JUMBO_FRAME_SIZE;
} else if (!ring_is_rsc_enabled(rx_ring) &&
!ring_is_ps_enabled(rx_ring)) {
rx_ring->rx_buf_len =
IXGBE_FCOE_JUMBO_FRAME_SIZE;
}
}
#endif
}
}
static void ixgbe_setup_rdrxctl(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 rdrxctl = IXGBE_READ_REG(hw, IXGBE_RDRXCTL);
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
rdrxctl |= IXGBE_RDRXCTL_MVMEN;
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
IXGBE_WRITE_REG(hw, IXGBE_RSCDBU,
(IXGBE_RSCDBU_RSCACKDIS | IXGBE_READ_REG(hw, IXGBE_RSCDBU)));
rdrxctl &= ~IXGBE_RDRXCTL_RSCFRSTSIZE;
rdrxctl |= (IXGBE_RDRXCTL_RSCACKC | IXGBE_RDRXCTL_FCOE_WRFIX);
rdrxctl |= IXGBE_RDRXCTL_CRCSTRIP;
break;
default:
return;
}
IXGBE_WRITE_REG(hw, IXGBE_RDRXCTL, rdrxctl);
}
static void ixgbe_configure_rx(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int i;
u32 rxctrl;
rxctrl = IXGBE_READ_REG(hw, IXGBE_RXCTRL);
IXGBE_WRITE_REG(hw, IXGBE_RXCTRL, rxctrl & ~IXGBE_RXCTRL_RXEN);
ixgbe_setup_psrtype(adapter);
ixgbe_setup_rdrxctl(adapter);
ixgbe_setup_mrqc(adapter);
ixgbe_set_uta(adapter);
ixgbe_set_rx_buffer_len(adapter);
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbe_configure_rx_ring(adapter, adapter->rx_ring[i]);
if (hw->mac.type == ixgbe_mac_82598EB)
rxctrl |= IXGBE_RXCTRL_DMBYPS;
rxctrl |= IXGBE_RXCTRL_RXEN;
hw->mac.ops.enable_rx_dma(hw, rxctrl);
}
static void ixgbe_vlan_rx_add_vid(struct net_device *netdev, u16 vid)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int pool_ndx = adapter->num_vfs;
hw->mac.ops.set_vfta(&adapter->hw, vid, pool_ndx, true);
set_bit(vid, adapter->active_vlans);
}
static void ixgbe_vlan_rx_kill_vid(struct net_device *netdev, u16 vid)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int pool_ndx = adapter->num_vfs;
hw->mac.ops.set_vfta(&adapter->hw, vid, pool_ndx, false);
clear_bit(vid, adapter->active_vlans);
}
static void ixgbe_vlan_filter_disable(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vlnctrl;
vlnctrl = IXGBE_READ_REG(hw, IXGBE_VLNCTRL);
vlnctrl &= ~(IXGBE_VLNCTRL_VFE | IXGBE_VLNCTRL_CFIEN);
IXGBE_WRITE_REG(hw, IXGBE_VLNCTRL, vlnctrl);
}
static void ixgbe_vlan_filter_enable(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vlnctrl;
vlnctrl = IXGBE_READ_REG(hw, IXGBE_VLNCTRL);
vlnctrl |= IXGBE_VLNCTRL_VFE;
vlnctrl &= ~IXGBE_VLNCTRL_CFIEN;
IXGBE_WRITE_REG(hw, IXGBE_VLNCTRL, vlnctrl);
}
static void ixgbe_vlan_strip_disable(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vlnctrl;
int i, j;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
vlnctrl = IXGBE_READ_REG(hw, IXGBE_VLNCTRL);
vlnctrl &= ~IXGBE_VLNCTRL_VME;
IXGBE_WRITE_REG(hw, IXGBE_VLNCTRL, vlnctrl);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
for (i = 0; i < adapter->num_rx_queues; i++) {
j = adapter->rx_ring[i]->reg_idx;
vlnctrl = IXGBE_READ_REG(hw, IXGBE_RXDCTL(j));
vlnctrl &= ~IXGBE_RXDCTL_VME;
IXGBE_WRITE_REG(hw, IXGBE_RXDCTL(j), vlnctrl);
}
break;
default:
break;
}
}
static void ixgbe_vlan_strip_enable(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vlnctrl;
int i, j;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
vlnctrl = IXGBE_READ_REG(hw, IXGBE_VLNCTRL);
vlnctrl |= IXGBE_VLNCTRL_VME;
IXGBE_WRITE_REG(hw, IXGBE_VLNCTRL, vlnctrl);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
for (i = 0; i < adapter->num_rx_queues; i++) {
j = adapter->rx_ring[i]->reg_idx;
vlnctrl = IXGBE_READ_REG(hw, IXGBE_RXDCTL(j));
vlnctrl |= IXGBE_RXDCTL_VME;
IXGBE_WRITE_REG(hw, IXGBE_RXDCTL(j), vlnctrl);
}
break;
default:
break;
}
}
static void ixgbe_restore_vlan(struct ixgbe_adapter *adapter)
{
u16 vid;
ixgbe_vlan_rx_add_vid(adapter->netdev, 0);
for_each_set_bit(vid, adapter->active_vlans, VLAN_N_VID)
ixgbe_vlan_rx_add_vid(adapter->netdev, vid);
}
static int ixgbe_write_uc_addr_list(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
unsigned int vfn = adapter->num_vfs;
unsigned int rar_entries = IXGBE_MAX_PF_MACVLANS;
int count = 0;
if (netdev_uc_count(netdev) > rar_entries)
return -ENOMEM;
if (!netdev_uc_empty(netdev) && rar_entries) {
struct netdev_hw_addr *ha;
if (!hw->mac.ops.set_rar)
return -ENOMEM;
netdev_for_each_uc_addr(ha, netdev) {
if (!rar_entries)
break;
hw->mac.ops.set_rar(hw, rar_entries--, ha->addr,
vfn, IXGBE_RAH_AV);
count++;
}
}
for (; rar_entries > 0 ; rar_entries--)
hw->mac.ops.clear_rar(hw, rar_entries);
return count;
}
void ixgbe_set_rx_mode(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
u32 fctrl, vmolr = IXGBE_VMOLR_BAM | IXGBE_VMOLR_AUPE;
int count;
fctrl = IXGBE_READ_REG(hw, IXGBE_FCTRL);
fctrl |= IXGBE_FCTRL_BAM;
fctrl |= IXGBE_FCTRL_DPF;
fctrl |= IXGBE_FCTRL_PMCF;
fctrl &= ~(IXGBE_FCTRL_UPE | IXGBE_FCTRL_MPE);
if (netdev->flags & IFF_PROMISC) {
hw->addr_ctrl.user_set_promisc = true;
fctrl |= (IXGBE_FCTRL_UPE | IXGBE_FCTRL_MPE);
vmolr |= (IXGBE_VMOLR_ROPE | IXGBE_VMOLR_MPE);
ixgbe_vlan_filter_disable(adapter);
} else {
if (netdev->flags & IFF_ALLMULTI) {
fctrl |= IXGBE_FCTRL_MPE;
vmolr |= IXGBE_VMOLR_MPE;
} else {
hw->mac.ops.update_mc_addr_list(hw, netdev);
vmolr |= IXGBE_VMOLR_ROMPE;
}
ixgbe_vlan_filter_enable(adapter);
hw->addr_ctrl.user_set_promisc = false;
count = ixgbe_write_uc_addr_list(netdev);
if (count < 0) {
fctrl |= IXGBE_FCTRL_UPE;
vmolr |= IXGBE_VMOLR_ROPE;
}
}
if (adapter->num_vfs) {
ixgbe_restore_vf_multicasts(adapter);
vmolr |= IXGBE_READ_REG(hw, IXGBE_VMOLR(adapter->num_vfs)) &
~(IXGBE_VMOLR_MPE | IXGBE_VMOLR_ROMPE |
IXGBE_VMOLR_ROPE);
IXGBE_WRITE_REG(hw, IXGBE_VMOLR(adapter->num_vfs), vmolr);
}
IXGBE_WRITE_REG(hw, IXGBE_FCTRL, fctrl);
if (netdev->features & NETIF_F_HW_VLAN_RX)
ixgbe_vlan_strip_enable(adapter);
else
ixgbe_vlan_strip_disable(adapter);
}
static void ixgbe_napi_enable_all(struct ixgbe_adapter *adapter)
{
int q_idx;
struct ixgbe_q_vector *q_vector;
int q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
if (!(adapter->flags & IXGBE_FLAG_MSIX_ENABLED))
q_vectors = 1;
for (q_idx = 0; q_idx < q_vectors; q_idx++) {
struct napi_struct *napi;
q_vector = adapter->q_vector[q_idx];
napi = &q_vector->napi;
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED) {
if (!q_vector->rxr_count || !q_vector->txr_count) {
if (q_vector->txr_count == 1)
napi->poll = &ixgbe_clean_txonly;
else if (q_vector->rxr_count == 1)
napi->poll = &ixgbe_clean_rxonly;
}
}
napi_enable(napi);
}
}
static void ixgbe_napi_disable_all(struct ixgbe_adapter *adapter)
{
int q_idx;
struct ixgbe_q_vector *q_vector;
int q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
if (!(adapter->flags & IXGBE_FLAG_MSIX_ENABLED))
q_vectors = 1;
for (q_idx = 0; q_idx < q_vectors; q_idx++) {
q_vector = adapter->q_vector[q_idx];
napi_disable(&q_vector->napi);
}
}
static void ixgbe_configure_dcb(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int max_frame = adapter->netdev->mtu + ETH_HLEN + ETH_FCS_LEN;
if (!(adapter->flags & IXGBE_FLAG_DCB_ENABLED)) {
if (hw->mac.type == ixgbe_mac_82598EB)
netif_set_gso_max_size(adapter->netdev, 65536);
return;
}
if (hw->mac.type == ixgbe_mac_82598EB)
netif_set_gso_max_size(adapter->netdev, 32768);
adapter->netdev->features |= NETIF_F_HW_VLAN_RX;
hw->mac.ops.set_vfta(&adapter->hw, 0, 0, true);
if (adapter->dcbx_cap & (DCB_CAP_DCBX_HOST | DCB_CAP_DCBX_VER_CEE)) {
#ifdef CONFIG_FCOE
if (adapter->netdev->features & NETIF_F_FCOE_MTU)
max_frame = max(max_frame, IXGBE_FCOE_JUMBO_FRAME_SIZE);
#endif
ixgbe_dcb_calculate_tc_credits(hw, &adapter->dcb_cfg, max_frame,
DCB_TX_CONFIG);
ixgbe_dcb_calculate_tc_credits(hw, &adapter->dcb_cfg, max_frame,
DCB_RX_CONFIG);
ixgbe_dcb_hw_config(hw, &adapter->dcb_cfg);
} else {
struct net_device *dev = adapter->netdev;
if (adapter->ixgbe_ieee_ets)
dev->dcbnl_ops->ieee_setets(dev,
adapter->ixgbe_ieee_ets);
if (adapter->ixgbe_ieee_pfc)
dev->dcbnl_ops->ieee_setpfc(dev,
adapter->ixgbe_ieee_pfc);
}
if (hw->mac.type != ixgbe_mac_82598EB) {
int i;
u32 reg = 0;
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
u8 msb = 0;
u8 cnt = adapter->netdev->tc_to_txq[i].count;
while (cnt >>= 1)
msb++;
reg |= msb << IXGBE_RQTC_SHIFT_TC(i);
}
IXGBE_WRITE_REG(hw, IXGBE_RQTC, reg);
}
}
static void ixgbe_configure(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
int i;
#ifdef CONFIG_IXGBE_DCB
ixgbe_configure_dcb(adapter);
#endif
ixgbe_set_rx_mode(netdev);
ixgbe_restore_vlan(adapter);
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED)
ixgbe_configure_fcoe(adapter);
#endif
if (adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) {
for (i = 0; i < adapter->num_tx_queues; i++)
adapter->tx_ring[i]->atr_sample_rate =
adapter->atr_sample_rate;
ixgbe_init_fdir_signature_82599(hw, adapter->fdir_pballoc);
} else if (adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE) {
ixgbe_init_fdir_perfect_82599(hw, adapter->fdir_pballoc);
}
ixgbe_configure_virtualization(adapter);
ixgbe_configure_tx(adapter);
ixgbe_configure_rx(adapter);
}
static inline bool ixgbe_is_sfp(struct ixgbe_hw *hw)
{
switch (hw->phy.type) {
case ixgbe_phy_sfp_avago:
case ixgbe_phy_sfp_ftl:
case ixgbe_phy_sfp_intel:
case ixgbe_phy_sfp_unknown:
case ixgbe_phy_sfp_passive_tyco:
case ixgbe_phy_sfp_passive_unknown:
case ixgbe_phy_sfp_active_unknown:
case ixgbe_phy_sfp_ftl_active:
return true;
default:
return false;
}
}
static void ixgbe_sfp_link_config(struct ixgbe_adapter *adapter)
{
if (adapter->hw.mac.type == ixgbe_mac_82598EB)
adapter->flags2 |= IXGBE_FLAG2_SEARCH_FOR_SFP;
adapter->flags2 |= IXGBE_FLAG2_SFP_NEEDS_RESET;
}
static int ixgbe_non_sfp_link_config(struct ixgbe_hw *hw)
{
u32 autoneg;
bool negotiation, link_up = false;
u32 ret = IXGBE_ERR_LINK_SETUP;
if (hw->mac.ops.check_link)
ret = hw->mac.ops.check_link(hw, &autoneg, &link_up, false);
if (ret)
goto link_cfg_out;
autoneg = hw->phy.autoneg_advertised;
if ((!autoneg) && (hw->mac.ops.get_link_capabilities))
ret = hw->mac.ops.get_link_capabilities(hw, &autoneg,
&negotiation);
if (ret)
goto link_cfg_out;
if (hw->mac.ops.setup_link)
ret = hw->mac.ops.setup_link(hw, autoneg, negotiation, link_up);
link_cfg_out:
return ret;
}
static void ixgbe_setup_gpie(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 gpie = 0;
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED) {
gpie = IXGBE_GPIE_MSIX_MODE | IXGBE_GPIE_PBA_SUPPORT |
IXGBE_GPIE_OCD;
gpie |= IXGBE_GPIE_EIAME;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
IXGBE_WRITE_REG(hw, IXGBE_EIAM, IXGBE_EICS_RTX_QUEUE);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
default:
IXGBE_WRITE_REG(hw, IXGBE_EIAM_EX(0), 0xFFFFFFFF);
IXGBE_WRITE_REG(hw, IXGBE_EIAM_EX(1), 0xFFFFFFFF);
break;
}
} else {
IXGBE_WRITE_REG(hw, IXGBE_EIAM, IXGBE_EICS_RTX_QUEUE);
}
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) {
gpie &= ~IXGBE_GPIE_VTMODE_MASK;
gpie |= IXGBE_GPIE_VTMODE_64;
}
if (adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE)
gpie |= IXGBE_SDP1_GPIEN;
if (hw->mac.type == ixgbe_mac_82599EB) {
gpie |= IXGBE_SDP1_GPIEN;
gpie |= IXGBE_SDP2_GPIEN;
}
IXGBE_WRITE_REG(hw, IXGBE_GPIE, gpie);
}
static int ixgbe_up_complete(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int err;
u32 ctrl_ext;
ixgbe_get_hw_control(adapter);
ixgbe_setup_gpie(adapter);
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED)
ixgbe_configure_msix(adapter);
else
ixgbe_configure_msi_and_legacy(adapter);
if (hw->mac.ops.enable_tx_laser &&
((hw->phy.multispeed_fiber) ||
((hw->mac.ops.get_media_type(hw) == ixgbe_media_type_fiber) &&
(hw->mac.type == ixgbe_mac_82599EB))))
hw->mac.ops.enable_tx_laser(hw);
clear_bit(__IXGBE_DOWN, &adapter->state);
ixgbe_napi_enable_all(adapter);
if (ixgbe_is_sfp(hw)) {
ixgbe_sfp_link_config(adapter);
} else {
err = ixgbe_non_sfp_link_config(hw);
if (err)
e_err(probe, "link_config FAILED %d\n", err);
}
IXGBE_READ_REG(hw, IXGBE_EICR);
ixgbe_irq_enable(adapter, true, true);
if (adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE) {
u32 esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
if (esdp & IXGBE_ESDP_SDP1)
e_crit(drv, "Fan has stopped, replace the adapter\n");
}
netif_tx_start_all_queues(adapter->netdev);
adapter->flags |= IXGBE_FLAG_NEED_LINK_UPDATE;
adapter->link_check_timeout = jiffies;
mod_timer(&adapter->service_timer, jiffies);
ctrl_ext = IXGBE_READ_REG(hw, IXGBE_CTRL_EXT);
ctrl_ext |= IXGBE_CTRL_EXT_PFRSTD;
IXGBE_WRITE_REG(hw, IXGBE_CTRL_EXT, ctrl_ext);
return 0;
}
void ixgbe_reinit_locked(struct ixgbe_adapter *adapter)
{
WARN_ON(in_interrupt());
adapter->netdev->trans_start = jiffies;
while (test_and_set_bit(__IXGBE_RESETTING, &adapter->state))
usleep_range(1000, 2000);
ixgbe_down(adapter);
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
msleep(2000);
ixgbe_up(adapter);
clear_bit(__IXGBE_RESETTING, &adapter->state);
}
int ixgbe_up(struct ixgbe_adapter *adapter)
{
ixgbe_configure(adapter);
return ixgbe_up_complete(adapter);
}
void ixgbe_reset(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int err;
while (test_and_set_bit(__IXGBE_IN_SFP_INIT, &adapter->state))
usleep_range(1000, 2000);
adapter->flags2 &= ~(IXGBE_FLAG2_SEARCH_FOR_SFP |
IXGBE_FLAG2_SFP_NEEDS_RESET);
adapter->flags &= ~IXGBE_FLAG_NEED_LINK_CONFIG;
err = hw->mac.ops.init_hw(hw);
switch (err) {
case 0:
case IXGBE_ERR_SFP_NOT_PRESENT:
case IXGBE_ERR_SFP_NOT_SUPPORTED:
break;
case IXGBE_ERR_MASTER_REQUESTS_PENDING:
e_dev_err("master disable timed out\n");
break;
case IXGBE_ERR_EEPROM_VERSION:
e_dev_warn("This device is a pre-production adapter/LOM. "
"Please be aware there may be issuesassociated with "
"your hardware. If you are experiencing problems "
"please contact your Intel or hardware "
"representative who provided you with this "
"hardware.\n");
break;
default:
e_dev_err("Hardware Error: %d\n", err);
}
clear_bit(__IXGBE_IN_SFP_INIT, &adapter->state);
hw->mac.ops.set_rar(hw, 0, hw->mac.addr, adapter->num_vfs,
IXGBE_RAH_AV);
}
static void ixgbe_clean_rx_ring(struct ixgbe_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
unsigned long size;
u16 i;
if (!rx_ring->rx_buffer_info)
return;
for (i = 0; i < rx_ring->count; i++) {
struct ixgbe_rx_buffer *rx_buffer_info;
rx_buffer_info = &rx_ring->rx_buffer_info[i];
if (rx_buffer_info->dma) {
dma_unmap_single(rx_ring->dev, rx_buffer_info->dma,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
rx_buffer_info->dma = 0;
}
if (rx_buffer_info->skb) {
struct sk_buff *skb = rx_buffer_info->skb;
rx_buffer_info->skb = NULL;
do {
struct sk_buff *this = skb;
if (IXGBE_RSC_CB(this)->delay_unmap) {
dma_unmap_single(dev,
IXGBE_RSC_CB(this)->dma,
rx_ring->rx_buf_len,
DMA_FROM_DEVICE);
IXGBE_RSC_CB(this)->dma = 0;
IXGBE_RSC_CB(skb)->delay_unmap = false;
}
skb = skb->prev;
dev_kfree_skb(this);
} while (skb);
}
if (!rx_buffer_info->page)
continue;
if (rx_buffer_info->page_dma) {
dma_unmap_page(dev, rx_buffer_info->page_dma,
PAGE_SIZE / 2, DMA_FROM_DEVICE);
rx_buffer_info->page_dma = 0;
}
put_page(rx_buffer_info->page);
rx_buffer_info->page = NULL;
rx_buffer_info->page_offset = 0;
}
size = sizeof(struct ixgbe_rx_buffer) * rx_ring->count;
memset(rx_ring->rx_buffer_info, 0, size);
memset(rx_ring->desc, 0, rx_ring->size);
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
}
static void ixgbe_clean_tx_ring(struct ixgbe_ring *tx_ring)
{
struct ixgbe_tx_buffer *tx_buffer_info;
unsigned long size;
u16 i;
if (!tx_ring->tx_buffer_info)
return;
for (i = 0; i < tx_ring->count; i++) {
tx_buffer_info = &tx_ring->tx_buffer_info[i];
ixgbe_unmap_and_free_tx_resource(tx_ring, tx_buffer_info);
}
size = sizeof(struct ixgbe_tx_buffer) * tx_ring->count;
memset(tx_ring->tx_buffer_info, 0, size);
memset(tx_ring->desc, 0, tx_ring->size);
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
}
static void ixgbe_clean_all_rx_rings(struct ixgbe_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbe_clean_rx_ring(adapter->rx_ring[i]);
}
static void ixgbe_clean_all_tx_rings(struct ixgbe_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
ixgbe_clean_tx_ring(adapter->tx_ring[i]);
}
void ixgbe_down(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
u32 rxctrl;
int i;
int num_q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
set_bit(__IXGBE_DOWN, &adapter->state);
rxctrl = IXGBE_READ_REG(hw, IXGBE_RXCTRL);
IXGBE_WRITE_REG(hw, IXGBE_RXCTRL, rxctrl & ~IXGBE_RXCTRL_RXEN);
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbe_disable_rx_queue(adapter, adapter->rx_ring[i]);
usleep_range(10000, 20000);
netif_tx_stop_all_queues(netdev);
netif_carrier_off(netdev);
netif_tx_disable(netdev);
ixgbe_irq_disable(adapter);
ixgbe_napi_disable_all(adapter);
adapter->flags2 &= ~(IXGBE_FLAG2_FDIR_REQUIRES_REINIT |
IXGBE_FLAG2_RESET_REQUESTED);
adapter->flags &= ~IXGBE_FLAG_NEED_LINK_UPDATE;
del_timer_sync(&adapter->service_timer);
if (adapter->num_vfs) {
ixgbe_ping_all_vfs(adapter);
ixgbe_disable_tx_rx(adapter);
for (i = 0 ; i < adapter->num_vfs; i++)
adapter->vfinfo[i].clear_to_send = 0;
}
for (i = 0; i < num_q_vectors; i++) {
struct ixgbe_q_vector *q_vector = adapter->q_vector[i];
irq_set_affinity_hint(adapter->msix_entries[i]. vector, NULL);
free_cpumask_var(q_vector->affinity_mask);
}
for (i = 0; i < adapter->num_tx_queues; i++) {
u8 reg_idx = adapter->tx_ring[i]->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_TXDCTL(reg_idx), IXGBE_TXDCTL_SWFLSH);
}
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
IXGBE_WRITE_REG(hw, IXGBE_DMATXCTL,
(IXGBE_READ_REG(hw, IXGBE_DMATXCTL) &
~IXGBE_DMATXCTL_TE));
break;
default:
break;
}
if (!pci_channel_offline(adapter->pdev))
ixgbe_reset(adapter);
if (hw->mac.ops.disable_tx_laser &&
((hw->phy.multispeed_fiber) ||
((hw->mac.ops.get_media_type(hw) == ixgbe_media_type_fiber) &&
(hw->mac.type == ixgbe_mac_82599EB))))
hw->mac.ops.disable_tx_laser(hw);
ixgbe_clean_all_tx_rings(adapter);
ixgbe_clean_all_rx_rings(adapter);
#ifdef CONFIG_IXGBE_DCA
ixgbe_setup_dca(adapter);
#endif
}
static int ixgbe_poll(struct napi_struct *napi, int budget)
{
struct ixgbe_q_vector *q_vector =
container_of(napi, struct ixgbe_q_vector, napi);
struct ixgbe_adapter *adapter = q_vector->adapter;
int tx_clean_complete, work_done = 0;
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
ixgbe_update_dca(q_vector);
#endif
tx_clean_complete = ixgbe_clean_tx_irq(q_vector, adapter->tx_ring[0]);
ixgbe_clean_rx_irq(q_vector, adapter->rx_ring[0], &work_done, budget);
if (!tx_clean_complete)
work_done = budget;
if (work_done < budget) {
napi_complete(napi);
if (adapter->rx_itr_setting & 1)
ixgbe_set_itr(adapter);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable_queues(adapter, IXGBE_EIMS_RTX_QUEUE);
}
return work_done;
}
static void ixgbe_tx_timeout(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
ixgbe_tx_timeout_reset(adapter);
}
static inline bool ixgbe_set_rss_queues(struct ixgbe_adapter *adapter)
{
bool ret = false;
struct ixgbe_ring_feature *f = &adapter->ring_feature[RING_F_RSS];
if (adapter->flags & IXGBE_FLAG_RSS_ENABLED) {
f->mask = 0xF;
adapter->num_rx_queues = f->indices;
adapter->num_tx_queues = f->indices;
ret = true;
} else {
ret = false;
}
return ret;
}
static inline bool ixgbe_set_fdir_queues(struct ixgbe_adapter *adapter)
{
bool ret = false;
struct ixgbe_ring_feature *f_fdir = &adapter->ring_feature[RING_F_FDIR];
f_fdir->indices = min((int)num_online_cpus(), f_fdir->indices);
f_fdir->mask = 0;
if (adapter->flags & IXGBE_FLAG_RSS_ENABLED &&
((adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE ||
(adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE)))) {
adapter->num_tx_queues = f_fdir->indices;
adapter->num_rx_queues = f_fdir->indices;
ret = true;
} else {
adapter->flags &= ~IXGBE_FLAG_FDIR_HASH_CAPABLE;
adapter->flags &= ~IXGBE_FLAG_FDIR_PERFECT_CAPABLE;
}
return ret;
}
static inline bool ixgbe_set_fcoe_queues(struct ixgbe_adapter *adapter)
{
struct ixgbe_ring_feature *f = &adapter->ring_feature[RING_F_FCOE];
if (!(adapter->flags & IXGBE_FLAG_FCOE_ENABLED))
return false;
if (adapter->flags & IXGBE_FLAG_DCB_ENABLED) {
#ifdef CONFIG_IXGBE_DCB
int tc;
struct net_device *dev = adapter->netdev;
tc = netdev_get_prio_tc_map(dev, adapter->fcoe.up);
f->indices = dev->tc_to_txq[tc].count;
f->mask = dev->tc_to_txq[tc].offset;
#endif
} else {
f->indices = min((int)num_online_cpus(), f->indices);
adapter->num_rx_queues = 1;
adapter->num_tx_queues = 1;
if (adapter->flags & IXGBE_FLAG_RSS_ENABLED) {
e_info(probe, "FCoE enabled with RSS\n");
if ((adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) ||
(adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE))
ixgbe_set_fdir_queues(adapter);
else
ixgbe_set_rss_queues(adapter);
}
f->mask = adapter->num_rx_queues;
adapter->num_rx_queues += f->indices;
adapter->num_tx_queues += f->indices;
}
return true;
}
static inline bool ixgbe_set_dcb_queues(struct ixgbe_adapter *adapter)
{
bool ret = false;
struct ixgbe_ring_feature *f = &adapter->ring_feature[RING_F_DCB];
int i, q;
if (!(adapter->flags & IXGBE_FLAG_DCB_ENABLED))
return ret;
f->indices = 0;
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
q = min((int)num_online_cpus(), MAX_TRAFFIC_CLASS);
f->indices += q;
}
f->mask = 0x7 << 3;
adapter->num_rx_queues = f->indices;
adapter->num_tx_queues = f->indices;
ret = true;
#ifdef IXGBE_FCOE
ixgbe_set_fcoe_queues(adapter);
#endif
return ret;
}
static inline bool ixgbe_set_sriov_queues(struct ixgbe_adapter *adapter)
{
return false;
}
static int ixgbe_set_num_queues(struct ixgbe_adapter *adapter)
{
adapter->num_rx_queues = 1;
adapter->num_tx_queues = 1;
adapter->num_rx_pools = adapter->num_rx_queues;
adapter->num_rx_queues_per_pool = 1;
if (ixgbe_set_sriov_queues(adapter))
goto done;
#ifdef CONFIG_IXGBE_DCB
if (ixgbe_set_dcb_queues(adapter))
goto done;
#endif
#ifdef IXGBE_FCOE
if (ixgbe_set_fcoe_queues(adapter))
goto done;
#endif
if (ixgbe_set_fdir_queues(adapter))
goto done;
if (ixgbe_set_rss_queues(adapter))
goto done;
adapter->num_rx_queues = 1;
adapter->num_tx_queues = 1;
done:
netif_set_real_num_tx_queues(adapter->netdev, adapter->num_tx_queues);
return netif_set_real_num_rx_queues(adapter->netdev,
adapter->num_rx_queues);
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
adapter->num_msix_vectors = min(vectors,
adapter->max_msix_q_vectors + NON_Q_VECTORS);
}
}
static inline bool ixgbe_cache_ring_rss(struct ixgbe_adapter *adapter)
{
int i;
if (!(adapter->flags & IXGBE_FLAG_RSS_ENABLED))
return false;
for (i = 0; i < adapter->num_rx_queues; i++)
adapter->rx_ring[i]->reg_idx = i;
for (i = 0; i < adapter->num_tx_queues; i++)
adapter->tx_ring[i]->reg_idx = i;
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
*tx = tc << 3;
*rx = tc << 2;
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
if (num_tcs == 8) {
if (tc < 3) {
*tx = tc << 5;
*rx = tc << 4;
} else if (tc < 5) {
*tx = ((tc + 2) << 4);
*rx = tc << 4;
} else if (tc < num_tcs) {
*tx = ((tc + 8) << 3);
*rx = tc << 4;
}
} else if (num_tcs == 4) {
*rx = tc << 5;
switch (tc) {
case 0:
*tx = 0;
break;
case 1:
*tx = 64;
break;
case 2:
*tx = 96;
break;
case 3:
*tx = 112;
break;
default:
break;
}
}
break;
default:
break;
}
}
int ixgbe_setup_tc(struct net_device *dev, u8 tc)
{
int i;
unsigned int q, offset = 0;
if (!tc) {
netdev_reset_tc(dev);
} else {
struct ixgbe_adapter *adapter = netdev_priv(dev);
if (tc > MAX_TRAFFIC_CLASS || netdev_set_num_tc(dev, tc))
return -EINVAL;
for (i = 0; i < tc; i++) {
q = min((int)num_online_cpus(), IXGBE_MAX_Q_PER_TC);
netdev_set_prio_tc_map(dev, i, i);
netdev_set_tc_queue(dev, i, q, offset);
offset += q;
}
if (!(adapter->flags & IXGBE_FLAG_DCB_ENABLED) &&
dev->dcbnl_ops && dev->dcbnl_ops->setdcbx) {
struct ieee_ets ets = {
.prio_tc = {0, 1, 2, 3, 4, 5, 6, 7},
};
u8 mode = DCB_CAP_DCBX_HOST | DCB_CAP_DCBX_VER_IEEE;
dev->dcbnl_ops->setdcbx(dev, mode);
dev->dcbnl_ops->ieee_setets(dev, &ets);
}
}
return 0;
}
static inline bool ixgbe_cache_ring_dcb(struct ixgbe_adapter *adapter)
{
struct net_device *dev = adapter->netdev;
int i, j, k;
u8 num_tcs = netdev_get_num_tc(dev);
if (!(adapter->flags & IXGBE_FLAG_DCB_ENABLED))
return false;
for (i = 0, k = 0; i < num_tcs; i++) {
unsigned int tx_s, rx_s;
u16 count = dev->tc_to_txq[i].count;
ixgbe_get_first_reg_idx(adapter, i, &tx_s, &rx_s);
for (j = 0; j < count; j++, k++) {
adapter->tx_ring[k]->reg_idx = tx_s + j;
adapter->rx_ring[k]->reg_idx = rx_s + j;
adapter->tx_ring[k]->dcb_tc = i;
adapter->rx_ring[k]->dcb_tc = i;
}
}
return true;
}
static inline bool ixgbe_cache_ring_fdir(struct ixgbe_adapter *adapter)
{
int i;
bool ret = false;
if (adapter->flags & IXGBE_FLAG_RSS_ENABLED &&
((adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) ||
(adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE))) {
for (i = 0; i < adapter->num_rx_queues; i++)
adapter->rx_ring[i]->reg_idx = i;
for (i = 0; i < adapter->num_tx_queues; i++)
adapter->tx_ring[i]->reg_idx = i;
ret = true;
}
return ret;
}
static inline bool ixgbe_cache_ring_fcoe(struct ixgbe_adapter *adapter)
{
struct ixgbe_ring_feature *f = &adapter->ring_feature[RING_F_FCOE];
int i;
u8 fcoe_rx_i = 0, fcoe_tx_i = 0;
if (!(adapter->flags & IXGBE_FLAG_FCOE_ENABLED))
return false;
if (adapter->flags & IXGBE_FLAG_RSS_ENABLED) {
if ((adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) ||
(adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE))
ixgbe_cache_ring_fdir(adapter);
else
ixgbe_cache_ring_rss(adapter);
fcoe_rx_i = f->mask;
fcoe_tx_i = f->mask;
}
for (i = 0; i < f->indices; i++, fcoe_rx_i++, fcoe_tx_i++) {
adapter->rx_ring[f->mask + i]->reg_idx = fcoe_rx_i;
adapter->tx_ring[f->mask + i]->reg_idx = fcoe_tx_i;
}
return true;
}
static inline bool ixgbe_cache_ring_sriov(struct ixgbe_adapter *adapter)
{
adapter->rx_ring[0]->reg_idx = adapter->num_vfs * 2;
adapter->tx_ring[0]->reg_idx = adapter->num_vfs * 2;
if (adapter->num_vfs)
return true;
else
return false;
}
static void ixgbe_cache_ring_register(struct ixgbe_adapter *adapter)
{
adapter->rx_ring[0]->reg_idx = 0;
adapter->tx_ring[0]->reg_idx = 0;
if (ixgbe_cache_ring_sriov(adapter))
return;
#ifdef CONFIG_IXGBE_DCB
if (ixgbe_cache_ring_dcb(adapter))
return;
#endif
#ifdef IXGBE_FCOE
if (ixgbe_cache_ring_fcoe(adapter))
return;
#endif
if (ixgbe_cache_ring_fdir(adapter))
return;
if (ixgbe_cache_ring_rss(adapter))
return;
}
static int ixgbe_alloc_queues(struct ixgbe_adapter *adapter)
{
int rx = 0, tx = 0, nid = adapter->node;
if (nid < 0 || !node_online(nid))
nid = first_online_node;
for (; tx < adapter->num_tx_queues; tx++) {
struct ixgbe_ring *ring;
ring = kzalloc_node(sizeof(*ring), GFP_KERNEL, nid);
if (!ring)
ring = kzalloc(sizeof(*ring), GFP_KERNEL);
if (!ring)
goto err_allocation;
ring->count = adapter->tx_ring_count;
ring->queue_index = tx;
ring->numa_node = nid;
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
adapter->tx_ring[tx] = ring;
}
for (; rx < adapter->num_rx_queues; rx++) {
struct ixgbe_ring *ring;
ring = kzalloc_node(sizeof(*ring), GFP_KERNEL, nid);
if (!ring)
ring = kzalloc(sizeof(*ring), GFP_KERNEL);
if (!ring)
goto err_allocation;
ring->count = adapter->rx_ring_count;
ring->queue_index = rx;
ring->numa_node = nid;
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
adapter->rx_ring[rx] = ring;
}
ixgbe_cache_ring_register(adapter);
return 0;
err_allocation:
while (tx)
kfree(adapter->tx_ring[--tx]);
while (rx)
kfree(adapter->rx_ring[--rx]);
return -ENOMEM;
}
static int ixgbe_set_interrupt_capability(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int err = 0;
int vector, v_budget;
v_budget = min(adapter->num_rx_queues + adapter->num_tx_queues,
(int)num_online_cpus()) + NON_Q_VECTORS;
v_budget = min(v_budget, (int)hw->mac.max_msix_vectors);
adapter->msix_entries = kcalloc(v_budget,
sizeof(struct msix_entry), GFP_KERNEL);
if (adapter->msix_entries) {
for (vector = 0; vector < v_budget; vector++)
adapter->msix_entries[vector].entry = vector;
ixgbe_acquire_msix_vectors(adapter, v_budget);
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED)
goto out;
}
adapter->flags &= ~IXGBE_FLAG_DCB_ENABLED;
adapter->flags &= ~IXGBE_FLAG_RSS_ENABLED;
if (adapter->flags & (IXGBE_FLAG_FDIR_HASH_CAPABLE |
IXGBE_FLAG_FDIR_PERFECT_CAPABLE)) {
e_err(probe,
"Flow Director is not supported while multiple "
"queues are disabled. Disabling Flow Director\n");
}
adapter->flags &= ~IXGBE_FLAG_FDIR_HASH_CAPABLE;
adapter->flags &= ~IXGBE_FLAG_FDIR_PERFECT_CAPABLE;
adapter->atr_sample_rate = 0;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
ixgbe_disable_sriov(adapter);
err = ixgbe_set_num_queues(adapter);
if (err)
return err;
err = pci_enable_msi(adapter->pdev);
if (!err) {
adapter->flags |= IXGBE_FLAG_MSI_ENABLED;
} else {
netif_printk(adapter, hw, KERN_DEBUG, adapter->netdev,
"Unable to allocate MSI interrupt, "
"falling back to legacy. Error: %d\n", err);
err = 0;
}
out:
return err;
}
static int ixgbe_alloc_q_vectors(struct ixgbe_adapter *adapter)
{
int q_idx, num_q_vectors;
struct ixgbe_q_vector *q_vector;
int (*poll)(struct napi_struct *, int);
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED) {
num_q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
poll = &ixgbe_clean_rxtx_many;
} else {
num_q_vectors = 1;
poll = &ixgbe_poll;
}
for (q_idx = 0; q_idx < num_q_vectors; q_idx++) {
q_vector = kzalloc_node(sizeof(struct ixgbe_q_vector),
GFP_KERNEL, adapter->node);
if (!q_vector)
q_vector = kzalloc(sizeof(struct ixgbe_q_vector),
GFP_KERNEL);
if (!q_vector)
goto err_out;
q_vector->adapter = adapter;
if (q_vector->txr_count && !q_vector->rxr_count)
q_vector->eitr = adapter->tx_eitr_param;
else
q_vector->eitr = adapter->rx_eitr_param;
q_vector->v_idx = q_idx;
netif_napi_add(adapter->netdev, &q_vector->napi, (*poll), 64);
adapter->q_vector[q_idx] = q_vector;
}
return 0;
err_out:
while (q_idx) {
q_idx--;
q_vector = adapter->q_vector[q_idx];
netif_napi_del(&q_vector->napi);
kfree(q_vector);
adapter->q_vector[q_idx] = NULL;
}
return -ENOMEM;
}
static void ixgbe_free_q_vectors(struct ixgbe_adapter *adapter)
{
int q_idx, num_q_vectors;
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED)
num_q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
else
num_q_vectors = 1;
for (q_idx = 0; q_idx < num_q_vectors; q_idx++) {
struct ixgbe_q_vector *q_vector = adapter->q_vector[q_idx];
adapter->q_vector[q_idx] = NULL;
netif_napi_del(&q_vector->napi);
kfree(q_vector);
}
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
int ixgbe_init_interrupt_scheme(struct ixgbe_adapter *adapter)
{
int err;
err = ixgbe_set_num_queues(adapter);
if (err)
return err;
err = ixgbe_set_interrupt_capability(adapter);
if (err) {
e_dev_err("Unable to setup interrupt capabilities\n");
goto err_set_interrupt;
}
err = ixgbe_alloc_q_vectors(adapter);
if (err) {
e_dev_err("Unable to allocate memory for queue vectors\n");
goto err_alloc_q_vectors;
}
err = ixgbe_alloc_queues(adapter);
if (err) {
e_dev_err("Unable to allocate memory for queues\n");
goto err_alloc_queues;
}
e_dev_info("Multiqueue %s: Rx Queue count = %u, Tx Queue count = %u\n",
(adapter->num_rx_queues > 1) ? "Enabled" : "Disabled",
adapter->num_rx_queues, adapter->num_tx_queues);
set_bit(__IXGBE_DOWN, &adapter->state);
return 0;
err_alloc_queues:
ixgbe_free_q_vectors(adapter);
err_alloc_q_vectors:
ixgbe_reset_interrupt_capability(adapter);
err_set_interrupt:
return err;
}
void ixgbe_clear_interrupt_scheme(struct ixgbe_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++) {
kfree(adapter->tx_ring[i]);
adapter->tx_ring[i] = NULL;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
struct ixgbe_ring *ring = adapter->rx_ring[i];
kfree_rcu(ring, rcu);
adapter->rx_ring[i] = NULL;
}
adapter->num_tx_queues = 0;
adapter->num_rx_queues = 0;
ixgbe_free_q_vectors(adapter);
ixgbe_reset_interrupt_capability(adapter);
}
static int __devinit ixgbe_sw_init(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
struct net_device *dev = adapter->netdev;
unsigned int rss;
#ifdef CONFIG_IXGBE_DCB
int j;
struct tc_configuration *tc;
#endif
int max_frame = dev->mtu + ETH_HLEN + ETH_FCS_LEN;
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
hw->revision_id = pdev->revision;
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
rss = min(IXGBE_MAX_RSS_INDICES, (int)num_online_cpus());
adapter->ring_feature[RING_F_RSS].indices = rss;
adapter->flags |= IXGBE_FLAG_RSS_ENABLED;
adapter->ring_feature[RING_F_DCB].indices = IXGBE_MAX_DCB_INDICES;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
if (hw->device_id == IXGBE_DEV_ID_82598AT)
adapter->flags |= IXGBE_FLAG_FAN_FAIL_CAPABLE;
adapter->max_msix_q_vectors = MAX_MSIX_Q_VECTORS_82598;
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
adapter->max_msix_q_vectors = MAX_MSIX_Q_VECTORS_82599;
adapter->flags2 |= IXGBE_FLAG2_RSC_CAPABLE;
adapter->flags2 |= IXGBE_FLAG2_RSC_ENABLED;
if (hw->device_id == IXGBE_DEV_ID_82599_T3_LOM)
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_CAPABLE;
spin_lock_init(&adapter->fdir_perfect_lock);
adapter->flags |= IXGBE_FLAG_FDIR_HASH_CAPABLE;
adapter->atr_sample_rate = 20;
adapter->ring_feature[RING_F_FDIR].indices =
IXGBE_MAX_FDIR_INDICES;
adapter->fdir_pballoc = 0;
#ifdef IXGBE_FCOE
adapter->flags |= IXGBE_FLAG_FCOE_CAPABLE;
adapter->flags &= ~IXGBE_FLAG_FCOE_ENABLED;
adapter->ring_feature[RING_F_FCOE].indices = 0;
#ifdef CONFIG_IXGBE_DCB
adapter->fcoe.tc = IXGBE_FCOE_DEFTC;
adapter->fcoe.up = IXGBE_FCOE_DEFTC;
#endif
#endif
break;
default:
break;
}
#ifdef CONFIG_IXGBE_DCB
for (j = 0; j < MAX_TRAFFIC_CLASS; j++) {
tc = &adapter->dcb_cfg.tc_config[j];
tc->path[DCB_TX_CONFIG].bwg_id = 0;
tc->path[DCB_TX_CONFIG].bwg_percent = 12 + (j & 1);
tc->path[DCB_RX_CONFIG].bwg_id = 0;
tc->path[DCB_RX_CONFIG].bwg_percent = 12 + (j & 1);
tc->dcb_pfc = pfc_disabled;
}
adapter->dcb_cfg.bw_percentage[DCB_TX_CONFIG][0] = 100;
adapter->dcb_cfg.bw_percentage[DCB_RX_CONFIG][0] = 100;
adapter->dcb_cfg.rx_pba_cfg = pba_equal;
adapter->dcb_cfg.pfc_mode_enable = false;
adapter->dcb_set_bitmap = 0x00;
adapter->dcbx_cap = DCB_CAP_DCBX_HOST | DCB_CAP_DCBX_VER_CEE;
ixgbe_copy_dcb_cfg(&adapter->dcb_cfg, &adapter->temp_dcb_cfg,
MAX_TRAFFIC_CLASS);
#endif
hw->fc.requested_mode = ixgbe_fc_full;
hw->fc.current_mode = ixgbe_fc_full;
#ifdef CONFIG_DCB
adapter->last_lfc_mode = hw->fc.current_mode;
#endif
hw->fc.high_water = FC_HIGH_WATER(max_frame);
hw->fc.low_water = FC_LOW_WATER(max_frame);
hw->fc.pause_time = IXGBE_DEFAULT_FCPAUSE;
hw->fc.send_xon = true;
hw->fc.disable_fc_autoneg = false;
adapter->rx_itr_setting = 1;
adapter->rx_eitr_param = 20000;
adapter->tx_itr_setting = 1;
adapter->tx_eitr_param = 10000;
adapter->eitr_low = 10;
adapter->eitr_high = 20;
adapter->tx_ring_count = IXGBE_DEFAULT_TXD;
adapter->rx_ring_count = IXGBE_DEFAULT_RXD;
if (ixgbe_init_eeprom_params_generic(hw)) {
e_dev_err("EEPROM initialization failed\n");
return -EIO;
}
adapter->flags |= IXGBE_FLAG_RX_CSUM_ENABLED;
adapter->node = dev_to_node(&pdev->dev);
set_bit(__IXGBE_DOWN, &adapter->state);
return 0;
}
int ixgbe_setup_tx_resources(struct ixgbe_ring *tx_ring)
{
struct device *dev = tx_ring->dev;
int size;
size = sizeof(struct ixgbe_tx_buffer) * tx_ring->count;
tx_ring->tx_buffer_info = vzalloc_node(size, tx_ring->numa_node);
if (!tx_ring->tx_buffer_info)
tx_ring->tx_buffer_info = vzalloc(size);
if (!tx_ring->tx_buffer_info)
goto err;
tx_ring->size = tx_ring->count * sizeof(union ixgbe_adv_tx_desc);
tx_ring->size = ALIGN(tx_ring->size, 4096);
tx_ring->desc = dma_alloc_coherent(dev, tx_ring->size,
&tx_ring->dma, GFP_KERNEL);
if (!tx_ring->desc)
goto err;
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
tx_ring->work_limit = tx_ring->count;
return 0;
err:
vfree(tx_ring->tx_buffer_info);
tx_ring->tx_buffer_info = NULL;
dev_err(dev, "Unable to allocate memory for the Tx descriptor ring\n");
return -ENOMEM;
}
static int ixgbe_setup_all_tx_resources(struct ixgbe_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->num_tx_queues; i++) {
err = ixgbe_setup_tx_resources(adapter->tx_ring[i]);
if (!err)
continue;
e_err(probe, "Allocation for Tx Queue %u failed\n", i);
break;
}
return err;
}
int ixgbe_setup_rx_resources(struct ixgbe_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
int size;
size = sizeof(struct ixgbe_rx_buffer) * rx_ring->count;
rx_ring->rx_buffer_info = vzalloc_node(size, rx_ring->numa_node);
if (!rx_ring->rx_buffer_info)
rx_ring->rx_buffer_info = vzalloc(size);
if (!rx_ring->rx_buffer_info)
goto err;
rx_ring->size = rx_ring->count * sizeof(union ixgbe_adv_rx_desc);
rx_ring->size = ALIGN(rx_ring->size, 4096);
rx_ring->desc = dma_alloc_coherent(dev, rx_ring->size,
&rx_ring->dma, GFP_KERNEL);
if (!rx_ring->desc)
goto err;
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
return 0;
err:
vfree(rx_ring->rx_buffer_info);
rx_ring->rx_buffer_info = NULL;
dev_err(dev, "Unable to allocate memory for the Rx descriptor ring\n");
return -ENOMEM;
}
static int ixgbe_setup_all_rx_resources(struct ixgbe_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->num_rx_queues; i++) {
err = ixgbe_setup_rx_resources(adapter->rx_ring[i]);
if (!err)
continue;
e_err(probe, "Allocation for Rx Queue %u failed\n", i);
break;
}
return err;
}
void ixgbe_free_tx_resources(struct ixgbe_ring *tx_ring)
{
ixgbe_clean_tx_ring(tx_ring);
vfree(tx_ring->tx_buffer_info);
tx_ring->tx_buffer_info = NULL;
if (!tx_ring->desc)
return;
dma_free_coherent(tx_ring->dev, tx_ring->size,
tx_ring->desc, tx_ring->dma);
tx_ring->desc = NULL;
}
static void ixgbe_free_all_tx_resources(struct ixgbe_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
if (adapter->tx_ring[i]->desc)
ixgbe_free_tx_resources(adapter->tx_ring[i]);
}
void ixgbe_free_rx_resources(struct ixgbe_ring *rx_ring)
{
ixgbe_clean_rx_ring(rx_ring);
vfree(rx_ring->rx_buffer_info);
rx_ring->rx_buffer_info = NULL;
if (!rx_ring->desc)
return;
dma_free_coherent(rx_ring->dev, rx_ring->size,
rx_ring->desc, rx_ring->dma);
rx_ring->desc = NULL;
}
static void ixgbe_free_all_rx_resources(struct ixgbe_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
if (adapter->rx_ring[i]->desc)
ixgbe_free_rx_resources(adapter->rx_ring[i]);
}
static int ixgbe_change_mtu(struct net_device *netdev, int new_mtu)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED &&
hw->mac.type != ixgbe_mac_X540) {
if ((new_mtu < 68) || (max_frame > MAXIMUM_ETHERNET_VLAN_SIZE))
return -EINVAL;
} else {
if ((new_mtu < 68) || (max_frame > IXGBE_MAX_JUMBO_FRAME_SIZE))
return -EINVAL;
}
e_info(probe, "changing MTU from %d to %d\n", netdev->mtu, new_mtu);
netdev->mtu = new_mtu;
hw->fc.high_water = FC_HIGH_WATER(max_frame);
hw->fc.low_water = FC_LOW_WATER(max_frame);
if (netif_running(netdev))
ixgbe_reinit_locked(adapter);
return 0;
}
static int ixgbe_open(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int err;
if (test_bit(__IXGBE_TESTING, &adapter->state))
return -EBUSY;
netif_carrier_off(netdev);
err = ixgbe_setup_all_tx_resources(adapter);
if (err)
goto err_setup_tx;
err = ixgbe_setup_all_rx_resources(adapter);
if (err)
goto err_setup_rx;
ixgbe_configure(adapter);
err = ixgbe_request_irq(adapter);
if (err)
goto err_req_irq;
err = ixgbe_up_complete(adapter);
if (err)
goto err_up;
netif_tx_start_all_queues(netdev);
return 0;
err_up:
ixgbe_release_hw_control(adapter);
ixgbe_free_irq(adapter);
err_req_irq:
err_setup_rx:
ixgbe_free_all_rx_resources(adapter);
err_setup_tx:
ixgbe_free_all_tx_resources(adapter);
ixgbe_reset(adapter);
return err;
}
static int ixgbe_close(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
ixgbe_down(adapter);
ixgbe_free_irq(adapter);
ixgbe_free_all_tx_resources(adapter);
ixgbe_free_all_rx_resources(adapter);
ixgbe_release_hw_control(adapter);
return 0;
}
static int ixgbe_resume(struct pci_dev *pdev)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
u32 err;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
pci_save_state(pdev);
err = pci_enable_device_mem(pdev);
if (err) {
e_dev_err("Cannot enable PCI device from suspend\n");
return err;
}
pci_set_master(pdev);
pci_wake_from_d3(pdev, false);
err = ixgbe_init_interrupt_scheme(adapter);
if (err) {
e_dev_err("Cannot initialize interrupts for device\n");
return err;
}
ixgbe_reset(adapter);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_WUS, ~0);
if (netif_running(netdev)) {
err = ixgbe_open(netdev);
if (err)
return err;
}
netif_device_attach(netdev);
return 0;
}
static int __ixgbe_shutdown(struct pci_dev *pdev, bool *enable_wake)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
u32 ctrl, fctrl;
u32 wufc = adapter->wol;
#ifdef CONFIG_PM
int retval = 0;
#endif
netif_device_detach(netdev);
if (netif_running(netdev)) {
ixgbe_down(adapter);
ixgbe_free_irq(adapter);
ixgbe_free_all_tx_resources(adapter);
ixgbe_free_all_rx_resources(adapter);
}
ixgbe_clear_interrupt_scheme(adapter);
#ifdef CONFIG_DCB
kfree(adapter->ixgbe_ieee_pfc);
kfree(adapter->ixgbe_ieee_ets);
#endif
#ifdef CONFIG_PM
retval = pci_save_state(pdev);
if (retval)
return retval;
#endif
if (wufc) {
ixgbe_set_rx_mode(netdev);
if (wufc & IXGBE_WUFC_MC) {
fctrl = IXGBE_READ_REG(hw, IXGBE_FCTRL);
fctrl |= IXGBE_FCTRL_MPE;
IXGBE_WRITE_REG(hw, IXGBE_FCTRL, fctrl);
}
ctrl = IXGBE_READ_REG(hw, IXGBE_CTRL);
ctrl |= IXGBE_CTRL_GIO_DIS;
IXGBE_WRITE_REG(hw, IXGBE_CTRL, ctrl);
IXGBE_WRITE_REG(hw, IXGBE_WUFC, wufc);
} else {
IXGBE_WRITE_REG(hw, IXGBE_WUC, 0);
IXGBE_WRITE_REG(hw, IXGBE_WUFC, 0);
}
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
pci_wake_from_d3(pdev, false);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
pci_wake_from_d3(pdev, !!wufc);
break;
default:
break;
}
*enable_wake = !!wufc;
ixgbe_release_hw_control(adapter);
pci_disable_device(pdev);
return 0;
}
static int ixgbe_suspend(struct pci_dev *pdev, pm_message_t state)
{
int retval;
bool wake;
retval = __ixgbe_shutdown(pdev, &wake);
if (retval)
return retval;
if (wake) {
pci_prepare_to_sleep(pdev);
} else {
pci_wake_from_d3(pdev, false);
pci_set_power_state(pdev, PCI_D3hot);
}
return 0;
}
static void ixgbe_shutdown(struct pci_dev *pdev)
{
bool wake;
__ixgbe_shutdown(pdev, &wake);
if (system_state == SYSTEM_POWER_OFF) {
pci_wake_from_d3(pdev, wake);
pci_set_power_state(pdev, PCI_D3hot);
}
}
void ixgbe_update_stats(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_hw_stats *hwstats = &adapter->stats;
u64 total_mpc = 0;
u32 i, missed_rx = 0, mpc, bprc, lxon, lxoff, xon_off_tot;
u64 non_eop_descs = 0, restart_queue = 0, tx_busy = 0;
u64 alloc_rx_page_failed = 0, alloc_rx_buff_failed = 0;
u64 bytes = 0, packets = 0;
if (test_bit(__IXGBE_DOWN, &adapter->state) ||
test_bit(__IXGBE_RESETTING, &adapter->state))
return;
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED) {
u64 rsc_count = 0;
u64 rsc_flush = 0;
for (i = 0; i < 16; i++)
adapter->hw_rx_no_dma_resources +=
IXGBE_READ_REG(hw, IXGBE_QPRDC(i));
for (i = 0; i < adapter->num_rx_queues; i++) {
rsc_count += adapter->rx_ring[i]->rx_stats.rsc_count;
rsc_flush += adapter->rx_ring[i]->rx_stats.rsc_flush;
}
adapter->rsc_total_count = rsc_count;
adapter->rsc_total_flush = rsc_flush;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
struct ixgbe_ring *rx_ring = adapter->rx_ring[i];
non_eop_descs += rx_ring->rx_stats.non_eop_descs;
alloc_rx_page_failed += rx_ring->rx_stats.alloc_rx_page_failed;
alloc_rx_buff_failed += rx_ring->rx_stats.alloc_rx_buff_failed;
bytes += rx_ring->stats.bytes;
packets += rx_ring->stats.packets;
}
adapter->non_eop_descs = non_eop_descs;
adapter->alloc_rx_page_failed = alloc_rx_page_failed;
adapter->alloc_rx_buff_failed = alloc_rx_buff_failed;
netdev->stats.rx_bytes = bytes;
netdev->stats.rx_packets = packets;
bytes = 0;
packets = 0;
for (i = 0; i < adapter->num_tx_queues; i++) {
struct ixgbe_ring *tx_ring = adapter->tx_ring[i];
restart_queue += tx_ring->tx_stats.restart_queue;
tx_busy += tx_ring->tx_stats.tx_busy;
bytes += tx_ring->stats.bytes;
packets += tx_ring->stats.packets;
}
adapter->restart_queue = restart_queue;
adapter->tx_busy = tx_busy;
netdev->stats.tx_bytes = bytes;
netdev->stats.tx_packets = packets;
hwstats->crcerrs += IXGBE_READ_REG(hw, IXGBE_CRCERRS);
for (i = 0; i < 8; i++) {
mpc = IXGBE_READ_REG(hw, IXGBE_MPC(i));
missed_rx += mpc;
hwstats->mpc[i] += mpc;
total_mpc += hwstats->mpc[i];
if (hw->mac.type == ixgbe_mac_82598EB)
hwstats->rnbc[i] += IXGBE_READ_REG(hw, IXGBE_RNBC(i));
hwstats->qptc[i] += IXGBE_READ_REG(hw, IXGBE_QPTC(i));
hwstats->qbtc[i] += IXGBE_READ_REG(hw, IXGBE_QBTC(i));
hwstats->qprc[i] += IXGBE_READ_REG(hw, IXGBE_QPRC(i));
hwstats->qbrc[i] += IXGBE_READ_REG(hw, IXGBE_QBRC(i));
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
hwstats->pxonrxc[i] +=
IXGBE_READ_REG(hw, IXGBE_PXONRXC(i));
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
hwstats->pxonrxc[i] +=
IXGBE_READ_REG(hw, IXGBE_PXONRXCNT(i));
break;
default:
break;
}
hwstats->pxontxc[i] += IXGBE_READ_REG(hw, IXGBE_PXONTXC(i));
hwstats->pxofftxc[i] += IXGBE_READ_REG(hw, IXGBE_PXOFFTXC(i));
}
hwstats->gprc += IXGBE_READ_REG(hw, IXGBE_GPRC);
hwstats->gprc -= missed_rx;
ixgbe_update_xoff_received(adapter);
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
hwstats->lxonrxc += IXGBE_READ_REG(hw, IXGBE_LXONRXC);
hwstats->gorc += IXGBE_READ_REG(hw, IXGBE_GORCH);
hwstats->gotc += IXGBE_READ_REG(hw, IXGBE_GOTCH);
hwstats->tor += IXGBE_READ_REG(hw, IXGBE_TORH);
break;
case ixgbe_mac_X540:
hwstats->o2bgptc += IXGBE_READ_REG(hw, IXGBE_O2BGPTC);
hwstats->o2bspc += IXGBE_READ_REG(hw, IXGBE_O2BSPC);
hwstats->b2ospc += IXGBE_READ_REG(hw, IXGBE_B2OSPC);
hwstats->b2ogprc += IXGBE_READ_REG(hw, IXGBE_B2OGPRC);
case ixgbe_mac_82599EB:
hwstats->gorc += IXGBE_READ_REG(hw, IXGBE_GORCL);
IXGBE_READ_REG(hw, IXGBE_GORCH);
hwstats->gotc += IXGBE_READ_REG(hw, IXGBE_GOTCL);
IXGBE_READ_REG(hw, IXGBE_GOTCH);
hwstats->tor += IXGBE_READ_REG(hw, IXGBE_TORL);
IXGBE_READ_REG(hw, IXGBE_TORH);
hwstats->lxonrxc += IXGBE_READ_REG(hw, IXGBE_LXONRXCNT);
hwstats->fdirmatch += IXGBE_READ_REG(hw, IXGBE_FDIRMATCH);
hwstats->fdirmiss += IXGBE_READ_REG(hw, IXGBE_FDIRMISS);
#ifdef IXGBE_FCOE
hwstats->fccrc += IXGBE_READ_REG(hw, IXGBE_FCCRC);
hwstats->fcoerpdc += IXGBE_READ_REG(hw, IXGBE_FCOERPDC);
hwstats->fcoeprc += IXGBE_READ_REG(hw, IXGBE_FCOEPRC);
hwstats->fcoeptc += IXGBE_READ_REG(hw, IXGBE_FCOEPTC);
hwstats->fcoedwrc += IXGBE_READ_REG(hw, IXGBE_FCOEDWRC);
hwstats->fcoedwtc += IXGBE_READ_REG(hw, IXGBE_FCOEDWTC);
#endif
break;
default:
break;
}
bprc = IXGBE_READ_REG(hw, IXGBE_BPRC);
hwstats->bprc += bprc;
hwstats->mprc += IXGBE_READ_REG(hw, IXGBE_MPRC);
if (hw->mac.type == ixgbe_mac_82598EB)
hwstats->mprc -= bprc;
hwstats->roc += IXGBE_READ_REG(hw, IXGBE_ROC);
hwstats->prc64 += IXGBE_READ_REG(hw, IXGBE_PRC64);
hwstats->prc127 += IXGBE_READ_REG(hw, IXGBE_PRC127);
hwstats->prc255 += IXGBE_READ_REG(hw, IXGBE_PRC255);
hwstats->prc511 += IXGBE_READ_REG(hw, IXGBE_PRC511);
hwstats->prc1023 += IXGBE_READ_REG(hw, IXGBE_PRC1023);
hwstats->prc1522 += IXGBE_READ_REG(hw, IXGBE_PRC1522);
hwstats->rlec += IXGBE_READ_REG(hw, IXGBE_RLEC);
lxon = IXGBE_READ_REG(hw, IXGBE_LXONTXC);
hwstats->lxontxc += lxon;
lxoff = IXGBE_READ_REG(hw, IXGBE_LXOFFTXC);
hwstats->lxofftxc += lxoff;
hwstats->ruc += IXGBE_READ_REG(hw, IXGBE_RUC);
hwstats->gptc += IXGBE_READ_REG(hw, IXGBE_GPTC);
hwstats->mptc += IXGBE_READ_REG(hw, IXGBE_MPTC);
xon_off_tot = lxon + lxoff;
hwstats->gptc -= xon_off_tot;
hwstats->mptc -= xon_off_tot;
hwstats->gotc -= (xon_off_tot * (ETH_ZLEN + ETH_FCS_LEN));
hwstats->ruc += IXGBE_READ_REG(hw, IXGBE_RUC);
hwstats->rfc += IXGBE_READ_REG(hw, IXGBE_RFC);
hwstats->rjc += IXGBE_READ_REG(hw, IXGBE_RJC);
hwstats->tpr += IXGBE_READ_REG(hw, IXGBE_TPR);
hwstats->ptc64 += IXGBE_READ_REG(hw, IXGBE_PTC64);
hwstats->ptc64 -= xon_off_tot;
hwstats->ptc127 += IXGBE_READ_REG(hw, IXGBE_PTC127);
hwstats->ptc255 += IXGBE_READ_REG(hw, IXGBE_PTC255);
hwstats->ptc511 += IXGBE_READ_REG(hw, IXGBE_PTC511);
hwstats->ptc1023 += IXGBE_READ_REG(hw, IXGBE_PTC1023);
hwstats->ptc1522 += IXGBE_READ_REG(hw, IXGBE_PTC1522);
hwstats->bptc += IXGBE_READ_REG(hw, IXGBE_BPTC);
netdev->stats.multicast = hwstats->mprc;
netdev->stats.rx_errors = hwstats->crcerrs + hwstats->rlec;
netdev->stats.rx_dropped = 0;
netdev->stats.rx_length_errors = hwstats->rlec;
netdev->stats.rx_crc_errors = hwstats->crcerrs;
netdev->stats.rx_missed_errors = total_mpc;
}
static void ixgbe_fdir_reinit_subtask(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int i;
if (!(adapter->flags2 & IXGBE_FLAG2_FDIR_REQUIRES_REINIT))
return;
adapter->flags2 &= ~IXGBE_FLAG2_FDIR_REQUIRES_REINIT;
if (test_bit(__IXGBE_DOWN, &adapter->state))
return;
if (!(adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE))
return;
adapter->fdir_overflow++;
if (ixgbe_reinit_fdir_tables_82599(hw) == 0) {
for (i = 0; i < adapter->num_tx_queues; i++)
set_bit(__IXGBE_TX_FDIR_INIT_DONE,
&(adapter->tx_ring[i]->state));
IXGBE_WRITE_REG(hw, IXGBE_EIMS, IXGBE_EIMS_FLOW_DIR);
} else {
e_err(probe, "failed to finish FDIR re-initialization, "
"ignored adding FDIR ATR filters\n");
}
}
static void ixgbe_check_hang_subtask(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u64 eics = 0;
int i;
if (test_bit(__IXGBE_DOWN, &adapter->state) ||
test_bit(__IXGBE_RESETTING, &adapter->state))
return;
if (netif_carrier_ok(adapter->netdev)) {
for (i = 0; i < adapter->num_tx_queues; i++)
set_check_for_tx_hang(adapter->tx_ring[i]);
}
if (!(adapter->flags & IXGBE_FLAG_MSIX_ENABLED)) {
IXGBE_WRITE_REG(hw, IXGBE_EICS,
(IXGBE_EICS_TCP_TIMER | IXGBE_EICS_OTHER));
} else {
for (i = 0; i < adapter->num_msix_vectors - NON_Q_VECTORS; i++) {
struct ixgbe_q_vector *qv = adapter->q_vector[i];
if (qv->rxr_count || qv->txr_count)
eics |= ((u64)1 << i);
}
}
ixgbe_irq_rearm_queues(adapter, eics);
}
static void ixgbe_watchdog_update_link(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 link_speed = adapter->link_speed;
bool link_up = adapter->link_up;
int i;
if (!(adapter->flags & IXGBE_FLAG_NEED_LINK_UPDATE))
return;
if (hw->mac.ops.check_link) {
hw->mac.ops.check_link(hw, &link_speed, &link_up, false);
} else {
link_speed = IXGBE_LINK_SPEED_10GB_FULL;
link_up = true;
}
if (link_up) {
if (adapter->flags & IXGBE_FLAG_DCB_ENABLED) {
for (i = 0; i < MAX_TRAFFIC_CLASS; i++)
hw->mac.ops.fc_enable(hw, i);
} else {
hw->mac.ops.fc_enable(hw, 0);
}
}
if (link_up ||
time_after(jiffies, (adapter->link_check_timeout +
IXGBE_TRY_LINK_TIMEOUT))) {
adapter->flags &= ~IXGBE_FLAG_NEED_LINK_UPDATE;
IXGBE_WRITE_REG(hw, IXGBE_EIMS, IXGBE_EIMC_LSC);
IXGBE_WRITE_FLUSH(hw);
}
adapter->link_up = link_up;
adapter->link_speed = link_speed;
}
static void ixgbe_watchdog_link_is_up(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
u32 link_speed = adapter->link_speed;
bool flow_rx, flow_tx;
if (netif_carrier_ok(netdev))
return;
adapter->flags2 &= ~IXGBE_FLAG2_SEARCH_FOR_SFP;
switch (hw->mac.type) {
case ixgbe_mac_82598EB: {
u32 frctl = IXGBE_READ_REG(hw, IXGBE_FCTRL);
u32 rmcs = IXGBE_READ_REG(hw, IXGBE_RMCS);
flow_rx = !!(frctl & IXGBE_FCTRL_RFCE);
flow_tx = !!(rmcs & IXGBE_RMCS_TFCE_802_3X);
}
break;
case ixgbe_mac_X540:
case ixgbe_mac_82599EB: {
u32 mflcn = IXGBE_READ_REG(hw, IXGBE_MFLCN);
u32 fccfg = IXGBE_READ_REG(hw, IXGBE_FCCFG);
flow_rx = !!(mflcn & IXGBE_MFLCN_RFCE);
flow_tx = !!(fccfg & IXGBE_FCCFG_TFCE_802_3X);
}
break;
default:
flow_tx = false;
flow_rx = false;
break;
}
e_info(drv, "NIC Link is Up %s, Flow Control: %s\n",
(link_speed == IXGBE_LINK_SPEED_10GB_FULL ?
"10 Gbps" :
(link_speed == IXGBE_LINK_SPEED_1GB_FULL ?
"1 Gbps" :
(link_speed == IXGBE_LINK_SPEED_100_FULL ?
"100 Mbps" :
"unknown speed"))),
((flow_rx && flow_tx) ? "RX/TX" :
(flow_rx ? "RX" :
(flow_tx ? "TX" : "None"))));
netif_carrier_on(netdev);
#ifdef HAVE_IPLINK_VF_CONFIG
ixgbe_check_vf_rate_limit(adapter);
#endif
}
static void ixgbe_watchdog_link_is_down(struct ixgbe_adapter* adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
adapter->link_up = false;
adapter->link_speed = 0;
if (!netif_carrier_ok(netdev))
return;
if (ixgbe_is_sfp(hw) && hw->mac.type == ixgbe_mac_82598EB)
adapter->flags2 |= IXGBE_FLAG2_SEARCH_FOR_SFP;
e_info(drv, "NIC Link is Down\n");
netif_carrier_off(netdev);
}
static void ixgbe_watchdog_flush_tx(struct ixgbe_adapter *adapter)
{
int i;
int some_tx_pending = 0;
if (!netif_carrier_ok(adapter->netdev)) {
for (i = 0; i < adapter->num_tx_queues; i++) {
struct ixgbe_ring *tx_ring = adapter->tx_ring[i];
if (tx_ring->next_to_use != tx_ring->next_to_clean) {
some_tx_pending = 1;
break;
}
}
if (some_tx_pending) {
adapter->flags2 |= IXGBE_FLAG2_RESET_REQUESTED;
}
}
}
static void ixgbe_spoof_check(struct ixgbe_adapter *adapter)
{
u32 ssvpc;
if (adapter->hw.mac.type == ixgbe_mac_82598EB)
return;
ssvpc = IXGBE_READ_REG(&adapter->hw, IXGBE_SSVPC);
if (!ssvpc)
return;
e_warn(drv, "%d Spoofed packets detected\n", ssvpc);
}
static void ixgbe_watchdog_subtask(struct ixgbe_adapter *adapter)
{
if (test_bit(__IXGBE_DOWN, &adapter->state))
return;
ixgbe_watchdog_update_link(adapter);
if (adapter->link_up)
ixgbe_watchdog_link_is_up(adapter);
else
ixgbe_watchdog_link_is_down(adapter);
ixgbe_spoof_check(adapter);
ixgbe_update_stats(adapter);
ixgbe_watchdog_flush_tx(adapter);
}
static void ixgbe_sfp_detection_subtask(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
s32 err;
if (!(adapter->flags2 & IXGBE_FLAG2_SEARCH_FOR_SFP) &&
!(adapter->flags2 & IXGBE_FLAG2_SFP_NEEDS_RESET))
return;
if (test_and_set_bit(__IXGBE_IN_SFP_INIT, &adapter->state))
return;
err = hw->phy.ops.identify_sfp(hw);
if (err == IXGBE_ERR_SFP_NOT_SUPPORTED)
goto sfp_out;
if (err == IXGBE_ERR_SFP_NOT_PRESENT) {
adapter->flags2 |= IXGBE_FLAG2_SFP_NEEDS_RESET;
}
if (err)
goto sfp_out;
if (!(adapter->flags2 & IXGBE_FLAG2_SFP_NEEDS_RESET))
goto sfp_out;
adapter->flags2 &= ~IXGBE_FLAG2_SFP_NEEDS_RESET;
if (hw->mac.type == ixgbe_mac_82598EB)
err = hw->phy.ops.reset(hw);
else
err = hw->mac.ops.setup_sfp(hw);
if (err == IXGBE_ERR_SFP_NOT_SUPPORTED)
goto sfp_out;
adapter->flags |= IXGBE_FLAG_NEED_LINK_CONFIG;
e_info(probe, "detected SFP+: %d\n", hw->phy.sfp_type);
sfp_out:
clear_bit(__IXGBE_IN_SFP_INIT, &adapter->state);
if ((err == IXGBE_ERR_SFP_NOT_SUPPORTED) &&
(adapter->netdev->reg_state == NETREG_REGISTERED)) {
e_dev_err("failed to initialize because an unsupported "
"SFP+ module type was detected.\n");
e_dev_err("Reload the driver after installing a "
"supported module.\n");
unregister_netdev(adapter->netdev);
}
}
static void ixgbe_sfp_link_config_subtask(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 autoneg;
bool negotiation;
if (!(adapter->flags & IXGBE_FLAG_NEED_LINK_CONFIG))
return;
if (test_and_set_bit(__IXGBE_IN_SFP_INIT, &adapter->state))
return;
adapter->flags &= ~IXGBE_FLAG_NEED_LINK_CONFIG;
autoneg = hw->phy.autoneg_advertised;
if ((!autoneg) && (hw->mac.ops.get_link_capabilities))
hw->mac.ops.get_link_capabilities(hw, &autoneg, &negotiation);
hw->mac.autotry_restart = false;
if (hw->mac.ops.setup_link)
hw->mac.ops.setup_link(hw, autoneg, negotiation, true);
adapter->flags |= IXGBE_FLAG_NEED_LINK_UPDATE;
adapter->link_check_timeout = jiffies;
clear_bit(__IXGBE_IN_SFP_INIT, &adapter->state);
}
static void ixgbe_service_timer(unsigned long data)
{
struct ixgbe_adapter *adapter = (struct ixgbe_adapter *)data;
unsigned long next_event_offset;
if (adapter->flags & IXGBE_FLAG_NEED_LINK_UPDATE)
next_event_offset = HZ / 10;
else
next_event_offset = HZ * 2;
mod_timer(&adapter->service_timer, next_event_offset + jiffies);
ixgbe_service_event_schedule(adapter);
}
static void ixgbe_reset_subtask(struct ixgbe_adapter *adapter)
{
if (!(adapter->flags2 & IXGBE_FLAG2_RESET_REQUESTED))
return;
adapter->flags2 &= ~IXGBE_FLAG2_RESET_REQUESTED;
if (test_bit(__IXGBE_DOWN, &adapter->state) ||
test_bit(__IXGBE_RESETTING, &adapter->state))
return;
ixgbe_dump(adapter);
netdev_err(adapter->netdev, "Reset adapter\n");
adapter->tx_timeout_count++;
ixgbe_reinit_locked(adapter);
}
static void ixgbe_service_task(struct work_struct *work)
{
struct ixgbe_adapter *adapter = container_of(work,
struct ixgbe_adapter,
service_task);
ixgbe_reset_subtask(adapter);
ixgbe_sfp_detection_subtask(adapter);
ixgbe_sfp_link_config_subtask(adapter);
ixgbe_check_overtemp_subtask(adapter);
ixgbe_watchdog_subtask(adapter);
ixgbe_fdir_reinit_subtask(adapter);
ixgbe_check_hang_subtask(adapter);
ixgbe_service_event_complete(adapter);
}
static int ixgbe_tso(struct ixgbe_adapter *adapter,
struct ixgbe_ring *tx_ring, struct sk_buff *skb,
u32 tx_flags, u8 *hdr_len, __be16 protocol)
{
struct ixgbe_adv_tx_context_desc *context_desc;
unsigned int i;
int err;
struct ixgbe_tx_buffer *tx_buffer_info;
u32 vlan_macip_lens = 0, type_tucmd_mlhl;
u32 mss_l4len_idx, l4len;
if (skb_is_gso(skb)) {
if (skb_header_cloned(skb)) {
err = pskb_expand_head(skb, 0, 0, GFP_ATOMIC);
if (err)
return err;
}
l4len = tcp_hdrlen(skb);
*hdr_len += l4len;
if (protocol == htons(ETH_P_IP)) {
struct iphdr *iph = ip_hdr(skb);
iph->tot_len = 0;
iph->check = 0;
tcp_hdr(skb)->check = ~csum_tcpudp_magic(iph->saddr,
iph->daddr, 0,
IPPROTO_TCP,
0);
} else if (skb_is_gso_v6(skb)) {
ipv6_hdr(skb)->payload_len = 0;
tcp_hdr(skb)->check =
~csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr,
0, IPPROTO_TCP, 0);
}
i = tx_ring->next_to_use;
tx_buffer_info = &tx_ring->tx_buffer_info[i];
context_desc = IXGBE_TX_CTXTDESC_ADV(tx_ring, i);
if (tx_flags & IXGBE_TX_FLAGS_VLAN)
vlan_macip_lens |=
(tx_flags & IXGBE_TX_FLAGS_VLAN_MASK);
vlan_macip_lens |= ((skb_network_offset(skb)) <<
IXGBE_ADVTXD_MACLEN_SHIFT);
*hdr_len += skb_network_offset(skb);
vlan_macip_lens |=
(skb_transport_header(skb) - skb_network_header(skb));
*hdr_len +=
(skb_transport_header(skb) - skb_network_header(skb));
context_desc->vlan_macip_lens = cpu_to_le32(vlan_macip_lens);
context_desc->seqnum_seed = 0;
type_tucmd_mlhl = (IXGBE_TXD_CMD_DEXT |
IXGBE_ADVTXD_DTYP_CTXT);
if (protocol == htons(ETH_P_IP))
type_tucmd_mlhl |= IXGBE_ADVTXD_TUCMD_IPV4;
type_tucmd_mlhl |= IXGBE_ADVTXD_TUCMD_L4T_TCP;
context_desc->type_tucmd_mlhl = cpu_to_le32(type_tucmd_mlhl);
mss_l4len_idx =
(skb_shinfo(skb)->gso_size << IXGBE_ADVTXD_MSS_SHIFT);
mss_l4len_idx |= (l4len << IXGBE_ADVTXD_L4LEN_SHIFT);
mss_l4len_idx |= (1 << IXGBE_ADVTXD_IDX_SHIFT);
context_desc->mss_l4len_idx = cpu_to_le32(mss_l4len_idx);
tx_buffer_info->time_stamp = jiffies;
tx_buffer_info->next_to_watch = i;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
return true;
}
return false;
}
static u32 ixgbe_psum(struct ixgbe_adapter *adapter, struct sk_buff *skb,
__be16 protocol)
{
u32 rtn = 0;
switch (protocol) {
case cpu_to_be16(ETH_P_IP):
rtn |= IXGBE_ADVTXD_TUCMD_IPV4;
switch (ip_hdr(skb)->protocol) {
case IPPROTO_TCP:
rtn |= IXGBE_ADVTXD_TUCMD_L4T_TCP;
break;
case IPPROTO_SCTP:
rtn |= IXGBE_ADVTXD_TUCMD_L4T_SCTP;
break;
}
break;
case cpu_to_be16(ETH_P_IPV6):
switch (ipv6_hdr(skb)->nexthdr) {
case IPPROTO_TCP:
rtn |= IXGBE_ADVTXD_TUCMD_L4T_TCP;
break;
case IPPROTO_SCTP:
rtn |= IXGBE_ADVTXD_TUCMD_L4T_SCTP;
break;
}
break;
default:
if (unlikely(net_ratelimit()))
e_warn(probe, "partial checksum but proto=%x!\n",
protocol);
break;
}
return rtn;
}
static bool ixgbe_tx_csum(struct ixgbe_adapter *adapter,
struct ixgbe_ring *tx_ring,
struct sk_buff *skb, u32 tx_flags,
__be16 protocol)
{
struct ixgbe_adv_tx_context_desc *context_desc;
unsigned int i;
struct ixgbe_tx_buffer *tx_buffer_info;
u32 vlan_macip_lens = 0, type_tucmd_mlhl = 0;
if (skb->ip_summed == CHECKSUM_PARTIAL ||
(tx_flags & IXGBE_TX_FLAGS_VLAN)) {
i = tx_ring->next_to_use;
tx_buffer_info = &tx_ring->tx_buffer_info[i];
context_desc = IXGBE_TX_CTXTDESC_ADV(tx_ring, i);
if (tx_flags & IXGBE_TX_FLAGS_VLAN)
vlan_macip_lens |=
(tx_flags & IXGBE_TX_FLAGS_VLAN_MASK);
vlan_macip_lens |= (skb_network_offset(skb) <<
IXGBE_ADVTXD_MACLEN_SHIFT);
if (skb->ip_summed == CHECKSUM_PARTIAL)
vlan_macip_lens |= (skb_transport_header(skb) -
skb_network_header(skb));
context_desc->vlan_macip_lens = cpu_to_le32(vlan_macip_lens);
context_desc->seqnum_seed = 0;
type_tucmd_mlhl |= (IXGBE_TXD_CMD_DEXT |
IXGBE_ADVTXD_DTYP_CTXT);
if (skb->ip_summed == CHECKSUM_PARTIAL)
type_tucmd_mlhl |= ixgbe_psum(adapter, skb, protocol);
context_desc->type_tucmd_mlhl = cpu_to_le32(type_tucmd_mlhl);
context_desc->mss_l4len_idx = 0;
tx_buffer_info->time_stamp = jiffies;
tx_buffer_info->next_to_watch = i;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
return true;
}
return false;
}
static int ixgbe_tx_map(struct ixgbe_adapter *adapter,
struct ixgbe_ring *tx_ring,
struct sk_buff *skb, u32 tx_flags,
unsigned int first, const u8 hdr_len)
{
struct device *dev = tx_ring->dev;
struct ixgbe_tx_buffer *tx_buffer_info;
unsigned int len;
unsigned int total = skb->len;
unsigned int offset = 0, size, count = 0, i;
unsigned int nr_frags = skb_shinfo(skb)->nr_frags;
unsigned int f;
unsigned int bytecount = skb->len;
u16 gso_segs = 1;
i = tx_ring->next_to_use;
if (tx_flags & IXGBE_TX_FLAGS_FCOE)
total -= sizeof(struct fcoe_crc_eof);
len = min(skb_headlen(skb), total);
while (len) {
tx_buffer_info = &tx_ring->tx_buffer_info[i];
size = min(len, (uint)IXGBE_MAX_DATA_PER_TXD);
tx_buffer_info->length = size;
tx_buffer_info->mapped_as_page = false;
tx_buffer_info->dma = dma_map_single(dev,
skb->data + offset,
size, DMA_TO_DEVICE);
if (dma_mapping_error(dev, tx_buffer_info->dma))
goto dma_error;
tx_buffer_info->time_stamp = jiffies;
tx_buffer_info->next_to_watch = i;
len -= size;
total -= size;
offset += size;
count++;
if (len) {
i++;
if (i == tx_ring->count)
i = 0;
}
}
for (f = 0; f < nr_frags; f++) {
struct skb_frag_struct *frag;
frag = &skb_shinfo(skb)->frags[f];
len = min((unsigned int)frag->size, total);
offset = frag->page_offset;
while (len) {
i++;
if (i == tx_ring->count)
i = 0;
tx_buffer_info = &tx_ring->tx_buffer_info[i];
size = min(len, (uint)IXGBE_MAX_DATA_PER_TXD);
tx_buffer_info->length = size;
tx_buffer_info->dma = dma_map_page(dev,
frag->page,
offset, size,
DMA_TO_DEVICE);
tx_buffer_info->mapped_as_page = true;
if (dma_mapping_error(dev, tx_buffer_info->dma))
goto dma_error;
tx_buffer_info->time_stamp = jiffies;
tx_buffer_info->next_to_watch = i;
len -= size;
total -= size;
offset += size;
count++;
}
if (total == 0)
break;
}
if (tx_flags & IXGBE_TX_FLAGS_TSO)
gso_segs = skb_shinfo(skb)->gso_segs;
#ifdef IXGBE_FCOE
else if (tx_flags & IXGBE_TX_FLAGS_FSO)
gso_segs = DIV_ROUND_UP(skb->len - hdr_len,
skb_shinfo(skb)->gso_size);
#endif
bytecount += (gso_segs - 1) * hdr_len;
tx_ring->tx_buffer_info[i].bytecount = bytecount;
tx_ring->tx_buffer_info[i].gso_segs = gso_segs;
tx_ring->tx_buffer_info[i].skb = skb;
tx_ring->tx_buffer_info[first].next_to_watch = i;
return count;
dma_error:
e_dev_err("TX DMA map failed\n");
tx_buffer_info->dma = 0;
tx_buffer_info->time_stamp = 0;
tx_buffer_info->next_to_watch = 0;
if (count)
count--;
while (count--) {
if (i == 0)
i += tx_ring->count;
i--;
tx_buffer_info = &tx_ring->tx_buffer_info[i];
ixgbe_unmap_and_free_tx_resource(tx_ring, tx_buffer_info);
}
return 0;
}
static void ixgbe_tx_queue(struct ixgbe_ring *tx_ring,
int tx_flags, int count, u32 paylen, u8 hdr_len)
{
union ixgbe_adv_tx_desc *tx_desc = NULL;
struct ixgbe_tx_buffer *tx_buffer_info;
u32 olinfo_status = 0, cmd_type_len = 0;
unsigned int i;
u32 txd_cmd = IXGBE_TXD_CMD_EOP | IXGBE_TXD_CMD_RS | IXGBE_TXD_CMD_IFCS;
cmd_type_len |= IXGBE_ADVTXD_DTYP_DATA;
cmd_type_len |= IXGBE_ADVTXD_DCMD_IFCS | IXGBE_ADVTXD_DCMD_DEXT;
if (tx_flags & IXGBE_TX_FLAGS_VLAN)
cmd_type_len |= IXGBE_ADVTXD_DCMD_VLE;
if (tx_flags & IXGBE_TX_FLAGS_TSO) {
cmd_type_len |= IXGBE_ADVTXD_DCMD_TSE;
olinfo_status |= IXGBE_TXD_POPTS_TXSM <<
IXGBE_ADVTXD_POPTS_SHIFT;
olinfo_status |= (1 << IXGBE_ADVTXD_IDX_SHIFT);
if (tx_flags & IXGBE_TX_FLAGS_IPV4)
olinfo_status |= IXGBE_TXD_POPTS_IXSM <<
IXGBE_ADVTXD_POPTS_SHIFT;
} else if (tx_flags & IXGBE_TX_FLAGS_CSUM)
olinfo_status |= IXGBE_TXD_POPTS_TXSM <<
IXGBE_ADVTXD_POPTS_SHIFT;
if (tx_flags & IXGBE_TX_FLAGS_FCOE) {
olinfo_status |= IXGBE_ADVTXD_CC;
olinfo_status |= (1 << IXGBE_ADVTXD_IDX_SHIFT);
if (tx_flags & IXGBE_TX_FLAGS_FSO)
cmd_type_len |= IXGBE_ADVTXD_DCMD_TSE;
}
olinfo_status |= ((paylen - hdr_len) << IXGBE_ADVTXD_PAYLEN_SHIFT);
i = tx_ring->next_to_use;
while (count--) {
tx_buffer_info = &tx_ring->tx_buffer_info[i];
tx_desc = IXGBE_TX_DESC_ADV(tx_ring, i);
tx_desc->read.buffer_addr = cpu_to_le64(tx_buffer_info->dma);
tx_desc->read.cmd_type_len =
cpu_to_le32(cmd_type_len | tx_buffer_info->length);
tx_desc->read.olinfo_status = cpu_to_le32(olinfo_status);
i++;
if (i == tx_ring->count)
i = 0;
}
tx_desc->read.cmd_type_len |= cpu_to_le32(txd_cmd);
wmb();
tx_ring->next_to_use = i;
writel(i, tx_ring->tail);
}
static void ixgbe_atr(struct ixgbe_ring *ring, struct sk_buff *skb,
u32 tx_flags, __be16 protocol)
{
struct ixgbe_q_vector *q_vector = ring->q_vector;
union ixgbe_atr_hash_dword input = { .dword = 0 };
union ixgbe_atr_hash_dword common = { .dword = 0 };
union {
unsigned char *network;
struct iphdr *ipv4;
struct ipv6hdr *ipv6;
} hdr;
struct tcphdr *th;
__be16 vlan_id;
if (!q_vector)
return;
if (!ring->atr_sample_rate)
return;
ring->atr_count++;
hdr.network = skb_network_header(skb);
if ((protocol != __constant_htons(ETH_P_IPV6) ||
hdr.ipv6->nexthdr != IPPROTO_TCP) &&
(protocol != __constant_htons(ETH_P_IP) ||
hdr.ipv4->protocol != IPPROTO_TCP))
return;
th = tcp_hdr(skb);
if (th->fin)
return;
if (!th->syn && (ring->atr_count < ring->atr_sample_rate))
return;
ring->atr_count = 0;
vlan_id = htons(tx_flags >> IXGBE_TX_FLAGS_VLAN_SHIFT);
input.formatted.vlan_id = vlan_id;
if (vlan_id)
common.port.src ^= th->dest ^ __constant_htons(ETH_P_8021Q);
else
common.port.src ^= th->dest ^ protocol;
common.port.dst ^= th->source;
if (protocol == __constant_htons(ETH_P_IP)) {
input.formatted.flow_type = IXGBE_ATR_FLOW_TYPE_TCPV4;
common.ip ^= hdr.ipv4->saddr ^ hdr.ipv4->daddr;
} else {
input.formatted.flow_type = IXGBE_ATR_FLOW_TYPE_TCPV6;
common.ip ^= hdr.ipv6->saddr.s6_addr32[0] ^
hdr.ipv6->saddr.s6_addr32[1] ^
hdr.ipv6->saddr.s6_addr32[2] ^
hdr.ipv6->saddr.s6_addr32[3] ^
hdr.ipv6->daddr.s6_addr32[0] ^
hdr.ipv6->daddr.s6_addr32[1] ^
hdr.ipv6->daddr.s6_addr32[2] ^
hdr.ipv6->daddr.s6_addr32[3];
}
ixgbe_fdir_add_signature_filter_82599(&q_vector->adapter->hw,
input, common, ring->queue_index);
}
static int __ixgbe_maybe_stop_tx(struct ixgbe_ring *tx_ring, int size)
{
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
smp_mb();
if (likely(IXGBE_DESC_UNUSED(tx_ring) < size))
return -EBUSY;
netif_start_subqueue(tx_ring->netdev, tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
return 0;
}
static int ixgbe_maybe_stop_tx(struct ixgbe_ring *tx_ring, int size)
{
if (likely(IXGBE_DESC_UNUSED(tx_ring) >= size))
return 0;
return __ixgbe_maybe_stop_tx(tx_ring, size);
}
static u16 ixgbe_select_queue(struct net_device *dev, struct sk_buff *skb)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
int txq = smp_processor_id();
#ifdef IXGBE_FCOE
__be16 protocol;
protocol = vlan_get_protocol(skb);
if (((protocol == htons(ETH_P_FCOE)) ||
(protocol == htons(ETH_P_FIP))) &&
(adapter->flags & IXGBE_FLAG_FCOE_ENABLED)) {
txq &= (adapter->ring_feature[RING_F_FCOE].indices - 1);
txq += adapter->ring_feature[RING_F_FCOE].mask;
return txq;
}
#endif
if (adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) {
while (unlikely(txq >= dev->real_num_tx_queues))
txq -= dev->real_num_tx_queues;
return txq;
}
return skb_tx_hash(dev, skb);
}
netdev_tx_t ixgbe_xmit_frame_ring(struct sk_buff *skb,
struct ixgbe_adapter *adapter,
struct ixgbe_ring *tx_ring)
{
unsigned int first;
unsigned int tx_flags = 0;
u8 hdr_len = 0;
int tso;
int count = 0;
unsigned int f;
__be16 protocol;
protocol = vlan_get_protocol(skb);
if (vlan_tx_tag_present(skb)) {
tx_flags |= vlan_tx_tag_get(skb);
if (adapter->flags & IXGBE_FLAG_DCB_ENABLED) {
tx_flags &= ~IXGBE_TX_FLAGS_VLAN_PRIO_MASK;
tx_flags |= tx_ring->dcb_tc << 13;
}
tx_flags <<= IXGBE_TX_FLAGS_VLAN_SHIFT;
tx_flags |= IXGBE_TX_FLAGS_VLAN;
} else if (adapter->flags & IXGBE_FLAG_DCB_ENABLED &&
skb->priority != TC_PRIO_CONTROL) {
tx_flags |= tx_ring->dcb_tc << 13;
tx_flags <<= IXGBE_TX_FLAGS_VLAN_SHIFT;
tx_flags |= IXGBE_TX_FLAGS_VLAN;
}
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED &&
(protocol == htons(ETH_P_FCOE)))
tx_flags |= IXGBE_TX_FLAGS_FCOE;
#endif
if (skb_is_gso(skb) ||
(skb->ip_summed == CHECKSUM_PARTIAL) ||
(tx_flags & IXGBE_TX_FLAGS_VLAN) ||
(tx_flags & IXGBE_TX_FLAGS_FCOE))
count++;
count += TXD_USE_COUNT(skb_headlen(skb));
for (f = 0; f < skb_shinfo(skb)->nr_frags; f++)
count += TXD_USE_COUNT(skb_shinfo(skb)->frags[f].size);
if (ixgbe_maybe_stop_tx(tx_ring, count)) {
tx_ring->tx_stats.tx_busy++;
return NETDEV_TX_BUSY;
}
first = tx_ring->next_to_use;
if (tx_flags & IXGBE_TX_FLAGS_FCOE) {
#ifdef IXGBE_FCOE
tso = ixgbe_fso(adapter, tx_ring, skb, tx_flags, &hdr_len);
if (tso < 0) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
if (tso)
tx_flags |= IXGBE_TX_FLAGS_FSO;
#endif
} else {
if (protocol == htons(ETH_P_IP))
tx_flags |= IXGBE_TX_FLAGS_IPV4;
tso = ixgbe_tso(adapter, tx_ring, skb, tx_flags, &hdr_len,
protocol);
if (tso < 0) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
if (tso)
tx_flags |= IXGBE_TX_FLAGS_TSO;
else if (ixgbe_tx_csum(adapter, tx_ring, skb, tx_flags,
protocol) &&
(skb->ip_summed == CHECKSUM_PARTIAL))
tx_flags |= IXGBE_TX_FLAGS_CSUM;
}
count = ixgbe_tx_map(adapter, tx_ring, skb, tx_flags, first, hdr_len);
if (count) {
if (test_bit(__IXGBE_TX_FDIR_INIT_DONE, &tx_ring->state))
ixgbe_atr(tx_ring, skb, tx_flags, protocol);
ixgbe_tx_queue(tx_ring, tx_flags, count, skb->len, hdr_len);
ixgbe_maybe_stop_tx(tx_ring, DESC_NEEDED);
} else {
dev_kfree_skb_any(skb);
tx_ring->tx_buffer_info[first].time_stamp = 0;
tx_ring->next_to_use = first;
}
return NETDEV_TX_OK;
}
static netdev_tx_t ixgbe_xmit_frame(struct sk_buff *skb, struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_ring *tx_ring;
tx_ring = adapter->tx_ring[skb->queue_mapping];
return ixgbe_xmit_frame_ring(skb, adapter, tx_ring);
}
static int ixgbe_set_mac(struct net_device *netdev, void *p)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
memcpy(hw->mac.addr, addr->sa_data, netdev->addr_len);
hw->mac.ops.set_rar(hw, 0, hw->mac.addr, adapter->num_vfs,
IXGBE_RAH_AV);
return 0;
}
static int
ixgbe_mdio_read(struct net_device *netdev, int prtad, int devad, u16 addr)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
u16 value;
int rc;
if (prtad != hw->phy.mdio.prtad)
return -EINVAL;
rc = hw->phy.ops.read_reg(hw, addr, devad, &value);
if (!rc)
rc = value;
return rc;
}
static int ixgbe_mdio_write(struct net_device *netdev, int prtad, int devad,
u16 addr, u16 value)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
if (prtad != hw->phy.mdio.prtad)
return -EINVAL;
return hw->phy.ops.write_reg(hw, addr, devad, value);
}
static int ixgbe_ioctl(struct net_device *netdev, struct ifreq *req, int cmd)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
return mdio_mii_ioctl(&adapter->hw.phy.mdio, if_mii(req), cmd);
}
static int ixgbe_add_sanmac_netdev(struct net_device *dev)
{
int err = 0;
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct ixgbe_mac_info *mac = &adapter->hw.mac;
if (is_valid_ether_addr(mac->san_addr)) {
rtnl_lock();
err = dev_addr_add(dev, mac->san_addr, NETDEV_HW_ADDR_T_SAN);
rtnl_unlock();
}
return err;
}
static int ixgbe_del_sanmac_netdev(struct net_device *dev)
{
int err = 0;
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct ixgbe_mac_info *mac = &adapter->hw.mac;
if (is_valid_ether_addr(mac->san_addr)) {
rtnl_lock();
err = dev_addr_del(dev, mac->san_addr, NETDEV_HW_ADDR_T_SAN);
rtnl_unlock();
}
return err;
}
static void ixgbe_netpoll(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int i;
if (test_bit(__IXGBE_DOWN, &adapter->state))
return;
adapter->flags |= IXGBE_FLAG_IN_NETPOLL;
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED) {
int num_q_vectors = adapter->num_msix_vectors - NON_Q_VECTORS;
for (i = 0; i < num_q_vectors; i++) {
struct ixgbe_q_vector *q_vector = adapter->q_vector[i];
ixgbe_msix_clean_many(0, q_vector);
}
} else {
ixgbe_intr(adapter->pdev->irq, netdev);
}
adapter->flags &= ~IXGBE_FLAG_IN_NETPOLL;
}
static struct rtnl_link_stats64 *ixgbe_get_stats64(struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int i;
rcu_read_lock();
for (i = 0; i < adapter->num_rx_queues; i++) {
struct ixgbe_ring *ring = ACCESS_ONCE(adapter->rx_ring[i]);
u64 bytes, packets;
unsigned int start;
if (ring) {
do {
start = u64_stats_fetch_begin_bh(&ring->syncp);
packets = ring->stats.packets;
bytes = ring->stats.bytes;
} while (u64_stats_fetch_retry_bh(&ring->syncp, start));
stats->rx_packets += packets;
stats->rx_bytes += bytes;
}
}
for (i = 0; i < adapter->num_tx_queues; i++) {
struct ixgbe_ring *ring = ACCESS_ONCE(adapter->tx_ring[i]);
u64 bytes, packets;
unsigned int start;
if (ring) {
do {
start = u64_stats_fetch_begin_bh(&ring->syncp);
packets = ring->stats.packets;
bytes = ring->stats.bytes;
} while (u64_stats_fetch_retry_bh(&ring->syncp, start));
stats->tx_packets += packets;
stats->tx_bytes += bytes;
}
}
rcu_read_unlock();
stats->multicast = netdev->stats.multicast;
stats->rx_errors = netdev->stats.rx_errors;
stats->rx_length_errors = netdev->stats.rx_length_errors;
stats->rx_crc_errors = netdev->stats.rx_crc_errors;
stats->rx_missed_errors = netdev->stats.rx_missed_errors;
return stats;
}
static void __devinit ixgbe_probe_vf(struct ixgbe_adapter *adapter,
const struct ixgbe_info *ii)
{
#ifdef CONFIG_PCI_IOV
struct ixgbe_hw *hw = &adapter->hw;
int err;
int num_vf_macvlans, i;
struct vf_macvlans *mv_list;
if (hw->mac.type == ixgbe_mac_82598EB || !max_vfs)
return;
adapter->num_vfs = (max_vfs > 63) ? 63 : max_vfs;
adapter->flags |= IXGBE_FLAG_SRIOV_ENABLED;
err = pci_enable_sriov(adapter->pdev, adapter->num_vfs);
if (err) {
e_err(probe, "Failed to enable PCI sriov: %d\n", err);
goto err_novfs;
}
num_vf_macvlans = hw->mac.num_rar_entries -
(IXGBE_MAX_PF_MACVLANS + 1 + adapter->num_vfs);
adapter->mv_list = mv_list = kcalloc(num_vf_macvlans,
sizeof(struct vf_macvlans),
GFP_KERNEL);
if (mv_list) {
INIT_LIST_HEAD(&adapter->vf_mvs.l);
for (i = 0; i < num_vf_macvlans; i++) {
mv_list->vf = -1;
mv_list->free = true;
mv_list->rar_entry = hw->mac.num_rar_entries -
(i + adapter->num_vfs + 1);
list_add(&mv_list->l, &adapter->vf_mvs.l);
mv_list++;
}
}
adapter->vfinfo =
kcalloc(adapter->num_vfs,
sizeof(struct vf_data_storage), GFP_KERNEL);
if (adapter->vfinfo) {
ixgbe_init_mbx_params_pf(hw);
memcpy(&hw->mbx.ops, ii->mbx_ops,
sizeof(hw->mbx.ops));
adapter->flags2 &= ~(IXGBE_FLAG2_RSC_CAPABLE |
IXGBE_FLAG2_RSC_ENABLED);
return;
}
e_err(probe, "Unable to allocate memory for VF Data Storage - "
"SRIOV disabled\n");
pci_disable_sriov(adapter->pdev);
err_novfs:
adapter->flags &= ~IXGBE_FLAG_SRIOV_ENABLED;
adapter->num_vfs = 0;
#endif
}
static int __devinit ixgbe_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *netdev;
struct ixgbe_adapter *adapter = NULL;
struct ixgbe_hw *hw;
const struct ixgbe_info *ii = ixgbe_info_tbl[ent->driver_data];
static int cards_found;
int i, err, pci_using_dac;
u8 part_str[IXGBE_PBANUM_LENGTH];
unsigned int indices = num_possible_cpus();
#ifdef IXGBE_FCOE
u16 device_caps;
#endif
u32 eec;
if (pdev->is_virtfn) {
WARN(1, KERN_ERR "%s (%hx:%hx) should not be a VF!\n",
pci_name(pdev), pdev->vendor, pdev->device);
return -EINVAL;
}
err = pci_enable_device_mem(pdev);
if (err)
return err;
if (!dma_set_mask(&pdev->dev, DMA_BIT_MASK(64)) &&
!dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(64))) {
pci_using_dac = 1;
} else {
err = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
err = dma_set_coherent_mask(&pdev->dev,
DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev,
"No usable DMA configuration, aborting\n");
goto err_dma;
}
}
pci_using_dac = 0;
}
err = pci_request_selected_regions(pdev, pci_select_bars(pdev,
IORESOURCE_MEM), ixgbe_driver_name);
if (err) {
dev_err(&pdev->dev,
"pci_request_selected_regions failed 0x%x\n", err);
goto err_pci_reg;
}
pci_enable_pcie_error_reporting(pdev);
pci_set_master(pdev);
pci_save_state(pdev);
if (ii->mac == ixgbe_mac_82598EB)
indices = min_t(unsigned int, indices, IXGBE_MAX_RSS_INDICES);
else
indices = min_t(unsigned int, indices, IXGBE_MAX_FDIR_INDICES);
#if defined(CONFIG_DCB)
indices = max_t(unsigned int, indices, IXGBE_MAX_DCB_INDICES);
#elif defined(IXGBE_FCOE)
indices += min_t(unsigned int, num_possible_cpus(),
IXGBE_MAX_FCOE_INDICES);
#endif
netdev = alloc_etherdev_mq(sizeof(struct ixgbe_adapter), indices);
if (!netdev) {
err = -ENOMEM;
goto err_alloc_etherdev;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
adapter = netdev_priv(netdev);
pci_set_drvdata(pdev, adapter);
adapter->netdev = netdev;
adapter->pdev = pdev;
hw = &adapter->hw;
hw->back = adapter;
adapter->msg_enable = (1 << DEFAULT_DEBUG_LEVEL_SHIFT) - 1;
hw->hw_addr = ioremap(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
if (!hw->hw_addr) {
err = -EIO;
goto err_ioremap;
}
for (i = 1; i <= 5; i++) {
if (pci_resource_len(pdev, i) == 0)
continue;
}
netdev->netdev_ops = &ixgbe_netdev_ops;
ixgbe_set_ethtool_ops(netdev);
netdev->watchdog_timeo = 5 * HZ;
strncpy(netdev->name, pci_name(pdev), sizeof(netdev->name) - 1);
adapter->bd_number = cards_found;
memcpy(&hw->mac.ops, ii->mac_ops, sizeof(hw->mac.ops));
hw->mac.type = ii->mac;
memcpy(&hw->eeprom.ops, ii->eeprom_ops, sizeof(hw->eeprom.ops));
eec = IXGBE_READ_REG(hw, IXGBE_EEC);
if (!(eec & (1 << 8)))
hw->eeprom.ops.read = &ixgbe_read_eeprom_bit_bang_generic;
memcpy(&hw->phy.ops, ii->phy_ops, sizeof(hw->phy.ops));
hw->phy.sfp_type = ixgbe_sfp_type_unknown;
hw->phy.mdio.prtad = MDIO_PRTAD_NONE;
hw->phy.mdio.mmds = 0;
hw->phy.mdio.mode_support = MDIO_SUPPORTS_C45 | MDIO_EMULATE_C22;
hw->phy.mdio.dev = netdev;
hw->phy.mdio.mdio_read = ixgbe_mdio_read;
hw->phy.mdio.mdio_write = ixgbe_mdio_write;
ii->get_invariants(hw);
err = ixgbe_sw_init(adapter);
if (err)
goto err_sw_init;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
IXGBE_WRITE_REG(&adapter->hw, IXGBE_WUS, ~0);
break;
default:
break;
}
if (adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE) {
u32 esdp = IXGBE_READ_REG(hw, IXGBE_ESDP);
if (esdp & IXGBE_ESDP_SDP1)
e_crit(probe, "Fan has stopped, replace the adapter\n");
}
hw->phy.reset_if_overtemp = true;
err = hw->mac.ops.reset_hw(hw);
hw->phy.reset_if_overtemp = false;
if (err == IXGBE_ERR_SFP_NOT_PRESENT &&
hw->mac.type == ixgbe_mac_82598EB) {
err = 0;
} else if (err == IXGBE_ERR_SFP_NOT_SUPPORTED) {
e_dev_err("failed to load because an unsupported SFP+ "
"module type was detected.\n");
e_dev_err("Reload the driver after installing a supported "
"module.\n");
goto err_sw_init;
} else if (err) {
e_dev_err("HW Init failed: %d\n", err);
goto err_sw_init;
}
ixgbe_probe_vf(adapter, ii);
netdev->features = NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_HW_VLAN_TX |
NETIF_F_HW_VLAN_RX |
NETIF_F_HW_VLAN_FILTER;
netdev->features |= NETIF_F_IPV6_CSUM;
netdev->features |= NETIF_F_TSO;
netdev->features |= NETIF_F_TSO6;
netdev->features |= NETIF_F_GRO;
netdev->features |= NETIF_F_RXHASH;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
netdev->features |= NETIF_F_SCTP_CSUM;
break;
default:
break;
}
netdev->vlan_features |= NETIF_F_TSO;
netdev->vlan_features |= NETIF_F_TSO6;
netdev->vlan_features |= NETIF_F_IP_CSUM;
netdev->vlan_features |= NETIF_F_IPV6_CSUM;
netdev->vlan_features |= NETIF_F_SG;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
adapter->flags &= ~(IXGBE_FLAG_RSS_ENABLED |
IXGBE_FLAG_DCB_ENABLED);
#ifdef CONFIG_IXGBE_DCB
netdev->dcbnl_ops = &dcbnl_ops;
#endif
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_CAPABLE) {
if (hw->mac.ops.get_device_caps) {
hw->mac.ops.get_device_caps(hw, &device_caps);
if (device_caps & IXGBE_DEVICE_CAPS_FCOE_OFFLOADS)
adapter->flags &= ~IXGBE_FLAG_FCOE_CAPABLE;
}
}
if (adapter->flags & IXGBE_FLAG_FCOE_CAPABLE) {
netdev->vlan_features |= NETIF_F_FCOE_CRC;
netdev->vlan_features |= NETIF_F_FSO;
netdev->vlan_features |= NETIF_F_FCOE_MTU;
}
#endif
if (pci_using_dac) {
netdev->features |= NETIF_F_HIGHDMA;
netdev->vlan_features |= NETIF_F_HIGHDMA;
}
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)
netdev->features |= NETIF_F_LRO;
if (hw->eeprom.ops.validate_checksum(hw, NULL) < 0) {
e_dev_err("The EEPROM Checksum Is Not Valid\n");
err = -EIO;
goto err_eeprom;
}
memcpy(netdev->dev_addr, hw->mac.perm_addr, netdev->addr_len);
memcpy(netdev->perm_addr, hw->mac.perm_addr, netdev->addr_len);
if (ixgbe_validate_mac_addr(netdev->perm_addr)) {
e_dev_err("invalid MAC address\n");
err = -EIO;
goto err_eeprom;
}
if (hw->mac.ops.disable_tx_laser &&
((hw->phy.multispeed_fiber) ||
((hw->mac.ops.get_media_type(hw) == ixgbe_media_type_fiber) &&
(hw->mac.type == ixgbe_mac_82599EB))))
hw->mac.ops.disable_tx_laser(hw);
setup_timer(&adapter->service_timer, &ixgbe_service_timer,
(unsigned long) adapter);
INIT_WORK(&adapter->service_task, ixgbe_service_task);
clear_bit(__IXGBE_SERVICE_SCHED, &adapter->state);
err = ixgbe_init_interrupt_scheme(adapter);
if (err)
goto err_sw_init;
if (!(adapter->flags & IXGBE_FLAG_RSS_ENABLED))
netdev->features &= ~NETIF_F_RXHASH;
switch (pdev->device) {
case IXGBE_DEV_ID_82599_SFP:
if (pdev->subsystem_device == IXGBE_SUBDEV_ID_82599_SFP)
adapter->wol = (IXGBE_WUFC_MAG | IXGBE_WUFC_EX |
IXGBE_WUFC_MC | IXGBE_WUFC_BC);
break;
case IXGBE_DEV_ID_82599_COMBO_BACKPLANE:
if (pdev->subsystem_device != IXGBE_SUBDEV_ID_82599_KX4_KR_MEZZ)
adapter->wol = (IXGBE_WUFC_MAG | IXGBE_WUFC_EX |
IXGBE_WUFC_MC | IXGBE_WUFC_BC);
break;
case IXGBE_DEV_ID_82599_KX4:
adapter->wol = (IXGBE_WUFC_MAG | IXGBE_WUFC_EX |
IXGBE_WUFC_MC | IXGBE_WUFC_BC);
break;
default:
adapter->wol = 0;
break;
}
device_set_wakeup_enable(&adapter->pdev->dev, adapter->wol);
hw->mac.ops.get_bus_info(hw);
e_dev_info("(PCI Express:%s:%s) %pM\n",
(hw->bus.speed == ixgbe_bus_speed_5000 ? "5.0GT/s" :
hw->bus.speed == ixgbe_bus_speed_2500 ? "2.5GT/s" :
"Unknown"),
(hw->bus.width == ixgbe_bus_width_pcie_x8 ? "Width x8" :
hw->bus.width == ixgbe_bus_width_pcie_x4 ? "Width x4" :
hw->bus.width == ixgbe_bus_width_pcie_x1 ? "Width x1" :
"Unknown"),
netdev->dev_addr);
err = ixgbe_read_pba_string_generic(hw, part_str, IXGBE_PBANUM_LENGTH);
if (err)
strncpy(part_str, "Unknown", IXGBE_PBANUM_LENGTH);
if (ixgbe_is_sfp(hw) && hw->phy.sfp_type != ixgbe_sfp_type_not_present)
e_dev_info("MAC: %d, PHY: %d, SFP+: %d, PBA No: %s\n",
hw->mac.type, hw->phy.type, hw->phy.sfp_type,
part_str);
else
e_dev_info("MAC: %d, PHY: %d, PBA No: %s\n",
hw->mac.type, hw->phy.type, part_str);
if (hw->bus.width <= ixgbe_bus_width_pcie_x4) {
e_dev_warn("PCI-Express bandwidth available for this card is "
"not sufficient for optimal performance.\n");
e_dev_warn("For optimal performance a x8 PCI-Express slot "
"is required.\n");
}
hw->eeprom.ops.read(hw, 0x29, &adapter->eeprom_version);
err = hw->mac.ops.start_hw(hw);
if (err == IXGBE_ERR_EEPROM_VERSION) {
e_dev_warn("This device is a pre-production adapter/LOM. "
"Please be aware there may be issues associated "
"with your hardware. If you are experiencing "
"problems please contact your Intel or hardware "
"representative who provided you with this "
"hardware.\n");
}
strcpy(netdev->name, "eth%d");
err = register_netdev(netdev);
if (err)
goto err_register;
netif_carrier_off(netdev);
#ifdef CONFIG_IXGBE_DCA
if (dca_add_requester(&pdev->dev) == 0) {
adapter->flags |= IXGBE_FLAG_DCA_ENABLED;
ixgbe_setup_dca(adapter);
}
#endif
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) {
e_info(probe, "IOV is enabled with %d VFs\n", adapter->num_vfs);
for (i = 0; i < adapter->num_vfs; i++)
ixgbe_vf_configuration(pdev, (i | 0x10000000));
}
ixgbe_add_sanmac_netdev(netdev);
e_dev_info("Intel(R) 10 Gigabit Network Connection\n");
cards_found++;
return 0;
err_register:
ixgbe_release_hw_control(adapter);
ixgbe_clear_interrupt_scheme(adapter);
err_sw_init:
err_eeprom:
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
ixgbe_disable_sriov(adapter);
adapter->flags2 &= ~IXGBE_FLAG2_SEARCH_FOR_SFP;
iounmap(hw->hw_addr);
err_ioremap:
free_netdev(netdev);
err_alloc_etherdev:
pci_release_selected_regions(pdev,
pci_select_bars(pdev, IORESOURCE_MEM));
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static void __devexit ixgbe_remove(struct pci_dev *pdev)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
set_bit(__IXGBE_DOWN, &adapter->state);
cancel_work_sync(&adapter->service_task);
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED) {
adapter->flags &= ~IXGBE_FLAG_DCA_ENABLED;
dca_remove_requester(&pdev->dev);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL, 1);
}
#endif
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED)
ixgbe_cleanup_fcoe(adapter);
#endif
ixgbe_del_sanmac_netdev(netdev);
if (netdev->reg_state == NETREG_REGISTERED)
unregister_netdev(netdev);
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
ixgbe_disable_sriov(adapter);
ixgbe_clear_interrupt_scheme(adapter);
ixgbe_release_hw_control(adapter);
iounmap(adapter->hw.hw_addr);
pci_release_selected_regions(pdev, pci_select_bars(pdev,
IORESOURCE_MEM));
e_dev_info("complete\n");
free_netdev(netdev);
pci_disable_pcie_error_reporting(pdev);
pci_disable_device(pdev);
}
static pci_ers_result_t ixgbe_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
netif_device_detach(netdev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
if (netif_running(netdev))
ixgbe_down(adapter);
pci_disable_device(pdev);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t ixgbe_io_slot_reset(struct pci_dev *pdev)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
pci_ers_result_t result;
int err;
if (pci_enable_device_mem(pdev)) {
e_err(probe, "Cannot re-enable PCI device after reset.\n");
result = PCI_ERS_RESULT_DISCONNECT;
} else {
pci_set_master(pdev);
pci_restore_state(pdev);
pci_save_state(pdev);
pci_wake_from_d3(pdev, false);
ixgbe_reset(adapter);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_WUS, ~0);
result = PCI_ERS_RESULT_RECOVERED;
}
err = pci_cleanup_aer_uncorrect_error_status(pdev);
if (err) {
e_dev_err("pci_cleanup_aer_uncorrect_error_status "
"failed 0x%0x\n", err);
}
return result;
}
static void ixgbe_io_resume(struct pci_dev *pdev)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
if (netif_running(netdev)) {
if (ixgbe_up(adapter)) {
e_info(probe, "ixgbe_up failed after reset\n");
return;
}
}
netif_device_attach(netdev);
}
static int __init ixgbe_init_module(void)
{
int ret;
pr_info("%s - version %s\n", ixgbe_driver_string, ixgbe_driver_version);
pr_info("%s\n", ixgbe_copyright);
#ifdef CONFIG_IXGBE_DCA
dca_register_notify(&dca_notifier);
#endif
ret = pci_register_driver(&ixgbe_driver);
return ret;
}
static void __exit ixgbe_exit_module(void)
{
#ifdef CONFIG_IXGBE_DCA
dca_unregister_notify(&dca_notifier);
#endif
pci_unregister_driver(&ixgbe_driver);
rcu_barrier();
}
static int ixgbe_notify_dca(struct notifier_block *nb, unsigned long event,
void *p)
{
int ret_val;
ret_val = driver_for_each_device(&ixgbe_driver.driver, NULL, &event,
__ixgbe_notify_dca);
return ret_val ? NOTIFY_BAD : NOTIFY_DONE;
}
