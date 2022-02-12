static void mlxsw_sp_txhdr_construct(struct sk_buff *skb,
const struct mlxsw_tx_info *tx_info)
{
char *txhdr = skb_push(skb, MLXSW_TXHDR_LEN);
memset(txhdr, 0, MLXSW_TXHDR_LEN);
mlxsw_tx_hdr_version_set(txhdr, MLXSW_TXHDR_VERSION_1);
mlxsw_tx_hdr_ctl_set(txhdr, MLXSW_TXHDR_ETH_CTL);
mlxsw_tx_hdr_proto_set(txhdr, MLXSW_TXHDR_PROTO_ETH);
mlxsw_tx_hdr_swid_set(txhdr, 0);
mlxsw_tx_hdr_control_tclass_set(txhdr, 1);
mlxsw_tx_hdr_port_mid_set(txhdr, tx_info->local_port);
mlxsw_tx_hdr_type_set(txhdr, MLXSW_TXHDR_TYPE_CONTROL);
}
static int mlxsw_sp_base_mac_get(struct mlxsw_sp *mlxsw_sp)
{
char spad_pl[MLXSW_REG_SPAD_LEN];
int err;
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(spad), spad_pl);
if (err)
return err;
mlxsw_reg_spad_base_mac_memcpy_from(spad_pl, mlxsw_sp->base_mac);
return 0;
}
static int mlxsw_sp_port_admin_status_set(struct mlxsw_sp_port *mlxsw_sp_port,
bool is_up)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char paos_pl[MLXSW_REG_PAOS_LEN];
mlxsw_reg_paos_pack(paos_pl, mlxsw_sp_port->local_port,
is_up ? MLXSW_PORT_ADMIN_STATUS_UP :
MLXSW_PORT_ADMIN_STATUS_DOWN);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(paos), paos_pl);
}
static int mlxsw_sp_port_oper_status_get(struct mlxsw_sp_port *mlxsw_sp_port,
bool *p_is_up)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char paos_pl[MLXSW_REG_PAOS_LEN];
u8 oper_status;
int err;
mlxsw_reg_paos_pack(paos_pl, mlxsw_sp_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(paos), paos_pl);
if (err)
return err;
oper_status = mlxsw_reg_paos_oper_status_get(paos_pl);
*p_is_up = oper_status == MLXSW_PORT_ADMIN_STATUS_UP ? true : false;
return 0;
}
static int mlxsw_sp_vfid_create(struct mlxsw_sp *mlxsw_sp, u16 vfid)
{
char sfmr_pl[MLXSW_REG_SFMR_LEN];
int err;
mlxsw_reg_sfmr_pack(sfmr_pl, MLXSW_REG_SFMR_OP_CREATE_FID,
MLXSW_SP_VFID_BASE + vfid, 0);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sfmr), sfmr_pl);
if (err)
return err;
set_bit(vfid, mlxsw_sp->active_vfids);
return 0;
}
static void mlxsw_sp_vfid_destroy(struct mlxsw_sp *mlxsw_sp, u16 vfid)
{
char sfmr_pl[MLXSW_REG_SFMR_LEN];
clear_bit(vfid, mlxsw_sp->active_vfids);
mlxsw_reg_sfmr_pack(sfmr_pl, MLXSW_REG_SFMR_OP_DESTROY_FID,
MLXSW_SP_VFID_BASE + vfid, 0);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sfmr), sfmr_pl);
}
static int mlxsw_sp_port_dev_addr_set(struct mlxsw_sp_port *mlxsw_sp_port,
unsigned char *addr)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char ppad_pl[MLXSW_REG_PPAD_LEN];
mlxsw_reg_ppad_pack(ppad_pl, true, mlxsw_sp_port->local_port);
mlxsw_reg_ppad_mac_memcpy_to(ppad_pl, addr);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ppad), ppad_pl);
}
static int mlxsw_sp_port_dev_addr_init(struct mlxsw_sp_port *mlxsw_sp_port)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
unsigned char *addr = mlxsw_sp_port->dev->dev_addr;
ether_addr_copy(addr, mlxsw_sp->base_mac);
addr[ETH_ALEN - 1] += mlxsw_sp_port->local_port;
return mlxsw_sp_port_dev_addr_set(mlxsw_sp_port, addr);
}
static int mlxsw_sp_port_stp_state_set(struct mlxsw_sp_port *mlxsw_sp_port,
u16 vid, enum mlxsw_reg_spms_state state)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char *spms_pl;
int err;
spms_pl = kmalloc(MLXSW_REG_SPMS_LEN, GFP_KERNEL);
if (!spms_pl)
return -ENOMEM;
mlxsw_reg_spms_pack(spms_pl, mlxsw_sp_port->local_port);
mlxsw_reg_spms_vid_pack(spms_pl, vid, state);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(spms), spms_pl);
kfree(spms_pl);
return err;
}
static int mlxsw_sp_port_mtu_set(struct mlxsw_sp_port *mlxsw_sp_port, u16 mtu)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char pmtu_pl[MLXSW_REG_PMTU_LEN];
int max_mtu;
int err;
mtu += MLXSW_TXHDR_LEN + ETH_HLEN;
mlxsw_reg_pmtu_pack(pmtu_pl, mlxsw_sp_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(pmtu), pmtu_pl);
if (err)
return err;
max_mtu = mlxsw_reg_pmtu_max_mtu_get(pmtu_pl);
if (mtu > max_mtu)
return -EINVAL;
mlxsw_reg_pmtu_pack(pmtu_pl, mlxsw_sp_port->local_port, mtu);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pmtu), pmtu_pl);
}
static int mlxsw_sp_port_swid_set(struct mlxsw_sp_port *mlxsw_sp_port, u8 swid)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char pspa_pl[MLXSW_REG_PSPA_LEN];
mlxsw_reg_pspa_pack(pspa_pl, swid, mlxsw_sp_port->local_port);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pspa), pspa_pl);
}
static int mlxsw_sp_port_vp_mode_set(struct mlxsw_sp_port *mlxsw_sp_port,
bool enable)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char svpe_pl[MLXSW_REG_SVPE_LEN];
mlxsw_reg_svpe_pack(svpe_pl, mlxsw_sp_port->local_port, enable);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(svpe), svpe_pl);
}
int mlxsw_sp_port_vid_to_fid_set(struct mlxsw_sp_port *mlxsw_sp_port,
enum mlxsw_reg_svfa_mt mt, bool valid, u16 fid,
u16 vid)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char svfa_pl[MLXSW_REG_SVFA_LEN];
mlxsw_reg_svfa_pack(svfa_pl, mlxsw_sp_port->local_port, mt, valid,
fid, vid);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(svfa), svfa_pl);
}
static int mlxsw_sp_port_vid_learning_set(struct mlxsw_sp_port *mlxsw_sp_port,
u16 vid, bool learn_enable)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char *spvmlr_pl;
int err;
spvmlr_pl = kmalloc(MLXSW_REG_SPVMLR_LEN, GFP_KERNEL);
if (!spvmlr_pl)
return -ENOMEM;
mlxsw_reg_spvmlr_pack(spvmlr_pl, mlxsw_sp_port->local_port, vid, vid,
learn_enable);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(spvmlr), spvmlr_pl);
kfree(spvmlr_pl);
return err;
}
static int
mlxsw_sp_port_system_port_mapping_set(struct mlxsw_sp_port *mlxsw_sp_port)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char sspr_pl[MLXSW_REG_SSPR_LEN];
mlxsw_reg_sspr_pack(sspr_pl, mlxsw_sp_port->local_port);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sspr), sspr_pl);
}
static int mlxsw_sp_port_module_check(struct mlxsw_sp_port *mlxsw_sp_port,
bool *p_usable)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char pmlp_pl[MLXSW_REG_PMLP_LEN];
int err;
mlxsw_reg_pmlp_pack(pmlp_pl, mlxsw_sp_port->local_port);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(pmlp), pmlp_pl);
if (err)
return err;
*p_usable = mlxsw_reg_pmlp_width_get(pmlp_pl) ? true : false;
return 0;
}
static int mlxsw_sp_port_open(struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
int err;
err = mlxsw_sp_port_admin_status_set(mlxsw_sp_port, true);
if (err)
return err;
netif_start_queue(dev);
return 0;
}
static int mlxsw_sp_port_stop(struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
netif_stop_queue(dev);
return mlxsw_sp_port_admin_status_set(mlxsw_sp_port, false);
}
static netdev_tx_t mlxsw_sp_port_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
struct mlxsw_sp_port_pcpu_stats *pcpu_stats;
const struct mlxsw_tx_info tx_info = {
.local_port = mlxsw_sp_port->local_port,
.is_emad = false,
};
u64 len;
int err;
if (mlxsw_core_skb_transmit_busy(mlxsw_sp, &tx_info))
return NETDEV_TX_BUSY;
if (unlikely(skb_headroom(skb) < MLXSW_TXHDR_LEN)) {
struct sk_buff *skb_orig = skb;
skb = skb_realloc_headroom(skb, MLXSW_TXHDR_LEN);
if (!skb) {
this_cpu_inc(mlxsw_sp_port->pcpu_stats->tx_dropped);
dev_kfree_skb_any(skb_orig);
return NETDEV_TX_OK;
}
}
if (eth_skb_pad(skb)) {
this_cpu_inc(mlxsw_sp_port->pcpu_stats->tx_dropped);
return NETDEV_TX_OK;
}
mlxsw_sp_txhdr_construct(skb, &tx_info);
len = skb->len;
err = mlxsw_core_skb_transmit(mlxsw_sp, skb, &tx_info);
if (!err) {
pcpu_stats = this_cpu_ptr(mlxsw_sp_port->pcpu_stats);
u64_stats_update_begin(&pcpu_stats->syncp);
pcpu_stats->tx_packets++;
pcpu_stats->tx_bytes += len;
u64_stats_update_end(&pcpu_stats->syncp);
} else {
this_cpu_inc(mlxsw_sp_port->pcpu_stats->tx_dropped);
dev_kfree_skb_any(skb);
}
return NETDEV_TX_OK;
}
static int mlxsw_sp_port_set_mac_address(struct net_device *dev, void *p)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct sockaddr *addr = p;
int err;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
err = mlxsw_sp_port_dev_addr_set(mlxsw_sp_port, addr->sa_data);
if (err)
return err;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
return 0;
}
static int mlxsw_sp_port_change_mtu(struct net_device *dev, int mtu)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
int err;
err = mlxsw_sp_port_mtu_set(mlxsw_sp_port, mtu);
if (err)
return err;
dev->mtu = mtu;
return 0;
}
static struct rtnl_link_stats64 *
mlxsw_sp_port_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp_port_pcpu_stats *p;
u64 rx_packets, rx_bytes, tx_packets, tx_bytes;
u32 tx_dropped = 0;
unsigned int start;
int i;
for_each_possible_cpu(i) {
p = per_cpu_ptr(mlxsw_sp_port->pcpu_stats, i);
do {
start = u64_stats_fetch_begin_irq(&p->syncp);
rx_packets = p->rx_packets;
rx_bytes = p->rx_bytes;
tx_packets = p->tx_packets;
tx_bytes = p->tx_bytes;
} while (u64_stats_fetch_retry_irq(&p->syncp, start));
stats->rx_packets += rx_packets;
stats->rx_bytes += rx_bytes;
stats->tx_packets += tx_packets;
stats->tx_bytes += tx_bytes;
tx_dropped += p->tx_dropped;
}
stats->tx_dropped = tx_dropped;
return stats;
}
int mlxsw_sp_port_vlan_set(struct mlxsw_sp_port *mlxsw_sp_port, u16 vid_begin,
u16 vid_end, bool is_member, bool untagged)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char *spvm_pl;
int err;
spvm_pl = kmalloc(MLXSW_REG_SPVM_LEN, GFP_KERNEL);
if (!spvm_pl)
return -ENOMEM;
mlxsw_reg_spvm_pack(spvm_pl, mlxsw_sp_port->local_port, vid_begin,
vid_end, is_member, untagged);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(spvm), spvm_pl);
kfree(spvm_pl);
return err;
}
static int mlxsw_sp_port_vp_mode_trans(struct mlxsw_sp_port *mlxsw_sp_port)
{
enum mlxsw_reg_svfa_mt mt = MLXSW_REG_SVFA_MT_PORT_VID_TO_FID;
u16 vid, last_visited_vid;
int err;
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
err = mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port, mt, true, vid,
vid);
if (err) {
last_visited_vid = vid;
goto err_port_vid_to_fid_set;
}
}
err = mlxsw_sp_port_vp_mode_set(mlxsw_sp_port, true);
if (err) {
last_visited_vid = VLAN_N_VID;
goto err_port_vid_to_fid_set;
}
return 0;
err_port_vid_to_fid_set:
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, last_visited_vid)
mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port, mt, false, vid,
vid);
return err;
}
static int mlxsw_sp_port_vlan_mode_trans(struct mlxsw_sp_port *mlxsw_sp_port)
{
enum mlxsw_reg_svfa_mt mt = MLXSW_REG_SVFA_MT_PORT_VID_TO_FID;
u16 vid;
int err;
err = mlxsw_sp_port_vp_mode_set(mlxsw_sp_port, false);
if (err)
return err;
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
err = mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port, mt, false,
vid, vid);
if (err)
return err;
}
return 0;
}
int mlxsw_sp_port_add_vid(struct net_device *dev, __be16 __always_unused proto,
u16 vid)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char *sftr_pl;
int err;
if (!vid)
return 0;
if (test_bit(vid, mlxsw_sp_port->active_vfids)) {
netdev_warn(dev, "VID=%d already configured\n", vid);
return 0;
}
if (!test_bit(vid, mlxsw_sp->active_vfids)) {
err = mlxsw_sp_vfid_create(mlxsw_sp, vid);
if (err) {
netdev_err(dev, "Failed to create vFID=%d\n",
MLXSW_SP_VFID_BASE + vid);
return err;
}
sftr_pl = kmalloc(MLXSW_REG_SFTR_LEN, GFP_KERNEL);
if (!sftr_pl) {
err = -ENOMEM;
goto err_flood_table_alloc;
}
mlxsw_reg_sftr_pack(sftr_pl, 0, vid,
MLXSW_REG_SFGC_TABLE_TYPE_FID, 0,
MLXSW_PORT_CPU_PORT, true);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sftr), sftr_pl);
kfree(sftr_pl);
if (err) {
netdev_err(dev, "Failed to configure flood table\n");
goto err_flood_table_config;
}
}
if (!mlxsw_sp_port->nr_vfids) {
err = mlxsw_sp_port_vp_mode_trans(mlxsw_sp_port);
if (err) {
netdev_err(dev, "Failed to set to Virtual mode\n");
return err;
}
}
err = mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port,
MLXSW_REG_SVFA_MT_PORT_VID_TO_FID,
true, MLXSW_SP_VFID_BASE + vid, vid);
if (err) {
netdev_err(dev, "Failed to map {Port, VID=%d} to vFID=%d\n",
vid, MLXSW_SP_VFID_BASE + vid);
goto err_port_vid_to_fid_set;
}
err = mlxsw_sp_port_vid_learning_set(mlxsw_sp_port, vid, false);
if (err) {
netdev_err(dev, "Failed to disable learning for VID=%d\n", vid);
goto err_port_vid_learning_set;
}
err = mlxsw_sp_port_vlan_set(mlxsw_sp_port, vid, vid, true, false);
if (err) {
netdev_err(dev, "Failed to set VLAN membership for VID=%d\n",
vid);
goto err_port_add_vid;
}
err = mlxsw_sp_port_stp_state_set(mlxsw_sp_port, vid,
MLXSW_REG_SPMS_STATE_FORWARDING);
if (err) {
netdev_err(dev, "Failed to set STP state for VID=%d\n", vid);
goto err_port_stp_state_set;
}
mlxsw_sp_port->nr_vfids++;
set_bit(vid, mlxsw_sp_port->active_vfids);
return 0;
err_flood_table_config:
err_flood_table_alloc:
mlxsw_sp_vfid_destroy(mlxsw_sp, vid);
return err;
err_port_stp_state_set:
mlxsw_sp_port_vlan_set(mlxsw_sp_port, vid, vid, false, false);
err_port_add_vid:
mlxsw_sp_port_vid_learning_set(mlxsw_sp_port, vid, true);
err_port_vid_learning_set:
mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port,
MLXSW_REG_SVFA_MT_PORT_VID_TO_FID, false,
MLXSW_SP_VFID_BASE + vid, vid);
err_port_vid_to_fid_set:
mlxsw_sp_port_vlan_mode_trans(mlxsw_sp_port);
return err;
}
int mlxsw_sp_port_kill_vid(struct net_device *dev,
__be16 __always_unused proto, u16 vid)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
int err;
if (!vid)
return 0;
if (!test_bit(vid, mlxsw_sp_port->active_vfids)) {
netdev_warn(dev, "VID=%d does not exist\n", vid);
return 0;
}
err = mlxsw_sp_port_stp_state_set(mlxsw_sp_port, vid,
MLXSW_REG_SPMS_STATE_DISCARDING);
if (err) {
netdev_err(dev, "Failed to set STP state for VID=%d\n", vid);
return err;
}
err = mlxsw_sp_port_vlan_set(mlxsw_sp_port, vid, vid, false, false);
if (err) {
netdev_err(dev, "Failed to set VLAN membership for VID=%d\n",
vid);
return err;
}
err = mlxsw_sp_port_vid_learning_set(mlxsw_sp_port, vid, true);
if (err) {
netdev_err(dev, "Failed to enable learning for VID=%d\n", vid);
return err;
}
err = mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port,
MLXSW_REG_SVFA_MT_PORT_VID_TO_FID,
false, MLXSW_SP_VFID_BASE + vid,
vid);
if (err) {
netdev_err(dev, "Failed to invalidate {Port, VID=%d} to vFID=%d mapping\n",
vid, MLXSW_SP_VFID_BASE + vid);
return err;
}
if (mlxsw_sp_port->nr_vfids == 1) {
err = mlxsw_sp_port_vlan_mode_trans(mlxsw_sp_port);
if (err) {
netdev_err(dev, "Failed to set to VLAN mode\n");
return err;
}
}
mlxsw_sp_port->nr_vfids--;
clear_bit(vid, mlxsw_sp_port->active_vfids);
return 0;
}
static void mlxsw_sp_port_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *drvinfo)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
strlcpy(drvinfo->driver, mlxsw_sp_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, mlxsw_sp_driver_version,
sizeof(drvinfo->version));
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
"%d.%d.%d",
mlxsw_sp->bus_info->fw_rev.major,
mlxsw_sp->bus_info->fw_rev.minor,
mlxsw_sp->bus_info->fw_rev.subminor);
strlcpy(drvinfo->bus_info, mlxsw_sp->bus_info->device_name,
sizeof(drvinfo->bus_info));
}
static void mlxsw_sp_port_get_strings(struct net_device *dev,
u32 stringset, u8 *data)
{
u8 *p = data;
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < MLXSW_SP_PORT_HW_STATS_LEN; i++) {
memcpy(p, mlxsw_sp_port_hw_stats[i].str,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
break;
}
}
static void mlxsw_sp_port_get_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char ppcnt_pl[MLXSW_REG_PPCNT_LEN];
int i;
int err;
mlxsw_reg_ppcnt_pack(ppcnt_pl, mlxsw_sp_port->local_port);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(ppcnt), ppcnt_pl);
for (i = 0; i < MLXSW_SP_PORT_HW_STATS_LEN; i++)
data[i] = !err ? mlxsw_sp_port_hw_stats[i].getter(ppcnt_pl) : 0;
}
static int mlxsw_sp_port_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return MLXSW_SP_PORT_HW_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static u32 mlxsw_sp_from_ptys_supported_port(u32 ptys_eth_proto)
{
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_CR |
MLXSW_REG_PTYS_ETH_SPEED_10GBASE_SR |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_CR4 |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_SR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_SR4 |
MLXSW_REG_PTYS_ETH_SPEED_SGMII))
return SUPPORTED_FIBRE;
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KR |
MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KX4 |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_KR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_KR4 |
MLXSW_REG_PTYS_ETH_SPEED_1000BASE_KX))
return SUPPORTED_Backplane;
return 0;
}
static u32 mlxsw_sp_from_ptys_supported_link(u32 ptys_eth_proto)
{
u32 modes = 0;
int i;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (ptys_eth_proto & mlxsw_sp_port_link_mode[i].mask)
modes |= mlxsw_sp_port_link_mode[i].supported;
}
return modes;
}
static u32 mlxsw_sp_from_ptys_advert_link(u32 ptys_eth_proto)
{
u32 modes = 0;
int i;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (ptys_eth_proto & mlxsw_sp_port_link_mode[i].mask)
modes |= mlxsw_sp_port_link_mode[i].advertised;
}
return modes;
}
static void mlxsw_sp_from_ptys_speed_duplex(bool carrier_ok, u32 ptys_eth_proto,
struct ethtool_cmd *cmd)
{
u32 speed = SPEED_UNKNOWN;
u8 duplex = DUPLEX_UNKNOWN;
int i;
if (!carrier_ok)
goto out;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (ptys_eth_proto & mlxsw_sp_port_link_mode[i].mask) {
speed = mlxsw_sp_port_link_mode[i].speed;
duplex = DUPLEX_FULL;
break;
}
}
out:
ethtool_cmd_speed_set(cmd, speed);
cmd->duplex = duplex;
}
static u8 mlxsw_sp_port_connector_port(u32 ptys_eth_proto)
{
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_SR |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_SR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_SR4 |
MLXSW_REG_PTYS_ETH_SPEED_SGMII))
return PORT_FIBRE;
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_CR |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_CR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_CR4))
return PORT_DA;
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KR |
MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KX4 |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_KR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_KR4))
return PORT_NONE;
return PORT_OTHER;
}
static int mlxsw_sp_port_get_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char ptys_pl[MLXSW_REG_PTYS_LEN];
u32 eth_proto_cap;
u32 eth_proto_admin;
u32 eth_proto_oper;
int err;
mlxsw_reg_ptys_pack(ptys_pl, mlxsw_sp_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(ptys), ptys_pl);
if (err) {
netdev_err(dev, "Failed to get proto");
return err;
}
mlxsw_reg_ptys_unpack(ptys_pl, &eth_proto_cap,
&eth_proto_admin, &eth_proto_oper);
cmd->supported = mlxsw_sp_from_ptys_supported_port(eth_proto_cap) |
mlxsw_sp_from_ptys_supported_link(eth_proto_cap) |
SUPPORTED_Pause | SUPPORTED_Asym_Pause;
cmd->advertising = mlxsw_sp_from_ptys_advert_link(eth_proto_admin);
mlxsw_sp_from_ptys_speed_duplex(netif_carrier_ok(dev),
eth_proto_oper, cmd);
eth_proto_oper = eth_proto_oper ? eth_proto_oper : eth_proto_cap;
cmd->port = mlxsw_sp_port_connector_port(eth_proto_oper);
cmd->lp_advertising = mlxsw_sp_from_ptys_advert_link(eth_proto_oper);
cmd->transceiver = XCVR_INTERNAL;
return 0;
}
static u32 mlxsw_sp_to_ptys_advert_link(u32 advertising)
{
u32 ptys_proto = 0;
int i;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (advertising & mlxsw_sp_port_link_mode[i].advertised)
ptys_proto |= mlxsw_sp_port_link_mode[i].mask;
}
return ptys_proto;
}
static u32 mlxsw_sp_to_ptys_speed(u32 speed)
{
u32 ptys_proto = 0;
int i;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (speed == mlxsw_sp_port_link_mode[i].speed)
ptys_proto |= mlxsw_sp_port_link_mode[i].mask;
}
return ptys_proto;
}
static int mlxsw_sp_port_set_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char ptys_pl[MLXSW_REG_PTYS_LEN];
u32 speed;
u32 eth_proto_new;
u32 eth_proto_cap;
u32 eth_proto_admin;
bool is_up;
int err;
speed = ethtool_cmd_speed(cmd);
eth_proto_new = cmd->autoneg == AUTONEG_ENABLE ?
mlxsw_sp_to_ptys_advert_link(cmd->advertising) :
mlxsw_sp_to_ptys_speed(speed);
mlxsw_reg_ptys_pack(ptys_pl, mlxsw_sp_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(ptys), ptys_pl);
if (err) {
netdev_err(dev, "Failed to get proto");
return err;
}
mlxsw_reg_ptys_unpack(ptys_pl, &eth_proto_cap, &eth_proto_admin, NULL);
eth_proto_new = eth_proto_new & eth_proto_cap;
if (!eth_proto_new) {
netdev_err(dev, "Not supported proto admin requested");
return -EINVAL;
}
if (eth_proto_new == eth_proto_admin)
return 0;
mlxsw_reg_ptys_pack(ptys_pl, mlxsw_sp_port->local_port, eth_proto_new);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ptys), ptys_pl);
if (err) {
netdev_err(dev, "Failed to set proto admin");
return err;
}
err = mlxsw_sp_port_oper_status_get(mlxsw_sp_port, &is_up);
if (err) {
netdev_err(dev, "Failed to get oper status");
return err;
}
if (!is_up)
return 0;
err = mlxsw_sp_port_admin_status_set(mlxsw_sp_port, false);
if (err) {
netdev_err(dev, "Failed to set admin status");
return err;
}
err = mlxsw_sp_port_admin_status_set(mlxsw_sp_port, true);
if (err) {
netdev_err(dev, "Failed to set admin status");
return err;
}
return 0;
}
static int mlxsw_sp_port_create(struct mlxsw_sp *mlxsw_sp, u8 local_port)
{
struct mlxsw_sp_port *mlxsw_sp_port;
struct net_device *dev;
bool usable;
int err;
dev = alloc_etherdev(sizeof(struct mlxsw_sp_port));
if (!dev)
return -ENOMEM;
mlxsw_sp_port = netdev_priv(dev);
mlxsw_sp_port->dev = dev;
mlxsw_sp_port->mlxsw_sp = mlxsw_sp;
mlxsw_sp_port->local_port = local_port;
mlxsw_sp_port->learning = 1;
mlxsw_sp_port->learning_sync = 1;
mlxsw_sp_port->uc_flood = 1;
mlxsw_sp_port->pvid = 1;
mlxsw_sp_port->pcpu_stats =
netdev_alloc_pcpu_stats(struct mlxsw_sp_port_pcpu_stats);
if (!mlxsw_sp_port->pcpu_stats) {
err = -ENOMEM;
goto err_alloc_stats;
}
dev->netdev_ops = &mlxsw_sp_port_netdev_ops;
dev->ethtool_ops = &mlxsw_sp_port_ethtool_ops;
err = mlxsw_sp_port_dev_addr_init(mlxsw_sp_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Unable to init port mac address\n",
mlxsw_sp_port->local_port);
goto err_dev_addr_init;
}
netif_carrier_off(dev);
dev->features |= NETIF_F_NETNS_LOCAL | NETIF_F_LLTX | NETIF_F_SG |
NETIF_F_HW_VLAN_CTAG_FILTER;
dev->hard_header_len += MLXSW_TXHDR_LEN;
err = mlxsw_sp_port_module_check(mlxsw_sp_port, &usable);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to check module\n",
mlxsw_sp_port->local_port);
goto err_port_module_check;
}
if (!usable) {
dev_dbg(mlxsw_sp->bus_info->dev, "Port %d: Not usable, skipping initialization\n",
mlxsw_sp_port->local_port);
goto port_not_usable;
}
err = mlxsw_sp_port_system_port_mapping_set(mlxsw_sp_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to set system port mapping\n",
mlxsw_sp_port->local_port);
goto err_port_system_port_mapping_set;
}
err = mlxsw_sp_port_swid_set(mlxsw_sp_port, 0);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to set SWID\n",
mlxsw_sp_port->local_port);
goto err_port_swid_set;
}
err = mlxsw_sp_port_mtu_set(mlxsw_sp_port, ETH_DATA_LEN);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to set MTU\n",
mlxsw_sp_port->local_port);
goto err_port_mtu_set;
}
err = mlxsw_sp_port_admin_status_set(mlxsw_sp_port, false);
if (err)
goto err_port_admin_status_set;
err = mlxsw_sp_port_buffers_init(mlxsw_sp_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to initialize buffers\n",
mlxsw_sp_port->local_port);
goto err_port_buffers_init;
}
mlxsw_sp_port_switchdev_init(mlxsw_sp_port);
err = register_netdev(dev);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to register netdev\n",
mlxsw_sp_port->local_port);
goto err_register_netdev;
}
err = mlxsw_sp_port_vlan_init(mlxsw_sp_port);
if (err)
goto err_port_vlan_init;
mlxsw_sp->ports[local_port] = mlxsw_sp_port;
return 0;
err_port_vlan_init:
unregister_netdev(dev);
err_register_netdev:
err_port_buffers_init:
err_port_admin_status_set:
err_port_mtu_set:
err_port_swid_set:
err_port_system_port_mapping_set:
port_not_usable:
err_port_module_check:
err_dev_addr_init:
free_percpu(mlxsw_sp_port->pcpu_stats);
err_alloc_stats:
free_netdev(dev);
return err;
}
static void mlxsw_sp_vfids_fini(struct mlxsw_sp *mlxsw_sp)
{
u16 vfid;
for_each_set_bit(vfid, mlxsw_sp->active_vfids, VLAN_N_VID)
mlxsw_sp_vfid_destroy(mlxsw_sp, vfid);
}
static void mlxsw_sp_port_remove(struct mlxsw_sp *mlxsw_sp, u8 local_port)
{
struct mlxsw_sp_port *mlxsw_sp_port = mlxsw_sp->ports[local_port];
if (!mlxsw_sp_port)
return;
mlxsw_sp_port_kill_vid(mlxsw_sp_port->dev, 0, 1);
unregister_netdev(mlxsw_sp_port->dev);
mlxsw_sp_port_switchdev_fini(mlxsw_sp_port);
free_percpu(mlxsw_sp_port->pcpu_stats);
free_netdev(mlxsw_sp_port->dev);
}
static void mlxsw_sp_ports_remove(struct mlxsw_sp *mlxsw_sp)
{
int i;
for (i = 1; i < MLXSW_PORT_MAX_PORTS; i++)
mlxsw_sp_port_remove(mlxsw_sp, i);
kfree(mlxsw_sp->ports);
}
static int mlxsw_sp_ports_create(struct mlxsw_sp *mlxsw_sp)
{
size_t alloc_size;
int i;
int err;
alloc_size = sizeof(struct mlxsw_sp_port *) * MLXSW_PORT_MAX_PORTS;
mlxsw_sp->ports = kzalloc(alloc_size, GFP_KERNEL);
if (!mlxsw_sp->ports)
return -ENOMEM;
for (i = 1; i < MLXSW_PORT_MAX_PORTS; i++) {
err = mlxsw_sp_port_create(mlxsw_sp, i);
if (err)
goto err_port_create;
}
return 0;
err_port_create:
for (i--; i >= 1; i--)
mlxsw_sp_port_remove(mlxsw_sp, i);
kfree(mlxsw_sp->ports);
return err;
}
static void mlxsw_sp_pude_event_func(const struct mlxsw_reg_info *reg,
char *pude_pl, void *priv)
{
struct mlxsw_sp *mlxsw_sp = priv;
struct mlxsw_sp_port *mlxsw_sp_port;
enum mlxsw_reg_pude_oper_status status;
u8 local_port;
local_port = mlxsw_reg_pude_local_port_get(pude_pl);
mlxsw_sp_port = mlxsw_sp->ports[local_port];
if (!mlxsw_sp_port) {
dev_warn(mlxsw_sp->bus_info->dev, "Port %d: Link event received for non-existent port\n",
local_port);
return;
}
status = mlxsw_reg_pude_oper_status_get(pude_pl);
if (status == MLXSW_PORT_OPER_STATUS_UP) {
netdev_info(mlxsw_sp_port->dev, "link up\n");
netif_carrier_on(mlxsw_sp_port->dev);
} else {
netdev_info(mlxsw_sp_port->dev, "link down\n");
netif_carrier_off(mlxsw_sp_port->dev);
}
}
static int mlxsw_sp_event_register(struct mlxsw_sp *mlxsw_sp,
enum mlxsw_event_trap_id trap_id)
{
struct mlxsw_event_listener *el;
char hpkt_pl[MLXSW_REG_HPKT_LEN];
int err;
switch (trap_id) {
case MLXSW_TRAP_ID_PUDE:
el = &mlxsw_sp_pude_event;
break;
}
err = mlxsw_core_event_listener_register(mlxsw_sp->core, el, mlxsw_sp);
if (err)
return err;
mlxsw_reg_hpkt_pack(hpkt_pl, MLXSW_REG_HPKT_ACTION_FORWARD, trap_id);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(hpkt), hpkt_pl);
if (err)
goto err_event_trap_set;
return 0;
err_event_trap_set:
mlxsw_core_event_listener_unregister(mlxsw_sp->core, el, mlxsw_sp);
return err;
}
static void mlxsw_sp_event_unregister(struct mlxsw_sp *mlxsw_sp,
enum mlxsw_event_trap_id trap_id)
{
struct mlxsw_event_listener *el;
switch (trap_id) {
case MLXSW_TRAP_ID_PUDE:
el = &mlxsw_sp_pude_event;
break;
}
mlxsw_core_event_listener_unregister(mlxsw_sp->core, el, mlxsw_sp);
}
static void mlxsw_sp_rx_listener_func(struct sk_buff *skb, u8 local_port,
void *priv)
{
struct mlxsw_sp *mlxsw_sp = priv;
struct mlxsw_sp_port *mlxsw_sp_port = mlxsw_sp->ports[local_port];
struct mlxsw_sp_port_pcpu_stats *pcpu_stats;
if (unlikely(!mlxsw_sp_port)) {
dev_warn_ratelimited(mlxsw_sp->bus_info->dev, "Port %d: skb received for non-existent port\n",
local_port);
return;
}
skb->dev = mlxsw_sp_port->dev;
pcpu_stats = this_cpu_ptr(mlxsw_sp_port->pcpu_stats);
u64_stats_update_begin(&pcpu_stats->syncp);
pcpu_stats->rx_packets++;
pcpu_stats->rx_bytes += skb->len;
u64_stats_update_end(&pcpu_stats->syncp);
skb->protocol = eth_type_trans(skb, skb->dev);
netif_receive_skb(skb);
}
static int mlxsw_sp_traps_init(struct mlxsw_sp *mlxsw_sp)
{
char htgt_pl[MLXSW_REG_HTGT_LEN];
char hpkt_pl[MLXSW_REG_HPKT_LEN];
int i;
int err;
mlxsw_reg_htgt_pack(htgt_pl, MLXSW_REG_HTGT_TRAP_GROUP_RX);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(htgt), htgt_pl);
if (err)
return err;
mlxsw_reg_htgt_pack(htgt_pl, MLXSW_REG_HTGT_TRAP_GROUP_CTRL);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(htgt), htgt_pl);
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(mlxsw_sp_rx_listener); i++) {
err = mlxsw_core_rx_listener_register(mlxsw_sp->core,
&mlxsw_sp_rx_listener[i],
mlxsw_sp);
if (err)
goto err_rx_listener_register;
mlxsw_reg_hpkt_pack(hpkt_pl, MLXSW_REG_HPKT_ACTION_TRAP_TO_CPU,
mlxsw_sp_rx_listener[i].trap_id);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(hpkt), hpkt_pl);
if (err)
goto err_rx_trap_set;
}
return 0;
err_rx_trap_set:
mlxsw_core_rx_listener_unregister(mlxsw_sp->core,
&mlxsw_sp_rx_listener[i],
mlxsw_sp);
err_rx_listener_register:
for (i--; i >= 0; i--) {
mlxsw_reg_hpkt_pack(hpkt_pl, MLXSW_REG_HPKT_ACTION_FORWARD,
mlxsw_sp_rx_listener[i].trap_id);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(hpkt), hpkt_pl);
mlxsw_core_rx_listener_unregister(mlxsw_sp->core,
&mlxsw_sp_rx_listener[i],
mlxsw_sp);
}
return err;
}
static void mlxsw_sp_traps_fini(struct mlxsw_sp *mlxsw_sp)
{
char hpkt_pl[MLXSW_REG_HPKT_LEN];
int i;
for (i = 0; i < ARRAY_SIZE(mlxsw_sp_rx_listener); i++) {
mlxsw_reg_hpkt_pack(hpkt_pl, MLXSW_REG_HPKT_ACTION_FORWARD,
mlxsw_sp_rx_listener[i].trap_id);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(hpkt), hpkt_pl);
mlxsw_core_rx_listener_unregister(mlxsw_sp->core,
&mlxsw_sp_rx_listener[i],
mlxsw_sp);
}
}
static int __mlxsw_sp_flood_init(struct mlxsw_core *mlxsw_core,
enum mlxsw_reg_sfgc_type type,
enum mlxsw_reg_sfgc_bridge_type bridge_type)
{
enum mlxsw_flood_table_type table_type;
enum mlxsw_sp_flood_table flood_table;
char sfgc_pl[MLXSW_REG_SFGC_LEN];
if (bridge_type == MLXSW_REG_SFGC_BRIDGE_TYPE_VFID) {
table_type = MLXSW_REG_SFGC_TABLE_TYPE_FID;
flood_table = 0;
} else {
table_type = MLXSW_REG_SFGC_TABLE_TYPE_FID_OFFEST;
if (type == MLXSW_REG_SFGC_TYPE_UNKNOWN_UNICAST)
flood_table = MLXSW_SP_FLOOD_TABLE_UC;
else
flood_table = MLXSW_SP_FLOOD_TABLE_BM;
}
mlxsw_reg_sfgc_pack(sfgc_pl, type, bridge_type, table_type,
flood_table);
return mlxsw_reg_write(mlxsw_core, MLXSW_REG(sfgc), sfgc_pl);
}
static int mlxsw_sp_flood_init(struct mlxsw_sp *mlxsw_sp)
{
int type, err;
for (type = 0; type < MLXSW_REG_SFGC_TYPE_MAX; type++) {
if (type == MLXSW_REG_SFGC_TYPE_RESERVED)
continue;
err = __mlxsw_sp_flood_init(mlxsw_sp->core, type,
MLXSW_REG_SFGC_BRIDGE_TYPE_VFID);
if (err)
return err;
}
for (type = 0; type < MLXSW_REG_SFGC_TYPE_MAX; type++) {
if (type == MLXSW_REG_SFGC_TYPE_RESERVED)
continue;
err = __mlxsw_sp_flood_init(mlxsw_sp->core, type,
MLXSW_REG_SFGC_BRIDGE_TYPE_1Q_FID);
if (err)
return err;
}
return 0;
}
static int mlxsw_sp_init(void *priv, struct mlxsw_core *mlxsw_core,
const struct mlxsw_bus_info *mlxsw_bus_info)
{
struct mlxsw_sp *mlxsw_sp = priv;
int err;
mlxsw_sp->core = mlxsw_core;
mlxsw_sp->bus_info = mlxsw_bus_info;
err = mlxsw_sp_base_mac_get(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to get base mac\n");
return err;
}
err = mlxsw_sp_ports_create(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to create ports\n");
goto err_ports_create;
}
err = mlxsw_sp_event_register(mlxsw_sp, MLXSW_TRAP_ID_PUDE);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to register for PUDE events\n");
goto err_event_register;
}
err = mlxsw_sp_traps_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to set traps for RX\n");
goto err_rx_listener_register;
}
err = mlxsw_sp_flood_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to initialize flood tables\n");
goto err_flood_init;
}
err = mlxsw_sp_buffers_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to initialize buffers\n");
goto err_buffers_init;
}
err = mlxsw_sp_switchdev_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to initialize switchdev\n");
goto err_switchdev_init;
}
return 0;
err_switchdev_init:
err_buffers_init:
err_flood_init:
mlxsw_sp_traps_fini(mlxsw_sp);
err_rx_listener_register:
mlxsw_sp_event_unregister(mlxsw_sp, MLXSW_TRAP_ID_PUDE);
err_event_register:
mlxsw_sp_ports_remove(mlxsw_sp);
err_ports_create:
mlxsw_sp_vfids_fini(mlxsw_sp);
return err;
}
static void mlxsw_sp_fini(void *priv)
{
struct mlxsw_sp *mlxsw_sp = priv;
mlxsw_sp_switchdev_fini(mlxsw_sp);
mlxsw_sp_traps_fini(mlxsw_sp);
mlxsw_sp_event_unregister(mlxsw_sp, MLXSW_TRAP_ID_PUDE);
mlxsw_sp_ports_remove(mlxsw_sp);
mlxsw_sp_vfids_fini(mlxsw_sp);
}
static bool mlxsw_sp_port_dev_check(const struct net_device *dev)
{
return dev->netdev_ops == &mlxsw_sp_port_netdev_ops;
}
static int mlxsw_sp_port_bridge_join(struct mlxsw_sp_port *mlxsw_sp_port)
{
struct net_device *dev = mlxsw_sp_port->dev;
int err;
err = mlxsw_sp_port_kill_vid(dev, 0, 1);
if (err)
netdev_err(dev, "Failed to remove VID 1\n");
return err;
}
static int mlxsw_sp_port_bridge_leave(struct mlxsw_sp_port *mlxsw_sp_port)
{
struct net_device *dev = mlxsw_sp_port->dev;
int err;
err = mlxsw_sp_port_add_vid(dev, 0, 1);
if (err)
netdev_err(dev, "Failed to add VID 1\n");
return err;
}
static bool mlxsw_sp_master_bridge_check(struct mlxsw_sp *mlxsw_sp,
struct net_device *br_dev)
{
return !mlxsw_sp->master_bridge.dev ||
mlxsw_sp->master_bridge.dev == br_dev;
}
static void mlxsw_sp_master_bridge_inc(struct mlxsw_sp *mlxsw_sp,
struct net_device *br_dev)
{
mlxsw_sp->master_bridge.dev = br_dev;
mlxsw_sp->master_bridge.ref_count++;
}
static void mlxsw_sp_master_bridge_dec(struct mlxsw_sp *mlxsw_sp,
struct net_device *br_dev)
{
if (--mlxsw_sp->master_bridge.ref_count == 0)
mlxsw_sp->master_bridge.dev = NULL;
}
static int mlxsw_sp_netdevice_event(struct notifier_block *unused,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct netdev_notifier_changeupper_info *info;
struct mlxsw_sp_port *mlxsw_sp_port;
struct net_device *upper_dev;
struct mlxsw_sp *mlxsw_sp;
int err;
if (!mlxsw_sp_port_dev_check(dev))
return NOTIFY_DONE;
mlxsw_sp_port = netdev_priv(dev);
mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
info = ptr;
switch (event) {
case NETDEV_PRECHANGEUPPER:
upper_dev = info->upper_dev;
if (info->master && info->linking &&
netif_is_bridge_master(upper_dev) &&
!mlxsw_sp_master_bridge_check(mlxsw_sp, upper_dev))
return NOTIFY_BAD;
break;
case NETDEV_CHANGEUPPER:
upper_dev = info->upper_dev;
if (info->master &&
netif_is_bridge_master(upper_dev)) {
if (info->linking) {
err = mlxsw_sp_port_bridge_join(mlxsw_sp_port);
if (err)
netdev_err(dev, "Failed to join bridge\n");
mlxsw_sp_master_bridge_inc(mlxsw_sp, upper_dev);
mlxsw_sp_port->bridged = 1;
} else {
err = mlxsw_sp_port_bridge_leave(mlxsw_sp_port);
if (err)
netdev_err(dev, "Failed to leave bridge\n");
mlxsw_sp_port->bridged = 0;
mlxsw_sp_master_bridge_dec(mlxsw_sp, upper_dev);
}
}
break;
}
return NOTIFY_DONE;
}
static int __init mlxsw_sp_module_init(void)
{
int err;
register_netdevice_notifier(&mlxsw_sp_netdevice_nb);
err = mlxsw_core_driver_register(&mlxsw_sp_driver);
if (err)
goto err_core_driver_register;
return 0;
err_core_driver_register:
unregister_netdevice_notifier(&mlxsw_sp_netdevice_nb);
return err;
}
static void __exit mlxsw_sp_module_exit(void)
{
mlxsw_core_driver_unregister(&mlxsw_sp_driver);
unregister_netdevice_notifier(&mlxsw_sp_netdevice_nb);
}
