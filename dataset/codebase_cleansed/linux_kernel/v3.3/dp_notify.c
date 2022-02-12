static int dp_device_event(struct notifier_block *unused, unsigned long event,
void *ptr)
{
struct net_device *dev = ptr;
struct vport *vport;
if (ovs_is_internal_dev(dev))
vport = ovs_internal_dev_get_vport(dev);
else
vport = ovs_netdev_get_vport(dev);
if (!vport)
return NOTIFY_DONE;
switch (event) {
case NETDEV_UNREGISTER:
if (!ovs_is_internal_dev(dev)) {
struct sk_buff *notify;
notify = ovs_vport_cmd_build_info(vport, 0, 0,
OVS_VPORT_CMD_DEL);
ovs_dp_detach_port(vport);
if (IS_ERR(notify)) {
netlink_set_err(init_net.genl_sock, 0,
ovs_dp_vport_multicast_group.id,
PTR_ERR(notify));
break;
}
genlmsg_multicast(notify, 0, ovs_dp_vport_multicast_group.id,
GFP_KERNEL);
}
break;
}
return NOTIFY_DONE;
}
