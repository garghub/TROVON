static s32 fm10k_stop_hw_vf(struct fm10k_hw *hw)
{
u8 *perm_addr = hw->mac.perm_addr;
u32 bal = 0, bah = 0;
s32 err;
u16 i;
err = fm10k_stop_hw_generic(hw);
if (err)
return err;
if (is_valid_ether_addr(perm_addr)) {
bal = (((u32)perm_addr[3]) << 24) |
(((u32)perm_addr[4]) << 16) |
(((u32)perm_addr[5]) << 8);
bah = (((u32)0xFF) << 24) |
(((u32)perm_addr[0]) << 16) |
(((u32)perm_addr[1]) << 8) |
((u32)perm_addr[2]);
}
for (i = 0; i < hw->mac.max_queues; i++) {
fm10k_write_reg(hw, FM10K_TDBAL(i), bal);
fm10k_write_reg(hw, FM10K_TDBAH(i), bah);
fm10k_write_reg(hw, FM10K_RDBAL(i), bal);
fm10k_write_reg(hw, FM10K_RDBAH(i), bah);
}
return 0;
}
static s32 fm10k_reset_hw_vf(struct fm10k_hw *hw)
{
s32 err;
err = fm10k_stop_hw_vf(hw);
if (err)
return err;
fm10k_write_reg(hw, FM10K_VFCTRL, FM10K_VFCTRL_RST);
fm10k_write_flush(hw);
udelay(FM10K_RESET_TIMEOUT);
fm10k_write_reg(hw, FM10K_VFCTRL, 0);
if (fm10k_read_reg(hw, FM10K_VFCTRL) & FM10K_VFCTRL_RST)
err = FM10K_ERR_RESET_FAILED;
return err;
}
static s32 fm10k_init_hw_vf(struct fm10k_hw *hw)
{
u32 tqdloc, tqdloc0 = ~fm10k_read_reg(hw, FM10K_TQDLOC(0));
s32 err;
u16 i;
for (i = 1; tqdloc0 && (i < FM10K_MAX_QUEUES_POOL); i++) {
tqdloc = ~fm10k_read_reg(hw, FM10K_TQDLOC(i));
if (!tqdloc || (tqdloc == tqdloc0))
break;
if (!~fm10k_read_reg(hw, FM10K_TXQCTL(i)) ||
!~fm10k_read_reg(hw, FM10K_RXQCTL(i)))
break;
}
err = fm10k_disable_queues_generic(hw, i);
if (err)
return err;
hw->mac.max_queues = i;
hw->mac.default_vid = (fm10k_read_reg(hw, FM10K_TXQCTL(0)) &
FM10K_TXQCTL_VID_MASK) >> FM10K_TXQCTL_VID_SHIFT;
return 0;
}
static bool fm10k_is_slot_appropriate_vf(struct fm10k_hw *hw)
{
return true;
}
static s32 fm10k_update_vlan_vf(struct fm10k_hw *hw, u32 vid, u8 vsi, bool set)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 msg[4];
if (vsi)
return FM10K_ERR_PARAM;
if ((vid << 16 | vid) >> 28)
return FM10K_ERR_PARAM;
if (!set)
vid |= FM10K_VLAN_CLEAR;
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_MAC_VLAN);
fm10k_tlv_attr_put_u32(msg, FM10K_MAC_VLAN_MSG_VLAN, vid);
return mbx->ops.enqueue_tx(hw, mbx, msg);
}
s32 fm10k_msg_mac_vlan_vf(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
u8 perm_addr[ETH_ALEN];
u16 vid;
s32 err;
err = fm10k_tlv_attr_get_mac_vlan(
results[FM10K_MAC_VLAN_MSG_DEFAULT_MAC],
perm_addr, &vid);
if (err)
return err;
ether_addr_copy(hw->mac.perm_addr, perm_addr);
hw->mac.default_vid = vid & (FM10K_VLAN_TABLE_VID_MAX - 1);
hw->mac.vlan_override = !!(vid & FM10K_VLAN_CLEAR);
return 0;
}
static s32 fm10k_read_mac_addr_vf(struct fm10k_hw *hw)
{
u8 perm_addr[ETH_ALEN];
u32 base_addr;
base_addr = fm10k_read_reg(hw, FM10K_TDBAL(0));
if (base_addr << 24)
return FM10K_ERR_INVALID_MAC_ADDR;
perm_addr[3] = (u8)(base_addr >> 24);
perm_addr[4] = (u8)(base_addr >> 16);
perm_addr[5] = (u8)(base_addr >> 8);
base_addr = fm10k_read_reg(hw, FM10K_TDBAH(0));
if ((~base_addr) >> 24)
return FM10K_ERR_INVALID_MAC_ADDR;
perm_addr[0] = (u8)(base_addr >> 16);
perm_addr[1] = (u8)(base_addr >> 8);
perm_addr[2] = (u8)(base_addr);
ether_addr_copy(hw->mac.perm_addr, perm_addr);
ether_addr_copy(hw->mac.addr, perm_addr);
return 0;
}
static s32 fm10k_update_uc_addr_vf(struct fm10k_hw *hw, u16 glort,
const u8 *mac, u16 vid, bool add, u8 flags)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 msg[7];
if (vid >= FM10K_VLAN_TABLE_VID_MAX)
return FM10K_ERR_PARAM;
if (!is_valid_ether_addr(mac))
return FM10K_ERR_PARAM;
if (is_valid_ether_addr(hw->mac.perm_addr) &&
memcmp(hw->mac.perm_addr, mac, ETH_ALEN))
return FM10K_ERR_PARAM;
if (!add)
vid |= FM10K_VLAN_CLEAR;
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_MAC_VLAN);
fm10k_tlv_attr_put_mac_vlan(msg, FM10K_MAC_VLAN_MSG_MAC, mac, vid);
return mbx->ops.enqueue_tx(hw, mbx, msg);
}
static s32 fm10k_update_mc_addr_vf(struct fm10k_hw *hw, u16 glort,
const u8 *mac, u16 vid, bool add)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 msg[7];
if (vid >= FM10K_VLAN_TABLE_VID_MAX)
return FM10K_ERR_PARAM;
if (!is_multicast_ether_addr(mac))
return FM10K_ERR_PARAM;
if (!add)
vid |= FM10K_VLAN_CLEAR;
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_MAC_VLAN);
fm10k_tlv_attr_put_mac_vlan(msg, FM10K_MAC_VLAN_MSG_MULTICAST,
mac, vid);
return mbx->ops.enqueue_tx(hw, mbx, msg);
}
static void fm10k_update_int_moderator_vf(struct fm10k_hw *hw)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 msg[1];
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_MSIX);
mbx->ops.enqueue_tx(hw, mbx, msg);
}
s32 fm10k_msg_lport_state_vf(struct fm10k_hw *hw, u32 **results,
struct fm10k_mbx_info *mbx)
{
hw->mac.dglort_map = !results[FM10K_LPORT_STATE_MSG_READY] ?
FM10K_DGLORTMAP_NONE : FM10K_DGLORTMAP_ZERO;
return 0;
}
static s32 fm10k_update_lport_state_vf(struct fm10k_hw *hw, u16 glort,
u16 count, bool enable)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 msg[2];
hw->mac.dglort_map = FM10K_DGLORTMAP_NONE;
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_LPORT_STATE);
if (!enable)
fm10k_tlv_attr_put_bool(msg, FM10K_LPORT_STATE_MSG_DISABLE);
return mbx->ops.enqueue_tx(hw, mbx, msg);
}
static s32 fm10k_update_xcast_mode_vf(struct fm10k_hw *hw, u16 glort, u8 mode)
{
struct fm10k_mbx_info *mbx = &hw->mbx;
u32 msg[3];
if (mode > FM10K_XCAST_MODE_NONE)
return FM10K_ERR_PARAM;
fm10k_tlv_msg_init(msg, FM10K_VF_MSG_ID_LPORT_STATE);
fm10k_tlv_attr_put_u8(msg, FM10K_LPORT_STATE_MSG_XCAST_MODE, mode);
return mbx->ops.enqueue_tx(hw, mbx, msg);
}
static void fm10k_update_hw_stats_vf(struct fm10k_hw *hw,
struct fm10k_hw_stats *stats)
{
fm10k_update_hw_stats_q(hw, stats->q, 0, hw->mac.max_queues);
}
static void fm10k_rebind_hw_stats_vf(struct fm10k_hw *hw,
struct fm10k_hw_stats *stats)
{
fm10k_unbind_hw_stats_q(stats->q, 0, hw->mac.max_queues);
fm10k_update_hw_stats_vf(hw, stats);
}
static s32 fm10k_configure_dglort_map_vf(struct fm10k_hw *hw,
struct fm10k_dglort_cfg *dglort)
{
if (!dglort)
return FM10K_ERR_PARAM;
return 0;
}
static s32 fm10k_adjust_systime_vf(struct fm10k_hw *hw, s32 ppb)
{
return ppb ? FM10K_ERR_PARAM : 0;
}
static u64 fm10k_read_systime_vf(struct fm10k_hw *hw)
{
u32 systime_l, systime_h, systime_tmp;
systime_h = fm10k_read_reg(hw, FM10K_VFSYSTIME + 1);
do {
systime_tmp = systime_h;
systime_l = fm10k_read_reg(hw, FM10K_VFSYSTIME);
systime_h = fm10k_read_reg(hw, FM10K_VFSYSTIME + 1);
} while (systime_tmp != systime_h);
return ((u64)systime_h << 32) | systime_l;
}
static s32 fm10k_get_invariants_vf(struct fm10k_hw *hw)
{
fm10k_get_invariants_generic(hw);
return fm10k_pfvf_mbx_init(hw, &hw->mbx, fm10k_msg_data_vf, 0);
}
