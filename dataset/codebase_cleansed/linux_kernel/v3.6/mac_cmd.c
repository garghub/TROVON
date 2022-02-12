static int mac802154_mlme_start_req(struct net_device *dev,
struct ieee802154_addr *addr,
u8 channel, u8 page,
u8 bcn_ord, u8 sf_ord,
u8 pan_coord, u8 blx,
u8 coord_realign)
{
BUG_ON(addr->addr_type != IEEE802154_ADDR_SHORT);
mac802154_dev_set_pan_id(dev, addr->pan_id);
mac802154_dev_set_short_addr(dev, addr->short_addr);
mac802154_dev_set_ieee_addr(dev);
mac802154_dev_set_page_channel(dev, page, channel);
ieee802154_nl_start_confirm(dev, IEEE802154_SUCCESS);
return 0;
}
static struct wpan_phy *mac802154_get_phy(const struct net_device *dev)
{
struct mac802154_sub_if_data *priv = netdev_priv(dev);
BUG_ON(dev->type != ARPHRD_IEEE802154);
return to_phy(get_device(&priv->hw->phy->dev));
}
