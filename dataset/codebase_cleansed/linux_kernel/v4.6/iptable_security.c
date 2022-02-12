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
static int __net_init iptable_security_table_init(struct net *net)
{
struct ipt_replace *repl;
int ret;
if (net->ipv4.iptable_security)
return 0;
repl = ipt_alloc_initial_table(&security_table);
if (repl == NULL)
return -ENOMEM;
ret = ipt_register_table(net, &security_table, repl, sectbl_ops,
&net->ipv4.iptable_security);
kfree(repl);
return ret;
}
static void __net_exit iptable_security_net_exit(struct net *net)
{
if (!net->ipv4.iptable_security)
return;
ipt_unregister_table(net, net->ipv4.iptable_security, sectbl_ops);
net->ipv4.iptable_security = NULL;
}
static int __init iptable_security_init(void)
{
int ret;
sectbl_ops = xt_hook_ops_alloc(&security_table, iptable_security_hook);
if (IS_ERR(sectbl_ops))
return PTR_ERR(sectbl_ops);
ret = register_pernet_subsys(&iptable_security_net_ops);
if (ret < 0) {
kfree(sectbl_ops);
return ret;
}
ret = iptable_security_table_init(&init_net);
if (ret) {
unregister_pernet_subsys(&iptable_security_net_ops);
kfree(sectbl_ops);
}
return ret;
}
static void __exit iptable_security_fini(void)
{
unregister_pernet_subsys(&iptable_security_net_ops);
kfree(sectbl_ops);
}
