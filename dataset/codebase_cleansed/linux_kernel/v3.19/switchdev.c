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
