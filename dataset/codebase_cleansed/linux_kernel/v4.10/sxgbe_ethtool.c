static int sxgbe_get_eee(struct net_device *dev,
struct ethtool_eee *edata)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
if (!priv->hw_cap.eee)
return -EOPNOTSUPP;
edata->eee_enabled = priv->eee_enabled;
edata->eee_active = priv->eee_active;
edata->tx_lpi_timer = priv->tx_lpi_timer;
return phy_ethtool_get_eee(dev->phydev, edata);
}
static int sxgbe_set_eee(struct net_device *dev,
struct ethtool_eee *edata)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
priv->eee_enabled = edata->eee_enabled;
if (!priv->eee_enabled) {
sxgbe_disable_eee_mode(priv);
} else {
priv->eee_enabled = sxgbe_eee_init(priv);
if (!priv->eee_enabled)
return -EOPNOTSUPP;
priv->tx_lpi_timer = edata->tx_lpi_timer;
}
return phy_ethtool_set_eee(dev->phydev, edata);
}
static void sxgbe_getdrvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, KBUILD_MODNAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
}
static u32 sxgbe_getmsglevel(struct net_device *dev)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
return priv->msg_enable;
}
static void sxgbe_setmsglevel(struct net_device *dev, u32 level)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
priv->msg_enable = level;
}
static void sxgbe_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
int i;
u8 *p = data;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < SXGBE_STATS_LEN; i++) {
memcpy(p, sxgbe_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
break;
default:
WARN_ON(1);
break;
}
}
static int sxgbe_get_sset_count(struct net_device *netdev, int sset)
{
int len;
switch (sset) {
case ETH_SS_STATS:
len = SXGBE_STATS_LEN;
return len;
default:
return -EINVAL;
}
}
static void sxgbe_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *dummy, u64 *data)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
int i;
char *p;
if (priv->eee_enabled) {
int val = phy_get_eee_err(dev->phydev);
if (val)
priv->xstats.eee_wakeup_error_n = val;
}
for (i = 0; i < SXGBE_STATS_LEN; i++) {
p = (char *)priv + sxgbe_gstrings_stats[i].stat_offset;
data[i] = (sxgbe_gstrings_stats[i].sizeof_stat == sizeof(u64))
? (*(u64 *)p) : (*(u32 *)p);
}
}
static void sxgbe_get_channels(struct net_device *dev,
struct ethtool_channels *channel)
{
channel->max_rx = SXGBE_MAX_RX_CHANNELS;
channel->max_tx = SXGBE_MAX_TX_CHANNELS;
channel->rx_count = SXGBE_RX_QUEUES;
channel->tx_count = SXGBE_TX_QUEUES;
}
static u32 sxgbe_riwt2usec(u32 riwt, struct sxgbe_priv_data *priv)
{
unsigned long clk = clk_get_rate(priv->sxgbe_clk);
if (!clk)
return 0;
return (riwt * 256) / (clk / 1000000);
}
static u32 sxgbe_usec2riwt(u32 usec, struct sxgbe_priv_data *priv)
{
unsigned long clk = clk_get_rate(priv->sxgbe_clk);
if (!clk)
return 0;
return (usec * (clk / 1000000)) / 256;
}
static int sxgbe_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
if (priv->use_riwt)
ec->rx_coalesce_usecs = sxgbe_riwt2usec(priv->rx_riwt, priv);
return 0;
}
static int sxgbe_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
unsigned int rx_riwt;
if (!ec->rx_coalesce_usecs)
return -EINVAL;
rx_riwt = sxgbe_usec2riwt(ec->rx_coalesce_usecs, priv);
if ((rx_riwt > SXGBE_MAX_DMA_RIWT) || (rx_riwt < SXGBE_MIN_DMA_RIWT))
return -EINVAL;
else if (!priv->use_riwt)
return -EOPNOTSUPP;
priv->rx_riwt = rx_riwt;
priv->hw->dma->rx_watchdog(priv->ioaddr, priv->rx_riwt);
return 0;
}
static int sxgbe_get_rss_hash_opts(struct sxgbe_priv_data *priv,
struct ethtool_rxnfc *cmd)
{
cmd->data = 0;
switch (cmd->flow_type) {
case TCP_V4_FLOW:
case UDP_V4_FLOW:
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
case SCTP_V4_FLOW:
case AH_ESP_V4_FLOW:
case AH_V4_FLOW:
case ESP_V4_FLOW:
case IPV4_FLOW:
cmd->data |= RXH_IP_SRC | RXH_IP_DST;
break;
case TCP_V6_FLOW:
case UDP_V6_FLOW:
cmd->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
case SCTP_V6_FLOW:
case AH_ESP_V6_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case IPV6_FLOW:
cmd->data |= RXH_IP_SRC | RXH_IP_DST;
break;
default:
return -EINVAL;
}
return 0;
}
static int sxgbe_get_rxnfc(struct net_device *dev, struct ethtool_rxnfc *cmd,
u32 *rule_locs)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
int ret = -EOPNOTSUPP;
switch (cmd->cmd) {
case ETHTOOL_GRXFH:
ret = sxgbe_get_rss_hash_opts(priv, cmd);
break;
default:
break;
}
return ret;
}
static int sxgbe_set_rss_hash_opt(struct sxgbe_priv_data *priv,
struct ethtool_rxnfc *cmd)
{
u32 reg_val = 0;
if (cmd->data & ~(RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3))
return -EINVAL;
switch (cmd->flow_type) {
case TCP_V4_FLOW:
case TCP_V6_FLOW:
if (!(cmd->data & RXH_IP_SRC) ||
!(cmd->data & RXH_IP_DST) ||
!(cmd->data & RXH_L4_B_0_1) ||
!(cmd->data & RXH_L4_B_2_3))
return -EINVAL;
reg_val = SXGBE_CORE_RSS_CTL_TCP4TE;
break;
case UDP_V4_FLOW:
case UDP_V6_FLOW:
if (!(cmd->data & RXH_IP_SRC) ||
!(cmd->data & RXH_IP_DST) ||
!(cmd->data & RXH_L4_B_0_1) ||
!(cmd->data & RXH_L4_B_2_3))
return -EINVAL;
reg_val = SXGBE_CORE_RSS_CTL_UDP4TE;
break;
case SCTP_V4_FLOW:
case AH_ESP_V4_FLOW:
case AH_V4_FLOW:
case ESP_V4_FLOW:
case AH_ESP_V6_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case SCTP_V6_FLOW:
case IPV4_FLOW:
case IPV6_FLOW:
if (!(cmd->data & RXH_IP_SRC) ||
!(cmd->data & RXH_IP_DST) ||
(cmd->data & RXH_L4_B_0_1) ||
(cmd->data & RXH_L4_B_2_3))
return -EINVAL;
reg_val = SXGBE_CORE_RSS_CTL_IP2TE;
break;
default:
return -EINVAL;
}
reg_val |= readl(priv->ioaddr + SXGBE_CORE_RSS_CTL_REG);
writel(reg_val, priv->ioaddr + SXGBE_CORE_RSS_CTL_REG);
readl(priv->ioaddr + SXGBE_CORE_RSS_CTL_REG);
return 0;
}
static int sxgbe_set_rxnfc(struct net_device *dev, struct ethtool_rxnfc *cmd)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
int ret = -EOPNOTSUPP;
switch (cmd->cmd) {
case ETHTOOL_SRXFH:
ret = sxgbe_set_rss_hash_opt(priv, cmd);
break;
default:
break;
}
return ret;
}
static void sxgbe_get_regs(struct net_device *dev,
struct ethtool_regs *regs, void *space)
{
struct sxgbe_priv_data *priv = netdev_priv(dev);
u32 *reg_space = (u32 *)space;
int reg_offset;
int reg_ix = 0;
void __iomem *ioaddr = priv->ioaddr;
memset(reg_space, 0x0, REG_SPACE_SIZE);
for (reg_offset = START_MAC_REG_OFFSET;
reg_offset <= MAX_MAC_REG_OFFSET; reg_offset += 4) {
reg_space[reg_ix] = readl(ioaddr + reg_offset);
reg_ix++;
}
for (reg_offset = START_MTL_REG_OFFSET;
reg_offset <= MAX_MTL_REG_OFFSET; reg_offset += 4) {
reg_space[reg_ix] = readl(ioaddr + reg_offset);
reg_ix++;
}
for (reg_offset = START_DMA_REG_OFFSET;
reg_offset <= MAX_DMA_REG_OFFSET; reg_offset += 4) {
reg_space[reg_ix] = readl(ioaddr + reg_offset);
reg_ix++;
}
BUG_ON(reg_ix * 4 > REG_SPACE_SIZE);
}
static int sxgbe_get_regs_len(struct net_device *dev)
{
return REG_SPACE_SIZE;
}
void sxgbe_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &sxgbe_ethtool_ops;
}
