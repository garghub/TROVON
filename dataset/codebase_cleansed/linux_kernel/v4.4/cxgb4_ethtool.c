static u32 get_msglevel(struct net_device *dev)
{
return netdev2adap(dev)->msg_enable;
}
static void set_msglevel(struct net_device *dev, u32 val)
{
netdev2adap(dev)->msg_enable = val;
}
static int get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(stats_strings) +
ARRAY_SIZE(adapter_stats_strings) +
ARRAY_SIZE(channel_stats_strings) +
ARRAY_SIZE(loopback_stats_strings);
default:
return -EOPNOTSUPP;
}
}
static int get_regs_len(struct net_device *dev)
{
struct adapter *adap = netdev2adap(dev);
return t4_get_regs_len(adap);
}
static int get_eeprom_len(struct net_device *dev)
{
return EEPROMSIZE;
}
static void get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct adapter *adapter = netdev2adap(dev);
u32 exprom_vers;
strlcpy(info->driver, cxgb4_driver_name, sizeof(info->driver));
strlcpy(info->version, cxgb4_driver_version,
sizeof(info->version));
strlcpy(info->bus_info, pci_name(adapter->pdev),
sizeof(info->bus_info));
info->regdump_len = get_regs_len(dev);
if (!adapter->params.fw_vers)
strcpy(info->fw_version, "N/A");
else
snprintf(info->fw_version, sizeof(info->fw_version),
"%u.%u.%u.%u, TP %u.%u.%u.%u",
FW_HDR_FW_VER_MAJOR_G(adapter->params.fw_vers),
FW_HDR_FW_VER_MINOR_G(adapter->params.fw_vers),
FW_HDR_FW_VER_MICRO_G(adapter->params.fw_vers),
FW_HDR_FW_VER_BUILD_G(adapter->params.fw_vers),
FW_HDR_FW_VER_MAJOR_G(adapter->params.tp_vers),
FW_HDR_FW_VER_MINOR_G(adapter->params.tp_vers),
FW_HDR_FW_VER_MICRO_G(adapter->params.tp_vers),
FW_HDR_FW_VER_BUILD_G(adapter->params.tp_vers));
if (!t4_get_exprom_version(adapter, &exprom_vers))
snprintf(info->erom_version, sizeof(info->erom_version),
"%u.%u.%u.%u",
FW_HDR_FW_VER_MAJOR_G(exprom_vers),
FW_HDR_FW_VER_MINOR_G(exprom_vers),
FW_HDR_FW_VER_MICRO_G(exprom_vers),
FW_HDR_FW_VER_BUILD_G(exprom_vers));
}
static void get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
if (stringset == ETH_SS_STATS) {
memcpy(data, stats_strings, sizeof(stats_strings));
data += sizeof(stats_strings);
memcpy(data, adapter_stats_strings,
sizeof(adapter_stats_strings));
data += sizeof(adapter_stats_strings);
memcpy(data, channel_stats_strings,
sizeof(channel_stats_strings));
data += sizeof(channel_stats_strings);
memcpy(data, loopback_stats_strings,
sizeof(loopback_stats_strings));
}
}
static void collect_sge_port_stats(const struct adapter *adap,
const struct port_info *p,
struct queue_port_stats *s)
{
int i;
const struct sge_eth_txq *tx = &adap->sge.ethtxq[p->first_qset];
const struct sge_eth_rxq *rx = &adap->sge.ethrxq[p->first_qset];
memset(s, 0, sizeof(*s));
for (i = 0; i < p->nqsets; i++, rx++, tx++) {
s->tso += tx->tso;
s->tx_csum += tx->tx_cso;
s->rx_csum += rx->stats.rx_cso;
s->vlan_ex += rx->stats.vlan_ex;
s->vlan_ins += tx->vlan_ins;
s->gro_pkts += rx->stats.lro_pkts;
s->gro_merged += rx->stats.lro_merged;
}
}
static void collect_adapter_stats(struct adapter *adap, struct adapter_stats *s)
{
struct tp_tcp_stats v4, v6;
struct tp_rdma_stats rdma_stats;
struct tp_err_stats err_stats;
struct tp_usm_stats usm_stats;
u64 val1, val2;
memset(s, 0, sizeof(*s));
spin_lock(&adap->stats_lock);
t4_tp_get_tcp_stats(adap, &v4, &v6);
t4_tp_get_rdma_stats(adap, &rdma_stats);
t4_get_usm_stats(adap, &usm_stats);
t4_tp_get_err_stats(adap, &err_stats);
spin_unlock(&adap->stats_lock);
s->db_drop = adap->db_stats.db_drop;
s->db_full = adap->db_stats.db_full;
s->db_empty = adap->db_stats.db_empty;
s->tcp_v4_out_rsts = v4.tcp_out_rsts;
s->tcp_v4_in_segs = v4.tcp_in_segs;
s->tcp_v4_out_segs = v4.tcp_out_segs;
s->tcp_v4_retrans_segs = v4.tcp_retrans_segs;
s->tcp_v6_out_rsts = v6.tcp_out_rsts;
s->tcp_v6_in_segs = v6.tcp_in_segs;
s->tcp_v6_out_segs = v6.tcp_out_segs;
s->tcp_v6_retrans_segs = v6.tcp_retrans_segs;
if (is_offload(adap)) {
s->frames = usm_stats.frames;
s->octets = usm_stats.octets;
s->drops = usm_stats.drops;
s->rqe_dfr_mod = rdma_stats.rqe_dfr_mod;
s->rqe_dfr_pkt = rdma_stats.rqe_dfr_pkt;
}
s->ofld_no_neigh = err_stats.ofld_no_neigh;
s->ofld_cong_defer = err_stats.ofld_cong_defer;
if (!is_t4(adap->params.chip)) {
int v;
v = t4_read_reg(adap, SGE_STAT_CFG_A);
if (STATSOURCE_T5_G(v) == 7) {
val2 = t4_read_reg(adap, SGE_STAT_MATCH_A);
val1 = t4_read_reg(adap, SGE_STAT_TOTAL_A);
s->wc_success = val1 - val2;
s->wc_fail = val2;
}
}
}
static void collect_channel_stats(struct adapter *adap, struct channel_stats *s,
u8 i)
{
struct tp_cpl_stats cpl_stats;
struct tp_err_stats err_stats;
struct tp_fcoe_stats fcoe_stats;
memset(s, 0, sizeof(*s));
spin_lock(&adap->stats_lock);
t4_tp_get_cpl_stats(adap, &cpl_stats);
t4_tp_get_err_stats(adap, &err_stats);
t4_get_fcoe_stats(adap, i, &fcoe_stats);
spin_unlock(&adap->stats_lock);
s->cpl_req = cpl_stats.req[i];
s->cpl_rsp = cpl_stats.rsp[i];
s->mac_in_errs = err_stats.mac_in_errs[i];
s->hdr_in_errs = err_stats.hdr_in_errs[i];
s->tcp_in_errs = err_stats.tcp_in_errs[i];
s->tcp6_in_errs = err_stats.tcp6_in_errs[i];
s->tnl_cong_drops = err_stats.tnl_cong_drops[i];
s->tnl_tx_drops = err_stats.tnl_tx_drops[i];
s->ofld_vlan_drops = err_stats.ofld_vlan_drops[i];
s->ofld_chan_drops = err_stats.ofld_chan_drops[i];
s->octets_ddp = fcoe_stats.octets_ddp;
s->frames_ddp = fcoe_stats.frames_ddp;
s->frames_drop = fcoe_stats.frames_drop;
}
static void get_stats(struct net_device *dev, struct ethtool_stats *stats,
u64 *data)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
struct lb_port_stats s;
int i;
u64 *p0;
t4_get_port_stats_offset(adapter, pi->tx_chan,
(struct port_stats *)data,
&pi->stats_base);
data += sizeof(struct port_stats) / sizeof(u64);
collect_sge_port_stats(adapter, pi, (struct queue_port_stats *)data);
data += sizeof(struct queue_port_stats) / sizeof(u64);
collect_adapter_stats(adapter, (struct adapter_stats *)data);
data += sizeof(struct adapter_stats) / sizeof(u64);
*data++ = (u64)pi->port_id;
collect_channel_stats(adapter, (struct channel_stats *)data,
pi->port_id);
data += sizeof(struct channel_stats) / sizeof(u64);
*data++ = (u64)pi->port_id;
memset(&s, 0, sizeof(s));
t4_get_lb_stats(adapter, pi->port_id, &s);
p0 = &s.octets;
for (i = 0; i < ARRAY_SIZE(loopback_stats_strings) - 1; i++)
*data++ = (unsigned long long)*p0++;
}
static void get_regs(struct net_device *dev, struct ethtool_regs *regs,
void *buf)
{
struct adapter *adap = netdev2adap(dev);
size_t buf_size;
buf_size = t4_get_regs_len(adap);
regs->version = mk_adap_vers(adap);
t4_get_regs(adap, buf, buf_size);
}
static int restart_autoneg(struct net_device *dev)
{
struct port_info *p = netdev_priv(dev);
if (!netif_running(dev))
return -EAGAIN;
if (p->link_cfg.autoneg != AUTONEG_ENABLE)
return -EINVAL;
t4_restart_aneg(p->adapter, p->adapter->pf, p->tx_chan);
return 0;
}
static int identify_port(struct net_device *dev,
enum ethtool_phys_id_state state)
{
unsigned int val;
struct adapter *adap = netdev2adap(dev);
if (state == ETHTOOL_ID_ACTIVE)
val = 0xffff;
else if (state == ETHTOOL_ID_INACTIVE)
val = 0;
else
return -EINVAL;
return t4_identify_port(adap, adap->pf, netdev2pinfo(dev)->viid, val);
}
static unsigned int from_fw_linkcaps(enum fw_port_type type, unsigned int caps)
{
unsigned int v = 0;
if (type == FW_PORT_TYPE_BT_SGMII || type == FW_PORT_TYPE_BT_XFI ||
type == FW_PORT_TYPE_BT_XAUI) {
v |= SUPPORTED_TP;
if (caps & FW_PORT_CAP_SPEED_100M)
v |= SUPPORTED_100baseT_Full;
if (caps & FW_PORT_CAP_SPEED_1G)
v |= SUPPORTED_1000baseT_Full;
if (caps & FW_PORT_CAP_SPEED_10G)
v |= SUPPORTED_10000baseT_Full;
} else if (type == FW_PORT_TYPE_KX4 || type == FW_PORT_TYPE_KX) {
v |= SUPPORTED_Backplane;
if (caps & FW_PORT_CAP_SPEED_1G)
v |= SUPPORTED_1000baseKX_Full;
if (caps & FW_PORT_CAP_SPEED_10G)
v |= SUPPORTED_10000baseKX4_Full;
} else if (type == FW_PORT_TYPE_KR) {
v |= SUPPORTED_Backplane | SUPPORTED_10000baseKR_Full;
} else if (type == FW_PORT_TYPE_BP_AP) {
v |= SUPPORTED_Backplane | SUPPORTED_10000baseR_FEC |
SUPPORTED_10000baseKR_Full | SUPPORTED_1000baseKX_Full;
} else if (type == FW_PORT_TYPE_BP4_AP) {
v |= SUPPORTED_Backplane | SUPPORTED_10000baseR_FEC |
SUPPORTED_10000baseKR_Full | SUPPORTED_1000baseKX_Full |
SUPPORTED_10000baseKX4_Full;
} else if (type == FW_PORT_TYPE_FIBER_XFI ||
type == FW_PORT_TYPE_FIBER_XAUI ||
type == FW_PORT_TYPE_SFP ||
type == FW_PORT_TYPE_QSFP_10G ||
type == FW_PORT_TYPE_QSA) {
v |= SUPPORTED_FIBRE;
if (caps & FW_PORT_CAP_SPEED_1G)
v |= SUPPORTED_1000baseT_Full;
if (caps & FW_PORT_CAP_SPEED_10G)
v |= SUPPORTED_10000baseT_Full;
} else if (type == FW_PORT_TYPE_BP40_BA ||
type == FW_PORT_TYPE_QSFP) {
v |= SUPPORTED_40000baseSR4_Full;
v |= SUPPORTED_FIBRE;
}
if (caps & FW_PORT_CAP_ANEG)
v |= SUPPORTED_Autoneg;
return v;
}
static unsigned int to_fw_linkcaps(unsigned int caps)
{
unsigned int v = 0;
if (caps & ADVERTISED_100baseT_Full)
v |= FW_PORT_CAP_SPEED_100M;
if (caps & ADVERTISED_1000baseT_Full)
v |= FW_PORT_CAP_SPEED_1G;
if (caps & ADVERTISED_10000baseT_Full)
v |= FW_PORT_CAP_SPEED_10G;
if (caps & ADVERTISED_40000baseSR4_Full)
v |= FW_PORT_CAP_SPEED_40G;
return v;
}
static int get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
const struct port_info *p = netdev_priv(dev);
if (p->port_type == FW_PORT_TYPE_BT_SGMII ||
p->port_type == FW_PORT_TYPE_BT_XFI ||
p->port_type == FW_PORT_TYPE_BT_XAUI) {
cmd->port = PORT_TP;
} else if (p->port_type == FW_PORT_TYPE_FIBER_XFI ||
p->port_type == FW_PORT_TYPE_FIBER_XAUI) {
cmd->port = PORT_FIBRE;
} else if (p->port_type == FW_PORT_TYPE_SFP ||
p->port_type == FW_PORT_TYPE_QSFP_10G ||
p->port_type == FW_PORT_TYPE_QSA ||
p->port_type == FW_PORT_TYPE_QSFP) {
if (p->mod_type == FW_PORT_MOD_TYPE_LR ||
p->mod_type == FW_PORT_MOD_TYPE_SR ||
p->mod_type == FW_PORT_MOD_TYPE_ER ||
p->mod_type == FW_PORT_MOD_TYPE_LRM)
cmd->port = PORT_FIBRE;
else if (p->mod_type == FW_PORT_MOD_TYPE_TWINAX_PASSIVE ||
p->mod_type == FW_PORT_MOD_TYPE_TWINAX_ACTIVE)
cmd->port = PORT_DA;
else
cmd->port = PORT_OTHER;
} else {
cmd->port = PORT_OTHER;
}
if (p->mdio_addr >= 0) {
cmd->phy_address = p->mdio_addr;
cmd->transceiver = XCVR_EXTERNAL;
cmd->mdio_support = p->port_type == FW_PORT_TYPE_BT_SGMII ?
MDIO_SUPPORTS_C22 : MDIO_SUPPORTS_C45;
} else {
cmd->phy_address = 0;
cmd->transceiver = XCVR_INTERNAL;
cmd->mdio_support = 0;
}
cmd->supported = from_fw_linkcaps(p->port_type, p->link_cfg.supported);
cmd->advertising = from_fw_linkcaps(p->port_type,
p->link_cfg.advertising);
ethtool_cmd_speed_set(cmd,
netif_carrier_ok(dev) ? p->link_cfg.speed : 0);
cmd->duplex = DUPLEX_FULL;
cmd->autoneg = p->link_cfg.autoneg;
cmd->maxtxpkt = 0;
cmd->maxrxpkt = 0;
return 0;
}
static unsigned int speed_to_caps(int speed)
{
if (speed == 100)
return FW_PORT_CAP_SPEED_100M;
if (speed == 1000)
return FW_PORT_CAP_SPEED_1G;
if (speed == 10000)
return FW_PORT_CAP_SPEED_10G;
if (speed == 40000)
return FW_PORT_CAP_SPEED_40G;
return 0;
}
static int set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
unsigned int cap;
struct port_info *p = netdev_priv(dev);
struct link_config *lc = &p->link_cfg;
u32 speed = ethtool_cmd_speed(cmd);
struct link_config old_lc;
int ret;
if (cmd->duplex != DUPLEX_FULL)
return -EINVAL;
if (!(lc->supported & FW_PORT_CAP_ANEG)) {
if (cmd->autoneg == AUTONEG_DISABLE &&
(lc->supported & speed_to_caps(speed)))
return 0;
return -EINVAL;
}
old_lc = *lc;
if (cmd->autoneg == AUTONEG_DISABLE) {
cap = speed_to_caps(speed);
if (!(lc->supported & cap))
return -EINVAL;
lc->requested_speed = cap;
lc->advertising = 0;
} else {
cap = to_fw_linkcaps(cmd->advertising);
if (!(lc->supported & cap))
return -EINVAL;
lc->requested_speed = 0;
lc->advertising = cap | FW_PORT_CAP_ANEG;
}
lc->autoneg = cmd->autoneg;
ret = t4_link_l1cfg(p->adapter, p->adapter->mbox, p->tx_chan, lc);
if (ret)
*lc = old_lc;
return ret;
}
static void get_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
struct port_info *p = netdev_priv(dev);
epause->autoneg = (p->link_cfg.requested_fc & PAUSE_AUTONEG) != 0;
epause->rx_pause = (p->link_cfg.fc & PAUSE_RX) != 0;
epause->tx_pause = (p->link_cfg.fc & PAUSE_TX) != 0;
}
static int set_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
struct port_info *p = netdev_priv(dev);
struct link_config *lc = &p->link_cfg;
if (epause->autoneg == AUTONEG_DISABLE)
lc->requested_fc = 0;
else if (lc->supported & FW_PORT_CAP_ANEG)
lc->requested_fc = PAUSE_AUTONEG;
else
return -EINVAL;
if (epause->rx_pause)
lc->requested_fc |= PAUSE_RX;
if (epause->tx_pause)
lc->requested_fc |= PAUSE_TX;
if (netif_running(dev))
return t4_link_l1cfg(p->adapter, p->adapter->pf, p->tx_chan,
lc);
return 0;
}
static void get_sge_param(struct net_device *dev, struct ethtool_ringparam *e)
{
const struct port_info *pi = netdev_priv(dev);
const struct sge *s = &pi->adapter->sge;
e->rx_max_pending = MAX_RX_BUFFERS;
e->rx_mini_max_pending = MAX_RSPQ_ENTRIES;
e->rx_jumbo_max_pending = 0;
e->tx_max_pending = MAX_TXQ_ENTRIES;
e->rx_pending = s->ethrxq[pi->first_qset].fl.size - 8;
e->rx_mini_pending = s->ethrxq[pi->first_qset].rspq.size;
e->rx_jumbo_pending = 0;
e->tx_pending = s->ethtxq[pi->first_qset].q.size;
}
static int set_sge_param(struct net_device *dev, struct ethtool_ringparam *e)
{
int i;
const struct port_info *pi = netdev_priv(dev);
struct adapter *adapter = pi->adapter;
struct sge *s = &adapter->sge;
if (e->rx_pending > MAX_RX_BUFFERS || e->rx_jumbo_pending ||
e->tx_pending > MAX_TXQ_ENTRIES ||
e->rx_mini_pending > MAX_RSPQ_ENTRIES ||
e->rx_mini_pending < MIN_RSPQ_ENTRIES ||
e->rx_pending < MIN_FL_ENTRIES || e->tx_pending < MIN_TXQ_ENTRIES)
return -EINVAL;
if (adapter->flags & FULL_INIT_DONE)
return -EBUSY;
for (i = 0; i < pi->nqsets; ++i) {
s->ethtxq[pi->first_qset + i].q.size = e->tx_pending;
s->ethrxq[pi->first_qset + i].fl.size = e->rx_pending + 8;
s->ethrxq[pi->first_qset + i].rspq.size = e->rx_mini_pending;
}
return 0;
}
static int set_rx_intr_params(struct net_device *dev,
unsigned int us, unsigned int cnt)
{
int i, err;
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
struct sge_eth_rxq *q = &adap->sge.ethrxq[pi->first_qset];
for (i = 0; i < pi->nqsets; i++, q++) {
err = cxgb4_set_rspq_intr_params(&q->rspq, us, cnt);
if (err)
return err;
}
return 0;
}
static int set_adaptive_rx_setting(struct net_device *dev, int adaptive_rx)
{
int i;
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
struct sge_eth_rxq *q = &adap->sge.ethrxq[pi->first_qset];
for (i = 0; i < pi->nqsets; i++, q++)
q->rspq.adaptive_rx = adaptive_rx;
return 0;
}
static int get_adaptive_rx_setting(struct net_device *dev)
{
struct port_info *pi = netdev_priv(dev);
struct adapter *adap = pi->adapter;
struct sge_eth_rxq *q = &adap->sge.ethrxq[pi->first_qset];
return q->rspq.adaptive_rx;
}
static int set_coalesce(struct net_device *dev, struct ethtool_coalesce *c)
{
set_adaptive_rx_setting(dev, c->use_adaptive_rx_coalesce);
return set_rx_intr_params(dev, c->rx_coalesce_usecs,
c->rx_max_coalesced_frames);
}
static int get_coalesce(struct net_device *dev, struct ethtool_coalesce *c)
{
const struct port_info *pi = netdev_priv(dev);
const struct adapter *adap = pi->adapter;
const struct sge_rspq *rq = &adap->sge.ethrxq[pi->first_qset].rspq;
c->rx_coalesce_usecs = qtimer_val(adap, rq);
c->rx_max_coalesced_frames = (rq->intr_params & QINTR_CNT_EN_F) ?
adap->sge.counter_val[rq->pktcnt_idx] : 0;
c->use_adaptive_rx_coalesce = get_adaptive_rx_setting(dev);
return 0;
}
static int eeprom_ptov(unsigned int phys_addr, unsigned int fn, unsigned int sz)
{
fn *= sz;
if (phys_addr < 1024)
return phys_addr + (31 << 10);
if (phys_addr < 1024 + fn)
return 31744 - fn + phys_addr - 1024;
if (phys_addr < EEPROMSIZE)
return phys_addr - 1024 - fn;
return -EINVAL;
}
static int eeprom_rd_phys(struct adapter *adap, unsigned int phys_addr, u32 *v)
{
int vaddr = eeprom_ptov(phys_addr, adap->pf, EEPROMPFSIZE);
if (vaddr >= 0)
vaddr = pci_read_vpd(adap->pdev, vaddr, sizeof(u32), v);
return vaddr < 0 ? vaddr : 0;
}
static int eeprom_wr_phys(struct adapter *adap, unsigned int phys_addr, u32 v)
{
int vaddr = eeprom_ptov(phys_addr, adap->pf, EEPROMPFSIZE);
if (vaddr >= 0)
vaddr = pci_write_vpd(adap->pdev, vaddr, sizeof(u32), &v);
return vaddr < 0 ? vaddr : 0;
}
static int get_eeprom(struct net_device *dev, struct ethtool_eeprom *e,
u8 *data)
{
int i, err = 0;
struct adapter *adapter = netdev2adap(dev);
u8 *buf = t4_alloc_mem(EEPROMSIZE);
if (!buf)
return -ENOMEM;
e->magic = EEPROM_MAGIC;
for (i = e->offset & ~3; !err && i < e->offset + e->len; i += 4)
err = eeprom_rd_phys(adapter, i, (u32 *)&buf[i]);
if (!err)
memcpy(data, buf + e->offset, e->len);
t4_free_mem(buf);
return err;
}
static int set_eeprom(struct net_device *dev, struct ethtool_eeprom *eeprom,
u8 *data)
{
u8 *buf;
int err = 0;
u32 aligned_offset, aligned_len, *p;
struct adapter *adapter = netdev2adap(dev);
if (eeprom->magic != EEPROM_MAGIC)
return -EINVAL;
aligned_offset = eeprom->offset & ~3;
aligned_len = (eeprom->len + (eeprom->offset & 3) + 3) & ~3;
if (adapter->pf > 0) {
u32 start = 1024 + adapter->pf * EEPROMPFSIZE;
if (aligned_offset < start ||
aligned_offset + aligned_len > start + EEPROMPFSIZE)
return -EPERM;
}
if (aligned_offset != eeprom->offset || aligned_len != eeprom->len) {
buf = t4_alloc_mem(aligned_len);
if (!buf)
return -ENOMEM;
err = eeprom_rd_phys(adapter, aligned_offset, (u32 *)buf);
if (!err && aligned_len > 4)
err = eeprom_rd_phys(adapter,
aligned_offset + aligned_len - 4,
(u32 *)&buf[aligned_len - 4]);
if (err)
goto out;
memcpy(buf + (eeprom->offset & 3), data, eeprom->len);
} else {
buf = data;
}
err = t4_seeprom_wp(adapter, false);
if (err)
goto out;
for (p = (u32 *)buf; !err && aligned_len; aligned_len -= 4, p++) {
err = eeprom_wr_phys(adapter, aligned_offset, *p);
aligned_offset += 4;
}
if (!err)
err = t4_seeprom_wp(adapter, true);
out:
if (buf != data)
t4_free_mem(buf);
return err;
}
static int set_flash(struct net_device *netdev, struct ethtool_flash *ef)
{
int ret;
const struct firmware *fw;
struct adapter *adap = netdev2adap(netdev);
unsigned int mbox = PCIE_FW_MASTER_M + 1;
u32 pcie_fw;
unsigned int master;
u8 master_vld = 0;
pcie_fw = t4_read_reg(adap, PCIE_FW_A);
master = PCIE_FW_MASTER_G(pcie_fw);
if (pcie_fw & PCIE_FW_MASTER_VLD_F)
master_vld = 1;
if (master_vld && (master != adap->pf)) {
dev_warn(adap->pdev_dev,
"cxgb4 driver needs to be loaded as MASTER to support FW flash\n");
return -EOPNOTSUPP;
}
ef->data[sizeof(ef->data) - 1] = '\0';
ret = request_firmware(&fw, ef->data, adap->pdev_dev);
if (ret < 0)
return ret;
if (adap->flags & FULL_INIT_DONE)
mbox = adap->mbox;
ret = t4_fw_upgrade(adap, mbox, fw->data, fw->size, 1);
release_firmware(fw);
if (!ret)
dev_info(adap->pdev_dev,
"loaded firmware %s, reload cxgb4 driver\n", ef->data);
return ret;
}
static int get_ts_info(struct net_device *dev, struct ethtool_ts_info *ts_info)
{
ts_info->so_timestamping = SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE;
ts_info->so_timestamping |= SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
ts_info->phc_index = -1;
return 0;
}
static u32 get_rss_table_size(struct net_device *dev)
{
const struct port_info *pi = netdev_priv(dev);
return pi->rss_size;
}
static int get_rss_table(struct net_device *dev, u32 *p, u8 *key, u8 *hfunc)
{
const struct port_info *pi = netdev_priv(dev);
unsigned int n = pi->rss_size;
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
if (!p)
return 0;
while (n--)
p[n] = pi->rss[n];
return 0;
}
static int set_rss_table(struct net_device *dev, const u32 *p, const u8 *key,
const u8 hfunc)
{
unsigned int i;
struct port_info *pi = netdev_priv(dev);
if (key ||
(hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP))
return -EOPNOTSUPP;
if (!p)
return 0;
if (pi->adapter->flags & FULL_INIT_DONE) {
for (i = 0; i < pi->rss_size; i++)
pi->rss[i] = p[i];
return cxgb4_write_rss(pi, pi->rss);
}
return -EPERM;
}
static int get_rxnfc(struct net_device *dev, struct ethtool_rxnfc *info,
u32 *rules)
{
const struct port_info *pi = netdev_priv(dev);
switch (info->cmd) {
case ETHTOOL_GRXFH: {
unsigned int v = pi->rss_mode;
info->data = 0;
switch (info->flow_type) {
case TCP_V4_FLOW:
if (v & FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_F)
info->data = RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3;
else if (v & FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_F)
info->data = RXH_IP_SRC | RXH_IP_DST;
break;
case UDP_V4_FLOW:
if ((v & FW_RSS_VI_CONFIG_CMD_IP4FOURTUPEN_F) &&
(v & FW_RSS_VI_CONFIG_CMD_UDPEN_F))
info->data = RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3;
else if (v & FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_F)
info->data = RXH_IP_SRC | RXH_IP_DST;
break;
case SCTP_V4_FLOW:
case AH_ESP_V4_FLOW:
case IPV4_FLOW:
if (v & FW_RSS_VI_CONFIG_CMD_IP4TWOTUPEN_F)
info->data = RXH_IP_SRC | RXH_IP_DST;
break;
case TCP_V6_FLOW:
if (v & FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_F)
info->data = RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3;
else if (v & FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_F)
info->data = RXH_IP_SRC | RXH_IP_DST;
break;
case UDP_V6_FLOW:
if ((v & FW_RSS_VI_CONFIG_CMD_IP6FOURTUPEN_F) &&
(v & FW_RSS_VI_CONFIG_CMD_UDPEN_F))
info->data = RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3;
else if (v & FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_F)
info->data = RXH_IP_SRC | RXH_IP_DST;
break;
case SCTP_V6_FLOW:
case AH_ESP_V6_FLOW:
case IPV6_FLOW:
if (v & FW_RSS_VI_CONFIG_CMD_IP6TWOTUPEN_F)
info->data = RXH_IP_SRC | RXH_IP_DST;
break;
}
return 0;
}
case ETHTOOL_GRXRINGS:
info->data = pi->nqsets;
return 0;
}
return -EOPNOTSUPP;
}
void cxgb4_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &cxgb_ethtool_ops;
}
