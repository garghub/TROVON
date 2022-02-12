static bool
length_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_length_info *info = par->matchinfo;
u_int16_t pktlen = ntohs(ip_hdr(skb)->tot_len);
return (pktlen >= info->min && pktlen <= info->max) ^ info->invert;
}
static bool
length_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_length_info *info = par->matchinfo;
const u_int16_t pktlen = ntohs(ipv6_hdr(skb)->payload_len) +
sizeof(struct ipv6hdr);
return (pktlen >= info->min && pktlen <= info->max) ^ info->invert;
}
static int __init length_mt_init(void)
{
return xt_register_matches(length_mt_reg, ARRAY_SIZE(length_mt_reg));
}
static void __exit length_mt_exit(void)
{
xt_unregister_matches(length_mt_reg, ARRAY_SIZE(length_mt_reg));
}
