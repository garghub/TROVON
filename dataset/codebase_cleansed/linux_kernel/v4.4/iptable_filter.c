static unsigned int
iptable_filter_hook(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
if (state->hook == NF_INET_LOCAL_OUT &&
(skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr)))
return NF_ACCEPT;
return ipt_do_table(skb, state, state->net->ipv4.iptable_filter);
}
static int __net_init iptable_filter_net_init(struct net *net)
{
struct ipt_replace *repl;
repl = ipt_alloc_initial_table(&packet_filter);
if (repl == NULL)
return -ENOMEM;
((struct ipt_standard *)repl->entries)[1].target.verdict =
forward ? -NF_ACCEPT - 1 : -NF_DROP - 1;
net->ipv4.iptable_filter =
ipt_register_table(net, &packet_filter, repl);
kfree(repl);
return PTR_ERR_OR_ZERO(net->ipv4.iptable_filter);
}
static void __net_exit iptable_filter_net_exit(struct net *net)
{
ipt_unregister_table(net, net->ipv4.iptable_filter);
}
static int __init iptable_filter_init(void)
{
int ret;
ret = register_pernet_subsys(&iptable_filter_net_ops);
if (ret < 0)
return ret;
filter_ops = xt_hook_link(&packet_filter, iptable_filter_hook);
if (IS_ERR(filter_ops)) {
ret = PTR_ERR(filter_ops);
unregister_pernet_subsys(&iptable_filter_net_ops);
}
return ret;
}
static void __exit iptable_filter_fini(void)
{
xt_hook_unlink(&packet_filter, filter_ops);
unregister_pernet_subsys(&iptable_filter_net_ops);
}
