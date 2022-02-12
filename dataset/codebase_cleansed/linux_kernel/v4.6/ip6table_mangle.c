static unsigned int
ip6t_mangle_out(struct sk_buff *skb, const struct nf_hook_state *state)
{
unsigned int ret;
struct in6_addr saddr, daddr;
u_int8_t hop_limit;
u_int32_t flowlabel, mark;
int err;
#if 0
if (skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr)) {
net_warn_ratelimited("ip6t_hook: happy cracking\n");
return NF_ACCEPT;
}
#endif
memcpy(&saddr, &ipv6_hdr(skb)->saddr, sizeof(saddr));
memcpy(&daddr, &ipv6_hdr(skb)->daddr, sizeof(daddr));
mark = skb->mark;
hop_limit = ipv6_hdr(skb)->hop_limit;
flowlabel = *((u_int32_t *)ipv6_hdr(skb));
ret = ip6t_do_table(skb, state, state->net->ipv6.ip6table_mangle);
if (ret != NF_DROP && ret != NF_STOLEN &&
(!ipv6_addr_equal(&ipv6_hdr(skb)->saddr, &saddr) ||
!ipv6_addr_equal(&ipv6_hdr(skb)->daddr, &daddr) ||
skb->mark != mark ||
ipv6_hdr(skb)->hop_limit != hop_limit ||
flowlabel != *((u_int32_t *)ipv6_hdr(skb)))) {
err = ip6_route_me_harder(state->net, skb);
if (err < 0)
ret = NF_DROP_ERR(err);
}
return ret;
}
static unsigned int
ip6table_mangle_hook(void *priv, struct sk_buff *skb,
const struct nf_hook_state *state)
{
if (state->hook == NF_INET_LOCAL_OUT)
return ip6t_mangle_out(skb, state);
if (state->hook == NF_INET_POST_ROUTING)
return ip6t_do_table(skb, state,
state->net->ipv6.ip6table_mangle);
return ip6t_do_table(skb, state, state->net->ipv6.ip6table_mangle);
}
static int __net_init ip6table_mangle_table_init(struct net *net)
{
struct ip6t_replace *repl;
int ret;
if (net->ipv6.ip6table_mangle)
return 0;
repl = ip6t_alloc_initial_table(&packet_mangler);
if (repl == NULL)
return -ENOMEM;
ret = ip6t_register_table(net, &packet_mangler, repl, mangle_ops,
&net->ipv6.ip6table_mangle);
kfree(repl);
return ret;
}
static void __net_exit ip6table_mangle_net_exit(struct net *net)
{
if (!net->ipv6.ip6table_mangle)
return;
ip6t_unregister_table(net, net->ipv6.ip6table_mangle, mangle_ops);
net->ipv6.ip6table_mangle = NULL;
}
static int __init ip6table_mangle_init(void)
{
int ret;
mangle_ops = xt_hook_ops_alloc(&packet_mangler, ip6table_mangle_hook);
if (IS_ERR(mangle_ops))
return PTR_ERR(mangle_ops);
ret = register_pernet_subsys(&ip6table_mangle_net_ops);
if (ret < 0) {
kfree(mangle_ops);
return ret;
}
ret = ip6table_mangle_table_init(&init_net);
if (ret) {
unregister_pernet_subsys(&ip6table_mangle_net_ops);
kfree(mangle_ops);
}
return ret;
}
static void __exit ip6table_mangle_fini(void)
{
unregister_pernet_subsys(&ip6table_mangle_net_ops);
kfree(mangle_ops);
}
