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
static int __mlxsw_sx_port_mtu_set(struct mlxsw_sx_port *mlxsw_sx_port,
u16 mtu)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char pmtu_pl[MLXSW_REG_PMTU_LEN];
int max_mtu;
int err;
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
static int mlxsw_sx_port_mtu_eth_set(struct mlxsw_sx_port *mlxsw_sx_port,
u16 mtu)
{
mtu += MLXSW_TXHDR_LEN + ETH_HLEN;
return __mlxsw_sx_port_mtu_set(mlxsw_sx_port, mtu);
}
static int mlxsw_sx_port_mtu_ib_set(struct mlxsw_sx_port *mlxsw_sx_port,
u16 mtu)
{
return __mlxsw_sx_port_mtu_set(mlxsw_sx_port, mtu);
}
static int mlxsw_sx_port_ib_port_set(struct mlxsw_sx_port *mlxsw_sx_port,
u8 ib_port)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char plib_pl[MLXSW_REG_PLIB_LEN] = {0};
int err;
mlxsw_reg_plib_local_port_set(plib_pl, mlxsw_sx_port->local_port);
mlxsw_reg_plib_ib_port_set(plib_pl, ib_port);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(plib), plib_pl);
return err;
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
static int mlxsw_sx_port_module_info_get(struct mlxsw_sx *mlxsw_sx,
u8 local_port, u8 *p_module,
u8 *p_width)
{
char pmlp_pl[MLXSW_REG_PMLP_LEN];
int err;
mlxsw_reg_pmlp_pack(pmlp_pl, local_port);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(pmlp), pmlp_pl);
if (err)
return err;
*p_module = mlxsw_reg_pmlp_module_get(pmlp_pl, 0);
*p_width = mlxsw_reg_pmlp_width_get(pmlp_pl);
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
if (mlxsw_core_skb_transmit_busy(mlxsw_sx->core, &tx_info))
return NETDEV_TX_BUSY;
if (unlikely(skb_headroom(skb) < MLXSW_TXHDR_LEN)) {
struct sk_buff *skb_orig = skb;
skb = skb_realloc_headroom(skb, MLXSW_TXHDR_LEN);
if (!skb) {
this_cpu_inc(mlxsw_sx_port->pcpu_stats->tx_dropped);
dev_kfree_skb_any(skb_orig);
return NETDEV_TX_OK;
}
dev_consume_skb_any(skb_orig);
}
mlxsw_sx_txhdr_construct(skb, &tx_info);
len = skb->len - MLXSW_TXHDR_LEN;
err = mlxsw_core_skb_transmit(mlxsw_sx->core, skb, &tx_info);
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
err = mlxsw_sx_port_mtu_eth_set(mlxsw_sx_port, mtu);
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
static int mlxsw_sx_port_get_phys_port_name(struct net_device *dev, char *name,
size_t len)
{
struct mlxsw_sx_port *mlxsw_sx_port = netdev_priv(dev);
int err;
err = snprintf(name, len, "p%d", mlxsw_sx_port->mapping.module + 1);
if (err >= len)
return -EINVAL;
return 0;
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
mlxsw_reg_ppcnt_pack(ppcnt_pl, mlxsw_sx_port->local_port,
MLXSW_REG_PPCNT_IEEE_8023_CNT, 0);
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
mlxsw_reg_ptys_eth_pack(ptys_pl, mlxsw_sx_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(ptys), ptys_pl);
if (err) {
netdev_err(dev, "Failed to get proto");
return err;
}
mlxsw_reg_ptys_eth_unpack(ptys_pl, &eth_proto_cap,
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
static u32 mlxsw_sx_to_ptys_upper_speed(u32 upper_speed)
{
u32 ptys_proto = 0;
int i;
for (i = 0; i < MLXSW_SX_PORT_LINK_MODE_LEN; i++) {
if (mlxsw_sx_port_link_mode[i].speed <= upper_speed)
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
mlxsw_reg_ptys_eth_pack(ptys_pl, mlxsw_sx_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sx->core, MLXSW_REG(ptys), ptys_pl);
if (err) {
netdev_err(dev, "Failed to get proto");
return err;
}
mlxsw_reg_ptys_eth_unpack(ptys_pl, &eth_proto_cap, &eth_proto_admin,
NULL);
eth_proto_new = eth_proto_new & eth_proto_cap;
if (!eth_proto_new) {
netdev_err(dev, "Not supported proto admin requested");
return -EINVAL;
}
if (eth_proto_new == eth_proto_admin)
return 0;
mlxsw_reg_ptys_eth_pack(ptys_pl, mlxsw_sx_port->local_port,
eth_proto_new);
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
case SWITCHDEV_ATTR_ID_PORT_PARENT_ID:
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
char spad_pl[MLXSW_REG_SPAD_LEN] = {0};
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
mlxsw_reg_spms_pack(spms_pl, mlxsw_sx_port->local_port);
mlxsw_reg_spms_vid_pack(spms_pl, vid, state);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(spms), spms_pl);
kfree(spms_pl);
return err;
}
static int mlxsw_sx_port_ib_speed_set(struct mlxsw_sx_port *mlxsw_sx_port,
u16 speed, u16 width)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
char ptys_pl[MLXSW_REG_PTYS_LEN];
mlxsw_reg_ptys_ib_pack(ptys_pl, mlxsw_sx_port->local_port, speed,
width);
return mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(ptys), ptys_pl);
}
static int
mlxsw_sx_port_speed_by_width_set(struct mlxsw_sx_port *mlxsw_sx_port, u8 width)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_sx_port->mlxsw_sx;
u32 upper_speed = MLXSW_SX_PORT_BASE_SPEED * width;
char ptys_pl[MLXSW_REG_PTYS_LEN];
u32 eth_proto_admin;
eth_proto_admin = mlxsw_sx_to_ptys_upper_speed(upper_speed);
mlxsw_reg_ptys_eth_pack(ptys_pl, mlxsw_sx_port->local_port,
eth_proto_admin);
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
static int __mlxsw_sx_port_eth_create(struct mlxsw_sx *mlxsw_sx, u8 local_port,
u8 module, u8 width)
{
struct mlxsw_sx_port *mlxsw_sx_port;
struct net_device *dev;
int err;
dev = alloc_etherdev(sizeof(struct mlxsw_sx_port));
if (!dev)
return -ENOMEM;
SET_NETDEV_DEV(dev, mlxsw_sx->bus_info->dev);
mlxsw_sx_port = netdev_priv(dev);
mlxsw_sx_port->dev = dev;
mlxsw_sx_port->mlxsw_sx = mlxsw_sx;
mlxsw_sx_port->local_port = local_port;
mlxsw_sx_port->mapping.module = module;
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
dev->min_mtu = 0;
dev->max_mtu = ETH_MAX_MTU;
dev->needed_headroom = MLXSW_TXHDR_LEN;
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
err = mlxsw_sx_port_speed_by_width_set(mlxsw_sx_port, width);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set speed\n",
mlxsw_sx_port->local_port);
goto err_port_speed_set;
}
err = mlxsw_sx_port_mtu_eth_set(mlxsw_sx_port, ETH_DATA_LEN);
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
mlxsw_core_port_eth_set(mlxsw_sx->core, mlxsw_sx_port->local_port,
mlxsw_sx_port, dev, false, 0);
mlxsw_sx->ports[local_port] = mlxsw_sx_port;
return 0;
err_register_netdev:
err_port_mac_learning_mode_set:
err_port_stp_state_set:
err_port_admin_status_set:
err_port_mtu_set:
err_port_speed_set:
mlxsw_sx_port_swid_set(mlxsw_sx_port, MLXSW_PORT_SWID_DISABLED_PORT);
err_port_swid_set:
err_port_system_port_mapping_set:
err_dev_addr_get:
free_percpu(mlxsw_sx_port->pcpu_stats);
err_alloc_stats:
free_netdev(dev);
return err;
}
static int mlxsw_sx_port_eth_create(struct mlxsw_sx *mlxsw_sx, u8 local_port,
u8 module, u8 width)
{
int err;
err = mlxsw_core_port_init(mlxsw_sx->core, local_port);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to init core port\n",
local_port);
return err;
}
err = __mlxsw_sx_port_eth_create(mlxsw_sx, local_port, module, width);
if (err)
goto err_port_create;
return 0;
err_port_create:
mlxsw_core_port_fini(mlxsw_sx->core, local_port);
return err;
}
static void __mlxsw_sx_port_eth_remove(struct mlxsw_sx *mlxsw_sx, u8 local_port)
{
struct mlxsw_sx_port *mlxsw_sx_port = mlxsw_sx->ports[local_port];
mlxsw_core_port_clear(mlxsw_sx->core, local_port, mlxsw_sx);
unregister_netdev(mlxsw_sx_port->dev);
mlxsw_sx->ports[local_port] = NULL;
mlxsw_sx_port_swid_set(mlxsw_sx_port, MLXSW_PORT_SWID_DISABLED_PORT);
free_percpu(mlxsw_sx_port->pcpu_stats);
free_netdev(mlxsw_sx_port->dev);
}
static bool mlxsw_sx_port_created(struct mlxsw_sx *mlxsw_sx, u8 local_port)
{
return mlxsw_sx->ports[local_port] != NULL;
}
static int __mlxsw_sx_port_ib_create(struct mlxsw_sx *mlxsw_sx, u8 local_port,
u8 module, u8 width)
{
struct mlxsw_sx_port *mlxsw_sx_port;
int err;
mlxsw_sx_port = kzalloc(sizeof(*mlxsw_sx_port), GFP_KERNEL);
if (!mlxsw_sx_port)
return -ENOMEM;
mlxsw_sx_port->mlxsw_sx = mlxsw_sx;
mlxsw_sx_port->local_port = local_port;
mlxsw_sx_port->mapping.module = module;
err = mlxsw_sx_port_system_port_mapping_set(mlxsw_sx_port);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set system port mapping\n",
mlxsw_sx_port->local_port);
goto err_port_system_port_mapping_set;
}
err = mlxsw_sx_port_swid_set(mlxsw_sx_port, 1);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set SWID\n",
mlxsw_sx_port->local_port);
goto err_port_swid_set;
}
err = mlxsw_sx_port_ib_port_set(mlxsw_sx_port, module + 1);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set IB port\n",
mlxsw_sx_port->local_port);
goto err_port_ib_set;
}
err = mlxsw_sx_port_ib_speed_set(mlxsw_sx_port,
MLXSW_REG_PTYS_IB_SPEED_EDR - 1,
BIT(3) - 1);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set speed\n",
mlxsw_sx_port->local_port);
goto err_port_speed_set;
}
err = mlxsw_sx_port_mtu_ib_set(mlxsw_sx_port, MLXSW_IB_DEFAULT_MTU);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to set MTU\n",
mlxsw_sx_port->local_port);
goto err_port_mtu_set;
}
err = mlxsw_sx_port_admin_status_set(mlxsw_sx_port, true);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Port %d: Failed to change admin state to UP\n",
mlxsw_sx_port->local_port);
goto err_port_admin_set;
}
mlxsw_core_port_ib_set(mlxsw_sx->core, mlxsw_sx_port->local_port,
mlxsw_sx_port);
mlxsw_sx->ports[local_port] = mlxsw_sx_port;
return 0;
err_port_admin_set:
err_port_mtu_set:
err_port_speed_set:
err_port_ib_set:
mlxsw_sx_port_swid_set(mlxsw_sx_port, MLXSW_PORT_SWID_DISABLED_PORT);
err_port_swid_set:
err_port_system_port_mapping_set:
kfree(mlxsw_sx_port);
return err;
}
static void __mlxsw_sx_port_ib_remove(struct mlxsw_sx *mlxsw_sx, u8 local_port)
{
struct mlxsw_sx_port *mlxsw_sx_port = mlxsw_sx->ports[local_port];
mlxsw_core_port_clear(mlxsw_sx->core, local_port, mlxsw_sx);
mlxsw_sx->ports[local_port] = NULL;
mlxsw_sx_port_admin_status_set(mlxsw_sx_port, false);
mlxsw_sx_port_swid_set(mlxsw_sx_port, MLXSW_PORT_SWID_DISABLED_PORT);
kfree(mlxsw_sx_port);
}
static void __mlxsw_sx_port_remove(struct mlxsw_sx *mlxsw_sx, u8 local_port)
{
enum devlink_port_type port_type =
mlxsw_core_port_type_get(mlxsw_sx->core, local_port);
if (port_type == DEVLINK_PORT_TYPE_ETH)
__mlxsw_sx_port_eth_remove(mlxsw_sx, local_port);
else if (port_type == DEVLINK_PORT_TYPE_IB)
__mlxsw_sx_port_ib_remove(mlxsw_sx, local_port);
}
static void mlxsw_sx_port_remove(struct mlxsw_sx *mlxsw_sx, u8 local_port)
{
__mlxsw_sx_port_remove(mlxsw_sx, local_port);
mlxsw_core_port_fini(mlxsw_sx->core, local_port);
}
static void mlxsw_sx_ports_remove(struct mlxsw_sx *mlxsw_sx)
{
int i;
for (i = 1; i < MLXSW_PORT_MAX_PORTS; i++)
if (mlxsw_sx_port_created(mlxsw_sx, i))
mlxsw_sx_port_remove(mlxsw_sx, i);
kfree(mlxsw_sx->ports);
}
static int mlxsw_sx_ports_create(struct mlxsw_sx *mlxsw_sx)
{
size_t alloc_size;
u8 module, width;
int i;
int err;
alloc_size = sizeof(struct mlxsw_sx_port *) * MLXSW_PORT_MAX_PORTS;
mlxsw_sx->ports = kzalloc(alloc_size, GFP_KERNEL);
if (!mlxsw_sx->ports)
return -ENOMEM;
for (i = 1; i < MLXSW_PORT_MAX_PORTS; i++) {
err = mlxsw_sx_port_module_info_get(mlxsw_sx, i, &module,
&width);
if (err)
goto err_port_module_info_get;
if (!width)
continue;
err = mlxsw_sx_port_eth_create(mlxsw_sx, i, module, width);
if (err)
goto err_port_create;
}
return 0;
err_port_create:
err_port_module_info_get:
for (i--; i >= 1; i--)
if (mlxsw_sx_port_created(mlxsw_sx, i))
mlxsw_sx_port_remove(mlxsw_sx, i);
kfree(mlxsw_sx->ports);
return err;
}
static void mlxsw_sx_pude_eth_event_func(struct mlxsw_sx_port *mlxsw_sx_port,
enum mlxsw_reg_pude_oper_status status)
{
if (status == MLXSW_PORT_OPER_STATUS_UP) {
netdev_info(mlxsw_sx_port->dev, "link up\n");
netif_carrier_on(mlxsw_sx_port->dev);
} else {
netdev_info(mlxsw_sx_port->dev, "link down\n");
netif_carrier_off(mlxsw_sx_port->dev);
}
}
static void mlxsw_sx_pude_ib_event_func(struct mlxsw_sx_port *mlxsw_sx_port,
enum mlxsw_reg_pude_oper_status status)
{
if (status == MLXSW_PORT_OPER_STATUS_UP)
pr_info("ib link for port %d - up\n",
mlxsw_sx_port->mapping.module + 1);
else
pr_info("ib link for port %d - down\n",
mlxsw_sx_port->mapping.module + 1);
}
static void mlxsw_sx_pude_event_func(const struct mlxsw_reg_info *reg,
char *pude_pl, void *priv)
{
struct mlxsw_sx *mlxsw_sx = priv;
struct mlxsw_sx_port *mlxsw_sx_port;
enum mlxsw_reg_pude_oper_status status;
enum devlink_port_type port_type;
u8 local_port;
local_port = mlxsw_reg_pude_local_port_get(pude_pl);
mlxsw_sx_port = mlxsw_sx->ports[local_port];
if (!mlxsw_sx_port) {
dev_warn(mlxsw_sx->bus_info->dev, "Port %d: Link event received for non-existent port\n",
local_port);
return;
}
status = mlxsw_reg_pude_oper_status_get(pude_pl);
port_type = mlxsw_core_port_type_get(mlxsw_sx->core, local_port);
if (port_type == DEVLINK_PORT_TYPE_ETH)
mlxsw_sx_pude_eth_event_func(mlxsw_sx_port, status);
else if (port_type == DEVLINK_PORT_TYPE_IB)
mlxsw_sx_pude_ib_event_func(mlxsw_sx_port, status);
}
static void mlxsw_sx_rx_listener_func(struct sk_buff *skb, u8 local_port,
void *priv)
{
struct mlxsw_sx *mlxsw_sx = priv;
struct mlxsw_sx_port *mlxsw_sx_port = mlxsw_sx->ports[local_port];
struct mlxsw_sx_port_pcpu_stats *pcpu_stats;
if (unlikely(!mlxsw_sx_port)) {
dev_warn_ratelimited(mlxsw_sx->bus_info->dev, "Port %d: skb received for non-existent port\n",
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
static int mlxsw_sx_port_type_set(struct mlxsw_core *mlxsw_core, u8 local_port,
enum devlink_port_type new_type)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_core_driver_priv(mlxsw_core);
u8 module, width;
int err;
if (new_type == DEVLINK_PORT_TYPE_AUTO)
return -EOPNOTSUPP;
__mlxsw_sx_port_remove(mlxsw_sx, local_port);
err = mlxsw_sx_port_module_info_get(mlxsw_sx, local_port, &module,
&width);
if (err)
goto err_port_module_info_get;
if (new_type == DEVLINK_PORT_TYPE_ETH)
err = __mlxsw_sx_port_eth_create(mlxsw_sx, local_port, module,
width);
else if (new_type == DEVLINK_PORT_TYPE_IB)
err = __mlxsw_sx_port_ib_create(mlxsw_sx, local_port, module,
width);
err_port_module_info_get:
return err;
}
static int mlxsw_sx_traps_init(struct mlxsw_sx *mlxsw_sx)
{
char htgt_pl[MLXSW_REG_HTGT_LEN];
int i;
int err;
mlxsw_reg_htgt_pack(htgt_pl, MLXSW_REG_HTGT_TRAP_GROUP_SX2_RX,
MLXSW_REG_HTGT_INVALID_POLICER,
MLXSW_REG_HTGT_DEFAULT_PRIORITY,
MLXSW_REG_HTGT_DEFAULT_TC);
mlxsw_reg_htgt_local_path_rdq_set(htgt_pl,
MLXSW_REG_HTGT_LOCAL_PATH_RDQ_SX2_RX);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(htgt), htgt_pl);
if (err)
return err;
mlxsw_reg_htgt_pack(htgt_pl, MLXSW_REG_HTGT_TRAP_GROUP_SX2_CTRL,
MLXSW_REG_HTGT_INVALID_POLICER,
MLXSW_REG_HTGT_DEFAULT_PRIORITY,
MLXSW_REG_HTGT_DEFAULT_TC);
mlxsw_reg_htgt_local_path_rdq_set(htgt_pl,
MLXSW_REG_HTGT_LOCAL_PATH_RDQ_SX2_CTRL);
err = mlxsw_reg_write(mlxsw_sx->core, MLXSW_REG(htgt), htgt_pl);
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(mlxsw_sx_listener); i++) {
err = mlxsw_core_trap_register(mlxsw_sx->core,
&mlxsw_sx_listener[i],
mlxsw_sx);
if (err)
goto err_listener_register;
}
return 0;
err_listener_register:
for (i--; i >= 0; i--) {
mlxsw_core_trap_unregister(mlxsw_sx->core,
&mlxsw_sx_listener[i],
mlxsw_sx);
}
return err;
}
static void mlxsw_sx_traps_fini(struct mlxsw_sx *mlxsw_sx)
{
int i;
for (i = 0; i < ARRAY_SIZE(mlxsw_sx_listener); i++) {
mlxsw_core_trap_unregister(mlxsw_sx->core,
&mlxsw_sx_listener[i],
mlxsw_sx);
}
}
static int mlxsw_sx_flood_init(struct mlxsw_sx *mlxsw_sx)
{
char sfgc_pl[MLXSW_REG_SFGC_LEN];
char sgcr_pl[MLXSW_REG_SGCR_LEN];
char *sftr_pl;
int err;
sftr_pl = kmalloc(MLXSW_REG_SFTR_LEN, GFP_KERNEL);
if (!sftr_pl)
return -ENOMEM;
mlxsw_reg_sftr_pack(sftr_pl, 0, 0, MLXSW_REG_SFGC_TABLE_TYPE_SINGLE, 0,
MLXSW_PORT_CPU_PORT, true);
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
static int mlxsw_sx_basic_trap_groups_set(struct mlxsw_core *mlxsw_core)
{
char htgt_pl[MLXSW_REG_HTGT_LEN];
mlxsw_reg_htgt_pack(htgt_pl, MLXSW_REG_HTGT_TRAP_GROUP_EMAD,
MLXSW_REG_HTGT_INVALID_POLICER,
MLXSW_REG_HTGT_DEFAULT_PRIORITY,
MLXSW_REG_HTGT_DEFAULT_TC);
mlxsw_reg_htgt_swid_set(htgt_pl, MLXSW_PORT_SWID_ALL_SWIDS);
mlxsw_reg_htgt_local_path_rdq_set(htgt_pl,
MLXSW_REG_HTGT_LOCAL_PATH_RDQ_SX2_EMAD);
return mlxsw_reg_write(mlxsw_core, MLXSW_REG(htgt), htgt_pl);
}
static int mlxsw_sx_init(struct mlxsw_core *mlxsw_core,
const struct mlxsw_bus_info *mlxsw_bus_info)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_core_driver_priv(mlxsw_core);
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
err = mlxsw_sx_traps_init(mlxsw_sx);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Failed to set traps\n");
goto err_listener_register;
}
err = mlxsw_sx_flood_init(mlxsw_sx);
if (err) {
dev_err(mlxsw_sx->bus_info->dev, "Failed to initialize flood tables\n");
goto err_flood_init;
}
return 0;
err_flood_init:
mlxsw_sx_traps_fini(mlxsw_sx);
err_listener_register:
mlxsw_sx_ports_remove(mlxsw_sx);
return err;
}
static void mlxsw_sx_fini(struct mlxsw_core *mlxsw_core)
{
struct mlxsw_sx *mlxsw_sx = mlxsw_core_driver_priv(mlxsw_core);
mlxsw_sx_traps_fini(mlxsw_sx);
mlxsw_sx_ports_remove(mlxsw_sx);
}
static int __init mlxsw_sx_module_init(void)
{
int err;
err = mlxsw_core_driver_register(&mlxsw_sx_driver);
if (err)
return err;
err = mlxsw_pci_driver_register(&mlxsw_sx_pci_driver);
if (err)
goto err_pci_driver_register;
return 0;
err_pci_driver_register:
mlxsw_core_driver_unregister(&mlxsw_sx_driver);
return err;
}
static void __exit mlxsw_sx_module_exit(void)
{
mlxsw_pci_driver_unregister(&mlxsw_sx_pci_driver);
mlxsw_core_driver_unregister(&mlxsw_sx_driver);
}
