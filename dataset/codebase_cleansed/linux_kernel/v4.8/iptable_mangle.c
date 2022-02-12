static unsigned int
ipt_mangle_out(struct sk_buff *skb, const struct nf_hook_state *state)
{
unsigned int ret;
const struct iphdr *iph;
u_int8_t tos;
__be32 saddr, daddr;
u_int32_t mark;
int err;
if (skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr))
return NF_ACCEPT;
mark = skb->mark;
iph = ip_hdr(skb);
saddr = iph->saddr;
daddr = iph->daddr;
tos = iph->tos;
ret = ipt_do_table(skb, state, state->net->ipv4.iptable_mangle);
if (ret != NF_DROP && ret != NF_STOLEN) {
iph = ip_hdr(skb);
if (iph->saddr != saddr ||
iph->daddr != daddr ||
skb->mark != mark ||
iph->tos != tos) {
err = ip_route_me_harder(state->net, skb, RTN_UNSPEC);
if (err < 0)
ret = NF_DROP_ERR(err);
}
}
return ret;
}
static unsigned int
iptable_mangle_hook(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
if (state->hook == NF_INET_LOCAL_OUT)
return ipt_mangle_out(skb, state);
return ipt_do_table(skb, state, state->net->ipv4.iptable_mangle);
}
static int __net_init iptable_mangle_table_init(struct net *net)
{
struct ipt_replace *repl;
int ret;
if (net->ipv4.iptable_mangle)
return 0;
repl = ipt_alloc_initial_table(&packet_mangler);
if (repl == NULL)
return -ENOMEM;
ret = ipt_register_table(net, &packet_mangler, repl, mangle_ops,
&net->ipv4.iptable_mangle);
kfree(repl);
return ret;
}
static void __net_exit iptable_mangle_net_exit(struct net *net)
{
if (!net->ipv4.iptable_mangle)
return;
ipt_unregister_table(net, net->ipv4.iptable_mangle, mangle_ops);
net->ipv4.iptable_mangle = NULL;
}
static int __init iptable_mangle_init(void)
{
int ret;
mangle_ops = xt_hook_ops_alloc(&packet_mangler, iptable_mangle_hook);
if (IS_ERR(mangle_ops)) {
ret = PTR_ERR(mangle_ops);
return ret;
}
ret = register_pernet_subsys(&iptable_mangle_net_ops);
if (ret < 0) {
kfree(mangle_ops);
return ret;
}
ret = iptable_mangle_table_init(&init_net);
if (ret) {
unregister_pernet_subsys(&iptable_mangle_net_ops);
kfree(mangle_ops);
}
return ret;
}
static void __exit iptable_mangle_fini(void)
{
unregister_pernet_subsys(&iptable_mangle_net_ops);
kfree(mangle_ops);
}
