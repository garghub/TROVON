static int ixgbe_find_enabled_vfs(struct ixgbe_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
struct pci_dev *pvfdev;
u16 vf_devfn = 0;
int device_id;
int vfs_found = 0;
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
device_id = IXGBE_DEV_ID_82599_VF;
break;
case ixgbe_mac_X540:
device_id = IXGBE_DEV_ID_X540_VF;
break;
default:
device_id = 0;
break;
}
vf_devfn = pdev->devfn + 0x80;
pvfdev = pci_get_device(IXGBE_INTEL_VENDOR_ID, device_id, NULL);
while (pvfdev) {
if (pvfdev->devfn == vf_devfn &&
(pvfdev->bus->number >= pdev->bus->number))
vfs_found++;
vf_devfn += 2;
pvfdev = pci_get_device(IXGBE_INTEL_VENDOR_ID,
device_id, pvfdev);
}
return vfs_found;
}
void ixgbe_enable_sriov(struct ixgbe_adapter *adapter,
const struct ixgbe_info *ii)
{
struct ixgbe_hw *hw = &adapter->hw;
int err = 0;
int num_vf_macvlans, i;
struct vf_macvlans *mv_list;
int pre_existing_vfs = 0;
pre_existing_vfs = ixgbe_find_enabled_vfs(adapter);
if (!pre_existing_vfs && !adapter->num_vfs)
return;
if (pre_existing_vfs) {
adapter->num_vfs = pre_existing_vfs;
dev_warn(&adapter->pdev->dev, "Virtual Functions already "
"enabled for this device - Please reload all "
"VF drivers to avoid spoofed packet errors\n");
} else {
err = pci_enable_sriov(adapter->pdev, adapter->num_vfs);
}
if (err) {
e_err(probe, "Failed to enable PCI sriov: %d\n", err);
goto err_novfs;
}
adapter->flags |= IXGBE_FLAG_SRIOV_ENABLED;
e_info(probe, "SR-IOV enabled with %d VFs\n", adapter->num_vfs);
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
for (i = 0; i < adapter->num_vfs; i++)
adapter->vfinfo[i].spoofchk_enabled = true;
return;
}
e_err(probe, "Unable to allocate memory for VF Data Storage - "
"SRIOV disabled\n");
pci_disable_sriov(adapter->pdev);
err_novfs:
adapter->flags &= ~IXGBE_FLAG_SRIOV_ENABLED;
adapter->num_vfs = 0;
}
void ixgbe_disable_sriov(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 gcr;
u32 gpie;
u32 vmdctl;
int i;
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
IXGBE_WRITE_FLUSH(hw);
msleep(100);
for (i = 0; i < adapter->num_vfs; i++) {
if (adapter->vfinfo[i].vfdev)
pci_dev_put(adapter->vfinfo[i].vfdev);
}
kfree(adapter->vfinfo);
kfree(adapter->mv_list);
adapter->vfinfo = NULL;
adapter->num_vfs = 0;
adapter->flags &= ~IXGBE_FLAG_SRIOV_ENABLED;
}
static int ixgbe_set_vf_multicasts(struct ixgbe_adapter *adapter,
int entries, u16 *hash_list, u32 vf)
{
struct vf_data_storage *vfinfo = &adapter->vfinfo[vf];
struct ixgbe_hw *hw = &adapter->hw;
int i;
u32 vector_bit;
u32 vector_reg;
u32 mta_reg;
entries = min(entries, IXGBE_MAX_VF_MC_ENTRIES);
vfinfo->num_vf_mc_hashes = entries;
for (i = 0; i < entries; i++) {
vfinfo->vf_mc_hashes[i] = hash_list[i];
}
for (i = 0; i < vfinfo->num_vf_mc_hashes; i++) {
vector_reg = (vfinfo->vf_mc_hashes[i] >> 5) & 0x7F;
vector_bit = vfinfo->vf_mc_hashes[i] & 0x1F;
mta_reg = IXGBE_READ_REG(hw, IXGBE_MTA(vector_reg));
mta_reg |= (1 << vector_bit);
IXGBE_WRITE_REG(hw, IXGBE_MTA(vector_reg), mta_reg);
}
return 0;
}
static void ixgbe_restore_vf_macvlans(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct list_head *pos;
struct vf_macvlans *entry;
list_for_each(pos, &adapter->vf_mvs.l) {
entry = list_entry(pos, struct vf_macvlans, l);
if (!entry->free)
hw->mac.ops.set_rar(hw, entry->rar_entry,
entry->vf_macvlan,
entry->vf, IXGBE_RAH_AV);
}
}
void ixgbe_restore_vf_multicasts(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
struct vf_data_storage *vfinfo;
int i, j;
u32 vector_bit;
u32 vector_reg;
u32 mta_reg;
for (i = 0; i < adapter->num_vfs; i++) {
vfinfo = &adapter->vfinfo[i];
for (j = 0; j < vfinfo->num_vf_mc_hashes; j++) {
hw->addr_ctrl.mta_in_use++;
vector_reg = (vfinfo->vf_mc_hashes[j] >> 5) & 0x7F;
vector_bit = vfinfo->vf_mc_hashes[j] & 0x1F;
mta_reg = IXGBE_READ_REG(hw, IXGBE_MTA(vector_reg));
mta_reg |= (1 << vector_bit);
IXGBE_WRITE_REG(hw, IXGBE_MTA(vector_reg), mta_reg);
}
}
ixgbe_restore_vf_macvlans(adapter);
}
static int ixgbe_set_vf_vlan(struct ixgbe_adapter *adapter, int add, int vid,
u32 vf)
{
return adapter->hw.mac.ops.set_vfta(&adapter->hw, vid, vf, (bool)add);
}
static void ixgbe_set_vf_lpe(struct ixgbe_adapter *adapter, u32 *msgbuf)
{
struct ixgbe_hw *hw = &adapter->hw;
int new_mtu = msgbuf[1];
u32 max_frs;
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN;
if (adapter->hw.mac.type != ixgbe_mac_X540)
return;
if ((new_mtu < 68) || (max_frame > IXGBE_MAX_JUMBO_FRAME_SIZE)) {
e_err(drv, "VF mtu %d out of range\n", new_mtu);
return;
}
max_frs = (IXGBE_READ_REG(hw, IXGBE_MAXFRS) &
IXGBE_MHADD_MFS_MASK) >> IXGBE_MHADD_MFS_SHIFT;
if (max_frs < new_mtu) {
max_frs = new_mtu << IXGBE_MHADD_MFS_SHIFT;
IXGBE_WRITE_REG(hw, IXGBE_MAXFRS, max_frs);
}
e_info(hw, "VF requests change max MTU to %d\n", new_mtu);
}
static void ixgbe_set_vmolr(struct ixgbe_hw *hw, u32 vf, bool aupe)
{
u32 vmolr = IXGBE_READ_REG(hw, IXGBE_VMOLR(vf));
vmolr |= (IXGBE_VMOLR_ROMPE |
IXGBE_VMOLR_BAM);
if (aupe)
vmolr |= IXGBE_VMOLR_AUPE;
else
vmolr &= ~IXGBE_VMOLR_AUPE;
IXGBE_WRITE_REG(hw, IXGBE_VMOLR(vf), vmolr);
}
static void ixgbe_set_vmvir(struct ixgbe_adapter *adapter, u32 vid, u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
if (vid)
IXGBE_WRITE_REG(hw, IXGBE_VMVIR(vf),
(vid | IXGBE_VMVIR_VLANA_DEFAULT));
else
IXGBE_WRITE_REG(hw, IXGBE_VMVIR(vf), 0);
}
static inline void ixgbe_vf_reset_event(struct ixgbe_adapter *adapter, u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
int rar_entry = hw->mac.num_rar_entries - (vf + 1);
if (adapter->vfinfo[vf].pf_vlan) {
ixgbe_set_vf_vlan(adapter, true,
adapter->vfinfo[vf].pf_vlan, vf);
ixgbe_set_vmvir(adapter,
(adapter->vfinfo[vf].pf_vlan |
(adapter->vfinfo[vf].pf_qos <<
VLAN_PRIO_SHIFT)), vf);
ixgbe_set_vmolr(hw, vf, false);
} else {
ixgbe_set_vmvir(adapter, 0, vf);
ixgbe_set_vmolr(hw, vf, true);
}
adapter->vfinfo[vf].num_vf_mc_hashes = 0;
ixgbe_set_rx_mode(adapter->netdev);
hw->mac.ops.clear_rar(hw, rar_entry);
}
static int ixgbe_set_vf_mac(struct ixgbe_adapter *adapter,
int vf, unsigned char *mac_addr)
{
struct ixgbe_hw *hw = &adapter->hw;
int rar_entry = hw->mac.num_rar_entries - (vf + 1);
memcpy(adapter->vfinfo[vf].vf_mac_addresses, mac_addr, 6);
hw->mac.ops.set_rar(hw, rar_entry, mac_addr, vf, IXGBE_RAH_AV);
return 0;
}
static int ixgbe_set_vf_macvlan(struct ixgbe_adapter *adapter,
int vf, int index, unsigned char *mac_addr)
{
struct ixgbe_hw *hw = &adapter->hw;
struct list_head *pos;
struct vf_macvlans *entry;
if (index <= 1) {
list_for_each(pos, &adapter->vf_mvs.l) {
entry = list_entry(pos, struct vf_macvlans, l);
if (entry->vf == vf) {
entry->vf = -1;
entry->free = true;
entry->is_macvlan = false;
hw->mac.ops.clear_rar(hw, entry->rar_entry);
}
}
}
if (!index)
return 0;
entry = NULL;
list_for_each(pos, &adapter->vf_mvs.l) {
entry = list_entry(pos, struct vf_macvlans, l);
if (entry->free)
break;
}
if (!entry || !entry->free)
return -ENOSPC;
entry->free = false;
entry->is_macvlan = true;
entry->vf = vf;
memcpy(entry->vf_macvlan, mac_addr, ETH_ALEN);
hw->mac.ops.set_rar(hw, entry->rar_entry, mac_addr, vf, IXGBE_RAH_AV);
return 0;
}
int ixgbe_check_vf_assignment(struct ixgbe_adapter *adapter)
{
#ifdef CONFIG_PCI_IOV
int i;
for (i = 0; i < adapter->num_vfs; i++) {
if (adapter->vfinfo[i].vfdev->dev_flags &
PCI_DEV_FLAGS_ASSIGNED)
return true;
}
#endif
return false;
}
int ixgbe_vf_configuration(struct pci_dev *pdev, unsigned int event_mask)
{
unsigned char vf_mac_addr[6];
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
unsigned int vfn = (event_mask & 0x3f);
struct pci_dev *pvfdev;
unsigned int device_id;
u16 thisvf_devfn = (pdev->devfn + 0x80 + (vfn << 1)) |
(pdev->devfn & 1);
bool enable = ((event_mask & 0x10000000U) != 0);
if (enable) {
random_ether_addr(vf_mac_addr);
e_info(probe, "IOV: VF %d is enabled MAC %pM\n",
vfn, vf_mac_addr);
memcpy(adapter->vfinfo[vfn].vf_mac_addresses, vf_mac_addr, 6);
switch (adapter->hw.mac.type) {
case ixgbe_mac_82599EB:
device_id = IXGBE_DEV_ID_82599_VF;
break;
case ixgbe_mac_X540:
device_id = IXGBE_DEV_ID_X540_VF;
break;
default:
device_id = 0;
break;
}
pvfdev = pci_get_device(IXGBE_INTEL_VENDOR_ID, device_id, NULL);
while (pvfdev) {
if (pvfdev->devfn == thisvf_devfn)
break;
pvfdev = pci_get_device(IXGBE_INTEL_VENDOR_ID,
device_id, pvfdev);
}
if (pvfdev)
adapter->vfinfo[vfn].vfdev = pvfdev;
else
e_err(drv, "Couldn't find pci dev ptr for VF %4.4x\n",
thisvf_devfn);
}
return 0;
}
static inline void ixgbe_vf_reset_msg(struct ixgbe_adapter *adapter, u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 reg;
u32 reg_offset, vf_shift;
vf_shift = vf % 32;
reg_offset = vf / 32;
reg = IXGBE_READ_REG(hw, IXGBE_VFTE(reg_offset));
reg |= (reg | (1 << vf_shift));
IXGBE_WRITE_REG(hw, IXGBE_VFTE(reg_offset), reg);
reg = IXGBE_READ_REG(hw, IXGBE_VFRE(reg_offset));
reg |= (reg | (1 << vf_shift));
IXGBE_WRITE_REG(hw, IXGBE_VFRE(reg_offset), reg);
reg = IXGBE_READ_REG(hw, IXGBE_VMECM(reg_offset));
reg |= (1 << vf_shift);
IXGBE_WRITE_REG(hw, IXGBE_VMECM(reg_offset), reg);
ixgbe_vf_reset_event(adapter, vf);
}
static int ixgbe_rcv_msg_from_vf(struct ixgbe_adapter *adapter, u32 vf)
{
u32 mbx_size = IXGBE_VFMAILBOX_SIZE;
u32 msgbuf[IXGBE_VFMAILBOX_SIZE];
struct ixgbe_hw *hw = &adapter->hw;
s32 retval;
int entries;
u16 *hash_list;
int add, vid, index;
u8 *new_mac;
retval = ixgbe_read_mbx(hw, msgbuf, mbx_size, vf);
if (retval) {
pr_err("Error receiving message from VF\n");
return retval;
}
if (msgbuf[0] & (IXGBE_VT_MSGTYPE_ACK | IXGBE_VT_MSGTYPE_NACK))
return retval;
IXGBE_WRITE_FLUSH(hw);
if (msgbuf[0] == IXGBE_VF_RESET) {
unsigned char *vf_mac = adapter->vfinfo[vf].vf_mac_addresses;
new_mac = (u8 *)(&msgbuf[1]);
e_info(probe, "VF Reset msg received from vf %d\n", vf);
adapter->vfinfo[vf].clear_to_send = false;
ixgbe_vf_reset_msg(adapter, vf);
adapter->vfinfo[vf].clear_to_send = true;
if (is_valid_ether_addr(new_mac) &&
!adapter->vfinfo[vf].pf_set_mac)
ixgbe_set_vf_mac(adapter, vf, vf_mac);
else
ixgbe_set_vf_mac(adapter,
vf, adapter->vfinfo[vf].vf_mac_addresses);
msgbuf[0] = IXGBE_VF_RESET | IXGBE_VT_MSGTYPE_ACK;
memcpy(new_mac, vf_mac, ETH_ALEN);
msgbuf[3] = hw->mac.mc_filter_type;
ixgbe_write_mbx(hw, msgbuf, IXGBE_VF_PERMADDR_MSG_LEN, vf);
return retval;
}
if (!adapter->vfinfo[vf].clear_to_send) {
msgbuf[0] |= IXGBE_VT_MSGTYPE_NACK;
ixgbe_write_mbx(hw, msgbuf, 1, vf);
return retval;
}
switch ((msgbuf[0] & 0xFFFF)) {
case IXGBE_VF_SET_MAC_ADDR:
new_mac = ((u8 *)(&msgbuf[1]));
if (is_valid_ether_addr(new_mac) &&
!adapter->vfinfo[vf].pf_set_mac) {
ixgbe_set_vf_mac(adapter, vf, new_mac);
} else if (memcmp(adapter->vfinfo[vf].vf_mac_addresses,
new_mac, ETH_ALEN)) {
e_warn(drv, "VF %d attempted to override "
"administratively set MAC address\nReload "
"the VF driver to resume operations\n", vf);
retval = -1;
}
break;
case IXGBE_VF_SET_MULTICAST:
entries = (msgbuf[0] & IXGBE_VT_MSGINFO_MASK)
>> IXGBE_VT_MSGINFO_SHIFT;
hash_list = (u16 *)&msgbuf[1];
retval = ixgbe_set_vf_multicasts(adapter, entries,
hash_list, vf);
break;
case IXGBE_VF_SET_LPE:
ixgbe_set_vf_lpe(adapter, msgbuf);
break;
case IXGBE_VF_SET_VLAN:
add = (msgbuf[0] & IXGBE_VT_MSGINFO_MASK)
>> IXGBE_VT_MSGINFO_SHIFT;
vid = (msgbuf[1] & IXGBE_VLVF_VLANID_MASK);
if (adapter->vfinfo[vf].pf_vlan) {
e_warn(drv, "VF %d attempted to override "
"administratively set VLAN configuration\n"
"Reload the VF driver to resume operations\n",
vf);
retval = -1;
} else {
if (add)
adapter->vfinfo[vf].vlan_count++;
else if (adapter->vfinfo[vf].vlan_count)
adapter->vfinfo[vf].vlan_count--;
retval = ixgbe_set_vf_vlan(adapter, add, vid, vf);
if (!retval && adapter->vfinfo[vf].spoofchk_enabled)
hw->mac.ops.set_vlan_anti_spoofing(hw, true, vf);
}
break;
case IXGBE_VF_SET_MACVLAN:
index = (msgbuf[0] & IXGBE_VT_MSGINFO_MASK) >>
IXGBE_VT_MSGINFO_SHIFT;
if (adapter->vfinfo[vf].pf_set_mac && index > 0) {
e_warn(drv, "VF %d requested MACVLAN filter but is "
"administratively denied\n", vf);
retval = -1;
break;
}
if (index > 0 && adapter->vfinfo[vf].spoofchk_enabled)
ixgbe_ndo_set_vf_spoofchk(adapter->netdev, vf, false);
retval = ixgbe_set_vf_macvlan(adapter, vf, index,
(unsigned char *)(&msgbuf[1]));
if (retval == -ENOSPC)
e_warn(drv, "VF %d has requested a MACVLAN filter "
"but there is no space for it\n", vf);
break;
default:
e_err(drv, "Unhandled Msg %8.8x\n", msgbuf[0]);
retval = IXGBE_ERR_MBX;
break;
}
if (retval)
msgbuf[0] |= IXGBE_VT_MSGTYPE_NACK;
else
msgbuf[0] |= IXGBE_VT_MSGTYPE_ACK;
msgbuf[0] |= IXGBE_VT_MSGTYPE_CTS;
ixgbe_write_mbx(hw, msgbuf, 1, vf);
return retval;
}
static void ixgbe_rcv_ack_from_vf(struct ixgbe_adapter *adapter, u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 msg = IXGBE_VT_MSGTYPE_NACK;
if (!adapter->vfinfo[vf].clear_to_send)
ixgbe_write_mbx(hw, &msg, 1, vf);
}
void ixgbe_msg_task(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vf;
for (vf = 0; vf < adapter->num_vfs; vf++) {
if (!ixgbe_check_for_rst(hw, vf))
ixgbe_vf_reset_event(adapter, vf);
if (!ixgbe_check_for_msg(hw, vf))
ixgbe_rcv_msg_from_vf(adapter, vf);
if (!ixgbe_check_for_ack(hw, vf))
ixgbe_rcv_ack_from_vf(adapter, vf);
}
}
void ixgbe_disable_tx_rx(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
IXGBE_WRITE_REG(hw, IXGBE_VFTE(0), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFTE(1), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFRE(0), 0);
IXGBE_WRITE_REG(hw, IXGBE_VFRE(1), 0);
}
void ixgbe_ping_all_vfs(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 ping;
int i;
for (i = 0 ; i < adapter->num_vfs; i++) {
ping = IXGBE_PF_CONTROL_MSG;
if (adapter->vfinfo[i].clear_to_send)
ping |= IXGBE_VT_MSGTYPE_CTS;
ixgbe_write_mbx(hw, &ping, 1, i);
}
}
int ixgbe_ndo_set_vf_mac(struct net_device *netdev, int vf, u8 *mac)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (!is_valid_ether_addr(mac) || (vf >= adapter->num_vfs))
return -EINVAL;
adapter->vfinfo[vf].pf_set_mac = true;
dev_info(&adapter->pdev->dev, "setting MAC %pM on VF %d\n", mac, vf);
dev_info(&adapter->pdev->dev, "Reload the VF driver to make this"
" change effective.");
if (test_bit(__IXGBE_DOWN, &adapter->state)) {
dev_warn(&adapter->pdev->dev, "The VF MAC address has been set,"
" but the PF device is not up.\n");
dev_warn(&adapter->pdev->dev, "Bring the PF device up before"
" attempting to use the VF device.\n");
}
return ixgbe_set_vf_mac(adapter, vf, mac);
}
int ixgbe_ndo_set_vf_vlan(struct net_device *netdev, int vf, u16 vlan, u8 qos)
{
int err = 0;
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
if ((vf >= adapter->num_vfs) || (vlan > 4095) || (qos > 7))
return -EINVAL;
if (vlan || qos) {
err = ixgbe_set_vf_vlan(adapter, true, vlan, vf);
if (err)
goto out;
ixgbe_set_vmvir(adapter, vlan | (qos << VLAN_PRIO_SHIFT), vf);
ixgbe_set_vmolr(hw, vf, false);
if (adapter->vfinfo[vf].spoofchk_enabled)
hw->mac.ops.set_vlan_anti_spoofing(hw, true, vf);
adapter->vfinfo[vf].vlan_count++;
adapter->vfinfo[vf].pf_vlan = vlan;
adapter->vfinfo[vf].pf_qos = qos;
dev_info(&adapter->pdev->dev,
"Setting VLAN %d, QOS 0x%x on VF %d\n", vlan, qos, vf);
if (test_bit(__IXGBE_DOWN, &adapter->state)) {
dev_warn(&adapter->pdev->dev,
"The VF VLAN has been set,"
" but the PF device is not up.\n");
dev_warn(&adapter->pdev->dev,
"Bring the PF device up before"
" attempting to use the VF device.\n");
}
} else {
err = ixgbe_set_vf_vlan(adapter, false,
adapter->vfinfo[vf].pf_vlan, vf);
ixgbe_set_vmvir(adapter, vlan, vf);
ixgbe_set_vmolr(hw, vf, true);
hw->mac.ops.set_vlan_anti_spoofing(hw, false, vf);
if (adapter->vfinfo[vf].vlan_count)
adapter->vfinfo[vf].vlan_count--;
adapter->vfinfo[vf].pf_vlan = 0;
adapter->vfinfo[vf].pf_qos = 0;
}
out:
return err;
}
static int ixgbe_link_mbps(int internal_link_speed)
{
switch (internal_link_speed) {
case IXGBE_LINK_SPEED_100_FULL:
return 100;
case IXGBE_LINK_SPEED_1GB_FULL:
return 1000;
case IXGBE_LINK_SPEED_10GB_FULL:
return 10000;
default:
return 0;
}
}
static void ixgbe_set_vf_rate_limit(struct ixgbe_hw *hw, int vf, int tx_rate,
int link_speed)
{
int rf_dec, rf_int;
u32 bcnrc_val;
if (tx_rate != 0) {
rf_int = link_speed / tx_rate;
rf_dec = (link_speed - (rf_int * tx_rate));
rf_dec = (rf_dec * (1<<IXGBE_RTTBCNRC_RF_INT_SHIFT)) / tx_rate;
bcnrc_val = IXGBE_RTTBCNRC_RS_ENA;
bcnrc_val |= ((rf_int<<IXGBE_RTTBCNRC_RF_INT_SHIFT) &
IXGBE_RTTBCNRC_RF_INT_MASK);
bcnrc_val |= (rf_dec & IXGBE_RTTBCNRC_RF_DEC_MASK);
} else {
bcnrc_val = 0;
}
IXGBE_WRITE_REG(hw, IXGBE_RTTDQSEL, 2*vf);
switch (hw->mac.type) {
case ixgbe_mac_82599EB:
IXGBE_WRITE_REG(hw, IXGBE_RTTBCNRM, 0x4);
break;
case ixgbe_mac_X540:
IXGBE_WRITE_REG(hw, IXGBE_RTTBCNRM, 0x14);
break;
default:
break;
}
IXGBE_WRITE_REG(hw, IXGBE_RTTBCNRC, bcnrc_val);
}
void ixgbe_check_vf_rate_limit(struct ixgbe_adapter *adapter)
{
int actual_link_speed, i;
bool reset_rate = false;
if (adapter->vf_rate_link_speed == 0)
return;
actual_link_speed = ixgbe_link_mbps(adapter->link_speed);
if (actual_link_speed != adapter->vf_rate_link_speed) {
reset_rate = true;
adapter->vf_rate_link_speed = 0;
dev_info(&adapter->pdev->dev,
"Link speed has been changed. VF Transmit rate "
"is disabled\n");
}
for (i = 0; i < adapter->num_vfs; i++) {
if (reset_rate)
adapter->vfinfo[i].tx_rate = 0;
ixgbe_set_vf_rate_limit(&adapter->hw, i,
adapter->vfinfo[i].tx_rate,
actual_link_speed);
}
}
int ixgbe_ndo_set_vf_bw(struct net_device *netdev, int vf, int tx_rate)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
int actual_link_speed;
actual_link_speed = ixgbe_link_mbps(adapter->link_speed);
if ((vf >= adapter->num_vfs) || (!adapter->link_up) ||
(tx_rate > actual_link_speed) || (actual_link_speed != 10000) ||
((tx_rate != 0) && (tx_rate <= 10)))
return -EINVAL;
adapter->vf_rate_link_speed = actual_link_speed;
adapter->vfinfo[vf].tx_rate = (u16)tx_rate;
ixgbe_set_vf_rate_limit(hw, vf, tx_rate, actual_link_speed);
return 0;
}
int ixgbe_ndo_set_vf_spoofchk(struct net_device *netdev, int vf, bool setting)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int vf_target_reg = vf >> 3;
int vf_target_shift = vf % 8;
struct ixgbe_hw *hw = &adapter->hw;
u32 regval;
adapter->vfinfo[vf].spoofchk_enabled = setting;
regval = IXGBE_READ_REG(hw, IXGBE_PFVFSPOOF(vf_target_reg));
regval &= ~(1 << vf_target_shift);
regval |= (setting << vf_target_shift);
IXGBE_WRITE_REG(hw, IXGBE_PFVFSPOOF(vf_target_reg), regval);
if (adapter->vfinfo[vf].vlan_count) {
vf_target_shift += IXGBE_SPOOF_VLANAS_SHIFT;
regval = IXGBE_READ_REG(hw, IXGBE_PFVFSPOOF(vf_target_reg));
regval &= ~(1 << vf_target_shift);
regval |= (setting << vf_target_shift);
IXGBE_WRITE_REG(hw, IXGBE_PFVFSPOOF(vf_target_reg), regval);
}
return 0;
}
int ixgbe_ndo_get_vf_config(struct net_device *netdev,
int vf, struct ifla_vf_info *ivi)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (vf >= adapter->num_vfs)
return -EINVAL;
ivi->vf = vf;
memcpy(&ivi->mac, adapter->vfinfo[vf].vf_mac_addresses, ETH_ALEN);
ivi->tx_rate = adapter->vfinfo[vf].tx_rate;
ivi->vlan = adapter->vfinfo[vf].pf_vlan;
ivi->qos = adapter->vfinfo[vf].pf_qos;
ivi->spoofchk = adapter->vfinfo[vf].spoofchk_enabled;
return 0;
}
