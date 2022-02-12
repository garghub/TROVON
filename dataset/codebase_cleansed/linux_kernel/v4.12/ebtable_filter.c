static int check(const struct ebt_table_info *info, unsigned int valid_hooks)
{
if (valid_hooks & ~FILTER_VALID_HOOKS)
return -EINVAL;
return 0;
}
static unsigned int
ebt_in_hook(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
return ebt_do_table(skb, state, state->net->xt.frame_filter);
}
static unsigned int
ebt_out_hook(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
return ebt_do_table(skb, state, state->net->xt.frame_filter);
}
static int __net_init frame_filter_net_init(struct net *net)
{
net->xt.frame_filter = ebt_register_table(net, &frame_filter, ebt_ops_filter);
return PTR_ERR_OR_ZERO(net->xt.frame_filter);
}
static void __net_exit frame_filter_net_exit(struct net *net)
{
ebt_unregister_table(net, net->xt.frame_filter, ebt_ops_filter);
}
static int __init ebtable_filter_init(void)
{
return register_pernet_subsys(&frame_filter_net_ops);
}
static void __exit ebtable_filter_fini(void)
{
unregister_pernet_subsys(&frame_filter_net_ops);
}
