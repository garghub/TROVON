static void mwifiex_ethtool_get_wol(struct net_device *dev,
struct ethtool_wolinfo *wol)
{
struct mwifiex_private *priv = mwifiex_netdev_get_priv(dev);
u32 conditions = le32_to_cpu(priv->adapter->hs_cfg.conditions);
wol->supported = WAKE_UCAST|WAKE_MCAST|WAKE_BCAST|WAKE_PHY;
if (conditions == HS_CFG_COND_DEF)
return;
if (conditions & HS_CFG_COND_UNICAST_DATA)
wol->wolopts |= WAKE_UCAST;
if (conditions & HS_CFG_COND_MULTICAST_DATA)
wol->wolopts |= WAKE_MCAST;
if (conditions & HS_CFG_COND_BROADCAST_DATA)
wol->wolopts |= WAKE_BCAST;
if (conditions & HS_CFG_COND_MAC_EVENT)
wol->wolopts |= WAKE_PHY;
}
static int mwifiex_ethtool_set_wol(struct net_device *dev,
struct ethtool_wolinfo *wol)
{
struct mwifiex_private *priv = mwifiex_netdev_get_priv(dev);
u32 conditions = 0;
if (wol->wolopts & ~(WAKE_UCAST|WAKE_MCAST|WAKE_BCAST|WAKE_PHY))
return -EOPNOTSUPP;
if (wol->wolopts & WAKE_UCAST)
conditions |= HS_CFG_COND_UNICAST_DATA;
if (wol->wolopts & WAKE_MCAST)
conditions |= HS_CFG_COND_MULTICAST_DATA;
if (wol->wolopts & WAKE_BCAST)
conditions |= HS_CFG_COND_BROADCAST_DATA;
if (wol->wolopts & WAKE_PHY)
conditions |= HS_CFG_COND_MAC_EVENT;
if (wol->wolopts == 0)
conditions |= HS_CFG_COND_DEF;
priv->adapter->hs_cfg.conditions = cpu_to_le32(conditions);
return 0;
}
