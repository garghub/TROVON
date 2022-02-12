static const void *ipvtap_net_namespace(struct device *d)
{
struct net_device *dev = to_net_dev(d->parent);
return dev_net(dev);
}
static void ipvtap_count_tx_dropped(struct tap_dev *tap)
{
struct ipvtap_dev *vlantap = container_of(tap, struct ipvtap_dev, tap);
struct ipvl_dev *vlan = &vlantap->vlan;
this_cpu_inc(vlan->pcpu_stats->tx_drps);
}
static void ipvtap_count_rx_dropped(struct tap_dev *tap)
{
struct ipvtap_dev *vlantap = container_of(tap, struct ipvtap_dev, tap);
struct ipvl_dev *vlan = &vlantap->vlan;
ipvlan_count_rx(vlan, 0, 0, 0);
}
static void ipvtap_update_features(struct tap_dev *tap,
netdev_features_t features)
{
struct ipvtap_dev *vlantap = container_of(tap, struct ipvtap_dev, tap);
struct ipvl_dev *vlan = &vlantap->vlan;
vlan->sfeatures = features;
netdev_update_features(vlan->dev);
}
static int ipvtap_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[],
struct netlink_ext_ack *extack)
{
struct ipvtap_dev *vlantap = netdev_priv(dev);
int err;
INIT_LIST_HEAD(&vlantap->tap.queue_list);
vlantap->tap.tap_features = TUN_OFFLOADS;
vlantap->tap.count_tx_dropped = ipvtap_count_tx_dropped;
vlantap->tap.update_features = ipvtap_update_features;
vlantap->tap.count_rx_dropped = ipvtap_count_rx_dropped;
err = netdev_rx_handler_register(dev, tap_handle_frame, &vlantap->tap);
if (err)
return err;
err = ipvlan_link_new(src_net, dev, tb, data, extack);
if (err) {
netdev_rx_handler_unregister(dev);
return err;
}
vlantap->tap.dev = vlantap->vlan.dev;
return err;
}
static void ipvtap_dellink(struct net_device *dev,
struct list_head *head)
{
struct ipvtap_dev *vlan = netdev_priv(dev);
netdev_rx_handler_unregister(dev);
tap_del_queues(&vlan->tap);
ipvlan_link_delete(dev, head);
}
static void ipvtap_setup(struct net_device *dev)
{
ipvlan_link_setup(dev);
dev->tx_queue_len = TUN_READQ_SIZE;
dev->priv_flags &= ~IFF_NO_QUEUE;
}
static int ipvtap_device_event(struct notifier_block *unused,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct ipvtap_dev *vlantap;
struct device *classdev;
dev_t devt;
int err;
char tap_name[IFNAMSIZ];
if (dev->rtnl_link_ops != &ipvtap_link_ops)
return NOTIFY_DONE;
snprintf(tap_name, IFNAMSIZ, "tap%d", dev->ifindex);
vlantap = netdev_priv(dev);
switch (event) {
case NETDEV_REGISTER:
err = tap_get_minor(ipvtap_major, &vlantap->tap);
if (err)
return notifier_from_errno(err);
devt = MKDEV(MAJOR(ipvtap_major), vlantap->tap.minor);
classdev = device_create(&ipvtap_class, &dev->dev, devt,
dev, tap_name);
if (IS_ERR(classdev)) {
tap_free_minor(ipvtap_major, &vlantap->tap);
return notifier_from_errno(PTR_ERR(classdev));
}
err = sysfs_create_link(&dev->dev.kobj, &classdev->kobj,
tap_name);
if (err)
return notifier_from_errno(err);
break;
case NETDEV_UNREGISTER:
if (vlantap->tap.minor == 0)
break;
sysfs_remove_link(&dev->dev.kobj, tap_name);
devt = MKDEV(MAJOR(ipvtap_major), vlantap->tap.minor);
device_destroy(&ipvtap_class, devt);
tap_free_minor(ipvtap_major, &vlantap->tap);
break;
case NETDEV_CHANGE_TX_QUEUE_LEN:
if (tap_queue_resize(&vlantap->tap))
return NOTIFY_BAD;
break;
}
return NOTIFY_DONE;
}
static int ipvtap_init(void)
{
int err;
err = tap_create_cdev(&ipvtap_cdev, &ipvtap_major, "ipvtap",
THIS_MODULE);
if (err)
goto out1;
err = class_register(&ipvtap_class);
if (err)
goto out2;
err = register_netdevice_notifier(&ipvtap_notifier_block);
if (err)
goto out3;
err = ipvlan_link_register(&ipvtap_link_ops);
if (err)
goto out4;
return 0;
out4:
unregister_netdevice_notifier(&ipvtap_notifier_block);
out3:
class_unregister(&ipvtap_class);
out2:
tap_destroy_cdev(ipvtap_major, &ipvtap_cdev);
out1:
return err;
}
static void ipvtap_exit(void)
{
rtnl_link_unregister(&ipvtap_link_ops);
unregister_netdevice_notifier(&ipvtap_notifier_block);
class_unregister(&ipvtap_class);
tap_destroy_cdev(ipvtap_major, &ipvtap_cdev);
}
