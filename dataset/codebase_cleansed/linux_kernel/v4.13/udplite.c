static int udplitev6_rcv(struct sk_buff *skb)
{
return __udp6_lib_rcv(skb, &udplite_table, IPPROTO_UDPLITE);
}
static void udplitev6_err(struct sk_buff *skb,
struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
__udp6_lib_err(skb, opt, type, code, offset, info, &udplite_table);
}
int __init udplitev6_init(void)
{
int ret;
ret = inet6_add_protocol(&udplitev6_protocol, IPPROTO_UDPLITE);
if (ret)
goto out;
ret = inet6_register_protosw(&udplite6_protosw);
if (ret)
goto out_udplitev6_protocol;
out:
return ret;
out_udplitev6_protocol:
inet6_del_protocol(&udplitev6_protocol, IPPROTO_UDPLITE);
goto out;
}
void udplitev6_exit(void)
{
inet6_unregister_protosw(&udplite6_protosw);
inet6_del_protocol(&udplitev6_protocol, IPPROTO_UDPLITE);
}
static int __net_init udplite6_proc_init_net(struct net *net)
{
return udp_proc_register(net, &udplite6_seq_afinfo);
}
static void __net_exit udplite6_proc_exit_net(struct net *net)
{
udp_proc_unregister(net, &udplite6_seq_afinfo);
}
int __init udplite6_proc_init(void)
{
return register_pernet_subsys(&udplite6_net_ops);
}
void udplite6_proc_exit(void)
{
unregister_pernet_subsys(&udplite6_net_ops);
}
