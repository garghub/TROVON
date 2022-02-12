static unsigned int
redirect_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
return nf_nat_redirect_ipv6(skb, par->targinfo, xt_hooknum(par));
}
static int redirect_tg6_checkentry(const struct xt_tgchk_param *par)
{
const struct nf_nat_range *range = par->targinfo;
if (range->flags & NF_NAT_RANGE_MAP_IPS)
return -EINVAL;
return nf_ct_netns_get(par->net, par->family);
}
static void redirect_tg_destroy(const struct xt_tgdtor_param *par)
{
nf_ct_netns_put(par->net, par->family);
}
static int redirect_tg4_check(const struct xt_tgchk_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
if (mr->range[0].flags & NF_NAT_RANGE_MAP_IPS) {
pr_debug("bad MAP_IPS.\n");
return -EINVAL;
}
if (mr->rangesize != 1) {
pr_debug("bad rangesize %u.\n", mr->rangesize);
return -EINVAL;
}
return nf_ct_netns_get(par->net, par->family);
}
static unsigned int
redirect_tg4(struct sk_buff *skb, const struct xt_action_param *par)
{
return nf_nat_redirect_ipv4(skb, par->targinfo, xt_hooknum(par));
}
static int __init redirect_tg_init(void)
{
return xt_register_targets(redirect_tg_reg,
ARRAY_SIZE(redirect_tg_reg));
}
static void __exit redirect_tg_exit(void)
{
xt_unregister_targets(redirect_tg_reg, ARRAY_SIZE(redirect_tg_reg));
}
