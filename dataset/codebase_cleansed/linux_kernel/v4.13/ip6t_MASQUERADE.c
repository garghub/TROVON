static unsigned int
masquerade_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
return nf_nat_masquerade_ipv6(skb, par->targinfo, xt_out(par));
}
static int masquerade_tg6_checkentry(const struct xt_tgchk_param *par)
{
const struct nf_nat_range *range = par->targinfo;
if (range->flags & NF_NAT_RANGE_MAP_IPS)
return -EINVAL;
return 0;
}
static int __init masquerade_tg6_init(void)
{
int err;
err = xt_register_target(&masquerade_tg6_reg);
if (err == 0)
nf_nat_masquerade_ipv6_register_notifier();
return err;
}
static void __exit masquerade_tg6_exit(void)
{
nf_nat_masquerade_ipv6_unregister_notifier();
xt_unregister_target(&masquerade_tg6_reg);
}
