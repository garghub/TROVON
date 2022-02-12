static const void *macvtap_net_namespace(struct device *d)
{
struct net_device *dev = to_net_dev(d->parent);
return dev_net(dev);
}
static void macvtap_count_tx_dropped(struct tap_dev *tap)
{
struct macvtap_dev *vlantap = container_of(tap, struct macvtap_dev, tap);
struct macvlan_dev *vlan = &vlantap->vlan;
this_cpu_inc(vlan->pcpu_stats->tx_dropped);
}
static void macvtap_count_rx_dropped(struct tap_dev *tap)
{
struct macvtap_dev *vlantap = container_of(tap, struct macvtap_dev, tap);
struct macvlan_dev *vlan = &vlantap->vlan;
macvlan_count_rx(vlan, 0, 0, 0);
}
static void macvtap_update_features(struct tap_dev *tap,
netdev_features_t features)
{
struct macvtap_dev *vlantap = container_of(tap, struct macvtap_dev, tap);
struct macvlan_dev *vlan = &vlantap->vlan;
vlan->set_features = features;
netdev_update_features(vlan->dev);
}
static int macvtap_newlink(struct net *src_net,
struct net_device *dev,
struct nlattr *tb[],
struct nlattr *data[])
{
struct macvtap_dev *vlantap = netdev_priv(dev);
int err;
INIT_LIST_HEAD(&vlantap->tap.queue_list);
vlantap->tap.tap_features = TUN_OFFLOADS;
vlantap->tap.count_tx_dropped = macvtap_count_tx_dropped;
vlantap->tap.count_rx_dropped = macvtap_count_rx_dropped;
vlantap->tap.update_features = macvtap_update_features;
err = netdev_rx_handler_register(dev, tap_handle_frame, &vlantap->tap);
if (err)
return err;
err = macvlan_common_newlink(src_net, dev, tb, data);
if (err) {
netdev_rx_handler_unregister(dev);
return err;
}
vlantap->tap.dev = vlantap->vlan.dev;
return 0;
}
static void macvtap_dellink(struct net_device *dev,
struct list_head *head)
{
struct macvtap_dev *vlantap = netdev_priv(dev);
netdev_rx_handler_unregister(dev);
tap_del_queues(&vlantap->tap);
macvlan_dellink(dev, head);
}
static void macvtap_setup(struct net_device *dev)
{
macvlan_common_setup(dev);
dev->tx_queue_len = TUN_READQ_SIZE;
}
static int macvtap_device_event(struct notifier_block *unused,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct macvtap_dev *vlantap;
struct device *classdev;
dev_t devt;
int err;
char tap_name[IFNAMSIZ];
if (dev->rtnl_link_ops != &macvtap_link_ops)
return NOTIFY_DONE;
snprintf(tap_name, IFNAMSIZ, "tap%d", dev->ifindex);
vlantap = netdev_priv(dev);
switch (event) {
case NETDEV_REGISTER:
err = tap_get_minor(macvtap_major, &vlantap->tap);
if (err)
return notifier_from_errno(err);
devt = MKDEV(MAJOR(macvtap_major), vlantap->tap.minor);
classdev = device_create(&macvtap_class, &dev->dev, devt,
dev, tap_name);
if (IS_ERR(classdev)) {
tap_free_minor(macvtap_major, &vlantap->tap);
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
devt = MKDEV(MAJOR(macvtap_major), vlantap->tap.minor);
device_destroy(&macvtap_class, devt);
tap_free_minor(macvtap_major, &vlantap->tap);
break;
case NETDEV_CHANGE_TX_QUEUE_LEN:
if (tap_queue_resize(&vlantap->tap))
return NOTIFY_BAD;
break;
}
return NOTIFY_DONE;
}
static int macvtap_init(void)
{
int err;
err = tap_create_cdev(&macvtap_cdev, &macvtap_major, "macvtap");
if (err)
goto out1;
err = class_register(&macvtap_class);
if (err)
goto out2;
err = register_netdevice_notifier(&macvtap_notifier_block);
if (err)
goto out3;
err = macvlan_link_register(&macvtap_link_ops);
if (err)
goto out4;
return 0;
out4:
unregister_netdevice_notifier(&macvtap_notifier_block);
out3:
class_unregister(&macvtap_class);
out2:
tap_destroy_cdev(macvtap_major, &macvtap_cdev);
out1:
return err;
}
static void macvtap_exit(void)
{
rtnl_link_unregister(&macvtap_link_ops);
unregister_netdevice_notifier(&macvtap_notifier_block);
class_unregister(&macvtap_class);
tap_destroy_cdev(macvtap_major, &macvtap_cdev);
}
