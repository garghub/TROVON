static unsigned int ip6table_nat_do_chain(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state,
struct nf_conn *ct)
{
return ip6t_do_table(skb, state, state->net->ipv6.ip6table_nat);
}
static unsigned int ip6table_nat_fn(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv6_fn(priv, skb, state, ip6table_nat_do_chain);
}
static unsigned int ip6table_nat_in(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv6_in(priv, skb, state, ip6table_nat_do_chain);
}
static unsigned int ip6table_nat_out(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv6_out(priv, skb, state, ip6table_nat_do_chain);
}
static unsigned int ip6table_nat_local_fn(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv6_local_fn(priv, skb, state, ip6table_nat_do_chain);
}
static int __net_init ip6table_nat_table_init(struct net *net)
{
struct ip6t_replace *repl;
int ret;
if (net->ipv6.ip6table_nat)
return 0;
repl = ip6t_alloc_initial_table(&nf_nat_ipv6_table);
if (repl == NULL)
return -ENOMEM;
ret = ip6t_register_table(net, &nf_nat_ipv6_table, repl,
nf_nat_ipv6_ops, &net->ipv6.ip6table_nat);
kfree(repl);
return ret;
}
static void __net_exit ip6table_nat_net_exit(struct net *net)
{
if (!net->ipv6.ip6table_nat)
return;
ip6t_unregister_table(net, net->ipv6.ip6table_nat, nf_nat_ipv6_ops);
net->ipv6.ip6table_nat = NULL;
}
static int __init ip6table_nat_init(void)
{
int ret = register_pernet_subsys(&ip6table_nat_net_ops);
if (ret)
return ret;
ret = ip6table_nat_table_init(&init_net);
if (ret)
unregister_pernet_subsys(&ip6table_nat_net_ops);
return ret;
}
static void __exit ip6table_nat_exit(void)
{
unregister_pernet_subsys(&ip6table_nat_net_ops);
}
