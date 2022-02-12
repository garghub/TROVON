static int ipoib_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ipoib_dev_priv *priv = netdev_priv(dev);
u16 val;
if (nla_put_u16(skb, IFLA_IPOIB_PKEY, priv->pkey))
goto nla_put_failure;
val = test_bit(IPOIB_FLAG_ADMIN_CM, &priv->flags);
if (nla_put_u16(skb, IFLA_IPOIB_MODE, val))
goto nla_put_failure;
val = test_bit(IPOIB_FLAG_UMCAST, &priv->flags);
if (nla_put_u16(skb, IFLA_IPOIB_UMCAST, val))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int ipoib_changelink(struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
u16 mode, umcast;
int ret = 0;
if (data[IFLA_IPOIB_MODE]) {
mode = nla_get_u16(data[IFLA_IPOIB_MODE]);
if (mode == IPOIB_MODE_DATAGRAM)
ret = ipoib_set_mode(dev, "datagram\n");
else if (mode == IPOIB_MODE_CONNECTED)
ret = ipoib_set_mode(dev, "connected\n");
else
ret = -EINVAL;
if (ret < 0)
goto out_err;
}
if (data[IFLA_IPOIB_UMCAST]) {
umcast = nla_get_u16(data[IFLA_IPOIB_UMCAST]);
ipoib_set_umcast(dev, umcast);
}
out_err:
return ret;
}
static int ipoib_new_child_link(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct net_device *pdev;
struct ipoib_dev_priv *ppriv;
u16 child_pkey;
int err;
if (!tb[IFLA_LINK])
return -EINVAL;
pdev = __dev_get_by_index(src_net, nla_get_u32(tb[IFLA_LINK]));
if (!pdev)
return -ENODEV;
ppriv = netdev_priv(pdev);
if (test_bit(IPOIB_FLAG_SUBINTERFACE, &ppriv->flags)) {
ipoib_warn(ppriv, "child creation disallowed for child devices\n");
return -EINVAL;
}
if (!data || !data[IFLA_IPOIB_PKEY]) {
ipoib_dbg(ppriv, "no pkey specified, using parent pkey\n");
child_pkey = ppriv->pkey;
} else
child_pkey = nla_get_u16(data[IFLA_IPOIB_PKEY]);
if (child_pkey == 0 || child_pkey == 0x8000)
return -EINVAL;
child_pkey |= 0x8000;
err = __ipoib_vlan_add(ppriv, netdev_priv(dev), child_pkey, IPOIB_RTNL_CHILD);
if (!err && data)
err = ipoib_changelink(dev, tb, data);
return err;
}
static void ipoib_unregister_child_dev(struct net_device *dev, struct list_head *head)
{
struct ipoib_dev_priv *priv, *ppriv;
priv = netdev_priv(dev);
ppriv = netdev_priv(priv->parent);
mutex_lock(&ppriv->vlan_mutex);
unregister_netdevice_queue(dev, head);
list_del(&priv->list);
mutex_unlock(&ppriv->vlan_mutex);
}
static size_t ipoib_get_size(const struct net_device *dev)
{
return nla_total_size(2) +
nla_total_size(2) +
nla_total_size(2);
}
int __init ipoib_netlink_init(void)
{
return rtnl_link_register(&ipoib_link_ops);
}
void __exit ipoib_netlink_fini(void)
{
rtnl_link_unregister(&ipoib_link_ops);
}
