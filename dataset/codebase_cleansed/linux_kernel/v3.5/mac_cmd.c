struct wpan_phy *mac802154_get_phy(const struct net_device *dev)
{
struct mac802154_sub_if_data *priv = netdev_priv(dev);
BUG_ON(dev->type != ARPHRD_IEEE802154);
return to_phy(get_device(&priv->hw->phy->dev));
}
