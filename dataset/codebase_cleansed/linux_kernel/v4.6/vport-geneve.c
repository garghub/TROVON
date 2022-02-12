static inline struct geneve_port *geneve_vport(const struct vport *vport)
{
return vport_priv(vport);
}
static int geneve_get_options(const struct vport *vport,
struct sk_buff *skb)
{
struct geneve_port *geneve_port = geneve_vport(vport);
if (nla_put_u16(skb, OVS_TUNNEL_ATTR_DST_PORT, geneve_port->dst_port))
return -EMSGSIZE;
return 0;
}
static struct vport *geneve_tnl_create(const struct vport_parms *parms)
{
struct net *net = ovs_dp_get_net(parms->dp);
struct nlattr *options = parms->options;
struct geneve_port *geneve_port;
struct net_device *dev;
struct vport *vport;
struct nlattr *a;
u16 dst_port;
int err;
if (!options) {
err = -EINVAL;
goto error;
}
a = nla_find_nested(options, OVS_TUNNEL_ATTR_DST_PORT);
if (a && nla_len(a) == sizeof(u16)) {
dst_port = nla_get_u16(a);
} else {
err = -EINVAL;
goto error;
}
vport = ovs_vport_alloc(sizeof(struct geneve_port),
&ovs_geneve_vport_ops, parms);
if (IS_ERR(vport))
return vport;
geneve_port = geneve_vport(vport);
geneve_port->dst_port = dst_port;
rtnl_lock();
dev = geneve_dev_create_fb(net, parms->name, NET_NAME_USER, dst_port);
if (IS_ERR(dev)) {
rtnl_unlock();
ovs_vport_free(vport);
return ERR_CAST(dev);
}
dev_change_flags(dev, dev->flags | IFF_UP);
rtnl_unlock();
return vport;
error:
return ERR_PTR(err);
}
static struct vport *geneve_create(const struct vport_parms *parms)
{
struct vport *vport;
vport = geneve_tnl_create(parms);
if (IS_ERR(vport))
return vport;
return ovs_netdev_link(vport, parms->name);
}
static int __init ovs_geneve_tnl_init(void)
{
return ovs_vport_ops_register(&ovs_geneve_vport_ops);
}
static void __exit ovs_geneve_tnl_exit(void)
{
ovs_vport_ops_unregister(&ovs_geneve_vport_ops);
}
