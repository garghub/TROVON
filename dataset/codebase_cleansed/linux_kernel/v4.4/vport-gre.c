static struct vport *gre_tnl_create(const struct vport_parms *parms)
{
struct net *net = ovs_dp_get_net(parms->dp);
struct net_device *dev;
struct vport *vport;
vport = ovs_vport_alloc(0, &ovs_gre_vport_ops, parms);
if (IS_ERR(vport))
return vport;
rtnl_lock();
dev = gretap_fb_dev_create(net, parms->name, NET_NAME_USER);
if (IS_ERR(dev)) {
rtnl_unlock();
ovs_vport_free(vport);
return ERR_CAST(dev);
}
dev_change_flags(dev, dev->flags | IFF_UP);
rtnl_unlock();
return vport;
}
static struct vport *gre_create(const struct vport_parms *parms)
{
struct vport *vport;
vport = gre_tnl_create(parms);
if (IS_ERR(vport))
return vport;
return ovs_netdev_link(vport, parms->name);
}
static int __init ovs_gre_tnl_init(void)
{
return ovs_vport_ops_register(&ovs_gre_vport_ops);
}
static void __exit ovs_gre_tnl_exit(void)
{
ovs_vport_ops_unregister(&ovs_gre_vport_ops);
}
