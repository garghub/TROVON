static int mac802154_mlme_start_req(struct net_device *dev,
struct ieee802154_addr *addr,
u8 channel, u8 page,
u8 bcn_ord, u8 sf_ord,
u8 pan_coord, u8 blx,
u8 coord_realign)
{
struct ieee802154_mlme_ops *ops = ieee802154_mlme_ops(dev);
int rc = 0;
BUG_ON(addr->mode != IEEE802154_ADDR_SHORT);
mac802154_dev_set_pan_id(dev, addr->pan_id);
mac802154_dev_set_short_addr(dev, addr->short_addr);
mac802154_dev_set_ieee_addr(dev);
mac802154_dev_set_page_channel(dev, page, channel);
if (ops->llsec) {
struct ieee802154_llsec_params params;
int changed = 0;
params.coord_shortaddr = addr->short_addr;
changed |= IEEE802154_LLSEC_PARAM_COORD_SHORTADDR;
params.pan_id = addr->pan_id;
changed |= IEEE802154_LLSEC_PARAM_PAN_ID;
params.hwaddr = ieee802154_devaddr_from_raw(dev->dev_addr);
changed |= IEEE802154_LLSEC_PARAM_HWADDR;
params.coord_hwaddr = params.hwaddr;
changed |= IEEE802154_LLSEC_PARAM_COORD_HWADDR;
rc = ops->llsec->set_params(dev, &params, changed);
}
ieee802154_nl_start_confirm(dev, IEEE802154_SUCCESS);
return rc;
}
static struct wpan_phy *mac802154_get_phy(const struct net_device *dev)
{
struct mac802154_sub_if_data *priv = netdev_priv(dev);
BUG_ON(dev->type != ARPHRD_IEEE802154);
return to_phy(get_device(&priv->hw->phy->dev));
}
