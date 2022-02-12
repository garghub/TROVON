static unsigned int
iptable_raw_hook(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct nf_hook_state *state)
{
const struct net *net;
if (ops->hooknum == NF_INET_LOCAL_OUT &&
(skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr)))
return NF_ACCEPT;
net = dev_net(state->in ? state->in : state->out);
return ipt_do_table(skb, ops->hooknum, state, net->ipv4.iptable_raw);
}
static int __net_init iptable_raw_net_init(struct net *net)
{
struct ipt_replace *repl;
repl = ipt_alloc_initial_table(&packet_raw);
if (repl == NULL)
return -ENOMEM;
net->ipv4.iptable_raw =
ipt_register_table(net, &packet_raw, repl);
kfree(repl);
return PTR_ERR_OR_ZERO(net->ipv4.iptable_raw);
}
static void __net_exit iptable_raw_net_exit(struct net *net)
{
ipt_unregister_table(net, net->ipv4.iptable_raw);
}
static int __init iptable_raw_init(void)
{
int ret;
ret = register_pernet_subsys(&iptable_raw_net_ops);
if (ret < 0)
return ret;
rawtable_ops = xt_hook_link(&packet_raw, iptable_raw_hook);
if (IS_ERR(rawtable_ops)) {
ret = PTR_ERR(rawtable_ops);
unregister_pernet_subsys(&iptable_raw_net_ops);
}
return ret;
}
static void __exit iptable_raw_fini(void)
{
xt_hook_unlink(&packet_raw, rawtable_ops);
unregister_pernet_subsys(&iptable_raw_net_ops);
}
