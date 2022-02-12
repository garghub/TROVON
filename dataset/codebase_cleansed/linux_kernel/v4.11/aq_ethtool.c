static void aq_ethtool_get_regs(struct net_device *ndev,
struct ethtool_regs *regs, void *p)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
u32 regs_count = aq_nic_get_regs_count(aq_nic);
memset(p, 0, regs_count * sizeof(u32));
aq_nic_get_regs(aq_nic, regs, p);
}
static int aq_ethtool_get_regs_len(struct net_device *ndev)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
u32 regs_count = aq_nic_get_regs_count(aq_nic);
return regs_count * sizeof(u32);
}
static u32 aq_ethtool_get_link(struct net_device *ndev)
{
return ethtool_op_get_link(ndev);
}
static int aq_ethtool_get_link_ksettings(struct net_device *ndev,
struct ethtool_link_ksettings *cmd)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
aq_nic_get_link_ksettings(aq_nic, cmd);
cmd->base.speed = netif_carrier_ok(ndev) ?
aq_nic_get_link_speed(aq_nic) : 0U;
return 0;
}
static int
aq_ethtool_set_link_ksettings(struct net_device *ndev,
const struct ethtool_link_ksettings *cmd)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
return aq_nic_set_link_ksettings(aq_nic, cmd);
}
static void aq_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *stats, u64 *data)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
BUILD_BUG_ON(AQ_CFG_VECS_MAX > 8);
memset(data, 0, ARRAY_SIZE(aq_ethtool_stat_names) * sizeof(u64));
aq_nic_get_stats(aq_nic, data);
}
static void aq_ethtool_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *drvinfo)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
struct aq_nic_cfg_s *cfg = aq_nic_get_cfg(aq_nic);
struct pci_dev *pdev = to_pci_dev(ndev->dev.parent);
u32 firmware_version = aq_nic_get_fw_version(aq_nic);
u32 regs_count = aq_nic_get_regs_count(aq_nic);
strlcat(drvinfo->driver, AQ_CFG_DRV_NAME, sizeof(drvinfo->driver));
strlcat(drvinfo->version, AQ_CFG_DRV_VERSION, sizeof(drvinfo->version));
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
"%u.%u.%u", firmware_version >> 24,
(firmware_version >> 16) & 0xFFU, firmware_version & 0xFFFFU);
strlcpy(drvinfo->bus_info, pdev ? pci_name(pdev) : "",
sizeof(drvinfo->bus_info));
drvinfo->n_stats = ARRAY_SIZE(aq_ethtool_stat_names) -
(AQ_CFG_VECS_MAX - cfg->vecs) * aq_ethtool_stat_queue_lines;
drvinfo->testinfo_len = 0;
drvinfo->regdump_len = regs_count;
drvinfo->eedump_len = 0;
}
static void aq_ethtool_get_strings(struct net_device *ndev,
u32 stringset, u8 *data)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
struct aq_nic_cfg_s *cfg = aq_nic_get_cfg(aq_nic);
if (stringset == ETH_SS_STATS)
memcpy(data, *aq_ethtool_stat_names,
sizeof(aq_ethtool_stat_names) -
(AQ_CFG_VECS_MAX - cfg->vecs) *
aq_ethtool_stat_queue_chars);
}
static int aq_ethtool_get_sset_count(struct net_device *ndev, int stringset)
{
int ret = 0;
struct aq_nic_s *aq_nic = netdev_priv(ndev);
struct aq_nic_cfg_s *cfg = aq_nic_get_cfg(aq_nic);
switch (stringset) {
case ETH_SS_STATS:
ret = ARRAY_SIZE(aq_ethtool_stat_names) -
(AQ_CFG_VECS_MAX - cfg->vecs) *
aq_ethtool_stat_queue_lines;
break;
default:
ret = -EOPNOTSUPP;
}
return ret;
}
static u32 aq_ethtool_get_rss_indir_size(struct net_device *ndev)
{
return AQ_CFG_RSS_INDIRECTION_TABLE_MAX;
}
static u32 aq_ethtool_get_rss_key_size(struct net_device *ndev)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
struct aq_nic_cfg_s *cfg = aq_nic_get_cfg(aq_nic);
return sizeof(cfg->aq_rss.hash_secret_key);
}
static int aq_ethtool_get_rss(struct net_device *ndev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
struct aq_nic_cfg_s *cfg = aq_nic_get_cfg(aq_nic);
unsigned int i = 0U;
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
if (indir) {
for (i = 0; i < AQ_CFG_RSS_INDIRECTION_TABLE_MAX; i++)
indir[i] = cfg->aq_rss.indirection_table[i];
}
if (key)
memcpy(key, cfg->aq_rss.hash_secret_key,
sizeof(cfg->aq_rss.hash_secret_key));
return 0;
}
static int aq_ethtool_get_rxnfc(struct net_device *ndev,
struct ethtool_rxnfc *cmd,
u32 *rule_locs)
{
struct aq_nic_s *aq_nic = netdev_priv(ndev);
struct aq_nic_cfg_s *cfg = aq_nic_get_cfg(aq_nic);
int err = 0;
switch (cmd->cmd) {
case ETHTOOL_GRXRINGS:
cmd->data = cfg->vecs;
break;
default:
err = -EOPNOTSUPP;
break;
}
return err;
}
