int ieee802154_nl_assoc_indic(struct net_device *dev,
struct ieee802154_addr *addr, u8 cap)
{
struct sk_buff *msg;
pr_debug("%s\n", __func__);
if (addr->addr_type != IEEE802154_ADDR_LONG) {
pr_err("%s: received non-long source address!\n", __func__);
return -EINVAL;
}
msg = ieee802154_nl_create(0, IEEE802154_ASSOCIATE_INDIC);
if (!msg)
return -ENOBUFS;
if (nla_put_string(msg, IEEE802154_ATTR_DEV_NAME, dev->name) ||
nla_put_u32(msg, IEEE802154_ATTR_DEV_INDEX, dev->ifindex) ||
nla_put(msg, IEEE802154_ATTR_HW_ADDR, IEEE802154_ADDR_LEN,
dev->dev_addr) ||
nla_put(msg, IEEE802154_ATTR_SRC_HW_ADDR, IEEE802154_ADDR_LEN,
addr->hwaddr) ||
nla_put_u8(msg, IEEE802154_ATTR_CAPABILITY, cap))
goto nla_put_failure;
return ieee802154_nl_mcast(msg, ieee802154_coord_mcgrp.id);
nla_put_failure:
nlmsg_free(msg);
return -ENOBUFS;
}
int ieee802154_nl_assoc_confirm(struct net_device *dev, u16 short_addr,
u8 status)
{
struct sk_buff *msg;
pr_debug("%s\n", __func__);
msg = ieee802154_nl_create(0, IEEE802154_ASSOCIATE_CONF);
if (!msg)
return -ENOBUFS;
if (nla_put_string(msg, IEEE802154_ATTR_DEV_NAME, dev->name) ||
nla_put_u32(msg, IEEE802154_ATTR_DEV_INDEX, dev->ifindex) ||
nla_put(msg, IEEE802154_ATTR_HW_ADDR, IEEE802154_ADDR_LEN,
dev->dev_addr) ||
nla_put_u16(msg, IEEE802154_ATTR_SHORT_ADDR, short_addr) ||
nla_put_u8(msg, IEEE802154_ATTR_STATUS, status))
goto nla_put_failure;
return ieee802154_nl_mcast(msg, ieee802154_coord_mcgrp.id);
nla_put_failure:
nlmsg_free(msg);
return -ENOBUFS;
}
int ieee802154_nl_disassoc_indic(struct net_device *dev,
struct ieee802154_addr *addr, u8 reason)
{
struct sk_buff *msg;
pr_debug("%s\n", __func__);
msg = ieee802154_nl_create(0, IEEE802154_DISASSOCIATE_INDIC);
if (!msg)
return -ENOBUFS;
if (nla_put_string(msg, IEEE802154_ATTR_DEV_NAME, dev->name) ||
nla_put_u32(msg, IEEE802154_ATTR_DEV_INDEX, dev->ifindex) ||
nla_put(msg, IEEE802154_ATTR_HW_ADDR, IEEE802154_ADDR_LEN,
dev->dev_addr))
goto nla_put_failure;
if (addr->addr_type == IEEE802154_ADDR_LONG) {
if (nla_put(msg, IEEE802154_ATTR_SRC_HW_ADDR, IEEE802154_ADDR_LEN,
addr->hwaddr))
goto nla_put_failure;
} else {
if (nla_put_u16(msg, IEEE802154_ATTR_SRC_SHORT_ADDR,
addr->short_addr))
goto nla_put_failure;
}
if (nla_put_u8(msg, IEEE802154_ATTR_REASON, reason))
goto nla_put_failure;
return ieee802154_nl_mcast(msg, ieee802154_coord_mcgrp.id);
nla_put_failure:
nlmsg_free(msg);
return -ENOBUFS;
}
int ieee802154_nl_disassoc_confirm(struct net_device *dev, u8 status)
{
struct sk_buff *msg;
pr_debug("%s\n", __func__);
msg = ieee802154_nl_create(0, IEEE802154_DISASSOCIATE_CONF);
if (!msg)
return -ENOBUFS;
if (nla_put_string(msg, IEEE802154_ATTR_DEV_NAME, dev->name) ||
nla_put_u32(msg, IEEE802154_ATTR_DEV_INDEX, dev->ifindex) ||
nla_put(msg, IEEE802154_ATTR_HW_ADDR, IEEE802154_ADDR_LEN,
dev->dev_addr) ||
nla_put_u8(msg, IEEE802154_ATTR_STATUS, status))
goto nla_put_failure;
return ieee802154_nl_mcast(msg, ieee802154_coord_mcgrp.id);
nla_put_failure:
nlmsg_free(msg);
return -ENOBUFS;
}
int ieee802154_nl_beacon_indic(struct net_device *dev,
u16 panid, u16 coord_addr)
{
struct sk_buff *msg;
pr_debug("%s\n", __func__);
msg = ieee802154_nl_create(0, IEEE802154_BEACON_NOTIFY_INDIC);
if (!msg)
return -ENOBUFS;
if (nla_put_string(msg, IEEE802154_ATTR_DEV_NAME, dev->name) ||
nla_put_u32(msg, IEEE802154_ATTR_DEV_INDEX, dev->ifindex) ||
nla_put(msg, IEEE802154_ATTR_HW_ADDR, IEEE802154_ADDR_LEN,
dev->dev_addr) ||
nla_put_u16(msg, IEEE802154_ATTR_COORD_SHORT_ADDR, coord_addr) ||
nla_put_u16(msg, IEEE802154_ATTR_COORD_PAN_ID, panid))
goto nla_put_failure;
return ieee802154_nl_mcast(msg, ieee802154_coord_mcgrp.id);
nla_put_failure:
nlmsg_free(msg);
return -ENOBUFS;
}
int ieee802154_nl_scan_confirm(struct net_device *dev,
u8 status, u8 scan_type, u32 unscanned, u8 page,
u8 *edl)
{
struct sk_buff *msg;
pr_debug("%s\n", __func__);
msg = ieee802154_nl_create(0, IEEE802154_SCAN_CONF);
if (!msg)
return -ENOBUFS;
if (nla_put_string(msg, IEEE802154_ATTR_DEV_NAME, dev->name) ||
nla_put_u32(msg, IEEE802154_ATTR_DEV_INDEX, dev->ifindex) ||
nla_put(msg, IEEE802154_ATTR_HW_ADDR, IEEE802154_ADDR_LEN,
dev->dev_addr) ||
nla_put_u8(msg, IEEE802154_ATTR_STATUS, status) ||
nla_put_u8(msg, IEEE802154_ATTR_SCAN_TYPE, scan_type) ||
nla_put_u32(msg, IEEE802154_ATTR_CHANNELS, unscanned) ||
nla_put_u8(msg, IEEE802154_ATTR_PAGE, page) ||
(edl &&
nla_put(msg, IEEE802154_ATTR_ED_LIST, 27, edl)))
goto nla_put_failure;
return ieee802154_nl_mcast(msg, ieee802154_coord_mcgrp.id);
nla_put_failure:
nlmsg_free(msg);
return -ENOBUFS;
}
int ieee802154_nl_start_confirm(struct net_device *dev, u8 status)
{
struct sk_buff *msg;
pr_debug("%s\n", __func__);
msg = ieee802154_nl_create(0, IEEE802154_START_CONF);
if (!msg)
return -ENOBUFS;
if (nla_put_string(msg, IEEE802154_ATTR_DEV_NAME, dev->name) ||
nla_put_u32(msg, IEEE802154_ATTR_DEV_INDEX, dev->ifindex) ||
nla_put(msg, IEEE802154_ATTR_HW_ADDR, IEEE802154_ADDR_LEN,
dev->dev_addr) ||
nla_put_u8(msg, IEEE802154_ATTR_STATUS, status))
goto nla_put_failure;
return ieee802154_nl_mcast(msg, ieee802154_coord_mcgrp.id);
nla_put_failure:
nlmsg_free(msg);
return -ENOBUFS;
}
static int ieee802154_nl_fill_iface(struct sk_buff *msg, u32 portid,
u32 seq, int flags, struct net_device *dev)
{
void *hdr;
struct wpan_phy *phy;
pr_debug("%s\n", __func__);
hdr = genlmsg_put(msg, 0, seq, &nl802154_family, flags,
IEEE802154_LIST_IFACE);
if (!hdr)
goto out;
phy = ieee802154_mlme_ops(dev)->get_phy(dev);
BUG_ON(!phy);
if (nla_put_string(msg, IEEE802154_ATTR_DEV_NAME, dev->name) ||
nla_put_string(msg, IEEE802154_ATTR_PHY_NAME, wpan_phy_name(phy)) ||
nla_put_u32(msg, IEEE802154_ATTR_DEV_INDEX, dev->ifindex) ||
nla_put(msg, IEEE802154_ATTR_HW_ADDR, IEEE802154_ADDR_LEN,
dev->dev_addr) ||
nla_put_u16(msg, IEEE802154_ATTR_SHORT_ADDR,
ieee802154_mlme_ops(dev)->get_short_addr(dev)) ||
nla_put_u16(msg, IEEE802154_ATTR_PAN_ID,
ieee802154_mlme_ops(dev)->get_pan_id(dev)))
goto nla_put_failure;
wpan_phy_put(phy);
return genlmsg_end(msg, hdr);
nla_put_failure:
wpan_phy_put(phy);
genlmsg_cancel(msg, hdr);
out:
return -EMSGSIZE;
}
static struct net_device *ieee802154_nl_get_dev(struct genl_info *info)
{
struct net_device *dev;
if (info->attrs[IEEE802154_ATTR_DEV_NAME]) {
char name[IFNAMSIZ + 1];
nla_strlcpy(name, info->attrs[IEEE802154_ATTR_DEV_NAME],
sizeof(name));
dev = dev_get_by_name(&init_net, name);
} else if (info->attrs[IEEE802154_ATTR_DEV_INDEX])
dev = dev_get_by_index(&init_net,
nla_get_u32(info->attrs[IEEE802154_ATTR_DEV_INDEX]));
else
return NULL;
if (!dev)
return NULL;
if (dev->type != ARPHRD_IEEE802154) {
dev_put(dev);
return NULL;
}
return dev;
}
static int ieee802154_associate_req(struct sk_buff *skb,
struct genl_info *info)
{
struct net_device *dev;
struct ieee802154_addr addr;
u8 page;
int ret = -EINVAL;
if (!info->attrs[IEEE802154_ATTR_CHANNEL] ||
!info->attrs[IEEE802154_ATTR_COORD_PAN_ID] ||
(!info->attrs[IEEE802154_ATTR_COORD_HW_ADDR] &&
!info->attrs[IEEE802154_ATTR_COORD_SHORT_ADDR]) ||
!info->attrs[IEEE802154_ATTR_CAPABILITY])
return -EINVAL;
dev = ieee802154_nl_get_dev(info);
if (!dev)
return -ENODEV;
if (info->attrs[IEEE802154_ATTR_COORD_HW_ADDR]) {
addr.addr_type = IEEE802154_ADDR_LONG;
nla_memcpy(addr.hwaddr,
info->attrs[IEEE802154_ATTR_COORD_HW_ADDR],
IEEE802154_ADDR_LEN);
} else {
addr.addr_type = IEEE802154_ADDR_SHORT;
addr.short_addr = nla_get_u16(
info->attrs[IEEE802154_ATTR_COORD_SHORT_ADDR]);
}
addr.pan_id = nla_get_u16(info->attrs[IEEE802154_ATTR_COORD_PAN_ID]);
if (info->attrs[IEEE802154_ATTR_PAGE])
page = nla_get_u8(info->attrs[IEEE802154_ATTR_PAGE]);
else
page = 0;
ret = ieee802154_mlme_ops(dev)->assoc_req(dev, &addr,
nla_get_u8(info->attrs[IEEE802154_ATTR_CHANNEL]),
page,
nla_get_u8(info->attrs[IEEE802154_ATTR_CAPABILITY]));
dev_put(dev);
return ret;
}
static int ieee802154_associate_resp(struct sk_buff *skb,
struct genl_info *info)
{
struct net_device *dev;
struct ieee802154_addr addr;
int ret = -EINVAL;
if (!info->attrs[IEEE802154_ATTR_STATUS] ||
!info->attrs[IEEE802154_ATTR_DEST_HW_ADDR] ||
!info->attrs[IEEE802154_ATTR_DEST_SHORT_ADDR])
return -EINVAL;
dev = ieee802154_nl_get_dev(info);
if (!dev)
return -ENODEV;
addr.addr_type = IEEE802154_ADDR_LONG;
nla_memcpy(addr.hwaddr, info->attrs[IEEE802154_ATTR_DEST_HW_ADDR],
IEEE802154_ADDR_LEN);
addr.pan_id = ieee802154_mlme_ops(dev)->get_pan_id(dev);
ret = ieee802154_mlme_ops(dev)->assoc_resp(dev, &addr,
nla_get_u16(info->attrs[IEEE802154_ATTR_DEST_SHORT_ADDR]),
nla_get_u8(info->attrs[IEEE802154_ATTR_STATUS]));
dev_put(dev);
return ret;
}
static int ieee802154_disassociate_req(struct sk_buff *skb,
struct genl_info *info)
{
struct net_device *dev;
struct ieee802154_addr addr;
int ret = -EINVAL;
if ((!info->attrs[IEEE802154_ATTR_DEST_HW_ADDR] &&
!info->attrs[IEEE802154_ATTR_DEST_SHORT_ADDR]) ||
!info->attrs[IEEE802154_ATTR_REASON])
return -EINVAL;
dev = ieee802154_nl_get_dev(info);
if (!dev)
return -ENODEV;
if (info->attrs[IEEE802154_ATTR_DEST_HW_ADDR]) {
addr.addr_type = IEEE802154_ADDR_LONG;
nla_memcpy(addr.hwaddr,
info->attrs[IEEE802154_ATTR_DEST_HW_ADDR],
IEEE802154_ADDR_LEN);
} else {
addr.addr_type = IEEE802154_ADDR_SHORT;
addr.short_addr = nla_get_u16(
info->attrs[IEEE802154_ATTR_DEST_SHORT_ADDR]);
}
addr.pan_id = ieee802154_mlme_ops(dev)->get_pan_id(dev);
ret = ieee802154_mlme_ops(dev)->disassoc_req(dev, &addr,
nla_get_u8(info->attrs[IEEE802154_ATTR_REASON]));
dev_put(dev);
return ret;
}
static int ieee802154_start_req(struct sk_buff *skb, struct genl_info *info)
{
struct net_device *dev;
struct ieee802154_addr addr;
u8 channel, bcn_ord, sf_ord;
u8 page;
int pan_coord, blx, coord_realign;
int ret;
if (!info->attrs[IEEE802154_ATTR_COORD_PAN_ID] ||
!info->attrs[IEEE802154_ATTR_COORD_SHORT_ADDR] ||
!info->attrs[IEEE802154_ATTR_CHANNEL] ||
!info->attrs[IEEE802154_ATTR_BCN_ORD] ||
!info->attrs[IEEE802154_ATTR_SF_ORD] ||
!info->attrs[IEEE802154_ATTR_PAN_COORD] ||
!info->attrs[IEEE802154_ATTR_BAT_EXT] ||
!info->attrs[IEEE802154_ATTR_COORD_REALIGN]
)
return -EINVAL;
dev = ieee802154_nl_get_dev(info);
if (!dev)
return -ENODEV;
addr.addr_type = IEEE802154_ADDR_SHORT;
addr.short_addr = nla_get_u16(
info->attrs[IEEE802154_ATTR_COORD_SHORT_ADDR]);
addr.pan_id = nla_get_u16(info->attrs[IEEE802154_ATTR_COORD_PAN_ID]);
channel = nla_get_u8(info->attrs[IEEE802154_ATTR_CHANNEL]);
bcn_ord = nla_get_u8(info->attrs[IEEE802154_ATTR_BCN_ORD]);
sf_ord = nla_get_u8(info->attrs[IEEE802154_ATTR_SF_ORD]);
pan_coord = nla_get_u8(info->attrs[IEEE802154_ATTR_PAN_COORD]);
blx = nla_get_u8(info->attrs[IEEE802154_ATTR_BAT_EXT]);
coord_realign = nla_get_u8(info->attrs[IEEE802154_ATTR_COORD_REALIGN]);
if (info->attrs[IEEE802154_ATTR_PAGE])
page = nla_get_u8(info->attrs[IEEE802154_ATTR_PAGE]);
else
page = 0;
if (addr.short_addr == IEEE802154_ADDR_BROADCAST) {
ieee802154_nl_start_confirm(dev, IEEE802154_NO_SHORT_ADDRESS);
dev_put(dev);
return -EINVAL;
}
ret = ieee802154_mlme_ops(dev)->start_req(dev, &addr, channel, page,
bcn_ord, sf_ord, pan_coord, blx, coord_realign);
dev_put(dev);
return ret;
}
static int ieee802154_scan_req(struct sk_buff *skb, struct genl_info *info)
{
struct net_device *dev;
int ret;
u8 type;
u32 channels;
u8 duration;
u8 page;
if (!info->attrs[IEEE802154_ATTR_SCAN_TYPE] ||
!info->attrs[IEEE802154_ATTR_CHANNELS] ||
!info->attrs[IEEE802154_ATTR_DURATION])
return -EINVAL;
dev = ieee802154_nl_get_dev(info);
if (!dev)
return -ENODEV;
type = nla_get_u8(info->attrs[IEEE802154_ATTR_SCAN_TYPE]);
channels = nla_get_u32(info->attrs[IEEE802154_ATTR_CHANNELS]);
duration = nla_get_u8(info->attrs[IEEE802154_ATTR_DURATION]);
if (info->attrs[IEEE802154_ATTR_PAGE])
page = nla_get_u8(info->attrs[IEEE802154_ATTR_PAGE]);
else
page = 0;
ret = ieee802154_mlme_ops(dev)->scan_req(dev, type, channels, page,
duration);
dev_put(dev);
return ret;
}
static int ieee802154_list_iface(struct sk_buff *skb,
struct genl_info *info)
{
struct sk_buff *msg;
struct net_device *dev = NULL;
int rc = -ENOBUFS;
pr_debug("%s\n", __func__);
dev = ieee802154_nl_get_dev(info);
if (!dev)
return -ENODEV;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
goto out_dev;
rc = ieee802154_nl_fill_iface(msg, info->snd_portid, info->snd_seq,
0, dev);
if (rc < 0)
goto out_free;
dev_put(dev);
return genlmsg_reply(msg, info);
out_free:
nlmsg_free(msg);
out_dev:
dev_put(dev);
return rc;
}
static int ieee802154_dump_iface(struct sk_buff *skb,
struct netlink_callback *cb)
{
struct net *net = sock_net(skb->sk);
struct net_device *dev;
int idx;
int s_idx = cb->args[0];
pr_debug("%s\n", __func__);
idx = 0;
for_each_netdev(net, dev) {
if (idx < s_idx || (dev->type != ARPHRD_IEEE802154))
goto cont;
if (ieee802154_nl_fill_iface(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI, dev) < 0)
break;
cont:
idx++;
}
cb->args[0] = idx;
return skb->len;
}
int nl802154_mac_register(void)
{
int i;
int rc;
rc = genl_register_mc_group(&nl802154_family,
&ieee802154_coord_mcgrp);
if (rc)
return rc;
rc = genl_register_mc_group(&nl802154_family,
&ieee802154_beacon_mcgrp);
if (rc)
return rc;
for (i = 0; i < ARRAY_SIZE(ieee802154_coordinator_ops); i++) {
rc = genl_register_ops(&nl802154_family,
&ieee802154_coordinator_ops[i]);
if (rc)
return rc;
}
return 0;
}
