static void netdev_port_receive(struct vport *vport, struct sk_buff *skb)
{
if (unlikely(!vport))
goto error;
if (unlikely(skb_warn_if_lro(skb)))
goto error;
skb = skb_share_check(skb, GFP_ATOMIC);
if (unlikely(!skb))
return;
skb_push(skb, ETH_HLEN);
ovs_skb_postpush_rcsum(skb, skb->data, ETH_HLEN);
ovs_vport_receive(vport, skb, NULL);
return;
error:
kfree_skb(skb);
}
static rx_handler_result_t netdev_frame_hook(struct sk_buff **pskb)
{
struct sk_buff *skb = *pskb;
struct vport *vport;
if (unlikely(skb->pkt_type == PACKET_LOOPBACK))
return RX_HANDLER_PASS;
vport = ovs_netdev_get_vport(skb->dev);
netdev_port_receive(vport, skb);
return RX_HANDLER_CONSUMED;
}
static struct vport *netdev_create(const struct vport_parms *parms)
{
struct vport *vport;
struct netdev_vport *netdev_vport;
int err;
vport = ovs_vport_alloc(sizeof(struct netdev_vport),
&ovs_netdev_vport_ops, parms);
if (IS_ERR(vport)) {
err = PTR_ERR(vport);
goto error;
}
netdev_vport = netdev_vport_priv(vport);
netdev_vport->dev = dev_get_by_name(ovs_dp_get_net(vport->dp), parms->name);
if (!netdev_vport->dev) {
err = -ENODEV;
goto error_free_vport;
}
if (netdev_vport->dev->flags & IFF_LOOPBACK ||
netdev_vport->dev->type != ARPHRD_ETHER ||
ovs_is_internal_dev(netdev_vport->dev)) {
err = -EINVAL;
goto error_put;
}
rtnl_lock();
err = netdev_rx_handler_register(netdev_vport->dev, netdev_frame_hook,
vport);
if (err)
goto error_unlock;
dev_set_promiscuity(netdev_vport->dev, 1);
netdev_vport->dev->priv_flags |= IFF_OVS_DATAPATH;
rtnl_unlock();
return vport;
error_unlock:
rtnl_unlock();
error_put:
dev_put(netdev_vport->dev);
error_free_vport:
ovs_vport_free(vport);
error:
return ERR_PTR(err);
}
static void free_port_rcu(struct rcu_head *rcu)
{
struct netdev_vport *netdev_vport = container_of(rcu,
struct netdev_vport, rcu);
dev_put(netdev_vport->dev);
ovs_vport_free(vport_from_priv(netdev_vport));
}
static void netdev_destroy(struct vport *vport)
{
struct netdev_vport *netdev_vport = netdev_vport_priv(vport);
rtnl_lock();
netdev_vport->dev->priv_flags &= ~IFF_OVS_DATAPATH;
netdev_rx_handler_unregister(netdev_vport->dev);
dev_set_promiscuity(netdev_vport->dev, -1);
rtnl_unlock();
call_rcu(&netdev_vport->rcu, free_port_rcu);
}
const char *ovs_netdev_get_name(const struct vport *vport)
{
const struct netdev_vport *netdev_vport = netdev_vport_priv(vport);
return netdev_vport->dev->name;
}
static unsigned int packet_length(const struct sk_buff *skb)
{
unsigned int length = skb->len - ETH_HLEN;
if (skb->protocol == htons(ETH_P_8021Q))
length -= VLAN_HLEN;
return length;
}
static int netdev_send(struct vport *vport, struct sk_buff *skb)
{
struct netdev_vport *netdev_vport = netdev_vport_priv(vport);
int mtu = netdev_vport->dev->mtu;
int len;
if (unlikely(packet_length(skb) > mtu && !skb_is_gso(skb))) {
net_warn_ratelimited("%s: dropped over-mtu packet: %d > %d\n",
netdev_vport->dev->name,
packet_length(skb), mtu);
goto drop;
}
skb->dev = netdev_vport->dev;
len = skb->len;
dev_queue_xmit(skb);
return len;
drop:
kfree_skb(skb);
return 0;
}
struct vport *ovs_netdev_get_vport(struct net_device *dev)
{
if (likely(dev->priv_flags & IFF_OVS_DATAPATH))
return (struct vport *)
rcu_dereference_rtnl(dev->rx_handler_data);
else
return NULL;
}
