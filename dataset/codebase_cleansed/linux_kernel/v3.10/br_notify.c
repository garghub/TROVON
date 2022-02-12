static int br_device_event(struct notifier_block *unused, unsigned long event, void *ptr)
{
struct net_device *dev = ptr;
struct net_bridge_port *p;
struct net_bridge *br;
bool changed_addr;
int err;
if ((dev->priv_flags & IFF_EBRIDGE) && event == NETDEV_REGISTER) {
br_sysfs_addbr(dev);
return NOTIFY_DONE;
}
p = br_port_get_rtnl(dev);
if (!p)
return NOTIFY_DONE;
br = p->br;
switch (event) {
case NETDEV_CHANGEMTU:
dev_set_mtu(br->dev, br_min_mtu(br));
break;
case NETDEV_CHANGEADDR:
spin_lock_bh(&br->lock);
br_fdb_changeaddr(p, dev->dev_addr);
changed_addr = br_stp_recalculate_bridge_id(br);
spin_unlock_bh(&br->lock);
if (changed_addr)
call_netdevice_notifiers(NETDEV_CHANGEADDR, br->dev);
break;
case NETDEV_CHANGE:
br_port_carrier_check(p);
break;
case NETDEV_FEAT_CHANGE:
netdev_update_features(br->dev);
break;
case NETDEV_DOWN:
spin_lock_bh(&br->lock);
if (br->dev->flags & IFF_UP)
br_stp_disable_port(p);
spin_unlock_bh(&br->lock);
break;
case NETDEV_UP:
if (netif_running(br->dev) && netif_oper_up(dev)) {
spin_lock_bh(&br->lock);
br_stp_enable_port(p);
spin_unlock_bh(&br->lock);
}
break;
case NETDEV_UNREGISTER:
br_del_if(br, dev);
break;
case NETDEV_CHANGENAME:
err = br_sysfs_renameif(p);
if (err)
return notifier_from_errno(err);
break;
case NETDEV_PRE_TYPE_CHANGE:
return NOTIFY_BAD;
}
if (event == NETDEV_CHANGEADDR || event == NETDEV_UP ||
event == NETDEV_CHANGE || event == NETDEV_DOWN)
br_ifinfo_notify(RTM_NEWLINK, p);
return NOTIFY_DONE;
}
