static inline s32 ixgbevf_write_msg_read_ack(struct ixgbe_hw *hw, u32 *msg,
u32 *retmsg, u16 size)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
s32 retval = mbx->ops.write_posted(hw, msg, size);
if (retval)
return retval;
return mbx->ops.read_posted(hw, retmsg, size);
}
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
hw->api_version = ixgbe_mbox_api_10;
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
mdelay(10);
ret_val = mbx->ops.read_posted(hw, msgbuf, IXGBE_VF_PERMADDR_MSG_LEN);
if (ret_val)
return ret_val;
if (msgbuf[0] != (IXGBE_VF_RESET | IXGBE_VT_MSGTYPE_ACK) &&
msgbuf[0] != (IXGBE_VF_RESET | IXGBE_VT_MSGTYPE_NACK))
return IXGBE_ERR_INVALID_MAC_ADDR;
if (msgbuf[0] == (IXGBE_VF_RESET | IXGBE_VT_MSGTYPE_ACK))
ether_addr_copy(hw->mac.perm_addr, addr);
hw->mac.mc_filter_type = msgbuf[IXGBE_VF_MC_TYPE_WORD];
return 0;
}
static s32 ixgbevf_hv_reset_hw_vf(struct ixgbe_hw *hw)
{
#if IS_ENABLED(CONFIG_PCI_MMCONFIG)
struct ixgbevf_adapter *adapter = hw->back;
int i;
for (i = 0; i < 6; i++)
pci_read_config_byte(adapter->pdev,
(i + IXGBE_HV_RESET_OFFSET),
&hw->mac.perm_addr[i]);
return 0;
#else
pr_err("PCI_MMCONFIG needs to be enabled for Hyper-V\n");
return -EOPNOTSUPP;
#endif
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
ether_addr_copy(mac_addr, hw->mac.perm_addr);
return 0;
}
static s32 ixgbevf_set_uc_addr_vf(struct ixgbe_hw *hw, u32 index, u8 *addr)
{
u32 msgbuf[3], msgbuf_chk;
u8 *msg_addr = (u8 *)(&msgbuf[1]);
s32 ret_val;
memset(msgbuf, 0, sizeof(msgbuf));
msgbuf[0] |= index << IXGBE_VT_MSGINFO_SHIFT;
msgbuf[0] |= IXGBE_VF_SET_MACVLAN;
msgbuf_chk = msgbuf[0];
if (addr)
ether_addr_copy(msg_addr, addr);
ret_val = ixgbevf_write_msg_read_ack(hw, msgbuf, msgbuf,
sizeof(msgbuf) / sizeof(u32));
if (!ret_val) {
msgbuf[0] &= ~IXGBE_VT_MSGTYPE_CTS;
if (msgbuf[0] == (msgbuf_chk | IXGBE_VT_MSGTYPE_NACK))
return -ENOMEM;
}
return ret_val;
}
static s32 ixgbevf_hv_set_uc_addr_vf(struct ixgbe_hw *hw, u32 index, u8 *addr)
{
return -EOPNOTSUPP;
}
int ixgbevf_get_reta_locked(struct ixgbe_hw *hw, u32 *reta, int num_rx_queues)
{
int err, i, j;
u32 msgbuf[IXGBE_VFMAILBOX_SIZE];
u32 *hw_reta = &msgbuf[1];
u32 mask = 0;
int dwords = IXGBEVF_82599_RETA_SIZE / 16;
switch (hw->api_version) {
case ixgbe_mbox_api_13:
case ixgbe_mbox_api_12:
if (hw->mac.type < ixgbe_mac_X550_vf)
break;
default:
return -EOPNOTSUPP;
}
msgbuf[0] = IXGBE_VF_GET_RETA;
err = hw->mbx.ops.write_posted(hw, msgbuf, 1);
if (err)
return err;
err = hw->mbx.ops.read_posted(hw, msgbuf, dwords + 1);
if (err)
return err;
msgbuf[0] &= ~IXGBE_VT_MSGTYPE_CTS;
if (msgbuf[0] == (IXGBE_VF_GET_RETA | IXGBE_VT_MSGTYPE_NACK))
return -EPERM;
if (msgbuf[0] != (IXGBE_VF_GET_RETA | IXGBE_VT_MSGTYPE_ACK))
return IXGBE_ERR_MBX;
if (num_rx_queues > 1)
mask = 0x1;
for (i = 0; i < dwords; i++)
for (j = 0; j < 16; j++)
reta[i * 16 + j] = (hw_reta[i] >> (2 * j)) & mask;
return 0;
}
int ixgbevf_get_rss_key_locked(struct ixgbe_hw *hw, u8 *rss_key)
{
int err;
u32 msgbuf[IXGBE_VFMAILBOX_SIZE];
switch (hw->api_version) {
case ixgbe_mbox_api_13:
case ixgbe_mbox_api_12:
if (hw->mac.type < ixgbe_mac_X550_vf)
break;
default:
return -EOPNOTSUPP;
}
msgbuf[0] = IXGBE_VF_GET_RSS_KEY;
err = hw->mbx.ops.write_posted(hw, msgbuf, 1);
if (err)
return err;
err = hw->mbx.ops.read_posted(hw, msgbuf, 11);
if (err)
return err;
msgbuf[0] &= ~IXGBE_VT_MSGTYPE_CTS;
if (msgbuf[0] == (IXGBE_VF_GET_RSS_KEY | IXGBE_VT_MSGTYPE_NACK))
return -EPERM;
if (msgbuf[0] != (IXGBE_VF_GET_RSS_KEY | IXGBE_VT_MSGTYPE_ACK))
return IXGBE_ERR_MBX;
memcpy(rss_key, msgbuf + 1, IXGBEVF_RSS_HASH_KEY_SIZE);
return 0;
}
static s32 ixgbevf_set_rar_vf(struct ixgbe_hw *hw, u32 index, u8 *addr,
u32 vmdq)
{
u32 msgbuf[3];
u8 *msg_addr = (u8 *)(&msgbuf[1]);
s32 ret_val;
memset(msgbuf, 0, sizeof(msgbuf));
msgbuf[0] = IXGBE_VF_SET_MAC_ADDR;
ether_addr_copy(msg_addr, addr);
ret_val = ixgbevf_write_msg_read_ack(hw, msgbuf, msgbuf,
sizeof(msgbuf) / sizeof(u32));
msgbuf[0] &= ~IXGBE_VT_MSGTYPE_CTS;
if (!ret_val &&
(msgbuf[0] == (IXGBE_VF_SET_MAC_ADDR | IXGBE_VT_MSGTYPE_NACK))) {
ixgbevf_get_mac_addr_vf(hw, hw->mac.addr);
return IXGBE_ERR_MBX;
}
return ret_val;
}
static s32 ixgbevf_hv_set_rar_vf(struct ixgbe_hw *hw, u32 index, u8 *addr,
u32 vmdq)
{
if (ether_addr_equal(addr, hw->mac.perm_addr))
return 0;
return -EOPNOTSUPP;
}
static s32 ixgbevf_update_mc_addr_list_vf(struct ixgbe_hw *hw,
struct net_device *netdev)
{
struct netdev_hw_addr *ha;
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
if (is_link_local_ether_addr(ha->addr))
continue;
vector_list[i++] = ixgbevf_mta_vector(hw, ha->addr);
}
ixgbevf_write_msg_read_ack(hw, msgbuf, msgbuf, IXGBE_VFMAILBOX_SIZE);
return 0;
}
static s32 ixgbevf_hv_update_mc_addr_list_vf(struct ixgbe_hw *hw,
struct net_device *netdev)
{
return -EOPNOTSUPP;
}
static s32 ixgbevf_update_xcast_mode(struct ixgbe_hw *hw, int xcast_mode)
{
u32 msgbuf[2];
s32 err;
switch (hw->api_version) {
case ixgbe_mbox_api_12:
if (xcast_mode == IXGBEVF_XCAST_MODE_PROMISC)
return -EOPNOTSUPP;
case ixgbe_mbox_api_13:
break;
default:
return -EOPNOTSUPP;
}
msgbuf[0] = IXGBE_VF_UPDATE_XCAST_MODE;
msgbuf[1] = xcast_mode;
err = ixgbevf_write_msg_read_ack(hw, msgbuf, msgbuf,
sizeof(msgbuf) / sizeof(u32));
if (err)
return err;
msgbuf[0] &= ~IXGBE_VT_MSGTYPE_CTS;
if (msgbuf[0] == (IXGBE_VF_UPDATE_XCAST_MODE | IXGBE_VT_MSGTYPE_NACK))
return -EPERM;
return 0;
}
static s32 ixgbevf_hv_update_xcast_mode(struct ixgbe_hw *hw, int xcast_mode)
{
return -EOPNOTSUPP;
}
static s32 ixgbevf_set_vfta_vf(struct ixgbe_hw *hw, u32 vlan, u32 vind,
bool vlan_on)
{
u32 msgbuf[2];
s32 err;
msgbuf[0] = IXGBE_VF_SET_VLAN;
msgbuf[1] = vlan;
msgbuf[0] |= vlan_on << IXGBE_VT_MSGINFO_SHIFT;
err = ixgbevf_write_msg_read_ack(hw, msgbuf, msgbuf,
sizeof(msgbuf) / sizeof(u32));
if (err)
goto mbx_err;
msgbuf[0] &= ~IXGBE_VT_MSGTYPE_CTS;
msgbuf[0] &= ~(0xFF << IXGBE_VT_MSGINFO_SHIFT);
if (msgbuf[0] != (IXGBE_VF_SET_VLAN | IXGBE_VT_MSGTYPE_ACK))
err = IXGBE_ERR_INVALID_ARGUMENT;
mbx_err:
return err;
}
static s32 ixgbevf_hv_set_vfta_vf(struct ixgbe_hw *hw, u32 vlan, u32 vind,
bool vlan_on)
{
return -EOPNOTSUPP;
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
struct ixgbe_mbx_info *mbx = &hw->mbx;
struct ixgbe_mac_info *mac = &hw->mac;
s32 ret_val = 0;
u32 links_reg;
u32 in_msg = 0;
if (!mbx->ops.check_for_rst(hw) || !mbx->timeout)
mac->get_link_status = true;
if (!mac->get_link_status)
goto out;
links_reg = IXGBE_READ_REG(hw, IXGBE_VFLINKS);
if (!(links_reg & IXGBE_LINKS_UP))
goto out;
if (mac->type == ixgbe_mac_82599_vf) {
int i;
for (i = 0; i < 5; i++) {
udelay(100);
links_reg = IXGBE_READ_REG(hw, IXGBE_VFLINKS);
if (!(links_reg & IXGBE_LINKS_UP))
goto out;
}
}
switch (links_reg & IXGBE_LINKS_SPEED_82599) {
case IXGBE_LINKS_SPEED_10G_82599:
*speed = IXGBE_LINK_SPEED_10GB_FULL;
break;
case IXGBE_LINKS_SPEED_1G_82599:
*speed = IXGBE_LINK_SPEED_1GB_FULL;
break;
case IXGBE_LINKS_SPEED_100_82599:
*speed = IXGBE_LINK_SPEED_100_FULL;
break;
}
if (mbx->ops.read(hw, &in_msg, 1))
goto out;
if (!(in_msg & IXGBE_VT_MSGTYPE_CTS)) {
if (in_msg & IXGBE_VT_MSGTYPE_NACK)
ret_val = -1;
goto out;
}
if (!mbx->timeout) {
ret_val = -1;
goto out;
}
mac->get_link_status = false;
out:
*link_up = !mac->get_link_status;
return ret_val;
}
static s32 ixgbevf_hv_check_mac_link_vf(struct ixgbe_hw *hw,
ixgbe_link_speed *speed,
bool *link_up,
bool autoneg_wait_to_complete)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
struct ixgbe_mac_info *mac = &hw->mac;
u32 links_reg;
if (!mbx->ops.check_for_rst(hw) || !mbx->timeout)
mac->get_link_status = true;
if (!mac->get_link_status)
goto out;
links_reg = IXGBE_READ_REG(hw, IXGBE_VFLINKS);
if (!(links_reg & IXGBE_LINKS_UP))
goto out;
if (mac->type == ixgbe_mac_82599_vf) {
int i;
for (i = 0; i < 5; i++) {
udelay(100);
links_reg = IXGBE_READ_REG(hw, IXGBE_VFLINKS);
if (!(links_reg & IXGBE_LINKS_UP))
goto out;
}
}
switch (links_reg & IXGBE_LINKS_SPEED_82599) {
case IXGBE_LINKS_SPEED_10G_82599:
*speed = IXGBE_LINK_SPEED_10GB_FULL;
break;
case IXGBE_LINKS_SPEED_1G_82599:
*speed = IXGBE_LINK_SPEED_1GB_FULL;
break;
case IXGBE_LINKS_SPEED_100_82599:
*speed = IXGBE_LINK_SPEED_100_FULL;
break;
}
mac->get_link_status = false;
out:
*link_up = !mac->get_link_status;
return 0;
}
static s32 ixgbevf_set_rlpml_vf(struct ixgbe_hw *hw, u16 max_size)
{
u32 msgbuf[2];
s32 ret_val;
msgbuf[0] = IXGBE_VF_SET_LPE;
msgbuf[1] = max_size;
ret_val = ixgbevf_write_msg_read_ack(hw, msgbuf, msgbuf,
sizeof(msgbuf) / sizeof(u32));
if (ret_val)
return ret_val;
if ((msgbuf[0] & IXGBE_VF_SET_LPE) &&
(msgbuf[0] & IXGBE_VT_MSGTYPE_NACK))
return IXGBE_ERR_MBX;
return 0;
}
static s32 ixgbevf_hv_set_rlpml_vf(struct ixgbe_hw *hw, u16 max_size)
{
u32 reg;
reg = IXGBE_READ_REG(hw, IXGBE_VFRXDCTL(0));
reg |= ((max_size + 4) | IXGBE_RXDCTL_RLPML_EN);
IXGBE_WRITE_REG(hw, IXGBE_VFRXDCTL(0), reg);
return 0;
}
static int ixgbevf_negotiate_api_version_vf(struct ixgbe_hw *hw, int api)
{
int err;
u32 msg[3];
msg[0] = IXGBE_VF_API_NEGOTIATE;
msg[1] = api;
msg[2] = 0;
err = ixgbevf_write_msg_read_ack(hw, msg, msg,
sizeof(msg) / sizeof(u32));
if (!err) {
msg[0] &= ~IXGBE_VT_MSGTYPE_CTS;
if (msg[0] == (IXGBE_VF_API_NEGOTIATE | IXGBE_VT_MSGTYPE_ACK)) {
hw->api_version = api;
return 0;
}
err = IXGBE_ERR_INVALID_ARGUMENT;
}
return err;
}
static int ixgbevf_hv_negotiate_api_version_vf(struct ixgbe_hw *hw, int api)
{
if (api != ixgbe_mbox_api_10)
return IXGBE_ERR_INVALID_ARGUMENT;
return 0;
}
int ixgbevf_get_queues(struct ixgbe_hw *hw, unsigned int *num_tcs,
unsigned int *default_tc)
{
int err;
u32 msg[5];
switch (hw->api_version) {
case ixgbe_mbox_api_11:
case ixgbe_mbox_api_12:
case ixgbe_mbox_api_13:
break;
default:
return 0;
}
msg[0] = IXGBE_VF_GET_QUEUE;
msg[1] = msg[2] = msg[3] = msg[4] = 0;
err = ixgbevf_write_msg_read_ack(hw, msg, msg,
sizeof(msg) / sizeof(u32));
if (!err) {
msg[0] &= ~IXGBE_VT_MSGTYPE_CTS;
if (msg[0] != (IXGBE_VF_GET_QUEUE | IXGBE_VT_MSGTYPE_ACK))
return IXGBE_ERR_MBX;
hw->mac.max_tx_queues = msg[IXGBE_VF_TX_QUEUES];
if (hw->mac.max_tx_queues == 0 ||
hw->mac.max_tx_queues > IXGBE_VF_MAX_TX_QUEUES)
hw->mac.max_tx_queues = IXGBE_VF_MAX_TX_QUEUES;
hw->mac.max_rx_queues = msg[IXGBE_VF_RX_QUEUES];
if (hw->mac.max_rx_queues == 0 ||
hw->mac.max_rx_queues > IXGBE_VF_MAX_RX_QUEUES)
hw->mac.max_rx_queues = IXGBE_VF_MAX_RX_QUEUES;
*num_tcs = msg[IXGBE_VF_TRANS_VLAN];
if (*num_tcs > hw->mac.max_rx_queues)
*num_tcs = 1;
*default_tc = msg[IXGBE_VF_DEF_QUEUE];
if (*default_tc >= hw->mac.max_tx_queues)
*default_tc = 0;
}
return err;
}
