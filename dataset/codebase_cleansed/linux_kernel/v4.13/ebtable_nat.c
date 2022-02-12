static int check(const struct ebt_table_info *info, unsigned int valid_hooks)
{
if (valid_hooks & ~NAT_VALID_HOOKS)
return -EINVAL;
return 0;
}
static unsigned int
ebt_nat_in(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
return ebt_do_table(skb, state, state->net->xt.frame_nat);
}
static unsigned int
ebt_nat_out(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
return ebt_do_table(skb, state, state->net->xt.frame_nat);
}
static int __net_init frame_nat_net_init(struct net *net)
{
net->xt.frame_nat = ebt_register_table(net, &frame_nat, ebt_ops_nat);
return PTR_ERR_OR_ZERO(net->xt.frame_nat);
}
static void __net_exit frame_nat_net_exit(struct net *net)
{
ebt_unregister_table(net, net->xt.frame_nat, ebt_ops_nat);
}
static int __init ebtable_nat_init(void)
{
return register_pernet_subsys(&frame_nat_net_ops);
}
static void __exit ebtable_nat_fini(void)
{
unregister_pernet_subsys(&frame_nat_net_ops);
}
