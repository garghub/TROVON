static void ipcomp4_err(struct sk_buff *skb, u32 info)
{
struct net *net = dev_net(skb->dev);
__be32 spi;
const struct iphdr *iph = (const struct iphdr *)skb->data;
struct ip_comp_hdr *ipch = (struct ip_comp_hdr *)(skb->data+(iph->ihl<<2));
struct xfrm_state *x;
switch (icmp_hdr(skb)->type) {
case ICMP_DEST_UNREACH:
if (icmp_hdr(skb)->code != ICMP_FRAG_NEEDED)
return;
case ICMP_REDIRECT:
break;
default:
return;
}
spi = htonl(ntohs(ipch->cpi));
x = xfrm_state_lookup(net, skb->mark, (const xfrm_address_t *)&iph->daddr,
spi, IPPROTO_COMP, AF_INET);
if (!x)
return;
if (icmp_hdr(skb)->type == ICMP_DEST_UNREACH) {
atomic_inc(&flow_cache_genid);
rt_genid_bump(net);
ipv4_update_pmtu(skb, net, info, 0, 0, IPPROTO_COMP, 0);
} else
ipv4_redirect(skb, net, 0, 0, IPPROTO_COMP, 0);
xfrm_state_put(x);
}
static struct xfrm_state *ipcomp_tunnel_create(struct xfrm_state *x)
{
struct net *net = xs_net(x);
struct xfrm_state *t;
t = xfrm_state_alloc(net);
if (t == NULL)
goto out;
t->id.proto = IPPROTO_IPIP;
t->id.spi = x->props.saddr.a4;
t->id.daddr.a4 = x->id.daddr.a4;
memcpy(&t->sel, &x->sel, sizeof(t->sel));
t->props.family = AF_INET;
t->props.mode = x->props.mode;
t->props.saddr.a4 = x->props.saddr.a4;
t->props.flags = x->props.flags;
t->props.extra_flags = x->props.extra_flags;
memcpy(&t->mark, &x->mark, sizeof(t->mark));
if (xfrm_init_state(t))
goto error;
atomic_set(&t->tunnel_users, 1);
out:
return t;
error:
t->km.state = XFRM_STATE_DEAD;
xfrm_state_put(t);
t = NULL;
goto out;
}
static int ipcomp_tunnel_attach(struct xfrm_state *x)
{
struct net *net = xs_net(x);
int err = 0;
struct xfrm_state *t;
u32 mark = x->mark.v & x->mark.m;
t = xfrm_state_lookup(net, mark, (xfrm_address_t *)&x->id.daddr.a4,
x->props.saddr.a4, IPPROTO_IPIP, AF_INET);
if (!t) {
t = ipcomp_tunnel_create(x);
if (!t) {
err = -EINVAL;
goto out;
}
xfrm_state_insert(t);
xfrm_state_hold(t);
}
x->tunnel = t;
atomic_inc(&t->tunnel_users);
out:
return err;
}
static int ipcomp4_init_state(struct xfrm_state *x)
{
int err = -EINVAL;
x->props.header_len = 0;
switch (x->props.mode) {
case XFRM_MODE_TRANSPORT:
break;
case XFRM_MODE_TUNNEL:
x->props.header_len += sizeof(struct iphdr);
break;
default:
goto out;
}
err = ipcomp_init_state(x);
if (err)
goto out;
if (x->props.mode == XFRM_MODE_TUNNEL) {
err = ipcomp_tunnel_attach(x);
if (err)
goto out;
}
err = 0;
out:
return err;
}
static int __init ipcomp4_init(void)
{
if (xfrm_register_type(&ipcomp_type, AF_INET) < 0) {
pr_info("%s: can't add xfrm type\n", __func__);
return -EAGAIN;
}
if (inet_add_protocol(&ipcomp4_protocol, IPPROTO_COMP) < 0) {
pr_info("%s: can't add protocol\n", __func__);
xfrm_unregister_type(&ipcomp_type, AF_INET);
return -EAGAIN;
}
return 0;
}
static void __exit ipcomp4_fini(void)
{
if (inet_del_protocol(&ipcomp4_protocol, IPPROTO_COMP) < 0)
pr_info("%s: can't remove protocol\n", __func__);
if (xfrm_unregister_type(&ipcomp_type, AF_INET) < 0)
pr_info("%s: can't remove xfrm type\n", __func__);
}
