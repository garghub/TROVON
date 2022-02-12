static void netdev_port_receive(struct sk_buff *skb)
{
struct vport *vport;
vport = ovs_netdev_get_vport(skb->dev);
if (unlikely(!vport))
goto error;
if (unlikely(skb_warn_if_lro(skb)))
goto error;
skb = skb_share_check(skb, GFP_ATOMIC);
if (unlikely(!skb))
return;
skb_push(skb, ETH_HLEN);
skb_postpush_rcsum(skb, skb->data, ETH_HLEN);
ovs_vport_receive(vport, skb, skb_tunnel_info(skb));
return;
error:
kfree_skb(skb);
}
static rx_handler_result_t netdev_frame_hook(struct sk_buff **pskb)
{
struct sk_buff *skb = *pskb;
if (unlikely(skb->pkt_type == PACKET_LOOPBACK))
return RX_HANDLER_PASS;
netdev_port_receive(skb);
return RX_HANDLER_CONSUMED;
}
static struct net_device *get_dpdev(const struct datapath *dp)
{
struct vport *local;
local = ovs_vport_ovsl(dp, OVSP_LOCAL);
BUG_ON(!local);
return local->dev;
}
struct vport *ovs_netdev_link(struct vport *vport, const char *name)
{
int err;
vport->dev = dev_get_by_name(ovs_dp_get_net(vport->dp), name);
if (!vport->dev) {
err = -ENODEV;
goto error_free_vport;
}
if (vport->dev->flags & IFF_LOOPBACK ||
vport->dev->type != ARPHRD_ETHER ||
ovs_is_internal_dev(vport->dev)) {
err = -EINVAL;
goto error_put;
}
rtnl_lock();
err = netdev_master_upper_dev_link(vport->dev,
get_dpdev(vport->dp), NULL, NULL);
if (err)
goto error_unlock;
err = netdev_rx_handler_register(vport->dev, netdev_frame_hook,
vport);
if (err)
goto error_master_upper_dev_unlink;
dev_disable_lro(vport->dev);
dev_set_promiscuity(vport->dev, 1);
vport->dev->priv_flags |= IFF_OVS_DATAPATH;
rtnl_unlock();
return vport;
error_master_upper_dev_unlink:
netdev_upper_dev_unlink(vport->dev, get_dpdev(vport->dp));
error_unlock:
rtnl_unlock();
error_put:
dev_put(vport->dev);
error_free_vport:
ovs_vport_free(vport);
return ERR_PTR(err);
}
static struct vport *netdev_create(const struct vport_parms *parms)
{
struct vport *vport;
vport = ovs_vport_alloc(0, &ovs_netdev_vport_ops, parms);
if (IS_ERR(vport))
return vport;
return ovs_netdev_link(vport, parms->name);
}
static void vport_netdev_free(struct rcu_head *rcu)
{
struct vport *vport = container_of(rcu, struct vport, rcu);
if (vport->dev)
dev_put(vport->dev);
ovs_vport_free(vport);
}
void ovs_netdev_detach_dev(struct vport *vport)
{
ASSERT_RTNL();
vport->dev->priv_flags &= ~IFF_OVS_DATAPATH;
netdev_rx_handler_unregister(vport->dev);
netdev_upper_dev_unlink(vport->dev,
netdev_master_upper_dev_get(vport->dev));
dev_set_promiscuity(vport->dev, -1);
}
static void netdev_destroy(struct vport *vport)
{
rtnl_lock();
if (vport->dev->priv_flags & IFF_OVS_DATAPATH)
ovs_netdev_detach_dev(vport);
rtnl_unlock();
call_rcu(&vport->rcu, vport_netdev_free);
}
void ovs_netdev_tunnel_destroy(struct vport *vport)
{
rtnl_lock();
if (vport->dev->priv_flags & IFF_OVS_DATAPATH)
ovs_netdev_detach_dev(vport);
if (vport->dev->reg_state == NETREG_REGISTERED)
rtnl_delete_link(vport->dev);
dev_put(vport->dev);
vport->dev = NULL;
rtnl_unlock();
call_rcu(&vport->rcu, vport_netdev_free);
}
struct vport *ovs_netdev_get_vport(struct net_device *dev)
{
if (likely(dev->priv_flags & IFF_OVS_DATAPATH))
return (struct vport *)
rcu_dereference_rtnl(dev->rx_handler_data);
else
return NULL;
}
int __init ovs_netdev_init(void)
{
return ovs_vport_ops_register(&ovs_netdev_vport_ops);
}
void ovs_netdev_exit(void)
{
ovs_vport_ops_unregister(&ovs_netdev_vport_ops);
}
