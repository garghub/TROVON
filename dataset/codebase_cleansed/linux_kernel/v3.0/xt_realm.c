static bool
realm_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_realm_info *info = par->matchinfo;
const struct dst_entry *dst = skb_dst(skb);
return (info->id == (dst->tclassid & info->mask)) ^ info->invert;
}
static int __init realm_mt_init(void)
{
return xt_register_match(&realm_mt_reg);
}
static void __exit realm_mt_exit(void)
{
xt_unregister_match(&realm_mt_reg);
}
