static bool ttl_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct ipt_ttl_info *info = par->matchinfo;
const u8 ttl = ip_hdr(skb)->ttl;
switch (info->mode) {
case IPT_TTL_EQ:
return ttl == info->ttl;
case IPT_TTL_NE:
return ttl != info->ttl;
case IPT_TTL_LT:
return ttl < info->ttl;
case IPT_TTL_GT:
return ttl > info->ttl;
}
return false;
}
static bool hl_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct ip6t_hl_info *info = par->matchinfo;
const struct ipv6hdr *ip6h = ipv6_hdr(skb);
switch (info->mode) {
case IP6T_HL_EQ:
return ip6h->hop_limit == info->hop_limit;
case IP6T_HL_NE:
return ip6h->hop_limit != info->hop_limit;
case IP6T_HL_LT:
return ip6h->hop_limit < info->hop_limit;
case IP6T_HL_GT:
return ip6h->hop_limit > info->hop_limit;
}
return false;
}
static int __init hl_mt_init(void)
{
return xt_register_matches(hl_mt_reg, ARRAY_SIZE(hl_mt_reg));
}
static void __exit hl_mt_exit(void)
{
xt_unregister_matches(hl_mt_reg, ARRAY_SIZE(hl_mt_reg));
}
