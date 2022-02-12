static unsigned int
notrack_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
if (skb->nfct != NULL)
return XT_CONTINUE;
skb->nfct = &nf_ct_untracked_get()->ct_general;
skb->nfctinfo = IP_CT_NEW;
nf_conntrack_get(skb->nfct);
return XT_CONTINUE;
}
static int __init notrack_tg_init(void)
{
return xt_register_target(&notrack_tg_reg);
}
static void __exit notrack_tg_exit(void)
{
xt_unregister_target(&notrack_tg_reg);
}
