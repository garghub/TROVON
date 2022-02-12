static int bond_validate(struct nlattr *tb[], struct nlattr *data[])
{
if (tb[IFLA_ADDRESS]) {
if (nla_len(tb[IFLA_ADDRESS]) != ETH_ALEN)
return -EINVAL;
if (!is_valid_ether_addr(nla_data(tb[IFLA_ADDRESS])))
return -EADDRNOTAVAIL;
}
return 0;
}
static int bond_changelink(struct net_device *bond_dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct bonding *bond = netdev_priv(bond_dev);
int err;
if (data && data[IFLA_BOND_MODE]) {
int mode = nla_get_u8(data[IFLA_BOND_MODE]);
err = bond_option_mode_set(bond, mode);
if (err)
return err;
}
if (data && data[IFLA_BOND_ACTIVE_SLAVE]) {
int ifindex = nla_get_u32(data[IFLA_BOND_ACTIVE_SLAVE]);
struct net_device *slave_dev;
if (ifindex == 0) {
slave_dev = NULL;
} else {
slave_dev = __dev_get_by_index(dev_net(bond_dev),
ifindex);
if (!slave_dev)
return -ENODEV;
}
err = bond_option_active_slave_set(bond, slave_dev);
if (err)
return err;
}
return 0;
}
static int bond_newlink(struct net *src_net, struct net_device *bond_dev,
struct nlattr *tb[], struct nlattr *data[])
{
int err;
err = bond_changelink(bond_dev, tb, data);
if (err < 0)
return err;
return register_netdevice(bond_dev);
}
static size_t bond_get_size(const struct net_device *bond_dev)
{
return nla_total_size(sizeof(u8)) +
nla_total_size(sizeof(u32));
}
static int bond_fill_info(struct sk_buff *skb,
const struct net_device *bond_dev)
{
struct bonding *bond = netdev_priv(bond_dev);
struct net_device *slave_dev = bond_option_active_slave_get(bond);
if (nla_put_u8(skb, IFLA_BOND_MODE, bond->params.mode) ||
(slave_dev &&
nla_put_u32(skb, IFLA_BOND_ACTIVE_SLAVE, slave_dev->ifindex)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
int __init bond_netlink_init(void)
{
return rtnl_link_register(&bond_link_ops);
}
void bond_netlink_fini(void)
{
rtnl_link_unregister(&bond_link_ops);
}
