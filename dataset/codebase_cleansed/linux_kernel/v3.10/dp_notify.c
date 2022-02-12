static void dp_detach_port_notify(struct vport *vport)
{
struct sk_buff *notify;
struct datapath *dp;
dp = vport->dp;
notify = ovs_vport_cmd_build_info(vport, 0, 0,
OVS_VPORT_CMD_DEL);
ovs_dp_detach_port(vport);
if (IS_ERR(notify)) {
netlink_set_err(ovs_dp_get_net(dp)->genl_sock, 0,
ovs_dp_vport_multicast_group.id,
PTR_ERR(notify));
return;
}
genlmsg_multicast_netns(ovs_dp_get_net(dp), notify, 0,
ovs_dp_vport_multicast_group.id,
GFP_KERNEL);
}
void ovs_dp_notify_wq(struct work_struct *work)
{
struct ovs_net *ovs_net = container_of(work, struct ovs_net, dp_notify_work);
struct datapath *dp;
ovs_lock();
list_for_each_entry(dp, &ovs_net->dps, list_node) {
int i;
for (i = 0; i < DP_VPORT_HASH_BUCKETS; i++) {
struct vport *vport;
struct hlist_node *n;
hlist_for_each_entry_safe(vport, n, &dp->ports[i], dp_hash_node) {
struct netdev_vport *netdev_vport;
if (vport->ops->type != OVS_VPORT_TYPE_NETDEV)
continue;
netdev_vport = netdev_vport_priv(vport);
if (netdev_vport->dev->reg_state == NETREG_UNREGISTERED ||
netdev_vport->dev->reg_state == NETREG_UNREGISTERING)
dp_detach_port_notify(vport);
}
}
}
ovs_unlock();
}
static int dp_device_event(struct notifier_block *unused, unsigned long event,
void *ptr)
{
struct ovs_net *ovs_net;
struct net_device *dev = ptr;
struct vport *vport = NULL;
if (!ovs_is_internal_dev(dev))
vport = ovs_netdev_get_vport(dev);
if (!vport)
return NOTIFY_DONE;
if (event == NETDEV_UNREGISTER) {
ovs_net = net_generic(dev_net(dev), ovs_net_id);
queue_work(system_wq, &ovs_net->dp_notify_work);
}
return NOTIFY_DONE;
}
