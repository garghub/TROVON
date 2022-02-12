static unsigned int
ip6table_security_hook(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
const struct net *net = dev_net((in != NULL) ? in : out);
return ip6t_do_table(skb, ops->hooknum, in, out,
net->ipv6.ip6table_security);
}
static int __net_init ip6table_security_net_init(struct net *net)
{
struct ip6t_replace *repl;
repl = ip6t_alloc_initial_table(&security_table);
if (repl == NULL)
return -ENOMEM;
net->ipv6.ip6table_security =
ip6t_register_table(net, &security_table, repl);
kfree(repl);
return PTR_ERR_OR_ZERO(net->ipv6.ip6table_security);
}
static void __net_exit ip6table_security_net_exit(struct net *net)
{
ip6t_unregister_table(net, net->ipv6.ip6table_security);
}
static int __init ip6table_security_init(void)
{
int ret;
ret = register_pernet_subsys(&ip6table_security_net_ops);
if (ret < 0)
return ret;
sectbl_ops = xt_hook_link(&security_table, ip6table_security_hook);
if (IS_ERR(sectbl_ops)) {
ret = PTR_ERR(sectbl_ops);
goto cleanup_table;
}
return ret;
cleanup_table:
unregister_pernet_subsys(&ip6table_security_net_ops);
return ret;
}
static void __exit ip6table_security_fini(void)
{
xt_hook_unlink(&security_table, sectbl_ops);
unregister_pernet_subsys(&ip6table_security_net_ops);
}
