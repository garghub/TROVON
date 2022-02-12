static unsigned int
ip6table_filter_hook(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct nf_hook_state *state)
{
const struct net *net = dev_net(state->in ? state->in : state->out);
return ip6t_do_table(skb, ops->hooknum, state, net->ipv6.ip6table_filter);
}
static int __net_init ip6table_filter_net_init(struct net *net)
{
struct ip6t_replace *repl;
repl = ip6t_alloc_initial_table(&packet_filter);
if (repl == NULL)
return -ENOMEM;
((struct ip6t_standard *)repl->entries)[1].target.verdict =
forward ? -NF_ACCEPT - 1 : -NF_DROP - 1;
net->ipv6.ip6table_filter =
ip6t_register_table(net, &packet_filter, repl);
kfree(repl);
return PTR_ERR_OR_ZERO(net->ipv6.ip6table_filter);
}
static void __net_exit ip6table_filter_net_exit(struct net *net)
{
ip6t_unregister_table(net, net->ipv6.ip6table_filter);
}
static int __init ip6table_filter_init(void)
{
int ret;
ret = register_pernet_subsys(&ip6table_filter_net_ops);
if (ret < 0)
return ret;
filter_ops = xt_hook_link(&packet_filter, ip6table_filter_hook);
if (IS_ERR(filter_ops)) {
ret = PTR_ERR(filter_ops);
goto cleanup_table;
}
return ret;
cleanup_table:
unregister_pernet_subsys(&ip6table_filter_net_ops);
return ret;
}
static void __exit ip6table_filter_fini(void)
{
xt_hook_unlink(&packet_filter, filter_ops);
unregister_pernet_subsys(&ip6table_filter_net_ops);
}
