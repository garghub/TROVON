static unsigned int
ebt_redirect_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ebt_redirect_info *info = par->targinfo;
if (!skb_make_writable(skb, 0))
return EBT_DROP;
if (par->hooknum != NF_BR_BROUTING)
memcpy(eth_hdr(skb)->h_dest,
br_port_get_rcu(par->in)->br->dev->dev_addr, ETH_ALEN);
else
memcpy(eth_hdr(skb)->h_dest, par->in->dev_addr, ETH_ALEN);
skb->pkt_type = PACKET_HOST;
return info->target;
}
static int ebt_redirect_tg_check(const struct xt_tgchk_param *par)
{
const struct ebt_redirect_info *info = par->targinfo;
unsigned int hook_mask;
if (BASE_CHAIN && info->target == EBT_RETURN)
return -EINVAL;
hook_mask = par->hook_mask & ~(1 << NF_BR_NUMHOOKS);
if ((strcmp(par->table, "nat") != 0 ||
hook_mask & ~(1 << NF_BR_PRE_ROUTING)) &&
(strcmp(par->table, "broute") != 0 ||
hook_mask & ~(1 << NF_BR_BROUTING)))
return -EINVAL;
if (INVALID_TARGET)
return -EINVAL;
return 0;
}
static int __init ebt_redirect_init(void)
{
return xt_register_target(&ebt_redirect_tg_reg);
}
static void __exit ebt_redirect_fini(void)
{
xt_unregister_target(&ebt_redirect_tg_reg);
}
