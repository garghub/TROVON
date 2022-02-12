static unsigned int
iptable_security_hook(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
if (state->hook == NF_INET_LOCAL_OUT &&
(skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr)))
return NF_ACCEPT;
return ipt_do_table(skb, state, state->net->ipv4.iptable_security);
}
static int __net_init iptable_security_net_init(struct net *net)
{
struct ipt_replace *repl;
repl = ipt_alloc_initial_table(&security_table);
if (repl == NULL)
return -ENOMEM;
net->ipv4.iptable_security =
ipt_register_table(net, &security_table, repl);
kfree(repl);
return PTR_ERR_OR_ZERO(net->ipv4.iptable_security);
}
static void __net_exit iptable_security_net_exit(struct net *net)
{
ipt_unregister_table(net, net->ipv4.iptable_security);
}
static int __init iptable_security_init(void)
{
int ret;
ret = register_pernet_subsys(&iptable_security_net_ops);
if (ret < 0)
return ret;
sectbl_ops = xt_hook_link(&security_table, iptable_security_hook);
if (IS_ERR(sectbl_ops)) {
ret = PTR_ERR(sectbl_ops);
goto cleanup_table;
}
return ret;
cleanup_table:
unregister_pernet_subsys(&iptable_security_net_ops);
return ret;
}
static void __exit iptable_security_fini(void)
{
xt_hook_unlink(&security_table, sectbl_ops);
unregister_pernet_subsys(&iptable_security_net_ops);
}
