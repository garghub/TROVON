static unsigned int
iptable_filter_hook(unsigned int hook, struct sk_buff *skb,
const struct net_device *in, const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
const struct net *net;
if (hook == NF_INET_LOCAL_OUT &&
(skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr)))
return NF_ACCEPT;
net = dev_net((in != NULL) ? in : out);
return ipt_do_table(skb, hook, in, out, net->ipv4.iptable_filter);
}
static int __net_init iptable_filter_net_init(struct net *net)
{
struct ipt_replace *repl;
repl = ipt_alloc_initial_table(&packet_filter);
if (repl == NULL)
return -ENOMEM;
((struct ipt_standard *)repl->entries)[1].target.verdict =
-forward - 1;
net->ipv4.iptable_filter =
ipt_register_table(net, &packet_filter, repl);
kfree(repl);
if (IS_ERR(net->ipv4.iptable_filter))
return PTR_ERR(net->ipv4.iptable_filter);
return 0;
}
static void __net_exit iptable_filter_net_exit(struct net *net)
{
ipt_unregister_table(net, net->ipv4.iptable_filter);
}
static int __init iptable_filter_init(void)
{
int ret;
if (forward < 0 || forward > NF_MAX_VERDICT) {
pr_err("iptables forward must be 0 or 1\n");
return -EINVAL;
}
ret = register_pernet_subsys(&iptable_filter_net_ops);
if (ret < 0)
return ret;
filter_ops = xt_hook_link(&packet_filter, iptable_filter_hook);
if (IS_ERR(filter_ops)) {
ret = PTR_ERR(filter_ops);
goto cleanup_table;
}
return ret;
cleanup_table:
unregister_pernet_subsys(&iptable_filter_net_ops);
return ret;
}
static void __exit iptable_filter_fini(void)
{
xt_hook_unlink(&packet_filter, filter_ops);
unregister_pernet_subsys(&iptable_filter_net_ops);
}
