static unsigned int
ebt_dnat_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ebt_nat_info *info = par->targinfo;
if (!skb_make_writable(skb, 0))
return EBT_DROP;
memcpy(eth_hdr(skb)->h_dest, info->mac, ETH_ALEN);
return info->target;
}
static int ebt_dnat_tg_check(const struct xt_tgchk_param *par)
{
const struct ebt_nat_info *info = par->targinfo;
unsigned int hook_mask;
if (BASE_CHAIN && info->target == EBT_RETURN)
return -EINVAL;
hook_mask = par->hook_mask & ~(1 << NF_BR_NUMHOOKS);
if ((strcmp(par->table, "nat") != 0 ||
(hook_mask & ~((1 << NF_BR_PRE_ROUTING) |
(1 << NF_BR_LOCAL_OUT)))) &&
(strcmp(par->table, "broute") != 0 ||
hook_mask & ~(1 << NF_BR_BROUTING)))
return -EINVAL;
if (INVALID_TARGET)
return -EINVAL;
return 0;
}
static int __init ebt_dnat_init(void)
{
return xt_register_target(&ebt_dnat_tg_reg);
}
static void __exit ebt_dnat_fini(void)
{
xt_unregister_target(&ebt_dnat_tg_reg);
}
