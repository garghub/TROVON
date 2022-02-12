static int ixgbe_read_pci_cfg_word_parent(struct ixgbe_adapter *adapter,
u32 reg, u16 *value)
{
int pos = 0;
struct pci_dev *parent_dev;
struct pci_bus *parent_bus;
parent_bus = adapter->pdev->bus->parent;
if (!parent_bus)
return -1;
parent_dev = parent_bus->self;
if (!parent_dev)
return -1;
pos = pci_find_capability(parent_dev, PCI_CAP_ID_EXP);
if (!pos)
return -1;
pci_read_config_word(parent_dev, pos + reg, value);
return 0;
}
static s32 ixgbe_get_parent_bus_info(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u16 link_status = 0;
int err;
hw->bus.type = ixgbe_bus_type_pci_express;
err = ixgbe_read_pci_cfg_word_parent(adapter, 18, &link_status);
if (err)
return err;
hw->bus.width = ixgbe_convert_bus_width(link_status);
hw->bus.speed = ixgbe_convert_bus_speed(link_status);
return 0;
}
static inline bool ixgbe_pcie_from_parent(struct ixgbe_hw *hw)
{
switch (hw->device_id) {
case IXGBE_DEV_ID_82599_SFP_SF_QP:
case IXGBE_DEV_ID_82599_QSFP_SF_QP:
return true;
default:
return false;
}
}
static void ixgbe_check_minimum_link(struct ixgbe_adapter *adapter,
int expected_gts)
{
int max_gts = 0;
enum pci_bus_speed speed = PCI_SPEED_UNKNOWN;
enum pcie_link_width width = PCIE_LNK_WIDTH_UNKNOWN;
struct pci_dev *pdev;
if (ixgbe_pcie_from_parent(&adapter->hw))
pdev = adapter->pdev->bus->parent->self;
else
pdev = adapter->pdev;
if (pcie_get_minimum_link(pdev, &speed, &width) ||
speed == PCI_SPEED_UNKNOWN || width == PCIE_LNK_WIDTH_UNKNOWN) {
e_dev_warn("Unable to determine PCI Express bandwidth.\n");
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
e_dev_warn("Unable to determine PCI Express bandwidth.\n");
return;
}
e_dev_info("PCI Express bandwidth of %dGT/s available\n",
max_gts);
e_dev_info("(Speed:%s, Width: x%d, Encoding Loss:%s)\n",
(speed == PCIE_SPEED_8_0GT ? "8.0GT/s" :
speed == PCIE_SPEED_5_0GT ? "5.0GT/s" :
speed == PCIE_SPEED_2_5GT ? "2.5GT/s" :
"Unknown"),
width,
(speed == PCIE_SPEED_2_5GT ? "20%" :
speed == PCIE_SPEED_5_0GT ? "20%" :
speed == PCIE_SPEED_8_0GT ? "N/a" :
"Unknown"));
if (max_gts < expected_gts) {
e_dev_warn("This is not sufficient for optimal performance of this card.\n");
e_dev_warn("For optimal performance, at least %dGT/s of bandwidth is required.\n",
expected_gts);
e_dev_warn("A slot with more lanes and/or higher speed is suggested.\n");
}
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
struct ixgbe_tx_buffer *tx_buffer;
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
pr_info(" %s %s %s %s\n",
"Queue [NTU] [NTC] [bi(ntc)->dma ]",
"leng", "ntw", "timestamp");
for (n = 0; n < adapter->num_tx_queues; n++) {
tx_ring = adapter->tx_ring[n];
tx_buffer = &tx_ring->tx_buffer_info[tx_ring->next_to_clean];
pr_info(" %5d %5X %5X %016llX %08X %p %016llX\n",
n, tx_ring->next_to_use, tx_ring->next_to_clean,
(u64)dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
tx_buffer->next_to_watch,
(u64)tx_buffer->time_stamp);
}
if (!netif_msg_tx_done(adapter))
goto rx_ring_summary;
dev_info(&adapter->pdev->dev, "TX Rings Dump\n");
for (n = 0; n < adapter->num_tx_queues; n++) {
tx_ring = adapter->tx_ring[n];
pr_info("------------------------------------\n");
pr_info("TX QUEUE INDEX = %d\n", tx_ring->queue_index);
pr_info("------------------------------------\n");
pr_info("%s%s %s %s %s %s\n",
"T [desc] [address 63:0 ] ",
"[PlPOIdStDDt Ln] [bi->dma ] ",
"leng", "ntw", "timestamp", "bi->skb");
for (i = 0; tx_ring->desc && (i < tx_ring->count); i++) {
tx_desc = IXGBE_TX_DESC(tx_ring, i);
tx_buffer = &tx_ring->tx_buffer_info[i];
u0 = (struct my_u0 *)tx_desc;
if (dma_unmap_len(tx_buffer, len) > 0) {
pr_info("T [0x%03X] %016llX %016llX %016llX %08X %p %016llX %p",
i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
(u64)dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
tx_buffer->next_to_watch,
(u64)tx_buffer->time_stamp,
tx_buffer->skb);
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
tx_buffer->skb)
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS, 16, 1,
tx_buffer->skb->data,
dma_unmap_len(tx_buffer, len),
true);
}
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
pr_info("%s%s%s",
"R [desc] [ PktBuf A0] ",
"[ HeadBuf DD] [bi->dma ] [bi->skb ] ",
"<-- Adv Rx Read format\n");
pr_info("%s%s%s",
"RWB[desc] [PcsmIpSHl PtRs] ",
"[vl er S cks ln] ---------------- [bi->skb ] ",
"<-- Adv Rx Write-Back format\n");
for (i = 0; i < rx_ring->count; i++) {
rx_buffer_info = &rx_ring->rx_buffer_info[i];
rx_desc = IXGBE_RX_DESC(rx_ring, i);
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
if (netif_msg_pktdata(adapter) &&
rx_buffer_info->dma) {
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS, 16, 1,
page_address(rx_buffer_info->page) +
rx_buffer_info->page_offset,
ixgbe_rx_bufsz(rx_ring), true);
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
void ixgbe_unmap_and_free_tx_resource(struct ixgbe_ring *ring,
struct ixgbe_tx_buffer *tx_buffer)
{
if (tx_buffer->skb) {
dev_kfree_skb_any(tx_buffer->skb);
if (dma_unmap_len(tx_buffer, len))
dma_unmap_single(ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
} else if (dma_unmap_len(tx_buffer, len)) {
dma_unmap_page(ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
}
tx_buffer->next_to_watch = NULL;
tx_buffer->skb = NULL;
dma_unmap_len_set(tx_buffer, len, 0);
}
static void ixgbe_update_xoff_rx_lfc(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_hw_stats *hwstats = &adapter->stats;
int i;
u32 data;
if ((hw->fc.current_mode != ixgbe_fc_full) &&
(hw->fc.current_mode != ixgbe_fc_rx_pause))
return;
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
}
static void ixgbe_update_xoff_received(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_hw_stats *hwstats = &adapter->stats;
u32 xoff[8] = {0};
u8 tc;
int i;
bool pfc_en = adapter->dcb_cfg.pfc_mode_enable;
if (adapter->ixgbe_ieee_pfc)
pfc_en |= !!(adapter->ixgbe_ieee_pfc->pfc_en);
if (!(adapter->flags & IXGBE_FLAG_DCB_ENABLED) || !pfc_en) {
ixgbe_update_xoff_rx_lfc(adapter);
return;
}
for (i = 0; i < MAX_TX_PACKET_BUFFERS; i++) {
u32 pxoffrxc;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
pxoffrxc = IXGBE_READ_REG(hw, IXGBE_PXOFFRXC(i));
break;
default:
pxoffrxc = IXGBE_READ_REG(hw, IXGBE_PXOFFRXCNT(i));
}
hwstats->pxoffrxc[i] += pxoffrxc;
tc = netdev_get_prio_tc_map(adapter->netdev, i);
xoff[tc] += pxoffrxc;
}
for (i = 0; i < adapter->num_tx_queues; i++) {
struct ixgbe_ring *tx_ring = adapter->tx_ring[i];
tc = tx_ring->dcb_tc;
if (xoff[tc])
clear_bit(__IXGBE_HANG_CHECK_ARMED, &tx_ring->state);
}
}
static u64 ixgbe_get_tx_completed(struct ixgbe_ring *ring)
{
return ring->stats.packets;
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
e_warn(drv, "initiating reset due to tx timeout\n");
ixgbe_service_event_schedule(adapter);
}
}
static bool ixgbe_clean_tx_irq(struct ixgbe_q_vector *q_vector,
struct ixgbe_ring *tx_ring)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_tx_buffer *tx_buffer;
union ixgbe_adv_tx_desc *tx_desc;
unsigned int total_bytes = 0, total_packets = 0;
unsigned int budget = q_vector->tx.work_limit;
unsigned int i = tx_ring->next_to_clean;
if (test_bit(__IXGBE_DOWN, &adapter->state))
return true;
tx_buffer = &tx_ring->tx_buffer_info[i];
tx_desc = IXGBE_TX_DESC(tx_ring, i);
i -= tx_ring->count;
do {
union ixgbe_adv_tx_desc *eop_desc = tx_buffer->next_to_watch;
if (!eop_desc)
break;
read_barrier_depends();
if (!(eop_desc->wb.status & cpu_to_le32(IXGBE_TXD_STAT_DD)))
break;
tx_buffer->next_to_watch = NULL;
total_bytes += tx_buffer->bytecount;
total_packets += tx_buffer->gso_segs;
dev_kfree_skb_any(tx_buffer->skb);
dma_unmap_single(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
tx_buffer->skb = NULL;
dma_unmap_len_set(tx_buffer, len, 0);
while (tx_desc != eop_desc) {
tx_buffer++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buffer = tx_ring->tx_buffer_info;
tx_desc = IXGBE_TX_DESC(tx_ring, 0);
}
if (dma_unmap_len(tx_buffer, len)) {
dma_unmap_page(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
dma_unmap_len_set(tx_buffer, len, 0);
}
}
tx_buffer++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buffer = tx_ring->tx_buffer_info;
tx_desc = IXGBE_TX_DESC(tx_ring, 0);
}
prefetch(tx_desc);
budget--;
} while (likely(budget));
i += tx_ring->count;
tx_ring->next_to_clean = i;
u64_stats_update_begin(&tx_ring->syncp);
tx_ring->stats.bytes += total_bytes;
tx_ring->stats.packets += total_packets;
u64_stats_update_end(&tx_ring->syncp);
q_vector->tx.total_bytes += total_bytes;
q_vector->tx.total_packets += total_packets;
if (check_for_tx_hang(tx_ring) && ixgbe_check_tx_hang(tx_ring)) {
struct ixgbe_hw *hw = &adapter->hw;
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
tx_ring->next_to_use, i,
tx_ring->tx_buffer_info[i].time_stamp, jiffies);
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
e_info(probe,
"tx hang %d detected on queue %d, resetting adapter\n",
adapter->tx_timeout_count + 1, tx_ring->queue_index);
ixgbe_tx_timeout_reset(adapter);
return true;
}
netdev_tx_completed_queue(txring_txq(tx_ring),
total_packets, total_bytes);
#define TX_WAKE_THRESHOLD (DESC_NEEDED * 2)
if (unlikely(total_packets && netif_carrier_ok(tx_ring->netdev) &&
(ixgbe_desc_unused(tx_ring) >= TX_WAKE_THRESHOLD))) {
smp_mb();
if (__netif_subqueue_stopped(tx_ring->netdev,
tx_ring->queue_index)
&& !test_bit(__IXGBE_DOWN, &adapter->state)) {
netif_wake_subqueue(tx_ring->netdev,
tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
}
}
return !!budget;
}
static void ixgbe_update_tx_dca(struct ixgbe_adapter *adapter,
struct ixgbe_ring *tx_ring,
int cpu)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 txctrl = dca3_get_tag(tx_ring->dev, cpu);
u16 reg_offset;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
reg_offset = IXGBE_DCA_TXCTRL(tx_ring->reg_idx);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
reg_offset = IXGBE_DCA_TXCTRL_82599(tx_ring->reg_idx);
txctrl <<= IXGBE_DCA_TXCTRL_CPUID_SHIFT_82599;
break;
default:
return;
}
txctrl |= IXGBE_DCA_TXCTRL_DESC_RRO_EN |
IXGBE_DCA_TXCTRL_DATA_RRO_EN |
IXGBE_DCA_TXCTRL_DESC_DCA_EN;
IXGBE_WRITE_REG(hw, reg_offset, txctrl);
}
static void ixgbe_update_rx_dca(struct ixgbe_adapter *adapter,
struct ixgbe_ring *rx_ring,
int cpu)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 rxctrl = dca3_get_tag(rx_ring->dev, cpu);
u8 reg_idx = rx_ring->reg_idx;
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
rxctrl <<= IXGBE_DCA_RXCTRL_CPUID_SHIFT_82599;
break;
default:
break;
}
rxctrl |= IXGBE_DCA_RXCTRL_DESC_RRO_EN |
IXGBE_DCA_RXCTRL_DESC_DCA_EN;
IXGBE_WRITE_REG(hw, IXGBE_DCA_RXCTRL(reg_idx), rxctrl);
}
static void ixgbe_update_dca(struct ixgbe_q_vector *q_vector)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *ring;
int cpu = get_cpu();
if (q_vector->cpu == cpu)
goto out_no_update;
ixgbe_for_each_ring(ring, q_vector->tx)
ixgbe_update_tx_dca(adapter, ring, cpu);
ixgbe_for_each_ring(ring, q_vector->rx)
ixgbe_update_rx_dca(adapter, ring, cpu);
q_vector->cpu = cpu;
out_no_update:
put_cpu();
}
static void ixgbe_setup_dca(struct ixgbe_adapter *adapter)
{
int i;
if (!(adapter->flags & IXGBE_FLAG_DCA_ENABLED))
return;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL, 2);
for (i = 0; i < adapter->num_q_vectors; i++) {
adapter->q_vector[i]->cpu = -1;
ixgbe_update_dca(adapter->q_vector[i]);
}
}
static int __ixgbe_notify_dca(struct device *dev, void *data)
{
struct ixgbe_adapter *adapter = dev_get_drvdata(dev);
unsigned long event = *(unsigned long *)data;
if (!(adapter->flags & IXGBE_FLAG_DCA_CAPABLE))
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
static inline void ixgbe_rx_hash(struct ixgbe_ring *ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
if (ring->netdev->features & NETIF_F_RXHASH)
skb->rxhash = le32_to_cpu(rx_desc->wb.lower.hi_dword.rss);
}
static inline bool ixgbe_rx_is_fcoe(struct ixgbe_ring *ring,
union ixgbe_adv_rx_desc *rx_desc)
{
__le16 pkt_info = rx_desc->wb.lower.lo_dword.hs_rss.pkt_info;
return test_bit(__IXGBE_RX_FCOE, &ring->state) &&
((pkt_info & cpu_to_le16(IXGBE_RXDADV_PKTTYPE_ETQF_MASK)) ==
(cpu_to_le16(IXGBE_ETQF_FILTER_FCOE <<
IXGBE_RXDADV_PKTTYPE_ETQF_SHIFT)));
}
static inline void ixgbe_rx_checksum(struct ixgbe_ring *ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
skb_checksum_none_assert(skb);
if (!(ring->netdev->features & NETIF_F_RXCSUM))
return;
if (ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_IPCS) &&
ixgbe_test_staterr(rx_desc, IXGBE_RXDADV_ERR_IPE)) {
ring->rx_stats.csum_err++;
return;
}
if (!ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_L4CS))
return;
if (ixgbe_test_staterr(rx_desc, IXGBE_RXDADV_ERR_TCPE)) {
__le16 pkt_info = rx_desc->wb.lower.lo_dword.hs_rss.pkt_info;
if ((pkt_info & cpu_to_le16(IXGBE_RXDADV_PKTTYPE_UDP)) &&
test_bit(__IXGBE_RX_CSUM_UDP_ZERO_ERR, &ring->state))
return;
ring->rx_stats.csum_err++;
return;
}
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
static inline void ixgbe_release_rx_desc(struct ixgbe_ring *rx_ring, u32 val)
{
rx_ring->next_to_use = val;
rx_ring->next_to_alloc = val;
wmb();
writel(val, rx_ring->tail);
}
static bool ixgbe_alloc_mapped_page(struct ixgbe_ring *rx_ring,
struct ixgbe_rx_buffer *bi)
{
struct page *page = bi->page;
dma_addr_t dma = bi->dma;
if (likely(dma))
return true;
if (likely(!page)) {
page = __skb_alloc_pages(GFP_ATOMIC | __GFP_COLD | __GFP_COMP,
bi->skb, ixgbe_rx_pg_order(rx_ring));
if (unlikely(!page)) {
rx_ring->rx_stats.alloc_rx_page_failed++;
return false;
}
bi->page = page;
}
dma = dma_map_page(rx_ring->dev, page, 0,
ixgbe_rx_pg_size(rx_ring), DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev, dma)) {
__free_pages(page, ixgbe_rx_pg_order(rx_ring));
bi->page = NULL;
rx_ring->rx_stats.alloc_rx_page_failed++;
return false;
}
bi->dma = dma;
bi->page_offset = 0;
return true;
}
void ixgbe_alloc_rx_buffers(struct ixgbe_ring *rx_ring, u16 cleaned_count)
{
union ixgbe_adv_rx_desc *rx_desc;
struct ixgbe_rx_buffer *bi;
u16 i = rx_ring->next_to_use;
if (!cleaned_count)
return;
rx_desc = IXGBE_RX_DESC(rx_ring, i);
bi = &rx_ring->rx_buffer_info[i];
i -= rx_ring->count;
do {
if (!ixgbe_alloc_mapped_page(rx_ring, bi))
break;
rx_desc->read.pkt_addr = cpu_to_le64(bi->dma + bi->page_offset);
rx_desc++;
bi++;
i++;
if (unlikely(!i)) {
rx_desc = IXGBE_RX_DESC(rx_ring, 0);
bi = rx_ring->rx_buffer_info;
i -= rx_ring->count;
}
rx_desc->read.hdr_addr = 0;
cleaned_count--;
} while (cleaned_count);
i += rx_ring->count;
if (rx_ring->next_to_use != i)
ixgbe_release_rx_desc(rx_ring, i);
}
static unsigned int ixgbe_get_headlen(unsigned char *data,
unsigned int max_len)
{
union {
unsigned char *network;
struct ethhdr *eth;
struct vlan_hdr *vlan;
struct iphdr *ipv4;
struct ipv6hdr *ipv6;
} hdr;
__be16 protocol;
u8 nexthdr = 0;
u8 hlen;
if (max_len < ETH_HLEN)
return max_len;
hdr.network = data;
protocol = hdr.eth->h_proto;
hdr.network += ETH_HLEN;
if (protocol == __constant_htons(ETH_P_8021Q)) {
if ((hdr.network - data) > (max_len - VLAN_HLEN))
return max_len;
protocol = hdr.vlan->h_vlan_encapsulated_proto;
hdr.network += VLAN_HLEN;
}
if (protocol == __constant_htons(ETH_P_IP)) {
if ((hdr.network - data) > (max_len - sizeof(struct iphdr)))
return max_len;
hlen = (hdr.network[0] & 0x0F) << 2;
if (hlen < sizeof(struct iphdr))
return hdr.network - data;
if (!(hdr.ipv4->frag_off & htons(IP_OFFSET)))
nexthdr = hdr.ipv4->protocol;
} else if (protocol == __constant_htons(ETH_P_IPV6)) {
if ((hdr.network - data) > (max_len - sizeof(struct ipv6hdr)))
return max_len;
nexthdr = hdr.ipv6->nexthdr;
hlen = sizeof(struct ipv6hdr);
#ifdef IXGBE_FCOE
} else if (protocol == __constant_htons(ETH_P_FCOE)) {
if ((hdr.network - data) > (max_len - FCOE_HEADER_LEN))
return max_len;
hlen = FCOE_HEADER_LEN;
#endif
} else {
return hdr.network - data;
}
hdr.network += hlen;
if (nexthdr == IPPROTO_TCP) {
if ((hdr.network - data) > (max_len - sizeof(struct tcphdr)))
return max_len;
hlen = (hdr.network[12] & 0xF0) >> 2;
if (hlen < sizeof(struct tcphdr))
return hdr.network - data;
hdr.network += hlen;
} else if (nexthdr == IPPROTO_UDP) {
if ((hdr.network - data) > (max_len - sizeof(struct udphdr)))
return max_len;
hdr.network += sizeof(struct udphdr);
}
if ((hdr.network - data) < max_len)
return hdr.network - data;
else
return max_len;
}
static void ixgbe_set_rsc_gso_size(struct ixgbe_ring *ring,
struct sk_buff *skb)
{
u16 hdr_len = skb_headlen(skb);
skb_shinfo(skb)->gso_size = DIV_ROUND_UP((skb->len - hdr_len),
IXGBE_CB(skb)->append_cnt);
skb_shinfo(skb)->gso_type = SKB_GSO_TCPV4;
}
static void ixgbe_update_rsc_stats(struct ixgbe_ring *rx_ring,
struct sk_buff *skb)
{
if (!IXGBE_CB(skb)->append_cnt)
return;
rx_ring->rx_stats.rsc_count += IXGBE_CB(skb)->append_cnt;
rx_ring->rx_stats.rsc_flush++;
ixgbe_set_rsc_gso_size(rx_ring, skb);
IXGBE_CB(skb)->append_cnt = 0;
}
static void ixgbe_process_skb_fields(struct ixgbe_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct net_device *dev = rx_ring->netdev;
ixgbe_update_rsc_stats(rx_ring, skb);
ixgbe_rx_hash(rx_ring, rx_desc, skb);
ixgbe_rx_checksum(rx_ring, rx_desc, skb);
ixgbe_ptp_rx_hwtstamp(rx_ring, rx_desc, skb);
if ((dev->features & NETIF_F_HW_VLAN_CTAG_RX) &&
ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_VP)) {
u16 vid = le16_to_cpu(rx_desc->wb.upper.vlan);
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vid);
}
skb_record_rx_queue(skb, rx_ring->queue_index);
skb->protocol = eth_type_trans(skb, dev);
}
static void ixgbe_rx_skb(struct ixgbe_q_vector *q_vector,
struct sk_buff *skb)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
if (ixgbe_qv_ll_polling(q_vector))
netif_receive_skb(skb);
else if (!(adapter->flags & IXGBE_FLAG_IN_NETPOLL))
napi_gro_receive(&q_vector->napi, skb);
else
netif_rx(skb);
}
static bool ixgbe_is_non_eop(struct ixgbe_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
u32 ntc = rx_ring->next_to_clean + 1;
ntc = (ntc < rx_ring->count) ? ntc : 0;
rx_ring->next_to_clean = ntc;
prefetch(IXGBE_RX_DESC(rx_ring, ntc));
if (ring_is_rsc_enabled(rx_ring)) {
__le32 rsc_enabled = rx_desc->wb.lower.lo_dword.data &
cpu_to_le32(IXGBE_RXDADV_RSCCNT_MASK);
if (unlikely(rsc_enabled)) {
u32 rsc_cnt = le32_to_cpu(rsc_enabled);
rsc_cnt >>= IXGBE_RXDADV_RSCCNT_SHIFT;
IXGBE_CB(skb)->append_cnt += rsc_cnt - 1;
ntc = le32_to_cpu(rx_desc->wb.upper.status_error);
ntc &= IXGBE_RXDADV_NEXTP_MASK;
ntc >>= IXGBE_RXDADV_NEXTP_SHIFT;
}
}
if (likely(ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_EOP)))
return false;
rx_ring->rx_buffer_info[ntc].skb = skb;
rx_ring->rx_stats.non_eop_descs++;
return true;
}
static void ixgbe_pull_tail(struct ixgbe_ring *rx_ring,
struct sk_buff *skb)
{
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[0];
unsigned char *va;
unsigned int pull_len;
va = skb_frag_address(frag);
pull_len = ixgbe_get_headlen(va, IXGBE_RX_HDR_SIZE);
skb_copy_to_linear_data(skb, va, ALIGN(pull_len, sizeof(long)));
skb_frag_size_sub(frag, pull_len);
frag->page_offset += pull_len;
skb->data_len -= pull_len;
skb->tail += pull_len;
}
static void ixgbe_dma_sync_frag(struct ixgbe_ring *rx_ring,
struct sk_buff *skb)
{
if (unlikely(IXGBE_CB(skb)->page_released)) {
dma_unmap_page(rx_ring->dev, IXGBE_CB(skb)->dma,
ixgbe_rx_pg_size(rx_ring), DMA_FROM_DEVICE);
IXGBE_CB(skb)->page_released = false;
} else {
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[0];
dma_sync_single_range_for_cpu(rx_ring->dev,
IXGBE_CB(skb)->dma,
frag->page_offset,
ixgbe_rx_bufsz(rx_ring),
DMA_FROM_DEVICE);
}
IXGBE_CB(skb)->dma = 0;
}
static bool ixgbe_cleanup_headers(struct ixgbe_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct net_device *netdev = rx_ring->netdev;
if (unlikely(ixgbe_test_staterr(rx_desc,
IXGBE_RXDADV_ERR_FRAME_ERR_MASK) &&
!(netdev->features & NETIF_F_RXALL))) {
dev_kfree_skb_any(skb);
return true;
}
if (skb_is_nonlinear(skb))
ixgbe_pull_tail(rx_ring, skb);
#ifdef IXGBE_FCOE
if (ixgbe_rx_is_fcoe(rx_ring, rx_desc))
return false;
#endif
if (unlikely(skb->len < 60)) {
int pad_len = 60 - skb->len;
if (skb_pad(skb, pad_len))
return true;
__skb_put(skb, pad_len);
}
return false;
}
static void ixgbe_reuse_rx_page(struct ixgbe_ring *rx_ring,
struct ixgbe_rx_buffer *old_buff)
{
struct ixgbe_rx_buffer *new_buff;
u16 nta = rx_ring->next_to_alloc;
new_buff = &rx_ring->rx_buffer_info[nta];
nta++;
rx_ring->next_to_alloc = (nta < rx_ring->count) ? nta : 0;
new_buff->page = old_buff->page;
new_buff->dma = old_buff->dma;
new_buff->page_offset = old_buff->page_offset;
dma_sync_single_range_for_device(rx_ring->dev, new_buff->dma,
new_buff->page_offset,
ixgbe_rx_bufsz(rx_ring),
DMA_FROM_DEVICE);
}
static bool ixgbe_add_rx_frag(struct ixgbe_ring *rx_ring,
struct ixgbe_rx_buffer *rx_buffer,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct page *page = rx_buffer->page;
unsigned int size = le16_to_cpu(rx_desc->wb.upper.length);
#if (PAGE_SIZE < 8192)
unsigned int truesize = ixgbe_rx_bufsz(rx_ring);
#else
unsigned int truesize = ALIGN(size, L1_CACHE_BYTES);
unsigned int last_offset = ixgbe_rx_pg_size(rx_ring) -
ixgbe_rx_bufsz(rx_ring);
#endif
if ((size <= IXGBE_RX_HDR_SIZE) && !skb_is_nonlinear(skb)) {
unsigned char *va = page_address(page) + rx_buffer->page_offset;
memcpy(__skb_put(skb, size), va, ALIGN(size, sizeof(long)));
if (likely(page_to_nid(page) == numa_node_id()))
return true;
put_page(page);
return false;
}
skb_add_rx_frag(skb, skb_shinfo(skb)->nr_frags, page,
rx_buffer->page_offset, size, truesize);
if (unlikely(page_to_nid(page) != numa_node_id()))
return false;
#if (PAGE_SIZE < 8192)
if (unlikely(page_count(page) != 1))
return false;
rx_buffer->page_offset ^= truesize;
atomic_set(&page->_count, 2);
#else
rx_buffer->page_offset += truesize;
if (rx_buffer->page_offset > last_offset)
return false;
get_page(page);
#endif
return true;
}
static struct sk_buff *ixgbe_fetch_rx_buffer(struct ixgbe_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc)
{
struct ixgbe_rx_buffer *rx_buffer;
struct sk_buff *skb;
struct page *page;
rx_buffer = &rx_ring->rx_buffer_info[rx_ring->next_to_clean];
page = rx_buffer->page;
prefetchw(page);
skb = rx_buffer->skb;
if (likely(!skb)) {
void *page_addr = page_address(page) +
rx_buffer->page_offset;
prefetch(page_addr);
#if L1_CACHE_BYTES < 128
prefetch(page_addr + L1_CACHE_BYTES);
#endif
skb = netdev_alloc_skb_ip_align(rx_ring->netdev,
IXGBE_RX_HDR_SIZE);
if (unlikely(!skb)) {
rx_ring->rx_stats.alloc_rx_buff_failed++;
return NULL;
}
prefetchw(skb->data);
if (likely(ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_EOP)))
goto dma_sync;
IXGBE_CB(skb)->dma = rx_buffer->dma;
} else {
if (ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_EOP))
ixgbe_dma_sync_frag(rx_ring, skb);
dma_sync:
dma_sync_single_range_for_cpu(rx_ring->dev,
rx_buffer->dma,
rx_buffer->page_offset,
ixgbe_rx_bufsz(rx_ring),
DMA_FROM_DEVICE);
}
if (ixgbe_add_rx_frag(rx_ring, rx_buffer, rx_desc, skb)) {
ixgbe_reuse_rx_page(rx_ring, rx_buffer);
} else if (IXGBE_CB(skb)->dma == rx_buffer->dma) {
IXGBE_CB(skb)->page_released = true;
} else {
dma_unmap_page(rx_ring->dev, rx_buffer->dma,
ixgbe_rx_pg_size(rx_ring),
DMA_FROM_DEVICE);
}
rx_buffer->skb = NULL;
rx_buffer->dma = 0;
rx_buffer->page = NULL;
return skb;
}
static int ixgbe_clean_rx_irq(struct ixgbe_q_vector *q_vector,
struct ixgbe_ring *rx_ring,
const int budget)
{
unsigned int total_rx_bytes = 0, total_rx_packets = 0;
#ifdef IXGBE_FCOE
struct ixgbe_adapter *adapter = q_vector->adapter;
int ddp_bytes;
unsigned int mss = 0;
#endif
u16 cleaned_count = ixgbe_desc_unused(rx_ring);
do {
union ixgbe_adv_rx_desc *rx_desc;
struct sk_buff *skb;
if (cleaned_count >= IXGBE_RX_BUFFER_WRITE) {
ixgbe_alloc_rx_buffers(rx_ring, cleaned_count);
cleaned_count = 0;
}
rx_desc = IXGBE_RX_DESC(rx_ring, rx_ring->next_to_clean);
if (!ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_DD))
break;
rmb();
skb = ixgbe_fetch_rx_buffer(rx_ring, rx_desc);
if (!skb)
break;
cleaned_count++;
if (ixgbe_is_non_eop(rx_ring, rx_desc, skb))
continue;
if (ixgbe_cleanup_headers(rx_ring, rx_desc, skb))
continue;
total_rx_bytes += skb->len;
ixgbe_process_skb_fields(rx_ring, rx_desc, skb);
#ifdef IXGBE_FCOE
if (ixgbe_rx_is_fcoe(rx_ring, rx_desc)) {
ddp_bytes = ixgbe_fcoe_ddp(adapter, rx_desc, skb);
if (ddp_bytes > 0) {
if (!mss) {
mss = rx_ring->netdev->mtu -
sizeof(struct fcoe_hdr) -
sizeof(struct fc_frame_header) -
sizeof(struct fcoe_crc_eof);
if (mss > 512)
mss &= ~511;
}
total_rx_bytes += ddp_bytes;
total_rx_packets += DIV_ROUND_UP(ddp_bytes,
mss);
}
if (!ddp_bytes) {
dev_kfree_skb_any(skb);
continue;
}
}
#endif
skb_mark_napi_id(skb, &q_vector->napi);
ixgbe_rx_skb(q_vector, skb);
total_rx_packets++;
} while (likely(total_rx_packets < budget));
u64_stats_update_begin(&rx_ring->syncp);
rx_ring->stats.packets += total_rx_packets;
rx_ring->stats.bytes += total_rx_bytes;
u64_stats_update_end(&rx_ring->syncp);
q_vector->rx.total_packets += total_rx_packets;
q_vector->rx.total_bytes += total_rx_bytes;
if (cleaned_count)
ixgbe_alloc_rx_buffers(rx_ring, cleaned_count);
return total_rx_packets;
}
static int ixgbe_low_latency_recv(struct napi_struct *napi)
{
struct ixgbe_q_vector *q_vector =
container_of(napi, struct ixgbe_q_vector, napi);
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *ring;
int found = 0;
if (test_bit(__IXGBE_DOWN, &adapter->state))
return LL_FLUSH_FAILED;
if (!ixgbe_qv_lock_poll(q_vector))
return LL_FLUSH_BUSY;
ixgbe_for_each_ring(ring, q_vector->rx) {
found = ixgbe_clean_rx_irq(q_vector, ring, 4);
#ifdef LL_EXTENDED_STATS
if (found)
ring->stats.cleaned += found;
else
ring->stats.misses++;
#endif
if (found)
break;
}
ixgbe_qv_unlock_poll(q_vector);
return found;
}
static void ixgbe_configure_msix(struct ixgbe_adapter *adapter)
{
struct ixgbe_q_vector *q_vector;
int v_idx;
u32 mask;
if (adapter->num_vfs > 32) {
u32 eitrsel = (1 << (adapter->num_vfs - 32)) - 1;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EITRSEL, eitrsel);
}
for (v_idx = 0; v_idx < adapter->num_q_vectors; v_idx++) {
struct ixgbe_ring *ring;
q_vector = adapter->q_vector[v_idx];
ixgbe_for_each_ring(ring, q_vector->rx)
ixgbe_set_ivar(adapter, 0, ring->reg_idx, v_idx);
ixgbe_for_each_ring(ring, q_vector->tx)
ixgbe_set_ivar(adapter, 1, ring->reg_idx, v_idx);
ixgbe_write_eitr(q_vector);
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
mask &= ~(IXGBE_EIMS_OTHER |
IXGBE_EIMS_MAILBOX |
IXGBE_EIMS_LSC);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIAC, mask);
}
static void ixgbe_update_itr(struct ixgbe_q_vector *q_vector,
struct ixgbe_ring_container *ring_container)
{
int bytes = ring_container->total_bytes;
int packets = ring_container->total_packets;
u32 timepassed_us;
u64 bytes_perint;
u8 itr_setting = ring_container->itr;
if (packets == 0)
return;
timepassed_us = q_vector->itr >> 2;
if (timepassed_us == 0)
return;
bytes_perint = bytes / timepassed_us;
switch (itr_setting) {
case lowest_latency:
if (bytes_perint > 10)
itr_setting = low_latency;
break;
case low_latency:
if (bytes_perint > 20)
itr_setting = bulk_latency;
else if (bytes_perint <= 10)
itr_setting = lowest_latency;
break;
case bulk_latency:
if (bytes_perint <= 20)
itr_setting = low_latency;
break;
}
ring_container->total_bytes = 0;
ring_container->total_packets = 0;
ring_container->itr = itr_setting;
}
void ixgbe_write_eitr(struct ixgbe_q_vector *q_vector)
{
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_hw *hw = &adapter->hw;
int v_idx = q_vector->v_idx;
u32 itr_reg = q_vector->itr & IXGBE_MAX_EITR;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82598EB:
itr_reg |= (itr_reg << 16);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
itr_reg |= IXGBE_EITR_CNT_WDIS;
break;
default:
break;
}
IXGBE_WRITE_REG(hw, IXGBE_EITR(v_idx), itr_reg);
}
static void ixgbe_set_itr(struct ixgbe_q_vector *q_vector)
{
u32 new_itr = q_vector->itr;
u8 current_itr;
ixgbe_update_itr(q_vector, &q_vector->tx);
ixgbe_update_itr(q_vector, &q_vector->rx);
current_itr = max(q_vector->rx.itr, q_vector->tx.itr);
switch (current_itr) {
case lowest_latency:
new_itr = IXGBE_100K_ITR;
break;
case low_latency:
new_itr = IXGBE_20K_ITR;
break;
case bulk_latency:
new_itr = IXGBE_8K_ITR;
break;
default:
break;
}
if (new_itr != q_vector->itr) {
new_itr = (10 * new_itr * q_vector->itr) /
((9 * new_itr) + q_vector->itr);
q_vector->itr = new_itr;
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
u32 speed;
bool link_up = false;
hw->mac.ops.check_link(hw, &speed, &link_up, false);
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
static void ixgbe_check_overtemp_event(struct ixgbe_adapter *adapter, u32 eicr)
{
if (!(adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE))
return;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
if (((eicr & IXGBE_EICR_GPI_SDP0) || (eicr & IXGBE_EICR_LSC)) &&
(!test_bit(__IXGBE_DOWN, &adapter->state))) {
adapter->interrupt_event = eicr;
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_EVENT;
ixgbe_service_event_schedule(adapter);
return;
}
return;
case ixgbe_mac_X540:
if (!(eicr & IXGBE_EICR_TS))
return;
break;
default:
return;
}
e_crit(drv,
"Network adapter has been stopped because it has over heated. "
"Restart the computer. If the problem persists, "
"power off the system and replace the adapter\n");
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
static inline void ixgbe_irq_enable(struct ixgbe_adapter *adapter, bool queues,
bool flush)
{
u32 mask = (IXGBE_EIMS_ENABLE_MASK & ~IXGBE_EIMS_RTX_QUEUE);
if (adapter->flags & IXGBE_FLAG_NEED_LINK_UPDATE)
mask &= ~IXGBE_EIMS_LSC;
if (adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE)
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
mask |= IXGBE_EIMS_GPI_SDP0;
break;
case ixgbe_mac_X540:
mask |= IXGBE_EIMS_TS;
break;
default:
break;
}
if (adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE)
mask |= IXGBE_EIMS_GPI_SDP1;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
mask |= IXGBE_EIMS_GPI_SDP1;
mask |= IXGBE_EIMS_GPI_SDP2;
case ixgbe_mac_X540:
mask |= IXGBE_EIMS_ECC;
mask |= IXGBE_EIMS_MAILBOX;
break;
default:
break;
}
if (adapter->hw.mac.type == ixgbe_mac_X540)
mask |= IXGBE_EIMS_TIMESYNC;
if ((adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) &&
!(adapter->flags2 & IXGBE_FLAG2_FDIR_REQUIRES_REINIT))
mask |= IXGBE_EIMS_FLOW_DIR;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMS, mask);
if (queues)
ixgbe_irq_enable_queues(adapter, ~0);
if (flush)
IXGBE_WRITE_FLUSH(&adapter->hw);
}
static irqreturn_t ixgbe_msix_other(int irq, void *data)
{
struct ixgbe_adapter *adapter = data;
struct ixgbe_hw *hw = &adapter->hw;
u32 eicr;
eicr = IXGBE_READ_REG(hw, IXGBE_EICS);
eicr &= 0xFFFF0000;
IXGBE_WRITE_REG(hw, IXGBE_EICR, eicr);
if (eicr & IXGBE_EICR_LSC)
ixgbe_check_lsc(adapter);
if (eicr & IXGBE_EICR_MAILBOX)
ixgbe_msg_task(adapter);
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
if (eicr & IXGBE_EICR_ECC)
e_info(link, "Received unrecoverable ECC Err, please "
"reboot\n");
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
adapter->flags2 |= IXGBE_FLAG2_FDIR_REQUIRES_REINIT;
ixgbe_service_event_schedule(adapter);
}
}
ixgbe_check_sfp_event(adapter, eicr);
ixgbe_check_overtemp_event(adapter, eicr);
break;
default:
break;
}
ixgbe_check_fan_failure(adapter, eicr);
if (unlikely(eicr & IXGBE_EICR_TIMESYNC))
ixgbe_ptp_check_pps_event(adapter, eicr);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable(adapter, false, false);
return IRQ_HANDLED;
}
static irqreturn_t ixgbe_msix_clean_rings(int irq, void *data)
{
struct ixgbe_q_vector *q_vector = data;
if (q_vector->rx.ring || q_vector->tx.ring)
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
int ixgbe_poll(struct napi_struct *napi, int budget)
{
struct ixgbe_q_vector *q_vector =
container_of(napi, struct ixgbe_q_vector, napi);
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *ring;
int per_ring_budget;
bool clean_complete = true;
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
ixgbe_update_dca(q_vector);
#endif
ixgbe_for_each_ring(ring, q_vector->tx)
clean_complete &= !!ixgbe_clean_tx_irq(q_vector, ring);
if (!ixgbe_qv_lock_napi(q_vector))
return budget;
if (q_vector->rx.count > 1)
per_ring_budget = max(budget/q_vector->rx.count, 1);
else
per_ring_budget = budget;
ixgbe_for_each_ring(ring, q_vector->rx)
clean_complete &= (ixgbe_clean_rx_irq(q_vector, ring,
per_ring_budget) < per_ring_budget);
ixgbe_qv_unlock_napi(q_vector);
if (!clean_complete)
return budget;
napi_complete(napi);
if (adapter->rx_itr_setting & 1)
ixgbe_set_itr(q_vector);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable_queues(adapter, ((u64)1 << q_vector->v_idx));
return 0;
}
static int ixgbe_request_msix_irqs(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int vector, err;
int ri = 0, ti = 0;
for (vector = 0; vector < adapter->num_q_vectors; vector++) {
struct ixgbe_q_vector *q_vector = adapter->q_vector[vector];
struct msix_entry *entry = &adapter->msix_entries[vector];
if (q_vector->tx.ring && q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "TxRx", ri++);
ti++;
} else if (q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "rx", ri++);
} else if (q_vector->tx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"%s-%s-%d", netdev->name, "tx", ti++);
} else {
continue;
}
err = request_irq(entry->vector, &ixgbe_msix_clean_rings, 0,
q_vector->name, q_vector);
if (err) {
e_err(probe, "request_irq failed for MSIX interrupt "
"Error: %d\n", err);
goto free_queue_irqs;
}
if (adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) {
irq_set_affinity_hint(entry->vector,
&q_vector->affinity_mask);
}
}
err = request_irq(adapter->msix_entries[vector].vector,
ixgbe_msix_other, 0, netdev->name, adapter);
if (err) {
e_err(probe, "request_irq for msix_other failed: %d\n", err);
goto free_queue_irqs;
}
return 0;
free_queue_irqs:
while (vector) {
vector--;
irq_set_affinity_hint(adapter->msix_entries[vector].vector,
NULL);
free_irq(adapter->msix_entries[vector].vector,
adapter->q_vector[vector]);
}
adapter->flags &= ~IXGBE_FLAG_MSIX_ENABLED;
pci_disable_msix(adapter->pdev);
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
return err;
}
static irqreturn_t ixgbe_intr(int irq, void *data)
{
struct ixgbe_adapter *adapter = data;
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
case ixgbe_mac_X540:
if (eicr & IXGBE_EICR_ECC)
e_info(link, "Received unrecoverable ECC err, please "
"reboot\n");
ixgbe_check_overtemp_event(adapter, eicr);
break;
default:
break;
}
ixgbe_check_fan_failure(adapter, eicr);
if (unlikely(eicr & IXGBE_EICR_TIMESYNC))
ixgbe_ptp_check_pps_event(adapter, eicr);
napi_schedule(&q_vector->napi);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable(adapter, false, false);
return IRQ_HANDLED;
}
static int ixgbe_request_irq(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int err;
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED)
err = ixgbe_request_msix_irqs(adapter);
else if (adapter->flags & IXGBE_FLAG_MSI_ENABLED)
err = request_irq(adapter->pdev->irq, ixgbe_intr, 0,
netdev->name, adapter);
else
err = request_irq(adapter->pdev->irq, ixgbe_intr, IRQF_SHARED,
netdev->name, adapter);
if (err)
e_err(probe, "request_irq failed, Error %d\n", err);
return err;
}
static void ixgbe_free_irq(struct ixgbe_adapter *adapter)
{
int vector;
if (!(adapter->flags & IXGBE_FLAG_MSIX_ENABLED)) {
free_irq(adapter->pdev->irq, adapter);
return;
}
for (vector = 0; vector < adapter->num_q_vectors; vector++) {
struct ixgbe_q_vector *q_vector = adapter->q_vector[vector];
struct msix_entry *entry = &adapter->msix_entries[vector];
if (!q_vector->rx.ring && !q_vector->tx.ring)
continue;
irq_set_affinity_hint(entry->vector, NULL);
free_irq(entry->vector, q_vector);
}
free_irq(adapter->msix_entries[vector++].vector, adapter);
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
break;
default:
break;
}
IXGBE_WRITE_FLUSH(&adapter->hw);
if (adapter->flags & IXGBE_FLAG_MSIX_ENABLED) {
int vector;
for (vector = 0; vector < adapter->num_q_vectors; vector++)
synchronize_irq(adapter->msix_entries[vector].vector);
synchronize_irq(adapter->msix_entries[vector++].vector);
} else {
synchronize_irq(adapter->pdev->irq);
}
}
static void ixgbe_configure_msi_and_legacy(struct ixgbe_adapter *adapter)
{
struct ixgbe_q_vector *q_vector = adapter->q_vector[0];
ixgbe_write_eitr(q_vector);
ixgbe_set_ivar(adapter, 0, 0, 0);
ixgbe_set_ivar(adapter, 1, 0, 0);
e_info(hw, "Legacy interrupt IVAR setup done\n");
}
void ixgbe_configure_tx_ring(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u64 tdba = ring->dma;
int wait_loop = 10;
u32 txdctl = IXGBE_TXDCTL_ENABLE;
u8 reg_idx = ring->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_TXDCTL(reg_idx), 0);
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_TDBAL(reg_idx),
(tdba & DMA_BIT_MASK(32)));
IXGBE_WRITE_REG(hw, IXGBE_TDBAH(reg_idx), (tdba >> 32));
IXGBE_WRITE_REG(hw, IXGBE_TDLEN(reg_idx),
ring->count * sizeof(union ixgbe_adv_tx_desc));
IXGBE_WRITE_REG(hw, IXGBE_TDH(reg_idx), 0);
IXGBE_WRITE_REG(hw, IXGBE_TDT(reg_idx), 0);
ring->tail = hw->hw_addr + IXGBE_TDT(reg_idx);
#if IS_ENABLED(CONFIG_BQL)
if (!ring->q_vector || (ring->q_vector->itr < IXGBE_100K_ITR))
#else
if (!ring->q_vector || (ring->q_vector->itr < 8))
#endif
txdctl |= (1 << 16);
else
txdctl |= (8 << 16);
txdctl |= (1 << 8) |
32;
if (adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) {
ring->atr_sample_rate = adapter->atr_sample_rate;
ring->atr_count = 0;
set_bit(__IXGBE_TX_FDIR_INIT_DONE, &ring->state);
} else {
ring->atr_sample_rate = 0;
}
if (!test_and_set_bit(__IXGBE_TX_XPS_INIT_DONE, &ring->state)) {
struct ixgbe_q_vector *q_vector = ring->q_vector;
if (q_vector)
netif_set_xps_queue(adapter->netdev,
&q_vector->affinity_mask,
ring->queue_index);
}
clear_bit(__IXGBE_HANG_CHECK_ARMED, &ring->state);
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
u32 rttdcs, mtqc;
u8 tcs = netdev_get_num_tc(adapter->netdev);
if (hw->mac.type == ixgbe_mac_82598EB)
return;
rttdcs = IXGBE_READ_REG(hw, IXGBE_RTTDCS);
rttdcs |= IXGBE_RTTDCS_ARBDIS;
IXGBE_WRITE_REG(hw, IXGBE_RTTDCS, rttdcs);
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) {
mtqc = IXGBE_MTQC_VT_ENA;
if (tcs > 4)
mtqc |= IXGBE_MTQC_RT_ENA | IXGBE_MTQC_8TC_8TQ;
else if (tcs > 1)
mtqc |= IXGBE_MTQC_RT_ENA | IXGBE_MTQC_4TC_4TQ;
else if (adapter->ring_feature[RING_F_RSS].indices == 4)
mtqc |= IXGBE_MTQC_32VF;
else
mtqc |= IXGBE_MTQC_64VF;
} else {
if (tcs > 4)
mtqc = IXGBE_MTQC_RT_ENA | IXGBE_MTQC_8TC_8TQ;
else if (tcs > 1)
mtqc = IXGBE_MTQC_RT_ENA | IXGBE_MTQC_4TC_4TQ;
else
mtqc = IXGBE_MTQC_64Q_1PB;
}
IXGBE_WRITE_REG(hw, IXGBE_MTQC, mtqc);
if (tcs) {
u32 sectx = IXGBE_READ_REG(hw, IXGBE_SECTXMINIFG);
sectx |= IXGBE_SECTX_DCB;
IXGBE_WRITE_REG(hw, IXGBE_SECTXMINIFG, sectx);
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
static void ixgbe_enable_rx_drop(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u8 reg_idx = ring->reg_idx;
u32 srrctl = IXGBE_READ_REG(hw, IXGBE_SRRCTL(reg_idx));
srrctl |= IXGBE_SRRCTL_DROP_EN;
IXGBE_WRITE_REG(hw, IXGBE_SRRCTL(reg_idx), srrctl);
}
static void ixgbe_disable_rx_drop(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u8 reg_idx = ring->reg_idx;
u32 srrctl = IXGBE_READ_REG(hw, IXGBE_SRRCTL(reg_idx));
srrctl &= ~IXGBE_SRRCTL_DROP_EN;
IXGBE_WRITE_REG(hw, IXGBE_SRRCTL(reg_idx), srrctl);
}
static void ixgbe_configure_srrctl(struct ixgbe_adapter *adapter,
struct ixgbe_ring *rx_ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 srrctl;
u8 reg_idx = rx_ring->reg_idx;
if (hw->mac.type == ixgbe_mac_82598EB) {
u16 mask = adapter->ring_feature[RING_F_RSS].mask;
reg_idx &= mask;
}
srrctl = IXGBE_RX_HDR_SIZE << IXGBE_SRRCTL_BSIZEHDRSIZE_SHIFT;
srrctl |= ixgbe_rx_bufsz(rx_ring) >> IXGBE_SRRCTL_BSIZEPKT_SHIFT;
srrctl |= IXGBE_SRRCTL_DESCTYPE_ADV_ONEBUF;
IXGBE_WRITE_REG(hw, IXGBE_SRRCTL(reg_idx), srrctl);
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
u16 rss_i = adapter->ring_feature[RING_F_RSS].indices;
if ((adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) && (rss_i < 2))
rss_i = 2;
for (i = 0; i < 10; i++)
IXGBE_WRITE_REG(hw, IXGBE_RSSRK(i), seed[i]);
for (i = 0, j = 0; i < 128; i++, j++) {
if (j == rss_i)
j = 0;
reta = (reta << 8) | (j * 0x11);
if ((i & 3) == 3)
IXGBE_WRITE_REG(hw, IXGBE_RETA(i >> 2), reta);
}
rxcsum = IXGBE_READ_REG(hw, IXGBE_RXCSUM);
rxcsum |= IXGBE_RXCSUM_PCSD;
IXGBE_WRITE_REG(hw, IXGBE_RXCSUM, rxcsum);
if (adapter->hw.mac.type == ixgbe_mac_82598EB) {
if (adapter->ring_feature[RING_F_RSS].mask)
mrqc = IXGBE_MRQC_RSSEN;
} else {
u8 tcs = netdev_get_num_tc(adapter->netdev);
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) {
if (tcs > 4)
mrqc = IXGBE_MRQC_VMDQRT8TCEN;
else if (tcs > 1)
mrqc = IXGBE_MRQC_VMDQRT4TCEN;
else if (adapter->ring_feature[RING_F_RSS].indices == 4)
mrqc = IXGBE_MRQC_VMDQRSS32EN;
else
mrqc = IXGBE_MRQC_VMDQRSS64EN;
} else {
if (tcs > 4)
mrqc = IXGBE_MRQC_RTRSS8TCEN;
else if (tcs > 1)
mrqc = IXGBE_MRQC_RTRSS4TCEN;
else
mrqc = IXGBE_MRQC_RSSEN;
}
}
mrqc |= IXGBE_MRQC_RSS_FIELD_IPV4 |
IXGBE_MRQC_RSS_FIELD_IPV4_TCP |
IXGBE_MRQC_RSS_FIELD_IPV6 |
IXGBE_MRQC_RSS_FIELD_IPV6_TCP;
if (adapter->flags2 & IXGBE_FLAG2_RSS_FIELD_IPV4_UDP)
mrqc |= IXGBE_MRQC_RSS_FIELD_IPV4_UDP;
if (adapter->flags2 & IXGBE_FLAG2_RSS_FIELD_IPV6_UDP)
mrqc |= IXGBE_MRQC_RSS_FIELD_IPV6_UDP;
IXGBE_WRITE_REG(hw, IXGBE_MRQC, mrqc);
}
static void ixgbe_configure_rscctl(struct ixgbe_adapter *adapter,
struct ixgbe_ring *ring)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 rscctrl;
u8 reg_idx = ring->reg_idx;
if (!ring_is_rsc_enabled(ring))
return;
rscctrl = IXGBE_READ_REG(hw, IXGBE_RSCCTL(reg_idx));
rscctrl |= IXGBE_RSCCTL_RSCEN;
rscctrl |= IXGBE_RSCCTL_MAXDESC_16;
IXGBE_WRITE_REG(hw, IXGBE_RSCCTL(reg_idx), rscctrl);
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
if (hw->mac.type == ixgbe_mac_82598EB) {
rxdctl &= ~0x3FFFFF;
rxdctl |= 0x080420;
}
rxdctl |= IXGBE_RXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_RXDCTL(reg_idx), rxdctl);
ixgbe_rx_desc_queue_enable(adapter, ring);
ixgbe_alloc_rx_buffers(ring, ixgbe_desc_unused(ring));
}
static void ixgbe_setup_psrtype(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int rss_i = adapter->ring_feature[RING_F_RSS].indices;
int p;
u32 psrtype = IXGBE_PSRTYPE_TCPHDR |
IXGBE_PSRTYPE_UDPHDR |
IXGBE_PSRTYPE_IPV4HDR |
IXGBE_PSRTYPE_L2HDR |
IXGBE_PSRTYPE_IPV6HDR;
if (hw->mac.type == ixgbe_mac_82598EB)
return;
if (rss_i > 3)
psrtype |= 2 << 29;
else if (rss_i > 1)
psrtype |= 1 << 29;
for (p = 0; p < adapter->num_rx_pools; p++)
IXGBE_WRITE_REG(hw, IXGBE_PSRTYPE(VMDQ_P(p)),
psrtype);
}
static void ixgbe_configure_virtualization(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 reg_offset, vf_shift;
u32 gcr_ext, vmdctl;
int i;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return;
vmdctl = IXGBE_READ_REG(hw, IXGBE_VT_CTL);
vmdctl |= IXGBE_VMD_CTL_VMDQ_EN;
vmdctl &= ~IXGBE_VT_CTL_POOL_MASK;
vmdctl |= VMDQ_P(0) << IXGBE_VT_CTL_POOL_SHIFT;
vmdctl |= IXGBE_VT_CTL_REPLEN;
IXGBE_WRITE_REG(hw, IXGBE_VT_CTL, vmdctl);
vf_shift = VMDQ_P(0) % 32;
reg_offset = (VMDQ_P(0) >= 32) ? 1 : 0;
IXGBE_WRITE_REG(hw, IXGBE_VFRE(reg_offset), (~0) << vf_shift);
IXGBE_WRITE_REG(hw, IXGBE_VFRE(reg_offset ^ 1), reg_offset - 1);
IXGBE_WRITE_REG(hw, IXGBE_VFTE(reg_offset), (~0) << vf_shift);
IXGBE_WRITE_REG(hw, IXGBE_VFTE(reg_offset ^ 1), reg_offset - 1);
if (adapter->flags2 & IXGBE_FLAG2_BRIDGE_MODE_VEB)
IXGBE_WRITE_REG(hw, IXGBE_PFDTXGSWC, IXGBE_PFDTXGSWC_VT_LBEN);
hw->mac.ops.set_vmdq(hw, 0, VMDQ_P(0));
switch (adapter->ring_feature[RING_F_VMDQ].mask) {
case IXGBE_82599_VMDQ_8Q_MASK:
gcr_ext = IXGBE_GCR_EXT_VT_MODE_16;
break;
case IXGBE_82599_VMDQ_4Q_MASK:
gcr_ext = IXGBE_GCR_EXT_VT_MODE_32;
break;
default:
gcr_ext = IXGBE_GCR_EXT_VT_MODE_64;
break;
}
IXGBE_WRITE_REG(hw, IXGBE_GCR_EXT, gcr_ext);
hw->mac.ops.set_mac_anti_spoofing(hw, (adapter->num_vfs != 0),
adapter->num_vfs);
for (i = 0; i < adapter->num_vfs; i++) {
if (!adapter->vfinfo[i].spoofchk_enabled)
ixgbe_ndo_set_vf_spoofchk(adapter->netdev, i, false);
}
}
static void ixgbe_set_rx_buffer_len(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
int max_frame = netdev->mtu + ETH_HLEN + ETH_FCS_LEN;
struct ixgbe_ring *rx_ring;
int i;
u32 mhadd, hlreg0;
#ifdef IXGBE_FCOE
if ((adapter->flags & IXGBE_FLAG_FCOE_ENABLED) &&
(max_frame < IXGBE_FCOE_JUMBO_FRAME_SIZE))
max_frame = IXGBE_FCOE_JUMBO_FRAME_SIZE;
#endif
if (max_frame < (ETH_FRAME_LEN + ETH_FCS_LEN))
max_frame = (ETH_FRAME_LEN + ETH_FCS_LEN);
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
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)
set_ring_rsc_enabled(rx_ring);
else
clear_ring_rsc_enabled(rx_ring);
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
u32 rxctrl, rfctl;
rxctrl = IXGBE_READ_REG(hw, IXGBE_RXCTRL);
IXGBE_WRITE_REG(hw, IXGBE_RXCTRL, rxctrl & ~IXGBE_RXCTRL_RXEN);
ixgbe_setup_psrtype(adapter);
ixgbe_setup_rdrxctl(adapter);
rfctl = IXGBE_READ_REG(hw, IXGBE_RFCTL);
rfctl &= ~IXGBE_RFCTL_RSC_DIS;
if (!(adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED))
rfctl |= IXGBE_RFCTL_RSC_DIS;
IXGBE_WRITE_REG(hw, IXGBE_RFCTL, rfctl);
ixgbe_setup_mrqc(adapter);
ixgbe_set_rx_buffer_len(adapter);
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbe_configure_rx_ring(adapter, adapter->rx_ring[i]);
if (hw->mac.type == ixgbe_mac_82598EB)
rxctrl |= IXGBE_RXCTRL_DMBYPS;
rxctrl |= IXGBE_RXCTRL_RXEN;
hw->mac.ops.enable_rx_dma(hw, rxctrl);
}
static int ixgbe_vlan_rx_add_vid(struct net_device *netdev,
__be16 proto, u16 vid)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
hw->mac.ops.set_vfta(&adapter->hw, vid, VMDQ_P(0), true);
set_bit(vid, adapter->active_vlans);
return 0;
}
static int ixgbe_vlan_rx_kill_vid(struct net_device *netdev,
__be16 proto, u16 vid)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
hw->mac.ops.set_vfta(&adapter->hw, vid, VMDQ_P(0), false);
clear_bit(vid, adapter->active_vlans);
return 0;
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
ixgbe_vlan_rx_add_vid(adapter->netdev, htons(ETH_P_8021Q), 0);
for_each_set_bit(vid, adapter->active_vlans, VLAN_N_VID)
ixgbe_vlan_rx_add_vid(adapter->netdev, htons(ETH_P_8021Q), vid);
}
static int ixgbe_write_uc_addr_list(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
unsigned int rar_entries = hw->mac.num_rar_entries - 1;
int count = 0;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
rar_entries = IXGBE_MAX_PF_MACVLANS - 1;
if (netdev_uc_count(netdev) > rar_entries)
return -ENOMEM;
if (!netdev_uc_empty(netdev)) {
struct netdev_hw_addr *ha;
if (!hw->mac.ops.set_rar)
return -ENOMEM;
netdev_for_each_uc_addr(ha, netdev) {
if (!rar_entries)
break;
hw->mac.ops.set_rar(hw, rar_entries--, ha->addr,
VMDQ_P(0), IXGBE_RAH_AV);
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
fctrl &= ~IXGBE_FCTRL_SBP;
fctrl |= IXGBE_FCTRL_BAM;
fctrl |= IXGBE_FCTRL_DPF;
fctrl |= IXGBE_FCTRL_PMCF;
fctrl &= ~(IXGBE_FCTRL_UPE | IXGBE_FCTRL_MPE);
if (netdev->flags & IFF_PROMISC) {
hw->addr_ctrl.user_set_promisc = true;
fctrl |= (IXGBE_FCTRL_UPE | IXGBE_FCTRL_MPE);
vmolr |= (IXGBE_VMOLR_ROPE | IXGBE_VMOLR_MPE);
if (!(adapter->flags & (IXGBE_FLAG_VMDQ_ENABLED |
IXGBE_FLAG_SRIOV_ENABLED)))
ixgbe_vlan_filter_disable(adapter);
else
ixgbe_vlan_filter_enable(adapter);
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
}
count = ixgbe_write_uc_addr_list(netdev);
if (count < 0) {
fctrl |= IXGBE_FCTRL_UPE;
vmolr |= IXGBE_VMOLR_ROPE;
}
if (adapter->num_vfs)
ixgbe_restore_vf_multicasts(adapter);
if (hw->mac.type != ixgbe_mac_82598EB) {
vmolr |= IXGBE_READ_REG(hw, IXGBE_VMOLR(VMDQ_P(0))) &
~(IXGBE_VMOLR_MPE | IXGBE_VMOLR_ROMPE |
IXGBE_VMOLR_ROPE);
IXGBE_WRITE_REG(hw, IXGBE_VMOLR(VMDQ_P(0)), vmolr);
}
if (adapter->netdev->features & NETIF_F_RXALL) {
fctrl |= (IXGBE_FCTRL_SBP |
IXGBE_FCTRL_BAM |
IXGBE_FCTRL_PMCF);
fctrl &= ~(IXGBE_FCTRL_DPF);
}
IXGBE_WRITE_REG(hw, IXGBE_FCTRL, fctrl);
if (netdev->features & NETIF_F_HW_VLAN_CTAG_RX)
ixgbe_vlan_strip_enable(adapter);
else
ixgbe_vlan_strip_disable(adapter);
}
static void ixgbe_napi_enable_all(struct ixgbe_adapter *adapter)
{
int q_idx;
for (q_idx = 0; q_idx < adapter->num_q_vectors; q_idx++) {
ixgbe_qv_init_lock(adapter->q_vector[q_idx]);
napi_enable(&adapter->q_vector[q_idx]->napi);
}
}
static void ixgbe_napi_disable_all(struct ixgbe_adapter *adapter)
{
int q_idx;
local_bh_disable();
for (q_idx = 0; q_idx < adapter->num_q_vectors; q_idx++) {
napi_disable(&adapter->q_vector[q_idx]->napi);
while (!ixgbe_qv_lock_napi(adapter->q_vector[q_idx])) {
pr_info("QV %d locked\n", q_idx);
mdelay(1);
}
}
local_bh_enable();
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
#ifdef IXGBE_FCOE
if (adapter->netdev->features & NETIF_F_FCOE_MTU)
max_frame = max(max_frame, IXGBE_FCOE_JUMBO_FRAME_SIZE);
#endif
if (adapter->dcbx_cap & DCB_CAP_DCBX_VER_CEE) {
ixgbe_dcb_calculate_tc_credits(hw, &adapter->dcb_cfg, max_frame,
DCB_TX_CONFIG);
ixgbe_dcb_calculate_tc_credits(hw, &adapter->dcb_cfg, max_frame,
DCB_RX_CONFIG);
ixgbe_dcb_hw_config(hw, &adapter->dcb_cfg);
} else if (adapter->ixgbe_ieee_ets && adapter->ixgbe_ieee_pfc) {
ixgbe_dcb_hw_ets(&adapter->hw,
adapter->ixgbe_ieee_ets,
max_frame);
ixgbe_dcb_hw_pfc_config(&adapter->hw,
adapter->ixgbe_ieee_pfc->pfc_en,
adapter->ixgbe_ieee_ets->prio_tc);
}
if (hw->mac.type != ixgbe_mac_82598EB) {
u32 msb = 0;
u16 rss_i = adapter->ring_feature[RING_F_RSS].indices - 1;
while (rss_i) {
msb++;
rss_i >>= 1;
}
IXGBE_WRITE_REG(hw, IXGBE_RQTC, msb * 0x11111111);
}
}
static int ixgbe_hpbthresh(struct ixgbe_adapter *adapter, int pb)
{
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *dev = adapter->netdev;
int link, tc, kb, marker;
u32 dv_id, rx_pba;
tc = link = dev->mtu + ETH_HLEN + ETH_FCS_LEN + IXGBE_ETH_FRAMING;
#ifdef IXGBE_FCOE
if ((dev->features & NETIF_F_FCOE_MTU) &&
(tc < IXGBE_FCOE_JUMBO_FRAME_SIZE) &&
(pb == ixgbe_fcoe_get_tc(adapter)))
tc = IXGBE_FCOE_JUMBO_FRAME_SIZE;
#endif
switch (hw->mac.type) {
case ixgbe_mac_X540:
dv_id = IXGBE_DV_X540(link, tc);
break;
default:
dv_id = IXGBE_DV(link, tc);
break;
}
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
dv_id += IXGBE_B2BT(tc);
kb = IXGBE_BT2KB(dv_id);
rx_pba = IXGBE_READ_REG(hw, IXGBE_RXPBSIZE(pb)) >> 10;
marker = rx_pba - kb;
if (marker < 0) {
e_warn(drv, "Packet Buffer(%i) can not provide enough"
"headroom to support flow control."
"Decrease MTU or number of traffic classes\n", pb);
marker = tc + 1;
}
return marker;
}
static int ixgbe_lpbthresh(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *dev = adapter->netdev;
int tc;
u32 dv_id;
tc = dev->mtu + ETH_HLEN + ETH_FCS_LEN;
switch (hw->mac.type) {
case ixgbe_mac_X540:
dv_id = IXGBE_LOW_DV_X540(tc);
break;
default:
dv_id = IXGBE_LOW_DV(tc);
break;
}
return IXGBE_BT2KB(dv_id);
}
static void ixgbe_pbthresh_setup(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int num_tc = netdev_get_num_tc(adapter->netdev);
int i;
if (!num_tc)
num_tc = 1;
hw->fc.low_water = ixgbe_lpbthresh(adapter);
for (i = 0; i < num_tc; i++) {
hw->fc.high_water[i] = ixgbe_hpbthresh(adapter, i);
if (hw->fc.low_water > hw->fc.high_water[i])
hw->fc.low_water = 0;
}
}
static void ixgbe_configure_pb(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int hdrm;
u8 tc = netdev_get_num_tc(adapter->netdev);
if (adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE ||
adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE)
hdrm = 32 << adapter->fdir_pballoc;
else
hdrm = 0;
hw->mac.ops.set_rxpba(hw, tc, hdrm, PBA_STRATEGY_EQUAL);
ixgbe_pbthresh_setup(adapter);
}
static void ixgbe_fdir_filter_restore(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct hlist_node *node2;
struct ixgbe_fdir_filter *filter;
spin_lock(&adapter->fdir_perfect_lock);
if (!hlist_empty(&adapter->fdir_filter_list))
ixgbe_fdir_set_input_mask_82599(hw, &adapter->fdir_mask);
hlist_for_each_entry_safe(filter, node2,
&adapter->fdir_filter_list, fdir_node) {
ixgbe_fdir_write_perfect_filter_82599(hw,
&filter->filter,
filter->sw_idx,
(filter->action == IXGBE_FDIR_DROP_QUEUE) ?
IXGBE_FDIR_DROP_QUEUE :
adapter->rx_ring[filter->action]->reg_idx);
}
spin_unlock(&adapter->fdir_perfect_lock);
}
static void ixgbe_configure(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
ixgbe_configure_pb(adapter);
#ifdef CONFIG_IXGBE_DCB
ixgbe_configure_dcb(adapter);
#endif
ixgbe_configure_virtualization(adapter);
ixgbe_set_rx_mode(adapter->netdev);
ixgbe_restore_vlan(adapter);
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
hw->mac.ops.disable_rx_buff(hw);
break;
default:
break;
}
if (adapter->flags & IXGBE_FLAG_FDIR_HASH_CAPABLE) {
ixgbe_init_fdir_signature_82599(&adapter->hw,
adapter->fdir_pballoc);
} else if (adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE) {
ixgbe_init_fdir_perfect_82599(&adapter->hw,
adapter->fdir_pballoc);
ixgbe_fdir_filter_restore(adapter);
}
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
hw->mac.ops.enable_rx_buff(hw);
break;
default:
break;
}
#ifdef IXGBE_FCOE
ixgbe_configure_fcoe(adapter);
#endif
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
case ixgbe_phy_qsfp_passive_unknown:
case ixgbe_phy_qsfp_active_unknown:
case ixgbe_phy_qsfp_intel:
case ixgbe_phy_qsfp_unknown:
return true;
case ixgbe_phy_nl:
if (hw->mac.type == ixgbe_mac_82598EB)
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
u32 speed;
bool autoneg, link_up = false;
u32 ret = IXGBE_ERR_LINK_SETUP;
if (hw->mac.ops.check_link)
ret = hw->mac.ops.check_link(hw, &speed, &link_up, false);
if (ret)
goto link_cfg_out;
speed = hw->phy.autoneg_advertised;
if ((!speed) && (hw->mac.ops.get_link_capabilities))
ret = hw->mac.ops.get_link_capabilities(hw, &speed,
&autoneg);
if (ret)
goto link_cfg_out;
if (hw->mac.ops.setup_link)
ret = hw->mac.ops.setup_link(hw, speed, link_up);
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
switch (adapter->ring_feature[RING_F_VMDQ].mask) {
case IXGBE_82599_VMDQ_8Q_MASK:
gpie |= IXGBE_GPIE_VTMODE_16;
break;
case IXGBE_82599_VMDQ_4Q_MASK:
gpie |= IXGBE_GPIE_VTMODE_32;
break;
default:
gpie |= IXGBE_GPIE_VTMODE_64;
break;
}
}
if (adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE) {
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
gpie |= IXGBE_SDP0_GPIEN;
break;
case ixgbe_mac_X540:
gpie |= IXGBE_EIMS_TS;
break;
default:
break;
}
}
if (adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE)
gpie |= IXGBE_SDP1_GPIEN;
if (hw->mac.type == ixgbe_mac_82599EB) {
gpie |= IXGBE_SDP1_GPIEN;
gpie |= IXGBE_SDP2_GPIEN;
}
IXGBE_WRITE_REG(hw, IXGBE_GPIE, gpie);
}
static void ixgbe_up_complete(struct ixgbe_adapter *adapter)
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
if (hw->mac.ops.enable_tx_laser)
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
void ixgbe_up(struct ixgbe_adapter *adapter)
{
ixgbe_configure(adapter);
ixgbe_up_complete(adapter);
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
"Please be aware there may be issues associated with "
"your hardware. If you are experiencing problems "
"please contact your Intel or hardware "
"representative who provided you with this "
"hardware.\n");
break;
default:
e_dev_err("Hardware Error: %d\n", err);
}
clear_bit(__IXGBE_IN_SFP_INIT, &adapter->state);
hw->mac.ops.set_rar(hw, 0, hw->mac.addr, VMDQ_P(0), IXGBE_RAH_AV);
if (hw->mac.san_mac_rar_index)
hw->mac.ops.set_vmdq_san_mac(hw, VMDQ_P(0));
if (test_bit(__IXGBE_PTP_RUNNING, &adapter->state))
ixgbe_ptp_reset(adapter);
}
static void ixgbe_clean_rx_ring(struct ixgbe_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
unsigned long size;
u16 i;
if (!rx_ring->rx_buffer_info)
return;
for (i = 0; i < rx_ring->count; i++) {
struct ixgbe_rx_buffer *rx_buffer;
rx_buffer = &rx_ring->rx_buffer_info[i];
if (rx_buffer->skb) {
struct sk_buff *skb = rx_buffer->skb;
if (IXGBE_CB(skb)->page_released) {
dma_unmap_page(dev,
IXGBE_CB(skb)->dma,
ixgbe_rx_bufsz(rx_ring),
DMA_FROM_DEVICE);
IXGBE_CB(skb)->page_released = false;
}
dev_kfree_skb(skb);
}
rx_buffer->skb = NULL;
if (rx_buffer->dma)
dma_unmap_page(dev, rx_buffer->dma,
ixgbe_rx_pg_size(rx_ring),
DMA_FROM_DEVICE);
rx_buffer->dma = 0;
if (rx_buffer->page)
__free_pages(rx_buffer->page,
ixgbe_rx_pg_order(rx_ring));
rx_buffer->page = NULL;
}
size = sizeof(struct ixgbe_rx_buffer) * rx_ring->count;
memset(rx_ring->rx_buffer_info, 0, size);
memset(rx_ring->desc, 0, rx_ring->size);
rx_ring->next_to_alloc = 0;
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
netdev_tx_reset_queue(txring_txq(tx_ring));
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
static void ixgbe_fdir_filter_exit(struct ixgbe_adapter *adapter)
{
struct hlist_node *node2;
struct ixgbe_fdir_filter *filter;
spin_lock(&adapter->fdir_perfect_lock);
hlist_for_each_entry_safe(filter, node2,
&adapter->fdir_filter_list, fdir_node) {
hlist_del(&filter->fdir_node);
kfree(filter);
}
adapter->fdir_filter_count = 0;
spin_unlock(&adapter->fdir_perfect_lock);
}
void ixgbe_down(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
u32 rxctrl;
int i;
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
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EITRSEL, 0);
for (i = 0 ; i < adapter->num_vfs; i++)
adapter->vfinfo[i].clear_to_send = false;
ixgbe_ping_all_vfs(adapter);
ixgbe_disable_tx_rx(adapter);
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
if (hw->mac.ops.disable_tx_laser)
hw->mac.ops.disable_tx_laser(hw);
ixgbe_clean_all_tx_rings(adapter);
ixgbe_clean_all_rx_rings(adapter);
#ifdef CONFIG_IXGBE_DCA
ixgbe_setup_dca(adapter);
#endif
}
static void ixgbe_tx_timeout(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
ixgbe_tx_timeout_reset(adapter);
}
static int ixgbe_sw_init(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
unsigned int rss, fdir;
u32 fwsm;
#ifdef CONFIG_IXGBE_DCB
int j;
struct tc_configuration *tc;
#endif
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
hw->revision_id = pdev->revision;
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
rss = min_t(int, IXGBE_MAX_RSS_INDICES, num_online_cpus());
adapter->ring_feature[RING_F_RSS].limit = rss;
adapter->flags2 |= IXGBE_FLAG2_RSC_CAPABLE;
adapter->flags2 |= IXGBE_FLAG2_RSC_ENABLED;
adapter->max_q_vectors = MAX_Q_VECTORS_82599;
adapter->atr_sample_rate = 20;
fdir = min_t(int, IXGBE_MAX_FDIR_INDICES, num_online_cpus());
adapter->ring_feature[RING_F_FDIR].limit = fdir;
adapter->fdir_pballoc = IXGBE_FDIR_PBALLOC_64K;
#ifdef CONFIG_IXGBE_DCA
adapter->flags |= IXGBE_FLAG_DCA_CAPABLE;
#endif
#ifdef IXGBE_FCOE
adapter->flags |= IXGBE_FLAG_FCOE_CAPABLE;
adapter->flags &= ~IXGBE_FLAG_FCOE_ENABLED;
#ifdef CONFIG_IXGBE_DCB
adapter->fcoe.up = IXGBE_FCOE_DEFTC;
#endif
#endif
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
adapter->flags2 &= ~IXGBE_FLAG2_RSC_CAPABLE;
adapter->flags2 &= ~IXGBE_FLAG2_RSC_ENABLED;
if (hw->device_id == IXGBE_DEV_ID_82598AT)
adapter->flags |= IXGBE_FLAG_FAN_FAIL_CAPABLE;
adapter->max_q_vectors = MAX_Q_VECTORS_82598;
adapter->ring_feature[RING_F_FDIR].limit = 0;
adapter->atr_sample_rate = 0;
adapter->fdir_pballoc = 0;
#ifdef IXGBE_FCOE
adapter->flags &= ~IXGBE_FLAG_FCOE_CAPABLE;
adapter->flags &= ~IXGBE_FLAG_FCOE_ENABLED;
#ifdef CONFIG_IXGBE_DCB
adapter->fcoe.up = 0;
#endif
#endif
break;
case ixgbe_mac_82599EB:
if (hw->device_id == IXGBE_DEV_ID_82599_T3_LOM)
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_CAPABLE;
break;
case ixgbe_mac_X540:
fwsm = IXGBE_READ_REG(hw, IXGBE_FWSM);
if (fwsm & IXGBE_FWSM_TS_ENABLED)
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_CAPABLE;
break;
default:
break;
}
#ifdef IXGBE_FCOE
spin_lock_init(&adapter->fcoe.lock);
#endif
spin_lock_init(&adapter->fdir_perfect_lock);
#ifdef CONFIG_IXGBE_DCB
switch (hw->mac.type) {
case ixgbe_mac_X540:
adapter->dcb_cfg.num_tcs.pg_tcs = X540_TRAFFIC_CLASS;
adapter->dcb_cfg.num_tcs.pfc_tcs = X540_TRAFFIC_CLASS;
break;
default:
adapter->dcb_cfg.num_tcs.pg_tcs = MAX_TRAFFIC_CLASS;
adapter->dcb_cfg.num_tcs.pfc_tcs = MAX_TRAFFIC_CLASS;
break;
}
for (j = 0; j < MAX_TRAFFIC_CLASS; j++) {
tc = &adapter->dcb_cfg.tc_config[j];
tc->path[DCB_TX_CONFIG].bwg_id = 0;
tc->path[DCB_TX_CONFIG].bwg_percent = 12 + (j & 1);
tc->path[DCB_RX_CONFIG].bwg_id = 0;
tc->path[DCB_RX_CONFIG].bwg_percent = 12 + (j & 1);
tc->dcb_pfc = pfc_disabled;
}
tc = &adapter->dcb_cfg.tc_config[0];
tc->path[DCB_TX_CONFIG].up_to_tc_bitmap = 0xFF;
tc->path[DCB_RX_CONFIG].up_to_tc_bitmap = 0xFF;
adapter->dcb_cfg.bw_percentage[DCB_TX_CONFIG][0] = 100;
adapter->dcb_cfg.bw_percentage[DCB_RX_CONFIG][0] = 100;
adapter->dcb_cfg.pfc_mode_enable = false;
adapter->dcb_set_bitmap = 0x00;
adapter->dcbx_cap = DCB_CAP_DCBX_HOST | DCB_CAP_DCBX_VER_CEE;
memcpy(&adapter->temp_dcb_cfg, &adapter->dcb_cfg,
sizeof(adapter->temp_dcb_cfg));
#endif
hw->fc.requested_mode = ixgbe_fc_full;
hw->fc.current_mode = ixgbe_fc_full;
ixgbe_pbthresh_setup(adapter);
hw->fc.pause_time = IXGBE_DEFAULT_FCPAUSE;
hw->fc.send_xon = true;
hw->fc.disable_fc_autoneg = ixgbe_device_supports_autoneg_fc(hw);
#ifdef CONFIG_PCI_IOV
if (hw->mac.type != ixgbe_mac_82598EB)
adapter->num_vfs = (max_vfs > 63) ? 0 : max_vfs;
#endif
adapter->rx_itr_setting = 1;
adapter->tx_itr_setting = 1;
adapter->tx_ring_count = IXGBE_DEFAULT_TXD;
adapter->rx_ring_count = IXGBE_DEFAULT_RXD;
adapter->tx_work_limit = IXGBE_DEFAULT_TX_WORK;
if (ixgbe_init_eeprom_params_generic(hw)) {
e_dev_err("EEPROM initialization failed\n");
return -EIO;
}
set_bit(__IXGBE_DOWN, &adapter->state);
return 0;
}
int ixgbe_setup_tx_resources(struct ixgbe_ring *tx_ring)
{
struct device *dev = tx_ring->dev;
int orig_node = dev_to_node(dev);
int numa_node = -1;
int size;
size = sizeof(struct ixgbe_tx_buffer) * tx_ring->count;
if (tx_ring->q_vector)
numa_node = tx_ring->q_vector->numa_node;
tx_ring->tx_buffer_info = vzalloc_node(size, numa_node);
if (!tx_ring->tx_buffer_info)
tx_ring->tx_buffer_info = vzalloc(size);
if (!tx_ring->tx_buffer_info)
goto err;
tx_ring->size = tx_ring->count * sizeof(union ixgbe_adv_tx_desc);
tx_ring->size = ALIGN(tx_ring->size, 4096);
set_dev_node(dev, numa_node);
tx_ring->desc = dma_alloc_coherent(dev,
tx_ring->size,
&tx_ring->dma,
GFP_KERNEL);
set_dev_node(dev, orig_node);
if (!tx_ring->desc)
tx_ring->desc = dma_alloc_coherent(dev, tx_ring->size,
&tx_ring->dma, GFP_KERNEL);
if (!tx_ring->desc)
goto err;
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
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
goto err_setup_tx;
}
return 0;
err_setup_tx:
while (i--)
ixgbe_free_tx_resources(adapter->tx_ring[i]);
return err;
}
int ixgbe_setup_rx_resources(struct ixgbe_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
int orig_node = dev_to_node(dev);
int numa_node = -1;
int size;
size = sizeof(struct ixgbe_rx_buffer) * rx_ring->count;
if (rx_ring->q_vector)
numa_node = rx_ring->q_vector->numa_node;
rx_ring->rx_buffer_info = vzalloc_node(size, numa_node);
if (!rx_ring->rx_buffer_info)
rx_ring->rx_buffer_info = vzalloc(size);
if (!rx_ring->rx_buffer_info)
goto err;
rx_ring->size = rx_ring->count * sizeof(union ixgbe_adv_rx_desc);
rx_ring->size = ALIGN(rx_ring->size, 4096);
set_dev_node(dev, numa_node);
rx_ring->desc = dma_alloc_coherent(dev,
rx_ring->size,
&rx_ring->dma,
GFP_KERNEL);
set_dev_node(dev, orig_node);
if (!rx_ring->desc)
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
goto err_setup_rx;
}
#ifdef IXGBE_FCOE
err = ixgbe_setup_fcoe_ddp_resources(adapter);
if (!err)
#endif
return 0;
err_setup_rx:
while (i--)
ixgbe_free_rx_resources(adapter->rx_ring[i]);
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
#ifdef IXGBE_FCOE
ixgbe_free_fcoe_ddp_resources(adapter);
#endif
for (i = 0; i < adapter->num_rx_queues; i++)
if (adapter->rx_ring[i]->desc)
ixgbe_free_rx_resources(adapter->rx_ring[i]);
}
static int ixgbe_change_mtu(struct net_device *netdev, int new_mtu)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN;
if ((new_mtu < 68) || (max_frame > IXGBE_MAX_JUMBO_FRAME_SIZE))
return -EINVAL;
if ((adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) &&
(adapter->hw.mac.type == ixgbe_mac_82599EB) &&
(max_frame > (ETH_FRAME_LEN + ETH_FCS_LEN)))
e_warn(probe, "Setting MTU > 1500 will disable legacy VFs\n");
e_info(probe, "changing MTU from %d to %d\n", netdev->mtu, new_mtu);
netdev->mtu = new_mtu;
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
err = netif_set_real_num_tx_queues(netdev,
adapter->num_rx_pools > 1 ? 1 :
adapter->num_tx_queues);
if (err)
goto err_set_queues;
err = netif_set_real_num_rx_queues(netdev,
adapter->num_rx_pools > 1 ? 1 :
adapter->num_rx_queues);
if (err)
goto err_set_queues;
ixgbe_ptp_init(adapter);
ixgbe_up_complete(adapter);
return 0;
err_set_queues:
ixgbe_free_irq(adapter);
err_req_irq:
ixgbe_free_all_rx_resources(adapter);
err_setup_rx:
ixgbe_free_all_tx_resources(adapter);
err_setup_tx:
ixgbe_reset(adapter);
return err;
}
static int ixgbe_close(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
ixgbe_ptp_stop(adapter);
ixgbe_down(adapter);
ixgbe_free_irq(adapter);
ixgbe_fdir_filter_exit(adapter);
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
ixgbe_reset(adapter);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_WUS, ~0);
rtnl_lock();
err = ixgbe_init_interrupt_scheme(adapter);
if (!err && netif_running(netdev))
err = ixgbe_open(netdev);
rtnl_unlock();
if (err)
return err;
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
rtnl_lock();
if (netif_running(netdev)) {
ixgbe_down(adapter);
ixgbe_free_irq(adapter);
ixgbe_free_all_tx_resources(adapter);
ixgbe_free_all_rx_resources(adapter);
}
rtnl_unlock();
ixgbe_clear_interrupt_scheme(adapter);
#ifdef CONFIG_PM
retval = pci_save_state(pdev);
if (retval)
return retval;
#endif
if (hw->mac.ops.stop_link_on_d3)
hw->mac.ops.stop_link_on_d3(hw);
if (wufc) {
ixgbe_set_rx_mode(netdev);
if (hw->mac.ops.enable_tx_laser)
hw->mac.ops.enable_tx_laser(hw);
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
u64 bytes = 0, packets = 0, hw_csum_rx_error = 0;
if (test_bit(__IXGBE_DOWN, &adapter->state) ||
test_bit(__IXGBE_RESETTING, &adapter->state))
return;
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED) {
u64 rsc_count = 0;
u64 rsc_flush = 0;
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
hw_csum_rx_error += rx_ring->rx_stats.csum_err;
bytes += rx_ring->stats.bytes;
packets += rx_ring->stats.packets;
}
adapter->non_eop_descs = non_eop_descs;
adapter->alloc_rx_page_failed = alloc_rx_page_failed;
adapter->alloc_rx_buff_failed = alloc_rx_buff_failed;
adapter->hw_csum_rx_error = hw_csum_rx_error;
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
hwstats->pxontxc[i] += IXGBE_READ_REG(hw, IXGBE_PXONTXC(i));
hwstats->pxofftxc[i] += IXGBE_READ_REG(hw, IXGBE_PXOFFTXC(i));
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
hwstats->rnbc[i] += IXGBE_READ_REG(hw, IXGBE_RNBC(i));
hwstats->qbtc[i] += IXGBE_READ_REG(hw, IXGBE_QBTC(i));
hwstats->qbrc[i] += IXGBE_READ_REG(hw, IXGBE_QBRC(i));
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
}
for (i = 0; i < 16; i++) {
hwstats->qptc[i] += IXGBE_READ_REG(hw, IXGBE_QPTC(i));
hwstats->qprc[i] += IXGBE_READ_REG(hw, IXGBE_QPRC(i));
if ((hw->mac.type == ixgbe_mac_82599EB) ||
(hw->mac.type == ixgbe_mac_X540)) {
hwstats->qbtc[i] += IXGBE_READ_REG(hw, IXGBE_QBTC_L(i));
IXGBE_READ_REG(hw, IXGBE_QBTC_H(i));
hwstats->qbrc[i] += IXGBE_READ_REG(hw, IXGBE_QBRC_L(i));
IXGBE_READ_REG(hw, IXGBE_QBRC_H(i));
}
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
for (i = 0; i < 16; i++)
adapter->hw_rx_no_dma_resources +=
IXGBE_READ_REG(hw, IXGBE_QPRDC(i));
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
if (adapter->fcoe.ddp_pool) {
struct ixgbe_fcoe *fcoe = &adapter->fcoe;
struct ixgbe_fcoe_ddp_pool *ddp_pool;
unsigned int cpu;
u64 noddp = 0, noddp_ext_buff = 0;
for_each_possible_cpu(cpu) {
ddp_pool = per_cpu_ptr(fcoe->ddp_pool, cpu);
noddp += ddp_pool->noddp;
noddp_ext_buff += ddp_pool->noddp_ext_buff;
}
hwstats->fcoe_noddp = noddp;
hwstats->fcoe_noddp_ext_buff = noddp_ext_buff;
}
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
for (i = 0; i < adapter->num_q_vectors; i++) {
struct ixgbe_q_vector *qv = adapter->q_vector[i];
if (qv->rx.ring || qv->tx.ring)
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
bool pfc_en = adapter->dcb_cfg.pfc_mode_enable;
if (!(adapter->flags & IXGBE_FLAG_NEED_LINK_UPDATE))
return;
if (hw->mac.ops.check_link) {
hw->mac.ops.check_link(hw, &link_speed, &link_up, false);
} else {
link_speed = IXGBE_LINK_SPEED_10GB_FULL;
link_up = true;
}
if (adapter->ixgbe_ieee_pfc)
pfc_en |= !!(adapter->ixgbe_ieee_pfc->pfc_en);
if (link_up && !((adapter->flags & IXGBE_FLAG_DCB_ENABLED) && pfc_en)) {
hw->mac.ops.fc_enable(hw);
ixgbe_set_rx_drop_en(adapter);
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
static void ixgbe_update_default_up(struct ixgbe_adapter *adapter)
{
#ifdef CONFIG_IXGBE_DCB
struct net_device *netdev = adapter->netdev;
struct dcb_app app = {
.selector = IEEE_8021QAZ_APP_SEL_ETHERTYPE,
.protocol = 0,
};
u8 up = 0;
if (adapter->dcbx_cap & DCB_CAP_DCBX_VER_IEEE)
up = dcb_ieee_getapp_mask(netdev, &app);
adapter->default_up = (up > 1) ? (ffs(up) - 1) : 0;
#endif
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
adapter->last_rx_ptp_check = jiffies;
if (test_bit(__IXGBE_PTP_RUNNING, &adapter->state))
ixgbe_ptp_start_cyclecounter(adapter);
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
ixgbe_check_vf_rate_limit(adapter);
ixgbe_update_default_up(adapter);
ixgbe_ping_all_vfs(adapter);
}
static void ixgbe_watchdog_link_is_down(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
adapter->link_up = false;
adapter->link_speed = 0;
if (!netif_carrier_ok(netdev))
return;
if (ixgbe_is_sfp(hw) && hw->mac.type == ixgbe_mac_82598EB)
adapter->flags2 |= IXGBE_FLAG2_SEARCH_FOR_SFP;
if (test_bit(__IXGBE_PTP_RUNNING, &adapter->state))
ixgbe_ptp_start_cyclecounter(adapter);
e_info(drv, "NIC Link is Down\n");
netif_carrier_off(netdev);
ixgbe_ping_all_vfs(adapter);
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
e_warn(drv, "initiating reset to clear Tx work after link loss\n");
adapter->flags2 |= IXGBE_FLAG2_RESET_REQUESTED;
}
}
}
static void ixgbe_spoof_check(struct ixgbe_adapter *adapter)
{
u32 ssvpc;
if (adapter->hw.mac.type == ixgbe_mac_82598EB ||
adapter->num_vfs == 0)
return;
ssvpc = IXGBE_READ_REG(&adapter->hw, IXGBE_SSVPC);
if (!ssvpc)
return;
e_warn(drv, "%u Spoofed packets detected\n", ssvpc);
}
static void ixgbe_watchdog_subtask(struct ixgbe_adapter *adapter)
{
if (test_bit(__IXGBE_DOWN, &adapter->state) ||
test_bit(__IXGBE_RESETTING, &adapter->state))
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
u32 speed;
bool autoneg = false;
if (!(adapter->flags & IXGBE_FLAG_NEED_LINK_CONFIG))
return;
if (test_and_set_bit(__IXGBE_IN_SFP_INIT, &adapter->state))
return;
adapter->flags &= ~IXGBE_FLAG_NEED_LINK_CONFIG;
speed = hw->phy.autoneg_advertised;
if ((!speed) && (hw->mac.ops.get_link_capabilities)) {
hw->mac.ops.get_link_capabilities(hw, &speed, &autoneg);
if (!autoneg) {
if (speed & IXGBE_LINK_SPEED_10GB_FULL)
speed = IXGBE_LINK_SPEED_10GB_FULL;
}
}
if (hw->mac.ops.setup_link)
hw->mac.ops.setup_link(hw, speed, true);
adapter->flags |= IXGBE_FLAG_NEED_LINK_UPDATE;
adapter->link_check_timeout = jiffies;
clear_bit(__IXGBE_IN_SFP_INIT, &adapter->state);
}
static void ixgbe_check_for_bad_vf(struct ixgbe_adapter *adapter)
{
int vf;
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
u32 gpc;
u32 ciaa, ciad;
gpc = IXGBE_READ_REG(hw, IXGBE_TXDGPC);
if (gpc)
return;
for (vf = 0; vf < adapter->num_vfs; vf++) {
ciaa = (vf << 16) | 0x80000000;
ciaa |= PCI_COMMAND;
IXGBE_WRITE_REG(hw, IXGBE_CIAA_82599, ciaa);
ciad = IXGBE_READ_REG(hw, IXGBE_CIAD_82599);
ciaa &= 0x7FFFFFFF;
IXGBE_WRITE_REG(hw, IXGBE_CIAA_82599, ciaa);
ciad >>= 16;
if (ciad & PCI_STATUS_REC_MASTER_ABORT) {
netdev_err(netdev, "VF %d Hung DMA\n", vf);
ciaa = (vf << 16) | 0x80000000;
ciaa |= 0xA8;
IXGBE_WRITE_REG(hw, IXGBE_CIAA_82599, ciaa);
ciad = 0x00008000;
IXGBE_WRITE_REG(hw, IXGBE_CIAD_82599, ciad);
ciaa &= 0x7FFFFFFF;
IXGBE_WRITE_REG(hw, IXGBE_CIAA_82599, ciaa);
}
}
}
static void ixgbe_service_timer(unsigned long data)
{
struct ixgbe_adapter *adapter = (struct ixgbe_adapter *)data;
unsigned long next_event_offset;
bool ready = true;
if (adapter->flags & IXGBE_FLAG_NEED_LINK_UPDATE)
next_event_offset = HZ / 10;
else
next_event_offset = HZ * 2;
#ifdef CONFIG_PCI_IOV
if (!adapter->num_vfs ||
(adapter->flags & IXGBE_FLAG_NEED_LINK_UPDATE))
goto normal_timer_service;
ixgbe_check_for_bad_vf(adapter);
next_event_offset = HZ / 50;
adapter->timer_event_accumulator++;
if (adapter->timer_event_accumulator >= 100)
adapter->timer_event_accumulator = 0;
else
ready = false;
normal_timer_service:
#endif
mod_timer(&adapter->service_timer, next_event_offset + jiffies);
if (ready)
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
if (test_bit(__IXGBE_PTP_RUNNING, &adapter->state)) {
ixgbe_ptp_overflow_check(adapter);
ixgbe_ptp_rx_hang(adapter);
}
ixgbe_service_event_complete(adapter);
}
static int ixgbe_tso(struct ixgbe_ring *tx_ring,
struct ixgbe_tx_buffer *first,
u8 *hdr_len)
{
struct sk_buff *skb = first->skb;
u32 vlan_macip_lens, type_tucmd;
u32 mss_l4len_idx, l4len;
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (!skb_is_gso(skb))
return 0;
if (skb_header_cloned(skb)) {
int err = pskb_expand_head(skb, 0, 0, GFP_ATOMIC);
if (err)
return err;
}
type_tucmd = IXGBE_ADVTXD_TUCMD_L4T_TCP;
if (first->protocol == __constant_htons(ETH_P_IP)) {
struct iphdr *iph = ip_hdr(skb);
iph->tot_len = 0;
iph->check = 0;
tcp_hdr(skb)->check = ~csum_tcpudp_magic(iph->saddr,
iph->daddr, 0,
IPPROTO_TCP,
0);
type_tucmd |= IXGBE_ADVTXD_TUCMD_IPV4;
first->tx_flags |= IXGBE_TX_FLAGS_TSO |
IXGBE_TX_FLAGS_CSUM |
IXGBE_TX_FLAGS_IPV4;
} else if (skb_is_gso_v6(skb)) {
ipv6_hdr(skb)->payload_len = 0;
tcp_hdr(skb)->check =
~csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr,
0, IPPROTO_TCP, 0);
first->tx_flags |= IXGBE_TX_FLAGS_TSO |
IXGBE_TX_FLAGS_CSUM;
}
l4len = tcp_hdrlen(skb);
*hdr_len = skb_transport_offset(skb) + l4len;
first->gso_segs = skb_shinfo(skb)->gso_segs;
first->bytecount += (first->gso_segs - 1) * *hdr_len;
mss_l4len_idx = l4len << IXGBE_ADVTXD_L4LEN_SHIFT;
mss_l4len_idx |= skb_shinfo(skb)->gso_size << IXGBE_ADVTXD_MSS_SHIFT;
vlan_macip_lens = skb_network_header_len(skb);
vlan_macip_lens |= skb_network_offset(skb) << IXGBE_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= first->tx_flags & IXGBE_TX_FLAGS_VLAN_MASK;
ixgbe_tx_ctxtdesc(tx_ring, vlan_macip_lens, 0, type_tucmd,
mss_l4len_idx);
return 1;
}
static void ixgbe_tx_csum(struct ixgbe_ring *tx_ring,
struct ixgbe_tx_buffer *first)
{
struct sk_buff *skb = first->skb;
u32 vlan_macip_lens = 0;
u32 mss_l4len_idx = 0;
u32 type_tucmd = 0;
if (skb->ip_summed != CHECKSUM_PARTIAL) {
if (!(first->tx_flags & IXGBE_TX_FLAGS_HW_VLAN) &&
!(first->tx_flags & IXGBE_TX_FLAGS_CC))
return;
} else {
u8 l4_hdr = 0;
switch (first->protocol) {
case __constant_htons(ETH_P_IP):
vlan_macip_lens |= skb_network_header_len(skb);
type_tucmd |= IXGBE_ADVTXD_TUCMD_IPV4;
l4_hdr = ip_hdr(skb)->protocol;
break;
case __constant_htons(ETH_P_IPV6):
vlan_macip_lens |= skb_network_header_len(skb);
l4_hdr = ipv6_hdr(skb)->nexthdr;
break;
default:
if (unlikely(net_ratelimit())) {
dev_warn(tx_ring->dev,
"partial checksum but proto=%x!\n",
first->protocol);
}
break;
}
switch (l4_hdr) {
case IPPROTO_TCP:
type_tucmd |= IXGBE_ADVTXD_TUCMD_L4T_TCP;
mss_l4len_idx = tcp_hdrlen(skb) <<
IXGBE_ADVTXD_L4LEN_SHIFT;
break;
case IPPROTO_SCTP:
type_tucmd |= IXGBE_ADVTXD_TUCMD_L4T_SCTP;
mss_l4len_idx = sizeof(struct sctphdr) <<
IXGBE_ADVTXD_L4LEN_SHIFT;
break;
case IPPROTO_UDP:
mss_l4len_idx = sizeof(struct udphdr) <<
IXGBE_ADVTXD_L4LEN_SHIFT;
break;
default:
if (unlikely(net_ratelimit())) {
dev_warn(tx_ring->dev,
"partial checksum but l4 proto=%x!\n",
l4_hdr);
}
break;
}
first->tx_flags |= IXGBE_TX_FLAGS_CSUM;
}
vlan_macip_lens |= skb_network_offset(skb) << IXGBE_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= first->tx_flags & IXGBE_TX_FLAGS_VLAN_MASK;
ixgbe_tx_ctxtdesc(tx_ring, vlan_macip_lens, 0,
type_tucmd, mss_l4len_idx);
}
static u32 ixgbe_tx_cmd_type(struct sk_buff *skb, u32 tx_flags)
{
u32 cmd_type = IXGBE_ADVTXD_DTYP_DATA |
IXGBE_ADVTXD_DCMD_DEXT |
IXGBE_ADVTXD_DCMD_IFCS;
cmd_type |= IXGBE_SET_FLAG(tx_flags, IXGBE_TX_FLAGS_HW_VLAN,
IXGBE_ADVTXD_DCMD_VLE);
cmd_type |= IXGBE_SET_FLAG(tx_flags, IXGBE_TX_FLAGS_TSO,
IXGBE_ADVTXD_DCMD_TSE);
cmd_type |= IXGBE_SET_FLAG(tx_flags, IXGBE_TX_FLAGS_TSTAMP,
IXGBE_ADVTXD_MAC_TSTAMP);
cmd_type ^= IXGBE_SET_FLAG(skb->no_fcs, 1, IXGBE_ADVTXD_DCMD_IFCS);
return cmd_type;
}
static void ixgbe_tx_olinfo_status(union ixgbe_adv_tx_desc *tx_desc,
u32 tx_flags, unsigned int paylen)
{
u32 olinfo_status = paylen << IXGBE_ADVTXD_PAYLEN_SHIFT;
olinfo_status |= IXGBE_SET_FLAG(tx_flags,
IXGBE_TX_FLAGS_CSUM,
IXGBE_ADVTXD_POPTS_TXSM);
olinfo_status |= IXGBE_SET_FLAG(tx_flags,
IXGBE_TX_FLAGS_IPV4,
IXGBE_ADVTXD_POPTS_IXSM);
olinfo_status |= IXGBE_SET_FLAG(tx_flags,
IXGBE_TX_FLAGS_CC,
IXGBE_ADVTXD_CC);
tx_desc->read.olinfo_status = cpu_to_le32(olinfo_status);
}
static void ixgbe_tx_map(struct ixgbe_ring *tx_ring,
struct ixgbe_tx_buffer *first,
const u8 hdr_len)
{
struct sk_buff *skb = first->skb;
struct ixgbe_tx_buffer *tx_buffer;
union ixgbe_adv_tx_desc *tx_desc;
struct skb_frag_struct *frag;
dma_addr_t dma;
unsigned int data_len, size;
u32 tx_flags = first->tx_flags;
u32 cmd_type = ixgbe_tx_cmd_type(skb, tx_flags);
u16 i = tx_ring->next_to_use;
tx_desc = IXGBE_TX_DESC(tx_ring, i);
ixgbe_tx_olinfo_status(tx_desc, tx_flags, skb->len - hdr_len);
size = skb_headlen(skb);
data_len = skb->data_len;
#ifdef IXGBE_FCOE
if (tx_flags & IXGBE_TX_FLAGS_FCOE) {
if (data_len < sizeof(struct fcoe_crc_eof)) {
size -= sizeof(struct fcoe_crc_eof) - data_len;
data_len = 0;
} else {
data_len -= sizeof(struct fcoe_crc_eof);
}
}
#endif
dma = dma_map_single(tx_ring->dev, skb->data, size, DMA_TO_DEVICE);
tx_buffer = first;
for (frag = &skb_shinfo(skb)->frags[0];; frag++) {
if (dma_mapping_error(tx_ring->dev, dma))
goto dma_error;
dma_unmap_len_set(tx_buffer, len, size);
dma_unmap_addr_set(tx_buffer, dma, dma);
tx_desc->read.buffer_addr = cpu_to_le64(dma);
while (unlikely(size > IXGBE_MAX_DATA_PER_TXD)) {
tx_desc->read.cmd_type_len =
cpu_to_le32(cmd_type ^ IXGBE_MAX_DATA_PER_TXD);
i++;
tx_desc++;
if (i == tx_ring->count) {
tx_desc = IXGBE_TX_DESC(tx_ring, 0);
i = 0;
}
tx_desc->read.olinfo_status = 0;
dma += IXGBE_MAX_DATA_PER_TXD;
size -= IXGBE_MAX_DATA_PER_TXD;
tx_desc->read.buffer_addr = cpu_to_le64(dma);
}
if (likely(!data_len))
break;
tx_desc->read.cmd_type_len = cpu_to_le32(cmd_type ^ size);
i++;
tx_desc++;
if (i == tx_ring->count) {
tx_desc = IXGBE_TX_DESC(tx_ring, 0);
i = 0;
}
tx_desc->read.olinfo_status = 0;
#ifdef IXGBE_FCOE
size = min_t(unsigned int, data_len, skb_frag_size(frag));
#else
size = skb_frag_size(frag);
#endif
data_len -= size;
dma = skb_frag_dma_map(tx_ring->dev, frag, 0, size,
DMA_TO_DEVICE);
tx_buffer = &tx_ring->tx_buffer_info[i];
}
cmd_type |= size | IXGBE_TXD_CMD;
tx_desc->read.cmd_type_len = cpu_to_le32(cmd_type);
netdev_tx_sent_queue(txring_txq(tx_ring), first->bytecount);
first->time_stamp = jiffies;
wmb();
first->next_to_watch = tx_desc;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
writel(i, tx_ring->tail);
return;
dma_error:
dev_err(tx_ring->dev, "TX DMA map failed\n");
for (;;) {
tx_buffer = &tx_ring->tx_buffer_info[i];
ixgbe_unmap_and_free_tx_resource(tx_ring, tx_buffer);
if (tx_buffer == first)
break;
if (i == 0)
i = tx_ring->count;
i--;
}
tx_ring->next_to_use = i;
}
static void ixgbe_atr(struct ixgbe_ring *ring,
struct ixgbe_tx_buffer *first)
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
hdr.network = skb_network_header(first->skb);
if ((first->protocol != __constant_htons(ETH_P_IPV6) ||
hdr.ipv6->nexthdr != IPPROTO_TCP) &&
(first->protocol != __constant_htons(ETH_P_IP) ||
hdr.ipv4->protocol != IPPROTO_TCP))
return;
th = tcp_hdr(first->skb);
if (!th || th->fin)
return;
if (!th->syn && (ring->atr_count < ring->atr_sample_rate))
return;
ring->atr_count = 0;
vlan_id = htons(first->tx_flags >> IXGBE_TX_FLAGS_VLAN_SHIFT);
input.formatted.vlan_id = vlan_id;
if (first->tx_flags & (IXGBE_TX_FLAGS_SW_VLAN | IXGBE_TX_FLAGS_HW_VLAN))
common.port.src ^= th->dest ^ __constant_htons(ETH_P_8021Q);
else
common.port.src ^= th->dest ^ first->protocol;
common.port.dst ^= th->source;
if (first->protocol == __constant_htons(ETH_P_IP)) {
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
static int __ixgbe_maybe_stop_tx(struct ixgbe_ring *tx_ring, u16 size)
{
netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
smp_mb();
if (likely(ixgbe_desc_unused(tx_ring) < size))
return -EBUSY;
netif_start_subqueue(tx_ring->netdev, tx_ring->queue_index);
++tx_ring->tx_stats.restart_queue;
return 0;
}
static inline int ixgbe_maybe_stop_tx(struct ixgbe_ring *tx_ring, u16 size)
{
if (likely(ixgbe_desc_unused(tx_ring) >= size))
return 0;
return __ixgbe_maybe_stop_tx(tx_ring, size);
}
static u16 ixgbe_select_queue(struct net_device *dev, struct sk_buff *skb)
{
struct ixgbe_adapter *adapter;
struct ixgbe_ring_feature *f;
int txq;
switch (vlan_get_protocol(skb)) {
case __constant_htons(ETH_P_FCOE):
case __constant_htons(ETH_P_FIP):
adapter = netdev_priv(dev);
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED)
break;
default:
return __netdev_pick_tx(dev, skb);
}
f = &adapter->ring_feature[RING_F_FCOE];
txq = skb_rx_queue_recorded(skb) ? skb_get_rx_queue(skb) :
smp_processor_id();
while (txq >= f->indices)
txq -= f->indices;
return txq + f->offset;
}
netdev_tx_t ixgbe_xmit_frame_ring(struct sk_buff *skb,
struct ixgbe_adapter *adapter,
struct ixgbe_ring *tx_ring)
{
struct ixgbe_tx_buffer *first;
int tso;
u32 tx_flags = 0;
unsigned short f;
u16 count = TXD_USE_COUNT(skb_headlen(skb));
__be16 protocol = skb->protocol;
u8 hdr_len = 0;
for (f = 0; f < skb_shinfo(skb)->nr_frags; f++)
count += TXD_USE_COUNT(skb_shinfo(skb)->frags[f].size);
if (ixgbe_maybe_stop_tx(tx_ring, count + 3)) {
tx_ring->tx_stats.tx_busy++;
return NETDEV_TX_BUSY;
}
first = &tx_ring->tx_buffer_info[tx_ring->next_to_use];
first->skb = skb;
first->bytecount = skb->len;
first->gso_segs = 1;
if (vlan_tx_tag_present(skb)) {
tx_flags |= vlan_tx_tag_get(skb) << IXGBE_TX_FLAGS_VLAN_SHIFT;
tx_flags |= IXGBE_TX_FLAGS_HW_VLAN;
} else if (protocol == __constant_htons(ETH_P_8021Q)) {
struct vlan_hdr *vhdr, _vhdr;
vhdr = skb_header_pointer(skb, ETH_HLEN, sizeof(_vhdr), &_vhdr);
if (!vhdr)
goto out_drop;
protocol = vhdr->h_vlan_encapsulated_proto;
tx_flags |= ntohs(vhdr->h_vlan_TCI) <<
IXGBE_TX_FLAGS_VLAN_SHIFT;
tx_flags |= IXGBE_TX_FLAGS_SW_VLAN;
}
skb_tx_timestamp(skb);
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
tx_flags |= IXGBE_TX_FLAGS_TSTAMP;
adapter->ptp_tx_skb = skb_get(skb);
adapter->ptp_tx_start = jiffies;
schedule_work(&adapter->ptp_tx_work);
}
#ifdef CONFIG_PCI_IOV
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
tx_flags |= IXGBE_TX_FLAGS_CC;
#endif
if ((adapter->flags & IXGBE_FLAG_DCB_ENABLED) &&
((tx_flags & (IXGBE_TX_FLAGS_HW_VLAN | IXGBE_TX_FLAGS_SW_VLAN)) ||
(skb->priority != TC_PRIO_CONTROL))) {
tx_flags &= ~IXGBE_TX_FLAGS_VLAN_PRIO_MASK;
tx_flags |= (skb->priority & 0x7) <<
IXGBE_TX_FLAGS_VLAN_PRIO_SHIFT;
if (tx_flags & IXGBE_TX_FLAGS_SW_VLAN) {
struct vlan_ethhdr *vhdr;
if (skb_header_cloned(skb) &&
pskb_expand_head(skb, 0, 0, GFP_ATOMIC))
goto out_drop;
vhdr = (struct vlan_ethhdr *)skb->data;
vhdr->h_vlan_TCI = htons(tx_flags >>
IXGBE_TX_FLAGS_VLAN_SHIFT);
} else {
tx_flags |= IXGBE_TX_FLAGS_HW_VLAN;
}
}
first->tx_flags = tx_flags;
first->protocol = protocol;
#ifdef IXGBE_FCOE
if ((protocol == __constant_htons(ETH_P_FCOE)) &&
(tx_ring->netdev->features & (NETIF_F_FSO | NETIF_F_FCOE_CRC))) {
tso = ixgbe_fso(tx_ring, first, &hdr_len);
if (tso < 0)
goto out_drop;
goto xmit_fcoe;
}
#endif
tso = ixgbe_tso(tx_ring, first, &hdr_len);
if (tso < 0)
goto out_drop;
else if (!tso)
ixgbe_tx_csum(tx_ring, first);
if (test_bit(__IXGBE_TX_FDIR_INIT_DONE, &tx_ring->state))
ixgbe_atr(tx_ring, first);
#ifdef IXGBE_FCOE
xmit_fcoe:
#endif
ixgbe_tx_map(tx_ring, first, hdr_len);
ixgbe_maybe_stop_tx(tx_ring, DESC_NEEDED);
return NETDEV_TX_OK;
out_drop:
dev_kfree_skb_any(first->skb);
first->skb = NULL;
return NETDEV_TX_OK;
}
static netdev_tx_t ixgbe_xmit_frame(struct sk_buff *skb,
struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_ring *tx_ring;
if (unlikely(skb->len < 17)) {
if (skb_pad(skb, 17 - skb->len))
return NETDEV_TX_OK;
skb->len = 17;
skb_set_tail_pointer(skb, 17);
}
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
hw->mac.ops.set_rar(hw, 0, hw->mac.addr, VMDQ_P(0), IXGBE_RAH_AV);
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
switch (cmd) {
case SIOCSHWTSTAMP:
return ixgbe_ptp_hwtstamp_ioctl(adapter, req, cmd);
default:
return mdio_mii_ioctl(&adapter->hw.phy.mdio, if_mii(req), cmd);
}
}
static int ixgbe_add_sanmac_netdev(struct net_device *dev)
{
int err = 0;
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct ixgbe_hw *hw = &adapter->hw;
if (is_valid_ether_addr(hw->mac.san_addr)) {
rtnl_lock();
err = dev_addr_add(dev, hw->mac.san_addr, NETDEV_HW_ADDR_T_SAN);
rtnl_unlock();
hw->mac.ops.set_vmdq_san_mac(hw, VMDQ_P(0));
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
for (i = 0; i < adapter->num_q_vectors; i++)
ixgbe_msix_clean_rings(0, adapter->q_vector[i]);
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
static void ixgbe_validate_rtr(struct ixgbe_adapter *adapter, u8 tc)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 reg, rsave;
int i;
if (hw->mac.type == ixgbe_mac_82598EB)
return;
reg = IXGBE_READ_REG(hw, IXGBE_RTRUP2TC);
rsave = reg;
for (i = 0; i < MAX_TRAFFIC_CLASS; i++) {
u8 up2tc = reg >> (i * IXGBE_RTRUP2TC_UP_SHIFT);
if (up2tc > tc)
reg &= ~(0x7 << IXGBE_RTRUP2TC_UP_SHIFT);
}
if (reg != rsave)
IXGBE_WRITE_REG(hw, IXGBE_RTRUP2TC, reg);
return;
}
static void ixgbe_set_prio_tc_map(struct ixgbe_adapter *adapter)
{
struct net_device *dev = adapter->netdev;
struct ixgbe_dcb_config *dcb_cfg = &adapter->dcb_cfg;
struct ieee_ets *ets = adapter->ixgbe_ieee_ets;
u8 prio;
for (prio = 0; prio < MAX_USER_PRIORITY; prio++) {
u8 tc = 0;
if (adapter->dcbx_cap & DCB_CAP_DCBX_VER_CEE)
tc = ixgbe_dcb_get_tc_from_up(dcb_cfg, 0, prio);
else if (ets)
tc = ets->prio_tc[prio];
netdev_set_prio_tc_map(dev, prio, tc);
}
}
int ixgbe_setup_tc(struct net_device *dev, u8 tc)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct ixgbe_hw *hw = &adapter->hw;
if (tc > adapter->dcb_cfg.num_tcs.pg_tcs ||
(hw->mac.type == ixgbe_mac_82598EB &&
tc < MAX_TRAFFIC_CLASS))
return -EINVAL;
if (netif_running(dev))
ixgbe_close(dev);
ixgbe_clear_interrupt_scheme(adapter);
#ifdef CONFIG_IXGBE_DCB
if (tc) {
netdev_set_num_tc(dev, tc);
ixgbe_set_prio_tc_map(adapter);
adapter->flags |= IXGBE_FLAG_DCB_ENABLED;
if (adapter->hw.mac.type == ixgbe_mac_82598EB) {
adapter->last_lfc_mode = adapter->hw.fc.requested_mode;
adapter->hw.fc.requested_mode = ixgbe_fc_none;
}
} else {
netdev_reset_tc(dev);
if (adapter->hw.mac.type == ixgbe_mac_82598EB)
adapter->hw.fc.requested_mode = adapter->last_lfc_mode;
adapter->flags &= ~IXGBE_FLAG_DCB_ENABLED;
adapter->temp_dcb_cfg.pfc_mode_enable = false;
adapter->dcb_cfg.pfc_mode_enable = false;
}
ixgbe_validate_rtr(adapter, tc);
#endif
ixgbe_init_interrupt_scheme(adapter);
if (netif_running(dev))
return ixgbe_open(dev);
return 0;
}
void ixgbe_sriov_reinit(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
rtnl_lock();
ixgbe_setup_tc(netdev, netdev_get_num_tc(netdev));
rtnl_unlock();
}
void ixgbe_do_reset(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (netif_running(netdev))
ixgbe_reinit_locked(adapter);
else
ixgbe_reset(adapter);
}
static netdev_features_t ixgbe_fix_features(struct net_device *netdev,
netdev_features_t features)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (!(features & NETIF_F_RXCSUM))
features &= ~NETIF_F_LRO;
if (!(adapter->flags2 & IXGBE_FLAG2_RSC_CAPABLE))
features &= ~NETIF_F_LRO;
return features;
}
static int ixgbe_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
netdev_features_t changed = netdev->features ^ features;
bool need_reset = false;
if (!(features & NETIF_F_LRO)) {
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)
need_reset = true;
adapter->flags2 &= ~IXGBE_FLAG2_RSC_ENABLED;
} else if ((adapter->flags2 & IXGBE_FLAG2_RSC_CAPABLE) &&
!(adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)) {
if (adapter->rx_itr_setting == 1 ||
adapter->rx_itr_setting > IXGBE_MIN_RSC_ITR) {
adapter->flags2 |= IXGBE_FLAG2_RSC_ENABLED;
need_reset = true;
} else if ((changed ^ features) & NETIF_F_LRO) {
e_info(probe, "rx-usecs set too low, "
"disabling RSC\n");
}
}
switch (features & NETIF_F_NTUPLE) {
case NETIF_F_NTUPLE:
if (!(adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE))
need_reset = true;
adapter->flags &= ~IXGBE_FLAG_FDIR_HASH_CAPABLE;
adapter->flags |= IXGBE_FLAG_FDIR_PERFECT_CAPABLE;
break;
default:
if (adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE)
need_reset = true;
adapter->flags &= ~IXGBE_FLAG_FDIR_PERFECT_CAPABLE;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
break;
if (netdev_get_num_tc(netdev) > 1)
break;
if (adapter->ring_feature[RING_F_RSS].limit <= 1)
break;
if (!adapter->atr_sample_rate)
break;
adapter->flags |= IXGBE_FLAG_FDIR_HASH_CAPABLE;
break;
}
if (features & NETIF_F_HW_VLAN_CTAG_RX)
ixgbe_vlan_strip_enable(adapter);
else
ixgbe_vlan_strip_disable(adapter);
if (changed & NETIF_F_RXALL)
need_reset = true;
netdev->features = features;
if (need_reset)
ixgbe_do_reset(netdev);
return 0;
}
static int ixgbe_ndo_fdb_add(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev,
const unsigned char *addr,
u16 flags)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
int err;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return ndo_dflt_fdb_add(ndm, tb, dev, addr, flags);
if (ndm->ndm_state && !(ndm->ndm_state & NUD_PERMANENT)) {
pr_info("%s: FDB only supports static addresses\n",
ixgbe_driver_name);
return -EINVAL;
}
if (is_unicast_ether_addr(addr) || is_link_local_ether_addr(addr)) {
u32 rar_uc_entries = IXGBE_MAX_PF_MACVLANS;
if (netdev_uc_count(dev) < rar_uc_entries)
err = dev_uc_add_excl(dev, addr);
else
err = -ENOMEM;
} else if (is_multicast_ether_addr(addr)) {
err = dev_mc_add_excl(dev, addr);
} else {
err = -EINVAL;
}
if (err == -EEXIST && !(flags & NLM_F_EXCL))
err = 0;
return err;
}
static int ixgbe_ndo_bridge_setlink(struct net_device *dev,
struct nlmsghdr *nlh)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct nlattr *attr, *br_spec;
int rem;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return -EOPNOTSUPP;
br_spec = nlmsg_find_attr(nlh, sizeof(struct ifinfomsg), IFLA_AF_SPEC);
nla_for_each_nested(attr, br_spec, rem) {
__u16 mode;
u32 reg = 0;
if (nla_type(attr) != IFLA_BRIDGE_MODE)
continue;
mode = nla_get_u16(attr);
if (mode == BRIDGE_MODE_VEPA) {
reg = 0;
adapter->flags2 &= ~IXGBE_FLAG2_BRIDGE_MODE_VEB;
} else if (mode == BRIDGE_MODE_VEB) {
reg = IXGBE_PFDTXGSWC_VT_LBEN;
adapter->flags2 |= IXGBE_FLAG2_BRIDGE_MODE_VEB;
} else
return -EINVAL;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_PFDTXGSWC, reg);
e_info(drv, "enabling bridge mode: %s\n",
mode == BRIDGE_MODE_VEPA ? "VEPA" : "VEB");
}
return 0;
}
static int ixgbe_ndo_bridge_getlink(struct sk_buff *skb, u32 pid, u32 seq,
struct net_device *dev,
u32 filter_mask)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
u16 mode;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return 0;
if (adapter->flags2 & IXGBE_FLAG2_BRIDGE_MODE_VEB)
mode = BRIDGE_MODE_VEB;
else
mode = BRIDGE_MODE_VEPA;
return ndo_dflt_bridge_getlink(skb, pid, seq, dev, mode);
}
static inline int ixgbe_enumerate_functions(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct list_head *entry;
int physfns = 0;
switch (hw->device_id) {
case IXGBE_DEV_ID_82599_SFP_SF_QP:
case IXGBE_DEV_ID_82599_QSFP_SF_QP:
physfns = 4;
break;
default:
list_for_each(entry, &adapter->pdev->bus_list) {
struct pci_dev *pdev =
list_entry(entry, struct pci_dev, bus_list);
if (!pdev->is_virtfn)
physfns++;
}
}
return physfns;
}
int ixgbe_wol_supported(struct ixgbe_adapter *adapter, u16 device_id,
u16 subdevice_id)
{
struct ixgbe_hw *hw = &adapter->hw;
u16 wol_cap = adapter->eeprom_cap & IXGBE_DEVICE_CAPS_WOL_MASK;
int is_wol_supported = 0;
switch (device_id) {
case IXGBE_DEV_ID_82599_SFP:
switch (subdevice_id) {
case IXGBE_SUBDEV_ID_82599_560FLR:
if (hw->bus.func != 0)
break;
case IXGBE_SUBDEV_ID_82599_SP_560FLR:
case IXGBE_SUBDEV_ID_82599_SFP:
case IXGBE_SUBDEV_ID_82599_RNDC:
case IXGBE_SUBDEV_ID_82599_ECNA_DP:
case IXGBE_SUBDEV_ID_82599_LOM_SFP:
is_wol_supported = 1;
break;
}
break;
case IXGBE_DEV_ID_82599EN_SFP:
switch (subdevice_id) {
case IXGBE_SUBDEV_ID_82599EN_SFP_OCP1:
is_wol_supported = 1;
break;
}
break;
case IXGBE_DEV_ID_82599_COMBO_BACKPLANE:
if (subdevice_id != IXGBE_SUBDEV_ID_82599_KX4_KR_MEZZ)
is_wol_supported = 1;
break;
case IXGBE_DEV_ID_82599_KX4:
is_wol_supported = 1;
break;
case IXGBE_DEV_ID_X540T:
case IXGBE_DEV_ID_X540T1:
if ((wol_cap == IXGBE_DEVICE_CAPS_WOL_PORT0_1) ||
((wol_cap == IXGBE_DEVICE_CAPS_WOL_PORT0) &&
(hw->bus.func == 0))) {
is_wol_supported = 1;
}
break;
}
return is_wol_supported;
}
static int ixgbe_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev;
struct ixgbe_adapter *adapter = NULL;
struct ixgbe_hw *hw;
const struct ixgbe_info *ii = ixgbe_info_tbl[ent->driver_data];
static int cards_found;
int i, err, pci_using_dac, expected_gts;
unsigned int indices = MAX_TX_QUEUES;
u8 part_str[IXGBE_PBANUM_LENGTH];
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
if (ii->mac == ixgbe_mac_82598EB) {
#ifdef CONFIG_IXGBE_DCB
indices = 4 * MAX_TRAFFIC_CLASS;
#else
indices = IXGBE_MAX_RSS_INDICES;
#endif
}
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
adapter->msg_enable = netif_msg_init(debug, DEFAULT_MSG_ENABLE);
hw->hw_addr = ioremap(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
if (!hw->hw_addr) {
err = -EIO;
goto err_ioremap;
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
if (hw->mac.ops.mng_fw_enabled)
hw->mng_fw_enabled = hw->mac.ops.mng_fw_enabled(hw);
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
if (allow_unsupported_sfp)
hw->allow_unsupported_sfp = allow_unsupported_sfp;
hw->phy.reset_if_overtemp = true;
err = hw->mac.ops.reset_hw(hw);
hw->phy.reset_if_overtemp = false;
if (err == IXGBE_ERR_SFP_NOT_PRESENT &&
hw->mac.type == ixgbe_mac_82598EB) {
err = 0;
} else if (err == IXGBE_ERR_SFP_NOT_SUPPORTED) {
e_dev_err("failed to load because an unsupported SFP+ or QSFP module type was detected.\n");
e_dev_err("Reload the driver after installing a supported module.\n");
goto err_sw_init;
} else if (err) {
e_dev_err("HW Init failed: %d\n", err);
goto err_sw_init;
}
#ifdef CONFIG_PCI_IOV
if (adapter->hw.mac.type == ixgbe_mac_82598EB)
goto skip_sriov;
ixgbe_init_mbx_params_pf(hw);
memcpy(&hw->mbx.ops, ii->mbx_ops, sizeof(hw->mbx.ops));
ixgbe_enable_sriov(adapter);
pci_sriov_set_totalvfs(pdev, 63);
skip_sriov:
#endif
netdev->features = NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_FILTER |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_RXHASH |
NETIF_F_RXCSUM;
netdev->hw_features = netdev->features;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
netdev->features |= NETIF_F_SCTP_CSUM;
netdev->hw_features |= NETIF_F_SCTP_CSUM |
NETIF_F_NTUPLE;
break;
default:
break;
}
netdev->hw_features |= NETIF_F_RXALL;
netdev->vlan_features |= NETIF_F_TSO;
netdev->vlan_features |= NETIF_F_TSO6;
netdev->vlan_features |= NETIF_F_IP_CSUM;
netdev->vlan_features |= NETIF_F_IPV6_CSUM;
netdev->vlan_features |= NETIF_F_SG;
netdev->priv_flags |= IFF_UNICAST_FLT;
netdev->priv_flags |= IFF_SUPP_NOFCS;
#ifdef CONFIG_IXGBE_DCB
netdev->dcbnl_ops = &dcbnl_ops;
#endif
#ifdef IXGBE_FCOE
if (adapter->flags & IXGBE_FLAG_FCOE_CAPABLE) {
unsigned int fcoe_l;
if (hw->mac.ops.get_device_caps) {
hw->mac.ops.get_device_caps(hw, &device_caps);
if (device_caps & IXGBE_DEVICE_CAPS_FCOE_OFFLOADS)
adapter->flags &= ~IXGBE_FLAG_FCOE_CAPABLE;
}
fcoe_l = min_t(int, IXGBE_FCRETA_SIZE, num_online_cpus());
adapter->ring_feature[RING_F_FCOE].limit = fcoe_l;
netdev->features |= NETIF_F_FSO |
NETIF_F_FCOE_CRC;
netdev->vlan_features |= NETIF_F_FSO |
NETIF_F_FCOE_CRC |
NETIF_F_FCOE_MTU;
}
#endif
if (pci_using_dac) {
netdev->features |= NETIF_F_HIGHDMA;
netdev->vlan_features |= NETIF_F_HIGHDMA;
}
if (adapter->flags2 & IXGBE_FLAG2_RSC_CAPABLE)
netdev->hw_features |= NETIF_F_LRO;
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)
netdev->features |= NETIF_F_LRO;
if (hw->eeprom.ops.validate_checksum(hw, NULL) < 0) {
e_dev_err("The EEPROM Checksum Is Not Valid\n");
err = -EIO;
goto err_sw_init;
}
memcpy(netdev->dev_addr, hw->mac.perm_addr, netdev->addr_len);
if (!is_valid_ether_addr(netdev->dev_addr)) {
e_dev_err("invalid MAC address\n");
err = -EIO;
goto err_sw_init;
}
setup_timer(&adapter->service_timer, &ixgbe_service_timer,
(unsigned long) adapter);
INIT_WORK(&adapter->service_task, ixgbe_service_task);
clear_bit(__IXGBE_SERVICE_SCHED, &adapter->state);
err = ixgbe_init_interrupt_scheme(adapter);
if (err)
goto err_sw_init;
adapter->wol = 0;
hw->eeprom.ops.read(hw, 0x2c, &adapter->eeprom_cap);
hw->wol_enabled = ixgbe_wol_supported(adapter, pdev->device,
pdev->subsystem_device);
if (hw->wol_enabled)
adapter->wol = IXGBE_WUFC_MAG;
device_set_wakeup_enable(&adapter->pdev->dev, adapter->wol);
hw->eeprom.ops.read(hw, 0x2e, &adapter->eeprom_verh);
hw->eeprom.ops.read(hw, 0x2d, &adapter->eeprom_verl);
hw->mac.ops.get_bus_info(hw);
if (ixgbe_pcie_from_parent(hw))
ixgbe_get_parent_bus_info(adapter);
e_dev_info("(PCI Express:%s:%s) %pM\n",
(hw->bus.speed == ixgbe_bus_speed_8000 ? "8.0GT/s" :
hw->bus.speed == ixgbe_bus_speed_5000 ? "5.0GT/s" :
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
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
expected_gts = min(ixgbe_enumerate_functions(adapter) * 10, 16);
break;
default:
expected_gts = ixgbe_enumerate_functions(adapter) * 10;
break;
}
ixgbe_check_minimum_link(adapter, expected_gts);
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
if (hw->mac.ops.disable_tx_laser)
hw->mac.ops.disable_tx_laser(hw);
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
if (hw->mac.ops.set_fw_drv_ver)
hw->mac.ops.set_fw_drv_ver(hw, 0xFF, 0xFF, 0xFF,
0xFF);
ixgbe_add_sanmac_netdev(netdev);
e_dev_info("%s\n", ixgbe_default_device_descr);
cards_found++;
#ifdef CONFIG_IXGBE_HWMON
if (ixgbe_sysfs_init(adapter))
e_err(probe, "failed to allocate sysfs resources\n");
#endif
ixgbe_dbg_adapter_init(adapter);
if (hw->mng_fw_enabled && hw->mac.ops.setup_link)
hw->mac.ops.setup_link(hw,
IXGBE_LINK_SPEED_10GB_FULL | IXGBE_LINK_SPEED_1GB_FULL,
true);
return 0;
err_register:
ixgbe_release_hw_control(adapter);
ixgbe_clear_interrupt_scheme(adapter);
err_sw_init:
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
static void ixgbe_remove(struct pci_dev *pdev)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
ixgbe_dbg_adapter_exit(adapter);
set_bit(__IXGBE_DOWN, &adapter->state);
cancel_work_sync(&adapter->service_task);
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED) {
adapter->flags &= ~IXGBE_FLAG_DCA_ENABLED;
dca_remove_requester(&pdev->dev);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL, 1);
}
#endif
#ifdef CONFIG_IXGBE_HWMON
ixgbe_sysfs_exit(adapter);
#endif
ixgbe_del_sanmac_netdev(netdev);
if (netdev->reg_state == NETREG_REGISTERED)
unregister_netdev(netdev);
#ifdef CONFIG_PCI_IOV
if (max_vfs)
ixgbe_disable_sriov(adapter);
#endif
ixgbe_clear_interrupt_scheme(adapter);
ixgbe_release_hw_control(adapter);
#ifdef CONFIG_DCB
kfree(adapter->ixgbe_ieee_pfc);
kfree(adapter->ixgbe_ieee_ets);
#endif
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
#ifdef CONFIG_PCI_IOV
struct pci_dev *bdev, *vfdev;
u32 dw0, dw1, dw2, dw3;
int vf, pos;
u16 req_id, pf_func;
if (adapter->hw.mac.type == ixgbe_mac_82598EB ||
adapter->num_vfs == 0)
goto skip_bad_vf_detection;
bdev = pdev->bus->self;
while (bdev && (pci_pcie_type(bdev) != PCI_EXP_TYPE_ROOT_PORT))
bdev = bdev->bus->self;
if (!bdev)
goto skip_bad_vf_detection;
pos = pci_find_ext_capability(bdev, PCI_EXT_CAP_ID_ERR);
if (!pos)
goto skip_bad_vf_detection;
pci_read_config_dword(bdev, pos + PCI_ERR_HEADER_LOG, &dw0);
pci_read_config_dword(bdev, pos + PCI_ERR_HEADER_LOG + 4, &dw1);
pci_read_config_dword(bdev, pos + PCI_ERR_HEADER_LOG + 8, &dw2);
pci_read_config_dword(bdev, pos + PCI_ERR_HEADER_LOG + 12, &dw3);
req_id = dw1 >> 16;
if (!(req_id & 0x0080))
goto skip_bad_vf_detection;
pf_func = req_id & 0x01;
if ((pf_func & 1) == (pdev->devfn & 1)) {
unsigned int device_id;
vf = (req_id & 0x7F) >> 1;
e_dev_err("VF %d has caused a PCIe error\n", vf);
e_dev_err("TLP: dw0: %8.8x\tdw1: %8.8x\tdw2: "
"%8.8x\tdw3: %8.8x\n",
dw0, dw1, dw2, dw3);
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
device_id = IXGBE_82599_VF_DEVICE_ID;
break;
case ixgbe_mac_X540:
device_id = IXGBE_X540_VF_DEVICE_ID;
break;
default:
device_id = 0;
break;
}
vfdev = pci_get_device(PCI_VENDOR_ID_INTEL, device_id, NULL);
while (vfdev) {
if (vfdev->devfn == (req_id & 0xFF))
break;
vfdev = pci_get_device(PCI_VENDOR_ID_INTEL,
device_id, vfdev);
}
if (vfdev) {
e_dev_err("Issuing VFLR to VF %d\n", vf);
pci_write_config_dword(vfdev, 0xA8, 0x00008000);
pci_dev_put(vfdev);
}
pci_cleanup_aer_uncorrect_error_status(pdev);
}
adapter->vferr_refcount++;
return PCI_ERS_RESULT_RECOVERED;
skip_bad_vf_detection:
#endif
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
#ifdef CONFIG_PCI_IOV
if (adapter->vferr_refcount) {
e_info(drv, "Resuming after VF err\n");
adapter->vferr_refcount--;
return;
}
#endif
if (netif_running(netdev))
ixgbe_up(adapter);
netif_device_attach(netdev);
}
static int __init ixgbe_init_module(void)
{
int ret;
pr_info("%s - version %s\n", ixgbe_driver_string, ixgbe_driver_version);
pr_info("%s\n", ixgbe_copyright);
ixgbe_dbg_init();
ret = pci_register_driver(&ixgbe_driver);
if (ret) {
ixgbe_dbg_exit();
return ret;
}
#ifdef CONFIG_IXGBE_DCA
dca_register_notify(&dca_notifier);
#endif
return 0;
}
static void __exit ixgbe_exit_module(void)
{
#ifdef CONFIG_IXGBE_DCA
dca_unregister_notify(&dca_notifier);
#endif
pci_unregister_driver(&ixgbe_driver);
ixgbe_dbg_exit();
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
