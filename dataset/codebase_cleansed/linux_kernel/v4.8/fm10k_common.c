s32 fm10k_get_bus_info_generic(struct fm10k_hw *hw)
{
u16 link_cap, link_status, device_cap, device_control;
link_cap = fm10k_read_pci_cfg_word(hw, FM10K_PCIE_LINK_CAP);
switch (link_cap & FM10K_PCIE_LINK_WIDTH) {
case FM10K_PCIE_LINK_WIDTH_1:
hw->bus_caps.width = fm10k_bus_width_pcie_x1;
break;
case FM10K_PCIE_LINK_WIDTH_2:
hw->bus_caps.width = fm10k_bus_width_pcie_x2;
break;
case FM10K_PCIE_LINK_WIDTH_4:
hw->bus_caps.width = fm10k_bus_width_pcie_x4;
break;
case FM10K_PCIE_LINK_WIDTH_8:
hw->bus_caps.width = fm10k_bus_width_pcie_x8;
break;
default:
hw->bus_caps.width = fm10k_bus_width_unknown;
break;
}
switch (link_cap & FM10K_PCIE_LINK_SPEED) {
case FM10K_PCIE_LINK_SPEED_2500:
hw->bus_caps.speed = fm10k_bus_speed_2500;
break;
case FM10K_PCIE_LINK_SPEED_5000:
hw->bus_caps.speed = fm10k_bus_speed_5000;
break;
case FM10K_PCIE_LINK_SPEED_8000:
hw->bus_caps.speed = fm10k_bus_speed_8000;
break;
default:
hw->bus_caps.speed = fm10k_bus_speed_unknown;
break;
}
device_cap = fm10k_read_pci_cfg_word(hw, FM10K_PCIE_DEV_CAP);
switch (device_cap & FM10K_PCIE_DEV_CAP_PAYLOAD) {
case FM10K_PCIE_DEV_CAP_PAYLOAD_128:
hw->bus_caps.payload = fm10k_bus_payload_128;
break;
case FM10K_PCIE_DEV_CAP_PAYLOAD_256:
hw->bus_caps.payload = fm10k_bus_payload_256;
break;
case FM10K_PCIE_DEV_CAP_PAYLOAD_512:
hw->bus_caps.payload = fm10k_bus_payload_512;
break;
default:
hw->bus_caps.payload = fm10k_bus_payload_unknown;
break;
}
link_status = fm10k_read_pci_cfg_word(hw, FM10K_PCIE_LINK_STATUS);
switch (link_status & FM10K_PCIE_LINK_WIDTH) {
case FM10K_PCIE_LINK_WIDTH_1:
hw->bus.width = fm10k_bus_width_pcie_x1;
break;
case FM10K_PCIE_LINK_WIDTH_2:
hw->bus.width = fm10k_bus_width_pcie_x2;
break;
case FM10K_PCIE_LINK_WIDTH_4:
hw->bus.width = fm10k_bus_width_pcie_x4;
break;
case FM10K_PCIE_LINK_WIDTH_8:
hw->bus.width = fm10k_bus_width_pcie_x8;
break;
default:
hw->bus.width = fm10k_bus_width_unknown;
break;
}
switch (link_status & FM10K_PCIE_LINK_SPEED) {
case FM10K_PCIE_LINK_SPEED_2500:
hw->bus.speed = fm10k_bus_speed_2500;
break;
case FM10K_PCIE_LINK_SPEED_5000:
hw->bus.speed = fm10k_bus_speed_5000;
break;
case FM10K_PCIE_LINK_SPEED_8000:
hw->bus.speed = fm10k_bus_speed_8000;
break;
default:
hw->bus.speed = fm10k_bus_speed_unknown;
break;
}
device_control = fm10k_read_pci_cfg_word(hw, FM10K_PCIE_DEV_CTRL);
switch (device_control & FM10K_PCIE_DEV_CTRL_PAYLOAD) {
case FM10K_PCIE_DEV_CTRL_PAYLOAD_128:
hw->bus.payload = fm10k_bus_payload_128;
break;
case FM10K_PCIE_DEV_CTRL_PAYLOAD_256:
hw->bus.payload = fm10k_bus_payload_256;
break;
case FM10K_PCIE_DEV_CTRL_PAYLOAD_512:
hw->bus.payload = fm10k_bus_payload_512;
break;
default:
hw->bus.payload = fm10k_bus_payload_unknown;
break;
}
return 0;
}
static u16 fm10k_get_pcie_msix_count_generic(struct fm10k_hw *hw)
{
u16 msix_count;
msix_count = fm10k_read_pci_cfg_word(hw, FM10K_PCI_MSIX_MSG_CTRL);
msix_count &= FM10K_PCI_MSIX_MSG_CTRL_TBL_SZ_MASK;
msix_count++;
if (msix_count > FM10K_MAX_MSIX_VECTORS)
msix_count = FM10K_MAX_MSIX_VECTORS;
return msix_count;
}
s32 fm10k_get_invariants_generic(struct fm10k_hw *hw)
{
struct fm10k_mac_info *mac = &hw->mac;
mac->dglort_map = FM10K_DGLORTMAP_NONE;
mac->max_msix_vectors = fm10k_get_pcie_msix_count_generic(hw);
return 0;
}
s32 fm10k_start_hw_generic(struct fm10k_hw *hw)
{
hw->mac.tx_ready = true;
return 0;
}
s32 fm10k_disable_queues_generic(struct fm10k_hw *hw, u16 q_cnt)
{
u32 reg;
u16 i, time;
hw->mac.tx_ready = false;
for (i = 0; i < q_cnt; i++) {
reg = fm10k_read_reg(hw, FM10K_TXDCTL(i));
fm10k_write_reg(hw, FM10K_TXDCTL(i),
reg & ~FM10K_TXDCTL_ENABLE);
reg = fm10k_read_reg(hw, FM10K_RXQCTL(i));
fm10k_write_reg(hw, FM10K_RXQCTL(i),
reg & ~FM10K_RXQCTL_ENABLE);
}
fm10k_write_flush(hw);
udelay(1);
for (i = 0, time = FM10K_QUEUE_DISABLE_TIMEOUT; time;) {
if (i == q_cnt)
return 0;
reg = fm10k_read_reg(hw, FM10K_TXDCTL(i));
if (!~reg || !(reg & FM10K_TXDCTL_ENABLE)) {
reg = fm10k_read_reg(hw, FM10K_RXQCTL(i));
if (!~reg || !(reg & FM10K_RXQCTL_ENABLE)) {
i++;
continue;
}
}
time--;
if (time)
udelay(1);
}
return FM10K_ERR_REQUESTS_PENDING;
}
s32 fm10k_stop_hw_generic(struct fm10k_hw *hw)
{
return fm10k_disable_queues_generic(hw, hw->mac.max_queues);
}
u32 fm10k_read_hw_stats_32b(struct fm10k_hw *hw, u32 addr,
struct fm10k_hw_stat *stat)
{
u32 delta = fm10k_read_reg(hw, addr) - stat->base_l;
if (FM10K_REMOVED(hw->hw_addr))
stat->base_h = 0;
return delta;
}
static u64 fm10k_read_hw_stats_48b(struct fm10k_hw *hw, u32 addr,
struct fm10k_hw_stat *stat)
{
u32 count_l;
u32 count_h;
u32 count_tmp;
u64 delta;
count_h = fm10k_read_reg(hw, addr + 1);
do {
count_tmp = count_h;
count_l = fm10k_read_reg(hw, addr);
count_h = fm10k_read_reg(hw, addr + 1);
} while (count_h != count_tmp);
delta = ((u64)(count_h - stat->base_h) << 32) + count_l;
delta -= stat->base_l;
return delta & FM10K_48_BIT_MASK;
}
static void fm10k_update_hw_base_48b(struct fm10k_hw_stat *stat, u64 delta)
{
if (!delta)
return;
delta += stat->base_l;
stat->base_l = (u32)delta;
stat->base_h += (u32)(delta >> 32);
}
static void fm10k_update_hw_stats_tx_q(struct fm10k_hw *hw,
struct fm10k_hw_stats_q *q,
u32 idx)
{
u32 id_tx, id_tx_prev, tx_packets;
u64 tx_bytes = 0;
id_tx = fm10k_read_reg(hw, FM10K_TXQCTL(idx));
do {
tx_packets = fm10k_read_hw_stats_32b(hw, FM10K_QPTC(idx),
&q->tx_packets);
if (tx_packets)
tx_bytes = fm10k_read_hw_stats_48b(hw,
FM10K_QBTC_L(idx),
&q->tx_bytes);
id_tx_prev = id_tx;
id_tx = fm10k_read_reg(hw, FM10K_TXQCTL(idx));
} while ((id_tx ^ id_tx_prev) & FM10K_TXQCTL_ID_MASK);
id_tx &= FM10K_TXQCTL_ID_MASK;
id_tx |= FM10K_STAT_VALID;
if (q->tx_stats_idx == id_tx) {
q->tx_packets.count += tx_packets;
q->tx_bytes.count += tx_bytes;
}
fm10k_update_hw_base_32b(&q->tx_packets, tx_packets);
fm10k_update_hw_base_48b(&q->tx_bytes, tx_bytes);
q->tx_stats_idx = id_tx;
}
static void fm10k_update_hw_stats_rx_q(struct fm10k_hw *hw,
struct fm10k_hw_stats_q *q,
u32 idx)
{
u32 id_rx, id_rx_prev, rx_packets, rx_drops;
u64 rx_bytes = 0;
id_rx = fm10k_read_reg(hw, FM10K_RXQCTL(idx));
do {
rx_drops = fm10k_read_hw_stats_32b(hw, FM10K_QPRDC(idx),
&q->rx_drops);
rx_packets = fm10k_read_hw_stats_32b(hw, FM10K_QPRC(idx),
&q->rx_packets);
if (rx_packets)
rx_bytes = fm10k_read_hw_stats_48b(hw,
FM10K_QBRC_L(idx),
&q->rx_bytes);
id_rx_prev = id_rx;
id_rx = fm10k_read_reg(hw, FM10K_RXQCTL(idx));
} while ((id_rx ^ id_rx_prev) & FM10K_RXQCTL_ID_MASK);
id_rx &= FM10K_RXQCTL_ID_MASK;
id_rx |= FM10K_STAT_VALID;
if (q->rx_stats_idx == id_rx) {
q->rx_drops.count += rx_drops;
q->rx_packets.count += rx_packets;
q->rx_bytes.count += rx_bytes;
}
fm10k_update_hw_base_32b(&q->rx_drops, rx_drops);
fm10k_update_hw_base_32b(&q->rx_packets, rx_packets);
fm10k_update_hw_base_48b(&q->rx_bytes, rx_bytes);
q->rx_stats_idx = id_rx;
}
void fm10k_update_hw_stats_q(struct fm10k_hw *hw, struct fm10k_hw_stats_q *q,
u32 idx, u32 count)
{
u32 i;
for (i = 0; i < count; i++, idx++, q++) {
fm10k_update_hw_stats_tx_q(hw, q, idx);
fm10k_update_hw_stats_rx_q(hw, q, idx);
}
}
void fm10k_unbind_hw_stats_q(struct fm10k_hw_stats_q *q, u32 idx, u32 count)
{
u32 i;
for (i = 0; i < count; i++, idx++, q++) {
q->rx_stats_idx = 0;
q->tx_stats_idx = 0;
}
}
s32 fm10k_get_host_state_generic(struct fm10k_hw *hw, bool *host_ready)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
struct fm10k_mac_info *mac = &hw->mac;
s32 ret_val = 0;
u32 txdctl = fm10k_read_reg(hw, FM10K_TXDCTL(0));
mbx->ops.process(hw, mbx);
if (!(~txdctl) || !(txdctl & FM10K_TXDCTL_ENABLE))
mac->get_host_state = true;
if (!mac->get_host_state || !(~txdctl))
goto out;
if (hw->mac.tx_ready && !(txdctl & FM10K_TXDCTL_ENABLE)) {
ret_val = FM10K_ERR_RESET_REQUESTED;
goto out;
}
if (!mbx->timeout) {
ret_val = FM10K_ERR_RESET_REQUESTED;
goto out;
}
if (!mbx->ops.tx_ready(mbx, FM10K_VFMBX_MSG_MTU))
goto out;
if (mac->dglort_map == FM10K_DGLORTMAP_NONE) {
if (hw->mac.ops.request_lport_map)
ret_val = hw->mac.ops.request_lport_map(hw);
goto out;
}
mac->get_host_state = false;
out:
*host_ready = !mac->get_host_state;
return ret_val;
}
