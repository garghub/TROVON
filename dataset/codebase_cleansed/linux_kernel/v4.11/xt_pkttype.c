static bool
pkttype_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_pkttype_info *info = par->matchinfo;
u_int8_t type;
if (skb->pkt_type != PACKET_LOOPBACK)
type = skb->pkt_type;
else if (xt_family(par) == NFPROTO_IPV4 &&
ipv4_is_multicast(ip_hdr(skb)->daddr))
type = PACKET_MULTICAST;
else if (xt_family(par) == NFPROTO_IPV6)
type = PACKET_MULTICAST;
else
type = PACKET_BROADCAST;
return (type == info->pkttype) ^ info->invert;
}
static int __init pkttype_mt_init(void)
{
return xt_register_match(&pkttype_mt_reg);
}
static void __exit pkttype_mt_exit(void)
{
xt_unregister_match(&pkttype_mt_reg);
}
