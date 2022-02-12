int netdev_switch_parent_id_get(struct net_device *dev,
struct netdev_phys_item_id *psid)
{
const struct swdev_ops *ops = dev->swdev_ops;
if (!ops || !ops->swdev_parent_id_get)
return -EOPNOTSUPP;
return ops->swdev_parent_id_get(dev, psid);
}
int netdev_switch_port_stp_update(struct net_device *dev, u8 state)
{
const struct swdev_ops *ops = dev->swdev_ops;
struct net_device *lower_dev;
struct list_head *iter;
int err = -EOPNOTSUPP;
if (ops && ops->swdev_port_stp_update)
return ops->swdev_port_stp_update(dev, state);
netdev_for_each_lower_dev(dev, lower_dev, iter) {
err = netdev_switch_port_stp_update(lower_dev, state);
if (err && err != -EOPNOTSUPP)
return err;
}
return err;
}
int register_netdev_switch_notifier(struct notifier_block *nb)
{
int err;
mutex_lock(&netdev_switch_mutex);
err = raw_notifier_chain_register(&netdev_switch_notif_chain, nb);
mutex_unlock(&netdev_switch_mutex);
return err;
}
int unregister_netdev_switch_notifier(struct notifier_block *nb)
{
int err;
mutex_lock(&netdev_switch_mutex);
err = raw_notifier_chain_unregister(&netdev_switch_notif_chain, nb);
mutex_unlock(&netdev_switch_mutex);
return err;
}
int call_netdev_switch_notifiers(unsigned long val, struct net_device *dev,
struct netdev_switch_notifier_info *info)
{
int err;
info->dev = dev;
mutex_lock(&netdev_switch_mutex);
err = raw_notifier_call_chain(&netdev_switch_notif_chain, val, info);
mutex_unlock(&netdev_switch_mutex);
return err;
}
int netdev_switch_port_bridge_setlink(struct net_device *dev,
struct nlmsghdr *nlh, u16 flags)
{
const struct net_device_ops *ops = dev->netdev_ops;
if (!(dev->features & NETIF_F_HW_SWITCH_OFFLOAD))
return 0;
if (!ops->ndo_bridge_setlink)
return -EOPNOTSUPP;
return ops->ndo_bridge_setlink(dev, nlh, flags);
}
int netdev_switch_port_bridge_dellink(struct net_device *dev,
struct nlmsghdr *nlh, u16 flags)
{
const struct net_device_ops *ops = dev->netdev_ops;
if (!(dev->features & NETIF_F_HW_SWITCH_OFFLOAD))
return 0;
if (!ops->ndo_bridge_dellink)
return -EOPNOTSUPP;
return ops->ndo_bridge_dellink(dev, nlh, flags);
}
int ndo_dflt_netdev_switch_port_bridge_setlink(struct net_device *dev,
struct nlmsghdr *nlh, u16 flags)
{
struct net_device *lower_dev;
struct list_head *iter;
int ret = 0, err = 0;
if (!(dev->features & NETIF_F_HW_SWITCH_OFFLOAD))
return ret;
netdev_for_each_lower_dev(dev, lower_dev, iter) {
err = netdev_switch_port_bridge_setlink(lower_dev, nlh, flags);
if (err && err != -EOPNOTSUPP)
ret = err;
}
return ret;
}
int ndo_dflt_netdev_switch_port_bridge_dellink(struct net_device *dev,
struct nlmsghdr *nlh, u16 flags)
{
struct net_device *lower_dev;
struct list_head *iter;
int ret = 0, err = 0;
if (!(dev->features & NETIF_F_HW_SWITCH_OFFLOAD))
return ret;
netdev_for_each_lower_dev(dev, lower_dev, iter) {
err = netdev_switch_port_bridge_dellink(lower_dev, nlh, flags);
if (err && err != -EOPNOTSUPP)
ret = err;
}
return ret;
}
static struct net_device *netdev_switch_get_lowest_dev(struct net_device *dev)
{
const struct swdev_ops *ops = dev->swdev_ops;
struct net_device *lower_dev;
struct net_device *port_dev;
struct list_head *iter;
if (dev->features & NETIF_F_HW_SWITCH_OFFLOAD &&
ops && ops->swdev_parent_id_get)
return dev;
netdev_for_each_lower_dev(dev, lower_dev, iter) {
port_dev = netdev_switch_get_lowest_dev(lower_dev);
if (port_dev)
return port_dev;
}
return NULL;
}
static struct net_device *netdev_switch_get_dev_by_nhs(struct fib_info *fi)
{
struct netdev_phys_item_id psid;
struct netdev_phys_item_id prev_psid;
struct net_device *dev = NULL;
int nhsel;
for (nhsel = 0; nhsel < fi->fib_nhs; nhsel++) {
const struct fib_nh *nh = &fi->fib_nh[nhsel];
if (!nh->nh_dev)
return NULL;
dev = netdev_switch_get_lowest_dev(nh->nh_dev);
if (!dev)
return NULL;
if (netdev_switch_parent_id_get(dev, &psid))
return NULL;
if (nhsel > 0) {
if (prev_psid.id_len != psid.id_len)
return NULL;
if (memcmp(prev_psid.id, psid.id, psid.id_len))
return NULL;
}
prev_psid = psid;
}
return dev;
}
int netdev_switch_fib_ipv4_add(u32 dst, int dst_len, struct fib_info *fi,
u8 tos, u8 type, u32 nlflags, u32 tb_id)
{
struct net_device *dev;
const struct swdev_ops *ops;
int err = 0;
#ifdef CONFIG_IP_MULTIPLE_TABLES
if (fi->fib_net->ipv4.fib_has_custom_rules)
return 0;
#endif
if (fi->fib_net->ipv4.fib_offload_disabled)
return 0;
dev = netdev_switch_get_dev_by_nhs(fi);
if (!dev)
return 0;
ops = dev->swdev_ops;
if (ops->swdev_fib_ipv4_add) {
err = ops->swdev_fib_ipv4_add(dev, htonl(dst), dst_len,
fi, tos, type, nlflags,
tb_id);
if (!err)
fi->fib_flags |= RTNH_F_OFFLOAD;
}
return err;
}
int netdev_switch_fib_ipv4_del(u32 dst, int dst_len, struct fib_info *fi,
u8 tos, u8 type, u32 tb_id)
{
struct net_device *dev;
const struct swdev_ops *ops;
int err = 0;
if (!(fi->fib_flags & RTNH_F_OFFLOAD))
return 0;
dev = netdev_switch_get_dev_by_nhs(fi);
if (!dev)
return 0;
ops = dev->swdev_ops;
if (ops->swdev_fib_ipv4_del) {
err = ops->swdev_fib_ipv4_del(dev, htonl(dst), dst_len,
fi, tos, type, tb_id);
if (!err)
fi->fib_flags &= ~RTNH_F_OFFLOAD;
}
return err;
}
void netdev_switch_fib_ipv4_abort(struct fib_info *fi)
{
fib_flush_external(fi->fib_net);
fi->fib_net->ipv4.fib_offload_disabled = true;
}
