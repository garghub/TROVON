static void gfar_gstrings(struct net_device *dev, u32 stringset, u8 * buf)
{
struct gfar_private *priv = netdev_priv(dev);
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_RMON)
memcpy(buf, stat_gstrings, GFAR_STATS_LEN * ETH_GSTRING_LEN);
else
memcpy(buf, stat_gstrings,
GFAR_EXTRA_STATS_LEN * ETH_GSTRING_LEN);
}
static void gfar_fill_stats(struct net_device *dev, struct ethtool_stats *dummy, u64 * buf)
{
int i;
struct gfar_private *priv = netdev_priv(dev);
struct gfar __iomem *regs = priv->gfargrp[0].regs;
u64 *extra = (u64 *) & priv->extra_stats;
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_RMON) {
u32 __iomem *rmon = (u32 __iomem *) &regs->rmon;
struct gfar_stats *stats = (struct gfar_stats *) buf;
for (i = 0; i < GFAR_RMON_LEN; i++)
stats->rmon[i] = (u64) gfar_read(&rmon[i]);
for (i = 0; i < GFAR_EXTRA_STATS_LEN; i++)
stats->extra[i] = extra[i];
} else
for (i = 0; i < GFAR_EXTRA_STATS_LEN; i++)
buf[i] = extra[i];
}
static int gfar_sset_count(struct net_device *dev, int sset)
{
struct gfar_private *priv = netdev_priv(dev);
switch (sset) {
case ETH_SS_STATS:
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_RMON)
return GFAR_STATS_LEN;
else
return GFAR_EXTRA_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void gfar_gdrvinfo(struct net_device *dev, struct
ethtool_drvinfo *drvinfo)
{
strncpy(drvinfo->driver, DRV_NAME, GFAR_INFOSTR_LEN);
strncpy(drvinfo->version, gfar_driver_version, GFAR_INFOSTR_LEN);
strncpy(drvinfo->fw_version, "N/A", GFAR_INFOSTR_LEN);
strncpy(drvinfo->bus_info, "N/A", GFAR_INFOSTR_LEN);
drvinfo->regdump_len = 0;
drvinfo->eedump_len = 0;
}
static int gfar_ssettings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct gfar_private *priv = netdev_priv(dev);
struct phy_device *phydev = priv->phydev;
if (NULL == phydev)
return -ENODEV;
return phy_ethtool_sset(phydev, cmd);
}
static int gfar_gsettings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct gfar_private *priv = netdev_priv(dev);
struct phy_device *phydev = priv->phydev;
struct gfar_priv_rx_q *rx_queue = NULL;
struct gfar_priv_tx_q *tx_queue = NULL;
if (NULL == phydev)
return -ENODEV;
tx_queue = priv->tx_queue[0];
rx_queue = priv->rx_queue[0];
cmd->maxtxpkt = get_icft_value(tx_queue->txic);
cmd->maxrxpkt = get_icft_value(rx_queue->rxic);
return phy_ethtool_gset(phydev, cmd);
}
static int gfar_reglen(struct net_device *dev)
{
return sizeof (struct gfar);
}
static void gfar_get_regs(struct net_device *dev, struct ethtool_regs *regs, void *regbuf)
{
int i;
struct gfar_private *priv = netdev_priv(dev);
u32 __iomem *theregs = (u32 __iomem *) priv->gfargrp[0].regs;
u32 *buf = (u32 *) regbuf;
for (i = 0; i < sizeof (struct gfar) / sizeof (u32); i++)
buf[i] = gfar_read(&theregs[i]);
}
static unsigned int gfar_usecs2ticks(struct gfar_private *priv, unsigned int usecs)
{
unsigned int count;
switch (priv->phydev->speed) {
case SPEED_1000:
count = GFAR_GBIT_TIME;
break;
case SPEED_100:
count = GFAR_100_TIME;
break;
case SPEED_10:
default:
count = GFAR_10_TIME;
break;
}
return (usecs * 1000 + count - 1) / count;
}
static unsigned int gfar_ticks2usecs(struct gfar_private *priv, unsigned int ticks)
{
unsigned int count;
switch (priv->phydev->speed) {
case SPEED_1000:
count = GFAR_GBIT_TIME;
break;
case SPEED_100:
count = GFAR_100_TIME;
break;
case SPEED_10:
default:
count = GFAR_10_TIME;
break;
}
return (ticks * count) / 1000;
}
static int gfar_gcoalesce(struct net_device *dev, struct ethtool_coalesce *cvals)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar_priv_rx_q *rx_queue = NULL;
struct gfar_priv_tx_q *tx_queue = NULL;
unsigned long rxtime;
unsigned long rxcount;
unsigned long txtime;
unsigned long txcount;
if (!(priv->device_flags & FSL_GIANFAR_DEV_HAS_COALESCE))
return -EOPNOTSUPP;
if (NULL == priv->phydev)
return -ENODEV;
rx_queue = priv->rx_queue[0];
tx_queue = priv->tx_queue[0];
rxtime = get_ictt_value(rx_queue->rxic);
rxcount = get_icft_value(rx_queue->rxic);
txtime = get_ictt_value(tx_queue->txic);
txcount = get_icft_value(tx_queue->txic);
cvals->rx_coalesce_usecs = gfar_ticks2usecs(priv, rxtime);
cvals->rx_max_coalesced_frames = rxcount;
cvals->tx_coalesce_usecs = gfar_ticks2usecs(priv, txtime);
cvals->tx_max_coalesced_frames = txcount;
cvals->use_adaptive_rx_coalesce = 0;
cvals->use_adaptive_tx_coalesce = 0;
cvals->pkt_rate_low = 0;
cvals->rx_coalesce_usecs_low = 0;
cvals->rx_max_coalesced_frames_low = 0;
cvals->tx_coalesce_usecs_low = 0;
cvals->tx_max_coalesced_frames_low = 0;
cvals->pkt_rate_high = 0;
cvals->rx_coalesce_usecs_high = 0;
cvals->rx_max_coalesced_frames_high = 0;
cvals->tx_coalesce_usecs_high = 0;
cvals->tx_max_coalesced_frames_high = 0;
cvals->rate_sample_interval = 0;
return 0;
}
static int gfar_scoalesce(struct net_device *dev, struct ethtool_coalesce *cvals)
{
struct gfar_private *priv = netdev_priv(dev);
int i = 0;
if (!(priv->device_flags & FSL_GIANFAR_DEV_HAS_COALESCE))
return -EOPNOTSUPP;
if ((cvals->rx_coalesce_usecs == 0) ||
(cvals->rx_max_coalesced_frames == 0)) {
for (i = 0; i < priv->num_rx_queues; i++)
priv->rx_queue[i]->rxcoalescing = 0;
} else {
for (i = 0; i < priv->num_rx_queues; i++)
priv->rx_queue[i]->rxcoalescing = 1;
}
if (NULL == priv->phydev)
return -ENODEV;
if (cvals->rx_coalesce_usecs > GFAR_MAX_COAL_USECS) {
pr_info("Coalescing is limited to %d microseconds\n",
GFAR_MAX_COAL_USECS);
return -EINVAL;
}
if (cvals->rx_max_coalesced_frames > GFAR_MAX_COAL_FRAMES) {
pr_info("Coalescing is limited to %d frames\n",
GFAR_MAX_COAL_FRAMES);
return -EINVAL;
}
for (i = 0; i < priv->num_rx_queues; i++) {
priv->rx_queue[i]->rxic = mk_ic_value(
cvals->rx_max_coalesced_frames,
gfar_usecs2ticks(priv, cvals->rx_coalesce_usecs));
}
if ((cvals->tx_coalesce_usecs == 0) ||
(cvals->tx_max_coalesced_frames == 0)) {
for (i = 0; i < priv->num_tx_queues; i++)
priv->tx_queue[i]->txcoalescing = 0;
} else {
for (i = 0; i < priv->num_tx_queues; i++)
priv->tx_queue[i]->txcoalescing = 1;
}
if (cvals->tx_coalesce_usecs > GFAR_MAX_COAL_USECS) {
pr_info("Coalescing is limited to %d microseconds\n",
GFAR_MAX_COAL_USECS);
return -EINVAL;
}
if (cvals->tx_max_coalesced_frames > GFAR_MAX_COAL_FRAMES) {
pr_info("Coalescing is limited to %d frames\n",
GFAR_MAX_COAL_FRAMES);
return -EINVAL;
}
for (i = 0; i < priv->num_tx_queues; i++) {
priv->tx_queue[i]->txic = mk_ic_value(
cvals->tx_max_coalesced_frames,
gfar_usecs2ticks(priv, cvals->tx_coalesce_usecs));
}
gfar_configure_coalescing(priv, 0xFF, 0xFF);
return 0;
}
static void gfar_gringparam(struct net_device *dev, struct ethtool_ringparam *rvals)
{
struct gfar_private *priv = netdev_priv(dev);
struct gfar_priv_tx_q *tx_queue = NULL;
struct gfar_priv_rx_q *rx_queue = NULL;
tx_queue = priv->tx_queue[0];
rx_queue = priv->rx_queue[0];
rvals->rx_max_pending = GFAR_RX_MAX_RING_SIZE;
rvals->rx_mini_max_pending = GFAR_RX_MAX_RING_SIZE;
rvals->rx_jumbo_max_pending = GFAR_RX_MAX_RING_SIZE;
rvals->tx_max_pending = GFAR_TX_MAX_RING_SIZE;
rvals->rx_pending = rx_queue->rx_ring_size;
rvals->rx_mini_pending = rx_queue->rx_ring_size;
rvals->rx_jumbo_pending = rx_queue->rx_ring_size;
rvals->tx_pending = tx_queue->tx_ring_size;
}
static int gfar_sringparam(struct net_device *dev, struct ethtool_ringparam *rvals)
{
struct gfar_private *priv = netdev_priv(dev);
int err = 0, i = 0;
if (rvals->rx_pending > GFAR_RX_MAX_RING_SIZE)
return -EINVAL;
if (!is_power_of_2(rvals->rx_pending)) {
printk("%s: Ring sizes must be a power of 2\n",
dev->name);
return -EINVAL;
}
if (rvals->tx_pending > GFAR_TX_MAX_RING_SIZE)
return -EINVAL;
if (!is_power_of_2(rvals->tx_pending)) {
printk("%s: Ring sizes must be a power of 2\n",
dev->name);
return -EINVAL;
}
if (dev->flags & IFF_UP) {
unsigned long flags;
local_irq_save(flags);
lock_tx_qs(priv);
lock_rx_qs(priv);
gfar_halt(dev);
unlock_rx_qs(priv);
unlock_tx_qs(priv);
local_irq_restore(flags);
for (i = 0; i < priv->num_rx_queues; i++)
gfar_clean_rx_ring(priv->rx_queue[i],
priv->rx_queue[i]->rx_ring_size);
stop_gfar(dev);
}
for (i = 0; i < priv->num_rx_queues; i++) {
priv->rx_queue[i]->rx_ring_size = rvals->rx_pending;
priv->tx_queue[i]->tx_ring_size = rvals->tx_pending;
priv->tx_queue[i]->num_txbdfree = priv->tx_queue[i]->tx_ring_size;
}
if (dev->flags & IFF_UP) {
err = startup_gfar(dev);
netif_tx_wake_all_queues(dev);
}
return err;
}
int gfar_set_features(struct net_device *dev, u32 features)
{
struct gfar_private *priv = netdev_priv(dev);
unsigned long flags;
int err = 0, i = 0;
u32 changed = dev->features ^ features;
if (!(changed & NETIF_F_RXCSUM))
return 0;
if (dev->flags & IFF_UP) {
local_irq_save(flags);
lock_tx_qs(priv);
lock_rx_qs(priv);
gfar_halt(dev);
unlock_tx_qs(priv);
unlock_rx_qs(priv);
local_irq_restore(flags);
for (i = 0; i < priv->num_rx_queues; i++)
gfar_clean_rx_ring(priv->rx_queue[i],
priv->rx_queue[i]->rx_ring_size);
stop_gfar(dev);
dev->features = features;
err = startup_gfar(dev);
netif_tx_wake_all_queues(dev);
}
return err;
}
static uint32_t gfar_get_msglevel(struct net_device *dev)
{
struct gfar_private *priv = netdev_priv(dev);
return priv->msg_enable;
}
static void gfar_set_msglevel(struct net_device *dev, uint32_t data)
{
struct gfar_private *priv = netdev_priv(dev);
priv->msg_enable = data;
}
static void gfar_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct gfar_private *priv = netdev_priv(dev);
if (priv->device_flags & FSL_GIANFAR_DEV_HAS_MAGIC_PACKET) {
wol->supported = WAKE_MAGIC;
wol->wolopts = priv->wol_en ? WAKE_MAGIC : 0;
} else {
wol->supported = wol->wolopts = 0;
}
}
static int gfar_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct gfar_private *priv = netdev_priv(dev);
unsigned long flags;
if (!(priv->device_flags & FSL_GIANFAR_DEV_HAS_MAGIC_PACKET) &&
wol->wolopts != 0)
return -EINVAL;
if (wol->wolopts & ~WAKE_MAGIC)
return -EINVAL;
device_set_wakeup_enable(&dev->dev, wol->wolopts & WAKE_MAGIC);
spin_lock_irqsave(&priv->bflock, flags);
priv->wol_en = !!device_may_wakeup(&dev->dev);
spin_unlock_irqrestore(&priv->bflock, flags);
return 0;
}
static void ethflow_to_filer_rules (struct gfar_private *priv, u64 ethflow)
{
u32 fcr = 0x0, fpr = FPR_FILER_MASK;
if (ethflow & RXH_L2DA) {
fcr = RQFCR_PID_DAH |RQFCR_CMP_NOMATCH |
RQFCR_HASH | RQFCR_AND | RQFCR_HASHTBL_0;
priv->ftp_rqfpr[priv->cur_filer_idx] = fpr;
priv->ftp_rqfcr[priv->cur_filer_idx] = fcr;
gfar_write_filer(priv, priv->cur_filer_idx, fcr, fpr);
priv->cur_filer_idx = priv->cur_filer_idx - 1;
fcr = RQFCR_PID_DAL | RQFCR_AND | RQFCR_CMP_NOMATCH |
RQFCR_HASH | RQFCR_AND | RQFCR_HASHTBL_0;
priv->ftp_rqfpr[priv->cur_filer_idx] = fpr;
priv->ftp_rqfcr[priv->cur_filer_idx] = fcr;
gfar_write_filer(priv, priv->cur_filer_idx, fcr, fpr);
priv->cur_filer_idx = priv->cur_filer_idx - 1;
}
if (ethflow & RXH_VLAN) {
fcr = RQFCR_PID_VID | RQFCR_CMP_NOMATCH | RQFCR_HASH |
RQFCR_AND | RQFCR_HASHTBL_0;
gfar_write_filer(priv, priv->cur_filer_idx, fcr, fpr);
priv->ftp_rqfpr[priv->cur_filer_idx] = fpr;
priv->ftp_rqfcr[priv->cur_filer_idx] = fcr;
priv->cur_filer_idx = priv->cur_filer_idx - 1;
}
if (ethflow & RXH_IP_SRC) {
fcr = RQFCR_PID_SIA | RQFCR_CMP_NOMATCH | RQFCR_HASH |
RQFCR_AND | RQFCR_HASHTBL_0;
priv->ftp_rqfpr[priv->cur_filer_idx] = fpr;
priv->ftp_rqfcr[priv->cur_filer_idx] = fcr;
gfar_write_filer(priv, priv->cur_filer_idx, fcr, fpr);
priv->cur_filer_idx = priv->cur_filer_idx - 1;
}
if (ethflow & (RXH_IP_DST)) {
fcr = RQFCR_PID_DIA | RQFCR_CMP_NOMATCH | RQFCR_HASH |
RQFCR_AND | RQFCR_HASHTBL_0;
priv->ftp_rqfpr[priv->cur_filer_idx] = fpr;
priv->ftp_rqfcr[priv->cur_filer_idx] = fcr;
gfar_write_filer(priv, priv->cur_filer_idx, fcr, fpr);
priv->cur_filer_idx = priv->cur_filer_idx - 1;
}
if (ethflow & RXH_L3_PROTO) {
fcr = RQFCR_PID_L4P | RQFCR_CMP_NOMATCH | RQFCR_HASH |
RQFCR_AND | RQFCR_HASHTBL_0;
priv->ftp_rqfpr[priv->cur_filer_idx] = fpr;
priv->ftp_rqfcr[priv->cur_filer_idx] = fcr;
gfar_write_filer(priv, priv->cur_filer_idx, fcr, fpr);
priv->cur_filer_idx = priv->cur_filer_idx - 1;
}
if (ethflow & RXH_L4_B_0_1) {
fcr = RQFCR_PID_SPT | RQFCR_CMP_NOMATCH | RQFCR_HASH |
RQFCR_AND | RQFCR_HASHTBL_0;
priv->ftp_rqfpr[priv->cur_filer_idx] = fpr;
priv->ftp_rqfcr[priv->cur_filer_idx] = fcr;
gfar_write_filer(priv, priv->cur_filer_idx, fcr, fpr);
priv->cur_filer_idx = priv->cur_filer_idx - 1;
}
if (ethflow & RXH_L4_B_2_3) {
fcr = RQFCR_PID_DPT | RQFCR_CMP_NOMATCH | RQFCR_HASH |
RQFCR_AND | RQFCR_HASHTBL_0;
priv->ftp_rqfpr[priv->cur_filer_idx] = fpr;
priv->ftp_rqfcr[priv->cur_filer_idx] = fcr;
gfar_write_filer(priv, priv->cur_filer_idx, fcr, fpr);
priv->cur_filer_idx = priv->cur_filer_idx - 1;
}
}
static int gfar_ethflow_to_filer_table(struct gfar_private *priv, u64 ethflow, u64 class)
{
unsigned int last_rule_idx = priv->cur_filer_idx;
unsigned int cmp_rqfpr;
unsigned int local_rqfpr[MAX_FILER_IDX + 1];
unsigned int local_rqfcr[MAX_FILER_IDX + 1];
int i = 0x0, k = 0x0;
int j = MAX_FILER_IDX, l = 0x0;
switch (class) {
case TCP_V4_FLOW:
cmp_rqfpr = RQFPR_IPV4 |RQFPR_TCP;
break;
case UDP_V4_FLOW:
cmp_rqfpr = RQFPR_IPV4 |RQFPR_UDP;
break;
case TCP_V6_FLOW:
cmp_rqfpr = RQFPR_IPV6 |RQFPR_TCP;
break;
case UDP_V6_FLOW:
cmp_rqfpr = RQFPR_IPV6 |RQFPR_UDP;
break;
default:
printk(KERN_ERR "Right now this class is not supported\n");
return 0;
}
for (i = 0; i < MAX_FILER_IDX + 1; i++) {
local_rqfpr[j] = priv->ftp_rqfpr[i];
local_rqfcr[j] = priv->ftp_rqfcr[i];
j--;
if ((priv->ftp_rqfcr[i] == (RQFCR_PID_PARSE |
RQFCR_CLE |RQFCR_AND)) &&
(priv->ftp_rqfpr[i] == cmp_rqfpr))
break;
}
if (i == MAX_FILER_IDX + 1) {
printk(KERN_ERR "No parse rule found, ");
printk(KERN_ERR "can't create hash rules\n");
return 0;
}
for (l = i+1; l < MAX_FILER_IDX; l++) {
if ((priv->ftp_rqfcr[l] & RQFCR_CLE) &&
!(priv->ftp_rqfcr[l] & RQFCR_AND)) {
priv->ftp_rqfcr[l] = RQFCR_CLE | RQFCR_CMP_EXACT |
RQFCR_HASHTBL_0 | RQFCR_PID_MASK;
priv->ftp_rqfpr[l] = FPR_FILER_MASK;
gfar_write_filer(priv, l, priv->ftp_rqfcr[l],
priv->ftp_rqfpr[l]);
break;
}
if (!(priv->ftp_rqfcr[l] & RQFCR_CLE) &&
(priv->ftp_rqfcr[l] & RQFCR_AND))
continue;
else {
local_rqfpr[j] = priv->ftp_rqfpr[l];
local_rqfcr[j] = priv->ftp_rqfcr[l];
j--;
}
}
priv->cur_filer_idx = l - 1;
last_rule_idx = l;
ethflow_to_filer_rules(priv, ethflow);
for (k = j+1; k < MAX_FILER_IDX; k++) {
priv->ftp_rqfpr[priv->cur_filer_idx] = local_rqfpr[k];
priv->ftp_rqfcr[priv->cur_filer_idx] = local_rqfcr[k];
gfar_write_filer(priv, priv->cur_filer_idx,
local_rqfcr[k], local_rqfpr[k]);
if (!priv->cur_filer_idx)
break;
priv->cur_filer_idx = priv->cur_filer_idx - 1;
}
return 1;
}
static int gfar_set_hash_opts(struct gfar_private *priv, struct ethtool_rxnfc *cmd)
{
if (!gfar_ethflow_to_filer_table(priv, cmd->data, cmd->flow_type))
return -EINVAL;
return 0;
}
static int gfar_set_nfc(struct net_device *dev, struct ethtool_rxnfc *cmd)
{
struct gfar_private *priv = netdev_priv(dev);
int ret = 0;
switch(cmd->cmd) {
case ETHTOOL_SRXFH:
ret = gfar_set_hash_opts(priv, cmd);
break;
default:
ret = -EINVAL;
}
return ret;
}
