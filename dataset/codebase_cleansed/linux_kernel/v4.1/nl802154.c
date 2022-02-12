static struct wpan_dev *
__cfg802154_wpan_dev_from_attrs(struct net *netns, struct nlattr **attrs)
{
struct cfg802154_registered_device *rdev;
struct wpan_dev *result = NULL;
bool have_ifidx = attrs[NL802154_ATTR_IFINDEX];
bool have_wpan_dev_id = attrs[NL802154_ATTR_WPAN_DEV];
u64 wpan_dev_id;
int wpan_phy_idx = -1;
int ifidx = -1;
ASSERT_RTNL();
if (!have_ifidx && !have_wpan_dev_id)
return ERR_PTR(-EINVAL);
if (have_ifidx)
ifidx = nla_get_u32(attrs[NL802154_ATTR_IFINDEX]);
if (have_wpan_dev_id) {
wpan_dev_id = nla_get_u64(attrs[NL802154_ATTR_WPAN_DEV]);
wpan_phy_idx = wpan_dev_id >> 32;
}
list_for_each_entry(rdev, &cfg802154_rdev_list, list) {
struct wpan_dev *wpan_dev;
if (have_wpan_dev_id && rdev->wpan_phy_idx != wpan_phy_idx)
continue;
list_for_each_entry(wpan_dev, &rdev->wpan_dev_list, list) {
if (have_ifidx && wpan_dev->netdev &&
wpan_dev->netdev->ifindex == ifidx) {
result = wpan_dev;
break;
}
if (have_wpan_dev_id &&
wpan_dev->identifier == (u32)wpan_dev_id) {
result = wpan_dev;
break;
}
}
if (result)
break;
}
if (result)
return result;
return ERR_PTR(-ENODEV);
}
static struct cfg802154_registered_device *
__cfg802154_rdev_from_attrs(struct net *netns, struct nlattr **attrs)
{
struct cfg802154_registered_device *rdev = NULL, *tmp;
struct net_device *netdev;
ASSERT_RTNL();
if (!attrs[NL802154_ATTR_WPAN_PHY] &&
!attrs[NL802154_ATTR_IFINDEX] &&
!attrs[NL802154_ATTR_WPAN_DEV])
return ERR_PTR(-EINVAL);
if (attrs[NL802154_ATTR_WPAN_PHY])
rdev = cfg802154_rdev_by_wpan_phy_idx(
nla_get_u32(attrs[NL802154_ATTR_WPAN_PHY]));
if (attrs[NL802154_ATTR_WPAN_DEV]) {
u64 wpan_dev_id = nla_get_u64(attrs[NL802154_ATTR_WPAN_DEV]);
struct wpan_dev *wpan_dev;
bool found = false;
tmp = cfg802154_rdev_by_wpan_phy_idx(wpan_dev_id >> 32);
if (tmp) {
list_for_each_entry(wpan_dev, &tmp->wpan_dev_list, list) {
if (wpan_dev->identifier != (u32)wpan_dev_id)
continue;
found = true;
break;
}
if (!found)
tmp = NULL;
if (rdev && tmp != rdev)
return ERR_PTR(-EINVAL);
rdev = tmp;
}
}
if (attrs[NL802154_ATTR_IFINDEX]) {
int ifindex = nla_get_u32(attrs[NL802154_ATTR_IFINDEX]);
netdev = __dev_get_by_index(netns, ifindex);
if (netdev) {
if (netdev->ieee802154_ptr)
tmp = wpan_phy_to_rdev(
netdev->ieee802154_ptr->wpan_phy);
else
tmp = NULL;
if (!tmp)
return ERR_PTR(-EINVAL);
if (rdev && tmp != rdev)
return ERR_PTR(-EINVAL);
rdev = tmp;
}
}
if (!rdev)
return ERR_PTR(-ENODEV);
return rdev;
}
static struct cfg802154_registered_device *
cfg802154_get_dev_from_info(struct net *netns, struct genl_info *info)
{
return __cfg802154_rdev_from_attrs(netns, info->attrs);
}
static inline void *nl802154hdr_put(struct sk_buff *skb, u32 portid, u32 seq,
int flags, u8 cmd)
{
return genlmsg_put(skb, portid, seq, &nl802154_fam, flags, cmd);
}
static int
nl802154_send_wpan_phy_channels(struct cfg802154_registered_device *rdev,
struct sk_buff *msg)
{
struct nlattr *nl_page;
unsigned long page;
nl_page = nla_nest_start(msg, NL802154_ATTR_CHANNELS_SUPPORTED);
if (!nl_page)
return -ENOBUFS;
for (page = 0; page <= IEEE802154_MAX_PAGE; page++) {
if (nla_put_u32(msg, NL802154_ATTR_SUPPORTED_CHANNEL,
rdev->wpan_phy.channels_supported[page]))
return -ENOBUFS;
}
nla_nest_end(msg, nl_page);
return 0;
}
static int nl802154_send_wpan_phy(struct cfg802154_registered_device *rdev,
enum nl802154_commands cmd,
struct sk_buff *msg, u32 portid, u32 seq,
int flags)
{
void *hdr;
hdr = nl802154hdr_put(msg, portid, seq, flags, cmd);
if (!hdr)
return -ENOBUFS;
if (nla_put_u32(msg, NL802154_ATTR_WPAN_PHY, rdev->wpan_phy_idx) ||
nla_put_string(msg, NL802154_ATTR_WPAN_PHY_NAME,
wpan_phy_name(&rdev->wpan_phy)) ||
nla_put_u32(msg, NL802154_ATTR_GENERATION,
cfg802154_rdev_list_generation))
goto nla_put_failure;
if (cmd != NL802154_CMD_NEW_WPAN_PHY)
goto finish;
if (nla_put_u8(msg, NL802154_ATTR_PAGE,
rdev->wpan_phy.current_page) ||
nla_put_u8(msg, NL802154_ATTR_CHANNEL,
rdev->wpan_phy.current_channel))
goto nla_put_failure;
if (nl802154_send_wpan_phy_channels(rdev, msg))
goto nla_put_failure;
if (nla_put_u32(msg, NL802154_ATTR_CCA_MODE,
rdev->wpan_phy.cca.mode))
goto nla_put_failure;
if (rdev->wpan_phy.cca.mode == NL802154_CCA_ENERGY_CARRIER) {
if (nla_put_u32(msg, NL802154_ATTR_CCA_OPT,
rdev->wpan_phy.cca.opt))
goto nla_put_failure;
}
if (nla_put_s8(msg, NL802154_ATTR_TX_POWER,
rdev->wpan_phy.transmit_power))
goto nla_put_failure;
finish:
genlmsg_end(msg, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(msg, hdr);
return -EMSGSIZE;
}
static int nl802154_dump_wpan_phy_parse(struct sk_buff *skb,
struct netlink_callback *cb,
struct nl802154_dump_wpan_phy_state *state)
{
struct nlattr **tb = nl802154_fam.attrbuf;
int ret = nlmsg_parse(cb->nlh, GENL_HDRLEN + nl802154_fam.hdrsize,
tb, nl802154_fam.maxattr, nl802154_policy);
if (ret)
return 0;
if (tb[NL802154_ATTR_WPAN_PHY])
state->filter_wpan_phy = nla_get_u32(tb[NL802154_ATTR_WPAN_PHY]);
if (tb[NL802154_ATTR_WPAN_DEV])
state->filter_wpan_phy = nla_get_u64(tb[NL802154_ATTR_WPAN_DEV]) >> 32;
if (tb[NL802154_ATTR_IFINDEX]) {
struct net_device *netdev;
struct cfg802154_registered_device *rdev;
int ifidx = nla_get_u32(tb[NL802154_ATTR_IFINDEX]);
netdev = __dev_get_by_index(&init_net, ifidx);
if (!netdev)
return -ENODEV;
if (netdev->ieee802154_ptr) {
rdev = wpan_phy_to_rdev(
netdev->ieee802154_ptr->wpan_phy);
state->filter_wpan_phy = rdev->wpan_phy_idx;
}
}
return 0;
}
static int
nl802154_dump_wpan_phy(struct sk_buff *skb, struct netlink_callback *cb)
{
int idx = 0, ret;
struct nl802154_dump_wpan_phy_state *state = (void *)cb->args[0];
struct cfg802154_registered_device *rdev;
rtnl_lock();
if (!state) {
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state) {
rtnl_unlock();
return -ENOMEM;
}
state->filter_wpan_phy = -1;
ret = nl802154_dump_wpan_phy_parse(skb, cb, state);
if (ret) {
kfree(state);
rtnl_unlock();
return ret;
}
cb->args[0] = (long)state;
}
list_for_each_entry(rdev, &cfg802154_rdev_list, list) {
if (++idx <= state->start)
continue;
if (state->filter_wpan_phy != -1 &&
state->filter_wpan_phy != rdev->wpan_phy_idx)
continue;
ret = nl802154_send_wpan_phy(rdev,
NL802154_CMD_NEW_WPAN_PHY,
skb,
NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI);
if (ret < 0) {
if ((ret == -ENOBUFS || ret == -EMSGSIZE) &&
!skb->len && cb->min_dump_alloc < 4096) {
cb->min_dump_alloc = 4096;
rtnl_unlock();
return 1;
}
idx--;
break;
}
break;
}
rtnl_unlock();
state->start = idx;
return skb->len;
}
static int nl802154_dump_wpan_phy_done(struct netlink_callback *cb)
{
kfree((void *)cb->args[0]);
return 0;
}
static int nl802154_get_wpan_phy(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *msg;
struct cfg802154_registered_device *rdev = info->user_ptr[0];
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
if (nl802154_send_wpan_phy(rdev, NL802154_CMD_NEW_WPAN_PHY, msg,
info->snd_portid, info->snd_seq, 0) < 0) {
nlmsg_free(msg);
return -ENOBUFS;
}
return genlmsg_reply(msg, info);
}
static inline u64 wpan_dev_id(struct wpan_dev *wpan_dev)
{
return (u64)wpan_dev->identifier |
((u64)wpan_phy_to_rdev(wpan_dev->wpan_phy)->wpan_phy_idx << 32);
}
static int
nl802154_send_iface(struct sk_buff *msg, u32 portid, u32 seq, int flags,
struct cfg802154_registered_device *rdev,
struct wpan_dev *wpan_dev)
{
struct net_device *dev = wpan_dev->netdev;
void *hdr;
hdr = nl802154hdr_put(msg, portid, seq, flags,
NL802154_CMD_NEW_INTERFACE);
if (!hdr)
return -1;
if (dev &&
(nla_put_u32(msg, NL802154_ATTR_IFINDEX, dev->ifindex) ||
nla_put_string(msg, NL802154_ATTR_IFNAME, dev->name)))
goto nla_put_failure;
if (nla_put_u32(msg, NL802154_ATTR_WPAN_PHY, rdev->wpan_phy_idx) ||
nla_put_u32(msg, NL802154_ATTR_IFTYPE, wpan_dev->iftype) ||
nla_put_u64(msg, NL802154_ATTR_WPAN_DEV, wpan_dev_id(wpan_dev)) ||
nla_put_u32(msg, NL802154_ATTR_GENERATION,
rdev->devlist_generation ^
(cfg802154_rdev_list_generation << 2)))
goto nla_put_failure;
if (nla_put_le64(msg, NL802154_ATTR_EXTENDED_ADDR,
wpan_dev->extended_addr) ||
nla_put_le16(msg, NL802154_ATTR_SHORT_ADDR,
wpan_dev->short_addr) ||
nla_put_le16(msg, NL802154_ATTR_PAN_ID, wpan_dev->pan_id))
goto nla_put_failure;
if (nla_put_s8(msg, NL802154_ATTR_MAX_FRAME_RETRIES,
wpan_dev->frame_retries) ||
nla_put_u8(msg, NL802154_ATTR_MAX_BE, wpan_dev->max_be) ||
nla_put_u8(msg, NL802154_ATTR_MAX_CSMA_BACKOFFS,
wpan_dev->csma_retries) ||
nla_put_u8(msg, NL802154_ATTR_MIN_BE, wpan_dev->min_be))
goto nla_put_failure;
if (nla_put_u8(msg, NL802154_ATTR_LBT_MODE, wpan_dev->lbt))
goto nla_put_failure;
genlmsg_end(msg, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(msg, hdr);
return -EMSGSIZE;
}
static int
nl802154_dump_interface(struct sk_buff *skb, struct netlink_callback *cb)
{
int wp_idx = 0;
int if_idx = 0;
int wp_start = cb->args[0];
int if_start = cb->args[1];
struct cfg802154_registered_device *rdev;
struct wpan_dev *wpan_dev;
rtnl_lock();
list_for_each_entry(rdev, &cfg802154_rdev_list, list) {
if (wp_idx < wp_start) {
wp_idx++;
continue;
}
if_idx = 0;
list_for_each_entry(wpan_dev, &rdev->wpan_dev_list, list) {
if (if_idx < if_start) {
if_idx++;
continue;
}
if (nl802154_send_iface(skb, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI,
rdev, wpan_dev) < 0) {
goto out;
}
if_idx++;
}
wp_idx++;
}
out:
rtnl_unlock();
cb->args[0] = wp_idx;
cb->args[1] = if_idx;
return skb->len;
}
static int nl802154_get_interface(struct sk_buff *skb, struct genl_info *info)
{
struct sk_buff *msg;
struct cfg802154_registered_device *rdev = info->user_ptr[0];
struct wpan_dev *wdev = info->user_ptr[1];
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
if (nl802154_send_iface(msg, info->snd_portid, info->snd_seq, 0,
rdev, wdev) < 0) {
nlmsg_free(msg);
return -ENOBUFS;
}
return genlmsg_reply(msg, info);
}
static int nl802154_new_interface(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
enum nl802154_iftype type = NL802154_IFTYPE_UNSPEC;
__le64 extended_addr = cpu_to_le64(0x0000000000000000ULL);
if (!info->attrs[NL802154_ATTR_IFNAME])
return -EINVAL;
if (info->attrs[NL802154_ATTR_IFTYPE]) {
type = nla_get_u32(info->attrs[NL802154_ATTR_IFTYPE]);
if (type > NL802154_IFTYPE_MAX)
return -EINVAL;
}
if (info->attrs[NL802154_ATTR_EXTENDED_ADDR])
extended_addr = (__force __le64)nla_get_u64(
info->attrs[NL802154_ATTR_EXTENDED_ADDR]);
if (!rdev->ops->add_virtual_intf)
return -EOPNOTSUPP;
return rdev_add_virtual_intf(rdev,
nla_data(info->attrs[NL802154_ATTR_IFNAME]),
NET_NAME_USER, type, extended_addr);
}
static int nl802154_del_interface(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
struct wpan_dev *wpan_dev = info->user_ptr[1];
if (!rdev->ops->del_virtual_intf)
return -EOPNOTSUPP;
if (!wpan_dev->netdev)
info->user_ptr[1] = NULL;
return rdev_del_virtual_intf(rdev, wpan_dev);
}
static int nl802154_set_channel(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
u8 channel, page;
if (!info->attrs[NL802154_ATTR_PAGE] ||
!info->attrs[NL802154_ATTR_CHANNEL])
return -EINVAL;
page = nla_get_u8(info->attrs[NL802154_ATTR_PAGE]);
channel = nla_get_u8(info->attrs[NL802154_ATTR_CHANNEL]);
if (page > IEEE802154_MAX_PAGE || channel > IEEE802154_MAX_CHANNEL)
return -EINVAL;
return rdev_set_channel(rdev, page, channel);
}
static int nl802154_set_cca_mode(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
struct wpan_phy_cca cca;
if (!info->attrs[NL802154_ATTR_CCA_MODE])
return -EINVAL;
cca.mode = nla_get_u32(info->attrs[NL802154_ATTR_CCA_MODE]);
if (cca.mode < NL802154_CCA_ENERGY || cca.mode > NL802154_CCA_ATTR_MAX)
return -EINVAL;
if (cca.mode == NL802154_CCA_ENERGY_CARRIER) {
if (!info->attrs[NL802154_ATTR_CCA_OPT])
return -EINVAL;
cca.opt = nla_get_u32(info->attrs[NL802154_ATTR_CCA_OPT]);
if (cca.opt > NL802154_CCA_OPT_ATTR_MAX)
return -EINVAL;
}
return rdev_set_cca_mode(rdev, &cca);
}
static int nl802154_set_pan_id(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
struct net_device *dev = info->user_ptr[1];
struct wpan_dev *wpan_dev = dev->ieee802154_ptr;
__le16 pan_id;
if (netif_running(dev))
return -EBUSY;
if (wpan_dev->iftype == NL802154_IFTYPE_MONITOR)
return -EINVAL;
if (!info->attrs[NL802154_ATTR_PAN_ID])
return -EINVAL;
pan_id = nla_get_le16(info->attrs[NL802154_ATTR_PAN_ID]);
return rdev_set_pan_id(rdev, wpan_dev, pan_id);
}
static int nl802154_set_short_addr(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
struct net_device *dev = info->user_ptr[1];
struct wpan_dev *wpan_dev = dev->ieee802154_ptr;
__le16 short_addr;
if (netif_running(dev))
return -EBUSY;
if (wpan_dev->iftype == NL802154_IFTYPE_MONITOR)
return -EINVAL;
if (!info->attrs[NL802154_ATTR_SHORT_ADDR])
return -EINVAL;
short_addr = nla_get_le16(info->attrs[NL802154_ATTR_SHORT_ADDR]);
return rdev_set_short_addr(rdev, wpan_dev, short_addr);
}
static int
nl802154_set_backoff_exponent(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
struct net_device *dev = info->user_ptr[1];
struct wpan_dev *wpan_dev = dev->ieee802154_ptr;
u8 min_be, max_be;
if (netif_running(dev))
return -EBUSY;
if (!info->attrs[NL802154_ATTR_MIN_BE] ||
!info->attrs[NL802154_ATTR_MAX_BE])
return -EINVAL;
min_be = nla_get_u8(info->attrs[NL802154_ATTR_MIN_BE]);
max_be = nla_get_u8(info->attrs[NL802154_ATTR_MAX_BE]);
if (max_be < 3 || max_be > 8 || min_be > max_be)
return -EINVAL;
return rdev_set_backoff_exponent(rdev, wpan_dev, min_be, max_be);
}
static int
nl802154_set_max_csma_backoffs(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
struct net_device *dev = info->user_ptr[1];
struct wpan_dev *wpan_dev = dev->ieee802154_ptr;
u8 max_csma_backoffs;
if (netif_running(dev))
return -EBUSY;
if (!info->attrs[NL802154_ATTR_MAX_CSMA_BACKOFFS])
return -EINVAL;
max_csma_backoffs = nla_get_u8(
info->attrs[NL802154_ATTR_MAX_CSMA_BACKOFFS]);
if (max_csma_backoffs > 5)
return -EINVAL;
return rdev_set_max_csma_backoffs(rdev, wpan_dev, max_csma_backoffs);
}
static int
nl802154_set_max_frame_retries(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
struct net_device *dev = info->user_ptr[1];
struct wpan_dev *wpan_dev = dev->ieee802154_ptr;
s8 max_frame_retries;
if (netif_running(dev))
return -EBUSY;
if (!info->attrs[NL802154_ATTR_MAX_FRAME_RETRIES])
return -EINVAL;
max_frame_retries = nla_get_s8(
info->attrs[NL802154_ATTR_MAX_FRAME_RETRIES]);
if (max_frame_retries < -1 || max_frame_retries > 7)
return -EINVAL;
return rdev_set_max_frame_retries(rdev, wpan_dev, max_frame_retries);
}
static int nl802154_set_lbt_mode(struct sk_buff *skb, struct genl_info *info)
{
struct cfg802154_registered_device *rdev = info->user_ptr[0];
struct net_device *dev = info->user_ptr[1];
struct wpan_dev *wpan_dev = dev->ieee802154_ptr;
bool mode;
if (netif_running(dev))
return -EBUSY;
if (!info->attrs[NL802154_ATTR_LBT_MODE])
return -EINVAL;
mode = !!nla_get_u8(info->attrs[NL802154_ATTR_LBT_MODE]);
return rdev_set_lbt_mode(rdev, wpan_dev, mode);
}
static int nl802154_pre_doit(const struct genl_ops *ops, struct sk_buff *skb,
struct genl_info *info)
{
struct cfg802154_registered_device *rdev;
struct wpan_dev *wpan_dev;
struct net_device *dev;
bool rtnl = ops->internal_flags & NL802154_FLAG_NEED_RTNL;
if (rtnl)
rtnl_lock();
if (ops->internal_flags & NL802154_FLAG_NEED_WPAN_PHY) {
rdev = cfg802154_get_dev_from_info(genl_info_net(info), info);
if (IS_ERR(rdev)) {
if (rtnl)
rtnl_unlock();
return PTR_ERR(rdev);
}
info->user_ptr[0] = rdev;
} else if (ops->internal_flags & NL802154_FLAG_NEED_NETDEV ||
ops->internal_flags & NL802154_FLAG_NEED_WPAN_DEV) {
ASSERT_RTNL();
wpan_dev = __cfg802154_wpan_dev_from_attrs(genl_info_net(info),
info->attrs);
if (IS_ERR(wpan_dev)) {
if (rtnl)
rtnl_unlock();
return PTR_ERR(wpan_dev);
}
dev = wpan_dev->netdev;
rdev = wpan_phy_to_rdev(wpan_dev->wpan_phy);
if (ops->internal_flags & NL802154_FLAG_NEED_NETDEV) {
if (!dev) {
if (rtnl)
rtnl_unlock();
return -EINVAL;
}
info->user_ptr[1] = dev;
} else {
info->user_ptr[1] = wpan_dev;
}
if (dev) {
if (ops->internal_flags & NL802154_FLAG_CHECK_NETDEV_UP &&
!netif_running(dev)) {
if (rtnl)
rtnl_unlock();
return -ENETDOWN;
}
dev_hold(dev);
}
info->user_ptr[0] = rdev;
}
return 0;
}
static void nl802154_post_doit(const struct genl_ops *ops, struct sk_buff *skb,
struct genl_info *info)
{
if (info->user_ptr[1]) {
if (ops->internal_flags & NL802154_FLAG_NEED_WPAN_DEV) {
struct wpan_dev *wpan_dev = info->user_ptr[1];
if (wpan_dev->netdev)
dev_put(wpan_dev->netdev);
} else {
dev_put(info->user_ptr[1]);
}
}
if (ops->internal_flags & NL802154_FLAG_NEED_RTNL)
rtnl_unlock();
}
int nl802154_init(void)
{
return genl_register_family_with_ops_groups(&nl802154_fam, nl802154_ops,
nl802154_mcgrps);
}
void nl802154_exit(void)
{
genl_unregister_family(&nl802154_fam);
}
