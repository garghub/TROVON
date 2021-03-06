static ssize_t show_parent(struct device *d, struct device_attribute *attr,
char *buf)
{
struct net_device *dev = to_net_dev(d);
struct ipoib_dev_priv *priv = netdev_priv(dev);
return sprintf(buf, "%s\n", priv->parent->name);
}
int ipoib_vlan_add(struct net_device *pdev, unsigned short pkey)
{
struct ipoib_dev_priv *ppriv, *priv;
char intf_name[IFNAMSIZ];
int result;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
ppriv = netdev_priv(pdev);
if (!rtnl_trylock())
return restart_syscall();
mutex_lock(&ppriv->vlan_mutex);
if (ppriv->pkey == pkey) {
result = -ENOTUNIQ;
priv = NULL;
goto err;
}
list_for_each_entry(priv, &ppriv->child_intfs, list) {
if (priv->pkey == pkey) {
result = -ENOTUNIQ;
priv = NULL;
goto err;
}
}
snprintf(intf_name, sizeof intf_name, "%s.%04x",
ppriv->dev->name, pkey);
priv = ipoib_intf_alloc(intf_name);
if (!priv) {
result = -ENOMEM;
goto err;
}
priv->max_ib_mtu = ppriv->max_ib_mtu;
priv->dev->mtu = IPOIB_UD_MTU(priv->max_ib_mtu);
priv->mcast_mtu = priv->admin_mtu = priv->dev->mtu;
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
priv->parent = ppriv->dev;
ipoib_create_debug_files(priv->dev);
if (ipoib_cm_add_mode_attr(priv->dev))
goto sysfs_failed;
if (ipoib_add_pkey_attr(priv->dev))
goto sysfs_failed;
if (ipoib_add_umcast_attr(priv->dev))
goto sysfs_failed;
if (device_create_file(&priv->dev->dev, &dev_attr_parent))
goto sysfs_failed;
list_add_tail(&priv->list, &ppriv->child_intfs);
mutex_unlock(&ppriv->vlan_mutex);
rtnl_unlock();
return 0;
sysfs_failed:
ipoib_delete_debug_files(priv->dev);
unregister_netdevice(priv->dev);
register_failed:
ipoib_dev_cleanup(priv->dev);
err:
mutex_unlock(&ppriv->vlan_mutex);
rtnl_unlock();
if (priv)
free_netdev(priv->dev);
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
mutex_lock(&ppriv->vlan_mutex);
list_for_each_entry_safe(priv, tpriv, &ppriv->child_intfs, list) {
if (priv->pkey == pkey) {
unregister_netdevice(priv->dev);
ipoib_dev_cleanup(priv->dev);
list_del(&priv->list);
dev = priv->dev;
break;
}
}
mutex_unlock(&ppriv->vlan_mutex);
rtnl_unlock();
if (dev) {
free_netdev(dev);
return 0;
}
return -ENODEV;
}
