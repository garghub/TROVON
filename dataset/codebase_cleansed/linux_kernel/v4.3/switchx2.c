static void mlxsw_sx_txhdr_construct(struct sk_buff *skb,
const struct mlxsw_tx_info *tx_info)
{
char *txhdr = skb_push(skb, MLXSW_TXHDR_LEN);
bool is_emad = tx_info->is_emad;
memset(txhdr, 0, MLXSW_TXHDR_LEN);
mlxsw_tx_hdr_version_set(txhdr, MLXSW_TXHDR_VERSION_0);
mlxsw_tx_hdr_ctl_set(txhdr, MLXSW_TXHDR_ETH_CTL);
mlxsw_tx_hdr_proto_set(txhdr, MLXSW_TXHDR_PROTO_ETH);
mlxsw_tx_hdr_etclass_set(txhdr, is_emad ? MLXSW_TXHDR_ETCLASS_6 :
MLXSW_TXHDR_ETCLASS_5);
mlxsw_tx_hdr_swid_set(txhdr, 0);
mlxsw_tx_hdr_port_mid_set(txhdr, tx_info->local_port);
mlxsw_tx_hdr_ctclass3_set(txhdr, MLXSW_TXHDR_CTCLASS3);
mlxsw_tx_hdr_rdq_set(txhdr, is_emad ? MLXSW_TXHDR_RDQ_EMAD :
MLXSW_TXHDR_RDQ_OTHER);
mlxsw_tx_hdr_cpu_sig_set(txhdr, MLXSW_TXHDR_CPU_SIG);
mlxsw_tx_hdr_sig_set(txhdr, MLXSW_TXHDR_SIG);
mlxsw_tx_hdr_stclass_set(txhdr, MLXSW_TXHDR_STCLASS_NONE);
mlxsw_tx_hdr_emad_set(txhdr, is_emad ? MLXSW_TXHDR_EMAD :
MLXSW_TXHDR_NOT_EMAD);
mlxsw_tx_hdr_type_set(txhdr, MLXSW_TXHDR_TYPE_CONTROL);
}
static int mlxsw_sx_port_admin_status_set(struct mlxsw_sx_port *mlxsw_sx_port,
bool is_up)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char paos_pl[MLXSW_REG_PAOS_LEN];
mlxsw_reg_paos_pack(paos_pl, mlxsw_sx_port->local_port,
is_up ? MLXSW_PORT_ADMIN_STATUS_UP :
MLXSW_PORT_ADMIN_STATUS_DOWN);
return mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(paos), paos_pl);
}
static int mlxsw_sx_port_oper_status_get(struct mlxsw_sx_port *mlxsw_sx_port,
bool *p_is_up)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char paos_pl[MLXSW_REG_PAOS_LEN];
u8 oper_status;
int err;
mlxsw_reg_paos_pack(paos_pl, mlxsw_sx_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(paos), paos_pl);
if (err)
return err;
oper_status = mlxsw_reg_paos_oper_status_get(paos_pl);
*p_is_up = oper_status == MLXSW_PORT_ADMIN_STATUS_UP ? true : false;
return 0;
}
static int mlxsw_sx_port_mtu_set(struct mlxsw_sx_port *mlxsw_sx_port, u16 mtu)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char pmtu_pl[MLXSW_REG_PMTU_LEN];
int max_mtu;
int err;
mtu += MLXSW_TXHDR_LEN + ETH_HLEN;
mlxsw_reg_pmtu_pack(pmtu_pl, mlxsw_sx_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(pmtu), pmtu_pl);
if (err)
return err;
max_mtu = mlxsw_reg_pmtu_max_mtu_get(pmtu_pl);
if (mtu > max_mtu)
return -EINVAL;
mlxsw_reg_pmtu_pack(pmtu_pl, mlxsw_sx_port->local_port, mtu);
return mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(pmtu), pmtu_pl);
}
static int mlxsw_sx_port_swid_set(struct mlxsw_sx_port *mlxsw_sx_port, u8 swid)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char pspa_pl[MLXSW_REG_PSPA_LEN];
mlxsw_reg_pspa_pack(pspa_pl, swid, mlxsw_sx_port->local_port);
return mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(pspa), pspa_pl);
}
static int
mlxsw_sx_port_system_port_mapping_set(struct mlxsw_sx_port *mlxsw_sx_port)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char sspr_pl[MLXSW_REG_SSPR_LEN];
mlxsw_reg_sspr_pack(sspr_pl, mlxsw_sx_port->local_port);
return mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(sspr), sspr_pl);
}
static int mlxsw_sx_port_module_check(struct mlxsw_sx_port *mlxsw_sx_port,
bool *p_usable)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char pmlp_pl[MLXSW_REG_PMLP_LEN];
int err;
mlxsw_reg_pmlp_pack(pmlp_pl, mlxsw_sx_port->local_port);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(pmlp), pmlp_pl);
if (err)
return err;
*p_usable = mlxsw_reg_pmlp_width_get(pmlp_pl) ? true : false;
return 0;
}
static int mlxsw_sx_port_open(struct net_device *dev)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
int err;
err = mlxsw_sx_port_admin_status_set(mlxsw_sx_port, true);
if (err)
return err;
netif_start_queue(dev);
return 0;
}
static int mlxsw_sx_port_stop(struct net_device *dev)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
netif_stop_queue(dev);
return mlxsw_sx_port_admin_status_set(mlxsw_sx_port, false);
}
static netdev_tx_t mlxsw_sx_port_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
struct mlxsw_sx_port_pcpu_stats *pcpu_stats;
const struct mlxsw_tx_info tx_info = {
.local_port = mlxsw_sx_port->local_port,
.is_emad = false,
};
u64 len;
int err;
if (mlxsw_core_skb_transmit_busy(mlxsw_sx, &tx_info))
return NETDEV_TX_BUSY;
if (unlikely(skb_headroom(skb) < MLXSW_TXHDR_LEN)) {
struct sk_buff *skb_orig = skb;
skb = skb_realloc_headroom(skb, MLXSW_TXHDR_LEN);
if (!skb) {
this_cpu_inc(mlxsw_sx_port->pcpu_stats->tx_dropped);
dev_kfree_skb_any(skb_orig);
return NETDEV_TX_OK;
}
}
mlxsw_sx_txhdr_construct(skb, &tx_info);
len = skb->len;
err = mlxsw_core_skb_transmit(mlxsw_sx, skb, &tx_info);
if (!err) {
pcpu_stats = this_cpu_ptr(mlxsw_sx_port->pcpu_stats);
u64_stats_update_begin(&pcpu_stats->syncp);
pcpu_stats->tx_packets++;
pcpu_stats->tx_bytes += len;
u64_stats_update_end(&pcpu_stats->syncp);
} else {
this_cpu_inc(mlxsw_sx_port->pcpu_stats->tx_dropped);
dev_kfree_skb_any(skb);
}
return NETDEV_TX_OK;
}
static int mlxsw_sx_port_change_mtu(struct net_device *dev, int mtu)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
int err;
err = mlxsw_sx_port_mtu_set(mlxsw_sx_port, mtu);
if (err)
return err;
dev->mtu = mtu;
return 0;
}
static struct rtnl_link_stats64 *
mlxsw_sx_port_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
struct mlxsw_sx_port_pcpu_stats *p;
u64 rx_packets, rx_bytes, tx_packets, tx_bytes;
u32 tx_dropped = 0;
unsigned int start;
int i;
for_each_possible_cpu(i) {
p = per_cpu_ptr(mlxsw_sx_port->pcpu_stats, i);
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
static void mlxsw_sx_port_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *drvinfo)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
strlcpy(drvinfo->driver, mlxsw_sx_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, mlxsw_sx_driver_version,
sizeof(drvinfo->version));
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
"%d.%d.%d",
mlxsw_sx->bus_info->fw_rev.major,
mlxsw_sx->bus_info->fw_rev.minor,
mlxsw_sx->bus_info->fw_rev.subminor);
strlcpy(drvinfo->bus_info, mlxsw_sx->bus_info->device_name,
sizeof(drvinfo->bus_info));
}
static void mlxsw_sx_port_get_strings(struct net_device *dev,
u32 stringset, u8 *data)
{
u8 *p = data;
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < MLXSW_SX_PORT_HW_STATS_LEN; i++) {
memcpy(p, mlxsw_sx_port_hw_stats[i].str,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
break;
}
}
static void mlxsw_sx_port_get_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char ppcnt_pl[MLXSW_REG_PPCNT_LEN];
int i;
int err;
mlxsw_reg_ppcnt_pack(ppcnt_pl, mlxsw_sx_port->local_port);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(ppcnt), ppcnt_pl);
for (i = 0; i < MLXSW_SX_PORT_HW_STATS_LEN; i++)
data[i] = !err ? mlxsw_sx_port_hw_stats[i].getter(ppcnt_pl) : 0;
}
static int mlxsw_sx_port_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return MLXSW_SX_PORT_HW_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static u32 mlxsw_sx_from_ptys_supported_port(u32 ptys_eth_proto)
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
static u32 mlxsw_sx_from_ptys_supported_link(u32 ptys_eth_proto)
{
u32 modes = 0;
int i;
for (i = 0; i < MLXSW_SX_PORT_LINK_MODE_LEN; i++) {
if (ptys_eth_proto & mlxsw_sx_port_link_mode[i].mask)
modes |= mlxsw_sx_port_link_mode[i].supported;
}
return modes;
}
static u32 mlxsw_sx_from_ptys_advert_link(u32 ptys_eth_proto)
{
u32 modes = 0;
int i;
for (i = 0; i < MLXSW_SX_PORT_LINK_MODE_LEN; i++) {
if (ptys_eth_proto & mlxsw_sx_port_link_mode[i].mask)
modes |= mlxsw_sx_port_link_mode[i].advertised;
}
return modes;
}
static void mlxsw_sx_from_ptys_speed_duplex(bool carrier_ok, u32 ptys_eth_proto,
struct ethtool_cmd *cmd)
{
u32 speed = SPEED_UNKNOWN;
u8 duplex = DUPLEX_UNKNOWN;
int i;
if (!carrier_ok)
goto out;
for (i = 0; i < MLXSW_SX_PORT_LINK_MODE_LEN; i++) {
if (ptys_eth_proto & mlxsw_sx_port_link_mode[i].mask) {
speed = mlxsw_sx_port_link_mode[i].speed;
duplex = DUPLEX_FULL;
break;
}
}
out:
ethtool_cmd_speed_set(cmd, speed);
cmd->duplex = duplex;
}
static u8 mlxsw_sx_port_connector_port(u32 ptys_eth_proto)
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
static int mlxsw_sx_port_get_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char ptys_pl[MLXSW_REG_PTYS_LEN];
u32 eth_proto_cap;
u32 eth_proto_admin;
u32 eth_proto_oper;
int err;
mlxsw_reg_ptys_pack(ptys_pl, mlxsw_sx_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(ptys), ptys_pl);
if (err) {
netdev_err(dev, "Failed to get proto");
return err;
}
mlxsw_reg_ptys_unpack(ptys_pl, &eth_proto_cap,
&eth_proto_admin, &eth_proto_oper);
cmd->supported = mlxsw_sx_from_ptys_supported_port(eth_proto_cap) |
mlxsw_sx_from_ptys_supported_link(eth_proto_cap) |
SUPPORTED_Pause | SUPPORTED_Asym_Pause;
cmd->advertising = mlxsw_sx_from_ptys_advert_link(eth_proto_admin);
mlxsw_sx_from_ptys_speed_duplex(netif_carrier_ok(dev),
eth_proto_oper, cmd);
eth_proto_oper = eth_proto_oper ? eth_proto_oper : eth_proto_cap;
cmd->port = mlxsw_sx_port_connector_port(eth_proto_oper);
cmd->lp_advertising = mlxsw_sx_from_ptys_advert_link(eth_proto_oper);
cmd->transceiver = XCVR_INTERNAL;
return 0;
}
static u32 mlxsw_sx_to_ptys_advert_link(u32 advertising)
{
u32 ptys_proto = 0;
int i;
for (i = 0; i < MLXSW_SX_PORT_LINK_MODE_LEN; i++) {
if (advertising & mlxsw_sx_port_link_mode[i].advertised)
ptys_proto |= mlxsw_sx_port_link_mode[i].mask;
}
return ptys_proto;
}
static u32 mlxsw_sx_to_ptys_speed(u32 speed)
{
u32 ptys_proto = 0;
int i;
for (i = 0; i < MLXSW_SX_PORT_LINK_MODE_LEN; i++) {
if (speed == mlxsw_sx_port_link_mode[i].speed)
ptys_proto |= mlxsw_sx_port_link_mode[i].mask;
}
return ptys_proto;
}
static int mlxsw_sx_port_set_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char ptys_pl[MLXSW_REG_PTYS_LEN];
u32 speed;
u32 eth_proto_new;
u32 eth_proto_cap;
u32 eth_proto_admin;
bool is_up;
int err;
speed = ethtool_cmd_speed(cmd);
eth_proto_new = cmd->autoneg == AUTONEG_ENABLE ?
mlxsw_sx_to_ptys_advert_link(cmd->advertising) :
mlxsw_sx_to_ptys_speed(speed);
mlxsw_reg_ptys_pack(ptys_pl, mlxsw_sx_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(ptys), ptys_pl);
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
mlxsw_reg_ptys_pack(ptys_pl, mlxsw_sx_port->local_port, eth_proto_new);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(ptys), ptys_pl);
if (err) {
netdev_err(dev, "Failed to set proto admin");
return err;
}
err = mlxsw_sx_port_oper_status_get(mlxsw_sx_port, &is_up);
if (err) {
netdev_err(dev, "Failed to get oper status");
return err;
}
if (!is_up)
return 0;
err = mlxsw_sx_port_admin_status_set(mlxsw_sx_port, false);
if (err) {
netdev_err(dev, "Failed to set admin status");
return err;
}
err = mlxsw_sx_port_admin_status_set(mlxsw_sx_port, true);
if (err) {
netdev_err(dev, "Failed to set admin status");
return err;
}
return 0;
}
static int mlxsw_sx_port_attr_get(struct net_device *dev,
struct switchdev_attr *attr)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
switch (attr->id) {
case SWITCHDEV_ATTR_PORT_PARENT_ID:
attr->u.ppid.id_len = sizeof(mlxsw_sx->hw_id);
memcpy(&attr->u.ppid.id, &mlxsw_sx->hw_id, attr->u.ppid.id_len);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int mlxsw_sx_hw_id_get(struct mlxsw_sx *mlxsw_sx)
{
char spad_pl[MLXSW_REG_SPAD_LEN];
int err;
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(spad), spad_pl);
if (err)
return err;
mlxsw_reg_spad_base_mac_memcpy_from(spad_pl, mlxsw_sx->hw_id);
return 0;
}
static int mlxsw_sx_port_dev_addr_get(struct mlxsw_sx_port *mlxsw_sx_port)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
struct net_device *dev = mlxsw_sx_port->dev;
char ppad_pl[MLXSW_REG_PPAD_LEN];
int err;
mlxsw_reg_ppad_pack(ppad_pl, false, 0);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(ppad), ppad_pl);
if (err)
return err;
mlxsw_reg_ppad_mac_memcpy_from(ppad_pl, dev->dev_addr);
dev->dev_addr[ETH_ALEN - 1] += mlxsw_sx_port->local_port;
return 0;
}
static int mlxsw_sx_port_stp_state_set(struct mlxsw_sx_port *mlxsw_sx_port,
u16 vid, enum mlxsw_reg_spms_state state)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char *spms_pl;
int err;
spms_pl = kmalloc(MLXSW_REG_SPMS_LEN, GFP_KERNEL);
if (!spms_pl)
return -ENOMEM;
mlxsw_reg_spms_pack(spms_pl, mlxsw_sx_port->local_port, vid, state);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(spms), spms_pl);
kfree(spms_pl);
return err;
}
static int mlxsw_sx_port_speed_set(struct mlxsw_sx_port *mlxsw_sx_port,
u32 speed)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char ptys_pl[MLXSW_REG_PTYS_LEN];
mlxsw_reg_ptys_pack(ptys_pl, mlxsw_sx_port->local_port, speed);
return mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(ptys), ptys_pl);
}
static int
mlxsw_sx_port_mac_learning_mode_set(struct mlxsw_sx_port *mlxsw_sx_port,
enum mlxsw_reg_spmlr_learn_mode mode)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char spmlr_pl[MLXSW_REG_SPMLR_LEN];
mlxsw_reg_spmlr_pack(spmlr_pl, mlxsw_sx_port->local_port, mode);
return mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(spmlr), spmlr_pl);
}
static int mlxsw_sx_port_create(struct mlxsw_sx *mlxsw_sx, u8 local_port)
{
struct mlxsw_sx_port *mlxsw_sx_port;
struct net_device *dev;
bool usable;
int err;
dev = alloc_etherdev(sizeof(struct mlxsw_sx_port));
if (!dev)
return -ENOMEM;
mlxsw_sx_port = netdev_priv(dev);
mlxsw_sx_port->dev = dev;
mlxsw_sx_port->mlxsw_sx = mlxsw_sx;
mlxsw_sx_port->local_port = local_port;
mlxsw_sx_port->pcpu_stats =
netdev_alloc_pcpu_stats(struct mlxsw_sx_port_pcpu_stats);
if (!mlxsw_sx_port->pcpu_stats) {
err = -ENOMEM;
goto err_alloc_stats;
}
dev->netdev_ops = &mlxsw_sx_port_netdev_ops;
dev->ethtool_ops = &mlxsw_sx_port_ethtool_ops;
dev->switchdev_ops = &mlxsw_sx_port_switchdev_ops;
err = mlxsw_sx_port_dev_addr_get(mlxsw_sx_port);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Unable to get port mac address\n",
mlxsw_sx_port->local_port);
goto err_dev_addr_get;
}
netif_carrier_off(dev);
dev->features |= NETIF_F_NETNS_LOCAL | NETIF_F_LLTX | NETIF_F_SG |
NETIF_F_VLAN_CHALLENGED;
dev->hard_header_len += MLXSW_TXHDR_LEN;
err = mlxsw_sx_port_module_check(mlxsw_sx_port, &usable);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to check module\n",
mlxsw_sx_port->local_port);
goto err_port_module_check;
}
if (!usable) {
dev_dbg(mlxsw_sx->bus_info->dev, "Port %d: Not usable, skipping initialization\n",
mlxsw_sx_port->local_port);
goto port_not_usable;
}
err = mlxsw_sx_port_system_port_mapping_set(mlxsw_sx_port);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set system port mapping\n",
mlxsw_sx_port->local_port);
goto err_port_system_port_mapping_set;
}
err = mlxsw_sx_port_swid_set(mlxsw_sx_port, 0);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set SWID\n",
mlxsw_sx_port->local_port);
goto err_port_swid_set;
}
err = mlxsw_sx_port_speed_set(mlxsw_sx_port,
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_CR4);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set speed\n",
mlxsw_sx_port->local_port);
goto err_port_speed_set;
}
err = mlxsw_sx_port_mtu_set(mlxsw_sx_port, ETH_DATA_LEN);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set MTU\n",
mlxsw_sx_port->local_port);
goto err_port_mtu_set;
}
err = mlxsw_sx_port_admin_status_set(mlxsw_sx_port, false);
if (err)
goto err_port_admin_status_set;
err = mlxsw_sx_port_stp_state_set(mlxsw_sx_port,
MLXSW_PORT_DEFAULT_VID,
MLXSW_REG_SPMS_STATE_FORWARDING);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set STP state\n",
mlxsw_sx_port->local_port);
goto err_port_stp_state_set;
}
err = mlxsw_sx_port_mac_learning_mode_set(mlxsw_sx_port,
MLXSW_REG_SPMLR_LEARN_MODE_DISABLE);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set MAC learning mode\n",
mlxsw_sx_port->local_port);
goto err_port_mac_learning_mode_set;
}
err = register_netdev(dev);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to register netdev\n",
mlxsw_sx_port->local_port);
goto err_register_netdev;
}
mlxsw_sx->ports[local_port] = mlxsw_sx_port;
return 0;
err_register_netdev:
err_port_mac_learning_mode_set:
err_port_stp_state_set:
err_port_admin_status_set:
err_port_mtu_set:
err_port_speed_set:
err_port_swid_set:
err_port_system_port_mapping_set:
port_not_usable:
err_port_module_check:
err_dev_addr_get:
free_percpu(mlxsw_sx_port->pcpu_stats);
err_alloc_stats:
free_netdev(dev);
return err;
}
static void mlxsw_sx_port_remove(struct mlxsw_sx *mlxsw_sx, u8 local_port)
{
struct mlxsw_sx_port *mlxsw_sx_port = mlxsw_sx->ports[local_port];
if (!mlxsw_sx_port)
return;
unregister_netdev(mlxsw_sx_port->dev);
mlxsw_sx_port_swid_set(mlxsw_sx_port, MLXSW_PORT_SWID_DISABLED_PORT);
free_percpu(mlxsw_sx_port->pcpu_stats);
free_netdev(mlxsw_sx_port->dev);
}
static void mlxsw_sx_ports_remove(struct mlxsw_sx *mlxsw_sx)
{
int i;
for (i = 1; i < MLXSW_PORT_MAX_PORTS; i++)
mlxsw_sx_port_remove(mlxsw_sx, i);
kfree(mlxsw_sx->ports);
}
static int mlxsw_sx_ports_create(struct mlxsw_sx *mlxsw_sx)
{
size_t alloc_size;
int i;
int err;
alloc_size = sizeof(struct mlxsw_sx_port *) * MLXSW_PORT_MAX_PORTS;
mlxsw_sx->ports = kzalloc(alloc_size, GFP_KERNEL);
if (!mlxsw_sx->ports)
return -ENOMEM;
for (i = 1; i < MLXSW_PORT_MAX_PORTS; i++) {
err = mlxsw_sx_port_create(mlxsw_sx, i);
if (err)
goto err_port_create;
}
return 0;
err_port_create:
for (i--; i >= 1; i--)
mlxsw_sx_port_remove(mlxsw_sx, i);
kfree(mlxsw_sx->ports);
return err;
}
static void mlxsw_sx_pude_event_func(const struct mlxsw_reg_info *reg,
char *pude_pl, void *priv)
{
struct mlxsw_sx *mlxsw_sx = priv;
struct mlxsw_sx_port *mlxsw_sx_port;
enum mlxsw_reg_pude_oper_status status;
u8 local_port;
local_port = mlxsw_reg_pude_local_port_get(pude_pl);
mlxsw_sx_port = mlxsw_sx->ports[local_port];
if (!mlxsw_sx_port) {
dev_warn(mlxsw_sx->bus_info->dev, "Port %d: Link event received for non-existent port\n",
local_port);
return;
}
status = mlxsw_reg_pude_oper_status_get(pude_pl);
if (MLXSW_PORT_OPER_STATUS_UP == status) {
netdev_info(mlxsw_sx_port->dev, "link up\n");
netif_carrier_on(mlxsw_sx_port->dev);
} else {
netdev_info(mlxsw_sx_port->dev, "link down\n");
netif_carrier_off(mlxsw_sx_port->dev);
}
}
static int mlxsw_sx_event_register(struct mlxsw_sx *mlxsw_sx,
enum mlxsw_event_trap_id trap_id)
{
struct mlxsw_event_listener *el;
char hpkt_pl[MLXSW_REG_HPKT_LEN];
int err;
switch (trap_id) {
case MLXSW_TRAP_ID_PUDE:
el = &mlxsw_sx_pude_event;
break;
}
err = mlxsw_core_event_listener_register(mlxsw_sx->core, el, mlxsw_sx);
if (err)
return err;
mlxsw_reg_hpkt_pack(hpkt_pl, MLXSW_REG_HPKT_ACTION_FORWARD,
MLXSW_REG_HTGT_TRAP_GROUP_EMAD, trap_id);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(hpkt), hpkt_pl);
if (err)
goto err_event_trap_set;
return 0;
err_event_trap_set:
mlxsw_core_event_listener_unregister(mlxsw_sx->core, el, mlxsw_sx);
return err;
}
static void mlxsw_sx_event_unregister(struct mlxsw_sx *mlxsw_sx,
enum mlxsw_event_trap_id trap_id)
{
struct mlxsw_event_listener *el;
switch (trap_id) {
case MLXSW_TRAP_ID_PUDE:
el = &mlxsw_sx_pude_event;
break;
}
mlxsw_core_event_listener_unregister(mlxsw_sx->core, el, mlxsw_sx);
}
static void mlxsw_sx_rx_listener_func(struct sk_buff *skb, u8 local_port,
void *priv)
{
struct mlxsw_sx *mlxsw_sx = priv;
struct mlxsw_sx_port *mlxsw_sx_port = mlxsw_sx->ports[local_port];
struct mlxsw_sx_port_pcpu_stats *pcpu_stats;
if (unlikely(!mlxsw_sx_port)) {
if (net_ratelimit())
dev_warn(mlxsw_sx->bus_info->dev, "Port %d: skb received for non-existent port\n",
local_port);
return;
}
skb->dev = mlxsw_sx_port->dev;
pcpu_stats = this_cpu_ptr(mlxsw_sx_port->pcpu_stats);
u64_stats_update_begin(&pcpu_stats->syncp);
pcpu_stats->rx_packets++;
pcpu_stats->rx_bytes += skb->len;
u64_stats_update_end(&pcpu_stats->syncp);
skb->protocol = eth_type_trans(skb, skb->dev);
netif_receive_skb(skb);
}
static int mlxsw_sx_traps_init(struct mlxsw_sx *mlxsw_sx)
{
char htgt_pl[MLXSW_REG_HTGT_LEN];
char hpkt_pl[MLXSW_REG_HPKT_LEN];
int i;
int err;
mlxsw_reg_htgt_pack(htgt_pl, MLXSW_REG_HTGT_TRAP_GROUP_RX);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(htgt), htgt_pl);
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(mlxsw_sx_rx_listener); i++) {
err = mlxsw_core_rx_listener_register(mlxsw_sx->core,
&mlxsw_sx_rx_listener[i],
mlxsw_sx);
if (err)
goto err_rx_listener_register;
mlxsw_reg_hpkt_pack(hpkt_pl, MLXSW_REG_HPKT_ACTION_TRAP_TO_CPU,
MLXSW_REG_HTGT_TRAP_GROUP_RX,
mlxsw_sx_rx_listener[i].trap_id);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(hpkt), hpkt_pl);
if (err)
goto err_rx_trap_set;
}
return 0;
err_rx_trap_set:
mlxsw_core_rx_listener_unregister(mlxsw_sx->core,
&mlxsw_sx_rx_listener[i],
mlxsw_sx);
err_rx_listener_register:
for (i--; i >= 0; i--) {
mlxsw_reg_hpkt_pack(hpkt_pl, MLXSW_REG_HPKT_ACTION_FORWARD,
MLXSW_REG_HTGT_TRAP_GROUP_RX,
mlxsw_sx_rx_listener[i].trap_id);
mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(hpkt), hpkt_pl);
mlxsw_core_rx_listener_unregister(mlxsw_sx->core,
&mlxsw_sx_rx_listener[i],
mlxsw_sx);
}
return err;
}
static void mlxsw_sx_traps_fini(struct mlxsw_sx *mlxsw_sx)
{
char hpkt_pl[MLXSW_REG_HPKT_LEN];
int i;
for (i = 0; i < ARRAY_SIZE(mlxsw_sx_rx_listener); i++) {
mlxsw_reg_hpkt_pack(hpkt_pl, MLXSW_REG_HPKT_ACTION_FORWARD,
MLXSW_REG_HTGT_TRAP_GROUP_RX,
mlxsw_sx_rx_listener[i].trap_id);
mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(hpkt), hpkt_pl);
mlxsw_core_rx_listener_unregister(mlxsw_sx->core,
&mlxsw_sx_rx_listener[i],
mlxsw_sx);
}
}
static int mlxsw_sx_flood_init(struct mlxsw_sx *mlxsw_sx)
{
char sfgc_pl[MLXSW_REG_SFGC_LEN];
char sgcr_pl[MLXSW_REG_SGCR_LEN];
char *smid_pl;
char *sftr_pl;
int err;
smid_pl = kmalloc(MLXSW_REG_SMID_LEN, GFP_KERNEL);
if (!smid_pl)
return -ENOMEM;
mlxsw_reg_smid_pack(smid_pl, MLXSW_PORT_MID);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(smid), smid_pl);
kfree(smid_pl);
if (err)
return err;
sftr_pl = kmalloc(MLXSW_REG_SFTR_LEN, GFP_KERNEL);
if (!sftr_pl)
return -ENOMEM;
mlxsw_reg_sftr_pack(sftr_pl, 0, 0, MLXSW_REG_SFGC_TABLE_TYPE_SINGLE, 0);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(sftr), sftr_pl);
kfree(sftr_pl);
if (err)
return err;
mlxsw_reg_sfgc_pack(sfgc_pl,
MLXSW_REG_SFGC_TYPE_UNKNOWN_UNICAST,
MLXSW_REG_SFGC_BRIDGE_TYPE_1Q_FID,
MLXSW_REG_SFGC_TABLE_TYPE_SINGLE,
0);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(sfgc), sfgc_pl);
if (err)
return err;
mlxsw_reg_sfgc_pack(sfgc_pl,
MLXSW_REG_SFGC_TYPE_BROADCAST,
MLXSW_REG_SFGC_BRIDGE_TYPE_1Q_FID,
MLXSW_REG_SFGC_TABLE_TYPE_SINGLE,
0);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(sfgc), sfgc_pl);
if (err)
return err;
mlxsw_reg_sfgc_pack(sfgc_pl,
MLXSW_REG_SFGC_TYPE_UNREGISTERED_MULTICAST_NON_IP,
MLXSW_REG_SFGC_BRIDGE_TYPE_1Q_FID,
MLXSW_REG_SFGC_TABLE_TYPE_SINGLE,
0);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(sfgc), sfgc_pl);
if (err)
return err;
mlxsw_reg_sfgc_pack(sfgc_pl,
MLXSW_REG_SFGC_TYPE_UNREGISTERED_MULTICAST_IPV6,
MLXSW_REG_SFGC_BRIDGE_TYPE_1Q_FID,
MLXSW_REG_SFGC_TABLE_TYPE_SINGLE,
0);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(sfgc), sfgc_pl);
if (err)
return err;
mlxsw_reg_sfgc_pack(sfgc_pl,
MLXSW_REG_SFGC_TYPE_UNREGISTERED_MULTICAST_IPV4,
MLXSW_REG_SFGC_BRIDGE_TYPE_1Q_FID,
MLXSW_REG_SFGC_TABLE_TYPE_SINGLE,
0);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(sfgc), sfgc_pl);
if (err)
return err;
mlxsw_reg_sgcr_pack(sgcr_pl, true);
return mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(sgcr), sgcr_pl);
}
static int mlxsw_sx_init(void *priv, struct mlxsw_core *mlxsw_core,
const struct mlxsw_bus_info *mlxsw_bus_info)
{
struct mlxsw_sx *mlxsw_sx = priv;
int err;
mlxsw_sx->core = mlxsw_core;
mlxsw_sx->bus_info = mlxsw_bus_info;
err = mlxsw_sx_hw_id_get(mlxsw_sx);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Failed to get switch HW ID\n");
return err;
}
err = mlxsw_sx_ports_create(mlxsw_sx);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Failed to create ports\n");
return err;
}
err = mlxsw_sx_event_register(mlxsw_sx, MLXSW_TRAP_ID_PUDE);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Failed to register for PUDE events\n");
goto err_event_register;
}
err = mlxsw_sx_traps_init(mlxsw_sx);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Failed to set traps for RX\n");
goto err_rx_listener_register;
}
err = mlxsw_sx_flood_init(mlxsw_sx);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Failed to initialize flood tables\n");
goto err_flood_init;
}
return 0;
err_flood_init:
mlxsw_sx_traps_fini(mlxsw_sx);
err_rx_listener_register:
mlxsw_sx_event_unregister(mlxsw_sx, MLXSW_TRAP_ID_PUDE);
err_event_register:
mlxsw_sx_ports_remove(mlxsw_sx);
return err;
}
static void mlxsw_sx_fini(void *priv)
{
struct mlxsw_sx *mlxsw_sx = priv;
mlxsw_sx_traps_fini(mlxsw_sx);
mlxsw_sx_event_unregister(mlxsw_sx, MLXSW_TRAP_ID_PUDE);
mlxsw_sx_ports_remove(mlxsw_sx);
}
static int __init mlxsw_sx_module_init(void)
{
return mlxsw_core_driver_register(&mlxsw_sx_driver);
}
static void __exit mlxsw_sx_module_exit(void)
{
mlxsw_core_driver_unregister(&mlxsw_sx_driver);
}
