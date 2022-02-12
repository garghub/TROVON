static int mac802154_mlme_start_req(struct net_device *dev,
struct ieee802154_addr *addr,
u8 channel, u8 page,
u8 bcn_ord, u8 sf_ord,
u8 pan_coord, u8 blx,
u8 coord_realign)
{
struct ieee802154_mlme_ops *ops = ieee802154_mlme_ops(dev);
int rc = 0;
ASSERT_RTNL();
BUG_ON(addr->mode != IEEE802154_ADDR_SHORT);
mac802154_dev_set_pan_id(dev, addr->pan_id);
mac802154_dev_set_short_addr(dev, addr->short_addr);
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
return rc;
}
static int mac802154_set_mac_params(struct net_device *dev,
const struct ieee802154_mac_params *params)
{
struct ieee802154_sub_if_data *sdata = IEEE802154_DEV_TO_SUB_IF(dev);
struct ieee802154_local *local = sdata->local;
struct wpan_dev *wpan_dev = &sdata->wpan_dev;
int ret;
ASSERT_RTNL();
wpan_dev->wpan_phy->transmit_power = params->transmit_power;
wpan_dev->wpan_phy->cca_mode = params->cca_mode;
wpan_dev->wpan_phy->cca_ed_level = params->cca_ed_level;
wpan_dev->min_be = params->min_be;
wpan_dev->max_be = params->max_be;
wpan_dev->csma_retries = params->csma_retries;
wpan_dev->frame_retries = params->frame_retries;
wpan_dev->lbt = params->lbt;
if (local->hw.flags & IEEE802154_HW_TXPOWER) {
ret = drv_set_tx_power(local, params->transmit_power);
if (ret < 0)
return ret;
}
if (local->hw.flags & IEEE802154_HW_CCA_MODE) {
ret = drv_set_cca_mode(local, params->cca_mode);
if (ret < 0)
return ret;
}
if (local->hw.flags & IEEE802154_HW_CCA_ED_LEVEL) {
ret = drv_set_cca_ed_level(local, params->cca_ed_level);
if (ret < 0)
return ret;
}
return 0;
}
static void mac802154_get_mac_params(struct net_device *dev,
struct ieee802154_mac_params *params)
{
struct ieee802154_sub_if_data *sdata = IEEE802154_DEV_TO_SUB_IF(dev);
struct wpan_dev *wpan_dev = &sdata->wpan_dev;
ASSERT_RTNL();
params->transmit_power = wpan_dev->wpan_phy->transmit_power;
params->cca_mode = wpan_dev->wpan_phy->cca_mode;
params->cca_ed_level = wpan_dev->wpan_phy->cca_ed_level;
params->min_be = wpan_dev->min_be;
params->max_be = wpan_dev->max_be;
params->csma_retries = wpan_dev->csma_retries;
params->frame_retries = wpan_dev->frame_retries;
params->lbt = wpan_dev->lbt;
}
