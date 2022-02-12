static unsigned int
ip6table_security_hook(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
return ip6t_do_table(skb, state, state->net->ipv6.ip6table_security);
}
static int __net_init ip6table_security_table_init(struct net *net)
{
struct ip6t_replace *repl;
int ret;
if (net->ipv6.ip6table_security)
return 0;
repl = ip6t_alloc_initial_table(&security_table);
if (repl == NULL)
return -ENOMEM;
ret = ip6t_register_table(net, &security_table, repl, sectbl_ops,
&net->ipv6.ip6table_security);
kfree(repl);
return ret;
}
static void __net_exit ip6table_security_net_exit(struct net *net)
{
if (!net->ipv6.ip6table_security)
return;
ip6t_unregister_table(net, net->ipv6.ip6table_security, sectbl_ops);
net->ipv6.ip6table_security = NULL;
}
static int __init ip6table_security_init(void)
{
int ret;
sectbl_ops = xt_hook_ops_alloc(&security_table, ip6table_security_hook);
if (IS_ERR(sectbl_ops))
return PTR_ERR(sectbl_ops);
ret = register_pernet_subsys(&ip6table_security_net_ops);
if (ret < 0) {
kfree(sectbl_ops);
return ret;
}
ret = ip6table_security_table_init(&init_net);
if (ret) {
unregister_pernet_subsys(&ip6table_security_net_ops);
kfree(sectbl_ops);
}
return ret;
}
static void __exit ip6table_security_fini(void)
{
unregister_pernet_subsys(&ip6table_security_net_ops);
kfree(sectbl_ops);
}
