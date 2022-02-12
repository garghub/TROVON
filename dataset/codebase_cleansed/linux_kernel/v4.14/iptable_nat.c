static unsigned int iptable_nat_do_chain(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state,
struct nf_conn *ct)
{
return ipt_do_table(skb, state, state->net->ipv4.nat_table);
}
static unsigned int iptable_nat_ipv4_fn(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_fn(priv, skb, state, iptable_nat_do_chain);
}
static unsigned int iptable_nat_ipv4_in(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_in(priv, skb, state, iptable_nat_do_chain);
}
static unsigned int iptable_nat_ipv4_out(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_out(priv, skb, state, iptable_nat_do_chain);
}
static unsigned int iptable_nat_ipv4_local_fn(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_local_fn(priv, skb, state, iptable_nat_do_chain);
}
static int __net_init iptable_nat_table_init(struct net *net)
{
struct ipt_replace *repl;
int ret;
if (net->ipv4.nat_table)
return 0;
repl = ipt_alloc_initial_table(&nf_nat_ipv4_table);
if (repl == NULL)
return -ENOMEM;
ret = ipt_register_table(net, &nf_nat_ipv4_table, repl,
nf_nat_ipv4_ops, &net->ipv4.nat_table);
kfree(repl);
return ret;
}
static void __net_exit iptable_nat_net_exit(struct net *net)
{
if (!net->ipv4.nat_table)
return;
ipt_unregister_table(net, net->ipv4.nat_table, nf_nat_ipv4_ops);
net->ipv4.nat_table = NULL;
}
static int __init iptable_nat_init(void)
{
int ret = register_pernet_subsys(&iptable_nat_net_ops);
if (ret)
return ret;
ret = iptable_nat_table_init(&init_net);
if (ret)
unregister_pernet_subsys(&iptable_nat_net_ops);
return ret;
}
static void __exit iptable_nat_exit(void)
{
unregister_pernet_subsys(&iptable_nat_net_ops);
}
