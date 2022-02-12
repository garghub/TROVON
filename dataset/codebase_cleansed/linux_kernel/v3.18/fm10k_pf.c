static s32 fm10k_reset_hw_pf(struct fm10k_hw *hw)
{
s32 err;
u32 reg;
u16 i;
fm10k_write_reg(hw, FM10K_EIMR, FM10K_EIMR_DISABLE(ALL));
fm10k_write_reg(hw, FM10K_ITR2(0), 0);
fm10k_write_reg(hw, FM10K_INT_CTRL, 0);
for (i = 0; i < FM10K_TQMAP_TABLE_SIZE; i++) {
fm10k_write_reg(hw, FM10K_TQMAP(i), 0);
fm10k_write_reg(hw, FM10K_RQMAP(i), 0);
}
err = fm10k_disable_queues_generic(hw, FM10K_MAX_QUEUES);
if (err)
return err;
reg = fm10k_read_reg(hw, FM10K_DMA_CTRL);
if (reg & (FM10K_DMA_CTRL_TX_ACTIVE | FM10K_DMA_CTRL_RX_ACTIVE))
return FM10K_ERR_DMA_PENDING;
reg |= FM10K_DMA_CTRL_DATAPATH_RESET;
fm10k_write_reg(hw, FM10K_DMA_CTRL, reg);
fm10k_write_flush(hw);
udelay(FM10K_RESET_TIMEOUT);
reg = fm10k_read_reg(hw, FM10K_IP);
if (!(reg & FM10K_IP_NOTINRESET))
err = FM10K_ERR_RESET_FAILED;
return err;
}
static bool fm10k_is_ari_hierarchy_pf(struct fm10k_hw *hw)
{
u16 sriov_ctrl = fm10k_read_pci_cfg_word(hw, FM10K_PCIE_SRIOV_CTRL);
return !!(sriov_ctrl & FM10K_PCIE_SRIOV_CTRL_VFARI);
}
static s32 fm10k_init_hw_pf(struct fm10k_hw *hw)
{
u32 dma_ctrl, txqctl;
u16 i;
fm10k_write_reg(hw, FM10K_DGLORTDEC(fm10k_dglort_default), 0);
fm10k_write_reg(hw, FM10K_DGLORTMAP(fm10k_dglort_default),
FM10K_DGLORTMAP_ANY);
for (i = 1; i < FM10K_DGLORT_COUNT; i++)
fm10k_write_reg(hw, FM10K_DGLORTMAP(i), FM10K_DGLORTMAP_NONE);
fm10k_write_reg(hw, FM10K_ITR2(0), 0);
fm10k_write_reg(hw, FM10K_ITR2(FM10K_ITR_REG_COUNT_PF), 0);
for (i = 1; i < FM10K_ITR_REG_COUNT_PF; i++)
fm10k_write_reg(hw, FM10K_ITR2(i), i - 1);
fm10k_write_reg(hw, FM10K_INT_CTRL, FM10K_INT_CTRL_ENABLEMODERATOR);
txqctl = FM10K_TXQCTL_PF | FM10K_TXQCTL_UNLIMITED_BW |
(hw->mac.default_vid << FM10K_TXQCTL_VID_SHIFT);
for (i = 0; i < FM10K_MAX_QUEUES; i++) {
fm10k_write_reg(hw, FM10K_TQDLOC(i),
(i * FM10K_TQDLOC_BASE_32_DESC) |
FM10K_TQDLOC_SIZE_32_DESC);
fm10k_write_reg(hw, FM10K_TXQCTL(i), txqctl);
fm10k_write_reg(hw, FM10K_TPH_TXCTRL(i),
FM10K_TPH_TXCTRL_DESC_TPHEN |
FM10K_TPH_TXCTRL_DESC_RROEN |
FM10K_TPH_TXCTRL_DESC_WROEN |
FM10K_TPH_TXCTRL_DATA_RROEN);
fm10k_write_reg(hw, FM10K_TPH_RXCTRL(i),
FM10K_TPH_RXCTRL_DESC_TPHEN |
FM10K_TPH_RXCTRL_DESC_RROEN |
FM10K_TPH_RXCTRL_DATA_WROEN |
FM10K_TPH_RXCTRL_HDR_WROEN);
}
switch (hw->bus.speed) {
case fm10k_bus_speed_2500:
dma_ctrl = FM10K_DMA_CTRL_MAX_HOLD_1US_GEN1;
break;
case fm10k_bus_speed_5000:
dma_ctrl = FM10K_DMA_CTRL_MAX_HOLD_1US_GEN2;
break;
case fm10k_bus_speed_8000:
dma_ctrl = FM10K_DMA_CTRL_MAX_HOLD_1US_GEN3;
break;
default:
dma_ctrl = 0;
break;
}
fm10k_write_reg(hw, FM10K_DTXTCPFLGL, FM10K_TSO_FLAGS_LOW);
fm10k_write_reg(hw, FM10K_DTXTCPFLGH, FM10K_TSO_FLAGS_HI);
dma_ctrl |= FM10K_DMA_CTRL_TX_ENABLE | FM10K_DMA_CTRL_RX_ENABLE |
FM10K_DMA_CTRL_RX_DESC_SIZE | FM10K_DMA_CTRL_MINMSS_64 |
FM10K_DMA_CTRL_32_DESC;
fm10k_write_reg(hw, FM10K_DMA_CTRL, dma_ctrl);
hw->mac.max_queues = FM10K_MAX_QUEUES_PF;
hw->iov.total_vfs = fm10k_is_ari_hierarchy_pf(hw) ? 64 : 7;
return 0;
}
static bool fm10k_is_slot_appropriate_pf(struct fm10k_hw *hw)
{
return (hw->bus.speed == hw->bus_caps.speed) &&
(hw->bus.width == hw->bus_caps.width);
}
static s32 fm10k_update_vlan_pf(struct fm10k_hw *hw, u32 vid, u8 vsi, bool set)
{
u32 vlan_table, reg, mask, bit, len;
if (vsi > FM10K_VLAN_TABLE_VSI_MAX)
return FM10K_ERR_PARAM;
len = vid >> 16;
vid = (vid << 17) >> 17;
if (len >= FM10K_VLAN_TABLE_VID_MAX ||
vid >= FM10K_VLAN_TABLE_VID_MAX)
return FM10K_ERR_PARAM;
for (reg = FM10K_VLAN_TABLE(vsi, vid / 32), bit = vid % 32;
len < FM10K_VLAN_TABLE_VID_MAX;
len -= 32 - bit, reg++, bit = 0) {
vlan_table = fm10k_read_reg(hw, reg);
mask = (~(u32)0 >> ((len < 31) ? 31 - len : 0)) << bit;
mask &= set ? ~vlan_table : vlan_table;
if (mask)
fm10k_write_reg(hw, reg, vlan_table ^ mask);
}
return 0;
}
static s32 fm10k_read_mac_addr_pf(struct fm10k_hw *hw)
{
u8 perm_addr[ETH_ALEN];
u32 serial_num;
int i;
serial_num = fm10k_read_reg(hw, FM10K_SM_AREA(1));
if ((~serial_num) << 24)
return FM10K_ERR_INVALID_MAC_ADDR;
perm_addr[0] = (u8)(serial_num >> 24);
perm_addr[1] = (u8)(serial_num >> 16);
perm_addr[2] = (u8)(serial_num >> 8);
serial_num = fm10k_read_reg(hw, FM10K_SM_AREA(0));
if ((~serial_num) >> 24)
return FM10K_ERR_INVALID_MAC_ADDR;
perm_addr[3] = (u8)(serial_num >> 16);
perm_addr[4] = (u8)(serial_num >> 8);
perm_addr[5] = (u8)(serial_num);
for (i = 0; i < ETH_ALEN; i++) {
hw->mac.perm_addr[i] = perm_addr[i];
hw->mac.addr[i] = perm_addr[i];
}
return 0;
}
bool fm10k_glort_valid_pf(struct fm10k_hw *hw, u16 glort)
{
glort &= hw->mac.dglort_map >> FM10K_DGLORTMAP_MASK_SHIFT;
return glort == (hw->mac.dglort_map & FM10K_DGLORTMAP_NONE);
}
static s32 fm10k_update_xc_addr_pf(struct fm10k_hw *hw, u16 glort,
const u8 *mac, u16 vid, bool add, u8 flags)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
struct fm10k_mac_update mac_update;
u32 msg[5];
if (!fm10k_glort_valid_pf(hw, glort))
return FM10K_ERR_PARAM;
vid = (vid << 4) >> 4;
mac_update.mac_lower = cpu_to_le32(((u32)mac[2] << 24) |
((u32)mac[3] << 16) |
((u32)mac[4] << 8) |
((u32)mac[5]));
mac_update.mac_upper = cpu_to_le16(((u32)mac[0] << 8) |
((u32)mac[1]));
mac_update.vlan = cpu_to_le16(vid);
mac_update.glort = cpu_to_le16(glort);
mac_update.action = add ? 0 : 1;
mac_update.flags = flags;
fm10k_tlv_msg_init(msg, FM10K_PF_MSG_ID_UPDATE_MAC_FWD_RULE);
fm10k_tlv_attr_put_le_struct(msg, FM10K_PF_ATTR_ID_MAC_UPDATE,
&mac_update, sizeof(mac_update));
return mbx->ops.enqueue_tx(hw, mbx, msg);
}
static s32 fm10k_update_uc_addr_pf(struct fm10k_hw *hw, u16 glort,
const u8 *mac, u16 vid, bool add, u8 flags)
{
if (!is_valid_ether_addr(mac))
return FM10K_ERR_PARAM;
return fm10k_update_xc_addr_pf(hw, glort, mac, vid, add, flags);
}
static s32 fm10k_update_mc_addr_pf(struct fm10k_hw *hw, u16 glort,
const u8 *mac, u16 vid, bool add)
{
if (!is_multicast_ether_addr(mac))
return FM10K_ERR_PARAM;
return fm10k_update_xc_addr_pf(hw, glort, mac, vid, add, 0);
}
static s32 fm10k_update_xcast_mode_pf(struct fm10k_hw *hw, u16 glort, u8 mode)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 msg[3], xcast_mode;
if (mode > FM10K_XCAST_MODE_NONE)
return FM10K_ERR_PARAM;
if (!fm10k_glort_valid_pf(hw, glort))
return FM10K_ERR_PARAM;
xcast_mode = ((u32)mode << 16) | glort;
fm10k_tlv_msg_init(msg, FM10K_PF_MSG_ID_XCAST_MODES);
fm10k_tlv_attr_put_u32(msg, FM10K_PF_ATTR_ID_XCAST_MODE, xcast_mode);
return mbx->ops.enqueue_tx(hw, mbx, msg);
}
static void fm10k_update_int_moderator_pf(struct fm10k_hw *hw)
{
u32 i;
fm10k_write_reg(hw, FM10K_INT_CTRL, 0);
for (i = FM10K_ITR_REG_COUNT_PF - 1; i; i--) {
if (!fm10k_read_reg(hw, FM10K_MSIX_VECTOR_MASK(i)))
break;
}
fm10k_write_reg(hw, FM10K_ITR2(FM10K_ITR_REG_COUNT_PF), i);
if (!hw->iov.num_vfs)
fm10k_write_reg(hw, FM10K_ITR2(0), i);
fm10k_write_reg(hw, FM10K_INT_CTRL, FM10K_INT_CTRL_ENABLEMODERATOR);
}
static s32 fm10k_update_lport_state_pf(struct fm10k_hw *hw, u16 glort,
u16 count, bool enable)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 msg[3], lport_msg;
if (!count)
return 0;
if (!fm10k_glort_valid_pf(hw, glort))
return FM10K_ERR_PARAM;
lport_msg = ((u32)count << 16) | glort;
fm10k_tlv_msg_init(msg, enable ? FM10K_PF_MSG_ID_LPORT_CREATE :
FM10K_PF_MSG_ID_LPORT_DELETE);
fm10k_tlv_attr_put_u32(msg, FM10K_PF_ATTR_ID_PORT, lport_msg);
return mbx->ops.enqueue_tx(hw, mbx, msg);
}
static s32 fm10k_configure_dglort_map_pf(struct fm10k_hw *hw,
struct fm10k_dglort_cfg *dglort)
{
u16 glort, queue_count, vsi_count, pc_count;
u16 vsi, queue, pc, q_idx;
u32 txqctl, dglortdec, dglortmap;
if (!dglort)
return FM10K_ERR_PARAM;
if ((dglort->idx > 7) || (dglort->rss_l > 7) || (dglort->pc_l > 3) ||
(dglort->vsi_l > 6) || (dglort->vsi_b > 64) ||
(dglort->queue_l > 8) || (dglort->queue_b >= 256))
return FM10K_ERR_PARAM;
queue_count = 1 << (dglort->rss_l + dglort->pc_l);
vsi_count = 1 << (dglort->vsi_l + dglort->queue_l);
glort = dglort->glort;
q_idx = dglort->queue_b;
for (vsi = 0; vsi < vsi_count; vsi++, glort++) {
for (queue = 0; queue < queue_count; queue++, q_idx++) {
if (q_idx >= FM10K_MAX_QUEUES)
break;
fm10k_write_reg(hw, FM10K_TX_SGLORT(q_idx), glort);
fm10k_write_reg(hw, FM10K_RX_SGLORT(q_idx), glort);
}
}
queue_count = 1 << (dglort->queue_l + dglort->rss_l + dglort->vsi_l);
pc_count = 1 << dglort->pc_l;
for (pc = 0; pc < pc_count; pc++) {
q_idx = pc + dglort->queue_b;
for (queue = 0; queue < queue_count; queue++) {
if (q_idx >= FM10K_MAX_QUEUES)
break;
txqctl = fm10k_read_reg(hw, FM10K_TXQCTL(q_idx));
txqctl &= ~FM10K_TXQCTL_PC_MASK;
txqctl |= pc << FM10K_TXQCTL_PC_SHIFT;
fm10k_write_reg(hw, FM10K_TXQCTL(q_idx), txqctl);
q_idx += pc_count;
}
}
dglortdec = ((u32)(dglort->rss_l) << FM10K_DGLORTDEC_RSSLENGTH_SHIFT) |
((u32)(dglort->queue_b) << FM10K_DGLORTDEC_QBASE_SHIFT) |
((u32)(dglort->pc_l) << FM10K_DGLORTDEC_PCLENGTH_SHIFT) |
((u32)(dglort->vsi_b) << FM10K_DGLORTDEC_VSIBASE_SHIFT) |
((u32)(dglort->vsi_l) << FM10K_DGLORTDEC_VSILENGTH_SHIFT) |
((u32)(dglort->queue_l));
if (dglort->inner_rss)
dglortdec |= FM10K_DGLORTDEC_INNERRSS_ENABLE;
dglortmap = (dglort->idx == fm10k_dglort_default) ?
FM10K_DGLORTMAP_ANY : FM10K_DGLORTMAP_ZERO;
dglortmap <<= dglort->vsi_l + dglort->queue_l + dglort->shared_l;
dglortmap |= dglort->glort;
fm10k_write_reg(hw, FM10K_DGLORTDEC(dglort->idx), dglortdec);
fm10k_write_reg(hw, FM10K_DGLORTMAP(dglort->idx), dglortmap);
return 0;
}
u16 fm10k_queues_per_pool(struct fm10k_hw *hw)
{
u16 num_pools = hw->iov.num_pools;
return (num_pools > 32) ? 2 : (num_pools > 16) ? 4 : (num_pools > 8) ?
8 : FM10K_MAX_QUEUES_POOL;
}
u16 fm10k_vf_queue_index(struct fm10k_hw *hw, u16 vf_idx)
{
u16 num_vfs = hw->iov.num_vfs;
u16 vf_q_idx = FM10K_MAX_QUEUES;
vf_q_idx -= fm10k_queues_per_pool(hw) * (num_vfs - vf_idx);
return vf_q_idx;
}
static u16 fm10k_vectors_per_pool(struct fm10k_hw *hw)
{
u16 num_pools = hw->iov.num_pools;
return (num_pools > 32) ? 8 : (num_pools > 16) ? 16 :
FM10K_MAX_VECTORS_POOL;
}
static u16 fm10k_vf_vector_index(struct fm10k_hw *hw, u16 vf_idx)
{
u16 vf_v_idx = FM10K_MAX_VECTORS_PF;
vf_v_idx += fm10k_vectors_per_pool(hw) * vf_idx;
return vf_v_idx;
}
static s32 fm10k_iov_assign_resources_pf(struct fm10k_hw *hw, u16 num_vfs,
u16 num_pools)
{
u16 qmap_stride, qpp, vpp, vf_q_idx, vf_q_idx0, qmap_idx;
u32 vid = hw->mac.default_vid << FM10K_TXQCTL_VID_SHIFT;
int i, j;
if (num_pools > 64)
return FM10K_ERR_PARAM;
if ((num_vfs > num_pools) || (num_vfs > hw->iov.total_vfs))
return FM10K_ERR_PARAM;
hw->iov.num_vfs = num_vfs;
hw->iov.num_pools = num_pools;
qmap_stride = (num_vfs > 8) ? 32 : 256;
qpp = fm10k_queues_per_pool(hw);
vpp = fm10k_vectors_per_pool(hw);
vf_q_idx = fm10k_vf_queue_index(hw, 0);
qmap_idx = 0;
for (i = 0; i < num_vfs; i++) {
fm10k_write_reg(hw, FM10K_TC_MAXCREDIT(i), 0);
fm10k_write_reg(hw, FM10K_TC_RATE(i), 0);
fm10k_write_reg(hw, FM10K_TC_CREDIT(i),
FM10K_TC_CREDIT_CREDIT_MASK);
}
for (i = FM10K_VFMBMEM_LEN * num_vfs; i--;)
fm10k_write_reg(hw, FM10K_MBMEM(i), 0);
fm10k_write_reg(hw, FM10K_PFVFLREC(0), ~0);
fm10k_write_reg(hw, FM10K_PFVFLREC(1), ~0);
for (i = FM10K_MAX_QUEUES_PF; i < vf_q_idx; i++) {
fm10k_write_reg(hw, FM10K_TXDCTL(i), 0);
fm10k_write_reg(hw, FM10K_TXQCTL(i), FM10K_TXQCTL_PF | vid);
fm10k_write_reg(hw, FM10K_RXQCTL(i), FM10K_RXQCTL_PF);
}
for (i = FM10K_ITR_REG_COUNT_PF + 1; i < FM10K_ITR_REG_COUNT; i++) {
if (!(i & (vpp - 1)))
fm10k_write_reg(hw, FM10K_ITR2(i), i - vpp);
else
fm10k_write_reg(hw, FM10K_ITR2(i), i - 1);
}
fm10k_write_reg(hw, FM10K_ITR2(0),
fm10k_vf_vector_index(hw, num_vfs - 1));
for (i = 0; i < num_vfs; i++) {
vf_q_idx0 = vf_q_idx;
for (j = 0; j < qpp; j++, qmap_idx++, vf_q_idx++) {
fm10k_write_reg(hw, FM10K_TXDCTL(vf_q_idx), 0);
fm10k_write_reg(hw, FM10K_TXQCTL(vf_q_idx),
(i << FM10K_TXQCTL_TC_SHIFT) | i |
FM10K_TXQCTL_VF | vid);
fm10k_write_reg(hw, FM10K_RXDCTL(vf_q_idx),
FM10K_RXDCTL_WRITE_BACK_MIN_DELAY |
FM10K_RXDCTL_DROP_ON_EMPTY);
fm10k_write_reg(hw, FM10K_RXQCTL(vf_q_idx),
FM10K_RXQCTL_VF |
(i << FM10K_RXQCTL_VF_SHIFT));
fm10k_write_reg(hw, FM10K_TQMAP(qmap_idx), vf_q_idx);
fm10k_write_reg(hw, FM10K_RQMAP(qmap_idx), vf_q_idx);
}
for (; j < qmap_stride; j++, qmap_idx++) {
fm10k_write_reg(hw, FM10K_TQMAP(qmap_idx), vf_q_idx0);
fm10k_write_reg(hw, FM10K_RQMAP(qmap_idx), vf_q_idx0);
}
}
while (qmap_idx < FM10K_TQMAP_TABLE_SIZE) {
fm10k_write_reg(hw, FM10K_TQMAP(qmap_idx), 0);
fm10k_write_reg(hw, FM10K_RQMAP(qmap_idx), 0);
qmap_idx++;
}
return 0;
}
static s32 fm10k_iov_configure_tc_pf(struct fm10k_hw *hw, u16 vf_idx, int rate)
{
u32 interval = FM10K_TC_RATE_INTERVAL_4US_GEN3;
u32 tc_rate = FM10K_TC_RATE_QUANTA_MASK;
if (vf_idx >= hw->iov.num_vfs)
return FM10K_ERR_PARAM;
switch (hw->bus.speed) {
case fm10k_bus_speed_2500:
interval = FM10K_TC_RATE_INTERVAL_4US_GEN1;
break;
case fm10k_bus_speed_5000:
interval = FM10K_TC_RATE_INTERVAL_4US_GEN2;
break;
default:
break;
}
if (rate) {
if (rate > FM10K_VF_TC_MAX || rate < FM10K_VF_TC_MIN)
return FM10K_ERR_PARAM;
tc_rate = (rate * 128) / 125;
if (rate < 4000)
interval <<= 1;
else
tc_rate >>= 1;
}
fm10k_write_reg(hw, FM10K_TC_RATE(vf_idx), tc_rate | interval);
fm10k_write_reg(hw, FM10K_TC_MAXCREDIT(vf_idx), FM10K_TC_MAXCREDIT_64K);
fm10k_write_reg(hw, FM10K_TC_CREDIT(vf_idx), FM10K_TC_MAXCREDIT_64K);
return 0;
}
static s32 fm10k_iov_assign_int_moderator_pf(struct fm10k_hw *hw, u16 vf_idx)
{
u16 vf_v_idx, vf_v_limit, i;
if (vf_idx >= hw->iov.num_vfs)
return FM10K_ERR_PARAM;
vf_v_idx = fm10k_vf_vector_index(hw, vf_idx);
vf_v_limit = vf_v_idx + fm10k_vectors_per_pool(hw);
for (i = vf_v_limit - 1; i > vf_v_idx; i--) {
if (!fm10k_read_reg(hw, FM10K_MSIX_VECTOR_MASK(i)))
break;
}
if (vf_idx == (hw->iov.num_vfs - 1))
fm10k_write_reg(hw, FM10K_ITR2(0), i);
else
fm10k_write_reg(hw, FM10K_ITR2(vf_v_limit), i);
return 0;
}
static s32 fm10k_iov_assign_default_mac_vlan_pf(struct fm10k_hw *hw,
struct fm10k_vf_info *vf_info)
{
u16 qmap_stride, queues_per_pool, vf_q_idx, timeout, qmap_idx, i;
u32 msg[4], txdctl, txqctl, tdbal = 0, tdbah = 0;
s32 err = 0;
u16 vf_idx, vf_vid;
if (!vf_info || vf_info->vf_idx >= hw->iov.num_vfs)
return FM10K_ERR_PARAM;
qmap_stride = (hw->iov.num_vfs > 8) ? 32 : 256;
queues_per_pool = fm10k_queues_per_pool(hw);
vf_idx = vf_info->vf_idx;
vf_q_idx = fm10k_vf_queue_index(hw, vf_idx);
qmap_idx = qmap_stride * vf_idx;
fm10k_write_reg(hw, FM10K_TQMAP(qmap_idx), 0);
fm10k_write_reg(hw, FM10K_TXDCTL(vf_q_idx), 0);
if (vf_info->pf_vid)
vf_vid = vf_info->pf_vid | FM10K_VLAN_CLEAR;
else
vf_vid = vf_info->sw_vid;
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_MAC_VLAN);
fm10k_tlv_attr_put_mac_vlan(msg, FM10K_MAC_VLAN_MSG_DEFAULT_MAC,
vf_info->mac, vf_vid);
if (vf_info->mbx.ops.enqueue_tx)
vf_info->mbx.ops.enqueue_tx(hw, &vf_info->mbx, msg);
txdctl = fm10k_read_reg(hw, FM10K_TXDCTL(vf_q_idx));
for (timeout = 0; txdctl & FM10K_TXDCTL_ENABLE; timeout++) {
if (timeout == 10) {
err = FM10K_ERR_DMA_PENDING;
goto err_out;
}
usleep_range(100, 200);
txdctl = fm10k_read_reg(hw, FM10K_TXDCTL(vf_q_idx));
}
if (is_valid_ether_addr(vf_info->mac)) {
tdbal = (((u32)vf_info->mac[3]) << 24) |
(((u32)vf_info->mac[4]) << 16) |
(((u32)vf_info->mac[5]) << 8);
tdbah = (((u32)0xFF) << 24) |
(((u32)vf_info->mac[0]) << 16) |
(((u32)vf_info->mac[1]) << 8) |
((u32)vf_info->mac[2]);
}
fm10k_write_reg(hw, FM10K_TDBAL(vf_q_idx), tdbal);
fm10k_write_reg(hw, FM10K_TDBAH(vf_q_idx), tdbah);
err_out:
txqctl = ((u32)vf_vid << FM10K_TXQCTL_VID_SHIFT) &
FM10K_TXQCTL_VID_MASK;
txqctl |= (vf_idx << FM10K_TXQCTL_TC_SHIFT) |
FM10K_TXQCTL_VF | vf_idx;
for (i = 0; i < queues_per_pool; i++)
fm10k_write_reg(hw, FM10K_TXQCTL(vf_q_idx + i), txqctl);
fm10k_write_reg(hw, FM10K_TQMAP(qmap_idx), vf_q_idx);
return err;
}
static s32 fm10k_iov_reset_resources_pf(struct fm10k_hw *hw,
struct fm10k_vf_info *vf_info)
{
u16 qmap_stride, queues_per_pool, vf_q_idx, qmap_idx;
u32 tdbal = 0, tdbah = 0, txqctl, rxqctl;
u16 vf_v_idx, vf_v_limit, vf_vid;
u8 vf_idx = vf_info->vf_idx;
int i;
if (vf_idx >= hw->iov.num_vfs)
return FM10K_ERR_PARAM;
fm10k_write_reg(hw, FM10K_PFVFLREC(vf_idx / 32), 1 << (vf_idx % 32));
vf_info->mbx.timeout = 0;
if (vf_info->mbx.ops.disconnect)
vf_info->mbx.ops.disconnect(hw, &vf_info->mbx);
vf_v_idx = fm10k_vf_vector_index(hw, vf_idx);
vf_v_limit = vf_v_idx + fm10k_vectors_per_pool(hw);
qmap_stride = (hw->iov.num_vfs > 8) ? 32 : 256;
queues_per_pool = fm10k_queues_per_pool(hw);
qmap_idx = qmap_stride * vf_idx;
for (i = qmap_idx; i < (qmap_idx + qmap_stride); i++) {
fm10k_write_reg(hw, FM10K_TQMAP(i), 0);
fm10k_write_reg(hw, FM10K_RQMAP(i), 0);
}
vf_q_idx = fm10k_vf_queue_index(hw, vf_idx);
if (vf_info->pf_vid)
vf_vid = vf_info->pf_vid;
else
vf_vid = vf_info->sw_vid;
txqctl = ((u32)vf_vid << FM10K_TXQCTL_VID_SHIFT) |
(vf_idx << FM10K_TXQCTL_TC_SHIFT) |
FM10K_TXQCTL_VF | vf_idx;
rxqctl = FM10K_RXQCTL_VF | (vf_idx << FM10K_RXQCTL_VF_SHIFT);
for (i = vf_q_idx; i < (queues_per_pool + vf_q_idx); i++) {
fm10k_write_reg(hw, FM10K_TXDCTL(i), 0);
fm10k_write_reg(hw, FM10K_TXQCTL(i), txqctl);
fm10k_write_reg(hw, FM10K_RXDCTL(i),
FM10K_RXDCTL_WRITE_BACK_MIN_DELAY |
FM10K_RXDCTL_DROP_ON_EMPTY);
fm10k_write_reg(hw, FM10K_RXQCTL(i), rxqctl);
}
fm10k_write_reg(hw, FM10K_TC_MAXCREDIT(vf_idx), 0);
fm10k_write_reg(hw, FM10K_TC_RATE(vf_idx), 0);
fm10k_write_reg(hw, FM10K_TC_CREDIT(vf_idx),
FM10K_TC_CREDIT_CREDIT_MASK);
if (!vf_idx)
hw->mac.ops.update_int_moderator(hw);
else
hw->iov.ops.assign_int_moderator(hw, vf_idx - 1);
if (vf_idx == (hw->iov.num_vfs - 1))
fm10k_write_reg(hw, FM10K_ITR2(0), vf_v_idx);
else
fm10k_write_reg(hw, FM10K_ITR2(vf_v_limit), vf_v_idx);
for (vf_v_idx++; vf_v_idx < vf_v_limit; vf_v_idx++)
fm10k_write_reg(hw, FM10K_ITR2(vf_v_idx), vf_v_idx - 1);
for (i = FM10K_VFMBMEM_LEN; i--;)
fm10k_write_reg(hw, FM10K_MBMEM_VF(vf_idx, i), 0);
for (i = FM10K_VLAN_TABLE_SIZE; i--;)
fm10k_write_reg(hw, FM10K_VLAN_TABLE(vf_info->vsi, i), 0);
for (i = FM10K_RETA_SIZE; i--;)
fm10k_write_reg(hw, FM10K_RETA(vf_info->vsi, i), 0);
for (i = FM10K_RSSRK_SIZE; i--;)
fm10k_write_reg(hw, FM10K_RSSRK(vf_info->vsi, i), 0);
fm10k_write_reg(hw, FM10K_MRQC(vf_info->vsi), 0);
if (is_valid_ether_addr(vf_info->mac)) {
tdbal = (((u32)vf_info->mac[3]) << 24) |
(((u32)vf_info->mac[4]) << 16) |
(((u32)vf_info->mac[5]) << 8);
tdbah = (((u32)0xFF) << 24) |
(((u32)vf_info->mac[0]) << 16) |
(((u32)vf_info->mac[1]) << 8) |
((u32)vf_info->mac[2]);
}
for (i = queues_per_pool; i--;) {
fm10k_write_reg(hw, FM10K_TDBAL(vf_q_idx + i), tdbal);
fm10k_write_reg(hw, FM10K_TDBAH(vf_q_idx + i), tdbah);
fm10k_write_reg(hw, FM10K_TQMAP(qmap_idx + i), vf_q_idx + i);
fm10k_write_reg(hw, FM10K_RQMAP(qmap_idx + i), vf_q_idx + i);
}
return 0;
}
static s32 fm10k_iov_set_lport_pf(struct fm10k_hw *hw,
struct fm10k_vf_info *vf_info,
u16 lport_idx, u8 flags)
{
u16 glort = (hw->mac.dglort_map + lport_idx) & FM10K_DGLORTMAP_NONE;
if (!fm10k_glort_valid_pf(hw, glort))
return FM10K_ERR_PARAM;
vf_info->vf_flags = flags | FM10K_VF_FLAG_NONE_CAPABLE;
vf_info->glort = glort;
return 0;
}
static void fm10k_iov_reset_lport_pf(struct fm10k_hw *hw,
struct fm10k_vf_info *vf_info)
{
u32 msg[1];
if (FM10K_VF_FLAG_ENABLED(vf_info)) {
fm10k_update_lport_state_pf(hw, vf_info->glort, 1, false);
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_LPORT_STATE);
vf_info->mbx.ops.enqueue_tx(hw, &vf_info->mbx, msg);
}
vf_info->vf_flags = 0;
vf_info->glort = 0;
}
static void fm10k_iov_update_stats_pf(struct fm10k_hw *hw,
struct fm10k_hw_stats_q *q,
u16 vf_idx)
{
u32 idx, qpp;
qpp = fm10k_queues_per_pool(hw);
idx = fm10k_vf_queue_index(hw, vf_idx);
fm10k_update_hw_stats_q(hw, q, idx, qpp);
}
static s32 fm10k_iov_report_timestamp_pf(struct fm10k_hw *hw,
struct fm10k_vf_info *vf_info,
u64 timestamp)
{
u32 msg[4];
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_1588);
fm10k_tlv_attr_put_u64(msg, FM10K_1588_MSG_TIMESTAMP, timestamp);
return vf_info->mbx.ops.enqueue_tx(hw, &vf_info->mbx, msg);
}
s32 fm10k_iov_msg_msix_pf(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
struct fm10k_vf_info *vf_info = (struct fm10k_vf_info *)mbx;
u8 vf_idx = vf_info->vf_idx;
return hw->iov.ops.assign_int_moderator(hw, vf_idx);
}
s32 fm10k_iov_msg_mac_vlan_pf(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
struct fm10k_vf_info *vf_info = (struct fm10k_vf_info *)mbx;
int err = 0;
u8 mac[ETH_ALEN];
u32 *result;
u16 vlan;
u32 vid;
if (!FM10K_VF_FLAG_ENABLED(vf_info))
err = FM10K_ERR_PARAM;
if (!err && !!results[FM10K_MAC_VLAN_MSG_VLAN]) {
result = results[FM10K_MAC_VLAN_MSG_VLAN];
err = fm10k_tlv_attr_get_u32(result, &vid);
if (err)
return err;
if (!vid || (vid == FM10K_VLAN_CLEAR)) {
if (vf_info->pf_vid)
vid |= vf_info->pf_vid;
else
vid |= vf_info->sw_vid;
} else if (vid != vf_info->pf_vid) {
return FM10K_ERR_PARAM;
}
err = hw->mac.ops.update_vlan(hw, vid, vf_info->vsi,
!(vid & FM10K_VLAN_CLEAR));
}
if (!err && !!results[FM10K_MAC_VLAN_MSG_MAC]) {
result = results[FM10K_MAC_VLAN_MSG_MAC];
err = fm10k_tlv_attr_get_mac_vlan(result, mac, &vlan);
if (err)
return err;
if (is_valid_ether_addr(vf_info->mac) &&
memcmp(mac, vf_info->mac, ETH_ALEN))
return FM10K_ERR_PARAM;
if (!vlan || (vlan == FM10K_VLAN_CLEAR)) {
if (vf_info->pf_vid)
vlan |= vf_info->pf_vid;
else
vlan |= vf_info->sw_vid;
} else if (vf_info->pf_vid) {
return FM10K_ERR_PARAM;
}
err = hw->mac.ops.update_uc_addr(hw, vf_info->glort, mac, vlan,
!(vlan & FM10K_VLAN_CLEAR), 0);
}
if (!err && !!results[FM10K_MAC_VLAN_MSG_MULTICAST]) {
result = results[FM10K_MAC_VLAN_MSG_MULTICAST];
err = fm10k_tlv_attr_get_mac_vlan(result, mac, &vlan);
if (err)
return err;
if (!(vf_info->vf_flags & FM10K_VF_FLAG_MULTI_ENABLED))
return FM10K_ERR_PARAM;
if (!vlan || (vlan == FM10K_VLAN_CLEAR)) {
if (vf_info->pf_vid)
vlan |= vf_info->pf_vid;
else
vlan |= vf_info->sw_vid;
} else if (vf_info->pf_vid) {
return FM10K_ERR_PARAM;
}
err = hw->mac.ops.update_mc_addr(hw, vf_info->glort, mac,
!(vlan & FM10K_VLAN_CLEAR), 0);
}
return err;
}
static u8 fm10k_iov_supported_xcast_mode_pf(struct fm10k_vf_info *vf_info,
u8 mode)
{
u8 vf_flags = vf_info->vf_flags;
switch (mode) {
case FM10K_XCAST_MODE_PROMISC:
if (vf_flags & FM10K_VF_FLAG_PROMISC_CAPABLE)
return FM10K_XCAST_MODE_PROMISC;
case FM10K_XCAST_MODE_ALLMULTI:
if (vf_flags & FM10K_VF_FLAG_ALLMULTI_CAPABLE)
return FM10K_XCAST_MODE_ALLMULTI;
case FM10K_XCAST_MODE_MULTI:
if (vf_flags & FM10K_VF_FLAG_MULTI_CAPABLE)
return FM10K_XCAST_MODE_MULTI;
case FM10K_XCAST_MODE_NONE:
if (vf_flags & FM10K_VF_FLAG_NONE_CAPABLE)
return FM10K_XCAST_MODE_NONE;
default:
break;
}
return FM10K_XCAST_MODE_DISABLE;
}
s32 fm10k_iov_msg_lport_state_pf(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
struct fm10k_vf_info *vf_info = (struct fm10k_vf_info *)mbx;
u32 *result;
s32 err = 0;
u32 msg[2];
u8 mode = 0;
if (!(vf_info->vf_flags & FM10K_VF_FLAG_NONE_CAPABLE))
return FM10K_ERR_PARAM;
if (!!results[FM10K_LPORT_STATE_MSG_XCAST_MODE]) {
result = results[FM10K_LPORT_STATE_MSG_XCAST_MODE];
err = fm10k_tlv_attr_get_u8(result, &mode);
if (err)
return FM10K_ERR_PARAM;
mode = fm10k_iov_supported_xcast_mode_pf(vf_info, mode);
if (!(FM10K_VF_FLAG_ENABLED(vf_info) & (1 << mode)))
fm10k_update_xcast_mode_pf(hw, vf_info->glort, mode);
mode = FM10K_VF_FLAG_SET_MODE(mode);
} else if (!results[FM10K_LPORT_STATE_MSG_DISABLE]) {
if (FM10K_VF_FLAG_ENABLED(vf_info))
err = fm10k_update_lport_state_pf(hw, vf_info->glort,
1, false);
hw->iov.ops.configure_tc(hw, vf_info->vf_idx, vf_info->rate);
mode = FM10K_VF_FLAG_SET_MODE_NONE;
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_LPORT_STATE);
fm10k_tlv_attr_put_bool(msg, FM10K_LPORT_STATE_MSG_READY);
mbx->ops.enqueue_tx(hw, mbx, msg);
}
if (!err && (!FM10K_VF_FLAG_ENABLED(vf_info) != !mode))
err = fm10k_update_lport_state_pf(hw, vf_info->glort, 1,
!!mode);
mode |= FM10K_VF_FLAG_CAPABLE(vf_info);
if (!err)
vf_info->vf_flags = mode;
return err;
}
static void fm10k_update_hw_stats_pf(struct fm10k_hw *hw,
struct fm10k_hw_stats *stats)
{
u32 timeout, ur, ca, um, xec, vlan_drop, loopback_drop, nodesc_drop;
u32 id, id_prev;
id = fm10k_read_reg(hw, FM10K_TXQCTL(0));
do {
timeout = fm10k_read_hw_stats_32b(hw, FM10K_STATS_TIMEOUT,
&stats->timeout);
ur = fm10k_read_hw_stats_32b(hw, FM10K_STATS_UR, &stats->ur);
ca = fm10k_read_hw_stats_32b(hw, FM10K_STATS_CA, &stats->ca);
um = fm10k_read_hw_stats_32b(hw, FM10K_STATS_UM, &stats->um);
xec = fm10k_read_hw_stats_32b(hw, FM10K_STATS_XEC, &stats->xec);
vlan_drop = fm10k_read_hw_stats_32b(hw, FM10K_STATS_VLAN_DROP,
&stats->vlan_drop);
loopback_drop = fm10k_read_hw_stats_32b(hw,
FM10K_STATS_LOOPBACK_DROP,
&stats->loopback_drop);
nodesc_drop = fm10k_read_hw_stats_32b(hw,
FM10K_STATS_NODESC_DROP,
&stats->nodesc_drop);
id_prev = id;
id = fm10k_read_reg(hw, FM10K_TXQCTL(0));
} while ((id ^ id_prev) & FM10K_TXQCTL_ID_MASK);
id &= FM10K_TXQCTL_ID_MASK;
id |= FM10K_STAT_VALID;
if (stats->stats_idx == id) {
stats->timeout.count += timeout;
stats->ur.count += ur;
stats->ca.count += ca;
stats->um.count += um;
stats->xec.count += xec;
stats->vlan_drop.count += vlan_drop;
stats->loopback_drop.count += loopback_drop;
stats->nodesc_drop.count += nodesc_drop;
}
fm10k_update_hw_base_32b(&stats->timeout, timeout);
fm10k_update_hw_base_32b(&stats->ur, ur);
fm10k_update_hw_base_32b(&stats->ca, ca);
fm10k_update_hw_base_32b(&stats->um, um);
fm10k_update_hw_base_32b(&stats->xec, xec);
fm10k_update_hw_base_32b(&stats->vlan_drop, vlan_drop);
fm10k_update_hw_base_32b(&stats->loopback_drop, loopback_drop);
fm10k_update_hw_base_32b(&stats->nodesc_drop, nodesc_drop);
stats->stats_idx = id;
fm10k_update_hw_stats_q(hw, stats->q, 0, hw->mac.max_queues);
}
static void fm10k_rebind_hw_stats_pf(struct fm10k_hw *hw,
struct fm10k_hw_stats *stats)
{
fm10k_unbind_hw_stats_32b(&stats->timeout);
fm10k_unbind_hw_stats_32b(&stats->ur);
fm10k_unbind_hw_stats_32b(&stats->ca);
fm10k_unbind_hw_stats_32b(&stats->um);
fm10k_unbind_hw_stats_32b(&stats->xec);
fm10k_unbind_hw_stats_32b(&stats->vlan_drop);
fm10k_unbind_hw_stats_32b(&stats->loopback_drop);
fm10k_unbind_hw_stats_32b(&stats->nodesc_drop);
fm10k_unbind_hw_stats_q(stats->q, 0, hw->mac.max_queues);
fm10k_update_hw_stats_pf(hw, stats);
}
static void fm10k_set_dma_mask_pf(struct fm10k_hw *hw, u64 dma_mask)
{
u32 phyaddr = (u32)(dma_mask >> 32);
fm10k_write_reg(hw, FM10K_PHYADDR, phyaddr);
}
static s32 fm10k_get_fault_pf(struct fm10k_hw *hw, int type,
struct fm10k_fault *fault)
{
u32 func;
switch (type) {
case FM10K_PCA_FAULT:
case FM10K_THI_FAULT:
case FM10K_FUM_FAULT:
break;
default:
return FM10K_ERR_PARAM;
}
func = fm10k_read_reg(hw, type + FM10K_FAULT_FUNC);
if (!(func & FM10K_FAULT_FUNC_VALID))
return FM10K_ERR_PARAM;
fault->address = fm10k_read_reg(hw, type + FM10K_FAULT_ADDR_HI);
fault->address <<= 32;
fault->address = fm10k_read_reg(hw, type + FM10K_FAULT_ADDR_LO);
fault->specinfo = fm10k_read_reg(hw, type + FM10K_FAULT_SPECINFO);
fm10k_write_reg(hw, type + FM10K_FAULT_FUNC, FM10K_FAULT_FUNC_VALID);
if (func & FM10K_FAULT_FUNC_PF)
fault->func = 0;
else
fault->func = 1 + ((func & FM10K_FAULT_FUNC_VF_MASK) >>
FM10K_FAULT_FUNC_VF_SHIFT);
fault->type = func & FM10K_FAULT_FUNC_TYPE_MASK;
return 0;
}
static s32 fm10k_request_lport_map_pf(struct fm10k_hw *hw)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 msg[1];
fm10k_tlv_msg_init(msg, FM10K_PF_MSG_ID_LPORT_MAP);
return mbx->ops.enqueue_tx(hw, mbx, msg);
}
static s32 fm10k_get_host_state_pf(struct fm10k_hw *hw, bool *switch_ready)
{
s32 ret_val = 0;
u32 dma_ctrl2;
dma_ctrl2 = fm10k_read_reg(hw, FM10K_DMA_CTRL2);
if (!(dma_ctrl2 & FM10K_DMA_CTRL2_SWITCH_READY))
goto out;
ret_val = fm10k_get_host_state_generic(hw, switch_ready);
if (ret_val)
goto out;
if (hw->mac.dglort_map == FM10K_DGLORTMAP_NONE)
ret_val = fm10k_request_lport_map_pf(hw);
out:
return ret_val;
}
s32 fm10k_msg_lport_map_pf(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
u16 glort, mask;
u32 dglort_map;
s32 err;
err = fm10k_tlv_attr_get_u32(results[FM10K_PF_ATTR_ID_LPORT_MAP],
&dglort_map);
if (err)
return err;
glort = FM10K_MSG_HDR_FIELD_GET(dglort_map, LPORT_MAP_GLORT);
mask = FM10K_MSG_HDR_FIELD_GET(dglort_map, LPORT_MAP_MASK);
if (!mask || (glort & ~mask))
return FM10K_ERR_PARAM;
if (((~(mask - 1) & mask) + mask) & FM10K_DGLORTMAP_NONE)
return FM10K_ERR_PARAM;
hw->mac.dglort_map = dglort_map;
return 0;
}
s32 fm10k_msg_update_pvid_pf(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
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
hw->mac.default_vid = pvid;
return 0;
}
static void fm10k_record_global_table_data(struct fm10k_global_table_data *from,
struct fm10k_swapi_table_info *to)
{
to->used = le32_to_cpu(from->used);
to->avail = le32_to_cpu(from->avail);
}
s32 fm10k_msg_err_pf(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
struct fm10k_swapi_error err_msg;
s32 err;
err = fm10k_tlv_attr_get_le_struct(results[FM10K_PF_ATTR_ID_ERR],
&err_msg, sizeof(err_msg));
if (err)
return err;
fm10k_record_global_table_data(&err_msg.mac, &hw->swapi.mac);
fm10k_record_global_table_data(&err_msg.nexthop, &hw->swapi.nexthop);
fm10k_record_global_table_data(&err_msg.ffu, &hw->swapi.ffu);
hw->swapi.status = le32_to_cpu(err_msg.status);
return 0;
}
static s32 fm10k_adjust_systime_pf(struct fm10k_hw *hw, s32 ppb)
{
u64 systime_adjust;
if (!hw->sw_addr)
return ppb ? FM10K_ERR_PARAM : 0;
systime_adjust = (ppb < 0) ? -ppb : ppb;
systime_adjust <<= 31;
do_div(systime_adjust, 1953125);
if (systime_adjust > FM10K_SW_SYSTIME_ADJUST_MASK)
return FM10K_ERR_PARAM;
if (ppb < 0)
systime_adjust |= FM10K_SW_SYSTIME_ADJUST_DIR_NEGATIVE;
fm10k_write_sw_reg(hw, FM10K_SW_SYSTIME_ADJUST, (u32)systime_adjust);
return 0;
}
static u64 fm10k_read_systime_pf(struct fm10k_hw *hw)
{
u32 systime_l, systime_h, systime_tmp;
systime_h = fm10k_read_reg(hw, FM10K_SYSTIME + 1);
do {
systime_tmp = systime_h;
systime_l = fm10k_read_reg(hw, FM10K_SYSTIME);
systime_h = fm10k_read_reg(hw, FM10K_SYSTIME + 1);
} while (systime_tmp != systime_h);
return ((u64)systime_h << 32) | systime_l;
}
static s32 fm10k_get_invariants_pf(struct fm10k_hw *hw)
{
fm10k_get_invariants_generic(hw);
return fm10k_sm_mbx_init(hw, &hw->mbx, fm10k_msg_data_pf);
}
