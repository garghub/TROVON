static int hwrm_cfa_vfr_alloc(struct bnxt *bp, u16 vf_idx,
u16 *tx_cfa_action, u16 *rx_cfa_code)
{
struct hwrm_cfa_vfr_alloc_output *resp = bp->hwrm_cmd_resp_addr;
struct hwrm_cfa_vfr_alloc_input req = { 0 };
int rc;
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_CFA_VFR_ALLOC, -1, -1);
req.vf_id = cpu_to_le16(vf_idx);
sprintf(req.vfr_name, "vfr%d", vf_idx);
mutex_lock(&bp->hwrm_cmd_lock);
rc = _hwrm_send_message(bp, &req, sizeof(req), HWRM_CMD_TIMEOUT);
if (!rc) {
*tx_cfa_action = le16_to_cpu(resp->tx_cfa_action);
*rx_cfa_code = le16_to_cpu(resp->rx_cfa_code);
netdev_dbg(bp->dev, "tx_cfa_action=0x%x, rx_cfa_code=0x%x",
*tx_cfa_action, *rx_cfa_code);
} else {
netdev_info(bp->dev, "%s error rc=%d", __func__, rc);
}
mutex_unlock(&bp->hwrm_cmd_lock);
return rc;
}
static int hwrm_cfa_vfr_free(struct bnxt *bp, u16 vf_idx)
{
struct hwrm_cfa_vfr_free_input req = { 0 };
int rc;
bnxt_hwrm_cmd_hdr_init(bp, &req, HWRM_CFA_VFR_FREE, -1, -1);
sprintf(req.vfr_name, "vfr%d", vf_idx);
rc = hwrm_send_message(bp, &req, sizeof(req), HWRM_CMD_TIMEOUT);
if (rc)
netdev_info(bp->dev, "%s error rc=%d", __func__, rc);
return rc;
}
static int bnxt_vf_rep_open(struct net_device *dev)
{
struct bnxt_vf_rep *vf_rep = netdev_priv(dev);
struct bnxt *bp = vf_rep->bp;
if (netif_running(bp->dev)) {
netif_carrier_on(dev);
netif_tx_start_all_queues(dev);
}
return 0;
}
static int bnxt_vf_rep_close(struct net_device *dev)
{
netif_carrier_off(dev);
netif_tx_disable(dev);
return 0;
}
static netdev_tx_t bnxt_vf_rep_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct bnxt_vf_rep *vf_rep = netdev_priv(dev);
int rc, len = skb->len;
skb_dst_drop(skb);
dst_hold((struct dst_entry *)vf_rep->dst);
skb_dst_set(skb, (struct dst_entry *)vf_rep->dst);
skb->dev = vf_rep->dst->u.port_info.lower_dev;
rc = dev_queue_xmit(skb);
if (!rc) {
vf_rep->tx_stats.packets++;
vf_rep->tx_stats.bytes += len;
}
return rc;
}
static void
bnxt_vf_rep_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct bnxt_vf_rep *vf_rep = netdev_priv(dev);
stats->rx_packets = vf_rep->rx_stats.packets;
stats->rx_bytes = vf_rep->rx_stats.bytes;
stats->tx_packets = vf_rep->tx_stats.packets;
stats->tx_bytes = vf_rep->tx_stats.bytes;
}
static int bnxt_vf_rep_setup_tc(struct net_device *dev, enum tc_setup_type type,
void *type_data)
{
struct bnxt_vf_rep *vf_rep = netdev_priv(dev);
struct bnxt *bp = vf_rep->bp;
int vf_fid = bp->pf.vf[vf_rep->vf_idx].fw_fid;
switch (type) {
case TC_SETUP_CLSFLOWER:
return bnxt_tc_setup_flower(bp, vf_fid, type_data);
default:
return -EOPNOTSUPP;
}
}
struct net_device *bnxt_get_vf_rep(struct bnxt *bp, u16 cfa_code)
{
u16 vf_idx;
if (cfa_code && bp->cfa_code_map && BNXT_PF(bp)) {
vf_idx = bp->cfa_code_map[cfa_code];
if (vf_idx != VF_IDX_INVALID)
return bp->vf_reps[vf_idx]->dev;
}
return NULL;
}
void bnxt_vf_rep_rx(struct bnxt *bp, struct sk_buff *skb)
{
struct bnxt_vf_rep *vf_rep = netdev_priv(skb->dev);
struct bnxt_vf_rep_stats *rx_stats;
rx_stats = &vf_rep->rx_stats;
vf_rep->rx_stats.bytes += skb->len;
vf_rep->rx_stats.packets++;
netif_receive_skb(skb);
}
static int bnxt_vf_rep_get_phys_port_name(struct net_device *dev, char *buf,
size_t len)
{
struct bnxt_vf_rep *vf_rep = netdev_priv(dev);
struct pci_dev *pf_pdev = vf_rep->bp->pdev;
int rc;
rc = snprintf(buf, len, "pf%dvf%d", PCI_FUNC(pf_pdev->devfn),
vf_rep->vf_idx);
if (rc >= len)
return -EOPNOTSUPP;
return 0;
}
static void bnxt_vf_rep_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_MODULE_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_MODULE_VERSION, sizeof(info->version));
}
static int bnxt_vf_rep_port_attr_get(struct net_device *dev,
struct switchdev_attr *attr)
{
struct bnxt_vf_rep *vf_rep = netdev_priv(dev);
return bnxt_port_attr_get(vf_rep->bp, attr);
}
void bnxt_vf_reps_close(struct bnxt *bp)
{
struct bnxt_vf_rep *vf_rep;
u16 num_vfs, i;
if (bp->eswitch_mode != DEVLINK_ESWITCH_MODE_SWITCHDEV)
return;
num_vfs = pci_num_vf(bp->pdev);
for (i = 0; i < num_vfs; i++) {
vf_rep = bp->vf_reps[i];
if (netif_running(vf_rep->dev))
bnxt_vf_rep_close(vf_rep->dev);
}
}
void bnxt_vf_reps_open(struct bnxt *bp)
{
int i;
if (bp->eswitch_mode != DEVLINK_ESWITCH_MODE_SWITCHDEV)
return;
for (i = 0; i < pci_num_vf(bp->pdev); i++)
bnxt_vf_rep_open(bp->vf_reps[i]->dev);
}
static void __bnxt_vf_reps_destroy(struct bnxt *bp)
{
u16 num_vfs = pci_num_vf(bp->pdev);
struct bnxt_vf_rep *vf_rep;
int i;
for (i = 0; i < num_vfs; i++) {
vf_rep = bp->vf_reps[i];
if (vf_rep) {
dst_release((struct dst_entry *)vf_rep->dst);
if (vf_rep->tx_cfa_action != CFA_HANDLE_INVALID)
hwrm_cfa_vfr_free(bp, vf_rep->vf_idx);
if (vf_rep->dev) {
if (vf_rep->dev->netdev_ops)
unregister_netdev(vf_rep->dev);
free_netdev(vf_rep->dev);
}
}
}
kfree(bp->vf_reps);
bp->vf_reps = NULL;
}
void bnxt_vf_reps_destroy(struct bnxt *bp)
{
bool closed = false;
if (bp->eswitch_mode != DEVLINK_ESWITCH_MODE_SWITCHDEV)
return;
if (!bp->vf_reps)
return;
rtnl_lock();
if (netif_running(bp->dev)) {
bnxt_close_nic(bp, false, false);
closed = true;
}
kfree(bp->cfa_code_map);
bp->cfa_code_map = NULL;
bp->eswitch_mode = DEVLINK_ESWITCH_MODE_LEGACY;
if (closed)
bnxt_open_nic(bp, false, false);
rtnl_unlock();
__bnxt_vf_reps_destroy(bp);
}
static void bnxt_vf_rep_eth_addr_gen(u8 *src_mac, u16 vf_idx, u8 *mac)
{
u32 addr;
ether_addr_copy(mac, src_mac);
addr = jhash(src_mac, ETH_ALEN, 0) + vf_idx;
mac[3] = (u8)(addr & 0xFF);
mac[4] = (u8)((addr >> 8) & 0xFF);
mac[5] = (u8)((addr >> 16) & 0xFF);
}
static void bnxt_vf_rep_netdev_init(struct bnxt *bp, struct bnxt_vf_rep *vf_rep,
struct net_device *dev)
{
struct net_device *pf_dev = bp->dev;
dev->netdev_ops = &bnxt_vf_rep_netdev_ops;
dev->ethtool_ops = &bnxt_vf_rep_ethtool_ops;
SWITCHDEV_SET_OPS(dev, &bnxt_vf_rep_switchdev_ops);
dev->hw_features = pf_dev->hw_features;
dev->gso_partial_features = pf_dev->gso_partial_features;
dev->vlan_features = pf_dev->vlan_features;
dev->hw_enc_features = pf_dev->hw_enc_features;
dev->features |= pf_dev->features;
bnxt_vf_rep_eth_addr_gen(bp->pf.mac_addr, vf_rep->vf_idx,
dev->perm_addr);
ether_addr_copy(dev->dev_addr, dev->perm_addr);
}
static int bnxt_vf_reps_create(struct bnxt *bp)
{
u16 *cfa_code_map = NULL, num_vfs = pci_num_vf(bp->pdev);
struct bnxt_vf_rep *vf_rep;
struct net_device *dev;
int rc, i;
bp->vf_reps = kcalloc(num_vfs, sizeof(vf_rep), GFP_KERNEL);
if (!bp->vf_reps)
return -ENOMEM;
cfa_code_map = kmalloc(sizeof(*bp->cfa_code_map) * MAX_CFA_CODE,
GFP_KERNEL);
if (!cfa_code_map) {
rc = -ENOMEM;
goto err;
}
for (i = 0; i < MAX_CFA_CODE; i++)
cfa_code_map[i] = VF_IDX_INVALID;
for (i = 0; i < num_vfs; i++) {
dev = alloc_etherdev(sizeof(*vf_rep));
if (!dev) {
rc = -ENOMEM;
goto err;
}
vf_rep = netdev_priv(dev);
bp->vf_reps[i] = vf_rep;
vf_rep->dev = dev;
vf_rep->bp = bp;
vf_rep->vf_idx = i;
vf_rep->tx_cfa_action = CFA_HANDLE_INVALID;
rc = hwrm_cfa_vfr_alloc(bp, vf_rep->vf_idx,
&vf_rep->tx_cfa_action,
&vf_rep->rx_cfa_code);
if (rc) {
rc = -ENOLINK;
goto err;
}
cfa_code_map[vf_rep->rx_cfa_code] = vf_rep->vf_idx;
vf_rep->dst = metadata_dst_alloc(0, METADATA_HW_PORT_MUX,
GFP_KERNEL);
if (!vf_rep->dst) {
rc = -ENOMEM;
goto err;
}
vf_rep->dst->u.port_info.port_id = vf_rep->tx_cfa_action;
vf_rep->dst->u.port_info.lower_dev = bp->dev;
bnxt_vf_rep_netdev_init(bp, vf_rep, dev);
rc = register_netdev(dev);
if (rc) {
dev->netdev_ops = NULL;
goto err;
}
}
bp->cfa_code_map = cfa_code_map;
bp->eswitch_mode = DEVLINK_ESWITCH_MODE_SWITCHDEV;
netif_keep_dst(bp->dev);
return 0;
err:
netdev_info(bp->dev, "%s error=%d", __func__, rc);
kfree(cfa_code_map);
__bnxt_vf_reps_destroy(bp);
return rc;
}
static int bnxt_dl_eswitch_mode_get(struct devlink *devlink, u16 *mode)
{
struct bnxt *bp = bnxt_get_bp_from_dl(devlink);
*mode = bp->eswitch_mode;
return 0;
}
static int bnxt_dl_eswitch_mode_set(struct devlink *devlink, u16 mode)
{
struct bnxt *bp = bnxt_get_bp_from_dl(devlink);
int rc = 0;
mutex_lock(&bp->sriov_lock);
if (bp->eswitch_mode == mode) {
netdev_info(bp->dev, "already in %s eswitch mode",
mode == DEVLINK_ESWITCH_MODE_LEGACY ?
"legacy" : "switchdev");
rc = -EINVAL;
goto done;
}
switch (mode) {
case DEVLINK_ESWITCH_MODE_LEGACY:
bnxt_vf_reps_destroy(bp);
break;
case DEVLINK_ESWITCH_MODE_SWITCHDEV:
if (pci_num_vf(bp->pdev) == 0) {
netdev_info(bp->dev,
"Enable VFs before setting switchdev mode");
rc = -EPERM;
goto done;
}
rc = bnxt_vf_reps_create(bp);
break;
default:
rc = -EINVAL;
goto done;
}
done:
mutex_unlock(&bp->sriov_lock);
return rc;
}
int bnxt_dl_register(struct bnxt *bp)
{
struct devlink *dl;
int rc;
if (!pci_find_ext_capability(bp->pdev, PCI_EXT_CAP_ID_SRIOV))
return 0;
if (bp->hwrm_spec_code < 0x10800) {
netdev_warn(bp->dev, "Firmware does not support SR-IOV E-Switch SWITCHDEV mode.\n");
return -ENOTSUPP;
}
dl = devlink_alloc(&bnxt_dl_ops, sizeof(struct bnxt_dl));
if (!dl) {
netdev_warn(bp->dev, "devlink_alloc failed");
return -ENOMEM;
}
bnxt_link_bp_to_dl(bp, dl);
bp->eswitch_mode = DEVLINK_ESWITCH_MODE_LEGACY;
rc = devlink_register(dl, &bp->pdev->dev);
if (rc) {
bnxt_link_bp_to_dl(bp, NULL);
devlink_free(dl);
netdev_warn(bp->dev, "devlink_register failed. rc=%d", rc);
return rc;
}
return 0;
}
void bnxt_dl_unregister(struct bnxt *bp)
{
struct devlink *dl = bp->dl;
if (!dl)
return;
devlink_unregister(dl);
devlink_free(dl);
}
