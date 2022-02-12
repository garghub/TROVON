static bool
ebt_pkttype_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct ebt_pkttype_info *info = par->matchinfo;
return (skb->pkt_type == info->pkt_type) ^ info->invert;
}
static int ebt_pkttype_mt_check(const struct xt_mtchk_param *par)
{
const struct ebt_pkttype_info *info = par->matchinfo;
if (info->invert != 0 && info->invert != 1)
return -EINVAL;
return 0;
}
static int __init ebt_pkttype_init(void)
{
return xt_register_match(&ebt_pkttype_mt_reg);
}
static void __exit ebt_pkttype_fini(void)
{
xt_unregister_match(&ebt_pkttype_mt_reg);
}
