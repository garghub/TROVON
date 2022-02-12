static unsigned int ip6table_nat_do_chain(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state,
struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
return ip6t_do_table(skb, ops->hooknum, state, net->ipv6.ip6table_nat);
}
static unsigned int ip6table_nat_fn(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv6_fn(ops, skb, state, ip6table_nat_do_chain);
}
static unsigned int ip6table_nat_in(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv6_in(ops, skb, state, ip6table_nat_do_chain);
}
static unsigned int ip6table_nat_out(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv6_out(ops, skb, state, ip6table_nat_do_chain);
}
static unsigned int ip6table_nat_local_fn(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv6_local_fn(ops, skb, state, ip6table_nat_do_chain);
}
static int __net_init ip6table_nat_net_init(struct net *net)
{
struct ip6t_replace *repl;
repl = ip6t_alloc_initial_table(&nf_nat_ipv6_table);
if (repl == NULL)
return -ENOMEM;
net->ipv6.ip6table_nat = ip6t_register_table(net, &nf_nat_ipv6_table, repl);
kfree(repl);
return PTR_ERR_OR_ZERO(net->ipv6.ip6table_nat);
}
static void __net_exit ip6table_nat_net_exit(struct net *net)
{
ip6t_unregister_table(net, net->ipv6.ip6table_nat);
}
static int __init ip6table_nat_init(void)
{
int err;
err = register_pernet_subsys(&ip6table_nat_net_ops);
if (err < 0)
goto err1;
err = nf_register_hooks(nf_nat_ipv6_ops, ARRAY_SIZE(nf_nat_ipv6_ops));
if (err < 0)
goto err2;
return 0;
err2:
unregister_pernet_subsys(&ip6table_nat_net_ops);
err1:
return err;
}
static void __exit ip6table_nat_exit(void)
{
nf_unregister_hooks(nf_nat_ipv6_ops, ARRAY_SIZE(nf_nat_ipv6_ops));
unregister_pernet_subsys(&ip6table_nat_net_ops);
}
