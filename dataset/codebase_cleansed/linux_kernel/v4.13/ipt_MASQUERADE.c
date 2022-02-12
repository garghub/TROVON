static int masquerade_tg_check(const struct xt_tgchk_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
if (mr->range[0].flags & NF_NAT_RANGE_MAP_IPS) {
pr_debug("bad MAP_IPS.\n");
return -EINVAL;
}
if (mr->rangesize != 1) {
pr_debug("bad rangesize %u\n", mr->rangesize);
return -EINVAL;
}
return nf_ct_netns_get(par->net, par->family);
}
static unsigned int
masquerade_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
struct nf_nat_range range;
const struct nf_nat_ipv4_multi_range_compat *mr;
mr = par->targinfo;
range.flags = mr->range[0].flags;
range.min_proto = mr->range[0].min;
range.max_proto = mr->range[0].max;
return nf_nat_masquerade_ipv4(skb, xt_hooknum(par), &range,
xt_out(par));
}
static void masquerade_tg_destroy(const struct xt_tgdtor_param *par)
{
nf_ct_netns_put(par->net, par->family);
}
static int __init masquerade_tg_init(void)
{
int ret;
ret = xt_register_target(&masquerade_tg_reg);
if (ret == 0)
nf_nat_masquerade_ipv4_register_notifier();
return ret;
}
static void __exit masquerade_tg_exit(void)
{
xt_unregister_target(&masquerade_tg_reg);
nf_nat_masquerade_ipv4_unregister_notifier();
}
