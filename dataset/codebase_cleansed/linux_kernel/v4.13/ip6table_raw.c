static unsigned int
ip6table_raw_hook(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
return ip6t_do_table(skb, state, state->net->ipv6.ip6table_raw);
}
static int __net_init ip6table_raw_table_init(struct net *net)
{
struct ip6t_replace *repl;
int ret;
if (net->ipv6.ip6table_raw)
return 0;
repl = ip6t_alloc_initial_table(&packet_raw);
if (repl == NULL)
return -ENOMEM;
ret = ip6t_register_table(net, &packet_raw, repl, rawtable_ops,
&net->ipv6.ip6table_raw);
kfree(repl);
return ret;
}
static void __net_exit ip6table_raw_net_exit(struct net *net)
{
if (!net->ipv6.ip6table_raw)
return;
ip6t_unregister_table(net, net->ipv6.ip6table_raw, rawtable_ops);
net->ipv6.ip6table_raw = NULL;
}
static int __init ip6table_raw_init(void)
{
int ret;
rawtable_ops = xt_hook_ops_alloc(&packet_raw, ip6table_raw_hook);
if (IS_ERR(rawtable_ops))
return PTR_ERR(rawtable_ops);
ret = register_pernet_subsys(&ip6table_raw_net_ops);
if (ret < 0) {
kfree(rawtable_ops);
return ret;
}
ret = ip6table_raw_table_init(&init_net);
if (ret) {
unregister_pernet_subsys(&ip6table_raw_net_ops);
kfree(rawtable_ops);
}
return ret;
}
static void __exit ip6table_raw_fini(void)
{
unregister_pernet_subsys(&ip6table_raw_net_ops);
kfree(rawtable_ops);
}
