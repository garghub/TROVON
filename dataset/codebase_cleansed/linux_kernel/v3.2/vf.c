static s32 ixgbevf_start_hw_vf(struct ixgbe_hw *hw)
{
hw->adapter_stopped = false;
return 0;
}
static s32 ixgbevf_init_hw_vf(struct ixgbe_hw *hw)
{
s32 status = hw->mac.ops.start_hw(hw);
hw->mac.ops.get_mac_addr(hw, hw->mac.addr);
return status;
}
static s32 ixgbevf_reset_hw_vf(struct ixgbe_hw *hw)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
u32 timeout = IXGBE_VF_INIT_TIMEOUT;
s32 ret_val = IXGBE_ERR_INVALID_MAC_ADDR;
u32 msgbuf[IXGBE_VF_PERMADDR_MSG_LEN];
u8 *addr = (u8 *)(&msgbuf[1]);
hw->mac.ops.stop_adapter(hw);
IXGBE_WRITE_REG(hw, IXGBE_VFCTRL, IXGBE_CTRL_RST);
IXGBE_WRITE_FLUSH(hw);
while (!mbx->ops.check_for_rst(hw) && timeout) {
timeout--;
udelay(5);
}
if (!timeout)
return IXGBE_ERR_RESET_FAILED;
mbx->timeout = IXGBE_VF_MBX_INIT_TIMEOUT;
msgbuf[0] = IXGBE_VF_RESET;
mbx->ops.write_posted(hw, msgbuf, 1);
msleep(10);
ret_val = mbx->ops.read_posted(hw, msgbuf, IXGBE_VF_PERMADDR_MSG_LEN);
if (ret_val)
return ret_val;
if (msgbuf[0] != (IXGBE_VF_RESET | IXGBE_VT_MSGTYPE_ACK))
return IXGBE_ERR_INVALID_MAC_ADDR;
memcpy(hw->mac.perm_addr, addr, IXGBE_ETH_LENGTH_OF_ADDRESS);
hw->mac.mc_filter_type = msgbuf[IXGBE_VF_MC_TYPE_WORD];
return 0;
}
static s32 ixgbevf_stop_hw_vf(struct ixgbe_hw *hw)
{
u32 number_of_queues;
u32 reg_val;
u16 i;
hw->adapter_stopped = true;
number_of_queues = hw->mac.max_rx_queues;
for (i = 0; i < number_of_queues; i++) {
reg_val = IXGBE_READ_REG(hw, IXGBE_VFRXDCTL(i));
if (reg_val & IXGBE_RXDCTL_ENABLE) {
reg_val &= ~IXGBE_RXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_VFRXDCTL(i), reg_val);
}
}
IXGBE_WRITE_FLUSH(hw);
IXGBE_WRITE_REG(hw, IXGBE_VTEIMC, IXGBE_VF_IRQ_CLEAR_MASK);
IXGBE_READ_REG(hw, IXGBE_VTEICR);
number_of_queues = hw->mac.max_tx_queues;
for (i = 0; i < number_of_queues; i++) {
reg_val = IXGBE_READ_REG(hw, IXGBE_VFTXDCTL(i));
if (reg_val & IXGBE_TXDCTL_ENABLE) {
reg_val &= ~IXGBE_TXDCTL_ENABLE;
IXGBE_WRITE_REG(hw, IXGBE_VFTXDCTL(i), reg_val);
}
}
return 0;
}
static s32 ixgbevf_mta_vector(struct ixgbe_hw *hw, u8 *mc_addr)
{
u32 vector = 0;
switch (hw->mac.mc_filter_type) {
case 0:
vector = ((mc_addr[4] >> 4) | (((u16)mc_addr[5]) << 4));
break;
case 1:
vector = ((mc_addr[4] >> 3) | (((u16)mc_addr[5]) << 5));
break;
case 2:
vector = ((mc_addr[4] >> 2) | (((u16)mc_addr[5]) << 6));
break;
case 3:
vector = ((mc_addr[4]) | (((u16)mc_addr[5]) << 8));
break;
default:
break;
}
vector &= 0xFFF;
return vector;
}
static s32 ixgbevf_get_mac_addr_vf(struct ixgbe_hw *hw, u8 *mac_addr)
{
memcpy(mac_addr, hw->mac.perm_addr, IXGBE_ETH_LENGTH_OF_ADDRESS);
return 0;
}
static s32 ixgbevf_set_uc_addr_vf(struct ixgbe_hw *hw, u32 index, u8 *addr)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
u32 msgbuf[3];
u8 *msg_addr = (u8 *)(&msgbuf[1]);
s32 ret_val;
memset(msgbuf, 0, sizeof(msgbuf));
msgbuf[0] |= index << IXGBE_VT_MSGINFO_SHIFT;
msgbuf[0] |= IXGBE_VF_SET_MACVLAN;
if (addr)
memcpy(msg_addr, addr, 6);
ret_val = mbx->ops.write_posted(hw, msgbuf, 3);
if (!ret_val)
ret_val = mbx->ops.read_posted(hw, msgbuf, 3);
msgbuf[0] &= ~IXGBE_VT_MSGTYPE_CTS;
if (!ret_val)
if (msgbuf[0] ==
(IXGBE_VF_SET_MACVLAN | IXGBE_VT_MSGTYPE_NACK))
ret_val = -ENOMEM;
return ret_val;
}
static s32 ixgbevf_set_rar_vf(struct ixgbe_hw *hw, u32 index, u8 *addr,
u32 vmdq)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
u32 msgbuf[3];
u8 *msg_addr = (u8 *)(&msgbuf[1]);
s32 ret_val;
memset(msgbuf, 0, sizeof(msgbuf));
msgbuf[0] = IXGBE_VF_SET_MAC_ADDR;
memcpy(msg_addr, addr, 6);
ret_val = mbx->ops.write_posted(hw, msgbuf, 3);
if (!ret_val)
ret_val = mbx->ops.read_posted(hw, msgbuf, 3);
msgbuf[0] &= ~IXGBE_VT_MSGTYPE_CTS;
if (!ret_val &&
(msgbuf[0] == (IXGBE_VF_SET_MAC_ADDR | IXGBE_VT_MSGTYPE_NACK)))
ixgbevf_get_mac_addr_vf(hw, hw->mac.addr);
return ret_val;
}
static s32 ixgbevf_update_mc_addr_list_vf(struct ixgbe_hw *hw,
struct net_device *netdev)
{
struct netdev_hw_addr *ha;
struct ixgbe_mbx_info *mbx = &hw->mbx;
u32 msgbuf[IXGBE_VFMAILBOX_SIZE];
u16 *vector_list = (u16 *)&msgbuf[1];
u32 cnt, i;
cnt = netdev_mc_count(netdev);
if (cnt > 30)
cnt = 30;
msgbuf[0] = IXGBE_VF_SET_MULTICAST;
msgbuf[0] |= cnt << IXGBE_VT_MSGINFO_SHIFT;
i = 0;
netdev_for_each_mc_addr(ha, netdev) {
if (i == cnt)
break;
vector_list[i++] = ixgbevf_mta_vector(hw, ha->addr);
}
mbx->ops.write_posted(hw, msgbuf, IXGBE_VFMAILBOX_SIZE);
return 0;
}
static s32 ixgbevf_set_vfta_vf(struct ixgbe_hw *hw, u32 vlan, u32 vind,
bool vlan_on)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
u32 msgbuf[2];
msgbuf[0] = IXGBE_VF_SET_VLAN;
msgbuf[1] = vlan;
msgbuf[0] |= vlan_on << IXGBE_VT_MSGINFO_SHIFT;
return mbx->ops.write_posted(hw, msgbuf, 2);
}
static s32 ixgbevf_setup_mac_link_vf(struct ixgbe_hw *hw,
ixgbe_link_speed speed, bool autoneg,
bool autoneg_wait_to_complete)
{
return 0;
}
static s32 ixgbevf_check_mac_link_vf(struct ixgbe_hw *hw,
ixgbe_link_speed *speed,
bool *link_up,
bool autoneg_wait_to_complete)
{
u32 links_reg;
if (!(hw->mbx.ops.check_for_rst(hw))) {
*link_up = false;
*speed = 0;
return -1;
}
links_reg = IXGBE_READ_REG(hw, IXGBE_VFLINKS);
if (links_reg & IXGBE_LINKS_UP)
*link_up = true;
else
*link_up = false;
if ((links_reg & IXGBE_LINKS_SPEED_82599) ==
IXGBE_LINKS_SPEED_10G_82599)
*speed = IXGBE_LINK_SPEED_10GB_FULL;
else
*speed = IXGBE_LINK_SPEED_1GB_FULL;
return 0;
}
