static int udplite_rcv(struct sk_buff *skb)
{
return __udp4_lib_rcv(skb, &udplite_table, IPPROTO_UDPLITE);
}
static void udplite_err(struct sk_buff *skb, u32 info)
{
__udp4_lib_err(skb, info, &udplite_table);
}
static int __net_init udplite4_proc_init_net(struct net *net)
{
return udp_proc_register(net, &udplite4_seq_afinfo);
}
static void __net_exit udplite4_proc_exit_net(struct net *net)
{
udp_proc_unregister(net, &udplite4_seq_afinfo);
}
static __init int udplite4_proc_init(void)
{
return register_pernet_subsys(&udplite4_net_ops);
}
static inline int udplite4_proc_init(void)
{
return 0;
}
void __init udplite4_register(void)
{
udp_table_init(&udplite_table, "UDP-Lite");
if (proto_register(&udplite_prot, 1))
goto out_register_err;
if (inet_add_protocol(&udplite_protocol, IPPROTO_UDPLITE) < 0)
goto out_unregister_proto;
inet_register_protosw(&udplite4_protosw);
if (udplite4_proc_init())
printk(KERN_ERR "%s: Cannot register /proc!\n", __func__);
return;
out_unregister_proto:
proto_unregister(&udplite_prot);
out_register_err:
printk(KERN_CRIT "%s: Cannot add UDP-Lite protocol.\n", __func__);
}
