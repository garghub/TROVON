static int ixgbe_read_pci_cfg_word_parent(struct ixgbe_adapter *adapter,
u32 reg, u16 *value)
{
struct pci_dev *parent_dev;
struct pci_bus *parent_bus;
parent_bus = adapter->pdev->bus->parent;
if (!parent_bus)
return -1;
parent_dev = parent_bus->self;
if (!parent_dev)
return -1;
if (!pci_is_pcie(parent_dev))
return -1;
pcie_capability_read_word(parent_dev, reg, value);
if (*value == IXGBE_FAILED_READ_CFG_WORD &&
ixgbe_check_cfg_remove(&adapter->hw, parent_dev))
return -1;
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
struct ixgbe_hw *hw = &adapter->hw;
int max_gts = 0;
enum pci_bus_speed speed = PCI_SPEED_UNKNOWN;
enum pcie_link_width width = PCIE_LNK_WIDTH_UNKNOWN;
struct pci_dev *pdev;
if (hw->bus.type == ixgbe_bus_type_internal)
return;
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
speed == PCIE_SPEED_8_0GT ? "<2%" :
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
!test_bit(__IXGBE_REMOVING, &adapter->state) &&
!test_and_set_bit(__IXGBE_SERVICE_SCHED, &adapter->state))
queue_work(ixgbe_wq, &adapter->service_task);
}
static void ixgbe_remove_adapter(struct ixgbe_hw *hw)
{
struct ixgbe_adapter *adapter = hw->back;
if (!hw->hw_addr)
return;
hw->hw_addr = NULL;
e_dev_err("Adapter removed\n");
if (test_bit(__IXGBE_SERVICE_INITED, &adapter->state))
ixgbe_service_event_schedule(adapter);
}
static void ixgbe_check_remove(struct ixgbe_hw *hw, u32 reg)
{
u32 value;
if (reg == IXGBE_STATUS) {
ixgbe_remove_adapter(hw);
return;
}
value = ixgbe_read_reg(hw, IXGBE_STATUS);
if (value == IXGBE_FAILED_READ_REG)
ixgbe_remove_adapter(hw);
}
u32 ixgbe_read_reg(struct ixgbe_hw *hw, u32 reg)
{
u8 __iomem *reg_addr = ACCESS_ONCE(hw->hw_addr);
u32 value;
if (ixgbe_removed(reg_addr))
return IXGBE_FAILED_READ_REG;
if (unlikely(hw->phy.nw_mng_if_sel &
IXGBE_NW_MNG_IF_SEL_ENABLE_10_100M)) {
struct ixgbe_adapter *adapter;
int i;
for (i = 0; i < 200; ++i) {
value = readl(reg_addr + IXGBE_MAC_SGMII_BUSY);
if (likely(!value))
goto writes_completed;
if (value == IXGBE_FAILED_READ_REG) {
ixgbe_remove_adapter(hw);
return IXGBE_FAILED_READ_REG;
}
udelay(5);
}
adapter = hw->back;
e_warn(hw, "register writes incomplete %08x\n", value);
}
writes_completed:
value = readl(reg_addr + reg);
if (unlikely(value == IXGBE_FAILED_READ_REG))
ixgbe_check_remove(hw, reg);
return value;
}
static bool ixgbe_check_cfg_remove(struct ixgbe_hw *hw, struct pci_dev *pdev)
{
u16 value;
pci_read_config_word(pdev, PCI_VENDOR_ID, &value);
if (value == IXGBE_FAILED_READ_CFG_WORD) {
ixgbe_remove_adapter(hw);
return true;
}
return false;
}
u16 ixgbe_read_pci_cfg_word(struct ixgbe_hw *hw, u32 reg)
{
struct ixgbe_adapter *adapter = hw->back;
u16 value;
if (ixgbe_removed(hw->hw_addr))
return IXGBE_FAILED_READ_CFG_WORD;
pci_read_config_word(adapter->pdev, reg, &value);
if (value == IXGBE_FAILED_READ_CFG_WORD &&
ixgbe_check_cfg_remove(hw, adapter->pdev))
return IXGBE_FAILED_READ_CFG_WORD;
return value;
}
static u32 ixgbe_read_pci_cfg_dword(struct ixgbe_hw *hw, u32 reg)
{
struct ixgbe_adapter *adapter = hw->back;
u32 value;
if (ixgbe_removed(hw->hw_addr))
return IXGBE_FAILED_READ_CFG_DWORD;
pci_read_config_dword(adapter->pdev, reg, &value);
if (value == IXGBE_FAILED_READ_CFG_DWORD &&
ixgbe_check_cfg_remove(hw, adapter->pdev))
return IXGBE_FAILED_READ_CFG_DWORD;
return value;
}
void ixgbe_write_pci_cfg_word(struct ixgbe_hw *hw, u32 reg, u16 value)
{
struct ixgbe_adapter *adapter = hw->back;
if (ixgbe_removed(hw->hw_addr))
return;
pci_write_config_word(adapter->pdev, reg, value);
}
static void ixgbe_service_event_complete(struct ixgbe_adapter *adapter)
{
BUG_ON(!test_bit(__IXGBE_SERVICE_SCHED, &adapter->state));
smp_mb__before_atomic();
clear_bit(__IXGBE_SERVICE_SCHED, &adapter->state);
}
static void ixgbe_regdump(struct ixgbe_hw *hw, struct ixgbe_reg_info *reginfo)
{
int i;
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
pr_info("%-15s %08x\n",
reginfo->name, IXGBE_READ_REG(hw, reginfo->ofs));
return;
}
i = 0;
while (i < 64) {
int j;
char buf[9 * 8 + 1];
char *p = buf;
snprintf(rname, 16, "%s[%d-%d]", reginfo->name, i, i + 7);
for (j = 0; j < 8; j++)
p += sprintf(p, " %08x", regs[i++]);
pr_err("%-15s%s\n", rname, buf);
}
}
static void ixgbe_print_buffer(struct ixgbe_ring *ring, int n)
{
struct ixgbe_tx_buffer *tx_buffer;
tx_buffer = &ring->tx_buffer_info[ring->next_to_clean];
pr_info(" %5d %5X %5X %016llX %08X %p %016llX\n",
n, ring->next_to_use, ring->next_to_clean,
(u64)dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
tx_buffer->next_to_watch,
(u64)tx_buffer->time_stamp);
}
static void ixgbe_dump(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_reg_info *reginfo;
int n = 0;
struct ixgbe_ring *ring;
struct ixgbe_tx_buffer *tx_buffer;
union ixgbe_adv_tx_desc *tx_desc;
struct my_u0 { u64 a; u64 b; } *u0;
struct ixgbe_ring *rx_ring;
union ixgbe_adv_rx_desc *rx_desc;
struct ixgbe_rx_buffer *rx_buffer_info;
int i = 0;
if (!netif_msg_hw(adapter))
return;
if (netdev) {
dev_info(&adapter->pdev->dev, "Net device Info\n");
pr_info("Device Name state "
"trans_start\n");
pr_info("%-15s %016lX %016lX\n",
netdev->name,
netdev->state,
dev_trans_start(netdev));
}
dev_info(&adapter->pdev->dev, "Register Dump\n");
pr_info(" Register Name Value\n");
for (reginfo = (struct ixgbe_reg_info *)ixgbe_reg_info_tbl;
reginfo->name; reginfo++) {
ixgbe_regdump(hw, reginfo);
}
if (!netdev || !netif_running(netdev))
return;
dev_info(&adapter->pdev->dev, "TX Rings Summary\n");
pr_info(" %s %s %s %s\n",
"Queue [NTU] [NTC] [bi(ntc)->dma ]",
"leng", "ntw", "timestamp");
for (n = 0; n < adapter->num_tx_queues; n++) {
ring = adapter->tx_ring[n];
ixgbe_print_buffer(ring, n);
}
for (n = 0; n < adapter->num_xdp_queues; n++) {
ring = adapter->xdp_ring[n];
ixgbe_print_buffer(ring, n);
}
if (!netif_msg_tx_done(adapter))
goto rx_ring_summary;
dev_info(&adapter->pdev->dev, "TX Rings Dump\n");
for (n = 0; n < adapter->num_tx_queues; n++) {
ring = adapter->tx_ring[n];
pr_info("------------------------------------\n");
pr_info("TX QUEUE INDEX = %d\n", ring->queue_index);
pr_info("------------------------------------\n");
pr_info("%s%s %s %s %s %s\n",
"T [desc] [address 63:0 ] ",
"[PlPOIdStDDt Ln] [bi->dma ] ",
"leng", "ntw", "timestamp", "bi->skb");
for (i = 0; ring->desc && (i < ring->count); i++) {
tx_desc = IXGBE_TX_DESC(ring, i);
tx_buffer = &ring->tx_buffer_info[i];
u0 = (struct my_u0 *)tx_desc;
if (dma_unmap_len(tx_buffer, len) > 0) {
const char *ring_desc;
if (i == ring->next_to_use &&
i == ring->next_to_clean)
ring_desc = " NTC/U";
else if (i == ring->next_to_use)
ring_desc = " NTU";
else if (i == ring->next_to_clean)
ring_desc = " NTC";
else
ring_desc = "";
pr_info("T [0x%03X] %016llX %016llX %016llX %08X %p %016llX %p%s",
i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
(u64)dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
tx_buffer->next_to_watch,
(u64)tx_buffer->time_stamp,
tx_buffer->skb,
ring_desc);
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
return;
dev_info(&adapter->pdev->dev, "RX Rings Dump\n");
for (n = 0; n < adapter->num_rx_queues; n++) {
rx_ring = adapter->rx_ring[n];
pr_info("------------------------------------\n");
pr_info("RX QUEUE INDEX = %d\n", rx_ring->queue_index);
pr_info("------------------------------------\n");
pr_info("%s%s%s\n",
"R [desc] [ PktBuf A0] ",
"[ HeadBuf DD] [bi->dma ] [bi->skb ] ",
"<-- Adv Rx Read format");
pr_info("%s%s%s\n",
"RWB[desc] [PcsmIpSHl PtRs] ",
"[vl er S cks ln] ---------------- [bi->skb ] ",
"<-- Adv Rx Write-Back format");
for (i = 0; i < rx_ring->count; i++) {
const char *ring_desc;
if (i == rx_ring->next_to_use)
ring_desc = " NTU";
else if (i == rx_ring->next_to_clean)
ring_desc = " NTC";
else
ring_desc = "";
rx_buffer_info = &rx_ring->rx_buffer_info[i];
rx_desc = IXGBE_RX_DESC(rx_ring, i);
u0 = (struct my_u0 *)rx_desc;
if (rx_desc->wb.upper.length) {
pr_info("RWB[0x%03X] %016llX %016llX ---------------- %p%s\n",
i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
rx_buffer_info->skb,
ring_desc);
} else {
pr_info("R [0x%03X] %016llX %016llX %016llX %p%s\n",
i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
(u64)rx_buffer_info->dma,
rx_buffer_info->skb,
ring_desc);
if (netif_msg_pktdata(adapter) &&
rx_buffer_info->dma) {
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS, 16, 1,
page_address(rx_buffer_info->page) +
rx_buffer_info->page_offset,
ixgbe_rx_bufsz(rx_ring), true);
}
}
}
}
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
mask = (qmask & 0xFFFFFFFF);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EICS_EX(0), mask);
mask = (qmask >> 32);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EICS_EX(1), mask);
break;
default:
break;
}
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
for (i = 0; i < adapter->num_xdp_queues; i++)
clear_bit(__IXGBE_HANG_CHECK_ARMED,
&adapter->xdp_ring[i]->state);
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
for (i = 0; i < adapter->num_xdp_queues; i++) {
struct ixgbe_ring *xdp_ring = adapter->xdp_ring[i];
tc = xdp_ring->dcb_tc;
if (xoff[tc])
clear_bit(__IXGBE_HANG_CHECK_ARMED, &xdp_ring->state);
}
}
static u64 ixgbe_get_tx_completed(struct ixgbe_ring *ring)
{
return ring->stats.packets;
}
static u64 ixgbe_get_tx_pending(struct ixgbe_ring *ring)
{
struct ixgbe_adapter *adapter;
struct ixgbe_hw *hw;
u32 head, tail;
if (ring->l2_accel_priv)
adapter = ring->l2_accel_priv->real_adapter;
else
adapter = netdev_priv(ring->netdev);
hw = &adapter->hw;
head = IXGBE_READ_REG(hw, IXGBE_TDH(ring->reg_idx));
tail = IXGBE_READ_REG(hw, IXGBE_TDT(ring->reg_idx));
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
clear_check_for_tx_hang(tx_ring);
if (tx_done_old == tx_done && tx_pending)
return test_and_set_bit(__IXGBE_HANG_CHECK_ARMED,
&tx_ring->state);
tx_ring->tx_stats.tx_done_old = tx_done;
clear_bit(__IXGBE_HANG_CHECK_ARMED, &tx_ring->state);
return false;
}
static void ixgbe_tx_timeout_reset(struct ixgbe_adapter *adapter)
{
if (!test_bit(__IXGBE_DOWN, &adapter->state)) {
set_bit(__IXGBE_RESET_REQUESTED, &adapter->state);
e_warn(drv, "initiating reset due to tx timeout\n");
ixgbe_service_event_schedule(adapter);
}
}
static int ixgbe_tx_maxrate(struct net_device *netdev,
int queue_index, u32 maxrate)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
u32 bcnrc_val = ixgbe_link_mbps(adapter);
if (!maxrate)
return 0;
bcnrc_val <<= IXGBE_RTTBCNRC_RF_INT_SHIFT;
bcnrc_val /= maxrate;
bcnrc_val &= IXGBE_RTTBCNRC_RF_INT_MASK |
IXGBE_RTTBCNRC_RF_DEC_MASK;
bcnrc_val |= IXGBE_RTTBCNRC_RS_ENA;
IXGBE_WRITE_REG(hw, IXGBE_RTTDQSEL, queue_index);
IXGBE_WRITE_REG(hw, IXGBE_RTTBCNRC, bcnrc_val);
return 0;
}
static bool ixgbe_clean_tx_irq(struct ixgbe_q_vector *q_vector,
struct ixgbe_ring *tx_ring, int napi_budget)
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
if (ring_is_xdp(tx_ring))
page_frag_free(tx_buffer->data);
else
napi_consume_skb(tx_buffer->skb, napi_budget);
dma_unmap_single(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
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
e_err(drv, "Detected Tx Unit Hang %s\n"
" Tx Queue <%d>\n"
" TDH, TDT <%x>, <%x>\n"
" next_to_use <%x>\n"
" next_to_clean <%x>\n"
"tx_buffer_info[next_to_clean]\n"
" time_stamp <%lx>\n"
" jiffies <%lx>\n",
ring_is_xdp(tx_ring) ? "(XDP)" : "",
tx_ring->queue_index,
IXGBE_READ_REG(hw, IXGBE_TDH(tx_ring->reg_idx)),
IXGBE_READ_REG(hw, IXGBE_TDT(tx_ring->reg_idx)),
tx_ring->next_to_use, i,
tx_ring->tx_buffer_info[i].time_stamp, jiffies);
if (!ring_is_xdp(tx_ring))
netif_stop_subqueue(tx_ring->netdev,
tx_ring->queue_index);
e_info(probe,
"tx hang %d detected on queue %d, resetting adapter\n",
adapter->tx_timeout_count + 1, tx_ring->queue_index);
ixgbe_tx_timeout_reset(adapter);
return true;
}
if (ring_is_xdp(tx_ring))
return !!budget;
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
u32 txctrl = 0;
u16 reg_offset;
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
txctrl = dca3_get_tag(tx_ring->dev, cpu);
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
u32 rxctrl = 0;
u8 reg_idx = rx_ring->reg_idx;
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
rxctrl = dca3_get_tag(rx_ring->dev, cpu);
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
rxctrl <<= IXGBE_DCA_RXCTRL_CPUID_SHIFT_82599;
break;
default:
break;
}
rxctrl |= IXGBE_DCA_RXCTRL_DESC_RRO_EN |
IXGBE_DCA_RXCTRL_DATA_DCA_EN |
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
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL,
IXGBE_DCA_CTRL_DCA_MODE_CB2);
else
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL,
IXGBE_DCA_CTRL_DCA_DISABLE);
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
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL,
IXGBE_DCA_CTRL_DCA_MODE_CB2);
break;
}
case DCA_PROVIDER_REMOVE:
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED) {
dca_remove_requester(dev);
adapter->flags &= ~IXGBE_FLAG_DCA_ENABLED;
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL,
IXGBE_DCA_CTRL_DCA_DISABLE);
}
break;
}
return 0;
}
static inline void ixgbe_rx_hash(struct ixgbe_ring *ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
u16 rss_type;
if (!(ring->netdev->features & NETIF_F_RXHASH))
return;
rss_type = le16_to_cpu(rx_desc->wb.lower.lo_dword.hs_rss.pkt_info) &
IXGBE_RXDADV_RSSTYPE_MASK;
if (!rss_type)
return;
skb_set_hash(skb, le32_to_cpu(rx_desc->wb.lower.hi_dword.rss),
(IXGBE_RSS_L4_TYPES_MASK & (1ul << rss_type)) ?
PKT_HASH_TYPE_L4 : PKT_HASH_TYPE_L3);
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
__le16 pkt_info = rx_desc->wb.lower.lo_dword.hs_rss.pkt_info;
bool encap_pkt = false;
skb_checksum_none_assert(skb);
if (!(ring->netdev->features & NETIF_F_RXCSUM))
return;
if (pkt_info & cpu_to_le16(IXGBE_RXDADV_PKTTYPE_VXLAN)) {
encap_pkt = true;
skb->encapsulation = 1;
}
if (ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_IPCS) &&
ixgbe_test_staterr(rx_desc, IXGBE_RXDADV_ERR_IPE)) {
ring->rx_stats.csum_err++;
return;
}
if (!ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_L4CS))
return;
if (ixgbe_test_staterr(rx_desc, IXGBE_RXDADV_ERR_TCPE)) {
if ((pkt_info & cpu_to_le16(IXGBE_RXDADV_PKTTYPE_UDP)) &&
test_bit(__IXGBE_RX_CSUM_UDP_ZERO_ERR, &ring->state))
return;
ring->rx_stats.csum_err++;
return;
}
skb->ip_summed = CHECKSUM_UNNECESSARY;
if (encap_pkt) {
if (!ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_OUTERIPCS))
return;
if (ixgbe_test_staterr(rx_desc, IXGBE_RXDADV_ERR_OUTERIPER)) {
skb->ip_summed = CHECKSUM_NONE;
return;
}
skb->csum_level = 1;
}
}
static inline unsigned int ixgbe_rx_offset(struct ixgbe_ring *rx_ring)
{
return ring_uses_build_skb(rx_ring) ? IXGBE_SKB_PAD : 0;
}
static bool ixgbe_alloc_mapped_page(struct ixgbe_ring *rx_ring,
struct ixgbe_rx_buffer *bi)
{
struct page *page = bi->page;
dma_addr_t dma;
if (likely(page))
return true;
page = dev_alloc_pages(ixgbe_rx_pg_order(rx_ring));
if (unlikely(!page)) {
rx_ring->rx_stats.alloc_rx_page_failed++;
return false;
}
dma = dma_map_page_attrs(rx_ring->dev, page, 0,
ixgbe_rx_pg_size(rx_ring),
DMA_FROM_DEVICE,
IXGBE_RX_DMA_ATTR);
if (dma_mapping_error(rx_ring->dev, dma)) {
__free_pages(page, ixgbe_rx_pg_order(rx_ring));
rx_ring->rx_stats.alloc_rx_page_failed++;
return false;
}
bi->dma = dma;
bi->page = page;
bi->page_offset = ixgbe_rx_offset(rx_ring);
bi->pagecnt_bias = 1;
return true;
}
void ixgbe_alloc_rx_buffers(struct ixgbe_ring *rx_ring, u16 cleaned_count)
{
union ixgbe_adv_rx_desc *rx_desc;
struct ixgbe_rx_buffer *bi;
u16 i = rx_ring->next_to_use;
u16 bufsz;
if (!cleaned_count)
return;
rx_desc = IXGBE_RX_DESC(rx_ring, i);
bi = &rx_ring->rx_buffer_info[i];
i -= rx_ring->count;
bufsz = ixgbe_rx_bufsz(rx_ring);
do {
if (!ixgbe_alloc_mapped_page(rx_ring, bi))
break;
dma_sync_single_range_for_device(rx_ring->dev, bi->dma,
bi->page_offset, bufsz,
DMA_FROM_DEVICE);
rx_desc->read.pkt_addr = cpu_to_le64(bi->dma + bi->page_offset);
rx_desc++;
bi++;
i++;
if (unlikely(!i)) {
rx_desc = IXGBE_RX_DESC(rx_ring, 0);
bi = rx_ring->rx_buffer_info;
i -= rx_ring->count;
}
rx_desc->wb.upper.length = 0;
cleaned_count--;
} while (cleaned_count);
i += rx_ring->count;
if (rx_ring->next_to_use != i) {
rx_ring->next_to_use = i;
rx_ring->next_to_alloc = i;
wmb();
writel(i, rx_ring->tail);
}
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
u32 flags = rx_ring->q_vector->adapter->flags;
ixgbe_update_rsc_stats(rx_ring, skb);
ixgbe_rx_hash(rx_ring, rx_desc, skb);
ixgbe_rx_checksum(rx_ring, rx_desc, skb);
if (unlikely(flags & IXGBE_FLAG_RX_HWTSTAMP_ENABLED))
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
napi_gro_receive(&q_vector->napi, skb);
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
pull_len = eth_get_headlen(va, IXGBE_RX_HDR_SIZE);
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
dma_unmap_page_attrs(rx_ring->dev, IXGBE_CB(skb)->dma,
ixgbe_rx_pg_size(rx_ring),
DMA_FROM_DEVICE,
IXGBE_RX_DMA_ATTR);
} else {
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[0];
dma_sync_single_range_for_cpu(rx_ring->dev,
IXGBE_CB(skb)->dma,
frag->page_offset,
skb_frag_size(frag),
DMA_FROM_DEVICE);
}
}
static bool ixgbe_cleanup_headers(struct ixgbe_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct net_device *netdev = rx_ring->netdev;
if (IS_ERR(skb))
return true;
if (unlikely(ixgbe_test_staterr(rx_desc,
IXGBE_RXDADV_ERR_FRAME_ERR_MASK) &&
!(netdev->features & NETIF_F_RXALL))) {
dev_kfree_skb_any(skb);
return true;
}
if (!skb_headlen(skb))
ixgbe_pull_tail(rx_ring, skb);
#ifdef IXGBE_FCOE
if (ixgbe_rx_is_fcoe(rx_ring, rx_desc))
return false;
#endif
if (eth_skb_pad(skb))
return true;
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
new_buff->dma = old_buff->dma;
new_buff->page = old_buff->page;
new_buff->page_offset = old_buff->page_offset;
new_buff->pagecnt_bias = old_buff->pagecnt_bias;
}
static inline bool ixgbe_page_is_reserved(struct page *page)
{
return (page_to_nid(page) != numa_mem_id()) || page_is_pfmemalloc(page);
}
static bool ixgbe_can_reuse_rx_page(struct ixgbe_rx_buffer *rx_buffer)
{
unsigned int pagecnt_bias = rx_buffer->pagecnt_bias;
struct page *page = rx_buffer->page;
if (unlikely(ixgbe_page_is_reserved(page)))
return false;
#if (PAGE_SIZE < 8192)
if (unlikely((page_ref_count(page) - pagecnt_bias) > 1))
return false;
#else
#define IXGBE_LAST_OFFSET \
(SKB_WITH_OVERHEAD(PAGE_SIZE) - IXGBE_RXBUFFER_3K)
if (rx_buffer->page_offset > IXGBE_LAST_OFFSET)
return false;
#endif
if (unlikely(!pagecnt_bias)) {
page_ref_add(page, USHRT_MAX);
rx_buffer->pagecnt_bias = USHRT_MAX;
}
return true;
}
static void ixgbe_add_rx_frag(struct ixgbe_ring *rx_ring,
struct ixgbe_rx_buffer *rx_buffer,
struct sk_buff *skb,
unsigned int size)
{
#if (PAGE_SIZE < 8192)
unsigned int truesize = ixgbe_rx_pg_size(rx_ring) / 2;
#else
unsigned int truesize = ring_uses_build_skb(rx_ring) ?
SKB_DATA_ALIGN(IXGBE_SKB_PAD + size) :
SKB_DATA_ALIGN(size);
#endif
skb_add_rx_frag(skb, skb_shinfo(skb)->nr_frags, rx_buffer->page,
rx_buffer->page_offset, size, truesize);
#if (PAGE_SIZE < 8192)
rx_buffer->page_offset ^= truesize;
#else
rx_buffer->page_offset += truesize;
#endif
}
static struct ixgbe_rx_buffer *ixgbe_get_rx_buffer(struct ixgbe_ring *rx_ring,
union ixgbe_adv_rx_desc *rx_desc,
struct sk_buff **skb,
const unsigned int size)
{
struct ixgbe_rx_buffer *rx_buffer;
rx_buffer = &rx_ring->rx_buffer_info[rx_ring->next_to_clean];
prefetchw(rx_buffer->page);
*skb = rx_buffer->skb;
if (!ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_EOP)) {
if (!*skb)
goto skip_sync;
} else {
if (*skb)
ixgbe_dma_sync_frag(rx_ring, *skb);
}
dma_sync_single_range_for_cpu(rx_ring->dev,
rx_buffer->dma,
rx_buffer->page_offset,
size,
DMA_FROM_DEVICE);
skip_sync:
rx_buffer->pagecnt_bias--;
return rx_buffer;
}
static void ixgbe_put_rx_buffer(struct ixgbe_ring *rx_ring,
struct ixgbe_rx_buffer *rx_buffer,
struct sk_buff *skb)
{
if (ixgbe_can_reuse_rx_page(rx_buffer)) {
ixgbe_reuse_rx_page(rx_ring, rx_buffer);
} else {
if (!IS_ERR(skb) && IXGBE_CB(skb)->dma == rx_buffer->dma) {
IXGBE_CB(skb)->page_released = true;
} else {
dma_unmap_page_attrs(rx_ring->dev, rx_buffer->dma,
ixgbe_rx_pg_size(rx_ring),
DMA_FROM_DEVICE,
IXGBE_RX_DMA_ATTR);
}
__page_frag_cache_drain(rx_buffer->page,
rx_buffer->pagecnt_bias);
}
rx_buffer->page = NULL;
rx_buffer->skb = NULL;
}
static struct sk_buff *ixgbe_construct_skb(struct ixgbe_ring *rx_ring,
struct ixgbe_rx_buffer *rx_buffer,
struct xdp_buff *xdp,
union ixgbe_adv_rx_desc *rx_desc)
{
unsigned int size = xdp->data_end - xdp->data;
#if (PAGE_SIZE < 8192)
unsigned int truesize = ixgbe_rx_pg_size(rx_ring) / 2;
#else
unsigned int truesize = SKB_DATA_ALIGN(xdp->data_end -
xdp->data_hard_start);
#endif
struct sk_buff *skb;
prefetch(xdp->data);
#if L1_CACHE_BYTES < 128
prefetch(xdp->data + L1_CACHE_BYTES);
#endif
skb = napi_alloc_skb(&rx_ring->q_vector->napi, IXGBE_RX_HDR_SIZE);
if (unlikely(!skb))
return NULL;
if (size > IXGBE_RX_HDR_SIZE) {
if (!ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_EOP))
IXGBE_CB(skb)->dma = rx_buffer->dma;
skb_add_rx_frag(skb, 0, rx_buffer->page,
xdp->data - page_address(rx_buffer->page),
size, truesize);
#if (PAGE_SIZE < 8192)
rx_buffer->page_offset ^= truesize;
#else
rx_buffer->page_offset += truesize;
#endif
} else {
memcpy(__skb_put(skb, size),
xdp->data, ALIGN(size, sizeof(long)));
rx_buffer->pagecnt_bias++;
}
return skb;
}
static struct sk_buff *ixgbe_build_skb(struct ixgbe_ring *rx_ring,
struct ixgbe_rx_buffer *rx_buffer,
struct xdp_buff *xdp,
union ixgbe_adv_rx_desc *rx_desc)
{
#if (PAGE_SIZE < 8192)
unsigned int truesize = ixgbe_rx_pg_size(rx_ring) / 2;
#else
unsigned int truesize = SKB_DATA_ALIGN(sizeof(struct skb_shared_info)) +
SKB_DATA_ALIGN(xdp->data_end -
xdp->data_hard_start);
#endif
struct sk_buff *skb;
prefetch(xdp->data);
#if L1_CACHE_BYTES < 128
prefetch(xdp->data + L1_CACHE_BYTES);
#endif
skb = build_skb(xdp->data_hard_start, truesize);
if (unlikely(!skb))
return NULL;
skb_reserve(skb, xdp->data - xdp->data_hard_start);
__skb_put(skb, xdp->data_end - xdp->data);
if (!ixgbe_test_staterr(rx_desc, IXGBE_RXD_STAT_EOP))
IXGBE_CB(skb)->dma = rx_buffer->dma;
#if (PAGE_SIZE < 8192)
rx_buffer->page_offset ^= truesize;
#else
rx_buffer->page_offset += truesize;
#endif
return skb;
}
static struct sk_buff *ixgbe_run_xdp(struct ixgbe_adapter *adapter,
struct ixgbe_ring *rx_ring,
struct xdp_buff *xdp)
{
int result = IXGBE_XDP_PASS;
struct bpf_prog *xdp_prog;
u32 act;
rcu_read_lock();
xdp_prog = READ_ONCE(rx_ring->xdp_prog);
if (!xdp_prog)
goto xdp_out;
act = bpf_prog_run_xdp(xdp_prog, xdp);
switch (act) {
case XDP_PASS:
break;
case XDP_TX:
result = ixgbe_xmit_xdp_ring(adapter, xdp);
break;
default:
bpf_warn_invalid_xdp_action(act);
case XDP_ABORTED:
trace_xdp_exception(rx_ring->netdev, xdp_prog, act);
case XDP_DROP:
result = IXGBE_XDP_CONSUMED;
break;
}
xdp_out:
rcu_read_unlock();
return ERR_PTR(-result);
}
static void ixgbe_rx_buffer_flip(struct ixgbe_ring *rx_ring,
struct ixgbe_rx_buffer *rx_buffer,
unsigned int size)
{
#if (PAGE_SIZE < 8192)
unsigned int truesize = ixgbe_rx_pg_size(rx_ring) / 2;
rx_buffer->page_offset ^= truesize;
#else
unsigned int truesize = ring_uses_build_skb(rx_ring) ?
SKB_DATA_ALIGN(IXGBE_SKB_PAD + size) :
SKB_DATA_ALIGN(size);
rx_buffer->page_offset += truesize;
#endif
}
static int ixgbe_clean_rx_irq(struct ixgbe_q_vector *q_vector,
struct ixgbe_ring *rx_ring,
const int budget)
{
unsigned int total_rx_bytes = 0, total_rx_packets = 0;
struct ixgbe_adapter *adapter = q_vector->adapter;
#ifdef IXGBE_FCOE
int ddp_bytes;
unsigned int mss = 0;
#endif
u16 cleaned_count = ixgbe_desc_unused(rx_ring);
bool xdp_xmit = false;
while (likely(total_rx_packets < budget)) {
union ixgbe_adv_rx_desc *rx_desc;
struct ixgbe_rx_buffer *rx_buffer;
struct sk_buff *skb;
struct xdp_buff xdp;
unsigned int size;
if (cleaned_count >= IXGBE_RX_BUFFER_WRITE) {
ixgbe_alloc_rx_buffers(rx_ring, cleaned_count);
cleaned_count = 0;
}
rx_desc = IXGBE_RX_DESC(rx_ring, rx_ring->next_to_clean);
size = le16_to_cpu(rx_desc->wb.upper.length);
if (!size)
break;
dma_rmb();
rx_buffer = ixgbe_get_rx_buffer(rx_ring, rx_desc, &skb, size);
if (!skb) {
xdp.data = page_address(rx_buffer->page) +
rx_buffer->page_offset;
xdp.data_hard_start = xdp.data -
ixgbe_rx_offset(rx_ring);
xdp.data_end = xdp.data + size;
skb = ixgbe_run_xdp(adapter, rx_ring, &xdp);
}
if (IS_ERR(skb)) {
if (PTR_ERR(skb) == -IXGBE_XDP_TX) {
xdp_xmit = true;
ixgbe_rx_buffer_flip(rx_ring, rx_buffer, size);
} else {
rx_buffer->pagecnt_bias++;
}
total_rx_packets++;
total_rx_bytes += size;
} else if (skb) {
ixgbe_add_rx_frag(rx_ring, rx_buffer, skb, size);
} else if (ring_uses_build_skb(rx_ring)) {
skb = ixgbe_build_skb(rx_ring, rx_buffer,
&xdp, rx_desc);
} else {
skb = ixgbe_construct_skb(rx_ring, rx_buffer,
&xdp, rx_desc);
}
if (!skb) {
rx_ring->rx_stats.alloc_rx_buff_failed++;
rx_buffer->pagecnt_bias++;
break;
}
ixgbe_put_rx_buffer(rx_ring, rx_buffer, skb);
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
ixgbe_rx_skb(q_vector, skb);
total_rx_packets++;
}
if (xdp_xmit) {
struct ixgbe_ring *ring = adapter->xdp_ring[smp_processor_id()];
wmb();
writel(ring->next_to_use, ring->tail);
}
u64_stats_update_begin(&rx_ring->syncp);
rx_ring->stats.packets += total_rx_packets;
rx_ring->stats.bytes += total_rx_bytes;
u64_stats_update_end(&rx_ring->syncp);
q_vector->rx.total_packets += total_rx_packets;
q_vector->rx.total_bytes += total_rx_bytes;
return total_rx_packets;
}
static void ixgbe_configure_msix(struct ixgbe_adapter *adapter)
{
struct ixgbe_q_vector *q_vector;
int v_idx;
u32 mask;
if (adapter->num_vfs > 32) {
u32 eitrsel = BIT(adapter->num_vfs - 32) - 1;
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
new_itr = IXGBE_12K_ITR;
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
s32 rc;
if (test_bit(__IXGBE_DOWN, &adapter->state))
return;
if (!(adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE) &&
!(adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_EVENT))
return;
adapter->flags2 &= ~IXGBE_FLAG2_TEMP_SENSOR_EVENT;
switch (hw->device_id) {
case IXGBE_DEV_ID_82599_T3_LOM:
if (!(eicr & IXGBE_EICR_GPI_SDP0_8259X) &&
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
case IXGBE_DEV_ID_X550EM_A_1G_T:
case IXGBE_DEV_ID_X550EM_A_1G_T_L:
rc = hw->phy.ops.check_overtemp(hw);
if (rc != IXGBE_ERR_OVERTEMP)
return;
break;
default:
if (adapter->hw.mac.type >= ixgbe_mac_X540)
return;
if (!(eicr & IXGBE_EICR_GPI_SDP0(hw)))
return;
break;
}
e_crit(drv, "%s\n", ixgbe_overheat_msg);
adapter->interrupt_event = 0;
}
static void ixgbe_check_fan_failure(struct ixgbe_adapter *adapter, u32 eicr)
{
struct ixgbe_hw *hw = &adapter->hw;
if ((adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE) &&
(eicr & IXGBE_EICR_GPI_SDP1(hw))) {
e_crit(probe, "Fan has stopped, replace the adapter\n");
IXGBE_WRITE_REG(hw, IXGBE_EICR, IXGBE_EICR_GPI_SDP1(hw));
}
}
static void ixgbe_check_overtemp_event(struct ixgbe_adapter *adapter, u32 eicr)
{
struct ixgbe_hw *hw = &adapter->hw;
if (!(adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE))
return;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
if (((eicr & IXGBE_EICR_GPI_SDP0(hw)) ||
(eicr & IXGBE_EICR_LSC)) &&
(!test_bit(__IXGBE_DOWN, &adapter->state))) {
adapter->interrupt_event = eicr;
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_EVENT;
ixgbe_service_event_schedule(adapter);
return;
}
return;
case ixgbe_mac_x550em_a:
if (eicr & IXGBE_EICR_GPI_SDP0_X550EM_a) {
adapter->interrupt_event = eicr;
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_EVENT;
ixgbe_service_event_schedule(adapter);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC,
IXGBE_EICR_GPI_SDP0_X550EM_a);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EICR,
IXGBE_EICR_GPI_SDP0_X550EM_a);
}
return;
case ixgbe_mac_X550:
case ixgbe_mac_X540:
if (!(eicr & IXGBE_EICR_TS))
return;
break;
default:
return;
}
e_crit(drv, "%s\n", ixgbe_overheat_msg);
}
static inline bool ixgbe_is_sfp(struct ixgbe_hw *hw)
{
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
if (hw->phy.type == ixgbe_phy_nl)
return true;
return false;
case ixgbe_mac_82599EB:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
switch (hw->mac.ops.get_media_type(hw)) {
case ixgbe_media_type_fiber:
case ixgbe_media_type_fiber_qsfp:
return true;
default:
return false;
}
default:
return false;
}
}
static void ixgbe_check_sfp_event(struct ixgbe_adapter *adapter, u32 eicr)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 eicr_mask = IXGBE_EICR_GPI_SDP2(hw);
if (!ixgbe_is_sfp(hw))
return;
if (hw->mac.type >= ixgbe_mac_X540)
eicr_mask = IXGBE_EICR_GPI_SDP0_X540;
if (eicr & eicr_mask) {
IXGBE_WRITE_REG(hw, IXGBE_EICR, eicr_mask);
if (!test_bit(__IXGBE_DOWN, &adapter->state)) {
adapter->flags2 |= IXGBE_FLAG2_SFP_NEEDS_RESET;
adapter->sfp_poll_time = 0;
ixgbe_service_event_schedule(adapter);
}
}
if (adapter->hw.mac.type == ixgbe_mac_82599EB &&
(eicr & IXGBE_EICR_GPI_SDP1(hw))) {
IXGBE_WRITE_REG(hw, IXGBE_EICR, IXGBE_EICR_GPI_SDP1(hw));
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
struct ixgbe_hw *hw = &adapter->hw;
u32 mask = (IXGBE_EIMS_ENABLE_MASK & ~IXGBE_EIMS_RTX_QUEUE);
if (adapter->flags & IXGBE_FLAG_NEED_LINK_UPDATE)
mask &= ~IXGBE_EIMS_LSC;
if (adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_CAPABLE)
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
mask |= IXGBE_EIMS_GPI_SDP0(hw);
break;
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
mask |= IXGBE_EIMS_TS;
break;
default:
break;
}
if (adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE)
mask |= IXGBE_EIMS_GPI_SDP1(hw);
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
mask |= IXGBE_EIMS_GPI_SDP1(hw);
mask |= IXGBE_EIMS_GPI_SDP2(hw);
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
if (adapter->hw.device_id == IXGBE_DEV_ID_X550EM_X_SFP ||
adapter->hw.device_id == IXGBE_DEV_ID_X550EM_A_SFP ||
adapter->hw.device_id == IXGBE_DEV_ID_X550EM_A_SFP_N)
mask |= IXGBE_EIMS_GPI_SDP0(&adapter->hw);
if (adapter->hw.phy.type == ixgbe_phy_x550em_ext_t)
mask |= IXGBE_EICR_GPI_SDP0_X540;
mask |= IXGBE_EIMS_ECC;
mask |= IXGBE_EIMS_MAILBOX;
break;
default:
break;
}
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
if (hw->phy.type == ixgbe_phy_x550em_ext_t &&
(eicr & IXGBE_EICR_GPI_SDP0_X540)) {
adapter->flags2 |= IXGBE_FLAG2_PHY_INTERRUPT;
ixgbe_service_event_schedule(adapter);
IXGBE_WRITE_REG(hw, IXGBE_EICR,
IXGBE_EICR_GPI_SDP0_X540);
}
if (eicr & IXGBE_EICR_ECC) {
e_info(link, "Received ECC Err, initiating reset\n");
set_bit(__IXGBE_RESET_REQUESTED, &adapter->state);
ixgbe_service_event_schedule(adapter);
IXGBE_WRITE_REG(hw, IXGBE_EICR, IXGBE_EICR_ECC);
}
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
ixgbe_ptp_check_pps_event(adapter);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable(adapter, false, false);
return IRQ_HANDLED;
}
static irqreturn_t ixgbe_msix_clean_rings(int irq, void *data)
{
struct ixgbe_q_vector *q_vector = data;
if (q_vector->rx.ring || q_vector->tx.ring)
napi_schedule_irqoff(&q_vector->napi);
return IRQ_HANDLED;
}
int ixgbe_poll(struct napi_struct *napi, int budget)
{
struct ixgbe_q_vector *q_vector =
container_of(napi, struct ixgbe_q_vector, napi);
struct ixgbe_adapter *adapter = q_vector->adapter;
struct ixgbe_ring *ring;
int per_ring_budget, work_done = 0;
bool clean_complete = true;
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED)
ixgbe_update_dca(q_vector);
#endif
ixgbe_for_each_ring(ring, q_vector->tx) {
if (!ixgbe_clean_tx_irq(q_vector, ring, budget))
clean_complete = false;
}
if (budget <= 0)
return budget;
if (q_vector->rx.count > 1)
per_ring_budget = max(budget/q_vector->rx.count, 1);
else
per_ring_budget = budget;
ixgbe_for_each_ring(ring, q_vector->rx) {
int cleaned = ixgbe_clean_rx_irq(q_vector, ring,
per_ring_budget);
work_done += cleaned;
if (cleaned >= per_ring_budget)
clean_complete = false;
}
if (!clean_complete)
return budget;
napi_complete_done(napi, work_done);
if (adapter->rx_itr_setting & 1)
ixgbe_set_itr(q_vector);
if (!test_bit(__IXGBE_DOWN, &adapter->state))
ixgbe_irq_enable_queues(adapter, BIT_ULL(q_vector->v_idx));
return min(work_done, budget - 1);
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
if (eicr & IXGBE_EICR_ECC) {
e_info(link, "Received ECC Err, initiating reset\n");
set_bit(__IXGBE_RESET_REQUESTED, &adapter->state);
ixgbe_service_event_schedule(adapter);
IXGBE_WRITE_REG(hw, IXGBE_EICR, IXGBE_EICR_ECC);
}
ixgbe_check_overtemp_event(adapter, eicr);
break;
default:
break;
}
ixgbe_check_fan_failure(adapter, eicr);
if (unlikely(eicr & IXGBE_EICR_TIMESYNC))
ixgbe_ptp_check_pps_event(adapter);
napi_schedule_irqoff(&q_vector->napi);
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
if (!adapter->msix_entries)
return;
for (vector = 0; vector < adapter->num_q_vectors; vector++) {
struct ixgbe_q_vector *q_vector = adapter->q_vector[vector];
struct msix_entry *entry = &adapter->msix_entries[vector];
if (!q_vector->rx.ring && !q_vector->tx.ring)
continue;
irq_set_affinity_hint(entry->vector, NULL);
free_irq(entry->vector, q_vector);
}
free_irq(adapter->msix_entries[vector].vector, adapter);
}
static inline void ixgbe_irq_disable(struct ixgbe_adapter *adapter)
{
switch (adapter->hw.mac.type) {
case ixgbe_mac_82598EB:
IXGBE_WRITE_REG(&adapter->hw, IXGBE_EIMC, ~0);
break;
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
ring->tail = adapter->io_addr + IXGBE_TDT(reg_idx);
if (!ring->q_vector || (ring->q_vector->itr < IXGBE_100K_ITR))
txdctl |= 1u << 16;
else
txdctl |= 8u << 16;
txdctl |= (1u << 8) |
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
netif_set_xps_queue(ring->netdev,
&q_vector->affinity_mask,
ring->queue_index);
}
clear_bit(__IXGBE_HANG_CHECK_ARMED, &ring->state);
memset(ring->tx_buffer_info, 0,
sizeof(struct ixgbe_tx_buffer) * ring->count);
IXGBE_WRITE_REG(hw, IXGBE_TXDCTL(reg_idx), txdctl);
if (hw->mac.type == ixgbe_mac_82598EB &&
!(IXGBE_READ_REG(hw, IXGBE_LINKS) & IXGBE_LINKS_UP))
return;
do {
usleep_range(1000, 2000);
txdctl = IXGBE_READ_REG(hw, IXGBE_TXDCTL(reg_idx));
} while (--wait_loop && !(txdctl & IXGBE_TXDCTL_ENABLE));
if (!wait_loop)
hw_dbg(hw, "Could not enable Tx Queue %d\n", reg_idx);
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
else if (adapter->ring_feature[RING_F_VMDQ].mask ==
IXGBE_82599_VMDQ_4Q_MASK)
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
for (i = 0; i < adapter->num_xdp_queues; i++)
ixgbe_configure_tx_ring(adapter, adapter->xdp_ring[i]);
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
if (test_bit(__IXGBE_RX_3K_BUFFER, &rx_ring->state))
srrctl |= IXGBE_RXBUFFER_3K >> IXGBE_SRRCTL_BSIZEPKT_SHIFT;
else
srrctl |= IXGBE_RXBUFFER_2K >> IXGBE_SRRCTL_BSIZEPKT_SHIFT;
srrctl |= IXGBE_SRRCTL_DESCTYPE_ADV_ONEBUF;
IXGBE_WRITE_REG(hw, IXGBE_SRRCTL(reg_idx), srrctl);
}
u32 ixgbe_rss_indir_tbl_entries(struct ixgbe_adapter *adapter)
{
if (adapter->hw.mac.type < ixgbe_mac_X550)
return 128;
else if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
return 64;
else
return 512;
}
void ixgbe_store_key(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int i;
for (i = 0; i < 10; i++)
IXGBE_WRITE_REG(hw, IXGBE_RSSRK(i), adapter->rss_key[i]);
}
static inline int ixgbe_init_rss_key(struct ixgbe_adapter *adapter)
{
u32 *rss_key;
if (!adapter->rss_key) {
rss_key = kzalloc(IXGBE_RSS_KEY_SIZE, GFP_KERNEL);
if (unlikely(!rss_key))
return -ENOMEM;
netdev_rss_key_fill(rss_key, IXGBE_RSS_KEY_SIZE);
adapter->rss_key = rss_key;
}
return 0;
}
void ixgbe_store_reta(struct ixgbe_adapter *adapter)
{
u32 i, reta_entries = ixgbe_rss_indir_tbl_entries(adapter);
struct ixgbe_hw *hw = &adapter->hw;
u32 reta = 0;
u32 indices_multi;
u8 *indir_tbl = adapter->rss_indir_tbl;
if (adapter->hw.mac.type == ixgbe_mac_82598EB)
indices_multi = 0x11;
else
indices_multi = 0x1;
for (i = 0; i < reta_entries; i++) {
reta |= indices_multi * indir_tbl[i] << (i & 0x3) * 8;
if ((i & 3) == 3) {
if (i < 128)
IXGBE_WRITE_REG(hw, IXGBE_RETA(i >> 2), reta);
else
IXGBE_WRITE_REG(hw, IXGBE_ERETA((i >> 2) - 32),
reta);
reta = 0;
}
}
}
static void ixgbe_store_vfreta(struct ixgbe_adapter *adapter)
{
u32 i, reta_entries = ixgbe_rss_indir_tbl_entries(adapter);
struct ixgbe_hw *hw = &adapter->hw;
u32 vfreta = 0;
unsigned int pf_pool = adapter->num_vfs;
for (i = 0; i < reta_entries; i++) {
vfreta |= (u32)adapter->rss_indir_tbl[i] << (i & 0x3) * 8;
if ((i & 3) == 3) {
IXGBE_WRITE_REG(hw, IXGBE_PFVFRETA(i >> 2, pf_pool),
vfreta);
vfreta = 0;
}
}
}
static void ixgbe_setup_reta(struct ixgbe_adapter *adapter)
{
u32 i, j;
u32 reta_entries = ixgbe_rss_indir_tbl_entries(adapter);
u16 rss_i = adapter->ring_feature[RING_F_RSS].indices;
if ((adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) && (rss_i < 4))
rss_i = 4;
ixgbe_store_key(adapter);
memset(adapter->rss_indir_tbl, 0, sizeof(adapter->rss_indir_tbl));
for (i = 0, j = 0; i < reta_entries; i++, j++) {
if (j == rss_i)
j = 0;
adapter->rss_indir_tbl[i] = j;
}
ixgbe_store_reta(adapter);
}
static void ixgbe_setup_vfreta(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u16 rss_i = adapter->ring_feature[RING_F_RSS].indices;
unsigned int pf_pool = adapter->num_vfs;
int i, j;
for (i = 0; i < 10; i++)
IXGBE_WRITE_REG(hw, IXGBE_PFVFRSSRK(i, pf_pool),
*(adapter->rss_key + i));
for (i = 0, j = 0; i < 64; i++, j++) {
if (j == rss_i)
j = 0;
adapter->rss_indir_tbl[i] = j;
}
ixgbe_store_vfreta(adapter);
}
static void ixgbe_setup_mrqc(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 mrqc = 0, rss_field = 0, vfmrqc = 0;
u32 rxcsum;
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
else if (adapter->ring_feature[RING_F_VMDQ].mask ==
IXGBE_82599_VMDQ_4Q_MASK)
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
rss_field |= IXGBE_MRQC_RSS_FIELD_IPV4 |
IXGBE_MRQC_RSS_FIELD_IPV4_TCP |
IXGBE_MRQC_RSS_FIELD_IPV6 |
IXGBE_MRQC_RSS_FIELD_IPV6_TCP;
if (adapter->flags2 & IXGBE_FLAG2_RSS_FIELD_IPV4_UDP)
rss_field |= IXGBE_MRQC_RSS_FIELD_IPV4_UDP;
if (adapter->flags2 & IXGBE_FLAG2_RSS_FIELD_IPV6_UDP)
rss_field |= IXGBE_MRQC_RSS_FIELD_IPV6_UDP;
if ((hw->mac.type >= ixgbe_mac_X550) &&
(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)) {
unsigned int pf_pool = adapter->num_vfs;
mrqc |= IXGBE_MRQC_MULTIPLE_RSS;
IXGBE_WRITE_REG(hw, IXGBE_MRQC, mrqc);
ixgbe_setup_vfreta(adapter);
vfmrqc = IXGBE_MRQC_RSSEN;
vfmrqc |= rss_field;
IXGBE_WRITE_REG(hw, IXGBE_PFVFMRQC(pf_pool), vfmrqc);
} else {
ixgbe_setup_reta(adapter);
mrqc |= rss_field;
IXGBE_WRITE_REG(hw, IXGBE_MRQC, mrqc);
}
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
if (ixgbe_removed(hw->hw_addr))
return;
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
if (ixgbe_removed(hw->hw_addr))
return;
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
union ixgbe_adv_rx_desc *rx_desc;
u64 rdba = ring->dma;
u32 rxdctl;
u8 reg_idx = ring->reg_idx;
rxdctl = IXGBE_READ_REG(hw, IXGBE_RXDCTL(reg_idx));
ixgbe_disable_rx_queue(adapter, ring);
IXGBE_WRITE_REG(hw, IXGBE_RDBAL(reg_idx), (rdba & DMA_BIT_MASK(32)));
IXGBE_WRITE_REG(hw, IXGBE_RDBAH(reg_idx), (rdba >> 32));
IXGBE_WRITE_REG(hw, IXGBE_RDLEN(reg_idx),
ring->count * sizeof(union ixgbe_adv_rx_desc));
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_RDH(reg_idx), 0);
IXGBE_WRITE_REG(hw, IXGBE_RDT(reg_idx), 0);
ring->tail = adapter->io_addr + IXGBE_RDT(reg_idx);
ixgbe_configure_srrctl(adapter, ring);
ixgbe_configure_rscctl(adapter, ring);
if (hw->mac.type == ixgbe_mac_82598EB) {
rxdctl &= ~0x3FFFFF;
rxdctl |= 0x080420;
#if (PAGE_SIZE < 8192)
} else {
rxdctl &= ~(IXGBE_RXDCTL_RLPMLMASK |
IXGBE_RXDCTL_RLPML_EN);
if (ring_uses_build_skb(ring) &&
!test_bit(__IXGBE_RX_3K_BUFFER, &ring->state))
rxdctl |= IXGBE_MAX_2K_FRAME_BUILD_SKB |
IXGBE_RXDCTL_RLPML_EN;
#endif
}
memset(ring->rx_buffer_info, 0,
sizeof(struct ixgbe_rx_buffer) * ring->count);
rx_desc = IXGBE_RX_DESC(ring, 0);
rx_desc->wb.upper.length = 0;
rxdctl |= IXGBE_RXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_RXDCTL(reg_idx), rxdctl);
ixgbe_rx_desc_queue_enable(adapter, ring);
ixgbe_alloc_rx_buffers(ring, ixgbe_desc_unused(ring));
}
static void ixgbe_setup_psrtype(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int rss_i = adapter->ring_feature[RING_F_RSS].indices;
u16 pool;
u32 psrtype = IXGBE_PSRTYPE_TCPHDR |
IXGBE_PSRTYPE_UDPHDR |
IXGBE_PSRTYPE_IPV4HDR |
IXGBE_PSRTYPE_L2HDR |
IXGBE_PSRTYPE_IPV6HDR;
if (hw->mac.type == ixgbe_mac_82598EB)
return;
if (rss_i > 3)
psrtype |= 2u << 29;
else if (rss_i > 1)
psrtype |= 1u << 29;
for_each_set_bit(pool, &adapter->fwd_bitmask, 32)
IXGBE_WRITE_REG(hw, IXGBE_PSRTYPE(VMDQ_P(pool)), psrtype);
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
IXGBE_WRITE_REG(hw, IXGBE_VFRE(reg_offset), GENMASK(31, vf_shift));
IXGBE_WRITE_REG(hw, IXGBE_VFRE(reg_offset ^ 1), reg_offset - 1);
IXGBE_WRITE_REG(hw, IXGBE_VFTE(reg_offset), GENMASK(31, vf_shift));
IXGBE_WRITE_REG(hw, IXGBE_VFTE(reg_offset ^ 1), reg_offset - 1);
if (adapter->bridge_mode == BRIDGE_MODE_VEB)
IXGBE_WRITE_REG(hw, IXGBE_PFDTXGSWC, IXGBE_PFDTXGSWC_VT_LBEN);
hw->mac.ops.set_vmdq(hw, 0, VMDQ_P(0));
adapter->flags2 &= ~IXGBE_FLAG2_VLAN_PROMISC;
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
for (i = 0; i < adapter->num_vfs; i++) {
ixgbe_ndo_set_vf_spoofchk(adapter->netdev, i,
adapter->vfinfo[i].spoofchk_enabled);
ixgbe_ndo_set_vf_rss_query_en(adapter->netdev, i,
adapter->vfinfo[i].rss_query_enabled);
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
clear_ring_rsc_enabled(rx_ring);
clear_bit(__IXGBE_RX_3K_BUFFER, &rx_ring->state);
clear_bit(__IXGBE_RX_BUILD_SKB_ENABLED, &rx_ring->state);
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)
set_ring_rsc_enabled(rx_ring);
if (test_bit(__IXGBE_RX_FCOE, &rx_ring->state))
set_bit(__IXGBE_RX_3K_BUFFER, &rx_ring->state);
clear_bit(__IXGBE_RX_BUILD_SKB_ENABLED, &rx_ring->state);
if (adapter->flags2 & IXGBE_FLAG2_RX_LEGACY)
continue;
set_bit(__IXGBE_RX_BUILD_SKB_ENABLED, &rx_ring->state);
#if (PAGE_SIZE < 8192)
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)
set_bit(__IXGBE_RX_3K_BUFFER, &rx_ring->state);
if (IXGBE_2K_TOO_SMALL_WITH_PADDING ||
(max_frame > (ETH_FRAME_LEN + ETH_FCS_LEN)))
set_bit(__IXGBE_RX_3K_BUFFER, &rx_ring->state);
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
if (adapter->num_vfs)
rdrxctl |= IXGBE_RDRXCTL_PSP;
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
hw->mac.ops.disable_rx(hw);
ixgbe_setup_psrtype(adapter);
ixgbe_setup_rdrxctl(adapter);
rfctl = IXGBE_READ_REG(hw, IXGBE_RFCTL);
rfctl &= ~IXGBE_RFCTL_RSC_DIS;
if (!(adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED))
rfctl |= IXGBE_RFCTL_RSC_DIS;
rfctl |= (IXGBE_RFCTL_NFSW_DIS | IXGBE_RFCTL_NFSR_DIS);
IXGBE_WRITE_REG(hw, IXGBE_RFCTL, rfctl);
ixgbe_setup_mrqc(adapter);
ixgbe_set_rx_buffer_len(adapter);
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbe_configure_rx_ring(adapter, adapter->rx_ring[i]);
rxctrl = IXGBE_READ_REG(hw, IXGBE_RXCTRL);
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
if (!vid || !(adapter->flags2 & IXGBE_FLAG2_VLAN_PROMISC))
hw->mac.ops.set_vfta(&adapter->hw, vid, VMDQ_P(0), true, !!vid);
set_bit(vid, adapter->active_vlans);
return 0;
}
static int ixgbe_find_vlvf_entry(struct ixgbe_hw *hw, u32 vlan)
{
u32 vlvf;
int idx;
if (vlan == 0)
return 0;
for (idx = IXGBE_VLVF_ENTRIES; --idx;) {
vlvf = IXGBE_READ_REG(hw, IXGBE_VLVF(idx));
if ((vlvf & VLAN_VID_MASK) == vlan)
break;
}
return idx;
}
void ixgbe_update_pf_promisc_vlvf(struct ixgbe_adapter *adapter, u32 vid)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 bits, word;
int idx;
idx = ixgbe_find_vlvf_entry(hw, vid);
if (!idx)
return;
word = idx * 2 + (VMDQ_P(0) / 32);
bits = ~BIT(VMDQ_P(0) % 32);
bits &= IXGBE_READ_REG(hw, IXGBE_VLVFB(word));
if (!bits && !IXGBE_READ_REG(hw, IXGBE_VLVFB(word ^ 1))) {
if (!(adapter->flags2 & IXGBE_FLAG2_VLAN_PROMISC))
IXGBE_WRITE_REG(hw, IXGBE_VLVFB(word), 0);
IXGBE_WRITE_REG(hw, IXGBE_VLVF(idx), 0);
}
}
static int ixgbe_vlan_rx_kill_vid(struct net_device *netdev,
__be16 proto, u16 vid)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
if (vid && !(adapter->flags2 & IXGBE_FLAG2_VLAN_PROMISC))
hw->mac.ops.set_vfta(hw, vid, VMDQ_P(0), false, true);
clear_bit(vid, adapter->active_vlans);
return 0;
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
for (i = 0; i < adapter->num_rx_queues; i++) {
struct ixgbe_ring *ring = adapter->rx_ring[i];
if (ring->l2_accel_priv)
continue;
j = ring->reg_idx;
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
for (i = 0; i < adapter->num_rx_queues; i++) {
struct ixgbe_ring *ring = adapter->rx_ring[i];
if (ring->l2_accel_priv)
continue;
j = ring->reg_idx;
vlnctrl = IXGBE_READ_REG(hw, IXGBE_RXDCTL(j));
vlnctrl |= IXGBE_RXDCTL_VME;
IXGBE_WRITE_REG(hw, IXGBE_RXDCTL(j), vlnctrl);
}
break;
default:
break;
}
}
static void ixgbe_vlan_promisc_enable(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vlnctrl, i;
vlnctrl = IXGBE_READ_REG(hw, IXGBE_VLNCTRL);
if (adapter->flags & IXGBE_FLAG_VMDQ_ENABLED) {
vlnctrl |= IXGBE_VLNCTRL_VFE;
IXGBE_WRITE_REG(hw, IXGBE_VLNCTRL, vlnctrl);
} else {
vlnctrl &= ~IXGBE_VLNCTRL_VFE;
IXGBE_WRITE_REG(hw, IXGBE_VLNCTRL, vlnctrl);
return;
}
if (hw->mac.type == ixgbe_mac_82598EB)
return;
if (adapter->flags2 & IXGBE_FLAG2_VLAN_PROMISC)
return;
adapter->flags2 |= IXGBE_FLAG2_VLAN_PROMISC;
for (i = IXGBE_VLVF_ENTRIES; --i;) {
u32 reg_offset = IXGBE_VLVFB(i * 2 + VMDQ_P(0) / 32);
u32 vlvfb = IXGBE_READ_REG(hw, reg_offset);
vlvfb |= BIT(VMDQ_P(0) % 32);
IXGBE_WRITE_REG(hw, reg_offset, vlvfb);
}
for (i = hw->mac.vft_size; i--;)
IXGBE_WRITE_REG(hw, IXGBE_VFTA(i), ~0U);
}
static void ixgbe_scrub_vfta(struct ixgbe_adapter *adapter, u32 vfta_offset)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vfta[VFTA_BLOCK_SIZE] = { 0 };
u32 vid_start = vfta_offset * 32;
u32 vid_end = vid_start + (VFTA_BLOCK_SIZE * 32);
u32 i, vid, word, bits;
for (i = IXGBE_VLVF_ENTRIES; --i;) {
u32 vlvf = IXGBE_READ_REG(hw, IXGBE_VLVF(i));
vid = vlvf & VLAN_VID_MASK;
if (vid < vid_start || vid >= vid_end)
continue;
if (vlvf) {
vfta[(vid - vid_start) / 32] |= BIT(vid % 32);
if (test_bit(vid, adapter->active_vlans))
continue;
}
word = i * 2 + VMDQ_P(0) / 32;
bits = ~BIT(VMDQ_P(0) % 32);
bits &= IXGBE_READ_REG(hw, IXGBE_VLVFB(word));
IXGBE_WRITE_REG(hw, IXGBE_VLVFB(word), bits);
}
for (i = VFTA_BLOCK_SIZE; i--;) {
vid = (vfta_offset + i) * 32;
word = vid / BITS_PER_LONG;
bits = vid % BITS_PER_LONG;
vfta[i] |= adapter->active_vlans[word] >> bits;
IXGBE_WRITE_REG(hw, IXGBE_VFTA(vfta_offset + i), vfta[i]);
}
}
static void ixgbe_vlan_promisc_disable(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vlnctrl, i;
vlnctrl = IXGBE_READ_REG(hw, IXGBE_VLNCTRL);
vlnctrl |= IXGBE_VLNCTRL_VFE;
IXGBE_WRITE_REG(hw, IXGBE_VLNCTRL, vlnctrl);
if (!(adapter->flags & IXGBE_FLAG_VMDQ_ENABLED) ||
hw->mac.type == ixgbe_mac_82598EB)
return;
if (!(adapter->flags2 & IXGBE_FLAG2_VLAN_PROMISC))
return;
adapter->flags2 &= ~IXGBE_FLAG2_VLAN_PROMISC;
for (i = 0; i < hw->mac.vft_size; i += VFTA_BLOCK_SIZE)
ixgbe_scrub_vfta(adapter, i);
}
static void ixgbe_restore_vlan(struct ixgbe_adapter *adapter)
{
u16 vid = 1;
ixgbe_vlan_rx_add_vid(adapter->netdev, htons(ETH_P_8021Q), 0);
for_each_set_bit_from(vid, adapter->active_vlans, VLAN_N_VID)
ixgbe_vlan_rx_add_vid(adapter->netdev, htons(ETH_P_8021Q), vid);
}
static int ixgbe_write_mc_addr_list(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
if (!netif_running(netdev))
return 0;
if (hw->mac.ops.update_mc_addr_list)
hw->mac.ops.update_mc_addr_list(hw, netdev);
else
return -ENOMEM;
#ifdef CONFIG_PCI_IOV
ixgbe_restore_vf_multicasts(adapter);
#endif
return netdev_mc_count(netdev);
}
void ixgbe_full_sync_mac_table(struct ixgbe_adapter *adapter)
{
struct ixgbe_mac_addr *mac_table = &adapter->mac_table[0];
struct ixgbe_hw *hw = &adapter->hw;
int i;
for (i = 0; i < hw->mac.num_rar_entries; i++, mac_table++) {
mac_table->state &= ~IXGBE_MAC_STATE_MODIFIED;
if (mac_table->state & IXGBE_MAC_STATE_IN_USE)
hw->mac.ops.set_rar(hw, i,
mac_table->addr,
mac_table->pool,
IXGBE_RAH_AV);
else
hw->mac.ops.clear_rar(hw, i);
}
}
static void ixgbe_sync_mac_table(struct ixgbe_adapter *adapter)
{
struct ixgbe_mac_addr *mac_table = &adapter->mac_table[0];
struct ixgbe_hw *hw = &adapter->hw;
int i;
for (i = 0; i < hw->mac.num_rar_entries; i++, mac_table++) {
if (!(mac_table->state & IXGBE_MAC_STATE_MODIFIED))
continue;
mac_table->state &= ~IXGBE_MAC_STATE_MODIFIED;
if (mac_table->state & IXGBE_MAC_STATE_IN_USE)
hw->mac.ops.set_rar(hw, i,
mac_table->addr,
mac_table->pool,
IXGBE_RAH_AV);
else
hw->mac.ops.clear_rar(hw, i);
}
}
static void ixgbe_flush_sw_mac_table(struct ixgbe_adapter *adapter)
{
struct ixgbe_mac_addr *mac_table = &adapter->mac_table[0];
struct ixgbe_hw *hw = &adapter->hw;
int i;
for (i = 0; i < hw->mac.num_rar_entries; i++, mac_table++) {
mac_table->state |= IXGBE_MAC_STATE_MODIFIED;
mac_table->state &= ~IXGBE_MAC_STATE_IN_USE;
}
ixgbe_sync_mac_table(adapter);
}
static int ixgbe_available_rars(struct ixgbe_adapter *adapter, u16 pool)
{
struct ixgbe_mac_addr *mac_table = &adapter->mac_table[0];
struct ixgbe_hw *hw = &adapter->hw;
int i, count = 0;
for (i = 0; i < hw->mac.num_rar_entries; i++, mac_table++) {
if (mac_table->state & IXGBE_MAC_STATE_DEFAULT)
continue;
if (mac_table->state & IXGBE_MAC_STATE_IN_USE) {
if (mac_table->pool != pool)
continue;
}
count++;
}
return count;
}
static void ixgbe_mac_set_default_filter(struct ixgbe_adapter *adapter)
{
struct ixgbe_mac_addr *mac_table = &adapter->mac_table[0];
struct ixgbe_hw *hw = &adapter->hw;
memcpy(&mac_table->addr, hw->mac.addr, ETH_ALEN);
mac_table->pool = VMDQ_P(0);
mac_table->state = IXGBE_MAC_STATE_DEFAULT | IXGBE_MAC_STATE_IN_USE;
hw->mac.ops.set_rar(hw, 0, mac_table->addr, mac_table->pool,
IXGBE_RAH_AV);
}
int ixgbe_add_mac_filter(struct ixgbe_adapter *adapter,
const u8 *addr, u16 pool)
{
struct ixgbe_mac_addr *mac_table = &adapter->mac_table[0];
struct ixgbe_hw *hw = &adapter->hw;
int i;
if (is_zero_ether_addr(addr))
return -EINVAL;
for (i = 0; i < hw->mac.num_rar_entries; i++, mac_table++) {
if (mac_table->state & IXGBE_MAC_STATE_IN_USE)
continue;
ether_addr_copy(mac_table->addr, addr);
mac_table->pool = pool;
mac_table->state |= IXGBE_MAC_STATE_MODIFIED |
IXGBE_MAC_STATE_IN_USE;
ixgbe_sync_mac_table(adapter);
return i;
}
return -ENOMEM;
}
int ixgbe_del_mac_filter(struct ixgbe_adapter *adapter,
const u8 *addr, u16 pool)
{
struct ixgbe_mac_addr *mac_table = &adapter->mac_table[0];
struct ixgbe_hw *hw = &adapter->hw;
int i;
if (is_zero_ether_addr(addr))
return -EINVAL;
for (i = 0; i < hw->mac.num_rar_entries; i++, mac_table++) {
if (!(mac_table->state & IXGBE_MAC_STATE_IN_USE))
continue;
if (mac_table->pool != pool)
continue;
if (!ether_addr_equal(addr, mac_table->addr))
continue;
mac_table->state |= IXGBE_MAC_STATE_MODIFIED;
mac_table->state &= ~IXGBE_MAC_STATE_IN_USE;
ixgbe_sync_mac_table(adapter);
return 0;
}
return -ENOMEM;
}
static int ixgbe_write_uc_addr_list(struct net_device *netdev, int vfn)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int count = 0;
if (netdev_uc_count(netdev) > ixgbe_available_rars(adapter, vfn))
return -ENOMEM;
if (!netdev_uc_empty(netdev)) {
struct netdev_hw_addr *ha;
netdev_for_each_uc_addr(ha, netdev) {
ixgbe_del_mac_filter(adapter, ha->addr, vfn);
ixgbe_add_mac_filter(adapter, ha->addr, vfn);
count++;
}
}
return count;
}
static int ixgbe_uc_sync(struct net_device *netdev, const unsigned char *addr)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int ret;
ret = ixgbe_add_mac_filter(adapter, addr, VMDQ_P(0));
return min_t(int, ret, 0);
}
static int ixgbe_uc_unsync(struct net_device *netdev, const unsigned char *addr)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
ixgbe_del_mac_filter(adapter, addr, VMDQ_P(0));
return 0;
}
void ixgbe_set_rx_mode(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
u32 fctrl, vmolr = IXGBE_VMOLR_BAM | IXGBE_VMOLR_AUPE;
netdev_features_t features = netdev->features;
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
vmolr |= IXGBE_VMOLR_MPE;
features &= ~NETIF_F_HW_VLAN_CTAG_FILTER;
} else {
if (netdev->flags & IFF_ALLMULTI) {
fctrl |= IXGBE_FCTRL_MPE;
vmolr |= IXGBE_VMOLR_MPE;
}
hw->addr_ctrl.user_set_promisc = false;
}
if (__dev_uc_sync(netdev, ixgbe_uc_sync, ixgbe_uc_unsync)) {
fctrl |= IXGBE_FCTRL_UPE;
vmolr |= IXGBE_VMOLR_ROPE;
}
count = ixgbe_write_mc_addr_list(netdev);
if (count < 0) {
fctrl |= IXGBE_FCTRL_MPE;
vmolr |= IXGBE_VMOLR_MPE;
} else if (count) {
vmolr |= IXGBE_VMOLR_ROMPE;
}
if (hw->mac.type != ixgbe_mac_82598EB) {
vmolr |= IXGBE_READ_REG(hw, IXGBE_VMOLR(VMDQ_P(0))) &
~(IXGBE_VMOLR_MPE | IXGBE_VMOLR_ROMPE |
IXGBE_VMOLR_ROPE);
IXGBE_WRITE_REG(hw, IXGBE_VMOLR(VMDQ_P(0)), vmolr);
}
if (features & NETIF_F_RXALL) {
fctrl |= (IXGBE_FCTRL_SBP |
IXGBE_FCTRL_BAM |
IXGBE_FCTRL_PMCF);
fctrl &= ~(IXGBE_FCTRL_DPF);
}
IXGBE_WRITE_REG(hw, IXGBE_FCTRL, fctrl);
if (features & NETIF_F_HW_VLAN_CTAG_RX)
ixgbe_vlan_strip_enable(adapter);
else
ixgbe_vlan_strip_disable(adapter);
if (features & NETIF_F_HW_VLAN_CTAG_FILTER)
ixgbe_vlan_promisc_disable(adapter);
else
ixgbe_vlan_promisc_enable(adapter);
}
static void ixgbe_napi_enable_all(struct ixgbe_adapter *adapter)
{
int q_idx;
for (q_idx = 0; q_idx < adapter->num_q_vectors; q_idx++)
napi_enable(&adapter->q_vector[q_idx]->napi);
}
static void ixgbe_napi_disable_all(struct ixgbe_adapter *adapter)
{
int q_idx;
for (q_idx = 0; q_idx < adapter->num_q_vectors; q_idx++)
napi_disable(&adapter->q_vector[q_idx]->napi);
}
static void ixgbe_clear_udp_tunnel_port(struct ixgbe_adapter *adapter, u32 mask)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vxlanctrl;
if (!(adapter->flags & (IXGBE_FLAG_VXLAN_OFFLOAD_CAPABLE |
IXGBE_FLAG_GENEVE_OFFLOAD_CAPABLE)))
return;
vxlanctrl = IXGBE_READ_REG(hw, IXGBE_VXLANCTRL) && ~mask;
IXGBE_WRITE_REG(hw, IXGBE_VXLANCTRL, vxlanctrl);
if (mask & IXGBE_VXLANCTRL_VXLAN_UDPPORT_MASK)
adapter->vxlan_port = 0;
if (mask & IXGBE_VXLANCTRL_GENEVE_UDPPORT_MASK)
adapter->geneve_port = 0;
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
static int ixgbe_lpbthresh(struct ixgbe_adapter *adapter, int pb)
{
struct ixgbe_hw *hw = &adapter->hw;
struct net_device *dev = adapter->netdev;
int tc;
u32 dv_id;
tc = dev->mtu + ETH_HLEN + ETH_FCS_LEN;
#ifdef IXGBE_FCOE
if ((dev->features & NETIF_F_FCOE_MTU) &&
(tc < IXGBE_FCOE_JUMBO_FRAME_SIZE) &&
(pb == netdev_get_prio_tc_map(dev, adapter->fcoe.up)))
tc = IXGBE_FCOE_JUMBO_FRAME_SIZE;
#endif
switch (hw->mac.type) {
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
for (i = 0; i < num_tc; i++) {
hw->fc.high_water[i] = ixgbe_hpbthresh(adapter, i);
hw->fc.low_water[i] = ixgbe_lpbthresh(adapter, i);
if (hw->fc.low_water[i] > hw->fc.high_water[i])
hw->fc.low_water[i] = 0;
}
for (; i < MAX_TRAFFIC_CLASS; i++)
hw->fc.high_water[i] = 0;
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
static void ixgbe_macvlan_set_rx_mode(struct net_device *dev, unsigned int pool,
struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vmolr;
vmolr = IXGBE_READ_REG(hw, IXGBE_VMOLR(pool));
vmolr |= (IXGBE_VMOLR_ROMPE | IXGBE_VMOLR_BAM | IXGBE_VMOLR_AUPE);
vmolr &= ~IXGBE_VMOLR_MPE;
if (dev->flags & IFF_ALLMULTI) {
vmolr |= IXGBE_VMOLR_MPE;
} else {
vmolr |= IXGBE_VMOLR_ROMPE;
hw->mac.ops.update_mc_addr_list(hw, dev);
}
ixgbe_write_uc_addr_list(adapter->netdev, pool);
IXGBE_WRITE_REG(hw, IXGBE_VMOLR(pool), vmolr);
}
static void ixgbe_fwd_psrtype(struct ixgbe_fwd_adapter *vadapter)
{
struct ixgbe_adapter *adapter = vadapter->real_adapter;
int rss_i = adapter->num_rx_queues_per_pool;
struct ixgbe_hw *hw = &adapter->hw;
u16 pool = vadapter->pool;
u32 psrtype = IXGBE_PSRTYPE_TCPHDR |
IXGBE_PSRTYPE_UDPHDR |
IXGBE_PSRTYPE_IPV4HDR |
IXGBE_PSRTYPE_L2HDR |
IXGBE_PSRTYPE_IPV6HDR;
if (hw->mac.type == ixgbe_mac_82598EB)
return;
if (rss_i > 3)
psrtype |= 2u << 29;
else if (rss_i > 1)
psrtype |= 1u << 29;
IXGBE_WRITE_REG(hw, IXGBE_PSRTYPE(VMDQ_P(pool)), psrtype);
}
static void ixgbe_clean_rx_ring(struct ixgbe_ring *rx_ring)
{
u16 i = rx_ring->next_to_clean;
struct ixgbe_rx_buffer *rx_buffer = &rx_ring->rx_buffer_info[i];
while (i != rx_ring->next_to_alloc) {
if (rx_buffer->skb) {
struct sk_buff *skb = rx_buffer->skb;
if (IXGBE_CB(skb)->page_released)
dma_unmap_page_attrs(rx_ring->dev,
IXGBE_CB(skb)->dma,
ixgbe_rx_pg_size(rx_ring),
DMA_FROM_DEVICE,
IXGBE_RX_DMA_ATTR);
dev_kfree_skb(skb);
}
dma_sync_single_range_for_cpu(rx_ring->dev,
rx_buffer->dma,
rx_buffer->page_offset,
ixgbe_rx_bufsz(rx_ring),
DMA_FROM_DEVICE);
dma_unmap_page_attrs(rx_ring->dev, rx_buffer->dma,
ixgbe_rx_pg_size(rx_ring),
DMA_FROM_DEVICE,
IXGBE_RX_DMA_ATTR);
__page_frag_cache_drain(rx_buffer->page,
rx_buffer->pagecnt_bias);
i++;
rx_buffer++;
if (i == rx_ring->count) {
i = 0;
rx_buffer = rx_ring->rx_buffer_info;
}
}
rx_ring->next_to_alloc = 0;
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
}
static void ixgbe_disable_fwd_ring(struct ixgbe_fwd_adapter *vadapter,
struct ixgbe_ring *rx_ring)
{
struct ixgbe_adapter *adapter = vadapter->real_adapter;
int index = rx_ring->queue_index + vadapter->rx_base_queue;
ixgbe_disable_rx_queue(adapter, rx_ring);
usleep_range(10000, 20000);
ixgbe_irq_disable_queues(adapter, BIT_ULL(index));
ixgbe_clean_rx_ring(rx_ring);
rx_ring->l2_accel_priv = NULL;
}
static int ixgbe_fwd_ring_down(struct net_device *vdev,
struct ixgbe_fwd_adapter *accel)
{
struct ixgbe_adapter *adapter = accel->real_adapter;
unsigned int rxbase = accel->rx_base_queue;
unsigned int txbase = accel->tx_base_queue;
int i;
netif_tx_stop_all_queues(vdev);
for (i = 0; i < adapter->num_rx_queues_per_pool; i++) {
ixgbe_disable_fwd_ring(accel, adapter->rx_ring[rxbase + i]);
adapter->rx_ring[rxbase + i]->netdev = adapter->netdev;
}
for (i = 0; i < adapter->num_rx_queues_per_pool; i++) {
adapter->tx_ring[txbase + i]->l2_accel_priv = NULL;
adapter->tx_ring[txbase + i]->netdev = adapter->netdev;
}
return 0;
}
static int ixgbe_fwd_ring_up(struct net_device *vdev,
struct ixgbe_fwd_adapter *accel)
{
struct ixgbe_adapter *adapter = accel->real_adapter;
unsigned int rxbase, txbase, queues;
int i, baseq, err = 0;
if (!test_bit(accel->pool, &adapter->fwd_bitmask))
return 0;
baseq = accel->pool * adapter->num_rx_queues_per_pool;
netdev_dbg(vdev, "pool %i:%i queues %i:%i VSI bitmask %lx\n",
accel->pool, adapter->num_rx_pools,
baseq, baseq + adapter->num_rx_queues_per_pool,
adapter->fwd_bitmask);
accel->netdev = vdev;
accel->rx_base_queue = rxbase = baseq;
accel->tx_base_queue = txbase = baseq;
for (i = 0; i < adapter->num_rx_queues_per_pool; i++)
ixgbe_disable_fwd_ring(accel, adapter->rx_ring[rxbase + i]);
for (i = 0; i < adapter->num_rx_queues_per_pool; i++) {
adapter->rx_ring[rxbase + i]->netdev = vdev;
adapter->rx_ring[rxbase + i]->l2_accel_priv = accel;
ixgbe_configure_rx_ring(adapter, adapter->rx_ring[rxbase + i]);
}
for (i = 0; i < adapter->num_rx_queues_per_pool; i++) {
adapter->tx_ring[txbase + i]->netdev = vdev;
adapter->tx_ring[txbase + i]->l2_accel_priv = accel;
}
queues = min_t(unsigned int,
adapter->num_rx_queues_per_pool, vdev->num_tx_queues);
err = netif_set_real_num_tx_queues(vdev, queues);
if (err)
goto fwd_queue_err;
err = netif_set_real_num_rx_queues(vdev, queues);
if (err)
goto fwd_queue_err;
if (is_valid_ether_addr(vdev->dev_addr))
ixgbe_add_mac_filter(adapter, vdev->dev_addr, accel->pool);
ixgbe_fwd_psrtype(accel);
ixgbe_macvlan_set_rx_mode(vdev, accel->pool, adapter);
return err;
fwd_queue_err:
ixgbe_fwd_ring_down(vdev, accel);
return err;
}
static int ixgbe_upper_dev_walk(struct net_device *upper, void *data)
{
if (netif_is_macvlan(upper)) {
struct macvlan_dev *dfwd = netdev_priv(upper);
struct ixgbe_fwd_adapter *vadapter = dfwd->fwd_priv;
if (dfwd->fwd_priv)
ixgbe_fwd_ring_up(upper, vadapter);
}
return 0;
}
static void ixgbe_configure_dfwd(struct ixgbe_adapter *adapter)
{
netdev_walk_all_upper_dev_rcu(adapter->netdev,
ixgbe_upper_dev_walk, NULL);
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
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_CAPABLE)
ixgbe_setup_dca(adapter);
#endif
#ifdef IXGBE_FCOE
ixgbe_configure_fcoe(adapter);
#endif
ixgbe_configure_tx(adapter);
ixgbe_configure_rx(adapter);
ixgbe_configure_dfwd(adapter);
}
static void ixgbe_sfp_link_config(struct ixgbe_adapter *adapter)
{
if (adapter->hw.mac.type == ixgbe_mac_82598EB)
adapter->flags2 |= IXGBE_FLAG2_SEARCH_FOR_SFP;
adapter->flags2 |= IXGBE_FLAG2_SFP_NEEDS_RESET;
adapter->sfp_poll_time = 0;
}
static int ixgbe_non_sfp_link_config(struct ixgbe_hw *hw)
{
u32 speed;
bool autoneg, link_up = false;
int ret = IXGBE_ERR_LINK_SETUP;
if (hw->mac.ops.check_link)
ret = hw->mac.ops.check_link(hw, &speed, &link_up, false);
if (ret)
return ret;
speed = hw->phy.autoneg_advertised;
if ((!speed) && (hw->mac.ops.get_link_capabilities))
ret = hw->mac.ops.get_link_capabilities(hw, &speed,
&autoneg);
if (ret)
return ret;
if (hw->mac.ops.setup_link)
ret = hw->mac.ops.setup_link(hw, speed, link_up);
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
gpie |= IXGBE_SDP0_GPIEN_8259X;
break;
default:
break;
}
}
if (adapter->flags & IXGBE_FLAG_FAN_FAIL_CAPABLE)
gpie |= IXGBE_SDP1_GPIEN(hw);
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
gpie |= IXGBE_SDP1_GPIEN_8259X | IXGBE_SDP2_GPIEN_8259X;
break;
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
gpie |= IXGBE_SDP0_GPIEN_X540;
break;
default:
break;
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
if (hw->phy.ops.set_phy_power)
hw->phy.ops.set_phy_power(hw, true);
smp_mb__before_atomic();
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
netif_trans_update(adapter->netdev);
while (test_and_set_bit(__IXGBE_RESETTING, &adapter->state))
usleep_range(1000, 2000);
if (adapter->hw.phy.type == ixgbe_phy_fw)
ixgbe_watchdog_link_is_down(adapter);
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
struct net_device *netdev = adapter->netdev;
int err;
if (ixgbe_removed(hw->hw_addr))
return;
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
ixgbe_flush_sw_mac_table(adapter);
__dev_uc_unsync(netdev, NULL);
ixgbe_mac_set_default_filter(adapter);
if (hw->mac.san_mac_rar_index)
hw->mac.ops.set_vmdq_san_mac(hw, VMDQ_P(0));
if (test_bit(__IXGBE_PTP_RUNNING, &adapter->state))
ixgbe_ptp_reset(adapter);
if (hw->phy.ops.set_phy_power) {
if (!netif_running(adapter->netdev) && !adapter->wol)
hw->phy.ops.set_phy_power(hw, false);
else
hw->phy.ops.set_phy_power(hw, true);
}
}
static void ixgbe_clean_tx_ring(struct ixgbe_ring *tx_ring)
{
u16 i = tx_ring->next_to_clean;
struct ixgbe_tx_buffer *tx_buffer = &tx_ring->tx_buffer_info[i];
while (i != tx_ring->next_to_use) {
union ixgbe_adv_tx_desc *eop_desc, *tx_desc;
if (ring_is_xdp(tx_ring))
page_frag_free(tx_buffer->data);
else
dev_kfree_skb_any(tx_buffer->skb);
dma_unmap_single(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
eop_desc = tx_buffer->next_to_watch;
tx_desc = IXGBE_TX_DESC(tx_ring, i);
while (tx_desc != eop_desc) {
tx_buffer++;
tx_desc++;
i++;
if (unlikely(i == tx_ring->count)) {
i = 0;
tx_buffer = tx_ring->tx_buffer_info;
tx_desc = IXGBE_TX_DESC(tx_ring, 0);
}
if (dma_unmap_len(tx_buffer, len))
dma_unmap_page(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
}
tx_buffer++;
i++;
if (unlikely(i == tx_ring->count)) {
i = 0;
tx_buffer = tx_ring->tx_buffer_info;
}
}
if (!ring_is_xdp(tx_ring))
netdev_tx_reset_queue(txring_txq(tx_ring));
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
for (i = 0; i < adapter->num_xdp_queues; i++)
ixgbe_clean_tx_ring(adapter->xdp_ring[i]);
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
static int ixgbe_disable_macvlan(struct net_device *upper, void *data)
{
if (netif_is_macvlan(upper)) {
struct macvlan_dev *vlan = netdev_priv(upper);
if (vlan->fwd_priv) {
netif_tx_stop_all_queues(upper);
netif_carrier_off(upper);
netif_tx_disable(upper);
}
}
return 0;
}
void ixgbe_down(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
int i;
if (test_and_set_bit(__IXGBE_DOWN, &adapter->state))
return;
hw->mac.ops.disable_rx(hw);
for (i = 0; i < adapter->num_rx_queues; i++)
ixgbe_disable_rx_queue(adapter, adapter->rx_ring[i]);
usleep_range(10000, 20000);
netif_tx_stop_all_queues(netdev);
netif_carrier_off(netdev);
netif_tx_disable(netdev);
netdev_walk_all_upper_dev_rcu(adapter->netdev,
ixgbe_disable_macvlan, NULL);
ixgbe_irq_disable(adapter);
ixgbe_napi_disable_all(adapter);
clear_bit(__IXGBE_RESET_REQUESTED, &adapter->state);
adapter->flags2 &= ~IXGBE_FLAG2_FDIR_REQUIRES_REINIT;
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
for (i = 0; i < adapter->num_xdp_queues; i++) {
u8 reg_idx = adapter->xdp_ring[i]->reg_idx;
IXGBE_WRITE_REG(hw, IXGBE_TXDCTL(reg_idx), IXGBE_TXDCTL_SWFLSH);
}
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
}
static void ixgbe_set_eee_capable(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_A_1G_T:
case IXGBE_DEV_ID_X550EM_A_1G_T_L:
if (!hw->phy.eee_speeds_supported)
break;
adapter->flags2 |= IXGBE_FLAG2_EEE_CAPABLE;
if (!hw->phy.eee_speeds_advertised)
break;
adapter->flags2 |= IXGBE_FLAG2_EEE_ENABLED;
break;
default:
adapter->flags2 &= ~IXGBE_FLAG2_EEE_CAPABLE;
adapter->flags2 &= ~IXGBE_FLAG2_EEE_ENABLED;
break;
}
}
static void ixgbe_tx_timeout(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
ixgbe_tx_timeout_reset(adapter);
}
static void ixgbe_init_dcb(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct tc_configuration *tc;
int j;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
case ixgbe_mac_82599EB:
adapter->dcb_cfg.num_tcs.pg_tcs = MAX_TRAFFIC_CLASS;
adapter->dcb_cfg.num_tcs.pfc_tcs = MAX_TRAFFIC_CLASS;
break;
case ixgbe_mac_X540:
case ixgbe_mac_X550:
adapter->dcb_cfg.num_tcs.pg_tcs = X540_TRAFFIC_CLASS;
adapter->dcb_cfg.num_tcs.pfc_tcs = X540_TRAFFIC_CLASS;
break;
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
default:
adapter->dcb_cfg.num_tcs.pg_tcs = DEF_TRAFFIC_CLASS;
adapter->dcb_cfg.num_tcs.pfc_tcs = DEF_TRAFFIC_CLASS;
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
if (adapter->flags & IXGBE_FLAG_DCB_CAPABLE)
adapter->dcbx_cap = DCB_CAP_DCBX_HOST | DCB_CAP_DCBX_VER_CEE;
memcpy(&adapter->temp_dcb_cfg, &adapter->dcb_cfg,
sizeof(adapter->temp_dcb_cfg));
}
static int ixgbe_sw_init(struct ixgbe_adapter *adapter,
const struct ixgbe_info *ii)
{
struct ixgbe_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
unsigned int rss, fdir;
u32 fwsm;
int i;
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
hw->revision_id = pdev->revision;
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
ii->get_invariants(hw);
rss = min_t(int, ixgbe_max_rss_indices(adapter), num_online_cpus());
adapter->ring_feature[RING_F_RSS].limit = rss;
adapter->flags2 |= IXGBE_FLAG2_RSC_CAPABLE;
adapter->max_q_vectors = MAX_Q_VECTORS_82599;
adapter->atr_sample_rate = 20;
fdir = min_t(int, IXGBE_MAX_FDIR_INDICES, num_online_cpus());
adapter->ring_feature[RING_F_FDIR].limit = fdir;
adapter->fdir_pballoc = IXGBE_FDIR_PBALLOC_64K;
#ifdef CONFIG_IXGBE_DCA
adapter->flags |= IXGBE_FLAG_DCA_CAPABLE;
#endif
#ifdef CONFIG_IXGBE_DCB
adapter->flags |= IXGBE_FLAG_DCB_CAPABLE;
adapter->flags &= ~IXGBE_FLAG_DCB_ENABLED;
#endif
#ifdef IXGBE_FCOE
adapter->flags |= IXGBE_FLAG_FCOE_CAPABLE;
adapter->flags &= ~IXGBE_FLAG_FCOE_ENABLED;
#ifdef CONFIG_IXGBE_DCB
adapter->fcoe.up = IXGBE_FCOE_DEFTC;
#endif
#endif
adapter->jump_tables[0] = kzalloc(sizeof(*adapter->jump_tables[0]),
GFP_KERNEL);
if (!adapter->jump_tables[0])
return -ENOMEM;
adapter->jump_tables[0]->mat = ixgbe_ipv4_fields;
for (i = 1; i < IXGBE_MAX_LINK_HANDLE; i++)
adapter->jump_tables[i] = NULL;
adapter->mac_table = kzalloc(sizeof(struct ixgbe_mac_addr) *
hw->mac.num_rar_entries,
GFP_ATOMIC);
if (!adapter->mac_table)
return -ENOMEM;
if (ixgbe_init_rss_key(adapter))
return -ENOMEM;
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
adapter->flags2 &= ~IXGBE_FLAG2_RSC_CAPABLE;
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
fwsm = IXGBE_READ_REG(hw, IXGBE_FWSM(hw));
if (fwsm & IXGBE_FWSM_TS_ENABLED)
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_CAPABLE;
break;
case ixgbe_mac_x550em_a:
adapter->flags |= IXGBE_FLAG_GENEVE_OFFLOAD_CAPABLE;
switch (hw->device_id) {
case IXGBE_DEV_ID_X550EM_A_1G_T:
case IXGBE_DEV_ID_X550EM_A_1G_T_L:
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_CAPABLE;
break;
default:
break;
}
case ixgbe_mac_X550EM_x:
#ifdef CONFIG_IXGBE_DCB
adapter->flags &= ~IXGBE_FLAG_DCB_CAPABLE;
#endif
#ifdef IXGBE_FCOE
adapter->flags &= ~IXGBE_FLAG_FCOE_CAPABLE;
#ifdef CONFIG_IXGBE_DCB
adapter->fcoe.up = 0;
#endif
#endif
case ixgbe_mac_X550:
if (hw->mac.type == ixgbe_mac_X550)
adapter->flags2 |= IXGBE_FLAG2_TEMP_SENSOR_CAPABLE;
#ifdef CONFIG_IXGBE_DCA
adapter->flags &= ~IXGBE_FLAG_DCA_CAPABLE;
#endif
adapter->flags |= IXGBE_FLAG_VXLAN_OFFLOAD_CAPABLE;
break;
default:
break;
}
#ifdef IXGBE_FCOE
spin_lock_init(&adapter->fcoe.lock);
#endif
spin_lock_init(&adapter->fdir_perfect_lock);
#ifdef CONFIG_IXGBE_DCB
ixgbe_init_dcb(adapter);
#endif
hw->fc.requested_mode = ixgbe_fc_full;
hw->fc.current_mode = ixgbe_fc_full;
ixgbe_pbthresh_setup(adapter);
hw->fc.pause_time = IXGBE_DEFAULT_FCPAUSE;
hw->fc.send_xon = true;
hw->fc.disable_fc_autoneg = ixgbe_device_supports_autoneg_fc(hw);
#ifdef CONFIG_PCI_IOV
if (max_vfs > 0)
e_dev_warn("Enabling SR-IOV VFs using the max_vfs module parameter is deprecated - please use the pci sysfs interface instead.\n");
if (hw->mac.type != ixgbe_mac_82598EB) {
if (max_vfs > IXGBE_MAX_VFS_DRV_LIMIT) {
max_vfs = 0;
e_dev_warn("max_vfs parameter out of range. Not assigning any SR-IOV VFs\n");
}
}
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
set_bit(0, &adapter->fwd_bitmask);
set_bit(__IXGBE_DOWN, &adapter->state);
return 0;
}
int ixgbe_setup_tx_resources(struct ixgbe_ring *tx_ring)
{
struct device *dev = tx_ring->dev;
int orig_node = dev_to_node(dev);
int ring_node = -1;
int size;
size = sizeof(struct ixgbe_tx_buffer) * tx_ring->count;
if (tx_ring->q_vector)
ring_node = tx_ring->q_vector->numa_node;
tx_ring->tx_buffer_info = vmalloc_node(size, ring_node);
if (!tx_ring->tx_buffer_info)
tx_ring->tx_buffer_info = vmalloc(size);
if (!tx_ring->tx_buffer_info)
goto err;
u64_stats_init(&tx_ring->syncp);
tx_ring->size = tx_ring->count * sizeof(union ixgbe_adv_tx_desc);
tx_ring->size = ALIGN(tx_ring->size, 4096);
set_dev_node(dev, ring_node);
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
int i, j = 0, err = 0;
for (i = 0; i < adapter->num_tx_queues; i++) {
err = ixgbe_setup_tx_resources(adapter->tx_ring[i]);
if (!err)
continue;
e_err(probe, "Allocation for Tx Queue %u failed\n", i);
goto err_setup_tx;
}
for (j = 0; j < adapter->num_xdp_queues; j++) {
err = ixgbe_setup_tx_resources(adapter->xdp_ring[j]);
if (!err)
continue;
e_err(probe, "Allocation for Tx Queue %u failed\n", j);
goto err_setup_tx;
}
return 0;
err_setup_tx:
while (j--)
ixgbe_free_tx_resources(adapter->xdp_ring[j]);
while (i--)
ixgbe_free_tx_resources(adapter->tx_ring[i]);
return err;
}
int ixgbe_setup_rx_resources(struct ixgbe_adapter *adapter,
struct ixgbe_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
int orig_node = dev_to_node(dev);
int ring_node = -1;
int size;
size = sizeof(struct ixgbe_rx_buffer) * rx_ring->count;
if (rx_ring->q_vector)
ring_node = rx_ring->q_vector->numa_node;
rx_ring->rx_buffer_info = vmalloc_node(size, ring_node);
if (!rx_ring->rx_buffer_info)
rx_ring->rx_buffer_info = vmalloc(size);
if (!rx_ring->rx_buffer_info)
goto err;
u64_stats_init(&rx_ring->syncp);
rx_ring->size = rx_ring->count * sizeof(union ixgbe_adv_rx_desc);
rx_ring->size = ALIGN(rx_ring->size, 4096);
set_dev_node(dev, ring_node);
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
rx_ring->xdp_prog = adapter->xdp_prog;
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
err = ixgbe_setup_rx_resources(adapter, adapter->rx_ring[i]);
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
for (i = 0; i < adapter->num_xdp_queues; i++)
if (adapter->xdp_ring[i]->desc)
ixgbe_free_tx_resources(adapter->xdp_ring[i]);
}
void ixgbe_free_rx_resources(struct ixgbe_ring *rx_ring)
{
ixgbe_clean_rx_ring(rx_ring);
rx_ring->xdp_prog = NULL;
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
if ((adapter->flags & IXGBE_FLAG_SRIOV_ENABLED) &&
(adapter->hw.mac.type == ixgbe_mac_82599EB) &&
(new_mtu > ETH_DATA_LEN))
e_warn(probe, "Setting MTU > 1500 will disable legacy VFs\n");
e_info(probe, "changing MTU from %d to %d\n", netdev->mtu, new_mtu);
netdev->mtu = new_mtu;
if (netif_running(netdev))
ixgbe_reinit_locked(adapter);
return 0;
}
int ixgbe_open(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int err, queues;
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
if (adapter->num_rx_pools > 1)
queues = adapter->num_rx_queues_per_pool;
else
queues = adapter->num_tx_queues;
err = netif_set_real_num_tx_queues(netdev, queues);
if (err)
goto err_set_queues;
if (adapter->num_rx_pools > 1 &&
adapter->num_rx_queues > IXGBE_MAX_L2A_QUEUES)
queues = IXGBE_MAX_L2A_QUEUES;
else
queues = adapter->num_rx_queues;
err = netif_set_real_num_rx_queues(netdev, queues);
if (err)
goto err_set_queues;
ixgbe_ptp_init(adapter);
ixgbe_up_complete(adapter);
ixgbe_clear_udp_tunnel_port(adapter, IXGBE_VXLANCTRL_ALL_UDPPORT_MASK);
udp_tunnel_get_rx_info(netdev);
return 0;
err_set_queues:
ixgbe_free_irq(adapter);
err_req_irq:
ixgbe_free_all_rx_resources(adapter);
if (hw->phy.ops.set_phy_power && !adapter->wol)
hw->phy.ops.set_phy_power(&adapter->hw, false);
err_setup_rx:
ixgbe_free_all_tx_resources(adapter);
err_setup_tx:
ixgbe_reset(adapter);
return err;
}
static void ixgbe_close_suspend(struct ixgbe_adapter *adapter)
{
ixgbe_ptp_suspend(adapter);
if (adapter->hw.phy.ops.enter_lplu) {
adapter->hw.phy.reset_disable = true;
ixgbe_down(adapter);
adapter->hw.phy.ops.enter_lplu(&adapter->hw);
adapter->hw.phy.reset_disable = false;
} else {
ixgbe_down(adapter);
}
ixgbe_free_irq(adapter);
ixgbe_free_all_tx_resources(adapter);
ixgbe_free_all_rx_resources(adapter);
}
int ixgbe_close(struct net_device *netdev)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
ixgbe_ptp_stop(adapter);
if (netif_device_present(netdev))
ixgbe_close_suspend(adapter);
ixgbe_fdir_filter_exit(adapter);
ixgbe_release_hw_control(adapter);
return 0;
}
static int ixgbe_resume(struct pci_dev *pdev)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
u32 err;
adapter->hw.hw_addr = adapter->io_addr;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
pci_save_state(pdev);
err = pci_enable_device_mem(pdev);
if (err) {
e_dev_err("Cannot enable PCI device from suspend\n");
return err;
}
smp_mb__before_atomic();
clear_bit(__IXGBE_DISABLED, &adapter->state);
pci_set_master(pdev);
pci_wake_from_d3(pdev, false);
ixgbe_reset(adapter);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_WUS, ~0);
rtnl_lock();
err = ixgbe_init_interrupt_scheme(adapter);
if (!err && netif_running(netdev))
err = ixgbe_open(netdev);
if (!err)
netif_device_attach(netdev);
rtnl_unlock();
return err;
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
rtnl_lock();
netif_device_detach(netdev);
if (netif_running(netdev))
ixgbe_close_suspend(adapter);
ixgbe_clear_interrupt_scheme(adapter);
rtnl_unlock();
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
pci_wake_from_d3(pdev, !!wufc);
break;
default:
break;
}
*enable_wake = !!wufc;
if (hw->phy.ops.set_phy_power && !*enable_wake)
hw->phy.ops.set_phy_power(hw, false);
ixgbe_release_hw_control(adapter);
if (!test_and_set_bit(__IXGBE_DISABLED, &adapter->state))
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
for (i = 0; i < adapter->num_xdp_queues; i++) {
struct ixgbe_ring *xdp_ring = adapter->xdp_ring[i];
restart_queue += xdp_ring->tx_stats.restart_queue;
tx_busy += xdp_ring->tx_stats.tx_busy;
bytes += xdp_ring->stats.bytes;
packets += xdp_ring->stats.packets;
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
(hw->mac.type == ixgbe_mac_X540) ||
(hw->mac.type == ixgbe_mac_X550) ||
(hw->mac.type == ixgbe_mac_X550EM_x) ||
(hw->mac.type == ixgbe_mac_x550em_a)) {
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
for (i = 0; i < adapter->num_xdp_queues; i++)
set_bit(__IXGBE_TX_FDIR_INIT_DONE,
&adapter->xdp_ring[i]->state);
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
test_bit(__IXGBE_REMOVING, &adapter->state) ||
test_bit(__IXGBE_RESETTING, &adapter->state))
return;
if (netif_carrier_ok(adapter->netdev)) {
for (i = 0; i < adapter->num_tx_queues; i++)
set_check_for_tx_hang(adapter->tx_ring[i]);
for (i = 0; i < adapter->num_xdp_queues; i++)
set_check_for_tx_hang(adapter->xdp_ring[i]);
}
if (!(adapter->flags & IXGBE_FLAG_MSIX_ENABLED)) {
IXGBE_WRITE_REG(hw, IXGBE_EICS,
(IXGBE_EICS_TCP_TIMER | IXGBE_EICS_OTHER));
} else {
for (i = 0; i < adapter->num_q_vectors; i++) {
struct ixgbe_q_vector *qv = adapter->q_vector[i];
if (qv->rx.ring || qv->tx.ring)
eics |= BIT_ULL(i);
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
static int ixgbe_enable_macvlan(struct net_device *upper, void *data)
{
if (netif_is_macvlan(upper)) {
struct macvlan_dev *vlan = netdev_priv(upper);
if (vlan->fwd_priv)
netif_tx_wake_all_queues(upper);
}
return 0;
}
static void ixgbe_watchdog_link_is_up(struct ixgbe_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct ixgbe_hw *hw = &adapter->hw;
u32 link_speed = adapter->link_speed;
const char *speed_str;
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
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
switch (link_speed) {
case IXGBE_LINK_SPEED_10GB_FULL:
speed_str = "10 Gbps";
break;
case IXGBE_LINK_SPEED_2_5GB_FULL:
speed_str = "2.5 Gbps";
break;
case IXGBE_LINK_SPEED_1GB_FULL:
speed_str = "1 Gbps";
break;
case IXGBE_LINK_SPEED_100_FULL:
speed_str = "100 Mbps";
break;
case IXGBE_LINK_SPEED_10_FULL:
speed_str = "10 Mbps";
break;
default:
speed_str = "unknown speed";
break;
}
e_info(drv, "NIC Link is Up %s, Flow Control: %s\n", speed_str,
((flow_rx && flow_tx) ? "RX/TX" :
(flow_rx ? "RX" :
(flow_tx ? "TX" : "None"))));
netif_carrier_on(netdev);
ixgbe_check_vf_rate_limit(adapter);
netif_tx_wake_all_queues(adapter->netdev);
rtnl_lock();
netdev_walk_all_upper_dev_rcu(adapter->netdev,
ixgbe_enable_macvlan, NULL);
rtnl_unlock();
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
static bool ixgbe_ring_tx_pending(struct ixgbe_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++) {
struct ixgbe_ring *tx_ring = adapter->tx_ring[i];
if (tx_ring->next_to_use != tx_ring->next_to_clean)
return true;
}
for (i = 0; i < adapter->num_xdp_queues; i++) {
struct ixgbe_ring *ring = adapter->xdp_ring[i];
if (ring->next_to_use != ring->next_to_clean)
return true;
}
return false;
}
static bool ixgbe_vf_tx_pending(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_ring_feature *vmdq = &adapter->ring_feature[RING_F_VMDQ];
u32 q_per_pool = __ALIGN_MASK(1, ~vmdq->mask);
int i, j;
if (!adapter->num_vfs)
return false;
if (hw->mac.type >= ixgbe_mac_X550)
return false;
for (i = 0; i < adapter->num_vfs; i++) {
for (j = 0; j < q_per_pool; j++) {
u32 h, t;
h = IXGBE_READ_REG(hw, IXGBE_PVFTDHN(q_per_pool, i, j));
t = IXGBE_READ_REG(hw, IXGBE_PVFTDTN(q_per_pool, i, j));
if (h != t)
return true;
}
}
return false;
}
static void ixgbe_watchdog_flush_tx(struct ixgbe_adapter *adapter)
{
if (!netif_carrier_ok(adapter->netdev)) {
if (ixgbe_ring_tx_pending(adapter) ||
ixgbe_vf_tx_pending(adapter)) {
e_warn(drv, "initiating reset to clear Tx work after link loss\n");
set_bit(__IXGBE_RESET_REQUESTED, &adapter->state);
}
}
}
static void ixgbe_check_for_bad_vf(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
unsigned int vf;
u32 gpc;
if (!(netif_carrier_ok(adapter->netdev)))
return;
gpc = IXGBE_READ_REG(hw, IXGBE_TXDGPC);
if (gpc)
return;
if (!pdev)
return;
for (vf = 0; vf < adapter->num_vfs; ++vf) {
struct pci_dev *vfdev = adapter->vfinfo[vf].vfdev;
u16 status_reg;
if (!vfdev)
continue;
pci_read_config_word(vfdev, PCI_STATUS, &status_reg);
if (status_reg != IXGBE_FAILED_READ_CFG_WORD &&
status_reg & PCI_STATUS_REC_MASTER_ABORT)
pcie_flr(vfdev);
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
static void ixgbe_spoof_check(struct ixgbe_adapter __always_unused *adapter)
{
}
static void
ixgbe_check_for_bad_vf(struct ixgbe_adapter __always_unused *adapter)
{
}
static void ixgbe_watchdog_subtask(struct ixgbe_adapter *adapter)
{
if (test_bit(__IXGBE_DOWN, &adapter->state) ||
test_bit(__IXGBE_REMOVING, &adapter->state) ||
test_bit(__IXGBE_RESETTING, &adapter->state))
return;
ixgbe_watchdog_update_link(adapter);
if (adapter->link_up)
ixgbe_watchdog_link_is_up(adapter);
else
ixgbe_watchdog_link_is_down(adapter);
ixgbe_check_for_bad_vf(adapter);
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
if (adapter->sfp_poll_time &&
time_after(adapter->sfp_poll_time, jiffies))
return;
if (test_and_set_bit(__IXGBE_IN_SFP_INIT, &adapter->state))
return;
adapter->sfp_poll_time = jiffies + IXGBE_SFP_POLL_JIFFIES - 1;
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
static void ixgbe_phy_interrupt_subtask(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 status;
if (!(adapter->flags2 & IXGBE_FLAG2_PHY_INTERRUPT))
return;
adapter->flags2 &= ~IXGBE_FLAG2_PHY_INTERRUPT;
if (!hw->phy.ops.handle_lasi)
return;
status = hw->phy.ops.handle_lasi(&adapter->hw);
if (status != IXGBE_ERR_OVERTEMP)
return;
e_crit(drv, "%s\n", ixgbe_overheat_msg);
}
static void ixgbe_reset_subtask(struct ixgbe_adapter *adapter)
{
if (!test_and_clear_bit(__IXGBE_RESET_REQUESTED, &adapter->state))
return;
if (test_bit(__IXGBE_DOWN, &adapter->state) ||
test_bit(__IXGBE_REMOVING, &adapter->state) ||
test_bit(__IXGBE_RESETTING, &adapter->state))
return;
ixgbe_dump(adapter);
netdev_err(adapter->netdev, "Reset adapter\n");
adapter->tx_timeout_count++;
rtnl_lock();
ixgbe_reinit_locked(adapter);
rtnl_unlock();
}
static void ixgbe_service_task(struct work_struct *work)
{
struct ixgbe_adapter *adapter = container_of(work,
struct ixgbe_adapter,
service_task);
if (ixgbe_removed(adapter->hw.hw_addr)) {
if (!test_bit(__IXGBE_DOWN, &adapter->state)) {
rtnl_lock();
ixgbe_down(adapter);
rtnl_unlock();
}
ixgbe_service_event_complete(adapter);
return;
}
if (adapter->flags2 & IXGBE_FLAG2_UDP_TUN_REREG_NEEDED) {
rtnl_lock();
adapter->flags2 &= ~IXGBE_FLAG2_UDP_TUN_REREG_NEEDED;
udp_tunnel_get_rx_info(adapter->netdev);
rtnl_unlock();
}
ixgbe_reset_subtask(adapter);
ixgbe_phy_interrupt_subtask(adapter);
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
u32 vlan_macip_lens, type_tucmd, mss_l4len_idx;
struct sk_buff *skb = first->skb;
union {
struct iphdr *v4;
struct ipv6hdr *v6;
unsigned char *hdr;
} ip;
union {
struct tcphdr *tcp;
unsigned char *hdr;
} l4;
u32 paylen, l4_offset;
int err;
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (!skb_is_gso(skb))
return 0;
err = skb_cow_head(skb, 0);
if (err < 0)
return err;
ip.hdr = skb_network_header(skb);
l4.hdr = skb_checksum_start(skb);
type_tucmd = IXGBE_ADVTXD_TUCMD_L4T_TCP;
if (ip.v4->version == 4) {
unsigned char *csum_start = skb_checksum_start(skb);
unsigned char *trans_start = ip.hdr + (ip.v4->ihl * 4);
ip.v4->check = csum_fold(csum_partial(trans_start,
csum_start - trans_start,
0));
type_tucmd |= IXGBE_ADVTXD_TUCMD_IPV4;
ip.v4->tot_len = 0;
first->tx_flags |= IXGBE_TX_FLAGS_TSO |
IXGBE_TX_FLAGS_CSUM |
IXGBE_TX_FLAGS_IPV4;
} else {
ip.v6->payload_len = 0;
first->tx_flags |= IXGBE_TX_FLAGS_TSO |
IXGBE_TX_FLAGS_CSUM;
}
l4_offset = l4.hdr - skb->data;
*hdr_len = (l4.tcp->doff * 4) + l4_offset;
paylen = skb->len - l4_offset;
csum_replace_by_diff(&l4.tcp->check, htonl(paylen));
first->gso_segs = skb_shinfo(skb)->gso_segs;
first->bytecount += (first->gso_segs - 1) * *hdr_len;
mss_l4len_idx = (*hdr_len - l4_offset) << IXGBE_ADVTXD_L4LEN_SHIFT;
mss_l4len_idx |= skb_shinfo(skb)->gso_size << IXGBE_ADVTXD_MSS_SHIFT;
vlan_macip_lens = l4.hdr - ip.hdr;
vlan_macip_lens |= (ip.hdr - skb->data) << IXGBE_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= first->tx_flags & IXGBE_TX_FLAGS_VLAN_MASK;
ixgbe_tx_ctxtdesc(tx_ring, vlan_macip_lens, 0, type_tucmd,
mss_l4len_idx);
return 1;
}
static inline bool ixgbe_ipv6_csum_is_sctp(struct sk_buff *skb)
{
unsigned int offset = 0;
ipv6_find_hdr(skb, &offset, IPPROTO_SCTP, NULL, NULL);
return offset == skb_checksum_start_offset(skb);
}
static void ixgbe_tx_csum(struct ixgbe_ring *tx_ring,
struct ixgbe_tx_buffer *first)
{
struct sk_buff *skb = first->skb;
u32 vlan_macip_lens = 0;
u32 type_tucmd = 0;
if (skb->ip_summed != CHECKSUM_PARTIAL) {
csum_failed:
if (!(first->tx_flags & (IXGBE_TX_FLAGS_HW_VLAN |
IXGBE_TX_FLAGS_CC)))
return;
goto no_csum;
}
switch (skb->csum_offset) {
case offsetof(struct tcphdr, check):
type_tucmd = IXGBE_ADVTXD_TUCMD_L4T_TCP;
case offsetof(struct udphdr, check):
break;
case offsetof(struct sctphdr, checksum):
if (((first->protocol == htons(ETH_P_IP)) &&
(ip_hdr(skb)->protocol == IPPROTO_SCTP)) ||
((first->protocol == htons(ETH_P_IPV6)) &&
ixgbe_ipv6_csum_is_sctp(skb))) {
type_tucmd = IXGBE_ADVTXD_TUCMD_L4T_SCTP;
break;
}
default:
skb_checksum_help(skb);
goto csum_failed;
}
first->tx_flags |= IXGBE_TX_FLAGS_CSUM;
vlan_macip_lens = skb_checksum_start_offset(skb) -
skb_network_offset(skb);
no_csum:
vlan_macip_lens |= skb_network_offset(skb) << IXGBE_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= first->tx_flags & IXGBE_TX_FLAGS_VLAN_MASK;
ixgbe_tx_ctxtdesc(tx_ring, vlan_macip_lens, 0, type_tucmd, 0);
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
ixgbe_maybe_stop_tx(tx_ring, DESC_NEEDED);
if (netif_xmit_stopped(txring_txq(tx_ring)) || !skb->xmit_more) {
writel(i, tx_ring->tail);
mmiowb();
}
return;
dma_error:
dev_err(tx_ring->dev, "TX DMA map failed\n");
tx_buffer = &tx_ring->tx_buffer_info[i];
while (tx_buffer != first) {
if (dma_unmap_len(tx_buffer, len))
dma_unmap_page(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
dma_unmap_len_set(tx_buffer, len, 0);
if (i--)
i += tx_ring->count;
tx_buffer = &tx_ring->tx_buffer_info[i];
}
if (dma_unmap_len(tx_buffer, len))
dma_unmap_single(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
dma_unmap_len_set(tx_buffer, len, 0);
dev_kfree_skb_any(first->skb);
first->skb = NULL;
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
unsigned int hlen;
struct sk_buff *skb;
__be16 vlan_id;
int l4_proto;
if (!q_vector)
return;
if (!ring->atr_sample_rate)
return;
ring->atr_count++;
if ((first->protocol != htons(ETH_P_IP)) &&
(first->protocol != htons(ETH_P_IPV6)))
return;
skb = first->skb;
hdr.network = skb_network_header(skb);
if (unlikely(hdr.network <= skb->data))
return;
if (skb->encapsulation &&
first->protocol == htons(ETH_P_IP) &&
hdr.ipv4->protocol == IPPROTO_UDP) {
struct ixgbe_adapter *adapter = q_vector->adapter;
if (unlikely(skb_tail_pointer(skb) < hdr.network +
VXLAN_HEADROOM))
return;
if (adapter->vxlan_port &&
udp_hdr(skb)->dest == adapter->vxlan_port)
hdr.network = skb_inner_network_header(skb);
if (adapter->geneve_port &&
udp_hdr(skb)->dest == adapter->geneve_port)
hdr.network = skb_inner_network_header(skb);
}
if (unlikely(skb_tail_pointer(skb) < hdr.network + 40))
return;
switch (hdr.ipv4->version) {
case IPVERSION:
hlen = (hdr.network[0] & 0x0F) << 2;
l4_proto = hdr.ipv4->protocol;
break;
case 6:
hlen = hdr.network - skb->data;
l4_proto = ipv6_find_hdr(skb, &hlen, IPPROTO_TCP, NULL, NULL);
hlen -= hdr.network - skb->data;
break;
default:
return;
}
if (l4_proto != IPPROTO_TCP)
return;
if (unlikely(skb_tail_pointer(skb) < hdr.network +
hlen + sizeof(struct tcphdr)))
return;
th = (struct tcphdr *)(hdr.network + hlen);
if (th->fin)
return;
if (!th->syn && (ring->atr_count < ring->atr_sample_rate))
return;
ring->atr_count = 0;
vlan_id = htons(first->tx_flags >> IXGBE_TX_FLAGS_VLAN_SHIFT);
input.formatted.vlan_id = vlan_id;
if (first->tx_flags & (IXGBE_TX_FLAGS_SW_VLAN | IXGBE_TX_FLAGS_HW_VLAN))
common.port.src ^= th->dest ^ htons(ETH_P_8021Q);
else
common.port.src ^= th->dest ^ first->protocol;
common.port.dst ^= th->source;
switch (hdr.ipv4->version) {
case IPVERSION:
input.formatted.flow_type = IXGBE_ATR_FLOW_TYPE_TCPV4;
common.ip ^= hdr.ipv4->saddr ^ hdr.ipv4->daddr;
break;
case 6:
input.formatted.flow_type = IXGBE_ATR_FLOW_TYPE_TCPV6;
common.ip ^= hdr.ipv6->saddr.s6_addr32[0] ^
hdr.ipv6->saddr.s6_addr32[1] ^
hdr.ipv6->saddr.s6_addr32[2] ^
hdr.ipv6->saddr.s6_addr32[3] ^
hdr.ipv6->daddr.s6_addr32[0] ^
hdr.ipv6->daddr.s6_addr32[1] ^
hdr.ipv6->daddr.s6_addr32[2] ^
hdr.ipv6->daddr.s6_addr32[3];
break;
default:
break;
}
if (hdr.network != skb_network_header(skb))
input.formatted.flow_type |= IXGBE_ATR_L4TYPE_TUNNEL_MASK;
ixgbe_fdir_add_signature_filter_82599(&q_vector->adapter->hw,
input, common, ring->queue_index);
}
static u16 ixgbe_select_queue(struct net_device *dev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
struct ixgbe_fwd_adapter *fwd_adapter = accel_priv;
#ifdef IXGBE_FCOE
struct ixgbe_adapter *adapter;
struct ixgbe_ring_feature *f;
int txq;
#endif
if (fwd_adapter)
return skb->queue_mapping + fwd_adapter->tx_base_queue;
#ifdef IXGBE_FCOE
switch (vlan_get_protocol(skb)) {
case htons(ETH_P_FCOE):
case htons(ETH_P_FIP):
adapter = netdev_priv(dev);
if (adapter->flags & IXGBE_FLAG_FCOE_ENABLED)
break;
default:
return fallback(dev, skb);
}
f = &adapter->ring_feature[RING_F_FCOE];
txq = skb_rx_queue_recorded(skb) ? skb_get_rx_queue(skb) :
smp_processor_id();
while (txq >= f->indices)
txq -= f->indices;
return txq + f->offset;
#else
return fallback(dev, skb);
#endif
}
static int ixgbe_xmit_xdp_ring(struct ixgbe_adapter *adapter,
struct xdp_buff *xdp)
{
struct ixgbe_ring *ring = adapter->xdp_ring[smp_processor_id()];
struct ixgbe_tx_buffer *tx_buffer;
union ixgbe_adv_tx_desc *tx_desc;
u32 len, cmd_type;
dma_addr_t dma;
u16 i;
len = xdp->data_end - xdp->data;
if (unlikely(!ixgbe_desc_unused(ring)))
return IXGBE_XDP_CONSUMED;
dma = dma_map_single(ring->dev, xdp->data, len, DMA_TO_DEVICE);
if (dma_mapping_error(ring->dev, dma))
return IXGBE_XDP_CONSUMED;
tx_buffer = &ring->tx_buffer_info[ring->next_to_use];
tx_buffer->bytecount = len;
tx_buffer->gso_segs = 1;
tx_buffer->protocol = 0;
i = ring->next_to_use;
tx_desc = IXGBE_TX_DESC(ring, i);
dma_unmap_len_set(tx_buffer, len, len);
dma_unmap_addr_set(tx_buffer, dma, dma);
tx_buffer->data = xdp->data;
tx_desc->read.buffer_addr = cpu_to_le64(dma);
cmd_type = IXGBE_ADVTXD_DTYP_DATA |
IXGBE_ADVTXD_DCMD_DEXT |
IXGBE_ADVTXD_DCMD_IFCS;
cmd_type |= len | IXGBE_TXD_CMD;
tx_desc->read.cmd_type_len = cpu_to_le32(cmd_type);
tx_desc->read.olinfo_status =
cpu_to_le32(len << IXGBE_ADVTXD_PAYLEN_SHIFT);
smp_wmb();
i++;
if (i == ring->count)
i = 0;
tx_buffer->next_to_watch = tx_desc;
ring->next_to_use = i;
return IXGBE_XDP_TX;
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
if (skb_vlan_tag_present(skb)) {
tx_flags |= skb_vlan_tag_get(skb) << IXGBE_TX_FLAGS_VLAN_SHIFT;
tx_flags |= IXGBE_TX_FLAGS_HW_VLAN;
} else if (protocol == htons(ETH_P_8021Q)) {
struct vlan_hdr *vhdr, _vhdr;
vhdr = skb_header_pointer(skb, ETH_HLEN, sizeof(_vhdr), &_vhdr);
if (!vhdr)
goto out_drop;
tx_flags |= ntohs(vhdr->h_vlan_TCI) <<
IXGBE_TX_FLAGS_VLAN_SHIFT;
tx_flags |= IXGBE_TX_FLAGS_SW_VLAN;
}
protocol = vlan_get_protocol(skb);
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP) &&
adapter->ptp_clock &&
!test_and_set_bit_lock(__IXGBE_PTP_TX_IN_PROGRESS,
&adapter->state)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
tx_flags |= IXGBE_TX_FLAGS_TSTAMP;
adapter->ptp_tx_skb = skb_get(skb);
adapter->ptp_tx_start = jiffies;
schedule_work(&adapter->ptp_tx_work);
}
skb_tx_timestamp(skb);
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
if (skb_cow_head(skb, 0))
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
if ((protocol == htons(ETH_P_FCOE)) &&
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
return NETDEV_TX_OK;
out_drop:
dev_kfree_skb_any(first->skb);
first->skb = NULL;
return NETDEV_TX_OK;
}
static netdev_tx_t __ixgbe_xmit_frame(struct sk_buff *skb,
struct net_device *netdev,
struct ixgbe_ring *ring)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_ring *tx_ring;
if (skb_put_padto(skb, 17))
return NETDEV_TX_OK;
tx_ring = ring ? ring : adapter->tx_ring[skb->queue_mapping];
return ixgbe_xmit_frame_ring(skb, adapter, tx_ring);
}
static netdev_tx_t ixgbe_xmit_frame(struct sk_buff *skb,
struct net_device *netdev)
{
return __ixgbe_xmit_frame(skb, netdev, NULL);
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
ixgbe_mac_set_default_filter(adapter);
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
return ixgbe_ptp_set_ts_config(adapter, req);
case SIOCGHWTSTAMP:
return ixgbe_ptp_get_ts_config(adapter, req);
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
for (i = 0; i < adapter->num_q_vectors; i++)
ixgbe_msix_clean_rings(0, adapter->q_vector[i]);
}
static void ixgbe_get_ring_stats64(struct rtnl_link_stats64 *stats,
struct ixgbe_ring *ring)
{
u64 bytes, packets;
unsigned int start;
if (ring) {
do {
start = u64_stats_fetch_begin_irq(&ring->syncp);
packets = ring->stats.packets;
bytes = ring->stats.bytes;
} while (u64_stats_fetch_retry_irq(&ring->syncp, start));
stats->tx_packets += packets;
stats->tx_bytes += bytes;
}
}
static void ixgbe_get_stats64(struct net_device *netdev,
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
start = u64_stats_fetch_begin_irq(&ring->syncp);
packets = ring->stats.packets;
bytes = ring->stats.bytes;
} while (u64_stats_fetch_retry_irq(&ring->syncp, start));
stats->rx_packets += packets;
stats->rx_bytes += bytes;
}
}
for (i = 0; i < adapter->num_tx_queues; i++) {
struct ixgbe_ring *ring = ACCESS_ONCE(adapter->tx_ring[i]);
ixgbe_get_ring_stats64(stats, ring);
}
for (i = 0; i < adapter->num_xdp_queues; i++) {
struct ixgbe_ring *ring = ACCESS_ONCE(adapter->xdp_ring[i]);
ixgbe_get_ring_stats64(stats, ring);
}
rcu_read_unlock();
stats->multicast = netdev->stats.multicast;
stats->rx_errors = netdev->stats.rx_errors;
stats->rx_length_errors = netdev->stats.rx_length_errors;
stats->rx_crc_errors = netdev->stats.rx_crc_errors;
stats->rx_missed_errors = netdev->stats.rx_missed_errors;
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
bool pools;
if (tc > adapter->dcb_cfg.num_tcs.pg_tcs)
return -EINVAL;
if (hw->mac.type == ixgbe_mac_82598EB && tc && tc < MAX_TRAFFIC_CLASS)
return -EINVAL;
pools = (find_first_zero_bit(&adapter->fwd_bitmask, 32) > 1);
if (tc && pools && adapter->num_rx_pools > IXGBE_MAX_DCBMACVLANS)
return -EBUSY;
if (netif_running(dev))
ixgbe_close(dev);
else
ixgbe_reset(adapter);
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
static int ixgbe_delete_clsu32(struct ixgbe_adapter *adapter,
struct tc_cls_u32_offload *cls)
{
u32 hdl = cls->knode.handle;
u32 uhtid = TC_U32_USERHTID(cls->knode.handle);
u32 loc = cls->knode.handle & 0xfffff;
int err = 0, i, j;
struct ixgbe_jump_table *jump = NULL;
if (loc > IXGBE_MAX_HW_ENTRIES)
return -EINVAL;
if ((uhtid != 0x800) && (uhtid >= IXGBE_MAX_LINK_HANDLE))
return -EINVAL;
if (uhtid != 0x800) {
jump = adapter->jump_tables[uhtid];
if (!jump)
return -EINVAL;
if (!test_bit(loc - 1, jump->child_loc_map))
return -EINVAL;
clear_bit(loc - 1, jump->child_loc_map);
}
for (i = 1; i < IXGBE_MAX_LINK_HANDLE; i++) {
jump = adapter->jump_tables[i];
if (jump && jump->link_hdl == hdl) {
for (j = 0; j < IXGBE_MAX_HW_ENTRIES; j++) {
if (!test_bit(j, jump->child_loc_map))
continue;
spin_lock(&adapter->fdir_perfect_lock);
err = ixgbe_update_ethtool_fdir_entry(adapter,
NULL,
j + 1);
spin_unlock(&adapter->fdir_perfect_lock);
clear_bit(j, jump->child_loc_map);
}
kfree(jump->input);
kfree(jump->mask);
kfree(jump);
adapter->jump_tables[i] = NULL;
return err;
}
}
spin_lock(&adapter->fdir_perfect_lock);
err = ixgbe_update_ethtool_fdir_entry(adapter, NULL, loc);
spin_unlock(&adapter->fdir_perfect_lock);
return err;
}
static int ixgbe_configure_clsu32_add_hnode(struct ixgbe_adapter *adapter,
__be16 protocol,
struct tc_cls_u32_offload *cls)
{
u32 uhtid = TC_U32_USERHTID(cls->hnode.handle);
if (uhtid >= IXGBE_MAX_LINK_HANDLE)
return -EINVAL;
if (cls->hnode.divisor > 0)
return -EINVAL;
set_bit(uhtid - 1, &adapter->tables);
return 0;
}
static int ixgbe_configure_clsu32_del_hnode(struct ixgbe_adapter *adapter,
struct tc_cls_u32_offload *cls)
{
u32 uhtid = TC_U32_USERHTID(cls->hnode.handle);
if (uhtid >= IXGBE_MAX_LINK_HANDLE)
return -EINVAL;
clear_bit(uhtid - 1, &adapter->tables);
return 0;
}
static int get_macvlan_queue(struct net_device *upper, void *_data)
{
if (netif_is_macvlan(upper)) {
struct macvlan_dev *dfwd = netdev_priv(upper);
struct ixgbe_fwd_adapter *vadapter = dfwd->fwd_priv;
struct upper_walk_data *data = _data;
struct ixgbe_adapter *adapter = data->adapter;
int ifindex = data->ifindex;
if (vadapter && vadapter->netdev->ifindex == ifindex) {
data->queue = adapter->rx_ring[vadapter->rx_base_queue]->reg_idx;
data->action = data->queue;
return 1;
}
}
return 0;
}
static int handle_redirect_action(struct ixgbe_adapter *adapter, int ifindex,
u8 *queue, u64 *action)
{
unsigned int num_vfs = adapter->num_vfs, vf;
struct upper_walk_data data;
struct net_device *upper;
for (vf = 0; vf < num_vfs; ++vf) {
upper = pci_get_drvdata(adapter->vfinfo[vf].vfdev);
if (upper->ifindex == ifindex) {
if (adapter->num_rx_pools > 1)
*queue = vf * 2;
else
*queue = vf * adapter->num_rx_queues_per_pool;
*action = vf + 1;
*action <<= ETHTOOL_RX_FLOW_SPEC_RING_VF_OFF;
return 0;
}
}
data.adapter = adapter;
data.ifindex = ifindex;
data.action = 0;
data.queue = 0;
if (netdev_walk_all_upper_dev_rcu(adapter->netdev,
get_macvlan_queue, &data)) {
*action = data.action;
*queue = data.queue;
return 0;
}
return -EINVAL;
}
static int parse_tc_actions(struct ixgbe_adapter *adapter,
struct tcf_exts *exts, u64 *action, u8 *queue)
{
const struct tc_action *a;
LIST_HEAD(actions);
int err;
if (tc_no_actions(exts))
return -EINVAL;
tcf_exts_to_list(exts, &actions);
list_for_each_entry(a, &actions, list) {
if (is_tcf_gact_shot(a)) {
*action = IXGBE_FDIR_DROP_QUEUE;
*queue = IXGBE_FDIR_DROP_QUEUE;
return 0;
}
if (is_tcf_mirred_egress_redirect(a)) {
int ifindex = tcf_mirred_ifindex(a);
err = handle_redirect_action(adapter, ifindex, queue,
action);
if (err == 0)
return err;
}
}
return -EINVAL;
}
static int parse_tc_actions(struct ixgbe_adapter *adapter,
struct tcf_exts *exts, u64 *action, u8 *queue)
{
return -EINVAL;
}
static int ixgbe_clsu32_build_input(struct ixgbe_fdir_filter *input,
union ixgbe_atr_input *mask,
struct tc_cls_u32_offload *cls,
struct ixgbe_mat_field *field_ptr,
struct ixgbe_nexthdr *nexthdr)
{
int i, j, off;
__be32 val, m;
bool found_entry = false, found_jump_field = false;
for (i = 0; i < cls->knode.sel->nkeys; i++) {
off = cls->knode.sel->keys[i].off;
val = cls->knode.sel->keys[i].val;
m = cls->knode.sel->keys[i].mask;
for (j = 0; field_ptr[j].val; j++) {
if (field_ptr[j].off == off) {
field_ptr[j].val(input, mask, val, m);
input->filter.formatted.flow_type |=
field_ptr[j].type;
found_entry = true;
break;
}
}
if (nexthdr) {
if (nexthdr->off == cls->knode.sel->keys[i].off &&
nexthdr->val == cls->knode.sel->keys[i].val &&
nexthdr->mask == cls->knode.sel->keys[i].mask)
found_jump_field = true;
else
continue;
}
}
if (nexthdr && !found_jump_field)
return -EINVAL;
if (!found_entry)
return 0;
mask->formatted.flow_type = IXGBE_ATR_L4TYPE_IPV6_MASK |
IXGBE_ATR_L4TYPE_MASK;
if (input->filter.formatted.flow_type == IXGBE_ATR_FLOW_TYPE_IPV4)
mask->formatted.flow_type &= IXGBE_ATR_L4TYPE_IPV6_MASK;
return 0;
}
static int ixgbe_configure_clsu32(struct ixgbe_adapter *adapter,
__be16 protocol,
struct tc_cls_u32_offload *cls)
{
u32 loc = cls->knode.handle & 0xfffff;
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_mat_field *field_ptr;
struct ixgbe_fdir_filter *input = NULL;
union ixgbe_atr_input *mask = NULL;
struct ixgbe_jump_table *jump = NULL;
int i, err = -EINVAL;
u8 queue;
u32 uhtid, link_uhtid;
uhtid = TC_U32_USERHTID(cls->knode.handle);
link_uhtid = TC_U32_USERHTID(cls->knode.link_handle);
if (protocol != htons(ETH_P_IP))
return err;
if (loc >= ((1024 << adapter->fdir_pballoc) - 2)) {
e_err(drv, "Location out of range\n");
return err;
}
if (uhtid == 0x800) {
field_ptr = (adapter->jump_tables[0])->mat;
} else {
if (uhtid >= IXGBE_MAX_LINK_HANDLE)
return err;
if (!adapter->jump_tables[uhtid])
return err;
field_ptr = (adapter->jump_tables[uhtid])->mat;
}
if (!field_ptr)
return err;
if (link_uhtid) {
struct ixgbe_nexthdr *nexthdr = ixgbe_ipv4_jumps;
if (link_uhtid >= IXGBE_MAX_LINK_HANDLE)
return err;
if (!test_bit(link_uhtid - 1, &adapter->tables))
return err;
if (adapter->jump_tables[link_uhtid] &&
(adapter->jump_tables[link_uhtid])->link_hdl) {
e_err(drv, "Link filter exists for link: %x\n",
link_uhtid);
return err;
}
for (i = 0; nexthdr[i].jump; i++) {
if (nexthdr[i].o != cls->knode.sel->offoff ||
nexthdr[i].s != cls->knode.sel->offshift ||
nexthdr[i].m != cls->knode.sel->offmask)
return err;
jump = kzalloc(sizeof(*jump), GFP_KERNEL);
if (!jump)
return -ENOMEM;
input = kzalloc(sizeof(*input), GFP_KERNEL);
if (!input) {
err = -ENOMEM;
goto free_jump;
}
mask = kzalloc(sizeof(*mask), GFP_KERNEL);
if (!mask) {
err = -ENOMEM;
goto free_input;
}
jump->input = input;
jump->mask = mask;
jump->link_hdl = cls->knode.handle;
err = ixgbe_clsu32_build_input(input, mask, cls,
field_ptr, &nexthdr[i]);
if (!err) {
jump->mat = nexthdr[i].jump;
adapter->jump_tables[link_uhtid] = jump;
break;
}
}
return 0;
}
input = kzalloc(sizeof(*input), GFP_KERNEL);
if (!input)
return -ENOMEM;
mask = kzalloc(sizeof(*mask), GFP_KERNEL);
if (!mask) {
err = -ENOMEM;
goto free_input;
}
if ((uhtid != 0x800) && (adapter->jump_tables[uhtid])) {
if ((adapter->jump_tables[uhtid])->input)
memcpy(input, (adapter->jump_tables[uhtid])->input,
sizeof(*input));
if ((adapter->jump_tables[uhtid])->mask)
memcpy(mask, (adapter->jump_tables[uhtid])->mask,
sizeof(*mask));
for (i = 1; i < IXGBE_MAX_LINK_HANDLE; i++) {
struct ixgbe_jump_table *link = adapter->jump_tables[i];
if (link && (test_bit(loc - 1, link->child_loc_map))) {
e_err(drv, "Filter exists in location: %x\n",
loc);
err = -EINVAL;
goto err_out;
}
}
}
err = ixgbe_clsu32_build_input(input, mask, cls, field_ptr, NULL);
if (err)
goto err_out;
err = parse_tc_actions(adapter, cls->knode.exts, &input->action,
&queue);
if (err < 0)
goto err_out;
input->sw_idx = loc;
spin_lock(&adapter->fdir_perfect_lock);
if (hlist_empty(&adapter->fdir_filter_list)) {
memcpy(&adapter->fdir_mask, mask, sizeof(*mask));
err = ixgbe_fdir_set_input_mask_82599(hw, mask);
if (err)
goto err_out_w_lock;
} else if (memcmp(&adapter->fdir_mask, mask, sizeof(*mask))) {
err = -EINVAL;
goto err_out_w_lock;
}
ixgbe_atr_compute_perfect_hash_82599(&input->filter, mask);
err = ixgbe_fdir_write_perfect_filter_82599(hw, &input->filter,
input->sw_idx, queue);
if (!err)
ixgbe_update_ethtool_fdir_entry(adapter, input, input->sw_idx);
spin_unlock(&adapter->fdir_perfect_lock);
if ((uhtid != 0x800) && (adapter->jump_tables[uhtid]))
set_bit(loc - 1, (adapter->jump_tables[uhtid])->child_loc_map);
kfree(mask);
return err;
err_out_w_lock:
spin_unlock(&adapter->fdir_perfect_lock);
err_out:
kfree(mask);
free_input:
kfree(input);
free_jump:
kfree(jump);
return err;
}
static int __ixgbe_setup_tc(struct net_device *dev, u32 handle, __be16 proto,
struct tc_to_netdev *tc)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
if (TC_H_MAJ(handle) == TC_H_MAJ(TC_H_INGRESS) &&
tc->type == TC_SETUP_CLSU32) {
switch (tc->cls_u32->command) {
case TC_CLSU32_NEW_KNODE:
case TC_CLSU32_REPLACE_KNODE:
return ixgbe_configure_clsu32(adapter,
proto, tc->cls_u32);
case TC_CLSU32_DELETE_KNODE:
return ixgbe_delete_clsu32(adapter, tc->cls_u32);
case TC_CLSU32_NEW_HNODE:
case TC_CLSU32_REPLACE_HNODE:
return ixgbe_configure_clsu32_add_hnode(adapter, proto,
tc->cls_u32);
case TC_CLSU32_DELETE_HNODE:
return ixgbe_configure_clsu32_del_hnode(adapter,
tc->cls_u32);
default:
return -EINVAL;
}
}
if (tc->type != TC_SETUP_MQPRIO)
return -EINVAL;
tc->mqprio->hw = TC_MQPRIO_HW_OFFLOAD_TCS;
return ixgbe_setup_tc(dev, tc->mqprio->num_tc);
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
if ((features & NETIF_F_NTUPLE) || (features & NETIF_F_HW_TC)) {
if (!(adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE))
need_reset = true;
adapter->flags &= ~IXGBE_FLAG_FDIR_HASH_CAPABLE;
adapter->flags |= IXGBE_FLAG_FDIR_PERFECT_CAPABLE;
} else {
if (adapter->flags & IXGBE_FLAG_FDIR_PERFECT_CAPABLE)
need_reset = true;
adapter->flags &= ~IXGBE_FLAG_FDIR_PERFECT_CAPABLE;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED ||
(netdev_get_num_tc(netdev) > 1) ||
(adapter->ring_feature[RING_F_RSS].limit <= 1) ||
(!adapter->atr_sample_rate))
;
else
adapter->flags |= IXGBE_FLAG_FDIR_HASH_CAPABLE;
}
if (changed & NETIF_F_RXALL)
need_reset = true;
netdev->features = features;
if ((adapter->flags & IXGBE_FLAG_VXLAN_OFFLOAD_CAPABLE)) {
if (features & NETIF_F_RXCSUM) {
adapter->flags2 |= IXGBE_FLAG2_UDP_TUN_REREG_NEEDED;
} else {
u32 port_mask = IXGBE_VXLANCTRL_VXLAN_UDPPORT_MASK;
ixgbe_clear_udp_tunnel_port(adapter, port_mask);
}
}
if ((adapter->flags & IXGBE_FLAG_GENEVE_OFFLOAD_CAPABLE)) {
if (features & NETIF_F_RXCSUM) {
adapter->flags2 |= IXGBE_FLAG2_UDP_TUN_REREG_NEEDED;
} else {
u32 port_mask = IXGBE_VXLANCTRL_GENEVE_UDPPORT_MASK;
ixgbe_clear_udp_tunnel_port(adapter, port_mask);
}
}
if (need_reset)
ixgbe_do_reset(netdev);
else if (changed & (NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_FILTER))
ixgbe_set_rx_mode(netdev);
return 0;
}
static void ixgbe_add_udp_tunnel_port(struct net_device *dev,
struct udp_tunnel_info *ti)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct ixgbe_hw *hw = &adapter->hw;
__be16 port = ti->port;
u32 port_shift = 0;
u32 reg;
if (ti->sa_family != AF_INET)
return;
switch (ti->type) {
case UDP_TUNNEL_TYPE_VXLAN:
if (!(adapter->flags & IXGBE_FLAG_VXLAN_OFFLOAD_CAPABLE))
return;
if (adapter->vxlan_port == port)
return;
if (adapter->vxlan_port) {
netdev_info(dev,
"VXLAN port %d set, not adding port %d\n",
ntohs(adapter->vxlan_port),
ntohs(port));
return;
}
adapter->vxlan_port = port;
break;
case UDP_TUNNEL_TYPE_GENEVE:
if (!(adapter->flags & IXGBE_FLAG_GENEVE_OFFLOAD_CAPABLE))
return;
if (adapter->geneve_port == port)
return;
if (adapter->geneve_port) {
netdev_info(dev,
"GENEVE port %d set, not adding port %d\n",
ntohs(adapter->geneve_port),
ntohs(port));
return;
}
port_shift = IXGBE_VXLANCTRL_GENEVE_UDPPORT_SHIFT;
adapter->geneve_port = port;
break;
default:
return;
}
reg = IXGBE_READ_REG(hw, IXGBE_VXLANCTRL) | ntohs(port) << port_shift;
IXGBE_WRITE_REG(hw, IXGBE_VXLANCTRL, reg);
}
static void ixgbe_del_udp_tunnel_port(struct net_device *dev,
struct udp_tunnel_info *ti)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
u32 port_mask;
if (ti->type != UDP_TUNNEL_TYPE_VXLAN &&
ti->type != UDP_TUNNEL_TYPE_GENEVE)
return;
if (ti->sa_family != AF_INET)
return;
switch (ti->type) {
case UDP_TUNNEL_TYPE_VXLAN:
if (!(adapter->flags & IXGBE_FLAG_VXLAN_OFFLOAD_CAPABLE))
return;
if (adapter->vxlan_port != ti->port) {
netdev_info(dev, "VXLAN port %d not found\n",
ntohs(ti->port));
return;
}
port_mask = IXGBE_VXLANCTRL_VXLAN_UDPPORT_MASK;
break;
case UDP_TUNNEL_TYPE_GENEVE:
if (!(adapter->flags & IXGBE_FLAG_GENEVE_OFFLOAD_CAPABLE))
return;
if (adapter->geneve_port != ti->port) {
netdev_info(dev, "GENEVE port %d not found\n",
ntohs(ti->port));
return;
}
port_mask = IXGBE_VXLANCTRL_GENEVE_UDPPORT_MASK;
break;
default:
return;
}
ixgbe_clear_udp_tunnel_port(adapter, port_mask);
adapter->flags2 |= IXGBE_FLAG2_UDP_TUN_REREG_NEEDED;
}
static int ixgbe_ndo_fdb_add(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev,
const unsigned char *addr, u16 vid,
u16 flags)
{
if (is_unicast_ether_addr(addr) || is_link_local_ether_addr(addr)) {
struct ixgbe_adapter *adapter = netdev_priv(dev);
u16 pool = VMDQ_P(0);
if (netdev_uc_count(dev) >= ixgbe_available_rars(adapter, pool))
return -ENOMEM;
}
return ndo_dflt_fdb_add(ndm, tb, dev, addr, vid, flags);
}
static int ixgbe_configure_bridge_mode(struct ixgbe_adapter *adapter,
__u16 mode)
{
struct ixgbe_hw *hw = &adapter->hw;
unsigned int p, num_pools;
u32 vmdctl;
switch (mode) {
case BRIDGE_MODE_VEPA:
IXGBE_WRITE_REG(&adapter->hw, IXGBE_PFDTXGSWC, 0);
vmdctl = IXGBE_READ_REG(hw, IXGBE_VMD_CTL);
vmdctl |= IXGBE_VT_CTL_REPLEN;
IXGBE_WRITE_REG(hw, IXGBE_VMD_CTL, vmdctl);
num_pools = adapter->num_vfs + adapter->num_rx_pools;
for (p = 0; p < num_pools; p++) {
if (hw->mac.ops.set_source_address_pruning)
hw->mac.ops.set_source_address_pruning(hw,
true,
p);
}
break;
case BRIDGE_MODE_VEB:
IXGBE_WRITE_REG(&adapter->hw, IXGBE_PFDTXGSWC,
IXGBE_PFDTXGSWC_VT_LBEN);
vmdctl = IXGBE_READ_REG(hw, IXGBE_VMD_CTL);
if (!adapter->num_vfs)
vmdctl &= ~IXGBE_VT_CTL_REPLEN;
IXGBE_WRITE_REG(hw, IXGBE_VMD_CTL, vmdctl);
num_pools = adapter->num_vfs + adapter->num_rx_pools;
for (p = 0; p < num_pools; p++) {
if (hw->mac.ops.set_source_address_pruning)
hw->mac.ops.set_source_address_pruning(hw,
false,
p);
}
break;
default:
return -EINVAL;
}
adapter->bridge_mode = mode;
e_info(drv, "enabling bridge mode: %s\n",
mode == BRIDGE_MODE_VEPA ? "VEPA" : "VEB");
return 0;
}
static int ixgbe_ndo_bridge_setlink(struct net_device *dev,
struct nlmsghdr *nlh, u16 flags)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct nlattr *attr, *br_spec;
int rem;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return -EOPNOTSUPP;
br_spec = nlmsg_find_attr(nlh, sizeof(struct ifinfomsg), IFLA_AF_SPEC);
if (!br_spec)
return -EINVAL;
nla_for_each_nested(attr, br_spec, rem) {
int status;
__u16 mode;
if (nla_type(attr) != IFLA_BRIDGE_MODE)
continue;
if (nla_len(attr) < sizeof(mode))
return -EINVAL;
mode = nla_get_u16(attr);
status = ixgbe_configure_bridge_mode(adapter, mode);
if (status)
return status;
break;
}
return 0;
}
static int ixgbe_ndo_bridge_getlink(struct sk_buff *skb, u32 pid, u32 seq,
struct net_device *dev,
u32 filter_mask, int nlflags)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return 0;
return ndo_dflt_bridge_getlink(skb, pid, seq, dev,
adapter->bridge_mode, 0, 0, nlflags,
filter_mask, NULL);
}
static void *ixgbe_fwd_add(struct net_device *pdev, struct net_device *vdev)
{
struct ixgbe_fwd_adapter *fwd_adapter = NULL;
struct ixgbe_adapter *adapter = netdev_priv(pdev);
int used_pools = adapter->num_vfs + adapter->num_rx_pools;
unsigned int limit;
int pool, err;
if (used_pools >= IXGBE_MAX_VF_FUNCTIONS)
return ERR_PTR(-EINVAL);
#ifdef CONFIG_RPS
if (vdev->num_rx_queues != vdev->num_tx_queues) {
netdev_info(pdev, "%s: Only supports a single queue count for TX and RX\n",
vdev->name);
return ERR_PTR(-EINVAL);
}
#endif
if (vdev->num_tx_queues > IXGBE_MAX_L2A_QUEUES ||
vdev->num_tx_queues == IXGBE_BAD_L2A_QUEUE) {
netdev_info(pdev,
"%s: Supports RX/TX Queue counts 1,2, and 4\n",
pdev->name);
return ERR_PTR(-EINVAL);
}
if (((adapter->flags & IXGBE_FLAG_DCB_ENABLED) &&
adapter->num_rx_pools > IXGBE_MAX_DCBMACVLANS - 1) ||
(adapter->num_rx_pools > IXGBE_MAX_MACVLANS))
return ERR_PTR(-EBUSY);
fwd_adapter = kzalloc(sizeof(*fwd_adapter), GFP_KERNEL);
if (!fwd_adapter)
return ERR_PTR(-ENOMEM);
pool = find_first_zero_bit(&adapter->fwd_bitmask, 32);
adapter->num_rx_pools++;
set_bit(pool, &adapter->fwd_bitmask);
limit = find_last_bit(&adapter->fwd_bitmask, 32);
adapter->flags |= IXGBE_FLAG_VMDQ_ENABLED | IXGBE_FLAG_SRIOV_ENABLED;
adapter->ring_feature[RING_F_VMDQ].limit = limit + 1;
adapter->ring_feature[RING_F_RSS].limit = vdev->num_tx_queues;
err = ixgbe_setup_tc(pdev, netdev_get_num_tc(pdev));
if (err)
goto fwd_add_err;
fwd_adapter->pool = pool;
fwd_adapter->real_adapter = adapter;
if (netif_running(pdev)) {
err = ixgbe_fwd_ring_up(vdev, fwd_adapter);
if (err)
goto fwd_add_err;
netif_tx_start_all_queues(vdev);
}
return fwd_adapter;
fwd_add_err:
netdev_info(pdev,
"%s: dfwd hardware acceleration failed\n", vdev->name);
clear_bit(pool, &adapter->fwd_bitmask);
adapter->num_rx_pools--;
kfree(fwd_adapter);
return ERR_PTR(err);
}
static void ixgbe_fwd_del(struct net_device *pdev, void *priv)
{
struct ixgbe_fwd_adapter *fwd_adapter = priv;
struct ixgbe_adapter *adapter = fwd_adapter->real_adapter;
unsigned int limit;
clear_bit(fwd_adapter->pool, &adapter->fwd_bitmask);
adapter->num_rx_pools--;
limit = find_last_bit(&adapter->fwd_bitmask, 32);
adapter->ring_feature[RING_F_VMDQ].limit = limit + 1;
ixgbe_fwd_ring_down(fwd_adapter->netdev, fwd_adapter);
ixgbe_setup_tc(pdev, netdev_get_num_tc(pdev));
netdev_dbg(pdev, "pool %i:%i queues %i:%i VSI bitmask %lx\n",
fwd_adapter->pool, adapter->num_rx_pools,
fwd_adapter->rx_base_queue,
fwd_adapter->rx_base_queue + adapter->num_rx_queues_per_pool,
adapter->fwd_bitmask);
kfree(fwd_adapter);
}
static netdev_features_t
ixgbe_features_check(struct sk_buff *skb, struct net_device *dev,
netdev_features_t features)
{
unsigned int network_hdr_len, mac_hdr_len;
mac_hdr_len = skb_network_header(skb) - skb->data;
if (unlikely(mac_hdr_len > IXGBE_MAX_MAC_HDR_LEN))
return features & ~(NETIF_F_HW_CSUM |
NETIF_F_SCTP_CRC |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_TSO |
NETIF_F_TSO6);
network_hdr_len = skb_checksum_start(skb) - skb_network_header(skb);
if (unlikely(network_hdr_len > IXGBE_MAX_NETWORK_HDR_LEN))
return features & ~(NETIF_F_HW_CSUM |
NETIF_F_SCTP_CRC |
NETIF_F_TSO |
NETIF_F_TSO6);
if (skb->encapsulation && !(features & NETIF_F_TSO_MANGLEID))
features &= ~NETIF_F_TSO;
return features;
}
static int ixgbe_xdp_setup(struct net_device *dev, struct bpf_prog *prog)
{
int i, frame_size = dev->mtu + ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN;
struct ixgbe_adapter *adapter = netdev_priv(dev);
struct bpf_prog *old_prog;
if (adapter->flags & IXGBE_FLAG_SRIOV_ENABLED)
return -EINVAL;
if (adapter->flags & IXGBE_FLAG_DCB_ENABLED)
return -EINVAL;
for (i = 0; i < adapter->num_rx_queues; i++) {
struct ixgbe_ring *ring = adapter->rx_ring[i];
if (ring_is_rsc_enabled(ring))
return -EINVAL;
if (frame_size > ixgbe_rx_bufsz(ring))
return -EINVAL;
}
if (nr_cpu_ids > MAX_XDP_QUEUES)
return -ENOMEM;
old_prog = xchg(&adapter->xdp_prog, prog);
if (!!prog != !!old_prog) {
int err = ixgbe_setup_tc(dev, netdev_get_num_tc(dev));
if (err) {
rcu_assign_pointer(adapter->xdp_prog, old_prog);
return -EINVAL;
}
} else {
for (i = 0; i < adapter->num_rx_queues; i++)
xchg(&adapter->rx_ring[i]->xdp_prog, adapter->xdp_prog);
}
if (old_prog)
bpf_prog_put(old_prog);
return 0;
}
static int ixgbe_xdp(struct net_device *dev, struct netdev_xdp *xdp)
{
struct ixgbe_adapter *adapter = netdev_priv(dev);
switch (xdp->command) {
case XDP_SETUP_PROG:
return ixgbe_xdp_setup(dev, xdp->prog);
case XDP_QUERY_PROG:
xdp->prog_attached = !!(adapter->xdp_prog);
return 0;
default:
return -EINVAL;
}
}
static inline int ixgbe_enumerate_functions(struct ixgbe_adapter *adapter)
{
struct pci_dev *entry, *pdev = adapter->pdev;
int physfns = 0;
if (ixgbe_pcie_from_parent(&adapter->hw))
physfns = 4;
list_for_each_entry(entry, &adapter->pdev->bus->devices, bus_list) {
if (entry->is_virtfn)
continue;
if ((entry->vendor != pdev->vendor) ||
(entry->device != pdev->device))
return -1;
physfns++;
}
return physfns;
}
bool ixgbe_wol_supported(struct ixgbe_adapter *adapter, u16 device_id,
u16 subdevice_id)
{
struct ixgbe_hw *hw = &adapter->hw;
u16 wol_cap = adapter->eeprom_cap & IXGBE_DEVICE_CAPS_WOL_MASK;
if (hw->mac.type == ixgbe_mac_82598EB)
return false;
if (hw->mac.type >= ixgbe_mac_X540) {
if ((wol_cap == IXGBE_DEVICE_CAPS_WOL_PORT0_1) ||
((wol_cap == IXGBE_DEVICE_CAPS_WOL_PORT0) &&
(hw->bus.func == 0)))
return true;
}
switch (device_id) {
case IXGBE_DEV_ID_82599_SFP:
switch (subdevice_id) {
case IXGBE_SUBDEV_ID_82599_560FLR:
case IXGBE_SUBDEV_ID_82599_LOM_SNAP6:
case IXGBE_SUBDEV_ID_82599_SFP_WOL0:
case IXGBE_SUBDEV_ID_82599_SFP_2OCP:
if (hw->bus.func != 0)
break;
case IXGBE_SUBDEV_ID_82599_SP_560FLR:
case IXGBE_SUBDEV_ID_82599_SFP:
case IXGBE_SUBDEV_ID_82599_RNDC:
case IXGBE_SUBDEV_ID_82599_ECNA_DP:
case IXGBE_SUBDEV_ID_82599_SFP_1OCP:
case IXGBE_SUBDEV_ID_82599_SFP_LOM_OEM1:
case IXGBE_SUBDEV_ID_82599_SFP_LOM_OEM2:
return true;
}
break;
case IXGBE_DEV_ID_82599EN_SFP:
switch (subdevice_id) {
case IXGBE_SUBDEV_ID_82599EN_SFP_OCP1:
return true;
}
break;
case IXGBE_DEV_ID_82599_COMBO_BACKPLANE:
if (subdevice_id != IXGBE_SUBDEV_ID_82599_KX4_KR_MEZZ)
return true;
break;
case IXGBE_DEV_ID_82599_KX4:
return true;
default:
break;
}
return false;
}
static int ixgbe_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev;
struct ixgbe_adapter *adapter = NULL;
struct ixgbe_hw *hw;
const struct ixgbe_info *ii = ixgbe_info_tbl[ent->driver_data];
int i, err, pci_using_dac, expected_gts;
unsigned int indices = MAX_TX_QUEUES;
u8 part_str[IXGBE_PBANUM_LENGTH];
bool disable_dev = false;
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
if (!dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64))) {
pci_using_dac = 1;
} else {
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev,
"No usable DMA configuration, aborting\n");
goto err_dma;
}
pci_using_dac = 0;
}
err = pci_request_mem_regions(pdev, ixgbe_driver_name);
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
adapter->netdev = netdev;
adapter->pdev = pdev;
hw = &adapter->hw;
hw->back = adapter;
adapter->msg_enable = netif_msg_init(debug, DEFAULT_MSG_ENABLE);
hw->hw_addr = ioremap(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
adapter->io_addr = hw->hw_addr;
if (!hw->hw_addr) {
err = -EIO;
goto err_ioremap;
}
netdev->netdev_ops = &ixgbe_netdev_ops;
ixgbe_set_ethtool_ops(netdev);
netdev->watchdog_timeo = 5 * HZ;
strlcpy(netdev->name, pci_name(pdev), sizeof(netdev->name));
hw->mac.ops = *ii->mac_ops;
hw->mac.type = ii->mac;
hw->mvals = ii->mvals;
if (ii->link_ops)
hw->link.ops = *ii->link_ops;
hw->eeprom.ops = *ii->eeprom_ops;
eec = IXGBE_READ_REG(hw, IXGBE_EEC(hw));
if (ixgbe_removed(hw->hw_addr)) {
err = -EIO;
goto err_ioremap;
}
if (!(eec & BIT(8)))
hw->eeprom.ops.read = &ixgbe_read_eeprom_bit_bang_generic;
hw->phy.ops = *ii->phy_ops;
hw->phy.sfp_type = ixgbe_sfp_type_unknown;
hw->phy.mdio.prtad = MDIO_PRTAD_NONE;
hw->phy.mdio.mmds = 0;
hw->phy.mdio.mode_support = MDIO_SUPPORTS_C45 | MDIO_EMULATE_C22;
hw->phy.mdio.dev = netdev;
hw->phy.mdio.mdio_read = ixgbe_mdio_read;
hw->phy.mdio.mdio_write = ixgbe_mdio_write;
err = ixgbe_sw_init(adapter, ii);
if (err)
goto err_sw_init;
if (hw->mac.ops.init_swfw_sync)
hw->mac.ops.init_swfw_sync(hw);
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
case ixgbe_mac_X540:
case ixgbe_mac_X550:
case ixgbe_mac_X550EM_x:
case ixgbe_mac_x550em_a:
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
ixgbe_set_eee_capable(adapter);
if (err == IXGBE_ERR_SFP_NOT_PRESENT) {
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
hw->mbx.ops = ii->mbx_ops;
pci_sriov_set_totalvfs(pdev, IXGBE_MAX_VFS_DRV_LIMIT);
ixgbe_enable_sriov(adapter, max_vfs);
skip_sriov:
#endif
netdev->features = NETIF_F_SG |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_RXHASH |
NETIF_F_RXCSUM |
NETIF_F_HW_CSUM;
#define IXGBE_GSO_PARTIAL_FEATURES (NETIF_F_GSO_GRE | \
NETIF_F_GSO_GRE_CSUM | \
NETIF_F_GSO_IPXIP4 | \
NETIF_F_GSO_IPXIP6 | \
NETIF_F_GSO_UDP_TUNNEL | \
NETIF_F_GSO_UDP_TUNNEL_CSUM)
netdev->gso_partial_features = IXGBE_GSO_PARTIAL_FEATURES;
netdev->features |= NETIF_F_GSO_PARTIAL |
IXGBE_GSO_PARTIAL_FEATURES;
if (hw->mac.type >= ixgbe_mac_82599EB)
netdev->features |= NETIF_F_SCTP_CRC;
netdev->hw_features |= netdev->features |
NETIF_F_HW_VLAN_CTAG_FILTER |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_RXALL |
NETIF_F_HW_L2FW_DOFFLOAD;
if (hw->mac.type >= ixgbe_mac_82599EB)
netdev->hw_features |= NETIF_F_NTUPLE |
NETIF_F_HW_TC;
if (pci_using_dac)
netdev->features |= NETIF_F_HIGHDMA;
netdev->vlan_features |= netdev->features | NETIF_F_TSO_MANGLEID;
netdev->hw_enc_features |= netdev->vlan_features;
netdev->mpls_features |= NETIF_F_HW_CSUM;
netdev->features |= NETIF_F_HW_VLAN_CTAG_FILTER |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX;
netdev->priv_flags |= IFF_UNICAST_FLT;
netdev->priv_flags |= IFF_SUPP_NOFCS;
netdev->min_mtu = ETH_MIN_MTU;
netdev->max_mtu = IXGBE_MAX_JUMBO_FRAME_SIZE - (ETH_HLEN + ETH_FCS_LEN);
#ifdef CONFIG_IXGBE_DCB
if (adapter->flags & IXGBE_FLAG_DCB_CAPABLE)
netdev->dcbnl_ops = &ixgbe_dcbnl_ops;
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
if (adapter->flags2 & IXGBE_FLAG2_RSC_CAPABLE)
netdev->hw_features |= NETIF_F_LRO;
if (adapter->flags2 & IXGBE_FLAG2_RSC_ENABLED)
netdev->features |= NETIF_F_LRO;
if (hw->eeprom.ops.validate_checksum(hw, NULL) < 0) {
e_dev_err("The EEPROM Checksum Is Not Valid\n");
err = -EIO;
goto err_sw_init;
}
eth_platform_get_mac_address(&adapter->pdev->dev,
adapter->hw.mac.perm_addr);
memcpy(netdev->dev_addr, hw->mac.perm_addr, netdev->addr_len);
if (!is_valid_ether_addr(netdev->dev_addr)) {
e_dev_err("invalid MAC address\n");
err = -EIO;
goto err_sw_init;
}
ether_addr_copy(hw->mac.addr, hw->mac.perm_addr);
ixgbe_mac_set_default_filter(adapter);
setup_timer(&adapter->service_timer, &ixgbe_service_timer,
(unsigned long) adapter);
if (ixgbe_removed(hw->hw_addr)) {
err = -EIO;
goto err_sw_init;
}
INIT_WORK(&adapter->service_task, ixgbe_service_task);
set_bit(__IXGBE_SERVICE_INITED, &adapter->state);
clear_bit(__IXGBE_SERVICE_SCHED, &adapter->state);
err = ixgbe_init_interrupt_scheme(adapter);
if (err)
goto err_sw_init;
for (i = 0; i < adapter->num_xdp_queues; i++)
u64_stats_init(&adapter->xdp_ring[i]->syncp);
adapter->wol = 0;
hw->eeprom.ops.read(hw, 0x2c, &adapter->eeprom_cap);
hw->wol_enabled = ixgbe_wol_supported(adapter, pdev->device,
pdev->subsystem_device);
if (hw->wol_enabled)
adapter->wol = IXGBE_WUFC_MAG;
device_set_wakeup_enable(&adapter->pdev->dev, adapter->wol);
hw->eeprom.ops.read(hw, 0x2e, &adapter->eeprom_verh);
hw->eeprom.ops.read(hw, 0x2d, &adapter->eeprom_verl);
if (ixgbe_pcie_from_parent(hw))
ixgbe_get_parent_bus_info(adapter);
else
hw->mac.ops.get_bus_info(hw);
switch (hw->mac.type) {
case ixgbe_mac_82598EB:
expected_gts = min(ixgbe_enumerate_functions(adapter) * 10, 16);
break;
default:
expected_gts = ixgbe_enumerate_functions(adapter) * 10;
break;
}
if (expected_gts > 0)
ixgbe_check_minimum_link(adapter, expected_gts);
err = ixgbe_read_pba_string_generic(hw, part_str, sizeof(part_str));
if (err)
strlcpy(part_str, "Unknown", sizeof(part_str));
if (ixgbe_is_sfp(hw) && hw->phy.sfp_type != ixgbe_sfp_type_not_present)
e_dev_info("MAC: %d, PHY: %d, SFP+: %d, PBA No: %s\n",
hw->mac.type, hw->phy.type, hw->phy.sfp_type,
part_str);
else
e_dev_info("MAC: %d, PHY: %d, PBA No: %s\n",
hw->mac.type, hw->phy.type, part_str);
e_dev_info("%pM\n", netdev->dev_addr);
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
pci_set_drvdata(pdev, adapter);
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
hw->mac.ops.set_fw_drv_ver(hw, 0xFF, 0xFF, 0xFF, 0xFF,
sizeof(ixgbe_driver_version) - 1,
ixgbe_driver_version);
ixgbe_add_sanmac_netdev(netdev);
e_dev_info("%s\n", ixgbe_default_device_descr);
#ifdef CONFIG_IXGBE_HWMON
if (ixgbe_sysfs_init(adapter))
e_err(probe, "failed to allocate sysfs resources\n");
#endif
ixgbe_dbg_adapter_init(adapter);
if (ixgbe_mng_enabled(hw) && ixgbe_is_sfp(hw) && hw->mac.ops.setup_link)
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
iounmap(adapter->io_addr);
kfree(adapter->jump_tables[0]);
kfree(adapter->mac_table);
kfree(adapter->rss_key);
err_ioremap:
disable_dev = !test_and_set_bit(__IXGBE_DISABLED, &adapter->state);
free_netdev(netdev);
err_alloc_etherdev:
pci_release_mem_regions(pdev);
err_pci_reg:
err_dma:
if (!adapter || disable_dev)
pci_disable_device(pdev);
return err;
}
static void ixgbe_remove(struct pci_dev *pdev)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev;
bool disable_dev;
int i;
if (!adapter)
return;
netdev = adapter->netdev;
ixgbe_dbg_adapter_exit(adapter);
set_bit(__IXGBE_REMOVING, &adapter->state);
cancel_work_sync(&adapter->service_task);
#ifdef CONFIG_IXGBE_DCA
if (adapter->flags & IXGBE_FLAG_DCA_ENABLED) {
adapter->flags &= ~IXGBE_FLAG_DCA_ENABLED;
dca_remove_requester(&pdev->dev);
IXGBE_WRITE_REG(&adapter->hw, IXGBE_DCA_CTRL,
IXGBE_DCA_CTRL_DCA_DISABLE);
}
#endif
#ifdef CONFIG_IXGBE_HWMON
ixgbe_sysfs_exit(adapter);
#endif
ixgbe_del_sanmac_netdev(netdev);
#ifdef CONFIG_PCI_IOV
ixgbe_disable_sriov(adapter);
#endif
if (netdev->reg_state == NETREG_REGISTERED)
unregister_netdev(netdev);
ixgbe_clear_interrupt_scheme(adapter);
ixgbe_release_hw_control(adapter);
#ifdef CONFIG_DCB
kfree(adapter->ixgbe_ieee_pfc);
kfree(adapter->ixgbe_ieee_ets);
#endif
iounmap(adapter->io_addr);
pci_release_mem_regions(pdev);
e_dev_info("complete\n");
for (i = 0; i < IXGBE_MAX_LINK_HANDLE; i++) {
if (adapter->jump_tables[i]) {
kfree(adapter->jump_tables[i]->input);
kfree(adapter->jump_tables[i]->mask);
}
kfree(adapter->jump_tables[i]);
}
kfree(adapter->mac_table);
kfree(adapter->rss_key);
disable_dev = !test_and_set_bit(__IXGBE_DISABLED, &adapter->state);
free_netdev(netdev);
pci_disable_pcie_error_reporting(pdev);
if (disable_dev)
pci_disable_device(pdev);
}
static pci_ers_result_t ixgbe_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
#ifdef CONFIG_PCI_IOV
struct ixgbe_hw *hw = &adapter->hw;
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
dw0 = ixgbe_read_pci_cfg_dword(hw, pos + PCI_ERR_HEADER_LOG);
dw1 = ixgbe_read_pci_cfg_dword(hw, pos + PCI_ERR_HEADER_LOG + 4);
dw2 = ixgbe_read_pci_cfg_dword(hw, pos + PCI_ERR_HEADER_LOG + 8);
dw3 = ixgbe_read_pci_cfg_dword(hw, pos + PCI_ERR_HEADER_LOG + 12);
if (ixgbe_removed(hw->hw_addr))
goto skip_bad_vf_detection;
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
case ixgbe_mac_X550:
device_id = IXGBE_DEV_ID_X550_VF;
break;
case ixgbe_mac_X550EM_x:
device_id = IXGBE_DEV_ID_X550EM_X_VF;
break;
case ixgbe_mac_x550em_a:
device_id = IXGBE_DEV_ID_X550EM_A_VF;
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
pcie_flr(vfdev);
pci_dev_put(vfdev);
}
pci_cleanup_aer_uncorrect_error_status(pdev);
}
adapter->vferr_refcount++;
return PCI_ERS_RESULT_RECOVERED;
skip_bad_vf_detection:
#endif
if (!test_bit(__IXGBE_SERVICE_INITED, &adapter->state))
return PCI_ERS_RESULT_DISCONNECT;
rtnl_lock();
netif_device_detach(netdev);
if (state == pci_channel_io_perm_failure) {
rtnl_unlock();
return PCI_ERS_RESULT_DISCONNECT;
}
if (netif_running(netdev))
ixgbe_close_suspend(adapter);
if (!test_and_set_bit(__IXGBE_DISABLED, &adapter->state))
pci_disable_device(pdev);
rtnl_unlock();
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
smp_mb__before_atomic();
clear_bit(__IXGBE_DISABLED, &adapter->state);
adapter->hw.hw_addr = adapter->io_addr;
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
rtnl_lock();
if (netif_running(netdev))
ixgbe_open(netdev);
netif_device_attach(netdev);
rtnl_unlock();
}
static int __init ixgbe_init_module(void)
{
int ret;
pr_info("%s - version %s\n", ixgbe_driver_string, ixgbe_driver_version);
pr_info("%s\n", ixgbe_copyright);
ixgbe_wq = create_singlethread_workqueue(ixgbe_driver_name);
if (!ixgbe_wq) {
pr_err("%s: Failed to create workqueue\n", ixgbe_driver_name);
return -ENOMEM;
}
ixgbe_dbg_init();
ret = pci_register_driver(&ixgbe_driver);
if (ret) {
destroy_workqueue(ixgbe_wq);
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
if (ixgbe_wq) {
destroy_workqueue(ixgbe_wq);
ixgbe_wq = NULL;
}
}
static int ixgbe_notify_dca(struct notifier_block *nb, unsigned long event,
void *p)
{
int ret_val;
ret_val = driver_for_each_device(&ixgbe_driver.driver, NULL, &event,
__ixgbe_notify_dca);
return ret_val ? NOTIFY_BAD : NOTIFY_DONE;
}
