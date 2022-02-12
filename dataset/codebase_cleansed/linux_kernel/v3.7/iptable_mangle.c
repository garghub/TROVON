static unsigned int
ipt_mangle_out(struct sk_buff *skb, const struct net_device *out)
{
unsigned int ret;
const struct iphdr *iph;
u_int8_t tos;
__be32 saddr, daddr;
u_int32_t mark;
if (skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr))
return NF_ACCEPT;
mark = skb->mark;
iph = ip_hdr(skb);
saddr = iph->saddr;
daddr = iph->daddr;
tos = iph->tos;
ret = ipt_do_table(skb, NF_INET_LOCAL_OUT, NULL, out,
dev_net(out)->ipv4.iptable_mangle);
if (ret != NF_DROP && ret != NF_STOLEN) {
iph = ip_hdr(skb);
if (iph->saddr != saddr ||
iph->daddr != daddr ||
skb->mark != mark ||
iph->tos != tos)
if (ip_route_me_harder(skb, RTN_UNSPEC))
ret = NF_DROP;
}
return ret;
}
static unsigned int
iptable_mangle_hook(unsigned int hook,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
if (hook == NF_INET_LOCAL_OUT)
return ipt_mangle_out(skb, out);
if (hook == NF_INET_POST_ROUTING)
return ipt_do_table(skb, hook, in, out,
dev_net(out)->ipv4.iptable_mangle);
return ipt_do_table(skb, hook, in, out,
dev_net(in)->ipv4.iptable_mangle);
}
static int __net_init iptable_mangle_net_init(struct net *net)
{
struct ipt_replace *repl;
repl = ipt_alloc_initial_table(&packet_mangler);
if (repl == NULL)
return -ENOMEM;
net->ipv4.iptable_mangle =
ipt_register_table(net, &packet_mangler, repl);
kfree(repl);
return PTR_RET(net->ipv4.iptable_mangle);
}
static void __net_exit iptable_mangle_net_exit(struct net *net)
{
ipt_unregister_table(net, net->ipv4.iptable_mangle);
}
static int __init iptable_mangle_init(void)
{
int ret;
ret = register_pernet_subsys(&iptable_mangle_net_ops);
if (ret < 0)
return ret;
mangle_ops = xt_hook_link(&packet_mangler, iptable_mangle_hook);
if (IS_ERR(mangle_ops)) {
ret = PTR_ERR(mangle_ops);
unregister_pernet_subsys(&iptable_mangle_net_ops);
}
return ret;
}
static void __exit iptable_mangle_fini(void)
{
xt_hook_unlink(&packet_mangler, mangle_ops);
unregister_pernet_subsys(&iptable_mangle_net_ops);
}
