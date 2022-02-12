static int hsr_netdev_notify(struct notifier_block *nb, unsigned long event,
void *ptr)
{
struct net_device *dev;
struct hsr_port *port, *master;
struct hsr_priv *hsr;
int mtu_max;
int res;
dev = netdev_notifier_info_to_dev(ptr);
port = hsr_port_get_rtnl(dev);
if (port == NULL) {
if (!is_hsr_master(dev))
return NOTIFY_DONE;
hsr = netdev_priv(dev);
port = hsr_port_get_hsr(hsr, HSR_PT_MASTER);
} else {
hsr = port->hsr;
}
switch (event) {
case NETDEV_UP:
case NETDEV_DOWN:
case NETDEV_CHANGE:
hsr_check_carrier_and_operstate(hsr);
break;
case NETDEV_CHANGEADDR:
if (port->type == HSR_PT_MASTER) {
break;
}
master = hsr_port_get_hsr(hsr, HSR_PT_MASTER);
if (port->type == HSR_PT_SLAVE_A) {
ether_addr_copy(master->dev->dev_addr, dev->dev_addr);
call_netdevice_notifiers(NETDEV_CHANGEADDR, master->dev);
}
port = hsr_port_get_hsr(hsr, HSR_PT_SLAVE_B);
res = hsr_create_self_node(&hsr->self_node_db,
master->dev->dev_addr,
port ?
port->dev->dev_addr :
master->dev->dev_addr);
if (res)
netdev_warn(master->dev,
"Could not update HSR node address.\n");
break;
case NETDEV_CHANGEMTU:
if (port->type == HSR_PT_MASTER)
break;
mtu_max = hsr_get_max_mtu(port->hsr);
master = hsr_port_get_hsr(port->hsr, HSR_PT_MASTER);
master->dev->mtu = mtu_max;
break;
case NETDEV_UNREGISTER:
hsr_del_port(port);
break;
case NETDEV_PRE_TYPE_CHANGE:
return NOTIFY_BAD;
}
return NOTIFY_DONE;
}
struct hsr_port *hsr_port_get_hsr(struct hsr_priv *hsr, enum hsr_port_type pt)
{
struct hsr_port *port;
hsr_for_each_port(hsr, port)
if (port->type == pt)
return port;
return NULL;
}
static int __init hsr_init(void)
{
int res;
BUILD_BUG_ON(sizeof(struct hsr_tag) != HSR_HLEN);
register_netdevice_notifier(&hsr_nb);
res = hsr_netlink_init();
return res;
}
static void __exit hsr_exit(void)
{
unregister_netdevice_notifier(&hsr_nb);
hsr_netlink_exit();
}
