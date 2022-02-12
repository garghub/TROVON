static int __ixgbe_enable_sriov(struct ixgbe_adapter *adapter)
{
struct ixgbe_hw *hw = &adapter->hw;
int num_vf_macvlans, i;
struct vf_macvlans *mv_list;
adapter->flags |= IXGBE_FLAG_SRIOV_ENABLED;
e_info(probe, "SR-IOV enabled with %d VFs\n", adapter->num_vfs);
adapter->flags |= IXGBE_FLAG_VMDQ_ENABLED;
if (!adapter->ring_feature[RING_F_VMDQ].limit)
adapter->ring_feature[RING_F_VMDQ].limit = 1;
adapter->ring_feature[RING_F_VMDQ].offset = adapter->num_vfs;
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
list_add(&mv_list->l, &adapter->vf_mvs.l);
mv_list++;
}
}
IXGBE_WRITE_REG(hw, IXGBE_PFDTXGSWC, IXGBE_PFDTXGSWC_VT_LBEN);
adapter->bridge_mode = BRIDGE_MODE_VEB;
adapter->vfinfo =
kcalloc(adapter->num_vfs,
sizeof(struct vf_data_storage), GFP_KERNEL);
if (adapter->vfinfo) {
if ((adapter->hw.mac.type == ixgbe_mac_82599EB) &&
(adapter->num_vfs < 16)) {
adapter->dcb_cfg.num_tcs.pg_tcs = MAX_TRAFFIC_CLASS;
adapter->dcb_cfg.num_tcs.pfc_tcs = MAX_TRAFFIC_CLASS;
} else if (adapter->num_vfs < 32) {
adapter->dcb_cfg.num_tcs.pg_tcs = 4;
adapter->dcb_cfg.num_tcs.pfc_tcs = 4;
} else {
adapter->dcb_cfg.num_tcs.pg_tcs = 1;
adapter->dcb_cfg.num_tcs.pfc_tcs = 1;
}
adapter->flags2 &= ~(IXGBE_FLAG2_RSC_CAPABLE |
IXGBE_FLAG2_RSC_ENABLED);
for (i = 0; i < adapter->num_vfs; i++) {
adapter->vfinfo[i].spoofchk_enabled = true;
adapter->vfinfo[i].rss_query_enabled = 0;
adapter->vfinfo[i].trusted = false;
adapter->vfinfo[i].xcast_mode = IXGBEVF_XCAST_MODE_NONE;
}
return 0;
}
return -ENOMEM;
}
static void ixgbe_get_vfs(struct ixgbe_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
u16 vendor = pdev->vendor;
struct pci_dev *vfdev;
int vf = 0;
u16 vf_id;
int pos;
pos = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_SRIOV);
if (!pos)
return;
pci_read_config_word(pdev, pos + PCI_SRIOV_VF_DID, &vf_id);
vfdev = pci_get_device(vendor, vf_id, NULL);
for (; vfdev; vfdev = pci_get_device(vendor, vf_id, vfdev)) {
if (!vfdev->is_virtfn)
continue;
if (vfdev->physfn != pdev)
continue;
if (vf >= adapter->num_vfs)
continue;
pci_dev_get(vfdev);
adapter->vfinfo[vf].vfdev = vfdev;
++vf;
}
}
void ixgbe_enable_sriov(struct ixgbe_adapter *adapter)
{
int pre_existing_vfs = 0;
pre_existing_vfs = pci_num_vf(adapter->pdev);
if (!pre_existing_vfs && !adapter->num_vfs)
return;
if (pre_existing_vfs) {
adapter->num_vfs = pre_existing_vfs;
dev_warn(&adapter->pdev->dev,
"Virtual Functions already enabled for this device - Please reload all VF drivers to avoid spoofed packet errors\n");
} else {
int err;
adapter->num_vfs = min_t(unsigned int, adapter->num_vfs, IXGBE_MAX_VFS_DRV_LIMIT);
err = pci_enable_sriov(adapter->pdev, adapter->num_vfs);
if (err) {
e_err(probe, "Failed to enable PCI sriov: %d\n", err);
adapter->num_vfs = 0;
return;
}
}
if (!__ixgbe_enable_sriov(adapter)) {
ixgbe_get_vfs(adapter);
return;
}
e_err(probe, "Unable to allocate memory for VF Data Storage - "
"SRIOV disabled\n");
ixgbe_disable_sriov(adapter);
}
int ixgbe_disable_sriov(struct ixgbe_adapter *adapter)
{
unsigned int num_vfs = adapter->num_vfs, vf;
struct ixgbe_hw *hw = &adapter->hw;
u32 gpie;
u32 vmdctl;
int rss;
adapter->num_vfs = 0;
for (vf = 0; vf < num_vfs; ++vf) {
struct pci_dev *vfdev = adapter->vfinfo[vf].vfdev;
if (!vfdev)
continue;
adapter->vfinfo[vf].vfdev = NULL;
pci_dev_put(vfdev);
}
kfree(adapter->vfinfo);
adapter->vfinfo = NULL;
kfree(adapter->mv_list);
adapter->mv_list = NULL;
if (!(adapter->flags & IXGBE_FLAG_SRIOV_ENABLED))
return 0;
#ifdef CONFIG_PCI_IOV
if (pci_vfs_assigned(adapter->pdev)) {
e_dev_warn("Unloading driver while VFs are assigned - VFs will not be deallocated\n");
return -EPERM;
}
pci_disable_sriov(adapter->pdev);
#endif
IXGBE_WRITE_REG(hw, IXGBE_GCR_EXT, 0);
gpie = IXGBE_READ_REG(hw, IXGBE_GPIE);
gpie &= ~IXGBE_GPIE_VTMODE_MASK;
IXGBE_WRITE_REG(hw, IXGBE_GPIE, gpie);
vmdctl = IXGBE_READ_REG(hw, IXGBE_VT_CTL);
vmdctl &= ~IXGBE_VT_CTL_POOL_MASK;
IXGBE_WRITE_REG(hw, IXGBE_VT_CTL, vmdctl);
IXGBE_WRITE_FLUSH(hw);
if (adapter->ring_feature[RING_F_VMDQ].limit == 1) {
adapter->flags &= ~IXGBE_FLAG_VMDQ_ENABLED;
adapter->flags &= ~IXGBE_FLAG_SRIOV_ENABLED;
rss = min_t(int, ixgbe_max_rss_indices(adapter),
num_online_cpus());
} else {
rss = min_t(int, IXGBE_MAX_L2A_QUEUES, num_online_cpus());
}
adapter->ring_feature[RING_F_VMDQ].offset = 0;
adapter->ring_feature[RING_F_RSS].limit = rss;
msleep(100);
return 0;
}
static int ixgbe_pci_sriov_enable(struct pci_dev *dev, int num_vfs)
{
#ifdef CONFIG_PCI_IOV
struct ixgbe_adapter *adapter = pci_get_drvdata(dev);
int err = 0;
int i;
int pre_existing_vfs = pci_num_vf(dev);
if (pre_existing_vfs && pre_existing_vfs != num_vfs)
err = ixgbe_disable_sriov(adapter);
else if (pre_existing_vfs && pre_existing_vfs == num_vfs)
return num_vfs;
if (err)
return err;
if ((num_vfs + adapter->num_rx_pools) > IXGBE_MAX_VF_FUNCTIONS)
return -EPERM;
adapter->num_vfs = num_vfs;
err = __ixgbe_enable_sriov(adapter);
if (err)
return err;
for (i = 0; i < adapter->num_vfs; i++)
ixgbe_vf_configuration(dev, (i | 0x10000000));
err = pci_enable_sriov(dev, num_vfs);
if (err) {
e_dev_warn("Failed to enable PCI sriov: %d\n", err);
return err;
}
ixgbe_get_vfs(adapter);
ixgbe_sriov_reinit(adapter);
return num_vfs;
#else
return 0;
#endif
}
static int ixgbe_pci_sriov_disable(struct pci_dev *dev)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(dev);
int err;
#ifdef CONFIG_PCI_IOV
u32 current_flags = adapter->flags;
#endif
err = ixgbe_disable_sriov(adapter);
#ifdef CONFIG_PCI_IOV
if (!err && current_flags != adapter->flags)
ixgbe_sriov_reinit(adapter);
#endif
return err;
}
int ixgbe_pci_sriov_configure(struct pci_dev *dev, int num_vfs)
{
if (num_vfs == 0)
return ixgbe_pci_sriov_disable(dev);
else
return ixgbe_pci_sriov_enable(dev, num_vfs);
}
static int ixgbe_set_vf_multicasts(struct ixgbe_adapter *adapter,
u32 *msgbuf, u32 vf)
{
int entries = (msgbuf[0] & IXGBE_VT_MSGINFO_MASK)
>> IXGBE_VT_MSGINFO_SHIFT;
u16 *hash_list = (u16 *)&msgbuf[1];
struct vf_data_storage *vfinfo = &adapter->vfinfo[vf];
struct ixgbe_hw *hw = &adapter->hw;
int i;
u32 vector_bit;
u32 vector_reg;
u32 mta_reg;
u32 vmolr = IXGBE_READ_REG(hw, IXGBE_VMOLR(vf));
entries = min(entries, IXGBE_MAX_VF_MC_ENTRIES);
vfinfo->num_vf_mc_hashes = entries;
for (i = 0; i < entries; i++) {
vfinfo->vf_mc_hashes[i] = hash_list[i];
}
for (i = 0; i < vfinfo->num_vf_mc_hashes; i++) {
vector_reg = (vfinfo->vf_mc_hashes[i] >> 5) & 0x7F;
vector_bit = vfinfo->vf_mc_hashes[i] & 0x1F;
mta_reg = IXGBE_READ_REG(hw, IXGBE_MTA(vector_reg));
mta_reg |= BIT(vector_bit);
IXGBE_WRITE_REG(hw, IXGBE_MTA(vector_reg), mta_reg);
}
vmolr |= IXGBE_VMOLR_ROMPE;
IXGBE_WRITE_REG(hw, IXGBE_VMOLR(vf), vmolr);
return 0;
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
u32 vmolr = IXGBE_READ_REG(hw, IXGBE_VMOLR(i));
vfinfo = &adapter->vfinfo[i];
for (j = 0; j < vfinfo->num_vf_mc_hashes; j++) {
hw->addr_ctrl.mta_in_use++;
vector_reg = (vfinfo->vf_mc_hashes[j] >> 5) & 0x7F;
vector_bit = vfinfo->vf_mc_hashes[j] & 0x1F;
mta_reg = IXGBE_READ_REG(hw, IXGBE_MTA(vector_reg));
mta_reg |= BIT(vector_bit);
IXGBE_WRITE_REG(hw, IXGBE_MTA(vector_reg), mta_reg);
}
if (vfinfo->num_vf_mc_hashes)
vmolr |= IXGBE_VMOLR_ROMPE;
else
vmolr &= ~IXGBE_VMOLR_ROMPE;
IXGBE_WRITE_REG(hw, IXGBE_VMOLR(i), vmolr);
}
ixgbe_full_sync_mac_table(adapter);
}
static int ixgbe_set_vf_vlan(struct ixgbe_adapter *adapter, int add, int vid,
u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
int err;
if (add && test_bit(vid, adapter->active_vlans)) {
err = hw->mac.ops.set_vfta(hw, vid, VMDQ_P(0), true, false);
if (err)
return err;
}
err = hw->mac.ops.set_vfta(hw, vid, vf, !!add, false);
if (add && !err)
return err;
if (test_bit(vid, adapter->active_vlans) ||
(adapter->flags2 & IXGBE_FLAG2_VLAN_PROMISC))
ixgbe_update_pf_promisc_vlvf(adapter, vid);
return err;
}
static s32 ixgbe_set_vf_lpe(struct ixgbe_adapter *adapter, u32 *msgbuf, u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
int max_frame = msgbuf[1];
u32 max_frs;
if (adapter->hw.mac.type == ixgbe_mac_82599EB) {
struct net_device *dev = adapter->netdev;
int pf_max_frame = dev->mtu + ETH_HLEN;
u32 reg_offset, vf_shift, vfre;
s32 err = 0;
#ifdef CONFIG_FCOE
if (dev->features & NETIF_F_FCOE_MTU)
pf_max_frame = max_t(int, pf_max_frame,
IXGBE_FCOE_JUMBO_FRAME_SIZE);
#endif
switch (adapter->vfinfo[vf].vf_api) {
case ixgbe_mbox_api_11:
case ixgbe_mbox_api_12:
if (pf_max_frame > ETH_FRAME_LEN)
break;
default:
if ((pf_max_frame > ETH_FRAME_LEN) ||
(max_frame > (ETH_FRAME_LEN + ETH_FCS_LEN)))
err = -EINVAL;
break;
}
vf_shift = vf % 32;
reg_offset = vf / 32;
vfre = IXGBE_READ_REG(hw, IXGBE_VFRE(reg_offset));
if (err)
vfre &= ~BIT(vf_shift);
else
vfre |= BIT(vf_shift);
IXGBE_WRITE_REG(hw, IXGBE_VFRE(reg_offset), vfre);
if (err) {
e_err(drv, "VF max_frame %d out of range\n", max_frame);
return err;
}
}
if (max_frame > IXGBE_MAX_JUMBO_FRAME_SIZE) {
e_err(drv, "VF max_frame %d out of range\n", max_frame);
return -EINVAL;
}
max_frs = IXGBE_READ_REG(hw, IXGBE_MAXFRS);
max_frs &= IXGBE_MHADD_MFS_MASK;
max_frs >>= IXGBE_MHADD_MFS_SHIFT;
if (max_frs < max_frame) {
max_frs = max_frame << IXGBE_MHADD_MFS_SHIFT;
IXGBE_WRITE_REG(hw, IXGBE_MAXFRS, max_frs);
}
e_info(hw, "VF requests change max MTU to %d\n", max_frame);
return 0;
}
static void ixgbe_set_vmolr(struct ixgbe_hw *hw, u32 vf, bool aupe)
{
u32 vmolr = IXGBE_READ_REG(hw, IXGBE_VMOLR(vf));
vmolr |= IXGBE_VMOLR_BAM;
if (aupe)
vmolr |= IXGBE_VMOLR_AUPE;
else
vmolr &= ~IXGBE_VMOLR_AUPE;
IXGBE_WRITE_REG(hw, IXGBE_VMOLR(vf), vmolr);
}
static void ixgbe_clear_vmvir(struct ixgbe_adapter *adapter, u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
IXGBE_WRITE_REG(hw, IXGBE_VMVIR(vf), 0);
}
static void ixgbe_clear_vf_vlans(struct ixgbe_adapter *adapter, u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 vlvfb_mask, pool_mask, i;
pool_mask = ~BIT(VMDQ_P(0) % 32);
vlvfb_mask = BIT(vf % 32);
for (i = IXGBE_VLVF_ENTRIES; i--;) {
u32 bits[2], vlvfb, vid, vfta, vlvf;
u32 word = i * 2 + vf / 32;
u32 mask;
vlvfb = IXGBE_READ_REG(hw, IXGBE_VLVFB(word));
if (!(vlvfb & vlvfb_mask))
continue;
vlvfb ^= vlvfb_mask;
bits[word % 2] = vlvfb;
bits[~word % 2] = IXGBE_READ_REG(hw, IXGBE_VLVFB(word ^ 1));
if (bits[(VMDQ_P(0) / 32) ^ 1] ||
(bits[VMDQ_P(0) / 32] & pool_mask))
goto update_vlvfb;
if (bits[0] || bits[1])
goto update_vlvf;
vlvf = IXGBE_READ_REG(hw, IXGBE_VLVF(i));
if (!vlvf)
goto update_vlvfb;
vid = vlvf & VLAN_VID_MASK;
mask = BIT(vid % 32);
vfta = IXGBE_READ_REG(hw, IXGBE_VFTA(vid / 32));
if (vfta & mask)
IXGBE_WRITE_REG(hw, IXGBE_VFTA(vid / 32), vfta ^ mask);
update_vlvf:
IXGBE_WRITE_REG(hw, IXGBE_VLVF(i), 0);
if (!(adapter->flags2 & IXGBE_FLAG2_VLAN_PROMISC))
vlvfb = 0;
update_vlvfb:
IXGBE_WRITE_REG(hw, IXGBE_VLVFB(word), vlvfb);
}
}
static inline void ixgbe_vf_reset_event(struct ixgbe_adapter *adapter, u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
struct vf_data_storage *vfinfo = &adapter->vfinfo[vf];
u8 num_tcs = netdev_get_num_tc(adapter->netdev);
ixgbe_clear_vf_vlans(adapter, vf);
ixgbe_set_vf_vlan(adapter, true, vfinfo->pf_vlan, vf);
ixgbe_set_vmolr(hw, vf, !vfinfo->pf_vlan);
if (!vfinfo->pf_vlan && !vfinfo->pf_qos && !num_tcs) {
ixgbe_clear_vmvir(adapter, vf);
} else {
if (vfinfo->pf_qos || !num_tcs)
ixgbe_set_vmvir(adapter, vfinfo->pf_vlan,
vfinfo->pf_qos, vf);
else
ixgbe_set_vmvir(adapter, vfinfo->pf_vlan,
adapter->default_up, vf);
if (vfinfo->spoofchk_enabled)
hw->mac.ops.set_vlan_anti_spoofing(hw, true, vf);
}
adapter->vfinfo[vf].num_vf_mc_hashes = 0;
ixgbe_set_rx_mode(adapter->netdev);
ixgbe_del_mac_filter(adapter, adapter->vfinfo[vf].vf_mac_addresses, vf);
adapter->vfinfo[vf].vf_api = ixgbe_mbox_api_10;
}
static int ixgbe_set_vf_mac(struct ixgbe_adapter *adapter,
int vf, unsigned char *mac_addr)
{
ixgbe_del_mac_filter(adapter, adapter->vfinfo[vf].vf_mac_addresses, vf);
memcpy(adapter->vfinfo[vf].vf_mac_addresses, mac_addr, ETH_ALEN);
ixgbe_add_mac_filter(adapter, adapter->vfinfo[vf].vf_mac_addresses, vf);
return 0;
}
static int ixgbe_set_vf_macvlan(struct ixgbe_adapter *adapter,
int vf, int index, unsigned char *mac_addr)
{
struct list_head *pos;
struct vf_macvlans *entry;
if (index <= 1) {
list_for_each(pos, &adapter->vf_mvs.l) {
entry = list_entry(pos, struct vf_macvlans, l);
if (entry->vf == vf) {
entry->vf = -1;
entry->free = true;
entry->is_macvlan = false;
ixgbe_del_mac_filter(adapter,
entry->vf_macvlan, vf);
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
ixgbe_add_mac_filter(adapter, mac_addr, vf);
return 0;
}
int ixgbe_vf_configuration(struct pci_dev *pdev, unsigned int event_mask)
{
struct ixgbe_adapter *adapter = pci_get_drvdata(pdev);
unsigned int vfn = (event_mask & 0x3f);
bool enable = ((event_mask & 0x10000000U) != 0);
if (enable)
eth_zero_addr(adapter->vfinfo[vfn].vf_mac_addresses);
return 0;
}
static inline void ixgbe_write_qde(struct ixgbe_adapter *adapter, u32 vf,
u32 qde)
{
struct ixgbe_hw *hw = &adapter->hw;
struct ixgbe_ring_feature *vmdq = &adapter->ring_feature[RING_F_VMDQ];
u32 q_per_pool = __ALIGN_MASK(1, ~vmdq->mask);
int i;
for (i = vf * q_per_pool; i < ((vf + 1) * q_per_pool); i++) {
u32 reg;
IXGBE_WRITE_FLUSH(hw);
reg = IXGBE_QDE_WRITE | IXGBE_QDE_ENABLE;
reg |= i << IXGBE_QDE_IDX_SHIFT;
IXGBE_WRITE_REG(hw, IXGBE_QDE, reg);
}
}
static int ixgbe_vf_reset_msg(struct ixgbe_adapter *adapter, u32 vf)
{
struct ixgbe_ring_feature *vmdq = &adapter->ring_feature[RING_F_VMDQ];
struct ixgbe_hw *hw = &adapter->hw;
unsigned char *vf_mac = adapter->vfinfo[vf].vf_mac_addresses;
u32 reg, reg_offset, vf_shift;
u32 msgbuf[4] = {0, 0, 0, 0};
u8 *addr = (u8 *)(&msgbuf[1]);
u32 q_per_pool = __ALIGN_MASK(1, ~vmdq->mask);
int i;
e_info(probe, "VF Reset msg received from vf %d\n", vf);
ixgbe_vf_reset_event(adapter, vf);
if (!is_zero_ether_addr(vf_mac))
ixgbe_set_vf_mac(adapter, vf, vf_mac);
vf_shift = vf % 32;
reg_offset = vf / 32;
reg = IXGBE_READ_REG(hw, IXGBE_VFTE(reg_offset));
reg |= BIT(vf_shift);
IXGBE_WRITE_REG(hw, IXGBE_VFTE(reg_offset), reg);
ixgbe_write_qde(adapter, vf, IXGBE_QDE_ENABLE);
reg = IXGBE_READ_REG(hw, IXGBE_VFRE(reg_offset));
reg |= BIT(vf_shift);
if (adapter->hw.mac.type == ixgbe_mac_82599EB) {
struct net_device *dev = adapter->netdev;
int pf_max_frame = dev->mtu + ETH_HLEN;
#ifdef CONFIG_FCOE
if (dev->features & NETIF_F_FCOE_MTU)
pf_max_frame = max_t(int, pf_max_frame,
IXGBE_FCOE_JUMBO_FRAME_SIZE);
#endif
if (pf_max_frame > ETH_FRAME_LEN)
reg &= ~BIT(vf_shift);
}
IXGBE_WRITE_REG(hw, IXGBE_VFRE(reg_offset), reg);
adapter->vfinfo[vf].clear_to_send = true;
reg = IXGBE_READ_REG(hw, IXGBE_VMECM(reg_offset));
reg |= BIT(vf_shift);
IXGBE_WRITE_REG(hw, IXGBE_VMECM(reg_offset), reg);
for (i = 0; i < q_per_pool; i++) {
IXGBE_WRITE_REG(hw, IXGBE_PVFTDWBAHn(q_per_pool, vf, i), 0);
IXGBE_WRITE_REG(hw, IXGBE_PVFTDWBALn(q_per_pool, vf, i), 0);
}
msgbuf[0] = IXGBE_VF_RESET;
if (!is_zero_ether_addr(vf_mac)) {
msgbuf[0] |= IXGBE_VT_MSGTYPE_ACK;
memcpy(addr, vf_mac, ETH_ALEN);
} else {
msgbuf[0] |= IXGBE_VT_MSGTYPE_NACK;
dev_warn(&adapter->pdev->dev,
"VF %d has no MAC address assigned, you may have to assign one manually\n",
vf);
}
msgbuf[3] = hw->mac.mc_filter_type;
ixgbe_write_mbx(hw, msgbuf, IXGBE_VF_PERMADDR_MSG_LEN, vf);
return 0;
}
static int ixgbe_set_vf_mac_addr(struct ixgbe_adapter *adapter,
u32 *msgbuf, u32 vf)
{
u8 *new_mac = ((u8 *)(&msgbuf[1]));
if (!is_valid_ether_addr(new_mac)) {
e_warn(drv, "VF %d attempted to set invalid mac\n", vf);
return -1;
}
if (adapter->vfinfo[vf].pf_set_mac && !adapter->vfinfo[vf].trusted &&
!ether_addr_equal(adapter->vfinfo[vf].vf_mac_addresses, new_mac)) {
e_warn(drv,
"VF %d attempted to override administratively set MAC address\n"
"Reload the VF driver to resume operations\n",
vf);
return -1;
}
return ixgbe_set_vf_mac(adapter, vf, new_mac) < 0;
}
static int ixgbe_set_vf_vlan_msg(struct ixgbe_adapter *adapter,
u32 *msgbuf, u32 vf)
{
u32 add = (msgbuf[0] & IXGBE_VT_MSGINFO_MASK) >> IXGBE_VT_MSGINFO_SHIFT;
u32 vid = (msgbuf[1] & IXGBE_VLVF_VLANID_MASK);
u8 tcs = netdev_get_num_tc(adapter->netdev);
if (adapter->vfinfo[vf].pf_vlan || tcs) {
e_warn(drv,
"VF %d attempted to override administratively set VLAN configuration\n"
"Reload the VF driver to resume operations\n",
vf);
return -1;
}
if (!vid && !add)
return 0;
return ixgbe_set_vf_vlan(adapter, add, vid, vf);
}
static int ixgbe_set_vf_macvlan_msg(struct ixgbe_adapter *adapter,
u32 *msgbuf, u32 vf)
{
u8 *new_mac = ((u8 *)(&msgbuf[1]));
int index = (msgbuf[0] & IXGBE_VT_MSGINFO_MASK) >>
IXGBE_VT_MSGINFO_SHIFT;
int err;
if (adapter->vfinfo[vf].pf_set_mac && index > 0) {
e_warn(drv,
"VF %d requested MACVLAN filter but is administratively denied\n",
vf);
return -1;
}
if (index) {
if (!is_valid_ether_addr(new_mac)) {
e_warn(drv, "VF %d attempted to set invalid mac\n", vf);
return -1;
}
if (adapter->vfinfo[vf].spoofchk_enabled) {
struct ixgbe_hw *hw = &adapter->hw;
hw->mac.ops.set_mac_anti_spoofing(hw, false, vf);
}
}
err = ixgbe_set_vf_macvlan(adapter, vf, index, new_mac);
if (err == -ENOSPC)
e_warn(drv,
"VF %d has requested a MACVLAN filter but there is no space for it\n",
vf);
return err < 0;
}
static int ixgbe_negotiate_vf_api(struct ixgbe_adapter *adapter,
u32 *msgbuf, u32 vf)
{
int api = msgbuf[1];
switch (api) {
case ixgbe_mbox_api_10:
case ixgbe_mbox_api_11:
case ixgbe_mbox_api_12:
adapter->vfinfo[vf].vf_api = api;
return 0;
default:
break;
}
e_info(drv, "VF %d requested invalid api version %u\n", vf, api);
return -1;
}
static int ixgbe_get_vf_queues(struct ixgbe_adapter *adapter,
u32 *msgbuf, u32 vf)
{
struct net_device *dev = adapter->netdev;
struct ixgbe_ring_feature *vmdq = &adapter->ring_feature[RING_F_VMDQ];
unsigned int default_tc = 0;
u8 num_tcs = netdev_get_num_tc(dev);
switch (adapter->vfinfo[vf].vf_api) {
case ixgbe_mbox_api_20:
case ixgbe_mbox_api_11:
case ixgbe_mbox_api_12:
break;
default:
return -1;
}
msgbuf[IXGBE_VF_TX_QUEUES] = __ALIGN_MASK(1, ~vmdq->mask);
msgbuf[IXGBE_VF_RX_QUEUES] = __ALIGN_MASK(1, ~vmdq->mask);
if (num_tcs > 1)
default_tc = netdev_get_prio_tc_map(dev, adapter->default_up);
if (num_tcs)
msgbuf[IXGBE_VF_TRANS_VLAN] = num_tcs;
else if (adapter->vfinfo[vf].pf_vlan || adapter->vfinfo[vf].pf_qos)
msgbuf[IXGBE_VF_TRANS_VLAN] = 1;
else
msgbuf[IXGBE_VF_TRANS_VLAN] = 0;
msgbuf[IXGBE_VF_DEF_QUEUE] = default_tc;
return 0;
}
static int ixgbe_get_vf_reta(struct ixgbe_adapter *adapter, u32 *msgbuf, u32 vf)
{
u32 i, j;
u32 *out_buf = &msgbuf[1];
const u8 *reta = adapter->rss_indir_tbl;
u32 reta_size = ixgbe_rss_indir_tbl_entries(adapter);
if (!adapter->vfinfo[vf].rss_query_enabled)
return -EPERM;
if (adapter->vfinfo[vf].vf_api != ixgbe_mbox_api_12)
return -EOPNOTSUPP;
for (i = 0; i < reta_size / 16; i++) {
out_buf[i] = 0;
for (j = 0; j < 16; j++)
out_buf[i] |= (u32)(reta[16 * i + j] & 0x3) << (2 * j);
}
return 0;
}
static int ixgbe_get_vf_rss_key(struct ixgbe_adapter *adapter,
u32 *msgbuf, u32 vf)
{
u32 *rss_key = &msgbuf[1];
if (!adapter->vfinfo[vf].rss_query_enabled)
return -EPERM;
if (adapter->vfinfo[vf].vf_api != ixgbe_mbox_api_12)
return -EOPNOTSUPP;
memcpy(rss_key, adapter->rss_key, sizeof(adapter->rss_key));
return 0;
}
static int ixgbe_update_vf_xcast_mode(struct ixgbe_adapter *adapter,
u32 *msgbuf, u32 vf)
{
struct ixgbe_hw *hw = &adapter->hw;
int xcast_mode = msgbuf[1];
u32 vmolr, disable, enable;
switch (adapter->vfinfo[vf].vf_api) {
case ixgbe_mbox_api_12:
break;
default:
return -EOPNOTSUPP;
}
if (xcast_mode > IXGBEVF_XCAST_MODE_MULTI &&
!adapter->vfinfo[vf].trusted) {
xcast_mode = IXGBEVF_XCAST_MODE_MULTI;
}
if (adapter->vfinfo[vf].xcast_mode == xcast_mode)
goto out;
switch (xcast_mode) {
case IXGBEVF_XCAST_MODE_NONE:
disable = IXGBE_VMOLR_BAM | IXGBE_VMOLR_ROMPE | IXGBE_VMOLR_MPE;
enable = 0;
break;
case IXGBEVF_XCAST_MODE_MULTI:
disable = IXGBE_VMOLR_MPE;
enable = IXGBE_VMOLR_BAM | IXGBE_VMOLR_ROMPE;
break;
case IXGBEVF_XCAST_MODE_ALLMULTI:
disable = 0;
enable = IXGBE_VMOLR_BAM | IXGBE_VMOLR_ROMPE | IXGBE_VMOLR_MPE;
break;
default:
return -EOPNOTSUPP;
}
vmolr = IXGBE_READ_REG(hw, IXGBE_VMOLR(vf));
vmolr &= ~disable;
vmolr |= enable;
IXGBE_WRITE_REG(hw, IXGBE_VMOLR(vf), vmolr);
adapter->vfinfo[vf].xcast_mode = xcast_mode;
out:
msgbuf[1] = xcast_mode;
return 0;
}
static int ixgbe_rcv_msg_from_vf(struct ixgbe_adapter *adapter, u32 vf)
{
u32 mbx_size = IXGBE_VFMAILBOX_SIZE;
u32 msgbuf[IXGBE_VFMAILBOX_SIZE];
struct ixgbe_hw *hw = &adapter->hw;
s32 retval;
retval = ixgbe_read_mbx(hw, msgbuf, mbx_size, vf);
if (retval) {
pr_err("Error receiving message from VF\n");
return retval;
}
if (msgbuf[0] & (IXGBE_VT_MSGTYPE_ACK | IXGBE_VT_MSGTYPE_NACK))
return 0;
IXGBE_WRITE_FLUSH(hw);
if (msgbuf[0] == IXGBE_VF_RESET)
return ixgbe_vf_reset_msg(adapter, vf);
if (!adapter->vfinfo[vf].clear_to_send) {
msgbuf[0] |= IXGBE_VT_MSGTYPE_NACK;
ixgbe_write_mbx(hw, msgbuf, 1, vf);
return 0;
}
switch ((msgbuf[0] & 0xFFFF)) {
case IXGBE_VF_SET_MAC_ADDR:
retval = ixgbe_set_vf_mac_addr(adapter, msgbuf, vf);
break;
case IXGBE_VF_SET_MULTICAST:
retval = ixgbe_set_vf_multicasts(adapter, msgbuf, vf);
break;
case IXGBE_VF_SET_VLAN:
retval = ixgbe_set_vf_vlan_msg(adapter, msgbuf, vf);
break;
case IXGBE_VF_SET_LPE:
retval = ixgbe_set_vf_lpe(adapter, msgbuf, vf);
break;
case IXGBE_VF_SET_MACVLAN:
retval = ixgbe_set_vf_macvlan_msg(adapter, msgbuf, vf);
break;
case IXGBE_VF_API_NEGOTIATE:
retval = ixgbe_negotiate_vf_api(adapter, msgbuf, vf);
break;
case IXGBE_VF_GET_QUEUES:
retval = ixgbe_get_vf_queues(adapter, msgbuf, vf);
break;
case IXGBE_VF_GET_RETA:
retval = ixgbe_get_vf_reta(adapter, msgbuf, vf);
break;
case IXGBE_VF_GET_RSS_KEY:
retval = ixgbe_get_vf_rss_key(adapter, msgbuf, vf);
break;
case IXGBE_VF_UPDATE_XCAST_MODE:
retval = ixgbe_update_vf_xcast_mode(adapter, msgbuf, vf);
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
ixgbe_write_mbx(hw, msgbuf, mbx_size, vf);
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
static inline void ixgbe_ping_vf(struct ixgbe_adapter *adapter, int vf)
{
struct ixgbe_hw *hw = &adapter->hw;
u32 ping;
ping = IXGBE_PF_CONTROL_MSG;
if (adapter->vfinfo[vf].clear_to_send)
ping |= IXGBE_VT_MSGTYPE_CTS;
ixgbe_write_mbx(hw, &ping, 1, vf);
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
static int ixgbe_enable_port_vlan(struct ixgbe_adapter *adapter, int vf,
u16 vlan, u8 qos)
{
struct ixgbe_hw *hw = &adapter->hw;
int err;
err = ixgbe_set_vf_vlan(adapter, true, vlan, vf);
if (err)
goto out;
ixgbe_set_vf_vlan(adapter, false, 0, vf);
ixgbe_set_vmvir(adapter, vlan, qos, vf);
ixgbe_set_vmolr(hw, vf, false);
if (hw->mac.type >= ixgbe_mac_X550)
ixgbe_write_qde(adapter, vf, IXGBE_QDE_ENABLE |
IXGBE_QDE_HIDE_VLAN);
adapter->vfinfo[vf].pf_vlan = vlan;
adapter->vfinfo[vf].pf_qos = qos;
dev_info(&adapter->pdev->dev,
"Setting VLAN %d, QOS 0x%x on VF %d\n", vlan, qos, vf);
if (test_bit(__IXGBE_DOWN, &adapter->state)) {
dev_warn(&adapter->pdev->dev,
"The VF VLAN has been set, but the PF device is not up.\n");
dev_warn(&adapter->pdev->dev,
"Bring the PF device up before attempting to use the VF device.\n");
}
out:
return err;
}
static int ixgbe_disable_port_vlan(struct ixgbe_adapter *adapter, int vf)
{
struct ixgbe_hw *hw = &adapter->hw;
int err;
err = ixgbe_set_vf_vlan(adapter, false,
adapter->vfinfo[vf].pf_vlan, vf);
ixgbe_set_vf_vlan(adapter, true, 0, vf);
ixgbe_clear_vmvir(adapter, vf);
ixgbe_set_vmolr(hw, vf, true);
if (hw->mac.type >= ixgbe_mac_X550)
ixgbe_write_qde(adapter, vf, IXGBE_QDE_ENABLE);
adapter->vfinfo[vf].pf_vlan = 0;
adapter->vfinfo[vf].pf_qos = 0;
return err;
}
int ixgbe_ndo_set_vf_vlan(struct net_device *netdev, int vf, u16 vlan, u8 qos)
{
int err = 0;
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if ((vf >= adapter->num_vfs) || (vlan > 4095) || (qos > 7))
return -EINVAL;
if (vlan || qos) {
if (adapter->vfinfo[vf].pf_vlan)
err = ixgbe_disable_port_vlan(adapter, vf);
if (err)
goto out;
err = ixgbe_enable_port_vlan(adapter, vf, vlan, qos);
} else {
err = ixgbe_disable_port_vlan(adapter, vf);
}
out:
return err;
}
int ixgbe_link_mbps(struct ixgbe_adapter *adapter)
{
switch (adapter->link_speed) {
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
static void ixgbe_set_vf_rate_limit(struct ixgbe_adapter *adapter, int vf)
{
struct ixgbe_ring_feature *vmdq = &adapter->ring_feature[RING_F_VMDQ];
struct ixgbe_hw *hw = &adapter->hw;
u32 bcnrc_val = 0;
u16 queue, queues_per_pool;
u16 tx_rate = adapter->vfinfo[vf].tx_rate;
if (tx_rate) {
bcnrc_val = adapter->vf_rate_link_speed;
bcnrc_val <<= IXGBE_RTTBCNRC_RF_INT_SHIFT;
bcnrc_val /= tx_rate;
bcnrc_val &= IXGBE_RTTBCNRC_RF_INT_MASK |
IXGBE_RTTBCNRC_RF_DEC_MASK;
bcnrc_val |= IXGBE_RTTBCNRC_RS_ENA;
}
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
queues_per_pool = __ALIGN_MASK(1, ~vmdq->mask);
for (queue = 0; queue < queues_per_pool; queue++) {
unsigned int reg_idx = (vf * queues_per_pool) + queue;
IXGBE_WRITE_REG(hw, IXGBE_RTTDQSEL, reg_idx);
IXGBE_WRITE_REG(hw, IXGBE_RTTBCNRC, bcnrc_val);
}
}
void ixgbe_check_vf_rate_limit(struct ixgbe_adapter *adapter)
{
int i;
if (!adapter->vf_rate_link_speed)
return;
if (ixgbe_link_mbps(adapter) != adapter->vf_rate_link_speed) {
adapter->vf_rate_link_speed = 0;
dev_info(&adapter->pdev->dev,
"Link speed has been changed. VF Transmit rate is disabled\n");
}
for (i = 0; i < adapter->num_vfs; i++) {
if (!adapter->vf_rate_link_speed)
adapter->vfinfo[i].tx_rate = 0;
ixgbe_set_vf_rate_limit(adapter, i);
}
}
int ixgbe_ndo_set_vf_bw(struct net_device *netdev, int vf, int min_tx_rate,
int max_tx_rate)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
int link_speed;
if (vf >= adapter->num_vfs)
return -EINVAL;
if (!adapter->link_up)
return -EINVAL;
link_speed = ixgbe_link_mbps(adapter);
if (link_speed != 10000)
return -EINVAL;
if (min_tx_rate)
return -EINVAL;
if (max_tx_rate && ((max_tx_rate <= 10) || (max_tx_rate > link_speed)))
return -EINVAL;
adapter->vf_rate_link_speed = link_speed;
adapter->vfinfo[vf].tx_rate = max_tx_rate;
ixgbe_set_vf_rate_limit(adapter, vf);
return 0;
}
int ixgbe_ndo_set_vf_spoofchk(struct net_device *netdev, int vf, bool setting)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
struct ixgbe_hw *hw = &adapter->hw;
if (vf >= adapter->num_vfs)
return -EINVAL;
adapter->vfinfo[vf].spoofchk_enabled = setting;
hw->mac.ops.set_mac_anti_spoofing(hw, setting, vf);
hw->mac.ops.set_vlan_anti_spoofing(hw, setting, vf);
if (hw->mac.ops.set_ethertype_anti_spoofing) {
IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_LLDP),
(IXGBE_ETQF_FILTER_EN |
IXGBE_ETQF_TX_ANTISPOOF |
IXGBE_ETH_P_LLDP));
IXGBE_WRITE_REG(hw, IXGBE_ETQF(IXGBE_ETQF_FILTER_FC),
(IXGBE_ETQF_FILTER_EN |
IXGBE_ETQF_TX_ANTISPOOF |
ETH_P_PAUSE));
hw->mac.ops.set_ethertype_anti_spoofing(hw, setting, vf);
}
return 0;
}
int ixgbe_ndo_set_vf_rss_query_en(struct net_device *netdev, int vf,
bool setting)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (adapter->hw.mac.type < ixgbe_mac_82599EB ||
adapter->hw.mac.type >= ixgbe_mac_X550)
return -EOPNOTSUPP;
if (vf >= adapter->num_vfs)
return -EINVAL;
adapter->vfinfo[vf].rss_query_enabled = setting;
return 0;
}
int ixgbe_ndo_set_vf_trust(struct net_device *netdev, int vf, bool setting)
{
struct ixgbe_adapter *adapter = netdev_priv(netdev);
if (vf >= adapter->num_vfs)
return -EINVAL;
if (adapter->vfinfo[vf].trusted == setting)
return 0;
adapter->vfinfo[vf].trusted = setting;
adapter->vfinfo[vf].clear_to_send = false;
ixgbe_ping_vf(adapter, vf);
e_info(drv, "VF %u is %strusted\n", vf, setting ? "" : "not ");
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
ivi->max_tx_rate = adapter->vfinfo[vf].tx_rate;
ivi->min_tx_rate = 0;
ivi->vlan = adapter->vfinfo[vf].pf_vlan;
ivi->qos = adapter->vfinfo[vf].pf_qos;
ivi->spoofchk = adapter->vfinfo[vf].spoofchk_enabled;
ivi->rss_query_en = adapter->vfinfo[vf].rss_query_enabled;
ivi->trusted = adapter->vfinfo[vf].trusted;
return 0;
}
