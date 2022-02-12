static int vlan_group_prealloc_vid(struct vlan_group *vg,
__be16 vlan_proto, u16 vlan_id)
{
struct net_device **array;
unsigned int pidx, vidx;
unsigned int size;
ASSERT_RTNL();
pidx = vlan_proto_idx(vlan_proto);
vidx = vlan_id / VLAN_GROUP_ARRAY_PART_LEN;
array = vg->vlan_devices_arrays[pidx][vidx];
if (array != NULL)
return 0;
size = sizeof(struct net_device *) * VLAN_GROUP_ARRAY_PART_LEN;
array = kzalloc(size, GFP_KERNEL);
if (array == NULL)
return -ENOBUFS;
vg->vlan_devices_arrays[pidx][vidx] = array;
return 0;
}
void unregister_vlan_dev(struct net_device *dev, struct list_head *head)
{
struct vlan_dev_priv *vlan = vlan_dev_priv(dev);
struct net_device *real_dev = vlan->real_dev;
struct vlan_info *vlan_info;
struct vlan_group *grp;
u16 vlan_id = vlan->vlan_id;
ASSERT_RTNL();
vlan_info = rtnl_dereference(real_dev->vlan_info);
BUG_ON(!vlan_info);
grp = &vlan_info->grp;
grp->nr_vlan_devs--;
if (vlan->flags & VLAN_FLAG_MVRP)
vlan_mvrp_request_leave(dev);
if (vlan->flags & VLAN_FLAG_GVRP)
vlan_gvrp_request_leave(dev);
vlan_group_set_device(grp, vlan->vlan_proto, vlan_id, NULL);
netdev_upper_dev_unlink(real_dev, dev);
unregister_netdevice_queue(dev, head);
if (grp->nr_vlan_devs == 0) {
vlan_mvrp_uninit_applicant(real_dev);
vlan_gvrp_uninit_applicant(real_dev);
}
if (vlan_id)
vlan_vid_del(real_dev, vlan->vlan_proto, vlan_id);
dev_put(real_dev);
}
int vlan_check_real_dev(struct net_device *real_dev,
__be16 protocol, u16 vlan_id)
{
const char *name = real_dev->name;
if (real_dev->features & NETIF_F_VLAN_CHALLENGED) {
pr_info("VLANs not supported on %s\n", name);
return -EOPNOTSUPP;
}
if (vlan_find_dev(real_dev, protocol, vlan_id) != NULL)
return -EEXIST;
return 0;
}
int register_vlan_dev(struct net_device *dev)
{
struct vlan_dev_priv *vlan = vlan_dev_priv(dev);
struct net_device *real_dev = vlan->real_dev;
u16 vlan_id = vlan->vlan_id;
struct vlan_info *vlan_info;
struct vlan_group *grp;
int err;
err = vlan_vid_add(real_dev, vlan->vlan_proto, vlan_id);
if (err)
return err;
vlan_info = rtnl_dereference(real_dev->vlan_info);
BUG_ON(!vlan_info);
grp = &vlan_info->grp;
if (grp->nr_vlan_devs == 0) {
err = vlan_gvrp_init_applicant(real_dev);
if (err < 0)
goto out_vid_del;
err = vlan_mvrp_init_applicant(real_dev);
if (err < 0)
goto out_uninit_gvrp;
}
err = vlan_group_prealloc_vid(grp, vlan->vlan_proto, vlan_id);
if (err < 0)
goto out_uninit_mvrp;
err = register_netdevice(dev);
if (err < 0)
goto out_uninit_mvrp;
err = netdev_upper_dev_link(real_dev, dev);
if (err)
goto out_unregister_netdev;
dev_hold(real_dev);
netif_stacked_transfer_operstate(real_dev, dev);
linkwatch_fire_event(dev);
vlan_group_set_device(grp, vlan->vlan_proto, vlan_id, dev);
grp->nr_vlan_devs++;
return 0;
out_unregister_netdev:
unregister_netdevice(dev);
out_uninit_mvrp:
if (grp->nr_vlan_devs == 0)
vlan_mvrp_uninit_applicant(real_dev);
out_uninit_gvrp:
if (grp->nr_vlan_devs == 0)
vlan_gvrp_uninit_applicant(real_dev);
out_vid_del:
vlan_vid_del(real_dev, vlan->vlan_proto, vlan_id);
return err;
}
static int register_vlan_device(struct net_device *real_dev, u16 vlan_id)
{
struct net_device *new_dev;
struct vlan_dev_priv *vlan;
struct net *net = dev_net(real_dev);
struct vlan_net *vn = net_generic(net, vlan_net_id);
char name[IFNAMSIZ];
int err;
if (vlan_id >= VLAN_VID_MASK)
return -ERANGE;
err = vlan_check_real_dev(real_dev, htons(ETH_P_8021Q), vlan_id);
if (err < 0)
return err;
switch (vn->name_type) {
case VLAN_NAME_TYPE_RAW_PLUS_VID:
snprintf(name, IFNAMSIZ, "%s.%.4i", real_dev->name, vlan_id);
break;
case VLAN_NAME_TYPE_PLUS_VID_NO_PAD:
snprintf(name, IFNAMSIZ, "vlan%i", vlan_id);
break;
case VLAN_NAME_TYPE_RAW_PLUS_VID_NO_PAD:
snprintf(name, IFNAMSIZ, "%s.%i", real_dev->name, vlan_id);
break;
case VLAN_NAME_TYPE_PLUS_VID:
default:
snprintf(name, IFNAMSIZ, "vlan%.4i", vlan_id);
}
new_dev = alloc_netdev(sizeof(struct vlan_dev_priv), name, vlan_setup);
if (new_dev == NULL)
return -ENOBUFS;
dev_net_set(new_dev, net);
new_dev->mtu = real_dev->mtu;
new_dev->priv_flags |= (real_dev->priv_flags & IFF_UNICAST_FLT);
vlan = vlan_dev_priv(new_dev);
vlan->vlan_proto = htons(ETH_P_8021Q);
vlan->vlan_id = vlan_id;
vlan->real_dev = real_dev;
vlan->dent = NULL;
vlan->flags = VLAN_FLAG_REORDER_HDR;
new_dev->rtnl_link_ops = &vlan_link_ops;
err = register_vlan_dev(new_dev);
if (err < 0)
goto out_free_newdev;
return 0;
out_free_newdev:
free_netdev(new_dev);
return err;
}
static void vlan_sync_address(struct net_device *dev,
struct net_device *vlandev)
{
struct vlan_dev_priv *vlan = vlan_dev_priv(vlandev);
if (ether_addr_equal(vlan->real_dev_addr, dev->dev_addr))
return;
if (!ether_addr_equal(vlandev->dev_addr, vlan->real_dev_addr) &&
ether_addr_equal(vlandev->dev_addr, dev->dev_addr))
dev_uc_del(dev, vlandev->dev_addr);
if (ether_addr_equal(vlandev->dev_addr, vlan->real_dev_addr) &&
!ether_addr_equal(vlandev->dev_addr, dev->dev_addr))
dev_uc_add(dev, vlandev->dev_addr);
memcpy(vlan->real_dev_addr, dev->dev_addr, ETH_ALEN);
}
static void vlan_transfer_features(struct net_device *dev,
struct net_device *vlandev)
{
vlandev->gso_max_size = dev->gso_max_size;
if (dev->features & NETIF_F_HW_VLAN_CTAG_TX)
vlandev->hard_header_len = dev->hard_header_len;
else
vlandev->hard_header_len = dev->hard_header_len + VLAN_HLEN;
#if IS_ENABLED(CONFIG_FCOE)
vlandev->fcoe_ddp_xid = dev->fcoe_ddp_xid;
#endif
netdev_update_features(vlandev);
}
static void __vlan_device_event(struct net_device *dev, unsigned long event)
{
switch (event) {
case NETDEV_CHANGENAME:
vlan_proc_rem_dev(dev);
if (vlan_proc_add_dev(dev) < 0)
pr_warn("failed to change proc name for %s\n",
dev->name);
break;
case NETDEV_REGISTER:
if (vlan_proc_add_dev(dev) < 0)
pr_warn("failed to add proc entry for %s\n", dev->name);
break;
case NETDEV_UNREGISTER:
vlan_proc_rem_dev(dev);
break;
}
}
static int vlan_device_event(struct notifier_block *unused, unsigned long event,
void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct vlan_group *grp;
struct vlan_info *vlan_info;
int i, flgs;
struct net_device *vlandev;
struct vlan_dev_priv *vlan;
bool last = false;
LIST_HEAD(list);
if (is_vlan_dev(dev))
__vlan_device_event(dev, event);
if ((event == NETDEV_UP) &&
(dev->features & NETIF_F_HW_VLAN_CTAG_FILTER)) {
pr_info("adding VLAN 0 to HW filter on device %s\n",
dev->name);
vlan_vid_add(dev, htons(ETH_P_8021Q), 0);
}
vlan_info = rtnl_dereference(dev->vlan_info);
if (!vlan_info)
goto out;
grp = &vlan_info->grp;
switch (event) {
case NETDEV_CHANGE:
vlan_group_for_each_dev(grp, i, vlandev)
netif_stacked_transfer_operstate(dev, vlandev);
break;
case NETDEV_CHANGEADDR:
vlan_group_for_each_dev(grp, i, vlandev) {
flgs = vlandev->flags;
if (!(flgs & IFF_UP))
continue;
vlan_sync_address(dev, vlandev);
}
break;
case NETDEV_CHANGEMTU:
vlan_group_for_each_dev(grp, i, vlandev) {
if (vlandev->mtu <= dev->mtu)
continue;
dev_set_mtu(vlandev, dev->mtu);
}
break;
case NETDEV_FEAT_CHANGE:
vlan_group_for_each_dev(grp, i, vlandev)
vlan_transfer_features(dev, vlandev);
break;
case NETDEV_DOWN:
if (dev->features & NETIF_F_HW_VLAN_CTAG_FILTER)
vlan_vid_del(dev, htons(ETH_P_8021Q), 0);
vlan_group_for_each_dev(grp, i, vlandev) {
flgs = vlandev->flags;
if (!(flgs & IFF_UP))
continue;
vlan = vlan_dev_priv(vlandev);
if (!(vlan->flags & VLAN_FLAG_LOOSE_BINDING))
dev_change_flags(vlandev, flgs & ~IFF_UP);
netif_stacked_transfer_operstate(dev, vlandev);
}
break;
case NETDEV_UP:
vlan_group_for_each_dev(grp, i, vlandev) {
flgs = vlandev->flags;
if (flgs & IFF_UP)
continue;
vlan = vlan_dev_priv(vlandev);
if (!(vlan->flags & VLAN_FLAG_LOOSE_BINDING))
dev_change_flags(vlandev, flgs | IFF_UP);
netif_stacked_transfer_operstate(dev, vlandev);
}
break;
case NETDEV_UNREGISTER:
if (dev->reg_state != NETREG_UNREGISTERING)
break;
vlan_group_for_each_dev(grp, i, vlandev) {
if (vlan_info->nr_vids == 1)
last = true;
unregister_vlan_dev(vlandev, &list);
if (last)
break;
}
unregister_netdevice_many(&list);
break;
case NETDEV_PRE_TYPE_CHANGE:
if (vlan_uses_dev(dev))
return NOTIFY_BAD;
break;
case NETDEV_NOTIFY_PEERS:
case NETDEV_BONDING_FAILOVER:
case NETDEV_RESEND_IGMP:
vlan_group_for_each_dev(grp, i, vlandev)
call_netdevice_notifiers(event, vlandev);
break;
}
out:
return NOTIFY_DONE;
}
static int vlan_ioctl_handler(struct net *net, void __user *arg)
{
int err;
struct vlan_ioctl_args args;
struct net_device *dev = NULL;
if (copy_from_user(&args, arg, sizeof(struct vlan_ioctl_args)))
return -EFAULT;
args.device1[23] = 0;
args.u.device2[23] = 0;
rtnl_lock();
switch (args.cmd) {
case SET_VLAN_INGRESS_PRIORITY_CMD:
case SET_VLAN_EGRESS_PRIORITY_CMD:
case SET_VLAN_FLAG_CMD:
case ADD_VLAN_CMD:
case DEL_VLAN_CMD:
case GET_VLAN_REALDEV_NAME_CMD:
case GET_VLAN_VID_CMD:
err = -ENODEV;
dev = __dev_get_by_name(net, args.device1);
if (!dev)
goto out;
err = -EINVAL;
if (args.cmd != ADD_VLAN_CMD && !is_vlan_dev(dev))
goto out;
}
switch (args.cmd) {
case SET_VLAN_INGRESS_PRIORITY_CMD:
err = -EPERM;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
break;
vlan_dev_set_ingress_priority(dev,
args.u.skb_priority,
args.vlan_qos);
err = 0;
break;
case SET_VLAN_EGRESS_PRIORITY_CMD:
err = -EPERM;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
break;
err = vlan_dev_set_egress_priority(dev,
args.u.skb_priority,
args.vlan_qos);
break;
case SET_VLAN_FLAG_CMD:
err = -EPERM;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
break;
err = vlan_dev_change_flags(dev,
args.vlan_qos ? args.u.flag : 0,
args.u.flag);
break;
case SET_VLAN_NAME_TYPE_CMD:
err = -EPERM;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
break;
if ((args.u.name_type >= 0) &&
(args.u.name_type < VLAN_NAME_TYPE_HIGHEST)) {
struct vlan_net *vn;
vn = net_generic(net, vlan_net_id);
vn->name_type = args.u.name_type;
err = 0;
} else {
err = -EINVAL;
}
break;
case ADD_VLAN_CMD:
err = -EPERM;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
break;
err = register_vlan_device(dev, args.u.VID);
break;
case DEL_VLAN_CMD:
err = -EPERM;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
break;
unregister_vlan_dev(dev, NULL);
err = 0;
break;
case GET_VLAN_REALDEV_NAME_CMD:
err = 0;
vlan_dev_get_realdev_name(dev, args.u.device2);
if (copy_to_user(arg, &args,
sizeof(struct vlan_ioctl_args)))
err = -EFAULT;
break;
case GET_VLAN_VID_CMD:
err = 0;
args.u.VID = vlan_dev_vlan_id(dev);
if (copy_to_user(arg, &args,
sizeof(struct vlan_ioctl_args)))
err = -EFAULT;
break;
default:
err = -EOPNOTSUPP;
break;
}
out:
rtnl_unlock();
return err;
}
static int __net_init vlan_init_net(struct net *net)
{
struct vlan_net *vn = net_generic(net, vlan_net_id);
int err;
vn->name_type = VLAN_NAME_TYPE_RAW_PLUS_VID_NO_PAD;
err = vlan_proc_init(net);
return err;
}
static void __net_exit vlan_exit_net(struct net *net)
{
vlan_proc_cleanup(net);
}
static int __init vlan_proto_init(void)
{
int err;
pr_info("%s v%s\n", vlan_fullname, vlan_version);
err = register_pernet_subsys(&vlan_net_ops);
if (err < 0)
goto err0;
err = register_netdevice_notifier(&vlan_notifier_block);
if (err < 0)
goto err2;
err = vlan_gvrp_init();
if (err < 0)
goto err3;
err = vlan_mvrp_init();
if (err < 0)
goto err4;
err = vlan_netlink_init();
if (err < 0)
goto err5;
vlan_ioctl_set(vlan_ioctl_handler);
return 0;
err5:
vlan_mvrp_uninit();
err4:
vlan_gvrp_uninit();
err3:
unregister_netdevice_notifier(&vlan_notifier_block);
err2:
unregister_pernet_subsys(&vlan_net_ops);
err0:
return err;
}
static void __exit vlan_cleanup_module(void)
{
vlan_ioctl_set(NULL);
vlan_netlink_fini();
unregister_netdevice_notifier(&vlan_notifier_block);
unregister_pernet_subsys(&vlan_net_ops);
rcu_barrier();
vlan_mvrp_uninit();
vlan_gvrp_uninit();
}
