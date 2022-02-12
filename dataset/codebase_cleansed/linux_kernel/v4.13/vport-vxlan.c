static int vxlan_get_options(const struct vport *vport, struct sk_buff *skb)
{
struct vxlan_dev *vxlan = netdev_priv(vport->dev);
__be16 dst_port = vxlan->cfg.dst_port;
if (nla_put_u16(skb, OVS_TUNNEL_ATTR_DST_PORT, ntohs(dst_port)))
return -EMSGSIZE;
if (vxlan->cfg.flags & VXLAN_F_GBP) {
struct nlattr *exts;
exts = nla_nest_start(skb, OVS_TUNNEL_ATTR_EXTENSION);
if (!exts)
return -EMSGSIZE;
if (vxlan->cfg.flags & VXLAN_F_GBP &&
nla_put_flag(skb, OVS_VXLAN_EXT_GBP))
return -EMSGSIZE;
nla_nest_end(skb, exts);
}
return 0;
}
static int vxlan_configure_exts(struct vport *vport, struct nlattr *attr,
struct vxlan_config *conf)
{
struct nlattr *exts[OVS_VXLAN_EXT_MAX + 1];
int err;
if (nla_len(attr) < sizeof(struct nlattr))
return -EINVAL;
err = nla_parse_nested(exts, OVS_VXLAN_EXT_MAX, attr, exts_policy,
NULL);
if (err < 0)
return err;
if (exts[OVS_VXLAN_EXT_GBP])
conf->flags |= VXLAN_F_GBP;
return 0;
}
static struct vport *vxlan_tnl_create(const struct vport_parms *parms)
{
struct net *net = ovs_dp_get_net(parms->dp);
struct nlattr *options = parms->options;
struct net_device *dev;
struct vport *vport;
struct nlattr *a;
int err;
struct vxlan_config conf = {
.no_share = true,
.flags = VXLAN_F_COLLECT_METADATA | VXLAN_F_UDP_ZERO_CSUM6_RX,
.mtu = IP_MAX_MTU,
};
if (!options) {
err = -EINVAL;
goto error;
}
a = nla_find_nested(options, OVS_TUNNEL_ATTR_DST_PORT);
if (a && nla_len(a) == sizeof(u16)) {
conf.dst_port = htons(nla_get_u16(a));
} else {
err = -EINVAL;
goto error;
}
vport = ovs_vport_alloc(0, &ovs_vxlan_netdev_vport_ops, parms);
if (IS_ERR(vport))
return vport;
a = nla_find_nested(options, OVS_TUNNEL_ATTR_EXTENSION);
if (a) {
err = vxlan_configure_exts(vport, a, &conf);
if (err) {
ovs_vport_free(vport);
goto error;
}
}
rtnl_lock();
dev = vxlan_dev_create(net, parms->name, NET_NAME_USER, &conf);
if (IS_ERR(dev)) {
rtnl_unlock();
ovs_vport_free(vport);
return ERR_CAST(dev);
}
err = dev_change_flags(dev, dev->flags | IFF_UP);
if (err < 0) {
rtnl_delete_link(dev);
rtnl_unlock();
ovs_vport_free(vport);
goto error;
}
rtnl_unlock();
return vport;
error:
return ERR_PTR(err);
}
static struct vport *vxlan_create(const struct vport_parms *parms)
{
struct vport *vport;
vport = vxlan_tnl_create(parms);
if (IS_ERR(vport))
return vport;
return ovs_netdev_link(vport, parms->name);
}
static int __init ovs_vxlan_tnl_init(void)
{
return ovs_vport_ops_register(&ovs_vxlan_netdev_vport_ops);
}
static void __exit ovs_vxlan_tnl_exit(void)
{
ovs_vport_ops_unregister(&ovs_vxlan_netdev_vport_ops);
}
