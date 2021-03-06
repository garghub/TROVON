static int change_mac(struct hinic_dev *nic_dev, const u8 *addr,
u16 vlan_id, enum mac_op op)
{
struct net_device *netdev = nic_dev->netdev;
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_port_mac_cmd port_mac_cmd;
struct hinic_hwif *hwif = hwdev->hwif;
struct pci_dev *pdev = hwif->pdev;
enum hinic_port_cmd cmd;
u16 out_size;
int err;
if (vlan_id >= VLAN_N_VID) {
netif_err(nic_dev, drv, netdev, "Invalid VLAN number\n");
return -EINVAL;
}
if (op == MAC_SET)
cmd = HINIC_PORT_CMD_SET_MAC;
else
cmd = HINIC_PORT_CMD_DEL_MAC;
port_mac_cmd.func_idx = HINIC_HWIF_FUNC_IDX(hwif);
port_mac_cmd.vlan_id = vlan_id;
memcpy(port_mac_cmd.mac, addr, ETH_ALEN);
err = hinic_port_msg_cmd(hwdev, cmd, &port_mac_cmd,
sizeof(port_mac_cmd),
&port_mac_cmd, &out_size);
if (err || (out_size != sizeof(port_mac_cmd)) || port_mac_cmd.status) {
dev_err(&pdev->dev, "Failed to change MAC, ret = %d\n",
port_mac_cmd.status);
return -EFAULT;
}
return 0;
}
int hinic_port_add_mac(struct hinic_dev *nic_dev,
const u8 *addr, u16 vlan_id)
{
return change_mac(nic_dev, addr, vlan_id, MAC_SET);
}
int hinic_port_del_mac(struct hinic_dev *nic_dev, const u8 *addr,
u16 vlan_id)
{
return change_mac(nic_dev, addr, vlan_id, MAC_DEL);
}
int hinic_port_get_mac(struct hinic_dev *nic_dev, u8 *addr)
{
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_port_mac_cmd port_mac_cmd;
struct hinic_hwif *hwif = hwdev->hwif;
struct pci_dev *pdev = hwif->pdev;
u16 out_size;
int err;
port_mac_cmd.func_idx = HINIC_HWIF_FUNC_IDX(hwif);
err = hinic_port_msg_cmd(hwdev, HINIC_PORT_CMD_GET_MAC,
&port_mac_cmd, sizeof(port_mac_cmd),
&port_mac_cmd, &out_size);
if (err || (out_size != sizeof(port_mac_cmd)) || port_mac_cmd.status) {
dev_err(&pdev->dev, "Failed to get mac, ret = %d\n",
port_mac_cmd.status);
return -EFAULT;
}
memcpy(addr, port_mac_cmd.mac, ETH_ALEN);
return 0;
}
int hinic_port_set_mtu(struct hinic_dev *nic_dev, int new_mtu)
{
struct net_device *netdev = nic_dev->netdev;
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_port_mtu_cmd port_mtu_cmd;
struct hinic_hwif *hwif = hwdev->hwif;
struct pci_dev *pdev = hwif->pdev;
int err, max_frame;
u16 out_size;
if (new_mtu < HINIC_MIN_MTU_SIZE) {
netif_err(nic_dev, drv, netdev, "mtu < MIN MTU size");
return -EINVAL;
}
max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN;
if (max_frame > HINIC_MAX_JUMBO_FRAME_SIZE) {
netif_err(nic_dev, drv, netdev, "mtu > MAX MTU size");
return -EINVAL;
}
port_mtu_cmd.func_idx = HINIC_HWIF_FUNC_IDX(hwif);
port_mtu_cmd.mtu = new_mtu;
err = hinic_port_msg_cmd(hwdev, HINIC_PORT_CMD_CHANGE_MTU,
&port_mtu_cmd, sizeof(port_mtu_cmd),
&port_mtu_cmd, &out_size);
if (err || (out_size != sizeof(port_mtu_cmd)) || port_mtu_cmd.status) {
dev_err(&pdev->dev, "Failed to set mtu, ret = %d\n",
port_mtu_cmd.status);
return -EFAULT;
}
return 0;
}
int hinic_port_add_vlan(struct hinic_dev *nic_dev, u16 vlan_id)
{
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_port_vlan_cmd port_vlan_cmd;
port_vlan_cmd.func_idx = HINIC_HWIF_FUNC_IDX(hwdev->hwif);
port_vlan_cmd.vlan_id = vlan_id;
return hinic_port_msg_cmd(hwdev, HINIC_PORT_CMD_ADD_VLAN,
&port_vlan_cmd, sizeof(port_vlan_cmd),
NULL, NULL);
}
int hinic_port_del_vlan(struct hinic_dev *nic_dev, u16 vlan_id)
{
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_port_vlan_cmd port_vlan_cmd;
port_vlan_cmd.func_idx = HINIC_HWIF_FUNC_IDX(hwdev->hwif);
port_vlan_cmd.vlan_id = vlan_id;
return hinic_port_msg_cmd(hwdev, HINIC_PORT_CMD_DEL_VLAN,
&port_vlan_cmd, sizeof(port_vlan_cmd),
NULL, NULL);
}
int hinic_port_set_rx_mode(struct hinic_dev *nic_dev, u32 rx_mode)
{
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_port_rx_mode_cmd rx_mode_cmd;
rx_mode_cmd.func_idx = HINIC_HWIF_FUNC_IDX(hwdev->hwif);
rx_mode_cmd.rx_mode = rx_mode;
return hinic_port_msg_cmd(hwdev, HINIC_PORT_CMD_SET_RX_MODE,
&rx_mode_cmd, sizeof(rx_mode_cmd),
NULL, NULL);
}
int hinic_port_link_state(struct hinic_dev *nic_dev,
enum hinic_port_link_state *link_state)
{
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_hwif *hwif = hwdev->hwif;
struct hinic_port_link_cmd link_cmd;
struct pci_dev *pdev = hwif->pdev;
u16 out_size;
int err;
if (!HINIC_IS_PF(hwif) && !HINIC_IS_PPF(hwif)) {
dev_err(&pdev->dev, "unsupported PCI Function type\n");
return -EINVAL;
}
link_cmd.func_idx = HINIC_HWIF_FUNC_IDX(hwif);
err = hinic_port_msg_cmd(hwdev, HINIC_PORT_CMD_GET_LINK_STATE,
&link_cmd, sizeof(link_cmd),
&link_cmd, &out_size);
if (err || (out_size != sizeof(link_cmd)) || link_cmd.status) {
dev_err(&pdev->dev, "Failed to get link state, ret = %d\n",
link_cmd.status);
return -EINVAL;
}
*link_state = link_cmd.state;
return 0;
}
int hinic_port_set_state(struct hinic_dev *nic_dev, enum hinic_port_state state)
{
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_port_state_cmd port_state;
struct hinic_hwif *hwif = hwdev->hwif;
struct pci_dev *pdev = hwif->pdev;
u16 out_size;
int err;
if (!HINIC_IS_PF(hwif) && !HINIC_IS_PPF(hwif)) {
dev_err(&pdev->dev, "unsupported PCI Function type\n");
return -EINVAL;
}
port_state.state = state;
err = hinic_port_msg_cmd(hwdev, HINIC_PORT_CMD_SET_PORT_STATE,
&port_state, sizeof(port_state),
&port_state, &out_size);
if (err || (out_size != sizeof(port_state)) || port_state.status) {
dev_err(&pdev->dev, "Failed to set port state, ret = %d\n",
port_state.status);
return -EFAULT;
}
return 0;
}
int hinic_port_set_func_state(struct hinic_dev *nic_dev,
enum hinic_func_port_state state)
{
struct hinic_port_func_state_cmd func_state;
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_hwif *hwif = hwdev->hwif;
struct pci_dev *pdev = hwif->pdev;
u16 out_size;
int err;
func_state.func_idx = HINIC_HWIF_FUNC_IDX(hwif);
func_state.state = state;
err = hinic_port_msg_cmd(hwdev, HINIC_PORT_CMD_SET_FUNC_STATE,
&func_state, sizeof(func_state),
&func_state, &out_size);
if (err || (out_size != sizeof(func_state)) || func_state.status) {
dev_err(&pdev->dev, "Failed to set port func state, ret = %d\n",
func_state.status);
return -EFAULT;
}
return 0;
}
int hinic_port_get_cap(struct hinic_dev *nic_dev,
struct hinic_port_cap *port_cap)
{
struct hinic_hwdev *hwdev = nic_dev->hwdev;
struct hinic_hwif *hwif = hwdev->hwif;
struct pci_dev *pdev = hwif->pdev;
u16 out_size;
int err;
port_cap->func_idx = HINIC_HWIF_FUNC_IDX(hwif);
err = hinic_port_msg_cmd(hwdev, HINIC_PORT_CMD_GET_CAP,
port_cap, sizeof(*port_cap),
port_cap, &out_size);
if (err || (out_size != sizeof(*port_cap)) || port_cap->status) {
dev_err(&pdev->dev,
"Failed to get port capabilities, ret = %d\n",
port_cap->status);
return -EINVAL;
}
return 0;
}
