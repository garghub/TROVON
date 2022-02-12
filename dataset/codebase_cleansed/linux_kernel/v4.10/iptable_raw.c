static unsigned int
iptable_raw_hook(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
if (state->hook == NF_INET_LOCAL_OUT &&
(skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr)))
return NF_ACCEPT;
return ipt_do_table(skb, state, state->net->ipv4.iptable_raw);
}
static int __net_init iptable_raw_table_init(struct net *net)
{
struct ipt_replace *repl;
int ret;
if (net->ipv4.iptable_raw)
return 0;
repl = ipt_alloc_initial_table(&packet_raw);
if (repl == NULL)
return -ENOMEM;
ret = ipt_register_table(net, &packet_raw, repl, rawtable_ops,
&net->ipv4.iptable_raw);
kfree(repl);
return ret;
}
static void __net_exit iptable_raw_net_exit(struct net *net)
{
if (!net->ipv4.iptable_raw)
return;
ipt_unregister_table(net, net->ipv4.iptable_raw, rawtable_ops);
net->ipv4.iptable_raw = NULL;
}
static int __init iptable_raw_init(void)
{
int ret;
rawtable_ops = xt_hook_ops_alloc(&packet_raw, iptable_raw_hook);
if (IS_ERR(rawtable_ops))
return PTR_ERR(rawtable_ops);
ret = register_pernet_subsys(&iptable_raw_net_ops);
if (ret < 0) {
kfree(rawtable_ops);
return ret;
}
ret = iptable_raw_table_init(&init_net);
if (ret) {
unregister_pernet_subsys(&iptable_raw_net_ops);
kfree(rawtable_ops);
}
return ret;
}
static void __exit iptable_raw_fini(void)
{
unregister_pernet_subsys(&iptable_raw_net_ops);
kfree(rawtable_ops);
}
