static struct nfp_flower_cmsg_hdr *
nfp_flower_cmsg_get_hdr(struct sk_buff *skb)
{
return (struct nfp_flower_cmsg_hdr *)skb->data;
}
struct sk_buff *
nfp_flower_cmsg_alloc(struct nfp_app *app, unsigned int size,
enum nfp_flower_cmsg_type_port type)
{
struct nfp_flower_cmsg_hdr *ch;
struct sk_buff *skb;
size += NFP_FLOWER_CMSG_HLEN;
skb = nfp_app_ctrl_msg_alloc(app, size, GFP_KERNEL);
if (!skb)
return NULL;
ch = nfp_flower_cmsg_get_hdr(skb);
ch->pad = 0;
ch->version = NFP_FLOWER_CMSG_VER1;
ch->type = type;
skb_put(skb, size);
return skb;
}
int nfp_flower_cmsg_portmod(struct nfp_repr *repr, bool carrier_ok)
{
struct nfp_flower_cmsg_portmod *msg;
struct sk_buff *skb;
skb = nfp_flower_cmsg_alloc(repr->app, sizeof(*msg),
NFP_FLOWER_CMSG_TYPE_PORT_MOD);
if (!skb)
return -ENOMEM;
msg = nfp_flower_cmsg_get_data(skb);
msg->portnum = cpu_to_be32(repr->dst->u.port_info.port_id);
msg->reserved = 0;
msg->info = carrier_ok;
msg->mtu = cpu_to_be16(repr->netdev->mtu);
nfp_ctrl_tx(repr->app->ctrl, skb);
return 0;
}
static void
nfp_flower_cmsg_portmod_rx(struct nfp_app *app, struct sk_buff *skb)
{
struct nfp_flower_cmsg_portmod *msg;
struct net_device *netdev;
bool link;
msg = nfp_flower_cmsg_get_data(skb);
link = msg->info & NFP_FLOWER_CMSG_PORTMOD_INFO_LINK;
rcu_read_lock();
netdev = nfp_app_repr_get(app, be32_to_cpu(msg->portnum));
if (!netdev) {
nfp_flower_cmsg_warn(app, "ctrl msg for unknown port 0x%08x\n",
be32_to_cpu(msg->portnum));
rcu_read_unlock();
return;
}
if (link)
netif_carrier_on(netdev);
else
netif_carrier_off(netdev);
rcu_read_unlock();
}
void nfp_flower_cmsg_rx(struct nfp_app *app, struct sk_buff *skb)
{
struct nfp_flower_cmsg_hdr *cmsg_hdr;
enum nfp_flower_cmsg_type_port type;
cmsg_hdr = nfp_flower_cmsg_get_hdr(skb);
if (unlikely(cmsg_hdr->version != NFP_FLOWER_CMSG_VER1)) {
nfp_flower_cmsg_warn(app, "Cannot handle repr control version %u\n",
cmsg_hdr->version);
goto out;
}
type = cmsg_hdr->type;
switch (type) {
case NFP_FLOWER_CMSG_TYPE_PORT_MOD:
nfp_flower_cmsg_portmod_rx(app, skb);
break;
case NFP_FLOWER_CMSG_TYPE_FLOW_STATS:
nfp_flower_rx_flow_stats(app, skb);
break;
default:
nfp_flower_cmsg_warn(app, "Cannot handle invalid repr control type %u\n",
type);
}
out:
dev_kfree_skb_any(skb);
}
