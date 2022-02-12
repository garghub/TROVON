static ssize_t show_parent(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_device *dev = to_net_dev(d);
struct ipoib_dev_priv *priv = netdev_priv(dev);
return sprintf(buf, "%s\n", priv->parent->name);
}
int __ipoib_vlan_add(struct ipoib_dev_priv *ppriv, struct ipoib_dev_priv *priv,
u16 pkey, int type)
{
int result;
priv->max_ib_mtu = ppriv->max_ib_mtu;
priv->dev->mtu = IPOIB_UD_MTU(priv->max_ib_mtu);
priv->mcast_mtu = priv->admin_mtu = priv->dev->mtu;
priv->parent = ppriv->dev;
set_bit(IPOIB_FLAG_SUBINTERFACE, &priv->flags);
result = ipoib_set_dev_features(priv, ppriv->ca);
if (result)
goto err;
priv->pkey = pkey;
memcpy(priv->dev->dev_addr, ppriv->dev->dev_addr, INFINIBAND_ALEN);
priv->dev->broadcast[8] = pkey >> 8;
priv->dev->broadcast[9] = pkey & 0xff;
result = ipoib_dev_init(priv->dev, ppriv->ca, ppriv->port);
if (result < 0) {
ipoib_warn(ppriv, "failed to initialize subinterface: "
"device %s, port %d",
ppriv->ca->name, ppriv->port);
goto err;
}
result = register_netdevice(priv->dev);
if (result) {
ipoib_warn(priv, "failed to initialize; error %i", result);
goto register_failed;
}
ipoib_create_debug_files(priv->dev);
if (type == IPOIB_LEGACY_CHILD) {
if (ipoib_cm_add_mode_attr(priv->dev))
goto sysfs_failed;
if (ipoib_add_pkey_attr(priv->dev))
goto sysfs_failed;
if (ipoib_add_umcast_attr(priv->dev))
goto sysfs_failed;
if (device_create_file(&priv->dev->dev, &dev_attr_parent))
goto sysfs_failed;
}
priv->child_type = type;
list_add_tail(&priv->list, &ppriv->child_intfs);
return 0;
sysfs_failed:
result = -ENOMEM;
ipoib_delete_debug_files(priv->dev);
unregister_netdevice(priv->dev);
register_failed:
ipoib_dev_cleanup(priv->dev);
err:
return result;
}
int ipoib_vlan_add(struct net_device *pdev, unsigned short pkey)
{
struct ipoib_dev_priv *ppriv, *priv;
char intf_name[IFNAMSIZ];
struct ipoib_dev_priv *tpriv;
int result;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
ppriv = netdev_priv(pdev);
snprintf(intf_name, sizeof intf_name, "%s.%04x",
ppriv->dev->name, pkey);
priv = ipoib_intf_alloc(intf_name);
if (!priv)
return -ENOMEM;
if (!rtnl_trylock())
return restart_syscall();
down_write(&ppriv->vlan_rwsem);
if (ppriv->pkey == pkey) {
result = -ENOTUNIQ;
goto out;
}
list_for_each_entry(tpriv, &ppriv->child_intfs, list) {
if (tpriv->pkey == pkey &&
tpriv->child_type == IPOIB_LEGACY_CHILD) {
result = -ENOTUNIQ;
goto out;
}
}
result = __ipoib_vlan_add(ppriv, priv, pkey, IPOIB_LEGACY_CHILD);
out:
up_write(&ppriv->vlan_rwsem);
if (result)
free_netdev(priv->dev);
rtnl_unlock();
return result;
}
int ipoib_vlan_delete(struct net_device *pdev, unsigned short pkey)
{
struct ipoib_dev_priv *ppriv, *priv, *tpriv;
struct net_device *dev = NULL;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
ppriv = netdev_priv(pdev);
if (!rtnl_trylock())
return restart_syscall();
down_write(&ppriv->vlan_rwsem);
list_for_each_entry_safe(priv, tpriv, &ppriv->child_intfs, list) {
if (priv->pkey == pkey &&
priv->child_type == IPOIB_LEGACY_CHILD) {
unregister_netdevice(priv->dev);
list_del(&priv->list);
dev = priv->dev;
break;
}
}
up_write(&ppriv->vlan_rwsem);
rtnl_unlock();
if (dev) {
free_netdev(dev);
return 0;
}
return -ENODEV;
}
