static unsigned int
iptable_raw_hook(unsigned int hook, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
const struct net *net;
if (hook == NF_INET_LOCAL_OUT &&
(skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr)))
return NF_ACCEPT;
net = dev_net((in != NULL) ? in : out);
return ipt_do_table(skb, hook, in, out, net->ipv4.iptable_raw);
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
if (IS_ERR(net->ipv4.iptable_raw))
return PTR_ERR(net->ipv4.iptable_raw);
return 0;
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
goto cleanup_table;
}
return ret;
cleanup_table:
unregister_pernet_subsys(&iptable_raw_net_ops);
return ret;
}
static void __exit iptable_raw_fini(void)
{
xt_hook_unlink(&packet_raw, rawtable_ops);
unregister_pernet_subsys(&iptable_raw_net_ops);
}
