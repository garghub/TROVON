int netdev_switch_parent_id_get(struct net_device *dev,
struct netdev_phys_item_id *psid)
{
const struct net_device_ops *ops = dev->netdev_ops;
if (!ops->ndo_switch_parent_id_get)
return -EOPNOTSUPP;
return ops->ndo_switch_parent_id_get(dev, psid);
}
int netdev_switch_port_stp_update(struct net_device *dev, u8 state)
{
const struct net_device_ops *ops = dev->netdev_ops;
if (!ops->ndo_switch_port_stp_update)
return -EOPNOTSUPP;
WARN_ON(!ops->ndo_switch_parent_id_get);
return ops->ndo_switch_port_stp_update(dev, state);
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
