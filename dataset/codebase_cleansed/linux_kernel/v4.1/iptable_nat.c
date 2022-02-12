static unsigned int iptable_nat_do_chain(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state,
struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
return ipt_do_table(skb, ops->hooknum, state, net->ipv4.nat_table);
}
static unsigned int iptable_nat_ipv4_fn(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_fn(ops, skb, state, iptable_nat_do_chain);
}
static unsigned int iptable_nat_ipv4_in(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_in(ops, skb, state, iptable_nat_do_chain);
}
static unsigned int iptable_nat_ipv4_out(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_out(ops, skb, state, iptable_nat_do_chain);
}
static unsigned int iptable_nat_ipv4_local_fn(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_local_fn(ops, skb, state, iptable_nat_do_chain);
}
static int __net_init iptable_nat_net_init(struct net *net)
{
struct ipt_replace *repl;
repl = ipt_alloc_initial_table(&nf_nat_ipv4_table);
if (repl == NULL)
return -ENOMEM;
net->ipv4.nat_table = ipt_register_table(net, &nf_nat_ipv4_table, repl);
kfree(repl);
return PTR_ERR_OR_ZERO(net->ipv4.nat_table);
}
static void __net_exit iptable_nat_net_exit(struct net *net)
{
ipt_unregister_table(net, net->ipv4.nat_table);
}
static int __init iptable_nat_init(void)
{
int err;
err = register_pernet_subsys(&iptable_nat_net_ops);
if (err < 0)
goto err1;
err = nf_register_hooks(nf_nat_ipv4_ops, ARRAY_SIZE(nf_nat_ipv4_ops));
if (err < 0)
goto err2;
return 0;
err2:
unregister_pernet_subsys(&iptable_nat_net_ops);
err1:
return err;
}
static void __exit iptable_nat_exit(void)
{
nf_unregister_hooks(nf_nat_ipv4_ops, ARRAY_SIZE(nf_nat_ipv4_ops));
unregister_pernet_subsys(&iptable_nat_net_ops);
}
