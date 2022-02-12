static void fou6_build_udp(struct sk_buff *skb, struct ip_tunnel_encap *e,
struct flowi6 *fl6, u8 *protocol, __be16 sport)
{
struct udphdr *uh;
skb_push(skb, sizeof(struct udphdr));
skb_reset_transport_header(skb);
uh = udp_hdr(skb);
uh->dest = e->dport;
uh->source = sport;
uh->len = htons(skb->len);
udp6_set_csum(!(e->flags & TUNNEL_ENCAP_FLAG_CSUM6), skb,
&fl6->saddr, &fl6->daddr, skb->len);
*protocol = IPPROTO_UDP;
}
static int fou6_build_header(struct sk_buff *skb, struct ip_tunnel_encap *e,
u8 *protocol, struct flowi6 *fl6)
{
__be16 sport;
int err;
int type = e->flags & TUNNEL_ENCAP_FLAG_CSUM6 ?
SKB_GSO_UDP_TUNNEL_CSUM : SKB_GSO_UDP_TUNNEL;
err = __fou_build_header(skb, e, protocol, &sport, type);
if (err)
return err;
fou6_build_udp(skb, e, fl6, protocol, sport);
return 0;
}
static int gue6_build_header(struct sk_buff *skb, struct ip_tunnel_encap *e,
u8 *protocol, struct flowi6 *fl6)
{
__be16 sport;
int err;
int type = e->flags & TUNNEL_ENCAP_FLAG_CSUM6 ?
SKB_GSO_UDP_TUNNEL_CSUM : SKB_GSO_UDP_TUNNEL;
err = __gue_build_header(skb, e, protocol, &sport, type);
if (err)
return err;
fou6_build_udp(skb, e, fl6, protocol, sport);
return 0;
}
static int ip6_tnl_encap_add_fou_ops(void)
{
int ret;
ret = ip6_tnl_encap_add_ops(&fou_ip6tun_ops, TUNNEL_ENCAP_FOU);
if (ret < 0) {
pr_err("can't add fou6 ops\n");
return ret;
}
ret = ip6_tnl_encap_add_ops(&gue_ip6tun_ops, TUNNEL_ENCAP_GUE);
if (ret < 0) {
pr_err("can't add gue6 ops\n");
ip6_tnl_encap_del_ops(&fou_ip6tun_ops, TUNNEL_ENCAP_FOU);
return ret;
}
return 0;
}
static void ip6_tnl_encap_del_fou_ops(void)
{
ip6_tnl_encap_del_ops(&fou_ip6tun_ops, TUNNEL_ENCAP_FOU);
ip6_tnl_encap_del_ops(&gue_ip6tun_ops, TUNNEL_ENCAP_GUE);
}
static int ip6_tnl_encap_add_fou_ops(void)
{
return 0;
}
static void ip6_tnl_encap_del_fou_ops(void)
{
}
static int __init fou6_init(void)
{
int ret;
ret = ip6_tnl_encap_add_fou_ops();
return ret;
}
static void __exit fou6_fini(void)
{
ip6_tnl_encap_del_fou_ops();
}
